	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805fdac
FUN_0805fdac: @ 0x0805FDAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r1, r0, #1
	movs r2, #0
	strb r1, [r5, #0x12]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bhi _0805FDD4
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0805FDF8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0805FDFE
_0805FDD4:
	cmp r0, #0x2f
	bhi _0805FDE8
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _0805FDF8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0805FDFE
_0805FDE8:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0805FDF8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0805FDFE
_0805FDF8:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
_0805FDFE:
	strb r0, [r5, #0xa]
	ldr r1, _0805FE9C @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r5, #0x12]
	cmp r0, #0x40
	bne _0805FE92
	ldr r2, _0805FEA0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805FEA4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805FEA8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r6, r0, #0x11
	movs r0, #3
	ands r6, r0
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r7, [r0]
	adds r3, r5, #0
	adds r3, #0xc9
	ldrb r1, [r3]
	lsls r2, r1, #5
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #8
	adds r7, r7, r0
	movs r0, #1
	eors r1, r0
	strb r1, [r3]
	str r7, [r5, #0x54]
	movs r4, #0
	movs r0, #0xc4
	adds r0, r0, r5
	mov r8, r0
_0805FE5C:
	cmp r4, r6
	beq _0805FE6C
	adds r1, r4, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_0809130c
_0805FE6C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0805FE5C
	subs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r7, r0
	str r0, [r5, #0x54]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #1
	mov r1, r8
	str r0, [r1]
_0805FE92:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805FE9C: .4byte gSineTable
_0805FEA0: .4byte RNG_0202f388
_0805FEA4: .4byte 0x000343FD
_0805FEA8: .4byte 0x00269EC3

	thumb_func_start FUN_0805feac
FUN_0805feac: @ 0x0805FEAC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xc4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	movs r2, #0
	strb r1, [r4, #0x12]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x4f
	bhi _0805FED8
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0805FEFC
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FF02
_0805FED8:
	cmp r0, #0x6f
	bhi _0805FEEC
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _0805FEFC
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FF02
_0805FEEC:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0805FEFC
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FF02
_0805FEFC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805FF02:
	strb r0, [r4, #0xa]
	ldr r1, _0805FF5C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x80
	bne _0805FF54
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805FF60 @ =sCollisions+(8*24)
	bl SetDDP
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080607a0
	adds r1, r4, #0
	adds r1, #0xc4
	movs r0, #8
	str r0, [r1]
	movs r0, #2
	strh r0, [r4, #0xe]
	movs r0, #0
	strb r0, [r4, #0x12]
	movs r0, #0x10
	strb r0, [r4, #0x13]
_0805FF54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805FF5C: .4byte gSineTable
_0805FF60: .4byte sCollisions+(8*24)
