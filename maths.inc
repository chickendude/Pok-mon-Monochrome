calculate_proportionality:	; output : a = int((hl/bc)*a)
	push af
	push bc
	bcall(_SetXXXXOP2)
	bcall(_OP2ToOP1)
	pop hl
	bcall(_SetXXXXOP2)
	bcall(_fpdiv)
	pop af
	bcall(_SetXXOP2)
	bcall(_FPMult)
	jp maths_functions_end

calculate_damages:
; input :	hl = attacking pokémon's stats pointer
;		 	de = Pokémon being attacked stats pointer
; output : a = int(((([attacking pokémon level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50+2)*CE)
	push hl				; on commence par vérifier la précision de l'attaque
	push de
		ld a,(current_attack)
		sub _AT1
		rra
		call find_attack_data_current_pokemon_id	;cpID = currentPokemon ID, read the data of attack ID X from the pokemon in currentPokemon
		ld d,0
		ld e,ATK_ACCURACY
		add hl,de
		ld e,(hl)
		ld b,100
		call random		; on tire un nombre sur 100
		inc a
		sub e				; on lui soustrait la précision de l'attaque
	pop de
	pop hl
	scf
	 ret p					; si le test est positif, l'attaque rate
	ld a,(hl)				;a = pokemon's pokédex id
	push hl
		push de
			call find_pokemon_data
			ld e,POKE_DEF
			ld d,0
			add hl,de
			ld l,(hl)		; hl = DEF
			ld h,0
		pop de
		inc de
		ld a,(de)			;defending pokemon's level
		call calculate_stats
		ld h,0
		ld l,a				; hl = DEF at level de
		bcall(_SetXXXXOP2)
		ld a,50
		bcall(_SetXXOP1)
		bcall(_FPMult)		; op1 = [Pokémon being attacked DEF at his level]*50
		bcall(_OP1ToOP4)	; because op3 is destroyed _FPMult/_fpdiv
		ld a,2
		bcall(_SetXXOP1)
		ld a,5
		bcall(_SetXXOP2)
		bcall(_fpdiv)		; op1 = .4
	pop hl
	push hl
		inc hl	; son niveau
		ld l,(hl)
		ld h,0
		bcall(_SetXXXXOP2)
		bcall(_FPMult)		; op1 = [Pokémon attacking level]*0.4
		ld a,2
		bcall(_SetXXOP2)
		bcall(_FPAdd)		; op1 = [Pokémon attacking level]*0.4+2
	pop hl
	push hl
		ld a,(hl)
		call find_pokemon_data
		ld e,POKE_ATK
		ld d,0
		add hl,de
		ld l,(hl)			; hl = ATT
		ld h,0
	pop de
	inc de
	ld a,(de)
	call calculate_stats
	ld h,0
	ld l,a				; hl = ATT at level hl
	bcall(_SetXXXXOP2)
	bcall(_FPMult)		; op1 = ([Pokémon attacking level]*0.4+2)*[Pokémon attacking ATT at his level]
	ld a,(current_attack)
	call find_attack_data
	ld d,0
	ld e,POKE_ATK
	add hl,de
	ld l,(hl)
	ld h,d
	bcall(_SetXXXXOP2)
	bcall(_FPMult)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]
	bcall(_OP4ToOP2)
	bcall(_fpdiv)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50)
	ld a,2
	bcall(_SetXXOP2)
	bcall(_FPAdd)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50+2)
CE = $+1				; 0=pas très efficace, 1=normal, 2=super efficace
	ld a,0
	or a
	jr z,calculate_damages_not_effective
	bcall(_SetXXOP2)
	bcall(_FPMult)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50+2)*CE
	jr calculate_damages_next

calculate_damages_not_effective:
	ld a,2
	bcall(_SetXXOP2)
	bcall(_fpdiv)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50+2)*CE

