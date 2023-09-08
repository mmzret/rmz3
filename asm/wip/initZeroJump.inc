	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xf]
	cmp r0, #4
	bls _0802A8C4
	b _0802AB82
_0802A8C4:
	lsls r0, r0, #2
	ldr r1, _0802A8D0 @ =_0802A8D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A8D0: .4byte _0802A8D4
_0802A8D4: @ jump table
	.4byte _0802A8E8 @ case 0
	.4byte _0802A928 @ case 1
	.4byte _0802A97E @ case 2
	.4byte _0802AAC4 @ case 3
	.4byte _0802AB34 @ case 4
_0802A8E8:
	ldr r1, _0802A924 @ =0x00000403
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl getZeroJumpingPower
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	ldr r4, [r5, #0x5c]
	cmp r4, #0
	bge _0802A906
	rsbs r4, r4, #0
_0802A906:
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	blt _0802A916
	b _0802AB28
_0802A916:
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r5, #0x5c]
	b _0802AB28
	.align 2, 0
_0802A924: .4byte 0x00000403
_0802A928:
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl getZeroRisingDy
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r1, #0x54]
	cmp r0, #0
	beq _0802A95A
	movs r0, #0
	str r0, [r1, #0x54]
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r5, #0x5c]
_0802A95A:
	ldr r4, [r5, #0x5c]
	cmp r4, #0
	bge _0802A962
	rsbs r4, r4, #0
_0802A962:
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	blt _0802A972
	b _0802AB82
_0802A972:
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _0802AB80
_0802A97E:
	adds r0, r5, #0
	adds r0, #0x54
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	movs r7, #1
	ands r1, r7
	bl FUN_080b388c
	movs r1, #0x86
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0802AA68
	ldr r1, _0802AA00 @ =0x00000601
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0xa]
	movs r6, #0x10
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0802AA08
	ldr r0, [r4]
	ands r0, r2
	cmp r0, #0
	beq _0802A9D6
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToLeft2
	ldr r1, [r5, #0x54]
	ldr r2, _0802AA04 @ =0xFFFFF900
	adds r1, r1, r2
	adds r1, r1, r0
	str r1, [r5, #0x54]
_0802A9D6:
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	b _0802AA4C
	.align 2, 0
_0802AA00: .4byte 0x00000601
_0802AA04: .4byte 0xFFFFF900
_0802AA08:
	ldr r0, [r4]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802AA2C
	ldr r0, [r5, #0x54]
	ldr r1, _0802AA64 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToRight2
	ldr r1, [r5, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r1, r1, r2
	adds r1, r1, r0
	str r1, [r5, #0x54]
_0802AA2C:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r1, r5, #0
	adds r1, #0x4a
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	ldrb r0, [r5, #0xa]
	orrs r0, r6
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_0802AA4C:
	str r0, [r5, #0x5c]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r0, #0x40]
	adds r6, r0, #0
	cmp r1, #0
	bne _0802AA9C
	adds r0, r5, #0
	bl CreateAfterImages
	str r0, [r6, #0x40]
	b _0802AA9C
	.align 2, 0
_0802AA64: .4byte 0xFFFFF000
_0802AA68:
	ldr r1, _0802AA88 @ =0x00000501
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802AA8C
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	b _0802AA96
	.align 2, 0
_0802AA88: .4byte 0x00000501
_0802AA8C:
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_0802AA96:
	str r0, [r5, #0x5c]
	adds r6, r5, #0
	adds r6, #0xb4
_0802AA9C:
	ldr r0, _0802AAC0 @ =0x00000111
	adds r1, r5, r0
	movs r4, #0
	movs r0, #7
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08032bac
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	str r4, [r6, #0x54]
	movs r0, #0xc
	bl PlaySound
	b _0802AB82
	.align 2, 0
_0802AAC0: .4byte 0x00000111
_0802AAC4:
	adds r0, r5, #0
	bl GetRodJumpPower
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	adds r6, r5, #0
	adds r6, #0xb4
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r5, #0x5c]
	adds r4, r0, #0
	cmp r4, #0
	bge _0802AAEA
	rsbs r4, r4, #0
_0802AAEA:
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bge _0802AB04
	adds r0, r5, #0
	bl CalcDx
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r5, #0x5c]
_0802AB04:
	ldr r4, [r5, #0x5c]
	cmp r4, #0
	bge _0802AB0C
	rsbs r4, r4, #0
_0802AB0C:
	adds r0, r5, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	blt _0802AB28
	ldr r0, [r6, #0x40]
	cmp r0, #0
	bne _0802AB28
	adds r0, r5, #0
	bl CreateAfterImages
	str r0, [r6, #0x40]
_0802AB28:
	movs r0, #0x89
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	b _0802AB82
_0802AB34:
	adds r2, r5, #0
	adds r2, #0xb4
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r2, #0xe]
	cmp r0, #2
	bne _0802AB50
	adds r0, r5, #0
	bl FUN_08032c30
	b _0802AB56
_0802AB50:
	adds r0, r5, #0
	bl FUN_08032c04
_0802AB56:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802AB74
	adds r0, r5, #0
	bl GetSplitHeavenSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _0802AB80
_0802AB74:
	adds r0, r5, #0
	bl GetSplitHeavenSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0802AB80:
	str r0, [r5, #0x5c]
_0802AB82:
	movs r0, #1
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	bl zeroJumpRise
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
