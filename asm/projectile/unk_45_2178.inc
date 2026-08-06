	push {r4, lr}
	movs r4, #0
	ldr r3, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r2, [r0, #0x2c]
	ldrb r0, [r3, #0x11]
	cmp r0, #0
	bne _080B2190
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B2190
	movs r4, #1
_080B2190:
	ldrb r0, [r3, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21A0
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21A0
	movs r4, #1
_080B21A0:
	cmp r1, #2
	bne _080B21AC
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21AC
	movs r4, #1
_080B21AC:
	adds r1, r3, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
	cmp r4, #1
	bne _080B21BA
	strb r4, [r1]
_080B21BA:
	pop {r4}
	pop {r0}
	bx r0
