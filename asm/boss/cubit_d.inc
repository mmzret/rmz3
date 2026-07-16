	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitNeutral
cubitNeutral: @ 0x08052C7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08052C90
	cmp r0, #1
	beq _08052D00
	b _08052EEC
_08052C90:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08052CB8
	ldr r1, _08052CB0 @ =0x0000B001
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08052CB4 @ =sCollisions+(24*1)
	bl SetDDP
	b _08052CCA
	.align 2, 0
_08052CB0: .4byte 0x0000B001
_08052CB4: .4byte sCollisions+(24*1)
_08052CB8:
	ldr r1, _08052CDC @ =0x0000B002
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08052CE0 @ =sCollisions+(24*1)
	bl SetDDP
_08052CCA:
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _08052CE4
	movs r0, #1
	strb r0, [r6, #0x12]
	movs r0, #0x7f
	strb r0, [r6, #0xf]
	b _08052CE8
	.align 2, 0
_08052CDC: .4byte 0x0000B002
_08052CE0: .4byte sCollisions+(24*1)
_08052CE4:
	movs r0, #0x10
	strb r0, [r6, #0x12]
_08052CE8:
	movs r0, #0
	strb r0, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0x5c
	str r0, [r1, #4]
	str r0, [r6, #0x5c]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08052D00:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08052D30
	adds r0, r6, #0
	bl cubit_08054688
	ldrb r0, [r6, #0x13]
	adds r0, #4
	strb r0, [r6, #0x13]
	ldr r1, _08052D2C @ =gSineTable
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _08052D36
	.align 2, 0
_08052D2C: .4byte gSineTable
_08052D30:
	adds r0, r6, #0
	bl cubit_08054688
_08052D36:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	bne _08052D44
	b _08052EEC
_08052D44:
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08052D50
	b _08052EEC
_08052D50:
	ldrb r0, [r6, #0xf]
	cmp r0, #0x7f
	bne _08052D90
	ldr r2, _08052D84 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052D88 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052D8C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r2, r0, #0x11
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne _08052D90
	movs r1, #6
	strb r1, [r6, #0xd]
	strb r2, [r6, #0xe]
	adds r7, r6, #0
	adds r7, #0xb5
	movs r2, #0xb6
	adds r2, r2, r6
	mov r8, r2
	b _08052EE0
	.align 2, 0
_08052D84: .4byte RNG_0202f388
_08052D88: .4byte 0x000343FD
_08052D8C: .4byte 0x00269EC3
_08052D90:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r7, r0, #0
	mov r8, r1
	cmp r3, r2
	bne _08052E68
	ldr r0, _08052DFC @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08052E10
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052E00 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052E04 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052E08 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052E0C @ =CubitEXModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _08052EDA
	adds r0, r6, #0
	movs r2, #1
	bl cubit_080545cc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08052EDA
	.align 2, 0
_08052DFC: .4byte gScore
_08052E00: .4byte RNG_0202f388
_08052E04: .4byte 0x000343FD
_08052E08: .4byte 0x00269EC3
_08052E0C: .4byte CubitEXModes
_08052E10:
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052E58 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052E5C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052E60 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052E64 @ =CubitModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _08052EDA
	adds r0, r6, #0
	movs r2, #0
	bl cubit_080545cc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08052EDA
	.align 2, 0
_08052E58: .4byte RNG_0202f388
_08052E5C: .4byte 0x000343FD
_08052E60: .4byte 0x00269EC3
_08052E64: .4byte CubitModes
_08052E68:
	ldr r0, _08052E94 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08052EA8
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052E98 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052E9C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052EA0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052EA4 @ =CubitEXModes
	b _08052EC6
	.align 2, 0
_08052E94: .4byte gScore
_08052E98: .4byte RNG_0202f388
_08052E9C: .4byte 0x000343FD
_08052EA0: .4byte 0x00269EC3
_08052EA4: .4byte CubitEXModes
_08052EA8:
	adds r0, r6, #0
	bl cubit_08054674
	adds r3, r0, #0
	ldr r2, _08052EF8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08052EFC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08052F00 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08052F04 @ =CubitModes
_08052EC6:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
_08052EDA:
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
_08052EE0:
	movs r0, #0
	strb r0, [r6, #0xf]
	ldrb r0, [r7]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r7]
_08052EEC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052EF8: .4byte RNG_0202f388
_08052EFC: .4byte 0x000343FD
_08052F00: .4byte 0x00269EC3
_08052F04: .4byte CubitModes

