	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createGoldOmega1Laser
createGoldOmega1Laser: @ 0x080AC388
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	adds r7, r3, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AC3E0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AC3D6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC3E4 @ =gProjectileFnTable
	movs r1, #0x21
	strb r1, [r3, #9]
	adds r0, #0x84
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r4, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC3D6:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC3E0: .4byte gProjectileHeaderPtr
_080AC3E4: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac3e8
FUN_080ac3e8: @ 0x080AC3E8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r0, _080AC440 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AC438
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC444 @ =gProjectileFnTable
	movs r1, #0x21
	strb r1, [r3, #9]
	adds r0, #0x84
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xbc
	str r6, [r0]
_080AC438:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AC440: .4byte gProjectileHeaderPtr
_080AC444: .4byte gProjectileFnTable

	thumb_func_start OmegaGoldProjectile_Init
OmegaGoldProjectile_Init: @ 0x080AC448
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r5, [r6, #0x10]
	cmp r5, #0
	bne _080AC4A0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AC498 @ =0x0836C644
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x25
	strb r5, [r0]
	ldr r1, _080AC49C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	b _080AC4E8
	.align 2, 0
_080AC498: .4byte 0x0836C644
_080AC49C: .4byte gProjectileFnTable
_080AC4A0:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AC4FC @ =0x0836C614
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080AC500 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080AC504 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #2
	strb r0, [r6, #0xd]
_080AC4E8:
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl OmegaGoldProjectile_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AC4FC: .4byte 0x0836C614
_080AC500: .4byte 0xFFFFFF00
_080AC504: .4byte gProjectileFnTable

	thumb_func_start OmegaGoldProjectile_Update
OmegaGoldProjectile_Update: @ 0x080AC508
	push {lr}
	ldr r2, _080AC51C @ =0x0836C608
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AC51C: .4byte 0x0836C608

	thumb_func_start OmegaGoldProjectile_Die
OmegaGoldProjectile_Die: @ 0x080AC520
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
	ldr r1, _080AC558 @ =gProjectileFnTable
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
_080AC558: .4byte gProjectileFnTable
