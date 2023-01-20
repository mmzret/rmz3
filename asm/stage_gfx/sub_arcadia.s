	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08014b28
FUN_08014b28: @ 0x08014B28
	ldr r0, _08014B3C @ =0x02002200
	ldr r2, _08014B40 @ =0x0002D028
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r1, _08014B44 @ =0x0002D029
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_08014B3C: .4byte 0x02002200
_08014B40: .4byte 0x0002D028
_08014B44: .4byte 0x0002D029

	thumb_func_start subAracadia_08014b48
subAracadia_08014b48: @ 0x08014B48
	push {r4, lr}
	ldr r2, _08014BBC @ =0x02002200
	ldr r1, _08014BC0 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xf
	bne _08014BC8
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	bne _08014BC8
	ldr r0, _08014BC4 @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08014B9C
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x7c
	movs r1, #0
	bl loadBlink
	movs r0, #0x7d
	movs r1, #0
	bl loadBlink
	movs r0, #0x7e
	movs r1, #0
	bl loadBlink
	movs r0, #0x82
	movs r1, #0
	bl loadBlink
	movs r0, #0xa6
	movs r1, #0
	bl loadBlink
_08014B9C:
	movs r0, #0x7c
	bl FUN_08004068
	movs r0, #0x7d
	bl FUN_08004068
	movs r0, #0x7e
	bl FUN_08004068
	movs r0, #0x82
	bl FUN_08004068
	movs r0, #0xa6
	bl FUN_08004068
	b _08014BFC
	.align 2, 0
_08014BBC: .4byte 0x02002200
_08014BC0: .4byte 0x000007D4
_08014BC4: .4byte 0x0002D028
_08014BC8:
	ldr r0, _08014C54 @ =0x02002200
	ldr r1, _08014C58 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08014BFC
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x7c
	bl clearBlink
	movs r0, #0x7d
	bl clearBlink
	movs r0, #0x7e
	bl clearBlink
	movs r0, #0x82
	bl clearBlink
	movs r0, #0xa6
	bl clearBlink
_08014BFC:
	ldr r2, _08014C54 @ =0x02002200
	ldr r1, _08014C5C @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xf
	bne _08014C60
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _08014C60
	ldr r0, _08014C58 @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08014C3E
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x7f
	movs r1, #0
	bl loadBlink
	movs r0, #0x80
	movs r1, #0
	bl loadBlink
	movs r0, #0x81
	movs r1, #0
	bl loadBlink
_08014C3E:
	movs r0, #0x7f
	bl FUN_08004068
	movs r0, #0x80
	bl FUN_08004068
	movs r0, #0x81
	bl FUN_08004068
	b _08014C88
	.align 2, 0
_08014C54: .4byte 0x02002200
_08014C58: .4byte 0x0002D028
_08014C5C: .4byte 0x000007D6
_08014C60:
	ldr r0, _08014CFC @ =0x02002200
	ldr r1, _08014D00 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08014C88
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x7f
	bl clearBlink
	movs r0, #0x80
	bl clearBlink
	movs r0, #0x81
	bl clearBlink
_08014C88:
	ldr r2, _08014CFC @ =0x02002200
	ldr r1, _08014D04 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xf
	bne _08014D08
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _08014D08
	ldr r0, _08014D00 @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08014CDA
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xa1
	movs r1, #0
	bl loadBlink
	movs r0, #0xa2
	movs r1, #0
	bl loadBlink
	movs r0, #0xa3
	movs r1, #0
	bl loadBlink
	movs r0, #0xa4
	movs r1, #0
	bl loadBlink
	movs r0, #0xa5
	movs r1, #0
	bl loadBlink
_08014CDA:
	movs r0, #0xa1
	bl FUN_08004068
	movs r0, #0xa2
	bl FUN_08004068
	movs r0, #0xa3
	bl FUN_08004068
	movs r0, #0xa4
	bl FUN_08004068
	movs r0, #0xa5
	bl FUN_08004068
	b _08014D3C
	.align 2, 0
_08014CFC: .4byte 0x02002200
_08014D00: .4byte 0x0002D028
_08014D04: .4byte 0x000007D4
_08014D08:
	ldr r0, _08014DCC @ =0x02002200
	ldr r1, _08014DD0 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08014D3C
	movs r0, #4
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xa1
	bl clearBlink
	movs r0, #0xa2
	bl clearBlink
	movs r0, #0xa3
	bl clearBlink
	movs r0, #0xa4
	bl clearBlink
	movs r0, #0xa5
	bl clearBlink
_08014D3C:
	ldr r2, _08014DCC @ =0x02002200
	ldr r1, _08014DD4 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xf
	bne _08014DD8
	movs r0, #0xff
	ands r0, r1
	cmp r0, #3
	bne _08014DD8
	ldr r0, _08014DD0 @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08014D9E
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x9a
	movs r1, #0
	bl loadBlink
	movs r0, #0x9b
	movs r1, #0
	bl loadBlink
	movs r0, #0x9c
	movs r1, #0
	bl loadBlink
	movs r0, #0x9d
	movs r1, #0
	bl loadBlink
	movs r0, #0x9e
	movs r1, #0
	bl loadBlink
	movs r0, #0x9f
	movs r1, #0
	bl loadBlink
	movs r0, #0xa0
	movs r1, #0
	bl loadBlink
