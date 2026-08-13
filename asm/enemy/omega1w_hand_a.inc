	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806a8fc
FUN_0806a8fc: @ 0x0806A8FC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #0xe]
	cmp r3, #1
	beq _0806A9DE
	cmp r3, #1
	bgt _0806A910
	cmp r3, #0
	beq _0806A91E
	b _0806AA4C
_0806A910:
	cmp r3, #2
	bne _0806A916
	b _0806AA2C
_0806A916:
	cmp r3, #3
	bne _0806A91C
	b _0806AA44
_0806A91C:
	b _0806AA4C
_0806A91E:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806A970
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x24
	strb r3, [r0]
	ldr r1, _0806A96C @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	b _0806A9B8
	.align 2, 0
_0806A96C: .4byte 0x00000901
_0806A970:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x24
	strb r3, [r0]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
_0806A9B8:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	str r1, [r4, #0x5c]
	str r1, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806A9DE:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806A9F2
	ldr r1, [r4, #0x28]
	ldr r2, [r4, #0x58]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r2, r3
	ldr r1, [r1, #0x58]
	b _0806AA16
_0806A9F2:
	ldr r3, [r4, #0x28]
	ldr r2, [r4, #0x54]
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r1, [r3, #0x54]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r1, #0xe8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r3, #0x58]
_0806AA16:
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0806AA4C
_0806AA2C:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806AA4C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806AA4C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0806AA4C
_0806AA44:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806AA4C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806aa54
FUN_0806aa54: @ 0x0806AA54
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806AA90
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806AA98 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0806AA90:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806AA98: .4byte gEnemyFnTable

	thumb_func_start FUN_0806aa9c
FUN_0806aa9c: @ 0x0806AA9C
	movs r0, #1
	bx lr

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

	thumb_func_start FUN_0806ae90
FUN_0806ae90: @ 0x0806AE90
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806ae94
FUN_0806ae94: @ 0x0806AE94
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806AEA4
	cmp r0, #1
	beq _0806AEC6
	b _0806AED4
_0806AEA4:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806AEC6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806AED4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806aedc
FUN_0806aedc: @ 0x0806AEDC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806AEEC
	cmp r0, #1
	beq _0806AF0C
	b _0806AF1A
_0806AEEC:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r1, _0806AF20 @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806AF0C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806AF1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806AF20: .4byte 0x00000901

	thumb_func_start FUN_0806af24
FUN_0806af24: @ 0x0806AF24
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	bne _0806AF38
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0806AF38:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806af40
FUN_0806af40: @ 0x0806AF40
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806AF50
	cmp r5, #1
	beq _0806AF9A
	b _0806AFCE
_0806AF50:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1d]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806AFD4 @ =sCollisions
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806AF9A:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _0806AFD8 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	adds r0, r0, r3
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806AFCE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806AFD4: .4byte sCollisions
_0806AFD8: .4byte gSineTable

	thumb_func_start FUN_0806afdc
FUN_0806afdc: @ 0x0806AFDC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806AFEC
	cmp r5, #1
	beq _0806B04C
	b _0806B082
_0806AFEC:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r1, _0806B088 @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806B08C @ =0x08366478
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806B04C:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _0806B090 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r3, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r3, #0x58]
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806B082:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806B088: .4byte 0x00000901
_0806B08C: .4byte sCollisions+(24*3)
_0806B090: .4byte gSineTable

	thumb_func_start FUN_0806b094
FUN_0806b094: @ 0x0806B094
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806b098
FUN_0806b098: @ 0x0806B098
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0806B0A8
	cmp r3, #1
	beq _0806B0D2
	b _0806B0D8
_0806B0A8:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_0806B0D2:
	adds r0, r2, #0
	bl UpdateEntityAnim
_0806B0D8:
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b0dc
FUN_0806b0dc: @ 0x0806B0DC
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0806B0EC
	cmp r3, #1
	beq _0806B116
	b _0806B11C
_0806B0EC:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_0806B116:
	adds r0, r2, #0
	bl UpdateEntityAnim
_0806B11C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b120
FUN_0806b120: @ 0x0806B120
	movs r0, #1
	bx lr
