	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099d88
FUN_08099d88: @ 0x08099D88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099D98
	cmp r5, #1
	beq _08099DAC
	b _08099DF2
_08099D98:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099E18 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099DAC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099DBC
	str r1, [r4, #0x60]
_08099DBC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099E1C @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099DE8
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099DF2
_08099DE8:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099DF2:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099E10
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099E10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099E18: .4byte sCollisions+(6*24)
_08099E1C: .4byte 0xFFFFF600

	thumb_func_start cattatank_08099e20
cattatank_08099e20: @ 0x08099E20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _08099EAA
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08099EAA
	ldr r2, _08099E6C @ =0x0836A670
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099E84
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E70
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	movs r0, #7
	b _08099E7E
	.align 2, 0
_08099E6C: .4byte sElementCoords
_08099E70:
	cmp r1, #0x30
	bne _08099EAA
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #2
	strb r1, [r0]
	movs r0, #9
_08099E7E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08099EAA
_08099E84:
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E9E
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	b _08099EAA
_08099E9E:
	cmp r1, #0x30
	bne _08099EAA
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
_08099EAA:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08099eb4
FUN_08099eb4: @ 0x08099EB4
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _08099ECC
	cmp r0, #0xe
	beq _08099ECC
	cmp r0, #0xf
	bne _08099EF6
_08099ECC:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099EF6
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _08099EEE
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xff
	b _08099EF4
_08099EEE:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xfe
_08099EF4:
	strb r0, [r1]
_08099EF6:
	ldr r0, [r3, #4]
	ldr r1, _08099F28 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08099F2C
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099F4E
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099F20
	adds r0, r4, #0
	bl IsFrozen
_08099F20:
	movs r1, #0
	movs r0, #6
	b _08099F4A
	.align 2, 0
_08099F28: .4byte 0x000200FF
_08099F2C:
	ldr r4, [r2, #0x2c]
	ldr r0, [r2, #4]
	ldrb r0, [r0]
	cmp r0, #2
	bne _08099F4E
	ldrb r0, [r3, #6]
	cmp r0, #0x40
	beq _08099F4E
	adds r0, r4, #0
	bl IsFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08099F4E
	movs r0, #5
_08099F4A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099F4E:
	pop {r4, r5}
	pop {r0}
	bx r0

