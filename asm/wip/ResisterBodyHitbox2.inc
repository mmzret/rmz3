	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov ip, r1
	ldr r3, [r4]
	ldr r5, [r4, #8]
	adds r6, r4, #0
	adds r6, #0x20
	ldrb r2, [r6]
	movs r1, #0x7f
	ands r1, r2
	cmp r1, #0
	beq _08007388
	movs r0, #0x80
	ands r0, r2
	subs r1, #1
	orrs r0, r1
	strb r0, [r6]
_08007388:
	cmp r3, #0
	beq _08007456
	ldrb r0, [r3, #3]
	cmp r0, #0
	bne _080073A0
	ldrb r1, [r3, #8]
	cmp r1, #0
	bne _080073A0
	ldr r0, [r4, #0x18]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x18]
	b _08007456
_080073A0:
	ldr r0, _080073E8 @ =gCollisionManager
	ldrb r1, [r0, #3]
	mov sb, r0
	cmp r1, #0x3f
	bhi _0800744E
	mov r6, sb
	movs r0, #1
	mov r1, ip
	ands r1, r0
	mov r8, r1
	ldr r7, _080073EC @ =0x00000604
	add r7, sb
	movs r0, #2
	mov r1, ip
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
_080073C4:
	ldrb r0, [r6, #3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r2, r6, #4
	adds r2, r1, r2
	adds r0, #1
	strb r0, [r6, #3]
	str r4, [r2, #8]
	str r3, [r2, #4]
	mov r0, r8
	cmp r0, #0
	beq _080073F0
	movs r0, #0x10
	ldrsh r1, [r3, r0]
	ldr r0, [r5]
	subs r0, r0, r1
	b _080073F8
	.align 2, 0
_080073E8: .4byte gCollisionManager
_080073EC: .4byte 0x00000604
_080073F0:
	movs r0, #0x10
	ldrsh r1, [r3, r0]
	ldr r0, [r5]
	adds r0, r0, r1
_080073F8:
	str r0, [r2, #0xc]
	mov r1, ip
	cmp r1, #0
	beq _0800740A
	movs r0, #0x12
	ldrsh r1, [r3, r0]
	ldr r0, [r5, #4]
	subs r0, r0, r1
	b _08007412
_0800740A:
	movs r0, #0x12
	ldrsh r1, [r3, r0]
	ldr r0, [r5, #4]
	adds r0, r0, r1
_08007412:
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
	beq _0800744E
	adds r3, #0x18
	mov r1, sb
	ldrb r0, [r1, #3]
	cmp r0, #0x3f
	bls _080073C4
_0800744E:
	ldr r0, [r4, #0x18]
	str r0, [r4, #0x1c]
	movs r0, #0
	str r0, [r4, #0x18]
_08007456:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
