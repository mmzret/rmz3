	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809e9c4
FUN_0809e9c4: @ 0x0809E9C4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809E9D4
	cmp r0, #1
	beq _0809EA2A
	b _0809EACA
_0809E9D4:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	bl ResetDynamicMotion
	adds r2, r5, #0
	adds r2, #0xbc
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r2]
	adds r0, r5, #0
	adds r0, #0x50
	movs r4, #0
	strh r1, [r0]
	ldr r0, [r2]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, _0809EAD0 @ =0x0000A301
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r2]
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0xa
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EA2A:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	rsbs r1, r2, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r0, r2, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	adds r3, #4
	ldr r2, [r3]
	movs r1, #0xe0
	lsls r1, r1, #1
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	adds r0, r5, #0
	adds r0, #0x50
	strh r2, [r0]
	ldr r0, [r3]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, [r3]
	movs r0, #0xd0
	lsls r0, r0, #1
	cmp r1, r0
	ble _0809EA92
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0809EA92
	adds r0, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809EAD4 @ =0x0836AE38
	bl SetDDP
_0809EA92:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809EAB8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809EACA
_0809EAB8:
	ldr r1, _0809EAD8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809EACA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809EAD0: .4byte 0x0000A301
_0809EAD4: .4byte 0x0836AE38
_0809EAD8: .4byte gProjectileFnTable
