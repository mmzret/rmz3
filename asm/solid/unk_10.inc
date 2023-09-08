	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid10_Die
Solid10_Die: @ 0x080CD918
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #1
	beq _080CD974
	cmp r0, #1
	bgt _080CD92E
	cmp r0, #0
	beq _080CD93A
	b _080CDB26
_080CD92E:
	cmp r0, #2
	beq _080CDA06
	cmp r0, #3
	bne _080CD938
	b _080CDA8C
_080CD938:
	b _080CDB26
_080CD93A:
	adds r0, r5, #0
	adds r0, #0x54
	bl FUN_0800e308
	ldrb r1, [r5, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080CD9C0 @ =0x08370168
	str r0, [r5, #0x30]
	ldr r0, _080CD9C4 @ =0x00002001
	strh r0, [r5, #0x26]
	adds r0, r5, #0
	adds r0, #0x64
	str r0, [r5, #0x40]
	ldr r4, _080CD9C8 @ =0x0000011D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _080CD96A
	adds r0, r4, #0
	bl PlaySound
_080CD96A:
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080CD974:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080CD9CC @ =0x08370170
	ldrb r2, [r5, #0x12]
	movs r1, #7
	ands r1, r2
	lsls r1, r1, #2
	adds r0, r1, r0
	ldr r0, [r0]
	lsls r0, r0, #8
	ldr r3, [r5, #0x54]
	adds r0, r3, r0
	str r0, [r5, #0x64]
	ldr r0, _080CD9D0 @ =0x08370190
	adds r1, r1, r0
	ldr r0, [r1]
	lsls r0, r0, #8
	ldr r1, [r5, #0x58]
	adds r0, r1, r0
	str r0, [r5, #0x68]
	adds r2, #1
	strb r2, [r5, #0x12]
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080CD9F0
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #8
	adds r0, r1, r0
	str r0, [sp, #4]
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	beq _080CD9D4
	movs r1, #0x88
	lsls r1, r1, #5
	b _080CD9D6
	.align 2, 0
_080CD9C0: .4byte 0x08370168
_080CD9C4: .4byte 0x00002001
_080CD9C8: .4byte 0x0000011D
_080CD9CC: .4byte 0x08370170
_080CD9D0: .4byte 0x08370190
_080CD9D4:
	ldr r1, _080CDAA8 @ =0xFFFFEF00
_080CD9D6:
	adds r0, r3, r1
	str r0, [sp]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CD9F0
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080CD9F0:
	ldrb r0, [r5, #0x12]
	cmp r0, #0x2c
	bhi _080CD9F8
	b _080CDB26
_080CD9F8:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080CDA06:
	ldr r0, [r5, #0x54]
	ldr r1, _080CDAAC @ =0xFFFFF800
	adds r4, r0, r1
	str r4, [sp]
	ldr r0, [r5, #0x58]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r3, r0, r7
	str r3, [sp, #4]
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _080CDA42
	adds r0, r4, #0
	adds r1, r3, #0
	bl PushoutToUp2
	cmp r0, #0
	bne _080CDA42
	ldr r0, [sp]
	adds r0, r0, r7
	ldr r1, [sp, #4]
	bl PushoutToUp2
	cmp r0, #0
	beq _080CDA8C
_080CDA42:
	movs r4, #0
	str r4, [r6]
	adds r0, r5, #0
	adds r0, #0x90
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
	ldr r1, _080CDAB0 @ =0x00004403
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	strb r4, [r5, #0x13]
	movs r0, #0x41
	bl isSoundPlaying
	cmp r0, #0
	bne _080CDA86
	movs r0, #0x41
	bl PlaySound
_080CDA86:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080CDA8C:
	ldrb r0, [r5, #0xd]
	cmp r0, #3
	bne _080CDABC
	ldrb r1, [r5, #0x13]
	adds r0, r1, #1
	strb r0, [r5, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDAB4
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080CDABA
	.align 2, 0
_080CDAA8: .4byte 0xFFFFEF00
_080CDAAC: .4byte 0xFFFFF800
_080CDAB0: .4byte 0x00004403
_080CDAB4:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
_080CDABA:
	strb r0, [r5, #0xa]
_080CDABC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x60]
	ldr r0, _080CDB30 @ =0x000006FF
	cmp r1, r0
	bgt _080CDAD0
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r5, #0x60]
_080CDAD0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	str r0, [r5, #0x68]
	ldr r0, _080CDB34 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080CDB26
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
	ldr r1, _080CDB38 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080CDB26:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CDB30: .4byte 0x000006FF
_080CDB34: .4byte gStageRun+232
_080CDB38: .4byte gSolidFnTable
