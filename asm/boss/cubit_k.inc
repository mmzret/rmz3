	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubit_08054688
cubit_08054688: @ 0x08054688
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x1e]
	lsls r0, r0, #8
	adds r1, r2, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r3, _080546CC @ =0x0000B003
	cmp r0, r3
	bne _08054710
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08054746
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080546D0
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _080546EA
	.align 2, 0
_080546CC: .4byte 0x0000B003
_080546D0:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_080546EA:
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08054700
	ldr r1, _080546FC @ =0x0000B001
	b _08054702
	.align 2, 0
_080546FC: .4byte 0x0000B001
_08054700:
	ldr r1, _0805470C @ =0x0000B002
_08054702:
	adds r0, r2, #0
	bl SetMotion
	b _08054746
	.align 2, 0
_0805470C: .4byte 0x0000B002
_08054710:
	ldr r0, _08054730 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _08054734
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08054746
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
	b _08054746
	.align 2, 0
_08054730: .4byte pZero2
_08054734:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08054746
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
_08054746:
	pop {r0}
	bx r0
	.align 2, 0
