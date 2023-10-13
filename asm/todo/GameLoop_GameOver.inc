	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #2]
	cmp r0, #4
	bls _080EF58E
	b _080EF88C
_080EF58E:
	lsls r0, r0, #2
	ldr r1, _080EF598 @ =_080EF59C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080EF598: .4byte _080EF59C
_080EF59C: @ jump table
	.4byte _080EF5B0 @ case 0
	.4byte _080EF642 @ case 1
	.4byte _080EF67E @ case 2
	.4byte _080EF738 @ case 3
	.4byte _080EF776 @ case 4
_080EF5B0:
	movs r0, #0
	strb r0, [r6, #3]
	movs r4, #0
_080EF5B6:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x94
	lsls r1, r1, #2
	bl CheckSavedataCorrect
	cmp r0, #0
	beq _080EF5CA
	movs r0, #1
	strb r0, [r6, #3]
_080EF5CA:
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _080EF5B6
	ldr r2, _080EF70C @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EF710 @ =0x0000FFF8
	ands r0, r1
	movs r4, #0
	ldr r1, _080EF714 @ =0x0000F0FF
	ands r0, r1
	movs r3, #0xf4
	lsls r3, r3, #6
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080EF718 @ =0x00000406
	adds r0, r1, #0
	strh r0, [r2, #8]
	str r4, [r2, #0x14]
	ldr r3, _080EF71C @ =0x00000606
	adds r0, r3, #0
	strh r0, [r2, #0xa]
	str r4, [r2, #0x18]
	ldr r0, _080EF720 @ =gGraphic_Capcom+(102*20)
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, _080EF724 @ =gGraphic_Capcom+(102*20)+12
	movs r1, #0
	bl LoadPalette
	ldr r5, _080EF728 @ =gBgMapOffsets
	str r4, [sp]
	movs r0, #0x24
	adds r1, r5, #0
	movs r2, #0x67
	movs r3, #0
	bl LoadBgMap
	str r4, [sp]
	movs r0, #0x38
	adds r1, r5, #0
	movs r2, #0x66
	movs r3, #0
	bl LoadBgMap
	bl text_080e9730
	bl FUN_080e981c
	strh r4, [r6, #4]
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EF642:
	ldrh r0, [r6, #4]
	adds r0, #1
	adds r2, r0, #0
	strh r0, [r6, #4]
	ldr r3, _080EF72C @ =gPaletteManager
	ldr r4, _080EF730 @ =0x00000402
	adds r1, r3, r4
	strb r2, [r1]
	movs r1, #0xff
	ands r1, r2
	subs r4, #1
	adds r2, r3, r4
	strb r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r3, r3, r2
	strb r1, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _080EF66E
	b _080EF88C
_080EF66E:
	movs r0, #0xa1
	bl playBGM
	movs r0, #0
	strh r0, [r6, #6]
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EF67E:
	ldr r0, _080EF734 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080EF6B2
	movs r0, #1
	bl PlaySound
	movs r3, #6
	ldrsh r0, [r6, r3]
	adds r0, #2
	movs r1, #3
	bl __modsi3
	adds r1, r0, #0
	strh r1, [r6, #6]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _080EF6B2
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _080EF6B2
	subs r0, r1, #1
	strh r0, [r6, #6]
_080EF6B2:
	ldr r0, _080EF734 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080EF6E6
	movs r0, #1
	bl PlaySound
	movs r4, #6
	ldrsh r0, [r6, r4]
	adds r0, #1
	movs r1, #3
	bl __modsi3
	adds r1, r0, #0
	strh r1, [r6, #6]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _080EF6E6
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _080EF6E6
	adds r0, r1, #1
	strh r0, [r6, #6]
_080EF6E6:
	ldr r0, _080EF734 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	bne _080EF6F4
	b _080EF88C
_080EF6F4:
	movs r0, #2
	bl PlaySound
	movs r0, #0xa1
	bl fadeoutBGM
	movs r0, #0x20
	strh r0, [r6, #4]
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
	b _080EF88C
	.align 2, 0
_080EF70C: .4byte gVideoRegBuffer
_080EF710: .4byte 0x0000FFF8
_080EF714: .4byte 0x0000F0FF
_080EF718: .4byte 0x00000406
_080EF71C: .4byte 0x00000606
_080EF720: .4byte gGraphic_Capcom+(102*20)
_080EF724: .4byte gGraphic_Capcom+(102*20)+12
_080EF728: .4byte gBgMapOffsets
_080EF72C: .4byte gPaletteManager
_080EF730: .4byte 0x00000402
_080EF734: .4byte gJoypad
_080EF738:
	ldrh r2, [r6, #4]
	subs r2, #1
	adds r1, r2, #0
	strh r2, [r6, #4]
	ldr r3, _080EF824 @ =gPaletteManager
	ldr r4, _080EF828 @ =0x00000402
	adds r0, r3, r4
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	subs r4, #1
	adds r1, r3, r4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r3, r3, r1
	strb r0, [r3]
	lsls r2, r2, #0x10
	cmp r2, #0
	beq _080EF762
	b _080EF88C
_080EF762:
	ldr r2, _080EF82C @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EF830 @ =0x0000C3FF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x60
	strh r0, [r6, #4]
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EF776:
	ldrh r0, [r6, #4]
	subs r0, #1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _080EF792
	movs r0, #0xa1
	bl _isSoundPlaying
	cmp r0, #0
	bne _080EF88C
_080EF792:
	movs r2, #6
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bne _080EF878
	ldr r2, _080EF834 @ =gMission
	ldr r1, [r2]
	movs r0, #2
	strb r0, [r1]
	ldr r1, [r2]
	ldr r3, _080EF838 @ =0x00006262
	adds r0, r6, r3
	ldrh r0, [r0]
	strb r0, [r1, #1]
	ldr r4, _080EF83C @ =0x00006490
	adds r0, r6, r4
	ldr r2, _080EF840 @ =0x00006460
	adds r1, r6, r2
	movs r2, #0
	bl CpuFastSet
	adds r0, r6, r4
	ldr r3, _080EF840 @ =0x00006460
	adds r1, r6, r3
	ldr r5, _080EF844 @ =0x04000003
	adds r2, r5, #0
	bl CpuSet
	ldr r0, _080EF848 @ =0x00006260
	adds r4, r6, r0
	ldrb r0, [r4]
	ldr r2, _080EF84C @ =0x000062C4
	adds r1, r6, r2
	bl resetCurStory
	ldr r3, _080EF850 @ =0x00006270
	adds r0, r6, r3
	bl saveCurStory
	ldr r1, _080EF854 @ =0x00006348
	adds r0, r6, r1
	ldr r2, _080EF858 @ =0x00006318
	adds r1, r6, r2
	movs r2, #8
	bl CpuFastSet
	ldr r3, _080EF85C @ =0x00006368
	adds r0, r6, r3
	ldr r2, _080EF860 @ =0x00006338
	adds r1, r6, r2
	ldr r2, _080EF864 @ =0x04000004
	bl CpuSet
	ldr r3, _080EF868 @ =0x000063C4
	adds r0, r6, r3
	ldr r2, _080EF86C @ =0x00006378
	adds r1, r6, r2
	movs r2, #0x10
	bl CpuFastSet
	ldr r3, _080EF870 @ =0x00006404
	adds r0, r6, r3
	ldr r2, _080EF874 @ =0x000063B8
	adds r1, r6, r2
	adds r2, r5, #0
	bl CpuSet
	ldrb r0, [r4]
	bl InitStageRun
	movs r1, #0xc0
	lsls r1, r1, #2
	b _080EF880
	.align 2, 0
_080EF824: .4byte gPaletteManager
_080EF828: .4byte 0x00000402
_080EF82C: .4byte gVideoRegBuffer
_080EF830: .4byte 0x0000C3FF
_080EF834: .4byte gMission
_080EF838: .4byte 0x00006262
_080EF83C: .4byte 0x00006490
_080EF840: .4byte 0x00006460
_080EF844: .4byte 0x04000003
_080EF848: .4byte 0x00006260
_080EF84C: .4byte 0x000062C4
_080EF850: .4byte 0x00006270
_080EF854: .4byte 0x00006348
_080EF858: .4byte 0x00006318
_080EF85C: .4byte 0x00006368
_080EF860: .4byte 0x00006338
_080EF864: .4byte 0x04000004
_080EF868: .4byte 0x000063C4
_080EF86C: .4byte 0x00006378
_080EF870: .4byte 0x00006404
_080EF874: .4byte 0x000063B8
_080EF878:
	cmp r0, #1
	bne _080EF888
	movs r1, #0x80
	lsls r1, r1, #1
_080EF880:
	adds r0, r6, #0
	bl SetGameMode
	b _080EF88C
_080EF888:
	bl ExitProcess
_080EF88C:
	ldr r5, _080EF90C @ =StringOfsTable
	movs r3, #6
	ldrsh r0, [r6, r3]
	movs r1, #0x82
	lsls r1, r1, #3
	cmp r0, #0
	beq _080EF89C
	adds r1, #2
_080EF89C:
	adds r0, r1, r5
	ldrh r0, [r0]
	ldr r4, _080EF910 @ =gStringData
	adds r0, r0, r4
	movs r1, #0
	movs r2, #8
	bl PrintString
	movs r1, #6
	ldrsh r0, [r6, r1]
	ldr r1, _080EF914 @ =0x00000414
	cmp r0, #1
	beq _080EF8B8
	adds r1, #2
_080EF8B8:
	adds r0, r1, r5
	ldrh r0, [r0]
	adds r0, r0, r4
	movs r1, #0
	movs r2, #0xa
	bl PrintString
	movs r2, #6
	ldrsh r0, [r6, r2]
	movs r1, #0x83
	lsls r1, r1, #3
	cmp r0, #2
	beq _080EF8D4
	adds r1, #2
_080EF8D4:
	adds r0, r1, r5
	ldrh r0, [r0]
	adds r0, r0, r4
	movs r1, #0
	movs r2, #0xc
	bl PrintString
	ldr r0, _080EF918 @ =gProcessManager
	movs r3, #0x98
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080EF902
	ldr r0, _080EF91C @ =gVideoRegBuffer+24
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	subs r1, #1
	strh r1, [r0, #2]
_080EF902:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EF90C: .4byte StringOfsTable
_080EF910: .4byte gStringData
_080EF914: .4byte 0x00000414
_080EF918: .4byte gProcessManager
_080EF91C: .4byte gVideoRegBuffer+24
