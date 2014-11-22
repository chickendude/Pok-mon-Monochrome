;Pokémons names
bulbasaur_txt:
	.db "BULBIZARRE",0
ivysaur_txt:
	.db "HERBIZARRE",0
venusaur_txt:
	.db "FLORIZARRE",0
charmander_txt:
	.db "SALAM",$92,"CHE",0
charmeleon_txt:
	.db "REPTINCEL",0
charizard_txt:
	.db "DRACAUFEU",0
squirtle_txt:
	.db "CARAPUCE",0
wartortle_txt:
	.db "CARABAFFE",0
blastoise_txt:
	.db "TORTANK",0
caterpie_txt:
	.db "CHENIPAN",0
metapod_txt:
	.db "CHRYSACIER",0
butterfree_txt:
	.db "PAPILUSION",0
weedle_txt:
	.db "ASPICOT",0
kakuna_txt:
	.db "COCONFORT",0
beedrill_txt:
	.db "DARDARGNAN",0
pidgey_txt:
	.db "ROUCOUL",0
pidgeotto_txt:
	.db "ROUCOUPS",0
pidgeot_txt:
	.db "ROUCARNAGE",0
rattata_txt:
	.db "RATTATA",0
raticate_txt:
	.db "RATTATAC",0
spearow_txt:
	.db "PIAFABEC",0
fearow_txt:
	.db "RAPASDEPIC",0
ekans_txt:
	.db "ABO",0
arbok_txt:
	.db "ARBOK",0
pikachu_txt:
	.db "PIKACHU",0
raichu_txt:
	.db "RAICHU",0
sandshrew_txt:
	.db "SABELETTE",0
sandslash_txt:
	.db "SABLAIREAU",0
nidoranF_txt:
	.db "NIDORAN F",0
nidorina_txt:
	.db "NIDORINA",0
nidoqueen_txt:
	.db "NIDOQUEEN",0
nidoranM_txt:
	.db "NIDORAN M",0
nidorino_txt:
	.db "NIDORINO",0
nidoking_txt:
	.db "NIDOKING",0
clefairy_txt:
	.db "MELOFEE",0
	.db "MELODELFE",0
	.db "GOUPIX",0
	.db "FEUNARD",0
	.db "RONDOUDOU",0
	.db "GRODOUDOU",0
	.db "NOSFERAPTI",0
	.db "NOSFERALTO",0
	.db "MYSTHERBE",0
	.db "ORTIDE",0
	.db "RAFFLESIA",0
	.db "PARAS",0
	.db "PARASECT",0
	.db "MIMITOSS",0
	.db "AEROMITE",0
	.db "TAUPIQUEUR",0
	.db "TRIOPIKEUR",0
	.db "MIAOUSS",0
	.db "PERSIAN",0
	.db "PSYKOKWAK",0
	.db "AKWAKWAK",0
	.db "FEROSINGE",0
	.db "COLOSSINGE",0
	.db "CANINOS",0
	.db "ARCANIN",0
	.db "PTITARD",0
	.db "TETARTE",0
	.db "TARTARD",0
	.db "ABRA",0
	.db "KADABRA",0
	.db "ALAKAZAM",0
	.db "MACHOP",0
	.db "MACHOPEUR",0
	.db "MACKOGNEUR",0
	.db "CHETIFLOR",0
	.db "BOUSTIFLOR",0
	.db "EMPIFLOR",0
	.db "TENTACOOL",0
	.db "TENTACRUEL",0
	.db "RACAILLOU",0
	.db "GRAVALANCH",0
	.db "GROLEM",0
	.db "PONYTA",0
	.db "GALOPA",0
	.db "RAMOLOSS",0
	.db "FLAGADOSS",0
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
	.db MN,"Continuer",NEWL
	.db MN,"Nouveau jeu",NEWL
	.db MN,"Quitter",0

gender_str:
	.db $94,"tes vous un gar",$b3,"on ou une",NEWL
	.db "fille ?",0
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
	.db MN,_AT1,NEWX,48,MN,_AT2,NEWL
	.db MN,_AT3,NEWX,48,MN,_AT4,0

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
	.db "N:",_LVL,	NEWX,24		;continues into HP_txt
HP_txt:
	.db _HP,"/",_HPTOT,0

battle_str_player:
starting_player_pokemon2 = $+1
	.db PKMN,0,_NAME,NEWXY,43,35
	.db "N:",_LVL,	NEWX,66,_HP,"/",_HPTOT,0

	.db _HP,0

battle_str_lvl:
	.db "N:",0

battle_str_attack:
	.db _NAME," lance",NEWL
