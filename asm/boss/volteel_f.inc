	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelMode6
volteelMode6: @ 0x080449F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08044A00
	b _08044CAC
_08044A00:
	lsls r0, r0, #2
	ldr r1, _08044A0C @ =_08044A10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044A0C: .4byte _08044A10
_08044A10: @ jump table
	.4byte _08044A24 @ case 0
	.4byte _08044BA2 @ case 1
	.4byte _08044C4E @ case 2
	.4byte _08044C6E @ case 3
	.4byte _08044CA4 @ case 4
_08044A24:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _08044A58 @ =pZero2
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r3, [r0, #0x54]
	ldr r0, [r1]
	subs r2, r3, r0
	adds r7, r1, #0
	cmp r2, #0
	bgt _08044A42
	subs r2, r0, r3
_08044A42:
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r5, [r0]
	subs r1, r3, r5
	adds r6, r0, #0
	cmp r1, #0
	ble _08044A5C
	cmp r2, r1
	bgt _08044A62
	b _08044A96
	.align 2, 0
_08044A58: .4byte pZero2
_08044A5C:
	subs r0, r5, r3
	cmp r2, r0
	ble _08044A96
_08044A62:
	ldr r0, [r6]
	str r0, [r4, #0x54]
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r4, #0x64]
	adds r2, r4, #0
	adds r2, #0xca
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	subs r2, #0x80
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	b _08044AC2
_08044A96:
	ldr r0, [r7]
	str r0, [r4, #0x54]
	ldr r0, [r6]
	ldr r2, _08044BF0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0xca
	movs r0, #3
	strb r0, [r1]
	subs r1, #0x7e
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
_08044AC2:
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #6
	adds r0, r1, r2
	str r0, [r4, #0x58]
	ldr r0, _08044BF4 @ =0x7FFFFFFF
	str r0, [r4, #0x68]
	ldr r0, [r4, #0x64]
	ldr r2, _08044BF8 @ =0xFFFFD400
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bge _08044B02
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _08044BFC @ =0xFFFFB000
	adds r0, r0, r1
	cmp r2, r0
	ble _08044B02
	str r2, [r4, #0x68]
_08044B02:
	ldr r0, [r4, #0x64]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _08044BFC @ =0xFFFFB000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bge _08044B2C
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _08044BFC @ =0xFFFFB000
	adds r0, r0, r1
	cmp r2, r0
	ble _08044B2C
	str r2, [r4, #0x68]
_08044B2C:
	ldr r0, [r4, #0x64]
	ldr r2, _08044C00 @ =0xFFFFEE00
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _08044BFC @ =0xFFFFB000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bge _08044B54
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _08044BFC @ =0xFFFFB000
	adds r0, r0, r1
	cmp r2, r0
	ble _08044B54
	str r2, [r4, #0x68]
_08044B54:
	ldr r0, [r4, #0x64]
	movs r1, #0x50
	strb r1, [r4, #0x12]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x50
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r2, #0xc8
	lsls r2, r2, #8
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	subs r2, r2, r0
	adds r0, r2, #0
	movs r1, #0x50
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x4f
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	movs r0, #0x7a
	bl PlaySound
	ldr r1, _08044C04 @ =0x0000A512
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044C08 @ =sCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044BA2:
	ldr r2, [r4, #0x60]
	adds r2, #0x10
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r5, _08044C0C @ =0x0000A513
	cmp r0, r5
	beq _08044C2C
	ldrb r0, [r4, #0x13]
	ldrb r1, [r4, #0x12]
	lsrs r0, r0, #1
	cmp r1, r0
	bhs _08044C14
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044C10 @ =0x08362498
	bl SetDDP
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetMotion
	b _08044C2C
	.align 2, 0
_08044BF0: .4byte 0xFFFFC000
_08044BF4: .4byte 0x7FFFFFFF
_08044BF8: .4byte 0xFFFFD400
_08044BFC: .4byte 0xFFFFB000
_08044C00: .4byte 0xFFFFEE00
_08044C04: .4byte 0x0000A512
_08044C08: .4byte sCollisions
_08044C0C: .4byte 0x0000A513
_08044C10: .4byte sCollisions+(15*24)
_08044C14:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08044C24
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08044C2A
_08044C24:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08044C2A:
	strb r0, [r4, #0xa]
_08044C2C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08044C42
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044C42:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08044CAC
	subs r0, #1
	strb r0, [r4, #0x12]
	b _08044CAC
_08044C4E:
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08044CA0 @ =0x0000A502
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044C6E:
	ldr r2, [r4, #0x60]
	adds r2, #0x10
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08044C98
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08044CAC
_08044C98:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08044CAC
	.align 2, 0
_08044CA0: .4byte 0x0000A502
_08044CA4:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08044CAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

