	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b8804
FUN_080b8804: @ 0x080B8804
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x1c
	movs r1, #1
	ands r5, r1
	lsrs r4, r0, #0x1d
	ands r4, r1
	ldrb r6, [r7, #0x11]
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080B8826
	cmp r0, #1
	beq _080B88E2
	b _080B8978
_080B8826:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	strb r2, [r7, #0xa]
	adds r1, r5, #0
	cmp r5, #0
	beq _080B883E
	movs r0, #0x10
	orrs r2, r0
	b _080B8842
_080B883E:
	movs r0, #0xef
	ands r2, r0
_080B8842:
	strb r2, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	adds r3, r4, #0
	adds r4, r2, #0
	cmp r3, #0
	beq _080B886C
	ldrb r0, [r7, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080B8872
_080B886C:
	ldrb r1, [r7, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080B8872:
	strb r0, [r7, #0xa]
	adds r1, r3, #0
	adds r2, r7, #0
	adds r2, #0x4d
	strb r1, [r2]
	lsls r1, r1, #5
	ldrb r2, [r4]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldr r1, [r7, #0x74]
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	cmp r5, #0
	beq _080B88A0
	movs r0, #2
	subs r6, r0, r6
_080B88A0:
	subs r1, r6, #1
	lsls r1, r1, #8
	ldr r6, _080B88F8 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080B88FC @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080B8900 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080B8904 @ =0x000001FF
	ands r0, r4
	adds r1, r1, r0
	ldr r0, _080B8908 @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, _080B890C @ =0xFFFFFE00
	subs r1, r1, r0
	str r1, [r7, #0x60]
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B88E2:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B8910
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080B8916
	.align 2, 0
_080B88F8: .4byte RNG_0202f388
_080B88FC: .4byte 0x000343FD
_080B8900: .4byte 0x00269EC3
_080B8904: .4byte 0x000001FF
_080B8908: .4byte 0xFFFFFF00
_080B890C: .4byte 0xFFFFFE00
_080B8910:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B8916:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r1, #0x40
	str r1, [r7, #0x60]
	adds r0, r7, #0
	bl FUN_0801779c
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080B8978
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080B8978
	adds r0, r7, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B895C
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	b _080B8966
_080B895C:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_080B8966:
	ldr r1, _080B8980 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080B8978:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8980: .4byte gVFXFnTable

	thumb_func_start FUN_080b8984
FUN_080b8984: @ 0x080B8984
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x1c
	movs r1, #1
	ands r5, r1
	lsrs r4, r0, #0x1d
	ands r4, r1
	ldrb r7, [r6, #0x11]
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B89A6
	cmp r0, #1
	beq _080B8A64
	b _080B8AEE
_080B89A6:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	strb r2, [r6, #0xa]
	adds r1, r5, #0
	cmp r5, #0
	beq _080B89BE
	movs r0, #0x10
	orrs r2, r0
	b _080B89C2
_080B89BE:
	movs r0, #0xef
	ands r2, r0
_080B89C2:
	strb r2, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	adds r3, r4, #0
	adds r4, r2, #0
	cmp r3, #0
	beq _080B89EC
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080B89F2
_080B89EC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080B89F2:
	strb r0, [r6, #0xa]
	adds r1, r3, #0
	adds r2, r6, #0
	adds r2, #0x4d
	strb r1, [r2]
	lsls r1, r1, #5
	ldrb r2, [r4]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldr r1, [r6, #0x74]
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl SetMotion
	cmp r5, #0
	beq _080B8A20
	movs r0, #2
	subs r7, r0, r7
_080B8A20:
	subs r1, r7, #1
	lsls r1, r1, #8
	ldr r5, _080B8A78 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080B8A7C @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _080B8A80 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	adds r1, r1, r0
	ldr r0, _080B8A84 @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	adds r1, r2, #0
	muls r1, r4, r1
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r5]
	lsrs r1, r1, #0x11
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	ldr r0, _080B8A88 @ =0xFFFFFE00
	subs r0, r0, r1
	str r0, [r6, #0x60]
	movs r0, #0
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B8A64:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B8A8C
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	b _080B8A92
	.align 2, 0
_080B8A78: .4byte RNG_0202f388
_080B8A7C: .4byte 0x000343FD
_080B8A80: .4byte 0x00269EC3
_080B8A84: .4byte 0xFFFFFF00
_080B8A88: .4byte 0xFFFFFE00
_080B8A8C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B8A92:
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r1, #0x20
	str r1, [r6, #0x60]
	adds r0, r6, #0
	bl FUN_0801779c
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080B8AEE
	adds r0, r6, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B8AD2
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	b _080B8ADC
_080B8AD2:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_080B8ADC:
	ldr r1, _080B8AF4 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080B8AEE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8AF4: .4byte gVFXFnTable

	thumb_func_start FUN_080b8af8
FUN_080b8af8: @ 0x080B8AF8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x1c
	movs r1, #1
	ands r5, r1
	lsrs r4, r0, #0x1d
	ands r4, r1
	ldrb r7, [r6, #0x11]
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B8B1A
	cmp r0, #1
	beq _080B8BD8
	b _080B8C68
_080B8B1A:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	strb r2, [r6, #0xa]
	adds r1, r5, #0
	cmp r5, #0
	beq _080B8B32
	movs r0, #0x10
	orrs r2, r0
	b _080B8B36
_080B8B32:
	movs r0, #0xef
	ands r2, r0
_080B8B36:
	strb r2, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	adds r3, r4, #0
	adds r4, r2, #0
	cmp r3, #0
	beq _080B8B60
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080B8B66
_080B8B60:
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080B8B66:
	strb r0, [r6, #0xa]
	adds r1, r3, #0
	adds r2, r6, #0
	adds r2, #0x4d
	strb r1, [r2]
	lsls r1, r1, #5
	ldrb r2, [r4]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldr r1, [r6, #0x74]
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl SetMotion
	cmp r5, #0
	beq _080B8B94
	movs r0, #2
	subs r7, r0, r7
_080B8B94:
	subs r1, r7, #1
	lsls r1, r1, #8
	ldr r5, _080B8BEC @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080B8BF0 @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _080B8BF4 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	adds r1, r1, r0
	ldr r0, _080B8BF8 @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	adds r1, r2, #0
	muls r1, r4, r1
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r5]
	lsrs r1, r1, #0x11
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	ldr r0, _080B8BFC @ =0xFFFFFE00
	subs r0, r0, r1
	str r0, [r6, #0x60]
	movs r0, #0
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B8BD8:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B8C00
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	b _080B8C06
	.align 2, 0
_080B8BEC: .4byte RNG_0202f388
_080B8BF0: .4byte 0x000343FD
_080B8BF4: .4byte 0x00269EC3
_080B8BF8: .4byte 0xFFFFFF00
_080B8BFC: .4byte 0xFFFFFE00
_080B8C00:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B8C06:
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r1, #0x40
	str r1, [r6, #0x60]
	adds r0, r6, #0
	bl FUN_0801779c
	ldrb r0, [r6, #0x12]
	cmp r0, #0x18
	bls _080B8C68
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080B8C68
	adds r0, r6, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B8C4C
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	b _080B8C56
_080B8C4C:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_080B8C56:
	ldr r1, _080B8C70 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080B8C68:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B8C70: .4byte gVFXFnTable

	thumb_func_start FUN_080b8c74
FUN_080b8c74: @ 0x080B8C74
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x1c
	movs r1, #1
	ands r3, r1
	lsrs r5, r0, #0x1d
	ands r5, r1
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B8C94
	cmp r0, #1
	beq _080B8D08
	b _080B8D42
_080B8C94:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	adds r2, r0, #0
	orrs r2, r1
	strb r2, [r4, #0xa]
	adds r1, r3, #0
	cmp r1, #0
	beq _080B8CAC
	movs r0, #0x10
	orrs r2, r0
	b _080B8CB0
_080B8CAC:
	movs r0, #0xef
	ands r2, r0
_080B8CB0:
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	adds r3, r5, #0
	adds r5, r2, #0
	cmp r3, #0
	beq _080B8CDA
	ldrb r0, [r4, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080B8CE0
_080B8CDA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080B8CE0:
	strb r0, [r4, #0xa]
	adds r1, r3, #0
	adds r2, r4, #0
	adds r2, #0x4d
	strb r1, [r2]
	lsls r1, r1, #5
	ldrb r2, [r5]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	ldr r0, [r4, #0x74]
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B8D08:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x68]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B8D3C
	ldr r1, _080B8D48 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B8D3C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080B8D42:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B8D48: .4byte gVFXFnTable

	thumb_func_start FUN_080b8d4c
FUN_080b8d4c: @ 0x080B8D4C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x1c
	movs r1, #1
	ands r3, r1
	lsrs r5, r0, #0x1d
	ands r5, r1
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B8D6C
	cmp r0, #1
	beq _080B8DE0
	b _080B8E32
_080B8D6C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	adds r2, r0, #0
	orrs r2, r1
	strb r2, [r4, #0xa]
	adds r1, r3, #0
	cmp r1, #0
	beq _080B8D84
	movs r0, #0x10
	orrs r2, r0
	b _080B8D88
_080B8D84:
	movs r0, #0xef
	ands r2, r0
_080B8D88:
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	adds r3, r5, #0
	adds r5, r2, #0
	cmp r3, #0
	beq _080B8DB2
	ldrb r0, [r4, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080B8DB8
_080B8DB2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080B8DB8:
	strb r0, [r4, #0xa]
	adds r1, r3, #0
	adds r2, r4, #0
	adds r2, #0x4d
	strb r1, [r2]
	lsls r1, r1, #5
	ldrb r2, [r5]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	ldr r0, [r4, #0x74]
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B8DE0:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r3, r1, r0
	str r3, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B8E10
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080B8E2C
_080B8E10:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	ldr r1, _080B8E38 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B8E2C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080B8E32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B8E38: .4byte gVFXFnTable
