;**Plus tard il faudra tenir en compte la vitesse des deux pokémons**

;start of a battle
battle:
	ld hl,pokemon_who_fought	; reset the list of pokémons who fought
	ld (hl),0
	ld de,pokemon_who_fought+1
	ld bc,opponent_pokemon_stats-pokemon_who_fought-1
	ldir
	;définir si c'est un combat contre un pokémon sauvage, un dresseur voire un autre joueur (par link)
battle_type = $+1	;	0 = pokémon sauvage
	ld a,0
	or a
	 ret nz
	call generate_wild_pokemon

battle_intro:
	bcall(_GrBufClr)
	call battle_draw_player_back
	call battle_draw_frame				;draw the player and the little text frame at the bottom
	ld hl,opponent_pokemon_stats		;début des données du groupe de pokémon méchants
	ld (battle_current_opponent_pokemon_address),hl
	call battle_wild_pokemon_intro		;load the wild pokemon sprite and display some text announcing the wild pokemon

battle_start:
	call battle_player_pokemon_intro	; /!\ cette routine se termine par un fade_out
	call battle_draw_screen				;the 2 pokemon, HP, HP bars, etc.
	call fade_in

battle_loop:
	xor a
	ld de,$3206
	ld hl,menu_battle
	call draw_menu
	call menu_key			;attendre une réponse
;if [Alpha] was pressed, just loop back
	call battle_draw_screen	;reset the screen
	jr battle_loop

;- Routine du menu principal des combats --------------------------------------------------------------------------
battle_menu_pokemon_valid:
	ld d,0
	ld e,a
	ld hl,player_pokemons
	add hl,de
	ld a,(hl)
	push af
	call find_pokemon_stats
	ld a,(hl)
	ex de,hl
	ld hl,(battle_current_player_pokemon_address)
	cp (hl)	; check if you haven't selected the current fighting pokémon
	pop bc
	;jp z,menu_pokemon_return
	; TODO : check if he's dead
	push bc
	push de
	push hl
	call battle_draw_screen
	call battle_draw_frame	; smaller than having to restore pencol/penrow, even if the frame is already drawn by the previous routine
	pop hl
	call battle_disp_player_pokemon_name
;	ld hl,battle_player_pokemon_intro2
	call _v_type
	ld de,$3802
	ld (pencol),de
	ld hl,battle_player_pokemon_change
	call battle_disp_vputs
	pop de	; de = called pokémon stats pointer
	pop af	; a = called pokémon ID
	push de
	ld hl,pokemon_who_fought
	ld b,opponent_pokemon_stats-pokemon_who_fought

battle_menu_pokemon_valid_check_if_he_has_already_fought:
	cp (hl)
	jr z,battle_menu_pokemon_valid_skip
	ld d,a		;sauver a dans d
	ld a,(hl)
	or a
	ld a,d		;restaurer a
	jr z,battle_menu_pokemon_valid_add_to_list
	inc hl
	djnz battle_menu_pokemon_valid_check_if_he_has_already_fought

battle_menu_pokemon_valid_add_to_list:
	inc a	; else the pokémon which ID is 0 will not be counted
	ld (hl),a

battle_menu_pokemon_valid_skip:
	pop hl
	ld (battle_current_player_pokemon_address),hl
	call battle_player_pokemon_intro_disp_text
	call battle_draw_screen
	call fade_in
	ret

;------------------------------------------------------------------------------------------------------------------
;- Routine du menu des attaques -----------------------------------------------------------------------------------

battle_draw_fight_menu:
	call battle_draw_frame
	xor a						;default menu option is 0
	ld de,$3206					;e = x, d = y
	ld hl,menu_battle_attack	;address of menu to draw
	call draw_menu_return
	call menu_key_return		;handle the cursor, returns a = option chosen
;a = attack chosen
	call player_attack			;player's attack
	call check_enemy_ko
	 jp z,draw_map
	call battle_wild_pokemon_ai	;opponent's attack
	call check_enemy_ko
	 jp z,draw_map
;check if player/enemy's pokemon have all fainted or not	
	jr battle_draw_fight_menu	;loop

check_enemy_ko:
	ld hl,(battle_current_opponent_pokemon_address)
	inc hl
	inc hl						;jump to HP
	ld a,(hl)
	or a
	ret


