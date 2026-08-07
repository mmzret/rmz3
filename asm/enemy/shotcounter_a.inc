	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080665ec
FUN_080665ec: @ 0x080665EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0806666C
	cmp r5, #1
	bgt _08066600
	cmp r5, #0
	beq _08066606
	b _080667A8
_08066600:
	cmp r5, #2
	beq _080666E6
	b _080667A8
_08066606:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	bne _08066638
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
	str r2, [r4, #0x5c]
	ldr r0, _08066634 @ =0xFFFFFF00
	b _08066660
	.align 2, 0
_08066634: .4byte 0xFFFFFF00
_08066638:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	str r5, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
_08066660:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806666C:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bge _08066698
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
	adds r0, #0xbc
	strb r2, [r0]
	b _080666C4
_08066698:
	movs r3, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
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
	adds r0, #0xbc
	strb r3, [r0]
_080666C4:
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xbd
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806671C @ =sCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080666E6:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r5, r4, #0
	adds r5, #0xb8
	cmp r1, #0
	bge _080666F8
	rsbs r1, r1, #0
_080666F8:
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r5]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r5]
	movs r0, #0xa8
	lsls r0, r0, #7
	cmp r1, r0
	ble _08066720
	ldr r0, [r4, #0x64]
	asrs r0, r0, #2
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #5
	b _08066728
	.align 2, 0
_0806671C: .4byte sCollisions
_08066720:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #4
_08066728:
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08066764
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bne _08066792
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _08066760 @ =0xFFFFF000
	adds r1, r1, r2
	bl PushoutToLeft1
	b _0806678C
	.align 2, 0
_08066760: .4byte 0xFFFFF000
_08066764:
	ldr r0, [r4, #0x54]
	ldr r1, _080667B0 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	bne _08066792
	ldr r0, [r4, #0x54]
	ldr r1, _080667B0 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080667B0 @ =0xFFFFF000
	adds r1, r1, r2
	bl PushoutToRight1
_0806678C:
	adds r1, r0, #0
	cmp r1, #0
	beq _08066798
_08066792:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08066798:
	ldr r1, [r5]
	ldr r0, _080667B4 @ =0x00005FFF
	cmp r1, r0
	ble _080667A8
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080667A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080667B0: .4byte 0xFFFFF000
_080667B4: .4byte 0x00005FFF

