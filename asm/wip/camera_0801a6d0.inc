	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0
	cmp r1, #1
	beq _0801A6FA
	cmp r1, #1
	bgt _0801A6E8
	cmp r1, #0
	beq _0801A7AE
	b _0801A6F0
_0801A6E8:
	cmp r0, #2
	beq _0801A73A
	cmp r0, #4
	beq _0801A7A4
_0801A6F0:
	ldrb r1, [r3, #0x19]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r3, #0x19]
	b _0801A7AE
_0801A6FA:
	ldr r0, [r3, #0x30]
	ldr r2, [r3, #0x38]
	subs r1, r0, r2
	cmp r1, #0
	ble _0801A70E
	adds r0, r1, #0
	adds r0, #0x1f
	asrs r0, r0, #5
	adds r0, r2, r0
	b _0801A716
_0801A70E:
	movs r0, #0x1f
	subs r0, r0, r1
	asrs r0, r0, #5
	subs r0, r2, r0
_0801A716:
	str r0, [r3, #0x38]
	ldr r0, [r3, #0x34]
	ldr r2, [r3, #0x3c]
	subs r1, r0, r2
	cmp r1, #0
	ble _0801A72E
	adds r0, r1, #0
	adds r0, #0x1f
	asrs r0, r0, #5
	adds r0, r2, r0
	str r0, [r3, #0x3c]
	b _0801A80A
_0801A72E:
	movs r0, #0x1f
	subs r0, r0, r1
	asrs r0, r0, #5
	subs r0, r2, r0
	str r0, [r3, #0x3c]
	b _0801A80A
_0801A73A:
	ldrh r2, [r3, #0x22]
	movs r0, #0x22
	ldrsh r1, [r3, r0]
	ldr r0, _0801A7A0 @ =0x000003FE
	cmp r1, r0
	bgt _0801A7AE
	adds r0, r2, #1
	strh r0, [r3, #0x22]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	ldr r0, [r3, #0x38]
	asrs r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #3
	subs r2, r1, r4
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r5, [r3, #0x30]
	asrs r0, r5, #2
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	bge _0801A76A
	adds r0, #0xff
_0801A76A:
	asrs r6, r0, #8
	str r6, [r3, #0x38]
	ldr r0, [r3, #0x3c]
	asrs r0, r0, #2
	muls r2, r0, r2
	ldr r1, [r3, #0x34]
	asrs r0, r1, #2
	muls r0, r4, r0
	adds r0, r2, r0
	cmp r0, #0
	bge _0801A782
	adds r0, #0xff
_0801A782:
	asrs r0, r0, #8
	str r0, [r3, #0x3c]
	subs r0, r6, r5
	adds r0, #0x80
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r0, r2
	bhi _0801A794
	str r5, [r3, #0x38]
_0801A794:
	ldr r0, [r3, #0x3c]
	subs r0, r0, r1
	adds r0, #0x80
	cmp r0, r2
	bhi _0801A80A
	b _0801A808
	.align 2, 0
_0801A7A0: .4byte 0x000003FE
_0801A7A4:
	ldrh r1, [r3, #0x22]
	movs r2, #0x22
	ldrsh r0, [r3, r2]
	cmp r0, #0xfe
	ble _0801A7B8
_0801A7AE:
	ldr r0, [r3, #0x30]
	str r0, [r3, #0x38]
	ldr r0, [r3, #0x34]
	str r0, [r3, #0x3c]
	b _0801A80A
_0801A7B8:
	adds r0, r1, #1
	strh r0, [r3, #0x22]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	movs r7, #0x80
	lsls r7, r7, #1
	subs r2, r7, r4
	ldr r0, [r3, #0x38]
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r5, [r3, #0x30]
	adds r0, r5, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	bge _0801A7DA
	adds r0, #0xff
_0801A7DA:
	asrs r6, r0, #8
	str r6, [r3, #0x38]
	ldr r0, [r3, #0x3c]
	muls r2, r0, r2
	ldr r1, [r3, #0x34]
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r2, r0
	cmp r0, #0
	bge _0801A7F0
	adds r0, #0xff
_0801A7F0:
	asrs r0, r0, #8
	str r0, [r3, #0x3c]
	subs r0, r6, r5
	adds r0, #0x80
	cmp r0, r7
	bhi _0801A7FE
	str r5, [r3, #0x38]
_0801A7FE:
	ldr r0, [r3, #0x3c]
	subs r0, r0, r1
	adds r0, #0x80
	cmp r0, r7
	bhi _0801A80A
_0801A808:
	str r1, [r3, #0x3c]
_0801A80A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
