	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08067f78
FUN_08067f78: @ 0x08067F78
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08067F88
	cmp r4, #1
	beq _08067F9A
	b _08067FE4
_08067F88:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067FD4 @ =sCollisions+(24*3)
	bl SetDDP
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067F9A:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067FAA
	str r1, [r5, #0x60]
_08067FAA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08067FDC
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	ldr r1, _08067FD8 @ =0xFFFFF200
	b _08067FE0
	.align 2, 0
_08067FD4: .4byte sCollisions+(24*3)
_08067FD8: .4byte 0xFFFFF200
_08067FDC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
_08067FE0:
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08067FE4:
	adds r6, r5, #0
	adds r6, #0xbc
	ldr r0, [r6]
	bl isKilled
	cmp r0, #0
	beq _0806800A
	movs r4, #0
	str r4, [r6]
	adds r0, r5, #0
	adds r0, #0xc0
	strb r4, [r0]
	subs r0, #0x4c
	ldr r1, _08068010 @ =sCollisions+48
	bl SetDDP
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_0806800A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068010: .4byte sCollisions+48
