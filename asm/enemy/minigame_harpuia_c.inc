	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
