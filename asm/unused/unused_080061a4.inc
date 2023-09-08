	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp]
	adds r5, r1, #0
	str r2, [sp, #4]
	ldr r0, [sp, #0x60]
	ldr r2, [sp, #0x64]
	ldr r4, [r5]
	ldr r1, [sp]
	str r4, [r1]
	ldr r1, [r5, #4]
	ldr r6, [sp]
	str r1, [r6, #4]
	str r3, [r6, #0xc]
	str r0, [r6, #0x10]
	str r2, [r6, #0x14]
	ldr r2, _080061E4 @ =0x000001FF
	adds r0, r4, #0
	ands r0, r2
	strh r0, [r6, #8]
	ands r1, r2
	strh r1, [r6, #0xa]
	subs r4, #0x10
	cmp r4, #0
	ble _080061E8
	str r4, [sp, #0xc]
	b _080061EC
	.align 2, 0
_080061E4: .4byte 0x000001FF
_080061E8:
	movs r0, #0
	str r0, [sp, #0xc]
_080061EC:
	ldr r0, [r5, #4]
	subs r0, #0x10
	cmp r0, #0
	ble _080061F8
	str r0, [sp, #0x10]
	b _080061FC
_080061F8:
	movs r1, #0
	str r1, [sp, #0x10]
_080061FC:
	ldr r0, [sp, #0xc]
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	ldr r2, [sp]
	ldr r6, [r2, #0x14]
	adds r4, r6, r4
	ldr r5, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r6]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #8]
	ldr r0, [sp, #0xc]
	movs r1, #0xf0
	bl __modsi3
	adds r4, r0, #0
	lsls r4, r4, #0xc
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldr r3, [sp, #8]
	ldrb r2, [r3]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r1, [sp]
	ldr r3, [r1, #0x10]
	adds r2, r3, r2
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #1
	adds r2, r2, r5
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r7, r2, r1
	ldr r2, [sp, #0xc]
	asrs r2, r2, #4
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x10]
	asrs r1, r1, #4
	str r1, [sp, #0x10]
	movs r2, #0
	mov sb, r2
	movs r1, #0
	str r1, [sp, #0x14]
	mov r8, r1
	str r6, [sp, #0x30]
	str r3, [sp, #0x2c]
	str r0, [sp, #0x1c]
	movs r0, #0xa
	ldr r3, [sp, #0x1c]
	subs r0, r0, r3
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	str r5, [sp, #0x18]
	movs r6, #0xf
	subs r4, r6, r4
	str r4, [sp, #0x28]
_0800628C:
	movs r1, #0
	mov r0, sb
	lsls r0, r0, #0x10
	str r0, [sp, #0x38]
	lsls r2, r2, #0x10
	str r2, [sp, #0x3c]
	asrs r2, r2, #0x10
	mov sl, r2
_0800629C:
	ldr r2, [sp, #0x38]
	lsrs r2, r2, #0x10
	mov ip, r2
	lsls r1, r1, #0x10
	mov sb, r1
	mov r3, sl
	cmp r3, #0
	bne _080062BC
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _080062BA
	b _080063D0
_080062BA:
	b _080062EA
_080062BC:
	mov r6, sl
	cmp r6, #1
	bne _080062DE
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	ble _080062D0
	b _080063D0
_080062D0:
	adds r0, r1, #0
	subs r0, #0xa
	ldr r3, [sp, #0x1c]
	adds r0, r0, r3
	cmp r0, #9
	bgt _080063D0
	b _080062EA
_080062DE:
	mov r4, ip
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	bgt _080063D0
_080062EA:
	asrs r0, r2, #0x10
	ldr r1, [sp, #0x10]
	adds r6, r1, r0
	movs r0, #0x1f
	ands r6, r0
	ldr r2, [sp, #0x14]
	lsls r0, r2, #0x10
	lsrs r3, r0, #0x10
	mov r8, r3
	str r0, [sp, #0x34]
	mov r4, sb
	cmp r4, #0
	bne _08006310
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x28]
	cmp r0, r1
	bge _0800639A
	b _08006338
_08006310:
	mov r2, sb
	asrs r0, r2, #0x10
	cmp r0, #1
	bne _0800632E
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800639A
	subs r0, #0xf
	ldr r4, [sp, #0x24]
	adds r0, r0, r4
	cmp r0, #0xe
	bgt _0800639A
	b _08006338
_0800632E:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800639A
_08006338:
	mov r2, r8
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	ldr r3, [sp, #0xc]
	adds r1, r3, r5
	movs r2, #0x1f
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r4, [sp]
	ldr r3, [r4, #0xc]
	adds r3, r3, r0
	ands r1, r2
	lsls r4, r6, #7
	lsls r1, r1, #1
	ldr r0, [sp, #4]
	adds r1, r1, r0
	adds r4, r4, r1
	ldrh r0, [r3]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r4]
	adds r4, #0x40
	ldrh r0, [r3, #4]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #6]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r4]
	adds r7, #2
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r8, r5
	mov r1, sb
	cmp r1, #0
	bne _08006310
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x28]
	cmp r0, r2
	blt _08006338
_0800639A:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r4, [sp, #0x34]
	asrs r1, r4, #0x10
	subs r0, r0, r1
	movs r6, #0xf
	subs r0, r6, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r1, ip
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	mov ip, r0
	mov r3, sl
	cmp r3, #0
	beq _080063C4
	b _080062BC
_080063C4:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _080062EA
_080063D0:
	mov r6, r8
	str r6, [sp, #0x14]
	mov r1, sb
	asrs r0, r1, #0x10
	cmp r0, #2
	beq _08006426
	ldr r3, [sp, #8]
	adds r3, #1
	str r3, [sp, #8]
	mov r4, sl
	cmp r4, #0
	bne _08006404
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r6, [sp, #0x2c]
	adds r1, r6, r1
	ldr r3, [sp, #0x1c]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r7, r1, r0
	b _08006416
_08006404:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r6, [sp, #0x2c]
	adds r7, r6, r0
_08006416:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08006426
	b _0800629C
_08006426:
	ldr r0, [sp, #0x3c]
	asrs r3, r0, #0x10
	cmp r3, #2
	beq _08006464
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r4, [sp, #8]
	adds r0, r4, r0
	subs r0, #2
	str r0, [sp, #8]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r6, [sp, #0x2c]
	adds r0, r6, r0
	ldr r1, [sp, #0x18]
	adds r7, r0, r1
	lsrs r2, r2, #0x10
	mov sb, r2
	movs r2, #0
	str r2, [sp, #0x14]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08006464
	b _0800628C
_08006464:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
