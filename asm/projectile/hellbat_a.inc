	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a14dc
FUN_080a14dc: @ 0x080A14DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A1530 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A1528
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A1534 @ =gProjectileFnTable
	movs r0, #0xf
	strb r0, [r3, #9]
	ldr r0, [r1, #0x3c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A1528:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A1530: .4byte gProjectileHeaderPtr
_080A1534: .4byte gProjectileFnTable

	thumb_func_start FUN_080a1538
FUN_080a1538: @ 0x080A1538
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A158C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A1584
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A1590 @ =gProjectileFnTable
	movs r0, #0xf
	strb r0, [r3, #9]
	ldr r0, [r1, #0x3c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A1584:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A158C: .4byte gProjectileHeaderPtr
_080A1590: .4byte gProjectileFnTable

	thumb_func_start FUN_080a1594
FUN_080a1594: @ 0x080A1594
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A15E8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A15E0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A15EC @ =gProjectileFnTable
	movs r0, #0xf
	strb r0, [r3, #9]
	ldr r0, [r1, #0x3c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A15E0:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A15E8: .4byte gProjectileHeaderPtr
_080A15EC: .4byte gProjectileFnTable

	thumb_func_start Projectile15_Init
Projectile15_Init: @ 0x080A15F0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldrb r5, [r6, #0x10]
	cmp r5, #0
	bne _080A1620
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A161C @ =0x0836B264
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	b _080A16C6
	.align 2, 0
_080A161C: .4byte 0x0836B264
_080A1620:
	cmp r5, #1
	bne _080A1660
	adds r0, r6, #0
	bl InitNonAffineMotion
	movs r5, #0
	strb r5, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0xbc
	str r5, [r0]
	adds r0, r6, #0
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
	ldr r1, _080A165C @ =0x0836B2DC
	b _080A16BE
	.align 2, 0
_080A165C: .4byte 0x0836B2DC
_080A1660:
	cmp r5, #2
	bne _080A1680
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A167C @ =0x0836B294
	b _080A16BE
	.align 2, 0
_080A167C: .4byte 0x0836B294
_080A1680:
	cmp r5, #3
	bne _080A16A4
	adds r0, r6, #0
	bl InitScalerotMotion1
	adds r0, r6, #0
	adds r0, #0x24
	movs r5, #0
	strb r5, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	b _080A16B4
_080A16A4:
	cmp r5, #4
	bne _080A16CE
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
_080A16B4:
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A1708 @ =0x0836B2AC
_080A16BE:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
_080A16C6:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_080A16CE:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldr r1, _080A170C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl Projectile15_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1708: .4byte 0x0836B2AC
_080A170C: .4byte gProjectileFnTable

