attack_index:
	.dw absorb_atk
	.dw acid_atk
	.dw acid_armor_atk
	.dw agility_atk
	.dw amnesia_atk
	.dw aurora_beam_atk
	.dw barrage_atk
	.dw barrier_atk
	.dw bide_atk
	.dw bind_atk
	.dw bite_atk
	.dw blizzard_atk
	.dw body_slam_atk
	.dw bone_club_atk
	.dw bonemerang_atk
	.dw bubble_atk
	.dw bubblebeam_atk
	.dw clamp_atk
	.dw comet_punch_atk
	.dw confuse_ray_atk
	.dw confusion_atk
	.dw constrict_atk
	.dw conversion_atk
	.dw counter_atk
	.dw crabhammer_atk
	.dw cut_atk
	.dw defense_curl_atk
	.dw dig_atk
	.dw disable_atk
	.dw dizzy_punch_atk
	.dw double_kick_atk
	.dw double_team_atk
	.dw double_edge_atk
	.dw doubleslap_atk
	.dw dragon_rage_atk
	.dw dream_eater_atk
	.dw drill_peck_atk
	.dw earthquake_atk
	.dw egg_bomb_atk
	.dw ember_atk
	.dw explosion_atk
	.dw fire_blast_atk
	.dw fire_punch_atk
	.dw fire_spin_atk
	.dw fissure_atk
	.dw flamethrower_atk
	.dw flash_atk
	.dw fly_atk
	.dw focus_energy_atk
	.dw fury_attack_atk
	.dw fury_swipes_atk
	.dw glare_atk
	.dw growl_atk
	.dw growth_atk
	.dw guillotine_atk
	.dw gust_atk
	.dw harden_atk
	.dw haze_atk
	.dw headbutt_atk
	.dw hi_jump_kick_atk
	.dw horn_attack_atk
	.dw horn_drill_atk
	.dw hydro_pump_atk
	.dw hyper_beam_atk
	.dw hyper_fang_atk
	.dw hypnosis_atk
	.dw ice_beam_atk
	.dw ice_punch_atk
	.dw jump_kick_atk
	.dw karate_chop_atk
	.dw kinesis_atk
	.dw leech_life_atk
	.dw leech_seed_atk
	.dw leer_atk
	.dw lick_atk
	.dw light_screen_atk
	.dw lovely_kiss_atk
	.dw low_kick_atk
	.dw meditate_atk
	.dw mega_drain_atk
	.dw mega_kick_atk
	.dw mega_punch_atk
	.dw metronome_atk
	.dw mimic_atk
	.dw minimize_atk
	.dw mirror_move_atk
	.dw mist_atk
	.dw night_shade_atk
	.dw pay_day_atk
	.dw peck_atk
	.dw petal_dance_atk
	.dw pin_missile_atk
	.dw poison_gas_atk
	.dw poison_sting_atk
	.dw poisonpowder_atk
	.dw pound_atk
	.dw psybeam_atk
	.dw psychic_atk
	.dw psywave_atk
	.dw quick_attack_atk
	.dw rage_atk
	.dw razor_leaf_atk
	.dw razor_wind_atk
	.dw recover_atk
	.dw reflect_atk
	.dw rest_atk
	.dw roar_atk
	.dw rock_slide_atk
	.dw rock_throw_atk
	.dw rolling_kick_atk
	.dw sand_attack_atk
	.dw scratch_atk
	.dw screech_atk
	.dw seismic_toss_atk
	.dw selfdestruct_atk
	.dw sharpen_atk
	.dw sing_atk
	.dw skull_bash_atk
	.dw sky_attack_atk
	.dw slam_atk
	.dw slash_atk
	.dw sleep_powder_atk
	.dw sludge_atk
	.dw smog_atk
	.dw smokescreen_atk
	.dw softboiled_atk
	.dw solarbeam_atk
	.dw sonicboom_atk
	.dw spike_cannon_atk
	.dw splash_atk
	.dw spore_atk
	.dw stomp_atk
	.dw strength_atk
	.dw string_shot_atk
	.dw struggle_atk
	.dw stun_spore_atk
	.dw submission_atk
	.dw substitute_atk
	.dw super_fang_atk
	.dw supersonic_atk
	.dw surf_atk
	.dw swift_atk
	.dw swords_dance_atk
	.dw tackle_atk
	.dw tail_whip_atk
	.dw take_down_atk
	.dw teleport_atk
	.dw thrash_atk
	.dw thunder_atk
	.dw thunder_wave_atk
	.dw thunderbolt_atk
	.dw thunderpunch_atk
	.dw thundershock_atk
	.dw toxic_atk
	.dw transform_atk
	.dw tri_attack_atk
	.dw twineedle_atk
	.dw vicegrip_atk
	.dw vine_whip_atk
	.dw water_gun_atk
	.dw waterfall_atk
	.dw whirlwind_atk
	.dw wing_attack_atk
	.dw withdraw_atk
	.dw wrap_atk

