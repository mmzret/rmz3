	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08048788
FUN_08048788: @ 0x08048788
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08048814
	cmp r5, #1
	bgt _0804879C
	cmp r5, #0
	beq _080487A8
	b _080488C4
_0804879C:
	cmp r5, #2
	beq _08048838
	cmp r5, #3
	bne _080487A6
	b _080488A4
_080487A6:
	b _080488C4
_080487A8:
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
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _080487D2
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x54]
	str r1, [r4, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r4, #0x58]
_080487D2:
	adds r0, r4, #0
	adds r0, #0x22
	strb r5, [r0]
	ldr r1, _08048834 @ =0x0000330A
	adds r0, r4, #0
	bl SetMotion
	adds r6, r4, #0
	adds r6, #0xc6
	ldrb r0, [r6]
	cmp r0, #0
	beq _080487F0
	bl RemovePaletteAnimation
	strb r5, [r6]
_080487F0:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x1c
	bl StartPaletteAnimation
	movs r0, #0x1c
	strb r0, [r6]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08048814:
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0804882C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804882C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080488C4
	.align 2, 0
_08048834: .4byte 0x0000330A
_08048838:
	ldrb r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r5, r4, #0
	adds r5, #0xc6
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804885C
	bl RemovePaletteAnimation
	movs r0, #0
	strb r0, [r5]
_0804885C:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08048880
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x16
	bl StartPaletteAnimation
	movs r0, #0x16
	b _0804889C
_08048880:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x11
	bl StartPaletteAnimation
	movs r0, #0x11
_0804889C:
	strb r0, [r5]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080488A4:
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080488BE
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080488BE:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080488C4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080488cc
FUN_080488cc: @ 0x080488CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #8
	bls _080488DE
	b _08048D4A
_080488DE:
	lsls r0, r0, #2
	ldr r1, _080488E8 @ =_080488EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080488E8: .4byte _080488EC
_080488EC: @ jump table
	.4byte _08048910 @ case 0
	.4byte _0804899A @ case 1
	.4byte _080489B6 @ case 2
	.4byte _08048A08 @ case 3
	.4byte _08048AD4 @ case 4
	.4byte _08048AFE @ case 5
	.4byte _08048C14 @ case 6
	.4byte _08048C1E @ case 7
	.4byte _08048D4A @ case 8
_08048910:
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08048922
	bl RemovePaletteAnimation
	movs r0, #0
	strb r0, [r4]
_08048922:
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08048958
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x17
	bl StartPaletteAnimation
	movs r0, #0x17
	b _08048974
_08048958:
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0x12
	bl StartPaletteAnimation
	movs r0, #0x12
_08048974:
	strb r0, [r4]
	adds r0, r7, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08048D4A
_0804899A:
	adds r0, r7, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080489AE
	b _08048BFC
_080489AE:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08048BFC
_080489B6:
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _080489C8
	bl RemovePaletteAnimation
	movs r0, #0
	strb r0, [r4]
_080489C8:
	adds r1, r7, #0
	adds r1, #0x22
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080489FE
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r6, #0x80
	lsls r6, r6, #2
	adds r0, r6, #0
	orrs r1, r0
	movs r0, #0xd
	bl StartPaletteAnimation
	movs r0, #0xd
	strb r0, [r4]
_080489FE:
	movs r0, #0xa0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048A08:
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r3, [r0]
	movs r0, #0x9c
	lsls r0, r0, #7
	adds r3, r3, r0
	ldrb r1, [r7, #0x10]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xa
	adds r3, r3, r0
	ldr r4, [r7, #0x54]
	subs r3, r3, r4
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r2, [r0]
	ldr r6, _08048AC0 @ =0xFFFF9C00
	adds r2, r2, r6
	lsls r1, r1, #3
	movs r0, #0x28
	lsls r0, r1
	adds r2, r2, r0
	ldr r1, [r7, #0x58]
	subs r2, r2, r1
	adds r0, r3, #0
	cmp r3, #0
	bge _08048A40
	adds r0, #0x3f
_08048A40:
	asrs r3, r0, #6
	adds r0, r2, #0
	cmp r2, #0
	bge _08048A4A
	adds r0, #0x3f
_08048A4A:
	asrs r2, r0, #6
	adds r0, r4, r3
	str r0, [r7, #0x54]
	adds r0, r1, r2
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048A66
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048A66:
	ldrb r0, [r7, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048AAC
	ldr r5, _08048AC4 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08048AC8 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08048ACC @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r0, _08048AD0 @ =0xFFFFFC00
	adds r1, r1, r0
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	ldr r1, [r7, #0x58]
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0
	bl FUN_080bc540
_08048AAC:
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	beq _08048AB4
	b _08048BFC
_08048AB4:
	adds r0, r7, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	bl StepPaletteAnimation
	b _08048BFC
	.align 2, 0
_08048AC0: .4byte 0xFFFF9C00
_08048AC4: .4byte RNG_0202f388
_08048AC8: .4byte 0x000343FD
_08048ACC: .4byte 0x00269EC3
_08048AD0: .4byte 0xFFFFFC00
_08048AD4:
	movs r5, #0
	strb r5, [r7, #0x13]
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r7, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r7, #0x58]
	str r0, [r1]
	str r5, [r7, #0x5c]
	adds r4, r7, #0
	adds r4, #0xc6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08048AF8
	bl RemovePaletteAnimation
	strb r5, [r4]
_08048AF8:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048AFE:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	ldr r0, [r7, #0x5c]
	adds r1, r0, #0
	adds r1, #0x60
	str r1, [r7, #0x5c]
	adds r0, r7, #0
	adds r0, #0xbc
	ldr r4, [r0]
	str r4, [r7, #0x54]
	adds r0, #4
	ldr r5, [r0]
	str r5, [r7, #0x58]
	ldrb r0, [r7, #0x10]
	mov r8, r0
	mov r2, r8
	cmp r2, #0
	bne _08048B54
	ldr r3, _08048B50 @ =gSineTable
	asrs r1, r1, #8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r2, [r0, r6]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r4, r0
	str r0, [r7, #0x54]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r5, r0
	b _08048B7C
	.align 2, 0
_08048B50: .4byte gSineTable
_08048B54:
	ldr r3, _08048B94 @ =gSineTable
	asrs r1, r1, #8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r2, [r0, r6]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r0, r4, r0
	str r0, [r7, #0x54]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	subs r0, r5, r0
_08048B7C:
	str r0, [r7, #0x58]
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08048B98
	ldr r1, [r7, #0x28]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	beq _08048BB0
	ldr r0, [r1, #0x18]
	b _08048BA0
	.align 2, 0
_08048B94: .4byte gSineTable
_08048B98:
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	beq _08048BB0
	ldr r0, [r7, #0x18]
_08048BA0:
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08048BB0
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048BB0:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048BFC
	ldr r5, _08048C04 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08048C08 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _08048C0C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #4
	lsrs r1, r1, #0x15
	ldr r6, _08048C10 @ =0xFFFFFC00
	adds r1, r1, r6
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #5
	lsrs r2, r2, #0x16
	ldr r1, [r7, #0x58]
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0x40
	bl FUN_080bc540
_08048BFC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _08048D4A
	.align 2, 0
_08048C04: .4byte RNG_0202f388
_08048C08: .4byte 0x000343FD
_08048C0C: .4byte 0x00269EC3
_08048C10: .4byte 0xFFFFFC00
_08048C14:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048C1E:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	ldrb r4, [r7, #0x12]
	adds r0, r4, #0
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08048CAA
	cmp r4, #0x4f
	bhi _08048CAA
	ldr r4, _08048D58 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _08048D5C @ =0x000343FD
	mov r8, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r3, _08048D60 @ =0x00269EC3
	mov sb, r3
	add r0, sb
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	bl __umodsi3
	adds r6, r0, #0
	mov r0, r8
	muls r0, r5, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	adds r3, r0, #0
	adds r3, #0x80
	ldr r5, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r4, _08048D64 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	bge _08048C8E
	adds r0, #0xff
_08048C8E:
	asrs r2, r0, #8
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	cmp r0, #0
	bge _08048CA2
	adds r0, #0xff
_08048CA2:
	asrs r3, r0, #8
	adds r0, r5, #0
	bl FUN_080bc540
_08048CAA:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x5a
	bne _08048CF2
	movs r0, #0x45
	bl PlaySound
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r4, #0
	ldr r5, _08048D64 @ =gSineTable
_08048CC2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	lsls r2, r4, #0x1d
	movs r6, #0x80
	lsls r6, r6, #0x17
	adds r2, r2, r6
	lsrs r2, r2, #0x17
	adds r2, r2, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	lsls r2, r2, #1
	lsls r3, r4, #0x1d
	lsrs r3, r3, #0x17
	adds r3, r3, r5
	movs r6, #0
	ldrsh r3, [r3, r6]
	lsls r3, r3, #1
	bl FUN_080bc540
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls _08048CC2
_08048CF2:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x5b
	bne _08048D2C
	movs r4, #1
	ldr r5, _08048D64 @ =gSineTable
_08048CFC:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	lsls r2, r4, #0x1d
	movs r3, #0x80
	lsls r3, r3, #0x17
	adds r2, r2, r3
	lsrs r2, r2, #0x17
	adds r2, r2, r5
	movs r6, #0
	ldrsh r2, [r2, r6]
	lsls r2, r2, #1
	lsls r3, r4, #0x1d
	lsrs r3, r3, #0x17
	adds r3, r3, r5
	movs r6, #0
	ldrsh r3, [r3, r6]
	lsls r3, r3, #1
	bl FUN_080bc540
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls _08048CFC
_08048D2C:
	movs r0, #0x12
	ldrsb r0, [r7, r0]
	cmp r0, #0
	bge _08048D44
	ldr r2, _08048D68 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08048D44:
	adds r0, r7, #0
	bl UpdateEntityAnim
_08048D4A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08048D58: .4byte RNG_0202f388
_08048D5C: .4byte 0x000343FD
_08048D60: .4byte 0x00269EC3
_08048D64: .4byte gSineTable
_08048D68: .4byte gStageRun

