	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bne _080306CE
	adds r0, r4, #0
	movs r1, #0
	b _080306D2
_080306CE:
	adds r0, r4, #0
	movs r1, #1
_080306D2:
	bl GetWeaponCharge
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r2, _08030700 @ =0x0000022D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _080306E6
	movs r1, #2
_080306E6:
	cmp r1, #2
	bne _08030704
	adds r2, r4, #0
	adds r2, #0xed
	movs r0, #0
	strb r1, [r2]
	adds r1, r4, #0
	adds r1, #0xee
	strb r0, [r1]
	adds r0, r4, #0
	bl charge_saber
	b _0803071A
	.align 2, 0
_08030700: .4byte 0x0000022D
_08030704:
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl wall_saber
_0803071A:
	pop {r4}
	pop {r0}
	bx r0
