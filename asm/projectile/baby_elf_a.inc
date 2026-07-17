	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809f970
FUN_0809f970: @ 0x0809F970
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809F9D8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
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

