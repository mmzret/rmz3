	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0802A7B0 @ =0x00000147
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #3
	beq _0802A75E
	movs r0, #1
	strb r0, [r1]
_0802A75E:
	ldr r0, _0802A7B4 @ =0x00000123
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0802A784
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl CreateDashDust
_0802A784:
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0802A798
	b _0802A89A
_0802A798:
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0802A7B8
	movs r5, #0
	b _0802A7CA
	.align 2, 0
_0802A7B0: .4byte 0x00000147
_0802A7B4: .4byte 0x00000123
_0802A7B8:
	movs r0, #0x10
	ands r2, r0
	cmp r2, #0
	beq _0802A7C4
	movs r5, #1
	b _0802A7CA
_0802A7C4:
	ldrb r0, [r4, #0xa]
	lsrs r5, r0, #4
	ands r5, r3
_0802A7CA:
	movs r3, #1
	adds r1, r5, #0
	ands r1, r3
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _0802A7FC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0802A802
_0802A7FC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0802A802:
	strb r0, [r4, #0xa]
	ldr r1, _0802A834 @ =0x0000011F
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A850
	cmp r5, #0
	beq _0802A838
	ldr r0, [r4, #0x5c]
	adds r0, #0x20
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x5c]
	cmp r1, r0
	ble _0802A86E
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _0802A86C
	.align 2, 0
_0802A834: .4byte 0x0000011F
_0802A838:
	ldr r0, [r4, #0x5c]
	subs r0, #0x20
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x5c]
	cmn r1, r0
	bge _0802A86E
	b _0802A860
_0802A850:
	cmp r5, #0
	beq _0802A860
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _0802A86C
_0802A860:
	adds r0, r4, #0
	bl GetDashSpeed
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0802A86C:
	str r0, [r4, #0x5c]
_0802A86E:
	movs r0, #0x88
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0802A89A
	ldr r1, [r6]
	movs r0, #0x30
	ands r1, r0
	cmp r1, #0
	beq _0802A896
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0
	strb r0, [r4, #0xf]
	b _0802A89A
_0802A896:
	strb r1, [r4, #0xe]
	strb r1, [r4, #0xf]
_0802A89A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
