	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807b0d0
FUN_0807b0d0: @ 0x0807B0D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0807B11C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _0807B116
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807B120 @ =gEnemyFnTable
	movs r0, #0x1d
	strb r0, [r4, #9]
	ldr r0, [r1, #0x74]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x54]
	str r6, [r4, #0x58]
_0807B116:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B11C: .4byte gZakoHeaderPtr
_0807B120: .4byte gEnemyFnTable

	thumb_func_start FUN_0807b124
FUN_0807b124: @ 0x0807B124
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _0807B17C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0807B174
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807B180 @ =gEnemyFnTable
	movs r0, #0x1d
	strb r0, [r3, #9]
	ldr r0, [r1, #0x74]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x5c]
	str r7, [r3, #0x60]
_0807B174:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807B17C: .4byte gZakoHeaderPtr
_0807B180: .4byte gEnemyFnTable

	thumb_func_start FUN_0807b184
FUN_0807b184: @ 0x0807B184
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0807B1D4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0807B1CC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807B1D8 @ =gEnemyFnTable
	movs r0, #0x1d
	strb r0, [r3, #9]
	ldr r0, [r1, #0x74]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_0807B1CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B1D4: .4byte gZakoHeaderPtr
_0807B1D8: .4byte gEnemyFnTable

	thumb_func_start nop_0807b1dc
nop_0807b1dc: @ 0x0807B1DC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807b1e0
FUN_0807b1e0: @ 0x0807B1E0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0807B1F6
	movs r0, #0
	b _0807B214
_0807B1F6:
	ldr r1, _0807B218 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl WormerSnowBall_Die
	movs r0, #1
_0807B214:
	pop {r1}
	bx r1
	.align 2, 0
_0807B218: .4byte gEnemyFnTable

	thumb_func_start WormerSnowBall_Init
WormerSnowBall_Init: @ 0x0807B21C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0807B270 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0807B274 @ =0x083679AC
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bhi _0807B27C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807B278 @ =0x08367814
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	b _0807B292
	.align 2, 0
_0807B270: .4byte gEnemyFnTable
_0807B274: .4byte 0x083679AC
_0807B278: .4byte 0x08367814
_0807B27C:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807B2AC @ =0x08367814
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_0807B292:
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r0, _0807B2B0 @ =nop_0807b1dc
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl WormerSnowBall_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B2AC: .4byte 0x08367814
_0807B2B0: .4byte nop_0807b1dc

	thumb_func_start WormerSnowBall_Update
WormerSnowBall_Update: @ 0x0807B2B4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807b1e0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807B2E2
	ldr r1, _0807B2E8 @ =0x083677E8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807B2EC @ =0x083677F8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0807B2E2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B2E8: .4byte 0x083677E8
_0807B2EC: .4byte 0x083677F8

	thumb_func_start WormerSnowBall_Die
WormerSnowBall_Die: @ 0x0807B2F0
	push {lr}
	ldr r2, _0807B304 @ =0x08367808
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0807B304: .4byte 0x08367808

	thumb_func_start FUN_0807b308
FUN_0807b308: @ 0x0807B308
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807b30c
FUN_0807b30c: @ 0x0807B30C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807B324
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807B324:
	pop {r0}
	bx r0

	thumb_func_start FUN_0807b328
FUN_0807b328: @ 0x0807B328
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807B338
	cmp r0, #1
	beq _0807B376
	b _0807B402
_0807B338:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807B3E0 @ =0x0836782C
	bl SetDDP
	ldr r0, _0807B3E4 @ =0xFFFFFB00
	str r0, [r4, #0x60]
	ldr r2, _0807B3E8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0807B3EC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0807B3F0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #2
	bl __umodsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807B376:
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807B386
	str r1, [r4, #0x60]
_0807B386:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _0807B3F4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bls _0807B3FC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807B3F8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0807B402
	.align 2, 0
_0807B3E0: .4byte 0x0836782C
_0807B3E4: .4byte 0xFFFFFB00
_0807B3E8: .4byte RNG_0202f388
_0807B3EC: .4byte 0x000343FD
_0807B3F0: .4byte 0x00269EC3
_0807B3F4: .4byte gStageRun+232
_0807B3F8: .4byte gEnemyFnTable
_0807B3FC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807B402:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807b408
FUN_0807b408: @ 0x0807B408
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807B418
	cmp r5, #1
	beq _0807B434
	b _0807B48E
_0807B418:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807B47C @ =0x0836782C
	bl SetDDP
	strb r5, [r4, #0x12]
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807B434:
	ldrb r0, [r4, #0x12]
	adds r0, #6
	strb r0, [r4, #0x12]
	ldr r1, _0807B480 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bge _0807B44C
	adds r1, #3
_0807B44C:
	asrs r1, r1, #2
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x60
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807B488
	ldr r1, _0807B484 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldrb r0, [r4, #0x10]
	strb r0, [r4, #0xd]
	b _0807B48E
	.align 2, 0
_0807B47C: .4byte 0x0836782C
_0807B480: .4byte gSineTable
_0807B484: .4byte gEnemyFnTable
_0807B488:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807B48E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807b494
FUN_0807b494: @ 0x0807B494
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _0807B4A4
	cmp r4, #1
	beq _0807B51E
	b _0807B5B2
_0807B4A4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080bea24
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r4, _0807B598 @ =pZero2
	ldr r0, [r4]
	movs r1, #0x18
	bl makeZeroSlower
	movs r0, #0x80
	strb r0, [r5, #0x12]
	movs r0, #0x18
	str r0, [r5, #0x5c]
	ldr r0, [r4]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x64]
	ldr r0, _0807B59C @ =0xFFFFF600
	cmp r1, r0
	blt _0807B4F4
	movs r0, #0xa0
	lsls r0, r0, #4
	cmp r1, r0
	ble _0807B4F6
_0807B4F4:
	str r0, [r5, #0x64]
_0807B4F6:
	ldr r0, _0807B598 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	subs r1, r1, r0
	str r1, [r5, #0x68]
	ldr r0, _0807B5A0 @ =0xFFFFE800
	cmp r1, r0
	blt _0807B50E
	cmp r1, #0
	ble _0807B510
	movs r0, #0
_0807B50E:
	str r0, [r5, #0x68]
_0807B510:
	ldr r1, _0807B5A4 @ =0x00004003
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807B51E:
	ldr r4, _0807B598 @ =pZero2
	ldr r0, [r4]
	ldr r1, [r0, #0x54]
	ldr r2, [r5, #0x64]
	adds r1, r1, r2
	str r1, [r5, #0x54]
	ldr r1, [r0, #0x58]
	ldr r2, [r5, #0x68]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldrb r1, [r5, #0x12]
	subs r1, #1
	strb r1, [r5, #0x12]
	bl CountButtonMashing
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r5, #0x5c]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807B56E
	cmp r1, #0
	blt _0807B56E
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0807B56E
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0807B5AC
_0807B56E:
	ldr r0, _0807B598 @ =pZero2
	ldr r0, [r0]
	movs r1, #0x18
	bl makeZeroFaster
	ldr r1, _0807B5A8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	ldrb r0, [r5, #0x10]
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	bl WormerSnowBall_Die
	b _0807B5B2
	.align 2, 0
_0807B598: .4byte pZero2
_0807B59C: .4byte 0xFFFFF600
_0807B5A0: .4byte 0xFFFFE800
_0807B5A4: .4byte 0x00004003
_0807B5A8: .4byte gEnemyFnTable
_0807B5AC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0807B5B2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807b5b8
FUN_0807b5b8: @ 0x0807B5B8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0807B5F4
	cmp r0, #1
	bgt _0807B5CC
	cmp r0, #0
	beq _0807B5D6
	b _0807B7AC
_0807B5CC:
	cmp r0, #2
	beq _0807B644
	cmp r0, #3
	beq _0807B660
	b _0807B7AC
_0807B5D6:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807B63C @ =0x0836785C
	bl SetDDP
	ldr r1, _0807B640 @ =0x00004004
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807B5F4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807B60C
	str r1, [r5, #0x60]
_0807B60C:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x68]
	adds r1, r1, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _0807B634
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807B634:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0807B7AC
	.align 2, 0
_0807B63C: .4byte 0x0836785C
_0807B640: .4byte 0x00004004
_0807B644:
	adds r0, r5, #0
	bl InitScalerotMotion1
	movs r1, #0
	movs r0, #0x80
	strb r0, [r5, #0x12]
	str r1, [r5, #0x64]
	ldr r1, _0807B71C @ =0x00004005
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807B660:
	adds r4, r5, #0
	adds r4, #0x74
	ldrb r0, [r5, #0x12]
	subs r0, #0x80
	movs r1, #0x15
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _0807B720 @ =0x0836785C
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetDDP
	ldrb r1, [r5, #0x12]
	adds r0, r1, #0
	cmp r0, #0xff
	beq _0807B68A
	adds r0, r1, #1
	strb r0, [r5, #0x12]
_0807B68A:
	ldrb r1, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r1, [r5, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x64]
	asrs r0, r0, #8
	lsls r0, r0, #1
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x30
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807B6CE
	str r1, [r5, #0x60]
_0807B6CE:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x68]
	adds r1, r1, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _0807B75E
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r2, r0, r2
	str r2, [r5, #0x58]
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _0807B724
	ldr r0, [r5, #0x54]
	subs r0, #0x30
	ldr r1, [r5, #0x68]
	adds r1, r2, r1
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	subs r2, r2, r0
	cmp r2, #0
	bge _0807B714
	adds r0, r2, #3
	asrs r2, r0, #2
_0807B714:
	ldr r0, [r5, #0x5c]
	subs r0, r0, r2
	b _0807B746
	.align 2, 0
_0807B71C: .4byte 0x00004005
_0807B720: .4byte 0x0836785C
_0807B724:
	ldr r0, [r5, #0x54]
	adds r0, #0x30
	ldr r1, [r5, #0x68]
	adds r1, r2, r1
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	subs r2, r2, r0
	cmp r2, #0
	bge _0807B742
	adds r0, r2, #3
	asrs r2, r0, #2
_0807B742:
	ldr r0, [r5, #0x5c]
	adds r0, r0, r2
_0807B746:
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x5c]
	ldr r1, _0807B7B4 @ =0xFFFFFE00
	cmp r0, r1
	bge _0807B752
	str r1, [r5, #0x5c]
_0807B752:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _0807B75E
	str r1, [r5, #0x5c]
_0807B75E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0807B7B8 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _0807B7AC
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0807B7BC @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_0807B7AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B7B4: .4byte 0xFFFFFE00
_0807B7B8: .4byte gStageRun+232
_0807B7BC: .4byte gEnemyFnTable

	thumb_func_start FUN_0807b7c0
FUN_0807b7c0: @ 0x0807B7C0
	push {r4, lr}
	adds r4, r0, #0
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
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080bea24
	ldr r1, _0807B7FC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B7FC: .4byte gEnemyFnTable

	thumb_func_start FUN_0807b800
FUN_0807b800: @ 0x0807B800
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _0807B854 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0807B858 @ =0x0000270E
	cmp r1, r0
	bhi _0807B812
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807B812:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	bl TryDropZakoDisk
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
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080bea80
	ldr r1, _0807B85C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B854: .4byte gMission
_0807B858: .4byte 0x0000270E
_0807B85C: .4byte gEnemyFnTable
