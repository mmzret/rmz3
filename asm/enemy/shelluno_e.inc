	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shelluno_0807a070
shelluno_0807a070: @ 0x0807A070
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807A080
	cmp r5, #1
	beq _0807A092
	b _0807A0D0
_0807A080:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A0C4 @ =0x083675E4
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A092:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807A0A2
	str r1, [r4, #0x60]
_0807A0A2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807A0C8
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	b _0807A0CE
	.align 2, 0
_0807A0C4: .4byte 0x083675E4
_0807A0C8:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
_0807A0CE:
	str r0, [r4, #0x58]
_0807A0D0:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807A0F0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A0F8 @ =0x083675CC
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807A0F0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A0F8: .4byte 0x083675CC

