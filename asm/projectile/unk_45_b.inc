	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b1b7c
FUN_080b1b7c: @ 0x080B1B7C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B1BA2
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
	strb r0, [r5, #0xa]
	b _080B1BBC
_080B1BA2:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080B1BD4
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1BD4
_080B1BBC:
	ldr r1, _080B1BD0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B1CAE
	.align 2, 0
_080B1BD0: .4byte gProjectileFnTable
_080B1BD4:
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B1BE0
	cmp r6, #1
	beq _080B1CA0
	b _080B1CAE
_080B1BE0:
	movs r7, #0
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080B1C2C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1C28 @ =0x0836D7DC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb6
	lsls r1, r1, #7
	b _080B1C52
	.align 2, 0
_080B1C28: .4byte 0x0836D7DC
_080B1C2C:
	cmp r0, #1
	bne _080B1C60
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1C5C @ =0x0836D7F4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb8
	lsls r1, r1, #7
_080B1C52:
	adds r0, r5, #0
	bl SetMotion
	b _080B1C8C
	.align 2, 0
_080B1C5C: .4byte 0x0836D7F4
_080B1C60:
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #2
	bne _080B1C8C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1CB4 @ =0x0836D80C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xbe
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
_080B1C8C:
	ldr r0, _080B1CB8 @ =FUN_080b2178
	str r0, [r4, #0x24]
	movs r0, #0
	str r0, [r5, #0x60]
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1CA0:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
_080B1CAE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1CB4: .4byte 0x0836D80C
_080B1CB8: .4byte FUN_080b2178

	thumb_func_start FUN_080b1cbc
FUN_080b1cbc: @ 0x080B1CBC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xbc
	ldrb r6, [r0]
	cmp r6, #0
	beq _080B1D24
	subs r0, #0x30
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _080B1D0E
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	ldr r0, _080B1D20 @ =0x00000137
	bl PlaySound
_080B1D0E:
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	b _080B1EE2
	.align 2, 0
_080B1D20: .4byte 0x00000137
_080B1D24:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r7, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1D34
	b _080B1ED6
_080B1D34:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080B1E0C
	cmp r0, #1
	bgt _080B1D44
	cmp r0, #0
	beq _080B1D52
	b _080B1EF4
_080B1D44:
	cmp r0, #2
	bne _080B1D4A
	b _080B1E5C
_080B1D4A:
	cmp r0, #3
	bne _080B1D50
	b _080B1EA0
_080B1D50:
	b _080B1EF4
_080B1D52:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080B1D9C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1D94 @ =0x0836D824
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1D98 @ =0x00000E08
	b _080B1DC0
	.align 2, 0
_080B1D94: .4byte 0x0836D824
_080B1D98: .4byte 0x00000E08
_080B1D9C:
	cmp r0, #1
	bne _080B1DD0
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1DC8 @ =0x0836D83C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1DCC @ =0x00000E07
_080B1DC0:
	adds r0, r5, #0
	bl SetMotion
	b _080B1DFA
	.align 2, 0
_080B1DC8: .4byte 0x0836D83C
_080B1DCC: .4byte 0x00000E07
_080B1DD0:
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #2
	bne _080B1DFA
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1E4C @ =0x0836D854
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1E50 @ =0x00000E09
	adds r0, r5, #0
	bl SetMotion
_080B1DFA:
	ldr r0, _080B1E54 @ =FUN_080b21c0
	str r0, [r4, #0x24]
	movs r0, #0
	str r0, [r5, #0x60]
	subs r0, #0xa8
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1E0C:
	ldr r0, [r5, #0x60]
	adds r0, #0x10
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1E1C
	str r1, [r5, #0x60]
_080B1E1C:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, _080B1E58 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1EF4
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _080B1E94
	.align 2, 0
_080B1E4C: .4byte 0x0836D854
_080B1E50: .4byte 0x00000E09
_080B1E54: .4byte FUN_080b21c0
_080B1E58: .4byte 0xFFFFF800
_080B1E5C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _080B1E9C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r1, [r5, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	cmp r0, r1
	beq _080B1EF4
	str r6, [r5, #0x60]
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	movs r0, #0x28
	strb r0, [r5, #0x13]
_080B1E94:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080B1EF4
	.align 2, 0
_080B1E9C: .4byte 0xFFFFF000
_080B1EA0:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1EB0
	str r1, [r5, #0x60]
_080B1EB0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080B1ED6
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1EF4
_080B1ED6:
	ldr r1, [r5, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _080B1EE2
	subs r0, #1
	strb r0, [r1, #0xc]
_080B1EE2:
	ldr r1, _080B1EFC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B1EF4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1EFC: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1f00
FUN_080b1f00: @ 0x080B1F00
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne _080B1F12
	movs r0, #0xff
	strb r0, [r6, #0x12]
_080B1F12:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1F38
	ldr r1, _080B1F34 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080B2030
	.align 2, 0
_080B1F34: .4byte gProjectileFnTable
_080B1F38:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B1F44
	cmp r0, #1
	beq _080B2010
	b _080B2030
_080B1F44:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r6, #0x58]
	ldr r0, _080B1FC0 @ =0x000117FF
	cmp r1, r0
	ble _080B1FA2
	ldr r0, _080B1FC4 @ =0x00013BFF
	cmp r1, r0
	bgt _080B1FD4
	ldr r0, [r6, #0x54]
	ldr r4, _080B1FC8 @ =0xFFFFF800
	adds r1, r1, r4
	bl FUN_0800a31c
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_0800a22c
	ldr r0, [r6, #0x54]
	ldr r2, _080B1FCC @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	movs r4, #0x9e
	lsls r4, r4, #9
	cmp r0, r4
	bgt _080B1FA2
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r2, _080B1FC8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	cmp r0, r4
	ble _080B1FD4
_080B1FA2:
	ldr r1, _080B1FD0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	b _080B2030
	.align 2, 0
_080B1FC0: .4byte 0x000117FF
_080B1FC4: .4byte 0x00013BFF
_080B1FC8: .4byte 0xFFFFF800
_080B1FCC: .4byte 0xFFFFE000
_080B1FD0: .4byte gProjectileFnTable
_080B1FD4:
	adds r1, r6, #0
	adds r1, #0x25
	movs r5, #0
	movs r0, #0x12
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080B2038 @ =0x0836D86C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r1, #0xf3
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xb4
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B2010:
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B2020
	ldr r0, [r6, #0x54]
	ldr r1, _080B203C @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r6, #0x54]
_080B2020:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, _080B2040 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl Camera_GetDistance
_080B2030:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B2038: .4byte 0x0836D86C
_080B203C: .4byte 0xFFFC4000
_080B2040: .4byte gStageRun+232

	thumb_func_start FUN_080b2044
FUN_080b2044: @ 0x080B2044
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne _080B2056
	movs r0, #0xff
	strb r0, [r5, #0x12]
_080B2056:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B207C
	ldr r1, _080B2078 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B216C
	.align 2, 0
_080B2078: .4byte gProjectileFnTable
_080B207C:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #1
	bne _080B20C2
	ldrb r0, [r5, #0xe]
	cmp r0, #2
	beq _080B20C2
	ldr r1, [r5, #0x28]
	ldrh r0, [r1, #0xe]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0xe]
	ldr r0, _080B20D4 @ =0x00000137
	bl PlaySound
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	movs r0, #2
	strb r0, [r5, #0xe]
_080B20C2:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080B2116
	cmp r0, #1
	bgt _080B20D8
	cmp r0, #0
	beq _080B20DE
	b _080B216C
	.align 2, 0
_080B20D4: .4byte 0x00000137
_080B20D8:
	cmp r0, #2
	beq _080B214C
	b _080B216C
_080B20DE:
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B2138 @ =0x0836D884
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080B213C @ =FUN_080b2204
	str r0, [r4, #0x24]
	ldr r1, _080B2140 @ =0x0000AA04
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B2116:
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B2126
	ldr r0, [r5, #0x54]
	ldr r1, _080B2144 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r5, #0x54]
_080B2126:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _080B2148 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl Camera_GetDistance
	b _080B216C
	.align 2, 0
_080B2138: .4byte 0x0836D884
_080B213C: .4byte FUN_080b2204
_080B2140: .4byte 0x0000AA04
_080B2144: .4byte 0xFFFC4000
_080B2148: .4byte gStageRun+232
_080B214C:
	ldrb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080B215C
	movs r0, #0x22
	bl PlaySound
_080B215C:
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B216C
	ldr r0, [r5, #0x54]
	ldr r1, _080B2174 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r5, #0x54]
_080B216C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B2174: .4byte 0xFFFC4000

	thumb_func_start FUN_080b2178
FUN_080b2178: @ 0x080B2178
	push {r4, lr}
	movs r4, #0
	ldr r3, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r2, [r0, #0x2c]
	ldrb r0, [r3, #0x11]
	cmp r0, #0
	bne _080B2190
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B2190
	movs r4, #1
_080B2190:
	ldrb r0, [r3, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21A0
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21A0
	movs r4, #1
_080B21A0:
	cmp r1, #2
	bne _080B21AC
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21AC
	movs r4, #1
_080B21AC:
	adds r1, r3, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
	cmp r4, #1
	bne _080B21BA
	strb r4, [r1]
_080B21BA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b21c0
FUN_080b21c0: @ 0x080B21C0
	push {lr}
	movs r3, #0
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r1, [r0, #0x2c]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	bne _080B21D8
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B21D8
	movs r3, #1
_080B21D8:
	ldrb r0, [r1, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21E8
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21E8
	movs r3, #1
_080B21E8:
	cmp r1, #2
	bne _080B21F4
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21F4
	movs r3, #1
_080B21F4:
	cmp r3, #1
	bne _080B21FE
	adds r0, r2, #0
	adds r0, #0xbc
	strb r3, [r0]
_080B21FE:
	pop {r0}
	bx r0
	.align 2, 0

