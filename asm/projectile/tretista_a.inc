	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretista_080a369c
tretista_080a369c: @ 0x080A369C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A36EC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A36E4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A36F0 @ =gProjectileFnTable
	movs r0, #0x13
	strb r0, [r3, #9]
	ldr r0, [r1, #0x4c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A36E4:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A36EC: .4byte gProjectileHeaderPtr
_080A36F0: .4byte gProjectileFnTable

	thumb_func_start tretista_080a36f4
tretista_080a36f4: @ 0x080A36F4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A3744 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A373C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A3748 @ =gProjectileFnTable
	movs r0, #0x13
	strb r0, [r3, #9]
	ldr r0, [r1, #0x4c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A373C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A3744: .4byte gProjectileHeaderPtr
_080A3748: .4byte gProjectileFnTable

	thumb_func_start FUN_080a374c
FUN_080a374c: @ 0x080A374C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A379C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A3794
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A37A0 @ =gProjectileFnTable
	movs r0, #0x13
	strb r0, [r3, #9]
	ldr r0, [r1, #0x4c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A3794:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A379C: .4byte gProjectileHeaderPtr
_080A37A0: .4byte gProjectileFnTable

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

	thumb_func_start TretistaProjectile_Update
TretistaProjectile_Update: @ 0x080A388C
	push {lr}
	ldr r2, _080A38A8 @ =0x0836B4E4
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r2, [r0, #0xd]
	ldr r1, [r1]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r1, [r2]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A38A8: .4byte 0x0836B4E4

	thumb_func_start TretistaProjectile_Die
TretistaProjectile_Die: @ 0x080A38AC
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080A38E4 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080A38E4: .4byte gProjectileFnTable
