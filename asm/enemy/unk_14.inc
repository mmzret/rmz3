	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Enemy14_Init
Enemy14_Init: @ 0x0806F430
	push {lr}
	ldr r2, _0806F444 @ =0x08366950
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0806F444: .4byte 0x08366950

	thumb_func_start Enemy14_Update
Enemy14_Update: @ 0x0806F448
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x11]
	cmp r0, #2
	beq _0806F47C
	ldr r0, _0806F474 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0806F494
	ldr r1, _0806F478 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _0806F58E
	.align 2, 0
_0806F474: .4byte gCurStory
_0806F478: .4byte gEnemyFnTable
_0806F47C:
	ldr r0, _0806F4B4 @ =pZero2
	ldr r0, [r0]
	cmp r0, #0
	beq _0806F494
	ldr r1, _0806F4B8 @ =0x00000216
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0806F58E
_0806F494:
	adds r0, r5, #0
	adds r0, #0xc2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806F4C0
	ldr r1, _0806F4BC @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _0806F58E
	.align 2, 0
_0806F4B4: .4byte pZero2
_0806F4B8: .4byte 0x00000216
_0806F4BC: .4byte gEnemyFnTable
_0806F4C0:
	ldrb r1, [r5, #0x1e]
	lsls r1, r1, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r0, _0806F564 @ =0x00001503
	adds r6, r5, #0
	adds r6, #0xbc
	cmp r1, r0
	beq _0806F51C
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806F51C
	ldr r0, [r6]
	cmp r0, #0
	bne _0806F522
	ldrb r2, [r5, #0x10]
	lsls r2, r2, #3
	ldr r0, _0806F568 @ =0x083669D0
	adds r2, r2, r0
	movs r0, #0
	adds r1, r5, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0806F574
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r1, [r5, #0x10]
	movs r2, #2
	ands r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0806F56C @ =0x08366988
	adds r1, r1, r2
	bl SetDDP
_0806F51C:
	ldr r0, [r6]
	cmp r0, #0
	beq _0806F574
_0806F522:
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r6]
	bl isKilled
	cmp r0, #0
	beq _0806F58E
	movs r4, #0
	str r4, [r6]
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r1, [r5, #0x10]
	movs r2, #2
	ands r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0806F570 @ =0x08366970
	adds r1, r1, r2
	bl SetDDP
	strb r4, [r5, #0xd]
	strb r4, [r5, #0xe]
	b _0806F58E
	.align 2, 0
_0806F564: .4byte 0x00001503
_0806F568: .4byte 0x083669D0
_0806F56C: .4byte 0x08366988
_0806F570: .4byte 0x08366970
_0806F574:
	adds r0, r5, #0
	bl isFrozen
	cmp r0, #0
	bne _0806F58E
	ldr r0, _0806F594 @ =0x08366960
	ldrb r1, [r5, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
_0806F58E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806F594: .4byte 0x08366960

	thumb_func_start Enemy14_Die
Enemy14_Die: @ 0x0806F598
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806F5CC @ =gEnemyFnTable
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
_0806F5CC: .4byte gEnemyFnTable

	thumb_func_start FUN_0806f5d0
FUN_0806f5d0: @ 0x0806F5D0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r6, #0
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0806F654 @ =0x08366970
	adds r2, r5, #0
	adds r2, #0x54
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r4, #0
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0806F658 @ =FUN_08070000
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	ldr r0, _0806F65C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0806F660
	movs r0, #0x80
	str r0, [r5, #0x5c]
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _0806F682
	.align 2, 0
_0806F654: .4byte 0x08366970
_0806F658: .4byte FUN_08070000
_0806F65C: .4byte pZero2
_0806F660:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0806F682:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r5, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc2
	movs r1, #0
	strb r1, [r0]
	strb r1, [r5, #0x12]
	ldr r2, _0806F6C8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r2, #1
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r1, [r5, #0xd]
	strb r2, [r5, #0xe]
	adds r0, r5, #0
	bl Enemy14_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F6C8: .4byte gEnemyFnTable

	thumb_func_start FUN_0806f6cc
FUN_0806f6cc: @ 0x0806F6CC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r6, #0
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0806F76C @ =0x08366970
	adds r2, r5, #0
	adds r2, #0x54
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r4, #0
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0806F770 @ =FUN_08070000
	str r0, [r4, #0x24]
	movs r4, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	ldr r0, _0806F774 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0806F778
	movs r0, #0x80
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	b _0806F794
	.align 2, 0
_0806F76C: .4byte 0x08366970
_0806F770: .4byte FUN_08070000
_0806F774: .4byte pZero2
_0806F778:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r7, [r0]
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_0806F794:
	strb r0, [r3]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a134
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r5, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc2
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0806F7D8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r2, [r5, #0xd]
	strb r1, [r5, #0xe]
	adds r0, r5, #0
	bl Enemy14_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F7D8: .4byte gEnemyFnTable

	thumb_func_start FUN_0806f7dc
FUN_0806f7dc: @ 0x0806F7DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806F890 @ =0x083669A0
	adds r2, r6, #0
	adds r2, #0x54
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r4, #0
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _0806F894 @ =FUN_08070000
	str r0, [r4, #0x24]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r4, #1
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xbc
	str r5, [r0]
	movs r0, #0x80
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb4
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc2
	strb r5, [r0]
	ldr r1, _0806F898 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	strb r4, [r6, #0xe]
	adds r0, r6, #0
	bl Enemy14_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806F890: .4byte 0x083669A0
_0806F894: .4byte FUN_08070000
_0806F898: .4byte gEnemyFnTable

	thumb_func_start FUN_0806f89c
FUN_0806f89c: @ 0x0806F89C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806F958 @ =0x083669A0
	adds r2, r6, #0
	adds r2, #0x54
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r4, #0
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _0806F95C @ =FUN_08070000
	str r0, [r4, #0x24]
	movs r4, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xbc
	str r5, [r0]
	movs r0, #0x80
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb4
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc2
	strb r5, [r0]
	strb r5, [r6, #0x12]
	ldr r1, _0806F960 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	strb r4, [r6, #0xe]
	adds r0, r6, #0
	bl Enemy14_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806F958: .4byte 0x083669A0
_0806F95C: .4byte FUN_08070000
_0806F960: .4byte gEnemyFnTable

	thumb_func_start FUN_0806f964
FUN_0806f964: @ 0x0806F964
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _0806F9C0
	cmp r0, #1
	bgt _0806F978
	cmp r0, #0
	beq _0806F97E
	b _0806FA38
_0806F978:
	cmp r0, #2
	beq _0806FA0C
	b _0806FA38
_0806F97E:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806F9A4
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0806F998
	movs r0, #0x80
	b _0806F99C
_0806F998:
	movs r0, #0x80
	rsbs r0, r0, #0
_0806F99C:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806F9A4:
	ldr r1, [r4, #0x58]
	asrs r1, r1, #8
	ldr r0, _0806F9BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	asrs r0, r0, #8
	cmp r1, r0
	bne _0806FA38
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	b _0806FA36
	.align 2, 0
_0806F9BC: .4byte pZero2
_0806F9C0:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806F9EA
	ldr r1, _0806F9DC @ =0x00001501
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0806F9E0
	movs r0, #0xa0
	lsls r0, r0, #2
	b _0806F9E2
	.align 2, 0
_0806F9DC: .4byte 0x00001501
_0806F9E0:
	ldr r0, _0806FA04 @ =0xFFFFFD80
_0806F9E2:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806F9EA:
	ldr r1, [r4, #0x58]
	asrs r1, r1, #8
	ldr r0, _0806FA08 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	asrs r0, r0, #8
	cmp r1, r0
	beq _0806FA38
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0806FA38
	.align 2, 0
_0806FA04: .4byte 0xFFFFFD80
_0806FA08: .4byte pZero2
_0806FA0C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FA24
	ldr r1, _0806FA74 @ =0x00001503
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FA24:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0806FA38
	strb r1, [r4, #0xd]
_0806FA36:
	strb r1, [r4, #0xe]
_0806FA38:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	beq _0806FB02
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldrb r0, [r4, #0x11]
	cmp r0, #2
	bne _0806FA88
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl FUN_0800a05c
	adds r1, r0, #0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0806FA78
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r0, r2
	bl FUN_0800a05c
	b _0806FAAC
	.align 2, 0
_0806FA74: .4byte 0x00001503
_0806FA78:
	ldr r0, [r4, #0x54]
	ldr r2, _0806FA84 @ =0xFFFFF600
	adds r0, r0, r2
	bl FUN_0800a05c
	b _0806FAAC
	.align 2, 0
_0806FA84: .4byte 0xFFFFF600
_0806FA88:
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0806FAA2
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	b _0806FAA6
_0806FAA2:
	ldr r0, [r4, #0x54]
	ldr r2, _0806FAC4 @ =0xFFFFF600
_0806FAA6:
	adds r0, r0, r2
	bl FUN_08009f6c
_0806FAAC:
	ldr r1, [r4, #0x58]
	subs r1, r1, r0
	cmp r1, #0
	bge _0806FAB6
	rsbs r1, r1, #0
_0806FAB6:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _0806FAC8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	b _0806FB00
	.align 2, 0
_0806FAC4: .4byte 0xFFFFF600
_0806FAC8:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _0806FB02
	ldr r2, [r4, #0x5c]
	cmp r2, #0
	ble _0806FAEC
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	ldr r1, _0806FAE8 @ =0xFFFFD000
	cmp r0, r1
	bge _0806FB02
	b _0806FAFE
	.align 2, 0
_0806FAE8: .4byte 0xFFFFD000
_0806FAEC:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0806FB02
_0806FAFE:
	rsbs r0, r2, #0
_0806FB00:
	str r0, [r4, #0x5c]
_0806FB02:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806fb08
FUN_0806fb08: @ 0x0806FB08
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x58]
	movs r0, #0xa0
	lsls r0, r0, #6
	adds r1, r1, r0
	ldr r0, _0806FB2C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	subs r5, r1, r0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _0806FB78
	cmp r0, #1
	bgt _0806FB30
	cmp r0, #0
	beq _0806FB36
	b _0806FBEC
	.align 2, 0
_0806FB2C: .4byte pZero2
_0806FB30:
	cmp r0, #2
	beq _0806FBC0
	b _0806FBEC
_0806FB36:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FB5C
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0806FB50
	movs r0, #0x80
	b _0806FB54
_0806FB50:
	movs r0, #0x80
	rsbs r0, r0, #0
_0806FB54:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FB5C:
	adds r1, r5, #0
	cmp r5, #0
	bge _0806FB64
	rsbs r1, r5, #0
_0806FB64:
	ldr r0, _0806FB74 @ =0x000003FF
	cmp r1, r0
	bgt _0806FBEC
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	b _0806FBEA
	.align 2, 0
_0806FB74: .4byte 0x000003FF
_0806FB78:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FBA2
	ldr r1, _0806FB94 @ =0x00001501
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0806FB98
	movs r0, #0xa0
	lsls r0, r0, #2
	b _0806FB9A
	.align 2, 0
_0806FB94: .4byte 0x00001501
_0806FB98:
	ldr r0, _0806FBB8 @ =0xFFFFFD80
_0806FB9A:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FBA2:
	adds r1, r5, #0
	cmp r5, #0
	bge _0806FBAA
	rsbs r1, r5, #0
_0806FBAA:
	ldr r0, _0806FBBC @ =0x000003FF
	cmp r1, r0
	ble _0806FBEC
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0806FBEC
	.align 2, 0
_0806FBB8: .4byte 0xFFFFFD80
_0806FBBC: .4byte 0x000003FF
_0806FBC0:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FBD8
	ldr r1, _0806FC0C @ =0x00001503
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FBD8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0806FBEC
	strb r1, [r4, #0xd]
_0806FBEA:
	strb r1, [r4, #0xe]
_0806FBEC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	beq _0806FC72
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0806FC10
	movs r1, #0xa0
	lsls r1, r1, #4
	b _0806FC12
	.align 2, 0
_0806FC0C: .4byte 0x00001503
_0806FC10:
	ldr r1, _0806FC34 @ =0xFFFFF600
_0806FC12:
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_0800a134
	ldr r1, [r4, #0x58]
	subs r5, r1, r0
	adds r1, r5, #0
	cmp r1, #0
	bge _0806FC26
	rsbs r1, r1, #0
_0806FC26:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _0806FC38
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	b _0806FC70
	.align 2, 0
_0806FC34: .4byte 0xFFFFF600
_0806FC38:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _0806FC72
	ldr r2, [r4, #0x5c]
	cmp r2, #0
	ble _0806FC5C
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	ldr r1, _0806FC58 @ =0xFFFFD000
	cmp r0, r1
	bge _0806FC72
	b _0806FC6E
	.align 2, 0
_0806FC58: .4byte 0xFFFFD000
_0806FC5C:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0806FC72
_0806FC6E:
	rsbs r0, r2, #0
_0806FC70:
	str r0, [r4, #0x5c]
_0806FC72:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806fc78
FUN_0806fc78: @ 0x0806FC78
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0806FC98 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r5, r1, r0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _0806FCE4
	cmp r0, #1
	bgt _0806FC9C
	cmp r0, #0
	beq _0806FCA2
	b _0806FD58
	.align 2, 0
_0806FC98: .4byte pZero2
_0806FC9C:
	cmp r0, #2
	beq _0806FD2C
	b _0806FD58
_0806FCA2:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FCC8
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0806FCBC
	movs r0, #0x80
	b _0806FCC0
_0806FCBC:
	movs r0, #0x80
	rsbs r0, r0, #0
_0806FCC0:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FCC8:
	adds r1, r5, #0
	cmp r5, #0
	bge _0806FCD0
	rsbs r1, r5, #0
_0806FCD0:
	ldr r0, _0806FCE0 @ =0x00000FFF
	cmp r1, r0
	bgt _0806FD58
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	b _0806FD56
	.align 2, 0
_0806FCE0: .4byte 0x00000FFF
_0806FCE4:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FD0E
	ldr r1, _0806FD00 @ =0x00001501
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0806FD04
	movs r0, #0xa0
	lsls r0, r0, #2
	b _0806FD06
	.align 2, 0
_0806FD00: .4byte 0x00001501
_0806FD04:
	ldr r0, _0806FD24 @ =0xFFFFFD80
_0806FD06:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FD0E:
	adds r1, r5, #0
	cmp r5, #0
	bge _0806FD16
	rsbs r1, r5, #0
_0806FD16:
	ldr r0, _0806FD28 @ =0x00000FFF
	cmp r1, r0
	ble _0806FD58
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0806FD58
	.align 2, 0
_0806FD24: .4byte 0xFFFFFD80
_0806FD28: .4byte 0x00000FFF
_0806FD2C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FD44
	ldr r1, _0806FD94 @ =0x00001503
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FD44:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0806FD58
	strb r1, [r4, #0xd]
_0806FD56:
	strb r1, [r4, #0xe]
_0806FD58:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	beq _0806FE32
	movs r5, #0
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r2, r0, r1
	str r2, [r4, #0x58]
	cmp r1, #0
	ble _0806FD98
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r1, r2, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806FDAA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _0806FDD4
	.align 2, 0
_0806FD94: .4byte 0x00001503
_0806FD98:
	ldrb r0, [r4, #0x11]
	cmp r0, #2
	bne _0806FDB8
	ldr r0, _0806FDB0 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r3, _0806FDB4 @ =0xFFFFB000
	adds r0, r0, r3
	cmp r2, r0
	bge _0806FDDE
_0806FDAA:
	movs r5, #0x80
	lsls r5, r5, #5
	b _0806FDDE
	.align 2, 0
_0806FDB0: .4byte gStageRun+232
_0806FDB4: .4byte 0xFFFFB000
_0806FDB8:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, _0806FDF4 @ =0xFFFFF400
	adds r1, r2, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806FDAA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0806FDF4 @ =0xFFFFF400
_0806FDD4:
	adds r1, r1, r2
	bl FUN_0800a31c
	ldr r1, [r4, #0x54]
	subs r5, r1, r0
_0806FDDE:
	adds r1, r5, #0
	cmp r1, #0
	bge _0806FDE6
	rsbs r1, r1, #0
_0806FDE6:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _0806FDF8
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
	b _0806FE30
	.align 2, 0
_0806FDF4: .4byte 0xFFFFF400
_0806FDF8:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _0806FE32
	ldr r2, [r4, #0x60]
	cmp r2, #0
	ble _0806FE1C
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _0806FE18 @ =0xFFFFD000
	cmp r0, r1
	bge _0806FE32
	b _0806FE2E
	.align 2, 0
_0806FE18: .4byte 0xFFFFD000
_0806FE1C:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0806FE32
_0806FE2E:
	rsbs r0, r2, #0
_0806FE30:
	str r0, [r4, #0x60]
_0806FE32:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806fe38
FUN_0806fe38: @ 0x0806FE38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0806FE58 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r5, r1, r0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _0806FEA4
	cmp r0, #1
	bgt _0806FE5C
	cmp r0, #0
	beq _0806FE62
	b _0806FF18
	.align 2, 0
_0806FE58: .4byte pZero2
_0806FE5C:
	cmp r0, #2
	beq _0806FEEC
	b _0806FF18
_0806FE62:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FE88
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0806FE7C
	movs r0, #0x80
	b _0806FE80
_0806FE7C:
	movs r0, #0x80
	rsbs r0, r0, #0
_0806FE80:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FE88:
	adds r1, r5, #0
	cmp r5, #0
	bge _0806FE90
	rsbs r1, r5, #0
_0806FE90:
	ldr r0, _0806FEA0 @ =0x00000FFF
	cmp r1, r0
	bgt _0806FF18
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	b _0806FF16
	.align 2, 0
_0806FEA0: .4byte 0x00000FFF
_0806FEA4:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FECE
	ldr r1, _0806FEC0 @ =0x00001501
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0806FEC4
	movs r0, #0xa0
	lsls r0, r0, #2
	b _0806FEC6
	.align 2, 0
_0806FEC0: .4byte 0x00001501
_0806FEC4:
	ldr r0, _0806FEE4 @ =0xFFFFFD80
_0806FEC6:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FECE:
	adds r1, r5, #0
	cmp r5, #0
	bge _0806FED6
	rsbs r1, r5, #0
_0806FED6:
	ldr r0, _0806FEE8 @ =0x00000FFF
	cmp r1, r0
	ble _0806FF18
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0806FF18
	.align 2, 0
_0806FEE4: .4byte 0xFFFFFD80
_0806FEE8: .4byte 0x00000FFF
_0806FEEC:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806FF04
	ldr r1, _0806FF54 @ =0x00001503
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806FF04:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0806FF18
	strb r1, [r4, #0xd]
_0806FF16:
	strb r1, [r4, #0xe]
_0806FF18:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	beq _0806FFFA
	movs r5, #0
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r2, r0, r1
	str r2, [r4, #0x58]
	cmp r1, #0
	ble _0806FF5C
	ldr r0, [r4, #0x54]
	ldr r1, _0806FF58 @ =0xFFFFFF00
	adds r0, r0, r1
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r1, r2, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806FF6E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _0806FF96
	.align 2, 0
_0806FF54: .4byte 0x00001503
_0806FF58: .4byte 0xFFFFFF00
_0806FF5C:
	ldrb r0, [r4, #0x11]
	cmp r0, #2
	bne _0806FF7C
	ldr r0, _0806FF74 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r3, _0806FF78 @ =0xFFFFB000
	adds r0, r0, r3
	cmp r2, r0
	bge _0806FFA0
_0806FF6E:
	movs r5, #0x80
	lsls r5, r5, #5
	b _0806FFA0
	.align 2, 0
_0806FF74: .4byte gStageRun+232
_0806FF78: .4byte 0xFFFFB000
_0806FF7C:
	ldr r0, [r4, #0x54]
	ldr r1, _0806FFB8 @ =0xFFFFFF00
	adds r0, r0, r1
	ldr r3, _0806FFBC @ =0xFFFFF400
	adds r1, r2, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806FF6E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0806FFBC @ =0xFFFFF400
_0806FF96:
	adds r1, r1, r2
	bl FUN_0800a22c
	ldr r1, [r4, #0x54]
	subs r5, r1, r0
_0806FFA0:
	adds r1, r5, #0
	cmp r1, #0
	bge _0806FFA8
	rsbs r1, r1, #0
_0806FFA8:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _0806FFC0
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
	b _0806FFF8
	.align 2, 0
_0806FFB8: .4byte 0xFFFFFF00
_0806FFBC: .4byte 0xFFFFF400
_0806FFC0:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _0806FFFA
	ldr r2, [r4, #0x60]
	cmp r2, #0
	ble _0806FFE4
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _0806FFE0 @ =0xFFFFD000
	cmp r0, r1
	bge _0806FFFA
	b _0806FFF6
	.align 2, 0
_0806FFE0: .4byte 0xFFFFD000
_0806FFE4:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0806FFFA
_0806FFF6:
	rsbs r0, r2, #0
_0806FFF8:
	str r0, [r4, #0x60]
_0806FFFA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08070000
FUN_08070000: @ 0x08070000
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #9
	ands r0, r1
	cmp r0, #0
	beq _08070024
	ldr r2, [r2, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #2
	beq _08070020
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
	b _08070024
_08070020:
	movs r0, #0x40
	strb r0, [r2, #0x12]
_08070024:
	pop {r0}
	bx r0
