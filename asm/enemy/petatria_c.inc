	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080902c8
FUN_080902c8: @ 0x080902C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x17
	bls _080902D4
	b _080906E0
_080902D4:
	lsls r0, r0, #2
	ldr r1, _080902E0 @ =_080902E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080902E0: .4byte _080902E4
_080902E4: @ jump table
	.4byte _08090344 @ case 0
	.4byte _0809039A @ case 1
	.4byte _080903AE @ case 2
	.4byte _08090490 @ case 3
	.4byte _080904D8 @ case 4
	.4byte _0809051C @ case 5
	.4byte _080906E0 @ case 6
	.4byte _080906E0 @ case 7
	.4byte _080906E0 @ case 8
	.4byte _080906E0 @ case 9
	.4byte _080906E0 @ case 10
	.4byte _080906E0 @ case 11
	.4byte _080906E0 @ case 12
	.4byte _080906E0 @ case 13
	.4byte _080906E0 @ case 14
	.4byte _080906E0 @ case 15
	.4byte _080906E0 @ case 16
	.4byte _080906E0 @ case 17
	.4byte _080906E0 @ case 18
	.4byte _080906E0 @ case 19
	.4byte _08090548 @ case 20
	.4byte _0809062C @ case 21
	.4byte _0809068C @ case 22
	.4byte _080906BC @ case 23
_08090344:
	movs r4, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080903A4 @ =0x08369608
	bl SetDDP
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	movs r1, #0xfc
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809039A:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080903A8
	movs r0, #2
	b _080903AA
	.align 2, 0
_080903A4: .4byte sCollisions
_080903A8:
	movs r0, #0x14
_080903AA:
	strb r0, [r5, #0xe]
	b _08090680
_080903AE:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r4, r5, #0
	adds r4, #0xb9
	cmp r0, #3
	bne _080903F4
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080903D4
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #0
	strb r0, [r5, #0x13]
_080903D4:
	ldr r1, _08090478 @ =0x0836978C
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x64]
	ldr r1, _0809047C @ =0x08369768
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_080903F4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x64]
	str r0, [r5, #0x54]
	ldrb r0, [r4]
	cmp r0, #3
	bls _08090432
	movs r6, #0
	strb r6, [r4]
	ldr r3, _08090480 @ =0x08369728
	ldr r2, _08090484 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090488 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809048C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08090432
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
_08090432:
	ldrb r0, [r5, #0xd]
	cmp r0, #2
	bne _0809043A
	b _080906E0
_0809043A:
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809045A
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809045A:
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r1, r0
	bne _08090472
	b _080906E0
_08090472:
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _08090604
	.align 2, 0
_08090478: .4byte 0x0836978C
_0809047C: .4byte sMotions1
_08090480: .4byte s32_ARRAY_08369728
_08090484: .4byte RNG_0202f388
_08090488: .4byte 0x000343FD
_0809048C: .4byte 0x00269EC3
_08090490:
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r2, _080904D0 @ =0xFFFF8200
	adds r0, r1, r2
	cmp r0, #1
	bhi _080904A6
	b _08090646
_080904A6:
	ldr r0, _080904D4 @ =0x00007E05
	cmp r1, r0
	bne _080904AE
	b _08090646
_080904AE:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080904BA
	b _08090680
_080904BA:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi _080904CA
	b _08090670
_080904CA:
	movs r0, #0
	b _0809066E
	.align 2, 0
_080904D0: .4byte 0xFFFF8200
_080904D4: .4byte 0x00007E05
_080904D8:
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r1, _08090544 @ =0x00007E0C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809051C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0809052E
	b _080906E0
_0809052E:
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xcc
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	strb r1, [r5, #0xd]
	strb r2, [r5, #0xe]
	b _080906E0
	.align 2, 0
_08090544: .4byte 0x00007E0C
_08090548:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r4, r5, #0
	adds r4, #0xb9
	cmp r0, #3
	bne _0809058A
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08090560
	subs r0, #1
	b _08090568
_08090560:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #5
_08090568:
	strb r0, [r5, #0x13]
	ldr r1, _0809060C @ =0x08369774
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r5, #0x64]
	ldr r1, _08090610 @ =0x08369768
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_0809058A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x64]
	str r0, [r5, #0x54]
	ldrb r0, [r4]
	cmp r0, #3
	bls _080905C8
	movs r6, #0
	strb r6, [r4]
	ldr r3, _08090614 @ =0x08369728
	ldr r2, _08090618 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809061C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08090620 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080905C8
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
_080905C8:
	ldrb r0, [r5, #0xd]
	cmp r0, #2
	bne _080905D0
	b _080906E0
_080905D0:
	ldr r0, [r5, #0x54]
	ldr r2, _08090624 @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _080905EE
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080905EE:
	ldr r0, [r5, #0x54]
	ldr r1, _08090628 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r1, r0
	beq _080906E0
	movs r0, #0xcc
_08090604:
	str r0, [r5, #0x5c]
	movs r0, #1
	strb r0, [r5, #0xe]
	b _080906E0
	.align 2, 0
_0809060C: .4byte 0x08369774
_08090610: .4byte sMotions1
_08090614: .4byte s32_ARRAY_08369728
_08090618: .4byte RNG_0202f388
_0809061C: .4byte 0x000343FD
_08090620: .4byte 0x00269EC3
_08090624: .4byte 0xFFFFE000
_08090628: .4byte 0xFFFFF000
_0809062C:
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r2, _08090650 @ =0xFFFF8200
	adds r0, r1, r2
	cmp r0, #1
	bls _08090646
	ldr r0, _08090654 @ =0x00007E05
	cmp r1, r0
	bne _08090658
_08090646:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080906E0
	.align 2, 0
_08090650: .4byte 0xFFFF8200
_08090654: .4byte 0x00007E05
_08090658:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090680
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0809066C
	subs r0, #1
	b _0809066E
_0809066C:
	movs r0, #5
_0809066E:
	strb r0, [r5, #0x13]
_08090670:
	ldr r0, _08090688 @ =0x08369768
	ldrb r1, [r5, #0x13]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r5, #0
	bl SetMotion
_08090680:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _080906E0
	.align 2, 0
_08090688: .4byte sMotions1
_0809068C:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r1, _080906E8 @ =0x00007E0C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080906BC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080906E0
	adds r0, r5, #0
	adds r0, #0xb8
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xcc
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080906E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080906E8: .4byte 0x00007E0C

