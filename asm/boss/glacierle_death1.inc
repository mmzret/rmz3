	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bls _080598A2
	b _08059A3A
_080598A2:
	lsls r0, r0, #2
	ldr r1, _080598AC @ =_080598B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080598AC: .4byte _080598B0
_080598B0: @ jump table
	.4byte _080598C4 @ case 0
	.4byte _080599A6 @ case 1
	.4byte _08059A12 @ case 2
	.4byte _08059A22 @ case 3
	.4byte _08059A3A @ case 4
_080598C4:
	movs r0, #0x2f
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0xc2
	ldrb r6, [r0]
	ldr r0, _080599C4 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _0805992C
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r2, _080599C8 @ =gBossFnTable
	movs r1, #0x10
	movs r0, #0x10
	strb r0, [r4, #9]
	ldr r0, [r2, #0x40]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r2, r4, #0
	adds r2, #0x22
	strb r0, [r2]
	ldrb r0, [r4, #0xb]
	orrs r1, r0
	strb r1, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	str r5, [r4, #0x28]
	movs r1, #1
	strb r1, [r4, #0x10]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	ands r0, r1
	eors r0, r6
	strb r0, [r4, #0x13]
_0805992C:
	ldr r1, _080599CC @ =0x0000B203
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r3, _080599D0 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _0805996E
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0805996E
	ldr r0, _080599D4 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805996E:
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	lsls r1, r6, #0xc
	subs r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _080599D8 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r0, #0x32
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080599A6:
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xc2
	ldrb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080599DC
	cmp r3, #1
	bne _080599E0
	b _080599E4
	.align 2, 0
_080599C4: .4byte gBossHeaderPtr
_080599C8: .4byte gBossFnTable
_080599CC: .4byte 0x0000B203
_080599D0: .4byte gStageRun
_080599D4: .4byte 0x0000FFFE
_080599D8: .4byte 0xFFFFD800
_080599DC:
	cmp r3, #0
	beq _080599E4
_080599E0:
	movs r0, #0xfa
	b _080599E6
_080599E4:
	movs r0, #0xf6
_080599E6:
	muls r0, r2, r0
	cmp r0, #0
	bge _080599EE
	adds r0, #0xff
_080599EE:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08059A0A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08059A0A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _08059A3A
_08059A12:
	ldr r1, _08059A44 @ =0x08364B34
	adds r0, r5, #0
	bl CreateBossExplosion
	str r0, [r5, #0x2c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08059A22:
	ldr r0, [r5, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08059A3A
	ldr r2, _08059A48 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08059A3A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08059A44: .4byte 0x08364B34
_08059A48: .4byte gStageRun
