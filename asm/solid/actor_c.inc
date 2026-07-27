	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
