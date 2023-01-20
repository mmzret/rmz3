	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initSunkenLib
initSunkenLib: @ 0x08013484
	push {lr}
	ldr r1, _080134C4 @ =0x02002200
	ldr r2, _080134C8 @ =0x0002D024
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _080134CC @ =0x0002D028
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r2, [r0]
	subs r3, #6
	adds r0, r1, r3
	str r2, [r0]
	ldr r0, _080134D0 @ =0x0002C00C
	adds r1, r1, r0
	movs r0, #0x8e
	lsls r0, r0, #0xa
	str r0, [r1]
	movs r0, #0x96
	movs r1, #0
	bl loadBlink
	pop {r0}
	bx r0
	.align 2, 0
_080134C4: .4byte 0x02002200
_080134C8: .4byte 0x0002D024
_080134CC: .4byte 0x0002D028
_080134D0: .4byte 0x0002C00C

	thumb_func_start FUN_080134d4
FUN_080134d4: @ 0x080134D4
	push {r4, lr}
	ldr r2, _08013520 @ =0x02002200
	ldr r1, _08013524 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xd
	bne _0801352C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _0801352C
	ldr r3, _08013528 @ =0x0002D028
	adds r2, r2, r3
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08013510
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x94
	movs r1, #0
	bl loadBlink
	movs r0, #0x95
	movs r1, #0
	bl loadBlink
_08013510:
	movs r0, #0x94
	bl FUN_08004068
	movs r0, #0x95
	bl FUN_08004068
	b _0801354E
	.align 2, 0
_08013520: .4byte 0x02002200
_08013524: .4byte 0x000007D4
_08013528: .4byte 0x0002D028
_0801352C:
	ldr r0, _08013588 @ =0x02002200
	ldr r1, _0801358C @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801354E
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x94
	bl clearBlink
	movs r0, #0x95
	bl clearBlink
_0801354E:
	ldr r2, _08013588 @ =0x02002200
	ldr r3, _08013590 @ =0x000007D6
	adds r0, r2, r3
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xd
	bne _08013594
	movs r0, #0xff
	ands r0, r1
	cmp r0, #5
	bne _08013594
	ldr r0, _0801358C @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08013580
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x99
	movs r1, #0
	bl loadBlink
_08013580:
	movs r0, #0x99
	bl FUN_08004068
	b _080135B0
	.align 2, 0
_08013588: .4byte 0x02002200
_0801358C: .4byte 0x0002D028
_08013590: .4byte 0x000007D6
_08013594:
	ldr r0, _080135F0 @ =0x02002200
	ldr r1, _080135F4 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080135B0
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x99
	bl clearBlink
_080135B0:
	movs r0, #0x96
	bl FUN_08004068
	ldr r2, _080135F0 @ =0x02002200
	ldr r3, _080135F8 @ =0x0002D029
	adds r4, r2, r3
	ldrb r1, [r4]
	cmp r1, #0
	bne _08013632
	ldr r0, _080135FC @ =0x0002D02A
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, #0
	bne _0801360C
	ldr r1, _08013600 @ =0x0002D02C
	adds r2, r2, r1
	ldr r1, [r2]
	ldr r0, _08013604 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013608 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	adds r0, #1
	strb r0, [r3]
	movs r0, #8
	b _08013630
	.align 2, 0
_080135F0: .4byte 0x02002200
_080135F4: .4byte 0x0002D028
_080135F8: .4byte 0x0002D029
_080135FC: .4byte 0x0002D02A
_08013600: .4byte 0x0002D02C
_08013604: .4byte 0x000343FD
_08013608: .4byte 0x00269EC3
_0801360C:
	strb r1, [r3]
	ldr r3, _08013678 @ =0x0002D02C
	adds r2, r2, r3
	ldr r1, [r2]
	ldr r0, _0801367C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013680 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x3a
	bl __umodsi3
	movs r1, #0xf8
	ands r0, r1
	adds r0, #7
_08013630:
	strb r0, [r4]
