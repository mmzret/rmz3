	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ad994
FUN_080ad994: @ 0x080AD994
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080AD9C8 @ =0x00006A06
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080AD9CC
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AD9D2
	.align 2, 0
_080AD9C8: .4byte 0x00006A06
_080AD9CC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AD9D2:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ADA00
	ldr r0, [r5, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	b _080ADA04
_080ADA00:
	ldr r0, [r5, #0x54]
	ldr r1, _080ADA48 @ =0xFFFFF600
_080ADA04:
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080ADA28
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
_080ADA28:
	ldr r1, _080ADA4C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile36_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA48: .4byte 0xFFFFF600
_080ADA4C: .4byte gProjectileFnTable

