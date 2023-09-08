	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b9b9c
FUN_080b9b9c: @ 0x080B9B9C
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B9BCC @ =0x00001701
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080B9BD0
	movs r0, #0x40
	str r0, [r4, #0x5c]
	subs r0, #0x42
	b _080B9BD8
	.align 2, 0
_080B9BCC: .4byte 0x00001701
_080B9BD0:
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #2
_080B9BD8:
	str r0, [r4, #0x64]
	movs r0, #0x40
	str r0, [r4, #0x60]
	subs r0, #0x42
	str r0, [r4, #0x68]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldr r1, _080B9C04 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost27_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9C04: .4byte gVFXFnTable

	thumb_func_start FUN_080b9c08
FUN_080b9c08: @ 0x080B9C08
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B9C48 @ =0x00001708
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x60]
	ldr r1, _080B9C4C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost27_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9C48: .4byte 0x00001708
_080B9C4C: .4byte gVFXFnTable

	thumb_func_start FUN_080b9c50
FUN_080b9c50: @ 0x080B9C50
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r2, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x68]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080B9C9A
	ldr r1, _080B9CA0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost27_Die
_080B9C9A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9CA0: .4byte gVFXFnTable

	thumb_func_start FUN_080b9ca4
FUN_080b9ca4: @ 0x080B9CA4
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B9CBC
	str r1, [r4, #0x60]
_080B9CBC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080B9CEE
	ldr r1, _080B9CF4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost27_Die
_080B9CEE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9CF4: .4byte gVFXFnTable

	thumb_func_start FUN_080b9cf8
FUN_080b9cf8: @ 0x080B9CF8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x54
	ldr r6, _080B9D20 @ =0x08366758
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	asrs r1, r1, #0x1f
	ands r1, r2
	cmp r0, #0
	beq _080B9D24
	movs r3, #1
	orrs r3, r1
	b _080B9D28
	.align 2, 0
_080B9D20: .4byte 0x08366758
_080B9D24:
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
_080B9D28:
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	adds r6, r4, #0
	adds r6, #0x54
	ldr r7, _080B9D58 @ =0x08366774
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	asrs r1, r1, #0x1f
	ands r1, r2
	adds r5, r6, #0
	cmp r0, #0
	beq _080B9D5C
	movs r3, #1
	orrs r3, r1
	b _080B9D60
	.align 2, 0
_080B9D58: .4byte 0x08366774
_080B9D5C:
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
_080B9D60:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	movs r0, #1
	adds r1, r5, #0
	bl CreateSmoke
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080B9D86
	movs r0, #2
	adds r1, r5, #0
	bl CreateSmoke
	b _080B9D8E
_080B9D86:
	movs r0, #2
	adds r1, r5, #0
	bl CreateSmoke
_080B9D8E:
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080B9DAC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9DAC: .4byte gVFXFnTable

	thumb_func_start FUN_080b9db0
FUN_080b9db0: @ 0x080B9DB0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x54
	ldr r6, _080B9DD8 @ =0x08366758
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	asrs r1, r1, #0x1f
	ands r1, r2
	cmp r0, #0
	beq _080B9DDC
	movs r3, #1
	orrs r3, r1
	b _080B9DE0
	.align 2, 0
_080B9DD8: .4byte 0x08366758
_080B9DDC:
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
_080B9DE0:
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	adds r6, r4, #0
	adds r6, #0x54
	ldr r7, _080B9E10 @ =0x08366774
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	asrs r1, r1, #0x1f
	ands r1, r2
	adds r5, r6, #0
	cmp r0, #0
	beq _080B9E14
	movs r3, #1
	orrs r3, r1
	b _080B9E18
	.align 2, 0
_080B9E10: .4byte 0x08366774
_080B9E14:
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
_080B9E18:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	movs r0, #1
	adds r1, r5, #0
	bl CreateSmoke
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080B9E3E
	movs r0, #2
	adds r1, r5, #0
	bl CreateSmoke
	b _080B9E46
_080B9E3E:
	movs r0, #2
	adds r1, r5, #0
	bl CreateSmoke
_080B9E46:
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080B9E64 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9E64: .4byte gVFXFnTable
