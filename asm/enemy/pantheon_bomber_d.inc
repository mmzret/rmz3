	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start pantheon_bomber_08086418
pantheon_bomber_08086418: @ 0x08086418
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	bls _08086426
	b _080865C8
_08086426:
	lsls r0, r0, #2
	ldr r1, _08086430 @ =_08086434
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08086430: .4byte _08086434
_08086434: @ jump table
	.4byte _08086460 @ case 0
	.4byte _08086480 @ case 1
	.4byte _080864BC @ case 2
	.4byte _0808659E @ case 3
	.4byte _080864D2 @ case 4
	.4byte _080864E4 @ case 5
	.4byte _08086550 @ case 6
	.4byte _0808659E @ case 7
	.4byte _08086554 @ case 8
	.4byte _0808659E @ case 9
	.4byte _080865C0 @ case 10
_08086460:
	ldr r1, _080864AC @ =0x00006903
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080864B0 @ =0x08368534
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08086480:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x70]
	ldr r1, _080864B4 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _0808649E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080864B8 @ =0x0836854C
	bl SetDDP
_0808649E:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080864AA
	b _080865C8
_080864AA:
	b _080865B4
	.align 2, 0
_080864AC: .4byte 0x00006903
_080864B0: .4byte 0x08368534
_080864B4: .4byte 0x00FFFF00
_080864B8: .4byte 0x0836854C
_080864BC:
	movs r1, #0xd2
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x10
	b _08086596
_080864D2:
	ldr r1, _08086538 @ =0x00006905
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080864E4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0808649E
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0808649E
	ldr r0, [r4, #0x54]
	ldr r1, _0808653C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08086540 @ =0xFFFFF200
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r3, _08086544 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _08086548 @ =0x000343FD
	adds r2, r1, #0
	muls r2, r0, r2
	ldr r0, _0808654C @ =0x00269EC3
	adds r2, r2, r0
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r3]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	mov r0, sp
	mov r1, sp
	bl createPantheonBomb
	movs r0, #1
	strb r0, [r4, #0x12]
	b _0808649E
	.align 2, 0
_08086538: .4byte 0x00006905
_0808653C: .4byte 0xFFFFF800
_08086540: .4byte 0xFFFFF200
_08086544: .4byte RNG_0202f388
_08086548: .4byte 0x000343FD
_0808654C: .4byte 0x00269EC3
_08086550:
	movs r0, #0x12
	b _08086596
_08086554:
	ldr r2, _0808657C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08086580 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08086584 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808658C
	ldr r1, _08086588 @ =0x00006901
	adds r0, r4, #0
	bl SetMotion
	b _08086594
	.align 2, 0
_0808657C: .4byte RNG_0202f388
_08086580: .4byte 0x000343FD
_08086584: .4byte 0x00269EC3
_08086588: .4byte 0x00006901
_0808658C:
	ldr r1, _080865BC @ =0x00006902
	adds r0, r4, #0
	bl SetMotion
_08086594:
	movs r0, #0x40
_08086596:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808659E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080865B4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080865C8
_080865B4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080865C8
	.align 2, 0
_080865BC: .4byte 0x00006902
_080865C0:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080865C8:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

