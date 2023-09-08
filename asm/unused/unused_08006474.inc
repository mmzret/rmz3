	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp]
	adds r4, r1, #0
	str r2, [sp, #4]
	ldr r2, [r4]
	str r2, [r0]
	ldr r1, [r4, #4]
	ldr r0, [sp]
	str r1, [r0, #4]
	ldr r3, _080064A8 @ =0x000001FF
	adds r0, r2, #0
	ands r0, r3
	ldr r5, [sp]
	strh r0, [r5, #8]
	ands r1, r3
	strh r1, [r5, #0xa]
	subs r2, #0x10
	cmp r2, #0
	ble _080064AC
	str r2, [sp, #0xc]
	b _080064B0
	.align 2, 0
_080064A8: .4byte 0x000001FF
_080064AC:
	movs r0, #0
	str r0, [sp, #0xc]
_080064B0:
	ldr r0, [r4, #4]
	subs r0, #0x10
	cmp r0, #0
	ble _080064BC
	str r0, [sp, #0x10]
	b _080064C0
_080064BC:
	movs r1, #0
	str r1, [sp, #0x10]
_080064C0:
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
	ldr r5, [sp]
	ldr r3, [r5, #0x10]
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
	ldr r1, [sp, #0xc]
	asrs r1, r1, #4
	str r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	asrs r2, r2, #4
	str r2, [sp, #0x10]
	movs r1, #0
	mov sb, r1
	movs r2, #0
	str r2, [sp, #0x14]
	mov r8, r2
	str r6, [sp, #0x3c]
	str r3, [sp, #0x38]
	str r0, [sp, #0x1c]
	movs r0, #0xa
	ldr r3, [sp, #0x1c]
	subs r0, r0, r3
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	str r5, [sp, #0x18]
	movs r5, #0xf
	subs r4, r5, r4
	str r4, [sp, #0x28]
_08006550:
	movs r1, #0
	mov r0, sb
	lsls r0, r0, #0x10
	str r0, [sp, #0x30]
	lsls r2, r2, #0x10
	str r2, [sp, #0x34]
	asrs r2, r2, #0x10
	mov sl, r2
_08006560:
	ldr r2, [sp, #0x30]
	lsrs r2, r2, #0x10
	mov ip, r2
	lsls r1, r1, #0x10
	mov sb, r1
	mov r3, sl
	cmp r3, #0
	bne _08006580
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _0800657E
	b _08006694
_0800657E:
	b _080065AE
_08006580:
	mov r5, sl
	cmp r5, #1
	bne _080065A2
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	ble _08006594
	b _08006694
_08006594:
	adds r0, r1, #0
	subs r0, #0xa
	ldr r3, [sp, #0x1c]
	adds r0, r0, r3
	cmp r0, #9
	bgt _08006694
	b _080065AE
_080065A2:
	mov r4, ip
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	bgt _08006694
_080065AE:
	asrs r0, r2, #0x10
	ldr r5, [sp, #0x10]
	adds r6, r5, r0
	movs r0, #0x1f
	ands r6, r0
	ldr r1, [sp, #0x14]
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	mov r8, r2
	str r0, [sp, #0x2c]
	mov r3, sb
	cmp r3, #0
	bne _080065D4
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldr r4, [sp, #0x28]
	cmp r0, r4
	bge _0800665E
	b _080065FC
_080065D4:
	mov r5, sb
	asrs r0, r5, #0x10
	cmp r0, #1
	bne _080065F2
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800665E
	subs r0, #0xf
	ldr r2, [sp, #0x24]
	adds r0, r0, r2
	cmp r0, #0xe
	bgt _0800665E
	b _080065FC
_080065F2:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800665E
_080065FC:
	mov r4, r8
	lsls r5, r4, #0x10
	asrs r5, r5, #0x10
	ldr r0, [sp, #0xc]
	adds r1, r0, r5
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
	bne _080065D4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x28]
	cmp r0, r2
	blt _080065FC
_0800665E:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r4, [sp, #0x2c]
	asrs r1, r4, #0x10
	subs r0, r0, r1
	movs r5, #0xf
	subs r0, r5, r0
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
	beq _08006688
	b _08006580
_08006688:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _080065AE
_08006694:
	mov r5, r8
	str r5, [sp, #0x14]
	mov r1, sb
	asrs r0, r1, #0x10
	cmp r0, #2
	beq _080066EA
	ldr r3, [sp, #8]
	adds r3, #1
	str r3, [sp, #8]
	mov r4, sl
	cmp r4, #0
	bne _080066C8
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r5, [sp, #0x38]
	adds r1, r5, r1
	ldr r3, [sp, #0x1c]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r7, r1, r0
	b _080066DA
_080066C8:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r5, [sp, #0x38]
	adds r7, r5, r0
_080066DA:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _080066EA
	b _08006560
_080066EA:
	ldr r0, [sp, #0x34]
	asrs r3, r0, #0x10
	cmp r3, #2
	beq _08006728
	ldr r1, [sp, #0x3c]
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
	ldr r5, [sp, #0x38]
	adds r0, r5, r0
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
	bgt _08006728
	b _08006550
_08006728:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
