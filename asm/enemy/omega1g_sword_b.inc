	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808b938
FUN_0808b938: @ 0x0808B938
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	ldrb r2, [r5, #0xe]
	cmp r2, #1
	bne _0808B94E
	b _0808BB14
_0808B94E:
	cmp r2, #1
	bgt _0808B958
	cmp r2, #0
	beq _0808B966
	b _0808BB46
_0808B958:
	cmp r2, #2
	bne _0808B95E
	b _0808BB26
_0808B95E:
	cmp r2, #3
	bne _0808B964
	b _0808BB3E
_0808B964:
	b _0808BB46
_0808B966:
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	str r2, [r5, #0x5c]
	str r2, [r5, #0x60]
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x70
	ldrb r1, [r2]
	orrs r0, r1
	ldr r1, _0808BA24 @ =0xFFFF9AFA
	adds r0, r0, r1
	str r2, [sp, #0x14]
	cmp r0, #1
	bhi _0808BA3C
	ldr r2, _0808BA28 @ =RNG_0202f388
	mov sl, r2
	mov r0, sp
	str r0, [sp, #0x10]
	movs r1, #0
	mov sb, r1
	ldr r7, _0808BA2C @ =0x08368E54
	movs r2, #3
	mov r8, r2
	ldr r6, _0808BA30 @ =0x08368E74
_0808B9AE:
	mov r0, sl
	ldr r1, [r0]
	ldr r0, _0808BA34 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808BA38 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	mov r2, sl
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	ldr r1, [r7]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, [r7, #4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r2, [sp, #0x10]
	str r0, [r2, #4]
	ldrh r3, [r6]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080c1cf4
	ldr r0, _0808BA30 @ =0x08368E74
	adds r0, #2
	add r0, sb
	ldrh r3, [r0]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080c1cf4
	ldrh r3, [r6, #4]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080c1cf4
	adds r6, #6
	movs r0, #6
	add sb, r0
	adds r7, #8
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	bge _0808B9AE
	b _0808BAC0
	.align 2, 0
_0808BA24: .4byte 0xFFFF9AFA
_0808BA28: .4byte RNG_0202f388
_0808BA2C: .4byte 0x08368E54
_0808BA30: .4byte 0x08368E74
_0808BA34: .4byte 0x000343FD
_0808BA38: .4byte 0x00269EC3
_0808BA3C:
	add r6, sp, #8
	movs r0, #0
	mov sl, r0
	ldr r1, _0808BAE0 @ =0x08368E8C
	mov r8, r1
	movs r2, #3
	mov sb, r2
	ldr r7, _0808BAE4 @ =0x08368EAC
_0808BA4C:
	ldr r0, _0808BAE8 @ =RNG_0202f388
	ldr r1, [r0]
	ldr r0, _0808BAEC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808BAF0 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	ldr r2, _0808BAE8 @ =RNG_0202f388
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	mov r2, r8
	ldr r1, [r2]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r6, #4]
	ldrh r3, [r7]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080c1cf4
	ldr r0, _0808BAE4 @ =0x08368EAC
	adds r0, #2
	add r0, sl
	ldrh r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080c1cf4
	ldrh r3, [r7, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080c1cf4
	adds r7, #6
	movs r2, #6
	add sl, r2
	movs r0, #8
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r2, sb
	cmp r2, #0
	bge _0808BA4C
_0808BAC0:
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	ldr r2, [sp, #0x14]
	ldrb r1, [r2]
	orrs r0, r1
	ldr r1, _0808BAF4 @ =0x00006501
	cmp r0, r1
	bne _0808BAF8
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
	movs r0, #2
	strb r0, [r5, #0xe]
	b _0808BB46
	.align 2, 0
_0808BAE0: .4byte 0x08368E8C
_0808BAE4: .4byte 0x08368EAC
_0808BAE8: .4byte RNG_0202f388
_0808BAEC: .4byte 0x000343FD
_0808BAF0: .4byte 0x00269EC3
_0808BAF4: .4byte 0x00006501
_0808BAF8:
	ldr r1, _0808BB10 @ =0x00006505
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0808BB36
	.align 2, 0
_0808BB10: .4byte 0x00006505
_0808BB14:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808BB46
	b _0808BB36
_0808BB26:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0808BB46
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808BB46
_0808BB36:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808BB46
_0808BB3E:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808BB46:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
