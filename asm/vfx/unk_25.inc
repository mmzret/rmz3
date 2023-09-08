	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b94dc
FUN_080b94dc: @ 0x080B94DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B9504
	ldr r1, _080B9500 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080B9524
	.align 2, 0
_080B9500: .4byte gVFXFnTable
_080B9504:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B9510
	cmp r0, #1
	beq _080B951E
	b _080B9524
_080B9510:
	ldr r1, _080B952C @ =0x00000A09
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B951E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080B9524:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B952C: .4byte 0x00000A09

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
	ldr r0, _080B9618 @ =0x0202F360
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
	bl UpdateMotionGraphic
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
_080B9618: .4byte 0x0202F360
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

	thumb_func_start FUN_080b963c
FUN_080b963c: @ 0x080B963C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080B9654
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B966C
_080B9654:
	ldr r1, _080B9668 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080B9700
	.align 2, 0
_080B9668: .4byte gVFXFnTable
_080B966C:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080B9678
	cmp r5, #1
	beq _080B9688
	b _080B9700
_080B9678:
	ldr r1, _080B96B4 @ =0x00000B01
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B9688:
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
	beq _080B96B8
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B96BE
	.align 2, 0
_080B96B4: .4byte 0x00000B01
_080B96B8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B96BE:
	strb r0, [r4, #0xa]
	adds r0, r3, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B96F2
	ldr r0, _080B9708 @ =0x0202F360
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
	bne _080B96F2
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080B96FA
_080B96F2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080B96FA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080B9700:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9708: .4byte 0x0202F360

	thumb_func_start FUN_080b970c
FUN_080b970c: @ 0x080B970C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x12]
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B972E
	ldr r1, _080B9734 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_080B972E:
	pop {r0}
	bx r0
	.align 2, 0
_080B9734: .4byte gVFXFnTable

	thumb_func_start FUN_080b9738
FUN_080b9738: @ 0x080B9738
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r5, #0xff
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080B9754
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080B97E0
_080B9754:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B9760
	cmp r0, #1
	beq _080B97AA
	b _080B97E0
_080B9760:
	ldr r2, _080B97E8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B97EC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080B97F0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	bl __umodsi3
	strb r0, [r4, #0x13]
	ands r0, r5
	adds r2, r4, #0
	adds r2, #0x24
	strb r0, [r2]
	adds r3, r4, #0
	adds r3, #0x50
	movs r1, #0
	movs r0, #0x80
	strh r0, [r3]
	movs r5, #0x52
	strh r0, [r5, r4]
	strb r1, [r2]
	adds r0, #0x80
	strh r0, [r3]
	strh r0, [r5, r4]
	movs r1, #0xe0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B97AA:
	ldr r2, [r4, #0x5c]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B97CA
	str r1, [r4, #0x60]
_080B97CA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080B97E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B97E8: .4byte RNG_0202f388
_080B97EC: .4byte 0x000343FD
_080B97F0: .4byte 0x00269EC3

	thumb_func_start FUN_080b97f4
FUN_080b97f4: @ 0x080B97F4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B9804
	cmp r0, #1
	beq _080B9818
	b _080B985A
_080B9804:
	movs r1, #0xe0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B9818:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B9830
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B9836
_080B9830:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B9836:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080B985A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B985A
	ldr r1, _080B9860 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B985A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9860: .4byte gVFXFnTable
