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
