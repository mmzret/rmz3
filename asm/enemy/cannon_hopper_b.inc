	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08098414
FUN_08098414: @ 0x08098414
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	bne _08098422
	b _08098538
_08098422:
	cmp r0, #1
	bgt _0809842C
	cmp r0, #0
	beq _08098434
	b _080985FE
_0809842C:
	cmp r0, #2
	bne _08098432
	b _080985D8
_08098432:
	b _080985FE
_08098434:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _0809846C
	cmp r0, #2
	bgt _0809844A
	cmp r0, #1
	beq _08098454
	b _080984EC
_0809844A:
	cmp r0, #3
	beq _08098484
	cmp r0, #4
	beq _080984A8
	b _080984EC
_08098454:
	ldr r5, _08098468 @ =0xFFFFEE00
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984EC
	movs r5, #0x90
	lsls r5, r5, #5
	b _080984EC
	.align 2, 0
_08098468: .4byte 0xFFFFEE00
_0809846C:
	ldr r5, _08098480 @ =0xFFFFE800
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984EC
	movs r5, #0xc0
	lsls r5, r5, #5
	b _080984EC
	.align 2, 0
_08098480: .4byte 0xFFFFE800
_08098484:
	ldr r5, _080984A4 @ =0xFFFFDD00
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08098494
	movs r5, #0x8c
	lsls r5, r5, #6
_08098494:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080984CC
	movs r0, #0x20
	orrs r0, r1
	b _080984D0
	.align 2, 0
_080984A4: .4byte 0xFFFFDD00
_080984A8:
	ldr r5, _080984C8 @ =0xFFFFD500
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984B8
	movs r5, #0xac
	lsls r5, r5, #6
_080984B8:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080984CC
	movs r0, #0x20
	orrs r0, r1
	b _080984D0
	.align 2, 0
_080984C8: .4byte 0xFFFFD500
_080984CC:
	movs r0, #0xdf
	ands r0, r1
_080984D0:
	strb r0, [r4, #0xa]
	adds r0, r2, #0
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_080984EC:
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_08097224
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809851C
	movs r2, #1
_0809851C:
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #8
	movs r0, #0xa0
	lsls r0, r0, #2
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _080985CC @ =0xFFFFFB80
	str r0, [r4, #0x60]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08098538:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _08098556
	str r0, [r4, #0x60]
_08098556:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08098576
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080985FE
_08098576:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c6e70
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080985D0 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080985D4 @ =0x0000270E
	cmp r1, r0
	bhi _080985BC
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080985BC:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080985FE
	.align 2, 0
_080985CC: .4byte 0xFFFFFB80
_080985D0: .4byte gScore
_080985D4: .4byte 0x0000270E
_080985D8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080985EC
	subs r0, #1
	strb r0, [r4, #0x12]
	b _080985FE
_080985EC:
	ldr r1, _08098608 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080985FE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098608: .4byte gEnemyFnTable

	thumb_func_start FUN_0809860c
FUN_0809860c: @ 0x0809860C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809861E
	cmp r0, #1
	bne _0809861C
	b _08098772
_0809861C:
	b _0809882C
_0809861E:
	movs r6, #0
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08098654
	cmp r0, #2
	bgt _08098634
	cmp r0, #1
	beq _0809863E
	b _080986D4
_08098634:
	cmp r0, #3
	beq _0809866C
	cmp r0, #4
	beq _08098690
	b _080986D4
_0809863E:
	ldr r6, _08098650 @ =0xFFFFEE00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986D4
	movs r6, #0x90
	lsls r6, r6, #5
	b _080986D4
	.align 2, 0
_08098650: .4byte 0xFFFFEE00
_08098654:
	ldr r6, _08098668 @ =0xFFFFE800
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986D4
	movs r6, #0xc0
	lsls r6, r6, #5
	b _080986D4
	.align 2, 0
_08098668: .4byte 0xFFFFE800
_0809866C:
	ldr r6, _0809868C @ =0xFFFFDD00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809867C
	movs r6, #0x8c
	lsls r6, r6, #6
_0809867C:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080986B4
	movs r0, #0x20
	orrs r0, r1
	b _080986B8
	.align 2, 0
_0809868C: .4byte 0xFFFFDD00
_08098690:
	ldr r6, _080986B0 @ =0xFFFFD500
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986A0
	movs r6, #0xac
	lsls r6, r6, #6
_080986A0:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080986B4
	movs r0, #0x20
	orrs r0, r1
	b _080986B8
	.align 2, 0
_080986B0: .4byte 0xFFFFD500
_080986B4:
	movs r0, #0xdf
	ands r0, r1
_080986B8:
	strb r0, [r5, #0xa]
	adds r0, r2, #0
	adds r1, r5, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_080986D4:
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_08097224
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08098758 @ =0x0836A3A8
	bl SetDDP
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _0809875C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08098760 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08098764
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0809876C
	.align 2, 0
_08098758: .4byte sCollisions+(12*24)
_0809875C: .4byte pZero2
_08098760: .4byte 0xFFFFE800
_08098764:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0809876C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08098772:
	movs r4, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _08098798
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r6, r0, #0
	cmp r6, #0
	bge _080987B0
	ldr r0, _08098794 @ =0xFFFFF800
	cmp r6, r0
	ble _080987B0
	b _080987A8
	.align 2, 0
_08098794: .4byte 0xFFFFF800
_08098798:
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r6, r0, #0
	subs r1, r6, #1
	ldr r0, _080987E4 @ =0x000007FE
	cmp r1, r0
	bhi _080987B0
_080987A8:
	movs r4, #1
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	str r0, [r5, #0x54]
_080987B0:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080987C0
	str r1, [r5, #0x60]
_080987C0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	cmp r1, #0
	ble _080987EC
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r6, #0
	bge _08098806
	ldr r0, _080987E8 @ =0xFFFFF800
	cmp r6, r0
	ble _08098806
	b _080987FE
	.align 2, 0
_080987E4: .4byte 0x000007FE
_080987E8: .4byte 0xFFFFF800
_080987EC:
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToDown1
	adds r6, r0, #0
	subs r1, r6, #1
	ldr r0, _08098834 @ =0x000007FE
	cmp r1, r0
	bhi _08098806
_080987FE:
	movs r4, #1
	ldr r0, [r5, #0x58]
	adds r0, r0, r6
	str r0, [r5, #0x58]
_08098806:
	cmp r4, #0
	bne _08098826
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08098826
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809882C
_08098826:
	adds r0, r5, #0
	bl FUN_08097f3c
_0809882C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098834: .4byte 0x000007FE
