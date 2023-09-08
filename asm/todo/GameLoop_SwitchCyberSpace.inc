	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r0, [r7, #2]
	cmp r0, #6
	bls _080EEFEE
	b _080EF2C4
_080EEFEE:
	lsls r0, r0, #2
	ldr r1, _080EEFF8 @ =_080EEFFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080EEFF8: .4byte _080EEFFC
_080EEFFC: @ jump table
	.4byte _080EF018 @ case 0
	.4byte _080EF02C @ case 1
	.4byte _080EF056 @ case 2
	.4byte _080EF102 @ case 3
	.4byte _080EF154 @ case 4
	.4byte _080EF24C @ case 5
	.4byte _080EF264 @ case 6
_080EF018:
	ldr r2, _080EF120 @ =gCollisionManager
	ldrb r1, [r2]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x20
	strh r0, [r7, #4]
	ldrb r0, [r7, #2]
	adds r0, #1
	strb r0, [r7, #2]
_080EF02C:
	ldrh r0, [r7, #4]
	subs r0, #1
	movs r3, #0
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080EF03C
	b _080EF2C4
_080EF03C:
	ldr r1, _080EF124 @ =pZero2
	ldr r2, [r1]
	movs r0, #0xb
	strb r0, [r2, #0xd]
	ldr r0, [r1]
	strb r3, [r0, #0xe]
	ldr r0, [r1]
	strb r3, [r0, #0xf]
	movs r0, #0x20
	strh r0, [r7, #4]
	ldrb r0, [r7, #2]
	adds r0, #1
	strb r0, [r7, #2]
_080EF056:
	ldrh r2, [r7, #4]
	adds r2, #1
	movs r6, #0
	adds r1, r2, #0
	strh r2, [r7, #4]
	ldr r4, _080EF128 @ =gPaletteManager
	ldr r3, _080EF12C @ =0x00000402
	adds r0, r4, r3
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	subs r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	subs r3, #1
	adds r1, r4, r3
	strb r0, [r1]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0x3f
	bgt _080EF082
	b _080EF2C4
_080EF082:
	adds r0, r7, #0
	bl SaveGraphicState
	strh r6, [r4]
	ldr r5, _080EF130 @ =gVideoRegBuffer
	ldrh r1, [r5]
	ldr r0, _080EF134 @ =0x0000B0FF
	ands r0, r1
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r0, _080EF138 @ =wMOSAIC
	strh r6, [r0]
	bl PauseAllBlinks
	movs r3, #0x81
	lsls r3, r3, #2
	adds r0, r3, #0
	strh r0, [r5, #6]
	str r6, [r5, #0x10]
	ldr r0, _080EF13C @ =0x08547CA8
	movs r4, #0xc
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, _080EF140 @ =0x08547CB4
	movs r1, #0
	bl LoadPalette
	ldr r0, _080EF144 @ =0x08547CBC
	ldrh r1, [r5, #6]
	ands r4, r1
	lsls r4, r4, #0xc
	adds r1, r4, #0
	bl LoadGraphic
	ldr r0, _080EF148 @ =0x08547CC8
	movs r1, #0
	bl LoadPalette
	ldr r1, _080EF14C @ =gBgMapOffsets
	str r6, [sp]
	movs r0, #0x12
	movs r2, #0x82
	movs r3, #0
	bl LoadBgMap
	bl CancelCyberSpaceColorFilter
	movs r0, #0x89
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #0x40
	strh r0, [r7, #4]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r7, #6]
	ldrb r0, [r7, #2]
	adds r0, #1
	strb r0, [r7, #2]
_080EF102:
	ldrh r1, [r7, #4]
	movs r2, #4
	ldrsh r0, [r7, r2]
	cmp r0, #0x20
	ble _080EF150
	subs r0, r1, #1
	adds r1, r0, #0
	strh r0, [r7, #4]
	ldr r2, _080EF128 @ =gPaletteManager
	ldr r3, _080EF12C @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	b _080EF282
	.align 2, 0
_080EF120: .4byte gCollisionManager
_080EF124: .4byte pZero2
_080EF128: .4byte gPaletteManager
_080EF12C: .4byte 0x00000402
_080EF130: .4byte gVideoRegBuffer
_080EF134: .4byte 0x0000B0FF
_080EF138: .4byte wMOSAIC
_080EF13C: .4byte 0x08547CA8
_080EF140: .4byte 0x08547CB4
_080EF144: .4byte 0x08547CBC
_080EF148: .4byte 0x08547CC8
_080EF14C: .4byte gBgMapOffsets
_080EF150:
	movs r0, #0
	b _080EF25A
_080EF154:
	ldrh r1, [r7, #4]
	movs r2, #4
	ldrsh r0, [r7, r2]
	cmp r0, #0x3f
	bgt _080EF162
	adds r0, r1, #1
	b _080EF270
_080EF162:
	ldrb r3, [r7, #3]
	cmp r3, #0
	bne _080EF198
	ldr r2, _080EF188 @ =gCurStory
	ldrb r1, [r2, #4]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2, #4]
	ldr r1, _080EF18C @ =gMission
	movs r0, #7
	ldrsb r0, [r1, r0]
	subs r0, #5
	cmp r0, #0
	ble _080EF190
	ldrb r0, [r1, #7]
	subs r0, #5
	strb r0, [r1, #7]
	b _080EF192
	.align 2, 0
_080EF188: .4byte gCurStory
_080EF18C: .4byte gMission
_080EF190:
	strb r3, [r1, #7]
_080EF192:
	bl ApplyCyberSpaceColorFilter
	b _080EF1D2
_080EF198:
	ldr r2, _080EF1C0 @ =gCurStory
	ldrb r1, [r2, #4]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #4]
	bl CancelCyberSpaceColorFilter
	ldr r0, _080EF1C4 @ =gOverworld
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xa
	beq _080EF1CC
	ldr r1, _080EF1C8 @ =gStageRun+328
	movs r0, #0xf0
	lsls r0, r0, #0xe
	b _080EF1D0
	.align 2, 0
_080EF1C0: .4byte gCurStory
_080EF1C4: .4byte gOverworld
_080EF1C8: .4byte gStageRun+328
_080EF1CC:
	ldr r1, _080EF234 @ =gStageRun+324
	movs r0, #0
_080EF1D0:
	str r0, [r1]
_080EF1D2:
	ldr r4, _080EF238 @ =pZero2
	ldr r0, [r4]
	bl resetSateliteElfPosition
	ldr r1, _080EF23C @ =gIsUsingDoor3D
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x4c
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, #0x4a
	ldrb r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	ldrb r0, [r1, #0xa]
	orrs r0, r2
	strb r0, [r1, #0xa]
	ldr r1, [r4]
	movs r0, #0xb
	strb r0, [r1, #0xd]
	ldr r1, [r4]
	movs r0, #2
	strb r0, [r1, #0xe]
	ldr r0, [r4]
	strb r3, [r0, #0xf]
	adds r0, r7, #0
	bl RestoreGraphicState
	bl ResumeAllBlinks
	ldr r0, _080EF240 @ =gStageRun+288
	bl UpdateStageEntities
	ldr r0, _080EF244 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl UpdateBlockingEntities
	ldr r0, _080EF248 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl UpdateBlockingEntities
	movs r0, #8
	b _080EF25A
	.align 2, 0
_080EF234: .4byte gStageRun+324
_080EF238: .4byte pZero2
_080EF23C: .4byte gIsUsingDoor3D
_080EF240: .4byte gStageRun+288
_080EF244: .4byte gSolidHeaderPtr
_080EF248: .4byte gZakoHeaderPtr
_080EF24C:
	ldrh r0, [r7, #4]
	subs r0, #1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080EF2C4
	movs r0, #0x40
_080EF25A:
	strh r0, [r7, #4]
	ldrb r0, [r7, #2]
	adds r0, #1
	strb r0, [r7, #2]
	b _080EF2C4
_080EF264:
	ldrh r1, [r7, #4]
	movs r3, #4
	ldrsh r0, [r7, r3]
	cmp r0, #0
	beq _080EF29C
	subs r0, r1, #1
_080EF270:
	strh r0, [r7, #4]
	ldr r2, _080EF294 @ =gPaletteManager
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r0, #0x20
	ldr r3, _080EF298 @ =0x00000402
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0xff
_080EF282:
	ands r0, r1
	subs r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
	b _080EF2C4
	.align 2, 0
_080EF294: .4byte gPaletteManager
_080EF298: .4byte 0x00000402
_080EF29C:
	ldr r0, _080EF2DC @ =pZero2
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _080EF2C4
	ldrb r0, [r1, #0xd]
	cmp r0, #0
	bne _080EF2C4
	ldr r2, _080EF2E0 @ =gCollisionManager
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r7, #0
	bl SetGameMode
_080EF2C4:
	ldrb r0, [r7, #2]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080EF32C
	ldrb r0, [r7, #3]
	cmp r0, #0
	bne _080EF2E4
	ldrh r0, [r7, #6]
	adds r0, #1
	b _080EF2E8
	.align 2, 0
_080EF2DC: .4byte pZero2
_080EF2E0: .4byte gCollisionManager
_080EF2E4:
	ldrh r0, [r7, #6]
	subs r0, #1
_080EF2E8:
	strh r0, [r7, #6]
	ldr r1, _080EF324 @ =gBgMapOffsets
	ldrh r3, [r7, #6]
	lsls r2, r3, #0x10
	asrs r2, r2, #0x11
	movs r0, #3
	ands r2, r0
	subs r2, #0x7e
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r4, #1
	adds r0, r4, #0
	ands r0, r3
	lsls r0, r0, #5
	str r0, [sp]
	movs r0, #0x12
	movs r3, #0
	bl LoadBgMap
	ldr r1, _080EF328 @ =gVideoRegBuffer+18
	ldrh r0, [r7, #6]
	ands r4, r0
	movs r0, #0
	cmp r4, #0
	bne _080EF320
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
_080EF320:
	strh r0, [r1]
	b _080EF3CC
	.align 2, 0
_080EF324: .4byte gBgMapOffsets
_080EF328: .4byte gVideoRegBuffer+18
_080EF32C:
	movs r3, #0x9a
	lsls r3, r3, #4
	adds r4, r7, r3
	adds r0, r4, #0
	bl ClearTaskBuffer
	bl ClearAllHitboxes
	ldr r1, _080EF3D4 @ =0x0202F354
	movs r0, #0
	strb r0, [r1]
	movs r0, #0
	ldr r1, _080EF3D8 @ =0x0202F360
	str r0, [sp, #4]
	ldr r2, _080EF3DC @ =0x01000008
	add r0, sp, #4
	bl CpuFastSet
	movs r0, #1
	bl OverworldUpdate
	ldr r5, _080EF3E0 @ =0x0203029C
	ldr r0, [r5]
	bl UpdateEntities
	ldr r6, _080EF3E4 @ =gElfHeaderPtr
	ldr r0, [r6]
	bl UpdateBlockingEntities
	bl UpdateVFXs
	ldr r0, _080EF3E8 @ =gSolidHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, _080EF3EC @ =gBossHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, _080EF3F0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, [r5]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, [r6]
	adds r1, r4, #0
	bl DrawEntity
	adds r0, r4, #0
	bl DrawWeapon
	ldr r0, _080EF3F4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	ldr r0, _080EF3F8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	ldr r0, _080EF3FC @ =gMapItemHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	movs r0, #1
	bl CameraUpdate
	adds r0, r7, #0
	bl DrawHUD
	bl UpdateTextWindow
_080EF3CC:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EF3D4: .4byte 0x0202F354
_080EF3D8: .4byte 0x0202F360
_080EF3DC: .4byte 0x01000008
_080EF3E0: .4byte 0x0203029C
_080EF3E4: .4byte gElfHeaderPtr
_080EF3E8: .4byte gSolidHeaderPtr
_080EF3EC: .4byte gBossHeaderPtr
_080EF3F0: .4byte gZakoHeaderPtr
_080EF3F4: .4byte gProjectileHeaderPtr
_080EF3F8: .4byte gVFXHeaderPtr
_080EF3FC: .4byte gMapItemHeaderPtr
