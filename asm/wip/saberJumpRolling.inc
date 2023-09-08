	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r4]
	mov r8, r0
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	bne _08038C10
	ldrb r0, [r0, #0x1e]
	lsls r0, r0, #8
	mov r1, r8
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	movs r0, #0xd0
	lsls r0, r0, #5
	adds r7, r5, #0
	adds r7, #0x71
	cmp r1, r0
	beq _08038BA4
	mov r0, r8
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	beq _08038BA4
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08038BA0 @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08038CC6
	.align 2, 0
_08038BA0: .4byte gWeaponFnTable
_08038BA4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _08038C08 @ =gSaberCollisions
	ldrb r1, [r5, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #0
	ldrsb r2, [r7, r2]
	ldr r1, [r1]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r1, [r2]
	adds r6, r5, #0
	adds r6, #0xb4
	ldrb r2, [r6, #0xd]
	ldrb r3, [r6, #0xc]
	ldrb r4, [r6, #0xe]
	str r4, [sp]
	ldrb r4, [r7]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x19
	adds r4, #1
	str r4, [sp, #4]
	bl InitWeaponBody
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08038CC8
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
	ldr r0, _08038C0C @ =gSaberElements
	ldrb r0, [r0]
	strb r0, [r6, #0xc]
	b _08038CC8
	.align 2, 0
_08038C08: .4byte gSaberCollisions
_08038C0C: .4byte gSaberElements
_08038C10:
	cmp r2, #1
	bne _08038C88
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _08038C2E
	movs r1, #0xc4
	lsls r1, r1, #7
	adds r0, r5, #0
	movs r2, #4
	movs r3, #2
	bl GotoMotion
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_08038C2E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _08038C84 @ =gSaberCollisions
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
	beq _08038CC8
	movs r0, #0xd0
	lsls r0, r0, #5
	cmp r1, r0
	beq _08038CC8
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xe]
	strb r1, [r5, #0xf]
	b _08038CC8
	.align 2, 0
_08038C84: .4byte gSaberCollisions
_08038C88:
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _08038C9C
	ldr r1, _08038CD4 @ =0x00006201
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_08038C9C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08038CD8 @ =gSaberGeneralCollisions
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08038CC8
	ldr r1, _08038CDC @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_08038CC6:
	str r0, [r5, #0x14]
_08038CC8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038CD4: .4byte 0x00006201
_08038CD8: .4byte gSaberGeneralCollisions
_08038CDC: .4byte gWeaponFnTable
