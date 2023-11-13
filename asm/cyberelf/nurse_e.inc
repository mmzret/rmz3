	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateNurseEElf
CreateNurseEElf: @ 0x080E2BE4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080E2C3C @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E2C4C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E2C40 @ =gElfFnTable
	movs r0, #4
	strb r0, [r3, #9]
	ldr r0, [r1, #0x10]
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
	strb r5, [r3, #0x12]
	cmp r5, #0
	bne _080E2C44
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	b _080E2C4A
	.align 2, 0
_080E2C3C: .4byte gElfHeaderPtr
_080E2C40: .4byte gElfFnTable
_080E2C44:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0, #1]
_080E2C4A:
	strb r0, [r3, #0x13]
_080E2C4C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start NurseE_Init
NurseE_Init: @ 0x080E2C54
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _080E2D28 @ =gZeroRanges
	movs r0, #0xb4
	add r0, r8
	mov sb, r0
	ldr r0, _080E2D2C @ =0x00000147
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r5, [r0, #4]
	ldr r1, _080E2D30 @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r0, #0
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
	strb r6, [r0]
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
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	mov r2, r8
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	asrs r4, r4, #0x10
	ldr r0, [r2, #0x58]
	adds r0, r0, r4
	str r0, [r7, #0x58]
	str r6, [r7, #0x64]
	str r6, [r7, #0x68]
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r2]
	str r1, [r2, #4]
	str r6, [r7, #0x5c]
	adds r0, r7, #0
	adds r0, #0xb9
	strb r6, [r0]
	movs r0, #0x20
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080E2D34
	mov r0, sb
	ldrb r1, [r0]
	b _080E2D38
	.align 2, 0
_080E2D28: .4byte gZeroRanges
_080E2D2C: .4byte 0x00000147
_080E2D30: .4byte gElfFnTable
_080E2D34:
	mov r2, sb
	ldrb r1, [r2, #1]
_080E2D38:
	ldr r0, _080E2D54 @ =gUnlockedElfPtr
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E2D58
	adds r1, r7, #0
	adds r1, #0xba
	movs r0, #0x96
	lsls r0, r0, #2
	b _080E2D60
	.align 2, 0
_080E2D54: .4byte gUnlockedElfPtr
_080E2D58:
	adds r1, r7, #0
	adds r1, #0xba
	movs r0, #0xe1
	lsls r0, r0, #2
_080E2D60:
	strh r0, [r1]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080E2D74
	mov r1, r8
	ldrb r0, [r1, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	eors r0, r1
	b _080E2D7C
_080E2D74:
	mov r2, r8
	ldrb r0, [r2, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
_080E2D7C:
	ands r0, r1
	strb r0, [r7, #0xd]
	adds r0, r7, #0
	bl NurseE_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NurseE_Update
NurseE_Update: @ 0x080E2D94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _080E2E0C @ =gZeroRanges
	ldr r0, _080E2E10 @ =0x00000147
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	str r1, [sp, #0x24]
	str r2, [sp, #0x28]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080E2E14 @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	beq _080E2DCA
	b _080E3348
_080E2DCA:
	ldr r0, _080E2E18 @ =0x00000232
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E2E20
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
	ldr r1, _080E2E1C @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080E3348
	.align 2, 0
_080E2E0C: .4byte gZeroRanges
_080E2E10: .4byte 0x00000147
_080E2E14: .4byte gPause
_080E2E18: .4byte 0x00000232
_080E2E1C: .4byte gElfFnTable
_080E2E20:
	mov r0, r8
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E2E3C
	mov r0, r8
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080E2E54
_080E2E3C:
	ldr r1, _080E2E50 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080E3348
	.align 2, 0
_080E2E50: .4byte gElfFnTable
_080E2E54:
	ldr r0, _080E2EA8 @ =gStageRun+288
	ldr r4, [r0]
	ldr r3, _080E2EAC @ =0xFFFF8800
	adds r2, r4, r3
	mov r6, r8
	ldr r3, [r6, #0x54]
	movs r6, #0x8c
	lsls r6, r6, #9
	adds r1, r3, r6
	adds r6, r0, #0
	cmp r2, r1
	ble _080E2E6E
	b _080E3348
_080E2E6E:
	ldr r2, _080E2EB0 @ =0x00000216
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r2
	cmp r0, #0
	bne _080E2E86
	b _080E2F9A
_080E2E86:
	mov r0, r8
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E2EC4
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E2EBC
	ldr r1, _080E2EB4 @ =0xFFFFE500
	adds r0, r3, r1
	str r0, [sp, #0x1c]
	mov r2, r8
	ldr r0, [r2, #0x58]
	ldr r3, _080E2EB8 @ =0xFFFFED00
	adds r0, r0, r3
	b _080E2EF0
	.align 2, 0
_080E2EA8: .4byte gStageRun+288
_080E2EAC: .4byte 0xFFFF8800
_080E2EB0: .4byte 0x00000216
_080E2EB4: .4byte 0xFFFFE500
_080E2EB8: .4byte 0xFFFFED00
_080E2EBC:
	ldr r6, _080E2EC0 @ =0xFFFFF300
	b _080E2EE4
	.align 2, 0
_080E2EC0: .4byte 0xFFFFF300
_080E2EC4:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E2EE0
	movs r6, #0xd8
	lsls r6, r6, #5
	adds r0, r3, r6
	str r0, [sp, #0x1c]
	mov r1, r8
	ldr r0, [r1, #0x58]
	ldr r2, _080E2EDC @ =0xFFFFED00
	b _080E2EEE
	.align 2, 0
_080E2EDC: .4byte 0xFFFFED00
_080E2EE0:
	movs r6, #0xd0
	lsls r6, r6, #4
_080E2EE4:
	adds r0, r3, r6
	str r0, [sp, #0x1c]
	mov r1, r8
	ldr r0, [r1, #0x58]
	ldr r2, _080E2F04 @ =0xFFFFD700
_080E2EEE:
	adds r0, r0, r2
_080E2EF0:
	str r0, [sp, #0x20]
	ldr r0, [r5, #0x54]
	ldr r1, [sp, #0x1c]
	subs r2, r0, r1
	cmp r2, #0
	blt _080E2F0C
	ldr r0, _080E2F08 @ =0x000001FF
	cmp r2, r0
	ble _080E2F14
	b _080E2F38
	.align 2, 0
_080E2F04: .4byte 0xFFFFD700
_080E2F08: .4byte 0x000001FF
_080E2F0C:
	subs r1, r1, r0
	ldr r0, _080E2F28 @ =0x000001FF
	cmp r1, r0
	bgt _080E2F38
_080E2F14:
	ldr r0, [r5, #0x58]
	ldr r1, [sp, #0x20]
	subs r2, r0, r1
	cmp r2, #0
	blt _080E2F2C
	ldr r0, _080E2F28 @ =0x000001FF
	cmp r2, r0
	ble _080E2F34
	b _080E2F38
	.align 2, 0
_080E2F28: .4byte 0x000001FF
_080E2F2C:
	subs r1, r1, r0
	ldr r0, _080E2F68 @ =0x000001FF
	cmp r1, r0
	bgt _080E2F38
_080E2F34:
	movs r0, #1
	strb r0, [r5, #0xe]
_080E2F38:
	ldrb r0, [r5, #0xe]
	adds r7, r5, #0
	adds r7, #0xbc
	cmp r0, #0
	beq _080E2F44
	b _080E3126
_080E2F44:
	mov r3, sb
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080E2F6C
	adds r2, r5, #0
	adds r2, #0x5c
	adds r3, r5, #0
	adds r3, #0xb8
	movs r1, #0x80
	lsls r1, r1, #3
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0xa0
	lsls r0, r0, #3
	b _080E2F80
	.align 2, 0
_080E2F68: .4byte 0x000001FF
_080E2F6C:
	adds r2, r5, #0
	adds r2, #0x5c
	adds r3, r5, #0
	adds r3, #0xb8
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0xc0
	lsls r0, r0, #2
_080E2F80:
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0x70
	str r0, [sp, #0x10]
	movs r0, #0xe0
	str r0, [sp, #0x14]
	movs r0, #4
	str r0, [sp, #0x18]
	adds r0, r7, #0
	add r1, sp, #0x1c
	bl FUN_080e3388
	b _080E3088
_080E2F9A:
	strb r0, [r5, #0xe]
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	subs r0, r0, r4
	adds r2, r0, r1
	cmp r2, #0
	bge _080E2FAE
	rsbs r2, r2, #0
_080E2FAE:
	movs r0, #0xf0
	lsls r0, r0, #9
	cmp r2, r0
	bgt _080E2FD6
	ldr r0, [r5, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r0, r0, r2
	ldr r1, [r6, #4]
	subs r0, r0, r1
	adds r1, r0, r2
	cmp r1, #0
	bge _080E2FCA
	rsbs r1, r1, #0
_080E2FCA:
	movs r0, #0xa0
	lsls r0, r0, #9
	adds r7, r5, #0
	adds r7, #0xbc
	cmp r1, r0
	ble _080E2FFC
_080E2FD6:
	ldr r0, [sp, #0x24]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	mov r2, r8
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r3, [sp, #0x24]
	asrs r1, r3, #0x10
	ldr r0, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r2]
	str r1, [r2, #4]
	adds r7, r2, #0
_080E2FFC:
	ldr r3, [r6]
	ldr r2, _080E302C @ =0xFFFF8800
	adds r0, r3, r2
	str r0, [sp, #0x1c]
	ldr r0, [r6, #4]
	ldr r1, _080E3030 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r6]
	adds r0, r0, r2
	str r0, [r5, #0x64]
	ldr r0, [r6, #4]
	adds r0, r0, r1
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xd]
	cmp r0, #0
	beq _080E303C
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E3034
	movs r6, #0xa0
	lsls r6, r6, #7
	b _080E304E
	.align 2, 0
_080E302C: .4byte 0xFFFF8800
_080E3030: .4byte 0xFFFFB000
_080E3034:
	movs r1, #0xc0
	lsls r1, r1, #7
	adds r0, r3, r1
	b _080E3050
_080E303C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E304C
	ldr r2, _080E3048 @ =0xFFFFB000
	adds r0, r3, r2
	b _080E3050
	.align 2, 0
_080E3048: .4byte 0xFFFFB000
_080E304C:
	ldr r6, _080E3118 @ =0xFFFFA000
_080E304E:
	adds r0, r3, r6
_080E3050:
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp, #0x20]
	adds r2, r5, #0
	adds r2, #0x5c
	adds r3, r5, #0
	adds r3, #0xb8
	movs r1, #0x80
	lsls r1, r1, #3
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0x70
	str r0, [sp, #0x10]
	movs r0, #0xe0
	str r0, [sp, #0x14]
	movs r0, #4
	str r0, [sp, #0x18]
	adds r0, r7, #0
	add r1, sp, #0x1c
	bl FUN_080e3388
_080E3088:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _080E3126
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	mov r2, sb
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _080E30AA
	b _080E32C0
_080E30AA:
	adds r4, r5, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	adds r2, r0, #1
	adds r0, r2, #0
	movs r1, #0x18
	bl __umodsi3
	adds r2, r0, #0
	strb r2, [r4]
	lsls r0, r2, #8
	movs r1, #0x18
	bl __udivsi3
	adds r2, r0, #0
	ldr r1, _080E311C @ =gSineTable
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r5, #0x58]
	subs r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [sp, #0x1c]
	ldr r0, [r7]
	subs r1, r1, r0
	asrs r1, r1, #8
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ldr r2, [r7, #4]
	subs r0, r0, r2
	asrs r0, r0, #8
	str r0, [sp, #0x20]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #8
	ble _080E310E
	b _080E32C0
_080E310E:
	ldrb r0, [r5, #0xd]
	cmp r0, #0
	beq _080E3120
	strb r6, [r5, #0xd]
	b _080E32C0
	.align 2, 0
_080E3118: .4byte 0xFFFFA000
_080E311C: .4byte gSineTable
_080E3120:
	movs r0, #1
	strb r0, [r5, #0xd]
	b _080E32C0
_080E3126:
	mov r6, r8
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E315A
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E3152
	ldr r0, [r7]
	movs r1, #0xd8
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r6, #0x54]
	subs r6, r1, r0
	ldr r0, [r7, #4]
	movs r2, #0x98
	lsls r2, r2, #5
	adds r0, r0, r2
	mov r3, r8
	ldr r1, [r3, #0x58]
	b _080E318E
_080E3152:
	ldr r0, [r7]
	movs r6, #0xd0
	lsls r6, r6, #4
	b _080E317C
_080E315A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E3178
	ldr r0, [r7]
	ldr r6, _080E3174 @ =0xFFFFE500
	adds r0, r0, r6
	mov r2, r8
	ldr r1, [r2, #0x54]
	subs r6, r1, r0
	ldr r0, [r7, #4]
	movs r3, #0x98
	lsls r3, r3, #5
	b _080E318A
	.align 2, 0
_080E3174: .4byte 0xFFFFE500
_080E3178:
	ldr r0, [r7]
	ldr r6, _080E31D0 @ =0xFFFFF300
_080E317C:
	adds r0, r0, r6
	mov r2, r8
	ldr r1, [r2, #0x54]
	subs r6, r1, r0
	ldr r0, [r7, #4]
	movs r3, #0xa4
	lsls r3, r3, #6
_080E318A:
	adds r0, r0, r3
	ldr r1, [r2, #0x58]
_080E318E:
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcAngle
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r6, #0
	cmp r6, #0
	bge _080E31A4
	rsbs r1, r6, #0
_080E31A4:
	adds r0, r4, #0
	cmp r4, #0
	bge _080E31AC
	rsbs r0, r4, #0
_080E31AC:
	cmp r1, r0
	ble _080E31D8
	adds r1, r6, #0
	cmp r1, #0
	bge _080E31B8
	rsbs r1, r1, #0
_080E31B8:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E31FC
	ldr r1, [r5, #0x5c]
	ldr r0, _080E31D4 @ =0x000005FF
	cmp r1, r0
	bgt _080E320E
	adds r0, r1, #0
	adds r0, #0x10
	b _080E320C
	.align 2, 0
_080E31D0: .4byte 0xFFFFF300
_080E31D4: .4byte 0x000005FF
_080E31D8:
	adds r1, r4, #0
	cmp r1, #0
	bge _080E31E0
	rsbs r1, r1, #0
_080E31E0:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E31FC
	ldr r1, [r5, #0x5c]
	ldr r0, _080E31F8 @ =0x000005FF
	cmp r1, r0
	bgt _080E320E
	adds r0, r1, #0
	adds r0, #0x10
	b _080E320C
	.align 2, 0
_080E31F8: .4byte 0x000005FF
_080E31FC:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080E3208
	str r1, [r5, #0x5c]
_080E3208:
	ldr r0, [r5, #0x5c]
	subs r0, #0x20
_080E320C:
	str r0, [r5, #0x5c]
_080E320E:
	ldr r0, [r5, #0x5c]
	cmp r0, #0x7f
	bgt _080E3218
	movs r0, #0x80
	str r0, [r5, #0x5c]
_080E3218:
	adds r4, r7, #0
	ldr r6, _080E3294 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	lsls r0, r2, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r4, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0xb9
	ldrb r2, [r1]
	adds r3, r2, #1
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1]
	ldrb r3, [r1]
	lsls r2, r3, #3
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E3298
	movs r0, #0x3f
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r4]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #0xff
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r1, r1, #2
	ldr r0, [r4, #4]
	subs r0, r0, r1
	b _080E32BE
	.align 2, 0
_080E3294: .4byte gSineTable
_080E3298:
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r7]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r7, #4]
	adds r0, r0, r1
_080E32BE:
	str r0, [r5, #0x58]
_080E32C0:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _080E32EE
	mov r0, r8
	bl CheckPlayerStandStill
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E332E
	mov r6, sb
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080E332E
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _080E332E
_080E32EE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080E32FC
	mov r0, r8
	adds r0, #0xb4
	ldrb r2, [r0]
	b _080E3302
_080E32FC:
	mov r0, r8
	adds r0, #0xb4
	ldrb r2, [r0, #1]
_080E3302:
	ldr r0, _080E3318 @ =gUnlockedElfPtr
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E331C
	movs r0, #0x96
	lsls r0, r0, #2
	b _080E3320
	.align 2, 0
_080E3318: .4byte gUnlockedElfPtr
_080E331C:
	movs r0, #0xe1
	lsls r0, r0, #2
_080E3320:
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #0
	movs r2, #0
	bl CreatePickupItem
_080E332E:
	ldr r0, [r5, #0x60]
	adds r1, r0, #0
	subs r0, #1
	str r0, [r5, #0x60]
	cmp r1, #0
	bne _080E3348
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #1
	bl FUN_080bfc94
	movs r0, #0x20
	str r0, [r5, #0x60]
_080E3348:
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NurseE_Die
NurseE_Die:
	push {r4, lr}
	.byte 0x04, 0x1C, 0x54, 0x30, 0x00, 0x21
	.byte 0xDC, 0xF7, 0xC2, 0xFC, 0xA1, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0xA0, 0x72, 0x05, 0x49, 0x60, 0x7A
	.byte 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xE1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x60, 0x61, 0x10, 0xBC
	pop {r0}
	bx r0
	.4byte gElfFnTable

	thumb_func_start FUN_080e3388
FUN_080e3388: @ 0x080E3388
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r2
	mov r8, r3
	ldr r5, [sp, #0x1c]
	ldr r0, [r1]
	ldr r2, [r7]
	subs r0, r0, r2
	ldr r1, [r1, #4]
	ldr r2, [r7, #4]
	subs r1, r1, r2
	bl CalcAngle
	adds r6, r0, #0
	mov r0, sb
	ldr r4, [r0]
	adds r3, r6, #0
	cmp r4, #0
	ble _080E33D0
	mov r1, r8
	ldrb r3, [r1]
	subs r0, r6, r3
	adds r0, #0x3f
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7e
	bgt _080E33D0
	adds r0, r6, #0
	adds r1, r3, #0
	ldr r2, [sp, #0x34]
	bl FUN_080e964c
	adds r3, r0, #0
_080E33D0:
	mov r0, r8
	strb r3, [r0]
	subs r0, r6, r3
	adds r0, #0x3f
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7e
	bgt _080E33F2
	cmp r5, #0
	bgt _080E33E8
	ldr r5, [sp, #0x20]
	b _080E33F4
_080E33E8:
	ldr r1, [sp, #0x24]
	cmp r5, r1
	ble _080E33F4
	adds r5, r1, #0
	b _080E33F4
_080E33F2:
	movs r5, #0
_080E33F4:
	cmp r4, r5
	beq _080E3422
	cmp r4, r5
	bge _080E3406
	ldr r0, [sp, #0x2c]
	adds r4, r4, r0
	cmp r4, r5
	ble _080E341E
	b _080E341C
_080E3406:
	ldr r1, [sp, #0x28]
	cmp r1, #0
	ble _080E3414
	cmp r4, r1
	ble _080E3414
	ldr r0, [sp, #0x30]
	b _080E3416
_080E3414:
	ldr r0, [sp, #0x2c]
_080E3416:
	subs r4, r4, r0
	cmp r4, r5
	bge _080E341E
_080E341C:
	adds r4, r5, #0
_080E341E:
	mov r1, sb
	str r4, [r1]
_080E3422:
	cmp r4, #0
	ble _080E3458
	ldr r2, _080E3464 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r7]
	adds r0, r0, r1
	str r0, [r7]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r7, #4]
	adds r0, r0, r1
	str r0, [r7, #4]
_080E3458:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E3464: .4byte gSineTable
