	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelMode9
volteelMode9: @ 0x080450C0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080450CE
	b _08045454
_080450CE:
	lsls r0, r0, #2
	ldr r1, _080450D8 @ =_080450DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080450D8: .4byte _080450DC
_080450DC: @ jump table
	.4byte _080450F4 @ case 0
	.4byte _080452D0 @ case 1
	.4byte _080452EC @ case 2
	.4byte _080453A2 @ case 3
	.4byte _080453C0 @ case 4
	.4byte _080453F6 @ case 5
_080450F4:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r7, #0
	movs r6, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x24
	strb r6, [r0]
	ldr r2, _08045168 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804516C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08045170 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r5, r0, #0x11
	movs r3, #3
	ands r5, r3
	cmp r5, #0
	bne _08045174
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r5, [r0]
	subs r0, #0x7d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	b _0804522E
	.align 2, 0
_08045168: .4byte RNG_0202f388
_0804516C: .4byte 0x000343FD
_08045170: .4byte 0x00269EC3
_08045174:
	cmp r5, #1
	bne _080451E8
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r5, [r0]
	subs r0, #0x7d
	strb r6, [r0]
	subs r2, #0x8a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080451E0 @ =0x0000A514
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080451E4 @ =0x083624C8
	bl SetDDP
	b _080452BE
	.align 2, 0
_080451E0: .4byte 0x0000A514
_080451E4: .4byte sCollisions+(17*24)
_080451E8:
	cmp r5, #2
	bne _0804525C
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x4d
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
_0804522E:
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08045254 @ =0x0000A516
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08045258 @ =0x083624F8
	bl SetDDP
	b _080452BE
	.align 2, 0
_08045254: .4byte 0x0000A516
_08045258: .4byte sCollisions+(19*24)
_0804525C:
	adds r0, r4, #0
	adds r0, #0xdc
	ldr r0, [r0]
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r3, [r0]
	subs r0, #0x7d
	strb r6, [r0]
	subs r2, #0x8a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080452E4 @ =0x0000A514
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080452E8 @ =0x083624C8
	bl SetDDP
_080452BE:
	strb r5, [r4, #0x13]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	movs r0, #0x7c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080452D0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080452E2
	b _08045454
_080452E2:
	b _080453A8
	.align 2, 0
_080452E4: .4byte 0x0000A514
_080452E8: .4byte sCollisions+(17*24)
_080452EC:
	ldr r2, _0804533C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08045340 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08045344 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r3, r0, #0x11
	movs r0, #3
	ands r3, r0
	adds r0, r4, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r3, r0
	bne _08045318
	adds r1, r3, #1
	adds r0, r1, #0
	asrs r3, r0, #2
	lsls r0, r3, #2
	subs r3, r1, r0
_08045318:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	cmp r3, #0
	bne _08045348
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [sp]
	adds r0, r4, #0
	adds r0, #0xd4
	b _0804536E
	.align 2, 0
_0804533C: .4byte RNG_0202f388
_08045340: .4byte 0x000343FD
_08045344: .4byte 0x00269EC3
_08045348:
	cmp r3, #1
	bne _08045352
	adds r0, r4, #0
	adds r0, #0xe0
	b _08045378
_08045352:
	cmp r3, #2
	bne _08045374
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [sp]
	adds r0, r4, #0
	adds r0, #0xd8
_0804536E:
	ldr r0, [r0]
	str r0, [sp, #4]
	b _08045390
_08045374:
	adds r0, r4, #0
	adds r0, #0xdc
_08045378:
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	str r1, [sp, #4]
_08045390:
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	mov r1, sp
	bl volteel_080bc0b0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080453A2:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080453A8:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080453B8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08045454
_080453B8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08045454
_080453C0:
	adds r0, r4, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #0
	bne _080453D4
	ldr r1, _080453D0 @ =0x0000A517
	b _080453DA
	.align 2, 0
_080453D0: .4byte 0x0000A517
_080453D4:
	cmp r0, #1
	bne _080453E8
	ldr r1, _080453E4 @ =0x0000A515
_080453DA:
	adds r0, r4, #0
	bl SetMotion
	b _080453F0
	.align 2, 0
_080453E4: .4byte 0x0000A515
_080453E8:
	ldr r1, _0804545C @ =0x0000A515
	adds r0, r4, #0
	bl SetMotion
_080453F0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080453F6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08045454
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08045460 @ =sCollisions
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x4d
	movs r2, #0
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #5
	strb r0, [r4, #0xd]
	movs r0, #8
	strb r0, [r4, #0xe]
	strb r2, [r4, #0xf]
_08045454:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804545C: .4byte 0x0000A515
_08045460: .4byte sCollisions

