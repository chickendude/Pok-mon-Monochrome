;- Routine d'introduction des pokémons sauvages -------------------------------------------------------------------
;entrée : hl = pointeur à l'ID
;sortie : ix = addresse du sprite
get_pokemon_sprite_ix:
	ld b,(hl)
	inc b
	ld de,26*4
	ld hl,pokemon_sprites-(26*4)
	add hl,de
	djnz $-1
	push hl
	pop ix
	ret

battle_wild_pokemon_intro:
	call get_pokemon_sprite_ix		;hl = pointeur à l'id du pokémon
	xor a
	ld bc,POKEMON_SPRITE_SIZE
	ld l,0
	call large_sprite_push
	push ix
		call large_sprite
	pop ix
	call fade_in

	ld b,SCREEN_WIDTH-POKEMON_SPRITE_WIDTH-POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN
battle_wild_pokemon_intro_loop:
	push bc
		ld a,SCREEN_WIDTH-POKEMON_SPRITE_WIDTH-POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN
		sub b
		ld bc,POKEMON_SPRITE_SIZE
		ld l,0
		call large_sprite_push
		push ix
			call large_sprite
		pop ix
	pop bc
	djnz battle_wild_pokemon_intro_loop
;afficher le sprite du pokémon sauvage
	ld a,SCREEN_WIDTH-POKEMON_SPRITE_WIDTH-POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN
	sub b
	ld bc,POKEMON_SPRITE_SIZE
	ld l,0
	call large_sprite
;afficher le texte du pokémon sauvage
	ld hl,battle_wild_pokemon_intro1
	jp draw_battle_dialogue

;sauver registres
large_sprite_push:
	push af
	push bc
	push hl
	push ix
		call large_sprite
		call fast_copy
	pop ix
	pop hl
	pop bc
	pop af
	ret
;------------------------------------------------------------------------------------------------------------------

;- Routine d'introduction des pokémons du joueur ------------------------------------------------------------------
battle_player_pokemon_intro:
	call battle_search_next_player_pokemon_alive	; il faut d'abord vérifier quel est le premier pokémon en vie sur les 6 qu'on porte avec nous
	 ret nz	; s'il n'y en a pas, tous les pokémons de l'équipe sont KO
battle_player_pokemon_intro_disp_text:
	ld a,(hl)
	ld (current_player_pokemon),a
	ld (starting_player_pokemon1),a
	ld (starting_player_pokemon2),a
	ld hl,battle_player_pokemon_intro1
	call draw_battle_dialogue
	jp fade_out

battle_draw_player_back:
player_gender = $+1
	ld a,0
	or a
	ld ix,player_woman_back_sprite
	 jr nz,battle_draw_player_next
		ld ix,player_man_back_sprite
battle_draw_player_next:
	xor a
	ld bc,$1704
	ld l,26
	jp large_sprite

;- Routines d'affichages de différentes choses durant les combats -------------------------------------------------
battle_draw_screen:
	bcall(_grbufclr)
	call battle_draw_frame
;############# peut-être pas nécéssaire ############
battle_current_opponent_pokemon_address = $+1	;###
	ld hl,0										;###
;############# peut-être pas nécéssaire ############

;d'abord le pokémon adverse
	ld de,$0002
	ld hl,battle_str_enemy	;nom, niveau et PV du pokémon
	call draw_text
;maintenant current_pokemon contient les données du pokémon méchant
	call battle_draw_pokeball_if_already_captured	; On s'occupe d'abord d'afficher le cadre + les données du pokémon adverse
	ld ix,(current_pokemon+CP_SPRITE)
	ld bc,POKEMON_SPRITE_SIZE
	ld a,SCREEN_WIDTH-POKEMON_SPRITE_WIDTH-POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN
	ld l,0
	call large_sprite	; on affiche le sprite du pokémon adverse

	call battle_draw_opponent_pokemon_health_bar
;	call battle_draw_opponent_pokemon_state
	ld bc,$1007
	push bc
		ld a,1
		ld l,7
		ld ix,battle_bar
		push ix
			call large_sprite	; on affiche sa barre de vie
		pop ix
	pop bc
	; Ensuite lorsque ce sera un dresseur : afficher ses pokéballs
	call flip_sprite	; on la flip horizontalement
	ld a,39
	ld l,32
	call large_sprite	; puis on l'affiche de notre côté
	;-------------------------------------------
	; À partie de là on ne s'occupe plus que de notre côté
	;-------------------------------------------
