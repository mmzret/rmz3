	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldrb r0, [r7, #6]
	cmp r0, #0xd
	bls _080EC372
	b _080EC95E
_080EC372:
	lsls r0, r0, #2
	ldr r1, _080EC37C @ =_080EC380
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080EC37C: .4byte _080EC380
_080EC380: @ jump table
	.4byte _080EC3B8 @ case 0
	.4byte _080EC3CE @ case 1
	.4byte _080EC454 @ case 2
	.4byte _080EC48C @ case 3
	.4byte _080EC4BC @ case 4
	.4byte _080EC5CC @ case 5
	.4byte _080EC5F4 @ case 6
	.4byte _080EC6B8 @ case 7
	.4byte _080EC7C4 @ case 8
	.4byte _080EC8A0 @ case 9
	.4byte _080EC8F0 @ case 10
	.4byte _080EC924 @ case 11
	.4byte _080EC936 @ case 12
	.4byte _080EC94A @ case 13
_080EC3B8:
	ldr r1, _080EC3F8 @ =gIntro
	movs r0, #0
	str r0, [r1, #0xc]
	movs r0, #0x20
	strh r0, [r7, #8]
	movs r0, #0x96
	lsls r0, r0, #3
	strh r0, [r7, #0xa]
	ldrb r0, [r7, #6]
	adds r0, #1
	strb r0, [r7, #6]
_080EC3CE:
	adds r0, r7, #0
	bl intro_080ecd28
	ldr r1, _080EC3FC @ =0x00000236
	adds r2, r7, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080EC400
	ldrh r1, [r7, #8]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	bne _080EC3F2
	b _080EC95A
_080EC3F2:
	movs r0, #0
	b _080EC958
	.align 2, 0
_080EC3F8: .4byte gIntro
_080EC3FC: .4byte 0x00000236
_080EC400:
	ldrh r0, [r7, #0xa]
	subs r0, #1
	strh r0, [r7, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080EC42C
	ldrh r1, [r7, #8]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _080EC418
	strh r4, [r7, #8]
_080EC418:
	ldr r2, _080EC428 @ =0x00000235
	adds r1, r7, r2
	movs r0, #0x20
	strb r0, [r1]
	ldrb r0, [r7, #6]
	adds r0, #1
	b _080EC95C
	.align 2, 0
_080EC428: .4byte 0x00000235
_080EC42C:
	ldr r0, _080EC450 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080EC43A
	b _080EC95E
_080EC43A:
	movs r0, #2
	bl PlaySound
	ldrh r1, [r7, #8]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	bne _080EC44C
	b _080EC95A
_080EC44C:
	strh r4, [r7, #8]
	b _080EC95A
	.align 2, 0
_080EC450: .4byte gJoypad
_080EC454:
	ldr r3, _080EC480 @ =0x00000235
	adds r0, r7, r3
	ldrb r1, [r0]
	cmp r1, #0
	beq _080EC460
	b _080EC95E
_080EC460:
	ldr r0, _080EC484 @ =gBlendRegBuffer
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080EC488 @ =gVideoRegBuffer+4
	movs r0, #8
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r4, #0x8e
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #3
	strb r0, [r1]
	strb r2, [r7, #6]
	movs r0, #4
	strb r0, [r7, #5]
	b _080EC95E
	.align 2, 0
_080EC480: .4byte 0x00000235
_080EC484: .4byte gBlendRegBuffer
_080EC488: .4byte gVideoRegBuffer+4
_080EC48C:
	ldrh r0, [r7, #8]
	adds r0, #1
	strh r0, [r7, #8]
	movs r2, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080EC49C
	b _080EC95E
_080EC49C:
	ldr r1, _080EC4DC @ =gVideoRegBuffer+4
	movs r0, #8
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, _080EC4E0 @ =gBlendRegBuffer
	ldr r0, _080EC4E4 @ =0x00003E43
	strh r0, [r1]
	strh r2, [r7, #8]
	ldrh r1, [r7, #0x10]
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldrb r0, [r7, #6]
	adds r0, #1
	strb r0, [r7, #6]
_080EC4BC:
	adds r0, r7, #0
	bl intro_080ecd28
	ldr r3, _080EC4E8 @ =0x00000236
	adds r2, r7, r3
	ldrb r1, [r2]
	orrs r1, r0
	strb r1, [r2]
	ldrh r2, [r7, #8]
	movs r4, #8
	ldrsh r0, [r7, r4]
	cmp r0, #0x3f
	bgt _080EC4EC
	adds r0, r2, #2
	strh r0, [r7, #8]
	b _080EC4FA
	.align 2, 0
_080EC4DC: .4byte gVideoRegBuffer+4
_080EC4E0: .4byte gBlendRegBuffer
_080EC4E4: .4byte 0x00003E43
_080EC4E8: .4byte 0x00000236
_080EC4EC:
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _080EC4FA
	movs r0, #0
	strh r0, [r7, #8]
	movs r0, #6
	strb r0, [r7, #6]
_080EC4FA:
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r5, [r0]
	ldr r0, _080EC5C0 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080EC540
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r4, r7, r2
_080EC514:
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #3
	bl __modsi3
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080EC540
	cmp r1, #1
	bne _080EC532
	ldrh r0, [r7, #0x10]
	cmp r0, #0
	bne _080EC540
_080EC532:
	cmp r1, #2
	bne _080EC514
	bl IsAnyMinigameUnlocked
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080EC514
_080EC540:
	ldr r0, _080EC5C0 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080EC57E
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r4, r7, r3
_080EC552:
	ldrb r0, [r4]
	adds r0, #2
	movs r1, #3
	bl __modsi3
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080EC57E
	cmp r1, #1
	bne _080EC570
	ldrh r0, [r7, #0x10]
	cmp r0, #0
	bne _080EC57E
_080EC570:
	cmp r1, #2
	bne _080EC552
	bl IsAnyMinigameUnlocked
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080EC552
_080EC57E:
	movs r4, #0x8e
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r5, r0
	beq _080EC590
	movs r0, #1
	bl PlaySound
_080EC590:
	ldr r1, _080EC5C4 @ =0x00000236
	adds r0, r7, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _080EC59C
	b _080EC95E
_080EC59C:
	ldr r0, _080EC5C0 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	bne _080EC5AA
	b _080EC95E
_080EC5AA:
	movs r0, #2
	bl PlaySound
	ldr r2, _080EC5C8 @ =0x00000235
	adds r1, r7, r2
	movs r0, #0x20
	strb r0, [r1]
	strh r4, [r7, #8]
	ldrb r0, [r7, #6]
	adds r0, #1
	b _080EC95C
	.align 2, 0
_080EC5C0: .4byte gJoypad
_080EC5C4: .4byte 0x00000236
_080EC5C8: .4byte 0x00000235
_080EC5CC:
	ldrh r0, [r7, #8]
	adds r0, #1
	strh r0, [r7, #8]
	ldr r3, _080EC5EC @ =0x00000235
	adds r0, r7, r3
	ldrb r1, [r0]
	cmp r1, #0
	beq _080EC5DE
	b _080EC95E
_080EC5DE:
	ldr r0, _080EC5F0 @ =gBlendRegBuffer
	strh r1, [r0]
	movs r0, #0
	strb r0, [r7, #6]
	movs r0, #4
	strb r0, [r7, #5]
	b _080ECC2A
	.align 2, 0
_080EC5EC: .4byte 0x00000235
_080EC5F0: .4byte gBlendRegBuffer
_080EC5F4:
	adds r0, r7, #0
	bl intro_080ecd28
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrh r0, [r7, #8]
	adds r0, #1
	movs r4, #0
	strh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _080EC610
	b _080EC95E
_080EC610:
	ldr r1, _080EC62C @ =0x00000236
	adds r0, r7, r1
	strb r4, [r0]
	ldr r1, _080EC630 @ =gBlendRegBuffer
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080EC634 @ =gGameState+16
	bl ClearTextWindow
	cmp r5, #0
	bne _080EC638
	movs r0, #0xb
	b _080EC95C
	.align 2, 0
_080EC62C: .4byte 0x00000236
_080EC630: .4byte gBlendRegBuffer
_080EC634: .4byte gGameState+16
_080EC638:
	ldr r2, _080EC658 @ =0x00000252
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EC65C
	movs r0, #0x73
	bl PrintOptionMessage1
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	ldrb r0, [r7, #6]
	adds r0, #1
	b _080EC95C
	.align 2, 0
_080EC658: .4byte 0x00000252
_080EC65C:
	movs r0, #6
	bl PlaySound
	ldr r1, _080EC6A4 @ =0x08385F8E
	movs r0, #0x93
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PrintNormalMessage
	ldr r2, _080EC6A8 @ =gSystemSavedataManager
	ldr r1, _080EC6AC @ =0x08385F9C
	ldr r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	subs r2, #0xd8
	ldr r1, _080EC6B0 @ =gSineTable
	adds r0, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	bl SaveSystemData
	ldr r2, _080EC6B4 @ =0x00000253
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xd
	b _080EC95C
	.align 2, 0
_080EC6A4: .4byte UnlockMinigameTextIDs
_080EC6A8: .4byte gSystemSavedataManager
_080EC6AC: .4byte u8_ARRAY_08385f9c
_080EC6B0: .4byte gSineTable
_080EC6B4: .4byte 0x00000253
_080EC6B8:
	adds r0, r7, #0
	bl intro_080ecd28
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl UpdateTextWindow
	ldr r0, _080EC6F0 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EC6D4
	cmp r0, #4
	beq _080EC6D4
	b _080EC95E
_080EC6D4:
	ldr r0, _080EC6F4 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080EC6F8
	movs r0, #1
	bl PlaySound
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r7, r3
	b _080EC70C
	.align 2, 0
_080EC6F0: .4byte gTextWindow+8
_080EC6F4: .4byte gJoypad
_080EC6F8:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080EC716
	movs r0, #1
	bl PlaySound
	movs r4, #0x8e
	lsls r4, r4, #2
	adds r0, r7, r4
_080EC70C:
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #1
	ands r1, r2
	strb r1, [r0]
_080EC716:
	ldr r0, _080EC758 @ =StringOfsTable
	ldrh r1, [r0]
	ldr r0, _080EC75C @ =gStringData
	adds r6, r1, r0
	movs r2, #0
	ldr r0, _080EC760 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r3, r0, #0
	cmp r1, #0
	bne _080EC730
	ldrb r0, [r3, #4]
	cmp r0, #1
	bne _080EC732
_080EC730:
	movs r2, #1
_080EC732:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #8
	subs r1, r1, r0
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r4, r7, r0
	ldrb r2, [r4]
	lsls r2, r2, #1
	adds r2, #2
	ldrb r3, [r3, #5]
	adds r2, r2, r3
	adds r0, r6, #0
	bl PrintString
	cmp r5, #0
	bne _080EC764
	movs r0, #0xb
	b _080EC95C
	.align 2, 0
_080EC758: .4byte StringOfsTable
_080EC75C: .4byte gStringData
_080EC760: .4byte gTextWindow+8
_080EC764:
	ldr r0, _080EC784 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r5, #2
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080EC78C
	movs r0, #3
	bl PlaySound
	ldr r1, _080EC788 @ =0x00000253
	adds r0, r7, r1
	strb r5, [r0]
	movs r0, #0xa
	b _080EC95C
	.align 2, 0
_080EC784: .4byte gJoypad
_080EC788: .4byte 0x00000253
_080EC78C:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080EC796
	b _080EC95E
_080EC796:
	movs r0, #2
	bl PlaySound
	ldrb r0, [r4]
	cmp r0, #0
	bne _080EC7B4
	ldr r2, _080EC7B0 @ =0x00000253
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r7, #6]
	adds r0, #1
	b _080EC95C
	.align 2, 0
_080EC7B0: .4byte 0x00000253
_080EC7B4:
	ldr r3, _080EC7C0 @ =0x00000253
	adds r0, r7, r3
	strb r5, [r0]
	movs r0, #0xa
	b _080EC95C
	.align 2, 0
_080EC7C0: .4byte 0x00000253
_080EC7C4:
	adds r0, r7, #0
	bl intro_080ecd28
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl UpdateTextWindow
	ldr r2, _080EC7F4 @ =gTextWindow+8
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq _080EC7DC
	b _080EC906
_080EC7DC:
	cmp r5, #0
	beq _080EC7E2
	b _080EC95E
_080EC7E2:
	movs r4, #0x93
	lsls r4, r4, #2
	adds r0, r7, r4
	ldr r3, [r0]
	cmp r3, #0
	bge _080EC7F8
	movs r0, #0xb
	b _080EC95C
	.align 2, 0
_080EC7F4: .4byte gTextWindow+8
_080EC7F8:
	ldr r1, _080EC83C @ =gSystemSavedataManager
	ldr r0, _080EC840 @ =MaybeCharTable
	adds r0, r3, r0
	ldrb r4, [r0]
	adds r2, r4, #0
	adds r2, #0x3e
	asrs r0, r2, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #7
	ands r2, r1
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080EC854
	ldr r2, _080EC844 @ =gTextPrinter
	ldr r0, _080EC848 @ =0x00000594
	adds r2, r2, r0
	ldr r1, _080EC84C @ =StringOfsTable
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r0, r3, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080EC850 @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x75
	bl PrintNormalMessage
	b _080EC862
	.align 2, 0
_080EC83C: .4byte gSystemSavedataManager
_080EC840: .4byte MaybeCharTable
_080EC844: .4byte gTextPrinter
_080EC848: .4byte 0x00000594
_080EC84C: .4byte StringOfsTable
_080EC850: .4byte gStringData
_080EC854:
	ldr r0, _080EC884 @ =0x08385E24
	subs r1, r4, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PrintNormalMessage
_080EC862:
	ldr r4, _080EC888 @ =gSystemSavedataManager
	adds r4, #0x45
	ldrb r5, [r4]
	ldr r1, _080EC88C @ =MaybeCharTable
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl ToggleMods
	ldrb r4, [r4]
	cmp r5, r4
	beq _080EC890
	movs r0, #0x20
	b _080EC892
	.align 2, 0
_080EC884: .4byte ModCardTextIDs
_080EC888: .4byte gSystemSavedataManager
_080EC88C: .4byte MaybeCharTable
_080EC890:
	movs r0, #0
_080EC892:
	strh r0, [r7, #8]
	movs r0, #6
	bl PlaySound
	ldrb r0, [r7, #6]
	adds r0, #1
	b _080EC95C
_080EC8A0:
	bl UpdateTextWindow
	ldrh r1, [r7, #8]
	movs r3, #8
	ldrsh r0, [r7, r3]
	cmp r0, #0
	beq _080EC94E
	subs r3, r1, #1
	strh r3, [r7, #8]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _080EC8CC
	ldr r2, _080EC8C8 @ =wMOSAIC
	movs r1, #0x20
	subs r1, r1, r3
	movs r0, #0xf
	ands r1, r0
	b _080EC8D6
	.align 2, 0
_080EC8C8: .4byte wMOSAIC
_080EC8CC:
	cmp r0, #0xf
	bgt _080EC8DC
	ldr r2, _080EC8EC @ =wMOSAIC
	movs r1, #0xf
	ands r1, r3
_080EC8D6:
	lsls r0, r1, #4
	orrs r0, r1
	strh r0, [r2]
_080EC8DC:
	movs r4, #8
	ldrsh r0, [r7, r4]
	cmp r0, #0x10
	bne _080EC94E
	adds r0, r7, #0
	bl loadTitleScreen
	b _080EC94E
	.align 2, 0
_080EC8EC: .4byte wMOSAIC
_080EC8F0:
	adds r0, r7, #0
	bl intro_080ecd28
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl UpdateTextWindow
	ldr r2, _080EC910 @ =gTextWindow+8
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq _080EC914
_080EC906:
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	b _080EC95E
	.align 2, 0
_080EC910: .4byte gTextWindow+8
_080EC914:
	cmp r5, #0
	bne _080EC95E
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _080EC956
_080EC924:
	movs r0, #4
	bl PlaySound
	movs r0, #0x74
	bl PrintNormalMessage
	ldrb r0, [r7, #6]
	adds r0, #1
	strb r0, [r7, #6]
_080EC936:
	bl UpdateTextWindow
	ldr r0, _080EC998 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080EC95E
	movs r0, #0x20
	strh r0, [r7, #8]
	movs r0, #3
	strb r0, [r7, #6]
_080EC94A:
	bl UpdateTextWindow
_080EC94E:
	ldr r0, _080EC998 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080EC95E
_080EC956:
	movs r0, #0x20
_080EC958:
	strh r0, [r7, #8]
_080EC95A:
	movs r0, #3
_080EC95C:
	strb r0, [r7, #6]
_080EC95E:
	movs r0, #0xf0
	bl UpdateBlinkMotionState
	ldr r2, _080EC99C @ =0x00000235
	adds r0, r7, r2
	ldrb r1, [r0]
	cmp r1, #0
	beq _080EC9AC
	subs r1, #1
	strb r1, [r0]
	ldr r2, _080EC9A0 @ =gPaletteManager
	ldr r3, _080EC9A4 @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	ldr r4, _080EC9A8 @ =0x00000401
	adds r1, r2, r4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x20
	strb r0, [r1]
	b _080EC9D8
	.align 2, 0
_080EC998: .4byte gTextWindow+8
_080EC99C: .4byte 0x00000235
_080EC9A0: .4byte gPaletteManager
_080EC9A4: .4byte 0x00000402
_080EC9A8: .4byte 0x00000401
_080EC9AC:
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r1, [r0]
	cmp r1, #0x1f
	bhi _080EC9D8
	adds r1, #1
	strb r1, [r0]
	ldr r2, _080ECA00 @ =gPaletteManager
	movs r0, #0x40
	subs r0, r0, r1
	ldr r4, _080ECA04 @ =0x00000402
	adds r1, r2, r4
	strb r0, [r1]
	movs r1, #0xff
	ands r0, r1
	ldr r3, _080ECA08 @ =0x00000401
	adds r1, r2, r3
	strb r0, [r1]
	subs r4, #2
	adds r2, r2, r4
	strb r0, [r2]
_080EC9D8:
	ldrb r1, [r7, #6]
	cmp r1, #6
	bls _080EC9E0
	b _080ECC2A
_080EC9E0:
	ldrh r2, [r7, #8]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080ECA14
	movs r0, #0
	str r0, [sp, #0xc]
	cmp r1, #3
	bhi _080EC9F6
	movs r1, #2
	str r1, [sp, #0xc]
_080EC9F6:
	ldr r1, _080ECA0C @ =gBlendRegBuffer
	ldr r0, _080ECA10 @ =0x00000808
	strh r0, [r1, #2]
	b _080ECA62
	.align 2, 0
_080ECA00: .4byte gPaletteManager
_080ECA04: .4byte 0x00000402
_080ECA08: .4byte 0x00000401
_080ECA0C: .4byte gBlendRegBuffer
_080ECA10: .4byte 0x00000808
_080ECA14:
	ldr r1, _080ECA44 @ =gSineTable
	movs r0, #0x3f
	ands r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080ECA48
	movs r1, #0x1f
	ands r1, r2
	lsrs r1, r1, #2
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _080ECA4E
	.align 2, 0
_080ECA44: .4byte gSineTable
_080ECA48:
	movs r0, #0x1f
	ands r0, r2
	lsrs r0, r0, #2
_080ECA4E:
	ldr r3, _080ECB48 @ =gBlendRegBuffer
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x1f
	ands r2, r1
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r2, r0
	strh r2, [r3, #2]
_080ECA62:
	ldr r2, [sp, #0xc]
	cmp r2, #0
	beq _080ECB1A
	movs r0, #0xa0
	lsls r0, r0, #3
	bl Malloc
	mov r8, r0
	cmp r0, #0
	beq _080ECB1A
	ldr r2, _080ECB4C @ =gIntrManager
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r2, r3
	mov r4, r8
	str r4, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080ECB50 @ =0x04000010
	str r0, [r1]
	adds r3, #8
	adds r1, r2, r3
	ldr r0, _080ECB54 @ =0xA6600002
	str r0, [r1]
	movs r1, #0
	movs r0, #0xbf
	lsls r0, r0, #2
	add r0, r8
_080ECA9C:
	str r1, [r0]
	subs r0, #4
	cmp r0, r8
	bge _080ECA9C
	ldr r4, _080ECB58 @ =gIntro
	mov sl, r4
	movs r6, #0xc0
	movs r0, #0xc0
	lsls r0, r0, #2
	add r0, r8
	str r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	lsrs r1, r1, #1
	mov sb, r1
_080ECAB8:
	mov r2, sl
	ldr r0, [r2, #0xc]
	ldr r3, _080ECB5C @ =0x41C64E6D
	adds r5, r0, #0
	muls r5, r3, r5
	ldr r4, _080ECB60 @ =0x00003039
	adds r5, r5, r4
	str r5, [r2, #0xc]
	lsrs r0, r5, #0x10
	ldr r1, [sp, #0xc]
	bl __umodsi3
	adds r4, r0, #0
	mov r0, sb
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r1, _080ECB5C @ =0x41C64E6D
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, _080ECB60 @ =0x00003039
	adds r0, r0, r2
	mov r3, sl
	str r0, [r3, #0xc]
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	bl __umodsi3
	mov r1, sb
	subs r0, r0, r1
	ldr r1, _080ECB64 @ =0x0000FFFF
	ands r0, r1
	orrs r4, r0
	ldr r2, [sp, #0x10]
	stm r2!, {r4}
	str r2, [sp, #0x10]
	adds r6, #1
	ldr r0, _080ECB68 @ =0x0000011F
	cmp r6, r0
	ble _080ECAB8
	ldr r1, _080ECB6C @ =0x0000013F
	cmp r6, r1
	bgt _080ECB1A
	movs r2, #0
	lsls r0, r6, #2
	add r0, r8
_080ECB12:
	stm r0!, {r2}
	adds r6, #1
	cmp r6, r1
	ble _080ECB12
_080ECB1A:
	ldrb r0, [r7, #6]
	cmp r0, #3
	bhi _080ECB7C
	ldrh r0, [r7, #8]
	adds r0, #1
	movs r1, #0
	strh r0, [r7, #8]
	ldr r4, _080ECB70 @ =gGameState+16
	str r1, [sp, #4]
	ldr r2, _080ECB74 @ =0x01000200
	add r0, sp, #4
	adds r1, r4, #0
	bl CpuFastSet
	ldr r1, _080ECB78 @ =gBgMapOffsets
	movs r0, #0xe
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #5
	movs r3, #0
	bl loadBgMap_08004248
	b _080ECC2A
	.align 2, 0
_080ECB48: .4byte gBlendRegBuffer
_080ECB4C: .4byte gIntrManager
_080ECB50: .4byte 0x04000010
_080ECB54: .4byte 0xA6600002
_080ECB58: .4byte gIntro
_080ECB5C: .4byte 0x41C64E6D
_080ECB60: .4byte 0x00003039
_080ECB64: .4byte 0x0000FFFF
_080ECB68: .4byte 0x0000011F
_080ECB6C: .4byte 0x0000013F
_080ECB70: .4byte gGameState+16
_080ECB74: .4byte 0x01000200
_080ECB78: .4byte gBgMapOffsets
_080ECB7C:
	bl IsAnyMinigameUnlocked
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080ECBEC
	ldr r6, _080ECBE0 @ =StringOfsTable
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r4, r7, r3
	ldrb r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #2
	cmp r0, #0
	beq _080ECB9A
	adds r1, #2
_080ECB9A:
	adds r0, r1, r6
	ldrh r0, [r0]
	ldr r5, _080ECBE4 @ =gStringData
	adds r0, r0, r5
	movs r1, #0xa
	movs r2, #0xc
	bl PrintString
	ldrb r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, #1
	beq _080ECBB6
	adds r1, #2
_080ECBB6:
	adds r0, r1, r6
	ldrh r0, [r0]
	adds r0, r0, r5
	movs r1, #0xa
	movs r2, #0xe
	bl PrintString
	ldrb r0, [r4]
	ldr r1, _080ECBE8 @ =0x00000404
	cmp r0, #2
	beq _080ECBCE
	adds r1, #2
_080ECBCE:
	adds r0, r1, r6
	ldrh r0, [r0]
	adds r0, r0, r5
	movs r1, #0xa
	movs r2, #0x10
	bl PrintString
	b _080ECC2A
	.align 2, 0
_080ECBE0: .4byte StringOfsTable
_080ECBE4: .4byte gStringData
_080ECBE8: .4byte 0x00000404
_080ECBEC:
	ldr r6, _080ECC3C @ =StringOfsTable
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r4, r7, r0
	ldrb r0, [r4]
	movs r1, #0xff
	lsls r1, r1, #2
	cmp r0, #0
	beq _080ECC00
	adds r1, #2
_080ECC00:
	adds r0, r1, r6
	ldrh r0, [r0]
	ldr r5, _080ECC40 @ =gStringData
	adds r0, r0, r5
	movs r1, #0xa
	movs r2, #0xd
	bl PrintString
	ldrb r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, #1
	beq _080ECC1C
	adds r1, #2
_080ECC1C:
	adds r0, r1, r6
	ldrh r0, [r0]
	adds r0, r0, r5
	movs r1, #0xa
	movs r2, #0xf
	bl PrintString
_080ECC2A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ECC3C: .4byte StringOfsTable
_080ECC40: .4byte gStringData
