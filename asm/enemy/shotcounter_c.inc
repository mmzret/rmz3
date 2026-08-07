	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shotcounter_0806697c
shotcounter_0806697c: @ 0x0806697C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08066A10
	cmp r5, #1
	bgt _08066990
	cmp r5, #0
	beq _0806699C
	b _08066AC8
_08066990:
	cmp r5, #2
	beq _08066A34
	cmp r5, #3
	bne _0806699A
	b _08066AA8
_0806699A:
	b _08066AC8
_0806699C:
	ldr r1, _080669D0 @ =0x00000404
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	bne _080669D4
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
	b _080669F8
	.align 2, 0
_080669D0: .4byte 0x00000404
_080669D4:
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
_080669F8:
	movs r1, #0
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xb8
	str r1, [r0]
	subs r0, #0x44
	ldr r1, _08066A30 @ =0x08365DDC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08066A10:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08066AC8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08066AC8
	.align 2, 0
_08066A30: .4byte sCollisions+(24*5)
_08066A34:
	ldr r1, _08066A70 @ =0x00000405
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	strb r0, [r2]
	adds r2, r0, #0
	cmp r2, #0
	bne _08066A74
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
	b _08066A9E
	.align 2, 0
_08066A70: .4byte 0x00000405
_08066A74:
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r2, [r0]
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
	str r3, [r4, #0x5c]
_08066A9E:
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08066AA8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08066AC8
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08066AC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

