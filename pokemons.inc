#define	BULBASAUR 	0	
#define	IVYSAUR 	1	
#define	VENUSAUR 	2	
#define	CHARMANDER 	3	
#define	CHARMELEON 	4	
#define	CHARIZARD 	5	
#define	SQUIRTLE 	6	
#define	WARTORTLE 	7	
#define	BLASTOISE 	8	
#define	CATERPIE 	9	
#define	METAPOD 	10	
#define	BUTTERFREE 	11	
#define	WEEDLE 		12	
#define	KAKUNA 		13	
#define	BEEDRILL 	14	
#define	PIDGEY 		15	
#define	PIDGEOTTO 	16	
#define	PIDGEOT 	17	
#define	RATTATA 	18	
#define	RATICATE 	19	
#define	SPEAROW 	20	
#define	FEAROW 		21	
#define	EKANS 		22	
#define	ARBOK 		23	
#define	PIKACHU 	24	
#define	RAICHU 		25	
#define	SANDSHREW 	26	
#define	SANDSLASH 	27	
#define	NIDORANF 	28	; note that it is nidoranf
#define	NIDORINA 	29	
#define	NIDOQUEEN 	30	
#define	NIDORANM 	31	; nidoranm
#define	NIDORINO 	32	
#define	NIDOKING 	33	
#define	CLEFAIRY 	34	
#define	CLEFABLE 	35	
#define	VULPIX 		36	
#define	NINETALES 	37	
#define	JIGGLYPUFF 	38	
#define	WIGGLYTUFF 	39	
#define	ZUBAT 		40	
#define	GOLBAT 		41	
#define	ODDISH 		42	
#define	GLOOM 		43	
#define	VILEPLUME 	44	
#define	PARAS 		45	
#define	PARASECT 	46	
#define	VENONAT 	47	
#define	VENOMOTH 	48	
#define	DIGLETT 	49	
#define	DUGTRIO 	50	
#define	MEOWTH 		51	
#define	PERSIAN 	52	
#define	PSYDUCK 	53	
#define	GOLDUCK 	54	
#define	MANKEY 		55	
#define	PRIMEAPE 	56	
#define	GROWLITHE 	57	
#define	ARCANINE 	58	
#define	POLIWAG 	59	
#define	POLIWHIRL 	60	
#define	POLIWRATH 	61	
#define	ABRA 		62	
#define	KADABRA 	63	
#define	ALAKAZAM 	64	
#define	MACHOP 		65	
#define	MACHOKE 	66	
#define	MACHAMP 	67	
#define	BELLSPROUT 	68	
#define	WEEPINBELL 	69	
#define	VICTREEBEL 	70	
#define	TENTACOOL 	71	
#define	TENTACRUEL 	72	
#define	GEODUDE 	73	
#define	GRAVELER 	74	
#define	GOLEM 		75	
#define	PONYTA 		76	
#define	RAPIDASH 	77	
#define	SLOWPOKE 	78	
#define	SLOWBRO 	79	
#define	MAGNEMITE 	80	
#define	MAGNETON 	81	
#define	FARFETCHD 	82	
#define	DODUO 		83	
#define	DODRIO 		84	
#define	SEEL 		85	
#define	DEWGONG 	86	
#define	GRIMER 		87	
#define	MUK 		88	
#define	SHELLDER 	89	
#define	CLOYSTER 	90	
#define	GASTLY 		91	
#define	HAUNTER 	92	
#define	GENGAR 		93	
#define	ONIX 		94	
#define	DROWZEE 	95	
#define	HYPNO 		96	
#define	KRABBY 		97	
#define	KINGLER 	98	
#define	VOLTORB 	99	
#define	ELECTRODE 	100	
#define	EXEGGCUTE 	101	
#define	EXEGGUTOR 	102	
#define	CUBONE 		103	
#define	MAROWAK 	104	
#define	HITMONLEE 	105	
#define	HITMONCHAN 	106	
#define	LICKITUNG 	107	
#define	KOFFING 	108	
#define	WEEZING 	109	
#define	RHYHORN 	110	
#define	RHYDON 		111	
#define	CHANSEY 	112	
#define	TANGELA 	113	
#define	KANGASKHAN 	114	
#define	HORSEA 		115	
#define	SEADRA 		116	
#define	GOLDEEN 	117	
#define	SEAKING 	118	
#define	STARYU 		119	
#define	STARMIE 	120	
#define	MR_MIME 	121	
#define	SCYTHER 	122	
#define	JYNX 		123	
#define	ELECTABUZZ 	124	
#define	MAGMAR 		125	
#define	PINSIR 		126	
#define	TAUROS 		127	
#define	MAGIKARP 	128	
#define	GYARADOS 	129	
#define	LAPRAS 		130	
#define	DITTO 		131	
#define	EEVEE 		132	
#define	VAPOREON 	133	
#define	JOLTEON 	134	
#define	FLAREON 	135	
#define	PORYGON 	136	
#define	OMANYTE 	137	
#define	OMASTAR 	138	
#define	KABUTO 		139	
#define	KABUTOPS 	140	
#define	AERODACTYL 	141	
#define	SNORLAX 	142	
#define	ARTICUNO 	143	
#define	ZAPDOS 		144	
#define	MOLTRES 	145
#define	DRATINI 	146
#define	DRAGONAIR 	147
#define	DRAGONITE 	148
#define	MEWTWO 		149
#define	MEW			150

