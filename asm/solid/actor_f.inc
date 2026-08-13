	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080d6afc
FUN_080d6afc: @ 0x080D6AFC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D6B7E
	cmp r0, #1
	bgt _080D6B10
	cmp r0, #0
	beq _080D6B16
	b _080D6C48
_080D6B10:
	cmp r0, #2
	beq _080D6BD8
	b _080D6C48
_080D6B16:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D6BC0 @ =wStaticGraphicTilenums
	adds r1, #0xa2
	movs r6, #0
	ldr r0, _080D6BC4 @ =0x000002BE
	strh r0, [r1]
	ldr r5, _080D6BC8 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #6
	strh r0, [r5]
	ldr r4, _080D6BCC @ =0x00000654
	ldr r2, _080D6BD0 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D6BD4 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	bl InitScalerotMotion1
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	movs r0, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6B7E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D6B9E
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #3
	movs r1, #0
	bl FUN_080c5628
_080D6B9E:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6BB0
	ldr r0, [r7, #0x5c]
	adds r0, #0x60
	str r0, [r7, #0x5c]
_080D6BB0:
	ldrb r1, [r2, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6C48
	movs r0, #0
	strb r0, [r7, #0x13]
	b _080D6C42
	.align 2, 0
_080D6BC0: .4byte wStaticGraphicTilenums
_080D6BC4: .4byte 0x000002BE
_080D6BC8: .4byte wStaticMotionPalIDs
_080D6BCC: .4byte 0x00000654
_080D6BD0: .4byte gStaticMotionGraphics
_080D6BD4: .4byte gStaticMotionGraphics+12
_080D6BD8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	adds r0, #0x80
	str r0, [r7, #0x5c]
	ldrb r0, [r7, #0x13]
	adds r1, r0, #1
	strb r1, [r7, #0x13]
	ldr r3, _080D6C7C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	movs r1, #0x90
	lsls r1, r1, #1
	cmp r0, r1
	bls _080D6C12
	adds r2, r1, #0
_080D6C12:
	adds r0, r7, #0
	adds r0, #0x50
	strh r2, [r0]
	ldrb r0, [r7, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r7, #0x13]
	cmp r0, #0x50
	bls _080D6C48
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D6C42:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6C48:
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r3, _080D6C7C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D6C7C: .4byte gSineTable

	thumb_func_start FUN_080d6c80
FUN_080d6c80: @ 0x080D6C80
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xc
	bls _080D6C8C
	b _080D6F5E
_080D6C8C:
	lsls r0, r0, #2
	ldr r1, _080D6C98 @ =_080D6C9C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D6C98: .4byte _080D6C9C
_080D6C9C: @ jump table
	.4byte _080D6CD0 @ case 0
	.4byte _080D6CEC @ case 1
	.4byte _080D6D04 @ case 2
	.4byte _080D6D2C @ case 3
	.4byte _080D6D64 @ case 4
	.4byte _080D6D8C @ case 5
	.4byte _080D6DD8 @ case 6
	.4byte _080D6E00 @ case 7
	.4byte _080D6E2C @ case 8
	.4byte _080D6E74 @ case 9
	.4byte _080D6F38 @ case 10
	.4byte _080D6F48 @ case 11
	.4byte _080D6F5E @ case 12
_080D6CD0:
	ldr r0, _080D6CFC @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xf0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D6D00 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D6CEC:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	b _080D6F52
	.align 2, 0
_080D6CFC: .4byte wDynamicGraphicTilenums
_080D6D00: .4byte wDynamicMotionPalIDs
_080D6D04:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D6D18
	b _080D6F5E
_080D6D18:
	ldr r1, _080D6D28 @ =0x0000BE01
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D6F58
	.align 2, 0
_080D6D28: .4byte 0x0000BE01
_080D6D2C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D6D44
	ldr r0, _080D6D5C @ =0x00000101
	bl PlaySound
_080D6D44:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6D50
	b _080D6F5E
_080D6D50:
	ldr r1, _080D6D60 @ =0x0000BE02
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6D5C: .4byte 0x00000101
_080D6D60: .4byte 0x0000BE02
_080D6D64:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6D76
	b _080D6F5E
_080D6D76:
	ldr r1, _080D6D88 @ =0x0000BE03
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r6, #0x12]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	b _080D6F58
	.align 2, 0
_080D6D88: .4byte 0x0000BE03
_080D6D8C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, _080D6DD0 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r6, #0x68]
	subs r1, r1, r0
	str r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r0, r0, #3
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080D6DC0
	b _080D6F5E
_080D6DC0:
	ldr r1, _080D6DD4 @ =0x0000BE11
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x60]
	b _080D6F58
	.align 2, 0
_080D6DD0: .4byte gSineTable
_080D6DD4: .4byte 0x0000BE11
_080D6DD8:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6DEA
	b _080D6F5E
_080D6DEA:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound
	ldr r1, _080D6DFC @ =0x0000BE12
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6DFC: .4byte 0x0000BE12
_080D6E00:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D6E14
	b _080D6F5E
_080D6E14:
	movs r0, #0x92
	lsls r0, r0, #1
	bl StopSound
	ldr r1, _080D6E28 @ =0x0000BE13
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6E28: .4byte 0x0000BE13
_080D6E2C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6E3E
	b _080D6F5E
_080D6E3E:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D6E6C @ =0x08370DD0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080D6E70 @ =0x0000BE03
	adds r0, r6, #0
	bl SetMotion
	str r5, [r6, #0x5c]
	strb r5, [r6, #0x13]
	b _080D6F58
	.align 2, 0
_080D6E6C: .4byte sCollisions_08370C68+(24*15)
_080D6E70: .4byte 0x0000BE03
_080D6E74:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	beq _080D6EAA
	adds r0, #0x20
	str r0, [r6, #0x5c]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080D6E8E
	str r1, [r6, #0x5c]
_080D6E8E:
	ldr r1, [r6, #0x60]
	ldr r0, [r6, #0x5c]
	adds r1, r1, r0
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x54]
	bl PushoutToUp1
	cmp r0, #0
	beq _080D6EAA
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x60]
	bl FUN_08009f6c
	str r0, [r6, #0x60]
_080D6EAA:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080D6ED8
	subs r0, #1
	strb r0, [r6, #0x13]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6EC4
	adds r0, r6, #0
	bl PaintEntityWhite
	b _080D6ECA
_080D6EC4:
	adds r0, r6, #0
	bl UpdateEntityPaletteID
_080D6ECA:
	ldrb r0, [r6, #0x13]
	cmp r0, #0x16
	bne _080D6ED8
	ldr r1, _080D6EF8 @ =0x0000BE0D
	adds r0, r6, #0
	bl SetMotion
_080D6ED8:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D6F00
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x60]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldr r1, _080D6EFC @ =0x0000BE0E
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6EF8: .4byte 0x0000BE0D
_080D6EFC: .4byte 0x0000BE0E
_080D6F00:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6F5E
	ldr r1, _080D6F34 @ =0x0000BE0C
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x13]
	ldr r0, [r6, #0x5c]
	adds r0, #1
	str r0, [r6, #0x5c]
	movs r0, #0xf8
	bl isSoundPlaying
	cmp r0, #0
	bne _080D6F5E
	movs r0, #0xf8
	bl PlaySound
	b _080D6F5E
	.align 2, 0
_080D6F34: .4byte 0x0000BE0C
_080D6F38:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	b _080D6F54
_080D6F48:
	ldr r1, _080D6F98 @ =0x0000BE0B
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0934
_080D6F52:
	lsls r0, r0, #0x10
_080D6F54:
	cmp r0, #0
	beq _080D6F5E
_080D6F58:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D6F5E:
	ldrb r0, [r6, #0xd]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080D6F90
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r1, _080D6F9C @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r0, r0, #3
	str r0, [r6, #0x58]
_080D6F90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D6F98: .4byte 0x0000BE0B
_080D6F9C: .4byte gSineTable

	thumb_func_start FUN_080d6fa0
FUN_080d6fa0: @ 0x080D6FA0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #5
	bls _080D6FAC
	b _080D71F0
_080D6FAC:
	lsls r0, r0, #2
	ldr r1, _080D6FB8 @ =_080D6FBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D6FB8: .4byte _080D6FBC
_080D6FBC: @ jump table
	.4byte _080D6FD4 @ case 0
	.4byte _080D708E @ case 1
	.4byte _080D70E0 @ case 2
	.4byte _080D710C @ case 3
	.4byte _080D71B8 @ case 4
	.4byte _080D71F0 @ case 5
_080D6FD4:
	movs r4, #0xb8
	ldr r0, _080D7050 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D7054 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D7058 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D705C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r4, _080D7060 @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D7068
	ldr r1, _080D7064 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0
	str r0, [r6, #0x60]
	movs r0, #3
	b _080D71EE
	.align 2, 0
_080D7050: .4byte wStaticGraphicTilenums
_080D7054: .4byte wStaticMotionPalIDs
_080D7058: .4byte gStaticMotionGraphics
_080D705C: .4byte gStaticMotionGraphics+12
_080D7060: .4byte 0xFFFFE800
_080D7064: .4byte 0x0000B802
_080D7068:
	str r0, [r6, #0x60]
	movs r0, #0x10
	str r0, [r6, #0x68]
	ldrb r4, [r6, #0xd]
	movs r3, #0x10
	movs r2, #0x5f
_080D7074:
	ldr r1, [r6, #0x60]
	adds r1, r1, r3
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [r6, #0x58]
	subs r2, #1
	cmp r2, #0
	bge _080D7074
	movs r0, #0
	strb r0, [r6, #0x13]
	adds r0, r4, #1
	strb r0, [r6, #0xd]
_080D708E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x68]
	subs r4, r1, r0
	str r4, [r6, #0x60]
	cmp r4, #0
	beq _080D70A8
	b _080D71F0
_080D70A8:
	ldr r1, _080D70D0 @ =gPaletteManager
	ldr r0, _080D70D4 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D70D8 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D70DC @ =0x0000B801
	adds r0, r6, #0
	bl SetMotion
	str r4, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	b _080D71EA
	.align 2, 0
_080D70D0: .4byte gPaletteManager
_080D70D4: .4byte 0x00000404
_080D70D8: .4byte 0x00000406
_080D70DC: .4byte 0x0000B801
_080D70E0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D70F2
	b _080D71F0
_080D70F2:
	ldr r1, _080D7104 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _080D7108 @ =0x0000013D
	bl PlaySound
	b _080D71EA
	.align 2, 0
_080D7104: .4byte 0x0000B802
_080D7108: .4byte 0x0000013D
_080D710C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7124
	ldr r1, _080D7190 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
_080D7124:
	ldr r2, _080D7194 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D7198 @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _080D719C @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D7148
	ldr r1, _080D71A0 @ =0x0000B803
	adds r0, r6, #0
	bl SetMotion
_080D7148:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D71F0
	ldr r0, _080D71A4 @ =0x0000013D
	bl StopSound
	ldr r1, _080D71A8 @ =gPaletteManager
	ldr r0, _080D71AC @ =0x00000404
	adds r2, r1, r0
	movs r4, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D71B0 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x64
	str r0, [r6, #0x40]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r0, _080D71B4 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	strb r4, [r6, #0x13]
	b _080D71EA
	.align 2, 0
_080D7190: .4byte 0x0000B802
_080D7194: .4byte RNG_0202f388
_080D7198: .4byte 0x000343FD
_080D719C: .4byte 0x00269EC3
_080D71A0: .4byte 0x0000B803
_080D71A4: .4byte 0x0000013D
_080D71A8: .4byte gPaletteManager
_080D71AC: .4byte 0x00000404
_080D71B0: .4byte 0x00000406
_080D71B4: .4byte 0xFFFFFF00
_080D71B8:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D71F0
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, _080D7240 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _080D7244 @ =0x00000FFF
	cmp r0, r1
	bls _080D71F0
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
_080D71EA:
	ldrb r0, [r6, #0xd]
	adds r0, #1
_080D71EE:
	strb r0, [r6, #0xd]
_080D71F0:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	movs r1, #0xb8
	lsls r1, r1, #8
	cmp r0, r1
	bne _080D7238
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bge _080D7238
	ldrb r0, [r6, #0x13]
	adds r2, r0, #1
	strb r2, [r6, #0x13]
	ldr r3, _080D7248 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #2
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x64]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #3
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [r6, #0x68]
_080D7238:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7240: .4byte gStageRun+232
_080D7244: .4byte 0x00000FFF
_080D7248: .4byte gSineTable

	thumb_func_start FUN_080d724c
FUN_080d724c: @ 0x080D724C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #5
	bls _080D7258
	b _080D73FA
_080D7258:
	lsls r0, r0, #2
	ldr r1, _080D7264 @ =_080D7268
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7264: .4byte _080D7268
_080D7268: @ jump table
	.4byte _080D7280 @ case 0
	.4byte _080D72FE @ case 1
	.4byte _080D731C @ case 2
	.4byte _080D734E @ case 3
	.4byte _080D7388 @ case 4
	.4byte _080D73B4 @ case 5
_080D7280:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r4, #0xaf
	lsls r4, r4, #4
	ldr r1, _080D72E4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D72E8 @ =wStaticGraphicTilenums
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D72EC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D72F0 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D72F4 @ =0x00008C06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D72F8
	movs r0, #5
	strb r0, [r6, #0xd]
	b _080D73FA
	.align 2, 0
_080D72E4: .4byte gStaticMotionGraphics
_080D72E8: .4byte wStaticGraphicTilenums
_080D72EC: .4byte gStaticMotionGraphics+12
_080D72F0: .4byte wStaticMotionPalIDs
_080D72F4: .4byte 0x00008C06
_080D72F8:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D72FE:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D73FA
	ldr r1, _080D7318 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D73A8
	.align 2, 0
_080D7318: .4byte 0x00008C05
_080D731C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080D73FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080D73A8
_080D734E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D73FA
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D73A8
_080D7388:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D73FA
	ldr r1, _080D73B0 @ =0x00008C06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D73A8:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D73FA
	.align 2, 0
_080D73B0: .4byte 0x00008C06
_080D73B4:
	ldr r0, _080D7400 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _080D7404 @ =0x00000FFF
	cmp r0, r1
	bls _080D73FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
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
	ldr r1, _080D7408 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080D73FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7400: .4byte gStageRun+232
_080D7404: .4byte 0x00000FFF
_080D7408: .4byte gSolidFnTable

	thumb_func_start FUN_080d740c
FUN_080d740c: @ 0x080D740C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bls _080D7418
	b _080D7512
_080D7418:
	lsls r0, r0, #2
	ldr r1, _080D7424 @ =_080D7428
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7424: .4byte _080D7428
_080D7428: @ jump table
	.4byte _080D743C @ case 0
	.4byte _080D74A0 @ case 1
	.4byte _080D74E4 @ case 2
	.4byte _080D74FC @ case 3
	.4byte _080D7512 @ case 4
_080D743C:
	movs r4, #0xaf
	lsls r4, r4, #4
	ldr r1, _080D74C0 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D74C4 @ =wStaticGraphicTilenums
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D74C8 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D74CC @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D74D0 @ =0x00008C07
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, _080D74D4 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D74D8 @ =0x000087FF
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D74A0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	ldr r2, _080D74DC @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x64]
	cmp r0, r1
	bge _080D7512
	str r1, [r6, #0x54]
	ldr r1, _080D74E0 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
	b _080D750C
	.align 2, 0
_080D74C0: .4byte gStaticMotionGraphics
_080D74C4: .4byte wStaticGraphicTilenums
_080D74C8: .4byte gStaticMotionGraphics+12
_080D74CC: .4byte wStaticMotionPalIDs
_080D74D0: .4byte 0x00008C07
_080D74D4: .4byte gStageRun+232
_080D74D8: .4byte 0x000087FF
_080D74DC: .4byte 0xFFFFFF00
_080D74E0: .4byte 0x00008C05
_080D74E4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7512
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D74FC:
	ldr r1, _080D7518 @ =0x00008C05
	adds r0, r6, #0
	movs r2, #0
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D7512
_080D750C:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D7512:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7518: .4byte 0x00008C05

	thumb_func_start FUN_080d751c
FUN_080d751c: @ 0x080D751C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D755A
	cmp r0, #1
	bgt _080D7530
	cmp r0, #0
	beq _080D7536
	b _080D7630
_080D7530:
	cmp r0, #2
	beq _080D7610
	b _080D7630
_080D7536:
	ldr r0, _080D7588 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D758C @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldr r1, _080D7590 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D755A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D75A0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D7594 @ =0x0000C502
	cmp r0, r1
	bne _080D7598
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D75A0
	.align 2, 0
_080D7588: .4byte wDynamicGraphicTilenums
_080D758C: .4byte wDynamicMotionPalIDs
_080D7590: .4byte 0x0000C501
_080D7594: .4byte 0x0000C502
_080D7598:
	ldr r1, _080D7608 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D75A0:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D75D0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D7608 @ =0x0000C501
	cmp r0, r1
	bne _080D75C4
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D75C4:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D75E6
_080D75D0:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D760C @ =0x0000C503
	cmp r0, r1
	bne _080D75E6
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D75E6:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7630
	ldrb r0, [r4, #0x1e]
	lsls r1, r0, #8
	ldrb r0, [r5]
	orrs r1, r0
	ldr r0, _080D7608 @ =0x0000C501
	cmp r1, r0
	beq _080D762A
	adds r0, #2
	cmp r1, r0
	bne _080D7630
	b _080D762A
	.align 2, 0
_080D7608: .4byte 0x0000C501
_080D760C: .4byte 0x0000C503
_080D7610:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D7630
_080D762A:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7630:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7638
FUN_080d7638: @ 0x080D7638
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D7682
	cmp r0, #1
	bgt _080D764C
	cmp r0, #0
	beq _080D7652
	b _080D76B4
_080D764C:
	cmp r0, #2
	beq _080D769C
	b _080D76B4
_080D7652:
	ldr r0, _080D7694 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D7698 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7682:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	b _080D76AA
	.align 2, 0
_080D7694: .4byte wDynamicGraphicTilenums
_080D7698: .4byte wDynamicMotionPalIDs
_080D769C:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
_080D76AA:
	cmp r0, #0
	beq _080D76B4
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D76B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor62_Update
Actor62_Update: @ 0x080D76BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D76C8
	b _080D7868
_080D76C8:
	lsls r0, r0, #2
	ldr r1, _080D76D4 @ =_080D76D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D76D4: .4byte _080D76D8
_080D76D8: @ jump table
	.4byte _080D7700 @ case 0
	.4byte _080D7718 @ case 1
	.4byte _080D7738 @ case 2
	.4byte _080D775A @ case 3
	.4byte _080D778C @ case 4
	.4byte _080D77AC @ case 5
	.4byte _080D77BE @ case 6
	.4byte _080D77EA @ case 7
	.4byte _080D7828 @ case 8
	.4byte _080D7868 @ case 9
_080D7700:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7718:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D772C
	b _080D7868
_080D772C:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
_080D7738:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	beq _080D774A
	b _080D7868
_080D774A:
	movs r1, #0xc4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	b _080D7862
_080D775A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	adds r0, #0x60
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D7776
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_080D7776:
	ldrb r0, [r4, #0x12]
	cmp r0, #2
	bne _080D7868
	ldr r1, _080D7788 @ =0x00003303
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
	.align 2, 0
_080D7788: .4byte 0x00003303
_080D778C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7868
	ldr r1, _080D77A8 @ =0x00003301
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
	.align 2, 0
_080D77A8: .4byte 0x00003301
_080D77AC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7868
	b _080D7862
_080D77BE:
	ldr r1, _080D7824 @ =0x00000301
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D77EA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7868
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	movs r0, #0
	str r0, [r4, #0x2c]
	b _080D7862
	.align 2, 0
_080D7824: .4byte 0x00000301
_080D7828:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _080D783C
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r4, #0x2c]
_080D783C:
	ldr r1, [r4, #0x54]
	ldr r0, _080D7870 @ =0xFFFFFC80
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, _080D7874 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D7878 @ =0xFFFF6800
	adds r0, r0, r2
	cmp r1, r0
	bge _080D7868
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080D785A
	movs r0, #1
	strb r0, [r1, #0x11]
_080D785A:
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_080D7862:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7868:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D7870: .4byte 0xFFFFFC80
_080D7874: .4byte gStageRun+232
_080D7878: .4byte 0xFFFF6800

	thumb_func_start Actor63_Update
Actor63_Update: @ 0x080D787C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #1
	beq _080D78F6
	cmp r0, #1
	bgt _080D7890
	cmp r0, #0
	beq _080D7896
	b _080D793E
_080D7890:
	cmp r0, #2
	beq _080D7938
	b _080D793E
_080D7896:
	ldr r4, _080D7920 @ =0x00000F28
	ldr r1, _080D7924 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D7928 @ =wStaticGraphicTilenums
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D792C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D7930 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D7934 @ =0x0000C203
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r0, #0x5a
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D78F6:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	adds r0, #0x80
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D793E
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D793E
	.align 2, 0
_080D7920: .4byte 0x00000F28
_080D7924: .4byte gStaticMotionGraphics
_080D7928: .4byte wStaticGraphicTilenums
_080D792C: .4byte gStaticMotionGraphics+12
_080D7930: .4byte wStaticMotionPalIDs
_080D7934: .4byte 0x0000C203
_080D7938:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D793E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Actor64_Update
Actor64_Update: @ 0x080D7944
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #4
	bls _080D7950
	b _080D7AC0
_080D7950:
	lsls r0, r0, #2
	ldr r1, _080D795C @ =_080D7960
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D795C: .4byte _080D7960
_080D7960: @ jump table
	.4byte _080D7974 @ case 0
	.4byte _080D7A34 @ case 1
	.4byte _080D7A74 @ case 2
	.4byte _080D7AA0 @ case 3
	.4byte _080D7ABA @ case 4
_080D7974:
	movs r4, #0x8c
	ldr r0, _080D7A04 @ =wStaticGraphicTilenums
	lsls r1, r4, #1
	adds r0, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #2
	strh r2, [r0]
	ldr r0, _080D7A08 @ =wStaticMotionPalIDs
	adds r6, r0, r1
	movs r0, #7
	strh r0, [r6]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080D79C4
	lsls r4, r4, #2
	adds r4, #0x8c
	lsls r4, r4, #2
	ldr r1, _080D7A0C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	subs r1, r2, r1
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D7A10 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_080D79C4:
	ldr r1, _080D7A14 @ =0x00008C02
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0x11]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D79DE
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
_080D79DE:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r1, [r5, #0x11]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7A20
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x5c]
	ldr r0, _080D7A18 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D7A1C @ =0xFFFF7800
	adds r0, r0, r1
	b _080D7A2C
	.align 2, 0
_080D7A04: .4byte wStaticGraphicTilenums
_080D7A08: .4byte wStaticMotionPalIDs
_080D7A0C: .4byte gStaticMotionGraphics
_080D7A10: .4byte gStaticMotionGraphics+12
_080D7A14: .4byte 0x00008C02
_080D7A18: .4byte gStageRun+232
_080D7A1C: .4byte 0xFFFF7800
_080D7A20:
	ldr r0, _080D7A68 @ =0xFFFFFF00
	str r0, [r5, #0x5c]
	ldr r0, _080D7A6C @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D7A70 @ =0x000087FF
	adds r0, r0, r2
_080D7A2C:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D7A34:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	cmp r2, #0
	bge _080D7A4C
	ldr r1, [r5, #0x64]
	cmp r0, r1
	ble _080D7A56
_080D7A4C:
	cmp r2, #0
	ble _080D7AC0
	ldr r1, [r5, #0x64]
	cmp r0, r1
	blt _080D7AC0
_080D7A56:
	str r1, [r5, #0x54]
	movs r1, #0x8c
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r5, #0x12]
	b _080D7A94
	.align 2, 0
_080D7A68: .4byte 0xFFFFFF00
_080D7A6C: .4byte gStageRun+232
_080D7A70: .4byte 0x000087FF
_080D7A74:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D7AC0
	ldr r1, _080D7A9C @ =0x00008C01
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
_080D7A94:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	b _080D7AC0
	.align 2, 0
_080D7A9C: .4byte 0x00008C01
_080D7AA0:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7AC0
	ldr r1, _080D7AC8 @ =0x00008C03
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D7ABA:
	adds r0, r5, #0
	bl UpdateEntityAnim
_080D7AC0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7AC8: .4byte 0x00008C03

	thumb_func_start Actor65_Update
Actor65_Update: @ 0x080D7ACC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #5
	bls _080D7AD8
	b _080D7D04
_080D7AD8:
	lsls r0, r0, #2
	ldr r1, _080D7AE4 @ =_080D7AE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7AE4: .4byte _080D7AE8
_080D7AE8: @ jump table
	.4byte _080D7B00 @ case 0
	.4byte _080D7B8C @ case 1
	.4byte _080D7BF4 @ case 2
	.4byte _080D7C20 @ case 3
	.4byte _080D7CCC @ case 4
	.4byte _080D7D04 @ case 5
_080D7B00:
	movs r4, #0xb8
	ldr r0, _080D7BD0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r6, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D7BD4 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D7BD8 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D7BDC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r4, _080D7BE0 @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r7, #0x58]
	str r6, [r7, #0x60]
	movs r0, #0x10
	str r0, [r7, #0x68]
	movs r3, #0x10
	movs r2, #0x5f
_080D7B70:
	ldr r1, [r7, #0x60]
	adds r1, r1, r3
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x58]
	subs r2, #1
	cmp r2, #0
	bge _080D7B70
	movs r0, #0
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D7B8C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x68]
	subs r4, r1, r0
	str r4, [r7, #0x60]
	cmp r4, #0
	beq _080D7BA6
	b _080D7D04
_080D7BA6:
	ldr r1, _080D7BE4 @ =gPaletteManager
	ldr r0, _080D7BE8 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D7BEC @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D7BF0 @ =0x0000B801
	adds r0, r7, #0
	bl SetMotion
	str r4, [r7, #0x60]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	b _080D7CFE
	.align 2, 0
_080D7BD0: .4byte wStaticGraphicTilenums
_080D7BD4: .4byte wStaticMotionPalIDs
_080D7BD8: .4byte gStaticMotionGraphics
_080D7BDC: .4byte gStaticMotionGraphics+12
_080D7BE0: .4byte 0xFFFFE800
_080D7BE4: .4byte gPaletteManager
_080D7BE8: .4byte 0x00000404
_080D7BEC: .4byte 0x00000406
_080D7BF0: .4byte 0x0000B801
_080D7BF4:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D7C06
	b _080D7D04
_080D7C06:
	ldr r1, _080D7C18 @ =0x0000B802
	adds r0, r7, #0
	bl SetMotion
	ldr r0, _080D7C1C @ =0x0000013D
	bl PlaySound
	b _080D7CFE
	.align 2, 0
_080D7C18: .4byte 0x0000B802
_080D7C1C: .4byte 0x0000013D
_080D7C20:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7C38
	ldr r1, _080D7CA4 @ =0x0000B802
	adds r0, r7, #0
	bl SetMotion
_080D7C38:
	ldr r2, _080D7CA8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D7CAC @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _080D7CB0 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D7C5C
	ldr r1, _080D7CB4 @ =0x0000B803
	adds r0, r7, #0
	bl SetMotion
_080D7C5C:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7D04
	ldr r0, _080D7CB8 @ =0x0000013D
	bl StopSound
	ldr r1, _080D7CBC @ =gPaletteManager
	ldr r0, _080D7CC0 @ =0x00000404
	adds r2, r1, r0
	movs r4, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D7CC4 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [r7, #0x40]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r0, _080D7CC8 @ =0xFFFFFF00
	str r0, [r7, #0x60]
	strb r4, [r7, #0x13]
	b _080D7CFE
	.align 2, 0
_080D7CA4: .4byte 0x0000B802
_080D7CA8: .4byte RNG_0202f388
_080D7CAC: .4byte 0x000343FD
_080D7CB0: .4byte 0x00269EC3
_080D7CB4: .4byte 0x0000B803
_080D7CB8: .4byte 0x0000013D
_080D7CBC: .4byte gPaletteManager
_080D7CC0: .4byte 0x00000404
_080D7CC4: .4byte 0x00000406
_080D7CC8: .4byte 0xFFFFFF00
_080D7CCC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7D04
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, _080D7D54 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _080D7D58 @ =0x00000FFF
	cmp r0, r1
	bls _080D7D04
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D7CFE:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D7D04:
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	adds r1, r7, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	movs r1, #0xb8
	lsls r1, r1, #8
	cmp r0, r1
	bne _080D7D4C
	ldr r0, [r7, #0x60]
	cmp r0, #0
	bge _080D7D4C
	ldrb r0, [r7, #0x13]
	adds r2, r0, #1
	strb r2, [r7, #0x13]
	ldr r3, _080D7D5C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #2
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #3
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x68]
_080D7D4C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D7D54: .4byte gStageRun+232
_080D7D58: .4byte 0x00000FFF
_080D7D5C: .4byte gSineTable
