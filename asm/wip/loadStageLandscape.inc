	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r1
	ldr r3, _080090BC @ =0x020029E0
	ldrb r1, [r1]
	mov r4, r8
	ldrb r2, [r4, #2]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldrb r1, [r4, #1]
	str r1, [sp, #0x10]
	ldrb r4, [r4, #3]
	movs r1, #4
	add r8, r1
	ldr r1, [r0, #8]
	ldr r0, [r1, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r7, r2, #0
	lsls r0, r7, #4
	subs r0, r0, r7
	strh r0, [r3]
	adds r3, #4
	adds r6, r0, #0
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #1
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #8]
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	ldr r2, _080090C0 @ =0x0100AE08
	mov r0, sp
	adds r1, r3, #0
	str r3, [sp, #0x28]
	bl CpuFastSet
	movs r5, #0
	lsls r0, r4, #0x10
	ldr r3, [sp, #0x28]
	cmp r5, r4
	bge _080090FA
	str r7, [sp, #0x1c]
	str r0, [sp, #0x20]
	mov r2, sb
	lsls r0, r2, #0x10
	mov sl, r6
	asrs r0, r0, #0x10
	str r0, [sp, #0x18]
_08009058:
	movs r2, #0
	lsls r5, r5, #0x10
	str r5, [sp, #0x24]
	ldr r4, [sp, #0x1c]
	cmp r2, r4
	bge _080090D8
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x14]
_08009068:
	mov r1, r8
	ldrb r0, [r1]
	movs r4, #1
	add r8, r4
	ldr r1, [sp, #0x14]
	cmp r0, r1
	beq _080090C4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #8]
	adds r4, r1, r0
	movs r6, #0
	ldr r0, [sp, #0xc]
	lsls r0, r0, #0x10
	mov sb, r0
	lsls r5, r2, #0x10
	mov r1, sl
	lsls r7, r1, #1
_08009092:
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0x1e
	str r3, [sp, #0x28]
	bl Transfer30Bytes
	ldr r3, [sp, #0x28]
	adds r3, r3, r7
	adds r4, #0x1e
	lsls r0, r6, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08009092
	mov r4, sb
	asrs r0, r4, #0xf
	adds r3, r3, r0
	b _080090C8
	.align 2, 0
_080090BC: .4byte 0x020029E0
_080090C0: .4byte 0x0100AE08
_080090C4:
	adds r3, #0x1e
	lsls r5, r2, #0x10
_080090C8:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r5, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	ldr r4, [sp, #0x1c]
	cmp r0, r4
	blt _08009068
_080090D8:
	ldr r0, [sp, #0x18]
	add r8, r0
	mov r1, sl
	lsls r0, r1, #3
	add r0, sl
	lsls r0, r0, #1
	adds r3, r3, r0
	ldr r2, [sp, #0x24]
	movs r4, #0x80
	lsls r4, r4, #9
	adds r1, r2, r4
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [sp, #0x20]
	asrs r0, r2, #0x10
	cmp r1, r0
	blt _08009058
_080090FA:
	ldr r0, _08009118 @ =gOverworld
	movs r4, #0xb0
	lsls r4, r4, #0xa
	adds r0, r0, r4
	movs r1, #0
	strh r1, [r0]
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009118: .4byte gOverworld