;a = attack chosen (0-3)
player_attack:
	add a,a						;each attack takes up 2 bytes, its ID and PP left
	ld e,a
	ld d,0
	ld hl,current_pokemon+CP_ATK1
	add hl,de					;find the attack chosen
	push hl						;hl = pointer to current attack data
		add a,_AT1
		ld (current_attack),a	;store the attack name we want to draw in the battle_str_attack string
; vérifier s'il y a assez de PP
		inc hl
		ld a,(hl)
		or a
		 jr z,$					; ***pas assez de PP***
		dec (hl)				; si c'est bon on decrémente
		call battle_draw_screen
		ld hl,battle_str_attack
		call draw_battle_dialogue	;draw the attack text (XXX used XXX)
	pop hl
	ld de,(battle_current_opponent_pokemon_address)
	call check_attack_effectiveness	; vérifier en fonction des types si c'est super efficace
	cp 3						; si l'attaque n'a pas d'effet pas besoin de calculer les dommages
	 jp z,battle_attack_calculate_opponent_damages_skip
	ld hl,(battle_current_player_pokemon_address)
	ld de,(battle_current_opponent_pokemon_address)
	call calculate_damages		;put the damage to be done into a
	 jp c,battle_attack_missed
	push af						;save damage to be done
		call battle_draw_screen
		ld hl,(battle_current_opponent_pokemon_address)
		call battle_opponent_pokemon_blink_sprite
		ld hl,(battle_current_opponent_pokemon_address)
		call load_pokemon_data	;store pokémon into current_pokemon
	pop bc						;b = number of damage done
	ld hl,(battle_current_opponent_pokemon_address)
	inc hl						;id
	inc hl						;lvl
	ld a,(hl)					;HP
	sub b						;subtract damage and save new HP
	 jr nc,$+3
		xor a					;if there's a carry, set to 0
	ld (hl),a
	ld hl,current_pokemon+CP_HP	;we've loaded the enemy pokémon's current stats here
battle_menu_damages_loop:
	ld a,(hl)			;check if pokémon has no HP left
	dec a
	 jp m,battle_attack_calculate_opponent_damages_skip
	ld (hl),a
	push bc
	push hl
		call battle_reset_opponent_pokemon_health_bar_and_hp
		ld hl,current_pokemon+CP_HPTOT
		call battle_draw_opponent_pokemon_health_bar+3
		ld de,$0a18
		ld hl,HP_txt
		call draw_text_fast_copy	;draw the new HP and call fastcopy
	pop hl
	pop bc
	djnz battle_menu_damages_loop
battle_attack_calculate_opponent_damages_skip:
	ld de,$0a18
	ld hl,HP_txt
	call draw_text_fast_copy	;draw the new HP and call fastcopy
	ld a,(CE)
	cp 1
	 call nz,battle_disp_effectivity
	ld a,(current_pokemon+CP_HP)
	or a
	 jp z,battle_handle_wild_pokemon_ko

	; vérifier les changements d'états
	; vérifier si le pokémon est KO
	; etc...
	; calculer l'exp
	; si c'est contre dresseur : gérer le fric
	; À la fin il faudra penser à retirer l'état confus aux pokémons concernés !!!!!!!!!!!!!
	ret

battle_fight_menu_disp_pp:
	ld bc,$0960
	ld de,$0029
	call draw_frame
;	call battle_find_current_attack
	call find_attack_data
	push hl
	push af
	call find_type
	ld b,3	; ce qui suit c'est pour récupérer le nom du type (j'en ferais peut être une routine pour les autres menus)

battle_fight_menu_next_type_loop:
	ld a,(hl)
	inc hl
	ld d,0
	ld e,a
	add hl,de
	djnz battle_fight_menu_next_type_loop
	ld de,$2a02
	ld (pencol),de
	bcall(_VPutS)
	pop af
	ld c,a
	ld hl,(battle_current_player_pokemon_address)
	call find_pokemon_attack
	inc hl
	ld a,(hl)
	ld de,$2a4b
	ld (pencol),de
	call _vdispa
	ld de,$2a53
	ld (pencol),de
	ld a,$2f
	bcall(_vputmap)
	pop hl
	inc hl	; ld de,attack_pp-attack_data
	inc hl	; add hl,de
	ld a,(hl)
	ld de,$2a57
	ld (pencol),de
	call _vdispa
	jp fast_copy


;- Routine qui se charge de rechercher le prochain pokémon en vie sur les 6 qu'a le joueur + le place dans la liste des pokémons ayant combattus
battle_search_next_player_pokemon_alive:	; output : z:pokémon found ; nz:all pokémon dead ; hl = pokémon datas
	ld hl,player_pokemons
	ld b,6

