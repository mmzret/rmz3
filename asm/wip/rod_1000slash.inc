	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x93
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r7, #0
	movs r0, #0x15
	strb r0, [r1]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r6, r4, #0
	adds r6, #0xee
	ldrb r0, [r6]
	cmp r0, #0
	bne _0802DDD8
	ldr r1, _0802DDD0 @ =0x00001E02
	adds r0, r4, #0
	bl SetMotion
	ldr r1, _0802DDD4 @ =0x00000133
	adds r0, r4, r1
	strb r7, [r0]
	adds r0, r4, #0
	bl CreateWeaponRod
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _0802DE70
	.align 2, 0
_0802DDD0: .4byte 0x00001E02
_0802DDD4: .4byte 0x00000133
_0802DDD8:
	ldr r5, _0802DE24 @ =0x00001E02
	adds r0, r4, #0
	adds r1, r5, #0
	bl KeepMotion
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	cmp r1, r5
	beq _0802DE08
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl GotoMotion
_0802DE08:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802DE50
	ldr r1, _0802DE28 @ =0x00000133
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802DE2C
	cmp r0, #2
	bls _0802DE2C
	strb r7, [r6]
	b _0802DE70
	.align 2, 0
_0802DE24: .4byte 0x00001E02
_0802DE28: .4byte 0x00000133
_0802DE2C:
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl GetDefaultMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x93
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xff
	b _0802DE6E
_0802DE50:
	adds r0, r4, #0
	mov r1, sp
	bl IsAttackOK
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802DE70
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #2
	bne _0802DE70
	ldr r0, _0802DE78 @ =0x00000133
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
_0802DE6E:
	strb r0, [r1]
_0802DE70:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DE78: .4byte 0x00000133
