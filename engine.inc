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
	ld (mapWidth),a
	inc hl
	ld a,(hl)
	ld (mapHeight),a
	inc hl
	ld (mapAddr),hl		; start of tilemap
	ld hl,tiles			;*** maybe later we will have multiple tilesets? ***
	ld (tileAddr),hl
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
	ld a,(mapWidth)		; we've drawn 12 rows, so we need to skip
	sub 12				;.. mapWidth-12 bytes to get to the next row in the map
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
	ld de,(mapWidth)	; 
	call mult_EH		; hl = mapY*mapWidth
	ld de,(mapAddr)		; de = map address
	add hl,de			; start of map + mapY*mapWidth
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
	ld bc,(tileAddr)
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
		ld hl,player_down	; player's sprite ***
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
	ld a,(player_x_off)
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
	ld hl,player_y_off
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
	ld hl,(mapWidth-1)		; mapWidth into h
	call mult_EH			; hl = player y * map width
	ld a,(player_x)			; 
	add a,c					; add x offset to player_x
	ld e,a
	ld d,0
	add hl,de
	ld de,(mapAddr)
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
	
#comment

;################### OLD ROUTINES ############################
check_event_block_tile:
	;ld hl,event_block_tiles	; pour le moment, pas nécessaire (après check_tile_loop hl pointe sur event_block_tiles)
	ld b,(event_block_tiles_end-event_block_tiles)/3
	jr check_event_tile_loop
check_event:					; a = tile #
	cp trainer_tile
	jp p,trainer_event
	ld hl,event_tiles
	ld b,(event_tiles_end-event_tiles)/3	;chaque évènement occupe trois octets
check_event_tile_loop:
	cp (hl)
	 jr nz,check_event_tile_skip	; la taille d'un bcall n'est pas la même sur 83 que sur 83+
	inc hl
	call ld_hl_hl
	jp (hl)
check_event_tile_skip:
	inc hl
	inc hl
	inc hl
	djnz check_event_tile_loop
	ret


walk_engine:	; hl:map addr
	push hl
	call fade_out
	bcall(_grbufclr)
	pop hl
	ld a,(hl)
	ld (mapWidth),a
	inc hl
	ld a,(hl)
	ld (mapHeight),a
	inc hl
	ld (mapAddr),hl
	ld hl,tiles
	ld (tileAddr),hl
	call gbaInitMap
	call draw_map
	call fade_in

walk_engine_loop:
	call draw_map
	ld a,$fe			;groupe 1
	out (1),a			;flèches directionnelles
	in a,(1)
	bit 0,a				;on pourrait aussi utiliser rra et vérifier nc (rra \ call nc,walk_down)
	push af
	call z,walk_down
	pop af
	bit 1,a
	push af
	call z,walk_left
	pop af
	bit 2,a
	push af
	call z,walk_right
	pop af
	bit 3,a
	call z,walk_up

	ld a,$bf			;groupe 7
	out (1),a			;[2nd][Mode][Del],[Y=]->[Graph]
	in a,(1)
	bit 4,a				;[Y=] ?
	call z,menu_start

	ld a,$fd			;groupe 2
	out (1),a			;[Enter]->[Clear]
	in a,(1)
	bit 6,a				;[Clear] ?
	 jr nz,walk_engine_loop
	ret

walk_down:
	ld hl,player_down   ; l'addresse du sprite du joueur à afficher
	ld (player_direction),hl
	ld bc,(player_y)	;c = player y, b = player x
	ld a,8				;vérifier qu'il n'y a rien dessous
	add a,c
	ld c,a
	call gbaCollision	;returns a = no. de tile
	call check_tile
	jp nz,draw_map		;nz = un tile praticable n'a pas été rencontré

walk_down_no_collision:
	ld hl,no_scroll
	ld (hl),0			;0 : déplacer la carte
	ld a,(player_y)
	cp 24
	jp p,walk_down2
	ld (hl),1			;!= 0 : il ne faut pas déplacer la carte

walk_down2:
	ld hl,gbaScrollDown
	ld (scroll_addr),hl	;la routine à exécuter
	ld hl,inc_walk_y	;l'adresse d'une routine
	ld (no_scroll_addr),hl
	jp walk_and_scroll

