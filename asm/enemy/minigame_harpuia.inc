	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809af20
FUN_0809af20: @ 0x0809AF20
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _0809AF80 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809AF76
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809AF84 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r4, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
	strb r6, [r4, #0x11]
	str r7, [r4, #0x28]
_0809AF76:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809AF80: .4byte gZakoHeaderPtr
_0809AF84: .4byte gEnemyFnTable

	thumb_func_start FUN_0809af88
FUN_0809af88: @ 0x0809AF88
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _0809AFE8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809AFE0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809AFEC @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
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
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r6, [r3, #0x28]
_0809AFE0:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AFE8: .4byte gZakoHeaderPtr
_0809AFEC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809aff0
FUN_0809aff0: @ 0x0809AFF0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809B05C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809B052
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809B060 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
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
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r6, [r0]
	str r7, [r3, #0x28]
_0809B052:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B05C: .4byte gZakoHeaderPtr
_0809B060: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b064
FUN_0809b064: @ 0x0809B064
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809B0D0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809B0C6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809B0D4 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
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
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r6, [r0]
	str r7, [r3, #0x28]
_0809B0C6:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B0D0: .4byte gZakoHeaderPtr
_0809B0D4: .4byte gEnemyFnTable

	thumb_func_start HarpuiaMinigameEnemy_Init
HarpuiaMinigameEnemy_Init: @ 0x0809B0D8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r7, [r6, #0x10]
	cmp r7, #0
	bne _0809B160
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	movs r5, #1
	ldrb r0, [r6, #0xa]
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r6, #0
	mov r1, sp
	movs r2, #0
	bl FUN_0809af88
	str r0, [r6, #0x2c]
	ldrb r0, [r6, #0xb]
	orrs r4, r0
	strb r4, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B15C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B15C: .4byte gEnemyFnTable
_0809B160:
	cmp r7, #1
	bne _0809B1D4
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldrb r0, [r6, #0xa]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
	strb r7, [r0]
	adds r5, r6, #0
	adds r5, #0x4a
	movs r3, #0x10
	ldrb r1, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r5]
	ldrb r0, [r6, #0xb]
	orrs r2, r0
	strb r2, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B1D0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B1D0: .4byte gEnemyFnTable
_0809B1D4:
	cmp r7, #2
	bne _0809B278
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r2, #0
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B224
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B220 @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x18
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r7, [r0]
	b _0809B248
	.align 2, 0
_0809B220: .4byte 0x0836A7D0
_0809B224:
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B26C @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
_0809B248:
	ldr r0, _0809B270 @ =FUN_0809bd2c
	str r0, [r4, #0x24]
	ldr r1, _0809B274 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B26C: .4byte 0x0836A7D0
_0809B270: .4byte FUN_0809bd2c
_0809B274: .4byte gEnemyFnTable
_0809B278:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B2D4 @ =0x0836A818
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r5, [r0]
	ldr r1, _0809B2D8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #5
	strb r0, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_0809B2C6:
	adds r0, r6, #0
	bl HarpuiaMinigameEnemy_Update
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B2D4: .4byte 0x0836A818
_0809B2D8: .4byte gEnemyFnTable

	thumb_func_start HarpuiaMinigameEnemy_Update
HarpuiaMinigameEnemy_Update: @ 0x0809B2DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809B308 @ =0x0836A7A0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809B30C @ =0x0836A7B8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809B308: .4byte 0x0836A7A0
_0809B30C: .4byte 0x0836A7B8

	thumb_func_start HarpuiaMinigameEnemy_Die
HarpuiaMinigameEnemy_Die: @ 0x0809B310
	adds r3, r0, #0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0809B34C @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r3, #0x14]
	strb r2, [r3, #0xd]
	strb r2, [r3, #0xe]
	strb r2, [r3, #0xf]
	bx lr
	.align 2, 0
_0809B34C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b350
FUN_0809b350:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b354
FUN_0809b354: @ 0x0809B354
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809B380
	ldr r1, _0809B37C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _0809B400
	.align 2, 0
_0809B37C: .4byte gEnemyFnTable
_0809B380:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809B3A8
	cmp r0, #1
	bgt _0809B390
	cmp r0, #0
	beq _0809B39A
	b _0809B400
_0809B390:
	cmp r0, #2
	beq _0809B3D0
	cmp r0, #3
	beq _0809B3E0
	b _0809B400
_0809B39A:
	ldr r1, _0809B3CC @ =0x0000BF01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B3A8:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B400
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809B3FE
	.align 2, 0
_0809B3CC: .4byte 0x0000BF01
_0809B3D0:
	movs r1, #0xbf
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B3E0:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809B400
_0809B3FE:
	strb r0, [r4, #0xe]
_0809B400:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809b408
FUN_0809b408:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b40c
FUN_0809b40c:
	bx lr

	thumb_func_start FUN_0809b410
FUN_0809b410:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b414
FUN_0809b414:
	bx lr

	thumb_func_start FUN_0809b418
FUN_0809b418:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b41c
FUN_0809b41c: @ 0x0809B41C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809B448
	ldr r1, _0809B444 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _0809B4CC
	.align 2, 0
_0809B444: .4byte gEnemyFnTable
_0809B448:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809B470
	cmp r0, #1
	bgt _0809B458
	cmp r0, #0
	beq _0809B462
	b _0809B4CC
_0809B458:
	cmp r0, #2
	beq _0809B49C
	cmp r0, #3
	beq _0809B4AA
	b _0809B4CC
_0809B462:
	ldr r1, _0809B498 @ =0x0000BF02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B470:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B4CC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809B4CA
	.align 2, 0
_0809B498: .4byte 0x0000BF02
_0809B49C:
	ldr r1, _0809B4D4 @ =0x0000BF03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B4AA:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809B4CC
_0809B4CA:
	strb r0, [r4, #0xe]
_0809B4CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809B4D4: .4byte 0x0000BF03

	thumb_func_start FUN_0809b4d8
FUN_0809b4d8: @ 0x0809B4D8
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b4dc
FUN_0809b4dc: @ 0x0809B4DC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0809B5D8
	adds r2, r5, #0
	adds r2, #0xb6
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809B512
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r6, r5, #0
	adds r6, #0xb4
	cmp r0, #2
	beq _0809B552
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldrh r2, [r1, #0x38]
	adds r0, r0, r2
	b _0809B52C
_0809B512:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #1
	bne _0809B53C
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #5
_0809B52C:
	strh r0, [r1, #0x38]
	ldr r0, _0809B538 @ =0x00000137
	bl PlaySound
	b _0809B552
	.align 2, 0
_0809B538: .4byte 0x00000137
_0809B53C:
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #1
	strh r0, [r1, #0x38]
	ldr r0, _0809B5BC @ =0x00000137
	bl PlaySound
_0809B552:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0809B5C0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B5C4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r3, _0809B5C8 @ =0x00269EC3
	adds r4, r4, r3
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5CC @ =0x00004707
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D0 @ =0x00004708
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D4 @ =0x00004709
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	b _0809B924
	.align 2, 0
_0809B5BC: .4byte 0x00000137
_0809B5C0: .4byte RNG_0202f388
_0809B5C4: .4byte 0x000343FD
_0809B5C8: .4byte 0x00269EC3
_0809B5CC: .4byte 0x00004707
_0809B5D0: .4byte 0x00004708
_0809B5D4: .4byte 0x00004709
_0809B5D8:
	adds r0, r5, #0
	adds r0, #0xb5
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _0809B5F8
	movs r1, #1
	ands r2, r1
	cmp r2, #0
	beq _0809B5F8
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _0809B5F8
	strb r1, [r3]
	movs r0, #0xa
	strb r0, [r5, #0xe]
_0809B5F8:
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _0809B600
	b _0809B936
_0809B600:
	lsls r0, r0, #2
	ldr r1, _0809B60C @ =_0809B610
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B60C: .4byte _0809B610
_0809B610: @ jump table
	.4byte _0809B640 @ case 0
	.4byte _0809B6B6 @ case 1
	.4byte _0809B6F6 @ case 2
	.4byte _0809B700 @ case 3
	.4byte _0809B936 @ case 4
	.4byte _0809B73E @ case 5
	.4byte _0809B7F2 @ case 6
	.4byte _0809B936 @ case 7
	.4byte _0809B936 @ case 8
	.4byte _0809B936 @ case 9
	.4byte _0809B818 @ case 10
	.4byte _0809B8C0 @ case 11
_0809B640:
	movs r4, #0
	str r4, [r5, #0x2c]
	strb r4, [r3]
	adds r0, r5, #0
	adds r0, #0xb6
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r1, _0809B688 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0809B68C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0809B690
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
	b _0809B6AC
	.align 2, 0
_0809B688: .4byte 0x00004703
_0809B68C: .4byte pZero2
_0809B690:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0809B6AC:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B6B6:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B6EE
	b _0809B936
_0809B6EE:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809B936
_0809B6F6:
	movs r0, #0x30
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B700:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B738
	b _0809B936
_0809B738:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0809B936
_0809B73E:
	movs r0, #0
	str r0, [r5, #0x2c]
	strb r0, [r3]
	ldr r1, _0809B7A0 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r6, _0809B7A4 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B7A8
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B7C4
	.align 2, 0
_0809B7A0: .4byte 0x00004703
_0809B7A4: .4byte pZero2
_0809B7A8:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B7BC
	ldr r0, _0809B7B8 @ =0xFFFFFF00
	b _0809B7C0
	.align 2, 0
_0809B7B8: .4byte 0xFFFFFF00
_0809B7BC:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B7C0:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B7C4:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B7F2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B816
	b _0809B936
_0809B816:
	b _0809B924
_0809B818:
	ldr r6, _0809B86C @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B870
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B88C
	.align 2, 0
_0809B86C: .4byte pZero2
_0809B870:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B884
	ldr r0, _0809B880 @ =0xFFFFFF00
	b _0809B888
	.align 2, 0
_0809B880: .4byte 0xFFFFFF00
_0809B884:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B888:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B88C:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	ldr r1, _0809B940 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809B944 @ =0x0836A800
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B8C0:
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r3, [r5, #0x60]
	adds r0, r0, r3
	str r0, [r5, #0x58]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x5c]
	rsbs r1, r3, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809B936
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B914
	ldrh r0, [r1, #0x38]
	adds r0, #5
	strh r0, [r1, #0x38]
	ldr r0, _0809B948 @ =0x00000137
	bl PlaySound
_0809B914:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
_0809B924:
	ldr r1, _0809B94C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809B936:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B940: .4byte 0x00004703
_0809B944: .4byte 0x0836A800
_0809B948: .4byte 0x00000137
_0809B94C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b950
FUN_0809b950: @ 0x0809B950
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b954
FUN_0809b954: @ 0x0809B954
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809BA0C
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	ldr r2, _0809B9F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B9F4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0809B9F8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldr r2, _0809B9FC @ =0x00004707
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA00 @ =0x00004708
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA04 @ =0x00004709
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _0809BA08 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl HarpuiaMinigameEnemy_Die
	b _0809BD16
	.align 2, 0
_0809B9F0: .4byte RNG_0202f388
_0809B9F4: .4byte 0x000343FD
_0809B9F8: .4byte 0x00269EC3
_0809B9FC: .4byte 0x00004707
_0809BA00: .4byte 0x00004708
_0809BA04: .4byte 0x00004709
_0809BA08: .4byte gEnemyFnTable
_0809BA0C:
	ldrb r0, [r7, #0xe]
	cmp r0, #6
	bls _0809BA14
	b _0809BD16
_0809BA14:
	lsls r0, r0, #2
	ldr r1, _0809BA20 @ =_0809BA24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809BA20: .4byte _0809BA24
_0809BA24: @ jump table
	.4byte _0809BA40 @ case 0
	.4byte _0809BAFC @ case 1
	.4byte _0809BBD0 @ case 2
	.4byte _0809BBDA @ case 3
	.4byte _0809BD16 @ case 4
	.4byte _0809BC08 @ case 5
	.4byte _0809BCD2 @ case 6
_0809BA40:
	ldr r1, _0809BA80 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	ldr r0, _0809BA84 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0809BA88
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _0809BAA6
	.align 2, 0
_0809BA80: .4byte 0x00004703
_0809BA84: .4byte pZero2
_0809BA88:
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0809BAA6:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	movs r0, #4
	strb r0, [r7, #0x13]
	ldr r4, _0809BB44 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _0809BB48 @ =0x000343FD
	mov r8, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r6, _0809BB4C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BAFC:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BB18
	ldr r0, [r7, #0x54]
	ldr r1, _0809BB50 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x64]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x5c]
_0809BB18:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0809BB28
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BBAC
_0809BB28:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _0809BB3C
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BB54
_0809BB3C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BBC8
	.align 2, 0
_0809BB44: .4byte RNG_0202f388
_0809BB48: .4byte 0x000343FD
_0809BB4C: .4byte 0x00269EC3
_0809BB50: .4byte 0xFFFC4000
_0809BB54:
	ldr r4, _0809BBA0 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _0809BBA4 @ =0x000343FD
	mov r8, r3
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _0809BBA8 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x64]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	b _0809BBC8
	.align 2, 0
_0809BBA0: .4byte RNG_0202f388
_0809BBA4: .4byte 0x000343FD
_0809BBA8: .4byte 0x00269EC3
_0809BBAC:
	ldr r0, [r7, #0x5c]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
_0809BBC8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _0809BD16
_0809BBD0:
	movs r0, #7
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BBDA:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BBEA
	ldr r0, [r7, #0x54]
	ldr r2, _0809BC04 @ =0xFFFC4000
	adds r0, r0, r2
	str r0, [r7, #0x54]
_0809BBEA:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809BBFE
	b _0809BD16
_0809BBFE:
	movs r0, #5
	strb r0, [r7, #0xe]
	b _0809BD16
	.align 2, 0
_0809BC04: .4byte 0xFFFC4000
_0809BC08:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BC18
	ldr r0, [r7, #0x54]
	ldr r3, _0809BC74 @ =0xFFFC4000
	adds r0, r0, r3
	str r0, [r7, #0x54]
_0809BC18:
	ldr r1, _0809BC78 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r5, _0809BC7C @ =pZero2
	ldr r2, [r5]
	ldr r0, [r7, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, [r7, #0x58]
	movs r3, #0xd8
	lsls r3, r3, #6
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r7, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809BC80
	ldr r0, [r7, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x68]
	b _0809BC9C
	.align 2, 0
_0809BC74: .4byte 0xFFFC4000
_0809BC78: .4byte 0x00004703
_0809BC7C: .4byte pZero2
_0809BC80:
	ldr r0, [r5]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809BC94
	ldr r0, _0809BC90 @ =0xFFFFFF00
	b _0809BC98
	.align 2, 0
_0809BC90: .4byte 0xFFFFFF00
_0809BC94:
	movs r0, #0x80
	lsls r0, r0, #1
_0809BC98:
	str r0, [r7, #0x64]
	str r4, [r7, #0x68]
_0809BC9C:
	ldr r1, [r7, #0x64]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r1, [r7, #0x68]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BD16
_0809BCD2:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BCE2
	ldr r0, [r7, #0x54]
	ldr r1, _0809BD24 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
_0809BCE2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BD16
	ldr r1, _0809BD28 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_0809BD16:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809BD24: .4byte 0xFFFC4000
_0809BD28: .4byte gEnemyFnTable

	thumb_func_start FUN_0809bd2c
FUN_0809bd2c: @ 0x0809BD2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0xc]
	ldr r3, [r2, #4]
	ldr r0, [r4, #0x2c]
	mov ip, r0
	ldr r0, [r3, #4]
	ldr r1, _0809BD58 @ =0x00FF00FF
	ands r0, r1
	ldr r1, _0809BD5C @ =0x00020002
	cmp r0, r1
	bne _0809BD60
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD94
	ldr r0, [r2, #0x2c]
	mov r1, ip
	str r0, [r1, #0x2c]
	b _0809BD94
	.align 2, 0
_0809BD58: .4byte 0x00FF00FF
_0809BD5C: .4byte 0x00020002
_0809BD60:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BD94
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD8C
	mov r1, ip
	adds r1, #0xa4
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0x10
	bgt _0809BD94
	adds r0, r2, #0
	adds r0, #8
	strh r0, [r1]
	b _0809BD94
_0809BD8C:
	mov r1, ip
	adds r1, #0xb6
	movs r0, #1
	strb r0, [r1]
_0809BD94:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BDCC
	ldr r0, [r4, #0xc]
	ldr r3, [r0, #0x2c]
	adds r0, r3, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	beq _0809BDCC
	ldr r0, [r4, #4]
	ldrb r2, [r0, #1]
	cmp r2, #2
	bne _0809BDCC
	mov r1, ip
	adds r1, #0xb7
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809BDC8
	adds r0, r3, #0
	adds r0, #0xb6
	strb r2, [r0]
	b _0809BDCC
_0809BDC8:
	adds r0, #1
	strb r0, [r1]
_0809BDCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
