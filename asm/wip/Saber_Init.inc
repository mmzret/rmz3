	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _080382A4 @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080382A8 @ =gSaberMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl SetMotion
	ldr r1, _080382AC @ =gSaberCollisions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r7, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080382B0 @ =gSaberSoundIDs
	ldrb r2, [r6, #0x10]
	lsls r0, r2, #1
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	beq _080382C2
	cmp r2, #0xd
	bne _080382BC
	movs r0, #0x95
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080382B4
	movs r0, #0x11
	bl PlaySound
	b _080382C2
	.align 2, 0
_080382A4: .4byte gWeaponFnTable
_080382A8: .4byte gSaberMotions
_080382AC: .4byte gSaberCollisions
_080382B0: .4byte gSaberSoundIDs
_080382B4:
	ldrh r0, [r1]
	bl PlaySound
	b _080382C2
_080382BC:
	ldrh r0, [r1]
	bl PlaySound
_080382C2:
	ldrb r0, [r6, #0x10]
	adds r5, r6, #0
	adds r5, #0xb4
	cmp r0, #0xd
	bne _08038306
	ldr r1, [r5]
	adds r2, r1, #0
	adds r2, #0xb4
	movs r3, #0x95
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080382EA
	adds r0, r1, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSaberWave
	b _08038306
_080382EA:
	ldrb r0, [r2, #0xe]
	cmp r0, #3
	bne _080382FC
	adds r0, r1, #0
	adds r1, r6, #0
	movs r2, #1
	bl CreateThrowBlade
	b _08038306
_080382FC:
	adds r0, r1, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateThrowBlade
_08038306:
	ldrb r0, [r6, #0x10]
	cmp r0, #0xe
	beq _0803832C
	cmp r0, #0x10
	beq _0803832C
	cmp r0, #0x16
	beq _0803832C
	ldrb r1, [r7, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803832C
	ldr r0, _08038328 @ =gSaberElements
	ldrb r1, [r6, #0x11]
	adds r1, r1, r0
	ldrb r0, [r1]
	b _08038330
	.align 2, 0
_08038328: .4byte gSaberElements
_0803832C:
	ldr r0, _0803836C @ =gSaberElements
	ldrb r0, [r0]
_08038330:
	strb r0, [r5, #0xc]
	ldr r1, _08038370 @ =gSaberDamages
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	mov r0, r8
	bl CalcSaberBonus
	ldrb r1, [r5, #0xd]
	adds r0, r0, r1
	strb r0, [r5, #0xd]
	mov r0, r8
	movs r1, #0x2e
	bl isElfUsed_2
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08038378
	ldr r0, _08038374 @ =gIlethasables
	ldrb r1, [r6, #0x10]
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08038378
	ldrb r0, [r7, #6]
	movs r1, #0x40
	orrs r0, r1
	b _0803837A
	.align 2, 0
_0803836C: .4byte gSaberElements
_08038370: .4byte gSaberDamages
_08038374: .4byte gIlethasables
_08038378:
	ldrb r0, [r7, #6]
_0803837A:
	strb r0, [r5, #0xe]
	ldrb r0, [r6, #0x10]
	cmp r0, #0x11
	bne _08038394
	ldr r1, _080383CC @ =gSaberElements
	ldrb r0, [r6, #0x11]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xc]
	ldrb r1, [r5, #0xe]
	movs r0, #2
	orrs r0, r1
	strb r0, [r5, #0xe]
_08038394:
	adds r4, r6, #0
	adds r4, #0x74
	ldrb r2, [r5, #0xd]
	ldrb r3, [r5, #0xc]
	ldrb r0, [r5, #0xe]
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r7, #0
	bl InitWeaponBody
	movs r0, #0
	strb r0, [r6, #0x12]
	movs r0, #1
	strb r0, [r5, #0xf]
	ldr r0, _080383D0 @ =onHit
	str r0, [r4, #0x24]
	adds r0, r6, #0
	bl Saber_Update
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080383CC: .4byte gSaberElements
_080383D0: .4byte onHit
