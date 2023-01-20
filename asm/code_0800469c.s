	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800469c
FUN_0800469c: @ 0x0800469C
	str r1, [r0]
	ldr r1, _080046A8 @ =0x08338CCC
	str r1, [r0, #4]
	str r3, [r0, #8]
	bx lr
	.align 2, 0
_080046A8: .4byte 0x08338CCC

	thumb_func_start FUN_080046ac
FUN_080046ac: @ 0x080046AC
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0, #4]
	movs r2, #0xe0
	lsls r2, r2, #1
	strh r2, [r0, #6]
	asrs r1, r1, #1
	strh r1, [r0, #8]
	movs r1, #0xe0
	strh r1, [r0, #0xa]
	bx lr
_080046C8:
	.byte 0x01, 0x81, 0x42, 0x81, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080046d0
FUN_080046d0: @ 0x080046D0
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	cmp r3, #0
	beq _08004710
	ldr r2, [r3]
	ldr r0, [r2]
	str r0, [r4]
	ldr r0, [r2, #4]
	str r0, [r4, #4]
	ldr r1, [r2]
	asrs r1, r1, #8
	ldr r3, [r3, #4]
	ldr r0, [r3]
	asrs r0, r0, #8
	adds r1, r1, r0
	subs r1, #0x78
	lsls r1, r1, #8
	str r1, [r4, #8]
	ldr r0, [r2, #4]
	asrs r0, r0, #8
	ldr r1, [r3, #4]
	asrs r1, r1, #8
	adds r0, r0, r1
	subs r0, #0x50
	lsls r0, r0, #8
	str r0, [r4, #0xc]
	ldr r0, [r3]
	str r0, [r4, #0x10]
	ldr r0, [r3, #4]
	str r0, [r4, #0x14]
	b _0800471C
_08004710:
	str r3, [r4, #4]
	str r3, [r4]
	str r3, [r4, #0xc]
	str r3, [r4, #8]
	str r3, [r4, #0x14]
	str r3, [r4, #0x10]
_0800471C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start setU32ToArrIdx1
setU32ToArrIdx1: @ 0x08004724
	str r1, [r0, #4]
	bx lr

	thumb_func_start FUN_08004728
FUN_08004728: @ 0x08004728
	movs r1, #0
	str r1, [r0, #4]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08004730
FUN_08004730: @ 0x08004730
	movs r1, #0
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08004738
FUN_08004738: @ 0x08004738
	ldr r2, [r0]
	str r2, [r1]
	str r1, [r0]
	bx lr

	thumb_func_start FUN_08004740
FUN_08004740: @ 0x08004740
	ldr r3, [r0]
	str r3, [r2]
	str r1, [r0]
	bx lr

	thumb_func_start FUN_08004748
FUN_08004748: @ 0x08004748
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r1
	mov sb, r2
	movs r5, #0
	adds r6, r4, #0
	adds r6, #8
	str r5, [sp]
	movs r2, #0x80
	lsls r2, r2, #0x11
	mov r0, sp
	adds r1, r6, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	ldr r2, _080047AC @ =0x05000006
	adds r1, r6, #0
	bl CpuSet
	ldr r1, _080047B0 @ =FUN_0800033c
	adds r0, r4, #0
	bl setU32ToArrIdx1
	ldrb r0, [r4, #0x11]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0x11]
	ldrb r1, [r4, #0x15]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #0x15]
	mov r0, r8
	str r0, [r4, #8]
	mov r0, sb
	str r0, [r4, #0xc]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080047AC: .4byte 0x05000006
_080047B0: .4byte FUN_0800033c

	thumb_func_start FUN_080047b4
FUN_080047b4: @ 0x080047B4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r1
	mov sb, r2
	movs r5, #0
	adds r6, r4, #0
	adds r6, #8
	str r5, [sp]
	movs r2, #0x80
	lsls r2, r2, #0x11
	mov r0, sp
	adds r1, r6, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	ldr r2, _0800481C @ =0x05000006
	adds r1, r6, #0
	bl CpuSet
	ldr r1, _08004820 @ =FUN_08000408
	adds r0, r4, #0
	bl setU32ToArrIdx1
	ldrb r2, [r4, #0x11]
	movs r0, #0x10
	orrs r2, r0
	ldrb r1, [r4, #0x15]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #0x15]
	mov r0, r8
	str r0, [r4, #8]
	mov r0, sb
	str r0, [r4, #0xc]
	movs r0, #3
	orrs r2, r0
	strb r2, [r4, #0x11]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800481C: .4byte 0x05000006
_08004820: .4byte FUN_08000408

	thumb_func_start FUN_08004824
FUN_08004824: @ 0x08004824
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r1
	mov sb, r2
	movs r5, #0
	adds r6, r4, #0
	adds r6, #8
	str r5, [sp]
	movs r2, #0x80
	lsls r2, r2, #0x11
	mov r0, sp
	adds r1, r6, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	ldr r2, _08004894 @ =0x05000006
	adds r1, r6, #0
	bl CpuSet
	ldr r1, _08004898 @ =FUN_080048f8
	adds r0, r4, #0
	bl setU32ToArrIdx1
	ldrb r2, [r4, #0x11]
	movs r0, #0x10
	orrs r2, r0
	ldrb r1, [r4, #0x15]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #0x15]
	mov r0, r8
	str r0, [r4, #8]
	mov r0, sb
	str r0, [r4, #0xc]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	movs r0, #3
	orrs r2, r0
	strb r2, [r4, #0x11]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004894: .4byte 0x05000006
_08004898: .4byte FUN_080048f8

	thumb_func_start FUN_0800489c
FUN_0800489c: @ 0x0800489C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _080048F0 @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	ldr r1, _080048F4 @ =FUN_08004aec
	adds r0, r4, #0
	bl setU32ToArrIdx1
	ldrb r2, [r4, #0x11]
	movs r0, #0x10
	orrs r2, r0
	ldrb r1, [r4, #0x15]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #0x15]
	str r5, [r4, #8]
	str r6, [r4, #0xc]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	movs r0, #4
	rsbs r0, r0, #0
	ands r2, r0
	movs r0, #1
	orrs r2, r0
	strb r2, [r4, #0x11]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080048F0: .4byte 0x01000008
_080048F4: .4byte FUN_08004aec

	thumb_func_start FUN_080048f8
FUN_080048f8: @ 0x080048F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r1, [sp]
	mov ip, r0
	ldrb r1, [r0, #0x1a]
	lsls r1, r1, #2
	ldr r2, [r0, #8]
	adds r1, r2, r1
	ldrh r0, [r1]
	adds r2, r2, r0
	str r2, [sp, #4]
	ldr r2, _08004AD0 @ =0x03002ED0
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r4, [r0]
	str r4, [sp, #8]
	subs r0, r0, r4
	lsrs r0, r0, #3
	ldrb r1, [r1, #2]
	cmp r0, r1
	bhs _0800492E
	b _08004ABE
_0800492E:
	str r1, [sp, #0xc]
	cmp r1, #0
	bne _08004936
	b _08004AB2
_08004936:
	mov r0, ip
	ldr r0, [r0, #0xc]
	str r0, [sp, #0x1c]
_0800493C:
	mov r2, ip
	ldrb r1, [r2, #0x18]
	ldrb r0, [r2, #0x19]
	eors r1, r0
	lsls r2, r1, #8
	subs r2, r2, r1
	mov r3, ip
	ldrb r0, [r3, #0x1b]
	eors r2, r0
	adds r2, r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, [sp, #4]
	ldr r0, [r4]
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x1e
	lsls r1, r1, #2
	lsls r0, r0, #0x12
	lsrs r0, r0, #0x1e
	orrs r1, r0
	movs r0, #2
	ldrsb r0, [r4, r0]
	lsls r0, r0, #8
	str r0, [sp, #0x10]
	lsls r1, r1, #1
	ldr r3, _08004AD4 @ =0x08338CD4
	adds r0, r1, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r3, [sp, #0x10]
	adds r3, r3, r0
	mov sl, r3
	ldr r4, [sp, #4]
	movs r3, #3
	ldrsb r3, [r4, r3]
	lsls r3, r3, #8
	ldr r0, _08004AD8 @ =0x08338CEC
	adds r1, r1, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r0, r0, r3
	mov r8, r0
	mov r0, ip
	ldrb r7, [r0, #0x18]
	lsls r5, r7, #0x1f
	asrs r5, r5, #0x1f
	mov r1, sl
	eors r5, r1
	adds r5, r5, r7
	lsls r0, r2, #1
	ldr r4, _08004ADC @ =0x080FEA74
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	str r1, [sp, #0x14]
	muls r5, r1, r5
	mov r0, ip
	ldrh r0, [r0, #0x1c]
	str r0, [sp, #0x18]
	muls r5, r0, r5
	asrs r5, r5, #8
	mov r1, ip
	ldrb r6, [r1, #0x19]
	lsls r4, r6, #0x1f
	asrs r4, r4, #0x1f
	mov r0, r8
	eors r4, r0
	adds r4, r4, r6
	adds r2, #0x40
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	ldr r1, _08004ADC @ =0x080FEA74
	adds r2, r2, r1
	movs r0, #0
	ldrsh r2, [r2, r0]
	muls r4, r2, r4
	mov r1, ip
	ldrh r1, [r1, #0x1e]
	mov sb, r1
	mov r0, sb
	muls r0, r4, r0
	adds r4, r0, #0
	asrs r4, r4, #8
	adds r5, r5, r4
	asrs r5, r5, #8
	mov r1, r8
	subs r3, r3, r1
	lsls r3, r3, #1
	adds r5, r5, r3
	asrs r5, r5, #8
	ldr r3, [sp, #0x1c]
	ldr r0, [r3, #4]
	ldr r4, [sp]
	ldr r1, [r4, #0xc]
	subs r0, r0, r1
	asrs r0, r0, #8
	adds r5, r5, r0
	adds r0, r5, #0
	adds r0, #0x40
	cmp r0, #0xdf
	bhi _08004A9C
	lsls r3, r7, #0x1f
	asrs r3, r3, #0x1f
	mov r0, sl
	eors r3, r0
	adds r3, r3, r7
	muls r3, r2, r3
	ldr r1, [sp, #0x18]
	muls r3, r1, r3
	asrs r3, r3, #8
	lsls r4, r6, #0x1f
	asrs r4, r4, #0x1f
	mov r2, r8
	eors r4, r2
	adds r4, r4, r6
	ldr r1, [sp, #0x14]
	rsbs r0, r1, #0
	muls r4, r0, r4
	mov r2, sb
	muls r2, r4, r2
	adds r4, r2, #0
	asrs r4, r4, #8
	adds r3, r3, r4
	asrs r3, r3, #8
	ldr r4, [sp, #0x10]
	mov r1, sl
	subs r0, r4, r1
	lsls r0, r0, #1
	adds r3, r3, r0
	asrs r3, r3, #8
	ldr r2, [sp, #0x1c]
	ldr r0, [r2]
	ldr r4, [sp]
	ldr r1, [r4, #8]
	subs r0, r0, r1
	asrs r0, r0, #8
	adds r3, r3, r0
	adds r1, r3, #0
	adds r1, #0x80
	ldr r0, _08004AE0 @ =0x0000016F
	cmp r1, r0
	bhi _08004A9C
	mov r0, ip
	ldr r2, [r0, #0x10]
	ldr r4, [sp, #4]
	ldrh r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r0, r1
	lsls r4, r0, #0x12
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r1
	orrs r4, r0
	movs r0, #0xff
	ands r5, r0
	orrs r4, r5
	ldr r0, _08004AE4 @ =0x000001FF
	ands r3, r0
	lsls r0, r3, #0x10
	orrs r4, r0
	orrs r2, r4
	ldr r0, [sp, #8]
	str r2, [r0]
	mov r2, ip
	ldrh r1, [r2, #0x14]
	strh r1, [r0, #4]
	ldr r3, [sp, #4]
	ldrh r2, [r3]
	ldr r0, _08004AE8 @ =0x000003FF
	ands r0, r2
	adds r1, r1, r0
	ldr r4, [sp, #8]
	strh r1, [r4, #4]
	adds r4, #8
	str r4, [sp, #8]
_08004A9C:
	ldr r0, [sp, #4]
	adds r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	cmp r0, #0
	beq _08004AB2
	b _0800493C
_08004AB2:
	ldr r1, _08004AD0 @ =0x03002ED0
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, [sp, #8]
	str r3, [r0]
_08004ABE:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004AD0: .4byte 0x03002ED0
_08004AD4: .4byte 0x08338CD4
_08004AD8: .4byte 0x08338CEC
_08004ADC: .4byte 0x080FEA74
_08004AE0: .4byte 0x0000016F
_08004AE4: .4byte 0x000001FF
_08004AE8: .4byte 0x000003FF

	thumb_func_start FUN_08004aec
FUN_08004aec: @ 0x08004AEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r1, [sp]
	adds r7, r0, #0
	ldrb r1, [r7, #0x1a]
	lsls r1, r1, #2
	ldr r2, [r7, #8]
	adds r1, r2, r1
	ldrh r0, [r1]
	adds r2, r2, r0
	str r2, [sp, #4]
	ldr r2, _08004CB4 @ =0x03002ED0
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r4, [r0]
	str r4, [sp, #8]
	subs r0, r0, r4
	lsrs r0, r0, #3
	ldrb r1, [r1, #2]
	cmp r0, r1
	bhs _08004B22
	b _08004CA2
_08004B22:
	str r1, [sp, #0xc]
	cmp r1, #0
	bne _08004B2A
	b _08004C96
_08004B2A:
	ldr r0, [r7, #0xc]
	str r0, [sp, #0x18]
_08004B2E:
	ldrb r1, [r7, #0x18]
	ldrb r0, [r7, #0x19]
	eors r1, r0
	lsls r2, r1, #8
	subs r2, r2, r1
	ldrb r0, [r7, #0x1b]
	eors r2, r0
	adds r2, r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, [sp, #4]
	ldr r0, [r1]
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x1e
	lsls r1, r1, #2
	lsls r0, r0, #0x12
	lsrs r0, r0, #0x1e
	orrs r1, r0
	ldr r3, [sp, #4]
	movs r0, #2
	ldrsb r0, [r3, r0]
	lsls r0, r0, #8
	str r0, [sp, #0x10]
	lsls r1, r1, #1
	ldr r4, _08004CB8 @ =0x08338CD4
	adds r0, r1, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r4, [sp, #0x10]
	adds r4, r4, r0
	mov sb, r4
	ldr r0, [sp, #4]
	movs r3, #3
	ldrsb r3, [r0, r3]
	lsls r3, r3, #8
	ldr r4, _08004CBC @ =0x08338CEC
	adds r1, r1, r4
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r0, r0, r3
	mov ip, r0
	ldrb r6, [r7, #0x18]
	lsls r5, r6, #0x1f
	asrs r5, r5, #0x1f
	mov r0, sb
	eors r5, r0
	adds r5, r5, r6
	lsls r0, r2, #1
	ldr r1, _08004CC0 @ =0x080FEA74
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	str r4, [sp, #0x14]
	muls r5, r4, r5
	ldrh r4, [r7, #0x1c]
	mov sl, r4
	mov r0, sl
	muls r0, r5, r0
	adds r5, r0, #0
	asrs r5, r5, #8
	ldrb r1, [r7, #0x19]
	lsls r4, r1, #0x1f
	asrs r4, r4, #0x1f
	mov r0, ip
	eors r4, r0
	adds r4, r4, r1
	adds r2, #0x40
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	ldr r0, _08004CC0 @ =0x080FEA74
	adds r2, r2, r0
	movs r0, #0
	ldrsh r2, [r2, r0]
	muls r4, r2, r4
	ldrh r0, [r7, #0x1e]
	mov r8, r0
	mov r0, r8
	muls r0, r4, r0
	adds r4, r0, #0
	asrs r4, r4, #8
	adds r5, r5, r4
	asrs r5, r5, #8
	mov r4, ip
	subs r3, r3, r4
	adds r5, r5, r3
	ldr r3, [sp, #0x18]
	ldr r0, [r3, #4]
	adds r5, r5, r0
	ldr r4, [sp]
	ldr r0, [r4, #0xc]
	subs r5, r5, r0
	asrs r5, r5, #8
	adds r0, r5, #0
	adds r0, #0x40
	cmp r0, #0xdf
	bhi _08004C80
	lsls r3, r6, #0x1f
	asrs r3, r3, #0x1f
	mov r0, sb
	eors r3, r0
	adds r3, r3, r6
	muls r3, r2, r3
	mov r2, sl
	muls r2, r3, r2
	adds r3, r2, #0
	asrs r3, r3, #8
	lsls r4, r1, #0x1f
	asrs r4, r4, #0x1f
	mov r0, ip
	eors r4, r0
	adds r4, r4, r1
	ldr r1, [sp, #0x14]
	rsbs r0, r1, #0
	muls r4, r0, r4
	mov r2, r8
	muls r2, r4, r2
	adds r4, r2, #0
	asrs r4, r4, #8
	adds r3, r3, r4
	asrs r3, r3, #8
	ldr r4, [sp, #0x10]
	mov r1, sb
	subs r0, r4, r1
	adds r3, r3, r0
	ldr r2, [sp, #0x18]
	ldr r0, [r2]
	adds r3, r3, r0
	ldr r4, [sp]
	ldr r0, [r4, #8]
	subs r3, r3, r0
	asrs r3, r3, #8
	adds r1, r3, #0
	adds r1, #0x80
	ldr r0, _08004CC4 @ =0x0000016F
	cmp r1, r0
	bhi _08004C80
	ldr r2, [r7, #0x10]
	ldr r0, [sp, #4]
	ldrh r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r0, r1
	lsls r4, r0, #0x12
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r1
	orrs r4, r0
	movs r0, #0xff
	ands r5, r0
	orrs r4, r5
	ldr r0, _08004CC8 @ =0x000001FF
	ands r3, r0
	lsls r0, r3, #0x10
	orrs r4, r0
	orrs r2, r4
	ldr r1, [sp, #8]
	str r2, [r1]
	ldrh r1, [r7, #0x14]
	ldr r2, [sp, #8]
	strh r1, [r2, #4]
	ldr r3, [sp, #4]
	ldrh r2, [r3]
	ldr r0, _08004CCC @ =0x000003FF
	ands r0, r2
	adds r1, r1, r0
	ldr r4, [sp, #8]
	strh r1, [r4, #4]
	adds r4, #8
	str r4, [sp, #8]
_08004C80:
	ldr r0, [sp, #4]
	adds r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	cmp r0, #0
	beq _08004C96
	b _08004B2E
_08004C96:
	ldr r1, _08004CB4 @ =0x03002ED0
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, [sp, #8]
	str r3, [r0]
_08004CA2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004CB4: .4byte 0x03002ED0
_08004CB8: .4byte 0x08338CD4
_08004CBC: .4byte 0x08338CEC
_08004CC0: .4byte 0x080FEA74
_08004CC4: .4byte 0x0000016F
_08004CC8: .4byte 0x000001FF
_08004CCC: .4byte 0x000003FF

	thumb_func_start FUN_08004cd0
FUN_08004cd0: @ 0x08004CD0
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r4, r0, #0
	mov sl, r1
	adds r5, r2, #0
	adds r6, r3, #0
	lsls r5, r5, #0x18
	lsrs r0, r5, #0x18
	mov r8, r0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r1, _08004D70 @ =FUN_08004d80
	adds r0, r4, #0
	bl setU32ToArrIdx1
	ldrb r0, [r4, #0xd]
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r2, r0
	ldrb r1, [r4, #0x11]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0
	mov sb, r1
	mov r3, sb
	strb r3, [r4, #0x12]
	strb r3, [r4, #0x13]
	movs r1, #0x10
	orrs r2, r1
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r0, r3
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #0x11]
	ands r2, r3
	mov r0, sl
	str r0, [r4, #8]
	lsrs r5, r5, #0x1a
	lsls r5, r5, #6
	movs r1, #0x3f
	ands r2, r1
	orrs r2, r5
	movs r0, #3
	mov r3, r8
	ands r3, r0
	lsls r3, r3, #6
	ldrb r0, [r4, #0xf]
	ands r1, r0
	orrs r1, r3
	ldr r0, _08004D74 @ =0x000003FF
	ands r6, r0
	ldrh r3, [r4, #0x10]
	ldr r0, _08004D78 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r6
	strh r0, [r4, #0x10]
	movs r0, #4
	rsbs r0, r0, #0
	ands r2, r0
	strb r2, [r4, #0xd]
	subs r0, #0x3b
	ands r1, r0
	strb r1, [r4, #0xf]
	ldrh r1, [r4, #0xe]
	ldr r0, _08004D7C @ =0xFFFFFE00
	ands r0, r1
	strh r0, [r4, #0xe]
	mov r0, sb
	strb r0, [r4, #0xc]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004D70: .4byte FUN_08004d80
_08004D74: .4byte 0x000003FF
_08004D78: .4byte 0xFFFFFC00
_08004D7C: .4byte 0xFFFFFE00

	thumb_func_start FUN_08004d80
FUN_08004d80: @ 0x08004D80
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _08004E08 @ =0x03002ED0
	movs r1, #0x80
	lsls r1, r1, #3
	adds r7, r0, r1
	ldr r5, [r7]
	cmp r5, r7
	bhs _08004E00
	ldr r2, [r4, #8]
	ldr r0, [r2, #4]
	ldr r1, [r3, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r6, r0, #0x10
	adds r0, r6, #0
	adds r0, #0x40
	cmp r0, #0xdf
	bhi _08004E00
	ldr r0, [r2]
	ldr r1, [r3, #8]
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r3, r0, #0x10
	adds r1, r3, #0
	adds r1, #0x80
	ldr r0, _08004E0C @ =0x0000016F
	cmp r1, r0
	bhi _08004E00
	ldr r2, [r4, #0xc]
	str r2, [r5]
	movs r1, #0xff
	ands r1, r6
	ldrb r0, [r4, #0xd]
	lsrs r0, r0, #6
	lsls r0, r0, #0xe
	orrs r1, r0
	ldr r0, _08004E10 @ =0x000001FF
	ands r3, r0
	lsls r0, r3, #0x10
	orrs r1, r0
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0x1c
	orrs r1, r0
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #0x1d
	orrs r1, r0
	ldrb r0, [r4, #0xf]
	lsrs r0, r0, #6
	lsls r0, r0, #0x1e
	orrs r1, r0
	orrs r2, r1
	str r2, [r5]
	ldrh r1, [r4, #0x10]
	strh r1, [r5, #4]
	ldrh r0, [r4, #0x10]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	orrs r1, r0
	strh r1, [r5, #4]
	adds r0, r5, #0
	adds r0, #8
	str r0, [r7]
_08004E00:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004E08: .4byte 0x03002ED0
_08004E0C: .4byte 0x0000016F
_08004E10: .4byte 0x000001FF

	thumb_func_start FUN_08004e14
FUN_08004e14: @ 0x08004E14
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r5, #0
	str r5, [sp]
	ldr r2, _08004E48 @ =0x01000080
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	str r4, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r5, [r0]
	movs r0, #0x82
	lsls r0, r0, #2
	adds r4, r4, r0
	str r5, [r4]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004E48: .4byte 0x01000080

	thumb_func_start FUN_08004e4c
FUN_08004e4c: @ 0x08004E4C
	movs r2, #0x81
	lsls r2, r2, #2
	adds r0, r0, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08004e58
FUN_08004e58: @ 0x08004E58
	movs r2, #0x82
	lsls r2, r2, #2
	adds r0, r0, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08004e64
FUN_08004e64: @ 0x08004E64
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, [r2]
	str r0, [r1]
	str r1, [r2]
	bx lr

	thumb_func_start FUN_08004e74
FUN_08004e74: @ 0x08004E74
	lsls r2, r2, #0x10
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	asrs r2, r2, #9
	adds r2, r2, r0
	ldr r0, [r2]
	str r0, [r1]
	str r1, [r2]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08004e8c
FUN_08004e8c: @ 0x08004E8C
	push {r4, lr}
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	asrs r3, r3, #0xe
	asrs r2, r2, #9
	adds r2, r2, r0
	adds r3, r3, r2
	ldr r0, [r3]
	str r0, [r1]
	str r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08004eb0
FUN_08004eb0: @ 0x08004EB0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08004EF8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r2, [r0]
	mov r0, sp
	bl FUN_080046d0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r6, [r0]
	movs r0, #0
_08004EDA:
	ldm r6!, {r4}
	adds r5, r0, #1
	cmp r4, #0
	beq _08004EF2
_08004EE2:
	ldr r2, [r4, #4]
	adds r0, r4, #0
	mov r1, sp
	bl _call_via_r2
	ldr r4, [r4]
	cmp r4, #0
	bne _08004EE2
_08004EF2:
	adds r0, r5, #0
	cmp r0, #0x7f
	ble _08004EDA
_08004EF8:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08004f00
FUN_08004f00: @ 0x08004F00
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	bl malloc
	adds r1, r5, r4
	str r0, [r1]
	cmp r0, #0
	bne _08004F1A
	str r5, [r1]
_08004F1A:
	movs r0, #0
	ldr r1, [r1]
	str r0, [sp]
	ldr r2, _08004F30 @ =0x01000080
	mov r0, sp
	bl CpuFastSet
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004F30: .4byte 0x01000080

	thumb_func_start changeMotionTable
changeMotionTable: @ 0x08004F34
	str r1, [r0]
	movs r2, #0
	strb r2, [r0, #4]
	strb r2, [r0, #5]
	ldr r1, [r1]
	ldrb r1, [r1, #1]
	adds r1, #1
	strb r1, [r0, #6]
	strb r2, [r0, #7]
	bx lr

	thumb_func_start action_08004f48
action_08004f48: @ 0x08004F48
	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r4, #0
	strb r1, [r3, #4]
	strb r4, [r3, #5]
	ldr r2, [r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	adds r1, r0, #1
	strb r1, [r3, #6]
	ldrb r0, [r3, #4]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #3
	ldrsb r2, [r0, r2]
	cmp r2, #0
	bge _08004F9E
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08004F80
	strb r0, [r3, #7]
	b _08004FA0
_08004F80:
	cmp r0, #1
	bne _08004F98
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne _08004F92
	movs r0, #3
	strb r0, [r3, #7]
	b _08004FA0
_08004F92:
	movs r0, #4
	strb r0, [r3, #7]
	b _08004FA0
_08004F98:
	movs r0, #1
	strb r0, [r3, #7]
	b _08004FA0
_08004F9E:
	strb r4, [r3, #7]
_08004FA0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start motion_08004fa8
motion_08004fa8: @ 0x08004FA8
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #6]
	subs r0, #1
	strb r0, [r2, #6]
	lsls r0, r0, #0x18
	asrs r3, r0, #0x18
	cmp r3, #0
	bne _0800504A
	ldrb r5, [r2, #5]
	adds r0, r5, #1
	strb r0, [r2, #5]
	ldrb r0, [r2, #4]
	ldr r7, [r2]
	lsls r0, r0, #2
	adds r6, r0, r7
	movs r0, #5
	ldrsb r0, [r2, r0]
	ldr r1, [r6]
	lsls r0, r0, #1
	adds r4, r0, r1
	movs r1, #1
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	mov ip, r0
	cmp r1, ip
	bne _08004FEA
	strb r5, [r2, #5]
	movs r0, #1
	strb r0, [r2, #6]
	movs r0, #3
	b _08005080
_08004FEA:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08004FF8
	ldrb r0, [r4]
	strb r0, [r2, #5]
	strb r3, [r2, #7]
_08004FF8:
	movs r0, #5
	ldrsb r0, [r2, r0]
	ldr r1, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r3, [r0, #1]
	strb r3, [r2, #6]
	ldrb r0, [r2, #5]
	adds r0, #1
	strb r0, [r2, #5]
	ldrb r0, [r2, #4]
	lsls r0, r0, #2
	adds r0, r0, r7
	movs r1, #5
	ldrsb r1, [r2, r1]
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrb r1, [r1, #1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	bge _08005042
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _08005040
	cmp r0, #1
	bne _0800503E
	cmp r1, ip
	bne _0800503A
	movs r0, #3
	b _08005040
_0800503A:
	movs r0, #4
	b _08005040
_0800503E:
	movs r0, #1
_08005040:
	strb r0, [r2, #7]
_08005042:
	ldrb r0, [r2, #5]
	subs r0, #1
	strb r0, [r2, #5]
	b _08005082
_0800504A:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08005082
	cmp r3, #2
	bne _08005058
	strb r3, [r2, #7]
	b _08005082
_08005058:
	cmp r3, #1
	bne _08005082
	ldrb r1, [r2, #4]
	ldr r0, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #5
	ldrsb r0, [r2, r0]
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #3
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0800507E
	movs r0, #3
	b _08005080
_0800507E:
	movs r0, #4
_08005080:
	strb r0, [r2, #7]
_08005082:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08005088
FUN_08005088: @ 0x08005088
	push {r4, r5, lr}
	ldr r4, [sp, #0xc]
	ldr r5, [sp, #0x10]
	ldr r2, [r1]
	str r2, [r0]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	str r3, [r0, #0xc]
	str r4, [r0, #0x10]
	str r5, [r0, #0x14]
	ldr r3, _080050AC @ =0x000001FF
	ands r2, r3
	strh r2, [r0, #8]
	ands r1, r3
	strh r1, [r0, #0xa]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080050AC: .4byte 0x000001FF

	thumb_func_start FUN_080050b0
FUN_080050b0: @ 0x080050B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	mov r8, r0
	str r1, [sp]
	str r2, [sp, #4]
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r3, [r1]
	movs r2, #0x10
	adds r1, r3, #0
	ands r1, r2
	mov r7, r8
	ldr r4, [r7]
	adds r0, r4, #0
	ands r0, r2
	cmp r1, r0
	beq _08005106
	cmp r3, r4
	ble _080050F4
	movs r0, #0x88
	lsls r0, r0, #1
	adds r0, r3, r0
	str r0, [sp, #8]
	ldr r1, [sp]
	ldr r0, [r1, #4]
	adds r2, r0, #0
	subs r2, #0x10
	str r2, [sp, #0xc]
	adds r4, r0, #0
	b _0800510E
_080050F4:
	subs r3, #0x20
	str r3, [sp, #8]
	ldr r3, [sp]
	ldr r0, [r3, #4]
	adds r4, r0, #0
	subs r4, #0x10
	str r4, [sp, #0xc]
	adds r4, r0, #0
	b _0800510E
_08005106:
	movs r7, #1
	str r7, [sp, #0x18]
	ldr r0, [sp]
	ldr r4, [r0, #4]
_0800510E:
	adds r3, r4, #0
	movs r2, #0x10
	adds r1, r3, #0
	ands r1, r2
	mov r7, r8
	ldr r5, [r7, #4]
	adds r0, r5, #0
	ands r0, r2
	cmp r1, r0
	beq _08005142
	cmp r3, r5
	ble _08005134
	ldr r1, [sp]
	ldr r0, [r1]
	subs r0, #0x20
	str r0, [sp, #0x10]
	adds r3, #0xb0
	str r3, [sp, #0x14]
	b _0800514A
_08005134:
	ldr r2, [sp]
	ldr r0, [r2]
	subs r0, #0x20
	str r0, [sp, #0x10]
	subs r4, #0x10
	str r4, [sp, #0x14]
	b _0800514A
_08005142:
	movs r0, #2
	ldr r3, [sp, #0x18]
	orrs r3, r0
	str r3, [sp, #0x18]
_0800514A:
	ldr r4, [sp, #8]
	cmp r4, #0
	bge _08005154
	movs r7, #0
	str r7, [sp, #8]
_08005154:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bge _0800515E
	movs r1, #0
	str r1, [sp, #0xc]
_0800515E:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	bge _08005168
	movs r3, #0
	str r3, [sp, #0x10]
_08005168:
	ldr r4, [sp, #0x14]
	cmp r4, #0
	bge _08005172
	movs r7, #0
	str r7, [sp, #0x14]
_08005172:
	movs r0, #1
	ldr r1, [sp, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0800517E
	b _0800535A
_0800517E:
	ldr r2, [sp, #8]
	mov sl, r2
	adds r0, r2, #0
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	mov r3, r8
	ldr r6, [r3, #0x14]
	adds r4, r6, r4
	ldr r5, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r6]
	muls r0, r1, r0
	adds r4, r4, r0
	mov sb, r4
	ldr r0, [sp, #8]
	movs r1, #0xf0
	bl __modsi3
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x10
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldrb r2, [r4]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	mov r4, r8
	ldr r3, [r4, #0x10]
	adds r2, r3, r2
	ldr r7, [sp, #0x1c]
	lsls r1, r7, #0x10
	asrs r1, r1, #0xf
	adds r2, r2, r1
	lsrs r1, r0, #0x10
	str r1, [sp, #0x20]
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r5, r2, r1
	movs r7, #0
	movs r1, #0xa
	subs r1, r1, r0
	str r6, [sp, #0x38]
	str r3, [sp, #0x34]
	cmp r7, r1
	bge _08005250
	mov r2, sp
	ldrh r3, [r2, #0xc]
	strh r3, [r2, #0x24]
	ldr r0, [sp, #8]
	asrs r4, r0, #3
	movs r0, #0x1e
	ands r4, r0
	adds r0, #0xe2
	mov r2, sl
	ands r2, r0
	lsls r2, r2, #3
	mov ip, r2
	mov r3, r8
	ldr r3, [r3, #0xc]
	mov sl, r3
	adds r6, r1, #0
_08005214:
	lsls r2, r7, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #4
	mov r7, sp
	ldrh r7, [r7, #0x24]
	adds r0, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sl
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	movs r1, #0xf0
	lsls r1, r1, #2
	ands r0, r1
	adds r0, r0, r4
	lsls r0, r0, #1
	ldr r1, [sp, #4]
	adds r0, r0, r1
	add r0, ip
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r5, #0x1e
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, r6
	blt _08005214
_08005250:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2]
	add sb, r0
	mov r3, sb
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r4, [sp, #0x34]
	adds r0, r4, r0
	ldr r1, [sp, #0x1c]
	lsls r2, r1, #0x10
	asrs r1, r2, #0xf
	adds r5, r0, r1
	lsls r3, r7, #0x10
	asrs r0, r3, #0x10
	str r2, [sp, #0x2c]
	cmp r0, #0xc
	bgt _080052E6
	subs r0, #0xa
	ldr r2, [sp, #0x20]
	lsls r6, r2, #0x10
	asrs r1, r6, #0x10
	adds r0, r0, r1
	cmp r0, #9
	bgt _080052E6
	mov r4, sp
	ldrh r4, [r4, #0xc]
	mov ip, r4
	ldr r7, [sp, #8]
	asrs r4, r7, #3
	movs r0, #0x1e
	ands r4, r0
	adds r0, #0xe2
	adds r1, r7, #0
	ands r0, r1
	lsls r0, r0, #3
	mov sl, r0
_080052A0:
	asrs r3, r3, #0x10
	lsls r0, r3, #4
	add r0, ip
	ldrh r1, [r5]
	lsls r1, r1, #3
	mov r7, r8
	ldr r2, [r7, #0xc]
	adds r2, r2, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	movs r1, #0xf0
	lsls r1, r1, #2
	ands r0, r1
	adds r0, r0, r4
	lsls r0, r0, #1
	ldr r1, [sp, #4]
	adds r0, r0, r1
	add r0, sl
	ldr r1, [r2]
	str r1, [r0]
	ldr r1, [r2, #4]
	str r1, [r0, #0x40]
	adds r5, #0x1e
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r3, r7, #0x10
	asrs r0, r3, #0x10
	cmp r0, #0xc
	bgt _080052E6
	subs r0, #0xa
	asrs r1, r6, #0x10
	adds r0, r0, r1
	cmp r0, #9
	ble _080052A0
_080052E6:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2]
	add sb, r0
	mov r3, sb
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r4, [sp, #0x34]
	adds r0, r4, r0
	ldr r2, [sp, #0x2c]
	asrs r1, r2, #0xf
	adds r5, r0, r1
	lsls r2, r7, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0xc
	bgt _0800535A
	mov r3, sp
	ldrh r3, [r3, #0xc]
	mov sb, r3
	ldr r7, [sp, #8]
	asrs r4, r7, #3
	movs r0, #0x1e
	ands r4, r0
	adds r0, #0xe2
	adds r1, r7, #0
	ands r0, r1
	lsls r7, r0, #3
	mov r3, r8
	ldr r6, [r3, #0xc]
_08005326:
	asrs r3, r2, #0x10
	lsls r0, r3, #4
	add r0, sb
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r6, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	movs r1, #0xf0
	lsls r1, r1, #2
	ands r0, r1
	adds r0, r0, r4
	lsls r0, r0, #1
	ldr r1, [sp, #4]
	adds r0, r0, r1
	adds r0, r7, r0
	ldr r1, [r2]
	str r1, [r0]
	ldr r1, [r2, #4]
	str r1, [r0, #0x40]
	adds r5, #0x1e
	adds r3, #1
	lsls r2, r3, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0xc
	ble _08005326
_0800535A:
	movs r0, #2
	ldr r2, [sp, #0x18]
	ands r2, r0
	cmp r2, #0
	beq _08005366
	b _08005554
_08005366:
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	mov r3, r8
	ldr r5, [r3, #0x14]
	adds r4, r5, r4
	ldr r6, [sp, #0x14]
	adds r0, r6, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r5]
	muls r0, r1, r0
	adds r4, r4, r0
	mov sb, r4
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __modsi3
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x10
	str r0, [sp, #0x1c]
	adds r0, r6, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldrb r2, [r4]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	mov r7, r8
	ldr r4, [r7, #0x10]
	adds r2, r4, r2
	ldr r1, [sp, #0x1c]
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r1, r3, #1
	adds r2, r2, r1
	lsrs r7, r0, #0x10
	str r7, [sp, #0x20]
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r5, r2, r1
	movs r7, #0
	movs r0, #0xf
	subs r1, r0, r3
	str r4, [sp, #0x34]
	cmp r7, r1
	bge _08005436
	mov r0, sp
	ldrh r2, [r0, #0x10]
	strh r2, [r0, #0x28]
	ldr r3, [sp, #0x14]
	lsls r6, r3, #2
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r6, r0
	mov r4, r8
	ldr r4, [r4, #0xc]
	mov ip, r4
	mov sl, r1
_080053F0:
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #4
	mov r7, sp
	ldrh r7, [r7, #0x28]
	adds r2, r7, r2
	ldrh r4, [r5]
	lsls r4, r4, #3
	add r4, ip
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r6, r1
	movs r7, #0x80
	lsls r7, r7, #1
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r5, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, sl
	blt _080053F0
_08005436:
	movs r3, #1
	add sb, r3
	mov r4, sb
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [sp, #0x34]
	adds r1, r0, r1
	ldr r2, [sp, #0x20]
	lsls r3, r2, #0x10
	asrs r2, r3, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r5, r1, r0
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	str r3, [sp, #0x30]
	cmp r0, #0x13
	bgt _080054D6
	subs r0, #0xf
	ldr r3, [sp, #0x1c]
	lsls r3, r3, #0x10
	mov ip, r3
	asrs r1, r3, #0x10
	adds r0, r0, r1
	cmp r0, #0xe
	bgt _080054D6
	mov r7, sp
	ldrh r7, [r7, #0x10]
	mov sl, r7
	ldr r0, [sp, #0x14]
	lsls r6, r0, #2
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r6, r0
_08005484:
	asrs r4, r4, #0x10
	lsls r2, r4, #4
	add r2, sl
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, r8
	ldr r3, [r1, #0xc]
	adds r3, r3, r0
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r6, r1
	movs r7, #0x80
	lsls r7, r7, #1
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r5, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	cmp r0, #0x13
	bgt _080054D6
	subs r0, #0xf
	mov r3, ip
	asrs r1, r3, #0x10
	adds r0, r0, r1
	cmp r0, #0xe
	ble _08005484
_080054D6:
	mov r4, sb
	ldrb r1, [r4, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [sp, #0x34]
	adds r1, r0, r1
	ldr r3, [sp, #0x30]
	asrs r2, r3, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r5, r1, r0
	lsls r2, r7, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0x13
	bgt _08005554
	mov r4, sp
	ldrh r4, [r4, #0x10]
	mov sb, r4
	ldr r7, [sp, #0x14]
	lsls r6, r7, #2
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r6, r0
	movs r0, #0x80
	lsls r0, r0, #1
	mov sl, r0
	mov r1, r8
	ldr r1, [r1, #0xc]
	mov ip, r1
_08005518:
	asrs r4, r2, #0x10
	lsls r2, r4, #4
	add r2, sb
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, ip
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r6, r1
	mov r7, sl
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r5, #2
	adds r4, #1
	lsls r2, r4, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0x13
	ble _08005518
_08005554:
	ldr r4, [sp]
	ldr r3, [r4]
	ldr r2, _08005580 @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	mov r7, r8
	strh r0, [r7, #8]
	ldr r1, [r4, #4]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r7, #0xa]
	str r3, [r7]
	str r1, [r7, #4]
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005580: .4byte 0x000001FF

	thumb_func_start FUN_08005584
FUN_08005584: @ 0x08005584
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	mov ip, r2
	movs r1, #0
_08005592:
	movs r3, #0
	lsls r4, r1, #0x10
	asrs r0, r4, #0x10
	lsls r6, r0, #6
	lsls r1, r0, #4
	subs r5, r1, r0
_0800559E:
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	adds r3, r6, r3
	lsls r3, r3, #1
	add r3, r8
	adds r1, r5, r2
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r0, [r0]
	str r0, [r3]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r0, [r0, #4]
	str r0, [r3, #0x40]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xe
	ble _0800559E
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08005592
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080055e8
FUN_080055e8: @ 0x080055E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov ip, r0
	adds r7, r1, #0
	mov r8, r2
	movs r1, #0
_080055F8:
	movs r3, #0
	lsls r4, r1, #0x10
	asrs r0, r4, #0x10
	lsls r6, r0, #6
	lsls r1, r0, #4
	subs r5, r1, r0
_08005604:
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	adds r3, r6, r3
	lsls r3, r3, #1
	add r3, ip
	adds r1, r5, r2
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r0, [r0]
	str r0, [r3]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r0, [r0, #4]
	str r0, [r3, #0x40]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xe
	ble _08005604
	asrs r0, r4, #0x10
	lsls r1, r0, #6
	lsls r2, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	add r1, ip
	movs r2, #0
	str r2, [r1]
	str r2, [r1, #0x40]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _080055F8
	movs r1, #0xa0
	lsls r1, r1, #3
	add r1, ip
	str r2, [sp]
	ldr r2, _08005670 @ =0x010000C0
	mov r0, sp
	bl CpuFastSet
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005670: .4byte 0x010000C0

	thumb_func_start FUN_08005674
FUN_08005674: @ 0x08005674
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	ldr r2, [sp]
	ldr r5, [r2, #0x14]
	adds r4, r5, r4
	ldr r6, [sp, #0x14]
	adds r0, r6, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r5]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #0xc]
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __modsi3
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	adds r0, r6, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldrb r2, [r4]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r7, [sp]
	ldr r3, [r7, #0x10]
	adds r3, r3, r2
	ldr r2, [sp, #0x18]
	lsls r1, r2, #0x10
	asrs r2, r1, #0x10
	lsls r1, r2, #1
	adds r3, r3, r1
	lsrs r7, r0, #0x10
	str r7, [sp, #0x1c]
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r6, r3, r1
	movs r1, #0
	mov ip, r1
	movs r7, #0
	movs r1, #0xa
	subs r1, r1, r0
	cmp ip, r1
	bge _080057A0
	mov r3, sp
	ldrh r7, [r3, #0x14]
	strh r7, [r3, #0x2c]
	movs r0, #0xf
	subs r2, r0, r2
	mov sl, r2
	str r1, [sp, #0x28]
_08005710:
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0xc
	mov r2, sp
	ldrh r2, [r2, #0x2c]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r7, #0
	cmp r7, sl
	bge _0800577E
	mov r3, sp
	ldrh r3, [r3, #0x10]
	mov sb, r3
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r0, [sp]
	ldr r0, [r0, #0xc]
	mov r8, r0
_0800573C:
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #4
	add r2, sb
	ldrh r4, [r6]
	lsls r4, r4, #3
	add r4, r8
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	movs r7, #0x80
	lsls r7, r7, #1
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, sl
	blt _0800573C
_0800577E:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r3, #0xf
	subs r0, r3, r0
	lsls r0, r0, #1
	adds r6, r6, r0
	mov r1, ip
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r3, r0, #0x10
	mov ip, r3
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x28]
	cmp r0, r1
	blt _08005710
_080057A0:
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [sp]
	ldr r3, [r0, #0x10]
	adds r1, r3, r1
	ldr r0, [sp, #0x1c]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r6, r1, r0
	lsls r1, r7, #0x10
	lsrs r7, r1, #0x10
	str r7, [sp, #0x20]
	movs r0, #0
	mov ip, r0
	movs r0, #0xa
	subs r0, r0, r2
	ldr r2, [sp]
	ldr r2, [r2, #0x14]
	str r2, [sp, #0x50]
	str r3, [sp, #0x4c]
	ldr r3, [sp, #0x18]
	lsls r3, r3, #0x10
	str r3, [sp, #0x54]
	adds r2, r1, #0
	cmp ip, r0
	bge _08005894
	mov r7, sp
	ldrh r1, [r7, #0x14]
	strh r1, [r7, #0x34]
	ldr r2, [sp, #0x20]
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #0x38]
	str r0, [sp, #0x30]
_080057F8:
	mov r3, ip
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	mov r7, sp
	ldrh r7, [r7, #0x34]
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r7, [sp, #0x20]
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	cmp r0, #0xf
	bgt _0800586E
	mov r0, sp
	ldrh r0, [r0, #0x10]
	mov sb, r0
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r1, [sp]
	ldr r1, [r1, #0xc]
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #1
	mov sl, r2
_0800582E:
	asrs r4, r4, #0x10
	lsls r2, r4, #4
	add r2, sb
	ldrh r3, [r6]
	lsls r3, r3, #3
	add r3, r8
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	mov r7, sl
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	cmp r0, #0xf
	ble _0800582E
_0800586E:
	lsls r2, r7, #0x10
	asrs r1, r2, #0x10
	ldr r3, [sp, #0x38]
	subs r1, r1, r3
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r6, r6, r0
	mov r7, ip
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r3, r0, #0x10
	mov ip, r3
	asrs r0, r0, #0x10
	ldr r7, [sp, #0x30]
	cmp r0, r7
	blt _080057F8
_08005894:
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	subs r0, #1
	str r0, [sp, #0xc]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x4c]
	adds r0, r7, r0
	ldr r1, [sp, #0x54]
	asrs r3, r1, #0x10
	lsls r1, r3, #1
	adds r6, r0, r1
	mov r7, ip
	str r7, [sp, #0x24]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r5, r0, #0x10
	asrs r0, r5, #0x10
	cmp r0, #0xa
	bgt _0800596E
	mov r0, sp
	ldrh r1, [r0, #0x14]
	strh r1, [r0, #0x3c]
	movs r2, #0xf
	subs r3, r2, r3
	str r3, [sp, #0x48]
_080058D6:
	asrs r0, r5, #0xc
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r7, #0
	mov r0, ip
	lsls r0, r0, #0x10
	mov sl, r0
	ldr r2, [sp, #0x48]
	cmp r7, r2
	bge _0800594E
	mov r3, sp
	ldrh r3, [r3, #0x10]
	mov sb, r3
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r0, [sp]
	ldr r0, [r0, #0xc]
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov ip, r1
_0800590C:
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #4
	add r2, sb
	ldrh r4, [r6]
	lsls r4, r4, #3
	add r4, r8
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	mov r7, ip
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	asrs r3, r3, #0x10
	ldr r0, [sp, #0x48]
	cmp r3, r0
	blt _0800590C
_0800594E:
	lsls r1, r7, #0x10
	asrs r0, r1, #0x10
	movs r2, #0xf
	subs r0, r2, r0
	lsls r0, r0, #1
	adds r6, r6, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r5, r0, #0x10
	asrs r0, r5, #0x10
	adds r2, r1, #0
	cmp r0, #0xa
	ble _080058D6
_0800596E:
	ldr r3, [sp, #0xc]
	ldrb r0, [r3, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x4c]
	adds r6, r7, r0
	lsrs r2, r2, #0x10
	str r2, [sp, #0x20]
	ldr r1, [sp, #0x24]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xa
	bgt _08005A3E
	mov r2, sp
	ldrh r2, [r2, #0x14]
	add r3, sp, #0x40
	strh r2, [r3]
	ldr r7, [sp, #0x20]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #0x44]
_080059A4:
	asrs r0, r1, #0xc
	add r1, sp, #0x40
	ldrh r1, [r1]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r7, [sp, #0x20]
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	mov r2, ip
	lsls r2, r2, #0x10
	mov sl, r2
	cmp r0, #0xf
	bgt _08005A1C
	mov r3, sp
	ldrh r3, [r3, #0x10]
	mov r8, r3
	lsls r0, r1, #0x10
	asrs r5, r0, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r5, r0
	ldr r7, [sp]
	ldr r7, [r7, #0xc]
	mov ip, r7
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
_080059DC:
	asrs r4, r4, #0x10
	lsls r2, r4, #4
	add r2, r8
	ldrh r3, [r6]
	lsls r3, r3, #3
	add r3, ip
	lsls r2, r2, #0x10
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	adds r1, r5, r1
	mov r7, sb
	lsls r0, r7, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #8]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r6, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r4, r7, #0x10
	asrs r0, r4, #0x10
	cmp r0, #0xf
	ble _080059DC
_08005A1C:
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #0x44]
	subs r1, r1, r3
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r6, r6, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xa
	ble _080059A4
_08005A3E:
	ldr r7, [sp, #4]
	ldr r3, [r7]
	ldr r2, _08005A6C @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	ldr r1, [sp]
	strh r0, [r1, #8]
	ldr r1, [r7, #4]
	adds r0, r1, #0
	ands r0, r2
	ldr r2, [sp]
	strh r0, [r2, #0xa]
	str r3, [r2]
	str r1, [r2, #4]
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005A6C: .4byte 0x000001FF

	thumb_func_start FUN_08005a70
FUN_08005a70: @ 0x08005A70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp, #4]
	ldr r0, [r2]
	subs r0, #0x20
	cmp r0, #0
	ble _08005A98
	str r0, [sp, #0x10]
	b _08005A9C
_08005A98:
	movs r3, #0
	str r3, [sp, #0x10]
_08005A9C:
	ldr r1, [sp, #4]
	ldr r0, [r1, #4]
	subs r0, #0x10
	cmp r0, #0
	ble _08005AAA
	str r0, [sp, #0x14]
	b _08005AAE
_08005AAA:
	movs r2, #0
	str r2, [sp, #0x14]
_08005AAE:
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	ldr r3, [sp]
	ldr r6, [r3, #0x14]
	adds r4, r6, r4
	ldr r5, [sp, #0x14]
	adds r0, r5, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r6]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #0xc]
	ldr r0, [sp, #0x10]
	movs r1, #0xf0
	bl __modsi3
	adds r4, r0, #0
	lsls r4, r4, #0xc
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldr r1, [sp, #0xc]
	ldrb r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r1, [sp]
	ldr r3, [r1, #0x10]
	adds r2, r3, r2
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #1
	adds r2, r2, r5
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r7, r2, r1
	movs r2, #0
	mov r8, r2
	movs r1, #0
	str r1, [sp, #0x18]
	mov ip, r1
	str r6, [sp, #0x40]
	str r3, [sp, #0x3c]
	str r0, [sp, #0x20]
	movs r0, #0xa
	ldr r3, [sp, #0x20]
	subs r0, r0, r3
	str r0, [sp, #0x24]
	str r4, [sp, #0x28]
	str r5, [sp, #0x1c]
	movs r0, #0xf
	subs r0, r0, r4
	str r0, [sp, #0x2c]
_08005B32:
	movs r1, #0
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x34]
	lsls r2, r2, #0x10
	str r2, [sp, #0x38]
	asrs r2, r2, #0x10
	mov sb, r2
_08005B42:
	ldr r0, [sp, #0x34]
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	mov r8, r1
	mov r1, sb
	cmp r1, #0
	bne _08005B60
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r3, [sp, #0x24]
	cmp r1, r3
	blt _08005B5E
	b _08005C6E
_08005B5E:
	b _08005B88
_08005B60:
	mov r0, sb
	cmp r0, #1
	bne _08005B7E
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	bgt _08005C6E
	adds r0, r1, #0
	subs r0, #0xa
	ldr r1, [sp, #0x20]
	adds r0, r0, r1
	cmp r0, #9
	bgt _08005C6E
	b _08005B88
_08005B7E:
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	bgt _08005C6E
_08005B88:
	asrs r0, r2, #0xc
	ldr r2, [sp, #0x14]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r3, [sp, #0x18]
	lsls r0, r3, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	str r0, [sp, #0x30]
	mov r2, r8
	cmp r2, #0
	bne _08005BB0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #0x2c]
	cmp r0, r3
	bge _08005C3C
	b _08005BD8
_08005BB0:
	mov r1, r8
	asrs r0, r1, #0x10
	cmp r0, #1
	bne _08005BCE
	mov r2, ip
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _08005C3C
	subs r0, #0xf
	ldr r3, [sp, #0x28]
	adds r0, r0, r3
	cmp r0, #0xe
	bgt _08005C3C
	b _08005BD8
_08005BCE:
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _08005C3C
_08005BD8:
	mov r2, ip
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r2, r4, #4
	ldr r3, [sp, #0x10]
	adds r2, r3, r2
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r1, [sp]
	ldr r5, [r1, #0xc]
	adds r5, r5, r0
	mov r0, sl
	lsls r3, r0, #0x10
	asrs r3, r3, #0xe
	movs r0, #0xf0
	lsls r0, r0, #2
	ands r3, r0
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	asrs r2, r2, #0x13
	movs r0, #0x1e
	ands r2, r0
	adds r3, r3, r2
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r1, r1, #3
	lsls r3, r3, #1
	ldr r2, [sp, #8]
	adds r3, r3, r2
	adds r1, r1, r3
	ldr r0, [r5]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #0x40]
	adds r7, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov ip, r4
	mov r3, r8
	cmp r3, #0
	bne _08005BB0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x2c]
	cmp r0, r1
	blt _08005BD8
_08005C3C:
	mov r2, ip
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #0x30]
	asrs r1, r3, #0x10
	subs r0, r0, r1
	movs r1, #0xf
	subs r0, r1, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	lsls r0, r6, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r6, r0, #0x10
	mov r3, sb
	cmp r3, #0
	beq _08005C62
	b _08005B60
_08005C62:
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r0, [sp, #0x24]
	cmp r1, r0
	blt _08005B88
_08005C6E:
	mov r1, ip
	str r1, [sp, #0x18]
	mov r3, r8
	asrs r0, r3, #0x10
	cmp r0, #2
	beq _08005CC4
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	mov r1, sb
	cmp r1, #0
	bne _08005CA2
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r3, [sp, #0x3c]
	adds r1, r3, r1
	ldr r3, [sp, #0x20]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r7, r1, r0
	b _08005CB4
_08005CA2:
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r3, [sp, #0x3c]
	adds r7, r3, r0
_08005CB4:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08005CC4
	b _08005B42
_08005CC4:
	ldr r0, [sp, #0x38]
	asrs r3, r0, #0x10
	cmp r3, #2
	beq _08005D02
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	ldr r1, [sp, #0xc]
	adds r0, r1, r0
	subs r0, #2
	str r0, [sp, #0xc]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x3c]
	adds r0, r1, r0
	ldr r1, [sp, #0x1c]
	adds r7, r0, r1
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r2, #0
	str r2, [sp, #0x18]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08005D02
	b _08005B32
_08005D02:
	ldr r0, [sp, #4]
	ldr r3, [r0]
	ldr r2, _08005D30 @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	ldr r1, [sp]
	strh r0, [r1, #8]
	ldr r0, [sp, #4]
	ldr r1, [r0, #4]
	adds r0, r1, #0
	ands r0, r2
	ldr r2, [sp]
	strh r0, [r2, #0xa]
	str r3, [r2]
	str r1, [r2, #4]
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005D30: .4byte 0x000001FF

	thumb_func_start FUN_08005d34
FUN_08005d34: @ 0x08005D34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	str r0, [sp]
	adds r6, r1, #0
	str r2, [sp, #4]
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov sb, r0
	movs r1, #0xf
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r4, #4
	ldr r2, [sp]
	ldr r5, [r2, #0x14]
	adds r4, r5, r4
	movs r0, #2
	ldrsh r3, [r6, r0]
	mov r8, r3
	movs r1, #0xa
	mov sl, r1
	mov r0, r8
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r5]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #8]
	mov r0, sb
	movs r1, #0xf
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r0, r8
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	ldrb r2, [r4]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r5, [sp]
	ldr r3, [r5, #0x10]
	adds r3, r3, r2
	ldr r1, [sp, #0xc]
	lsls r4, r1, #0x10
	asrs r5, r4, #0x10
	lsls r1, r5, #1
	adds r3, r3, r1
	lsrs r2, r0, #0x10
	str r2, [sp, #0x10]
	asrs r2, r0, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r7, r3, r0
	movs r3, #0
	mov sb, r3
	mov r8, r3
	mov r0, sl
	subs r0, r0, r2
	cmp sb, r0
	bge _08005EA6
	movs r1, #6
	ldrsh r0, [r6, r1]
	str r4, [sp, #0x40]
	cmp sb, r0
	bge _08005EA6
	str r4, [sp, #0x30]
	movs r3, #0xf
	subs r5, r3, r5
	str r5, [sp, #0x34]
	str r2, [sp, #0x1c]
_08005DE0:
	ldrh r1, [r6, #2]
	lsls r1, r1, #4
	mov r5, sb
	lsls r0, r5, #0x10
	asrs r0, r0, #0xc
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r0, #0
	mov r8, r0
	ldr r1, [sp, #0x34]
	cmp r8, r1
	bge _08005E76
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r8, r0
	bge _08005E76
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r5, [sp, #0x4c]
	ands r5, r0
	str r5, [sp, #0x4c]
	ldr r0, [sp, #0x30]
	asrs r0, r0, #0x10
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sl, r1
_08005E1E:
	ldrh r2, [r6]
	mov r5, r8
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	adds r2, r2, r3
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r1, [sp]
	ldr r4, [r1, #0xc]
	adds r4, r4, r0
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	mov r8, r5
	asrs r1, r3, #0x10
	movs r2, #0xf
	mov r3, ip
	subs r0, r2, r3
	cmp r1, r0
	bge _08005E76
	movs r5, #4
	ldrsh r0, [r6, r5]
	cmp r1, r0
	blt _08005E1E
_08005E76:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r2, #0xf
	subs r0, r2, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r3, sb
	lsls r0, r3, #0x10
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r0, r5
	lsrs r1, r0, #0x10
	mov sb, r1
	asrs r1, r0, #0x10
	movs r0, #0xa
	ldr r2, [sp, #0x1c]
	subs r0, r0, r2
	cmp r1, r0
	bge _08005EA6
	movs r3, #6
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08005DE0
_08005EA6:
	ldr r5, [sp, #8]
	adds r5, #1
	str r5, [sp, #8]
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [sp]
	ldr r3, [r0, #0x10]
	adds r1, r3, r1
	ldr r5, [sp, #0x10]
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r7, r1, r0
	mov r0, r8
	lsls r1, r0, #0x10
	lsrs r5, r1, #0x10
	str r5, [sp, #0x14]
	movs r0, #0
	mov sb, r0
	movs r0, #0xa
	subs r4, r0, r2
	ldr r2, [sp]
	ldr r2, [r2, #0x14]
	str r2, [sp, #0x48]
	str r3, [sp, #0x44]
	ldr r3, [sp, #0xc]
	lsls r3, r3, #0x10
	str r3, [sp, #0x40]
	ldrh r3, [r6, #6]
	adds r2, r1, #0
	cmp sb, r4
	bge _08005FB8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp sb, r0
	bge _08005FB8
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x24]
	str r4, [sp, #0x20]
_08005F02:
	ldrh r1, [r6, #2]
	lsls r1, r1, #4
	mov r5, sb
	lsls r0, r5, #0x10
	asrs r0, r0, #0xc
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	ldr r0, [sp, #0x14]
	mov r8, r0
	lsls r4, r0, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bge _08005F86
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r5, [sp, #0x4c]
	ands r5, r0
	str r5, [sp, #0x4c]
	ldr r0, [sp]
	ldr r0, [r0, #0xc]
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sl, r1
_08005F3E:
	ldrh r2, [r6]
	asrs r4, r4, #0x10
	adds r2, r2, r4
	ldrh r3, [r7]
	lsls r3, r3, #3
	add r3, ip
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r4, r4, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08005F3E
_08005F86:
	mov r5, r8
	lsls r2, r5, #0x10
	asrs r1, r2, #0x10
	ldr r0, [sp, #0x24]
	subs r1, r1, r0
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r1, sb
	lsls r0, r1, #0x10
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r0, r3
	lsrs r5, r0, #0x10
	mov sb, r5
	asrs r1, r0, #0x10
	ldrh r3, [r6, #6]
	ldr r0, [sp, #0x20]
	cmp r1, r0
	bge _08005FB8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _08005F02
_08005FB8:
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r5, [sp, #8]
	adds r0, r5, r0
	subs r0, #1
	str r0, [sp, #8]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x44]
	adds r0, r1, r0
	ldr r5, [sp, #0x40]
	asrs r4, r5, #0x10
	lsls r1, r4, #1
	adds r7, r0, r1
	mov r0, sb
	str r0, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r5, r0, #0x10
	lsls r0, r3, #0x10
	cmp r5, r0
	bge _080060B6
	ldr r1, [sp, #0x40]
	str r1, [sp, #0x38]
	movs r2, #0xf
	subs r4, r2, r4
	str r4, [sp, #0x3c]
_08005FF8:
	ldrh r0, [r6, #2]
	lsls r0, r0, #4
	asrs r1, r5, #0xc
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0
	mov r8, r3
	mov r5, sb
	lsls r5, r5, #0x10
	mov ip, r5
	ldr r0, [sp, #0x3c]
	cmp r8, r0
	bge _08006090
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r8, r0
	bge _08006090
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r2, [sp, #0x4c]
	ands r2, r0
	str r2, [sp, #0x4c]
	ldr r3, [sp, #0x38]
	asrs r3, r3, #0x10
	mov sb, r3
	movs r5, #0x80
	lsls r5, r5, #1
	mov sl, r5
_08006038:
	ldrh r2, [r6]
	mov r0, r8
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	adds r2, r2, r3
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r1, [sp]
	ldr r4, [r1, #0xc]
	adds r4, r4, r0
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r4]
	str r1, [r0]
	ldr r1, [r4, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	mov r8, r5
	asrs r1, r3, #0x10
	movs r2, #0xf
	mov r3, sb
	subs r0, r2, r3
	cmp r1, r0
	bge _08006090
	movs r5, #4
	ldrsh r0, [r6, r5]
	cmp r1, r0
	blt _08006038
_08006090:
	mov r0, r8
	lsls r2, r0, #0x10
	asrs r0, r2, #0x10
	movs r1, #0xf
	subs r0, r1, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r5, r0, #0x10
	asrs r1, r5, #0x10
	movs r3, #6
	ldrsh r0, [r6, r3]
	ldrh r3, [r6, #6]
	cmp r1, r0
	blt _08005FF8
_080060B6:
	ldr r5, [sp, #8]
	ldrb r0, [r5, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x44]
	adds r7, r1, r0
	lsrs r2, r2, #0x10
	str r2, [sp, #0x14]
	ldr r2, [sp, #0x18]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r2, r0, #0x10
	lsls r0, r3, #0x10
	cmp r2, r0
	bge _08006192
	ldr r3, [sp, #0x14]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x28]
_080060E4:
	ldrh r0, [r6, #2]
	lsls r0, r0, #4
	asrs r1, r2, #0xc
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r5, [sp, #0x14]
	mov r8, r5
	lsls r4, r5, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	mov r5, sb
	lsls r5, r5, #0x10
	mov ip, r5
	cmp r1, r0
	bge _0800616A
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	str r0, [sp, #0x4c]
	movs r0, #0xf0
	lsls r0, r0, #2
	ldr r1, [sp, #0x4c]
	ands r1, r0
	str r1, [sp, #0x4c]
	ldr r2, [sp]
	ldr r2, [r2, #0xc]
	mov sb, r2
	movs r3, #0x80
	lsls r3, r3, #1
	mov sl, r3
_08006122:
	ldrh r2, [r6]
	asrs r4, r4, #0x10
	adds r2, r2, r4
	ldrh r3, [r7]
	lsls r3, r3, #3
	add r3, sb
	lsls r2, r2, #0x14
	asrs r1, r2, #0x13
	movs r0, #0x1e
	ands r1, r0
	ldr r5, [sp, #0x4c]
	adds r1, r5, r1
	mov r5, sl
	lsls r0, r5, #0x10
	ands r0, r2
	asrs r0, r0, #0x10
	lsls r0, r0, #3
	lsls r1, r1, #1
	ldr r2, [sp, #4]
	adds r1, r1, r2
	adds r0, r0, r1
	ldr r1, [r3]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #0x40]
	adds r7, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r4, r4, #0x10
	asrs r1, r4, #0x10
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08006122
_0800616A:
	mov r5, r8
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r0, [sp, #0x28]
	subs r1, r1, r0
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r7, r7, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r2, r0, #0x10
	asrs r1, r2, #0x10
	movs r3, #6
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _080060E4
_08006192:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080061a4
FUN_080061a4: @ 0x080061A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp]
	adds r5, r1, #0
	str r2, [sp, #4]
	ldr r0, [sp, #0x60]
	ldr r2, [sp, #0x64]
	ldr r4, [r5]
	ldr r1, [sp]
	str r4, [r1]
	ldr r1, [r5, #4]
	ldr r6, [sp]
	str r1, [r6, #4]
	str r3, [r6, #0xc]
	str r0, [r6, #0x10]
	str r2, [r6, #0x14]
	ldr r2, _080061E4 @ =0x000001FF
	adds r0, r4, #0
	ands r0, r2
	strh r0, [r6, #8]
	ands r1, r2
	strh r1, [r6, #0xa]
	subs r4, #0x10
	cmp r4, #0
	ble _080061E8
	str r4, [sp, #0xc]
	b _080061EC
	.align 2, 0
_080061E4: .4byte 0x000001FF
_080061E8:
	movs r0, #0
	str r0, [sp, #0xc]
_080061EC:
	ldr r0, [r5, #4]
	subs r0, #0x10
	cmp r0, #0
	ble _080061F8
	str r0, [sp, #0x10]
	b _080061FC
_080061F8:
	movs r1, #0
	str r1, [sp, #0x10]
_080061FC:
	ldr r0, [sp, #0xc]
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	ldr r2, [sp]
	ldr r6, [r2, #0x14]
	adds r4, r6, r4
	ldr r5, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r6]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #8]
	ldr r0, [sp, #0xc]
	movs r1, #0xf0
	bl __modsi3
	adds r4, r0, #0
	lsls r4, r4, #0xc
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldr r3, [sp, #8]
	ldrb r2, [r3]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r1, [sp]
	ldr r3, [r1, #0x10]
	adds r2, r3, r2
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #1
	adds r2, r2, r5
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r7, r2, r1
	ldr r2, [sp, #0xc]
	asrs r2, r2, #4
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x10]
	asrs r1, r1, #4
	str r1, [sp, #0x10]
	movs r2, #0
	mov sb, r2
	movs r1, #0
	str r1, [sp, #0x14]
	mov r8, r1
	str r6, [sp, #0x30]
	str r3, [sp, #0x2c]
	str r0, [sp, #0x1c]
	movs r0, #0xa
	ldr r3, [sp, #0x1c]
	subs r0, r0, r3
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	str r5, [sp, #0x18]
	movs r6, #0xf
	subs r4, r6, r4
	str r4, [sp, #0x28]
_0800628C:
	movs r1, #0
	mov r0, sb
	lsls r0, r0, #0x10
	str r0, [sp, #0x38]
	lsls r2, r2, #0x10
	str r2, [sp, #0x3c]
	asrs r2, r2, #0x10
	mov sl, r2
_0800629C:
	ldr r2, [sp, #0x38]
	lsrs r2, r2, #0x10
	mov ip, r2
	lsls r1, r1, #0x10
	mov sb, r1
	mov r3, sl
	cmp r3, #0
	bne _080062BC
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _080062BA
	b _080063D0
_080062BA:
	b _080062EA
_080062BC:
	mov r6, sl
	cmp r6, #1
	bne _080062DE
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	ble _080062D0
	b _080063D0
_080062D0:
	adds r0, r1, #0
	subs r0, #0xa
	ldr r3, [sp, #0x1c]
	adds r0, r0, r3
	cmp r0, #9
	bgt _080063D0
	b _080062EA
_080062DE:
	mov r4, ip
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	bgt _080063D0
_080062EA:
	asrs r0, r2, #0x10
	ldr r1, [sp, #0x10]
	adds r6, r1, r0
	movs r0, #0x1f
	ands r6, r0
	ldr r2, [sp, #0x14]
	lsls r0, r2, #0x10
	lsrs r3, r0, #0x10
	mov r8, r3
	str r0, [sp, #0x34]
	mov r4, sb
	cmp r4, #0
	bne _08006310
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x28]
	cmp r0, r1
	bge _0800639A
	b _08006338
_08006310:
	mov r2, sb
	asrs r0, r2, #0x10
	cmp r0, #1
	bne _0800632E
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800639A
	subs r0, #0xf
	ldr r4, [sp, #0x24]
	adds r0, r0, r4
	cmp r0, #0xe
	bgt _0800639A
	b _08006338
_0800632E:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800639A
_08006338:
	mov r2, r8
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	ldr r3, [sp, #0xc]
	adds r1, r3, r5
	movs r2, #0x1f
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r4, [sp]
	ldr r3, [r4, #0xc]
	adds r3, r3, r0
	ands r1, r2
	lsls r4, r6, #7
	lsls r1, r1, #1
	ldr r0, [sp, #4]
	adds r1, r1, r0
	adds r4, r4, r1
	ldrh r0, [r3]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r4]
	adds r4, #0x40
	ldrh r0, [r3, #4]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #6]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r4]
	adds r7, #2
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r8, r5
	mov r1, sb
	cmp r1, #0
	bne _08006310
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x28]
	cmp r0, r2
	blt _08006338
_0800639A:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r4, [sp, #0x34]
	asrs r1, r4, #0x10
	subs r0, r0, r1
	movs r6, #0xf
	subs r0, r6, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r1, ip
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	mov ip, r0
	mov r3, sl
	cmp r3, #0
	beq _080063C4
	b _080062BC
_080063C4:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _080062EA
_080063D0:
	mov r6, r8
	str r6, [sp, #0x14]
	mov r1, sb
	asrs r0, r1, #0x10
	cmp r0, #2
	beq _08006426
	ldr r3, [sp, #8]
	adds r3, #1
	str r3, [sp, #8]
	mov r4, sl
	cmp r4, #0
	bne _08006404
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r6, [sp, #0x2c]
	adds r1, r6, r1
	ldr r3, [sp, #0x1c]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r7, r1, r0
	b _08006416
_08006404:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r6, [sp, #0x2c]
	adds r7, r6, r0
_08006416:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08006426
	b _0800629C
_08006426:
	ldr r0, [sp, #0x3c]
	asrs r3, r0, #0x10
	cmp r3, #2
	beq _08006464
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r4, [sp, #8]
	adds r0, r4, r0
	subs r0, #2
	str r0, [sp, #8]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r6, [sp, #0x2c]
	adds r0, r6, r0
	ldr r1, [sp, #0x18]
	adds r7, r0, r1
	lsrs r2, r2, #0x10
	mov sb, r2
	movs r2, #0
	str r2, [sp, #0x14]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08006464
	b _0800628C
_08006464:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08006474
FUN_08006474: @ 0x08006474
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp]
	adds r4, r1, #0
	str r2, [sp, #4]
	ldr r2, [r4]
	str r2, [r0]
	ldr r1, [r4, #4]
	ldr r0, [sp]
	str r1, [r0, #4]
	ldr r3, _080064A8 @ =0x000001FF
	adds r0, r2, #0
	ands r0, r3
	ldr r5, [sp]
	strh r0, [r5, #8]
	ands r1, r3
	strh r1, [r5, #0xa]
	subs r2, #0x10
	cmp r2, #0
	ble _080064AC
	str r2, [sp, #0xc]
	b _080064B0
	.align 2, 0
_080064A8: .4byte 0x000001FF
_080064AC:
	movs r0, #0
	str r0, [sp, #0xc]
_080064B0:
	ldr r0, [r4, #4]
	subs r0, #0x10
	cmp r0, #0
	ble _080064BC
	str r0, [sp, #0x10]
	b _080064C0
_080064BC:
	movs r1, #0
	str r1, [sp, #0x10]
_080064C0:
	ldr r0, [sp, #0xc]
	movs r1, #0xf0
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	ldr r2, [sp]
	ldr r6, [r2, #0x14]
	adds r4, r6, r4
	ldr r5, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #0xa0
	bl __divsi3
	ldrb r1, [r6]
	muls r0, r1, r0
	adds r4, r4, r0
	str r4, [sp, #8]
	ldr r0, [sp, #0xc]
	movs r1, #0xf0
	bl __modsi3
	adds r4, r0, #0
	lsls r4, r4, #0xc
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0xc
	ldr r3, [sp, #8]
	ldrb r2, [r3]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r5, [sp]
	ldr r3, [r5, #0x10]
	adds r2, r3, r2
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #1
	adds r2, r2, r5
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r7, r2, r1
	ldr r1, [sp, #0xc]
	asrs r1, r1, #4
	str r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	asrs r2, r2, #4
	str r2, [sp, #0x10]
	movs r1, #0
	mov sb, r1
	movs r2, #0
	str r2, [sp, #0x14]
	mov r8, r2
	str r6, [sp, #0x3c]
	str r3, [sp, #0x38]
	str r0, [sp, #0x1c]
	movs r0, #0xa
	ldr r3, [sp, #0x1c]
	subs r0, r0, r3
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	str r5, [sp, #0x18]
	movs r5, #0xf
	subs r4, r5, r4
	str r4, [sp, #0x28]
_08006550:
	movs r1, #0
	mov r0, sb
	lsls r0, r0, #0x10
	str r0, [sp, #0x30]
	lsls r2, r2, #0x10
	str r2, [sp, #0x34]
	asrs r2, r2, #0x10
	mov sl, r2
_08006560:
	ldr r2, [sp, #0x30]
	lsrs r2, r2, #0x10
	mov ip, r2
	lsls r1, r1, #0x10
	mov sb, r1
	mov r3, sl
	cmp r3, #0
	bne _08006580
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _0800657E
	b _08006694
_0800657E:
	b _080065AE
_08006580:
	mov r5, sl
	cmp r5, #1
	bne _080065A2
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	ble _08006594
	b _08006694
_08006594:
	adds r0, r1, #0
	subs r0, #0xa
	ldr r3, [sp, #0x1c]
	adds r0, r0, r3
	cmp r0, #9
	bgt _08006694
	b _080065AE
_080065A2:
	mov r4, ip
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	cmp r1, #0xc
	bgt _08006694
_080065AE:
	asrs r0, r2, #0x10
	ldr r5, [sp, #0x10]
	adds r6, r5, r0
	movs r0, #0x1f
	ands r6, r0
	ldr r1, [sp, #0x14]
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	mov r8, r2
	str r0, [sp, #0x2c]
	mov r3, sb
	cmp r3, #0
	bne _080065D4
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldr r4, [sp, #0x28]
	cmp r0, r4
	bge _0800665E
	b _080065FC
_080065D4:
	mov r5, sb
	asrs r0, r5, #0x10
	cmp r0, #1
	bne _080065F2
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800665E
	subs r0, #0xf
	ldr r2, [sp, #0x24]
	adds r0, r0, r2
	cmp r0, #0xe
	bgt _0800665E
	b _080065FC
_080065F2:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	bgt _0800665E
_080065FC:
	mov r4, r8
	lsls r5, r4, #0x10
	asrs r5, r5, #0x10
	ldr r0, [sp, #0xc]
	adds r1, r0, r5
	movs r2, #0x1f
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r4, [sp]
	ldr r3, [r4, #0xc]
	adds r3, r3, r0
	ands r1, r2
	lsls r4, r6, #7
	lsls r1, r1, #1
	ldr r0, [sp, #4]
	adds r1, r1, r0
	adds r4, r4, r1
	ldrh r0, [r3]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r4]
	adds r4, #0x40
	ldrh r0, [r3, #4]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #6]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r4]
	adds r7, #2
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r8, r5
	mov r1, sb
	cmp r1, #0
	bne _080065D4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x28]
	cmp r0, r2
	blt _080065FC
_0800665E:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r4, [sp, #0x2c]
	asrs r1, r4, #0x10
	subs r0, r0, r1
	movs r5, #0xf
	subs r0, r5, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	mov r1, ip
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	mov ip, r0
	mov r3, sl
	cmp r3, #0
	beq _08006688
	b _08006580
_08006688:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	adds r2, r0, #0
	ldr r4, [sp, #0x20]
	cmp r1, r4
	blt _080065AE
_08006694:
	mov r5, r8
	str r5, [sp, #0x14]
	mov r1, sb
	asrs r0, r1, #0x10
	cmp r0, #2
	beq _080066EA
	ldr r3, [sp, #8]
	adds r3, #1
	str r3, [sp, #8]
	mov r4, sl
	cmp r4, #0
	bne _080066C8
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r5, [sp, #0x38]
	adds r1, r5, r1
	ldr r3, [sp, #0x1c]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r7, r1, r0
	b _080066DA
_080066C8:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r5, [sp, #0x38]
	adds r7, r5, r0
_080066DA:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _080066EA
	b _08006560
_080066EA:
	ldr r0, [sp, #0x34]
	asrs r3, r0, #0x10
	cmp r3, #2
	beq _08006728
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	ldr r4, [sp, #8]
	adds r0, r4, r0
	subs r0, #2
	str r0, [sp, #8]
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r5, [sp, #0x38]
	adds r0, r5, r0
	ldr r1, [sp, #0x18]
	adds r7, r0, r1
	lsrs r2, r2, #0x10
	mov sb, r2
	movs r2, #0
	str r2, [sp, #0x14]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08006728
	b _08006550
_08006728:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08006738
FUN_08006738: @ 0x08006738
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	str r0, [sp]
	mov r8, r1
	str r2, [sp, #4]
	ldr r6, [sp, #0x60]
	ldr r5, [sp, #0x64]
	str r3, [r0, #0xc]
	ldr r0, [sp]
	str r6, [r0, #0x10]
	str r5, [r0, #0x14]
	ldr r1, [r1]
	mov sb, r1
	mov r0, sb
	movs r1, #0xf
	bl __divsi3
	adds r4, r0, #0
	adds r4, #4
	adds r4, r5, r4
	mov r2, r8
	ldr r2, [r2, #4]
	mov r8, r2
	mov r0, r8
	movs r1, #0xa
	bl __divsi3
	ldrb r1, [r5]
	muls r0, r1, r0
	adds r4, r4, r0
	mov sl, r4
	mov r3, sl
	str r3, [sp, #8]
	mov r0, sb
	movs r1, #0xf
	bl __modsi3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, r8
	movs r1, #0xa
	bl __modsi3
	mov r2, sl
	ldrb r1, [r2]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r6, r6, r1
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r2, r4, #1
	adds r6, r6, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r7, r6, r1
	movs r1, #0
	movs r3, #0
	str r3, [sp, #0xc]
	movs r5, #0
	str r0, [sp, #0x28]
	movs r0, #0xa
	ldr r6, [sp, #0x28]
	subs r0, r0, r6
	str r0, [sp, #0x2c]
	subs r6, #0x14
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x28]
	subs r0, #0x1e
	str r0, [sp, #0x14]
	str r4, [sp, #0x30]
	adds r6, r4, #0
	subs r6, #0x1e
	str r6, [sp, #0x18]
	str r2, [sp, #0x1c]
	movs r0, #0xf
	subs r0, r0, r4
	str r0, [sp, #0x34]
_080067E8:
	movs r2, #0
	lsls r1, r1, #0x10
	str r1, [sp, #0x38]
	lsls r3, r3, #0x10
	str r3, [sp, #0x3c]
	str r3, [sp, #0x20]
	asrs r1, r3, #0x10
	str r1, [sp, #0x24]
_080067F8:
	ldr r3, [sp, #0x38]
	lsrs r6, r3, #0x10
	lsls r2, r2, #0x10
	mov sb, r2
	ldr r0, [sp, #0x24]
	cmp r0, #0
	bne _08006816
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	ldr r2, [sp, #0x2c]
	cmp r1, r2
	blt _08006814
	b _08006936
_08006814:
	b _08006862
_08006816:
	ldr r3, [sp, #0x20]
	asrs r0, r3, #0x10
	cmp r0, #1
	bne _0800682C
	lsls r1, r6, #0x10
	asrs r0, r1, #0x10
	subs r0, #0xa
	ldr r2, [sp, #0x28]
	adds r0, r0, r2
	mov r8, r1
	b _08006852
_0800682C:
	cmp r0, #2
	bne _08006840
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x1f
	bgt _08006936
	ldr r3, [sp, #0x10]
	adds r0, r1, r3
	b _08006852
_08006840:
	cmp r0, #3
	bne _08006858
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x1f
	bgt _08006936
	ldr r2, [sp, #0x14]
	adds r0, r1, r2
_08006852:
	cmp r0, #9
	bgt _08006936
	b _08006862
_08006858:
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x1f
	bgt _08006936
_08006862:
	ldr r3, [sp, #0xc]
	lsls r0, r3, #0x10
	lsrs r5, r0, #0x10
	mov ip, r0
	mov r0, sb
	cmp r0, #0
	bne _0800687C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x34]
	cmp r0, r1
	bge _08006906
	b _080068AE
_0800687C:
	mov r2, sb
	asrs r0, r2, #0x10
	cmp r0, #1
	bne _08006890
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	subs r0, #0xf
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	b _080068A0
_08006890:
	cmp r0, #2
	bne _080068A6
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _08006906
	ldr r1, [sp, #0x18]
	adds r0, r0, r1
_080068A0:
	cmp r0, #0xe
	bgt _08006906
	b _080068AE
_080068A6:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _08006906
_080068AE:
	ldrh r0, [r7]
	lsls r0, r0, #3
	ldr r2, [sp]
	ldr r3, [r2, #0xc]
	adds r3, r3, r0
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	mov r0, r8
	asrs r5, r0, #9
	lsls r0, r4, #1
	ldr r1, [sp, #4]
	adds r0, r0, r1
	adds r5, r5, r0
	ldrh r0, [r3]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5]
	adds r5, #0x40
	ldrh r0, [r3, #4]
	movs r1, #0xff
	ands r1, r0
	ldrh r2, [r3, #6]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5]
	adds r7, #2
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	mov r2, sb
	cmp r2, #0
	bne _0800687C
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #0x34]
	cmp r0, r3
	blt _080068AE
_08006906:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	mov r2, ip
	asrs r1, r2, #0x10
	subs r0, r0, r1
	movs r3, #0xf
	subs r0, r3, r0
	lsls r0, r0, #1
	adds r7, r7, r0
	lsls r0, r6, #0x10
	movs r6, #0x80
	lsls r6, r6, #9
	adds r0, r0, r6
	lsrs r6, r0, #0x10
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _0800692A
	b _08006816
_0800692A:
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	ldr r2, [sp, #0x2c]
	cmp r1, r2
	blt _08006862
_08006936:
	str r5, [sp, #0xc]
	mov r3, sb
	asrs r0, r3, #0x10
	cmp r0, #3
	beq _0800698C
	movs r6, #1
	add sl, r6
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _08006968
	mov r1, sl
	ldrb r0, [r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, [sp]
	ldr r1, [r2, #0x10]
	adds r1, r1, r0
	ldr r3, [sp, #0x28]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #1
	b _0800697A
_08006968:
	mov r6, sl
	ldrb r0, [r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, [sp]
	ldr r1, [r2, #0x10]
_0800697A:
	adds r7, r1, r0
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _0800698C
	b _080067F8
_0800698C:
	ldr r3, [sp, #0x3c]
	asrs r2, r3, #0x10
	cmp r2, #4
	beq _080069CE
	ldr r6, [sp]
	ldr r0, [r6, #0x14]
	ldrb r0, [r0]
	ldr r1, [sp, #8]
	adds r1, r1, r0
	mov sl, r1
	mov r3, sl
	str r3, [sp, #8]
	ldrb r1, [r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r6, #0x10]
	adds r0, r0, r1
	ldr r6, [sp, #0x1c]
	adds r7, r0, r6
	mov r0, r8
	lsrs r1, r0, #0x10
	movs r3, #0
	str r3, [sp, #0xc]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _080069CE
	b _080067E8
_080069CE:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080069e0
FUN_080069e0: @ 0x080069E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r2, r2, #0x10
	movs r3, #0
	lsrs r2, r2, #0xd
	adds r2, r2, r1
	ldr r5, [r2]
	ldr r4, [r2, #4]
_080069F0:
	lsls r0, r3, #7
	adds r2, r3, #1
	adds r0, r0, r6
	movs r1, #0xf
_080069F8:
	str r5, [r0]
	str r4, [r0, #0x40]
	adds r0, #4
	subs r1, #1
	cmp r1, #0
	bge _080069F8
	adds r3, r2, #0
	cmp r3, #0xf
	ble _080069F0
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08006a10
FUN_08006a10: @ 0x08006A10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov sb, r1
	str r2, [sp]
	ldr r1, [r1]
	asrs r1, r1, #4
	adds r5, r1, #0
	mov r2, sb
	ldr r0, [r2, #4]
	asrs r6, r0, #4
	lsls r1, r1, #1
	adds r1, #4
	adds r1, r3, r1
	ldrh r2, [r3]
	adds r0, r2, #0
	muls r0, r6, r0
	lsls r0, r0, #1
	adds r4, r1, r0
	movs r1, #0
	mov r3, sl
	ldr r3, [r3, #0xc]
	mov ip, r3
	lsls r2, r2, #1
	str r2, [sp, #4]
_08006A4A:
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	adds r0, r0, r6
	movs r2, #0xf
	ands r0, r2
	lsls r0, r0, #7
	ldr r3, [sp]
	adds r7, r3, r0
	movs r0, #0
	mov r8, r1
_08006A5E:
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	adds r1, r3, r5
	adds r2, r1, #0
	movs r0, #0xf
	ands r2, r0
	lsls r2, r2, #2
	adds r2, r7, r2
	movs r0, #0x10
	ands r1, r0
	lsls r1, r1, #7
	adds r2, r2, r1
	ldrh r0, [r4]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0]
	str r0, [r2]
	ldrh r0, [r4]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0, #4]
	str r0, [r2, #0x40]
	adds r4, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _08006A5E
	ldr r1, [sp, #4]
	adds r0, r4, r1
	adds r4, r0, #0
	subs r4, #0x20
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble _08006A4A
	mov r2, sb
	ldr r3, [r2]
	ldr r2, _08006ADC @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	mov r1, sl
	strh r0, [r1, #8]
	mov r0, sb
	ldr r1, [r0, #4]
	adds r0, r1, #0
	ands r0, r2
	mov r2, sl
	strh r0, [r2, #0xa]
	str r3, [r2]
	str r1, [r2, #4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006ADC: .4byte 0x000001FF

	thumb_func_start FUN_08006ae0
FUN_08006ae0: @ 0x08006AE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov sb, r1
	str r2, [sp]
	ldr r2, [r1]
	adds r0, r2, #0
	subs r0, #0x10
	ldr r1, [r1, #4]
	adds r5, r1, #0
	subs r5, #0x10
	asrs r0, r2, #4
	adds r4, r0, #0
	asrs r5, r1, #4
	lsls r0, r0, #1
	adds r0, #4
	adds r0, r3, r0
	ldrh r2, [r3]
	adds r1, r2, #0
	muls r1, r5, r1
	lsls r1, r1, #1
	adds r6, r0, r1
	movs r1, #0
	mov r0, sl
	ldr r0, [r0, #0xc]
	mov ip, r0
	lsls r2, r2, #1
	str r2, [sp, #4]
_08006B20:
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	adds r0, r0, r5
	movs r2, #0xf
	ands r0, r2
	lsls r0, r0, #7
	ldr r3, [sp]
	adds r7, r3, r0
	movs r0, #0
	mov r8, r1
_08006B34:
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	adds r1, r3, r4
	adds r2, r1, #0
	movs r0, #0xf
	ands r2, r0
	lsls r2, r2, #2
	adds r2, r7, r2
	movs r0, #0x10
	ands r1, r0
	lsls r1, r1, #7
	adds r2, r2, r1
	ldrh r0, [r6]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0]
	str r0, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0, #4]
	str r0, [r2, #0x40]
	adds r6, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0x11
	ble _08006B34
	ldr r1, [sp, #4]
	adds r0, r6, r1
	adds r6, r0, #0
	subs r6, #0x24
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _08006B20
	mov r2, sb
	ldr r3, [r2]
	ldr r2, _08006BB0 @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	mov r6, sl
	strh r0, [r6, #8]
	mov r0, sb
	ldr r1, [r0, #4]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r6, #0xa]
	str r3, [r6]
	str r1, [r6, #4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006BB0: .4byte 0x000001FF

	thumb_func_start FUN_08006bb4
FUN_08006bb4: @ 0x08006BB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r0
	str r1, [sp]
	str r2, [sp, #4]
	mov sl, r3
	movs r0, #0
	mov sb, r0
	ldr r3, [r1]
	movs r2, #0x10
	adds r1, r3, #0
	ands r1, r2
	mov r7, r8
	ldr r4, [r7]
	adds r0, r4, #0
	ands r0, r2
	cmp r1, r0
	beq _08006BF8
	cmp r3, r4
	ble _08006BEC
	adds r0, r3, #0
	adds r0, #0xf0
	asrs r5, r0, #4
	b _08006BEE
_08006BEC:
	asrs r5, r3, #4
_08006BEE:
	ldr r1, [sp]
	ldr r0, [r1, #4]
	asrs r6, r0, #4
	adds r4, r0, #0
	b _08006C00
_08006BF8:
	movs r2, #1
	mov sb, r2
	ldr r7, [sp]
	ldr r4, [r7, #4]
_08006C00:
	adds r3, r4, #0
	movs r2, #0x10
	adds r1, r3, #0
	ands r1, r2
	mov r0, r8
	ldr r7, [r0, #4]
	adds r0, r7, #0
	ands r0, r2
	cmp r1, r0
	beq _08006C30
	cmp r3, r7
	ble _08006C22
	adds r0, r3, #0
	adds r0, #0xa0
	asrs r0, r0, #4
	str r0, [sp, #0xc]
	b _08006C26
_08006C22:
	asrs r4, r4, #4
	str r4, [sp, #0xc]
_08006C26:
	ldr r1, [sp]
	ldr r0, [r1]
	asrs r0, r0, #4
	str r0, [sp, #8]
	b _08006C38
_08006C30:
	movs r0, #2
	mov r2, sb
	orrs r2, r0
	mov sb, r2
_08006C38:
	movs r0, #1
	mov r7, sb
	ands r0, r7
	cmp r0, #0
	bne _08006CA8
	adds r2, r5, #0
	lsls r1, r2, #1
	adds r1, #4
	add r1, sl
	mov r0, sl
	ldrh r3, [r0]
	adds r0, r3, #0
	muls r0, r6, r0
	lsls r0, r0, #1
	adds r4, r1, r0
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r0, r1, r0
	movs r1, #0x10
	ands r2, r1
	lsls r2, r2, #7
	adds r0, r0, r2
	mov ip, r0
	movs r0, #0
	mov r2, r8
	ldr r2, [r2, #0xc]
	str r2, [sp, #0x10]
	lsls r3, r3, #1
_08006C74:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r2, r6
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #7
	mov r7, ip
	adds r1, r7, r0
	ldrh r0, [r4]
	lsls r0, r0, #3
	ldr r7, [sp, #0x10]
	adds r0, r0, r7
	ldr r0, [r0]
	str r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r0, [r0, #4]
	str r0, [r1, #0x40]
	adds r4, r4, r3
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xa
	ble _08006C74
_08006CA8:
	movs r0, #2
	mov r1, sb
	ands r1, r0
	cmp r1, #0
	bne _08006D12
	ldr r2, [sp, #8]
	lsls r1, r2, #1
	adds r1, #4
	add r1, sl
	mov r7, sl
	ldrh r0, [r7]
	ldr r2, [sp, #0xc]
	muls r0, r2, r0
	lsls r0, r0, #1
	adds r4, r1, r0
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #7
	ldr r7, [sp, #4]
	adds r7, r7, r0
	mov ip, r7
	movs r0, #0
	mov r1, r8
	ldr r5, [r1, #0xc]
_08006CD8:
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	ldr r7, [sp, #8]
	adds r2, r3, r7
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #2
	add r0, ip
	movs r1, #0x10
	ands r2, r1
	lsls r2, r2, #7
	adds r1, r0, r2
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r0, [r0, #4]
	str r0, [r1, #0x40]
	adds r4, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _08006CD8
_08006D12:
	ldr r0, [sp]
	ldr r3, [r0]
	ldr r2, _08006D40 @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	mov r1, r8
	strh r0, [r1, #8]
	ldr r7, [sp]
	ldr r1, [r7, #4]
	adds r0, r1, #0
	ands r0, r2
	mov r2, r8
	strh r0, [r2, #0xa]
	str r3, [r2]
	str r1, [r2, #4]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006D40: .4byte 0x000001FF

	thumb_func_start FUN_08006d44
FUN_08006d44: @ 0x08006D44
	push {lr}
	sub sp, #8
	adds r1, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _08006D5C @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08006D5C: .4byte 0x01000200

	thumb_func_start FastCopy
FastCopy: @ 0x08006D60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r5, #0x20
	rsbs r5, r5, #0
	ands r5, r4
	lsrs r2, r5, #2
	ldr r0, _08006DA8 @ =0x001FFFFF
	mov r8, r0
	ands r2, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl CpuFastSet
	movs r2, #0x1f
	ands r2, r4
	cmp r2, #0
	beq _08006D9E
	adds r0, r6, r5
	adds r1, r7, r5
	lsrs r2, r2, #2
	mov r3, r8
	ands r2, r3
	movs r3, #0x80
	lsls r3, r3, #0x13
	orrs r2, r3
	bl CpuSet
_08006D9E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006DA8: .4byte 0x001FFFFF

	thumb_func_start FUN_08006dac
FUN_08006dac: @ 0x08006DAC
	ldrh r2, [r0, #8]
	strh r2, [r1]
	ldrh r0, [r0, #0xa]
	strh r0, [r1, #2]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08006db8
FUN_08006db8: @ 0x08006DB8
	push {r4, lr}
	ldr r4, [sp, #8]
	str r1, [r0]
	str r2, [r0, #4]
	str r3, [r0, #8]
	str r4, [r0, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006dcc
FUN_08006dcc: @ 0x08006DCC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, [r4]
	mov r8, r0
	movs r1, #0xf0
	bl __divsi3
	adds r5, r0, #0
	ldr r4, [r4, #4]
	mov sb, r4
	mov r0, sb
	movs r1, #0xa0
	bl __divsi3
	ldr r2, [r6, #0xc]
	ldrb r1, [r2]
	muls r0, r1, r0
	adds r0, r0, r5
	adds r0, r0, r2
	ldrb r5, [r0, #4]
	mov r0, r8
	movs r1, #0xf0
	bl __modsi3
	adds r4, r0, #0
	asrs r4, r4, #4
	mov r0, sb
	movs r1, #0xa0
	bl __modsi3
	asrs r0, r0, #4
	lsls r1, r0, #4
	subs r1, r1, r0
	movs r0, #0x96
	muls r0, r5, r0
	adds r0, r0, r4
	adds r1, r1, r0
	ldr r0, [r6, #8]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r1, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08006e3c
FUN_08006e3c: @ 0x08006E3C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov sb, r2
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	mov r0, sb
	movs r1, #0xa
	bl __udivsi3
	ldr r2, [r5, #0xc]
	ldrb r1, [r2]
	muls r0, r1, r0
	adds r0, r0, r4
	adds r0, r0, r2
	ldrb r0, [r0, #4]
	mov r8, r0
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	adds r4, r0, #0
	mov r0, sb
	movs r1, #0xa
	bl __umodsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	movs r0, #0x96
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r0, r4
	adds r1, r1, r0
	ldr r0, [r5, #8]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r1, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08006ea8
FUN_08006ea8: @ 0x08006EA8
	push {r4, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r4, r3, #4
	subs r4, r4, r3
	movs r3, #0x96
	muls r1, r3, r1
	adds r1, r1, r2
	adds r4, r4, r1
	ldr r1, [r0, #8]
	lsls r4, r4, #1
	adds r4, r4, r1
	ldrh r1, [r4]
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
