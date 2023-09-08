	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Ripple_Update
Ripple_Update: @ 0x080B54F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	bne _080B551A
	adds r0, r6, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080B5538
_080B551A:
	ldr r1, _080B5534 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ripple_Die
	b _080B564C
	.align 2, 0
_080B5534: .4byte gVFXFnTable
_080B5538:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x7c]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _080B5576
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080B5564
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _080B5564
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_080B5564:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B564C
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080B564C
_080B5576:
	ldr r0, [r6, #0x54]
	str r0, [r4, #0x54]
	ldr r1, _080B5598 @ =gOverworld
	ldr r2, _080B559C @ =0x0002C00C
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r3, r1, #0
	cmp r0, #2
	beq _080B55DA
	cmp r0, #2
	bgt _080B55A0
	cmp r0, #1
	beq _080B55AA
	b _080B5612
	.align 2, 0
_080B5598: .4byte gOverworld
_080B559C: .4byte 0x0002C00C
_080B55A0:
	cmp r0, #3
	beq _080B55F0
	cmp r0, #4
	beq _080B5604
	b _080B5612
_080B55AA:
	adds r0, r4, #0
	movs r1, #0x14
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080B55DA:
	ldr r1, [r4, #0x7c]
	ldr r0, [r4, #0x54]
	ldr r3, _080B55EC @ =gOverworld
	cmp r1, r0
	beq _080B5612
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _080B5610
	.align 2, 0
_080B55EC: .4byte gOverworld
_080B55F0:
	adds r0, r4, #0
	movs r1, #0x15
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080B5604:
	ldr r1, [r4, #0x7c]
	ldr r0, [r4, #0x54]
	ldr r3, _080B5654 @ =gOverworld
	cmp r1, r0
	bne _080B5612
	movs r0, #1
_080B5610:
	strb r0, [r4, #0xd]
_080B5612:
	ldr r1, _080B5658 @ =gZeroRanges
	ldr r5, _080B565C @ =0x00000147
	adds r0, r6, r5
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #6
	ldrsh r1, [r0, r2]
	ldr r2, [r6, #0x58]
	subs r1, r2, r1
	ldr r5, _080B5660 @ =0x0002C00C
	adds r0, r3, r5
	ldr r0, [r0]
	cmp r1, r0
	bgt _080B5634
	cmp r2, r0
	bge _080B564C
_080B5634:
	ldr r1, _080B5664 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ripple_Die
_080B564C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B5654: .4byte gOverworld
_080B5658: .4byte gZeroRanges
_080B565C: .4byte 0x00000147
_080B5660: .4byte 0x0002C00C
_080B5664: .4byte gVFXFnTable

	thumb_func_start Ripple_Die
Ripple_Die: @ 0x080B5668
	push {r4, lr}
	ldr r3, [r0, #0x28]
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	movs r2, #0
	strb r1, [r0, #0xa]
	ldr r4, _080B5694 @ =0x0000011B
	adds r1, r3, r4
	strb r2, [r1]
	ldr r2, _080B5698 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B5694: .4byte 0x0000011B
_080B5698: .4byte gVFXFnTable

	thumb_func_start Ripple_Disappear
Ripple_Disappear: @ 0x080B569C
	push {lr}
	ldr r1, [r0, #0x28]
	ldr r3, _080B56B0 @ =0x0000011B
	adds r2, r1, r3
	movs r1, #0
	strb r1, [r2]
	bl DeleteVFX
	pop {r0}
	bx r0
	.align 2, 0
_080B56B0: .4byte 0x0000011B