battle_search_next_player_pokemon_alive_loop:
	ld a,(hl)
	or a	; vérifier qu'il y ait bien un pokémon dans l'emplacement
	jr z,battle_search_next_player_pokemon_alive_skip
	push bc
	push hl
	call find_pokemon_stats
	inc hl
	inc hl	; vérifier s'il est en vie
	ld a,(hl)
	or a
	jp nz,battle_search_next_player_pokemon_alive_ok
	pop hl
	pop bc

battle_search_next_player_pokemon_alive_skip:
	inc hl
	djnz battle_search_next_player_pokemon_alive_loop
	or $80	; reset zero flag ; peut être inutile ?
	ret

battle_search_next_player_pokemon_alive_ok:
	dec hl
	dec hl	; on retourne à l'ID du pokémon (depuis les PV)
	ld (battle_current_player_pokemon_address),hl
	pop hl	; on retourne au numero d'index du pokémon
	ld c,(hl)
	inc c	; on incrémente l'index du pokémon car sinon le pokémon n°0 ne sera jamais comptabilisé
	ld de,pokemon_who_fought
	ld b,6

battle_list_pokemon_who_fought_loop:	; on regarde si le pokémon sélectionné a déjà combattu et si non on le place dans la liste
	ld a,(de)
	cp c
	jr z,battle_list_pokemon_who_fought_skip	; le pokémon a déjà combattu une fois pendant le combat
	or a
	jr z,battle_list_pokemon_who_fought
	inc de
	djnz battle_list_pokemon_who_fought_loop

battle_list_pokemon_who_fought:
	ld a,c
	ld (de),a

battle_list_pokemon_who_fought_skip:
	pop bc
	ld hl,(battle_current_player_pokemon_address)
	xor a	; set zero flag
	ret

;hl points to attacking pokemon's attack id
;de points to attacked pokemon's data
check_attack_effectiveness:
	ld a,(hl)				;a = attack id
	call find_attack_data	;returns hl = pointer to attack data
;first byte is attack type: (type, state, PP, power, accuracy (%), name)
	ld l,(hl)
	ld h,0
	add hl,hl
	ld bc,type_index-2
	add hl,bc
	call ld_hl_hl
	ex de,hl				;swap attack data into hl
	ld a,(hl)				;enemy's pokemon id
	call find_pokemon_data	;put attacked pokemon's data pointer in hl
	ld bc,POKE_TYPE1
	add hl,bc
	push de					;de = start of type data
		ld e,(hl)			;type 1
		inc hl
		ld d,(hl)			;type 2
	pop hl					;hl = start of type data
	call compareTypes
	ld (CE),a
	ret

;check if the attack type has special effects against the pokemon type(s)
compareTypes:
;super effective
	call checkTypes			;if z, then attack is super effective
	ld a,2
	 ret z
check_notEffective:
	inc hl
	call checkTypes			;if z, then attack is super effective
	ld a,0
	 ret z
check_noEffect:
	inc hl
	call checkTypes			;if z, then attack is super effective
	ld a,3
	 ret z
	ld a,1
	ret
checkTypes:
	ld a,(hl)				;check how many types to compare with
	or a					;if 0, then quit
	 jr nz,$+4
		inc a				;set nz
		ret
	ld b,a
checkTypesLoop:
	inc hl
	ld a,e
	cp (hl)
	 ret z
	ld a,d
	cp (hl)
	 ret z
	djnz checkTypesLoop
	ret

;- Routine qui se charge de gérer la mort d'un pokémon ------------------------------------------------------------
battle_handle_player_pokemon_ko:
	pop af	; petit "hack" pour sortir de la boucle de combat
	jp _v_disp_pause	; dire "machin est mort" et gérer la suite

battle_handle_wild_pokemon_ko:	; hl = opponent pokemon stats
	ld hl,(battle_current_player_pokemon_address)
	ld (last_player_pokemon_who_fought_address),hl
	call battle_draw_frame		; on commence par afficher "le pokémon ennemi est KO"
	ld hl,battle_str_opponent_ko
	call draw_battle_dialogue
	ret
;i haven't started to handle experience
	ld hl,pokemon_who_fought
	ld bc,$0600
battle_check_how_many_pokemon_fought_loop:
	ld a,(hl)
	or a
	jr z,battle_check_how_many_pokemon_fought
	inc hl
	inc c
	djnz battle_check_how_many_pokemon_fought_loop

