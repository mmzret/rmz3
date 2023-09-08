	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start batring_080677e0
batring_080677e0: @ 0x080677E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #1
	beq _0806783A
	cmp r4, #1
	bgt _080677FA
	cmp r4, #0
	beq _08067804
	b _08067A40
_080677FA:
	cmp r4, #2
	beq _080678C2
	cmp r4, #3
	beq _080678D0
	b _08067A40
_08067804:
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08067878 @ =sCollisions+48
	bl SetDDP
	str r4, [r7, #0x60]
	str r4, [r7, #0x5c]
	movs r0, #0xc
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0xbb
	strb r4, [r0]
	ldr r0, _0806787C @ =0xFFFFFD80
	str r0, [r7, #0x60]
	strb r4, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0806783A:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _08067858
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08067858:
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08067884
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08067880 @ =sCollisions+96
	bl SetDDP
	b _0806788E
	.align 2, 0
_08067878: .4byte sCollisions+48
_0806787C: .4byte 0xFFFFFD80
_08067880: .4byte sCollisions+96
_08067884:
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080678A8 @ =sCollisions+48
	bl SetDDP
_0806788E:
	ldr r0, _080678AC @ =pZero2
	ldr r0, [r0]
	ldr r3, [r7, #0x58]
	ldr r1, [r0, #0x58]
	subs r2, r3, r1
	cmp r2, #0
	ble _080678B0
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _080678BC
	b _08067A40
	.align 2, 0
_080678A8: .4byte sCollisions+48
_080678AC: .4byte pZero2
_080678B0:
	subs r1, r1, r3
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	bgt _080678BC
	b _08067A40
_080678BC:
	movs r0, #1
	strb r0, [r7, #0xe]
	b _08067A40
_080678C2:
	movs r0, #1
	strb r0, [r7, #0x12]
	movs r0, #0x60
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080678D0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080678FC
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080678F8 @ =sCollisions+96
	bl SetDDP
	b _08067906
	.align 2, 0
_080678F8: .4byte sCollisions+96
_080678FC:
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08067964 @ =sCollisions+48
	bl SetDDP
_08067906:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _08067980
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08067980
	ldr r0, _08067968 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r2, r2, r0
	adds r5, r2, #0
	ldr r0, [r7, #0x58]
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	adds r6, r1, #0
	cmp r2, #0
	bne _08067938
	cmp r1, #0
	beq _0806796C
_08067938:
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r5, #8
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r0, r6, #8
	adds r1, r4, #0
	bl __divsi3
	adds r6, r0, #0
	b _08067970
	.align 2, 0
_08067964: .4byte sCollisions+48
_08067968: .4byte pZero2
_0806796C:
	movs r5, #0x80
	lsls r5, r5, #1
_08067970:
	lsls r0, r5, #7
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	lsls r0, r6, #7
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	movs r0, #0x10
	strb r0, [r7, #0x12]
_08067980:
	ldr r1, [r7, #0x54]
	ldr r0, [r7, #0x5c]
	adds r6, r1, r0
	str r6, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	mov sb, r1
	str r1, [r7, #0x58]
	ldr r0, _08067A4C @ =pZero2
	ldr r3, [r0]
	ldr r0, [r3, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	subs r0, r0, r6
	movs r1, #0xa0
	lsls r1, r1, #8
	cmp r0, r1
	bhs _08067A3C
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _08067A40
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08067A40
	ldr r2, _08067A50 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08067A54 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08067A58 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #7
	bhi _08067A3C
	ldr r0, [r3, #0x58]
	cmp sb, r0
	bgt _08067A3C
	adds r0, r6, #0
	mov r1, sb
	bl FUN_080098a4
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r5, #0x90
	lsls r5, r5, #5
	adds r3, r6, r5
	mov r8, r3
	add r5, sb
	mov r0, r8
	adds r1, r5, #0
	bl FUN_080098a4
	orrs r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _08067A5C @ =0xFFFFEE00
	adds r6, r6, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080098a4
	orrs r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r5, _08067A5C @ =0xFFFFEE00
	add r5, sb
	mov r0, r8
	adds r1, r5, #0
	bl FUN_080098a4
	orrs r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080098a4
	orrs r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0
	bne _08067A3C
	movs r0, #3
	strb r0, [r7, #0xd]
	strb r4, [r7, #0xe]
_08067A3C:
	movs r0, #0x60
	strb r0, [r7, #0x13]
_08067A40:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067A4C: .4byte pZero2
_08067A50: .4byte RNG_0202f388
_08067A54: .4byte 0x000343FD
_08067A58: .4byte 0x00269EC3
_08067A5C: .4byte 0xFFFFEE00

	thumb_func_start FUN_08067a60
FUN_08067a60: @ 0x08067A60
	movs r0, #1
	bx lr

	thumb_func_start FUN_08067a64
FUN_08067a64: @ 0x08067A64
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _08067A70
	b _08067C3E
_08067A70:
	lsls r0, r0, #2
	ldr r1, _08067A7C @ =_08067A80
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08067A7C: .4byte _08067A80
_08067A80: @ jump table
	.4byte _08067AA0 @ case 0
	.4byte _08067AB0 @ case 1
	.4byte _08067AD6 @ case 2
	.4byte _08067AEC @ case 3
	.4byte _08067B14 @ case 4
	.4byte _08067B36 @ case 5
	.4byte _08067B86 @ case 6
	.4byte _08067BBE @ case 7
_08067AA0:
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067AB0:
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08067AC0
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08067AC0:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08067AC8
	b _08067C3E
_08067AC8:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08067AD4
	b _08067C3E
_08067AD4:
	b _08067B6E
_08067AD6:
	ldr r1, _08067B10 @ =0x00000601
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067AEC:
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	strb r0, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08067B00
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08067B00:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08067B0C
	b _08067C3E
_08067B0C:
	b _08067B6E
	.align 2, 0
_08067B10: .4byte 0x00000601
_08067B14:
	adds r0, r5, #0
	adds r0, #0xb9
	movs r4, #0
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08067B78 @ =sCollisions+(24*6)
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbb
	movs r0, #1
	strb r0, [r1]
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067B36:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067B46
	str r1, [r5, #0x60]
_08067B46:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08067B7C
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08067B6E:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08067C3E
	.align 2, 0
_08067B78: .4byte sCollisions+(24*6)
_08067B7C:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _08067C3E
_08067B86:
	movs r0, #0x82
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _08067BA4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bge _08067BAC
	ldr r1, _08067BA8 @ =0x00000603
	adds r0, r5, #0
	bl SetMotion
	b _08067BB4
	.align 2, 0
_08067BA4: .4byte pZero2
_08067BA8: .4byte 0x00000603
_08067BAC:
	ldr r1, _08067BF0 @ =0x00000605
	adds r0, r5, #0
	bl SetMotion
_08067BB4:
	ldr r0, _08067BF4 @ =0xFFFFFE80
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067BBE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08067BE2
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08067BFC
_08067BE2:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067BF8 @ =sCollisions+(24*10)
	bl SetDDP
	b _08067C06
	.align 2, 0
_08067BF0: .4byte 0x00000605
_08067BF4: .4byte 0xFFFFFE80
_08067BF8: .4byte sCollisions+(24*10)
_08067BFC:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067C44 @ =sCollisions+(24*8)
	bl SetDDP
_08067C06:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067C16
	str r1, [r5, #0x60]
_08067C16:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08067C3E
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08067C3E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08067C44: .4byte sCollisions+(24*8)

	thumb_func_start FUN_08067c48
FUN_08067c48: @ 0x08067C48
	movs r0, #1
	bx lr

	thumb_func_start FUN_08067c4c
FUN_08067c4c: @ 0x08067C4C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #6
	bls _08067C58
	b _08067F10
_08067C58:
	lsls r0, r0, #2
	ldr r1, _08067C64 @ =_08067C68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08067C64: .4byte _08067C68
_08067C68: @ jump table
	.4byte _08067C84 @ case 0
	.4byte _08067E82 @ case 1
	.4byte _08067CB0 @ case 2
	.4byte _08067CF4 @ case 3
	.4byte _08067E00 @ case 4
	.4byte _08067E20 @ case 5
	.4byte _08067EA0 @ case 6
_08067C84:
	movs r4, #0
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0xb9
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08067CAC @ =sCollisions+(24*8)
	bl SetDDP
	movs r0, #4
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0xbb
	strb r4, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08067E82
	.align 2, 0
_08067CAC: .4byte sCollisions+(24*8)
_08067CB0:
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, _08067CD0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bge _08067CDC
	ldr r0, _08067CD4 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldr r1, _08067CD8 @ =0x00000603
	adds r0, r5, #0
	bl SetMotion
	b _08067CEA
	.align 2, 0
_08067CD0: .4byte pZero2
_08067CD4: .4byte 0xFFFFFE00
_08067CD8: .4byte 0x00000603
_08067CDC:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldr r1, _08067D08 @ =0x00000605
	adds r0, r5, #0
	bl SetMotion
_08067CEA:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067CF4:
	movs r4, #0
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x5c]
	cmp r2, #0
	bge _08067D10
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	ldr r2, _08067D0C @ =0xFFFFF200
	b _08067D18
	.align 2, 0
_08067D08: .4byte 0x00000605
_08067D0C: .4byte 0xFFFFF200
_08067D10:
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	movs r2, #0xe0
	lsls r2, r2, #4
_08067D18:
	adds r0, r0, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08067D30
	movs r4, #1
	b _08067DA6
_08067D30:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _08067D78 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r1, _08067D7C @ =0xFFFFF200
	adds r2, r0, r1
	ldr r0, [r5, #0x58]
	subs r0, r2, r0
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067D8A
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, r1
	ble _08067D5E
	str r1, [r5, #0x60]
_08067D5E:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	cmp r0, r2
	bls _08067D6C
	str r2, [r5, #0x58]
_08067D6C:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _08067D84
	ldr r0, _08067D80 @ =0xFFFFFF00
	b _08067DA4
	.align 2, 0
_08067D78: .4byte 0xFFFFF800
_08067D7C: .4byte 0xFFFFF200
_08067D80: .4byte 0xFFFFFF00
_08067D84:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08067DA4
_08067D8A:
	movs r0, #0
	str r0, [r5, #0x60]
	str r2, [r5, #0x58]
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _08067DA0
	ldr r0, _08067D9C @ =0xFFFFFE00
	b _08067DA4
	.align 2, 0
_08067D9C: .4byte 0xFFFFFE00
_08067DA0:
	movs r0, #0x80
	lsls r0, r0, #2
_08067DA4:
	str r0, [r5, #0x5c]
_08067DA6:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08067DB2
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08067DB4
_08067DB2:
	movs r4, #1
_08067DB4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08067DD8
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08067DE8
_08067DD8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067DE4 @ =sCollisions+(24*10)
	bl SetDDP
	b _08067DF2
	.align 2, 0
_08067DE4: .4byte sCollisions+(24*10)
_08067DE8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067DFC @ =sCollisions+(24*8)
	bl SetDDP
_08067DF2:
	cmp r4, #1
	beq _08067DF8
	b _08067F10
_08067DF8:
	b _08067E92
	.align 2, 0
_08067DFC: .4byte sCollisions+(24*8)
_08067E00:
	movs r1, #0
	str r1, [r5, #0x5c]
	ldr r0, _08067E68 @ =0xFFFFFF00
	str r0, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0xb9
	strb r1, [r0]
	subs r0, #0x45
	ldr r1, _08067E6C @ =sCollisions+(24*8)
	bl SetDDP
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067E20:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r2, _08067E70 @ =0xFFFFF200
	adds r1, r1, r2
	bl PushoutToDown1
	ldr r1, [r5, #0x58]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08067E5C
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08067E78
_08067E5C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067E74 @ =sCollisions+(24*10)
	bl SetDDP
	b _08067E82
	.align 2, 0
_08067E68: .4byte 0xFFFFFF00
_08067E6C: .4byte sCollisions+(24*8)
_08067E70: .4byte 0xFFFFF200
_08067E74: .4byte sCollisions+(24*10)
_08067E78:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067E9C @ =sCollisions+(24*8)
	bl SetDDP
_08067E82:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08067F10
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08067F10
_08067E92:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08067F10
	.align 2, 0
_08067E9C: .4byte sCollisions+(24*8)
_08067EA0:
	ldr r1, _08067EBC @ =pZero2
	ldr r0, [r1]
	ldr r3, [r5, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r3, r0
	adds r4, r1, #0
	cmp r2, #0
	ble _08067EC0
	movs r0, #0xf0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _08067EEA
	b _08067ECA
	.align 2, 0
_08067EBC: .4byte pZero2
_08067EC0:
	subs r1, r0, r3
	movs r0, #0xf0
	lsls r0, r0, #8
	cmp r1, r0
	bgt _08067EEA
_08067ECA:
	ldr r0, [r4]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	subs r2, r1, r0
	cmp r2, #0
	ble _08067EE0
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _08067EEA
	b _08067F08
_08067EE0:
	subs r1, r0, r1
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _08067F08
_08067EEA:
	movs r0, #1
	strb r0, [r5, #0x11]
	ldr r1, _08067F04 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _08067F10
	.align 2, 0
_08067F04: .4byte gEnemyFnTable
_08067F08:
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08067F10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08067f18
FUN_08067f18: @ 0x08067F18
	movs r0, #1
	bx lr

	thumb_func_start FUN_08067f1c
FUN_08067f1c: @ 0x08067F1C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08067F36
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08067F64 @ =sCollisions+(24*3)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08067F36:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08067F5E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08067F68 @ =sCollisions+48
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0xc0
	strb r1, [r0]
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08067F5E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08067F64: .4byte sCollisions+(24*3)
_08067F68: .4byte sCollisions+48

	thumb_func_start FUN_08067f6c
FUN_08067f6c: @ 0x08067F6C
	movs r0, #1
	bx lr

	thumb_func_start nop_08067f70
nop_08067f70: @ 0x08067F70
	bx lr
	.align 2, 0

	thumb_func_start FUN_08067f74
FUN_08067f74: @ 0x08067F74
	movs r0, #1
	bx lr

	thumb_func_start FUN_08067f78
FUN_08067f78: @ 0x08067F78
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08067F88
	cmp r4, #1
	beq _08067F9A
	b _08067FE4
_08067F88:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067FD4 @ =sCollisions+(24*3)
	bl SetDDP
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067F9A:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067FAA
	str r1, [r5, #0x60]
_08067FAA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08067FDC
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	ldr r1, _08067FD8 @ =0xFFFFF200
	b _08067FE0
	.align 2, 0
_08067FD4: .4byte sCollisions+(24*3)
_08067FD8: .4byte 0xFFFFF200
_08067FDC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
_08067FE0:
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08067FE4:
	adds r6, r5, #0
	adds r6, #0xbc
	ldr r0, [r6]
	bl isKilled
	cmp r0, #0
	beq _0806800A
	movs r4, #0
	str r4, [r6]
	adds r0, r5, #0
	adds r0, #0xc0
	strb r4, [r0]
	subs r0, #0x4c
	ldr r1, _08068010 @ =sCollisions+48
	bl SetDDP
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_0806800A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068010: .4byte sCollisions+48

	thumb_func_start FUN_08068014
FUN_08068014: @ 0x08068014
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068018
FUN_08068018: @ 0x08068018
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08068028
	cmp r0, #1
	beq _0806803C
	b _0806812A
_08068028:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080680C4 @ =sCollisions+(24*12)
	bl SetDDP
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806803C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	beq _0806810C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r1, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	lsls r0, r2, #4
	subs r0, r2, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x60]
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08068096
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08068096:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0806812A
	ldr r1, [r5]
	cmp r1, #0
	beq _08068100
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r2, [r0]
	cmp r2, #1
	bne _080680C8
	subs r0, #0x1c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	ble _0806810C
	movs r0, #5
	b _080680FA
	.align 2, 0
_080680C4: .4byte sCollisions+(24*12)
_080680C8:
	cmp r2, #2
	bne _080680EC
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _080680E8
	ldr r1, _080680E4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08068118
	.align 2, 0
_080680E4: .4byte gEnemyFnTable
_080680E8:
	movs r0, #7
	b _080680FA
_080680EC:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	ble _0806810C
	movs r0, #2
_080680FA:
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
	b _0806812A
_08068100:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08068124
_0806810C:
	ldr r1, _08068120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08068118:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0806812A
	.align 2, 0
_08068120: .4byte gEnemyFnTable
_08068124:
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806812A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start batring_08068130
batring_08068130: @ 0x08068130
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _080681BA
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _080681BA
	ldr r2, _0806817C @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08068194
	cmp r1, #0
	beq _080681BA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08068180
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	movs r0, #5
	b _0806818E
	.align 2, 0
_0806817C: .4byte sElementCoord
_08068180:
	cmp r1, #0x30
	bne _080681BA
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #2
	strb r1, [r0]
	movs r0, #7
_0806818E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _080681BA
_08068194:
	cmp r1, #0
	beq _080681BA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _080681AE
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	b _080681BA
_080681AE:
	cmp r1, #0x30
	bne _080681BA
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
_080681BA:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start batring_080681c4
batring_080681c4: @ 0x080681C4
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _080681DC
	cmp r0, #0xe
	beq _080681DC
	cmp r0, #0xf
	bne _08068206
_080681DC:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08068206
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _080681FE
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xff
	b _08068204
_080681FE:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xfe
_08068204:
	strb r0, [r1]
_08068206:
	ldr r0, [r3, #4]
	ldr r1, _08068284 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _080682C8
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _080682C8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08068230
	adds r0, r4, #0
	bl isFrozen
_08068230:
	ldr r6, _08068288 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r4, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _0806828C
	ldr r0, [r4, #0x64]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x68]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x68]
	b _080682A8
	.align 2, 0
_08068284: .4byte 0x000200FF
_08068288: .4byte pZero2
_0806828C:
	ldr r0, [r6]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080682A0
	ldr r0, _0806829C @ =0xFFFFFF00
	b _080682A4
	.align 2, 0
_0806829C: .4byte 0xFFFFFF00
_080682A0:
	movs r0, #0x80
	lsls r0, r0, #1
_080682A4:
	str r0, [r4, #0x64]
	str r5, [r4, #0x68]
_080682A8:
	ldr r1, [r4, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080682C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
