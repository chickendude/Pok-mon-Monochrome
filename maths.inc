calculate_proportionality:	; output : a = int((hl/bc)*a)
	push af
	push bc
	bcall(_setxxxxop2)
	bcall(_op2toop1)
	pop hl
	bcall(_setxxxxop2)
	bcall(_fpdiv)
	pop af
	bcall(_setxxop2)
	bcall(_fpmult)
	jp maths_functions_end

calculate_damages:
; input :	hl = attacking pok�mon's stats pointer
;		 	de = Pok�mon being attacked stats pointer
; output : a = int(((([attacking pok�mon level]*0.4+2)*[Attack power])*[Pok�mon attacking ATT at his level]/([Pok�mon being attacked DEF at his level]*50+2)*CE)
	push hl				; on commence par v�rifier la pr�cision de l'attaque
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
		sub e				; on lui soustrait la pr�cision de l'attaque
	pop de
	pop hl
	scf
	 ret p					; si le test est positif, l'attaque rate
	ld a,(hl)				;a = pokemon's pok�dex id
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
		bcall(_setxxxxop2)
		ld a,50
		bcall(_setxxop1)
		bcall(_fpmult)		; op1 = [Pok�mon being attacked DEF at his level]*50
		bcall(_op1toop4)	; because op3 is destroyed _fpmult/_fpdiv
		ld a,2
		bcall(_setxxop1)
		ld a,5
		bcall(_setxxop2)
		bcall(_fpdiv)		; op1 = .4
	pop hl
	push hl
		inc hl	; son niveau
		ld l,(hl)
		ld h,0
		bcall(_setxxxxop2)
		bcall(_fpmult)		; op1 = [Pok�mon attacking level]*0.4
		ld a,2
		bcall(_setxxop2)
		bcall(_fpadd)		; op1 = [Pok�mon attacking level]*0.4+2
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
	bcall(_setxxxxop2)
	bcall(_fpmult)		; op1 = ([Pok�mon attacking level]*0.4+2)*[Pok�mon attacking ATT at his level]
	ld a,(current_attack)
	call find_attack_data
	ld d,0
	ld e,POKE_ATK
	add hl,de
	ld l,(hl)
	ld h,d
	bcall(_setxxxxop2)
	bcall(_fpmult)		; op1 = (([Pok�mon attacking level]*0.4+2)*[Attack power])*[Pok�mon attacking ATT at his level]
	bcall(_op4toop2)
	bcall(_fpdiv)		; op1 = (([Pok�mon attacking level]*0.4+2)*[Attack power])*[Pok�mon attacking ATT at his level]/([Pok�mon being attacked DEF at his level]*50)
	ld a,2
	bcall(_setxxop2)
	bcall(_fpadd)		; op1 = (([Pok�mon attacking level]*0.4+2)*[Attack power])*[Pok�mon attacking ATT at his level]/([Pok�mon being attacked DEF at his level]*50+2)
CE = $+1				; 0=pas tr�s efficace, 1=normal, 2=super efficace
	ld a,0
	or a
	jr z,calculate_damages_not_effective
	bcall(_setxxop2)
	bcall(_fpmult)		; op1 = (([Pok�mon attacking level]*0.4+2)*[Attack power])*[Pok�mon attacking ATT at his level]/([Pok�mon being attacked DEF at his level]*50+2)*CE
	jr calculate_damages_next

calculate_damages_not_effective:
	ld a,2
	bcall(_setxxop2)
	bcall(_fpdiv)		; op1 = (([Pok�mon attacking level]*0.4+2)*[Attack power])*[Pok�mon attacking ATT at his level]/([Pok�mon being attacked DEF at his level]*50+2)*CE

calculate_damages_next:
	bcall(_op1toop4)	; op1=d�g�ts, mais on le passe dans op4 (pas 3, cf plus haut) le temps de faire les calculs suivants
	ld b,16				; calcul de la marge de 15% (0.85 � 1 fois le r�sultat)
	call random
	add a,85
	ld h,0
	ld l,a
	bcall(_setxxxxop2)
	bcall(_op2toop1)	; car _setxxop1 ne marche pas si a=100 (jusqu'� 99 seulement)
	ld hl,100
	bcall(_setxxxxop2)
	bcall(_fpdiv)
	bcall(_op4toop2)
	bcall(_fpmult)
	bcall(_int)
	bcall(_convop1)
	push af
	ld b,16 ; chance de faire un coup critique = 1/16
	call random
	ld b,a
	pop af
	dec b
	 ret p ;finished calculating damage
	add a,a	; si on a de la chance : attaque*2 (il faudra peut �tre v�rifier si a>255)
	 jr nc,$+4 ;**check if a has overflowed
		ld a,255
	push af
		call battle_draw_frame
		ld hl,battle_str_critical_hit
		call draw_battle_dialogue
	pop af
	or a
	ret

; cf http://www.pokepedia.fr/index.php/Calcul_des_statistiques , je modifierai peut �tre la formule ci-dessous :
calculate_hp:
; input : hl = pokemon hp base pointer, a = level
; output : a = int(2*hl*a/100+a+10)
	call calculate_stats_or_hp
	ld h,0
	ld l,a
	bcall(_setxxxxop2)
	bcall(_fpadd)
	ld a,10
	bcall(_setxxop2)
	bcall(_fpadd)
	jp maths_functions_end

calculate_stats:	; output : op2 = int(2*hl*a/100+5), uses op5
	push hl
	bcall(_op1toop5)
	pop hl
	call calculate_stats_or_hp
	ld a,5
	bcall(_setxxop2)
	bcall(_fpadd)
	bcall(_op1toop2)
	bcall(_op5toop1)
	ret

calculate_stats_or_hp:
	push af
	push hl
	ld a,2
	bcall(_setxxop1)
	pop hl
	ld l,(hl)
	ld h,0
	bcall(_setxxxxop2)
	bcall(_fpmult)
	pop af
	push af
	ld h,0
	ld l,a
	bcall(_setxxxxop2
	bcall(_fpmult)
	ld hl,100
	bcall(_setxxxxop2)
	bcall(_fpdiv)
	pop af
	ret

calculate_experience:	; output : a=experience de base du pok�mon vaincu*niveau du pok�mon vaincu/7/c
	push bc
	push hl
	inc hl
	ld l,(hl)
	ld h,0
	bcall(_setxxxxop2)
	bcall(_op2toop1)	; on r�cup�re le niveau du pok�mon vaincu et on le met dans op1
	pop hl
	ld a,(hl)
	call find_pokemon_data
	ld e,POKE_EXP
	add hl,de
	ld l,(hl)
	ld h,d
	bcall(_setxxxxop2)	; on met l'experience de base dans op2
	bcall(_fpmult)
	ld a,7
	bcall(_setxxop2)
	bcall(_fpdiv)
	pop bc
	ld a,c
	bcall(_setxxop2)
	bcall(_fpdiv)

maths_functions_end:	; a=op1
	bcall(_int)	; je me demande si c'est utile
	bcall(_convop1)
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
	ld h,0	; hl=pok�mon lvl
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