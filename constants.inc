; Flags
#define pokeflags	asm_flag1
#define rectxor	0	; set = XOR, reset = OR (for drawing rectangles)
#define textdelay	1	; set = typewriter text (updates LCD), reset = no delay

; Pokémon base stat constants
#define POKE_NAME		0
#define POKE_HP			2
#define POKE_ATK		3
#define POKE_DEF		4
#define POKE_SPD		5
#define POKE_SP			6
#define POKE_TYPE1		7
#define POKE_TYPE2		8
#define POKE_CATCH		9
#define POKE_EXP		10
#define POKE_GROWTH		11
#define POKE_ATK_LIST	12
#define POKE_TM			14
#define POKE_EVOLVE		21

; Current Pokémon constants
CP_NAME			= 0		; strings
CP_ATK1STR		= 2
CP_ATK2STR		= 4
CP_ATK3STR		= 6
CP_ATK4STR		= 8
CP_TYPE1		= 10
CP_TYPE2		= 12
CP_LVL			= 14	; 8-bit numbers
CP_STATE		= 15
CP_ATK1			= 16
CP_ATK1PP		= 17
CP_ATK1PPMAX	= 18
CP_ATK2			= 19
CP_ATK2PP		= 20
CP_ATK2PPMAX	= 21
CP_ATK3			= 22
CP_ATK3PP		= 23
CP_ATK3PPMAX	= 24
CP_ATK4			= 25
CP_ATK4PP		= 26
CP_ATK4PPMAX	= 27
CP_HP			= 28	; 16-bit numbers
CP_HPTOT		= 30
CP_ATK			= 32
CP_DEF			= 34
CP_SPD			= 36
CP_SP			= 38
CP_EXPLVL		= 40	; experience to next level
CP_EXPTOT		= 42	; total experience
CP_SPRITE		= 45


; Text constants
#define POKEMON_MENU_SIZE	menu_pokemon_list_end - menu_pokemon_list	; [strings_XX.inc]
#define POKEMON_MENU_ID_OFFSET	menu_pokemon_list_first_id - menu_pokemon_list	; [strings_XX.inc]

;$00 = end of a dialogue or end of a menu option
;NEWX ($ff) = new X coordinate
;NEWL ($fe) = new line
;BRK ($fd) = pause
;PKMN ($fc) = load a pokémon to draw its stats
;MN ($fb) = new option
;ENEM ($fa) = load an opponent pokémon to draw its stats
;NEWXY ($f9) = new XY coordinates
#define NEWX	$ff
#define NEWL	$fe
#define BRK		$fd
#define PKMN	$fc
#define MN		$fb	;menu
#define ENEM	$fa	;same value as PKMN
#define NEWXY	$f9
;+1 because 0 = end of string
#define _NAME	CP_NAME+1		; strings
#define _AT1	CP_ATK1STR+1	; (attack names)
#define _AT2	CP_ATK2STR+1	;
#define _AT3	CP_ATK3STR+1	;
#define _AT4	CP_ATK4STR+1	;
#define _TYPE1	CP_TYPE1+1		; pokemon type strings
#define _TYPE2	CP_TYPE2+1		;
#define _LVL	CP_LVL+1		; 1 byte
#define _STATE	CP_STATE+1		;
#define _PP1	CP_ATK1PP+1		; attack pp
#define _PP1MAX	CP_ATK1PPMAX+1	; attack max pp
#define _PP2	CP_ATK2PP+1		;
#define _PP2MAX	CP_ATK2PPMAX+1	;
#define _PP3	CP_ATK3PP+1		;
#define _PP3MAX	CP_ATK3PPMAX+1	;
#define _PP4	CP_ATK4PP+1		;
#define _PP4MAX	CP_ATK4PPMAX+1	;
#define _HP		CP_HP+1			; 2 bytes
#define _HPTOT	CP_HPTOT+1		;
#define _ATK	CP_ATK+1		;
#define _DEF	CP_DEF+1		;
#define _SPD	CP_SPD+1		;
#define _SP		CP_SP+1			;
#define _EXPLVL	CP_EXPLVL+1		;
#define _EXPTOT	CP_EXPTOT+1		;

_2BYTE = _HP					; marker for 2-byte numbers

; Tiles/Maps constants
#define NUM_EVENTS	(event_tiles_end-event_tiles)/3
#define NUM_PASSABLE_TILES	passable_tiles_end-passable_tiles
#define TRAINER_TILE	56	; tile # after which there's only trainers-related tiles

; Game constants
#define SCREEN_WIDTH			96
#define SCREEN_HEIGHT			64
#define POKEMON_SPRITE_WIDTH	32
#define POKEMON_SPRITE_HEIGHT	26
#define POKEMON_SPRITE_SIZE		$1A04
#define INSERT_RAM				2000
#define POKEMON_SPRITE_BATTLE_DISTANCE_FROM_SCREEN	5
#define CURSOR_SPEED			20
#define SCROLL_CURSOR_SPEED		30
#define TEXT_TYPING_SPEED		6
#define WALK_SPEED				3
#define WALK_FREQUENCY			2
#define FADE_SPEED				2
#define POKEMON_ENCOUNTER_FREQUENCY	200
#define BATTLE_FLASH_SCREEN_FREQUENCY	4
#define BATTLE_BLINK_SPRITE_TIMES	4
#define BATTLE_BLINK_SPRITE_SPEED	10
#define BATTLE_EVOLUTION_BLINK_SPRITE_TIMES	26	; must be even
#define BATTLE_EVOLUTION_BLINK_SPRITE_SPEED	10
#define PLAYER_DOWN				0
#define PLAYER_LEFT				1
#define PLAYER_RIGHT			2
#define PLAYER_UP				3
#define MAX_PARTY				6				; maximum number of pokémon you can have in your party

; Misc constants
#define VMODE_DIRECT		0
#define VMODE_TYPE			1
#define VMODE_TYPE_NO_PAUSE	2

; Pokémon stat constants:
LVL_SLOW		= 0
LVL_MED_SLOW	= 1
LVL_MED_FAST	= 2
LVL_FAST		= 3
