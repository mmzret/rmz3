	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	asrs r4, r5, #0xc
	asrs r3, r6, #0xc
	movs r0, #0xee
	lsls r0, r0, #3
	cmp r4, r0
	bhi _080098BC
	ldr r0, _080098C0 @ =0x000004F5
	cmp r3, r0
	bls _080098C8
_080098BC:
	ldr r0, _080098C4 @ =0x00000A01
	b _08009922
	.align 2, 0
_080098C0: .4byte 0x000004F5
_080098C4: .4byte 0x00000A01
_080098C8:
	ldr r2, _08009914 @ =gOverworld+440
	movs r0, #0xc5
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r0, [r1]
	muls r0, r3, r0
	adds r0, r0, r4
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, _08009918 @ =gShapeCheckerUp
	movs r2, #0xf
	ands r2, r4
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r3, _0800991C @ =0x00000FFF
	adds r0, r5, #0
	ands r0, r3
	adds r1, r6, #0
	ands r1, r3
	ldr r2, [r2]
	bl _call_via_r2
	cmp r0, #0
	bne _08009920
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetHazardMetatileAttr
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08009922
	.align 2, 0
_08009914: .4byte gOverworld+440
_08009918: .4byte gShapeCheckerUp
_0800991C: .4byte 0x00000FFF
_08009920:
	adds r0, r4, #0
_08009922:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
