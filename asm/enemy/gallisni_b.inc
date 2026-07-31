	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start gallisni_08087118
gallisni_08087118: @ 0x08087118
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _080871AA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _080871AA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08087138
	cmp r0, #1
	beq _08087188
	b _080871AA
_08087138:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080871AA
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0808714E
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808714E:
	ldr r1, _08087180 @ =0x0836868C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08087184 @ =0x083686AC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808717A:
	movs r0, #1
	b _080871AC
	.align 2, 0
_08087180: .4byte 0x0836868C
_08087184: .4byte 0x083686AC
_08087188:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080871A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080871A4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808717A
	strb r5, [r4, #0xf]
	b _080871AA
	.align 2, 0
_080871A4: .4byte 0x00020001
_080871A8:
	strb r0, [r4, #0xf]
_080871AA:
	movs r0, #0
_080871AC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
