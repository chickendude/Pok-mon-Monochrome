saferam1		=$86EC	;saveSScreen=768
saferam2		=$8A3A	;statVars=531
saferam3		=$8508	;textShadow=128
saferam4		=$8478	;OPs=66
saferam5		=$84D3	;iMathPtrs=10
saferamp		=$9872	;appBackUpScreen=768
saferamp2		=$8251	;bootTemp=52
gbuf			=$9340

; Map variables
mapAddr		= saferam3				;128 bytes
mapHeight	= saferam3+2
mapWidth	= saferam3+3
tileAddr	= saferam3+4
map_y		= saferam3+6
map_x		= saferam3+7
offsetY		= saferam3+8
player_tile	= saferam3+9			; the tile that's behind the player (8 bytes)

; Player variables
player_direction	= saferam3+20	;
walk_count			= saferam3+21	; how many pixels the player has gone (should go up to 8)
walk_anim			= saferam3+22	; current animation frame (how many total? 4?)
player_y			= saferam3+23
player_x			= saferam3+24
player_y_off		= saferam3+25
player_x_off		= saferam3+26

; Misc variables
randData			= saferam3+60	; used for Ion's random routine
contrast_var		= saferam3+61	; holds the current contrast
_v_mode				= saferam3+62	; text drawing mode