;############### POKÉMON ATTACKS ###############
;level learned, attack id
bulbasaur_attacks:
	.db 11	;nombre d'attaques
	.db 1,ATK_TACKLE
	.db 1,ATK_GROWL
	.db 7,ATK_LEECH_SEED
	.db 13,ATK_VINE_WHIP
	.db 20,ATK_POISONPOWDER
	.db 27,ATK_RAZOR_LEAF
	.db 34,ATK_GROWTH
	.db 41,ATK_SLEEP_POWDER
	.db 48,ATK_SOLARBEAM
ivysaur_attacks:
	.db 11	;nombre d'attaques
	.db 1,ATK_TACKLE
	.db 1,ATK_GROWL
	.db 1,ATK_LEECH_SEED
	.db 7,ATK_LEECH_SEED
	.db 13,ATK_VINE_WHIP
	.db 22,ATK_POISONPOWDER
	.db 30,ATK_RAZOR_LEAF
	.db 38,ATK_GROWTH
	.db 46,ATK_SLEEP_POWDER
	.db 54,ATK_SOLARBEAM
venusaur_attacks:
	.db 11	;nombre d'attaques
	.db 1,ATK_VINE_WHIP
	.db 1,ATK_TACKLE
	.db 1,ATK_GROWL
	.db 1,ATK_LEECH_SEED
	.db 7,ATK_LEECH_SEED
	.db 13,ATK_VINE_WHIP
	.db 22,ATK_POISONPOWDER
	.db 30,ATK_RAZOR_LEAF
	.db 43,ATK_GROWTH
	.db 55,ATK_SLEEP_POWDER
	.db 65,ATK_SOLARBEAM
charmander_attacks:
	.db 8
	.db 1,ATK_SCRATCH
	.db 1,ATK_GROWL
	.db 9,ATK_EMBER
	.db 15,ATK_LEER
	.db 22,ATK_RAGE
	.db 30,ATK_SLASH
	.db 38,ATK_FLAMETHROWER
	.db 46,ATK_FIRE_SPIN
charmeleon_attacks:

charizard_attacks:

squirtle_attacks:
	.db 8	;nombre d'attaques
	.db 1,ATK_TACKLE
	.db 1,ATK_TAIL_WHIP
	.db 8,ATK_BUBBLE
	.db 15,ATK_WATER_GUN
	.db 22,ATK_BITE
	.db 28,ATK_WITHDRAW
	.db 35,ATK_SKULL_BASH
	.db 42,ATK_HYDRO_PUMP
wartortle_attacks:

blastoise_attacks:

caterpie_attacks:

metapod_attacks:

butterfree_attacks:

weedle_attacks:

kakuna_attacks:

beedrill_attacks:

pidgey_attacks:

pidgeotto_attacks:

pidgeot_attacks:

rattata_attacks:

raticate_attacks:

spearow_attacks:

fearow_attacks:

ekans_attacks:

arbok_attacks:

pikachu_attacks:

raichu_attacks:

sandshrew_attacks:

sandslash_attacks:

nidoranF_attacks:

nidorina_attacks:

