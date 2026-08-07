	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Wormer_Init
Wormer_Init: @ 0x0804243C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _080424B0 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _080424B4 @ =0x08362260
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080424C8
	movs r4, #0xd2
	lsls r4, r4, #2
	ldr r1, _080424B8 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080424BC @ =wStaticGraphicTilenums
	adds r1, #0x54
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080424C0 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080424C4 @ =wStaticMotionPalIDs
	adds r0, #0x54
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	b _080424FA
	.align 2, 0
_080424B0: .4byte gBossFnTable
_080424B4: .4byte 0x08362260
_080424B8: .4byte gStaticMotionGraphics
_080424BC: .4byte wStaticGraphicTilenums
_080424C0: .4byte gStaticMotionGraphics+12
_080424C4: .4byte wStaticMotionPalIDs
_080424C8:
	ldr r0, _080425B4 @ =0x085D7DF8
	ldr r1, _080425B8 @ =wStaticGraphicTilenums
	adds r1, #0x80
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080425BC @ =0x085D7E04
	ldr r1, _080425C0 @ =wStaticMotionPalIDs
	adds r1, #0x80
	ldrh r1, [r1]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
_080424FA:
	movs r4, #0xd7
	lsls r4, r4, #2
	ldr r0, _080425C4 @ =gStaticMotionGraphics
	mov r8, r0
	adds r0, r4, r0
	ldr r6, _080425B8 @ =wStaticGraphicTilenums
	adds r1, r6, #0
	adds r1, #0x56
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080425C8 @ =gStaticMotionGraphics+12
	mov sl, r0
	add r4, sl
	ldr r5, _080425C0 @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x56
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
	movs r4, #0xdc
	lsls r4, r4, #2
	add r8, r4
	adds r6, #0x58
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
	adds r5, #0x58
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	ldrb r1, [r7, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldr r0, _080425CC @ =gSystemSavedata
	ldrb r1, [r0, #0x16]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08042598
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	beq _080425A6
_08042598:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080425D4
	ldrb r0, [r7, #0x10]
	cmp r0, #1
	bne _080425D4
_080425A6:
	ldr r1, _080425D0 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x50
	bl ResetBossBody
	b _080425DE
	.align 2, 0
_080425B4: .4byte 0x085D7DF8
_080425B8: .4byte wStaticGraphicTilenums
_080425BC: .4byte 0x085D7E04
_080425C0: .4byte wStaticMotionPalIDs
_080425C4: .4byte gStaticMotionGraphics
_080425C8: .4byte gStaticMotionGraphics+12
_080425CC: .4byte gSystemSavedata
_080425D0: .4byte sCollisions
_080425D4:
	ldr r1, _08042640 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
_080425DE:
	ldr r1, _08042644 @ =nop_080423e0
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	adds r1, r7, #0
	adds r1, #0xb4
	str r0, [r1]
	adds r1, #4
	movs r5, #0
	movs r2, #0
	movs r0, #0xc0
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xba
	strb r5, [r0]
	adds r0, #2
	str r2, [r0]
	adds r4, r7, #0
	adds r4, #0xc4
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
	adds r0, r7, #0
	adds r0, #0xc0
	strb r5, [r0]
	adds r0, r7, #0
	bl Wormer_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042640: .4byte sCollisions
_08042644: .4byte nop_080423e0
