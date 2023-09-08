	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start minigameSelectScript
minigameSelectScript: @ 0x080EDA5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0
	mov sb, r0
	mov r8, r0
	ldrb r0, [r5, #6]
	cmp r0, #1
	beq _080EDB72
	cmp r0, #1
	bgt _080EDA80
	cmp r0, #0
	beq _080EDA8E
	b _080EDCC4
_080EDA80:
	cmp r0, #2
	bne _080EDA86
	b _080EDC54
_080EDA86:
	cmp r0, #3
	bne _080EDA8C
	b _080EDC98
_080EDA8C:
	b _080EDCC4
_080EDA8E:
	ldr r2, _080EDBEC @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EDBF0 @ =0x0000FFF8
	ands r0, r1
	ldr r1, _080EDBF4 @ =0x0000F0FF
	ands r0, r1
	movs r3, #0xe4
	lsls r3, r3, #6
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080EDBF8 @ =0x00000606
	adds r0, r1, #0
	strh r0, [r2, #0xa]
	mov r3, r8
	str r3, [r2, #0x18]
	ldr r0, _080EDBFC @ =gGraphic_MenuMisc
	ldrh r2, [r2, #8]
	movs r1, #0xc
	ands r1, r2
	lsls r1, r1, #0xc
	bl LoadGraphic
	ldr r0, _080EDC00 @ =gGraphic_MenuMisc+12
	movs r1, #0
	bl LoadPalette
	ldr r1, _080EDC04 @ =gBgMapOffsets
	mov r0, r8
	str r0, [sp]
	movs r0, #0x38
	movs r2, #6
	movs r3, #0
	bl LoadBgMap
	movs r0, #0x40
	movs r1, #0
	bl LoadBlink
	ldr r1, _080EDC08 @ =gBlendRegBuffer
	ldr r0, _080EDC0C @ =0x00003E41
	strh r0, [r1]
	movs r2, #0x10
	mov sl, r2
	mov r3, sl
	strh r3, [r1, #2]
	bl text_080e9730
	bl FUN_080e9840
	movs r1, #0
	ldr r6, _080EDC10 @ =gSystemSavedataManager
	ldrb r0, [r6, #0x1a]
	ldr r7, _080EDC14 @ =gSineTable
	movs r4, #0xff
	ldrb r2, [r7, #0x14]
	cmp r0, r2
	bne _080EDB04
	movs r1, #1
_080EDB04:
	adds r3, r1, #0
	ldrb r2, [r6, #0x1b]
	ldrh r1, [r7, #0x16]
	adds r0, r4, #0
	ands r0, r1
	cmp r2, r0
	bne _080EDB14
	adds r3, #1
_080EDB14:
	ldrb r2, [r6, #0x1c]
	ldrh r1, [r7, #0x18]
	adds r0, r4, #0
	ands r0, r1
	cmp r2, r0
	bne _080EDB22
	adds r3, #1
_080EDB22:
	ldrb r2, [r6, #0x1d]
	ldrh r1, [r7, #0x1a]
	adds r0, r4, #0
	ands r0, r1
	cmp r2, r0
	bne _080EDB30
	adds r3, #1
_080EDB30:
	ldrb r2, [r6, #0x1e]
	ldrh r1, [r7, #0x1c]
	adds r0, r4, #0
	ands r0, r1
	cmp r2, r0
	bne _080EDB3E
	adds r3, #1
_080EDB3E:
	ldrb r2, [r6, #0x1f]
	ldrh r1, [r7, #0x1e]
	adds r0, r4, #0
	ands r0, r1
	cmp r2, r0
	bne _080EDB4C
	adds r3, #1
_080EDB4C:
	adds r2, r3, #0
	adds r0, r6, #0
	adds r0, #0x20
	ldrb r1, [r0]
	ldrh r0, [r7, #0x20]
	ands r4, r0
	cmp r1, r4
	bne _080EDB5E
	adds r2, #1
_080EDB5E:
	ldr r3, _080EDC18 @ =0x00000241
	adds r0, r5, r3
	strb r2, [r0]
	mov r0, sl
	strh r0, [r5, #8]
	mov r1, r8
	strh r1, [r5, #0xa]
	ldrb r0, [r5, #6]
	adds r0, #1
	strb r0, [r5, #6]
_080EDB72:
	movs r2, #0x90
	lsls r2, r2, #2
	adds r6, r5, r2
	ldrb r2, [r6]
	adds r4, r2, #0
	ldr r7, _080EDC1C @ =gJoypad
	ldrh r1, [r7, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080EDB8C
	adds r0, r2, #1
	strb r0, [r6]
_080EDB8C:
	ldrh r1, [r7, #6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080EDBA4
	ldrb r0, [r6]
	ldr r3, _080EDC18 @ =0x00000241
	adds r1, r5, r3
	adds r0, #0xff
	ldrb r1, [r1]
	adds r0, r0, r1
	strb r0, [r6]
_080EDBA4:
	ldr r0, _080EDC18 @ =0x00000241
	adds r1, r5, r0
	ldrb r0, [r6]
	ldrb r1, [r1]
	bl __umodsi3
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	beq _080EDBC0
	movs r0, #1
	bl PlaySound
_080EDBC0:
	ldrh r2, [r5, #8]
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #0xf
	bgt _080EDBDE
	adds r2, #1
	strh r2, [r5, #8]
	ldr r3, _080EDC08 @ =gBlendRegBuffer
	movs r1, #0x1f
	ands r1, r2
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #2]
_080EDBDE:
	ldrh r1, [r5, #0xa]
	movs r2, #0xa
	ldrsh r0, [r5, r2]
	cmp r0, #0x1f
	bgt _080EDC20
	adds r0, r1, #1
	b _080EDC60
	.align 2, 0
_080EDBEC: .4byte gVideoRegBuffer
_080EDBF0: .4byte 0x0000FFF8
_080EDBF4: .4byte 0x0000F0FF
_080EDBF8: .4byte 0x00000606
_080EDBFC: .4byte gGraphic_MenuMisc
_080EDC00: .4byte gPalette_MenuMisc
_080EDC04: .4byte gBgMapOffsets
_080EDC08: .4byte gBlendRegBuffer
_080EDC0C: .4byte 0x00003E41
_080EDC10: .4byte gSystemSavedataManager
_080EDC14: .4byte gSineTable
_080EDC18: .4byte 0x00000241
_080EDC1C: .4byte gJoypad
_080EDC20:
	ldrh r1, [r7, #4]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _080EDC38
	movs r0, #2
	bl PlaySound
	ldrb r0, [r5, #6]
	adds r0, #2
	strb r0, [r5, #6]
	b _080EDCC4
_080EDC38:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080EDCC4
	movs r0, #3
	bl PlaySound
	movs r0, #0x40
	bl ClearBlink
	ldrb r0, [r5, #6]
	adds r0, #1
	strb r0, [r5, #6]
	b _080EDCC4
_080EDC54:
	ldrh r1, [r5, #0xa]
	movs r2, #0xa
	ldrsh r0, [r5, r2]
	cmp r0, #0
	beq _080EDC88
	subs r0, r1, #1
_080EDC60:
	adds r1, r0, #0
	strh r0, [r5, #0xa]
	ldr r2, _080EDC80 @ =gPaletteManager
	ldr r3, _080EDC84 @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	subs r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
	b _080EDCC4
	.align 2, 0
_080EDC80: .4byte gPaletteManager
_080EDC84: .4byte 0x00000402
_080EDC88:
	movs r0, #0x40
	bl ClearBlink
	adds r0, r5, #0
	movs r1, #4
	bl SetIntroMode
	b _080EDCC4
_080EDC98:
	ldrh r2, [r5, #8]
	movs r3, #8
	ldrsh r0, [r5, r3]
	cmp r0, #0
	beq _080EDCBC
	subs r2, #1
	strh r2, [r5, #8]
	ldr r3, _080EDCB8 @ =gBlendRegBuffer
	movs r1, #0x1f
	ands r1, r2
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #2]
	b _080EDCC4
	.align 2, 0
_080EDCB8: .4byte gBlendRegBuffer
_080EDCBC:
	mov r0, r8
	strb r0, [r5, #6]
	movs r0, #2
	strb r0, [r5, #5]
_080EDCC4:
	movs r0, #0x40
	bl GetBlinkMotionState
	mov r1, sb
	lsls r4, r1, #0x10
	asrs r1, r4, #0x10
	ldr r2, _080EDD38 @ =0x00000241
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r1, r0
	bge _080EDDA0
	mov r3, r8
	lsls r1, r3, #0x10
	asrs r0, r1, #0x10
	adds r7, r1, #0
	cmp r0, #6
	bgt _080EDDA0
	ldr r0, _080EDD3C @ =0x020021C8
	mov sl, r0
_080EDCEA:
	ldr r0, _080EDD40 @ =u8_ARRAY_0838607c
	asrs r6, r1, #0x10
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0xf0
	add r0, sl
	ldrb r2, [r0]
	ldr r0, _080EDD44 @ =gSineTable
	adds r1, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrb r1, [r1]
	cmp r2, r1
	bne _080EDD7A
	movs r1, #0x90
	lsls r1, r1, #2
	adds r3, r5, r1
	ldrb r0, [r3]
	asrs r2, r4, #0x10
	cmp r0, r2
	bne _080EDD20
	adds r1, #2
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
_080EDD20:
	ldr r4, _080EDD48 @ =StringOfsTable
	ldr r0, _080EDD4C @ =u16_ARRAY_08386084
	lsls r1, r6, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrb r0, [r3]
	cmp r0, r2
	beq _080EDD50
	adds r0, r1, #1
	lsls r0, r0, #1
	b _080EDD52
	.align 2, 0
_080EDD38: .4byte 0x00000241
_080EDD3C: .4byte gSystemSavedataManager+24
_080EDD40: .4byte u8_ARRAY_0838607c
_080EDD44: .4byte gSineTable
_080EDD48: .4byte StringOfsTable
_080EDD4C: .4byte u16_ARRAY_08386084
_080EDD50:
	lsls r0, r1, #1
_080EDD52:
	adds r0, r4, r0
	ldrh r0, [r0]
	ldr r1, _080EDDB0 @ =gStringData
	adds r0, r0, r1
	mov r2, sb
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r2, r4, #1
	adds r2, #0xa
	ldr r3, _080EDDB4 @ =0x00000241
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r2, r2, r1
	movs r1, #8
	bl PrintString
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov sb, r4
_080EDD7A:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r7, r1
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r2, sb
	lsls r4, r2, #0x10
	asrs r1, r4, #0x10
	ldr r3, _080EDDB4 @ =0x00000241
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r1, r0
	bge _080EDDA0
	mov r0, r8
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	adds r7, r1, #0
	cmp r0, #6
	ble _080EDCEA
_080EDDA0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EDDB0: .4byte gStringData
_080EDDB4: .4byte 0x00000241

	thumb_func_start FUN_080eddb8
FUN_080eddb8: @ 0x080EDDB8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #6]
	cmp r0, #1
	beq _080EDDE2
	cmp r0, #1
	bgt _080EDDCC
	cmp r0, #0
	beq _080EDDD6
	b _080EDEB2
_080EDDCC:
	cmp r0, #2
	beq _080EDE3A
	cmp r0, #3
	beq _080EDE88
	b _080EDEB2
_080EDDD6:
	strh r0, [r6, #8]
	movs r0, #0x20
	strh r0, [r6, #0xa]
	ldrb r0, [r6, #6]
	adds r0, #1
	strb r0, [r6, #6]
_080EDDE2:
	ldrh r2, [r6, #8]
	movs r1, #8
	ldrsh r0, [r6, r1]
	cmp r0, #0xf
	bgt _080EDE00
	adds r2, #1
	strh r2, [r6, #8]
	ldr r3, _080EDE1C @ =gBlendRegBuffer
	movs r1, #0x1f
	ands r1, r2
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #2]
_080EDE00:
	ldr r0, _080EDE20 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _080EDE24
	movs r0, #2
	bl PlaySound
	ldrb r0, [r6, #6]
	adds r0, #1
	strb r0, [r6, #6]
	b _080EDEB2
	.align 2, 0
_080EDE1C: .4byte gBlendRegBuffer
_080EDE20: .4byte gJoypad
_080EDE24:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080EDEB2
	movs r0, #3
	bl PlaySound
	ldrb r0, [r6, #6]
	adds r0, #2
	strb r0, [r6, #6]
	b _080EDEB2
_080EDE3A:
	ldrh r0, [r6, #0xa]
	movs r2, #0xa
	ldrsh r4, [r6, r2]
	cmp r4, #0
	beq _080EDE70
	subs r0, #1
	adds r1, r0, #0
	strh r0, [r6, #0xa]
	ldr r2, _080EDE68 @ =gPaletteManager
	ldr r3, _080EDE6C @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	subs r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
	b _080EDEB2
	.align 2, 0
_080EDE68: .4byte gPaletteManager
_080EDE6C: .4byte 0x00000402
_080EDE70:
	movs r0, #0x40
	bl ClearBlink
	ldr r0, _080EDE84 @ =gBlendRegBuffer
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6, #6]
	movs r0, #3
	b _080EDEB0
	.align 2, 0
_080EDE84: .4byte gBlendRegBuffer
_080EDE88:
	ldrh r2, [r6, #8]
	movs r3, #8
	ldrsh r0, [r6, r3]
	cmp r0, #0
	beq _080EDEAC
	subs r2, #1
	strh r2, [r6, #8]
	ldr r3, _080EDEA8 @ =gBlendRegBuffer
	movs r1, #0x1f
	ands r1, r2
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #2]
	b _080EDEB2
	.align 2, 0
_080EDEA8: .4byte gBlendRegBuffer
_080EDEAC:
	movs r0, #1
	strb r0, [r6, #6]
_080EDEB0:
	strb r0, [r6, #5]
_080EDEB2:
	movs r0, #0x40
	bl GetBlinkMotionState
	ldr r5, _080EDEF4 @ =StringOfsTable
	movs r1, #0x88
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r0, [r0]
	ldr r4, _080EDEF8 @ =gStringData
	adds r0, r0, r4
	movs r1, #0xd
	movs r2, #2
	bl PrintString
	ldr r1, _080EDEFC @ =0x08386092
	ldr r2, _080EDF00 @ =0x00000242
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r0, r0, r4
	movs r1, #3
	movs r2, #4
	bl PrintString
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EDEF4: .4byte StringOfsTable
_080EDEF8: .4byte gStringData
_080EDEFC: .4byte u16_ARRAY_08386092
_080EDF00: .4byte 0x00000242

	thumb_func_start FUN_080edf04
FUN_080edf04: @ 0x080EDF04
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r5, [r6, #6]
	cmp r5, #0
	beq _080EDF14
	cmp r5, #1
	beq _080EDF88
	b _080EDF9C
_080EDF14:
	ldr r4, _080EDFA4 @ =gPaletteManager
	ldr r1, _080EDFA8 @ =0x00000402
	adds r0, r4, r1
	movs r1, #0x20
	strb r1, [r0]
	ldr r2, _080EDFAC @ =0x00000401
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	bl ClearBlinkings
	ldr r0, _080EDFB0 @ =gBlendRegBuffer
	strh r5, [r0]
	ldr r1, _080EDFB4 @ =gWindowRegBuffer
	strh r5, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xe]
	ldr r0, _080EDFB8 @ =wMOSAIC
	strh r5, [r0]
	strh r5, [r4]
	bl text_080e9730
	ldr r2, _080EDFBC @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EDFC0 @ =0x0000FFF8
	ands r0, r1
	ldr r1, _080EDFC4 @ =0x0000F0FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	bl SwitchProcess
	ldr r0, _080EDFC8 @ =gGameState
	ldr r2, _080EDFCC @ =0x00000242
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, #3
	bl SetGameMode
	ldr r1, _080EDFD0 @ =Process_Game
	movs r0, #1
	bl ResetProcess
	ldrb r0, [r6, #6]
	adds r0, #1
	strb r0, [r6, #6]
_080EDF88:
	ldr r0, _080EDFD4 @ =gProcessManager
	movs r3, #0x99
	lsls r3, r3, #5
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, #1
	bne _080EDF9C
	movs r0, #0
	strb r0, [r6, #6]
	strb r1, [r6, #5]
_080EDF9C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EDFA4: .4byte gPaletteManager
_080EDFA8: .4byte 0x00000402
_080EDFAC: .4byte 0x00000401
_080EDFB0: .4byte gBlendRegBuffer
_080EDFB4: .4byte gWindowRegBuffer
_080EDFB8: .4byte wMOSAIC
_080EDFBC: .4byte gVideoRegBuffer
_080EDFC0: .4byte 0x0000FFF8
_080EDFC4: .4byte 0x0000F0FF
_080EDFC8: .4byte gGameState
_080EDFCC: .4byte 0x00000242
_080EDFD0: .4byte Process_Game
_080EDFD4: .4byte gProcessManager
