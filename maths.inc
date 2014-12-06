; Math functions
;####### 24 bit
;div_ehl_d			; EHL=EHL/D, A = remainder
;mult_dhl_e			; AHL=DHL*E
;mult_de_a			; AHL=DE*A
;####### 16 bit
;hl_pow_2			; HL=HL²
;de_times_bc		; HL=DE*BC
;div_hl_c			; HL=HL/C
;mult_hl_b			; slow
;mult_a_e			; HL=A*E
;mult_h_e			; HL=H*E


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
		bcall(_setxxxxop2)
		ld a,50
		bcall(_setxxop1)
		bcall(_fpmult)		; op1 = [Pokémon being attacked DEF at his level]*50
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
		bcall(_fpmult)		; op1 = [Pokémon attacking level]*0.4
		ld a,2
		bcall(_setxxop2)
		bcall(_fpadd)		; op1 = [Pokémon attacking level]*0.4+2
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
	bcall(_fpmult)		; op1 = ([Pokémon attacking level]*0.4+2)*[Pokémon attacking ATT at his level]
	ld a,(current_attack)
	call find_attack_data
	ld d,0
	ld e,POKE_ATK
	add hl,de
	ld l,(hl)
	ld h,d
	bcall(_setxxxxop2)
	bcall(_fpmult)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]
	bcall(_op4toop2)
	bcall(_fpdiv)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50)
	ld a,2
	bcall(_setxxop2)
	bcall(_fpadd)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50+2)
CE = $+1				; 0=pas très efficace, 1=normal, 2=super efficace
	ld a,0
	or a
	jr z,calculate_damages_not_effective
	bcall(_setxxop2)
	bcall(_fpmult)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50+2)*CE
	jr calculate_damages_next

calculate_damages_not_effective:
	ld a,2
	bcall(_setxxop2)
	bcall(_fpdiv)		; op1 = (([Pokémon attacking level]*0.4+2)*[Attack power])*[Pokémon attacking ATT at his level]/([Pokémon being attacked DEF at his level]*50+2)*CE

