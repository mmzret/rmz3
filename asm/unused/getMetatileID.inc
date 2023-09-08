	push {lr}
	asrs r3,r0,#0xc
	asrs r2,r1,#0xc
	movs r0,#0xee
	lsls r0,r0,#0x3
	cmp r3,r0
	bhi _08008e28
	cmp r2,#0x0
	blt _08008e28
	ldr r0, _08008e30
	cmp r2,r0
	ble _08008e34
_08008e28:
	movs r0,#0x1
	rsbs r0,r0,#0
	b _08008e4c
	.align 2, 0
_08008e30: .4byte 0x4F5
_08008e34:
	ldr r1, _08008e50
	movs r0,#0xfc
	lsls r0,r0,#0x3
	adds r1,r1,r0
	ldrh r0,[r1,#0x0]
	muls r0,r2
	adds r0,r0,r3
	adds r0,r0,#0x2
	lsls r0,r0,#0x1
	adds r0,r0,r1
	movs r1,#0x0
	ldrsh r0,[r0,r1]
_08008e4c:
	pop {r1}
	bx r1
	.align 2, 0
_08008e50: .4byte gOverworld
