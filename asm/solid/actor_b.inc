	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Actor13_Update
Actor13_Update: @ 0x080D2804
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D2816
	cmp r0, #1
	beq _080D286E
	b _080D289C
_080D2816:
	adds r0, r4, #0
	bl InitScalerotMotion1
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r2, _080D28A4 @ =0xFFFFE200
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D286E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, _080D28A8 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D28AC @ =0x0000B7FF
	adds r0, r0, r2
	cmp r1, r0
	ble _080D289C
	ldr r1, _080D28B0 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080D289C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D28A4: .4byte 0xFFFFE200
_080D28A8: .4byte gStageRun+232
_080D28AC: .4byte 0x0000B7FF
_080D28B0: .4byte gSolidFnTable

	thumb_func_start ActorSaveSelectCiel_Update
ActorSaveSelectCiel_Update: @ 0x080D28B4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D28C4
	cmp r0, #1
	beq _080D28DE
	b _080D28E4
_080D28C4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D28DE:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D28E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor15_Update
Actor15_Update: @ 0x080D28EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D28FC
	cmp r0, #1
	beq _080D2922
	b _080D2928
_080D28FC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D2930 @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0xca
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2922:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D2928:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2930: .4byte 0xFFFFE400

	thumb_func_start ActorOperator_Update
ActorOperator_Update: @ 0x080D2934
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D2944
	cmp r0, #1
	beq _080D29C4
	b _080D29CA
_080D2944:
	ldr r1, [r4, #0x54]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080D2952
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080D2954
_080D2952:
	ldr r2, _080D2994 @ =0xFFFFF400
_080D2954:
	adds r0, r1, r2
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D2998 @ =0xFFFFE500
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x11]
	movs r2, #0xc9
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	movs r1, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080D2986
	movs r1, #1
_080D2986:
	adds r2, r1, #0
	cmp r2, #0
	beq _080D299C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080D29A2
	.align 2, 0
_080D2994: .4byte 0xFFFFF400
_080D2998: .4byte 0xFFFFE500
_080D299C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080D29A2:
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
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D29C4:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D29CA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Actor17_Update
Actor17_Update: @ 0x080D29D0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D2AC0
	cmp r7, #1
	ble _080D29E0
	b _080D2B34
_080D29E0:
	cmp r7, #0
	beq _080D29E6
	b _080D2B34
