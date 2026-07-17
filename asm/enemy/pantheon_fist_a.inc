	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08094fa8
FUN_08094fa8: @ 0x08094FA8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	ldr r3, _08094FD4 @ =0xFFFFF200
	adds r0, r0, r3
	cmp r1, #0
	ble _08094FBC
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
_08094FBC:
	ldr r1, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08094FD8
	movs r0, #0
	b _08094FDA
	.align 2, 0
_08094FD4: .4byte 0xFFFFF200
_08094FD8:
	movs r0, #1
_08094FDA:
	pop {r1}
	bx r1
	.align 2, 0

