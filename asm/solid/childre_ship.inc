	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ChildreShip_Init
ChildreShip_Init: @ 0x080E02CC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080E0390 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080E03D8
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	beq _080E02F2
	ldr r0, _080E0394 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bgt _080E03D8
_080E02F2:
	ldrb r1, [r6, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	movs r1, #0xb4
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x25
	strb r5, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080E0398 @ =0x083719D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r1, [r6, #0xb]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xb]
	ldrb r0, [r6, #0x1c]
	strb r0, [r6, #0x1d]
	movs r4, #0xe1
	lsls r4, r4, #4
	ldr r1, _080E039C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080E03A0 @ =wStaticGraphicTilenums
	movs r5, #0xb4
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
	ldr r0, _080E03A4 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080E03A8 @ =wStaticMotionPalIDs
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
	ldrb r1, [r6, #0x10]
	cmp r1, #0
	bne _080E03AC
	str r1, [r6, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r6, #0x68]
	str r1, [r6, #0x64]
	b _080E03BA
	.align 2, 0
_080E0390: .4byte gCurStory
_080E0394: .4byte pZero2
_080E0398: .4byte 0x083719D0
_080E039C: .4byte gStaticMotionGraphics
_080E03A0: .4byte wStaticGraphicTilenums
_080E03A4: .4byte gStaticMotionGraphics+12
_080E03A8: .4byte wStaticMotionPalIDs
_080E03AC:
	movs r0, #0x80
	str r0, [r6, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r6, #0x68]
	movs r0, #3
	str r0, [r6, #0x64]
_080E03BA:
	movs r0, #0
	strb r0, [r6, #0x12]
	movs r2, #1
	strb r2, [r6, #0x13]
	movs r0, #0x96
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	ldr r1, _080E03E0 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
_080E03D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E03E0: .4byte gSolidFnTable

	thumb_func_start ChildreShip_Update
ChildreShip_Update: @ 0x080E03E4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	mov sb, r0
	ldrb r4, [r7, #0xd]
	cmp r4, #1
	beq _080E0458
	cmp r4, #1
	bgt _080E0404
	cmp r4, #0
	beq _080E040A
	b _080E063A
_080E0404:
	cmp r4, #2
	beq _080E0488
	b _080E063A
_080E040A:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080E0434
	ldr r0, _080E042C @ =0x00000103
	bl PlaySound
	ldr r1, _080E0430 @ =0x0000B401
	adds r0, r7, #0
	bl SetMotion
	b _080E0634
	.align 2, 0
_080E042C: .4byte 0x00000103
_080E0430: .4byte 0x0000B401
_080E0434:
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080E0440
	b _080E063A
_080E0440:
	ldr r1, _080E0454 @ =0x0000B404
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x1c
	strb r0, [r1]
	strb r4, [r7, #0xd]
	b _080E063A
	.align 2, 0
_080E0454: .4byte 0x0000B404
_080E0458:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r0, [r0, #9]
	ands r4, r0
	cmp r4, #0
	beq _080E046A
	b _080E063A
_080E046A:
	ldr r0, _080E0480 @ =0x00000147
	bl PlaySound
	ldr r1, _080E0484 @ =0x0000B403
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0xd]
	b _080E063A
	.align 2, 0
_080E0480: .4byte 0x00000147
_080E0484: .4byte 0x0000B403
_080E0488:
	ldr r1, [r7, #0x68]
	ldr r0, _080E0520 @ =0x00003FFF
	cmp r1, r0
	bgt _080E0496
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r7, #0x68]
_080E0496:
	ldr r1, [r7, #0x5c]
	ldr r0, _080E0524 @ =0x000001DF
	cmp r1, r0
	bgt _080E04A2
	adds r0, r1, #1
	str r0, [r7, #0x5c]
_080E04A2:
	ldr r1, [r7, #0x54]
	ldr r0, [r7, #0x5c]
	adds r5, r1, r0
	str r5, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080E0506
	ldr r2, _080E0528 @ =RNG_0202f388
	mov r8, r2
	ldr r0, [r2]
	ldr r4, _080E052C @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _080E0530 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r1, _080E0534 @ =0x00000FFF
	ands r0, r1
	ldr r6, _080E0538 @ =0xFFFFD800
	adds r0, r0, r6
	adds r0, r5, r0
	str r0, [sp]
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r5, r2, #1
	lsrs r2, r2, #0x11
	ands r2, r1
	ldr r1, _080E053C @ =0xFFFFF000
	adds r2, r2, r1
	ldr r1, [r7, #0x58]
	adds r1, r1, r2
	str r1, [sp, #4]
	adds r2, r5, #0
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r3, r2, #1
	mov r4, r8
	str r3, [r4]
	lsrs r2, r2, #0x11
	movs r3, #3
	ands r2, r3
	bl CreateSeaEnemy
_080E0506:
	ldr r0, _080E0540 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bls _080E0544
	mov r6, sb
	strb r6, [r7, #0x13]
	b _080E058E
	.align 2, 0
_080E0520: .4byte 0x00003FFF
_080E0524: .4byte 0x000001DF
_080E0528: .4byte RNG_0202f388
_080E052C: .4byte 0x000343FD
_080E0530: .4byte 0x00269EC3
_080E0534: .4byte 0x00000FFF
_080E0538: .4byte 0xFFFFD800
_080E053C: .4byte 0xFFFFF000
_080E0540: .4byte gStageRun+232
_080E0544:
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _080E058E
	movs r0, #1
	strb r0, [r7, #0x13]
	movs r4, #0xe1
	lsls r4, r4, #4
	ldr r1, _080E05AC @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080E05B0 @ =wStaticGraphicTilenums
	movs r5, #0xb4
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
	ldr r6, _080E05B4 @ =gStaticMotionGraphics+12
	adds r4, r4, r6
	ldr r0, _080E05B8 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
_080E058E:
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080E05D8
	ldr r1, [r7, #0x54]
	movs r0, #0xc6
	lsls r0, r0, #0xd
	cmp r1, r0
	ble _080E05BC
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	b _080E05CE
	.align 2, 0
_080E05AC: .4byte gStaticMotionGraphics
_080E05B0: .4byte wStaticGraphicTilenums
_080E05B4: .4byte gStaticMotionGraphics+12
_080E05B8: .4byte wStaticMotionPalIDs
_080E05BC:
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r2]
_080E05CE:
	ldr r1, [r7, #0x54]
	ldr r0, _080E05D4 @ =0x0019B000
	b _080E0610
	.align 2, 0
_080E05D4: .4byte 0x0019B000
_080E05D8:
	ldr r1, [r7, #0x54]
	ldr r0, _080E05FC @ =0x00297000
	cmp r1, r0
	bgt _080E0600
	movs r0, #0xf3
	lsls r0, r0, #0xd
	cmp r1, r0
	ble _080E0600
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r2]
	b _080E060C
	.align 2, 0
_080E05FC: .4byte 0x00297000
_080E0600:
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
_080E060C:
	ldr r1, [r7, #0x54]
	ldr r0, _080E07EC @ =0x0029E000
_080E0610:
	cmp r1, r0
	ble _080E063A
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
_080E0634:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080E063A:
	ldr r0, [r7, #0x60]
	cmp r0, #0
	beq _080E0644
	subs r0, #1
	str r0, [r7, #0x60]
_080E0644:
	movs r5, #0
	movs r1, #0xc0
	lsls r1, r1, #5
	mov r8, r1
	mov r6, sp
_080E064E:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	ldr r0, [r7, #0x64]
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080E06AE
	ldr r0, _080E07F0 @ =0x08371A00
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r2, [r7, #0x54]
	ldr r0, [r1]
	cmp r2, r0
	blt _080E06AE
	ldr r0, _080E07F4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	cmp r0, #1
	ble _080E06AE
	str r2, [sp]
	ldr r0, [r7, #0x58]
	add r0, r8
	str r0, [r6, #4]
	mov r0, sp
	movs r1, #0
	bl FUN_080b2794
	ldr r0, [r7, #0x58]
	mov r2, r8
	subs r0, r0, r2
	str r0, [r6, #4]
	mov r0, sp
	movs r1, #1
	bl FUN_080b2794
	movs r0, #1
	mov sb, r0
	mov r1, sb
	lsls r1, r4
	ldr r0, [r7, #0x64]
	orrs r0, r1
	str r0, [r7, #0x64]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound
_080E06AE:
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080E064E
	mov r2, sb
	cmp r2, #0
	beq _080E06D6
	ldr r0, [r7, #0x60]
	cmp r0, #0
	bne _080E06D6
	movs r0, #0x6a
	bl PlaySound
	movs r0, #0x96
	lsls r0, r0, #2
	str r0, [r7, #0x60]
_080E06D6:
	movs r4, #0
	mov sb, r4
	movs r5, #0
	ldr r6, _080E07F8 @ =0xFFFFE800
	mov r8, r6
	mov r6, sp
_080E06E2:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsls r1, r4, #0xc
	add r1, r8
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r7, #0x58]
	add r1, r8
	str r1, [r6, #4]
	ldr r0, [sp]
	bl FUN_0800d61c
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080E071C
	ldr r0, [sp]
	ldr r1, [r6, #4]
	bl FUN_080e086c
	movs r0, #0xc0
	str r0, [r7, #0x5c]
	movs r0, #2
	adds r1, r7, #0
	adds r1, #0x54
	bl AppendQuake
	movs r0, #1
	mov sb, r0
_080E071C:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080E06E2
	movs r5, #0
	mov r6, sp
_080E072C:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsls r1, r4, #0xc
	ldr r2, _080E07F8 @ =0xFFFFE800
	adds r1, r1, r2
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r7, #0x58]
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r1, r0
	str r1, [r6, #4]
	ldr r0, [sp]
	bl FUN_0800d61c
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080E076C
	ldr r0, [sp]
	ldr r1, [r6, #4]
	bl FUN_080e086c
	movs r0, #0xc0
	str r0, [r7, #0x5c]
	movs r0, #2
	adds r1, r7, #0
	adds r1, #0x54
	bl AppendQuake
	movs r1, #1
	mov sb, r1
_080E076C:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080E072C
	movs r5, #1
	mov r6, sp
_080E077C:
	ldr r0, [r7, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp]
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0xc
	ldr r1, _080E07F8 @ =0xFFFFE800
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	str r1, [r6, #4]
	ldr r0, [sp]
	bl FUN_0800d61c
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080E07BC
	ldr r0, [sp]
	ldr r1, [r6, #4]
	bl FUN_080e086c
	movs r0, #0xc0
	str r0, [r7, #0x5c]
	movs r0, #2
	adds r1, r7, #0
	adds r1, #0x54
	bl AppendQuake
	movs r2, #1
	mov sb, r2
_080E07BC:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _080E077C
	mov r4, sb
	lsls r0, r4, #0x10
	adds r4, r0, #0
	cmp r4, #0
	beq _080E080C
	ldr r0, _080E07FC @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bls _080E0804
	ldr r0, _080E0800 @ =0x0000013F
	bl PlaySound
	b _080E080C
	.align 2, 0
_080E07EC: .4byte 0x0029E000
_080E07F0: .4byte 0x08371A00
_080E07F4: .4byte gProjectileHeaderPtr
_080E07F8: .4byte 0xFFFFE800
_080E07FC: .4byte gStageRun+232
_080E0800: .4byte 0x0000013F
_080E0804:
	movs r0, #0xa0
	lsls r0, r0, #1
	bl PlaySound
_080E080C:
	ldr r0, _080E0830 @ =gOverworld
	ldr r6, _080E0834 @ =0x0002C00C
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	bne _080E0856
	cmp r4, #0
	beq _080E0838
	ldr r0, [r7, #0x60]
	cmp r0, #0
	bne _080E0856
	movs r0, #0x69
	b _080E084C
	.align 2, 0
_080E0830: .4byte gOverworld
_080E0834: .4byte 0x0002C00C
_080E0838:
	ldr r0, [r7, #0x60]
	cmp r0, #0
	bne _080E0856
	ldr r0, _080E0864 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _080E0856
	movs r0, #0x68
_080E084C:
	bl PlaySound
	movs r0, #0x96
	lsls r0, r0, #2
	str r0, [r7, #0x60]
_080E0856:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E0864: .4byte pZero2

	thumb_func_start ChildreShip_Die
ChildreShip_Die: @ 0x080E0868
	bx lr
	.align 2, 0

	thumb_func_start FUN_080e086c
FUN_080e086c: @ 0x080E086C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	mov sl, r1
	str r0, [sp]
	str r1, [sp, #4]
	movs r4, #6
	ldr r0, _080E0910 @ =gStageRun+232
	mov r1, sp
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bhi _080E08FE
	ldr r0, _080E0914 @ =gVFXHeaderPtr
	ldr r0, [r0]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	cmp r0, #0x17
	ble _080E08FE
	cmp r0, #0x2f
	bgt _080E08A4
	movs r4, #2
_080E08A4:
	cmp r4, #0
	beq _080E08FE
	ldr r2, _080E0918 @ =RNG_0202f388
	mov sb, r2
	ldr r6, _080E091C @ =0x000343FD
	ldr r5, _080E0920 @ =0x00269EC3
	ldr r3, _080E0924 @ =0x00001FFF
	mov r8, r3
_080E08B4:
	mov r7, sb
	ldr r0, [r7]
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov r2, r8
	ands r0, r2
	ldr r3, _080E0928 @ =0xFFFFF000
	adds r0, r0, r3
	ldr r7, [sp, #8]
	adds r0, r7, r0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	mov r3, r8
	ands r1, r3
	ldr r7, _080E0928 @ =0xFFFFF000
	adds r1, r1, r7
	add r1, sl
	muls r2, r6, r2
	adds r2, r2, r5
	lsls r2, r2, #1
	lsrs r3, r2, #1
	mov r7, sb
	str r3, [r7]
	lsrs r2, r2, #0x11
	movs r3, #3
	ands r2, r3
	bl CreateSeaEnemy
	subs r4, #1
	cmp r4, #0
	bne _080E08B4
_080E08FE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E0910: .4byte gStageRun+232
_080E0914: .4byte gVFXHeaderPtr
_080E0918: .4byte RNG_0202f388
_080E091C: .4byte 0x000343FD
_080E0920: .4byte 0x00269EC3
_080E0924: .4byte 0x00001FFF
_080E0928: .4byte 0xFFFFF000
