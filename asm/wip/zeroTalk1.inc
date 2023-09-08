	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0802CA9C @ =gCollisionManager
	movs r1, #0xc5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _0802CAA8
	ldr r0, [r2, #0x2c]
	cmp r0, #0
	beq _0802CAA8
	movs r3, #0
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0802CA64
	movs r3, #1
_0802CA64:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r0, [r2, #0x2c]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0802CA78
	movs r3, #1
_0802CA78:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0802CAA0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0802CAA6
	.align 2, 0
_0802CA9C: .4byte gCollisionManager
_0802CAA0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0802CAA6:
	strb r0, [r4, #0xa]
_0802CAA8:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0802CAD0
	ldr r0, _0802CAC8 @ =gInChat
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802CAE4
	ldr r1, _0802CACC @ =0x00003301
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _0802CAE4
	.align 2, 0
_0802CAC8: .4byte gInChat
_0802CACC: .4byte 0x00003301
_0802CAD0:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802CAE4
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	str r0, [r4, #0x5c]
_0802CAE4:
	pop {r4}
	pop {r0}
	bx r0
