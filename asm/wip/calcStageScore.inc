	push {r4, lr}
	ldr r4, _080197E8 @ =gMission
	ldr r1, [r4]
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	ldr r2, [r4]
	movs r3, #1
	adds r1, r3, #0
	ldrb r0, [r4, #4]
	lsls r1, r0
	ldr r0, [r2, #0x14]
	orrs r0, r1
	str r0, [r2, #0x14]
	ldrb r0, [r4, #4]
	strb r0, [r2, #0x13]
	ldrb r0, [r4, #7]
	strb r0, [r4, #0x16]
	ldr r1, [r4]
	ldrb r0, [r1, #0x11]
	adds r0, #1
	strb r0, [r1, #0x11]
	ldr r1, [r4]
	ldrb r2, [r4, #4]
	lsls r3, r2
	ldr r0, [r1, #0x18]
	orrs r0, r3
	str r0, [r1, #0x18]
	ldr r0, [r4, #8]
	movs r1, #0x3c
	bl __udivsi3
	ldr r2, _080197EC @ =gClearTimeTable
	ldrb r1, [r4, #4]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	subs r2, r0, r1
	cmp r2, #0
	bgt _080197F0
	movs r0, #0x14
	b _08019808
	.align 2, 0
_080197E8: .4byte gMission
_080197EC: .4byte gClearTimeTable
_080197F0:
	cmp r2, #0xc7
	bgt _08019806
	adds r0, r2, #0
	adds r0, #9
	movs r1, #0xa
	bl __divsi3
	movs r1, #0x14
	subs r1, r1, r0
	strb r1, [r4, #0x17]
	b _0801980A
_08019806:
	movs r0, #0
_08019808:
	strb r0, [r4, #0x17]
_0801980A:
	ldrh r0, [r4, #0xc]
	ldrh r1, [r4, #0x14]
	adds r1, #1
	bl __divsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _0801981E
	strb r2, [r4, #0x18]
	b _08019852
_0801981E:
	ldr r1, _08019840 @ =gEnemyCountTable
	ldrb r0, [r4, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r2, #0
	bl __divsi3
	adds r2, r0, #0
	cmp r2, #0xa
	bgt _08019844
	movs r0, #0xf
	b _08019850
	.align 2, 0
_08019840: .4byte gEnemyCountTable
_08019844:
	cmp r2, #0x18
	ble _0801984C
	movs r0, #0
	b _08019850
_0801984C:
	movs r0, #0x19
	subs r0, r0, r2
_08019850:
	strb r0, [r4, #0x18]
_08019852:
	ldrh r2, [r4, #0xe]
	cmp r2, #0
	bne _0801985E
	movs r0, #0xf
	strb r0, [r4, #0x19]
	b _08019876
_0801985E:
	cmp r2, #0x5a
	ble _08019868
	movs r0, #0
	strb r0, [r4, #0x19]
	b _08019876
_08019868:
	subs r0, r2, #1
	movs r1, #6
	bl __divsi3
	movs r1, #0xf
	subs r1, r1, r0
	strb r1, [r4, #0x19]
_08019876:
	ldrh r2, [r4, #0x14]
	cmp r2, #0
	bne _08019880
	movs r0, #0xf
	b _08019890
_08019880:
	cmp r2, #4
	ble _08019888
	movs r0, #0
	b _08019890
_08019888:
	lsls r1, r2, #1
	adds r1, r1, r2
	movs r0, #0xf
	subs r0, r0, r1
_08019890:
	strb r0, [r4, #0x1a]
	ldr r1, [r4, #0x10]
	movs r0, #0xf
	subs r2, r0, r1
	subs r0, #0x73
	cmp r2, r0
	bge _080198A2
	strb r0, [r4, #0x1b]
	b _080198A4
_080198A2:
	strb r2, [r4, #0x1b]
_080198A4:
	ldrb r0, [r4, #0x17]
	ldrb r1, [r4, #0x16]
	adds r0, r0, r1
	ldrb r1, [r4, #0x18]
	adds r1, r1, r0
	ldrb r2, [r4, #0x19]
	adds r1, r1, r2
	ldrb r0, [r4, #0x1a]
	adds r0, r0, r1
	ldrb r1, [r4, #0x1b]
	adds r0, r0, r1
	strb r0, [r4, #5]
	ldr r1, [r4]
	movs r0, #5
	ldrsb r0, [r4, r0]
	ldrh r2, [r1, #0xa]
	adds r0, r0, r2
	strh r0, [r1, #0xa]
	ldr r1, [r4]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	ldrb r1, [r1, #0x10]
	bl __divsi3
	adds r3, r0, #0
	movs r2, #0
	ldr r1, _080198DC @ =sRankBorder
	b _080198E4
	.align 2, 0
_080198DC: .4byte sRankBorder
_080198E0:
	adds r1, #4
	adds r2, #1
_080198E4:
	ldr r0, [r1]
	cmp r3, r0
	bge _080198E0
	ldr r4, _08019928 @ =gMission
	ldr r0, [r4]
	strb r2, [r0, #1]
	bl calcCodename
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _08019900
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0801990A
_08019900:
	ldr r2, _0801992C @ =gCurStory
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
_0801990A:
	ldr r1, _08019928 @ =gMission
	ldrh r0, [r1, #0x1c]
	cmp r0, #0
	bne _08019918
	ldr r0, [r1, #0x20]
	cmp r0, #0
	beq _08019922
_08019918:
	ldr r2, _0801992C @ =gCurStory
	ldrb r1, [r2, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r2, #0xa]
_08019922:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08019928: .4byte gMission
_0801992C: .4byte gCurStory
