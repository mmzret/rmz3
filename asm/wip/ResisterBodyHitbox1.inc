	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r3, [r4]
	ldr r6, [r4, #8]
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r2, [r5]
	movs r1, #0x7f
	ands r1, r2
	cmp r1, #0
	beq _080072BC
	movs r0, #0x80
	ands r0, r2
	subs r1, #1
	orrs r0, r1
	strb r0, [r5]
_080072BC:
	cmp r3, #0
	beq _0800734E
	ldrb r0, [r3, #3]
	cmp r0, #0
	bne _080072D4
	ldrb r1, [r3, #8]
	cmp r1, #0
	bne _080072D4
	ldr r0, [r4, #0x18]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x18]
	b _0800734E
_080072D4:
	ldr r0, _08007354 @ =gCollisionManager
	ldrb r1, [r0, #3]
	mov ip, r0
	cmp r1, #0x3f
	bhi _08007346
	mov r5, ip
	ldr r7, _08007358 @ =0x00000604
	add r7, ip
_080072E4:
	ldrb r1, [r5, #3]
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	adds r0, r5, #4
	adds r2, r2, r0
	adds r1, #1
	strb r1, [r5, #3]
	str r4, [r2, #8]
	str r3, [r2, #4]
	movs r0, #0x10
	ldrsh r1, [r3, r0]
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r2, #0xc]
	movs r0, #0x12
	ldrsh r1, [r3, r0]
	ldr r0, [r6, #4]
	adds r0, r0, r1
	str r0, [r2, #0x10]
	ldrh r0, [r3, #0x14]
	strh r0, [r2, #0x14]
	ldrh r0, [r3, #0x16]
	strh r0, [r2, #0x16]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r1, [r3, #1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	str r0, [r2]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r1, [r3, #1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	str r2, [r0]
	ldrb r0, [r3, #0xb]
	cmp r0, #0
	beq _08007346
	adds r3, #0x18
	mov r1, ip
	ldrb r0, [r1, #3]
	cmp r0, #0x3f
	bls _080072E4
_08007346:
	ldr r0, [r4, #0x18]
	str r0, [r4, #0x1c]
	movs r0, #0
	str r0, [r4, #0x18]
_0800734E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007354: .4byte gCollisionManager
_08007358: .4byte 0x00000604