battle_check_how_many_pokemon_fought:
	; ici : hl = opponent pokemon stats, c = nombre de pokémons ayant participé au combat
	ld hl,(battle_current_opponent_pokemon_address)
	ld b,(hl)					;id
	inc hl
	ld a,(hl)					;level
	ld hl,GSTATS_LENGTH
	call slow_mult_hl_b
	ld de,pokemon_general_stats+POKE_EXP
	add hl,de
	call calculate_experience	; on calcule l'experience gagnée et on la divise par le nombre de pokémon du joueur qui ont participé
	pop bc
	ld hl,pokemon_who_fought
	ld b,c

battle_experience_distribution_loop:
	push bc
	dec (hl)	; le numero d'index = +1 (cf search_next_pokemon_alive)
	push hl
	push af
	push hl
	call battle_draw_frame
	pop hl
	call find_pokemon_stats
	push hl
	call battle_disp_player_pokemon_name
	ld a,vmode_type_no_pause
	ld (_v_mode),a
	ld hl,battle_str_experience_earned
	call _VPutS_ml
	pop hl
	pop af
	push af
	push hl
	call _vdispa
	ld hl,battle_str_experience_earned_next
	call battle_disp_vputs
last_player_pokemon_who_fought_address = $+1
	ld de,0
	pop hl	; hl = ID du pokémon dont on s'occupe (depuis pokemon_stats)
	cp_hl_de()
	ld a,0
	call nz,inc_a
	ld (battle_inc_experience_bar_no_draw),a
	ld (battle_current_player_pokemon_address),hl
	ld d,0
	ld e,pokemon_xp-pokemon_stats
	add hl,de
	pop af
	push af
	ld b,a
	push hl
	call calculate_next_experience
	pop hl

battle_inc_experience_bar:
	push bc
	push hl
	call ldhlind_no_little_indian
	inc hl	; inc experience
	ld b,h
	ld c,l
	pop hl
	push hl
	ld (hl),b
	inc hl
	ld (hl),c
	dec hl
	push hl
battle_inc_experience_bar_no_draw = $+1
	ld a,0
	or a
	jr nz,battle_inc_experience_bar_skip
	push de
	call battle_draw_player_pokemon_experience_bar
	call fast_copy
	pop de
	pop hl

battle_inc_experience_bar_skip:
	cp_hl_de()
	push de
	call z,battle_inc_lvl
	pop de
	pop hl
	pop bc
	djnz battle_inc_experience_bar
	pop af
	pop hl
	inc (hl)
	inc hl
	pop bc
	djnz battle_experience_distribution_loop
	pop af
	jp _v_disp_pause	; pour l'instant, on quitte le combat (en vrai il faudrait téléporter le joueur au pokécenter)

battle_inc_lvl:	; ici, hl=XP
	ld hl,(battle_current_player_pokemon_address)
	inc hl	; on retourne au niveau du pokémon
	inc (hl)	; on l'augmente
	push hl
	call battle_draw_frame
	pop hl
	push hl
	dec hl
	call battle_disp_player_pokemon_name
	ld a,vmode_type_no_pause
	ld (_v_mode),a
	ld hl,battle_str_level_up
	call _vputs_ml
	pop hl
	push hl
	ld a,(hl)
	call _vdispa
	ld a,$21
	bcall(_vputmap)	; affiche "!"
	call _v_disp_pause
	pop hl
	push hl
	dec hl		; on retourne à l'ID du pokémon pour vérifier s'il apprend des attaques ou s'il évolue
	;call find_pokemon_data_sprite
	ld e,POKE_ATK_LIST
	add hl,de	; hl=pokemon attacks
	ld b,(hl)	; nombre d'attaques
	pop de
	ld a,(de)	; a=niveau actuel
	push de
	push hl
	push af
	inc hl
	call battle_check_new_attacks
	pop af
	pop hl

battle_check_evolution:
	ld d,0
	ld e,(hl)
	add hl,de
	add hl,de
	inc hl	; hl = lvl to evolve
	cp (hl)
	jp nz,battle_handle_next_experience_max
; gérer l'évolution du pokémon
	push hl
	bcall(_grbufclr)
	call battle_draw_frame	; clear entire screen then redraw the text frame
	ld hl,(battle_current_player_pokemon_address)
	push hl
	call battle_disp_evolution_things	; write "What ? [Pokémon][...]
	ld hl,battle_str_evolution_end
	call _v_type	; [...]is evolving !" (this has been splitted to allow to reuse it when we cancel the evolution)
	pop hl	; hl = pokémon ID
	push hl
	call find_and_flip_sprite	; self explaining
	call battle_draw_evolution	; draw the sprite in the center of the screen
	pop de	; de = pokémon ID
	pop hl
	inc hl	; hl = evoluted pokémon ID
	ld b,battle_evolution_blink_sprite_times

