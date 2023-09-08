	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r3, r1, #0
	movs r0, #0
	mov sb, r0
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026730
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r2, [r6, #0x54]
	subs r0, r2, r0
	ldrh r1, [r3, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	adds r0, r0, r1
	str r0, [sp]
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r2, r0
	subs r0, r0, r1
	b _0802674A
_0802672C:
	movs r0, #2
	b _080267E0
_08026730:
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r2, [r6, #0x54]
	adds r0, r2, r0
	ldrh r1, [r3, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	subs r0, r0, r1
	str r0, [sp]
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r0, r2, r0
	adds r0, r0, r1
_0802674A:
	str r0, [sp, #4]
	str r2, [sp, #8]
	movs r1, #2
	ldrsh r0, [r3, r1]
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldrh r0, [r3, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r1, r1, r0
	adds r1, #1
	mov r8, r1
	movs r5, #0
	movs r7, #0xf
	mov r4, sp
_08026768:
	ldr r1, [r4]
	adds r0, r6, #0
	mov r2, r8
	bl AppendHazardID
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08026790
	adds r0, r2, #0
	ands r0, r7
	cmp r0, #0
	beq _08026796
	cmp r0, #0xe
	bls _0802672C
_08026790:
	ands r2, r7
	cmp r2, #0
	bne _080267D2
_08026796:
	adds r4, #4
	adds r5, #1
	cmp r5, #2
	ble _08026768
	movs r5, #0
	mov r4, sp
_080267A2:
	ldr r0, [r4]
	mov r1, r8
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080267D6
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080267D2
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	beq _080267D2
	cmp r0, #0xe
	bhi _080267D2
	movs r1, #1
	mov sb, r1
	b _080267D6
_080267D2:
	movs r0, #0
	b _080267E0
_080267D6:
	adds r4, #4
	adds r5, #1
	cmp r5, #2
	ble _080267A2
	mov r0, sb
_080267E0:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
