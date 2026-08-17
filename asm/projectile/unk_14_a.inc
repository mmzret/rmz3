	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile14_Init
Projectile14_Init: @ 0x080A0A60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080A0AE0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080A0AE4 @ =u8_ARRAY_0836b20c
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080A0AE8 @ =sCollisions
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080A0AEC @ =onCollision
	str r0, [r5, #0x24]
	ldr r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0xb4
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r1]
	adds r5, #0x44
	ldr r0, [r4, #0x58]
	asrs r0, r0, #8
	str r0, [r5]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	str r1, [r5]
	adds r0, r4, #0
	bl Projectile14_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0AE0: .4byte gProjectileFnTable
_080A0AE4: .4byte u8_ARRAY_0836b20c
_080A0AE8: .4byte sCollisions
_080A0AEC: .4byte onCollision

	thumb_func_start Projectile14_Update
Projectile14_Update: @ 0x080A0AF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A0B1C @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080A0B20 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0B1C: .4byte sUpdates1
_080A0B20: .4byte sUpdates2

	thumb_func_start Projectile14_Die
Projectile14_Die: @ 0x080A0B24
	push {r4, lr}
	adds r4, r0, #0
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
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080A0B68 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0B68: .4byte gProjectileFnTable

	thumb_func_start nop_080a0b6c
nop_080a0b6c: @ 0x080A0B6C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a0b70
FUN_080a0b70: @ 0x080A0B70
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bls _080A0B7E
	b _080A0D88
_080A0B7E:
	lsls r0, r0, #2
	ldr r1, _080A0B88 @ =_080A0B8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0B88: .4byte _080A0B8C
_080A0B8C: @ jump table
	.4byte _080A0BB4 @ case 0
	.4byte _080A0BD4 @ case 1
	.4byte _080A0C18 @ case 2
	.4byte _080A0C30 @ case 3
	.4byte _080A0C78 @ case 4
	.4byte _080A0CA4 @ case 5
	.4byte _080A0CF4 @ case 6
	.4byte _080A0D02 @ case 7
	.4byte _080A0D36 @ case 8
	.4byte _080A0D40 @ case 9
_080A0BB4:
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A0BF8 @ =sCollisions
	bl SetDDP
	movs r0, #0x80
	str r0, [r4, #0x5c]
	ldr r1, _080A0BFC @ =0x00003701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0BD4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0C00
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xd0
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	bgt _080A0BF4
	b _080A0D88
_080A0BF4:
	b _080A0CE6
	.align 2, 0
_080A0BF8: .4byte sCollisions
_080A0BFC: .4byte 0x00003701
_080A0C00:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080A0C14 @ =0xFFFF9800
	b _080A0CE0
	.align 2, 0
_080A0C14: .4byte 0xFFFF9800
_080A0C18:
	movs r2, #0
	ldr r0, _080A0C54 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x58]
	ldr r0, [r4, #0x58]
	cmp r1, r0
	ble _080A0C28
	movs r2, #1
_080A0C28:
	strb r2, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0C30:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080A0C58
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #8
	adds r0, r0, r2
	cmp r1, r0
	bgt _080A0C50
	b _080A0D88
_080A0C50:
	str r0, [r4, #0x58]
	b _080A0CE8
	.align 2, 0
_080A0C54: .4byte pZero2
_080A0C58:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _080A0C74 @ =0xFFFF7000
	adds r0, r0, r2
	cmp r1, r0
	blt _080A0C70
	b _080A0D88
_080A0C70:
	str r0, [r4, #0x58]
	b _080A0CE8
	.align 2, 0
_080A0C74: .4byte 0xFFFF7000
_080A0C78:
	ldr r2, _080A0CC4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080A0CC8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080A0CCC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	ldr r1, [r4, #0x5c]
	muls r0, r1, r0
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	movs r1, #1
	eors r0, r1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0CA4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0CD0
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xb0
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	ble _080A0D88
	b _080A0CE6
	.align 2, 0
_080A0CC4: .4byte RNG_0202f388
_080A0CC8: .4byte 0x000343FD
_080A0CCC: .4byte 0x00269EC3
_080A0CD0:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080A0CF0 @ =0xFFFFA800
_080A0CE0:
	adds r0, r0, r2
	cmp r1, r0
	bge _080A0D88
_080A0CE6:
	str r0, [r4, #0x54]
_080A0CE8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A0D88
	.align 2, 0
_080A0CF0: .4byte 0xFFFFA800
_080A0CF4:
	ldrb r0, [r4, #0x13]
	movs r1, #1
	eors r0, r1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0D02:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080A0D18
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	cmp r0, r1
	ble _080A0D88
	b _080A0D26
_080A0D18:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	cmp r0, r1
	bge _080A0D88
_080A0D26:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	adds r1, r5, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
	b _080A0D88
_080A0D36:
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0D40:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A0D88
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A0D84 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080A0DB4
	.align 2, 0
_080A0D84: .4byte gProjectileFnTable
_080A0D88:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	adds r0, #0x30
	str r0, [r4, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	ble _080A0D9E
	str r1, [r4, #0x5c]
_080A0D9E:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A0DB6
	ldr r1, _080A0DBC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_080A0DB4:
	str r0, [r4, #0x14]
_080A0DB6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0DBC: .4byte gProjectileFnTable
