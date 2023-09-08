	push {r4, lr}
	asrs r4, r0, #0xc
	asrs r3, r1, #0xc
	movs r0, #0xee
	lsls r0, r0, #3
	cmp r4, r0
	bhi _08008E6C
	cmp r3, #0
	blt _08008E6C
	ldr r0, _08008E70 @ =0x000004F5
	cmp r3, r0
	ble _08008E78
_08008E6C:
	ldr r0, _08008E74 @ =0x00000A01
	b _08008E96
	.align 2, 0
_08008E70: .4byte 0x000004F5
_08008E74: .4byte 0x00000A01
_08008E78:
	ldr r2, _08008E9C @ =gOverworld+440
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
	ldrh r0, [r0]
_08008E96:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08008E9C: .4byte gOverworld+440
