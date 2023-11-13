	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r6, [r5, #3]
	cmp r6, #0
	bne _080EEEB2
	ldr r1, _080EEE30 @ =0x000064AC
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, #0xb4
	ldrb r4, [r0, #0x10]
	ldr r0, _080EEE34 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080EEE16
	bl ApplyCyberSpaceColorFilter
_080EEE16:
	adds r0, r5, #0
	bl RestoreGraphicState
	bl ResumeAllBlinks
	strh r6, [r5, #4]
	ldr r2, _080EEE38 @ =0x0000625C
	adds r0, r5, r2
	ldrh r0, [r0, #2]
	cmp r0, #1
	bne _080EEE3C
	movs r4, #6
	b _080EEE42
	.align 2, 0
_080EEE30: .4byte 0x000064AC
_080EEE34: .4byte gCurStory
_080EEE38: .4byte 0x0000625C
_080EEE3C:
	cmp r0, #2
	bne _080EEE42
	movs r4, #7
_080EEE42:
	ldr r3, _080EEE64 @ =0x000064AC
	adds r6, r5, r3
	ldr r1, [r6]
	ldr r2, _080EEE68 @ =0x00000147
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _080EEE6C
	adds r0, r1, #0
	adds r1, r4, #0
	bl LoadZeroPalette
	ldr r0, [r6]
	adds r1, r4, #0
	bl LoadShadowDashPalette
	b _080EEE74
	.align 2, 0
_080EEE64: .4byte 0x000064AC
_080EEE68: .4byte 0x00000147
_080EEE6C:
	adds r0, r1, #0
	adds r1, r4, #0
	bl LoadZeroPalette
_080EEE74:
	ldr r0, _080EEEA0 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080EEEAC
	ldr r2, _080EEEA4 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EEEA8 @ =0x0000F0FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetGameMode
	b _080EEFD6
	.align 2, 0
_080EEEA0: .4byte gStageRun
_080EEEA4: .4byte gVideoRegBuffer
_080EEEA8: .4byte 0x0000F0FF
_080EEEAC:
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_080EEEB2:
	movs r0, #0x9a
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl ClearTaskBuffer
	bl ClearAllHitboxes
	ldr r1, _080EEF84 @ =0x0202F354
	movs r0, #0
	strb r0, [r1]
	movs r7, #0
	ldr r1, _080EEF88 @ =0x0202F360
	str r7, [sp]
	movs r6, #8
	ldr r2, _080EEF8C @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	movs r0, #1
	bl OverworldUpdate
	ldr r0, _080EEF90 @ =gSolidHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, _080EEF94 @ =gBossHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, _080EEF98 @ =gZakoHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, _080EEF9C @ =0x0203029C
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, _080EEFA0 @ =gElfHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	adds r0, r4, #0
	bl DrawWeapon
	ldr r0, _080EEFA4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	ldr r0, _080EEFA8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	ldr r0, _080EEFAC @ =gPickupHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawCollidableEntity
	movs r0, #1
	bl CameraUpdate
	adds r0, r5, #0
	bl DrawHUD
	bl UpdateTextWindow
	ldrh r0, [r5, #4]
	adds r0, #2
	adds r2, r0, #0
	strh r0, [r5, #4]
	ldr r3, _080EEFB0 @ =gPaletteManager
	ldr r4, _080EEFB4 @ =0x00000402
	adds r1, r3, r4
	strb r2, [r1]
	movs r1, #0xff
	ands r1, r2
	subs r4, #1
	adds r2, r3, r4
	strb r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r3, r3, r2
	strb r1, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	bne _080EEFD6
	ldr r3, _080EEFB8 @ =0x00001EDC
	adds r0, r5, r3
	strh r7, [r0]
	ldr r0, _080EEFBC @ =gCurStory
	ldrb r0, [r0, #8]
	ands r6, r0
	cmp r6, #0
	bne _080EEFC0
	bl TurnUpBGM
	b _080EEFCC
	.align 2, 0
_080EEF84: .4byte 0x0202F354
_080EEF88: .4byte 0x0202F360
_080EEF8C: .4byte 0x01000008
_080EEF90: .4byte gSolidHeaderPtr
_080EEF94: .4byte gBossHeaderPtr
_080EEF98: .4byte gZakoHeaderPtr
_080EEF9C: .4byte 0x0203029C
_080EEFA0: .4byte gElfHeaderPtr
_080EEFA4: .4byte gProjectileHeaderPtr
_080EEFA8: .4byte gVFXHeaderPtr
_080EEFAC: .4byte gPickupHeaderPtr
_080EEFB0: .4byte gPaletteManager
_080EEFB4: .4byte 0x00000402
_080EEFB8: .4byte 0x00001EDC
_080EEFBC: .4byte gCurStory
_080EEFC0:
	movs r0, #0x25
	bl SetStageNoiseVolume
	movs r0, #0x26
	bl SetStageNoiseVolume
_080EEFCC:
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r5, #0
	bl SetGameMode
_080EEFD6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
