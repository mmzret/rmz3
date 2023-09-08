	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start OmegaWhiteHand_Init
OmegaWhiteHand_Init: @ 0x0806A72C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl InitScalerotMotion1
	adds r0, r6, #0
	adds r0, #0x24
	movs r7, #0
	strb r7, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r5, #1
	adds r0, r6, #0
	adds r0, #0x4c
	strb r7, [r0]
	movs r0, #0x4a
	adds r0, r0, r6
	mov r8, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, r8
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806A7CC @ =0x08366430
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _0806A7D0 @ =nop_0806be0c
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x5c
	str r7, [r0, #4]
	str r7, [r6, #0x5c]
	ldr r1, _0806A7D4 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r5, [r6, #0xf]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0806A7E0
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, _0806A7D8 @ =0xFFFFED00
	str r0, [r1]
	adds r1, #4
	ldr r0, _0806A7DC @ =0xFFFFC600
	str r0, [r1]
	b _0806A812
	.align 2, 0
_0806A7CC: .4byte 0x08366430
_0806A7D0: .4byte nop_0806be0c
_0806A7D4: .4byte gEnemyFnTable
_0806A7D8: .4byte 0xFFFFED00
_0806A7DC: .4byte 0xFFFFC600
_0806A7E0:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	adds r1, #0x8f
	movs r0, #0xa8
	lsls r0, r0, #5
	str r0, [r1]
	adds r1, #4
	ldr r0, _0806A830 @ =0xFFFFC800
	str r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r7, [r0]
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, r8
	strb r0, [r1]
_0806A812:
	ldrb r1, [r6, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	adds r0, r6, #0
	bl OmegaWhiteHand_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A830: .4byte 0xFFFFC800

	thumb_func_start OmegaWhiteHand_Update
OmegaWhiteHand_Update: @ 0x0806A834
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #2
	bls _0806A87C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806A878 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0806A8D8
	.align 2, 0
_0806A878: .4byte gEnemyFnTable
_0806A87C:
	adds r0, r1, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806A898
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _0806A898
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806A898:
	ldr r1, _0806A8C0 @ =0x083663E0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0806A8C8
	ldr r0, _0806A8C4 @ =0x083663F8
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	b _0806A8D8
	.align 2, 0
_0806A8C0: .4byte 0x083663E0
_0806A8C4: .4byte 0x083663F8
_0806A8C8:
	ldr r0, _0806A8E0 @ =0x08366410
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0806A8D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806A8E0: .4byte 0x08366410

	thumb_func_start OmegaWhiteHand_Die
OmegaWhiteHand_Die: @ 0x0806A8E4
	push {lr}
	ldr r2, _0806A8F8 @ =0x08366428
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0806A8F8: .4byte 0x08366428

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	ldr r1, _0806AFD4 @ =0x08366430
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
	bl UpdateMotionGraphic
_0806AFCE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806AFD4: .4byte 0x08366430
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
	bl UpdateMotionGraphic
_0806B082:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806B088: .4byte 0x00000901
_0806B08C: .4byte 0x08366478
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
_0806B11C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b120
FUN_0806b120: @ 0x0806B120
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806b124
FUN_0806b124: @ 0x0806B124
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _0806B132
	b _0806B4C4
_0806B132:
	lsls r0, r0, #2
	ldr r1, _0806B13C @ =_0806B140
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B13C: .4byte _0806B140
_0806B140: @ jump table
	.4byte _0806B1A4 @ case 0
	.4byte _0806B1AE @ case 1
	.4byte _0806B1E8 @ case 2
	.4byte _0806B1FE @ case 3
	.4byte _0806B216 @ case 4
	.4byte _0806B260 @ case 5
	.4byte _0806B2D0 @ case 6
	.4byte _0806B2F6 @ case 7
	.4byte _0806B4C4 @ case 8
	.4byte _0806B4C4 @ case 9
	.4byte _0806B380 @ case 10
	.4byte _0806B3C4 @ case 11
	.4byte _0806B3E0 @ case 12
	.4byte _0806B4C4 @ case 13
	.4byte _0806B4C4 @ case 14
	.4byte _0806B4C4 @ case 15
	.4byte _0806B4C4 @ case 16
	.4byte _0806B4C4 @ case 17
	.4byte _0806B4C4 @ case 18
	.4byte _0806B4C4 @ case 19
	.4byte _0806B3FA @ case 20
	.4byte _0806B430 @ case 21
	.4byte _0806B470 @ case 22
	.4byte _0806B4A8 @ case 23
	.4byte _0806B4AE @ case 24
_0806B1A4:
	movs r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B1AE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	ldr r1, _0806B1E0 @ =0xFFFFFD00
	cmp r0, r1
	bge _0806B1C2
	str r1, [r5, #0x60]
_0806B1C2:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B1E4 @ =0xFFFF8600
	adds r0, r0, r2
	cmp r1, r0
	blt _0806B1D8
	b _0806B4C4
_0806B1D8:
	str r0, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _0806B49C
	.align 2, 0
_0806B1E0: .4byte 0xFFFFFD00
_0806B1E4: .4byte 0xFFFF8600
_0806B1E8:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B1F0
	b _0806B4C4
_0806B1F0:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B1FC
	b _0806B4C4
_0806B1FC:
	b _0806B49C
_0806B1FE:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B2B4 @ =0x08366448
	bl SetDDP
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B216:
	ldr r1, _0806B2B8 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _0806B2BC @ =0x083664A8
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _0806B2C0 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B260:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B2C4 @ =0xFFFF8800
	adds r4, r0, #0
	cmp r2, r1
	bge _0806B27E
	ldr r0, [r5, #0x5c]
	subs r0, #0x40
	str r0, [r5, #0x5c]
	movs r1, #0x80
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0806B27E
	str r1, [r5, #0x5c]
_0806B27E:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r1, _0806B2C8 @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r4]
	ldr r0, _0806B2CC @ =0xFFFF8000
	cmp r1, r0
	bge _0806B366
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B360
	movs r0, #6
	strb r0, [r5, #0xe]
	b _0806B4C4
	.align 2, 0
_0806B2B4: .4byte 0x08366448
_0806B2B8: .4byte 0x00000902
_0806B2BC: .4byte 0x083664A8
_0806B2C0: .4byte 0xFFFFFE00
_0806B2C4: .4byte 0xFFFF8800
_0806B2C8: .4byte 0xFFFFED00
_0806B2CC: .4byte 0xFFFF8000
_0806B2D0:
	ldr r1, _0806B34C @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B350 @ =0x083664A8
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _0806B354 @ =0xFFFF8000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B2F6:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B358 @ =0xFFFFF800
	adds r4, r0, #0
	cmp r2, r1
	ble _0806B312
	ldr r0, [r5, #0x5c]
	adds r0, #0x40
	str r0, [r5, #0x5c]
	cmp r0, #0x80
	ble _0806B312
	movs r0, #0x80
	str r0, [r5, #0x5c]
_0806B312:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r4, _0806B35C @ =0xFFFFED00
	adds r0, r0, r4
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0806B366
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B360
	movs r0, #4
	strb r0, [r5, #0xe]
	b _0806B4C4
	.align 2, 0
_0806B34C: .4byte 0x00000902
_0806B350: .4byte 0x083664A8
_0806B354: .4byte 0xFFFF8000
_0806B358: .4byte 0xFFFFF800
_0806B35C: .4byte 0xFFFFED00
_0806B360:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B366:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B36E
	b _0806B4C4
_0806B36E:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B37A
	b _0806B4C4
_0806B37A:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B380:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806B398
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r0, r0, r2
	b _0806B39E
_0806B398:
	ldr r0, [r5, #0x54]
	ldr r1, _0806B3D8 @ =0xFFFFFA00
	adds r0, r0, r1
_0806B39E:
	str r0, [sp]
	ldr r0, [r5, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp, #4]
	ldr r0, _0806B3DC @ =0x0000012D
	bl PlaySound
	movs r1, #0xa0
	lsls r1, r1, #1
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_0809d8a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B3C4:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B3CC
	b _0806B4C4
_0806B3CC:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806B4C4
	b _0806B49C
	.align 2, 0
_0806B3D8: .4byte 0xFFFFFA00
_0806B3DC: .4byte 0x0000012D
_0806B3E0:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806B3F4
	movs r0, #7
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B3F4:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B3FA:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x24
	movs r4, #0
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _0806B428 @ =0x08366448
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r1, _0806B42C @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	b _0806B49C
	.align 2, 0
_0806B428: .4byte 0x08366448
_0806B42C: .4byte 0xFFFFED00
_0806B430:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806B4C4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0806B4C4
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B46C @ =0x08366430
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _0806B49C
	.align 2, 0
_0806B46C: .4byte 0x08366430
_0806B470:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	adds r0, #0x80
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806B486
	str r1, [r5, #0x60]
_0806B486:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B4A4 @ =0xFFFFC600
	adds r0, r0, r2
	cmp r1, r0
	ble _0806B4C4
	str r0, [r5, #0x58]
_0806B49C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0806B4C4
	.align 2, 0
_0806B4A4: .4byte 0xFFFFC600
_0806B4A8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B4AE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _0806B4C4
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0806B4C4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b4cc
FUN_0806b4cc: @ 0x0806B4CC
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _0806B4DA
	b _0806B8C4
_0806B4DA:
	lsls r0, r0, #2
	ldr r1, _0806B4E4 @ =_0806B4E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B4E4: .4byte _0806B4E8
_0806B4E8: @ jump table
	.4byte _0806B54C @ case 0
	.4byte _0806B5B6 @ case 1
	.4byte _0806B60C @ case 2
	.4byte _0806B622 @ case 3
	.4byte _0806B630 @ case 4
	.4byte _0806B676 @ case 5
	.4byte _0806B6E0 @ case 6
	.4byte _0806B706 @ case 7
	.4byte _0806B8C4 @ case 8
	.4byte _0806B8C4 @ case 9
	.4byte _0806B790 @ case 10
	.4byte _0806B7BA @ case 11
	.4byte _0806B7D8 @ case 12
	.4byte _0806B8C4 @ case 13
	.4byte _0806B8C4 @ case 14
	.4byte _0806B8C4 @ case 15
	.4byte _0806B8C4 @ case 16
	.4byte _0806B8C4 @ case 17
	.4byte _0806B8C4 @ case 18
	.4byte _0806B8C4 @ case 19
	.4byte _0806B7F2 @ case 20
	.4byte _0806B85C @ case 21
	.4byte _0806B86E @ case 22
	.4byte _0806B8A8 @ case 23
	.4byte _0806B8AE @ case 24
_0806B54C:
	ldr r1, _0806B600 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r3, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	movs r4, #0
	strb r3, [r0]
	movs r2, #0x20
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B604 @ =0x083664A8
	bl SetDDP
	strb r4, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B5B6:
	ldrb r0, [r5, #0x13]
	cmp r0, #0x3f
	bhi _0806B5C0
	adds r0, #4
	strb r0, [r5, #0x13]
_0806B5C0:
	ldrb r0, [r5, #0x13]
	mvns r0, r0
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806B5E0
	str r1, [r5, #0x60]
_0806B5E0:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B608 @ =0xFFFFFE00
	adds r0, r0, r2
	cmp r1, r0
	bgt _0806B5F6
	b _0806B8C4
_0806B5F6:
	str r0, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _0806B89A
	.align 2, 0
_0806B600: .4byte 0x00000902
_0806B604: .4byte 0x083664A8
_0806B608: .4byte 0xFFFFFE00
_0806B60C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B614
	b _0806B8C4
_0806B614:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B620
	b _0806B8C4
_0806B620:
	b _0806B89A
_0806B622:
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x50
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B630:
	ldr r1, _0806B6C8 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B6CC @ =0x083664A8
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _0806B6D0 @ =0xFFFFFF00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B676:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B6D4 @ =0xFFFFD180
	adds r4, r0, #0
	cmp r2, r1
	bge _0806B694
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0x40
	rsbs r1, r1, #0
	cmp r0, r1
	ble _0806B694
	str r1, [r5, #0x60]
_0806B694:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	adds r0, r0, r1
	ldr r1, _0806B6D8 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r4]
	ldr r0, _0806B6DC @ =0xFFFFD000
	cmp r1, r0
	bge _0806B776
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B770
	movs r0, #6
	strb r0, [r5, #0xe]
	b _0806B8C4
	.align 2, 0
_0806B6C8: .4byte 0x00000902
_0806B6CC: .4byte 0x083664A8
_0806B6D0: .4byte 0xFFFFFF00
_0806B6D4: .4byte 0xFFFFD180
_0806B6D8: .4byte 0xFFFFFE00
_0806B6DC: .4byte 0xFFFFD000
_0806B6E0:
	ldr r1, _0806B75C @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B760 @ =0x083664A8
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _0806B764 @ =0xFFFFD000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B706:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B768 @ =0xFFFFFE80
	adds r4, r0, #0
	cmp r2, r1
	ble _0806B722
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, #0x3f
	bgt _0806B722
	movs r0, #0x40
	str r0, [r5, #0x60]
_0806B722:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	adds r0, r0, r1
	ldr r4, _0806B76C @ =0xFFFFFE00
	adds r0, r0, r4
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _0806B776
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B770
	movs r0, #4
	strb r0, [r5, #0xe]
	b _0806B8C4
	.align 2, 0
_0806B75C: .4byte 0x00000902
_0806B760: .4byte 0x083664A8
_0806B764: .4byte 0xFFFFD000
_0806B768: .4byte 0xFFFFFE80
_0806B76C: .4byte 0xFFFFFE00
_0806B770:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B776:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B77E
	b _0806B8C4
_0806B77E:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B78A
	b _0806B8C4
_0806B78A:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B790:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	ldr r2, _0806B7D0 @ =0xFFFFEE00
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldr r0, _0806B7D4 @ =0x0000012D
	bl PlaySound
	movs r1, #0x80
	lsls r1, r1, #2
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_0809d904
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B7BA:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B7C2
	b _0806B8C4
_0806B7C2:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806B8C4
	b _0806B89A
	.align 2, 0
_0806B7D0: .4byte 0xFFFFEE00
_0806B7D4: .4byte 0x0000012D
_0806B7D8:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806B7EC
	movs r0, #7
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B7EC:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B7F2:
	ldr r1, _0806B854 @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _0806B858 @ =0x08366478
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x32
	strb r0, [r5, #0x12]
	b _0806B89A
	.align 2, 0
_0806B854: .4byte 0x00000901
_0806B858: .4byte 0x08366478
_0806B85C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806B8C4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806B8C4
	b _0806B89A
_0806B86E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	subs r0, #4
	str r0, [r5, #0x60]
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0806B884
	str r1, [r5, #0x60]
_0806B884:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B8A4 @ =0xFFFFC800
	adds r0, r0, r2
	cmp r1, r0
	bge _0806B8C4
	str r0, [r5, #0x58]
_0806B89A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0806B8C4
	.align 2, 0
_0806B8A4: .4byte 0xFFFFC800
_0806B8A8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B8AE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _0806B8C4
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0806B8C4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b8cc
FUN_0806b8cc: @ 0x0806B8CC
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806b8d0
FUN_0806b8d0: @ 0x0806B8D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _0806B8DC
	b _0806BB4A
_0806B8DC:
	lsls r0, r0, #2
	ldr r1, _0806B8E8 @ =_0806B8EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B8E8: .4byte _0806B8EC
_0806B8EC: @ jump table
	.4byte _0806B910 @ case 0
	.4byte _0806B99C @ case 1
	.4byte _0806B9EE @ case 2
	.4byte _0806BA4E @ case 3
	.4byte _0806BA58 @ case 4
	.4byte _0806BA74 @ case 5
	.4byte _0806BA98 @ case 6
	.4byte _0806BAE0 @ case 7
	.4byte _0806BB4A @ case 8
_0806B910:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r4, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldr r2, _0806B990 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806B994 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806B998 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #2
	b _0806BB48
	.align 2, 0
_0806B990: .4byte RNG_0202f388
_0806B994: .4byte 0x000343FD
_0806B998: .4byte 0x00269EC3
_0806B99C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r3, [r5, #0x28]
	ldr r2, [r5, #0x54]
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
	str r2, [r5, #0x54]
	ldr r2, [r5, #0x58]
	movs r1, #0xe8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r3, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B9DC
	b _0806BB4A
_0806B9DC:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B9E8
	b _0806BB4A
_0806B9E8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BB48
_0806B9EE:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806B9FE
	str r1, [r5, #0x60]
_0806B9FE:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	beq _0806BA46
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	movs r0, #0x91
	bl PlaySound
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806BA40
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r0, #0xe8
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	b _0806BA46
_0806BA40:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BA46:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0806BB4A
_0806BA4E:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BA58:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BB4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BB4A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BB48
_0806BA74:
	ldr r2, _0806BAD4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BAD8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BADC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	adds r0, #5
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BA98:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BB4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BB4A
	ldr r2, _0806BAD4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BAD8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BADC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BB48
	.align 2, 0
_0806BAD4: .4byte RNG_0202f388
_0806BAD8: .4byte 0x000343FD
_0806BADC: .4byte 0x00269EC3
_0806BAE0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r3, r5, #0
	adds r3, #0xb4
	ldr r4, [r5, #0x28]
	ldr r0, [r3]
	ldr r1, [r4, #0x54]
	adds r0, r0, r1
	ldr r2, [r5, #0x54]
	cmp r2, r0
	ble _0806BB10
	ldr r0, _0806BB0C @ =0xFFFFFD00
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	bge _0806BB2A
	b _0806BB22
	.align 2, 0
_0806BB0C: .4byte 0xFFFFFD00
_0806BB10:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r2, r2, r1
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	ble _0806BB2A
_0806BB22:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BB2A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	beq _0806BB4A
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BB4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BB4A
	movs r0, #4
_0806BB48:
	strb r0, [r5, #0xe]
_0806BB4A:
	ldr r2, [r5, #0x28]
	adds r0, r2, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0806BB7E
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0806BB84 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r1, _0806BB88 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r0, [r5, #0xf]
_0806BB7E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806BB84: .4byte 0xFFFFF800
_0806BB88: .4byte 0xFFFFE800

	thumb_func_start FUN_0806bb8c
FUN_0806bb8c: @ 0x0806BB8C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _0806BB98
	b _0806BDCA
_0806BB98:
	lsls r0, r0, #2
	ldr r1, _0806BBA4 @ =_0806BBA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806BBA4: .4byte _0806BBA8
_0806BBA8: @ jump table
	.4byte _0806BBCC @ case 0
	.4byte _0806BC44 @ case 1
	.4byte _0806BC7E @ case 2
	.4byte _0806BCDE @ case 3
	.4byte _0806BCE8 @ case 4
	.4byte _0806BD04 @ case 5
	.4byte _0806BD20 @ case 6
	.4byte _0806BD60 @ case 7
	.4byte _0806BDCA @ case 8
_0806BBCC:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r4, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	ldr r1, _0806BC34 @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldr r2, _0806BC38 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BC3C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BC40 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #2
	b _0806BDC8
	.align 2, 0
_0806BC34: .4byte 0x00000901
_0806BC38: .4byte RNG_0202f388
_0806BC3C: .4byte 0x000343FD
_0806BC40: .4byte 0x00269EC3
_0806BC44:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x58]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r2, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806BC6C
	b _0806BDCA
_0806BC6C:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806BC78
	b _0806BDCA
_0806BC78:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BDC8
_0806BC7E:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806BC8E
	str r1, [r5, #0x60]
_0806BC8E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	beq _0806BCD6
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	movs r0, #0x91
	bl PlaySound
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806BCD0
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r0, #0xe8
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	b _0806BCD6
_0806BCD0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BCD6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0806BDCA
_0806BCDE:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BCE8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BDCA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BDCA
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BDC8
_0806BD04:
	ldr r2, _0806BD54 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BD58 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _0806BD5C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	movs r0, #5
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BD20:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BDCA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BDCA
	ldr r2, _0806BD54 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BD58 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BD5C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BDC8
	.align 2, 0
_0806BD54: .4byte RNG_0202f388
_0806BD58: .4byte 0x000343FD
_0806BD5C: .4byte 0x00269EC3
_0806BD60:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r3, r5, #0
	adds r3, #0xb4
	ldr r4, [r5, #0x28]
	ldr r0, [r3]
	ldr r1, [r4, #0x54]
	adds r0, r0, r1
	ldr r2, [r5, #0x54]
	cmp r2, r0
	ble _0806BD90
	ldr r0, _0806BD8C @ =0xFFFFFC80
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	bge _0806BDAA
	b _0806BDA2
	.align 2, 0
_0806BD8C: .4byte 0xFFFFFC80
_0806BD90:
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r2, r2, r1
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	ble _0806BDAA
_0806BDA2:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BDAA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	beq _0806BDCA
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BDCA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BDCA
	movs r0, #4
_0806BDC8:
	strb r0, [r5, #0xe]
_0806BDCA:
	ldr r2, [r5, #0x28]
	adds r0, r2, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0806BDFE
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0806BE04 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r3, _0806BE08 @ =0xFFFFE800
	adds r0, r0, r3
	str r0, [r5, #0x58]
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r0, [r5, #0xf]
_0806BDFE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806BE04: .4byte 0xFFFFF800
_0806BE08: .4byte 0xFFFFE800

	thumb_func_start nop_0806be0c
nop_0806be0c: @ 0x0806BE0C
	bx lr
	.align 2, 0
