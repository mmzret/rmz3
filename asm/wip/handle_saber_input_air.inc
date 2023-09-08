	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bne _0802F6E6
	adds r0, r4, #0
	movs r1, #0
	b _0802F6EA
_0802F6E6:
	adds r0, r4, #0
	movs r1, #1
_0802F6EA:
	bl GetWeaponCharge
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r2, _0802F71C @ =0x0000022D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802F6FE
	movs r1, #2
_0802F6FE:
	cmp r1, #2
	bne _0802F720
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #4
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl air_charge_saber
	b _0802F79C
	.align 2, 0
_0802F71C: .4byte 0x0000022D
_0802F720:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0x40
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0802F758
	adds r0, r4, #0
	movs r1, #0x2d
	bl isElfUsed_2
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802F758
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #6
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl air_rolling_saber
	b _0802F79C
_0802F758:
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r0, [r5]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0802F786
	ldrh r1, [r2, #0x12]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802F786
	adds r2, #0x39
	movs r1, #0
	movs r0, #7
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl saber_smash
	b _0802F79C
_0802F786:
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl air_saber
_0802F79C:
	pop {r4, r5}
	pop {r0}
	bx r0
