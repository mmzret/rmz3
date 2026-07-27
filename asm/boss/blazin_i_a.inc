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
