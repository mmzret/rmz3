	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099d88
FUN_08099d88: @ 0x08099D88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099D98
	cmp r5, #1
	beq _08099DAC
	b _08099DF2
_08099D98:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099E18 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099DAC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099DBC
	str r1, [r4, #0x60]
_08099DBC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099E1C @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099DE8
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099DF2
_08099DE8:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099DF2:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099E10
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099E10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099E18: .4byte sCollisions+(6*24)
_08099E1C: .4byte 0xFFFFF600
