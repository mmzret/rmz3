	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	mov sb, r1
	ldr r7, [r0, #8]
	ldr r0, [r1, #8]
	mov sl, r0
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080080C4
	mov r1, sb
	ldrh r5, [r1, #0x14]
	ldr r4, [r1, #0xc]
	subs r2, r4, r5
	ldr r1, [r7, #8]
	movs r3, #0x34
	ldrsh r0, [r7, r3]
	lsls r0, r0, #8
	ldr r3, [r1]
	adds r0, r3, r0
	cmp r2, r0
	ble _080080B4
	b _080082D2
_080080B4:
	adds r1, r4, r5
	movs r2, #0x32
	ldrsh r0, [r7, r2]
	lsls r0, r0, #8
	adds r0, r3, r0
	cmp r1, r0
	bge _080080C4
	b _080082D2
_080080C4:
	movs r0, #0
	str r0, [r7, #0x14]
	mov r3, sl
	str r0, [r3, #0x14]
	mov r1, r8
	ldr r0, [r1, #4]
	str r0, [r7, #4]
	mov r2, sb
	ldr r0, [r2, #4]
	str r0, [r3, #4]
	adds r2, r7, #0
	adds r2, #0x36
	ldrb r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080080F4
	mov r3, r8
	ldr r0, [r3, #4]
	ldrb r0, [r0, #3]
	adds r1, r7, #0
	adds r1, #0x37
	strb r0, [r1]
_080080F4:
	ldrb r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0800810C
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r1, [r0, #5]
	adds r0, r7, #0
	adds r0, #0x38
	strb r1, [r0]
_0800810C:
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08008122
	mov r3, r8
	ldr r0, [r3, #4]
	ldrb r0, [r0, #6]
	adds r1, r7, #0
	adds r1, #0x39
	strb r0, [r1]
_08008122:
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08008138
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0, #7]
	adds r1, r7, #0
	adds r1, #0x3a
	strb r0, [r1]
_08008138:
	ldrb r1, [r2]
	movs r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0800814C
	mov r2, r8
	ldr r0, [r2, #4]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x3c]
	b _08008204
_0800814C:
	mov r3, r8
	ldr r1, [r3, #4]
	ldrb r0, [r1, #4]
	cmp r0, #3
	bhi _08008188
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r3, [r0]
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	bne _08008182
	ldrb r1, [r1, #4]
	lsls r0, r1, #2
	adds r2, r0, r1
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _0800817E
	adds r0, r1, #1
	adds r0, r2, r0
	b _080081A6
_0800817E:
	adds r0, r2, r1
	b _080081A6
_08008182:
	movs r1, #0x80
	lsls r1, r1, #0x18
	b _08008202
_08008188:
	cmp r0, #4
	beq _080081FE
	cmp r0, #7
	bhi _08008196
	ldrb r0, [r1, #4]
	subs r0, #3
	b _080081A6
_08008196:
	cmp r0, #0xb
	bhi _080081B0
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	cmp r0, #0
	beq _080081AC
	adds r0, #6
_080081A6:
	adds r1, r4, #0
	lsls r1, r0
	b _08008202
_080081AC:
	movs r1, #0x40
	b _08008202
_080081B0:
	cmp r0, #0xc
	beq _080081F8
	cmp r0, #0xd
	bne _080081CC
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xe
	cmp r0, #2
	bne _08008202
	movs r1, #0x80
	lsls r1, r1, #0xf
	b _08008202
_080081CC:
	cmp r0, #0xe
	bne _080081E4
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, #1
	bne _08008202
	movs r1, #0x80
	lsls r1, r1, #0xa
	b _08008202
_080081E4:
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, #3
	bne _08008202
	movs r1, #0x80
	lsls r1, r1, #0xb
	b _08008202
_080081F8:
	movs r1, #0x80
	lsls r1, r1, #1
	b _08008202
_080081FE:
	movs r1, #0x80
	lsls r1, r1, #9
_08008202:
	str r1, [r7, #0x3c]
_08008204:
	adds r0, r7, #0
	mov r1, sl
	bl hitbox_08007674
	ldr r0, [r7, #0x24]
	cmp r0, #0
	bne _0800821A
	mov r1, sl
	ldr r0, [r1, #0x24]
	cmp r0, #0
	beq _080082D2
_0800821A:
	ldr r0, [r7, #0x14]
	cmp r0, #0
	bne _08008228
	mov r2, sl
	ldr r0, [r2, #0x14]
	cmp r0, #0
	beq _080082D2
_08008228:
	mov r3, r8
	ldr r0, [r3, #0xc]
	mov r1, sb
	ldr r5, [r1, #0xc]
	subs r0, r0, r5
	str r0, [sp]
	ldr r4, [r3, #0x10]
	ldr r6, [r1, #0x10]
	subs r4, r4, r6
	str r4, [sp, #4]
	ldrh r2, [r1, #0x14]
	muls r0, r2, r0
	ldrh r1, [r3, #0x14]
	adds r1, r1, r2
	bl __divsi3
	adds r5, r5, r0
	str r5, [sp, #8]
	mov r3, sb
	ldrh r2, [r3, #0x16]
	adds r0, r2, #0
	muls r0, r4, r0
	mov r3, r8
	ldrh r1, [r3, #0x16]
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
	beq _080082AE
	ldr r0, [r7, #0x14]
	cmp r0, #0
	beq _080082AE
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sp
	bl _call_via_r3
_080082AE:
	mov r0, sl
	ldr r3, [r0, #0x24]
	cmp r3, #0
	beq _080082D2
	ldr r0, [r0, #0x14]
	cmp r0, #0
	beq _080082D2
	ldr r0, [sp]
	rsbs r0, r0, #0
	str r0, [sp]
	ldr r0, [sp, #4]
	rsbs r0, r0, #0
	str r0, [sp, #4]
	mov r0, sl
	adds r1, r5, #0
	mov r2, sp
	bl _call_via_r3
_080082D2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
