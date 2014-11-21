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
#define _NAME	CP_NAME+1		;strings
#define _AT1	CP_ATK1STR+1	;(attack names)
#define _AT2	CP_ATK2STR+1
#define _AT3	CP_ATK3STR+1
#define _AT4	CP_ATK4STR+1
#define _LVL	CP_LVL+1		;numbers
#define _HP		CP_HP+1
#define _HPTOT	CP_HPTOT+1
#define _ATK	CP_ATK+1
#define _DEF	CP_DEF+1
#define _STATE	CP_STATE+1
#define _PP1	CP_ATK1PP+1		;attack pp
#define _PP2	CP_ATK2PP+1
#define _PP3	CP_ATK3PP+1
#define _PP4	CP_ATK4PP+1
#define _EXP	CP_EXP+1

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
