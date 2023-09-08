	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	asrs r3, r6, #0xc
	asrs r1, r5, #0xc
	ldr r4, _0800997C @ =gOverworld+440
	movs r0, #0xc5
	lsls r0, r0, #3
	adds r2, r4, r0
	ldrh r0, [r2]
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, #0
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0
	beq _08009976
	cmp r1, #1
	beq _0800998A
	ldr r0, _08009980 @ =gShapeCheckerUp
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, _08009984 @ =0x00000FFF
	ands r5, r0
	ldr r2, [r1]
	ands r0, r6
	adds r1, r5, #0
	bl _call_via_r2
	cmp r0, #0
	bne _08009988
_08009976:
	movs r0, #0
	b _0800998A
	.align 2, 0
_0800997C: .4byte gOverworld+440
_08009980: .4byte gShapeCheckerUp
_08009984: .4byte 0x00000FFF
_08009988:
	adds r0, r4, #0
_0800998A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
