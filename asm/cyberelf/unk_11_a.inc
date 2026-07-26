	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Elf11_Update
Elf11_Update: @ 0x080E50FC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _080E5154 @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	bne _080E5170
	ldr r1, _080E5158 @ =0x00000232
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E5160
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E515C @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080E5170
	.align 2, 0
_080E5154: .4byte gPause
_080E5158: .4byte 0x00000232
_080E515C: .4byte gElfFnTable
_080E5160:
	ldr r0, _080E5178 @ =0x08371E08
	ldrb r1, [r4, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_080E5170:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5178: .4byte sUpdates
