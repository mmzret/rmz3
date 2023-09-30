	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid46_Update
Solid46_Update: @ 0x080DE914
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r6, #0x11]
	ldr r0, _080DE984 @ =gCurStory
	ldrb r0, [r0, #8]
	lsrs r2, r0, #6
	movs r0, #1
	ands r0, r2
	cmp r1, r0
	beq _080DE970
	movs r0, #1
	ands r2, r0
	strb r2, [r6, #0x11]
	ldr r4, _080DE988 @ =0x00000C1C
	ldr r1, _080DE98C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080DE990 @ =wStaticGraphicTilenums
	movs r5, #0x9b
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
	ldr r0, _080DE994 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080DE998 @ =wStaticMotionPalIDs
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
_080DE970:
	ldrb r0, [r6, #0xd]
	cmp r0, #6
	bls _080DE978
	b _080DEAC6
_080DE978:
	lsls r0, r0, #2
	ldr r1, _080DE99C @ =_080DE9A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE984: .4byte gCurStory
_080DE988: .4byte 0x00000C1C
_080DE98C: .4byte gStaticMotionGraphics
_080DE990: .4byte wStaticGraphicTilenums
_080DE994: .4byte gStaticMotionGraphics+12
_080DE998: .4byte wStaticMotionPalIDs
_080DE99C: .4byte _080DE9A0
_080DE9A0: @ jump table
	.4byte _080DE9BC @ case 0
	.4byte _080DE9E2 @ case 1
	.4byte _080DE9F8 @ case 2
	.4byte _080DEA38 @ case 3
	.4byte _080DEA5A @ case 4
	.4byte _080DEA80 @ case 5
	.4byte _080DEA96 @ case 6
_080DE9BC:
	ldr r0, [r6, #0x58]
	movs r1, #0xe0
	lsls r1, r1, #0xb
	subs r1, r1, r0
	lsls r1, r1, #0xb
	asrs r2, r1, #0x10
	ldr r1, [r6, #0x60]
	adds r3, r0, #0
	cmp r2, r1
	bge _080DE9D2
	str r2, [r6, #0x60]
_080DE9D2:
	ldr r0, [r6, #0x60]
	adds r0, r3, r0
	str r0, [r6, #0x58]
	cmp r2, #0x20
	bgt _080DEAC6
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DE9E2:
	ldr r0, _080DEA28 @ =gOverworld
	ldr r1, _080DEA2C @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080DEAC6
	movs r0, #0
	str r0, [r6, #0x60]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DE9F8:
	ldr r0, [r6, #0x60]
	adds r0, #4
	str r0, [r6, #0x60]
	ldr r1, [r6, #0x58]
	subs r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, _080DEA30 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080DEA34 @ =0xFFFF8000
	adds r0, r0, r2
	cmp r1, r0
	bge _080DEAC6
	ldrb r1, [r6, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r6, #0xb]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080DEAC6
	.align 2, 0
_080DEA28: .4byte gOverworld
_080DEA2C: .4byte 0x0002D024
_080DEA30: .4byte gStageRun+232
_080DEA34: .4byte 0xFFFF8000
_080DEA38:
	ldr r0, _080DEACC @ =gOverworld
	ldr r1, _080DEAD0 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080DEAC6
	ldrb r1, [r6, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r0, _080DEAD4 @ =0x083717C0
	str r0, [r6, #0x30]
	ldr r0, _080DEAD8 @ =0x00002001
	strh r0, [r6, #0x26]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DEA5A:
	ldr r0, [r6, #0x58]
	movs r1, #0xe0
	lsls r1, r1, #0xb
	subs r1, r1, r0
	lsls r1, r1, #0xb
	asrs r2, r1, #0x10
	ldr r1, [r6, #0x60]
	adds r3, r0, #0
	cmp r2, r1
	bge _080DEA70
	str r2, [r6, #0x60]
_080DEA70:
	ldr r0, [r6, #0x60]
	adds r0, r3, r0
	str r0, [r6, #0x58]
	cmp r2, #0x20
	bgt _080DEAC6
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DEA80:
	ldr r0, _080DEACC @ =gOverworld
	ldr r2, _080DEAD0 @ =0x0002D024
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #8
	bls _080DEAC6
	movs r0, #0
	str r0, [r6, #0x60]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DEA96:
	ldr r0, [r6, #0x60]
	adds r0, #4
	str r0, [r6, #0x60]
	ldr r1, [r6, #0x58]
	subs r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, _080DEADC @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080DEAE0 @ =0xFFFF8000
	adds r0, r0, r2
	cmp r1, r0
	bge _080DEAC6
	ldr r1, _080DEAE4 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl Solid46_Die
_080DEAC6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DEACC: .4byte gOverworld
_080DEAD0: .4byte 0x0002D024
_080DEAD4: .4byte 0x083717C0
_080DEAD8: .4byte 0x00002001
_080DEADC: .4byte gStageRun+232
_080DEAE0: .4byte 0xFFFF8000
_080DEAE4: .4byte gSolidFnTable

	thumb_func_start Solid46_Die
Solid46_Die: @ 0x080DEAE8
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldrb r2, [r0, #0xb]
	movs r1, #0xf7
	ands r1, r2
	strb r1, [r0, #0xb]
	ldr r2, _080DEB0C @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080DEB0C: .4byte gSolidFnTable
