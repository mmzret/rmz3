	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809ec24
FUN_0809ec24: @ 0x0809EC24
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0809EC8A
	cmp r0, #1
	bgt _0809EC38
	cmp r0, #0
	beq _0809EC3E
	b _0809EDF0
_0809EC38:
	cmp r0, #2
	beq _0809ED36
	b _0809EDF0
_0809EC3E:
	adds r0, r5, #0
	bl InitRotatableMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	adds r0, r5, #0
	adds r0, #0x50
	movs r4, #0x80
	lsls r4, r4, #1
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #0x62
	ldrb r1, [r0]
	subs r0, #0x90
	strb r1, [r0]
	ldr r1, _0809ECEC @ =0x0000A301
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	str r4, [r2]
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #6
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EC8A:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _0809EC9C
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bgt _0809ECCE
_0809EC9C:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	rsbs r1, r2, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r2, r0, r2
	asrs r2, r2, #8
	str r2, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r1, r0, r1
	asrs r1, r1, #8
	str r1, [r5, #0x68]
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0809ECCE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809ECE0
	subs r0, #1
	movs r3, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809ECF0
_0809ECE0:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809ED2E
	.align 2, 0
_0809ECEC: .4byte 0x0000A301
_0809ECF0:
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809ED14
	str r3, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0809EDDE
_0809ED14:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809ED2E
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809EDD4
_0809ED2E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _0809EDF0
_0809ED36:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _0809ED48
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bgt _0809ED7E
_0809ED48:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r2, r0, r2
	asrs r2, r2, #8
	str r2, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r1, r0, r1
	asrs r1, r1, #8
	str r1, [r5, #0x68]
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0809ED7E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809EDDE
	subs r0, #1
	movs r3, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809EDDE
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809EDBA
	str r3, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0809EDDE
_0809EDBA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809EDF0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809EDF0
_0809EDD4:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_0809EDDE:
	ldr r1, _0809EDF8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809EDF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809EDF8: .4byte gProjectileFnTable
