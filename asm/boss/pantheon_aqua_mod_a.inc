	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonAquaMod_Init
PantheonAquaMod_Init: @ 0x08051330
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _08051384 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _08051388 @ =0x0836394C
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
	ldr r0, _0805138C @ =gSystemSavedata
	ldrb r1, [r0, #0x12]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08051394
	ldr r1, _08051390 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x50
	bl ResetBossBody
	b _0805139E
	.align 2, 0
_08051384: .4byte gBossFnTable
_08051388: .4byte 0x0836394C
_0805138C: .4byte gSystemSavedata
_08051390: .4byte sCollisions
_08051394:
	ldr r1, _0805158C @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
_0805139E:
	ldr r1, _08051590 @ =onCollision
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x4c
	str r0, [sp]
	movs r1, #0
	str r1, [r0]
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
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08051424
	movs r4, #0xc3
	lsls r4, r4, #2
	ldr r1, _08051594 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _08051598 @ =wStaticGraphicTilenums
	adds r1, #0x4e
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805159C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080515A0 @ =wStaticMotionPalIDs
	adds r0, #0x4e
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_08051424:
	ldr r4, _080515A4 @ =0x00000604
	ldr r5, _08051594 @ =gStaticMotionGraphics
	adds r0, r4, r5
	ldr r1, _08051598 @ =wStaticGraphicTilenums
	mov sb, r1
	adds r1, #0x9a
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805159C @ =gStaticMotionGraphics+12
	mov r8, r0
	add r4, r8
	ldr r1, _080515A0 @ =wStaticMotionPalIDs
	mov sl, r1
	mov r0, sl
	adds r0, #0x9a
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xc3
	lsls r4, r4, #3
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0x9c
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0x9c
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080515A8 @ =0x0000062C
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0x9e
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0x9e
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xc8
	lsls r4, r4, #3
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0xa0
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0xa0
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080515AC @ =0x00000654
	adds r5, r4, r5
	mov r0, sb
	adds r0, #0xa2
	ldrh r1, [r0]
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0xa2
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	adds r0, #2
	movs r2, #0
	strh r2, [r0]
	adds r3, r7, #0
	adds r3, #0xbc
	ldr r0, [r7, #0x58]
	ldr r1, _080515B0 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [r3]
	adds r0, r7, #0
	adds r0, #0xb9
	strb r2, [r0]
	movs r0, #0
	ldr r1, [sp]
	str r0, [r1]
	adds r1, r7, #0
	adds r1, #0xc4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc5
	strb r2, [r0]
	ldrb r0, [r7, #0x10]
	cmp r0, #1
	bne _08051576
	ldr r0, [r3]
	str r0, [r7, #0x58]
_08051576:
	adds r0, r7, #0
	bl PantheonAquaMod_Update
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805158C: .4byte sCollisions
_08051590: .4byte onCollision
_08051594: .4byte gStaticMotionGraphics
_08051598: .4byte wStaticGraphicTilenums
_0805159C: .4byte gStaticMotionGraphics+12
_080515A0: .4byte wStaticMotionPalIDs
_080515A4: .4byte 0x00000604
_080515A8: .4byte 0x0000062C
_080515AC: .4byte 0x00000654
_080515B0: .4byte 0xFFFFEC00

	thumb_func_start PantheonAquaMod_Update
PantheonAquaMod_Update: @ 0x080515B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	beq _080515CE
	bl isKilled
	cmp r0, #0
	beq _080515CE
	movs r0, #0
	str r0, [r5]
_080515CE:
	adds r0, r4, #0
	bl tryKillPantheonAquaMod
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080515FA
	ldr r1, _08051600 @ =0x08363600
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08051604 @ =0x08363624
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080515FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08051600: .4byte 0x08363600
_08051604: .4byte 0x08363624

	thumb_func_start PantheonAquaMod_Die
PantheonAquaMod_Die: @ 0x08051608
	push {lr}
	ldr r2, _0805161C @ =0x08363648
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805161C: .4byte 0x08363648
