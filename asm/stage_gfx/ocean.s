	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initOcean
initOcean: @ 0x0800CB4C
	push {r4, r5, r6, lr}
	ldr r5, _0800CB8C @ =0x02002200
	ldr r1, _0800CB90 @ =0x0002D028
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0800CB94 @ =0x0002D029
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0800CB98 @ =0x0202FDC0
	ldrb r6, [r0, #9]
	lsls r3, r6, #0x18
	lsrs r0, r3, #0x19
	movs r1, #1
	adds r2, r1, #0
	bics r2, r0
	lsrs r4, r3, #0x1a
	adds r0, r1, #0
	bics r0, r4
	adds r2, r2, r0
	lsrs r3, r3, #0x1b
	bics r1, r3
	adds r2, r2, r1
	movs r0, #0x10
	ands r0, r6
	cmp r0, #0
	bne _0800CB9C
	adds r0, r2, #1
	b _0800CB9E
	.align 2, 0
_0800CB8C: .4byte 0x02002200
_0800CB90: .4byte 0x0002D028
_0800CB94: .4byte 0x0002D029
_0800CB98: .4byte 0x0202FDC0
_0800CB9C:
	adds r0, r2, #0
_0800CB9E:
	ldr r1, _0800CBD8 @ =0x0002C00C
	adds r2, r5, r1
	ldr r1, _0800CBDC @ =0x0833CCDC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0
_0800CBAE:
	lsls r4, r0, #0x18
	lsrs r0, r4, #0x18
	asrs r4, r4, #0x18
	lsls r1, r4, #3
	ldr r2, _0800CBE0 @ =0x0833CD08
	adds r1, r1, r2
	bl createSeaLevelButton
	lsls r1, r4, #2
	ldr r2, _0800CBE4 @ =0x0202F22C
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x18
	lsrs r0, r4, #0x18
	asrs r4, r4, #0x18
	cmp r4, #3
	ble _0800CBAE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800CBD8: .4byte 0x0002C00C
_0800CBDC: .4byte 0x0833CCDC
_0800CBE0: .4byte 0x0833CD08
_0800CBE4: .4byte 0x0202F22C

	thumb_func_start ocean_0800cbe8
ocean_0800cbe8: @ 0x0800CBE8
	push {r4, r5, lr}
	ldr r2, _0800CC34 @ =0x02002200
	ldr r1, _0800CC38 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #3
	bne _0800CC40
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	bne _0800CC40
	ldr r0, _0800CC3C @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0800CC24
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xe5
	movs r1, #0
	bl loadBlink
	movs r0, #0xe6
	movs r1, #0
	bl loadBlink
_0800CC24:
	movs r0, #0xe5
	bl FUN_08004068
	movs r0, #0xe6
	bl FUN_08004068
	b _0800CC62
	.align 2, 0
_0800CC34: .4byte 0x02002200
_0800CC38: .4byte 0x000007D4
_0800CC3C: .4byte 0x0002D028
_0800CC40:
	ldr r0, _0800CCC8 @ =0x02002200
	ldr r1, _0800CCCC @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800CC62
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xe5
	bl clearBlink
	movs r0, #0xe6
	bl clearBlink
_0800CC62:
	ldr r2, _0800CCC8 @ =0x02002200
	ldr r1, _0800CCD0 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #3
	bne _0800CCD4
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _0800CCD4
	ldr r0, _0800CCCC @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0800CCAC
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xe7
	movs r1, #0
	bl loadBlink
	movs r0, #0xe8
	movs r1, #0
	bl loadBlink
	movs r0, #0xe9
	movs r1, #0
	bl loadBlink
	movs r0, #0xea
	movs r1, #0
	bl loadBlink
_0800CCAC:
	movs r0, #0xe7
	bl FUN_08004068
	movs r0, #0xe8
	bl FUN_08004068
	movs r0, #0xe9
	bl FUN_08004068
	movs r0, #0xea
	bl FUN_08004068
	b _0800CD02
	.align 2, 0
_0800CCC8: .4byte 0x02002200
_0800CCCC: .4byte 0x0002D028
_0800CCD0: .4byte 0x000007D6
_0800CCD4:
	ldr r0, _0800CD78 @ =0x02002200
	ldr r1, _0800CD7C @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800CD02
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xe7
	bl clearBlink
	movs r0, #0xe8
	bl clearBlink
	movs r0, #0xe9
	bl clearBlink
	movs r0, #0xea
	bl clearBlink
_0800CD02:
	ldr r5, _0800CD78 @ =0x02002200
	ldr r2, _0800CD80 @ =0x000007D4
	adds r0, r5, r2
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #3
	bne _0800CD8C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _0800CD8C
	ldr r0, _0800CD7C @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0800CD44
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xeb
	movs r1, #0
	bl loadBlink
	ldr r1, _0800CD84 @ =0x0002D029
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0800CD88 @ =0x0002D02A
	adds r0, r5, r2
	strb r4, [r0]
_0800CD44:
	movs r0, #0xeb
	bl FUN_08004068
	ldr r0, _0800CD84 @ =0x0002D029
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _0800CD60
	strb r2, [r1]
_0800CD60:
	ldr r0, _0800CD88 @ =0x0002D02A
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _0800CDA8
	strb r2, [r1]
	b _0800CDA8
	.align 2, 0
_0800CD78: .4byte 0x02002200
_0800CD7C: .4byte 0x0002D028
_0800CD80: .4byte 0x000007D4
_0800CD84: .4byte 0x0002D029
_0800CD88: .4byte 0x0002D02A
_0800CD8C:
	ldr r0, _0800CE0C @ =0x02002200
	ldr r1, _0800CE10 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CDA8
	movs r0, #4
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xeb
	bl clearBlink
_0800CDA8:
	ldr r2, _0800CE0C @ =0x02002200
	ldr r1, _0800CE14 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #3
	bne _0800CE18
	movs r0, #0xff
	ands r0, r1
	cmp r0, #3
	bne _0800CE18
	ldr r0, _0800CE10 @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800CDF2
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xec
	movs r1, #0
	bl loadBlink
	movs r0, #0xed
	movs r1, #0
	bl loadBlink
	movs r0, #0xee
	movs r1, #0
	bl loadBlink
	movs r0, #0xef
	movs r1, #0
	bl loadBlink
_0800CDF2:
	movs r0, #0xec
	bl FUN_08004068
	movs r0, #0xed
	bl FUN_08004068
	movs r0, #0xee
	bl FUN_08004068
	movs r0, #0xef
	bl FUN_08004068
	b _0800CE46
	.align 2, 0
_0800CE0C: .4byte 0x02002200
_0800CE10: .4byte 0x0002D028
_0800CE14: .4byte 0x000007D4
_0800CE18:
	ldr r0, _0800CF80 @ =0x02002200
	ldr r1, _0800CF84 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800CE46
	movs r0, #8
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xec
	bl clearBlink
	movs r0, #0xed
	bl clearBlink
	movs r0, #0xee
	bl clearBlink
	movs r0, #0xef
	bl clearBlink
_0800CE46:
	ldr r0, _0800CF88 @ =0x0202FDC0
	ldrb r5, [r0, #9]
	lsls r3, r5, #0x18
	lsrs r0, r3, #0x19
	movs r1, #1
	adds r2, r1, #0
	bics r2, r0
	lsrs r4, r3, #0x1a
	adds r0, r1, #0
	bics r0, r4
	adds r2, r2, r0
	lsrs r3, r3, #0x1b
	bics r1, r3
	adds r1, r2, r1
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	bne _0800CE6C
	adds r1, #1
_0800CE6C:
	ldr r2, _0800CF80 @ =0x02002200
	ldr r0, _0800CF8C @ =0x0002C00C
	adds r4, r2, r0
	ldr r0, _0800CF90 @ =0x0833CCDC
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r3, [r4]
	ldr r0, [r1]
	cmp r3, r0
	bge _0800CE86
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r4]
_0800CE86:
	ldr r0, _0800CF88 @ =0x0202FDC0
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800CEC6
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r2, r2, r1
	ldrh r1, [r2]
	movs r0, #0x34
	muls r0, r1, r0
	adds r0, #0xc0
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	cmp r1, r0
	bne _0800CEC6
	ldr r4, _0800CF94 @ =0x0833CCF0
	movs r0, #0xb6
	movs r1, #0x34
	adds r2, r4, #0
	bl patchBlockMap
	adds r4, #0xc
	movs r0, #0xbe
	movs r1, #0x34
	adds r2, r4, #0
	bl patchBlockMap
_0800CEC6:
	ldr r0, _0800CF88 @ =0x0202FDC0
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CF0E
	ldr r2, _0800CF80 @ =0x02002200
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrh r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	ldr r1, _0800CF98 @ =0x00000139
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	cmp r1, r0
	bne _0800CF0E
	subs r0, #0xa0
	ldr r4, _0800CF94 @ =0x0833CCF0
	movs r1, #0x37
	adds r2, r4, #0
	bl patchBlockMap
	ldr r0, _0800CF9C @ =0x00000137
	adds r4, #0xc
	movs r1, #0x37
	adds r2, r4, #0
	bl patchBlockMap
_0800CF0E:
	ldr r0, _0800CF88 @ =0x0202FDC0
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800CF44
	ldr r2, _0800CF80 @ =0x02002200
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrh r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _0800CFA0 @ =0x0000043A
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	cmp r1, r0
	bne _0800CF44
	adds r0, #0x59
	ldr r2, _0800CFA4 @ =0x0833CCFC
	movs r1, #0x38
	bl patchBlockMap
_0800CF44:
	ldr r0, _0800CF88 @ =0x0202FDC0
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800CF7A
	ldr r1, _0800CF80 @ =0x02002200
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r0, #0x36
	muls r0, r2, r0
	ldr r2, _0800CFA8 @ =0x00000286
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	cmp r1, r0
	bne _0800CF7A
	adds r0, #0xc4
	ldr r2, _0800CF94 @ =0x0833CCF0
	movs r1, #0x36
	bl patchBlockMap
_0800CF7A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800CF80: .4byte 0x02002200
_0800CF84: .4byte 0x0002D028
_0800CF88: .4byte 0x0202FDC0
_0800CF8C: .4byte 0x0002C00C
_0800CF90: .4byte 0x0833CCDC
_0800CF94: .4byte 0x0833CCF0
_0800CF98: .4byte 0x00000139
_0800CF9C: .4byte 0x00000137
_0800CFA0: .4byte 0x0000043A
_0800CFA4: .4byte 0x0833CCFC
_0800CFA8: .4byte 0x00000286

	thumb_func_start ocean_0800cfac
ocean_0800cfac: @ 0x0800CFAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _0800D054 @ =0x02002200
	ldr r1, _0800D058 @ =0x000007D4
	adds r0, r7, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #3
	bne _0800D04A
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _0800D04A
	ldr r6, _0800D05C @ =0x087044F8
	ldr r0, _0800D060 @ =0x0002D029
	adds r5, r7, r0
	ldrb r0, [r5]
	lsrs r0, r0, #3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0800D064 @ =0x0870518C
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	mov r8, r1
	bl appendGraphicTask
	ldrb r0, [r5]
	lsrs r0, r0, #3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	ldr r0, _0800D068 @ =0x0002D02A
	adds r5, r7, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r4, #0xa0
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_0800D04A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D054: .4byte 0x02002200
_0800D058: .4byte 0x000007D4
_0800D05C: .4byte 0x087044F8
_0800D060: .4byte 0x0002D029
_0800D064: .4byte 0x0870518C
_0800D068: .4byte 0x0002D02A

	thumb_func_start exitOcean
exitOcean: @ 0x0800D06C
	push {r4, r5, lr}
	movs r0, #0xe5
	bl clearBlink
	movs r0, #0xe6
	bl clearBlink
	movs r0, #0xe7
	bl clearBlink
	movs r0, #0xe8
	bl clearBlink
	movs r0, #0xe9
	bl clearBlink
	movs r0, #0xea
	bl clearBlink
	movs r0, #0xeb
	bl clearBlink
	movs r0, #0xec
	bl clearBlink
	movs r0, #0xed
	bl clearBlink
	movs r0, #0xee
	bl clearBlink
	movs r0, #0xef
	bl clearBlink
	movs r0, #0
	movs r4, #0
	ldr r5, _0800D108 @ =0x0836FB24
_0800D0B6:
	lsls r2, r0, #0x18
	asrs r2, r2, #0x18
	lsls r0, r2, #2
	ldr r1, _0800D10C @ =0x0202F22C
	adds r0, r0, r1
	ldr r3, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldrb r1, [r3, #9]
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #3
	str r0, [r3, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r0, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #3
	ble _0800D0B6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D108: .4byte 0x0836FB24
_0800D10C: .4byte 0x0202F22C

	thumb_func_start ocean_0800d110
ocean_0800d110: @ 0x0800D110
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	bne _0800D18E
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _0800D1A0 @ =0x02002144
	adds r5, r5, r3
	ldr r1, [r7, #0x60]
	ldr r2, [r7, #0x64]
	orrs r1, r2
	ldr r6, _0800D1A4 @ =0x00008044
	adds r2, r6, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r4, [r0]
	ldr r0, _0800D1A8 @ =0x08522354
	ldr r0, [r0]
	ldr r2, _0800D1AC @ =0x0852235C
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldr r0, _0800D1B0 @ =0x08522358
	ldr r0, [r0]
	ldr r1, _0800D1B4 @ =0x08522360
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _0800D1B8 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	ldr r1, _0800D1BC @ =0x02002180
	movs r2, #0
	ldr r0, _0800D1C0 @ =0x00003B44
	strh r0, [r1]
	ldr r0, _0800D1C4 @ =0x00000C04
	strh r0, [r1, #2]
	adds r0, r7, #0
	adds r0, #0x68
	strb r2, [r0]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800D18E:
	adds r1, r7, #0
	adds r1, #0x68
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D1A0: .4byte 0x02002144
_0800D1A4: .4byte 0x00008044
_0800D1A8: .4byte 0x08522354
_0800D1AC: .4byte 0x0852235C
_0800D1B0: .4byte 0x08522358
_0800D1B4: .4byte 0x08522360
_0800D1B8: .4byte 0x06000800
_0800D1BC: .4byte 0x02002180
_0800D1C0: .4byte 0x00003B44
_0800D1C4: .4byte 0x00000C04

	thumb_func_start FUN_0800d1c8
FUN_0800d1c8: @ 0x0800D1C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _0800D22C @ =0x02002200
	ldr r1, _0800D230 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r1, [r5, #0x38]
	subs r1, r1, r0
	ldr r2, _0800D234 @ =0x080FEA74
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x16
	subs r0, #5
	subs r4, r1, r0
	movs r0, #0xb4
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0800D200
	adds r4, r0, #0
_0800D200:
	cmp r4, #0
	bge _0800D23C
	ldr r1, _0800D238 @ =0x02002190
	ldrh r2, [r1]
	movs r6, #0x80
	lsls r6, r6, #7
	adds r0, r6, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xfb
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	movs r2, #0xff
	movs r0, #0xff
	strh r0, [r1, #6]
	rsbs r0, r4, #0
	ands r0, r2
	b _0800D240
	.align 2, 0
_0800D22C: .4byte 0x02002200
_0800D230: .4byte 0x0002C00C
_0800D234: .4byte 0x080FEA74
_0800D238: .4byte 0x02002190
_0800D23C:
	ldr r1, _0800D25C @ =0x02002190
	movs r0, #0
_0800D240:
	strh r0, [r1, #0xa]
	lsrs r2, r3, #4
	lsls r2, r2, #2
	ldr r0, _0800D260 @ =0x0200214C
	adds r3, r2, r0
	ldr r1, [r5, #0x34]
	strh r1, [r3]
	adds r0, #2
	adds r2, r2, r0
	strh r4, [r2]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800D25C: .4byte 0x02002190
_0800D260: .4byte 0x0200214C

	thumb_func_start FUN_0800d264
FUN_0800d264: @ 0x0800D264
	ldr r1, _0800D280 @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0800D284 @ =0x02002190
	ldrh r2, [r1]
	ldr r0, _0800D288 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	bx lr
	.align 2, 0
_0800D280: .4byte 0x02002180
_0800D284: .4byte 0x02002190
_0800D288: .4byte 0x0000BFFF

	thumb_func_start ocean_0800d28c
ocean_0800d28c: @ 0x0800D28C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	bne _0800D2F8
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _0800D300 @ =0x02002144
	adds r5, r5, r3
	ldr r1, [r7, #0x60]
	ldr r2, [r7, #0x64]
	orrs r1, r2
	ldr r6, _0800D304 @ =0x00008044
	adds r2, r6, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r4, [r0]
	ldr r0, _0800D308 @ =0x0852234C
	ldr r0, [r0]
	ldr r2, _0800D30C @ =0x08522354
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldr r0, _0800D310 @ =0x08522350
	ldr r0, [r0]
	ldr r1, _0800D314 @ =0x08522358
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _0800D318 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800D2F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D300: .4byte 0x02002144
_0800D304: .4byte 0x00008044
_0800D308: .4byte 0x0852234C
_0800D30C: .4byte 0x08522354
_0800D310: .4byte 0x08522350
_0800D314: .4byte 0x08522358
_0800D318: .4byte 0x06000800

	thumb_func_start ocean_0800d31c
ocean_0800d31c: @ 0x0800D31C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #0x9f
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	str r0, [sp]
	cmp r0, #0
	bne _0800D33C
	b _0800D462
_0800D33C:
	ldr r2, _0800D474 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [sp]
	str r3, [r0]
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r1, r2, r7
	ldr r0, _0800D478 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800D47C @ =0xA6600001
	str r0, [r1]
	ldr r0, [r5, #0x34]
	subs r0, #0xf0
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [r5, #0x38]
	subs r0, #0xc0
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r8, sb
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	adds r0, #0x9f
	cmp r0, #0x87
	ble _0800D39E
	movs r7, #0x9f
	lsls r7, r7, #2
	adds r1, r3, r7
	adds r3, r2, #0
	lsls r2, r3, #0x10
	ldr r0, [sp, #4]
	orrs r2, r0
_0800D38E:
	str r2, [r1]
	subs r1, #4
	subs r6, #1
	cmp r6, #0
	blt _0800D39E
	adds r0, r6, r3
	cmp r0, #0x87
	bgt _0800D38E
_0800D39E:
	ldr r4, [r5, #0x34]
	subs r4, #0xf0
	adds r0, r4, #0
	movs r1, #3
	bl __divsi3
	lsls r4, r4, #0xe
	ldr r1, [r5, #0x38]
	subs r1, #0xc0
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #5
	asrs r2, r2, #8
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov sl, r0
	lsrs r1, r4, #0x10
	str r1, [sp, #4]
	asrs r4, r4, #0x10
	subs r4, r0, r4
	lsls r4, r4, #0xc
	lsrs r3, r2, #0x10
	mov sb, r3
	asrs r7, r2, #0x10
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	subs r5, r7, r0
	adds r5, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	str r0, [sp, #8]
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r5, #0
	bl __divsi3
	ldr r3, _0800D480 @ =0xFFFFF000
	adds r3, r3, r0
	mov ip, r3
	cmp r6, #0
	blt _0800D462
	adds r0, r6, r7
	cmp r0, #0x77
	ble _0800D446
	mov r4, r8
	mov r8, sl
	adds r5, r7, #0
	lsls r0, r6, #2
	ldr r7, [sp]
	adds r2, r0, r7
	ldr r0, _0800D484 @ =0x0000FFFF
	mov sl, r0
	rsbs r0, r6, #0
	adds r0, #0x87
	subs r3, r0, r4
_0800D418:
	mov r1, ip
	muls r1, r3, r1
	asrs r1, r1, #0xc
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ldr r7, [sp, #8]
	adds r0, r3, #0
	muls r0, r7, r0
	asrs r0, r0, #0xc
	mov r7, r8
	subs r0, r7, r0
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	str r1, [r2]
	subs r2, #4
	adds r3, #1
	subs r6, #1
	cmp r6, #0
	blt _0800D462
	adds r0, r6, r5
	cmp r0, #0x77
	bgt _0800D418
_0800D446:
	cmp r6, #0
	blt _0800D462
	mov r0, sb
	lsls r2, r0, #0x10
	ldr r1, [sp, #4]
	orrs r2, r1
	lsls r0, r6, #2
	ldr r3, [sp]
	adds r0, r0, r3
_0800D458:
	str r2, [r0]
	subs r0, #4
	subs r6, #1
	cmp r6, #0
	bge _0800D458
_0800D462:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D474: .4byte 0x03001590
_0800D478: .4byte 0x0400001C
_0800D47C: .4byte 0xA6600001
_0800D480: .4byte 0xFFFFF000
_0800D484: .4byte 0x0000FFFF

	thumb_func_start ocean_0800d488
ocean_0800d488: @ 0x0800D488
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	bne _0800D4F4
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _0800D4FC @ =0x02002144
	adds r5, r5, r3
	ldr r1, [r7, #0x60]
	ldr r2, [r7, #0x64]
	orrs r1, r2
	ldr r6, _0800D500 @ =0x00008044
	adds r2, r6, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r4, [r0]
	ldr r0, _0800D504 @ =0x08522384
	ldr r0, [r0]
	ldr r2, _0800D508 @ =0x0852238C
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldr r0, _0800D50C @ =0x08522380
	ldr r0, [r0]
	ldr r1, _0800D510 @ =0x08522388
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _0800D514 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800D4F4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D4FC: .4byte 0x02002144
_0800D500: .4byte 0x00008044
_0800D504: .4byte 0x08522384
_0800D508: .4byte 0x0852238C
_0800D50C: .4byte 0x08522380
_0800D510: .4byte 0x08522388
_0800D514: .4byte 0x06000800

	thumb_func_start setOceanBGScroll
setOceanBGScroll: @ 0x0800D518
	push {r4, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r3, _0800D540 @ =0x0200214C
	adds r4, r2, r3
	ldr r1, [r0, #0x34]
	asrs r1, r1, #1
	strh r1, [r4]
	adds r3, #2
	adds r2, r2, r3
	ldr r0, [r0, #0x38]
	asrs r0, r0, #1
	subs r0, #0x60
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800D540: .4byte 0x0200214C

	thumb_func_start ocean_0800d544
ocean_0800d544: @ 0x0800D544
	push {lr}
	adds r1, r0, #0
	ldrb r3, [r1, #0xe]
	adds r2, r3, #0
	cmp r2, #0
	bne _0800D564
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r1, #0x44]
	movs r0, #0x80
	str r0, [r1, #0x48]
	str r2, [r1, #0x4c]
	adds r0, #0xc0
	str r0, [r1, #0x50]
	adds r0, r3, #1
	strb r0, [r1, #0xe]
_0800D564:
	pop {r0}
	bx r0

	thumb_func_start ocean_0800d568
ocean_0800d568: @ 0x0800D568
	push {lr}
	ldr r0, [r0, #0x34]
	ldr r1, _0800D590 @ =0xFFFFE69F
	adds r0, r0, r1
	movs r1, #0xdf
	lsls r1, r1, #1
	cmp r0, r1
	bhi _0800D594
	movs r0, #0xe1
	bl isSoundPlaying
	cmp r0, #0
	bne _0800D588
	movs r0, #0xe1
	bl playSound
_0800D588:
	movs r0, #0xe1
	bl sound_0800465c
	b _0800D5A4
	.align 2, 0
_0800D590: .4byte 0xFFFFE69F
_0800D594:
	movs r0, #0xe1
	bl isSoundPlaying
	cmp r0, #0
	beq _0800D5A4
	movs r0, #0xe1
	bl stopSound
_0800D5A4:
	pop {r0}
	bx r0

	thumb_func_start FUN_0800d5a8
FUN_0800d5a8: @ 0x0800D5A8
	push {lr}
	ldr r2, _0800D5B8 @ =0x0833CDA8
	movs r0, #0x1f
	movs r1, #0x25
	bl patchBlockMap
	pop {r0}
	bx r0
	.align 2, 0
_0800D5B8: .4byte 0x0833CDA8

	thumb_func_start FUN_0800d5bc
FUN_0800d5bc: @ 0x0800D5BC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0800D5D0 @ =0xFFFE2000
	adds r1, r5, r0
	ldr r0, _0800D5D4 @ =0x0001DFFF
	cmp r1, r0
	bls _0800D5D8
	movs r0, #0
	b _0800D610
	.align 2, 0
_0800D5D0: .4byte 0xFFFE2000
_0800D5D4: .4byte 0x0001DFFF
_0800D5D8:
	ldr r2, _0800D618 @ =0x02002200
	movs r6, #0xfc
	lsls r6, r6, #3
	adds r2, r2, r6
	ldrh r4, [r2]
	asrs r0, r5, #0xc
	adds r1, r4, #0
	muls r1, r0, r1
	asrs r3, r3, #0xc
	adds r1, r1, r3
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r6, #0xc8
	lsls r6, r6, #0xa
	adds r0, r5, r6
	asrs r0, r0, #0xc
	muls r0, r4, r0
	adds r0, r0, r3
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
_0800D610:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0800D618: .4byte 0x02002200

	thumb_func_start FUN_0800d61c
FUN_0800d61c: @ 0x0800D61C
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0800D660 @ =0x080FECC4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800d5bc
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0800D664
	asrs r0, r5, #0xc
	lsls r2, r0, #0x10
	movs r3, #0xc8
	lsls r3, r3, #0xa
	adds r1, r4, r3
	lsls r1, r1, #4
	lsrs r1, r1, #0x10
	lsls r1, r1, #0x10
	lsrs r2, r2, #0x10
	orrs r2, r1
	str r2, [sp]
	asrs r1, r4, #0xc
	mov r2, sp
	bl shiftTerrain
	movs r0, #1
	b _0800D666
	.align 2, 0
_0800D660: .4byte 0x080FECC4
_0800D664:
	movs r0, #0
_0800D666:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
