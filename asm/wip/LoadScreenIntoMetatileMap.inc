	push {r4, r5, r6, r7, lr}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _080092D4 @ =gOverworld
	movs r4, #0xe8
	lsls r4, r4, #1
	adds r3, r5, r4
	ldrb r4, [r3]
	movs r3, #0x7f
	ands r3, r4
	ldr r4, _080092D8 @ =gStageLandscape
	lsls r3, r3, #2
	adds r3, r3, r4
	ldr r6, [r3]
	ldr r3, _080092DC @ =0x000007E4
	adds r5, r5, r3
	ldr r4, [r6, #8]
	ldr r3, [r4, #8]
	adds r4, r3, r4
	lsls r3, r2, #2
	adds r3, r3, r2
	lsls r2, r3, #4
	subs r2, r2, r3
	lsls r2, r2, #2
	adds r4, r4, r2
	ldr r2, [r6, #0xc]
	ldrb r2, [r2, #2]
	lsls r3, r2, #4
	subs r3, r3, r2
	adds r2, r3, #0
	muls r2, r1, r2
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	lsls r2, r0, #4
	subs r2, r2, r0
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r5, r1, r5
	movs r6, #0
	lsls r7, r3, #1
_080092A2:
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x1e
	bl Transfer30Bytes
	adds r5, r5, r7
	adds r4, #0x1e
	lsls r0, r6, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _080092A2
	ldr r0, _080092D4 @ =gOverworld
	movs r3, #0xb0
	lsls r3, r3, #0xa
	adds r0, r0, r3
	movs r1, #1
	strh r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080092D4: .4byte gOverworld
_080092D8: .4byte gStageLandscape
_080092DC: .4byte 0x000007E4
