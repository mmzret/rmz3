	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, #8
	bls _08024018
	b _080242E4
_08024018:
	lsls r0, r0, #2
	ldr r1, _08024024 @ =_08024028
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08024024: .4byte _08024028
_08024028: @ jump table
	.4byte _0802404C @ case 0
	.4byte _0802417C @ case 1
	.4byte _080241D4 @ case 2
	.4byte _080241EC @ case 3
	.4byte _08024202 @ case 4
	.4byte _08024218 @ case 5
	.4byte _0802422E @ case 6
	.4byte _08024268 @ case 7
	.4byte _0802429A @ case 8
_0802404C:
	ldr r4, _0802419C @ =gScore
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	str r0, [r6, #0x10]
	ldr r0, _080241A0 @ =gGameState
	ldr r1, _080241A4 @ =0x000064AC
	adds r5, r0, r1
	ldr r0, [r5]
	bl IsAllElfUnlocked
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08024088
	ldr r1, [r4]
	movs r0, #1
	strb r0, [r1, #6]
	ldr r0, [r5]
	bl IsElfBreeder
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08024088
	ldr r2, [r4]
	ldrb r1, [r2, #7]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #7]
_08024088:
	bl allSecretDiskFound
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080240A2
	ldr r0, _0802419C @ =gScore
	ldr r2, [r0]
	ldrb r1, [r2, #7]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #7]
_080240A2:
	ldr r0, _080241A0 @ =gGameState
	ldr r2, _080241A4 @ =0x000064AC
	adds r0, r0, r2
	ldr r0, [r0]
	bl CalcElfPenalty
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802419C @ =gScore
	ldr r1, [r2, #0x10]
	adds r1, r1, r0
	movs r7, #1
	rsbs r7, r7, #0
	str r1, [r2, #0x10]
	bl CalcMissionScore
	ldr r5, _080241A8 @ =gVideoRegBuffer+6
	movs r3, #0x81
	lsls r3, r3, #2
	adds r0, r3, #0
	strh r0, [r5]
	adds r1, r5, #0
	adds r1, #0xa
	movs r0, #0
	str r0, [r1]
	subs r2, r5, #6
	ldrh r1, [r2]
	ldr r0, _080241AC @ =0x0000F0FF
	ands r0, r1
	movs r3, #0x98
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080241B0 @ =gGraphic_Capcom+(22*20)
	movs r4, #0xc
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, _080241B4 @ =gGraphic_Capcom+(22*20)+12
	movs r1, #0
	bl LoadPalette
	ldr r0, _080241B8 @ =gGraphic_CodeName
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #0xc
	adds r1, r4, #0
	bl LoadGraphic
	ldr r0, _080241BC @ =0x085475E8
	movs r1, #0
	bl LoadPalette
	ldrh r1, [r5]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	ldr r2, _080241C0 @ =0x08522430
	ldr r1, [r2]
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0
	bl CopyBgMap
	bl PauseAllPaletteAnimations
	movs r0, #0x40
	movs r1, #0
	bl StartPaletteAnimation
	ldr r2, _080241C4 @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080241C8 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _080241CC @ =gStageRun
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, #0xbe
	beq _0802416A
	cmp r0, r7
	beq _08024160
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FadeOutBGM
	str r7, [r4]
_08024160:
	movs r0, #0xbe
	bl PlayBGM
	movs r0, #0xbe
	str r0, [r4]
_0802416A:
	ldr r0, _080241CC @ =gStageRun
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #9
	str r1, [r0]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_0802417C:
	movs r0, #0x40
	bl StepPaletteAnimation
	ldr r0, _080241CC @ =gStageRun
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r2, [r0]
	cmp r2, #0
	beq _08024192
	b _080242E4
_08024192:
	ldr r0, _080241D0 @ =gPaletteManager
	movs r1, #0
	strh r2, [r0]
	strb r1, [r6, #1]
	b _0802425A
	.align 2, 0
_0802419C: .4byte gScore
_080241A0: .4byte gGameState
_080241A4: .4byte 0x000064AC
_080241A8: .4byte gVideoRegBuffer+6
_080241AC: .4byte 0x0000F0FF
_080241B0: .4byte gGraphic_Capcom+(22*20)
_080241B4: .4byte gGraphic_Capcom+(22*20)+12
_080241B8: .4byte gGraphic_CodeName
_080241BC: .4byte gPalette_CodeName
_080241C0: .4byte gBgMapOffsets+400
_080241C4: .4byte gWindowRegBuffer
_080241C8: .4byte 0x0000BFFF
_080241CC: .4byte gStageRun
_080241D0: .4byte gPaletteManager
_080241D4:
	movs r0, #0x40
	bl StepPaletteAnimation
	adds r0, r6, #0
	bl printPlayerAllScore
	cmp r0, #1
	bne _080241E6
	b _080242E4
_080241E6:
	movs r0, #0
	strb r0, [r6, #1]
	b _0802425A
_080241EC:
	movs r0, #0x40
	bl StepPaletteAnimation
	adds r0, r6, #0
	bl getStageRewardChip
	cmp r0, #1
	beq _080242E4
	movs r0, #0
	strb r0, [r6, #1]
	b _0802425A
_08024202:
	movs r0, #0x40
	bl StepPaletteAnimation
	adds r0, r6, #0
	bl getStageRewardExSkill
	cmp r0, #1
	beq _080242E4
	movs r0, #0
	strb r0, [r6, #1]
	b _0802425A
_08024218:
	movs r0, #0x40
	bl StepPaletteAnimation
	adds r0, r6, #0
	bl FUN_080248f0
	cmp r0, #1
	beq _080242E4
	movs r0, #0
	strb r0, [r6, #1]
	b _0802425A
_0802422E:
	movs r0, #0x40
	bl StepPaletteAnimation
	ldr r4, _08024264 @ =gStageRun
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r7, r4, r0
	ldr r0, [r7]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, r5
	beq _08024250
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FadeOutBGM
	str r5, [r7]
_08024250:
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0xa
	str r0, [r1]
_0802425A:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _080242E4
	.align 2, 0
_08024264: .4byte gStageRun
_08024268:
	movs r0, #0x40
	bl StepPaletteAnimation
	ldr r0, _080242C4 @ =gStageRun
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _080242E4
	ldr r2, _080242C8 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080242CC @ =0x0000EDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x40
	bl RemovePaletteAnimation
	bl ResumeAllPaletteAnimations
	movs r0, #0x3c
	strh r0, [r6, #4]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_0802429A:
	ldrh r0, [r6, #4]
	movs r2, #4
	ldrsh r1, [r6, r2]
	cmp r1, #0
	bne _080242E0
	ldr r0, _080242D0 @ =gScore
	ldr r0, [r0]
	adds r0, #0x4c
	strb r1, [r0]
	ldr r1, _080242D4 @ =gGameState
	ldr r3, _080242D8 @ =0x000064AC
	adds r0, r1, r3
	ldr r0, [r0]
	ldr r2, _080242DC @ =0x00006460
	adds r1, r1, r2
	bl StoreZeroStatus
	bl ResultScreen_UpdateAndRenderWidget
	movs r0, #0
	b _080242EA
	.align 2, 0
_080242C4: .4byte gStageRun
_080242C8: .4byte gVideoRegBuffer
_080242CC: .4byte 0x0000EDFF
_080242D0: .4byte gScore
_080242D4: .4byte gGameState
_080242D8: .4byte 0x000064AC
_080242DC: .4byte 0x00006460
_080242E0:
	subs r0, #1
	strh r0, [r6, #4]
_080242E4:
	bl ResultScreen_UpdateAndRenderWidget
	movs r0, #1
_080242EA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
