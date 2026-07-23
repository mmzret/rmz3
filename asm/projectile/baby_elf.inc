	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	bl AllocEntityFirst
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
	ldr r1, _0809FB5C @ =sCollisions
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
_0809FB5C: .4byte sCollisions
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
	ldr r1, _0809FC40 @ =sCollisions
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
	bl UpdateEntityAnim
	b _0809FCF0
	.align 2, 0
_0809FC40: .4byte sCollisions
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809FE38 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl Camera_GetDistance
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl Camera_GetDistance
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
	bl UpdateEntityAnim
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
	ldr r1, _080A0554 @ =sUnkDeltaX
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
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A05F4
	b _080A05B2
	.align 2, 0
_080A0550: .4byte 0x0836B098
_080A0554: .4byte sUnkDeltaX
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
