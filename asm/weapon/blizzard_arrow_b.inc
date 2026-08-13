	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start BlizzardArrow_Die
BlizzardArrow_Die: @ 0x0803BD3C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803BD58 @ =gWeaponFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0803BD58: .4byte gWeaponFnTable

	thumb_func_start hitBlizzardArrow
hitBlizzardArrow: @ 0x0803BD5C
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803BD92
	ldr r4, [r2, #0x2c]
	ldr r3, _0803BD98 @ =gScore
	ldrh r1, [r3, #0x1c]
	ldr r0, _0803BD9C @ =0x0000FFFE
	cmp r1, r0
	bhi _0803BD7A
	adds r0, r1, #1
	strh r0, [r3, #0x1c]
_0803BD7A:
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BD8E
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0803BD92
_0803BD8E:
	movs r0, #1
	strb r0, [r4, #0x13]
_0803BD92:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803BD98: .4byte gScore
_0803BD9C: .4byte 0x0000FFFE
