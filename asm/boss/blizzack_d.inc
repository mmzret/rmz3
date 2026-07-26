	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blizzackNeutral
blizzackNeutral: @ 0x08059E60
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08059E88
	movs r1, #0xb4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	strh r1, [r0]
	strb r2, [r4, #0xe]
_08059E88:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r3, #0
	ldr r0, _08059ED4 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08059E9E
	movs r3, #1
_08059E9E:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08059EB0
	movs r3, #1
_08059EB0:
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
	beq _08059ED8
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08059EDE
	.align 2, 0
_08059ED4: .4byte pZero2
_08059ED8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08059EDE:
	strb r0, [r4, #0xa]
	ldr r0, _08059F44 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r3, r1, r0
	cmp r3, #0
	bge _08059EF0
	subs r3, r0, r1
_08059EF0:
	ldr r2, _08059F48 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08059F4C @ =0x000343FD
	muls r0, r1, r0
	ldr r6, _08059F50 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r2, r0, #0x11
	movs r0, #0x1f
	ands r2, r0
	ldr r0, _08059F54 @ =0x000037FF
	cmp r3, r0
	bgt _08059F66
	cmp r2, #7
	bgt _08059F14
	b _0805A0F8
_08059F14:
	ldr r0, _08059F58 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08059F5C
	cmp r2, #0xf
	bgt _08059F24
	b _0805A07C
_08059F24:
	adds r0, r4, #0
	adds r0, #0xd0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa4
	asrs r0, r0, #1
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _08059F42
	b _0805A070
_08059F42:
	b _0805A07C
	.align 2, 0
_08059F44: .4byte pZero2
_08059F48: .4byte RNG_0202f388
_08059F4C: .4byte 0x000343FD
_08059F50: .4byte 0x00269EC3
_08059F54: .4byte 0x000037FF
_08059F58: .4byte gScore
_08059F5C:
	movs r0, #7
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	b _0805A100
_08059F66:
	ldr r0, _08059F94 @ =0x00004FFF
	cmp r3, r0
	bgt _0805A022
	adds r0, r4, #0
	adds r0, #0xd0
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsrs r0, r3, #0x1f
	adds r0, r3, r0
	adds r5, r4, #0
	adds r5, #0xa4
	asrs r0, r0, #1
	movs r6, #0
	ldrsh r1, [r5, r6]
	cmp r0, r1
	ble _08059FB6
	cmp r2, #7
	bgt _08059F98
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
	.align 2, 0
_08059F94: .4byte 0x00004FFF
_08059F98:
	cmp r2, #0x13
	ble _08059F9E
	b _0805A0F8
_08059F9E:
	adds r0, r4, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08059FAE
	b _0805A0EA
_08059FAE:
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_08059FB6:
	adds r0, r3, #0
	cmp r0, #0
	bge _08059FBE
	adds r0, #3
_08059FBE:
	asrs r0, r0, #2
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	ble _08059FF8
	cmp r2, #2
	ble _0805A0C6
	cmp r2, #7
	bgt _08059FDC
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_08059FDC:
	cmp r2, #0x13
	ble _08059FE2
	b _0805A0F8
_08059FE2:
	adds r0, r4, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0805A0EA
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_08059FF8:
	cmp r2, #5
	ble _0805A0C6
	cmp r2, #0xc
	bgt _0805A008
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A008:
	cmp r2, #0x18
	bgt _0805A0F8
	adds r0, r4, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0805A0EA
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A022:
	adds r0, r4, #0
	adds r0, #0xd0
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsrs r0, r3, #0x1f
	adds r0, r3, r0
	adds r5, r4, #0
	adds r5, #0xa4
	asrs r0, r0, #1
	movs r6, #0
	ldrsh r1, [r5, r6]
	cmp r0, r1
	ble _0805A082
	cmp r2, #5
	bgt _0805A048
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A048:
	cmp r2, #0xd
	bgt _0805A062
	adds r0, r4, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0805A0EA
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A062:
	cmp r2, #0x17
	ble _0805A0F8
	ldr r0, _0805A078 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0805A07C
_0805A070:
	movs r0, #0xa
	strb r0, [r4, #0xd]
	b _0805A100
	.align 2, 0
_0805A078: .4byte gScore
_0805A07C:
	movs r0, #7
	strb r0, [r4, #0xd]
	b _0805A100
_0805A082:
	adds r0, r3, #0
	cmp r0, #0
	bge _0805A08A
	adds r0, #3
_0805A08A:
	asrs r0, r0, #2
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	ble _0805A0C2
	cmp r2, #3
	ble _0805A0C6
	cmp r2, #0xd
	bgt _0805A0A8
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A0A8:
	cmp r2, #0x11
	bgt _0805A0F8
	adds r0, r4, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0805A0EA
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A0C2:
	cmp r2, #5
	bgt _0805A0CC
_0805A0C6:
	movs r0, #3
	strb r0, [r4, #0xd]
	b _0805A100
_0805A0CC:
	cmp r2, #0xc
	bgt _0805A0D8
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A0D8:
	cmp r2, #0x18
	bgt _0805A0F8
	adds r0, r4, #0
	adds r0, #0xe0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0805A0F0
_0805A0EA:
	movs r0, #0x11
	strb r0, [r4, #0xd]
	b _0805A100
_0805A0F0:
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #5
	b _0805A0FE
_0805A0F8:
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #0xd
_0805A0FE:
	strb r0, [r4, #0xf]
_0805A100:
	adds r0, r4, #0
	adds r0, #0xcc
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r3, r0, #0
	adds r2, r4, #0
	adds r2, #0xcd
	ldrb r6, [r4, #0xd]
	cmp r1, r6
	bne _0805A126
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0805A126
	movs r0, #2
	strb r0, [r4, #0xd]
	b _0805A136
_0805A126:
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xce
	strb r0, [r1]
	ldrb r0, [r3]
	strb r0, [r2]
	ldrb r0, [r4, #0xd]
	strb r0, [r3]
_0805A136:
	movs r0, #1
	strb r0, [r4, #0xe]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start blizzackPreAI
blizzackPreAI: @ 0x0805A140
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A16C
	movs r1, #0xb4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #0x20
	strb r0, [r4, #0x12]
_0805A16C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r3, #0
	ldr r0, _0805A1B8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805A182
	movs r3, #1
_0805A182:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805A194
	movs r3, #1
_0805A194:
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
	beq _0805A1BC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805A1C2
	.align 2, 0
_0805A1B8: .4byte pZero2
_0805A1BC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805A1C2:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805A1DA
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A1DA:
	pop {r4}
	pop {r0}
	bx r0