_080D29E6:
	ldrb r1, [r6, #0x11]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D2A0C
	movs r0, #0x2b
	bl PlaySound
	ldr r0, _080D2AD8 @ =wStaticGraphicTilenums
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2ADC @ =wStaticMotionPalIDs
	adds r0, r0, r2
	movs r1, #8
	strh r1, [r0]
_080D2A0C:
	ldr r4, _080D2AE0 @ =0x00001270
	ldr r1, _080D2AE4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D2AD8 @ =wStaticGraphicTilenums
	movs r5, #0xec
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
	ldr r3, _080D2AE8 @ =gStaticMotionGraphics+12
	adds r4, r4, r3
	ldr r0, _080D2ADC @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080D2AEC @ =0x0000EC01
	adds r0, r6, #0
	bl SetMotion
	adds r3, r6, #0
	adds r3, #0x45
	ldrb r2, [r3]
	movs r1, #0xd
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	movs r2, #4
	orrs r0, r2
	strb r0, [r3]
	adds r3, #4
	ldrb r0, [r3]
	ands r1, r0
	orrs r1, r2
	strb r1, [r3]
	ldrb r0, [r6, #0xa]
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldrb r1, [r6, #0x11]
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080D2AF0 @ =sCollisions_08370B58+(24*2)
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #9
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D2AF4 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _080D2AF8 @ =gBlendRegBuffer
	movs r0, #0xfd
	lsls r0, r0, #6
	strh r0, [r1]
	movs r0, #8
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2AC0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #6
	bls _080D2B00
	ldr r1, _080D2AF8 @ =gBlendRegBuffer
	ldr r0, _080D2AFC @ =0x00001010
	strh r0, [r1, #2]
	adds r2, r1, #0
	b _080D2B16
	.align 2, 0
_080D2AD8: .4byte wStaticGraphicTilenums
_080D2ADC: .4byte wStaticMotionPalIDs
_080D2AE0: .4byte 0x00001270
_080D2AE4: .4byte gStaticMotionGraphics
_080D2AE8: .4byte gStaticMotionGraphics+12
_080D2AEC: .4byte 0x0000EC01
_080D2AF0: .4byte sCollisions_08370B58+(24*2)
_080D2AF4: .4byte 0xFFFFB000
_080D2AF8: .4byte gBlendRegBuffer
_080D2AFC: .4byte 0x00001010
_080D2B00:
	ldr r2, _080D2B3C @ =gBlendRegBuffer
	ldrb r1, [r6, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r1, #0x1f
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #2]
_080D2B16:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080D2B34
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	strh r3, [r2]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2B34:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2B3C: .4byte gBlendRegBuffer

	thumb_func_start Actor18_Update
Actor18_Update: @ 0x080D2B40
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	bls _080D2B4C
	b _080D2D44
_080D2B4C:
	lsls r0, r0, #2
	ldr r1, _080D2B58 @ =_080D2B5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D2B58: .4byte _080D2B5C
_080D2B5C: @ jump table
	.4byte _080D2B88 @ case 0
	.4byte _080D2BA4 @ case 1
	.4byte _080D2BBC @ case 2
	.4byte _080D2BE4 @ case 3
	.4byte _080D2C1C @ case 4
	.4byte _080D2C44 @ case 5
	.4byte _080D2C80 @ case 6
	.4byte _080D2CC4 @ case 7
	.4byte _080D2D14 @ case 8
	.4byte _080D2D2E @ case 9
	.4byte _080D2D44 @ case 10
_080D2B88:
	ldr r0, _080D2BB4 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xf0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2BB8 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2BA4:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0aa0
	b _080D2D38
	.align 2, 0
_080D2BB4: .4byte wDynamicGraphicTilenums
_080D2BB8: .4byte wDynamicMotionPalIDs
_080D2BBC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D2BD0
	b _080D2D44
_080D2BD0:
	ldr r1, _080D2BE0 @ =0x0000BE01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	b _080D2D3E
	.align 2, 0
_080D2BE0: .4byte 0x0000BE01
_080D2BE4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D2BFC
	ldr r0, _080D2C14 @ =0x00000101
	bl PlaySound
_080D2BFC:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D2C08
	b _080D2D44
_080D2C08:
	ldr r1, _080D2C18 @ =0x0000BE02
	adds r0, r4, #0
	bl SetMotion
	b _080D2D3E
	.align 2, 0
_080D2C14: .4byte 0x00000101
_080D2C18: .4byte 0x0000BE02
_080D2C1C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D2C2E
	b _080D2D44
_080D2C2E:
	ldr r1, _080D2C40 @ =0x0000BE03
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	b _080D2D3E
	.align 2, 0
_080D2C40: .4byte 0x0000BE03
_080D2C44:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, _080D2C7C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r4, #0x68]
	subs r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r1, r0, #3
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080D2D44
	strb r0, [r4, #0x12]
	str r1, [r4, #0x60]
	b _080D2D3E
	.align 2, 0
_080D2C7C: .4byte gSineTable
_080D2C80:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldr r1, _080D2CC0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r2, r0, #3
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2D44
	movs r0, #0x40
	strb r0, [r4, #0x12]
	str r2, [r4, #0x68]
	b _080D2D3E
	.align 2, 0
_080D2CC0: .4byte gSineTable
_080D2CC4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r2, [r4, #0x68]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _080D2D0C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	str r2, [r4, #0x68]
	ldr r0, [r4, #0x58]
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, r1, r2
	asrs r1, r1, #3
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp2
	cmp r0, #0
	beq _080D2D44
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080D2D10 @ =0x0000BE0E
	adds r0, r4, #0
	bl SetMotion
	b _080D2D3E
	.align 2, 0
_080D2D0C: .4byte gSineTable
_080D2D10: .4byte 0x0000BE0E
_080D2D14:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D2D44
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	b _080D2D3A
_080D2D2E:
	ldr r1, _080D2D4C @ =0x0000BE0E
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
_080D2D38:
	lsls r0, r0, #0x10
_080D2D3A:
	cmp r0, #0
	beq _080D2D44
_080D2D3E:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2D44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2D4C: .4byte 0x0000BE0E

	thumb_func_start Actor19_Update
Actor19_Update: @ 0x080D2D50
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D2DA8
	cmp r0, #1
	bgt _080D2D64
	cmp r0, #0
	beq _080D2D6A
	b _080D2DFE
_080D2D64:
	cmp r0, #2
	beq _080D2DE8
	b _080D2DFE
_080D2D6A:
	ldr r0, _080D2DD4 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2DD8 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #8
	strh r1, [r0]
	ldr r1, _080D2DDC @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	ldr r0, _080D2DE0 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080D2DE4 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2DA8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x54]
	lsls r0, r1, #7
	subs r0, r0, r1
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	asrs r0, r0, #7
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	lsls r0, r1, #7
	subs r0, r0, r1
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	asrs r0, r0, #7
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	b _080D2DF4
	.align 2, 0
_080D2DD4: .4byte wDynamicGraphicTilenums
_080D2DD8: .4byte wDynamicMotionPalIDs
_080D2DDC: .4byte 0x0000C501
_080D2DE0: .4byte gStageRun+232
_080D2DE4: .4byte 0xFFFFB000
_080D2DE8:
	ldr r1, _080D2E04 @ =0x0000C501
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
_080D2DF4:
	cmp r0, #0
	beq _080D2DFE
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2DFE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2E04: .4byte 0x0000C501

	thumb_func_start Actor20_Update
Actor20_Update: @ 0x080D2E08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bhi _080D2E8E
	lsls r0, r0, #2
	ldr r1, _080D2E1C @ =_080D2E20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D2E1C: .4byte _080D2E20
_080D2E20: @ jump table
	.4byte _080D2E34 @ case 0
	.4byte _080D2E50 @ case 1
	.4byte _080D2E68 @ case 2
	.4byte _080D2E78 @ case 3
	.4byte _080D2E8E @ case 4
_080D2E34:
	ldr r0, _080D2E5C @ =wDynamicGraphicTilenums
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xd0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2E60 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #7
	strh r1, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2E50:
	ldr r1, _080D2E64 @ =0x0000B319
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0aa0
	b _080D2E82
	.align 2, 0
_080D2E5C: .4byte wDynamicGraphicTilenums
_080D2E60: .4byte wDynamicMotionPalIDs
_080D2E64: .4byte 0x0000B319
_080D2E68:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	b _080D2E84
_080D2E78:
	ldr r1, _080D2E94 @ =0x0000B319
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
_080D2E82:
	lsls r0, r0, #0x10
_080D2E84:
	cmp r0, #0
	beq _080D2E8E
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2E8E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2E94: .4byte 0x0000B319
