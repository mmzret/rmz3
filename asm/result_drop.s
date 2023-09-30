	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start prepareResultScreen
prepareResultScreen: @ 0x08023F00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	bl FUN_08024db4
	ldr r1, _08023FEC @ =gWindowRegBuffer
	movs r2, #0
	strh r2, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xe]
	ldr r0, _08023FF0 @ =gBlendRegBuffer
	strh r2, [r0]
	movs r4, #0x8c
	lsls r4, r4, #1
	ldr r0, _08023FF4 @ =gStaticMotionGraphics
	mov r8, r0
	adds r0, r4, r0
	ldr r6, _08023FF8 @ =wStaticGraphicTilenums
	ldrh r1, [r6, #0x1c]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08023FFC @ =gStaticMotionGraphics+12
	mov sl, r0
	add r4, sl
	ldr r5, _08024000 @ =wStaticMotionPalIDs
	ldrh r1, [r5, #0x1c]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _08024004 @ =0x000009EC
	add r8, r4
	adds r6, #0xfe
	ldrh r1, [r6]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	add r4, sl
	adds r5, #0xfe
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r0, #0xe4
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r4, #0
	ldr r0, _08024008 @ =gStageDiskManager
	ldrb r1, [r0, #0xe]
	cmp r4, r1
	bhs _08023FC6
	adds r5, r0, #0
_08023FA2:
	lsls r0, r4, #0xc
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [sp]
	adds r0, r5, #4
	adds r0, r4, r0
	ldrb r1, [r0]
	mov r0, sp
	movs r2, #0
	bl CreateDiskIcon
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrb r0, [r5, #0xe]
	cmp r4, r0
	blo _08023FA2
_08023FC6:
	movs r0, #0
	strb r0, [r7, #3]
	strb r0, [r7, #2]
	strb r0, [r7, #1]
	strb r0, [r7]
	strh r0, [r7, #0xa]
	strh r0, [r7, #8]
	strh r0, [r7, #6]
	strh r0, [r7, #4]
	str r0, [r7, #0xc]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023FEC: .4byte gWindowRegBuffer
_08023FF0: .4byte gBlendRegBuffer
_08023FF4: .4byte gStaticMotionGraphics
_08023FF8: .4byte wStaticGraphicTilenums
_08023FFC: .4byte gStaticMotionGraphics+12
_08024000: .4byte wStaticMotionPalIDs
_08024004: .4byte 0x000009EC
_08024008: .4byte gStageDiskManager

	thumb_func_start result_0802400c
result_0802400c: @ 0x0802400C
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
	ldr r4, _0802419C @ =gMission
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
	ldr r0, _0802419C @ =gMission
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
	bl calcElfPenalty
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802419C @ =gMission
	ldr r1, [r2, #0x10]
	adds r1, r1, r0
	movs r7, #1
	rsbs r7, r7, #0
	str r1, [r2, #0x10]
	bl calcStageScore
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
	ldr r0, _080241B0 @ =gGraphic_MenuMisc
	movs r4, #0xc
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, _080241B4 @ =gGraphic_MenuMisc+12
	movs r1, #0
	bl LoadPalette
	ldr r0, _080241B8 @ =gGraphics_CodeName
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
	bl PauseAllBlinks
	movs r0, #0x40
	movs r1, #0
	bl LoadBlink
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
	bl fadeoutBGM
	str r7, [r4]
_08024160:
	movs r0, #0xbe
	bl playBGM
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
	bl UpdateBlinkMotionState
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
_0802419C: .4byte gMission
_080241A0: .4byte gGameState
_080241A4: .4byte 0x000064AC
_080241A8: .4byte gVideoRegBuffer+6
_080241AC: .4byte 0x0000F0FF
_080241B0: .4byte gGraphic_MenuMisc
_080241B4: .4byte gGraphic_MenuMisc+12
_080241B8: .4byte gGraphics_CodeName
_080241BC: .4byte gGraphics_CodeName+12
_080241C0: .4byte gBgMapOffsets+400
_080241C4: .4byte gWindowRegBuffer
_080241C8: .4byte 0x0000BFFF
_080241CC: .4byte gStageRun
_080241D0: .4byte gPaletteManager
_080241D4:
	movs r0, #0x40
	bl UpdateBlinkMotionState
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
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl getStageRewardChip
	cmp r0, #1
	beq _080242E4
	movs r0, #0
	strb r0, [r6, #1]
	b _0802425A
_08024202:
	movs r0, #0x40
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl getStageRewardExSkill
	cmp r0, #1
	beq _080242E4
	movs r0, #0
	strb r0, [r6, #1]
	b _0802425A
_08024218:
	movs r0, #0x40
	bl UpdateBlinkMotionState
	adds r0, r6, #0
	bl FUN_080248f0
	cmp r0, #1
	beq _080242E4
	movs r0, #0
	strb r0, [r6, #1]
	b _0802425A
_0802422E:
	movs r0, #0x40
	bl UpdateBlinkMotionState
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
	bl fadeoutBGM
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
	bl UpdateBlinkMotionState
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
	bl ClearBlink
	bl ResumeAllBlinks
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
	ldr r0, _080242D0 @ =gMission
	ldr r0, [r0]
	adds r0, #0x4c
	strb r1, [r0]
	ldr r1, _080242D4 @ =gGameState
	ldr r3, _080242D8 @ =0x000064AC
	adds r0, r1, r3
	ldr r0, [r0]
	ldr r2, _080242DC @ =0x00006460
	adds r1, r1, r2
	bl CopyZeroStatus
	bl result_08024e0c
	movs r0, #0
	b _080242EA
	.align 2, 0
_080242C4: .4byte gStageRun
_080242C8: .4byte gVideoRegBuffer
_080242CC: .4byte 0x0000EDFF
_080242D0: .4byte gMission
_080242D4: .4byte gGameState
_080242D8: .4byte 0x000064AC
_080242DC: .4byte 0x00006460
_080242E0:
	subs r0, #1
	strh r0, [r6, #4]
_080242E4:
	bl result_08024e0c
	movs r0, #1
_080242EA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start printPlayerAllScore
printPlayerAllScore: @ 0x080242F0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	ldr r0, _0802431C @ =gJoypad
	ldrh r1, [r0]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0802430A
	movs r6, #1
	ldr r0, _08024320 @ =0x00004E21
	strh r0, [r5, #4]
_0802430A:
	ldrb r0, [r5, #1]
	cmp r0, #0x17
	bls _08024312
	b _08024774
_08024312:
	lsls r0, r0, #2
	ldr r1, _08024324 @ =_08024328
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802431C: .4byte gJoypad
_08024320: .4byte 0x00004E21
_08024324: .4byte _08024328
_08024328: @ jump table
	.4byte _08024388 @ case 0
	.4byte _080243AE @ case 1
	.4byte _080243C8 @ case 2
	.4byte _080243F2 @ case 3
	.4byte _0802444A @ case 4
	.4byte _08024464 @ case 5
	.4byte _0802448C @ case 6
	.4byte _080244BC @ case 7
	.4byte _080244D6 @ case 8
	.4byte _08024500 @ case 9
	.4byte _08024530 @ case 10
	.4byte _0802454A @ case 11
	.4byte _08024574 @ case 12
	.4byte _080245A4 @ case 13
	.4byte _080245BE @ case 14
	.4byte _080245E8 @ case 15
	.4byte _0802461C @ case 16
	.4byte _08024636 @ case 17
	.4byte _08024664 @ case 18
	.4byte _0802467E @ case 19
	.4byte _080246AA @ case 20
	.4byte _080246C2 @ case 21
	.4byte _080246F4 @ case 22
	.4byte _0802471C @ case 23
_08024388:
	ldr r0, _08024724 @ =gMission
	movs r1, #7
	ldrsb r1, [r0, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x10
	movs r2, #2
	bl printNumOnResultScreen
	cmp r6, #0
	bne _080243A4
	movs r0, #0x34
	bl PlaySound
_080243A4:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080243AE:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt _080243BE
	b _08024774
_080243BE:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080243C8:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldrb r0, [r0, #0x16]
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #2
	str r2, [sp]
	movs r2, #3
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	bne _080243E8
	b _08024774
_080243E8:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080243F2:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt _08024402
	b _08024774
_08024402:
	ldr r4, _08024724 @ =gMission
	ldr r0, [r4, #8]
	movs r1, #0xe1
	lsls r1, r1, #4
	bl __udivsi3
	movs r1, #0xe
	movs r2, #3
	bl printNumOnResultScreen
	ldr r0, [r4, #8]
	movs r1, #0x3c
	bl __udivsi3
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0x11
	movs r2, #3
	bl printNumOnResultScreen
	movs r0, #0
	movs r1, #0x10
	movs r2, #3
	bl printNumOnResultScreen
	cmp r6, #0
	bne _08024440
	movs r0, #0x34
	bl PlaySound
_08024440:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0802444A:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt _0802445A
	b _08024774
_0802445A:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_08024464:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldrb r0, [r0, #0x17]
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #3
	str r2, [sp]
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	bne _08024482
	b _08024774
_08024482:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0802448C:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt _0802449C
	b _08024774
_0802449C:
	ldr r0, _08024724 @ =gMission
	ldrh r0, [r0, #0xc]
	movs r1, #0x11
	movs r2, #4
	bl printNumOnResultScreen
	cmp r6, #0
	bne _080244B2
	movs r0, #0x34
	bl PlaySound
_080244B2:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080244BC:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt _080244CC
	b _08024774
_080244CC:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080244D6:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldrb r0, [r0, #0x18]
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #4
	str r2, [sp]
	movs r2, #3
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	bne _080244F6
	b _08024774
_080244F6:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_08024500:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt _08024510
	b _08024774
_08024510:
	ldr r0, _08024724 @ =gMission
	ldrh r0, [r0, #0xe]
	movs r1, #0x11
	movs r2, #5
	bl printNumOnResultScreen
	cmp r6, #0
	bne _08024526
	movs r0, #0x34
	bl PlaySound
_08024526:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_08024530:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt _08024540
	b _08024774
_08024540:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0802454A:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldrb r0, [r0, #0x19]
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #5
	str r2, [sp]
	movs r2, #3
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	bne _0802456A
	b _08024774
_0802456A:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_08024574:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt _08024584
	b _08024774
_08024584:
	ldr r0, _08024724 @ =gMission
	ldrh r0, [r0, #0x14]
	movs r1, #0x11
	movs r2, #6
	bl printNumOnResultScreen
	cmp r6, #0
	bne _0802459A
	movs r0, #0x34
	bl PlaySound
_0802459A:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080245A4:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt _080245B4
	b _08024774
_080245B4:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080245BE:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldrb r0, [r0, #0x1a]
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #6
	str r2, [sp]
	movs r2, #3
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	bne _080245DE
	b _08024774
_080245DE:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080245E8:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt _080245F8
	b _08024774
_080245F8:
	ldr r0, _08024724 @ =gMission
	ldr r0, [r0]
	adds r0, #0x4c
	ldrb r0, [r0]
	movs r1, #0x11
	movs r2, #7
	bl printNumOnResultScreen
	cmp r6, #0
	bne _08024612
	movs r0, #0x34
	bl PlaySound
_08024612:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0802461C:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt _0802462C
	b _08024774
_0802462C:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_08024636:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldrb r0, [r0, #0x1b]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #7
	str r2, [sp]
	movs r2, #3
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	bne _0802465A
	b _08024774
_0802465A:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_08024664:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt _08024674
	b _08024774
_08024674:
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0802467E:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldrb r0, [r0, #5]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #9
	str r2, [sp]
	movs r2, #3
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	beq _08024774
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080246AA:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _08024774
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080246C2:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	ldr r0, _08024724 @ =gMission
	ldr r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	ldrb r1, [r1, #0x10]
	bl __divsi3
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #0xa
	str r2, [sp]
	movs r2, #3
	movs r3, #0x18
	bl printResultScore
	cmp r0, #1
	beq _08024774
	movs r0, #0
	strh r0, [r5, #4]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080246F4:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1d
	ble _08024774
	ldr r0, _08024724 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	bl FUN_08024b54
	movs r0, #0x1d
	bl PlaySound
	movs r0, #0
	strh r0, [r5, #6]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0802471C:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _08024728
	.align 2, 0
_08024724: .4byte gMission
_08024728:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3b
	ble _08024774
	ldr r0, _08024744 @ =gStageRun
	ldrh r0, [r0]
	cmp r0, #0x10
	beq _0802474C
	ldr r0, _08024748 @ =gMission
	ldr r1, [r0]
	ldrb r0, [r1, #4]
	strb r0, [r5, #0x18]
	ldrb r0, [r1, #2]
	b _08024756
	.align 2, 0
_08024744: .4byte gStageRun
_08024748: .4byte gMission
_0802474C:
	ldr r0, _08024770 @ =gMission
	ldr r1, [r0]
	ldrb r0, [r1, #9]
	strb r0, [r5, #0x18]
	ldrb r0, [r1, #8]
_08024756:
	strb r0, [r5, #0x19]
	adds r0, r5, #0
	bl FUN_08024b98
	adds r0, r5, #0
	bl FUN_08024c48
	movs r0, #0xc7
	bl PlaySound
	movs r0, #0
	b _08024776
	.align 2, 0
_08024770: .4byte gMission
_08024774:
	movs r0, #1
_08024776:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start getStageRewardChip
getStageRewardChip: @ 0x08024780
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _080247B4 @ =gGameState
	ldr r1, _080247B8 @ =0x000064AC
	adds r0, r0, r1
	ldr r3, [r0]
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _08024844
	ldr r0, _080247BC @ =StageChipTypes
	ldr r1, _080247C0 @ =gStageRun
	ldrh r4, [r1]
	adds r2, r4, r0
	ldrb r0, [r2]
	adds r7, r1, #0
	cmp r0, #0
	beq _08024844
	adds r2, r0, #0
	cmp r2, #2
	beq _080247EC
	cmp r2, #2
	bgt _080247C4
	cmp r2, #1
	beq _080247CA
	b _0802482E
	.align 2, 0
_080247B4: .4byte gGameState
_080247B8: .4byte 0x000064AC
_080247BC: .4byte StageChipTypes
_080247C0: .4byte gStageRun
_080247C4:
	cmp r2, #3
	beq _08024810
	b _0802482E
_080247CA:
	adds r5, r3, #0
	adds r5, #0xb4
	ldrb r3, [r5, #0x17]
	ldr r0, _080247E8 @ =StageChipIDs
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r2, r1
	adds r0, r3, #0
	ands r0, r2
	asrs r0, r1
	cmp r0, #0
	bne _0802484C
	orrs r3, r2
	strb r3, [r5, #0x17]
	b _0802482E
	.align 2, 0
_080247E8: .4byte StageChipIDs
_080247EC:
	adds r5, r3, #0
	adds r5, #0xb4
	ldrb r2, [r5, #0x18]
	ldr r0, _0802480C @ =StageChipIDs
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r3, #1
	lsls r3, r1
	adds r0, r2, #0
	ands r0, r3
	asrs r0, r1
	cmp r0, #0
	bne _0802484C
	orrs r2, r3
	strb r2, [r5, #0x18]
	b _0802482E
	.align 2, 0
_0802480C: .4byte StageChipIDs
_08024810:
	adds r5, r3, #0
	adds r5, #0xb4
	ldrb r2, [r5, #0x19]
	ldr r0, _08024850 @ =StageChipIDs
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r3, #1
	lsls r3, r1
	adds r0, r2, #0
	ands r0, r3
	asrs r0, r1
	cmp r0, #0
	bne _0802484C
	orrs r2, r3
	strb r2, [r5, #0x19]
_0802482E:
	ldr r1, _08024854 @ =UnlockEquipTextIDs
	ldrh r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0
	bl PrintResultInline
	ldrb r0, [r6, #1]
	adds r0, #1
	strb r0, [r6, #1]
_08024844:
	ldr r0, _08024858 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _0802485C
_0802484C:
	movs r0, #0
	b _0802485E
	.align 2, 0
_08024850: .4byte StageChipIDs
_08024854: .4byte UnlockEquipTextIDs
_08024858: .4byte gTextWindow+8
_0802485C:
	movs r0, #1
_0802485E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start getStageRewardExSkill
getStageRewardExSkill: @ 0x08024864
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080248D0 @ =gGameState
	ldr r1, _080248D4 @ =0x000064AC
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0xb4
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	beq _080248CC
	ldrb r0, [r5, #1]
	cmp r0, #0
	bne _080248C4
	ldr r1, _080248D8 @ =StageRewardExSkills
	ldr r7, _080248DC @ =gStageRun
	ldrh r0, [r7]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0xff
	beq _080248BE
	ldr r0, [r5, #0x10]
	cmp r0, #4
	bls _080248BE
	ldrh r2, [r4, #0x14]
	movs r6, #1
	adds r1, r6, #0
	lsls r1, r3
	adds r0, r2, #0
	ands r0, r1
	asrs r0, r3
	cmp r0, #0
	bne _080248CC
	orrs r2, r1
	strh r2, [r4, #0x14]
	ldr r0, _080248E0 @ =UnlockExSkillTextIDs
	ldrh r1, [r7]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r1, #0
	bl PrintResultInline
	str r6, [r5, #0xc]
_080248BE:
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_080248C4:
	ldr r0, _080248E4 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080248E8
_080248CC:
	movs r0, #0
	b _080248EA
	.align 2, 0
_080248D0: .4byte gGameState
_080248D4: .4byte 0x000064AC
_080248D8: .4byte StageRewardExSkills
_080248DC: .4byte gStageRun
_080248E0: .4byte UnlockExSkillTextIDs
_080248E4: .4byte gTextWindow+8
_080248E8:
	movs r0, #1
_080248EA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080248f0
FUN_080248f0: @ 0x080248F0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #1]
	cmp r5, #0
	bne _0802491A
	movs r1, #0
	movs r2, #0
	bl CreateMenuComp2
	str r0, [r4, #0x14]
	adds r0, #0x74
	movs r1, #0x18
	strh r1, [r0]
	ldr r0, [r4, #0x14]
	adds r0, #0x76
	movs r1, #0x72
	strh r1, [r0]
	strh r5, [r4, #6]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_0802491A:
	ldr r0, _0802494C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _08024924
	b _08024A64
_08024924:
	movs r5, #0
	ldrh r2, [r4, #6]
	strh r2, [r4, #4]
	ldr r0, _08024950 @ =gStageDiskManager
	ldrb r1, [r0, #0xe]
	adds r3, r0, #0
	cmp r1, #0
	beq _0802497C
	ldr r0, _08024954 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802495C
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _08024958
	subs r0, r2, #1
	b _0802495A
	.align 2, 0
_0802494C: .4byte gTextWindow+8
_08024950: .4byte gStageDiskManager
_08024954: .4byte gJoypad
_08024958:
	ldrb r0, [r3, #0xe]
_0802495A:
	strh r0, [r4, #6]
_0802495C:
	ldr r0, _080249DC @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802497C
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	movs r1, #6
	ldrsh r0, [r4, r1]
	ldrb r3, [r3, #0xe]
	cmp r0, r3
	ble _0802497C
	movs r0, #0
	strh r0, [r4, #6]
_0802497C:
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r2, #6
	ldrsh r0, [r4, r2]
	cmp r1, r0
	beq _0802498E
	movs r0, #1
	bl PlaySound
_0802498E:
	movs r1, #6
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _08024A0E
	ldr r0, _080249DC @ =gJoypad
	ldrh r2, [r0, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	cmp r1, #0
	beq _080249F4
	ldr r1, _080249E0 @ =gStageDiskManager
	movs r2, #6
	ldrsh r0, [r4, r2]
	adds r0, r1, r0
	ldrb r2, [r0, #3]
	ldr r0, [r1]
	lsrs r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r2
	adds r0, #4
	asrs r1, r0
	ands r1, r3
	cmp r1, #0
	bne _080249EC
	ldr r0, _080249E4 @ =gGameState
	adds r1, r2, #0
	movs r2, #1
	bl openSecretDisk
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _080249FE
	ldr r5, _080249E8 @ =0x00000101
	b _080249FE
	.align 2, 0
_080249DC: .4byte gJoypad
_080249E0: .4byte gStageDiskManager
_080249E4: .4byte gGameState
_080249E8: .4byte 0x00000101
_080249EC:
	movs r0, #4
	bl PlaySound
	b _080249FE
_080249F4:
	movs r0, #0xa
	ands r0, r2
	cmp r0, #0
	beq _080249FE
	strh r1, [r4, #6]
_080249FE:
	ldr r1, [r4, #0x14]
	movs r2, #6
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	adds r0, #0x20
	adds r1, #0x74
	strh r0, [r1]
	b _08024A2C
_08024A0E:
	ldr r0, [r4, #0x14]
	adds r0, #0x74
	movs r1, #0x18
	strh r1, [r0]
	ldr r0, _08024A28 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _08024A2C
	movs r0, #0
	b _08024A66
	.align 2, 0
_08024A28: .4byte gJoypad
_08024A2C:
	cmp r5, #0
	beq _08024A4E
	ldr r0, _08024A40 @ =0x00000101
	cmp r5, r0
	bne _08024A44
	adds r0, r5, #0
	movs r1, #1
	bl PrintResultInline
	b _08024A64
	.align 2, 0
_08024A40: .4byte 0x00000101
_08024A44:
	adds r0, r5, #0
	movs r1, #0
	bl PrintResultInline
	b _08024A64
_08024A4E:
	ldr r0, _08024A6C @ =StringOfsTable
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _08024A70 @ =gStringData
	adds r0, r0, r1
	movs r1, #1
	movs r2, #0x12
	bl PrintString
_08024A64:
	movs r0, #1
_08024A66:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08024A6C: .4byte StringOfsTable
_08024A70: .4byte gStringData

	thumb_func_start printNumOnResultScreen
printNumOnResultScreen: @ 0x08024A74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #4]
	mov r6, sb
	cmp r6, #0
	bge _08024A96
	rsbs r6, r6, #0
_08024A96:
	movs r1, #1
	movs r4, #0xa
	cmp r6, #0xa
	blo _08024AAE
_08024A9E:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r4, r0, #1
	cmp r6, r4
	bhs _08024A9E
_08024AAE:
	mov r0, sb
	cmp r0, #0
	bge _08024ABC
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08024ABE
_08024ABC:
	adds r4, r1, #0
_08024ABE:
	lsls r5, r4, #1
	adds r0, r5, #0
	bl Malloc
	mov r8, r0
	cmp r0, #0
	beq _08024B38
	mov sl, r5
	mov r1, sb
	lsrs r7, r1, #0x1f
	ldr r2, [sp]
	subs r2, r2, r4
	str r2, [sp, #0xc]
	ldr r0, [sp, #4]
	lsls r0, r0, #5
	str r0, [sp, #8]
	cmp r4, r7
	bls _08024B0A
	mov r0, sl
	subs r0, #2
	mov r1, r8
	adds r5, r0, r1
_08024AEA:
	adds r0, r6, #0
	movs r1, #0xa
	bl __umodsi3
	ldr r2, _08024B48 @ =0x00005167
	adds r0, r0, r2
	strh r0, [r5]
	subs r5, #2
	subs r4, #1
	adds r0, r6, #0
	movs r1, #0xa
	bl __udivsi3
	adds r6, r0, #0
	cmp r4, r7
	bhi _08024AEA
_08024B0A:
	mov r0, sb
	cmp r0, #0
	bge _08024B18
	ldr r1, _08024B4C @ =0x00005174
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
_08024B18:
	ldr r1, _08024B50 @ =gVideoRegBuffer+6
	ldrh r0, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	ldr r0, [sp, #8]
	adds r0, #1
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	lsls r0, r0, #1
	adds r1, r1, r0
	mov r0, r8
	mov r2, sl
	bl RequestBgMapTransfer
_08024B38:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024B48: .4byte 0x00005167
_08024B4C: .4byte 0x00005174
_08024B50: .4byte gVideoRegBuffer+6

	thumb_func_start FUN_08024b54
FUN_08024b54: @ 0x08024B54
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #2
	bl Malloc
	adds r2, r0, #0
	cmp r2, #0
	beq _08024B86
	ldr r1, _08024B8C @ =0x00005166
	adds r0, r1, #0
	subs r0, r0, r4
	strh r0, [r2]
	ldr r0, _08024B90 @ =gVideoRegBuffer+6
	ldrh r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	ldr r0, _08024B94 @ =0x000002E2
	adds r1, r1, r0
	adds r0, r2, #0
	movs r2, #2
	bl RequestBgMapTransfer
_08024B86:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024B8C: .4byte 0x00005166
_08024B90: .4byte gVideoRegBuffer+6
_08024B94: .4byte 0x000002E2

	thumb_func_start FUN_08024b98
FUN_08024b98: @ 0x08024B98
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0x10
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08024C32
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	bne _08024BEC
	movs r0, #0
	ldr r1, _08024BE0 @ =gVideoRegBuffer+6
	mov ip, r1
	ldr r7, _08024BE4 @ =u8_ARRAY_083863e8
	ldr r1, _08024BE8 @ =0xFFFFF300
	adds r6, r1, #0
_08024BBA:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	adds r3, r3, r4
	ldrb r1, [r5, #0x19]
	lsls r1, r1, #1
	adds r1, r1, r7
	adds r0, r6, r0
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #7
	ble _08024BBA
	b _08024C1A
	.align 2, 0
_08024BE0: .4byte gVideoRegBuffer+6
_08024BE4: .4byte u8_ARRAY_083863e8
_08024BE8: .4byte 0xFFFFF300
_08024BEC:
	movs r0, #0
	ldr r1, _08024C38 @ =gVideoRegBuffer+6
	mov ip, r1
	ldr r7, _08024C3C @ =u8_ARRAY_083863d0
	ldr r1, _08024C40 @ =0xFFFFF300
	adds r6, r1, #0
_08024BF8:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	adds r3, r3, r4
	ldrb r1, [r5, #0x18]
	lsls r1, r1, #1
	adds r1, r1, r7
	adds r0, r6, r0
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #7
	ble _08024BF8
_08024C1A:
	mov r1, ip
	ldrh r0, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	ldr r0, _08024C44 @ =0x00000322
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0x10
	bl RequestBgMapTransfer
_08024C32:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024C38: .4byte gVideoRegBuffer+6
_08024C3C: .4byte u8_ARRAY_083863d0
_08024C40: .4byte 0xFFFFF300
_08024C44: .4byte 0x00000322

	thumb_func_start FUN_08024c48
FUN_08024c48: @ 0x08024C48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0x18]
	cmp r0, #0
	beq _08024CF2
	ldr r0, _08024D00 @ =u8_ARRAY_083863e8
	mov r8, r0
	ldrb r0, [r6, #0x19]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #1
	adds r0, r0, r1
	ldrb r5, [r0]
	lsls r4, r5, #1
	adds r0, r4, #0
	bl Malloc
	adds r7, r0, #0
	cmp r7, #0
	beq _08024CF2
	movs r0, #0
	mov sb, r4
	ldr r1, _08024D04 @ =u8_ARRAY_083863d0
	mov ip, r1
	ldr r3, _08024D08 @ =gVideoRegBuffer+6
	mov sl, r3
	cmp r0, r5
	bge _08024CAE
	ldr r1, _08024D0C @ =0xFFFFF300
	adds r4, r1, #0
_08024C8C:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	adds r3, r3, r7
	ldrb r1, [r6, #0x19]
	lsls r1, r1, #1
	add r1, r8
	adds r0, r4, r0
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, r5
	blt _08024C8C
_08024CAE:
	ldrb r0, [r6, #0x18]
	lsls r0, r0, #1
	mov r1, ip
	adds r1, #1
	adds r0, r0, r1
	ldrb r2, [r0]
	adds r1, r2, r5
	cmp r1, #9
	ble _08024CCC
	subs r1, #9
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_08024CCC:
	cmp r5, #8
	bne _08024CD6
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_08024CD6:
	mov r3, sl
	ldrh r0, [r3]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	ldr r3, _08024D10 @ =0x000001B1
	adds r0, r2, r3
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r0, r7, #0
	mov r2, sb
	bl RequestBgMapTransfer
_08024CF2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024D00: .4byte u8_ARRAY_083863e8
_08024D04: .4byte u8_ARRAY_083863d0
_08024D08: .4byte gVideoRegBuffer+6
_08024D0C: .4byte 0xFFFFF300
_08024D10: .4byte 0x000001B1

	thumb_func_start printResultScore
printResultScore: @ 0x08024D14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [sp, #0x28]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	mov r2, sb
	str r2, [sp]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	str r0, [sp, #4]
	asrs r0, r7, #4
	movs r2, #1
	mov sl, r2
	cmp r0, #0
	beq _08024D4A
	mov sl, r0
_08024D4A:
	cmp r5, #0
	bne _08024D56
	adds r0, r7, #0
	mov r1, sb
	mov r2, r8
	b _08024D9C
_08024D56:
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r6, #0
	muls r0, r5, r0
	cmp r0, r4
	bne _08024D72
	movs r0, #0x34
	bl PlaySound
_08024D72:
	mov r0, sl
	muls r0, r6, r0
	adds r2, r0, #0
	cmp r0, #0
	bge _08024D7E
	rsbs r2, r0, #0
_08024D7E:
	adds r1, r7, #0
	cmp r7, #0
	bge _08024D86
	rsbs r1, r7, #0
_08024D86:
	cmp r2, r1
	bgt _08024D96
	mov r1, sb
	mov r2, r8
	bl printNumOnResultScreen
	movs r0, #1
	b _08024DA2
_08024D96:
	adds r0, r7, #0
	ldr r1, [sp]
	ldr r2, [sp, #4]
_08024D9C:
	bl printNumOnResultScreen
	movs r0, #0
_08024DA2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08024db4
FUN_08024db4: @ 0x08024DB4
	push {r4, r5, r6, lr}
	ldr r4, _08024DFC @ =0x02031924
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r4, #4]
	adds r6, r4, #0
	subs r6, #0xc
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl ResetPivot
	ldr r0, _08024E00 @ =0xFFFFFDE8
	adds r5, r4, r0
	adds r0, r5, #0
	bl ResetTaskManager
	adds r0, r5, #0
	adds r1, r6, #0
	bl SetTaskPivot
	ldr r0, _08024E04 @ =0xFFFFFBB4
	adds r4, r4, r0
	ldr r1, _08024E08 @ =gWidgets
	adds r0, r4, #0
	movs r2, #0x40
	bl InitWidgetHeader
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08024DFC: .4byte 0x02031924
_08024E00: .4byte 0xFFFFFDE8
_08024E04: .4byte 0xFFFFFBB4
_08024E08: .4byte gWidgets

	thumb_func_start result_08024e0c
result_08024e0c: @ 0x08024E0C
	push {r4, r5, lr}
	ldr r5, _08024E48 @ =0x02031924
	ldr r0, _08024E4C @ =gVideoRegBuffer+16
	ldrh r1, [r0]
	ldr r0, _08024E50 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r5]
	ldr r0, _08024E54 @ =0xFFFFFDE8
	adds r5, r5, r0
	adds r0, r5, #0
	bl ClearTaskBuffer
	ldr r4, _08024E58 @ =gWidgetHeaderPtr
	ldr r0, [r4]
	bl UpdateEntities
	ldr r0, [r4]
	adds r1, r5, #0
	bl DrawEntity
	adds r0, r5, #0
	bl RunAllTasks
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08024E48: .4byte 0x02031924
_08024E4C: .4byte gVideoRegBuffer+16
_08024E50: .4byte 0x000001FF
_08024E54: .4byte 0xFFFFFDE8
_08024E58: .4byte gWidgetHeaderPtr

	thumb_func_start TryDropItem
TryDropItem: @ 0x08024E5C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	ldr r2, _08024EB0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08024EB4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08024EB8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r3, #8
	bls _08024ED2
	adds r0, r3, #0
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _08024EBC @ =gStageDiskManager
	ldr r1, [r0]
	ldr r0, _08024EC0 @ =0x0835DCDA
	adds r3, r4, r0
	movs r2, #0
	ldrsb r2, [r3, r2]
	subs r2, #1
	asrs r0, r2, #2
	adds r1, r1, r0
	ldrb r1, [r1]
	movs r0, #0xf
	ands r0, r1
	movs r1, #3
	ands r2, r1
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08024EC4
	movs r0, #0
	b _08024F2C
	.align 2, 0
_08024EB0: .4byte RNG_0202f388
_08024EB4: .4byte 0x000343FD
_08024EB8: .4byte 0x00269EC3
_08024EBC: .4byte gStageDiskManager
_08024EC0: .4byte MiddleBossDiskNo
_08024EC4:
	ldrb r0, [r3]
	adds r1, r7, #0
	movs r2, #1
	bl CreateMapDisk
	movs r0, #1
	b _08024F2C
_08024ED2:
	ldr r2, _08024F34 @ =gCurStory
	ldrb r1, [r2, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08024EE0
	movs r3, #8
_08024EE0:
	ldrb r1, [r2, #8]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08024EEC
	movs r3, #5
_08024EEC:
	movs r4, #0
	ldr r5, _08024F38 @ =0x0835DC5C
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r2, r0, #1
	adds r0, r2, r5
	adds r1, r6, #0
	ldrh r0, [r0]
	cmp r1, r0
	blo _08024F18
	adds r3, r5, #0
_08024F02:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bhi _08024F18
	lsls r0, r4, #1
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r1, r0
	bhs _08024F02
_08024F18:
	cmp r4, #0
	beq _08024F2A
	subs r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	movs r2, #0
	bl CreateMapItem
_08024F2A:
	adds r0, r4, #0
_08024F2C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08024F34: .4byte gCurStory
_08024F38: .4byte MapItemDropRates

	thumb_func_start TryDropZakoDisk
TryDropZakoDisk: @ 0x08024F3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov sl, r1
	ldr r0, _08025064 @ =gStageRun
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08025068 @ =StageEnemyDiskDrops
	ldr r1, [sp]
	adds r0, r1, r0
	ldrb r4, [r0]
	ldr r2, _0802506C @ =gCurStory
	ldrb r1, [r2, #4]
	movs r0, #0x10
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _08024F6A
	b _080250A6
_08024F6A:
	ldr r3, _08025070 @ =EnemyDiskDrops
	lsls r2, r4, #4
	adds r0, r2, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	mov r8, r3
	ldr r1, [sp]
	cmp r1, r0
	beq _08024F7E
	b _080250A6
_08024F7E:
	mov ip, r3
	adds r0, r2, #0
	adds r0, #0xe
	adds r6, r0, r3
_08024F86:
	ldr r0, _08025074 @ =gOverworld
	movs r7, #0xe8
	lsls r7, r7, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r1, r0
	mov r0, ip
	adds r0, #2
	adds r0, r2, r0
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bne _08025090
	ldrb r0, [r5, #9]
	adds r1, r3, #0
	adds r1, #8
	adds r1, r2, r1
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	bne _08025090
	mov r0, ip
	adds r0, #6
	adds r0, r2, r0
	movs r1, #8
	ldrsb r1, [r5, r1]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bne _08025090
	mov r0, ip
	adds r0, #0xa
	adds r3, r2, r0
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08024FE0
	ldrb r1, [r5, #0x10]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08025090
_08024FE0:
	mov r0, ip
	adds r0, #4
	adds r5, r2, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r7, sb
	adds r7, #0xc
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _08024FFA
	adds r0, #1
	strb r0, [r1]
_08024FFA:
	movs r3, #0
	ldrsh r0, [r5, r3]
	adds r0, r0, r7
	ldrb r1, [r0]
	mov r0, ip
	adds r0, #0xc
	adds r0, r2, r0
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _080250A6
	ldr r0, _08025078 @ =gStageDiskManager
	ldr r1, [r0]
	movs r3, #0
	ldrsh r2, [r6, r3]
	subs r2, #1
	asrs r0, r2, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r4, #0xf
	ands r4, r0
	movs r0, #3
	ands r2, r0
	asrs r4, r2
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	bne _080250A6
	ldr r0, _0802507C @ =gMapItemHeaderPtr
	ldr r0, [r0]
	ldrb r2, [r6]
	movs r1, #1
	movs r3, #0
	bl countSpecificEntities2
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08025086
	ldrb r0, [r6]
	mov r1, sl
	movs r2, #0
	bl CreateMapDisk
	cmp r0, #0
	bne _08025080
	movs r0, #0
	ldrsh r1, [r5, r0]
	adds r1, r1, r7
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _080250A6
	.align 2, 0
_08025064: .4byte gStageRun
_08025068: .4byte StageEnemyDiskDrops
_0802506C: .4byte gCurStory
_08025070: .4byte EnemyDiskDrops
_08025074: .4byte gOverworld
_08025078: .4byte gStageDiskManager
_0802507C: .4byte gMapItemHeaderPtr
_08025080:
	movs r1, #0
	ldrsh r0, [r5, r1]
	b _0802508A
_08025086:
	movs r2, #0
	ldrsh r0, [r5, r2]
_0802508A:
	adds r0, r0, r7
	strb r4, [r0]
	b _080250A6
_08025090:
	adds r6, #0x10
	adds r4, #1
	mov r3, r8
	lsls r2, r4, #4
	adds r0, r2, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	ldr r1, [sp]
	cmp r1, r0
	bne _080250A6
	b _08024F86
_080250A6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

