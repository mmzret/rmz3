	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r4, r0, #0
	mov sl, r1
	adds r5, r2, #0
	adds r6, r3, #0
	lsls r5, r5, #0x18
	lsrs r0, r5, #0x18
	mov r8, r0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r1, _08004D70 @ =phantom_minigame_08004d80
	adds r0, r4, #0
	bl SetTaskCallback
	ldrb r0, [r4, #0xd]
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r2, r0
	ldrb r1, [r4, #0x11]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0
	mov sb, r1
	mov r3, sb
	strb r3, [r4, #0x12]
	strb r3, [r4, #0x13]
	movs r1, #0x10
	orrs r2, r1
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #0x11]
	ands r2, r3
	mov r0, sl
	str r0, [r4, #8]
	lsrs r5, r5, #0x1a
	lsls r5, r5, #6
	movs r1, #0x3f
	ands r2, r1
	orrs r2, r5
	movs r0, #3
	mov r3, r8
	ands r3, r0
	lsls r3, r3, #6
	ldrb r0, [r4, #0xf]
	ands r1, r0
	orrs r1, r3
	ldr r0, _08004D74 @ =0x000003FF
	ands r6, r0
	ldrh r3, [r4, #0x10]
	ldr r0, _08004D78 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r6
	strh r0, [r4, #0x10]
	movs r0, #4
	rsbs r0, r0, #0
	ands r2, r0
	strb r2, [r4, #0xd]
	subs r0, #0x3b
	ands r1, r0
	strb r1, [r4, #0xf]
	ldrh r1, [r4, #0xe]
	ldr r0, _08004D7C @ =0xFFFFFE00
	ands r0, r1
	strh r0, [r4, #0xe]
	mov r0, sb
	strb r0, [r4, #0xc]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004D70: .4byte phantom_minigame_08004d80
_08004D74: .4byte 0x000003FF
_08004D78: .4byte 0xFFFFFC00
_08004D7C: .4byte 0xFFFFFE00
