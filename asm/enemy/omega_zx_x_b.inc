	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08092664
FUN_08092664: @ 0x08092664
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x1e
	bls _08092670
	b _08092910
_08092670:
	lsls r0, r0, #2
	ldr r1, _0809267C @ =_08092680
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809267C: .4byte _08092680
_08092680: @ jump table
	.4byte _080926FC @ case 0
	.4byte _080927BC @ case 1
	.4byte _08092910 @ case 2
	.4byte _08092910 @ case 3
	.4byte _08092910 @ case 4
	.4byte _08092910 @ case 5
	.4byte _08092910 @ case 6
	.4byte _08092910 @ case 7
	.4byte _08092910 @ case 8
	.4byte _08092910 @ case 9
	.4byte _080927E4 @ case 10
	.4byte _0809280C @ case 11
	.4byte _08092910 @ case 12
	.4byte _08092910 @ case 13
	.4byte _08092910 @ case 14
	.4byte _08092838 @ case 15
	.4byte _0809287A @ case 16
	.4byte _080928AC @ case 17
	.4byte _08092910 @ case 18
	.4byte _08092910 @ case 19
	.4byte _080928C8 @ case 20
	.4byte _08092910 @ case 21
	.4byte _08092910 @ case 22
	.4byte _08092910 @ case 23
	.4byte _08092910 @ case 24
	.4byte _08092910 @ case 25
	.4byte _08092910 @ case 26
	.4byte _08092910 @ case 27
	.4byte _08092910 @ case 28
	.4byte _08092910 @ case 29
	.4byte _08092908 @ case 30
_080926FC:
	ldrb r3, [r5, #0x10]
	cmp r3, #0
	bne _08092754
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r4, #1
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r3, [r0]
	ldr r1, _08092750 @ =0x0000B601
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0xe]
	b _08092794
	.align 2, 0
_08092750: .4byte 0x0000B601
_08092754:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r2, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x24
	strb r2, [r0]
_08092794:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r5, #0xa]
	str r1, [r5, #0x5c]
	str r1, [r5, #0x60]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _08092910
_080927BC:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080927DC
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x58]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r2, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
_080927DC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _08092910
_080927E4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080927F6
	b _08092910
_080927F6:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08092804
	b _08092910
_08092804:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08092910
_0809280C:
	ldr r0, [r5, #0x54]
	ldr r1, _0809282C @ =0xFFFFD200
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r3, _08092830 @ =0xFFFFB000
	adds r0, r0, r3
	str r0, [r5, #0x58]
	ldr r1, _08092834 @ =0x0000B601
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _080928C2
	.align 2, 0
_0809282C: .4byte 0xFFFFD200
_08092830: .4byte 0xFFFFB000
_08092834: .4byte 0x0000B601
_08092838:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08092910
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08092858
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092910
_08092858:
	ldrb r1, [r5, #0x13]
	cmp r1, #0xfb
	bhi _08092864
	adds r0, r1, #3
	strb r0, [r5, #0x13]
	b _08092870
_08092864:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092870:
	ldrb r1, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	b _08092910
_0809287A:
	movs r1, #0xb6
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080928AC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080928C2
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092910
_080928C2:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _08092910
_080928C8:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08092910
	ldr r3, [r5, #0x28]
	ldr r2, [r5, #0x54]
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r1, [r3, #0x54]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r2, [r5, #0x58]
	movs r1, #0xe8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r3, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	b _08092910
_08092908:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08092910:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

