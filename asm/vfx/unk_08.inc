	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Ghost8_Init
Ghost8_Init: @ 0x080B49F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080B4A1E
	adds r0, r4, #0
	adds r0, #0x78
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r5, r0, #0
	cmp r2, r1
	bne _080B4A1E
	adds r0, r4, #0
	bl InitNonAffineMotion
	b _080B4A28
_080B4A1E:
	adds r0, r4, #0
	bl InitScalerotMotion1
	adds r5, r4, #0
	adds r5, #0x78
_080B4A28:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #0xb
	bl SetMotion
	ldrb r2, [r4, #0x11]
	cmp r2, #0
	beq _080B4A48
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080B4A4E
_080B4A48:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080B4A4E:
	strb r0, [r4, #0xa]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r1, [r0]
	subs r0, #0x50
	strb r1, [r0]
	ldrh r1, [r5]
	adds r0, #0x2c
	strh r1, [r0]
	ldrh r0, [r5]
	adds r2, r4, #0
	adds r2, #0x52
	strh r0, [r2]
	ldr r1, _080B4AA8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost8_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4AA8: .4byte gVFXFnTable

	thumb_func_start Ghost8_Update
Ghost8_Update: @ 0x080B4AAC
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B4AD0
	ldr r1, _080B4AD8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B4AD0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4AD8: .4byte gVFXFnTable

	thumb_func_start Ghost8_Die
Ghost8_Die: @ 0x080B4ADC
	ldr r2, _080B4AF0 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080B4AF0: .4byte gVFXFnTable
