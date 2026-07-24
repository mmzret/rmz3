	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08093a20
FUN_08093a20: @ 0x08093A20
	push {lr}
	movs r3, #0
	ldr r1, _08093A50 @ =pZero2
	ldr r1, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	ble _08093A32
	movs r3, #1
_08093A32:
	ldr r1, _08093A54 @ =0xFFFFA000
	adds r0, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #0xe
	adds r0, r0, r1
	subs r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _08093A58 @ =0x00000FFF
	cmp r0, r1
	bls _08093A5C
	adds r0, r3, #0
	b _08093A5E
	.align 2, 0
_08093A50: .4byte pZero2
_08093A54: .4byte 0xFFFFA000
_08093A58: .4byte 0x00000FFF
_08093A5C:
	movs r0, #2
_08093A5E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093a64
FUN_08093a64: @ 0x08093A64
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _08093A90
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08093A8C @ =0x000007FF
	cmp r1, r0
	bgt _08093A90
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _08093A92
	.align 2, 0
_08093A8C: .4byte 0x000007FF
_08093A90:
	movs r0, #0
_08093A92:
	pop {r4}
	pop {r1}
	bx r1
