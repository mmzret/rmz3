	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinMode4
blazinMode4: @ 0x0803F284
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0803F290
	b _0803F3E8
_0803F290:
	lsls r0, r0, #2
	ldr r1, _0803F29C @ =_0803F2A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F29C: .4byte _0803F2A0
_0803F2A0: @ jump table
	.4byte _0803F2B8 @ case 0
	.4byte _0803F312 @ case 1
	.4byte _0803F33C @ case 2
	.4byte _0803F364 @ case 3
	.4byte _0803F39C @ case 4
	.4byte _0803F3D2 @ case 5
_0803F2B8:
	ldr r2, _0803F330 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F334 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F338 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r2, #3
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0xca
	ldrb r3, [r0]
	cmp r1, r3
	bne _0803F2DE
	adds r1, #1
	ands r1, r2
_0803F2DE:
	strb r1, [r0]
	adds r0, r4, #0
	bl blazin_080403a0
	movs r1, #0x30
	strb r1, [r4, #0x12]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x30
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #9
	movs r1, #0x30
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x2f
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F312:
	adds r0, r4, #0
	bl setBlazinDirection
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0803F328
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F3E8
_0803F328:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F3E6
	.align 2, 0
_0803F330: .4byte RNG_0202f388
_0803F334: .4byte 0x000343FD
_0803F338: .4byte 0x00269EC3
_0803F33C:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #1
	ldr r2, _0803F394 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F398 @ =gBlazinCollisions+(24*3)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F364:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0803F38E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F3E8
_0803F38E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F3E6
	.align 2, 0
_0803F394: .4byte 0xFFFFA200
_0803F398: .4byte gBlazinCollisions+(24*3)
_0803F39C:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #2
	ldr r3, _0803F3F0 @ =0xFFFFA200
	adds r0, r3, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F3F4 @ =gBlazinCollisions+(24*1)
	bl SetDDP
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0803F3F8 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F3D2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803F3E8
	movs r0, #0
	strb r1, [r4, #0xd]
_0803F3E6:
	strb r0, [r4, #0xe]
_0803F3E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F3F0: .4byte 0xFFFFA200
_0803F3F4: .4byte gBlazinCollisions+(24*1)
_0803F3F8: .4byte 0xFFFFF000

