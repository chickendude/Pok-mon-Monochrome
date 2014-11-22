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
#define _NAME	CP_NAME+1		;1 strings
#define _AT1	CP_ATK1STR+1	;3 (attack names)
#define _AT2	CP_ATK2STR+1	;5
#define _AT3	CP_ATK3STR+1	;7
#define _AT4	CP_ATK4STR+1	;9
#define _LVL	CP_LVL+1		;B numbers
#define _HP		CP_HP+1			;C
#define _HPTOT	CP_HPTOT+1		;D
#define _ATK	CP_ATK+1		;E
#define _DEF	CP_DEF+1		;F
#define _STATE	CP_STATE+1		;10
#define _PP1	CP_ATK1PP+1		;11 attack pp
#define _PP1MAX	CP_ATK1PPMAX+1	;12 attack max pp
#define _PP2	CP_ATK2PP+1		;13
#define _PP2MAX	CP_ATK2PPMAX+1	;14
#define _PP3	CP_ATK3PP+1		;15
#define _PP3MAX	CP_ATK3PPMAX+1	;16
#define _PP4	CP_ATK4PP+1		;17
#define _PP4MAX	CP_ATK4PPMAX+1	;18
#define _EXP	CP_EXP+1		;19

#ifdef FR
; il faudra sans doute que je rajoute les fichiers types.inc et pokemons.inc qui sont en partie en français !!!
	.echo "Compiling in french."
	#include "strings_fr.inc"
#else
#ifdef EN
	.echo "Compiling in english."
	#include "strings_en.inc"
#else
	.echo "Error: no language selected."
	.echo "Using default French files."
	#include "strings_fr.inc"
#endif
#endif
