;hl = pointer to pokémon's data
load_pokemon_data:					; load pokémon data to current_pokemon
	push hl							; save pointer to pokedex id
		inc hl						; skip pokémon id (used later for pokémon name)
		ld de,current_pokemon+CP_LVL
		ld a,(hl)					; level
		ldi							; copy current level
		ld de,current_pokemon+CP_HP
		ldi
		ldi							; copy current HP
		inc hl						; skip pokemon state
;now load the attacks
		ex af,af'					; a' = pokémon level
		ld bc,$04ff					; can have up to four attacks, c is for the ldi
		exx
			ld de,current_pokemon+CP_ATK1STR
		exx
		ld de,current_pokemon+CP_ATK1	; de = where to store attack ID and PP
load_attacks:
		ld a,(hl)					; attack id
		exx
			ld hl,null_text			; default is a pointer to a 0
			or a					; if attack id = 0,
			 jr z,store_attack		; .. store a null text pointer
			call find_attack_data	; otherwise load attack pointer [routines.inc]
			ld bc,ATK_NAME			; there are 5 bytes of data before the string
			add hl,bc				; hl points to string
store_attack:
			ex de,hl
			ld (hl),e				; store string pointer
			inc hl
			ld (hl),d
			inc hl
			ex de,hl
		exx
		ldi							; attack id
		ldi							; attack PP
		ldi							; attack max PP
		djnz load_attacks
		ld de,current_pokemon+CP_EXPTOT
		ldi
		ldi
		ldi
;copier les stats precalculés du pokémon (hp total, attack, defense)
	pop hl							; hl points to pokedex id
	push hl
		call get_pokemon_sprite_ix	; hl = pointer to pokémon sprite [battle_graphics.inc]
		ld (current_pokemon+CP_SPRITE),hl
	pop hl
	ld a,(hl)						; pokémon pokédex id
	call find_pokemon_data			; returns hl = pointer to start of pokémon data
	ex af,af'						; restore a = pokemon level
	push hl
		push af						; save pokémon's level
			inc hl
			inc hl					; first two bytes are the string name pointer
			push hl
				call calculate_hp	; hl = max HP [maths.inc]
				ld (current_pokemon+CP_HPTOT),hl	; store total HP
			pop hl
		pop af						; pokémon level
