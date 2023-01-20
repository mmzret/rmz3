	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initVolcano
initVolcano: @ 0x0800BE0C
	ldr r1, _0800BE2C @ =0x02002200
	ldr r2, _0800BE30 @ =0x0002D028
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0800BE34 @ =0x0002D02C
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, #4
	adds r0, r1, r3
	str r2, [r0]
	ldr r0, _0800BE38 @ =0x0002D034
	adds r1, r1, r0
	str r2, [r1]
	bx lr
	.align 2, 0
_0800BE2C: .4byte 0x02002200
_0800BE30: .4byte 0x0002D028
_0800BE34: .4byte 0x0002D02C
_0800BE38: .4byte 0x0002D034

	thumb_func_start volcano_0800be3c
volcano_0800be3c: @ 0x0800BE3C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r5, _0800BEA4 @ =0x02002200
	ldr r1, _0800BEA8 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800BEB4
	movs r4, #0xff
	ands r4, r1
	cmp r4, #0
	bne _0800BEB4
	ldr r0, _0800BEAC @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0800BE80
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x31
	movs r1, #0
	bl loadBlink
	movs r0, #0x32
	movs r1, #0
	bl loadBlink
	ldr r1, _0800BEB0 @ =0x0002D029
	adds r0, r5, r1
	strb r4, [r0]
_0800BE80:
	movs r0, #0x31
	bl FUN_08004068
	movs r0, #0x32
	bl FUN_08004068
	ldr r0, _0800BEB0 @ =0x0002D029
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2d
	bne _0800BED6
	strb r4, [r1]
	b _0800BED6
	.align 2, 0
_0800BEA4: .4byte 0x02002200
_0800BEA8: .4byte 0x000007D4
_0800BEAC: .4byte 0x0002D028
_0800BEB0: .4byte 0x0002D029
_0800BEB4:
	ldr r0, _0800BF10 @ =0x02002200
	ldr r1, _0800BF14 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800BED6
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x31
	bl clearBlink
	movs r0, #0x32
	bl clearBlink
_0800BED6:
	ldr r3, _0800BF10 @ =0x02002200
	ldr r1, _0800BF18 @ =0x000007D6
	adds r0, r3, r1
	ldrh r2, [r0]
	lsrs r1, r2, #8
	cmp r1, #2
	bne _0800BF1C
	movs r0, #0xff
	ands r0, r2
	cmp r0, #1
	bne _0800BF1C
	ldr r0, _0800BF14 @ =0x0002D028
	adds r3, r3, r0
	ldrb r2, [r3]
	ands r1, r2
	cmp r1, #0
	bne _0800BF06
	movs r0, #2
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x3c
	movs r1, #0
	bl loadBlink
_0800BF06:
	movs r0, #0x3c
	bl FUN_08004068
	b _0800BF38
	.align 2, 0
_0800BF10: .4byte 0x02002200
_0800BF14: .4byte 0x0002D028
_0800BF18: .4byte 0x000007D6
_0800BF1C:
	ldr r0, _0800BFA0 @ =0x02002200
	ldr r1, _0800BFA4 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800BF38
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x3c
	bl clearBlink
_0800BF38:
	ldr r5, _0800BFA0 @ =0x02002200
	ldr r1, _0800BFA8 @ =0x000007D6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800BFB0
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _0800BFB0
	ldr r0, _0800BFA4 @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0800BF7C
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x33
	movs r1, #0
	bl loadBlink
	movs r0, #0x34
	movs r1, #0
	bl loadBlink
	ldr r1, _0800BFAC @ =0x0002D02A
	adds r0, r5, r1
	strb r4, [r0]
_0800BF7C:
	movs r0, #0x33
	bl FUN_08004068
	movs r0, #0x34
	bl FUN_08004068
	ldr r0, _0800BFAC @ =0x0002D02A
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _0800BFD2
	movs r0, #0
	strb r0, [r1]
	b _0800BFD2
	.align 2, 0
_0800BFA0: .4byte 0x02002200
_0800BFA4: .4byte 0x0002D028
_0800BFA8: .4byte 0x000007D6
_0800BFAC: .4byte 0x0002D02A
_0800BFB0:
	ldr r0, _0800C074 @ =0x02002200
	ldr r1, _0800C078 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800BFD2
	movs r0, #4
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x33
	bl clearBlink
	movs r0, #0x34
	bl clearBlink
