	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080500f4
FUN_080500f4: @ 0x080500F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r4, #0
	adds r7, #0x8c
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08050114
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0805018C
_08050114:
	ldr r0, _08050174 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _0805018C
	adds r5, r4, #0
	adds r5, #0xd0
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0805013E
	adds r0, r1, #0
	bl StopSound
	ldr r0, _08050178 @ =0x0000FFFF
	strh r0, [r5]
_0805013E:
	adds r1, r4, #0
	adds r1, #0xce
	ldrb r0, [r1]
	cmp r0, #0
	beq _08050150
	strb r6, [r1]
	movs r0, #0
	bl FUN_08010188
_08050150:
	ldr r1, _0805017C @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _08050180
	movs r0, #1
	strb r0, [r4, #0xd]
	b _08050182
	.align 2, 0
_08050174: .4byte gStageRun
_08050178: .4byte 0x0000FFFF
_0805017C: .4byte gBossFnTable
_08050180:
	strb r1, [r4, #0xd]
_08050182:
	adds r0, r4, #0
	bl Anubis_Die
	movs r0, #1
	b _0805018E
_0805018C:
	movs r0, #0
_0805018E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Anubis_Init
Anubis_Init: @ 0x08050194
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _080502EC @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _080502F0 @ =sInitModes
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _080502F4 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
	ldr r1, _080502F8 @ =FUN_080500c8
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	str r5, [r0]
	ldrb r0, [r7, #0x10]
	cmp r0, #1
	beq _080502D6
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r4]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r4]
	adds r4, #4
	ldr r0, [r7, #0x58]
	asrs r0, r0, #8
	str r0, [r4]
	movs r1, #0xa0
	bl __divsi3
	adds r0, #1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	str r1, [r4]
	adds r0, r7, #0
	adds r0, #0xc0
	str r5, [r0]
	adds r0, #8
	movs r1, #0
	strh r5, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0xcd
	movs r0, #0x40
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xce
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r4, _080502FC @ =0x000005B4
	ldr r0, _08050300 @ =gStaticMotionGraphics
	mov r8, r0
	adds r0, r4, r0
	ldr r6, _08050304 @ =wStaticGraphicTilenums
	adds r1, r6, #0
	adds r1, #0x92
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08050308 @ =gStaticMotionGraphics+12
	mov sl, r0
	add r4, sl
	ldr r5, _0805030C @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x92
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xb9
	lsls r4, r4, #3
	add r8, r4
	adds r6, #0x94
	ldrh r1, [r6]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	add r4, sl
	adds r5, #0x94
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	adds r1, r7, #0
	adds r1, #0xd0
	ldr r0, _08050310 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xd2
	movs r1, #1
	strb r1, [r0]
_080502D6:
	adds r0, r7, #0
	bl Anubis_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080502EC: .4byte gBossFnTable
_080502F0: .4byte sInitModes
_080502F4: .4byte sCollisions
_080502F8: .4byte FUN_080500c8
_080502FC: .4byte 0x000005B4
_08050300: .4byte gStaticMotionGraphics
_08050304: .4byte wStaticGraphicTilenums
_08050308: .4byte gStaticMotionGraphics+12
_0805030C: .4byte wStaticMotionPalIDs
_08050310: .4byte 0x0000FFFF

