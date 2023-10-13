	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateOmegaGoldSword
CreateOmegaGoldSword: @ 0x0808B798
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0808B7F4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808B7EA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808B7F8 @ =gEnemyFnTable
	movs r1, #0x35
	strb r1, [r3, #9]
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
	str r6, [r3, #0x28]
_0808B7EA:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0808B7F4: .4byte gZakoHeaderPtr
_0808B7F8: .4byte gEnemyFnTable

	thumb_func_start OmegaGoldSword_Init
OmegaGoldSword_Init: @ 0x0808B7FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl InitNonAffineMotion
	movs r5, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r2, #1
	movs r6, #1
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r7, #0xa]
	orrs r0, r2
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _0808B8A4 @ =0x08368DC4
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	ldr r0, _0808B8A8 @ =nop_0808c384
	str r0, [r4, #0x24]
	adds r0, r7, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r7, #0x5c]
	ldr r1, _0808B8AC @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r5, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _0808B8B0 @ =0xFFFFED00
	str r0, [r1]
	adds r1, #4
	ldr r0, _0808B8B4 @ =0xFFFFC600
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r5, [r0]
	ldrb r1, [r7, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r7, #0x1d]
	adds r0, r7, #0
	bl OmegaGoldSword_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B8A4: .4byte 0x08368DC4
_0808B8A8: .4byte nop_0808c384
_0808B8AC: .4byte gEnemyFnTable
_0808B8B0: .4byte 0xFFFFED00
_0808B8B4: .4byte 0xFFFFC600

	thumb_func_start OmegaGoldSword_Update
OmegaGoldSword_Update: @ 0x0808B8B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808B8F0
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0808B8EC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl OmegaGoldSword_Die
	b _0808B910
	.align 2, 0
_0808B8EC: .4byte gEnemyFnTable
_0808B8F0:
	ldr r1, _0808B918 @ =0x08368D94
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808B91C @ =0x08368DA8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808B910:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B918: .4byte 0x08368D94
_0808B91C: .4byte 0x08368DA8

	thumb_func_start OmegaGoldSword_Die
OmegaGoldSword_Die: @ 0x0808B920
	push {lr}
	ldr r2, _0808B934 @ =0x08368DBC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0808B934: .4byte 0x08368DBC

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
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0808BB36
	.align 2, 0
_0808BB10: .4byte 0x00006505
_0808BB14:
	adds r0, r5, #0
	bl UpdateMotionGraphic
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

	thumb_func_start FUN_0808bb58
FUN_0808bb58:
	.byte 0x00, 0xB5, 0x02, 0x1C, 0x90, 0x7B, 0x00, 0x28
	.byte 0x0C, 0xD1, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00
	.byte 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x01, 0xBC, 0x00, 0x47
	.byte 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_0808bb84
FUN_0808bb84:
  movs r0, #1
	bx lr

	thumb_func_start FUN_0808bb88
FUN_0808bb88: @ 0x0808BB88
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808BB98
	cmp r0, #1
	beq _0808BBBE
	b _0808BBDA
_0808BB98:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xca
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808BBE0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808BBBE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808BBDA
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808BBDA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808BBE0: .4byte 0xFFFFC000

	thumb_func_start FUN_0808bbe4
FUN_0808bbe4:
  movs r0, #1
	bx lr

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
	bl UpdateMotionGraphic
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

	thumb_func_start FUN_0808bd00
FUN_0808bd00: @ 0x0808BD00
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #6
	bne _0808BD14
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0808BD14:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808bd1c
FUN_0808bd1c:
	.byte 0x30, 0xB5, 0x04, 0x1C
	.byte 0xA5, 0x7B, 0x00, 0x2D, 0x02, 0xD0, 0x01, 0x2D, 0x1F, 0xD0, 0x28, 0xE0, 0xE1, 0x7A, 0x10, 0x20
	.byte 0x08, 0x43, 0xE0, 0x72, 0xA0, 0x6A, 0x00, 0x7F, 0x60, 0x77, 0x12, 0x49, 0x20, 0x1C, 0x8B, 0xF7
	.byte 0x13, 0xFC, 0xA1, 0x7A, 0xEF, 0x20, 0x08, 0x40, 0xA0, 0x72, 0x20, 0x1C, 0x4C, 0x30, 0x05, 0x70
	.byte 0x22, 0x1C, 0x4A, 0x32, 0x11, 0x78, 0x11, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x70, 0x25, 0x66
	.byte 0xE5, 0x65, 0xA5, 0x74, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xA0, 0x6A, 0x81, 0x6D, 0x06, 0x4A
	.byte 0x89, 0x18, 0xA1, 0x65, 0x40, 0x6D, 0x60, 0x65, 0x20, 0x1C, 0x8B, 0xF7, 0x6F, 0xFC, 0x30, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x01, 0x65, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF

	thumb_func_start FUN_0808bd8c
FUN_0808bd8c: @ 0x0808BD8C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808bd90
FUN_0808bd90: @ 0x0808BD90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0x1e
	bls _0808BDA2
	b _0808C31C
_0808BDA2:
	lsls r0, r0, #2
	ldr r1, _0808BDAC @ =_0808BDB0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808BDAC: .4byte _0808BDB0
_0808BDB0: @ jump table
	.4byte _0808BE2C @ case 0
	.4byte _0808C2C2 @ case 1
	.4byte _0808BE44 @ case 2
	.4byte _0808BE56 @ case 3
	.4byte _0808BE70 @ case 4
	.4byte _0808BE82 @ case 5
	.4byte _0808BEA8 @ case 6
	.4byte _0808BEB2 @ case 7
	.4byte _0808BEC8 @ case 8
	.4byte _0808BEE0 @ case 9
	.4byte _0808BF12 @ case 10
	.4byte _0808BF48 @ case 11
	.4byte _0808BF64 @ case 12
	.4byte _0808BF9C @ case 13
	.4byte _0808BFAC @ case 14
	.4byte _0808BFF2 @ case 15
	.4byte _0808C010 @ case 16
	.4byte _0808C06C @ case 17
	.4byte _0808C194 @ case 18
	.4byte _0808C1B6 @ case 19
	.4byte _0808C1D0 @ case 20
	.4byte _0808C1EC @ case 21
	.4byte _0808C218 @ case 22
	.4byte _0808C24E @ case 23
	.4byte _0808C298 @ case 24
	.4byte _0808C2B4 @ case 25
	.4byte _0808C2E4 @ case 26
	.4byte _0808C31C @ case 27
	.4byte _0808C31C @ case 28
	.4byte _0808C31C @ case 29
	.4byte _0808C2F4 @ case 30
_0808BE2C:
	ldr r1, _0808BE40 @ =0x00006502
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808C2C2
	.align 2, 0
_0808BE40: .4byte 0x00006502
_0808BE44:
	ldr r1, _0808BE6C @ =0x00006503
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BE56:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BE6A
	b _0808C31C
_0808BE6A:
	b _0808C2D2
	.align 2, 0
_0808BE6C: .4byte 0x00006503
_0808BE70:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	movs r0, #0xa
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BE82:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BEA6
	b _0808C31C
_0808BEA6:
	b _0808C2D2
_0808BEA8:
	movs r0, #0xa
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BEB2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BEC6
	b _0808C31C
_0808BEC6:
	b _0808C2D2
_0808BEC8:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	adds r0, #0x60
	str r0, [r7, #0x64]
	str r0, [r7, #0x68]
	movs r0, #0x12
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BEE0:
	ldr r2, [r7, #0x5c]
	ldr r0, [r7, #0x64]
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	ldr r0, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BF10
	b _0808C31C
_0808BF10:
	b _0808C2D2
_0808BF12:
	ldr r1, _0808BF88 @ =0x00006506
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0808BF8C @ =0x08368DDC
	bl SetDDP
	adds r1, r7, #0
	adds r1, #0xc0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0808BF90 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0808BF94 @ =0xFFFF2000
	adds r0, r0, r1
	str r0, [r7, #0x58]
	movs r0, #3
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BF48:
	ldr r1, _0808BF88 @ =0x00006506
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0808BF98 @ =0xFFFF7000
	adds r0, r0, r2
	str r0, [r7, #0x68]
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BF64:
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BF86
	b _0808C31C
_0808BF86:
	b _0808C2D2
	.align 2, 0
_0808BF88: .4byte 0x00006506
_0808BF8C: .4byte 0x08368DDC
_0808BF90: .4byte pZero2
_0808BF94: .4byte 0xFFFF2000
_0808BF98: .4byte 0xFFFF7000
_0808BF9C:
	movs r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	movs r0, #0x40
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BFAC:
	ldr r0, _0808BFBC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r7, #0x54]
	cmp r2, r0
	ble _0808BFC4
	ldr r0, _0808BFC0 @ =0xFFFFFE00
	b _0808BFC8
	.align 2, 0
_0808BFBC: .4byte pZero2
_0808BFC0: .4byte 0xFFFFFE00
_0808BFC4:
	movs r0, #0x80
	lsls r0, r0, #2
_0808BFC8:
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r1, r2, r1
	str r1, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BFF0
	b _0808C31C
_0808BFF0:
	b _0808C2D2
_0808BFF2:
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0808C04C @ =0x0000012F
	bl PlaySound
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C010:
	ldr r0, [r7, #0x60]
	adds r0, #0x80
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808C020
	str r1, [r7, #0x60]
_0808C020:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r1, r0, r1
	str r1, [r7, #0x58]
	ldrb r0, [r7, #0x13]
	cmp r0, #1
	bne _0808C050
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0808C042
	b _0808C31C
_0808C042:
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	b _0808C2D2
	.align 2, 0
_0808C04C: .4byte 0x0000012F
_0808C050:
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0808C064
	b _0808C31C
_0808C064:
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	b _0808C2D2
_0808C06C:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, _0808C168 @ =0x00006507
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C17C
	movs r0, #8
	mov r1, sp
	bl AppendQuake
	movs r0, #0x41
	bl PlaySound
	ldr r4, _0808C16C @ =0x00000C01
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080ac9b4
	mov r0, sp
	movs r1, #1
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080ac9b4
	ldr r5, _0808C170 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r2, _0808C174 @ =0x000343FD
	mov r8, r2
	mov r1, r8
	muls r1, r0, r1
	ldr r6, _0808C178 @ =0x00269EC3
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r5]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r1, #2
	mov r0, sp
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080ac9b4
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r5]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r4, #0xf
	ands r0, r4
	subs r0, #8
	lsls r0, r0, #8
	ldr r1, [sp]
	adds r1, r1, r0
	str r1, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	ands r0, r4
	subs r0, #0xa
	lsls r0, r0, #8
	ldr r1, [sp, #4]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r5]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r4
	subs r0, #8
	lsls r0, r0, #8
	ldr r1, [sp]
	adds r1, r1, r0
	str r1, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	ands r0, r4
	subs r0, #0xa
	lsls r0, r0, #8
	ldr r1, [sp, #4]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	b _0808C184
	.align 2, 0
_0808C168: .4byte 0x00006507
_0808C16C: .4byte 0x00000C01
_0808C170: .4byte RNG_0202f388
_0808C174: .4byte 0x000343FD
_0808C178: .4byte 0x00269EC3
_0808C17C:
	movs r0, #4
	mov r1, sp
	bl AppendQuake
_0808C184:
	movs r0, #0x14
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C194:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808C1A6
	b _0808C31C
_0808C1A6:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808C1B4
	b _0808C31C
_0808C1B4:
	b _0808C2D2
_0808C1B6:
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _0808C1CA
	b _0808C2D2
_0808C1CA:
	movs r0, #0xb
	strb r0, [r7, #0xe]
	b _0808C31C
_0808C1D0:
	ldr r1, _0808C210 @ =0x00006506
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0808C214 @ =0xFFFF6600
	adds r0, r0, r1
	str r0, [r7, #0x68]
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C1EC:
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808C20E
	b _0808C31C
_0808C20E:
	b _0808C2D2
	.align 2, 0
_0808C210: .4byte 0x00006506
_0808C214: .4byte 0xFFFF6600
_0808C218:
	ldr r1, _0808C288 @ =0x00006503
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0808C28C @ =0x08368DC4
	bl SetDDP
	adds r1, r7, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0808C290 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _0808C294 @ =0xFFFF8000
	adds r0, r0, r1
	str r0, [r7, #0x58]
	movs r0, #0x12
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C24E:
	ldr r3, [r7, #0x28]
	ldr r0, [r3, #0x54]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r0, #0x80
	lsls r0, r0, #7
	adds r2, r1, r0
	ldr r0, [r3, #0x58]
	subs r0, r0, r2
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C31C
	b _0808C2D2
	.align 2, 0
_0808C288: .4byte 0x00006503
_0808C28C: .4byte 0x08368DC4
_0808C290: .4byte 0xFFFFC000
_0808C294: .4byte 0xFFFF8000
_0808C298:
	ldr r1, _0808C2DC @ =0x00006504
	adds r0, r7, #0
	bl SetMotion
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808C2E0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C2B4:
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808C2E0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
_0808C2C2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808C31C
_0808C2D2:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808C31C
	.align 2, 0
_0808C2DC: .4byte 0x00006504
_0808C2E0: .4byte 0xFFFFC000
_0808C2E4:
	ldr r1, _0808C328 @ =0x00006501
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	movs r0, #0x1e
	strb r0, [r7, #0xe]
_0808C2F4:
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808C32C @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808C31C
	movs r0, #2
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_0808C31C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C328: .4byte 0x00006501
_0808C32C: .4byte 0xFFFFC000

	thumb_func_start FUN_0808c330
FUN_0808c330:
  movs r0, #1
	bx lr

	thumb_func_start FUN_0808c334
FUN_0808c334: @ 0x0808C334
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0808C344
	cmp r3, #1
	beq _0808C364
	b _0808C380
_0808C344:
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	str r3, [r2, #0x5c]
	str r3, [r2, #0x60]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_0808C364:
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	cmp r0, #0x40
	ble _0808C372
	movs r0, #0x40
	str r0, [r2, #0x60]
_0808C372:
	ldr r0, [r2, #0x58]
	ldr r1, [r2, #0x60]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r0, r2, #0
	bl UpdateMotionGraphic
_0808C380:
	pop {r0}
	bx r0

	thumb_func_start nop_0808c384
nop_0808c384: @ 0x0808C384
	bx lr
	.align 2, 0
