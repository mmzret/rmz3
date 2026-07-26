	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c3108
FUN_080c3108: @ 0x080C3108
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3130
	ldr r1, _080C312C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C320C
	.align 2, 0
_080C312C: .4byte gVFXFnTable
_080C3130:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C313C
	cmp r5, #1
	beq _080C3178
	b _080C320C
_080C313C:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldr r1, _080C3198 @ =0x00006B03
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x5c]
	str r5, [r4, #0x60]
	ldr r2, _080C319C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C31A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C31A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x40
	str r0, [r4, #0x64]
	movs r0, #0x32
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3178:
	ldrb r0, [r4, #0x13]
	adds r1, r0, #1
	movs r5, #0
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x14
	bls _080C31A8
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080C31BE
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C31C4
	.align 2, 0
_080C3198: .4byte 0x00006B03
_080C319C: .4byte RNG_0202f388
_080C31A0: .4byte 0x000343FD
_080C31A4: .4byte 0x00269EC3
_080C31A8:
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C31BE
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C31C4
_080C31BE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C31C4:
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x64]
	cmp r1, #0
	ble _080C31D8
	ldr r0, [r4, #0x5c]
	adds r0, #8
	str r0, [r4, #0x5c]
	cmp r0, r1
	ble _080C31E6
	b _080C31E4
_080C31D8:
	ldr r0, [r4, #0x5c]
	subs r0, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	cmp r0, r1
	bge _080C31E6
_080C31E4:
	str r1, [r4, #0x5c]
_080C31E6:
	ldr r0, [r4, #0x60]
	adds r0, #8
	str r0, [r4, #0x60]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C31F6
	str r1, [r4, #0x60]
_080C31F6:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080C320C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c3214
FUN_080c3214: @ 0x080C3214
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3290
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C3278 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C327C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C3280 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080C3284 @ =0x00006B04
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C3288 @ =0x00006B05
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C328C @ =0x00006B06
	mov r0, sp
	b _080C32FC
	.align 2, 0
_080C3278: .4byte RNG_0202f388
_080C327C: .4byte 0x000343FD
_080C3280: .4byte 0x00269EC3
_080C3284: .4byte 0x00006B04
_080C3288: .4byte 0x00006B05
_080C328C: .4byte 0x00006B06
_080C3290:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C3334
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C3334
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C3318 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C331C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C3320 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080C3324 @ =0x00006B04
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C3328 @ =0x00006B05
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C332C @ =0x00006B06
	adds r0, r5, #0
_080C32FC:
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldr r1, _080C3330 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080C337C
	.align 2, 0
_080C3318: .4byte RNG_0202f388
_080C331C: .4byte 0x000343FD
_080C3320: .4byte 0x00269EC3
_080C3324: .4byte 0x00006B04
_080C3328: .4byte 0x00006B05
_080C332C: .4byte 0x00006B06
_080C3330: .4byte gVFXFnTable
_080C3334:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080C3340
	cmp r0, #1
	beq _080C3356
	b _080C337C
_080C3340:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	ldr r0, _080C3384 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080C3388 @ =0x00006B02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080C3356:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C3366
	str r1, [r6, #0x60]
_080C3366:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateEntityAnim
_080C337C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C3384: .4byte 0xFFFFFF00
_080C3388: .4byte 0x00006B02

	thumb_func_start FUN_080c338c
FUN_080c338c: @ 0x080C338C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080C33C2
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C33E4
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C33E4
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080C33E4
_080C33C2:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080C33E0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080C34B2
	.align 2, 0
_080C33E0: .4byte gVFXFnTable
_080C33E4:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080C33F2
	cmp r0, #1
	beq _080C345C
	b _080C34B2
_080C33F2:
	ldr r4, _080C3474 @ =0x0836F490
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080C3478 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C347C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C3480 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C345C:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C3484
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C348A
	.align 2, 0
_080C3474: .4byte 0x0836F490
_080C3478: .4byte RNG_0202f388
_080C347C: .4byte 0x000343FD
_080C3480: .4byte 0x00269EC3
_080C3484:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C348A:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C349C
	str r1, [r7, #0x60]
_080C349C:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateEntityAnim
_080C34B2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

