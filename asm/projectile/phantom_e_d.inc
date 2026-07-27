	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
