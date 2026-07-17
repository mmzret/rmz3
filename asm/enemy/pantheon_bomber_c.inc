	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start pantheon_bomber_080863a4
pantheon_bomber_080863a4: @ 0x080863A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080863B4
	cmp r5, #1
	beq _080863CC
	b _08086402
_080863B4:
	ldr r1, _08086408 @ =0x00006904
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb9
	strb r5, [r0]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080863CC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x70]
	ldr r1, _0808640C @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _080863EA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08086410 @ =0x08368534
	bl SetDDP
_080863EA:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080863FA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08086402
_080863FA:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08086402:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086408: .4byte 0x00006904
_0808640C: .4byte 0x00FFFF00
_08086410: .4byte 0x08368534

