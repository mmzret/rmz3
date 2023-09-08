	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	mov sb, r1
	bl setCurProcessedEntityHeader
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #4]
	str r0, [r6, #0xc]
	adds r5, r0, #0
	adds r0, r6, #0
	adds r0, #0x14
	cmp r5, r0
	beq _080171A4
	movs r0, #1
	mov r8, r0
_080170B0:
	ldrb r1, [r5, #0xa]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _08017194
	adds r4, r5, #0
	adds r4, #0x34
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08017184
	ldr r0, _080170EC @ =0x0202F360
	ldrb r1, [r5, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	mov r1, r8
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080170F0
	ldrb r0, [r4, #0x15]
	movs r1, #0xf
	ands r1, r0
	movs r0, #0xd0
	b _080170FE
	.align 2, 0
_080170EC: .4byte 0x0202F360
_080170F0:
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldrb r2, [r4, #0x15]
	movs r1, #0xf
	ands r1, r2
_080170FE:
	orrs r1, r0
	strb r1, [r4, #0x15]
	ldrb r1, [r5, #0xa]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0801716E
	ldr r3, _08017150 @ =0x0202F354
	ldrb r2, [r3]
	movs r0, #0x1f
	ands r2, r0
	lsls r2, r2, #1
	ldrb r0, [r4, #0x13]
	movs r7, #0x3f
	rsbs r7, r7, #0
	adds r1, r7, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, #0x13]
	ldrb r0, [r3]
	cmp r0, #0x1e
	bhi _0801712E
	adds r0, #1
	strb r0, [r3]
_0801712E:
	ldrb r1, [r5, #0xb]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _08017162
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08017154
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r1, [r0]
	adds r0, r4, #0
	bl ScalerotSprite
	b _0801716E
	.align 2, 0
_08017150: .4byte 0x0202F354
_08017154:
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r1, [r0]
	adds r0, r4, #0
	bl ScalerotSprite
	b _0801716E
_08017162:
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r1, [r0]
	adds r0, r4, #0
	bl RotateSprite
_0801716E:
	ldrb r2, [r4, #0x15]
	lsls r2, r2, #0x1c
	lsrs r2, r2, #0x1e
	adds r0, r5, #0
	adds r0, #0x25
	ldrb r3, [r0]
	mov r0, sb
	adds r1, r4, #0
	bl AppendTask
	b _08017194
_08017184:
	adds r0, r5, #0
	adds r0, #0x25
	ldrb r3, [r0]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl AppendTask
_08017194:
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #4]
	str r0, [r6, #0xc]
	adds r5, r0, #0
	adds r0, r6, #0
	adds r0, #0x14
	cmp r5, r0
	bne _080170B0
_080171A4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
