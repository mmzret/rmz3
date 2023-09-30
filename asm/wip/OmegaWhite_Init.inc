	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	bl omegaWhite_0800bd24
	ldr r0, _0803DFF0 @ =gOverworld
	ldr r1, _0803DFF4 @ =0x0002D025
	adds r0, r0, r1
	movs r2, #0
	strb r2, [r0]
	ldr r0, _0803DFF8 @ =gStaticMotionGraphics
	mov sb, r0
	adds r0, #0xb4
	ldr r1, _0803DFFC @ =wStaticGraphicTilenums
	mov r8, r1
	ldrh r1, [r1, #0x12]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #9
	adds r1, r1, r6
	bl LoadGraphic
	ldr r2, _0803E000 @ =gStaticMotionGraphics+12
	mov sl, r2
	mov r0, sl
	adds r0, #0xb4
	ldr r5, _0803E004 @ =wStaticMotionPalIDs
	ldrh r1, [r5, #0x12]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r1, r4
	bl LoadPalette
	mov r0, sb
	adds r0, #0xc8
	mov r2, r8
	ldrh r1, [r2, #0x14]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r1, r1, r6
	bl LoadGraphic
	mov r0, sl
	adds r0, #0xc8
	ldrh r1, [r5, #0x14]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r1, r1, r4
	bl LoadPalette
	mov r0, sb
	adds r0, #0xdc
	mov r2, r8
	ldrh r1, [r2, #0x16]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r1, r1, r6
	bl LoadGraphic
	mov r0, sl
	adds r0, #0xdc
	ldrh r1, [r5, #0x16]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r1, r1, r4
	bl LoadPalette
	mov r0, sb
	adds r0, #0xf0
	mov r2, r8
	ldrh r1, [r2, #0x18]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r1, r1, r6
	bl LoadGraphic
	mov r0, sl
	adds r0, #0xf0
	ldrh r1, [r5, #0x18]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r1, r1, r4
	bl LoadPalette
	ldr r1, _0803E008 @ =0x08361B2C
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
	ldr r1, _0803E00C @ =onCollision
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	movs r1, #0
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	movs r2, #0
	str r2, [r0]
	subs r0, #5
	strb r2, [r0]
	adds r0, #9
	movs r4, #0
	strh r4, [r0]
	adds r0, #0x14
	movs r1, #0
	str r1, [r0]
	ldr r1, [r7, #0x58]
	ldr r2, _0803E010 @ =0xFFFFB000
	adds r1, r1, r2
	ldr r0, [r7, #0x54]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xb8
	str r0, [r1]
	str r0, [r7, #0x68]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _0803E018
	ldr r1, _0803E014 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r4, [r7, #0xd]
	b _0803E02E
	.align 2, 0
_0803DFF0: .4byte gOverworld
_0803DFF4: .4byte 0x0002D025
_0803DFF8: .4byte gStaticMotionGraphics
_0803DFFC: .4byte wStaticGraphicTilenums
_0803E000: .4byte gStaticMotionGraphics+12
_0803E004: .4byte wStaticMotionPalIDs
_0803E008: .4byte 0x08361B2C
_0803E00C: .4byte onCollision
_0803E010: .4byte 0xFFFFB000
_0803E014: .4byte gBossFnTable
_0803E018:
	ldr r1, _0803E074 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	movs r0, #3
	strb r0, [r7, #0xd]
_0803E02E:
	strb r4, [r7, #0xe]
	strb r4, [r7, #0xf]
	mov r0, sp
	movs r1, #0
	adds r2, r7, #0
	bl CreateOmegaWhiteHand
	mov r0, sp
	movs r1, #2
	adds r2, r7, #0
	bl omegaWhite_080b91d4
	str r0, [r7, #0x2c]
	mov r0, sp
	movs r1, #1
	adds r2, r7, #0
	bl CreateOmegaWhiteHand
	movs r1, #0xa8
	lsls r1, r1, #2
	movs r0, #0xb
	bl LoadBlink
	adds r0, r7, #0
	bl OmegaWhite_Update
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E074: .4byte gBossFnTable
