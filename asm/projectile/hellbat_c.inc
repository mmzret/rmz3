	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a1a1c
FUN_080a1a1c: @ 0x080A1A1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _080A1A30
	subs r0, #1
	str r0, [r1]
_080A1A30:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A1A50
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_080A1A50:
	ldrb r6, [r4, #0xe]
	cmp r6, #1
	bne _080A1A58
	b _080A1C70
_080A1A58:
	cmp r6, #1
	bgt _080A1A62
	cmp r6, #0
	beq _080A1A6A
	b _080A1F04
_080A1A62:
	cmp r6, #2
	bne _080A1A68
	b _080A1ED0
_080A1A68:
	b _080A1F04
_080A1A6A:
	movs r7, #0
	strb r6, [r4, #0x12]
	strb r6, [r4, #0x13]
	str r6, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r5, [r0]
	cmp r5, #0
	bne _080A1AC4
	ldr r1, _080A1ABC @ =gSineTable
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0x14
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1AC0 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080A1B9E
	.align 2, 0
_080A1ABC: .4byte gSineTable
_080A1AC0: .4byte 0x0000A906
_080A1AC4:
	cmp r5, #1
	bne _080A1B08
	ldr r1, _080A1B00 @ =gSineTable
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1B04 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	b _080A1B8C
	.align 2, 0
_080A1B00: .4byte gSineTable
_080A1B04: .4byte 0x0000A906
_080A1B08:
	cmp r5, #2
	bne _080A1B58
	ldr r1, _080A1B50 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0x94
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1B54 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080A1B9E
	.align 2, 0
_080A1B50: .4byte gSineTable
_080A1B54: .4byte 0x0000A906
_080A1B58:
	cmp r5, #3
	bne _080A1BB8
	ldr r1, _080A1BAC @ =gSineTable
	adds r0, r1, #0
	adds r0, #0x6c
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	adds r1, #0xec
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1BB0 @ =0x0000A906
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
_080A1B8C:
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080A1B9E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A1BB4 @ =0x0836B2DC
	bl SetDDP
	b _080A1C6A
	.align 2, 0
_080A1BAC: .4byte gSineTable
_080A1BB0: .4byte 0x0000A906
_080A1BB4: .4byte 0x0836B2DC
_080A1BB8:
	cmp r5, #4
	bne _080A1C1C
	ldr r1, _080A1C10 @ =gSineTable
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1C14 @ =0x0000A90A
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A1C18 @ =0x0836B2F4
	bl SetDDP
	b _080A1C6A
	.align 2, 0
_080A1C10: .4byte gSineTable
_080A1C14: .4byte 0x0000A90A
_080A1C18: .4byte 0x0836B2F4
_080A1C1C:
	cmp r5, #5
	bne _080A1C6A
	ldr r1, _080A1CCC @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xec
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	ldr r1, _080A1CD0 @ =0x0000A90A
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A1CD4 @ =0x0836B2F4
	bl SetDDP
_080A1C6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A1C70:
	movs r6, #0
	ldr r0, [r4, #0x54]
	ldr r5, [r4, #0x5c]
	adds r2, r0, r5
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r3, [r4, #0x60]
	adds r1, r0, r3
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r7, [r0]
	cmp r7, #3
	bgt _080A1D68
	cmp r3, #0
	bge _080A1D0C
	str r6, [sp]
	ldr r0, _080A1CD8 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080A1CDC @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	bge _080A1CA2
	movs r0, #1
	str r0, [sp]
_080A1CA2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #4]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1CE0
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	ble _080A1CE0
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
	.align 2, 0
_080A1CCC: .4byte gSineTable
_080A1CD0: .4byte 0x0000A90A
_080A1CD4: .4byte 0x0836B2F4
_080A1CD8: .4byte gStageRun+232
_080A1CDC: .4byte 0xFFFFB000
_080A1CE0:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1CF6
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	bge _080A1CF6
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
_080A1CF6:
	ldr r1, [sp]
	cmp r1, #0
	bne _080A1CFE
	b _080A1E40
_080A1CFE:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1D0C:
	adds r0, r2, #0
	bl PushoutToUp1
	str r0, [sp]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #4]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1D3E
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	ble _080A1D3E
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
_080A1D3E:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1D54
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	bge _080A1D54
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	rsbs r0, r1, #0
	b _080A1E3C
_080A1D54:
	ldr r1, [sp]
	cmp r1, #0
	beq _080A1E40
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1D68:
	cmp r5, #0
	ble _080A1DCC
	adds r0, r2, #0
	bl PushoutToUp1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r0, _080A1DAC @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080A1DB0 @ =0xFFFFB000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r1, r0
	bge _080A1D88
	movs r0, #1
	str r0, [sp, #4]
_080A1D88:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1DB4
	ldr r1, [r4, #0x60]
	cmp r1, #0
	bge _080A1DB4
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
	.align 2, 0
_080A1DAC: .4byte gStageRun+232
_080A1DB0: .4byte 0xFFFFB000
_080A1DB4:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1E2C
	ldr r1, [r4, #0x60]
	cmp r1, #0
	ble _080A1E2C
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1DCC:
	adds r0, r2, #0
	bl PushoutToUp1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r0, _080A1E0C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080A1E10 @ =0xFFFFB000
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	cmp r1, r0
	bge _080A1DE8
	movs r0, #1
	str r0, [sp, #4]
_080A1DE8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _080A1E14
	ldr r1, [r4, #0x60]
	cmp r1, #0
	bge _080A1E14
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
	.align 2, 0
_080A1E0C: .4byte gStageRun+232
_080A1E10: .4byte 0xFFFFB000
_080A1E14:
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _080A1E2C
	ldr r1, [r4, #0x60]
	cmp r1, #0
	ble _080A1E2C
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	rsbs r0, r1, #0
	str r0, [r4, #0x60]
	b _080A1E3E
_080A1E2C:
	ldr r1, [sp]
	cmp r1, #0
	beq _080A1E40
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
_080A1E3C:
	str r0, [r4, #0x5c]
_080A1E3E:
	movs r6, #1
_080A1E40:
	cmp r6, #1
	bne _080A1E7A
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r2, [r4, #0xa]
	lsrs r1, r2, #4
	eors r1, r6
	ands r1, r6
	cmp r1, #0
	beq _080A1E5C
	movs r0, #0x10
	orrs r0, r2
	b _080A1E60
_080A1E5C:
	movs r0, #0xef
	ands r0, r2
_080A1E60:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080A1E7A:
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _080A1EA2
	movs r0, #0xff
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A1EA2:
	ldrb r1, [r4, #0x13]
	adds r1, #1
	strb r1, [r4, #0x13]
	lsls r1, r1, #0x18
	movs r0, #0xe0
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	bne _080A1EC8
	adds r1, r4, #0
	adds r1, #0x54
	adds r2, r7, #0
	ldrb r3, [r4, #0xa]
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r4, #0
	bl FUN_080bde9c
_080A1EC8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080A1F04
_080A1ED0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	ldr r0, [r4, #0x64]
	adds r1, #2
	strh r0, [r1]
	ldr r0, [r4, #0x64]
	cmp r0, #0
	ble _080A1EEE
	subs r0, #0x20
	str r0, [r4, #0x64]
_080A1EEE:
	ldr r0, [r4, #0x64]
	cmp r0, #0x20
	bgt _080A1F04
	ldr r1, _080A1F0C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A1F04:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1F0C: .4byte gProjectileFnTable

