	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hanu_0805bd38
hanu_0805bd38: @ 0x0805BD38
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BD5A
	ldr r1, _0805BD78 @ =0x0000B510
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x50
	bl PlaySound
	movs r0, #0xa0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BD5A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	bne _0805BD80
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805BDA4
	ldr r1, _0805BD7C @ =0x0000B516
	b _0805BD92
	.align 2, 0
_0805BD78: .4byte 0x0000B510
_0805BD7C: .4byte 0x0000B516
_0805BD80:
	cmp r0, #2
	bne _0805BDA4
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805BDA4
	movs r1, #0xb5
	lsls r1, r1, #8
_0805BD92:
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BDA4:
	ldr r0, _0805BDBC @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0805BDB6
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805BDB6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805BDBC: .4byte gStageRun

	thumb_func_start hanu_0805bdc0
hanu_0805bdc0: @ 0x0805BDC0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl UpdateEntityAnim
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a31c
	ldr r1, [r4]
	cmp r1, r0
	bne _0805BDEA
	adds r4, #4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a22c
	ldr r1, [r4]
	cmp r1, r0
	beq _0805BDF6
_0805BDEA:
	movs r1, #0
	movs r0, #0xd
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xf]
	strb r1, [r5, #0xe]
	b _0805BF0A
_0805BDF6:
	adds r1, r5, #0
	adds r1, #0xbd
	ldrb r2, [r1]
	movs r0, #1
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0805BE68
	ldr r0, _0805BE2C @ =gScore
	ldr r1, [r0]
	ldrb r1, [r1, #1]
	adds r6, r0, #0
	cmp r1, #4
	bls _0805BE3C
	ldr r2, _0805BE30 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805BE34 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805BE38 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #7
	ands r1, r0
	b _0805BE6E
	.align 2, 0
_0805BE2C: .4byte gScore
_0805BE30: .4byte RNG_0202f388
_0805BE34: .4byte 0x000343FD
_0805BE38: .4byte 0x00269EC3
_0805BE3C:
	ldr r2, _0805BE5C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805BE60 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805BE64 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _0805BE6E
	.align 2, 0
_0805BE5C: .4byte RNG_0202f388
_0805BE60: .4byte 0x000343FD
_0805BE64: .4byte 0x00269EC3
_0805BE68:
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x19
	ldr r6, _0805BE7C @ =gScore
_0805BE6E:
	cmp r1, #7
	bhi _0805BEDE
	lsls r0, r1, #2
	ldr r1, _0805BE80 @ =_0805BE84
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805BE7C: .4byte gScore
_0805BE80: .4byte _0805BE84
_0805BE84: @ jump table
	.4byte _0805BEA4 @ case 0
	.4byte _0805BEAE @ case 1
	.4byte _0805BEB2 @ case 2
	.4byte _0805BEB6 @ case 3
	.4byte _0805BEC8 @ case 4
	.4byte _0805BED2 @ case 5
	.4byte _0805BED6 @ case 6
	.4byte _0805BEDA @ case 7
_0805BEA4:
	movs r0, #0xd
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xf]
	b _0805BEDE
_0805BEAE:
	movs r0, #8
	b _0805BEDC
_0805BEB2:
	movs r0, #0xa
	b _0805BEDC
_0805BEB6:
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805BEC4
	movs r0, #0x16
	b _0805BEDC
_0805BEC4:
	movs r0, #4
	b _0805BEDC
_0805BEC8:
	movs r1, #0
	movs r0, #0xd
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xf]
	b _0805BEDE
_0805BED2:
	movs r0, #0x16
	b _0805BEDC
_0805BED6:
	movs r0, #0x19
	b _0805BEDC
_0805BEDA:
	movs r0, #0x13
