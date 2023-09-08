	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid11_Update
Solid11_Update: @ 0x080CDBEC
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDC4E
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080CDC4E
	movs r1, #0
	str r1, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	movs r1, #0x90
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r1, _080CDC54 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Solid11_Die
_080CDC4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CDC54: .4byte gSolidFnTable

	thumb_func_start Solid11_Die
Solid11_Die: @ 0x080CDC58
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #0
	beq _080CDC68
	cmp r0, #1
	beq _080CDC86
	b _080CDCD0
_080CDC68:
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, r4, #0
	bl FUN_0800e370
	movs r0, #4
	adds r1, r4, #0
	bl AppendQuake
	ldr r0, _080CDCD8 @ =0x0000011D
	bl PlaySound
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080CDC86:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x60]
	ldr r0, _080CDCDC @ =0x000006FF
	cmp r1, r0
	bgt _080CDC9A
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r5, #0x60]
_080CDC9A:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	str r0, [r5, #0x68]
	ldr r0, _080CDCE0 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080CDCD0
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080CDCE4 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080CDCD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CDCD8: .4byte 0x0000011D
_080CDCDC: .4byte 0x000006FF
_080CDCE0: .4byte gStageRun+232
_080CDCE4: .4byte gSolidFnTable
