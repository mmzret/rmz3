	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelMode4
volteelMode4: @ 0x08043DB4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _08043DC0
	b _080440A2
_08043DC0:
	lsls r0, r0, #2
	ldr r1, _08043DCC @ =_08043DD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08043DCC: .4byte _08043DD0
_08043DD0: @ jump table
	.4byte _08043DE8 @ case 0
	.4byte _08043EA4 @ case 1
	.4byte _08043ED4 @ case 2
	.4byte _08043EEC @ case 3
	.4byte _08043FFE @ case 4
	.4byte _0804408C @ case 5
_08043DE8:
	ldr r7, _08043EC4 @ =0x7FFFFFFF
	ldr r0, _08043EC8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, _08043ECC @ =0xFFFFEE00
	adds r6, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r1, r1, r2
	adds r0, r6, #0
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r7
	bge _08043E16
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043E16
	adds r7, r1, #0
_08043E16:
	ldr r0, _08043EC8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r4, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r1, r1, r2
	adds r0, r4, #0
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r7
	bge _08043E46
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043E46
	adds r7, r1, #0
	adds r6, r4, #0
_08043E46:
	ldr r0, _08043EC8 @ =pZero2
	ldr r0, [r0]
	ldr r4, [r0, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, _08043ED0 @ =0xFFFFB000
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r7
	bge _08043E70
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043E70
	adds r7, r1, #0
	adds r6, r4, #0
_08043E70:
	movs r0, #0x50
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x50
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r1, #0xc8
	lsls r1, r1, #8
	ldr r0, [r5, #0x58]
	subs r0, r7, r0
	subs r1, r1, r0
	adds r0, r1, #0
	movs r1, #0x50
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x4f
	strb r0, [r5, #0x12]
	movs r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08043EA4:
	adds r0, r5, #0
	bl volteel_08045abc
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08043EBC
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08043EBC
	b _080440A2
_08043EBC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080440A0
	.align 2, 0
_08043EC4: .4byte 0x7FFFFFFF
_08043EC8: .4byte pZero2
_08043ECC: .4byte 0xFFFFEE00
_08043ED0: .4byte 0xFFFFB000
_08043ED4:
	ldr r1, _08043FE0 @ =0x0000A501
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08043FE4 @ =0x08362378
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08043EEC:
	movs r6, #0
	ldr r2, [r5, #0x60]
	adds r2, #0x10
	str r2, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	bl PushoutToUp2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F28
	adds r1, r4, #0
	cmp r4, #0
	bge _08043F1A
	rsbs r1, r4, #0
_08043F1A:
	ldr r0, _08043FE8 @ =0x000007FF
	cmp r1, r0
	bgt _08043F28
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	movs r6, #1
_08043F28:
	ldr r0, [r5, #0x54]
	ldr r1, _08043FEC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToUp2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F50
	adds r1, r4, #0
	cmp r4, #0
	bge _08043F42
	rsbs r1, r4, #0
_08043F42:
	ldr r0, _08043FE8 @ =0x000007FF
	cmp r1, r0
	bgt _08043F50
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	movs r6, #1
_08043F50:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F74
	adds r1, r4, #0
	cmp r4, #0
	bge _08043F66
	rsbs r1, r4, #0
_08043F66:
	ldr r0, _08043FE8 @ =0x000007FF
	cmp r1, r0
	bgt _08043F74
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	movs r6, #1
_08043F74:
	ldr r0, [r5, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToLeft2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F8E
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	str r0, [r5, #0x54]
_08043F8E:
	ldr r0, [r5, #0x54]
	ldr r1, _08043FEC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToRight2
	cmp r4, #0
	beq _08043FA4
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	str r0, [r5, #0x54]
_08043FA4:
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08043FF0 @ =0x0000A502
	cmp r0, r1
	beq _08043FC2
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08043FC2
	adds r0, r5, #0
	bl SetMotion
_08043FC2:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08043FD8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043FF4
_08043FD8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080440A0
	.align 2, 0
_08043FE0: .4byte 0x0000A501
_08043FE4: .4byte sCollisions+(3*24)
_08043FE8: .4byte 0x000007FF
_08043FEC: .4byte 0xFFFFEE00
_08043FF0: .4byte 0x0000A502
_08043FF4:
	cmp r6, #1
	bne _080440A2
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080440A0
_08043FFE:
	ldr r1, _080440A8 @ =0x0000A503
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080440AC @ =sCollisions+(24*1)
	bl SetDDP
	ldr r4, _080440B0 @ =0x7FFFFFFF
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080440B4 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08044036
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _080440B8 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08044036
	adds r4, r1, #0
	str r4, [r5, #0x58]
_08044036:
	ldr r0, [r5, #0x54]
	ldr r1, _080440BC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _080440B4 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _0804405E
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _080440B8 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _0804405E
	adds r4, r1, #0
	str r4, [r5, #0x58]
_0804405E:
	ldr r0, [r5, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _080440B4 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08044086
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _080440B8 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08044086
	str r1, [r5, #0x58]
_08044086:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804408C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _080440A2
	movs r0, #0
	strb r1, [r5, #0xd]
_080440A0:
	strb r0, [r5, #0xe]
_080440A2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080440A8: .4byte 0x0000A503
_080440AC: .4byte sCollisions+(24*1)
_080440B0: .4byte 0x7FFFFFFF
_080440B4: .4byte 0xFFFFF000
_080440B8: .4byte 0xFFFFB000
_080440BC: .4byte 0xFFFFEE00

