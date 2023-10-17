	push {r4, r5, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r4, [r5, #0x11]
	cmp r4, #0
	bne _080CADD8
	ldr r0, _080CADB8 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	bne _080CAD16
	b _080CAE3C
_080CAD16:
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080CADBC @ =gSolidFnTable
	movs r0, #2
	strb r0, [r2, #9]
	ldr r0, [r1, #8]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r0, #0
	strh r4, [r2, #0x20]
	adds r1, r2, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r2, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #1
	strb r0, [r2, #0x11]
	str r5, [r2, #0x28]
	ldr r0, [r5, #0x54]
	ldr r1, _080CADC0 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r2, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r2, #0x58]
	ldr r0, _080CADC4 @ =gOverworld
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	ldr r2, _080CADC8 @ =wStaticGraphicTilenums
	cmp r0, #3
	bne _080CAD80
	ldr r1, _080CADCC @ =wStaticMotionPalIDs
	movs r0, #0xa
	strh r0, [r1, #0x24]
_080CAD80:
	movs r4, #0xb4
	lsls r4, r4, #1
	ldr r1, _080CADD0 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r2, #0x24]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080CADD4 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080CADCC @ =wStaticMotionPalIDs
	ldrh r1, [r0, #0x24]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	b _080CAE04
	.align 2, 0
_080CADB8: .4byte gSolidHeaderPtr
_080CADBC: .4byte gSolidFnTable
_080CADC0: .4byte 0xFFFFFF00
_080CADC4: .4byte gOverworld
_080CADC8: .4byte wStaticGraphicTilenums
_080CADCC: .4byte wStaticMotionPalIDs
_080CADD0: .4byte gStaticMotionGraphics
_080CADD4: .4byte gStaticMotionGraphics+12
_080CADD8:
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080CAE04:
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080CAE44 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r2, [r5, #0xd]
	strb r2, [r5, #0xe]
	adds r0, r5, #0
	bl Door2DBlue_Update
_080CAE3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CAE44: .4byte gSolidFnTable
