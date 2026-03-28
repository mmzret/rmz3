	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initCielMinigame
initCielMinigame: @ 0x080F98A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	ldr r0, _080F9BE0 @ =0x00000DC4
	adds r1, r7, r0
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r1, #4]
	ldr r2, _080F9BE4 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080F9BE8 @ =0x0000FFF8
	ands r0, r1
	ldr r1, _080F9BEC @ =0x0000F0FF
	ands r0, r1
	movs r3, #0xdc
	lsls r3, r3, #6
	adds r1, r3, #0
	movs r3, #0
	mov r4, sp
	strh r3, [r4, #0xc]
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _080F9BF0 @ =0x00000206
	adds r0, r4, #0
	strh r0, [r2, #6]
	ldr r1, _080F9BF4 @ =0x00000407
	adds r0, r1, #0
	strh r0, [r2, #8]
	movs r3, #0
	str r3, [r2, #0x10]
	str r3, [r2, #0x14]
	ldr r0, _080F9BF8 @ =0x08547C80
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, _080F9BFC @ =0x08547C8C
	movs r1, #0
	bl LoadPalette
	ldr r4, _080F9C00 @ =0x00000ED8
	adds r0, r7, r4
	ldr r4, _080F9C04 @ =gBgMapOffsets
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0x80
	movs r3, #0
	bl loadBgMap_08004248
	movs r2, #0
	str r2, [sp]
	movs r0, #0x24
	adds r1, r4, #0
	movs r2, #0x81
	movs r3, #0
	bl LoadBgMap
	ldr r5, _080F9C08 @ =0x00001234
	ldr r3, _080F9C0C @ =gStaticMotionGraphics
	mov sl, r3
	adds r0, r5, r3
	movs r4, #0xe9
	lsls r4, r4, #1
	ldr r2, _080F9C10 @ =wStaticGraphicTilenums
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	ldr r6, _080F9C14 @ =gStaticMotionGraphics+12
	adds r5, r5, r6
	ldr r0, _080F9C18 @ =wStaticMotionPalIDs
	mov sb, r0
	add r4, sb
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	add r1, r8
	adds r0, r5, #0
	bl LoadPalette
	ldr r5, _080F9C1C @ =0x00001248
	mov r3, sl
	adds r0, r5, r3
	movs r4, #0xea
	lsls r4, r4, #1
	ldr r2, _080F9C10 @ =wStaticGraphicTilenums
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	adds r5, r5, r6
	add r4, sb
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r5, #0
	bl LoadPalette
	ldr r4, _080F9C10 @ =wStaticGraphicTilenums
	ldrh r1, [r4]
	mov r2, sl
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	mov r0, sl
	bl LoadGraphic
	mov r4, sb
	ldrh r1, [r4]
	ldrb r0, [r6, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r6, #0
	bl LoadPalette
	ldr r0, _080F9C20 @ =0x00000DCC
	adds r1, r7, r0
	mov r2, sp
	ldrb r2, [r2, #0xc]
	strb r2, [r1, #4]
	mov r3, sp
	ldrb r3, [r3, #0xc]
	strb r3, [r1, #5]
	movs r4, #0
	str r4, [r1, #8]
	ldr r0, _080F9C24 @ =gSystemSavedataManager
	ldr r0, [r0, #0x28]
	str r0, [r1, #0xc]
	strh r4, [r1, #6]
	movs r5, #0
	ldr r0, _080F9C28 @ =0x00000DE4
	adds r2, r7, r0
	movs r3, #0xff
_080F99EC:
	adds r0, r2, r5
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F99EC
	ldr r1, _080F9C20 @ =0x00000DCC
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0, #0x10]
	movs r1, #0x78
	strh r1, [r0, #0x12]
	movs r5, #0
	movs r2, #0xde
	lsls r2, r2, #4
	adds r2, r2, r7
	mov r8, r2
	ldr r3, _080F9C2C @ =0x00000DE9
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0xdf
	lsls r4, r4, #4
	adds r4, r4, r7
	mov sl, r4
	ldr r0, _080F9C30 @ =0x00000E04
	adds r0, r7, r0
	str r0, [sp, #0x18]
	ldr r1, _080F9C34 @ =0x00000DEE
	adds r1, r7, r1
	str r1, [sp, #0x10]
	ldr r2, _080F9C38 @ =0x00000DEF
	adds r2, r7, r2
	str r2, [sp, #0x14]
	ldr r3, _080F9C3C @ =0x00000E0F
	adds r3, r7, r3
	str r3, [sp, #0x20]
	ldr r4, _080F9C40 @ =0x00000E0E
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	movs r0, #0xe1
	lsls r0, r0, #4
	adds r0, r7, r0
	str r0, [sp, #0x24]
	ldr r1, _080F9C44 @ =0x00000E12
	adds r1, r7, r1
	str r1, [sp, #0x28]
	ldr r2, _080F9C48 @ =0x00000E13
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	ldr r3, _080F9C4C @ =0x00000E14
	adds r3, r7, r3
	str r3, [sp, #0x30]
	ldr r4, _080F9C50 @ =0x00000E15
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r0, _080F9C54 @ =0x00000E16
	adds r0, r7, r0
	str r0, [sp, #0x38]
	ldr r1, _080F9C58 @ =0x00000E17
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _080F9C5C @ =0x02036DCC
_080F9A6E:
	mov r2, r8
	adds r4, r2, r5
	ldr r1, [r6]
	ldr r0, _080F9C60 @ =0x41C64E6D
	muls r0, r1, r0
	ldr r3, _080F9C64 @ =0x00003039
	adds r0, r0, r3
	str r0, [r6]
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	strb r0, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _080F9A6E
	movs r5, #0
	mov r1, sb
	movs r2, #0
_080F9A98:
	adds r0, r1, r5
	strb r2, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F9A98
	movs r5, #0
	mov r2, sl
	movs r4, #0
	movs r3, #0xff
	ldr r1, [sp, #0x18]
_080F9AB0:
	lsls r0, r5, #1
	adds r0, r2, r0
	strh r3, [r0]
	adds r0, r1, r5
	strb r4, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #9
	bls _080F9AB0
	ldr r4, _080F9C20 @ =0x00000DCC
	adds r1, r7, r4
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x24]
	movs r0, #1
	strh r0, [r1, #0x28]
	movs r0, #2
	strh r0, [r1, #0x2e]
	movs r0, #3
	strh r0, [r1, #0x32]
	movs r0, #4
	strh r0, [r1, #0x34]
	ldr r0, [sp, #0x10]
	strb r2, [r0]
	ldr r1, [sp, #0x14]
	strb r2, [r1]
	movs r5, #0
_080F9AE8:
	adds r0, r7, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_080b221c
	adds r0, r7, #0
	movs r1, #1
	adds r2, r5, #0
	bl FUN_080b221c
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F9AE8
	movs r5, #0
_080F9B08:
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0809c1cc
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _080F9B08
	movs r5, #0
_080F9B1E:
	adds r0, r7, #0
	movs r1, #0
	adds r2, r5, #0
	bl createCielMiniObj
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #9
	bls _080F9B1E
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl createCielMiniObj
	movs r0, #0xd8
	lsls r0, r0, #8
	movs r1, #0xb0
	lsls r1, r1, #7
	ldr r3, _080F9C68 @ =0x00000DD8
	adds r2, r7, r3
	movs r3, #0
	str r3, [sp]
	movs r3, #5
	str r3, [sp, #4]
	movs r5, #1
	str r5, [sp, #8]
	movs r3, #0
	bl CreateGhost79_1
	ldr r4, _080F9C20 @ =0x00000DCC
	adds r1, r7, r4
	str r0, [r1]
	ldr r0, _080F9C6C @ =gZakoHeaderPtr
	ldr r0, [r0]
	ldrh r0, [r0, #0xa]
	ldr r1, [sp, #0x20]
	strb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	movs r4, #0
	movs r0, #0x40
	ldr r3, [sp, #0x24]
	strh r0, [r3]
	ldr r0, [sp, #0x28]
	strb r5, [r0]
	ldr r1, [sp, #0x2c]
	strb r4, [r1]
	ldr r2, [sp, #0x30]
	strb r4, [r2]
	ldr r3, [sp, #0x34]
	strb r4, [r3]
	ldr r0, [sp, #0x38]
	strb r4, [r0]
	ldr r1, [sp, #0x3c]
	strb r4, [r1]
	movs r0, #0xd6
	movs r1, #0
	bl LoadBlink
	ldr r2, _080F9C70 @ =gWindowRegBuffer
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x12
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xe]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2, #0xe]
	ldr r0, _080F9C74 @ =0x0000D0E0
	strh r0, [r2, #4]
	ldr r0, _080F9C78 @ =0x00000838
	strh r0, [r2, #8]
	ldr r4, _080F9C00 @ =0x00000ED8
	adds r0, r7, r4
	ldr r1, _080F9C7C @ =gVideoRegBuffer+6
	ldrh r2, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	bl RequestBgMapTransfer
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F9BE0: .4byte 0x00000DC4
_080F9BE4: .4byte gVideoRegBuffer
_080F9BE8: .4byte 0x0000FFF8
_080F9BEC: .4byte 0x0000F0FF
_080F9BF0: .4byte 0x00000206
_080F9BF4: .4byte 0x00000407
_080F9BF8: .4byte 0x08547C80
_080F9BFC: .4byte 0x08547C8C
_080F9C00: .4byte 0x00000ED8
_080F9C04: .4byte gBgMapOffsets
_080F9C08: .4byte 0x00001234
_080F9C0C: .4byte gStaticMotionGraphics
_080F9C10: .4byte wStaticGraphicTilenums
_080F9C14: .4byte gStaticMotionGraphics+12
_080F9C18: .4byte wStaticMotionPalIDs
_080F9C1C: .4byte 0x00001248
_080F9C20: .4byte 0x00000DCC
_080F9C24: .4byte gSystemSavedataManager
_080F9C28: .4byte 0x00000DE4
_080F9C2C: .4byte 0x00000DE9
_080F9C30: .4byte 0x00000E04
_080F9C34: .4byte 0x00000DEE
_080F9C38: .4byte 0x00000DEF
_080F9C3C: .4byte 0x00000E0F
_080F9C40: .4byte 0x00000E0E
_080F9C44: .4byte 0x00000E12
_080F9C48: .4byte 0x00000E13
_080F9C4C: .4byte 0x00000E14
_080F9C50: .4byte 0x00000E15
_080F9C54: .4byte 0x00000E16
_080F9C58: .4byte 0x00000E17
_080F9C5C: .4byte 0x02036DCC
_080F9C60: .4byte 0x41C64E6D
_080F9C64: .4byte 0x00003039
_080F9C68: .4byte 0x00000DD8
_080F9C6C: .4byte gZakoHeaderPtr
_080F9C70: .4byte gWindowRegBuffer
_080F9C74: .4byte 0x0000D0E0
_080F9C78: .4byte 0x00000838
_080F9C7C: .4byte gVideoRegBuffer+6

	thumb_func_start cielMinigame
cielMinigame: @ 0x080F9C80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, _080F9CCC @ =0x00000DCC
	adds r4, r6, r0
	ldrh r0, [r4, #6]
	adds r0, #0x80
	strh r0, [r4, #6]
	ldr r1, _080F9CD0 @ =0x02002154
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r1]
	rsbs r0, r0, #0
	strh r0, [r1, #2]
	movs r0, #0xd6
	bl UpdateBlinkMotionState
	ldrb r0, [r4, #4]
	cmp r0, #2
	bhi _080F9CE0
	ldr r1, _080F9CD4 @ =0x00000E17
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0xf
	bhi _080F9CD8
	ldr r1, [r4]
	movs r0, #1
	strb r0, [r1, #0x13]
	b _080F9D32
	.align 2, 0
_080F9CCC: .4byte 0x00000DCC
_080F9CD0: .4byte 0x02002154
_080F9CD4: .4byte 0x00000E17
_080F9CD8:
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0x13]
	b _080F9D32
_080F9CE0:
	ldr r0, [r4]
	movs r1, #1
	strb r1, [r0, #0x13]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	cmp r0, r1
	bls _080F9D32
	adds r1, #1
	str r1, [r4, #0xc]
	ldr r2, _080F9D48 @ =0x00000E16
	adds r4, r6, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _080F9D12
	ldr r0, _080F9D4C @ =gSystemSavedataManager
	ldr r0, [r0, #0x28]
	cmp r0, r1
	bhs _080F9D12
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080F9D12:
	ldr r3, _080F9D50 @ =0x00000DCC
	adds r0, r6, r3
	ldr r0, [r0, #0xc]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080F9D32
	movs r0, #0x9c
	lsls r0, r0, #1
	bl isSoundPlaying
	cmp r0, #0
	bne _080F9D32
	ldr r0, _080F9D54 @ =0x00000137
	bl PlaySound
_080F9D32:
	ldr r4, _080F9D50 @ =0x00000DCC
	adds r0, r6, r4
	ldrb r0, [r0, #4]
	cmp r0, #5
	bls _080F9D3E
	b _080F9E74
_080F9D3E:
	lsls r0, r0, #2
	ldr r1, _080F9D58 @ =_080F9D5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F9D48: .4byte 0x00000E16
_080F9D4C: .4byte gSystemSavedataManager
_080F9D50: .4byte 0x00000DCC
_080F9D54: .4byte 0x00000137
_080F9D58: .4byte _080F9D5C
_080F9D5C: @ jump table
	.4byte _080F9D74 @ case 0
	.4byte _080F9D98 @ case 1
	.4byte _080F9DCC @ case 2
	.4byte _080F9DF8 @ case 3
	.4byte _080F9E30 @ case 4
	.4byte _080F9E60 @ case 5
_080F9D74:
	movs r0, #0x9b
	lsls r0, r0, #1
	bl playBGM
	ldr r0, _080F9D90 @ =0x00000DCC
	adds r2, r6, r0
	ldr r3, _080F9D94 @ =0x00000E15
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r2, #4]
	adds r0, #1
	strb r0, [r2, #4]
	b _080FA1FC
	.align 2, 0
_080F9D90: .4byte 0x00000DCC
_080F9D94: .4byte 0x00000E15
_080F9D98:
	ldr r4, _080F9DC4 @ =0x00000DCC
	adds r5, r6, r4
	ldr r0, _080F9DC8 @ =0x00000E15
	adds r4, r6, r0
	ldrb r0, [r4]
	adds r1, r0, #1
	strb r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bhi _080F9DB0
	b _080FA1FC
_080F9DB0:
	movs r0, #0
	bl CreateMissionAlert
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r5, #4]
	adds r0, #1
	strb r0, [r5, #4]
	b _080FA1FC
	.align 2, 0
_080F9DC4: .4byte 0x00000DCC
_080F9DC8: .4byte 0x00000E15
_080F9DCC:
	ldr r1, _080F9DF0 @ =0x00000DCC
	adds r3, r6, r1
	ldr r2, _080F9DF4 @ =0x00000E15
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r2, r1, #1
	strb r2, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x78
	bhi _080F9DE4
	b _080FA1FC
_080F9DE4:
	movs r0, #0
	str r0, [r3, #0xc]
	ldrb r0, [r3, #4]
	adds r0, #1
	strb r0, [r3, #4]
	b _080FA1FC
	.align 2, 0
_080F9DF0: .4byte 0x00000DCC
_080F9DF4: .4byte 0x00000E15
_080F9DF8:
	ldr r3, _080F9E24 @ =0x00000DCC
	adds r4, r6, r3
	ldr r1, _080F9E28 @ =0x00000E13
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _080F9E74
	movs r0, #4
	bl CreateMissionAlert
	movs r0, #0x9b
	lsls r0, r0, #1
	bl fadeoutBGM
	ldr r2, _080F9E2C @ =0x00000E15
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r4, #4]
	adds r0, #1
	strb r0, [r4, #4]
	b _080F9E74
	.align 2, 0
_080F9E24: .4byte 0x00000DCC
_080F9E28: .4byte 0x00000E13
_080F9E2C: .4byte 0x00000E15
_080F9E30:
	ldr r4, _080F9E54 @ =0x00000DCC
	adds r3, r6, r4
	ldr r1, _080F9E58 @ =0x00000E15
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r1, #1
	strb r2, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0xa0
	bls _080F9E74
	ldr r1, _080F9E5C @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrb r0, [r3, #4]
	adds r0, #1
	strb r0, [r3, #4]
	b _080F9E74
	.align 2, 0
_080F9E54: .4byte 0x00000DCC
_080F9E58: .4byte 0x00000E15
_080F9E5C: .4byte gGameState
_080F9E60:
	ldr r0, _080F9E70 @ =gGameState
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r0, #0x20
	bne _080F9E74
	movs r0, #0
	b _080FA1FE
	.align 2, 0
_080F9E70: .4byte gGameState
_080F9E74:
	ldr r4, _080F9F54 @ =0x00000DCC
	adds r3, r6, r4
	ldrh r0, [r3, #0x10]
	adds r0, #1
	strh r0, [r3, #0x10]
	ldrh r1, [r3, #0x12]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _080F9E8A
	strh r1, [r3, #0x10]
_080F9E8A:
	ldr r0, _080F9F58 @ =gZakoHeaderPtr
	ldr r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	ldr r4, _080F9F5C @ =0x00000E13
	adds r4, r6, r4
	str r4, [sp, #4]
	ldr r2, _080F9F60 @ =0x00000E14
	adds r2, r6, r2
	str r2, [sp, #8]
	cmp r0, #0
	bne _080F9EA4
	b _080F9FE2
_080F9EA4:
	ldr r4, _080F9F64 @ =0x00000E0F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r4, #0xa
	ldrsh r1, [r1, r4]
	mov r8, r0
	cmp r2, r1
	ble _080F9EB6
	b _080F9FE2
_080F9EB6:
	ldr r1, _080F9F68 @ =0x00000E12
	adds r0, r6, r1
	ldrb r1, [r0]
	str r0, [sp]
	cmp r1, #0
	bne _080F9EC4
	b _080F9FE2
_080F9EC4:
	ldrh r0, [r3, #0x10]
	ldrh r3, [r3, #0x12]
	cmp r0, r3
	beq _080F9ECE
	b _080F9FE2
_080F9ECE:
	ldr r4, _080F9F6C @ =gGameState
	ldr r3, _080F9F70 @ =0x0000626C
	adds r2, r4, r3
	ldr r1, [r2]
	ldr r0, _080F9F74 @ =0x41C64E6D
	muls r0, r1, r0
	ldr r1, _080F9F78 @ =0x00003039
	adds r0, r0, r1
	str r0, [r2]
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r5, #0
	ldr r2, _080F9F7C @ =0x00000DE4
	adds r7, r6, r2
	ldr r3, _080F9F54 @ =0x00000DCC
	adds r4, r6, r3
	mov sl, r5
_080F9EFA:
	mov r1, sb
	adds r0, r5, r1
	movs r1, #5
	bl __modsi3
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080F9FD8
	ldrb r0, [r4, #0x14]
	strb r0, [r1]
	ldrb r0, [r4, #0x15]
	strb r0, [r4, #0x14]
	ldrb r0, [r4, #0x16]
	strb r0, [r4, #0x15]
	ldrb r0, [r4, #0x17]
	strb r0, [r4, #0x16]
	ldr r3, _080F9F6C @ =gGameState
	ldr r0, _080F9F70 @ =0x0000626C
	adds r2, r3, r0
	ldr r1, [r2]
	ldr r0, _080F9F74 @ =0x41C64E6D
	muls r0, r1, r0
	ldr r1, _080F9F78 @ =0x00003039
	adds r0, r0, r1
	str r0, [r2]
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	strb r0, [r4, #0x17]
	mov r2, sl
	strh r2, [r4, #0x10]
	ldr r3, _080F9F80 @ =0x00000E0E
	adds r0, r6, r3
	ldrb r1, [r0]
	mov r2, r8
	ldrb r0, [r2]
	subs r1, r1, r0
	cmp r1, #0
	beq _080F9F84
	cmp r1, #1
	beq _080F9FB6
	b _080F9FCA
	.align 2, 0
_080F9F54: .4byte 0x00000DCC
_080F9F58: .4byte gZakoHeaderPtr
_080F9F5C: .4byte 0x00000E13
_080F9F60: .4byte 0x00000E14
_080F9F64: .4byte 0x00000E0F
_080F9F68: .4byte 0x00000E12
_080F9F6C: .4byte gGameState
_080F9F70: .4byte 0x0000626C
_080F9F74: .4byte 0x41C64E6D
_080F9F78: .4byte 0x00003039
_080F9F7C: .4byte 0x00000DE4
_080F9F80: .4byte 0x00000E0E
_080F9F84:
	movs r3, #0xe1
	lsls r3, r3, #4
	adds r5, r6, r3
	ldrh r0, [r5]
	ldr r1, _080F9F98 @ =0x0000017F
	cmp r0, r1
	bhi _080F9F9C
	adds r0, #0x14
	strh r0, [r5]
	b _080F9FCA
	.align 2, 0
_080F9F98: .4byte 0x0000017F
_080F9F9C:
	ldrb r0, [r4, #4]
	cmp r0, #3
	bhi _080F9FCA
	movs r0, #6
	bl PlaySound
	movs r0, #0x40
	strh r0, [r5]
	mov r2, r8
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _080F9FCA
_080F9FB6:
	movs r3, #0xe1
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrh r1, [r2]
	ldr r0, _080F9FD4 @ =0x000003FF
	cmp r1, r0
	bhi _080F9FCA
	adds r0, r1, #0
	adds r0, #0x14
	strh r0, [r2]
_080F9FCA:
	mov r0, sl
	ldr r4, [sp]
	strb r0, [r4]
	b _080F9FE2
	.align 2, 0
_080F9FD4: .4byte 0x000003FF
_080F9FD8:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F9EFA
_080F9FE2:
	ldr r1, _080FA020 @ =0x00000DCC
	adds r0, r6, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080FA092
	ldr r2, _080FA024 @ =gJoypad
	ldrh r1, [r2, #4]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080FA03C
	ldr r2, _080FA028 @ =0x00000DEE
	adds r0, r6, r2
	ldrb r1, [r0]
	ldr r3, _080FA02C @ =0x00000E04
	adds r0, r6, r3
	adds r0, r0, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _080FA092
	lsls r0, r1, #1
	movs r4, #0xdf
	lsls r4, r4, #4
	adds r1, r6, r4
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0xff
	bne _080FA030
	strh r2, [r1]
	b _080FA034
	.align 2, 0
_080FA020: .4byte 0x00000DCC
_080FA024: .4byte gJoypad
_080FA028: .4byte 0x00000DEE
_080FA02C: .4byte 0x00000E04
_080FA030:
	movs r0, #0xff
	strh r0, [r1]
_080FA034:
	movs r0, #5
	bl PlaySound
	b _080FA092
_080FA03C:
	movs r4, #0xff
	ldrh r1, [r2, #6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080FA04C
	movs r4, #0
	b _080FA06E
_080FA04C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080FA058
	movs r4, #1
	b _080FA06E
_080FA058:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080FA064
	movs r4, #2
	b _080FA06E
_080FA064:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080FA06E
	movs r4, #3
_080FA06E:
	cmp r4, #0xff
	beq _080FA092
	ldr r0, _080FA0BC @ =0x00000DEE
	adds r2, r6, r0
	ldrb r3, [r2]
	ldr r1, _080FA0C0 @ =0x08386B58
	lsls r0, r3, #2
	adds r0, r4, r0
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r3, r0
	beq _080FA092
	movs r0, #1
	bl PlaySound
_080FA092:
	ldr r1, [sp, #4]
	ldrb r0, [r1]
	ldr r2, [sp, #8]
	ldrb r2, [r2]
	cmp r0, r2
	bne _080FA0A0
	b _080FA1FC
_080FA0A0:
	ldr r3, [sp, #8]
	strb r0, [r3]
	movs r0, #4
	bl PlaySound
	ldr r4, [sp, #4]
	ldrb r0, [r4]
	cmp r0, #2
	beq _080FA108
	cmp r0, #2
	bgt _080FA0C4
	cmp r0, #1
	beq _080FA0CA
	b _080FA1E4
	.align 2, 0
_080FA0BC: .4byte 0x00000DEE
_080FA0C0: .4byte 0x08386B58
_080FA0C4:
	cmp r0, #3
	beq _080FA17C
	b _080FA1E4
_080FA0CA:
	ldr r0, _080FA0F4 @ =0x00001106
	adds r1, r6, r0
	ldr r2, _080FA0F8 @ =0x00003092
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _080FA0FC @ =0x00001108
	adds r1, r6, r3
	ldr r4, _080FA100 @ =0x00003093
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA104 @ =0x00001146
	adds r1, r6, r0
	adds r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r3, #0x40
	adds r1, r6, r3
	adds r4, #6
	adds r0, r4, #0
	strh r0, [r1]
	b _080FA1E4
	.align 2, 0
_080FA0F4: .4byte 0x00001106
_080FA0F8: .4byte 0x00003092
_080FA0FC: .4byte 0x00001108
_080FA100: .4byte 0x00003093
_080FA104: .4byte 0x00001146
_080FA108:
	ldr r0, _080FA150 @ =0x00001106
	adds r1, r6, r0
	ldr r2, _080FA154 @ =0x00003092
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _080FA158 @ =0x00001108
	adds r1, r6, r3
	ldr r4, _080FA15C @ =0x00003093
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA160 @ =0x00001146
	adds r0, r6, r1
	adds r2, #6
	adds r3, r2, #0
	strh r3, [r0]
	ldr r4, _080FA164 @ =0x00001148
	adds r0, r6, r4
	ldr r1, _080FA168 @ =0x00003099
	adds r2, r1, #0
	strh r2, [r0]
	subs r4, #0x3e
	adds r1, r6, r4
	ldr r4, _080FA16C @ =0x00003094
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA170 @ =0x0000110C
	adds r1, r6, r0
	adds r4, #1
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA174 @ =0x0000114A
	adds r0, r6, r1
	strh r3, [r0]
	ldr r3, _080FA178 @ =0x0000114C
	b _080FA1E0
	.align 2, 0
_080FA150: .4byte 0x00001106
_080FA154: .4byte 0x00003092
_080FA158: .4byte 0x00001108
_080FA15C: .4byte 0x00003093
_080FA160: .4byte 0x00001146
_080FA164: .4byte 0x00001148
_080FA168: .4byte 0x00003099
_080FA16C: .4byte 0x00003094
_080FA170: .4byte 0x0000110C
_080FA174: .4byte 0x0000114A
_080FA178: .4byte 0x0000114C
_080FA17C:
	ldr r4, _080FA210 @ =0x00001106
	adds r1, r6, r4
	ldr r2, _080FA214 @ =0x00003092
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _080FA218 @ =0x00001108
	adds r1, r6, r3
	ldr r4, _080FA21C @ =0x00003093
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA220 @ =0x00001146
	adds r0, r6, r1
	adds r2, #6
	adds r3, r2, #0
	strh r3, [r0]
	ldr r4, _080FA224 @ =0x00001148
	adds r0, r6, r4
	ldr r1, _080FA228 @ =0x00003099
	adds r2, r1, #0
	strh r2, [r0]
	subs r4, #0x3e
	adds r1, r6, r4
	ldr r4, _080FA22C @ =0x00003094
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA230 @ =0x0000110C
	adds r1, r6, r0
	adds r4, #1
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA234 @ =0x0000114A
	adds r0, r6, r1
	strh r3, [r0]
	ldr r4, _080FA238 @ =0x0000114C
	adds r0, r6, r4
	strh r2, [r0]
	ldr r0, _080FA23C @ =0x0000110E
	adds r1, r6, r0
	ldr r4, _080FA240 @ =0x00003096
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA244 @ =0x00001110
	adds r1, r6, r0
	adds r4, #1
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA248 @ =0x0000114E
	adds r0, r6, r1
	strh r3, [r0]
	ldr r3, _080FA24C @ =0x00001150
_080FA1E0:
	adds r0, r6, r3
	strh r2, [r0]
_080FA1E4:
	ldr r4, _080FA250 @ =0x00000ED8
	adds r0, r6, r4
	ldr r1, _080FA254 @ =gVideoRegBuffer+6
	ldrh r2, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	bl RequestBgMapTransfer
_080FA1FC:
	movs r0, #1
_080FA1FE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FA210: .4byte 0x00001106
_080FA214: .4byte 0x00003092
_080FA218: .4byte 0x00001108
_080FA21C: .4byte 0x00003093
_080FA220: .4byte 0x00001146
_080FA224: .4byte 0x00001148
_080FA228: .4byte 0x00003099
_080FA22C: .4byte 0x00003094
_080FA230: .4byte 0x0000110C
_080FA234: .4byte 0x0000114A
_080FA238: .4byte 0x0000114C
_080FA23C: .4byte 0x0000110E
_080FA240: .4byte 0x00003096
_080FA244: .4byte 0x00001110
_080FA248: .4byte 0x0000114E
_080FA24C: .4byte 0x00001150
_080FA250: .4byte 0x00000ED8
_080FA254: .4byte gVideoRegBuffer+6

