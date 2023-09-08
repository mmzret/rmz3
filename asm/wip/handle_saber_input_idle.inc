	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	movs r1, #0x95
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #0
	strb r1, [r2]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bne _0802D3EA
	adds r0, r4, #0
	b _0802D3EE
_0802D3EA:
	adds r0, r4, #0
	movs r1, #1
_0802D3EE:
	bl GetWeaponCharge
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r2, _0802D424 @ =0x0000022D
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r2, r4, #0
	adds r2, #0xb4
	cmp r0, #3
	bne _0802D406
	movs r1, #2
_0802D406:
	cmp r1, #2
	bne _0802D428
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #4
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl charge_saber_ground
	b _0802D4A2
	.align 2, 0
_0802D424: .4byte 0x0000022D
_0802D428:
	ldrh r1, [r2, #0x12]
	movs r3, #0x40
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0802D45A
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ands r0, r3
	cmp r0, #0
	beq _0802D45A
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #7
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl split_heavens
	b _0802D4A2
_0802D45A:
	ldrh r1, [r2, #0x12]
	movs r2, #0x80
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0802D48C
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _0802D48C
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #6
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl throw_blade
	b _0802D4A2
_0802D48C:
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl triple_slash_1st
_0802D4A2:
	pop {r4}
	pop {r0}
	bx r0
