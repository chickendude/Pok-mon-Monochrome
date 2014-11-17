; player values

player_map:	; idem
	.db 0

player_pokemons:
	.db 3,2,1,0,0,0
player_pokemons_length:
#define POKEMON_LIST_LENGTH	player_pokemons_length-player_pokemons

pokemon_stats:	; ID pokédex, lvl, PV, state (0=normal; 1=poison; 2=sleep; 3=para), (Attack ID, PP)*4, XP (2 bytes)
	.db 0
pokemon_lvl:
	.db 1
pokemon_hp:
	.db 4
pokemon_state:
	.db 1
pokemon_attacks:
	.db ATK_TACKLE,35,0,0,0,0,0,0
pokemon_xp:
	.dw 0
pokemon_stats_length:
	.db 1,26,40,0,11,30,12,15,13,10,0,0,0,0
	.db 2,10,20,0,ATK_TACKLE,35,ATK_GROWL,20,ATK_LEECH_SEED,35,ATK_VINE_WHIP,0,0,$ff
pokemon_stats_end:
#define STATS_LENGTH	pokemon_stats_length-pokemon_stats