evolution_loop:
	ld a,$ff	; reset the keyboard port
	out (1),a
	ld a,$df
	out (1),a	; check if alpha (=B) is pushed
	in a,(1)
	bit 7,a
	jr z,battle_cancel_evolution	; if so, cancel the evolution
	push bc
	push de
	push hl
	ex de,hl	; hl = non evoluted pokémon ID
	call find_and_flip_sprite
	call battle_draw_evolution	; just to erase or draw it from the screen (since it's XORed)
	ld b,battle_evolution_blink_sprite_speed
	call wait
	pop hl	; hl = evoluted pokémon ID
	push hl
	call find_and_flip_sprite
	call battle_draw_evolution	; same thing with the evoluted pokémon sprite
	pop hl
	pop de
	pop bc
	djnz evolution_loop
	push hl	; hl = evoluted pokémon ID
	push de	; de = non evoluted pokémon ID
	call battle_draw_evolution	; to draw the evoluted pokémon sprite (erased in the last loop, if battle_evolution_blink_sprite_times was even)
	call battle_draw_frame
	pop hl
	call battle_disp_player_pokemon_name
	ld hl,battle_str_evolution_done
	ld a,vmode_type_no_pause
	ld (_v_mode),a
	call _vputs_ml
	pop hl
	push hl
	call battle_disp_player_pokemon_name
	;ld hl,battle_player_pokemon_intro2	; " !"
	;call battle_disp_vputs
	pop de
	ld hl,(battle_current_player_pokemon_address)
	ld a,(de)
	ld (hl),a

battle_handle_next_experience_max:
	ld hl,(last_player_pokemon_who_fought_address)
	ld (battle_current_player_pokemon_address),hl
	ld d,0
	ld e,pokemon_xp-pokemon_stats
	add hl,de
	ld (hl),0	; on remet l'experience à 0
	jp battle_draw_screen

battle_cancel_evolution:
	; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	; TODO : FAIRE EN SORTE D'AFFICHER LE BON SPRITE (PARFOIS C'EST CELUI DU POKEMON EVOLUE)
	; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	call battle_draw_frame
	ld hl,(battle_current_player_pokemon_address)
	call battle_disp_evolution_things
	ld hl,battle_str_evolution_cancelled
	call battle_disp_vputs
	jr battle_handle_next_experience_max

battle_check_new_attacks:
	cp (hl)
	inc hl
	jr z,battle_new_attack
	inc hl
	djnz battle_check_new_attacks
	ret

battle_new_attack:
	push hl
	push de
	call battle_draw_frame
	pop de
	dec de
	ex de,hl
	call battle_disp_player_pokemon_name
	ld a,vmode_type_no_pause
	ld (_v_mode),a
	ld hl,battle_str_learn_attack
	call _vputs_ml
	pop hl
	push hl
	;call find_attack
	;ld d,0
	;ld e,attack_name-attack_data
	;add hl,de
	;call battle_disp_vputs
	ld bc,$0f2b
	ld de,$3523
	call draw_frame
	ld de,$243b
	ld (pencol),de
	xor a
	ld (_v_mode),a
;	ld (menu_cursor),a
	ld hl,battle_str_learn_attack_valid
	call _vputs_ml
	ld a,1
;	ld (menu_max_option),a
	add a,35
;	ld (menu_cursor_y),a
	add a,19
;	ld (menu_cursor_x),a
	ld hl,battle_new_attack_valid
;	ld (menu_valid_addr),hl
	ld hl,battle_new_attack_cancel
;	ld (menu_cancel_addr),hl
;	call draw_menu_cursor
;	jp menu_handle

battle_new_attack_valid:
;	ld a,(menu_cursor)
	or a
	jp nz,battle_new_attack_cancel

battle_new_attack_valid_skip:
	call battle_draw_screen
	xor a
;	ld (first_attack_id),a
;	ld (second_attack_id),a
;	ld (third_attack_id),a
;	ld (fourth_attack_id),a
	inc a
;	ld (menu_max_option),a
	inc a
;	ld (menu_cursor_x),a
	add a,48
;	ld (menu_cursor_y),a
	call battle_draw_fight_menu
