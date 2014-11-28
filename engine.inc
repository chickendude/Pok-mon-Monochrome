;###########################
load_map:
;# loads a new map
;# -a = map number (0-255)
;# -bc = YYXX position
;###########################
	add a,a				; each map takes up 2 bytes
	ld c,a
	ld b,0
	ld hl,map_table
	add hl,bc			; find the map in the map table
	call ld_hl_hl		; ld hl,(hl)
; HL points to start of map data	
	ld a,(hl)			; save map width and height
	ld (map_width),a
	inc hl
	ld a,(hl)
	ld (map_height),a
	inc hl
	ld (map_addr),hl		; start of tilemap
	ld hl,tiles			;*** maybe later we will have multiple tilesets? ***
	ld (tile_addr),hl
	ld (map_x),bc		; load map X and Y coordinates
	ret

;###########################
draw_map:
;# draws the map to the graph buffer
;# input:
;# -none
;###########################
	call get_map_offset	; load starting map tile into hl
	exx
		ld hl,gbuf
		ld de,12		; no. of columns
		ld bc,$0C08		; draw 12 (hex: $0C) columns and 8 rows
draw_row:
		push hl			; save gbuf pointer
	exx
	push hl				; save map location
	ld l,(hl) 			; sprite #
	call get_tile		; load tile into hl
	ld b,8				; each sprite is 8 rows tall
sprite_loop: 
	ld a,(hl)			; byte to draw
	inc hl				; next byte
	exx					; switch to shadow registers
		ld (hl),a
		add hl,de		; next row in gbuf
	exx
	djnz sprite_loop

	pop hl				; map position
	inc hl 
	exx 
		pop hl			; previous gbuf
		inc hl
		djnz draw_row

	exx
	ld a,(map_width)		; we've drawn 12 rows, so we need to skip
	sub 12				;.. map_width-12 bytes to get to the next row in the map
	ld e,a				; d already = 0
	add hl,de			; move to the next row in map
	exx
		ld e,12*7		; 12 colonnes, 7 rangs à baisser
		add hl,de 		; next row in gbuf
		ld e,12			; rendre les valeurs originales à e/b
		ld b,12
		dec c			; c = # rows left to draw
		jr nz,draw_row
	ret

;###########################
get_map_offset:
;# calculates the top left position of the map
;# input:
;# -none
;# output:
;# -hl = top left position in map
;###########################
	ld hl,(map_y-1)	; map's Y position into h
	ld de,(map_width)	; 
	call mult_EH		; hl = mapY*map_width
	ld de,(map_addr)		; de = map address
	add hl,de			; start of map + mapY*map_width
	ld de,(map_x)		; 
	ld d,0				; clear out MSB
	add hl,de			; add map x
	ret

;###########################
get_tile:
;# loads a tile into hl
;# -l = tile id to load
;# output:
;# -hl = pointer to first byte of sprite data
;###########################
	ld h,0				; 
	add hl,hl
	add hl,hl
	add hl,hl			; hl * 8
	ld bc,(tile_addr)
	add hl,bc			; start of sprite's data
	ret


;###########################
draw_player:
;# draws the masked player to the screen
;# .. and save the tile beneath the player
;# .. in player_tile
;# Masks are stored intertwined, like
;# .. this (M'ask, S'prite):
;# .. .db M,S
;# .. .db M,S
;# .. .db M,S
;# .. etc.
;# input:
;# -none
;###########################
	call get_player_gbuf	; find players position in gbuf, put in HL
	ld b,8					; sprite height
	ld de,12
	exx
		ld hl,player_down_sprite	; player's sprite ***
		ld a,(player_direction)
		rlca
		rlca
		rlca
		rlca				; x16 (8 for sprite, 8 for mask)
		ld e,a
		ld d,0
		add hl,de			; add offset to find proper sprite according to
		add hl,de			; .. player's direction
		add hl,de			; .. x3 because each direction has three sprites
		ld a,(walk_anim)	; check what frame we are on
		inc a				; if a = $FF, we are standing still
		 jr z,$+8
			rlca
			rlca
			rlca
			rlca			; a*16
			ld e,a
			add hl,de		; hl points to the current animation sprite
		ld de,player_tile	; where to save the tile the player will cover (used when scrolling the map)
	exx
	ld a,(player_x_offset)
	ld c,a
	or a
	 jr nz,draw_sprite_mask_unaligned
draw_sprite_mask:
	ld a,(hl)				; current byte in gbuf
	exx
		ld (de),a			; save the tile that's behind the player
		inc de
		and (hl)			; apply the mask
		inc hl
		xor (hl)			; draw sprite
		inc hl
	exx
	ld (hl),a				; update gbuf
	add hl,de 				; next row
	djnz draw_sprite_mask
	ret
