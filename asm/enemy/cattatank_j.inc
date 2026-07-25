	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cattatank_08099e20
cattatank_08099e20: @ 0x08099E20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _08099EAA
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08099EAA
	ldr r2, _08099E6C @ =0x0836A670
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099E84
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E70
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	movs r0, #7
	b _08099E7E
	.align 2, 0
_08099E6C: .4byte sElementCoords
_08099E70:
	cmp r1, #0x30
	bne _08099EAA
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #2
	strb r1, [r0]
	movs r0, #9
_08099E7E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08099EAA
_08099E84:
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E9E
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	b _08099EAA
_08099E9E:
	cmp r1, #0x30
	bne _08099EAA
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
_08099EAA:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0


