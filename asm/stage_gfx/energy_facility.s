	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initEFacility
initEFacility: @ 0x08011D5C
	push {r4, lr}
	ldr r1, _08011DC4 @ =0x0202FDC0
	adds r1, #0x54
	ldrb r2, [r1]
	movs r0, #0x40
	movs r3, #0
	orrs r0, r2
	strb r0, [r1]
	ldr r0, _08011DC8 @ =0x02002200
	ldr r2, _08011DCC @ =0x0002D028
	adds r1, r0, r2
	strb r3, [r1]
	ldr r4, _08011DD0 @ =0x0002D034
	adds r1, r0, r4
	strb r3, [r1]
	adds r2, #0xe
	adds r1, r0, r2
	movs r2, #0
	strh r3, [r1]
	adds r4, #1
	adds r1, r0, r4
	strb r2, [r1]
	adds r4, #7
	adds r1, r0, r4
	strh r3, [r1]
	subs r4, #4
	adds r1, r0, r4
	strb r2, [r1]
	adds r4, #1
	adds r1, r0, r4
	strb r2, [r1]
	adds r4, #5
	adds r1, r0, r4
	strh r3, [r1]
	subs r4, #4
	adds r1, r0, r4
	strb r2, [r1]
	adds r4, #1
	adds r1, r0, r4
	strb r2, [r1]
	subs r4, #0x17
	adds r1, r0, r4
	strb r2, [r1]
	ldr r2, _08011DD4 @ =0x0002D02C
	adds r1, r0, r2
	str r3, [r1]
	adds r4, #0xc
	adds r0, r0, r4
	str r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011DC4: .4byte 0x0202FDC0
_08011DC8: .4byte 0x02002200
_08011DCC: .4byte 0x0002D028
_08011DD0: .4byte 0x0002D034
_08011DD4: .4byte 0x0002D02C

	thumb_func_start FUN_08011dd8
FUN_08011dd8: @ 0x08011DD8
	push {r4, r5, lr}
	ldr r2, _08011E14 @ =0x02002200
	ldr r1, _08011E18 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xb
	bne _08011E20
	movs r0, #0xff
	ands r0, r1
	cmp r0, #3
	bne _08011E20
	ldr r0, _08011E1C @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08011E0C
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xc4
	movs r1, #0
	bl loadBlink
_08011E0C:
	movs r0, #0xc4
	bl FUN_08004068
	b _08011E3C
	.align 2, 0
_08011E14: .4byte 0x02002200
_08011E18: .4byte 0x000007D6
_08011E1C: .4byte 0x0002D028
_08011E20:
	ldr r0, _08011E8C @ =0x02002200
	ldr r1, _08011E90 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08011E3C
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xc4
	bl clearBlink
_08011E3C:
	ldr r4, _08011E8C @ =0x02002200
	ldr r2, _08011E94 @ =0x000007D6
	adds r0, r4, r2
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xb
	bne _08011E9C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _08011E9C
	ldr r0, _08011E90 @ =0x0002D028
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08011E6E
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xc5
	movs r1, #0
	bl loadBlink
_08011E6E:
	movs r0, #0xc5
	bl FUN_08004068
	ldr r2, _08011E98 @ =0x0002D034
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1b
	bne _08011EB8
	movs r0, #0
	strb r0, [r1]
	b _08011EB8
	.align 2, 0
_08011E8C: .4byte 0x02002200
_08011E90: .4byte 0x0002D028
_08011E94: .4byte 0x000007D6
_08011E98: .4byte 0x0002D034
_08011E9C:
	ldr r0, _08011F68 @ =0x02002200
	ldr r1, _08011F6C @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08011EB8
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0xc5
	bl clearBlink
_08011EB8:
	ldr r0, _08011F68 @ =0x02002200
	ldr r2, _08011F70 @ =0x000007D6
	adds r1, r0, r2
	ldrh r2, [r1]
	lsrs r1, r2, #8
	adds r5, r0, #0
	cmp r1, #0xb
	beq _08011ECA
	b _0801207C
