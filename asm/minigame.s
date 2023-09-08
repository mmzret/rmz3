	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start MinigameLoop_Main
MinigameLoop_Main: @ 0x080F8F5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	movs r2, #4
	ldrsh r1, [r6, r2]
	cmp r1, #0x1f
	bgt _080F8F90
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r6, #4]
	ldr r2, _080F8F88 @ =gPaletteManager
	ldr r3, _080F8F8C @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	b _080F8FA4
	.align 2, 0
_080F8F88: .4byte gPaletteManager
_080F8F8C: .4byte 0x00000402
_080F8F90:
	cmp r1, #0x20
	ble _080F8FB4
	subs r0, #1
	strh r0, [r6, #4]
	ldr r2, _080F9170 @ =gPaletteManager
	subs r0, #0x20
	ldr r3, _080F9174 @ =0x00000402
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0xff
_080F8FA4:
	ands r0, r1
	subs r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
_080F8FB4:
	ldr r2, _080F9178 @ =0x00001ED8
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r3, #0x9a
	lsls r3, r3, #4
	adds r0, r6, r3
	bl ClearTaskBuffer
	ldr r1, _080F917C @ =0x0202F354
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080F9180 @ =0x0202F360
	movs r0, #0
	str r0, [sp]
	ldr r2, _080F9184 @ =0x001FFFFF
	mov sl, r2
	ldr r2, _080F9188 @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	ldr r1, _080F918C @ =0x08386AB4
	ldrb r0, [r6, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	cmp r0, #0
	bne _080F8FFA
	ldrb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #2]
_080F8FFA:
	ldrb r0, [r6, #1]
	cmp r0, #1
	beq _080F9058
	ldr r7, _080F9190 @ =0x020023D4
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r3, r3, r7
	mov sb, r3
	subs r0, r7, #2
	mov r8, r0
	ldrb r0, [r0]
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #3
	adds r5, r4, #0
	movs r0, #0x20
	rsbs r0, r0, #0
	ands r5, r0
	lsrs r2, r5, #2
	mov r1, sl
	ands r2, r1
	adds r0, r7, #0
	mov r1, sb
	bl CpuFastSet
	movs r0, #0x1f
	ands r4, r0
	cmp r4, #0
	beq _080F904A
	adds r0, r5, r7
	mov r2, sb
	adds r1, r5, r2
	lsrs r2, r4, #2
	mov r3, sl
	ands r2, r3
	movs r3, #0x80
	lsls r3, r3, #0x13
	orrs r2, r3
	bl CpuSet
_080F904A:
	mov r0, r8
	ldrb r1, [r0]
	subs r0, r7, #1
	strb r1, [r0]
	movs r2, #0
	mov r1, r8
	strb r2, [r1]
_080F9058:
	ldr r5, _080F9194 @ =gSolidHeaderPtr
	ldr r0, [r5]
	bl UpdateBlockingEntities
	ldr r7, _080F9198 @ =gZakoHeaderPtr
	ldr r0, [r7]
	bl UpdateBlockingEntities
	ldr r3, _080F919C @ =0x0203029C
	mov r8, r3
	ldr r0, [r3]
	bl UpdateEntities
	bl UpdateProjectiles
	ldr r4, _080F91A0 @ =gWeaponHeaderPtr
	ldr r0, [r4]
	bl UpdateEntities
	ldr r0, _080F91A4 @ =gMapItemHeaderPtr
	mov sb, r0
	ldr r0, [r0]
	bl UpdateEntities
	bl UpdateVFXs
	bl ClearAllHitboxes
	ldr r0, [r5]
	bl RegisterHitboxes
	ldr r0, [r7]
	bl RegisterHitboxes
	mov r1, r8
	ldr r0, [r1]
	bl RegisterHitboxes
	ldr r2, _080F91A8 @ =gProjectileHeaderPtr
	mov sl, r2
	ldr r0, [r2]
	bl RegisterHitboxes
	ldr r0, [r4]
	bl RegisterHitboxes
	mov r3, sb
	ldr r0, [r3]
	bl RegisterHitboxes
	ldrb r0, [r6, #1]
	cmp r0, #1
	beq _080F90CA
	ldr r1, _080F91AC @ =0x00000DC4
	adds r0, r6, r1
	bl UpdateStageLandscape
_080F90CA:
	bl CheckCollision
	ldr r0, [r5]
	bl RunDamageEffect
	ldr r0, [r7]
	bl RunDamageEffect
	mov r2, r8
	ldr r0, [r2]
	bl RunDamageEffect
	mov r3, sb
	ldr r0, [r3]
	bl RunDamageEffect
	ldr r0, [r5]
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r4, r6, r1
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldr r0, [r7]
	adds r1, r4, #0
	bl DrawCollidableEntity
	mov r2, r8
	ldr r0, [r2]
	adds r1, r4, #0
	bl DrawCollidableEntity
	adds r0, r4, #0
	bl DrawWeapon
	mov r3, sl
	ldr r0, [r3]
	adds r1, r4, #0
	bl DrawEntity
	ldr r0, _080F91B0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	adds r1, r4, #0
	bl DrawEntity
	mov r1, sb
	ldr r0, [r1]
	adds r1, r4, #0
	bl DrawCollidableEntity
	ldrb r0, [r6, #1]
	cmp r0, #1
	beq _080F913A
	adds r0, r4, #0
	bl DrawOverworld
_080F913A:
	adds r0, r4, #0
	bl RunAllTasks
	ldr r0, _080F91B4 @ =0x0202F330
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F915A
	ldr r0, _080F91B8 @ =gCollisionManager
	ldrb r1, [r0, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080F915A
	movs r0, #0x29
	bl PlaySound
_080F915A:
	ldr r1, _080F91B4 @ =0x0202F330
	movs r0, #0
	strb r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F9170: .4byte gPaletteManager
_080F9174: .4byte 0x00000402
_080F9178: .4byte 0x00001ED8
_080F917C: .4byte 0x0202F354
_080F9180: .4byte 0x0202F360
_080F9184: .4byte 0x001FFFFF
_080F9188: .4byte 0x01000008
_080F918C: .4byte 0x08386AB4
_080F9190: .4byte 0x020023D4
_080F9194: .4byte gSolidHeaderPtr
_080F9198: .4byte gZakoHeaderPtr
_080F919C: .4byte 0x0203029C
_080F91A0: .4byte gWeaponHeaderPtr
_080F91A4: .4byte gMapItemHeaderPtr
_080F91A8: .4byte gProjectileHeaderPtr
_080F91AC: .4byte 0x00000DC4
_080F91B0: .4byte gVFXHeaderPtr
_080F91B4: .4byte 0x0202F330
_080F91B8: .4byte gCollisionManager

	thumb_func_start MinigameLoop_ExitMinigame
MinigameLoop_ExitMinigame: @ 0x080F91BC
	push {lr}
	ldr r2, _080F91E0 @ =0x08386AD0
	ldrb r1, [r0, #1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	cmp r0, #0
	bne _080F91DC
	bl ExitStageLandscape
	bl ClearBlinkings
	bl ExitProcess
_080F91DC:
	pop {r0}
	bx r0
	.align 2, 0
_080F91E0: .4byte 0x08386AD0

	thumb_func_start initZeroMinigame
initZeroMinigame: @ 0x080F91E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r7, _080F9384 @ =0x00000DCC
	add r7, sl
	ldr r1, _080F9388 @ =0x00000DC4
	add r1, sl
	ldr r0, _080F938C @ =0x002E6800
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r1, #4]
	movs r0, #3
	bl ResetLandscape
	ldr r4, _080F9390 @ =0x0000058C
	ldr r1, _080F9394 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080F9398 @ =wStaticGraphicTilenums
	adds r1, #0x8e
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080F939C @ =gStaticMotionGraphics+12
	mov r8, r0
	add r4, r8
	ldr r6, _080F93A0 @ =wStaticMotionPalIDs
	adds r0, r6, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0x9e
	lsls r5, r4, #1
	ldr r1, _080F9398 @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xe1
	lsls r1, r1, #2
	strh r1, [r0]
	adds r5, r6, r5
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r4, r4, r2
	ldr r2, _080F9394 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xf0
	ldr r0, _080F9398 @ =wStaticGraphicTilenums
	strh r1, [r0]
	movs r0, #0xe
	strh r0, [r6]
	ldr r2, _080F9394 @ =gStaticMotionGraphics
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r2, #0
	bl LoadGraphic
	ldrh r1, [r6]
	mov r2, r8
	ldrb r0, [r2, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	mov r0, r8
	bl LoadPalette
	ldr r0, _080F938C @ =0x002E6800
	str r0, [sp, #4]
	movs r0, #0xb4
	lsls r0, r0, #8
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	bl CreateZeroMini
	str r0, [r7, #0x14]
	ldr r1, _080F93A4 @ =pZero2
	str r0, [r1]
	movs r1, #0
	add r6, sp, #4
	movs r5, #0x80
	lsls r5, r5, #5
_080F92E2:
	adds r4, r1, #1
	ldr r0, _080F93A8 @ =0x002ED800
	subs r0, r0, r5
	str r0, [sp, #4]
	movs r0, #0x94
	lsls r0, r0, #9
	str r0, [r6, #4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	adds r3, r7, #0
	adds r3, #0xc
	bl FUN_080c82b8
	movs r1, #0x80
	lsls r1, r1, #5
	adds r5, r5, r1
	adds r1, r4, #0
	cmp r1, #2
	ble _080F92E2
	movs r4, #0
	movs r0, #3
	strb r0, [r7, #0xc]
	movs r5, #0
	strh r4, [r7]
	movs r0, #0x60
	mov r2, sl
	strh r0, [r2, #6]
	ldr r1, _080F93AC @ =gGameState
	ldr r0, _080F93B0 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080F93B4 @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080F93B8 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __umodsi3
	mov r1, sl
	strh r0, [r1, #8]
	strh r4, [r1, #0xa]
	strh r4, [r7, #4]
	strh r4, [r7, #6]
	strh r4, [r7, #8]
	strh r4, [r7, #0xa]
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	str r4, [r7, #0x30]
	str r4, [r7, #0x2c]
	strh r4, [r7, #0x38]
	movs r0, #0xe0
	lsls r0, r0, #1
	str r0, [r7, #0x34]
	strb r5, [r7, #0xd]
	strh r4, [r7, #0xe]
	str r4, [r7, #0x20]
	str r4, [r7, #0x24]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	strh r4, [r1, #4]
	ldr r0, _080F93BC @ =gSystemSavedataManager
	ldr r0, [r0, #0x24]
	str r0, [r7, #0x3c]
	strh r4, [r7, #0x3a]
	movs r0, #0xad
	bl playBGM
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F9384: .4byte 0x00000DCC
_080F9388: .4byte 0x00000DC4
_080F938C: .4byte 0x002E6800
_080F9390: .4byte 0x0000058C
_080F9394: .4byte gStaticMotionGraphics
_080F9398: .4byte wStaticGraphicTilenums
_080F939C: .4byte gStaticMotionGraphics+12
_080F93A0: .4byte wStaticMotionPalIDs
_080F93A4: .4byte pZero2
_080F93A8: .4byte 0x002ED800
_080F93AC: .4byte gGameState
_080F93B0: .4byte 0x0000626C
_080F93B4: .4byte 0x41C64E6D
_080F93B8: .4byte 0x00003039
_080F93BC: .4byte gSystemSavedataManager

	thumb_func_start zeroMinigame
zeroMinigame: @ 0x080F93C0
	push {lr}
	ldr r2, _080F93DC @ =0x00000DCC
	adds r1, r0, r2
	ldr r2, _080F93E0 @ =0x08386AEC
	movs r3, #4
	ldrsh r1, [r1, r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_080F93DC: .4byte 0x00000DCC
_080F93E0: .4byte 0x08386AEC

	thumb_func_start zeroMinigamePhase0
zeroMinigamePhase0: @ 0x080F93E4
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080F9400 @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080F9418
	cmp r0, #1
	bgt _080F9404
	cmp r0, #0
	beq _080F940E
	b _080F9452
	.align 2, 0
_080F9400: .4byte 0x00000DCC
_080F9404:
	cmp r0, #2
	beq _080F942C
	cmp r0, #3
	beq _080F9440
	b _080F9452
_080F940E:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F9418:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080F9452
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080F9452
_080F942C:
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0x1d
	bl PlaySound
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F9440:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080F9452
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080F9452:
	ldr r1, _080F94A8 @ =0x0810E248
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r4, [r5, #0x38]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080F947A
	str r4, [r5, #0x3c]
_080F947A:
	add r4, sp, #8
	ldr r1, _080F94AC @ =0x0810E250
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	movs r0, #1
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080F94A8: .4byte 0x0810E248
_080F94AC: .4byte 0x0810E250

	thumb_func_start zeroMinigamePhase1
zeroMinigamePhase1: @ 0x080F94B0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r0, _080F94E8 @ =0x00000DCC
	adds r5, r4, r0
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldr r1, [r5, #0x30]
	ldr r0, _080F94EC @ =0x0003BFFF
	cmp r1, r0
	ble _080F94F8
	ldr r1, _080F94F0 @ =0x00000DC4
	adds r2, r4, r1
	ldr r0, [r2]
	ldr r1, _080F94F4 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r5, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x30]
	ldr r2, [r5, #0x14]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r2, #0x54]
	movs r0, #1
	b _080F94FA
	.align 2, 0
_080F94E8: .4byte 0x00000DCC
_080F94EC: .4byte 0x0003BFFF
_080F94F0: .4byte 0x00000DC4
_080F94F4: .4byte 0xFFFC4000
_080F94F8:
	movs r0, #0
_080F94FA:
	strb r0, [r5, #0xd]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r0, [r5, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080F950C
	b _080F96D4
_080F950C:
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #6
	ldrsh r1, [r4, r3]
	bl __modsi3
	cmp r0, #0
	beq _080F951E
	b _080F96D4
_080F951E:
	ldrh r6, [r5, #0xe]
	adds r0, r6, #1
	movs r1, #0xa
	bl __modsi3
	cmp r0, #0
	bne _080F95C4
	ldr r1, _080F9574 @ =gGameState
	ldr r0, _080F9578 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080F957C @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080F9580 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	adds r0, #2
	strh r0, [r4, #8]
	ands r0, r1
	cmp r0, #0
	beq _080F958C
	ldr r1, _080F9584 @ =Coord_ARRAY_08386af8
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _080F9588 @ =0x002EE000
	adds r0, r0, r2
	str r0, [sp, #0x14]
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	b _080F95B0
	.align 2, 0
_080F9574: .4byte gGameState
_080F9578: .4byte 0x0000626C
_080F957C: .4byte 0x41C64E6D
_080F9580: .4byte 0x00003039
_080F9584: .4byte Coord_ARRAY_08386af8
_080F9588: .4byte 0x002EE000
_080F958C:
	ldr r1, _080F95BC @ =Coord_ARRAY_08386af8
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F95C0 @ =0x002DF000
	adds r0, r0, r3
	str r0, [sp, #0x14]
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r0, r3
_080F95B0:
	add r1, sp, #0x14
	str r0, [r1, #4]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #1
	b _080F9654
	.align 2, 0
_080F95BC: .4byte Coord_ARRAY_08386af8
_080F95C0: .4byte 0x002DF000
_080F95C4:
	adds r0, r6, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080F95EE
	ldr r1, _080F960C @ =gGameState
	ldr r0, _080F9610 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080F9614 @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080F9618 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __umodsi3
	strh r0, [r4, #8]
_080F95EE:
	ldrh r1, [r4, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080F9624
	ldr r1, _080F961C @ =Coord_ARRAY_08386af8
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _080F9620 @ =0x002EE000
	adds r0, r0, r2
	b _080F9634
	.align 2, 0
_080F960C: .4byte gGameState
_080F9610: .4byte 0x0000626C
_080F9614: .4byte 0x41C64E6D
_080F9618: .4byte 0x00003039
_080F961C: .4byte Coord_ARRAY_08386af8
_080F9620: .4byte 0x002EE000
_080F9624:
	ldr r1, _080F9678 @ =Coord_ARRAY_08386af8
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F967C @ =0x002DF000
	adds r0, r0, r3
_080F9634:
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r2, #4]
	adds r1, r2, #0
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
_080F9654:
	bl FUN_0809aff0
	adds r2, r0, #0
	cmp r2, #0
	beq _080F96D4
	ldrh r1, [r4, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080F9688
	ldr r1, _080F9680 @ =Coord_ARRAY_08386b28
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F9684 @ =0x002EE000
	b _080F9696
	.align 2, 0
_080F9678: .4byte Coord_ARRAY_08386af8
_080F967C: .4byte 0x002DF000
_080F9680: .4byte Coord_ARRAY_08386b28
_080F9684: .4byte 0x002EE000
_080F9688:
	ldr r1, _080F96C0 @ =Coord_ARRAY_08386b28
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F96C4 @ =0x002DF000
_080F9696:
	adds r0, r0, r3
	str r0, [r2, #0x64]
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r2, #0x68]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _080F96C8
	movs r0, #0x58
	b _080F96D2
	.align 2, 0
_080F96C0: .4byte Coord_ARRAY_08386b28
_080F96C4: .4byte 0x002DF000
_080F96C8:
	cmp r0, #0x27
	bhi _080F96D0
	movs r0, #0x4c
	b _080F96D2
_080F96D0:
	movs r0, #0x40
_080F96D2:
	strh r0, [r4, #6]
_080F96D4:
	ldr r1, _080F9748 @ =0x0810E248
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r4, [r5, #0x38]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080F970E
	str r4, [r5, #0x3c]
	ldrh r0, [r5, #0x3a]
	cmp r0, #0
	bne _080F970E
	movs r0, #1
	strh r0, [r5, #0x3a]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
_080F970E:
	add r4, sp, #8
	ldr r1, _080F974C @ =0x0810E250
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldrb r1, [r5, #0xc]
	cmp r1, #0
	bne _080F973E
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080F973E:
	movs r0, #1
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080F9748: .4byte 0x0810E248
_080F974C: .4byte 0x0810E250

	thumb_func_start zeroMinigamePhase2
zeroMinigamePhase2: @ 0x080F9750
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080F976C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080F97EC
	lsls r0, r0, #2
	ldr r1, _080F9770 @ =_080F9774
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F976C: .4byte 0x00000DCC
_080F9770: .4byte _080F9774
_080F9774: @ jump table
	.4byte _080F978C @ case 0
	.4byte _080F9796 @ case 1
	.4byte _080F97A4 @ case 2
	.4byte _080F97B8 @ case 3
	.4byte _080F97C8 @ case 4
	.4byte _080F97D4 @ case 5
_080F978C:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F9796:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080F97EC
	b _080F97C0
_080F97A4:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xad
	bl fadeoutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F97B8:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080F97EC
_080F97C0:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080F97EC
_080F97C8:
	ldr r1, _080F97E8 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F97D4:
	ldr r0, _080F97E8 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080F97EC
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080F9838
	.align 2, 0
_080F97E8: .4byte gGameState
_080F97EC:
	ldr r1, _080F9840 @ =0x0810E248
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r4, [r5, #0x38]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080F9814
	str r4, [r5, #0x3c]
_080F9814:
	add r4, sp, #8
	ldr r1, _080F9844 @ =0x0810E250
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	movs r0, #1
_080F9838:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080F9840: .4byte 0x0810E248
_080F9844: .4byte 0x0810E250

	thumb_func_start exitZeroMinigame
exitZeroMinigame: @ 0x080F9848
	push {lr}
	ldr r2, _080F9864 @ =0x00000DCC
	adds r1, r0, r2
	ldrh r2, [r1, #6]
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _080F9868
	movs r0, #2
	strh r0, [r1]
	adds r0, r2, #1
	strh r0, [r1, #6]
	b _080F9898
	.align 2, 0
_080F9864: .4byte 0x00000DCC
_080F9868:
	cmp r0, #1
	bne _080F9898
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080F9880
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080F9898
_080F9880:
	ldr r2, _080F9894 @ =gSystemSavedataManager
	ldr r1, [r1, #0x3c]
	ldr r0, [r2, #0x24]
	cmp r1, r0
	bls _080F9890
	str r1, [r2, #0x24]
	bl SaveSystemData
_080F9890:
	movs r0, #0
	b _080F989A
	.align 2, 0
_080F9894: .4byte gSystemSavedataManager
_080F9898:
	movs r0, #1
_080F989A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start initCielMinigame
initCielMinigame: @ 0x080F98A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	ldr r0, _080F9BE0 @ =0x00000DC4
	adds r1, r7, r0
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r1, #4]
	ldr r2, _080F9BE4 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080F9BE8 @ =0x0000FFF8
	ands r0, r1
	ldr r1, _080F9BEC @ =0x0000F0FF
	ands r0, r1
	movs r3, #0xdc
	lsls r3, r3, #6
	adds r1, r3, #0
	movs r3, #0
	mov r4, sp
	strh r3, [r4, #0xc]
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _080F9BF0 @ =0x00000206
	adds r0, r4, #0
	strh r0, [r2, #6]
	ldr r1, _080F9BF4 @ =0x00000407
	adds r0, r1, #0
	strh r0, [r2, #8]
	movs r3, #0
	str r3, [r2, #0x10]
	str r3, [r2, #0x14]
	ldr r0, _080F9BF8 @ =0x08547C80
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, _080F9BFC @ =0x08547C8C
	movs r1, #0
	bl LoadPalette
	ldr r4, _080F9C00 @ =0x00000ED8
	adds r0, r7, r4
	ldr r4, _080F9C04 @ =gBgMapOffsets
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0x80
	movs r3, #0
	bl loadBgMap_08004248
	movs r2, #0
	str r2, [sp]
	movs r0, #0x24
	adds r1, r4, #0
	movs r2, #0x81
	movs r3, #0
	bl LoadBgMap
	ldr r5, _080F9C08 @ =0x00001234
	ldr r3, _080F9C0C @ =gStaticMotionGraphics
	mov sl, r3
	adds r0, r5, r3
	movs r4, #0xe9
	lsls r4, r4, #1
	ldr r2, _080F9C10 @ =wStaticGraphicTilenums
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	ldr r6, _080F9C14 @ =gStaticMotionGraphics+12
	adds r5, r5, r6
	ldr r0, _080F9C18 @ =wStaticMotionPalIDs
	mov sb, r0
	add r4, sb
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	add r1, r8
	adds r0, r5, #0
	bl LoadPalette
	ldr r5, _080F9C1C @ =0x00001248
	mov r3, sl
	adds r0, r5, r3
	movs r4, #0xea
	lsls r4, r4, #1
	ldr r2, _080F9C10 @ =wStaticGraphicTilenums
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	adds r5, r5, r6
	add r4, sb
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r5, #0
	bl LoadPalette
	ldr r4, _080F9C10 @ =wStaticGraphicTilenums
	ldrh r1, [r4]
	mov r2, sl
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	mov r0, sl
	bl LoadGraphic
	mov r4, sb
	ldrh r1, [r4]
	ldrb r0, [r6, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r6, #0
	bl LoadPalette
	ldr r0, _080F9C20 @ =0x00000DCC
	adds r1, r7, r0
	mov r2, sp
	ldrb r2, [r2, #0xc]
	strb r2, [r1, #4]
	mov r3, sp
	ldrb r3, [r3, #0xc]
	strb r3, [r1, #5]
	movs r4, #0
	str r4, [r1, #8]
	ldr r0, _080F9C24 @ =gSystemSavedataManager
	ldr r0, [r0, #0x28]
	str r0, [r1, #0xc]
	strh r4, [r1, #6]
	movs r5, #0
	ldr r0, _080F9C28 @ =0x00000DE4
	adds r2, r7, r0
	movs r3, #0xff
_080F99EC:
	adds r0, r2, r5
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F99EC
	ldr r1, _080F9C20 @ =0x00000DCC
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0, #0x10]
	movs r1, #0x78
	strh r1, [r0, #0x12]
	movs r5, #0
	movs r2, #0xde
	lsls r2, r2, #4
	adds r2, r2, r7
	mov r8, r2
	ldr r3, _080F9C2C @ =0x00000DE9
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0xdf
	lsls r4, r4, #4
	adds r4, r4, r7
	mov sl, r4
	ldr r0, _080F9C30 @ =0x00000E04
	adds r0, r7, r0
	str r0, [sp, #0x18]
	ldr r1, _080F9C34 @ =0x00000DEE
	adds r1, r7, r1
	str r1, [sp, #0x10]
	ldr r2, _080F9C38 @ =0x00000DEF
	adds r2, r7, r2
	str r2, [sp, #0x14]
	ldr r3, _080F9C3C @ =0x00000E0F
	adds r3, r7, r3
	str r3, [sp, #0x20]
	ldr r4, _080F9C40 @ =0x00000E0E
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	movs r0, #0xe1
	lsls r0, r0, #4
	adds r0, r7, r0
	str r0, [sp, #0x24]
	ldr r1, _080F9C44 @ =0x00000E12
	adds r1, r7, r1
	str r1, [sp, #0x28]
	ldr r2, _080F9C48 @ =0x00000E13
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	ldr r3, _080F9C4C @ =0x00000E14
	adds r3, r7, r3
	str r3, [sp, #0x30]
	ldr r4, _080F9C50 @ =0x00000E15
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r0, _080F9C54 @ =0x00000E16
	adds r0, r7, r0
	str r0, [sp, #0x38]
	ldr r1, _080F9C58 @ =0x00000E17
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _080F9C5C @ =0x02036DCC
_080F9A6E:
	mov r2, r8
	adds r4, r2, r5
	ldr r1, [r6]
	ldr r0, _080F9C60 @ =0x41C64E6D
	muls r0, r1, r0
	ldr r3, _080F9C64 @ =0x00003039
	adds r0, r0, r3
	str r0, [r6]
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	strb r0, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _080F9A6E
	movs r5, #0
	mov r1, sb
	movs r2, #0
_080F9A98:
	adds r0, r1, r5
	strb r2, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F9A98
	movs r5, #0
	mov r2, sl
	movs r4, #0
	movs r3, #0xff
	ldr r1, [sp, #0x18]
_080F9AB0:
	lsls r0, r5, #1
	adds r0, r2, r0
	strh r3, [r0]
	adds r0, r1, r5
	strb r4, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #9
	bls _080F9AB0
	ldr r4, _080F9C20 @ =0x00000DCC
	adds r1, r7, r4
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x24]
	movs r0, #1
	strh r0, [r1, #0x28]
	movs r0, #2
	strh r0, [r1, #0x2e]
	movs r0, #3
	strh r0, [r1, #0x32]
	movs r0, #4
	strh r0, [r1, #0x34]
	ldr r0, [sp, #0x10]
	strb r2, [r0]
	ldr r1, [sp, #0x14]
	strb r2, [r1]
	movs r5, #0
_080F9AE8:
	adds r0, r7, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_080b221c
	adds r0, r7, #0
	movs r1, #1
	adds r2, r5, #0
	bl FUN_080b221c
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F9AE8
	movs r5, #0
_080F9B08:
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0809c1cc
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _080F9B08
	movs r5, #0
_080F9B1E:
	adds r0, r7, #0
	movs r1, #0
	adds r2, r5, #0
	bl createCielMiniObj
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #9
	bls _080F9B1E
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl createCielMiniObj
	movs r0, #0xd8
	lsls r0, r0, #8
	movs r1, #0xb0
	lsls r1, r1, #7
	ldr r3, _080F9C68 @ =0x00000DD8
	adds r2, r7, r3
	movs r3, #0
	str r3, [sp]
	movs r3, #5
	str r3, [sp, #4]
	movs r5, #1
	str r5, [sp, #8]
	movs r3, #0
	bl CreateGhost79_1
	ldr r4, _080F9C20 @ =0x00000DCC
	adds r1, r7, r4
	str r0, [r1]
	ldr r0, _080F9C6C @ =gZakoHeaderPtr
	ldr r0, [r0]
	ldrh r0, [r0, #0xa]
	ldr r1, [sp, #0x20]
	strb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	movs r4, #0
	movs r0, #0x40
	ldr r3, [sp, #0x24]
	strh r0, [r3]
	ldr r0, [sp, #0x28]
	strb r5, [r0]
	ldr r1, [sp, #0x2c]
	strb r4, [r1]
	ldr r2, [sp, #0x30]
	strb r4, [r2]
	ldr r3, [sp, #0x34]
	strb r4, [r3]
	ldr r0, [sp, #0x38]
	strb r4, [r0]
	ldr r1, [sp, #0x3c]
	strb r4, [r1]
	movs r0, #0xd6
	movs r1, #0
	bl LoadBlink
	ldr r2, _080F9C70 @ =gWindowRegBuffer
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x12
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xe]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2, #0xe]
	ldr r0, _080F9C74 @ =0x0000D0E0
	strh r0, [r2, #4]
	ldr r0, _080F9C78 @ =0x00000838
	strh r0, [r2, #8]
	ldr r4, _080F9C00 @ =0x00000ED8
	adds r0, r7, r4
	ldr r1, _080F9C7C @ =gVideoRegBuffer+6
	ldrh r2, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	bl RequestBgMapTransfer
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F9BE0: .4byte 0x00000DC4
_080F9BE4: .4byte gVideoRegBuffer
_080F9BE8: .4byte 0x0000FFF8
_080F9BEC: .4byte 0x0000F0FF
_080F9BF0: .4byte 0x00000206
_080F9BF4: .4byte 0x00000407
_080F9BF8: .4byte 0x08547C80
_080F9BFC: .4byte 0x08547C8C
_080F9C00: .4byte 0x00000ED8
_080F9C04: .4byte gBgMapOffsets
_080F9C08: .4byte 0x00001234
_080F9C0C: .4byte gStaticMotionGraphics
_080F9C10: .4byte wStaticGraphicTilenums
_080F9C14: .4byte gStaticMotionGraphics+12
_080F9C18: .4byte wStaticMotionPalIDs
_080F9C1C: .4byte 0x00001248
_080F9C20: .4byte 0x00000DCC
_080F9C24: .4byte gSystemSavedataManager
_080F9C28: .4byte 0x00000DE4
_080F9C2C: .4byte 0x00000DE9
_080F9C30: .4byte 0x00000E04
_080F9C34: .4byte 0x00000DEE
_080F9C38: .4byte 0x00000DEF
_080F9C3C: .4byte 0x00000E0F
_080F9C40: .4byte 0x00000E0E
_080F9C44: .4byte 0x00000E12
_080F9C48: .4byte 0x00000E13
_080F9C4C: .4byte 0x00000E14
_080F9C50: .4byte 0x00000E15
_080F9C54: .4byte 0x00000E16
_080F9C58: .4byte 0x00000E17
_080F9C5C: .4byte 0x02036DCC
_080F9C60: .4byte 0x41C64E6D
_080F9C64: .4byte 0x00003039
_080F9C68: .4byte 0x00000DD8
_080F9C6C: .4byte gZakoHeaderPtr
_080F9C70: .4byte gWindowRegBuffer
_080F9C74: .4byte 0x0000D0E0
_080F9C78: .4byte 0x00000838
_080F9C7C: .4byte gVideoRegBuffer+6

	thumb_func_start cielMinigame
cielMinigame: @ 0x080F9C80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, _080F9CCC @ =0x00000DCC
	adds r4, r6, r0
	ldrh r0, [r4, #6]
	adds r0, #0x80
	strh r0, [r4, #6]
	ldr r1, _080F9CD0 @ =0x02002154
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r1]
	rsbs r0, r0, #0
	strh r0, [r1, #2]
	movs r0, #0xd6
	bl GetBlinkMotionState
	ldrb r0, [r4, #4]
	cmp r0, #2
	bhi _080F9CE0
	ldr r1, _080F9CD4 @ =0x00000E17
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0xf
	bhi _080F9CD8
	ldr r1, [r4]
	movs r0, #1
	strb r0, [r1, #0x13]
	b _080F9D32
	.align 2, 0
_080F9CCC: .4byte 0x00000DCC
_080F9CD0: .4byte 0x02002154
_080F9CD4: .4byte 0x00000E17
_080F9CD8:
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0x13]
	b _080F9D32
_080F9CE0:
	ldr r0, [r4]
	movs r1, #1
	strb r1, [r0, #0x13]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	cmp r0, r1
	bls _080F9D32
	adds r1, #1
	str r1, [r4, #0xc]
	ldr r2, _080F9D48 @ =0x00000E16
	adds r4, r6, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _080F9D12
	ldr r0, _080F9D4C @ =gSystemSavedataManager
	ldr r0, [r0, #0x28]
	cmp r0, r1
	bhs _080F9D12
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080F9D12:
	ldr r3, _080F9D50 @ =0x00000DCC
	adds r0, r6, r3
	ldr r0, [r0, #0xc]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080F9D32
	movs r0, #0x9c
	lsls r0, r0, #1
	bl isSoundPlaying
	cmp r0, #0
	bne _080F9D32
	ldr r0, _080F9D54 @ =0x00000137
	bl PlaySound
_080F9D32:
	ldr r4, _080F9D50 @ =0x00000DCC
	adds r0, r6, r4
	ldrb r0, [r0, #4]
	cmp r0, #5
	bls _080F9D3E
	b _080F9E74
_080F9D3E:
	lsls r0, r0, #2
	ldr r1, _080F9D58 @ =_080F9D5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F9D48: .4byte 0x00000E16
_080F9D4C: .4byte gSystemSavedataManager
_080F9D50: .4byte 0x00000DCC
_080F9D54: .4byte 0x00000137
_080F9D58: .4byte _080F9D5C
_080F9D5C: @ jump table
	.4byte _080F9D74 @ case 0
	.4byte _080F9D98 @ case 1
	.4byte _080F9DCC @ case 2
	.4byte _080F9DF8 @ case 3
	.4byte _080F9E30 @ case 4
	.4byte _080F9E60 @ case 5
_080F9D74:
	movs r0, #0x9b
	lsls r0, r0, #1
	bl playBGM
	ldr r0, _080F9D90 @ =0x00000DCC
	adds r2, r6, r0
	ldr r3, _080F9D94 @ =0x00000E15
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r2, #4]
	adds r0, #1
	strb r0, [r2, #4]
	b _080FA1FC
	.align 2, 0
_080F9D90: .4byte 0x00000DCC
_080F9D94: .4byte 0x00000E15
_080F9D98:
	ldr r4, _080F9DC4 @ =0x00000DCC
	adds r5, r6, r4
	ldr r0, _080F9DC8 @ =0x00000E15
	adds r4, r6, r0
	ldrb r0, [r4]
	adds r1, r0, #1
	strb r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bhi _080F9DB0
	b _080FA1FC
_080F9DB0:
	movs r0, #0
	bl CreateMissionAlert
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r5, #4]
	adds r0, #1
	strb r0, [r5, #4]
	b _080FA1FC
	.align 2, 0
_080F9DC4: .4byte 0x00000DCC
_080F9DC8: .4byte 0x00000E15
_080F9DCC:
	ldr r1, _080F9DF0 @ =0x00000DCC
	adds r3, r6, r1
	ldr r2, _080F9DF4 @ =0x00000E15
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r2, r1, #1
	strb r2, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x78
	bhi _080F9DE4
	b _080FA1FC
_080F9DE4:
	movs r0, #0
	str r0, [r3, #0xc]
	ldrb r0, [r3, #4]
	adds r0, #1
	strb r0, [r3, #4]
	b _080FA1FC
	.align 2, 0
_080F9DF0: .4byte 0x00000DCC
_080F9DF4: .4byte 0x00000E15
_080F9DF8:
	ldr r3, _080F9E24 @ =0x00000DCC
	adds r4, r6, r3
	ldr r1, _080F9E28 @ =0x00000E13
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _080F9E74
	movs r0, #4
	bl CreateMissionAlert
	movs r0, #0x9b
	lsls r0, r0, #1
	bl fadeoutBGM
	ldr r2, _080F9E2C @ =0x00000E15
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r4, #4]
	adds r0, #1
	strb r0, [r4, #4]
	b _080F9E74
	.align 2, 0
_080F9E24: .4byte 0x00000DCC
_080F9E28: .4byte 0x00000E13
_080F9E2C: .4byte 0x00000E15
_080F9E30:
	ldr r4, _080F9E54 @ =0x00000DCC
	adds r3, r6, r4
	ldr r1, _080F9E58 @ =0x00000E15
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r1, #1
	strb r2, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0xa0
	bls _080F9E74
	ldr r1, _080F9E5C @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrb r0, [r3, #4]
	adds r0, #1
	strb r0, [r3, #4]
	b _080F9E74
	.align 2, 0
_080F9E54: .4byte 0x00000DCC
_080F9E58: .4byte 0x00000E15
_080F9E5C: .4byte gGameState
_080F9E60:
	ldr r0, _080F9E70 @ =gGameState
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r0, #0x20
	bne _080F9E74
	movs r0, #0
	b _080FA1FE
	.align 2, 0
_080F9E70: .4byte gGameState
_080F9E74:
	ldr r4, _080F9F54 @ =0x00000DCC
	adds r3, r6, r4
	ldrh r0, [r3, #0x10]
	adds r0, #1
	strh r0, [r3, #0x10]
	ldrh r1, [r3, #0x12]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _080F9E8A
	strh r1, [r3, #0x10]
_080F9E8A:
	ldr r0, _080F9F58 @ =gZakoHeaderPtr
	ldr r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	ldr r4, _080F9F5C @ =0x00000E13
	adds r4, r6, r4
	str r4, [sp, #4]
	ldr r2, _080F9F60 @ =0x00000E14
	adds r2, r6, r2
	str r2, [sp, #8]
	cmp r0, #0
	bne _080F9EA4
	b _080F9FE2
_080F9EA4:
	ldr r4, _080F9F64 @ =0x00000E0F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r4, #0xa
	ldrsh r1, [r1, r4]
	mov r8, r0
	cmp r2, r1
	ble _080F9EB6
	b _080F9FE2
_080F9EB6:
	ldr r1, _080F9F68 @ =0x00000E12
	adds r0, r6, r1
	ldrb r1, [r0]
	str r0, [sp]
	cmp r1, #0
	bne _080F9EC4
	b _080F9FE2
_080F9EC4:
	ldrh r0, [r3, #0x10]
	ldrh r3, [r3, #0x12]
	cmp r0, r3
	beq _080F9ECE
	b _080F9FE2
_080F9ECE:
	ldr r4, _080F9F6C @ =gGameState
	ldr r3, _080F9F70 @ =0x0000626C
	adds r2, r4, r3
	ldr r1, [r2]
	ldr r0, _080F9F74 @ =0x41C64E6D
	muls r0, r1, r0
	ldr r1, _080F9F78 @ =0x00003039
	adds r0, r0, r1
	str r0, [r2]
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r5, #0
	ldr r2, _080F9F7C @ =0x00000DE4
	adds r7, r6, r2
	ldr r3, _080F9F54 @ =0x00000DCC
	adds r4, r6, r3
	mov sl, r5
_080F9EFA:
	mov r1, sb
	adds r0, r5, r1
	movs r1, #5
	bl __modsi3
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080F9FD8
	ldrb r0, [r4, #0x14]
	strb r0, [r1]
	ldrb r0, [r4, #0x15]
	strb r0, [r4, #0x14]
	ldrb r0, [r4, #0x16]
	strb r0, [r4, #0x15]
	ldrb r0, [r4, #0x17]
	strb r0, [r4, #0x16]
	ldr r3, _080F9F6C @ =gGameState
	ldr r0, _080F9F70 @ =0x0000626C
	adds r2, r3, r0
	ldr r1, [r2]
	ldr r0, _080F9F74 @ =0x41C64E6D
	muls r0, r1, r0
	ldr r1, _080F9F78 @ =0x00003039
	adds r0, r0, r1
	str r0, [r2]
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	strb r0, [r4, #0x17]
	mov r2, sl
	strh r2, [r4, #0x10]
	ldr r3, _080F9F80 @ =0x00000E0E
	adds r0, r6, r3
	ldrb r1, [r0]
	mov r2, r8
	ldrb r0, [r2]
	subs r1, r1, r0
	cmp r1, #0
	beq _080F9F84
	cmp r1, #1
	beq _080F9FB6
	b _080F9FCA
	.align 2, 0
_080F9F54: .4byte 0x00000DCC
_080F9F58: .4byte gZakoHeaderPtr
_080F9F5C: .4byte 0x00000E13
_080F9F60: .4byte 0x00000E14
_080F9F64: .4byte 0x00000E0F
_080F9F68: .4byte 0x00000E12
_080F9F6C: .4byte gGameState
_080F9F70: .4byte 0x0000626C
_080F9F74: .4byte 0x41C64E6D
_080F9F78: .4byte 0x00003039
_080F9F7C: .4byte 0x00000DE4
_080F9F80: .4byte 0x00000E0E
_080F9F84:
	movs r3, #0xe1
	lsls r3, r3, #4
	adds r5, r6, r3
	ldrh r0, [r5]
	ldr r1, _080F9F98 @ =0x0000017F
	cmp r0, r1
	bhi _080F9F9C
	adds r0, #0x14
	strh r0, [r5]
	b _080F9FCA
	.align 2, 0
_080F9F98: .4byte 0x0000017F
_080F9F9C:
	ldrb r0, [r4, #4]
	cmp r0, #3
	bhi _080F9FCA
	movs r0, #6
	bl PlaySound
	movs r0, #0x40
	strh r0, [r5]
	mov r2, r8
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _080F9FCA
_080F9FB6:
	movs r3, #0xe1
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrh r1, [r2]
	ldr r0, _080F9FD4 @ =0x000003FF
	cmp r1, r0
	bhi _080F9FCA
	adds r0, r1, #0
	adds r0, #0x14
	strh r0, [r2]
_080F9FCA:
	mov r0, sl
	ldr r4, [sp]
	strb r0, [r4]
	b _080F9FE2
	.align 2, 0
_080F9FD4: .4byte 0x000003FF
_080F9FD8:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _080F9EFA
_080F9FE2:
	ldr r1, _080FA020 @ =0x00000DCC
	adds r0, r6, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080FA092
	ldr r2, _080FA024 @ =gJoypad
	ldrh r1, [r2, #4]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080FA03C
	ldr r2, _080FA028 @ =0x00000DEE
	adds r0, r6, r2
	ldrb r1, [r0]
	ldr r3, _080FA02C @ =0x00000E04
	adds r0, r6, r3
	adds r0, r0, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _080FA092
	lsls r0, r1, #1
	movs r4, #0xdf
	lsls r4, r4, #4
	adds r1, r6, r4
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0xff
	bne _080FA030
	strh r2, [r1]
	b _080FA034
	.align 2, 0
_080FA020: .4byte 0x00000DCC
_080FA024: .4byte gJoypad
_080FA028: .4byte 0x00000DEE
_080FA02C: .4byte 0x00000E04
_080FA030:
	movs r0, #0xff
	strh r0, [r1]
_080FA034:
	movs r0, #5
	bl PlaySound
	b _080FA092
_080FA03C:
	movs r4, #0xff
	ldrh r1, [r2, #6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080FA04C
	movs r4, #0
	b _080FA06E
_080FA04C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080FA058
	movs r4, #1
	b _080FA06E
_080FA058:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080FA064
	movs r4, #2
	b _080FA06E
_080FA064:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080FA06E
	movs r4, #3
_080FA06E:
	cmp r4, #0xff
	beq _080FA092
	ldr r0, _080FA0BC @ =0x00000DEE
	adds r2, r6, r0
	ldrb r3, [r2]
	ldr r1, _080FA0C0 @ =0x08386B58
	lsls r0, r3, #2
	adds r0, r4, r0
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r3, r0
	beq _080FA092
	movs r0, #1
	bl PlaySound
_080FA092:
	ldr r1, [sp, #4]
	ldrb r0, [r1]
	ldr r2, [sp, #8]
	ldrb r2, [r2]
	cmp r0, r2
	bne _080FA0A0
	b _080FA1FC
_080FA0A0:
	ldr r3, [sp, #8]
	strb r0, [r3]
	movs r0, #4
	bl PlaySound
	ldr r4, [sp, #4]
	ldrb r0, [r4]
	cmp r0, #2
	beq _080FA108
	cmp r0, #2
	bgt _080FA0C4
	cmp r0, #1
	beq _080FA0CA
	b _080FA1E4
	.align 2, 0
_080FA0BC: .4byte 0x00000DEE
_080FA0C0: .4byte 0x08386B58
_080FA0C4:
	cmp r0, #3
	beq _080FA17C
	b _080FA1E4
_080FA0CA:
	ldr r0, _080FA0F4 @ =0x00001106
	adds r1, r6, r0
	ldr r2, _080FA0F8 @ =0x00003092
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _080FA0FC @ =0x00001108
	adds r1, r6, r3
	ldr r4, _080FA100 @ =0x00003093
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA104 @ =0x00001146
	adds r1, r6, r0
	adds r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r3, #0x40
	adds r1, r6, r3
	adds r4, #6
	adds r0, r4, #0
	strh r0, [r1]
	b _080FA1E4
	.align 2, 0
_080FA0F4: .4byte 0x00001106
_080FA0F8: .4byte 0x00003092
_080FA0FC: .4byte 0x00001108
_080FA100: .4byte 0x00003093
_080FA104: .4byte 0x00001146
_080FA108:
	ldr r0, _080FA150 @ =0x00001106
	adds r1, r6, r0
	ldr r2, _080FA154 @ =0x00003092
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _080FA158 @ =0x00001108
	adds r1, r6, r3
	ldr r4, _080FA15C @ =0x00003093
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA160 @ =0x00001146
	adds r0, r6, r1
	adds r2, #6
	adds r3, r2, #0
	strh r3, [r0]
	ldr r4, _080FA164 @ =0x00001148
	adds r0, r6, r4
	ldr r1, _080FA168 @ =0x00003099
	adds r2, r1, #0
	strh r2, [r0]
	subs r4, #0x3e
	adds r1, r6, r4
	ldr r4, _080FA16C @ =0x00003094
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA170 @ =0x0000110C
	adds r1, r6, r0
	adds r4, #1
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA174 @ =0x0000114A
	adds r0, r6, r1
	strh r3, [r0]
	ldr r3, _080FA178 @ =0x0000114C
	b _080FA1E0
	.align 2, 0
_080FA150: .4byte 0x00001106
_080FA154: .4byte 0x00003092
_080FA158: .4byte 0x00001108
_080FA15C: .4byte 0x00003093
_080FA160: .4byte 0x00001146
_080FA164: .4byte 0x00001148
_080FA168: .4byte 0x00003099
_080FA16C: .4byte 0x00003094
_080FA170: .4byte 0x0000110C
_080FA174: .4byte 0x0000114A
_080FA178: .4byte 0x0000114C
_080FA17C:
	ldr r4, _080FA210 @ =0x00001106
	adds r1, r6, r4
	ldr r2, _080FA214 @ =0x00003092
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _080FA218 @ =0x00001108
	adds r1, r6, r3
	ldr r4, _080FA21C @ =0x00003093
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA220 @ =0x00001146
	adds r0, r6, r1
	adds r2, #6
	adds r3, r2, #0
	strh r3, [r0]
	ldr r4, _080FA224 @ =0x00001148
	adds r0, r6, r4
	ldr r1, _080FA228 @ =0x00003099
	adds r2, r1, #0
	strh r2, [r0]
	subs r4, #0x3e
	adds r1, r6, r4
	ldr r4, _080FA22C @ =0x00003094
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA230 @ =0x0000110C
	adds r1, r6, r0
	adds r4, #1
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA234 @ =0x0000114A
	adds r0, r6, r1
	strh r3, [r0]
	ldr r4, _080FA238 @ =0x0000114C
	adds r0, r6, r4
	strh r2, [r0]
	ldr r0, _080FA23C @ =0x0000110E
	adds r1, r6, r0
	ldr r4, _080FA240 @ =0x00003096
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _080FA244 @ =0x00001110
	adds r1, r6, r0
	adds r4, #1
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, _080FA248 @ =0x0000114E
	adds r0, r6, r1
	strh r3, [r0]
	ldr r3, _080FA24C @ =0x00001150
_080FA1E0:
	adds r0, r6, r3
	strh r2, [r0]
_080FA1E4:
	ldr r4, _080FA250 @ =0x00000ED8
	adds r0, r6, r4
	ldr r1, _080FA254 @ =gVideoRegBuffer+6
	ldrh r2, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	bl RequestBgMapTransfer
_080FA1FC:
	movs r0, #1
_080FA1FE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FA210: .4byte 0x00001106
_080FA214: .4byte 0x00003092
_080FA218: .4byte 0x00001108
_080FA21C: .4byte 0x00003093
_080FA220: .4byte 0x00001146
_080FA224: .4byte 0x00001148
_080FA228: .4byte 0x00003099
_080FA22C: .4byte 0x00003094
_080FA230: .4byte 0x0000110C
_080FA234: .4byte 0x0000114A
_080FA238: .4byte 0x0000114C
_080FA23C: .4byte 0x0000110E
_080FA240: .4byte 0x00003096
_080FA244: .4byte 0x00001110
_080FA248: .4byte 0x0000114E
_080FA24C: .4byte 0x00001150
_080FA250: .4byte 0x00000ED8
_080FA254: .4byte gVideoRegBuffer+6

	thumb_func_start exitCielMinigame
exitCielMinigame: @ 0x080FA258
	push {lr}
	ldr r2, _080FA284 @ =gSystemSavedataManager
	ldr r1, _080FA288 @ =0x00000DCC
	adds r0, r0, r1
	ldr r1, [r2, #0x28]
	ldr r0, [r0, #8]
	cmp r1, r0
	bhs _080FA26E
	str r0, [r2, #0x28]
	bl SaveSystemData
_080FA26E:
	ldr r2, _080FA28C @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080FA290 @ =0x0000DFFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xd6
	bl ClearBlink
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080FA284: .4byte gSystemSavedataManager
_080FA288: .4byte 0x00000DCC
_080FA28C: .4byte gWindowRegBuffer
_080FA290: .4byte 0x0000DFFF

	thumb_func_start initCopyXMinigame
initCopyXMinigame: @ 0x080FA294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	ldr r1, _080FA510 @ =0x00000DCC
	adds r7, r0, r1
	ldr r2, _080FA514 @ =0x00000DC4
	adds r1, r0, r2
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r1, #4]
	movs r0, #4
	bl ResetLandscape
	movs r5, #0x8c
	lsls r5, r5, #1
	ldr r0, _080FA518 @ =gStaticMotionGraphics
	mov r8, r0
	ldr r1, _080FA51C @ =wStaticGraphicTilenums
	mov sb, r1
	ldrh r1, [r1, #0x1c]
	ldr r2, _080FA520 @ =0x085D7A10
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r2, #0
	bl LoadGraphic
	ldr r1, _080FA524 @ =gStaticMotionGraphics+12
	adds r5, r5, r1
	ldr r6, _080FA528 @ =wStaticMotionPalIDs
	ldrh r1, [r6, #0x1c]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	ldr r4, _080FA52C @ =0x0000071C
	mov r1, r8
	adds r0, r4, r1
	mov r1, sb
	adds r1, #0xb6
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xe6
	lsls r4, r4, #3
	mov r1, r8
	adds r0, r4, r1
	mov r1, sb
	adds r1, #0xb8
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080FA530 @ =0x0000076C
	mov r1, r8
	adds r0, r4, r1
	mov r1, sb
	adds r1, #0xbe
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0xbe
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	movs r0, #0
	mov r1, sb
	strh r0, [r1, #0x1c]
	movs r0, #7
	strh r0, [r6, #0x1c]
	ldr r2, _080FA520 @ =0x085D7A10
	ldrh r1, [r2, #6]
	lsrs r1, r1, #6
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	subs r1, r0, r1
	adds r0, r2, #0
	bl LoadGraphic
	ldrh r1, [r6, #0x1c]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	ldr r5, _080FA534 @ =0x00001310
	mov r1, r8
	adds r0, r5, r1
	movs r4, #0xf4
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	adds r4, r6, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	add r0, sp, #4
	movs r1, #0
	bl CreateMinigameIcon_1
	movs r1, #0xb9
	lsls r1, r1, #1
	mov r2, sb
	strh r1, [r2]
	movs r0, #0xe
	strh r0, [r6]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	ldrh r1, [r6]
	ldr r2, _080FA524 @ =gStaticMotionGraphics+12
	ldrb r0, [r2, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r2, #0
	bl LoadPalette
	movs r4, #0x9f
	lsls r0, r4, #1
	add sb, r0
	movs r1, #0xf0
	lsls r1, r1, #1
	mov r2, sb
	strh r1, [r2]
	adds r6, r6, r0
	movs r0, #9
	strh r0, [r6]
	lsls r4, r4, #4
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r4, r4, r0
	add r8, r4
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	ldr r1, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r1
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	movs r0, #0x8c
	lsls r0, r0, #9
	str r0, [sp, #4]
	movs r0, #0xf6
	lsls r0, r0, #8
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	bl CreatePlayerCopyX
	movs r1, #0
	add r6, sp, #4
	movs r5, #0x80
	lsls r5, r5, #5
_080FA4A8:
	adds r4, r1, #1
	movs r0, #0xec
	lsls r0, r0, #9
	subs r0, r0, r5
	str r0, [sp, #4]
	movs r0, #0x94
	lsls r0, r0, #9
	str r0, [r6, #4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #2
	adds r3, r7, #0
	adds r3, #0xc
	bl FUN_080c82b8
	movs r2, #0x80
	lsls r2, r2, #5
	adds r5, r5, r2
	adds r1, r4, #0
	cmp r1, #2
	ble _080FA4A8
	movs r4, #0
	movs r0, #3
	strb r0, [r7, #0xc]
	strh r4, [r7]
	movs r0, #0x78
	strh r0, [r7, #2]
	str r4, [r7, #0x20]
	strh r4, [r7, #4]
	strh r4, [r7, #6]
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	ldr r0, _080FA538 @ =gSystemSavedataManager
	ldr r0, [r0, #0x2c]
	str r0, [r7, #0x24]
	strh r4, [r7, #0xe]
	movs r0, #0xb3
	bl playBGM
	ldr r0, [sp, #0xc]
	strh r4, [r0, #4]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FA510: .4byte 0x00000DCC
_080FA514: .4byte 0x00000DC4
_080FA518: .4byte gStaticMotionGraphics
_080FA51C: .4byte wStaticGraphicTilenums
_080FA520: .4byte 0x085D7A10
_080FA524: .4byte gStaticMotionGraphics+12
_080FA528: .4byte wStaticMotionPalIDs
_080FA52C: .4byte 0x0000071C
_080FA530: .4byte 0x0000076C
_080FA534: .4byte 0x00001310
_080FA538: .4byte gSystemSavedataManager

	thumb_func_start copyXMinigame
copyXMinigame: @ 0x080FA53C
	push {lr}
	ldr r2, _080FA558 @ =0x00000DCC
	adds r1, r0, r2
	ldr r2, _080FA55C @ =0x08386B80
	movs r3, #4
	ldrsh r1, [r1, r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_080FA558: .4byte 0x00000DCC
_080FA55C: .4byte 0x08386B80

	thumb_func_start copyx_minigame_080fa560
copyx_minigame_080fa560: @ 0x080FA560
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FA57C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080FA594
	cmp r0, #1
	bgt _080FA580
	cmp r0, #0
	beq _080FA58A
	b _080FA5CE
	.align 2, 0
_080FA57C: .4byte 0x00000DCC
_080FA580:
	cmp r0, #2
	beq _080FA5A8
	cmp r0, #3
	beq _080FA5BC
	b _080FA5CE
_080FA58A:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA594:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FA5CE
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FA5CE
_080FA5A8:
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0x1d
	bl PlaySound
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA5BC:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FA5CE
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FA5CE:
	ldr r1, _080FA624 @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA5F6
	str r4, [r5, #0x24]
_080FA5F6:
	add r4, sp, #8
	ldr r1, _080FA628 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl minigame_str_080e9d04
	movs r0, #1
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA624: .4byte 0x0810E25C
_080FA628: .4byte 0x0810E264

	thumb_func_start copyx_minigame_080fa62c
copyx_minigame_080fa62c: @ 0x080FA62C
	push {r4, r5, lr}
	sub sp, #0x1c
	ldr r1, _080FA6AC @ =0x00000DCC
	adds r5, r0, r1
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #2
	ldrsh r1, [r5, r3]
	bl __modsi3
	adds r4, r0, #0
	cmp r4, #0
	bne _080FA6E8
	ldr r1, _080FA6B0 @ =gGameState
	ldr r0, _080FA6B4 @ =0x0000626C
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r3, _080FA6B8 @ =0x41C64E6D
	muls r0, r3, r0
	ldr r2, _080FA6BC @ =0x00003039
	adds r0, r0, r2
	muls r0, r3, r0
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [sp, #0x14]
	movs r0, #0xf0
	lsls r0, r0, #8
	add r1, sp, #0x14
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r0, r0, r3
	str r0, [sp, #0x14]
	ldr r0, [r1, #4]
	ldr r3, _080FA6C0 @ =0xFFFFD000
	adds r0, r0, r3
	str r0, [r1, #4]
	adds r0, r5, #0
	bl FUN_080b1934
	ldr r0, [r5, #0x20]
	adds r0, #1
	str r0, [r5, #0x20]
	strh r4, [r5]
	cmp r0, #3
	bhi _080FA6C4
	movs r0, #0x78
	b _080FA6E6
	.align 2, 0
_080FA6AC: .4byte 0x00000DCC
_080FA6B0: .4byte gGameState
_080FA6B4: .4byte 0x0000626C
_080FA6B8: .4byte 0x41C64E6D
_080FA6BC: .4byte 0x00003039
_080FA6C0: .4byte 0xFFFFD000
_080FA6C4:
	cmp r0, #0xb
	bhi _080FA6CC
	movs r0, #0x70
	b _080FA6E6
_080FA6CC:
	cmp r0, #0x17
	bhi _080FA6D4
	movs r0, #0x68
	b _080FA6E6
_080FA6D4:
	cmp r0, #0x1f
	bhi _080FA6DC
	movs r0, #0x60
	b _080FA6E6
_080FA6DC:
	cmp r0, #0x2f
	bhi _080FA6E4
	movs r0, #0x58
	b _080FA6E6
_080FA6E4:
	movs r0, #0x46
_080FA6E6:
	strh r0, [r5, #2]
_080FA6E8:
	ldr r1, _080FA75C @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA722
	str r4, [r5, #0x24]
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne _080FA722
	movs r0, #1
	strh r0, [r5, #0xe]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
_080FA722:
	add r4, sp, #8
	ldr r1, _080FA760 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl minigame_str_080e9d04
	ldrb r1, [r5, #0xc]
	cmp r1, #0
	bne _080FA752
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FA752:
	movs r0, #1
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA75C: .4byte 0x0810E25C
_080FA760: .4byte 0x0810E264

	thumb_func_start copyx_minigame_080fa764
copyx_minigame_080fa764: @ 0x080FA764
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FA780 @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080FA800
	lsls r0, r0, #2
	ldr r1, _080FA784 @ =_080FA788
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FA780: .4byte 0x00000DCC
_080FA784: .4byte _080FA788
_080FA788: @ jump table
	.4byte _080FA7A0 @ case 0
	.4byte _080FA7AA @ case 1
	.4byte _080FA7B8 @ case 2
	.4byte _080FA7CC @ case 3
	.4byte _080FA7DC @ case 4
	.4byte _080FA7E8 @ case 5
_080FA7A0:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7AA:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FA800
	b _080FA7D4
_080FA7B8:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xb3
	bl fadeoutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7CC:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FA800
_080FA7D4:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FA800
_080FA7DC:
	ldr r1, _080FA7FC @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7E8:
	ldr r0, _080FA7FC @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FA800
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080FA84C
	.align 2, 0
_080FA7FC: .4byte gGameState
_080FA800:
	ldr r1, _080FA854 @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA828
	str r4, [r5, #0x24]
_080FA828:
	add r4, sp, #8
	ldr r1, _080FA858 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl minigame_str_080e9d04
	movs r0, #1
_080FA84C:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA854: .4byte 0x0810E25C
_080FA858: .4byte 0x0810E264

	thumb_func_start exitCopyXMinigame
exitCopyXMinigame: @ 0x080FA85C
	push {lr}
	ldr r2, _080FA878 @ =0x00000DCC
	adds r1, r0, r2
	ldrh r2, [r1, #6]
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _080FA87C
	movs r0, #2
	strh r0, [r1]
	adds r0, r2, #1
	strh r0, [r1, #6]
	b _080FA8AC
	.align 2, 0
_080FA878: .4byte 0x00000DCC
_080FA87C:
	cmp r0, #1
	bne _080FA8AC
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080FA894
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080FA8AC
_080FA894:
	ldr r2, _080FA8A8 @ =gSystemSavedataManager
	ldr r1, [r1, #0x24]
	ldr r0, [r2, #0x2c]
	cmp r1, r0
	bls _080FA8A4
	str r1, [r2, #0x2c]
	bl SaveSystemData
_080FA8A4:
	movs r0, #0
	b _080FA8AE
	.align 2, 0
_080FA8A8: .4byte gSystemSavedataManager
_080FA8AC:
	movs r0, #1
_080FA8AE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start initHarpuiaMinigame
initHarpuiaMinigame: @ 0x080FA8B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r7, _080FAAC4 @ =0x00000DCC
	add r7, sl
	ldr r1, _080FAAC8 @ =0x00000DC4
	add r1, sl
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r1, #4]
	movs r0, #0xa
	bl ResetLandscape
	ldr r1, _080FAACC @ =wStaticGraphicTilenums
	adds r1, #0x8e
	movs r0, #0
	strh r0, [r1]
	ldr r5, _080FAAD0 @ =wStaticMotionPalIDs
	adds r5, #0x8e
	movs r0, #7
	strh r0, [r5]
	ldr r4, _080FAAD4 @ =0x0000058C
	ldr r1, _080FAAD8 @ =gStaticMotionGraphics
	mov r8, r1
	adds r0, r4, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	rsbs r1, r1, #0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r6, _080FAADC @ =gStaticMotionGraphics+12
	adds r4, r4, r6
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	mov sb, r0
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xf3
	lsls r5, r4, #1
	ldr r1, _080FAACC @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xc8
	strh r1, [r0]
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	adds r5, r2, r5
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, r8
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	adds r4, r4, r6
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xa1
	lsls r5, r4, #1
	ldr r1, _080FAACC @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xf0
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	adds r5, r2, r5
	movs r0, #9
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, r8
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	adds r4, r4, r6
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	ldr r5, _080FAAE0 @ =0x00000D48
	mov r1, r8
	adds r0, r5, r1
	movs r4, #0xaa
	lsls r4, r4, #1
	ldr r2, _080FAACC @ =wStaticGraphicTilenums
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	adds r5, r5, r6
	ldr r0, _080FAAD0 @ =wStaticMotionPalIDs
	adds r4, r0, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r5, #0
	bl LoadPalette
	movs r1, #0xf0
	ldr r2, _080FAACC @ =wStaticGraphicTilenums
	strh r1, [r2]
	movs r0, #0xe
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	strh r0, [r2]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	ldrh r1, [r2]
	ldrb r0, [r6, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r6, #0
	bl LoadPalette
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [sp, #4]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	bl CreatePlayerHarpuia
	str r0, [r7, #0x14]
	ldr r1, _080FAAE4 @ =pZero2
	str r0, [r1]
	movs r1, #0
	add r6, sp, #4
	movs r5, #0x80
	lsls r5, r5, #5
_080FAA3A:
	adds r4, r1, #1
	movs r0, #0xec
	lsls r0, r0, #9
	subs r0, r0, r5
	str r0, [sp, #4]
	movs r0, #0x94
	lsls r0, r0, #9
	str r0, [r6, #4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #3
	adds r3, r7, #0
	adds r3, #0xc
	bl FUN_080c82b8
	mov r1, sl
	str r1, [r0, #0x2c]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r5, r5, r2
	adds r1, r4, #0
	cmp r1, #2
	ble _080FAA3A
	movs r4, #0
	movs r0, #3
	strb r0, [r7, #0xc]
	movs r1, #0
	strh r4, [r7]
	movs r0, #0x78
	mov r2, sl
	strh r0, [r2, #6]
	strh r4, [r2, #8]
	strh r4, [r2, #0xa]
	strh r4, [r7, #4]
	strh r4, [r7, #6]
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	str r4, [r7, #0x30]
	str r4, [r7, #0x2c]
	strh r4, [r7, #0xe]
	strh r4, [r7, #0x38]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r7, #0x34]
	strb r1, [r7, #0xd]
	str r4, [r7, #0x20]
	str r4, [r7, #0x24]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	ldr r0, _080FAAE8 @ =gSystemSavedataManager
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x3c]
	strh r4, [r7, #0x3a]
	movs r0, #0xb7
	bl playBGM
	mov r0, sl
	strh r4, [r0, #4]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FAAC4: .4byte 0x00000DCC
_080FAAC8: .4byte 0x00000DC4
_080FAACC: .4byte wStaticGraphicTilenums
_080FAAD0: .4byte wStaticMotionPalIDs
_080FAAD4: .4byte 0x0000058C
_080FAAD8: .4byte gStaticMotionGraphics
_080FAADC: .4byte gStaticMotionGraphics+12
_080FAAE0: .4byte 0x00000D48
_080FAAE4: .4byte pZero2
_080FAAE8: .4byte gSystemSavedataManager

	thumb_func_start harpuiaMinigame
harpuiaMinigame: @ 0x080FAAEC
	push {lr}
	ldr r2, _080FAB08 @ =0x00000DCC
	adds r1, r0, r2
	ldr r2, _080FAB0C @ =0x08386B8C
	movs r3, #4
	ldrsh r1, [r1, r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_080FAB08: .4byte 0x00000DCC
_080FAB0C: .4byte 0x08386B8C

	thumb_func_start harpuia_minigame_080fab10
harpuia_minigame_080fab10: @ 0x080FAB10
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FAB2C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080FAB44
	cmp r0, #1
	bgt _080FAB30
	cmp r0, #0
	beq _080FAB3A
	b _080FAB7E
	.align 2, 0
_080FAB2C: .4byte 0x00000DCC
_080FAB30:
	cmp r0, #2
	beq _080FAB58
	cmp r0, #3
	beq _080FAB6C
	b _080FAB7E
_080FAB3A:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAB44:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAB7E
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FAB7E
_080FAB58:
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0x1d
	bl PlaySound
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAB6C:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FAB7E
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FAB7E:
	ldr r1, _080FABE0 @ =0x0810E270
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r0, [r5, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrh r2, [r5, #0x38]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080FABB2
	str r4, [r5, #0x3c]
_080FABB2:
	add r4, sp, #8
	ldr r1, _080FABE4 @ =0x0810E278
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	movs r0, #1
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FABE0: .4byte 0x0810E270
_080FABE4: .4byte 0x0810E278

	thumb_func_start harpuia_minigame_080fabe8
harpuia_minigame_080fabe8: @ 0x080FABE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sb, r0
	ldr r7, _080FAC34 @ =0x00000DCC
	add r7, sb
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	ldr r2, _080FAC38 @ =0x00000DC4
	add r2, sb
	ldr r0, [r2]
	ldr r1, [r7, #0x34]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r7, #0x30]
	ldr r1, [r7, #0x34]
	adds r0, r0, r1
	str r0, [r7, #0x30]
	ldr r1, _080FAC3C @ =0x0003BFFF
	cmp r0, r1
	ble _080FAC44
	ldr r0, [r2]
	ldr r1, _080FAC40 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r7, #0x30]
	adds r0, r0, r1
	str r0, [r7, #0x30]
	ldr r2, [r7, #0x14]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r2, #0x54]
	movs r0, #1
	b _080FAC46
	.align 2, 0
_080FAC34: .4byte 0x00000DCC
_080FAC38: .4byte 0x00000DC4
_080FAC3C: .4byte 0x0003BFFF
_080FAC40: .4byte 0xFFFC4000
_080FAC44:
	movs r0, #0
_080FAC46:
	strb r0, [r7, #0xd]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	ldr r0, [r7, #0x14]
	ldrb r0, [r0, #0xc]
	adds r1, r7, #0
	adds r1, #0x20
	str r1, [sp, #0x2c]
	add r2, sp, #8
	mov sl, r2
	cmp r0, #1
	bhi _080FAD1C
	movs r3, #0
	ldrsh r0, [r7, r3]
	mov r2, sb
	movs r3, #6
	ldrsh r1, [r2, r3]
	bl __modsi3
	cmp r0, #0
	bne _080FAD1C
	ldr r1, [r7, #0x30]
	ldr r0, _080FACFC @ =0x000365FF
	cmp r1, r0
	bgt _080FAD1C
	ldr r5, _080FAD00 @ =gGameState
	ldr r0, _080FAD04 @ =0x0000626C
	adds r5, r5, r0
	ldr r0, [r5]
	ldr r1, _080FAD08 @ =0x41C64E6D
	mov r8, r1
	mov r4, r8
	muls r4, r0, r4
	ldr r6, _080FAD0C @ =0x00003039
	adds r4, r4, r6
	str r4, [r5]
	lsrs r0, r4, #0x10
	movs r1, #0x28
	bl __umodsi3
	adds r0, #0x64
	mov r2, sb
	strh r0, [r2, #6]
	ldr r0, _080FAD10 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r3, #0xfa
	lsls r3, r3, #8
	adds r0, r0, r3
	str r0, [sp, #0x14]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r6
	str r0, [r5]
	lsrs r0, r0, #0x10
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r0, r0, #8
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r0, r1
	add r1, sp, #0x14
	str r0, [r1, #4]
	movs r5, #0
	ldr r4, [sp, #0x2c]
_080FACCC:
	ldr r0, [r4]
	cmp r0, #0
	bne _080FAD14
	adds r0, r7, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0809b064
	adds r1, r0, #0
	cmp r1, #0
	beq _080FAD1C
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #0x17
	strb r0, [r2]
	str r1, [r4]
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x28
	adds r0, r0, r1
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0]
	b _080FAD1C
	.align 2, 0
_080FACFC: .4byte 0x000365FF
_080FAD00: .4byte gGameState
_080FAD04: .4byte 0x0000626C
_080FAD08: .4byte 0x41C64E6D
_080FAD0C: .4byte 0x00003039
_080FAD10: .4byte pZero2
_080FAD14:
	adds r4, #4
	adds r5, #1
	cmp r5, #1
	ble _080FACCC
_080FAD1C:
	ldr r6, [sp, #0x2c]
	movs r5, #0
	adds r3, r6, #0
	adds r4, r7, #0
	adds r4, #0x28
	ldr r2, _080FAD3C @ =gEnemyFnTable
	mov r8, r2
_080FAD2A:
	ldr r0, [r3]
	cmp r0, #0
	beq _080FAD84
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FAD40
	str r5, [r3]
	strh r5, [r4]
	b _080FAD84
	.align 2, 0
_080FAD3C: .4byte gEnemyFnTable
_080FAD40:
	ldrh r0, [r4]
	cmp r0, #0
	beq _080FAD50
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAD84
_080FAD50:
	ldr r2, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	add r1, r8
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_080FAD84:
	adds r3, #4
	adds r4, #2
	adds r0, r6, #4
	cmp r3, r0
	ble _080FAD2A
	ldr r0, [r7, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080FAE18
	movs r3, #0
	ldrsh r0, [r7, r3]
	movs r1, #0xdc
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FADC4
	ldr r0, _080FAEA0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0x8c
	lsls r1, r1, #9
	adds r0, r0, r1
	str r0, [sp, #0x1c]
	movs r0, #0xf0
	lsls r0, r0, #8
	add r1, sp, #0x1c
	str r0, [r1, #4]
	adds r0, r7, #0
	movs r2, #0
	bl FUN_080b1990
_080FADC4:
	ldr r0, [r7, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080FAE18
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAE18
	ldr r0, _080FAEA0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r3, #0x8c
	lsls r3, r3, #9
	adds r0, r0, r3
	str r0, [sp, #0x24]
	ldr r1, _080FAEA4 @ =gGameState
	ldr r0, _080FAEA8 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080FAEAC @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080FAEB0 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r0, r0, #8
	movs r3, #0xd0
	lsls r3, r3, #8
	adds r0, r0, r3
	add r1, sp, #0x24
	str r0, [r1, #4]
	adds r0, r7, #0
	movs r2, #0
	bl FUN_080b19ec
_080FAE18:
	ldr r1, _080FAEB4 @ =0x0810E270
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r0, [r7, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrh r2, [r7, #0x38]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r7, #0x3c]
	cmp r4, r0
	bls _080FAE5E
	str r4, [r7, #0x3c]
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne _080FAE5E
	movs r0, #1
	strh r0, [r7, #0x3a]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
_080FAE5E:
	ldr r1, _080FAEB8 @ =0x0810E278
	mov r0, sl
	movs r2, #9
	bl memcpy
	mov r0, sl
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r7, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldrb r1, [r7, #0xc]
	cmp r1, #0
	bne _080FAE8C
	ldrh r0, [r7, #4]
	adds r0, #1
	strh r0, [r7, #4]
	strh r1, [r7, #6]
_080FAE8C:
	movs r0, #1
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FAEA0: .4byte pZero2
_080FAEA4: .4byte gGameState
_080FAEA8: .4byte 0x0000626C
_080FAEAC: .4byte 0x41C64E6D
_080FAEB0: .4byte 0x00003039
_080FAEB4: .4byte 0x0810E270
_080FAEB8: .4byte 0x0810E278

	thumb_func_start harpuia_minigame_080faebc
harpuia_minigame_080faebc: @ 0x080FAEBC
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FAED8 @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080FAF58
	lsls r0, r0, #2
	ldr r1, _080FAEDC @ =_080FAEE0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FAED8: .4byte 0x00000DCC
_080FAEDC: .4byte _080FAEE0
_080FAEE0: @ jump table
	.4byte _080FAEF8 @ case 0
	.4byte _080FAF02 @ case 1
	.4byte _080FAF10 @ case 2
	.4byte _080FAF24 @ case 3
	.4byte _080FAF34 @ case 4
	.4byte _080FAF40 @ case 5
_080FAEF8:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAF02:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAF58
	b _080FAF2C
_080FAF10:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xb7
	bl fadeoutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAF24:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FAF58
_080FAF2C:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FAF58
_080FAF34:
	ldr r1, _080FAF54 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAF40:
	ldr r0, _080FAF54 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FAF58
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080FAFB0
	.align 2, 0
_080FAF54: .4byte gGameState
_080FAF58:
	ldr r1, _080FAFB8 @ =0x0810E270
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r0, [r5, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrh r2, [r5, #0x38]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080FAF8C
	str r4, [r5, #0x3c]
_080FAF8C:
	add r4, sp, #8
	ldr r1, _080FAFBC @ =0x0810E278
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	movs r0, #1
_080FAFB0:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FAFB8: .4byte 0x0810E270
_080FAFBC: .4byte 0x0810E278

	thumb_func_start exitHarpuiaMinigame
exitHarpuiaMinigame: @ 0x080FAFC0
	push {lr}
	ldr r2, _080FAFDC @ =0x00000DCC
	adds r1, r0, r2
	ldrh r2, [r1, #6]
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _080FAFE0
	movs r0, #2
	strh r0, [r1]
	adds r0, r2, #1
	strh r0, [r1, #6]
	b _080FB010
	.align 2, 0
_080FAFDC: .4byte 0x00000DCC
_080FAFE0:
	cmp r0, #1
	bne _080FB010
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080FAFF8
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080FB010
_080FAFF8:
	ldr r2, _080FB00C @ =gSystemSavedataManager
	ldr r1, [r1, #0x3c]
	ldr r0, [r2, #0x30]
	cmp r1, r0
	bls _080FB008
	str r1, [r2, #0x30]
	bl SaveSystemData
_080FB008:
	movs r0, #0
	b _080FB012
	.align 2, 0
_080FB00C: .4byte gSystemSavedataManager
_080FB010:
	movs r0, #1
_080FB012:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start fefnir_080fb018
fefnir_080fb018: @ 0x080FB018
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080FB050 @ =0x00000DCC
	adds r4, r4, r0
	ldr r0, _080FB054 @ =0x0810E284
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x20]
	movs r1, #0xc
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, _080FB058 @ =0x0810E28C
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x28]
	movs r1, #0x1c
	movs r2, #0
	bl minigame_str_080e9d04
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FB050: .4byte 0x00000DCC
_080FB054: .4byte 0x0810E284
_080FB058: .4byte 0x0810E28C

	thumb_func_start initFefnirMinigame
initFefnirMinigame: @ 0x080FB05C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r5, _080FB204 @ =0x00000DCC
	add r5, sb
	ldr r1, _080FB208 @ =0x00000DC4
	add r1, sb
	ldr r0, _080FB20C @ =0x0026E800
	str r0, [r1]
	movs r2, #0x88
	lsls r2, r2, #0xa
	str r2, [r1, #4]
	movs r0, #7
	bl ResetLandscape
	ldr r6, _080FB210 @ =gStaticMotionGraphics
	ldr r0, _080FB214 @ =wStaticGraphicTilenums
	mov sl, r0
	ldrh r1, [r0]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	adds r0, r6, #0
	bl LoadGraphic
	ldr r0, _080FB218 @ =gStaticMotionGraphics+12
	mov r8, r0
	ldr r7, _080FB21C @ =wStaticMotionPalIDs
	ldrh r1, [r7]
	ldrb r0, [r0, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	mov r0, r8
	bl LoadPalette
	movs r4, #0xa5
	lsls r4, r4, #2
	adds r0, r4, r6
	mov r1, sl
	adds r1, #0x42
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
	adds r0, r7, #0
	adds r0, #0x42
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xaa
	lsls r4, r4, #2
	adds r0, r4, r6
	mov r1, sl
	adds r1, #0x44
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
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r6, r4, r6
	mov r0, sl
	adds r0, #0x46
	ldrh r1, [r0]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	adds r0, r6, #0
	bl LoadGraphic
	add r4, r8
	adds r0, r7, #0
	adds r0, #0x46
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r5, #0
	ldr r1, _080FB20C @ =0x0026E800
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl CreatePlayerFefnir
	ldr r1, _080FB220 @ =0x00269700
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #4]
	ldr r1, _080FB224 @ =0x0026CD00
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #8]
	ldr r1, _080FB228 @ =0x00270300
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #0xc]
	ldr r1, _080FB22C @ =0x00273900
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #0x10]
	ldr r2, _080FB230 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080FB234 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080FB238 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x30
	ldr r1, _080FB23C @ =0x00000DF9
	add r1, sb
	strb r0, [r1]
	ldr r0, _080FB240 @ =0x00000DFA
	add r0, sb
	movs r2, #0
	strb r2, [r0]
	strb r2, [r5]
	strb r2, [r5, #1]
	strb r2, [r5, #2]
	strb r2, [r5, #3]
	movs r0, #0
	str r0, [r5, #0x20]
	str r0, [r5, #0x24]
	ldr r0, _080FB244 @ =gSystemSavedataManager
	ldr r0, [r0, #0x34]
	str r0, [r5, #0x28]
	ldr r0, _080FB248 @ =0x00000DF8
	add r0, sb
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080FB24C @ =0x00000DFB
	add sb, r2
	mov r0, sb
	strb r1, [r0]
	movs r0, #0xbd
	bl playBGM
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FB204: .4byte 0x00000DCC
_080FB208: .4byte 0x00000DC4
_080FB20C: .4byte 0x0026E800
_080FB210: .4byte gStaticMotionGraphics
_080FB214: .4byte wStaticGraphicTilenums
_080FB218: .4byte gStaticMotionGraphics+12
_080FB21C: .4byte wStaticMotionPalIDs
_080FB220: .4byte 0x00269700
_080FB224: .4byte 0x0026CD00
_080FB228: .4byte 0x00270300
_080FB22C: .4byte 0x00273900
_080FB230: .4byte RNG_0202f388
_080FB234: .4byte 0x000343FD
_080FB238: .4byte 0x00269EC3
_080FB23C: .4byte 0x00000DF9
_080FB240: .4byte 0x00000DFA
_080FB244: .4byte gSystemSavedataManager
_080FB248: .4byte 0x00000DF8
_080FB24C: .4byte 0x00000DFB

	thumb_func_start fefnirMinigame
fefnirMinigame: @ 0x080FB250
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080FB294 @ =0x00000DCC
	adds r4, r5, r0
	ldr r1, _080FB298 @ =0x08386B98
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r0, [r4, #0x20]
	ldr r1, _080FB29C @ =0x0001869F
	cmp r0, r1
	ble _080FB274
	str r1, [r4, #0x20]
_080FB274:
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble _080FB2B4
	ldr r0, _080FB2A0 @ =0x00000DF8
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080FB2A4
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
	b _080FB2AA
	.align 2, 0
_080FB294: .4byte 0x00000DCC
_080FB298: .4byte 0x08386B98
_080FB29C: .4byte 0x0001869F
_080FB2A0: .4byte 0x00000DF8
_080FB2A4:
	ldr r0, _080FB2B0 @ =0x00000137
	bl PlaySound
_080FB2AA:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x28]
	b _080FB2C0
	.align 2, 0
_080FB2B0: .4byte 0x00000137
_080FB2B4:
	ldr r0, [r4, #0x24]
	cmp r0, r1
	beq _080FB2C0
	ldr r0, _080FB2D4 @ =0x00000137
	bl PlaySound
_080FB2C0:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl fefnir_080fb018
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080FB2D4: .4byte 0x00000137

	thumb_func_start fefnir_minigame_080fb2d8
fefnir_minigame_080fb2d8: @ 0x080FB2D8
	push {r4, lr}
	ldr r1, _080FB2F0 @ =0x00000DCC
	adds r4, r0, r1
	ldrb r0, [r4, #1]
	cmp r0, #1
	beq _080FB308
	cmp r0, #1
	bgt _080FB2F4
	cmp r0, #0
	beq _080FB2FE
	b _080FB344
	.align 2, 0
_080FB2F0: .4byte 0x00000DCC
_080FB2F4:
	cmp r0, #2
	beq _080FB31A
	cmp r0, #3
	beq _080FB32E
	b _080FB344
_080FB2FE:
	movs r0, #0x3c
	str r0, [r4, #0x1c]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB308:
	ldr r0, [r4, #0x1c]
	subs r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #0
	bne _080FB344
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FB344
_080FB31A:
	movs r0, #0x1d
	bl PlaySound
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r4, #0x14]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB32E:
	ldr r0, [r4, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FB344
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strb r1, [r4, #3]
_080FB344:
	movs r0, #0
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start fefnir_minigame_080fb354
fefnir_minigame_080fb354: @ 0x080FB354
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r1, _080FB448 @ =0x00000DCC
	adds r6, r0, r1
	ldr r2, _080FB44C @ =gJoypad
	ldrh r1, [r2]
	strh r1, [r6, #0x18]
	ldrh r1, [r2, #4]
	strh r1, [r6, #0x1a]
	movs r7, #0
	movs r2, #0xdd
	lsls r2, r2, #4
	adds r2, r2, r0
	mov sb, r2
	movs r3, #0
	movs r2, #0xdd
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r2, #3
_080FB380:
	ldr r0, [r1]
	cmp r0, #0
	beq _080FB390
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FB390
	str r3, [r1]
	movs r7, #1
_080FB390:
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080FB380
	cmp r7, #0
	beq _080FB3B2
	adds r2, r6, #0
	adds r2, #0x2f
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	strb r1, [r6, #1]
	strb r1, [r6, #2]
	strb r1, [r6, #3]
_080FB3B2:
	adds r0, r6, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _080FB472
	ldr r0, _080FB450 @ =RNG_0202f388
	mov ip, r0
	ldr r0, [r0]
	ldr r3, _080FB454 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r3, r1
	ldr r2, _080FB458 @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r4, r1, #1
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	adds r5, r6, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	lsrs r0, r0, #3
	subs r0, #0x30
	subs r1, r1, r0
	mov r0, r8
	strb r1, [r0]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, ip
	str r1, [r2]
	lsrs r2, r0, #0x11
	movs r0, #3
	ands r2, r0
	adds r7, r2, #0
	adds r0, r2, #4
	cmp r2, r0
	bge _080FB468
	mov r4, ip
_080FB406:
	adds r0, r2, #0
	cmp r2, #0
	bge _080FB40E
	adds r0, r2, #3
_080FB40E:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r2, r0
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	cmp r3, #0
	beq _080FB460
	ldr r1, [r4]
	ldr r0, _080FB454 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080FB458 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	ldr r2, _080FB45C @ =0x0026E800
	movs r3, #0xe0
	lsls r3, r3, #9
	bl FUN_08071470
	b _080FB468
	.align 2, 0
_080FB448: .4byte 0x00000DCC
_080FB44C: .4byte gJoypad
_080FB450: .4byte RNG_0202f388
_080FB454: .4byte 0x000343FD
_080FB458: .4byte 0x00269EC3
_080FB45C: .4byte 0x0026E800
_080FB460:
	adds r2, #1
	adds r0, r7, #4
	cmp r2, r0
	blt _080FB406
_080FB468:
	ldrb r0, [r5]
	cmp r0, #0xfe
	bhi _080FB472
	adds r0, #1
	strb r0, [r5]
_080FB472:
	mov r2, r8
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	movs r0, #1
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start fefnir_minigame_080fb48c
fefnir_minigame_080fb48c: @ 0x080FB48C
	push {r4, lr}
	ldr r1, _080FB4A8 @ =0x00000DCC
	adds r4, r0, r1
	movs r0, #0
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _080FB528
	lsls r0, r0, #2
	ldr r1, _080FB4AC @ =_080FB4B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FB4A8: .4byte 0x00000DCC
_080FB4AC: .4byte _080FB4B0
_080FB4B0: @ jump table
	.4byte _080FB4C8 @ case 0
	.4byte _080FB4D8 @ case 1
	.4byte _080FB4E4 @ case 2
	.4byte _080FB4F2 @ case 3
	.4byte _080FB502 @ case 4
	.4byte _080FB50E @ case 5
_080FB4C8:
	movs r0, #0xbd
	bl fadeoutBGM
	movs r0, #0x3c
	str r0, [r4, #0x1c]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB4D8:
	ldr r0, [r4, #0x1c]
	subs r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #0
	bne _080FB528
	b _080FB4FA
_080FB4E4:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r4, #0x14]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB4F2:
	ldr r0, [r4, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FB528
_080FB4FA:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FB528
_080FB502:
	ldr r1, _080FB524 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB50E:
	ldr r0, [r4, #0x1c]
	subs r0, #1
	str r0, [r4, #0x1c]
	ldr r0, _080FB524 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FB528
	movs r0, #0
	b _080FB52A
	.align 2, 0
_080FB524: .4byte gGameState
_080FB528:
	movs r0, #1
_080FB52A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start exitFefnirMinigame
exitFefnirMinigame: @ 0x080FB530
	push {lr}
	ldr r1, _080FB548 @ =0x00000DCC
	adds r0, r0, r1
	ldr r1, _080FB54C @ =gSystemSavedataManager
	ldr r0, [r0, #0x28]
	str r0, [r1, #0x34]
	bl SaveSystemData
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080FB548: .4byte 0x00000DCC
_080FB54C: .4byte gSystemSavedataManager

	thumb_func_start leviathan_minigame_080fb550
leviathan_minigame_080fb550: @ 0x080FB550
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080FB588 @ =0x00000DCC
	adds r4, r4, r0
	ldr r0, _080FB58C @ =0x0810E298
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x24]
	movs r1, #0xc
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, _080FB590 @ =0x0810E2A0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x2c]
	movs r1, #0x1c
	movs r2, #0
	bl minigame_str_080e9d04
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FB588: .4byte 0x00000DCC
_080FB58C: .4byte 0x0810E298
_080FB590: .4byte 0x0810E2A0

	thumb_func_start leviathan_minigame_080fb594
leviathan_minigame_080fb594: @ 0x080FB594
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080FB5D4 @ =0x00000DCC
	adds r4, r4, r0
	ldr r0, _080FB5D8 @ =0x0810E2AC
	movs r1, #0xa
	movs r2, #0x13
	bl PrintUnicodeString
	ldr r0, [r4, #0x20]
	movs r1, #0x3c
	bl __divsi3
	movs r1, #0x3c
	bl __modsi3
	movs r1, #0x12
	movs r2, #0x13
	bl minigame_str_080e9d04
	ldr r0, [r4, #0x20]
	movs r1, #0xe1
	lsls r1, r1, #4
	bl __divsi3
	movs r1, #0xf
	movs r2, #0x13
	bl minigame_str_080e9d04
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FB5D4: .4byte 0x00000DCC
_080FB5D8: .4byte 0x0810E2AC

	thumb_func_start leviathan_minigame_080fb5dc
leviathan_minigame_080fb5dc: @ 0x080FB5DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080FB658 @ =0x00000DCC
	adds r7, r0, r1
	ldrh r0, [r7, #0x16]
	subs r0, #1
	strh r0, [r7, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FB64E
	ldrh r0, [r7, #0x14]
	strh r0, [r7, #0x16]
	ldr r4, _080FB65C @ =RNG_0202f388
	mov r8, r4
	ldr r0, [r4]
	ldr r5, _080FB660 @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _080FB664 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r6, r0, #1
	mov r1, r8
	str r6, [r1]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r1, r0, #0
	movs r0, #0xfc
	lsls r0, r0, #0xa
	adds r1, r1, r0
	adds r2, r6, #0
	muls r2, r5, r2
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r3, r2, #1
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	ldr r6, _080FB668 @ =0x08386BB0
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r3, r0, #1
	mov r4, r8
	str r3, [r4]
	lsrs r0, r0, #0x11
	movs r3, #0xf
	ands r0, r3
	adds r0, r0, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	bl FUN_08099fb8
_080FB64E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FB658: .4byte 0x00000DCC
_080FB65C: .4byte RNG_0202f388
_080FB660: .4byte 0x000343FD
_080FB664: .4byte 0x00269EC3
_080FB668: .4byte 0x08386BB0

	thumb_func_start leviathan_minigame_080fb66c
leviathan_minigame_080fb66c: @ 0x080FB66C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	ldr r0, _080FB6DC @ =0x00000DCC
	adds r7, r1, r0
	ldrh r0, [r7, #0x16]
	subs r0, #1
	strh r0, [r7, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FB74A
	ldrh r0, [r7, #0x14]
	strh r0, [r7, #0x16]
	ldr r4, _080FB6E0 @ =0x00000DFE
	adds r1, r1, r4
	ldrb r0, [r1]
	cmp r0, #8
	bls _080FB6F4
	movs r0, #0
	strb r0, [r1]
	ldr r4, _080FB6E4 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080FB6E8 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080FB6EC @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #6
	bl __umodsi3
	adds r1, r0, #0
	ldr r0, _080FB6F0 @ =0x00042400
	adds r1, r1, r0
	mov r2, r8
	muls r2, r5, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r4]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08099fb8
	b _080FB74A
	.align 2, 0
_080FB6DC: .4byte 0x00000DCC
_080FB6E0: .4byte 0x00000DFE
_080FB6E4: .4byte RNG_0202f388
_080FB6E8: .4byte 0x000343FD
_080FB6EC: .4byte 0x00269EC3
_080FB6F0: .4byte 0x00042400
_080FB6F4:
	ldr r1, _080FB7AC @ =RNG_0202f388
	mov r8, r1
	ldr r0, [r1]
	ldr r5, _080FB7B0 @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _080FB7B4 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r1]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r1, r0, #0
	movs r0, #0xfc
	lsls r0, r0, #0xa
	adds r1, r1, r0
	adds r2, r6, #0
	muls r2, r5, r2
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r3, r2, #1
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	ldr r6, _080FB7B8 @ =0x08386BC0
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r3, r0, #1
	mov r4, r8
	str r3, [r4]
	lsrs r0, r0, #0x11
	movs r3, #0xf
	ands r0, r3
	adds r0, r0, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	bl FUN_08099fb8
_080FB74A:
	ldrh r0, [r7, #0x1a]
	subs r0, #1
	strh r0, [r7, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FB804
	ldrh r0, [r7, #0x18]
	strh r0, [r7, #0x1a]
	adds r1, r7, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #8
	bls _080FB7C0
	movs r0, #0
	strb r0, [r1]
	ldr r4, _080FB7AC @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080FB7B0 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080FB7B4 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #6
	bl __umodsi3
	adds r1, r0, #0
	ldr r0, _080FB7BC @ =0x00042400
	adds r1, r1, r0
	mov r2, r8
	muls r2, r5, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r4]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08099fb8
	b _080FB804
	.align 2, 0
_080FB7AC: .4byte RNG_0202f388
_080FB7B0: .4byte 0x000343FD
_080FB7B4: .4byte 0x00269EC3
_080FB7B8: .4byte 0x08386BC0
_080FB7BC: .4byte 0x00042400
_080FB7C0:
	ldr r4, _080FB810 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080FB814 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080FB818 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r1, r0, #0
	movs r0, #0xfc
	lsls r0, r0, #0xa
	adds r1, r1, r0
	mov r2, r8
	muls r2, r5, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r4]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	adds r0, r7, #0
	movs r3, #0
	bl FUN_08099fb8
_080FB804:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FB810: .4byte RNG_0202f388
_080FB814: .4byte 0x000343FD
_080FB818: .4byte 0x00269EC3

	thumb_func_start initLeviathanMinigame
initLeviathanMinigame: @ 0x080FB81C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r0, _080FBAC8 @ =0x00000DCC
	adds r0, r0, r7
	mov r8, r0
	ldr r2, _080FBACC @ =0x00000DC4
	adds r1, r7, r2
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #0xb
	str r0, [r1, #4]
	movs r0, #9
	bl ResetLandscape
	ldr r1, _080FBAD0 @ =gStaticMotionGraphics
	mov sl, r1
	ldr r2, _080FBAD4 @ =wStaticGraphicTilenums
	ldrh r1, [r2]
	mov r2, sl
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, sl
	bl LoadGraphic
	ldr r1, _080FBAD8 @ =wStaticMotionPalIDs
	mov sb, r1
	ldrh r1, [r1]
	ldr r2, _080FBADC @ =gStaticMotionGraphics+12
	ldrb r0, [r2, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r2, #0
	bl LoadPalette
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r1, #0x6a
	ldr r0, _080FBAE0 @ =0x00000167
	strh r0, [r1]
	mov r5, sb
	adds r5, #0x6a
	movs r2, #0
	strh r2, [r5]
	ldr r4, _080FBAE4 @ =0x00000424
	mov r2, sl
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r0, _080FBAE8 @ =0x00000195
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	strh r0, [r1, #0x30]
	movs r0, #2
	mov r2, sb
	strh r0, [r2, #0x30]
	movs r6, #0xf0
	lsls r6, r6, #1
	mov r1, sl
	adds r0, r6, r1
	ldr r2, _080FBAD4 @ =wStaticGraphicTilenums
	ldrh r1, [r2, #0x30]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r1, _080FBADC @ =gStaticMotionGraphics+12
	adds r0, r6, r1
	mov r2, sb
	ldrh r1, [r2, #0x30]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	movs r4, #0xef
	lsls r5, r4, #1
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0]
	add r5, sb
	movs r2, #0
	strh r2, [r5]
	lsls r4, r4, #4
	movs r0, #0xef
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, sl
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r0, _080FBAD4 @ =wStaticGraphicTilenums
	adds r1, r0, r6
	ldr r0, _080FBAEC @ =0x000002A7
	strh r0, [r1]
	add r6, sb
	movs r2, #2
	strh r2, [r6]
	movs r4, #0x96
	lsls r4, r4, #5
	mov r2, sl
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xf1
	lsls r5, r4, #1
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xb6
	lsls r1, r1, #2
	strh r1, [r0]
	add r5, sb
	movs r2, #2
	strh r2, [r5]
	lsls r4, r4, #4
	movs r0, #0xf1
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, sl
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xf2
	lsls r0, r4, #1
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r2, r1, r0
	movs r1, #0xbb
	lsls r1, r1, #2
	strh r1, [r2]
	add sb, r0
	movs r0, #5
	mov r2, sb
	strh r0, [r2]
	lsls r4, r4, #4
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r4, r4, r0
	add sl, r4
	mov r2, sl
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, sl
	bl LoadGraphic
	ldr r1, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r1
	mov r2, sb
	ldrh r1, [r2]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r2, #0xf7
	lsls r2, r2, #0xa
	mov r0, r8
	movs r1, #0xb4
	lsls r1, r1, #9
	bl CreatePlayerLeviathan
	mov r1, r8
	str r0, [r1, #4]
	ldr r2, _080FBAF0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080FBAF4 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080FBAF8 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	mov r0, r8
	bl FUN_0809a02c
	mov r1, r8
	str r0, [r1, #0xc]
	movs r0, #0x3c
	strh r0, [r1, #0x14]
	strh r0, [r1, #0x16]
	movs r0, #0xb4
	strh r0, [r1, #0x18]
	strh r0, [r1, #0x1a]
	movs r0, #0xe1
	lsls r0, r0, #3
	str r0, [r1, #0x20]
	ldr r2, _080FBAFC @ =0x00000DFD
	adds r0, r7, r2
	movs r1, #0
	strb r1, [r0]
	movs r2, #0
	mov r0, r8
	str r2, [r0, #0x1c]
	ldr r1, _080FBB00 @ =0x00000E01
	adds r0, r7, r1
	strb r2, [r0]
	subs r1, #3
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r7, r2
	movs r1, #0
	strb r1, [r0]
	movs r2, #0
	mov r0, r8
	str r2, [r0, #0x24]
	str r2, [r0, #0x28]
	ldr r0, _080FBB04 @ =gSystemSavedataManager
	ldr r0, [r0, #0x38]
	mov r1, r8
	str r0, [r1, #0x2c]
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	ldr r1, _080FBB08 @ =0x00000DFC
	adds r0, r7, r1
	strb r2, [r0]
	movs r0, #0xb6
	bl playBGM
	movs r0, #0x32
	bl PlaySound
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FBAC8: .4byte 0x00000DCC
_080FBACC: .4byte 0x00000DC4
_080FBAD0: .4byte gStaticMotionGraphics
_080FBAD4: .4byte wStaticGraphicTilenums
_080FBAD8: .4byte wStaticMotionPalIDs
_080FBADC: .4byte gStaticMotionGraphics+12
_080FBAE0: .4byte 0x00000167
_080FBAE4: .4byte 0x00000424
_080FBAE8: .4byte 0x00000195
_080FBAEC: .4byte 0x000002A7
_080FBAF0: .4byte RNG_0202f388
_080FBAF4: .4byte 0x000343FD
_080FBAF8: .4byte 0x00269EC3
_080FBAFC: .4byte 0x00000DFD
_080FBB00: .4byte 0x00000E01
_080FBB04: .4byte gSystemSavedataManager
_080FBB08: .4byte 0x00000DFC

	thumb_func_start leviathanMinigame
leviathanMinigame: @ 0x080FBB0C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080FBB38 @ =0x00000DCC
	adds r4, r5, r0
	ldr r0, _080FBB3C @ =0x08386BA4
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	adds r0, r5, #0
	bl leviathan_minigame_080fb594
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bge _080FBB40
	movs r0, #0
	str r0, [r4, #0x24]
	b _080FBB48
	.align 2, 0
_080FBB38: .4byte 0x00000DCC
_080FBB3C: .4byte 0x08386BA4
_080FBB40:
	ldr r1, _080FBB68 @ =0x0001869F
	cmp r0, r1
	ble _080FBB48
	str r1, [r4, #0x24]
_080FBB48:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x2c]
	cmp r1, r0
	ble _080FBB7C
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #0
	bne _080FBB6C
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
	b _080FBB72
	.align 2, 0
_080FBB68: .4byte 0x0001869F
_080FBB6C:
	ldr r0, _080FBB78 @ =0x00000137
	bl PlaySound
_080FBB72:
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x2c]
	b _080FBB88
	.align 2, 0
_080FBB78: .4byte 0x00000137
_080FBB7C:
	ldr r0, [r4, #0x28]
	cmp r0, r1
	beq _080FBB88
	ldr r0, _080FBB9C @ =0x00000137
	bl PlaySound
_080FBB88:
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x28]
	adds r0, r5, #0
	bl leviathan_minigame_080fb550
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080FBB9C: .4byte 0x00000137

	thumb_func_start leviathan_minigame_080fbba0
leviathan_minigame_080fbba0: @ 0x080FBBA0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080FBBB8 @ =0x00000DCC
	adds r4, r5, r0
	ldrb r0, [r4, #1]
	cmp r0, #1
	beq _080FBBD4
	cmp r0, #1
	bgt _080FBBBC
	cmp r0, #0
	beq _080FBBC6
	b _080FBC1A
	.align 2, 0
_080FBBB8: .4byte 0x00000DCC
_080FBBBC:
	cmp r0, #2
	beq _080FBBF0
	cmp r0, #3
	beq _080FBC04
	b _080FBC1A
_080FBBC6:
	ldr r0, _080FBBEC @ =0x00000DFF
	adds r1, r5, r0
	movs r0, #0x3c
	strb r0, [r1]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBBD4:
	adds r1, r4, #0
	adds r1, #0x33
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080FBC1A
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FBC1A
	.align 2, 0
_080FBBEC: .4byte 0x00000DFF
_080FBBF0:
	movs r0, #0x1d
	bl PlaySound
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r4, #8]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBC04:
	ldr r0, [r4, #8]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FBC1A
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strb r1, [r4, #3]
_080FBC1A:
	movs r0, #0
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	adds r0, r5, #0
	bl leviathan_minigame_080fb5dc
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start leviathan_minigame_080fbc30
leviathan_minigame_080fbc30: @ 0x080FBC30
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080FBC54 @ =0x00000DCC
	adds r4, r5, r0
	ldr r0, _080FBC58 @ =gJoypad
	ldrh r1, [r0]
	strh r1, [r4, #0x10]
	ldrh r0, [r0, #4]
	strh r0, [r4, #0x12]
	ldr r0, _080FBC5C @ =0x00000DFD
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FBC60
	subs r0, #1
	strb r0, [r1]
	b _080FBC92
	.align 2, 0
_080FBC54: .4byte 0x00000DCC
_080FBC58: .4byte gJoypad
_080FBC5C: .4byte 0x00000DFD
_080FBC60:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _080FBC6C
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FBC8C
_080FBC6C:
	ldr r2, _080FBCCC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080FBCD0 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080FBCD4 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0809a02c
	str r0, [r4, #0xc]
_080FBC8C:
	adds r0, r5, #0
	bl leviathan_minigame_080fb66c
_080FBC92:
	ldr r0, [r4, #0x20]
	ldr r1, _080FBCD8 @ =0x00002A30
	cmp r0, r1
	ble _080FBC9C
	str r1, [r4, #0x20]
_080FBC9C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _080FBCAA
	subs r0, #1
	str r0, [r4, #0x20]
	cmp r0, #0
	bgt _080FBCC2
_080FBCAA:
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x34
	movs r0, #1
	strb r0, [r2]
	str r1, [r4, #0x20]
_080FBCC2:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FBCCC: .4byte RNG_0202f388
_080FBCD0: .4byte 0x000343FD
_080FBCD4: .4byte 0x00269EC3
_080FBCD8: .4byte 0x00002A30

	thumb_func_start leviathan_minigame_080fbcdc
leviathan_minigame_080fbcdc: @ 0x080FBCDC
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _080FBD20 @ =0x00000DCC
	adds r4, r1, r0
	movs r5, #0
	strh r5, [r4, #0x10]
	strh r5, [r4, #0x12]
	adds r0, #0x31
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080FBCF8
	subs r0, #1
	strb r0, [r2]
_080FBCF8:
	adds r0, r1, #0
	bl leviathan_minigame_080fb5dc
	ldr r0, [r4, #0x20]
	ldr r1, _080FBD24 @ =0x00002A30
	cmp r0, r1
	ble _080FBD08
	str r1, [r4, #0x20]
_080FBD08:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bgt _080FBD10
	str r5, [r4, #0x20]
_080FBD10:
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _080FBDB4
	lsls r0, r0, #2
	ldr r1, _080FBD28 @ =_080FBD2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FBD20: .4byte 0x00000DCC
_080FBD24: .4byte 0x00002A30
_080FBD28: .4byte _080FBD2C
_080FBD2C: @ jump table
	.4byte _080FBD44 @ case 0
	.4byte _080FBD5E @ case 1
	.4byte _080FBD70 @ case 2
	.4byte _080FBD7E @ case 3
	.4byte _080FBD8E @ case 4
	.4byte _080FBD9A @ case 5
_080FBD44:
	movs r0, #0xb6
	bl fadeoutBGM
	movs r0, #0xf6
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x33
	movs r0, #0x3c
	strb r0, [r1]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBD5E:
	adds r1, r4, #0
	adds r1, #0x33
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080FBDB4
	b _080FBD86
_080FBD70:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r4, #8]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBD7E:
	ldr r0, [r4, #8]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FBDB4
_080FBD86:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FBDB4
_080FBD8E:
	ldr r1, _080FBDB0 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBD9A:
	ldr r0, _080FBDB0 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FBDB4
	movs r0, #0x32
	bl stopSound
	movs r0, #0
	b _080FBDB6
	.align 2, 0
_080FBDB0: .4byte gGameState
_080FBDB4:
	movs r0, #1
_080FBDB6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start exitLeviathanMinigame
exitLeviathanMinigame: @ 0x080FBDBC
	push {lr}
	ldr r1, _080FBDD4 @ =0x00000DCC
	adds r0, r0, r1
	ldr r1, _080FBDD8 @ =gSystemSavedataManager
	ldr r0, [r0, #0x2c]
	str r0, [r1, #0x38]
	bl SaveSystemData
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080FBDD4: .4byte 0x00000DCC
_080FBDD8: .4byte gSystemSavedataManager

	thumb_func_start phantomMinigame_080fbddc
phantomMinigame_080fbddc: @ 0x080FBDDC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080FBE14 @ =0x00000DCC
	adds r4, r4, r0
	ldr r0, _080FBE18 @ =0x0810E2B8
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x34]
	movs r1, #0xc
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, _080FBE1C @ =0x0810E2C0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x3c]
	movs r1, #0x1c
	movs r2, #0
	bl minigame_str_080e9d04
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FBE14: .4byte 0x00000DCC
_080FBE18: .4byte 0x0810E2B8
_080FBE1C: .4byte 0x0810E2C0

	thumb_func_start initPhantomMinigame
initPhantomMinigame: @ 0x080FBE20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r0, _080FC058 @ =0x00000DCC
	adds r7, r4, r0
	ldr r2, _080FC05C @ =0x00000DC4
	adds r1, r4, r2
	ldr r0, _080FC060 @ =0x0009D800
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #0xb
	str r0, [r1, #4]
	movs r0, #6
	bl ResetLandscape
	movs r2, #0
	str r2, [r7, #0x14]
	str r2, [r7, #4]
	movs r5, #0xa0
	lsls r5, r5, #7
	str r5, [r7, #0x1c]
	movs r3, #0xa0
	lsls r3, r3, #8
	str r3, [r7, #0x20]
	movs r0, #0xea
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	str r5, [r7, #0x24]
	str r3, [r7, #0x28]
	ldr r0, [r7, #8]
	ldr r0, [r0, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r7, #0x18]
	movs r3, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r7, #0x2c]
	str r2, [r7, #0x34]
	str r2, [r7, #0x38]
	ldr r0, _080FC064 @ =gSystemSavedataManager
	ldr r0, [r0, #0x3c]
	str r0, [r7, #0x3c]
	str r2, [r7, #0x30]
	ldr r0, _080FC068 @ =0x00000EA1
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	strb r3, [r7]
	strb r3, [r7, #1]
	strb r3, [r7, #2]
	strb r3, [r7, #3]
	ldr r1, _080FC06C @ =0x00000EA2
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
	subs r1, #0x1b
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	mov r8, r2
	mov sb, r2
	movs r0, #0xe7
	lsls r0, r0, #4
	adds r6, r4, r0
	subs r1, #0x8c
	adds r5, r4, r1
_080FBED2:
	mov r2, r8
	lsls r4, r2, #3
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #0xa0
	lsls r3, r3, #2
	bl createPhantomIcon
	adds r1, r7, #0
	adds r1, #0xa4
	adds r1, r1, r4
	movs r0, #0xdc
	lsls r0, r0, #8
	mov r2, sb
	subs r0, r0, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xa8
	adds r0, r0, r4
	movs r1, #0x8e
	lsls r1, r1, #8
	str r1, [r0]
	ldrb r1, [r5, #0x11]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x60
	orrs r0, r1
	movs r2, #0xd
	rsbs r2, r2, #0
	adds r1, r2, #0
	ands r0, r1
	strb r0, [r5, #0x11]
	movs r0, #0x90
	lsls r0, r0, #5
	add sb, r0
	adds r6, #8
	adds r5, #0x20
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #2
	ble _080FBED2
	ldr r6, _080FC070 @ =gStaticMotionGraphics
	ldr r0, _080FC074 @ =wStaticGraphicTilenums
	mov sb, r0
	ldrh r1, [r0]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	adds r0, r6, #0
	bl LoadGraphic
	ldr r0, _080FC078 @ =gStaticMotionGraphics+12
	mov sl, r0
	ldr r1, _080FC07C @ =wStaticMotionPalIDs
	mov r8, r1
	ldrh r1, [r1]
	ldrb r0, [r0, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	mov r0, sl
	bl LoadPalette
	ldr r5, _080FC080 @ =0x00000A78
	adds r0, r5, r6
	movs r4, #0x86
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r5, sl
	add r4, r8
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadPalette
	movs r4, #0xe1
	lsls r4, r4, #2
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0x5a
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, sl
	mov r0, r8
	adds r0, #0x5a
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xc8
	lsls r4, r4, #4
	adds r6, r4, r6
	movs r5, #0xa0
	lsls r5, r5, #1
	add sb, r5
	mov r2, sb
	ldrh r1, [r2]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r6, #0
	bl LoadGraphic
	add r4, sl
	add r8, r5
	mov r2, r8
	ldrh r1, [r2]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080FC060 @ =0x0009D800
	movs r2, #0xbe
	lsls r2, r2, #0xb
	adds r0, r7, #0
	adds r1, r4, #0
	bl CreatePlayerPhantom
	str r0, [r7, #8]
	movs r2, #0xbf
	lsls r2, r2, #0xb
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080d915c
	ldr r0, [r7, #8]
	ldr r1, [r0, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r1, r1, r2
	ldr r2, [r0, #0x58]
	movs r0, #0x80
	lsls r0, r0, #5
	adds r2, r2, r0
	adds r0, r7, #0
	movs r3, #0
	bl FUN_080d91b4
	movs r0, #0xa8
	bl playBGM
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FC058: .4byte 0x00000DCC
_080FC05C: .4byte 0x00000DC4
_080FC060: .4byte 0x0009D800
_080FC064: .4byte gSystemSavedataManager
_080FC068: .4byte 0x00000EA1
_080FC06C: .4byte 0x00000EA2
_080FC070: .4byte gStaticMotionGraphics
_080FC074: .4byte wStaticGraphicTilenums
_080FC078: .4byte gStaticMotionGraphics+12
_080FC07C: .4byte wStaticMotionPalIDs
_080FC080: .4byte 0x00000A78

	thumb_func_start phantomMinigame
phantomMinigame: @ 0x080FC084
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _080FC0CC @ =0x00000DCC
	adds r6, r4, r0
	ldr r1, _080FC0D0 @ =0x08386BD0
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	mov r8, r0
	ldr r0, [r6, #0x34]
	ldr r1, _080FC0D4 @ =0x0001869F
	cmp r0, r1
	ble _080FC0AC
	str r1, [r6, #0x34]
_080FC0AC:
	ldr r1, [r6, #0x34]
	ldr r0, [r6, #0x3c]
	cmp r1, r0
	ble _080FC0EC
	ldr r0, _080FC0D8 @ =0x00000EA3
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080FC0DC
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
	b _080FC0E2
	.align 2, 0
_080FC0CC: .4byte 0x00000DCC
_080FC0D0: .4byte 0x08386BD0
_080FC0D4: .4byte 0x0001869F
_080FC0D8: .4byte 0x00000EA3
_080FC0DC:
	ldr r0, _080FC0E8 @ =0x00000137
	bl PlaySound
_080FC0E2:
	ldr r0, [r6, #0x34]
	str r0, [r6, #0x3c]
	b _080FC0F8
	.align 2, 0
_080FC0E8: .4byte 0x00000137
_080FC0EC:
	ldr r0, [r6, #0x38]
	cmp r0, r1
	beq _080FC0F8
	ldr r0, _080FC138 @ =0x00000137
	bl PlaySound
_080FC0F8:
	ldr r0, [r6, #0x34]
	str r0, [r6, #0x38]
	adds r0, r4, #0
	bl phantomMinigame_080fbddc
	movs r5, #0
	adds r0, r6, #0
	adds r0, #0xd5
	adds r7, r0, #0
	ldrb r0, [r7]
	cmp r5, r0
	bge _080FC12A
	adds r4, r6, #0
	adds r4, #0x44
_080FC114:
	ldr r2, [r4, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xbc
	bl _call_via_r2
	adds r4, #0x20
	adds r5, #1
	ldrb r0, [r7]
	cmp r5, r0
	blt _080FC114
_080FC12A:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FC138: .4byte 0x00000137

	thumb_func_start phantomMinigame_080fc13c
phantomMinigame_080fc13c: @ 0x080FC13C
	push {r4, lr}
	ldr r1, _080FC154 @ =0x00000DCC
	adds r4, r0, r1
	ldrb r0, [r4, #1]
	cmp r0, #1
	beq _080FC16C
	cmp r0, #1
	bgt _080FC158
	cmp r0, #0
	beq _080FC162
	b _080FC1A8
	.align 2, 0
_080FC154: .4byte 0x00000DCC
_080FC158:
	cmp r0, #2
	beq _080FC17E
	cmp r0, #3
	beq _080FC192
	b _080FC1A8
_080FC162:
	movs r0, #0x3c
	str r0, [r4, #0x40]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FC16C:
	ldr r0, [r4, #0x40]
	subs r0, #1
	str r0, [r4, #0x40]
	cmp r0, #0
	bne _080FC1A8
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FC1A8
_080FC17E:
	movs r0, #0x1d
	bl PlaySound
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r4, #0xc]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FC192:
	ldr r0, [r4, #0xc]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FC1A8
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strb r1, [r4, #3]
_080FC1A8:
	movs r0, #0
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start phantomMinigame_080fc1b8
phantomMinigame_080fc1b8: @ 0x080FC1B8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080FC2E4 @ =0x00000DCC
	adds r5, r6, r0
	ldr r1, _080FC2E8 @ =gJoypad
	ldrh r0, [r1]
	movs r4, #0
	strh r0, [r5, #0x10]
	ldrh r0, [r1, #4]
	strh r0, [r5, #0x12]
	ldr r3, [r5, #8]
	ldr r1, _080FC2EC @ =0x00000DC4
	adds r2, r6, r1
	ldr r0, [r3, #0x54]
	ldr r1, [r2]
	cmp r0, r1
	bgt _080FC1DC
	b _080FC358
_080FC1DC:
	subs r1, r0, r1
	ldr r0, [r5, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x30]
	ldr r1, [r3, #0x54]
	ldr r0, [r2]
	subs r1, r1, r0
	ldr r0, [r5, #4]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldr r1, [r3, #0x54]
	ldr r0, [r2]
	subs r1, r1, r0
	ldr r0, [r5, #0x1c]
	adds r0, r0, r1
	str r0, [r5, #0x1c]
	ldr r1, [r3, #0x54]
	ldr r0, [r2]
	subs r1, r1, r0
	ldr r0, [r5, #0x24]
	adds r0, r0, r1
	str r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	cmp r0, r1
	blt _080FC24A
	ldr r2, _080FC2F0 @ =0xFFFFFF00
	adds r1, r1, r2
	str r1, [r5, #0x28]
	ldr r0, _080FC2F4 @ =0x00003BFF
	cmp r1, r0
	bgt _080FC21E
	adds r0, #1
	str r0, [r5, #0x28]
_080FC21E:
	ldr r1, [r5, #4]
	movs r0, #0xa7
	lsls r0, r0, #0xc
	adds r1, r1, r0
	ldr r3, _080FC2F8 @ =RNG_0202f388
	ldr r2, [r3]
	ldr r0, _080FC2FC @ =0x000343FD
	muls r2, r0, r2
	ldr r0, _080FC300 @ =0x00269EC3
	adds r2, r2, r0
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r3]
	lsls r2, r2, #1
	lsrs r2, r2, #0x12
	movs r0, #0xba
	lsls r0, r0, #0xb
	adds r2, r2, r0
	adds r0, r5, #0
	bl CreateIronStar
	str r4, [r5, #0x24]
_080FC24A:
	ldr r1, [r5, #0x1c]
	ldr r0, [r5, #0x20]
	adds r2, r0, #0
	cmp r1, r2
	blt _080FC2CE
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080FC268
	strh r1, [r5, #0x2c]
_080FC268:
	ldr r0, _080FC2F0 @ =0xFFFFFF00
	adds r1, r2, r0
	str r1, [r5, #0x20]
	ldr r0, _080FC304 @ =0x00004FFF
	cmp r1, r0
	bgt _080FC278
	adds r0, #1
	str r0, [r5, #0x20]
_080FC278:
	ldr r2, [r5, #0x18]
	ldr r1, _080FC308 @ =0xFFFFE000
	adds r2, r2, r1
	ldr r3, _080FC2F8 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080FC2FC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080FC300 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #1
	lsrs r0, r0, #0x12
	adds r2, r2, r0
	str r2, [r5, #0x18]
	ldr r0, _080FC30C @ =0x0005DFFF
	cmp r2, r0
	bgt _080FC2A2
	adds r0, #1
	str r0, [r5, #0x18]
_080FC2A2:
	ldr r0, [r5, #0x18]
	movs r1, #0xc6
	lsls r1, r1, #0xb
	cmp r0, r1
	ble _080FC2AE
	str r1, [r5, #0x18]
_080FC2AE:
	ldr r1, [r5, #4]
	movs r2, #0xa7
	lsls r2, r2, #0xc
	adds r1, r1, r2
	ldr r2, [r5, #0x18]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_080d91b4
	adds r1, r5, #0
	adds r1, #0xd4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
	str r0, [r5, #0x1c]
_080FC2CE:
	ldr r4, [r5, #4]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl __modsi3
	cmp r0, r4
	bge _080FC314
	ldr r0, _080FC310 @ =0xFFFF1000
	b _080FC316
	.align 2, 0
_080FC2E4: .4byte 0x00000DCC
_080FC2E8: .4byte gJoypad
_080FC2EC: .4byte 0x00000DC4
_080FC2F0: .4byte 0xFFFFFF00
_080FC2F4: .4byte 0x00003BFF
_080FC2F8: .4byte RNG_0202f388
_080FC2FC: .4byte 0x000343FD
_080FC300: .4byte 0x00269EC3
_080FC304: .4byte 0x00004FFF
_080FC308: .4byte 0xFFFFE000
_080FC30C: .4byte 0x0005DFFF
_080FC310: .4byte 0xFFFF1000
_080FC314:
	movs r0, #0
_080FC316:
	str r0, [r5, #0x14]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl __modsi3
	str r0, [r5, #4]
	ldr r0, _080FC34C @ =0x00000DC4
	adds r2, r6, r0
	ldr r1, _080FC350 @ =0x0009D800
	str r1, [r2]
	ldr r0, [r5, #4]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, [r5, #0x30]
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080FC35A
	ldr r2, _080FC354 @ =0xFFFFF000
	adds r0, r1, r2
	str r0, [r5, #0x30]
	ldr r0, [r5, #0x34]
	adds r0, #1
	str r0, [r5, #0x34]
	b _080FC35A
	.align 2, 0
_080FC34C: .4byte 0x00000DC4
_080FC350: .4byte 0x0009D800
_080FC354: .4byte 0xFFFFF000
_080FC358:
	str r4, [r5, #0x14]
_080FC35A:
	ldr r0, [r5, #8]
	ldr r1, [r0, #0x58]
	movs r0, #0xd2
	lsls r0, r0, #0xb
	cmp r1, r0
	bgt _080FC370
	adds r0, r5, #0
	adds r0, #0xd5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FC386
_080FC370:
	adds r2, r5, #0
	adds r2, #0xd6
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	strb r1, [r5, #1]
	strb r1, [r5, #2]
	strb r1, [r5, #3]
_080FC386:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start phantomMinigame_080fc390
phantomMinigame_080fc390: @ 0x080FC390
	push {r4, lr}
	ldr r1, _080FC3AC @ =0x00000DCC
	adds r4, r0, r1
	movs r0, #0
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _080FC424
	lsls r0, r0, #2
	ldr r1, _080FC3B0 @ =_080FC3B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FC3AC: .4byte 0x00000DCC
_080FC3B0: .4byte _080FC3B4
_080FC3B4: @ jump table
	.4byte _080FC3CC @ case 0
	.4byte _080FC3DC @ case 1
	.4byte _080FC3E8 @ case 2
	.4byte _080FC3F6 @ case 3
	.4byte _080FC406 @ case 4
	.4byte _080FC412 @ case 5
_080FC3CC:
	movs r0, #0xa8
	bl fadeoutBGM
	movs r0, #0x3c
	str r0, [r4, #0x40]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FC3DC:
	ldr r0, [r4, #0x40]
	subs r0, #1
	str r0, [r4, #0x40]
	cmp r0, #0
	bne _080FC424
	b _080FC3FE
_080FC3E8:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r4, #0xc]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FC3F6:
	ldr r0, [r4, #0xc]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FC424
_080FC3FE:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FC424
_080FC406:
	ldr r1, _080FC420 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FC412:
	ldr r0, _080FC420 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FC424
	movs r0, #0
	b _080FC426
	.align 2, 0
_080FC420: .4byte gGameState
_080FC424:
	movs r0, #1
_080FC426:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start exitPhantomMinigame
exitPhantomMinigame: @ 0x080FC42C
	push {lr}
	ldr r1, _080FC444 @ =0x00000DCC
	adds r0, r0, r1
	ldr r1, _080FC448 @ =gSystemSavedataManager
	ldr r0, [r0, #0x3c]
	str r0, [r1, #0x3c]
	bl SaveSystemData
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080FC444: .4byte 0x00000DCC
_080FC448: .4byte gSystemSavedataManager
