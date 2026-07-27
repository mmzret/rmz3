	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08066b3c
FUN_08066b3c: @ 0x08066B3C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08066B4C
	cmp r4, #1
	beq _08066B5E
	b _08066BA8
_08066B4C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066B98 @ =0x08365E24
	bl SetDDP
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066B5E:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08066B6E
	str r1, [r5, #0x60]
_08066B6E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08066BA0
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	ldr r1, _08066B9C @ =0xFFFFF000
	b _08066BA4
	.align 2, 0
_08066B98: .4byte sCollisions+(24*8)
_08066B9C: .4byte 0xFFFFF000
_08066BA0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
_08066BA4:
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08066BA8:
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, [r4]
	bl isKilled
	cmp r0, #0
	beq _08066BD2
	adds r1, r5, #0
	adds r1, #0xbf
	movs r0, #0
	strb r0, [r1]
	str r0, [r4]
	movs r4, #1
	strb r4, [r5, #0xd]
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066BD8 @ =0x08365E0C
	bl SetDDP
	strb r4, [r5, #0xe]
_08066BD2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066BD8: .4byte sCollisions+(24*7)
