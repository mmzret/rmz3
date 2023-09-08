.ifndef GUARD_MACROS_M4A_INC
.set GUARD_MACROS_M4A_INC, 1

	.macro song label, music_player, unknown
	.4byte \label
	.2byte \music_player
	.2byte \unknown
	.endm

	.macro music_player info_struct, track_struct, length, unknown_2
	.4byte \info_struct
	.4byte \track_struct
	.byte \length
	.space 1
	.2byte \unknown_2
	.endm

.endif
