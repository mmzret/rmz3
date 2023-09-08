	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #2]
	cmp r0, #9
	bls _080EF930
	b _080EFCE6
_080EF930:
	lsls r0, r0, #2
	ldr r1, _080EF93C @ =_080EF940
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080EF93C: .4byte _080EF940
_080EF940: @ jump table
	.4byte _080EF968 @ case 0
	.4byte _080EF9EA @ case 1
	.4byte _080EFA24 @ case 2
	.4byte _080EFA54 @ case 3
	.4byte _080EFA8E @ case 4
	.4byte _080EFAC8 @ case 5
	.4byte _080EFB0A @ case 6
	.4byte _080EFB4C @ case 7
	.4byte _080EFB92 @ case 8
	.4byte _080EFBDE @ case 9
_080EF968:
	ldr r5, _080EFC0C @ =gPaletteManager
	ldr r1, _080EFC10 @ =0x00000402
	adds r0, r5, r1
	movs r4, #0
	movs r1, #0x20
	strb r1, [r0]
	ldr r2, _080EFC14 @ =0x00000401
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	bl ClearBlinkings
	ldr r0, _080EFC18 @ =gBlendRegBuffer
	strh r4, [r0]
	ldr r1, _080EFC1C @ =gWindowRegBuffer
	strh r4, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xe]
	ldr r0, _080EFC20 @ =wMOSAIC
	strh r4, [r0]
	strh r4, [r5]
	ldr r2, _080EFC24 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EFC28 @ =0x0000FFF8
	ands r0, r1
	ldr r1, _080EFC2C @ =0x0000F0FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	bl text_080e9730
	bl FUN_080e981c
	ldr r0, _080EFC30 @ =gGameState+16
	bl ClearTextWindow
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x18]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x10]
	ldrb r0, [r0, #0x10]
	cmp r1, r0
	beq _080EF9E4
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x18]
	bl SaveSystemData
	movs r0, #0xd9
	bl PrintNormalMessage
_080EF9E4:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EF9EA:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EF9F4
	b _080EFCE6
_080EF9F4:
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x19]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x12]
	ldrb r0, [r0, #0x12]
	cmp r1, r0
	beq _080EFA1E
	bl allSecretDiskFound
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080EFA1E
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x19]
	bl SaveSystemData
	movs r0, #0xda
	bl PrintNormalMessage
_080EFA1E:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFA24:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFA2E
	b _080EFCE6
_080EFA2E:
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x1a]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x14]
	ldrb r0, [r0, #0x14]
	cmp r1, r0
	beq _080EFA4E
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x1a]
	bl SaveSystemData
	movs r0, #0xd2
	bl PrintNormalMessage
_080EFA4E:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFA54:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFA5E
	b _080EFCE6
_080EFA5E:
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x1b]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x16]
	ldrb r0, [r0, #0x16]
	cmp r1, r0
	beq _080EFA88
	ldr r0, _080EFC40 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #6
	bne _080EFA88
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x1b]
	bl SaveSystemData
	movs r0, #0xd3
	bl PrintNormalMessage
_080EFA88:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFA8E:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFA98
	b _080EFCE6
