	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b73d4
FUN_080b73d4: @ 0x080B73D4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B7450
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080B7438 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B743C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080B7440 @ =0x00269EC3
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
	ldr r2, _080B7444 @ =0x00000409
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B7448 @ =0x0000040A
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B744C @ =0x0000040B
	mov r0, sp
	b _080B74BC
	.align 2, 0
_080B7438: .4byte RNG_0202f388
_080B743C: .4byte 0x000343FD
_080B7440: .4byte 0x00269EC3
_080B7444: .4byte 0x00000409
_080B7448: .4byte 0x0000040A
_080B744C: .4byte 0x0000040B
_080B7450:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080B74F4
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080B74F4
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080B74D8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B74DC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080B74E0 @ =0x00269EC3
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
	ldr r2, _080B74E4 @ =0x00000409
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B74E8 @ =0x0000040A
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B74EC @ =0x0000040B
	adds r0, r5, #0
_080B74BC:
	adds r3, r4, #0
	bl FUN_080b721c
	ldr r1, _080B74F0 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080B753C
	.align 2, 0
_080B74D8: .4byte RNG_0202f388
_080B74DC: .4byte 0x000343FD
_080B74E0: .4byte 0x00269EC3
_080B74E4: .4byte 0x00000409
_080B74E8: .4byte 0x0000040A
_080B74EC: .4byte 0x0000040B
_080B74F0: .4byte gVFXFnTable
_080B74F4:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B7500
	cmp r0, #1
	beq _080B7516
	b _080B753C
_080B7500:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	ldr r0, _080B7544 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080B7548 @ =0x00000407
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B7516:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B7526
	str r1, [r6, #0x60]
_080B7526:
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
_080B753C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B7544: .4byte 0xFFFFFF00
_080B7548: .4byte 0x00000407
