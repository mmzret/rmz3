	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	mov sb, r1
	ldr r7, [r0, #8]
	ldr r0, [r1, #8]
	mov r8, r0
	ldr r2, _08007EE0 @ =gCollisionManager
	ldrb r1, [r2]
	movs r3, #0x80
	mov ip, r3
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	beq _08007E50
	b _08008066
_08007E50:
	mov r4, sl
	ldr r3, [r4, #4]
	ldrb r0, [r3, #2]
	cmp r0, #4
	bne _08007E5C
	b _08008066
_08007E5C:
	adds r4, r7, #0
	adds r4, #0x36
	ldrb r1, [r4]
	movs r6, #4
	adds r0, r6, #0
	ands r0, r1
	adds r5, r7, #0
	adds r5, #0x39
	cmp r0, #0
	bne _08007E74
	ldrb r0, [r3, #6]
	strb r0, [r5]
_08007E74:
	ldrb r1, [r5]
	mov r0, ip
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08007E84
	b _08008066
_08007E84:
	str r0, [r7, #0x14]
	mov r1, r8
	str r0, [r1, #0x14]
	mov r3, sl
	ldr r0, [r3, #4]
	str r0, [r7, #4]
	mov r1, sb
	ldr r0, [r1, #4]
	mov r3, r8
	str r0, [r3, #4]
	ldrb r1, [r4]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08007EAA
	mov r4, sl
	ldr r0, [r4, #4]
	ldrb r0, [r0, #6]
	strb r0, [r5]
_08007EAA:
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08007EC0
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r7, #0x32]
	subs r0, #1
	strh r0, [r7, #0x34]
_08007EC0:
	ldr r0, [r7, #8]
	mov r3, r8
	ldr r1, [r3, #8]
	ldr r3, [r0]
	ldr r0, [r1]
	cmp r3, r0
	bge _08007EE4
	mov r4, sb
	ldrh r1, [r4, #0x14]
	ldr r0, [r4, #0xc]
	subs r0, r0, r1
	subs r0, r0, r3
	asrs r0, r0, #8
	strh r0, [r7, #0x34]
	b _08007EF2
	.align 2, 0
_08007EE0: .4byte gCollisionManager
_08007EE4:
	mov r0, sb
	ldrh r1, [r0, #0x14]
	ldr r0, [r0, #0xc]
	adds r0, r0, r1
	subs r0, r0, r3
	asrs r0, r0, #8
	strh r0, [r7, #0x32]
_08007EF2:
	ldr r0, [r7, #4]
	ldrb r1, [r0, #2]
	adds r3, r0, #0
	cmp r1, #1
	bne _08007F1C
	ldrb r0, [r3, #4]
	cmp r0, #0
	beq _08007F1C
	mov r1, r8
	ldr r0, [r1, #0x1c]
	movs r1, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _08007F1C
	mov r2, r8
	str r7, [r2, #0xc]
	ldr r0, [r2, #0x18]
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2, #0x18]
	b _08007F70
_08007F1C:
	mov r4, r8
	ldr r0, [r4, #4]
	ldrb r1, [r0, #9]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08007F3A
	mov r1, r8
	ldr r0, [r1, #0x14]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	mov r1, r8
	str r0, [r1, #0x14]
_08007F3A:
	mov r0, r8
	str r7, [r0, #0xc]
	ldr r0, [r0, #0x14]
	movs r1, #0x40
	orrs r0, r1
	mov r1, r8
	str r0, [r1, #0x14]
	ldrb r0, [r3, #4]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08007F58
	movs r0, #4
	strb r0, [r2, #2]
_08007F58:
	mov r2, r8
	ldr r0, [r2, #4]
	ldrb r1, [r0, #9]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08007F70
	ldr r0, [r7, #0x14]
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	str r0, [r7, #0x14]
_08007F70:
	mov r3, r8
	str r3, [r7, #0xc]
	ldr r0, [r7, #0x14]
	movs r2, #0x20
	orrs r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r7, #0x14]
	ldrb r0, [r5]
	ands r2, r0
	cmp r2, #0
	beq _08007F94
	ldr r0, [r3, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r3, #0x14]
_08007F94:
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x14]
	orrs r0, r1
	str r0, [r7, #0x18]
	mov r4, r8
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x14]
	orrs r0, r1
	str r0, [r4, #0x18]
	ldr r0, [r7, #0x24]
	cmp r0, #0
	bne _08007FB2
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _08008066
_08007FB2:
	ldr r0, [r7, #0x14]
	cmp r0, #0
	bne _08007FBC
	cmp r1, #0
	beq _08008066
_08007FBC:
	mov r1, sl
	ldr r0, [r1, #0xc]
	mov r2, sb
	ldr r5, [r2, #0xc]
	subs r0, r0, r5
	str r0, [sp]
	ldr r4, [r1, #0x10]
	ldr r6, [r2, #0x10]
	subs r4, r4, r6
	str r4, [sp, #4]
	ldrh r2, [r2, #0x14]
	muls r0, r2, r0
	ldrh r1, [r1, #0x14]
	adds r1, r1, r2
	bl __divsi3
	adds r5, r5, r0
	str r5, [sp, #8]
	mov r3, sb
	ldrh r2, [r3, #0x16]
	adds r0, r2, #0
	muls r0, r4, r0
	mov r4, sl
	ldrh r1, [r4, #0x16]
	adds r1, r1, r2
	bl __divsi3
	adds r6, r6, r0
	add r5, sp, #8
	str r6, [r5, #4]
	ldr r0, [sp]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, [sp, #4]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [sp]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	ldr r0, [sp, #4]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp, #4]
	ldr r3, [r7, #0x24]
	cmp r3, #0
	beq _08008042
	ldr r0, [r7, #0x14]
	cmp r0, #0
	beq _08008042
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sp
	bl _call_via_r3
_08008042:
	mov r4, r8
	ldr r3, [r4, #0x24]
	cmp r3, #0
	beq _08008066
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _08008066
	ldr r0, [sp]
	rsbs r0, r0, #0
	str r0, [sp]
	ldr r0, [sp, #4]
	rsbs r0, r0, #0
	str r0, [sp, #4]
	mov r0, r8
	adds r1, r5, #0
	mov r2, sp
	bl _call_via_r3
_08008066:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