_08011ECA:
	movs r0, #0xff
	ands r0, r2
	cmp r0, #4
	beq _08011ED4
	b _0801207C
_08011ED4:
	ldr r1, _08011F6C @ =0x0002D028
	adds r2, r5, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08011EE6
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
_08011EE6:
	ldr r2, _08011F74 @ =0x0202FDC0
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08011F0C
	ldr r0, _08011F78 @ =0x0002D039
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x18
	bne _08011F0C
	movs r0, #0
	strb r0, [r1]
_08011F0C:
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08011F30
	ldr r2, _08011F7C @ =0x0002D038
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bne _08011F30
	movs r0, #0
	strb r0, [r1]
_08011F30:
	ldr r0, _08011F74 @ =0x0202FDC0
	adds r0, #0x54
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08011F96
	ldr r0, _08011F68 @ =0x02002200
	ldr r1, _08011F80 @ =0x0002D036
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	movs r1, #0x90
	lsls r1, r1, #0x12
	cmp r0, r1
	bne _08011F58
	movs r0, #0
	strh r0, [r2]
_08011F58:
	ldrh r0, [r2]
	cmp r0, #0
	bne _08011F84
	movs r0, #0xc0
	bl clearBlink
	b _08011F90
	.align 2, 0
_08011F68: .4byte 0x02002200
_08011F6C: .4byte 0x0002D028
_08011F70: .4byte 0x000007D6
_08011F74: .4byte 0x0202FDC0
_08011F78: .4byte 0x0002D039
_08011F7C: .4byte 0x0002D038
_08011F80: .4byte 0x0002D036
_08011F84:
	cmp r0, #0xc6
	bne _08011F90
	movs r0, #0xc0
	movs r1, #0
	bl loadBlink
_08011F90:
	movs r0, #0xc0
	bl FUN_08004068
_08011F96:
	ldr r2, _08012058 @ =0x0202FDC0
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	ldr r5, _0801205C @ =0x02002200
	cmp r0, #0
	beq _08011FD2
	ldr r0, _08012060 @ =0x0002D03A
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _08011FB6
	adds r0, #1
	strb r0, [r1]
_08011FB6:
	ldr r0, _08012064 @ =0x0002D03C
	adds r4, r5, r0
	ldrb r1, [r1]
	ldrh r0, [r4]
	adds r3, r0, r1
	strh r3, [r4]
	lsls r1, r3, #0x10
	movs r0, #0xc0
	lsls r0, r0, #0x12
	cmp r1, r0
	bls _08011FD2
	ldr r1, _08012068 @ =0xFFFFFD00
	adds r0, r3, r1
	strh r0, [r4]
_08011FD2:
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801200A
	ldr r0, _0801206C @ =0x0002D03B
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _08011FEE
	adds r0, #1
	strb r0, [r1]
_08011FEE:
	ldr r0, _08012070 @ =0x0002D03E
	adds r4, r5, r0
	ldrb r1, [r1]
	ldrh r0, [r4]
	adds r3, r0, r1
	strh r3, [r4]
	lsls r1, r3, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x12
	cmp r1, r0
	bls _0801200A
	ldr r1, _08012074 @ =0xFFFFFE80
	adds r0, r3, r1
	strh r0, [r4]
_0801200A:
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080120B4
	ldr r0, _0801205C @ =0x02002200
	ldr r2, _08012078 @ =0x0002D035
	adds r4, r0, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801202C
	movs r0, #0xc1
	movs r1, #0
	bl loadBlink
_0801202C:
	ldrb r0, [r4]
	cmp r0, #0x5a
	bhi _0801204A
	cmp r0, #0x5a
	bne _08012044
	movs r0, #0xc1
	bl clearBlink
	movs r0, #0xc2
	movs r1, #0
	bl loadBlink
_08012044:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801204A:
	movs r0, #0xc1
	bl FUN_08004068
	movs r0, #0xc2
	bl FUN_08004068
	b _080120B4
	.align 2, 0
