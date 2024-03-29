@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.equ PLAYER, 0
.equ BOSS, 2
.equ SOLID, 6

.equ DIR_LEFT, 0x00
.equ DIR_RIGHT, 0x01
.equ IN_SEA, 0x100

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.equ FRAME, 1
.equ SECOND, 60

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.equ PX, 256
.equ MAX_X, 240*64*PX @ 15360*PX, 0x3C0000
.equ MAX_Y, 160*64*PX @ 10240*PX, 0x280000

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.equ A_BUTTON, 0x0001
.equ B_BUTTON, 0x0002
.equ SELECT_BUTTON, 0x0004
.equ START_BUTTON, 0x0008
.equ DPAD_RIGHT, 0x0010
.equ DPAD_LEFT, 0x0020
.equ DPAD_UP, 0x0040
.equ DPAD_DOWN, 0x0080
.equ R_BUTTON, 0x0100
.equ L_BUTTON, 0x0200
.equ KEYS_MASK, 0x03FF
.equ KEY_INTR_ENABLE, 0x0400
.equ KEY_OR_INTR, 0x0000
.equ KEY_AND_INTR, 0x8000
.equ DPAD_ANY, 0x00F0
.equ JOY_EXCL_DPAD, 0x030F

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.equ FALSE, 0
.equ TRUE, 1
