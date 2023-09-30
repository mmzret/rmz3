	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateProjectile7
CreateProjectile7: @ 0x0809E064
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809E0EC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809E0E4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809E0F0 @ =gProjectileFnTable
	movs r0, #7
	strb r0, [r3, #9]
	ldr r0, [r1, #0x1c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r6]
	str r0, [r3, #0x54]
	ldr r0, [r6, #4]
	str r0, [r3, #0x58]
	adds r0, r4, #0
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	adds r0, r3, #0
	adds r0, #0xb4
	str r5, [r0]
	ldr r2, _0809E0F4 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _0809E0CC
	adds r0, #0xff
_0809E0CC:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _0809E0E0
	adds r0, #0xff
_0809E0E0:
	asrs r0, r0, #8
	str r0, [r3, #0x60]
_0809E0E4:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809E0EC: .4byte gProjectileHeaderPtr
_0809E0F0: .4byte gProjectileFnTable
_0809E0F4: .4byte gSineTable

	thumb_func_start Projectile7_Init
Projectile7_Init: @ 0x0809E0F8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r6, #4
	orrs r0, r6
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0809E170 @ =0x0836AC9C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0
	bl InitBody
	str r4, [r5, #0x2c]
	mov r0, r8
	str r0, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #1
	bl SetMotion
	movs r0, #0xff
	strb r0, [r4, #0x12]
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r6
	strb r0, [r2]
	ldr r1, _0809E174 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile7_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E170: .4byte 0x0836AC9C
_0809E174: .4byte gProjectileFnTable

	thumb_func_start Projectile7_Update
Projectile7_Update: @ 0x0809E178
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0809E1C4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0809E1CC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809E1C8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0809E212
	.align 2, 0
_0809E1C4: .4byte gCurStory
_0809E1C8: .4byte gProjectileFnTable
_0809E1CC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809E214
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809E21C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_0809E212:
	str r0, [r4, #0x14]
_0809E214:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809E21C: .4byte gProjectileFnTable

	thumb_func_start Projectile7_Die
Projectile7_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68
	.byte 0x00, 0x69, 0x50, 0x61, 0x70, 0x47, 0x00, 0x00, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_0809e25c
FUN_0809e25c: @ 0x0809E25C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0809E298 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809E292
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809E29C @ =gProjectileFnTable
	strb r0, [r3, #9]
	ldr r0, [r1, #0x20]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_0809E292:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809E298: .4byte gProjectileHeaderPtr
_0809E29C: .4byte gProjectileFnTable

	thumb_func_start Projectile8_Init
Projectile8_Init: @ 0x0809E2A0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809E324 @ =0x00001709
	adds r0, r4, #0
	bl SetMotion
	movs r6, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #1
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0809E328 @ =0x0836ACE0
	adds r2, #0xa
	adds r0, r5, #0
	movs r3, #8
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	str r6, [r4, #0x60]
	ldr r1, _0809E32C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile8_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E324: .4byte 0x00001709
_0809E328: .4byte 0x0836ACE0
_0809E32C: .4byte gProjectileFnTable

	thumb_func_start Projectile8_Update
Projectile8_Update: @ 0x0809E330
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0809E37C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0809E384
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809E380 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0809E43A
	.align 2, 0
_0809E37C: .4byte gCurStory
_0809E380: .4byte gProjectileFnTable
_0809E384:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0809E3F4
	ldr r1, [r4, #0x60]
	ldr r0, _0809E3E8 @ =0x000006FF
	cmp r1, r0
	bgt _0809E39E
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r4, #0x60]
_0809E39E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0809E3C2
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0809E43A
_0809E3C2:
	ldr r1, _0809E3EC @ =0x0000170A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0x35
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809E3F0 @ =0x0836ACF8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809E43A
	.align 2, 0
_0809E3E8: .4byte 0x000006FF
_0809E3EC: .4byte 0x0000170A
_0809E3F0: .4byte 0x0836ACF8
_0809E3F4:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0809E418
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_0809E418:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809E43A
	ldr r1, _0809E440 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile8_Die
_0809E43A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809E440: .4byte gProjectileFnTable

	thumb_func_start Projectile8_Die
Projectile8_Die: @ 0x0809E444
	push {lr}
	adds r3, r0, #0
	ldr r0, _0809E48C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0809E494
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0809E490 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0809E4A4
	.align 2, 0
_0809E48C: .4byte gCurStory
_0809E490: .4byte gProjectileFnTable
_0809E494:
	ldr r1, _0809E4AC @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0809E4A4:
	str r0, [r3, #0x14]
	pop {r0}
	bx r0
	.align 2, 0
_0809E4AC: .4byte gProjectileFnTable

	thumb_func_start FUN_0809e4b0
FUN_0809e4b0: @ 0x0809E4B0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0809E4F8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809E4F0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809E4FC @ =gProjectileFnTable
	movs r0, #9
	strb r0, [r3, #9]
	ldr r0, [r1, #0x24]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r5, [r3, #0x28]
_0809E4F0:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809E4F8: .4byte gProjectileHeaderPtr
_0809E4FC: .4byte gProjectileFnTable

	thumb_func_start FUN_0809e500
FUN_0809e500: @ 0x0809E500
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r0, _0809E554 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809E54C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809E558 @ =gProjectileFnTable
	movs r0, #9
	strb r0, [r3, #9]
	ldr r0, [r1, #0x24]
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
	ldr r1, [r4, #4]
	str r0, [r3, #0x5c]
	str r1, [r3, #0x60]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_0809E54C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809E554: .4byte gProjectileHeaderPtr
_0809E558: .4byte gProjectileFnTable

	thumb_func_start FUN_0809e55c
FUN_0809e55c: @ 0x0809E55C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _0809E5B0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809E5A8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809E5B4 @ =gProjectileFnTable
	movs r0, #9
	strb r0, [r3, #9]
	ldr r0, [r1, #0x24]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x64]
	str r1, [r3, #0x68]
	str r6, [r3, #0x28]
_0809E5A8:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809E5B0: .4byte gProjectileHeaderPtr
_0809E5B4: .4byte gProjectileFnTable

	thumb_func_start _createBlazinEXFireBall
_createBlazinEXFireBall: @ 0x0809E5B8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _0809E618 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809E60E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809E61C @ =gProjectileFnTable
	movs r0, #9
	strb r0, [r3, #9]
	ldr r0, [r1, #0x24]
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
	adds r0, #0xb4
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x5c]
	str r1, [r3, #0x60]
	str r7, [r3, #0x28]
_0809E60E:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809E618: .4byte gProjectileHeaderPtr
_0809E61C: .4byte gProjectileFnTable

	thumb_func_start blazin_0809e620
blazin_0809e620: @ 0x0809E620
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r0, _0809E674 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809E66C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809E678 @ =gProjectileFnTable
	movs r0, #9
	strb r0, [r3, #9]
	ldr r0, [r1, #0x24]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x5c]
	str r1, [r3, #0x60]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_0809E66C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809E674: .4byte gProjectileHeaderPtr
_0809E678: .4byte gProjectileFnTable

	thumb_func_start Projectile9_Init
Projectile9_Init: @ 0x0809E67C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0xa]
	movs r1, #1
	movs r4, #0
	movs r6, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0809E6BC
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809E6B8 @ =0x0836AD60
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	b _0809E71E
	.align 2, 0
_0809E6B8: .4byte 0x0836AD60
_0809E6BC:
	cmp r0, #1
	bne _0809E6D4
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809E6D0 @ =0x0836ADF0
	b _0809E716
	.align 2, 0
_0809E6D0: .4byte 0x0836ADF0
_0809E6D4:
	cmp r0, #2
	bne _0809E6EC
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809E6E8 @ =0x0836ADC0
	b _0809E716
	.align 2, 0
_0809E6E8: .4byte 0x0836ADC0
_0809E6EC:
	cmp r0, #3
	bne _0809E704
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809E700 @ =0x0836ADA8
	b _0809E716
	.align 2, 0
_0809E700: .4byte 0x0836ADA8
_0809E704:
	cmp r0, #4
	bne _0809E726
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809E750 @ =0x0836AE80
_0809E716:
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
_0809E71E:
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_0809E726:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldr r1, _0809E754 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	movs r0, #0
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	bl Projectile9_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E750: .4byte 0x0836AE80
_0809E754: .4byte gProjectileFnTable

	thumb_func_start Projectile9_Update
Projectile9_Update: @ 0x0809E758
	push {lr}
	ldr r2, _0809E774 @ =0x0836AD4C
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
_0809E774: .4byte 0x0836AD4C

	thumb_func_start Projectile9_Die
Projectile9_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40
	.byte 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30
	.byte 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00
	.byte 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x70, 0x47
	.align 2, 0
	.4byte gProjectileFnTable

	thumb_func_start FUN_0809e7b4
FUN_0809e7b4:
	.byte 0x00, 0x22, 0x01, 0x21, 0x41, 0x73, 0x82, 0x73, 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_0809e7c0
FUN_0809e7c0: @ 0x0809E7C0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0809E824
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809E818
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0809E810 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _0809E814 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	b _0809E82A
	.align 2, 0
_0809E810: .4byte 0xFFFFF800
_0809E814: .4byte 0xFFFFFC00
_0809E818:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809E848
_0809E824:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
_0809E82A:
	bl CreateSmoke
	ldr r1, _0809E844 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809E9AE
	.align 2, 0
_0809E844: .4byte gProjectileFnTable
_0809E848:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809E854
	cmp r0, #1
	beq _0809E8C8
	b _0809E9AE
_0809E854:
	ldr r1, _0809E890 @ =0x0000A304
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0809E894
	movs r0, #0xc0
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	b _0809E8B8
	.align 2, 0
_0809E890: .4byte 0x0000A304
_0809E894:
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
_0809E8B8:
	strb r0, [r2]
	ldr r0, _0809E948 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x28
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809E8C8:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0809E8E2
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809E8E2
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809E94C @ =0x0836AD78
	bl SetDDP
_0809E8E2:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809E8F2
	str r1, [r4, #0x60]
_0809E8F2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809E916
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809E950 @ =0xFFFFFD00
	str r0, [r4, #0x60]
_0809E916:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809E954
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809E9A8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809E984
	movs r0, #0x10
	orrs r0, r2
	b _0809E988
	.align 2, 0
_0809E948: .4byte 0xFFFFFC00
_0809E94C: .4byte 0x0836AD78
_0809E950: .4byte 0xFFFFFD00
_0809E954:
	ldr r0, [r4, #0x54]
	ldr r1, _0809E980 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809E9A8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809E984
	movs r0, #0x10
	orrs r0, r2
	b _0809E988
	.align 2, 0
_0809E980: .4byte 0xFFFFF800
_0809E984:
	movs r0, #0xef
	ands r0, r2
_0809E988:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809E9A8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809E9AE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e9b8
FUN_0809e9b8:
	.byte 0x00, 0x22, 0x01, 0x21, 0x41, 0x73, 0x82, 0x73
	.byte 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_0809e9c4
FUN_0809e9c4: @ 0x0809E9C4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809E9D4
	cmp r0, #1
	beq _0809EA2A
	b _0809EACA
_0809E9D4:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	bl ResetDynamicMotion
	adds r2, r5, #0
	adds r2, #0xbc
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r2]
	adds r0, r5, #0
	adds r0, #0x50
	movs r4, #0
	strh r1, [r0]
	ldr r0, [r2]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, _0809EAD0 @ =0x0000A301
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r2]
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0xa
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EA2A:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	rsbs r1, r2, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r0, r2, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	adds r3, #4
	ldr r2, [r3]
	movs r1, #0xe0
	lsls r1, r1, #1
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	adds r0, r5, #0
	adds r0, #0x50
	strh r2, [r0]
	ldr r0, [r3]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, [r3]
	movs r0, #0xd0
	lsls r0, r0, #1
	cmp r1, r0
	ble _0809EA92
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0809EA92
	adds r0, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809EAD4 @ =0x0836AE38
	bl SetDDP
_0809EA92:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809EAB8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809EACA
_0809EAB8:
	ldr r1, _0809EAD8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809EACA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809EAD0: .4byte 0x0000A301
_0809EAD4: .4byte 0x0836AE38
_0809EAD8: .4byte gProjectileFnTable

	thumb_func_start FUN_0809eadc
FUN_0809eadc:
	.byte 0x00, 0x22, 0x01, 0x21
	.byte 0x41, 0x73, 0x82, 0x73, 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_0809eae8
FUN_0809eae8: @ 0x0809EAE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809EB3E
	cmp r0, #1
	bgt _0809EAFC
	cmp r0, #0
	beq _0809EB06
	b _0809EC04
_0809EAFC:
	cmp r0, #2
	beq _0809EBC6
	cmp r0, #3
	beq _0809EBE2
	b _0809EC04
_0809EB06:
	ldr r1, _0809EB74 @ =0x0000A302
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x64]
	movs r1, #0x36
	strb r1, [r4, #0x12]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x36
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0809EB78 @ =0x00016C80
	ldr r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x36
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x35
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809EB3E:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0809EB6A
	subs r0, #1
	movs r3, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809EB7C
_0809EB6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809EC04
	.align 2, 0
_0809EB74: .4byte 0x0000A302
_0809EB78: .4byte 0x00016C80
_0809EB7C:
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809EBA0
	str r3, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0809EBF2
_0809EBA0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809EC04
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809EC04
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	b _0809EBF2
_0809EBC6:
	ldr r1, _0809EC0C @ =0x0000A303
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809EC10 @ =0x0836ADD8
	bl SetDDP
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809EBE2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809EC04
_0809EBF2:
	ldr r1, _0809EC14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809EC04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809EC0C: .4byte 0x0000A303
_0809EC10: .4byte 0x0836ADD8
_0809EC14: .4byte gProjectileFnTable

	thumb_func_start FUN_0809ec18
FUN_0809ec18:
	.byte 0x00, 0x22, 0x01, 0x21, 0x41, 0x73, 0x82, 0x73
	.byte 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_0809ec24
FUN_0809ec24: @ 0x0809EC24
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0809EC8A
	cmp r0, #1
	bgt _0809EC38
	cmp r0, #0
	beq _0809EC3E
	b _0809EDF0
_0809EC38:
	cmp r0, #2
	beq _0809ED36
	b _0809EDF0
_0809EC3E:
	adds r0, r5, #0
	bl InitRotatableMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	adds r0, r5, #0
	adds r0, #0x50
	movs r4, #0x80
	lsls r4, r4, #1
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #0x62
	ldrb r1, [r0]
	subs r0, #0x90
	strb r1, [r0]
	ldr r1, _0809ECEC @ =0x0000A301
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	str r4, [r2]
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #6
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EC8A:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _0809EC9C
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bgt _0809ECCE
_0809EC9C:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	rsbs r1, r2, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r2, r0, r2
	asrs r2, r2, #8
	str r2, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r1, r0, r1
	asrs r1, r1, #8
	str r1, [r5, #0x68]
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0809ECCE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809ECE0
	subs r0, #1
	movs r3, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809ECF0
_0809ECE0:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809ED2E
	.align 2, 0
_0809ECEC: .4byte 0x0000A301
_0809ECF0:
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809ED14
	str r3, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0809EDDE
_0809ED14:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809ED2E
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809EDD4
_0809ED2E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0809EDF0
_0809ED36:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _0809ED48
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bgt _0809ED7E
_0809ED48:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r2, r0, r2
	asrs r2, r2, #8
	str r2, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r1, r0, r1
	asrs r1, r1, #8
	str r1, [r5, #0x68]
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0809ED7E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809EDDE
	subs r0, #1
	movs r3, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809EDDE
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809EDBA
	str r3, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0809EDDE
_0809EDBA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809EDF0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809EDF0
_0809EDD4:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_0809EDDE:
	ldr r1, _0809EDF8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809EDF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809EDF8: .4byte gProjectileFnTable

	thumb_func_start FUN_0809edfc
FUN_0809edfc: @ 0x0809EDFC
	movs r2, #0
	movs r1, #1
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809ee08
FUN_0809ee08: @ 0x0809EE08
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809EE22
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	b _0809EFEE
_0809EE22:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0809EE6E
	cmp r0, #1
	bgt _0809EE32
	cmp r0, #0
	beq _0809EE40
	b _0809F000
_0809EE32:
	cmp r0, #2
	bne _0809EE38
	b _0809EF4E
_0809EE38:
	cmp r0, #3
	bne _0809EE3E
	b _0809EFC4
_0809EE3E:
	b _0809F000
_0809EE40:
	ldr r1, _0809EEE0 @ =0x0000A305
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	movs r1, #0xa0
	lsls r1, r1, #3
	str r1, [r2]
	ldr r0, [r5, #0x5c]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EE6E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r6, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r1, r4
	bl PushoutToUp1
	str r0, [sp]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0809EEE4 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToDown1
	str r0, [sp, #4]
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #8]
	ldr r0, [r5, #0x54]
	ldr r3, _0809EEE4 @ =0xFFFFF800
	adds r0, r0, r3
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r2, r0, #0
	str r2, [sp, #0xc]
	ldr r1, [sp]
	cmp r1, #0
	beq _0809EEEE
	ldr r0, [r5, #0x68]
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EEE8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
	.align 2, 0
_0809EEE0: .4byte 0x0000A305
_0809EEE4: .4byte 0xFFFFF800
_0809EEE8:
	cmp r2, #0
	beq _0809EF2E
	b _0809EF22
_0809EEEE:
	ldr r1, [sp, #4]
	cmp r1, #0
	beq _0809EF12
	ldr r0, [r5, #0x68]
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EF0C
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
_0809EF0C:
	cmp r2, #0
	beq _0809EF2E
	b _0809EF22
_0809EF12:
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EF1E
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
_0809EF1E:
	cmp r2, #0
	beq _0809EF30
_0809EF22:
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
_0809EF26:
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x64]
	rsbs r0, r0, #0
	str r0, [r5, #0x64]
_0809EF2E:
	movs r6, #1
_0809EF30:
	cmp r6, #1
	bne _0809F000
	movs r0, #0
	bl PlaySound
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809F000
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809F000
_0809EF4E:
	adds r6, r5, #0
	adds r6, #0xb8
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r6]
	ldr r1, [r5, #0x28]
	ldr r2, [r1, #0x54]
	ldr r0, [r5, #0x54]
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r5, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809EFA4
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x60]
_0809EFA4:
	ldr r1, [r5, #0x5c]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EFC4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r2, r5, #0
	adds r2, #0xbc
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	cmp r0, #0
	bgt _0809F000
_0809EFEE:
	ldr r1, _0809F008 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809F000:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F008: .4byte gProjectileFnTable

	thumb_func_start createBlazinTail
createBlazinTail: @ 0x0809F00C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0809F054 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809F04A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809F058 @ =gProjectileFnTable
	movs r0, #0xa
	strb r0, [r3, #9]
	ldr r0, [r1, #0x28]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
	adds r0, r3, #0
	adds r0, #0xb4
	str r5, [r0]
_0809F04A:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F054: .4byte gProjectileHeaderPtr
_0809F058: .4byte gProjectileFnTable

	thumb_func_start BlazinTail_Init
BlazinTail_Init: @ 0x0809F05C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #2
	movs r6, #0
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0809F0B0 @ =0x0836AEC8
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r0, #0xb4
	movs r7, #0
	ldrsh r3, [r0, r7]
	adds r0, r5, #0
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0809F0B4 @ =FUN_0809f23c
	str r0, [r5, #0x24]
	ldr r1, _0809F0B8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r6, [r4, #0xd]
	strb r6, [r4, #0xe]
	strb r6, [r4, #0xf]
	adds r0, r4, #0
	bl BlazinTail_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809F0B0: .4byte 0x0836AEC8
_0809F0B4: .4byte FUN_0809f23c
_0809F0B8: .4byte gProjectileFnTable

	thumb_func_start BlazinTail_Update
BlazinTail_Update: @ 0x0809F0BC
	push {lr}
	adds r3, r0, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _0809F0E8
	ldr r1, _0809F0E4 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	adds r0, r3, #0
	bl BlazinTail_Die
	b _0809F108
	.align 2, 0
_0809F0E4: .4byte gProjectileFnTable
_0809F0E8:
	adds r2, r3, #0
	adds r2, #0xb8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	str r0, [r2]
	ldr r1, _0809F10C @ =0x0836AEC4
	ldrb r0, [r3, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
_0809F108:
	pop {r0}
	bx r0
	.align 2, 0
_0809F10C: .4byte 0x0836AEC4

	thumb_func_start BlazinTail_Die
BlazinTail_Die: @ 0x0809F110
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _0809F13C @ =gProjectileFnTable
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
_0809F13C: .4byte gProjectileFnTable

	thumb_func_start FUN_0809f140
FUN_0809f140: @ 0x0809F140
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0809F164
	ldr r1, _0809F160 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809F236
	.align 2, 0
_0809F160: .4byte gProjectileFnTable
_0809F164:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809F18A
	cmp r0, #1
	bgt _0809F174
	cmp r0, #0
	beq _0809F17A
	b _0809F236
_0809F174:
	cmp r0, #2
	beq _0809F1EC
	b _0809F236
_0809F17A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809F1A0 @ =0x0836AEE0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809F18A:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809F1A4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809F1AA
	.align 2, 0
_0809F1A0: .4byte 0x0836AEE0
_0809F1A4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809F1AA:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	ldrb r0, [r1, #0xd]
	cmp r0, #9
	bne _0809F236
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809F1E8 @ =0x0836AEC8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809F234
	.align 2, 0
_0809F1E8: .4byte 0x0836AEC8
_0809F1EC:
	ldrb r0, [r1, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809F200
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809F206
_0809F200:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809F206:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	ldrb r0, [r1, #0xd]
	cmp r0, #9
	beq _0809F236
	movs r0, #0
_0809F234:
	strb r0, [r4, #0xe]
_0809F236:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809f23c
FUN_0809f23c: @ 0x0809F23C
	push {lr}
	movs r3, #0
	ldr r2, [r0, #0x2c]
	adds r0, #0x23
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #1
	beq _0809F252
	cmp r1, #3
	bne _0809F282
_0809F252:
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, #0
	bne _0809F270
	ldr r0, _0809F26C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _0809F282
	b _0809F28E
	.align 2, 0
_0809F26C: .4byte pZero2
_0809F270:
	cmp r0, #1
	bne _0809F282
	ldr r0, _0809F294 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0809F282
	movs r3, #1
_0809F282:
	cmp r3, #0
	bne _0809F28E
	adds r1, r2, #0
	adds r1, #0xa4
	movs r0, #1
	strh r0, [r1]
_0809F28E:
	pop {r0}
	bx r0
	.align 2, 0
_0809F294: .4byte pZero2

	thumb_func_start createEarShot
createEarShot: @ 0x0809F298
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _0809F2E8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0809F2E0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809F2EC @ =gProjectileFnTable
	movs r0, #0xb
	strb r0, [r3, #9]
	ldr r0, [r1, #0x2c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	rsbs r0, r4, #0
	lsrs r0, r0, #0x1f
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x12]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
_0809F2E0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809F2E8: .4byte gProjectileHeaderPtr
_0809F2EC: .4byte gProjectileFnTable

	thumb_func_start nop_0809f2f0
nop_0809f2f0: @ 0x0809F2F0
	bx lr
	.align 2, 0

	thumb_func_start EarShot_Init
EarShot_Init: @ 0x0809F2F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0809F35C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0809F360 @ =0x0836AF74
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
	ldr r1, _0809F364 @ =0x0836AF14
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0809F33C
	adds r1, #0x18
_0809F33C:
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0809F368 @ =nop_0809f2f0
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl EarShot_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F35C: .4byte gProjectileFnTable
_0809F360: .4byte 0x0836AF74
_0809F364: .4byte 0x0836AF14
_0809F368: .4byte nop_0809f2f0

	thumb_func_start EarShot_Update
EarShot_Update: @ 0x0809F36C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809F398 @ =0x0836AF0C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809F39C @ =0x0836AF10
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809F398: .4byte 0x0836AF0C
_0809F39C: .4byte 0x0836AF10

	thumb_func_start EarShot_Die
EarShot_Die: @ 0x0809F3A0
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _0809F3CC @ =gProjectileFnTable
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
_0809F3CC: .4byte gProjectileFnTable

	thumb_func_start nop_0809f3d0
nop_0809f3d0: @ 0x0809F3D0
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809f3d4
FUN_0809f3d4: @ 0x0809F3D4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809F3E4
	cmp r0, #1
	beq _0809F44A
	b _0809F47C
_0809F3E4:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0809F3F6
	movs r1, #0x94
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _0809F3FE
_0809F3F6:
	ldr r1, _0809F418 @ =0x00002501
	adds r0, r4, #0
	bl SetMotion
_0809F3FE:
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0xb
	ldr r1, _0809F41C @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0809F420
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809F426
	.align 2, 0
_0809F418: .4byte 0x00002501
_0809F41C: .4byte 0xFFFFFC00
_0809F420:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809F426:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809F44A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _0809F484 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0809F47C
	ldr r1, _0809F488 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809F47C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809F484: .4byte gStageRun+232
_0809F488: .4byte gProjectileFnTable

	thumb_func_start FUN_0809f48c
FUN_0809f48c: @ 0x0809F48C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0809F4D4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809F4CC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809F4D8 @ =gProjectileFnTable
	movs r0, #0xc
	strb r0, [r3, #9]
	ldr r0, [r1, #0x30]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r5, [r3, #0x28]
_0809F4CC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F4D4: .4byte gProjectileHeaderPtr
_0809F4D8: .4byte gProjectileFnTable

	thumb_func_start FUN_0809f4dc
FUN_0809f4dc: @ 0x0809F4DC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809F53C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809F532
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809F540 @ =gProjectileFnTable
	movs r0, #0xc
	strb r0, [r3, #9]
	ldr r0, [r1, #0x30]
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
	ldr r1, [r4, #4]
	str r0, [r3, #0x5c]
	str r1, [r3, #0x60]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r7, [r3, #0x28]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r6, [r0]
_0809F532:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809F53C: .4byte gProjectileHeaderPtr
_0809F540: .4byte gProjectileFnTable

	thumb_func_start Projectile12_Init
Projectile12_Init: @ 0x0809F544
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	adds r0, #0x24
	movs r6, #0
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0xa]
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0809F590
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809F58C @ =0x0836AFA4
	b _0809F5A2
	.align 2, 0
_0809F58C: .4byte 0x0836AFA4
_0809F590:
	cmp r0, #1
	bne _0809F5B2
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809F5DC @ =0x0836AFBC
_0809F5A2:
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_0809F5B2:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldr r1, _0809F5E0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	movs r0, #0
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	bl Projectile12_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F5DC: .4byte 0x0836AFBC
_0809F5E0: .4byte gProjectileFnTable

	thumb_func_start Projectile12_Update
Projectile12_Update: @ 0x0809F5E4
	push {lr}
	ldr r2, _0809F600 @ =0x0836AF9C
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
_0809F600: .4byte 0x0836AF9C

	thumb_func_start Projectile12_Die
Projectile12_Die: @ 0x0809F604
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
	ldr r1, _0809F63C @ =gProjectileFnTable
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
_0809F63C: .4byte gProjectileFnTable

	thumb_func_start FUN_0809f640
FUN_0809f640: @ 0x0809F640
	movs r2, #0
	movs r1, #1
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809f64c
FUN_0809f64c: @ 0x0809F64C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809F67E
	cmp r0, #1
	bgt _0809F660
	cmp r0, #0
	beq _0809F66C
	b _0809F7BE
_0809F660:
	cmp r0, #2
	beq _0809F6A0
	cmp r0, #3
	bne _0809F66A
	b _0809F780
_0809F66A:
	b _0809F7BE
_0809F66C:
	ldr r1, _0809F69C @ =0x0000A601
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809F67E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0809F696
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809F696
	b _0809F7BE
_0809F696:
	movs r0, #0xa0
	strb r0, [r4, #0x12]
	b _0809F774
	.align 2, 0
_0809F69C: .4byte 0x0000A601
_0809F6A0:
	ldr r0, _0809F744 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _0809F6EE
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_0809F6EE:
	ldr r0, [r4, #0x5c]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #6
	asrs r2, r2, #8
	str r2, [r4, #0x64]
	ldr r0, [r4, #0x60]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	asrs r1, r1, #8
	str r1, [r4, #0x68]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r3, #0
	strb r0, [r4, #0x12]
	movs r5, #0xff
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809F730
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809F748
_0809F730:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	orrs r0, r5
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	b _0809F766
	.align 2, 0
_0809F744: .4byte pZero2
_0809F748:
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	ldr r1, _0809F77C @ =0x00400100
	ands r0, r1
	cmp r0, #0
	beq _0809F7BE
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	orrs r0, r5
	strb r0, [r4, #0x13]
	str r3, [r2]
	adds r0, r4, #0
	adds r0, #0x90
_0809F766:
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_0809F774:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809F7BE
	.align 2, 0
_0809F77C: .4byte 0x00400100
_0809F780:
	ldrb r1, [r4, #0x13]
	rsbs r0, r1, #0
	asrs r0, r0, #4
	adds r1, r1, r0
	strb r1, [r4, #0x13]
	ldrb r1, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809F7BE
	ldr r1, _0809F7C4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809F7BE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F7C4: .4byte gProjectileFnTable

	thumb_func_start FUN_0809f7c8
FUN_0809f7c8: @ 0x0809F7C8
	movs r2, #0
	movs r1, #1
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809f7d4
FUN_0809f7d4: @ 0x0809F7D4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809F7F8
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_0809F7F8:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809F804
	cmp r0, #1
	beq _0809F854
	b _0809F8A0
_0809F804:
	movs r1, #0xa6
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0xa
	asrs r0, r0, #8
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #0xa
	asrs r0, r0, #8
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	subs r0, #0x90
	strb r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809F854:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809F8A0
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809F8A8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809F8A0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809F8A8: .4byte gProjectileFnTable

	thumb_func_start FUN_0809f8ac
FUN_0809f8ac: @ 0x0809F8AC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r4, #0
	movs r5, #0
	ldr r7, _0809F8F4 @ =gProjectileFnTable
_0809F8B6:
	ldr r0, _0809F8F8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r1, r0, #0
	cmp r1, #0
	beq _0809F8E6
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #8
	strb r0, [r2]
	movs r0, #0xd
	strb r0, [r1, #9]
	ldr r0, [r7, #0x34]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r5, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r5, [r0]
	movs r0, #5
	strb r0, [r1, #0x10]
	strb r4, [r1, #0x12]
	str r6, [r1, #0x28]
_0809F8E6:
	adds r4, #1
	cmp r4, #3
	ble _0809F8B6
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809F8F4: .4byte gProjectileFnTable
_0809F8F8: .4byte gProjectileHeaderPtr

	thumb_func_start FUN_0809f8fc
FUN_0809f8fc: @ 0x0809F8FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809F964 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0809F95C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809F968 @ =gProjectileFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	ldr r1, _0809F96C @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r3, #0x5c]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	rsbs r0, r0, #0
	str r0, [r3, #0x60]
_0809F95C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F964: .4byte gProjectileHeaderPtr
_0809F968: .4byte gProjectileFnTable
_0809F96C: .4byte gSineTable

	thumb_func_start FUN_0809f970
FUN_0809f970: @ 0x0809F970
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809F9D8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0809F9D2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809F9DC @ =gProjectileFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x64]
	str r6, [r3, #0x68]
	ldr r2, _0809F9E0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809F9E4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809F9E8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #4
	lsrs r0, r0, #0x15
	ldr r1, _0809F9EC @ =0xFFFFFC00
	adds r0, r0, r1
	adds r0, r5, r0
	str r0, [r3, #0x54]
	str r6, [r3, #0x58]
_0809F9D2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F9D8: .4byte gProjectileHeaderPtr
_0809F9DC: .4byte gProjectileFnTable
_0809F9E0: .4byte RNG_0202f388
_0809F9E4: .4byte 0x000343FD
_0809F9E8: .4byte 0x00269EC3
_0809F9EC: .4byte 0xFFFFFC00

	thumb_func_start babyelf_0809f9f0
babyelf_0809f9f0: @ 0x0809F9F0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _0809FA3C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0809FA36
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809FA40 @ =gProjectileFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
	str r7, [r3, #0x28]
_0809FA36:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FA3C: .4byte gProjectileHeaderPtr
_0809FA40: .4byte gProjectileFnTable

	thumb_func_start FUN_0809fa44
FUN_0809fa44: @ 0x0809FA44
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809FA94 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0809FA8E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809FA98 @ =gProjectileFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r6, [r3, #0x12]
	str r4, [r3, #0x64]
	str r5, [r3, #0x68]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r7, [r3, #0x28]
_0809FA8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FA94: .4byte gProjectileHeaderPtr
_0809FA98: .4byte gProjectileFnTable

	thumb_func_start FUN_0809fa9c
FUN_0809fa9c: @ 0x0809FA9C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _0809FAE8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0809FAE2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809FAEC @ =gProjectileFnTable
	movs r0, #0xd
	strb r0, [r3, #9]
	ldr r0, [r1, #0x34]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	str r7, [r3, #0x28]
_0809FAE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FAE8: .4byte gProjectileHeaderPtr
_0809FAEC: .4byte gProjectileFnTable

	thumb_func_start nop_0809faf0
nop_0809faf0: @ 0x0809FAF0
	bx lr
	.align 2, 0

	thumb_func_start Projectile13_Init
Projectile13_Init: @ 0x0809FAF4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0809FB54 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0809FB58 @ =0x0836B0C8
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
	ldr r1, _0809FB5C @ =0x0836B050
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0809FB60 @ =nop_0809faf0
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl Projectile13_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809FB54: .4byte gProjectileFnTable
_0809FB58: .4byte 0x0836B0C8
_0809FB5C: .4byte 0x0836B050
_0809FB60: .4byte nop_0809faf0

	thumb_func_start Projectile13_Update
Projectile13_Update: @ 0x0809FB64
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809FB90 @ =0x0836B018
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809FB94 @ =0x0836B034
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809FB90: .4byte 0x0836B018
_0809FB94: .4byte 0x0836B034

	thumb_func_start Projectile13_Die
Projectile13_Die: @ 0x0809FB98
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _0809FBD4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809FBD4: .4byte gProjectileFnTable

	thumb_func_start nop_0809fbd8
nop_0809fbd8: @ 0x0809FBD8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809fbdc
FUN_0809fbdc: @ 0x0809FBDC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809FC16
	cmp r0, #1
	bgt _0809FBF0
	cmp r0, #0
	beq _0809FBFA
	b _0809FCF0
_0809FBF0:
	cmp r0, #2
	beq _0809FC48
	cmp r0, #3
	beq _0809FC6A
	b _0809FCF0
_0809FBFA:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809FC40 @ =0x0836B050
	bl SetDDP
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldr r1, _0809FC44 @ =0x00003308
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FC16:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809FC28
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FC28:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0809FCF0
	.align 2, 0
_0809FC40: .4byte 0x0836B050
_0809FC44: .4byte 0x00003308
_0809FC48:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FC6A:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #4
	bls _0809FC82
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0809FC92
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0809FC98
_0809FC82:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0809FC92
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0809FC98
_0809FC92:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809FC98:
	strb r0, [r4, #0xa]
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0809FCDA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809FCF8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809FCDA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809FCF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809FCF8: .4byte gProjectileFnTable

	thumb_func_start FUN_0809fcfc
FUN_0809fcfc: @ 0x0809FCFC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0809FD08
	b _0809FF6A
_0809FD08:
	lsls r0, r0, #2
	ldr r1, _0809FD14 @ =_0809FD18
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809FD14: .4byte _0809FD18
_0809FD18: @ jump table
	.4byte _0809FD30 @ case 0
	.4byte _0809FD66 @ case 1
	.4byte _0809FE40 @ case 2
	.4byte _0809FE70 @ case 3
	.4byte _0809FEDC @ case 4
	.4byte _0809FEE6 @ case 5
_0809FD30:
	movs r0, #8
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809FE20 @ =0x0836B068
	bl SetDDP
	ldr r2, _0809FE24 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809FE28 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _0809FE2C @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	ldr r0, _0809FE30 @ =0x00003203
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FD66:
	ldrb r2, [r4, #0x12]
	cmp r2, #2
	bhi _0809FD8A
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0809FD8A
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809FD8A
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x68]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	bl FUN_0809f970
_0809FD8A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #4
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _0809FDC4
	ldr r5, _0809FE34 @ =pZero2
	ldr r0, [r5]
	movs r1, #0
	bl makeZeroSlower
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5f
	bhi _0809FDC4
	ldr r2, [r5]
	ldr r0, [r4, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x58]
	ldr r1, [r2, #0x58]
	subs r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FDC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809FE38 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bhi _0809FDE8
	b _0809FF6A
_0809FDE8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809FE3C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0809FF6A
	.align 2, 0
_0809FE20: .4byte 0x0836B068
_0809FE24: .4byte RNG_0202f388
_0809FE28: .4byte 0x000343FD
_0809FE2C: .4byte 0x00269EC3
_0809FE30: .4byte 0x00003203
_0809FE34: .4byte pZero2
_0809FE38: .4byte gStageRun+232
_0809FE3C: .4byte gProjectileFnTable
_0809FE40:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _0809FED8 @ =pZero2
	ldr r0, [r0]
	movs r1, #0xc
	bl makeZeroSlower
	movs r0, #0x80
	strb r0, [r4, #0x12]
	movs r0, #0x18
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FE70:
	ldr r5, _0809FED8 @ =pZero2
	ldr r0, [r5]
	ldr r1, [r0, #0x54]
	ldr r2, [r4, #0x64]
	adds r1, r1, r2
	str r1, [r4, #0x54]
	ldr r1, [r0, #0x58]
	ldr r2, [r4, #0x68]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl CountButtonMashing
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809FEC0
	cmp r1, #0
	blt _0809FEC0
	ldr r2, [r5]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0809FEC0
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0809FED0
_0809FEC0:
	ldr r0, _0809FED8 @ =pZero2
	ldr r0, [r0]
	movs r1, #0xc
	bl makeZeroFaster
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FED0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0809FF6A
	.align 2, 0
_0809FED8: .4byte pZero2
_0809FEDC:
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809FEE6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0809FF28
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809FF3C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809FF28:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809FF40
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0809FF46
	.align 2, 0
_0809FF3C: .4byte gProjectileFnTable
_0809FF40:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809FF46:
	strb r0, [r4, #0xa]
	ldr r0, _0809FF70 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x68]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809FF6A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809FF70: .4byte pZero2

	thumb_func_start FUN_0809ff74
FUN_0809ff74: @ 0x0809FF74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #7
	bls _0809FF80
	b _080A01D8
_0809FF80:
	lsls r0, r0, #2
	ldr r1, _0809FF8C @ =_0809FF90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809FF8C: .4byte _0809FF90
_0809FF90: @ jump table
	.4byte _0809FFB0 @ case 0
	.4byte _080A0012 @ case 1
	.4byte _080A0030 @ case 2
	.4byte _080A0042 @ case 3
	.4byte _080A00D4 @ case 4
	.4byte _080A00DE @ case 5
	.4byte _080A016C @ case 6
	.4byte _080A0182 @ case 7
_0809FFB0:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0809FFD0 @ =0x0836B080
	bl SetDDP
	ldrb r1, [r6, #0x12]
	movs r0, #1
	adds r2, r0, #0
	eors r2, r1
	cmp r2, #0
	beq _0809FFD4
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809FFDA
	.align 2, 0
_0809FFD0: .4byte 0x0836B080
_0809FFD4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809FFDA:
	strb r0, [r6, #0xa]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r5, r6, #0
	adds r5, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x22
	strb r3, [r0]
	str r4, [r6, #0x60]
	ldr r1, _080A002C @ =0x00003101
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A0012:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080A0024
	b _080A01D8
_080A0024:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A01D8
	.align 2, 0
_080A002C: .4byte 0x00003101
_080A0030:
	movs r0, #0
	strb r0, [r6, #0x13]
	ldr r1, _080A0080 @ =0x00003102
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A0042:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2a
	bls _080A0056
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A0056:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080A0088
	ldr r4, _080A0084 @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #4
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	b _080A00A8
	.align 2, 0
_080A0080: .4byte 0x00003102
_080A0084: .4byte gSineTable
_080A0088:
	ldr r4, _080A00D0 @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #4
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
_080A00A8:
	str r0, [r6, #0x54]
	adds r5, r4, #0
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #4
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	b _080A015C
	.align 2, 0
_080A00D0: .4byte gSineTable
_080A00D4:
	movs r0, #0
	str r0, [r6, #0x64]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A00DE:
	ldr r0, [r6, #0x64]
	adds r0, #3
	str r0, [r6, #0x64]
	cmp r0, #0xaa
	ble _080A00EE
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A00EE:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080A011C
	ldr r5, _080A0118 @ =gSineTable
	ldr r4, [r6, #0x64]
	lsls r0, r4, #4
	subs r0, r0, r4
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	b _080A013E
	.align 2, 0
_080A0118: .4byte gSineTable
_080A011C:
	ldr r5, _080A0168 @ =gSineTable
	ldr r4, [r6, #0x64]
	lsls r0, r4, #4
	subs r0, r0, r4
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
_080A013E:
	str r0, [r6, #0x54]
	lsls r0, r4, #4
	subs r0, r0, r4
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
_080A015C:
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _080A01D8
	.align 2, 0
_080A0168: .4byte gSineTable
_080A016C:
	movs r2, #0xc0
	lsls r2, r2, #2
	ldrb r1, [r6, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #9
	subs r2, r2, r0
	str r2, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A0182:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A01F4 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080A01D2
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A01F8 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080A01D2:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080A01D8:
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A0250
	ldr r0, [r6, #0x60]
	adds r1, r0, #1
	str r1, [r6, #0x60]
	cmp r1, #0xf
	ble _080A01FC
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _080A0204
	b _080A020C
	.align 2, 0
_080A01F4: .4byte gStageRun+232
_080A01F8: .4byte gProjectileFnTable
_080A01FC:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080A020C
_080A0204:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A0212
_080A020C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A0212:
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x60]
	cmp r0, #0x1e
	ble _080A0250
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A0258 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080A0250:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A0258: .4byte gProjectileFnTable

	thumb_func_start FUN_080a025c
FUN_080a025c: @ 0x080A025C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A029E
	cmp r0, #1
	bgt _080A0274
	cmp r0, #0
	beq _080A027E
	b _080A039A
_080A0274:
	cmp r0, #2
	beq _080A02C0
	cmp r0, #3
	beq _080A02D2
	b _080A039A
_080A027E:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A02B8 @ =0x0836B098
	bl SetDDP
	ldr r1, _080A02BC @ =0x00003401
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A029E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A039A
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A039A
	.align 2, 0
_080A02B8: .4byte 0x0836B098
_080A02BC: .4byte 0x00003401
_080A02C0:
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r1, _080A03A4 @ =0x00003402
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A02D2:
	ldrb r3, [r4, #0x12]
	cmp r3, #1
	bhi _080A02F8
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080A02F8
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A02F8
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x68]
	adds r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r7, #0
	bl FUN_0809fa44
_080A02F8:
	ldr r1, [r4, #0x58]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080A0394
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A03A8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080A037C
	movs r6, #0x80
	lsls r6, r6, #0x16
	movs r5, #2
_080A0356:
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	lsrs r0, r6, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_080bc6ac
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r6, r6, r0
	subs r5, #1
	cmp r5, #0
	bge _080A0356
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080bc758
_080A037C:
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	adds r0, r7, #0
	movs r3, #0
	bl FUN_0809fa9c
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_0809fa9c
_080A0394:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A039A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A03A4: .4byte 0x00003402
_080A03A8: .4byte gProjectileFnTable

	thumb_func_start FUN_080a03ac
FUN_080a03ac: @ 0x080A03AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080A03BC
	cmp r5, #1
	beq _080A03EC
	b _080A0442
_080A03BC:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A0460 @ =0x0836B098
	bl SetDDP
	ldr r1, _080A0464 @ =0x00003403
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _080A0468 @ =0xFFFFFC80
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A03EC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _080A046C @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080A043C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A0470 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A043C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A0442:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A04C8
	ldr r0, [r4, #0x60]
	adds r1, r0, #1
	str r1, [r4, #0x60]
	cmp r1, #0xf
	ble _080A0474
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _080A047C
	b _080A0484
	.align 2, 0
_080A0460: .4byte 0x0836B098
_080A0464: .4byte 0x00003403
_080A0468: .4byte 0xFFFFFC80
_080A046C: .4byte gStageRun+232
_080A0470: .4byte gProjectileFnTable
_080A0474:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080A0484
_080A047C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A048A
_080A0484:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A048A:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x60]
	cmp r0, #0x1e
	ble _080A04C8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A04D0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A04C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A04D0: .4byte gProjectileFnTable

	thumb_func_start FUN_080a04d4
FUN_080a04d4: @ 0x080A04D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080A04EC
	b _080A05F4
_080A04EC:
	lsls r0, r0, #2
	ldr r1, _080A04F8 @ =_080A04FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A04F8: .4byte _080A04FC
_080A04FC: @ jump table
	.4byte _080A0514 @ case 0
	.4byte _080A053E @ case 1
	.4byte _080A055C @ case 2
	.4byte _080A056E @ case 3
	.4byte _080A05CC @ case 4
	.4byte _080A05D2 @ case 5
_080A0514:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A0550 @ =0x0836B098
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x68]
	ldr r1, _080A0554 @ =0x0836B0CE
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x5c]
	ldr r1, _080A0558 @ =0x00003401
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A053E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A05F4
	b _080A05B2
	.align 2, 0
_080A0550: .4byte 0x0836B098
_080A0554: .4byte 0x0836B0CE
_080A0558: .4byte 0x00003401
_080A055C:
	movs r0, #0
	str r0, [r4, #0x64]
	ldr r1, _080A05BC @ =0x00003402
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A056E:
	ldr r0, [r4, #0x64]
	adds r0, #4
	str r0, [r4, #0x64]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080A057E
	str r1, [r4, #0x64]
_080A057E:
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x68]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0xce
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A05F4
	ldr r1, [r4, #0x68]
	adds r0, r1, #0
	cmp r1, #0
	bge _080A05A2
	ldr r2, _080A05C0 @ =0x0000FFFF
	adds r0, r1, r2
_080A05A2:
	asrs r0, r0, #0x10
	lsls r0, r0, #0x10
	subs r0, r1, r0
	ldr r3, _080A05C4 @ =0xFFFFA100
	adds r0, r0, r3
	ldr r1, _080A05C8 @ =0x000001FF
	cmp r0, r1
	bhi _080A05F4
_080A05B2:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A05F4
	.align 2, 0
_080A05BC: .4byte 0x00003402
_080A05C0: .4byte 0x0000FFFF
_080A05C4: .4byte 0xFFFFA100
_080A05C8: .4byte 0x000001FF
_080A05CC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A05D2:
	ldr r0, [r4, #0x64]
	adds r1, r0, #0
	subs r1, #0x10
	str r1, [r4, #0x64]
	cmp r1, #0
	bne _080A05E6
	str r1, [r4, #0x68]
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A05E6:
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x68]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A05F4:
	ldr r1, [r7, #0x54]
	str r1, [r4, #0x54]
	ldr r5, _080A06B8 @ =gSineTable
	ldr r0, [r4, #0x68]
	asrs r3, r0, #8
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r2, [r4, #0x5c]
	muls r0, r2, r0
	cmp r0, #0
	bge _080A0616
	adds r0, #0xff
_080A0616:
	asrs r0, r0, #8
	adds r0, r1, r0
	str r0, [r4, #0x54]
	ldr r1, [r7, #0x58]
	str r1, [r4, #0x58]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	bge _080A0632
	adds r0, #0xff
_080A0632:
	asrs r0, r0, #8
	adds r0, r1, r0
	str r0, [r4, #0x58]
	ldrb r0, [r7, #0xc]
	cmp r0, #1
	bls _080A06A8
	movs r0, #0x8c
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0x90
	adds r1, r1, r4
	mov sb, r1
	movs r2, #0x94
	adds r2, r2, r4
	mov sl, r2
	movs r6, #0x80
	lsls r6, r6, #0x16
	movs r5, #3
_080A0656:
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	lsrs r0, r6, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_080bc6ac
	movs r3, #0x80
	lsls r3, r3, #0x17
	adds r6, r6, r3
	subs r5, #1
	cmp r5, #0
	bge _080A0656
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	mov r0, r8
	str r2, [r0]
	mov r1, sb
	str r2, [r1]
	mov r3, sl
	strb r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A06BC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A06A8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A06B8: .4byte gSineTable
_080A06BC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a06c0
FUN_080a06c0: @ 0x080A06C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	mov sl, r0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _080A0700
	cmp r0, #1
	bgt _080A06E2
	cmp r0, #0
	beq _080A06EC
	b _080A0802
_080A06E2:
	cmp r0, #2
	beq _080A071C
	cmp r0, #3
	beq _080A077C
	b _080A0802
_080A06EC:
	ldr r1, _080A0718 @ =0x0836B0D6
	ldrb r0, [r7, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r7, #0x64]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A0700:
	ldr r0, [r7, #0x64]
	subs r0, #1
	str r0, [r7, #0x64]
	cmp r0, #0
	bne _080A0710
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A0710:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _080A0802
	.align 2, 0
_080A0718: .4byte 0x0836B0D6
_080A071C:
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _080A0880 @ =pZero2
	ldr r1, [r0]
	ldr r5, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r5, r5, r0
	ldr r0, [r7, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r6, [r1, #0x58]
	subs r6, r6, r0
	asrs r0, r5, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r6, #8
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #8
	lsls r5, r5, #8
	adds r0, r5, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	lsls r6, r6, #8
	adds r0, r6, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A077C:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, [r7, #0x60]
	adds r1, r1, r2
	str r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A07FC
	adds r6, r7, #0
	adds r6, #0x8c
	movs r0, #0x90
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x94
	adds r1, r1, r7
	mov sb, r1
	movs r5, #0x80
	lsls r5, r5, #0x16
	movs r4, #2
_080A07AC:
	ldr r1, [r7, #0x54]
	ldr r2, [r7, #0x58]
	lsrs r0, r5, #0x18
	str r0, [sp]
	mov r0, sl
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_080bc6ac
	movs r2, #0x80
	lsls r2, r2, #0x16
	adds r5, r5, r2
	subs r4, #1
	cmp r4, #0
	bge _080A07AC
	movs r4, #3
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	str r2, [r6]
	mov r0, r8
	str r2, [r0]
	mov r1, sb
	strb r2, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080A0884 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080A07FC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080A0802:
	mov r2, sl
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bls _080A0870
	adds r6, r7, #0
	adds r6, #0x8c
	movs r0, #0x90
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0x94
	adds r1, r1, r7
	mov sb, r1
	movs r5, #0x80
	lsls r5, r5, #0x16
	movs r4, #3
_080A0820:
	ldr r1, [r7, #0x54]
	ldr r2, [r7, #0x58]
	lsrs r0, r5, #0x18
	str r0, [sp]
	mov r0, sl
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_080bc6ac
	movs r2, #0x80
	lsls r2, r2, #0x17
	adds r5, r5, r2
	subs r4, #1
	cmp r4, #0
	bge _080A0820
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	str r2, [r6]
	mov r0, r8
	str r2, [r0]
	mov r1, sb
	strb r2, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080A0884 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080A0870:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0880: .4byte pZero2
_080A0884: .4byte gProjectileFnTable

	thumb_func_start FUN_080a0888
FUN_080a0888: @ 0x080A0888
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080A08D8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A08D0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A08DC @ =gProjectileFnTable
	movs r0, #0xe
	strb r0, [r3, #9]
	ldr r0, [r1, #0x38]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
	strb r5, [r3, #0x12]
	strb r4, [r3, #0x13]
_080A08D0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A08D8: .4byte gProjectileHeaderPtr
_080A08DC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a08e0
FUN_080a08e0: @ 0x080A08E0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080A092C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A0924
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A0930 @ =gProjectileFnTable
	movs r0, #0xe
	strb r0, [r3, #9]
	ldr r0, [r1, #0x38]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
	str r7, [r3, #0x28]
_080A0924:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A092C: .4byte gProjectileHeaderPtr
_080A0930: .4byte gProjectileFnTable

	thumb_func_start deathtanz_080a0934
deathtanz_080a0934: @ 0x080A0934
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, [sp, #0x18]
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080A0998 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A098C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A099C @ =gProjectileFnTable
	movs r0, #0xe
	strb r0, [r3, #9]
	ldr r0, [r1, #0x38]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
	strb r4, [r3, #0x12]
	mov r0, r8
	str r0, [r3, #0x28]
	adds r0, r3, #0
	adds r0, #0xbc
	strb r5, [r0]
_080A098C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0998: .4byte gProjectileHeaderPtr
_080A099C: .4byte gProjectileFnTable

	thumb_func_start deathtanz_080a09a0
deathtanz_080a09a0: @ 0x080A09A0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080A09EC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A09E6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A09F0 @ =gProjectileFnTable
	movs r0, #0xe
	strb r0, [r3, #9]
	ldr r0, [r1, #0x38]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
	str r7, [r3, #0x28]
_080A09E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A09EC: .4byte gProjectileHeaderPtr
_080A09F0: .4byte gProjectileFnTable

	thumb_func_start deathtanz_080a09f4
deathtanz_080a09f4: @ 0x080A09F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, [sp, #0x18]
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080A0A54 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A0A48
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A0A58 @ =gProjectileFnTable
	movs r0, #0xe
	strb r0, [r3, #9]
	ldr r0, [r1, #0x38]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x10]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
	strb r5, [r3, #0x12]
	strb r4, [r3, #0x13]
	mov r0, r8
	str r0, [r3, #0x28]
_080A0A48:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A0A54: .4byte gProjectileHeaderPtr
_080A0A58: .4byte gProjectileFnTable
_080A0A5C:
	.byte 0x70, 0x47, 0x00, 0x00

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
	ldr r1, _080A0AE4 @ =0x0836B20C
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
	ldr r1, _080A0AE8 @ =0x0836B11C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080A0AEC @ =0x080A0A5D
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
_080A0AE4: .4byte 0x0836B20C
_080A0AE8: .4byte 0x0836B11C
_080A0AEC: .4byte 0x080A0A5D

	thumb_func_start Projectile14_Update
Projectile14_Update: @ 0x080A0AF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A0B1C @ =0x0836B0F4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080A0B20 @ =0x0836B108
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0B1C: .4byte 0x0836B0F4
_080A0B20: .4byte 0x0836B108

	thumb_func_start Projectile14_Die
Projectile14_Die: @ 0x080A0B24
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080A0B68 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0B68: .4byte gProjectileFnTable

	thumb_func_start nop_080a0b6c
nop_080a0b6c: @ 0x080A0B6C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a0b70
FUN_080a0b70: @ 0x080A0B70
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bls _080A0B7E
	b _080A0D88
_080A0B7E:
	lsls r0, r0, #2
	ldr r1, _080A0B88 @ =_080A0B8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0B88: .4byte _080A0B8C
_080A0B8C: @ jump table
	.4byte _080A0BB4 @ case 0
	.4byte _080A0BD4 @ case 1
	.4byte _080A0C18 @ case 2
	.4byte _080A0C30 @ case 3
	.4byte _080A0C78 @ case 4
	.4byte _080A0CA4 @ case 5
	.4byte _080A0CF4 @ case 6
	.4byte _080A0D02 @ case 7
	.4byte _080A0D36 @ case 8
	.4byte _080A0D40 @ case 9
_080A0BB4:
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A0BF8 @ =0x0836B11C
	bl SetDDP
	movs r0, #0x80
	str r0, [r4, #0x5c]
	ldr r1, _080A0BFC @ =0x00003701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0BD4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0C00
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xd0
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	bgt _080A0BF4
	b _080A0D88
_080A0BF4:
	b _080A0CE6
	.align 2, 0
_080A0BF8: .4byte 0x0836B11C
_080A0BFC: .4byte 0x00003701
_080A0C00:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080A0C14 @ =0xFFFF9800
	b _080A0CE0
	.align 2, 0
_080A0C14: .4byte 0xFFFF9800
_080A0C18:
	movs r2, #0
	ldr r0, _080A0C54 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x58]
	ldr r0, [r4, #0x58]
	cmp r1, r0
	ble _080A0C28
	movs r2, #1
_080A0C28:
	strb r2, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0C30:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080A0C58
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #8
	adds r0, r0, r2
	cmp r1, r0
	bgt _080A0C50
	b _080A0D88
_080A0C50:
	str r0, [r4, #0x58]
	b _080A0CE8
	.align 2, 0
_080A0C54: .4byte pZero2
_080A0C58:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _080A0C74 @ =0xFFFF7000
	adds r0, r0, r2
	cmp r1, r0
	blt _080A0C70
	b _080A0D88
_080A0C70:
	str r0, [r4, #0x58]
	b _080A0CE8
	.align 2, 0
_080A0C74: .4byte 0xFFFF7000
_080A0C78:
	ldr r2, _080A0CC4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080A0CC8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080A0CCC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	ldr r1, [r4, #0x5c]
	muls r0, r1, r0
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	movs r1, #1
	eors r0, r1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0CA4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0CD0
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xb0
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	ble _080A0D88
	b _080A0CE6
	.align 2, 0
_080A0CC4: .4byte RNG_0202f388
_080A0CC8: .4byte 0x000343FD
_080A0CCC: .4byte 0x00269EC3
_080A0CD0:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080A0CF0 @ =0xFFFFA800
_080A0CE0:
	adds r0, r0, r2
	cmp r1, r0
	bge _080A0D88
_080A0CE6:
	str r0, [r4, #0x54]
_080A0CE8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A0D88
	.align 2, 0
_080A0CF0: .4byte 0xFFFFA800
_080A0CF4:
	ldrb r0, [r4, #0x13]
	movs r1, #1
	eors r0, r1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0D02:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080A0D18
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	cmp r0, r1
	ble _080A0D88
	b _080A0D26
_080A0D18:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	cmp r0, r1
	bge _080A0D88
_080A0D26:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	adds r1, r5, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
	b _080A0D88
_080A0D36:
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0D40:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A0D88
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A0D84 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080A0DB4
	.align 2, 0
_080A0D84: .4byte gProjectileFnTable
_080A0D88:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	adds r0, #0x30
	str r0, [r4, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	ble _080A0D9E
	str r1, [r4, #0x5c]
_080A0D9E:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A0DB6
	ldr r1, _080A0DBC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_080A0DB4:
	str r0, [r4, #0x14]
_080A0DB6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0DBC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a0dc0
FUN_080a0dc0: @ 0x080A0DC0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _080A0DCE
	b _080A0F70
_080A0DCE:
	lsls r0, r0, #2
	ldr r1, _080A0DD8 @ =_080A0DDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0DD8: .4byte _080A0DDC
_080A0DDC: @ jump table
	.4byte _080A0DFC @ case 0
	.4byte _080A0E1C @ case 1
	.4byte _080A0E68 @ case 2
	.4byte _080A0E88 @ case 3
	.4byte _080A0E96 @ case 4
	.4byte _080A0EEC @ case 5
	.4byte _080A0F1E @ case 6
	.4byte _080A0F28 @ case 7
_080A0DFC:
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A0E40 @ =0x0836B11C
	bl SetDDP
	movs r0, #0x80
	str r0, [r4, #0x5c]
	ldr r1, _080A0E44 @ =0x00003701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0E1C:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0E48
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xd0
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	bgt _080A0E3C
	b _080A0F70
_080A0E3C:
	b _080A0EDE
	.align 2, 0
_080A0E40: .4byte 0x0836B11C
_080A0E44: .4byte 0x00003701
_080A0E48:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080A0E64 @ =0xFFFF9800
	adds r0, r0, r2
	cmp r1, r0
	blt _080A0E60
	b _080A0F70
_080A0E60:
	b _080A0EDE
	.align 2, 0
_080A0E64: .4byte 0xFFFF9800
_080A0E68:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _080A0E84 @ =0xFFFF7000
	adds r0, r0, r2
	cmp r1, r0
	bge _080A0F70
	str r0, [r4, #0x58]
	b _080A0EDE
	.align 2, 0
_080A0E84: .4byte 0xFFFF7000
_080A0E88:
	ldrb r0, [r4, #0x12]
	movs r1, #1
	eors r0, r1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0E96:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0EC0
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r2, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	lsls r0, r0, #0xb
	ldr r1, _080A0EBC @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r1, r1, r0
	cmp r2, r1
	ble _080A0F70
	b _080A0EDC
	.align 2, 0
_080A0EBC: .4byte 0xFFFFF800
_080A0EC0:
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r2, r2, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	lsls r0, r0, #0xb
	ldr r1, _080A0EE8 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	cmp r2, r1
	bge _080A0F70
_080A0EDC:
	str r1, [r4, #0x54]
_080A0EDE:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A0F70
	.align 2, 0
_080A0EE8: .4byte 0xFFFFF800
_080A0EEC:
	ldr r2, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xb
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x68]
	subs r1, r1, r0
	cmp r2, r1
	ble _080A0F70
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	adds r1, r5, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
	b _080A0F70
_080A0F1E:
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0F28:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A0F70
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A0F6C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080A0F9C
	.align 2, 0
_080A0F6C: .4byte gProjectileFnTable
_080A0F70:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	adds r0, #0x30
	str r0, [r4, #0x5c]
	movs r1, #0xa0
	lsls r1, r1, #4
	cmp r0, r1
	ble _080A0F86
	str r1, [r4, #0x5c]
_080A0F86:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A0F9E
	ldr r1, _080A0FA4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_080A0F9C:
	str r0, [r4, #0x14]
_080A0F9E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0FA4: .4byte gProjectileFnTable

	thumb_func_start FUN_080a0fa8
FUN_080a0fa8: @ 0x080A0FA8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r0, [r5, #0xe]
	cmp r0, #9
	bls _080A0FB6
	b _080A125E
_080A0FB6:
	lsls r0, r0, #2
	ldr r1, _080A0FC0 @ =_080A0FC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0FC0: .4byte _080A0FC4
_080A0FC4: @ jump table
	.4byte _080A0FEC @ case 0
	.4byte _080A107C @ case 1
	.4byte _080A10C8 @ case 2
	.4byte _080A10F8 @ case 3
	.4byte _080A1120 @ case 4
	.4byte _080A1138 @ case 5
	.4byte _080A115C @ case 6
	.4byte _080A11AA @ case 7
	.4byte _080A1208 @ case 8
	.4byte _080A1212 @ case 9
_080A0FEC:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A101C @ =0x0836B164
	bl SetDDP
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldr r1, _080A1020 @ =0x0000A71C
	adds r0, r5, #0
	bl SetMotion
	ldrb r2, [r5, #0x12]
	cmp r2, #0
	beq _080A1024
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A102A
	.align 2, 0
_080A101C: .4byte 0x0836B164
_080A1020: .4byte 0x0000A71C
_080A1024:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A102A:
	strb r0, [r5, #0xa]
	movs r4, #1
	adds r1, r4, #0
	ands r1, r2
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
	ldr r2, _080A10A0 @ =0xFFFFFD80
	ldr r3, _080A10A4 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080A10A8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080A10AC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #7
	subs r2, r2, r1
	rsbs r1, r2, #0
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	muls r0, r1, r0
	adds r2, r2, r0
	str r2, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A107C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r1, r0, r1
	str r1, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A10B0
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	bgt _080A109C
	b _080A1200
_080A109C:
	b _080A10C0
	.align 2, 0
_080A10A0: .4byte 0xFFFFFD80
_080A10A4: .4byte RNG_0202f388
_080A10A8: .4byte 0x000343FD
_080A10AC: .4byte 0x00269EC3
_080A10B0:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080A10C4 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	blt _080A10C0
	b _080A1200
_080A10C0:
	str r0, [r5, #0x54]
	b _080A11FA
	.align 2, 0
_080A10C4: .4byte 0xFFFFB000
_080A10C8:
	ldr r2, _080A1110 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080A1114 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080A1118 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	strb r0, [r5, #0x12]
	ldr r1, _080A111C @ =0x0000A71D
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A10F8:
	adds r0, r5, #0
	bl FUN_0801779c
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A110C
	b _080A125E
_080A110C:
	b _080A114A
	.align 2, 0
_080A1110: .4byte RNG_0202f388
_080A1114: .4byte 0x000343FD
_080A1118: .4byte 0x00269EC3
_080A111C: .4byte 0x0000A71D
_080A1120:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A1154 @ =0x0836B17C
	bl SetDDP
	ldr r1, _080A1158 @ =0x0000A71E
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A1138:
	adds r0, r5, #0
	bl FUN_0801779c
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080A114A
	b _080A125E
_080A114A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A125E
	.align 2, 0
_080A1154: .4byte 0x0836B17C
_080A1158: .4byte 0x0000A71E
_080A115C:
	ldr r1, _080A1190 @ =0x0000A71F
	adds r0, r5, #0
	bl SetMotion
	ldr r2, _080A1194 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080A1198 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080A119C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	lsls r2, r0, #7
	str r2, [r5, #0x5c]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A11A0
	rsbs r0, r2, #0
	lsls r0, r0, #1
	b _080A11A2
	.align 2, 0
_080A1190: .4byte 0x0000A71F
_080A1194: .4byte RNG_0202f388
_080A1198: .4byte 0x000343FD
_080A119C: .4byte 0x00269EC3
_080A11A0:
	movs r0, #0
_080A11A2:
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A11AA:
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A11D8
	adds r0, r2, #0
	subs r0, #0x30
	str r0, [r5, #0x5c]
	ldr r1, _080A11D4 @ =0xFFFFFA00
	cmp r0, r1
	bge _080A11CA
	str r1, [r5, #0x5c]
_080A11CA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	cmp r0, r1
	bge _080A1200
	b _080A11F0
	.align 2, 0
_080A11D4: .4byte 0xFFFFFA00
_080A11D8:
	adds r0, r2, #0
	adds r0, #0x30
	str r0, [r5, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A11E8
	str r1, [r5, #0x5c]
_080A11E8:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	cmp r0, r1
	ble _080A1200
_080A11F0:
	str r1, [r5, #0x54]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
_080A11FA:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A1200:
	adds r0, r5, #0
	bl FUN_0801779c
	b _080A125E
_080A1208:
	movs r0, #2
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A1212:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A1258
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080A1254 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080A1274
	.align 2, 0
_080A1254: .4byte gProjectileFnTable
_080A1258:
	adds r0, r5, #0
	bl FUN_0801779c
_080A125E:
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080A1276
	ldr r1, _080A127C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_080A1274:
	str r0, [r5, #0x14]
_080A1276:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A127C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a1280
FUN_080a1280: @ 0x080A1280
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A1292
	cmp r0, #1
	beq _080A12AA
	b _080A131C
_080A1292:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A1324 @ =0x0836B194
	bl SetDDP
	ldr r1, _080A1328 @ =0x00003704
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A12AA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	ldr r1, _080A132C @ =0xFFFFF900
	adds r2, r0, r1
	str r2, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, _080A1330 @ =0xFFFF4000
	adds r0, r0, r1
	cmp r2, r0
	bge _080A131C
	ldrb r0, [r4, #0x12]
	cmp r0, #2
	bne _080A12E6
	ldrb r3, [r4, #0x13]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #2
	subs r0, r0, r3
	lsls r0, r0, #9
	ldr r1, _080A1334 @ =0xFFFFC500
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	adds r0, r5, #0
	bl CreateDeathtanzRock
_080A12E6:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A1338 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A131C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A1324: .4byte 0x0836B194
_080A1328: .4byte 0x00003704
_080A132C: .4byte 0xFFFFF900
_080A1330: .4byte 0xFFFF4000
_080A1334: .4byte 0xFFFFC500
_080A1338: .4byte gProjectileFnTable

	thumb_func_start FUN_080a133c
FUN_080a133c: @ 0x080A133C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A134C
	cmp r0, #1
	beq _080A139E
	b _080A1408
_080A134C:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080A1370 @ =0x00003702
	adds r1, r0, #0
	ldrb r0, [r4, #0x12]
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x13]
	cmp r2, #0
	beq _080A1374
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A137A
	.align 2, 0
_080A1370: .4byte 0x00003702
_080A1374:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A137A:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A139E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r3, _080A1410 @ =0x0836B211
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrb r2, [r4, #0x12]
	eors r1, r2
	adds r1, r1, r3
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A1414 @ =0x0836B11C
	adds r1, r1, r2
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _080A1408
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A1418 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A1408:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1410: .4byte 0x0836B211
_080A1414: .4byte 0x0836B11C
_080A1418: .4byte gProjectileFnTable

	thumb_func_start createBat
createBat: @ 0x080A141C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080A1478 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A146E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A147C @ =gProjectileFnTable
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
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r4, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r7, [r3, #0x28]
_080A146E:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A1478: .4byte gProjectileHeaderPtr
_080A147C: .4byte gProjectileFnTable

	thumb_func_start createEchoWave
createEchoWave: @ 0x080A1480
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A14D4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A14CC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A14D8 @ =gProjectileFnTable
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
	movs r0, #1
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A14CC:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A14D4: .4byte gProjectileHeaderPtr
_080A14D8: .4byte gProjectileFnTable

	thumb_func_start FUN_080a14dc
FUN_080a14dc: @ 0x080A14DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A1530 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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

	thumb_func_start Projectile15_Update
Projectile15_Update: @ 0x080A1710
	push {lr}
	ldr r2, _080A172C @ =0x0836B250
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
_080A172C: .4byte 0x0836B250

	thumb_func_start Projectile15_Die
Projectile15_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68
	.byte 0x00, 0x69, 0x50, 0x61, 0x70, 0x47
	.align 2, 0
	.4byte gProjectileFnTable

	thumb_func_start FUN_080a176c
FUN_080a176c: @ 0x080A176C
	movs r2, #0
	movs r1, #1
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a1778
FUN_080a1778: @ 0x080A1778
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A1792
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	b _080A180C
_080A1792:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080A1800
	ldr r2, _080A17F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080A17F4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080A17F8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r5, _080A17FC @ =0x0000AA02
	mov r0, sp
	movs r1, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080bddcc
	mov r0, sp
	movs r1, #1
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080bddcc
	movs r0, #0x2a
	bl PlaySound
	b _080A180C
	.align 2, 0
_080A17F0: .4byte RNG_0202f388
_080A17F4: .4byte 0x000343FD
_080A17F8: .4byte 0x00269EC3
_080A17FC: .4byte 0x0000AA02
_080A1800:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A1824
_080A180C:
	ldr r1, _080A1820 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080A1A04
	.align 2, 0
_080A1820: .4byte gProjectileFnTable
_080A1824:
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	bne _080A182C
	b _080A198C
_080A182C:
	cmp r0, #1
	bgt _080A1836
	cmp r0, #0
	beq _080A1844
	b _080A1A04
_080A1836:
	cmp r0, #2
	bne _080A183C
	b _080A19CA
_080A183C:
	cmp r0, #3
	bne _080A1842
	b _080A19D8
_080A1842:
	b _080A1A04
_080A1844:
	movs r0, #0x78
	strb r0, [r6, #0x12]
	movs r1, #0xaa
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0xb6
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080A1868
	movs r0, #0x12
	strb r0, [r6, #0x13]
	movs r0, #0x80
	lsls r0, r0, #7
	b _080A188C
_080A1868:
	cmp r1, #1
	bne _080A1876
	movs r0, #0x1a
	strb r0, [r6, #0x13]
	movs r0, #0xc0
	lsls r0, r0, #7
	b _080A188C
_080A1876:
	cmp r1, #2
	bne _080A1884
	movs r0, #0x22
	strb r0, [r6, #0x13]
	movs r0, #0x80
	lsls r0, r0, #8
	b _080A188C
_080A1884:
	movs r0, #0x2a
	strb r0, [r6, #0x13]
	movs r0, #0xa0
	lsls r0, r0, #8
_080A188C:
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x28]
	ldrb r1, [r0, #0xa]
	movs r4, #0x10
	adds r0, r4, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A18C2
	ldr r1, [r6, #0x54]
	ldr r0, [r6, #0x64]
	subs r3, r1, r0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	b _080A18E6
_080A18C2:
	ldr r1, [r6, #0x54]
	ldr r0, [r6, #0x64]
	adds r3, r1, r0
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r4
_080A18E6:
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	subs r0, r3, r0
	ldrb r1, [r6, #0x13]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldrb r0, [r5]
	ldrb r3, [r6, #0x13]
	cmp r0, #0
	bne _080A1900
	movs r0, #0x4c
	b _080A1912
_080A1900:
	cmp r0, #1
	bne _080A1908
	movs r0, #0x38
	b _080A1912
_080A1908:
	cmp r0, #2
	bne _080A1910
	movs r0, #0x26
	b _080A1912
_080A1910:
	movs r0, #0x14
_080A1912:
	str r0, [r6, #0x68]
	ldr r0, [r6, #0x68]
	lsls r0, r0, #8
	asrs r0, r0, #8
	adds r2, r3, #0
	adds r1, r2, #1
	asrs r1, r1, #1
	muls r1, r2, r1
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xb5
	ldrb r1, [r1]
	cmp r1, #0
	bne _080A1940
	adds r1, r2, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	subs r1, r1, r0
	lsls r1, r1, #4
	b _080A197C
_080A1940:
	cmp r1, #1
	bne _080A1956
	adds r1, r2, #0
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r1, r1, r0
	lsls r1, r1, #4
	b _080A197C
_080A1956:
	cmp r1, #2
	bne _080A196C
	adds r1, r2, #0
	bl __divsi3
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #4
	b _080A197C
_080A196C:
	adds r1, r3, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	subs r1, r1, r0
	lsls r1, r1, #5
_080A197C:
	asrs r1, r1, #8
	str r1, [r6, #0x60]
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A198C:
	ldr r0, [r6, #0x68]
	rsbs r0, r0, #0
	lsls r0, r0, #8
	asrs r0, r0, #8
	ldr r2, [r6, #0x60]
	adds r2, r2, r0
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A19B2
	subs r0, #1
	strb r0, [r6, #0x13]
_080A19B2:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A1A04
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A1A04
_080A19CA:
	ldr r1, _080A1A0C @ =0x0000AA01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A19D8:
	ldr r0, [r6, #0x68]
	rsbs r0, r0, #0
	lsls r0, r0, #8
	asrs r0, r0, #8
	ldr r2, [r6, #0x60]
	adds r2, r2, r0
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A19FE
	subs r0, #1
	strb r0, [r6, #0x13]
_080A19FE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080A1A04:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1A0C: .4byte 0x0000AA01

	thumb_func_start FUN_080a1a10
FUN_080a1a10:
	.byte 0x00, 0x22, 0x01, 0x21, 0x41, 0x73, 0x82, 0x73, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a1a1c
FUN_080a1a1c: @ 0x080A1A1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _080A1A30
	subs r0, #1
	str r0, [r1]
_080A1A30:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A1A50
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_080A1A50:
	ldrb r6, [r4, #0xe]
	cmp r6, #1
	bne _080A1A58
	b _080A1C70
_080A1A58:
	cmp r6, #1
	bgt _080A1A62
	cmp r6, #0
	beq _080A1A6A
	b _080A1F04
_080A1A62:
	cmp r6, #2
	bne _080A1A68
	b _080A1ED0
_080A1A68:
	b _080A1F04
_080A1A6A:
	movs r7, #0
	strb r6, [r4, #0x12]
	strb r6, [r4, #0x13]
	str r6, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r5, [r0]
	cmp r5, #0
	bne _080A1AC4
	ldr r1, _080A1ABC @ =gSineTable
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0x14
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1AC0 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080A1B9E
	.align 2, 0
_080A1ABC: .4byte gSineTable
_080A1AC0: .4byte 0x0000A906
_080A1AC4:
	cmp r5, #1
	bne _080A1B08
	ldr r1, _080A1B00 @ =gSineTable
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1B04 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	b _080A1B8C
	.align 2, 0
_080A1B00: .4byte gSineTable
_080A1B04: .4byte 0x0000A906
_080A1B08:
	cmp r5, #2
	bne _080A1B58
	ldr r1, _080A1B50 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0x94
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1B54 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080A1B9E
	.align 2, 0
_080A1B50: .4byte gSineTable
_080A1B54: .4byte 0x0000A906
_080A1B58:
	cmp r5, #3
	bne _080A1BB8
	ldr r1, _080A1BAC @ =gSineTable
	adds r0, r1, #0
	adds r0, #0x6c
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	adds r1, #0xec
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1BB0 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
_080A1B8C:
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080A1B9E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A1BB4 @ =0x0836B2DC
	bl SetDDP
	b _080A1C6A
	.align 2, 0
_080A1BAC: .4byte gSineTable
_080A1BB0: .4byte 0x0000A906
_080A1BB4: .4byte 0x0836B2DC
_080A1BB8:
	cmp r5, #4
	bne _080A1C1C
	ldr r1, _080A1C10 @ =gSineTable
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1C14 @ =0x0000A90A
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A1C18 @ =0x0836B2F4
	bl SetDDP
	b _080A1C6A
	.align 2, 0
_080A1C10: .4byte gSineTable
_080A1C14: .4byte 0x0000A90A
_080A1C18: .4byte 0x0836B2F4
_080A1C1C:
	cmp r5, #5
	bne _080A1C6A
	ldr r1, _080A1CCC @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xec
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1CD0 @ =0x0000A90A
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A1CD4 @ =0x0836B2F4
	bl SetDDP
_080A1C6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A1C70:
	movs r6, #0
	ldr r0, [r4, #0x54]
	ldr r5, [r4, #0x5c]
	adds r2, r0, r5
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r3, [r4, #0x60]
	adds r1, r0, r3
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r7, [r0]
	cmp r7, #3
	bgt _080A1D68
	cmp r3, #0
	bge _080A1D0C
	str r6, [sp]
	ldr r0, _080A1CD8 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080A1CDC @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	bge _080A1CA2
	movs r0, #1
	str r0, [sp]
_080A1CA2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #4]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1CE0
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	ble _080A1CE0
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
	.align 2, 0
_080A1CCC: .4byte gSineTable
_080A1CD0: .4byte 0x0000A90A
_080A1CD4: .4byte 0x0836B2F4
_080A1CD8: .4byte gStageRun+232
_080A1CDC: .4byte 0xFFFFB000
_080A1CE0:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1CF6
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	bge _080A1CF6
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
_080A1CF6:
	ldr r1, [sp]
	cmp r1, #0
	bne _080A1CFE
	b _080A1E40
_080A1CFE:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1D0C:
	adds r0, r2, #0
	bl PushoutToUp1
	str r0, [sp]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #4]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1D3E
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	ble _080A1D3E
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
_080A1D3E:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1D54
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	bge _080A1D54
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
_080A1D54:
	ldr r1, [sp]
	cmp r1, #0
	beq _080A1E40
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1D68:
	cmp r5, #0
	ble _080A1DCC
	adds r0, r2, #0
	bl PushoutToUp1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r0, _080A1DAC @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080A1DB0 @ =0xFFFFB000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r1, r0
	bge _080A1D88
	movs r0, #1
	str r0, [sp, #4]
_080A1D88:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1DB4
	ldr r1, [r4, #0x60]
	cmp r1, #0
	bge _080A1DB4
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
	.align 2, 0
_080A1DAC: .4byte gStageRun+232
_080A1DB0: .4byte 0xFFFFB000
_080A1DB4:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1E2C
	ldr r1, [r4, #0x60]
	cmp r1, #0
	ble _080A1E2C
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1DCC:
	adds r0, r2, #0
	bl PushoutToUp1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r0, _080A1E0C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080A1E10 @ =0xFFFFB000
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	cmp r1, r0
	bge _080A1DE8
	movs r0, #1
	str r0, [sp, #4]
_080A1DE8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1E14
	ldr r1, [r4, #0x60]
	cmp r1, #0
	bge _080A1E14
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
	.align 2, 0
_080A1E0C: .4byte gStageRun+232
_080A1E10: .4byte 0xFFFFB000
_080A1E14:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1E2C
	ldr r1, [r4, #0x60]
	cmp r1, #0
	ble _080A1E2C
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1E2C:
	ldr r1, [sp]
	cmp r1, #0
	beq _080A1E40
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
_080A1E3C:
	str r0, [r4, #0x5c]
_080A1E3E:
	movs r6, #1
_080A1E40:
	cmp r6, #1
	bne _080A1E7A
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r2, [r4, #0xa]
	lsrs r1, r2, #4
	eors r1, r6
	ands r1, r6
	cmp r1, #0
	beq _080A1E5C
	movs r0, #0x10
	orrs r0, r2
	b _080A1E60
_080A1E5C:
	movs r0, #0xef
	ands r0, r2
_080A1E60:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080A1E7A:
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _080A1EA2
	movs r0, #0xff
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A1EA2:
	ldrb r1, [r4, #0x13]
	adds r1, #1
	strb r1, [r4, #0x13]
	lsls r1, r1, #0x18
	movs r0, #0xe0
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	bne _080A1EC8
	adds r1, r4, #0
	adds r1, #0x54
	adds r2, r7, #0
	ldrb r3, [r4, #0xa]
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r4, #0
	bl FUN_080bde9c
_080A1EC8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080A1F04
_080A1ED0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	ldr r0, [r4, #0x64]
	adds r1, #2
	strh r0, [r1]
	ldr r0, [r4, #0x64]
	cmp r0, #0
	ble _080A1EEE
	subs r0, #0x20
	str r0, [r4, #0x64]
_080A1EEE:
	ldr r0, [r4, #0x64]
	cmp r0, #0x20
	bgt _080A1F04
	ldr r1, _080A1F0C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A1F04:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1F0C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a1f10
FUN_080a1f10:
	.byte 0x00, 0x22, 0x01, 0x21, 0x41, 0x73, 0x82, 0x73, 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_080a1f1c
FUN_080a1f1c: @ 0x080A1F1C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080A1F4C
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A1F4C
	ldr r1, _080A1F48 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080A2018
	.align 2, 0
_080A1F48: .4byte gProjectileFnTable
_080A1F4C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A1F58
	cmp r0, #1
	beq _080A1F84
	b _080A2018
_080A1F58:
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A1F6C
	movs r0, #0x12
	rsbs r0, r0, #0
	b _080A1F6E
_080A1F6C:
	movs r0, #0x12
_080A1F6E:
	str r0, [r4, #0x5c]
	movs r0, #0xc8
	strb r0, [r4, #0x12]
	movs r1, #0xa9
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A1F84:
	ldr r0, [r4, #0x64]
	ldr r3, [r4, #0x5c]
	adds r1, r0, r3
	str r1, [r4, #0x64]
	adds r2, r1, #0
	cmp r1, #0
	bge _080A1F94
	rsbs r2, r1, #0
_080A1F94:
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r2, r0
	ble _080A1FA0
	subs r0, r1, r3
	str r0, [r4, #0x64]
_080A1FA0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A1FE4
	cmp r1, #0
	ble _080A1FBE
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToLeft1
	b _080A1FC6
_080A1FBE:
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToRight1
_080A1FC6:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2012
	ldr r1, _080A1FE0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080A2012
	.align 2, 0
_080A1FE0: .4byte gProjectileFnTable
_080A1FE4:
	cmp r1, #0
	ble _080A1FF2
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToLeft1
	b _080A1FFA
_080A1FF2:
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToRight1
_080A1FFA:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2012
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
_080A2012:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A2018:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a2020
FUN_080a2020: @ 0x080A2020
	movs r2, #0
	movs r1, #1
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a202c
FUN_080a202c: @ 0x080A202C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A2052
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
_080A2052:
	ldrb r0, [r5, #0xe]
	cmp r0, #6
	bls _080A205A
	b _080A22DE
_080A205A:
	lsls r0, r0, #2
	ldr r1, _080A2064 @ =_080A2068
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A2064: .4byte _080A2068
_080A2068: @ jump table
	.4byte _080A2084 @ case 0
	.4byte _080A20EC @ case 1
	.4byte _080A2136 @ case 2
	.4byte _080A2162 @ case 3
	.4byte _080A21CE @ case 4
	.4byte _080A2254 @ case 5
	.4byte _080A22A8 @ case 6
_080A2084:
	adds r0, r5, #0
	adds r0, #0xb5
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A209E
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
	strb r2, [r5, #0x13]
	movs r0, #3
	strb r0, [r5, #0xe]
	b _080A22DE
_080A209E:
	ldr r1, _080A20E4 @ =0x0000A903
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, _080A20E8 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [r5, #0x60]
	str r4, [r5, #0x5c]
	b _080A2298
	.align 2, 0
_080A20E4: .4byte 0x0000A903
_080A20E8: .4byte 0xFFFFFF00
_080A20EC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _080A2110
	b _080A22DE
_080A2110:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x54]
	str r1, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	movs r3, #1
	bl createHellbatElectricBeam
	movs r0, #0
	strb r0, [r5, #0x13]
	movs r0, #1
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	b _080A2294
_080A2136:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A2148
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A2148
	b _080A22DE
_080A2148:
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	add r1, sp, #8
	str r0, [r1, #4]
	ldr r0, [r5, #0x28]
	movs r2, #1
	bl FUN_080a1538
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A2296
_080A2162:
	ldr r1, _080A21A0 @ =0x0000A905
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A21A4 @ =0x0836B2C4
	bl SetDDP
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0x13]
	cmp r0, #1
	bne _080A21A8
	movs r0, #0xc0
	lsls r0, r0, #2
	b _080A21AA
	.align 2, 0
_080A21A0: .4byte 0x0000A905
_080A21A4: .4byte 0x0836B2C4
_080A21A8:
	ldr r0, _080A2224 @ =0xFFFFFD00
_080A21AA:
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080A2228 @ =0xFFFFFC00
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	str r4, [r5, #0x64]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A21CE:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x64]
	adds r1, r0, #0
	cmp r1, #0
	bge _080A21E4
	rsbs r1, r1, #0
_080A21E4:
	movs r0, #0xa0
	lsls r0, r0, #5
	cmp r1, r0
	ble _080A2206
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080A2206
	movs r0, #1
	strb r0, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x54
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080a1594
	ldr r1, [r5, #0x5c]
	str r1, [r0, #0x5c]
_080A2206:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x13]
	cmp r0, #1
	bne _080A222C
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	b _080A2238
	.align 2, 0
_080A2224: .4byte 0xFFFFFD00
_080A2228: .4byte 0xFFFFFC00
_080A222C:
	ldr r0, [r5, #0x54]
	ldr r2, _080A224C @ =0xFFFFFC00
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
_080A2238:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A22DE
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, _080A2250 @ =0xFFFFFD00
	str r0, [r5, #0x60]
	b _080A2298
	.align 2, 0
_080A224C: .4byte 0xFFFFFC00
_080A2250: .4byte 0xFFFFFD00
_080A2254:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldr r0, _080A22A0 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080A22A4 @ =0xFFFFB000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	bge _080A2274
	movs r2, #1
_080A2274:
	cmp r2, #0
	beq _080A22DE
	adds r0, r1, r2
	str r0, [r5, #0x58]
	movs r0, #0xff
	str r0, [r5, #0x64]
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
_080A2294:
	ands r0, r1
_080A2296:
	strb r0, [r5, #0xa]
_080A2298:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A22DE
	.align 2, 0
_080A22A0: .4byte gStageRun+232
_080A22A4: .4byte 0xFFFFB000
_080A22A8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0x50
	strh r0, [r1]
	ldr r0, [r5, #0x64]
	adds r1, #2
	strh r0, [r1]
	ldr r0, [r5, #0x64]
	cmp r0, #0
	ble _080A22C6
	subs r0, #0x20
	str r0, [r5, #0x64]
_080A22C6:
	ldr r0, [r5, #0x64]
	cmp r0, #0x20
	bgt _080A22DE
	ldr r1, _080A22E8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080A22DE:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A22E8: .4byte gProjectileFnTable

	thumb_func_start FUN_080a22ec
FUN_080a22ec:
	.byte 0x00, 0x22, 0x01, 0x21
	.byte 0x41, 0x73, 0x82, 0x73, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a22f8
FUN_080a22f8: @ 0x080A22F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A2334
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A2330 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080A2446
	.align 2, 0
_080A2330: .4byte gProjectileFnTable
_080A2334:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080A23AE
	cmp r5, #1
	bgt _080A2344
	cmp r5, #0
	beq _080A234A
	b _080A2446
_080A2344:
	cmp r5, #2
	beq _080A2438
	b _080A2446
_080A234A:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A238C @ =0x0000A905
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A2390 @ =0x0836B2C4
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080A2398
	ldr r0, [r4, #0x54]
	ldr r1, _080A2394 @ =0xFFFFEC00
	b _080A239E
	.align 2, 0
_080A238C: .4byte 0x0000A905
_080A2390: .4byte 0x0836B2C4
_080A2394: .4byte 0xFFFFEC00
_080A2398:
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #5
_080A239E:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x64]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A23AE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r0, r1
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A23EE
	cmp r1, #0
	bge _080A23CC
	rsbs r1, r1, #0
_080A23CC:
	movs r0, #0xa0
	lsls r0, r0, #5
	cmp r1, r0
	ble _080A23EE
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A23EE
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080a1594
	ldr r1, [r4, #0x5c]
	str r1, [r0, #0x5c]
_080A23EE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080A240A
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _080A2416
_080A240A:
	ldr r0, [r4, #0x54]
	ldr r1, _080A2430 @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_080A2416:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2446
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _080A2434 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A2446
	.align 2, 0
_080A2430: .4byte 0xFFFFFC00
_080A2434: .4byte 0xFFFFFD00
_080A2438:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A2446:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a244c
FUN_080a244c: @ 0x080A244C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080A24A0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A2496
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A24A4 @ =gProjectileFnTable
	movs r0, #0x10
	strb r0, [r3, #9]
	ldr r0, [r1, #0x40]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	ldr r0, [r5]
	str r0, [r3, #0x64]
	ldr r0, [r5, #4]
	str r0, [r3, #0x68]
_080A2496:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A24A0: .4byte gProjectileHeaderPtr
_080A24A4: .4byte gProjectileFnTable

	thumb_func_start Projectile16_Init
Projectile16_Init: @ 0x080A24A8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r7, #0
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A2500 @ =0x0836B358
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r2, [r6, #0x10]
	cmp r2, #0
	bne _080A2504
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080A2526
	.align 2, 0
_080A2500: .4byte 0x0836B358
_080A2504:
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080A2526:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldr r1, _080A2550 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r0, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	adds r0, r6, #0
	bl Projectile16_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2550: .4byte gProjectileFnTable

	thumb_func_start Projectile16_Update
Projectile16_Update: @ 0x080A2554
	push {lr}
	adds r3, r0, #0
	ldr r0, _080A259C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080A25A4
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080A25A0 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080A25B4
	.align 2, 0
_080A259C: .4byte gCurStory
_080A25A0: .4byte gProjectileFnTable
_080A25A4:
	ldr r0, _080A25B8 @ =0x0836B350
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_080A25B4:
	pop {r0}
	bx r0
	.align 2, 0
_080A25B8: .4byte 0x0836B350

	thumb_func_start Projectile16_Die
Projectile16_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A
	.byte 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30, 0x01, 0x60, 0x04, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49
	.byte 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61
	.byte 0x70, 0x47, 0x00, 0x00, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080a25f8
FUN_080a25f8: @ 0x080A25F8
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	ands r3, r1
	cmp r3, #0
	beq _080A2622
	movs r1, #0
	str r1, [r2]
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080A265C
_080A2622:
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _080A2650
	str r3, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x35
	bl PlaySound
	b _080A2666
_080A2650:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A2680
_080A265C:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_080A2666:
	ldr r1, _080A267C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080A2706
	.align 2, 0
_080A267C: .4byte gProjectileFnTable
_080A2680:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A268C
	cmp r0, #1
	beq _080A26D6
	b _080A2706
_080A268C:
	ldr r1, _080A26A4 @ =0x00003E03
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A26AC
	ldr r0, [r4, #0x54]
	ldr r2, _080A26A8 @ =0xFFFFA000
	b _080A26B2
	.align 2, 0
_080A26A4: .4byte 0x00003E03
_080A26A8: .4byte 0xFFFFA000
_080A26AC:
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #7
_080A26B2:
	adds r1, r0, r2
	movs r0, #0x1e
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x54]
	subs r0, r1, r0
	movs r1, #0x1e
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r1, #0
	ldr r0, _080A270C @ =0xFFFFFC40
	str r0, [r4, #0x60]
	movs r0, #0x1d
	str r0, [r4, #0x64]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A26D6:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A2706
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A2706:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A270C: .4byte 0xFFFFFC40

	thumb_func_start FUN_080a2710
FUN_080a2710: @ 0x080A2710
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A2722
	cmp r0, #1
	beq _080A2758
	b _080A277A
_080A2722:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080A2784 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x35
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A2788 @ =0x0836B388
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A2758:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A2768
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A277A
_080A2768:
	ldr r1, _080A278C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A277A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2784: .4byte 0xFFFFF800
_080A2788: .4byte 0x0836B388
_080A278C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2790
FUN_080a2790: @ 0x080A2790
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080A27DC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A27D4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A27E0 @ =gProjectileFnTable
	movs r0, #0x11
	strb r0, [r3, #9]
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x11]
_080A27D4:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A27DC: .4byte gProjectileHeaderPtr
_080A27E0: .4byte gProjectileFnTable

	thumb_func_start FUN_080a27e4
FUN_080a27e4: @ 0x080A27E4
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080A2830 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A2828
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A2834 @ =gProjectileFnTable
	movs r0, #0x11
	strb r0, [r3, #9]
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	movs r0, #2
	strb r0, [r3, #0x11]
_080A2828:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A2830: .4byte gProjectileHeaderPtr
_080A2834: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2838
FUN_080a2838: @ 0x080A2838
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080A2890 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A2888
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A2894 @ =gProjectileFnTable
	movs r0, #0x11
	strb r0, [r3, #9]
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	strb r6, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	ldr r0, [r5]
	str r0, [r3, #0x64]
	ldr r0, [r5, #4]
	str r0, [r3, #0x68]
	strb r1, [r3, #0x11]
	str r7, [r3, #0x28]
_080A2888:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A2890: .4byte gProjectileHeaderPtr
_080A2894: .4byte gProjectileFnTable

	thumb_func_start Projectile17_Init
Projectile17_Init: @ 0x080A2898
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldrb r1, [r6, #0x10]
	cmp r1, #0
	bne _080A28D4
	movs r0, #0xef
	ands r2, r0
	strb r2, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080A28F4
_080A28D4:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080A28F4:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldrb r7, [r6, #0x11]
	cmp r7, #0
	bne _080A298C
	movs r4, #0xa5
	lsls r4, r4, #3
	ldr r1, _080A2974 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080A2978 @ =wStaticGraphicTilenums
	adds r1, #0x84
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080A297C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080A2980 @ =wStaticMotionPalIDs
	adds r0, #0x84
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A2984 @ =0x0836B3C0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r1, _080A2988 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _080A2A20
	.align 2, 0
_080A2974: .4byte gStaticMotionGraphics
_080A2978: .4byte wStaticGraphicTilenums
_080A297C: .4byte gStaticMotionGraphics+12
_080A2980: .4byte wStaticMotionPalIDs
_080A2984: .4byte 0x0836B3C0
_080A2988: .4byte gProjectileFnTable
_080A298C:
	cmp r7, #1
	bne _080A29C4
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A29BC @ =0x0836B3F0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080A29C0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	b _080A2A14
	.align 2, 0
_080A29BC: .4byte 0x0836B3F0
_080A29C0: .4byte gProjectileFnTable
_080A29C4:
	cmp r7, #2
	bne _080A2A20
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A2A2C @ =0x0836B408
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080A2A30 @ =0x080FF080
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r6, #0x54]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #3
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r6, #0x58]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _080A2A34 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
_080A2A14:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_080A2A20:
	adds r0, r6, #0
	bl Projectile17_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2A2C: .4byte 0x0836B408
_080A2A30: .4byte 0x080FF080
_080A2A34: .4byte gProjectileFnTable

	thumb_func_start Projectile17_Update
Projectile17_Update: @ 0x080A2A38
	push {lr}
	adds r3, r0, #0
	ldr r0, _080A2A80 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080A2A88
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080A2A84 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080A2A98
	.align 2, 0
_080A2A80: .4byte gCurStory
_080A2A84: .4byte gProjectileFnTable
_080A2A88:
	ldr r0, _080A2A9C @ =0x0836B3B4
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_080A2A98:
	pop {r0}
	bx r0
	.align 2, 0
_080A2A9C: .4byte 0x0836B3B4

	thumb_func_start Projectile17_Die
Projectile17_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68
	.byte 0x00, 0x69, 0x50, 0x61, 0x70, 0x47, 0x00, 0x00, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080a2adc
FUN_080a2adc: @ 0x080A2ADC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	beq _080A2AF6
	movs r1, #0
	b _080A2AFE
_080A2AF6:
	ldr r2, _080A2B20 @ =0x00400100
	ands r2, r0
	cmp r2, #0
	beq _080A2B28
_080A2AFE:
	str r1, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A2B24 @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r6, #0xe]
	b _080A2B6A
	.align 2, 0
_080A2B20: .4byte 0x00400100
_080A2B24: .4byte 0x00004201
_080A2B28:
	movs r4, #4
	ands r0, r4
	cmp r0, #0
	beq _080A2B3E
	str r2, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	b _080A2B58
_080A2B3E:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080A2B6A
	str r1, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
_080A2B58:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A2B7C @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0xe]
_080A2B6A:
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _080A2B72
	b _080A2D86
_080A2B72:
	lsls r0, r0, #2
	ldr r1, _080A2B80 @ =_080A2B84
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A2B7C: .4byte 0x00004201
_080A2B80: .4byte _080A2B84
_080A2B84: @ jump table
	.4byte _080A2B9C @ case 0
	.4byte _080A2BB0 @ case 1
	.4byte _080A2BE0 @ case 2
	.4byte _080A2C22 @ case 3
	.4byte _080A2CE4 @ case 4
	.4byte _080A2D5E @ case 5
_080A2B9C:
	movs r1, #0x84
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xc
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A2BB0:
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _080A2BDC @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A2BD2
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A2BD2
	b _080A2D86
_080A2BD2:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A2D86
	.align 2, 0
_080A2BDC: .4byte 0xFFFFF600
_080A2BE0:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A2BF8
	ldr r0, [r6, #0x54]
	ldr r2, _080A2BF4 @ =0xFFFFC000
	adds r1, r0, r2
	b _080A2C00
	.align 2, 0
_080A2BF4: .4byte 0xFFFFC000
_080A2BF8:
	ldr r0, [r6, #0x54]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r0, r3
_080A2C00:
	movs r0, #0x4c
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x54]
	subs r0, r1, r0
	movs r1, #0x4c
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r1, #0
	ldr r0, _080A2C4C @ =0xFFFFFDA0
	str r0, [r6, #0x60]
	movs r0, #0x4b
	str r0, [r6, #0x64]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A2C22:
	ldr r2, [r6, #0x60]
	adds r2, #0x10
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	movs r4, #0
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	bge _080A2C54
	ldr r0, [r6, #0x54]
	ldr r3, _080A2C50 @ =0xFFFFF600
	b _080A2C5A
	.align 2, 0
_080A2C4C: .4byte 0xFFFFFDA0
_080A2C50: .4byte 0xFFFFF600
_080A2C54:
	ldr r0, [r6, #0x54]
	movs r3, #0xa0
	lsls r3, r3, #4
_080A2C5A:
	adds r2, r0, r3
	adds r0, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _080A2C96
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A2CDC @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r6, #0xe]
	movs r4, #1
_080A2C96:
	cmp r4, #0
	bne _080A2D86
	ldr r2, [r6, #0x54]
	ldr r0, [r6, #0x58]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2CBA
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #2
	strb r0, [r6, #0xe]
_080A2CBA:
	ldr r2, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r3, _080A2CE0 @ =0xFFFFFC00
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2D86
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x60]
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	b _080A2D86
	.align 2, 0
_080A2CDC: .4byte 0x00004201
_080A2CE0: .4byte 0xFFFFFC00
_080A2CE4:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _080A2D90 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	mov r0, sp
	bl FUN_080a2790
	ldr r0, [r6, #0x54]
	movs r4, #0xc0
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	adds r1, r5, #0
	bics r1, r0
	mov r0, sp
	bl FUN_080a2790
	ldr r0, [r6, #0x54]
	ldr r2, _080A2D90 @ =0xFFFFF400
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	mov r0, sp
	bl FUN_080a2790
	movs r4, #0
	adds r5, r6, #0
	adds r5, #0x54
_080A2D40:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_080a27e4
	adds r4, #1
	cmp r4, #4
	ble _080A2D40
	ldr r1, _080A2D94 @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A2D5E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A2D86
	movs r0, #0x31
	bl PlaySound
	ldr r1, _080A2D98 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A2D86:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D90: .4byte 0xFFFFF400
_080A2D94: .4byte 0x00004201
_080A2D98: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2d9c
FUN_080a2d9c: @ 0x080A2D9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A2DAC
	cmp r0, #1
	beq _080A2DBA
	b _080A2DDC
_080A2DAC:
	ldr r1, _080A2DE4 @ =0x00004204
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A2DBA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A2DDC
	ldr r1, _080A2DE8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A2DDC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2DE4: .4byte 0x00004204
_080A2DE8: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2dec
FUN_080a2dec: @ 0x080A2DEC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A2E20
	cmp r0, #1
	bgt _080A2E00
	cmp r0, #0
	beq _080A2E0A
	b _080A2E92
_080A2E00:
	cmp r0, #2
	beq _080A2E4C
	cmp r0, #3
	beq _080A2E62
	b _080A2E92
_080A2E0A:
	ldr r1, _080A2E48 @ =0x00004202
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	movs r0, #0x40
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A2E20:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A2E3E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A2E92
_080A2E3E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A2E92
	.align 2, 0
_080A2E48: .4byte 0x00004202
_080A2E4C:
	ldr r1, _080A2E98 @ =0x00004203
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	movs r0, #0x20
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A2E62:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A2E80
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A2E92
_080A2E80:
	ldr r1, _080A2E9C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A2E92:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E98: .4byte 0x00004203
_080A2E9C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2ea0
FUN_080a2ea0: @ 0x080A2EA0
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _080A2EE0 @ =gProjectileFnTable
	movs r4, #4
_080A2EA8:
	ldr r0, _080A2EE4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2ED4
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #8
	strb r0, [r2]
	movs r0, #0x12
	strb r0, [r1, #9]
	ldr r0, [r6, #0x48]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r5, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r5, [r0]
	movs r0, #2
	strb r0, [r1, #0x10]
_080A2ED4:
	subs r4, #1
	cmp r4, #0
	bge _080A2EA8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2EE0: .4byte gProjectileFnTable
_080A2EE4: .4byte gProjectileHeaderPtr

	thumb_func_start FUN_080a2ee8
FUN_080a2ee8: @ 0x080A2EE8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080A2F2C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A2F24
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A2F30 @ =gProjectileFnTable
	movs r0, #0x12
	strb r0, [r3, #9]
	ldr r0, [r1, #0x48]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_080A2F24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2F2C: .4byte gProjectileHeaderPtr
_080A2F30: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2f34
FUN_080a2f34: @ 0x080A2F34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	movs r5, #0
	movs r6, #0
	ldr r1, _080A2F98 @ =0xFFFFE400
	adds r4, r0, r1
	ldr r2, _080A2F9C @ =gProjectileFnTable
	mov r8, r2
_080A2F48:
	ldr r0, _080A2FA0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2F80
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #8
	strb r0, [r2]
	movs r0, #0x12
	strb r0, [r1, #9]
	mov r2, r8
	ldr r0, [r2, #0x48]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r6, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r6, [r0]
	strb r6, [r1, #0x10]
	str r4, [r1, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r7, r2
	str r0, [r1, #0x58]
	strb r5, [r1, #0x12]
_080A2F80:
	movs r0, #0xe0
	lsls r0, r0, #6
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	ble _080A2F48
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2F98: .4byte 0xFFFFE400
_080A2F9C: .4byte gProjectileFnTable
_080A2FA0: .4byte gProjectileHeaderPtr

	thumb_func_start FUN_080a2fa4
FUN_080a2fa4: @ 0x080A2FA4
	bx lr
	.align 2, 0

	thumb_func_start Projectile18_Init
Projectile18_Init: @ 0x080A2FA8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080A3008 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080A300C @ =0x0836B4BC
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
	ldr r1, _080A3010 @ =0x0836B45C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080A3014 @ =FUN_080a2fa4
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl Projectile18_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3008: .4byte gProjectileFnTable
_080A300C: .4byte 0x0836B4BC
_080A3010: .4byte 0x0836B45C
_080A3014: .4byte FUN_080a2fa4

	thumb_func_start Projectile18_Update
Projectile18_Update: @ 0x080A3018
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A3044 @ =0x0836B434
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080A3048 @ =0x0836B448
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3044: .4byte 0x0836B434
_080A3048: .4byte 0x0836B448

	thumb_func_start Projectile18_Die
Projectile18_Die: @ 0x080A304C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080A3088 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3088: .4byte gProjectileFnTable

	thumb_func_start FUN_080a308c
FUN_080a308c:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a3090
FUN_080a3090:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a3094
FUN_080a3094: @ 0x080A3094
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A30A4
	cmp r0, #1
	beq _080A30FE
	b _080A3166
_080A30A4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A30BC @ =0x0836B474
	bl SetDDP
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080A30C0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A30C6
	.align 2, 0
_080A30BC: .4byte 0x0836B474
_080A30C0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A30C6:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _080A3134 @ =0xFFFFFE00
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0xa
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	str r1, [r4, #0x60]
	ldr r1, _080A3138 @ =0x00004604
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A30FE:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A3116
	str r1, [r4, #0x60]
_080A3116:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	cmp r2, #0
	bge _080A3140
	ldr r0, [r4, #0x54]
	ldr r2, _080A313C @ =0xFFFFF800
	adds r0, r0, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _080A3160
	b _080A3152
	.align 2, 0
_080A3134: .4byte 0xFFFFFE00
_080A3138: .4byte 0x00004604
_080A313C: .4byte 0xFFFFF800
_080A3140:
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _080A3160
_080A3152:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A3160:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A3166:
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A31B4
	bl FUN_080a2ea0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080a2ee8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A31BC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A31B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A31BC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a31c0
FUN_080a31c0: @ 0x080A31C0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A31D0
	cmp r0, #1
	beq _080A320E
	b _080A3234
_080A31D0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A3288 @ =0x0836B48C
	bl SetDDP
	ldr r3, [r4, #0x54]
	ldr r1, _080A328C @ =0xFFFFF800
	adds r0, r3, r1
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A31F4
	movs r0, #0x80
	lsls r0, r0, #4
	adds r2, r3, r0
_080A31F4:
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080A3290 @ =0x00004605
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A320E:
	ldr r1, [r4, #0x58]
	adds r1, #0x80
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080A322E
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A322E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A3234:
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A3282
	bl FUN_080a2ea0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080a2ee8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A3294 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A3282:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3288: .4byte 0x0836B48C
_080A328C: .4byte 0xFFFFF800
_080A3290: .4byte 0x00004605
_080A3294: .4byte gProjectileFnTable

	thumb_func_start FUN_080a3298
FUN_080a3298: @ 0x080A3298
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A32D2
	cmp r0, #1
	bgt _080A32AC
	cmp r0, #0
	beq _080A32BA
	b _080A32B4
_080A32AC:
	cmp r0, #2
	beq _080A32F8
	cmp r0, #3
	beq _080A3336
_080A32B4:
	adds r5, r4, #0
	adds r5, #0x8c
	b _080A33C2
_080A32BA:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A32F0 @ =0x0836B4A4
	bl SetDDP
	ldr r1, _080A32F4 @ =0x00004606
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A32D2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x8c
	cmp r0, #3
	bne _080A33C2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A33C2
	.align 2, 0
_080A32F0: .4byte 0x0836B4A4
_080A32F4: .4byte 0x00004606
_080A32F8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A334C @ =0x0836B45C
	bl SetDDP
	movs r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl InitScalerotMotion1
	ldr r1, _080A3350 @ =0x00004606
	adds r0, r4, #0
	movs r2, #3
	movs r3, #1
	bl GotoMotion
	movs r0, #0x20
	str r0, [r4, #0x5c]
	movs r2, #0x20
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A332E
	subs r2, #0x40
_080A332E:
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A3336:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080A3354
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080A335A
	.align 2, 0
_080A334C: .4byte 0x0836B45C
_080A3350: .4byte 0x00004606
_080A3354:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A335A:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #4
	movs r2, #0
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	adds r5, r4, #0
	adds r5, #0x8c
	cmp r0, #7
	bhi _080A33BC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A3414 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A33BC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A33C2:
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A340C
	bl FUN_080a2ea0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080a2ee8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A3414 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A340C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3414: .4byte gProjectileFnTable

	thumb_func_start FUN_080a3418
FUN_080a3418: @ 0x080A3418
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A3428
	cmp r0, #1
	beq _080A3436
	b _080A348A
_080A3428:
	ldr r1, _080A3490 @ =0x00004607
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A3436:
	ldr r0, _080A3494 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _080A3498 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _080A348A
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A349C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A348A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3490: .4byte 0x00004607
_080A3494: .4byte pZero2
_080A3498: .4byte 0xFFFFF000
_080A349C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a34a0
FUN_080a34a0: @ 0x080A34A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080A34BC @ =pZero2
	ldr r3, [r0]
	ldrb r1, [r3, #0xc]
	adds r4, r0, #0
	cmp r1, #1
	bls _080A34C0
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _080A360C
	.align 2, 0
_080A34BC: .4byte pZero2
_080A34C0:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080A3530
	cmp r0, #1
	bgt _080A34D0
	cmp r0, #0
	beq _080A34DA
	b _080A363A
_080A34D0:
	cmp r0, #2
	beq _080A35AC
	cmp r0, #3
	beq _080A35C6
	b _080A363A
_080A34DA:
	movs r0, #0x8c
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x10
	str r0, [r5, #0x5c]
	movs r0, #0x80
	strb r0, [r5, #0x13]
	ldr r4, _080A3594 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _080A3598 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080A359C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r6, _080A35A0 @ =0xFFFFF800
	adds r0, r0, r6
	str r0, [r5, #0x64]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r1, _080A35A4 @ =0x00004608
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A3530:
	ldr r4, _080A35A8 @ =pZero2
	ldr r0, [r4]
	bl CountButtonMashing
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r5, #0x5c]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A3570
	cmp r1, #0
	blt _080A3570
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3570
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080A3576
_080A3570:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A3576:
	ldr r0, _080A35A8 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080A363A
	.align 2, 0
_080A3594: .4byte RNG_0202f388
_080A3598: .4byte 0x000343FD
_080A359C: .4byte 0x00269EC3
_080A35A0: .4byte 0xFFFFF800
_080A35A4: .4byte 0x00004608
_080A35A8: .4byte pZero2
_080A35AC:
	movs r6, #0x8c
	lsls r6, r6, #2
	adds r1, r3, r6
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	strb r2, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A35C6:
	ldr r2, [r4]
	ldr r0, [r2, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0x12]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A35F0
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A35F6
_080A35F0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A35F6:
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A363A
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A360C:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080A3640 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080A363A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3640: .4byte gProjectileFnTable

	thumb_func_start createTretistaBreathGas
createTretistaBreathGas: @ 0x080A3644
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A3694 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A368A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A3698 @ =gProjectileFnTable
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
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	str r6, [r3, #0x28]
_080A368A:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A3694: .4byte gProjectileHeaderPtr
_080A3698: .4byte gProjectileFnTable

	thumb_func_start tretista_080a369c
tretista_080a369c: @ 0x080A369C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A36EC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	ldr r1, _080A37D4 @ =0x0836B4F4
	b _080A3832
	.align 2, 0
_080A37D4: .4byte 0x0836B4F4
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

	thumb_func_start FUN_080a38e8
FUN_080a38e8: @ 0x080A38E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A38FE
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bhi _080A38FE
	movs r0, #0xc
	strb r0, [r4, #0xe]
_080A38FE:
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xd]
	adds r2, r0, #0
	cmp r1, #0xa
	bne _080A3912
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bhi _080A3912
	movs r0, #0xc
	strb r0, [r4, #0xe]
_080A3912:
	ldrb r0, [r2, #0xd]
	cmp r0, #8
	beq _080A3922
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bhi _080A3922
	movs r0, #0xc
	strb r0, [r4, #0xe]
_080A3922:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _080A392A
	b _080A3C4C
_080A392A:
	lsls r0, r0, #2
	ldr r1, _080A3934 @ =_080A3938
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A3934: .4byte _080A3938
_080A3938: @ jump table
	.4byte _080A3970 @ case 0
	.4byte _080A3A00 @ case 1
	.4byte _080A3A84 @ case 2
	.4byte _080A3AB0 @ case 3
	.4byte _080A3AE8 @ case 4
	.4byte _080A3C4C @ case 5
	.4byte _080A3C4C @ case 6
	.4byte _080A3C4C @ case 7
	.4byte _080A3C4C @ case 8
	.4byte _080A3C4C @ case 9
	.4byte _080A3B4A @ case 10
	.4byte _080A3B6C @ case 11
	.4byte _080A3BB8 @ case 12
	.4byte _080A3BF0 @ case 13
_080A3970:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080A39A0
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldr r0, _080A399C @ =0xFFFFCE00
	movs r1, #0x28
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x27
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080A39EC
	.align 2, 0
_080A399C: .4byte 0xFFFFCE00
_080A39A0:
	cmp r0, #1
	bne _080A39CC
	movs r0, #0x28
	strb r0, [r4, #0x12]
	movs r0, #0xc8
	lsls r0, r0, #6
	movs r1, #0x28
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x27
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080A39EC
_080A39CC:
	cmp r0, #2
	bne _080A39DC
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, _080A39D8 @ =0xFFFFFE00
	b _080A39E8
	.align 2, 0
_080A39D8: .4byte 0xFFFFFE00
_080A39DC:
	cmp r0, #3
	bne _080A39EE
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x80
	lsls r0, r0, #2
_080A39E8:
	str r0, [r4, #0x5c]
	movs r0, #0xa
_080A39EC:
	strb r0, [r4, #0xe]
_080A39EE:
	movs r1, #0xae
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080A3C4C
_080A3A00:
	ldr r2, [r4, #0x60]
	adds r2, #0x24
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0xc0
	lsls r5, r5, #4
	adds r1, r1, r5
	bl PushoutToUp1
	cmp r0, #0
	beq _080A3A44
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080A3A38
	movs r0, #0x80
	lsls r0, r0, #2
	b _080A3A3A
_080A3A38:
	ldr r0, _080A3A40 @ =0xFFFFFE00
_080A3A3A:
	str r0, [r4, #0x5c]
	b _080A3BAA
	.align 2, 0
_080A3A40: .4byte 0xFFFFFE00
_080A3A44:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080A3A60
	ldr r0, [r4, #0x54]
	ldr r1, _080A3A5C @ =0xFFFFF400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A3A5C @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToRight1
	b _080A3A6E
	.align 2, 0
_080A3A5C: .4byte 0xFFFFF400
_080A3A60:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	ldr r2, _080A3A80 @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToLeft1
_080A3A6E:
	cmp r0, #0
	bne _080A3A74
	b _080A3C4C
_080A3A74:
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #3
	strb r0, [r4, #0xe]
	b _080A3C4C
	.align 2, 0
_080A3A80: .4byte 0xFFFFF400
_080A3A84:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	blt _080A3A9A
	b _080A3B94
_080A3A9A:
	ldr r0, [r4, #0x54]
	ldr r2, _080A3AAC @ =0xFFFFF400
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl PushoutToRight1
	b _080A3BA6
	.align 2, 0
_080A3AAC: .4byte 0xFFFFF400
_080A3AB0:
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x50
	movs r3, #0
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A3AE8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	rsbs r0, r1, #0
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x64]
	ldr r0, [r4, #0x60]
	adds r0, #0x24
	str r0, [r4, #0x60]
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3B1E
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080A3B1E:
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	ldr r0, [r4, #0x64]
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A3B36
	subs r0, #1
	strb r0, [r4, #0x12]
_080A3B36:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080A3C2E
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A3C34
_080A3B4A:
	ldr r1, [r4, #0x60]
	adds r1, #0x24
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	b _080A3BA6
_080A3B6C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080A3B94
	ldr r0, [r4, #0x54]
	ldr r2, _080A3B90 @ =0xFFFFF400
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl PushoutToRight1
	b _080A3BA6
	.align 2, 0
_080A3B90: .4byte 0xFFFFF400
_080A3B94:
	ldr r0, [r4, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A3BB4 @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToLeft1
_080A3BA6:
	cmp r0, #0
	beq _080A3C4C
_080A3BAA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A3C4C
	.align 2, 0
_080A3BB4: .4byte 0xFFFFF400
_080A3BB8:
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x50
	movs r3, #0
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A3BF0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	rsbs r0, r1, #0
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A3C1A
	subs r0, #1
	strb r0, [r4, #0x12]
_080A3C1A:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080A3C2E
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A3C34
_080A3C2E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A3C34:
	strb r0, [r4, #0xa]
	cmp r2, #0
	bne _080A3C4C
	ldr r1, _080A3C54 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A3C4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3C54: .4byte gProjectileFnTable

	thumb_func_start FUN_080a3c58
FUN_080a3c58: @ 0x080A3C58
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x28]
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _080A3C78
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	bl FUN_080a449c
_080A3C78:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	bne _080A3C88
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bhi _080A3C88
	bl FUN_080a449c
_080A3C88:
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r0, [r1]
	movs r2, #4
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _080A3CAA
	adds r0, r7, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080A3CAA
	movs r0, #0x52
	bl PlaySound
_080A3CAA:
	ldrb r0, [r7, #0xe]
	cmp r0, #0x1b
	bls _080A3CB4
	bl _080A44AE
_080A3CB4:
	lsls r0, r0, #2
	ldr r1, _080A3CC0 @ =_080A3CC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A3CC0: .4byte _080A3CC4
_080A3CC4: @ jump table
	.4byte _080A3D34 @ case 0
	.4byte _080A3DB0 @ case 1
	.4byte _080A3E04 @ case 2
	.4byte _080A3E3E @ case 3
	.4byte _080A3E74 @ case 4
	.4byte _080A3E8E @ case 5
	.4byte _080A3F02 @ case 6
	.4byte _080A3FBC @ case 7
	.4byte _080A3FD4 @ case 8
	.4byte _080A4072 @ case 9
	.4byte _080A40A2 @ case 10
	.4byte _080A4104 @ case 11
	.4byte _080A4140 @ case 12
	.4byte _080A44AE @ case 13
	.4byte _080A44AE @ case 14
	.4byte _080A44AE @ case 15
	.4byte _080A44AE @ case 16
	.4byte _080A44AE @ case 17
	.4byte _080A44AE @ case 18
	.4byte _080A44AE @ case 19
	.4byte _080A4198 @ case 20
	.4byte _080A41B0 @ case 21
	.4byte _080A427C @ case 22
	.4byte _080A4282 @ case 23
	.4byte _080A431E @ case 24
	.4byte _080A434E @ case 25
	.4byte _080A43E8 @ case 26
	.4byte _080A443A @ case 27
_080A3D34:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A3D50
	ldr r0, [r7, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
	b _080A3D56
_080A3D50:
	ldr r0, [r7, #0x54]
	ldr r2, _080A3D7C @ =0xFFFFD600
	adds r0, r0, r2
_080A3D56:
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _080A3D80 @ =0xFFFF9800
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, _080A3D84 @ =0x0000AD06
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A3D88
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A3D8E
	.align 2, 0
_080A3D7C: .4byte 0xFFFFD600
_080A3D80: .4byte 0xFFFF9800
_080A3D84: .4byte 0x0000AD06
_080A3D88:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A3D8E:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3DB0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A3DCC
	ldr r0, [r7, #0x54]
	movs r2, #0xa8
	lsls r2, r2, #6
	adds r0, r0, r2
	b _080A3DD2
_080A3DCC:
	ldr r0, [r7, #0x54]
	ldr r1, _080A3DFC @ =0xFFFFD600
	adds r0, r0, r1
_080A3DD2:
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r2, _080A3E00 @ =0xFFFF9800
	adds r0, r0, r2
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r2, r7, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080A3DF2
	b _080A44AE
_080A3DF2:
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	b _080A43E0
	.align 2, 0
_080A3DFC: .4byte 0xFFFFD600
_080A3E00: .4byte 0xFFFF9800
_080A3E04:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A3E20
	ldr r0, [r7, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
	b _080A3E26
_080A3E20:
	ldr r0, [r7, #0x54]
	ldr r2, _080A3E68 @ =0xFFFFD600
	adds r0, r0, r2
_080A3E26:
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _080A3E6C @ =0xFFFF9800
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, _080A3E70 @ =0x0000AD06
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3E3E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r2, r7, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3E54
	b _080A44AE
_080A3E54:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _080A43E0
	.align 2, 0
_080A3E68: .4byte 0xFFFFD600
_080A3E6C: .4byte 0xFFFF9800
_080A3E70: .4byte 0x0000AD06
_080A3E74:
	adds r2, r7, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080A3E84
	b _080A44AE
_080A3E84:
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	b _080A43E0
_080A3E8E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080A3ED8 @ =0x0000AD07
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080A3EDC @ =0x0836B524
	bl SetDDP
	ldr r0, [r4, #0x58]
	ldr r2, _080A3EE0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A3EEC
	ldr r0, _080A3EE4 @ =0xFFFFFCD0
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	ldr r1, _080A3EE8 @ =0xFFFFAA00
	adds r0, r0, r1
	b _080A3EFA
	.align 2, 0
_080A3ED8: .4byte 0x0000AD07
_080A3EDC: .4byte 0x0836B524
_080A3EE0: .4byte 0xFFFFC000
_080A3EE4: .4byte 0xFFFFFCD0
_080A3EE8: .4byte 0xFFFFAA00
_080A3EEC:
	movs r0, #0xcc
	lsls r0, r0, #2
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	movs r2, #0xac
	lsls r2, r2, #7
	adds r0, r0, r2
_080A3EFA:
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3F02:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #2
	adds r0, #3
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A3F50 @ =0x0836B524
	adds r1, r1, r2
	bl SetDDP
	mov r1, sb
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A3F80
	ldr r2, [r7, #0x5c]
	cmp r2, #0
	bge _080A3F58
	ldr r0, _080A3F54 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _080A3F70
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	b _080A3F74
	.align 2, 0
_080A3F50: .4byte 0x0836B524
_080A3F54: .4byte pZero2
_080A3F58:
	ldr r0, _080A3F6C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080A3F70
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	b _080A3F74
	.align 2, 0
_080A3F6C: .4byte pZero2
_080A3F70:
	lsls r0, r2, #1
	adds r0, r0, r2
_080A3F74:
	lsls r0, r0, #7
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	movs r0, #0x14
	strb r0, [r7, #0xe]
	b _080A44AE
_080A3F80:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A3F98
	ldr r0, [r7, #0x54]
	ldr r2, _080A3F94 @ =0xFFFFEE00
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A3FA6
	.align 2, 0
_080A3F94: .4byte 0xFFFFEE00
_080A3F98:
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A3FA6:
	adds r1, r0, #0
	cmp r1, #0
	bne _080A3FAE
	b _080A44AE
_080A3FAE:
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	movs r0, #0x52
	bl PlaySound
	b _080A43E0
_080A3FBC:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	ldr r0, _080A4028 @ =0xFFFFFC00
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3FD4:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A3FE4
	str r1, [r7, #0x60]
_080A3FE4:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #2
	adds r0, #3
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A402C @ =0x0836B524
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A4034
	ldr r0, [r7, #0x54]
	ldr r2, _080A4030 @ =0xFFFFF800
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A4042
	.align 2, 0
_080A4028: .4byte 0xFFFFFC00
_080A402C: .4byte 0x0836B524
_080A4030: .4byte 0xFFFFF800
_080A4034:
	ldr r0, [r7, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A4042:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A404E
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_080A404E:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bne _080A4064
	b _080A44AE
_080A4064:
	movs r0, #0x52
	bl PlaySound
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
	b _080A43E0
_080A4072:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, _080A40DC @ =0xFFFFFD80
	str r0, [r7, #0x60]
	movs r1, #0
	mov r0, sb
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	strb r1, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A40A2:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A40B2
	str r1, [r7, #0x60]
_080A40B2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A40E0
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080A40E6
	.align 2, 0
_080A40DC: .4byte 0xFFFFFD80
_080A40E0:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A40E6:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	blt _080A40F0
	b _080A43AC
_080A40F0:
	ldr r0, [r7, #0x54]
	ldr r1, _080A4100 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A43BA
	.align 2, 0
_080A4100: .4byte 0xFFFFF800
_080A4104:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, _080A4194 @ =0xFFFFFF00
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x68]
	movs r1, #0
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	mov r0, sb
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A4140:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #5
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A415C
	str r1, [r7, #0x60]
_080A415C:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A417C
	subs r0, #1
	strb r0, [r7, #0x12]
_080A417C:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	bne _080A418A
	b _080A4490
_080A418A:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A4496
	.align 2, 0
_080A4194: .4byte 0xFFFFFF00
_080A4198:
	ldr r1, _080A4218 @ =0x0000AD08
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080A421C @ =0x0836B554
	bl SetDDP
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A41B0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #1
	adds r0, #3
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A4220 @ =0x0836B824
	adds r1, r1, r2
	bl SetDDP
	mov r1, sb
	ldr r0, [r1]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A4228
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	ldr r0, _080A4224 @ =0xFFFFFE00
	str r0, [r7, #0x60]
	movs r0, #0x52
	bl PlaySound
	movs r1, #0
	mov r2, sb
	str r1, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	b _080A43E0
	.align 2, 0
_080A4218: .4byte 0x0000AD08
_080A421C: .4byte 0x0836B554
_080A4220: .4byte 0x0836B824
_080A4224: .4byte 0xFFFFFE00
_080A4228:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A4240
	ldr r0, [r7, #0x54]
	ldr r1, _080A423C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A424E
	.align 2, 0
_080A423C: .4byte 0xFFFFEE00
_080A4240:
	ldr r0, [r7, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A424E:
	adds r4, r0, #0
	cmp r4, #0
	bne _080A4256
	b _080A44AE
_080A4256:
	movs r0, #0x52
	bl PlaySound
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	ldr r0, _080A4278 @ =0xFFFFFC00
	str r0, [r7, #0x60]
	b _080A43E0
	.align 2, 0
_080A4278: .4byte 0xFFFFFC00
_080A427C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A4282:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A4292
	str r1, [r7, #0x60]
_080A4292:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #1
	adds r0, #3
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A42D8 @ =0x0836B824
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A42E0
	ldr r0, [r7, #0x54]
	ldr r1, _080A42DC @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A42EE
	.align 2, 0
_080A42D8: .4byte 0x0836B824
_080A42DC: .4byte 0xFFFFF800
_080A42E0:
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A42EE:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A42FA
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_080A42FA:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bne _080A4310
	b _080A44AE
_080A4310:
	movs r0, #0x52
	bl PlaySound
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
	b _080A43E0
_080A431E:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	movs r1, #0
	mov r0, sb
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	strb r1, [r7, #0x12]
	ldr r0, _080A4388 @ =0xFFFFFD80
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A434E:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A435E
	str r1, [r7, #0x60]
_080A435E:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A438C
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080A4392
	.align 2, 0
_080A4388: .4byte 0xFFFFFD80
_080A438C:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A4392:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A43AC
	ldr r0, [r7, #0x54]
	ldr r1, _080A43A8 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A43BA
	.align 2, 0
_080A43A8: .4byte 0xFFFFF800
_080A43AC:
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A43BA:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A43C6
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_080A43C6:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A44AE
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_080A43E0:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080A44AE
_080A43E8:
	movs r5, #0
	mov r0, sb
	str r5, [r0]
	movs r1, #0x90
	adds r1, r1, r7
	mov r8, r1
	str r5, [r1]
	adds r6, r7, #0
	adds r6, #0x94
	strb r5, [r6]
	ldrb r1, [r7, #0xa]
	movs r4, #0xfb
	adds r0, r4, #0
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, _080A448C @ =0xFFFFFF00
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x68]
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	mov r2, sb
	str r5, [r2]
	mov r0, r8
	str r5, [r0]
	strb r5, [r6]
	ldrb r0, [r7, #0xa]
	ands r4, r0
	strb r4, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A443A:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #5
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A4456
	str r1, [r7, #0x60]
_080A4456:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A4476
	subs r0, #1
	strb r0, [r7, #0x12]
_080A4476:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080A4490
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A4496
	.align 2, 0
_080A448C: .4byte 0xFFFFFF00
_080A4490:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A4496:
	strb r0, [r7, #0xa]
	cmp r2, #0
	bne _080A44AE

	thumb_func_start FUN_080a449c
FUN_080a449c: @ 0x080A449C
	ldr r1, _080A44BC @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080A44AE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A44BC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a44c0
FUN_080a44c0: @ 0x080A44C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A44E2
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	b _080A4CB8
_080A44E2:
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bne _080A44EC
	movs r0, #8
	strb r0, [r4, #0xe]
_080A44EC:
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _080A44F4
	b _080A4CCA
_080A44F4:
	lsls r0, r0, #2
	ldr r1, _080A4500 @ =_080A4504
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A4500: .4byte _080A4504
_080A4504: @ jump table
	.4byte _080A4528 @ case 0
	.4byte _080A4588 @ case 1
	.4byte _080A45DC @ case 2
	.4byte _080A461E @ case 3
	.4byte _080A4674 @ case 4
	.4byte _080A4700 @ case 5
	.4byte _080A4B0C @ case 6
	.4byte _080A4B32 @ case 7
	.4byte _080A4B38 @ case 8
_080A4528:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0xad
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A4560
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A4566
_080A4560:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A4566:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4588:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A45A8
	ldr r0, [r4, #0x54]
	ldr r2, _080A45A4 @ =0xFFFFD600
	adds r0, r0, r2
	b _080A45B0
	.align 2, 0
_080A45A4: .4byte 0xFFFFD600
_080A45A8:
	ldr r0, [r4, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
_080A45B0:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, _080A45D8 @ =0xFFFF9C00
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080A45D0
	b _080A4CCA
_080A45D0:
	movs r0, #2
	rsbs r0, r0, #0
	b _080A4B26
	.align 2, 0
_080A45D8: .4byte 0xFFFF9C00
_080A45DC:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A45FC
	ldr r0, [r4, #0x54]
	ldr r1, _080A45F8 @ =0xFFFFD600
	adds r0, r0, r1
	b _080A4604
	.align 2, 0
_080A45F8: .4byte 0xFFFFD600
_080A45FC:
	ldr r0, [r4, #0x54]
	movs r2, #0xa8
	lsls r2, r2, #6
	adds r0, r0, r2
_080A4604:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _080A4638 @ =0xFFFF9C00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0xad
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A461E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4640
	ldr r0, [r4, #0x54]
	ldr r2, _080A463C @ =0xFFFFD600
	adds r0, r0, r2
	b _080A4648
	.align 2, 0
_080A4638: .4byte 0xFFFF9C00
_080A463C: .4byte 0xFFFFD600
_080A4640:
	ldr r0, [r4, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
_080A4648:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, _080A4670 @ =0xFFFF9C00
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A4668
	b _080A4CCA
_080A4668:
	movs r0, #9
	rsbs r0, r0, #0
	b _080A4B26
	.align 2, 0
_080A4670: .4byte 0xFFFF9C00
_080A4674:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	movs r1, #0xad
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r5, #0x58]
	ldr r1, _080A46A4 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A46B0
	ldr r0, [r4, #0x54]
	ldr r2, _080A46A8 @ =0xFFFF6800
	adds r1, r0, r2
	ldr r2, _080A46AC @ =0xFFFFE000
	b _080A46BC
	.align 2, 0
_080A46A4: .4byte 0xFFFFC000
_080A46A8: .4byte 0xFFFF6800
_080A46AC: .4byte 0xFFFFE000
_080A46B0:
	ldr r0, [r4, #0x54]
	movs r2, #0x98
	lsls r2, r2, #8
	adds r1, r0, r2
	movs r2, #0x80
	lsls r2, r2, #6
_080A46BC:
	adds r0, r0, r2
	str r0, [r4, #0x54]
	movs r0, #0x2c
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	subs r0, r1, r0
	movs r1, #0x2c
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xf2
	lsls r0, r0, #8
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x2c
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x2b
	strb r0, [r4, #0x12]
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r2, #0
	movs r3, #0
	bl CreateSolid13
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4700:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A4710
	str r1, [r4, #0x60]
_080A4710:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bne _080A4736
	b _080A491C
_080A4736:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080A4746
	b _080A48E8
_080A4746:
	movs r0, #0
	str r0, [r4, #0x2c]
	ldr r0, _080A48BC @ =0x00000113
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x8c
	str r0, [sp, #0x24]
	adds r1, r4, #0
	adds r1, #0x90
	str r1, [sp, #0x28]
	adds r2, r4, #0
	adds r2, #0x94
	str r2, [sp, #0x2c]
	mov r7, sp
	ldr r5, _080A48C0 @ =0x0836B9EC
	ldr r6, _080A48C4 @ =RNG_0202f388
	ldr r0, _080A48C8 @ =0x000343FD
	mov sl, r0
	ldr r1, _080A48CC @ =0x00269EC3
	mov sb, r1
	movs r2, #3
	mov r8, r2
	movs r0, #1
	str r0, [sp, #0x18]
_080A4778:
	ldr r0, [r4, #0x54]
	ldr r1, [r5]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5]
	ldr r2, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	mov r0, sp
	ldr r2, _080A48D4 @ =0x0000AD01
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #8]
	ldr r0, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	mov r0, sp
	ldr r2, _080A48D8 @ =0x0000AD02
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #0x10]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #0x10]
	ldr r2, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	mov r0, sp
	ldr r2, _080A48DC @ =0x0000AD03
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #0x18]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #0x18]
	ldr r0, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	mov r0, sp
	ldr r2, _080A48E0 @ =0x0000AD04
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #0x20]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #0x20]
	ldr r2, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	mov r0, sp
	ldr r2, _080A48E4 @ =0x0000AD05
	bl FUN_080bec8c
	adds r5, #0x28
	ldr r0, [sp, #0x18]
	subs r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0
	blt _080A489E
	b _080A4778
_080A489E:
	movs r1, #0
	ldrb r2, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r4, #0xa]
	ldr r2, [sp, #0x24]
	str r1, [r2]
	ldr r0, [sp, #0x28]
	str r1, [r0]
	ldr r2, [sp, #0x2c]
	strb r1, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	b _080A4CB4
	.align 2, 0
_080A48BC: .4byte 0x00000113
_080A48C0: .4byte 0x0836B9EC
_080A48C4: .4byte RNG_0202f388
_080A48C8: .4byte 0x000343FD
_080A48CC: .4byte 0x00269EC3
_080A48D0: .4byte 0xFFFFE200
_080A48D4: .4byte 0x0000AD01
_080A48D8: .4byte 0x0000AD02
_080A48DC: .4byte 0x0000AD03
_080A48E0: .4byte 0x0000AD04
_080A48E4: .4byte 0x0000AD05
_080A48E8:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r3, [r4, #0xa]
	movs r2, #0xfb
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r4, #0xa]
	ldr r3, [r4, #0x2c]
	adds r0, r3, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r0, [r3, #0xa]
	ands r2, r0
	strb r2, [r3, #0xa]
	str r1, [r4, #0x2c]
	b _080A4B2A
_080A491C:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080A493C
	ldr r0, [r4, #0x54]
	ldr r1, _080A4934 @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A4938 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight2
	b _080A494E
	.align 2, 0
_080A4934: .4byte 0xFFFFE000
_080A4938: .4byte 0xFFFFF800
_080A493C:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A4ADC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft2
_080A494E:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A495E
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x5c]
_080A495E:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080A4968
	b _080A4CCA
_080A4968:
	movs r0, #0
	str r0, [r4, #0x2c]
	ldr r0, _080A4AE0 @ =0x00000113
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x8c
	str r0, [sp, #0x24]
	adds r1, r4, #0
	adds r1, #0x90
	str r1, [sp, #0x28]
	adds r2, r4, #0
	adds r2, #0x94
	str r2, [sp, #0x2c]
	add r5, sp, #8
	ldr r6, _080A4AE4 @ =0x0836B9EC
	ldr r7, _080A4AE8 @ =RNG_0202f388
	ldr r0, _080A4AEC @ =0x000343FD
	mov sl, r0
	ldr r1, _080A4AF0 @ =0x00269EC3
	mov sb, r1
	movs r2, #3
	mov r8, r2
	movs r0, #1
	str r0, [sp, #0x1c]
_080A499A:
	ldr r0, [r4, #0x54]
	ldr r1, [r6]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6]
	ldr r2, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4AF8 @ =0x0000AD01
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #8]
	ldr r0, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4AFC @ =0x0000AD02
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x10]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #0x10]
	ldr r2, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4B00 @ =0x0000AD03
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x18]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #0x18]
	ldr r0, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4B04 @ =0x0000AD04
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x20]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #0x20]
	ldr r2, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4B08 @ =0x0000AD05
	bl FUN_080bec8c
	adds r6, #0x28
	ldr r0, [sp, #0x1c]
	subs r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #0
	blt _080A4AC0
	b _080A499A
_080A4AC0:
	movs r1, #0
	ldrb r2, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r4, #0xa]
	ldr r2, [sp, #0x24]
	str r1, [r2]
	ldr r0, [sp, #0x28]
	str r1, [r0]
	ldr r2, [sp, #0x2c]
	strb r1, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	b _080A4CB4
	.align 2, 0
_080A4ADC: .4byte 0xFFFFF800
_080A4AE0: .4byte 0x00000113
_080A4AE4: .4byte 0x0836B9EC
_080A4AE8: .4byte RNG_0202f388
_080A4AEC: .4byte 0x000343FD
_080A4AF0: .4byte 0x00269EC3
_080A4AF4: .4byte 0xFFFFE200
_080A4AF8: .4byte 0x0000AD01
_080A4AFC: .4byte 0x0000AD02
_080A4B00: .4byte 0x0000AD03
_080A4B04: .4byte 0x0000AD04
_080A4B08: .4byte 0x0000AD05
_080A4B0C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4B22
	b _080A4CCA
_080A4B22:
	movs r0, #0x11
	rsbs r0, r0, #0
_080A4B26:
	ands r1, r0
	str r1, [r2]
_080A4B2A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A4CCA
_080A4B32:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4B38:
	ldr r0, _080A4CDC @ =0x00000113
	bl PlaySound
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _080A4B74
	adds r0, r4, #0
	adds r0, #0x8c
	movs r2, #0
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r3, [r4, #0xa]
	movs r1, #0xfb
	adds r0, r1, #0
	ands r0, r3
	strb r0, [r4, #0xa]
	ldr r3, [r4, #0x2c]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r0, [r3, #0xa]
	ands r1, r0
	strb r1, [r3, #0xa]
_080A4B74:
	add r5, sp, #0x10
	ldr r6, _080A4CE0 @ =0x0836B9EC
	ldr r7, _080A4CE4 @ =RNG_0202f388
	ldr r0, _080A4CE8 @ =0x000343FD
	mov sl, r0
	ldr r1, _080A4CEC @ =0x00269EC3
	mov sb, r1
	movs r2, #3
	mov r8, r2
	movs r0, #1
	str r0, [sp, #0x20]
_080A4B8A:
	ldr r0, [r4, #0x54]
	ldr r1, [r6]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6]
	ldr r2, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4CF4 @ =0x0000AD01
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #8]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #8]
	ldr r0, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4CF8 @ =0x0000AD02
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x10]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #0x10]
	ldr r2, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4CFC @ =0x0000AD03
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x18]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #0x18]
	ldr r0, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4D00 @ =0x0000AD04
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x20]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #0x20]
	ldr r2, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4D04 @ =0x0000AD05
	bl FUN_080bec8c
	adds r6, #0x28
	ldr r0, [sp, #0x20]
	subs r0, #1
	str r0, [sp, #0x20]
	cmp r0, #0
	blt _080A4CB0
	b _080A4B8A
_080A4CB0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
_080A4CB4:
	ands r0, r1
	strb r0, [r4, #0xa]
_080A4CB8:
	ldr r1, _080A4D08 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A4CCA:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4CDC: .4byte 0x00000113
_080A4CE0: .4byte 0x0836B9EC
_080A4CE4: .4byte RNG_0202f388
_080A4CE8: .4byte 0x000343FD
_080A4CEC: .4byte 0x00269EC3
_080A4CF0: .4byte 0xFFFFE200
_080A4CF4: .4byte 0x0000AD01
_080A4CF8: .4byte 0x0000AD02
_080A4CFC: .4byte 0x0000AD03
_080A4D00: .4byte 0x0000AD04
_080A4D04: .4byte 0x0000AD05
_080A4D08: .4byte gProjectileFnTable

	thumb_func_start FUN_080a4d0c
FUN_080a4d0c: @ 0x080A4D0C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A4D1A
	b _080A4EDC
_080A4D1A:
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bne _080A4D22
	b _080A4EDC
_080A4D22:
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080A4D2A
	b _080A4EEE
_080A4D2A:
	lsls r0, r0, #2
	ldr r1, _080A4D34 @ =_080A4D38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A4D34: .4byte _080A4D38
_080A4D38: @ jump table
	.4byte _080A4D50 @ case 0
	.4byte _080A4DB0 @ case 1
	.4byte _080A4DEA @ case 2
	.4byte _080A4E48 @ case 3
	.4byte _080A4E8E @ case 4
	.4byte _080A4EA2 @ case 5
_080A4D50:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A4D80 @ =0x0836B9BC
	bl SetDDP
	ldr r1, _080A4D84 @ =0x0000AE01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A4D88
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A4D8E
	.align 2, 0
_080A4D80: .4byte 0x0836B9BC
_080A4D84: .4byte 0x0000AE01
_080A4D88:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A4D8E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4DB0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4DD4
	ldr r0, [r4, #0x54]
	ldr r1, _080A4DD0 @ =0xFFFFC000
	b _080A4DDA
	.align 2, 0
_080A4DD0: .4byte 0xFFFFC000
_080A4DD4:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #7
_080A4DDA:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	b _080A4E80
_080A4DEA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r1, _080A4E18 @ =0x0000AE02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A4E1C @ =0x0836B9D4
	bl SetDDP
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A4E20
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A4E26
	.align 2, 0
_080A4E18: .4byte 0x0000AE02
_080A4E1C: .4byte 0x0836B9D4
_080A4E20:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A4E26:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4E48:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4E6C
	ldr r0, [r4, #0x54]
	ldr r1, _080A4E68 @ =0xFFFFC000
	b _080A4E72
	.align 2, 0
_080A4E68: .4byte 0xFFFFC000
_080A4E6C:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #7
_080A4E72:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
_080A4E80:
	ands r0, r1
	cmp r0, #0
	beq _080A4EEE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A4EEE
_080A4E8E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A4EC0 @ =0x0836B9A4
	bl SetDDP
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4EA2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	cmp r1, #0x1d
	bhi _080A4ECC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A4EC4
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A4ECA
	.align 2, 0
_080A4EC0: .4byte 0x0836B9A4
_080A4EC4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A4ECA:
	strb r0, [r4, #0xa]
_080A4ECC:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A4EDC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A4EEE
_080A4EDC:
	ldr r1, _080A4EF4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A4EEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4EF4: .4byte gProjectileFnTable

	thumb_func_start FUN_080a4ef8
FUN_080a4ef8: @ 0x080A4EF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A4F34 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A4F2E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A4F38 @ =gProjectileFnTable
	movs r0, #0x14
	strb r0, [r3, #9]
	ldr r0, [r1, #0x50]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
_080A4F2E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4F34: .4byte gProjectileHeaderPtr
_080A4F38: .4byte gProjectileFnTable

	thumb_func_start FUN_080a4f3c
FUN_080a4f3c: @ 0x080A4F3C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, _080A4F90 @ =RNG_0202f388
	movs r6, #3
_080A4F44:
	ldr r4, [r5, #0x54]
	ldr r0, _080A4F94 @ =0xFFFFF000
	adds r4, r4, r0
	ldr r1, [r7]
	ldr r0, _080A4F98 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080A4F9C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsls r0, r0, #2
	lsrs r0, r0, #0x13
	adds r4, r4, r0
	ldr r1, [r5, #0x58]
	adds r0, r4, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, _080A4FA0 @ =0x00002FFF
	cmp r0, r1
	bhi _080A4F84
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #1
	bl FUN_080bf438
_080A4F84:
	subs r6, #1
	cmp r6, #0
	bge _080A4F44
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4F90: .4byte RNG_0202f388
_080A4F94: .4byte 0xFFFFF000
_080A4F98: .4byte 0x000343FD
_080A4F9C: .4byte 0x00269EC3
_080A4FA0: .4byte 0x00002FFF

	thumb_func_start FUN_080a4fa4
FUN_080a4fa4: @ 0x080A4FA4
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r5, [r3, #0x28]
	adds r0, #0xb4
	ldrh r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A4FBE
	rsbs r0, r4, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080A4FBE:
	ldr r6, [r5, #0x54]
	str r6, [r3, #0x54]
	ldr r2, _080A4FF8 @ =gSineTable
	lsrs r0, r4, #8
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xb
	rsbs r0, r0, #0
	adds r7, r2, #0
	lsrs r2, r4, #8
	cmp r0, #0
	bge _080A4FE0
	adds r0, #0xff
_080A4FE0:
	asrs r0, r0, #8
	adds r0, r6, r0
	str r0, [r3, #0x54]
	ldr r1, _080A4FFC @ =0xFFFFC000
	adds r0, r4, r1
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _080A5000
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #0x17
	b _080A5006
	.align 2, 0
_080A4FF8: .4byte gSineTable
_080A4FFC: .4byte 0xFFFFC000
_080A5000:
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #0x19
_080A5006:
	strb r0, [r1]
	ldr r1, [r5, #0x58]
	str r1, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb8
	ldr r0, [r0]
	asrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r7
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #2
	adds r1, r1, r0
	str r1, [r3, #0x58]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r7
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #0xa
	rsbs r0, r0, #0
	cmp r0, #0
	bge _080A503C
	adds r0, #0xff
_080A503C:
	asrs r0, r0, #8
	adds r0, r1, r0
	str r0, [r3, #0x58]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start nop_080a5048
nop_080a5048: @ 0x080A5048
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a504c
FUN_080a504c: @ 0x080A504C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080A50AC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080A50B0 @ =0x0836BAE8
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
	ldr r1, _080A50B4 @ =0x0836BAA0
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080A50B8 @ =nop_080a5048
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080a50bc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A50AC: .4byte gProjectileFnTable
_080A50B0: .4byte 0x0836BAE8
_080A50B4: .4byte 0x0836BAA0
_080A50B8: .4byte nop_080a5048

	thumb_func_start FUN_080a50bc
FUN_080a50bc: @ 0x080A50BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A50D6
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _080A50D6
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A50D6:
	ldr r1, _080A50FC @ =0x0836BA50
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080A5100 @ =0x0836BA78
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A50FC: .4byte 0x0836BA50
_080A5100: .4byte 0x0836BA78

	thumb_func_start FUN_080a5104
FUN_080a5104: @ 0x080A5104
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080A5140 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5140: .4byte gProjectileFnTable
_080A5144:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a5148
FUN_080a5148: @ 0x080A5148
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080A5158
	cmp r5, #1
	beq _080A5180
	b _080A51A8
_080A5158:
	adds r0, r4, #0
	adds r0, #0xb4
	str r5, [r0]
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r1]
	subs r1, #0x93
	movs r0, #0x19
	strb r0, [r1]
	movs r1, #0x92
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A5180:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [r0]
	ldr r0, _080A51B0 @ =0x00003FFF
	cmp r1, r0
	ble _080A519C
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A519C:
	adds r0, r4, #0
	bl FUN_080a4fa4
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A51A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A51B0: .4byte 0x00003FFF

	thumb_func_start FUN_080a51b4
FUN_080a51b4: @ 0x080A51B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A51C6
	cmp r0, #1
	beq _080A5222
	b _080A5288
_080A51C6:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A51EC @ =0x0836BAD0
	bl SetDDP
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A51F0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A51F6
	.align 2, 0
_080A51EC: .4byte 0x0836BAD0
_080A51F0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A51F6:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0x92
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A5222:
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080a4fa4
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x17
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080A5258
	strb r1, [r4, #0xd]
	strb r3, [r4, #0xe]
_080A5258:
	ldr r0, [r2]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080A5268
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
_080A5268:
	ldr r0, [r2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080A5278
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
_080A5278:
	ldr r0, [r2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080A5288
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
_080A5288:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5290:
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x07, 0x1C, 0xBD, 0x6A, 0xB8, 0x7B, 0x01, 0x28, 0x3F, 0xD0
	.byte 0x01, 0x28, 0x02, 0xDC, 0x00, 0x28, 0x06, 0xD0, 0x96, 0xE0, 0x02, 0x28, 0x62, 0xD0, 0x03, 0x28
	.byte 0x00, 0xD1, 0x84, 0xE0, 0x90, 0xE0, 0x38, 0x1C, 0x74, 0x30, 0x0A, 0x49, 0x61, 0xF7, 0xAA, 0xFF
	.byte 0x39, 0x1C, 0x25, 0x31, 0x17, 0x20, 0x08, 0x70, 0x38, 0x1C, 0x72, 0xF7, 0x61, 0xF8, 0xA8, 0x7A
	.byte 0x02, 0x09, 0x01, 0x20, 0x02, 0x40, 0x00, 0x2A, 0x06, 0xD0, 0xB8, 0x7A, 0x10, 0x21, 0x08, 0x43
	.byte 0x05, 0xE0, 0x00, 0x00, 0xB8, 0xBA, 0x36, 0x08, 0xB9, 0x7A, 0xEF, 0x20, 0x08, 0x40, 0xB8, 0x72
	.byte 0x11, 0x1C, 0x38, 0x1C, 0x4C, 0x30, 0x00, 0x24, 0x01, 0x70, 0x3B, 0x1C, 0x4A, 0x33, 0x09, 0x01
	.byte 0x1A, 0x78, 0x11, 0x20, 0x40, 0x42, 0x10, 0x40, 0x08, 0x43, 0x18, 0x70, 0x18, 0x49, 0x38, 0x1C
	.byte 0x72, 0xF7, 0x2A, 0xF9, 0xBC, 0x74, 0x10, 0x20, 0xF8, 0x74, 0xB8, 0x7B, 0x01, 0x30, 0xB8, 0x73
	.byte 0xF8, 0x7C, 0x01, 0x38, 0xF8, 0x74, 0x00, 0x06, 0x00, 0x28, 0x02, 0xD1, 0xB8, 0x7B, 0x01, 0x30
	.byte 0xB8, 0x73, 0x68, 0x6D, 0x7C, 0x6D, 0x06, 0x1B, 0xA8, 0x6D, 0xB9, 0x6D, 0x88, 0x46, 0x45, 0x1A
	.byte 0x30, 0x02, 0xE0, 0x26, 0x76, 0x00, 0x31, 0x1C, 0x59, 0xF0, 0xEA, 0xF9, 0x24, 0x18, 0x7C, 0x65
	.byte 0x28, 0x02, 0x31, 0x1C, 0x59, 0xF0, 0xE4, 0xF9, 0x40, 0x44, 0xB8, 0x65, 0xB8, 0x7C, 0x10, 0x30
	.byte 0xB8, 0x74, 0x39, 0x1C, 0x24, 0x31, 0x08, 0x70, 0x38, 0x1C, 0x72, 0xF7, 0x77, 0xF9, 0x33, 0xE0
	.byte 0x01, 0x49, 0x00, 0x00, 0x1B, 0x48, 0x00, 0x68, 0x40, 0x6D, 0x79, 0x6D, 0x46, 0x1A, 0xB9, 0x6D
	.byte 0x64, 0xF7, 0xF4, 0xFD, 0xB9, 0x6D, 0x45, 0x1A, 0x30, 0x02, 0x00, 0x14, 0x29, 0x02, 0x09, 0x14
	.byte 0x59, 0xF0, 0xD0, 0xF8, 0x00, 0x04, 0x00, 0x0E, 0x02, 0x1C, 0x40, 0x32, 0xBA, 0x74, 0xB9, 0x7A
	.byte 0x10, 0x20, 0x08, 0x40, 0x00, 0x28, 0x01, 0xD0, 0x50, 0x42, 0xB8, 0x74, 0xB9, 0x7C, 0x38, 0x1C
	.byte 0x24, 0x30, 0x01, 0x70, 0x14, 0x20, 0xF8, 0x74, 0xB8, 0x7B, 0x01, 0x30, 0xB8, 0x73, 0xF8, 0x7C
	.byte 0x01, 0x38, 0xF8, 0x74, 0x00, 0x06, 0x01, 0x0E, 0x00, 0x29, 0x02, 0xD1, 0x03, 0x20, 0x78, 0x73
	.byte 0xB9, 0x73, 0x38, 0x1C, 0x72, 0xF7, 0x42, 0xF9, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x40, 0xF3, 0x02, 0x02

	thumb_func_start FUN_080a53e8
FUN_080a53e8: @ 0x080A53E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A547A
	cmp r0, #1
	bgt _080A53FE
	cmp r0, #0
	beq _080A5408
	b _080A54F0
_080A53FE:
	cmp r0, #2
	beq _080A54C0
	cmp r0, #3
	beq _080A54CA
	b _080A54F0
_080A5408:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A54B4 @ =0x0836BAB8
	bl SetDDP
	ldr r1, _080A54B8 @ =0x00004901
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A542C
	rsbs r0, r2, #0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080A542C:
	adds r0, r2, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	ldr r3, _080A54BC @ =gSineTable
	lsrs r2, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	cmp r0, #0
	bge _080A5454
	adds r0, #0xff
_080A5454:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	cmp r0, #0
	bge _080A5470
	adds r0, #0xff
_080A5470:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A547A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r1, r5
	bl PushoutToUp1
	cmp r0, #0
	bge _080A549E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A549E:
	ldrb r0, [r4, #0x12]
	adds r0, #0x10
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080A54F0
	.align 2, 0
_080A54B4: .4byte 0x0836BAB8
_080A54B8: .4byte 0x00004901
_080A54BC: .4byte gSineTable
_080A54C0:
	movs r0, #0x3c
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A54CA:
	ldrb r0, [r4, #0x12]
	adds r0, #0x10
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A54F0
	strb r1, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080A54F0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A54F8:
	.byte 0x70, 0xB5, 0x04, 0x1C, 0xA5, 0x6A, 0xA0, 0x7B
	.byte 0x01, 0x28, 0x69, 0xD0, 0x01, 0x28, 0x02, 0xDC, 0x00, 0x28, 0x07, 0xD0, 0xC3, 0xE0, 0x02, 0x28
	.byte 0x00, 0xD1, 0x81, 0xE0, 0x03, 0x28, 0x00, 0xD1, 0x99, 0xE0, 0xBC, 0xE0, 0x20, 0x1C, 0x74, 0x30
	.byte 0x16, 0x49, 0x61, 0xF7, 0x77, 0xFE, 0x28, 0x1C, 0xC0, 0x30, 0x00, 0x68, 0x10, 0x26, 0x30, 0x40
	.byte 0x00, 0x28, 0x27, 0xD0, 0xA3, 0x6D, 0xA8, 0x6D, 0x1B, 0x1A, 0x18, 0x1C, 0x00, 0x2B, 0x00, 0xDA
	.byte 0xD8, 0x1D, 0xC0, 0x10, 0x59, 0xF0, 0x02, 0xF8, 0x00, 0x04, 0x03, 0x0C, 0x18, 0x01, 0x40, 0x42
	.byte 0x20, 0x66, 0xA6, 0x66, 0xE3, 0x74, 0x6D, 0x6D, 0x09, 0x49, 0x68, 0x18, 0xE0, 0x65, 0x02, 0x1C
	.byte 0xA1, 0x7A, 0x30, 0x1C, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD0, 0xC0, 0x20, 0x40, 0x01, 0x2A, 0x18
	.byte 0x60, 0x6D, 0x10, 0x1A, 0xE0, 0x65, 0x19, 0x1C, 0x28, 0xE0, 0x00, 0x00, 0xB8, 0xBA, 0x36, 0x08
	.byte 0x00, 0xE8, 0xFF, 0xFF, 0xA3, 0x6D, 0xA8, 0x6D, 0x1B, 0x1A, 0x18, 0x1C, 0x00, 0x2B, 0x00, 0xDA
	.byte 0xD8, 0x1D, 0xC0, 0x10, 0x58, 0xF0, 0xDA, 0xFF, 0x00, 0x04, 0x03, 0x0C, 0x18, 0x01, 0x40, 0x42
	.byte 0x20, 0x66, 0xA6, 0x66, 0xE3, 0x74, 0x28, 0x1C, 0xB8, 0x30, 0x02, 0x68, 0x19, 0x49, 0x50, 0x18
	.byte 0xE0, 0x65, 0x03, 0x1C, 0xA1, 0x7A, 0x30, 0x1C, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x98, 0x20
	.byte 0xC0, 0x01, 0x13, 0x18, 0x60, 0x6D, 0x18, 0x1A, 0xE0, 0x65, 0xE1, 0x7C, 0x59, 0xF0, 0xA8, 0xF8
	.byte 0xE0, 0x65, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xE0, 0x7C, 0x01, 0x38, 0xE0, 0x74, 0x00, 0x06
	.byte 0x00, 0x28, 0x02, 0xD1, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xA0, 0x7C, 0x10, 0x30, 0xA0, 0x74
	.byte 0x21, 0x1C, 0x24, 0x31, 0x08, 0x70, 0x60, 0x6D, 0xE1, 0x6D, 0x40, 0x18, 0x60, 0x65, 0xA0, 0x6D
	.byte 0x21, 0x6E, 0x40, 0x18, 0xA0, 0x65, 0xA0, 0x6E, 0x09, 0x18, 0x21, 0x66, 0x20, 0x1C, 0x72, 0xF7
	.byte 0x25, 0xF8, 0x40, 0xE0, 0x00, 0xB4, 0xFF, 0xFF, 0x21, 0x1C, 0xB8, 0x31, 0x00, 0x20, 0x08, 0x60
	.byte 0x04, 0x39, 0x80, 0x20, 0xC0, 0x01, 0x08, 0x60, 0xA0, 0x7C, 0x00, 0x02, 0x20, 0x66, 0x80, 0x21
	.byte 0x89, 0x02, 0x0B, 0x1A, 0x18, 0x1C, 0x00, 0x2B, 0x00, 0xDA, 0x3F, 0x30, 0x80, 0x11, 0x58, 0xF0
	.byte 0x85, 0xFF, 0x00, 0x04, 0x40, 0x0A, 0xE0, 0x65, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x6E
	.byte 0xE1, 0x6D, 0x40, 0x18, 0x20, 0x66, 0x80, 0x39, 0xE1, 0x65, 0x00, 0x29, 0x0C, 0xDA, 0x00, 0x21
	.byte 0x21, 0x66, 0x01, 0x20, 0x60, 0x73, 0xA1, 0x73, 0x2A, 0x1C, 0xC0, 0x32, 0x10, 0x68, 0x05, 0x39
	.byte 0x08, 0x40, 0x0C, 0x39, 0x08, 0x40, 0x10, 0x60, 0x20, 0x6E, 0x00, 0x12, 0x21, 0x1C, 0x24, 0x31
	.byte 0x08, 0x70, 0x20, 0x1C, 0xFF, 0xF7, 0x8E, 0xFC, 0x21, 0x1C, 0x25, 0x31, 0x17, 0x20, 0x08, 0x70
	.byte 0x20, 0x1C, 0x71, 0xF7, 0xE3, 0xFF, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a569c
FUN_080a569c: @ 0x080A569C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r5, [r7, #0x28]
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _080A5724
	cmp r0, #1
	bgt _080A56B2
	cmp r0, #0
	beq _080A56BC
	b _080A57A6
_080A56B2:
	cmp r0, #2
	beq _080A5764
	cmp r0, #3
	beq _080A5770
	b _080A57A6
_080A56BC:
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080A56E8 @ =0x0836BAD0
	bl SetDDP
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	adds r0, r7, #0
	bl InitRotatableMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A56EC
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A56F2
	.align 2, 0
_080A56E8: .4byte 0x0836BAD0
_080A56EC:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A56F2:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _080A5760 @ =0x00004901
	adds r0, r7, #0
	bl SetMotion
	strb r4, [r7, #0x12]
	movs r0, #0x10
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A5724:
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A5736
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A5736:
	ldr r0, [r5, #0x54]
	ldr r4, [r7, #0x54]
	subs r0, r0, r4
	ldr r5, [r5, #0x58]
	ldr r6, [r7, #0x58]
	subs r5, r5, r6
	movs r1, #6
	bl __divsi3
	adds r4, r4, r0
	str r4, [r7, #0x54]
	adds r0, r5, #0
	movs r1, #6
	bl __divsi3
	adds r6, r6, r0
	str r6, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _080A57A6
	.align 2, 0
_080A5760: .4byte 0x00004901
_080A5764:
	movs r0, #0
	strb r0, [r7, #0x12]
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A5770:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _080A5786
	movs r0, #6
	strb r0, [r7, #0xd]
	movs r0, #0
	strb r0, [r7, #0xe]
_080A5786:
	ldrb r0, [r7, #0x13]
	cmp r0, #0x10
	bls _080A5792
	ldrb r0, [r7, #0x12]
	adds r0, #0x10
	b _080A5796
_080A5792:
	ldrb r1, [r7, #0x12]
	adds r0, r0, r1
_080A5796:
	strb r0, [r7, #0x12]
	ldrb r1, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080A57A6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a57ac
FUN_080a57ac: @ 0x080A57AC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, [r5, #0x28]
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080A57E2
	cmp r0, #1
	bgt _080A57C2
	cmp r0, #0
	beq _080A57CC
	b _080A5946
_080A57C2:
	cmp r0, #2
	beq _080A5870
	cmp r0, #3
	beq _080A588C
	b _080A5946
_080A57CC:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A5818 @ =0x0836BAB8
	bl SetDDP
	movs r0, #0xb0
	lsls r0, r0, #2
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A57E2:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	cmp r1, #0
	ble _080A5820
	ldr r0, [r5, #0x54]
	ldr r1, _080A581C @ =0xFFFFF000
	adds r0, r0, r1
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r2, r4
	bl PushoutToUp1
	adds r6, r0, #0
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r6, #0
	bne _080A5850
	cmp r2, #0
	beq _080A5856
	b _080A5850
	.align 2, 0
_080A5818: .4byte 0x0836BAB8
_080A581C: .4byte 0xFFFFF000
_080A5820:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A583A
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, r1
	bl PushoutToLeft1
	b _080A584A
_080A583A:
	ldr r0, [r5, #0x54]
	ldr r3, _080A586C @ =0xFFFFF000
	adds r0, r0, r3
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r2, r3
	bl PushoutToRight1
_080A584A:
	adds r6, r0, #0
	cmp r6, #0
	bne _080A5856
_080A5850:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A5856:
	ldrb r0, [r5, #0x12]
	adds r0, #0x10
	strb r0, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080A5946
	.align 2, 0
_080A586C: .4byte 0xFFFFF000
_080A5870:
	ldr r0, _080A58B8 @ =0xFFFFFD40
	str r0, [r5, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A5884
	movs r2, #0xb0
	lsls r2, r2, #2
_080A5884:
	str r2, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A588C:
	ldr r1, [r5, #0x54]
	ldr r0, [r5, #0x5c]
	adds r2, r1, r0
	str r2, [r5, #0x54]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A58C0
	movs r4, #0x80
	lsls r4, r4, #5
	adds r0, r2, r4
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	adds r6, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, _080A58BC @ =0xFFFFF000
	adds r0, r0, r1
	b _080A58D6
	.align 2, 0
_080A58B8: .4byte 0xFFFFFD40
_080A58BC: .4byte 0xFFFFF000
_080A58C0:
	ldr r3, _080A58F0 @ =0xFFFFF000
	adds r0, r2, r3
	ldr r1, [r5, #0x58]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r1, r4
	bl FUN_08009f6c
	adds r6, r0, #0
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
_080A58D6:
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	subs r3, r6, r0
	ldr r1, _080A58F4 @ =0xFFFFE800
	adds r4, r0, #0
	cmp r3, r1
	bge _080A58FC
	ldr r0, _080A58F8 @ =0xFFFFFD40
	b _080A590E
	.align 2, 0
_080A58F0: .4byte 0xFFFFF000
_080A58F4: .4byte 0xFFFFE800
_080A58F8: .4byte 0xFFFFFD40
_080A58FC:
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r3, r1
	ble _080A5916
	subs r0, r2, r4
	cmp r0, r1
	ble _080A5916
	movs r0, #0xb0
	lsls r0, r0, #2
_080A590E:
	str r0, [r5, #0x60]
	movs r0, #1
	strb r0, [r5, #0xe]
	b _080A5934
_080A5916:
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	bl FUN_08009f6c
	adds r6, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r6, r0
	ldr r1, _080A5980 @ =0x000017FF
	cmp r0, r1
	bgt _080A5934
	ldr r3, _080A5984 @ =0xFFFFF000
	adds r0, r6, r3
	str r0, [r5, #0x58]
_080A5934:
	ldrb r0, [r5, #0x12]
	adds r0, #0x10
	strb r0, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080A5946:
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	subs r2, r1, r0
	ldr r0, _080A5988 @ =0xFFFFA800
	cmp r2, r0
	bge _080A5960
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A5972
_080A5960:
	movs r0, #0xb0
	lsls r0, r0, #7
	cmp r2, r0
	ble _080A597A
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A597A
_080A5972:
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080A597A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5980: .4byte 0x000017FF
_080A5984: .4byte 0xFFFFF000
_080A5988: .4byte 0xFFFFA800

	thumb_func_start FUN_080a598c
FUN_080a598c: @ 0x080A598C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080A5A10
	cmp r0, #1
	bgt _080A59A2
	cmp r0, #0
	beq _080A59A8
	b _080A5AB0
_080A59A2:
	cmp r0, #2
	beq _080A5A4C
	b _080A5AB0
_080A59A8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A59CC @ =0x0836BAB8
	bl SetDDP
	adds r0, r5, #0
	bl InitRotatableMotion
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A59D0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A59D6
	.align 2, 0
_080A59CC: .4byte 0x0836BAB8
_080A59D0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A59D6:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
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
	ldr r1, _080A5A48 @ =0x00004901
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	strb r4, [r5, #0x12]
	strb r4, [r5, #0x13]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A5A10:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0x13]
	adds r1, r1, r0
	strb r1, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	ldr r1, [r5, #0x58]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	cmp r0, #0
	bge _080A5AB0
	adds r0, r5, #0
	bl FUN_080a4f3c
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A5AB0
	.align 2, 0
_080A5A48: .4byte 0x00004901
_080A5A4C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A5AB8 @ =0x0836BAA0
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r3, #0xfe
	adds r0, r3, #0
	ands r0, r1
	movs r2, #0
	strb r0, [r5, #0xa]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080A5A76
	movs r0, #8
	strb r0, [r5, #0xd]
	strb r2, [r5, #0xe]
_080A5A76:
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _080A5AB0
	ldrb r1, [r5, #0xa]
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080A5ABC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080A5AB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5AB8: .4byte 0x0836BAA0
_080A5ABC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a5ac0
FUN_080a5ac0: @ 0x080A5AC0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A5AD0
	cmp r0, #1
	beq _080A5AEE
	b _080A5B1C
_080A5AD0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A5B24 @ =0x0836BAB8
	bl SetDDP
	adds r0, r4, #0
	bl FUN_080a4f3c
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A5AEE:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	subs r1, #0x40
	str r1, [r4, #0x60]
	ldrb r1, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	subs r1, r1, r0
	strb r1, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080A5B14
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A5B14:
	ldrb r1, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
_080A5B1C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5B24: .4byte 0x0836BAB8

	thumb_func_start FUN_080a5b28
FUN_080a5b28: @ 0x080A5B28
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A5B3A
	cmp r0, #1
	beq _080A5B62
	b _080A5BA8
_080A5B3A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A5BB0 @ =0x0836BAD0
	bl SetDDP
	movs r0, #0x80
	lsls r0, r0, #3
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xb
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xb4
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A5B62:
	adds r3, r4, #0
	adds r3, #0xb4
	ldr r0, [r3]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r3]
	movs r1, #0xc0
	lsls r1, r1, #0xa
	cmp r0, r1
	ble _080A5B7C
	ldr r0, [r4, #0x5c]
	subs r0, #0x20
	str r0, [r4, #0x5c]
_080A5B7C:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bgt _080A5B9C
	adds r2, r5, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #0x81
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r3]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080A5B9C:
	adds r0, r4, #0
	bl FUN_080a4fa4
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080A5BA8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5BB0: .4byte 0x0836BAD0

	thumb_func_start FUN_080a5bb4
FUN_080a5bb4: @ 0x080A5BB4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r4, #0
	movs r5, #0
	ldr r0, _080A5C08 @ =gProjectileFnTable
	mov r8, r0
_080A5BC6:
	ldr r0, _080A5C0C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5BF8
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #8
	strb r0, [r2]
	movs r0, #0x15
	strb r0, [r1, #9]
	mov r2, r8
	ldr r0, [r2, #0x54]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r5, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r5, [r0]
	strb r5, [r1, #0x10]
	strb r4, [r1, #0x12]
	str r7, [r1, #0x54]
	str r6, [r1, #0x58]
_080A5BF8:
	adds r4, #1
	cmp r4, #4
	ble _080A5BC6
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5C08: .4byte gProjectileFnTable
_080A5C0C: .4byte gProjectileHeaderPtr

	thumb_func_start nop_080a5c10
nop_080a5c10: @ 0x080A5C10
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a5c14
FUN_080a5c14: @ 0x080A5C14
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080A5C74 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080A5C78 @ =0x0836BB48
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
	ldr r1, _080A5C7C @ =0x0836BB18
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080A5C80 @ =nop_080a5c10
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080a5c84
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5C74: .4byte gProjectileFnTable
_080A5C78: .4byte 0x0836BB48
_080A5C7C: .4byte 0x0836BB18
_080A5C80: .4byte nop_080a5c10

	thumb_func_start FUN_080a5c84
FUN_080a5c84: @ 0x080A5C84
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A5CB0 @ =0x0836BB00
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080A5CB4 @ =0x0836BB0C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5CB0: .4byte 0x0836BB00
_080A5CB4: .4byte 0x0836BB0C

	thumb_func_start FUN_080a5cb8
FUN_080a5cb8: @ 0x080A5CB8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080A5CF4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5CF4: .4byte gProjectileFnTable
_080A5CF8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a5cfc
FUN_080a5cfc: @ 0x080A5CFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A5D0C
	cmp r0, #1
	beq _080A5DC8
	b _080A5DFA
_080A5D0C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A5D94 @ =0x0836BB18
	bl SetDDP
	ldr r1, _080A5D98 @ =0x0836BB4A
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x57
	bl LoadBlink
	ldr r2, _080A5D9C @ =gSineTable
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #5
	movs r3, #0x40
	rsbs r3, r3, #0
	adds r0, r3, #0
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #5
	movs r3, #0x80
	rsbs r3, r3, #0
	adds r0, r3, #0
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r1, #0
	ldrb r0, [r4, #0x12]
	cmp r0, #2
	bls _080A5D84
	movs r1, #1
_080A5D84:
	adds r2, r1, #0
	cmp r2, #0
	beq _080A5DA0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A5DA6
	.align 2, 0
_080A5D94: .4byte 0x0836BB18
_080A5D98: .4byte 0x0836BB4A
_080A5D9C: .4byte gSineTable
_080A5DA0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A5DA6:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A5DC8:
	movs r0, #0x57
	bl UpdateBlinkMotionState
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A5DFA
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A5DFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5e00
FUN_080a5e00: @ 0x080A5E00
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A5E10
	cmp r0, #1
	beq _080A5E34
	b _080A5E54
_080A5E10:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A5E5C @ =0x0836BB30
	bl SetDDP
	ldr r1, _080A5E60 @ =0x0836BB54
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x30
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A5E34:
	movs r0, #0x57
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080A5E54
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A5E54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5E5C: .4byte 0x0836BB30
_080A5E60: .4byte 0x0836BB54

	thumb_func_start FUN_080a5e64
FUN_080a5e64: @ 0x080A5E64
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _080A5E74
	cmp r1, #1
	beq _080A5E94
	b _080A5EF6
_080A5E74:
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A5E94:
	ldrb r1, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080A5EA8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080A5EAE
_080A5EA8:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080A5EAE:
	strb r0, [r4, #0xa]
	subs r0, r2, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080A5EF6
	movs r0, #0x57
	bl ClearBlink
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A5EFC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A5EF6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5EFC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a5f00
FUN_080a5f00: @ 0x080A5F00
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080A5F4C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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

	thumb_func_start initCubitAtkObject
initCubitAtkObject: @ 0x080A61FC
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
_080A625C: .4byte 0x0836BCAC
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
_080A62B8: .4byte 0x0836BBA4
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
_080A62F8: .4byte 0x0836BCF4
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
	bl FUN_080a6350
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6348: .4byte 0x0836BCC4
_080A634C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a6350
FUN_080a6350: @ 0x080A6350
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
_080A636C: .4byte 0x0836BB94

	thumb_func_start FUN_080a6370
FUN_080a6370: @ 0x080A6370
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
_080A645C: .4byte 0x0836BC1C
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
	bl UpdateMotionGraphic
	adds r0, r6, #0
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
_080A6564: .4byte 0x0836BC1C
_080A6568: .4byte 0x0836BD24
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
	bl UpdateMotionGraphic
	adds r0, r6, #0
	bl UpdateMotionGraphic
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
_080A664C: .4byte 0x0836BC1C
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
	bl UpdateMotionGraphic
	adds r0, r6, #0
	bl UpdateMotionGraphic
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
_080A66C8: .4byte 0x0836BC1C
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
	bl UpdateMotionGraphic
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

	thumb_func_start FUN_080a6718
FUN_080a6718: @ 0x080A6718
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080A672C
	ldrb r0, [r1, #0xd]
	cmp r0, #0xb
	bne _080A6736
_080A672C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0x13
	bhi _080A6736
	movs r0, #0x14
	strb r0, [r4, #0xe]
_080A6736:
	ldrb r0, [r4, #0xe]
	cmp r0, #0x15
	bls _080A673E
	b _080A6D2A
_080A673E:
	lsls r0, r0, #2
	ldr r1, _080A6748 @ =_080A674C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A6748: .4byte _080A674C
_080A674C: @ jump table
	.4byte _080A67A4 @ case 0
	.4byte _080A68A2 @ case 1
	.4byte _080A6900 @ case 2
	.4byte _080A691C @ case 3
	.4byte _080A6944 @ case 4
	.4byte _080A697E @ case 5
	.4byte _080A6A94 @ case 6
	.4byte _080A6D2A @ case 7
	.4byte _080A6D2A @ case 8
	.4byte _080A6D2A @ case 9
	.4byte _080A6B54 @ case 10
	.4byte _080A6C3E @ case 11
	.4byte _080A6C9C @ case 12
	.4byte _080A6CB4 @ case 13
	.4byte _080A6CD0 @ case 14
	.4byte _080A6CE2 @ case 15
	.4byte _080A6D2A @ case 16
	.4byte _080A6D2A @ case 17
	.4byte _080A6D2A @ case 18
	.4byte _080A6D2A @ case 19
	.4byte _080A6CFA @ case 20
	.4byte _080A6D08 @ case 21
_080A67A4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A686C @ =0x0836BCAC
	bl SetDDP
	adds r6, r4, #0
	adds r6, #0xb8
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r6]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a31c
	str r0, [sp]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _080A6870 @ =0xFFFF8400
	adds r1, r0, r1
	str r1, [sp, #4]
	ldr r1, _080A6874 @ =0x0836BD4C
	adds r3, r4, #0
	adds r3, #0xb4
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r0, [sp]
	adds r2, r2, r0
	ldr r0, [r4, #0x54]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [sp, #4]
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080A6830
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080A6830:
	ldr r1, [r4, #0x5c]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x60]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	ldr r1, [r4, #0x64]
	cmp r1, #0
	bge _080A6852
	rsbs r1, r1, #0
_080A6852:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _080A688C
	ldr r0, [r4, #0x64]
	cmp r0, #0
	ble _080A687C
	ldr r1, _080A6878 @ =0x0000B108
	adds r0, r4, #0
	bl SetMotion
	movs r0, #2
	b _080A6896
	.align 2, 0
_080A686C: .4byte 0x0836BCAC
_080A6870: .4byte 0xFFFF8400
_080A6874: .4byte 0x0836BD4C
_080A6878: .4byte 0x0000B108
_080A687C:
	ldr r1, _080A6888 @ =0x0000B107
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	b _080A6896
	.align 2, 0
_080A6888: .4byte 0x0000B107
_080A688C:
	ldr r1, _080A68FC @ =0x0000B106
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
_080A6896:
	strb r0, [r4, #0x13]
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A68A2:
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	strb r1, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A68CE
	adds r0, r4, #0
	adds r0, #0x54
	adds r1, r4, #0
	adds r1, #0x64
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r3, #1
	ands r2, r3
	ldrb r3, [r4, #0x13]
	bl FUN_080c07e4
_080A68CE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r2, r4, #0
	adds r2, #0xbc
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	cmp r0, #0
	ble _080A68FA
	b _080A6D2A
_080A68FA:
	b _080A6CC4
	.align 2, 0
_080A68FC: .4byte 0x0000B106
_080A6900:
	ldr r1, [r4, #0x28]
	adds r1, #0xb4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x1e
	strb r0, [r4, #0x13]
	ldr r1, _080A6940 @ =0x0000B106
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A691C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #5
	beq _080A692E
	b _080A6D2A
_080A692E:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A6936
	b _080A6CC4
_080A6936:
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	b _080A6CC0
	.align 2, 0
_080A6940: .4byte 0x0000B106
_080A6944:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r2, #0
	str r2, [r0]
	subs r0, #8
	ldrb r0, [r0]
	cmp r0, #2
	bne _080A6974
	ldr r0, _080A696C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080A6970
	strb r2, [r4, #0x13]
	b _080A6974
	.align 2, 0
_080A696C: .4byte pZero2
_080A6970:
	movs r0, #1
	strb r0, [r4, #0x13]
_080A6974:
	movs r0, #0
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A697E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _080A699A
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #3
	b _080A69C8
_080A699A:
	cmp r1, #1
	beq _080A69C0
	cmp r1, #3
	bne _080A69AC
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #3
	b _080A69C8
_080A69AC:
	cmp r1, #4
	beq _080A69C0
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A69C0
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #3
	b _080A69C8
_080A69C0:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	subs r0, #3
_080A69C8:
	str r0, [r1]
	adds r5, r1, #0
	ldr r3, _080A6A30 @ =gSineTable
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #1
	lsls r0, r0, #4
	ldr r2, [r4, #0x64]
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r5]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	ldr r1, [r4, #0x68]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldr r3, [r4, #0x54]
	subs r2, r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r4, #0x54]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x58]
	ldrb r0, [r6]
	cmp r0, #0
	bne _080A6A34
	ldr r1, [r5]
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	bgt _080A6A2E
	b _080A6D2A
_080A6A2E:
	b _080A6CC4
	.align 2, 0
_080A6A30: .4byte gSineTable
_080A6A34:
	cmp r0, #1
	bne _080A6A48
	ldr r1, [r5]
	ldr r0, _080A6A44 @ =0xFFFFFEC1
	cmp r1, r0
	ble _080A6A42
	b _080A6D2A
_080A6A42:
	b _080A6CC4
	.align 2, 0
_080A6A44: .4byte 0xFFFFFEC1
_080A6A48:
	cmp r0, #3
	bne _080A6A5A
	ldr r1, [r5]
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	bgt _080A6A58
	b _080A6D2A
_080A6A58:
	b _080A6CC4
_080A6A5A:
	cmp r0, #4
	bne _080A6A70
	ldr r1, [r5]
	ldr r0, _080A6A6C @ =0xFFFFFEC1
	cmp r1, r0
	ble _080A6A68
	b _080A6D2A
_080A6A68:
	b _080A6CC4
	.align 2, 0
_080A6A6C: .4byte 0xFFFFFEC1
_080A6A70:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A6A84
	ldr r1, [r5]
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	bgt _080A6A82
	b _080A6D2A
_080A6A82:
	b _080A6CC4
_080A6A84:
	ldr r1, [r5]
	ldr r0, _080A6A90 @ =0xFFFFFEC1
	cmp r1, r0
	ble _080A6A8E
	b _080A6D2A
_080A6A8E:
	b _080A6CC4
	.align 2, 0
_080A6A90: .4byte 0xFFFFFEC1
_080A6A94:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _080A6AB0
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	b _080A6ADE
_080A6AB0:
	cmp r1, #1
	beq _080A6AD6
	cmp r1, #3
	bne _080A6AC2
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	b _080A6ADE
_080A6AC2:
	cmp r1, #4
	beq _080A6AD6
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A6AD6
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	b _080A6ADE
_080A6AD6:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	subs r0, #1
_080A6ADE:
	str r0, [r1]
	adds r5, r1, #0
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r6]
	cmp r0, #0
	bne _080A6B12
	ldr r1, [r5]
	movs r0, #0xbf
	lsls r0, r0, #1
	cmp r1, r0
	bgt _080A6B10
	b _080A6D2A
_080A6B10:
	b _080A6B4A
_080A6B12:
	cmp r0, #1
	beq _080A6B40
	cmp r0, #3
	bne _080A6B28
	ldr r1, [r5]
	movs r0, #0xbf
	lsls r0, r0, #1
	cmp r1, r0
	bgt _080A6B26
	b _080A6D2A
_080A6B26:
	b _080A6B4A
_080A6B28:
	cmp r0, #4
	beq _080A6B40
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A6B40
	ldr r1, [r5]
	movs r0, #0xbf
	lsls r0, r0, #1
	cmp r1, r0
	bgt _080A6B3E
	b _080A6D2A
_080A6B3E:
	b _080A6B4A
_080A6B40:
	ldr r1, [r5]
	ldr r0, _080A6B50 @ =0xFFFFFE81
	cmp r1, r0
	ble _080A6B4A
	b _080A6D2A
_080A6B4A:
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _080A6D2A
	.align 2, 0
_080A6B50: .4byte 0xFFFFFE81
_080A6B54:
	adds r7, r4, #0
	adds r7, #0xb8
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r7]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a31c
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r2, _080A6C0C @ =0xFFFF8400
	adds r6, r0, r2
	ldr r1, _080A6C10 @ =0x0836BD4C
	adds r3, r4, #0
	adds r3, #0xb5
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, [r0]
	adds r2, r2, r5
	ldr r0, [r4, #0x54]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, r1, r6
	ldr r0, [r4, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080A6BD0
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080A6BD0:
	ldr r1, [r4, #0x5c]
	ldr r0, [r7]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x60]
	ldr r0, [r7]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	ldr r1, [r4, #0x64]
	cmp r1, #0
	bge _080A6BF2
	rsbs r1, r1, #0
_080A6BF2:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _080A6C28
	ldr r0, [r4, #0x64]
	cmp r0, #0
	ble _080A6C18
	ldr r1, _080A6C14 @ =0x0000B108
	adds r0, r4, #0
	bl SetMotion
	movs r0, #2
	b _080A6C32
	.align 2, 0
_080A6C0C: .4byte 0xFFFF8400
_080A6C10: .4byte 0x0836BD4C
_080A6C14: .4byte 0x0000B108
_080A6C18:
	ldr r1, _080A6C24 @ =0x0000B107
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	b _080A6C32
	.align 2, 0
_080A6C24: .4byte 0x0000B107
_080A6C28:
	ldr r1, _080A6C98 @ =0x0000B106
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
_080A6C32:
	strb r0, [r4, #0x13]
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A6C3E:
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	strb r1, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6C6A
	adds r0, r4, #0
	adds r0, #0x54
	adds r1, r4, #0
	adds r1, #0x64
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r3, #1
	ands r2, r3
	ldrb r3, [r4, #0x13]
	bl FUN_080c07e4
_080A6C6A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r2, r4, #0
	adds r2, #0xbc
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	cmp r0, #0
	bgt _080A6D2A
	b _080A6CC4
	.align 2, 0
_080A6C98: .4byte 0x0000B106
_080A6C9C:
	ldr r1, [r4, #0x28]
	adds r1, #0xb4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _080A6CCC @ =0x0000B106
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A6CB4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	adds r0, #0xb4
	ldrb r0, [r0]
_080A6CC0:
	cmp r0, #0
	bne _080A6D2A
_080A6CC4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A6D2A
	.align 2, 0
_080A6CCC: .4byte 0x0000B106
_080A6CD0:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A6CE2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A6D18
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6D2A
	b _080A6D18
_080A6CFA:
	ldr r1, _080A6D34 @ =0x0000B102
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A6D08:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A6D2A
_080A6D18:
	ldr r1, _080A6D38 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A6D2A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6D34: .4byte 0x0000B102
_080A6D38: .4byte gProjectileFnTable

	thumb_func_start FUN_080a6d3c
FUN_080a6d3c: @ 0x080A6D3C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, [r5, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080A6D4C
	b _080A6EB4
_080A6D4C:
	adds r0, r1, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A6D58
	b _080A6EB4
_080A6D58:
	ldrb r0, [r1, #0xd]
	cmp r0, #0xb
	bne _080A6D60
	b _080A6EB4
_080A6D60:
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _080A6D68
	b _080A6EC6
_080A6D68:
	lsls r0, r0, #2
	ldr r1, _080A6D74 @ =_080A6D78
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A6D74: .4byte _080A6D78
_080A6D78: @ jump table
	.4byte _080A6D98 @ case 0
	.4byte _080A6DB6 @ case 1
	.4byte _080A6E3C @ case 2
	.4byte _080A6E46 @ case 3
	.4byte _080A6E50 @ case 4
	.4byte _080A6E64 @ case 5
	.4byte _080A6E9A @ case 6
	.4byte _080A6EA4 @ case 7
_080A6D98:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #9
	strb r0, [r5, #0x12]
	movs r0, #1
	strb r0, [r5, #0x13]
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6DB6:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080A6DC8
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A6DC8
	b _080A6EC6
_080A6DC8:
	ldrb r1, [r5, #0x12]
	movs r0, #9
	subs r6, r0, r1
	ldr r1, [r5, #0x28]
	ldr r4, [r1, #0x54]
	str r4, [sp]
	ldr r3, [r1, #0x58]
	str r3, [sp, #4]
	ldrb r2, [r1, #0xa]
	movs r0, #0x10
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	bne _080A6DFC
	ldr r1, _080A6DF8 @ =0x0836BD74
	lsls r2, r6, #3
	adds r0, r2, r1
	ldr r0, [r0]
	adds r0, r0, r4
	str r0, [sp]
	adds r1, #4
	adds r2, r2, r1
	ldr r0, [r2]
	b _080A6E12
	.align 2, 0
_080A6DF8: .4byte 0x0836BD74
_080A6DFC:
	ldr r2, _080A6E38 @ =0x0836BD74
	movs r1, #8
	subs r1, r1, r6
	lsls r1, r1, #3
	adds r0, r1, r2
	ldr r0, [r0]
	adds r0, r0, r4
	str r0, [sp]
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r1]
_080A6E12:
	adds r0, r0, r3
	str r0, [sp, #4]
	ldrb r2, [r7, #0xa]
	lsrs r2, r2, #4
	movs r4, #1
	ands r2, r4
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	adds r0, r5, #0
	mov r1, sp
	bl FUN_080a6014
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A6E92
	subs r0, #1
	b _080A6E8A
	.align 2, 0
_080A6E38: .4byte 0x0836BD74
_080A6E3C:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6E46:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A6E92
	subs r0, #1
	b _080A6E8A
_080A6E50:
	movs r1, #0
	movs r0, #0x20
	strb r0, [r5, #0x12]
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0xb5
	strb r1, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6E64:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080A6E74
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6EC6
_080A6E74:
	adds r1, r5, #0
	adds r1, #0xb5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r5, #0x12]
	strb r1, [r5, #0x13]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _080A6E92
	subs r0, r1, #1
_080A6E8A:
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6EC6
_080A6E92:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A6EC6
_080A6E9A:
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6EA4:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A6EB4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6EC6
_080A6EB4:
	ldr r1, _080A6ED0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080A6EC6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6ED0: .4byte gProjectileFnTable

	thumb_func_start cubit_080a6ed4
cubit_080a6ed4: @ 0x080A6ED4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A6EEA
	ldrb r0, [r5, #0xe]
	cmp r0, #0x13
	bhi _080A6EEA
	movs r0, #0x14
	strb r0, [r5, #0xe]
_080A6EEA:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6EF8
	b _080A723A
_080A6EF8:
	ldrb r0, [r5, #0xe]
	cmp r0, #0x15
	bls _080A6F00
	b _080A724C
_080A6F00:
	lsls r0, r0, #2
	ldr r1, _080A6F0C @ =_080A6F10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A6F0C: .4byte _080A6F10
_080A6F10: @ jump table
	.4byte _080A6F68 @ case 0
	.4byte _080A7204 @ case 1
	.4byte _080A6FB8 @ case 2
	.4byte _080A6FC6 @ case 3
	.4byte _080A6FE8 @ case 4
	.4byte _080A7204 @ case 5
	.4byte _080A6FFC @ case 6
	.4byte _080A71F4 @ case 7
	.4byte _080A711A @ case 8
	.4byte _080A7128 @ case 9
	.4byte _080A7158 @ case 10
	.4byte _080A71F4 @ case 11
	.4byte _080A724C @ case 12
	.4byte _080A724C @ case 13
	.4byte _080A724C @ case 14
	.4byte _080A724C @ case 15
	.4byte _080A724C @ case 16
	.4byte _080A724C @ case 17
	.4byte _080A724C @ case 18
	.4byte _080A724C @ case 19
	.4byte _080A721C @ case 20
	.4byte _080A722A @ case 21
_080A6F68:
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0xb6
	ldrb r2, [r0]
	cmp r2, #0
	beq _080A6F8C
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A6F92
_080A6F8C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A6F92:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A7204
_080A6FB8:
	ldr r1, _080A6FE4 @ =0x0000B101
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6FC6:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r1, r5, #0
	adds r1, #0xb5
	ldr r0, [r5, #0x28]
	adds r0, #0xb5
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080A6FE2
	b _080A724C
_080A6FE2:
	b _080A7214
	.align 2, 0
_080A6FE4: .4byte 0x0000B101
_080A6FE8:
	ldr r1, _080A6FF8 @ =0x0000B102
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A7204
	.align 2, 0
_080A6FF8: .4byte 0x0000B102
_080A6FFC:
	ldr r1, _080A70B0 @ =0x0000B10C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x25
	movs r4, #8
	strb r4, [r0]
	adds r0, #0x4f
	ldr r1, _080A70B4 @ =0x0836BBBC
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x28]
	ldr r6, [r0, #0x54]
	ldr r7, [r0, #0x58]
	ldr r2, _080A70B8 @ =0x0836BDBC
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	ands r0, r4
	adds r1, r0, r2
	ldr r1, [r1]
	adds r1, r1, r6
	str r1, [r5, #0x54]
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	adds r0, r0, r7
	str r0, [r5, #0x58]
	adds r4, r5, #0
	adds r4, #0xb8
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r4]
	ldr r0, _080A70BC @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r5, #0x54]
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r5, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0xe
	cmp r6, #0
	beq _080A7098
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	str r0, [r5, #0x60]
_080A7098:
	ldr r2, [r5, #0x60]
	adds r0, r2, #0
	cmp r2, #0
	bge _080A70A2
	rsbs r0, r2, #0
_080A70A2:
	cmp r0, #0x80
	ble _080A70DC
	cmp r2, #0
	ble _080A70C0
	movs r0, #0x80
	b _080A70C4
	.align 2, 0
_080A70B0: .4byte 0x0000B10C
_080A70B4: .4byte 0x0836BBBC
_080A70B8: .4byte 0x0836BDBC
_080A70BC: .4byte pZero2
_080A70C0:
	movs r0, #0x80
	rsbs r0, r0, #0
_080A70C4:
	str r0, [r5, #0x60]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A70D6
	movs r0, #0xdd
	rsbs r0, r0, #0
	b _080A70D8
_080A70D6:
	movs r0, #0xdd
_080A70D8:
	str r0, [r5, #0x5c]
	ldr r2, [r5, #0x60]
_080A70DC:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A70F2
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080A70FC
	b _080A70F8
_080A70F2:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _080A70FC
_080A70F8:
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_080A70FC:
	ldr r1, [r5, #0x5c]
	ldr r0, [r4]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r0, [r4]
	muls r0, r2, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #0xce
	bl PlaySound
	movs r0, #0x78
	strb r0, [r5, #0x12]
	b _080A71EE
_080A711A:
	ldr r1, _080A7154 @ =0x0000B10D
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A7128:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A7150
	b _080A724C
_080A7150:
	b _080A7214
	.align 2, 0
_080A7154: .4byte 0x0000B10D
_080A7158:
	ldr r1, _080A7174 @ =0x0000B10F
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A7178 @ =0x0836BBEC
	bl SetDDP
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080A717C
	movs r0, #0xb5
	b _080A7180
	.align 2, 0
_080A7174: .4byte 0x0000B10F
_080A7178: .4byte 0x0836BBEC
_080A717C:
	movs r0, #0xb5
	rsbs r0, r0, #0
_080A7180:
	str r0, [r5, #0x5c]
	ldr r2, _080A71C4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080A71C8 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _080A71CC @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080A71D0
	movs r0, #0xb5
	str r0, [r5, #0x60]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _080A71D6
	.align 2, 0
_080A71C4: .4byte RNG_0202f388
_080A71C8: .4byte 0x000343FD
_080A71CC: .4byte 0x00269EC3
_080A71D0:
	movs r0, #0xb5
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
_080A71D6:
	adds r2, r5, #0
	adds r2, #0xb8
	ldr r1, [r5, #0x5c]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
_080A71EE:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A71F4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_080A7204:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A724C
_080A7214:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A724C
_080A721C:
	ldr r1, _080A7254 @ =0x0000B102
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A722A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A724C
_080A723A:
	ldr r1, _080A7258 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080A724C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7254: .4byte 0x0000B102
_080A7258: .4byte gProjectileFnTable

	thumb_func_start cubit_080a725c
cubit_080a725c: @ 0x080A725C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080A726C
	b _080A745A
_080A726C:
	adds r0, r1, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A7278
	b _080A745A
_080A7278:
	ldrb r0, [r1, #0xd]
	cmp r0, #0xb
	bne _080A7280
	b _080A745A
_080A7280:
	ldrb r0, [r6, #0xe]
	cmp r0, #7
	bls _080A7288
	b _080A746C
_080A7288:
	lsls r0, r0, #2
	ldr r1, _080A7294 @ =_080A7298
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A7294: .4byte _080A7298
_080A7298: @ jump table
	.4byte _080A72B8 @ case 0
	.4byte _080A72F2 @ case 1
	.4byte _080A73F0 @ case 2
	.4byte _080A7410 @ case 3
	.4byte _080A73F6 @ case 4
	.4byte _080A7410 @ case 5
	.4byte _080A7428 @ case 6
	.4byte _080A7436 @ case 7
_080A72B8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r0, #9
	strb r0, [r6, #0x12]
	movs r0, #4
	strb r0, [r6, #0x13]
	ldr r0, [r6, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A72DC
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #0xe8
	b _080A72E2
_080A72DC:
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #0x18
_080A72E2:
	str r0, [r1]
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A72F2:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A7304
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A7304
	b _080A746C
_080A7304:
	ldrb r1, [r6, #0x12]
	movs r0, #9
	subs r0, r0, r1
	mov ip, r0
	ldr r0, [r6, #0x28]
	ldr r3, [r0, #0x54]
	str r3, [sp]
	ldr r4, [r0, #0x58]
	str r4, [sp, #4]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A733C
	ldr r1, _080A7338 @ =0x0836BDCC
	mov r0, ip
	lsls r2, r0, #3
	adds r0, r2, r1
	ldr r0, [r0]
	adds r0, r0, r3
	str r0, [sp]
	adds r1, #4
	adds r2, r2, r1
	ldr r0, [r2]
	b _080A7354
	.align 2, 0
_080A7338: .4byte 0x0836BDCC
_080A733C:
	ldr r2, _080A73D8 @ =0x0836BDCC
	movs r1, #8
	mov r0, ip
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r0, r1, r2
	ldr r0, [r0]
	adds r0, r0, r3
	str r0, [sp]
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r1]
_080A7354:
	adds r0, r0, r4
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r3, #0x90
	lsls r3, r3, #6
	str r3, [r0]
	ldr r4, [r6, #0x28]
	ldr r5, _080A73DC @ =gSineTable
	adds r7, r6, #0
	adds r7, #0xbc
	ldr r2, [r7]
	ldrb r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	asrs r1, r1, #8
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	adds r2, #0x40
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	adds r2, r2, r5
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	asrs r1, r1, #8
	ldr r0, _080A73E0 @ =0xFFFFE800
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	mov r1, ip
	lsls r3, r1, #0x18
	lsrs r3, r3, #0x18
	adds r0, r6, #0
	mov r1, sp
	bl FUN_080a60c8
	cmp r0, #0
	beq _080A73C0
	adds r1, r0, #0
	adds r1, #0xbc
	ldr r0, [r7]
	str r0, [r1]
_080A73C0:
	movs r0, #4
	strb r0, [r6, #0x13]
	ldr r0, [r6, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A73E4
	ldr r0, [r7]
	subs r0, #0x1a
	b _080A73E8
	.align 2, 0
_080A73D8: .4byte 0x0836BDCC
_080A73DC: .4byte gSineTable
_080A73E0: .4byte 0xFFFFE800
_080A73E4:
	ldr r0, [r7]
	adds r0, #0x1a
_080A73E8:
	movs r1, #0xff
	ands r0, r1
	str r0, [r7]
	b _080A7410
_080A73F0:
	movs r0, #0xc
	strb r0, [r6, #0x12]
	b _080A740A
_080A73F6:
	movs r0, #0xcf
	bl PlaySound
	movs r0, #0x20
	strb r0, [r6, #0x12]
	strb r0, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #9
	strb r0, [r1]
_080A740A:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A7410:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080A7420
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A746C
_080A7420:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A746C
_080A7428:
	movs r0, #0x81
	strb r0, [r6, #0x12]
	movs r0, #3
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A7436:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080A7446
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A746C
_080A7446:
	movs r0, #0xc4
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A745A
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A746C
_080A745A:
	ldr r1, _080A7474 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A746C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7474: .4byte gProjectileFnTable

	thumb_func_start FUN_080a7478
FUN_080a7478: @ 0x080A7478
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080A748A
	ldrb r0, [r1, #0xd]
	cmp r0, #0xb
	bne _080A7494
_080A748A:
	ldrb r0, [r6, #0xe]
	cmp r0, #0x13
	bhi _080A7494
	movs r0, #0x14
	strb r0, [r6, #0xe]
_080A7494:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A74A2
	b _080A7A4E
_080A74A2:
	ldrb r0, [r6, #0xe]
	cmp r0, #0x15
	bls _080A74AA
	b _080A7A60
_080A74AA:
	lsls r0, r0, #2
	ldr r1, _080A74B4 @ =_080A74B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A74B4: .4byte _080A74B8
_080A74B8: @ jump table
	.4byte _080A7510 @ case 0
	.4byte _080A755E @ case 1
	.4byte _080A7572 @ case 2
	.4byte _080A7584 @ case 3
	.4byte _080A75B4 @ case 4
	.4byte _080A75C2 @ case 5
	.4byte _080A75DC @ case 6
	.4byte _080A76A8 @ case 7
	.4byte _080A7784 @ case 8
	.4byte _080A7858 @ case 9
	.4byte _080A791C @ case 10
	.4byte _080A7942 @ case 11
	.4byte _080A7A60 @ case 12
	.4byte _080A7A60 @ case 13
	.4byte _080A7A60 @ case 14
	.4byte _080A7A60 @ case 15
	.4byte _080A7A60 @ case 16
	.4byte _080A7A60 @ case 17
	.4byte _080A7A60 @ case 18
	.4byte _080A7A60 @ case 19
	.4byte _080A7A04 @ case 20
	.4byte _080A7A2E @ case 21
_080A7510:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0xb6
	ldrb r2, [r0]
	cmp r2, #0
	beq _080A7534
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A753A
_080A7534:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A753A:
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
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A755E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080A7570
	b _080A7A60
_080A7570:
	b _080A790C
_080A7572:
	ldr r1, _080A75AC @ =0x0000B101
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A7584:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldrb r2, [r6, #0x13]
	ldr r1, _080A75B0 @ =0x0836BE14
	adds r0, r6, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r2, r0
	bge _080A75AA
	b _080A7A60
_080A75AA:
	b _080A790C
	.align 2, 0
_080A75AC: .4byte 0x0000B101
_080A75B0: .4byte 0x0836BE14
_080A75B4:
	ldr r1, _080A75D8 @ =0x0000B114
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A75C2:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080A75D4
	b _080A7A60
_080A75D4:
	b _080A790C
	.align 2, 0
_080A75D8: .4byte 0x0000B114
_080A75DC:
	ldr r1, _080A764C @ =0x0000B115
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080A7650 @ =0x0836BD0C
	bl SetDDP
	adds r4, r6, #0
	adds r4, #0xbc
	ldr r0, [r4]
	strb r0, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r4]
	lsls r0, r0, #8
	str r0, [r1]
	subs r1, #8
	movs r0, #0x90
	lsls r0, r0, #6
	str r0, [r1]
	ldr r0, [r6, #0x28]
	ldr r1, [r0, #0x28]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl FUN_0800a31c
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x28]
	ldr r1, [r0, #0x28]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl FUN_08009f6c
	ldr r1, _080A7654 @ =0xFFFFA200
	adds r0, r0, r1
	ldr r1, [r6, #0x28]
	ldr r1, [r1, #0x28]
	ldr r1, [r1, #0x58]
	cmp r0, r1
	ble _080A7658
	adds r1, r6, #0
	adds r1, #0xb7
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x64]
	movs r2, #0xf8
	lsls r2, r2, #7
	adds r0, r0, r2
	b _080A7668
	.align 2, 0
_080A764C: .4byte 0x0000B115
_080A7650: .4byte 0x0836BD0C
_080A7654: .4byte 0xFFFFA200
_080A7658:
	adds r1, r6, #0
	adds r1, #0xb7
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r6, #0x64]
	movs r1, #0xd0
	lsls r1, r1, #7
	adds r0, r0, r1
_080A7668:
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x28]
	ldr r1, [r0, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _080A76CC @ =0xFFFFE800
	adds r0, r0, r2
	str r0, [r6, #0x68]
	ldr r0, [r1, #0x54]
	str r0, [r6, #0x5c]
	ldr r0, [r1, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #9
	str r0, [r4]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A769C
	cmp r0, #3
	beq _080A769C
	cmp r0, #6
	bne _080A76A2
_080A769C:
	movs r0, #0xcb
	bl PlaySound
_080A76A2:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A76A8:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A76D4
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r1, [r0]
	ldr r2, _080A76D0 @ =0xFFFFFE40
	adds r1, r1, r2
	str r1, [r0]
	asrs r1, r1, #8
	movs r2, #0xff
	ands r1, r2
	adds r7, r0, #0
	cmp r1, #0xe8
	ble _080A76F4
	b _080A76EE
	.align 2, 0
_080A76CC: .4byte 0xFFFFE800
_080A76D0: .4byte 0xFFFFFE40
_080A76D4:
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [r0]
	asrs r1, r1, #8
	movs r2, #0xff
	ands r1, r2
	adds r7, r0, #0
	cmp r1, #0x17
	bgt _080A76F4
_080A76EE:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A76F4:
	adds r0, r6, #0
	adds r0, #0xb7
	ldrb r0, [r0]
	cmp r0, #1
	bne _080A770A
	adds r2, r6, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #7
	b _080A7714
_080A770A:
	adds r2, r6, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0xd0
	lsls r0, r0, #7
_080A7714:
	subs r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r2]
	adds r5, r2, #0
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x68]
	ldr r3, [r6, #0x60]
	subs r0, r0, r3
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x60]
	ldr r4, _080A7780 @ =gSineTable
	ldr r0, [r7]
	asrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov ip, r0
	ldr r0, [r5]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldr r0, [r7]
	asrs r0, r0, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _080A784A
	.align 2, 0
_080A7780: .4byte gSineTable
_080A7784:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A779C
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ldr r2, _080A7798 @ =0xFFFFFE40
	b _080A77A6
	.align 2, 0
_080A7798: .4byte 0xFFFFFE40
_080A779C:
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
_080A77A6:
	adds r0, r0, r2
	str r0, [r1]
	adds r7, r1, #0
	adds r0, r6, #0
	adds r0, #0xb7
	ldrb r0, [r0]
	cmp r0, #1
	bne _080A77C2
	adds r2, r6, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #7
	b _080A77CC
_080A77C2:
	adds r2, r6, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0xd0
	lsls r0, r0, #7
_080A77CC:
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r2]
	adds r5, r2, #0
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x68]
	ldr r3, [r6, #0x60]
	subs r0, r0, r3
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x60]
	ldr r4, _080A7850 @ =gSineTable
	ldr r0, [r7]
	asrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov ip, r0
	ldr r0, [r5]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldr r0, [r7]
	asrs r0, r0, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, [r1]
	ldr r2, _080A7854 @ =0xFFFFFE40
	adds r0, r0, r2
	str r0, [r1]
	cmp r0, #0
	bgt _080A784A
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A784A:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	b _080A7A60
	.align 2, 0
_080A7850: .4byte gSineTable
_080A7854: .4byte 0xFFFFFE40
_080A7858:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A7870
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ldr r2, _080A786C @ =0xFFFFFD00
	b _080A787A
	.align 2, 0
_080A786C: .4byte 0xFFFFFD00
_080A7870:
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #2
_080A787A:
	adds r0, r0, r2
	str r0, [r1]
	adds r7, r1, #0
	adds r5, r6, #0
	adds r5, #0xb8
	ldr r2, [r5]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5]
	ldr r0, [r6, #0x28]
	ldr r4, [r0, #0x28]
	ldr r1, [r4, #0x54]
	ldr r2, [r6, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x5c]
	ldr r3, [r6, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r3, r1
	ldr r1, [r4, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x60]
	ldr r4, _080A7914 @ =gSineTable
	ldr r0, [r7]
	asrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov ip, r0
	ldr r0, [r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x54]
	ldr r0, [r7]
	asrs r0, r0, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r5]
	ldr r0, _080A7918 @ =0x000007FF
	cmp r1, r0
	ble _080A790C
	b _080A7A60
_080A790C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A7A60
	.align 2, 0
_080A7914: .4byte gSineTable
_080A7918: .4byte 0x000007FF
_080A791C:
	ldr r1, _080A7958 @ =0x0000B116
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A7942:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A7960
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ldr r2, _080A795C @ =0xFFFFFD00
	b _080A796A
	.align 2, 0
_080A7958: .4byte 0x0000B116
_080A795C: .4byte 0xFFFFFD00
_080A7960:
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #2
_080A796A:
	adds r0, r0, r2
	str r0, [r1]
	adds r7, r1, #0
	adds r5, r6, #0
	adds r5, #0xb8
	ldr r2, [r5]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5]
	ldr r0, [r6, #0x28]
	ldr r4, [r0, #0x28]
	ldr r1, [r4, #0x54]
	ldr r2, [r6, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x5c]
	ldr r3, [r6, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r3, r1
	ldr r1, [r4, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x60]
	ldr r4, _080A7A00 @ =gSineTable
	ldr r0, [r7]
	asrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov ip, r0
	ldr r0, [r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x54]
	ldr r0, [r7]
	asrs r0, r0, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A7A60
	b _080A7A4E
	.align 2, 0
_080A7A00: .4byte gSineTable
_080A7A04:
	ldr r1, _080A7A68 @ =0x0000B102
	adds r0, r6, #0
	bl SetMotion
	movs r1, #0
	movs r0, #0xa
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A7A2E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A7A60
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080A7A4E
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A7A60
_080A7A4E:
	ldr r1, _080A7A6C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A7A60:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7A68: .4byte 0x0000B102
_080A7A6C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a7a70
FUN_080a7a70: @ 0x080A7A70
	movs r2, #0
	movs r1, #1
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a7a7c
FUN_080a7a7c: @ 0x080A7A7C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, [r7, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080A7A8A
	b _080A7C40
_080A7A8A:
	adds r0, r1, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A7A9E
	ldrb r0, [r7, #0xe]
	cmp r0, #3
	beq _080A7A9E
	movs r0, #3
	strb r0, [r7, #0xe]
_080A7A9E:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #0xb
	bne _080A7AB0
	ldrb r0, [r7, #0xe]
	cmp r0, #3
	beq _080A7AB0
	movs r0, #3
	strb r0, [r7, #0xe]
_080A7AB0:
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bls _080A7AB8
	b _080A7C52
_080A7AB8:
	lsls r0, r0, #2
	ldr r1, _080A7AC4 @ =_080A7AC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A7AC4: .4byte _080A7AC8
_080A7AC8: @ jump table
	.4byte _080A7ADC @ case 0
	.4byte _080A7B82 @ case 1
	.4byte _080A7C04 @ case 2
	.4byte _080A7C22 @ case 3
	.4byte _080A7C30 @ case 4
_080A7ADC:
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	bne _080A7B1A
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_0800a31c
	adds r4, r0, #0
	adds r0, r7, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A7AFC
	movs r0, #0xc0
	lsls r0, r0, #4
	b _080A7B3C
_080A7AFC:
	cmp r0, #1
	bne _080A7B06
	movs r0, #0x98
	lsls r0, r0, #7
	b _080A7B3C
_080A7B06:
	cmp r0, #2
	bne _080A7B10
	movs r0, #0x8c
	lsls r0, r0, #8
	b _080A7B3C
_080A7B10:
	cmp r0, #3
	bne _080A7B3E
	movs r0, #0xcc
	lsls r0, r0, #8
	b _080A7B3C
_080A7B1A:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_0800a31c
	adds r4, r0, #0
	adds r0, r7, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A7B34
	movs r0, #0xb0
	lsls r0, r0, #6
	b _080A7B3C
_080A7B34:
	cmp r0, #1
	bne _080A7B3E
	movs r0, #0xac
	lsls r0, r0, #8
_080A7B3C:
	adds r4, r4, r0
_080A7B3E:
	ldr r1, _080A7BF0 @ =0x0000B110
	adds r0, r7, #0
	bl SetMotion
	movs r6, #0
	movs r0, #0x32
	strb r0, [r7, #0x12]
	ldr r5, [r7, #0x54]
	subs r0, r4, r5
	movs r1, #0x32
	bl __divsi3
	str r0, [r7, #0x5c]
	ldr r4, _080A7BF4 @ =0x00013880
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl FUN_08009f6c
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	subs r4, r4, r0
	ldrb r1, [r7, #0x12]
	adds r0, r4, #0
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A7B82:
	ldr r2, [r7, #0x60]
	adds r2, #0x40
	str r2, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r2
	str r0, [r7, #0x58]
	cmp r2, #0
	ble _080A7BD2
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _080A7BAC
	adds r0, #1
	strb r0, [r7, #0x13]
	ldr r1, _080A7BF8 @ =0x0000B111
	adds r0, r7, #0
	bl SetMotion
_080A7BAC:
	ldrb r1, [r7, #0x13]
	cmp r1, #1
	bne _080A7BD2
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A7BD2
	adds r0, r1, #1
	strb r0, [r7, #0x13]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080A7BFC @ =0x0836BCDC
	bl SetDDP
	ldr r1, _080A7C00 @ =0x0000B112
	adds r0, r7, #0
	bl SetMotion
_080A7BD2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A7BE8
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A7C52
_080A7BE8:
	movs r0, #0x28
	strb r0, [r7, #0x12]
	b _080A7C1A
	.align 2, 0
_080A7BF0: .4byte 0x0000B110
_080A7BF4: .4byte 0x00013880
_080A7BF8: .4byte 0x0000B111
_080A7BFC: .4byte 0x0836BCDC
_080A7C00: .4byte 0x0000B112
_080A7C04:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A7C1A
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A7C52
_080A7C1A:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080A7C52
_080A7C22:
	ldr r1, _080A7C58 @ =0x0000B113
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A7C30:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A7C52
_080A7C40:
	ldr r1, _080A7C5C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080A7C52:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7C58: .4byte 0x0000B113
_080A7C5C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a7c60
FUN_080a7c60: @ 0x080A7C60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A7CA8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A7CA0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A7CAC @ =gProjectileFnTable
	movs r0, #0x17
	strb r0, [r3, #9]
	ldr r0, [r1, #0x5c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
_080A7CA0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A7CA8: .4byte gProjectileHeaderPtr
_080A7CAC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a7cb0
FUN_080a7cb0: @ 0x080A7CB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080A7CF8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A7CF2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A7CFC @ =gProjectileFnTable
	movs r0, #0x17
	strb r0, [r3, #9]
	ldr r0, [r1, #0x5c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
_080A7CF2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A7CF8: .4byte gProjectileHeaderPtr
_080A7CFC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a7d00
FUN_080a7d00: @ 0x080A7D00
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a7d04
FUN_080a7d04: @ 0x080A7D04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080A7D64 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080A7D68 @ =0x0836BEC4
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
	ldr r1, _080A7D6C @ =0x0836BE64
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080A7D70 @ =FUN_080a7d00
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080a7d74
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A7D64: .4byte gProjectileFnTable
_080A7D68: .4byte 0x0836BEC4
_080A7D6C: .4byte 0x0836BE64
_080A7D70: .4byte FUN_080a7d00

	thumb_func_start FUN_080a7d74
FUN_080a7d74: @ 0x080A7D74
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A7DA0 @ =0x0836BE4C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080A7DA4 @ =0x0836BE58
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7DA0: .4byte 0x0836BE4C
_080A7DA4: .4byte 0x0836BE58

	thumb_func_start FUN_080a7da8
FUN_080a7da8: @ 0x080A7DA8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080A7DE4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7DE4: .4byte gProjectileFnTable
_080A7DE8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a7dec
FUN_080a7dec: @ 0x080A7DEC
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A7E06
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080A7E06:
	pop {r0}
	bx r0
	.align 2, 0
_080A7E0C:
	.byte 0x30, 0xB5, 0x82, 0xB0
	.byte 0x04, 0x1C, 0x25, 0x1C, 0x8C, 0x35, 0x28, 0x68, 0x80, 0x21, 0x09, 0x01, 0x08, 0x40, 0x00, 0x28
	.byte 0x07, 0xD0, 0x1A, 0x48, 0x00, 0x68, 0x8C, 0x30, 0x00, 0x68, 0x01, 0x21, 0x08, 0x40, 0x00, 0x28
	.byte 0x28, 0xD0, 0x60, 0x6D, 0x00, 0x90, 0xA0, 0x6D, 0x15, 0x49, 0x40, 0x18, 0x01, 0x90, 0x15, 0x4A
	.byte 0x20, 0x1C, 0x69, 0x46, 0x04, 0x23, 0x10, 0xF0, 0xD9, 0xF8, 0x3F, 0x20, 0x5C, 0xF7, 0xA8, 0xFB
	.byte 0xA1, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x22, 0xFD, 0x21, 0x08, 0x40, 0xA0, 0x72, 0x2A, 0x60
	.byte 0x20, 0x1C, 0x90, 0x30, 0x02, 0x60, 0x04, 0x30, 0x02, 0x70, 0xA1, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0xA0, 0x72, 0x09, 0x49, 0x60, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x03, 0x21, 0xE1, 0x60, 0x00, 0x68
	.byte 0xC0, 0x68, 0x60, 0x61, 0x02, 0xB0, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x40, 0xF3, 0x02, 0x02
	.byte 0x00, 0xF0, 0xFF, 0xFF, 0xC6, 0xBE, 0x36, 0x08, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080a7e9c
FUN_080a7e9c: @ 0x080A7E9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A7EAC
	cmp r0, #1
	beq _080A7EDA
	b _080A7F62
_080A7EAC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7EF4 @ =0x0836BE64
	bl SetDDP
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _080A7EF8 @ =0xFFFFFEC0
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r1, #0xae
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A7EDA:
	ldr r0, _080A7EFC @ =pZero2
	ldr r0, [r0]
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A7F04
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7F00 @ =0x0836BEAC
	bl SetDDP
	b _080A7F0E
	.align 2, 0
_080A7EF4: .4byte 0x0836BE64
_080A7EF8: .4byte 0xFFFFFEC0
_080A7EFC: .4byte pZero2
_080A7F00: .4byte 0x0836BEAC
_080A7F04:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7F68 @ =0x0836BE64
	bl SetDDP
_080A7F0E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _080A7F62
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A7F6C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A7F62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7F68: .4byte 0x0836BE64
_080A7F6C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a7f70
FUN_080a7f70: @ 0x080A7F70
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A7FBE
	cmp r0, #1
	bgt _080A7F84
	cmp r0, #0
	beq _080A7F8E
	b _080A8072
_080A7F84:
	cmp r0, #2
	beq _080A7FF4
	cmp r0, #3
	beq _080A802E
	b _080A8072
_080A7F8E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A7FEC @ =0x0836BE7C
	bl SetDDP
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _080A7FF0 @ =0xFFFFFEE0
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	movs r0, #0xe0
	str r0, [r4, #0x60]
	movs r0, #0x40
	strb r0, [r4, #0x12]
	movs r1, #0xac
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A7FBE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	subs r1, #2
	str r1, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A8072
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A8072
	.align 2, 0
_080A7FEC: .4byte 0x0836BE7C
_080A7FF0: .4byte 0xFFFFFEE0
_080A7FF4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	subs r1, #2
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A8078 @ =0x00005601
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A802E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _080A8072
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A807C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A8072:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8078: .4byte 0x00005601
_080A807C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a8080
FUN_080a8080: @ 0x080A8080
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080A8090
	cmp r4, #1
	beq _080A80B2
	b _080A8110
_080A8090:
	movs r0, #0x40
	bl PlaySound
	strb r4, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A80EC @ =0x0836BE94
	bl SetDDP
	movs r1, #0xb0
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A80B2:
	ldr r2, _080A80F0 @ =pZero2
	ldr r0, [r2]
	ldr r1, _080A80F4 @ =0x00000143
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r4, #1
	orrs r0, r4
	strb r0, [r3]
	ldr r0, [r2]
	ldr r1, _080A80F4 @ =0x00000143
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A80F8
	ldrb r0, [r5, #0xa]
	orrs r0, r4
	b _080A80FE
	.align 2, 0
_080A80EC: .4byte 0x0836BE94
_080A80F0: .4byte pZero2
_080A80F4: .4byte 0x00000143
_080A80F8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A80FE:
	strb r0, [r5, #0xa]
	ldr r0, [r2]
	ldr r1, [r0, #0x54]
	str r1, [r5, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080A8110:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start createCopyXSonicBoom
createCopyXSonicBoom: @ 0x080A8118
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080A8168 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A8160
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A816C @ =gProjectileFnTable
	movs r0, #0x18
	strb r0, [r3, #9]
	ldr r0, [r1, #0x60]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080A8160:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A8168: .4byte gProjectileHeaderPtr
_080A816C: .4byte gProjectileFnTable

	thumb_func_start initCopyXSonicBoom
initCopyXSonicBoom: @ 0x080A8170
	push {lr}
	ldr r2, _080A8184 @ =0x0836BEE4
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A8184: .4byte 0x0836BEE4

	thumb_func_start FUN_080a8188
FUN_080a8188: @ 0x080A8188
	push {lr}
	ldr r2, _080A819C @ =0x0836BEEC
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A819C: .4byte 0x0836BEEC

	thumb_func_start FUN_080a81a0
FUN_080a81a0: @ 0x080A81A0
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080A81CC @ =gProjectileFnTable
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
_080A81CC: .4byte gProjectileFnTable

	thumb_func_start initCopyXSlidingSonicBoom
initCopyXSlidingSonicBoom: @ 0x080A81D0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r5, [r7, #0x28]
	ldr r1, _080A8220 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r1, #0xbc
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8224
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A822A
	.align 2, 0
_080A8220: .4byte gProjectileFnTable
_080A8224:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A822A:
	strb r0, [r7, #0xa]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	movs r6, #0
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080A827C @ =0x0836BEF4
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r0, #0x28
	strb r0, [r7, #0x12]
	strb r5, [r7, #0xe]
	adds r0, r7, #0
	bl FUN_080a8188
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A827C: .4byte 0x0836BEF4

	thumb_func_start moveSlidingSonicBoom
moveSlidingSonicBoom: @ 0x080A8280
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A829C
	ldr r0, [r5, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #5
	b _080A82A0
_080A829C:
	ldr r0, [r5, #0x54]
	ldr r1, _080A82D4 @ =0xFFFFE400
_080A82A0:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080A82BC
	ldrb r0, [r5, #0xd]
	cmp r0, #5
	bls _080A82BC
	cmp r0, #8
	bls _080A82CE
_080A82BC:
	ldr r1, _080A82D8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A82CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A82D4: .4byte 0xFFFFE400
_080A82D8: .4byte gProjectileFnTable

	thumb_func_start FUN_080a82dc
FUN_080a82dc: @ 0x080A82DC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r5, [r7, #0x28]
	ldr r1, _080A8328 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080A832C @ =0x00005E01
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8330
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A8336
	.align 2, 0
_080A8328: .4byte gProjectileFnTable
_080A832C: .4byte 0x00005E01
_080A8330:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A8336:
	strb r0, [r7, #0xa]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	movs r6, #0
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080A8388 @ =0x0836BF24
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r0, #0x28
	strb r0, [r7, #0x12]
	strb r5, [r7, #0xe]
	adds r0, r7, #0
	bl FUN_080a8188
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8388: .4byte 0x0836BF24

	thumb_func_start moveNovaStrikeSonicBoom
moveNovaStrikeSonicBoom: @ 0x080A838C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A83A8
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #5
	b _080A83AC
_080A83A8:
	ldr r0, [r5, #0x54]
	ldr r1, _080A83D8 @ =0xFFFFE800
_080A83AC:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _080A83DC @ =0xFFFFE600
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r5, #0xd]
	cmp r0, #0xf
	beq _080A83D0
	ldr r1, _080A83E0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A83D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A83D8: .4byte 0xFFFFE800
_080A83DC: .4byte 0xFFFFE600
_080A83E0: .4byte gProjectileFnTable

	thumb_func_start FUN_080a83e4
FUN_080a83e4: @ 0x080A83E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080A8434 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A842C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A8438 @ =gProjectileFnTable
	movs r0, #0x19
	strb r0, [r3, #9]
	ldr r0, [r1, #0x64]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080A842C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A8434: .4byte gProjectileHeaderPtr
_080A8438: .4byte gProjectileFnTable

	thumb_func_start FUN_080a843c
FUN_080a843c: @ 0x080A843C
	push {lr}
	ldr r2, _080A8450 @ =0x0836BF68
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A8450: .4byte 0x0836BF68

	thumb_func_start FUN_080a8454
FUN_080a8454: @ 0x080A8454
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A8488
	ldr r1, _080A8490 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A8488:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8490: .4byte gProjectileFnTable
_080A8494:
	.byte 0x02, 0x1C, 0x8C, 0x30, 0x00, 0x21, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60
	.byte 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x04, 0x49, 0x50, 0x7A
	.byte 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x70, 0x47
	.byte 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080a84c4
FUN_080a84c4: @ 0x080A84C4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A850C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xba
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8510
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A8516
	.align 2, 0
_080A850C: .4byte gProjectileFnTable
_080A8510:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A8516:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A854C
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	b _080A8556
_080A854C:
	ldr r0, [r6, #0x54]
	ldr r1, _080A8590 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A8594 @ =0xFFFFFC00
_080A8556:
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r1, _080A8598 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r5, #0
	str r5, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A859C @ =0x0836BF78
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a8454
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8590: .4byte 0xFFFFF000
_080A8594: .4byte 0xFFFFFC00
_080A8598: .4byte 0xFFFFE800
_080A859C: .4byte 0x0836BF78

	thumb_func_start FUN_080a85a0
FUN_080a85a0: @ 0x080A85A0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A85EC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A85F0 @ =0x00005D01
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A85F4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A85FA
	.align 2, 0
_080A85EC: .4byte gProjectileFnTable
_080A85F0: .4byte 0x00005D01
_080A85F4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A85FA:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A8630
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	b _080A863A
_080A8630:
	ldr r0, [r6, #0x54]
	ldr r1, _080A8674 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A8678 @ =0xFFFFFC00
_080A863A:
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r1, _080A867C @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r5, #0
	str r5, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A8680 @ =0x0836BFA8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a8454
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8674: .4byte 0xFFFFF000
_080A8678: .4byte 0xFFFFFC00
_080A867C: .4byte 0xFFFFE800
_080A8680: .4byte 0x0836BFA8

	thumb_func_start FUN_080a8684
FUN_080a8684: @ 0x080A8684
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A86D4 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xba
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A86D8
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A86DE
	.align 2, 0
_080A86D4: .4byte gProjectileFnTable
_080A86D8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A86DE:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A8724
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A8720 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xc0
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0x40
	b _080A873E
	.align 2, 0
_080A8720: .4byte gSineTable
_080A8724:
	ldr r0, [r6, #0x54]
	ldr r1, _080A8784 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A8788 @ =gSineTable
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0xc0
_080A873E:
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0xe0
	strb r0, [r1]
	ldr r0, [r6, #0x58]
	ldr r1, _080A878C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A8790 @ =0x0836BFD8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a8454
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8784: .4byte 0xFFFFF000
_080A8788: .4byte gSineTable
_080A878C: .4byte 0xFFFFEE00
_080A8790: .4byte 0x0836BFD8

	thumb_func_start FUN_080a8794
FUN_080a8794: @ 0x080A8794
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A87E0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A87E4 @ =0x00005D01
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A87E8
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A87EE
	.align 2, 0
_080A87E0: .4byte gProjectileFnTable
_080A87E4: .4byte 0x00005D01
_080A87E8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A87EE:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A8834
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A8830 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xc0
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0x40
	b _080A884E
	.align 2, 0
_080A8830: .4byte gSineTable
_080A8834:
	ldr r0, [r6, #0x54]
	ldr r1, _080A8894 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A8898 @ =gSineTable
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0xc0
_080A884E:
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0xe0
	strb r0, [r1]
	ldr r0, [r6, #0x58]
	ldr r1, _080A889C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A88A0 @ =0x0836BFA8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a8454
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8894: .4byte 0xFFFFF000
_080A8898: .4byte gSineTable
_080A889C: .4byte 0xFFFFEE00
_080A88A0: .4byte 0x0836BFA8

	thumb_func_start FUN_080a88a4
FUN_080a88a4: @ 0x080A88A4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080A88F4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A88EC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A88F8 @ =gProjectileFnTable
	movs r0, #0x1a
	strb r0, [r3, #9]
	ldr r0, [r1, #0x68]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080A88EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A88F4: .4byte gProjectileHeaderPtr
_080A88F8: .4byte gProjectileFnTable

	thumb_func_start FUN_080a88fc
FUN_080a88fc: @ 0x080A88FC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080A894C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080A8944
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A8950 @ =gProjectileFnTable
	movs r0, #0x1a
	strb r0, [r3, #9]
	ldr r0, [r1, #0x68]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080A8944:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A894C: .4byte gProjectileHeaderPtr
_080A8950: .4byte gProjectileFnTable

	thumb_func_start FUN_080a8954
FUN_080a8954: @ 0x080A8954
	push {lr}
	ldr r2, _080A8968 @ =0x0836C01C
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A8968: .4byte 0x0836C01C

	thumb_func_start FUN_080a896c
FUN_080a896c: @ 0x080A896C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A898C @ =0x0836C034
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A898C: .4byte 0x0836C034

	thumb_func_start FUN_080a8990
FUN_080a8990: @ 0x080A8990
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x28]
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	bhi _080A89F8
	ldrb r0, [r2, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A8A2E
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
	ldr r1, _080A89F4 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	adds r1, r3, #0
	adds r1, #0xcf
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A8A2E
	adds r0, r2, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl stopSound
	b _080A8A2E
	.align 2, 0
_080A89F4: .4byte gProjectileFnTable
_080A89F8:
	adds r0, r2, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080A8A34 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl stopSound
_080A8A2E:
	pop {r0}
	bx r0
	.align 2, 0
_080A8A34: .4byte gProjectileFnTable

	thumb_func_start FUN_080a8a38
FUN_080a8a38: @ 0x080A8A38
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, [r6, #0x28]
	ldr r1, _080A8A80 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A8A84 @ =0x00005B01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r7, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8A88
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A8A8E
	.align 2, 0
_080A8A80: .4byte gProjectileFnTable
_080A8A84: .4byte 0x00005B01
_080A8A88:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A8A8E:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	adds r4, r6, #0
	adds r4, #0xc0
	ldr r0, _080A8AD4 @ =0x0000FFFF
	strh r0, [r4]
	movs r0, #0x48
	bl PlaySound
	strh r0, [r4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A8AD8
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xe0
	lsls r0, r0, #2
	b _080A8AE2
	.align 2, 0
_080A8AD4: .4byte 0x0000FFFF
_080A8AD8:
	ldr r0, [r6, #0x54]
	ldr r1, _080A8B3C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A8B40 @ =0xFFFFFC80
_080A8AE2:
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r1, _080A8B44 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r5, #0
	str r5, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, _080A8B48 @ =0x0000FFF0
	strh r0, [r1]
	subs r1, #8
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r1, r7, #0
	adds r1, #0xcf
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A8B4C @ =0x0836C04C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #2
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl FUN_080a896c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8B3C: .4byte 0xFFFFF000
_080A8B40: .4byte 0xFFFFFC80
_080A8B44: .4byte 0xFFFFE800
_080A8B48: .4byte 0x0000FFF0
_080A8B4C: .4byte 0x0836C04C

	thumb_func_start FUN_080a8b50
FUN_080a8b50: @ 0x080A8B50
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, [r6, #0x28]
	ldr r1, _080A8B98 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A8B9C @ =0x00005B01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r7, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8BA0
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A8BA6
	.align 2, 0
_080A8B98: .4byte gProjectileFnTable
_080A8B9C: .4byte 0x00005B01
_080A8BA0:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A8BA6:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	adds r4, r6, #0
	adds r4, #0xc0
	ldr r0, _080A8BF0 @ =0x0000FFFF
	strh r0, [r4]
	movs r0, #0x48
	bl PlaySound
	strh r0, [r4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A8BF4
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	b _080A8C04
	.align 2, 0
_080A8BF0: .4byte 0x0000FFFF
_080A8BF4:
	ldr r0, [r6, #0x54]
	ldr r1, _080A8C60 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A8C64 @ =0xFFFFFC80
	str r0, [r6, #0x5c]
	movs r0, #0xe0
	lsls r0, r0, #2
_080A8C04:
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x58]
	ldr r1, _080A8C68 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xbc
	movs r5, #0
	ldr r0, _080A8C6C @ =0x0000FFE8
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xcf
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A8C70 @ =0x0836C04C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #2
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl FUN_080a896c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8C60: .4byte 0xFFFFF000
_080A8C64: .4byte 0xFFFFFC80
_080A8C68: .4byte 0xFFFFEE00
_080A8C6C: .4byte 0x0000FFE8
_080A8C70: .4byte 0x0836C04C

	thumb_func_start FUN_080a8c74
FUN_080a8c74: @ 0x080A8C74
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A8CBC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xb6
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8CC0
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A8CC6
	.align 2, 0
_080A8CBC: .4byte gProjectileFnTable
_080A8CC0:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A8CC6:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, _080A8D1C @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r0]
	str r1, [r6, #0x54]
	adds r0, #4
	ldr r0, [r0]
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb4
	str r1, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r0, [r6, #0x58]
	str r0, [r1]
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _080A8D24
	ldr r0, [r5, #0x5c]
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	adds r1, #4
	ldr r0, _080A8D20 @ =0x0000FFF0
	b _080A8D34
	.align 2, 0
_080A8D1C: .4byte 0x0000FFFF
_080A8D20: .4byte 0x0000FFF0
_080A8D24:
	ldr r0, [r5, #0x5c]
	str r0, [r6, #0x5c]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, _080A8D68 @ =0x0000FFE8
_080A8D34:
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A8D6C @ =0x0836C04C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #2
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl FUN_080a896c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8D68: .4byte 0x0000FFE8
_080A8D6C: .4byte 0x0836C04C

	thumb_func_start FUN_080a8d70
FUN_080a8d70: @ 0x080A8D70
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A8DB8 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A8DBC @ =0x00005B01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8DC0
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A8DC6
	.align 2, 0
_080A8DB8: .4byte gProjectileFnTable
_080A8DBC: .4byte 0x00005B01
_080A8DC0:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A8DC6:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, _080A8DFC @ =0x0000FFFF
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A8E04
	ldr r0, [r6, #0x54]
	ldr r1, _080A8E00 @ =0xFFFFFB00
	b _080A8E0A
	.align 2, 0
_080A8DFC: .4byte 0x0000FFFF
_080A8E00: .4byte 0xFFFFFB00
_080A8E04:
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #3
_080A8E0A:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, _080A8E54 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _080A8E58 @ =0x0836C0AC
	ldrb r0, [r6, #0x11]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r6, #0x5c]
	ldr r0, _080A8E5C @ =0xFFFFFA00
	str r0, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A8E60 @ =0x0836C04C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a896c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8E54: .4byte 0xFFFFD800
_080A8E58: .4byte 0x0836C0AC
_080A8E5C: .4byte 0xFFFFFA00
_080A8E60: .4byte 0x0836C04C

	thumb_func_start FUN_080a8e64
FUN_080a8e64: @ 0x080A8E64
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A8EAC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A8EB0 @ =0x00005B02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A8EB4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A8EBA
	.align 2, 0
_080A8EAC: .4byte gProjectileFnTable
_080A8EB0: .4byte 0x00005B02
_080A8EB4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A8EBA:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	movs r5, #0
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
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, _080A8F0C @ =0x0000FFFF
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A8F10 @ =0x0836C07C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	strb r5, [r6, #0x12]
	adds r0, r6, #0
	bl FUN_080a896c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8F0C: .4byte 0x0000FFFF
_080A8F10: .4byte 0x0836C07C

	thumb_func_start FUN_080a8f14
FUN_080a8f14: @ 0x080A8F14
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _080A8F60
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A8F60
	ldrb r2, [r4, #0x11]
	cmp r2, #1
	beq _080A8F5A
	ldrb r1, [r4, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A8F4C
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080a88fc
	b _080A8F5A
_080A8F4C:
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080a88fc
_080A8F5A:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080A8F60:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r3, [r4, #0x60]
	adds r1, r1, r3
	str r1, [r4, #0x58]
	adds r2, r4, #0
	adds r2, #0xbc
	movs r5, #0
	ldrsh r2, [r2, r5]
	adds r3, r3, r2
	str r3, [r4, #0x60]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A8F9C
	ldr r1, _080A8FA4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0x10
	strb r0, [r4, #0x12]
_080A8F9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8FA4: .4byte gProjectileFnTable

	thumb_func_start FUN_080a8fa8
FUN_080a8fa8: @ 0x080A8FA8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	adds r2, #0x40
	str r2, [r4, #0x60]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A8FE6
	ldr r1, _080A8FEC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0
	bl FUN_080a88fc
_080A8FE6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8FEC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a8ff0
FUN_080a8ff0: @ 0x080A8FF0
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x12]
	adds r0, #1
	movs r1, #0
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x24
	bne _080A901A
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
_080A901A:
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080A903E
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080A9044 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_080A903E:
	pop {r0}
	bx r0
	.align 2, 0
_080A9044: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9048
FUN_080a9048: @ 0x080A9048
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080A9098 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A9090
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A909C @ =gProjectileFnTable
	movs r0, #0x1b
	strb r0, [r3, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080A9090:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9098: .4byte gProjectileHeaderPtr
_080A909C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a90a0
FUN_080a90a0: @ 0x080A90A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080A90F0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A90E8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A90F4 @ =gProjectileFnTable
	movs r0, #0x1b
	strb r0, [r3, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080A90E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A90F0: .4byte gProjectileHeaderPtr
_080A90F4: .4byte gProjectileFnTable

	thumb_func_start FUN_080a90f8
FUN_080a90f8: @ 0x080A90F8
	push {lr}
	ldr r2, _080A910C @ =0x0836C0D0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A910C: .4byte 0x0836C0D0

	thumb_func_start FUN_080a9110
FUN_080a9110: @ 0x080A9110
	push {lr}
	ldr r2, _080A9124 @ =0x0836C0EC
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A9124: .4byte 0x0836C0EC
_080A9128:
	.byte 0x02, 0x1C, 0x8C, 0x30, 0x00, 0x21, 0x01, 0x60
	.byte 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72
	.byte 0x04, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69
	.byte 0x50, 0x61, 0x70, 0x47, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080a9158
FUN_080a9158: @ 0x080A9158
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A91A0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xb8
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A91A4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A91AA
	.align 2, 0
_080A91A0: .4byte gProjectileFnTable
_080A91A4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A91AA:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A91EC
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, _080A91E8 @ =0x0000FFE0
	b _080A91FE
	.align 2, 0
_080A91E8: .4byte 0x0000FFE0
_080A91EC:
	ldr r0, [r6, #0x54]
	ldr r1, _080A9240 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A9244 @ =0xFFFFFD00
	str r0, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #0x20
_080A91FE:
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xbe
	movs r5, #0
	strh r5, [r0]
	ldr r0, [r6, #0x58]
	ldr r1, _080A9248 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	str r5, [r6, #0x60]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A924C @ =0x0836C108
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a9110
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9240: .4byte 0xFFFFF000
_080A9244: .4byte 0xFFFFFD00
_080A9248: .4byte 0xFFFFE800
_080A924C: .4byte 0x0836C108

	thumb_func_start FUN_080a9250
FUN_080a9250: @ 0x080A9250
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A9298 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xb8
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A929C
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A92A2
	.align 2, 0
_080A9298: .4byte gProjectileFnTable
_080A929C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A92A2:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A92E8
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, _080A92E4 @ =0x0000FFE0
	b _080A9300
	.align 2, 0
_080A92E4: .4byte 0x0000FFE0
_080A92E8:
	ldr r0, [r6, #0x54]
	ldr r1, _080A9344 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A9348 @ =0xFFFFFD00
	str r0, [r6, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #0x20
_080A9300:
	strh r0, [r1]
	ldr r0, [r6, #0x58]
	ldr r1, _080A934C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r5, #0
	ldr r0, _080A9350 @ =0x0000FFE0
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A9354 @ =0x0836C108
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl FUN_080a9110
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9344: .4byte 0xFFFFF000
_080A9348: .4byte 0xFFFFFD00
_080A934C: .4byte 0xFFFFEE00
_080A9350: .4byte 0x0000FFE0
_080A9354: .4byte 0x0836C108

	thumb_func_start FUN_080a9358
FUN_080a9358: @ 0x080A9358
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080A93B4
	cmp r0, #1
	bgt _080A9370
	cmp r0, #0
	beq _080A9376
	b _080A9442
_080A9370:
	cmp r0, #2
	beq _080A9400
	b _080A9442
_080A9376:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xbe
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	cmp r2, #0
	bge _080A93A4
	rsbs r2, r2, #0
_080A93A4:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	bgt _080A9442
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080A9442
_080A93B4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r2, r0
	ldr r0, _080A93D8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	subs r1, r1, r0
	asrs r1, r1, #9
	cmp r1, #0
	ble _080A93DC
	adds r0, r2, #0
	subs r0, #0x40
	b _080A93E4
	.align 2, 0
_080A93D8: .4byte pZero2
_080A93DC:
	cmp r1, #0
	bge _080A93E6
	adds r0, r2, #0
	adds r0, #0x40
_080A93E4:
	str r0, [r4, #0x58]
_080A93E6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A9442
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0x40
	strb r0, [r4, #0x12]
	b _080A9442
_080A9400:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r1, [r4, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bls _080A941C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A9422
_080A941C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A9422:
	strb r0, [r4, #0xa]
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A9442
	ldr r1, _080A9468 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9442:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A9462
	ldr r1, _080A9468 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9462:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A9468: .4byte gProjectileFnTable

	thumb_func_start FUN_080a946c
FUN_080a946c: @ 0x080A946C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080A94AC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A94B0 @ =0x00005C01
	adds r0, r6, #0
	bl SetMotion
	ldrb r2, [r6, #0x11]
	cmp r2, #0
	beq _080A94B4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A94BA
	.align 2, 0
_080A94AC: .4byte gProjectileFnTable
_080A94B0: .4byte 0x00005C01
_080A94B4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A94BA:
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A94F8
	ldr r0, [r6, #0x54]
	ldr r1, _080A94F0 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A94F4 @ =0xFFFFFF00
	b _080A9506
	.align 2, 0
_080A94F0: .4byte 0xFFFFF000
_080A94F4: .4byte 0xFFFFFF00
_080A94F8:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0x80
	lsls r0, r0, #1
_080A9506:
	str r0, [r6, #0x5c]
	movs r5, #0
	strb r5, [r6, #0x12]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A9538 @ =0x0836C138
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a9110
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9538: .4byte 0x0836C138

	thumb_func_start FUN_080a953c
FUN_080a953c: @ 0x080A953C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080A9586
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080A9558
	ldr r0, [r6, #0x54]
	ldr r1, _080A9554 @ =0xFFFFE000
	b _080A955E
	.align 2, 0
_080A9554: .4byte 0xFFFFE000
_080A9558:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
_080A955E:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r5, #0
	strb r5, [r6, #0xe]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A95F8 @ =0x0836C138
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	strb r5, [r6, #0x12]
_080A9586:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bne _080A95C2
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A95FC @ =0x0836C168
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
_080A95C2:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080A95D2
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A95D2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A95F2
	ldr r1, _080A9600 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A95F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A95F8: .4byte 0x0836C138
_080A95FC: .4byte 0x0836C168
_080A9600: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9604
FUN_080a9604: @ 0x080A9604
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A964C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A9650 @ =0x00005C02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A9654
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A965A
	.align 2, 0
_080A964C: .4byte gProjectileFnTable
_080A9650: .4byte 0x00005C02
_080A9654:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A965A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A9690
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	b _080A969A
_080A9690:
	ldr r0, [r6, #0x54]
	ldr r1, _080A96E8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A96EC @ =0xFFFFFC00
_080A969A:
	str r0, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0x24
	movs r5, #0
	movs r0, #0xc0
	strb r0, [r1]
	ldr r1, [r6, #0x58]
	ldr r0, _080A96F0 @ =0xFFFFE800
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl FUN_08009f6c
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	str r5, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A96F4 @ =0x0836C198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a9110
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A96E8: .4byte 0xFFFFF000
_080A96EC: .4byte 0xFFFFFC00
_080A96F0: .4byte 0xFFFFE800
_080A96F4: .4byte 0x0836C198

	thumb_func_start FUN_080a96f8
FUN_080a96f8: @ 0x080A96F8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A9740 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A9744 @ =0x00005C02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A9748
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A974E
	.align 2, 0
_080A9740: .4byte gProjectileFnTable
_080A9744: .4byte 0x00005C02
_080A9748:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A974E:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A9794
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A9790 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xc0
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0x40
	b _080A97AE
	.align 2, 0
_080A9790: .4byte gSineTable
_080A9794:
	ldr r0, [r6, #0x54]
	ldr r1, _080A9800 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A9804 @ =gSineTable
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0xc0
_080A97AE:
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0x24
	movs r5, #0
	movs r0, #0xa0
	strb r0, [r1]
	ldr r1, [r6, #0x58]
	ldr r0, _080A9808 @ =0xFFFFEE00
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl FUN_08009f6c
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A980C @ =0x0836C198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl FUN_080a9110
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9800: .4byte 0xFFFFF000
_080A9804: .4byte gSineTable
_080A9808: .4byte 0xFFFFEE00
_080A980C: .4byte 0x0836C198

	thumb_func_start FUN_080a9810
FUN_080a9810: @ 0x080A9810
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9840
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	bl FUN_080a90a0
_080A9840:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A9916
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	cmp r1, r0
	bgt _080A988E
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x2b
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x15
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xea
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xd4
	bl FUN_080a90a0
	b _080A98FE
_080A988E:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A98CC
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xeb
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xd5
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xc0
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xab
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x95
	bl FUN_080a90a0
	b _080A98FE
_080A98CC:
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x6b
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x55
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x40
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x2b
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x15
	bl FUN_080a90a0
_080A98FE:
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080A991C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9916:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A991C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9920
FUN_080a9920: @ 0x080A9920
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080A99C4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitRotatableMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A99C8 @ =0x00005C03
	adds r0, r4, #0
	bl SetMotion
	movs r6, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r3, _080A99CC @ =gSineTable
	ldrb r2, [r4, #0x11]
	adds r1, r2, #0
	adds r1, #0xc0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080A99D0 @ =0x0836C1C8
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080a9110
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A99C4: .4byte gProjectileFnTable
_080A99C8: .4byte 0x00005C03
_080A99CC: .4byte gSineTable
_080A99D0: .4byte 0x0836C1C8

	thumb_func_start FUN_080a99d4
FUN_080a99d4: @ 0x080A99D4
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r3, [r4, #0xd]
	cmp r3, #0
	bne _080A9A06
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A9A24
	adds r0, r3, #1
	strb r0, [r4, #0xd]
	b _080A9A24
_080A9A06:
	adds r0, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A9A24
	ldr r1, _080A9A2C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9A24:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A9A2C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9a30
FUN_080a9a30: @ 0x080A9A30
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A9A6C @ =0x00005C04
	adds r0, r4, #0
	bl SetMotion
	ldr r1, _080A9A70 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080a9110
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A9A6C: .4byte 0x00005C04
_080A9A70: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9a74
FUN_080a9a74: @ 0x080A9A74
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r0, r4, #0
	bl CreateVFX53
	ldr r1, _080A9A9C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A9A9C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9aa0
FUN_080a9aa0: @ 0x080A9AA0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080A9AF0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080A9AE8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080A9AF4 @ =gProjectileFnTable
	movs r0, #0x1c
	strb r0, [r3, #9]
	ldr r0, [r1, #0x70]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080A9AE8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9AF0: .4byte gProjectileHeaderPtr
_080A9AF4: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9af8
FUN_080a9af8: @ 0x080A9AF8
	push {lr}
	ldr r2, _080A9B0C @ =0x0836C20C
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A9B0C: .4byte 0x0836C20C

	thumb_func_start FUN_080a9b10
FUN_080a9b10: @ 0x080A9B10
	push {lr}
	ldr r2, _080A9B24 @ =0x0836C21C
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080A9B24: .4byte 0x0836C21C

	thumb_func_start FUN_080a9b28
FUN_080a9b28: @ 0x080A9B28
	push {lr}
	mov ip, r0
	ldrb r0, [r0, #0x10]
	cmp r0, #1
	bls _080A9B4A
	ldr r1, _080A9B80 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _080A9B84 @ =0x0000BFFF
	ands r0, r2
	movs r3, #0
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfe
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r0, _080A9B88 @ =gPaletteManager
	strh r3, [r0]
_080A9B4A:
	mov r0, ip
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	mov r0, ip
	ldrb r1, [r0, #0xa]
	movs r0, #0xfb
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
	ldr r1, _080A9B8C @ =gProjectileFnTable
	mov r2, ip
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	pop {r0}
	bx r0
	.align 2, 0
_080A9B80: .4byte gWindowRegBuffer
_080A9B84: .4byte 0x0000BFFF
_080A9B88: .4byte gPaletteManager
_080A9B8C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9b90
FUN_080a9b90: @ 0x080A9B90
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A9BD8 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xbe
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A9BDC
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A9BE2
	.align 2, 0
_080A9BD8: .4byte gProjectileFnTable
_080A9BDC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A9BE2:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A9C20
	ldr r0, [r6, #0x54]
	movs r1, #0xf8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0x80
	str r0, [r6, #0x5c]
	movs r0, #0x7f
	strb r0, [r6, #0x12]
	b _080A9C30
_080A9C20:
	ldr r0, [r6, #0x54]
	ldr r2, _080A9C7C @ =0xFFFFE100
	adds r0, r0, r2
	str r0, [r6, #0x54]
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r6, #0x5c]
	strb r1, [r6, #0x12]
_080A9C30:
	ldr r0, [r6, #0x58]
	ldr r1, _080A9C80 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r5, #0
	str r5, [r6, #0x60]
	strb r5, [r6, #0x13]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A9C84 @ =0x0836C22C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	movs r0, #1
	strb r0, [r6, #0xe]
	adds r0, r6, #0
	bl FUN_080a9b10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9C7C: .4byte 0xFFFFE100
_080A9C80: .4byte 0xFFFFE800
_080A9C84: .4byte 0x0836C22C

	thumb_func_start FUN_080a9c88
FUN_080a9c88: @ 0x080A9C88
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A9CEC
	adds r5, r6, #0
	adds r5, #0xb4
	ldr r4, _080A9CE8 @ =gSineTable
	ldrb r2, [r6, #0x12]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xb
	muls r1, r0, r1
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r3, r6, #0
	adds r3, #0xb8
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x16
	muls r1, r0, r1
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r2, #0x10
	strb r2, [r6, #0x12]
	ldr r0, [r6, #0x5c]
	adds r0, #8
	str r0, [r6, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080A9D36
	b _080A9D34
	.align 2, 0
_080A9CE8: .4byte gSineTable
_080A9CEC:
	adds r5, r6, #0
	adds r5, #0xb4
	ldr r4, _080A9D7C @ =gSineTable
	ldrb r2, [r6, #0x12]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xb
	muls r1, r0, r1
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r3, r6, #0
	adds r3, #0xb8
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x16
	muls r1, r0, r1
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	subs r2, #0x10
	strb r2, [r6, #0x12]
	ldr r0, [r6, #0x5c]
	subs r0, #8
	str r0, [r6, #0x5c]
	ldr r1, _080A9D80 @ =0xFFFFFE00
	cmp r0, r1
	bge _080A9D36
_080A9D34:
	str r1, [r6, #0x5c]
_080A9D36:
	ldrb r1, [r6, #0x13]
	adds r0, r1, #1
	strb r0, [r6, #0x13]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080A9D4E
	adds r0, r6, #0
	movs r1, #6
	movs r2, #0
	bl FUN_080a90a0
_080A9D4E:
	ldr r0, [r5]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r5]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A9D76
	ldr r1, _080A9D84 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A9D76:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9D7C: .4byte gSineTable
_080A9D80: .4byte 0xFFFFFE00
_080A9D84: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9d88
FUN_080a9d88: @ 0x080A9D88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080A9DC4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r5, #1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A9DC8 @ =0x00005F01
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0xe]
	adds r0, r4, #0
	bl FUN_080a9b10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A9DC4: .4byte gProjectileFnTable
_080A9DC8: .4byte 0x00005F01

	thumb_func_start FUN_080a9dcc
FUN_080a9dcc: @ 0x080A9DCC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A9DEE
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A9DF4
_080A9DEE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A9DF4:
	strb r0, [r4, #0xa]
	movs r6, #1
	adds r1, r6, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A9E40
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A9E2C
	ldr r1, _080A9E3C @ =0x00005F01
	adds r0, r4, #0
	bl SetMotion
_080A9E2C:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _080A9E4A
	.align 2, 0
_080A9E3C: .4byte 0x00005F01
_080A9E40:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	strb r6, [r4, #0xe]
_080A9E4A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A9E68
	ldr r1, _080A9E70 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9E68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9E70: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9e74
FUN_080a9e74: @ 0x080A9E74
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, _080A9EE4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _080A9EE8 @ =FUN_080a9fe4
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r1, _080A9EEC @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x31
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r1, _080A9EF0 @ =gPaletteManager
	ldr r2, _080A9EF4 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	strb r3, [r4, #0x13]
	strb r3, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_080a9b10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A9EE4: .4byte gProjectileFnTable
_080A9EE8: .4byte FUN_080a9fe4
_080A9EEC: .4byte gWindowRegBuffer
_080A9EF0: .4byte gPaletteManager
_080A9EF4: .4byte 0x00007FFF

	thumb_func_start FUN_080a9ef8
FUN_080a9ef8: @ 0x080A9EF8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080A9F28 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080A9F30
	ldr r1, _080A9F2C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080a9b28
	b _080A9FD8
	.align 2, 0
_080A9F28: .4byte gStageRun
_080A9F2C: .4byte gProjectileFnTable
_080A9F30:
	ldrb r6, [r5, #0xd]
	cmp r6, #1
	beq _080A9F84
	cmp r6, #1
	bgt _080A9F40
	cmp r6, #0
	beq _080A9F46
	b _080A9FD2
_080A9F40:
	cmp r6, #2
	beq _080A9FB0
	b _080A9FD2
_080A9F46:
	ldrb r0, [r5, #0x13]
	adds r0, #4
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080A9FD2
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080A9F80 @ =0x0836C25C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	b _080A9FD2
	.align 2, 0
_080A9F80: .4byte 0x0836C25C
_080A9F84:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A9FD2
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _080A9FD2
_080A9FB0:
	ldrb r0, [r5, #0x13]
	subs r0, #4
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A9FD2
	ldr r1, _080A9FE0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080a9b28
_080A9FD2:
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_080A9FD8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9FE0: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9fe4
FUN_080a9fe4: @ 0x080A9FE4
	push {r4, r5, r6, lr}
	adds r3, r1, #0
	adds r3, #8
	ldr r2, [r0, #8]
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bhi _080AA082
	ldr r0, [r2, #0x54]
	ldr r1, [r1, #8]
	subs r0, r0, r1
	asrs r5, r0, #8
	ldr r0, [r2, #0x58]
	ldr r1, [r3, #4]
	subs r0, r0, r1
	asrs r0, r0, #8
	adds r4, r0, #2
	ldrb r1, [r2, #0xf]
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bls _080AA01C
	ldr r1, _080AA014 @ =gPaletteManager
	ldr r3, _080AA018 @ =0x00007FFF
	b _080AA022
	.align 2, 0
_080AA014: .4byte gPaletteManager
_080AA018: .4byte 0x00007FFF
_080AA01C:
	ldr r1, _080AA040 @ =gPaletteManager
	movs r3, #0xf8
	lsls r3, r3, #7
_080AA022:
	adds r0, r3, #0
	strh r0, [r1]
	ldrb r0, [r2, #0x13]
	subs r1, r5, r0
	lsls r1, r1, #0x10
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	bge _080AA044
	movs r6, #0
	b _080AA04A
	.align 2, 0
_080AA040: .4byte gPaletteManager
_080AA044:
	cmp r1, #0xf0
	ble _080AA04A
	movs r6, #0xf0
_080AA04A:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA056
	movs r5, #0
	b _080AA05C
_080AA056:
	cmp r0, #0xf0
	ble _080AA05C
	movs r5, #0xf0
_080AA05C:
	cmp r4, #0
	bge _080AA064
	movs r4, #0
	b _080AA06A
_080AA064:
	cmp r4, #0xa0
	ble _080AA06A
	movs r4, #0xa0
_080AA06A:
	ldr r2, _080AA088 @ =gWindowRegBuffer
	movs r3, #0xff
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xff
	ands r1, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #8
	orrs r1, r0
	strh r1, [r2, #6]
	ands r4, r3
	strh r4, [r2, #0xa]
_080AA082:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA088: .4byte gWindowRegBuffer

	thumb_func_start FUN_080aa08c
FUN_080aa08c: @ 0x080AA08C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, _080AA10C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _080AA110 @ =FUN_080aa15c
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r1, _080AA114 @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x31
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r1, _080AA118 @ =gPaletteManager
	ldr r2, _080AA11C @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x58]
	str r0, [r1]
	strb r3, [r4, #0x13]
	strb r3, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_080a9b10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA10C: .4byte gProjectileFnTable
_080AA110: .4byte FUN_080aa15c
_080AA114: .4byte gWindowRegBuffer
_080AA118: .4byte gPaletteManager
_080AA11C: .4byte 0x00007FFF

	thumb_func_start FUN_080aa120
FUN_080aa120: @ 0x080AA120
	push {lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xf
	beq _080AA152
	ldr r1, _080AA158 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	adds r0, r3, #0
	bl FUN_080a9b28
_080AA152:
	pop {r0}
	bx r0
	.align 2, 0
_080AA158: .4byte gProjectileFnTable

	thumb_func_start FUN_080aa15c
FUN_080aa15c: @ 0x080AA15C
	push {r4, r5, r6, lr}
	adds r3, r1, #0
	adds r3, #8
	ldr r2, [r0, #8]
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bhi _080AA242
	ldr r0, [r2, #0x54]
	ldr r1, [r1, #8]
	subs r0, r0, r1
	asrs r4, r0, #8
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r3, #4]
	subs r0, r0, r1
	asrs r0, r0, #8
	adds r6, r0, #0
	subs r6, #0x20
	ldrb r1, [r2, #0x13]
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bls _080AA19C
	ldr r1, _080AA194 @ =gPaletteManager
	ldr r5, _080AA198 @ =0x00007FFF
	b _080AA1A0
	.align 2, 0
_080AA194: .4byte gPaletteManager
_080AA198: .4byte 0x00007FFF
_080AA19C:
	ldr r1, _080AA1D0 @ =gPaletteManager
	ldr r5, _080AA1D4 @ =0x000003FF
_080AA1A0:
	adds r0, r5, #0
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3]
	subs r0, r0, r1
	lsls r0, r0, #8
	lsrs r5, r0, #0x10
	lsls r0, r4, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r5, #0x10
	lsls r0, r2, #0x10
	cmp r1, r0
	ble _080AA1C2
	lsrs r5, r0, #0x10
	lsrs r2, r1, #0x10
_080AA1C2:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA1D8
	movs r5, #0
	b _080AA1DE
	.align 2, 0
_080AA1D0: .4byte gPaletteManager
_080AA1D4: .4byte 0x000003FF
_080AA1D8:
	cmp r0, #0xf0
	ble _080AA1DE
	movs r5, #0xf0
_080AA1DE:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA1EA
	movs r2, #0
	b _080AA1F0
_080AA1EA:
	cmp r0, #0xf0
	ble _080AA1F0
	movs r2, #0xf0
_080AA1F0:
	adds r1, r6, #0
	subs r1, #8
	lsls r1, r1, #0x10
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	bge _080AA20A
	movs r6, #0
	b _080AA210
_080AA20A:
	cmp r1, #0xa0
	ble _080AA210
	movs r6, #0xa0
_080AA210:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA21C
	movs r4, #0
	b _080AA222
_080AA21C:
	cmp r0, #0xa0
	ble _080AA222
	movs r4, #0xa0
_080AA222:
	ldr r3, _080AA248 @ =gWindowRegBuffer
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	movs r2, #0xff
	ands r1, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #6]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ands r0, r2
	lsls r1, r6, #0x10
	asrs r1, r1, #8
	orrs r0, r1
	strh r0, [r3, #0xa]
_080AA242:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA248: .4byte gWindowRegBuffer

	thumb_func_start copyx_080aa24c
copyx_080aa24c: @ 0x080AA24C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080AA294 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AA28C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080AA298 @ =gProjectileFnTable
	movs r0, #0x1d
	strb r0, [r3, #9]
	ldr r0, [r1, #0x74]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080AA28C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA294: .4byte gProjectileHeaderPtr
_080AA298: .4byte gProjectileFnTable

	thumb_func_start FUN_080aa29c
FUN_080aa29c: @ 0x080AA29C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r6, [r7, #0x28]
	ldr r1, _080AA2E8 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r1, #0xc0
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080AA2EC
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AA2F2
	.align 2, 0
_080AA2E8: .4byte gProjectileFnTable
_080AA2EC:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AA2F2:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	movs r2, #0
	mov r8, r2
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r7, #0xa]
	movs r5, #4
	orrs r0, r5
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080AA364 @ =0x0836C2A0
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r7, [r4, #0x2c]
	mov r0, r8
	str r0, [r4, #0x24]
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r5
	strb r0, [r2]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080AA38C
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AA368
	ldr r0, [r6, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r7, #0x54]
	movs r0, #0xa0
	lsls r0, r0, #3
	b _080AA372
	.align 2, 0
_080AA364: .4byte 0x0836C2A0
_080AA368:
	ldr r0, [r6, #0x54]
	ldr r2, _080AA380 @ =0xFFFFEB00
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, _080AA384 @ =0xFFFFFB00
_080AA372:
	str r0, [r7, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r4, _080AA388 @ =0xFFFFE900
	adds r0, r0, r4
	str r0, [r7, #0x58]
	movs r0, #0
	b _080AA3E6
	.align 2, 0
_080AA380: .4byte 0xFFFFEB00
_080AA384: .4byte 0xFFFFFB00
_080AA388: .4byte 0xFFFFE900
_080AA38C:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AA3A8
	ldr r0, [r6, #0x54]
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r1, r7, #0
	adds r1, #0xc0
	movs r0, #0x20
	b _080AA3B6
_080AA3A8:
	ldr r0, [r6, #0x54]
	ldr r2, _080AA400 @ =0xFFFFEF00
	adds r0, r0, r2
	str r0, [r7, #0x54]
	adds r1, r7, #0
	adds r1, #0xc0
	movs r0, #0x60
_080AA3B6:
	strb r0, [r1]
	adds r3, r1, #0
	ldr r0, [r6, #0x58]
	ldr r4, _080AA404 @ =0xFFFFF200
	adds r0, r0, r4
	str r0, [r7, #0x58]
	ldr r2, _080AA408 @ =gSineTable
	ldrb r0, [r3]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
_080AA3E6:
	str r0, [r7, #0x60]
	movs r1, #0
	movs r0, #0x14
	strb r0, [r7, #0x12]
	strb r1, [r7, #0x13]
	adds r0, r7, #0
	bl FUN_080aa40c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA400: .4byte 0xFFFFEF00
_080AA404: .4byte 0xFFFFF200
_080AA408: .4byte gSineTable

	thumb_func_start FUN_080aa40c
FUN_080aa40c: @ 0x080AA40C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080AA438
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _080AA438
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl CreateVFX56
	movs r0, #0
	strb r0, [r4, #0x12]
_080AA438:
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080AA4B8
	cmp r0, #1
	bgt _080AA448
	cmp r0, #0
	beq _080AA44E
	b _080AA56C
_080AA448:
	cmp r0, #2
	beq _080AA524
	b _080AA56C
_080AA44E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080AA46E
	movs r0, #0x4d
	bl PlaySound
	ldrb r0, [r4, #0xd]
	adds r0, #1
	ldrb r1, [r4, #0x10]
	adds r0, r0, r1
	strb r0, [r4, #0xd]
	b _080AA56C
_080AA46E:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080AA494
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _080AA490 @ =0x0000B31B
	cmp r0, r1
	beq _080AA56C
	movs r0, #0x4d
	bl PlaySound
	b _080AA516
	.align 2, 0
_080AA490: .4byte 0x0000B31B
_080AA494:
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _080AA4B4 @ =0x0000B31C
	cmp r0, r1
	beq _080AA56C
	movs r0, #0x4d
	bl PlaySound
	ldrb r0, [r4, #0xd]
	adds r0, #2
	strb r0, [r4, #0xd]
	b _080AA56C
	.align 2, 0
_080AA4B4: .4byte 0x0000B31C
_080AA4B8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AA56C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	bge _080AA4E0
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0x20
	b _080AA4E6
_080AA4E0:
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0x60
_080AA4E6:
	strb r0, [r1]
	adds r3, r1, #0
	ldr r2, _080AA520 @ =gSineTable
	ldrb r0, [r3]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
_080AA516:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080AA56C
	.align 2, 0
_080AA520: .4byte gSineTable
_080AA524:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AA546
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	rsbs r1, r1, #0
	str r1, [r4, #0x5c]
	b _080AA566
_080AA546:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AA56C
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	rsbs r1, r1, #0
	str r1, [r4, #0x60]
_080AA566:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
_080AA56C:
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bls _080AA5BC
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl CreateVFX56
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x20
	bl CreateVFX56
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x40
	bl CreateVFX56
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x60
	bl CreateVFX56
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x80
	bl CreateVFX56
	ldr r1, _080AA5C4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080aa5c8
_080AA5BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA5C4: .4byte gProjectileFnTable

	thumb_func_start FUN_080aa5c8
FUN_080aa5c8: @ 0x080AA5C8
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080AA5E4 @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080AA5E4: .4byte gProjectileFnTable

	thumb_func_start FUN_080aa5e8
FUN_080aa5e8: @ 0x080AA5E8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AA630 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AA62A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080AA634 @ =gProjectileFnTable
	movs r0, #0x1e
	strb r0, [r3, #9]
	ldr r0, [r1, #0x78]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x5c]
	str r7, [r3, #0x60]
_080AA62A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA630: .4byte gProjectileHeaderPtr
_080AA634: .4byte gProjectileFnTable

	thumb_func_start nop_080aa638
nop_080aa638: @ 0x080AA638
	bx lr
	.align 2, 0

	thumb_func_start FUN_080aa63c
FUN_080aa63c: @ 0x080AA63C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080AA69C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080AA6A0 @ =0x0836C304
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
	ldr r1, _080AA6A4 @ =0x0836C2EC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080AA6A8 @ =nop_080aa638
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080aa6ac
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA69C: .4byte gProjectileFnTable
_080AA6A0: .4byte 0x0836C304
_080AA6A4: .4byte 0x0836C2EC
_080AA6A8: .4byte nop_080aa638

	thumb_func_start FUN_080aa6ac
FUN_080aa6ac: @ 0x080AA6AC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AA6D8 @ =0x0836C2E4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080AA6DC @ =0x0836C2E8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AA6D8: .4byte 0x0836C2E4
_080AA6DC: .4byte 0x0836C2E8
_080AA6E0:
	.byte 0x02, 0x1C, 0x8C, 0x30, 0x00, 0x21, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70
	.byte 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x04, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18
	.byte 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x70, 0x47, 0x0C, 0xA9, 0x36, 0x08
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080aa714
FUN_080aa714: @ 0x080AA714
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080AA724
	cmp r0, #1
	beq _080AA728
	b _080AA798
_080AA724:
	movs r0, #1
	strb r0, [r4, #0xe]
_080AA728:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x20
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _080AA746
	str r0, [r4, #0x60]
_080AA746:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1d
	ldr r1, _080AA7A0 @ =0x0836C306
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AA798
	ldr r1, _080AA7A4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080AA798:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AA7A0: .4byte 0x0836C306
_080AA7A4: .4byte gProjectileFnTable

	thumb_func_start FUN_080aa7a8
FUN_080aa7a8: @ 0x080AA7A8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080AA7C8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	bne _080AA7CC
	movs r0, #0
	b _080AA7FC
	.align 2, 0
_080AA7C8: .4byte gProjectileHeaderPtr
_080AA7CC:
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080AA804 @ =gProjectileFnTable
	movs r0, #0x1f
	strb r0, [r3, #9]
	ldr r0, [r1, #0x7c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r0, r3, #0
_080AA7FC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AA804: .4byte gProjectileFnTable

	thumb_func_start FUN_080aa808
FUN_080aa808: @ 0x080AA808
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, [r6, #0x28]
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080AA894 @ =0x0000640F
	adds r0, r6, #0
	bl SetMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AA898 @ =0x0836C32C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AA8A4
	ldr r2, _080AA89C @ =0x0836C35C
	ldrb r1, [r6, #0x11]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldr r1, _080AA8A0 @ =0x0836C36C
	ldrb r0, [r6, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _080AA8C4
	.align 2, 0
_080AA894: .4byte 0x0000640F
_080AA898: .4byte 0x0836C32C
_080AA89C: .4byte 0x0836C35C
_080AA8A0: .4byte 0x0836C36C
_080AA8A4:
	ldr r2, _080AA91C @ =0x0836C35C
	ldrb r1, [r6, #0x11]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r6, #0x54]
	ldr r1, _080AA920 @ =0x0836C36C
	ldrb r0, [r6, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	rsbs r0, r0, #0
_080AA8C4:
	str r0, [r6, #0x5c]
	ldrb r2, [r6, #0x11]
	ldr r0, [r7, #0x58]
	ldr r1, _080AA924 @ =0xFFFFD000
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _080AA928 @ =0x0836C38C
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	asrs r0, r0, #8
	strb r0, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r1, _080AA92C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl FUN_080aa930
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA91C: .4byte 0x0836C35C
_080AA920: .4byte 0x0836C36C
_080AA924: .4byte 0xFFFFD000
_080AA928: .4byte 0x0836C38C
_080AA92C: .4byte gProjectileFnTable

	thumb_func_start FUN_080aa930
FUN_080aa930: @ 0x080AA930
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r7, #0x60]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	asrs r0, r0, #8
	strb r0, [r7, #0x13]
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, [r7, #0x60]
	adds r1, r1, r2
	str r1, [r7, #0x58]
	adds r2, #0x40
	str r2, [r7, #0x60]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AAA2A
	movs r2, #0x54
	adds r2, r2, r7
	mov sl, r2
	ldr r0, _080AAA3C @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r6, _080AAA40 @ =0x000343FD
	adds r3, r0, #0
	muls r3, r6, r3
	ldr r5, _080AAA44 @ =0x00269EC3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r4, r2, #0
	orrs r3, r4
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r1, _080AAA48 @ =0x000003FF
	mov sb, r1
	mov r2, sb
	ands r0, r2
	adds r0, r0, r4
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	mov r1, r8
	ldr r0, [r1]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r2, #0xff
	ands r3, r2
	adds r3, r3, r4
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	adds r0, r0, r4
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r1, _080AAA4C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080AAA2A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAA3C: .4byte RNG_0202f388
_080AAA40: .4byte 0x000343FD
_080AAA44: .4byte 0x00269EC3
_080AAA48: .4byte 0x000003FF
_080AAA4C: .4byte gProjectileFnTable
_080AAA50:
	.byte 0x02, 0x1C, 0x8C, 0x30, 0x00, 0x21, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70
	.byte 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x04, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18
	.byte 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x70, 0x47, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080aaa80
FUN_080aaa80: @ 0x080AAA80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080AAAA0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	bne _080AAAA4
	movs r0, #0
	b _080AAAD6
	.align 2, 0
_080AAAA0: .4byte gProjectileHeaderPtr
_080AAAA4:
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAADC @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r0, r3, #0
_080AAAD6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AAADC: .4byte gProjectileFnTable

	thumb_func_start blizzack_080aaae0
blizzack_080aaae0: @ 0x080AAAE0
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080AAB30 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAB28
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAB34 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
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
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080AAB28:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AAB30: .4byte gProjectileHeaderPtr
_080AAB34: .4byte gProjectileFnTable

	thumb_func_start FUN_080aab38
FUN_080aab38: @ 0x080AAB38
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080AAB90 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AABCE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAB94 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	str r5, [r3, #0x28]
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080AAB80
	movs r1, #1
_080AAB80:
	adds r2, r1, #0
	cmp r2, #0
	beq _080AAB98
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAB9E
	.align 2, 0
_080AAB90: .4byte gProjectileHeaderPtr
_080AAB94: .4byte gProjectileFnTable
_080AAB98:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAB9E:
	strb r0, [r3, #0xa]
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r3, #0x58]
_080AABCE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aabd4
FUN_080aabd4: @ 0x080AABD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AAC20 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAC18
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAC24 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080AAC18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AAC20: .4byte gProjectileHeaderPtr
_080AAC24: .4byte gProjectileFnTable

	thumb_func_start FUN_080aac28
FUN_080aac28: @ 0x080AAC28
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AAC74 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAC6C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAC78 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #4
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080AAC6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AAC74: .4byte gProjectileHeaderPtr
_080AAC78: .4byte gProjectileFnTable

	thumb_func_start FUN_080aac7c
FUN_080aac7c: @ 0x080AAC7C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AACD4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAD06
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AACD8 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #5
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r2, r4, #0
	cmp r2, #0
	beq _080AACDC
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AACE2
	.align 2, 0
_080AACD4: .4byte gProjectileHeaderPtr
_080AACD8: .4byte gProjectileFnTable
_080AACDC:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AACE2:
	strb r0, [r3, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	str r6, [r3, #0x28]
_080AAD06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aad0c
FUN_080aad0c: @ 0x080AAD0C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AAD64 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAD9A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAD68 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #6
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r2, r4, #0
	cmp r2, #0
	beq _080AAD6C
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAD72
	.align 2, 0
_080AAD64: .4byte gProjectileHeaderPtr
_080AAD68: .4byte gProjectileFnTable
_080AAD6C:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAD72:
	strb r0, [r3, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	str r6, [r3, #0x28]
	ldr r0, [r6, #0x28]
	str r0, [r3, #0x2c]
_080AAD9A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aada0
FUN_080aada0: @ 0x080AADA0
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080AADFC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAE2C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAE00 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #7
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080AAE04
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAE0A
	.align 2, 0
_080AADFC: .4byte gProjectileHeaderPtr
_080AAE00: .4byte gProjectileFnTable
_080AAE04:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAE0A:
	strb r0, [r3, #0xa]
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	str r4, [r3, #0x28]
_080AAE2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080aae34
FUN_080aae34: @ 0x080AAE34
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AAE4C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	bne _080AAE50
	movs r0, #0
	b _080AAE7A
	.align 2, 0
_080AAE4C: .4byte gProjectileHeaderPtr
_080AAE50:
	adds r0, r4, #0
	adds r0, #0x25
	movs r3, #0
	movs r2, #8
	strb r2, [r0]
	ldr r0, _080AAE80 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r4, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r2, [r4, #0x10]
	strb r0, [r4, #0x11]
	str r5, [r4, #0x28]
	adds r0, r4, #0
_080AAE7A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AAE80: .4byte gProjectileFnTable

	thumb_func_start FUN_080aae84
FUN_080aae84: @ 0x080AAE84
	push {lr}
	ldr r2, _080AAE98 @ =0x0836C3C0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AAE98: .4byte 0x0836C3C0

	thumb_func_start FUN_080aae9c
FUN_080aae9c: @ 0x080AAE9C
	push {lr}
	ldr r2, _080AAEB0 @ =0x0836C3E4
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AAEB0: .4byte 0x0836C3E4

	thumb_func_start FUN_080aaeb4
FUN_080aaeb4: @ 0x080AAEB4
	push {lr}
	ldr r2, _080AAEC8 @ =0x0836C408
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AAEC8: .4byte 0x0836C408

	thumb_func_start nop_080aaecc
nop_080aaecc: @ 0x080AAECC
	bx lr
	.align 2, 0

	thumb_func_start nop_080aaed0
nop_080aaed0: @ 0x080AAED0
	bx lr
	.align 2, 0

	thumb_func_start nop_080aaed4
nop_080aaed4: @ 0x080AAED4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080aaed8
FUN_080aaed8: @ 0x080AAED8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r6, [r7, #0x28]
	ldr r1, _080AAF4C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	mov sb, r1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r5, #0
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080AAF50 @ =0x00006208
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080AAF54 @ =0x0836C42C
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r7, [r4, #0x2c]
	mov r0, r8
	str r0, [r4, #0x24]
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	mov r1, sb
	ands r2, r1
	cmp r2, #0
	beq _080AAF58
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAF5E
	.align 2, 0
_080AAF4C: .4byte gProjectileFnTable
_080AAF50: .4byte 0x00006208
_080AAF54: .4byte 0x0836C42C
_080AAF58:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAF5E:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	str r0, [r7, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080AAFAC @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xb8
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	str r0, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AAFB0
	ldrb r0, [r7, #0x11]
	cmp r0, #0x80
	bhi _080AAFC2
	cmp r0, #0x4f
	bhi _080AAFC6
	movs r0, #0x50
	b _080AAFC4
	.align 2, 0
_080AAFAC: .4byte 0xFFFFF000
_080AAFB0:
	ldrb r0, [r7, #0x11]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0xc0
	bls _080AAFBE
	movs r0, #0xc0
	b _080AAFC4
_080AAFBE:
	cmp r1, #0
	blt _080AAFC6
_080AAFC2:
	movs r0, #0x80
_080AAFC4:
	strb r0, [r7, #0x11]
_080AAFC6:
	ldr r3, _080AB000 @ =gSineTable
	ldrb r0, [r7, #0x11]
	adds r1, r0, #0
	adds r1, #0xc0
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r2, #2
	adds r0, r0, r2
	str r0, [r7, #0x5c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl FUN_080aae9c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB000: .4byte gSineTable

	thumb_func_start FUN_080ab004
FUN_080ab004: @ 0x080AB004
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	bl UpdateMotionGraphic
	ldrb r4, [r7, #0xd]
	cmp r4, #0
	bne _080AB088
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, [r7, #0x60]
	adds r1, r1, r2
	str r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AB036
	b _080AB154
_080AB036:
	adds r0, r7, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r1, [r7, #0x58]
	ldr r0, [r0]
	cmp r1, r0
	bge _080AB080
	ldr r1, _080AB07C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _080AB154
	.align 2, 0
_080AB07C: .4byte gProjectileFnTable
_080AB080:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080AB154
_080AB088:
	ldrb r0, [r7, #0x12]
	movs r4, #7
	ands r4, r0
	cmp r4, #0
	bne _080AB12C
	ldr r0, [r7, #0x54]
	str r0, [sp, #4]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [sp, #8]
	movs r3, #0x80
	lsls r3, r3, #1
	str r4, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #0
	bl CreateVFX57
	ldr r3, _080AB164 @ =0xFFFFFF00
	str r4, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #0
	bl CreateVFX57
	ldr r6, _080AB168 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080AB16C @ =0x000343FD
	adds r3, r0, #0
	muls r3, r5, r3
	ldr r4, _080AB170 @ =0x00269EC3
	adds r3, r3, r4
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x3f
	mov r8, r1
	mov r1, r8
	ands r3, r1
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	mov sb, r1
	mov r1, sb
	ands r0, r1
	rsbs r0, r0, #0
	str r0, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r6]
	adds r3, r0, #0
	muls r3, r5, r3
	adds r3, r3, r4
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	mov r1, r8
	ands r3, r1
	rsbs r3, r3, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	rsbs r0, r0, #0
	str r0, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #1
	bl CreateVFX57
_080AB12C:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080AB154
	ldr r1, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080aab38
	ldr r1, _080AB174 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080AB154:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB164: .4byte 0xFFFFFF00
_080AB168: .4byte RNG_0202f388
_080AB16C: .4byte 0x000343FD
_080AB170: .4byte 0x00269EC3
_080AB174: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab178
FUN_080ab178: @ 0x080AB178
	ldr r2, _080AB18C @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080AB18C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab190
FUN_080ab190: @ 0x080AB190
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldr r1, _080AB210 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AB214 @ =0x00006201
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080AB218 @ =0x0836C45C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #6
	bl InitBody
	str r4, [r5, #0x2c]
	mov r0, r8
	str r0, [r5, #0x24]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #9
	strb r0, [r1]
	movs r0, #0x30
	strb r0, [r4, #0x12]
	adds r6, #0xc6
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	adds r0, r4, #0
	bl FUN_080aae9c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AB210: .4byte gProjectileFnTable
_080AB214: .4byte 0x00006201
_080AB218: .4byte 0x0836C45C

	thumb_func_start FUN_080ab21c
FUN_080ab21c: @ 0x080AB21C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x8c
	ldr r6, [r7]
	movs r1, #0x80
	lsls r1, r1, #2
	mov sb, r1
	ands r6, r1
	cmp r6, #0
	bne _080AB2DA
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r4, [r5, #0xd]
	cmp r4, #1
	beq _080AB2C4
	cmp r4, #1
	bgt _080AB252
	cmp r4, #0
	beq _080AB258
	b _080AB39A
_080AB252:
	cmp r4, #2
	beq _080AB300
	b _080AB39A
_080AB258:
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080AB298
	adds r0, r5, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldr r4, [r0, #0x2c]
	adds r0, r5, #0
	bl FUN_080aae34
	str r0, [r5, #0x2c]
	mov r1, r8
	adds r1, #0xc5
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	strb r0, [r5, #0xd]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [r5, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r5, #0x58]
	movs r0, #0x40
	bl PlaySound
	b _080AB39A
_080AB298:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080AB39A
	movs r0, #1
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080AB2C0 @ =0x0836C48C
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	mov r1, sb
	strh r1, [r0]
	b _080AB39A
	.align 2, 0
_080AB2C0: .4byte 0x0836C48C
_080AB2C4:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _080AB39A
_080AB2DA:
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080AB2FC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080ab3ac
	b _080AB39A
	.align 2, 0
_080AB2FC: .4byte gProjectileFnTable
_080AB300:
	ldr r2, [r7]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r2, r0
	cmp r2, #0
	beq _080AB370
	adds r0, r5, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldr r4, [r0, #0x2c]
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080AB354
	ldr r0, _080AB36C @ =0x00000143
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r4, #0x58]
	add r1, sb
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _080AB33E
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080AB33E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AB39A
_080AB354:
	str r6, [r7]
	adds r0, r5, #0
	adds r0, #0x90
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _080AB39A
	.align 2, 0
_080AB36C: .4byte 0x00000143
_080AB370:
	movs r1, #1
	strb r1, [r5, #0x11]
	ldr r0, [r5, #0x2c]
	strb r1, [r0, #0x11]
	mov r0, r8
	adds r0, #0xc5
	strb r2, [r0]
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080AB3A8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080ab3ac
_080AB39A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB3A8: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab3ac
FUN_080ab3ac: @ 0x080AB3AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [sp, #4]
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	beq _080AB3C6
	b _080AB4F2
_080AB3C6:
	movs r1, #0x54
	adds r1, r1, r7
	mov sl, r1
	ldr r4, _080AB53C @ =RNG_0202f388
	ldr r0, [r4]
	ldr r6, _080AB540 @ =0x000343FD
	muls r0, r6, r0
	ldr r5, _080AB544 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AB548 @ =0x000003FF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x7f
	mov sb, r1
	mov r1, sb
	ands r3, r1
	adds r3, #0x80
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AB548 @ =0x000003FF
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #2
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	mov r1, r8
	orrs r3, r1
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AB548 @ =0x000003FF
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	mov r1, sb
	ands r3, r1
	adds r3, #0x80
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AB548 @ =0x000003FF
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	add r3, r8
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AB548 @ =0x000003FF
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
_080AB4F2:
	ldr r2, [sp, #4]
	adds r2, #0xc6
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080AB54C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB53C: .4byte RNG_0202f388
_080AB540: .4byte 0x000343FD
_080AB544: .4byte 0x00269EC3
_080AB548: .4byte 0x000003FF
_080AB54C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab550
FUN_080ab550: @ 0x080AB550
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldr r2, _080AB598 @ =gVideoRegBuffer
	ldrh r1, [r2]
	movs r3, #0x90
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080AB59C @ =FUN_080ac1e4
	bl SetTaskCallback
	str r5, [r5, #0x3c]
	ldrb r0, [r5, #0xa]
	movs r2, #0xf7
	ands r2, r0
	movs r0, #1
	movs r3, #0
	orrs r2, r0
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r5, #0xa]
	ldrb r0, [r4, #0xa]
	lsrs r1, r0, #4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080AB5A0
	movs r0, #0x10
	orrs r2, r0
	b _080AB5A4
	.align 2, 0
_080AB598: .4byte gVideoRegBuffer
_080AB59C: .4byte FUN_080ac1e4
_080AB5A0:
	movs r0, #0xef
	ands r2, r0
_080AB5A4:
	strb r2, [r5, #0xa]
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
	ldr r1, _080AB5FC @ =gBlendRegBuffer
	ldr r0, _080AB600 @ =0x00003F44
	strh r0, [r1]
	ldr r0, _080AB604 @ =0x00001008
	strh r0, [r1, #2]
	ldr r1, _080AB608 @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r1, #0xe]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AB60C
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #2
	rsbs r0, r0, #0
	b _080AB616
	.align 2, 0
_080AB5FC: .4byte gBlendRegBuffer
_080AB600: .4byte 0x00003F44
_080AB604: .4byte 0x00001008
_080AB608: .4byte gWindowRegBuffer
_080AB60C:
	ldr r0, [r5, #0x54]
	ldr r3, _080AB65C @ =0xFFFFE200
	adds r0, r0, r3
	str r0, [r5, #0x54]
	movs r0, #2
_080AB616:
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r1, _080AB660 @ =0xFFFFDA00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	movs r0, #0x44
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0xc0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080aada0
	ldr r1, _080AB664 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080aae9c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AB65C: .4byte 0xFFFFE200
_080AB660: .4byte 0xFFFFDA00
_080AB664: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab668
FUN_080ab668: @ 0x080AB668
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, [r4, #0x5c]
	ldrb r0, [r4, #0x13]
	adds r0, r0, r1
	strb r0, [r4, #0x13]
	ldrb r1, [r4, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080AB6D4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r3, r1, #0
	cmp r0, #0
	beq _080AB696
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	b _080AB69A
_080AB696:
	ldr r0, [r4, #0x54]
	ldr r1, _080AB710 @ =0xFFFFF000
_080AB69A:
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, _080AB714 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080AB718 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080AB71C @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	lsls r1, r1, #8
	ldr r0, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp, #4]
	lsls r1, r3, #0x18
	lsrs r1, r1, #0x1c
	movs r0, #1
	ands r1, r0
	mov r0, sp
	adds r2, r4, #0
	bl FUN_080aad0c
_080AB6D4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080AB6EE
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bhi _080AB6EE
	ldrb r0, [r5, #0xd]
	cmp r0, #0x13
	bne _080AB706
_080AB6EE:
	ldr r1, _080AB720 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080aaeb4
_080AB706:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AB710: .4byte 0xFFFFF000
_080AB714: .4byte RNG_0202f388
_080AB718: .4byte 0x000343FD
_080AB71C: .4byte 0x00269EC3
_080AB720: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab724
FUN_080ab724: @ 0x080AB724
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080AB770 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080AB774 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080AB778 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _080AB77C @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfe
	orrs r0, r2
	strb r0, [r1, #0xe]
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl stopSound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AB780 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB770: .4byte gVideoRegBuffer
_080AB774: .4byte 0x0000DBFF
_080AB778: .4byte gWindowRegBuffer
_080AB77C: .4byte 0x0000BFFF
_080AB780: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab784
FUN_080ab784: @ 0x080AB784
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldr r2, _080AB7CC @ =gVideoRegBuffer
	ldrh r1, [r2]
	movs r3, #0x90
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080AB7D0 @ =FUN_080ac1e4
	bl SetTaskCallback
	str r5, [r5, #0x3c]
	ldrb r0, [r5, #0xa]
	movs r2, #0xf7
	ands r2, r0
	movs r0, #1
	movs r3, #0
	orrs r2, r0
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r5, #0xa]
	ldrb r0, [r4, #0xa]
	lsrs r1, r0, #4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080AB7D4
	movs r0, #0x10
	orrs r2, r0
	b _080AB7D8
	.align 2, 0
_080AB7CC: .4byte gVideoRegBuffer
_080AB7D0: .4byte FUN_080ac1e4
_080AB7D4:
	movs r0, #0xef
	ands r2, r0
_080AB7D8:
	strb r2, [r5, #0xa]
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
	ldr r1, _080AB830 @ =gBlendRegBuffer
	ldr r0, _080AB834 @ =0x00003F44
	strh r0, [r1]
	ldr r0, _080AB838 @ =0x00001008
	strh r0, [r1, #2]
	ldr r1, _080AB83C @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r1, #0xe]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AB840
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #3
	rsbs r0, r0, #0
	b _080AB84A
	.align 2, 0
_080AB830: .4byte gBlendRegBuffer
_080AB834: .4byte 0x00003F44
_080AB838: .4byte 0x00001008
_080AB83C: .4byte gWindowRegBuffer
_080AB840:
	ldr r0, [r5, #0x54]
	ldr r3, _080AB8B4 @ =0xFFFFE200
	adds r0, r0, r3
	str r0, [r5, #0x54]
	movs r0, #3
_080AB84A:
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r1, _080AB8B4 @ =0xFFFFE200
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, _080AB8B8 @ =0x0000FFFF
	strh r0, [r4]
	movs r0, #0x44
	bl PlaySound
	strh r0, [r4]
	ldr r2, _080AB8BC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080AB8C0 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _080AB8C4 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r1, r5, #0
	adds r1, #0xc2
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080aada0
	ldr r1, _080AB8C8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080aae9c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AB8B4: .4byte 0xFFFFE200
_080AB8B8: .4byte 0x0000FFFF
_080AB8BC: .4byte RNG_0202f388
_080AB8C0: .4byte 0x000343FD
_080AB8C4: .4byte 0x00269EC3
_080AB8C8: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab8cc
FUN_080ab8cc: @ 0x080AB8CC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r7, [r5, #0x28]
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x5c]
	ldrb r0, [r5, #0x13]
	adds r0, r0, r1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x12]
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AB948
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	beq _080AB902
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	b _080AB906
_080AB902:
	ldr r0, [r5, #0x54]
	ldr r1, _080AB984 @ =0xFFFFF000
_080AB906:
	adds r0, r0, r1
	str r0, [sp]
	ldr r4, _080AB988 @ =0x0836C57C
	ldrb r0, [r5, #0x12]
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r1, r5, #0
	adds r1, #0xc2
	ldrb r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r4
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080AB948
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [sp, #4]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x1c
	movs r0, #1
	ands r1, r0
	mov r0, sp
	adds r2, r5, #0
	bl FUN_080aac7c
_080AB948:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080AB962
	ldrb r0, [r7, #0xc]
	cmp r0, #1
	bhi _080AB962
	ldrb r0, [r7, #0xd]
	cmp r0, #0x13
	bne _080AB97A
_080AB962:
	ldr r1, _080AB98C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080aaeb4
_080AB97A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB984: .4byte 0xFFFFF000
_080AB988: .4byte 0x0836C57C
_080AB98C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab990
FUN_080ab990: @ 0x080AB990
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080AB9DC @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080AB9E0 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080AB9E4 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _080AB9E8 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xfe
	orrs r0, r2
	strb r0, [r1, #0xe]
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl stopSound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AB9EC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB9DC: .4byte gVideoRegBuffer
_080AB9E0: .4byte 0x0000DBFF
_080AB9E4: .4byte gWindowRegBuffer
_080AB9E8: .4byte 0x0000BFFF
_080AB9EC: .4byte gProjectileFnTable

	thumb_func_start FUN_080ab9f0
FUN_080ab9f0: @ 0x080AB9F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080ABA54 @ =0x00006202
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080ABA58 @ =0x0836C4EC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	movs r0, #0xa0
	str r0, [r4, #0x5c]
	ldr r1, _080ABA5C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080aae9c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABA54: .4byte 0x00006202
_080ABA58: .4byte 0x0836C4EC
_080ABA5C: .4byte gProjectileFnTable

	thumb_func_start FUN_080aba60
FUN_080aba60: @ 0x080ABA60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xd]
	cmp r1, #0
	bne _080ABAA6
	ldr r0, [r4, #0x5c]
	adds r0, #0x10
	str r0, [r4, #0x5c]
	movs r2, #0xa0
	lsls r2, r2, #2
	cmp r0, r2
	ble _080ABA80
	str r2, [r4, #0x5c]
_080ABA80:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080ABAE0
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080ABAE0
_080ABAA6:
	ldrb r1, [r4, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bls _080ABABA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABAC0
_080ABABA:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
_080ABAC0:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bls _080ABAE0
	ldr r1, _080ABAF4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABAE0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABAF8
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	b _080ABAFE
	.align 2, 0
_080ABAF4: .4byte gProjectileFnTable
_080ABAF8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
_080ABAFE:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080ABB20
	ldr r1, _080ABB28 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABB20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB28: .4byte gProjectileFnTable

	thumb_func_start FUN_080abb2c
FUN_080abb2c: @ 0x080ABB2C
	ldr r2, _080ABB40 @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080ABB40: .4byte gProjectileFnTable

	thumb_func_start FUN_080abb44
FUN_080abb44: @ 0x080ABB44
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080ABBAC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080ABBB0 @ =0x00006207
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080ABBB4 @ =0x0836C51C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	movs r0, #0x80
	str r0, [r4, #0x5c]
	str r6, [r4, #0x60]
	strb r6, [r4, #0x12]
	strb r6, [r4, #0x13]
	adds r0, r4, #0
	bl FUN_080aae9c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBAC: .4byte gProjectileFnTable
_080ABBB0: .4byte 0x00006207
_080ABBB4: .4byte 0x0836C51C

	thumb_func_start FUN_080abbb8
FUN_080abbb8: @ 0x080ABBB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x28]
	bl UpdateMotionGraphic
	ldrb r6, [r7, #0xd]
	cmp r6, #1
	beq _080ABCA0
	cmp r6, #1
	bgt _080ABBDA
	cmp r6, #0
	beq _080ABBE2
	b _080ABD76
_080ABBDA:
	cmp r6, #2
	bne _080ABBE0
	b _080ABCE0
_080ABBE0:
	b _080ABD76
_080ABBE2:
	ldr r0, [r7, #0x5c]
	adds r0, #0x10
	str r0, [r7, #0x5c]
	movs r1, #0xa0
	lsls r1, r1, #2
	cmp r0, r1
	ble _080ABBF2
	str r1, [r7, #0x5c]
_080ABBF2:
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _080ABC12
	adds r0, r7, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #1
	b _080ABD74
_080ABC12:
	movs r0, #0x8c
	adds r0, r0, r7
	mov sl, r0
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080ABC24
	b _080ABD76
_080ABC24:
	ldr r4, _080ABC90 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080ABC94 @ =0x000343FD
	mov r8, r1
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r1, _080ABC98 @ =0x00269EC3
	mov sb, r1
	add r0, sb
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xe
	bl __umodsi3
	subs r0, #7
	lsls r0, r0, #8
	str r0, [r7, #0x64]
	mov r0, r8
	muls r0, r5, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #4
	lsls r0, r0, #8
	str r0, [r7, #0x68]
	ldr r0, _080ABC9C @ =pZero2
	ldr r0, [r0]
	cmp r0, #0
	beq _080ABC74
	movs r1, #8
	bl makeZeroSlower
_080ABC74:
	mov r3, sl
	str r6, [r3]
	adds r0, r7, #0
	adds r0, #0x90
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #2
	b _080ABD74
	.align 2, 0
_080ABC90: .4byte RNG_0202f388
_080ABC94: .4byte 0x000343FD
_080ABC98: .4byte 0x00269EC3
_080ABC9C: .4byte pZero2
_080ABCA0:
	ldrb r1, [r7, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bls _080ABCB4
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABCBA
_080ABCB4:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
_080ABCBA:
	strb r0, [r7, #0xa]
	adds r0, r2, #1
	strb r0, [r7, #0x12]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bls _080ABD76
	ldr r1, _080ABCDC @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080ABD76
	.align 2, 0
_080ABCDC: .4byte gProjectileFnTable
_080ABCE0:
	ldr r0, _080ABCF4 @ =pZero2
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	bne _080ABCF8
	str r2, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	b _080ABD72
	.align 2, 0
_080ABCF4: .4byte pZero2
_080ABCF8:
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080ABD14
	adds r0, r2, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _080ABD1C
_080ABD14:
	movs r0, #0
	str r0, [r7, #0x5c]
	str r1, [r7, #0x60]
	b _080ABD72
_080ABD1C:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABD2E
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x64]
	adds r0, r0, r1
	b _080ABD34
_080ABD2E:
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x64]
	subs r0, r0, r1
_080ABD34:
	str r0, [r7, #0x54]
	ldr r0, [r4]
	ldr r1, [r0, #0x58]
	ldr r2, [r7, #0x68]
	subs r1, r1, r2
	str r1, [r7, #0x58]
	bl CountButtonMashing
	ldrb r1, [r7, #0x12]
	adds r0, r0, r1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bhi _080ABD60
	ldrb r0, [r7, #0x13]
	adds r1, r0, #1
	strb r1, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf0
	bls _080ABD76
_080ABD60:
	movs r0, #0
	str r0, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	ldr r0, [r4]
	movs r1, #8
	bl makeZeroFaster
_080ABD72:
	movs r0, #3
_080ABD74:
	strb r0, [r7, #0xd]
_080ABD76:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABD88
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	b _080ABD8E
_080ABD88:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
_080ABD8E:
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, [r7, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080ABDB6
	ldr r1, _080ABDC4 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080ABDB6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABDC4: .4byte gProjectileFnTable

	thumb_func_start FUN_080abdc8
FUN_080abdc8: @ 0x080ABDC8
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080ABDF4 @ =gProjectileFnTable
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
_080ABDF4: .4byte gProjectileFnTable

	thumb_func_start FUN_080abdf8
FUN_080abdf8: @ 0x080ABDF8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080ABE48 @ =0x0836C4BC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080ABE4C @ =FUN_080ac1a4
	str r0, [r5, #0x24]
	ldr r1, _080ABE50 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080aae9c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABE48: .4byte 0x0836C4BC
_080ABE4C: .4byte FUN_080ac1a4
_080ABE50: .4byte gProjectileFnTable

	thumb_func_start FUN_080abe54
FUN_080abe54: @ 0x080ABE54
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldr r0, _080ABE78 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r0, #0x54]
	str r2, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABE7C
	ldr r0, [r5, #0x54]
	cmp r2, r0
	bge _080ABE84
	b _080ABE82
	.align 2, 0
_080ABE78: .4byte pZero2
_080ABE7C:
	ldr r0, [r5, #0x54]
	cmp r2, r0
	ble _080ABE84
_080ABE82:
	str r0, [r4, #0x54]
_080ABE84:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080ABE9C
	ldr r1, _080ABEA4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABE9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABEA4: .4byte gProjectileFnTable

	thumb_func_start FUN_080abea8
FUN_080abea8: @ 0x080ABEA8
	ldr r2, _080ABEBC @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080ABEBC: .4byte gProjectileFnTable

	thumb_func_start FUN_080abec0
FUN_080abec0: @ 0x080ABEC0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xc4
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080ABF00 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080ABF04
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080ABF0A
	.align 2, 0
_080ABF00: .4byte pZero2
_080ABF04:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080ABF0A:
	strb r0, [r5, #0xa]
	movs r4, #1
	adds r1, r4, #0
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	strb r3, [r5, #0x11]
	ldr r1, _080ABF50 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080aae9c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABF50: .4byte gProjectileFnTable

	thumb_func_start FUN_080abf54
FUN_080abf54: @ 0x080ABF54
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080ABF72
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABF78
_080ABF72:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080ABF78:
	strb r0, [r4, #0xa]
	ldr r0, _080ABFB0 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _080ABFB4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080ABFA8
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080ABFB8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABFA8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ABFB0: .4byte pZero2
_080ABFB4: .4byte 0xFFFFF800
_080ABFB8: .4byte gProjectileFnTable

	thumb_func_start FUN_080abfbc
FUN_080abfbc: @ 0x080ABFBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x54
	adds r0, r0, r7
	mov sl, r0
	ldr r4, _080AC190 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r6, _080AC194 @ =0x000343FD
	muls r0, r6, r0
	ldr r5, _080AC198 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AC19C @ =0x000003FF
	mov sb, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x7f
	ands r3, r1
	adds r3, #0x80
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #2
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	mov r1, r8
	orrs r3, r1
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	mov r1, r8
	orrs r3, r1
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x7f
	ands r3, r1
	adds r3, #0x80
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	add r3, r8
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	add r3, r8
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r1, _080AC1A0 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC190: .4byte RNG_0202f388
_080AC194: .4byte 0x000343FD
_080AC198: .4byte 0x00269EC3
_080AC19C: .4byte 0x000003FF
_080AC1A0: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac1a4
FUN_080ac1a4: @ 0x080AC1A4
	push {lr}
	ldr r1, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r2, [r0, #0x2c]
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _080AC1E0
	ldrb r0, [r1, #0x11]
	movs r3, #0xa0
	lsls r3, r3, #2
	cmp r0, #0
	bne _080AC1C2
	movs r3, #0xc0
	lsls r3, r3, #1
_080AC1C2:
	ldrb r1, [r1, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AC1D6
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r2, r1
	str r3, [r0]
	b _080AC1E0
_080AC1D6:
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r1, r2, r0
	rsbs r0, r3, #0
	str r0, [r1]
_080AC1E0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac1e4
FUN_080ac1e4: @ 0x080AC1E4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x58
	adds r1, #8
	mov ip, r1
	ldr r5, [r0, #8]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AC1F6
	b _080AC36E
_080AC1F6:
	ldr r0, [r5, #0x58]
	ldr r1, [r1, #4]
	subs r0, r0, r1
	asrs r6, r0, #8
	ldrb r0, [r5, #0x12]
	cmp r0, #0x13
	bls _080AC218
	cmp r0, #0x9f
	bhi _080AC212
	adds r3, r6, #0
	subs r3, #0x28
	adds r2, r6, #0
	adds r2, #0x28
	b _080AC21E
_080AC212:
	ldrb r1, [r5, #0x12]
	movs r0, #0xb5
	subs r0, r0, r1
_080AC218:
	lsls r0, r0, #1
	subs r3, r6, r0
	adds r2, r6, r0
_080AC21E:
	cmp r3, #0x9f
	ble _080AC238
	ldr r2, _080AC230 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080AC234 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r2]
	b _080AC36E
	.align 2, 0
_080AC230: .4byte gVideoRegBuffer
_080AC234: .4byte 0x0000DBFF
_080AC238:
	ldr r7, _080AC29C @ =gVideoRegBuffer
	ldrh r1, [r7]
	movs r4, #0x90
	lsls r4, r4, #6
	adds r0, r4, #0
	adds r4, r0, #0
	orrs r4, r1
	strh r4, [r7]
	cmp r3, #0
	bge _080AC24E
	movs r3, #0
_080AC24E:
	cmp r2, #0x9f
	ble _080AC254
	movs r2, #0x9f
_080AC254:
	ldr r1, _080AC2A0 @ =gWindowRegBuffer
	movs r0, #0xff
	ands r2, r0
	lsls r0, r3, #8
	orrs r2, r0
	strh r2, [r1, #0xa]
	mov r0, ip
	ldr r2, [r0]
	asrs r0, r2, #8
	ldrb r1, [r5, #0x13]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r0, #0x28
	subs r0, r0, r6
	strh r0, [r7, #0x16]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AC2BA
	ldr r0, [r5, #0x54]
	subs r0, r0, r2
	asrs r1, r0, #8
	cmp r1, #0xf0
	bgt _080AC2C4
	movs r2, #0
	movs r4, #0xf0
	mov r3, sp
_080AC28C:
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r0, r0, #5
	adds r0, r1, r0
	cmp r0, #0
	bge _080AC2A4
	movs r0, #0
	b _080AC2AA
	.align 2, 0
_080AC29C: .4byte gVideoRegBuffer
_080AC2A0: .4byte gWindowRegBuffer
_080AC2A4:
	cmp r0, #0xf0
	ble _080AC2AA
	movs r0, #0xf0
_080AC2AA:
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	ble _080AC28C
	b _080AC2F4
_080AC2BA:
	ldr r0, [r5, #0x54]
	subs r0, r0, r2
	asrs r1, r0, #8
	cmp r1, #0
	bge _080AC2D0
_080AC2C4:
	ldr r0, _080AC2CC @ =0x0000DBFF
	ands r4, r0
	strh r4, [r7]
	b _080AC36E
	.align 2, 0
_080AC2CC: .4byte 0x0000DBFF
_080AC2D0:
	movs r2, #0
	mov r3, sp
_080AC2D4:
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r0, r0, #5
	subs r0, r1, r0
	cmp r0, #0
	bge _080AC2E4
	movs r0, #0
	b _080AC2EA
_080AC2E4:
	cmp r0, #0xf0
	ble _080AC2EA
	movs r0, #0xf0
_080AC2EA:
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	ble _080AC2D4
_080AC2F4:
	movs r0, #0xa0
	lsls r0, r0, #1
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC36E
	movs r0, #0
	str r0, [sp, #0x50]
	add r0, sp, #0x50
	ldr r2, _080AC378 @ =0x01000050
	adds r1, r4, #0
	bl CpuFastSet
	movs r2, #0
	adds r0, r6, #0
	cmp r0, #0
	blt _080AC330
	mov r3, sp
_080AC31A:
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	bgt _080AC330
	subs r0, r6, r2
	cmp r0, #0
	bge _080AC31A
_080AC330:
	movs r2, #0
	adds r0, r6, #0
	ldr r5, _080AC37C @ =gIntrManager
	cmp r0, #0xf0
	bgt _080AC352
	mov r3, sp
_080AC33C:
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	bgt _080AC352
	adds r0, r6, r2
	cmp r0, #0xf0
	ble _080AC33C
_080AC352:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r5, r2
	str r4, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, _080AC380 @ =0x04000042
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _080AC384 @ =0xA2600001
	str r0, [r1]
_080AC36E:
	add sp, #0x58
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC378: .4byte 0x01000050
_080AC37C: .4byte gIntrManager
_080AC380: .4byte 0x04000042
_080AC384: .4byte 0xA2600001

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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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

	thumb_func_start initGoldOmega1Atk
initGoldOmega1Atk: @ 0x080AC448
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
	bl FUN_080ac508
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AC4FC: .4byte 0x0836C614
_080AC500: .4byte 0xFFFFFF00
_080AC504: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac508
FUN_080ac508: @ 0x080AC508
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

	thumb_func_start FUN_080ac520
FUN_080ac520: @ 0x080AC520
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

	thumb_func_start doGoldOmega1Laser1
doGoldOmega1Laser1: @ 0x080AC55C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AC58C
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080AC588 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080AC5D4
	.align 2, 0
_080AC588: .4byte gProjectileFnTable
_080AC58C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080AC598
	cmp r0, #1
	beq _080AC5A6
	b _080AC5BA
_080AC598:
	ldr r1, _080AC5DC @ =0x00000A06
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AC5A6:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _080AC5E0 @ =0xFFFF9A00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080AC5BA:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	beq _080AC5CC
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _080AC5D4
_080AC5CC:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080AC5D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC5DC: .4byte 0x00000A06
_080AC5E0: .4byte 0xFFFF9A00

	thumb_func_start doGoldOmega1Laser2
doGoldOmega1Laser2: @ 0x080AC5E4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080AC5FC
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AC620
_080AC5FC:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080AC61C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080AC6EC
	.align 2, 0
_080AC61C: .4byte gProjectileFnTable
_080AC620:
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	beq _080AC62C
	cmp r2, #1
	beq _080AC696
	b _080AC6EC
_080AC62C:
	adds r4, r5, #0
	adds r4, #0xb8
	ldr r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	lsrs r0, r0, #8
	str r0, [r4]
	strb r2, [r5, #0x13]
	ldr r1, _080AC6F4 @ =0x00000A07
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080AC6F8 @ =0x0836C65C
	bl SetDDP
	ldr r3, _080AC6FC @ =gSineTable
	adds r2, r5, #0
	adds r2, #0xb4
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, [r4]
	muls r0, r1, r0
	lsrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	ldrb r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	lsrs r0, r0, #8
	str r0, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080AC696:
	ldrb r0, [r5, #0x13]
	adds r1, r0, #1
	strb r1, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080AC6B2
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080c1b98
_080AC6B2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _080AC6E6
	adds r1, r5, #0
	adds r1, #0xb5
	ldrb r0, [r1]
	cmp r0, #0
	beq _080AC6E6
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5, #0x58]
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x60]
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
_080AC6E6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080AC6EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AC6F4: .4byte 0x00000A07
_080AC6F8: .4byte 0x0836C65C
_080AC6FC: .4byte gSineTable

	thumb_func_start FUN_080ac700
FUN_080ac700: @ 0x080AC700
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080AC736
	movs r1, #0
	str r1, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	b _080AC7E2
_080AC736:
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080AC742
	cmp r0, #1
	beq _080AC79C
	b _080AC7F4
_080AC742:
	ldr r2, _080AC7FC @ =0x0836C6F4
	ldrb r0, [r7, #0x11]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _080AC800 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080AC804 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080AC808 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldr r2, [r2]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, _080AC80C @ =0x00000C01
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080AC79C:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x32
	bne _080AC7AC
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080AC810 @ =0x0836C644
	bl SetDDP
_080AC7AC:
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AC7BC
	str r1, [r7, #0x60]
_080AC7BC:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080AC7E2
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AC7F4
_080AC7E2:
	ldr r1, _080AC814 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080AC7F4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC7FC: .4byte 0x0836C6F4
_080AC800: .4byte RNG_0202f388
_080AC804: .4byte 0x000343FD
_080AC808: .4byte 0x00269EC3
_080AC80C: .4byte 0x00000C01
_080AC810: .4byte 0x0836C644
_080AC814: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac818
FUN_080ac818: @ 0x080AC818
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AC878 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	mov ip, r0
	cmp r0, #0
	beq _080AC86E
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC87C @ =gProjectileFnTable
	movs r1, #0x22
	mov r2, ip
	strb r1, [r2, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x20]
	adds r0, #0x22
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r2, [r3, #0x10]
	strb r2, [r3, #0x11]
	mov r0, ip
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC86E:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC878: .4byte gProjectileHeaderPtr
_080AC87C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac880
FUN_080ac880: @ 0x080AC880
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AC8E0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	mov ip, r0
	cmp r0, #0
	beq _080AC8D8
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC8E4 @ =gProjectileFnTable
	movs r1, #0x22
	mov r2, ip
	strb r1, [r2, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x20]
	adds r0, #0x22
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r2, [r3, #0x11]
	mov r0, ip
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC8D8:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC8E0: .4byte gProjectileHeaderPtr
_080AC8E4: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac8e8
FUN_080ac8e8: @ 0x080AC8E8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AC948 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	mov ip, r0
	cmp r0, #0
	beq _080AC940
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC94C @ =gProjectileFnTable
	movs r1, #0x22
	mov r2, ip
	strb r1, [r2, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x20]
	adds r0, #0x22
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r2, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
	mov r0, ip
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC940:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC948: .4byte gProjectileHeaderPtr
_080AC94C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac950
FUN_080ac950: @ 0x080AC950
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AC9AC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AC9A4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC9B0 @ =gProjectileFnTable
	movs r1, #0x22
	strb r1, [r3, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r0, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC9A4:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC9AC: .4byte gProjectileHeaderPtr
_080AC9B0: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac9b4
FUN_080ac9b4: @ 0x080AC9B4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080ACA10 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080ACA06
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080ACA14 @ =gProjectileFnTable
	movs r1, #0x22
	strb r1, [r3, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #2
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080ACA06:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACA10: .4byte gProjectileHeaderPtr
_080ACA14: .4byte gProjectileFnTable

	thumb_func_start FUN_080aca18
FUN_080aca18: @ 0x080ACA18
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r2, #0
	movs r6, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	orrs r1, r2
	strb r1, [r5, #0xa]
	ldrb r7, [r5, #0x10]
	cmp r7, #2
	bne _080ACA74
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080ACA6C @ =0x0836C728
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080ACA70 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r7, [r5, #0xd]
	b _080ACAE6
	.align 2, 0
_080ACA6C: .4byte 0x0836C728
_080ACA70: .4byte gProjectileFnTable
_080ACA74:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080ACAB4
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080ACAAC @ =0x0836C728
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080ACAB0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r6, [r5, #0xd]
	b _080ACAE6
	.align 2, 0
_080ACAAC: .4byte 0x0836C728
_080ACAB0: .4byte gProjectileFnTable
_080ACAB4:
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080ACAF8 @ =0x0836C728
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080ACAFC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	movs r0, #3
	strb r0, [r5, #0xd]
_080ACAE6:
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
	adds r0, r5, #0
	bl FUN_080acb00
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAF8: .4byte 0x0836C728
_080ACAFC: .4byte gProjectileFnTable

	thumb_func_start FUN_080acb00
FUN_080acb00: @ 0x080ACB00
	push {lr}
	ldr r2, _080ACB14 @ =0x0836C718
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080ACB14: .4byte 0x0836C718
_080ACB18:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40
	.byte 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30
	.byte 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00
	.byte 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x70, 0x47, 0x00, 0x00
	.byte 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080acb54
FUN_080acb54: @ 0x080ACB54
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080ACB84
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080ACB80 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080ACBD4
	.align 2, 0
_080ACB80: .4byte gProjectileFnTable
_080ACB84:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080ACB90
	cmp r0, #1
	beq _080ACBB0
	b _080ACBB6
_080ACB90:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080ACBA2
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	b _080ACBAA
_080ACBA2:
	ldr r1, _080ACBDC @ =0x00000A03
	adds r0, r4, #0
	bl SetMotion
_080ACBAA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ACBB0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080ACBB6:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	beq _080ACBC8
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _080ACBD4
_080ACBC8:
	movs r0, #0
	movs r1, #0x7f
	strb r1, [r4, #0x12]
	movs r1, #1
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_080ACBD4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ACBDC: .4byte 0x00000A03

	thumb_func_start FUN_080acbe0
FUN_080acbe0: @ 0x080ACBE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080ACBF8
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	b _080ACC04
_080ACBF8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ACC1C
_080ACC04:
	ldr r1, _080ACC18 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080ACCEA
	.align 2, 0
_080ACC18: .4byte gProjectileFnTable
_080ACC1C:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080ACC9E
	cmp r5, #1
	bgt _080ACC2C
	cmp r5, #0
	beq _080ACC32
	b _080ACCEA
_080ACC2C:
	cmp r5, #2
	beq _080ACCD4
	b _080ACCEA
_080ACC32:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080ACC60
	ldr r1, _080ACC58 @ =0x00000A01
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080ACC5C @ =0x0836C740
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r4, #0x60]
	str r5, [r4, #0x5c]
	b _080ACC7E
	.align 2, 0
_080ACC58: .4byte 0x00000A01
_080ACC5C: .4byte 0x0836C740
_080ACC60:
	ldr r1, _080ACCC0 @ =0x00000A04
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080ACCC4 @ =0x0836C758
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	str r5, [r4, #0x60]
_080ACC7E:
	ldr r2, _080ACCC8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080ACCCC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080ACCD0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ACC9E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080ACCEA
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080ACCEA
	.align 2, 0
_080ACCC0: .4byte 0x00000A04
_080ACCC4: .4byte 0x0836C758
_080ACCC8: .4byte RNG_0202f388
_080ACCCC: .4byte 0x000343FD
_080ACCD0: .4byte 0x00269EC3
_080ACCD4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080ACCEA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080accf0
FUN_080accf0: @ 0x080ACCF0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080ACD1E
	movs r1, #0
	str r1, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	b _080ACE06
_080ACD1E:
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080ACD44
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080ACD44
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080ACD44
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080ACE06
_080ACD44:
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080ACD50
	cmp r0, #1
	beq _080ACDB8
	b _080ACE78
_080ACD50:
	ldr r2, _080ACE80 @ =0x0836C820
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _080ACE84 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080ACE88 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080ACE8C @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldr r2, [r2]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, _080ACE90 @ =0x00000C01
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080ACE94 @ =0x0836C770
	bl SetDDP
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080ACDB8:
	ldrb r0, [r7, #0x12]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ACDD0
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
_080ACDD0:
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080ACDE0
	str r1, [r7, #0x60]
_080ACDE0:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080ACE06
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ACE78
_080ACE06:
	ldr r0, [r7, #0x54]
	ldr r1, _080ACE98 @ =0xFFFFF700
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r7, #0x58]
	movs r4, #0x90
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [sp]
	ldr r0, [r7, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r4, [r7, #0x54]
	subs r4, #6
	ldr r2, _080ACE84 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080ACE88 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080ACE8C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r4, r4, r0
	str r4, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080ACE98 @ =0xFFFFF700
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r1, _080ACE9C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080ACE78:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACE80: .4byte 0x0836C820
_080ACE84: .4byte RNG_0202f388
_080ACE88: .4byte 0x000343FD
_080ACE8C: .4byte 0x00269EC3
_080ACE90: .4byte 0x00000C01
_080ACE94: .4byte 0x0836C770
_080ACE98: .4byte 0xFFFFF700
_080ACE9C: .4byte gProjectileFnTable

	thumb_func_start FUN_080acea0
FUN_080acea0: @ 0x080ACEA0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080ACEAC
	b _080ACFFA
_080ACEAC:
	lsls r0, r0, #2
	ldr r1, _080ACEB8 @ =_080ACEBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ACEB8: .4byte _080ACEBC
_080ACEBC: @ jump table
	.4byte _080ACED0 @ case 0
	.4byte _080ACF08 @ case 1
	.4byte _080ACF28 @ case 2
	.4byte _080ACF94 @ case 3
	.4byte _080ACFCC @ case 4
_080ACED0:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080ACEFA
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	b _080ACF02
_080ACEFA:
	ldr r1, _080ACF24 @ =0x00000A03
	adds r0, r4, #0
	bl SetMotion
_080ACF02:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ACF08:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	beq _080ACF20
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _080ACFFA
_080ACF20:
	movs r0, #0x7f
	b _080ACFAE
	.align 2, 0
_080ACF24: .4byte 0x00000A03
_080ACF28:
	ldrb r5, [r4, #0x10]
	cmp r5, #0
	bne _080ACF54
	ldr r1, _080ACF4C @ =0x00000A01
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080ACF50 @ =0x0836C740
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r4, #0x60]
	str r5, [r4, #0x5c]
	b _080ACF74
	.align 2, 0
_080ACF4C: .4byte 0x00000A01
_080ACF50: .4byte 0x0836C740
_080ACF54:
	ldr r1, _080ACFB8 @ =0x00000A04
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080ACFBC @ =0x0836C758
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
_080ACF74:
	ldr r2, _080ACFC0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080ACFC4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080ACFC8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ACF94:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080ACFFA
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xff
_080ACFAE:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080ACFFA
	.align 2, 0
_080ACFB8: .4byte 0x00000A04
_080ACFBC: .4byte 0x0836C758
_080ACFC0: .4byte RNG_0202f388
_080ACFC4: .4byte 0x000343FD
_080ACFC8: .4byte 0x00269EC3
_080ACFCC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080ACFFA
	ldr r1, _080AD000 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ACFFA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD000: .4byte gProjectileFnTable

	thumb_func_start createPantheonBomb
createPantheonBomb: @ 0x080AD004
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080AD05C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AD052
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AD060 @ =gProjectileFnTable
	movs r1, #0x23
	strb r1, [r3, #9]
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	ldr r0, [r5]
	str r0, [r3, #0x64]
	ldr r0, [r5, #4]
	str r0, [r3, #0x68]
_080AD052:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AD05C: .4byte gProjectileHeaderPtr
_080AD060: .4byte gProjectileFnTable

	thumb_func_start createPantheonBombBlast
createPantheonBombBlast: @ 0x080AD064
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080AD0B4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AD0AA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AD0B8 @ =gProjectileFnTable
	movs r1, #0x23
	strb r1, [r3, #9]
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080AD0AA:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AD0B4: .4byte gProjectileHeaderPtr
_080AD0B8: .4byte gProjectileFnTable

	thumb_func_start initPantheonBomb
initPantheonBomb: @ 0x080AD0BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r6, [r7, #0x11]
	cmp r6, #0
	bne _080AD118
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080AD110 @ =0x0836C84C
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080AD114 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r6, [r7, #0xe]
	strb r6, [r7, #0xf]
	b _080AD17A
	.align 2, 0
_080AD110: .4byte 0x0836C84C
_080AD114: .4byte gProjectileFnTable
_080AD118:
	cmp r6, #1
	bne _080AD17A
	adds r0, r7, #0
	bl InitScalerotMotion1
	adds r1, r7, #0
	adds r1, #0x50
	movs r5, #0
	movs r0, #0
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x24
	strb r5, [r0]
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080AD190 @ =0x0836C84C
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r7, [r4, #0x2c]
	mov r0, r8
	str r0, [r4, #0x24]
	ldr r1, _080AD194 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
_080AD17A:
	movs r0, #0xff
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	bl pantheonBombAI
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD190: .4byte 0x0836C84C
_080AD194: .4byte gProjectileFnTable

	thumb_func_start pantheonBombAI
pantheonBombAI: @ 0x080AD198
	push {lr}
	adds r2, r0, #0
	ldr r0, _080AD1E4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080AD1EC
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
	ldr r1, _080AD1E8 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl FUN_080ad204
	b _080AD1FC
	.align 2, 0
_080AD1E4: .4byte gCurStory
_080AD1E8: .4byte gProjectileFnTable
_080AD1EC:
	ldr r0, _080AD200 @ =0x0836C844
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080AD1FC:
	pop {r0}
	bx r0
	.align 2, 0
_080AD200: .4byte 0x0836C844

	thumb_func_start FUN_080ad204
FUN_080ad204: @ 0x080AD204
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
	ldr r1, _080AD23C @ =gProjectileFnTable
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
_080AD23C: .4byte gProjectileFnTable

	thumb_func_start _pantheonBombAI
_pantheonBombAI: @ 0x080AD240
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080AD276
	movs r1, #0
	str r1, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	b _080AD3E2
_080AD276:
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _080AD27E
	b _080AD3F4
_080AD27E:
	lsls r0, r0, #2
	ldr r1, _080AD288 @ =_080AD28C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AD288: .4byte _080AD28C
_080AD28C: @ jump table
	.4byte _080AD2AC @ case 0
	.4byte _080AD2DE @ case 1
	.4byte _080AD322 @ case 2
	.4byte _080AD334 @ case 3
	.4byte _080AD34C @ case 4
	.4byte _080AD35A @ case 5
	.4byte _080AD37C @ case 6
	.4byte _080AD3BA @ case 7
_080AD2AC:
	ldr r1, _080AD2C0 @ =0x0000690B
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080AD2C8
	ldr r0, _080AD2C4 @ =0xFFFFFE80
	b _080AD2CC
	.align 2, 0
_080AD2C0: .4byte 0x0000690B
_080AD2C4: .4byte 0xFFFFFE80
_080AD2C8:
	movs r0, #0xc0
	lsls r0, r0, #1
_080AD2CC:
	str r0, [r5, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080AD2DE:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AD2EE
	str r1, [r5, #0x60]
_080AD2EE:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080AD31A
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080AD31A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080AD3F4
_080AD322:
	ldr r1, _080AD348 @ =0x0000690C
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x30
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080AD334:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080AD3F4
	b _080AD370
	.align 2, 0
_080AD348: .4byte 0x0000690C
_080AD34C:
	ldr r1, _080AD378 @ =0x0000690D
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080AD35A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080AD370
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AD3F4
_080AD370:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080AD3F4
	.align 2, 0
_080AD378: .4byte 0x0000690D
_080AD37C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080AD3FC @ =0x0836C87C
	bl SetDDP
	movs r0, #0x14
	strb r0, [r5, #0x13]
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
	movs r0, #0x35
	bl PlaySound
	adds r0, r4, #0
	movs r1, #0
	bl createPantheonBombBlast
	adds r0, r4, #0
	movs r1, #1
	bl createPantheonBombBlast
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080AD3BA:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080AD3CA
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AD3F4
_080AD3CA:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
_080AD3E2:
	ldr r1, _080AD400 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080AD3F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD3FC: .4byte 0x0836C87C
_080AD400: .4byte gProjectileFnTable

	thumb_func_start pantheonBombBlastAI
pantheonBombBlastAI: @ 0x080AD404
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080AD4A0
	cmp r5, #1
	bgt _080AD418
	cmp r5, #0
	beq _080AD420
	b _080AD58C
_080AD418:
	cmp r5, #2
	bne _080AD41E
	b _080AD550
_080AD41E:
	b _080AD58C
_080AD420:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080AD45C @ =0x0836C894
	bl SetDDP
	ldr r1, _080AD460 @ =0x0000690E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080AD468
	ldr r0, _080AD464 @ =0xFFFFFD80
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080AD490
	.align 2, 0
_080AD45C: .4byte 0x0836C894
_080AD460: .4byte 0x0000690E
_080AD464: .4byte 0xFFFFFD80
_080AD468:
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080AD490:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	movs r0, #0x24
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AD4A0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080AD4B8
	subs r0, #1
	strb r0, [r4, #0x13]
_080AD4B8:
	ldrb r0, [r4, #0x13]
	cmp r0, #9
	bhi _080AD4DA
	ldr r1, [r4, #0x60]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldr r0, [r4, #0x60]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
_080AD4DA:
	ldrb r0, [r4, #0x13]
	cmp r0, #4
	bne _080AD4FA
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080AD536
_080AD4FA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080AD514
	ldr r0, [r4, #0x54]
	ldr r1, _080AD510 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	b _080AD522
	.align 2, 0
_080AD510: .4byte 0xFFFFF800
_080AD514:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
_080AD522:
	cmp r0, #0
	beq _080AD536
	ldrb r0, [r4, #0x13]
	cmp r0, #0xa
	bls _080AD530
	movs r0, #0xa
	strb r0, [r4, #0x13]
_080AD530:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AD536:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080AD58C
	ldr r1, _080AD54C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	b _080AD586
	.align 2, 0
_080AD54C: .4byte gProjectileFnTable
_080AD550:
	ldr r1, [r4, #0x60]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldr r0, [r4, #0x60]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080AD57C
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AD58C
_080AD57C:
	ldr r1, _080AD594 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
_080AD586:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080AD58C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD594: .4byte gProjectileFnTable

	thumb_func_start hanu_080ad598
hanu_080ad598: @ 0x080AD598
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080AD5E8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AD5E2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AD5EC @ =gProjectileFnTable
	movs r1, #0x24
	strb r1, [r3, #9]
	adds r0, #0x90
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080AD5E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AD5E8: .4byte gProjectileHeaderPtr
_080AD5EC: .4byte gProjectileFnTable

	thumb_func_start FUN_080ad5f0
FUN_080ad5f0: @ 0x080AD5F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080AD640 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AD63A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AD644 @ =gProjectileFnTable
	movs r1, #0x24
	strb r1, [r3, #9]
	adds r0, #0x90
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080AD63A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AD640: .4byte gProjectileHeaderPtr
_080AD644: .4byte gProjectileFnTable

	thumb_func_start FUN_080ad648
FUN_080ad648: @ 0x080AD648
	push {lr}
	ldr r2, _080AD65C @ =0x0836C8C0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AD65C: .4byte 0x0836C8C0

	thumb_func_start FUN_080ad660
FUN_080ad660: @ 0x080AD660
	push {lr}
	ldr r2, _080AD674 @ =0x0836C8D0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AD674: .4byte 0x0836C8D0
_080AD678:
	.byte 0x82, 0x7A, 0xFE, 0x21, 0x11, 0x40, 0x81, 0x72
	.byte 0x04, 0x4A, 0x41, 0x7A, 0x89, 0x00, 0x89, 0x18, 0x04, 0x22, 0xC2, 0x60, 0x09, 0x68, 0x09, 0x69
	.byte 0x41, 0x61, 0x70, 0x47, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080ad698
FUN_080ad698: @ 0x080AD698
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xd4
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AD76C @ =0x0836C8E0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r4, _080AD770 @ =gSineTable
	ldrb r0, [r6, #0x11]
	adds r3, r0, #0
	adds r3, #0xc0
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _080AD6F2
	adds r0, #0xff
_080AD6F2:
	asrs r2, r0, #8
	str r2, [r6, #0x5c]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _080AD70C
	adds r0, #0xff
_080AD70C:
	asrs r1, r0, #8
	str r1, [r6, #0x60]
	lsls r0, r2, #3
	ldr r2, [r6, #0x54]
	adds r2, r2, r0
	str r2, [r6, #0x54]
	lsls r1, r1, #3
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb4
	str r2, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #3
	bl FUN_080ad5f0
	adds r0, r6, #0
	movs r1, #1
	movs r2, #6
	bl FUN_080ad5f0
	adds r0, r6, #0
	movs r1, #1
	movs r2, #9
	bl FUN_080ad5f0
	ldr r1, _080AD774 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl FUN_080ad660
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AD76C: .4byte 0x0836C8E0
_080AD770: .4byte gSineTable
_080AD774: .4byte gProjectileFnTable

	thumb_func_start FUN_080ad778
FUN_080ad778: @ 0x080AD778
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AD7C4
	ldr r1, _080AD7CC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_080AD7C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD7CC: .4byte gProjectileFnTable

	thumb_func_start FUN_080ad7d0
FUN_080ad7d0: @ 0x080AD7D0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AD838 @ =0x00006A01
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #9
	strb r0, [r1]
	ldr r0, [r5, #0x5c]
	str r0, [r4, #0x5c]
	ldr r0, [r5, #0x60]
	str r0, [r4, #0x60]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r0]
	str r1, [r4, #0x54]
	adds r5, #0xb8
	ldr r0, [r5]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x58]
	str r0, [r1]
	ldrb r0, [r4, #0x11]
	strb r0, [r4, #0x13]
	ldr r1, _080AD83C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080ad660
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD838: .4byte 0x00006A01
_080AD83C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ad840
FUN_080ad840: @ 0x080AD840
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080AD860
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AD88E
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080AD88C
_080AD860:
	ldrb r2, [r4, #0x12]
	adds r2, #1
	strb r2, [r4, #0x12]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #3
	ands r2, r0
	cmp r2, #1
	bls _080AD886
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080AD88C
_080AD886:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080AD88C:
	strb r0, [r4, #0xa]
_080AD88E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AD8AE
	ldr r1, _080AD8B4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080AD8AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD8B4: .4byte gProjectileFnTable

	thumb_func_start FUN_080ad8b8
FUN_080ad8b8: @ 0x080AD8B8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl InitRotatableMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r6, #0
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080AD8F4 @ =0x00006A05
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	ldrb r2, [r5, #0x11]
	cmp r2, #0
	beq _080AD8F8
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AD8FE
	.align 2, 0
_080AD8F4: .4byte 0x00006A05
_080AD8F8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AD8FE:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	strb r3, [r5, #0x12]
	strb r3, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AD932
	movs r0, #4
	rsbs r0, r0, #0
	b _080AD934
_080AD932:
	movs r0, #4
_080AD934:
	strb r0, [r5, #0x13]
	ldr r1, _080AD954 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl FUN_080ad660
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AD954: .4byte gProjectileFnTable

	thumb_func_start FUN_080ad958
FUN_080ad958: @ 0x080AD958
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	ldrb r1, [r4, #0x12]
	adds r0, r0, r1
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080AD98A
	ldr r1, _080AD990 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080AD98A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD990: .4byte gProjectileFnTable

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
	bl FUN_080ad660
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA48: .4byte 0xFFFFF600
_080ADA4C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ada50
FUN_080ada50: @ 0x080ADA50
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080ADA74
	ldr r1, _080ADA7C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ADA74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA7C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ada80
FUN_080ada80: @ 0x080ADA80
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080ADAC8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080ADAC0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080ADACC @ =gProjectileFnTable
	movs r1, #0x25
	strb r1, [r3, #9]
	adds r0, #0x94
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r4, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
	str r5, [r3, #0x28]
_080ADAC0:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080ADAC8: .4byte gProjectileHeaderPtr
_080ADACC: .4byte gProjectileFnTable

	thumb_func_start FUN_080adad0
FUN_080adad0: @ 0x080ADAD0
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080ADB1C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080ADB14
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080ADB20 @ =gProjectileFnTable
	movs r1, #0x25
	strb r1, [r3, #9]
	adds r0, #0x94
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080ADB14:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080ADB1C: .4byte gProjectileHeaderPtr
_080ADB20: .4byte gProjectileFnTable

	thumb_func_start FUN_080adb24
FUN_080adb24: @ 0x080ADB24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0x11]
	cmp r7, #0
	bne _080ADB7C
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
	ldr r1, _080ADB74 @ =0x0836C944
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r1, _080ADB78 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _080ADBC4
	.align 2, 0
_080ADB74: .4byte 0x0836C944
_080ADB78: .4byte gProjectileFnTable
_080ADB7C:
	cmp r7, #1
	bne _080ADBC4
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
	ldr r1, _080ADBD4 @ =0x0836C92C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080ADBD8 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_080ADBC4:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl FUN_080adbdc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADBD4: .4byte 0x0836C92C
_080ADBD8: .4byte gProjectileFnTable

	thumb_func_start FUN_080adbdc
FUN_080adbdc: @ 0x080ADBDC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080ADC28 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080ADC30
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
	ldr r1, _080ADC2C @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl FUN_080adc48
	b _080ADC40
	.align 2, 0
_080ADC28: .4byte gCurStory
_080ADC2C: .4byte gProjectileFnTable
_080ADC30:
	ldr r0, _080ADC44 @ =0x0836C924
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080ADC40:
	pop {r0}
	bx r0
	.align 2, 0
_080ADC44: .4byte 0x0836C924

	thumb_func_start FUN_080adc48
FUN_080adc48: @ 0x080ADC48
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
	ldr r1, _080ADC80 @ =gProjectileFnTable
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
_080ADC80: .4byte gProjectileFnTable

	thumb_func_start FUN_080adc84
FUN_080adc84: @ 0x080ADC84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r1, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r2, r1
	cmp r2, #0
	beq _080ADCB6
	movs r1, #0
	str r1, [r5]
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	b _080ADD1A
_080ADCB6:
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _080ADCDA
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	b _080ADD1A
_080ADCDA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080ADD06
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080ADD3C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080ADD3C
_080ADD06:
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_080ADD1A:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080ADD38 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080AE138
	.align 2, 0
_080ADD38: .4byte gProjectileFnTable
_080ADD3C:
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080ADD44
	b _080AE138
_080ADD44:
	lsls r0, r0, #2
	ldr r1, _080ADD50 @ =_080ADD54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ADD50: .4byte _080ADD54
_080ADD54: @ jump table
	.4byte _080ADD6C @ case 0
	.4byte _080ADD9E @ case 1
	.4byte _080ADDE0 @ case 2
	.4byte _080ADDF4 @ case 3
	.4byte _080ADE5E @ case 4
	.4byte _080ADF90 @ case 5
_080ADD6C:
	ldr r1, _080ADDDC @ =0x00006F08
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	str r2, [r4, #0x60]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADD9E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _080ADDAE
	str r1, [r4, #0x60]
_080ADDAE:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080ADDD4
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADDD4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080AE138
	.align 2, 0
_080ADDDC: .4byte 0x00006F08
_080ADDE0:
	movs r0, #0x64
	bl PlaySound
	movs r0, #0x20
	str r0, [r4, #0x5c]
	movs r0, #0xc
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADDF4:
	ldr r0, [r4, #0x60]
	subs r0, #0x80
	str r0, [r4, #0x60]
	cmp r0, #0
	bge _080ADE02
	movs r0, #0
	str r0, [r4, #0x60]
_080ADE02:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ADE40
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080ADE40:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080ADE4E
	b _080AE138
_080ADE4E:
	ldr r0, [r4, #0x5c]
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x60]
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080AE138
_080ADE5E:
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0xd
	strb r0, [r4, #0x13]
	ldr r0, _080ADEF0 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080ADECE
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080ADECE:
	ldr r1, [r4, #0x5c]
	lsls r1, r1, #9
	asrs r1, r1, #8
	str r1, [r4, #0x64]
	ldr r2, [r4, #0x60]
	lsls r0, r2, #9
	asrs r0, r0, #8
	str r0, [r4, #0x68]
	cmp r1, #0
	ble _080ADF32
	cmp r0, #0
	ble _080ADF0C
	cmp r2, #0x5e
	bgt _080ADEF8
	ldr r1, _080ADEF4 @ =0x00006F06
	b _080ADF72
	.align 2, 0
_080ADEF0: .4byte pZero2
_080ADEF4: .4byte 0x00006F06
_080ADEF8:
	cmp r2, #0xea
	bgt _080ADF04
	ldr r1, _080ADF00 @ =0x00006F05
	b _080ADF72
	.align 2, 0
_080ADF00: .4byte 0x00006F05
_080ADF04:
	ldr r1, _080ADF08 @ =0x00006F04
	b _080ADF72
	.align 2, 0
_080ADF08: .4byte 0x00006F04
_080ADF0C:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF1C
	ldr r1, _080ADF18 @ =0x00006F06
	b _080ADF72
	.align 2, 0
_080ADF18: .4byte 0x00006F06
_080ADF1C:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF2C
	ldr r1, _080ADF28 @ =0x00006F07
	b _080ADF72
	.align 2, 0
_080ADF28: .4byte 0x00006F07
_080ADF2C:
	movs r1, #0xde
	lsls r1, r1, #7
	b _080ADF72
_080ADF32:
	cmp r0, #0
	ble _080ADF58
	cmp r2, #0x5e
	bgt _080ADF44
	ldr r1, _080ADF40 @ =0x00006F02
	b _080ADF72
	.align 2, 0
_080ADF40: .4byte 0x00006F02
_080ADF44:
	cmp r2, #0xea
	bgt _080ADF50
	ldr r1, _080ADF4C @ =0x00006F03
	b _080ADF72
	.align 2, 0
_080ADF4C: .4byte 0x00006F03
_080ADF50:
	ldr r1, _080ADF54 @ =0x00006F04
	b _080ADF72
	.align 2, 0
_080ADF54: .4byte 0x00006F04
_080ADF58:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF68
	ldr r1, _080ADF64 @ =0x00006F02
	b _080ADF72
	.align 2, 0
_080ADF64: .4byte 0x00006F02
_080ADF68:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF80
	ldr r1, _080ADF7C @ =0x00006F01
_080ADF72:
	adds r0, r4, #0
	bl SetMotion
	b _080ADF8A
	.align 2, 0
_080ADF7C: .4byte 0x00006F01
_080ADF80:
	movs r1, #0xde
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_080ADF8A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADF90:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080ADFBC
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080ADFA2
	b _080AE0FA
_080ADFA2:
	ldr r0, _080AE060 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080ADFB4
	movs r0, #0xd
	strb r0, [r4, #0x13]
_080ADFB4:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080ADFBC
	b _080AE0FA
_080ADFBC:
	ldr r0, _080AE060 @ =pZero2
	ldr r3, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080ADFCC
	b _080AE0FA
_080ADFCC:
	movs r0, #0xd
	strb r0, [r4, #0x13]
	ldr r2, [r3, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r3, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080AE01A
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080AE01A:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #9
	asrs r0, r0, #8
	adds r6, r0, #0
	ldr r3, [r4, #0x60]
	lsls r1, r3, #9
	asrs r1, r1, #8
	adds r7, r1, #0
	ldr r2, [r4, #0x64]
	lsls r2, r2, #6
	asrs r2, r2, #8
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x64]
	ldr r0, [r4, #0x68]
	lsls r0, r0, #6
	asrs r0, r0, #8
	lsls r1, r1, #1
	adds r1, r1, r7
	lsls r1, r1, #6
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x68]
	cmp r2, #0
	ble _080AE0A2
	cmp r0, #0
	ble _080AE07C
	cmp r3, #0x5e
	bgt _080AE068
	ldr r1, _080AE064 @ =0x00006F06
	b _080AE0E2
	.align 2, 0
_080AE060: .4byte pZero2
_080AE064: .4byte 0x00006F06
_080AE068:
	cmp r3, #0xea
	bgt _080AE074
	ldr r1, _080AE070 @ =0x00006F05
	b _080AE0E2
	.align 2, 0
_080AE070: .4byte 0x00006F05
_080AE074:
	ldr r1, _080AE078 @ =0x00006F04
	b _080AE0E2
	.align 2, 0
_080AE078: .4byte 0x00006F04
_080AE07C:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE08C
	ldr r1, _080AE088 @ =0x00006F06
	b _080AE0E2
	.align 2, 0
_080AE088: .4byte 0x00006F06
_080AE08C:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE09C
	ldr r1, _080AE098 @ =0x00006F07
	b _080AE0E2
	.align 2, 0
_080AE098: .4byte 0x00006F07
_080AE09C:
	movs r1, #0xde
	lsls r1, r1, #7
	b _080AE0E2
_080AE0A2:
	cmp r0, #0
	ble _080AE0C8
	cmp r3, #0x5e
	bgt _080AE0B4
	ldr r1, _080AE0B0 @ =0x00006F02
	b _080AE0E2
	.align 2, 0
_080AE0B0: .4byte 0x00006F02
_080AE0B4:
	cmp r3, #0xea
	bgt _080AE0C0
	ldr r1, _080AE0BC @ =0x00006F03
	b _080AE0E2
	.align 2, 0
_080AE0BC: .4byte 0x00006F03
_080AE0C0:
	ldr r1, _080AE0C4 @ =0x00006F04
	b _080AE0E2
	.align 2, 0
_080AE0C4: .4byte 0x00006F04
_080AE0C8:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE0D8
	ldr r1, _080AE0D4 @ =0x00006F02
	b _080AE0E2
	.align 2, 0
_080AE0D4: .4byte 0x00006F02
_080AE0D8:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE0F0
	ldr r1, _080AE0EC @ =0x00006F01
_080AE0E2:
	adds r0, r4, #0
	bl SetMotion
	b _080AE0FA
	.align 2, 0
_080AE0EC: .4byte 0x00006F01
_080AE0F0:
	movs r1, #0xde
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_080AE0FA:
	ldrb r0, [r4, #0x13]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AE122
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldr r0, [r1, #4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	str r0, [r1, #4]
	movs r0, #3
	bl CreateSmoke
_080AE122:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080AE138:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ae140
FUN_080ae140: @ 0x080AE140
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #2
	bls _080AE17C
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AE178 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080AE1F6
	.align 2, 0
_080AE178: .4byte gProjectileFnTable
_080AE17C:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080AE1A2
	cmp r5, #1
	bgt _080AE18C
	cmp r5, #0
	beq _080AE192
	b _080AE1F6
_080AE18C:
	cmp r5, #2
	beq _080AE1C8
	b _080AE1F6
_080AE192:
	ldr r1, _080AE1C4 @ =0x00006E06
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AE1A2:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AE1F6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080AE1F6
	.align 2, 0
_080AE1C4: .4byte 0x00006E06
_080AE1C8:
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AE1E8
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080AE1EE
_080AE1E8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080AE1EE:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080AE1F6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start createOzArcBlade
createOzArcBlade: @ 0x080AE1FC
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080AE254 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AE24C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AE258 @ =gProjectileFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x12]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #0x13]
_080AE24C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AE254: .4byte gProjectileHeaderPtr
_080AE258: .4byte gProjectileFnTable

	thumb_func_start CreateMessenkou
CreateMessenkou: @ 0x080AE25C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r6, #0
	ldr r7, _080AE2A8 @ =0x0836A9A4
_080AE266:
	ldr r0, _080AE2AC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080AE29C
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #8
	strb r0, [r2]
	movs r0, #0x26
	strb r0, [r1, #9]
	ldr r0, [r7]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r6, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r6, [r0]
	movs r0, #1
	strb r0, [r1, #0x10]
	ldr r0, [r5, #0x54]
	str r0, [r1, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r1, #0x58]
	strb r4, [r1, #0x12]
_080AE29C:
	adds r4, #1
	cmp r4, #4
	ble _080AE266
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AE2A8: .4byte 0x0836A9A4
_080AE2AC: .4byte gProjectileHeaderPtr

	thumb_func_start CreateOmegaZeroSaber
CreateOmegaZeroSaber: @ 0x080AE2B0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AE2F8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AE2EE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AE2FC @ =gProjectileFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x11]
	str r5, [r3, #0x28]
_080AE2EE:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AE2F8: .4byte gProjectileHeaderPtr
_080AE2FC: .4byte gProjectileFnTable

	thumb_func_start ozRekkoha_080ae300
ozRekkoha_080ae300: @ 0x080AE300
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AE358 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AE350
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AE35C @ =gProjectileFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x10]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r1, r0, #4
	adds r0, r0, r1
	strb r0, [r3, #0x12]
	str r5, [r3, #0x28]
	ldr r0, [r5, #0x58]
	ldr r1, _080AE360 @ =0xFFFFD000
	adds r0, r0, r1
	str r0, [r3, #0x58]
_080AE350:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AE358: .4byte gProjectileHeaderPtr
_080AE35C: .4byte gProjectileFnTable
_080AE360: .4byte 0xFFFFD000

	thumb_func_start CreateDoubleChargeWave1
CreateDoubleChargeWave1: @ 0x080AE364
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AE3D0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AE3CA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AE3D4 @ =gProjectileFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #0x12]
	ldr r4, [r5, #0x54]
	ldr r1, _080AE3D8 @ =0xFFFFE600
	adds r0, r4, r1
	str r0, [r3, #0x54]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AE3C0
	movs r0, #0xd0
	lsls r0, r0, #5
	adds r2, r4, r0
_080AE3C0:
	str r2, [r3, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _080AE3DC @ =0xFFFFE900
	adds r0, r0, r1
	str r0, [r3, #0x58]
_080AE3CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AE3D0: .4byte gProjectileHeaderPtr
_080AE3D4: .4byte gProjectileFnTable
_080AE3D8: .4byte 0xFFFFE600
_080AE3DC: .4byte 0xFFFFE900

	thumb_func_start CreateDoubleChargeWave2
CreateDoubleChargeWave2: @ 0x080AE3E0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AE44C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AE446
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AE450 @ =gProjectileFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #5
	strb r0, [r3, #0x10]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #0x12]
	ldr r4, [r5, #0x54]
	ldr r1, _080AE454 @ =0xFFFFE600
	adds r0, r4, r1
	str r0, [r3, #0x54]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AE43C
	movs r0, #0xd0
	lsls r0, r0, #5
	adds r2, r4, r0
_080AE43C:
	str r2, [r3, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _080AE458 @ =0xFFFFE900
	adds r0, r0, r1
	str r0, [r3, #0x58]
_080AE446:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AE44C: .4byte gProjectileHeaderPtr
_080AE450: .4byte gProjectileFnTable
_080AE454: .4byte 0xFFFFE600
_080AE458: .4byte 0xFFFFE900

	thumb_func_start CreateDoubleChargeWave3
CreateDoubleChargeWave3: @ 0x080AE45C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AE4C8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AE4C2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AE4CC @ =gProjectileFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #6
	strb r0, [r3, #0x10]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #0x12]
	ldr r4, [r5, #0x54]
	ldr r1, _080AE4D0 @ =0xFFFFD800
	adds r0, r4, r1
	str r0, [r3, #0x54]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AE4B8
	movs r0, #0xa0
	lsls r0, r0, #6
	adds r2, r4, r0
_080AE4B8:
	str r2, [r3, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _080AE4D4 @ =0xFFFFF100
	adds r0, r0, r1
	str r0, [r3, #0x58]
_080AE4C2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AE4C8: .4byte gProjectileHeaderPtr
_080AE4CC: .4byte gProjectileFnTable
_080AE4D0: .4byte 0xFFFFD800
_080AE4D4: .4byte 0xFFFFF100

	thumb_func_start nop_080ae4d8
nop_080ae4d8: @ 0x080AE4D8
	bx lr
	.align 2, 0
