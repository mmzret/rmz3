	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile17_Die
Projectile17_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68
	.byte 0x00, 0x69, 0x50, 0x61, 0x70, 0x47
  .align 2, 0
  .4byte gProjectileFnTable

	thumb_func_start FUN_080a2adc
FUN_080a2adc: @ 0x080A2ADC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	beq _080A2AF6
	movs r1, #0
	b _080A2AFE
_080A2AF6:
	ldr r2, _080A2B20 @ =0x00400100
	ands r2, r0
	cmp r2, #0
	beq _080A2B28
_080A2AFE:
	str r1, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A2B24 @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r6, #0xe]
	b _080A2B6A
	.align 2, 0
_080A2B20: .4byte 0x00400100
_080A2B24: .4byte 0x00004201
_080A2B28:
	movs r4, #4
	ands r0, r4
	cmp r0, #0
	beq _080A2B3E
	str r2, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	b _080A2B58
_080A2B3E:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080A2B6A
	str r1, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
_080A2B58:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A2B7C @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0xe]
_080A2B6A:
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _080A2B72
	b _080A2D86
_080A2B72:
	lsls r0, r0, #2
	ldr r1, _080A2B80 @ =_080A2B84
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A2B7C: .4byte 0x00004201
_080A2B80: .4byte _080A2B84
_080A2B84: @ jump table
	.4byte _080A2B9C @ case 0
	.4byte _080A2BB0 @ case 1
	.4byte _080A2BE0 @ case 2
	.4byte _080A2C22 @ case 3
	.4byte _080A2CE4 @ case 4
	.4byte _080A2D5E @ case 5
_080A2B9C:
	movs r1, #0x84
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xc
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A2BB0:
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _080A2BDC @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080A2BD2
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A2BD2
	b _080A2D86
_080A2BD2:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080A2D86
	.align 2, 0
_080A2BDC: .4byte 0xFFFFF600
_080A2BE0:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A2BF8
	ldr r0, [r6, #0x54]
	ldr r2, _080A2BF4 @ =0xFFFFC000
	adds r1, r0, r2
	b _080A2C00
	.align 2, 0
_080A2BF4: .4byte 0xFFFFC000
_080A2BF8:
	ldr r0, [r6, #0x54]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r0, r3
_080A2C00:
	movs r0, #0x4c
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x54]
	subs r0, r1, r0
	movs r1, #0x4c
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r1, #0
	ldr r0, _080A2C4C @ =0xFFFFFDA0
	str r0, [r6, #0x60]
	movs r0, #0x4b
	str r0, [r6, #0x64]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A2C22:
	ldr r2, [r6, #0x60]
	adds r2, #0x10
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	movs r4, #0
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	bge _080A2C54
	ldr r0, [r6, #0x54]
	ldr r3, _080A2C50 @ =0xFFFFF600
	b _080A2C5A
	.align 2, 0
_080A2C4C: .4byte 0xFFFFFDA0
_080A2C50: .4byte 0xFFFFF600
_080A2C54:
	ldr r0, [r6, #0x54]
	movs r3, #0xa0
	lsls r3, r3, #4
_080A2C5A:
	adds r2, r0, r3
	adds r0, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _080A2C96
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A2CDC @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r6, #0xe]
	movs r4, #1
_080A2C96:
	cmp r4, #0
	bne _080A2D86
	ldr r2, [r6, #0x54]
	ldr r0, [r6, #0x58]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2CBA
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #2
	strb r0, [r6, #0xe]
_080A2CBA:
	ldr r2, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r3, _080A2CE0 @ =0xFFFFFC00
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2D86
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x60]
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	b _080A2D86
	.align 2, 0
_080A2CDC: .4byte 0x00004201
_080A2CE0: .4byte 0xFFFFFC00
_080A2CE4:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _080A2D90 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	mov r0, sp
	bl FUN_080a2790
	ldr r0, [r6, #0x54]
	movs r4, #0xc0
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	adds r1, r5, #0
	bics r1, r0
	mov r0, sp
	bl FUN_080a2790
	ldr r0, [r6, #0x54]
	ldr r2, _080A2D90 @ =0xFFFFF400
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	mov r0, sp
	bl FUN_080a2790
	movs r4, #0
	adds r5, r6, #0
	adds r5, #0x54
_080A2D40:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_080a27e4
	adds r4, #1
	cmp r4, #4
	ble _080A2D40
	ldr r1, _080A2D94 @ =0x00004201
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A2D5E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A2D86
	movs r0, #0x31
	bl PlaySound
	ldr r1, _080A2D98 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A2D86:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D90: .4byte 0xFFFFF400
_080A2D94: .4byte 0x00004201
_080A2D98: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2d9c
FUN_080a2d9c: @ 0x080A2D9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A2DAC
	cmp r0, #1
	beq _080A2DBA
	b _080A2DDC
_080A2DAC:
	ldr r1, _080A2DE4 @ =0x00004204
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A2DBA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A2DDC
	ldr r1, _080A2DE8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A2DDC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2DE4: .4byte 0x00004204
_080A2DE8: .4byte gProjectileFnTable

	thumb_func_start FUN_080a2dec
FUN_080a2dec: @ 0x080A2DEC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A2E20
	cmp r0, #1
	bgt _080A2E00
	cmp r0, #0
	beq _080A2E0A
	b _080A2E92
_080A2E00:
	cmp r0, #2
	beq _080A2E4C
	cmp r0, #3
	beq _080A2E62
	b _080A2E92
_080A2E0A:
	ldr r1, _080A2E48 @ =0x00004202
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	movs r0, #0x40
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A2E20:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A2E3E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A2E92
_080A2E3E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A2E92
	.align 2, 0
_080A2E48: .4byte 0x00004202
_080A2E4C:
	ldr r1, _080A2E98 @ =0x00004203
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	movs r0, #0x20
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A2E62:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A2E80
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A2E92
_080A2E80:
	ldr r1, _080A2E9C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A2E92:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E98: .4byte 0x00004203
_080A2E9C: .4byte gProjectileFnTable

