	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