;############# peut-être pas nécéssaire ############
battle_current_player_pokemon_address = $+1		;###
	ld hl,0										;###
;############# peut-être pas nécéssaire ############
	ld de,$192c
	ld hl,battle_str_player	;nom, niveau et PV du pokémon
	call draw_text
	ld ix,(current_pokemon+CP_SPRITE)
	ld bc,POKEMON_SPRITE_SIZE
	call flip_sprite
	ld a,POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN
	ld l,23
	call large_sprite	; on affiche le sprite du pokémon adverse
;	call battle_draw_player_pokemon_state
;	call calculate_next_experience
	call battle_draw_player_pokemon_health_bar
;	call battle_draw_player_pokemon_experience_bar
	call battle_draw_player_pokeballs
	ret

battle_player_pokemon_blink_sprite:	; hl=player pokemon stats
	ld a,(hl)
	call battle_find_sprite
battle_player_pokemon_blink_sprite_loop:
	push bc
	push ix
	ld bc,POKEMON_SPRITE_SIZE
	call flip_sprite
	ld a,POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN
	ld l,23
	call large_sprite
	call fast_copy
	ld b,BATTLE_BLINK_SPRITE_SPEED
	call wait
	pop ix
	pop bc
	djnz battle_player_pokemon_blink_sprite_loop
	ret

battle_opponent_pokemon_blink_sprite:	; hl=opponent pokemon stats
	ld a,(hl)							;pokédex id of pokémon
	call battle_find_sprite				;sprite address in hl
battle_opponent_pokemon_blink_sprite_loop:
	push bc
	push ix
		ld bc,POKEMON_SPRITE_SIZE
		ld a,SCREEN_WIDTH-POKEMON_SPRITE_WIDTH-POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN
		ld l,0
		call large_sprite
		call fast_copy
		ld b,BATTLE_BLINK_SPRITE_SPEED
		call wait
	pop ix
	pop bc
	djnz battle_opponent_pokemon_blink_sprite_loop
	ret

;get pokémon's sprite
;input: a = pokédex id
battle_find_sprite:
	ld l,a
	ld h,0
	ld b,(POKEMON_SPRITE_SIZE&$FF)*(POKEMON_SPRITE_SIZE>>8)
	call slow_mult_hl_b
	ld bc,pokemon_sprites
	add hl,bc
	push hl
	pop ix
	ld b,BATTLE_BLINK_SPRITE_TIMES*2	; must be even
	ret

battle_draw_player_pokemon_state:	; input : hl = player pokemon state
	ld a,(hl)
	or a
	ret z
	push af
	ld bc,$060c
	ld de,$1e2a
	call rectangle_filled_white
	pop af
	call battle_draw_pokemon_state
	ld de,$2a1f
	ld (pencol),de
	bcall(_vputs)
	ret

battle_draw_opponent_pokemon_state:	; input : hl = opponent pokemon state
	ld a,(hl)
	or a
	ret z
	push af
	ld bc,$060c
	ld de,$3611
	call rectangle_filled_white
	pop af
	call battle_draw_pokemon_state
	ld de,$1136
	ld (pencol),de
	bcall(_vputs)
	ret

battle_draw_pokemon_state:
	ld hl,menu_pokemon_str_poison
	cp 2
	jr z,battle_draw_player_pokemon_state_sleep
	cp 3
	jr z,battle_draw_player_pokemon_state_para
	ret

battle_draw_player_pokemon_state_sleep:
	ld hl,menu_pokemon_str_sleep
	ret

battle_draw_player_pokemon_state_para:
	ld hl,menu_pokemon_str_para
	ret

battle_reset_player_pokemon_health_bar_and_hp:
	ld bc,$0132
	ld de,$2c21
	call rectangle_filled_white
	ld bc,$051b
	ld de,$4224
	jp rectangle_filled_white

battle_reset_opponent_pokemon_health_bar_and_hp:
	ld bc,$0132
	ld de,$0208
	call rectangle_filled_white
	ld bc,$051b
	ld de,$180b
	jp rectangle_filled_white

battle_reset_player_experience_bar:
	ld bc,$012c
	ld de,$312e
	jp rectangle_filled_white

