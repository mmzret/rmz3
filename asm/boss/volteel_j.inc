	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelEX
volteelEX: @ 0x08045468
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08045562
	lsls r0, r0, #2
	ldr r1, _0804547C @ =_08045480
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804547C: .4byte _08045480
_08045480: @ jump table
	.4byte _08045498 @ case 0
	.4byte _080454B8 @ case 1
	.4byte _080454D8 @ case 2
	.4byte _080454EC @ case 3
	.4byte _0804552E @ case 4
	.4byte _0804554C @ case 5
_08045498:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	movs r0, #4
	strb r0, [r4, #0x13]
	ldr r1, _080454D0 @ =0x0000A50E
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080454D4 @ =0x083623F0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080454B8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08045562
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08045560
	.align 2, 0
_080454D0: .4byte 0x0000A50E
_080454D4: .4byte sCollisions+(8*24)
_080454D8:
	movs r0, #0x7f
	bl PlaySound
	ldr r1, _08045518 @ =0x0000A50F
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080454EC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08045502
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08045562
_08045502:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08045512
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804551C
_08045512:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08045560
	.align 2, 0
_08045518: .4byte 0x0000A50F
_0804551C:
	adds r0, r4, #0
	bl FUN_080459e8
	movs r0, #0x80
	bl PlaySound
	movs r0, #0x30
	strb r0, [r4, #0x12]
	b _08045562
_0804552E:
	movs r0, #0x7f
	bl StopSound
	ldr r1, _08045568 @ =0x0000A50A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804556C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804554C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08045562
	movs r0, #0
	strb r1, [r4, #0xd]
_08045560:
	strb r0, [r4, #0xe]
_08045562:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08045568: .4byte 0x0000A50A
_0804556C: .4byte sCollisions+(24*1)

