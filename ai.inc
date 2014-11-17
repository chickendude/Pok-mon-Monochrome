battle_wild_pokemon_ai:	; pas très compliqué, il se contente d'attaquer
	ld hl,(battle_current_opponent_pokemon_address)
	call load_pokemon_data		;load pokémon's data into current_pokemon
wild_attack_loop:
	ld b,4
	call random
	ld hl,opponent_pokemon_stats_attacks
	add a,a
	ld e,a
	ld d,0
	add hl,de	; on choisit une attaque au hasard
	ld a,(hl)
	or a
	 jr z,wild_attack_loop	; il sera plus simple de dénombrer les attaques
	push hl
; pour l'instant je ne vérifie pas le nombre de PP... peut être plus tard ?
		ld a,e
		add a,_AT1
		ld (current_attack),a	;store the attack name we want to draw in the battle_str_attack string
		ld hl,battle_str_attack
		call draw_battle_dialogue	;draw the attack text (XXX used XXX)
	pop hl
	ld de,(battle_current_player_pokemon_address)
	call check_attack_effectiveness	; vérifier en fonction des types si c'est super efficace
	cp 3						; si l'attaque n'a pas d'effet pas besoin de calculer les dommages
	 jp z,battle_attack_calculate_player_damages_skip
	ld hl,(battle_current_opponent_pokemon_address)	;hl = attacking
	ld de,(battle_current_player_pokemon_address)	;de = defending
	call calculate_damages		;put the damage to be done into a
	 jp c,battle_attack_missed
	push af						;save damage to be done
		call battle_draw_screen
		ld hl,(battle_current_player_pokemon_address)
		call battle_player_pokemon_blink_sprite
		ld hl,(battle_current_player_pokemon_address)
		call load_pokemon_data	;store pokémon into current_pokemon
	pop bc						;b = number of damage to be done
	ld hl,(battle_current_player_pokemon_address)
	inc hl						;skip id
	inc hl						;skip level
	ld a,(hl)					;load HP
	sub b
	 jr nc,$+3
		xor a
	ld (hl),a
battle_wild_pokemon_ai_damages_loop:
	ld hl,current_pokemon+CP_HP	;we've loaded the enemy pokémon's current stats here
battle_player_damages_loop:
	ld a,(hl)			;check if pokémon has no HP left
	dec a
	 jp m,battle_attack_calculate_player_damages_skip
	ld (hl),a
	push bc
	push hl
		call battle_reset_player_pokemon_health_bar_and_hp
		ld hl,current_pokemon+CP_HPTOT
		call battle_draw_player_pokemon_health_bar+3
		ld de,$2342
		ld hl,HP_txt
		call draw_text_fastcopy	;draw the new HP and call fastcopy
	pop hl
	pop bc
	djnz battle_player_damages_loop
battle_attack_calculate_player_damages_skip:
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
