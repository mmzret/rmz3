	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _08029AD8 @ =0x00000119
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029ADC
	movs r1, #0
	movs r0, #5
	b _08029BAC
	.align 2, 0
_08029AD8: .4byte 0x00000119
_08029ADC:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrb r0, [r1]
	movs r3, #1
	ands r3, r0
	mov ip, r1
	cmp r3, #0
	beq _08029AF0
	b _08029C54
_08029AF0:
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #0x17
	ands r1, r0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r5, r4, r0
	cmp r1, #0
	beq _08029B1E
	ldr r0, [r5]
	movs r1, #0x86
	lsls r1, r1, #3
	ands r0, r1
	subs r1, #0x30
	cmp r0, r1
	bne _08029B1E
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	b _08029C54
_08029B1E:
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	beq _08029B3C
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08029B3C
	movs r1, #0
	movs r0, #9
	b _08029BAC
_08029B3C:
	ldr r0, [r2]
	cmp r0, #0
	bge _08029B5C
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08029B5C
	movs r0, #0
	movs r1, #0xa
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	movs r0, #1
	strb r0, [r4, #0xf]
	b _08029C54
_08029B5C:
	adds r7, r4, #0
	adds r7, #0xb4
	ldr r2, [r5]
	movs r6, #1
	adds r0, r2, #0
	ands r0, r6
	cmp r0, #0
	beq _08029BB4
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	beq _08029BA8
	ldr r1, _08029BA0 @ =gZeroRanges
	adds r0, r4, #0
	movs r2, #0
	bl IsOnSoftPlatform
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08029BA8
	ldr r2, _08029BA4 @ =0x00000113
	adds r1, r4, r2
	movs r0, #0
	strb r6, [r1]
	ldr r1, [r4, #0x58]
	movs r2, #0xd0
	lsls r2, r2, #4
	adds r1, r1, r2
	str r1, [r7, #0x60]
	strb r6, [r4, #0xd]
	movs r1, #2
	strb r1, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _08029C54
	.align 2, 0
_08029BA0: .4byte gZeroRanges
_08029BA4: .4byte 0x00000113
_08029BA8:
	movs r1, #0
	movs r0, #1
_08029BAC:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	strb r1, [r4, #0xf]
	b _08029C54
_08029BB4:
	mov r0, ip
	ldrb r1, [r0]
	movs r7, #2
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08029BE8
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	beq _08029BE8
	ldr r1, _08029BE4 @ =gZeroRanges+8
	adds r0, r4, #0
	bl TryGroundDash
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08029BE8
	strb r7, [r4, #0xe]
	strb r6, [r4, #0xf]
	b _08029C54
	.align 2, 0
_08029BE4: .4byte gZeroRanges+8
_08029BE8:
	ldr r1, [r5]
	movs r6, #0x30
	ands r6, r1
	cmp r6, #0
	beq _08029BFC
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xe]
	strb r1, [r4, #0xf]
	b _08029C54
_08029BFC:
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08029C54
	movs r5, #0x80
	ands r5, r1
	cmp r5, #0
	beq _08029C34
	ldr r1, _08029C30 @ =gZeroRanges
	adds r0, r4, #0
	movs r2, #0
	bl TryLadderDown
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08029C54
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	strb r6, [r4, #0xf]
	b _08029C54
	.align 2, 0
_08029C30: .4byte gZeroRanges
_08029C34:
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	beq _08029C54
	ldr r1, _08029C5C @ =gZeroRanges
	adds r0, r4, #0
	movs r2, #0
	bl TryLadderUp
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08029C54
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	strb r5, [r4, #0xf]
_08029C54:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029C5C: .4byte gZeroRanges
