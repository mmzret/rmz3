	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0xb4
	adds r0, r0, r4
	mov r8, r0
	ldr r1, _08029C80 @ =0x00000119
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029C84
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	b _08029D26
	.align 2, 0
_08029C80: .4byte 0x00000119
_08029C84:
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r3, [r0]
	movs r6, #1
	adds r5, r6, #0
	ands r5, r3
	cmp r5, #0
	bne _08029D2A
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, [r1]
	adds r0, r2, #0
	ands r0, r6
	adds r7, r1, #0
	cmp r0, #0
	beq _08029CEC
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	beq _08029CE4
	ldr r1, _08029CDC @ =gZeroRanges
	adds r0, r4, #0
	movs r2, #0
	bl IsOnSoftPlatform
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08029CE4
	ldr r1, _08029CE0 @ =0x00000113
	adds r0, r4, r1
	strb r6, [r0]
	ldr r0, [r4, #0x58]
	movs r1, #0xd0
	lsls r1, r1, #4
	adds r0, r0, r1
	mov r1, r8
	str r0, [r1, #0x60]
	strb r6, [r4, #0xd]
	movs r0, #2
	strb r0, [r4, #0xe]
	strb r5, [r4, #0xf]
	b _08029D2A
	.align 2, 0
_08029CDC: .4byte gZeroRanges
_08029CE0: .4byte 0x00000113
_08029CE4:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	b _08029D26
_08029CEC:
	movs r6, #2
	adds r0, r6, #0
	ands r0, r3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08029D1C
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	beq _08029D1C
	ldr r1, _08029D18 @ =gZeroRanges+8
	adds r0, r4, #0
	bl TryGroundDash
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08029D1C
	strb r6, [r4, #0xe]
	strb r5, [r4, #0xf]
	b _08029D2A
	.align 2, 0
_08029D18: .4byte gZeroRanges+8
_08029D1C:
	ldr r1, [r7]
	movs r0, #0x30
	ands r1, r0
	cmp r1, #0
	bne _08029D2A
_08029D26:
	strb r1, [r4, #0xe]
	strb r1, [r4, #0xf]
_08029D2A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