nidoqueen_attacks:

nidoranM_attacks:

nidorino_attacks:

nidoking_attacks:

clefairy_attacks:
	.db 8
	.db ATK_POUND
	.db ATK_GROWL
	.db ATK_SING
	.db ATK_DOUBLESLAP
	.db ATK_MINIMIZE
	.db ATK_METRONOME
	.db ATK_DEFENSE_CURL
	.db ATK_LIGHT_SCREEN

#define POKE_NAME	0
#define POKE_HP		2
#define POKE_ATK	3
#define POKE_SP		4
#define POKE_SPD	5
#define POKE_DEF	6
#define POKE_EXP	7
#define POKE_TYPE1	8
#define POKE_TYPE2	9
#define POKE_EXPCURVE	10
#define POKE_ATK_LIST	11
#define POKE_EVOLVE	13


#define GSTATS_LENGTH ivysaur-bulbasaur

;base stats for each pokémon
pokemon_general_stats:
bulbasaur:
	.dw bulbasaur_txt
	.db 45			;HP
	.db 49			;Att
	.db 49			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 64			;Base EXP
	.db TYPE_GRASS	;Type 1
	.db TYPE_POISON	;Type 2
	.db 2			;EXP curve
	.dw bulbasaur_attacks
	.db 16			;niveau d'évolution
ivysaur:
	.dw ivysaur_txt
	.db 60			;HP
	.db 62			;Att
	.db 63			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 141			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 2			;EXP curve
	.dw ivysaur_attacks
	.db 32			;niveau d'évolution
venusaur:
	.dw venusaur_txt
	.db 80			;HP
	.db 82			;Att
	.db 83			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 208			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 2			;EXP curve
	.dw venusaur_attacks
	.db 0			;pas d'évolution
charmander:
	.dw charmander_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw charmander_attacks
	.db 0			;pas d'évolution
charmeleon:
	.dw charmeleon_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw charmeleon_attacks
	.db 0			;pas d'évolution
charizard:
	.dw charizard_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw charizard_attacks
	.db 0			;pas d'évolution
squirtle:
	.dw squirtle_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw squirtle_attacks
	.db 0			;pas d'évolution
wartortle:
	.dw wartortle_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw wartortle_attacks
	.db 0			;pas d'évolution
blastoise:
	.dw blastoise_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw blastoise_attacks
	.db 0			;pas d'évolution
caterpie:
	.dw caterpie_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw caterpie_attacks
	.db 0			;pas d'évolution
metapod:
	.dw metapod_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw metapod_attacks
	.db 0			;pas d'évolution
butterfree:
	.dw butterfree_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw butterfree_attacks
	.db 0			;pas d'évolution
weedle:
	.dw weedle_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw weedle_attacks
	.db 0			;pas d'évolution
kakuna:
	.dw kakuna_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw kakuna_attacks
	.db 0			;pas d'évolution
beedrill:
	.dw beedrill_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw beedrill_attacks
	.db 0			;pas d'évolution
pidgey:
	.dw pidgey_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw pidgey_attacks
	.db 0			;pas d'évolution
pidgeotto:
	.dw pidgeotto_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw pidgeotto_attacks
	.db 0			;pas d'évolution
pidgeot:
	.dw pidgeot_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw pidgeot_attacks
	.db 0			;pas d'évolution
rattata:
	.dw rattata_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw rattata_attacks
	.db 0			;pas d'évolution
raticate:
	.dw raticate_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw raticate_attacks
	.db 0			;pas d'évolution
spearow:
	.dw spearow_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw spearow_attacks
	.db 0			;pas d'évolution
fearow:
	.dw fearow_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw fearow_attacks
	.db 0			;pas d'évolution
ekans:
	.dw ekans_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw ekans_attacks
	.db 0			;pas d'évolution
arbok:
	.dw arbok_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw arbok_attacks
	.db 0			;pas d'évolution
pikachu:
	.dw pikachu_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw pikachu_attacks
	.db 0			;pas d'évolution
raichu:
	.dw raichu_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw raichu_attacks
	.db 0			;pas d'évolution
sandshrew:
	.dw sandshrew_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw sandshrew_attacks
	.db 0			;pas d'évolution
sandslash:
	.dw sandslash_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw sandslash_attacks
	.db 0			;pas d'évolution
