	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b1698
FUN_080b1698: @ 0x080B1698
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080B16E8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080B16E0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B16EC @ =gProjectileFnTable
	movs r1, #0x2c
	strb r1, [r3, #9]
	adds r0, #0xb0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
	strb r5, [r3, #0x12]
	strb r4, [r3, #0x13]
_080B16E0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B16E8: .4byte gProjectileHeaderPtr
_080B16EC: .4byte gProjectileFnTable
_080B16F0:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080b16f4
FUN_080b16f4: @ 0x080B16F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080B1754 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080B1758 @ =0x0836D7B4
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
	ldr r1, _080B175C @ =0x0836D79C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080B1760 @ =0x080B16F1
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080b1764
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1754: .4byte gProjectileFnTable
_080B1758: .4byte 0x0836D7B4
_080B175C: .4byte 0x0836D79C
_080B1760: .4byte 0x080B16F1
