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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
