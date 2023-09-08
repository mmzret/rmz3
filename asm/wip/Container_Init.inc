	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r4, [r6, #0x10]
	adds r4, #0xe2
	lsls r5, r4, #2
	adds r5, r5, r4
	lsls r5, r5, #2
	ldr r1, _080DC378 @ =gStaticMotionGraphics
	adds r0, r5, r1
	ldr r1, _080DC37C @ =wStaticGraphicTilenums
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
	ldr r0, _080DC380 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	ldr r0, _080DC384 @ =wStaticMotionPalIDs
	adds r4, r4, r0
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r5, #0
	bl LoadPalette
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xe2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r5, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r7, #1
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DC388 @ =0x08371558
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r1, [r6, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r0, _080DC38C @ =0x083715E0
	str r0, [r6, #0x30]
	strh r7, [r6, #0x26]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	ldr r2, _080DC390 @ =0xFFFFF400
	adds r0, r0, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080DC32C
	ldr r0, [r6, #0x54]
	ldr r1, _080DC390 @ =0xFFFFF400
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	ldr r1, [r6, #0x54]
	ldr r2, _080DC394 @ =0xFFFFFF00
	adds r1, r1, r2
	adds r1, r1, r0
	str r1, [r6, #0x54]
_080DC32C:
	ldr r0, [r6, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080DC35A
	ldr r0, [r6, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	ldr r1, [r6, #0x54]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	str r1, [r6, #0x54]
_080DC35A:
	ldr r1, _080DC398 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl Solid35_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC378: .4byte gStaticMotionGraphics
_080DC37C: .4byte wStaticGraphicTilenums
_080DC380: .4byte gStaticMotionGraphics+12
_080DC384: .4byte wStaticMotionPalIDs
_080DC388: .4byte sCollision
_080DC38C: .4byte sSize
_080DC390: .4byte 0xFFFFF400
_080DC394: .4byte 0xFFFFFF00
_080DC398: .4byte gSolidFnTable
