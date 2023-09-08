	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	ldr r2, [sp]
	ldr r5, [r2, #0x14]
	adds r4, r5, r4
	ldr r6, [sp, #0x14]
	adds r0, r6, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r5]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #0xc]
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __modsi3
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	adds r0, r6, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldrb r2, [r4]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r7, [sp]
	ldr r3, [r7, #0x10]
	adds r3, r3, r2
	ldr r2, [sp, #0x18]
	lsls r1, r2, #0x10
	asrs r2, r1, #0x10
	lsls r1, r2, #1
	adds r3, r3, r1
	lsrs r7, r0, #0x10
	str r7, [sp, #0x1c]
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r6, r3, r1
	movs r1, #0
	mov ip, r1
	movs r7, #0
	movs r1, #0xa
	subs r1, r1, r0
	cmp ip, r1
	bge _080057A0
	mov r3, sp
	ldrh r7, [r3, #0x14]
	strh r7, [r3, #0x2c]
	movs r0, #0xf
	subs r2, r0, r2
	mov sl, r2
	str r1, [sp, #0x28]
_08005710:
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0xc
	mov r2, sp
	ldrh r2, [r2, #0x2c]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r7, #0
	cmp r7, sl
	bge _0800577E
	mov r3, sp
	ldrh r3, [r3, #0x10]
	mov sb, r3
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r0, [sp]
	ldr r0, [r0, #0xc]
	mov r8, r0
_0800573C:
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #4
	add r2, sb
	ldrh r4, [r6]
	lsls r4, r4, #3
	add r4, r8
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	movs r7, #0x80
	lsls r7, r7, #1
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, sl
	blt _0800573C
_0800577E:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r3, #0xf
	subs r0, r3, r0
	lsls r0, r0, #1
	adds r6, r6, r0
	mov r1, ip
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r3, r0, #0x10
	mov ip, r3
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x28]
	cmp r0, r1
	blt _08005710
_080057A0:
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [sp]
	ldr r3, [r0, #0x10]
	adds r1, r3, r1
	ldr r0, [sp, #0x1c]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r6, r1, r0
	lsls r1, r7, #0x10
	lsrs r7, r1, #0x10
	str r7, [sp, #0x20]
	movs r0, #0
	mov ip, r0
	movs r0, #0xa
	subs r0, r0, r2
	ldr r2, [sp]
	ldr r2, [r2, #0x14]
	str r2, [sp, #0x50]
	str r3, [sp, #0x4c]
	ldr r3, [sp, #0x18]
	lsls r3, r3, #0x10
	str r3, [sp, #0x54]
	adds r2, r1, #0
	cmp ip, r0
	bge _08005894
	mov r7, sp
	ldrh r1, [r7, #0x14]
	strh r1, [r7, #0x34]
	ldr r2, [sp, #0x20]
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #0x38]
	str r0, [sp, #0x30]
_080057F8:
	mov r3, ip
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	mov r7, sp
	ldrh r7, [r7, #0x34]
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r7, [sp, #0x20]
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	cmp r0, #0xf
	bgt _0800586E
	mov r0, sp
	ldrh r0, [r0, #0x10]
	mov sb, r0
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r1, [sp]
	ldr r1, [r1, #0xc]
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #1
	mov sl, r2
_0800582E:
	asrs r4, r4, #0x10
	lsls r2, r4, #4
	add r2, sb
	ldrh r3, [r6]
	lsls r3, r3, #3
	add r3, r8
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	mov r7, sl
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	cmp r0, #0xf
	ble _0800582E
_0800586E:
	lsls r2, r7, #0x10
	asrs r1, r2, #0x10
	ldr r3, [sp, #0x38]
	subs r1, r1, r3
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r6, r6, r0
	mov r7, ip
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r3, r0, #0x10
	mov ip, r3
	asrs r0, r0, #0x10
	ldr r7, [sp, #0x30]
	cmp r0, r7
	blt _080057F8
_08005894:
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	subs r0, #1
	str r0, [sp, #0xc]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x4c]
	adds r0, r7, r0
	ldr r1, [sp, #0x54]
	asrs r3, r1, #0x10
	lsls r1, r3, #1
	adds r6, r0, r1
	mov r7, ip
	str r7, [sp, #0x24]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r5, r0, #0x10
	asrs r0, r5, #0x10
	cmp r0, #0xa
	bgt _0800596E
	mov r0, sp
	ldrh r1, [r0, #0x14]
	strh r1, [r0, #0x3c]
	movs r2, #0xf
	subs r3, r2, r3
	str r3, [sp, #0x48]
_080058D6:
	asrs r0, r5, #0xc
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r7, #0
	mov r0, ip
	lsls r0, r0, #0x10
	mov sl, r0
	ldr r2, [sp, #0x48]
	cmp r7, r2
	bge _0800594E
	mov r3, sp
	ldrh r3, [r3, #0x10]
	mov sb, r3
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r0, [sp]
	ldr r0, [r0, #0xc]
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov ip, r1
_0800590C:
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #4
	add r2, sb
	ldrh r4, [r6]
	lsls r4, r4, #3
	add r4, r8
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	mov r7, ip
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	asrs r3, r3, #0x10
	ldr r0, [sp, #0x48]
	cmp r3, r0
	blt _0800590C
_0800594E:
	lsls r1, r7, #0x10
	asrs r0, r1, #0x10
	movs r2, #0xf
	subs r0, r2, r0
	lsls r0, r0, #1
	adds r6, r6, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r5, r0, #0x10
	asrs r0, r5, #0x10
	adds r2, r1, #0
	cmp r0, #0xa
	ble _080058D6
_0800596E:
	ldr r3, [sp, #0xc]
	ldrb r0, [r3, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x4c]
	adds r6, r7, r0
	lsrs r2, r2, #0x10
	str r2, [sp, #0x20]
	ldr r1, [sp, #0x24]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xa
	bgt _08005A3E
	mov r2, sp
	ldrh r2, [r2, #0x14]
	add r3, sp, #0x40
	strh r2, [r3]
	ldr r7, [sp, #0x20]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #0x44]
_080059A4:
	asrs r0, r1, #0xc
	add r1, sp, #0x40
	ldrh r1, [r1]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r7, [sp, #0x20]
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	mov r2, ip
	lsls r2, r2, #0x10
	mov sl, r2
	cmp r0, #0xf
	bgt _08005A1C
	mov r3, sp
	ldrh r3, [r3, #0x10]
	mov r8, r3
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r7, [sp]
	ldr r7, [r7, #0xc]
	mov ip, r7
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
_080059DC:
	asrs r4, r4, #0x10
	lsls r2, r4, #4
	add r2, r8
	ldrh r3, [r6]
	lsls r3, r3, #3
	add r3, ip
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	mov r7, sb
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	cmp r0, #0xf
	ble _080059DC
_08005A1C:
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #0x44]
	subs r1, r1, r3
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r6, r6, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xa
	ble _080059A4
_08005A3E:
	ldr r7, [sp, #4]
	ldr r3, [r7]
	ldr r2, _08005A6C @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	ldr r1, [sp]
	strh r0, [r1, #8]
	ldr r1, [r7, #4]
	adds r0, r1, #0
	ands r0, r2
	ldr r2, [sp]
	strh r0, [r2, #0xa]
	str r3, [r2]
	str r1, [r2, #4]
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005A6C: .4byte 0x000001FF
