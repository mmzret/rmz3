	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r4]
	mov r8, r0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08038726
	b _08038834
_08038726:
	ldr r0, _08038770 @ =0x00000125
	add r0, r8
	ldrb r1, [r0]
	adds r0, r1, #7
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r1, #0
	bne _08038738
	b _080388DA
_08038738:
	ldr r1, _08038774 @ =gSaberMotions
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r7, [r0]
	ldrb r1, [r5, #0x1e]
	lsls r1, r1, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	adds r4, r5, #0
	adds r4, #0x71
	cmp r7, r0
	beq _08038798
	ldr r0, _08038778 @ =0x00006202
	cmp r7, r0
	bne _0803877C
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #6
	ble _0803877C
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #7
	movs r3, #1
	bl GotoMotion
	b _08038798
	.align 2, 0
_08038770: .4byte 0x00000125
_08038774: .4byte gSaberMotions
_08038778: .4byte 0x00006202
_0803877C:
	movs r2, #0
	ldrsb r2, [r4, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r0, #0x72
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	bl GotoMotion
_08038798:
	ldrb r0, [r5, #0x10]
	cmp r0, #8
	bne _080387C4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bne _080387C4
	adds r0, r5, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _080387C4
	adds r0, r5, #0
	adds r0, #0x54
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl oz_080b3820
_080387C4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08038828 @ =gSaberCollisions
	lsls r2, r6, #2
	adds r2, r2, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldr r2, [r2]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	adds r6, r5, #0
	adds r6, #0xb4
	ldrb r2, [r6, #0xd]
	ldrb r3, [r6, #0xc]
	ldrb r4, [r6, #0xe]
	str r4, [sp]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #4]
	bl InitWeaponBody
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080388EC
	ldr r0, _0803882C @ =0x00006202
	cmp r7, r0
	bne _080388DA
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xe]
	strb r1, [r5, #0xf]
	movs r0, #0xa
	strb r0, [r6, #0xd]
	mov r0, r8
	bl CalcSaberBonus
	ldrb r1, [r6, #0xd]
	adds r0, r0, r1
	strb r0, [r6, #0xd]
	ldr r0, _08038830 @ =gSaberElements
	ldrb r0, [r0]
	strb r0, [r6, #0xc]
	b _080388EC
	.align 2, 0
_08038828: .4byte gSaberCollisions
_0803882C: .4byte 0x00006202
_08038830: .4byte gSaberElements
_08038834:
	cmp r0, #1
	bne _080388AC
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _08038852
	movs r1, #0xc4
	lsls r1, r1, #7
	adds r0, r5, #0
	movs r2, #4
	movs r3, #2
	bl GotoMotion
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_08038852:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _080388A8 @ =gSaberCollisions
	adds r1, r5, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldr r2, [r2, #0x14]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	ldrb r2, [r4, #0xd]
	ldrb r3, [r4, #0xc]
	ldrb r4, [r4, #0xe]
	str r4, [sp]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #4]
	bl InitWeaponBody
	mov r1, r8
	ldrb r0, [r1, #0x1e]
	lsls r0, r0, #8
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	movs r0, #0xc8
	lsls r0, r0, #5
	cmp r1, r0
	beq _080388EC
	adds r0, #2
	cmp r1, r0
	beq _080388EC
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xe]
	strb r1, [r5, #0xf]
	b _080388EC
	.align 2, 0
_080388A8: .4byte gSaberCollisions
_080388AC:
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _080388C0
	ldr r1, _080388F8 @ =0x00006201
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_080388C0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080388FC @ =gSaberGeneralCollisions
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080388EC
_080388DA:
	ldr r1, _08038900 @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080388EC:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080388F8: .4byte 0x00006201
_080388FC: .4byte gSaberGeneralCollisions
_08038900: .4byte gWeaponFnTable
