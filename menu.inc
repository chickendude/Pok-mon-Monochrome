;LIST OF IMPORTANT ROUTINES :
;	draw_text	draw a normal text
;	draw_menu	draw a menu with routines
;	draw_menu_return	draw a menu without routines
;	draw_dialogue	draw a dialogue box (3 text rows)
;	draw_battle_dialogue = draw a smaller dialogue box (2 text rows)
;	setupSubMenu	load a submenu that displays informations according to the selected choice
;	setup_sub_menu_l_r	load a submenu that displays informations according to the selected choice with two parts (left and right)
;	menu_key		handle the cursor, jump to a routine automatically
;	menu_key_return	handle the cursor, return the choice number in 'a'

; Menus are set up as follows:
;menu_X:
;	.db NUM_CHOICES
;	.dw ACTION1
;	.dw ACTION2
;	.dw ACTION3
;	.db MN,"Text 1",NEWL
;	.db MN,"Text 2",NEWL
;	.db MN,"Text 3",0
; Menus don't have to be separated by a NEWL

;TODO : add in status names (psn, etc.)

menu_beginning:
	call fade_out
	bcall(_GrBufClr)

	ld bc,$240c			;c = width, b = height
	xor a				;a = x
	ld l,a				;l = y
	ld ix,title			;title sprite
	call largeSprite
	ld hl,$201d
	ld (penCol),hl
	ld hl,monochrome_str
	bcall(_VPutS)		;put "MONOCHROME" under the title sprite

	xor a				;default choice
	ld de,$2b1d			;e = penCol, d = penRow
	ld hl,menu_beginning_str
	call draw_menu		;draw the menu
	call fade_in
	call menu_key		;wait for a choice
exit:
	ret

;###########################
menu_start:
;# Draws the start menu on top of the map
;###########################
	call draw_map				; [engine.inc]
	call draw_player			; [engine.inc]
	ld bc,$2d25				; bc = $HHWW (in pixels)
	ld de,$3b00				; de = $XXYY
	call draw_frame			; [routines.inc]
	call release_key		; make sure no keys are being held before continuing
	xor a					; default option selected
	ld de,$0141				; coordinates $YYXX
	ld hl,menu_start_str	; the menu to display
	call draw_menu			; draw the menu
	call menu_key			; wait for a key, handles the cursor, returns if [Alpha] was pressed
	jp draw_map				; if we return here, we've exited the menu, so now go back to the map

setup_sub_menu_l_r:
	ld (sub_menu_left),hl
	ld (sub_menu_right),ix
	ld a,1
	ld (sub_menu_flag),a

setupSubMenu:
	ld (sub_menu_dim),bc
	ld (sub_menu_coord),de
	ld (sub_menu_addr),hl
	ld hl,sub_menu_flag
	inc (hl)
	ret

update_sub_menu:
sub_menu_dim = $+1
	ld bc,$0000			;b = height, c = width
sub_menu_coord = $+1
	ld de,$0000			;d = x, e = y
	call draw_frame
	ld a,d
	ld d,e
	ld e,a				;de = frame coordinates
sub_menu_addr = $+1
	ld hl,$0000
	ld a,(menu_cursor)
	ld b,a
	or a
	jp z,draw_menu_start
sub_menu_loop:
	ld a,(hl)
	inc hl
	or a
	jr nz,sub_menu_loop
	djnz sub_menu_loop
	jp draw_menu_start

check_sub_menu:
;vérifier si on a installé un submenu
sub_menu_flag = $+1
	ld b,0
	dec b
	ret m
	jr update_sub_menu

draw_battle_dialogue:
	ld bc,draw_battle_dialogue
	ld (dialogue_jump),bc
	ld bc,$0F60			;b = height, c = width
	ld de,$0031			;d = x, e = y
	push hl
		call draw_frame
		set textDelay,(iy+pokeFlags)	; turn on typewriter effect
	pop hl
	ld de,$3202
	jr draw_menu_start

draw_dialogue:
	ld bc,draw_dialogue
	ld (dialogue_jump),bc
	ld bc,$1560
	ld de,$002b
	push hl
		call draw_frame
		set textDelay,(iy+pokeFlags)	; turn on typewriter effect
	pop hl
	ld de,$2C02
	jr draw_menu_start


;###########################
draw_menu_return:
;# Draws a menu that doesn't need routines
;# Input:
;# - a = default menu item to select
;###########################
	ld (menu_cursor),a			; save default cursor position
	ld a,(hl)					; read number of menu items
	inc hl						; hl now points to start of text
	ld ix,menu_coordinates+1
	ld (ix-1),a					; number of menu options
	jr draw_text_fastcopy

