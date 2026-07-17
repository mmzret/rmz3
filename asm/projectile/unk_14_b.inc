	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile14_Init
Projectile14_Init: @ 0x080A0A60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080A0AE0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080A0AE4 @ =u8_ARRAY_0836b20c
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
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
	ldr r1, _080A0AE8 @ =sCollisions
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080A0AEC @ =onCollision
	str r0, [r5, #0x24]
	ldr r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0xb4
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r1]
	adds r5, #0x44
	ldr r0, [r4, #0x58]
	asrs r0, r0, #8
	str r0, [r5]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	str r1, [r5]
	adds r0, r4, #0
	bl Projectile14_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0AE0: .4byte gProjectileFnTable
_080A0AE4: .4byte u8_ARRAY_0836b20c
_080A0AE8: .4byte sCollisions
_080A0AEC: .4byte onCollision