_0800BFD2:
	ldr r5, _0800C074 @ =0x02002200
	ldr r1, _0800C07C @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C084
	movs r0, #0xff
	ands r0, r1
	cmp r0, #3
	bne _0800C084
	ldr r0, _0800C078 @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0800C036
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x32
	movs r1, #0
	bl loadBlink
	movs r0, #0x35
	movs r1, #0
	bl loadBlink
	movs r0, #0x36
	movs r1, #0
	bl loadBlink
	movs r0, #0x37
	movs r1, #0
	bl loadBlink
	movs r0, #0x38
	movs r1, #0
	bl loadBlink
	movs r0, #0x39
	movs r1, #0
	bl loadBlink
	ldr r1, _0800C080 @ =0x0002D029
	adds r0, r5, r1
	strb r4, [r0]
_0800C036:
	movs r0, #0x32
	bl FUN_08004068
	movs r0, #0x35
	bl FUN_08004068
	movs r0, #0x36
	bl FUN_08004068
	movs r0, #0x37
	bl FUN_08004068
	movs r0, #0x38
	bl FUN_08004068
	movs r0, #0x39
	bl FUN_08004068
	ldr r0, _0800C080 @ =0x0002D029
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2d
	bne _0800C0BE
	movs r0, #0
	strb r0, [r1]
	b _0800C0BE
	.align 2, 0
_0800C074: .4byte 0x02002200
_0800C078: .4byte 0x0002D028
_0800C07C: .4byte 0x000007D4
_0800C080: .4byte 0x0002D029
_0800C084:
	ldr r0, _0800C134 @ =0x02002200
	ldr r1, _0800C138 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800C0BE
	movs r0, #8
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x32
	bl clearBlink
	movs r0, #0x35
	bl clearBlink
	movs r0, #0x36
	bl clearBlink
	movs r0, #0x37
	bl clearBlink
	movs r0, #0x38
	bl clearBlink
	movs r0, #0x39
	bl clearBlink
_0800C0BE:
	ldr r5, _0800C134 @ =0x02002200
	ldr r1, _0800C13C @ =0x000007D6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C148
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _0800C148
	ldr r0, _0800C138 @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0800C100
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x3a
	movs r1, #0
	bl loadBlink
	ldr r1, _0800C140 @ =0x0002D02A
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r4, [r0]
_0800C100:
	movs r0, #0x3a
	bl FUN_08004068
	ldr r0, _0800C140 @ =0x0002D02A
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2d
	bne _0800C11C
	strb r2, [r1]
_0800C11C:
	ldr r0, _0800C144 @ =0x0002D02B
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _0800C164
	strb r2, [r1]
	b _0800C164
	.align 2, 0
_0800C134: .4byte 0x02002200
_0800C138: .4byte 0x0002D028
_0800C13C: .4byte 0x000007D6
_0800C140: .4byte 0x0002D02A
_0800C144: .4byte 0x0002D02B
_0800C148:
	ldr r0, _0800C1E8 @ =0x02002200
	ldr r1, _0800C1EC @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800C164
	movs r0, #0x10
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x3a
	bl clearBlink
_0800C164:
	ldr r5, _0800C1E8 @ =0x02002200
	ldr r1, _0800C1F0 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C1F8
	movs r0, #0xff
	ands r0, r1
	cmp r0, #5
	bne _0800C1F8
	ldr r0, _0800C1EC @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0800C1B8
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x35
	movs r1, #0
	bl loadBlink
	movs r0, #0x36
	movs r1, #0
	bl loadBlink
	movs r0, #0x38
	movs r1, #0
	bl loadBlink
	movs r0, #0x39
	movs r1, #0
	bl loadBlink
	ldr r1, _0800C1F4 @ =0x0002D029
	adds r0, r5, r1
	strb r4, [r0]
_0800C1B8:
	movs r0, #0x35
	bl FUN_08004068
	movs r0, #0x36
	bl FUN_08004068
	movs r0, #0x38
	bl FUN_08004068
	movs r0, #0x39
	bl FUN_08004068
	ldr r0, _0800C1F4 @ =0x0002D029
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bne _0800C226
	movs r0, #0
	strb r0, [r1]
	b _0800C226
	.align 2, 0
