	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080af9f4
FUN_080af9f4: @ 0x080AF9F4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AFA6A
	movs r5, #0
	ldr r7, _080AFB10 @ =gSineTable
	mov r6, sp
_080AFA1E:
	ldrb r3, [r4, #0x13]
	lsls r3, r3, #4
	lsls r0, r5, #6
	adds r3, r3, r0
	lsls r3, r3, #0x18
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	lsrs r2, r3, #0x18
	movs r0, #0x80
	lsls r0, r0, #0x17
	adds r3, r3, r0
	lsrs r3, r3, #0x17
	adds r3, r3, r7
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #3
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	lsls r0, r2, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	ldr r1, [r6, #4]
	adds r0, r0, r1
	str r0, [r6, #4]
	mov r0, sp
	movs r1, #0xf0
	lsls r1, r1, #2
	movs r3, #0
	bl FUN_080afbfc
	adds r5, #1
	cmp r5, #3
	ble _080AFA1E
_080AFA6A:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r5, #0
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AFAC2
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
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
	ldr r1, _080AFB14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AFAC2:
	ldr r0, _080AFB18 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AFB08
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
	ldr r1, _080AFB14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AFB08:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFB10: .4byte gSineTable
_080AFB14: .4byte gProjectileFnTable
_080AFB18: .4byte gStageRun+232

	thumb_func_start FUN_080afb1c
FUN_080afb1c: @ 0x080AFB1C
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AFB5E
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
	ldr r1, _080AFB64 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080AFB5E:
	pop {r0}
	bx r0
	.align 2, 0
_080AFB64: .4byte gProjectileFnTable

	thumb_func_start PhantomProjectile_Die
PhantomProjectile_Die: @ 0x080AFB68
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AFBAC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AFBAC: .4byte gProjectileFnTable

	thumb_func_start FUN_080afbb0
FUN_080afbb0: @ 0x080AFBB0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AFBF4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFBEC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFBF8 @ =gProjectileFnTable
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
	strb r4, [r3, #0x10]
	str r5, [r3, #0x28]
_080AFBEC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AFBF4: .4byte gProjectileHeaderPtr
_080AFBF8: .4byte gProjectileFnTable

	thumb_func_start FUN_080afbfc
FUN_080afbfc: @ 0x080AFBFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	mov r8, r4
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	ldr r0, _080AFC90 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFC82
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFC94 @ =gProjectileFnTable
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
	movs r0, #1
	strb r0, [r3, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldr r2, _080AFC98 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _080AFC64
	adds r0, #0xff
_080AFC64:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _080AFC78
	adds r0, #0xff
_080AFC78:
	asrs r0, r0, #8
	str r0, [r3, #0x60]
	mov r0, r8
	strb r0, [r3, #0x12]
	strb r7, [r3, #0x11]
_080AFC82:
	adds r0, r3, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AFC90: .4byte gProjectileHeaderPtr
_080AFC94: .4byte gProjectileFnTable
_080AFC98: .4byte gSineTable

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


