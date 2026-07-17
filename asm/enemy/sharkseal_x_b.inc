	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start sharksealxMode1
sharksealxMode1: @ 0x080707DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080707EC
	cmp r4, #1
	beq _08070872
	b _080708CE
_080707EC:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0807080C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08070810
	adds r0, r5, #0
	adds r0, #0xbc
	strb r4, [r0]
	b _08070818
	.align 2, 0
_0807080C: .4byte pZero2
_08070810:
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
_08070818:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _0807082A
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08070830
_0807082A:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070830:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080708A8 @ =sCollisions
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xb8
	str r4, [r0]
	strb r4, [r5, #0x12]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070872:
	ldrb r0, [r5, #0x12]
	adds r0, #2
	strb r0, [r5, #0x12]
	ldr r1, _080708AC @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #3
	ldr r0, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl forceWaterLanding
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _080708B4
	ldr r0, _080708B0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	b _080708BC
	.align 2, 0
_080708A8: .4byte sCollisions
_080708AC: .4byte gSineTable
_080708B0: .4byte pZero2
_080708B4:
	ldr r0, _080708D4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
_080708BC:
	subs r1, r1, r0
	ldr r0, _080708D8 @ =0x00007FFF
	cmp r1, r0
	bgt _080708CE
	movs r1, #0
	str r1, [r5, #0x60]
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080708CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080708D4: .4byte pZero2
_080708D8: .4byte 0x00007FFF

