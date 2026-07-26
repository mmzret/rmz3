	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Mellnet_Init
Mellnet_Init: @ 0x0807D85C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0807D8C4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0807D8C8 @ =0x08367D44
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
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
	ldr r1, _0807D8CC @ =0x08367CDC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #4
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0807D8D0 @ =FUN_0807d720
	str r0, [r5, #0x24]
	adds r0, r4, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r0, r4, #0
	bl Mellnet_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D8C4: .4byte gEnemyFnTable
_0807D8C8: .4byte 0x08367D44
_0807D8CC: .4byte sCollisions
_0807D8D0: .4byte FUN_0807d720
