	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp]
	mov r8, r1
	str r2, [sp, #4]
	ldr r6, [sp, #0x60]
	ldr r5, [sp, #0x64]
	str r3, [r0, #0xc]
	ldr r0, [sp]
	str r6, [r0, #0x10]
	str r5, [r0, #0x14]
	ldr r1, [r1]
	mov sb, r1
	mov r0, sb
	movs r1, #0xf
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	adds r4, r5, r4
	mov r2, r8
	ldr r2, [r2, #4]
	mov r8, r2
	mov r0, r8
	movs r1, #0xa
	bl __divsi3
	ldrb r1, [r5]
	muls r0, r1, r0
	adds r4, r4, r0
	mov sl, r4
	mov r3, sl
	str r3, [sp, #8]
	mov r0, sb
	movs r1, #0xf
	bl __modsi3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, r8
	movs r1, #0xa
	bl __modsi3
	mov r2, sl
	ldrb r1, [r2]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r6, r6, r1
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r2, r4, #1
	adds r6, r6, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r7, r6, r1
	movs r1, #0
	movs r3, #0
	str r3, [sp, #0xc]
	movs r5, #0
	str r0, [sp, #0x28]
	movs r0, #0xa
	ldr r6, [sp, #0x28]
	subs r0, r0, r6
	str r0, [sp, #0x2c]
	subs r6, #0x14
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x28]
	subs r0, #0x1e
	str r0, [sp, #0x14]
	str r4, [sp, #0x30]
	adds r6, r4, #0
	subs r6, #0x1e
	str r6, [sp, #0x18]
	str r2, [sp, #0x1c]
	movs r0, #0xf
	subs r0, r0, r4
	str r0, [sp, #0x34]
_080067E8:
	movs r2, #0
	lsls r1, r1, #0x10
	str r1, [sp, #0x38]
	lsls r3, r3, #0x10
	str r3, [sp, #0x3c]
	str r3, [sp, #0x20]
	asrs r1, r3, #0x10
	str r1, [sp, #0x24]
_080067F8:
	ldr r3, [sp, #0x38]
	lsrs r6, r3, #0x10
	lsls r2, r2, #0x10
	mov sb, r2
	ldr r0, [sp, #0x24]
	cmp r0, #0
	bne _08006816
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	ldr r2, [sp, #0x2c]
	cmp r1, r2
	blt _08006814
	b _08006936
_08006814:
	b _08006862
_08006816:
	ldr r3, [sp, #0x20]
	asrs r0, r3, #0x10
	cmp r0, #1
	bne _0800682C
	lsls r1, r6, #0x10
	asrs r0, r1, #0x10
	subs r0, #0xa
	ldr r2, [sp, #0x28]
	adds r0, r0, r2
	mov r8, r1
	b _08006852
_0800682C:
	cmp r0, #2
	bne _08006840
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x1f
	bgt _08006936
	ldr r3, [sp, #0x10]
	adds r0, r1, r3
	b _08006852
_08006840:
	cmp r0, #3
	bne _08006858
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x1f
	bgt _08006936
	ldr r2, [sp, #0x14]
	adds r0, r1, r2
_08006852:
	cmp r0, #9
	bgt _08006936
	b _08006862
_08006858:
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x1f
	bgt _08006936
_08006862:
	ldr r3, [sp, #0xc]
	lsls r0, r3, #0x10
	lsrs r5, r0, #0x10
	mov ip, r0
	mov r0, sb
	cmp r0, #0
	bne _0800687C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x34]
	cmp r0, r1
	bge _08006906
	b _080068AE
_0800687C:
	mov r2, sb
	asrs r0, r2, #0x10
	cmp r0, #1
	bne _08006890
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	subs r0, #0xf
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	b _080068A0
_08006890:
	cmp r0, #2
	bne _080068A6
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _08006906
	ldr r1, [sp, #0x18]
	adds r0, r0, r1
_080068A0:
	cmp r0, #0xe
	bgt _08006906
	b _080068AE
_080068A6:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _08006906
_080068AE:
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r2, [sp]
	ldr r3, [r2, #0xc]
	adds r3, r3, r0
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	mov r0, r8
	asrs r5, r0, #9
	lsls r0, r4, #1
	ldr r1, [sp, #4]
	adds r0, r0, r1
	adds r5, r5, r0
	ldrh r0, [r3]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5]
	adds r5, #0x40
	ldrh r0, [r3, #4]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #6]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5]
	adds r7, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	mov r2, sb
	cmp r2, #0
	bne _0800687C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #0x34]
	cmp r0, r3
	blt _080068AE
_08006906:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	mov r2, ip
	asrs r1, r2, #0x10
	subs r0, r0, r1
	movs r3, #0xf
	subs r0, r3, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	lsls r0, r6, #0x10
	movs r6, #0x80
	lsls r6, r6, #9
	adds r0, r0, r6
	lsrs r6, r0, #0x10
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _0800692A
	b _08006816
_0800692A:
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	ldr r2, [sp, #0x2c]
	cmp r1, r2
	blt _08006862
_08006936:
	str r5, [sp, #0xc]
	mov r3, sb
	asrs r0, r3, #0x10
	cmp r0, #3
	beq _0800698C
	movs r6, #1
	add sl, r6
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _08006968
	mov r1, sl
	ldrb r0, [r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, [sp]
	ldr r1, [r2, #0x10]
	adds r1, r1, r0
	ldr r3, [sp, #0x28]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #1
	b _0800697A
_08006968:
	mov r6, sl
	ldrb r0, [r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, [sp]
	ldr r1, [r2, #0x10]
_0800697A:
	adds r7, r1, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _0800698C
	b _080067F8
_0800698C:
	ldr r3, [sp, #0x3c]
	asrs r2, r3, #0x10
	cmp r2, #4
	beq _080069CE
	ldr r6, [sp]
	ldr r0, [r6, #0x14]
	ldrb r0, [r0]
	ldr r1, [sp, #8]
	adds r1, r1, r0
	mov sl, r1
	mov r3, sl
	str r3, [sp, #8]
	ldrb r1, [r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r6, #0x10]
	adds r0, r0, r1
	ldr r6, [sp, #0x1c]
	adds r7, r0, r6
	mov r0, r8
	lsrs r1, r0, #0x10
	movs r3, #0
	str r3, [sp, #0xc]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _080069CE
	b _080067E8
_080069CE:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
