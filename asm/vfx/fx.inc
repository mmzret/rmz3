	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initWallDust
initWallDust: @ 0x080B3D34
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _080B3DF8 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r6, _080B3DFC @ =0x000343FD
	muls r0, r6, r0
	ldr r5, _080B3E00 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r0, r0, #1
	mov r1, r8
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #0x1b
	bl SetMotion
	mov r2, r8
	ldr r0, [r2]
	adds r1, r0, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r1, r1, #1
	movs r3, #0
	ldrb r2, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r2
	strb r0, [r4, #0xa]
	movs r0, #1
	mov sb, r0
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r3]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r2, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	subs r0, #4
	lsls r0, r0, #8
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r1, _080B3E04 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, sb
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost5_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3DF8: .4byte RNG_0202f388
_080B3DFC: .4byte 0x000343FD
_080B3E00: .4byte 0x00269EC3
_080B3E04: .4byte gVFXFnTable

	thumb_func_start FUN_080b3e08
FUN_080b3e08: @ 0x080B3E08
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #5
	bl SetMotion
	movs r0, #4
	strb r0, [r4, #0x12]
	ldr r1, _080B3E48 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost5_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B3E48: .4byte gVFXFnTable

	thumb_func_start FUN_080b3e4c
FUN_080b3e4c: @ 0x080B3E4C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #0xd
	bl SetMotion
	ldr r6, _080B3ED0 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r3, _080B3ED4 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080B3ED8 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r5, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x3c
	strb r0, [r4, #0x12]
	adds r0, r5, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r5, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r5, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0xc0
	str r0, [r4, #0x60]
	ldr r1, _080B3EDC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost5_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3ED0: .4byte RNG_0202f388
_080B3ED4: .4byte 0x000343FD
_080B3ED8: .4byte 0x00269EC3
_080B3EDC: .4byte gVFXFnTable

	thumb_func_start FUN_080b3ee0
FUN_080b3ee0: @ 0x080B3EE0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080B3EF6
	ldr r0, [r6, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #4
	b _080B3EFA
_080B3EF6:
	ldr r0, [r6, #0x54]
	ldr r1, _080B3F48 @ =0xFFFFF100
_080B3EFA:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	bne _080B3F54
	ldr r1, [r6, #0x58]
	ldr r0, _080B3F4C @ =0xFFFFEE00
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl FUN_080098a4
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	bne _080B3F54
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080B3F50 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080B3FD0
	.align 2, 0
_080B3F48: .4byte 0xFFFFF100
_080B3F4C: .4byte 0xFFFFEE00
_080B3F50: .4byte gVFXFnTable
_080B3F54:
	ldr r5, _080B3FD8 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r3, _080B3FDC @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080B3FE0 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x3c
	strb r0, [r6, #0x12]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
	str r1, [r6, #0x54]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0xc0
	str r0, [r6, #0x60]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	movs r1, #0xd
	bl SetMotion
	ldr r1, _080B3FE4 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl Ghost5_Update
_080B3FD0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3FD8: .4byte RNG_0202f388
_080B3FDC: .4byte 0x000343FD
_080B3FE0: .4byte 0x00269EC3
_080B3FE4: .4byte gVFXFnTable

	thumb_func_start FUN_080b3fe8
FUN_080b3fe8: @ 0x080B3FE8
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B4006
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080B400C
_080B4006:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080B400C:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	subs r0, #0xc0
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B4030
	ldr r1, _080B4038 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B4030:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4038: .4byte gVFXFnTable

	thumb_func_start FUN_080b403c
FUN_080b403c: @ 0x080B403C
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B405A
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080B4060
_080B405A:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080B4060:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	subs r0, #0xc0
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B4084
	ldr r1, _080B408C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B4084:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B408C: .4byte gVFXFnTable

	thumb_func_start FUN_080b4090
FUN_080b4090: @ 0x080B4090
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	adds r2, #0x40
	str r2, [r4, #0x60]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080B40C8
	ldr r1, _080B40D0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B40C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B40D0: .4byte gVFXFnTable

	thumb_func_start updateDashDust
updateDashDust: @ 0x080B40D4
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B40F8
	ldr r1, _080B4100 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B40F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4100: .4byte gVFXFnTable

	thumb_func_start FUN_080b4104
FUN_080b4104: @ 0x080B4104
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	cmp r1, #0x1d
	bhi _080B412A
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B4122
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080B4128
_080B4122:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080B4128:
	strb r0, [r4, #0xa]
_080B412A:
	ldr r1, _080B4184 @ =gSineTable
	ldrb r2, [r4, #0x12]
	lsls r0, r2, #0x1c
	movs r3, #0x80
	lsls r3, r3, #0x17
	adds r0, r0, r3
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	ldr r3, _080B4188 @ =0xFFFFF800
	adds r1, r0, r3
	subs r2, #1
	strb r2, [r4, #0x12]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #0xff
	beq _080B416A
	ldr r0, _080B418C @ =gOverworld
	ldr r2, _080B4190 @ =0x0002C00C
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	ble _080B417C
_080B416A:
	ldr r1, _080B4194 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B417C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4184: .4byte gSineTable
_080B4188: .4byte 0xFFFFF800
_080B418C: .4byte gOverworld
_080B4190: .4byte 0x0002C00C
_080B4194: .4byte gVFXFnTable

	thumb_func_start FUN_080b4198
FUN_080b4198: @ 0x080B4198
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080B41C0
	ldr r1, _080B41C8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B41C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B41C8: .4byte gVFXFnTable