; je rajoutterai peut être des trucs spéciaux par attaques (jackpot qui fait gagner du fric par exemple)

; type, state alteration (0=normal; 1=poison; 2=sleep; 3=para; 4=confusion), PP, power, accuracy (%), name
#define ATK_TYPE	0
#define ATK_STATE	1
#define ATK_PP	2
#define ATK_POWER	3
#define ATK_ACCURACY	4
#define ATK_NAME	5

#define ATK_ABSORB	1
#define ATK_ACID	2
#define ATK_ACID_ARMOR	3
#define ATK_AGILITY	4
#define ATK_AMNESIA	5
#define ATK_AURORA_BEAM	6
#define ATK_BARRAGE	7
#define ATK_BARRIER	8
#define ATK_BIDE	9
#define ATK_BIND	10
#define ATK_BITE	11
#define ATK_BLIZZARD	12
#define ATK_BODY_SLAM	13
#define ATK_BONE_CLUB	14
#define ATK_BONEMERANG	15
#define ATK_BUBBLE	16
#define ATK_BUBBLEBEAM	17
#define ATK_CLAMP	18
#define ATK_COMET_PUNCH	19
#define ATK_CONFUSE_RAY	20
#define ATK_CONFUSION	21
#define ATK_CONSTRICT	22
#define ATK_CONVERSION	23
#define ATK_COUNTER	24
#define ATK_CRABHAMMER	25
#define ATK_CUT		26
#define ATK_DEFENSE_CURL	27
#define ATK_DIG		28
#define ATK_DISABLE	29
#define ATK_DIZZY_PUNCH	30
#define ATK_DOUBLE_KICK	31
#define ATK_DOUBLE_TEAM	32
#define ATK_DOUBLE_EDGE	33
#define ATK_DOUBLESLAP	34
#define ATK_DRAGON_RAGE	35
#define ATK_DREAM_EATER	36
#define ATK_DRILL_PECK	37
#define ATK_EARTHQUAKE	38
#define ATK_EGG_BOMB	39
#define ATK_EMBER	40
#define ATK_EXPLOSION	41
#define ATK_FIRE_BLAST	42
#define ATK_FIRE_PUNCH	43
#define ATK_FIRE_SPIN	44
#define ATK_FISSURE	45
#define ATK_FLAMETHROWER	46
#define ATK_FLASH	47
#define ATK_FLY		48
#define ATK_FOCUS_ENERGY	49
#define ATK_FURY_ATTACK	50
#define ATK_FURY_SWIPES	51
#define ATK_GLARE	52
#define ATK_GROWL	53
#define ATK_GROWTH	54
#define ATK_GUILLOTINE	55
#define ATK_GUST	56
#define ATK_HARDEN	57
#define ATK_HAZE	58
#define ATK_HEADBUTT	59
#define ATK_HI_JUMP_KICK	60
#define ATK_HORN_ATTACK	61
#define ATK_HORN_DRILL	62
#define ATK_HYDRO_PUMP	63
#define ATK_HYPER_BEAM	64
#define ATK_HYPER_FANG	65
#define ATK_HYPNOSIS	66
#define ATK_ICE_BEAM	67
#define ATK_ICE_PUNCH	68
#define ATK_JUMP_KICK	69
#define ATK_KARATE_CHOP	70
#define ATK_KINESIS	71
#define ATK_LEECH_LIFE	72
#define ATK_LEECH_SEED	73
#define ATK_LEER	74
#define ATK_LICK	75
#define ATK_LIGHT_SCREEN	76
#define ATK_LOVELY_KISS	77
#define ATK_LOW_KICK	78
#define ATK_MEDITATE	79
#define ATK_MEGA_DRAIN	80
#define ATK_MEGA_KICK	81
#define ATK_MEGA_PUNCH	82
#define ATK_METRONOME	83
#define ATK_MIMIC	84
#define ATK_MINIMIZE	85
#define ATK_MIRROR_MOVE	86
#define ATK_MIST	87
#define ATK_NIGHT_SHADE	88
#define ATK_PAY_DAY	89
#define ATK_PECK	90
#define ATK_PETAL_DANCE	91
#define ATK_PIN_MISSILE	92
#define ATK_POISON_GAS	93
#define ATK_POISON_STING	94
#define ATK_POISONPOWDER	95
#define ATK_POUND	96
#define ATK_PSYBEAM	97
#define ATK_PSYCHIC	98
#define ATK_PSYWAVE	99
#define ATK_QUICK_ATTACK	100
#define ATK_RAGE	101
#define ATK_RAZOR_LEAF	102
#define ATK_RAZOR_WIND	103
#define ATK_RECOVER	104
#define ATK_REFLECT	105
#define ATK_REST	106
#define ATK_ROAR	107
#define ATK_ROCK_SLIDE	108
#define ATK_ROCK_THROW	109
#define ATK_ROLLING_KICK	110
#define ATK_SAND_ATTACK	111
#define ATK_SCRATCH	112
#define ATK_SCREECH	113
#define ATK_SEISMIC_TOSS	114
#define ATK_SELFDESTRUCT	115
#define ATK_SHARPEN	116
#define ATK_SING	117
#define ATK_SKULL_BASH	118
#define ATK_SKY_ATTACK	119
#define ATK_SLAM	120
#define ATK_SLASH	121
#define ATK_SLEEP_POWDER	122
#define ATK_SLUDGE	123
#define ATK_SMOG	124
#define ATK_SMOKESCREEN	125
#define ATK_SOFTBOILED	126
#define ATK_SOLARBEAM	127
#define ATK_SONICBOOM	128
#define ATK_SPIKE_CANNON	129
#define ATK_SPLASH	130
#define ATK_SPORE	131
#define ATK_STOMP	132
#define ATK_STRENGTH	133
#define ATK_STRING_SHOT	134
#define ATK_STRUGGLE	135
#define ATK_STUN_SPORE	136
#define ATK_SUBMISSION	137
#define ATK_SUBSTITUTE	138
#define ATK_SUPER_FANG	139
#define ATK_SUPERSONIC	140
#define ATK_SURF	141
#define ATK_SWIFT	142
#define ATK_SWORDS_DANCE	143
#define ATK_TACKLE	144
#define ATK_TAIL_WHIP	145
#define ATK_TAKE_DOWN	146
#define ATK_TELEPORT	147
#define ATK_THRASH	148
#define ATK_THUNDER	149
#define ATK_THUNDER_WAVE	150
#define ATK_THUNDERBOLT	151
#define ATK_THUNDERPUNCH	152
#define ATK_THUNDERSHOCK	153
#define ATK_TOXIC	154
#define ATK_TRANSFORM	155
#define ATK_TRI_ATTACK	156
#define ATK_TWINEEDLE	157
#define ATK_VICEGRIP	158
#define ATK_VINE_WHIP	159
#define ATK_WATER_GUN	160
#define ATK_WATERFALL	161
#define ATK_WHIRLWIND	162
#define ATK_WING_ATTACK	163
#define ATK_WITHDRAW	164
#define ATK_WRAP	165

