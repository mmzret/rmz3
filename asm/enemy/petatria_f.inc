	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08090c64
FUN_08090c64: @ 0x08090C64
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090C72
	b _08090D96
_08090C72:
	lsls r0, r0, #2
	ldr r1, _08090C7C @ =_08090C80
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090C7C: .4byte _08090C80
_08090C80: @ jump table
	.4byte _08090CA4 @ case 0
	.4byte _08090CBC @ case 1
	.4byte _08090D52 @ case 2
	.4byte _08090CDC @ case 3
	.4byte _08090D20 @ case 4
	.4byte _08090D40 @ case 5
	.4byte _08090D52 @ case 6
	.4byte _08090D70 @ case 7
	.4byte _08090D7E @ case 8
_08090CA4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090CD4 @ =0x083696B0
	bl SetDDP
	ldr r1, _08090CD8 @ =0x00007E12
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090CBC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	b _08090D30
	.align 2, 0
_08090CD4: .4byte sCollisions+(7*24)
_08090CD8: .4byte 0x00007E12
_08090CDC:
	ldr r1, _08090CF8 @ =0x00007E13
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #1
	bne _08090CFC
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	b _08090D00
	.align 2, 0
_08090CF8: .4byte 0x00007E13
_08090CFC:
	ldr r0, [r4, #0x54]
	ldr r1, _08090D38 @ =0xFFFFFC00
_08090D00:
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08090D3C @ =0xFFFFE700
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
_08090D20:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
_08090D30:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08090D96
	.align 2, 0
_08090D38: .4byte 0xFFFFFC00
_08090D3C: .4byte 0xFFFFE700
_08090D40:
	ldr r1, _08090D6C @ =0x00007E14
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D52:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090D64
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D64:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08090D96
	.align 2, 0
_08090D6C: .4byte 0x00007E14
_08090D70:
	ldr r1, _08090DA0 @ =0x00007E15
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D7E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08090D96:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090DA0: .4byte 0x00007E15