calculate_damages_next:
	bcall(_OP1ToOP4)	; op1=dégâts, mais on le passe dans op4 (pas 3, cf plus haut) le temps de faire les calculs suivants
	ld b,16				; calcul de la marge de 15% (0.85 à 1 fois le résultat)
	call random
	add a,85
	ld h,0
	ld l,a
	bcall(_SetXXXXOP2)
	bcall(_OP2ToOP1)	; car _SetXXOP1 ne marche pas si a=100 (jusqu'à 99 seulement)
	ld hl,100
	bcall(_SetXXXXOP2)
	bcall(_fpdiv)
	bcall(_OP4ToOP2)
	bcall(_FPMult)
	bcall(_int)
	bcall(_ConvOP1)
	push af
	ld b,16 ; chance de faire un coup critique = 1/16
	call random
	ld b,a
	pop af
	dec b
	 ret p ;finished calculating damage
	add a,a	; si on a de la chance : attaque*2 (il faudra peut être vérifier si a>255)
	 jr nc,$+4 ;**check if a has overflowed
		ld a,255
	push af
		call battle_draw_frame
		ld hl,battle_str_critical_hit
		call draw_battle_dialogue
	pop af
	or a
	ret

; cf http://www.pokepedia.fr/index.php/Calcul_des_statistiques , je modifierai peut être la formule ci-dessous :
calculate_hp:
; input : hl = pokemon hp base pointer, a = level
; output : a = int(2*hl*a/100+a+10)
	call calculate_stats_or_hp
	ld h,0
	ld l,a
	bcall(_SetXXXXOP2)
	bcall(_FPAdd)
	ld a,10
	bcall(_SetXXOP2)
	bcall(_FPAdd)
	jp maths_functions_end

calculate_stats:	; output : op2 = int(2*hl*a/100+5), uses op5
	push hl
	bcall(_OP1ToOP5)
	pop hl
	call calculate_stats_or_hp
	ld a,5
	bcall(_SetXXOP2)
	bcall(_FPAdd)
	bcall(_OP1ToOP2)
	bcall(_OP5ToOP1)
	ret

calculate_stats_or_hp:
	push af
	push hl
	ld a,2
	bcall(_SetXXOP1)
	pop hl
	ld l,(hl)
	ld h,0
	bcall(_SetXXXXOP2)
	bcall(_FPMult)
	pop af
	push af
	ld h,0
	ld l,a
	bcall(_SetXXXXOP2
	bcall(_FPMult)
	ld hl,100
	bcall(_SetXXXXOP2)
	bcall(_fpdiv)
	pop af
	ret

calculate_experience:	; output : a=experience de base du pokémon vaincu*niveau du pokémon vaincu/7/c
	push bc
	push hl
	inc hl
	ld l,(hl)
	ld h,0
	bcall(_SetXXXXOP2)
	bcall(_OP2ToOP1)	; on récupère le niveau du pokémon vaincu et on le met dans op1
	pop hl
	ld a,(hl)
	call find_pokemon_data
	ld e,POKE_EXP
	add hl,de
	ld l,(hl)
	ld h,d
	bcall(_SetXXXXOP2)	; on met l'experience de base dans op2
	bcall(_FPMult)
	ld a,7
	bcall(_SetXXOP2)
	bcall(_fpdiv)
	pop bc
	ld a,c
	bcall(_SetXXOP2)
	bcall(_fpdiv)

maths_functions_end:	; a=op1
	bcall(_int)	; je me demande si c'est utile
	bcall(_ConvOP1)
	ret

calculate_next_experience:	; input : none; output : de=XPmax
	ld hl,(battle_current_player_pokemon_address)
	push hl
	ld a,(hl)
	call find_pokemon_data
	ld e,POKE_EXPCURVE
	add hl,de
	ld a,(hl)	; a=experience curve #
	pop hl
	push af
	inc hl
	ld l,(hl)
	ld h,0	; hl=pokémon lvl
	call hl_pow_2
	ld d,h
	ld e,l
	pop af
	cp 1
	jr z,calculate_next_experience_fast_curve
	cp 2
	jr z,calculate_next_experience_medium_fast_curve
	cp 3
	jr z,calculate_next_experience_medium_slow_curve

calculate_next_experience_slow_curve:	; exp=6.5*lvl^2
	ld bc,13
	jr calculate_next_experience_pre_end1

calculate_next_experience_fast_curve:	; exp=5*lvl^2
	ld bc,5
	jr calculate_next_experience_pre_end2

calculate_next_experience_medium_fast_curve:	; exp=5.5*lvl^2
	ld bc,11

calculate_next_experience_pre_end1:
	call de_times_bc
	ld c,2
	call hl_div_c
	jr calculate_next_experience_end

calculate_next_experience_medium_slow_curve:	; exp=6*lvl^2
	ld bc,6

calculate_next_experience_pre_end2:
	call de_times_bc

calculate_next_experience_end:
	ld d,h
	ld e,l
	ret

hl_pow_2:
	push hl
	push hl
	pop bc
	pop de

de_times_bc:
;By Xeda112358 & Quigibo
;Inputs:
;     DE and BC are factors
;Outputs:
;     A, DE are destroyed
;     HL is the product
;
	ld a,c
	ld c,b
	ld hl,0
	ld b,16
mul_loop_1:
	add hl,hl
	add a,a
	rl c
	jr nc,$+3
	add hl,de
	djnz mul_loop_1
	ret

hl_div_c:
;By Xeda112358
;Inputs:
;     HL is the numerator
;     C is the denominator
;Outputs:
;     A is the remainder
;     B is destroyed
;     HL is the quotient
;
	ld b,16
	xor a
	add hl,hl
	rla
	cp c
	jr c,$+4
	inc l
	sub c
	djnz $-7
	ret

slow_mult_hl_b:
	push de
		ld e,l
		ld d,h
		ld hl,0
		dec b
		inc b
		 jr z,slow_mult_hl_b_exit
		add hl,de
		djnz $-1
slow_mult_hl_b_exit:
	pop de
	ret
