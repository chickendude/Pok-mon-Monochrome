;attaques des pokémons
;level, id de l'attaque
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
#define POKE_DEF	4
#define POKE_EXP	5
#define POKE_TYPE1	6
#define POKE_TYPE2	7
#define POKE_EXPCURVE	8
#define POKE_ATK_LIST	9

#define GSTATS_LENGTH ivysaur-bulbasaur

pokemon_general_stats:
bulbasaur:
	.dw bulbasaur_txt
	.db 45	;HP
	.db 49	;Att
	.db 49	;Def
	;Sp. Atk
	;Sp. Def
	;Speed
	.db 64	;Base EXP
	.db TYPE_GRASS	;Type 1
	.db TYPE_POISON	;Type 2
	.db 2	;EXP curve
	.dw bulbasaur_attacks
	.db 16	;niveau d'évolution
ivysaur:
	.dw ivysaur_txt
	.db 60			;HP
	.db 62			;Att
	.db 63			;Def
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
	;Sp. Atk
	;Sp. Def
	;Speed
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
#comment
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
