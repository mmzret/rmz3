	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080593DC
	cmp r0, #1
	beq _08059484
	b _080594BC
_080593DC:
	ldr r7, [r6, #0x2c]
	adds r1, r7, #0
	adds r1, #0xb4
	ldrb r0, [r1]
	movs r2, #0xb4
	adds r2, r2, r6
	mov sb, r2
	cmp r0, #0
	beq _080593FC
	adds r4, r1, #0
_080593F0:
	adds r0, r7, #0
	bl FUN_08082348
	ldrb r0, [r4]
	cmp r0, #0
	bne _080593F0
_080593FC:
	ldr r5, [r6, #0x28]
	mov ip, r5
	ldrb r2, [r5, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	movs r4, #0
	movs r2, #0xfd
	mov sl, r2
	ands r0, r2
	strb r0, [r5, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r2, [r5, #0xa]
	movs r3, #0xfb
	adds r0, r3, #0
	ands r0, r2
	strb r0, [r5, #0xa]
	ldr r0, _080594CC @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r2, #3
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	ldrb r0, [r7, #0xa]
	ands r1, r0
	mov r5, sl
	ands r1, r5
	strb r1, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r0, [r7, #0xa]
	ands r3, r0
	strb r3, [r7, #0xa]
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	add r0, r8
	str r2, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
	mov r1, sb
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r1, _080594D0 @ =0x0000B219
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08059484:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805949A
	movs r0, #0
	strb r0, [r6, #0xd]
	strb r0, [r6, #0xe]
_0805949A:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r2, _080594D4 @ =0x08364B26
	adds r1, r6, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080594D8 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
_080594BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080594CC: .4byte gEnemyFnTable
_080594D0: .4byte 0x0000B219
_080594D4: .4byte 0x08364B26
_080594D8: .4byte sCollisions
