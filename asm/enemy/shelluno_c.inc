	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shelluno_080793a0
shelluno_080793a0: @ 0x080793A0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080793B2
	cmp r4, #1
	beq _080793D8
	b _080795B0
_080793B2:
	adds r0, r5, #0
	adds r0, #0xc0
	strb r4, [r0]
	subs r0, #7
	strb r4, [r0]
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807941C @ =0x0836759C
	bl SetDDP
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080793D8:
	ldr r0, [r5, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #4
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r0, #0x10
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080793F4
	str r1, [r5, #0x60]
_080793F4:
	ldr r2, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r2, r2, r3
	str r2, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r4, r2, #0
	ldr r1, _08079420 @ =0xFFFFF400
	adds r6, r0, r1
	cmp r3, #0
	bge _08079424
	adds r4, r4, r1
	adds r0, r4, #0
	adds r1, r6, #0
	bl PushoutToRight2
	b _08079432
	.align 2, 0
_0807941C: .4byte 0x0836759C
_08079420: .4byte 0xFFFFF400
_08079424:
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r4, r4, r3
	adds r0, r4, #0
	adds r1, r6, #0
	bl PushoutToLeft2
_08079432:
	adds r1, r0, #0
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r6, [r5, #0x58]
	adds r4, r0, #0
	adds r1, r6, #0
	bl PushoutToUp2
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	adds r1, r6, #0
	bl PushoutToUp2
	str r0, [sp, #4]
	ldr r3, _08079484 @ =0xFFFFF400
	adds r0, r4, r3
	adds r1, r6, #0
	bl PushoutToUp2
	adds r1, r0, #0
	str r1, [sp, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08079472
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _08079472
	cmp r1, #0
	beq _0807949C
_08079472:
	ldr r2, [sp]
	ldr r0, [sp, #4]
	cmp r2, r0
	bge _08079488
	ldr r1, [sp, #8]
	cmp r2, r1
	bge _08079490
	adds r1, r2, #0
	b _08079490
	.align 2, 0
_08079484: .4byte 0xFFFFF400
_08079488:
	ldr r1, [sp, #8]
	cmp r0, r1
	bge _08079490
	adds r1, r0, #0
_08079490:
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0807949C:
	adds r0, r5, #0
	bl FUN_0807a46c
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r2, r5, #0
	adds r2, #0xc1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080794BE
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080794BE
	b _080795B0
_080794BE:
	ldr r0, _080794EC @ =gOverworld
	ldr r1, _080794F0 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r3, _080794F4 @ =0xFFFFF400
	adds r1, r1, r3
	ldr r0, [r0]
	cmp r0, r1
	bge _080795AC
	ldr r0, _080794F8 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r3, [r5, #0x54]
	adds r4, r0, #0
	cmp r3, r2
	bge _080794FC
	ldrb r1, [r1, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08079514
	movs r1, #0
	b _0807950E
	.align 2, 0
_080794EC: .4byte gOverworld
_080794F0: .4byte 0x0002C00C
_080794F4: .4byte 0xFFFFF400
_080794F8: .4byte pZero2
_080794FC:
	cmp r3, r2
	ble _08079514
	ldrb r1, [r1, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08079514
_0807950E:
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08079514:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bne _080795B0
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	subs r1, r0, r3
	cmp r1, #0
	ble _08079530
	ldr r0, _0807952C @ =0x00004FFF
	cmp r1, r0
	ble _08079538
	b _08079570
	.align 2, 0
_0807952C: .4byte 0x00004FFF
_08079530:
	subs r1, r3, r0
	ldr r0, _08079560 @ =0x00004FFF
	cmp r1, r0
	bgt _08079570
_08079538:
	ldr r2, _08079564 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079568 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0807956C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x64
	bl __umodsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _080795B0
	adds r0, r5, #0
	adds r0, #0xc0
	movs r1, #0x3c
	b _08079596
	.align 2, 0
_08079560: .4byte 0x00004FFF
_08079564: .4byte RNG_0202f388
_08079568: .4byte 0x000343FD
_0807956C: .4byte 0x00269EC3
_08079570:
	ldr r2, _080795A0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080795A4 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _080795A8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc8
	bl __umodsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _080795B0
	adds r0, r5, #0
	adds r0, #0xc0
	movs r1, #0x32
_08079596:
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r2, [r5, #0xe]
	b _080795B0
	.align 2, 0
_080795A0: .4byte RNG_0202f388
_080795A4: .4byte 0x000343FD
_080795A8: .4byte 0x00269EC3
_080795AC:
	movs r0, #0x3c
	strb r0, [r2]
_080795B0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
