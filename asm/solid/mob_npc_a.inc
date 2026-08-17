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
	bl UpdateEntityAnim
	ldr r0, _080D9870 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080D98DE
	ldr r2, _080D9874 @ =gSystemSavedata
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
_080D9874: .4byte gSystemSavedata
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
	bl UpdateEntityAnim
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
	ldr r0, _080D9D14 @ =gSystemSavedata
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
_080D9D14: .4byte gSystemSavedata
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
	ldr r0, _080D9DB8 @ =gSystemSavedata
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
_080D9DB8: .4byte gSystemSavedata
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
	ldr r0, _080D9F00 @ =gSystemSavedata
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
	bl _ForceEntityPalette
	b _080D9F3A
	.align 2, 0
_080D9F00: .4byte gSystemSavedata
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
	bl _ForceEntityPalette
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
