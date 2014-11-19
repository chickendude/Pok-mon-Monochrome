tiles:
#include "tiles/tiles.bmp"

passable_tiles:	; tiles you can walk on
	.db 0,2,4,27,56,57,58,59,60,61,62,63,64,65
passable_tiles_end:

event_tiles:
	.db 3	\	.dw event_grass
	.db 19	\	.dw event_cliff_down
	.db 20	\	.dw event_cliff_left
	.db 21	\	.dw event_cliff_right
	.db 27	\	.dw event_door
event_block_tiles_end:


event_tiles_end:
