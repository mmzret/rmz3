	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08090ee0
FUN_08090ee0: @ 0x08090EE0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090EEC
	b _0809105C
_08090EEC:
	lsls r0, r0, #2
	ldr r1, _08090EF8 @ =_08090EFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090EF8: .4byte _08090EFC
_08090EFC: @ jump table
	.4byte _08090F20 @ case 0
	.4byte _08090F34 @ case 1
	.4byte _08090F4C @ case 2
	.4byte _08090F8A @ case 3
	.4byte _08090FC2 @ case 4
	.4byte _08090FE4 @ case 5
	.4byte _08091010 @ case 6
	.4byte _08091038 @ case 7
	.4byte _08091046 @ case 8
_08090F20:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090F48 @ =0x08369710
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090F34:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08090F42
	b _0809105C
_08090F42:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
	.align 2, 0
_08090F48: .4byte sCollisions+(11*24)
_08090F4C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090F74 @ =0x083696F8
	bl SetDDP
	ldr r1, _08090F78 @ =0x00007E17
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x60
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #1
	bne _08090F7C
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _08090F7E
	.align 2, 0
_08090F74: .4byte sCollisions+(10*24)
_08090F78: .4byte 0x00007E17
_08090F7C:
	movs r0, #0xcc
_08090F7E:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090F8A:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08090F9A
	str r1, [r4, #0x60]
_08090F9A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809105C
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
_08090FC2:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809105C
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0809105C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
_08090FE4:
	ldr r1, _08091028 @ =0x00007E18
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _0809102C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08091030 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08091034 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091010:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809105C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
	.align 2, 0
_08091028: .4byte 0x00007E18
_0809102C: .4byte RNG_0202f388
_08091030: .4byte 0x000343FD
_08091034: .4byte 0x00269EC3
_08091038:
	ldr r1, _08091064 @ =0x00007E19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091046:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809105C
	movs r0, #0
	strb r0, [r4, #0xd]
_0809105A:
	strb r0, [r4, #0xe]
_0809105C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091064: .4byte 0x00007E19

