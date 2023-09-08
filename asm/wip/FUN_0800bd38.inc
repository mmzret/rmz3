	asrs r0, r0, #0xc
	subs r0, #1
	asrs r1, r1, #0xc
	subs r1, #1
	ldr r3, _0800BD74 @ =gOverworld
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r3, r3, r2
	ldrh r2, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	muls r2, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r2, r0
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r3
	adds r2, r2, r0
	adds r2, #0x7a
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrh r1, [r1]
	ldrh r0, [r2]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bx lr
	.align 2, 0
_0800BD74: .4byte gOverworld
