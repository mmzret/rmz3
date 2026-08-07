	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080918FC
	cmp r5, #1
	beq _08091924
	b _0809197A
_080918FC:
	movs r6, #0
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0809190A
	movs r6, #1
_0809190A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091934 @ =0x08369894
	bl SetDDP
	lsls r0, r6, #9
	ldr r1, _08091938 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091924:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _0809193C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091942
	.align 2, 0
_08091934: .4byte 0x08369894
_08091938: .4byte 0xFFFFFF00
_0809193C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091942:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _08091954
	movs r0, #0
	strb r0, [r4, #0x12]
_08091954:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r1, r0, r1
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x64]
	subs r2, r0, r1
	adds r3, r0, #0
	cmp r2, #0
	blt _0809196C
	cmp r2, #0xff
	ble _08091972
	b _0809197A
_0809196C:
	subs r0, r1, r3
	cmp r0, #0xff
	bgt _0809197A
_08091972:
	str r3, [r4, #0x54]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0809197A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

