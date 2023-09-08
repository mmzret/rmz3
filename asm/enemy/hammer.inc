	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807562c
FUN_0807562c: @ 0x0807562C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807563C
	cmp r0, #1
	beq _08075656
	b _080756DA
_0807563C:
	movs r1, #0xa4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080756E0 @ =0x0836705C
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08075656:
	ldr r1, [r4, #0x5c]
	movs r0, #0xd0
	lsls r0, r0, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xc0
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _080756E4 @ =gSineTable
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r1, [r0]
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #8
	adds r2, r0, #0
	muls r2, r1, r2
	asrs r2, r2, #8
	str r2, [r4, #0x60]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r3]
	muls r0, r6, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080756DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080756E0: .4byte 0x0836705C
_080756E4: .4byte gSineTable

	thumb_func_start FUN_080756e8
FUN_080756e8:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_080756ec
FUN_080756ec: @ 0x080756EC
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _080756FA
	b _08075A22
_080756FA:
	lsls r0, r0, #2
	ldr r1, _08075704 @ =_08075708
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08075704: .4byte _08075708
_08075708: @ jump table
	.4byte _08075724 @ case 0
	.4byte _080757C8 @ case 1
	.4byte _08075868 @ case 2
	.4byte _08075A22 @ case 3
	.4byte _08075A22 @ case 4
	.4byte _080758DC @ case 5
	.4byte _08075984 @ case 6
_08075724:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08075778 @ =0x0836708C
	bl SetDDP
	ldr r0, _0807577C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08075784
	ldr r0, _08075780 @ =gSineTable
	adds r3, r4, #0
	adds r3, #0xc0
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2]
	ldrb r5, [r3]
	adds r1, r1, r5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	movs r0, #0
	ldrsh r1, [r1, r0]
	adds r0, r4, #0
	adds r0, #0xc2
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, r1
	ble _08075768
	movs r0, #0
	ldrsb r0, [r2, r0]
	rsbs r0, r0, #0
	strb r0, [r2]
_08075768:
	movs r0, #0x40
	str r0, [r4, #0x5c]
	strh r0, [r3]
	movs r0, #2
	strb r0, [r2]
	movs r0, #1
	b _080757C2
	.align 2, 0
_08075778: .4byte 0x0836708C
_0807577C: .4byte pZero2
_08075780: .4byte gSineTable
_08075784:
	ldr r0, _080757E4 @ =gSineTable
	adds r3, r4, #0
	adds r3, #0xc0
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2]
	ldrb r5, [r3]
	adds r1, r1, r5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	movs r0, #0
	ldrsh r1, [r1, r0]
	adds r0, r4, #0
	adds r0, #0xc2
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, r1
	ble _080757B2
	movs r0, #0
	ldrsb r0, [r2, r0]
	rsbs r0, r0, #0
	strb r0, [r2]
_080757B2:
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #0xc0
	strh r0, [r3]
	movs r0, #2
	strb r0, [r2]
	movs r0, #5
_080757C2:
	strb r0, [r4, #0xe]
	movs r0, #0xf0
	strb r0, [r4, #0x12]
_080757C8:
	ldr r0, [r4, #0x60]
	ldr r1, [r4, #0x5c]
	cmp r0, r1
	bge _080757EC
	adds r0, #3
	str r0, [r4, #0x60]
	cmp r0, r1
	blt _08075826
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r1, [r4, #0x58]
	ldr r2, _080757E8 @ =0xFFFFF800
	adds r1, r1, r2
	b _080757FE
	.align 2, 0
_080757E4: .4byte gSineTable
_080757E8: .4byte 0xFFFFF800
_080757EC:
	subs r0, #3
	str r0, [r4, #0x60]
	cmp r0, r1
	bgt _08075826
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r1, [r4, #0x58]
	ldr r3, _08075860 @ =0xFFFFF800
	adds r1, r1, r3
_080757FE:
	str r1, [sp, #4]
	bl FUN_0800daec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _0807581A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08075a84
	movs r0, #0x2d
	bl PlaySound
_0807581A:
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08075826:
	ldr r1, _08075864 @ =gSineTable
	ldr r2, [r4, #0x60]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r5, [r0, r3]
	str r5, [sp]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	str r5, [sp, #4]
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	ldr r5, [sp]
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r3]
	ldr r1, [sp, #4]
	muls r0, r1, r0
	b _08075962
	.align 2, 0
_08075860: .4byte 0xFFFFF800
_08075864: .4byte gSineTable
_08075868:
	ldr r3, _080758D8 @ =gSineTable
	adds r1, r4, #0
	adds r1, #0xc0
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r2, [r0]
	ldr r1, [r4, #0x5c]
	movs r0, #0xe0
	lsls r0, r0, #6
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	muls r2, r1, r2
	asrs r2, r2, #0x10
	str r2, [r4, #0x60]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r1, [r0, r5]
	str r1, [sp, #8]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	str r1, [sp, #0xc]
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	ldr r5, [sp, #8]
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r3]
	ldr r1, [sp, #0xc]
	b _080759F2
	.align 2, 0
_080758D8: .4byte gSineTable
_080758DC:
	ldr r0, [r4, #0x60]
	ldr r1, [r4, #0x5c]
	cmp r0, r1
	bge _080758FC
	adds r0, #3
	str r0, [r4, #0x60]
	cmp r0, r1
	blt _08075932
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _080758F8 @ =0xFFFFF800
	adds r1, r1, r2
	b _0807590C
	.align 2, 0
_080758F8: .4byte 0xFFFFF800
_080758FC:
	subs r0, #3
	str r0, [r4, #0x60]
	cmp r0, r1
	bgt _08075932
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r3, _0807597C @ =0xFFFFF800
	adds r1, r1, r3
_0807590C:
	bl FUN_0800daec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08075926
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08075a84
	movs r0, #0x2d
	bl PlaySound
_08075926:
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08075932:
	ldr r1, _08075980 @ =gSineTable
	ldr r2, [r4, #0x60]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r5, [r0, r3]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r3]
	muls r0, r6, r0
_08075962:
	asrs r0, r0, #8
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08075A22
	.align 2, 0
_0807597C: .4byte 0xFFFFF800
_08075980: .4byte gSineTable
_08075984:
	ldr r3, _08075A2C @ =gSineTable
	adds r1, r4, #0
	adds r1, #0xc0
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r2, [r0]
	ldr r1, [r4, #0x5c]
	movs r0, #0xe0
	lsls r0, r0, #6
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	muls r2, r1, r2
	asrs r2, r2, #0x10
	str r2, [r4, #0x60]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r1, [r0, r5]
	str r1, [sp, #0x10]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	str r1, [sp, #0x14]
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	ldr r5, [sp, #0x10]
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r3]
	ldr r1, [sp, #0x14]
_080759F2:
	muls r0, r1, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08075A1A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08075A22
_08075A1A:
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08075A22:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08075A2C: .4byte gSineTable

	thumb_func_start FUN_08075a30
FUN_08075a30: @ 0x08075A30
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08075A56
	adds r3, r2, #0
	adds r3, #0xb5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #1
	bne _08075A56
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
	strb r1, [r3]
_08075A56:
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08075a5c
FUN_08075a5c: @ 0x08075A5C
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r0, [r0, #4]
	ldrb r2, [r0, #2]
	cmp r2, #1
	bne _08075A7C
	ldr r0, [r0, #4]
	ldr r1, _08075A80 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08075A7C
	ldr r0, [r3, #0x2c]
	adds r0, #0xb5
	strb r2, [r0]
_08075A7C:
	pop {r0}
	bx r0
	.align 2, 0
_08075A80: .4byte 0x000200FF

	thumb_func_start FUN_08075a84
FUN_08075a84: @ 0x08075A84
	push {lr}
	sub sp, #8
	ldr r1, [r0, #0x54]
	str r1, [sp]
	ldr r0, [r0, #0x58]
	ldr r1, _08075AA4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #0
	bl FUN_080b9228
	movs r0, #1
	add sp, #8
	pop {r1}
	bx r1
	.align 2, 0
_08075AA4: .4byte 0xFFFFF000
