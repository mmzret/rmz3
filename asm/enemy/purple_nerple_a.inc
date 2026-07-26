	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08075aa8
FUN_08075aa8: @ 0x08075AA8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r1, r1, r5
	bl FUN_0800a40c
	adds r2, r0, #0
	cmp r2, #0
	beq _08075B12
	cmp r2, #0
	bge _08075AF0
	ldr r0, [r4, #0x54]
	adds r1, r0, #0
	subs r1, #0x80
	str r1, [r4, #0x54]
	ldr r1, _08075AEC @ =0xFFFFFD80
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	rsbs r1, r1, #0
	lsrs r6, r1, #0x1f
	b _08075B2C
	.align 2, 0
_08075AEC: .4byte 0xFFFFFD80
_08075AF0:
	ldr r1, [r4, #0x54]
	adds r0, r1, #0
	adds r0, #0x80
	str r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq _08075B2C
	b _08075B68
_08075B12:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq _08075B2C
	movs r6, #1
_08075B2C:
	cmp r6, #0
	bne _08075B68
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08075B6E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r3, [r4, #0x58]
	subs r2, r2, r3
	ldr r0, _08075B60 @ =0x000003FF
	adds r1, r2, r0
	ldr r0, _08075B64 @ =0x000007FE
	cmp r1, r0
	bhi _08075B6E
	adds r0, r3, r2
	b _08075B6C
	.align 2, 0
_08075B60: .4byte 0x000003FF
_08075B64: .4byte 0x000007FE
_08075B68:
	ldr r0, [r4, #0x58]
	adds r0, #0x80
_08075B6C:
	str r0, [r4, #0x58]
_08075B6E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
