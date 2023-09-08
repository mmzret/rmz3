	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldr r5, [r4, #0x2c]
	adds r6, r4, #0
	adds r6, #0x74
	adds r7, r4, #0
	adds r7, #0x54
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	beq _080B4304
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	str r6, [r4, #0x40]
	movs r0, #8
	ldrsb r0, [r5, r0]
	cmp r0, #2
	beq _080B42C2
	ldrb r0, [r4, #0x10]
	adds r0, #0x11
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xc
	bl ForceEntityPalette
	b _080B42D4
_080B42C2:
	ldrb r0, [r4, #0x10]
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #8
	bl ForceEntityPalette
_080B42D4:
	ldr r3, _080B430C @ =gVFXFnTable
	adds r1, r7, #0
	movs r2, #2
_080B42DA:
	ldr r0, [r5, #0x54]
	str r0, [r1]
	ldr r0, [r5, #0x58]
	str r0, [r1, #4]
	adds r1, #8
	subs r2, #1
	cmp r2, #0
	bge _080B42DA
	movs r0, #3
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl AfterImage_Update
_080B4304:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B430C: .4byte gVFXFnTable
