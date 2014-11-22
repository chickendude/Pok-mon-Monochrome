PLAYER_DOWN		= 0
PLAYER_LEFT		= 1
PLAYER_RIGHT	= 2
PLAYER_UP		= 3

; Flags
pokeFlags = asm_Flag1
rectXOR			= 0		; set = XOR, reset = OR (for drawing rectangles)
textDelay		= 1		; set = typewriter text (updates LCD), reset = no delay

; Saferam and buffers
saferam1		= $86EC	; saveSScreen=768
saferam2		= $8A3A	; statVars=531
saferam3		= $8508	; textShadow=128
saferam4		= $8478	; OPs=66
saferam5		= $84D3	; iMathPtrs=10
saferamp		= $9872	; appBackUpScreen=768
saferamp2		= $8251	; bootTemp=52
gbuf			= $9340
ramBuf			= $9D95	; we've inserted RAM here, see [settings.inc] to find out how much
scrollBuf		= ramBuf		; this is where we load the extra column/row when we scroll the screen
scrapSpace		= ramBuf+500	; space that can be used for multiple purposes (volatile)
flipSpriteBuf	= scrapSpace	; where the sprites get flipped to

; Menu variables
menu_coordinates = scrapSpace	; where menu coordinates are stored at, first byte holds number of menu items
								; .. followed by two bytes per item holding cursor's X and Y when item is selected
menu_cursor		= scrapSpace+17	; the currently selected menu item
cursor_wait		= scrapSpace+18
default_col		= scrapSpace+19	; default penCol value when reaching a newline
option_list		= scrapSpace+20	; [2 bytes]: pointer to menu's routine list
RAM_string		= scrapSpace+22	; we'll alot around 200 bytes for this
selected_pokemon= scrapSpace+222	; which pokemon was selected in the pokemon menu
sub_menu_dim	= scrapSpace+223	; dimensions of the submenu
sub_menu_coord	= scrapSpace+225	; coordinates of the submenu
sub_menu_addr	= scrapSpace+227	; pointer to currently displayed submenu
sub_menu_left	= scrapSpace+229	; pointer to left submenu
sub_menu_right	= scrapSpace+231	; pointer to right submenu
sub_menu_flag	= scrapSpace+234	; 

; Map variables
mapAddr		= saferam3				;128 bytes
mapHeight	= saferam3+2
mapWidth	= saferam3+3
tileAddr	= saferam3+4
map_y		= saferam3+6
map_x		= saferam3+7
offsetY		= saferam3+8
player_tile	= saferam3+9			; the tile that's behind the player (8 bytes)

; Player variables
player_direction	= saferam3+20	; 0-3: DLRU
walk_count			= saferam3+21	; how many pixels the player has gone (should go up to 8)
walk_anim			= saferam3+22	; current animation frame (how many total? 4?)
player_y			= saferam3+23	; aligned to map
player_x			= saferam3+24
player_y_off		= saferam3+25	; tile offset in pixels
player_x_off		= saferam3+26

; Pokémon variables
player_party	= ramBuf+1000			; [6 bytes]
current_pokemon	= ramBuf+1006			; currently [28 bytes], i'll leave 30 bytes for now
;	.dw 0	;pokemon name string address
;	.fill 8,0	;(attack string)*4
;	;put more strings here
;	.db 0		;lvl
;	.db 0		;hp
;	.db 0		;total hp
;	.db 0		;att
;	.db 0		;def
;	.db 0		;state
;	.dw 0		;atk 1 id, pp
;	.dw 0		;atk 2 id, pp
;	.dw 0		;atk 3 id, pp
;	.dw 0		;atk 4 id, pp
;	.dw 0		;exp
;	.dw 0		;sprite address
current_pokemon_player	= ramBuf+1036	; current player's pokemon data
current_pokemon_enemy	= ramBuf+1066	; current enemy data
;						= ramBuf+1096	;

; Misc variables
randData			= saferam3+60	; used for Ion's random routine
contrast_var		= saferam3+61	; holds the current contrast
_v_mode				= saferam3+62	; text drawing mode
