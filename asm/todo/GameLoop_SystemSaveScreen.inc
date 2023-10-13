	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #2]
	cmp r0, #9
	bls _080EFD1E
	b _080F02C6
_080EFD1E:
	lsls r0, r0, #2
	ldr r1, _080EFD28 @ =_080EFD2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080EFD28: .4byte _080EFD2C
_080EFD2C: @ jump table
	.4byte _080EFD54 @ case 0
	.4byte _080EFD80 @ case 1
	.4byte _080EFDE8 @ case 2
	.4byte _080EFE64 @ case 3
	.4byte _080EFEF2 @ case 4
	.4byte _080EFEFC @ case 5
	.4byte _080F00B8 @ case 6
	.4byte _080F01BC @ case 7
	.4byte _080F01D4 @ case 8
	.4byte _080F0220 @ case 9
_080EFD54:
	ldr r1, _080EFDC4 @ =gPaletteManager
	movs r0, #0
	strh r0, [r1]
	ldr r2, _080EFDC8 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EFDCC @ =0x0000FFF8
	ands r0, r1
	movs r4, #0
	ldr r1, _080EFDD0 @ =0x0000F0FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	str r4, [r2, #0xc]
	bl text_080e9730
	strh r4, [r6, #6]
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFD80:
	ldrh r0, [r6, #6]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r6, #6]
	ldr r2, _080EFDC4 @ =gPaletteManager
	ldr r4, _080EFDD4 @ =0x00000402
	adds r0, r2, r4
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	ldr r3, _080EFDD8 @ =0x00000401
	adds r1, r2, r3
	strb r0, [r1]
	subs r4, #2
	adds r2, r2, r4
	strb r0, [r2]
	ldr r0, _080EFDDC @ =StringOfsTable
	ldr r1, _080EFDE0 @ =0x00000316
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080EFDE4 @ =gStringData
	adds r0, r0, r1
	movs r1, #9
	movs r2, #7
	bl PrintString
	movs r2, #6
	ldrsh r0, [r6, r2]
	cmp r0, #0x1f
	bgt _080EFDBE
	b _080F02C6
_080EFDBE:
	movs r0, #0
	b _080F01FC
	.align 2, 0
_080EFDC4: .4byte gPaletteManager
_080EFDC8: .4byte gVideoRegBuffer
_080EFDCC: .4byte 0x0000FFF8
_080EFDD0: .4byte 0x0000F0FF
_080EFDD4: .4byte 0x00000402
_080EFDD8: .4byte 0x00000401
_080EFDDC: .4byte StringOfsTable
_080EFDE0: .4byte 0x00000316
_080EFDE4: .4byte gStringData
_080EFDE8:
	ldr r7, _080EFE50 @ =gJoypad
	ldrh r1, [r7, #6]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _080EFE02
	movs r0, #1
	bl PlaySound
	ldrh r0, [r6, #4]
	movs r1, #1
	eors r0, r1
	strh r0, [r6, #4]
_080EFE02:
	ldr r5, _080EFE54 @ =StringOfsTable
	ldr r3, _080EFE58 @ =0x00000316
	adds r0, r5, r3
	ldrh r0, [r0]
	ldr r4, _080EFE5C @ =gStringData
	adds r0, r0, r4
	movs r1, #9
	movs r2, #7
	bl PrintString
	ldrh r0, [r5]
	adds r0, r0, r4
	movs r4, #4
	ldrsh r2, [r6, r4]
	lsls r2, r2, #1
	adds r2, #9
	movs r1, #9
	bl PrintString
	ldrh r1, [r7, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080EFE34
	b _080F02C6
_080EFE34:
	movs r0, #2
	bl PlaySound
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _080EFE44
	b _080F01FE
_080EFE44:
	ldr r0, _080EFE60 @ =0x0000018B
	strh r0, [r6, #4]
	movs r0, #9
	strb r0, [r6, #2]
	b _080F02C6
	.align 2, 0
_080EFE50: .4byte gJoypad
_080EFE54: .4byte StringOfsTable
_080EFE58: .4byte 0x00000316
_080EFE5C: .4byte gStringData
_080EFE60: .4byte 0x0000018B
_080EFE64:
	movs r5, #0
	ldr r2, _080EFE8C @ =0x020002C4
	mov r8, r2
	ldr r3, _080EFE90 @ =0xFFFFFE4C
	add r3, r8
	mov sb, r3
_080EFE70:
	lsls r0, r5, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #0x94
	lsls r1, r1, #2
	bl CheckSavedataCorrect
	adds r1, r0, #0
	cmp r1, #0
	bne _080EFE98
	ldr r0, _080EFE94 @ =0x02000360
	adds r0, r5, r0
	b _080EFEE4
	.align 2, 0
_080EFE8C: .4byte 0x020002C4
_080EFE90: .4byte 0xFFFFFE4C
_080EFE94: .4byte 0x02000360
_080EFE98:
	ldr r0, _080EFF8C @ =0x02000360
	adds r0, r5, r0
	movs r1, #1
	strb r1, [r0]
	adds r0, r4, #0
	ldr r1, _080EFF90 @ =0x02000110
	movs r2, #0x94
	lsls r2, r2, #2
	bl sram_08003378
	lsls r7, r5, #2
	ldr r4, _080EFF94 @ =gSramState
_080EFEB0:
	bl UpdateSram
	ldrb r0, [r4]
	cmp r0, #1
	beq _080EFEB0
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _080EFEB0
	ldr r0, _080EFF98 @ =0x02000368
	adds r0, r7, r0
	mov r2, r8
	ldr r1, [r2, #0xc]
	str r1, [r0]
	ldr r0, _080EFF9C @ =0x02000380
	adds r0, r7, r0
	ldrb r1, [r2, #1]
	str r1, [r0]
	ldr r0, _080EFFA0 @ =0x02000394
	adds r0, r5, r0
	mov r3, sb
	ldrh r1, [r3]
	strb r1, [r0]
	ldr r0, _080EFFA4 @ =0x0200039C
	adds r0, r5, r0
	ldrh r1, [r3, #2]
_080EFEE4:
	strb r1, [r0]
	adds r5, #1
	cmp r5, #4
	ble _080EFE70
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFEF2:
	movs r0, #0
	strh r0, [r6, #4]
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080EFEFC:
	ldr r4, _080EFFA8 @ =StringOfsTable
	mov r8, r4
	movs r0, #0xc6
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	ldr r7, _080EFFAC @ =gStringData
	adds r0, r0, r7
	movs r1, #9
	movs r2, #3
	bl PrintString
	ldr r4, _080EFFB0 @ =gJoypad
	ldrh r1, [r4, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080EFF34
	movs r0, #1
	bl PlaySound
	movs r1, #4
	ldrsh r0, [r6, r1]
	adds r0, #1
	movs r1, #5
	bl __modsi3
	strh r0, [r6, #4]
_080EFF34:
	ldrh r1, [r4, #6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080EFF52
	movs r0, #1
	bl PlaySound
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r0, #4
	movs r1, #5
	bl __modsi3
	strh r0, [r6, #4]
_080EFF52:
	movs r5, #0
	mov sl, r7
	movs r3, #0xe0
	lsls r3, r3, #0x13
	mov sb, r3
	movs r7, #7
	ldr r4, _080EFFA8 @ =StringOfsTable
	adds r4, #0x3e
	mov r8, r4
_080EFF64:
	ldr r0, _080EFF8C @ =0x02000360
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EFFB4
	mov r1, r8
	ldrh r0, [r1]
	add r0, sl
	movs r1, #7
	adds r2, r7, #0
	bl PrintString
	ldr r2, _080EFFA8 @ =StringOfsTable
	ldrh r0, [r2, #2]
	add r0, sl
	movs r1, #9
	adds r2, r7, #0
	bl PrintString
	b _080EFFDE
	.align 2, 0
_080EFF8C: .4byte 0x02000360
_080EFF90: .4byte 0x02000110
_080EFF94: .4byte gSramState
_080EFF98: .4byte 0x02000368
_080EFF9C: .4byte 0x02000380
_080EFFA0: .4byte 0x02000394
_080EFFA4: .4byte 0x0200039C
_080EFFA8: .4byte StringOfsTable
_080EFFAC: .4byte gStringData
_080EFFB0: .4byte gJoypad
_080EFFB4:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080F0024 @ =0x02000380
	lsls r3, r5, #2
	adds r1, r3, r1
	ldrb r1, [r1]
	ldr r2, _080F0028 @ =0x02000368
	adds r3, r3, r2
	ldr r2, [r3]
	ldr r3, _080F002C @ =0x02000394
	adds r3, r5, r3
	ldrb r3, [r3]
	ldr r4, _080F0030 @ =0x0200039C
	adds r4, r5, r4
	ldrb r4, [r4]
	str r4, [sp]
	mov r4, sb
	lsrs r4, r4, #0x18
	str r4, [sp, #4]
	bl printSaveDataRowText
_080EFFDE:
	movs r0, #0x80
	lsls r0, r0, #0x12
	add sb, r0
	adds r7, #2
	movs r1, #2
	add r8, r1
	adds r5, #1
	cmp r5, #4
	ble _080EFF64
	ldr r0, _080F0034 @ =StringOfsTable
	ldrh r0, [r0]
	ldr r1, _080F0038 @ =gStringData
	adds r0, r0, r1
	movs r3, #4
	ldrsh r2, [r6, r3]
	lsls r2, r2, #1
	adds r2, #7
	movs r1, #5
	bl PrintString
	ldr r0, _080F003C @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080F0040
	movs r0, #3
	bl PlaySound
	movs r0, #0
	strh r0, [r6, #4]
	movs r0, #2
	strb r0, [r6, #2]
	b _080F02C6
	.align 2, 0
_080F0024: .4byte 0x02000380
_080F0028: .4byte 0x02000368
_080F002C: .4byte 0x02000394
_080F0030: .4byte 0x0200039C
_080F0034: .4byte StringOfsTable
_080F0038: .4byte gStringData
_080F003C: .4byte gJoypad
_080F0040:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080F004C
	b _080F02C6
_080F004C:
	movs r0, #2
	bl PlaySound
	ldr r0, _080F009C @ =0x02000360
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080F00B4
	ldr r3, _080F00A0 @ =0x00006270
	adds r4, r6, r3
	adds r0, r4, #0
	bl saveCurStory
	ldr r1, _080F00A4 @ =0x000064AC
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _080F00A8 @ =0x00006460
	adds r1, r6, r2
	bl CopyZeroStatus
	ldr r2, _080F00AC @ =gCurStory
	ldrb r1, [r2, #4]
	movs r0, #8
	orrs r1, r0
	strb r1, [r2, #4]
	ldrb r1, [r4]
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r6, #4]
	ldr r3, _080F00B0 @ =0x0000625C
	adds r1, r6, r3
	movs r2, #0x94
	lsls r2, r2, #2
	bl sram_08003330
	movs r0, #7
	strb r0, [r6, #2]
	b _080F02C6
	.align 2, 0
_080F009C: .4byte 0x02000360
_080F00A0: .4byte 0x00006270
_080F00A4: .4byte 0x000064AC
_080F00A8: .4byte 0x00006460
_080F00AC: .4byte gCurStory
_080F00B0: .4byte 0x0000625C
_080F00B4:
	strh r4, [r6, #0xa]
	b _080F01FE
_080F00B8:
	ldrb r0, [r6, #4]
	ldr r1, _080F0180 @ =0x02000380
	movs r4, #4
	ldrsh r5, [r6, r4]
	lsls r2, r5, #2
	adds r1, r2, r1
	ldrb r1, [r1]
	ldr r3, _080F0184 @ =0x02000368
	adds r2, r2, r3
	ldr r2, [r2]
	ldr r3, _080F0188 @ =0x02000394
	adds r3, r5, r3
	ldrb r3, [r3]
	ldr r4, _080F018C @ =0x0200039C
	adds r5, r5, r4
	ldrb r4, [r5]
	str r4, [sp]
	movs r4, #6
	str r4, [sp, #4]
	bl printSaveDataRowText
	ldr r7, _080F0190 @ =gJoypad
	ldrh r1, [r7, #6]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _080F00FC
	movs r0, #1
	bl PlaySound
	ldrh r0, [r6, #0xa]
	movs r1, #1
	eors r0, r1
	strh r0, [r6, #0xa]
_080F00FC:
	ldr r5, _080F0194 @ =StringOfsTable
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldr r4, _080F0198 @ =gStringData
	adds r0, r0, r4
	movs r1, #9
	movs r2, #9
	bl PrintString
	ldrh r0, [r5]
	adds r0, r0, r4
	movs r3, #0xa
	ldrsh r2, [r6, r3]
	lsls r2, r2, #1
	adds r2, #0xb
	movs r1, #9
	bl PrintString
	ldrh r1, [r7, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080F01B0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080F0138
	b _080F02C6
_080F0138:
	movs r0, #2
	bl PlaySound
	movs r4, #0xa
	ldrsh r0, [r6, r4]
	cmp r0, #0
	bne _080F01B6
	ldr r0, _080F019C @ =0x00006270
	adds r4, r6, r0
	adds r0, r4, #0
	bl saveCurStory
	ldr r1, _080F01A0 @ =0x000064AC
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _080F01A4 @ =0x00006460
	adds r1, r6, r2
	bl CopyZeroStatus
	ldr r2, _080F01A8 @ =gCurStory
	ldrb r1, [r2, #4]
	movs r0, #8
	orrs r1, r0
	strb r1, [r2, #4]
	ldrb r1, [r4]
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r6, #4]
	ldr r3, _080F01AC @ =0x0000625C
	adds r1, r6, r3
	movs r2, #0x94
	lsls r2, r2, #2
	bl sram_08003330
	b _080F01FE
	.align 2, 0
_080F0180: .4byte 0x02000380
_080F0184: .4byte 0x02000368
_080F0188: .4byte 0x02000394
_080F018C: .4byte 0x0200039C
_080F0190: .4byte gJoypad
_080F0194: .4byte StringOfsTable
_080F0198: .4byte gStringData
_080F019C: .4byte 0x00006270
_080F01A0: .4byte 0x000064AC
_080F01A4: .4byte 0x00006460
_080F01A8: .4byte gCurStory
_080F01AC: .4byte 0x0000625C
_080F01B0:
	movs r0, #3
	bl PlaySound
_080F01B6:
	movs r0, #5
	strb r0, [r6, #2]
	b _080F02C6
_080F01BC:
	ldr r1, _080F0208 @ =gSramState
	ldrb r0, [r1]
	cmp r0, #2
	bne _080F01C6
	b _080F02C6
_080F01C6:
	movs r4, #0x1c
	ldrsh r0, [r1, r4]
	cmp r0, #0
	beq _080F02C6
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080F01D4:
	ldr r0, _080F020C @ =StringOfsTable
	ldr r1, _080F0210 @ =0x0000031A
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080F0214 @ =gStringData
	adds r0, r0, r1
	movs r1, #0xa
	movs r2, #9
	bl PrintString
	ldr r0, _080F0218 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080F02C6
	movs r0, #2
	bl PlaySound
	ldr r0, _080F021C @ =0x0000018D
_080F01FC:
	strh r0, [r6, #4]
_080F01FE:
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
	b _080F02C6
	.align 2, 0
_080F0208: .4byte gSramState
_080F020C: .4byte StringOfsTable
_080F0210: .4byte 0x0000031A
_080F0214: .4byte gStringData
_080F0218: .4byte gJoypad
_080F021C: .4byte 0x0000018D
_080F0220:
	ldrh r0, [r6, #6]
	subs r0, #1
	adds r1, r0, #0
	strh r0, [r6, #6]
	ldr r2, _080F0264 @ =gPaletteManager
	ldr r3, _080F0268 @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	ldr r4, _080F026C @ =0x00000401
	adds r1, r2, r4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
	movs r2, #4
	ldrsh r1, [r6, r2]
	ldr r0, _080F0270 @ =0x0000018D
	cmp r1, r0
	bne _080F027C
	ldr r0, _080F0274 @ =StringOfsTable
	subs r3, #0xe8
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, _080F0278 @ =gStringData
	adds r0, r0, r1
	movs r1, #0xa
	movs r2, #9
	bl PrintString
	b _080F0290
	.align 2, 0
_080F0264: .4byte gPaletteManager
_080F0268: .4byte 0x00000402
_080F026C: .4byte 0x00000401
_080F0270: .4byte 0x0000018D
_080F0274: .4byte StringOfsTable
_080F0278: .4byte gStringData
_080F027C:
	ldr r0, _080F02D8 @ =StringOfsTable
	ldr r4, _080F02DC @ =0x00000316
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, _080F02E0 @ =gStringData
	adds r0, r0, r1
	movs r1, #9
	movs r2, #7
	bl PrintString
_080F0290:
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _080F02C6
	ldr r3, _080F02E4 @ =gCurStory
	ldrb r2, [r3, #4]
	movs r1, #0xf7
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #4]
	ldr r3, _080F02E8 @ =0x00006270
	adds r2, r6, r3
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	ldr r4, _080F02EC @ =0x00006260
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _080F02BC
	bl ExitProcess
_080F02BC:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, #0
	bl SetGameMode
_080F02C6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F02D8: .4byte StringOfsTable
_080F02DC: .4byte 0x00000316
_080F02E0: .4byte gStringData
_080F02E4: .4byte gCurStory
_080F02E8: .4byte 0x00006270
_080F02EC: .4byte 0x00006260
