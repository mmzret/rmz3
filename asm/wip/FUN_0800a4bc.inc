	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	asrs r4, r6, #0xc
	asrs r2, r3, #0xc
	movs r0, #0xee
	lsls r0, r0, #3
	cmp r4, r0
	bhi _0800A548
	ldr r0, _0800A51C @ =0x000004F5
	cmp r2, r0
	bhi _0800A548
	ldr r5, _0800A520 @ =gOverworld+440
	movs r0, #0xc5
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r0, r0, r4
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, _0800A524 @ =gShapeCheckerUp
	movs r1, #0xf
	ands r1, r4
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, _0800A528 @ =0x00000FFF
	ands r3, r0
	ldr r2, [r1]
	ands r0, r6
	adds r1, r3, #0
	bl _call_via_r2
	cmp r0, #0
	beq _0800A548
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r4
	cmp r0, #0
	beq _0800A530
	ldr r1, _0800A52C @ =0x0002BE50
	b _0800A53C
	.align 2, 0
_0800A51C: .4byte 0x000004F5
_0800A520: .4byte gOverworld+440
_0800A524: .4byte gShapeCheckerUp
_0800A528: .4byte 0x00000FFF
_0800A52C: .4byte 0x0002BE50
_0800A530:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r4, r0
	cmp r4, #0
	beq _0800A548
	ldr r1, _0800A544 @ =0x0002BE4C
_0800A53C:
	adds r0, r5, r1
	ldr r0, [r0]
	b _0800A54A
	.align 2, 0
_0800A544: .4byte 0x0002BE4C
_0800A548:
	movs r0, #0
_0800A54A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
