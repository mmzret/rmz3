	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080afc9c
FUN_080afc9c: @ 0x080AFC9C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AFCE4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFCDC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFCE8 @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
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
	strb r4, [r3, #0x12]
	str r5, [r3, #0x28]
_080AFCDC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AFCE4: .4byte gProjectileHeaderPtr
_080AFCE8: .4byte gProjectileFnTable

	thumb_func_start FUN_080afcec
FUN_080afcec: @ 0x080AFCEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	mov r8, r5
	ldr r0, _080AFD98 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080AFD8C
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFD9C @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r4, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r4, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r2, _080AFDA0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	bge _080AFD50
	adds r0, #0xff
_080AFD50:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	bge _080AFD64
	adds r0, #0xff
_080AFD64:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	mov r0, r8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0x80
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0xc0
	bl FUN_080afc9c
_080AFD8C:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AFD98: .4byte gProjectileHeaderPtr
_080AFD9C: .4byte gProjectileFnTable
_080AFDA0: .4byte gSineTable

	thumb_func_start FUN_080afda4
FUN_080afda4: @ 0x080AFDA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AFDE8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFDDE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFDEC @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
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
	str r4, [r3, #0x28]
_080AFDDE:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AFDE8: .4byte gProjectileHeaderPtr
_080AFDEC: .4byte gProjectileFnTable

	thumb_func_start FUN_080afdf0
FUN_080afdf0: @ 0x080AFDF0
	push {r4, r5, lr}
	ldr r5, [r2]
	ldr r3, [r1]
	adds r4, r3, r5
	str r4, [r1]
	ldr r3, [r1, #4]
	ldr r2, [r2, #4]
	adds r3, r3, r2
	str r3, [r1, #4]
	adds r1, r0, #0
	adds r1, #0xdc
	ldr r1, [r1]
	ldr r2, _080AFE28 @ =0xFFFFB400
	adds r1, r1, r2
	ldr r3, _080AFE2C @ =0xFFFFDA00
	adds r2, r4, r3
	adds r0, #0xd4
	ldr r0, [r0]
	subs r4, r2, r0
	cmp r4, r1
	bls _080AFE30
	adds r0, r4, #0
	muls r0, r5, r0
	cmp r0, #0
	ble _080AFE30
	movs r0, #1
	b _080AFE32
	.align 2, 0
_080AFE28: .4byte 0xFFFFB400
_080AFE2C: .4byte 0xFFFFDA00
_080AFE30:
	movs r0, #0
_080AFE32:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080afe38
FUN_080afe38: @ 0x080AFE38
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r6, r3, #0
	ldr r5, [r6]
	ldr r0, [r2]
	adds r3, r0, r5
	str r3, [r2]
	ldr r1, [r2, #4]
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	ble _080AFE54
	subs r1, #8
	str r1, [r2, #4]
_080AFE54:
	ldr r0, [r4]
	adds r0, r0, r3
	str r0, [r4]
	ldr r0, [r4, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _080AFE70 @ =0x000003FF
	adds r1, r3, r0
	ldr r0, _080AFE74 @ =0x000007FE
	cmp r1, r0
	bhi _080AFE78
	movs r0, #0
	b _080AFE7E
	.align 2, 0
_080AFE70: .4byte 0x000003FF
_080AFE74: .4byte 0x000007FE
_080AFE78:
	rsbs r0, r5, #0
	str r0, [r6]
	movs r0, #1
_080AFE7E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
