	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080729ec
FUN_080729ec: @ 0x080729EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _08072A02
	b _08072E30
_08072A02:
	lsls r0, r0, #2
	ldr r1, _08072A0C @ =_08072A10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072A0C: .4byte _08072A10
_08072A10: @ jump table
	.4byte _08072A40 @ case 0
	.4byte _08072A5C @ case 1
	.4byte _08072B00 @ case 2
	.4byte _08072B12 @ case 3
	.4byte _08072B60 @ case 4
	.4byte _08072D06 @ case 5
	.4byte _08072B70 @ case 6
	.4byte _08072B8C @ case 7
	.4byte _08072BDC @ case 8
	.4byte _08072D06 @ case 9
	.4byte _08072D54 @ case 10
	.4byte _08072D70 @ case 11
_08072A40:
	ldr r1, _08072A80 @ =0x00002702
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072A84 @ =sCollisions
	bl SetDDP
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072A5C:
	ldrb r1, [r7, #0x12]
	adds r1, #1
	strb r1, [r7, #0x12]
	lsls r1, r1, #0x18
	movs r0, #0xc0
	lsls r0, r0, #0x12
	ands r0, r1
	cmp r0, #0
	beq _08072A70
	b _08072D06
_08072A70:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08072A8C
	ldr r0, _08072A88 @ =0xFFFFF000
	b _08072A90
	.align 2, 0
_08072A80: .4byte 0x00002702
_08072A84: .4byte sCollisions
_08072A88: .4byte 0xFFFFF000
_08072A8C:
	movs r0, #0x80
	lsls r0, r0, #5
_08072A90:
	str r0, [sp]
	ldr r1, [r7, #0x54]
	ldr r0, [sp]
	adds r1, r1, r0
	ldr r4, [r7, #0x58]
	ldr r0, _08072AF0 @ =0xFFFFF000
	adds r4, r4, r0
	ldr r2, _08072AF4 @ =RNG_0202f388
	mov r8, r2
	ldr r0, [r2]
	ldr r3, _08072AF8 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _08072AFC @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r6, r0, #1
	lsrs r0, r0, #0x11
	movs r5, #7
	ands r0, r5
	subs r0, #3
	lsls r0, r0, #8
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r6, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r0, #3
	lsls r0, r0, #8
	adds r0, r0, r4
	str r0, [sp, #4]
	muls r1, r3, r1
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r2, r8
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl FUN_080ba8e8
	b _08072D06
	.align 2, 0
_08072AF0: .4byte 0xFFFFF000
_08072AF4: .4byte RNG_0202f388
_08072AF8: .4byte 0x000343FD
_08072AFC: .4byte 0x00269EC3
_08072B00:
	ldr r1, _08072B5C @ =0x00002703
	adds r0, r7, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072B12:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08072B4C
	b _08072D42
_08072B4C:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08072B58
	b _08072E30
_08072B58:
	b _08072D42
	.align 2, 0
_08072B5C: .4byte 0x00002703
_08072B60:
	ldr r1, _08072B6C @ =0x00002704
	adds r0, r7, #0
	bl SetMotion
	b _08072D00
	.align 2, 0
_08072B6C: .4byte 0x00002704
_08072B70:
	ldr r1, _08072BD4 @ =0x00002705
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072BD8 @ =0x08366C40
	bl SetDDP
	movs r0, #0x10
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072B8C:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08072BC6
	b _08072D42
_08072BC6:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08072BD2
	b _08072E30
_08072BD2:
	b _08072D42
	.align 2, 0
_08072BD4: .4byte 0x00002705
_08072BD8: .4byte sCollisions+(2*24)
_08072BDC:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08072BF0
	ldr r0, _08072BEC @ =0xFFFFE200
	b _08072BF4
	.align 2, 0
_08072BEC: .4byte 0xFFFFE200
_08072BF0:
	movs r0, #0xf0
	lsls r0, r0, #5
_08072BF4:
	str r0, [sp, #8]
	ldr r0, _08072C78 @ =0xFFFFE300
	add r4, sp, #8
	str r0, [r4, #4]
	ldr r0, [r7, #0x54]
	ldr r1, [sp, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	ldr r1, [r4, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	adds r0, r7, #0
	bl FUN_08073610
	ldr r1, _08072C7C @ =0x00002706
	adds r0, r7, #0
	bl SetMotion
	ldrb r2, [r7, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	adds r1, r4, #0
	bl CreateProjectile2
	movs r0, #0x63
	bl PlaySound
	movs r5, #0
	ldr r6, _08072C80 @ =RNG_0202f388
	mov sl, r4
	ldr r0, _08072C84 @ =0x000343FD
	mov sb, r0
_08072C3A:
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne _08072CFA
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	mov r8, r1
	cmp r0, #0
	bne _08072C90
	ldr r4, [r7, #0x54]
	ldr r1, _08072C88 @ =0xFFFFD000
	adds r4, r4, r1
	str r4, [sp, #8]
	ldr r0, [r6]
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _08072C8C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r4, r4, r0
	b _08072CBA
	.align 2, 0
_08072C78: .4byte 0xFFFFE300
_08072C7C: .4byte 0x00002706
_08072C80: .4byte RNG_0202f388
_08072C84: .4byte 0x000343FD
_08072C88: .4byte 0xFFFFD000
_08072C8C: .4byte 0x00269EC3
_08072C90:
	ldr r4, [r7, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r4, r4, r2
	str r4, [sp, #8]
	ldr r0, [r6]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r2, _08072D4C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r0, r0, r5
	lsls r0, r0, #8
	subs r4, r4, r0
_08072CBA:
	str r4, [sp, #8]
	ldr r2, [r7, #0x58]
	ldr r0, _08072D50 @ =0xFFFFE300
	adds r2, r2, r0
	ldr r0, [r6]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _08072D4C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	subs r0, #1
	lsls r0, r0, #8
	adds r2, r2, r0
	mov r0, sl
	str r2, [r0, #4]
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	mov r0, r8
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x1c
	movs r0, #1
	ands r2, r0
	mov r0, sl
	bl FUN_080ba940
_08072CFA:
	adds r5, #1
	cmp r5, #7
	ble _08072C3A
_08072D00:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072D06:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08072E30
_08072D42:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08072E30
	.align 2, 0
_08072D4C: .4byte 0x00269EC3
_08072D50: .4byte 0xFFFFE300
_08072D54:
	ldr r1, _08072DE8 @ =0x00002707
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072DEC @ =sCollisions
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072D70:
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08072E30
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _08072DBC
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072E30
_08072DBC:
	ldr r0, _08072DF0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08072DF4
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08072E16
	.align 2, 0
_08072DE8: .4byte 0x00002707
_08072DEC: .4byte sCollisions
_08072DF0: .4byte pZero2
_08072DF4:
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08072E16:
	adds r0, r7, #0
	bl FUN_08073500
	adds r2, r7, #0
	adds r2, #0xb9
	movs r1, #0
	strb r0, [r2]
	adds r2, #1
	movs r0, #0x1e
	strb r0, [r2]
	movs r0, #1
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_08072E30:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

