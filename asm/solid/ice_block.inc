	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start IceBlock_Init
IceBlock_Init: @ 0x080D8B44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #2
	movs r6, #0
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x5c
	str r6, [r0, #4]
	str r6, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080D8BEC @ =0xFFFFF500
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r2, _080D8BF0 @ =gSolidFnTable
	mov r8, r2
	ldrb r2, [r5, #9]
	lsls r2, r2, #2
	add r2, r8
	movs r3, #1
	str r3, [r5, #0xc]
	ldr r2, [r2]
	ldr r2, [r2, #4]
	str r2, [r5, #0x14]
	bl FUN_0800bd38
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D8C64
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	movs r4, #0x80
	lsls r4, r4, #6
	adds r1, r1, r4
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_0800bd38
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D8BF4
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080D8C92
	.align 2, 0
_080D8BEC: .4byte 0xFFFFF500
_080D8BF0: .4byte gSolidFnTable
_080D8BF4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r1, r2
	bl FUN_0800bd38
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D8C0E
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
_080D8C0E:
	ldrb r0, [r5, #0xb]
	movs r1, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080D8C54 @ =0x083710D8
	str r0, [r5, #0x30]
	ldr r0, _080D8C58 @ =0x00003801
	strh r0, [r5, #0x26]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800bd78
	ldr r1, _080D8C5C @ =0x0000CB01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D8C60 @ =0x083710C0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x50
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r0, #2
	strb r0, [r5, #0x10]
	strb r0, [r5, #0xd]
	b _080D8C8C
	.align 2, 0
_080D8C54: .4byte 0x083710D8
_080D8C58: .4byte 0x00003801
_080D8C5C: .4byte 0x0000CB01
_080D8C60: .4byte 0x083710C0
_080D8C64:
	movs r1, #0xcb
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D8C9C @ =0x083710A8
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x50
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D8C8C:
	adds r0, r5, #0
	bl IceBlock_Update
_080D8C92:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8C9C: .4byte 0x083710A8

	thumb_func_start IceBlock_Update
IceBlock_Update: @ 0x080D8CA0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xd]
	cmp r5, #1
	beq _080D8D0A
	cmp r5, #1
	bgt _080D8CB4
	cmp r5, #0
	beq _080D8CBA
	b _080D8E22
_080D8CB4:
	cmp r5, #2
	beq _080D8D9C
	b _080D8E22
_080D8CBA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r3, _080D8D78 @ =gStageRun+232
	ldr r1, [r3, #0x38]
	ldr r2, _080D8D7C @ =0x000077FF
	adds r0, r1, r2
	ldr r2, [r4, #0x54]
	cmp r2, r0
	ble _080D8CD0
	b _080D8E22
_080D8CD0:
	ldr r5, _080D8D80 @ =0xFFFF8800
	adds r0, r1, r5
	cmp r2, r0
	bge _080D8CDA
	b _080D8E22
_080D8CDA:
	ldr r0, [r3, #0x3c]
	ldr r1, _080D8D84 @ =0xFFFF6800
	adds r0, r0, r1
	ldr r3, [r4, #0x58]
	cmp r3, r0
	bge _080D8CE8
	b _080D8E22
_080D8CE8:
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080D8D88 @ =0x083710D8
	str r0, [r4, #0x30]
	ldr r0, _080D8D8C @ =0x00003801
	strh r0, [r4, #0x26]
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0800bd78
	movs r0, #1
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D8D0A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x60]
	ldr r0, _080D8D90 @ =0x000006FF
	cmp r1, r0
	bgt _080D8D1E
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r4, #0x60]
_080D8D1E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	str r1, [r4, #0x68]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	cmp r0, #0
	beq _080D8E22
	ldr r1, [r4, #0x60]
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	ble _080D8D4C
	subs r0, #0xe3
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
_080D8D4C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080D8D94 @ =0x083710C0
	bl SetDDP
	ldr r1, _080D8D98 @ =0x0000CB01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D8E22
	.align 2, 0
_080D8D78: .4byte gStageRun+232
_080D8D7C: .4byte 0x000077FF
_080D8D80: .4byte 0xFFFF8800
_080D8D84: .4byte 0xFFFF6800
_080D8D88: .4byte 0x083710D8
_080D8D8C: .4byte 0x00003801
_080D8D90: .4byte 0x000006FF
_080D8D94: .4byte 0x083710C0
_080D8D98: .4byte 0x0000CB01
_080D8D9C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #1
	bl PushoutToUp1
	cmp r0, #0
	bne _080D8DC0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080D8DEC @ =0x083710A8
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0x10]
	strb r0, [r4, #0xd]
_080D8DC0:
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D8E22
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _080D8DF0 @ =0x0000CB01
	cmp r0, r1
	bne _080D8DF4
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D8E22
	.align 2, 0
_080D8DEC: .4byte 0x083710A8
_080D8DF0: .4byte 0x0000CB01
_080D8DF4:
	movs r1, #0
	str r1, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080D8E28 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080D8E22:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D8E28: .4byte gSolidFnTable

	thumb_func_start IceBlock_Die
IceBlock_Die: @ 0x080D8E2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xd]
	cmp r5, #0
	beq _080D8E3C
	cmp r5, #1
	beq _080D8E54
	b _080D8EE2
_080D8E3C:
	ldr r1, _080D8E6C @ =0x0000CB03
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x3f
	bl PlaySound
	str r5, [r4, #0x60]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D8E54:
	ldrb r1, [r4, #0x13]
	adds r0, r1, #1
	strb r0, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D8E70
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080D8E76
	.align 2, 0
_080D8E6C: .4byte 0x0000CB03
_080D8E70:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_080D8E76:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x60]
	ldr r0, _080D8EE8 @ =0x000006FF
	cmp r1, r0
	bgt _080D8E8C
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r4, #0x60]
_080D8E8C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r0, [r4, #0x68]
	ldr r0, _080D8EEC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080D8EE2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080D8EF0 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080D8EE2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D8EE8: .4byte 0x000006FF
_080D8EEC: .4byte gStageRun+232
_080D8EF0: .4byte gSolidFnTable

	thumb_func_start IceBlock_Disappear
IceBlock_Disappear: @ 0x080D8EF4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _080D8F08
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080D8F08:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080D8F1A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _080D8F28 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800bdd4
_080D8F1A:
	adds r0, r4, #0
	bl DeleteSolid
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D8F28: .4byte 0xFFFFF800