_08012058: .4byte 0x0202FDC0
_0801205C: .4byte 0x02002200
_08012060: .4byte 0x0002D03A
_08012064: .4byte 0x0002D03C
_08012068: .4byte 0xFFFFFD00
_0801206C: .4byte 0x0002D03B
_08012070: .4byte 0x0002D03E
_08012074: .4byte 0xFFFFFE80
_08012078: .4byte 0x0002D035
_0801207C:
	ldr r5, _080120E8 @ =0x02002200
	ldr r0, _080120EC @ =0x0002D028
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080120B4
	movs r0, #4
	eors r0, r1
	movs r4, #0
	strb r0, [r2]
	movs r0, #0xc0
	bl clearBlink
	movs r0, #0xc1
	bl clearBlink
	movs r0, #0xc2
	bl clearBlink
	ldr r1, _080120F0 @ =0x0002D036
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	ldr r2, _080120F4 @ =0x0002D035
	adds r0, r5, r2
	strb r1, [r0]
_080120B4:
	ldr r4, _080120E8 @ =0x02002200
	ldr r1, _080120F8 @ =0x0002D024
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0801210C
	ldr r0, _080120FC @ =0x0002D02C
	adds r2, r4, r0
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	ldr r1, _08012100 @ =0x000CE200
	cmp r0, r1
	bne _080120D2
	str r3, [r2]
_080120D2:
	ldr r2, _08012104 @ =0x0002D030
	adds r1, r4, r2
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bge _08012132
	ldr r0, _08012108 @ =0x000CE1FF
	str r0, [r1]
	b _08012132
	.align 2, 0
_080120E8: .4byte 0x02002200
_080120EC: .4byte 0x0002D028
_080120F0: .4byte 0x0002D036
_080120F4: .4byte 0x0002D035
_080120F8: .4byte 0x0002D024
_080120FC: .4byte 0x0002D02C
_08012100: .4byte 0x000CE200
_08012104: .4byte 0x0002D030
_08012108: .4byte 0x000CE1FF
_0801210C:
	ldr r0, _08012138 @ =0x0002D02C
	adds r1, r4, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bge _0801211E
	ldr r0, _0801213C @ =0x000CE1FF
	str r0, [r1]
_0801211E:
	ldr r1, _08012140 @ =0x0002D030
	adds r2, r4, r1
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	ldr r1, _08012144 @ =0x000CE200
	cmp r0, r1
	bne _08012132
	movs r0, #0
	str r0, [r2]
_08012132:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08012138: .4byte 0x0002D02C
_0801213C: .4byte 0x000CE1FF
_08012140: .4byte 0x0002D030
_08012144: .4byte 0x000CE200

	thumb_func_start FUN_08012148
FUN_08012148: @ 0x08012148
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, _08012298 @ =0x02002200
	ldr r1, _0801229C @ =0x000007D6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xb
	bne _080121B0
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _080121B0
	ldr r6, _080122A0 @ =0x087044F8
	ldr r2, _080122A4 @ =0x0002D034
	adds r5, r5, r2
	ldrb r0, [r5]
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _080122A8 @ =0x08704CA0
	adds r1, r1, r4
	ldr r0, [r6]
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
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_080121B0:
	ldr r3, _08012298 @ =0x02002200
	mov sb, r3
	ldr r0, _0801229C @ =0x000007D6
	add r0, sb
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xb
	beq _080121C2
	b _080124AE
_080121C2:
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	beq _080121CC
	b _080124AE
_080121CC:
	ldr r0, _080122AC @ =0x0202FDC0
	adds r7, r0, #0
	adds r7, #0x54
	ldrb r1, [r7]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08012224
	ldr r6, _080122A0 @ =0x087044F8
	ldr r5, _080122B0 @ =0x0002D039
	add r5, sb
	ldrb r0, [r5]
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _080122B4 @ =0x08704E08
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrb r0, [r5]
	movs r1, #3
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
_08012224:
	ldrb r1, [r7]
	movs r0, #2
	mov sl, r0
	ands r0, r1
	cmp r0, #0
	bne _08012232
	b _0801239C
