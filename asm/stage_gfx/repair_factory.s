	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initRepairFactory
initRepairFactory: @ 0x0800D670
	push {lr}
	ldr r1, _0800D6A4 @ =0x02002200
	ldr r2, _0800D6A8 @ =0x0002D024
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0800D6AC @ =0x0002D028
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _0800D6B0 @ =0x0002D02A
	adds r1, r1, r0
	strb r2, [r1]
	movs r0, #0x2b
	movs r1, #0
	bl loadBlink
	movs r0, #0x2c
	movs r1, #0
	bl loadBlink
	pop {r0}
	bx r0
	.align 2, 0
_0800D6A4: .4byte 0x02002200
_0800D6A8: .4byte 0x0002D024
_0800D6AC: .4byte 0x0002D028
_0800D6B0: .4byte 0x0002D02A

	thumb_func_start repairFactory_0800d6b4
repairFactory_0800d6b4: @ 0x0800D6B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _0800D6F0 @ =0x02002200
	ldr r1, _0800D6F4 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #4
	bne _0800D6FC
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _0800D6FC
	ldr r1, _0800D6F8 @ =0x0002D028
	adds r2, r2, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0800D6E8
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x2d
	movs r1, #0
	bl loadBlink
_0800D6E8:
	movs r0, #0x2d
	bl FUN_08004068
	b _0800D718
	.align 2, 0
_0800D6F0: .4byte 0x02002200
_0800D6F4: .4byte 0x000007D6
_0800D6F8: .4byte 0x0002D028
_0800D6FC:
	ldr r0, _0800D770 @ =0x02002200
	ldr r1, _0800D774 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800D718
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x2d
	bl clearBlink
_0800D718:
	ldr r2, _0800D770 @ =0x02002200
	ldr r1, _0800D778 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #4
	bne _0800D77C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _0800D77C
	ldr r0, _0800D774 @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0800D75A
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x2e
	movs r1, #0
	bl loadBlink
	movs r0, #0x2f
	movs r1, #0
	bl loadBlink
	movs r0, #0x30
	movs r1, #0
	bl loadBlink
_0800D75A:
	movs r0, #0x2e
	bl FUN_08004068
	movs r0, #0x2f
	bl FUN_08004068
	movs r0, #0x30
	bl FUN_08004068
	b _0800D7A4
	.align 2, 0
_0800D770: .4byte 0x02002200
_0800D774: .4byte 0x0002D028
_0800D778: .4byte 0x000007D6
_0800D77C:
	ldr r0, _0800D7E4 @ =0x02002200
	ldr r1, _0800D7E8 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D7A4
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x2e
	bl clearBlink
	movs r0, #0x2f
	bl clearBlink
	movs r0, #0x30
	bl clearBlink
_0800D7A4:
	movs r0, #0x2b
	bl FUN_08004068
	movs r0, #0x2c
	bl FUN_08004068
	ldr r2, _0800D7E4 @ =0x02002200
	ldr r1, _0800D7EC @ =0x0002D024
	adds r0, r2, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0800D804
	ldr r0, _0800D7F0 @ =0x0002C004
	adds r1, r2, r0
	ldr r0, _0800D7F4 @ =0xFFFFFEAB
	str r0, [r1]
	ldr r0, _0800D7F8 @ =0x0002C008
	adds r1, r2, r0
	ldr r0, _0800D7FC @ =0x00000155
	str r0, [r1]
	ldr r0, _0800D800 @ =0x0002D029
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0800D828
	strb r3, [r1]
	b _0800D828
	.align 2, 0
_0800D7E4: .4byte 0x02002200
_0800D7E8: .4byte 0x0002D028
_0800D7EC: .4byte 0x0002D024
_0800D7F0: .4byte 0x0002C004
_0800D7F4: .4byte 0xFFFFFEAB
_0800D7F8: .4byte 0x0002C008
_0800D7FC: .4byte 0x00000155
_0800D800: .4byte 0x0002D029
_0800D804:
	ldr r0, _0800D874 @ =0x0002C004
	adds r1, r2, r0
	ldr r0, _0800D878 @ =0x00000155
	str r0, [r1]
	ldr r0, _0800D87C @ =0x0002C008
	adds r1, r2, r0
	ldr r0, _0800D880 @ =0xFFFFFEAB
	str r0, [r1]
	ldr r0, _0800D884 @ =0x0002D029
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _0800D828
	movs r0, #5
	strb r0, [r1]
_0800D828:
	ldr r0, _0800D888 @ =0x02002200
	ldr r2, _0800D88C @ =0x0002D02A
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2d
	bne _0800D840
	movs r0, #0
	strb r0, [r1]
