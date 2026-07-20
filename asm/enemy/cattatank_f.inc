	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099740
FUN_08099740: @ 0x08099740
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0809974C
	b _08099948
_0809974C:
	lsls r0, r0, #2
	ldr r1, _08099758 @ =_0809975C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099758: .4byte _0809975C
_0809975C: @ jump table
	.4byte _08099778 @ case 0
	.4byte _08099794 @ case 1
	.4byte _080997A4 @ case 2
	.4byte _080997C4 @ case 3
	.4byte _08099858 @ case 4
	.4byte _08099878 @ case 5
	.4byte _0809990C @ case 6
_08099778:
	ldr r1, _0809979C @ =0x0000D507
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080997A0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099794:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080998E6
	.align 2, 0
_0809979C: .4byte 0x0000D507
_080997A0: .4byte sCollisions+(1*24)
_080997A4:
	ldr r1, _08099844 @ =0x0000D508
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099848 @ =0x0836A520
	bl SetDDP
	movs r1, #0
	movs r0, #0x32
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080997C4:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080997E4
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080997E4
	movs r0, #0x52
	bl PlaySound
_080997E4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #4
	bne _0809980C
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0809980C
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809984C @ =0x0836A568
	bl SetDDP
_0809980C:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bne _08099828
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _08099828
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099850 @ =0x0836A5B0
	bl SetDDP
_08099828:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099854 @ =0x0836A5F8
	b _080998D8
	.align 2, 0
_08099844: .4byte 0x0000D508
_08099848: .4byte sCollisions+(4*24)
_0809984C: .4byte sCollisions+(7*24)
_08099850: .4byte sCollisions+(10*24)
_08099854: .4byte sCollisions+(13*24)
_08099858:
	ldr r1, _080998FC @ =0x0000D509
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099900 @ =0x0836A5B0
	bl SetDDP
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099878:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08099898
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08099898
	movs r0, #0x52
	bl PlaySound
_08099898:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #1
	bne _080998C0
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080998C0
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099904 @ =0x0836A568
	bl SetDDP
_080998C0:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099908 @ =0x0836A520
_080998D8:
	bl SetDDP
_080998DC:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099948
_080998E6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099948
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099948
	.align 2, 0
_080998FC: .4byte 0x0000D509
_08099900: .4byte sCollisions+(10*24)
_08099904: .4byte sCollisions+(7*24)
_08099908: .4byte sCollisions+(4*24)
_0809990C:
	ldr r0, _08099924 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0809992C
	ldr r0, _08099928 @ =0x000039FF
	cmp r2, r0
	ble _08099934
	b _08099940
	.align 2, 0
_08099924: .4byte pZero2
_08099928: .4byte 0x000039FF
_0809992C:
	subs r1, r1, r0
	ldr r0, _0809993C @ =0x000039FF
	cmp r1, r0
	bgt _08099940
_08099934:
	movs r1, #0
	movs r0, #3
	b _08099944
	.align 2, 0
_0809993C: .4byte 0x000039FF
_08099940:
	movs r1, #0
	movs r0, #2
_08099944:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099948:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

