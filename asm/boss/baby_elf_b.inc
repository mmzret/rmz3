	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08045d54
FUN_08045d54: @ 0x08045D54
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08045DF4
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08045DF4
	ldr r0, _08045DD4 @ =0x00000119
	bl PlaySound
	ldr r3, _08045DD8 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _08045D92
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08045D92
	ldr r0, _08045DDC @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08045D92:
	ldr r3, [r4, #0x2c]
	movs r5, #0
	ldrb r1, [r4, #0xd]
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08045DA8
	cmp r1, #0x10
	bne _08045DAA
_08045DA8:
	movs r5, #1
_08045DAA:
	ldr r2, _08045DE0 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	cmp r5, #0
	beq _08045DE4
	movs r0, #0
	b _08045DE6
	.align 2, 0
_08045DD4: .4byte 0x00000119
_08045DD8: .4byte gStageRun
_08045DDC: .4byte 0x0000FFFE
_08045DE0: .4byte gBossFnTable
_08045DE4:
	movs r0, #1
_08045DE6:
	strb r0, [r4, #0xd]
	strb r0, [r3, #0xd]
	adds r0, r4, #0
	bl BabyElf_Die
	movs r0, #1
	b _08045DF6
_08045DF4:
	movs r0, #0
_08045DF6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start BabyElf_Init
BabyElf_Init: @ 0x08045DFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	beq _08045E16
	adds r1, r6, #0
	adds r1, #0xd1
	movs r0, #0
	strb r0, [r1]
_08045E16:
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _08045E24
	movs r0, #0
	strb r0, [r6, #0x10]
	movs r0, #1
	b _08045E50
_08045E24:
	cmp r0, #3
	bne _08045E38
	movs r1, #0
	strb r1, [r6, #0x10]
	movs r0, #2
	strb r0, [r6, #0x11]
	adds r0, r6, #0
	adds r0, #0xd1
	strb r1, [r0]
	b _08045E52
_08045E38:
	cmp r0, #4
	bne _08045E4E
	movs r0, #0
	strb r0, [r6, #0x10]
	movs r0, #2
	strb r0, [r6, #0x11]
	adds r1, r6, #0
	adds r1, #0xd1
	movs r0, #1
	strb r0, [r1]
	b _08045E52
_08045E4E:
	movs r0, #0
_08045E50:
	strb r0, [r6, #0x11]
_08045E52:
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	ldr r1, _080460BC @ =gBossFnTable
	adds r0, r0, r1
	movs r2, #1
	str r2, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _080460C0 @ =sInitModes
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r2, #0
	mov sl, r2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080460C4 @ =sCollisions
	adds r0, r6, #0
	movs r2, #0x60
	bl ResetBossBody
	ldr r1, _080460C8 @ =FUN_08045d28
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r4, r6, #0
	adds r4, #0xb4
	ldr r0, [r6, #0x54]
	asrs r0, r0, #8
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	ldr r0, _080460CC @ =0xFFFFF800
	adds r1, r1, r0
	str r1, [r4]
	ldr r0, [r6, #0x58]
	asrs r0, r0, #8
	movs r1, #0xa0
	bl __divsi3
	adds r0, #1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	str r1, [r0]
	ldr r2, _080460D0 @ =0xFFFFB000
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc4
	movs r1, #0
	mov r8, r1
	strh r5, [r0]
	adds r1, r6, #0
	adds r1, #0xcc
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xcd
	mov r2, r8
	strb r2, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	subs r0, #0xa
	strb r2, [r0]
	ldrb r0, [r6, #0x10]
	subs r1, #5
	strb r0, [r1]
	ldrb r0, [r6, #0x10]
	mov sb, r0
	cmp r0, #0
	beq _08045F16
	b _080460A8
_08045F16:
	ldrb r0, [r6, #0x11]
	cmp r0, #2
	beq _08045F58
	movs r4, #0x82
	lsls r4, r4, #3
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080460D8 @ =wStaticGraphicTilenums
	adds r1, #0x68
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080460E0 @ =wStaticMotionPalIDs
	adds r0, #0x68
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
_08045F58:
	movs r4, #0xf0
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r7, _080460D8 @ =wStaticGraphicTilenums
	adds r1, r7, #0
	adds r1, #0x60
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r5, _080460E0 @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x60
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldrb r0, [r6, #0x11]
	cmp r0, #2
	beq _08046052
	movs r4, #0xf5
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	adds r1, r7, #0
	adds r1, #0x62
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xfa
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	adds r1, r7, #0
	adds r1, #0x64
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r5, #0
	adds r0, #0x64
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xff
	lsls r4, r4, #2
	ldr r1, _080460D4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	adds r1, r7, #0
	adds r1, #0x66
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080460DC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r5, #0
	adds r0, #0x66
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_08046052:
	ldr r0, _080460E4 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _080460A6
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #6
	strb r0, [r2, #9]
	ldr r1, _080460BC @ =gBossFnTable
	ldr r0, [r1, #0x18]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	mov r0, sb
	strh r0, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	mov r1, r8
	strb r1, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #1
	strb r0, [r2, #0x10]
	ldr r0, [r6, #0x54]
	str r0, [r2, #0x54]
	ldr r0, [r6, #0x58]
	str r0, [r2, #0x58]
	adds r0, r6, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0xd1
	strb r0, [r1]
	str r6, [r2, #0x28]
_080460A6:
	str r2, [r6, #0x2c]
_080460A8:
	adds r0, r6, #0
	bl BabyElf_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080460BC: .4byte gBossFnTable
_080460C0: .4byte sInitModes
_080460C4: .4byte sCollisions
_080460C8: .4byte FUN_08045d28
_080460CC: .4byte 0xFFFFF800
_080460D0: .4byte 0xFFFFB000
_080460D4: .4byte gStaticMotionGraphics
_080460D8: .4byte wStaticGraphicTilenums
_080460DC: .4byte gStaticMotionGraphics+12
_080460E0: .4byte wStaticMotionPalIDs
_080460E4: .4byte gBossHeaderPtr