;load the other values (find the pokemon's attack, defense, max HP, etc.)
		ld de,current_pokemon+CP_ATK
		ld b,4						; ATK, DEF, SPD, SPEC
load_stats_loop:
		inc hl						; base ATK [pokemons.inc]
		push hl						; hl points to pokémon's base stats [pokemons.inc]
		push de						; de points to position in current_pokemon
		push bc						; bc is our counter
		push af						; a holds pokémon level
			call calculate_stats
		pop af
		pop bc
		pop de
		ex de,hl
			ld (hl),e
			inc hl
			ld (hl),d
			inc hl					; save the stat in current_pokemon
		ex de,hl
		pop hl
		djnz load_stats_loop
; find experience needed to get to next level
	pop hl
	push hl
		ld de,POKE_EXP
		add hl,de
		ld e,(hl)						; pokemon's level up rate
		ld a,(current_pokemon+CP_LVL)	; pokemon's level
		call calculate_next_level
		ld (current_pokemon+CP_EXPLVL),hl
; find pokémon name string
	pop hl
	push hl
		call ld_hl_hl
		ld (current_pokemon),hl	;sauver l'adresse du string
	pop hl
; find pokémon type strings
	ld de,POKE_TYPE1
	add hl,de
	ld a,(hl)
	push hl
		call find_type_string
		ld (current_pokemon+CP_TYPE1),hl
	pop hl
	inc hl
	ld a,(hl)
	push hl
		call find_type_string
		ld (current_pokemon+CP_TYPE2),hl
	pop hl
	ret

; input:
; a = type id
; output: hl = string pointer
find_type_string:
	or a
	 jr nz,$+6
		ld hl,null_text			; pointer to a 0
		ret
	ld e,a
	ld hl,type_index-2
	ld d,0
	add hl,de
	add hl,de
	ld a,(hl)
	inc hl
	ld h,(hl)
	ld l,a
	ld b,3						; super effective, not very effective, no effect
find_type_string_loop:
	ld e,(hl)					; number of entries
	inc e						; +1 to skip the number of entries byte
	add hl,de					; skip super effective/not effective types
	djnz find_type_string_loop
	ret

;###########################
create_pokemon:
;# Creates a pokémon and saves
;# .. it in (pokemon_entry)
;# Input:
;# - b = pokédex id
;# - a = pokémon's level
;###########################
	ld (pokemon_entry+PE_LVL),a		; save pokémon's lvl
	push af
		ld a,b
		ld (pokemon_entry+PE_ID),a	; save pokémon's ID
		call find_pokemon_data
	pop af
; hl now points to start of pokémon's data [pokemons.inc]
	inc hl							; skip the string pointer
	inc hl							; 
	push hl
		call calculate_hp			; calculate HP based on level, a = level, hl = pointer to HP
		ld (pokemon_entry+PE_HP),hl	; save pokémon's current HP (starts off full)
	pop hl
	xor a
	ld (pokemon_entry+PE_STATE),a
; fill out attack list based on level
	ld d,a
	ld e,POKE_ATK_LIST-2 			; because we've already skipped two bytes (string name)
	add hl,de
	call ld_hl_hl					; hl now points to the list of attacks
	ld c,(hl)						; b = number of attacks pokemon can learn by levelling up
	inc hl							; start of attack list
	ld c,0							; count how many attacks were processed
	ld a,(pokemon_entry+PE_LVL)		; pokémon's current level in a
; find the first attack that is above cur. pokemon's level
; .. and load the previous 4 attacks, or c attacks if the pokemon
; .. hasn't learned 4 attacks yet
create_pokemon_attacks_loop:
	cp (hl)
	inc hl							; skip attack level
	 jr c,create_pokemon_attacks	; if the attack level > pokémon's level, can't learn any more attacks
	inc c							; how many attacks the pokemon has learned so far
	inc hl							; skip attack id
	djnz create_pokemon_attacks_loop
create_pokemon_attacks:
;first make sure that the pokemon has at least 4 attacks
	ld a,c ;total number of attacks
	cp 4
	 jr c,$+4
		ld a,4						; if more than 4 attacks have been learned, limit to the last 4
	ld b,a
	dec hl
	dec hl
	djnz $-2						; first attack the pokemon knows
	ld b,a
	ld de,opponent_pokemon_stats_attacks	;store attacks here
create_pokemon_save_attacks:
	ld a,(hl)
	ldi								; store attack ID
	exx
		call find_attack_data		; a = attack id, returns hl = start of attack's data
		inc hl						; skip type
		inc hl						; skip state
		ld a,(hl)					; max PP
	exx
	ld (de),a						; store attack PP
	inc hl							; next attack ID
	inc de							; next attack ID (skip level learned)
	djnz create_pokemon_save_attacks
	ret


; player values

player_pokemons_length:

pokemon_stats:	; ID pokédex, lvl, HP (2 bytes), state (0=normal; 1=poison; 2=sleep; 3=para), (Attack ID, PP, PPMAX)*4, XP (2 bytes)
	.db BULBASAUR		; pokédex ID
pokemon_lvl:
	.db 1
pokemon_hp:
	.dw 4
pokemon_state:
	.db 1
pokemon_attacks:
	.db ATK_TACKLE,35,35, 0,0,0, 0,0,0, 0,0,0
pokemon_xp:
	.db 0,0,0
pokemon_stats_length:
	.db IVYSAUR,26, 40,0, 0, ATK_BITE,25,25, ATK_FURY_SWIPES,14,15, ATK_FURY_SWIPES,8,10, 0,0,0, $D2,$55,0
	.db VENUSAUR,32, 20,0, 0, ATK_TACKLE,35,35, ATK_GROWL,20,20, ATK_LEECH_SEED,30,35, ATK_VINE_WHIP,10,10, 0,$A0,0,$ff
pokemon_stats_end:
#define STATS_LENGTH	pokemon_stats_length-pokemon_stats
