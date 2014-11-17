#define TYPE_NORMAL	1
#define TYPE_FIGHTING	2
#define TYPE_FLYING	3
#define TYPE_POISON	4
#define TYPE_GROUND	5
#define TYPE_ROCK	6
#define TYPE_BUG	7
#define TYPE_GHOST	8
#define TYPE_GRASS	9
#define TYPE_FIRE	10
#define TYPE_WATER	11
#define TYPE_ELECTRIC	12
#define TYPE_PSYCHIC	13
#define TYPE_ICE	14
#define TYPE_DRAGON	15

type_index:
	.dw normal,fighting,flying,poison,ground,rock,bug,ghost,grass,fire,water,electric,psychic,ice,dragon

normal:
	.db 0	; types contre lesquels c'est super efficace (multiplie par deux l'attaque)
	.db 1,TYPE_ROCK	; types résistants contre lesquel ça n'est pas très efficace (divise par deux l'attaque)
	.db 1,TYPE_GHOST	; types contre lesquels l'attaque n'a aucun effet
	.db "Normal",0

fighting:
	.db 3,TYPE_NORMAL,TYPE_ROCK,TYPE_ICE
	.db 4,TYPE_FLYING,TYPE_POISON,TYPE_BUG,TYPE_PSYCHIC
	.db 1,TYPE_GHOST
	.db "Combat",0

flying:
	.db 3,TYPE_FIGHTING,TYPE_ROCK,TYPE_GRASS
	.db 2,TYPE_ROCK,TYPE_ELECTRIC
	.db 0
	.db "Vol",0

poison:
	.db 1,TYPE_GRASS
	.db 4,TYPE_POISON,TYPE_GROUND,TYPE_ROCK,TYPE_GHOST
	.db 0
	.db "Poison",0

ground:
	.db 4,TYPE_POISON,TYPE_ROCK,TYPE_FIRE,TYPE_ELECTRIC
	.db 3,TYPE_GROUND,TYPE_BUG,TYPE_GRASS
	.db 1,TYPE_FLYING
	.db "Sol",0

rock:
	.db 4,TYPE_FLYING,TYPE_BUG,TYPE_FIRE,TYPE_ICE
	.db 2,TYPE_FIGHTING,TYPE_GROUND
	.db 0
	.db "Roche",0

bug:
	.db 2,TYPE_GRASS,TYPE_PSYCHIC
	.db 5,TYPE_FIGHTING,TYPE_FLYING,TYPE_POISON,TYPE_GHOST,TYPE_ELECTRIC
	.db 0
	.db "Insecte",0

ghost:
	.db 2,TYPE_GHOST,TYPE_PSYCHIC
	.db 0
	.db 1,TYPE_NORMAL
	.db "Spectre",0

grass:
	.db 3,TYPE_GROUND,TYPE_ROCK,TYPE_WATER
	.db 6,TYPE_FLYING,TYPE_POISON,TYPE_BUG,TYPE_GRASS,TYPE_ELECTRIC,TYPE_DRAGON
	.db 0
	.db "Plante",0

fire:
	.db 3,TYPE_BUG,TYPE_GRASS,TYPE_ICE
	.db 4,TYPE_ROCK,TYPE_FIRE,TYPE_WATER,TYPE_DRAGON
	.db 0
	.db "Feu",0

water:
	.db 3,TYPE_GROUND,TYPE_ROCK,TYPE_FIRE
	.db 3,TYPE_GRASS,TYPE_WATER,TYPE_DRAGON
	.db 0
	.db "Eau",0

electric:
	.db 2,TYPE_FLYING,TYPE_WATER
	.db 3,TYPE_GRASS,TYPE_ELECTRIC,TYPE_DRAGON
	.db 1,TYPE_GROUND
	.db "Electrique",0

psychic:
	.db 2,TYPE_FIGHTING,TYPE_POISON
	.db 1,TYPE_PSYCHIC
	.db 0
	.db "Psy",0

ice:
	.db 4,TYPE_FLYING,TYPE_GROUND,TYPE_GRASS,TYPE_DRAGON
	.db 3,TYPE_FIRE,TYPE_WATER,TYPE_ICE
	.db 0
	.db "Glace",0

dragon:
	.db 1,TYPE_DRAGON
	.db 0
	.db 0
	.db "Dragon",0