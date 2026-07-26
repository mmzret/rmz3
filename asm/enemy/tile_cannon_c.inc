	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

