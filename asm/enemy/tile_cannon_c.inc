	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08078480
FUN_08078480: @ 0x08078480
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08078496
	bl isKilled
	cmp r0, #0
	beq _080784AA
_08078496:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080784B0 @ =0x08367508
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080784AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080784B0: .4byte 0x08367508

	thumb_func_start FUN_080784b4
FUN_080784b4: @ 0x080784B4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080784CE
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080784D4 @ =0x08367520
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080784CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080784D4: .4byte 0x08367520

	thumb_func_start FUN_080784d8
FUN_080784d8: @ 0x080784D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080784E8
	cmp r5, #1
	beq _08078530
	b _08078544
_080784E8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807854C @ =0x08367460
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	strb r5, [r0]
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
	ldrb r1, [r4, #0x10]
	movs r2, #0xbc
	lsls r2, r2, #6
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08078530:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08078544
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08078544:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807854C: .4byte 0x08367460

	thumb_func_start FUN_08078550
FUN_08078550: @ 0x08078550
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08078560
	cmp r0, #1
	beq _08078576
	b _080785AE
_08078560:
	ldrb r1, [r4, #0x10]
	movs r2, #0xbc
	lsls r2, r2, #6
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08078576:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _080785B4 @ =0x0836754A
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080785B8 @ =0x08367460
	adds r1, r1, r2
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _080785AE
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_080785AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080785B4: .4byte 0x0836754A
_080785B8: .4byte 0x08367460

	thumb_func_start FUN_080785bc
FUN_080785bc: @ 0x080785BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080785CC
	cmp r0, #1
	beq _080785F2
	b _08078616
_080785CC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807861C @ =0x08367460
	bl SetDDP
	adds r0, r4, #0
	bl FUN_08078108
	str r0, [r4, #0x2c]
	ldr r0, _08078620 @ =0x00002F04
	adds r1, r0, #0
	ldrb r0, [r4, #0x10]
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080785F2:
	adds r0, r4, #0
	bl FUN_080780c4
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08078610
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08078610
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08078610:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08078616:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807861C: .4byte 0x08367460
_08078620: .4byte 0x00002F04

	thumb_func_start FUN_08078624
FUN_08078624: @ 0x08078624
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08078634
	cmp r0, #1
	beq _08078642
	b _0807865A
_08078634:
	ldr r1, _08078660 @ =0x00002F06
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08078642:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807865A
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807865A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08078660: .4byte 0x00002F06

	thumb_func_start FUN_08078664
FUN_08078664: @ 0x08078664
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08078676
	cmp r4, #1
	beq _0807869A
	b _0807873C
_08078676:
	adds r0, r5, #0
	bl InitRotatableMotion
	ldr r1, _08078744 @ =0x00002F06
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	movs r0, #0x78
	strb r0, [r5, #0x12]
	str r4, [r5, #0x5c]
	adds r0, #0x88
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807869A:
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	bne _08078736
	ldr r0, _08078748 @ =pZero2
	ldr r1, [r0]
	ldr r4, [r1, #0x54]
	ldr r0, [r5, #0x54]
	subs r4, r4, r0
	ldr r0, [r5, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r1, #0x58]
	subs r7, r1, r0
	asrs r0, r4, #8
	adds r6, r0, #0
	muls r6, r0, r6
	asrs r0, r7, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	lsls r4, r4, #8
	adds r0, r4, #0
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r0, r7, #8
	adds r1, r6, #0
	bl __divsi3
	adds r7, r0, #0
	ldr r1, [r5, #0x5c]
	subs r0, r4, r1
	cmp r0, #0
	bge _080786F4
	adds r0, #7
_080786F4:
	asrs r0, r0, #3
	adds r4, r1, r0
	str r4, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	subs r0, r7, r2
	cmp r0, #0
	bge _08078704
	adds r0, #7
_08078704:
	asrs r1, r0, #3
	adds r1, r2, r1
	str r1, [r5, #0x60]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	subs r0, #0x40
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08078736
	movs r0, #6
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08078736:
	adds r0, r5, #0
	bl UpdateEntityAnim
_0807873C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078744: .4byte 0x00002F06
_08078748: .4byte pZero2

	thumb_func_start FUN_0807874c
FUN_0807874c: @ 0x0807874C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r2, [r5, #0x28]
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bhi _08078842
	lsls r0, r0, #2
	ldr r1, _08078764 @ =_08078768
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08078764: .4byte _08078768
_08078768: @ jump table
	.4byte _0807877C @ case 0
	.4byte _08078786 @ case 1
	.4byte _080787EA @ case 2
	.4byte _08078808 @ case 3
	.4byte _08078812 @ case 4
_0807877C:
	movs r0, #2
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08078786:
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r2, [r0]
	ldr r3, [r5, #0x54]
	str r3, [sp]
	ldr r4, _08078800 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	str r0, [sp]
	ldr r3, [r5, #0x58]
	str r3, [sp, #4]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	subs r2, #0x40
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	bl CreateLemon
	movs r0, #0x2c
	bl PlaySound
	ldr r1, _08078804 @ =0x00002F08
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080787EA:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08078842
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _08078840
	.align 2, 0
_08078800: .4byte gSineTable
_08078804: .4byte 0x00002F08
_08078808:
	movs r0, #4
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08078812:
	adds r0, r2, #0
	bl IsFrozen
	cmp r0, #0
	bne _08078842
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08078842
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0807883E
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08078842
_0807883E:
	movs r0, #1
_08078840:
	strb r0, [r5, #0xe]
_08078842:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807884c
FUN_0807884c:
	.byte 0x70, 0xB5, 0x04, 0x1C
	.byte 0xA5, 0x6A, 0xA0, 0x7B, 0x00, 0x28, 0x53, 0xD1, 0x28, 0x1C, 0xEA, 0xF7, 0xF7, 0xFE, 0x06, 0x1C
	.byte 0x00, 0x2E, 0x4D, 0xD1, 0xE1, 0x6D, 0x48, 0x42, 0x00, 0x28, 0x00, 0xDA, 0x07, 0x30, 0xC0, 0x10
	.byte 0x0A, 0x18, 0xE2, 0x65, 0x21, 0x6E, 0x80, 0x20, 0x40, 0x00, 0x40, 0x1A, 0x00, 0x28, 0x00, 0xDA
	.byte 0x07, 0x30, 0xC0, 0x10, 0x09, 0x18, 0x21, 0x66, 0xF0, 0x29, 0x2D, 0xDD, 0x14, 0x48, 0x01, 0x1C
	.byte 0x28, 0x7C, 0x09, 0x18, 0x28, 0x1C, 0x9E, 0xF7, 0x67, 0xFE, 0x28, 0x1C, 0x9E, 0xF7, 0xDE, 0xFE
	.byte 0x29, 0x1C, 0xB8, 0x31, 0x01, 0x20, 0x08, 0x70, 0xEE, 0x62, 0xA1, 0x7A, 0xFE, 0x20, 0x08, 0x40
	.byte 0xFD, 0x21, 0x08, 0x40, 0xA0, 0x72, 0x20, 0x1C, 0x8C, 0x30, 0x06, 0x60, 0x04, 0x30, 0x06, 0x60
	.byte 0x04, 0x30, 0x06, 0x70, 0xA1, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0xA0, 0x72, 0x05, 0x49, 0x60, 0x7A
	.byte 0x80, 0x00, 0x40, 0x18, 0x03, 0x21, 0xE1, 0x60, 0x00, 0x68, 0xC0, 0x68, 0x60, 0x61, 0x0F, 0xE0
	.byte 0x02, 0x2F, 0x00, 0x00, 0x48, 0x59, 0x36, 0x08, 0x10, 0x04, 0x00, 0x14, 0x09, 0x04, 0x09, 0x14
	.byte 0x85, 0xF0, 0x20, 0xFE, 0x00, 0x04, 0x00, 0x0E, 0x40, 0x38, 0x21, 0x1C, 0x24, 0x31, 0x08, 0x70
	.byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_08078908
FUN_08078908:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x7B, 0x00, 0x28
	.byte 0x02, 0xD0, 0x01, 0x28, 0x1B, 0xD0, 0x39, 0xE0, 0x01, 0x22, 0xA1, 0x7A, 0x10, 0x20, 0x08, 0x43
	.byte 0xA0, 0x72, 0x20, 0x1C, 0x4C, 0x30, 0x02, 0x70, 0x23, 0x1C, 0x4A, 0x33, 0x10, 0x22, 0x19, 0x78
	.byte 0x11, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x43, 0x18, 0x70, 0x16, 0x48, 0x01, 0x1C, 0x20, 0x7C
	.byte 0x09, 0x18, 0x20, 0x1C, 0x9E, 0xF7, 0x10, 0xFE, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C
	.byte 0x9E, 0xF7, 0x84, 0xFE, 0x20, 0x1C, 0x74, 0x30, 0x0F, 0x4A, 0x21, 0x1C, 0x71, 0x31, 0x09, 0x78
	.byte 0x09, 0x06, 0x09, 0x16, 0x89, 0x18, 0x0A, 0x78, 0x51, 0x00, 0x89, 0x18, 0xC9, 0x00, 0x0B, 0x4A
	.byte 0x89, 0x18, 0x8E, 0xF7, 0x4F, 0xFC, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x05, 0xD1
	.byte 0x00, 0x20, 0x01, 0x21, 0x61, 0x73, 0xA0, 0x73, 0x3C, 0x20, 0xA0, 0x74, 0x10, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x02, 0x2F, 0x00, 0x00, 0x50, 0x75, 0x36, 0x08, 0x60, 0x74, 0x36, 0x08