draw_sprite_mask_unaligned:
	push bc					; b = iterations left, c = x offset
		ld a,c				; load x offset into a
		exx					; [exx]
			ld b,a			; 	.. then load x offset into b
			ld a,(hl)		; 	mask
			ld c,$FF		; 	dummy byte
			inc hl			;	hl' now points to sprite
			ld d,(hl)		; 	sprite
			ld e,0			; 	dummy byte
			inc hl			;	hl' now points to next row in mask
dsm_rotate:
			scf				; 	we need to shift a 1 into the mask
			rra				; 	a = mask
			rr c			; 	c' = overflow
			srl d			; 	d' = sprite byte
			rr e			; 	e' = sprite overflow
			djnz dsm_rotate	; 	repeat for the number of pixels we need to shift over
		exx					; [/exx]
							; * mask = ac'
							; * sprite = d'e'
		and (hl)			; maskLeft AND gbufLeft
		exx					; [exx]
			xor d			; 	spriteLeft, d'
		exx					; [/exx]
		ld (hl),a			; update gbuf
		inc	hl				; move to next byte in gbuf
		ld a,(hl)			; gbufRight
		exx					; [exx]
			and c			; 	maskRight, c'
			xor e			; 	XOR spriteR, e'
		exx					; [/exx]
		ld (hl),a			; update 2nd byte of gbuf
		ld de,11			; we've shifted over one byte in gbuf, so to move down we add 11 (=12-1)
		add	hl,de			; next row gbuf
	pop	bc
	djnz draw_sprite_mask_unaligned
	ret

;###########################
clear_player:
;# clears the player from the screen
;# input/output:
;# -none
;###########################
	call get_player_gbuf	; find players position in gbuf, put in HL
	ld b,8					; sprite height
	ld de,12
	exx
		ld de,player_tile	; where to save the tile the player will cover
	exx		
clear_sprite:
	exx
		ld a,(de)
		inc de
	exx
	ld (hl),a
	add hl,de 				; next row
	djnz clear_sprite
	ret

;###########################
get_player_gbuf:
;# loads players position in gbuf into HL
;# input:
;# -none
;# output:
;# -HL = player's position in gbuf
;###########################
	ld hl,map_x
	ld a,(player_x)
	sub (hl)
	ld e,a					; x position on screen
	ld d,0
	ld a,(player_y)			; (player y - map y)*8
	ld hl,map_y
	sub (hl)
	add a,a					; x2
	add a,a					; x4
	add a,a					; x8
	ld hl,player_y_offset
	add a,(hl)				; add the player's y offset (if they're unaligned)
	ld l,a
	ld h,d
	add a,a					; x2
	add a,l					; x3
	ld l,a
	add hl,hl				; x6
	add hl,hl				; x12 rows of tiles
	add hl,de				; add x position
	ld de,gbuf
	add hl,de
	ret

;###########################
get_player_map:
;# loads players map position into HL
;# input:
;# -bc = YYXX offset (c holds x, b holds y)
;#		 used in collision detection, to check tiles next to player
;# output:
;# -HL = player's position in map
;###########################
	ld a,(player_y)
	add a,b					; add y offset to player y
	ld e,a					; player_y into e
	ld hl,(map_width-1)		; map_width into h
	call mult_EH			; hl = player y * map width
	ld a,(player_x)			; 
	add a,c					; add x offset to player_x
	ld e,a
	ld d,0
	add hl,de
	ld de,(map_addr)
	add hl,de
	ret

;###########################
check_tile:	; z if tile is passable
;# checks a tile for events and if it can be passed
;# input:
;# -a = tile ID
;# output:
;# -z is set if you can walk through the tile
;# -nz means an event has taken place and we should quit
;#	.. the routine or the tile is not passable
;###########################
; first check for events
	ld hl,event_tiles
	ld b,NUM_EVENTS				;chaque évènement occupe trois octets
		cp (hl)
		inc hl
		 jr z,load_event
		inc hl
		inc hl
	 djnz $-6
; now check if we can pass through the tile
	ld hl,passable_tiles
	ld bc,NUM_PASSABLE_TILES
	cpir
	ret

load_event:
	call ld_hl_hl			; get the routine to jump to in HL
	call jp_hl				; call the routine
	xor a					; 
	inc a					; set nz
	ret
	
;###########################
;# force_down, force_up, etc. are used
;# .. to skip tile checking. convenient 
;# .. for use in events, eg. tiles
;# .. that activate when you step on them
;###########################

;###########################
player_walk:
;# This moves the player based on the
;# .. direction they're facing.
;# .. Useful for events or perhaps
;# .. even cutscenes?!
;# Inputs:
;# -none (reads value in player_direction)
;###########################
	ld a,(player_direction)
	or a
	 jr z,force_down
	dec a
	 jp z,force_left
	dec a
	 jp z,force_right
	jp force_up

