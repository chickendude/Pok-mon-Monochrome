;-----------------------------------------------------------------------------;
;-------------------| this is part of 		|-----------------------------;
;-------------------| GBAlib v2.0		|-----------------------------;
;-------------------| published in January 2009	|-----------------------------;
;-------------------| by Martin BOUSQUET	|-----------------------------;
;-------------------| martin.bousquet@hotmail.fr|-----------------------------;
;-------------------| on www.ticalc.org		|-----------------------------;
;-----------------------------------------------------------------------------;

backOrigin		= backBuffer+screenOffsetX+(12*screenOffsetY)
frontOrigin		= frontBuffer+screenOffsetX+(12*screenOffsetY)

;-------------------------------------------------------------------------;
;-------------------| GBA TILE MAP ROUTINES |-----------------------------;
;-------------------------------------------------------------------------;

gbaInitMap:
	ld hl,(mapAddr)
	ld de,(scrollX)
	add hl,de
	ld de,(scrollY)
	ld a,(mapWidth)
	call hl_plus_axde
	; xor a
	ld (offsetX2),a
	ld (offsetY),a
	ld (offsetX),a
#if eventEnable != 0
	ld (locX),a
#endif
	set 7,a
	ld (offsetX),a
	ld de,backOrigin
	ld b,screenWidth
gbaInitMap_row:
	ld c,screenHeight
	push de
	push hl
#if eventEnable != 0
	xor a
	ld (locY),a
#endif
gbaInitMap_col:
	push bc
	push hl
	call findTile
	ld a,8
draw8x8:
	ld b,(hl)
	inc hl
	ex de,hl
	ld (hl),b
	ld bc,12
	add hl,bc
	ex de,hl
	dec a
	jr nz,draw8x8
#if eventEnable != 0
	ld a,$00
locY = $-1
	add a,8
	ld (locY),a
#endif
	pop hl
	ld bc,(mapWidth)
	add hl,bc
	pop bc
	dec c
	jr nz,gbaInitMap_col
#if eventEnable != 0
	ld a,$00
locX = $-1
	add a,8
	ld (locX),a
#endif
	pop hl
	inc hl
	pop de
	inc de
	djnz gbaInitMap_row
	ret



;-------------------------
; GBA HORIZONTAL SCROLLS |
;-------------------------


gbaScrollRight:
	ld a,(mapWidth)
	ld hl,scrollX
	sub (hl)
	cp screenWidth+1
	ret c

	ld hl,backOrigin+screenWidth-1
	ld b,8*screenHeight
