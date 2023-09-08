	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xee
	ldrb r0, [r4]
	cmp r0, #0
	bne _0802F03C
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _0802F038 @ =0x00000129
	adds r1, r6, r0
	movs r0, #0x10
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	mov r8, r1
	b _0802F0A2
	.align 2, 0
_0802F038: .4byte 0x00000129
_0802F03C:
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r6, #0
	bl KeepMotion
	ldrb r0, [r4]
	cmp r0, #1
	bne _0802F074
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0802F070 @ =0x00000129
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #1
	bgt _0802F0A2
	adds r0, r6, #0
	movs r1, #4
	bl CreateWeaponSaber
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0802F0A2
	.align 2, 0
_0802F070: .4byte 0x00000129
_0802F074:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	ldr r1, _0802F0EC @ =0x00000129
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #3
	bne _0802F0A2
	movs r0, #0x92
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrb r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0
	strb r0, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0xec
	strb r0, [r1]
_0802F0A2:
	mov r7, r8
	ldrb r0, [r7]
	cmp r0, #0
	beq _0802F128
	subs r0, #1
	strb r0, [r7]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802F0F0
	adds r0, r6, #0
	bl CalcDx
	adds r5, r0, #0
	adds r0, r6, #0
	bl GetDashSpeed
	adds r4, r0, #0
	adds r0, r6, #0
	bl CalcDx
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r4, r4, r0
	ldrb r0, [r7]
	muls r0, r4, r0
	cmp r0, #0
	bge _0802F0E6
	adds r0, #0xf
_0802F0E6:
	asrs r0, r0, #4
	adds r0, r5, r0
	b _0802F126
	.align 2, 0
_0802F0EC: .4byte 0x00000129
_0802F0F0:
	adds r0, r6, #0
	bl CalcDx
	adds r5, r0, #0
	adds r0, r6, #0
	bl GetDashSpeed
	adds r4, r0, #0
	adds r0, r6, #0
	bl CalcDx
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	rsbs r5, r5, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r4, r4, r0
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r4, r0
	cmp r0, #0
	bge _0802F122
	adds r0, #0xf
_0802F122:
	asrs r0, r0, #4
	subs r0, r5, r0
_0802F126:
	str r0, [r6, #0x5c]
_0802F128:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