_0800C1E8: .4byte 0x02002200
_0800C1EC: .4byte 0x0002D028
_0800C1F0: .4byte 0x000007D4
_0800C1F4: .4byte 0x0002D029
_0800C1F8:
	ldr r0, _0800C260 @ =0x02002200
	ldr r1, _0800C264 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800C226
	movs r0, #0x20
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x35
	bl clearBlink
	movs r0, #0x36
	bl clearBlink
	movs r0, #0x38
	bl clearBlink
	movs r0, #0x39
	bl clearBlink
_0800C226:
	ldr r2, _0800C260 @ =0x02002200
	ldr r1, _0800C268 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C26C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #6
	bne _0800C26C
	ldr r0, _0800C264 @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0800C258
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x3b
	movs r1, #0
	bl loadBlink
_0800C258:
	movs r0, #0x3b
	bl FUN_08004068
	b _0800C288
	.align 2, 0
_0800C260: .4byte 0x02002200
_0800C264: .4byte 0x0002D028
_0800C268: .4byte 0x000007D4
_0800C26C:
	ldr r0, _0800C2C8 @ =0x02002200
	ldr r1, _0800C2CC @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800C288
	movs r0, #0x40
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x3b
	bl clearBlink
_0800C288:
	ldr r0, [r6]
	ldr r1, _0800C2D0 @ =0xFFE20000
	adds r0, r0, r1
	ldr r1, _0800C2D4 @ =0x000E0FFF
	cmp r0, r1
	bhi _0800C2E8
	ldr r5, _0800C2C8 @ =0x02002200
	ldr r0, _0800C2D8 @ =0x0002D030
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _0800C2AE
	ldr r1, _0800C2DC @ =0x001F3800
	movs r2, #0xe0
	lsls r2, r2, #9
	movs r0, #0
	bl createVolcanoCoffin
	str r0, [r4]
_0800C2AE:
	ldr r1, _0800C2E0 @ =0x0002D034
	adds r4, r5, r1
	ldr r0, [r4]
	cmp r0, #0
	bne _0800C36E
	ldr r1, _0800C2E4 @ =0x0020B800
	movs r2, #0x94
	lsls r2, r2, #0xa
	movs r0, #1
	bl createVolcanoCoffin
	str r0, [r4]
	b _0800C36E
	.align 2, 0
_0800C2C8: .4byte 0x02002200
_0800C2CC: .4byte 0x0002D028
_0800C2D0: .4byte 0xFFE20000
_0800C2D4: .4byte 0x000E0FFF
_0800C2D8: .4byte 0x0002D030
_0800C2DC: .4byte 0x001F3800
_0800C2E0: .4byte 0x0002D034
_0800C2E4: .4byte 0x0020B800
_0800C2E8:
	ldr r5, _0800C380 @ =0x02002200
	ldr r0, _0800C384 @ =0x0002D030
	adds r4, r5, r0
	ldr r3, [r4]
	cmp r3, #0
	beq _0800C32C
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0800C388 @ =0x0836FB24
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	str r2, [r4]
_0800C32C:
	ldr r1, _0800C38C @ =0x0002D034
	adds r4, r5, r1
	ldr r3, [r4]
	cmp r3, #0
	beq _0800C36E
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0800C388 @ =0x0836FB24
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	str r2, [r4]
_0800C36E:
	ldr r1, _0800C380 @ =0x02002200
	ldr r0, _0800C390 @ =0x0002D02C
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800C380: .4byte 0x02002200
_0800C384: .4byte 0x0002D030
_0800C388: .4byte 0x0836FB24
_0800C38C: .4byte 0x0002D034
_0800C390: .4byte 0x0002D02C

	thumb_func_start volcano_0800c394
