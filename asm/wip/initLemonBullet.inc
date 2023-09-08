	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r0, _08037168 @ =gSystemSavedataManager
	adds r0, #0x4d
	ldrb r0, [r0]
	cmp r0, #2
	bne _08037170
	ldr r1, _0803716C @ =0x00008502
	b _08037176
	.align 2, 0
_08037168: .4byte gSystemSavedataManager
_0803716C: .4byte 0x00008502
_08037170:
	cmp r0, #1
	bne _08037184
	ldr r1, _08037180 @ =0x00008501
_08037176:
	adds r0, r5, #0
	bl SetMotion
	b _0803718E
	.align 2, 0
_08037180: .4byte 0x00008501
_08037184:
	movs r1, #0x85
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
_0803718E:
	movs r0, #0x16
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r1, [r0, #0xd]
	movs r2, #0
	mov r8, r0
	cmp r1, #1
	bne _080371B0
	mov r0, sb
	adds r0, #0xb4
	ldrh r1, [r0, #0x12]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x11
_080371B0:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080371CE
	movs r0, #0x98
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	cmp r2, #0
	beq _080371F8
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080371DE
	b _080371EC
_080371CE:
	ldr r0, _080371E8 @ =0xFFFFFB40
	str r0, [r5, #0x5c]
	cmp r2, #0
	beq _080371F8
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080371EC
_080371DE:
	movs r0, #0x98
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	b _080371FA
	.align 2, 0
_080371E8: .4byte 0xFFFFFB40
_080371EC:
	ldr r0, _080371F4 @ =0xFFFFFED0
	str r0, [r5, #0x60]
	b _080371FA
	.align 2, 0
_080371F4: .4byte 0xFFFFFED0
_080371F8:
	str r2, [r5, #0x60]
_080371FA:
	movs r0, #4
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r6, r5, #0
	adds r6, #0x74
	ldr r7, _0803725C @ =0x0835EEA4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r6, #0
	adds r1, r7, #0
	movs r3, #1
	bl InitBody
	str r5, [r6, #0x2c]
	str r4, [r6, #0x24]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #0xc]
	ldr r0, _08037260 @ =0x00FFFF00
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0xa
	movs r4, #2
	cmp r1, r0
	bne _08037230
	movs r4, #3
_08037230:
	mov r0, sb
	bl CalcBusterBonus
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl InitWeaponBody
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803725C: .4byte 0x0835EEA4
_08037260: .4byte 0x00FFFF00