_08014D9E:
	movs r0, #0x9a
	bl FUN_08004068
	movs r0, #0x9b
	bl FUN_08004068
	movs r0, #0x9c
	bl FUN_08004068
	movs r0, #0x9d
	bl FUN_08004068
	movs r0, #0x9e
	bl FUN_08004068
	movs r0, #0x9f
	bl FUN_08004068
	movs r0, #0xa0
	bl FUN_08004068
	b _08014E18
	.align 2, 0
_08014DCC: .4byte 0x02002200
_08014DD0: .4byte 0x0002D028
_08014DD4: .4byte 0x000007D6
_08014DD8:
	ldr r0, _08014E68 @ =0x02002200
	ldr r1, _08014E6C @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08014E18
	movs r0, #8
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x9a
	bl clearBlink
	movs r0, #0x9b
	bl clearBlink
	movs r0, #0x9c
	bl clearBlink
	movs r0, #0x9d
	bl clearBlink
	movs r0, #0x9e
	bl clearBlink
	movs r0, #0x9f
	bl clearBlink
	movs r0, #0xa0
	bl clearBlink
_08014E18:
	ldr r0, _08014E68 @ =0x02002200
	ldr r1, _08014E70 @ =0x0002D029
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	bne _08014E42
	ldr r0, _08014E74 @ =0x0202FDC0
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08014E3C
	movs r0, #1
	strb r0, [r4]
	movs r1, #6
	movs r2, #0x4e
	bl loadScreenIntoBlockMap
_08014E3C:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08014E62
_08014E42:
	ldr r0, _08014E74 @ =0x0202FDC0
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08014E62
	ldr r0, _08014E68 @ =0x02002200
	ldr r1, _08014E70 @ =0x0002D029
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #1
	movs r1, #6
	movs r2, #0x17
	bl loadScreenIntoBlockMap
_08014E62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014E68: .4byte 0x02002200
_08014E6C: .4byte 0x0002D028
_08014E70: .4byte 0x0002D029
_08014E74: .4byte 0x0202FDC0

	thumb_func_start nop_08014e78
nop_08014e78: @ 0x08014E78
	bx lr
	.align 2, 0

	thumb_func_start FUN_08014e7c
FUN_08014e7c: @ 0x08014E7C
	push {lr}
	movs r0, #0x7c
	bl clearBlink
	movs r0, #0x7d
	bl clearBlink
	movs r0, #0x7e
	bl clearBlink
	movs r0, #0x7f
	bl clearBlink
	movs r0, #0x80
	bl clearBlink
	movs r0, #0x81
	bl clearBlink
	movs r0, #0x82
	bl clearBlink
	movs r0, #0x9a
	bl clearBlink
	movs r0, #0x9b
	bl clearBlink
	movs r0, #0x9c
	bl clearBlink
	movs r0, #0x9d
	bl clearBlink
	movs r0, #0x9e
	bl clearBlink
	movs r0, #0x9f
	bl clearBlink
	movs r0, #0xa0
	bl clearBlink
	movs r0, #0xa1
	bl clearBlink
	movs r0, #0xa2
	bl clearBlink
	movs r0, #0xa3
	bl clearBlink
	movs r0, #0xa4
	bl clearBlink
	movs r0, #0xa5
	bl clearBlink
	movs r0, #0xa6
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08014efc
FUN_08014efc: @ 0x08014EFC
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	bne _08014F54
	ldr r1, [r2, #0x34]
	movs r0, #0x87
	lsls r0, r0, #4
	cmp r1, r0
	ble _08014F22
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r2, #0x44]
	movs r0, #0x40
	str r0, [r2, #0x48]
	str r3, [r2, #0x4c]
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08014F4C
_08014F22:
	ldr r1, [r2, #0x38]
	ldr r0, _08014F38 @ =0x000001DF
	cmp r1, r0
	bgt _08014F3C
	movs r0, #0x80
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	movs r0, #0x78
	str r0, [r2, #0x4c]
	movs r0, #0x50
	b _08014F4C
	.align 2, 0
_08014F38: .4byte 0x000001DF
_08014F3C:
	movs r0, #0x40
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	movs r0, #0xb4
	lsls r0, r0, #1
	str r0, [r2, #0x4c]
	movs r0, #0xb4
	lsls r0, r0, #2
_08014F4C:
	str r0, [r2, #0x50]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08014F54:
	pop {r0}
	bx r0

	thumb_func_start FUN_08014f58
FUN_08014f58: @ 0x08014F58
	push {lr}
	adds r1, r0, #0
	ldrb r3, [r1, #0xe]
	adds r2, r3, #0
	cmp r2, #0
	bne _08014F7A
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r1, #0x44]
	movs r0, #0x80
	str r0, [r1, #0x48]
	str r2, [r1, #0x4c]
	movs r0, #0x96
	lsls r0, r0, #3
	str r0, [r1, #0x50]
	adds r0, r3, #1
	strb r0, [r1, #0xe]
_08014F7A:
	pop {r0}
	bx r0
	.align 2, 0
