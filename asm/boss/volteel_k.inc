	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelMode11
volteelMode11: @ 0x08045574
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _080455C6
	movs r0, #0x7f
	bl isSoundPlaying
	cmp r0, #0
	beq _0804558E
	movs r0, #0x7f
	bl StopSound
_0804558E:
	ldr r2, _080455A4 @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _080455AC
	ldr r1, _080455A8 @ =0x0002D024
	b _080455AE
	.align 2, 0
_080455A4: .4byte gOverworld
_080455A8: .4byte 0x0002D024
_080455AC:
	ldr r1, _080455FC @ =0x0002D026
_080455AE:
	adds r0, r2, r1
	strb r5, [r0]
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	movs r0, #0x81
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080455C6:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0804560A
	movs r2, #0
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0xd0
	ldrb r0, [r0]
	adds r1, r0, #0
	cmp r1, #5
	beq _080455E8
	cmp r1, #9
	bne _08045600
_080455E8:
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	b _08045608
	.align 2, 0
_080455FC: .4byte 0x0002D026
_08045600:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	movs r0, #0xff
_08045608:
	strb r0, [r4, #0xf]
_0804560A:
	pop {r4, r5}
	pop {r0}
	bx r0