_0800D840:
	ldr r2, [r4]
	ldr r0, _0800D890 @ =0xFFEF2FFF
	adds r1, r2, r0
	ldr r0, _0800D894 @ =0x0005AFFE
	cmp r1, r0
	bls _0800D85A
	ldr r0, _0800D898 @ =0x0001DFFF
	cmp r2, r0
	bgt _0800D8A4
	ldr r1, [r4, #4]
	ldr r0, _0800D89C @ =0x00013FFF
	cmp r1, r0
	bgt _0800D8A4
_0800D85A:
	ldr r4, _0800D8A0 @ =0x0000010B
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _0800D86C
	adds r0, r4, #0
	bl playSound
_0800D86C:
	adds r0, r4, #0
	bl sound_0800465c
	b _0800D8B6
	.align 2, 0
_0800D874: .4byte 0x0002C004
_0800D878: .4byte 0x00000155
_0800D87C: .4byte 0x0002C008
_0800D880: .4byte 0xFFFFFEAB
_0800D884: .4byte 0x0002D029
_0800D888: .4byte 0x02002200
_0800D88C: .4byte 0x0002D02A
_0800D890: .4byte 0xFFEF2FFF
_0800D894: .4byte 0x0005AFFE
_0800D898: .4byte 0x0001DFFF
_0800D89C: .4byte 0x00013FFF
_0800D8A0: .4byte 0x0000010B
_0800D8A4:
	ldr r4, _0800D8BC @ =0x0000010B
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _0800D8B6
	adds r0, r4, #0
	bl stopSound
_0800D8B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800D8BC: .4byte 0x0000010B

	thumb_func_start repairFactory_0800d8c0
repairFactory_0800d8c0: @ 0x0800D8C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _0800D99C @ =0x087044F8
	ldr r5, _0800D9A0 @ =0x02002200
	ldr r0, _0800D9A4 @ =0x0002D029
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	lsls r0, r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0800D9A8 @ =0x0870478C
	adds r1, r1, r4
	ldr r0, [r7]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	mov r8, r1
	bl appendGraphicTask
	movs r0, #0
	ldrsb r0, [r6, r0]
	lsls r0, r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r7]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	ldr r0, _0800D9AC @ =0x0002D02A
	adds r6, r5, r0
	ldrb r0, [r6]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r4, #0x50
	adds r1, r1, r4
	ldr r0, [r7]
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldrb r0, [r6]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r7]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	ldr r1, _0800D9B0 @ =0x000007D6
	adds r5, r5, r1
	ldrh r5, [r5]
	lsrs r0, r5, #8
	cmp r0, #4
	bne _0800D990
	movs r0, #0xff
	ands r0, r5
	cmp r0, #4
	bne _0800D990
	ldr r0, _0800D9B4 @ =0x0202FE20
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800D990
	ldr r0, [r7]
	ldr r1, _0800D9B8 @ =0x08704C28
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldr r0, [r7]
	ldr r1, _0800D9BC @ =0x08704C34
	adds r0, r0, r1
	movs r1, #0
	bl transferPalette
_0800D990:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D99C: .4byte 0x087044F8
_0800D9A0: .4byte 0x02002200
_0800D9A4: .4byte 0x0002D029
_0800D9A8: .4byte 0x0870478C
_0800D9AC: .4byte 0x0002D02A
_0800D9B0: .4byte 0x000007D6
_0800D9B4: .4byte 0x0202FE20
_0800D9B8: .4byte 0x08704C28
_0800D9BC: .4byte 0x08704C34

	thumb_func_start exitRepairFactory
exitRepairFactory: @ 0x0800D9C0
	push {r4, lr}
	movs r0, #0x2b
	bl clearBlink
	movs r0, #0x2c
	bl clearBlink
	movs r0, #0x2d
	bl clearBlink
	movs r0, #0x2e
	bl clearBlink
	movs r0, #0x2f
	bl clearBlink
	movs r0, #0x30
	bl clearBlink
	ldr r4, _0800DA00 @ =0x0000010B
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _0800D9F8
	adds r0, r4, #0
	bl stopSound
_0800D9F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800DA00: .4byte 0x0000010B

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
	ldr r1, _0800DA4C @ =0x02002144
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
	ldr r1, _0800DA54 @ =0x083396E8
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
_0800DA4C: .4byte 0x02002144
_0800DA50: .4byte 0x0000FFFC
_0800DA54: .4byte 0x083396E8
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
	ldr r1, _0800DAA0 @ =0x083396E8
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
_0800DAA0: .4byte 0x083396E8
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
	ldr r2, _0800DB5C @ =0x02002200
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
	bl loadScreenIntoBlockMap
	b _0800DB6E
	.align 2, 0
_0800DB4C: .4byte 0xFFF97000
_0800DB50: .4byte 0x0001DFFF
_0800DB54: .4byte 0xFFFD8000
_0800DB58: .4byte 0x00013FFF
_0800DB5C: .4byte 0x02002200
_0800DB60: .4byte 0x00077FFF
_0800DB64:
	movs r0, #8
	movs r1, #4
	movs r2, #0x37
	bl loadScreenIntoBlockMap
_0800DB6E:
	movs r0, #8
	mov r1, sp
	bl shake_0801ab60
	movs r0, #1
	b _0800DB7C
_0800DB7A:
	movs r0, #0
_0800DB7C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
