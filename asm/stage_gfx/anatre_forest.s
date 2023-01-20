	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initAnatreForest
initAnatreForest: @ 0x080101BC
	ldr r0, _080101E0 @ =0x02002200
	ldr r2, _080101E4 @ =0x0002D028
	adds r1, r0, r2
	movs r2, #0
	str r2, [r1]
	ldr r3, _080101E8 @ =0x0002D02C
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #4
	adds r1, r0, r3
	str r2, [r1]
	adds r3, #4
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _080101EC @ =0x0002D035
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_080101E0: .4byte 0x02002200
_080101E4: .4byte 0x0002D028
_080101E8: .4byte 0x0002D02C
_080101EC: .4byte 0x0002D035

	thumb_func_start FUN_080101f0
FUN_080101f0: @ 0x080101F0
	push {r4, r5, lr}
	ldr r5, _0801025C @ =0x02002200
	ldr r0, _08010260 @ =0x0002D028
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _08010206
	movs r0, #1
	bl FUN_080cb364
	str r0, [r4]
_08010206:
	ldr r1, _08010264 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #8
	bne _0801026C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	bne _0801026C
	ldr r0, _08010268 @ =0x0002D034
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08010246
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xda
	movs r1, #0
	bl loadBlink
	movs r0, #0xdb
	movs r1, #0
	bl loadBlink
	movs r0, #0xdc
	movs r1, #0
	bl loadBlink
_08010246:
	movs r0, #0xda
	bl FUN_08004068
	movs r0, #0xdb
	bl FUN_08004068
	movs r0, #0xdc
	bl FUN_08004068
	b _08010294
	.align 2, 0
_0801025C: .4byte 0x02002200
_08010260: .4byte 0x0002D028
_08010264: .4byte 0x000007D4
_08010268: .4byte 0x0002D034
_0801026C:
	ldr r0, _080102D0 @ =0x02002200
	ldr r1, _080102D4 @ =0x0002D034
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08010294
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xda
	bl clearBlink
	movs r0, #0xdb
	bl clearBlink
	movs r0, #0xdc
	bl clearBlink
_08010294:
	ldr r2, _080102D0 @ =0x02002200
	ldr r1, _080102D8 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #8
	bne _080102DC
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _080102DC
	ldr r0, _080102D4 @ =0x0002D034
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080102C6
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xdd
	movs r1, #0
	bl loadBlink
_080102C6:
	movs r0, #0xdd
	bl FUN_08004068
	b _080102F8
	.align 2, 0
_080102D0: .4byte 0x02002200
_080102D4: .4byte 0x0002D034
_080102D8: .4byte 0x000007D6
_080102DC:
	ldr r0, _08010380 @ =0x02002200
	ldr r1, _08010384 @ =0x0002D034
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080102F8
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xdd
	bl clearBlink
_080102F8:
	ldr r4, _08010380 @ =0x02002200
	ldr r2, _08010388 @ =0x000007D4
	adds r0, r4, r2
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #8
	bne _08010390
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _08010390
	ldr r0, _08010384 @ =0x0002D034
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0801034A
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xde
	movs r1, #0
	bl loadBlink
	movs r0, #0xdf
	movs r1, #0
	bl loadBlink
	movs r0, #0xe0
	movs r1, #0
	bl loadBlink
	movs r0, #0xe1
	movs r1, #0
	bl loadBlink
	movs r0, #0xe2
	movs r1, #0
	bl loadBlink
_0801034A:
	movs r0, #0xde
	bl FUN_08004068
	movs r0, #0xdf
	bl FUN_08004068
	movs r0, #0xe0
	bl FUN_08004068
	movs r0, #0xe1
	bl FUN_08004068
	movs r0, #0xe2
	bl FUN_08004068
	ldr r2, _0801038C @ =0x0002D035
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xbe
	bne _080103C4
	movs r0, #0
	strb r0, [r1]
	b _080103C4
	.align 2, 0
