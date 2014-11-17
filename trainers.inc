#define TRAINER_ID	0
#define TRAINER_GENDER	1	;0=man, 1=woman
#define TRAINER_POKE_1_ID	2
#define TRAINER_POKE_1_LVL	3
#define TRAINER_POKE_2_ID	4
#define TRAINER_POKE_2_LVL	5
#define TRAINER_POKE_3_ID	6
#define TRAINER_POKE_3_LVL	7
#define TRAINER_POKE_4_ID	8
#define TRAINER_POKE_4_LVL	9
#define TRAINER_POKE_5_ID	10
#define TRAINER_POKE_5_LVL	11
#define TRAINER_POKE_6_ID	12
#define TRAINER_POKE_6_LVL	13
#define TRAINER_DATA_LENGTH	14

trainer_event:
	sub trainer_tile	; a = trainer id
	push af
	ld hl,map_trainers
	ld b,(map_trainers_end-map_trainers)/4
	call find_map_data
	bcall(_ldhlind)	; hl = trainers data relative to the current map
	pop bc
	push hl
	ld hl,(TRAINER_DATA_LENGTH)
	call slow_mult_hl_b
	ld d,0
	ld e,(hl)
	pop hl
	add hl,de	; hl = encountered trainer data
	; todo : check if already beaten, if not start the battle
	; etc...
	ld hl,trainer_intro_str
	jp draw_battle_dialogue

get_trainer_state:	; input : a=trainer ID ; output : carry flag is set if trainer is already beaten
	push af
	srl a
	srl a
	srl a	; a/8
	ld (de),a
	ld hl,trainers_state
	add hl,de
	pop af
	and %00000111
	ld b,a
	ld a,(hl)
 
get_trainer_state_loop:
	sla a
	djnz get_trainer_state_loop
	ret
 
trainers_state:
	.fill 4	; 4*8 = 32 trainers max for now