;	ld a,4
;	ld (battle_fight_menu_choices),a
;	ld hl,battle_learn_new_attack_valid
;	ld (menu_valid_addr),hl
;	ld hl,battle_new_attack_cancel
;	ld (menu_cancel_addr),hl
;	ld hl,battle_find_current_attack
;	ld (menu_oncursor_call_addr),hl
;	ld hl,battle_menu_down
;	ld (menu_down_addr),hl
;	ld hl,menu_up
;	ld (menu_up_addr),hl
;	ld hl,battle_menu_left
;	ld (menu_left_addr),hl
;	ld hl,battle_fight_menu_right
;	ld (menu_right_addr),hl
;	call draw_menu_cursor
;	jp menu_handle

battle_learn_new_attack_valid:
;	ld a,(menu_cursor)
	ld (selected_attack_slot),a
;	ld a,(menu_cursor_x)
	ld (old_menu_cursor_x),a
	ld a,(current_attack)
	or a
	jr z,battle_learn_new_attack_ok	; le slot est libre pour une nouvelle attaque
	call battle_draw_screen	; ou pas
	call battle_draw_frame	; smaller than having to do "ld de,$3202\	ld (pencol),de"

	ld a,vmode_type_no_pause
	ld (_v_mode),a
	ld hl,battle_str_are_you_sure
	call _vputs_ml
	ld bc,$0f13
	ld de,$4d23
	call draw_frame
	ld de,$2453
	ld (pencol),de
	xor a
	ld (_v_mode),a
;	ld (menu_cursor),a
	ld hl,battle_str_yes_no
	call _vputs_ml
	ld a,1
;	ld (menu_max_option),a
	add a,35
;	ld (menu_cursor_y),a
	add a,43
;	ld (menu_cursor_x),a
	ld hl,battle_learn_new_attack_valid_empty_slot
;	ld (menu_valid_addr),hl
	ld hl,battle_new_attack_valid_skip
;	ld (menu_cancel_addr),hl
;	call draw_menu_cursor
;	jp menu_handle

battle_learn_new_attack_valid_empty_slot:
;	ld a,(menu_cursor)
	or a
	jp nz,battle_new_attack_valid_skip

battle_learn_new_attack_ok:
	ld hl,(battle_current_player_pokemon_address)
	ld de,pokemon_attacks-pokemon_stats
	add hl,de
selected_attack_slot = $+1
	ld a,0
	or a
	jr nz,battle_learn_new_attack_second_line
old_menu_cursor_x = $+1
	ld a,0
	cp 2
	xor a
	call nz,inc_a
	jr battle_finally_learn_new_attack

battle_learn_new_attack_second_line:
	inc a	; a = 2
	ld b,a
	ld a,(old_menu_cursor_x)
	cp b
	ld a,b
	call nz,inc_a

battle_finally_learn_new_attack:
	ld d,0
	ld e,a
	add hl,de	; skip attack ID
	add hl,de	; skip PP
	pop de	; de = attack ID
	ld a,(de)
	ld (hl),a
	push hl
	;call find_attack_a
	inc hl	; ld de,attack_pp-attack_data
	inc hl	; add hl,de
	ld a,(hl)	; get PP #
	pop hl
	inc hl
	ld (hl),a
	ret

battle_new_attack_cancel:
	pop de	; de = attack ID
	ret
;------------------------------------------------------------------------------------------------------------------

pokemon_who_fought:
	.db 0,0,0,0,0,0

opponent_pokemon_stats:	; ID, lvl, PV, state (0=normal; 1=poison; 2=sleep; 3=para), (Attack ID, PP)*4, Exp (2 bytes)
	.db 0

opponent_pokemon_stats_lvl:
	.db 0

opponent_pokemon_stats_hp:
	.db 0

opponent_pokemon_stats_state:
	.db 0

opponent_pokemon_stats_attacks:
	.db 0,0,0,0,0,0,0,0

opponent_pokemon_stats_exp:
	.dw 0

	.db 0,0,0,0,0,0,0,0,0,0,0 \ .dw 0
	.db 0,0,0,0,0,0,0,0,0,0,0 \ .dw 0
	.db 0,0,0,0,0,0,0,0,0,0,0 \ .dw 0
	.db 0,0,0,0,0,0,0,0,0,0,0 \ .dw 0
	.db 0,0,0,0,0,0,0,0,0,0,0 \ .dw 0

opponent_pokemon_stats_length:

opponent_pokemon_lvl:	; en attendant de s'en servir
	.db 0
