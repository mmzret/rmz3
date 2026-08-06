	push {lr}
	movs r3, #0
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r1, [r0, #0x2c]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	bne _080B21D8
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B21D8
	movs r3, #1
_080B21D8:
	ldrb r0, [r1, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21E8
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21E8
	movs r3, #1
_080B21E8:
	cmp r1, #2
	bne _080B21F4
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21F4
	movs r3, #1
_080B21F4:
	cmp r3, #1
	bne _080B21FE
	adds r0, r2, #0
	adds r0, #0xbc
	strb r3, [r0]
_080B21FE:
	pop {r0}
	bx r0
	.align 2, 0
