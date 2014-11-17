;- Routine d'introduction des pok�mons sauvages -------------------------------------------------------------------
;entr�e : hl = pointeur � l'ID
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
	call get_pokemon_sprite_ix		;hl = pointeur � l'id du pok�mon
	xor a
	ld bc,pokemon_sprite_size
	ld l,0
	call largeSprite_push
	push ix
		call largeSprite
	pop ix
	call fade_in

	ld b,screen_width-pokemon_sprite_width-pokemon_sprite_battle_distance_from_screen
battle_wild_pokemon_intro_loop:
	push bc
		ld a,screen_width-pokemon_sprite_width-pokemon_sprite_battle_distance_from_screen
		sub b
		ld bc,pokemon_sprite_size
		ld l,0
		call largeSprite_push
		push ix
			call largeSprite
		pop ix
	pop bc
	djnz battle_wild_pokemon_intro_loop
;afficher le sprite du pok�mon sauvage
	ld a,screen_width-pokemon_sprite_width-pokemon_sprite_battle_distance_from_screen
	sub b
	ld bc,pokemon_sprite_size
	ld l,0
	call largeSprite
;afficher le texte du pok�mon sauvage
	ld hl,battle_wild_pokemon_intro1
	jp draw_battle_dialogue

;sauver registres
largeSprite_push:
	push af
	push bc
	push hl
	push ix
		call largeSprite
		call fastCopy
	pop ix
	pop hl
	pop bc
	pop af
	ret
;------------------------------------------------------------------------------------------------------------------

;- Routine d'introduction des pok�mons du joueur ------------------------------------------------------------------
battle_player_pokemon_intro:
	call battle_search_next_player_pokemon_alive	; il faut d'abord v�rifier quel est le premier pok�mon en vie sur les 6 qu'on porte avec nous
	 ret nz	; s'il n'y en a pas, tous les pok�mons de l'�quipe sont KO
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
	ld ix,player_woman_back
	 jr nz,battle_draw_player_next
		ld ix,player_man_back
battle_draw_player_next:
	xor a
	ld bc,$1704
	ld l,26
	jp largeSprite

;- Routines d'affichages de diff�rentes choses durant les combats -------------------------------------------------
battle_draw_screen:
	bcall(_grbufclr)
	call battle_draw_frame
;############# peut-�tre pas n�c�ssaire ############
battle_current_opponent_pokemon_address = $+1	;###
	ld hl,0										;###
;############# peut-�tre pas n�c�ssaire ############

;d'abord le pok�mon adverse
	ld de,$0002
	ld hl,battle_str_enemy	;nom, niveau et PV du pok�mon
	call draw_text
;maintenant current_pokemon contient les donn�es du pok�mon m�chant
	call battle_draw_pokeball_if_already_captured	; On s'occupe d'abord d'afficher le cadre + les donn�es du pok�mon adverse
	ld ix,(current_pokemon+CP_SPRITE)
	ld bc,pokemon_sprite_size
	ld a,screen_width-pokemon_sprite_width-pokemon_sprite_battle_distance_from_screen
	ld l,0
	call largeSprite	; on affiche le sprite du pok�mon adverse

	call battle_draw_opponent_pokemon_health_bar
;	call battle_draw_opponent_pokemon_state
	ld bc,$1007
	push bc
		ld a,1
		ld l,7
		ld ix,battle_bar
		push ix
			call largeSprite	; on affiche sa barre de vie
		pop ix
	pop bc
	; Ensuite lorsque ce sera un dresseur : afficher ses pok�balls
	call flip_sprite	; on la flip horizontalement
	ld a,39
	ld l,32
	call largeSprite	; puis on l'affiche de notre c�t�
	;-------------------------------------------
	; � partie de l� on ne s'occupe plus que de notre c�t�
	;-------------------------------------------
;############# peut-�tre pas n�c�ssaire ############
battle_current_player_pokemon_address = $+1		;###
	ld hl,0										;###
;############# peut-�tre pas n�c�ssaire ############
	ld de,$192c
	ld hl,battle_str_player	;nom, niveau et PV du pok�mon
	call draw_text
	ld ix,(current_pokemon+CP_SPRITE)
	ld bc,pokemon_sprite_size
	call flip_sprite
	ld a,pokemon_sprite_battle_distance_from_screen
	ld l,23
	call largeSprite	; on affiche le sprite du pok�mon adverse
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
	ld bc,pokemon_sprite_size
	call flip_sprite
	ld a,pokemon_sprite_battle_distance_from_screen
	ld l,23
	call largeSprite
	call fastCopy
	ld b,battle_blink_sprite_speed
	call wait
	pop ix
	pop bc
	djnz battle_player_pokemon_blink_sprite_loop
	ret

battle_opponent_pokemon_blink_sprite:	; hl=opponent pokemon stats
	ld a,(hl)							;pok�dex id of pok�mon
	call battle_find_sprite				;sprite address in hl
battle_opponent_pokemon_blink_sprite_loop:
	push bc
	push ix
		ld bc,pokemon_sprite_size
		ld a,screen_width-pokemon_sprite_width-pokemon_sprite_battle_distance_from_screen
		ld l,0
		call largeSprite
		call fastCopy
		ld b,battle_blink_sprite_speed
		call wait
	pop ix
	pop bc
	djnz battle_opponent_pokemon_blink_sprite_loop
	ret

;get pok�mon's sprite
;input: a = pok�dex id
battle_find_sprite:
	ld l,a
	ld h,0
	ld b,(pokemon_sprite_size&$FF)*(pokemon_sprite_size>>8)
	call slow_mult_hl_b
	ld bc,pokemon_sprites
	add hl,bc
	push hl
	pop ix
	ld b,battle_blink_sprite_times*2	; must be even
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

battle_draw_opponent_pokemon_health_bar:	; input : hl = opponent pok�mon hp pointer, a = opponent pok�mon lvl
	ld hl,current_pokemon_enemy+CP_HPTOT
	ld de,$0208
battle_draw_pokemon_health_bar:
	push de
		ld c,(hl)			;max HP
		dec hl
		ld h,(hl)			;cur HP
		ld l,0
		call hl_div_c		;curHP/maxHP (l will hold the remainder, aka the fraction)
		ld b,50
		call slow_mult_hl_b	;the bar takes up 50 pixels
	pop de
	xor a
	cp h
	 ret z					;if no HP, no bar
	ld b,1
	ld c,h
	jp rectangle_filled_solid

battle_draw_player_pokemon_experience_bar:	; input : hl = pok�mon XP, de = XPmax
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
	jp putSprite

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
	call putSprite
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
	ld bc,pokemon_sprite_size
	ld a,28
	ld l,11
	push ix
	call largeSprite
	pop ix
	jp fastCopy

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
	ld a,vmode_type
	ld (_v_mode),a
	jp _vputs_ml

battle_disp_evolution_things:
	call battle_find_sprite
	push hl
	ld bc,pokemon_sprite_size
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