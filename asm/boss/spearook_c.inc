	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08062bb4
FUN_08062bb4: @ 0x08062BB4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _08062BD4 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08062BD8
	cmp r5, #1
	beq _08062C12
	b _08062C70
	.align 2, 0
_08062BD4: .4byte 0xFFFFEE00
_08062BD8:
	ldr r0, _08062C4C @ =0x00000103
	bl PlaySound
	ldr r3, _08062C50 @ =0x08365938
	ldr r2, _08062C54 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08062C58 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08062C5C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r4, #0x12]
	movs r0, #0xff
	strb r0, [r4, #0x13]
	str r5, [r4, #0x64]
	ldr r1, _08062C60 @ =0x0000D603
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062C12:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08062C70
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08062C64 @ =0x0836585C
	bl SetDDP
	ldr r2, _08062C54 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08062C58 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08062C5C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08062C68
	movs r0, #0xc
	b _08062C6A
	.align 2, 0
_08062C4C: .4byte 0x00000103
_08062C50: .4byte 0x08365938
_08062C54: .4byte RNG_0202f388
_08062C58: .4byte 0x000343FD
_08062C5C: .4byte 0x00269EC3
_08062C60: .4byte 0x0000D603
_08062C64: .4byte 0x0836585C
_08062C68:
	movs r0, #0xb
_08062C6A:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08062C70:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08062c78
FUN_08062c78: @ 0x08062C78
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _08062C9C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08062C92
	b _08062E1E
_08062C92:
	lsls r0, r0, #2
	ldr r1, _08062CA0 @ =_08062CA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08062C9C: .4byte 0xFFFFEE00
_08062CA0: .4byte _08062CA4
_08062CA4: @ jump table
	.4byte _08062CBC @ case 0
	.4byte _08062D90 @ case 1
	.4byte _08062CD8 @ case 2
	.4byte _08062D90 @ case 3
	.4byte _08062DBC @ case 4
	.4byte _08062DD2 @ case 5
_08062CBC:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _08062CC8
	ldr r0, [r4, #0x64]
	adds r0, #1
	b _08062CCA
_08062CC8:
	movs r0, #0
_08062CCA:
	str r0, [r4, #0x64]
	movs r0, #0
	strb r0, [r4, #0x13]
	ldr r1, _08062CD4 @ =0x0000D609
	b _08062D84
	.align 2, 0
_08062CD4: .4byte 0x0000D609
_08062CD8:
	movs r1, #0xa0
	lsls r1, r1, #5
	ldr r2, _08062DA8 @ =0xFFFFBB00
	adds r0, r4, #0
	bl FUN_08061b68
	ldr r5, _08062DAC @ =0xFFFFF500
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062CF4
	movs r5, #0xb0
	lsls r5, r5, #4
_08062CF4:
	ldr r3, _08062DB0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r2, [r0, r6]
	adds r0, r5, #0
	muls r0, r2, r0
	cmp r0, #0
	bge _08062D18
	adds r0, #0xff
_08062D18:
	asrs r6, r0, #8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r3, [r0, r1]
	rsbs r1, r3, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #8
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08062D3C
	adds r0, #0xff
_08062D3C:
	asrs r0, r0, #8
	adds r6, r6, r0
	adds r0, r5, #0
	muls r0, r3, r0
	cmp r0, #0
	bge _08062D4A
	adds r0, #0xff
_08062D4A:
	asrs r5, r0, #8
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #8
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08062D62
	adds r0, #0xff
_08062D62:
	asrs r0, r0, #8
	adds r5, r5, r0
	ldr r0, _08062DB4 @ =0x0000012F
	bl PlaySound
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r3, #1
	ands r2, r3
	movs r3, #0
	bl FUN_080b1698
	ldr r1, _08062DB8 @ =0x0000D60B
_08062D84:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062D90:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08062E1E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08062E1E
	.align 2, 0
_08062DA8: .4byte 0xFFFFBB00
_08062DAC: .4byte 0xFFFFF500
_08062DB0: .4byte gSineTable
_08062DB4: .4byte 0x0000012F
_08062DB8: .4byte 0x0000D60B
_08062DBC:
	movs r0, #0x2d
	str r0, [r4, #0x68]
	ldr r1, _08062DEC @ =0x0000D603
	adds r0, r4, #0
	movs r2, #0xa
	movs r3, #1
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062DD2:
	ldr r0, [r4, #0x68]
	subs r3, r0, #1
	str r3, [r4, #0x68]
	cmp r3, #0
	bne _08062E18
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08062DF0
	movs r0, #0xd
	b _08062E14
	.align 2, 0
_08062DEC: .4byte 0x0000D603
_08062DF0:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bgt _08062E12
	ldr r2, _08062E24 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08062E28 @ =0x000343FD
	muls r0, r1, r0
	ldr r6, _08062E2C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #5
	bls _08062E16
_08062E12:
	movs r0, #0xc
_08062E14:
	strb r0, [r4, #0xd]
_08062E16:
	strb r3, [r4, #0xe]
_08062E18:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08062E1E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062E24: .4byte RNG_0202f388
_08062E28: .4byte 0x000343FD
_08062E2C: .4byte 0x00269EC3

	thumb_func_start FUN_08062e30
FUN_08062e30: @ 0x08062E30
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _08062E54 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08062E4A
	b _08062FCE
_08062E4A:
	lsls r0, r0, #2
	ldr r1, _08062E58 @ =_08062E5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08062E54: .4byte 0xFFFFEE00
_08062E58: .4byte _08062E5C
_08062E5C: @ jump table
	.4byte _08062E74 @ case 0
	.4byte _08062F3E @ case 1
	.4byte _08062E90 @ case 2
	.4byte _08062F3E @ case 3
	.4byte _08062F6C @ case 4
	.4byte _08062F82 @ case 5
_08062E74:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _08062E80
	ldr r0, [r4, #0x64]
	adds r0, #1
	b _08062E82
_08062E80:
	movs r0, #0
_08062E82:
	str r0, [r4, #0x64]
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r1, _08062E8C @ =0x0000D60A
	b _08062F32
	.align 2, 0
_08062E8C: .4byte 0x0000D60A
_08062E90:
	movs r1, #0xa0
	lsls r1, r1, #5
	ldr r2, _08062F58 @ =0xFFFFBB00
	adds r0, r4, #0
	bl FUN_08061b68
	ldr r5, _08062F5C @ =0xFFFFF500
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062EAC
	movs r5, #0xb0
	lsls r5, r5, #4
_08062EAC:
	ldr r3, _08062F60 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r2, [r0, r6]
	adds r0, r5, #0
	muls r0, r2, r0
	cmp r0, #0
	bge _08062ED0
	adds r0, #0xff
_08062ED0:
	asrs r6, r0, #8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r3, [r0, r1]
	rsbs r1, r3, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #8
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08062EF0
	adds r0, #0xff
_08062EF0:
	asrs r0, r0, #8
	adds r6, r6, r0
	adds r0, r5, #0
	muls r0, r3, r0
	cmp r0, #0
	bge _08062EFE
	adds r0, #0xff
_08062EFE:
	asrs r5, r0, #8
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #8
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08062F12
	adds r0, #0xff
_08062F12:
	asrs r0, r0, #8
	adds r5, r5, r0
	ldr r0, _08062F64 @ =0x0000012F
	bl PlaySound
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r3, #1
	ands r2, r3
	bl FUN_080b1698
	ldr r1, _08062F68 @ =0x0000D60C
_08062F32:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062F3E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08062FCE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08062FCE
	.align 2, 0
_08062F58: .4byte 0xFFFFBB00
_08062F5C: .4byte 0xFFFFF500
_08062F60: .4byte gSineTable
_08062F64: .4byte 0x0000012F
_08062F68: .4byte 0x0000D60C
_08062F6C:
	movs r0, #0x2d
	str r0, [r4, #0x68]
	ldr r1, _08062F9C @ =0x0000D603
	adds r0, r4, #0
	movs r2, #0xa
	movs r3, #1
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08062F82:
	ldr r0, [r4, #0x68]
	subs r3, r0, #1
	str r3, [r4, #0x68]
	cmp r3, #0
	bne _08062FC8
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08062FA0
	movs r0, #0xd
	b _08062FC4
	.align 2, 0
_08062F9C: .4byte 0x0000D603
_08062FA0:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bgt _08062FC2
	ldr r2, _08062FD4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08062FD8 @ =0x000343FD
	muls r0, r1, r0
	ldr r6, _08062FDC @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #4
	bhi _08062FC6
_08062FC2:
	movs r0, #0xb
_08062FC4:
	strb r0, [r4, #0xd]
_08062FC6:
	strb r3, [r4, #0xe]
_08062FC8:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08062FCE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062FD4: .4byte RNG_0202f388
_08062FD8: .4byte 0x000343FD
_08062FDC: .4byte 0x00269EC3

	thumb_func_start FUN_08062fe0
FUN_08062fe0: @ 0x08062FE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldr r0, [r6, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, _08063000 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08063004
	cmp r5, #1
	beq _0806301E
	b _08063062
	.align 2, 0
_08063000: .4byte 0xFFFFEE00
_08063004:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08063068 @ =0x083657CC
	bl SetDDP
	ldr r1, _0806306C @ =0x0000D604
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806301E:
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	movs r1, #0xf
	bl __modsi3
	str r0, [r4, #0x5c]
	cmp r0, #0
	bne _0806303C
	movs r1, #0xf0
	lsls r1, r1, #4
	ldr r2, _08063070 @ =0xFFFFCF00
	adds r0, r4, #0
	bl FUN_08061b68
_0806303C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08063062
	adds r2, r6, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063062:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08063068: .4byte 0x083657CC
_0806306C: .4byte 0x0000D604
_08063070: .4byte 0xFFFFCF00

	thumb_func_start FUN_08063074
FUN_08063074: @ 0x08063074
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080630BA
	cmp r0, #1
	bgt _08063088
	cmp r0, #0
	beq _08063092
	b _0806315C
_08063088:
	cmp r0, #2
	beq _0806311A
	cmp r0, #3
	beq _08063138
	b _0806315C
_08063092:
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r2]
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #9
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080630BA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r5, #0
	cmp r1, #0
	bge _080630E4
	ldr r1, _080630E0 @ =0xFFFFEA00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806310C
	b _080630FC
	.align 2, 0
_080630E0: .4byte 0xFFFFEA00
_080630E4:
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08063106
_080630FC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	b _08063108
_08063106:
	movs r5, #1
_08063108:
	cmp r5, #0
	beq _08063112
_0806310C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08063112:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0806315C
_0806311A:
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	str r1, [r4, #0x5c]
	movs r0, #0x18
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	cmp r1, #0
	bge _0806312C
	movs r0, #0x18
_0806312C:
	str r0, [r4, #0x64]
	lsrs r0, r1, #0x1f
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08063138:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	cmp r1, #0
	bge _08063152
	cmp r0, #1
	bne _08063156
	b _0806315C
_08063152:
	cmp r0, #0
	beq _0806315C
_08063156:
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0806315C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_0806316c
nop_0806316c: @ 0x0806316C
	bx lr
	.align 2, 0

	thumb_func_start nop_08063170
nop_08063170: @ 0x08063170
	bx lr
	.align 2, 0

	thumb_func_start FUN_08063174
FUN_08063174: @ 0x08063174
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08063182
	b _0806328C
_08063182:
	lsls r0, r0, #2
	ldr r1, _0806318C @ =_08063190
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806318C: .4byte _08063190
_08063190: @ jump table
	.4byte _080631A4 @ case 0
	.4byte _080631E8 @ case 1
	.4byte _0806320C @ case 2
	.4byte _08063216 @ case 3
	.4byte _0806328C @ case 4
_080631A4:
	ldr r3, _08063204 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _080631C6
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080631C6
	ldr r0, _08063208 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080631C6:
	movs r1, #0
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080631E8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806328C
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2]
	b _08063286
	.align 2, 0
_08063204: .4byte gStageRun
_08063208: .4byte 0x0000FFFE
_0806320C:
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08063216:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0806328C
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #0x10
	bl TryDropItem
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08063294 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08063298 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	ldr r2, _0806329C @ =gStageRun
	ldrb r0, [r2, #0x12]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_08063286:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806328C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063294: .4byte 0xFFFFF400
_08063298: .4byte gBossFnTable
_0806329C: .4byte gStageRun

	thumb_func_start FUN_080632a0
FUN_080632a0: @ 0x080632A0
	push {r4, r5, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	bne _080632EA
	ldr r4, _080632F0 @ =gStageRun
	ldrh r3, [r4, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _080632CC
	ldrb r1, [r4, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080632CC
	ldr r0, _080632F4 @ =0x0000FFFE
	ands r0, r3
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r4, #8]
_080632CC:
	adds r0, r2, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_080632EA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080632F0: .4byte gStageRun
_080632F4: .4byte 0x0000FFFE

	thumb_func_start FUN_080632f8
FUN_080632f8: @ 0x080632F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	mov r8, r0
	ldrb r4, [r6, #0xe]
	cmp r4, #1
	beq _0806334A
	cmp r4, #1
	bgt _08063316
	cmp r4, #0
	beq _08063324
	b _080634FA
_08063316:
	cmp r4, #2
	bne _0806331C
	b _0806342C
_0806331C:
	cmp r4, #3
	bne _08063322
	b _0806343A
_08063322:
	b _080634FA
_08063324:
	ldr r1, _08063418 @ =0x0000D601
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0806334A:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08063402
	ldr r5, _0806341C @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08063420 @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _08063424 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	lsls r7, r0, #8
	str r7, [sp]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	lsls r3, r0, #8
	str r3, [sp, #4]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsrs r1, r0, #8
	ldr r5, _08063428 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r0, r4, #0
	muls r0, r7, r0
	cmp r0, #0
	bge _080633AE
	adds r0, #0xff
_080633AE:
	asrs r2, r0, #8
	str r2, [sp, #8]
	lsls r0, r1, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	rsbs r0, r1, #0
	muls r0, r3, r0
	cmp r0, #0
	bge _080633C4
	adds r0, #0xff
_080633C4:
	asrs r0, r0, #8
	adds r0, r0, r2
	str r0, [sp, #8]
	adds r0, r1, #0
	muls r0, r7, r0
	cmp r0, #0
	bge _080633D4
	adds r0, #0xff
_080633D4:
	asrs r1, r0, #8
	add r2, sp, #8
	str r1, [r2, #4]
	ldr r0, [sp, #4]
	muls r0, r4, r0
	cmp r0, #0
	bge _080633E4
	adds r0, #0xff
_080633E4:
	asrs r0, r0, #8
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, [r6, #0x54]
	ldr r1, [sp, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	str r0, [r2, #4]
	movs r0, #2
	adds r1, r2, #0
	bl CreateSmoke
_08063402:
	mov r0, r8
	adds r0, #0xbc
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080634FA
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080634FA
	.align 2, 0
_08063418: .4byte 0x0000D601
_0806341C: .4byte RNG_0202f388
_08063420: .4byte 0x000343FD
_08063424: .4byte 0x00269EC3
_08063428: .4byte gSineTable
_0806342C:
	movs r0, #0
	strb r0, [r6, #0x12]
	strb r0, [r6, #0x13]
	str r0, [r6, #0x64]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0806343A:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080634FA
	ldr r5, _08063508 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [r6, #0x64]
	muls r0, r2, r0
	cmp r0, #0
	bge _08063470
	adds r0, #0xff
_08063470:
	asrs r1, r0, #8
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	bge _0806348E
	adds r0, #0xff
_0806348E:
	asrs r1, r0, #8
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldrb r1, [r6, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080634AE
	movs r0, #0x2a
	bl PlaySound
_080634AE:
	ldr r0, [r6, #0x64]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080634FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0806350C @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080634FA:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063508: .4byte gSineTable
_0806350C: .4byte gBossFnTable

	thumb_func_start nop_08063510
nop_08063510: @ 0x08063510
	bx lr
	.align 2, 0

	thumb_func_start FUN_08063514
FUN_08063514: @ 0x08063514
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _08063524
	cmp r2, #1
	beq _08063542
	b _080635B2
_08063524:
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08063542:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08063552
	str r1, [r4, #0x60]
_08063552:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080635B2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080635B8 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080635B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080635B8: .4byte gBossFnTable