_08012232:
	ldr r6, _080122A0 @ =0x087044F8
	ldr r5, _080122B8 @ =0x0002D038
	add r5, sb
	ldrb r0, [r5]
	lsrs r0, r0, #3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _080122BC @ =0x08704DB8
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
	ldrb r1, [r7]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	bne _08012278
	b _0801239C
_08012278:
	ldr r7, _080122C0 @ =0x0002D036
	add r7, sb
	ldrh r1, [r7]
	cmp r1, #0xb3
	bhi _080122CC
	ldr r0, [r6]
	ldr r2, _080122C4 @ =0x08704C3C
	adds r0, r0, r2
	mov r1, r8
	bl appendGraphicTask
	ldr r0, [r6]
	ldr r3, _080122C8 @ =0x08704C48
	adds r0, r0, r3
	b _08012372
	.align 2, 0
_08012298: .4byte 0x02002200
_0801229C: .4byte 0x000007D6
_080122A0: .4byte 0x087044F8
_080122A4: .4byte 0x0002D034
_080122A8: .4byte 0x08704CA0
_080122AC: .4byte 0x0202FDC0
_080122B0: .4byte 0x0002D039
_080122B4: .4byte 0x08704E08
_080122B8: .4byte 0x0002D038
_080122BC: .4byte 0x08704DB8
_080122C0: .4byte 0x0002D036
_080122C4: .4byte 0x08704C3C
_080122C8: .4byte 0x08704C48
_080122CC:
	cmp r1, #0xc5
	bhi _08012308
	ldrh r0, [r7]
	subs r0, #0xb4
	movs r1, #6
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08012304 @ =0x08704C50
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldrh r0, [r7]
	subs r0, #0xb4
	movs r1, #6
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	b _0801236C
	.align 2, 0
_08012304: .4byte 0x08704C50
_08012308:
	ldr r0, _08012324 @ =0x00000179
	cmp r1, r0
	bhi _08012330
	ldr r0, [r6]
	ldr r1, _08012328 @ =0x08704C8C
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldr r0, [r6]
	ldr r2, _0801232C @ =0x08704C98
	adds r0, r0, r2
	b _08012372
	.align 2, 0
_08012324: .4byte 0x00000179
_08012328: .4byte 0x08704C8C
_0801232C: .4byte 0x08704C98
_08012330:
	ldr r0, _0801237C @ =0x0000018B
	cmp r1, r0
	bhi _08012384
	ldrh r0, [r7]
	ldr r5, _08012380 @ =0xFFFFFE86
	adds r0, r0, r5
	movs r1, #6
	bl __divsi3
	movs r4, #0x60
	subs r0, r4, r0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r0, [r6]
	adds r0, r0, r1
	mov r1, r8
	bl appendGraphicTask
	ldrh r0, [r7]
	adds r0, r0, r5
	movs r1, #6
	bl __divsi3
	subs r4, r4, r0
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r6
_0801236C:
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
_08012372:
	movs r1, #0
	bl transferPalette
	b _0801239C
	.align 2, 0
_0801237C: .4byte 0x0000018B
_08012380: .4byte 0xFFFFFE86
_08012384:
	ldr r0, [r6]
	ldr r3, _080124BC @ =0x08704C3C
	adds r0, r0, r3
	mov r1, r8
	bl appendGraphicTask
	ldr r0, [r6]
	ldr r1, _080124C0 @ =0x08704C48
	adds r0, r0, r1
	movs r1, #0
	bl transferPalette
