; Saferam and buffers
#define saferam1	$86ec	;savesscreen=768
#define saferam2	$8a3a	;statvars=531
#define saferam3	$8508	;textshadow=128
#define saferam4	$8478	;ops=66
#define saferam5	$84d3	;imathptrs=10
#define saferamp	$9872	;appbackupscreen=768
#define saferamp2	$8251	;boottemp=52
#define gbuf	$9340
#define rambuf	usermem	; we've inserted RAM here, see [settings.inc] to find out how much
#define scrollbuf	rambuf		; this is where we load the extra column/row when we scroll the screen
#define scrapspace	rambuf+500	; space that can be used for multiple purposes (volatile)
#define flipspritebuf	scrapspace	; where the sprites get flipped to

; Menu variables
#define menu_coordinates	scrapspace	; where menu coordinates are stored at, first byte holds number of menu items
										; .. followed by two bytes per item holding cursor's X and Y when item is selected
#define menu_cursor	scrapspace+17	; the currently selected menu item
#define cursor_wait	scrapspace+18
#define default_col	scrapspace+19	; default pencol value when reaching a newline
#define option_list	scrapspace+20	; [2 bytes]: pointer to menu's routine list
#define RAM_string	scrapspace+22	; we'll alot around 200 bytes for this
#define selected_pokemon	scrapspace+222	; which pokemon was selected in the pokemon menu
#define sub_menu_dim	scrapspace+223	; dimensions of the submenu
#define sub_menu_coord	scrapspace+225	; coordinates of the submenu
#define sub_menu_addr	scrapspace+227	; pointer to currently displayed submenu
#define sub_menu_left	scrapspace+229	; pointer to left submenu
#define sub_menu_right	scrapspace+231	; pointer to right submenu
#define sub_menu_flag	scrapspace+234	; 
number_string			= scrapspace+236	; where numbers are stored in decimal format 

; Map variables
#define map_addr	saferam3	;128 bytes
#define map_height	saferam3+2
#define map_width	saferam3+3
#define tile_addr	saferam3+4
#define map_y	saferam3+6
#define map_x	saferam3+7
#define map_y_offset	saferam3+8
#define player_tile	saferam3+9	; the tile that's behind the player (8 bytes)

; Player variables
#define player_direction	saferam3+20	; 0-3: DLRU
#define walk_count	saferam3+21	; how many pixels the player has gone (should go up to 8)
#define walk_anim	saferam3+22	; current animation frame (how many total? 4?)
#define player_y	saferam3+23	; aligned to map
#define player_x	saferam3+24
#define player_y_offset	saferam3+25	; tile offset in pixels
#define player_x_offset	saferam3+26

; Pokémon variables
#define party_number			rambuf+999	; how many pokémon are in the player's party
#define player_party			rambuf+1000	; [6 bytes]
#define current_pokemon			rambuf+1006	; currently [40+ bytes], i'll leave 50 bytes for now
#define current_pokemon_player	rambuf+1056	; current player's pokemon data
#define current_pokemon_enemy	rambuf+1106	; current enemy data
;						= 		rambuf+1110	;

; Misc variables
#define rand_data			saferam3+60	; used for Ion's random routine
#define contrast_var		saferam3+61	; holds the current contrast
#define _v_mode				saferam3+62	; text drawing mode
