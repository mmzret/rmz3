	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start mob_chat_080d97b4
mob_chat_080d97b4: @ 0x080D97B4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080D983C
	ldr r1, _080D980C @ =sMobNPCTalks
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
	ldrh r0, [r1]
	bl PrintNormalMessage
	adds r0, r4, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D9836
	movs r2, #0
	ldr r0, _080D9810 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080D9800
	movs r2, #1
_080D9800:
	cmp r2, #0
	beq _080D9814
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080D981A
	.align 2, 0
_080D980C: .4byte sMobNPCTalks
_080D9810: .4byte pZero2
_080D9814:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080D981A:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080D9836:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D983C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _080D9870 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080D98DE
	ldr r2, _080D9874 @ =gSystemSavedataManager
	ldrb r1, [r2, #0xf]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D9898
	adds r3, r4, #0
	adds r3, #0xba
	ldrh r1, [r3]
	ldr r0, _080D9878 @ =0x0000029E
	cmp r1, r0
	bne _080D987C
	adds r0, #1
	strh r0, [r3]
	ldrh r0, [r3]
	bl PrintNormalMessage
	b _080D98DE
	.align 2, 0
_080D9870: .4byte gTextWindow+8
_080D9874: .4byte gSystemSavedataManager
_080D9878: .4byte 0x0000029E
_080D987C:
	movs r0, #0xa8
	lsls r0, r0, #2
	cmp r1, r0
	beq _080D988A
	ldr r0, _080D9894 @ =0x000002A2
	cmp r1, r0
	bne _080D9898
_080D988A:
	adds r0, #1
	strh r0, [r3]
	bl PrintNormalMessage
	b _080D98DE
	.align 2, 0
_080D9894: .4byte 0x000002A2
_080D9898:
	ldrb r1, [r2, #0xe]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D98D0
	adds r2, r4, #0
	adds r2, #0xba
	ldrh r1, [r2]
	ldr r0, _080D98C4 @ =0x000002A7
	cmp r1, r0
	beq _080D98BA
	ldr r0, _080D98C8 @ =0x000002A9
	cmp r1, r0
	beq _080D98BA
	ldr r0, _080D98CC @ =0x000002AB
	cmp r1, r0
	bne _080D98D0
_080D98BA:
	adds r0, #1
	strh r0, [r2]
	bl PrintNormalMessage
	b _080D98DE
	.align 2, 0
_080D98C4: .4byte 0x000002A7
_080D98C8: .4byte 0x000002A9
_080D98CC: .4byte 0x000002AB
_080D98D0:
	ldr r1, _080D98E4 @ =gInChat
	movs r0, #0
	strb r0, [r1]
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080D98DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D98E4: .4byte gInChat

	thumb_func_start FUN_080d98e8
FUN_080d98e8: @ 0x080D98E8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	ldr r0, _080D9C50 @ =0x00000241
	cmp r1, r0
	bne _080D9930
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D9930
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r2, [r0]
	ldrb r1, [r2, #0x1a]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2, #0x1a]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9C68 @ =0x00000716
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9930:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r2, [r0]
	ldr r1, _080D9C70 @ =0x000002CF
	adds r4, r0, #0
	cmp r2, r1
	bne _080D9972
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D9972
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r2, [r0]
	ldrb r1, [r2, #0x1a]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2, #0x1a]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9C68 @ =0x00000716
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9972:
	ldrh r1, [r4]
	ldr r0, _080D9C74 @ =0x00000247
	cmp r1, r0
	bne _080D99B0
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D99B0
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r2, [r0]
	ldrb r1, [r2, #0x1c]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #0x1c]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D99B0:
	ldrh r1, [r4]
	ldr r0, _080D9C78 @ =0x0000024E
	cmp r1, r0
	bne _080D99EE
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D99EE
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r1, [r0]
	adds r1, #0x2a
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9C7C @ =0x00000792
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D99EE:
	ldrh r1, [r4]
	ldr r0, _080D9C80 @ =0x00000253
	cmp r1, r0
	bne _080D9A2C
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D9A2C
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r1, [r0]
	adds r1, #0x2b
	ldrb r2, [r1]
	movs r0, #4
	orrs r0, r2
	strb r0, [r1]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9C84 @ =0x0000079E
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9A2C:
	ldrh r1, [r4]
	ldr r0, _080D9C88 @ =0x0000025A
	cmp r1, r0
	bne _080D9A60
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r1, [r0]
	adds r1, #0x29
	ldrb r2, [r1]
	movs r0, #4
	orrs r0, r2
	strb r0, [r1]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9C8C @ =0x0000078E
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9A60:
	ldrh r1, [r4]
	ldr r0, _080D9C90 @ =0x0000025D
	cmp r1, r0
	bne _080D9A94
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r2, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #0xa]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	movs r1, #0xd3
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9A94:
	ldrh r1, [r4]
	ldr r0, _080D9C94 @ =0x00000271
	cmp r1, r0
	bne _080D9AD2
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D9AD2
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r1, [r0]
	adds r1, #0x2b
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9C98 @ =0x0000079A
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9AD2:
	ldrh r1, [r4]
	movs r0, #0xa1
	lsls r0, r0, #2
	cmp r1, r0
	bne _080D9B08
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r1, [r0]
	adds r1, #0x2b
	ldrb r2, [r1]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9C9C @ =0x0000079C
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9B08:
	ldrh r1, [r4]
	ldr r0, _080D9CA0 @ =0x000002A6
	cmp r1, r0
	bne _080D9B3A
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r2, [r0]
	ldrb r1, [r2, #0xe]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0xe]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9CA4 @ =0x000006B4
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9B3A:
	ldrh r2, [r4]
	movs r0, #0xb2
	lsls r0, r0, #2
	cmp r2, r0
	bne _080D9B4C
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x20
	str r0, [r1]
_080D9B4C:
	movs r0, #0xb0
	lsls r0, r0, #2
	cmp r2, r0
	bne _080D9B5C
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x34
	str r0, [r1]
_080D9B5C:
	ldr r0, _080D9CAC @ =0x000002C2
	cmp r2, r0
	bne _080D9B6A
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x20
	str r0, [r1]
_080D9B6A:
	movs r0, #0xb1
	lsls r0, r0, #2
	cmp r2, r0
	bne _080D9B7A
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x34
	str r0, [r1]
_080D9B7A:
	ldr r0, _080D9CB0 @ =0x000002C6
	cmp r2, r0
	bne _080D9B88
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x28
	str r0, [r1]
_080D9B88:
	movs r0, #0xaf
	lsls r0, r0, #2
	cmp r2, r0
	bne _080D9B98
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x20
	str r0, [r1]
_080D9B98:
	ldr r0, _080D9CB4 @ =0x000002BE
	cmp r2, r0
	bne _080D9BA6
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x34
	str r0, [r1]
_080D9BA6:
	ldr r0, _080D9CB8 @ =0x000002BA
	cmp r2, r0
	bne _080D9BB4
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x64
	str r0, [r1]
_080D9BB4:
	ldrh r1, [r4]
	ldr r0, _080D9CBC @ =0x000002CA
	cmp r1, r0
	bne _080D9BC4
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x34
	str r0, [r1]
_080D9BC4:
	ldrh r1, [r4]
	ldr r0, _080D9CC0 @ =0x000002B6
	cmp r1, r0
	bne _080D9BE8
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D9BE8
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0xc8
	str r0, [r1]
	ldr r1, _080D9CC4 @ =gCurStory
	adds r1, #0x24
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080D9BE8:
	ldrh r1, [r4]
	movs r0, #0xad
	lsls r0, r0, #2
	cmp r1, r0
	bne _080D9BFA
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x34
	str r0, [r1]
_080D9BFA:
	ldrh r1, [r4]
	ldr r0, _080D9CC8 @ =0x000002B1
	cmp r1, r0
	bne _080D9C36
	ldr r0, _080D9C54 @ =gTextWindow+8
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080D9C36
	ldr r0, _080D9C58 @ =gStageDiskManager
	ldr r2, [r0]
	ldrb r1, [r2, #5]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldr r2, _080D9C5C @ =gTextPrinter
	ldr r0, _080D9C60 @ =0x00000594
	adds r2, r2, r0
	ldr r0, _080D9C64 @ =StringOfsTable
	ldr r1, _080D9CCC @ =0x0000066E
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _080D9C6C @ =gStringData
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x5a
	bl PrintTextWindow
_080D9C36:
	ldrh r1, [r4]
	movs r0, #0xae
	lsls r0, r0, #2
	cmp r1, r0
	bne _080D9C48
	ldr r1, _080D9CA8 @ =gECrystalGainAmount
	ldr r0, [r1]
	adds r0, #0x50
	str r0, [r1]
_080D9C48:
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
	b _080D9CD0
	.align 2, 0
_080D9C50: .4byte 0x00000241
_080D9C54: .4byte gTextWindow+8
_080D9C58: .4byte gStageDiskManager
_080D9C5C: .4byte gTextPrinter
_080D9C60: .4byte 0x00000594
_080D9C64: .4byte StringOfsTable
_080D9C68: .4byte 0x00000716
_080D9C6C: .4byte gStringData
_080D9C70: .4byte 0x000002CF
_080D9C74: .4byte 0x00000247
_080D9C78: .4byte 0x0000024E
_080D9C7C: .4byte 0x00000792
_080D9C80: .4byte 0x00000253
_080D9C84: .4byte 0x0000079E
_080D9C88: .4byte 0x0000025A
_080D9C8C: .4byte 0x0000078E
_080D9C90: .4byte 0x0000025D
_080D9C94: .4byte 0x00000271
_080D9C98: .4byte 0x0000079A
_080D9C9C: .4byte 0x0000079C
_080D9CA0: .4byte 0x000002A6
_080D9CA4: .4byte 0x000006B4
_080D9CA8: .4byte gECrystalGainAmount
_080D9CAC: .4byte 0x000002C2
_080D9CB0: .4byte 0x000002C6
_080D9CB4: .4byte 0x000002BE
_080D9CB8: .4byte 0x000002BA
_080D9CBC: .4byte 0x000002CA
_080D9CC0: .4byte 0x000002B6
_080D9CC4: .4byte gCurStory
_080D9CC8: .4byte 0x000002B1
_080D9CCC: .4byte 0x0000066E
_080D9CD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start andrew_080d9cd8
andrew_080d9cd8: @ 0x080D9CD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080D9D14 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xc]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D9D18
	adds r0, r6, #0
	adds r0, #0xbe
	movs r2, #0
	movs r3, #0
	movs r1, #0xbd
	lsls r1, r1, #8
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r2, [r0]
	adds r0, #4
	strh r3, [r0]
	b _080D9D54
	.align 2, 0
_080D9D14: .4byte gSystemSavedataManager
_080D9D18:
	ldr r2, _080D9D84 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #1
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	subs r1, #9
	movs r0, #1
	strb r0, [r1]
	subs r1, #1
	movs r0, #0x30
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xc0
	strh r0, [r1]
_080D9D54:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D9D88 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #1
	strb r0, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D9D84: .4byte sMotions
_080D9D88: .4byte sCollisions

	thumb_func_start andrew_080d9d8c
andrew_080d9d8c: @ 0x080D9D8C
	push {lr}
	ldr r0, _080D9DB8 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xc]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D9E28
	ldr r2, _080D9DBC @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D9DCC
	ldrb r0, [r2, #0xf]
	cmp r0, #3
	bhi _080D9DC4
	movs r0, #4
	strb r0, [r2, #0xf]
	ldr r0, _080D9DC0 @ =0x000002D1
	b _080D9EAE
	.align 2, 0
_080D9DB8: .4byte gSystemSavedataManager
_080D9DBC: .4byte gCurStory
_080D9DC0: .4byte 0x000002D1
_080D9DC4:
	ldr r0, _080D9DC8 @ =0x000002D2
	b _080D9EAE
	.align 2, 0
_080D9DC8: .4byte 0x000002D2
_080D9DCC:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D9DFC
	ldr r0, _080D9DF0 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #0x1a]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9DF4
	movs r0, #0xb4
	lsls r0, r0, #2
	b _080D9EAE
	.align 2, 0
_080D9DF0: .4byte gStageDiskManager
_080D9DF4:
	ldr r0, _080D9DF8 @ =0x000002CF
	b _080D9EAE
	.align 2, 0
_080D9DF8: .4byte 0x000002CF
_080D9DFC:
	ldrb r0, [r2, #0xf]
	cmp r0, #0
	bne _080D9E0A
	strb r3, [r2, #0xf]
	movs r0, #0xb3
	lsls r0, r0, #2
	b _080D9EAE
_080D9E0A:
	cmp r0, #1
	bne _080D9E1C
	movs r0, #2
	strb r0, [r2, #0xf]
	ldr r0, _080D9E18 @ =0x000002CD
	b _080D9EAE
	.align 2, 0
_080D9E18: .4byte 0x000002CD
_080D9E1C:
	movs r0, #3
	strb r0, [r2, #0xf]
	ldr r0, _080D9E24 @ =0x000002CE
	b _080D9EAE
	.align 2, 0
_080D9E24: .4byte 0x000002CE
_080D9E28:
	ldr r2, _080D9E44 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D9E54
	ldrb r0, [r2, #0xf]
	cmp r0, #3
	bhi _080D9E4C
	movs r0, #4
	strb r0, [r2, #0xf]
	ldr r0, _080D9E48 @ =0x00000242
	b _080D9EAE
	.align 2, 0
_080D9E44: .4byte gCurStory
_080D9E48: .4byte 0x00000242
_080D9E4C:
	ldr r0, _080D9E50 @ =0x00000243
	b _080D9EAE
	.align 2, 0
_080D9E50: .4byte 0x00000243
_080D9E54:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D9E88
	ldr r0, _080D9E78 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #0x1a]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9E80
	ldr r0, _080D9E7C @ =0x000002D3
	b _080D9EAE
	.align 2, 0
_080D9E78: .4byte gStageDiskManager
_080D9E7C: .4byte 0x000002D3
_080D9E80:
	ldr r0, _080D9E84 @ =0x00000241
	b _080D9EAE
	.align 2, 0
_080D9E84: .4byte 0x00000241
_080D9E88:
	ldrb r0, [r2, #0xf]
	cmp r0, #0
	bne _080D9E98
	strb r3, [r2, #0xf]
	ldr r0, _080D9E94 @ =0x0000023D
	b _080D9EAE
	.align 2, 0
_080D9E94: .4byte 0x0000023D
_080D9E98:
	cmp r0, #1
	beq _080D9EA8
	movs r0, #3
	strb r0, [r2, #0xf]
	ldr r0, _080D9EA4 @ =0x0000023F
	b _080D9EAE
	.align 2, 0
_080D9EA4: .4byte 0x0000023F
_080D9EA8:
	movs r0, #2
	strb r0, [r2, #0xf]
	ldr r0, _080D9EB4 @ =0x0000023E
_080D9EAE:
	pop {r1}
	bx r1
	.align 2, 0
_080D9EB4: .4byte 0x0000023E

	thumb_func_start alouette_080d9eb8
alouette_080d9eb8: @ 0x080D9EB8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080D9F00 @ =gSystemSavedataManager
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D9F08
	ldr r2, _080D9F04 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #2
	adds r1, r6, #0
	adds r1, #0xbe
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #3
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #2
	adds r1, #2
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #9
	bl ForceEntityPalette
	b _080D9F3A
	.align 2, 0
_080D9F00: .4byte gSystemSavedataManager
_080D9F04: .4byte sMotions
_080D9F08:
	ldr r2, _080D9F80 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #1
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #7
	bl ForceEntityPalette
_080D9F3A:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D9F84 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb9
	movs r2, #1
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #4
	adds r0, #0xf0
	strh r0, [r1]
	strb r2, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D9F80: .4byte sMotions
_080D9F84: .4byte sCollisions

	thumb_func_start alouette_080d9f88
alouette_080d9f88: @ 0x080D9F88
	push {lr}
	ldr r2, _080D9FA8 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D9FB8
	ldrb r0, [r2, #0x10]
	cmp r0, #3
	bhi _080D9FB0
	movs r0, #4
	strb r0, [r2, #0x10]
	ldr r0, _080D9FAC @ =0x00000249
	b _080DA016
	.align 2, 0
_080D9FA8: .4byte gCurStory
_080D9FAC: .4byte 0x00000249
_080D9FB0:
	ldr r0, _080D9FB4 @ =0x0000024A
	b _080DA016
	.align 2, 0
_080D9FB4: .4byte 0x0000024A
_080D9FB8:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D9FFC
	ldrb r0, [r2, #0x10]
	cmp r0, #2
	bhi _080D9FD4
	movs r0, #3
	strb r0, [r2, #0x10]
	ldr r0, _080D9FD0 @ =0x00000246
	b _080DA016
	.align 2, 0
_080D9FD0: .4byte 0x00000246
_080D9FD4:
	ldr r0, _080D9FF0 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #0x1c]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9FF4
	movs r0, #0x92
	lsls r0, r0, #2
	b _080DA016
	.align 2, 0
_080D9FF0: .4byte gStageDiskManager
_080D9FF4:
	ldr r0, _080D9FF8 @ =0x00000247
	b _080DA016
	.align 2, 0
_080D9FF8: .4byte 0x00000247
_080D9FFC:
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	beq _080DA010
	movs r0, #2
	strb r0, [r2, #0x10]
	ldr r0, _080DA00C @ =0x00000245
	b _080DA016
	.align 2, 0
_080DA00C: .4byte 0x00000245
_080DA010:
	strb r3, [r2, #0x10]
	movs r0, #0x91
	lsls r0, r0, #2
_080DA016:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080da01c
FUN_080da01c: @ 0x080DA01C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r2, _080DA090 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r5, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #1
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA094 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb9
	movs r2, #1
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #0x30
	strb r0, [r1]
	adds r1, #4
	adds r0, #0xd0
	strh r0, [r1]
	strb r2, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA090: .4byte sMotions
_080DA094: .4byte sCollisions

	thumb_func_start hibou_080da098
hibou_080da098: @ 0x080DA098
	push {lr}
	ldr r2, _080DA0B8 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA0C4
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bhi _080DA0BC
	movs r0, #3
	strb r0, [r2, #0x11]
	movs r0, #0x94
	lsls r0, r0, #2
	b _080DA10E
	.align 2, 0
_080DA0B8: .4byte gCurStory
_080DA0BC:
	ldr r0, _080DA0C0 @ =0x00000251
	b _080DA10E
	.align 2, 0
_080DA0C0: .4byte 0x00000251
_080DA0C4:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA0F4
	ldr r0, _080DA0E4 @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA0EC
	ldr r0, _080DA0E8 @ =0x0000024F
	b _080DA10E
	.align 2, 0
_080DA0E4: .4byte gStageDiskManager
_080DA0E8: .4byte 0x0000024F
_080DA0EC:
	ldr r0, _080DA0F0 @ =0x0000024E
	b _080DA10E
	.align 2, 0
_080DA0F0: .4byte 0x0000024E
_080DA0F4:
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	beq _080DA108
	movs r0, #2
	strb r0, [r2, #0x11]
	ldr r0, _080DA104 @ =0x0000024D
	b _080DA10E
	.align 2, 0
_080DA104: .4byte 0x0000024D
_080DA108:
	strb r3, [r2, #0x11]
	movs r0, #0x93
	lsls r0, r0, #2
_080DA10E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080da114
FUN_080da114: @ 0x080DA114
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA184 @ =sCollisions+24
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DA188 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb9
	strb r3, [r0]
	subs r0, #1
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA184: .4byte sCollisions+24
_080DA188: .4byte sMotions

	thumb_func_start menart_080da18c
menart_080da18c: @ 0x080DA18C
	push {lr}
	ldr r2, _080DA1AC @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA1BA
	ldrb r0, [r2, #0x12]
	cmp r0, #2
	bhi _080DA1B4
	movs r0, #3
	strb r0, [r2, #0x12]
	ldr r0, _080DA1B0 @ =0x00000257
	b _080DA218
	.align 2, 0
_080DA1AC: .4byte gCurStory
_080DA1B0: .4byte 0x00000257
_080DA1B4:
	movs r0, #0x96
	lsls r0, r0, #2
	b _080DA218
_080DA1BA:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA1E0
	ldrb r0, [r2, #0x12]
	cmp r0, #1
	bhi _080DA1D8
	movs r0, #2
	strb r0, [r2, #0x12]
	ldr r0, _080DA1D4 @ =0x00000255
	b _080DA218
	.align 2, 0
_080DA1D4: .4byte 0x00000255
_080DA1D8:
	ldr r0, _080DA1DC @ =0x00000256
	b _080DA218
	.align 2, 0
_080DA1DC: .4byte 0x00000256
_080DA1E0:
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	bne _080DA1F0
	strb r3, [r2, #0x12]
	ldr r0, _080DA1EC @ =0x00000252
	b _080DA218
	.align 2, 0
_080DA1EC: .4byte 0x00000252
_080DA1F0:
	ldr r0, _080DA20C @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080DA214
	ldr r0, _080DA210 @ =0x00000253
	b _080DA218
	.align 2, 0
_080DA20C: .4byte gStageDiskManager
_080DA210: .4byte 0x00000253
_080DA214:
	movs r0, #0x95
	lsls r0, r0, #2
_080DA218:
	pop {r1}
	bx r1

	thumb_func_start FUN_080da21c
FUN_080da21c: @ 0x080DA21C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA28C @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DA290 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	subs r1, #9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA28C: .4byte sCollisions
_080DA290: .4byte sMotions

	thumb_func_start rocinolle_080da294
rocinolle_080da294: @ 0x080DA294
	push {r4, lr}
	ldr r2, _080DA2B8 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r4, #1
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA2E4
	ldrb r0, [r2, #0x18]
	cmp r0, #1
	bhi _080DA2BC
	movs r0, #2
	strb r0, [r2, #0x18]
	movs r0, #0x97
	lsls r0, r0, #2
	b _080DA316
	.align 2, 0
_080DA2B8: .4byte gCurStory
_080DA2BC:
	ldr r0, _080DA2D4 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #3
	ands r0, r4
	cmp r0, #0
	beq _080DA2DC
	ldr r0, _080DA2D8 @ =0x0000025E
	b _080DA316
	.align 2, 0
_080DA2D4: .4byte gStageDiskManager
_080DA2D8: .4byte 0x0000025E
_080DA2DC:
	ldr r0, _080DA2E0 @ =0x0000025D
	b _080DA316
	.align 2, 0
_080DA2E0: .4byte 0x0000025D
_080DA2E4:
	ldrb r0, [r2, #0x18]
	cmp r0, #0
	bne _080DA2F4
	strb r3, [r2, #0x18]
	ldr r0, _080DA2F0 @ =0x00000259
	b _080DA316
	.align 2, 0
_080DA2F0: .4byte 0x00000259
_080DA2F4:
	ldr r0, _080DA30C @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	ands r0, r4
	cmp r0, #0
	bne _080DA314
	ldr r0, _080DA310 @ =0x0000025A
	b _080DA316
	.align 2, 0
_080DA30C: .4byte gStageDiskManager
_080DA310: .4byte 0x0000025A
_080DA314:
	ldr r0, _080DA31C @ =0x0000025B
_080DA316:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DA31C: .4byte 0x0000025B

	thumb_func_start FUN_080da320
FUN_080da320: @ 0x080DA320
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA390 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DA394 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	subs r1, #9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA390: .4byte sCollisions
_080DA394: .4byte sMotions

	thumb_func_start hirondelle_080da398
hirondelle_080da398: @ 0x080DA398
	push {lr}
	ldr r2, _080DA3BC @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA3D0
	ldr r0, _080DA3C0 @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA3C8
	ldr r0, _080DA3C4 @ =0x00000272
	b _080DA416
	.align 2, 0
_080DA3BC: .4byte gCurStory
_080DA3C0: .4byte gStageDiskManager
_080DA3C4: .4byte 0x00000272
_080DA3C8:
	ldr r0, _080DA3CC @ =0x00000271
	b _080DA416
	.align 2, 0
_080DA3CC: .4byte 0x00000271
_080DA3D0:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA402
	ldrb r0, [r2, #0x13]
	cmp r0, #1
	bhi _080DA3EC
	movs r0, #2
	strb r0, [r2, #0x13]
	ldr r0, _080DA3E8 @ =0x0000026E
	b _080DA416
	.align 2, 0
_080DA3E8: .4byte 0x0000026E
_080DA3EC:
	cmp r0, #2
	bhi _080DA3FC
	movs r0, #3
	strb r0, [r2, #0x13]
	ldr r0, _080DA3F8 @ =0x0000026F
	b _080DA416
	.align 2, 0
_080DA3F8: .4byte 0x0000026F
_080DA3FC:
	movs r0, #0x9c
	lsls r0, r0, #2
	b _080DA416
_080DA402:
	ldrb r0, [r2, #0x13]
	cmp r0, #0
	beq _080DA410
	ldr r0, _080DA40C @ =0x0000026D
	b _080DA416
	.align 2, 0
_080DA40C: .4byte 0x0000026D
_080DA410:
	strb r3, [r2, #0x13]
	movs r0, #0x9b
	lsls r0, r0, #2
_080DA416:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080da41c
FUN_080da41c: @ 0x080DA41C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA48C @ =sCollisions+24
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DA490 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb9
	strb r3, [r0]
	subs r0, #1
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA48C: .4byte sCollisions+24
_080DA490: .4byte sMotions

	thumb_func_start pic_080da494
pic_080da494: @ 0x080DA494
	push {lr}
	ldr r2, _080DA4B4 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA4C2
	ldrb r0, [r2, #0x14]
	cmp r0, #2
	bhi _080DA4BC
	movs r0, #3
	strb r0, [r2, #0x14]
	ldr r0, _080DA4B8 @ =0x00000277
	b _080DA4F8
	.align 2, 0
_080DA4B4: .4byte gCurStory
_080DA4B8: .4byte 0x00000277
_080DA4BC:
	movs r0, #0x9e
	lsls r0, r0, #2
	b _080DA4F8
_080DA4C2:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA4E8
	ldrb r0, [r2, #0x14]
	cmp r0, #1
	bhi _080DA4E0
	movs r0, #2
	strb r0, [r2, #0x14]
	ldr r0, _080DA4DC @ =0x00000275
	b _080DA4F8
	.align 2, 0
_080DA4DC: .4byte 0x00000275
_080DA4E0:
	ldr r0, _080DA4E4 @ =0x00000276
	b _080DA4F8
	.align 2, 0
_080DA4E4: .4byte 0x00000276
_080DA4E8:
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	beq _080DA4F4
	movs r0, #0x9d
	lsls r0, r0, #2
	b _080DA4F8
_080DA4F4:
	strb r3, [r2, #0x14]
	ldr r0, _080DA4FC @ =0x00000273
_080DA4F8:
	pop {r1}
	bx r1
	.align 2, 0
_080DA4FC: .4byte 0x00000273

	thumb_func_start FUN_080da500
FUN_080da500: @ 0x080DA500
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r2, _080DA574 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r5, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #1
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA578 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb9
	movs r2, #1
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #0x30
	strb r0, [r1]
	adds r1, #4
	adds r0, #0xd0
	strh r0, [r1]
	strb r2, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA574: .4byte sMotions
_080DA578: .4byte sCollisions

	thumb_func_start perroquiet_080da57c
perroquiet_080da57c: @ 0x080DA57C
	push {lr}
	ldr r2, _080DA59C @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA5AC
	ldrb r0, [r2, #0x15]
	cmp r0, #2
	bhi _080DA5A4
	movs r0, #3
	strb r0, [r2, #0x15]
	ldr r0, _080DA5A0 @ =0x0000027D
	b _080DA5E0
	.align 2, 0
_080DA59C: .4byte gCurStory
_080DA5A0: .4byte 0x0000027D
_080DA5A4:
	ldr r0, _080DA5A8 @ =0x0000027E
	b _080DA5E0
	.align 2, 0
_080DA5A8: .4byte 0x0000027E
_080DA5AC:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA5CE
	ldrb r0, [r2, #0x15]
	cmp r0, #1
	bhi _080DA5C8
	movs r0, #2
	strb r0, [r2, #0x15]
	ldr r0, _080DA5C4 @ =0x0000027B
	b _080DA5E0
	.align 2, 0
_080DA5C4: .4byte 0x0000027B
_080DA5C8:
	movs r0, #0x9f
	lsls r0, r0, #2
	b _080DA5E0
_080DA5CE:
	ldrb r0, [r2, #0x15]
	cmp r0, #0
	beq _080DA5DC
	ldr r0, _080DA5D8 @ =0x0000027A
	b _080DA5E0
	.align 2, 0
_080DA5D8: .4byte 0x0000027A
_080DA5DC:
	strb r3, [r2, #0x15]
	ldr r0, _080DA5E4 @ =0x00000279
_080DA5E0:
	pop {r1}
	bx r1
	.align 2, 0
_080DA5E4: .4byte 0x00000279

	thumb_func_start FUN_080da5e8
FUN_080da5e8: @ 0x080DA5E8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA658 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DA65C @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	subs r1, #9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA658: .4byte sCollisions
_080DA65C: .4byte sMotions

	thumb_func_start doigt_080da660
doigt_080da660: @ 0x080DA660
	push {lr}
	ldr r2, _080DA680 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA6B2
	ldrb r0, [r2, #0x16]
	cmp r0, #2
	bhi _080DA688
	movs r0, #3
	strb r0, [r2, #0x16]
	ldr r0, _080DA684 @ =0x00000283
	b _080DA6E8
	.align 2, 0
_080DA680: .4byte gCurStory
_080DA684: .4byte 0x00000283
_080DA688:
	ldr r0, _080DA6A4 @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA6AC
	ldr r0, _080DA6A8 @ =0x00000285
	b _080DA6E8
	.align 2, 0
_080DA6A4: .4byte gStageDiskManager
_080DA6A8: .4byte 0x00000285
_080DA6AC:
	movs r0, #0xa1
	lsls r0, r0, #2
	b _080DA6E8
_080DA6B2:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA6D8
	ldrb r0, [r2, #0x16]
	cmp r0, #1
	bhi _080DA6D0
	movs r0, #2
	strb r0, [r2, #0x16]
	ldr r0, _080DA6CC @ =0x00000281
	b _080DA6E8
	.align 2, 0
_080DA6CC: .4byte 0x00000281
_080DA6D0:
	ldr r0, _080DA6D4 @ =0x00000282
	b _080DA6E8
	.align 2, 0
_080DA6D4: .4byte 0x00000282
_080DA6D8:
	ldrb r0, [r2, #0x16]
	cmp r0, #0
	beq _080DA6E4
	movs r0, #0xa0
	lsls r0, r0, #2
	b _080DA6E8
_080DA6E4:
	strb r3, [r2, #0x16]
	ldr r0, _080DA6EC @ =0x0000027F
_080DA6E8:
	pop {r1}
	bx r1
	.align 2, 0
_080DA6EC: .4byte 0x0000027F

	thumb_func_start FUN_080da6f0
FUN_080da6f0: @ 0x080DA6F0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA760 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DA764 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	subs r1, #9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA760: .4byte sCollisions
_080DA764: .4byte sMotions

	thumb_func_start autruche_080da768
autruche_080da768: @ 0x080DA768
	push {lr}
	ldr r2, _080DA788 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA798
	ldrb r0, [r2, #0x17]
	cmp r0, #2
	bhi _080DA790
	movs r0, #3
	strb r0, [r2, #0x17]
	ldr r0, _080DA78C @ =0x0000028A
	b _080DA7D0
	.align 2, 0
_080DA788: .4byte gCurStory
_080DA78C: .4byte 0x0000028A
_080DA790:
	ldr r0, _080DA794 @ =0x0000028B
	b _080DA7D0
	.align 2, 0
_080DA794: .4byte 0x0000028B
_080DA798:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA7BC
	ldrb r0, [r2, #0x17]
	cmp r0, #1
	bhi _080DA7B2
	movs r0, #2
	strb r0, [r2, #0x17]
	movs r0, #0xa2
	lsls r0, r0, #2
	b _080DA7D0
_080DA7B2:
	ldr r0, _080DA7B8 @ =0x00000289
	b _080DA7D0
	.align 2, 0
_080DA7B8: .4byte 0x00000289
_080DA7BC:
	ldrb r0, [r2, #0x17]
	cmp r0, #0
	beq _080DA7CC
	ldr r0, _080DA7C8 @ =0x00000287
	b _080DA7D0
	.align 2, 0
_080DA7C8: .4byte 0x00000287
_080DA7CC:
	strb r3, [r2, #0x17]
	ldr r0, _080DA7D4 @ =0x00000286
_080DA7D0:
	pop {r1}
	bx r1
	.align 2, 0
_080DA7D4: .4byte 0x00000286

	thumb_func_start extraNPC_080da7d8
extraNPC_080da7d8: @ 0x080DA7D8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x10]
	subs r0, #0xc
	cmp r0, #8
	bls _080DA7E6
	b _080DA8C8
_080DA7E6:
	lsls r0, r0, #2
	ldr r1, _080DA7F0 @ =_080DA7F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA7F0: .4byte _080DA7F4
_080DA7F4: @ jump table
	.4byte _080DA818 @ case 0
	.4byte _080DA824 @ case 1
	.4byte _080DA830 @ case 2
	.4byte _080DA83C @ case 3
	.4byte _080DA848 @ case 4
	.4byte _080DA854 @ case 5
	.4byte _080DA860 @ case 6
	.4byte _080DA86C @ case 7
	.4byte _080DA878 @ case 8
_080DA818:
	ldr r0, _080DA820 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x12]
	movs r0, #0x10
	b _080DA87E
	.align 2, 0
_080DA820: .4byte gSystemSavedataManager
_080DA824:
	ldr r0, _080DA82C @ =gSystemSavedataManager
	ldrb r1, [r0, #0xe]
	movs r0, #0x80
	b _080DA87E
	.align 2, 0
_080DA82C: .4byte gSystemSavedataManager
_080DA830:
	ldr r0, _080DA838 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x11]
	movs r0, #0x40
	b _080DA87E
	.align 2, 0
_080DA838: .4byte gSystemSavedataManager
_080DA83C:
	ldr r0, _080DA844 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x11]
	movs r0, #0x80
	b _080DA87E
	.align 2, 0
_080DA844: .4byte gSystemSavedataManager
_080DA848:
	ldr r0, _080DA850 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x12]
	movs r0, #4
	b _080DA87E
	.align 2, 0
_080DA850: .4byte gSystemSavedataManager
_080DA854:
	ldr r0, _080DA85C @ =gSystemSavedataManager
	ldrb r1, [r0, #0xe]
	movs r0, #0x10
	b _080DA87E
	.align 2, 0
_080DA85C: .4byte gSystemSavedataManager
_080DA860:
	ldr r0, _080DA868 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xe]
	movs r0, #0x40
	b _080DA87E
	.align 2, 0
_080DA868: .4byte gSystemSavedataManager
_080DA86C:
	ldr r0, _080DA874 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xd]
	movs r0, #0x40
	b _080DA87E
	.align 2, 0
_080DA874: .4byte gSystemSavedataManager
_080DA878:
	ldr r0, _080DA8C0 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x12]
	movs r0, #0x20
_080DA87E:
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080DA8C8
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080DA8C4 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080DA92E
	.align 2, 0
_080DA8C0: .4byte gSystemSavedataManager
_080DA8C4: .4byte gSolidFnTable
_080DA8C8:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DA934 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DA938 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	subs r1, #9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
_080DA92E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DA934: .4byte sCollisions
_080DA938: .4byte sMotions

	thumb_func_start faucon_080da93c
faucon_080da93c: @ 0x080DA93C
	push {lr}
	ldrb r0, [r0, #0x10]
	subs r0, #0xa
	cmp r0, #0xa
	bls _080DA948
	b _080DAB34
_080DA948:
	lsls r0, r0, #2
	ldr r1, _080DA954 @ =_080DA958
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA954: .4byte _080DA958
_080DA958: @ jump table
	.4byte _080DA984 @ case 0
	.4byte _080DA9AE @ case 1
	.4byte _080DAA04 @ case 2
	.4byte _080DAA24 @ case 3
	.4byte _080DAA44 @ case 4
	.4byte _080DAA64 @ case 5
	.4byte _080DAA84 @ case 6
	.4byte _080DAAA4 @ case 7
	.4byte _080DAAC8 @ case 8
	.4byte _080DAAEC @ case 9
	.4byte _080DAB10 @ case 10
_080DA984:
	ldr r2, _080DA994 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA99C
	ldr r0, _080DA998 @ =0x000002A2
	b _080DAB36
	.align 2, 0
_080DA994: .4byte gCurStory
_080DA998: .4byte 0x000002A2
_080DA99C:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080DA9A8
	b _080DAB34
_080DA9A8:
	movs r0, #0xa8
	lsls r0, r0, #2
	b _080DAB36
_080DA9AE:
	ldr r2, _080DA9C0 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA9C8
	ldr r0, _080DA9C4 @ =0x000002AB
	b _080DAB36
	.align 2, 0
_080DA9C0: .4byte gCurStory
_080DA9C4: .4byte 0x000002AB
_080DA9C8:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA9DC
	ldr r0, _080DA9D8 @ =0x000002A9
	b _080DAB36
	.align 2, 0
_080DA9D8: .4byte 0x000002A9
_080DA9DC:
	ldr r0, _080DA9F4 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #0xe]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA9FC
	ldr r0, _080DA9F8 @ =0x000002A7
	b _080DAB36
	.align 2, 0
_080DA9F4: .4byte gStageDiskManager
_080DA9F8: .4byte 0x000002A7
_080DA9FC:
	ldr r0, _080DAA00 @ =0x000002A6
	b _080DAB36
	.align 2, 0
_080DAA00: .4byte 0x000002A6
_080DAA04:
	ldr r1, _080DAA18 @ =gCurStory
	ldrb r0, [r1, #0x1b]
	cmp r0, #0
	bne _080DAA1C
	adds r0, #1
	strb r0, [r1, #0x1b]
	movs r0, #0xb2
	lsls r0, r0, #2
	b _080DAB36
	.align 2, 0
_080DAA18: .4byte gCurStory
_080DAA1C:
	ldr r0, _080DAA20 @ =0x000002C9
	b _080DAB36
	.align 2, 0
_080DAA20: .4byte 0x000002C9
_080DAA24:
	ldr r1, _080DAA38 @ =gCurStory
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _080DAA3C
	adds r0, #1
	strb r0, [r1, #0x1c]
	movs r0, #0xb0
	lsls r0, r0, #2
	b _080DAB36
	.align 2, 0
_080DAA38: .4byte gCurStory
_080DAA3C:
	ldr r0, _080DAA40 @ =0x000002C1
	b _080DAB36
	.align 2, 0
_080DAA40: .4byte 0x000002C1
_080DAA44:
	ldr r1, _080DAA54 @ =gCurStory
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	bne _080DAA5C
	adds r0, #1
	strb r0, [r1, #0x1d]
	ldr r0, _080DAA58 @ =0x000002C2
	b _080DAB36
	.align 2, 0
_080DAA54: .4byte gCurStory
_080DAA58: .4byte 0x000002C2
_080DAA5C:
	ldr r0, _080DAA60 @ =0x000002C3
	b _080DAB36
	.align 2, 0
_080DAA60: .4byte 0x000002C3
_080DAA64:
	ldr r1, _080DAA78 @ =gCurStory
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _080DAA7C
	adds r0, #1
	strb r0, [r1, #0x1e]
	movs r0, #0xb1
	lsls r0, r0, #2
	b _080DAB36
	.align 2, 0
_080DAA78: .4byte gCurStory
_080DAA7C:
	ldr r0, _080DAA80 @ =0x000002C5
	b _080DAB36
	.align 2, 0
_080DAA80: .4byte 0x000002C5
_080DAA84:
	ldr r1, _080DAA94 @ =gCurStory
	ldrb r0, [r1, #0x1f]
	cmp r0, #0
	bne _080DAA9C
	adds r0, #1
	strb r0, [r1, #0x1f]
	ldr r0, _080DAA98 @ =0x000002C6
	b _080DAB36
	.align 2, 0
_080DAA94: .4byte gCurStory
_080DAA98: .4byte 0x000002C6
_080DAA9C:
	ldr r0, _080DAAA0 @ =0x000002C7
	b _080DAB36
	.align 2, 0
_080DAAA0: .4byte 0x000002C7
_080DAAA4:
	ldr r0, _080DAABC @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DAAC0
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #2
	b _080DAB36
	.align 2, 0
_080DAABC: .4byte gCurStory
_080DAAC0:
	ldr r0, _080DAAC4 @ =0x000002BD
	b _080DAB36
	.align 2, 0
_080DAAC4: .4byte 0x000002BD
_080DAAC8:
	ldr r0, _080DAADC @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x21
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DAAE4
	adds r0, #1
	strb r0, [r1]
	ldr r0, _080DAAE0 @ =0x000002BE
	b _080DAB36
	.align 2, 0
_080DAADC: .4byte gCurStory
_080DAAE0: .4byte 0x000002BE
_080DAAE4:
	ldr r0, _080DAAE8 @ =0x000002BF
	b _080DAB36
	.align 2, 0
_080DAAE8: .4byte 0x000002BF
_080DAAEC:
	ldr r0, _080DAB00 @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DAB08
	adds r0, #1
	strb r0, [r1]
	ldr r0, _080DAB04 @ =0x000002BA
	b _080DAB36
	.align 2, 0
_080DAB00: .4byte gCurStory
_080DAB04: .4byte 0x000002BA
_080DAB08:
	ldr r0, _080DAB0C @ =0x000002BB
	b _080DAB36
	.align 2, 0
_080DAB0C: .4byte 0x000002BB
_080DAB10:
	ldr r0, _080DAB24 @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x23
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DAB2C
	adds r0, #1
	strb r0, [r1]
	ldr r0, _080DAB28 @ =0x000002CA
	b _080DAB36
	.align 2, 0
_080DAB24: .4byte gCurStory
_080DAB28: .4byte 0x000002CA
_080DAB2C:
	ldr r0, _080DAB30 @ =0x000002CB
	b _080DAB36
	.align 2, 0
_080DAB30: .4byte 0x000002CB
_080DAB34:
	ldr r0, _080DAB3C @ =0x0000029E
_080DAB36:
	pop {r1}
	bx r1
	.align 2, 0
_080DAB3C: .4byte 0x0000029E

	thumb_func_start FUN_080dab40
FUN_080dab40: @ 0x080DAB40
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _080DAB88 @ =gSystemSavedataManager
	ldrb r0, [r0, #0xa]
	movs r7, #1
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0
	bne _080DAB90
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080DAB8C @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080DABF4
	.align 2, 0
_080DAB88: .4byte gSystemSavedataManager
_080DAB8C: .4byte gSolidFnTable
_080DAB90:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DABFC @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080DAC00 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r3, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb9
	strb r7, [r0]
	subs r0, #1
	strb r3, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r3, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
_080DABF4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DABFC: .4byte sCollisions
_080DAC00: .4byte sMotions

	thumb_func_start kiss_080dac04
kiss_080dac04: @ 0x080DAC04
	push {lr}
	ldr r0, _080DAC14 @ =gCurStory
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DAC1C
	ldr r0, _080DAC18 @ =0x000002B7
	b _080DAC1E
	.align 2, 0
_080DAC14: .4byte gCurStory
_080DAC18: .4byte 0x000002B7
_080DAC1C:
	ldr r0, _080DAC24 @ =0x000002B6
_080DAC1E:
	pop {r1}
	bx r1
	.align 2, 0
_080DAC24: .4byte 0x000002B6

	thumb_func_start FUN_080dac28
FUN_080dac28: @ 0x080DAC28
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x10]
	cmp r0, #0x16
	bne _080DAC42
	ldr r0, _080DAC90 @ =gSystemSavedataManager
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080DAC58
_080DAC42:
	ldrb r0, [r6, #0x10]
	cmp r0, #0x19
	bne _080DAC98
	ldr r0, _080DAC90 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xb]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080DAC98
_080DAC58:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080DAC94 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080DAD00
	.align 2, 0
_080DAC90: .4byte gSystemSavedataManager
_080DAC94: .4byte gSolidFnTable
_080DAC98:
	ldr r2, _080DAD08 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r5, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #2
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DAD0C @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb9
	movs r2, #1
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #0x30
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xc0
	strh r0, [r1]
	strb r2, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
_080DAD00:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAD08: .4byte sMotions
_080DAD0C: .4byte sCollisions

	thumb_func_start colbor_080dad10
colbor_080dad10: @ 0x080DAD10
	push {lr}
	ldrb r0, [r0, #0x10]
	cmp r0, #0x17
	beq _080DAD50
	cmp r0, #0x17
	bgt _080DAD22
	cmp r0, #0x16
	beq _080DAD2C
	b _080DADF0
_080DAD22:
	cmp r0, #0x18
	beq _080DAD7C
	cmp r0, #0x19
	beq _080DADCE
	b _080DADF0
_080DAD2C:
	ldr r0, _080DAD44 @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DAD48
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xad
	lsls r0, r0, #2
	b _080DADF2
	.align 2, 0
_080DAD44: .4byte gCurStory
_080DAD48:
	ldr r0, _080DAD4C @ =0x000002B5
	b _080DADF2
	.align 2, 0
_080DAD4C: .4byte 0x000002B5
_080DAD50:
	ldr r2, _080DAD60 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DAD68
	ldr r0, _080DAD64 @ =0x000002AF
	b _080DADF2
	.align 2, 0
_080DAD60: .4byte gCurStory
_080DAD64: .4byte 0x000002AF
_080DAD68:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DADF0
	ldr r0, _080DAD78 @ =0x000002AE
	b _080DADF2
	.align 2, 0
_080DAD78: .4byte 0x000002AE
_080DAD7C:
	ldr r2, _080DAD8C @ =gCurStory
	ldrb r1, [r2, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DAD94
	ldr r0, _080DAD90 @ =0x000002B3
	b _080DADF2
	.align 2, 0
_080DAD8C: .4byte gCurStory
_080DAD90: .4byte 0x000002B3
_080DAD94:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DADC8
	ldr r0, _080DADB8 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #5]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DADC0
	ldr r0, _080DADBC @ =0x000002B2
	b _080DADF2
	.align 2, 0
_080DADB8: .4byte gStageDiskManager
_080DADBC: .4byte 0x000002B2
_080DADC0:
	ldr r0, _080DADC4 @ =0x000002B1
	b _080DADF2
	.align 2, 0
_080DADC4: .4byte 0x000002B1
_080DADC8:
	movs r0, #0xac
	lsls r0, r0, #2
	b _080DADF2
_080DADCE:
	ldr r0, _080DADE4 @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DADE8
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #2
	b _080DADF2
	.align 2, 0
_080DADE4: .4byte gCurStory
_080DADE8:
	ldr r0, _080DADEC @ =0x000002B9
	b _080DADF2
	.align 2, 0
_080DADEC: .4byte 0x000002B9
_080DADF0:
	ldr r0, _080DADF8 @ =0x000002AD
_080DADF2:
	pop {r1}
	bx r1
	.align 2, 0
_080DADF8: .4byte 0x000002AD

	thumb_func_start FUN_080dadfc
FUN_080dadfc: @ 0x080DADFC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r2, _080DAE70 @ =sMotions
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0xbe
	movs r6, #0
	movs r5, #0
	strh r0, [r1]
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0xc2
	strh r0, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080DAE74 @ =sCollisions+48
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r7, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb8
	strb r6, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r6, [r7, #0xd]
	adds r0, r7, #0
	bl MobNPC_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DAE70: .4byte sMotions
_080DAE74: .4byte sCollisions+48

	thumb_func_start getCielComputerResearchTextID
getCielComputerResearchTextID: @ 0x080DAE78
	movs r0, #0xa3
	lsls r0, r0, #2
	bx lr
	.align 2, 0
