	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802D5C6
	movs r1, #0xf0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	movs r1, #1
	bl CreateWeaponSaber
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0802D5F2
_0802D5C6:
	adds r0, r4, #0
	mov r1, sp
	bl IsAttackOK
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802D5E8
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	bne _0802D5E8
	movs r0, #0x95
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802D5E8:
	movs r1, #0xf0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl KeepMotion
_0802D5F2:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _0802D688
	movs r1, #0x95
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _0802D688
	adds r1, #0xee
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0x40
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0802D642
	adds r0, r4, #0
	movs r1, #0x2a
	bl isElfUsed_2
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802D642
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #5
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl slash_up
	b _0802D688
_0802D642:
	ldr r0, [r5]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0802D672
	adds r0, r4, #0
	movs r1, #0x2b
	bl isElfUsed_2
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802D672
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
	b _0802D688
_0802D672:
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl triple_slash_3rd
_0802D688:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802D6AC
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl GetDefaultMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
_0802D6AC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
