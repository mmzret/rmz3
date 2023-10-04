	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e4b88
FUN_080e4b88: @ 0x080E4B88
	push {lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, [r3, #0x64]
	cmp r2, #0
	bne _080E4BAA
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080E4BEC
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080E4BBE
_080E4BAA:
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _080E4BEC
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
_080E4BBE:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080E4BF0 @ =gElfFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080E4BEC:
	pop {r0}
	bx r0
	.align 2, 0
_080E4BF0: .4byte gElfFnTable

	thumb_func_start elf_080e4bf4
elf_080e4bf4: @ 0x080E4BF4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080E4C4C @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E4C5C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E4C50 @ =gElfFnTable
	movs r0, #0xa
	strb r0, [r3, #9]
	ldr r0, [r1, #0x28]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb4
	str r4, [r0]
	strb r7, [r3, #0x10]
	strb r6, [r3, #0x11]
	str r5, [r3, #0x64]
	cmp r5, #0
	bne _080E4C54
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	b _080E4C5A
	.align 2, 0
_080E4C4C: .4byte gElfHeaderPtr
_080E4C50: .4byte gElfFnTable
_080E4C54:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0, #1]
_080E4C5A:
	strb r0, [r3, #0x13]
_080E4C5C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Elf10_Init
Elf10_Init: @ 0x080E4C64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r1, _080E4D30 @ =gZeroRanges
	ldr r2, _080E4D34 @ =0x00000147
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r0, #1
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
	str r1, [r7, #0x54]
	asrs r4, r4, #0x10
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0xb8
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r7, #0x58]
	str r0, [r1]
	adds r2, #0x78
	movs r1, #0
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xc1
	movs r0, #0x20
	strb r0, [r1]
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldr r1, _080E4D38 @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl Elf10_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E4D30: .4byte gZeroRanges
_080E4D34: .4byte 0x00000147
_080E4D38: .4byte gElfFnTable

	thumb_func_start Elf10_Update
Elf10_Update: @ 0x080E4D3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r7, [r0]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080E4D9C @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	beq _080E4D5A
	b _080E500A
_080E4D5A:
	ldr r1, _080E4DA0 @ =0x00000232
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E4DA8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080E4DA4 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080E500A
	.align 2, 0
_080E4D9C: .4byte gPause
_080E4DA0: .4byte 0x00000232
_080E4DA4: .4byte gElfFnTable
_080E4DA8:
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E4DC4
	adds r0, r7, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080E4DDC
_080E4DC4:
	ldr r1, _080E4DD8 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080E500A
	.align 2, 0
_080E4DD8: .4byte gElfFnTable
_080E4DDC:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E4E14
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _080E4E08
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r1, #0xd8
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E4E50
_080E4E08:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r2, #0xd0
	lsls r2, r2, #4
	b _080E4E40
_080E4E14:
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _080E4E38
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E4E34 @ =0xFFFFE500
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E4E50
	.align 2, 0
_080E4E34: .4byte 0xFFFFE500
_080E4E38:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E4E98 @ =0xFFFFF300
_080E4E40:
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0xa4
	lsls r1, r1, #6
_080E4E50:
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	subs r4, r1, r0
	mov r8, r3
	mov sb, r2
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcAngle
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r6, #0
	cmp r6, #0
	bge _080E4E6E
	rsbs r1, r6, #0
_080E4E6E:
	adds r0, r4, #0
	cmp r4, #0
	bge _080E4E76
	rsbs r0, r4, #0
_080E4E76:
	cmp r1, r0
	ble _080E4EA0
	adds r1, r6, #0
	cmp r1, #0
	bge _080E4E82
	rsbs r1, r1, #0
_080E4E82:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E4EC4
	ldr r1, [r5, #0x5c]
	ldr r0, _080E4E9C @ =0x000005FF
	cmp r1, r0
	bgt _080E4ED6
	adds r0, r1, #0
	adds r0, #0x10
	b _080E4ED4
	.align 2, 0
_080E4E98: .4byte 0xFFFFF300
_080E4E9C: .4byte 0x000005FF
_080E4EA0:
	adds r1, r4, #0
	cmp r1, #0
	bge _080E4EA8
	rsbs r1, r1, #0
_080E4EA8:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E4EC4
	ldr r1, [r5, #0x5c]
	ldr r0, _080E4EC0 @ =0x000005FF
	cmp r1, r0
	bgt _080E4ED6
	adds r0, r1, #0
	adds r0, #0x10
	b _080E4ED4
	.align 2, 0
_080E4EC0: .4byte 0x000005FF
_080E4EC4:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080E4ED0
	str r1, [r5, #0x5c]
_080E4ED0:
	ldr r0, [r5, #0x5c]
	subs r0, #0x20
_080E4ED4:
	str r0, [r5, #0x5c]
_080E4ED6:
	ldr r0, [r5, #0x5c]
	cmp r0, #0x9f
	bgt _080E4EE0
	movs r0, #0xa0
	str r0, [r5, #0x5c]
_080E4EE0:
	mov r6, r8
	ldr r3, _080E4F5C @ =gSineTable
	mov ip, r3
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r6]
	mov r4, sb
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0xc0
	ldrb r2, [r1]
	adds r3, r2, #1
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1]
	ldrb r3, [r1]
	lsls r2, r3, #3
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _080E4F60
	movs r0, #0x3f
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r6]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	mvns r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r4]
	subs r0, r0, r1
	b _080E4F8A
	.align 2, 0
_080E4F5C: .4byte gSineTable
_080E4F60:
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r1
_080E4F8A:
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E4F96
	subs r0, #1
	b _080E4FE8
_080E4F96:
	adds r0, r7, #0
	bl CheckPlayerStandStill
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E4FE6
	ldr r0, [r5, #0x64]
	cmp r0, #0
	bne _080E4FB0
	adds r0, r7, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	b _080E4FB6
_080E4FB0:
	adds r0, r7, #0
	adds r0, #0xb4
	ldrb r1, [r0, #1]
_080E4FB6:
	ldr r0, _080E4FD8 @ =gUnlockedElfPtr
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E4FDC
	ldrb r2, [r5, #0x10]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_080e5048
	b _080E4FE6
	.align 2, 0
_080E4FD8: .4byte gUnlockedElfPtr
_080E4FDC:
	ldrb r2, [r5, #0x10]
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_080e5048
_080E4FE6:
	movs r0, #0x3c
_080E4FE8:
	strb r0, [r5, #0x12]
	adds r4, r5, #0
	adds r4, #0xc1
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E500A
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #2
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r4]
_080E500A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Elf10_Die
Elf10_Die: @ 0x080E5018
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E5044 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E5044: .4byte gElfFnTable
