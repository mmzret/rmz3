	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080990d8
FUN_080990d8: @ 0x080990D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080990E4
	b _08099256
_080990E4:
	lsls r0, r0, #2
	ldr r1, _080990F0 @ =_080990F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080990F0: .4byte _080990F4
_080990F4: @ jump table
	.4byte _0809910C @ case 0
	.4byte _080991A0 @ case 1
	.4byte _080991F2 @ case 2
	.4byte _0809920A @ case 3
	.4byte _08099228 @ case 4
	.4byte _0809923C @ case 5
_0809910C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809915C @ =0x0000D503
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099160 @ =0x0836A4D8
	bl SetDDP
	ldr r0, _08099164 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099168
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
	b _08099194
	.align 2, 0
_0809915C: .4byte 0x0000D503
_08099160: .4byte sCollisions+(1*24)
_08099164: .4byte pZero2
_08099168:
	movs r3, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r3, [r0]
_08099194:
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080991A0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080991B6
	str r1, [r4, #0x60]
_080991B6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _080991D4
	ldr r1, _080991D0 @ =0xFFFFF800
	b _080991D8
	.align 2, 0
_080991D0: .4byte 0xFFFFF800
_080991D4:
	movs r1, #0x80
	lsls r1, r1, #4
_080991D8:
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099256
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _0809921A
_080991F2:
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08099224 @ =0x0000D504
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809920A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099256
_0809921A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099256
	.align 2, 0
_08099224: .4byte 0x0000D504
_08099228:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809923C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099256
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099256:
	pop {r4, r5}
	pop {r0}
	bx r0

