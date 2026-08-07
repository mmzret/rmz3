	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start anubisNeutral
anubisNeutral: @ 0x080505F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0805062E
	cmp r0, #1
	bgt _08050610
	cmp r0, #0
	beq _08050616
	b _080507CC
_08050610:
	cmp r0, #2
	beq _08050638
	b _080507CC
_08050616:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08050668 @ =sCollisions+(1*24)
	bl SetDDP
	ldr r1, _0805066C @ =0x0000AF01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805062E:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050638:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xa4
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0xf
	ble _08050676
	adds r0, r4, #0
	adds r0, #0xce
	ldrb r1, [r0]
	cmp r1, #0
	beq _08050670
	movs r0, #0xa
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _08050676
	.align 2, 0
_08050668: .4byte sCollisions+(1*24)
_0805066C: .4byte 0x0000AF01
_08050670:
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08050676:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805067E
	b _080507C0
_0805067E:
	ldr r0, _080506B4 @ =pZero2
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08050694
	b _080507C0
_08050694:
	adds r0, r2, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080506A2
	b _080507C0
_080506A2:
	adds r2, r4, #0
	adds r2, #0xd2
	ldrb r0, [r2]
	cmp r0, #0
	beq _080506B8
	strb r1, [r2]
	movs r0, #2
	b _080507BC
	.align 2, 0
_080506B4: .4byte pZero2
_080506B8:
	adds r0, r4, #0
	adds r0, #0xcb
	ldrb r0, [r0]
	cmp r0, #2
	bls _0805073C
	ldr r7, _080506D0 @ =u8_ARRAY_083635c0
	ldr r0, _080506D4 @ =gScore
	mov r8, r0
	ldr r6, _080506D8 @ =RNG_0202f388
	adds r5, r4, #0
	adds r5, #0xcf
	b _080506E4
	.align 2, 0
_080506D0: .4byte u8_ARRAY_083635c0
_080506D4: .4byte gScore
_080506D8: .4byte RNG_0202f388
_080506DC:
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _080507AC
_080506E4:
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08050710
	ldr r1, [r6]
	ldr r0, _08050708 @ =0x000343FD
	muls r0, r1, r0
	ldr r2, _0805070C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r1, r0, #0x11
	movs r0, #3
	ands r1, r0
	b _0805072C
	.align 2, 0
_08050708: .4byte 0x000343FD
_0805070C: .4byte 0x00269EC3
_08050710:
	ldr r1, [r6]
	ldr r0, _08050734 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08050738 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0805072C:
	ldrb r0, [r5]
	cmp r0, #0
	bne _080506DC
	b _080507AC
	.align 2, 0
_08050734: .4byte 0x000343FD
_08050738: .4byte 0x00269EC3
_0805073C:
	ldr r2, _0805074C @ =gScore
	mov r8, r2
	ldr r6, _08050750 @ =RNG_0202f388
	adds r5, r4, #0
	adds r5, #0xcf
	ldr r7, _08050754 @ =u8_ARRAY_083635c0+4
	b _08050760
	.align 2, 0
_0805074C: .4byte gScore
_08050750: .4byte RNG_0202f388
_08050754: .4byte u8_ARRAY_083635c0+4
_08050758:
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _080507AC
_08050760:
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08050790
	ldr r1, [r6]
	ldr r0, _08050788 @ =0x000343FD
	muls r0, r1, r0
	ldr r2, _0805078C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _080507A6
	.align 2, 0
_08050788: .4byte 0x000343FD
_0805078C: .4byte 0x00269EC3
_08050790:
	ldr r1, [r6]
	ldr r0, _080507D8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080507DC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r1, r0, #0x11
	movs r0, #3
	ands r1, r0
_080507A6:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08050758
_080507AC:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080507B6
	subs r0, #1
	strb r0, [r5]
_080507B6:
	adds r0, r1, r7
	ldrb r0, [r0]
	movs r1, #0
_080507BC:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080507C0:
	adds r0, r4, #0
	bl FUN_08050090
	adds r0, r4, #0
	bl UpdateEntityAnim
_080507CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080507D8: .4byte 0x000343FD
_080507DC: .4byte 0x00269EC3
