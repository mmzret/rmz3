	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r4, r0
	adds r0, r4, #0
	bl IsAttackOK
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0802F410
	ldr r2, _0802F40C @ =0x0000012B
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0xec
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xed
	strb r2, [r0]
	b _0802F432
	.align 2, 0
_0802F40C: .4byte 0x0000012B
_0802F410:
	ldr r0, _0802F43C @ =0x0000012B
	adds r2, r4, r0
	ldrb r1, [r2]
	adds r0, r1, #0
	cmp r0, #0xff
	beq _0802F440
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xed
	strb r3, [r0]
_0802F432:
	adds r0, r4, #0
	bl zeroAirAtk
	b _0802F446
	.align 2, 0
_0802F43C: .4byte 0x0000012B
_0802F440:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r2]
_0802F446:
	pop {r4}
	pop {r0}
	bx r0
