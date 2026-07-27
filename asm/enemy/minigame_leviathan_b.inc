	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl UpdateEntityAnim
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
_0809A18C: .4byte sMotions
_0809A190: .4byte sCollisions
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