;type, special effect, PP, strength, accuracy, name
absorb_atk:
acid_atk:
acid_armor_atk:
agility_atk:
amnesia_atk:
aurora_beam_atk:
barrage_atk:
barrier_atk:
bide_atk:
bind_atk:
bite_atk:
	.db TYPE_NORMAL,0,25,60,100,"Morsure",0
blizzard_atk:
body_slam_atk:
bone_club_atk:
bonemerang_atk:
bubble_atk:
bubblebeam_atk:
clamp_atk:
comet_punch_atk:
confuse_ray_atk:
	.db TYPE_GHOST,4,10,0,100,"Onde folie",0
confusion_atk:
constrict_atk:
conversion_atk:
counter_atk:
crabhammer_atk:
cut_atk:
defense_curl_atk:
dig_atk:
disable_atk:
dizzy_punch_atk:
double_kick_atk:
double_team_atk:
double_edge_atk:
doubleslap_atk:
dragon_rage_atk:
dream_eater_atk:
	.db TYPE_NORMAL,3,0,15,100,100,"D",$93,"VOR",$94,"VE",0	; cette attaque ne fonctionne normalement que si le pokemon adverse est endormie !
drill_peck_atk:
earthquake_atk:
egg_bomb_atk:
ember_atk:
explosion_atk:
fire_blast_atk:
fire_punch_atk:
fire_spin_atk:
fissure_atk:
flamethrower_atk:
flash_atk:
fly_atk:
focus_energy_atk:
fury_attack_atk:
fury_swipes_atk:
	.db TYPE_NORMAL,0,15,18,80,"Combo-Griffe",0