volcano_0800c394: @ 0x0800C394
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r5, _0800C58C @ =0x02002200
	ldr r1, _0800C590 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C3F6
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	bne _0800C3F6
	ldr r4, _0800C594 @ =0x087044F8
	ldr r0, _0800C598 @ =0x0002D029
	adds r5, r5, r0
	ldrb r0, [r5]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrb r0, [r5]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_0800C3F6:
	ldr r5, _0800C58C @ =0x02002200
	ldr r1, _0800C59C @ =0x000007D6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C444
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _0800C444
	ldr r6, _0800C594 @ =0x087044F8
	ldr r0, _0800C5A0 @ =0x0002D02A
	adds r5, r5, r0
	ldrb r0, [r5]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0800C5A4 @ =0x0870455C
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrb r0, [r5]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_0800C444:
	ldr r5, _0800C58C @ =0x02002200
	ldr r1, _0800C590 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C4A0
	movs r0, #0xff
	ands r0, r1
	cmp r0, #3
	bne _0800C4A0
	ldr r4, _0800C594 @ =0x087044F8
	ldr r0, _0800C598 @ =0x0002D029
	adds r5, r5, r0
	ldrb r0, [r5]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrb r0, [r5]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_0800C4A0:
	ldr r7, _0800C58C @ =0x02002200
	ldr r1, _0800C59C @ =0x000007D6
	adds r0, r7, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C534
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _0800C534
	ldr r6, _0800C594 @ =0x087044F8
	ldr r0, _0800C5A0 @ =0x0002D02A
	adds r5, r7, r0
	ldrb r0, [r5]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0800C5A8 @ =0x087045AC
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	mov r8, r1
	bl appendGraphicTask
	ldrb r0, [r5]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	ldr r0, _0800C5AC @ =0x0002D02B
	adds r5, r7, r0
	ldrb r0, [r5]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r4, #0x64
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldrb r0, [r5]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_0800C534:
	ldr r5, _0800C58C @ =0x02002200
	ldr r1, _0800C590 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #2
	bne _0800C582
	movs r0, #0xff
	ands r0, r1
	cmp r0, #5
	bne _0800C582
	ldr r6, _0800C594 @ =0x087044F8
	ldr r0, _0800C598 @ =0x0002D029
	adds r5, r5, r0
	ldrb r0, [r5]
	lsrs r0, r0, #3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0800C5B0 @ =0x087046EC
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
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
_0800C582:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C58C: .4byte 0x02002200
_0800C590: .4byte 0x000007D4
_0800C594: .4byte 0x087044F8
_0800C598: .4byte 0x0002D029
_0800C59C: .4byte 0x000007D6
_0800C5A0: .4byte 0x0002D02A
_0800C5A4: .4byte 0x0870455C
_0800C5A8: .4byte 0x087045AC
_0800C5AC: .4byte 0x0002D02B
_0800C5B0: .4byte 0x087046EC

	thumb_func_start exitVolcano
