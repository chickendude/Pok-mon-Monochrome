; Settings for a new game
#define NEW_GAME_X	8			; player's starting X
#define NEW_GAME_Y	8			; player's starting Y
#define new_game_offset_x	0	; starting map X
#define new_game_offset_y	0	; starting map Y
#define NEW_GAME_MAP	map_test	; the first map to load
#define NEW_GAME_DIRECTION	player_down	;

; Tiles/Maps
#define NUM_EVENTS (event_tiles_end-event_tiles)/3
#define NUM_PASSABLE_TILES passable_tiles_end-passable_tiles

; Party settings
MAX_PARTY	= 6					; maximum number of pokémon you can have in your party

; Text constants
POKEMON_MENU_SIZE		= menu_pokemon_list_end - menu_pokemon_list			; [strings_XX.inc]
POKEMON_MENU_ID_OFFSET	= menu_pokemon_list_first_id - menu_pokemon_list	; [strings_XX.inc]

; Menu defines
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


#define vmode_direct	0
#define vmode_type	1
#define vmode_type_no_pause	2
#define screen_width	96
#define screen_height	64
#define pokemon_sprite_width	32
#define pokemon_sprite_height	26
#define pokemon_sprite_size	$1a04
#define pokemon_sprite_battle_distance_from_screen	5
#define CURSOR_SPEED	20
#define scroll_cursor_speed	30
#define text_typing_speed	6
#define walk_speed	3
#define walk_frequency	2
#define fade_speed	2
#define pokemon_encounter_frequency	200
#define battle_flash_screen_frequency	4
#define battle_blink_sprite_times	4
#define battle_blink_sprite_speed	10
#define battle_evolution_blink_sprite_times	26	; must be even
#define battle_evolution_blink_sprite_speed	10
#define trainer_tile	56	; tile # after which there's only trainers-related tiles

INSERT_RAM = 2000
