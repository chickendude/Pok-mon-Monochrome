; player values

player_map:	; idem
	.db 0

player_pokemons:		;** this has been changed to player_party, see [variables.inc]
	.db 1,2,3,0,0,0
player_pokemons_length:

pokemon_stats:	; ID pokédex, lvl, HP (2 bytes), state (0=normal; 1=poison; 2=sleep; 3=para), (Attack ID, PP, PPMAX)*4, XP (2 bytes)
	.db BULBASAUR		; pokédex ID
pokemon_lvl:
	.db 1
pokemon_hp:
	.dw 4
pokemon_state:
	.db 1
pokemon_attacks:
	.db ATK_TACKLE,35,35, 0,0,0, 0,0,0, 0,0,0
pokemon_xp:
	.dw 0
pokemon_stats_length:
	.db IVYSAUR,26, 40,0, 0, ATK_BITE,25,25, ATK_FURY_SWIPES,14,15, ATK_FURY_SWIPES,8,10, 0,0,0, 0,0
	.db VENUSAUR,10, 20,0, 0, ATK_TACKLE,35,35, ATK_GROWL,20,20, ATK_LEECH_SEED,30,35, ATK_VINE_WHIP,10,10, 0,0,$ff
pokemon_stats_end:
#define STATS_LENGTH	pokemon_stats_length-pokemon_stats
