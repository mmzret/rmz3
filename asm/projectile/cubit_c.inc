	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a7a7c
FUN_080a7a7c: @ 0x080A7A7C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, [r7, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080A7A8A
	b _080A7C40
_080A7A8A:
	adds r0, r1, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A7A9E
	ldrb r0, [r7, #0xe]
	cmp r0, #3
	beq _080A7A9E
	movs r0, #3
	strb r0, [r7, #0xe]
_080A7A9E:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #0xb
	bne _080A7AB0
	ldrb r0, [r7, #0xe]
	cmp r0, #3
	beq _080A7AB0
	movs r0, #3
	strb r0, [r7, #0xe]
_080A7AB0:
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bls _080A7AB8
	b _080A7C52
_080A7AB8:
	lsls r0, r0, #2
	ldr r1, _080A7AC4 @ =_080A7AC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A7AC4: .4byte _080A7AC8
_080A7AC8: @ jump table
	.4byte _080A7ADC @ case 0
	.4byte _080A7B82 @ case 1
	.4byte _080A7C04 @ case 2
	.4byte _080A7C22 @ case 3
	.4byte _080A7C30 @ case 4
_080A7ADC:
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	bne _080A7B1A
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_0800a31c
	adds r4, r0, #0
	adds r0, r7, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A7AFC
	movs r0, #0xc0
	lsls r0, r0, #4
	b _080A7B3C
_080A7AFC:
	cmp r0, #1
	bne _080A7B06
	movs r0, #0x98
	lsls r0, r0, #7
	b _080A7B3C
_080A7B06:
	cmp r0, #2
	bne _080A7B10
	movs r0, #0x8c
	lsls r0, r0, #8
	b _080A7B3C
_080A7B10:
	cmp r0, #3
	bne _080A7B3E
	movs r0, #0xcc
	lsls r0, r0, #8
	b _080A7B3C
_080A7B1A:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_0800a31c
	adds r4, r0, #0
	adds r0, r7, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A7B34
	movs r0, #0xb0
	lsls r0, r0, #6
	b _080A7B3C
_080A7B34:
	cmp r0, #1
	bne _080A7B3E
	movs r0, #0xac
	lsls r0, r0, #8
_080A7B3C:
	adds r4, r4, r0
_080A7B3E:
	ldr r1, _080A7BF0 @ =0x0000B110
	adds r0, r7, #0
	bl SetMotion
	movs r6, #0
	movs r0, #0x32
	strb r0, [r7, #0x12]
	ldr r5, [r7, #0x54]
	subs r0, r4, r5
	movs r1, #0x32
	bl __divsi3
	str r0, [r7, #0x5c]
	ldr r4, _080A7BF4 @ =0x00013880
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl FUN_08009f6c
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	subs r4, r4, r0
	ldrb r1, [r7, #0x12]
	adds r0, r4, #0
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A7B82:
	ldr r2, [r7, #0x60]
	adds r2, #0x40
	str r2, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r2
	str r0, [r7, #0x58]
	cmp r2, #0
	ble _080A7BD2
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _080A7BAC
	adds r0, #1
	strb r0, [r7, #0x13]
	ldr r1, _080A7BF8 @ =0x0000B111
	adds r0, r7, #0
	bl SetMotion
_080A7BAC:
	ldrb r1, [r7, #0x13]
	cmp r1, #1
	bne _080A7BD2
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A7BD2
	adds r0, r1, #1
	strb r0, [r7, #0x13]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080A7BFC @ =0x0836BCDC
	bl SetDDP
	ldr r1, _080A7C00 @ =0x0000B112
	adds r0, r7, #0
	bl SetMotion
_080A7BD2:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A7BE8
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A7C52
_080A7BE8:
	movs r0, #0x28
	strb r0, [r7, #0x12]
	b _080A7C1A
	.align 2, 0
_080A7BF0: .4byte 0x0000B110
_080A7BF4: .4byte 0x00013880
_080A7BF8: .4byte 0x0000B111
_080A7BFC: .4byte sCollisions+(13*24)
_080A7C00: .4byte 0x0000B112
_080A7C04:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080A7C1A
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A7C52
_080A7C1A:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080A7C52
_080A7C22:
	ldr r1, _080A7C58 @ =0x0000B113
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080A7C30:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A7C52
_080A7C40:
	ldr r1, _080A7C5C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080A7C52:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7C58: .4byte 0x0000B113
_080A7C5C: .4byte gProjectileFnTable

