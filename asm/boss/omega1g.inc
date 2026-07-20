	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start OmegaGold_Die
OmegaGold_Die: @ 0x0805B22C
	push {lr}
	ldr r2, _0805B240 @ =0x08364C6C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805B240: .4byte 0x08364C6C

	thumb_func_start OmegaGold_Disappear
OmegaGold_Disappear: @ 0x0805B244
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xb
	bl RemovePaletteAnimation
	movs r0, #0x66
	bl RemovePaletteAnimation
	movs r0, #0x67
	bl RemovePaletteAnimation
	ldr r0, _0805B26C @ =0x0000010F
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl DeleteBoss
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805B26C: .4byte 0x0000010F

	thumb_func_start FUN_0805b270
FUN_0805b270: @ 0x0805B270
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0805B2F4
	cmp r0, #1
	bgt _0805B284
	cmp r0, #0
	beq _0805B28A
	b _0805B352
_0805B284:
	cmp r0, #2
	beq _0805B32C
	b _0805B352
_0805B28A:
	ldr r3, _0805B320 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0805B2AC
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0805B2AC
	ldr r0, _0805B324 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805B2AC:
	movs r0, #0xe8
	bl PlaySound
	movs r0, #0xb
	bl RemovePaletteAnimation
	movs r0, #0x66
	bl RemovePaletteAnimation
	movs r0, #0x67
	bl RemovePaletteAnimation
	ldr r0, _0805B328 @ =0x0000010F
	bl RemovePaletteAnimation
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B2F4:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B352
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B352
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0805B352
	.align 2, 0
_0805B320: .4byte gStageRun
_0805B324: .4byte 0x0000FFFE
_0805B328: .4byte 0x0000010F
_0805B32C:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805B352
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805B352:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b358
FUN_0805b358: @ 0x0805B358
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #1
	beq _0805B382
	cmp r1, #1
	bgt _0805B36C
	cmp r1, #0
	beq _0805B372
	b _0805B408
_0805B36C:
	cmp r1, #2
	beq _0805B3EC
	b _0805B408
