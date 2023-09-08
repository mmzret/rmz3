	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateSeaLevelButton
CreateSeaLevelButton: @ 0x080DFEA4
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080DFEFC @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080DFEF2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r0, _080DFF00 @ =gSolidFnTable
	movs r1, #0x36
	strb r1, [r3, #9]
	adds r0, #0xd8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x10]
_080DFEF2:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080DFEFC: .4byte gSolidHeaderPtr
_080DFF00: .4byte gSolidFnTable

	thumb_func_start SeaLevelButton_Init
SeaLevelButton_Init: @ 0x080DFF04
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #2
	movs r7, #0
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0x5c
	str r4, [r0, #4]
	str r4, [r5, #0x5c]
	ldr r0, _080DFF68 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080DFF74
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DFF6C @ =0x08371974
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080DFF70 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	b _080DFF84
	.align 2, 0
_080DFF68: .4byte gCurStory
_080DFF6C: .4byte 0x08371974
_080DFF70: .4byte gSolidFnTable
_080DFF74:
	ldr r1, _080DFF8C @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_080DFF84:
	str r0, [r5, #0x14]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DFF8C: .4byte gSolidFnTable

	thumb_func_start SeaLevelButton_Update
SeaLevelButton_Update: @ 0x080DFF90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0
	beq _080DFFAC
	cmp r0, #1
	beq _080E007E
	adds r5, r7, #0
	adds r5, #0x8c
	b _080E0166
_080DFFAC:
	ldr r0, _080E00C4 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	adds r5, r7, #0
	adds r5, #0x8c
	cmp r0, r1
	bls _080DFFC4
	b _080E0166
_080DFFC4:
	ldr r1, _080E00C8 @ =gCurStory
	ldr r0, _080E00CC @ =0x083719B4
	mov sl, r0
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	add r0, sl
	ldrh r2, [r0]
	lsrs r0, r2, #3
	adds r1, #4
	mov r8, r1
	add r0, r8
	ldrb r1, [r0]
	movs r0, #7
	mov sb, r0
	ands r0, r2
	asrs r1, r0
	movs r6, #1
	ands r1, r6
	strb r1, [r7, #0x12]
	ldr r4, _080E00D0 @ =0x00000E24
	ldr r1, _080E00D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080E00D8 @ =wStaticGraphicTilenums
	movs r5, #0xb5
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
	ldr r0, _080E00DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080E00E0 @ =wStaticMotionPalIDs
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
	ldrb r0, [r7, #0xa]
	movs r4, #0
	orrs r0, r6
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r0, [r7, #0x12]
	movs r1, #0xb5
	lsls r1, r1, #8
	cmp r0, #0
	beq _080E0042
	adds r1, #1
_080E0042:
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xb]
	movs r1, #8
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	add r0, sl
	ldrh r2, [r0]
	lsrs r0, r2, #3
	add r0, r8
	ldrb r1, [r0]
	mov r0, sb
	ands r0, r2
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #3
	ldr r0, _080E00E4 @ =0x083719A4
	adds r1, r1, r0
	str r1, [r7, #0x30]
	movs r1, #0
	ldr r0, _080E00E8 @ =0x00002001
	strh r0, [r7, #0x26]
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080E007E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #4
	ands r2, r0
	adds r5, r1, #0
	cmp r2, #0
	beq _080E00EC
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r6, _080E00C8 @ =gCurStory
	ldr r4, _080E00CC @ =0x083719B4
	cmp r0, #0x1d
	bls _080E00F2
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	lsrs r2, r3, #3
	adds r0, r6, #4
	adds r2, r2, r0
	movs r1, #7
	ands r1, r3
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _080E00F2
	.align 2, 0
_080E00C4: .4byte gStageRun+232
_080E00C8: .4byte gCurStory
_080E00CC: .4byte 0x083719B4
_080E00D0: .4byte 0x00000E24
_080E00D4: .4byte gStaticMotionGraphics
_080E00D8: .4byte wStaticGraphicTilenums
_080E00DC: .4byte gStaticMotionGraphics+12
_080E00E0: .4byte wStaticMotionPalIDs
_080E00E4: .4byte 0x083719A4
_080E00E8: .4byte 0x00002001
_080E00EC:
	strb r2, [r7, #0x13]
	ldr r6, _080E01CC @ =gCurStory
	ldr r4, _080E01D0 @ =0x083719B4
_080E00F2:
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	lsrs r0, r2, #3
	adds r1, r6, #4
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r2
	asrs r1, r0
	movs r2, #1
	ands r1, r2
	adds r4, r7, #0
	adds r4, #0x54
	cmp r1, #0
	beq _080E0142
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080E0142
	strb r2, [r7, #0x12]
	movs r0, #4
	adds r1, r4, #0
	bl AppendQuake
	movs r0, #0x91
	bl PlaySound
	ldr r1, _080E01D4 @ =0x0000B501
	adds r0, r7, #0
	bl SetMotion
	ldrb r1, [r7, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldr r0, _080E01D8 @ =0x083719AC
	str r0, [r7, #0x30]
	ldr r0, _080E01DC @ =0x00002001
	strh r0, [r7, #0x26]
_080E0142:
	ldr r0, _080E01E0 @ =gStageRun+232
	adds r1, r4, #0
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bls _080E0166
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	strb r0, [r7, #0xa]
	ldrb r1, [r7, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7, #0xb]
	strb r2, [r7, #0xd]
_080E0166:
	ldr r0, [r5]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080E01BE
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r7, #0xa]
	str r1, [r5]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r1, [r7, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7, #0xb]
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r1, _080E01E4 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl SeaLevelButton_Die
_080E01BE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E01CC: .4byte gCurStory
_080E01D0: .4byte 0x083719B4
_080E01D4: .4byte 0x0000B501
_080E01D8: .4byte 0x083719AC
_080E01DC: .4byte 0x00002001
_080E01E0: .4byte gStageRun+232
_080E01E4: .4byte gSolidFnTable

	thumb_func_start SeaLevelButton_Die
SeaLevelButton_Die: @ 0x080E01E8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _080E01F8
	cmp r0, #1
	beq _080E0274
	b _080E02A0
_080E01F8:
	ldr r0, _080E02A8 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bhi _080E02A0
	ldr r4, _080E02AC @ =0x00000E24
	ldr r1, _080E02B0 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080E02B4 @ =wStaticGraphicTilenums
	movs r5, #0xb5
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
	ldr r0, _080E02B8 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080E02BC @ =wStaticMotionPalIDs
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
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080E02C0 @ =0x0000B502
	adds r0, r6, #0
	bl SetMotion
	ldrb r1, [r6, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r0, _080E02C4 @ =0x083719AC
	str r0, [r6, #0x30]
	ldr r0, _080E02C8 @ =0x00002001
	strh r0, [r6, #0x26]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080E0274:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080E02A8 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bls _080E02A0
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	strb r0, [r6, #0xa]
	ldrb r1, [r6, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r6, #0xb]
	strb r2, [r6, #0xd]
_080E02A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E02A8: .4byte gStageRun+232
_080E02AC: .4byte 0x00000E24
_080E02B0: .4byte gStaticMotionGraphics
_080E02B4: .4byte wStaticGraphicTilenums
_080E02B8: .4byte gStaticMotionGraphics+12
_080E02BC: .4byte wStaticMotionPalIDs
_080E02C0: .4byte 0x0000B502
_080E02C4: .4byte 0x083719AC
_080E02C8: .4byte 0x00002001
