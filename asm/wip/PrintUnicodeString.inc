	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080E9CCC @ =gTextPrinter
	ldr r3, [r0]
	cmp r2, #0x1f
	bhi _080E9CFE
	lsls r0, r2, #5
	adds r0, r1, r0
	lsls r0, r0, #1
	adds r3, r3, r0
	b _080E9CF8
	.align 2, 0
_080E9CCC: .4byte gTextPrinter
_080E9CD0:
	cmp r1, #0x1f
	bhi _080E9CFE
	cmp r0, #0x60
	bhi _080E9CDE
	movs r2, #0xe8
	lsls r2, r2, #2
	b _080E9CEC
_080E9CDE:
	cmp r0, #0x9f
	bhi _080E9CE8
	movs r2, #0xe0
	lsls r2, r2, #2
	b _080E9CEC
_080E9CE8:
	movs r2, #0xb8
	lsls r2, r2, #2
_080E9CEC:
	adds r0, r2, #0
	ldrb r2, [r4]
	adds r0, r0, r2
	strh r0, [r3]
	adds r4, #1
	adds r3, #2
_080E9CF8:
	ldrb r0, [r4]
	cmp r0, #0
	bne _080E9CD0
_080E9CFE:
	pop {r4}
	pop {r0}
	bx r0
