	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	adds r5, r4, #0
	adds r5, #0xee
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803230A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl CreateWeaponRod
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080324F6
_0803230A:
	adds r0, r4, #0
	adds r1, r6, #0
	bl KeepMotion
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	cmp r1, r6
	beq _08032338
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	bl GotoMotion
_08032338:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bgt _08032348
	b _0803248C
_08032348:
	adds r0, r4, #0
	bl Is1000Slash
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08032384
	cmp r7, #0
	bne _08032368
	ldr r2, _08032364 @ =0x0000013B
	adds r1, r4, r2
	movs r0, #0x10
	b _0803236E
	.align 2, 0
_08032364: .4byte 0x0000013B
_08032368:
	ldr r0, _08032380 @ =0x0000013B
	adds r1, r4, r0
	movs r0, #0
_0803236E:
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xed
	movs r0, #0
	movs r1, #0xb
	strb r1, [r2]
	adds r1, r4, #0
	adds r1, #0xee
	b _080324F4
	.align 2, 0
_08032380: .4byte 0x0000013B
_08032384:
	ldr r2, _080323A0 @ =0x00000133
	adds r0, r4, r2
	ldrb r5, [r0]
	adds r6, r0, #0
	cmp r5, #0
	beq _08032448
	cmp r7, #0
	bne _080323A8
	ldr r0, _080323A4 @ =0x0000013B
	adds r1, r4, r0
	movs r0, #0x10
	strb r0, [r1]
	b _080323AE
	.align 2, 0
_080323A0: .4byte 0x00000133
_080323A4: .4byte 0x0000013B
_080323A8:
	ldr r2, _08032410 @ =0x0000013B
	adds r0, r4, r2
	strb r1, [r0]
_080323AE:
	movs r0, #0x86
	lsls r0, r0, #2
	adds r3, r4, r0
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080323D8
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
_080323D8:
	ldr r0, [r3]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080323FE
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_080323FE:
	ldr r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032418
	ldr r0, _08032414 @ =u8_ARRAY_0835e84c
	adds r0, #2
	b _0803242E
	.align 2, 0
_08032410: .4byte 0x0000013B
_08032414: .4byte u8_ARRAY_0835e84c
_08032418:
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _0803242C
	ldr r0, _08032428 @ =u8_ARRAY_0835e84c
	adds r0, #4
	b _0803242E
	.align 2, 0
_08032428: .4byte u8_ARRAY_0835e84c
_0803242C:
	ldr r0, _08032444 @ =u8_ARRAY_0835e84c
_0803242E:
	adds r0, r7, r0
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xed
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0xee
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
	b _080324F6
	.align 2, 0
_08032444: .4byte u8_ARRAY_0835e84c
_08032448:
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r0, r4, #0
	bl IsAttackOK
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803248C
	cmp r7, #0
	bne _0803246C
	ldr r0, _08032468 @ =0x0000013B
	adds r1, r4, r0
	movs r0, #0x10
	strb r0, [r1]
	b _08032472
	.align 2, 0
_08032468: .4byte 0x0000013B
_0803246C:
	ldr r1, _08032488 @ =0x0000013B
	adds r0, r4, r1
	strb r5, [r0]
_08032472:
	adds r0, r4, #0
	adds r0, #0xec
	movs r2, #0
	movs r1, #3
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, r4, #0
	bl zeroAttack
	b _080324F6
	.align 2, 0
_08032488: .4byte 0x0000013B
_0803248C:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080324D8
	cmp r7, #0
	bne _080324A8
	ldr r2, _080324A4 @ =0x0000013B
	adds r1, r4, r2
	movs r0, #0x10
	b _080324AE
	.align 2, 0
_080324A4: .4byte 0x0000013B
_080324A8:
	ldr r0, _080324D4 @ =0x0000013B
	adds r1, r4, r0
	movs r0, #0
_080324AE:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl GetDefaultMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0x93
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0xff
	b _080324F4
	.align 2, 0
_080324D4: .4byte 0x0000013B
_080324D8:
	adds r0, r4, #0
	mov r1, sp
	bl IsAttackOK
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080324F6
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #2
	bne _080324F6
	ldr r0, _08032500 @ =0x00000133
	adds r1, r4, r0
	movs r0, #1
_080324F4:
	strb r0, [r1]
_080324F6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032500: .4byte 0x00000133