_0801239C:
	ldr r0, _080124C4 @ =0x0202FDC0
	adds r7, r0, #0
	adds r7, #0x54
	ldrb r1, [r7]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08012402
	ldr r2, _080124C8 @ =0x087044F8
	mov r8, r2
	ldr r4, _080124CC @ =0x02002200
	ldr r3, _080124D0 @ =0x0002D03C
	adds r4, r4, r3
	ldrh r0, [r4]
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x16
	movs r6, #1
	ands r0, r6
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _080124D4 @ =0x08704D90
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r4]
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x16
	ands r0, r6
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_08012402:
	ldrb r1, [r7]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08012452
	ldr r0, _080124C8 @ =0x087044F8
	mov r8, r0
	ldr r4, _080124CC @ =0x02002200
	ldr r1, _080124D8 @ =0x0002D03E
	adds r4, r4, r1
	ldrh r0, [r4]
	lsrs r0, r0, #7
	movs r6, #3
	ands r0, r6
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _080124DC @ =0x08704EA8
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r4]
	lsrs r0, r0, #7
	ands r0, r6
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_08012452:
	ldrb r1, [r7]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080124AE
	movs r1, #0
	ldr r0, _080124CC @ =0x02002200
	ldr r2, _080124E0 @ =0x0002D035
	adds r0, r0, r2
	ldr r2, _080124E4 @ =0x0834283C
	ldrb r0, [r0]
	ldrb r3, [r2]
	cmp r0, r3
	bls _08012486
	adds r3, r2, #0
	adds r2, r0, #0
_08012472:
	lsls r0, r1, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r1, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	bhi _08012472
_08012486:
	ldr r5, _080124C8 @ =0x087044F8
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r2, _080124E8 @ =0x08704CDC
	adds r4, r4, r2
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
_080124AE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080124BC: .4byte 0x08704C3C
_080124C0: .4byte 0x08704C48
_080124C4: .4byte 0x0202FDC0
_080124C8: .4byte 0x087044F8
_080124CC: .4byte 0x02002200
_080124D0: .4byte 0x0002D03C
_080124D4: .4byte 0x08704D90
_080124D8: .4byte 0x0002D03E
_080124DC: .4byte 0x08704EA8
_080124E0: .4byte 0x0002D035
_080124E4: .4byte 0x0834283C
_080124E8: .4byte 0x08704CDC

	thumb_func_start FUN_080124ec
