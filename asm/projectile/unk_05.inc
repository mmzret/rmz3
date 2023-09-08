	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809d904
FUN_0809d904: @ 0x0809D904
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _0809D95C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809D954
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809D960 @ =gProjectileFnTable
	movs r0, #5
	strb r0, [r3, #9]
	ldr r0, [r1, #0x14]
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
	adds r0, r3, #0
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_0809D954:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809D95C: .4byte gProjectileHeaderPtr
_0809D960: .4byte gProjectileFnTable

	thumb_func_start Projectile5_Init
Projectile5_Init: @ 0x0809D964
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0809D9B8 @ =sCollisions
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	ldr r1, _0809D9BC @ =gProjectileFnTable
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
	bl Projectile5_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D9B8: .4byte sCollisions
_0809D9BC: .4byte gProjectileFnTable

	thumb_func_start Projectile5_Update
Projectile5_Update: @ 0x0809D9C0
	push {lr}
	ldr r2, _0809D9D4 @ =sUpdates
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809D9D4: .4byte sUpdates

	thumb_func_start Projectile5_Die
Projectile5_Die: @ 0x0809D9D8
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
	ldr r1, _0809DA10 @ =gProjectileFnTable
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
_0809DA10: .4byte gProjectileFnTable

	thumb_func_start FUN_0809da14
FUN_0809da14: @ 0x0809DA14
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809DA44
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _0809DA40 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809DA94
	.align 2, 0
_0809DA40: .4byte gProjectileFnTable
_0809DA44:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809DA50
	cmp r0, #1
	beq _0809DA70
	b _0809DA76
_0809DA50:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0809DA62
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	b _0809DA6A
_0809DA62:
	ldr r1, _0809DA9C @ =0x00000A03
	adds r0, r4, #0
	bl SetMotion
_0809DA6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809DA70:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809DA76:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	beq _0809DA88
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0809DA94
_0809DA88:
	movs r0, #0
	movs r1, #0x7f
	strb r1, [r4, #0x12]
	movs r1, #1
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0809DA94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809DA9C: .4byte 0x00000A03

	thumb_func_start FUN_0809daa0
FUN_0809daa0: @ 0x0809DAA0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809DAB8
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	b _0809DAC4
_0809DAB8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809DADC
_0809DAC4:
	ldr r1, _0809DAD8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809DBAA
	.align 2, 0
_0809DAD8: .4byte gProjectileFnTable
_0809DADC:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0809DB5E
	cmp r5, #1
	bgt _0809DAEC
	cmp r5, #0
	beq _0809DAF2
	b _0809DBAA
_0809DAEC:
	cmp r5, #2
	beq _0809DB94
	b _0809DBAA
_0809DAF2:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0809DB20
	ldr r1, _0809DB18 @ =0x00000A01
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809DB1C @ =sCollisions+24
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r4, #0x60]
	str r5, [r4, #0x5c]
	b _0809DB3E
	.align 2, 0
_0809DB18: .4byte 0x00000A01
_0809DB1C: .4byte sCollisions+24
_0809DB20:
	ldr r1, _0809DB80 @ =0x00000A04
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809DB84 @ =sCollisions+48
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	str r5, [r4, #0x60]
_0809DB3E:
	ldr r2, _0809DB88 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809DB8C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809DB90 @ =0x00269EC3
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
_0809DB5E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809DBAA
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809DBAA
	.align 2, 0
_0809DB80: .4byte 0x00000A04
_0809DB84: .4byte sCollisions+48
_0809DB88: .4byte RNG_0202f388
_0809DB8C: .4byte 0x000343FD
_0809DB90: .4byte 0x00269EC3
_0809DB94:
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
_0809DBAA:
	pop {r4, r5}
	pop {r0}
	bx r0
