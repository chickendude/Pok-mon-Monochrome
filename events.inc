event_down_cliff:
	ld hl,(player_direction)
;	ld de,player_down
	ld bc,walk_down_no_collision
	ld (event_jump_cliff_direction),bc
	jr event_jump_cliff

event_right_cliff:
	ld hl,(player_direction)
;	ld de,(player_right)	; l'adresse est relative au sexe du joueur
	ld bc,walk_right_no_collision
	ld (event_jump_cliff_direction),bc
	jr event_jump_cliff

event_left_cliff:
	ld hl,(player_direction)
;	ld de,(player_left)		; idem
	ld bc,walk_left_no_collision
	ld (event_jump_cliff_direction),bc

event_jump_cliff:
	cp_hl_de()
	ret nz
	ld hl,player_y
	dec (hl)
	dec (hl)
	dec (hl)
	push hl
event_jump_cliff_direction = $+1
	ld hl,0
	call jp_hl
	pop hl
	inc (hl)
	push hl
	ld hl,(event_jump_cliff_direction)
	call jp_hl
	pop hl
	inc (hl)
	inc (hl)
	ret

event_grass:
	ld b,pokemon_encounter_frequency
	call random
	or a
	ret nz
	ld b,battle_flash_screen_frequency
	call flash_screen
	call fade_out
	jr battle

event_door:
	ld b,battle_flash_screen_frequency
	jp flash_screen
