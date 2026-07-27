	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cbe38
FUN_080cbe38: @ 0x080CBE38
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x2c]
	cmp r3, #0
	beq _080CBE78
	ldr r3, [r3, #0x58]
	ldr r4, [r2, #0x58]
	subs r1, r3, r4
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080CBE68
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CBE60
	str r1, [r2, #0x60]
_080CBE60:
	ldr r0, [r2, #0x60]
	adds r0, r4, r0
	str r0, [r2, #0x58]
	b _080CBE9E
_080CBE68:
	ldr r1, _080CBE74 @ =0xFFFFF000
	adds r0, r3, r1
	str r0, [r2, #0x58]
	movs r0, #0
	str r0, [r2, #0x60]
	b _080CBE9E
	.align 2, 0
_080CBE74: .4byte 0xFFFFF000
_080CBE78:
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CBE88
	str r1, [r2, #0x60]
_080CBE88:
	ldr r0, [r2, #0x58]
	ldr r1, [r2, #0x60]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r1, [r1]
	cmp r0, r1
	ble _080CBE9E
	str r1, [r2, #0x58]
	str r3, [r2, #0x60]
_080CBE9E:
	pop {r4}
	pop {r0}
	bx r0
