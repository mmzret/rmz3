	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r1, _08029DF4 @ =0x00000119
	adds r0, r4, r1
	ldrb r7, [r0]
	cmp r7, #0
	beq _08029DF8
	movs r1, #0
	movs r0, #5
	b _08029F0C
	.align 2, 0
_08029DF4: .4byte 0x00000119
_08029DF8:
	ldrh r1, [r4, #0xe]
	ldr r0, _08029E6C @ =0x00000202
	cmp r1, r0
	bne _08029E02
	b _08029F60
_08029E02:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r0, [r1]
	movs r6, #1
	ands r0, r6
	mov r8, r1
	cmp r0, #0
	beq _08029EEC
	ldrb r0, [r4, #0xf]
	cmp r0, #2
	bhi _08029EEC
	ldr r1, _08029E70 @ =0x00000147
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #3
	ldr r0, _08029E74 @ =gZeroRanges
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0
	bl zero_08026970
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08029E8C
	ldr r0, [r5, #0x40]
	cmp r0, #0
	beq _08029E40
	strb r6, [r0, #0x11]
	str r7, [r5, #0x40]
_08029E40:
	subs r1, #1
	movs r0, #1
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _08029E78
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08029E7E
	.align 2, 0
_08029E6C: .4byte 0x00000202
_08029E70: .4byte 0x00000147
_08029E74: .4byte gZeroRanges
_08029E78:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08029E7E:
	strb r0, [r4, #0xa]
	movs r0, #0
	movs r1, #1
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	movs r0, #2
	b _08029EDC
_08029E8C:
	ldrb r0, [r5, #0x11]
	cmp r0, #1
	beq _08029E96
	cmp r0, #7
	bne _08029EAA
_08029E96:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029EAA
	strb r6, [r4, #0xd]
	strb r1, [r4, #0xe]
	strb r1, [r4, #0xf]
	b _08029EDE
_08029EAA:
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, _08029EE8 @ =0x00000216
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08029EEC
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	beq _08029EC8
	cmp r0, #7
	bne _08029EEC
_08029EC8:
	movs r0, #0x8d
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r1, [r2]
	cmp r1, #0
	bne _08029EEC
	movs r0, #1
	strb r0, [r2]
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08029EDC:
	strb r0, [r4, #0xf]
_08029EDE:
	adds r0, r4, #0
	bl zero_08032724
	b _08029F60
	.align 2, 0
_08029EE8: .4byte 0x00000216
_08029EEC:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08029F18
	ldr r1, _08029F14 @ =gZeroRanges
	adds r0, r4, #0
	movs r2, #0
	bl TryLadderUp
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08029F18
	movs r1, #0
	movs r0, #3
_08029F0C:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	strb r1, [r4, #0xf]
	b _08029F60
	.align 2, 0
_08029F14: .4byte gZeroRanges
_08029F18:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	bne _08029F3C
	ldrb r0, [r4, #0xf]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08029F60
	mov r2, r8
	ldr r0, [r2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08029F60
	strb r1, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _08029F60
_08029F3C:
	cmp r5, #2
	bne _08029F60
	ldr r1, _08029F6C @ =0x00000147
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #3
	ldr r0, _08029F70 @ =gZeroRanges
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0
	bl CanWallSlide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08029F60
	movs r0, #0
	strb r5, [r4, #0xd]
	strb r0, [r4, #0xe]
_08029F60:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029F6C: .4byte 0x00000147
_08029F70: .4byte gZeroRanges
