get_key:
	out (1),a
	push af				; delay for slow keyboard drivers
	pop af
	in a,(1)
	ret

release_key:
	xor a
	call get_key
	inc a
	jr nz,release_key
	ret

inc_a:
	inc a
	ret

find_player_pokemon: ; output : hl=selected pokemon ID from the pokemon menu, de=player_pokemons
	ld hl,(selected_pokemon)
	ld h,0
	ld de,player_party
	add hl,de
	ret

find_pokemon_stats:	; hl=pokemon index # ; output : hl=pokemon stats
	ld a,(hl)

find_pokemon_stats_a:
	or a
	ret z
	ld hl,pokemon_stats
	ld bc,pokemon_stats_length-pokemon_stats

find_pokemon_stats_loop:
	add hl,bc
	dec a
	jp nz,find_pokemon_stats_loop
	or a
	sbc hl,bc
	ret

find_pokemon_attack:	; input : hl=pokemon stats, c=attack id ; output : z:attack found, nz:attack not found, hl=attack data
	ld d,0
	ld e,pokemon_attacks-pokemon_stats
	add hl,de
	ld b,4
find_pokemon_attack_loop:
	ld a,(hl)
	cp c
	ret z
	inc hl
	inc hl
	djnz find_pokemon_attack_loop
	or $80	; reset zero flag
	ret

;takes an attack id of the current pokemon (1-4) and goes to that attacks data
find_attack_data_current_pokemon_id:
;	add a,a						;each attack takes up 2 bytes, its ID and PP left
	ld e,a
	ld d,0
	ld hl,current_pokemon+CP_ATK1
	add hl,de					;find the attack chosen
	ld a,(hl)

;input: a = attack id
;output: hl = start of attack data
find_attack_data:
	ld l,a
	ld h,0
	add hl,hl
	ld bc,attack_index-2	;on commence à 1, parce que 0 = un attaque vide
	add hl,bc
	ld a,(hl)
	inc hl
	ld h,(hl)
	ld l,a
	ret

find_pokemon_data:
	ld l,a					;l'id pokédex du pokémon
	ld h,0
	ld b,GSTATS_LENGTH
	call slow_mult_hl_b
	ld bc,pokemon_general_stats
	add hl,bc
	ret

find_type:
	ld a,(hl)
	ld hl,type_index
	;jp find_pokemon_data_loop
	ret

find_map_data:	; input : hl = list of map adress & pointers, b = iterations
	ld de,(mapAddr)

find_map_data_loop:	;compare the map address with the list of each pokémons encounterable by maps
	push hl
	call ld_hl_hl
	cp_hl_de()
	pop hl
	inc hl	;first word (2 bytes) = map address
	inc hl	;/
	ret z
	inc hl	;second word = address of the map pokémons
	inc hl	;/
	djnz find_map_data_loop
	ret

is_already_captured:	; input : a=id ; output : z:already captured, nz:not captured
	ld hl,pokemon_stats
	ld b,(pokemon_stats_end-pokemon_stats)/(pokemon_stats_length-pokemon_stats)

is_already_captured_loop:
	cp (hl)
	ret z
	ld d,0
	ld e,pokemon_stats_length-pokemon_stats
	add hl,de
	djnz is_already_captured_loop
	or $80
	ret

generate_wild_pokemon:
	ld hl,opponent_pokemon_stats	;reset opponent pokémons datas
	ld (hl),0
	ld de,opponent_pokemon_stats+1
	ld bc,opponent_pokemon_stats_length-opponent_pokemon_stats-1
	ldir
	ld hl,map_pokemons
	ld b,(map_pokemons_end-map_pokemons)/4
	call find_map_data
	ret nz	;no data on encounterable Pokémons so no battle...

