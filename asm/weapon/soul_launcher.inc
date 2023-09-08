	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start SoulLauncher_Init
SoulLauncher_Init: @ 0x0803B14C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r7, [r6, #0x28]
	ldr r1, _0803B194 @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0x11]
	cmp r0, #1
	bne _0803B198
	movs r1, #0xce
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	b _0803B1A0
	.align 2, 0
_0803B194: .4byte gWeaponFnTable
_0803B198:
	ldr r1, _0803B1D0 @ =0x00006703
	adds r0, r6, #0
	bl SetMotion
_0803B1A0:
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803B1D4
	ldr r0, [r7, #0x54]
	movs r1, #0xb0
	lsls r1, r1, #4
	b _0803B1D8
	.align 2, 0
_0803B1D0: .4byte 0x00006703
_0803B1D4:
	ldr r0, [r7, #0x54]
	ldr r1, _0803B24C @ =0xFFFFF500
_0803B1D8:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _0803B250 @ =0xFFFFB800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _0803B254 @ =0x0836159C
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r6, #0x5c]
	ldr r0, _0803B258 @ =0xFFFFF900
	str r0, [r6, #0x60]
	movs r5, #0
	movs r0, #5
	strb r0, [r6, #0xd]
	movs r0, #0x40
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0xb4
	strb r5, [r0, #0xc]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r0, _0803B25C @ =0x08361558
	mov r8, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	bne _0803B260
	adds r0, r7, #0
	bl CalcRodBonus
	adds r0, #8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	movs r3, #0
	bl InitWeaponBody
	b _0803B27E
	.align 2, 0
_0803B24C: .4byte 0xFFFFF500
_0803B250: .4byte 0xFFFFB800
_0803B254: .4byte 0x0836159C
_0803B258: .4byte 0xFFFFF900
_0803B25C: .4byte 0x08361558
_0803B260:
	adds r0, r7, #0
	bl CalcRodBonus
	adds r0, #0xa
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	movs r3, #2
	bl InitWeaponBody
_0803B27E:
	ldr r0, _0803B294 @ =FUN_0803b4b0
	str r0, [r4, #0x24]
	adds r0, r6, #0
	bl SoulLauncher_Update
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B294: .4byte FUN_0803b4b0

	thumb_func_start SoulLauncher_Update
SoulLauncher_Update: @ 0x0803B298
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	beq _0803B2BC
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_0803B2BC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a40c
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	bls _0803B2D8
	b _0803B48A
_0803B2D8:
	lsls r0, r0, #2
	ldr r1, _0803B2E4 @ =_0803B2E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B2E4: .4byte _0803B2E8
_0803B2E8: @ jump table
	.4byte _0803B300 @ case 0
	.4byte _0803B35C @ case 1
	.4byte _0803B36C @ case 2
	.4byte _0803B3C0 @ case 3
	.4byte _0803B3CC @ case 4
	.4byte _0803B430 @ case 5
_0803B300:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0803B324
	str r0, [r4, #0x60]
_0803B324:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0803b4e8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803B334
	b _0803B48A
_0803B334:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	ldr r0, _0803B358 @ =0xFFFFF800
	cmp r2, r0
	blt _0803B34A
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
_0803B34A:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0803B408
	movs r0, #1
	strb r0, [r4, #0xd]
	b _0803B48A
	.align 2, 0
_0803B358: .4byte 0xFFFFF800
_0803B35C:
	ldr r1, _0803B3BC @ =0x00006701
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	movs r0, #2
	strb r0, [r4, #0xd]
_0803B36C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #1
	bl FUN_0803b4e8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803B38A
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0803B38A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r2, r0
	subs r0, #1
	cmp r1, r0
	bhi _0803B3A6
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
_0803B3A6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0803B48A
	movs r0, #3
	strb r0, [r4, #0xd]
	b _0803B48A
	.align 2, 0
_0803B3BC: .4byte 0x00006701
_0803B3C0:
	ldr r1, _0803B424 @ =0x00006702
	adds r0, r4, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r4, #0xd]
_0803B3CC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #1
	bl FUN_0803b4e8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803B3FE
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r2, r0, #0
	ldr r0, _0803B428 @ =0xFFFFF800
	cmp r2, r0
	blt _0803B3FE
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
_0803B3FE:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803B48A
_0803B408:
	ldr r1, _0803B42C @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl SoulLauncher_Die
	b _0803B48A
	.align 2, 0
_0803B424: .4byte 0x00006702
_0803B428: .4byte 0xFFFFF800
_0803B42C: .4byte gWeaponFnTable
_0803B430:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803B476
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0803B476
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToDown1
	adds r2, r0, #0
	ldr r0, [r4, #0x60]
	cmn r2, r0
	bge _0803B470
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
_0803B470:
	str r5, [r4, #0x60]
	strb r5, [r4, #0xd]
	b _0803B48A
_0803B476:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0803B48A
	str r1, [r4, #0x60]
	strb r1, [r4, #0xd]
_0803B48A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start SoulLauncher_Die
SoulLauncher_Die: @ 0x0803B490
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803B4AC @ =gWeaponFnTable
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
_0803B4AC: .4byte gWeaponFnTable

	thumb_func_start FUN_0803b4b0
FUN_0803b4b0: @ 0x0803B4B0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803B4DA
	ldr r1, [r2, #0x2c]
	ldr r3, _0803B4E0 @ =gMission
	ldrh r2, [r3, #0x20]
	ldr r0, _0803B4E4 @ =0x0000FFFE
	cmp r2, r0
	bhi _0803B4CE
	adds r0, r2, #1
	strh r0, [r3, #0x20]
_0803B4CE:
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	bne _0803B4DA
	adds r1, #0xb4
	movs r0, #1
	strb r0, [r1, #0xc]
_0803B4DA:
	pop {r0}
	bx r0
	.align 2, 0
_0803B4E0: .4byte gMission
_0803B4E4: .4byte 0x0000FFFE

	thumb_func_start FUN_0803b4e8
FUN_0803b4e8: @ 0x0803B4E8
	push {lr}
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0803B500 @ =0x0000800F
	cmp r1, r0
	bne _0803B4FA
	movs r1, #0
_0803B4FA:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_0803B500: .4byte 0x0000800F