FUN_080124ec: @ 0x080124EC
	push {lr}
	movs r0, #0xc0
	bl clearBlink
	movs r0, #0xc1
	bl clearBlink
	movs r0, #0xc2
	bl clearBlink
	movs r0, #0xc4
	bl clearBlink
	movs r0, #0xc5
	bl clearBlink
	movs r0, #0xc6
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08012518
FUN_08012518: @ 0x08012518
	push {lr}
	adds r3, r0, #0
	ldr r1, [r3]
	ldr r0, _08012538 @ =0x000003BF
	cmp r1, r0
	bgt _08012544
	ldr r1, [r3, #4]
	ldr r0, _0801253C @ =0x000001BF
	cmp r1, r0
	ble _080125AA
	ldr r0, _08012540 @ =0x0000025F
	cmp r1, r0
	bgt _08012544
	movs r0, #0
	b _080125B6
	.align 2, 0
_08012538: .4byte 0x000003BF
_0801253C: .4byte 0x000001BF
_08012540: .4byte 0x0000025F
_08012544:
	ldr r0, _08012558 @ =0x0000068F
	ldr r2, [r3]
	cmp r2, r0
	bgt _08012560
	ldr r1, [r3, #4]
	ldr r0, _0801255C @ =0x0000011F
	cmp r1, r0
	ble _08012560
	movs r0, #1
	b _080125B6
	.align 2, 0
_08012558: .4byte 0x0000068F
_0801255C: .4byte 0x0000011F
_08012560:
	ldr r0, _0801256C @ =0x0000095F
	cmp r2, r0
	bgt _08012570
	movs r0, #2
	b _080125B6
	.align 2, 0
_0801256C: .4byte 0x0000095F
_08012570:
	ldr r0, _0801257C @ =0x00000CAF
	cmp r2, r0
	bgt _08012580
	movs r0, #3
	b _080125B6
	.align 2, 0
_0801257C: .4byte 0x00000CAF
_08012580:
	ldr r0, _08012598 @ =0x00000F7F
	cmp r2, r0
	ble _080125AA
	ldr r0, _0801259C @ =0x000013AF
	cmp r2, r0
	bgt _080125A4
	ldr r1, [r3, #4]
	ldr r0, _080125A0 @ =0x0000025F
	cmp r1, r0
	ble _080125A4
	movs r0, #4
	b _080125B6
	.align 2, 0
_08012598: .4byte 0x00000F7F
_0801259C: .4byte 0x000013AF
_080125A0: .4byte 0x0000025F
_080125A4:
	ldr r0, _080125B0 @ =0x0000142F
	cmp r2, r0
	ble _080125B4
_080125AA:
	movs r0, #6
	b _080125B6
	.align 2, 0
_080125B0: .4byte 0x0000142F
_080125B4:
	movs r0, #5
_080125B6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080125bc
FUN_080125bc: @ 0x080125BC
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _080125E8
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _080125F8 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080125FC @ =0x0000FFFC
	ands r1, r2
	movs r2, #3
	orrs r1, r2
	strh r1, [r0]
	movs r0, #0xc0
	str r0, [r3, #0x44]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_080125E8:
	ldr r1, [r3, #0x34]
	ldr r0, _08012600 @ =0x0000086F
	cmp r1, r0
	bgt _08012604
	movs r0, #0xd2
	lsls r0, r0, #1
	b _08012608
	.align 2, 0
_080125F8: .4byte 0x02002144
_080125FC: .4byte 0x0000FFFC
_08012600: .4byte 0x0000086F
_08012604:
	movs r0, #0x96
	lsls r0, r0, #2
_08012608:
	str r0, [r3, #0x4c]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08012610
FUN_08012610: @ 0x08012610
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08012646
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r3, r3, #1
	ldr r1, _08012650 @ =0x02002144
	adds r3, r3, r1
	ldr r1, [r4, #0x64]
	movs r2, #0x47
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _08012654 @ =0x085222A0
	str r5, [sp]
	movs r2, #0x4f
	movs r3, #0
	bl loadBGMapIntoVram
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08012646:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08012650: .4byte 0x02002144
_08012654: .4byte 0x085222A0

	thumb_func_start FUN_08012658
FUN_08012658: @ 0x08012658
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, [r7, #0x5c]
	lsls r1, r1, #0x10
	ldr r0, [r7, #0x34]
	lsls r0, r0, #0xf
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	subs r0, #0xe0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsrs r1, r1, #0x14
	lsls r1, r1, #2
	ldr r0, _080126F8 @ =0x0200214C
	adds r2, r1, r0
	strh r5, [r2]
	adds r0, #2
	adds r1, r1, r0
	strh r4, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	adds r6, r0, #0
	cmp r6, #0
	beq _080126F0
	ldr r2, _080126FC @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r6, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08012700 @ =0x04000018
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08012704 @ =0xA6600001
	str r0, [r1]
	movs r2, #0
	lsls r3, r4, #0x10
	asrs r0, r3, #0x10
	mov ip, r3
	cmp r0, #0x37
	bgt _080126CE
	adds r4, r5, #0
	adds r5, r6, #0
_080126BA:
	asrs r1, r3, #0x10
	adds r0, r3, #0
	orrs r0, r4
	stm r5!, {r0}
	adds r2, #1
	adds r1, r1, r2
	cmp r1, #0x37
	bgt _080126CE
	cmp r2, #0x9f
	ble _080126BA
_080126CE:
	cmp r2, #0x9f
	bgt _080126F0
	mov r4, ip
	ldr r5, _08012708 @ =0x0000FFFF
	lsls r0, r2, #2
	adds r3, r0, r6
_080126DA:
	ldr r1, [r7, #0x34]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	ands r0, r5
	orrs r0, r4
	stm r3!, {r0}
	adds r2, #1
	cmp r2, #0x9f
	ble _080126DA
_080126F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080126F8: .4byte 0x0200214C
_080126FC: .4byte 0x03001590
_08012700: .4byte 0x04000018
_08012704: .4byte 0xA6600001
_08012708: .4byte 0x0000FFFF

	thumb_func_start FUN_0801270c
FUN_0801270c: @ 0x0801270C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0801274E
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r3, r3, #1
	ldr r1, _08012774 @ =0x02002144
	adds r3, r3, r1
	ldr r1, [r4, #0x64]
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _08012778 @ =0x085222A0
	str r5, [sp]
	movs r2, #0x50
	movs r3, #0
	bl loadBGMapIntoVram
	ldr r1, _0801277C @ =0x02002180
	ldr r0, _08012780 @ =0x00003B44
	strh r0, [r1]
	movs r0, #0x40
	strh r0, [r4, #0x10]
	strh r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801274E:
	adds r0, r4, #0
	adds r0, #0x34
	bl FUN_08012518
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _08012784 @ =0x0202FDC0
	adds r0, #0x54
	ldrb r0, [r0]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08012788
	ldrh r0, [r4, #0x10]
	cmp r0, #0x3f
	bhi _08012792
	adds r0, #1
	b _08012790
	.align 2, 0
_08012774: .4byte 0x02002144
_08012778: .4byte 0x085222A0
_0801277C: .4byte 0x02002180
_08012780: .4byte 0x00003B44
_08012784: .4byte 0x0202FDC0
_08012788:
	ldrh r0, [r4, #0x10]
	cmp r0, #0x20
	bls _08012792
	subs r0, #1
_08012790:
	strh r0, [r4, #0x10]
_08012792:
	ldr r1, _080127DC @ =0x02002180
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #2
	lsls r0, r0, #8
	strh r0, [r1, #2]
	ldr r0, _080127E0 @ =0x02002200
	ldr r1, _080127E4 @ =0x000007D6
	adds r0, r0, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xb
	bne _0801280C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _0801280C
	ldr r0, _080127E8 @ =0x0202FDC0
	adds r0, #0x54
	ldrb r0, [r0]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080127EC
	ldrh r2, [r4, #0x12]
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08012820
	movs r0, #1
	orrs r0, r2
	strh r0, [r4, #0x12]
	movs r0, #0xf3
	bl clearBlink
	movs r0, #0xbf
	b _08012804
	.align 2, 0
_080127DC: .4byte 0x02002180
_080127E0: .4byte 0x02002200
_080127E4: .4byte 0x000007D6
_080127E8: .4byte 0x0202FDC0
_080127EC:
	ldrh r2, [r4, #0x12]
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08012820
	movs r0, #0xfe
	ands r0, r2
	strh r0, [r4, #0x12]
	movs r0, #0xbf
	bl clearBlink
	movs r0, #0xf3
_08012804:
	movs r1, #0
	bl loadBlink
	b _08012820
_0801280C:
	ldrh r1, [r4, #0x12]
	movs r0, #0xfe
	ands r0, r1
	strh r0, [r4, #0x12]
	movs r0, #0xbf
	bl clearBlink
	movs r0, #0xf3
	bl clearBlink
_08012820:
	ldr r0, _08012860 @ =0x02002200
	ldr r1, _08012864 @ =0x000007D4
	adds r0, r0, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xb
	bne _0801286C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	bne _0801286C
	ldr r0, _08012868 @ =0x0202FDC0
	adds r0, #0x54
	ldrb r1, [r0]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801287A
	ldrh r1, [r4, #0x12]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0801287A
	movs r0, #2
	orrs r0, r1
	strh r0, [r4, #0x12]
	movs r0, #0xc3
	movs r1, #0
	bl loadBlink
	b _0801287A
	.align 2, 0
_08012860: .4byte 0x02002200
_08012864: .4byte 0x000007D4
_08012868: .4byte 0x0202FDC0
_0801286C:
	ldrh r1, [r4, #0x12]
	movs r0, #0xfd
	ands r0, r1
	strh r0, [r4, #0x12]
	movs r0, #0xc3
	bl clearBlink
_0801287A:
	movs r0, #0xbf
	bl FUN_08004068
	movs r0, #0xc3
	bl FUN_08004068
	movs r0, #0xf3
	bl FUN_08004068
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08012894
FUN_08012894: @ 0x08012894
	bx lr
	.align 2, 0

	thumb_func_start FUN_08012898
FUN_08012898: @ 0x08012898
	push {lr}
	ldr r1, _080128B8 @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xbf
	bl clearBlink
	movs r0, #0xc3
	bl clearBlink
	movs r0, #0xf3
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0
_080128B8: .4byte 0x02002180

	thumb_func_start FUN_080128bc
FUN_080128bc: @ 0x080128BC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _080128EA
	movs r2, #0
	movs r3, #0
_080128CC:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r6
	str r3, [r0, #0x68]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #5
	ble _080128CC
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0801291C
_080128EA:
	movs r2, #0
_080128EC:
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	lsls r0, r5, #2
	adds r4, r0, r6
	ldr r0, [r4, #0x68]
	cmp r0, #0
	bne _08012910
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r0, [sp]
	movs r0, #0xc5
	lsls r0, r0, #0xd
	movs r1, #0xbc
	lsls r1, r1, #9
	movs r3, #0
	bl FUN_080df530
	str r0, [r4, #0x68]
_08012910:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _080128EC
_0801291C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08012924
FUN_08012924: @ 0x08012924
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	movs r5, #0
	ldr r7, _08012984 @ =0x0836FB24
_0801292E:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #2
	adds r3, r0, r6
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _08012970
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r5, [r3, #0x68]
_08012970:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0801292E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012984: .4byte 0x0836FB24

	thumb_func_start FUN_08012988
FUN_08012988: @ 0x08012988
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _080129B6
	movs r3, #0
	movs r2, #0
_08012998:
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r6
	str r2, [r0, #0x68]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08012998
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080129F2
_080129B6:
	movs r3, #0
	movs r7, #1
_080129BA:
	lsls r2, r3, #0x10
	asrs r4, r2, #0x10
	lsls r0, r4, #2
	adds r5, r0, r6
	ldr r0, [r5, #0x68]
	cmp r0, #0
	bne _080129E6
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r1, #0x13
	lsls r1, r1, #4
	adds r1, #8
	lsls r1, r1, #8
	asrs r2, r2, #0x11
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ands r3, r7
	str r7, [sp]
	ldr r0, _080129FC @ =0x00272000
	bl FUN_080df530
	str r0, [r5, #0x68]
_080129E6:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080129BA
_080129F2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080129FC: .4byte 0x00272000

	thumb_func_start FUN_08012a00
FUN_08012a00: @ 0x08012A00
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	movs r5, #0
	ldr r7, _08012A60 @ =0x0836FB24
_08012A0A:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #2
	adds r3, r0, r6
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _08012A4C
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r5, [r3, #0x68]
_08012A4C:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08012A0A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012A60: .4byte 0x0836FB24

	thumb_func_start FUN_08012a64
FUN_08012a64: @ 0x08012A64
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4]
	asrs r0, r0, #8
	str r0, [sp]
	ldr r0, [r4, #4]
	asrs r0, r0, #8
	str r0, [sp, #4]
	ldr r0, _08012AB8 @ =0x02002200
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xb
	bne _08012AD0
	mov r0, sp
	bl FUN_08012518
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #6
	beq _08012AD0
	ldr r0, _08012ABC @ =0x0202FDC0
	adds r0, #0x54
	ldrb r0, [r0]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08012AD0
	cmp r2, #2
	bne _08012AC4
	ldr r1, [r4]
	movs r0, #0x87
	lsls r0, r0, #0xc
	cmp r1, r0
	ble _08012AC4
	ldr r0, _08012AC0 @ =0x083427B4
	b _08012AD2
	.align 2, 0
_08012AB8: .4byte 0x02002200
_08012ABC: .4byte 0x0202FDC0
_08012AC0: .4byte 0x083427B4
_08012AC4:
	lsls r0, r2, #3
	ldr r1, _08012ACC @ =0x08342784
	adds r0, r0, r1
	b _08012AD2
	.align 2, 0
_08012ACC: .4byte 0x08342784
_08012AD0:
	movs r0, #0
_08012AD2:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
