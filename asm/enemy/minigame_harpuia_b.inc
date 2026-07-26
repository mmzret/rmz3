	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