_08010380: .4byte 0x02002200
_08010384: .4byte 0x0002D034
_08010388: .4byte 0x000007D4
_0801038C: .4byte 0x0002D035
_08010390:
	ldr r0, _0801040C @ =0x02002200
	ldr r1, _08010410 @ =0x0002D034
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080103C4
	movs r0, #4
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xde
	bl clearBlink
	movs r0, #0xdf
	bl clearBlink
	movs r0, #0xe0
	bl clearBlink
	movs r0, #0xe1
	bl clearBlink
	movs r0, #0xe2
	bl clearBlink
_080103C4:
	ldr r1, _0801040C @ =0x02002200
	ldr r2, _08010414 @ =0x000007D6
	adds r0, r1, r2
	ldrh r3, [r0]
	lsrs r2, r3, #8
	cmp r2, #8
	bne _08010418
	movs r0, #0xff
	ands r0, r3
	cmp r0, #3
	bne _08010418
	ldr r0, _08010410 @ =0x0002D034
	adds r1, r1, r0
	ldrb r3, [r1]
	ands r2, r3
	cmp r2, #0
	bne _080103FC
	movs r0, #8
	orrs r0, r3
	strb r0, [r1]
	movs r0, #0xe3
	movs r1, #0
	bl loadBlink
	movs r0, #0xe4
	movs r1, #0
	bl loadBlink
_080103FC:
	movs r0, #0xe3
	bl FUN_08004068
	movs r0, #0xe4
	bl FUN_08004068
	b _08010438
	.align 2, 0
_0801040C: .4byte 0x02002200
_08010410: .4byte 0x0002D034
_08010414: .4byte 0x000007D6
_08010418:
	ldr r2, _08010440 @ =0x0002D034
	adds r1, r1, r2
	ldrb r2, [r1]
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08010438
	movs r0, #8
	eors r0, r2
	strb r0, [r1]
	movs r0, #0xe3
	bl clearBlink
	movs r0, #0xe4
	bl clearBlink
_08010438:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010440: .4byte 0x0002D034

	thumb_func_start FUN_08010444
FUN_08010444: @ 0x08010444
	push {r4, r5, r6, lr}
	ldr r2, _080104BC @ =0x02002200
	ldr r1, _080104C0 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #8
	bne _080104B6
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _080104B6
	movs r4, #0
	ldr r1, _080104C4 @ =0x0002D035
	adds r0, r2, r1
	ldr r1, _080104C8 @ =0x08340128
	ldrb r0, [r0]
	ldrb r2, [r1]
	cmp r0, r2
	bls _08010480
	adds r3, r1, #0
	adds r2, r0, #0
_08010470:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r4, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	bhi _08010470
_08010480:
	ldr r6, _080104CC @ =0x087044F8
	lsls r4, r4, #1
	adds r0, r1, #1
	adds r4, r4, r0
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _080104D0 @ =0x08705150
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_080104B6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080104BC: .4byte 0x02002200
_080104C0: .4byte 0x000007D4
_080104C4: .4byte 0x0002D035
_080104C8: .4byte 0x08340128
_080104CC: .4byte 0x087044F8
_080104D0: .4byte 0x08705150

	thumb_func_start FUN_080104d4
FUN_080104d4: @ 0x080104D4
	push {lr}
	ldr r0, _08010560 @ =0x02002200
	ldr r1, _08010564 @ =0x0002D028
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _08010518
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
	ldr r1, _08010568 @ =0x0836FB24
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_08010518:
	movs r0, #0xda
	bl clearBlink
	movs r0, #0xdb
	bl clearBlink
	movs r0, #0xdc
	bl clearBlink
	movs r0, #0xdd
	bl clearBlink
	movs r0, #0xde
	bl clearBlink
	movs r0, #0xdf
	bl clearBlink
	movs r0, #0xe0
	bl clearBlink
	movs r0, #0xe1
	bl clearBlink
	movs r0, #0xe2
	bl clearBlink
	movs r0, #0xe3
	bl clearBlink
	movs r0, #0xe4
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0
_08010560: .4byte 0x02002200
_08010564: .4byte 0x0002D028
_08010568: .4byte 0x0836FB24

	thumb_func_start FUN_0801056c
