;Pokémons names
bulbasaur_txt:
	.db "Bulbasaur",0
ivysaur_txt:
	.db "Ivysaur",0
venusaur_txt:
	.db "Venusaur",0
charmander_txt:
	.db "Charmander",0
charmeleon_txt:
	.db "Charmeleon",0
charizard_txt:
	.db "Charizard",0
squirtle_txt:
	.db "Squirtle",0
wartortle_txt:
	.db "Wartortle",0
blastoise_txt:
	.db "Blastoise",0
caterpie_txt:
	.db "Caterpie",0
metapod_txt:
	.db "Metapod",0
butterfree_txt:
	.db "Butterfree",0
weedle_txt:
	.db "Weedle",0
kakuna_txt:
	.db "Kakuna",0
beedrill_txt:
	.db "Beedrill",0
pidgey_txt:
	.db "Pidgey",0
pidgeotto_txt:
	.db "Pidgeotto",0
pidgeot_txt:
	.db "Pidgeot",0
rattata_txt:
	.db "Rattata",0
raticate_txt:
	.db "Raticate",0
spearow_txt:
	.db "Spearow",0
fearow_txt:
	.db "Fearow",0
ekans_txt:
	.db "Ekans",0
arbok_txt:
	.db "Arbok",0
pikachu_txt:
	.db "Pikachu",0
raichu_txt:
	.db "Raichu",0
sandshrew_txt:
	.db "Sandshrew",0
sandslash_txt:
	.db "Sandslash",0
nidoranF_txt:
	.db "NidoranF",0
nidorina_txt:
	.db "Nidorina",0
nidoqueen_txt:
	.db "Nidoqueen",0
nidoranM_txt:
	.db "Nidoran♂",0
nidorino_txt:
	.db "Nidorino",0
nidoking_txt:
	.db "Nidoking",0
clefairy_txt:
	.db "Clefairy",0
	.db "Clefable",0
	.db "Vulpix",0
	.db "Ninetales",0
	.db "Jigglypuff",0
	.db "Wigglytuff",0
	.db "Zubat",0
	.db "Golbat",0
	.db "Oddish",0
	.db "Gloom",0
	.db "Vileplume",0
	.db "Paras",0
	.db "Parasect",0
	.db "Venonat",0
	.db "Venomoth",0
	.db "Diglett",0
	.db "Dugtrio",0
	.db "Meowth",0
	.db "Persian",0
	.db "Psyduck",0
	.db "Golduck",0
	.db "Mankey",0
	.db "Primeape",0
	.db "Growlithe",0
	.db "Arcanine",0
	.db "Poliwag",0
	.db "Poliwhirl",0
	.db "Poliwrath",0
	.db "Abra",0
	.db "Kadabra",0
	.db "Alakazam",0
	.db "Machop",0
	.db "Machoke",0
	.db "Machamp",0
	.db "Bellsprout",0
	.db "Weepinbell",0
	.db "Victreebel",0
	.db "Tentacool",0
	.db "Tentacruel",0
	.db "Geodude",0
	.db "Graveler",0
	.db "Golem",0
	.db "Ponyta",0
	.db "Rapidash",0
	.db "Slowpoke",0
	.db "Slowbro",0
	.db "Magnemite",0
	.db "Magneton",0
	.db "Farfetch'd",0
	.db "Doduo",0
	.db "Dodrio",0
	.db "Seel",0
	.db "Dewgong",0
	.db "Grimer",0
	.db "Muk",0
	.db "Shellder",0
	.db "Cloyster",0
	.db "Gastly",0
	.db "Haunter",0
	.db "Gengar",0
	.db "Onix",0
	.db "Drowzee",0
	.db "Hypno",0
	.db "Krabby",0
	.db "Kingler",0
	.db "Voltorb",0
	.db "Electrode",0
	.db "Exeggcute",0
	.db "Exeggutor",0
	.db "Cubone",0
	.db "Marowak",0
	.db "Hitmonlee",0
	.db "Hitmonchan",0
	.db "Lickitung",0
	.db "Koffing",0
	.db "Weezing",0
	.db "Rhyhorn",0
	.db "Rhydon",0
	.db "Chansey",0
	.db "Tangela",0
	.db "Kangaskhan",0
	.db "Horsea",0
	.db "Seadra",0
	.db "Goldeen",0
	.db "Seaking",0
	.db "Staryu",0
	.db "Starmie",0
	.db "Mr. Mime",0
	.db "Scyther",0
	.db "Jynx",0
	.db "Electabuzz",0
	.db "Magmar",0
	.db "Pinsir",0
	.db "Tauros",0
	.db "Magikarp",0
	.db "Gyarados",0
	.db "Lapras",0
	.db "Ditto",0
	.db "Eevee",0
	.db "Vaporeon",0
	.db "Jolteon",0
	.db "Flareon",0
	.db "Porygon",0
	.db "Omanyte",0
	.db "Omastar",0
	.db "Kabuto",0
	.db "Kabutops",0
	.db "Aerodactyl",0
	.db "Snorlax",0
	.db "Articuno",0
	.db "Zapdos",0
	.db "Moltres",0
	.db "Dratini",0
	.db "Dragonair",0
	.db "Dragonite",0
	.db "Mewtwo",0

