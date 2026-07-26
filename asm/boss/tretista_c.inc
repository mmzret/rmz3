	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretistaNeutral
tretistaNeutral: @ 0x0804E090
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0804E116
	cmp r0, #1
	bgt _0804E0AA
	cmp r0, #0
	beq _0804E0B0
	b _0804E3E4
_0804E0AA:
	cmp r0, #2
	beq _0804E158
	b _0804E3E4
_0804E0B0:
	ldrb r0, [r6, #0xd]
	adds r1, r6, #0
	adds r1, #0xe1
	strb r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _0804E0D4
	ldr r1, _0804E0D0 @ =0x0000AB09
	adds r0, r6, #0
	bl SetMotion
	b _0804E0DC
	.align 2, 0
_0804E0D0: .4byte 0x0000AB09
_0804E0D4:
	ldr r1, _0804E104 @ =0x0000AB0D
	adds r0, r6, #0
	bl SetMotion
_0804E0DC:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804E108 @ =sCollisions+(24*1)
	bl SetDDP
	movs r1, #0
	str r1, [r6, #0x60]
	str r1, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r1, [r0, #4]
	str r1, [r6, #0x64]
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _0804E10C
	movs r0, #1
	strb r0, [r6, #0x13]
	strb r1, [r6, #0xf]
	b _0804E110
	.align 2, 0
_0804E104: .4byte 0x0000AB0D
_0804E108: .4byte sCollisions+(24*1)
_0804E10C:
	movs r0, #0x14
	strb r0, [r6, #0x13]
_0804E110:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804E116:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804E130
	str r1, [r6, #0x68]
_0804E130:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r2
	ble _0804E14A
	ldr r1, _0804E154 @ =0x0000AB09
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804E14A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _0804E3E4
	.align 2, 0
_0804E154: .4byte 0x0000AB09
_0804E158:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	bl FUN_0804ff5c
	ldr r0, [r6, #0x70]
	ldr r1, _0804E234 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _0804E238 @ =0x00080200
	cmp r0, r1
	bne _0804E180
	movs r0, #0xd4
	bl PlaySound
_0804E180:
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804E190
	str r1, [r6, #0x68]
_0804E190:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r4
	ble _0804E19E
	str r4, [r6, #0x58]
_0804E19E:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _0804E1AE
	b _0804E3E4
_0804E1AE:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0804E1B6
	b _0804E3E4
_0804E1B6:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0804E1C4
	b _0804E3E4
_0804E1C4:
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
	bne _0804E2AC
	ldr r0, _0804E23C @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804E250
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E240 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E244 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E248 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E24C @ =TretistaEXModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r4, r0
	beq _0804E224
	b _0804E31E
_0804E224:
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl tretista_0804fecc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0804E31E
	.align 2, 0
_0804E234: .4byte 0x00FFFF00
_0804E238: .4byte 0x00080200
_0804E23C: .4byte gScore
_0804E240: .4byte RNG_0202f388
_0804E244: .4byte 0x000343FD
_0804E248: .4byte 0x00269EC3
_0804E24C: .4byte TretistaEXModes
_0804E250:
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E29C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E2A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E2A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E2A8 @ =TretistaModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r4, r0
	bne _0804E31E
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl tretista_0804fecc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0804E31E
	.align 2, 0
_0804E29C: .4byte RNG_0202f388
_0804E2A0: .4byte 0x000343FD
_0804E2A4: .4byte 0x00269EC3
_0804E2A8: .4byte TretistaModes
_0804E2AC:
	ldr r0, _0804E2D8 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804E2EC
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E2DC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E2E0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E2E4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E2E8 @ =TretistaEXModes
	b _0804E30A
	.align 2, 0
_0804E2D8: .4byte gScore
_0804E2DC: .4byte RNG_0202f388
_0804E2E0: .4byte 0x000343FD
_0804E2E4: .4byte 0x00269EC3
_0804E2E8: .4byte TretistaEXModes
_0804E2EC:
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E344 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E348 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E34C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E350 @ =TretistaModes
_0804E30A:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
_0804E31E:
	strb r4, [r6, #0xd]
	strb r7, [r6, #0xe]
	subs r0, r4, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804E3B0
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	ldr r1, [r6, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0804E358
	ldr r0, _0804E354 @ =0x000077FF
	cmp r2, r0
	ble _0804E360
	b _0804E378
	.align 2, 0
_0804E344: .4byte RNG_0202f388
_0804E348: .4byte 0x000343FD
_0804E34C: .4byte 0x00269EC3
_0804E350: .4byte TretistaModes
_0804E354: .4byte 0x000077FF
_0804E358:
	subs r1, r1, r0
	ldr r0, _0804E370 @ =0x000077FF
	cmp r1, r0
	bgt _0804E378
_0804E360:
	ldr r0, _0804E374 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	bge _0804E3B0
	b _0804E3A8
	.align 2, 0
_0804E370: .4byte 0x000077FF
_0804E374: .4byte pZero2
_0804E378:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	ldr r1, [r6, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0804E394
	ldr r0, _0804E390 @ =0x000077FF
	cmp r2, r0
	ble _0804E39C
	b _0804E3B0
	.align 2, 0
_0804E390: .4byte 0x000077FF
_0804E394:
	subs r1, r1, r0
	ldr r0, _0804E3C4 @ =0x000077FF
	cmp r1, r0
	bgt _0804E3B0
_0804E39C:
	ldr r0, _0804E3C8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _0804E3B0
_0804E3A8:
	movs r4, #5
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
_0804E3B0:
	cmp r4, #5
	bne _0804E3D0
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	cmp r3, #0
	bne _0804E3CC
	strb r3, [r6, #0xf]
	b _0804E3D0
	.align 2, 0
_0804E3C4: .4byte 0x000077FF
_0804E3C8: .4byte pZero2
_0804E3CC:
	movs r0, #1
	strb r0, [r6, #0xf]
_0804E3D0:
	adds r0, r6, #0
	adds r0, #0xe2
	movs r1, #0
	strb r1, [r0]
	mov r1, r8
	ldrb r0, [r1]
	mov r1, sb
	strb r0, [r1]
	mov r0, r8
	strb r4, [r0]
_0804E3E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