battle_draw_player_pokemon_health_bar:	; input : hl = player pokemon datas
	ld hl,current_pokemon_player+CP_HPTOT
	ld de,$2c21
	jr battle_draw_pokemon_health_bar

battle_draw_opponent_pokemon_health_bar:	; input : hl = opponent pokémon hp pointer, a = opponent pokémon lvl
	ld hl,current_pokemon_enemy+CP_HPTOT
	ld de,$0208
battle_draw_pokemon_health_bar:
	push de
		ld c,(hl)			;max HP
		dec hl
		ld h,(hl)			;cur HP
		ld l,0
		call div_hl_c		;curHP/maxHP (l will hold the remainder, aka the fraction)
		ld b,50
		call slow_mult_hl_b	;the bar takes up 50 pixels
	pop de
	xor a
	cp h
	 ret z					;if no HP, no bar
	ld b,1
	ld c,h
	jp rectangle_filled_solid

battle_draw_player_pokemon_experience_bar:	; input : hl = pokémon XP, de = XPmax
	ld b,d
	ld c,e
	call ldhlind_no_little_indian
	ld d,0
	ld e,d
	cp_hl_de()
	ret z
	ld a,44
	call calculate_proportionality
	or a
	ret z
	ld b,1
	ld c,a
	ld de,$312e
	jp rectangle_filled_solid

battle_draw_pokeball_if_already_captured:	; input : hl=id
	ld a,(hl)
	call is_already_captured
	ret nz
	ld a,4
	ld l,17
	ld b,4
	ld ix,pokeball_pokemon_alread_captured
	jp put_sprite

battle_draw_player_pokeballs:
	xor a
	ld (battle_draw_player_pokeballs_count),a
	ld hl,player_pokemons
	ld b,6

battle_draw_player_pokeballs_loop:
	ld a,(hl)
	or a
	jr z,battle_draw_player_pokeballs_skip
	push bc
	push hl
	call find_pokemon_stats
	ld ix,pokeball_pokemon_alive
	inc hl
	inc hl
	ld a,(hl)
	or a
	call z,battle_draw_player_pokeball_dead
	ld a,49
battle_draw_player_pokeballs_count = $+1
	ld c,0
	add a,c
	add a,c
	add a,c
	add a,c
	ld l,42
	ld b,3
	call put_sprite
	ld a,(battle_draw_player_pokeballs_count)
	inc a
	ld (battle_draw_player_pokeballs_count),a
	pop hl
	pop bc
	inc hl
	djnz battle_draw_player_pokeballs_loop
	ret

battle_draw_player_pokeball_dead:
	ld ix,pokeball_pokemon_dead
	ret

battle_draw_player_pokeballs_skip:
	inc hl
	djnz battle_draw_player_pokeballs_loop
	ret

battle_draw_evolution:
	ld bc,POKEMON_SPRITE_SIZE
	ld a,28
	ld l,11
	push ix
	call large_sprite
	pop ix
	jp fast_copy

;- Routines graphiques pour le texte ------------------------------------------------------------------------------
battle_draw_frame:	; affiche le cadre des textes et positionne pencol/penrow
	ld de,$3202
	ld (pencol),de
	ld bc,$0f60
	ld de,$0031
	jp draw_frame

battle_disp_player_pokemon_name:	; hl=pokemon ID
	call find_pokemon_data
	inc hl
	jp _v_type

battle_disp_effectivity:
	push af
	call battle_draw_frame
	pop af
	ld hl,battle_str_no_effect
	or a
	call z,battle_disp_not_effective
	cp 2
	call z,battle_disp_super_effective
	jr battle_disp_vputs

battle_disp_not_effective:
	ld hl,battle_str_not_effective
	ret

battle_disp_super_effective:
	ld hl,battle_str_super_effective
	ret

battle_attack_missed:
	call battle_draw_frame
	ld hl,battle_str_attack_missed

battle_disp_vputs:
	ld a,VMODE_TYPE
	ld (_v_mode),a
	jp _vputs_ml

battle_disp_evolution_things:
	call battle_find_sprite
	push hl
	ld bc,POKEMON_SPRITE_SIZE
	call flip_sprite
	call battle_draw_evolution
	ld hl,battle_str_evolution_start
	call _v_type
	pop hl
	inc hl
	call _v_type
	ld de,$3802
	ld (pencol),de
	ret
;------------------------------------------------------------------------------------------------------------------