generate_wild_pokemon_find_map_data_ok:
	call ld_hl_hl	; on a les données des pokémons (ID et amplitudes des niveaux)
	ld a,(hl)		; nombre maximum de pokémons
	ld b,a
	call random
	ld d,0
	ld e,a			; on en choisit un au hasard (faudrait peut être gérer la rareté ?)
	inc hl			; premier pokémon
	add hl,de		; ou plus
	add hl,de		;  |
	add hl,de		; /		*3
	ld a,(hl)
	ld (opponent_pokemon_stats),a	; on a l'ID du pokémon, maintenant faut tirer un niveau au hasard
	push af
		inc hl
		push hl			; niveau min
			inc hl
			ld b,(hl)	; niveau max
			call random
		pop hl
		add a,(hl)
		ld (opponent_pokemon_stats_lvl),a	; on a son niveau
	pop af					; maintenant on s'occupe de ses PV
	call find_pokemon_data
	inc hl					;sauter deux octets du string
	inc hl					;hl pointe sur PV
	ld a,(opponent_pokemon_stats_lvl)
	push hl
		call calculate_hp	; on calcul ses pv en fonction de son niveau
	pop hl
	ld (opponent_pokemon_stats_hp),a
	xor a
	ld (opponent_pokemon_stats_state),a
	ld d,0
	ld e,POKE_ATK_LIST-2 	;because we've already skipped two bytes (string name)
	add hl,de
	call ld_hl_hl			;hl now points to the list of attacks
	ld b,(hl)				;b = number of attacks pokemon can learn by level
	inc hl					;start of attack list
	ld c,0					;count how many attacks were processed
	ld a,(opponent_pokemon_stats_lvl)
;find the first attack that is above cur. pokemon's level
; and load the previous 4 attacks, or c attacks if the pokemon
; hasn't learned 4 attacks yet
generate_wild_pokemon_loop:
	cp (hl)
	inc hl					;attack id
	 jr c,generate_wild_pokemon_save_attack
	inc c					;how many attacks the pokemon has learned so far
	inc hl					;start of next attack's data (level learned)
	djnz generate_wild_pokemon_loop

generate_wild_pokemon_save_attack:
;first make sure that the pokemon has at least 4 attacks
	ld a,c ;total number of attacks
	cp 4
	 jr c,$+4
		ld a,4					;if more than 4 attacks have been learned, limit to the last 4
	ld b,a
	dec hl
	dec hl
	djnz $-2					;first attack the pokemon knows
	ld b,a
	ld de,opponent_pokemon_stats_attacks	;store attacks here

generate_wild_pokemon_save_attack_ok:
	ld a,(hl)
	ldi							;store attack ID
	exx
		call find_attack_data	;a = attack id, returns hl = start of attack's data
		inc hl					;skip type
		inc hl					;skip state
		ld a,(hl)				;max PP
	exx
	ld (de),a					;store attack PP
	inc hl						;next attack ID
	inc de						;next attack ID (skip level learned)
	djnz generate_wild_pokemon_save_attack_ok
	ret

wait:
	ei

wait_loop:
	halt
	djnz wait_loop
	di
	ret

jp_hl:
	jp (hl)


_VPutS_ml:	;	_v_mode: 0=text is directly drawn; 1=text is typing; 2=text is typing with no pause at end (cf battle)	|	string:$d6=new line; $07=pause and next text
	ld a,(penCol)
	push af
	push hl

_v_inc_loop:
	ld a,(hl)
	cp $d6
	jr z,_v_replace_zero
	cp 7
	jr z,_v_pause
	or a
	jp z,_v_disp_end
	inc hl
	jr _v_inc_loop

_v_replace_zero:
	ld (hl),0
	ex de,hl
	pop hl
	push de
	ld a,(_v_mode)
	or a
	 jr nz,$+5
		call draw_string
	call nz,_v_type
	pop de
	pop af
	push af
	push hl
	call _v_new_line
	ex de,hl
	ld (hl),$d6
	inc hl
	jr _v_inc_loop

_v_pause:
	ld (hl),0
	ex de,hl
	pop hl
	push de
	ld a,(_v_mode)
	or a
	 jr nz,$+5
		call draw_string
	call nz,_v_type
	push hl
	call _v_disp_pause
	pop hl
	pop de
	push hl
	xor a
	call _v_new_text
	ex de,hl
	ld (hl),7
	inc hl
	jr _v_inc_loop

_v_disp_pause:
_v_disp_no_pause = $+1
	ld a,0
	or a
	ret nz
	call _v_disp_pause_blink