_0805BEDC:
	strb r0, [r5, #0xd]
_0805BEDE:
	adds r2, r4, #0
	ldrb r0, [r2]
	adds r1, r0, #1
	movs r3, #0
	strb r1, [r2]
	ldr r0, [r6]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0805BEFC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0805BF06
	strb r3, [r2]
	b _0805BF06
_0805BEFC:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bls _0805BF06
	strb r3, [r4]
_0805BF06:
	movs r0, #0
	strb r0, [r5, #0xe]
_0805BF0A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start hanu_0805bf10
hanu_0805bf10: @ 0x0805BF10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BF38
	movs r1, #0xb5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805BF5C @ =sCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0x20
	strb r0, [r4, #0x12]
_0805BF38:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805BF54
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805BF54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805BF5C: .4byte sCollisions

	thumb_func_start hanu_0805bf60
hanu_0805bf60: @ 0x0805BF60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BFF4
	ldr r1, _0805BFC0 @ =0x0000B501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805BFC4 @ =0x08364E68
	bl SetDDP
	movs r3, #0
	ldr r0, _0805BFC8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805BF8C
	movs r3, #1
_0805BF8C:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805BF9E
	movs r3, #1
_0805BF9E:
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
	beq _0805BFCC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805BFD2
	.align 2, 0
_0805BFC0: .4byte 0x0000B501
_0805BFC4: .4byte 0x08364E68
_0805BFC8: .4byte pZero2
_0805BFCC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805BFD2:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805BFE4
	movs r0, #0xe0
	lsls r0, r0, #2
	b _0805BFE6
_0805BFE4:
	ldr r0, _0805C044 @ =0xFFFFFC80
_0805BFE6:
	str r0, [r4, #0x5c]
	movs r0, #0x4e
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BFF4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0805C068
	ldr r0, [r4, #0x54]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0805C02E
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
_0805C02E:
	ldr r1, [r4, #0x54]
	adds r2, r1, r5
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	adds r3, r1, #0
	cmp r2, r0
	ble _0805C048
	movs r1, #0
	movs r0, #5
	b _0805C05A
	.align 2, 0
_0805C044: .4byte 0xFFFFFC80
_0805C048:
	ldr r2, _0805C060 @ =0xFFFFE000
	adds r1, r3, r2
	ldr r0, _0805C064 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _0805C0C4
	movs r1, #0
	movs r0, #3
_0805C05A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0805C0CA
	.align 2, 0
_0805C060: .4byte 0xFFFFE000
_0805C064: .4byte pZero2
_0805C068:
	ldr r0, [r4, #0x54]
	ldr r1, _0805C0A4 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805C08E
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
_0805C08E:
	ldr r1, [r4, #0x54]
	ldr r0, _0805C0A4 @ =0xFFFFF000
	adds r2, r1, r0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r3, r1, #0
	cmp r2, r0
	bge _0805C0A8
	movs r0, #5
	b _0805C0BA
	.align 2, 0
_0805C0A4: .4byte 0xFFFFF000
_0805C0A8:
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r3, r2
	ldr r0, _0805C0C0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0805C0C4
	movs r0, #3
_0805C0BA:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _0805C0CA
	.align 2, 0
_0805C0C0: .4byte pZero2
_0805C0C4:
	ldr r0, [r4, #0x5c]
	adds r0, r3, r0
	str r0, [r4, #0x54]
_0805C0CA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start hanu_0805c0d0
hanu_0805c0d0: @ 0x0805C0D0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C154
	adds r0, r4, #0
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C120 @ =0x0000B501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C124 @ =0x08364E98
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	ldr r2, _0805C128 @ =0xFFFFFC80
	str r2, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C130
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r4, #0x54]
	ldr r1, _0805C12C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x64]
	b _0805C142
	.align 2, 0
_0805C120: .4byte 0x0000B501
_0805C124: .4byte 0x08364E98
_0805C128: .4byte 0xFFFFFC80
_0805C12C: .4byte 0xFFFFF000
_0805C130:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x64]
	str r2, [r4, #0x60]
_0805C142:
	ldr r0, [r4, #0x58]
	ldr r2, _0805C190 @ =0xFFFFEA00
	adds r0, r0, r2
	str r0, [r4, #0x58]
	movs r0, #0x80
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C154:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0805C180
	ldr r0, [r4, #0x64]
	ldr r2, _0805C194 @ =0xFFFFD000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C188
_0805C180:
	movs r0, #6
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C188:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C190: .4byte 0xFFFFEA00
_0805C194: .4byte 0xFFFFD000

	thumb_func_start hanu_0805c198
hanu_0805c198: @ 0x0805C198
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _0805C24E
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C200 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C204 @ =0x08364EC8
	bl SetDDP
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805C208
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C20E
	.align 2, 0
_0805C200: .4byte 0x0000B506
_0805C204: .4byte 0x08364EC8
_0805C208:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C20E:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C22C
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x54]
	str r1, [r4, #0x64]
	movs r0, #0x80
	lsls r0, r0, #2
	b _0805C238
_0805C22C:
	ldr r0, [r4, #0x54]
	ldr r1, _0805C298 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r4, #0x54]
	str r1, [r4, #0x64]
	ldr r0, _0805C29C @ =0xFFFFFE00
_0805C238:
	str r0, [r4, #0x5c]
	ldr r0, _0805C2A0 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C24E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805C272
	str r0, [r4, #0x60]
_0805C272:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C292
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C292:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C298: .4byte 0xFFFFF600
_0805C29C: .4byte 0xFFFFFE00
_0805C2A0: .4byte 0xFFFFFD00

	thumb_func_start hanu_0805c2a4
hanu_0805c2a4: @ 0x0805C2A4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C2E8
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _0805C2CC @ =0x0000B514
	cmp r0, r1
	bne _0805C2D0
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _0805C2D8
	.align 2, 0
_0805C2CC: .4byte 0x0000B514
_0805C2D0:
	ldr r1, _0805C304 @ =0x0000B507
	adds r0, r4, #0
	bl SetMotion
_0805C2D8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C308 @ =0x08364EF8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C2E8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0805C2FE
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0805C2FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C304: .4byte 0x0000B507
_0805C308: .4byte 0x08364EF8

	thumb_func_start hanu_0805c30c
hanu_0805c30c: @ 0x0805C30C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C388
	ldr r1, _0805C364 @ =0x0000B50A
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C368 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C32E
	movs r3, #1
_0805C32E:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C340
	movs r3, #1
_0805C340:
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
	beq _0805C36C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C372
	.align 2, 0
_0805C364: .4byte 0x0000B50A
_0805C368: .4byte pZero2
_0805C36C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C372:
	strb r0, [r4, #0xa]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	movs r0, #3
	strb r0, [r4, #0x13]
	movs r0, #0x4f
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C388:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0805C3B6
	ldrb r1, [r4, #0x13]
	subs r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	bl FUN_080866a4
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	b _0805C3BA
_0805C3B6:
	subs r0, #1
	strb r0, [r4, #0x12]
_0805C3BA:
	ldrb r1, [r4, #0x13]
	cmp r1, #0
	bne _0805C3C6
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C3C6:
	pop {r4}
	pop {r0}
	bx r0

