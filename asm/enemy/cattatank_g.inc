	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099954
FUN_08099954: @ 0x08099954
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08099964
	cmp r0, #1
	beq _080999A4
	b _08099A88
_08099964:
	ldr r1, _0809998C @ =0x0000D50C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099990 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldr r0, _08099994 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099998
	movs r0, #0x60
	b _0809999C
	.align 2, 0
_0809998C: .4byte 0x0000D50C
_08099990: .4byte sCollisions+(1*24)
_08099994: .4byte pZero2
_08099998:
	movs r0, #0x60
	rsbs r0, r0, #0
_0809999C:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080999A4:
	ldr r1, [r4, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080999C6
	str r1, [r4, #0x60]
_080999C6:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080999E0
	ldr r0, [r4, #0x54]
	ldr r2, _080999DC @ =0xFFFFF600
	b _080999E6
	.align 2, 0
_080999DC: .4byte 0xFFFFF600
_080999E0:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_080999E6:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099A06
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099A06:
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	bne _08099A40
	ldr r0, _08099A3C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099A6E
	movs r2, #1
	movs r0, #0x10
	orrs r0, r3
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
	orrs r0, r5
	b _08099A66
	.align 2, 0
_08099A3C: .4byte pZero2
_08099A40:
	ldr r0, _08099A90 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099A6E
	movs r2, #0
	movs r0, #0xef
	ands r0, r3
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
_08099A66:
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
_08099A6E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099A88
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099A88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099A90: .4byte pZero2