_v_disp_pause_loop:
_v_disp_pause_count = $+1
	ld a,0
	inc a
	ld (_v_disp_pause_count),a
	cp scroll_cursor_speed
	call z,_v_disp_pause_blink
	ld b,1
	call wait
	ld a,$bf
	out (1),a
	in a,(1)
	bit 5,a
	ret z
	jr _v_disp_pause_loop

_v_disp_pause_blink:
	xor a
	ld (_v_disp_pause_count),a
	ld a,86
	ld l,54
	ld b,8
	ld ix,scroll_cursor_sprite
	call putSprite
	jp fastCopy

_v_disp_end:
	pop hl
	pop af
	ld a,(_v_mode)
	or a
	push af
	 jr nz,$+5
		call draw_string
	pop af
	push af
	call nz,_v_type
	pop af
	cp 1
	jr z,_v_disp_pause
	ret

_v_new_line:
	push af
	ld a,(_v_mode)
	cp vmode_type_no_pause
	pop bc
	call z,_v_new_line_battle
	ld a,b
	ld (penCol),a
	ld a,(penRow)
	add a,6
	ld (penRow),a

_v_new_line_battle:
	ld b,2
	ret

_v_new_text:	;	a:0=frame on the bottom ; 1=frame on the top ; 2=battle frame
	push de
	push bc
	push hl
	push af
	ld a,2
	ld (penCol),a
	ld (penRow),a
	dec a
	ld (_v_mode),a
	pop af
	or a
	jr z,dialogue_down
	cp 1
	jr z,dialogue_up
	ld a,50
	ld (penRow),a
	ld bc,$600f
	ld de,$0031
	jr dialogue_end

dialogue_up:
	ld bc,$1560
	ld de,0
	jr dialogue_end

dialogue_down:
	ld a,44
	ld (penRow),a
	ld bc,$1560
	ld de,$002b

