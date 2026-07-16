	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099ce4
FUN_08099ce4: @ 0x08099CE4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099CF4
	cmp r5, #1
	beq _08099D08
	b _08099D4E
_08099CF4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099D74 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099D08:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099D18
	str r1, [r4, #0x60]
_08099D18:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099D78 @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099D44
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099D4E
_08099D44:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099D4E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099D6C
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099D6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099D74: .4byte sCollisions+(6*24)
_08099D78: .4byte 0xFFFFF600

