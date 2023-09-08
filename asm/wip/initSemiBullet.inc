	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xb4
	ldr r0, [r4]
	mov r8, r0
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r1, #0x86
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x1a
	bl PlaySound
	ldrb r0, [r4, #0xd]
	movs r2, #0
	cmp r0, #1
	bne _080372B4
	mov r0, r8
	adds r0, #0xb4
	ldrh r1, [r0, #0x12]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x11
_080372B4:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080372D2
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r7, #0x5c]
	cmp r2, #0
	beq _080372FC
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080372E2
	b _080372F0
_080372D2:
	ldr r0, _080372EC @ =0xFFFFFA00
	str r0, [r7, #0x5c]
	cmp r2, #0
	beq _080372FC
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080372F0
_080372E2:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r7, #0x60]
	b _080372FE
	.align 2, 0
_080372EC: .4byte 0xFFFFFA00
_080372F0:
	ldr r0, _080372F8 @ =0xFFFFFE80
	str r0, [r7, #0x60]
	b _080372FE
	.align 2, 0
_080372F8: .4byte 0xFFFFFE80
_080372FC:
	str r2, [r7, #0x60]
_080372FE:
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r6, _08037348 @ =gSemiBulletCollisions
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	mov r0, r8
	bl CalcBusterBonus
	adds r2, r0, #0
	adds r2, #6
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	bl InitWeaponBody
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037348: .4byte gSemiBulletCollisions