glare_atk:
growl_atk:		;**maybe use state 5 to lower attack ???**
	.db TYPE_NORMAL,0,40,0,100,"Rugissement",0
growth_atk:
guillotine_atk:
gust_atk:
harden_atk:
haze_atk:
headbutt_atk:
hi_jump_kick_atk:
horn_attack_atk:
horn_drill_atk:
hydro_pump_atk:
hyper_beam_atk:
hyper_fang_atk:
hypnosis_atk:
	.db TYPE_NORMAL,3,20,0,60,"Hypnose",0
ice_beam_atk:
ice_punch_atk:
jump_kick_atk:
karate_chop_atk:
kinesis_atk:
leech_life_atk:
leech_seed_atk:
leer_atk:
lick_atk:
	.db TYPE_GHOST,3,30,20,100,"L",$96,"chouille",0
light_screen_atk:
lovely_kiss_atk:
low_kick_atk:
meditate_atk:
mega_drain_atk:
mega_kick_atk:
mega_punch_atk:
metronome_atk:
mimic_atk:
minimize_atk:
mirror_move_atk:
mist_atk:
night_shade_atk:
	.db TYPE_GHOST,0,15,40,100,"T",$93,"N",$92,"BRES",0	; cette attaque retire normalement le nombre de PV égal au niveau de l'attaquant
pay_day_atk:
	.db TYPE_NORMAL,0,20,40,100,"Jackpot",0
peck_atk:
petal_dance_atk:
pin_missile_atk:
poison_gas_atk:
poison_sting_atk:
	.db TYPE_POISON,1,35,15,100,"Dard-Venin",0
poisonpowder_atk:
pound_atk:
psybeam_atk:
psychic_atk:
psywave_atk:
quick_attack_atk:
rage_atk:
razor_leaf_atk:
razor_wind_atk:
recover_atk:
reflect_atk:
rest_atk:
roar_atk:
rock_slide_atk:
rock_throw_atk:
rolling_kick_atk:
sand_attack_atk:
scratch_atk:
	.db TYPE_NORMAL,0,35,40,100,"Griffe",0
screech_atk:
seismic_toss_atk:
selfdestruct_atk:
sharpen_atk:
sing_atk:
skull_bash_atk:
sky_attack_atk:
slam_atk:
slash_atk:
	.db TYPE_NORMAL,0,20,70,100,"Tranche",0
sleep_powder_atk:
sludge_atk:
smog_atk:
smokescreen_atk:
softboiled_atk:
solarbeam_atk:
sonicboom_atk:
spike_cannon_atk:
splash_atk:
spore_atk:
stomp_atk:
strength_atk:
string_shot_atk:
struggle_atk:
stun_spore_atk:
submission_atk:
substitute_atk:
super_fang_atk:
supersonic_atk:
surf_atk:
swift_atk:									;******************************
	.db TYPE_NORMAL,0,20,60,0,"Meteores",0	;** vérifier la précision (je ne sais plus pourquoi j'ai mis 0)
swords_dance_atk:
tackle_atk:
	.db TYPE_NORMAL,0,35,50,95,"Charge",0
tail_whip_atk:
take_down_atk:
teleport_atk:
thrash_atk:
thunder_atk:
thunder_wave_atk:
thunderbolt_atk:
thunderpunch_atk:
thundershock_atk:
toxic_atk:
transform_atk:
tri_attack_atk:
twineedle_atk:
vicegrip_atk:
vine_whip_atk:
	.db TYPE_GRASS,0,10,35,100,"Fouet Lianes",0	;type, effects, PP, strength, accuracy
water_gun_atk:
waterfall_atk:
whirlwind_atk:
wing_attack_atk:
withdraw_atk:
wrap_atk:
