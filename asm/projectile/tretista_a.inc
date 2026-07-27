	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start TretistaProjectile_Init
TretistaProjectile_Init: @ 0x080A37A4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r5, [r6, #0x10]
	cmp r5, #0
	bne _080A37D8
	bl InitNonAffineMotion
	adds r0, r6, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A37D4 @ =sCollisions
	b _080A3832
	.align 2, 0
_080A37D4: .4byte sCollisions
_080A37D8:
	cmp r5, #1
	bne _080A3808
	adds r1, r6, #0
	adds r1, #0x25
	movs r5, #0
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A3804 @ =0x0836B50C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x20
	b _080A383A
	.align 2, 0
_080A3804: .4byte 0x0836B50C
_080A3808:
	cmp r5, #2
	bne _080A3818
	adds r0, r6, #0
	bl InitNonAffineMotion
	movs r0, #0
	str r0, [r6, #0x2c]
	b _080A3842
_080A3818:
	cmp r5, #3
	bne _080A3842
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A3884 @ =0x0836B9A4
_080A3832:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
_080A383A:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_080A3842:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r0, r6, #0
	adds r0, #0xc0
	str r4, [r0]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldr r1, _080A3888 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl TretistaProjectile_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3884: .4byte 0x0836B9A4
_080A3888: .4byte gProjectileFnTable
