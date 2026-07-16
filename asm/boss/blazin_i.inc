	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinKnockBackDamage
blazinKnockBackDamage: @ 0x0803FD5C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0803FD6C
	cmp r6, #1
	beq _0803FE0C
	b _0803FED2
_0803FD6C:
	movs r0, #0x74
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0xd0
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803FD94
	strb r6, [r1]
	adds r4, r5, #0
	adds r4, #0xc4
	str r6, [r4]
	adds r0, r5, #0
	movs r1, #2
	bl createBlazinTail
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0xc8
	strh r6, [r0]
_0803FD94:
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0
	bne _0803FDB6
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #3
	ldr r2, _0803FDE8 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
_0803FDB6:
	movs r0, #0x48
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FDC6
	movs r0, #0x48
	bl StopSound
_0803FDC6:
	movs r0, #0x72
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FDD6
	movs r0, #0x72
	bl StopSound
_0803FDD6:
	ldr r0, _0803FDEC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0803FDF4
	ldr r0, _0803FDF0 @ =0xFFFFFE00
	b _0803FDF8
	.align 2, 0
_0803FDE8: .4byte 0xFFFFA200
_0803FDEC: .4byte pZero2
_0803FDF0: .4byte 0xFFFFFE00
_0803FDF4:
	movs r0, #0x80
	lsls r0, r0, #2
_0803FDF8:
	str r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0xc0
	movs r0, #0
	str r0, [r1]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803FE0C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803FE2E
	str r1, [r5, #0x60]
_0803FE2E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r2, r1, r0
	str r2, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _0803FE5C
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r0, r3
	ldr r3, _0803FEC0 @ =0xFFFFF800
	adds r1, r2, r3
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0803FE5C
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0803FE5C:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _0803FE7E
	ldr r0, [r5, #0x54]
	ldr r1, _0803FEC4 @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0803FEC0 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0803FE7E
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0803FE7E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0803FE92
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0803FE92:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803FEA2
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803FED2
_0803FEA2:
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r1, [r2]
	cmp r1, #0
	beq _0803FEC8
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0803FED2
	movs r0, #0
	str r0, [r2]
	movs r1, #3
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
	b _0803FECE
	.align 2, 0
_0803FEC0: .4byte 0xFFFFF800
_0803FEC4: .4byte 0xFFFFE000
_0803FEC8:
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0803FECE:
	movs r0, #0xff
	strb r0, [r5, #0xf]
_0803FED2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start blazin_0803fed8
blazin_0803fed8: @ 0x0803FED8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r6, [r5]
	cmp r6, #0
	bne _0803FF1E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803FF1E
	ldr r2, _0803FF18 @ =gBlazinCoords
	movs r0, #9
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0803FF1E
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x10
	bne _0803FF1C
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
	b _0803FF1E
	.align 2, 0
_0803FF18: .4byte gBlazinCoords
_0803FF1C:
	str r6, [r5]
_0803FF1E:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803ff28
FUN_0803ff28: @ 0x0803FF28
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _0803FF40
	cmp r0, #0xe
	beq _0803FF40
	cmp r0, #0xf
	bne _0803FF80
_0803FF40:
	ldr r2, [r3, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0803FF5E
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0803FF80
_0803FF5E:
	ldr r0, _0803FF78 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0803FF80
	ldr r1, [r2, #0x54]
	ldr r0, [r4]
	cmp r1, r0
	bge _0803FF7C
	movs r0, #0xff
	b _0803FF7E
	.align 2, 0
_0803FF78: .4byte gStageRun
_0803FF7C:
	movs r0, #0xfe
_0803FF7E:
	strb r0, [r2, #0x11]
_0803FF80:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _0803FFB6
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0803FFB6
	ldr r0, [r2, #4]
	ldr r1, _0803FFBC @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0803FFB6
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xb
	beq _0803FFB6
	cmp r0, #5
	beq _0803FFB6
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803FFB6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803FFBC: .4byte 0x000200FF