monochrome_str:
	.db "MONOCHROME",0

menu_beginning_str:
	.db 3			;number of choices
	.dw new_game	;action 1
	.dw new_game	;action 2
	.dw exit		;action 3
	.db MN,"Continue",NEWL
	.db MN,"New game",NEWL
	.db MN,"Quit",0

gender_str:
	.db "Are you a boy or a girl ?",0
null_text = $-1

new_game_str:
	.db "Ta qu",$98,"te des POK",$96,"MON est sur",NEWL
	.db "le point de commencer.",BRK
	.db "Un tout nouveau monde de",NEWL
	.db "r",$98,"ve, d'aventures et de",NEWL
	.db "POK",$96,"MON t'attend ! Dingue !",BRK,0

menu_start_str:
	.db 7
	.dw menu_pokemon
	.dw menu_pokemon
	.dw menu_pokemon
	.dw menu_pokemon
	.dw menu_pokemon
	.dw menu_pokemon
	.dw draw_map
	.db MN,"Pok",$96,"dex",NEWL
	.db MN,"Pok",$96,"mon",NEWL
	.db MN,"Objets",NEWL
	.db MN,"Joueur",NEWL
	.db MN,"Sauver",NEWL
	.db MN,"Options",NEWL
	.db MN,"Retour",0

menu_battle:
	.db 4
	.dw battle_draw_fight_menu
	.dw battle_draw_fight_menu
	.dw battle_draw_fight_menu
	.dw exit
	.db MN,"Attaquer",NEWX,$36,MN,"Pok",$96,"mon",NEWL
	.db MN,"Inventaire",NEWX,$36,MN,"Fuite",0

menu_battle_attack:
	.db 4		;attacks number
current_player_pokemon = $+1
	.db PKMN,0	;load our pokémon
	.db MN,_AT1,	NEWX,48,MN,_AT2,NEWL
	.db MN,_AT3,	NEWX,48,MN,_AT4,0

menu_pokemon_str_name:
	.db "Nom",0

menu_pokemon_str_lvl:
	.db "Niv",0

menu_pokemon_str_hp:
	.db "PV",0

menu_pokemon_str_states:
	.dw menu_pokemon_str_poison,menu_pokemon_str_sleep,menu_pokemon_str_para

menu_pokemon_str_poison:
	.db "PSN",0

menu_pokemon_str_sleep:
	.db "DOR",0

menu_pokemon_str_para:
	.db "PAR",0

battle_wild_pokemon_intro1:
	.db "Un ",ENEM,0,_NAME,NEWL
	.db "sauvage apparait !",BRK,0

