	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	ldr r2, _0802AC70 @ =0x00000403
	cmp r1, r2
	beq _0802AC1C
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802AC1C
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #1
	movs r3, #4
	bl GotoMotion
_0802AC1C:
	movs r0, #0x89
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r6, r4, #0
	adds r6, #0xb4
	cmp r0, #0
	beq _0802AC64
	subs r0, #1
	strb r0, [r5]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0802AC64
	movs r0, #8
	bl PlaySound
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x5c]
	ldr r0, [r6, #0x40]
	cmp r0, #0
	bne _0802AC64
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r6, #0x40]
_0802AC64:
	ldr r2, [r6, #0x54]
	cmp r2, #0
	beq _0802AC74
	lsls r0, r2, #0x10
	lsrs r3, r0, #0x10
	b _0802ACE2
	.align 2, 0
_0802AC70: .4byte 0x00000403
_0802AC74:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802ACB0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0802AC8C
	rsbs r0, r0, #0
_0802AC8C:
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
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
	b _0802ACE2
_0802ACB0:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _0802ACE0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0802ACC0
	rsbs r0, r0, #0
_0802ACC0:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0802ACE2
_0802ACE0:
	movs r3, #0
_0802ACE2:
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _0802AD80 @ =0x00000147
	adds r5, r4, r0
	ldrb r1, [r5]
	lsls r1, r1, #3
	ldr r7, _0802AD84 @ =gZeroRanges
	adds r1, r1, r7
	adds r0, r4, #0
	movs r2, #0
	bl PushoutWallX
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802AD0A
	movs r0, #0
	str r0, [r6, #0x54]
_0802AD0A:
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	adds r0, r4, #0
	movs r2, #1
	bl PushoutWallX
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802AD22
	movs r0, #0
	str r0, [r6, #0x54]
_0802AD22:
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
	adds r1, r1, r7
	adds r0, r4, #0
	movs r2, #0
	bl PushoutByCeiling
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0802AD62
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	adds r0, r4, #0
	movs r2, #1
	bl zero_080264dc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_0802AD62:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bgt _0802AD6C
	cmp r1, #0
	beq _0802AD74
_0802AD6C:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xe]
	strb r1, [r4, #0xf]
_0802AD74:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802AD80: .4byte 0x00000147
_0802AD84: .4byte gZeroRanges
