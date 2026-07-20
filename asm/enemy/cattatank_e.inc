	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080994ec
FUN_080994ec: @ 0x080994EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _080994F8
	b _08099736
_080994F8:
	lsls r0, r0, #2
	ldr r1, _08099504 @ =_08099508
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099504: .4byte _08099508
_08099508: @ jump table
	.4byte _08099540 @ case 0
	.4byte _0809954A @ case 1
	.4byte _08099584 @ case 2
	.4byte _08099670 @ case 3
	.4byte _08099684 @ case 4
	.4byte _08099736 @ case 5
	.4byte _08099736 @ case 6
	.4byte _08099736 @ case 7
	.4byte _08099736 @ case 8
	.4byte _08099736 @ case 9
	.4byte _080996A0 @ case 10
	.4byte _080996AE @ case 11
	.4byte _080996C8 @ case 12
	.4byte _08099722 @ case 13
_08099540:
	movs r0, #0
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809954A:
	ldr r1, _0809956C @ =0x0000D502
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099570 @ =0x0836A4D8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08099574
	movs r0, #0x80
	lsls r0, r0, #1
	b _08099576
	.align 2, 0
_0809956C: .4byte 0x0000D502
_08099570: .4byte sCollisions+(1*24)
_08099574:
	ldr r0, _080995B0 @ =0xFFFFFF00
_08099576:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099584:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x64]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r4, #0x64]
	cmp r1, #0
	ble _080995B4
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _080995BE
	.align 2, 0
_080995B0: .4byte 0xFFFFFF00
_080995B4:
	ldr r3, _080995DC @ =0xFFFFF600
	adds r0, r2, r3
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_080995BE:
	adds r1, r0, #0
	cmp r1, #0
	beq _080995CA
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_080995CA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080995E0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080995E6
	.align 2, 0
_080995DC: .4byte 0xFFFFF600
_080995E0:
	ldr r0, [r4, #0x54]
	ldr r3, _08099628 @ =0xFFFFF600
	adds r0, r0, r3
_080995E6:
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _080995FC
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
_080995FC:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _08099634
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _0809965C
	ldr r0, _0809962C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x58]
	ldr r0, [r2, #0x58]
	cmp r1, r0
	blt _0809965C
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099630
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099628: .4byte 0xFFFFF600
_0809962C: .4byte pZero2
_08099630:
	ldr r1, [r2, #0x54]
	b _08099652
_08099634:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809964C
	ldr r0, _08099648 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099648: .4byte pZero2
_0809964C:
	ldr r0, _0809966C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
_08099652:
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _0809965C
_08099658:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809965C:
	ldr r1, [r4, #0x64]
	movs r0, #0xc0
	lsls r0, r0, #5
	cmp r1, r0
	ble _08099736
	movs r0, #3
	b _08099734
	.align 2, 0
_0809966C: .4byte pZero2
_08099670:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099684:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099736
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08099736
_080996A0:
	ldr r1, _080996C4 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080996AE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08099734
	.align 2, 0
_080996C4: .4byte 0x0000D511
_080996C8:
	ldr r1, _080996FC @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _08099700
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
	b _0809971A
	.align 2, 0
_080996FC: .4byte 0x0000D512
_08099700:
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
_0809971A:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099722:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	movs r0, #1
_08099734:
	strb r0, [r4, #0xe]
_08099736:
	pop {r4}
	pop {r0}
	bx r0

