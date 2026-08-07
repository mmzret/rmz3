	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shotcounter_08066be0
shotcounter_08066be0: @ 0x08066BE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08066BF0
	cmp r0, #1
	beq _08066C12
	b _08066D9A
_08066BF0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08066D2C @ =0x08365E54
	bl SetDDP
	ldr r0, _08066D30 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0xf]
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08066C12:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	adds r1, r1, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066C3E
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	bne _08066C3E
	b _08066D7C
_08066C3E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	ldr r1, _08066D34 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066C6C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	bne _08066C6C
	b _08066D7C
_08066C6C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	ldr r2, _08066D34 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066C98
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08066D7C
_08066C98:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	ldr r3, _08066D34 @ =0xFFFFF000
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	adds r1, r1, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066CC0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08066D7C
_08066CC0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r1, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	lsls r0, r2, #4
	subs r0, r2, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x60]
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08066CFC
	adds r1, r4, #0
	adds r1, #0xbf
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08066CFC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08066D9A
	adds r0, r4, #0
	adds r0, #0xb8
	str r1, [r0]
	ldr r2, [r5]
	cmp r2, #0
	beq _08066D70
	adds r0, #7
	ldrb r2, [r0]
	cmp r2, #1
	bne _08066D38
	subs r0, #0x1b
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	ble _08066D7C
	movs r0, #5
	b _08066D6A
	.align 2, 0
_08066D2C: .4byte sCollisions+(24*10)
_08066D30: .4byte pZero2
_08066D34: .4byte 0xFFFFF000
_08066D38:
	cmp r2, #2
	bne _08066D5C
	adds r0, r4, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	bgt _08066D58
	ldr r1, _08066D54 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08066D88
	.align 2, 0
_08066D54: .4byte gEnemyFnTable
_08066D58:
	movs r0, #7
	b _08066D6A
_08066D5C:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	ble _08066D7C
	movs r0, #1
_08066D6A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08066D9A
_08066D70:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	bgt _08066D94
_08066D7C:
	ldr r1, _08066D90 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08066D88:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _08066D9A
	.align 2, 0
_08066D90: .4byte gEnemyFnTable
_08066D94:
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_08066D9A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start shotcounter_08066da0
shotcounter_08066da0: @ 0x08066DA0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xc0
	ldr r5, [r6]
	cmp r5, #0
	bne _08066E2A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08066E2A
	ldr r2, _08066DEC @ =0x08365E84
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08066E04
	cmp r1, #0
	beq _08066E2A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08066DF0
	adds r0, r4, #0
	adds r0, #0xbf
	strb r7, [r0]
	movs r0, #5
	b _08066DFE
	.align 2, 0
_08066DEC: .4byte Coord_08365e84
_08066DF0:
	cmp r1, #0x30
	bne _08066E2A
	adds r1, r4, #0
	adds r1, #0xbf
	movs r0, #2
	strb r0, [r1]
	movs r0, #7
_08066DFE:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08066E2A
_08066E04:
	cmp r1, #0
	beq _08066E2A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08066E1E
	adds r0, r4, #0
	adds r0, #0xbf
	strb r7, [r0]
	b _08066E2A
_08066E1E:
	cmp r1, #0x30
	bne _08066E2A
	adds r1, r4, #0
	adds r1, #0xbf
	movs r0, #2
	strb r0, [r1]
_08066E2A:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

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

