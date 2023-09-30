	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateWormerRockDrone
CreateWormerRockDrone: @ 0x08076E58
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _08076ED4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _08076ECA
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08076ED8 @ =gEnemyFnTable
	movs r0, #0x17
	strb r0, [r4, #9]
	ldr r0, [r1, #0x5c]
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
	strb r6, [r4, #0x12]
	str r7, [r4, #0x54]
	mov r0, r8
	str r0, [r4, #0x58]
	ldr r1, _08076EDC @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r4, #0x5c]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x60]
_08076ECA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076ED4: .4byte gZakoHeaderPtr
_08076ED8: .4byte gEnemyFnTable
_08076EDC: .4byte gSineTable

	thumb_func_start nop_08076ee0
nop_08076ee0: @ 0x08076EE0
	bx lr
	.align 2, 0

	thumb_func_start FUN_08076ee4
FUN_08076ee4: @ 0x08076EE4
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08076EFA
	movs r0, #0
	b _08076F18
_08076EFA:
	ldr r1, _08076F1C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	movs r0, #0
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl WormerRockDrone_Die
	movs r0, #1
_08076F18:
	pop {r1}
	bx r1
	.align 2, 0
_08076F1C: .4byte gEnemyFnTable

	thumb_func_start WormerRockDrone_Init
WormerRockDrone_Init: @ 0x08076F20
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08076F80 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _08076F84 @ =0x08367250
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _08076F88 @ =0x08367220
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #6
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _08076F8C @ =nop_08076ee0
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl WormerRockDrone_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08076F80: .4byte gEnemyFnTable
_08076F84: .4byte 0x08367250
_08076F88: .4byte 0x08367220
_08076F8C: .4byte nop_08076ee0

	thumb_func_start WormerRockDrone_Update
WormerRockDrone_Update: @ 0x08076F90
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08076ee4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076FBE
	ldr r1, _08076FC4 @ =0x08367214
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08076FC8 @ =0x08367218
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08076FBE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08076FC4: .4byte 0x08367214
_08076FC8: .4byte 0x08367218

	thumb_func_start WormerRockDrone_Die
WormerRockDrone_Die: @ 0x08076FCC
	push {lr}
	ldr r2, _08076FE0 @ =0x0836721C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08076FE0: .4byte 0x0836721C

	thumb_func_start FUN_08076fe4
FUN_08076fe4: @ 0x08076FE4
	bx lr
	.align 2, 0

	thumb_func_start FUN_08076fe8
FUN_08076fe8: @ 0x08076FE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08076FF8
	cmp r0, #1
	beq _0807700E
	b _080770A0
_08076FF8:
	ldrb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r1, _08077070 @ =0x00002C01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807700E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _08077074 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _0807707C
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
	ldr r1, _08077078 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080770A0
	.align 2, 0
_08077070: .4byte 0x00002C01
_08077074: .4byte gStageRun+232
_08077078: .4byte gEnemyFnTable
_0807707C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080770A0
	ldr r1, _080770A8 @ =gEnemyFnTable
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
_080770A0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080770A8: .4byte gEnemyFnTable

	thumb_func_start FUN_080770ac
FUN_080770ac: @ 0x080770AC
	push {r4, lr}
	sub sp, #8
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
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08077108 @ =0x08367252
	adds r0, r4, #0
	mov r1, sp
	movs r3, #2
	bl FUN_080b7f70
	movs r0, #0x91
	lsls r0, r0, #1
	bl PlaySound
	ldr r1, _0807710C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08077108: .4byte 0x08367252
_0807710C: .4byte gEnemyFnTable
