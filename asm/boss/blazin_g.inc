	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinEX
blazinEX: @ 0x0803F9C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xa
	bls _0803F9D0
	b _0803FC64
_0803F9D0:
	lsls r0, r0, #2
	ldr r1, _0803F9DC @ =_0803F9E0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F9DC: .4byte _0803F9E0
_0803F9E0: @ jump table
	.4byte _0803FA0C @ case 0
	.4byte _0803FA5C @ case 1
	.4byte _0803FA7A @ case 2
	.4byte _0803FAA6 @ case 3
	.4byte _0803FAF0 @ case 4
	.4byte _0803FB2C @ case 5
	.4byte _0803FB50 @ case 6
	.4byte _0803FB82 @ case 7
	.4byte _0803FBBC @ case 8
	.4byte _0803FC22 @ case 9
	.4byte _0803FC4E @ case 10
_0803FA0C:
	adds r0, r6, #0
	movs r1, #1
	bl blazin_080403a0
	adds r5, r0, #0
	adds r0, r6, #0
	movs r1, #2
	bl blazin_080403a0
	adds r4, r0, #0
	adds r0, r6, #0
	movs r1, #1
	bl blazin_080403a0
	subs r4, r4, r0
	asrs r4, r4, #1
	adds r5, r5, r4
	movs r0, #0x30
	strb r0, [r6, #0x12]
	ldr r0, [r6, #0x54]
	subs r5, r5, r0
	adds r0, r5, #0
	movs r1, #0x30
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #9
	movs r1, #0x30
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	movs r0, #0x2f
	strb r0, [r6, #0x12]
	movs r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FA5C:
	adds r0, r6, #0
	bl setBlazinDirection
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _0803FA74
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FA74
	b _0803FC64
_0803FA74:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
_0803FA7A:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #1
	ldr r2, _0803FAE8 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803FAEC @ =gBlazinCollisions+(24*3)
	bl SetDDP
	movs r0, #0
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FAA6:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	cmp r0, #0
	ble _0803FABA
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0803FABA
	movs r0, #1
	strb r0, [r6, #0x13]
_0803FABA:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803FAE2
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FAE2
	b _0803FC64
_0803FAE2:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
	.align 2, 0
_0803FAE8: .4byte 0xFFFFA200
_0803FAEC: .4byte gBlazinCollisions+(24*3)
_0803FAF0:
	movs r0, #0x72
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #2
	ldr r2, _0803FB44 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803FB48 @ =gBlazinCollisions+(24*1)
	bl SetDDP
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, _0803FB4C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FB2C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803FB3E
	b _0803FC64
_0803FB3E:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
	.align 2, 0
_0803FB44: .4byte 0xFFFFA200
_0803FB48: .4byte gBlazinCollisions+(24*1)
_0803FB4C: .4byte 0xFFFFF000
_0803FB50:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #8
	ldr r2, _0803FBB4 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803FBB8 @ =gBlazinCollisions+(24*7)
	bl SetDDP
	movs r1, #0
	movs r0, #0xf0
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	strb r1, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FB82:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _0803FC64
	ldrb r0, [r6, #0xf]
	movs r1, #6
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl FUN_080401d4
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
	.align 2, 0
_0803FBB4: .4byte 0xFFFFA200
_0803FBB8: .4byte gBlazinCollisions+(24*7)
_0803FBBC:
	ldrb r1, [r6, #0xf]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0803FBFA
	ldrb r4, [r6, #0x13]
	adds r0, r1, #0
	movs r1, #6
	bl __udivsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl createBlazinEXFireBall
	ldrb r4, [r6, #0x13]
	ldrb r0, [r6, #0xf]
	movs r1, #6
	bl __udivsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0x14
	bl createBlazinEXFireBall
_0803FBFA:
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803FC1C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803FC64
_0803FC1C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
_0803FC22:
	movs r0, #0x72
	bl StopSound
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #9
	ldr r2, _0803FC6C @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xff
	strb r0, [r6, #0x12]
	movs r0, #0
	strb r0, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FC4E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803FC64
	movs r0, #0
	strb r1, [r6, #0xd]
_0803FC62:
	strb r0, [r6, #0xe]
_0803FC64:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803FC6C: .4byte 0xFFFFA200