;###########################
walk_down:
;###########################
	xor a
	ld (player_direction),a
	ld bc,$0100					; y offset = +1
	call get_player_map
	ld a,(hl)					; a = tile id
	call check_tile				; check if tile can be passed, events, etc.
	 ret nz						; if nz, then we can't move there
force_down:
	ld a,(player_y)				; check how far down the screen the player is
	ld hl,map_y					; .. once you reach a certain point, the screen scrolls
	sub (hl)					; .. instead of the player
	cp 4
	 jr nc,scroll_down
walk_down_player:
	ld b,8
walk_down_loop:
	push bc
		ld hl,player_y_offset
		inc (hl)
		call draw_map
		call draw_player
		call fast_copy
	pop bc
	djnz walk_down_loop
	ld hl,player_y_offset
	ld (hl),b
	ld hl,player_y
	inc (hl)
	ret
scroll_down:
	ld a,(map_height)			; check if map has reached the edge
	ld hl,map_y					; .. if so, continue moving the player
	sub (hl)					; .. instead of the map
	cp 8
	 jr z,walk_down_player
	ld hl,(map_width)			; we need to load the row below the map
	ld h,0
	add hl,hl					; .. so we need to multiply map_width by 8
	add hl,hl
	add hl,hl
	push hl
		call get_map_offset
	pop de
	add hl,de					; hl now points to the first tile beneath the screen
	ld b,12						; there are 12 columns of tiles
	ld de,scrollbuf				; where to load sprites to
sd_new_row:
	push bc						; save counter
		push hl					; save map location
			push de				; save scrollbuf location
				ld l,(hl)		; get tile id
				call get_tile	; hl = tile data
			pop de
			ld bc,8				; copy sprite data to scrollbuf
			ldir
		pop hl					; move to next byte in map
		inc hl
	pop bc						; repeat 8 times
	djnz sd_new_row

	ld b,8
	exx
		ld hl,scrollbuf			; fill in the bottom row of pixels
	exx
scroll_down_loop:
	push bc
		ld de,gbuf				; shift the gbuf up
		ld hl,gbuf+12			; 
		ld bc,756				; 756 bytes to shift (63 rows of 12 bytes each)
		ldir
		ld b,12					; copy 12 bytes from scrollbuf
		exx
			push hl				; save scrollbuf position
			ld de,8
		exx
sd_fill_row:
		exx
			ld a,(hl)			; load byte from scrollbuf
			add hl,de			; move to next sprite in scrollbuf
		exx
		ld (de),a
		inc de
		djnz sd_fill_row
		call draw_player
		call fast_copy
		call clear_player
		exx
			pop hl				; recall original scrollbuf position
			inc hl				; and move to next row of sprite data
		exx
	pop bc
	djnz scroll_down_loop
	ld hl,player_y
	inc (hl)
	ld hl,map_y
	inc (hl)
	ret

;###########################
walk_up:
;###########################
	ld a,PLAYER_UP
	ld (player_direction),a
	ld bc,$ff00					; y offset = -1
	call get_player_map			; b holds the offset to add to player's position
	ld a,(hl)					; a holds tile id
	call check_tile				; essentially a cpir of passable tiles
	 ret nz						; if nz, then we can't move there
force_up:
	ld a,(player_y)
	ld hl,map_y
	sub (hl)
	cp 4
	 jr c,scroll_up
walk_up_player:
	ld b,7
	ld hl,player_y
	dec (hl)
	ld hl,player_y_offset
	ld (hl),b
walk_up_loop:
	push bc
		ld hl,player_y_offset
		dec (hl)
		call draw_map
		call draw_player
		call fast_copy
	pop bc
	djnz walk_up_loop
	ret
scroll_up:
	ld a,(map_y)
	or a
	 jr z,walk_up_player
	call get_map_offset
	ld de,(map_width)			; we need to load the row above the map
	ld d,0
	sbc hl,de					; hl now points to the first tile above the screen
	ld b,12						; there are 12 columns of tiles
	ld de,scrollbuf				; where to load sprites to
su_new_row:
	push bc						; save counter
		push hl					; save map location
			push de				; save scrollbuf location
				ld l,(hl)		; get tile id
				call get_tile	; hl = tile data
			pop de
			ld bc,8				; copy sprite data to scrollbuf
			ldir
		pop hl					; move to next byte in map
		inc hl
	pop bc						; repeat 8 times
	djnz su_new_row

	ld b,8
	exx
		ld hl,scrollbuf+(8*12)-1	; fill in the bottom row of pixels
	exx
scroll_up_loop:
	push bc
		ld hl,gbuf+756-1		; 
		ld de,gbuf+768-1		; shift the gbuf down
		ld bc,756				; 756 bytes to shift (63 rows of 12 bytes each)
		lddr
		ld b,12					; copy 12 bytes from scrollbuf
		exx
			push hl				; save scrollbuf position
			ld de,-8
		exx
