	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806aaa0
FUN_0806aaa0: @ 0x0806AAA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _0806AAAC
	b _0806AC90
_0806AAAC:
	lsls r0, r0, #2
	ldr r1, _0806AAB8 @ =_0806AABC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806AAB8: .4byte _0806AABC
_0806AABC: @ jump table
	.4byte _0806AAD4 @ case 0
	.4byte _0806AADA @ case 1
	.4byte _0806AAEC @ case 2
	.4byte _0806ABB8 @ case 3
	.4byte _0806AC18 @ case 4
	.4byte _0806AC80 @ case 5
_0806AAD4:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806AADA:
	ldr r0, [r5, #0x28]
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0806AAEA
	b _0806AC90
_0806AAEA:
	b _0806AC78
_0806AAEC:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x58]
	ldr r4, _0806AB6C @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x5c
	str r6, [r0, #4]
	str r6, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0806AB70 @ =0xFFFFFC00
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r5, #0x68]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	bne _0806AB74
	movs r0, #0x80
	strb r0, [r5, #0x12]
	strb r6, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xe]
	adds r0, #2
	b _0806ABB6
	.align 2, 0
_0806AB6C: .4byte 0xFFFFE800
_0806AB70: .4byte 0xFFFFFC00
_0806AB74:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r2, _0806AC0C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806AC10 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806AC14 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	strb r0, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	strb r6, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
_0806ABB6:
	strb r0, [r5, #0xe]
_0806ABB8:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x13]
	ldrb r4, [r5, #0x12]
	adds r1, r4, #0
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806ABFE
	adds r0, r4, #0
	subs r0, #0xa
	strb r0, [r5, #0x12]
	ldr r2, _0806AC0C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806AC10 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806AC14 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	subs r0, #3
	lsls r0, r0, #8
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	str r1, [r5, #0x54]
_0806ABFE:
	ldrb r1, [r5, #0x12]
	cmp r1, #0
	bne _0806AC90
	movs r0, #0x80
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	b _0806AC78
	.align 2, 0
_0806AC0C: .4byte RNG_0202f388
_0806AC10: .4byte 0x000343FD
_0806AC14: .4byte 0x00269EC3
_0806AC18:
	ldrb r3, [r5, #0x12]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _0806AC36
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r5, #0x28]
	ldr r1, [r0]
	ldr r0, [r2, #0x54]
	adds r1, r1, r0
	lsrs r0, r3, #3
	lsls r0, r0, #8
	adds r1, r1, r0
	b _0806AC4A
_0806AC36:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r5, #0x28]
	ldr r1, [r0]
	ldr r0, [r2, #0x54]
	adds r1, r1, r0
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1b
	lsls r0, r0, #8
	subs r1, r1, r0
_0806AC4A:
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806AC78
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806AC90
_0806AC78:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0806AC90
_0806AC80:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r2, [r5, #0xe]
_0806AC90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806ac98
FUN_0806ac98: @ 0x0806AC98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _0806ACA4
	b _0806AE88
_0806ACA4:
	lsls r0, r0, #2
	ldr r1, _0806ACB0 @ =_0806ACB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806ACB0: .4byte _0806ACB4
_0806ACB4: @ jump table
	.4byte _0806ACCC @ case 0
	.4byte _0806ACD2 @ case 1
	.4byte _0806ACE4 @ case 2
	.4byte _0806ADB2 @ case 3
	.4byte _0806AE10 @ case 4
	.4byte _0806AE78 @ case 5
_0806ACCC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806ACD2:
	ldr r0, [r5, #0x28]
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0806ACE2
	b _0806AE88
_0806ACE2:
	b _0806AE70
_0806ACE4:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x58]
	ldr r4, _0806AD64 @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _0806AD68 @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x5c
	str r6, [r0, #4]
	str r6, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0806AD6C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r5, #0x68]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	bne _0806AD70
	movs r0, #0x80
	strb r0, [r5, #0x12]
	strb r6, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xe]
	adds r0, #2
	b _0806ADB0
	.align 2, 0
_0806AD64: .4byte 0xFFFFE800
_0806AD68: .4byte 0x00000901
_0806AD6C: .4byte 0xFFFFF000
_0806AD70:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r2, _0806AE04 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806AE08 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806AE0C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	strb r0, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xe]
	adds r0, #1
_0806ADB0:
	strb r0, [r5, #0xe]
_0806ADB2:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x13]
	ldrb r4, [r5, #0x12]
	adds r1, r4, #0
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806ADF6
	adds r0, r4, #0
	subs r0, #0xa
	strb r0, [r5, #0x12]
	ldr r2, _0806AE04 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806AE08 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806AE0C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	subs r0, #4
	lsls r0, r0, #8
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	str r1, [r5, #0x54]
_0806ADF6:
	ldrb r1, [r5, #0x12]
	cmp r1, #0
	bne _0806AE88
	movs r0, #0x80
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	b _0806AE70
	.align 2, 0
_0806AE04: .4byte RNG_0202f388
_0806AE08: .4byte 0x000343FD
_0806AE0C: .4byte 0x00269EC3
_0806AE10:
	ldrb r3, [r5, #0x12]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _0806AE2E
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r5, #0x28]
	ldr r1, [r0]
	ldr r0, [r2, #0x54]
	adds r1, r1, r0
	lsrs r0, r3, #3
	lsls r0, r0, #8
	adds r1, r1, r0
	b _0806AE42
_0806AE2E:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r5, #0x28]
	ldr r1, [r0]
	ldr r0, [r2, #0x54]
	adds r1, r1, r0
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1b
	lsls r0, r0, #8
	subs r1, r1, r0
_0806AE42:
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806AE70
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806AE88
_0806AE70:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0806AE88
_0806AE78:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r2, [r5, #0xe]
_0806AE88:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

