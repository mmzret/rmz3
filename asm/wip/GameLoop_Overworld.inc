	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080EE904 @ =gPause
	ldrb r0, [r0]
	mov sl, r0
	movs r1, #0
	ldr r2, _080EE908 @ =0x00001EDC
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080EE898
	ldr r0, _080EE90C @ =gLifeRecoverAmount
	ldr r0, [r0]
	cmp r0, #0
	bne _080EE898
	ldr r0, _080EE910 @ =0x0202F344
	ldrb r0, [r0]
	cmp r0, #0
	beq _080EE89A
_080EE898:
	movs r1, #1
_080EE89A:
	str r1, [sp, #8]
	ldr r3, _080EE914 @ =0x00001ED8
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r0, r7, r1
	bl ClearTaskBuffer
	ldr r1, _080EE918 @ =0x0202F354
	movs r0, #0
	strb r0, [r1]
	movs r0, #0
	ldr r1, _080EE91C @ =0x0202F360
	str r0, [sp]
	movs r4, #8
	ldr r2, _080EE920 @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	ldr r5, _080EE924 @ =gCurStory
	ldrb r0, [r5, #8]
	ands r4, r0
	cmp r4, #0
	beq _080EE980
	ldr r2, [sp, #8]
	cmp r2, #0
	bne _080EE980
	mov r3, sl
	cmp r3, #0
	bne _080EE980
	ldr r4, _080EE928 @ =0x0202F33C
	ldrh r1, [r4]
	adds r2, r1, #0
	cmp r2, #0
	beq _080EE964
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080EE930
	bl TurnDownBGM
	movs r0, #0x25
	bl PlaySound
	ldrh r1, [r4]
	ldr r0, _080EE92C @ =0x00007FFF
	ands r0, r1
	strh r0, [r4]
	b _080EE954
	.align 2, 0
_080EE904: .4byte gPause
_080EE908: .4byte 0x00001EDC
_080EE90C: .4byte gLifeRecoverAmount
_080EE910: .4byte 0x0202F344
_080EE914: .4byte 0x00001ED8
_080EE918: .4byte 0x0202F354
_080EE91C: .4byte 0x0202F360
_080EE920: .4byte 0x01000008
_080EE924: .4byte gCurStory
_080EE928: .4byte 0x0202F33C
_080EE92C: .4byte 0x00007FFF
_080EE930:
	cmp r2, #0xb3
	bhi _080EE954
	movs r0, #0x25
	bl isSoundPlaying
	cmp r0, #0
	beq _080EE944
	movs r0, #0x25
	bl stopSound
_080EE944:
	movs r0, #0x26
	bl isSoundPlaying
	cmp r0, #0
	bne _080EE954
	movs r0, #0x26
	bl PlaySound
_080EE954:
	ldr r1, _080EE960 @ =0x0202F33C
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080EE980
	.align 2, 0
_080EE960: .4byte 0x0202F33C
_080EE964:
	bl TurnUpBGM
	ldrb r0, [r5, #8]
	movs r1, #0xf7
	ands r1, r0
	strb r1, [r5, #8]
	movs r0, #0x26
	bl isSoundPlaying
	cmp r0, #0
	beq _080EE980
	movs r0, #0x26
	bl stopSound
_080EE980:
	movs r0, #0
	ldr r1, [sp, #8]
	cmp r1, #0
	bne _080EE98E
	mov r2, sl
	cmp r2, #0
	beq _080EE990
_080EE98E:
	movs r0, #1
_080EE990:
	bl OverworldUpdate
	cmp r0, #0
	beq _080EE9C0
	ldr r2, _080EE9B8 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EE9BC @ =0x0000F0FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r7, #0
	bl SetGameMode
	b _080EEC50
	.align 2, 0
_080EE9B8: .4byte gVideoRegBuffer
_080EE9BC: .4byte 0x0000F0FF
_080EE9C0:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _080EE9C8
	b _080EEAC8
_080EE9C8:
	ldr r1, _080EEA98 @ =gStageRun
	ldrh r2, [r1, #8]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080EEA04
	ldrb r1, [r1, #0x12]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _080EEA04
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _080EEA04
	ldr r2, _080EEA9C @ =gMission
	ldr r1, [r2, #8]
	ldr r0, _080EEAA0 @ =0x00057E3E
	cmp r1, r0
	bhi _080EE9F6
	adds r0, r1, #1
	str r0, [r2, #8]
_080EE9F6:
	ldr r2, [r2]
	ldr r1, [r2, #0xc]
	ldr r0, _080EEAA4 @ =0x014996FE
	cmp r1, r0
	bhi _080EEA04
	adds r0, r1, #1
	str r0, [r2, #0xc]
_080EEA04:
	bl FUN_0802511c
	mov r1, sl
	cmp r1, #0
	bne _080EEA42
	ldr r0, _080EEAA8 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl UpdateHazardEntities
	ldr r0, _080EEAAC @ =gBossHeaderPtr
	ldr r0, [r0]
	bl UpdateHazardEntities
	ldr r0, _080EEAB0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl UpdateHazardEntities
	ldr r0, _080EEAB4 @ =0x0203029C
	ldr r0, [r0]
	bl UpdateEntities
	bl UpdateProjectiles
	ldr r0, _080EEAB8 @ =gWeaponHeaderPtr
	ldr r0, [r0]
	bl UpdateEntities
	ldr r0, _080EEABC @ =gPickupHeaderPtr
	ldr r0, [r0]
	bl UpdateEntities
_080EEA42:
	ldr r4, _080EEAC0 @ =gElfHeaderPtr
	ldr r0, [r4]
	bl UpdateHazardEntities
	bl UpdateVFXs
	bl ClearAllHitboxes
	mov r2, sl
	cmp r2, #0
	bne _080EEACC
	ldr r0, _080EEAA8 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl RegisterHitboxes
	ldr r0, _080EEAAC @ =gBossHeaderPtr
	ldr r0, [r0]
	bl RegisterHitboxes
	ldr r0, _080EEAB0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl RegisterHitboxes
	ldr r0, _080EEAB4 @ =0x0203029C
	ldr r0, [r0]
	bl RegisterHitboxes
	ldr r0, _080EEAC4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl RegisterHitboxes
	ldr r0, _080EEAB8 @ =gWeaponHeaderPtr
	ldr r0, [r0]
	bl RegisterHitboxes
	ldr r0, _080EEABC @ =gPickupHeaderPtr
	ldr r0, [r0]
	bl RegisterHitboxes
	ldr r0, [r4]
	bl RegisterHitboxes
	b _080EEACC
	.align 2, 0
_080EEA98: .4byte gStageRun
_080EEA9C: .4byte gMission
_080EEAA0: .4byte 0x00057E3E
_080EEAA4: .4byte 0x014996FE
_080EEAA8: .4byte gSolidHeaderPtr
_080EEAAC: .4byte gBossHeaderPtr
_080EEAB0: .4byte gZakoHeaderPtr
_080EEAB4: .4byte 0x0203029C
_080EEAB8: .4byte gWeaponHeaderPtr
_080EEABC: .4byte gPickupHeaderPtr
_080EEAC0: .4byte gElfHeaderPtr
_080EEAC4: .4byte gProjectileHeaderPtr
_080EEAC8:
	bl ClearAllHitboxes
_080EEACC:
	adds r0, r7, #0
	bl CheckItemGain
	bl CheckCollision
	ldr r4, _080EEC60 @ =gSolidHeaderPtr
	ldr r0, [r4]
	bl RunDamageEffect
	ldr r5, _080EEC64 @ =gBossHeaderPtr
	ldr r0, [r5]
	bl RunDamageEffect
	ldr r6, _080EEC68 @ =gZakoHeaderPtr
	ldr r0, [r6]
	bl RunDamageEffect
	ldr r3, _080EEC6C @ =0x0203029C
	mov r8, r3
	ldr r0, [r3]
	bl RunDamageEffect
	ldr r0, _080EEC70 @ =gPickupHeaderPtr
	mov sb, r0
	ldr r0, [r0]
	bl RunDamageEffect
	ldr r0, [r4]
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r4, r7, r1
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, [r5]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, [r6]
	adds r1, r4, #0
	bl DrawCollidableEntity
	mov r2, r8
	ldr r0, [r2]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, _080EEC74 @ =gElfHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	adds r0, r4, #0
	bl DrawWeapon
	ldr r0, _080EEC78 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	ldr r0, _080EEC7C @ =gVFXHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	mov r3, sb
	ldr r0, [r3]
	adds r1, r4, #0
	bl DrawCollidableEntity
	adds r0, r7, #0
	bl DrawHUD
	bl UpdateTextWindow
	adds r0, r7, #0
	bl RunOverworldLoop
	ldr r0, _080EEC80 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080EEC08
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	bne _080EEC08
	ldr r1, _080EEC84 @ =0x000064AC
	adds r0, r7, r1
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080EEC08
	adds r0, r2, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080EEC08
	ldr r1, _080EEC88 @ =gTextWindow+8
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq _080EEBAE
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _080EEC08
_080EEBAE:
	ldr r2, _080EEC8C @ =gStageRun
	ldrh r1, [r2, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _080EEC08
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080EEC08
	ldrb r1, [r2, #0x12]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _080EEC08
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080EEC08
	ldr r0, _080EEC90 @ =gGameState
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _080EEC08
	mov r2, sl
	cmp r2, #0
	bne _080EEC08
	ldr r0, _080EEC94 @ =wMOSAIC
	ldrh r0, [r0]
	cmp r0, #0
	bne _080EEC08
	ldr r0, _080EEC98 @ =gLifeRecoverAmount
	ldr r0, [r0]
	cmp r0, #0
	bne _080EEC08
	ldr r1, _080EEC9C @ =0x00001EDC
	adds r0, r7, r1
	strh r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r7, #0
	bl SetGameMode
_080EEC08:
	movs r0, #0
	ldr r2, [sp, #8]
	cmp r2, #0
	bne _080EEC16
	mov r3, sl
	cmp r3, #0
	beq _080EEC18
_080EEC16:
	movs r0, #1
_080EEC18:
	bl CameraUpdate
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _080EEC48
	mov r1, sl
	cmp r1, #0
	bne _080EEC48
	ldr r0, _080EECA0 @ =0x0202F330
	ldrb r0, [r0]
	cmp r0, #0
	beq _080EEC42
	ldr r0, _080EECA4 @ =gCollisionManager
	ldrb r1, [r0, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080EEC42
	movs r0, #0x29
	bl PlaySound
_080EEC42:
	ldr r1, _080EECA0 @ =0x0202F330
	movs r0, #0
	strb r0, [r1]
_080EEC48:
	ldr r0, _080EECA8 @ =0x0202F344
	ldr r1, _080EECA4 @ =gCollisionManager
	ldrb r1, [r1, #2]
	strb r1, [r0]
_080EEC50:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EEC60: .4byte gSolidHeaderPtr
_080EEC64: .4byte gBossHeaderPtr
_080EEC68: .4byte gZakoHeaderPtr
_080EEC6C: .4byte 0x0203029C
_080EEC70: .4byte gPickupHeaderPtr
_080EEC74: .4byte gElfHeaderPtr
_080EEC78: .4byte gProjectileHeaderPtr
_080EEC7C: .4byte gVFXHeaderPtr
_080EEC80: .4byte gJoypad
_080EEC84: .4byte 0x000064AC
_080EEC88: .4byte gTextWindow+8
_080EEC8C: .4byte gStageRun
_080EEC90: .4byte gGameState
_080EEC94: .4byte wMOSAIC
_080EEC98: .4byte gLifeRecoverAmount
_080EEC9C: .4byte 0x00001EDC
_080EECA0: .4byte 0x0202F330
_080EECA4: .4byte gCollisionManager
_080EECA8: .4byte 0x0202F344
