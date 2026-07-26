	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080aaed8
FUN_080aaed8: @ 0x080AAED8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r6, [r7, #0x28]
	ldr r1, _080AAF4C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	mov sb, r1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r5, #0
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080AAF50 @ =0x00006208
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080AAF54 @ =0x0836C42C
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r7, [r4, #0x2c]
	mov r0, r8
	str r0, [r4, #0x24]
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	mov r1, sb
	ands r2, r1
	cmp r2, #0
	beq _080AAF58
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAF5E
	.align 2, 0
_080AAF4C: .4byte gProjectileFnTable
_080AAF50: .4byte 0x00006208
_080AAF54: .4byte 0x0836C42C
_080AAF58:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAF5E:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	str r0, [r7, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080AAFAC @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xb8
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	str r0, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080AAFB0
	ldrb r0, [r7, #0x11]
	cmp r0, #0x80
	bhi _080AAFC2
	cmp r0, #0x4f
	bhi _080AAFC6
	movs r0, #0x50
	b _080AAFC4
	.align 2, 0
_080AAFAC: .4byte 0xFFFFF000
_080AAFB0:
	ldrb r0, [r7, #0x11]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0xc0
	bls _080AAFBE
	movs r0, #0xc0
	b _080AAFC4
_080AAFBE:
	cmp r1, #0
	blt _080AAFC6
_080AAFC2:
	movs r0, #0x80
_080AAFC4:
	strb r0, [r7, #0x11]
_080AAFC6:
	ldr r3, _080AB000 @ =gSineTable
	ldrb r0, [r7, #0x11]
	adds r1, r0, #0
	adds r1, #0xc0
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r2, #2
	adds r0, r0, r2
	str r0, [r7, #0x5c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl Projectile32_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB000: .4byte gSineTable

	thumb_func_start FUN_080ab004
FUN_080ab004: @ 0x080AB004
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	bl UpdateEntityAnim
	ldrb r4, [r7, #0xd]
	cmp r4, #0
	bne _080AB088
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, [r7, #0x60]
	adds r1, r1, r2
	str r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AB036
	b _080AB154
_080AB036:
	adds r0, r7, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r1, [r7, #0x58]
	ldr r0, [r0]
	cmp r1, r0
	bge _080AB080
	ldr r1, _080AB07C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _080AB154
	.align 2, 0
_080AB07C: .4byte gProjectileFnTable
_080AB080:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080AB154
_080AB088:
	ldrb r0, [r7, #0x12]
	movs r4, #7
	ands r4, r0
	cmp r4, #0
	bne _080AB12C
	ldr r0, [r7, #0x54]
	str r0, [sp, #4]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [sp, #8]
	movs r3, #0x80
	lsls r3, r3, #1
	str r4, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #0
	bl CreateVFX57
	ldr r3, _080AB164 @ =0xFFFFFF00
	str r4, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #0
	bl CreateVFX57
	ldr r6, _080AB168 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080AB16C @ =0x000343FD
	adds r3, r0, #0
	muls r3, r5, r3
	ldr r4, _080AB170 @ =0x00269EC3
	adds r3, r3, r4
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	movs r1, #0x3f
	mov r8, r1
	mov r1, r8
	ands r3, r1
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	mov sb, r1
	mov r1, sb
	ands r0, r1
	rsbs r0, r0, #0
	str r0, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #1
	bl CreateVFX57
	ldr r0, [r6]
	adds r3, r0, #0
	muls r3, r5, r3
	adds r3, r3, r4
	lsls r3, r3, #1
	lsrs r0, r3, #1
	lsrs r3, r3, #0x11
	mov r1, r8
	ands r3, r1
	rsbs r3, r3, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	mov r1, sb
	ands r0, r1
	rsbs r0, r0, #0
	str r0, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #1
	bl CreateVFX57
_080AB12C:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080AB154
	ldr r1, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080aab38
	ldr r1, _080AB174 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080AB154:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB164: .4byte 0xFFFFFF00
_080AB168: .4byte RNG_0202f388
_080AB16C: .4byte 0x000343FD
_080AB170: .4byte 0x00269EC3
_080AB174: .4byte gProjectileFnTable
