	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08068ebc
FUN_08068ebc: @ 0x08068EBC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08068ED6
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068F00 @ =0x083661BC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08068ED6:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08068EF8
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068F04 @ =0x083661A4
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08068EF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068F00: .4byte sCollisions+(12*24)
_08068F04: .4byte sCollisions+(11*24)
