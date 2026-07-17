	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808bbe8
FUN_0808bbe8: @ 0x0808BBE8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0808BC34
	cmp r0, #1
	bgt _0808BC04
	cmp r0, #0
	beq _0808BC0A
	b _0808BCD0
_0808BC04:
	cmp r0, #2
	beq _0808BC58
	b _0808BCD0
_0808BC0A:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xca
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808BC54 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r5, #0x54]
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808BC34:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0808BC4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808BCD0
_0808BC4A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808BCD0
	.align 2, 0
_0808BC54: .4byte 0xFFFFC000
_0808BC58:
	ldr r1, _0808BCE0 @ =0x00006501
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x41
	bl PlaySound
	ldr r0, _0808BCE4 @ =RNG_0202f388
	mov r8, r0
	mov sb, sp
	ldr r6, _0808BCE8 @ =0x08368EC4
	movs r7, #5
_0808BC70:
	mov r2, r8
	ldr r1, [r2]
	ldr r0, _0808BCEC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0808BCF0 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	ldr r1, [r6]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, [r6, #4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	mov r2, sb
	str r0, [r2, #4]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0808BCF4 @ =0x0000650E
	bl FUN_080c1c94
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0808BCF8 @ =0x0000650F
	bl FUN_080c1c94
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0808BCFC @ =0x00006510
	bl FUN_080c1c94
	adds r6, #8
	subs r7, #1
	cmp r7, #0
	bge _0808BC70
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808BCD0:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808BCE0: .4byte 0x00006501
_0808BCE4: .4byte RNG_0202f388
_0808BCE8: .4byte 0x08368EC4
_0808BCEC: .4byte 0x000343FD
_0808BCF0: .4byte 0x00269EC3
_0808BCF4: .4byte 0x0000650E
_0808BCF8: .4byte 0x0000650F
_0808BCFC: .4byte 0x00006510

