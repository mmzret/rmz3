	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelDeath0
volteelDeath0: @ 0x08043540
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08043614
	cmp r0, #1
	bgt _08043554
	cmp r0, #0
	beq _0804355A
	b _08043638
_08043554:
	cmp r0, #2
	beq _08043630
	b _08043638
_0804355A:
	ldr r3, _080435D4 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0804357C
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804357C
	ldr r0, _080435D8 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804357C:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0
	strb r0, [r1]
	adds r1, #0x2c
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x7f
	bl isSoundPlaying
	cmp r0, #0
	beq _080435BE
	movs r0, #0x7f
	bl StopSound
_080435BE:
	ldr r2, _080435DC @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _080435E4
	ldr r1, _080435E0 @ =0x0002D024
	b _080435E6
	.align 2, 0
_080435D4: .4byte gStageRun
_080435D8: .4byte 0x0000FFFE
_080435DC: .4byte gOverworld
_080435E0: .4byte 0x0002D024
_080435E4:
	ldr r1, _0804362C @ =0x0002D026
_080435E6:
	adds r0, r2, r1
	strb r5, [r0]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	movs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08043614:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08043638
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043638
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08043638
	.align 2, 0
_0804362C: .4byte 0x0002D026
_08043630:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08043638:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start volteelDeath1
volteelDeath1: @ 0x08043640
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x19
	bls _0804364E
	b _08043898
_0804364E:
	lsls r0, r0, #2
	ldr r1, _08043658 @ =_0804365C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08043658: .4byte _0804365C
_0804365C: @ jump table
	.4byte _080436C4 @ case 0
	.4byte _08043736 @ case 1
	.4byte _08043748 @ case 2
	.4byte _080437BA @ case 3
	.4byte _080437EC @ case 4
	.4byte _08043898 @ case 5
	.4byte _08043898 @ case 6
	.4byte _08043898 @ case 7
	.4byte _08043898 @ case 8
	.4byte _08043898 @ case 9
	.4byte _08043736 @ case 10
	.4byte _08043802 @ case 11
	.4byte _08043898 @ case 12
	.4byte _08043898 @ case 13
	.4byte _08043898 @ case 14
	.4byte _08043898 @ case 15
	.4byte _08043898 @ case 16
	.4byte _08043898 @ case 17
	.4byte _08043898 @ case 18
	.4byte _08043898 @ case 19
	.4byte _08043814 @ case 20
	.4byte _0804381E @ case 21
	.4byte _0804382C @ case 22
	.4byte _08043854 @ case 23
	.4byte _0804386C @ case 24
	.4byte _08043880 @ case 25
_080436C4:
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08043740 @ =0x0000A504
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08043702
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08043714
_08043702:
	ldr r0, _08043744 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08043714
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _08043716
_08043714:
	movs r0, #0xa
_08043716:
	strb r0, [r4, #0xe]
	movs r1, #0
	str r1, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
_08043736:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08043860
	.align 2, 0
_08043740: .4byte 0x0000A504
_08043744: .4byte gStageRun
_08043748:
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r2, [r4, #0x54]
	str r2, [sp]
	ldr r3, [r4, #0x58]
	str r3, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08043760
	str r2, [sp]
_08043760:
	ldr r1, _08043780 @ =0xFFFFDB00
	adds r0, r3, r1
	str r0, [sp, #4]
	ldrb r0, [r4, #0x11]
	cmp r0, #0xff
	beq _0804378E
	cmp r0, #0xfe
	bne _08043784
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _080437B2
	.align 2, 0
_08043780: .4byte 0xFFFFDB00
_08043784:
	ldr r0, _080437A0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r2
	ble _080437A4
_0804378E:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _080437B2
	.align 2, 0
_080437A0: .4byte pZero2
_080437A4:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_080437B2:
	movs r0, #0x2f
	bl PlaySound
	b _08043860
_080437BA:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r2, _080437E4 @ =0x0000A505
	ldrb r3, [r4, #0xa]
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r4, #0
	bl FUN_0809c3b4
	ldr r1, _080437E8 @ =0x0000A506
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #0x44
	strb r0, [r4, #0x12]
	b _08043860
	.align 2, 0
_080437E4: .4byte 0x0000A505
_080437E8: .4byte 0x0000A506
_080437EC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08043802
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043898
_08043802:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08043898
	movs r0, #0x14
	strb r0, [r4, #0xe]
	b _08043898
_08043814:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804381E:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08043898
	b _08043860
_0804382C:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08043840
	ldr r1, _0804383C @ =0x08362578
	b _08043842
	.align 2, 0
_0804383C: .4byte 0x08362578
_08043840:
	ldr r1, _08043868 @ =0x08362580
_08043842:
	adds r0, r4, #0
	bl CreateBossExplosion
	adds r1, r4, #0
	adds r1, #0xc0
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08043854:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08043898
_08043860:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08043898
	.align 2, 0
_08043868: .4byte 0x08362580
_0804386C:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldr r2, _080438A0 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08043880:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08043890
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043898
_08043890:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_08043898:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080438A0: .4byte gStageRun

