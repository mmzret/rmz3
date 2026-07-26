	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080aabd4
FUN_080aabd4: @ 0x080AABD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AAC20 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
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
	bl AllocEntityLast
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
