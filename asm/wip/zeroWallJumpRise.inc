	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	ldr r1, _0802AF28 @ =0x00000501
	cmp r0, r1
	bne _0802AF64
	adds r0, r4, #0
	adds r0, #0x71
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	bne _0802AF64
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0802AF64
	ldr r1, _0802AF2C @ =0x00000601
	adds r0, r4, #0
	movs r2, #1
	movs r3, #4
	bl GotoMotion
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802AF30
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	b _0802AF50
	.align 2, 0
_0802AF28: .4byte 0x00000501
_0802AF2C: .4byte 0x00000601
_0802AF30:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_0802AF50:
	str r0, [r4, #0x5c]
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5, #0x40]
	cmp r0, #0
	bne _0802AF64
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r5, #0x40]
_0802AF64:
	ldr r0, _0802AF80 @ =0x00000111
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r2, r0, #0
	cmp r2, #0
	beq _0802AF84
	subs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r7, r4, #0
	adds r7, #0xb4
	b _0802B036
	.align 2, 0
_0802AF80: .4byte 0x00000111
_0802AF84:
	ldrb r0, [r4, #0xa]
	lsrs r3, r0, #4
	movs r6, #1
	ands r3, r6
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802AFC8
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0802AFA4
	rsbs r0, r0, #0
_0802AFA4:
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0802AFF8
_0802AFC8:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _0802AFF6
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0802AFD8
	rsbs r0, r0, #0
_0802AFD8:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0802AFF8
_0802AFF6:
	movs r5, #0
_0802AFF8:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r6, [r0, #0x40]
	adds r7, r0, #0
	cmp r6, #0
	bne _0802B020
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r3, r0
	beq _0802B036
	ldr r1, _0802B01C @ =0x00000502
	adds r0, r4, #0
	bl SetMotion
	strb r6, [r4, #0xf]
	b _0802B036
	.align 2, 0
_0802B01C: .4byte 0x00000502
_0802B020:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x5c]
	cmp r0, r1
	beq _0802B036
	ldr r1, _0802B0D8 @ =0x00000602
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xf]
_0802B036:
	mov r8, r7
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _0802B0DC @ =0x00000147
	adds r5, r4, r0
	ldrb r1, [r5]
	lsls r1, r1, #3
	ldr r6, _0802B0E0 @ =gZeroRanges
	adds r1, r1, r6
	adds r0, r4, #0
	movs r2, #0
	bl PushoutWallX
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B062
	movs r0, #0
	mov r1, r8
	str r0, [r1, #0x54]
_0802B062:
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r0, r4, #0
	movs r2, #1
	bl PushoutWallX
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B07A
	movs r0, #0
	str r0, [r7, #0x54]
_0802B07A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl getFallAcceleration
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r0, r4, #0
	movs r2, #0
	bl PushoutByCeiling
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0802B0BA
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r0, r4, #0
	movs r2, #1
	bl PushoutByFloor2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_0802B0BA:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bgt _0802B0C4
	cmp r1, #0
	beq _0802B0CC
_0802B0C4:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xe]
	strb r1, [r4, #0xf]
_0802B0CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B0D8: .4byte 0x00000602
_0802B0DC: .4byte 0x00000147
_0802B0E0: .4byte gZeroRanges
