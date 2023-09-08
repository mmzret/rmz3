	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov ip, r0
	movs r2, #0x8f
	lsls r2, r2, #2
	add r2, ip
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	movs r1, #0xb0
	lsls r1, r1, #0x11
	cmp r0, r1
	bls _080ED17A
	ldr r4, _080ED1C0 @ =gPaletteManager
	ldr r1, _080ED1C4 @ =gGraphic_Capcom+2612
	ldr r0, [r1]
	adds r1, r0, r1
	ldrh r0, [r2]
	ldr r2, _080ED1C8 @ =0xFFFFFEA0
	adds r0, r0, r2
	asrs r3, r0, #1
	cmp r3, #0x20
	ble _080ED13A
	movs r3, #0x20
_080ED13A:
	movs r0, #0x20
	subs r3, r0, r3
	movs r7, #0x1f
	adds r6, r4, #0
	adds r6, #0x40
	adds r4, r1, #0
	movs r5, #0xf
_080ED148:
	ldrh r1, [r4]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r3, r2
	asrs r2, r2, #5
	lsrs r0, r1, #5
	ands r0, r7
	muls r0, r3, r0
	asrs r0, r0, #5
	lsls r0, r0, #5
	orrs r2, r0
	lsrs r1, r1, #0xa
	ands r1, r7
	adds r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #5
	lsls r0, r0, #0xa
	orrs r2, r0
	strh r2, [r6]
	adds r6, #2
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080ED148
_080ED17A:
	ldr r1, _080ED1CC @ =gBgMapOffsets
	movs r5, #0x8f
	lsls r5, r5, #2
	add r5, ip
	ldrh r3, [r5]
	lsrs r2, r3, #1
	movs r0, #3
	ands r2, r0
	adds r2, #0x82
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r4, #1
	adds r0, r4, #0
	ands r0, r3
	lsls r0, r0, #5
	str r0, [sp]
	movs r0, #0x12
	movs r3, #0
	bl LoadBgMap
	ldr r1, _080ED1D0 @ =gVideoRegBuffer+18
	ldrh r0, [r5]
	ands r4, r0
	movs r0, #0
	cmp r4, #0
	bne _080ED1B4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
_080ED1B4:
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ED1C0: .4byte gPaletteManager
_080ED1C4: .4byte gGraphic_Capcom+2612
_080ED1C8: .4byte 0xFFFFFEA0
_080ED1CC: .4byte gBgMapOffsets
_080ED1D0: .4byte gVideoRegBuffer+18
