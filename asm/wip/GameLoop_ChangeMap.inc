	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl UpdateStoryFlag
	ldr r0, _080EF41C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080EF420
	bl ExitProcess
	b _080EF578
	.align 2, 0
_080EF41C: .4byte gCurStory
_080EF420:
	ldr r2, _080EF43C @ =gStageRun
	ldrh r1, [r2, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080EF45C
	ldr r1, _080EF440 @ =gMission
	ldr r0, [r1]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EF444
	movs r1, #0x90
	lsls r1, r1, #4
	b _080EF55C
	.align 2, 0
_080EF43C: .4byte gStageRun
_080EF440: .4byte gMission
_080EF444:
	ldrh r0, [r1, #0x14]
	cmp r0, #0x62
	bhi _080EF44E
	adds r0, #1
	strh r0, [r1, #0x14]
_080EF44E:
	ldr r0, [r1]
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #2
	b _080EF55C
_080EF45C:
	ldr r0, _080EF470 @ =0x00006260
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x11
	bne _080EF478
	ldrb r0, [r2, #2]
	cmp r0, #0xc
	bne _080EF474
	movs r0, #6
	b _080EF538
	.align 2, 0
_080EF470: .4byte 0x00006260
_080EF474:
	cmp r0, #0x13
	beq _080EF536
_080EF478:
	ldr r5, _080EF498 @ =gCurStory
	ldrb r1, [r5, #4]
	movs r7, #0x20
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080EF4A0
	ldr r0, _080EF49C @ =0x00006260
	adds r1, r4, r0
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #9
	bl LoadStageRun
	b _080EF56E
	.align 2, 0
_080EF498: .4byte gCurStory
_080EF49C: .4byte 0x00006260
_080EF4A0:
	ldr r6, _080EF4B8 @ =0x00006260
	adds r1, r4, r6
	ldrh r3, [r1]
	cmp r3, #1
	bne _080EF4BC
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #3
	bl LoadStageRun
	b _080EF56E
	.align 2, 0
_080EF4B8: .4byte 0x00006260
_080EF4BC:
	ldrb r2, [r5, #5]
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080EF544
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _080EF4E2
	cmp r3, #0x11
	beq _080EF4DE
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #4
	bl LoadStageRun
	b _080EF56E
_080EF4DE:
	movs r0, #6
	b _080EF538
_080EF4E2:
	cmp r3, #6
	bne _080EF4F2
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #0xd
	bl LoadStageRun
	b _080EF56E
_080EF4F2:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _080EF544
	ldrb r2, [r5, #6]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080EF544
	cmp r3, #0xa
	bne _080EF514
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #0xf
	bl LoadStageRun
	b _080EF56E
_080EF514:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080EF544
	adds r0, r7, #0
	ands r0, r2
	cmp r0, #0
	bne _080EF540
	cmp r3, #0x11
	beq _080EF534
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #0x10
	bl LoadStageRun
	b _080EF56E
_080EF534:
	adds r1, r4, r6
_080EF536:
	movs r0, #0xf
_080EF538:
	strh r0, [r1]
	bl InitStageRun
	b _080EF56E
_080EF540:
	cmp r3, #0xf
	bne _080EF550
_080EF544:
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #7
	bl LoadStageRun
	b _080EF56E
_080EF550:
	adds r1, r4, r6
	ldrh r0, [r1]
	cmp r0, #0x10
	bne _080EF564
	movs r1, #0xb0
	lsls r1, r1, #4
_080EF55C:
	adds r0, r4, #0
	bl SetGameMode
	b _080EF578
_080EF564:
	movs r0, #0x11
	strh r0, [r1]
	movs r1, #7
	bl LoadStageRun
_080EF56E:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetGameMode
_080EF578:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