FUN_0801056c: @ 0x0801056C
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	cmp r2, #0
	bne _08010588
	movs r0, #0xc0
	str r0, [r1, #0x44]
	str r0, [r1, #0x48]
	ldr r0, _0801058C @ =0x0000074C
	str r0, [r1, #0x4c]
	movs r0, #0x58
	str r0, [r1, #0x50]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_08010588:
	pop {r0}
	bx r0
	.align 2, 0
_0801058C: .4byte 0x0000074C

	thumb_func_start FUN_08010590
FUN_08010590: @ 0x08010590
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	cmp r2, #0
	bne _080105A6
	ldr r0, _080105AC @ =0x00000E98
	str r0, [r1, #0x4c]
	movs r0, #0xa0
	str r0, [r1, #0x50]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_080105A6:
	pop {r0}
	bx r0
	.align 2, 0
_080105AC: .4byte 0x00000E98

	thumb_func_start FUN_080105b0
FUN_080105b0: @ 0x080105B0
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _080105D8
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _080105DC @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080105E0 @ =0x0000FFFC
	ands r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_080105D8:
	pop {r0}
	bx r0
	.align 2, 0
_080105DC: .4byte 0x02002144
_080105E0: .4byte 0x0000FFFC

	thumb_func_start FUN_080105e4
FUN_080105e4: @ 0x080105E4
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x14
	ldr r3, [r4, #0x34]
	ldr r2, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	subs r1, r3, r1
	adds r1, #0xf
	ldr r0, [r4, #0x40]
	subs r0, r2, r0
	adds r5, r0, #0
	adds r5, #0xf
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r0, [r4, #0x2c]
	asrs r0, r0, #8
	adds r0, r0, r3
	str r0, [sp]
	ldr r0, [r4, #0x30]
	asrs r0, r0, #8
	adds r0, r0, r2
	str r0, [sp, #4]
	cmp r1, #0x1e
	bhi _0801062A
	cmp r5, #0x1e
	bhi _0801062A
	ldr r3, _08010650 @ =0x02002200
	ldr r1, _08010654 @ =0x0002D02C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08010660
_0801062A:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _08010658 @ =0x02002144
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	ldr r3, _0801065C @ =0x020029E0
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08006ae0
	b _08010688
	.align 2, 0
_08010650: .4byte 0x02002200
_08010654: .4byte 0x0002D02C
_08010658: .4byte 0x02002144
_0801065C: .4byte 0x020029E0
_08010660:
	ldr r0, [r4, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _080106AC @ =0x02002144
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08006bb4
_08010688:
	ldr r0, _080106B0 @ =0x02002200
	ldr r1, _080106B4 @ =0x0002D02C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r4, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	ldr r0, _080106B8 @ =0x0200214C
	adds r1, r1, r0
	adds r0, r6, #0
	bl FUN_08006dac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080106AC: .4byte 0x02002144
_080106B0: .4byte 0x02002200
_080106B4: .4byte 0x0002D02C
_080106B8: .4byte 0x0200214C

	thumb_func_start FUN_080106bc
FUN_080106bc: @ 0x080106BC
	push {r4, lr}
	ldr r0, _080106D8 @ =0x02002200
	ldr r1, _080106DC @ =0x0002D030
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, #0
	bne _080106D2
	movs r0, #0
	bl FUN_080cedc0
	str r0, [r4]
_080106D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080106D8: .4byte 0x02002200
_080106DC: .4byte 0x0002D030

	thumb_func_start FUN_080106e0
FUN_080106e0: @ 0x080106E0
	push {r4, lr}
	ldr r0, _0801072C @ =0x02002200
	ldr r1, _08010730 @ =0x0002D030
	adds r4, r0, r1
	ldr r3, [r4]
	cmp r3, #0
	beq _08010726
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
	ldr r1, _08010734 @ =0x0836FB24
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	str r2, [r4]
_08010726:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801072C: .4byte 0x02002200
_08010730: .4byte 0x0002D030
_08010734: .4byte 0x0836FB24

	thumb_func_start anatre_08010738
anatre_08010738: @ 0x08010738
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r6, r0, #0x10
	lsrs r0, r6, #0x10
	str r0, [sp, #0x1c]
	movs r1, #0
	mov sb, r1
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	bne _08010842
	lsrs r6, r6, #0x14
	lsls r6, r6, #1
	ldr r0, _080108BC @ =0x02002144
	adds r6, r6, r0
	ldr r1, [r7, #0x64]
	ldr r2, _080108C0 @ =0x00004046
	adds r0, r2, #0
	orrs r1, r0
	strh r1, [r6]
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	mov r3, sb
	str r3, [sp, #0x14]
	add r0, sp, #0x14
	ldr r2, _080108C4 @ =0x01000400
	bl CpuFastSet
	ldr r0, [sp, #0x1c]
	lsls r5, r0, #0x18
	lsrs r5, r5, #0x18
	ldr r1, _080108C8 @ =0x085222A0
	mov r8, r1
	mov r2, sb
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x6a
	movs r3, #0
	bl loadBGMapIntoVram
	mov r3, sb
	str r3, [sp]
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0x6b
	movs r3, #0x10
	bl loadBGMapIntoVram
	ldrh r0, [r6]
	ands r4, r0
	lsls r4, r4, #3
	ldr r5, _080108CC @ =0x06000800
	adds r4, r4, r5
	mov r0, sb
	str r0, [sp]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0x6c
	movs r3, #0
	bl loadBgMap_08004248
	ldr r2, _080108D0 @ =0x02002190
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xff
	strb r0, [r2, #0xd]
	ldrb r1, [r2, #0xe]
	movs r0, #6
	orrs r0, r1
	movs r1, #0xf7
	ands r0, r1
	strb r0, [r2, #0xe]
	movs r3, #0
	ldr r5, _080108D4 @ =0x0202F228
	movs r4, #0
_080107EA:
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
	movs r1, #3
	ands r1, r2
	asrs r0, r0, #0x12
	adds r0, #4
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r1, r5
	strb r4, [r1]
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r5
	str r4, [r0]
	adds r0, r2, #0
	adds r0, #0x15
	lsls r0, r0, #2
	adds r0, r0, r5
	str r4, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #9
	ble _080107EA
	movs r3, #0
	ldr r4, _080108D4 @ =0x0202F228
	movs r2, #0
_08010822:
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x11
	lsls r0, r0, #2
	adds r0, r0, r4
	str r2, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08010822
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08010842:
	ldr r0, [r7, #0x34]
	lsls r0, r0, #8
	ldr r1, [r7, #0x2c]
	adds r0, r0, r1
	mov sl, r0
	ldr r0, [r7, #0x38]
	lsls r0, r0, #8
	ldr r1, [r7, #0x30]
	adds r0, r0, r1
	str r0, [sp, #0x20]
	movs r3, #0
	ldr r5, [sp, #0x1c]
	lsls r5, r5, #8
	str r5, [sp, #0x28]
	ldr r0, _080108D4 @ =0x0202F228
	mov r8, r0
_08010862:
	lsls r2, r3, #0x10
	asrs r3, r2, #0x10
	movs r1, #3
	ands r1, r3
	asrs r0, r2, #0x12
	adds r0, #4
	lsls r0, r0, #2
	adds r1, r1, r0
	add r1, r8
	ldrb r0, [r1]
	adds r7, r2, #0
	cmp r0, #0
	beq _080108E0
	adds r0, r3, #7
	lsls r0, r0, #2
	mov r1, r8
	adds r4, r0, r1
	ldr r0, [r4]
	ldr r5, _080108D8 @ =0x00003FFF
	cmp r0, r5
	bgt _08010914
	ldr r6, _080108DC @ =0x0202FF80
	movs r0, #1
	adds r1, r6, #0
	bl shake_0801ab60
	ldr r0, [r4]
	adds r0, #0x80
	str r0, [r4]
	movs r2, #1
	mov sb, r2
	cmp r0, r5
	ble _08010914
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r4]
	movs r0, #3
	adds r1, r6, #0
	bl shake_0801ab60
	movs r0, #0xe2
	bl playSound
	b _08010914
	.align 2, 0
_080108BC: .4byte 0x02002144
_080108C0: .4byte 0x00004046
_080108C4: .4byte 0x01000400
_080108C8: .4byte 0x085222A0
_080108CC: .4byte 0x06000800
_080108D0: .4byte 0x02002190
_080108D4: .4byte 0x0202F228
_080108D8: .4byte 0x00003FFF
_080108DC: .4byte 0x0202FF80
_080108E0:
	adds r0, r3, #7
	lsls r0, r0, #2
	mov r3, r8
	adds r4, r0, r3
	ldr r0, [r4]
	cmp r0, #0
	beq _08010914
	ldr r5, _08010944 @ =0x0202FF80
	movs r0, #1
	adds r1, r5, #0
	bl shake_0801ab60
	ldr r0, [r4]
	subs r0, #0x40
	str r0, [r4]
	movs r1, #1
	mov sb, r1
	cmp r0, #0
	bne _08010914
	movs r0, #3
	adds r1, r5, #0
	bl shake_0801ab60
	movs r0, #0xe2
	bl playSound
_08010914:
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r7, r2
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08010862
	mov r3, sb
	cmp r3, #0
	beq _0801094C
	ldr r4, _08010948 @ =0x0000010D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _0801093A
	adds r0, r4, #0
	bl playSound
_0801093A:
	adds r0, r4, #0
	bl sound_0800465c
	b _0801095E
	.align 2, 0
_08010944: .4byte 0x0202FF80
_08010948: .4byte 0x0000010D
_0801094C:
	ldr r4, _080109C8 @ =0x0000010D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _0801095E
	adds r0, r4, #0
	bl stopSound
_0801095E:
	movs r5, #0
	mov r8, r5
	ldr r0, _080109CC @ =0x08340134
	mov ip, r0
	ldr r7, _080109D0 @ =0x0202F228
	movs r1, #0xf0
	lsls r1, r1, #8
	add r1, sl
	str r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r2, r2, r3
	mov sb, r2
_0801097A:
	mov r5, r8
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	lsls r1, r2, #4
	mov r3, ip
	adds r0, r1, r3
	ldr r6, [r0]
	str r6, [sp, #4]
	mov r0, ip
	adds r0, #4
	adds r0, r1, r0
	ldr r4, [r0]
	str r4, [sp, #8]
	mov r0, ip
	adds r0, #8
	adds r0, r1, r0
	ldr r5, [r0]
	str r5, [sp, #0xc]
	ldr r0, _080109D4 @ =0x08340140
	adds r1, r1, r0
	ldr r3, [r1]
	str r3, [sp, #0x10]
	lsls r0, r2, #1
	ldr r1, _080109D8 @ =0x083401D5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080109DC
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	subs r1, r4, r1
	str r1, [sp, #8]
	ldr r0, [r0]
	subs r0, r3, r0
	str r0, [sp, #0x10]
	b _08010A20
	.align 2, 0
_080109C8: .4byte 0x0000010D
_080109CC: .4byte 0x08340134
_080109D0: .4byte 0x0202F228
_080109D4: .4byte 0x08340140
_080109D8: .4byte 0x083401D5
_080109DC:
	cmp r0, #1
	bne _080109F4
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r1, r4, r1
	str r1, [sp, #8]
	ldr r0, [r0]
	adds r0, r3, r0
	str r0, [sp, #0x10]
	b _08010A20
_080109F4:
	cmp r0, #2
	bne _08010A0A
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	subs r1, r6, r1
	str r1, [sp, #4]
	ldr r0, [r0]
	subs r0, r5, r0
	b _08010A1E
_08010A0A:
	cmp r0, #3
	bne _08010A20
	adds r0, r2, #7
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r1, r6, r1
	str r1, [sp, #4]
	ldr r0, [r0]
	adds r0, r5, r0
_08010A1E:
	str r0, [sp, #0xc]
_08010A20:
	ldr r6, [sp, #4]
	ldr r2, [sp, #0x24]
	cmp r2, r6
	ble _08010A3C
	ldr r0, [sp, #0xc]
	cmp sl, r0
	bge _08010A3C
	ldr r0, [sp, #8]
	cmp sb, r0
	ble _08010A3C
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x20]
	cmp r3, r0
	blt _08010A50
_08010A3C:
	mov r5, r8
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	mov r8, r2
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0801097A
_08010A50:
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r5, r0, #0x10
	adds r7, r0, #0
	cmp r5, #0xa
	bne _08010A6C
	ldr r1, _08010A68 @ =0x02002140
	ldrh r0, [r1]
	ldr r5, [sp, #0x28]
	bics r0, r5
	strh r0, [r1]
	b _08010B50
	.align 2, 0
_08010A68: .4byte 0x02002140
_08010A6C:
	ldr r0, [sp, #0x1c]
	lsrs r3, r0, #4
	lsls r3, r3, #2
	ldr r2, _08010AC4 @ =0x0200214C
	adds r4, r3, r2
	mov r0, sl
	subs r1, r0, r6
	asrs r1, r1, #8
	lsls r0, r5, #1
	ldr r5, _08010AC8 @ =0x083401D4
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #7
	adds r1, r1, r0
	strh r1, [r4]
	adds r2, #2
	adds r3, r3, r2
	ldr r1, [sp, #8]
	ldr r2, [sp, #0x20]
	subs r0, r2, r1
	asrs r0, r0, #8
	strh r0, [r3]
	mov r3, sl
	subs r2, r6, r3
	lsls r2, r2, #8
	ldr r5, [sp, #0x20]
	subs r1, r1, r5
	lsls r1, r1, #8
	lsrs r5, r1, #0x10
	ldr r0, [sp, #0xc]
	subs r0, r0, r3
	lsls r0, r0, #8
	lsrs r1, r0, #0x10
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x20]
	subs r0, r0, r3
	lsls r0, r0, #8
	lsrs r4, r0, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _08010ACC
	movs r6, #0
	b _08010AD2
	.align 2, 0
_08010AC4: .4byte 0x0200214C
_08010AC8: .4byte 0x083401D4
_08010ACC:
	cmp r2, #0xef
	ble _08010AD2
	movs r6, #0xef
_08010AD2:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08010ADE
	movs r5, #0
	b _08010AE4
_08010ADE:
	cmp r0, #0x9f
	ble _08010AE4
	movs r5, #0x9f
_08010AE4:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08010AF0
	movs r1, #1
	b _08010AF6
_08010AF0:
	cmp r0, #0xf0
	ble _08010AF6
	movs r1, #0xf0
_08010AF6:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08010B02
	movs r4, #1
	b _08010B08
_08010B02:
	cmp r0, #0xa0
	ble _08010B08
	movs r4, #0xa0
_08010B08:
	ldr r3, _08010BC0 @ =0x02002190
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0xff
	ands r1, r2
	lsls r0, r6, #0x10
	asrs r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #6]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ands r0, r2
	lsls r1, r5, #0x10
	asrs r1, r1, #8
	orrs r0, r1
	strh r0, [r3, #0xa]
	movs r5, #0x80
	lsls r5, r5, #0x18
	adds r0, r7, r5
	lsrs r0, r0, #0x10
	ldr r1, _08010BC4 @ =0x00002001
	asrs r2, r7, #0xf
	ldr r3, _08010BC8 @ =0x083401D4
	adds r2, r2, r3
	ldrb r3, [r2]
	lsls r3, r3, #3
	ldr r2, _08010BCC @ =0x083401E8
	adds r3, r3, r2
	add r2, sp, #4
	bl appendBlocking
	ldr r1, _08010BD0 @ =0x02002140
	ldrh r0, [r1]
	ldr r5, [sp, #0x28]
	orrs r5, r0
	strh r5, [r1]
_08010B50:
	movs r3, #0
	ldr r6, _08010BD4 @ =0x0202F228
_08010B54:
	lsls r0, r3, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x11
	lsls r0, r0, #2
	adds r5, r0, r6
	ldr r0, [r5]
	cmp r0, #0
	bne _08010B72
	lsls r0, r4, #3
	ldr r1, _08010BD8 @ =0x08340200
	adds r0, r0, r1
	bl FUN_080deb10
	str r0, [r5]
_08010B72:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08010B54
	movs r3, #0
	ldr r6, _08010BD4 @ =0x0202F228
_08010B82:
	lsls r0, r3, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x15
	lsls r0, r0, #2
	adds r5, r0, r6
	ldr r0, [r5]
	cmp r0, #0
	bne _08010BA4
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r4, #3
	ldr r2, _08010BDC @ =0x08340220
	adds r1, r1, r2
	bl FUN_080deb6c
	str r0, [r5]
_08010BA4:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08010B82
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010BC0: .4byte 0x02002190
_08010BC4: .4byte 0x00002001
_08010BC8: .4byte 0x083401D4
_08010BCC: .4byte 0x083401E8
_08010BD0: .4byte 0x02002140
_08010BD4: .4byte 0x0202F228
_08010BD8: .4byte 0x08340200
_08010BDC: .4byte 0x08340220

	thumb_func_start FUN_08010be0
FUN_08010be0: @ 0x08010BE0
	push {r4, r5, r6, lr}
	ldr r1, _08010CBC @ =0x02002190
	ldrh r2, [r1]
	ldr r0, _08010CC0 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	movs r1, #0
	ldr r6, _08010CC4 @ =0x0202F228
	movs r4, #0
	ldr r5, _08010CC8 @ =0x0836FB24
_08010BFC:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r0, r3, #0
	adds r0, #0x11
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	cmp r2, #0
	beq _08010C40
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08010C40:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08010BFC
	movs r1, #0
	ldr r6, _08010CC4 @ =0x0202F228
	movs r4, #0
	ldr r5, _08010CC8 @ =0x0836FB24
_08010C54:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r0, r3, #0
	adds r0, #0x15
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	cmp r2, #0
	beq _08010C98
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08010C98:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08010C54
	ldr r4, _08010CCC @ =0x0000010D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08010CB6
	adds r0, r4, #0
	bl stopSound
_08010CB6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010CBC: .4byte 0x02002190
_08010CC0: .4byte 0x0000BFFF
_08010CC4: .4byte 0x0202F228
_08010CC8: .4byte 0x0836FB24
_08010CCC: .4byte 0x0000010D

	thumb_func_start FUN_08010cd0
FUN_08010cd0: @ 0x08010CD0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _08010D08 @ =0x000EFFFF
	cmp r4, r0
	bgt _08010D18
	ldr r0, _08010D0C @ =0xFFFEC000
	adds r1, r3, r0
	ldr r0, _08010D10 @ =0x00013FFF
	cmp r1, r0
	bhi _08010D18
	ldr r2, _08010D14 @ =0x02002200
	movs r5, #0xfc
	lsls r5, r5, #3
	adds r2, r2, r5
	ldrh r1, [r2]
	movs r5, #0xf0
	lsls r5, r5, #9
	adds r0, r3, r5
	asrs r0, r0, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _08010D1A
	.align 2, 0
_08010D08: .4byte 0x000EFFFF
_08010D0C: .4byte 0xFFFEC000
_08010D10: .4byte 0x00013FFF
_08010D14: .4byte 0x02002200
_08010D18:
	movs r0, #0
_08010D1A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010d20
FUN_08010d20: @ 0x08010D20
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08010D5C @ =0xFFFEC000
	adds r1, r2, r0
	ldr r0, _08010D60 @ =0x00013FFF
	cmp r1, r0
	bhi _08010D54
	ldr r4, _08010D64 @ =0x02002200
	ldr r0, _08010D68 @ =0x0002D02C
	adds r1, r4, r0
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	asrs r0, r3, #0xc
	movs r3, #0xf0
	lsls r3, r3, #9
	adds r1, r2, r3
	asrs r1, r1, #0xc
	ldr r2, _08010D6C @ =0x08340270
	bl patchBlockMap
	movs r0, #0xb0
	lsls r0, r0, #0xa
	adds r4, r4, r0
	strh r5, [r4]
_08010D54:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010D5C: .4byte 0xFFFEC000
_08010D60: .4byte 0x00013FFF
_08010D64: .4byte 0x02002200
_08010D68: .4byte 0x0002D02C
_08010D6C: .4byte 0x08340270

	thumb_func_start FUN_08010d70
FUN_08010d70: @ 0x08010D70
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _08010DC0 @ =0x001A3FFF
	cmp r3, r0
	ble _08010DD0
	ldr r0, _08010DC4 @ =0xFFFF6000
	adds r1, r5, r0
	ldr r0, _08010DC8 @ =0x00013FFF
	cmp r1, r0
	bhi _08010DD0
	ldr r2, _08010DCC @ =0x02002200
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
	movs r6, #0xa0
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
	b _08010DD2
	.align 2, 0
_08010DC0: .4byte 0x001A3FFF
_08010DC4: .4byte 0xFFFF6000
_08010DC8: .4byte 0x00013FFF
_08010DCC: .4byte 0x02002200
_08010DD0:
	movs r0, #0
_08010DD2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010dd8
FUN_08010dd8: @ 0x08010DD8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08010E96
	ldr r0, _08010E18 @ =0x001D0FFF
	cmp r4, r0
	ble _08010E4C
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r5, r0
	ble _08010E1C
	asrs r0, r4, #0xc
	subs r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r4, r1, #1
	asrs r0, r5, #0xc
	adds r0, #2
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r5, r1, #2
	b _08010E3C
	.align 2, 0
_08010E18: .4byte 0x001D0FFF
_08010E1C:
	asrs r0, r4, #0xc
	subs r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r4, r1, #1
	asrs r0, r5, #0xc
	adds r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r5, r1, #1
_08010E3C:
	ldr r2, _08010E48 @ =0x08340278
	adds r0, r4, #0
	adds r1, r5, #0
	bl patchBlockMap
	b _08010E7C
	.align 2, 0
_08010E48: .4byte 0x08340278
_08010E4C:
	ldr r0, _08010E9C @ =0x001B2FFF
	cmp r4, r0
	ble _08010E7C
	asrs r0, r4, #0xc
	subs r0, #2
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r4, r1, #2
	asrs r0, r5, #0xc
	subs r0, #1
	movs r1, #3
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r5, r1, #1
	ldr r2, _08010EA0 @ =0x08340278
	adds r0, r4, #0
	adds r1, r5, #0
	bl patchBlockMap
_08010E7C:
	movs r0, #0x41
	bl isSoundPlaying
	cmp r0, #0
	bne _08010E8C
	movs r0, #0x41
	bl playSound
_08010E8C:
	lsls r1, r4, #0xc
	lsls r2, r5, #0xc
	movs r0, #0
	bl FUN_080cee14
_08010E96:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010E9C: .4byte 0x001B2FFF
_08010EA0: .4byte 0x08340278
