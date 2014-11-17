tiles:
#include "tiles/tiles.bmp"

practicable_tiles:	; practicable tiles
	.db 0,2,3,4,27,56,57,58,59,60,61,62,63,64,65

practicable_tiles_end:

event_block_tiles:
	.db 19
	.dw event_down_cliff
	.db 20
	.dw event_right_cliff
	.db 21
	.dw event_left_cliff

event_block_tiles_end:

event_tiles:
	.db 3
	.dw event_grass
	.db 27
	.dw event_door

event_tiles_end:
