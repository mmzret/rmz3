	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #6]
	subs r0, #1
	strb r0, [r2, #6]
	lsls r0, r0, #0x18
	asrs r3, r0, #0x18
	cmp r3, #0
	bne _0800504A
	ldrb r5, [r2, #5]
	adds r0, r5, #1
	strb r0, [r2, #5]
	ldrb r0, [r2, #4]
	ldr r7, [r2]
	lsls r0, r0, #2
	adds r6, r0, r7
	movs r0, #5
	ldrsb r0, [r2, r0]
	ldr r1, [r6]
	lsls r0, r0, #1
	adds r4, r0, r1
	movs r1, #1
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	mov ip, r0
	cmp r1, ip
	bne _08004FEA
	strb r5, [r2, #5]
	movs r0, #1
	strb r0, [r2, #6]
	movs r0, #3
	b _08005080
_08004FEA:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08004FF8
	ldrb r0, [r4]
	strb r0, [r2, #5]
	strb r3, [r2, #7]
_08004FF8:
	movs r0, #5
	ldrsb r0, [r2, r0]
	ldr r1, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r3, [r0, #1]
	strb r3, [r2, #6]
	ldrb r0, [r2, #5]
	adds r0, #1
	strb r0, [r2, #5]
	ldrb r0, [r2, #4]
	lsls r0, r0, #2
	adds r0, r0, r7
	movs r1, #5
	ldrsb r1, [r2, r1]
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrb r1, [r1, #1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	bge _08005042
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _08005040
	cmp r0, #1
	bne _0800503E
	cmp r1, ip
	bne _0800503A
	movs r0, #3
	b _08005040
_0800503A:
	movs r0, #4
	b _08005040
_0800503E:
	movs r0, #1
_08005040:
	strb r0, [r2, #7]
_08005042:
	ldrb r0, [r2, #5]
	subs r0, #1
	strb r0, [r2, #5]
	b _08005082
_0800504A:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08005082
	cmp r3, #2
	bne _08005058
	strb r3, [r2, #7]
	b _08005082
_08005058:
	cmp r3, #1
	bne _08005082
	ldrb r1, [r2, #4]
	ldr r0, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #5
	ldrsb r0, [r2, r0]
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #3
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0800507E
	movs r0, #3
	b _08005080
_0800507E:
	movs r0, #4
_08005080:
	strb r0, [r2, #7]
_08005082:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
