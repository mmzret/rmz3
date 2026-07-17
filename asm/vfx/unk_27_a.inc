	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

