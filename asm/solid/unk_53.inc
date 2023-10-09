	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid53_Die
Solid53_Die: @ 0x080DFD94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #0
	beq _080DFDAC
	cmp r0, #1
	beq _080DFE2A
	b _080DFE74
_080DFDAC:
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, r4, #0
	bl FUN_0800d5a8
	movs r0, #4
	adds r1, r4, #0
	bl AppendQuake
	movs r0, #0xe2
	bl PlaySound
	ldr r0, _080DFE84 @ =RNG_0202f388
	mov sl, r0
	ldr r6, _080DFE88 @ =0x00269EC3
	ldr r1, _080DFE8C @ =0x00001FFF
	mov sb, r1
	movs r4, #0xf
	ldr r2, _080DFE90 @ =0xFFFFF000
	mov r8, r2
_080DFDD4:
	mov r7, sl
	ldr r0, [r7]
	ldr r2, _080DFE94 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r2, r1
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	mov r7, sb
	ands r1, r7
	add r1, r8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	ldr r1, _080DFE94 @ =0x000343FD
	muls r2, r1, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r3, r2, #1
	lsrs r2, r2, #0x11
	ands r2, r7
	add r2, r8
	ldr r1, [r5, #0x58]
	adds r1, r1, r2
	ldr r7, _080DFE94 @ =0x000343FD
	adds r2, r3, #0
	muls r2, r7, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r3, r2, #1
	mov r7, sl
	str r3, [r7]
	lsrs r2, r2, #0x11
	movs r3, #3
	ands r2, r3
	bl CreateBubble
	subs r4, #1
	cmp r4, #0
	bge _080DFDD4
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DFE2A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x60]
	ldr r0, _080DFE98 @ =0x000006FF
	cmp r1, r0
	bgt _080DFE3E
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r5, #0x60]
_080DFE3E:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	str r0, [r5, #0x68]
	ldr r0, _080DFE9C @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080DFE74
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080DFEA0 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080DFE74:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DFE84: .4byte RNG_0202f388
_080DFE88: .4byte 0x00269EC3
_080DFE8C: .4byte 0x00001FFF
_080DFE90: .4byte 0xFFFFF000
_080DFE94: .4byte 0x000343FD
_080DFE98: .4byte 0x000006FF
_080DFE9C: .4byte gStageRun+232
_080DFEA0: .4byte gSolidFnTable