;###########################
draw_menu:
;# Draws and sets up a menu that runs
;# .. routines after selecting a menu item
;# Input:
;# - a = default menu item to select
;###########################
	ld (menu_cursor),a			; the default item to select
	ld a,(hl)					; how many menu items there are
	inc hl						; start of routines
	ld (option_list),hl			; addresses of routines to go to after selecting an option
	ld ix,menu_coordinates+1	; skip the first byte which holds the number of options
	ld (ix-1),a					; number of options
	add a,a						; skip the routine addresses (2 bytes each)
	ld c,a						; .. and point hl to start of text data
	ld b,0						; 
	add hl,bc					; hl now points to menu text
;	jr draw_text_fastcopy
;###########################
draw_text_fastcopy:
;# Draws text and updates the LCD after
;# .. text has been drawn to gbuf
;###########################
	res textDelay,(iy+pokeFlags); turn off typewriter effect
	call draw_menu_start
	jp fastCopy					; update LCD after drawing menu

draw_text:
	set textDelay,(iy+pokeFlags); turn on typewriter effect
;at the end of the string we'll jump to draw_text_continue, this just skips the fastCopy
draw_menu_start:
	ld (penCol),de
	ld a,e
	ld (default_col),a
draw_string:
	ld de,(penCol)				; some of the special routines use penCol
	ld a,(hl)					; read the next character
	or a						; 0 = EOS
	 ret z						; quit if EOS
	cp NEWXY					; the last special routine, 
	 jr c,not_special			; .. if a < last special routine, it's not a special character
		ld bc,draw_string		; ** we will return to draw_menu_loop **
		push bc					; ** .. after running the special routine **
	 	push hl
			ld hl,text_routine_table	; table holding special text routines (newline, pause, change x/y, etc.)
			cpl					; since our routines start at $FF (-1) and go down, this inverts them
			add a,a				; .. so they start at 0 and go up
			ld c,a				; each entry in the table takes up 2 bytes
			ld b,0				; 
			add hl,bc			; find offset in text_routine_table
			ld c,(hl)			; load address into bc
			inc hl				; .. put it on the stack
			ld b,(hl)			; .. and ret to put it in the PC
		pop hl					; hl = adress in the string
		push bc					; bc = routine adress where we want to jump
		ret						; don't forget the "push bc" (draw_menu_loop)
								; .. we'll return there after the special routine finishes
not_special:
	cp _EXP+1					; if <= _EXP, we are inserting a stat
	 jr c,insert_stat
	push de
	push ix
		bcall(_VPutMap)			; draw letter in 'a', updates penRow/penCol
	pop ix
	pop de
	bit textDelay,(iy+pokeFlags); reset if no delay, set for typewriter effect
	 call nz,text_delay			; a short delay, also updates LCD
	inc hl						; next character in string
	jr draw_string

;a = stat à afficher
insert_stat:
	ld c,a
	ld b,0
	dec c
	cp _LVL
	push hl
	 jr c,print_pokemon_name
	ld hl,current_pokemon
	add hl,bc
	ld a,(hl)
	or a
	call nz,_vdispa
	jr insert_stat_end

print_pokemon_name:
	ld hl,current_pokemon
	add hl,bc
	call ld_hl_hl
	call draw_string
insert_stat_end:
	pop hl
	inc hl
	jr draw_string

;$00 = end of a dialogue or end of a menu option
;NEWX ($ff) = new X coordinate
;NEWL ($fe) = new line
;BRK ($fd) = pause
;PKMN ($fc) = load a pokémon to draw its stats
;MN ($fb) = new option
;ENEM ($fa) = load an opponent pokémon to draw its stats
;NEWXY ($f9) = new XY coordinates

text_routine_table:
	.dw text_new_x
	.dw text_new_line
	.dw text_pause
	.dw text_load_pokemon
	.dw text_add_menu
	.dw text_load_enemy
	.dw text_new_x_y

text_new_x_y:
	inc hl
	ld e,(hl)
	inc hl
	ld d,(hl)
	ld (penCol),de
	inc hl
	ret

text_add_menu:
	ld a,e				;1
	sub 4				;2
	ld (ix),a			;3 coord X
	inc d
	ld (ix+1),d			;3 coord Y
	dec d
	inc ix				;2
	inc ix				;2
	inc hl
	ret

