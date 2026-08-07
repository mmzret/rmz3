	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b9530
FUN_080b9530: @ 0x080B9530
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bls _080B9554
	ldr r1, _080B9550 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080B9636
	.align 2, 0
_080B9550: .4byte gVFXFnTable
_080B9554:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080B957C
	cmp r5, #1
	bgt _080B9564
	cmp r5, #0
	beq _080B956A
	b _080B9636
_080B9564:
	cmp r5, #2
	beq _080B961C
	b _080B9636
_080B956A:
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B957C:
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x78]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x13]
	adds r0, r1, #1
	strb r0, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	beq _080B95A6
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B95AC
_080B95A6:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B95AC:
	strb r0, [r4, #0xa]
	adds r0, r3, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B95E0
	ldr r0, _080B9618 @ =gWhitePaintFlags
	ldrb r1, [r3, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080B95E0
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080B95E8
_080B95E0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080B95E8:
	ldr r0, [r3, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B95FC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080B95FC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080B9636
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080B9634
	.align 2, 0
_080B9618: .4byte gWhitePaintFlags
_080B961C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r2, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080B9636
	movs r0, #1
_080B9634:
	strb r0, [r4, #0xe]
_080B9636:
	pop {r4, r5}
	pop {r0}
	bx r0

