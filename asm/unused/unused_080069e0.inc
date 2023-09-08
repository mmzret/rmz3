	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r2, r2, #0x10
	movs r3, #0
	lsrs r2, r2, #0xd
	adds r2, r2, r1
	ldr r5, [r2]
	ldr r4, [r2, #4]
_080069F0:
	lsls r0, r3, #7
	adds r2, r3, #1
	adds r0, r0, r6
	movs r1, #0xf
_080069F8:
	str r5, [r0]
	str r4, [r0, #0x40]
	adds r0, #4
	subs r1, #1
	cmp r1, #0
	bge _080069F8
	adds r3, r2, #0
	cmp r3, #0xf
	ble _080069F0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
