	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretista_0804df74
tretista_0804df74: @ 0x0804DF74
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bhi _0804E014
	lsls r0, r0, #2
	ldr r1, _0804DF88 @ =_0804DF8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DF88: .4byte _0804DF8C
_0804DF8C: @ jump table
	.4byte _0804DFAC @ case 0
	.4byte _0804DFE0 @ case 1
	.4byte _0804DFB8 @ case 2
	.4byte _0804DFE0 @ case 3
	.4byte _0804DFC0 @ case 4
	.4byte _0804DFD2 @ case 5
	.4byte _0804DFE0 @ case 6
	.4byte _0804DFFC @ case 7
_0804DFAC:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r1, _0804DFB4 @ =0x0000AB21
	b _0804DFD4
	.align 2, 0
_0804DFB4: .4byte 0x0000AB21
_0804DFB8:
	ldr r1, _0804DFBC @ =0x0000AB22
	b _0804DFD4
	.align 2, 0
_0804DFBC: .4byte 0x0000AB22
_0804DFC0:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804DFF0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E014
	b _0804DFF0
_0804DFD2:
	ldr r1, _0804DFF8 @ =0x0000AB23
_0804DFD4:
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804DFE0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804E014
_0804DFF0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804E014
	.align 2, 0
_0804DFF8: .4byte 0x0000AB23
_0804DFFC:
	adds r0, r5, #0
	adds r0, #0xc8
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_0804E014:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
