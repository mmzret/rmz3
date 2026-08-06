	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x11]
	lsls r0, r0, #1
	movs r1, #0xdf
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r4, r4, r0
	ldrh r0, [r4]
	cmp r0, #0xff
	bne _080DDEE4
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080DDEEA
_080DDEE4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080DDEEA:
	strb r0, [r5, #0xa]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

