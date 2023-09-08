	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _080692B4
	ldr r3, [r4, #0x28]
	ldr r0, _0806924C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08069250
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _0806925C
	.align 2, 0
_0806924C: .4byte gCurStory
_08069250:
	ldrb r0, [r3, #0xc]
	cmp r0, #4
	bne _08069290
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0806925C:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806928C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080692F2
	.align 2, 0
_0806928C: .4byte gEnemyFnTable
_08069290:
	cmp r0, #1
	bls _080692D2
	ldr r1, _080692B0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	adds r0, r4, #0
	bl GrandCannon_Die
	b _080692F2
	.align 2, 0
_080692B0: .4byte gEnemyFnTable
_080692B4:
	adds r0, r4, #0
	bl tryKillGrandCannon
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080692F2
	adds r0, r4, #0
	bl FUN_0806910c
	adds r0, r4, #0
	bl FUN_08069098
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080692F2
_080692D2:
	ldr r1, _080692F8 @ =0x08366234
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080692FC @ =0x08366244
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080692F2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080692F8: .4byte 0x08366234
_080692FC: .4byte 0x08366244