text_new_x:
	inc hl				; the next byte holds the new x value
	ld e,(hl)
	ld (penCol),de		; update penCol
	inc hl				; ready to read next byte in string
	ret

text_new_line:
	ld a,d
	add a,6				; penRow+6
	ld de,(default_col)	; put the default column in e
	ld d,a				; and store the new row into d
	ld (penCol),de		; update penCol
	inc hl
;	ld a,(hl)
	ret

text_pause:
	pop bc			;clear stack (l'adresse de draw_menu_loop)
	push hl
	call fastCopy
	ld hl,cursor_wait
	ld (hl),50
	jr draw_cursor_wait

pause_text_loop:
	ei
	halt
	di
	ld a,$bf	;check 2nd
	call get_key
	bit 5,a
	jr z,load_next_text
	ld hl,cursor_wait
	dec (hl)
	jr nz,pause_text_loop
	ld (hl),50

draw_cursor_wait:
	ld a,86
	ld l,59
	ld b,3
	ld ix,scroll_cursor_sprite
	call putSprite
	call fastCopy
	jr pause_text_loop

load_next_text:
	set textDelay,(iy+pokeFlags)	; if we've pressed a key to advance quickly through text, turn typewriter effect back on
	call release_key
	pop hl
	inc hl							; skip the $FD (BRK)
dialogue_jump = $+1
	jp draw_dialogue

text_load_enemy:
	inc hl
	push hl
		ld de,opponent_pokemon_stats
		call text_load_pokemon_data
		ld hl,current_pokemon
		ld de,current_pokemon_enemy
		ld bc,CP_SPRITE+1
		ldir
	pop hl
	inc hl
	ret

text_load_pokemon:
	inc hl
	ld a,(hl)
	or a
	ret z
	push hl
		ld de,pokemon_stats
		call text_load_pokemon_data
		ld hl,current_pokemon		;copy current_pokemon to current_pokemon_player
		ld de,current_pokemon_player
		ld bc,CP_SPRITE+1
		ldir
	pop hl
	inc hl
	ret

text_load_pokemon_data:
	push ix
		ld l,(hl)			;party id
		dec l				;because the first pokemon id=1 not 0
		ld h,0
		ld b,STATS_LENGTH
		call slow_mult_hl_b
		add hl,de
		call load_pokemon_data
	pop ix
	ret

load_pokemon_data:			;mettre les données du pokémon dans current_pokemon
	push hl
		inc hl				;sauter l'id du pokémon (on va l'utiliser plus tard pour le nom du pokémon)
;copier les stats du pokémon
		ld de,current_pokemon+CP_LVL
		ld a,(hl)			;level
		ldi
		ldi					;lvl et hp actuels
		inc hl				;sauter pokemon type
;maintenant les attaques
		ex af,af'			;a = pokémon level
		ld b,4
		exx
			ld de,current_pokemon+CP_ATK1STR
		exx
		ld de,current_pokemon+CP_ATK1
load_attacks:
		ld a,(hl)			;attack type
		exx
			ld hl,null_text
			or a
			 jr z,store_attack
			call find_attack_data
			ld bc,5			;nombre d'octets avant le string
			add hl,bc
store_attack:
			ex de,hl
			ld (hl),e
			inc hl
			ld (hl),d
			inc hl
			ex de,hl
			inc hl
			inc hl
		exx
		ldi					;attack type
		ldi					;attack PP
		djnz load_attacks
;copier les stats precalculés du pokémon (hp total, attack, defense)
	pop hl
	push hl
		call get_pokemon_sprite_ix	;hl = pointeur à l'id du pokémon
		ld (current_pokemon+CP_SPRITE),hl
	pop hl
	ld a,(hl)
	call find_pokemon_data	;returns hl = pointer to start of pokémon data
	ex af,af'				;a = pokemon level
	push hl
		push af				;sauver niveau du pokémon
			inc hl
			inc hl			;first two bytes are the string name address
			push hl
				call calculate_hp
				ld (current_pokemon+CP_HPTOT),a	;HP totale
			pop hl
		pop af				;niveau
