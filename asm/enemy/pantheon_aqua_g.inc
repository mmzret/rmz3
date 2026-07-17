	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08073004
FUN_08073004: @ 0x08073004
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08073014
	cmp r5, #1
	beq _08073026
	b _080730A0
_08073014:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807306C @ =0x08366C28
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08073026:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08073036
	str r1, [r4, #0x60]
_08073036:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08073098
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	subs r0, r1, r0
	cmp r0, #0
	ble _08073074
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	subs r1, r1, r0
	ldr r0, _08073070 @ =0x000006FF
	cmp r1, r0
	ble _08073084
	b _080730A0
	.align 2, 0
_0807306C: .4byte sCollisions+(1*24)
_08073070: .4byte 0x000006FF
_08073074:
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _08073094 @ =0x000006FF
	cmp r0, r1
	bgt _080730A0
_08073084:
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	b _0807309E
	.align 2, 0
_08073094: .4byte 0x000006FF
_08073098:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
_0807309E:
	str r0, [r4, #0x58]
_080730A0:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _080730C0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080730C8 @ =sCollisions
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080730C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080730C8: .4byte sCollisions

