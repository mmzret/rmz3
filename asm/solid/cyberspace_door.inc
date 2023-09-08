	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080dbbd4
FUN_080dbbd4: @ 0x080DBBD4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080DBC2A
	cmp r0, #1
	bgt _080DBBE8
	cmp r0, #0
	beq _080DBBF0
	b _080DBDE6
_080DBBE8:
	cmp r0, #5
	bne _080DBBEE
	b _080DBDCC
_080DBBEE:
	b _080DBDE6
_080DBBF0:
	movs r1, #0xc6
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x3c]
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _080DBC8C @ =FUN_080dbdf4
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080DBC90 @ =sCyberSpaceDoorCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080DBC2A:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080DBCBE
	ldr r5, _080DBC94 @ =gStageRun+232
	ldr r1, [r5, #0x38]
	ldr r2, _080DBC98 @ =0xFFFF5800
	adds r0, r1, r2
	ldr r3, [r4, #0x54]
	cmp r3, r0
	bge _080DBC40
	b _080DBDE6
_080DBC40:
	ldr r7, _080DBC9C @ =0x0000A7FF
	adds r0, r1, r7
	cmp r3, r0
	ble _080DBC4A
	b _080DBDE6
_080DBC4A:
	ldr r2, [r5, #0x3c]
	ldr r6, _080DBCA0 @ =0xFFFF8000
	adds r0, r2, r6
	ldr r1, [r4, #0x58]
	cmp r1, r0
	bge _080DBC58
	b _080DBDE6
_080DBC58:
	ldr r7, _080DBCA4 @ =0x0000CFFF
	adds r0, r2, r7
	cmp r1, r0
	ble _080DBC62
	b _080DBDE6
_080DBC62:
	ldr r0, _080DBCA8 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DBCB4
	ldr r0, _080DBCAC @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xa
	beq _080DBCB0
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r3, r2
	str r0, [r5, #0x60]
	b _080DBCB4
	.align 2, 0
_080DBC8C: .4byte FUN_080dbdf4
_080DBC90: .4byte sCyberSpaceDoorCollisions
_080DBC94: .4byte gStageRun+232
_080DBC98: .4byte 0xFFFF5800
_080DBC9C: .4byte 0x0000A7FF
_080DBCA0: .4byte 0xFFFF8000
_080DBCA4: .4byte 0x0000CFFF
_080DBCA8: .4byte gCurStory
_080DBCAC: .4byte gOverworld
_080DBCB0:
	adds r0, r3, r6
	str r0, [r5, #0x5c]
_080DBCB4:
	movs r0, #0xff
	strb r0, [r4, #0x1f]
	movs r0, #1
	strb r0, [r4, #0x11]
	b _080DBD40
_080DBCBE:
	ldr r3, _080DBD10 @ =gStageRun+232
	ldr r2, [r3, #0x38]
	ldr r5, _080DBD14 @ =0xFFFF5800
	adds r0, r2, r5
	ldr r1, [r4, #0x54]
	cmp r1, r0
	blt _080DBCE8
	ldr r7, _080DBD18 @ =0x0000A7FF
	adds r0, r2, r7
	cmp r1, r0
	bgt _080DBCE8
	ldr r2, [r3, #0x3c]
	ldr r1, _080DBD1C @ =0xFFFF8000
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	cmp r1, r0
	blt _080DBCE8
	ldr r3, _080DBD20 @ =0x0000CFFF
	adds r0, r2, r3
	cmp r1, r0
	ble _080DBD40
_080DBCE8:
	ldr r0, _080DBD24 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DBD36
	ldr r0, _080DBD28 @ =gOverworld
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xa
	beq _080DBD30
	ldr r1, _080DBD2C @ =gStageRun+328
	movs r0, #0xf0
	lsls r0, r0, #0xe
	b _080DBD34
	.align 2, 0
_080DBD10: .4byte gStageRun+232
_080DBD14: .4byte 0xFFFF5800
_080DBD18: .4byte 0x0000A7FF
_080DBD1C: .4byte 0xFFFF8000
_080DBD20: .4byte 0x0000CFFF
_080DBD24: .4byte gCurStory
_080DBD28: .4byte gOverworld
_080DBD2C: .4byte gStageRun+328
_080DBD30:
	ldr r1, _080DBD3C @ =gStageRun+324
	movs r0, #0
_080DBD34:
	str r0, [r1]
_080DBD36:
	movs r0, #0
	strb r0, [r4, #0x11]
	b _080DBDE6
	.align 2, 0
_080DBD3C: .4byte gStageRun+324
_080DBD40:
	ldr r0, _080DBD6C @ =gIsUsingDoor3D
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DBD54
	ldr r0, _080DBD70 @ =gStageRun
	ldrh r1, [r0, #0x14]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DBDE6
_080DBD54:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x17
	ands r0, r1
	cmp r0, #0
	bne _080DBD74
	movs r0, #5
	strb r0, [r4, #0xe]
	b _080DBDE6
	.align 2, 0
_080DBD6C: .4byte gIsUsingDoor3D
_080DBD70: .4byte gStageRun
_080DBD74:
	ldr r2, _080DBD98 @ =gCollisionManager
	ldrb r1, [r2]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _080DBD9C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080DBDA4
	ldr r0, _080DBDA0 @ =gGameState
	movs r1, #0xe0
	lsls r1, r1, #3
	bl SetGameMode
	b _080DBDAC
	.align 2, 0
_080DBD98: .4byte gCollisionManager
_080DBD9C: .4byte gCurStory
_080DBDA0: .4byte gGameState
_080DBDA4:
	ldr r0, _080DBDC0 @ =gGameState
	ldr r1, _080DBDC4 @ =0x01000700
	bl SetGameMode
_080DBDAC:
	ldr r1, _080DBDC8 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080DBDE6
	.align 2, 0
_080DBDC0: .4byte gGameState
_080DBDC4: .4byte 0x01000700
_080DBDC8: .4byte gSolidFnTable
_080DBDCC:
	ldr r0, _080DBDEC @ =gIsUsingDoor3D
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DBDE6
	ldr r0, _080DBDF0 @ =gStageRun
	ldrh r0, [r0, #0x14]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080DBDE6
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xf]
	strb r1, [r4, #0xe]
_080DBDE6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DBDEC: .4byte gIsUsingDoor3D
_080DBDF0: .4byte gStageRun

	thumb_func_start FUN_080dbdf4
FUN_080dbdf4: @ 0x080DBDF4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r5, [r6, #8]
	ldr r0, _080DBE10 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080DBE14
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080DBE36
	b _080DBE1A
	.align 2, 0
_080DBE10: .4byte gCurStory
_080DBE14:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _080DBE36
_080DBE1A:
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r4]
	str r0, [r5, #0x3c]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r1, r7, #0
	bl TaskCB_DrawNoAffineSprite
	ldr r0, [r5, #0x3c]
	str r0, [r4]
	str r5, [r5, #0x3c]
_080DBE36:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