;load the other values (find the pokemon's attack, defense, max HP, etc.)
;			inc hl
;			inc de
;			ld b,1
;attack_defense_loop:
;			push hl
;			push de
;			push bc
;				call calculate_stats
;			pop bc
;			pop de
;			pop hl
;			djnz attack_defense_loop
;trouver le string du nom du pokémon
	pop hl
	call ld_hl_hl
	ld (current_pokemon),hl	;sauver l'adresse du string
	ret

text_delay:
	di
	exx
	ld a,$df	;check ALPHA to skip text typing
	call get_key
	bit 7,a
	 jr nz,$+6
		res textDelay,(iy+pokeFlags)	; turn typewriter effect off
	ld b,text_typing_speed
	push bc
		call nc,fastCopy
	pop bc
	djnz $-5
	exx
	ret

menu_select:
	call release_key
	scf					;set the carry flag so we can determine 2nd to alpha
	ret

;sortie : a = l'option choisie (menu_cursor), nc=alpha has been pushed, c=2nd
;###########################
menu_key_return:
;# Lets user pick a choice and
;# .. returns the item selected in a.
;# NOTE: Doesn't run any routines after
;# .. selecting an item, just returns
;# .. the value in a.
;###########################
	call menu_key_basic
	ld a,(menu_cursor)
	ret

;###########################
menu_key:
;# Waits for a key press then handles
;# .. the cursor. Exits if [Alpha] is
;# .. pressed. Jumps to the selected
;# .. item's corresponding routine if
;# .. [2nd] is pressed.
;###########################
	call menu_key_basic
	 ret nc				; nc means [Alpha] was pressed
	pop hl				; clear the stack (menu_key was called)
	ld a,(menu_cursor)
	add a,a
	ld c,a
	ld b,0
	ld hl,(option_list)
	add hl,bc
	ld a,(hl)
	inc hl
	ld h,(hl)
	ld l,a
	jp (hl)

menu_key_basic:
	call check_sub_menu
	call draw_cursor	;draw the cursor (XORed sprite)
menu_key_loop:
	ei
	halt
;	halt
	di
	ld a,$df			;check ALPHA
	call get_key
	rla
	 ret nc
	ld a,$bf			;check 2nd ($bf = key group #7 : Y=, WINDOW, ZOOM, TRACE, GRAPH, 2nd, MODE, DEL)
	call get_key
	cp 223				;2nd
	 jr z,menu_select
;*************************
	ld hl,menu_key_loop	;*
	push hl				;* where to jump
;*************************
	ld a,$fe			;check arrows
	call get_key
	or $f0				;erase bits 4-7
	ld b,a
	inc b				;if b+1 = 0, b = $FF then no arrows have been pushed
	ld hl,cursor_wait	;le compteur/delai
	 jr nz,$+4 			;sauter si une touche a été poussée
		ld (hl),b		;remettre le compteur à zéro
		ret
	dec (hl)			;compteur-1
	 ret p				;quitter si positif (>=0)
	ld (hl),cursor_speed
	push af
		call draw_cursor_no_screen_update	;erase the cursor (XORed sprite)
	pop af
;*****************************
	ld hl,draw_cursor		;*
	push hl					;* where to jump
	ld hl,check_sub_menu	;*
	push hl					;*
;*****************************
;which arrow ?
	ld hl,menu_cursor
	rra
	jr nc,cursor_down
	rra
	jr nc,cursor_left
	rra
	jr nc,cursor_right

cursor_up:
	ld a,(hl)
	or a
	ret z
	ld b,a					;actual menu_cursor
	call get_cursor_coords	;DE isn't destroyed
	ld a,(hl)				;X coordinate

find_next_up:
	dec b
	ret m
	dec hl
	dec hl
	cp (hl)
	jr z,found_up
	jr find_next_up

found_up:
	ld a,b
	ld (menu_cursor),a
	ret

cursor_down:
	ld a,(menu_coordinates)	;# de coordinées
	dec a
	cp (hl)
	ret z
	ld c,(hl)				;menu_cursor actuel
	sub c					;nombre d'options - cursor actuel
	ret z
	ld b,a					;nombre de coordonnées à chercher
	call get_cursor_coords	;ne modifie pas la valeur de DE
	ld a,(hl)				;coordonnée X

find_next_down:
	inc c
	inc hl
	inc hl
	cp (hl)
	jr z,found_down
	djnz find_next_down
	ret

found_down:
	ld a,c
	ld (menu_cursor),a
	ret

cursor_left:
	ld a,(sub_menu_flag)
	cp 2
	 jr nz,move_cursor_left
sub_menu_left = $+1
	ld hl,$0000
	ld (sub_menu_addr),hl
	ret

move_cursor_left:
	ld a,(hl)
	or a
	ret z
	dec (hl)
	ret

cursor_right:
	ld a,(sub_menu_flag)
	cp 2
	 jr nz,move_cursor_right
sub_menu_right = $+1		;if there is a special submenu, pressing right will load a second menu
	ld hl,$0000
	ld (sub_menu_addr),hl
	ret

move_cursor_right:
	ld a,(menu_coordinates)	;# de coordinées
	dec a
	cp (hl)
	ret z
	inc (hl)
	ret

draw_cursor_no_screen_update:	;to disable flickering
	call get_cursor_coords
	ld a,(hl)			;x
	inc hl
	ld l,(hl)			;y
	ld ix,cursor_sprite
	ld b,5
	jp putSprite

draw_cursor:
	call draw_cursor_no_screen_update
	jp fastCopy

get_cursor_coords:
	ld a,(menu_cursor)
	add a,a
	ld e,a
	ld d,0
	ld hl,menu_coordinates+1
	add hl,de
	ret

#define CP_NAME		0	; strings
#define CP_ATK1STR	2
#define CP_ATK2STR	4
#define CP_ATK3STR	6
#define CP_ATK4STR	8
#define CP_LVL		10	; numbers
#define CP_HP		11
#define CP_HPTOT	12
#define CP_ATK		13
#define CP_DEF		14
#define CP_STATE	15
#define CP_ATK1		16
#define CP_ATK1PP	17
#define CP_ATK2		18
#define CP_ATK2PP	19
#define CP_ATK3		20
#define CP_ATK3PP	21
#define CP_ATK4		22
#define CP_ATK4PP	23
#define CP_EXP		24
#define CP_SPRITE	25

;############### OLD ROUTINES

menu_pokemon:
	ld hl,menu_pokemon_list				; [strings_XX.inc]
	ld de,pokemon_menu					; buffer in RAM to hold and manipulate the string
	ld bc,POKEMON_MENU_SIZE				; copy the string into RAM
	ldir
	xor a								; set cursor to 0 (first menu item)
menu_pokemon_return:
	push af
		bcall(_GrBufClr)
		ld de,player_party				; holds current configuration of player's party, 6 bytes
		ld hl,pokemon_menu_id			; location of first pokémon's id in the string
		ld b,0							; counter
menu_pokemon_listing:
		ld a,(de)						; read pokemon's id in your party (1-6)
		or a
		 jr z,menu_pokemon_listing_end	; if it's a zero, then there are no more pokémon left in your party
		ld (hl),a						; copy pokémon's id into the string
		inc de							; move to next pokémon in the list
		push de
			ld de,POKEMON_LIST_STR_LENGTH
			add hl,de					; jump to next pokemon in string
		pop de
		inc b
		ld a,b
		cp MAX_PARTY
		 jr nz,menu_pokemon_listing
menu_pokemon_listing_end:
		ld a,b
		ld (pokemon_menu),a				; save number of pokémon in your party
		ld bc,$1560						; bc = $HHWW
		ld de,$002b						; de = $XXYY
		call draw_frame
	pop af								; default selected menu item
	ld de,$0005							; coordonnées
	ld hl,pokemon_menu					; the menu to draw (loaded in saferam)
	call draw_menu_return
	call menu_key_return				;pas d'actions, retourner ici
	 jp nc,menu_start					; [Alpha] (cancel) has been pushed
	ld (selected_pokemon),a
	ld bc,$151f							;bc = $HHWW
	ld de,$4117							;de = $XXYY
	call draw_frame
	xor a								;option par défaut
	ld de,$1847							;coordonnées
	ld hl,menu_pokemon_options			;le texte à afficher
	call draw_menu
	call menu_key
	jr menu_pokemon

menu_pokemon_order:
	call find_player_pokemon
	ld b,(hl)
	ld a,(de)
	ld (hl),a
	ld a,b
	ld (de),a	;swap the selected pokemon ID with the first
	jr menu_pokemon

menu_pokemon_stats:
	bcall(_GrBufClr)
	call find_player_pokemon
	call find_pokemon_stats
	call get_pokemon_sprite_ix
	ld bc,pokemon_sprite_size
	call flip_sprite
	ld a,4
	ld l,0
	call largeSprite
	ld ix,battle_bar
	ld bc,$1007
	ld a,39
	ld l,7
	call largeSprite
	ld bc,$2160				;b = height, c = width
	ld de,$001f				;d = x, e = y
	call draw_frame
	call fastCopy

pause_temporaire______________:
	ld a,$bf	;check 2nd
	call get_key
	bit 5,a
	 jr nz,pause_temporaire______________
	ld a,(selected_pokemon)	;set the cursor to the last selected pokemon
	jp menu_pokemon_return
