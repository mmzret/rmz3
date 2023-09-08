	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080dc81c
FUN_080dc81c: @ 0x080DC81C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080DC868 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x11]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080DC870
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080DC86C @ =gSolidFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _080DC890
	.align 2, 0
_080DC868: .4byte gSystemSavedataManager
_080DC86C: .4byte gSolidFnTable
_080DC870:
	movs r0, #0
	strb r0, [r2, #0x12]
	movs r0, #0x1e
	strb r0, [r2, #0x13]
	ldr r1, _080DC894 @ =gSolidFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl Solid37_Update
_080DC890:
	pop {r0}
	bx r0
	.align 2, 0
_080DC894: .4byte gSolidFnTable

	thumb_func_start FUN_080dc898
FUN_080dc898: @ 0x080DC898
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080DC8CC
	adds r0, r4, #0
	bl CreateSolid37
	ldr r2, _080DC8DC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080DC8E0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080DC8E4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	adds r0, #8
	strb r0, [r4, #0x13]
_080DC8CC:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1e
	bls _080DC8D6
	movs r0, #0
	strb r0, [r4, #0x12]
_080DC8D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DC8DC: .4byte RNG_0202f388
_080DC8E0: .4byte 0x000343FD
_080DC8E4: .4byte 0x00269EC3

	thumb_func_start FUN_080dc8e8
FUN_080dc8e8: @ 0x080DC8E8
	ldr r2, _080DC8FC @ =gSolidFnTable
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
_080DC8FC: .4byte gSolidFnTable

	thumb_func_start FUN_080dc900
FUN_080dc900: @ 0x080DC900
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080DC978 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0x12]
	cmp r0, #0x1e
	bne _080DC990
	adds r0, r6, #0
	bl InitScalerotMotion1
	adds r0, r6, #0
	adds r0, #0x50
	movs r1, #0x80
	lsls r1, r1, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r0, [r6, #0x54]
	ldr r1, _080DC97C @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r0, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _080DC980 @ =0xFFFFFE00
	str r0, [r6, #0x5c]
	ldr r2, _080DC984 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080DC988 @ =0x000343FD
	muls r0, r1, r0
	ldr r7, _080DC98C @ =0x00269EC3
	adds r0, r0, r7
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	adds r0, #0x18
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	strb r4, [r6, #0x11]
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0x12]
	adds r0, #1
	strb r0, [r1, #0x12]
	b _080DCA0E
	.align 2, 0
_080DC978: .4byte gSolidFnTable
_080DC97C: .4byte 0xFFFFE000
_080DC980: .4byte 0xFFFFFE00
_080DC984: .4byte RNG_0202f388
_080DC988: .4byte 0x000343FD
_080DC98C: .4byte 0x00269EC3
_080DC990:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r5, _080DCA50 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r3, _080DCA54 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080DCA58 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsls r0, r0, #2
	lsrs r0, r0, #0x13
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
	str r1, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r0, [r6, #0x58]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r0, r0, r7
	str r0, [r1]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	subs r1, #0xff
	subs r1, r1, r0
	str r1, [r6, #0x5c]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	adds r0, #0x18
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DCA5C @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_080DCA0E:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xe6
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl Solid37_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCA50: .4byte RNG_0202f388
_080DCA54: .4byte 0x000343FD
_080DCA58: .4byte 0x00269EC3
_080DCA5C: .4byte sCollisions

	thumb_func_start FUN_080dca60
FUN_080dca60: @ 0x080DCA60
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r5, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _080DCA94
	ldr r1, _080DCA90 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Solid37_Die
	b _080DCB74
	.align 2, 0
_080DCA90: .4byte gSolidFnTable
_080DCA94:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r2, r0, r1
	str r2, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080DCAE0
	cmp r0, #1
	bgt _080DCABE
	cmp r0, #0
	beq _080DCAC4
	b _080DCB74
_080DCABE:
	cmp r0, #2
	beq _080DCB28
	b _080DCB74
_080DCAC4:
	movs r0, #0x40
	rsbs r0, r0, #0
	cmp r1, r0
	ble _080DCB74
	ldr r1, _080DCADC @ =0x0000E601
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080DCB1C
	.align 2, 0
_080DCADC: .4byte 0x0000E601
_080DCAE0:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080DCB74
	ldr r1, _080DCB24 @ =0x0000E602
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080DCB1C
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #4
	movs r2, #0
	bl CreateMapItem
_080DCB1C:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080DCB74
	.align 2, 0
_080DCB24: .4byte 0x0000E602
_080DCB28:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r2, r0
	ble _080DCB74
	movs r0, #0xf
	bl PlaySound
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080DCB42
	ldr r0, [r4, #0x28]
	strb r5, [r0, #0x12]
_080DCB42:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080DCB7C @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080DCB74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DCB7C: .4byte gSolidFnTable

	thumb_func_start FUN_080dcb80
FUN_080dcb80: @ 0x080DCB80
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xd]
	cmp r5, #0
	bne _080DCBC2
	movs r1, #0xe6
	lsls r1, r1, #8
	bl SetMotion
	movs r0, #0xe0
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	ldr r0, _080DCBF4 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	strb r5, [r4, #0x12]
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0x12]
	adds r0, #1
	strb r0, [r1, #0x12]
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
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080DCBC2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
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
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DCBF8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080DCBFE
	.align 2, 0
_080DCBF4: .4byte 0xFFFFFC00
_080DCBF8:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080DCBFE:
	strb r0, [r4, #0xa]
	ldr r0, _080DCC28 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080DCC2C @ =0x000087FF
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	ble _080DCC20
	ldr r1, _080DCC30 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080DCC20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DCC28: .4byte gStageRun+232
_080DCC2C: .4byte 0x000087FF
_080DCC30: .4byte gSolidFnTable
