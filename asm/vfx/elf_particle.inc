	.include "asm/macros.inc"

	.syntax unified
	
	.text


	thumb_func_start FUN_080bfc94
FUN_080bfc94: @ 0x080BFC94
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _080BFCE0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BFCD8
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BFCE4 @ =gVFXFnTable
	movs r1, #0x30
	strb r1, [r4, #9]
	adds r0, #0xc0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
	strb r6, [r4, #0x11]
_080BFCD8:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BFCE0: .4byte gVFXHeaderPtr
_080BFCE4: .4byte gVFXFnTable

	thumb_func_start FUN_080bfce8
FUN_080bfce8: @ 0x080BFCE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	movs r4, #0
	ldr r0, _080BFD14 @ =gVFXHeaderPtr
	ldr r0, [r0]
	ldrh r1, [r0, #0xa]
	movs r2, #0xa
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bgt _080BFD18
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _080BFD1A
	.align 2, 0
_080BFD14: .4byte gVFXHeaderPtr
_080BFD18:
	movs r6, #5
_080BFD1A:
	movs r5, #0
	cmp r5, r6
	bhs _080BFD80
	movs r7, #0
	movs r0, #1
	mov r8, r0
_080BFD26:
	ldr r0, _080BFD90 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BFD76
	adds r0, #0x25
	mov r1, r8
	strb r1, [r0]
	movs r0, #0x30
	strb r0, [r4, #9]
	ldr r2, _080BFD94 @ =0x0836D9C0
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	strh r7, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r7, [r0]
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	mov r0, r8
	strb r0, [r4, #0x10]
	mov r1, sb
	strb r1, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x77
	strb r7, [r0]
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	subs r0, #0x40
	adds r1, r4, #0
	adds r1, #0x75
	strb r0, [r1]
_080BFD76:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r6
	blo _080BFD26
_080BFD80:
	adds r0, r4, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BFD90: .4byte gVFXHeaderPtr
_080BFD94: .4byte 0x0836D9C0

	thumb_func_start FUN_080bfd98
FUN_080bfd98: @ 0x080BFD98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #4]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	movs r4, #0
	ldr r0, _080BFDCC @ =gVFXHeaderPtr
	ldr r0, [r0]
	ldrh r1, [r0, #0xa]
	movs r2, #0xa
	ldrsh r0, [r0, r2]
	cmp r0, #2
	bgt _080BFDD0
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _080BFDD2
	.align 2, 0
_080BFDCC: .4byte gVFXHeaderPtr
_080BFDD0:
	movs r5, #3
_080BFDD2:
	movs r6, #0
	cmp r6, r5
	bhs _080BFE96
	mov sb, r6
	movs r0, #1
	mov r8, r0
	ldr r7, _080BFE50 @ =RNG_0202f388
_080BFDE0:
	ldr r0, _080BFE54 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BFE8C
	adds r0, #0x25
	mov r1, r8
	strb r1, [r0]
	movs r0, #0x30
	strb r0, [r4, #9]
	ldr r2, _080BFE58 @ =0x0836D9C0
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	mov r0, sb
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	mov r1, sb
	strb r1, [r0]
	ldr r2, [sp]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	mov r0, r8
	strb r0, [r4, #0x10]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x77
	mov r2, r8
	strb r2, [r0]
	mov r0, sl
	cmp r0, #0
	beq _080BFE64
	lsls r0, r6, #8
	adds r1, r5, #0
	bl __divsi3
	ldr r2, [r7]
	ldr r1, _080BFE5C @ =0x000343FD
	muls r1, r2, r1
	ldr r2, _080BFE60 @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r2, r1, #1
	str r2, [r7]
	lsrs r1, r1, #0x11
	movs r2, #0x1f
	ands r1, r2
	adds r1, #0x40
	b _080BFE84
	.align 2, 0
_080BFE50: .4byte RNG_0202f388
_080BFE54: .4byte gVFXHeaderPtr
_080BFE58: .4byte 0x0836D9C0
_080BFE5C: .4byte 0x000343FD
_080BFE60: .4byte 0x00269EC3
_080BFE64:
	lsls r0, r6, #8
	adds r1, r5, #0
	bl __divsi3
	ldr r2, [r7]
	ldr r1, _080BFEA8 @ =0x000343FD
	muls r1, r2, r1
	ldr r2, _080BFEAC @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r2, r1, #1
	str r2, [r7]
	lsrs r1, r1, #0x11
	movs r2, #0x1f
	ands r1, r2
	adds r1, #0xc0
_080BFE84:
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x75
	strb r0, [r1]
_080BFE8C:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r5
	blo _080BFDE0
_080BFE96:
	adds r0, r4, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BFEA8: .4byte 0x000343FD
_080BFEAC: .4byte 0x00269EC3

	thumb_func_start ElfParticle_Init
ElfParticle_Init: @ 0x080BFEB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r0, [r6, #0xa]
	movs r4, #1
	movs r5, #0
	orrs r0, r4
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0x93
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r2, _080BFF00 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BFF04 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BFF08 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r2, r0, #0x11
	ands r2, r4
	cmp r2, #0
	beq _080BFF0C
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080BFF12
	.align 2, 0
_080BFF00: .4byte RNG_0202f388
_080BFF04: .4byte 0x000343FD
_080BFF08: .4byte 0x00269EC3
_080BFF0C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080BFF12:
	strb r0, [r6, #0xa]
	movs r5, #1
	adds r1, r2, #0
	adds r4, r6, #0
	adds r4, #0x4c
	strb r1, [r4]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r2, _080BFF58 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BFF5C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BFF60 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r2, r0, #0x11
	ands r2, r5
	mov sb, r4
	adds r7, r3, #0
	cmp r2, #0
	beq _080BFF64
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080BFF6A
	.align 2, 0
_080BFF58: .4byte RNG_0202f388
_080BFF5C: .4byte 0x000343FD
_080BFF60: .4byte 0x00269EC3
_080BFF64:
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080BFF6A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r3, r6, #0
	adds r3, #0x4d
	strb r1, [r3]
	lsls r1, r1, #5
	ldrb r2, [r7]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7]
	adds r4, r6, #0
	adds r4, #0x49
	movs r0, #3
	ldrb r1, [r6, #0x11]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r4]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r6, #0x11]
	mov r8, r3
	cmp r0, #1
	bne _080BFFAA
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
_080BFFAA:
	movs r0, #0xa
	strb r0, [r6, #0x12]
	strb r0, [r6, #0x13]
	ldr r1, _080BFFF8 @ =0x0836F12C
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r4, _080BFFFC @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _080C0000 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080C0004 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	adds r5, r6, #0
	adds r5, #0x76
	strb r0, [r5]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r2, r0, #0x11
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080C0008
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C000E
	.align 2, 0
_080BFFF8: .4byte 0x0836F12C
_080BFFFC: .4byte RNG_0202f388
_080C0000: .4byte 0x000343FD
_080C0004: .4byte 0x00269EC3
_080C0008:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C000E:
	strb r0, [r6, #0xa]
	movs r3, #1
	adds r1, r2, #0
	mov r0, sb
	strb r1, [r0]
	lsls r1, r1, #4
	ldrb r2, [r7]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7]
	ldr r2, _080C0048 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C004C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C0050 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r2, r0, #0x11
	ands r2, r3
	cmp r2, #0
	beq _080C0054
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080C005A
	.align 2, 0
_080C0048: .4byte RNG_0202f388
_080C004C: .4byte 0x000343FD
_080C0050: .4byte 0x00269EC3
_080C0054:
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080C005A:
	strb r0, [r6, #0xa]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	mov r0, r8
	strb r1, [r0]
	lsls r1, r1, #5
	ldrb r2, [r7]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7]
	ldr r1, _080C0098 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl ElfParticle_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0098: .4byte gVFXFnTable

	thumb_func_start ElfParticle_Update
ElfParticle_Update: @ 0x080C009C
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r1, _080C0134 @ =0x0836F134
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x64]
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x68]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080C00FC
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _080C00FC
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_080C00FC:
	ldr r0, _080C0138 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bhi _080C0114
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080C012C
_080C0114:
	ldr r1, _080C013C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl ElfParticle_Die
_080C012C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0134: .4byte 0x0836F134
_080C0138: .4byte gStageRun+232
_080C013C: .4byte gVFXFnTable

	thumb_func_start ElfParticle_Die
ElfParticle_Die: @ 0x080C0140
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C015C @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080C015C: .4byte gVFXFnTable

	thumb_func_start FUN_080c0160
FUN_080c0160: @ 0x080C0160
	movs r1, #0
	str r1, [r0, #0x5c]
	str r1, [r0, #0x60]
	str r1, [r0, #0x64]
	movs r1, #4
	str r1, [r0, #0x68]
	ldr r1, [r0, #0x54]
	str r1, [r0, #0x78]
	ldr r3, _080C0190 @ =RNG_0202f388
	ldr r2, [r3]
	ldr r1, _080C0194 @ =0x000343FD
	muls r1, r2, r1
	ldr r2, _080C0198 @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r2, r1, #1
	str r2, [r3]
	lsrs r1, r1, #0x11
	movs r2, #1
	ands r1, r2
	lsls r1, r1, #5
	adds r0, #0x74
	strb r1, [r0]
	bx lr
	.align 2, 0
_080C0190: .4byte RNG_0202f388
_080C0194: .4byte 0x000343FD
_080C0198: .4byte 0x00269EC3

	thumb_func_start FUN_080c019c
FUN_080c019c: @ 0x080C019C
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x77
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C01E4
	movs r0, #6
	strb r0, [r3, #0x12]
	strb r0, [r3, #0x13]
	ldr r2, _080C01E0 @ =gSineTable
	movs r0, #0x75
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	str r0, [r3, #0x5c]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	b _080C0206
	.align 2, 0
_080C01E0: .4byte gSineTable
_080C01E4:
	ldr r1, _080C0218 @ =gSineTable
	adds r2, r3, #0
	adds r2, #0x75
	ldrb r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	asrs r0, r0, #2
	str r0, [r3, #0x5c]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
_080C0206:
	asrs r0, r0, #2
	str r0, [r3, #0x60]
	movs r0, #0
	str r0, [r3, #0x64]
	movs r0, #1
	str r0, [r3, #0x68]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0218: .4byte gSineTable

	thumb_func_start FUN_080c021c
FUN_080c021c: @ 0x080C021C
	push {r4, lr}
	adds r3, r0, #0
	adds r3, #0x74
	ldrb r1, [r3]
	ldr r2, _080C0254 @ =gSineTable
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x17
	adds r1, r1, r2
	movs r4, #0
	ldrsh r2, [r1, r4]
	lsls r2, r2, #1
	ldr r1, [r0, #0x78]
	adds r1, r1, r2
	str r1, [r0, #0x54]
	ldrb r1, [r3]
	adds r2, r1, #1
	adds r0, r2, #0
	cmp r2, #0
	bge _080C0246
	adds r0, r1, #0
	adds r0, #0x40
_080C0246:
	asrs r0, r0, #6
	lsls r0, r0, #6
	subs r0, r2, r0
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0254: .4byte gSineTable

	thumb_func_start nop_080c0258
nop_080c0258: @ 0x080C0258
	bx lr
	.align 2, 0
