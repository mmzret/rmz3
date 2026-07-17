	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08060114
FUN_08060114: @ 0x08060114
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08060160 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	ldr r0, _08060164 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08060168 @ =0xFFFFD000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08060864
	movs r0, #0
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080607a0
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0xfe
	bl PlaySound
	adds r0, r4, #0
	bl FUN_0805ecc8
	movs r0, #0xc
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_0806016c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08060160: .4byte pZero2
_08060164: .4byte gStageRun+232
_08060168: .4byte 0xFFFFD000

