	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08029F90 @ =0x00000119
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #0
	beq _08029F94
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	strb r1, [r4, #0xf]
	b _0802A0D6
	.align 2, 0
_08029F90: .4byte 0x00000119
_08029F94:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	beq _08029FD0
	ldr r1, _08029FC8 @ =0x00000147
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #3
	ldr r0, _08029FCC @ =gZeroRanges
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0
	bl PushoutWallX
	strb r6, [r4, #0xd]
	strb r5, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl zero_08032724
	b _0802A0D6
	.align 2, 0
_08029FC8: .4byte 0x00000147
_08029FCC: .4byte gZeroRanges
_08029FD0:
	ldr r6, _0802A00C @ =gZeroRanges+16
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl IsZeroAgainstWall
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08029FF4
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl IsForwardPressed
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A0D6
_08029FF4:
	cmp r5, #1
	bne _0802A022
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802A010
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	b _0802A016
	.align 2, 0
_0802A00C: .4byte gZeroRanges+16
_0802A010:
	ldr r0, [r4, #0x54]
	ldr r1, _0802A080 @ =0xFFFFF800
	adds r0, r0, r1
_0802A016:
	str r0, [r4, #0x54]
	ldr r1, _0802A084 @ =gZeroRanges
	adds r0, r4, #0
	movs r2, #0
	bl PushoutWallX
_0802A022:
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	bne _0802A088
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0802A0CA
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r2, #0x4a
	adds r2, r2, r4
	mov ip, r2
	lsls r3, r1, #4
	ldrb r2, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0802A0C2
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0802A0C8
	.align 2, 0
_0802A080: .4byte 0xFFFFF800
_0802A084: .4byte gZeroRanges
_0802A088:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0802A0C2
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0802A0C8
_0802A0C2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0802A0C8:
	strb r0, [r4, #0xa]
_0802A0CA:
	movs r0, #0
	movs r1, #1
	strb r1, [r4, #0xd]
	movs r1, #2
	strb r1, [r4, #0xe]
	strb r0, [r4, #0xf]
_0802A0D6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
