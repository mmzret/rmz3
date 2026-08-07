	push {r4, r5, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldrb r3, [r4, #0xa]
	movs r0, #0x10
	ands r0, r3
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080DD3B0
	movs r0, #0x8a
	lsls r0, r0, #0xb
	cmp r1, r0
	ble _080DD392
	movs r0, #0xfe
	ands r0, r3
	movs r2, #0
	b _080DD3C0
_080DD392:
	ldr r0, _080DD3A8 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080DD3AC @ =0x000097FF
	adds r0, r0, r2
	cmp r1, r0
	ble _080DD3EE
	movs r0, #0xfe
	ands r0, r3
	movs r2, #0
	b _080DD3C0
	.align 2, 0
_080DD3A8: .4byte gStageRun+232
_080DD3AC: .4byte 0x000097FF
_080DD3B0:
	ldr r0, _080DD3F4 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r5, _080DD3F8 @ =0xFFFF6800
	adds r0, r0, r5
	cmp r1, r0
	bge _080DD3EE
	movs r0, #0xfe
	ands r0, r3
_080DD3C0:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080DD3FC @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080DD3EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD3F4: .4byte gStageRun+232
_080DD3F8: .4byte 0xFFFF6800
_080DD3FC: .4byte gSolidFnTable
