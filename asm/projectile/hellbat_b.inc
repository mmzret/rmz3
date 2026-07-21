	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a1778
FUN_080a1778: @ 0x080A1778
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A1792
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	b _080A180C
_080A1792:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080A1800
	ldr r2, _080A17F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080A17F4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080A17F8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r5, _080A17FC @ =0x0000AA02
	mov r0, sp
	movs r1, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080bddcc
	mov r0, sp
	movs r1, #1
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080bddcc
	movs r0, #0x2a
	bl PlaySound
	b _080A180C
	.align 2, 0
_080A17F0: .4byte RNG_0202f388
_080A17F4: .4byte 0x000343FD
_080A17F8: .4byte 0x00269EC3
_080A17FC: .4byte 0x0000AA02
_080A1800:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A1824
_080A180C:
	ldr r1, _080A1820 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080A1A04
	.align 2, 0
_080A1820: .4byte gProjectileFnTable
_080A1824:
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	bne _080A182C
	b _080A198C
_080A182C:
	cmp r0, #1
	bgt _080A1836
	cmp r0, #0
	beq _080A1844
	b _080A1A04
_080A1836:
	cmp r0, #2
	bne _080A183C
	b _080A19CA
_080A183C:
	cmp r0, #3
	bne _080A1842
	b _080A19D8
_080A1842:
	b _080A1A04
_080A1844:
	movs r0, #0x78
	strb r0, [r6, #0x12]
	movs r1, #0xaa
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0xb6
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080A1868
	movs r0, #0x12
	strb r0, [r6, #0x13]
	movs r0, #0x80
	lsls r0, r0, #7
	b _080A188C
_080A1868:
	cmp r1, #1
	bne _080A1876
	movs r0, #0x1a
	strb r0, [r6, #0x13]
	movs r0, #0xc0
	lsls r0, r0, #7
	b _080A188C
_080A1876:
	cmp r1, #2
	bne _080A1884
	movs r0, #0x22
	strb r0, [r6, #0x13]
	movs r0, #0x80
	lsls r0, r0, #8
	b _080A188C
_080A1884:
	movs r0, #0x2a
	strb r0, [r6, #0x13]
	movs r0, #0xa0
	lsls r0, r0, #8
_080A188C:
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x28]
	ldrb r1, [r0, #0xa]
	movs r4, #0x10
	adds r0, r4, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A18C2
	ldr r1, [r6, #0x54]
	ldr r0, [r6, #0x64]
	subs r3, r1, r0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	b _080A18E6
_080A18C2:
	ldr r1, [r6, #0x54]
	ldr r0, [r6, #0x64]
	adds r3, r1, r0
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r4
_080A18E6:
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	subs r0, r3, r0
	ldrb r1, [r6, #0x13]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldrb r0, [r5]
	ldrb r3, [r6, #0x13]
	cmp r0, #0
	bne _080A1900
	movs r0, #0x4c
	b _080A1912
_080A1900:
	cmp r0, #1
	bne _080A1908
	movs r0, #0x38
	b _080A1912
_080A1908:
	cmp r0, #2
	bne _080A1910
	movs r0, #0x26
	b _080A1912
_080A1910:
	movs r0, #0x14
_080A1912:
	str r0, [r6, #0x68]
	ldr r0, [r6, #0x68]
	lsls r0, r0, #8
	asrs r0, r0, #8
	adds r2, r3, #0
	adds r1, r2, #1
	asrs r1, r1, #1
	muls r1, r2, r1
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xb5
	ldrb r1, [r1]
	cmp r1, #0
	bne _080A1940
	adds r1, r2, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	subs r1, r1, r0
	lsls r1, r1, #4
	b _080A197C
_080A1940:
	cmp r1, #1
	bne _080A1956
	adds r1, r2, #0
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r1, r1, r0
	lsls r1, r1, #4
	b _080A197C
_080A1956:
	cmp r1, #2
	bne _080A196C
	adds r1, r2, #0
	bl __divsi3
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #4
	b _080A197C
_080A196C:
	adds r1, r3, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	subs r1, r1, r0
	lsls r1, r1, #5
_080A197C:
	asrs r1, r1, #8
	str r1, [r6, #0x60]
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A198C:
	ldr r0, [r6, #0x68]
	rsbs r0, r0, #0
	lsls r0, r0, #8
	asrs r0, r0, #8
	ldr r2, [r6, #0x60]
	adds r2, r2, r0
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A19B2
	subs r0, #1
	strb r0, [r6, #0x13]
_080A19B2:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A1A04
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A1A04
_080A19CA:
	ldr r1, _080A1A0C @ =0x0000AA01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A19D8:
	ldr r0, [r6, #0x68]
	rsbs r0, r0, #0
	lsls r0, r0, #8
	asrs r0, r0, #8
	ldr r2, [r6, #0x60]
	adds r2, r2, r0
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A19FE
	subs r0, #1
	strb r0, [r6, #0x13]
_080A19FE:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080A1A04:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1A0C: .4byte 0x0000AA01

