new_game:
	call fade_out
	bcall(_grbufclr)
	call fastCopy
	call fade_in

	ld hl,gender_str
	call draw_dialogue

	ld bc,$1a03			;c = width, b = height
	push bc
	ld a,14				;a = x
	ld l,10				;l = y
	ld ix,opponent_man	;man sprite
	call largeSprite
	pop bc
	ld a,58
	ld l,10
	ld ix,opponent_woman
	call largeSprite
	xor a
	ld (menu_cursor),a	;default=left (man)
	call draw_new_game_genre_select_cursor

new_game_genre_select:
	ld a,$fe	;check arrows
	call get_key
	bit 1,a
	push af
	call z,new_game_genre_select_left
	pop af
	bit 2,a
	call z,new_game_genre_select_right

	ld a,$bf	;check 2nd
	call get_key
	bit 5,a
	jr nz,new_game_genre_select

	call fade_out
	bcall(_grbufclr)
	ld ix,opponent_woman
	ld a,(menu_cursor)
	ld (player_gender),a	; 0 = man, 1 = woman
;	ld hl,player_woman_up
;	ld (player_up),hl
;	ld hl,player_woman_left
;	ld (player_left),hl
;	ld hl,player_woman_right
;	ld (player_right),hl
	or a
	jr nz,new_game_valid_skip_man
	ld ix,opponent_man
;	ld hl,player_man_up
;	ld (player_up),hl
;	ld hl,player_man_left
;	ld (player_left),hl
;	ld hl,player_man_right
;	ld (player_right),hl

new_game_valid_skip_man:
	ld bc,$1a03
	ld a,36				;a = x
	ld l,10				;l = y
	call largeSprite
	call fastCopy
	call fade_in

	ld hl,new_game_str
	call draw_dialogue

;initialize variables
	ld a,new_game_y
	ld (player_y),a
	ld a,new_game_x
	ld (player_x),a
	ld a,new_game_offset_x
	ld (screenOffsetX),a
	ld a,new_game_offset_y
	ld (screenOffsetY),a
	ld hl,new_game_direction
	ld (player_direction),hl
	ld hl,new_game_map
	jr walk_engine

draw_new_game_genre_select_cursor_no_screen_update:	;to avoid flickering !
	ld a,(menu_cursor)
	or a
	ld a,64	;a = x
	call z,draw_new_game_genre_select_cursor_left
	ld l,6	;l = y
	ld b,3
	ld ix,scroll_cursor_sprite
	jp putSprite

draw_new_game_genre_select_cursor:
	call draw_new_game_genre_select_cursor_no_screen_update
	jp fastCopy

draw_new_game_genre_select_cursor_left:
	ld a,20 ;a = x
	ret

new_game_genre_select_left:
	ld a,(menu_cursor)
	or a
	ret z
	call draw_new_game_genre_select_cursor_no_screen_update	;erase cursor
	xor a
	ld (menu_cursor),a
	jr draw_new_game_genre_select_cursor

new_game_genre_select_right:
	ld a,(menu_cursor)
	or a
	ret nz
	call draw_new_game_genre_select_cursor_no_screen_update	;erase cursor
	ld a,1
	ld (menu_cursor),a
	jr draw_new_game_genre_select_cursor