dialogue_end:
	call draw_frame	; bcall(_DrawRectBorder not available on 83
	call fastCopy
	pop hl
	pop bc
	pop de
	ret

_v_type:
	ld a,$df
	out (1),a
	in a,(1)
	bit 7,a
	jr z,_v_type_skip

	ld a,(hl)
	or a
	ret z
	inc hl
	cp 7
	jr z,_v_type
	cp $d6
	jr z,_v_type

	push bc
	ld b,5
	call wait
	pop bc

	bcall(_VPutMap)
	push hl
	call fastCopy
	pop hl
	jr _v_type

_v_type_skip:
	call draw_string
	push hl
	call fastCopy
	pop hl
	ret

fade_out:
	ld a,(contrast)
	ld b,a

fade_out_loop:
	push bc
	ld a,b
	ld (contrast),a
	add a,$18
	or $c0
	bcall(_lcd_busy)
	out (10h),a
	ld b,fade_speed
	call wait
	pop bc
	djnz fade_out_loop
	ret

fade_in:
	ld hl,contrast
	ld a,(contrast_var)
	sub (hl)
	ld b,a

fade_in_loop:
	push bc
	inc (hl)
	ld a,(hl)
	add a,$18
	or $c0
	bcall(_lcd_busy)
	out (10h),a
	ld b,fade_speed
	call wait
	pop bc
	djnz fade_in_loop
	ret

flash_screen:
	push bc
	ld bc,$4060
	ld de,0
	call rectangle_filled_xor
	call fastCopy
	pop bc
	djnz flash_screen
	ret

ldhlind_no_little_indian:
	ld a,(hl)
	inc hl
	ld l,(hl)
	ld h,a
	ret

;####################### Rectangles and dialog boxes #######################

draw_frame:
	call rectangle_filled_solid
	inc d
	inc e
	dec b
	dec b
	dec c
	dec c
	jp rectangle_filled_xor

#define GBUF_LSB	$40
#define GBUF_MSB	$93

;b = height
;c = width
;d = starting x
;e = starting y
rectangle_filled_white:			; this just draws a filled rectangle then XORs the same rectangle over top
	call rectangle_filled_solid	; .. essentially drawing two rectangles

rectangle_filled_xor:			; draw a filled rectangle with XOR logic
	set rectXOR,(iy+pokeFlags)	; set the XOR flag
	jr rectangle_filled2

rectangle_filled_solid:			; draw a filled rectangle with OR logic (everything to black)
	res rectXOR,(iy+pokeFlags)	; reset XOR flag (use OR)

rectangle_filled2:
	push de
	push bc
		ld a,d			;starting x
		and $7			;what bit do we start on?
		ex af,af'
		ld a,d			;starting x
		ld l,e			;ld hl,e
		ld h,0			; ..
		ld d,h			;set d = 0
		add hl,de		;starting y * 12
		add hl,de		;x3
		add hl,hl		;x6
		add hl,hl		;x12
		rra				;a = x coord / 8
		rra				;
		rra				;
		and %00011111	;starting x/8 (starting byte in gbuf)
		add a,GBUF_LSB
		ld e,a			;
		ld d,GBUF_MSB	;
		add hl,de		;hl = offset in gbuf
		ex af,af'
		ld d,a
		ld a,%10000000
		jr z,$+6
		rra
		dec d
		jr nz,$-2
		ld e,12
rectangle_loop_x:
		push af
		push bc
		push hl
			ld c,a
rectangle_loop_y:
			bit rectXOR,(iy+pokeFlags)	; check if the rectangle XOR flag is set
			 jr nz,$+5					; jr ------>--------->------->-------\
				or (hl)					; if rectXOR is reset, use OR logic   |
				jr $+3					;                                     |
			xor (hl)					; if rectXOR is set, use XOR logic <-/
			ld (hl),a
			ld a,c
			add hl,de
			djnz rectangle_loop_y
		pop hl
		pop bc
		pop af
		rrca
		jr nc,$+3
		inc hl
		dec c
		 jr nz,rectangle_loop_x
rectangle_end:
	pop bc
	pop de
	ret

;------------------------------------------------------------------------------------------------------------------

find_and_flip_sprite:
	call battle_find_sprite
	ld bc,pokemon_sprite_size

;###########################
flip_sprite:
;# Input:
;# - ix=sprite
;# - b=height
;# - c=width/8
;# Output:
;# - ix=flipped sprite
;# destroys a, de, hl
;# uses flipSpriteBuf
;###########################
	push bc
		push ix						; put ix into de
		pop de
		ld hl,flipSpriteBuf			; where to store the sprite
flip_sprite_outer:
;de = original sprite
;hl = buffer
		push bc						; save b (sprite height)
			ld b,0					; bc = width in bytes
			add hl,bc				; go to very right of first sprite and draw leftward
			push hl
				ld b,8
flip_sprite_loop:
				dec hl				; go left in buffer
				push bc				; c gets overwritten so we need to save it
						ld a,(de)	; first byte in a
						rrca		; rotate a to the right 
						rl c		; .. and rotate the carry left into c
					 djnz $-3
					ld (hl),c		; save flipped byte
					inc de			; next byte of sprite
				pop bc				; c = counter (number of bytes to flip)
				dec c
				 jr nz,flip_sprite_loop
			pop hl
		pop bc						; restore b (height)
		djnz flip_sprite_outer
		ld ix,flipSpriteBuf
	pop bc
	ret

D_ZT_STR:
	bcall(_PutC)
	inc hl
	ld a,(hl)
	or a
	jr nz,D_ZT_STR
	ret

;random must return from 0-127
RAND:
	push	hl
	push	de
	push	bc
;	ld b,127	ld	hl,(randData)
	ld	hl, ($FE8D)
	ld	a, r
	ld	d, a
	ld	e, (hl)
	add	hl, de
	add	a, l
	xor	h
	ld	($FE8D), a
;	sbc	hl,hl
;	ld	e, a
;	ld	d, h
iRandomLp:
;	add	hl, de
;	djnz	iRandomLp
;	ld a,h
	rra
	pop bc
	pop	de
	pop	hl
	ret

ld_hl_hl:
	ld a,(hl)
	inc hl
	ld h,(hl)
	ld l,a
	ret

;multiplies e*h and puts the result into hl
;destroys b and d
;'a' and 'e' unmodified
;hl = e*h
mult_EH:
	ld l,0
	ld d,l		;set l and e to 0
	ld b,8
mEH_boucle:		;hl=e*h
	add hl,hl
	jr nc,mEH_noAdd
	add hl,de
mEH_noAdd:
	djnz mEH_boucle
	ret


;#### Ion routines ####

fastCopy:
	ld	a,$80			; 7
	out	($10),a			; 11
	ld	hl,gbuf-12-(-(12*64)+1)		; 10
	ld	a,$20			; 7
	ld	c,a				; 4
	inc	hl				; 6 waste
	dec	hl				; 6 waste
fastCopyAgain:
	ld	b,64			; 7
	inc	c				; 4
	ld	de,-(12*64)+1	; 10
	out	($10),a			; 11
	add	hl,de			; 11
	ld	de,10			; 10
fastCopyLoop:
	add	hl,de			; 11
	inc	hl				; 6 waste
	inc	hl				; 6 waste
	inc	de				; 6
	ld	a,(hl)			; 7
	out	($11),a			; 11
	dec	de				; 6
	djnz	fastCopyLoop	; 13/8
	ld	a,c				; 4
	cp	$2B+1			; 7
	jr	nz,fastCopyAgain	; 10/1
	ret					; 10

random:
	push	hl
	push	de
	ld	hl,(randData)
	ld	a,r
	ld	d,a
	ld	e,(hl)
	add	hl,de
	add	a,l
	xor	h
	ld	(randData),hl
	sbc	hl,hl
	ld	e,a
	ld	d,h
randomLoop:
	add	hl,de
	djnz	randomLoop
	ld	a,h
	pop	de
	pop	hl
	ret

;-----> Draw a sprite
; b=size of sprite
; l=yc
; a=xc
; ix holds pointer
putSprite:
	ld	e,l
	ld	h,$00
	ld	d,h
	add	hl,de
	add	hl,de
	add	hl,hl
	add	hl,hl
	ld	e,a
	and	$07
	ld	c,a
	srl	e
	srl	e
	srl	e
	add	hl,de
	ld	de,gbuf
	add	hl,de
putSpriteLoop1:
sl1:	ld	d,(ix)
	ld	e,$00
	ld	a,c
	or	a
	jr	z,putSpriteSkip1
putSpriteLoop2:
	srl	d
	rr	e
	dec	a
	jr	nz,putSpriteLoop2
putSpriteSkip1:
	ld	a,(hl)
	xor	d
	ld	(hl),a
	inc	hl
	ld	a,(hl)
	xor	e
	ld	(hl),a
	ld	de,$0B
	add	hl,de
	inc	ix
	djnz	putSpriteLoop1
	ret

;-----> Draw a picture
;Input:	ix->sprite
;	a=x
;	l=y
;	b=height	(in pixels)
;	c=width		(in bytes, e.g. 2 would be 16)
;Output: nothing
; All registers are destroyed except bc', de', hl'
largeSprite:
	di
	ex	af,af'
	ld	a,c
	push	af
	ex	af,af'
	ld	e,l
	ld	h,$00
	ld	d,h
	add	hl,de
	add	hl,de
	add	hl,hl
	add	hl,hl
	ld	e,a
	and	$07
	ld	c,a
	srl	e
	srl	e
	srl	e
	add	hl,de
	ld	de,gbuf
	add	hl,de
largeSpriteLoop1:
	push	hl
largeSpriteLoop2:
	ld	d,(ix)
	ld	e,$00
	ld	a,c
	or	a
	jr	z,largeSpriteSkip1
largeSpriteLoop3:
	srl	d
	rr	e
	dec	a
	jr	nz,largeSpriteLoop3
largeSpriteSkip1:
	ld	a,(hl)
	xor	d
	ld	(hl),a
	inc	hl
	ld	a,(hl)
	xor	e
	ld	(hl),a
	inc	ix
	ex	af,af'
	dec	a
	push	af
	ex	af,af'
	pop	af
	jr	nz,largeSpriteLoop2
	pop	hl
	pop	af
	push	af
	ex	af,af'
	ld	de,$0C
	add	hl,de
	djnz	largeSpriteLoop1
	pop	af
	ret
