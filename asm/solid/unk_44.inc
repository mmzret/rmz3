	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid44_Update
Solid44_Update: @ 0x080DE2CC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080DE2E8
	ldr r0, _080DE3A4 @ =pZero2
	ldr r0, [r0]
	adds r0, #0xb4
	ldrb r0, [r0, #0x10]
	cmp r0, #1
	bne _080DE312
_080DE2E8:
	ldr r0, [r5, #0x54]
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	adds r1, #1
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080DE312
	ldr r0, [r5, #0x54]
	ldr r1, _080DE3A8 @ =0xFFFFEF00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	adds r1, #1
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080DE39E
_080DE312:
	ldr r0, _080DE3AC @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080DE362
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r0, _080DE3B0 @ =gSolidFnTable
	movs r1, #0x2c
	strb r1, [r4, #9]
	adds r0, #0xb0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #1
	strb r0, [r4, #0x10]
	strb r2, [r4, #0x11]
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
_080DE362:
	ldr r0, [r5, #0x54]
	ldr r1, _080DE3B4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080DE3B0 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Solid44_Die
_080DE39E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DE3A4: .4byte pZero2
_080DE3A8: .4byte 0xFFFFEF00
_080DE3AC: .4byte gSolidHeaderPtr
_080DE3B0: .4byte gSolidFnTable
_080DE3B4: .4byte 0xFFFFF800

	thumb_func_start Solid44_Die
Solid44_Die: @ 0x080DE3B8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #1
	beq _080DE43C
	cmp r0, #1
	bgt _080DE3CE
	cmp r0, #0
	beq _080DE3D6
	b _080DE5C2
_080DE3CE:
	cmp r0, #2
	bne _080DE3D4
	b _080DE558
_080DE3D4:
	b _080DE5C2
_080DE3D6:
	str r0, [r6, #0x60]
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080DE434
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _080DE428 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080DE42C @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080DE430 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r1, #1
	movs r2, #0x9d
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r6, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r6, #0xd]
	b _080DE5C2
	.align 2, 0
_080DE428: .4byte RNG_0202f388
_080DE42C: .4byte 0x000343FD
_080DE430: .4byte 0x00269EC3
_080DE434:
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DE43C:
	ldrb r0, [r6, #0x12]
	adds r3, r0, #1
	strb r3, [r6, #0x12]
	movs r0, #7
	ands r0, r3
	cmp r0, #0
	bne _080DE526
	ldr r2, _080DE47C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080DE480 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080DE484 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #8
	ands r3, r0
	adds r7, r2, #0
	cmp r3, #0
	beq _080DE488
	ldr r0, [r6, #0x54]
	movs r2, #0x90
	lsls r2, r2, #4
	adds r0, r0, r2
	b _080DE48E
	.align 2, 0
_080DE47C: .4byte RNG_0202f388
_080DE480: .4byte 0x000343FD
_080DE484: .4byte 0x00269EC3
_080DE488:
	ldr r0, [r6, #0x54]
	ldr r1, _080DE5CC @ =0xFFFFF700
	adds r0, r0, r1
_080DE48E:
	str r0, [sp]
	ldr r1, [sp]
	ldr r2, _080DE5D0 @ =0xFFFFFC00
	adds r1, r1, r2
	ldr r0, [r7]
	ldr r3, _080DE5D4 @ =0x000343FD
	muls r0, r3, r0
	ldr r4, _080DE5D8 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsls r0, r0, #4
	lsrs r0, r0, #0x15
	adds r1, r1, r0
	str r1, [sp]
	ldr r0, _080DE5DC @ =0x00009D03
	muls r2, r3, r2
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r1, r2, #1
	lsrs r2, r2, #0x11
	movs r5, #1
	ands r2, r5
	muls r3, r1, r3
	adds r3, r3, r4
	lsls r3, r3, #1
	lsrs r1, r3, #1
	str r1, [r7]
	lsrs r3, r3, #0x11
	ands r3, r5
	mov r1, sp
	bl FUN_080b2c28
	ldr r0, _080DE5E0 @ =gSolidHeaderPtr
	ldr r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	cmp r0, #8
	ble _080DE526
	adds r0, r1, #0
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080DE526
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r0, _080DE5E4 @ =gSolidFnTable
	movs r1, #0x2c
	strb r1, [r3, #9]
	adds r0, #0xb0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [sp]
	str r0, [r3, #0x54]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	str r0, [r3, #0x58]
_080DE526:
	ldrb r0, [r6, #0x12]
	cmp r0, #0x3b
	bls _080DE5C2
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _080DE53A
	adds r0, r6, #0
	adds r0, #0x54
	bl FUN_080133e8
_080DE53A:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	movs r1, #0x9d
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DE558:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x60]
	ldr r0, _080DE5E8 @ =0x000006FF
	cmp r1, r0
	bgt _080DE56C
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r6, #0x60]
_080DE56C:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	str r0, [r6, #0x68]
	ldr r0, _080DE5EC @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xa0
	lsls r1, r1, #4
	cmp r0, r1
	bls _080DE5C2
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r1, [r6, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r6, #0xb]
	ldr r1, _080DE5E4 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
_080DE5C2:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE5CC: .4byte 0xFFFFF700
_080DE5D0: .4byte 0xFFFFFC00
_080DE5D4: .4byte 0x000343FD
_080DE5D8: .4byte 0x00269EC3
_080DE5DC: .4byte 0x00009D03
_080DE5E0: .4byte gSolidHeaderPtr
_080DE5E4: .4byte gSolidFnTable
_080DE5E8: .4byte 0x000006FF
_080DE5EC: .4byte gStageRun+232
