	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