calculate_damages_next:
	bcall(_op1toop4)	; op1=dégâts, mais on le passe dans op4 (pas 3, cf plus haut) le temps de faire les calculs suivants
	ld b,16				; calcul de la marge de 15% (0.85 à 1 fois le résultat)
	call random
	add a,85
	ld h,0
	ld l,a
	bcall(_setxxxxop2)
	bcall(_op2toop1)	; car _SetXXOP1 ne marche pas si a=100 (jusqu'à 99 seulement)
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
;###########################
calculate_hp:
;# Calculates a pokémon's HP based on
;# .. its level and base HP stat
;# input:
;# - hl	= base stat pointer (1-255)
;# - a	= level (1-100)
;# output:
;# - hl = int(hl*a/50+a+e)
;#	(e = 10 for HP, 5 for all other stats)
;###########################
	ld e,10						; amount to add at the end
	jr calculate_stats_start
calculate_stats:
; output : hl = int(hl*a/50+a+5)
	ld e,5						; amount to add at the end
calculate_stats_start:
	push af
	push de
		ld e,(hl)
		call mult_a_e			; hl=a*e -- (2*LVL)*BASE
		ld c,50
		call div_hl_c			; hl=hl/c -- (2*LVL*BASE)/100
	pop de
	pop af
	add a,e
	ld c,a						; div_hl_c ends with a djnz, so b=0
	add hl,bc
	ret

;###########################
calculate_next_level:
;# Calculates experience needed until
;# .. reaching next level
;# input:
;# - e	= exp growth rate (0-3)
;# - a	= level (1-100)
;# output:
;# - hl = experience remaining til next level
;###########################
	ld hl,calculate_slow_experience
	dec e
	 jr nz,$+5
		ld hl,calculate_medslow_experience
	dec e
	 jr nz,$+5
		ld hl,calculate_medfast_experience
	dec e
	 jr nz,$+5
		ld hl,calculate_fast_experience

	inc a						; check next level
	call jp_hl					; ehl = next level's base experience (we toss out the MSB)
	ld bc,(current_pokemon+CP_EXPTOT)
	or a
	sbc hl,bc					; subtract current level from next level (and the exp we currently have)
	ret

;a = level
;returns EHL = experience
calculate_slow_experience:
	push af
		ld e,a
		ld d,0
		call mult_de_a	; AHL = a² (but here it won't overflow into 24 bits)
	pop af
	ex de,hl
	call mult_de_a		; AHL = a³ (here it might overflow into A)
	ld d,a
	ld e,5
	call mult_dhl_e		; AHL = A³*5
	ld e,a
	ld d,4
	call div_ehl_d		; EHL = (A³*5)/4
	ret

;a = level
;returns EHL = experience (A³*6/5-15*A²+100*A-140)
calculate_medslow_experience:
	push af
		push af				; level
			ld e,a
			ld d,0
			call mult_de_a	; AHL = A² (but here it won't overflow into 24 bits)
		pop af				; level
		push hl				; HL = A²
			ex de,hl
			call mult_de_a	; AHL = A³ (here it might overflow into A)
			ld d,a
			ld e,6
			call mult_dhl_e	; AHL = A³*6
			ld e,a
			ld d,5
			call div_ehl_d	; EHL = (A³*6)/5
		pop bc				; BC = A²
		push hl
		push de				; save EHL
			ld e,c
			ld d,b
			ld a,15
			call mult_de_a	; AHL = A²*15
			ex de,hl
		pop bc
		pop hl
		sbc hl,de
		ld e,a
		ld a,c
		sbc a,e
		ld de,140			;
		sbc hl,de
		sbc a,0
	pop de					; d = level
	push af
	push hl
		ld a,100
		ld e,d
		call mult_a_e
	pop de
	pop af
	add hl,de
	adc a,0
	ld e,a
	ret

;a = level
;returns EHL = experience
calculate_medfast_experience:
	push af
		ld e,a
		ld d,0
		call mult_de_a	; AHL = a² (but here it won't overflow into 24 bits)
	pop af
	ex de,hl
	call mult_de_a		; AHL = a³ (here it might overflow into A)
	ret

;a = level
;returns EHL = experience
calculate_fast_experience:
	push af
		ld e,a
		ld d,0
		call mult_de_a	; AHL = a² (but here it won't overflow into 24 bits)
	pop af
	ex de,hl
	call mult_de_a		; AHL = a³ (here it might overflow into A)
	ld d,a
	ld e,4
	call mult_dhl_e		; AHL = A³*4
	ld e,a
	ld d,5
	call div_ehl_d		; EHL = (A³*4)/5
	ret

calculate_experience:	; output : a=experience de base du pokémon vaincu*niveau du pokémon vaincu/7/c
	push bc
	push hl
	inc hl
	ld l,(hl)
	ld h,0
	bcall(_setxxxxop2)
	bcall(_op2toop1)	; on récupère le niveau du pokémon vaincu et on le met dans op1
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
	bcall(_int)			; je me demande si c'est utile
	bcall(_convop1)
	ret

calculate_next_experience:	; input : none; output : de=XPmax
	ld hl,(battle_current_player_pokemon_address)
	push hl
	ld a,(hl)
	call find_pokemon_data
	ld e,POKE_GROWTH
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
; ******************** this all needs to be changed *********************
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
	call div_hl_c
	jr calculate_next_experience_end

calculate_next_experience_medium_slow_curve:	; exp=6*lvl^2
	ld bc,6

calculate_next_experience_pre_end2:
	call de_times_bc

calculate_next_experience_end:
	ld d,h
	ld e,l
	ret

;################# MULTIPLICATION, DIVISION, ETC. #################

;####### 24 bit
div_ehl_d:		; returns EHL, a = remainder
	xor a
	ld b,24		; 24 bits to check
div_ehl_d_loop
	add hl,hl	; shift EHL left
	rl e
	rla			; shift carry into a
	cp d		; repeat until a >= divisor
	 jr c,$+4
		sub d
		inc l	; add one to EHL since we were able to subtract
	djnz div_ehl_d_loop
	ret

; stores result in AHL
mult_dhl_e:
	ld a,e
	exx
		ld e,a
		ld hl,0
		ld d,h
	exx
	ld b,24
mult_dhl_loop:
	exx
		add hl,hl
	exx
	rla
	add hl,hl
	rl d
	 jr nc,$+5
		exx
			add hl,de
		exx
	djnz mult_dhl_loop
	exx
	ret

; stores result in AHL
mult_de_a
	ld hl,0
	ld b,8
mul_loop_a:
	add hl,hl
	rla
	 jr nc,$+5
		add hl,de
		adc a,0
	djnz mul_loop_a
	ret

;####### 16 bit

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

div_hl_c:
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

mult_hl_b:
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

; From CoBB's z80 guide
mult_a_e:
	ld h,a
mult_h_e:						; this routine performs the operation HL=H*E
	ld d,0						; clearing D and L
	ld l,d
	ld b,8						; we have 8 bits
mult_h_e_loop:
	add hl,hl					; advancing a bit
	 jr nc,mult_h_e_skip		; if zero, we skip the addition
	add hl,de					; adding to the product if necessary
mult_h_e_skip:
	djnz mult_h_e_loop
	ret
