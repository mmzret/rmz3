	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start rfactory_0800da04
rfactory_0800da04: @ 0x0800DA04
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800DA32
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800DA4C @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800DA50 @ =0x0000FFFC
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strh r1, [r0]
	movs r0, #0xc0
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800DA32:
	ldr r1, _0800DA54 @ =gScreenX
	ldr r0, [r3, #0x34]
	asrs r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bgt _0800DA58
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r3, #0x48]
	movs r0, #0x78
	str r0, [r3, #0x4c]
	b _0800DA7A
	.align 2, 0
_0800DA4C: .4byte gVideoRegBuffer+4
_0800DA50: .4byte 0x0000FFFC
_0800DA54: .4byte gScreenX
_0800DA58:
	cmp r0, #0x10
	bgt _0800DA62
	movs r0, #0xf0
	lsls r0, r0, #2
	b _0800DA74
_0800DA62:
	cmp r0, #0x13
	bgt _0800DA70
	movs r0, #0x87
	lsls r0, r0, #3
	str r0, [r3, #0x4c]
	movs r0, #0x8c
	b _0800DA78
_0800DA70:
	movs r0, #0xdb
	lsls r0, r0, #3
_0800DA74:
	str r0, [r3, #0x4c]
	movs r0, #0xc8
_0800DA78:
	str r0, [r3, #0x50]
_0800DA7A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start rfactory_0800da80
rfactory_0800da80: @ 0x0800DA80
	push {lr}
	adds r2, r0, #0
	ldr r1, _0800DAA0 @ =gScreenX
	ldr r0, [r2, #0x34]
	asrs r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bgt _0800DAA4
	movs r0, #0x40
	str r0, [r2, #0x44]
	adds r0, #0xc0
	str r0, [r2, #0x48]
	adds r0, #0x68
	str r0, [r2, #0x4c]
	b _0800DAE8
	.align 2, 0
_0800DAA0: .4byte gScreenX
_0800DAA4:
	cmp r0, #0xe
	bgt _0800DAB4
	movs r0, #0xc3
	lsls r0, r0, #3
	str r0, [r2, #0x4c]
	movs r0, #0xa0
	lsls r0, r0, #1
	b _0800DAE6
_0800DAB4:
	cmp r0, #0x10
	bgt _0800DABE
	movs r0, #0xf0
	lsls r0, r0, #3
	b _0800DAE0
_0800DABE:
	cmp r0, #0x13
	bgt _0800DACE
	movs r0, #0x87
	lsls r0, r0, #4
	str r0, [r2, #0x4c]
	movs r0, #0x8c
	lsls r0, r0, #1
	b _0800DAE6
_0800DACE:
	cmp r0, #0x1b
	bgt _0800DADC
	ldr r0, _0800DAD8 @ =0x00000BB8
	b _0800DAE0
	.align 2, 0
_0800DAD8: .4byte 0x00000BB8
_0800DADC:
	movs r0, #0xdb
	lsls r0, r0, #4
_0800DAE0:
	str r0, [r2, #0x4c]
	movs r0, #0xc8
	lsls r0, r0, #1
_0800DAE6:
	str r0, [r2, #0x50]
_0800DAE8:
	pop {r0}
	bx r0

	thumb_func_start FUN_0800daec
FUN_0800daec: @ 0x0800DAEC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0800DB4C @ =0xFFF97000
	adds r1, r5, r0
	ldr r0, _0800DB50 @ =0x0001DFFF
	cmp r1, r0
	bhi _0800DB7A
	ldr r0, _0800DB54 @ =0xFFFD8000
	adds r7, r6, r0
	ldr r0, _0800DB58 @ =0x00013FFF
	cmp r7, r0
	bhi _0800DB7A
	ldr r2, _0800DB5C @ =gOverworld
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrh r4, [r2]
	asrs r0, r6, #0xc
	adds r1, r4, #0
	muls r1, r0, r1
	asrs r3, r5, #0xc
	adds r1, r1, r3
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r2
	asrs r0, r7, #0xc
	muls r0, r4, r0
	adds r0, r0, r3
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0800DB7A
	str r5, [sp]
	str r6, [sp, #4]
	ldr r0, _0800DB60 @ =0x00077FFF
	cmp r5, r0
	bgt _0800DB64
	movs r0, #7
	movs r1, #4
	movs r2, #0x36
	bl LoadScreenIntoMetatileMap
	b _0800DB6E
	.align 2, 0
_0800DB4C: .4byte 0xFFF97000
_0800DB50: .4byte 0x0001DFFF
_0800DB54: .4byte 0xFFFD8000
_0800DB58: .4byte 0x00013FFF
_0800DB5C: .4byte gOverworld
_0800DB60: .4byte 0x00077FFF
_0800DB64:
	movs r0, #8
	movs r1, #4
	movs r2, #0x37
	bl LoadScreenIntoMetatileMap
_0800DB6E:
	movs r0, #8
	mov r1, sp
	bl AppendQuake
	movs r0, #1
	b _0800DB7C
_0800DB7A:
	movs r0, #0
_0800DB7C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