gbaScrollRight_loop:
	sla (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	rl (hl) \ dec hl
	ld de,screenWidth+12
	add hl,de
	djnz gbaScrollRight_loop

#if eventEnable != 0
	ld a,screenWidth*8-1
	ld (locX),a
	ld a,(offsetY)
	neg
	ld (locY),a
#endif


	ld a,%00000001
	ld (pixelMask),a
	ld de,backOrigin+screenWidth-1
	ld hl,(mapAddr)
	ld bc,screenWidth
	add hl,bc
	call gbaScrollHorizontal
	ld a,$00
offsetX2 = $-1
	inc a
	and %111
	ld (offsetX2),a
	ld a,$00
offsetX = $-1
	srl a
	ld (offsetX),a
	ret nc
	ld a,%10000000
	ld (offsetX),a
	ld hl,scrollX
	inc (hl)
	or a
	ret



gbaScrollLeft:
	ld a,(offsetX)
	cp %10000000
	jr nz,gbaScrollLeft_ok
	ld a,(scrollX)
	sub 1
	ret c
gbaScrollLeft_ok:
	ld a,(offsetX2)
	dec a
	and %111
	ld (offsetX2),a
	ld a,(offsetX)
	add a,a
	jr nc,gbaScrollLeft_next
	ld a,%00000001
	ld hl,scrollX
	dec (hl)
gbaScrollLeft_next:
	ld (offsetX),a
	ld hl,backOrigin
	ld b,8*screenHeight
gbaScrollLeft_loop:
	srl (hl) \ inc hl
#if screenWidth > 1
	rr (hl) \ inc hl
#if screenWidth > 2
	rr (hl) \ inc hl
#if screenWidth > 3
	rr (hl) \ inc hl
#if screenWidth > 4
	rr (hl) \ inc hl
#if screenWidth > 5
	rr (hl) \ inc hl
#if screenWidth > 6
	rr (hl) \ inc hl
#if screenWidth > 7
	rr (hl) \ inc hl
#if screenWidth > 8
	rr (hl) \ inc hl
#if screenWidth > 9
	rr (hl) \ inc hl
#if screenWidth > 10
	rr (hl) \ inc hl
#if screenWidth > 11
	rr (hl) \ inc hl
#endif \ #endif \ #endif \ #endif
#endif \ #endif \ #endif \ #endif
#endif \ #endif \ #endif


#if screenWidth < 9
	ld de,12-screenWidth
	add hl,de
#else
#if screenWidth < 12
	inc hl
#if screenWidth < 11
	inc hl
#if screenWidth < 10
	inc hl
#endif \ #endif \ #endif \ #endif
	djnz gbaScrollLeft_loop


#if eventEnable != 0
	xor a
	ld (locX),a
	ld a,(offsetY)
	neg
	ld (locY),a
#endif

	ld a,%10000000
	ld (pixelMask),a
	ld hl,(mapAddr)
	ld de,backOrigin
	call gbaScrollHorizontal
	or a
	ret

gbaScrollHorizontal:
	push de
	ld bc,(scrollX)
	add hl,bc
	ld de,(scrollY)
	ld a,(mapWidth)
	call hl_plus_axde
	pop de

	ld bc,gbaScrollHorizontal_next
	push bc
	push hl
	call findTile
	ld bc,(offsetY)
	ld b,0
	add hl,bc
	ld a,(offsetY)
	sub 8
	neg
	jr Col1xa_loop
gbaScrollHorizontal_next:
	ld b,7
gbaScrollHorizontal_loop:
	push bc
	ld a,8
	call Col1xa
	pop bc
	djnz gbaScrollHorizontal_loop
	ld a,(offsetY)
	or a
	ret z
Col1xa:
	push hl
	call findTile		;  de and a unchanged
Col1xa_loop:
	push af
	ld a,(offsetX)
	and (hl)
	ex de,hl
	jr z,Pixel_white
	ld a,$00
pixelMask = $-1
	or (hl)
	ld (hl),a
Pixel_white:
	ld bc,12
	add hl,bc
	ex de,hl
	inc hl
	pop af
	dec a
	 jr nz,Col1xa_loop
	pop hl
	ld bc,(mapWidth)
	ld b,a
	add hl,bc
	ret


gbaScrollUp:
	ld a,(offsetY)
	or a
	jr nz,gbaScrollUp_ok
	ld a,(scrollY)
	sub 1
	ret c
gbaScrollUp_ok:
	ld a,(offsetY)
	dec a
	and %111
	ld (offsetY),a
	cp 7
	jr nz,gbaScrollUp_next
	ld hl,scrollY
	dec (hl)
gbaScrollUp_next:

	ld de,backOrigin+screenWidth-1+(12*(8*screenHeight-1))
	ld hl,backOrigin+screenWidth-1+(12*(8*screenHeight-2))
#if screenWidth = 12
	ld bc,8*screenHeight*screenWidth
	lddr
#else
	ld b,8*screenHeight
gbaScrollUp_loop:
	push bc
	ld bc,screenWidth
#if screenWidth < 7
	push hl
	push de
	lddr
	pop hl
	ld bc,-12
	add hl,bc
	ex de,hl
	pop hl
	add hl,bc
#else
	lddr
	dec hl \ dec de
#if screenWidth < 11
	dec hl \ dec de
#if screenWidth < 10
	dec hl \ dec de
#if screenWidth < 9
	dec hl \ dec de
#if screenWidth < 8
	dec hl \ dec de
#endif \ #endif \ #endif \ #endif \ #endif
	pop bc
	djnz gbaScrollUp_loop
#endif


#if eventEnable != 0
	ld a,(offsetX)
	neg
	ld (locX),a
	xor a
	ld (locY),a
#endif


	ld a,(backOrigin+screenWidth)
	ld (saveByte),a
	ld hl,(mapAddr)
	ld de,backOrigin
	call gbaScrollVertical
	ld a,$00
saveByte = $-1
	ld (hl),a
	ret


gbaScrollDown:
	ld a,(mapHeight)
	ld hl,scrollY
	sub (hl)
	cp screenHeight+1
	ret c

	ld de,backOrigin
	ld hl,backOrigin+12
	ld bc,8*12*8
	ldir
#else
	ld b,8*screenHeight
gbaScrollDown_loop:
	push bc
	ld bc,screenWidth
#if screenWidth < 8
	push hl
	push de
	ldir
	pop hl
	ld bc,12
	add hl,bc
	ex de,hl
	pop hl
	add hl,bc
#else
	ldir
	inc hl \ inc de
#if screenWidth < 11
	inc hl \ inc de
#if screenWidth < 10
	inc hl \ inc de
#if screenWidth < 9
	inc hl \ inc de
#endif \ #endif \ #endif \ #endif \ 
	pop bc
	djnz gbaScrollDown_loop
#endif

#if eventEnable != 0
	ld a,(offsetX)
	neg
	ld (locX),a
	ld a,8*screenHeight-1
	ld (locY),a
#endif

	ld a,(de)
	ld (saveByte2),a
	ld hl,-12
	add hl,de
	push hl
	ld hl,(mapAddr)
	ld de,(mapWidth)
	ld a,screenHeight
	call hl_plus_axde
	pop de
	call gbaScrollVertical
	ld a,$00
saveByte2 = $-1
	ld (hl),a
	ld a,(offsetY)
	inc a
	and %111
	ld (offsetY),a
	ret nz
	ld hl,scrollY
	inc (hl)
	or a
	ret



gbaScrollVertical:
	push de
	ld de,(scrollX)
	add hl,de
	ld a,(mapWidth)
	ld de,(scrollY)
	call hl_plus_axde
	pop de
	ld b,screenWidth+1
gbaScrollVertical_loop:
	push bc
	push hl
	call findTile
	ld bc,(offsetY)
	ld b,0
	add hl,bc
	ld a,(hl)
	ld (de),a
	inc de
	pop hl
	inc hl
	pop bc
	djnz gbaScrollVertical_loop
	dec de
	ex de,hl
	ld a,(offsetX2)
	or a
	ret z
gbaScrollVertical_loop2:	
	push hl
	sla (hl) \ dec hl
	rl (hl) \ dec hl
#if screenWidth > 1
	rl (hl) \ dec hl
#if screenWidth > 2
	rl (hl) \ dec hl
#if screenWidth > 3
	rl (hl) \ dec hl
#if screenWidth > 4
	rl (hl) \ dec hl
#if screenWidth > 5
	rl (hl) \ dec hl
#if screenWidth > 6
	rl (hl) \ dec hl
#if screenWidth > 7
	rl (hl) \ dec hl
#if screenWidth > 8
	rl (hl) \ dec hl
#if screenWidth > 9
	rl (hl) \ dec hl
#if screenWidth > 10
	rl (hl) \ dec hl
#if screenWidth > 11
	rl (hl) \ dec hl
#endif \ #endif \ #endif \ #endif \ 
#endif \ #endif \ #endif \ #endif \ 
#endif \ #endif \ #endif
	pop hl
	dec a
	jr nz,gbaScrollVertical_loop2
	ret


gbaRestoreMap:
	ld hl,backOrigin
	ld de,frontOrigin
#if screenWidth = 12
	ld bc,screenWidth*8*screenHeight
	ldir
#else
	ld b,8*screenHeight	
gbaRestoreMap_loop:
	push bc
#if screenWidth < 7
	push de
	push hl
	ld bc,screenWidth
	ldir
	ld bc,12
	pop hl
	add hl,bc
	ex de,hl
	pop add hl,bc
	ex de,hl
#else
	ld bc,screenWidth
	ldir
	inc hl \ inc de
#if screenWidth < 11
	inc hl \ inc de
#if screenWidth < 10
	inc hl \ inc de
#if screenWidth < 9
	inc hl \ inc de
#if screenWidth < 8
	inc hl \ inc de
#endif \ #endif \ #endif \ #endif \ #endif
	pop bc
	djnz gbaRestoreMap_loop	
#endif
	ret

;-------------------------------------------------------------------------;
;----------------------| GBA SPRITE ROUTINES |----------------------------;
;-------------------------------------------------------------------------;


findTile:
#if eventEnable = 0
	ld l,(hl)
	ld h,0
	ld bc,(tileAddr)
	add hl,hl
	add hl,hl
	add hl,hl
	add hl,bc
	ret
#else
	push af
	ld a,(hl)
	sub eventTiles
	jr c,findTile_ok
	push de	
	call eventRoutine
	ld hl,(tileAddr)
	ld de,backgroundTile*8
	add hl,de
	pop de
	pop af
	ret

findTile_ok:
	pop af
	ld l,(hl)
	ld h,0
	ld bc,(tileAddr)
	add hl,hl
	add hl,hl
	add hl,hl
	add hl,bc
	ret
#endif


gbaDrawMaskSprite:
	push hl
	push de
	call findPixel
	pop bc
	ex de,hl
	pop hl
gbaDrawMaskSprite_col:
	push bc
	push de
gbaDrawMaskSprite_row:
	push bc
	ld b,(hl)
	ld c,%11111111
	inc hl
	push hl
	push af
	push af
	ld a,(hl)
gbaInvertedOpcode:
	nop
	nop
	ld h,a
	ld l,0
	pop af
	or a
	jr z,gbaDrawMaskSprite_next
gbaDrawMaskSprite_shift:
	scf
	rr b
	rr c
	srl h
	rr l
	dec a
	jr nz,gbaDrawMaskSprite_shift
gbaDrawMaskSprite_next:
	ex de,hl
	ld a,(hl)
	and b
	or d
	ld (hl),a
	inc hl
	ld a,(hl)
	and c
	or e
	ld (hl),a
	ex de,hl
	pop af
	pop hl
	inc hl
	pop bc
	djnz gbaDrawMaskSprite_row
	ex de,hl
	pop hl
	ld bc,12
	add hl,bc
	ex de,hl
	pop bc
	dec c
	jr nz,gbaDrawMaskSprite_col
	ret


gbaDrawInvertedSprite:
	push hl
	ld hl,gbaInvertedOpcode
	ld (hl),$2f			; opcode for 'cpl'
	inc hl
	ld (hl),$a8			; opcode for 'xor b'
	pop hl
	call gbaDrawMaskSprite
	ld hl,gbaInvertedOpcode
	ld (hl),0
	inc hl
	ld (hl),0
	ret


findPixel:
	ld hl,frontOrigin
	ld a,b
	and %111
	srl b \ srl b \ srl b
	ld d,0
	ld e,b
	add hl,de
	ld e,c
	ex de,hl
	add hl,hl
	add hl,hl
	ld b,h
	ld c,l
	add hl,hl
	add hl,bc
	add hl,de
	ret


gbaClipSprite:
	ld a,127
	cp b
	ret c
	ld a,screenWidth
	sub d
	add a,a
	add a,a
	add a,a
	sub b
	ret c

	ld a,c
	bit 7,a
	jr z,gbaClipSprite_next
	neg
	cp e
	ccf
	ret c
	add a,a
	push de
	ld e,d
	ld d,0
	call hl_plus_axde
	pop de
	or a
	ret
gbaClipSprite_next:
	ld a,screenHeight
	add a,a
	add a,a
	add a,a
	dec a
	sub c
	ret c
	inc a
	cp e
	ret nc
	ld e,a
	or a
	ret


;-------------------------------------------------------------------------;
;--------------------| GBA COLLISION ROUTINES |---------------------------;
;-------------------------------------------------------------------------;

gbaCollision:
	ld hl,(mapAddr)
	ld de,(scrollX)
	add hl,de
	ld a,(offsetX2)
	add a,b
	sra a \ sra a \ sra a
	ld e,a
	ld d,0
	bit 7,a
	jr z,gbaCollision_next
	dec d
gbaCollision_next:
	add hl,de
	ld a,(offsetY)
	add a,c
	sra a \ sra a \ sra a
	ld b,0
	ld c,a
	bit 7,a
	jr z,gbaCollision_next2
	dec b
gbaCollision_next2:
	ex de,hl
	ld hl,(scrollY)
	add hl,bc
	ex de,hl
	ld a,(mapWidth)
	call hl_plus_axde
	ld a,(hl)
	ret

;-------------------------------------------------------------------------;
;---------------------| GBA USEFUL ROUTINES |-----------------------------;
;-------------------------------------------------------------------------;


hl_plus_axde:
	ld b,8
hlplusaxde_loop:
	srl a
	jr nc,hlplusaxde_next
	add hl,de
hlplusaxde_next:
	sla e			; multiply de with 2
	rl d
	djnz hlplusaxde_loop
	ret