_08013632:
	ldr r2, _08013684 @ =0x02002200
	ldr r3, _08013688 @ =0x0002D029
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, _0801368C @ =0x0002D032
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08013690 @ =0x0002C00C
	adds r2, r2, r1
	ldr r1, _08013694 @ =0x080FEA74
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x8e
	lsls r1, r1, #0xa
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _08013698 @ =0x02002180
	ldr r0, _0801369C @ =0x00000C04
	strh r0, [r1, #2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013678: .4byte 0x0002D02C
_0801367C: .4byte 0x000343FD
_08013680: .4byte 0x00269EC3
_08013684: .4byte 0x02002200
_08013688: .4byte 0x0002D029
_0801368C: .4byte 0x0002D032
_08013690: .4byte 0x0002C00C
_08013694: .4byte 0x080FEA74
_08013698: .4byte 0x02002180
_0801369C: .4byte 0x00000C04

	thumb_func_start FUN_080136a0
FUN_080136a0: @ 0x080136A0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r5, _08013710 @ =0x02002200
	ldr r1, _08013714 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xd
	bne _08013768
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _08013768
	ldr r2, _08013718 @ =0x0002D02A
	adds r6, r5, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _08013724
	ldr r4, _0801371C @ =0x087044F8
	adds r2, r0, #0
	lsls r2, r2, #1
	ldr r0, _08013720 @ =0x0002D029
	adds r5, r5, r0
	ldrb r0, [r5]
	lsrs r0, r0, #2
	adds r0, #0x48
	adds r2, r2, r0
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrb r2, [r6]
	lsls r2, r2, #1
	ldrb r0, [r5]
	lsrs r0, r0, #2
	adds r0, #0x48
	adds r2, r2, r0
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	b _08013768
	.align 2, 0
_08013710: .4byte 0x02002200
_08013714: .4byte 0x000007D4
_08013718: .4byte 0x0002D02A
_0801371C: .4byte 0x087044F8
_08013720: .4byte 0x0002D029
_08013724:
	ldr r1, _08013774 @ =0x087044F8
	mov r8, r1
	ldr r2, _08013778 @ =0x0002D029
	adds r6, r5, r2
	ldrb r0, [r6]
	lsrs r0, r0, #2
	movs r5, #1
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0801377C @ =0x08704A98
	adds r1, r1, r4
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrb r0, [r6]
	lsrs r0, r0, #2
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_08013768:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013774: .4byte 0x087044F8
_08013778: .4byte 0x0002D029
_0801377C: .4byte 0x08704A98

	thumb_func_start exitSunkenLibrary
exitSunkenLibrary: @ 0x08013780
	push {lr}
	ldr r0, _080137B8 @ =0x02002200
	ldr r1, _080137BC @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
	str r1, [r0]
	movs r0, #0x94
	bl clearBlink
	movs r0, #0x95
	bl clearBlink
	movs r0, #0x96
	bl clearBlink
	movs r0, #0x97
	bl clearBlink
	movs r0, #0x98
	bl clearBlink
	movs r0, #0x99
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0
_080137B8: .4byte 0x02002200
_080137BC: .4byte 0x0002C00C

	thumb_func_start sunkenlib_080137c0
sunkenlib_080137c0: @ 0x080137C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	mov r8, r0
	cmp r0, #0
	bne _08013860
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _0801386C @ =0x02002144
	adds r5, r5, r3
	ldr r1, [r7, #0x60]
	ldr r2, [r7, #0x64]
	orrs r1, r2
	ldr r4, _08013870 @ =0x00008044
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	mov r2, r8
	str r2, [r0]
	ldr r0, _08013874 @ =0x085223AC
	ldr r0, [r0]
	ldr r3, _08013878 @ =0x085223B4
	adds r0, r0, r3
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldr r0, _0801387C @ =0x085223B0
	ldr r0, [r0]
	ldr r1, _08013880 @ =0x085223B8
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _08013884 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	ldr r1, _08013888 @ =0x02002180
	ldr r0, _0801388C @ =0x00003B44
	strh r0, [r1]
	ldr r0, _08013890 @ =0x00000C04
	strh r0, [r1, #2]
	ldr r1, _08013894 @ =0x02002190
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xf3
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	movs r0, #0xff
	strh r0, [r1, #6]
	mov r4, r8
	strh r4, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08013860:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801386C: .4byte 0x02002144
_08013870: .4byte 0x00008044
_08013874: .4byte 0x085223AC
_08013878: .4byte 0x085223B4
_0801387C: .4byte 0x085223B0
_08013880: .4byte 0x085223B8
_08013884: .4byte 0x06000800
_08013888: .4byte 0x02002180
_0801388C: .4byte 0x00003B44
_08013890: .4byte 0x00000C04
_08013894: .4byte 0x02002190

	thumb_func_start FUN_08013898
FUN_08013898: @ 0x08013898
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _080138D4 @ =0x02002200
	ldr r1, _080138D8 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	asrs r1, r1, #8
	ldr r0, [r5, #0x38]
	subs r0, r0, r1
	adds r4, r0, #5
	cmp r4, #0xff
	ble _080138B8
	movs r4, #0xff
_080138B8:
	movs r0, #0xff
	rsbs r0, r0, #0
	cmp r4, r0
	bge _080138C2
	adds r4, r0, #0
_080138C2:
	cmp r4, #0
	bge _080138E0
	ldr r0, _080138DC @ =0x02002190
	rsbs r1, r4, #0
	movs r2, #0xff
	ands r1, r2
	strh r1, [r0, #0xa]
	b _080138E6
	.align 2, 0
_080138D4: .4byte 0x02002200
_080138D8: .4byte 0x0002C00C
_080138DC: .4byte 0x02002190
_080138E0:
	ldr r1, _08013900 @ =0x02002190
	movs r0, #0
	strh r0, [r1, #0xa]
_080138E6:
	lsrs r2, r3, #4
	lsls r2, r2, #2
	ldr r0, _08013904 @ =0x0200214C
	adds r3, r2, r0
	ldr r1, [r5, #0x34]
	strh r1, [r3]
	adds r0, #2
	adds r2, r2, r0
	strh r4, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013900: .4byte 0x02002190
_08013904: .4byte 0x0200214C

	thumb_func_start FUN_08013908
FUN_08013908: @ 0x08013908
	ldr r1, _08013924 @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08013928 @ =0x02002190
	ldrh r2, [r1]
	ldr r0, _0801392C @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	bx lr
	.align 2, 0
_08013924: .4byte 0x02002180
_08013928: .4byte 0x02002190
_0801392C: .4byte 0x0000BFFF

	thumb_func_start sunkenlib_08013930
sunkenlib_08013930: @ 0x08013930
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	bne _080139A0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _08013A20 @ =0x02002144
	adds r5, r5, r3
	ldr r1, [r7, #0x64]
	ldr r4, _08013A24 @ =0x00008045
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r6, [r0]
	ldr r0, _08013A28 @ =0x085223B4
	ldr r0, [r0]
	ldr r2, _08013A2C @ =0x085223BC
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	bl CpuFastSet
	ldr r0, _08013A30 @ =0x085223B8
	ldr r0, [r0]
	ldr r1, _08013A34 @ =0x085223C0
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _08013A38 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	mov r2, r8
	bl CpuFastSet
	str r6, [r7, #0x68]
	strh r6, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080139A0:
	ldr r2, _08013A3C @ =0x02002190
	ldrb r1, [r2, #0xd]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r2, #0xd]
	ldr r0, [r7, #0x68]
	cmp r0, #0
	bne _080139B6
	bl FUN_080d8f2c
	str r0, [r7, #0x68]
_080139B6:
	ldr r5, _08013A40 @ =0x02002200
	ldr r4, _08013A44 @ =0x0002C00C
	adds r0, r5, r4
	ldr r1, [r0]
	ldr r0, _08013A48 @ =0x000227FF
	cmp r1, r0
	bgt _08013A60
	ldrh r0, [r7, #0x10]
	adds r0, #1
	strh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080139D6
	movs r0, #4
	strh r0, [r7, #0x10]
_080139D6:
	ldr r0, [r7, #0x68]
	bl FUN_080d8fd4
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _080139F0
	adds r0, r4, #0
	bl playSound
_080139F0:
	ldrh r1, [r7, #0x10]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08013A7E
	ldr r0, _08013A4C @ =0x0002D02C
	adds r2, r5, r0
	ldr r1, [r2]
	ldr r0, _08013A50 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013A54 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	beq _08013A7E
	ldr r1, _08013A58 @ =0x02002180
	ldr r0, _08013A5C @ =0x00000C0A
	b _08013A82
	.align 2, 0
_08013A20: .4byte 0x02002144
_08013A24: .4byte 0x00008045
_08013A28: .4byte 0x085223B4
_08013A2C: .4byte 0x085223BC
_08013A30: .4byte 0x085223B8
_08013A34: .4byte 0x085223C0
_08013A38: .4byte 0x06000800
_08013A3C: .4byte 0x02002190
_08013A40: .4byte 0x02002200
_08013A44: .4byte 0x0002C00C
_08013A48: .4byte 0x000227FF
_08013A4C: .4byte 0x0002D02C
_08013A50: .4byte 0x000343FD
_08013A54: .4byte 0x00269EC3
_08013A58: .4byte 0x02002180
_08013A5C: .4byte 0x00000C0A
_08013A60:
	movs r0, #3
	strh r0, [r7, #0x10]
	ldr r0, [r7, #0x68]
	bl FUN_080d8fe4
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013A7E
	adds r0, r4, #0
	bl stopSound
_08013A7E:
	ldr r1, _08013A90 @ =0x02002180
	ldr r0, _08013A94 @ =0x00000C04
_08013A82:
	strh r0, [r1, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013A90: .4byte 0x02002180
_08013A94: .4byte 0x00000C04

	thumb_func_start FUN_08013a98
FUN_08013a98: @ 0x08013A98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r2, [r5, #0x5c]
	lsls r2, r2, #0x10
	ldr r0, _08013AFC @ =0x02002200
	ldr r1, _08013B00 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r3, [r5, #0x38]
	subs r3, r3, r0
	adds r3, #5
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r0, _08013B04 @ =0x0200214C
	adds r4, r2, r0
	ldr r1, [r5, #0x34]
	strh r1, [r4]
	adds r0, #2
	adds r2, r2, r0
	strh r3, [r2]
	ldr r6, _08013B08 @ =0x087044F8
	ldrh r0, [r5, #0x10]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08013B0C @ =0x08704B10
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r5, #0x10]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013AFC: .4byte 0x02002200
_08013B00: .4byte 0x0002C00C
_08013B04: .4byte 0x0200214C
_08013B08: .4byte 0x087044F8
_08013B0C: .4byte 0x08704B10

	thumb_func_start FUN_08013b10
FUN_08013b10: @ 0x08013B10
	push {r4, lr}
	ldr r3, [r0, #0x68]
	cmp r3, #0
	beq _08013B4E
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
	ldr r1, _08013B68 @ =0x0836FB24
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_08013B4E:
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013B62
	adds r0, r4, #0
	bl stopSound
_08013B62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013B68: .4byte 0x0836FB24

	thumb_func_start sunkenlib_08013b6c
sunkenlib_08013b6c: @ 0x08013B6C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08013BBA
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r3, r0, #1
	ldr r4, _08013BCC @ =0x02002144
	adds r3, r3, r4
	ldr r1, [r5, #0x60]
	ldr r2, [r5, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #2
	adds r4, #8
	adds r0, r0, r4
	str r6, [r0]
	ldr r0, _08013BD0 @ =0x085223BC
	ldr r0, [r0]
	ldr r2, _08013BD4 @ =0x085223C4
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08013BBA:
	ldr r2, _08013BD8 @ =0x02002190
	ldrb r1, [r2, #0xd]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #0xd]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013BCC: .4byte 0x02002144
_08013BD0: .4byte 0x085223BC
_08013BD4: .4byte 0x085223C4
_08013BD8: .4byte 0x02002190

	thumb_func_start FUN_08013bdc
FUN_08013bdc: @ 0x08013BDC
	push {r4, r5, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r4, _08013C08 @ =0x0200214C
	adds r5, r2, r4
	ldr r3, [r0, #0x34]
	lsls r1, r3, #1
	adds r1, r1, r3
	asrs r1, r1, #2
	strh r1, [r5]
	adds r4, #2
	adds r2, r2, r4
	ldr r1, [r0, #0x38]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013C08: .4byte 0x0200214C

	thumb_func_start sunkenLib_08013c0c
sunkenLib_08013c0c: @ 0x08013C0C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	ldr r2, _08013CA4 @ =0x02002200
	cmp r0, #0
	bne _08013C30
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xc
_08013C1E:
	str r1, [r0, #0x68]
	subs r0, #4
	cmp r0, r5
	bge _08013C1E
	movs r0, #0
	strh r0, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08013C30:
	ldr r1, _08013CA8 @ =0x0002D024
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08013CC0
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x68
_08013C46:
	ldr r0, [r4]
	cmp r0, #0
	bne _08013C56
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl FUN_080d8f7c
	str r0, [r4]
_08013C56:
	adds r4, #4
	adds r6, #1
	cmp r6, #3
	ble _08013C46
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _08013C72
	adds r0, r4, #0
	bl playSound
_08013C72:
	ldrh r1, [r5, #0x10]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08013D20
	ldr r2, _08013CA4 @ =0x02002200
	ldr r0, _08013CAC @ =0x0002D02C
	adds r2, r2, r0
	ldr r1, [r2]
	ldr r0, _08013CB0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013CB4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	beq _08013D20
	ldr r1, _08013CB8 @ =0x02002180
	ldr r0, _08013CBC @ =0x00000C0A
	b _08013D24
	.align 2, 0
_08013CA4: .4byte 0x02002200
_08013CA8: .4byte 0x0002D024
_08013CAC: .4byte 0x0002D02C
_08013CB0: .4byte 0x000343FD
_08013CB4: .4byte 0x00269EC3
_08013CB8: .4byte 0x02002180
_08013CBC: .4byte 0x00000C0A
_08013CC0:
	movs r4, #0
	ldr r7, _08013D2C @ =0x0836FB24
	adds r3, r5, #0
	adds r3, #0x68
	movs r6, #3
_08013CCA:
	ldr r2, [r3]
	cmp r2, #0
	beq _08013D04
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r4, [r3]
_08013D04:
	adds r3, #4
	subs r6, #1
	cmp r6, #0
	bge _08013CCA
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013D20
	adds r0, r4, #0
	bl stopSound
_08013D20:
	ldr r1, _08013D30 @ =0x02002180
	ldr r0, _08013D34 @ =0x00000C04
_08013D24:
	strh r0, [r1, #2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013D2C: .4byte 0x0836FB24
_08013D30: .4byte 0x02002180
_08013D34: .4byte 0x00000C04

	thumb_func_start FUN_08013d38
FUN_08013d38: @ 0x08013D38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08013D6C @ =0x02002200
	ldr r1, _08013D70 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08013D80
	ldr r4, _08013D74 @ =0x087044F8
	ldr r0, [r4]
	ldr r1, _08013D78 @ =0x08704B74
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldr r0, [r4]
	ldr r1, _08013D7C @ =0x08704B80
	adds r0, r0, r1
	movs r1, #0
	bl transferPalette
	b _08013DBA
	.align 2, 0
_08013D6C: .4byte 0x02002200
_08013D70: .4byte 0x0002D024
_08013D74: .4byte 0x087044F8
_08013D78: .4byte 0x08704B74
_08013D7C: .4byte 0x08704B80
_08013D80:
	ldr r6, _08013DCC @ =0x087044F8
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	movs r5, #3
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08013DD0 @ =0x08704B88
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_08013DBA:
	adds r0, r7, #0
	mov r1, r8
	bl variousStageFunc_080093b8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013DCC: .4byte 0x087044F8
_08013DD0: .4byte 0x08704B88

	thumb_func_start FUN_08013dd4
FUN_08013dd4: @ 0x08013DD4
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _08013E38 @ =0x0836FB24
	adds r3, r0, #0
	movs r4, #3
_08013DDE:
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _08013E16
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08013E16:
	adds r3, #4
	subs r4, #1
	cmp r4, #0
	bge _08013DDE
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013E32
	adds r0, r4, #0
	bl stopSound
_08013E32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013E38: .4byte 0x0836FB24
