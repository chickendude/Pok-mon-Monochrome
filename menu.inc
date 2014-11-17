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

;TODO : add in status names (psn, etc.)

menu_beginning:
	call fade_out
	bcall(_grbufclr)

	ld bc,$240c			;c = width, b = height
	xor a				;a = x
	ld l,a				;l = y
	ld ix,title			;title sprite
	call largeSprite
	ld hl,$201d
	ld (pencol),hl
	ld hl,monochrome_str
	bcall(_vputs)		;put "MONOCHROME" under the title sprite

	xor a				;default choice
	ld de,$2b1d			;e = pencol, d = penrow
	ld hl,menu_beginning_str
	call draw_menu		;draw the menu
	call fade_in
	call menu_key		;wait for a choice

exit:
	ret

menu_start:
	call gbaRestoreMap
	ld hl,(player_direction)
	ld bc,(player_y)
	ld de,$0108
	call gbaClipSprite
	call gbaDrawMaskSprite
	ld bc,$2d25
	ld de,$3b00
	call draw_frame
	call release_key
	xor a					;option par défaut
	ld de,$0141				;les coordonnées
	ld hl,menu_start_str
	call draw_menu
	call menu_key
;si on retourne ici, on a annulé le menu
	jp draw_map

menu_pokemon:
	xor a

menu_pokemon_no_cursor_reset:
	push af
	bcall(_grbufclr)
	ld de,player_pokemons
	xor a

menu_pokemon_listing:
	ld b,a
	ld a,(de)
	or a
	jr z,menu_pokemon_listing_end
	ld a,b
	push af
	push de
	ld hl,POKEMON_LIST_STR_LENGTH
	ld b,a
	call slow_mult_hl_b
	ld de,menu_pokemon_list_first_id
	add hl,de
	pop de
	ld a,(de)
	ld (hl),a
	inc de
	pop af
	inc a
	cp POKEMON_LIST_LENGTH
	jr nz,menu_pokemon_listing
	ld b,a

menu_pokemon_listing_end:
	ld a,b
	ld (menu_pokemon_list),a
	ld bc,$1560				;b = height, c = width
	ld de,$002b				;d = x, e = y
	call draw_frame
	pop af					;option par défaut
	ld de,$0005				;coordonnées
	ld hl,menu_pokemon_list	;le texte à afficher
	call draw_menu_return
	call menu_key_return	;pas d'actions, retourner ici
	jr nc,menu_start		;Alpha (cancel) has been pushed
	ld (menu_pokemon_id),a
	ld bc,$151f				;b = height, c = width
	ld de,$4117				;d = x, e = y
	call draw_frame
	xor a					;option par défaut
	ld de,$1847				;coordonnées
	ld hl,menu_pokemon_options	;le texte à afficher
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
	bcall(_grbufclr)
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

	ld a,(menu_pokemon_id)	;set the cursor to the last selected pokemon
	jp menu_pokemon_no_cursor_reset

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
		ld hl,text_wait
		inc (hl)	;we want a non-zero value
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
		ld hl,text_wait
		inc (hl)	;we want a non-zero value
	pop hl
	ld de,$2C02
	jr draw_menu_start

draw_menu_return:	;reads the chosen option (menu_cursor)
	ld (menu_cursor),a
	ld a,(hl)
	inc hl
	ld ix,menu_coordinates+1
	ld (ix-1),a	;how many options
	jr draw_text_fastcopy

;menu, avec options
draw_menu:
	ld (menu_cursor),a
	ld a,(hl)
	inc hl
	ld (option_list),hl	;les adresses des routines où l'on peut aller après avoir choisi une option
	ld ix,menu_coordinates+1
	ld (ix-1),a			;combien d'options il y a
	add a,a
	ld c,a
	ld b,0
	add hl,bc
	jr draw_text_fastcopy

draw_text_continue:
	ld bc,fastCopy
	ld (no_fastcopy),bc
	ret

draw_text:
	ld bc,draw_text_continue
	ld (no_fastcopy),bc

draw_text_fastcopy:
	xor a
	ld (text_wait),a
;at the end of the string we'll jump to draw_text_continue, this just skips the fastCopy
draw_menu_start:
	ld (pencol),de
	ld a,e
	ld (default_col),a

draw_menu_loop:
	ld de,(pencol)
	ld a,(hl)
	or a
no_fastcopy = $+1
	jp z,fastCopy
	cp NEWXY
	jr c,not_special
		ld bc,draw_menu_loop
		push bc
	 	push hl
			ld hl,text_routine_table
			cpl
			add a,a
			ld c,a
			ld b,0
			add hl,bc
			ld c,(hl)
			inc hl
			ld b,(hl)
		pop hl			;hl = adress in the string
		push bc			;bc = routine adress where we want to jump
		ret				;n'oublie pas le "push bc" où bc = draw_menu_loop, on va y retourner après l'exécution de la routine

