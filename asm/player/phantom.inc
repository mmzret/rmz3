	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PhantomMini_Update
PhantomMini_Update: @ 0x08034AC0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r1, #0x14]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _08034B04 @ =0x0835EA68
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08034B08 @ =0x0835EA78
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, [r4, #0x68]
	movs r2, #0xf0
	lsls r2, r2, #8
	adds r1, r0, r2
	ldr r0, [r4, #0x58]
	cmp r0, r1
	ble _08034AFE
	str r1, [r4, #0x58]
_08034AFE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034B04: .4byte 0x0835EA68
_08034B08: .4byte 0x0835EA78

	thumb_func_start PhantomMini_Die
PhantomMini_Die: @ 0x08034B0C
	ldr r2, _08034B20 @ =gZeroFnTable
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
_08034B20: .4byte gZeroFnTable

	thumb_func_start nop_08034b24
nop_08034b24: @ 0x08034B24
	bx lr
	.align 2, 0

	thumb_func_start FUN_08034b28
FUN_08034b28: @ 0x08034B28
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x28]
	adds r0, r1, #0
	adds r0, #0xd6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034B46
	ldrb r0, [r1, #1]
	cmp r0, #3
	beq _08034B46
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08034B46:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start phantom_08034b4c
phantom_08034b4c: @ 0x08034B4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov r8, r0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08034B64
	cmp r4, #1
	beq _08034B96
	b _08034D36
_08034B64:
	strb r4, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r1, _08034BAC @ =0x0000BC04
	adds r0, r5, #0
	bl SetMotion
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08034B96:
	mov r3, r8
	ldrh r1, [r3, #0x10]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08034BB4
	ldr r0, [r5, #0x54]
	ldr r4, _08034BB0 @ =0xFFFFFE00
	adds r0, r0, r4
	b _08034BC4
	.align 2, 0
_08034BAC: .4byte 0x0000BC04
_08034BB0: .4byte 0xFFFFFE00
_08034BB4:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08034BDE
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
_08034BC4:
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl FUN_080349a8
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r2, r0
	ldr r1, _08034C84 @ =0x000007FF
	cmp r0, r1
	ble _08034BDE
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_08034BDE:
	mov r3, r8
	ldrh r1, [r3, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08034BF2
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08034BF2:
	ldr r2, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _08034C9C
	movs r3, #0
	ldr r0, _08034C88 @ =gOverworld
	movs r4, #0xe9
	lsls r4, r4, #1
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r3, r1
	bge _08034C2E
	movs r7, #0xea
	lsls r7, r7, #1
	adds r0, r4, r7
	ldrh r0, [r0]
	cmp r0, r2
	beq _08034C2E
	adds r6, r1, #0
	adds r1, r4, #0
_08034C1E:
	adds r1, #0x18
	adds r3, #1
	cmp r3, r6
	bge _08034C2E
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r2
	bne _08034C1E
_08034C2E:
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r3, r0
	beq _08034C8C
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r0, r2, r0
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r3, #8
	adds r0, r4, r3
	adds r0, r2, r0
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r5, #0x54]
	mov r3, r8
	ldr r0, [r3, #0x14]
	subs r1, r1, r0
	str r1, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r2, r0
	ldr r1, [r5, #0x58]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r2, r2, r0
	ldr r0, [r2]
	subs r1, r1, r0
	str r1, [r5, #0x58]
	b _08034C92
	.align 2, 0
_08034C84: .4byte 0x000007FF
_08034C88: .4byte gOverworld
_08034C8C:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_08034C92:
	ldr r1, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08034CDE
_08034C9C:
	adds r0, r5, #0
	bl FUN_080349a8
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r2, r0
	ldr r1, _08034D20 @ =0x000007FF
	cmp r0, r1
	bgt _08034CB0
	str r2, [r5, #0x58]
_08034CB0:
	movs r4, #1
	rsbs r4, r4, #0
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r0, r4, #0
	bl isStageBlocking
	adds r3, r0, #0
	cmp r3, r4
	beq _08034CDE
	ldr r0, _08034D24 @ =gOverworld
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r3, #0xea
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	str r0, [r5, #0x5c]
_08034CDE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08034CFA
	movs r0, #1
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08034CFA
	ldr r1, _08034D28 @ =0x0000BC02
	adds r0, r5, #0
	bl SetMotion
_08034CFA:
	ldr r1, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08034D30
	ldr r1, _08034D2C @ =0x0000BC03
	adds r0, r5, #0
	movs r2, #3
	movs r3, #4
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08034D36
	.align 2, 0
_08034D20: .4byte 0x000007FF
_08034D24: .4byte gOverworld
_08034D28: .4byte 0x0000BC02
_08034D2C: .4byte 0x0000BC03
_08034D30:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08034D36:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08034d40
FUN_08034d40: @ 0x08034D40
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08034D52
	cmp r0, #1
	beq _08034D5A
	b _08034DB4
_08034D52:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08034D5A:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08034D6A
	str r1, [r4, #0x60]
_08034D6A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl FUN_080349a8
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r0, r1
	ble _08034D88
	str r1, [r4, #0x58]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08034D88:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrh r1, [r5, #0x10]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08034DA0
	ldr r0, [r4, #0x54]
	ldr r1, _08034DBC @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08034DA0:
	ldrh r1, [r5, #0x10]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08034DB4
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08034DB4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034DBC: .4byte 0xFFFFFE00

	thumb_func_start phantom_08034dc0
phantom_08034dc0: @ 0x08034DC0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08034DD2
	cmp r0, #1
	beq _08034DEE
	b _08034E3E
_08034DD2:
	movs r0, #0xfc
	bl PlaySound
	ldr r1, _08034E44 @ =0x0000BC03
	adds r0, r4, #0
	movs r2, #2
	movs r3, #4
	bl GotoMotion
	ldr r0, _08034E48 @ =0xFFFFF900
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08034DEE:
	ldr r0, [r4, #0x60]
	adds r2, r0, #0
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldrh r1, [r5, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08034E0A
	cmp r2, #0
	ble _08034E12
_08034E0A:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08034E12:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrh r1, [r5, #0x10]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08034E2A
	ldr r0, [r4, #0x54]
	ldr r1, _08034E4C @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08034E2A:
	ldrh r1, [r5, #0x10]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08034E3E
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08034E3E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034E44: .4byte 0x0000BC03
_08034E48: .4byte 0xFFFFF900
_08034E4C: .4byte 0xFFFFFE00

	thumb_func_start FUN_08034e50
FUN_08034e50: @ 0x08034E50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov r8, r0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08034E68
	cmp r4, #1
	beq _08034EA4
	b _08034FEE
_08034E68:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08034F38 @ =0x0835EAA0
	bl SetDDP
	strb r4, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r1, _08034F3C @ =0x0000BC13
	adds r0, r5, #0
	bl SetMotion
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08034EA4:
	ldr r2, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _08034F54
	movs r3, #0
	ldr r0, _08034F40 @ =gOverworld
	movs r4, #0xe9
	lsls r4, r4, #1
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r3, r1
	bge _08034EE0
	movs r7, #0xea
	lsls r7, r7, #1
	adds r0, r4, r7
	ldrh r0, [r0]
	cmp r0, r2
	beq _08034EE0
	adds r6, r1, #0
	adds r1, r4, #0
_08034ED0:
	adds r1, #0x18
	adds r3, #1
	cmp r3, r6
	bge _08034EE0
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r2
	bne _08034ED0
_08034EE0:
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r3, r0
	beq _08034F44
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r0, r2, r0
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r3, #8
	adds r0, r4, r3
	adds r0, r2, r0
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r5, #0x54]
	mov r3, r8
	ldr r0, [r3, #0x14]
	subs r1, r1, r0
	str r1, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r2, r0
	ldr r1, [r5, #0x58]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r2, r2, r0
	ldr r0, [r2]
	subs r1, r1, r0
	str r1, [r5, #0x58]
	b _08034F4A
	.align 2, 0
_08034F38: .4byte 0x0835EAA0
_08034F3C: .4byte 0x0000BC13
_08034F40: .4byte gOverworld
_08034F44:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_08034F4A:
	ldr r1, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08034F96
_08034F54:
	adds r0, r5, #0
	bl FUN_080349a8
	adds r2, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r2, r0
	ldr r1, _08034FD8 @ =0x000007FF
	cmp r0, r1
	bgt _08034F68
	str r2, [r5, #0x58]
_08034F68:
	movs r4, #1
	rsbs r4, r4, #0
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r0, r4, #0
	bl isStageBlocking
	adds r3, r0, #0
	cmp r3, r4
	beq _08034F96
	ldr r0, _08034FDC @ =gOverworld
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r3, #0xea
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	str r0, [r5, #0x5c]
_08034F96:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08034FB2
	movs r0, #1
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08034FB2
	ldr r1, _08034FE0 @ =0x0000BC02
	adds r0, r5, #0
	bl SetMotion
_08034FB2:
	ldr r1, [r5, #0x5c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08034FE8
	ldr r1, _08034FE4 @ =0x0000BC03
	adds r0, r5, #0
	movs r2, #3
	movs r3, #4
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08034FEE
	.align 2, 0
_08034FD8: .4byte 0x000007FF
_08034FDC: .4byte gOverworld
_08034FE0: .4byte 0x0000BC02
_08034FE4: .4byte 0x0000BC03
_08034FE8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08034FEE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
