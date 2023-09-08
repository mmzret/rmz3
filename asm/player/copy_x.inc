	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CopyXMini_Update
CopyXMini_Update: @ 0x080359A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #2
	beq _080359D6
	ldr r1, _080359F4 @ =0x0835EBB4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080359F8 @ =0x0835EBC4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080359D6:
	ldr r0, _080359FC @ =0x0000027D
	adds r3, r4, r0
	ldr r0, [r4, #0x28]
	ldrb r2, [r0, #0xc]
	ldrb r1, [r3]
	adds r0, r2, #0
	cmp r1, r0
	beq _08035A2C
	strb r2, [r3]
	cmp r0, #2
	bne _08035A00
	movs r0, #4
	bl PlaySound
	b _08035A36
	.align 2, 0
_080359F4: .4byte 0x0835EBB4
_080359F8: .4byte 0x0835EBC4
_080359FC: .4byte 0x0000027D
_08035A00:
	cmp r0, #1
	bne _08035A0C
	movs r0, #0x4a
	bl PlaySound
	b _08035A36
_08035A0C:
	cmp r0, #0
	bne _08035A36
	ldr r1, _08035A28 @ =0x0000B313
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0x47
	bl PlaySound
	b _08035A36
	.align 2, 0
_08035A28: .4byte 0x0000B313
_08035A2C:
	cmp r1, #0
	bne _08035A36
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08035A36:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start CopyXMini_Die
CopyXMini_Die: @ 0x08035A3C
	bx lr
	.align 2, 0

	thumb_func_start nop_08035a40
nop_08035a40: @ 0x08035A40
	movs r0, #1
	bx lr

	thumb_func_start copyXMini_08035a44
copyXMini_08035a44: @ 0x08035A44
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08035A54
	cmp r5, #1
	beq _08035A78
	b _08035A96
_08035A54:
	movs r1, #0xb3
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #4
	movs r0, #0x5d
	bl LoadBlink
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08035A78:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08035A8E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035A96
_08035A8E:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08035A96:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08035a9c
FUN_08035a9c: @ 0x08035A9C
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	movs r1, #4
	ldrsh r4, [r0, r1]
	cmp r4, #1
	bne _08035AE8
	ldr r1, _08035AD0 @ =gJoypad
	ldrh r3, [r1, #4]
	movs r0, #0xc0
	lsls r0, r0, #2
	ands r0, r3
	adds r5, r1, #0
	cmp r0, #0
	beq _08035AD6
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r3
	cmp r0, #0
	beq _08035AD4
	strb r1, [r2, #0xf]
	b _08035AD6
	.align 2, 0
_08035AD0: .4byte gJoypad
_08035AD4:
	strb r4, [r2, #0xf]
_08035AD6:
	ldrh r1, [r5, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035AE8
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08035AE8:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08035af0
FUN_08035af0: @ 0x08035AF0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08035B00
	cmp r0, #1
	beq _08035B10
	b _08035B16
_08035B00:
	movs r1, #0xb3
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08035B10:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08035B16:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08035b1c
FUN_08035b1c: @ 0x08035B1C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	bls _08035B3A
	ldr r0, _08035B40 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035B3A
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08035B3A:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_08035B40: .4byte gJoypad

	thumb_func_start FUN_08035b44
FUN_08035b44: @ 0x08035B44
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	bne _08035B50
	b _08035C62
_08035B50:
	cmp r5, #1
	bgt _08035B5A
	cmp r5, #0
	beq _08035B68
	b _08035CD0
_08035B5A:
	cmp r5, #2
	bne _08035B60
	b _08035C8A
_08035B60:
	cmp r5, #3
	bne _08035B66
	b _08035CAC
_08035B66:
	b _08035CD0
_08035B68:
	ldr r1, _08035BA4 @ =0x0000B314
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x45
	bl PlaySound
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08035BE6
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08035BA8
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x5d
	bl ClearBlink
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x5e
	bl LoadBlink
	b _08035BD8
	.align 2, 0
_08035BA4: .4byte 0x0000B314
_08035BA8:
	cmp r0, #2
	bne _08035BC0
	strb r5, [r1]
	movs r0, #0x5f
	bl ClearBlink
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x5d
	bl LoadBlink
	b _08035BD8
_08035BC0:
	cmp r0, #1
	bne _08035BD8
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x5e
	bl ClearBlink
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x5f
	bl LoadBlink
_08035BD8:
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0x74
	movs r1, #2
	b _08035C44
_08035BE6:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08035C08
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x5d
	bl ClearBlink
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x5f
	bl LoadBlink
	b _08035C38
_08035C08:
	cmp r0, #2
	bne _08035C22
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x5f
	bl ClearBlink
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x5e
	bl LoadBlink
	b _08035C38
_08035C22:
	cmp r0, #1
	bne _08035C38
	strb r5, [r1]
	movs r0, #0x5e
	bl ClearBlink
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x5d
	bl LoadBlink
_08035C38:
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0x74
	movs r1, #1
_08035C44:
	strb r1, [r0]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, #0x74
	strb r1, [r0]
	adds r2, #8
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, #0x74
	strb r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08035C62:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	bl FUN_0801779c
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08035CA0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08035CA4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035CD0
	b _08035CA4
_08035C8A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	bl FUN_0801779c
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08035CD0
_08035CA0:
	movs r0, #0xa
	strb r0, [r4, #0x12]
_08035CA4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08035CD0
_08035CAC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	bl FUN_0801779c
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08035CC8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035CD0
_08035CC8:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08035CD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08035cd8
FUN_08035cd8: @ 0x08035CD8
	push {r4, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #4
	bls _08035D22
	ldr r1, _08035D08 @ =gJoypad
	ldrh r3, [r1, #4]
	movs r0, #0xc0
	lsls r0, r0, #2
	ands r0, r3
	adds r4, r1, #0
	cmp r0, #0
	beq _08035D10
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r3
	cmp r0, #0
	beq _08035D0C
	strb r1, [r2, #0xf]
	b _08035D10
	.align 2, 0
_08035D08: .4byte gJoypad
_08035D0C:
	movs r0, #1
	strb r0, [r2, #0xf]
_08035D10:
	ldrh r1, [r4, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035D22
	movs r0, #3
	strb r0, [r2, #0xd]
	movs r0, #2
	strb r0, [r2, #0xe]
_08035D22:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08035d2c
FUN_08035d2c: @ 0x08035D2C
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _08035D3A
	b _08035E3A
_08035D3A:
	lsls r0, r0, #2
	ldr r1, _08035D44 @ =_08035D48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08035D44: .4byte _08035D48
_08035D48: @ jump table
	.4byte _08035D68 @ case 0
	.4byte _08035DF8 @ case 1
	.4byte _08035D78 @ case 2
	.4byte _08035DF8 @ case 3
	.4byte _08035D88 @ case 4
	.4byte _08035DF8 @ case 5
	.4byte _08035E14 @ case 6
	.4byte _08035E22 @ case 7
_08035D68:
	ldr r1, _08035D74 @ =0x0000B301
	adds r0, r4, #0
	bl SetMotion
	b _08035DF2
	.align 2, 0
_08035D74: .4byte 0x0000B301
_08035D78:
	ldr r1, _08035D84 @ =0x0000B302
	adds r0, r4, #0
	bl SetMotion
	b _08035DF2
	.align 2, 0
_08035D84: .4byte 0x0000B302
_08035D88:
	ldr r1, _08035DA4 @ =0x0000B303
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08035DA8
	movs r0, #0x51
	bl PlaySound
	b _08035DC6
	.align 2, 0
_08035DA4: .4byte 0x0000B303
_08035DA8:
	cmp r0, #1
	bne _08035DB4
	movs r0, #0x49
	bl PlaySound
	b _08035DC6
_08035DB4:
	cmp r0, #2
	bne _08035DC0
	movs r0, #0x40
	bl PlaySound
	b _08035DC6
_08035DC0:
	movs r0, #0x51
	bl PlaySound
_08035DC6:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _08035E10 @ =0xFFFFEA00
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r1, r4, #0
	adds r1, #0x54
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r2, [r0]
	mov r0, sp
	bl FUN_080b18d4
_08035DF2:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08035DF8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08035E3A
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08035E3A
	.align 2, 0
_08035E10: .4byte 0xFFFFEA00
_08035E14:
	ldr r1, _08035E44 @ =0x0000B304
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08035E22:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08035E3A
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08035E3A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035E44: .4byte 0x0000B304
