	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08093a98
FUN_08093a98: @ 0x08093A98
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _08093AEE
	cmp r5, #0
	bge _08093AC8
	ldr r0, [r4, #0x54]
	ldr r1, _08093AC0 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AC4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #1
	b _08093AF0
	.align 2, 0
_08093AC0: .4byte 0xFFFFF200
_08093AC4: .4byte 0xFFFFF600
_08093AC8:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AE4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #2
	b _08093AF0
	.align 2, 0
_08093AE4: .4byte 0xFFFFF600
_08093AE8:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_08093AEE:
	movs r0, #0
_08093AF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

