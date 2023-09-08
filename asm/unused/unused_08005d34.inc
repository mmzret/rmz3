	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	str r0, [sp]
	adds r6, r1, #0
	str r2, [sp, #4]
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov sb, r0
	movs r1, #0xf
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r4, #4
	ldr r2, [sp]
	ldr r5, [r2, #0x14]
	adds r4, r5, r4
	movs r0, #2
	ldrsh r3, [r6, r0]
	mov r8, r3
	movs r1, #0xa
	mov sl, r1
	mov r0, r8
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r5]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #8]
	mov r0, sb
	movs r1, #0xf
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r0, r8
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	ldrb r2, [r4]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r5, [sp]
	ldr r3, [r5, #0x10]
	adds r3, r3, r2
	ldr r1, [sp, #0xc]
	lsls r4, r1, #0x10
	asrs r5, r4, #0x10
	lsls r1, r5, #1
	adds r3, r3, r1
	lsrs r2, r0, #0x10
	str r2, [sp, #0x10]
	asrs r2, r0, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r7, r3, r0
	movs r3, #0
	mov sb, r3
	mov r8, r3
	mov r0, sl
	subs r0, r0, r2
	cmp sb, r0
	bge _08005EA6
	movs r1, #6
	ldrsh r0, [r6, r1]
	str r4, [sp, #0x40]
	cmp sb, r0
	bge _08005EA6
	str r4, [sp, #0x30]
	movs r3, #0xf
	subs r5, r3, r5
	str r5, [sp, #0x34]
	str r2, [sp, #0x1c]
_08005DE0:
	ldrh r1, [r6, #2]
	lsls r1, r1, #4
	mov r5, sb
	lsls r0, r5, #0x10
	asrs r0, r0, #0xc
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r0, #0
	mov r8, r0
	ldr r1, [sp, #0x34]
	cmp r8, r1
	bge _08005E76
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r8, r0
	bge _08005E76
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r5, [sp, #0x4c]
	ands r5, r0
	str r5, [sp, #0x4c]
	ldr r0, [sp, #0x30]
	asrs r0, r0, #0x10
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sl, r1
_08005E1E:
	ldrh r2, [r6]
	mov r5, r8
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	adds r2, r2, r3
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r1, [sp]
	ldr r4, [r1, #0xc]
	adds r4, r4, r0
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	mov r8, r5
	asrs r1, r3, #0x10
	movs r2, #0xf
	mov r3, ip
	subs r0, r2, r3
	cmp r1, r0
	bge _08005E76
	movs r5, #4
	ldrsh r0, [r6, r5]
	cmp r1, r0
	blt _08005E1E
_08005E76:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r2, #0xf
	subs r0, r2, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r3, sb
	lsls r0, r3, #0x10
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r0, r5
	lsrs r1, r0, #0x10
	mov sb, r1
	asrs r1, r0, #0x10
	movs r0, #0xa
	ldr r2, [sp, #0x1c]
	subs r0, r0, r2
	cmp r1, r0
	bge _08005EA6
	movs r3, #6
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08005DE0
_08005EA6:
	ldr r5, [sp, #8]
	adds r5, #1
	str r5, [sp, #8]
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [sp]
	ldr r3, [r0, #0x10]
	adds r1, r3, r1
	ldr r5, [sp, #0x10]
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r7, r1, r0
	mov r0, r8
	lsls r1, r0, #0x10
	lsrs r5, r1, #0x10
	str r5, [sp, #0x14]
	movs r0, #0
	mov sb, r0
	movs r0, #0xa
	subs r4, r0, r2
	ldr r2, [sp]
	ldr r2, [r2, #0x14]
	str r2, [sp, #0x48]
	str r3, [sp, #0x44]
	ldr r3, [sp, #0xc]
	lsls r3, r3, #0x10
	str r3, [sp, #0x40]
	ldrh r3, [r6, #6]
	adds r2, r1, #0
	cmp sb, r4
	bge _08005FB8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp sb, r0
	bge _08005FB8
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x24]
	str r4, [sp, #0x20]
_08005F02:
	ldrh r1, [r6, #2]
	lsls r1, r1, #4
	mov r5, sb
	lsls r0, r5, #0x10
	asrs r0, r0, #0xc
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	ldr r0, [sp, #0x14]
	mov r8, r0
	lsls r4, r0, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bge _08005F86
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r5, [sp, #0x4c]
	ands r5, r0
	str r5, [sp, #0x4c]
	ldr r0, [sp]
	ldr r0, [r0, #0xc]
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sl, r1
_08005F3E:
	ldrh r2, [r6]
	asrs r4, r4, #0x10
	adds r2, r2, r4
	ldrh r3, [r7]
	lsls r3, r3, #3
	add r3, ip
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r4, r4, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08005F3E
_08005F86:
	mov r5, r8
	lsls r2, r5, #0x10
	asrs r1, r2, #0x10
	ldr r0, [sp, #0x24]
	subs r1, r1, r0
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r1, sb
	lsls r0, r1, #0x10
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r0, r3
	lsrs r5, r0, #0x10
	mov sb, r5
	asrs r1, r0, #0x10
	ldrh r3, [r6, #6]
	ldr r0, [sp, #0x20]
	cmp r1, r0
	bge _08005FB8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _08005F02
_08005FB8:
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r5, [sp, #8]
	adds r0, r5, r0
	subs r0, #1
	str r0, [sp, #8]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x44]
	adds r0, r1, r0
	ldr r5, [sp, #0x40]
	asrs r4, r5, #0x10
	lsls r1, r4, #1
	adds r7, r0, r1
	mov r0, sb
	str r0, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r5, r0, #0x10
	lsls r0, r3, #0x10
	cmp r5, r0
	bge _080060B6
	ldr r1, [sp, #0x40]
	str r1, [sp, #0x38]
	movs r2, #0xf
	subs r4, r2, r4
	str r4, [sp, #0x3c]
_08005FF8:
	ldrh r0, [r6, #2]
	lsls r0, r0, #4
	asrs r1, r5, #0xc
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0
	mov r8, r3
	mov r5, sb
	lsls r5, r5, #0x10
	mov ip, r5
	ldr r0, [sp, #0x3c]
	cmp r8, r0
	bge _08006090
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r8, r0
	bge _08006090
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r2, [sp, #0x4c]
	ands r2, r0
	str r2, [sp, #0x4c]
	ldr r3, [sp, #0x38]
	asrs r3, r3, #0x10
	mov sb, r3
	movs r5, #0x80
	lsls r5, r5, #1
	mov sl, r5
_08006038:
	ldrh r2, [r6]
	mov r0, r8
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	adds r2, r2, r3
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r1, [sp]
	ldr r4, [r1, #0xc]
	adds r4, r4, r0
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	mov r8, r5
	asrs r1, r3, #0x10
	movs r2, #0xf
	mov r3, sb
	subs r0, r2, r3
	cmp r1, r0
	bge _08006090
	movs r5, #4
	ldrsh r0, [r6, r5]
	cmp r1, r0
	blt _08006038
_08006090:
	mov r0, r8
	lsls r2, r0, #0x10
	asrs r0, r2, #0x10
	movs r1, #0xf
	subs r0, r1, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r5, r0, #0x10
	asrs r1, r5, #0x10
	movs r3, #6
	ldrsh r0, [r6, r3]
	ldrh r3, [r6, #6]
	cmp r1, r0
	blt _08005FF8
_080060B6:
	ldr r5, [sp, #8]
	ldrb r0, [r5, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x44]
	adds r7, r1, r0
	lsrs r2, r2, #0x10
	str r2, [sp, #0x14]
	ldr r2, [sp, #0x18]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r2, r0, #0x10
	lsls r0, r3, #0x10
	cmp r2, r0
	bge _08006192
	ldr r3, [sp, #0x14]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x28]
_080060E4:
	ldrh r0, [r6, #2]
	lsls r0, r0, #4
	asrs r1, r2, #0xc
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r5, [sp, #0x14]
	mov r8, r5
	lsls r4, r5, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	mov r5, sb
	lsls r5, r5, #0x10
	mov ip, r5
	cmp r1, r0
	bge _0800616A
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r1, [sp, #0x4c]
	ands r1, r0
	str r1, [sp, #0x4c]
	ldr r2, [sp]
	ldr r2, [r2, #0xc]
	mov sb, r2
	movs r3, #0x80
	lsls r3, r3, #1
	mov sl, r3
_08006122:
	ldrh r2, [r6]
	asrs r4, r4, #0x10
	adds r2, r2, r4
	ldrh r3, [r7]
	lsls r3, r3, #3
	add r3, sb
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r4, r4, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08006122
_0800616A:
	mov r5, r8
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r0, [sp, #0x28]
	subs r1, r1, r0
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r7, r7, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r2, r0, #0x10
	asrs r1, r2, #0x10
	movs r3, #6
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _080060E4
_08006192:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