exitVolcano: @ 0x0800C5B4
	push {lr}
	movs r0, #0x31
	bl clearBlink
	movs r0, #0x32
	bl clearBlink
	movs r0, #0x33
	bl clearBlink
	movs r0, #0x34
	bl clearBlink
	movs r0, #0x35
	bl clearBlink
	movs r0, #0x36
	bl clearBlink
	movs r0, #0x37
	bl clearBlink
	movs r0, #0x38
	bl clearBlink
	movs r0, #0x39
	bl clearBlink
	movs r0, #0x3a
	bl clearBlink
	movs r0, #0x3b
	bl clearBlink
	movs r0, #0x3c
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800c604
FUN_0800c604: @ 0x0800C604
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	cmp r2, #0
	bne _0800C620
	movs r0, #0x80
	str r0, [r1, #0x44]
	str r0, [r1, #0x48]
	ldr r0, _0800C624 @ =0x00000C6C
	str r0, [r1, #0x4c]
	movs r0, #0xc0
	str r0, [r1, #0x50]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_0800C620:
	pop {r0}
	bx r0
	.align 2, 0
_0800C624: .4byte 0x00000C6C

	thumb_func_start FUN_0800c628
FUN_0800c628: @ 0x0800C628
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	cmp r2, #0
	bne _0800C646
	movs r0, #0x80
	str r0, [r1, #0x44]
	str r0, [r1, #0x48]
	movs r0, #0x96
	lsls r0, r0, #5
	str r0, [r1, #0x4c]
	movs r0, #0xc0
	str r0, [r1, #0x50]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_0800C646:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800c64c
FUN_0800c64c: @ 0x0800C64C
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800C6A4
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _0800C68C @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _0800C690 @ =0x0000FFFC
	ands r1, r2
	movs r2, #3
	orrs r1, r2
	strh r1, [r0]
	movs r1, #0x40
	str r1, [r3, #0x44]
	str r1, [r3, #0x48]
	movs r0, #0xcc
	str r0, [r3, #0x4c]
	ldr r0, _0800C694 @ =0x0202FE20
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	ands r0, r1
	cmp r0, #0
	bne _0800C698
	movs r0, #0xb4
	lsls r0, r0, #1
	b _0800C69C
	.align 2, 0
_0800C68C: .4byte 0x02002144
_0800C690: .4byte 0x0000FFFC
_0800C694: .4byte 0x0202FE20
_0800C698:
	movs r0, #0xd2
	lsls r0, r0, #2
_0800C69C:
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800C6A4:
	pop {r0}
	bx r0

	thumb_func_start volcanoEruption
volcanoEruption: @ 0x0800C6A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r5, #0xdc
	ldrb r3, [r7, #0xe]
	cmp r3, #1
	beq _0800C700
	cmp r3, #1
	bgt _0800C6CE
	cmp r3, #0
	beq _0800C6D4
	b _0800C730
_0800C6CE:
	cmp r3, #2
	beq _0800C74C
	b _0800C730
_0800C6D4:
	lsrs r2, r0, #0x14
	lsls r2, r2, #1
	ldr r0, _0800C738 @ =0x02002144
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _0800C73C @ =0x0000FFFC
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xc0
	str r0, [r7, #0x44]
	str r0, [r7, #0x48]
	adds r0, #0xa8
	str r0, [r7, #0x4c]
	movs r0, #0x78
	str r0, [r7, #0x50]
	strh r3, [r7, #0x10]
	strh r3, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800C700:
	ldr r1, _0800C740 @ =0xFFFFFA1C
	adds r0, r5, r1
	ldr r1, [r7, #0x34]
	adds r0, r1, r0
	cmp r0, r5
	blo _0800C71C
	ldr r2, _0800C744 @ =0xFFFFF884
	adds r0, r5, r2
	adds r0, r1, r0
	lsls r1, r4, #8
	mov r8, r1
	cmp r0, r5
	blo _0800C71C
	b _0800C840
_0800C71C:
	movs r0, #0x78
	bl playSound
	ldr r1, _0800C748 @ =0x0202FF80
	movs r0, #8
	bl shake_0801ab60
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800C730:
	lsls r4, r4, #8
	mov r8, r4
	b _0800C840
	.align 2, 0
_0800C738: .4byte 0x02002144
_0800C73C: .4byte 0x0000FFFC
_0800C740: .4byte 0xFFFFFA1C
_0800C744: .4byte 0xFFFFF884
_0800C748: .4byte 0x0202FF80
_0800C74C:
	ldrh r0, [r7, #0x10]
	adds r0, #1
	strh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bne _0800C808
	movs r6, #0
	lsls r4, r4, #8
	mov r8, r4
_0800C760:
	mov r2, sp
	adds r0, r2, r6
	strb r6, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #6
	bls _0800C760
	movs r6, #0
	ldr r4, _0800C7FC @ =0x0202F388
	mov sb, r4
	ldr r0, _0800C800 @ =0x00269EC3
	mov sl, r0
_0800C77A:
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0800C804 @ =0x000343FD
	muls r0, r2, r0
	add r0, sl
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r1]
	lsrs r0, r0, #0x11
	movs r1, #7
	bl __umodsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0800C804 @ =0x000343FD
	adds r0, r5, #0
	muls r0, r1, r0
	add r0, sl
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, sb
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sp
	adds r2, r1, r4
	ldrb r3, [r2]
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0xf
	bls _0800C77A
	movs r6, #0
_0800C7CE:
	lsls r2, r6, #2
	adds r2, r2, r7
	mov r4, sp
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r1, r1, #5
	adds r1, #0x18
	ldr r0, [r7, #0x34]
	adds r0, r0, r1
	lsls r0, r0, #8
	str r0, [r2, #0x68]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #2
	bls _0800C7CE
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x38]
	lsls r1, r1, #8
	bl createVolcanoBomb
	b _0800C82E
	.align 2, 0
_0800C7FC: .4byte 0x0202F388
_0800C800: .4byte 0x00269EC3
_0800C804: .4byte 0x000343FD
_0800C808:
	cmp r0, #0x40
	bne _0800C81C
	ldr r0, [r7, #0x6c]
	ldr r1, [r7, #0x38]
	lsls r1, r1, #8
	bl createVolcanoBomb
	lsls r4, r4, #8
	mov r8, r4
	b _0800C82E
_0800C81C:
	lsls r4, r4, #8
	mov r8, r4
	cmp r0, #0x50
	bne _0800C82E
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x38]
	lsls r1, r1, #8
	bl createVolcanoBomb
_0800C82E:
	ldrh r0, [r7, #0x10]
	cmp r0, #0xa0
	bne _0800C840
	movs r0, #0
	strh r0, [r7, #0x10]
	strh r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	subs r0, #1
	strb r0, [r7, #0xe]
_0800C840:
	ldr r1, [r7, #0x34]
	ldr r0, _0800C854 @ =0x0000043F
	cmp r1, r0
	bgt _0800C85C
	ldr r1, _0800C858 @ =0x02002140
	ldrh r0, [r1]
	mov r2, r8
	bics r0, r2
	strh r0, [r1]
	b _0800C866
	.align 2, 0
_0800C854: .4byte 0x0000043F
_0800C858: .4byte 0x02002140
_0800C85C:
	ldr r1, _0800C878 @ =0x02002140
	ldrh r0, [r1]
	mov r4, r8
	orrs r4, r0
	strh r4, [r1]
_0800C866:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C878: .4byte 0x02002140

	thumb_func_start volcano_0800c87c
volcano_0800c87c: @ 0x0800C87C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	ldr r1, _0800C8FC @ =0x0833BF1C
	ldrh r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r3, r1, #1
	adds r0, r0, r3
	ldrh r2, [r6, #0x10]
	adds r7, r1, #0
	ldrb r0, [r0]
	cmp r2, r0
	blo _0800C8AE
	adds r1, r3, #0
_0800C89C:
	ldrh r0, [r6, #0x12]
	adds r0, #1
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bhs _0800C89C
_0800C8AE:
	ldr r5, _0800C900 @ =0x087044F8
	ldrh r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0800C904 @ =0x08704660
	adds r1, r1, r4
	ldr r0, [r5]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r5]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	adds r0, r6, #0
	mov r1, r8
	bl variousStageFunc_080093b8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C8FC: .4byte 0x0833BF1C
_0800C900: .4byte 0x087044F8
_0800C904: .4byte 0x08704660

	thumb_func_start volcano_0800c908
volcano_0800c908: @ 0x0800C908
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0800C94C
	lsrs r2, r0, #0x14
	lsls r2, r2, #1
	ldr r0, _0800C968 @ =0x02002144
	adds r2, r2, r0
	ldr r1, [r4, #0x64]
	ldr r3, _0800C96C @ =0x00008047
	adds r0, r3, #0
	orrs r1, r0
	strh r1, [r2]
	ldr r2, _0800C970 @ =0x40404040
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r2, [sp]
	ldr r2, _0800C974 @ =0x01000400
	mov r0, sp
	bl CpuFastSet
	strh r5, [r4, #0x10]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800C94C:
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bne _0800C95E
	movs r0, #0
	strh r0, [r4, #0x10]
_0800C95E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800C968: .4byte 0x02002144
_0800C96C: .4byte 0x00008047
_0800C970: .4byte 0x40404040
_0800C974: .4byte 0x01000400

	thumb_func_start volcano_0800c978
volcano_0800c978: @ 0x0800C978
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	mov r8, r0
	ldr r6, [r0, #0x5c]
	lsls r6, r6, #0x10
	lsrs r3, r6, #0x10
	ldrh r4, [r0, #0x10]
	adds r0, r4, #0
	movs r1, #6
	str r3, [sp, #4]
	bl __udivsi3
	adds r2, r0, #0
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r1, _0800C9F0 @ =0x085222A0
	lsls r2, r2, #0x18
	movs r0, #0xbc
	lsls r0, r0, #0x16
	adds r2, r2, r0
	lsrs r2, r2, #0x18
	movs r5, #1
	ands r4, r5
	lsls r4, r4, #5
	adds r4, #2
	str r4, [sp]
	adds r0, r3, #0
	movs r3, #7
	bl loadBGMapIntoVram
	lsrs r6, r6, #0x14
	lsls r6, r6, #2
	ldr r1, _0800C9F4 @ =0x0200214C
	adds r2, r6, r1
	mov r3, r8
	ldr r0, [r3, #0x34]
	ldr r3, _0800C9F8 @ =0xFFFFD300
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #2
	adds r6, r6, r1
	mov r1, r8
	ldr r0, [r1, #0x38]
	ldr r2, _0800C9FC @ =0xFFFFFEC0
	adds r0, r0, r2
	ldrh r1, [r1, #0x10]
	ands r5, r1
	lsls r5, r5, #8
	adds r0, r0, r5
	strh r0, [r6]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800C9F0: .4byte 0x085222A0
_0800C9F4: .4byte 0x0200214C
_0800C9F8: .4byte 0xFFFFD300
_0800C9FC: .4byte 0xFFFFFEC0

	thumb_func_start volcano_0800ca00
volcano_0800ca00: @ 0x0800CA00
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0800CA1C
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x3d
	bl loadBlink
	strh r5, [r4, #0x10]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800CA1C:
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x90
	bne _0800CA2E
	movs r0, #0
	strh r0, [r4, #0x10]
_0800CA2E:
	ldrh r4, [r4, #0x10]
	adds r0, r4, #0
	movs r1, #0x30
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800CA8A
	adds r0, r4, #0
	cmp r0, #0x2f
	bhi _0800CA5C
	ldr r4, _0800CA58 @ =0x0833BF40
	ldr r0, [r4]
	ldr r1, [r4, #4]
	bl FUN_080ccde8
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	bl FUN_080ccde8
	b _0800CA8A
	.align 2, 0
_0800CA58: .4byte 0x0833BF40
_0800CA5C:
	cmp r0, #0x5f
	bhi _0800CA78
	ldr r4, _0800CA74 @ =0x0833BF40
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	bl FUN_080ccde8
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	bl FUN_080ccde8
	b _0800CA8A
	.align 2, 0
_0800CA74: .4byte 0x0833BF40
_0800CA78:
	ldr r4, _0800CA98 @ =0x0833BF40
	ldr r0, [r4, #0x10]
	ldr r1, [r4, #0x14]
	bl FUN_080ccde8
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	bl FUN_080ccde8
_0800CA8A:
	movs r0, #0x3d
	bl FUN_08004068
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800CA98: .4byte 0x0833BF40

	thumb_func_start nop_0800ca9c
nop_0800ca9c: @ 0x0800CA9C
	push {lr}
	movs r0, #0x3d
	bl clearBlink
	pop {r0}
	bx r0

	thumb_func_start volcano_0800caa8
volcano_0800caa8: @ 0x0800CAA8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	bne _0800CAC6
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x3d
	bl loadBlink
	strh r4, [r5, #0x10]
	strh r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0800CAC6:
	ldrh r0, [r5, #0x10]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x90
	bne _0800CAD8
	strh r6, [r5, #0x10]
_0800CAD8:
	ldrh r0, [r5, #0x10]
	cmp r0, #0
	bne _0800CAF8
	ldr r4, _0800CB3C @ =0x0833BF70
	ldr r0, [r4]
	ldr r1, [r4, #4]
	bl FUN_080ccde8
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	bl FUN_080ccde8
	ldr r0, [r4, #0x10]
	ldr r1, [r4, #0x14]
	bl FUN_080ccde8
_0800CAF8:
	ldrh r0, [r5, #0x12]
	adds r0, #1
	strh r0, [r5, #0x12]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x60
	bne _0800CB08
	strh r6, [r5, #0x12]
_0800CB08:
	ldrh r0, [r5, #0x12]
	cmp r0, #0
	bne _0800CB18
	ldr r1, _0800CB3C @ =0x0833BF70
	ldr r0, [r1, #0x20]
	ldr r1, [r1, #0x2c]
	bl FUN_080ccde8
_0800CB18:
	ldrh r0, [r5, #0x12]
	cmp r0, #0x30
	bne _0800CB30
	ldr r4, _0800CB3C @ =0x0833BF70
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x2c]
	bl FUN_080ccde8
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	bl FUN_080ccde8
_0800CB30:
	movs r0, #0x3d
	bl FUN_08004068
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800CB3C: .4byte 0x0833BF70

	thumb_func_start FUN_0800cb40
FUN_0800cb40: @ 0x0800CB40
	push {lr}
	movs r0, #0x3d
	bl clearBlink
	pop {r0}
	bx r0
