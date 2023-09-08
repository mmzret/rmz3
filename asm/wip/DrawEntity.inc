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
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0x14
	cmp r4, r0
	beq _0801707E
	movs r0, #1
	mov r8, r0
_08016FC8:
	ldrb r1, [r4, #0xa]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _0801706E
	adds r5, r4, #0
	adds r5, #0x34
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0801703E
	ldr r3, _08017020 @ =0x0202F354
	ldrb r2, [r3]
	movs r0, #0x1f
	ands r2, r0
	lsls r2, r2, #1
	ldrb r0, [r5, #0x13]
	movs r7, #0x3f
	rsbs r7, r7, #0
	adds r1, r7, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, #0x13]
	ldrb r0, [r3]
	cmp r0, #0x1e
	bhi _08017000
	adds r0, #1
	strb r0, [r3]
_08017000:
	ldrb r1, [r4, #0xb]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _08017032
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08017024
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	adds r0, r5, #0
	bl ScalerotSprite
	b _0801703E
	.align 2, 0
_08017020: .4byte 0x0202F354
_08017024:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	adds r0, r5, #0
	bl ScalerotSprite
	b _0801703E
_08017032:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	adds r0, r5, #0
	bl RotateSprite
_0801703E:
	ldrb r1, [r4, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801705E
	ldrb r2, [r5, #0x15]
	lsls r2, r2, #0x1c
	lsrs r2, r2, #0x1e
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r3, [r0]
	mov r0, sb
	adds r1, r5, #0
	bl AppendTask
	b _0801706E
_0801705E:
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r3, [r0]
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl AppendTask
_0801706E:
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #4]
	str r0, [r6, #0xc]
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0x14
	cmp r4, r0
	bne _08016FC8
_0801707E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
