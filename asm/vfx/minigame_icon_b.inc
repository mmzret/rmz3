	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c843c
FUN_080c843c: @ 0x080C843C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C844C
	cmp r0, #1
	beq _080C847A
	b _080C8480
_080C844C:
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	movs r0, #0xa0
	lsls r0, r0, #8
	str r0, [r4, #0x58]
	movs r1, #0xf4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C847A:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080C8480:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c8488
FUN_080c8488: @ 0x080C8488
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bls _080C8494
	b _080C861C
_080C8494:
	lsls r0, r0, #2
	ldr r1, _080C84A0 @ =_080C84A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C84A0: .4byte _080C84A4
_080C84A4: @ jump table
	.4byte _080C84B8 @ case 0
	.4byte _080C8546 @ case 1
	.4byte _080C855C @ case 2
	.4byte _080C8594 @ case 3
	.4byte _080C85E0 @ case 4
_080C84B8:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0
	strb r0, [r1]
	adds r1, #0x2c
	movs r4, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x74
	strb r4, [r0]
	movs r2, #0xf0
	lsls r2, r2, #8
	str r2, [r5, #0x54]
	movs r3, #0xa0
	lsls r3, r3, #8
	str r3, [r5, #0x58]
	ldrb r1, [r5, #0x11]
	cmp r1, #0
	bne _080C8508
	movs r0, #0x88
	lsls r0, r0, #9
	str r0, [r5, #0x54]
	movs r0, #0xa8
	lsls r0, r0, #8
	str r0, [r5, #0x58]
	strb r4, [r5, #0x13]
	b _080C852A
_080C8508:
	cmp r1, #1
	bne _080C8514
	movs r0, #0x80
	lsls r0, r0, #4
	adds r0, r2, r0
	b _080C851E
_080C8514:
	cmp r1, #2
	bne _080C852A
	movs r4, #0xe0
	lsls r4, r4, #6
	adds r0, r2, r4
_080C851E:
	str r0, [r5, #0x54]
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r0, r3, r0
	str r0, [r5, #0x58]
	strb r1, [r5, #0x13]
_080C852A:
	ldr r1, _080C8558 @ =0x0836F998
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C8546:
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C858C
	movs r0, #5
	strb r0, [r5, #0x12]
	b _080C8586
	.align 2, 0
_080C8558: .4byte 0x0836F998
_080C855C:
	ldr r0, [r5, #0x60]
	subs r0, #0x33
	str r0, [r5, #0x60]
	cmp r0, #0
	bge _080C856A
	movs r0, #0
	str r0, [r5, #0x60]
_080C856A:
	ldr r0, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080C8582
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C858C
_080C8582:
	movs r0, #0
	strh r0, [r1]
_080C8586:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C858C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _080C861C
_080C8594:
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #1
	bne _080C85AC
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080C85A8
	subs r0, #1
	b _080C85B8
_080C85A8:
	movs r0, #2
	b _080C85B8
_080C85AC:
	ldrb r0, [r5, #0x13]
	cmp r0, #1
	bhi _080C85B6
	adds r0, #1
	b _080C85B8
_080C85B6:
	movs r0, #0
_080C85B8:
	strb r0, [r5, #0x13]
	ldr r4, _080C8624 @ =0x0836F998
	ldrb r0, [r5, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	str r0, [r5, #0x60]
	movs r0, #5
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C85E0:
	ldr r0, [r5, #0x60]
	adds r0, #0x33
	str r0, [r5, #0x60]
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r0, r4
	ble _080C85F0
	str r4, [r5, #0x60]
_080C85F0:
	ldr r0, [r5, #0x60]
	adds r6, r5, #0
	adds r6, #0x50
	strh r0, [r6]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080C860E
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C861C
_080C860E:
	adds r0, r5, #0
	adds r0, #0x74
	movs r1, #0
	strb r1, [r0]
	strh r4, [r6]
	movs r0, #1
	strb r0, [r5, #0xe]
_080C861C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C8624: .4byte 0x0836F998

	thumb_func_start FUN_080c8628
FUN_080c8628: @ 0x080C8628
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C8638
	cmp r0, #1
	beq _080C8658
	b _080C867A
_080C8638:
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #9
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C8658:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080C867A
	ldr r1, _080C8680 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C867A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C8680: .4byte gVFXFnTable

	thumb_func_start FUN_080c8684
FUN_080c8684: @ 0x080C8684
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C8694
	cmp r0, #1
	beq _080C86D2
	b _080C8732
_080C8694:
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080C86B6
	adds r0, r4, #0
	movs r1, #8
	bl SetMotion
	b _080C86BE
_080C86B6:
	adds r0, r4, #0
	movs r1, #0x12
	bl SetMotion
_080C86BE:
	adds r0, r4, #0
	movs r1, #0xe
	bl _ForceEntityPalette
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C86D2:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x58]
	ldr r1, _080C8738 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5a
	bls _080C86F6
	movs r0, #0x5a
	strb r0, [r4, #0x12]
_080C86F6:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x24
	bls _080C870E
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080C870E
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	movs r1, #0xf
	bl _ForceEntityPalette
_080C870E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _080C873C @ =gJoypad
	ldrh r1, [r0]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080C8732
	ldr r1, _080C8740 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C8732:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C8738: .4byte 0xFFFFF000
_080C873C: .4byte gJoypad
_080C8740: .4byte gVFXFnTable

	thumb_func_start FUN_080c8744
FUN_080c8744: @ 0x080C8744
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080C87A6
	cmp r0, #1
	bgt _080C8758
	cmp r0, #0
	beq _080C8762
	b _080C8826
_080C8758:
	cmp r0, #2
	beq _080C8810
	cmp r0, #3
	beq _080C8814
	b _080C8826
_080C8762:
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080C8780
	movs r1, #0x9e
	lsls r1, r1, #8
	b _080C8788
_080C8780:
	cmp r0, #2
	bne _080C8790
	movs r1, #0x9f
	lsls r1, r1, #8
_080C8788:
	adds r0, r4, #0
	bl SetMotion
	b _080C879A
_080C8790:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
_080C879A:
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C87A6:
	ldr r6, [r4, #0x74]
	ldrb r0, [r4, #0x11]
	adds r5, r4, #0
	adds r5, #0x7c
	cmp r0, #3
	bne _080C87E8
	ldr r2, [r4, #0x2c]
	ldr r0, _080C8800 @ =0x00000DC4
	adds r2, r2, r0
	ldrb r0, [r5]
	lsls r0, r0, #0xc
	ldr r1, _080C8804 @ =0xFFFF9800
	adds r0, r0, r1
	ldr r1, [r2]
	subs r1, r1, r0
	ldr r3, _080C8808 @ =0xFFFFF800
	adds r0, r1, r3
	str r0, [r4, #0x54]
	ldr r0, [r2, #4]
	movs r2, #0xe0
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x28]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r0, #1
	bne _080C87E8
	ldr r3, _080C880C @ =0xFFFFF600
	adds r0, r1, r3
	ldr r1, [r2, #0x34]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_080C87E8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r5]
	ldrb r6, [r6]
	cmp r0, r6
	blo _080C8826
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080C8826
	.align 2, 0
_080C8800: .4byte 0x00000DC4
_080C8804: .4byte 0xFFFF9800
_080C8808: .4byte 0xFFFFF800
_080C880C: .4byte 0xFFFFF600
_080C8810:
	movs r0, #3
	strb r0, [r4, #0xe]
_080C8814:
	ldr r1, _080C882C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C8826:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C882C: .4byte gVFXFnTable

