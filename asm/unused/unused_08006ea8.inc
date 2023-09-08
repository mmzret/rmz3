	push {r4, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r4, r3, #4
	subs r4, r4, r3
	movs r3, #0x96
	muls r1, r3, r1
	adds r1, r1, r2
	adds r4, r4, r1
	ldr r1, [r0, #8]
	lsls r4, r4, #1
	adds r4, r4, r1
	ldrh r1, [r4]
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