su_fill_row:
		exx
			ld a,(hl)			; load byte from scrollbuf
			add hl,de			; move to next sprite in scrollbuf
		exx
		ld (de),a
		dec de
		djnz su_fill_row
		call draw_player
		call fast_copy
		call clear_player
		exx
			pop hl				; recall original scrollbuf position
			dec hl				; and move to next row of sprite data
		exx
	pop bc
	djnz scroll_up_loop
	ld hl,player_y
	dec (hl)
	ld hl,map_y
	dec (hl)
	ret

;###########################
walk_left:
;###########################
	ld a,PLAYER_LEFT
	ld (player_direction),a
	ld bc,$00ff					; x offset = -1
	call get_player_map			; c holds the offset to add to player's x position
	ld a,(hl)					; a holds tile id
	call check_tile				; essentially a cpir of passable tiles
	 ret nz						; if nz, then we can't move there
force_left:
	ld a,(player_x)
	ld hl,map_x
	sub (hl)
	cp 6
	 jr c,scroll_left
walk_left_player:
	ld b,7
	ld hl,player_x
	dec (hl)
	ld hl,player_x_offset
	ld (hl),b
walk_left_loop:
	push bc
		ld hl,player_x_offset
		dec (hl)
		call draw_map
		call draw_player
		call fast_copy
	pop bc
	djnz walk_left_loop
	ret
scroll_left:
	ld a,(map_x)
	or a
	 jr z,walk_left_player
	call get_map_offset
	dec hl
	ld b,8						; there are 8 rows of tiles
	ld de,scrollbuf				; where to load sprites to
sl_new_column:
	push bc
		push hl
			push de
				ld l,(hl)		; get tile id
				call get_tile	; hl = tile data
			pop de
			ld bc,8
			ldir
		pop hl
		ld bc,(map_width)
		ld b,0
		add hl,bc
	pop bc
	djnz sl_new_column

	ld b,8
scroll_left_out:
	push bc
		ld b,64
		ld hl,gbuf
		ld de,scrollbuf
scroll_left_in:
		ex de,hl
			rr (hl)				; put new sprite data into the carry
			inc hl
		ex de,hl
		rr (hl) \ inc hl		; 1
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		rr (hl) \ inc hl
		djnz scroll_left_in	
		call draw_player
		call fast_copy
		call clear_player
	pop bc
	djnz scroll_left_out
	ld hl,player_x
	dec (hl)
	ld hl,map_x
	dec (hl)
	ret

;###########################
walk_right:
;###########################
	ld a,PLAYER_RIGHT
	ld (player_direction),a
	ld bc,$0001					; x offset = 1
	call get_player_map			; c holds the offset to add to player's x position
	ld a,(hl)					; a holds tile id
	call check_tile				; essentially a cpir of passable tiles
	 ret nz						; if nz, then we can't move there
force_right:
	ld a,(player_x)
	ld hl,map_x
	sub (hl)
	cp 6
	 jr nc,scroll_right
walk_right_player:
	ld b,7
walk_right_loop:
	push bc
		ld hl,player_x_offset
		inc (hl)
		call draw_map
		call draw_player
		call fast_copy
	pop bc
	djnz walk_right_loop
	ld hl,player_x_offset
	ld (hl),b
	ld hl,player_x
	inc (hl)
	ret
scroll_right:
	ld a,(map_width)			; check if map has reached the edge
	ld hl,map_x					; .. if so, continue moving the player
	sub (hl)					; .. instead of the map
	cp 12
	 jr z,walk_right_player
	call get_map_offset
	ld de,12					; we need to load the tile to the right of the screen
	add hl,de
	ld b,8						; there are 8 rows of tiles
	ld de,scrollbuf				; where to load sprites to
sr_new_column:
	push bc
		push hl
			push de
				ld l,(hl)		; get tile id
				call get_tile	; hl = tile data
			pop de
			ld bc,8
			ldir
		pop hl
		ld bc,(map_width)
		ld b,0
		add hl,bc
	pop bc
	djnz sr_new_column
	ld b,8
scroll_right_out:
	push bc
		ld b,64
		ld hl,gbuf+768-1
		ld de,scrollbuf+(8*8)-1
scroll_right_in:
		ex de,hl
			rl (hl)				; put new sprite data into the carry
			dec hl
		ex de,hl
		rl (hl) \ dec hl		; 1
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl
		rl (hl) \ dec hl		; 12
		djnz scroll_right_in
		call draw_player
		call fast_copy
		call clear_player
	pop bc
	djnz scroll_right_out
	ld hl,player_x
	inc (hl)
	ld hl,map_x
	inc (hl)
	ret
