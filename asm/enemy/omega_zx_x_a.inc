	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08092c5c
FUN_08092c5c: @ 0x08092C5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08092C7C
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bhi _08092C7C
	movs r0, #0xa
	strb r0, [r4, #0xe]
_08092C7C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _08092C84
	b _08092F04
_08092C84:
	lsls r0, r0, #2
	ldr r1, _08092C90 @ =_08092C94
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08092C90: .4byte _08092C94
_08092C94: @ jump table
	.4byte _08092CC4 @ case 0
	.4byte _08092D08 @ case 1
	.4byte _08092DE0 @ case 2
	.4byte _08092DF6 @ case 3
	.4byte _08092E74 @ case 4
	.4byte _08092F04 @ case 5
	.4byte _08092F04 @ case 6
	.4byte _08092F04 @ case 7
	.4byte _08092F04 @ case 8
	.4byte _08092F04 @ case 9
	.4byte _08092EC2 @ case 10
	.4byte _08092ED0 @ case 11
_08092CC4:
	ldr r1, _08092DC0 @ =0x0000B603
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _08092DC4 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08092DC8 @ =0x00001DFF
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldr r0, [r2, #0x54]
	str r0, [r4, #0x64]
	movs r0, #0x98
	lsls r0, r0, #1
	bl PlaySound
_08092D08:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	strb r1, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092DB2
	movs r5, #0
	ldr r2, _08092DCC @ =0x08369CCC
	mov sl, r2
	ldr r6, _08092DD0 @ =RNG_0202f388
	ldr r0, _08092DD4 @ =0x000343FD
	mov sb, r0
	ldr r1, _08092DD8 @ =0x00269EC3
	mov r8, r1
	movs r7, #7
_08092D52:
	adds r0, r5, #0
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #3
	mov r2, sl
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r1, [r6]
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	add r1, r8
	lsls r1, r1, #1
	lsrs r2, r1, #1
	str r2, [r6]
	lsrs r1, r1, #0x11
	ands r1, r7
	subs r1, #3
	adds r1, r1, r3
	lsls r1, r1, #8
	str r1, [sp]
	ldr r1, _08092DDC @ =0x08369CD0
	adds r0, r0, r1
	ldr r3, [r0]
	mov r0, sb
	muls r0, r2, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r7
	subs r0, #3
	adds r0, r0, r3
	lsls r0, r0, #8
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl FUN_080c4eac
	adds r5, #1
	cmp r5, #4
	ble _08092D52
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
_08092DB2:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xe]
	cmp r0, #1
	bhi _08092DBC
	b _08092F04
_08092DBC:
	b _08092E62
	.align 2, 0
_08092DC0: .4byte 0x0000B603
_08092DC4: .4byte gStageRun+232
_08092DC8: .4byte 0x00001DFF
_08092DCC: .4byte 0x08369CCC
_08092DD0: .4byte RNG_0202f388
_08092DD4: .4byte 0x000343FD
_08092DD8: .4byte 0x00269EC3
_08092DDC: .4byte 0x08369CD0
_08092DE0:
	ldr r1, _08092E6C @ =0x0000B602
	adds r0, r4, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r4, #0x12]
	movs r0, #8
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08092DF6:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08092F04
	subs r0, #1
	strb r0, [r4, #0x13]
	movs r5, #0xff
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092F04
	ldr r0, [r4, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r0, r1
	add r1, sp, #8
	str r0, [r1, #4]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080afe84
	ldr r0, _08092E70 @ =0x00000131
	bl PlaySound
	movs r0, #8
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08092F04
	subs r0, #1
	strb r0, [r4, #0x12]
	ands r0, r5
	cmp r0, #0
	bne _08092F04
_08092E62:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08092F04
	.align 2, 0
_08092E6C: .4byte 0x0000B602
_08092E70: .4byte 0x00000131
_08092E74:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r3, [r4, #0x28]
	ldr r1, [r0]
	ldr r0, [r3, #0x54]
	adds r1, r1, r0
	ldr r2, [r4, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r3, #0x58]
	adds r1, r1, r0
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #4
	beq _08092F04
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08092F04
_08092EC2:
	ldr r1, _08092F14 @ =0x0000B602
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08092ED0:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08092F04:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092F14: .4byte 0x0000B602

	thumb_func_start FUN_08092f18
FUN_08092f18: @ 0x08092F18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08092F38
	ldrb r0, [r5, #0xe]
	cmp r0, #0x13
	bhi _08092F38
	movs r0, #0x14
	strb r0, [r5, #0xe]
_08092F38:
	ldr r0, _08092F70 @ =gGameState
	ldr r1, _08092F74 @ =0x000064AC
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08092F5E
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _08092F54
	strb r2, [r5, #0xf]
_08092F54:
	ldrb r0, [r5, #0xe]
	cmp r0, #0x13
	bhi _08092F5E
	movs r0, #0x14
	strb r0, [r5, #0xe]
_08092F5E:
	ldrb r0, [r5, #0xe]
	cmp r0, #0x15
	bls _08092F66
	b _0809355C
_08092F66:
	lsls r0, r0, #2
	ldr r1, _08092F78 @ =_08092F7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08092F70: .4byte gGameState
_08092F74: .4byte 0x000064AC
_08092F78: .4byte _08092F7C
_08092F7C: @ jump table
	.4byte _08092FD4 @ case 0
	.4byte _08093000 @ case 1
	.4byte _0809304C @ case 2
	.4byte _080930DC @ case 3
	.4byte _080930F2 @ case 4
	.4byte _08093146 @ case 5
	.4byte _080932E0 @ case 6
	.4byte _0809355C @ case 7
	.4byte _0809355C @ case 8
	.4byte _0809355C @ case 9
	.4byte _08093498 @ case 10
	.4byte _080934BA @ case 11
	.4byte _0809355C @ case 12
	.4byte _0809355C @ case 13
	.4byte _0809355C @ case 14
	.4byte _0809355C @ case 15
	.4byte _0809355C @ case 16
	.4byte _0809355C @ case 17
	.4byte _0809355C @ case 18
	.4byte _0809355C @ case 19
	.4byte _08093510 @ case 20
	.4byte _08093528 @ case 21
_08092FD4:
	ldr r1, _0809303C @ =0x0000B603
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r5, #0x12]
	movs r0, #0x90
	lsls r0, r0, #5
	str r0, [r5, #0x5c]
	ldr r0, _08093040 @ =0xFFFFF800
	str r0, [r5, #0x60]
	ldr r0, _08093044 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _08093048 @ =0xFFFFF7FF
	adds r0, r0, r2
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08093000:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08093024
	b _0809355C
_08093024:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08093030
	b _0809355C
_08093030:
	movs r0, #0x98
	lsls r0, r0, #1
	bl PlaySound
	b _080934AE
	.align 2, 0
_0809303C: .4byte 0x0000B603
_08093040: .4byte 0xFFFFF800
_08093044: .4byte gStageRun+232
_08093048: .4byte 0xFFFFF7FF
_0809304C:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080930BE
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r0, r0, r3
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r7, #0xe0
	lsls r7, r7, #3
	adds r0, r0, r7
	str r0, [sp, #4]
	movs r4, #0
	ldr r7, _080930D8 @ =0x08369CF4
	add r6, sp, #8
_0809309E:
	ldr r0, [r7]
	lsls r0, r0, #8
	str r0, [sp, #8]
	ldr r0, [r7, #4]
	lsls r0, r0, #8
	str r0, [r6, #4]
	lsls r3, r4, #0x18
	lsrs r3, r3, #0x18
	adds r0, r5, #0
	mov r1, sp
	adds r2, r6, #0
	bl FUN_080c4f60
	adds r4, #1
	cmp r4, #5
	ble _0809309E
_080930BE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080930C6
	b _0809355C
_080930C6:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080930D2
	b _0809355C
_080930D2:
	movs r0, #0xe
	b _080934B0
	.align 2, 0
_080930D8: .4byte 0x08369CF4
_080930DC:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080930E4
	b _0809355C
_080930E4:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080930F0
	b _0809355C
_080930F0:
	b _080934B2
_080930F2:
	ldr r1, _0809325C @ =0x0000B602
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, _08093260 @ =gGameState
	ldr r1, _08093264 @ =0x000064AC
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093132
	ldr r0, [r5, #0x28]
	bl FUN_080b009c
	cmp r0, #0
	beq _0809311C
	str r5, [r0, #0x2c]
_0809311C:
	ldr r0, [r5, #0x28]
	bl CreateGhost83
	str r0, [r5, #0x2c]
	cmp r0, #0
	beq _0809312A
	str r5, [r0, #0x2c]
_0809312A:
	ldr r1, _08093268 @ =gPaletteManager
	ldr r2, _0809326C @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
_08093132:
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #0
	str r0, [r1]
	ldr r0, _08093270 @ =0x00000135
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08093146:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r1, [r4]
	movs r0, #0x88
	lsls r0, r0, #6
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4]
	asrs r1, r1, #9
	adds r0, r5, #0
	adds r0, #0x74
	movs r2, #0x17
	subs r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08093274 @ =0x08369A8C
	adds r1, r1, r2
	bl SetDDP
	ldr r2, _08093278 @ =u32_020302b0
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	subs r0, r0, r1
	asrs r6, r0, #9
	str r6, [r2]
	ldr r0, _08093260 @ =gGameState
	ldr r3, _08093264 @ =0x000064AC
	adds r3, r3, r0
	mov sb, r3
	ldr r0, [r3]
	ldrb r1, [r0, #0xa]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	mov r8, r4
	cmp r0, #0
	beq _080931F6
	ldr r4, _0809327C @ =gWindowRegBuffer
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x54]
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r2, _08093280 @ =gStageRun+232
	ldr r1, [r2, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	movs r3, #0xff
	ands r0, r3
	strh r0, [r4, #6]
	ldr r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r1, r1, r0
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	ldr r0, [r2, #0x3c]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r1, r2
	asrs r0, r0, #8
	subs r0, r0, r6
	ands r0, r3
	asrs r1, r1, #8
	adds r1, r6, r1
	lsls r1, r1, #8
	orrs r0, r1
	strh r0, [r4, #0xa]
_080931F6:
	ldr r3, _08093284 @ =u32_020302b4
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x58]
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r2, _08093280 @ =gStageRun+232
	ldr r1, [r2, #0x3c]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r3]
	ldr r3, _08093288 @ =u32_020302ac
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x54]
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r2, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r3]
	adds r0, r5, #0
	bl UpdateEntityAnim
	mov r2, sb
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _08093296
	ldr r1, _08093268 @ =gPaletteManager
	ldr r3, _0809326C @ =0x0000FFFF
	adds r0, r3, #0
	strh r0, [r1]
	ldrb r1, [r5, #0x12]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0809328C
	ldr r0, _0809327C @ =gWindowRegBuffer
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	strb r7, [r0, #0xd]
	b _08093296
	.align 2, 0
_0809325C: .4byte 0x0000B602
_08093260: .4byte gGameState
_08093264: .4byte 0x000064AC
_08093268: .4byte gPaletteManager
_0809326C: .4byte 0x0000FFFF
_08093270: .4byte 0x00000135
_08093274: .4byte 0x08369A8C
_08093278: .4byte u32_020302b0
_0809327C: .4byte gWindowRegBuffer
_08093280: .4byte gStageRun+232
_08093284: .4byte u32_020302b4
_08093288: .4byte u32_020302ac
_0809328C:
	ldr r2, _080932CC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080932D0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
_08093296:
	ldr r1, [r5, #0x2c]
	cmp r1, #0
	beq _080932B2
	ldr r0, _080932D4 @ =u32_020302ac
	ldr r0, [r0]
	str r0, [r1, #0x74]
	ldr r1, [r5, #0x2c]
	ldr r0, _080932D8 @ =u32_020302b4
	ldr r0, [r0]
	str r0, [r1, #0x78]
	ldr r1, [r5, #0x2c]
	ldr r0, _080932DC @ =u32_020302b0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
_080932B2:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	mov r7, r8
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080932C6
	b _0809355C
_080932C6:
	str r1, [r7]
	movs r0, #0x3c
	b _080934B0
	.align 2, 0
_080932CC: .4byte gWindowRegBuffer
_080932D0: .4byte 0x0000BFFF
_080932D4: .4byte u32_020302ac
_080932D8: .4byte u32_020302b4
_080932DC: .4byte u32_020302b0
_080932E0:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	adds r0, #0xbb
	str r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r6, r5, #0
	adds r6, #0xbc
	ldr r1, [r6]
	subs r1, #0x66
	str r1, [r6]
	asrs r1, r1, #9
	adds r4, r5, #0
	adds r4, #0x74
	movs r0, #0x17
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080933FC @ =0x08369A8C
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetDDP
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	str r4, [sp, #0x10]
	ldr r2, _08093400 @ =u32_020302b0
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #6
	subs r0, r0, r1
	asrs r0, r0, #9
	str r0, [r2]
	ldr r1, _08093404 @ =0x0203700C
	ldr r0, [r1]
	ldrb r1, [r0, #0xa]
	movs r3, #1
	mov sl, r3
	mov r0, sl
	ands r0, r1
	ldr r7, [r5, #0x54]
	mov sb, r7
	ldr r1, [r5, #0x58]
	str r1, [sp, #0x14]
	ldr r3, _08093408 @ =gStageRun+232
	mov ip, r3
	ldr r7, [r5, #0x5c]
	mov r8, r7
	ldr r6, [r5, #0x60]
	cmp r0, #0
	beq _0809339E
	ldr r4, _0809340C @ =gWindowRegBuffer
	mov r0, r8
	add r0, sb
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r3, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	movs r3, #0xff
	ands r0, r3
	strh r0, [r4, #6]
	ldr r7, [sp, #0x14]
	adds r1, r6, r7
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	mov r7, ip
	ldr r0, [r7, #0x3c]
	subs r1, r1, r0
	movs r7, #0x80
	lsls r7, r7, #6
	adds r0, r1, r7
	asrs r0, r0, #8
	ldr r2, [r2]
	subs r0, r0, r2
	ands r0, r3
	asrs r1, r1, #8
	adds r2, r2, r1
	lsls r2, r2, #8
	orrs r0, r2
	strh r0, [r4, #0xa]
_0809339E:
	ldr r2, _08093410 @ =u32_020302b4
	ldr r1, [sp, #0x14]
	adds r0, r6, r1
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r0, r0, r3
	mov r7, ip
	ldr r1, [r7, #0x3c]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r2]
	ldr r2, _08093414 @ =u32_020302ac
	mov r0, r8
	add r0, sb
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r7, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r2]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r2, _08093404 @ =0x0203700C
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08093436
	ldr r1, _08093418 @ =gPaletteManager
	ldr r3, _0809341C @ =0x0000FFFF
	adds r0, r3, #0
	strh r0, [r1]
	ldrb r1, [r5, #0x12]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08093424
	ldr r2, _0809340C @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _08093420 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	b _08093436
	.align 2, 0
_080933FC: .4byte 0x08369A8C
_08093400: .4byte u32_020302b0
_08093404: .4byte 0x0203700C
_08093408: .4byte gStageRun+232
_0809340C: .4byte gWindowRegBuffer
_08093410: .4byte u32_020302b4
_08093414: .4byte u32_020302ac
_08093418: .4byte gPaletteManager
_0809341C: .4byte 0x0000FFFF
_08093420: .4byte 0x0000BFFF
_08093424:
	ldr r0, _08093480 @ =gWindowRegBuffer
	ldrh r2, [r0]
	movs r7, #0x80
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r1, r2
	strh r1, [r0]
	mov r1, sl
	strb r1, [r0, #0xd]
_08093436:
	ldr r1, [r5, #0x2c]
	cmp r1, #0
	beq _08093452
	ldr r0, _08093484 @ =u32_020302ac
	ldr r0, [r0]
	str r0, [r1, #0x74]
	ldr r1, [r5, #0x2c]
	ldr r0, _08093488 @ =u32_020302b4
	ldr r0, [r0]
	str r0, [r1, #0x78]
	ldr r1, [r5, #0x2c]
	ldr r0, _0809348C @ =u32_020302b0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
_08093452:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0809345A
	b _0809355C
_0809345A:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809355C
	ldr r2, _08093480 @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _08093490 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08093494 @ =0x08369AA4
	ldr r0, [sp, #0x10]
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _0809355C
	.align 2, 0
_08093480: .4byte gWindowRegBuffer
_08093484: .4byte u32_020302ac
_08093488: .4byte u32_020302b4
_0809348C: .4byte u32_020302b0
_08093490: .4byte 0x0000BFFF
_08093494: .4byte 0x08369AA4
_08093498:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809355C
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809355C
_080934AE:
	movs r0, #0x28
_080934B0:
	strb r0, [r5, #0x12]
_080934B2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809355C
_080934BA:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r3, [r5, #0x28]
	ldr r1, [r0]
	ldr r0, [r3, #0x54]
	adds r1, r1, r0
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r3, #0x58]
	adds r1, r1, r0
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809355C
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809355C
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _0809355C
_08093510:
	ldr r2, _0809356C @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _08093570 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08093574 @ =0x0000B602
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08093528:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r5, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
_0809355C:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809356C: .4byte gWindowRegBuffer
_08093570: .4byte 0x0000BFFF
_08093574: .4byte 0x0000B602
