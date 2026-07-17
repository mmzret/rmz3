	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a60c8
FUN_080a60c8: @ 0x080A60C8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080A6124 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A611C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A6128 @ =gProjectileFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #6
	strb r0, [r3, #0x10]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r4, [r0]
	adds r0, #1
	strb r6, [r0]
	str r7, [r3, #0x28]
_080A611C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A6124: .4byte gProjectileHeaderPtr
_080A6128: .4byte gProjectileFnTable

	thumb_func_start createFlameRain1
createFlameRain1: @ 0x080A612C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _080A618C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	mov ip, r0
	cmp r0, #0
	beq _080A6182
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A6190 @ =gProjectileFnTable
	movs r0, #0x16
	mov r2, ip
	strb r0, [r2, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x20]
	adds r0, #0x22
	strb r2, [r0]
	movs r0, #3
	mov r1, ip
	strb r0, [r1, #0x10]
	strb r2, [r1, #0x11]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	mov r0, ip
	adds r0, #0xb5
	strb r5, [r0]
	adds r0, #1
	strb r2, [r0]
	str r6, [r3, #0x28]
_080A6182:
	mov r0, ip
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A618C: .4byte gProjectileHeaderPtr
_080A6190: .4byte gProjectileFnTable

	thumb_func_start createFlameRain2
createFlameRain2: @ 0x080A6194
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _080A61F4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	mov ip, r0
	cmp r0, #0
	beq _080A61EC
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A61F8 @ =gProjectileFnTable
	movs r0, #0x16
	mov r2, ip
	strb r0, [r2, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x20]
	adds r0, #0x22
	strb r2, [r0]
	movs r0, #3
	mov r1, ip
	strb r0, [r1, #0x10]
	movs r0, #1
	strb r0, [r1, #0x11]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	mov r0, ip
	adds r0, #0xb5
	strb r5, [r0]
	adds r0, #1
	strb r2, [r0]
	str r6, [r3, #0x28]
_080A61EC:
	mov r0, ip
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A61F4: .4byte gProjectileHeaderPtr
_080A61F8: .4byte gProjectileFnTable

	thumb_func_start CubitProjectile_Init
CubitProjectile_Init: @ 0x080A61FC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0xa]
	movs r1, #1
	movs r4, #0
	movs r7, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r2, [r6, #0x10]
	cmp r2, #0
	bne _080A623C
	ldr r1, _080A6238 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	b _080A6332
	.align 2, 0
_080A6238: .4byte gProjectileFnTable
_080A623C:
	cmp r2, #5
	bne _080A6260
	strb r7, [r6, #0x10]
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A625C @ =0x0836BCAC
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	b _080A6316
	.align 2, 0
_080A625C: .4byte sCollisions+(11*24)
_080A6260:
	cmp r2, #1
	bne _080A627C
	ldr r1, _080A6278 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	b _080A6332
	.align 2, 0
_080A6278: .4byte gProjectileFnTable
_080A627C:
	cmp r2, #4
	bne _080A62C0
	movs r5, #1
	strb r5, [r6, #0x10]
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A62B8 @ =0x0836BBA4
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r1, _080A62BC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	b _080A6332
	.align 2, 0
_080A62B8: .4byte sCollisions
_080A62BC: .4byte gProjectileFnTable
_080A62C0:
	cmp r2, #2
	bne _080A62E0
	ldr r1, _080A62DC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	b _080A6332
	.align 2, 0
_080A62DC: .4byte gProjectileFnTable
_080A62E0:
	cmp r2, #6
	bne _080A62FC
	movs r0, #2
	strb r0, [r6, #0x10]
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A62F8 @ =0x0836BCF4
	b _080A630E
	.align 2, 0
_080A62F8: .4byte sCollisions+(14*24)
_080A62FC:
	cmp r2, #3
	bne _080A6336
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A6348 @ =0x0836BCC4
_080A630E:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
_080A6316:
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r1, _080A634C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0xd]
_080A6332:
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
_080A6336:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl CubitProjectile_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6348: .4byte sCollisions+(12*24)
_080A634C: .4byte gProjectileFnTable

