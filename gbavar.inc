;-----------------------------------------------------------------------------;
;-------------------| this is part of 			|-----------------------------;
;-------------------| GBAlib v2.0				|-----------------------------;
;-------------------| published in January 2009	|-----------------------------;
;-------------------| by Martin BOUSQUET		|-----------------------------;
;-------------------| martin.bousquet@hotmail.fr|-----------------------------;
;-------------------| on www.ticalc.org			|-----------------------------;
;-----------------------------------------------------------------------------;


;-------------------------------------------------------------------------;
;--------------------| GBA USER'S CONSTANTS |-----------------------------;
;-------------------------------------------------------------------------;

backBuffer		= saferam1			; can we get rid of one of these?
frontBuffer		= graph_mem			; ... ?
screenHeight	= 8
screenWidth		= 12
screenOffsetY	= 0
screenOffsetX	= 0

eventEnable		= 0
eventTiles		= 0
backgroundTile		= 0



;; variables you can change
;mapAddr
;mapHeight
;mapWidth
;tileAddr
;scrollY
;scrollX

;useful routines
; gbaInitMap
; gbaRestoreMap
; gbaScrollLeft
; gbaScrollRight
; gbaScrollUp
; gbaScrollDown
; 
