	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Elf0_Init
Elf0_Init: @ 0x080E1D30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0xbc
	ldr r6, [r0]
	ldr r1, _080E1DF0 @ =gZeroRanges
	ldr r2, _080E1DF4 @ =0x00000147
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	str r1, [sp]
	str r2, [sp, #4]
	ldr r0, _080E1DF8 @ =gPause
	movs r4, #1
	strb r4, [r0]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r0, [r7, #0xa]
	movs r2, #0
	mov r8, r2
	orrs r4, r0
	movs r0, #2
	orrs r4, r0
	strb r4, [r7, #0xa]
	movs r0, #0
	bl createElfAction
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
	subs r2, #1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r2, [sp]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [sp]
	asrs r5, r0, #0x10
	ldr r0, [r6, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xb4
	movs r0, #0xa0
	lsls r0, r0, #4
	str r0, [r1]
	adds r4, r7, #0
	adds r4, #0xb8
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r4]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080E1DFC
	adds r0, r6, #0
	bl getMaxHP1x
	lsls r0, r0, #0x18
	lsrs r0, r0, #0xf
	b _080E1E06
	.align 2, 0
_080E1DF0: .4byte gZeroRanges
_080E1DF4: .4byte 0x00000147
_080E1DF8: .4byte gPause
_080E1DFC:
	adds r0, r6, #0
	bl getMaxHP1x
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x10
_080E1E06:
	ldr r1, [r4]
	subs r1, r1, r0
	str r1, [r4]
	ldr r0, [r7, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r2, _080E1E58 @ =gStageRun+288
	ldr r1, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x58]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x68]
	adds r1, r7, #0
	adds r1, #0xc1
	movs r0, #0x20
	strb r0, [r1]
	ldr r1, _080E1E5C @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl Elf0_Update
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E1E58: .4byte gStageRun+288
_080E1E5C: .4byte gElfFnTable

	thumb_func_start Elf0_Update
Elf0_Update: @ 0x080E1E60
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r1, _080E1EB8 @ =gElf0Updates
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bne _080E1EB0
	ldr r0, [r4, #0x64]
	ldr r1, _080E1EBC @ =0xFFFF8800
	adds r0, r0, r1
	ldr r2, _080E1EC0 @ =gStageRun+288
	ldr r1, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x68]
	ldr r0, _080E1EC4 @ =0xFFFFB000
	adds r1, r1, r0
	ldr r0, [r2, #4]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	ldr r2, _080E1EC8 @ =gSineTable
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r1, r1, r0
	str r1, [r4, #0x58]
_080E1EB0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E1EB8: .4byte gElf0Updates
_080E1EBC: .4byte 0xFFFF8800
_080E1EC0: .4byte gStageRun+288
_080E1EC4: .4byte 0xFFFFB000
_080E1EC8: .4byte gSineTable

	thumb_func_start Elf0_Die
Elf0_Die: @ 0x080E1ECC
	ldr r2, _080E1EF0 @ =gPause
	movs r1, #0
	strb r1, [r2]
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080E1EF4 @ =gElfFnTable
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
_080E1EF0: .4byte gPause
_080E1EF4: .4byte gElfFnTable

	thumb_func_start FUN_080e1ef8
FUN_080e1ef8: @ 0x080E1EF8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0xc0
	ldrb r1, [r3]
	adds r2, r1, #1
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r3]
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r1, [r6]
	ldr r0, [r4, #0x64]
	subs r3, r1, r0
	adds r5, r4, #0
	adds r5, #0xb8
	ldr r1, [r5]
	ldr r0, [r4, #0x68]
	subs r2, r1, r0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bhi _080E1F5C
	movs r7, #0x80
	lsls r7, r7, #2
	adds r0, r2, r7
	cmp r0, r1
	bhi _080E1F5C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r2, #0
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xb
	cmp r0, r1
	bgt _080E1F5C
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	ldr r0, [r6]
	str r0, [r4, #0x64]
	ldr r0, [r5]
	str r0, [r4, #0x68]
	b _080E1FAE
_080E1F5C:
	adds r0, r3, #0
	adds r1, r2, #0
	bl CalcAngle
	ldr r3, _080E1FB4 @ =gSineTable
	adds r1, r0, #0
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r5, #0
	ldrsh r2, [r1, r5]
	lsls r2, r2, #1
	ldr r1, [r4, #0x64]
	adds r1, r1, r2
	str r1, [r4, #0x64]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r1, r1, #1
	ldr r0, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x68]
	adds r5, r4, #0
	adds r5, #0xc1
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E1FAE
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r5]
_080E1FAE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E1FB4: .4byte gSineTable

	thumb_func_start FUN_080e1fb8
FUN_080e1fb8: @ 0x080E1FB8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080E1FD4
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E1FD4:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080E1FE2
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080E1FE2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e1fe8
FUN_080e1fe8: @ 0x080E1FE8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0xbc
	ldr r5, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _080E2012
	adds r0, r5, #0
	adds r0, #0xb4
	ldrh r1, [r0, #4]
	adds r1, #3
	strh r1, [r0, #4]
	adds r0, r5, #0
	bl IsDoubleHP
	lsls r0, r0, #0x18
	movs r3, #4
	cmp r0, #0
	beq _080E2026
	movs r3, #8
	b _080E2026
_080E2012:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrh r1, [r0, #4]
	adds r1, #5
	strh r1, [r0, #4]
	adds r0, r5, #0
	bl GetMaxHP
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080E2026:
	ldr r0, _080E2094 @ =gMission
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080E2038
	adds r0, #1
	strb r0, [r1]
_080E2038:
	ldr r1, _080E2098 @ =gUnlockedElfPtr
	ldr r2, _080E209C @ =0x00000121
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0xa4
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	adds r0, r5, #0
	bl GetMaxHP
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bge _080E2074
	adds r0, r5, #0
	bl GetMaxHP
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4]
_080E2074:
	ldr r1, _080E20A0 @ =gElfFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl Elf0_Die
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E2094: .4byte gMission
_080E2098: .4byte gUnlockedElfPtr
_080E209C: .4byte 0x00000121
_080E20A0: .4byte gElfFnTable


