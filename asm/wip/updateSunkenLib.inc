	push {r4, lr}
	ldr r2, _08013520 @ =gOverworld
	ldr r1, _08013524 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xd
	bne _0801352C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _0801352C
	ldr r3, _08013528 @ =0x0002D028
	adds r2, r2, r3
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08013510
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x94
	movs r1, #0
	bl LoadBlink
	movs r0, #0x95
	movs r1, #0
	bl LoadBlink
_08013510:
	movs r0, #0x94
	bl GetBlinkMotionState
	movs r0, #0x95
	bl GetBlinkMotionState
	b _0801354E
	.align 2, 0
_08013520: .4byte gOverworld
_08013524: .4byte 0x000007D4
_08013528: .4byte 0x0002D028
_0801352C:
	ldr r0, _08013588 @ =gOverworld
	ldr r1, _0801358C @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801354E
	movs r0, #1
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x94
	bl ClearBlink
	movs r0, #0x95
	bl ClearBlink
_0801354E:
	ldr r2, _08013588 @ =gOverworld
	ldr r3, _08013590 @ =0x000007D6
	adds r0, r2, r3
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xd
	bne _08013594
	movs r0, #0xff
	ands r0, r1
	cmp r0, #5
	bne _08013594
	ldr r0, _0801358C @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08013580
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x99
	movs r1, #0
	bl LoadBlink
_08013580:
	movs r0, #0x99
	bl GetBlinkMotionState
	b _080135B0
	.align 2, 0
_08013588: .4byte gOverworld
_0801358C: .4byte 0x0002D028
_08013590: .4byte 0x000007D6
_08013594:
	ldr r0, _080135F0 @ =gOverworld
	ldr r1, _080135F4 @ =0x0002D028
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080135B0
	movs r0, #2
	eors r0, r1
	strb r0, [r2]
	movs r0, #0x99
	bl ClearBlink
_080135B0:
	movs r0, #0x96
	bl GetBlinkMotionState
	ldr r2, _080135F0 @ =gOverworld
	ldr r3, _080135F8 @ =0x0002D029
	adds r4, r2, r3
	ldrb r1, [r4]
	cmp r1, #0
	bne _08013632
	ldr r0, _080135FC @ =0x0002D02A
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, #0
	bne _0801360C
	ldr r1, _08013600 @ =0x0002D02C
	adds r2, r2, r1
	ldr r1, [r2]
	ldr r0, _08013604 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013608 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	adds r0, #1
	strb r0, [r3]
	movs r0, #8
	b _08013630
	.align 2, 0
_080135F0: .4byte gOverworld
_080135F4: .4byte 0x0002D028
_080135F8: .4byte 0x0002D029
_080135FC: .4byte 0x0002D02A
_08013600: .4byte 0x0002D02C
_08013604: .4byte 0x000343FD
_08013608: .4byte 0x00269EC3
_0801360C:
	strb r1, [r3]
	ldr r3, _08013678 @ =0x0002D02C
	adds r2, r2, r3
	ldr r1, [r2]
	ldr r0, _0801367C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013680 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x3a
	bl __umodsi3
	movs r1, #0xf8
	ands r0, r1
	adds r0, #7
_08013630:
	strb r0, [r4]
_08013632:
	ldr r2, _08013684 @ =gOverworld
	ldr r3, _08013688 @ =0x0002D029
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, _0801368C @ =0x0002D032
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08013690 @ =0x0002C00C
	adds r2, r2, r1
	ldr r1, _08013694 @ =gSineTable
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x8e
	lsls r1, r1, #0xa
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _08013698 @ =gBlendRegBuffer
	ldr r0, _0801369C @ =0x00000C04
	strh r0, [r1, #2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013678: .4byte 0x0002D02C
_0801367C: .4byte 0x000343FD
_08013680: .4byte 0x00269EC3
_08013684: .4byte gOverworld
_08013688: .4byte 0x0002D029
_0801368C: .4byte 0x0002D032
_08013690: .4byte 0x0002C00C
_08013694: .4byte gSineTable
_08013698: .4byte gBlendRegBuffer
_0801369C: .4byte 0x00000C04
