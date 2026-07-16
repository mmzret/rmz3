	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelNeutral
volteelNeutral: @ 0x080439D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r2, [r6, #0xe]
	cmp r2, #1
	bne _080439E6
	b _08043AEC
_080439E6:
	cmp r2, #1
	bgt _080439F0
	cmp r2, #0
	beq _080439F8
	b _08043D94
_080439F0:
	cmp r2, #2
	bne _080439F6
	b _08043B50
_080439F6:
	b _08043D94
_080439F8:
	adds r3, r6, #0
	adds r3, #0x49
	ldrb r1, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _08043A40
	ldr r0, [r6, #0x54]
	ldr r2, _08043A58 @ =0xFFFFEE00
	adds r0, r0, r2
	bl FUN_0800a05c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _08043A40
	ldr r0, [r6, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	bl FUN_0800a05c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _08043A60
_08043A40:
	movs r1, #0xa5
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08043A5C @ =sCollisions+(24*1)
	bl SetDDP
	b _08043A76
	.align 2, 0
_08043A58: .4byte 0xFFFFEE00
_08043A5C: .4byte sCollisions+(24*1)
_08043A60:
	ldr r1, _08043AB8 @ =0x0000A501
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl GotoMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08043ABC @ =0x08362378
	bl SetDDP
_08043A76:
	movs r2, #0
	str r2, [r6, #0x60]
	str r2, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r2, [r0, #4]
	str r2, [r6, #0x64]
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _08043AE2
	strb r2, [r6, #0xf]
	movs r3, #1
	strb r3, [r6, #0x13]
	ldr r0, _08043AC0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _08043AC4
	adds r0, r6, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	strb r0, [r6, #0xa]
	b _08043AE6
	.align 2, 0
_08043AB8: .4byte 0x0000A501
_08043ABC: .4byte sCollisions+(3*24)
_08043AC0: .4byte pZero2
_08043AC4:
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	b _08043AE6
_08043AE2:
	movs r0, #0x1e
	strb r0, [r6, #0x13]
_08043AE6:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08043AEC:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08043B48 @ =0x0000A501
	cmp r0, r1
	bne _08043B38
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r6, #0x68]
	adds r0, #0x10
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08043B18
	str r1, [r6, #0x68]
_08043B18:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r2
	ble _08043B3E
	movs r1, #0xa5
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08043B4C @ =sCollisions+(24*1)
	bl SetDDP
_08043B38:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08043B3E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _08043D94
	.align 2, 0
_08043B48: .4byte 0x0000A501
_08043B4C: .4byte sCollisions+(24*1)
_08043B50:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r4, _08043C7C @ =0x7FFFFFFF
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08043B7C
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043C80 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043B7C
	adds r4, r1, #0
	adds r5, r4, #0
_08043B7C:
	ldr r0, [r6, #0x54]
	ldr r1, _08043C84 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08043BA0
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043C80 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043BA0
	adds r4, r1, #0
	adds r5, r4, #0
_08043BA0:
	ldr r0, [r6, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08043BC4
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043C80 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043BC4
	adds r5, r1, #0
_08043BC4:
	adds r0, r6, #0
	bl volteel_08045abc
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x68]
	adds r0, #0x10
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08043BE0
	str r1, [r6, #0x68]
_08043BE0:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r5
	ble _08043BEE
	str r5, [r6, #0x58]
_08043BEE:
	ldr r0, [r6, #0x58]
	cmp r0, r5
	beq _08043BF6
	b _08043D94
_08043BF6:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _08043BFE
	b _08043D94
_08043BFE:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08043C0C
	b _08043D94
_08043C0C:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	mov r8, r0
	mov sb, r1
	cmp r3, r2
	bne _08043CF8
	ldr r0, _08043C88 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08043C9C
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043C8C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043C90 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043C94 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043C98 @ =VolteelEXModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r4, r0
	beq _08043C6C
	b _08043D6A
_08043C6C:
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08043D6A
	.align 2, 0
_08043C7C: .4byte 0x7FFFFFFF
_08043C80: .4byte 0xFFFFB000
_08043C84: .4byte 0xFFFFEE00
_08043C88: .4byte gScore
_08043C8C: .4byte RNG_0202f388
_08043C90: .4byte 0x000343FD
_08043C94: .4byte 0x00269EC3
_08043C98: .4byte VolteelEXModes
_08043C9C:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043CE8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043CEC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043CF0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043CF4 @ =VolteelModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r4, r0
	bne _08043D6A
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08043D6A
	.align 2, 0
_08043CE8: .4byte RNG_0202f388
_08043CEC: .4byte 0x000343FD
_08043CF0: .4byte 0x00269EC3
_08043CF4: .4byte VolteelModes
_08043CF8:
	ldr r0, _08043D24 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08043D38
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043D28 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043D2C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043D30 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043D34 @ =VolteelEXModes
	b _08043D56
	.align 2, 0
_08043D24: .4byte gScore
_08043D28: .4byte RNG_0202f388
_08043D2C: .4byte 0x000343FD
_08043D30: .4byte 0x00269EC3
_08043D34: .4byte VolteelEXModes
_08043D38:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043DA0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043DA4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043DA8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043DAC @ =VolteelModes
_08043D56:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
_08043D6A:
	strb r4, [r6, #0xd]
	strb r7, [r6, #0xe]
	adds r0, r6, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, r6, #0
	adds r1, #0xa4
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _08043D8A
	movs r4, #5
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
_08043D8A:
	mov r1, r8
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	strb r4, [r1]
_08043D94:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043DA0: .4byte RNG_0202f388
_08043DA4: .4byte 0x000343FD
_08043DA8: .4byte 0x00269EC3
_08043DAC: .4byte VolteelModes

