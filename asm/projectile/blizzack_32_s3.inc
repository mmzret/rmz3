	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ab9f0
FUN_080ab9f0: @ 0x080AB9F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080ABA54 @ =0x00006202
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080ABA58 @ =0x0836C4EC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	movs r0, #0xa0
	str r0, [r4, #0x5c]
	ldr r1, _080ABA5C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile32_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABA54: .4byte 0x00006202
_080ABA58: .4byte 0x0836C4EC
_080ABA5C: .4byte gProjectileFnTable

	thumb_func_start FUN_080aba60
FUN_080aba60: @ 0x080ABA60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xd]
	cmp r1, #0
	bne _080ABAA6
	ldr r0, [r4, #0x5c]
	adds r0, #0x10
	str r0, [r4, #0x5c]
	movs r2, #0xa0
	lsls r2, r2, #2
	cmp r0, r2
	ble _080ABA80
	str r2, [r4, #0x5c]
_080ABA80:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080ABAE0
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080ABAE0
_080ABAA6:
	ldrb r1, [r4, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bls _080ABABA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABAC0
_080ABABA:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
_080ABAC0:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bls _080ABAE0
	ldr r1, _080ABAF4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABAE0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABAF8
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	b _080ABAFE
	.align 2, 0
_080ABAF4: .4byte gProjectileFnTable
_080ABAF8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
_080ABAFE:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080ABB20
	ldr r1, _080ABB28 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABB20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB28: .4byte gProjectileFnTable

	thumb_func_start FUN_080abb2c
FUN_080abb2c: @ 0x080ABB2C
	ldr r2, _080ABB40 @ =gProjectileFnTable
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
_080ABB40: .4byte gProjectileFnTable

	thumb_func_start FUN_080abb44
FUN_080abb44: @ 0x080ABB44
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080ABBAC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080ABBB0 @ =0x00006207
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080ABBB4 @ =0x0836C51C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	movs r0, #0x80
	str r0, [r4, #0x5c]
	str r6, [r4, #0x60]
	strb r6, [r4, #0x12]
	strb r6, [r4, #0x13]
	adds r0, r4, #0
	bl Projectile32_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBAC: .4byte gProjectileFnTable
_080ABBB0: .4byte 0x00006207
_080ABBB4: .4byte 0x0836C51C

	thumb_func_start FUN_080abbb8
FUN_080abbb8: @ 0x080ABBB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x28]
	bl UpdateEntityAnim
	ldrb r6, [r7, #0xd]
	cmp r6, #1
	beq _080ABCA0
	cmp r6, #1
	bgt _080ABBDA
	cmp r6, #0
	beq _080ABBE2
	b _080ABD76
_080ABBDA:
	cmp r6, #2
	bne _080ABBE0
	b _080ABCE0
_080ABBE0:
	b _080ABD76
_080ABBE2:
	ldr r0, [r7, #0x5c]
	adds r0, #0x10
	str r0, [r7, #0x5c]
	movs r1, #0xa0
	lsls r1, r1, #2
	cmp r0, r1
	ble _080ABBF2
	str r1, [r7, #0x5c]
_080ABBF2:
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _080ABC12
	adds r0, r7, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #1
	b _080ABD74
_080ABC12:
	movs r0, #0x8c
	adds r0, r0, r7
	mov sl, r0
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080ABC24
	b _080ABD76
_080ABC24:
	ldr r4, _080ABC90 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080ABC94 @ =0x000343FD
	mov r8, r1
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r1, _080ABC98 @ =0x00269EC3
	mov sb, r1
	add r0, sb
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xe
	bl __umodsi3
	subs r0, #7
	lsls r0, r0, #8
	str r0, [r7, #0x64]
	mov r0, r8
	muls r0, r5, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #4
	lsls r0, r0, #8
	str r0, [r7, #0x68]
	ldr r0, _080ABC9C @ =pZero2
	ldr r0, [r0]
	cmp r0, #0
	beq _080ABC74
	movs r1, #8
	bl makeZeroSlower
_080ABC74:
	mov r3, sl
	str r6, [r3]
	adds r0, r7, #0
	adds r0, #0x90
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #2
	b _080ABD74
	.align 2, 0
_080ABC90: .4byte RNG_0202f388
_080ABC94: .4byte 0x000343FD
_080ABC98: .4byte 0x00269EC3
_080ABC9C: .4byte pZero2
_080ABCA0:
	ldrb r1, [r7, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bls _080ABCB4
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABCBA
_080ABCB4:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
_080ABCBA:
	strb r0, [r7, #0xa]
	adds r0, r2, #1
	strb r0, [r7, #0x12]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bls _080ABD76
	ldr r1, _080ABCDC @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080ABD76
	.align 2, 0
_080ABCDC: .4byte gProjectileFnTable
_080ABCE0:
	ldr r0, _080ABCF4 @ =pZero2
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	bne _080ABCF8
	str r2, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	b _080ABD72
	.align 2, 0
_080ABCF4: .4byte pZero2
_080ABCF8:
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080ABD14
	adds r0, r2, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _080ABD1C
_080ABD14:
	movs r0, #0
	str r0, [r7, #0x5c]
	str r1, [r7, #0x60]
	b _080ABD72
_080ABD1C:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABD2E
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x64]
	adds r0, r0, r1
	b _080ABD34
_080ABD2E:
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x64]
	subs r0, r0, r1
_080ABD34:
	str r0, [r7, #0x54]
	ldr r0, [r4]
	ldr r1, [r0, #0x58]
	ldr r2, [r7, #0x68]
	subs r1, r1, r2
	str r1, [r7, #0x58]
	bl CountButtonMashing
	ldrb r1, [r7, #0x12]
	adds r0, r0, r1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bhi _080ABD60
	ldrb r0, [r7, #0x13]
	adds r1, r0, #1
	strb r1, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf0
	bls _080ABD76
_080ABD60:
	movs r0, #0
	str r0, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	ldr r0, [r4]
	movs r1, #8
	bl makeZeroFaster
_080ABD72:
	movs r0, #3
_080ABD74:
	strb r0, [r7, #0xd]
_080ABD76:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABD88
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	b _080ABD8E
_080ABD88:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
_080ABD8E:
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, [r7, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080ABDB6
	ldr r1, _080ABDC4 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080ABDB6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABDC4: .4byte gProjectileFnTable

	thumb_func_start FUN_080abdc8
FUN_080abdc8: @ 0x080ABDC8
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080ABDF4 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080ABDF4: .4byte gProjectileFnTable

	thumb_func_start FUN_080abdf8
FUN_080abdf8: @ 0x080ABDF8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080ABE48 @ =0x0836C4BC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080ABE4C @ =FUN_080ac1a4
	str r0, [r5, #0x24]
	ldr r1, _080ABE50 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Projectile32_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABE48: .4byte 0x0836C4BC
_080ABE4C: .4byte FUN_080ac1a4
_080ABE50: .4byte gProjectileFnTable

	thumb_func_start FUN_080abe54
FUN_080abe54: @ 0x080ABE54
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateEntityAnim
	ldr r0, _080ABE78 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r0, #0x54]
	str r2, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080ABE7C
	ldr r0, [r5, #0x54]
	cmp r2, r0
	bge _080ABE84
	b _080ABE82
	.align 2, 0
_080ABE78: .4byte pZero2
_080ABE7C:
	ldr r0, [r5, #0x54]
	cmp r2, r0
	ble _080ABE84
_080ABE82:
	str r0, [r4, #0x54]
_080ABE84:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080ABE9C
	ldr r1, _080ABEA4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABE9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABEA4: .4byte gProjectileFnTable

	thumb_func_start FUN_080abea8
FUN_080abea8: @ 0x080ABEA8
	ldr r2, _080ABEBC @ =gProjectileFnTable
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
_080ABEBC: .4byte gProjectileFnTable

	thumb_func_start FUN_080abec0
FUN_080abec0: @ 0x080ABEC0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xc4
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _080ABF00 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080ABF04
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080ABF0A
	.align 2, 0
_080ABF00: .4byte pZero2
_080ABF04:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080ABF0A:
	strb r0, [r5, #0xa]
	movs r4, #1
	adds r1, r4, #0
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	strb r3, [r5, #0x11]
	ldr r1, _080ABF50 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile32_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABF50: .4byte gProjectileFnTable

	thumb_func_start FUN_080abf54
FUN_080abf54: @ 0x080ABF54
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080ABF72
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080ABF78
_080ABF72:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080ABF78:
	strb r0, [r4, #0xa]
	ldr r0, _080ABFB0 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _080ABFB4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080ABFA8
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080ABFB8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ABFA8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ABFB0: .4byte pZero2
_080ABFB4: .4byte 0xFFFFF800
_080ABFB8: .4byte gProjectileFnTable

	thumb_func_start FUN_080abfbc
FUN_080abfbc: @ 0x080ABFBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x54
	adds r0, r0, r7
	mov sl, r0
	ldr r4, _080AC190 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r6, _080AC194 @ =0x000343FD
	muls r0, r6, r0
	ldr r5, _080AC198 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ldr r1, _080AC19C @ =0x000003FF
	mov sb, r1
	mov r1, sb
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x7f
	ands r3, r1
	adds r3, #0x80
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #2
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	mov r1, r8
	orrs r3, r1
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	mov r1, r8
	orrs r3, r1
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x7f
	ands r3, r1
	adds r3, #0x80
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	add r3, r8
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r4]
	adds r3, r0, #0
	muls r3, r6, r3
	adds r3, r3, r5
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0xff
	ands r3, r1
	add r3, r8
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	add r0, r8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r1, _080AC1A0 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC190: .4byte RNG_0202f388
_080AC194: .4byte 0x000343FD
_080AC198: .4byte 0x00269EC3
_080AC19C: .4byte 0x000003FF
_080AC1A0: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac1a4
FUN_080ac1a4: @ 0x080AC1A4
	push {lr}
	ldr r1, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r2, [r0, #0x2c]
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _080AC1E0
	ldrb r0, [r1, #0x11]
	movs r3, #0xa0
	lsls r3, r3, #2
	cmp r0, #0
	bne _080AC1C2
	movs r3, #0xc0
	lsls r3, r3, #1
_080AC1C2:
	ldrb r1, [r1, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AC1D6
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r2, r1
	str r3, [r0]
	b _080AC1E0
_080AC1D6:
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r1, r2, r0
	rsbs r0, r3, #0
	str r0, [r1]
_080AC1E0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac1e4
FUN_080ac1e4: @ 0x080AC1E4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x58
	adds r1, #8
	mov ip, r1
	ldr r5, [r0, #8]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AC1F6
	b _080AC36E
_080AC1F6:
	ldr r0, [r5, #0x58]
	ldr r1, [r1, #4]
	subs r0, r0, r1
	asrs r6, r0, #8
	ldrb r0, [r5, #0x12]
	cmp r0, #0x13
	bls _080AC218
	cmp r0, #0x9f
	bhi _080AC212
	adds r3, r6, #0
	subs r3, #0x28
	adds r2, r6, #0
	adds r2, #0x28
	b _080AC21E
_080AC212:
	ldrb r1, [r5, #0x12]
	movs r0, #0xb5
	subs r0, r0, r1
_080AC218:
	lsls r0, r0, #1
	subs r3, r6, r0
	adds r2, r6, r0
_080AC21E:
	cmp r3, #0x9f
	ble _080AC238
	ldr r2, _080AC230 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080AC234 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r2]
	b _080AC36E
	.align 2, 0
_080AC230: .4byte gVideoRegBuffer
_080AC234: .4byte 0x0000DBFF
_080AC238:
	ldr r7, _080AC29C @ =gVideoRegBuffer
	ldrh r1, [r7]
	movs r4, #0x90
	lsls r4, r4, #6
	adds r0, r4, #0
	adds r4, r0, #0
	orrs r4, r1
	strh r4, [r7]
	cmp r3, #0
	bge _080AC24E
	movs r3, #0
_080AC24E:
	cmp r2, #0x9f
	ble _080AC254
	movs r2, #0x9f
_080AC254:
	ldr r1, _080AC2A0 @ =gWindowRegBuffer
	movs r0, #0xff
	ands r2, r0
	lsls r0, r3, #8
	orrs r2, r0
	strh r2, [r1, #0xa]
	mov r0, ip
	ldr r2, [r0]
	asrs r0, r2, #8
	ldrb r1, [r5, #0x13]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r0, #0x28
	subs r0, r0, r6
	strh r0, [r7, #0x16]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AC2BA
	ldr r0, [r5, #0x54]
	subs r0, r0, r2
	asrs r1, r0, #8
	cmp r1, #0xf0
	bgt _080AC2C4
	movs r2, #0
	movs r4, #0xf0
	mov r3, sp
_080AC28C:
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r0, r0, #5
	adds r0, r1, r0
	cmp r0, #0
	bge _080AC2A4
	movs r0, #0
	b _080AC2AA
	.align 2, 0
_080AC29C: .4byte gVideoRegBuffer
_080AC2A0: .4byte gWindowRegBuffer
_080AC2A4:
	cmp r0, #0xf0
	ble _080AC2AA
	movs r0, #0xf0
_080AC2AA:
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	ble _080AC28C
	b _080AC2F4
_080AC2BA:
	ldr r0, [r5, #0x54]
	subs r0, r0, r2
	asrs r1, r0, #8
	cmp r1, #0
	bge _080AC2D0
_080AC2C4:
	ldr r0, _080AC2CC @ =0x0000DBFF
	ands r4, r0
	strh r4, [r7]
	b _080AC36E
	.align 2, 0
_080AC2CC: .4byte 0x0000DBFF
_080AC2D0:
	movs r2, #0
	mov r3, sp
_080AC2D4:
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r0, r0, #5
	subs r0, r1, r0
	cmp r0, #0
	bge _080AC2E4
	movs r0, #0
	b _080AC2EA
_080AC2E4:
	cmp r0, #0xf0
	ble _080AC2EA
	movs r0, #0xf0
_080AC2EA:
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	ble _080AC2D4
_080AC2F4:
	movs r0, #0xa0
	lsls r0, r0, #1
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC36E
	movs r0, #0
	str r0, [sp, #0x50]
	add r0, sp, #0x50
	ldr r2, _080AC378 @ =0x01000050
	adds r1, r4, #0
	bl CpuFastSet
	movs r2, #0
	adds r0, r6, #0
	cmp r0, #0
	blt _080AC330
	mov r3, sp
_080AC31A:
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	bgt _080AC330
	subs r0, r6, r2
	cmp r0, #0
	bge _080AC31A
_080AC330:
	movs r2, #0
	adds r0, r6, #0
	ldr r5, _080AC37C @ =gIntrManager
	cmp r0, #0xf0
	bgt _080AC352
	mov r3, sp
_080AC33C:
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, #2
	adds r2, #1
	cmp r2, #0x27
	bgt _080AC352
	adds r0, r6, r2
	cmp r0, #0xf0
	ble _080AC33C
_080AC352:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r5, r2
	str r4, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, _080AC380 @ =0x04000042
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _080AC384 @ =0xA2600001
	str r0, [r1]
_080AC36E:
	add sp, #0x58
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC378: .4byte 0x01000050
_080AC37C: .4byte gIntrManager
_080AC380: .4byte 0x04000042
_080AC384: .4byte 0xA2600001

