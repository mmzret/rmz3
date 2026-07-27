	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a38e8
FUN_080a38e8: @ 0x080A38E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A38FE
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bhi _080A38FE
	movs r0, #0xc
	strb r0, [r4, #0xe]
_080A38FE:
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xd]
	adds r2, r0, #0
	cmp r1, #0xa
	bne _080A3912
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bhi _080A3912
	movs r0, #0xc
	strb r0, [r4, #0xe]
_080A3912:
	ldrb r0, [r2, #0xd]
	cmp r0, #8
	beq _080A3922
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bhi _080A3922
	movs r0, #0xc
	strb r0, [r4, #0xe]
_080A3922:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _080A392A
	b _080A3C4C
_080A392A:
	lsls r0, r0, #2
	ldr r1, _080A3934 @ =_080A3938
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A3934: .4byte _080A3938
_080A3938: @ jump table
	.4byte _080A3970 @ case 0
	.4byte _080A3A00 @ case 1
	.4byte _080A3A84 @ case 2
	.4byte _080A3AB0 @ case 3
	.4byte _080A3AE8 @ case 4
	.4byte _080A3C4C @ case 5
	.4byte _080A3C4C @ case 6
	.4byte _080A3C4C @ case 7
	.4byte _080A3C4C @ case 8
	.4byte _080A3C4C @ case 9
	.4byte _080A3B4A @ case 10
	.4byte _080A3B6C @ case 11
	.4byte _080A3BB8 @ case 12
	.4byte _080A3BF0 @ case 13
_080A3970:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080A39A0
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldr r0, _080A399C @ =0xFFFFCE00
	movs r1, #0x28
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x27
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080A39EC
	.align 2, 0
_080A399C: .4byte 0xFFFFCE00
_080A39A0:
	cmp r0, #1
	bne _080A39CC
	movs r0, #0x28
	strb r0, [r4, #0x12]
	movs r0, #0xc8
	lsls r0, r0, #6
	movs r1, #0x28
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x27
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080A39EC
_080A39CC:
	cmp r0, #2
	bne _080A39DC
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, _080A39D8 @ =0xFFFFFE00
	b _080A39E8
	.align 2, 0
_080A39D8: .4byte 0xFFFFFE00
_080A39DC:
	cmp r0, #3
	bne _080A39EE
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x80
	lsls r0, r0, #2
_080A39E8:
	str r0, [r4, #0x5c]
	movs r0, #0xa
_080A39EC:
	strb r0, [r4, #0xe]
_080A39EE:
	movs r1, #0xae
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080A3C4C
_080A3A00:
	ldr r2, [r4, #0x60]
	adds r2, #0x24
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0xc0
	lsls r5, r5, #4
	adds r1, r1, r5
	bl PushoutToUp1
	cmp r0, #0
	beq _080A3A44
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080A3A38
	movs r0, #0x80
	lsls r0, r0, #2
	b _080A3A3A
_080A3A38:
	ldr r0, _080A3A40 @ =0xFFFFFE00
_080A3A3A:
	str r0, [r4, #0x5c]
	b _080A3BAA
	.align 2, 0
_080A3A40: .4byte 0xFFFFFE00
_080A3A44:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080A3A60
	ldr r0, [r4, #0x54]
	ldr r1, _080A3A5C @ =0xFFFFF400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A3A5C @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToRight1
	b _080A3A6E
	.align 2, 0
_080A3A5C: .4byte 0xFFFFF400
_080A3A60:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	ldr r2, _080A3A80 @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToLeft1
_080A3A6E:
	cmp r0, #0
	bne _080A3A74
	b _080A3C4C
_080A3A74:
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #3
	strb r0, [r4, #0xe]
	b _080A3C4C
	.align 2, 0
_080A3A80: .4byte 0xFFFFF400
_080A3A84:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	blt _080A3A9A
	b _080A3B94
_080A3A9A:
	ldr r0, [r4, #0x54]
	ldr r2, _080A3AAC @ =0xFFFFF400
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl PushoutToRight1
	b _080A3BA6
	.align 2, 0
_080A3AAC: .4byte 0xFFFFF400
_080A3AB0:
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x50
	movs r3, #0
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A3AE8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	rsbs r0, r1, #0
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x64]
	ldr r0, [r4, #0x60]
	adds r0, #0x24
	str r0, [r4, #0x60]
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3B1E
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080A3B1E:
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	ldr r0, [r4, #0x64]
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A3B36
	subs r0, #1
	strb r0, [r4, #0x12]
_080A3B36:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080A3C2E
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A3C34
_080A3B4A:
	ldr r1, [r4, #0x60]
	adds r1, #0x24
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	b _080A3BA6
_080A3B6C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080A3B94
	ldr r0, [r4, #0x54]
	ldr r2, _080A3B90 @ =0xFFFFF400
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl PushoutToRight1
	b _080A3BA6
	.align 2, 0
_080A3B90: .4byte 0xFFFFF400
_080A3B94:
	ldr r0, [r4, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A3BB4 @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToLeft1
_080A3BA6:
	cmp r0, #0
	beq _080A3C4C
_080A3BAA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A3C4C
	.align 2, 0
_080A3BB4: .4byte 0xFFFFF400
_080A3BB8:
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x50
	movs r3, #0
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A3BF0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	rsbs r0, r1, #0
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A3C1A
	subs r0, #1
	strb r0, [r4, #0x12]
_080A3C1A:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080A3C2E
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A3C34
_080A3C2E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A3C34:
	strb r0, [r4, #0xa]
	cmp r2, #0
	bne _080A3C4C
	ldr r1, _080A3C54 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A3C4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3C54: .4byte gProjectileFnTable

	thumb_func_start FUN_080a3c58
FUN_080a3c58: @ 0x080A3C58
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x28]
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _080A3C78
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	bl FUN_080a449c
_080A3C78:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	bne _080A3C88
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bhi _080A3C88
	bl FUN_080a449c
_080A3C88:
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r0, [r1]
	movs r2, #4
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _080A3CAA
	adds r0, r7, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080A3CAA
	movs r0, #0x52
	bl PlaySound
_080A3CAA:
	ldrb r0, [r7, #0xe]
	cmp r0, #0x1b
	bls _080A3CB4
	bl _080A44AE
_080A3CB4:
	lsls r0, r0, #2
	ldr r1, _080A3CC0 @ =_080A3CC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A3CC0: .4byte _080A3CC4
_080A3CC4: @ jump table
	.4byte _080A3D34 @ case 0
	.4byte _080A3DB0 @ case 1
	.4byte _080A3E04 @ case 2
	.4byte _080A3E3E @ case 3
	.4byte _080A3E74 @ case 4
	.4byte _080A3E8E @ case 5
	.4byte _080A3F02 @ case 6
	.4byte _080A3FBC @ case 7
	.4byte _080A3FD4 @ case 8
	.4byte _080A4072 @ case 9
	.4byte _080A40A2 @ case 10
	.4byte _080A4104 @ case 11
	.4byte _080A4140 @ case 12
	.4byte _080A44AE @ case 13
	.4byte _080A44AE @ case 14
	.4byte _080A44AE @ case 15
	.4byte _080A44AE @ case 16
	.4byte _080A44AE @ case 17
	.4byte _080A44AE @ case 18
	.4byte _080A44AE @ case 19
	.4byte _080A4198 @ case 20
	.4byte _080A41B0 @ case 21
	.4byte _080A427C @ case 22
	.4byte _080A4282 @ case 23
	.4byte _080A431E @ case 24
	.4byte _080A434E @ case 25
	.4byte _080A43E8 @ case 26
	.4byte _080A443A @ case 27
_080A3D34:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A3D50
	ldr r0, [r7, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
	b _080A3D56
_080A3D50:
	ldr r0, [r7, #0x54]
	ldr r2, _080A3D7C @ =0xFFFFD600
	adds r0, r0, r2
_080A3D56:
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _080A3D80 @ =0xFFFF9800
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, _080A3D84 @ =0x0000AD06
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A3D88
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A3D8E
	.align 2, 0
_080A3D7C: .4byte 0xFFFFD600
_080A3D80: .4byte 0xFFFF9800
_080A3D84: .4byte 0x0000AD06
_080A3D88:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A3D8E:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3DB0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A3DCC
	ldr r0, [r7, #0x54]
	movs r2, #0xa8
	lsls r2, r2, #6
	adds r0, r0, r2
	b _080A3DD2
_080A3DCC:
	ldr r0, [r7, #0x54]
	ldr r1, _080A3DFC @ =0xFFFFD600
	adds r0, r0, r1
_080A3DD2:
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r2, _080A3E00 @ =0xFFFF9800
	adds r0, r0, r2
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r2, r7, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080A3DF2
	b _080A44AE
_080A3DF2:
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	b _080A43E0
	.align 2, 0
_080A3DFC: .4byte 0xFFFFD600
_080A3E00: .4byte 0xFFFF9800
_080A3E04:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A3E20
	ldr r0, [r7, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
	b _080A3E26
_080A3E20:
	ldr r0, [r7, #0x54]
	ldr r2, _080A3E68 @ =0xFFFFD600
	adds r0, r0, r2
_080A3E26:
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _080A3E6C @ =0xFFFF9800
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, _080A3E70 @ =0x0000AD06
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3E3E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r2, r7, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3E54
	b _080A44AE
_080A3E54:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _080A43E0
	.align 2, 0
_080A3E68: .4byte 0xFFFFD600
_080A3E6C: .4byte 0xFFFF9800
_080A3E70: .4byte 0x0000AD06
_080A3E74:
	adds r2, r7, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080A3E84
	b _080A44AE
_080A3E84:
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	b _080A43E0
_080A3E8E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080A3ED8 @ =0x0000AD07
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080A3EDC @ =0x0836B524
	bl SetDDP
	ldr r0, [r4, #0x58]
	ldr r2, _080A3EE0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A3EEC
	ldr r0, _080A3EE4 @ =0xFFFFFCD0
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	ldr r1, _080A3EE8 @ =0xFFFFAA00
	adds r0, r0, r1
	b _080A3EFA
	.align 2, 0
_080A3ED8: .4byte 0x0000AD07
_080A3EDC: .4byte 0x0836B524
_080A3EE0: .4byte 0xFFFFC000
_080A3EE4: .4byte 0xFFFFFCD0
_080A3EE8: .4byte 0xFFFFAA00
_080A3EEC:
	movs r0, #0xcc
	lsls r0, r0, #2
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	movs r2, #0xac
	lsls r2, r2, #7
	adds r0, r0, r2
_080A3EFA:
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3F02:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #2
	adds r0, #3
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A3F50 @ =0x0836B524
	adds r1, r1, r2
	bl SetDDP
	mov r1, sb
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A3F80
	ldr r2, [r7, #0x5c]
	cmp r2, #0
	bge _080A3F58
	ldr r0, _080A3F54 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _080A3F70
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	b _080A3F74
	.align 2, 0
_080A3F50: .4byte 0x0836B524
_080A3F54: .4byte pZero2
_080A3F58:
	ldr r0, _080A3F6C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080A3F70
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	b _080A3F74
	.align 2, 0
_080A3F6C: .4byte pZero2
_080A3F70:
	lsls r0, r2, #1
	adds r0, r0, r2
_080A3F74:
	lsls r0, r0, #7
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	movs r0, #0x14
	strb r0, [r7, #0xe]
	b _080A44AE
_080A3F80:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A3F98
	ldr r0, [r7, #0x54]
	ldr r2, _080A3F94 @ =0xFFFFEE00
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A3FA6
	.align 2, 0
_080A3F94: .4byte 0xFFFFEE00
_080A3F98:
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A3FA6:
	adds r1, r0, #0
	cmp r1, #0
	bne _080A3FAE
	b _080A44AE
_080A3FAE:
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	movs r0, #0x52
	bl PlaySound
	b _080A43E0
_080A3FBC:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	ldr r0, _080A4028 @ =0xFFFFFC00
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A3FD4:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A3FE4
	str r1, [r7, #0x60]
_080A3FE4:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #2
	adds r0, #3
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A402C @ =0x0836B524
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A4034
	ldr r0, [r7, #0x54]
	ldr r2, _080A4030 @ =0xFFFFF800
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A4042
	.align 2, 0
_080A4028: .4byte 0xFFFFFC00
_080A402C: .4byte 0x0836B524
_080A4030: .4byte 0xFFFFF800
_080A4034:
	ldr r0, [r7, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A4042:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A404E
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_080A404E:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bne _080A4064
	b _080A44AE
_080A4064:
	movs r0, #0x52
	bl PlaySound
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
	b _080A43E0
_080A4072:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, _080A40DC @ =0xFFFFFD80
	str r0, [r7, #0x60]
	movs r1, #0
	mov r0, sb
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	strb r1, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A40A2:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A40B2
	str r1, [r7, #0x60]
_080A40B2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A40E0
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080A40E6
	.align 2, 0
_080A40DC: .4byte 0xFFFFFD80
_080A40E0:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A40E6:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	blt _080A40F0
	b _080A43AC
_080A40F0:
	ldr r0, [r7, #0x54]
	ldr r1, _080A4100 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A43BA
	.align 2, 0
_080A4100: .4byte 0xFFFFF800
_080A4104:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, _080A4194 @ =0xFFFFFF00
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x68]
	movs r1, #0
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	mov r0, sb
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A4140:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #5
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A415C
	str r1, [r7, #0x60]
_080A415C:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A417C
	subs r0, #1
	strb r0, [r7, #0x12]
_080A417C:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	bne _080A418A
	b _080A4490
_080A418A:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A4496
	.align 2, 0
_080A4194: .4byte 0xFFFFFF00
_080A4198:
	ldr r1, _080A4218 @ =0x0000AD08
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080A421C @ =0x0836B554
	bl SetDDP
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A41B0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #1
	adds r0, #3
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A4220 @ =0x0836B824
	adds r1, r1, r2
	bl SetDDP
	mov r1, sb
	ldr r0, [r1]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A4228
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	ldr r0, _080A4224 @ =0xFFFFFE00
	str r0, [r7, #0x60]
	movs r0, #0x52
	bl PlaySound
	movs r1, #0
	mov r2, sb
	str r1, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	b _080A43E0
	.align 2, 0
_080A4218: .4byte 0x0000AD08
_080A421C: .4byte 0x0836B554
_080A4220: .4byte 0x0836B824
_080A4224: .4byte 0xFFFFFE00
_080A4228:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A4240
	ldr r0, [r7, #0x54]
	ldr r1, _080A423C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A424E
	.align 2, 0
_080A423C: .4byte 0xFFFFEE00
_080A4240:
	ldr r0, [r7, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A424E:
	adds r4, r0, #0
	cmp r4, #0
	bne _080A4256
	b _080A44AE
_080A4256:
	movs r0, #0x52
	bl PlaySound
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	ldr r0, _080A4278 @ =0xFFFFFC00
	str r0, [r7, #0x60]
	b _080A43E0
	.align 2, 0
_080A4278: .4byte 0xFFFFFC00
_080A427C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A4282:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A4292
	str r1, [r7, #0x60]
_080A4292:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r2, r1, #1
	adds r0, #3
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080A42D8 @ =0x0836B824
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A42E0
	ldr r0, [r7, #0x54]
	ldr r1, _080A42DC @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A42EE
	.align 2, 0
_080A42D8: .4byte 0x0836B824
_080A42DC: .4byte 0xFFFFF800
_080A42E0:
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A42EE:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A42FA
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_080A42FA:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bne _080A4310
	b _080A44AE
_080A4310:
	movs r0, #0x52
	bl PlaySound
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
	b _080A43E0
_080A431E:
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	movs r1, #0
	mov r0, sb
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	strb r1, [r7, #0x12]
	ldr r0, _080A4388 @ =0xFFFFFD80
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A434E:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A435E
	str r1, [r7, #0x60]
_080A435E:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A438C
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080A4392
	.align 2, 0
_080A4388: .4byte 0xFFFFFD80
_080A438C:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A4392:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _080A43AC
	ldr r0, [r7, #0x54]
	ldr r1, _080A43A8 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToRight1
	b _080A43BA
	.align 2, 0
_080A43A8: .4byte 0xFFFFF800
_080A43AC:
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r7, #0x58]
	bl PushoutToLeft1
_080A43BA:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A43C6
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_080A43C6:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080A44AE
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_080A43E0:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080A44AE
_080A43E8:
	movs r5, #0
	mov r0, sb
	str r5, [r0]
	movs r1, #0x90
	adds r1, r1, r7
	mov r8, r1
	str r5, [r1]
	adds r6, r7, #0
	adds r6, #0x94
	strb r5, [r6]
	ldrb r1, [r7, #0xa]
	movs r4, #0xfb
	adds r0, r4, #0
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, _080A448C @ =0xFFFFFF00
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x68]
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	mov r2, sb
	str r5, [r2]
	mov r0, r8
	str r5, [r0]
	strb r5, [r6]
	ldrb r0, [r7, #0xa]
	ands r4, r0
	strb r4, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A443A:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #5
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A4456
	str r1, [r7, #0x60]
_080A4456:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A4476
	subs r0, #1
	strb r0, [r7, #0x12]
_080A4476:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080A4490
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A4496
	.align 2, 0
_080A448C: .4byte 0xFFFFFF00
_080A4490:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A4496:
	strb r0, [r7, #0xa]
	cmp r2, #0
	bne _080A44AE

	thumb_func_start FUN_080a449c
FUN_080a449c: @ 0x080A449C
	ldr r1, _080A44BC @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080A44AE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A44BC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a44c0
FUN_080a44c0: @ 0x080A44C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A44E2
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	b _080A4CB8
_080A44E2:
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bne _080A44EC
	movs r0, #8
	strb r0, [r4, #0xe]
_080A44EC:
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _080A44F4
	b _080A4CCA
_080A44F4:
	lsls r0, r0, #2
	ldr r1, _080A4500 @ =_080A4504
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A4500: .4byte _080A4504
_080A4504: @ jump table
	.4byte _080A4528 @ case 0
	.4byte _080A4588 @ case 1
	.4byte _080A45DC @ case 2
	.4byte _080A461E @ case 3
	.4byte _080A4674 @ case 4
	.4byte _080A4700 @ case 5
	.4byte _080A4B0C @ case 6
	.4byte _080A4B32 @ case 7
	.4byte _080A4B38 @ case 8
_080A4528:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0xad
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A4560
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A4566
_080A4560:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A4566:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4588:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A45A8
	ldr r0, [r4, #0x54]
	ldr r2, _080A45A4 @ =0xFFFFD600
	adds r0, r0, r2
	b _080A45B0
	.align 2, 0
_080A45A4: .4byte 0xFFFFD600
_080A45A8:
	ldr r0, [r4, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
_080A45B0:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, _080A45D8 @ =0xFFFF9C00
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080A45D0
	b _080A4CCA
_080A45D0:
	movs r0, #2
	rsbs r0, r0, #0
	b _080A4B26
	.align 2, 0
_080A45D8: .4byte 0xFFFF9C00
_080A45DC:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A45FC
	ldr r0, [r4, #0x54]
	ldr r1, _080A45F8 @ =0xFFFFD600
	adds r0, r0, r1
	b _080A4604
	.align 2, 0
_080A45F8: .4byte 0xFFFFD600
_080A45FC:
	ldr r0, [r4, #0x54]
	movs r2, #0xa8
	lsls r2, r2, #6
	adds r0, r0, r2
_080A4604:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _080A4638 @ =0xFFFF9C00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0xad
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A461E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4640
	ldr r0, [r4, #0x54]
	ldr r2, _080A463C @ =0xFFFFD600
	adds r0, r0, r2
	b _080A4648
	.align 2, 0
_080A4638: .4byte 0xFFFF9C00
_080A463C: .4byte 0xFFFFD600
_080A4640:
	ldr r0, [r4, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #6
	adds r0, r0, r1
_080A4648:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, _080A4670 @ =0xFFFF9C00
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A4668
	b _080A4CCA
_080A4668:
	movs r0, #9
	rsbs r0, r0, #0
	b _080A4B26
	.align 2, 0
_080A4670: .4byte 0xFFFF9C00
_080A4674:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	movs r1, #0xad
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r5, #0x58]
	ldr r1, _080A46A4 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A46B0
	ldr r0, [r4, #0x54]
	ldr r2, _080A46A8 @ =0xFFFF6800
	adds r1, r0, r2
	ldr r2, _080A46AC @ =0xFFFFE000
	b _080A46BC
	.align 2, 0
_080A46A4: .4byte 0xFFFFC000
_080A46A8: .4byte 0xFFFF6800
_080A46AC: .4byte 0xFFFFE000
_080A46B0:
	ldr r0, [r4, #0x54]
	movs r2, #0x98
	lsls r2, r2, #8
	adds r1, r0, r2
	movs r2, #0x80
	lsls r2, r2, #6
_080A46BC:
	adds r0, r0, r2
	str r0, [r4, #0x54]
	movs r0, #0x2c
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	subs r0, r1, r0
	movs r1, #0x2c
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xf2
	lsls r0, r0, #8
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x2c
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x2b
	strb r0, [r4, #0x12]
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r2, #0
	movs r3, #0
	bl CreateSolid13
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4700:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A4710
	str r1, [r4, #0x60]
_080A4710:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bne _080A4736
	b _080A491C
_080A4736:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080A4746
	b _080A48E8
_080A4746:
	movs r0, #0
	str r0, [r4, #0x2c]
	ldr r0, _080A48BC @ =0x00000113
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x8c
	str r0, [sp, #0x24]
	adds r1, r4, #0
	adds r1, #0x90
	str r1, [sp, #0x28]
	adds r2, r4, #0
	adds r2, #0x94
	str r2, [sp, #0x2c]
	mov r7, sp
	ldr r5, _080A48C0 @ =0x0836B9EC
	ldr r6, _080A48C4 @ =RNG_0202f388
	ldr r0, _080A48C8 @ =0x000343FD
	mov sl, r0
	ldr r1, _080A48CC @ =0x00269EC3
	mov sb, r1
	movs r2, #3
	mov r8, r2
	movs r0, #1
	str r0, [sp, #0x18]
_080A4778:
	ldr r0, [r4, #0x54]
	ldr r1, [r5]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5]
	ldr r2, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	mov r0, sp
	ldr r2, _080A48D4 @ =0x0000AD01
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #8]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #8]
	ldr r0, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	mov r0, sp
	ldr r2, _080A48D8 @ =0x0000AD02
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #0x10]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #0x10]
	ldr r2, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	mov r0, sp
	ldr r2, _080A48DC @ =0x0000AD03
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #0x18]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #0x18]
	ldr r0, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	mov r0, sp
	ldr r2, _080A48E0 @ =0x0000AD04
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #0x20]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #0x20]
	ldr r2, _080A48D0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r6]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r6]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	mov r0, sp
	ldr r2, _080A48E4 @ =0x0000AD05
	bl FUN_080bec8c
	adds r5, #0x28
	ldr r0, [sp, #0x18]
	subs r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0
	blt _080A489E
	b _080A4778
_080A489E:
	movs r1, #0
	ldrb r2, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r4, #0xa]
	ldr r2, [sp, #0x24]
	str r1, [r2]
	ldr r0, [sp, #0x28]
	str r1, [r0]
	ldr r2, [sp, #0x2c]
	strb r1, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	b _080A4CB4
	.align 2, 0
_080A48BC: .4byte 0x00000113
_080A48C0: .4byte 0x0836B9EC
_080A48C4: .4byte RNG_0202f388
_080A48C8: .4byte 0x000343FD
_080A48CC: .4byte 0x00269EC3
_080A48D0: .4byte 0xFFFFE200
_080A48D4: .4byte 0x0000AD01
_080A48D8: .4byte 0x0000AD02
_080A48DC: .4byte 0x0000AD03
_080A48E0: .4byte 0x0000AD04
_080A48E4: .4byte 0x0000AD05
_080A48E8:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r3, [r4, #0xa]
	movs r2, #0xfb
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r4, #0xa]
	ldr r3, [r4, #0x2c]
	adds r0, r3, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r0, [r3, #0xa]
	ands r2, r0
	strb r2, [r3, #0xa]
	str r1, [r4, #0x2c]
	b _080A4B2A
_080A491C:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080A493C
	ldr r0, [r4, #0x54]
	ldr r1, _080A4934 @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A4938 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight2
	b _080A494E
	.align 2, 0
_080A4934: .4byte 0xFFFFE000
_080A4938: .4byte 0xFFFFF800
_080A493C:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080A4ADC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft2
_080A494E:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A495E
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x5c]
_080A495E:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080A4968
	b _080A4CCA
_080A4968:
	movs r0, #0
	str r0, [r4, #0x2c]
	ldr r0, _080A4AE0 @ =0x00000113
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x8c
	str r0, [sp, #0x24]
	adds r1, r4, #0
	adds r1, #0x90
	str r1, [sp, #0x28]
	adds r2, r4, #0
	adds r2, #0x94
	str r2, [sp, #0x2c]
	add r5, sp, #8
	ldr r6, _080A4AE4 @ =0x0836B9EC
	ldr r7, _080A4AE8 @ =RNG_0202f388
	ldr r0, _080A4AEC @ =0x000343FD
	mov sl, r0
	ldr r1, _080A4AF0 @ =0x00269EC3
	mov sb, r1
	movs r2, #3
	mov r8, r2
	movs r0, #1
	str r0, [sp, #0x1c]
_080A499A:
	ldr r0, [r4, #0x54]
	ldr r1, [r6]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6]
	ldr r2, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4AF8 @ =0x0000AD01
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #8]
	ldr r0, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4AFC @ =0x0000AD02
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x10]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #0x10]
	ldr r2, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4B00 @ =0x0000AD03
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x18]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #0x18]
	ldr r0, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4B04 @ =0x0000AD04
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x20]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, [r6, #0x20]
	ldr r2, _080A4AF4 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4B08 @ =0x0000AD05
	bl FUN_080bec8c
	adds r6, #0x28
	ldr r0, [sp, #0x1c]
	subs r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #0
	blt _080A4AC0
	b _080A499A
_080A4AC0:
	movs r1, #0
	ldrb r2, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r2
	strb r0, [r4, #0xa]
	ldr r2, [sp, #0x24]
	str r1, [r2]
	ldr r0, [sp, #0x28]
	str r1, [r0]
	ldr r2, [sp, #0x2c]
	strb r1, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	b _080A4CB4
	.align 2, 0
_080A4ADC: .4byte 0xFFFFF800
_080A4AE0: .4byte 0x00000113
_080A4AE4: .4byte 0x0836B9EC
_080A4AE8: .4byte RNG_0202f388
_080A4AEC: .4byte 0x000343FD
_080A4AF0: .4byte 0x00269EC3
_080A4AF4: .4byte 0xFFFFE200
_080A4AF8: .4byte 0x0000AD01
_080A4AFC: .4byte 0x0000AD02
_080A4B00: .4byte 0x0000AD03
_080A4B04: .4byte 0x0000AD04
_080A4B08: .4byte 0x0000AD05
_080A4B0C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4B22
	b _080A4CCA
_080A4B22:
	movs r0, #0x11
	rsbs r0, r0, #0
_080A4B26:
	ands r1, r0
	str r1, [r2]
_080A4B2A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A4CCA
_080A4B32:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4B38:
	ldr r0, _080A4CDC @ =0x00000113
	bl PlaySound
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _080A4B74
	adds r0, r4, #0
	adds r0, #0x8c
	movs r2, #0
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r3, [r4, #0xa]
	movs r1, #0xfb
	adds r0, r1, #0
	ands r0, r3
	strb r0, [r4, #0xa]
	ldr r3, [r4, #0x2c]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r0, [r3, #0xa]
	ands r1, r0
	strb r1, [r3, #0xa]
_080A4B74:
	add r5, sp, #0x10
	ldr r6, _080A4CE0 @ =0x0836B9EC
	ldr r7, _080A4CE4 @ =RNG_0202f388
	ldr r0, _080A4CE8 @ =0x000343FD
	mov sl, r0
	ldr r1, _080A4CEC @ =0x00269EC3
	mov sb, r1
	movs r2, #3
	mov r8, r2
	movs r0, #1
	str r0, [sp, #0x20]
_080A4B8A:
	ldr r0, [r4, #0x54]
	ldr r1, [r6]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6]
	ldr r2, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4CF4 @ =0x0000AD01
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #8]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #8]
	ldr r0, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4CF8 @ =0x0000AD02
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x10]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #0x10]
	ldr r2, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4CFC @ =0x0000AD03
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x18]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #0x18]
	ldr r0, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r0, r8
	ands r3, r0
	adds r0, r5, #0
	ldr r2, _080A4D00 @ =0x0000AD04
	bl FUN_080bec8c
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #0x20]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	ldr r1, [r6, #0x20]
	ldr r2, _080A4CF0 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	ldr r0, [r7]
	mov r3, sl
	muls r3, r0, r3
	add r3, sb
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r7]
	lsrs r3, r3, #0x11
	mov r2, r8
	ands r3, r2
	adds r0, r5, #0
	ldr r2, _080A4D04 @ =0x0000AD05
	bl FUN_080bec8c
	adds r6, #0x28
	ldr r0, [sp, #0x20]
	subs r0, #1
	str r0, [sp, #0x20]
	cmp r0, #0
	blt _080A4CB0
	b _080A4B8A
_080A4CB0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
_080A4CB4:
	ands r0, r1
	strb r0, [r4, #0xa]
_080A4CB8:
	ldr r1, _080A4D08 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A4CCA:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4CDC: .4byte 0x00000113
_080A4CE0: .4byte 0x0836B9EC
_080A4CE4: .4byte RNG_0202f388
_080A4CE8: .4byte 0x000343FD
_080A4CEC: .4byte 0x00269EC3
_080A4CF0: .4byte 0xFFFFE200
_080A4CF4: .4byte 0x0000AD01
_080A4CF8: .4byte 0x0000AD02
_080A4CFC: .4byte 0x0000AD03
_080A4D00: .4byte 0x0000AD04
_080A4D04: .4byte 0x0000AD05
_080A4D08: .4byte gProjectileFnTable

	thumb_func_start FUN_080a4d0c
FUN_080a4d0c: @ 0x080A4D0C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A4D1A
	b _080A4EDC
_080A4D1A:
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bne _080A4D22
	b _080A4EDC
_080A4D22:
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080A4D2A
	b _080A4EEE
_080A4D2A:
	lsls r0, r0, #2
	ldr r1, _080A4D34 @ =_080A4D38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A4D34: .4byte _080A4D38
_080A4D38: @ jump table
	.4byte _080A4D50 @ case 0
	.4byte _080A4DB0 @ case 1
	.4byte _080A4DEA @ case 2
	.4byte _080A4E48 @ case 3
	.4byte _080A4E8E @ case 4
	.4byte _080A4EA2 @ case 5
_080A4D50:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A4D80 @ =0x0836B9BC
	bl SetDDP
	ldr r1, _080A4D84 @ =0x0000AE01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A4D88
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A4D8E
	.align 2, 0
_080A4D80: .4byte 0x0836B9BC
_080A4D84: .4byte 0x0000AE01
_080A4D88:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A4D8E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4DB0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4DD4
	ldr r0, [r4, #0x54]
	ldr r1, _080A4DD0 @ =0xFFFFC000
	b _080A4DDA
	.align 2, 0
_080A4DD0: .4byte 0xFFFFC000
_080A4DD4:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #7
_080A4DDA:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	b _080A4E80
_080A4DEA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r1, _080A4E18 @ =0x0000AE02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A4E1C @ =0x0836B9D4
	bl SetDDP
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080A4E20
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A4E26
	.align 2, 0
_080A4E18: .4byte 0x0000AE02
_080A4E1C: .4byte 0x0836B9D4
_080A4E20:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A4E26:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4E48:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A4E6C
	ldr r0, [r4, #0x54]
	ldr r1, _080A4E68 @ =0xFFFFC000
	b _080A4E72
	.align 2, 0
_080A4E68: .4byte 0xFFFFC000
_080A4E6C:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #7
_080A4E72:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
_080A4E80:
	ands r0, r1
	cmp r0, #0
	beq _080A4EEE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A4EEE
_080A4E8E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A4EC0 @ =0x0836B9A4
	bl SetDDP
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A4EA2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0x12]
	cmp r1, #0x1d
	bhi _080A4ECC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A4EC4
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A4ECA
	.align 2, 0
_080A4EC0: .4byte 0x0836B9A4
_080A4EC4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A4ECA:
	strb r0, [r4, #0xa]
_080A4ECC:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A4EDC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A4EEE
_080A4EDC:
	ldr r1, _080A4EF4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A4EEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4EF4: .4byte gProjectileFnTable