not_special:
	cp _EXP+1		;si <= _EXP, on veut afficher un stat
	jr c,insert_stat
	push de
	push ix
		bcall(_vputmap)
	pop ix
	pop de
	ld a,(text_wait)	;= 0 si pas de delai, != 0 s'il y en a
	or a
	call nz,text_delay
	inc hl
	jr draw_menu_loop

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
	bcall(_ldhlind)
	bcall(_vputs)

insert_stat_end:
	pop hl
	inc hl
	jr draw_menu_loop

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
	ld (pencol),de
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
	inc hl
	ld e,(hl)
	ld (pencol),de
	inc hl
	ret

text_new_line:
	ld a,d
	add a,6				;penRow+6
	ld d,a
default_col = $+1
	ld e,0
	ld (pencol),de
	inc hl
	ld a,(hl)
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
	ld hl,text_wait			;si on a poussé une touche pour faire avancer plus rapidement le texte
	inc (hl)				; il faut remettre le texte pour qu'il s'affiche à la vitesse normale
	in a,(1)
	inc a
	jr nz,load_next_text		;il faut relâcher la touche avant de continuer
	pop hl
	inc hl					;sauter le $FD (BRK)
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
	bcall(_ldhlind)
	ld (current_pokemon),hl	;sauver l'adresse du string
	ret

text_delay:
	di
	exx
	ld a,$df	;check ALPHA to skip text typing
	call get_key
	bit 7,a
	 jr nz,$+6
		xor a
		ld (text_wait),a
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

menu_select_smc:
	nop					;ou nop ou ret, selon on appelle menu_key ou menu_key_return
	pop hl				;nettoyer la pile (le call)
	ld a,(menu_cursor)
	add a,a
	ld c,a
	ld b,0
option_list = $+1
	ld hl,$0000
	add hl,bc
	ld a,(hl)
	inc hl
	ld h,(hl)
	ld l,a
	jp (hl)

;sortie : a = l'option choisie (menu_cursor), nc=alpha has been pushed, c=2nd
menu_key_return:
	ld a,$c9			;ret
	call menu_key+1
	ld a,(menu_cursor)
	ret
;sortie : sauter à la routine de l'option choisie
menu_key:
	xor a				;nop
	ld (menu_select_smc),a
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

cursor_wait:
	.db 0

text_wait:
	.db 0

menu_cursor:
	.db 0

menu_coordinates:
	.db 0					;nombre de choix
	.dw $0000
	.dw $0000
	.dw $0000
	.dw $0000
	.dw $0000
	.dw $0000
	.dw $0000

#define CP_NAME	0		;strings
#define CP_ATK1STR	2
#define CP_ATK2STR	4
#define CP_ATK3STR	6
#define CP_ATK4STR	8
#define CP_LVL	10	;numéros
#define CP_HP	11
#define CP_HPTOT	12
#define CP_ATK	13
#define CP_DEF	14
#define CP_STATE	15
#define CP_ATK1	16
#define CP_ATK1PP	17
#define CP_ATK2	18
#define CP_ATK2PP	19
#define CP_ATK3	20
#define CP_ATK3PP	21
#define CP_ATK4	22
#define CP_ATK4PP	23
#define CP_EXP	24
#define CP_SPRITE	25

current_pokemon:
	.dw 0	;pokemon name string address
	.fill 8,0	;(string de l'attaque)*4
	;put more strings here
	.db 0		;lvl
	.db 0		;hp
	.db 0		;total hp
	.db 0		;att
	.db 0		;def
	.db 0		;state
	.dw 0		;atk 1 id, pp
	.dw 0		;atk 2 id, pp
	.dw 0		;atk 3 id, pp
	.dw 0		;atk 4 id, pp
	.dw 0	;exp
	.dw 0	;sprite address

current_pokemon_player:
	.dw 0	;pokemon name string address
	.fill 8,0	;(string de l'attaque)*4
	;put more strings here
	.db 0		;lvl
	.db 0		;hp
	.db 0		;total hp
	.db 0		;att
	.db 0		;def
	.db 0		;state
	.dw 0		;atk 1 id, pp
	.dw 0		;atk 2 id, pp
	.dw 0		;atk 3 id, pp
	.dw 0		;atk 4 id, pp
	.dw 0	;exp
	.dw 0	;sprite address

current_pokemon_enemy:
	.dw 0	;pokemon name string address
	.fill 8,0	;(string de l'attaque)*4
	;put more strings here
	.db 0		;lvl
	.db 0		;hp
	.db 0		;total hp
	.db 0		;att
	.db 0		;def
	.db 0		;state
	.dw 0		;atk 1 id, pp
	.dw 0		;atk 2 id, pp
	.dw 0		;atk 3 id, pp
	.dw 0		;atk 4 id, pp
	.dw 0	;exp
	.dw 0	;sprite address
