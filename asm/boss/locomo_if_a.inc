	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tryKillLocomoIF
tryKillLocomoIF: @ 0x08054750
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0805476E
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080547A4
_0805476E:
	ldr r0, _0805479C @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _080547A4
	ldr r1, _080547A0 @ =gBossFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	strb r3, [r2, #0xd]
	adds r0, r2, #0
	bl LocomoIF_Die
	movs r0, #1
	b _080547A6
	.align 2, 0
_0805479C: .4byte gStageRun
_080547A0: .4byte gBossFnTable
_080547A4:
	movs r0, #0
_080547A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start LocomoIF_Init
LocomoIF_Init: @ 0x080547AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r1, _08054800 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _08054804 @ =0x08363B40
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldr r0, _08054808 @ =gSystemSavedata
	ldrb r1, [r0, #0x16]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08054810
	ldr r1, _0805480C @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x30
	bl ResetBossBody
	b _0805481A
	.align 2, 0
_08054800: .4byte gBossFnTable
_08054804: .4byte 0x08363B40
_08054808: .4byte gSystemSavedata
_0805480C: .4byte sCollisions
_08054810:
	ldr r1, _08054A18 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x20
	bl ResetBossBody
_0805481A:
	ldr r1, _08054A1C @ =nop_0805474c
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	movs r1, #0
	str r1, [r0]
	movs r4, #0x69
	lsls r5, r4, #2
	ldr r6, _08054A20 @ =gStaticMotionGraphics
	adds r0, r5, r6
	ldr r2, _08054A24 @ =wStaticGraphicTilenums
	mov sb, r2
	ldrh r1, [r2, #0x2a]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	ldr r1, _08054A2C @ =wStaticMotionPalIDs
	mov sl, r1
	ldrh r1, [r1, #0x2a]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	add r1, r8
	adds r0, r5, #0
	bl LoadPalette
	lsls r4, r4, #4
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xa8
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xa8
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _08054A30 @ =0x000006A4
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xaa
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xaa
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xd7
	lsls r4, r4, #3
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xac
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xac
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _08054A34 @ =0x000006CC
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xae
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xae
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xdc
	lsls r4, r4, #3
	adds r6, r4, r6
	mov r0, sb
	adds r0, #0xb0
	ldrh r1, [r0]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	adds r0, r6, #0
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xb0
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r7, #0x54]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x58]
	asrs r0, r0, #8
	str r0, [r7, #0x58]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	movs r2, #2
	bl CreateTopGabyoall
	adds r1, r7, #0
	adds r1, #0xc0
	str r0, [r1]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, _08054A38 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08054A3C @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #2
	movs r2, #2
	bl CreateTopGabyoall
	adds r1, r7, #0
	adds r1, #0xc4
	str r0, [r1]
	mov r0, sp
	movs r1, #3
	movs r2, #2
	bl CreateTopGabyoall
	adds r1, r7, #0
	adds r1, #0xc8
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb8
	movs r2, #0
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, r7, #0
	bl CreateLocomoIFPlatform
	adds r0, r7, #0
	bl LocomoIF_Update
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054A18: .4byte sCollisions
_08054A1C: .4byte nop_0805474c
_08054A20: .4byte gStaticMotionGraphics
_08054A24: .4byte wStaticGraphicTilenums
_08054A28: .4byte gStaticMotionGraphics+12
_08054A2C: .4byte wStaticMotionPalIDs
_08054A30: .4byte 0x000006A4
_08054A34: .4byte 0x000006CC
_08054A38: .4byte gStageRun+232
_08054A3C: .4byte 0xFFFFB000

	thumb_func_start LocomoIF_Update
LocomoIF_Update: @ 0x08054A40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08054A5A
	bl isKilled
	cmp r0, #0
	beq _08054A82
	movs r0, #0
	b _08054A80
_08054A5A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08054A82
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08054A82
	ldr r2, _08054AB4 @ =0x08363B44
	movs r0, #0x17
	adds r1, r4, #0
	bl ApplyElementEffect
_08054A80:
	str r0, [r5]
_08054A82:
	adds r0, r4, #0
	bl tryKillLocomoIF
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08054AAE
	ldr r1, _08054AB8 @ =0x08363ABC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08054ABC @ =0x08363AD8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08054AAE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08054AB4: .4byte 0x08363B44
_08054AB8: .4byte 0x08363ABC
_08054ABC: .4byte 0x08363AD8

	thumb_func_start LocomoIF_Die
LocomoIF_Die: @ 0x08054AC0
	push {lr}
	ldr r2, _08054AD4 @ =0x08363AF4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08054AD4: .4byte 0x08363AF4
