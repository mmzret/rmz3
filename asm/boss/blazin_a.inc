	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinMode1
blazinMode1: @ 0x0803EE90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _0803EF5E
	lsls r0, r0, #2
	ldr r1, _0803EEA4 @ =_0803EEA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803EEA4: .4byte _0803EEA8
_0803EEA8: @ jump table
	.4byte _0803EEC0 @ case 0
	.4byte _0803EEE8 @ case 1
	.4byte _0803EF32 @ case 2
	.4byte _0803EF00 @ case 3
	.4byte _0803EF22 @ case 4
	.4byte _0803EF50 @ case 5
_0803EEC0:
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x27
	ldr r2, _0803EEFC @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x73
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803EEE8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EF5E
	b _0803EF42
	.align 2, 0
_0803EEFC: .4byte 0xFFFFA200
_0803EF00:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x28
	ldr r2, _0803EF4C @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803EF22:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EF5E
_0803EF32:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0803EF42
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EF5E
_0803EF42:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0803EF5E
	.align 2, 0
_0803EF4C: .4byte 0xFFFFA200
_0803EF50:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0803EF5E:
	pop {r4}
	pop {r0}
	bx r0

