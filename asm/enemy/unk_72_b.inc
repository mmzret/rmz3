	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809c5bc
FUN_0809c5bc: @ 0x0809C5BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #1
	beq _0809C614
	cmp r2, #1
	bgt _0809C5D0
	cmp r2, #0
	beq _0809C5D6
	b _0809C65A
_0809C5D0:
	cmp r2, #2
	beq _0809C63C
	b _0809C65A
_0809C5D6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809C5F6
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _0809C5FC
_0809C5F6:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0809C638 @ =0xFFFFF400
_0809C5FC:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809C614:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0809C65A
	.align 2, 0
_0809C638: .4byte 0xFFFFF400
_0809C63C:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809C65A
	ldr r1, _0809C660 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809C65A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C660: .4byte gEnemyFnTable