walk_left:
	ld hl,player_man_left
	ld (player_direction),hl
	ld a,(player_x)
	dec a
	ld bc,(player_y)
	ld b,a
	call gbaCollision
	call check_tile
	jp nz,draw_map

walk_left_no_collision:
	ld hl,no_scroll
	ld (hl),0
	ld a,(player_x)
	cp 56
	jp m,walk_left2
	ld (hl),1

walk_left2:
	ld hl,gbaScrollLeft
	ld (scroll_addr),hl
	ld hl,dec_walk_x
	ld (no_scroll_addr),hl
	jr walk_and_scroll

walk_right:
	ld hl,player_man_right
	ld (player_direction),hl
	ld a,(player_x)
	add a,8
	ld bc,(player_y)
	ld b,a
	call gbaCollision
	call check_tile
	jp nz,draw_map

walk_right_no_collision:
	ld hl,no_scroll
	ld (hl),0
	ld a,(player_x)
	cp 40
	jp p,walk_right2
	ld (hl),1

walk_right2:
	ld hl,gbaScrollRight
	ld (scroll_addr),hl
	ld hl,inc_walk_x
	ld (no_scroll_addr),hl
	jr walk_and_scroll

walk_up:
	ld hl,player_man_up
	ld (player_direction),hl
	ld a,(player_y)
	dec a
	ld bc,(player_y)
	ld c,a
	call gbaCollision
	call check_tile
	jr nz,draw_map
	ld hl,no_scroll
	ld (hl),0
	ld a,(player_y)
	cp 40
	jp m,walk_up2
	ld (hl),1

walk_up2:
	ld hl,gbaScrollUp
	ld (scroll_addr),hl
	ld hl,dec_walk_y
	ld (no_scroll_addr),hl

walk_and_scroll:
	ld b,8

walk_and_scroll_loop:
	push bc

	ld b,walk_speed
	call wait			;slow down player's walking speed

	call inc_walk_count
no_scroll = $+1
	ld a,0				;spécifié dans les routines de mouvement
	or a				;=0 pour scroller la carte, !=0 pour ne pas scroller
	jr nz,walk_and_scroll_skip
scroll_addr = $+1
	ld hl,0				;l'adresse de la routine pour scroller la carte
	call jp_hl
	jr nc,walk_and_scroll_loop_2	;c = routine n'a pas pu scroller la carte

walk_and_scroll_skip:
no_scroll_addr = $+1
	ld hl,0
	call jp_hl

walk_and_scroll_loop_2:
	call draw_map
	pop bc
	djnz walk_and_scroll_loop	;scroller 8 fois
	xor a
	ld (walk_anim),a
	call draw_map
	ld bc,(player_y)
	call gbaCollision
	jr check_event

inc_walk_y:
	ld hl,player_y
	inc (hl)
	ret

dec_walk_x:
	ld hl,player_x
	dec (hl)
	ret

inc_walk_x:
	ld hl,player_x
	inc (hl)
	ret

dec_walk_y:
	ld hl,player_y
	dec (hl)
	ret

draw_map:
	call gbaRestoreMap
	ld hl,(player_direction)
	ld h,0
	ld a,(walk_anim)
	add a,a
	add a,a
	add a,a				;a*8	\
	add a,a				;a*2	/ *16 pour sauter le sprite et son masque
	ld d,b				;b est à 0 après gbaRestoreMap
	ld e,a
	add hl,de
	ld bc,(player_y)
	ld de,$0108
	call gbaClipSprite
	call gbaDrawMaskSprite
	jp fastCopy

inc_walk_count:
	ld hl,walk_count	;check if we've reached a new tile yet or not
	inc (hl)
	ld a,(hl)
	sub walk_frequency
	 ret nz
	ld (hl),a			;reset walk_count if we've reached a new tile
	ld hl,walk_anim		;switch to the next animation frame after reaching a new tile
	inc (hl)
	ld a,(hl)
	sub 3
	 ret nz				;*******************??????************************
	ld (hl),a
	ret
#endcomment
