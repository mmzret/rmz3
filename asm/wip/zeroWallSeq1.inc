	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0802B63C @ =0x00000147
	adds r5, r4, r0
	movs r0, #2
	strb r0, [r5]
	ldr r6, _0802B640 @ =gZeroRanges
	adds r1, r6, #0
	adds r1, #0x10
	adds r0, r4, #0
	movs r2, #0
	bl GetWallMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _0802B644
	adds r0, r4, #0
	bl InstantlyKilling
	adds r0, r4, #0
	bl zeroDamaged
	b _0802B732
	.align 2, 0
_0802B63C: .4byte 0x00000147
_0802B640: .4byte gZeroRanges
_0802B644:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802B65C
	ldr r0, [r4, #0x54]
	adds r1, #0xf0
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0802B65C:
	ldr r0, [r2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802B66E
	ldr r0, [r4, #0x54]
	ldr r1, _0802B6C0 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0802B66E:
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r0, r4, #0
	movs r2, #0
	bl PushoutWallX
	adds r0, r4, #0
	bl getWallFallSpeed
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	cmp r1, #0
	beq _0802B6C4
	adds r1, r4, #0
	adds r1, #0xf8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0802B6F6
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl CreateWallDust
	movs r0, #9
	bl PlaySound
	b _0802B6F6
	.align 2, 0
_0802B6C0: .4byte 0xFFFFFF00
_0802B6C4:
	adds r0, r4, #0
	adds r0, #0xf8
	strb r1, [r0]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	movs r0, #0xa0
	lsls r0, r0, #3
	cmp r1, r0
	bne _0802B6F6
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _0802B6F6
	adds r0, r4, #0
	movs r2, #5
	movs r3, #2
	bl GotoMotion
_0802B6F6:
	ldr r0, _0802B738 @ =0x00000147
	adds r5, r4, r0
	ldrb r1, [r5]
	lsls r1, r1, #3
	ldr r6, _0802B73C @ =gZeroRanges
	adds r1, r1, r6
	adds r0, r4, #0
	movs r2, #1
	bl PushoutByFloor
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B732
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r0, r4, #0
	movs r2, #0
	bl zero_080264dc
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B732
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	movs r0, #7
	bl PlaySound
_0802B732:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802B738: .4byte 0x00000147
_0802B73C: .4byte gZeroRanges