nidoranF:
	.dw nidoranF_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw nidoranF_attacks
	.db 0			;pas d'évolution
nidorina:
	.dw nidorina_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw nidorina_attacks
	.db 0			;pas d'évolution
nidoqueen:
	.dw nidoqueen_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw nidoqueen_attacks
	.db 0			;pas d'évolution
nidoranM:
	.dw nidoranM_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw nidoranM_attacks
	.db 0			;pas d'évolution
nidorino:
	.dw nidorino_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw nidorino_attacks
	.db 0			;pas d'évolution
nidoking:
	.dw nidoking_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw nidoking_attacks
	.db 0			;pas d'évolution
clefairy:
	.dw clefairy_txt
	.db 1			;HP
	.db 1			;Att
	.db 1			;Def
	.db 1			;Special
	.db 1			;Speed
	.db 1			;Base EXP
	.db TYPE_GRASS
	.db TYPE_POISON
	.db 1			;EXP curve
	.dw clefairy_attacks
	.db 0			;pas d'évolution

pokemon_sprites:
#include "sprites/pokemons/bulbasaur.bmp"
#include "sprites/pokemons/ivysaur.bmp"
#include "sprites/pokemons/venusaur.bmp"
#include "sprites/pokemons/charmander.bmp"
#include "sprites/pokemons/charmeleon.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/charizard.bmp"
#include "sprites/pokemons/squirtle.bmp"
#include "sprites/pokemons/wartortle.bmp"
#include "sprites/pokemons/blastoise.bmp"
#include "sprites/pokemons/caterpie.bmp"
#include "sprites/pokemons/metapod.bmp"
#include "sprites/pokemons/butterfree.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/weedle.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/kakuna.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/beedrill.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/pidgey.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/pidgeotto.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/pidgeot.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/rattata.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/raticate.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/spearow.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/fearow.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/ekans.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/arbok.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/pikachu.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/raichu.bmp"
#include "sprites/pokemons/sandshrew.bmp"
#include "sprites/pokemons/sandslash.bmp"
#comment
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/nidoranf.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/nidorina.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/nidoqueen.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/nidoranm.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/nidorino.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/nidoking.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/clefairy.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/clefable.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/vulpix.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/ninetales.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/jigglypuff.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/wigglytuff.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/zubat.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/golbat.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/oddish.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/gloom.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/vileplume.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/paras.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/parasect.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/venonat.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/venomoth.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/diglett.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/dugtrio.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/meowth.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/persian.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/psyduck.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/golduck.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/mankey.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/primeape.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/growlithe.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/arcanine.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/poliwag.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/poliwhirl.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/poliwrath.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/abra.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/kadabra.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/alakazam.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/machop.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/machoke.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/machamp.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/bellsprout.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/weepinbell.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/victreebel.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/tentacool.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/tentacruel.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/geodude.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/graveler.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/golem.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/ponyta.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/rapidash.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/slowpoke.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/slowbro.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/magnemite.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/magneton.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/farfetch'd.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/doduo.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/dodrio.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/seel.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/dewgong.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/grimer.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/muk.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/shellder.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/cloyster.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/gastly.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/haunter.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/gengar.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/onix.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/drowzee.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/hypno.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/krabby.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/kingler.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/voltorb.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/electrode.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/exeggcute.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/exeggutor.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/cubone.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/marowak.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/hitmonlee.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/hitmonchan.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/lickitung.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/koffing.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/weezing.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/rhyhorn.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/rhydon.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/chansey.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/tangela.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/kangaskhan.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/horsea.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/seadra.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/goldeen.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/seaking.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/staryu.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/starmie.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/mr. mime.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/scyther.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/jynx.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/electabuzz.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/magmar.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/pinsir.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/tauros.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/magikarp.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/gyarados.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/lapras.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/ditto.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/eevee.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/vaporeon.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/jolteon.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/flareon.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/porygon.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/omanyte.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/omastar.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/kabuto.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/kabutops.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/aerodactyl.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/snorlax.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/articuno.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/zapdos.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/moltres.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/dratini.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/dragonair.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/dragonite.bmp"
#include "sprites/pokemons/nosprite.bmp" ;#include "sprites/pokemons/mewtwo.bmp"
#endcomment
