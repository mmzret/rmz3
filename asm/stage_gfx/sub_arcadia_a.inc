	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08014efc
FUN_08014efc: @ 0x08014EFC
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	bne _08014F54
	ldr r1, [r2, #0x34]
	movs r0, #0x87
	lsls r0, r0, #4
	cmp r1, r0
	ble _08014F22
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r2, #0x44]
	movs r0, #0x40
	str r0, [r2, #0x48]
	str r3, [r2, #0x4c]
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08014F4C
_08014F22:
	ldr r1, [r2, #0x38]
	ldr r0, _08014F38 @ =0x000001DF
	cmp r1, r0
	bgt _08014F3C
	movs r0, #0x80
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	movs r0, #0x78
	str r0, [r2, #0x4c]
	movs r0, #0x50
	b _08014F4C
	.align 2, 0
_08014F38: .4byte 0x000001DF
_08014F3C:
	movs r0, #0x40
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	movs r0, #0xb4
	lsls r0, r0, #1
	str r0, [r2, #0x4c]
	movs r0, #0xb4
	lsls r0, r0, #2
_08014F4C:
	str r0, [r2, #0x50]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08014F54:
	pop {r0}
	bx r0

