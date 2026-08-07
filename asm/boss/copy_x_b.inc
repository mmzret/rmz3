	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start copyxMode11
copyxMode11: @ 0x08055EF8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08055F6E
	ldr r1, _08055F54 @ =0x0000B308
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r3, #0
	ldr r0, _08055F58 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055F1E
	movs r3, #1
_08055F1E:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055F30
	movs r3, #1
_08055F30:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08055F5C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08055F62
	.align 2, 0
_08055F54: .4byte 0x0000B308
_08055F58: .4byte pZero2
_08055F5C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08055F62:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08055FA8 @ =sCollisions
	bl SetDDP
_08055F6E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	adds r2, #0x40
	str r2, [r4, #0x60]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _08055FA2
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xc
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08055FA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055FA8: .4byte sCollisions

