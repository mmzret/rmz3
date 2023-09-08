	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e83d0
FUN_080e83d0: @ 0x080E83D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, [sp, #0x20]
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _080E8444 @ =gWidgetHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E8436
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E8448 @ =gWidgetFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	mov r0, r8
	str r0, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
	ldr r0, [sp, #0x18]
	str r0, [r3, #0x54]
	ldr r0, [sp, #0x1c]
	str r0, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0x78
	strh r6, [r0]
	adds r0, #5
	strb r7, [r0]
	adds r0, #2
	strb r1, [r0]
_080E8436:
	adds r0, r3, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E8444: .4byte gWidgetHeaderPtr
_080E8448: .4byte gWidgetFnTable

	thumb_func_start FUN_080e844c
FUN_080e844c: @ 0x080E844C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, [sp, #0x20]
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _080E84C0 @ =gWidgetHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E84B4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E84C4 @ =gWidgetFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	mov r0, r8
	str r0, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
	ldr r0, [sp, #0x18]
	str r0, [r3, #0x54]
	ldr r0, [sp, #0x1c]
	str r0, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0x78
	strh r6, [r0]
	adds r0, #5
	strb r7, [r0]
	adds r1, #0x5d
	movs r0, #1
	strb r0, [r1]
_080E84B4:
	adds r0, r3, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E84C0: .4byte gWidgetHeaderPtr
_080E84C4: .4byte gWidgetFnTable

	thumb_func_start MenuComp13_Init
MenuComp13_Init: @ 0x080E84C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	str r0, [sp, #0xc]
	ldr r1, _080E8550 @ =gWidgetFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldrb r0, [r6, #0x10]
	cmp r0, #0xa6
	bne _080E8512
	ldr r0, _080E8554 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xc]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E8512
	adds r1, r6, #0
	adds r1, #0x78
	movs r0, #0xbd
	lsls r0, r0, #8
	strh r0, [r1]
	ldr r0, [r6, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r6, #0x58]
_080E8512:
	ldrb r0, [r6, #0x10]
	adds r7, r6, #0
	adds r7, #0x78
	movs r2, #0x7d
	adds r2, r2, r6
	mov sl, r2
	cmp r0, #0xa7
	bne _080E8538
	ldr r0, _080E8554 @ =gSystemSavedataManager
	ldrb r1, [r0, #9]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080E8538
	ldr r0, _080E8558 @ =0x0000BB03
	strh r0, [r7]
	mov r3, sl
	strb r2, [r3]
_080E8538:
	ldrh r1, [r7]
	ldr r0, _080E855C @ =0x0000B00A
	cmp r1, r0
	bne _080E856C
	ldr r0, _080E8554 @ =gSystemSavedataManager
	adds r0, #0x4b
	ldrb r0, [r0]
	cmp r0, #1
	bne _080E8564
	ldr r0, _080E8560 @ =0x0000B10A
	b _080E856A
	.align 2, 0
_080E8550: .4byte gWidgetFnTable
_080E8554: .4byte gSystemSavedataManager
_080E8558: .4byte 0x0000BB03
_080E855C: .4byte 0x0000B00A
_080E8560: .4byte 0x0000B10A
_080E8564:
	cmp r0, #2
	bne _080E856C
	ldr r0, _080E8584 @ =0x0000B20A
_080E856A:
	strh r0, [r7]
_080E856C:
	ldrh r1, [r7]
	ldr r0, _080E8588 @ =0x0000AA04
	cmp r1, r0
	bne _080E859C
	ldr r0, _080E858C @ =gSystemSavedataManager
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #1
	bne _080E8594
	ldr r0, _080E8590 @ =0x0000AB04
	b _080E859A
	.align 2, 0
_080E8584: .4byte 0x0000B20A
_080E8588: .4byte 0x0000AA04
_080E858C: .4byte gSystemSavedataManager
_080E8590: .4byte 0x0000AB04
_080E8594:
	cmp r0, #2
	bne _080E859C
	ldr r0, _080E863C @ =0x0000AC04
_080E859A:
	strh r0, [r7]
_080E859C:
	ldrb r0, [r6, #0x10]
	subs r0, #0x14
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x49
	bhi _080E865C
	ldr r0, _080E8640 @ =wDynamicGraphicTilenums
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x7a
	strh r0, [r1]
	ldr r0, _080E8644 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #4
	strb r0, [r1]
	ldr r0, _080E8648 @ =wStaticGraphicTilenums
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080E864C @ =wStaticMotionPalIDs
	adds r0, r0, r2
	movs r4, #6
	strh r4, [r0]
	ldrh r2, [r7]
	lsrs r2, r2, #8
	subs r2, #0x8f
	strh r2, [r7]
	ldr r3, _080E8650 @ =gUnlockedElfPtr
	ldrb r0, [r6, #0x10]
	ldr r3, [r3]
	adds r0, r0, r3
	subs r0, #0x14
	ldr r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1e
	subs r2, r2, r0
	strh r2, [r7]
	ldrh r2, [r7]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, _080E8654 @ =gElfMugshotGraphics
	adds r0, r0, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl RequestGraphicTransfer
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080E8658 @ =gElfMugshotGraphics+12
	adds r0, r0, r1
	ldrb r1, [r0, #7]
	subs r4, r4, r1
	lsls r4, r4, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r4, r4, r2
	adds r1, r4, #0
	bl LoadPalette
	movs r0, #0x8f
	lsls r0, r0, #8
	strh r0, [r7]
	movs r3, #0x7f
	adds r3, r3, r6
	mov sb, r3
	b _080E8794
	.align 2, 0
_080E863C: .4byte 0x0000AC04
_080E8640: .4byte wDynamicGraphicTilenums
_080E8644: .4byte wDynamicMotionPalIDs
_080E8648: .4byte wStaticGraphicTilenums
_080E864C: .4byte wStaticMotionPalIDs
_080E8650: .4byte gUnlockedElfPtr
_080E8654: .4byte gElfMugshotGraphics
_080E8658: .4byte gElfMugshotGraphics+12
_080E865C:
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080E86A8
	ldr r2, _080E86A0 @ =wDynamicGraphicTilenums
	ldrh r0, [r7]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x7a
	strh r0, [r1]
	ldr r3, _080E86A4 @ =wDynamicMotionPalIDs
	ldrh r0, [r7]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r1, #4
	strb r0, [r1]
	ldrh r0, [r7]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r2, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r2]
	adds r0, r0, r3
	movs r1, #6
	strh r1, [r0]
	movs r0, #0x7f
	adds r0, r0, r6
	mov sb, r0
	b _080E8794
	.align 2, 0
_080E86A0: .4byte wDynamicGraphicTilenums
_080E86A4: .4byte wDynamicMotionPalIDs
_080E86A8:
	ldr r3, _080E8730 @ =wStaticGraphicTilenums
	ldrh r0, [r7]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x7a
	strh r0, [r1]
	ldr r1, _080E8734 @ =wStaticMotionPalIDs
	mov r8, r1
	ldrh r0, [r7]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x7e
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	mov sb, r1
	cmp r0, #0
	beq _080E8740
	ldrh r0, [r7]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r2, r0, r3
	movs r1, #0xc0
	lsls r1, r1, #2
	strh r1, [r2]
	add r0, r8
	movs r1, #7
	strh r1, [r0]
	ldrh r4, [r7]
	lsrs r4, r4, #8
	lsls r5, r4, #2
	adds r5, r5, r4
	lsls r5, r5, #2
	ldr r2, _080E8738 @ =gStaticMotionGraphics
	adds r0, r5, r2
	lsls r4, r4, #1
	adds r1, r4, r3
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	ldr r0, _080E873C @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	add r4, r8
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r5, #0
	bl LoadPalette
	b _080E8794
	.align 2, 0
_080E8730: .4byte wStaticGraphicTilenums
_080E8734: .4byte wStaticMotionPalIDs
_080E8738: .4byte gStaticMotionGraphics
_080E873C: .4byte gStaticMotionGraphics+12
_080E8740:
	ldrh r0, [r7]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r2, r0, r3
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r2]
	add r0, r8
	movs r1, #6
	strh r1, [r0]
	ldrh r4, [r7]
	lsrs r4, r4, #8
	lsls r5, r4, #2
	adds r5, r5, r4
	lsls r5, r5, #2
	ldr r1, _080E87B0 @ =gStaticMotionGraphics
	adds r0, r5, r1
	lsls r4, r4, #1
	adds r1, r4, r3
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r3, _080E87B4 @ =gStaticMotionGraphics+12
	adds r5, r5, r3
	add r4, r8
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadPalette
_080E8794:
	ldrb r0, [r6, #0x10]
	cmp r0, #0x13
	bhi _080E87C8
	adds r0, r6, #0
	bl InitScalerotMotion1
	ldrb r0, [r6, #0x10]
	cmp r0, #5
	bhi _080E87B8
	adds r0, r6, #0
	adds r0, #0x50
	movs r1, #0xf0
	lsls r1, r1, #1
	b _080E87C0
	.align 2, 0
_080E87B0: .4byte gStaticMotionGraphics
_080E87B4: .4byte gStaticMotionGraphics+12
_080E87B8:
	adds r0, r6, #0
	adds r0, #0x50
	movs r1, #0xf4
	lsls r1, r1, #1
_080E87C0:
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	b _080E87CE
_080E87C8:
	adds r0, r6, #0
	bl InitNonAffineMotion
_080E87CE:
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080E87DA
	adds r0, r6, #0
	bl ResetDynamicMotion
_080E87DA:
	ldrh r1, [r7]
	adds r0, r6, #0
	bl SetMotion
	ldrb r1, [r6, #0xa]
	movs r0, #2
	movs r4, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	mov r2, sl
	ldrb r1, [r2]
	adds r1, #6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl ForceEntityPalette
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x7c
	strb r4, [r0]
	adds r0, #4
	strb r4, [r0]
	mov r3, sb
	ldrb r2, [r3]
	adds r4, r0, #0
	cmp r2, #0
	bne _080E8864
	ldrb r0, [r6, #0x10]
	cmp r0, #0x77
	bne _080E8864
	adds r1, r0, #0
	ldr r3, _080E88A8 @ =0x00006401
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [sp, #0xc]
	movs r2, #0
	bl FUN_080e844c
_080E8864:
	ldrb r0, [r6, #0x10]
	cmp r0, #0x74
	bne _080E886E
	movs r0, #0x14
	strb r0, [r4]
_080E886E:
	ldrb r0, [r6, #0x10]
	cmp r0, #0x73
	bne _080E8878
	movs r0, #0xf
	strb r0, [r4]
_080E8878:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080E8892
	mov r2, sl
	ldrb r1, [r2]
	adds r1, #6
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	orrs r1, r2
	bl LoadBlink
_080E8892:
	adds r0, r6, #0
	bl MenuComp13_Update
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E88A8: .4byte 0x00006401

	thumb_func_start MenuComp13_Update
MenuComp13_Update: @ 0x080E88AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, _080E88F8 @ =0x00000DCC
	adds r0, r5, r1
	ldrb r0, [r0, #0xd]
	cmp r0, #0
	beq _080E88C0
	bl _080E9504
_080E88C0:
	adds r1, r4, #0
	adds r1, #0x80
	ldrb r0, [r1]
	cmp r0, #0
	beq _080E88CE
	bl GetBlinkMotionState
_080E88CE:
	ldrb r0, [r5, #2]
	cmp r0, #2
	bne _080E88DE
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	bhi _080E88DE
	movs r0, #3
	strb r0, [r4, #0xd]
_080E88DE:
	ldrb r0, [r4, #0x10]
	cmp r0, #0xb0
	beq _080E88E6
	b _080E8A70
_080E88E6:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xc
	bls _080E88EE
	b _080E8A70
_080E88EE:
	lsls r0, r0, #2
	ldr r1, _080E88FC @ =_080E8900
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E88F8: .4byte 0x00000DCC
_080E88FC: .4byte _080E8900
_080E8900: @ jump table
	.4byte _080E8934 @ case 0
	.4byte _080E893E @ case 1
	.4byte _080E895E @ case 2
	.4byte _080E8970 @ case 3
	.4byte _080E898E @ case 4
	.4byte _080E89A8 @ case 5
	.4byte _080E89C2 @ case 6
	.4byte _080E89D2 @ case 7
	.4byte _080E89F0 @ case 8
	.4byte _080E8A0C @ case 9
	.4byte _080E8A30 @ case 10
	.4byte _080E8A46 @ case 11
	.4byte _080E8A70 @ case 12
_080E8934:
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E893E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E894E
	b _080E8A70
_080E894E:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #1
	b _080E8A62
_080E895E:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080E896A
	b _080E8A70
_080E896A:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _080E8A6A
_080E8970:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E8A70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x16
	b _080E8A62
_080E898E:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8A70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x17
	b _080E8A62
_080E89A8:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8A70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x18
	b _080E8A62
_080E89C2:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8A70
	movs r0, #8
	strb r0, [r4, #0x12]
	b _080E8A6A
_080E89D2:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E8A70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x10
	b _080E8A62
_080E89F0:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _080E8A70
	ldr r0, [r4, #0x58]
	ldr r2, _080E8A08 @ =0xFFFFE900
	adds r0, r0, r2
	str r0, [r4, #0x58]
	b _080E8A6A
	.align 2, 0
_080E8A08: .4byte 0xFFFFE900
_080E8A0C:
	ldr r0, [r4, #0x54]
	subs r0, #0x60
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _080E8A70
	ldr r0, [r4, #0x58]
	ldr r1, _080E8A2C @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _080E8A6A
	.align 2, 0
_080E8A2C: .4byte 0xFFFFF400
_080E8A30:
	ldr r0, [r4, #0x54]
	subs r0, #0x60
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8A70
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _080E8A6A
_080E8A46:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E8A70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xa
_080E8A62:
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
_080E8A6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E8A70:
	ldrb r0, [r4, #0x10]
	cmp r0, #0xb1
	beq _080E8A78
	b _080E8F70
_080E8A78:
	ldrb r0, [r4, #0xe]
	cmp r0, #0x70
	bls _080E8A80
	b _080E8F70
_080E8A80:
	lsls r0, r0, #2
	ldr r1, _080E8A8C @ =_080E8A90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E8A8C: .4byte _080E8A90
_080E8A90: @ jump table
	.4byte _080E8C54 @ case 0
	.4byte _080E8C66 @ case 1
	.4byte _080E8C88 @ case 2
	.4byte _080E8CA4 @ case 3
	.4byte _080E8CD2 @ case 4
	.4byte _080E8CF0 @ case 5
	.4byte _080E8D0E @ case 6
	.4byte _080E8D20 @ case 7
	.4byte _080E8D6C @ case 8
	.4byte _080E8DA6 @ case 9
	.4byte _080E8DE0 @ case 10
	.4byte _080E8E18 @ case 11
	.4byte _080E8F70 @ case 12
	.4byte _080E8F70 @ case 13
	.4byte _080E8F70 @ case 14
	.4byte _080E8F70 @ case 15
	.4byte _080E8F70 @ case 16
	.4byte _080E8F70 @ case 17
	.4byte _080E8F70 @ case 18
	.4byte _080E8F70 @ case 19
	.4byte _080E8F70 @ case 20
	.4byte _080E8F70 @ case 21
	.4byte _080E8F70 @ case 22
	.4byte _080E8F70 @ case 23
	.4byte _080E8F70 @ case 24
	.4byte _080E8F70 @ case 25
	.4byte _080E8F70 @ case 26
	.4byte _080E8F70 @ case 27
	.4byte _080E8F70 @ case 28
	.4byte _080E8F70 @ case 29
	.4byte _080E8F70 @ case 30
	.4byte _080E8F70 @ case 31
	.4byte _080E8F70 @ case 32
	.4byte _080E8F70 @ case 33
	.4byte _080E8F70 @ case 34
	.4byte _080E8F70 @ case 35
	.4byte _080E8F70 @ case 36
	.4byte _080E8F70 @ case 37
	.4byte _080E8F70 @ case 38
	.4byte _080E8F70 @ case 39
	.4byte _080E8F70 @ case 40
	.4byte _080E8F70 @ case 41
	.4byte _080E8F70 @ case 42
	.4byte _080E8F70 @ case 43
	.4byte _080E8F70 @ case 44
	.4byte _080E8F70 @ case 45
	.4byte _080E8F70 @ case 46
	.4byte _080E8F70 @ case 47
	.4byte _080E8F70 @ case 48
	.4byte _080E8F70 @ case 49
	.4byte _080E8F70 @ case 50
	.4byte _080E8F70 @ case 51
	.4byte _080E8F70 @ case 52
	.4byte _080E8F70 @ case 53
	.4byte _080E8F70 @ case 54
	.4byte _080E8F70 @ case 55
	.4byte _080E8F70 @ case 56
	.4byte _080E8F70 @ case 57
	.4byte _080E8F70 @ case 58
	.4byte _080E8F70 @ case 59
	.4byte _080E8F70 @ case 60
	.4byte _080E8F70 @ case 61
	.4byte _080E8F70 @ case 62
	.4byte _080E8F70 @ case 63
	.4byte _080E8F70 @ case 64
	.4byte _080E8F70 @ case 65
	.4byte _080E8F70 @ case 66
	.4byte _080E8F70 @ case 67
	.4byte _080E8F70 @ case 68
	.4byte _080E8F70 @ case 69
	.4byte _080E8F70 @ case 70
	.4byte _080E8F70 @ case 71
	.4byte _080E8F70 @ case 72
	.4byte _080E8F70 @ case 73
	.4byte _080E8F70 @ case 74
	.4byte _080E8F70 @ case 75
	.4byte _080E8F70 @ case 76
	.4byte _080E8F70 @ case 77
	.4byte _080E8F70 @ case 78
	.4byte _080E8F70 @ case 79
	.4byte _080E8F70 @ case 80
	.4byte _080E8F70 @ case 81
	.4byte _080E8F70 @ case 82
	.4byte _080E8F70 @ case 83
	.4byte _080E8F70 @ case 84
	.4byte _080E8F70 @ case 85
	.4byte _080E8F70 @ case 86
	.4byte _080E8F70 @ case 87
	.4byte _080E8F70 @ case 88
	.4byte _080E8F70 @ case 89
	.4byte _080E8F70 @ case 90
	.4byte _080E8F70 @ case 91
	.4byte _080E8F70 @ case 92
	.4byte _080E8F70 @ case 93
	.4byte _080E8F70 @ case 94
	.4byte _080E8F70 @ case 95
	.4byte _080E8F70 @ case 96
	.4byte _080E8F70 @ case 97
	.4byte _080E8F70 @ case 98
	.4byte _080E8F70 @ case 99
	.4byte _080E8E4E @ case 100
	.4byte _080E8E58 @ case 101
	.4byte _080E8E7A @ case 102
	.4byte _080E8E96 @ case 103
	.4byte _080E8EBC @ case 104
	.4byte _080E8EE6 @ case 105
	.4byte _080E8EBC @ case 106
	.4byte _080E8EE6 @ case 107
	.4byte _080E8EBC @ case 108
	.4byte _080E8EE6 @ case 109
	.4byte _080E8EBC @ case 110
	.4byte _080E8F10 @ case 111
	.4byte _080E8F4E @ case 112
_080E8C54:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x74]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E8C66:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E8C76
	b _080E8F70
_080E8C76:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xc
	orrs r1, r0
	b _080E8F64
_080E8C88:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080E8C98
	b _080E8F70
_080E8C98:
	ldr r0, _080E8CA0 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
	b _080E8F6A
	.align 2, 0
_080E8CA0: .4byte 0xFFFFFC00
_080E8CA4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r1, #0x38
	str r1, [r4, #0x5c]
	cmp r1, #0x80
	bgt _080E8CB6
	b _080E8F70
_080E8CB6:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xd
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r4, #0x12]
	b _080E8F6A
_080E8CD2:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080E8CDE
	b _080E8F70
_080E8CDE:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xe
	orrs r1, r0
	b _080E8F64
_080E8CF0:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080E8CFC
	b _080E8F70
_080E8CFC:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xf
	orrs r1, r0
	b _080E8F64
_080E8D0E:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080E8D1A
	b _080E8F70
_080E8D1A:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _080E8F6A
_080E8D20:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E8D30
	b _080E8F70
_080E8D30:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x11
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080E8D68 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	b _080E8F6A
	.align 2, 0
_080E8D68: .4byte 0xFFFFFC00
_080E8D6C:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080E8D7C
	b _080E8F70
_080E8D7C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	adds r0, #0xc0
	str r0, [r4, #0x54]
	cmp r1, #0
	bgt _080E8D94
	b _080E8F70
_080E8D94:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x12
	orrs r1, r0
	b _080E8F64
_080E8DA6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x68]
	cmp r1, r0
	bgt _080E8DC4
	b _080E8F70
_080E8DC4:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x13
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x68]
	str r0, [r4, #0x58]
	b _080E8F6A
_080E8DE0:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _080E8DF0
	b _080E8F70
_080E8DF0:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #3
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, _080E8E14 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	b _080E8F6A
	.align 2, 0
_080E8E14: .4byte 0xFFFFFD00
_080E8E18:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x68]
	cmp r1, r0
	bgt _080E8E34
	b _080E8F70
_080E8E34:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x68]
	str r0, [r4, #0x58]
	movs r0, #0x64
	b _080E8F6E
_080E8E4E:
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E8E58:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E8E68
	b _080E8F70
_080E8E68:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x16
	orrs r1, r0
	b _080E8F64
_080E8E7A:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8F70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x17
	orrs r1, r0
	b _080E8F64
_080E8E96:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8F70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x18
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _080E8F6A
_080E8EBC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E8F70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x19
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _080E8F6A
_080E8EE6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E8F70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x18
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _080E8F6A
_080E8F10:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8F70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x1a
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080E8F6A
_080E8F4E:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E8F70
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
_080E8F64:
	adds r0, r4, #0
	bl SetMotion
_080E8F6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
_080E8F6E:
	strb r0, [r4, #0xe]
_080E8F70:
	ldrb r0, [r4, #0x10]
	cmp r0, #0xb2
	beq _080E8F78
	b _080E917C
_080E8F78:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xe
	bls _080E8F80
	b _080E917C
_080E8F80:
	lsls r0, r0, #2
	ldr r1, _080E8F8C @ =_080E8F90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E8F8C: .4byte _080E8F90
_080E8F90: @ jump table
	.4byte _080E8FCC @ case 0
	.4byte _080E8FD6 @ case 1
	.4byte _080E9000 @ case 2
	.4byte _080E902E @ case 3
	.4byte _080E905A @ case 4
	.4byte _080E9080 @ case 5
	.4byte _080E909A @ case 6
	.4byte _080E90B4 @ case 7
	.4byte _080E90CE @ case 8
	.4byte _080E90E8 @ case 9
	.4byte _080E90FA @ case 10
	.4byte _080E9124 @ case 11
	.4byte _080E9142 @ case 12
	.4byte _080E9152 @ case 13
	.4byte _080E917C @ case 14
_080E8FCC:
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E8FD6:
	ldr r0, [r4, #0x54]
	subs r0, #0x80
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E8FEC
	b _080E917C
_080E8FEC:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #1
	b _080E916E
_080E9000:
	ldr r0, [r4, #0x54]
	subs r0, #0x40
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E9016
	b _080E917C
_080E9016:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _080E9176
_080E902E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E903E
	b _080E917C
_080E903E:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #4
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	b _080E9176
_080E905A:
	ldr r0, [r4, #0x58]
	subs r0, #0x20
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E9070
	b _080E917C
_080E9070:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #5
	b _080E916E
_080E9080:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E917C
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #9
	b _080E916E
_080E909A:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E917C
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xa
	b _080E916E
_080E90B4:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E917C
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xb
	b _080E916E
_080E90CE:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E917C
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xc
	b _080E916E
_080E90E8:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E917C
	movs r0, #8
	strb r0, [r4, #0x12]
	movs r0, #0xd
	b _080E917A
_080E90FA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E917C
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xe
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	b _080E9176
_080E9124:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E917C
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xf
	b _080E916E
_080E9142:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E917C
	movs r0, #8
	strb r0, [r4, #0x12]
	b _080E9176
_080E9152:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E917C
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x14
_080E916E:
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
_080E9176:
	ldrb r0, [r4, #0xe]
	adds r0, #1
_080E917A:
	strb r0, [r4, #0xe]
_080E917C:
	ldrb r0, [r4, #0x10]
	cmp r0, #0xb3
	beq _080E9184
	b _080E947E
_080E9184:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xf
	bls _080E918C
	b _080E947E
_080E918C:
	lsls r0, r0, #2
	ldr r1, _080E9198 @ =_080E919C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E9198: .4byte _080E919C
_080E919C: @ jump table
	.4byte _080E91DC @ case 0
	.4byte _080E91EE @ case 1
	.4byte _080E9216 @ case 2
	.4byte _080E923E @ case 3
	.4byte _080E928C @ case 4
	.4byte _080E92C0 @ case 5
	.4byte _080E92F2 @ case 6
	.4byte _080E9328 @ case 7
	.4byte _080E9350 @ case 8
	.4byte _080E938C @ case 9
	.4byte _080E93B2 @ case 10
	.4byte _080E93CA @ case 11
	.4byte _080E9404 @ case 12
	.4byte _080E942A @ case 13
	.4byte _080E9442 @ case 14
	.4byte _080E947E @ case 15
_080E91DC:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x74]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E91EE:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E91FE
	b _080E947E
_080E91FE:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #1
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	b _080E9478
_080E9216:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080E9222
	b _080E947E
_080E9222:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	b _080E9478
_080E923E:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080E9256
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #7
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	b _080E925E
_080E9256:
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #7
	ldr r0, [r4, #0x54]
	subs r0, r0, r1
_080E925E:
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x78
	bhi _080E9268
	b _080E947E
_080E9268:
	ldr r0, _080E9288 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
	movs r0, #0x28
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xc
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	b _080E9478
	.align 2, 0
_080E9288: .4byte 0xFFFFFC00
_080E928C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, _080E92BC @ =0xFFFFFF00
	cmp r1, r0
	bgt _080E92A2
	b _080E947E
_080E92A2:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xd
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	b _080E9478
	.align 2, 0
_080E92BC: .4byte 0xFFFFFF00
_080E92C0:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r2, r2, r1
	str r2, [r4, #0x5c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmn r2, r0
	bgt _080E92DA
	b _080E947E
_080E92DA:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	b _080E9478
_080E92F2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080E9310
	b _080E947E
_080E9310:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #3
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	b _080E9478
_080E9328:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080E9338
	b _080E947E
_080E9338:
	ldr r0, _080E934C @ =0xFFFFFC40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x74]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x1e
	bl __divsi3
	str r0, [r4, #0x5c]
	b _080E9478
	.align 2, 0
_080E934C: .4byte 0xFFFFFC40
_080E9350:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x68]
	cmp r1, r0
	bgt _080E936C
	b _080E947E
_080E936C:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #4
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x68]
	str r0, [r4, #0x58]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _080E9478
_080E938C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E947E
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x16
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	b _080E9478
_080E93B2:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E947E
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080E9478
_080E93CA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E947E
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x17
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	ldr r1, _080E9400 @ =0xFFFFE400
	adds r0, r0, r1
	b _080E9476
	.align 2, 0
_080E9400: .4byte 0xFFFFE400
_080E9404:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E947E
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x18
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	b _080E9478
_080E942A:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E947E
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080E9478
_080E9442:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E947E
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0x19
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r0, r0, r2
_080E9476:
	str r0, [r4, #0x58]
_080E9478:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E947E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080E94D4
	cmp r0, #1
	bgt _080E9494
	cmp r0, #0
	beq _080E94A2
	b _080E949C
_080E9494:
	cmp r0, #2
	beq _080E94E6
	cmp r0, #3
	beq _080E9504
_080E949C:
	adds r2, r4, #0
	adds r2, #0x7c
	b _080E9524
_080E94A2:
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r1, #0
	cmp r0, #0xf
	bls _080E9524
	movs r0, #0x10
	strb r0, [r2]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080E9524
_080E94D4:
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r2, #0x37
	b _080E9524
_080E94E6:
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x7c
	movs r0, #8
	strb r0, [r1]
	adds r2, r1, #0
	b _080E9524
_080E9504:
	ldr r1, _080E9520 @ =gWidgetFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl MenuComp13_Die
	b _080E9538
	.align 2, 0
_080E9520: .4byte gWidgetFnTable
_080E9524:
	ldr r3, _080E9540 @ =gBlendRegBuffer
	ldrb r0, [r2]
	movs r1, #0x1f
	ands r1, r0
	ldrb r2, [r2]
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #2]
_080E9538:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E9540: .4byte gBlendRegBuffer

	thumb_func_start MenuComp13_Die
MenuComp13_Die: @ 0x080E9544
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080E9570
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	ldr r2, _080E9568 @ =wDynamicGraphicTilenums
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r2, r0, r2
	adds r1, r4, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	strh r1, [r2]
	ldr r1, _080E956C @ =wDynamicMotionPalIDs
	b _080E9588
	.align 2, 0
_080E9568: .4byte wDynamicGraphicTilenums
_080E956C: .4byte wDynamicMotionPalIDs
_080E9570:
	adds r0, r4, #0
	adds r0, #0x78
	ldrh r0, [r0]
	ldr r2, _080E95C0 @ =wStaticGraphicTilenums
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r2, r0, r2
	adds r1, r4, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	strh r1, [r2]
	ldr r1, _080E95C4 @ =wStaticMotionPalIDs
_080E9588:
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x7e
	ldrb r1, [r1]
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x80
	ldrb r0, [r1]
	cmp r0, #0
	beq _080E95A0
	bl ClearBlink
_080E95A0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E95C8 @ =gWidgetFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E95C0: .4byte wStaticGraphicTilenums
_080E95C4: .4byte wStaticMotionPalIDs
_080E95C8: .4byte gWidgetFnTable
