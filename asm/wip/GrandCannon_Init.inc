	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080691C0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _080691C4 @ =0x083662B0
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08069210
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldr r0, _080691C8 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x14]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080691D4
	ldr r0, _080691CC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _080691D4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080691D0 @ =0x08366260
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _080691EC
	.align 2, 0
_080691C0: .4byte gEnemyFnTable
_080691C4: .4byte 0x083662B0
_080691C8: .4byte gSystemSavedataManager
_080691CC: .4byte gCurStory
_080691D0: .4byte 0x08366260
_080691D4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08069208 @ =0x08366260
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_080691EC:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0806920C @ =onCollision
	str r0, [r4, #0x24]
	adds r0, r6, #0
	bl CreateGrandCannonBattery
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	b _08069216
	.align 2, 0
_08069208: .4byte 0x08366260
_0806920C: .4byte onCollision
_08069210:
	adds r0, r6, #0
	adds r0, #0xb8
	strb r5, [r0]
_08069216:
	adds r0, r6, #0
	bl GrandCannon_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
