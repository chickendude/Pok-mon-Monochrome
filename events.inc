event_cliff_down:
	ld a,(player_direction)
	or a
	 ret nz
	jr event_cliff
event_cliff_right:
	ld a,(player_direction)
	cp 2
	 ret nz
	jr event_cliff
event_cliff_left:
	ld a,(player_direction)
	dec a
	 ret nz
event_cliff:
	ld hl,player_y_offset			; give the player the appearance of jumping
	ld (hl),-3
	push hl
		call player_walk
	pop hl
	ld (hl),0					; reset player's y offset to 0
	jp player_walk

event_grass:
	call player_walk
	ld b,POKEMON_ENCOUNTER_FREQUENCY
	call random
	or a
	ret nz
	ld b,BATTLE_FLASH_SCREEN_FREQUENCY
	call flash_screen
	call fade_out
	jr battle

event_door:
	ld b,BATTLE_FLASH_SCREEN_FREQUENCY
	jp flash_screen
