	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cb3b8
FUN_080cb3b8: @ 0x080CB3B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r3, #0
	ldr r0, _080CB49C @ =gSolidHeaderPtr
	ldr r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	cmp r0, #7
	ble _080CB42E
	adds r0, r1, #0
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080CB432
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080CB4A0 @ =gSolidFnTable
	movs r0, #3
	strb r0, [r3, #9]
	ldr r0, [r1, #0xc]
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
	ldr r2, _080CB4A4 @ =0xFFFFF000
	adds r0, r5, #0
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r3, #0x54]
	adds r0, r6, #0
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r3, #0x58]
	ldrb r0, [r4, #0x10]
	strb r0, [r3, #0x10]
	ldrb r0, [r4, #0x11]
	cmp r0, #0xfe
	bhi _080CB42C
	adds r0, #1
_080CB42C:
	strb r0, [r3, #0x11]
_080CB42E:
	cmp r3, #0
	bne _080CB48C
_080CB432:
	ldr r0, _080CB4A8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080CB4B8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080CB4AC @ =gVFXFnTable
	movs r0, #0x1d
	strb r0, [r3, #9]
	ldr r0, [r1, #0x74]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r2, _080CB4A4 @ =0xFFFFF000
	adds r0, r5, #0
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r3, #0x54]
	adds r0, r6, #0
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r3, #0x58]
	ldrb r0, [r4, #0x10]
	strb r0, [r3, #0x10]
	ldrb r0, [r4, #0x11]
	cmp r0, #0xfe
	bhi _080CB486
	adds r0, #1
_080CB486:
	strb r0, [r3, #0x11]
	cmp r3, #0
	beq _080CB4B8
_080CB48C:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080CB4B0
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0800e2c4
	b _080CB4B8
	.align 2, 0
_080CB49C: .4byte gSolidHeaderPtr
_080CB4A0: .4byte gSolidFnTable
_080CB4A4: .4byte 0xFFFFF000
_080CB4A8: .4byte gVFXHeaderPtr
_080CB4AC: .4byte gVFXFnTable
_080CB4B0:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08010d20
_080CB4B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cb4c0
FUN_080cb4c0: @ 0x080CB4C0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080CB4F4
	ldr r0, [r4, #0x58]
	b _080CB4FA
_080CB4F4:
	ldr r0, [r4, #0x58]
	ldr r1, _080CB524 @ =0xFFFE2000
	adds r0, r0, r1
_080CB4FA:
	asrs r1, r0, #0xc
	adds r0, r1, #0
	cmp r1, #0
	bge _080CB504
	adds r0, #0x1f
_080CB504:
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r1, r0
	movs r1, #0x1f
	subs r1, r1, r0
	adds r2, r4, #0
	adds r2, #0x25
	strb r1, [r2]
	ldrb r1, [r4, #0x11]
	movs r0, #3
	ands r0, r1
	adds r0, #5
	strb r0, [r4, #0x12]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CB524: .4byte 0xFFFE2000

	thumb_func_start FUN_080cb528
FUN_080cb528: @ 0x080CB528
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080CB546
	subs r0, #1
	strb r0, [r5, #0x12]
	b _080CB742
_080CB546:
	ldr r0, [r5, #0x54]
	mov r8, r0
	ldr r7, [r5, #0x58]
	ldr r1, _080CB5B4 @ =0xFFFFF800
	adds r1, r1, r7
	mov sb, r1
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080CB5C0
	ldr r2, _080CB5B8 @ =0xFFFFE800
	adds r1, r7, r2
	mov r0, r8
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB56C
	movs r6, #1
	movs r4, #1
_080CB56C:
	movs r0, #0x80
	lsls r0, r0, #5
	add r0, r8
	mov r1, sb
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB588
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #2
	orrs r4, r0
_080CB588:
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r7, r0
	mov r0, r8
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB5A8
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #4
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
_080CB5A8:
	ldr r0, _080CB5BC @ =0xFFFFF000
	add r0, r8
	mov r1, sb
	bl FUN_0800e284
	b _080CB61A
	.align 2, 0
_080CB5B4: .4byte 0xFFFFF800
_080CB5B8: .4byte 0xFFFFE800
_080CB5BC: .4byte 0xFFFFF000
_080CB5C0:
	ldr r2, _080CB638 @ =0xFFFFE800
	adds r1, r7, r2
	mov r0, r8
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB5D4
	movs r6, #1
	movs r4, #1
_080CB5D4:
	movs r0, #0x80
	lsls r0, r0, #5
	add r0, r8
	mov r1, sb
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB5F0
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #2
	orrs r4, r0
_080CB5F0:
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r7, r0
	mov r0, r8
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB610
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #4
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
_080CB610:
	ldr r0, _080CB63C @ =0xFFFFF000
	add r0, r8
	mov r1, sb
	bl FUN_08010cd0
_080CB61A:
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB62E
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #8
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
_080CB62E:
	cmp r6, #0
	bne _080CB640
	movs r0, #0
	b _080CB744
	.align 2, 0
_080CB638: .4byte 0xFFFFE800
_080CB63C: .4byte 0xFFFFF000
_080CB640:
	ldr r0, _080CB670 @ =gSolidHeaderPtr
	ldr r0, [r0]
	movs r2, #0xa
	ldrsh r1, [r0, r2]
	ldr r0, _080CB674 @ =gVFXHeaderPtr
	ldr r0, [r0]
	movs r2, #0xa
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	subs r0, r6, #1
	cmp r1, r0
	blt _080CB742
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080CB67C
	ldr r0, [r5, #0x58]
	ldr r1, _080CB678 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #1
	eors r4, r0
	b _080CB6C0
	.align 2, 0
_080CB670: .4byte gSolidHeaderPtr
_080CB674: .4byte gVFXHeaderPtr
_080CB678: .4byte 0xFFFFF000
_080CB67C:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080CB692
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r5, #0x54]
	movs r0, #2
	b _080CB6BA
_080CB692:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _080CB6A8
	ldr r0, [r5, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #4
	b _080CB6BA
_080CB6A8:
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq _080CB6C0
	ldr r0, [r5, #0x54]
	ldr r2, _080CB6D4 @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [r5, #0x54]
	movs r0, #8
_080CB6BA:
	eors r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
_080CB6C0:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080CB6DC
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080CB6D8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800e2c4
	b _080CB6E8
	.align 2, 0
_080CB6D4: .4byte 0xFFFFF000
_080CB6D8: .4byte 0xFFFFF800
_080CB6DC:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080CB750 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08010d20
_080CB6E8:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080CB6FC
	ldr r2, _080CB754 @ =0xFFFFF000
	add r2, sb
	adds r0, r5, #0
	mov r1, r8
	bl FUN_080cb3b8
_080CB6FC:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080CB712
	movs r1, #0x80
	lsls r1, r1, #5
	add r1, r8
	adds r0, r5, #0
	mov r2, sb
	bl FUN_080cb3b8
_080CB712:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _080CB728
	movs r2, #0x80
	lsls r2, r2, #5
	add r2, sb
	adds r0, r5, #0
	mov r1, r8
	bl FUN_080cb3b8
_080CB728:
	movs r0, #8
	ands r4, r0
	cmp r4, #0
	beq _080CB73C
	ldr r1, _080CB754 @ =0xFFFFF000
	add r1, r8
	adds r0, r5, #0
	mov r2, sb
	bl FUN_080cb3b8
_080CB73C:
	adds r0, r5, #0
	bl FUN_080cb4c0
_080CB742:
	movs r0, #1
_080CB744:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CB750: .4byte 0xFFFFF800
_080CB754: .4byte 0xFFFFF000

	thumb_func_start Solid3_Init
Solid3_Init: @ 0x080CB758
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #2
	movs r2, #0
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080CB7A0
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080CB798 @ =sCollision
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080CB79C @ =FUN_080cb980
	str r0, [r4, #0x24]
	ldrb r1, [r5, #0xb]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r5, #0x1d]
	b _080CB7A6
	.align 2, 0
_080CB798: .4byte sCollision
_080CB79C: .4byte FUN_080cb980
_080CB7A0:
	adds r0, r5, #0
	bl FUN_080cb4c0
_080CB7A6:
	ldr r1, _080CB7C4 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Solid3_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB7C4: .4byte gSolidFnTable

	thumb_func_start Solid3_Update
Solid3_Update: @ 0x080CB7C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080CB7DC
	b _080CB926
_080CB7DC:
	ldr r1, _080CB890 @ =gStageRun+232
	ldr r0, [r1, #0x38]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x3c]
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _080CB7EE
	b _080CB968
_080CB7EE:
	ldr r7, [r4, #0x64]
	ldr r5, [r4, #0x68]
	ldr r0, [r4, #0x5c]
	mov sl, r0
	ldr r0, [r4, #0x60]
	mov r8, r0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080CB894
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB818
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_080cb3b8
_080CB818:
	mov r0, sl
	adds r6, r7, r0
	adds r0, r5, #0
	add r0, r8
	mov sb, r0
	adds r0, r6, #0
	mov r1, sb
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB83A
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sb
	bl FUN_080cb3b8
_080CB83A:
	mov r0, r8
	subs r0, r5, r0
	mov r8, r0
	adds r0, r6, #0
	mov r1, r8
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB858
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, r8
	bl FUN_080cb3b8
_080CB858:
	mov r0, sl
	subs r5, r7, r0
	adds r0, r5, #0
	mov r1, sb
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB874
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	bl FUN_080cb3b8
_080CB874:
	adds r0, r5, #0
	mov r1, r8
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB920
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, r8
	bl FUN_080cb3b8
	b _080CB920
	.align 2, 0
_080CB890: .4byte gStageRun+232
_080CB894:
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB8AC
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_080cb3b8
_080CB8AC:
	mov r0, sl
	adds r6, r7, r0
	adds r0, r5, #0
	add r0, r8
	mov sb, r0
	adds r0, r6, #0
	mov r1, sb
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB8CE
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sb
	bl FUN_080cb3b8
_080CB8CE:
	mov r0, r8
	subs r0, r5, r0
	mov r8, r0
	adds r0, r6, #0
	mov r1, r8
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB8EC
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, r8
	bl FUN_080cb3b8
_080CB8EC:
	mov r0, sl
	subs r5, r7, r0
	adds r0, r5, #0
	mov r1, sb
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB908
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	bl FUN_080cb3b8
_080CB908:
	adds r0, r5, #0
	mov r1, r8
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB920
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, r8
	bl FUN_080cb3b8
_080CB920:
	movs r0, #0
	strb r0, [r4, #0xd]
	b _080CB968
_080CB926:
	adds r0, r4, #0
	bl FUN_080cb528
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	bne _080CB968
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080CB978 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080CB968:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CB978: .4byte gSolidFnTable

	thumb_func_start Solid3_Die
Solid3_Die: @ 0x080CB97C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cb980
FUN_080cb980: @ 0x080CB980
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	ldr r7, [r0, #0x2c]
	ldrb r0, [r7, #0xd]
	cmp r0, #0
	beq _080CB998
	b _080CBAB6
_080CB998:
	ldr r1, [sp]
	ldr r0, [r1, #0xc]
	ldr r2, [r0, #4]
	ldr r3, [r0, #8]
	adds r4, r2, #0
	adds r4, #0x10
	ldr r0, [r0, #0x2c]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080CB9BA
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r0, [r3]
	adds r5, r0, r1
	b _080CB9C2
_080CB9BA:
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r0, [r3]
	subs r5, r0, r1
_080CB9C2:
	movs r0, #2
	ldrsh r1, [r4, r0]
	ldr r0, [r3, #4]
	adds r6, r0, r1
	ldrh r0, [r4, #4]
	lsrs r0, r0, #1
	str r0, [sp, #4]
	ldrh r0, [r4, #6]
	lsrs r0, r0, #1
	mov sl, r0
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080CBA30
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	ldr r1, [sp, #4]
	adds r4, r5, r1
	adds r0, r6, #0
	add r0, sl
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	mov r1, sl
	subs r1, r6, r1
	mov r8, r1
	adds r0, r4, #0
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	ldr r0, [sp, #4]
	subs r4, r5, r0
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	adds r0, r4, #0
	mov r1, r8
	bl FUN_0800e284
	b _080CBA82
_080CBA30:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	ldr r1, [sp, #4]
	adds r4, r5, r1
	adds r0, r6, #0
	add r0, sl
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	mov r1, sl
	subs r1, r6, r1
	mov r8, r1
	adds r0, r4, #0
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	ldr r0, [sp, #4]
	subs r4, r5, r0
	adds r0, r4, #0
	mov r1, sb
	bl FUN_08010cd0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CBA88
	adds r0, r4, #0
	mov r1, r8
	bl FUN_08010cd0
_080CBA82:
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CBAA8
_080CBA88:
	str r5, [r7, #0x64]
	str r6, [r7, #0x68]
	ldr r1, [sp, #4]
	str r1, [r7, #0x5c]
	mov r0, sl
	str r0, [r7, #0x60]
	movs r0, #0x3d
	bl isSoundPlaying
	cmp r0, #0
	bne _080CBAA4
	movs r0, #0x3d
	bl PlaySound
_080CBAA4:
	movs r0, #1
	strb r0, [r7, #0xd]
_080CBAA8:
	ldr r1, [sp]
	ldr r0, [r1, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r1, [sp]
	str r0, [r1, #0x18]
_080CBAB6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
