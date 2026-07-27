	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatKnockBackDamage
hellbatKnockBackDamage: @ 0x0804CAA4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804CAB4
	cmp r5, #1
	beq _0804CB62
	b _0804CBD4
_0804CAB4:
	movs r0, #0x8a
	bl PlaySound
	ldr r1, _0804CAF0 @ =0x0000A80B
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _0804CAF4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0804CAFC
	ldr r0, _0804CAF8 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0804CB1E
	.align 2, 0
_0804CAF0: .4byte 0x0000A80B
_0804CAF4: .4byte pZero2
_0804CAF8: .4byte 0xFFFFFE00
_0804CAFC:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_0804CB1E:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	movs r3, #0
	orrs r1, r0
	strb r1, [r4, #0xa]
	movs r0, #0x20
	ands r1, r0
	cmp r1, #0
	beq _0804CB52
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0xe4
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804CB52:
	adds r0, r4, #0
	adds r0, #0xc0
	str r3, [r0]
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804CB62:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	cmp r0, #0
	ble _0804CB9A
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	ldr r2, _0804CBDC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804CB9A
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804CB9A:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804CBBC
	ldr r0, [r4, #0x54]
	ldr r1, _0804CBE0 @ =0xFFFFE800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _0804CBDC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804CBBC
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804CBBC:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804CBCC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804CBD4
_0804CBCC:
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804CBD4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804CBDC: .4byte 0xFFFFF800
_0804CBE0: .4byte 0xFFFFE800

	thumb_func_start hellbat_0804cbe4
hellbat_0804cbe4: @ 0x0804CBE4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r6, [r5]
	cmp r6, #0
	bne _0804CC2E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804CC2E
	ldr r2, _0804CC28 @ =sElementCoord
	movs r0, #0x11
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0804CC2E
	str r6, [r5]
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x30
	bne _0804CC2C
	movs r0, #0x8a
	bl PlaySound
	b _0804CC2E
	.align 2, 0
_0804CC28: .4byte sElementCoord
_0804CC2C:
	str r6, [r5]
_0804CC2E:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start hellbat_0804cc38
hellbat_0804cc38: @ 0x0804CC38
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _0804CC4E
	cmp r0, #0xe
	beq _0804CC4E
	cmp r0, #0xf
	bne _0804CC90
_0804CC4E:
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0804CC70
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0804CC90
_0804CC70:
	ldr r0, _0804CC88 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0804CC90
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804CC8C
	movs r0, #0xff
	b _0804CC8E
	.align 2, 0
_0804CC88: .4byte gStageRun
_0804CC8C:
	movs r0, #0xfe
_0804CC8E:
	strb r0, [r2, #0x11]
_0804CC90:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _0804CCC2
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804CCC2
	ldr r0, [r2, #4]
	ldr r1, _0804CCC8 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0804CCC2
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xb
	beq _0804CCC2
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0804CCC2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804CCC8: .4byte 0x000200FF
