	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099260
FUN_08099260: @ 0x08099260
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _0809926C
	b _080994E2
_0809926C:
	lsls r0, r0, #2
	ldr r1, _08099278 @ =_0809927C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099278: .4byte _0809927C
_0809927C: @ jump table
	.4byte _080992B4 @ case 0
	.4byte _080992EE @ case 1
	.4byte _080994E2 @ case 2
	.4byte _080994E2 @ case 3
	.4byte _080994E2 @ case 4
	.4byte _080994E2 @ case 5
	.4byte _080994E2 @ case 6
	.4byte _080994E2 @ case 7
	.4byte _080994E2 @ case 8
	.4byte _080994E2 @ case 9
	.4byte _0809944C @ case 10
	.4byte _0809945A @ case 11
	.4byte _08099474 @ case 12
	.4byte _080994CE @ case 13
_080992B4:
	ldr r1, _080992DC @ =0x0000D501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080992E0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080992E4
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080992E6
	.align 2, 0
_080992DC: .4byte 0x0000D501
_080992E0: .4byte sCollisions+(1*24)
_080992E4:
	movs r0, #0xc0
_080992E6:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080992EE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0809930E
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _08099318
_0809930E:
	ldr r2, _08099354 @ =0xFFFFF600
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_08099318:
	adds r2, r0, #0
	cmp r2, #0
	beq _08099324
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_08099324:
	ldrb r0, [r4, #0x11]
	adds r6, r0, #0
	cmp r6, #1
	bne _08099360
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	ldr r2, [r4, #0x54]
	ldr r5, [r4, #0x5c]
	ldr r3, [r4, #0x58]
	cmp r0, #1
	bls _0809938E
	ldr r0, _08099358 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _0809938E
	cmp r5, #0
	ble _0809935C
	ldr r0, [r1, #0x54]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099354: .4byte 0xFFFFF600
_08099358: .4byte pZero2
_0809935C:
	ldr r0, [r1, #0x54]
	b _08099386
_08099360:
	ldr r5, [r4, #0x5c]
	cmp r5, #0
	ble _0809937C
	ldr r0, _08099378 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099378: .4byte pZero2
_0809937C:
	ldr r0, _080993BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
_08099386:
	cmp r0, r2
	ble _0809938E
_0809938A:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809938E:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	beq _080993EC
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080993C0
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _080993EC
	ldr r0, _080993BC @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _080993EC
	ldr r0, [r1, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080993CC
	b _080993DC
	.align 2, 0
_080993BC: .4byte pZero2
_080993C0:
	ldr r0, _080993D4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	ble _080993DC
_080993CC:
	ldr r0, _080993D8 @ =0x00003BFF
	cmp r1, r0
	ble _080993E4
	b _080993EC
	.align 2, 0
_080993D4: .4byte pZero2
_080993D8: .4byte 0x00003BFF
_080993DC:
	subs r1, r2, r0
	ldr r0, _0809940C @ =0x00003BFF
	cmp r1, r0
	bgt _080993EC
_080993E4:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080993EC:
	cmp r5, #0
	ble _08099414
	ldr r1, _08099410 @ =0xFFFFF600
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	b _0809942C
	.align 2, 0
_0809940C: .4byte 0x00003BFF
_08099410: .4byte 0xFFFFF600
_08099414:
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	ldr r2, _08099448 @ =0xFFFFF600
_0809942C:
	adds r0, r0, r2
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	cmp r2, r0
	beq _080994E2
	movs r1, #0
	str r1, [r4, #0x60]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080994E2
	.align 2, 0
_08099448: .4byte 0xFFFFF600
_0809944C:
	ldr r1, _08099470 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809945A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080994E0
	.align 2, 0
_08099470: .4byte 0x0000D511
_08099474:
	ldr r1, _080994A8 @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _080994AC
	movs r1, #1
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	b _080994C6
	.align 2, 0
_080994A8: .4byte 0x0000D512
_080994AC:
	movs r1, #0
	movs r0, #0xef
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_080994C6:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080994CE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	movs r0, #0
_080994E0:
	strb r0, [r4, #0xe]
_080994E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