battle_player_pokemon_intro1:
	.db "En avant !",NEWL
starting_player_pokemon1 = $+1
	.db PKMN,1,_NAME," !",BRK,0

battle_player_pokemon_change:
	.db "Reviens !",0

battle_str_enemy:
	.db ENEM,0,_NAME,NEWXY,2,10
	.db "N:",_LVL,	NEWX,24,_HP,"/",_HPTOT,0

battle_str_player:
starting_player_pokemon2 = $+1
	.db PKMN,0,_NAME,NEWXY,43,35
	.db "N:",_LVL,	NEWX,66,_HP,"/",_HPTOT,0

battle_str_lvl:
	.db "N:",0

battle_str_attack:
	.db _NAME," lance",NEWL
current_attack:
	.db _AT1,0

battle_str_super_effective:
	.db "C'est super efficace !",0

battle_str_not_effective:
	.db "Ce n'est pas tr",$97,"s efficace...",0

battle_str_no_effect:
	.db "Mais ",$b3,"a n'affecte pas le",$d6
	.db "pok",$96,"mon adverse...",0

battle_str_critical_hit:
	.db "Coup critique !",0

battle_str_attack_missed:
	.db "Mais l'attaque ",$96,"choue !",0	; but the attack missed

battle_str_opponent_ko:
	.db "Le ",0

battle_str_opponent_ko_next:
	.db $d6,"ennemi est K.O. !",0

battle_str_experience_earned:
	.db " gagne",$d6,0

battle_str_experience_earned_next:
	.db "points d'EXP !",0

battle_str_level_up:
	.db " monte au",$d6,"niveau ",0

battle_str_learn_attack:
	.db " tente",$d6,"d'apprendre ",0

battle_str_learn_attack_valid:
	.db "Apprendre",$d6,"Annuler",0

battle_str_are_you_sure:
	.db $94,"tes vous s",$b0,"re ?",0

battle_str_yes_no:
	.db "Oui",$d6,"Non",0

battle_str_evolution_start:
	.db "Hein ? ",0

battle_str_evolution_end:
	.db $96,"volue !",0

battle_str_evolution_cancelled:
	.db "n'",$96,"volue plus !",0

battle_str_evolution_done:
	.db " ",$96,"volue",$d6,"en ",0

battle_menu_pokemon_str:
	.db "Ordre",$d6,"Stats",$d6,"Retour",0

menu_pokemon_list:
	.db 3
	.db "Nom",NEWX,47,"Niv",NEWX,59,"PV",NEWL
	.db MN,PKMN,3,_NAME,10,_LVL,47,_HP,59,$2F,_HPTOT,77,NEWL
	.db MN,PKMN,2,_NAME,10,_LVL,47,_HP,59,$2F,_HPTOT,77,NEWL
	.db MN,PKMN,1,_NAME,10,_LVL,47,_HP,59,$2F,_HPTOT,77,0

sub_menu_l_str:
	.db PKMN,3,_AT1,10,_PP1,55,NEWL,_AT2,10,_PP2,55,NEWX,90,">",0
	.db PKMN,2,_AT1,10,_PP1,55,NEWL,_AT2,10,_PP2,55,NEWX,90,">",0
	.db PKMN,1,_AT1,10,_PP1,55,NEWL,_AT2,10,_PP2,55,NEWX,90,">",0

sub_menu_r_str:
	.db PKMN,3,_AT3,10,_PP3,55,NEWL,_AT4,10,_PP4,55,NEWX,2,"<",0
	.db PKMN,2,_AT3,10,_PP3,55,NEWL,_AT4,10,_PP4,55,NEWX,2,"<",0
	.db PKMN,1,_AT3,10,_PP3,55,NEWL,_AT4,10,_PP4,55,NEWX,2,"<",0

trainer_intro_str:
	.db "Un dresseur veut se battre !",BRK,0