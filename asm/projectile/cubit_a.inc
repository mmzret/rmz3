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
