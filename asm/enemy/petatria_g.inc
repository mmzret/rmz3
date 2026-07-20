	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08090da8
FUN_08090da8: @ 0x08090DA8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _08090DB4
	b _08090ED0
_08090DB4:
	lsls r0, r0, #2
	ldr r1, _08090DC0 @ =_08090DC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090DC0: .4byte _08090DC4
_08090DC4: @ jump table
	.4byte _08090DE4 @ case 0
	.4byte _08090DF8 @ case 1
	.4byte _08090E10 @ case 2
	.4byte _08090E2C @ case 3
	.4byte _08090E58 @ case 4
	.4byte _08090E84 @ case 5
	.4byte _08090EAC @ case 6
	.4byte _08090EBA @ case 7
_08090DE4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090E0C @ =0x08369710
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090DF8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E0C: .4byte sCollisions+(11*24)
_08090E10:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090E50 @ =0x083696F8
	bl SetDDP
	ldr r1, _08090E54 @ =0x00007E16
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090E2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090ED0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E50: .4byte sCollisions+(10*24)
_08090E54: .4byte 0x00007E16
_08090E58:
	ldr r1, _08090E9C @ =0x00007E18
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _08090EA0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090EA4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08090EA8 @ =0x00269EC3
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
_08090E84:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E9C: .4byte 0x00007E18
_08090EA0: .4byte RNG_0202f388
_08090EA4: .4byte 0x000343FD
_08090EA8: .4byte 0x00269EC3
_08090EAC:
	ldr r1, _08090ED8 @ =0x00007E19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090EBA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090ED0
	movs r0, #0
	strb r0, [r4, #0xd]
_08090ECE:
	strb r0, [r4, #0xe]
_08090ED0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090ED8: .4byte 0x00007E19

