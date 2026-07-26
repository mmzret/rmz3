	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080adc84
FUN_080adc84: @ 0x080ADC84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r1, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r2, r1
	cmp r2, #0
	beq _080ADCB6
	movs r1, #0
	str r1, [r5]
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	b _080ADD1A
_080ADCB6:
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _080ADCDA
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	b _080ADD1A
_080ADCDA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080ADD06
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080ADD3C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080ADD3C
_080ADD06:
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_080ADD1A:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080ADD38 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080AE138
	.align 2, 0
_080ADD38: .4byte gProjectileFnTable
_080ADD3C:
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080ADD44
	b _080AE138
_080ADD44:
	lsls r0, r0, #2
	ldr r1, _080ADD50 @ =_080ADD54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ADD50: .4byte _080ADD54
_080ADD54: @ jump table
	.4byte _080ADD6C @ case 0
	.4byte _080ADD9E @ case 1
	.4byte _080ADDE0 @ case 2
	.4byte _080ADDF4 @ case 3
	.4byte _080ADE5E @ case 4
	.4byte _080ADF90 @ case 5
_080ADD6C:
	ldr r1, _080ADDDC @ =0x00006F08
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	str r2, [r4, #0x60]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADD9E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _080ADDAE
	str r1, [r4, #0x60]
_080ADDAE:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080ADDD4
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADDD4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080AE138
	.align 2, 0
_080ADDDC: .4byte 0x00006F08
_080ADDE0:
	movs r0, #0x64
	bl PlaySound
	movs r0, #0x20
	str r0, [r4, #0x5c]
	movs r0, #0xc
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADDF4:
	ldr r0, [r4, #0x60]
	subs r0, #0x80
	str r0, [r4, #0x60]
	cmp r0, #0
	bge _080ADE02
	movs r0, #0
	str r0, [r4, #0x60]
_080ADE02:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ADE40
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080ADE40:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080ADE4E
	b _080AE138
_080ADE4E:
	ldr r0, [r4, #0x5c]
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x60]
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080AE138
_080ADE5E:
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0xd
	strb r0, [r4, #0x13]
	ldr r0, _080ADEF0 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080ADECE
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080ADECE:
	ldr r1, [r4, #0x5c]
	lsls r1, r1, #9
	asrs r1, r1, #8
	str r1, [r4, #0x64]
	ldr r2, [r4, #0x60]
	lsls r0, r2, #9
	asrs r0, r0, #8
	str r0, [r4, #0x68]
	cmp r1, #0
	ble _080ADF32
	cmp r0, #0
	ble _080ADF0C
	cmp r2, #0x5e
	bgt _080ADEF8
	ldr r1, _080ADEF4 @ =0x00006F06
	b _080ADF72
	.align 2, 0
_080ADEF0: .4byte pZero2
_080ADEF4: .4byte 0x00006F06
_080ADEF8:
	cmp r2, #0xea
	bgt _080ADF04
	ldr r1, _080ADF00 @ =0x00006F05
	b _080ADF72
	.align 2, 0
_080ADF00: .4byte 0x00006F05
_080ADF04:
	ldr r1, _080ADF08 @ =0x00006F04
	b _080ADF72
	.align 2, 0
_080ADF08: .4byte 0x00006F04
_080ADF0C:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF1C
	ldr r1, _080ADF18 @ =0x00006F06
	b _080ADF72
	.align 2, 0
_080ADF18: .4byte 0x00006F06
_080ADF1C:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF2C
	ldr r1, _080ADF28 @ =0x00006F07
	b _080ADF72
	.align 2, 0
_080ADF28: .4byte 0x00006F07
_080ADF2C:
	movs r1, #0xde
	lsls r1, r1, #7
	b _080ADF72
_080ADF32:
	cmp r0, #0
	ble _080ADF58
	cmp r2, #0x5e
	bgt _080ADF44
	ldr r1, _080ADF40 @ =0x00006F02
	b _080ADF72
	.align 2, 0
_080ADF40: .4byte 0x00006F02
_080ADF44:
	cmp r2, #0xea
	bgt _080ADF50
	ldr r1, _080ADF4C @ =0x00006F03
	b _080ADF72
	.align 2, 0
_080ADF4C: .4byte 0x00006F03
_080ADF50:
	ldr r1, _080ADF54 @ =0x00006F04
	b _080ADF72
	.align 2, 0
_080ADF54: .4byte 0x00006F04
_080ADF58:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF68
	ldr r1, _080ADF64 @ =0x00006F02
	b _080ADF72
	.align 2, 0
_080ADF64: .4byte 0x00006F02
_080ADF68:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r2, r0
	ble _080ADF80
	ldr r1, _080ADF7C @ =0x00006F01
_080ADF72:
	adds r0, r4, #0
	bl SetMotion
	b _080ADF8A
	.align 2, 0
_080ADF7C: .4byte 0x00006F01
_080ADF80:
	movs r1, #0xde
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_080ADF8A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ADF90:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080ADFBC
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080ADFA2
	b _080AE0FA
_080ADFA2:
	ldr r0, _080AE060 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080ADFB4
	movs r0, #0xd
	strb r0, [r4, #0x13]
_080ADFB4:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080ADFBC
	b _080AE0FA
_080ADFBC:
	ldr r0, _080AE060 @ =pZero2
	ldr r3, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080ADFCC
	b _080AE0FA
_080ADFCC:
	movs r0, #0xd
	strb r0, [r4, #0x13]
	ldr r2, [r3, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r3, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080AE01A
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080AE01A:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #9
	asrs r0, r0, #8
	adds r6, r0, #0
	ldr r3, [r4, #0x60]
	lsls r1, r3, #9
	asrs r1, r1, #8
	adds r7, r1, #0
	ldr r2, [r4, #0x64]
	lsls r2, r2, #6
	asrs r2, r2, #8
	lsls r0, r0, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x64]
	ldr r0, [r4, #0x68]
	lsls r0, r0, #6
	asrs r0, r0, #8
	lsls r1, r1, #1
	adds r1, r1, r7
	lsls r1, r1, #6
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x68]
	cmp r2, #0
	ble _080AE0A2
	cmp r0, #0
	ble _080AE07C
	cmp r3, #0x5e
	bgt _080AE068
	ldr r1, _080AE064 @ =0x00006F06
	b _080AE0E2
	.align 2, 0
_080AE060: .4byte pZero2
_080AE064: .4byte 0x00006F06
_080AE068:
	cmp r3, #0xea
	bgt _080AE074
	ldr r1, _080AE070 @ =0x00006F05
	b _080AE0E2
	.align 2, 0
_080AE070: .4byte 0x00006F05
_080AE074:
	ldr r1, _080AE078 @ =0x00006F04
	b _080AE0E2
	.align 2, 0
_080AE078: .4byte 0x00006F04
_080AE07C:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE08C
	ldr r1, _080AE088 @ =0x00006F06
	b _080AE0E2
	.align 2, 0
_080AE088: .4byte 0x00006F06
_080AE08C:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE09C
	ldr r1, _080AE098 @ =0x00006F07
	b _080AE0E2
	.align 2, 0
_080AE098: .4byte 0x00006F07
_080AE09C:
	movs r1, #0xde
	lsls r1, r1, #7
	b _080AE0E2
_080AE0A2:
	cmp r0, #0
	ble _080AE0C8
	cmp r3, #0x5e
	bgt _080AE0B4
	ldr r1, _080AE0B0 @ =0x00006F02
	b _080AE0E2
	.align 2, 0
_080AE0B0: .4byte 0x00006F02
_080AE0B4:
	cmp r3, #0xea
	bgt _080AE0C0
	ldr r1, _080AE0BC @ =0x00006F03
	b _080AE0E2
	.align 2, 0
_080AE0BC: .4byte 0x00006F03
_080AE0C0:
	ldr r1, _080AE0C4 @ =0x00006F04
	b _080AE0E2
	.align 2, 0
_080AE0C4: .4byte 0x00006F04
_080AE0C8:
	movs r0, #0x5f
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE0D8
	ldr r1, _080AE0D4 @ =0x00006F02
	b _080AE0E2
	.align 2, 0
_080AE0D4: .4byte 0x00006F02
_080AE0D8:
	movs r0, #0xeb
	rsbs r0, r0, #0
	cmp r3, r0
	ble _080AE0F0
	ldr r1, _080AE0EC @ =0x00006F01
_080AE0E2:
	adds r0, r4, #0
	bl SetMotion
	b _080AE0FA
	.align 2, 0
_080AE0EC: .4byte 0x00006F01
_080AE0F0:
	movs r1, #0xde
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_080AE0FA:
	ldrb r0, [r4, #0x13]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AE122
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldr r0, [r1, #4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	str r0, [r1, #4]
	movs r0, #3
	bl CreateSmoke
_080AE122:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080AE138:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ae140
FUN_080ae140: @ 0x080AE140
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #2
	bls _080AE17C
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AE178 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080AE1F6
	.align 2, 0
_080AE178: .4byte gProjectileFnTable
_080AE17C:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080AE1A2
	cmp r5, #1
	bgt _080AE18C
	cmp r5, #0
	beq _080AE192
	b _080AE1F6
_080AE18C:
	cmp r5, #2
	beq _080AE1C8
	b _080AE1F6
_080AE192:
	ldr r1, _080AE1C4 @ =0x00006E06
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AE1A2:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AE1F6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080AE1F6
	.align 2, 0
_080AE1C4: .4byte 0x00006E06
_080AE1C8:
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AE1E8
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080AE1EE
_080AE1E8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080AE1EE:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080AE1F6:
	pop {r4, r5}
	pop {r0}
	bx r0


