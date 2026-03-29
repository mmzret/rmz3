	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl MinigamePhantom_DrawScoreHiscore
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
