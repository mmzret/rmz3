	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b36e0
FUN_080b36e0: @ 0x080B36E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080B3726
	cmp r0, #1
	bgt _080B3704
	cmp r0, #0
	beq _080B370E
	b _080B375C
_080B3704:
	cmp r0, #2
	beq _080B373C
	cmp r0, #3
	beq _080B374C
	b _080B375C
_080B370E:
	movs r1, #0xeb
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080B3726:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B375C
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _080B375A
_080B373C:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080B374C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080B375C
_080B375A:
	strb r0, [r4, #0xd]
_080B375C:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080B3772
	ldrb r0, [r4, #0x13]
	cmp r0, #0x6c
	bne _080B3772
	ldr r0, [r4, #0x74]
	ldr r1, [r4, #0x78]
	movs r2, #0
	bl CreateFirework
_080B3772:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B3790
	ldr r1, _080B3798 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B3790:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B3798: .4byte gVFXFnTable