_0805B372:
	movs r0, #0xb4
	strb r0, [r4, #0x12]
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B382:
	ldr r0, [r4, #0x60]
	adds r0, #8
	str r0, [r4, #0x60]
	movs r1, #0x90
	lsls r1, r1, #1
	cmp r0, r1
	ble _0805B392
	str r1, [r4, #0x60]
_0805B392:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805B3C8
	ldr r2, _0805B3E0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805B3E4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805B3E8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	subs r0, #3
	lsls r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x54]
_0805B3C8:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B3D8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B408
_0805B3D8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0805B408
	.align 2, 0
_0805B3E0: .4byte RNG_0202f388
_0805B3E4: .4byte 0x000343FD
_0805B3E8: .4byte 0x00269EC3
_0805B3EC:
	ldr r2, _0805B410 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	movs r3, #0
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _0805B414 @ =gOverworld
	ldr r1, _0805B418 @ =0x0002D025
	adds r0, r0, r1
	strb r3, [r0]
_0805B408:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805B410: .4byte gStageRun
_0805B414: .4byte gOverworld
_0805B418: .4byte 0x0002D025

	thumb_func_start FUN_0805b41c
FUN_0805b41c: @ 0x0805B41C
	movs r0, #1
	bx lr

	thumb_func_start goldOmega1_0805b420
goldOmega1_0805b420: @ 0x0805B420
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _0805B430
	cmp r0, #1
	beq _0805B434
	b _0805B450
_0805B430:
	movs r0, #1
	strb r0, [r2, #0xe]
_0805B434:
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0805B450
	ldr r0, _0805B454 @ =gOverworld
	ldr r1, _0805B458 @ =0x0002D025
	adds r0, r0, r1
	movs r1, #0
	strb r3, [r0]
	strb r3, [r2, #0xd]
	strb r1, [r2, #0xe]
_0805B450:
	pop {r0}
	bx r0
	.align 2, 0
_0805B454: .4byte gOverworld
_0805B458: .4byte 0x0002D025

	thumb_func_start FUN_0805b45c
FUN_0805b45c: @ 0x0805B45C
	movs r0, #1
	bx lr

	thumb_func_start makeGoldOmega1Mode2
makeGoldOmega1Mode2: @ 0x0805B460
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0xe]
	cmp r1, #1
	beq _0805B482
	cmp r1, #1
	bgt _0805B474
	cmp r1, #0
	beq _0805B47A
	b _0805B49E
_0805B474:
	cmp r1, #2
	beq _0805B498
	b _0805B49E
_0805B47A:
	movs r0, #1
	strb r0, [r2, #0xe]
	movs r0, #0x3c
	strb r0, [r2, #0x12]
_0805B482:
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	beq _0805B492
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B49E
_0805B492:
	ldrb r0, [r2, #0xe]
	adds r0, #1
	b _0805B49C
_0805B498:
	movs r0, #0
	strb r1, [r2, #0xd]
_0805B49C:
	strb r0, [r2, #0xe]
_0805B49E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805b4a4
FUN_0805b4a4: @ 0x0805B4A4
	movs r0, #1
	bx lr

	thumb_func_start FUN_0805b4a8
FUN_0805b4a8: @ 0x0805B4A8
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _0805B4B8
	cmp r0, #1
	beq _0805B4BC
	b _0805B4CE
_0805B4B8:
	movs r0, #1
	strb r0, [r2, #0xe]
_0805B4BC:
	ldr r0, _0805B4D4 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0805B4CE
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0805B4CE:
	pop {r0}
	bx r0
	.align 2, 0
_0805B4D4: .4byte gStageRun

	thumb_func_start changeGoldOmega1Mode
changeGoldOmega1Mode: @ 0x0805B4D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0805B586
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0805B586
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _0805B586
	adds r0, r5, #0
	adds r0, #0xb5
	adds r1, r5, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r6, r0, #0
	mov r8, r1
	cmp r3, r2
	bne _0805B558
	ldr r2, _0805B548 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805B54C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805B550 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _0805B554 @ =0x080FEFBE
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	bne _0805B57A
	adds r0, r5, #0
	bl FUN_0805b8ac
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0805B57A
	.align 2, 0
_0805B548: .4byte RNG_0202f388
_0805B54C: .4byte 0x000343FD
_0805B550: .4byte 0x00269EC3
_0805B554: .4byte 0x080FEFBE
_0805B558:
	ldr r2, _0805B594 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805B598 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805B59C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _0805B5A0 @ =0x080FEFBE
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
_0805B57A:
	strb r1, [r5, #0xd]
	strb r7, [r5, #0xe]
	ldrb r0, [r6]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r6]
_0805B586:
	movs r0, #1
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B594: .4byte RNG_0202f388
_0805B598: .4byte 0x000343FD
_0805B59C: .4byte 0x00269EC3
_0805B5A0: .4byte 0x080FEFBE

	thumb_func_start goldOmega1Neutral
goldOmega1Neutral: @ 0x0805B5A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0805B5B4
	cmp r5, #1
	beq _0805B5CC
	b _0805B5D2
_0805B5B4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805B5D8 @ =0x08364C8C
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	movs r0, #0x1e
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B5CC:
	adds r0, r4, #0
	bl floatGoldOmega1
_0805B5D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805B5D8: .4byte 0x08364C8C

	thumb_func_start nop_0805b5dc
nop_0805b5dc: @ 0x0805B5DC
	movs r0, #1
	bx lr

	thumb_func_start goldOmega1Laser
goldOmega1Laser: @ 0x0805B5E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0805B5EC
	b _0805B738
_0805B5EC:
	lsls r0, r0, #2
	ldr r1, _0805B5F8 @ =_0805B5FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805B5F8: .4byte _0805B5FC
_0805B5FC: @ jump table
	.4byte _0805B610 @ case 0
	.4byte _0805B670 @ case 1
	.4byte _0805B6C0 @ case 2
	.4byte _0805B6E4 @ case 3
	.4byte _0805B714 @ case 4
_0805B610:
	adds r0, r4, #0
	adds r0, #0x4c
	movs r2, #0
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r2, [r0, #4]
	str r2, [r4, #0x5c]
	movs r0, #3
	strb r0, [r4, #0x12]
	ldr r2, _0805B65C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805B660 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805B664 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805B668
	strb r0, [r4, #0xf]
	b _0805B66A
	.align 2, 0
_0805B65C: .4byte RNG_0202f388
_0805B660: .4byte 0x000343FD
_0805B664: .4byte 0x00269EC3
_0805B668:
	strb r1, [r4, #0xf]
_0805B66A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B670:
	movs r0, #0x30
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0805B698
	movs r0, #0x9a
	lsls r0, r0, #3
	ldr r2, _0805B694 @ =unk_080fefb8
	ldrb r1, [r4, #0x12]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0x30
	adds r3, r4, #0
	bl createGoldOmega1Laser
	b _0805B6AE
	.align 2, 0
_0805B694: .4byte unk_080fefb8
_0805B698:
	movs r0, #0x9a
	lsls r0, r0, #3
	ldr r2, _0805B6BC @ =0x080FEFBB
	ldrb r1, [r4, #0x12]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0x30
	adds r3, r4, #0
	bl createGoldOmega1Laser
_0805B6AE:
	movs r0, #0xb
	bl StepPaletteAnimation
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0805B738
	.align 2, 0
_0805B6BC: .4byte 0x080FEFBB
_0805B6C0:
	adds r0, r4, #0
	bl floatGoldOmega1
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0805B6DC
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B6DC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B6DC:
	adds r0, r4, #0
	bl floatGoldOmega1
	b _0805B70C
_0805B6E4:
	adds r0, r4, #0
	bl floatGoldOmega1
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805B708
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0805B70A
_0805B708:
	movs r0, #1
_0805B70A:
	strb r0, [r4, #0xe]
_0805B70C:
	movs r0, #0xb
	bl StepPaletteAnimation
	b _0805B738
_0805B714:
	adds r0, r4, #0
	bl floatGoldOmega1
	movs r0, #0xb
	bl StepPaletteAnimation
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B738
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805B738
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805B738:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_0805b740
nop_0805b740: @ 0x0805B740
	movs r0, #1
	bx lr

	thumb_func_start FUN_0805b744
FUN_0805b744: @ 0x0805B744
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #1
	beq _0805B78E
	cmp r2, #1
	bgt _0805B758
	cmp r2, #0
	beq _0805B75E
	b _0805B7E6
_0805B758:
	cmp r2, #2
	beq _0805B7C2
	b _0805B7E6
_0805B75E:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r4, #0x60]
	str r2, [r4, #0x5c]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B78E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B79A
	subs r0, #1
	strb r0, [r4, #0x12]
	b _0805B7B4
_0805B79A:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0805B7B4
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B7B4
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B7B4:
	movs r0, #0xb
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl floatGoldOmega1
	b _0805B7E6
_0805B7C2:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B7D2
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B7DA
_0805B7D2:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805B7DA:
	movs r0, #0xb
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl floatGoldOmega1
_0805B7E6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_0805b7ec
nop_0805b7ec: @ 0x0805B7EC
	movs r0, #1
	bx lr

	thumb_func_start FUN_0805b7f0
FUN_0805b7f0: @ 0x0805B7F0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _0805B800
	cmp r2, #1
	beq _0805B840
	b _0805B86C
_0805B800:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r4, #0x60]
	str r2, [r4, #0x5c]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x13]
	movs r0, #0x66
	bl RemovePaletteAnimation
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x67
	bl StartPaletteAnimation
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B840:
	adds r0, r4, #0
	adds r0, #0xc8
	ldr r0, [r0]
	ldrb r0, [r0, #0xe]
	cmp r0, #0x1d
	bls _0805B860
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x66
	bl StartPaletteAnimation
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0805B86C
_0805B860:
	movs r0, #0x67
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl floatGoldOmega1
_0805B86C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0


