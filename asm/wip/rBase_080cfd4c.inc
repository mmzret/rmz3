	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0xbd
	ldrb r0, [r6]
	cmp r0, #0
	bne _080CFD98
	ldr r4, _080CFF08 @ =0x000008FC
	ldr r1, _080CFF0C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080CFF10 @ =wStaticGraphicTilenums
	adds r1, #0xe6
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080CFF14 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080CFF18 @ =wStaticMotionPalIDs
	adds r0, #0xe6
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_080CFD98:
	ldrb r0, [r6]
	cmp r0, #1
	bne _080CFDDC
	ldr r4, _080CFF1C @ =0x00000AB4
	ldr r1, _080CFF0C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080CFF10 @ =wStaticGraphicTilenums
	movs r5, #0x89
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
	ldr r0, _080CFF14 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080CFF18 @ =wStaticMotionPalIDs
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
_080CFDDC:
	ldrb r0, [r6]
	cmp r0, #2
	bne _080CFE20
	ldr r4, _080CFF20 @ =0x00000AC8
	ldr r1, _080CFF0C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080CFF10 @ =wStaticGraphicTilenums
	movs r5, #0x8a
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
	ldr r0, _080CFF14 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080CFF18 @ =wStaticMotionPalIDs
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
_080CFE20:
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r5, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #1
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r7, #0xb]
	movs r1, #8
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldr r0, _080CFF24 @ =Rect_08370728
	str r0, [r7, #0x30]
	movs r6, #0
	ldr r0, _080CFF28 @ =0x00002001
	strh r0, [r7, #0x26]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080CFF2C @ =sCollisions
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r7, #0
	adds r1, #0xb4
	movs r0, #0xca
	lsls r0, r0, #0xb
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xb8
	movs r0, #0x98
	lsls r0, r0, #0xa
	str r0, [r2]
	ldr r0, [r1]
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x11]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xbe
	ldr r0, _080CFF30 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl CreateResistanceBaseElevator2
	ldr r1, _080CFF34 @ =gOverworld
	ldr r2, _080CFF38 @ =0x0002C014
	adds r0, r1, r2
	str r5, [r0]
	adds r2, #4
	adds r0, r1, r2
	str r5, [r0]
	ldr r0, _080CFF3C @ =0x0002C01C
	adds r2, r1, r0
	movs r0, #0xf0
	lsls r0, r0, #0xe
	str r0, [r2]
	ldr r2, _080CFF40 @ =0x0002C020
	adds r1, r1, r2
	movs r0, #0xa0
	lsls r0, r0, #0xe
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0xc1
	movs r0, #5
	strb r0, [r1]
	ldr r1, _080CFF44 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl BaseElevator_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CFF08: .4byte 0x000008FC
_080CFF0C: .4byte gStaticMotionGraphics
_080CFF10: .4byte wStaticGraphicTilenums
_080CFF14: .4byte gStaticMotionGraphics+12
_080CFF18: .4byte wStaticMotionPalIDs
_080CFF1C: .4byte 0x00000AB4
_080CFF20: .4byte 0x00000AC8
_080CFF24: .4byte Rect_08370728
_080CFF28: .4byte 0x00002001
_080CFF2C: .4byte sCollisions
_080CFF30: .4byte 0x0000FFFF
_080CFF34: .4byte gOverworld
_080CFF38: .4byte 0x0002C014
_080CFF3C: .4byte 0x0002C01C
_080CFF40: .4byte 0x0002C020
_080CFF44: .4byte gSolidFnTable
