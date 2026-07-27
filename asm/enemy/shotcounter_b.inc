	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08066e34
FUN_08066e34: @ 0x08066E34
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _08066E4C
	cmp r0, #0xe
	beq _08066E4C
	cmp r0, #0xf
	bne _08066E76
_08066E4C:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08066E76
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _08066E6E
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #0xff
	b _08066E74
_08066E6E:
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #0xfe
_08066E74:
	strb r0, [r1]
_08066E76:
	ldr r0, [r3, #4]
	ldr r1, _08066F00 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08066F44
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08066F44
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08066EAC
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	bne _08066EAC
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #1
	strh r0, [r1]
_08066EAC:
	ldr r6, _08066F04 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r4, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _08066F08
	ldr r0, [r4, #0x64]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x68]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x68]
	b _08066F24
	.align 2, 0
_08066F00: .4byte 0x000200FF
_08066F04: .4byte pZero2
_08066F08:
	ldr r0, [r6]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08066F1C
	ldr r0, _08066F18 @ =0xFFFFFF00
	b _08066F20
	.align 2, 0
_08066F18: .4byte 0xFFFFFF00
_08066F1C:
	movs r0, #0x80
	lsls r0, r0, #1
_08066F20:
	str r0, [r4, #0x64]
	str r5, [r4, #0x68]
_08066F24:
	ldr r1, [r4, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08066F44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
