	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
