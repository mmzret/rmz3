  push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	ldr r0, [sp, #0x14]
	lsls r1, r1, #0x18
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r5, [r4]
	lsrs r7, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #0
	strh r1, [r4, #4]
	strh r6, [r4, #6]
	strh r3, [r4, #8]
	adds r0, r4, #0
	adds r0, #0x14
	str r0, [r4, #0x18]
	str r0, [r4, #0x14]
	str r2, [r4, #0x10]
	strh r3, [r4, #0xa]
	lsls r1, r3, #0x10
	cmp r1, #0
	ble _08006F1A
	lsls r0, r6, #0x10
	asrs r3, r0, #0x10
_08006F06:
	str r2, [r5]
	adds r2, r5, #0
	strb r7, [r2, #8]
	adds r5, r2, r3
	ldr r0, _08006F20 @ =0xFFFF0000
	adds r1, r1, r0
	asrs r0, r1, #0x10
	cmp r0, #0
	bgt _08006F06
	str r2, [r4, #0x10]
_08006F1A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006F20: .4byte 0xFFFF0000
