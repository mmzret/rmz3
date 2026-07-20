	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelMode8
volteelMode8: @ 0x08044F04
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _08044F10
	b _080450AE
_08044F10:
	lsls r0, r0, #2
	ldr r1, _08044F1C @ =_08044F20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044F1C: .4byte _08044F20
_08044F20: @ jump table
	.4byte _08044F44 @ case 0
	.4byte _08044F70 @ case 1
	.4byte _08044F94 @ case 2
	.4byte _08044FD8 @ case 3
	.4byte _08044FF0 @ case 4
	.4byte _08045010 @ case 5
	.4byte _08045036 @ case 6
	.4byte _08045080 @ case 7
	.4byte _08045098 @ case 8
_08044F44:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r1, _08044F8C @ =0x0000A50C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08044F90 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0x7b
	bl PlaySound
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #0xb
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08044F70:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08044F82
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08044F82
	b _080450AE
_08044F82:
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08044F8C: .4byte 0x0000A50C
_08044F90: .4byte sCollisions+(24*1)
_08044F94:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _08044FB6
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08044FB6
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08044FD4 @ =0x08362528
	bl SetDDP
	movs r0, #1
	strb r0, [r5, #0x13]
_08044FB6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08044FCC
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080450AE
_08044FCC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08044FD4: .4byte sCollisions+(21*24)
_08044FD8:
	ldr r1, _08045008 @ =0x0000A50D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804500C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08044FF0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080450AE
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08045008: .4byte 0x0000A50D
_0804500C: .4byte sCollisions+(24*1)
_08045010:
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r1, _08045074 @ =0x0000A50B
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08045078 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0x7b
	bl PlaySound
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08045036:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _08045058
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08045058
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804507C @ =0x08362528
	bl SetDDP
	movs r0, #1
	strb r0, [r5, #0x13]
_08045058:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804506E
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080450AE
_0804506E:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08045074: .4byte 0x0000A50B
_08045078: .4byte sCollisions+(24*1)
_0804507C: .4byte sCollisions+(21*24)
_08045080:
	ldr r1, _080450B4 @ =0x0000A50D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080450B8 @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08045098:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _080450AE
	movs r0, #0
	strb r1, [r5, #0xd]
_080450AC:
	strb r0, [r5, #0xe]
_080450AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080450B4: .4byte 0x0000A50D
_080450B8: .4byte sCollisions+(24*1)

