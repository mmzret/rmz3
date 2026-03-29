	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099f54
FUN_08099f54: @ 0x08099F54
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08099FB0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08099FA8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08099FB4 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
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
	movs r0, #6
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x68]
	str r7, [r3, #0x5c]
_08099FA8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099FB0: .4byte gZakoHeaderPtr
_08099FB4: .4byte gEnemyFnTable

	thumb_func_start FUN_08099fb8
FUN_08099fb8: @ 0x08099FB8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0809A024 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809A01E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A028 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
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
	strb r5, [r3, #0x10]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	subs r0, r0, r4
	lsls r0, r0, #0xc
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
	str r7, [r3, #0x28]
_0809A01E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A024: .4byte gZakoHeaderPtr
_0809A028: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a02c
FUN_0809a02c: @ 0x0809A02C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _0809A0A8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809A0A0
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A0AC @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r4, #9]
	adds r1, #0xcc
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #4
	strb r0, [r4, #0x10]
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r4, #0x54]
	movs r1, #0x82
	lsls r1, r1, #0xb
	str r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x54]
	ldr r0, _0809A0B0 @ =0xFFFF6800
	adds r1, r1, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	subs r0, r0, r5
	lsls r0, r0, #0xc
	adds r1, r1, r0
	str r1, [r4, #0x54]
	strb r5, [r4, #0x12]
	str r6, [r4, #0x28]
_0809A0A0:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809A0A8: .4byte gZakoHeaderPtr
_0809A0AC: .4byte gEnemyFnTable
_0809A0B0: .4byte 0xFFFF6800

	thumb_func_start nop_0809a0b4
nop_0809a0b4: @ 0x0809A0B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809a0b8
FUN_0809a0b8: @ 0x0809A0B8
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0809A0CE
	movs r0, #0
	b _0809A0FA
_0809A0CE:
	ldr r0, [r2, #0x28]
	adds r0, #0x31
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, _0809A100 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, _0809A104 @ =0x0836A764
	ldrb r0, [r2, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl LeviathanMinigameEnemy_Die
	movs r0, #1
_0809A0FA:
	pop {r1}
	bx r1
	.align 2, 0
_0809A100: .4byte gEnemyFnTable
_0809A104: .4byte 0x0836A764

	thumb_func_start LeviathanMinigameEnemy_Init
LeviathanMinigameEnemy_Init: @ 0x0809A108
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0809A184 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0809A188 @ =0x0836A76A
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
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
	cmp r0, #6
	beq _0809A152
	ldr r0, _0809A18C @ =0x0836A772
	ldrb r1, [r5, #0x10]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r5, #0
	bl SetMotion
_0809A152:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809A190 @ =0x0836A6D4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0809A194 @ =nop_0809a0b4
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl LeviathanMinigameEnemy_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A184: .4byte gEnemyFnTable
_0809A188: .4byte 0x0836A76A
_0809A18C: .4byte 0x0836A772
_0809A190: .4byte 0x0836A6D4
_0809A194: .4byte nop_0809a0b4

	thumb_func_start LeviathanMinigameEnemy_Update
LeviathanMinigameEnemy_Update: @ 0x0809A198
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809a0b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A1C6
	ldr r1, _0809A1CC @ =0x0836A68C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809A1D0 @ =0x0836A6A8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0809A1C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A1CC: .4byte 0x0836A68C
_0809A1D0: .4byte 0x0836A6A8

	thumb_func_start LeviathanMinigameEnemy_Die
LeviathanMinigameEnemy_Die: @ 0x0809A1D4
	push {lr}
	ldr r2, _0809A1E8 @ =0x0836A6C4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809A1E8: .4byte 0x0836A6C4

	thumb_func_start nop_0809a1ec
nop_0809a1ec: @ 0x0809A1EC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809a1f0
FUN_0809a1f0: @ 0x0809A1F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A210
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809A20C @ =0x0836A6D4
	bl SetDDP
	b _0809A30A
	.align 2, 0
_0809A20C: .4byte 0x0836A6D4
_0809A210:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809A228 @ =0x0836A6EC
	bl SetDDP
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809A22C
	cmp r0, #1
	beq _0809A292
	b _0809A30A
	.align 2, 0
_0809A228: .4byte 0x0836A6EC
_0809A22C:
	adds r1, r5, #0
	adds r1, #0x22
	movs r4, #1
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x12]
	eors r4, r0
	cmp r4, #0
	beq _0809A250
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A256
_0809A250:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A256:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r4
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	movs r2, #0xb0
	lsls r2, r2, #1
	ldrb r1, [r5, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	strb r3, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809A292:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _0809A310 @ =gSineTable
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	adds r0, #4
	movs r4, #0
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, _0809A314 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A30A
	str r4, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0x32
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
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
	ldr r1, _0809A318 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_0809A30A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A310: .4byte gSineTable
_0809A314: .4byte 0xFFFF3000
_0809A318: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a31c
FUN_0809a31c: @ 0x0809A31C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A33C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A338 @ =0x0836A6D4
	bl SetDDP
	b _0809A49A
	.align 2, 0
_0809A338: .4byte 0x0836A6D4
_0809A33C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A354 @ =0x0836A704
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A358
	cmp r0, #1
	beq _0809A3BE
	b _0809A49A
	.align 2, 0
_0809A354: .4byte 0x0836A704
_0809A358:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0809A378 @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0809A37C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A382
	.align 2, 0
_0809A378: .4byte 0x00003501
_0809A37C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A382:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, _0809A4A0 @ =0xFFFFFEC0
	str r0, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A3BE:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	movs r5, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A3F2
	ldr r2, _0809A4A4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A4A8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A4AC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r4, #0x13]
	ldr r1, _0809A4B0 @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
_0809A3F2:
	ldr r1, [r4, #0x5c]
	lsls r0, r1, #7
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	bge _0809A400
	adds r0, #0xff
_0809A400:
	asrs r1, r0, #8
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809A422
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0809A422:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0809A450
	ldr r0, _0809A4A0 @ =0xFFFFFEC0
	str r0, [r4, #0x60]
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	subs r2, r2, r0
	str r2, [r4, #0x5c]
_0809A450:
	ldr r0, [r4, #0x54]
	ldr r1, _0809A4B4 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A49A
	str r5, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0x32
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A4B8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A49A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A4A0: .4byte 0xFFFFFEC0
_0809A4A4: .4byte RNG_0202f388
_0809A4A8: .4byte 0x000343FD
_0809A4AC: .4byte 0x00269EC3
_0809A4B0: .4byte 0x00003501
_0809A4B4: .4byte 0xFFFF3000
_0809A4B8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a4bc
FUN_0809a4bc: @ 0x0809A4BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A4DC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A4D8 @ =0x0836A6D4
	bl SetDDP
	b _0809A5CC
	.align 2, 0
_0809A4D8: .4byte 0x0836A6D4
_0809A4DC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A4F4 @ =0x0836A71C
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A4F8
	cmp r0, #1
	beq _0809A55C
	b _0809A5CC
	.align 2, 0
_0809A4F4: .4byte 0x0836A71C
_0809A4F8:
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0x12]
	movs r0, #1
	adds r2, r0, #0
	eors r2, r1
	cmp r2, #0
	beq _0809A516
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A51C
_0809A516:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A51C:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r2, #0xb0
	lsls r2, r2, #1
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A55C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809A5D4 @ =gSineTable
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #3
	movs r5, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, _0809A5D8 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A5CC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A5DC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A5CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A5D4: .4byte gSineTable
_0809A5D8: .4byte 0xFFFF3000
_0809A5DC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a5e0
FUN_0809a5e0: @ 0x0809A5E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A600
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A5FC @ =0x0836A6D4
	bl SetDDP
	b _0809A6EC
	.align 2, 0
_0809A5FC: .4byte 0x0836A6D4
_0809A600:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A618 @ =0x0836A734
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A61C
	cmp r0, #1
	beq _0809A67A
	b _0809A6EC
	.align 2, 0
_0809A618: .4byte 0x0836A734
_0809A61C:
	movs r1, #0xef
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0x12]
	movs r0, #1
	adds r2, r0, #0
	eors r2, r1
	cmp r2, #0
	beq _0809A63A
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A640
_0809A63A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A640:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r2, #0xe0
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A67A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809A6F4 @ =gSineTable
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bge _0809A694
	adds r1, #3
_0809A694:
	asrs r1, r1, #2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #3
	movs r5, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, _0809A6F8 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A6EC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A6FC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A6EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A6F4: .4byte gSineTable
_0809A6F8: .4byte 0xFFFF3000
_0809A6FC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a700
FUN_0809a700: @ 0x0809A700
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A724
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0809A720 @ =0x0836A6D4
	bl SetDDP
	b _0809A8F4
	.align 2, 0
_0809A720: .4byte 0x0836A6D4
_0809A724:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0809A740 @ =0x0836A74C
	bl SetDDP
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0809A782
	cmp r0, #1
	bgt _0809A744
	cmp r0, #0
	beq _0809A750
	b _0809A8F4
	.align 2, 0
_0809A740: .4byte 0x0836A74C
_0809A744:
	cmp r0, #2
	beq _0809A7A8
	cmp r0, #3
	bne _0809A74E
	b _0809A894
_0809A74E:
	b _0809A8F4
_0809A750:
	movs r1, #0xf1
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r2, _0809A79C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A7A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A7A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A782:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A794
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A794:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0809A8F4
	.align 2, 0
_0809A79C: .4byte RNG_0202f388
_0809A7A0: .4byte 0x000343FD
_0809A7A4: .4byte 0x00269EC3
_0809A7A8:
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r2, _0809A800 @ =RNG_0202f388
	mov r8, r2
	ldr r0, [r2]
	ldr r7, _0809A804 @ =0x000343FD
	muls r0, r7, r0
	ldr r5, _0809A808 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r6, #0x12]
	adds r0, r4, #0
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r3, r0, #1
	mov r1, r8
	str r3, [r1]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _0809A810
	adds r0, r3, #0
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #0xa
	ldr r3, _0809A80C @ =0xFFFFFE00
	adds r0, r0, r3
	b _0809A846
	.align 2, 0
_0809A800: .4byte RNG_0202f388
_0809A804: .4byte 0x000343FD
_0809A808: .4byte 0x00269EC3
_0809A80C: .4byte 0xFFFFFE00
_0809A810:
	movs r2, #0x80
	rsbs r2, r2, #0
	adds r0, r3, #0
	muls r0, r7, r0
	ldr r1, _0809A860 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r2, r2, r0
	adds r0, r3, #0
	muls r0, r7, r0
	ldr r3, _0809A860 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r1, r0
_0809A846:
	str r0, [r6, #0x5c]
	movs r1, #0
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _0809A852
	movs r1, #1
_0809A852:
	adds r2, r1, #0
	cmp r2, #0
	beq _0809A864
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A86A
	.align 2, 0
_0809A860: .4byte 0x00269EC3
_0809A864:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A86A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _0809A900 @ =0x0000F101
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A894:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	movs r2, #0
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A8AC
	strb r2, [r6, #0xe]
_0809A8AC:
	ldr r0, [r6, #0x54]
	ldr r1, _0809A904 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A8EE
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0809A908 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_0809A8EE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0809A8F4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A900: .4byte 0x0000F101
_0809A904: .4byte 0xFFFF3000
_0809A908: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a90c
FUN_0809a90c: @ 0x0809A90C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AA02
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A926
	cmp r0, #1
	beq _0809A9B2
	b _0809AA02
_0809A926:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	movs r3, #0x80
	rsbs r3, r3, #0
	ldr r2, _0809A974 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A978 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A97C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r3, r3, r0
	ldrb r0, [r4, #0x12]
	movs r1, #1
	eors r1, r0
	lsls r1, r1, #1
	movs r0, #1
	subs r0, r0, r1
	muls r0, r3, r0
	str r0, [r4, #0x5c]
	movs r1, #0
	cmp r0, #0
	ble _0809A964
	movs r1, #1
_0809A964:
	adds r2, r1, #0
	cmp r2, #0
	beq _0809A980
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A986
	.align 2, 0
_0809A974: .4byte RNG_0202f388
_0809A978: .4byte 0x000343FD
_0809A97C: .4byte 0x00269EC3
_0809A980:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A986:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0xf2
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A9B2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809AA08 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A9FC
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
	ldr r1, _0809AA0C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A9FC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809AA02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809AA08: .4byte 0xFFFF3000
_0809AA0C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809aa10
FUN_0809aa10: @ 0x0809AA10
	push {r4, r5, r6, lr}
	ldr r6, [r0, #8]
	ldr r0, [r6, #0x54]
	ldr r2, [r1, #8]
	subs r0, r0, r2
	asrs r5, r0, #8
	ldr r0, [r6, #0x58]
	ldr r1, [r1, #0xc]
	subs r0, r0, r1
	asrs r4, r0, #8
	subs r5, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0809AA2E
	adds r0, r5, #7
_0809AA2E:
	asrs r5, r0, #3
	cmp r5, #0
	bge _0809AA38
	movs r5, #0
	b _0809AA40
_0809AA38:
	adds r0, r5, #4
	cmp r0, #0x1e
	ble _0809AA40
	movs r5, #0x1a
_0809AA40:
	adds r4, #0x10
	adds r0, r4, #0
	cmp r4, #0
	bge _0809AA4A
	adds r0, r4, #7
_0809AA4A:
	asrs r4, r0, #3
	cmp r4, #0
	bgt _0809AA54
	movs r4, #1
	b _0809AA5A
_0809AA54:
	cmp r4, #0x11
	ble _0809AA5A
	movs r4, #0x11
_0809AA5A:
	ldr r0, _0809AA88 @ =0x080FF064
	adds r1, r5, #0
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, _0809AA8C @ =0x080FF06C
	adds r1, r5, #2
	adds r4, #1
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, [r6, #0x5c]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r2, r4, #0
	bl PrintMinigameNumber
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AA88: .4byte 0x080FF064
_0809AA8C: .4byte 0x080FF06C

	thumb_func_start FUN_0809aa90
FUN_0809aa90: @ 0x0809AA90
	push {r4, r5, r6, lr}
	ldr r6, [r0, #8]
	ldr r0, [r6, #0x54]
	ldr r2, [r1, #8]
	subs r0, r0, r2
	asrs r5, r0, #8
	ldr r0, [r6, #0x58]
	ldr r1, [r1, #0xc]
	subs r0, r0, r1
	asrs r4, r0, #8
	subs r5, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0809AAAE
	adds r0, r5, #7
_0809AAAE:
	asrs r5, r0, #3
	ldrb r1, [r6, #0x13]
	subs r0, r5, r1
	adds r0, #1
	cmp r0, #0
	bge _0809AABE
	subs r5, r1, #1
	b _0809AAC6
_0809AABE:
	adds r0, r5, #7
	cmp r0, #0x1e
	ble _0809AAC6
	movs r5, #0x17
_0809AAC6:
	adds r4, #0x10
	adds r0, r4, #0
	cmp r4, #0
	bge _0809AAD0
	adds r0, r4, #7
_0809AAD0:
	asrs r4, r0, #3
	cmp r4, #0
	bgt _0809AADA
	movs r4, #1
	b _0809AAE0
_0809AADA:
	cmp r4, #0x11
	ble _0809AAE0
	movs r4, #0x11
_0809AAE0:
	ldr r0, [r6, #0x68]
	cmp r0, #1
	ble _0809AAFC
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	bl PrintMinigameNumber
	ldr r0, _0809AB20 @ =0x080FF070
	adds r1, r5, #2
	adds r2, r4, #0
	bl PrintUnicodeString
_0809AAFC:
	ldr r0, _0809AB24 @ =0x080FF078
	adds r4, #1
	adds r1, r5, #0
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, [r6, #0x5c]
	adds r1, r5, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r2, r4, #0
	bl PrintMinigameNumber
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AB20: .4byte 0x080FF070
_0809AB24: .4byte 0x080FF078

	thumb_func_start FUN_0809ab28
FUN_0809ab28: @ 0x0809AB28
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0809ABA6
	cmp r5, #1
	bgt _0809AB3C
	cmp r5, #0
	beq _0809AB46
	b _0809AC1E
_0809AB3C:
	cmp r5, #2
	beq _0809ABBC
	cmp r5, #3
	beq _0809ABC6
	b _0809AC1E
_0809AB46:
	ldr r1, [r4, #0x68]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0809AB6C
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809AB68 @ =FUN_0809aa10
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0809AB9C
	.align 2, 0
_0809AB68: .4byte FUN_0809aa10
_0809AB6C:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809ABB8 @ =FUN_0809aa90
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	strb r5, [r4, #0x13]
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _0809AB9C
_0809AB88:
	adds r0, r1, #0
	movs r1, #0xa
	bl __divsi3
	adds r1, r0, #0
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	cmp r1, #0
	bne _0809AB88
_0809AB9C:
	movs r0, #0x1e
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABA6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0
	bne _0809AC1E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809AC1E
	.align 2, 0
_0809ABB8: .4byte FUN_0809aa90
_0809ABBC:
	movs r0, #0x18
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABC6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809ABDC
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0809ABE2
_0809ABDC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809ABE2:
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x64]
	cmp r2, #0
	bne _0809AC1E
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _0809AC24 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809AC1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AC24: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ac28
FUN_0809ac28: @ 0x0809AC28
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AC7A
	ldr r0, [r4, #0x20]
	adds r0, #0x3c
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #1
	bl FUN_08099f54
	ldr r1, [r4, #0x1c]
	adds r1, #1
	cmp r1, #4
	ble _0809AC70
	movs r1, #4
_0809AC70:
	ldrb r0, [r6]
	muls r1, r0, r1
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AC7A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809ACD4 @ =0x0836A77E
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809ACD8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809ACD4: .4byte 0x0836A77E
_0809ACD8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809acdc
FUN_0809acdc: @ 0x0809ACDC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AD2A
	ldr r0, [r4, #0x20]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #5
	bl FUN_08099f54
	ldrb r0, [r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AD2A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809AD84 @ =0x0836A784
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809AD88 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AD84: .4byte 0x0836A784
_0809AD88: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ad8c
FUN_0809ad8c: @ 0x0809AD8C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AD9E
	cmp r5, #1
	beq _0809ADF0
	b _0809AE5C
_0809AD9E:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809ADCC
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AE04 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809ADCC:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ADF0:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AE08
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AE0E
	.align 2, 0
_0809AE04: .4byte 0xFFFFFED4
_0809AE08:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AE0E:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AE5C
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AE38
	ldr r1, _0809AE64 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AE38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0809AE4C
	adds r0, #0xff
_0809AE4C:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x10
	str r1, [r4, #0x60]
_0809AE5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AE64: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ae68
FUN_0809ae68: @ 0x0809AE68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AE7A
	cmp r5, #1
	beq _0809AECA
	b _0809AF14
_0809AE7A:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AEA8
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AEE0 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809AEA8:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809AECA:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AEE4
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AEEA
	.align 2, 0
_0809AEE0: .4byte 0xFFFFFED4
_0809AEE4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AEEA:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AF14
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AF14
	ldr r1, _0809AF1C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AF14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AF1C: .4byte gEnemyFnTable
