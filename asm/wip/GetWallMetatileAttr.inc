	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r2, #2
	ldrsh r0, [r1, r2]
	ldr r2, [r4, #0x58]
	adds r2, r2, r0
	ldrh r0, [r1, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r2, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080264A6
	ldr r1, [r4, #0x54]
	adds r0, r4, #0
	adds r2, r6, #0
	bl AppendHazardID
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0802649A
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0802649A
	cmp r0, #0xe
	bls _080264A6
_0802649A:
	ldr r1, [r4, #0x54]
	adds r0, r4, #0
	adds r2, r6, #0
	mov r3, sp
	bl _pushoutHazardY
_080264A6:
	ldr r0, [r4, #0x54]
	adds r1, r6, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0xf
	ands r0, r5
	cmp r0, #1
	bne _080264D2
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	bne _080264D2
	ldr r0, [r4, #0x54]
	adds r1, r6, #0
	bl PushoutToDown2
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
_080264D2:
	adds r0, r5, #0
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
