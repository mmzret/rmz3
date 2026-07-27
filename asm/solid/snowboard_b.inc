	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cf91c
FUN_080cf91c: @ 0x080CF91C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x2c]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CF92E
	cmp r5, #1
	beq _080CF968
	b _080CF9C6
_080CF92E:
	ldr r1, _080CF98C @ =0x00006D0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CF990 @ =0x08370694
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x58]
	str r0, [r1]
	str r5, [r4, #0x5c]
	str r5, [r4, #0x60]
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CF960
	movs r2, #0x40
_080CF960:
	str r2, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CF968:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080CF998
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	ble _080CF986
	str r0, [r4, #0x5c]
_080CF986:
	ldr r0, [r4, #0x5c]
	ldr r1, _080CF994 @ =0xFFFFFD00
	b _080CF9A6
	.align 2, 0
_080CF98C: .4byte 0x00006D0D
_080CF990: .4byte 0x08370694
_080CF994: .4byte 0xFFFFFD00
_080CF998:
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _080CF9A2
	str r0, [r4, #0x5c]
_080CF9A2:
	ldr r0, [r4, #0x5c]
	ldr r1, _080CF9DC @ =0xFFFFFC00
_080CF9A6:
	cmp r0, r1
	bge _080CF9AC
	str r1, [r4, #0x5c]
_080CF9AC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	bl FUN_080cf428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CF9C6
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CF9C6:
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080CF9D6
	movs r1, #0
	str r1, [r4, #0x2c]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CF9D6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF9DC: .4byte 0xFFFFFC00

	thumb_func_start FUN_080cf9e0
FUN_080cf9e0: @ 0x080CF9E0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x2c]
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080CF9F2
	cmp r0, #1
	beq _080CFA02
	b _080CFA6A
_080CF9F2:
	movs r0, #1
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080CFA02:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl FUN_080cf428
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFA64
	ldrb r1, [r5, #0xa]
	lsrs r0, r1, #4
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080CFA36
	movs r0, #0x10
	orrs r0, r1
	b _080CFA3A
_080CFA36:
	movs r0, #0xef
	ands r0, r1
_080CFA3A:
	strb r0, [r5, #0xa]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	strb r3, [r5, #0xd]
	strb r4, [r5, #0xe]
_080CFA64:
	adds r0, r5, #0
	bl UpdateEntityAnim
_080CFA6A:
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080CFA7A
	movs r1, #0
	str r1, [r5, #0x2c]
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080CFA7A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cfa80
FUN_080cfa80: @ 0x080CFA80
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CFA90
	cmp r5, #1
	beq _080CFABA
	b _080CFB26
_080CFA90:
	ldr r1, _080CFB2C @ =0x00006D0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CFB30 @ =0x083706AC
	bl SetDDP
	movs r0, #0x20
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	movs r1, #0x20
	bl __divsi3
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CFABA:
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080CFAD2
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	subs r0, r2, #1
	strb r0, [r4, #0x12]
_080CFAD2:
	adds r0, r4, #0
	bl FUN_080cf428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CFAEA
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
_080CFAEA:
	ldrb r0, [r4, #0x12]
	adds r3, r4, #0
	adds r3, #0x8c
	cmp r0, #0
	bne _080CFB16
	ldr r0, [r3]
	movs r5, #4
	ands r0, r5
	cmp r0, #0
	beq _080CFB16
	ldr r0, _080CFB34 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r4, #0x58]
	subs r0, #8
	ldr r1, [r2, #0x58]
	cmp r1, r0
	bge _080CFB16
	ldrb r0, [r2, #0xd]
	cmp r0, #0
	bne _080CFB16
	strb r5, [r4, #0xd]
	strb r0, [r4, #0xe]
_080CFB16:
	ldr r0, [r3]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080CFB26:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFB2C: .4byte 0x00006D0D
_080CFB30: .4byte 0x083706AC
_080CFB34: .4byte pZero2

	thumb_func_start FUN_080cfb38
FUN_080cfb38: @ 0x080CFB38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CFB48
	cmp r5, #1
	beq _080CFB84
	b _080CFBC4
_080CFB48:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CFBCC @ =0x08370694
	bl SetDDP
	ldr r1, _080CFBD0 @ =0x00006D0D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x58]
	str r0, [r1]
	str r5, [r4, #0x5c]
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	adds r2, r0, #0
	ldr r0, _080CFBD4 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CFB7C
	movs r2, #0x20
_080CFB7C:
	str r2, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CFB84:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0xe0
	lsls r0, r0, #2
	cmp r1, r0
	ble _080CFB9C
	str r0, [r4, #0x5c]
_080CFB9C:
	ldr r0, [r4, #0x5c]
	ldr r1, _080CFBD8 @ =0xFFFFFC80
	cmp r0, r1
	bge _080CFBA6
	str r1, [r4, #0x5c]
_080CFBA6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	bl FUN_080cf428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CFBC4
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
_080CFBC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFBCC: .4byte 0x08370694
_080CFBD0: .4byte 0x00006D0D
_080CFBD4: .4byte pZero2
_080CFBD8: .4byte 0xFFFFFC80
