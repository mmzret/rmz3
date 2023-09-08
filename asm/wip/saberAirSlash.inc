	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080385FA
	ldrb r1, [r6, #0x1e]
	lsls r1, r1, #8
	adds r0, r6, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xc8
	lsls r1, r1, #5
	cmp r0, r1
	bne _080385F4
	adds r0, r6, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	bne _080385F4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080385F0 @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080386F4
	.align 2, 0
_080385F0: .4byte gWeaponFnTable
_080385F4:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _08038628
_080385FA:
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _08038610
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _08038628
_08038610:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08038664 @ =gSaberGeneralCollisions
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_08038628:
	ldrb r5, [r4, #0xd]
	cmp r5, #1
	bne _080386B4
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r4, #0
	adds r5, #0xb4
	adds r7, r0, #0
	cmp r1, #3
	ble _0803867E
	ldrb r1, [r6, #0x1e]
	lsls r1, r1, #8
	adds r0, r6, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xc8
	lsls r1, r1, #5
	cmp r0, r1
	beq _08038668
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _0803867E
	.align 2, 0
_08038664: .4byte gSaberGeneralCollisions
_08038668:
	movs r0, #0xa
	strb r0, [r5, #0xd]
	adds r0, r6, #0
	bl CalcSaberBonus
	ldrb r1, [r5, #0xd]
	adds r0, r0, r1
	strb r0, [r5, #0xd]
	ldr r0, _080386AC @ =gSaberElements
	ldrb r0, [r0]
	strb r0, [r5, #0xc]
_0803867E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _080386B0 @ =gSaberCollisions
	ldrb r1, [r4, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #0
	ldrsb r2, [r7, r2]
	ldr r1, [r1]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrb r2, [r5, #0xd]
	ldrb r3, [r5, #0xc]
	ldrb r4, [r5, #0xe]
	str r4, [sp]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #4]
	bl InitWeaponBody
	b _080386F6
	.align 2, 0
_080386AC: .4byte gSaberElements
_080386B0: .4byte gSaberCollisions
_080386B4:
	cmp r5, #2
	bne _080386F6
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080386D6
	ldr r1, _08038700 @ =0x00006201
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08038704 @ =gSaberGeneralCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080386D6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080386F6
	ldr r1, _08038708 @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_080386F4:
	str r0, [r4, #0x14]
_080386F6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038700: .4byte 0x00006201
_08038704: .4byte gSaberGeneralCollisions
_08038708: .4byte gWeaponFnTable
