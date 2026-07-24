	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08094fe0
FUN_08094fe0: @ 0x08094FE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _0809500C
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08095008 @ =0x000007FF
	cmp r1, r0
	bgt _0809500C
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _0809500E
	.align 2, 0
_08095008: .4byte 0x000007FF
_0809500C:
	movs r0, #0
_0809500E:
	pop {r4}
	pop {r1}
	bx r1
