	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r5, r4, #0
	adds r5, #0xb4
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080329EC
	ldrb r0, [r5, #0x11]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080329DC
	adds r0, r4, #0
	movs r1, #0x1e
	bl IsElfUsed
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080329EA
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _080329EA
	movs r0, #0
	b _08032A2E
_080329DC:
	adds r0, r4, #0
	movs r1, #0x1e
	bl IsElfUsed
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080329EC
_080329EA:
	movs r6, #0xc0
_080329EC:
	ldr r1, _08032A18 @ =gZeroRanges
	ldr r2, _08032A1C @ =0x00000147
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldr r1, [r4, #0x58]
	subs r1, r1, r0
	ldr r0, _08032A20 @ =gOverworld
	ldr r2, _08032A24 @ =0x0002C00C
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	ble _08032A2C
	cmp r6, #0xc0
	bne _08032A28
	movs r0, #0x60
	b _08032A2E
	.align 2, 0
_08032A18: .4byte gZeroRanges
_08032A1C: .4byte 0x00000147
_08032A20: .4byte gOverworld
_08032A24: .4byte 0x0002C00C
_08032A28:
	movs r0, #0xc0
	b _08032A2E
_08032A2C:
	adds r0, r6, #0
_08032A2E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