_080EFA98:
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x1c]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x18]
	ldrb r0, [r0, #0x18]
	cmp r1, r0
	beq _080EFAC2
	ldr r1, _080EFC44 @ =0x0000625C
	adds r0, r6, r1
	ldrh r0, [r0, #2]
	cmp r0, #1
	bne _080EFAC2
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x1c]
	bl SaveSystemData
	movs r0, #0xd4
	bl PrintNormalMessage
_080EFAC2:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFAC8:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFAD2
	b _080EFCE6
_080EFAD2:
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x1e]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x1c]
	ldrb r0, [r0, #0x1c]
	cmp r1, r0
	beq _080EFB04
	ldr r0, _080EFC40 @ =gMission
	ldr r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	ldrb r1, [r1, #0x10]
	bl __divsi3
	cmp r0, #0x64
	bne _080EFB04
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x1e]
	bl SaveSystemData
	movs r0, #0xd6
	bl PrintNormalMessage
_080EFB04:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFB0A:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFB14
	b _080EFCE6
_080EFB14:
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x1f]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x1e]
	ldrb r0, [r0, #0x1e]
	cmp r1, r0
	beq _080EFB46
	ldr r0, _080EFC40 @ =gMission
	ldr r1, [r0]
	movs r3, #0xa
	ldrsh r0, [r1, r3]
	ldrb r1, [r1, #0x10]
	bl __divsi3
	cmp r0, #0x64
	bne _080EFB46
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x1f]
	bl SaveSystemData
	movs r0, #0xd7
	bl PrintNormalMessage
_080EFB46:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFB4C:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFB56
	b _080EFCE6
_080EFB56:
	ldr r5, _080EFC34 @ =gSystemSavedataManager
	ldrb r1, [r5, #0x1d]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x1a]
	ldrb r0, [r0, #0x1a]
	cmp r1, r0
	beq _080EFB8C
	ldr r0, _080EFC40 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #6
	bne _080EFB8C
	ldr r0, _080EFC48 @ =gCurStory
	ldrb r1, [r0, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080EFB8C
	movs r0, #6
	bl PlaySound
	strb r4, [r5, #0x1d]
	bl SaveSystemData
	movs r0, #0xd5
	bl PrintNormalMessage
_080EFB8C:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFB92:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFB9C
	b _080EFCE6
_080EFB9C:
	ldr r0, _080EFC34 @ =gSystemSavedataManager
	adds r5, r0, #0
	adds r5, #0x20
	ldrb r1, [r5]
	ldr r0, _080EFC38 @ =gSineTable
	ldrh r4, [r0, #0x20]
	movs r0, #0xff
	ands r0, r4
	cmp r1, r0
	beq _080EFBD8
	ldr r0, _080EFC40 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #6
	bne _080EFBD8
	ldr r0, _080EFC48 @ =gCurStory
	ldrb r1, [r0, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080EFBD8
	movs r0, #6
	bl PlaySound
	strb r4, [r5]
	bl SaveSystemData
	movs r0, #0xd8
	bl PrintNormalMessage
_080EFBD8:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFBDE:
	ldr r0, _080EFC3C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080EFBE8
	b _080EFCE6
_080EFBE8:
	ldr r0, _080EFC44 @ =0x0000625C
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x62
	bhi _080EFBF6
	adds r0, #1
	strh r0, [r4]
_080EFBF6:
	ldr r1, _080EFC4C @ =0x00006270
	adds r5, r6, r1
	adds r0, r5, #0
	bl FUN_08019678
	ldrh r0, [r4, #2]
	cmp r0, #1
	bne _080EFC50
	ldrb r1, [r5]
	movs r0, #1
	b _080EFC58
	.align 2, 0
_080EFC0C: .4byte gPaletteManager
_080EFC10: .4byte 0x00000402
_080EFC14: .4byte 0x00000401
_080EFC18: .4byte gBlendRegBuffer
_080EFC1C: .4byte gWindowRegBuffer
_080EFC20: .4byte wMOSAIC
_080EFC24: .4byte gVideoRegBuffer
_080EFC28: .4byte 0x0000FFF8
_080EFC2C: .4byte 0x0000F0FF
_080EFC30: .4byte gGameState+16
_080EFC34: .4byte gSystemSavedataManager
_080EFC38: .4byte gSineTable
_080EFC3C: .4byte gTextWindow+8
_080EFC40: .4byte gMission
_080EFC44: .4byte 0x0000625C
_080EFC48: .4byte gCurStory
_080EFC4C: .4byte 0x00006270
_080EFC50:
	cmp r0, #2
	bne _080EFC5C
	ldrb r1, [r5]
	movs r0, #2
_080EFC58:
	orrs r0, r1
	strb r0, [r5]
_080EFC5C:
	ldr r3, _080EFCF0 @ =gCurStory
	ldrb r1, [r3, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080EFC74
	ldr r0, _080EFCF4 @ =0x00006270
	adds r2, r6, r0
	ldrb r1, [r2, #4]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2, #4]
_080EFC74:
	ldrb r3, [r3, #8]
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _080EFC8A
	ldr r1, _080EFCF4 @ =0x00006270
	adds r2, r6, r1
	ldrb r1, [r2, #4]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r2, #4]
_080EFC8A:
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _080EFC9E
	ldr r3, _080EFCF4 @ =0x00006270
	adds r2, r6, r3
	ldrb r1, [r2, #4]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r2, #4]
_080EFC9E:
	ldr r0, _080EFCF4 @ =0x00006270
	adds r1, r6, r0
	movs r0, #1
	bl resetCurStory
	ldr r1, _080EFCF8 @ =0x00006410
	adds r4, r6, r1
	ldr r5, [r4, #0xc]
	adds r0, r4, #0
	bl ClearPlayInfo
	str r5, [r4, #0xc]
	ldr r0, _080EFCFC @ =gMission
	ldr r1, [r0]
	movs r0, #2
	strb r0, [r1]
	ldr r2, _080EFD00 @ =0x000064AC
	adds r5, r6, r2
	ldr r0, [r5]
	ldr r3, _080EFD04 @ =0x00006460
	adds r4, r6, r3
	adds r1, r4, #0
	bl CopyZeroStatus
	adds r0, r4, #0
	bl FUN_080321d4
	ldr r0, [r5]
	adds r1, r4, #0
	bl SaveZeroStatus
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, #0
	bl SetGameMode
_080EFCE6:
	bl UpdateTextWindow
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EFCF0: .4byte gCurStory
_080EFCF4: .4byte 0x00006270
_080EFCF8: .4byte 0x00006410
_080EFCFC: .4byte gMission
_080EFD00: .4byte 0x000064AC
_080EFD04: .4byte 0x00006460
