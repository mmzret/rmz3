	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a5f00
FUN_080a5f00: @ 0x080A5F00
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080A5F4C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A5F44
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A5F50 @ =gProjectileFnTable
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
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
	adds r1, #0x94
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r5, [r0]
_080A5F44:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A5F4C: .4byte gProjectileHeaderPtr
_080A5F50: .4byte gProjectileFnTable

	thumb_func_start FUN_080a5f54
FUN_080a5f54: @ 0x080A5F54
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080A5FBC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	mov ip, r0
	cmp r0, #0
	beq _080A5FB2
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A5FC0 @ =gProjectileFnTable
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
	movs r0, #5
	mov r1, ip
	strb r0, [r1, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	mov r0, ip
	adds r0, #0xb4
	strb r4, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r2, [r0]
	str r7, [r3, #0x28]
_080A5FB2:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A5FBC: .4byte gProjectileHeaderPtr
_080A5FC0: .4byte gProjectileFnTable

	thumb_func_start FUN_080a5fc4
FUN_080a5fc4: @ 0x080A5FC4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A600C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A6002
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A6010 @ =gProjectileFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #1
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb6
	strb r1, [r0]
	str r4, [r3, #0x28]
_080A6002:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A600C: .4byte gProjectileHeaderPtr
_080A6010: .4byte gProjectileFnTable

	thumb_func_start FUN_080a6014
FUN_080a6014: @ 0x080A6014
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080A6070 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A6068
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A6074 @ =gProjectileFnTable
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
	movs r0, #4
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
_080A6068:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A6070: .4byte gProjectileHeaderPtr
_080A6074: .4byte gProjectileFnTable

	thumb_func_start cubit_080a6078
cubit_080a6078: @ 0x080A6078
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A60C0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A60B6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A60C4 @ =gProjectileFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #2
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb6
	strb r1, [r0]
	str r4, [r3, #0x28]
_080A60B6:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A60C0: .4byte gProjectileHeaderPtr
_080A60C4: .4byte gProjectileFnTable

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

	thumb_func_start CubitProjectile_Update
CubitProjectile_Update: @ 0x080A6350
	push {lr}
	ldr r2, _080A636C @ =0x0836BB94
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
_080A636C: .4byte sUpdates

	thumb_func_start CubitProjectile_Die
CubitProjectile_Die: @ 0x080A6370
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
	ldr r1, _080A63A8 @ =gProjectileFnTable
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
_080A63A8: .4byte gProjectileFnTable

	thumb_func_start cubit_080a63ac
cubit_080a63ac: @ 0x080A63AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080A63C0
	b _080A66F0
_080A63C0:
	adds r0, r1, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A63CC
	b _080A66F0
_080A63CC:
	ldrb r0, [r1, #0xd]
	cmp r0, #0xb
	bne _080A63D4
	b _080A66F0
_080A63D4:
	ldrb r0, [r6, #0xe]
	cmp r0, #0xc
	bls _080A63DC
	b _080A6702
_080A63DC:
	lsls r0, r0, #2
	ldr r1, _080A63E8 @ =_080A63EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A63E8: .4byte _080A63EC
_080A63EC: @ jump table
	.4byte _080A6420 @ case 0
	.4byte _080A649C @ case 1
	.4byte _080A64B4 @ case 2
	.4byte _080A64C6 @ case 3
	.4byte _080A64E8 @ case 4
	.4byte _080A6550 @ case 5
	.4byte _080A656C @ case 6
	.4byte _080A6590 @ case 7
	.4byte _080A65B4 @ case 8
	.4byte _080A6650 @ case 9
	.4byte _080A6666 @ case 10
	.4byte _080A66D2 @ case 11
	.4byte _080A66E0 @ case 12
_080A6420:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r7, #0
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A645C @ =0x0836BC1C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080A6460 @ =0x0000B103
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0xb6
	ldrb r2, [r0]
	cmp r2, #0
	beq _080A6464
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A646A
	.align 2, 0
_080A645C: .4byte sCollisions+(5*24)
_080A6460: .4byte 0x0000B103
_080A6464:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A646A:
	strb r0, [r6, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r6, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r6, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r6, #0x58]
	movs r0, #5
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A649C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _080A65F8
_080A64B4:
	ldr r1, _080A64E4 @ =0x0000B104
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A64C6:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	bne _080A64D4
	b _080A6640
_080A64D4:
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A64E0
	b _080A6702
_080A64E0:
	b _080A6640
	.align 2, 0
_080A64E4: .4byte 0x0000B104
_080A64E8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080A6564 @ =0x0836BC1C
	bl SetDDP
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r7, #0
	movs r0, #0xb5
	adds r0, r0, r6
	mov r8, r0
	mov r4, sp
	ldr r5, _080A6568 @ =0x0836BD24
_080A6512:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [r4, #4]
	ldr r0, [r5]
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #4]
	ldr r1, [r4, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	mov r0, r8
	ldrb r3, [r0]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_080a5f54
	adds r5, #8
	adds r7, #1
	cmp r7, #4
	ble _080A6512
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A6550:
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A655C
	b _080A6702
_080A655C:
	movs r0, #0
	strb r0, [r6, #0x13]
	b _080A6640
	.align 2, 0
_080A6564: .4byte sCollisions+(5*24)
_080A6568: .4byte sCoords
_080A656C:
	ldrb r0, [r6, #0x13]
	adds r4, r6, #0
	adds r4, #0xb4
	cmp r0, #0
	bne _080A6586
	ldrb r0, [r4]
	cmp r0, #5
	bne _080A6586
	movs r0, #1
	strb r0, [r6, #0x13]
	movs r0, #0xcc
	bl PlaySound
_080A6586:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A658E
	b _080A6702
_080A658E:
	b _080A6640
_080A6590:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, [r6, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r6, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r6, #0x58]
	movs r0, #5
	strb r0, [r6, #0x13]
	ldr r1, _080A6648 @ =0x0000B103
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A65B4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r4, r0, #0
	cmp r1, #1
	beq _080A65DE
	cmp r1, #5
	beq _080A65DE
	cmp r1, #9
	beq _080A65DE
	cmp r1, #0xd
	beq _080A65DE
	cmp r1, #0x11
	bne _080A65F4
_080A65DE:
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080A65F4
	movs r0, #0xcb
	bl PlaySound
_080A65F4:
	movs r0, #0
	ldrsb r0, [r4, r0]
_080A65F8:
	cmp r0, #1
	beq _080A660C
	cmp r0, #5
	beq _080A660C
	cmp r0, #9
	beq _080A660C
	cmp r0, #0xd
	beq _080A660C
	cmp r0, #0x11
	bne _080A6636
_080A660C:
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080A6636
	adds r0, r6, #0
	adds r0, #0x74
	ldrb r2, [r6, #0x13]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A664C @ =0x0836BC1C
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
_080A6636:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A6702
_080A6640:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A6702
	.align 2, 0
_080A6648: .4byte 0x0000B103
_080A664C: .4byte sCollisions+(5*24)
_080A6650:
	ldr r1, _080A66C4 @ =0x0000B105
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x30
	strb r0, [r6, #0x12]
	movs r0, #2
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A6666:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _080A6690
	cmp r0, #5
	beq _080A6690
	cmp r0, #9
	beq _080A6690
	cmp r0, #0xd
	beq _080A6690
	cmp r0, #0x11
	bne _080A66E6
_080A6690:
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080A66E6
	adds r0, r6, #0
	adds r0, #0x74
	ldrb r2, [r6, #0x13]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A66C8 @ =0x0836BC1C
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r6, #0x13]
	adds r1, r0, #0
	cmp r1, #4
	bhi _080A66CC
	cmp r1, #0
	beq _080A66E6
	adds r0, #1
	b _080A66CE
	.align 2, 0
_080A66C4: .4byte 0x0000B105
_080A66C8: .4byte sCollisions+(5*24)
_080A66CC:
	movs r0, #0
_080A66CE:
	strb r0, [r6, #0x13]
	b _080A66E6
_080A66D2:
	ldr r1, _080A6710 @ =0x0000B105
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A66E0:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080A66E6:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A6702
_080A66F0:
	ldr r1, _080A6714 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A6702:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6710: .4byte 0x0000B105
_080A6714: .4byte gProjectileFnTable
