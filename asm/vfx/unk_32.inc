	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080baad8
FUN_080baad8: @ 0x080BAAD8
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080BAB06
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x60
	b _080BAB2C
_080BAB06:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x60
	rsbs r0, r0, #0
_080BAB2C:
	str r0, [r4, #0x5c]
	movs r2, #0
	str r2, [r4, #0x60]
	ldr r1, _080BAB50 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAB50: .4byte gVFXFnTable

	thumb_func_start FUN_080bab54
FUN_080bab54: @ 0x080BAB54
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	movs r3, #0
	str r3, [r4, #0x5c]
	str r3, [r4, #0x60]
	ldr r2, _080BAB9C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BABA0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BABA4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080BABA8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAB9C: .4byte RNG_0202f388
_080BABA0: .4byte 0x000343FD
_080BABA4: .4byte 0x00269EC3
_080BABA8: .4byte gVFXFnTable

	thumb_func_start FUN_080babac
FUN_080babac: @ 0x080BABAC
	push {r4, lr}
	adds r4, r0, #0
	bl InitScalerotMotion1
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	movs r3, #0
	strh r1, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r2, _080BAC04 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BAC08 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BAC0C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r1, _080BAC10 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAC04: .4byte RNG_0202f388
_080BAC08: .4byte 0x000343FD
_080BAC0C: .4byte 0x00269EC3
_080BAC10: .4byte gVFXFnTable

	thumb_func_start FUN_080bac14
FUN_080bac14: @ 0x080BAC14
	push {r4, lr}
	adds r4, r0, #0
	bl InitScalerotMotion1
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r1, _080BAC58 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAC58: .4byte gVFXFnTable

	thumb_func_start FUN_080bac5c
FUN_080bac5c: @ 0x080BAC5C
	push {r4, lr}
	adds r4, r0, #0
	bl InitScalerotMotion1
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r1, _080BACA0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BACA0: .4byte gVFXFnTable

	thumb_func_start FUN_080baca4
FUN_080baca4: @ 0x080BACA4
	push {r4, lr}
	adds r4, r0, #0
	bl InitScalerotMotion1
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r1, _080BACE8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BACE8: .4byte gVFXFnTable

	thumb_func_start FUN_080bacec
FUN_080bacec: @ 0x080BACEC
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r1, _080BAD30 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAD30: .4byte gVFXFnTable

	thumb_func_start FUN_080bad34
FUN_080bad34: @ 0x080BAD34
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r1, _080BAD78 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAD78: .4byte gVFXFnTable

	thumb_func_start Ghost32_Update
Ghost32_Update: @ 0x080BAD7C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BADA8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080BADB0
	ldr r1, _080BADAC @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl Ghost32_Die
	b _080BADC0
	.align 2, 0
_080BADA8: .4byte gCurStory
_080BADAC: .4byte gVFXFnTable
_080BADB0:
	ldr r0, _080BADC4 @ =0x0836EC44
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080BADC0:
	pop {r0}
	bx r0
	.align 2, 0
_080BADC4: .4byte 0x0836EC44

	thumb_func_start Ghost32_Die
Ghost32_Die: @ 0x080BADC8
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BADE4 @ =gVFXFnTable
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
_080BADE4: .4byte gVFXFnTable

	thumb_func_start FUN_080bade8
FUN_080bade8: @ 0x080BADE8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BAEA0
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r2, _080BAE7C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BAE80 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080BAE84 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE88 @ =0x00002710
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE8C @ =0x00002711
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE90 @ =0x00002712
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE94 @ =0x00002713
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE98 @ =0x00002714
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE9C @ =0x00002715
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	movs r0, #0x31
	bl PlaySound
	b _080BAF36
	.align 2, 0
_080BAE7C: .4byte RNG_0202f388
_080BAE80: .4byte 0x000343FD
_080BAE84: .4byte 0x00269EC3
_080BAE88: .4byte 0x00002710
_080BAE8C: .4byte 0x00002711
_080BAE90: .4byte 0x00002712
_080BAE94: .4byte 0x00002713
_080BAE98: .4byte 0x00002714
_080BAE9C: .4byte 0x00002715
_080BAEA0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080BAF74
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080BAF74
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _080BAF4C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BAF50 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _080BAF54 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF58 @ =0x00002710
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF5C @ =0x00002711
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF60 @ =0x00002712
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF64 @ =0x00002713
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF68 @ =0x00002714
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF6C @ =0x00002715
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
_080BAF36:
	ldr r1, _080BAF70 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080BB022
	.align 2, 0
_080BAF4C: .4byte RNG_0202f388
_080BAF50: .4byte 0x000343FD
_080BAF54: .4byte 0x00269EC3
_080BAF58: .4byte 0x00002710
_080BAF5C: .4byte 0x00002711
_080BAF60: .4byte 0x00002712
_080BAF64: .4byte 0x00002713
_080BAF68: .4byte 0x00002714
_080BAF6C: .4byte 0x00002715
_080BAF70: .4byte gVFXFnTable
_080BAF74:
	ldrb r1, [r7, #0xe]
	cmp r1, #0
	beq _080BAF80
	cmp r1, #1
	beq _080BAF96
	b _080BB022
_080BAF80:
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	str r1, [r7, #0x60]
	strb r1, [r7, #0x13]
	ldr r1, _080BB030 @ =0x0000270A
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BAF96:
	ldr r0, [r7, #0x60]
	adds r0, #8
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BAFA6
	str r1, [r7, #0x60]
_080BAFA6:
	ldrb r0, [r7, #0x12]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB00C
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r3, _080BB034 @ =RNG_0202f388
	mov sb, r3
	ldr r0, [r3]
	ldr r6, _080BB038 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _080BB03C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r8, r0
	lsrs r1, r1, #0x11
	ldr r5, _080BB040 @ =0x000007FF
	ands r1, r5
	add r4, sp, #0x10
	ldr r0, [r4, #4]
	subs r0, r0, r1
	str r0, [r4, #4]
	ldr r2, [sp, #0x10]
	ldr r1, _080BB044 @ =0xFFFFFC00
	adds r2, r2, r1
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, sb
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	adds r2, r2, r0
	str r2, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ba9f4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ba9f4
_080BB00C:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080BB022:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB030: .4byte 0x0000270A
_080BB034: .4byte RNG_0202f388
_080BB038: .4byte 0x000343FD
_080BB03C: .4byte 0x00269EC3
_080BB040: .4byte 0x000007FF
_080BB044: .4byte 0xFFFFFC00

	thumb_func_start FUN_080bb048
FUN_080bb048: @ 0x080BB048
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080BB07E
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080BB0A0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080BB0A0
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080BB0A0
_080BB07E:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080BB09C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080BB16E
	.align 2, 0
_080BB09C: .4byte gVFXFnTable
_080BB0A0:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080BB0AE
	cmp r0, #1
	beq _080BB118
	b _080BB16E
_080BB0AE:
	ldr r4, _080BB130 @ =0x0836ED24
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080BB134 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080BB138 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080BB13C @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BB118:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BB140
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BB146
	.align 2, 0
_080BB130: .4byte 0x0836ED24
_080BB134: .4byte RNG_0202f388
_080BB138: .4byte 0x000343FD
_080BB13C: .4byte 0x00269EC3
_080BB140:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BB146:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BB158
	str r1, [r7, #0x60]
_080BB158:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080BB16E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bb17c
FUN_080bb17c:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0xA0, 0x7C, 0x01, 0x38, 0xA0, 0x74, 0x00, 0x06, 0x00, 0x28, 0x0B, 0xD1, 0x04, 0x49, 0x60, 0x7A
	.byte 0x80, 0x00, 0x40, 0x18, 0x02, 0x21, 0xE1, 0x60, 0x00, 0x68, 0x80, 0x68, 0x60, 0x61, 0x92, 0xE0
	.byte 0x00, 0xD9, 0x36, 0x08, 0xA0, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28, 0x3B, 0xD0, 0x8A, 0xE0
	.byte 0x20, 0x7C, 0x00, 0x28, 0x1C, 0xD1, 0x0A, 0x4A, 0x11, 0x68, 0x0A, 0x48, 0x48, 0x43, 0x0A, 0x49
	.byte 0x40, 0x18, 0x40, 0x00, 0x41, 0x08, 0x11, 0x60, 0x40, 0x0C, 0x0A, 0x21, 0x43, 0xF0, 0x98, 0xFB
	.byte 0x1A, 0x30, 0xA0, 0x74, 0x05, 0x49, 0x20, 0x1C, 0x5C, 0xF7, 0xC6, 0xF9, 0x1E, 0xE0, 0x00, 0x00
	.byte 0x88, 0xF3, 0x02, 0x02, 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00, 0x0C, 0x27, 0x00, 0x00
	.byte 0x13, 0x4A, 0x11, 0x68, 0x13, 0x48, 0x48, 0x43, 0x13, 0x49, 0x40, 0x18, 0x40, 0x00, 0x41, 0x08
	.byte 0x11, 0x60, 0x40, 0x0C, 0x07, 0x21, 0x08, 0x40, 0x14, 0x30, 0xA0, 0x74, 0x0F, 0x49, 0x20, 0x1C
	.byte 0x5C, 0xF7, 0xAA, 0xF9, 0x21, 0x1C, 0x25, 0x31, 0x19, 0x20, 0x08, 0x70, 0x00, 0x20, 0xE0, 0x74
	.byte 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xE0, 0x7C, 0x01, 0x30, 0xE0, 0x74, 0xFF, 0x21, 0x08, 0x40
	.byte 0x01, 0x21, 0x08, 0x40, 0x00, 0x28, 0x0B, 0xD0, 0xA0, 0x7A, 0x08, 0x43, 0x0B, 0xE0, 0x00, 0x00
	.byte 0x88, 0xF3, 0x02, 0x02, 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00, 0x0D, 0x27, 0x00, 0x00
	.byte 0xA1, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0xA0, 0x72, 0xE2, 0x6F, 0xC0, 0x21, 0x49, 0x00, 0x89, 0x1A
	.byte 0x88, 0x00, 0x40, 0x18, 0xC0, 0x00, 0x00, 0x12, 0x12, 0x18, 0xE2, 0x67, 0x20, 0x1C, 0x50, 0x30
	.byte 0x02, 0x80, 0xE0, 0x6F, 0x21, 0x1C, 0x52, 0x31, 0x08, 0x80, 0x14, 0x4A, 0x11, 0x68, 0x14, 0x48
	.byte 0x48, 0x43, 0x14, 0x49, 0x40, 0x18, 0x40, 0x00, 0x41, 0x08, 0x11, 0x60, 0x40, 0x0C, 0x21, 0x1C
	.byte 0x24, 0x31, 0x08, 0x70, 0xE3, 0x6D, 0x59, 0x42, 0xC8, 0x00, 0x40, 0x18, 0x40, 0x00, 0x00, 0x12
	.byte 0x1B, 0x18, 0xE3, 0x65, 0x22, 0x6E, 0x51, 0x42, 0xC8, 0x00, 0x40, 0x18, 0x40, 0x00, 0x00, 0x12
	.byte 0x12, 0x18, 0x22, 0x66, 0xA0, 0x6D, 0x80, 0x18, 0xA0, 0x65, 0x60, 0x6D, 0xC0, 0x18, 0x60, 0x65
	.byte 0x20, 0x1C, 0x5C, 0xF7, 0xCB, 0xF9, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x88, 0xF3, 0x02, 0x02
	.byte 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00

	thumb_func_start FUN_080bb2d8
FUN_080bb2d8: @ 0x080BB2D8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB300
	ldr r1, _080BB2FC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080BB3C8
	.align 2, 0
_080BB2FC: .4byte gVFXFnTable
_080BB300:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BB30C
	cmp r0, #1
	beq _080BB366
	b _080BB3C8
_080BB30C:
	ldr r2, _080BB338 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB33C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB340 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080BB348
	ldr r1, _080BB344 @ =0x0000270C
	adds r0, r4, #0
	bl SetMotion
	b _080BB358
	.align 2, 0
_080BB338: .4byte RNG_0202f388
_080BB33C: .4byte 0x000343FD
_080BB340: .4byte 0x00269EC3
_080BB344: .4byte 0x0000270C
_080BB348:
	ldr r1, _080BB380 @ =0x0000270D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
_080BB358:
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x5c]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BB366:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BB384
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080BB38A
	.align 2, 0
_080BB380: .4byte 0x0000270D
_080BB384:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BB38A:
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x7c]
	movs r1, #0xc0
	lsls r1, r1, #1
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	strh r2, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, [r4, #0x60]
	ldr r0, _080BB3D0 @ =0xFFFFFF00
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BB3C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BB3D0: .4byte 0xFFFFFF00

	thumb_func_start FUN_080bb3d4
FUN_080bb3d4: @ 0x080BB3D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB400
	ldr r1, _080BB3FC @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080BB5BE
	.align 2, 0
_080BB3FC: .4byte gVFXFnTable
_080BB400:
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	bne _080BB408
	b _080BB51E
_080BB408:
	cmp r0, #1
	bgt _080BB412
	cmp r0, #0
	beq _080BB41A
	b _080BB5BE
_080BB412:
	cmp r0, #2
	bne _080BB418
	b _080BB54C
_080BB418:
	b _080BB5BE
_080BB41A:
	ldr r7, _080BB484 @ =RNG_0202f388
	ldr r0, [r7]
	ldr r1, _080BB488 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r5, _080BB48C @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r0, #0x14
	strb r0, [r6, #0x12]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	strb r0, [r6, #0x13]
	ldr r1, _080BB490 @ =0x0000270C
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0
	bne _080BB494
	ldr r0, [r7]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r0, r1
	b _080BB4AE
	.align 2, 0
_080BB484: .4byte RNG_0202f388
_080BB488: .4byte 0x000343FD
_080BB48C: .4byte 0x00269EC3
_080BB490: .4byte 0x0000270C
_080BB494:
	ldr r0, [r7]
	mov r1, r8
	muls r1, r0, r1
	ldr r0, _080BB4D4 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r7]
	lsrs r1, r1, #0x11
	movs r0, #0x7f
	ands r1, r0
	ldr r0, _080BB4D8 @ =0xFFFFFE40
	subs r0, r0, r1
_080BB4AE:
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _080BB4E4
	ldr r2, _080BB4DC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB4E0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB4D4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	adds r0, #0x20
	b _080BB502
	.align 2, 0
_080BB4D4: .4byte 0x00269EC3
_080BB4D8: .4byte 0xFFFFFE40
_080BB4DC: .4byte RNG_0202f388
_080BB4E0: .4byte 0x000343FD
_080BB4E4:
	ldr r2, _080BB540 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB544 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080BB548 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #0xff
	ands r1, r0
	movs r0, #0x20
	rsbs r0, r0, #0
	subs r0, r0, r1
_080BB502:
	str r0, [r6, #0x68]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	movs r0, #0
	str r0, [r6, #0x60]
	strb r0, [r6, #0x13]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080BB51E:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080BB52E
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB5BE
_080BB52E:
	ldrb r0, [r6, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080BB5BE
	.align 2, 0
_080BB540: .4byte RNG_0202f388
_080BB544: .4byte 0x000343FD
_080BB548: .4byte 0x00269EC3
_080BB54C:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldr r2, [r6, #0x7c]
	movs r1, #0xc0
	lsls r1, r1, #1
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x7c]
	adds r0, r6, #0
	adds r0, #0x50
	strh r2, [r0]
	ldr r0, [r6, #0x7c]
	adds r1, r6, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r2, _080BB5C8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB5CC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB5D0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	adds r1, r6, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r6, #0x68]
	ldr r3, [r6, #0x60]
	subs r0, r0, r3
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r6, #0x60]
	ldr r2, [r6, #0x5c]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	adds r0, r0, r3
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x54]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080BB5BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB5C8: .4byte RNG_0202f388
_080BB5CC: .4byte 0x000343FD
_080BB5D0: .4byte 0x00269EC3

	thumb_func_start FUN_080bb5d4
FUN_080bb5d4: @ 0x080BB5D4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB5FC
	ldr r1, _080BB5F8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080BB682
	.align 2, 0
_080BB5F8: .4byte gVFXFnTable
_080BB5FC:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080BB608
	cmp r5, #1
	beq _080BB636
	b _080BB682
_080BB608:
	ldr r2, _080BB650 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB654 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB658 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	adds r0, #0x12
	strb r0, [r4, #0x12]
	ldr r1, _080BB65C @ =0x0000270C
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BB636:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BB660
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080BB666
	.align 2, 0
_080BB650: .4byte RNG_0202f388
_080BB654: .4byte 0x000343FD
_080BB658: .4byte 0x00269EC3
_080BB65C: .4byte 0x0000270C
_080BB660:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BB666:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x60]
	ldr r1, _080BB688 @ =0xFFFFFF00
	subs r1, r1, r0
	lsls r1, r1, #4
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x60]
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BB682:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BB688: .4byte 0xFFFFFF00

	thumb_func_start FUN_080bb68c
FUN_080bb68c: @ 0x080BB68C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB6B4
	ldr r1, _080BB6B0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080BB7B8
	.align 2, 0
_080BB6B0: .4byte gVFXFnTable
_080BB6B4:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BB6C0
	cmp r0, #1
	beq _080BB732
	b _080BB7B8
_080BB6C0:
	ldr r2, _080BB6F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB6F4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB6F8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080BB700
	ldr r1, _080BB6FC @ =0x0000270E
	adds r0, r4, #0
	bl SetMotion
	b _080BB708
	.align 2, 0
_080BB6F0: .4byte RNG_0202f388
_080BB6F4: .4byte 0x000343FD
_080BB6F8: .4byte 0x00269EC3
_080BB6FC: .4byte 0x0000270E
_080BB700:
	ldr r1, _080BB74C @ =0x0000270F
	adds r0, r4, #0
	bl SetMotion
_080BB708:
	ldr r2, _080BB750 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BB754 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BB758 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	ldr r1, _080BB75C @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x5c]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BB732:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BB760
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080BB766
	.align 2, 0
_080BB74C: .4byte 0x0000270F
_080BB750: .4byte RNG_0202f388
_080BB754: .4byte 0x000343FD
_080BB758: .4byte 0x00269EC3
_080BB75C: .4byte 0xFFFFFF00
_080BB760:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BB766:
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x7c]
	movs r1, #0xc0
	lsls r1, r1, #1
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x50
	strh r2, [r0]
	ldr r0, [r4, #0x7c]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r2, [r4, #0x60]
	ldr r0, _080BB7C0 @ =0xFFFFFF00
	subs r0, r0, r2
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BB7B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BB7C0: .4byte 0xFFFFFF00

	thumb_func_start FUN_080bb7c4
FUN_080bb7c4: @ 0x080BB7C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB7EC
	ldr r1, _080BB7E8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080BB824
	.align 2, 0
_080BB7E8: .4byte gVFXFnTable
_080BB7EC:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080BB7F8
	cmp r5, #1
	beq _080BB808
	b _080BB824
_080BB7F8:
	ldr r1, _080BB82C @ =0x0000270C
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BB808:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BB824:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BB82C: .4byte 0x0000270C
