	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Actor21_Update
Actor21_Update: @ 0x080D2EDC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #6
	bls _080D2EE8
	b _080D2FEC
_080D2EE8:
	lsls r0, r0, #2
	ldr r1, _080D2EF4 @ =_080D2EF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D2EF4: .4byte _080D2EF8
_080D2EF8: @ jump table
	.4byte _080D2F14 @ case 0
	.4byte _080D2F26 @ case 1
	.4byte _080D2F58 @ case 2
	.4byte _080D2F6A @ case 3
	.4byte _080D2F86 @ case 4
	.4byte _080D2FC0 @ case 5
	.4byte _080D2FEC @ case 6
_080D2F14:
	movs r1, #0
	str r1, [r6, #0x54]
	movs r0, #0x93
	lsls r0, r0, #8
	str r0, [r6, #0x58]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2F26:
	ldr r2, _080D2F54 @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	adds r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1f
	bls _080D2FEC
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	movs r0, #0x10
	strb r0, [r6, #0x13]
	b _080D2FEC
	.align 2, 0
_080D2F54: .4byte gSineTable
_080D2F58:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D2FEC
	movs r0, #4
	strb r0, [r6, #0x13]
	b _080D2FE6
_080D2F6A:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D2FEC
	movs r0, #8
	strb r0, [r6, #0x13]
	b _080D2FE6
_080D2F86:
	ldrb r1, [r6, #0x13]
	subs r1, #1
	strb r1, [r6, #0x13]
	ldr r2, _080D2FBC @ =gSineTable
	lsls r0, r1, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [r6, #0x54]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080D2FEC
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	movs r0, #0x97
	lsls r0, r0, #1
	bl PlaySound
	b _080D2FEC
	.align 2, 0
_080D2FBC: .4byte gSineTable
_080D2FC0:
	ldr r1, [r6, #0x54]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	str r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bgt _080D2FEC
	ldr r2, _080D302C @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080D3030 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
_080D2FE6:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2FEC:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r5, _080D302C @ =gWindowRegBuffer
	ldr r2, [r6, #0x54]
	asrs r2, r2, #8
	movs r3, #1
	ands r3, r0
	lsls r0, r3, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xbc
	movs r4, #0xff
	ands r1, r4
	movs r0, #0xbc
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r6, #0x58]
	asrs r0, r0, #8
	lsls r3, r3, #2
	adds r0, r0, r3
	ands r0, r4
	strh r0, [r5, #0xa]
	ldr r1, _080D3034 @ =gPaletteManager
	ldr r3, _080D3038 @ =0x00007FFF
	adds r0, r3, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D302C: .4byte gWindowRegBuffer
_080D3030: .4byte 0x0000BFFF
_080D3034: .4byte gPaletteManager
_080D3038: .4byte 0x00007FFF

	thumb_func_start Actor22_Update
Actor22_Update: @ 0x080D303C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #4
	bls _080D3048
	b _080D3166
_080D3048:
	lsls r0, r0, #2
	ldr r1, _080D3054 @ =_080D3058
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3054: .4byte _080D3058
_080D3058: @ jump table
	.4byte _080D306C @ case 0
	.4byte _080D30D6 @ case 1
	.4byte _080D3120 @ case 2
	.4byte _080D3140 @ case 3
	.4byte _080D3166 @ case 4
_080D306C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	movs r4, #0x82
	ldr r0, _080D310C @ =wStaticGraphicTilenums
	lsls r1, r4, #1
	adds r2, r0, r1
	ldr r0, _080D3110 @ =0x0000024D
	strh r0, [r2]
	ldr r0, _080D3114 @ =wStaticMotionPalIDs
	adds r6, r0, r1
	movs r0, #8
	strh r0, [r6]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080D30C6
	lsls r4, r4, #2
	adds r4, #0x82
	lsls r4, r4, #2
	ldr r1, _080D3118 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r2]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D311C @ =gStaticMotionGraphics+12
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
_080D30C6:
	movs r1, #0x82
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D30D6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D3166
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #8
	strb r0, [r5, #0x12]
	b _080D3160
	.align 2, 0
_080D310C: .4byte wStaticGraphicTilenums
_080D3110: .4byte 0x0000024D
_080D3114: .4byte wStaticMotionPalIDs
_080D3118: .4byte gStaticMotionGraphics
_080D311C: .4byte gStaticMotionGraphics+12
_080D3120:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D3166
	ldr r1, _080D313C @ =0x00008202
	adds r0, r5, #0
	bl SetMotion
	b _080D3160
	.align 2, 0
_080D313C: .4byte 0x00008202
_080D3140:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x54]
	subs r1, #0x80
	str r1, [r5, #0x54]
	ldr r0, _080D316C @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D3170 @ =0xFFFF7800
	adds r0, r0, r2
	cmp r1, r0
	bge _080D3166
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
_080D3160:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D3166:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D316C: .4byte gStageRun+232
_080D3170: .4byte 0xFFFF7800

	thumb_func_start initActor23
initActor23: @ 0x080D3174
	push {lr}
	ldrb r2, [r0, #0xb]
	movs r1, #8
	movs r3, #0
	orrs r1, r2
	strb r1, [r0, #0xb]
	ldr r1, _080D31A4 @ =Rect_08370c60
	str r1, [r0, #0x30]
	ldr r1, _080D31A8 @ =0x00002001
	strh r1, [r0, #0x26]
	str r3, [r0, #0x5c]
	ldr r2, _080D31AC @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	bl Actor_Update
	pop {r0}
	bx r0
	.align 2, 0
_080D31A4: .4byte Rect_08370c60
_080D31A8: .4byte 0x00002001
_080D31AC: .4byte gSolidFnTable

	thumb_func_start Actor23_Update
Actor23_Update: @ 0x080D31B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D31EE
	ldr r0, _080D31F4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _080D31F8 @ =0x00000FFF
	cmp r0, r1
	bhi _080D31EE
	ldr r0, [r4, #0x5c]
	adds r0, #4
	str r0, [r4, #0x5c]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080D31E0
	str r1, [r4, #0x5c]
_080D31E0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	subs r0, r0, r1
	str r0, [r4, #0x58]
_080D31EE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D31F4: .4byte gStageRun+232
_080D31F8: .4byte 0x00000FFF

	thumb_func_start Actor24_Update
Actor24_Update: @ 0x080D31FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0
	bne _080D325C
	ldr r6, [r7, #0x28]
	ldr r4, _080D3268 @ =0x0000107C
	ldr r1, _080D326C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D3270 @ =wStaticGraphicTilenums
	movs r5, #0xd3
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
	ldr r0, _080D3274 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D3278 @ =wStaticMotionPalIDs
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
	ldr r1, _080D327C @ =0x0000D301
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r6]
	str r0, [r7, #0x54]
	ldr r0, [r6, #4]
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D325C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D3268: .4byte 0x0000107C
_080D326C: .4byte gStaticMotionGraphics
_080D3270: .4byte wStaticGraphicTilenums
_080D3274: .4byte gStaticMotionGraphics+12
_080D3278: .4byte wStaticMotionPalIDs
_080D327C: .4byte 0x0000D301

	thumb_func_start Actor25_Update
Actor25_Update: @ 0x080D3280
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #9
	bls _080D328E
	b _080D358C
_080D328E:
	lsls r0, r0, #2
	ldr r1, _080D3298 @ =_080D329C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3298: .4byte _080D329C
_080D329C: @ jump table
	.4byte _080D32C4 @ case 0
	.4byte _080D3352 @ case 1
	.4byte _080D336C @ case 2
	.4byte _080D339C @ case 3
	.4byte _080D33BA @ case 4
	.4byte _080D33DA @ case 5
	.4byte _080D3412 @ case 6
	.4byte _080D3478 @ case 7
	.4byte _080D356C @ case 8
	.4byte _080D3584 @ case 9
_080D32C4:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	ldrb r6, [r7, #0x11]
	movs r0, #0xf
	ands r0, r6
	strb r0, [r7, #0x11]
	ldrb r4, [r7, #0x11]
	adds r4, #0xf5
	lsls r5, r4, #2
	adds r5, r5, r4
	lsls r5, r5, #2
	ldr r1, _080D333C @ =gStaticMotionGraphics
	adds r0, r5, r1
	ldr r1, _080D3340 @ =wStaticGraphicTilenums
	lsls r4, r4, #1
	adds r1, r4, r1
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r3, _080D3344 @ =gStaticMotionGraphics+12
	adds r5, r5, r3
	ldr r0, _080D3348 @ =wStaticMotionPalIDs
	adds r4, r4, r0
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadPalette
	ldrb r1, [r7, #0x11]
	adds r1, #0xf5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	cmp r6, #0xf
	bhi _080D334C
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0xd]
	adds r0, #2
	strb r0, [r7, #0xd]
	b _080D358C
	.align 2, 0
_080D333C: .4byte gStaticMotionGraphics
_080D3340: .4byte wStaticGraphicTilenums
_080D3344: .4byte gStaticMotionGraphics+12
_080D3348: .4byte wStaticMotionPalIDs
_080D334C:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3352:
	ldrb r1, [r7, #0x11]
	adds r1, #0xf5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	movs r2, #0
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D336A
	b _080D358C
_080D336A:
	b _080D357C
_080D336C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3380
	b _080D358C
_080D3380:
	adds r0, r7, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xf8
	bl StartPaletteAnimation
	b _080D357C
_080D339C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0xf8
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080D33B2
	b _080D358C
_080D33B2:
	movs r0, #0xf8
	bl RemovePaletteAnimation
	b _080D357C
_080D33BA:
	adds r0, r7, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0xf9
	bl StartPaletteAnimation
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D33DA:
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0xf9
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _080D33F0
	b _080D358C
_080D33F0:
	movs r0, #0xf9
	bl RemovePaletteAnimation
	adds r0, r7, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xfa
	bl StartPaletteAnimation
	b _080D357C
_080D3412:
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0xfa
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080D3428
	b _080D358C
_080D3428:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x64]
	ldr r5, _080D34A0 @ =s32_ARRAY_08370de8
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	lsls r1, r1, #7
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x68]
	adds r0, r7, #0
	adds r0, #0x64
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r7, #0x28]
	adds r0, #0x74
	movs r4, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x76
	strb r1, [r0]
	movs r0, #0x58
	bl PlaySound
	strb r4, [r7, #0x12]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [r7, #0x5c]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3478:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	adds r3, r0, #1
	strb r3, [r7, #0x12]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bhi _080D34A8
	ldr r2, [r7, #0x28]
	ldr r1, _080D34A4 @ =gSineTable
	lsls r0, r3, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r7, #0x5c]
	b _080D34EA
	.align 2, 0
_080D34A0: .4byte s32_ARRAY_08370de8
_080D34A4: .4byte gSineTable
_080D34A8:
	cmp r0, #0x20
	bne _080D34C0
	ldr r1, [r7, #0x28]
	ldr r0, [r7, #0x5c]
	subs r0, #2
	lsls r0, r0, #8
	str r0, [r1, #0x78]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	b _080D3556
_080D34C0:
	cmp r0, #0x35
	bhi _080D34D0
	ldr r1, [r7, #0x28]
	ldr r0, [r7, #0x5c]
	subs r0, #4
	lsls r0, r0, #8
	str r0, [r1, #0x78]
	b _080D3556
_080D34D0:
	cmp r0, #0x3f
	bhi _080D34F4
	ldr r2, [r7, #0x28]
	ldr r1, _080D34F0 @ =gSineTable
	movs r0, #0x40
	subs r0, r0, r3
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r7, #0x5c]
	subs r0, #4
_080D34EA:
	muls r0, r1, r0
	str r0, [r2, #0x78]
	b _080D3556
	.align 2, 0
_080D34F0: .4byte gSineTable
_080D34F4:
	movs r4, #0
	ldr r5, _080D3568 @ =s32_ARRAY_08370de8
_080D34F8:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	bl FUN_080c5684
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _080D34F8
	ldr r0, [r7, #0x28]
	adds r0, #0x77
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xfa
	bl RemovePaletteAnimation
	ldrb r4, [r7, #0x11]
	adds r4, #0xfb
	adds r0, r7, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r4, #0
	bl StartPaletteAnimation
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3556:
	ldr r2, [r7, #0x28]
	ldrb r0, [r7, #0x12]
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	b _080D358C
	.align 2, 0
_080D3568: .4byte s32_ARRAY_08370de8
_080D356C:
	ldrb r0, [r7, #0x11]
	adds r0, #0xfb
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080D358C
_080D357C:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D358C
_080D3584:
	ldrb r0, [r7, #0x11]
	adds r0, #0xfb
	bl RemovePaletteAnimation
_080D358C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Actor26_Update
Actor26_Update: @ 0x080D3594
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D360C
	cmp r0, #1
	bgt _080D368C
	cmp r0, #0
	bne _080D368C
	ldr r1, _080D3694 @ =wStaticGraphicTilenums
	adds r1, #0xa2
	ldrh r0, [r1]
	str r0, [r7, #0x64]
	ldr r5, _080D3698 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	ldrh r0, [r5]
	str r0, [r7, #0x68]
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	movs r6, #0
	ldr r0, _080D369C @ =0x00000305
	strh r0, [r1]
	movs r0, #8
	strh r0, [r5]
	ldr r4, _080D36A0 @ =0x00000654
	ldr r2, _080D36A4 @ =gStaticMotionGraphics
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
	ldr r0, _080D36A8 @ =gStaticMotionGraphics+12
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
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D360C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r1, [r7, #0x12]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D3628
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #3
	movs r1, #0
	bl FUN_080c5628
_080D3628:
	ldrb r1, [r7, #0x12]
	adds r1, #1
	strb r1, [r7, #0x12]
	ldr r2, [r7, #0x5c]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r2, r4
	str r2, [r7, #0x5c]
	ldr r3, _080D36AC @ =gSineTable
	lsls r0, r1, #0x19
	movs r4, #0x80
	lsls r4, r4, #0x17
	adds r0, r0, r4
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	adds r2, r2, r0
	str r2, [r7, #0x54]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r1, r1, #2
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, _080D36B0 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D36B4 @ =0x000097FF
	adds r0, r0, r1
	cmp r2, r0
	blt _080D368C
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r0, _080D3694 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	ldr r1, [r7, #0x64]
	strh r1, [r0]
	ldr r0, _080D3698 @ =wStaticMotionPalIDs
	adds r0, #0xa2
	ldr r1, [r7, #0x68]
	strh r1, [r0]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D368C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D3694: .4byte wStaticGraphicTilenums
_080D3698: .4byte wStaticMotionPalIDs
_080D369C: .4byte 0x00000305
_080D36A0: .4byte 0x00000654
_080D36A4: .4byte gStaticMotionGraphics
_080D36A8: .4byte gStaticMotionGraphics+12
_080D36AC: .4byte gSineTable
_080D36B0: .4byte gStageRun+232
_080D36B4: .4byte 0x000097FF

	thumb_func_start Actor27_Update
Actor27_Update: @ 0x080D36B8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D36C4
	b _080D3890
_080D36C4:
	lsls r0, r0, #2
	ldr r1, _080D36D0 @ =_080D36D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D36D0: .4byte _080D36D4
_080D36D4: @ jump table
	.4byte _080D36FC @ case 0
	.4byte _080D3732 @ case 1
	.4byte _080D374C @ case 2
	.4byte _080D3760 @ case 3
	.4byte _080D378E @ case 4
	.4byte _080D37B4 @ case 5
	.4byte _080D37C6 @ case 6
	.4byte _080D37FA @ case 7
	.4byte _080D3828 @ case 8
	.4byte _080D3890 @ case 9
_080D36FC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r2, _080D3740 @ =wDynamicGraphicTilenums
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r2, r2, r3
	ldrh r0, [r2]
	str r0, [r4, #0x64]
	ldr r1, _080D3744 @ =wDynamicMotionPalIDs
	adds r1, r1, r3
	ldrh r0, [r1]
	str r0, [r4, #0x68]
	ldr r0, _080D3748 @ =0x00000305
	strh r0, [r2]
	movs r0, #9
	strh r0, [r1]
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3732:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D37A8
	b _080D379A
	.align 2, 0
_080D3740: .4byte wDynamicGraphicTilenums
_080D3744: .4byte wDynamicMotionPalIDs
_080D3748: .4byte 0x00000305
_080D374C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D375E
	b _080D3890
_080D375E:
	b _080D388A
_080D3760:
	movs r1, #0xa4
	lsls r1, r1, #8
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
_080D378E:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D37A8
_080D379A:
	ldr r1, _080D37B0 @ =0x0000A408
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D37A8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080D3890
	.align 2, 0
_080D37B0: .4byte 0x0000A408
_080D37B4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D3890
	b _080D388A
_080D37C6:
	movs r1, #0xa4
	lsls r1, r1, #8
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
	strb r2, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D37FA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D3890
	ldr r1, _080D3820 @ =0x0000A405
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080D3824 @ =0xFFFFFB00
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x5c]
	b _080D388A
	.align 2, 0
_080D3820: .4byte 0x0000A405
_080D3824: .4byte 0xFFFFFB00
_080D3828:
	ldr r0, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	cmp r1, #0
	ble _080D385A
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _080D3898 @ =0x0000A406
	cmp r0, r1
	beq _080D385A
	adds r0, r4, #0
	bl SetMotion
_080D385A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	movs r1, #0xd0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _080D3890
	ldr r0, _080D389C @ =wDynamicGraphicTilenums
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, [r4, #0x64]
	strh r1, [r0]
	ldr r0, _080D38A0 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	ldr r1, [r4, #0x68]
	strh r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080D388A:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3890:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D3898: .4byte 0x0000A406
_080D389C: .4byte wDynamicGraphicTilenums
_080D38A0: .4byte wDynamicMotionPalIDs

	thumb_func_start initActor28
initActor28: @ 0x080D38A4
	push {r4, lr}
	ldr r2, _080D38E0 @ =gWindowRegBuffer
	ldrh r3, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	movs r4, #0
	orrs r1, r3
	strh r1, [r2]
	strb r4, [r2, #0xd]
	ldrb r3, [r2, #0xe]
	movs r1, #0xfe
	orrs r1, r3
	strb r1, [r2, #0xe]
	strb r4, [r0, #0x12]
	ldr r2, _080D38E4 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	bl Actor_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D38E0: .4byte gWindowRegBuffer
_080D38E4: .4byte gSolidFnTable

	thumb_func_start Actor28_Update
Actor28_Update: @ 0x080D38E8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bhi _080D39A6
	lsls r0, r0, #2
	ldr r1, _080D38FC @ =_080D3900
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D38FC: .4byte _080D3900
_080D3900: @ jump table
	.4byte _080D3914 @ case 0
	.4byte _080D392E @ case 1
	.4byte _080D3960 @ case 2
	.4byte _080D3976 @ case 3
	.4byte _080D39A6 @ case 4
_080D3914:
	movs r4, #0
	str r4, [r6, #0x54]
	movs r0, #0x93
	lsls r0, r0, #8
	str r0, [r6, #0x58]
	movs r0, #0x97
	lsls r0, r0, #1
	bl PlaySound
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D392E:
	ldr r2, _080D395C @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	adds r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0xf
	bls _080D39A6
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	movs r0, #0x20
	strb r0, [r6, #0x13]
	b _080D39A6
	.align 2, 0
_080D395C: .4byte gSineTable
_080D3960:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D39A6
	movs r0, #0x20
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D3976:
	ldr r2, _080D39E8 @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	subs r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080D39A6
	ldr r2, _080D39EC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080D39F0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D39A6:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r5, _080D39EC @ =gWindowRegBuffer
	ldr r2, [r6, #0x54]
	asrs r2, r2, #8
	movs r3, #1
	ands r3, r0
	lsls r0, r3, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xbc
	movs r4, #0xff
	ands r1, r4
	movs r0, #0xbc
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r6, #0x58]
	asrs r0, r0, #8
	lsls r3, r3, #2
	adds r0, r0, r3
	ands r0, r4
	strh r0, [r5, #0xa]
	ldr r1, _080D39F4 @ =gPaletteManager
	ldr r2, _080D39F8 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D39E8: .4byte gSineTable
_080D39EC: .4byte gWindowRegBuffer
_080D39F0: .4byte 0x0000BFFF
_080D39F4: .4byte gPaletteManager
_080D39F8: .4byte 0x00007FFF

	thumb_func_start Actor29_Update
Actor29_Update: @ 0x080D39FC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D3A7E
	cmp r7, #1
	bgt _080D3A12
	cmp r7, #0
	beq _080D3A1A
	b _080D3B2E
_080D3A12:
	cmp r7, #2
	bne _080D3A18
	b _080D3B24
_080D3A18:
	b _080D3B2E
_080D3A1A:
	ldr r0, [r6, #0x54]
	ldr r1, _080D3AF8 @ =0xFFFF1000
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r0, #1
	str r0, [r6, #0x58]
	ldr r0, _080D3AFC @ =wStaticGraphicTilenums
	movs r5, #0
	ldr r1, _080D3B00 @ =0x000003CE
	strh r1, [r0, #2]
	ldr r4, _080D3B04 @ =wStaticMotionPalIDs
	movs r0, #9
	strh r0, [r4, #2]
	ldr r0, _080D3B08 @ =0x085D790C
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D3B0C @ =0x085D7918
	ldrh r1, [r4, #2]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #8
	bl AppendQuake
	strb r5, [r6, #0x12]
	str r7, [r6, #0x60]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D3A7E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, [r6, #0x60]
	adds r1, #0x10
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r4, r6, #0
	adds r4, #0x54
	movs r0, #2
	adds r1, r4, #0
	bl AppendQuake
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080D3AD6
	ldr r0, [r6, #0x54]
	ldr r1, _080D3B10 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, _080D3B14 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D3B18 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D3B1C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080D3AD6:
	ldr r0, _080D3B20 @ =gStageRun+232
	adds r1, r4, #0
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bls _080D3B2E
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D3B2E
	.align 2, 0
_080D3AF8: .4byte 0xFFFF1000
_080D3AFC: .4byte wStaticGraphicTilenums
_080D3B00: .4byte 0x000003CE
_080D3B04: .4byte wStaticMotionPalIDs
_080D3B08: .4byte gStaticMotionGraphics+(20*1)
_080D3B0C: .4byte gStaticMotionGraphics+(20*1)+12
_080D3B10: .4byte 0xFFFFC000
_080D3B14: .4byte RNG_0202f388
_080D3B18: .4byte 0x000343FD
_080D3B1C: .4byte 0x00269EC3
_080D3B20: .4byte gStageRun+232
_080D3B24:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
_080D3B2E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor30_Update
Actor30_Update: @ 0x080D3B38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D3C16
	cmp r0, #1
	bgt _080D3B56
	cmp r0, #0
	beq _080D3B64
	b _080D3D10
_080D3B56:
	cmp r0, #2
	bne _080D3B5C
	b _080D3C8C
_080D3B5C:
	cmp r0, #3
	bne _080D3B62
	b _080D3D08
_080D3B62:
	b _080D3D10
_080D3B64:
	ldr r0, [r7, #0x54]
	ldr r1, _080D3CD4 @ =0xFFFF6000
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r2, _080D3CD8 @ =0x00000101
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r1, _080D3CDC @ =wStaticGraphicTilenums
	ldr r0, _080D3CE0 @ =0x000003CE
	strh r0, [r1, #2]
	ldr r6, _080D3CE4 @ =wStaticMotionPalIDs
	movs r0, #9
	strh r0, [r6, #2]
	movs r4, #0xb9
	lsls r0, r4, #1
	mov r8, r0
	adds r2, r1, #0
	add r2, r8
	mov sl, r2
	ldr r0, _080D3CE8 @ =0x000003AF
	strh r0, [r2]
	add r8, r6
	movs r0, #0xa
	mov r2, r8
	strh r0, [r2]
	ldr r5, _080D3CEC @ =gStaticMotionGraphics
	adds r0, r5, #0
	adds r0, #0x14
	ldrh r1, [r1, #2]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D3CF0 @ =gStaticMotionGraphics+12
	mov sb, r0
	adds r0, #0x14
	ldrh r1, [r6, #2]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r1, r6
	bl LoadPalette
	lsls r4, r4, #4
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r5, r4, r5
	mov r2, sl
	ldrh r1, [r2]
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadGraphic
	add r4, sb
	mov r2, r8
	ldrh r1, [r2]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3C16:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D3D10
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0x10
	bl AppendQuake
	ldr r5, _080D3CF4 @ =RNG_0202f388
	mov r6, sp
	movs r4, #3
_080D3C38:
	ldr r0, [r7, #0x54]
	ldr r1, _080D3CF8 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5]
	ldr r0, _080D3CFC @ =0x000343FD
	muls r1, r0, r1
	ldr r2, _080D3D00 @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r5]
	lsls r1, r1, #3
	lsrs r1, r1, #0x14
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r6, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	subs r4, #1
	cmp r4, #0
	bge _080D3C38
	ldr r0, _080D3D04 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	str r0, [r7, #0x64]
	adds r0, r7, #0
	bl InitRotatableMotion
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	str r0, [r7, #0x60]
	str r0, [r7, #0x68]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3C8C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r1, [r7, #0x60]
	adds r1, #1
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x68]
	asrs r0, r0, #0xb
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r1, [r7, #0x60]
	asrs r2, r1, #2
	ldr r0, [r7, #0x58]
	subs r0, r0, r2
	str r0, [r7, #0x58]
	asrs r1, r1, #1
	ldr r0, [r7, #0x64]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, _080D3D04 @ =pZero2
	ldr r1, [r1]
	str r0, [r1, #0x58]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D10
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D3D10
	.align 2, 0
_080D3CD4: .4byte 0xFFFF6000
_080D3CD8: .4byte 0x00000101
_080D3CDC: .4byte wStaticGraphicTilenums
_080D3CE0: .4byte 0x000003CE
_080D3CE4: .4byte wStaticMotionPalIDs
_080D3CE8: .4byte 0x000003AF
_080D3CEC: .4byte gStaticMotionGraphics
_080D3CF0: .4byte gStaticMotionGraphics+12
_080D3CF4: .4byte RNG_0202f388
_080D3CF8: .4byte 0xFFFFC000
_080D3CFC: .4byte 0x000343FD
_080D3D00: .4byte 0x00269EC3
_080D3D04: .4byte pZero2
_080D3D08:
	ldr r0, _080D3D4C @ =pZero2
	ldr r1, [r0]
	ldr r0, [r7, #0x64]
	str r0, [r1, #0x58]
_080D3D10:
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	bhi _080D3D3A
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3D30
	movs r0, #4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080c5628
_080D3D30:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
_080D3D3A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D3D4C: .4byte pZero2

	thumb_func_start Actor31_Update
Actor31_Update: @ 0x080D3D50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xd]
	cmp r5, #1
	beq _080D3D98
	cmp r5, #1
	bgt _080D3DD8
	cmp r5, #0
	bne _080D3DD8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r4, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x74
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x76
	strb r1, [r0]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3D98:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldr r3, [r4, #0x28]
	ldr r2, _080D3DE0 @ =gSineTable
	movs r1, #0xfe
	ands r0, r1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	str r0, [r3, #0x78]
	ldr r2, [r4, #0x28]
	ldrb r0, [r4, #0x12]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0xc
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x81
	bne _080D3DD8
	ldr r0, [r4, #0x28]
	adds r0, #0x77
	strb r3, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3DD8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D3DE0: .4byte gSineTable

	thumb_func_start initActor32
initActor32: @ 0x080D3DE4
	push {r4, lr}
	ldr r2, _080D3E20 @ =gWindowRegBuffer
	ldrh r3, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	movs r4, #0
	orrs r1, r3
	strh r1, [r2]
	movs r1, #4
	strb r1, [r2, #0xd]
	ldrb r3, [r2, #0xe]
	movs r1, #0xfe
	orrs r1, r3
	strb r1, [r2, #0xe]
	strb r4, [r0, #0x12]
	ldr r2, _080D3E24 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	bl Actor_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D3E20: .4byte gWindowRegBuffer
_080D3E24: .4byte gSolidFnTable

	thumb_func_start Actor32_Update
Actor32_Update: @ 0x080D3E28
	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xd]
	ldr r5, _080D3E40 @ =gWindowRegBuffer
	cmp r0, #4
	bhi _080D3EDC
	lsls r0, r0, #2
	ldr r1, _080D3E44 @ =_080D3E48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3E40: .4byte gWindowRegBuffer
_080D3E44: .4byte _080D3E48
_080D3E48: @ jump table
	.4byte _080D3E5C @ case 0
	.4byte _080D3E72 @ case 1
	.4byte _080D3E94 @ case 2
	.4byte _080D3EC0 @ case 3
	.4byte _080D3EDC @ case 4
_080D3E5C:
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r3, #0x54]
	movs r0, #0x92
	lsls r0, r0, #8
	str r0, [r3, #0x58]
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3E72:
	ldr r0, [r3, #0x58]
	ldr r1, _080D3F08 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r3, #0x58]
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0x3f
	bls _080D3EDC
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3E94:
	ldr r1, _080D3F10 @ =gSineTable
	ldrb r0, [r3, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xb8
	muls r0, r1, r0
	str r0, [r3, #0x54]
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0x3f
	bls _080D3EDC
	movs r0, #0x10
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3EC0:
	ldrb r0, [r3, #0x13]
	subs r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0
	bne _080D3EDC
	ldrh r0, [r5]
	ldr r1, _080D3F14 @ =0x0000BFFF
	ands r1, r0
	strh r1, [r5]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3EDC:
	ldrb r0, [r3, #0x12]
	adds r0, #1
	strb r0, [r3, #0x12]
	ldr r2, [r3, #0x54]
	asrs r2, r2, #8
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xc0
	adds r4, r5, #0
	movs r0, #0xc0
	subs r0, r0, r2
	lsls r2, r0, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xf0
	bgt _080D3F18
	movs r0, #0xff
	ands r0, r1
	b _080D3F1A
	.align 2, 0
_080D3F08: .4byte 0xFFFFF800
_080D3F0C: .4byte gWindowRegBuffer
_080D3F10: .4byte gSineTable
_080D3F14: .4byte 0x0000BFFF
_080D3F18:
	movs r0, #0xf0
_080D3F1A:
	orrs r0, r2
	strh r0, [r4, #6]
	ldr r1, [r3, #0x58]
	asrs r1, r1, #8
	ldrb r2, [r3, #0x12]
	movs r0, #1
	ands r0, r2
	lsls r0, r0, #3
	subs r1, r1, r0
	adds r2, r0, #0
	adds r2, #0x93
	movs r0, #0xff
	ands r2, r0
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _080D3F40
	lsls r0, r0, #8
	orrs r2, r0
_080D3F40:
	strh r2, [r5, #0xa]
	ldr r1, _080D3F50 @ =gPaletteManager
	ldr r2, _080D3F54 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D3F50: .4byte gPaletteManager
_080D3F54: .4byte 0x00007FFF

	thumb_func_start Actor33_Update
Actor33_Update: @ 0x080D3F58
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0xe
	bls _080D3F64
	b _080D4108
_080D3F64:
	lsls r0, r0, #2
	ldr r1, _080D3F70 @ =_080D3F74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3F70: .4byte _080D3F74
_080D3F74: @ jump table
	.4byte _080D3FB0 @ case 0
	.4byte _080D3FC8 @ case 1
	.4byte _080D4006 @ case 2
	.4byte _080D402C @ case 3
	.4byte _080D403E @ case 4
	.4byte _080D405C @ case 5
	.4byte _080D406A @ case 6
	.4byte _080D4080 @ case 7
	.4byte _080D4092 @ case 8
	.4byte _080D40A6 @ case 9
	.4byte _080D40B6 @ case 10
	.4byte _080D40C4 @ case 11
	.4byte _080D40D4 @ case 12
	.4byte _080D40F4 @ case 13
	.4byte _080D4102 @ case 14
_080D3FB0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3FC8:
	ldr r1, _080D404C @ =gPaletteManager
	ldr r0, _080D4050 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _080D4054 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3FEA
	b _080D4108
_080D3FEA:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080D4058 @ =0x00003503
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4006:
	ldr r1, _080D404C @ =gPaletteManager
	ldr r0, _080D4050 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _080D4054 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D4108
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D402C:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D4108
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D403E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	b _080D40E6
	.align 2, 0
_080D404C: .4byte gPaletteManager
_080D4050: .4byte 0x00000404
_080D4054: .4byte 0x00000406
_080D4058: .4byte 0x00003503
_080D405C:
	ldr r1, _080D407C @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D406A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4108
	b _080D40EC
	.align 2, 0
_080D407C: .4byte 0x00003501
_080D4080:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4092:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D4108
	b _080D40EC
_080D40A6:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D40B6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	b _080D40E6
_080D40C4:
	movs r1, #0xc4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D40D4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	subs r0, #0x50
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x20
_080D40E6:
	ands r0, r1
	cmp r0, #0
	beq _080D4108
_080D40EC:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D4108
_080D40F4:
	ldr r1, _080D4110 @ =0x00003303
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4102:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D4108:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D4110: .4byte 0x00003303

	thumb_func_start Actor34_Update
Actor34_Update: @ 0x080D4114
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _080D4124
	cmp r0, #1
	beq _080D418C
	b _080D4220
_080D4124:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D41EC @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r4, #0xb8
	ldr r1, _080D41F0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D41F4 @ =0x00000385
	strh r0, [r1]
	ldr r5, _080D41F8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #5
	strh r0, [r5]
	lsls r4, r4, #4
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r4, r4, r2
	ldr r2, _080D41FC @ =gStaticMotionGraphics
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
	ldr r0, _080D4200 @ =gStaticMotionGraphics+12
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
	ldr r1, _080D4204 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D418C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D41A4
	ldr r1, _080D4204 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
_080D41A4:
	ldr r4, _080D4208 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r7, _080D420C @ =0x000343FD
	muls r0, r7, r0
	ldr r5, _080D4210 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D41C8
	ldr r1, _080D4214 @ =0x0000B803
	adds r0, r6, #0
	bl SetMotion
_080D41C8:
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D4220
	ldr r0, [r4]
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4218
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080D421E
	.align 2, 0
_080D41EC: .4byte 0xFFFFE800
_080D41F0: .4byte wStaticGraphicTilenums
_080D41F4: .4byte 0x00000385
_080D41F8: .4byte wStaticMotionPalIDs
_080D41FC: .4byte gStaticMotionGraphics
_080D4200: .4byte gStaticMotionGraphics+12
_080D4204: .4byte 0x0000B802
_080D4208: .4byte RNG_0202f388
_080D420C: .4byte 0x000343FD
_080D4210: .4byte 0x00269EC3
_080D4214: .4byte 0x0000B803
_080D4218:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080D421E:
	strb r0, [r6, #0xa]
_080D4220:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor35_Update
Actor35_Update: @ 0x080D4228
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D4234
	b _080D43B6
_080D4234:
	lsls r0, r0, #2
	ldr r1, _080D4240 @ =_080D4244
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4240: .4byte _080D4244
_080D4244: @ jump table
	.4byte _080D426C @ case 0
	.4byte _080D4284 @ case 1
	.4byte _080D42A4 @ case 2
	.4byte _080D42C0 @ case 3
	.4byte _080D42D4 @ case 4
	.4byte _080D42F4 @ case 5
	.4byte _080D4302 @ case 6
	.4byte _080D4324 @ case 7
	.4byte _080D434C @ case 8
	.4byte _080D436C @ case 9
_080D426C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080D429C @ =0x0000C20D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4284:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D4298
	b _080D43B6
_080D4298:
	ldr r1, _080D42A0 @ =0x0000C20C
	b _080D433A
	.align 2, 0
_080D429C: .4byte 0x0000C20D
_080D42A0: .4byte 0x0000C20C
_080D42A4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D42B8
	b _080D43B6
_080D42B8:
	ldr r1, _080D42BC @ =0x0000C201
	b _080D433A
	.align 2, 0
_080D42BC: .4byte 0x0000C201
_080D42C0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	b _080D4336
_080D42D4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D42F0 @ =0x0000C206
	adds r0, r4, #0
	bl SetMotion
	b _080D4344
	.align 2, 0
_080D42F0: .4byte 0x0000C206
_080D42F4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	b _080D4330
_080D4302:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D4320 @ =0x0000C201
	adds r0, r4, #0
	bl SetMotion
	b _080D4344
	.align 2, 0
_080D4320: .4byte 0x0000C201
_080D4324:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
_080D4330:
	ands r0, r1
	cmp r0, #0
	beq _080D43B6
_080D4336:
	movs r1, #0xc2
	lsls r1, r1, #8
_080D433A:
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
_080D4344:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D43B6
_080D434C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D4390 @ =0x0000C206
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D436C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r2, #0
	ldr r0, [r4, #0x18]
	ldr r0, [r0, #4]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080D4382
	movs r2, #1
_080D4382:
	cmp r2, #0
	beq _080D4394
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080D439A
	.align 2, 0
_080D4390: .4byte 0x0000C206
_080D4394:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080D439A:
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
_080D43B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Actor36_Update
Actor36_Update: @ 0x080D43BC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _080D43CC
	cmp r0, #1
	beq _080D4430
	b _080D4436
_080D43CC:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r4, #0xc2
	ldr r0, _080D443C @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x88
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4440 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #5
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0xc2
	lsls r4, r4, #2
	ldr r2, _080D4444 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D4448 @ =gStaticMotionGraphics+12
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
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4430:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D4436:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D443C: .4byte wStaticGraphicTilenums
_080D4440: .4byte wStaticMotionPalIDs
_080D4444: .4byte gStaticMotionGraphics
_080D4448: .4byte gStaticMotionGraphics+12

	thumb_func_start Actor37_Update
Actor37_Update: @ 0x080D444C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bls _080D4458
	b _080D45E4
_080D4458:
	lsls r0, r0, #2
	ldr r1, _080D4464 @ =_080D4468
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4464: .4byte _080D4468
_080D4468: @ jump table
	.4byte _080D447C @ case 0
	.4byte _080D454C @ case 1
	.4byte _080D459C @ case 2
	.4byte _080D45BC @ case 3
	.4byte _080D45E4 @ case 4
_080D447C:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	bne _080D44F4
	movs r4, #0x82
	ldr r0, _080D44E4 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x98
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D44E8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0x82
	lsls r4, r4, #2
	ldr r2, _080D44EC @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D44F0 @ =gStaticMotionGraphics+12
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
	movs r1, #0x82
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	b _080D4546
	.align 2, 0
_080D44E4: .4byte wStaticGraphicTilenums
_080D44E8: .4byte wStaticMotionPalIDs
_080D44EC: .4byte gStaticMotionGraphics
_080D44F0: .4byte gStaticMotionGraphics+12
_080D44F4:
	movs r4, #0x8c
	ldr r1, _080D4584 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D4588 @ =0x00000296
	strh r0, [r1]
	ldr r5, _080D458C @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0x8c
	lsls r4, r4, #2
	ldr r2, _080D4590 @ =gStaticMotionGraphics
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
	ldr r0, _080D4594 @ =gStaticMotionGraphics+12
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
	ldr r1, _080D4598 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
_080D4546:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D454C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D45E4
	movs r2, #0
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
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D45DE
	.align 2, 0
_080D4584: .4byte wStaticGraphicTilenums
_080D4588: .4byte 0x00000296
_080D458C: .4byte wStaticMotionPalIDs
_080D4590: .4byte gStaticMotionGraphics
_080D4594: .4byte gStaticMotionGraphics+12
_080D4598: .4byte 0x00008C05
_080D459C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D45E4
	ldr r1, _080D45B8 @ =0x00008C07
	adds r0, r6, #0
	bl SetMotion
	b _080D45DE
	.align 2, 0
_080D45B8: .4byte 0x00008C07
_080D45BC:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, [r6, #0x54]
	ldr r0, _080D45EC @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldr r0, _080D45F0 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D45F4 @ =0xFFFF7000
	adds r0, r0, r2
	cmp r1, r0
	bge _080D45E4
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
_080D45DE:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D45E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D45EC: .4byte 0xFFFFFF00
_080D45F0: .4byte gStageRun+232
_080D45F4: .4byte 0xFFFF7000

	thumb_func_start Actor38_Update
Actor38_Update: @ 0x080D45F8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D467C
	cmp r0, #1
	ble _080D4608
	b _080D4752
_080D4608:
	cmp r0, #0
	beq _080D460E
	b _080D4752
_080D460E:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D4720 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4724 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	movs r6, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4728 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #7
	strh r0, [r5]
	ldr r4, _080D472C @ =0x00000654
	ldr r2, _080D4730 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	ldr r0, _080D4734 @ =gStaticMotionGraphics+12
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
	adds r1, r7, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D467C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r5, _080D4738 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	ldr r1, [r7, #0x5c]
	adds r4, r1, r0
	str r4, [r7, #0x54]
	lsls r0, r2, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r7, #0x68]
	adds r3, r1, r0
	str r3, [r7, #0x58]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne _080D46C2
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl FUN_080c5628
_080D46C2:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4744
	ldrb r1, [r7, #0x13]
	adds r1, #1
	strb r1, [r7, #0x13]
	ldr r2, [r7, #0x5c]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r2, r3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	subs r2, r2, r1
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x68]
	ldr r2, _080D473C @ =0xFFFFFF00
	adds r0, r0, r2
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4740 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080D4752
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D4752
	.align 2, 0
_080D4720: .4byte 0xFFFFB000
_080D4724: .4byte wStaticGraphicTilenums
_080D4728: .4byte wStaticMotionPalIDs
_080D472C: .4byte 0x00000654
_080D4730: .4byte gStaticMotionGraphics
_080D4734: .4byte gStaticMotionGraphics+12
_080D4738: .4byte gSineTable
_080D473C: .4byte 0xFFFFFF00
_080D4740: .4byte gStageRun+232
_080D4744:
	ldr r0, [r7, #0x68]
	lsls r1, r0, #7
	subs r1, r1, r0
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	asrs r1, r1, #7
	str r1, [r7, #0x68]
_080D4752:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Actor39_Update
Actor39_Update: @ 0x080D4758
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #9
	bls _080D4768
	b _080D4976
_080D4768:
	lsls r0, r0, #2
	ldr r1, _080D4774 @ =_080D4778
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4774: .4byte _080D4778
_080D4778: @ jump table
	.4byte _080D47A0 @ case 0
	.4byte _080D47B8 @ case 1
	.4byte _080D481C @ case 2
	.4byte _080D4870 @ case 3
	.4byte _080D48A2 @ case 4
	.4byte _080D48D0 @ case 5
	.4byte _080D48FE @ case 6
	.4byte _080D4930 @ case 7
	.4byte _080D4954 @ case 8
	.4byte _080D4976 @ case 9
_080D47A0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	adds r0, r7, #0
	movs r1, #0
	bl SetMotion
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D47B8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	bne _080D47CE
	b _080D4976
_080D47CE:
	ldrb r1, [r7, #0xa]
	movs r0, #4
	movs r6, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080D4818 @ =sCollisions_08370C68
	adds r5, r7, #0
	adds r5, #0x54
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, #0
	bl SetMotion
	ldrb r2, [r7, #0xa]
	lsrs r2, r2, #4
	mov r1, r8
	ands r2, r1
	adds r0, r5, #0
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	str r6, [r7, #0x2c]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	b _080D4970
	.align 2, 0
_080D4818: .4byte sCollisions_08370C68
_080D481C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	bne _080D4830
	adds r0, r7, #0
	bl CreateAfterImages
	str r0, [r7, #0x2c]
_080D4830:
	ldr r0, [r7, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D484A
	b _080D4976
_080D484A:
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	beq _080D4852
	strb r1, [r0, #0x11]
_080D4852:
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xa
	bl PlaySound
	movs r0, #0xf0
	lsls r0, r0, #2
	str r0, [r7, #0x5c]
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	b _080D4970
_080D4870:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, [r7, #0x60]
	adds r1, r1, r2
	str r1, [r7, #0x58]
	adds r2, #0x40
	str r2, [r7, #0x60]
	bl PushoutToUp1
	cmp r0, #0
	beq _080D4976
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	movs r0, #0
	str r0, [r7, #0x60]
	b _080D4970
_080D48A2:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #4
	subs r1, r1, r0
	asrs r1, r1, #4
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4976
	adds r0, r7, #0
	movs r1, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r7, #0x12]
	b _080D4970
_080D48D0:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D4976
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	b _080D4970
_080D48FE:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	asrs r1, r1, #2
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	cmp r1, #3
	bgt _080D4976
	ldr r1, _080D492C @ =0x00003F05
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	b _080D4970
	.align 2, 0
_080D492C: .4byte 0x00003F05
_080D4930:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D4976
	ldr r1, _080D4950 @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r7, #0x12]
	b _080D4970
	.align 2, 0
_080D4950: .4byte 0x00003501
_080D4954:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D4968
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _080D4976
_080D4968:
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D4970:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D4976:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