current_attack:
	.db _AT1,BRK,0

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
	.db ENEM,0,"Le ",_NAME,NEWL
	.db "ennemi est K.O. !",BRK,0

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
	.db 6
	.db "Nom",NEWX,54,"Niv",NEWX,70,"PV",NEWL
	.db PKMN,1,MN,_NAME,NEWX,54,_LVL,NEWX,68,_HP,"/ ",_HPTOT,NEWL
	.db PKMN,2,MN,_NAME,NEWX,54,_LVL,NEWX,68,_HP,"/ ",_HPTOT,NEWL
	.db PKMN,3,MN,_NAME,NEWX,54,_LVL,NEWX,68,_HP,"/ ",_HPTOT,NEWL
	.db PKMN,4,MN,_NAME,NEWX,54,_LVL,NEWX,68,_HP,"/ ",_HPTOT,NEWL
	.db PKMN,5,MN,_NAME,NEWX,54,_LVL,NEWX,68,_HP,"/ ",_HPTOT,NEWL
	.db PKMN,6,MN,_NAME,NEWX,54,_LVL,NEWX,68,_HP,"/ ",_HPTOT,NEWL
menu_pokemon_list_left:
	.db PKMN,1,NEWX,12,"Status",NEWL,NEWX,4,_AT1,NEWX,55,_PP1,"/",_PP1MAX,NEWX,90,">",NEWL,NEWX,4,_AT2,NEWX,55,_PP2,"/",_PP1MAX,0
	.db PKMN,2,NEWX,12,"Status",NEWL,NEWX,4,_AT1,NEWX,55,_PP1,"/",_PP1MAX,NEWX,90,">",NEWL,NEWX,4,_AT2,NEWX,55,_PP2,"/",_PP1MAX,0
	.db PKMN,3,NEWX,12,"Status",NEWL,NEWX,4,_AT1,NEWX,55,_PP1,"/",_PP1MAX,NEWX,90,">",NEWL,NEWX,4,_AT2,NEWX,55,_PP2,"/",_PP1MAX,0
	.db PKMN,4,NEWX,12,"Status",NEWL,NEWX,4,_AT1,NEWX,55,_PP1,"/",_PP1MAX,NEWX,90,">",NEWL,NEWX,4,_AT2,NEWX,55,_PP2,"/",_PP1MAX,0
	.db PKMN,5,NEWX,12,"Status",NEWL,NEWX,4,_AT1,NEWX,55,_PP1,"/",_PP1MAX,NEWX,90,">",NEWL,NEWX,4,_AT2,NEWX,55,_PP2,"/",_PP1MAX,0
	.db PKMN,6,NEWX,12,"Status",NEWL,NEWX,4,_AT1,NEWX,55,_PP1,"/",_PP1MAX,NEWX,90,">",NEWL,NEWX,4,_AT2,NEWX,55,_PP2,"/",_PP1MAX,0
menu_pokemon_list_right:
	.db PKMN,1,NEWX,12,"EXP?",NEWL,"<",NEWX,8,_AT3,NEWX,59,_PP3,NEWL,NEWX,8,_AT4,NEWX,59,_PP4,0
	.db PKMN,2,NEWX,12,"EXP?",NEWL,"<",NEWX,8,_AT3,NEWX,59,_PP3,NEWL,NEWX,8,_AT4,NEWX,59,_PP4,0
	.db PKMN,3,NEWX,12,"EXP?",NEWL,"<",NEWX,8,_AT3,NEWX,59,_PP3,NEWL,NEWX,8,_AT4,NEWX,59,_PP4,0
	.db PKMN,4,NEWX,12,"EXP?",NEWL,"<",NEWX,8,_AT3,NEWX,59,_PP3,NEWL,NEWX,8,_AT4,NEWX,59,_PP4,0
	.db PKMN,5,NEWX,12,"EXP?",NEWL,"<",NEWX,8,_AT3,NEWX,59,_PP3,NEWL,NEWX,8,_AT4,NEWX,59,_PP4,0
	.db PKMN,6,NEWX,12,"EXP?",NEWL,"<",NEWX,8,_AT3,NEWX,59,_PP3,NEWL,NEWX,8,_AT4,NEWX,59,_PP4,0

menu_pokemon_options:
	.db 3
	.dw menu_pokemon_stats
	.dw menu_pokemon_order
	.dw menu_pokemon
	.db MN,"Stats",NEWL
	.db MN,"Ordre",NEWL
	.db MN,"Retour",0

stats_text:
	.db NEWX,40,_NAME,NEWL
	.db NEWXY,40,10,"L: ",_LVL,"STATUS/",NEWL
	.db NEWXY,2,26,"ATTACK",NEWX,40,"TYPE1:",NEWL
	.db NEWX,10,_ATK,NEWX,45,"TYPE",NEWL
	.db "DEFENSE",NEWX,40,"TYPE2:",NEWL
	.db NEWX,10,_DEF,NEWX,45,"TYPE",NEWL
	.db "SPEED",NEWX,40,"EXP:",NEWL
	.db NEWX,10,NEWX,40,"NEXT LVL:",NEWL
	.db 0


trainer_intro_str:
	.db "Un dresseur veut se battre !",BRK,0
