	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08090b24
FUN_08090b24: @ 0x08090B24
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090B32
	b _08090C54
_08090B32:
	lsls r0, r0, #2
	ldr r1, _08090B3C @ =_08090B40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090B3C: .4byte _08090B40
_08090B40: @ jump table
	.4byte _08090B64 @ case 0
	.4byte _08090B7C @ case 1
	.4byte _08090BA0 @ case 2
	.4byte _08090BB8 @ case 3
	.4byte _08090BE0 @ case 4
	.4byte _08090C00 @ case 5
	.4byte _08090C12 @ case 6
	.4byte _08090C30 @ case 7
	.4byte _08090C3E @ case 8
_08090B64:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090B98 @ =0x08369668
	bl SetDDP
	ldr r1, _08090B9C @ =0x00007E0E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090B7C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
	.align 2, 0
_08090B98: .4byte sCollisions+(4*24)
_08090B9C: .4byte 0x00007E0E
_08090BA0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090C54
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
_08090BB8:
	ldr r1, _08090BF8 @ =0x00007E0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08090BFC @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0809118c
	movs r0, #0x2c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090BE0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
	.align 2, 0
_08090BF8: .4byte 0x00007E0F
_08090BFC: .4byte 0xFFFFE400
_08090C00:
	ldr r1, _08090C2C @ =0x00007E10
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C12:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090C24
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C24:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08090C54
	.align 2, 0
_08090C2C: .4byte 0x00007E10
_08090C30:
	ldr r1, _08090C5C @ =0x00007E11
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C3E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	movs r0, #0
	strb r0, [r4, #0xd]
_08090C52:
	strb r0, [r4, #0xe]
_08090C54:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090C5C: .4byte 0x00007E11

