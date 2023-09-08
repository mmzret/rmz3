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
	bl stopSound
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
	movs r0, #0x44
	strb r0, [r4, #0x12]
	b _08043860
	.align 2, 0
_080437E4: .4byte 0x0000A505
_080437E8: .4byte 0x0000A506
_080437EC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
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

	thumb_func_start nop_080438a4
nop_080438a4: @ 0x080438A4
	movs r0, #1
	bx lr

	thumb_func_start volteelMode0
volteelMode0: @ 0x080438A8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080438B8
	cmp r0, #1
	beq _080438D0
	b _080438EA
_080438B8:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xa5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080438D0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080438EA
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_080438EA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080438f0
FUN_080438f0: @ 0x080438F0
	movs r0, #1
	bx lr

	thumb_func_start volteelMode1
volteelMode1: @ 0x080438F4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08043982
	lsls r0, r0, #2
	ldr r1, _08043908 @ =_0804390C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08043908: .4byte _0804390C
_0804390C: @ jump table
	.4byte _08043924 @ case 0
	.4byte _08043958 @ case 1
	.4byte _08043938 @ case 2
	.4byte _0804394A @ case 3
	.4byte _08043958 @ case 4
	.4byte _08043974 @ case 5
_08043924:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	movs r0, #0x79
	bl PlaySound
	ldr r1, _08043934 @ =0x0000A50E
	b _0804394C
	.align 2, 0
_08043934: .4byte 0x0000A50E
_08043938:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08043968
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043982
	b _08043968
_0804394A:
	ldr r1, _08043970 @ =0x0000A510
_0804394C:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08043958:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08043982
_08043968:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08043982
	.align 2, 0
_08043970: .4byte 0x0000A510
_08043974:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08043982:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043988
FUN_08043988: @ 0x08043988
	movs r0, #1
	bx lr

	thumb_func_start volteelMode2
volteelMode2: @ 0x0804398C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0804399C
	cmp r0, #1
	beq _080439AC
	b _080439C4
_0804399C:
	movs r1, #0xa5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080439AC:
	ldr r0, _080439CC @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080439BE
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080439BE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080439C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080439CC: .4byte gStageRun

	thumb_func_start nop_080439d0
nop_080439d0: @ 0x080439D0
	movs r0, #1
	bx lr

	thumb_func_start volteelNeutral
volteelNeutral: @ 0x080439D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r2, [r6, #0xe]
	cmp r2, #1
	bne _080439E6
	b _08043AEC
_080439E6:
	cmp r2, #1
	bgt _080439F0
	cmp r2, #0
	beq _080439F8
	b _08043D94
_080439F0:
	cmp r2, #2
	bne _080439F6
	b _08043B50
_080439F6:
	b _08043D94
_080439F8:
	adds r3, r6, #0
	adds r3, #0x49
	ldrb r1, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _08043A40
	ldr r0, [r6, #0x54]
	ldr r2, _08043A58 @ =0xFFFFEE00
	adds r0, r0, r2
	bl FUN_0800a05c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _08043A40
	ldr r0, [r6, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	bl FUN_0800a05c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _08043A60
_08043A40:
	movs r1, #0xa5
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08043A5C @ =0x08362348
	bl SetDDP
	b _08043A76
	.align 2, 0
_08043A58: .4byte 0xFFFFEE00
_08043A5C: .4byte 0x08362348
_08043A60:
	ldr r1, _08043AB8 @ =0x0000A501
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl GotoMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08043ABC @ =0x08362378
	bl SetDDP
_08043A76:
	movs r2, #0
	str r2, [r6, #0x60]
	str r2, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r2, [r0, #4]
	str r2, [r6, #0x64]
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _08043AE2
	strb r2, [r6, #0xf]
	movs r3, #1
	strb r3, [r6, #0x13]
	ldr r0, _08043AC0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _08043AC4
	adds r0, r6, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	strb r0, [r6, #0xa]
	b _08043AE6
	.align 2, 0
_08043AB8: .4byte 0x0000A501
_08043ABC: .4byte 0x08362378
_08043AC0: .4byte pZero2
_08043AC4:
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	b _08043AE6
_08043AE2:
	movs r0, #0x1e
	strb r0, [r6, #0x13]
_08043AE6:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08043AEC:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08043B48 @ =0x0000A501
	cmp r0, r1
	bne _08043B38
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r6, #0x68]
	adds r0, #0x10
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08043B18
	str r1, [r6, #0x68]
_08043B18:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r2
	ble _08043B3E
	movs r1, #0xa5
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08043B4C @ =0x08362348
	bl SetDDP
_08043B38:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08043B3E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _08043D94
	.align 2, 0
_08043B48: .4byte 0x0000A501
_08043B4C: .4byte 0x08362348
_08043B50:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r4, _08043C7C @ =0x7FFFFFFF
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08043B7C
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043C80 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043B7C
	adds r4, r1, #0
	adds r5, r4, #0
_08043B7C:
	ldr r0, [r6, #0x54]
	ldr r1, _08043C84 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08043BA0
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043C80 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043BA0
	adds r4, r1, #0
	adds r5, r4, #0
_08043BA0:
	ldr r0, [r6, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08043BC4
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043C80 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043BC4
	adds r5, r1, #0
_08043BC4:
	adds r0, r6, #0
	bl volteel_08045abc
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x68]
	adds r0, #0x10
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08043BE0
	str r1, [r6, #0x68]
_08043BE0:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r5
	ble _08043BEE
	str r5, [r6, #0x58]
_08043BEE:
	ldr r0, [r6, #0x58]
	cmp r0, r5
	beq _08043BF6
	b _08043D94
_08043BF6:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _08043BFE
	b _08043D94
_08043BFE:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08043C0C
	b _08043D94
_08043C0C:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	mov r8, r0
	mov sb, r1
	cmp r3, r2
	bne _08043CF8
	ldr r0, _08043C88 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08043C9C
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043C8C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043C90 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043C94 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043C98 @ =0x080FEE56
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r4, r0
	beq _08043C6C
	b _08043D6A
_08043C6C:
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08043D6A
	.align 2, 0
_08043C7C: .4byte 0x7FFFFFFF
_08043C80: .4byte 0xFFFFB000
_08043C84: .4byte 0xFFFFEE00
_08043C88: .4byte gMission
_08043C8C: .4byte RNG_0202f388
_08043C90: .4byte 0x000343FD
_08043C94: .4byte 0x00269EC3
_08043C98: .4byte 0x080FEE56
_08043C9C:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043CE8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043CEC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043CF0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043CF4 @ =0x080FEE34
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r4, r0
	bne _08043D6A
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08043D6A
	.align 2, 0
_08043CE8: .4byte RNG_0202f388
_08043CEC: .4byte 0x000343FD
_08043CF0: .4byte 0x00269EC3
_08043CF4: .4byte 0x080FEE34
_08043CF8:
	ldr r0, _08043D24 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08043D38
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043D28 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043D2C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043D30 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043D34 @ =0x080FEE56
	b _08043D56
	.align 2, 0
_08043D24: .4byte gMission
_08043D28: .4byte RNG_0202f388
_08043D2C: .4byte 0x000343FD
_08043D30: .4byte 0x00269EC3
_08043D34: .4byte 0x080FEE56
_08043D38:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08043DA0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08043DA4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08043DA8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08043DAC @ =0x080FEE34
_08043D56:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
_08043D6A:
	strb r4, [r6, #0xd]
	strb r7, [r6, #0xe]
	adds r0, r6, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, r6, #0
	adds r1, #0xa4
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _08043D8A
	movs r4, #5
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
_08043D8A:
	mov r1, r8
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	strb r4, [r1]
_08043D94:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043DA0: .4byte RNG_0202f388
_08043DA4: .4byte 0x000343FD
_08043DA8: .4byte 0x00269EC3
_08043DAC: .4byte 0x080FEE34

	thumb_func_start nop_08043db0
nop_08043db0: @ 0x08043DB0
	movs r0, #1
	bx lr

	thumb_func_start volteelMode4
volteelMode4: @ 0x08043DB4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _08043DC0
	b _080440A2
_08043DC0:
	lsls r0, r0, #2
	ldr r1, _08043DCC @ =_08043DD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08043DCC: .4byte _08043DD0
_08043DD0: @ jump table
	.4byte _08043DE8 @ case 0
	.4byte _08043EA4 @ case 1
	.4byte _08043ED4 @ case 2
	.4byte _08043EEC @ case 3
	.4byte _08043FFE @ case 4
	.4byte _0804408C @ case 5
_08043DE8:
	ldr r7, _08043EC4 @ =0x7FFFFFFF
	ldr r0, _08043EC8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, _08043ECC @ =0xFFFFEE00
	adds r6, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r1, r1, r2
	adds r0, r6, #0
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r7
	bge _08043E16
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043E16
	adds r7, r1, #0
_08043E16:
	ldr r0, _08043EC8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r4, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r1, r1, r2
	adds r0, r4, #0
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r7
	bge _08043E46
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043E46
	adds r7, r1, #0
	adds r6, r4, #0
_08043E46:
	ldr r0, _08043EC8 @ =pZero2
	ldr r0, [r0]
	ldr r4, [r0, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, _08043ED0 @ =0xFFFFB000
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r7
	bge _08043E70
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _08043ED0 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08043E70
	adds r7, r1, #0
	adds r6, r4, #0
_08043E70:
	movs r0, #0x50
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x50
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r1, #0xc8
	lsls r1, r1, #8
	ldr r0, [r5, #0x58]
	subs r0, r7, r0
	subs r1, r1, r0
	adds r0, r1, #0
	movs r1, #0x50
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x4f
	strb r0, [r5, #0x12]
	movs r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08043EA4:
	adds r0, r5, #0
	bl volteel_08045abc
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08043EBC
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08043EBC
	b _080440A2
_08043EBC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080440A0
	.align 2, 0
_08043EC4: .4byte 0x7FFFFFFF
_08043EC8: .4byte pZero2
_08043ECC: .4byte 0xFFFFEE00
_08043ED0: .4byte 0xFFFFB000
_08043ED4:
	ldr r1, _08043FE0 @ =0x0000A501
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08043FE4 @ =0x08362378
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08043EEC:
	movs r6, #0
	ldr r2, [r5, #0x60]
	adds r2, #0x10
	str r2, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	bl PushoutToUp2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F28
	adds r1, r4, #0
	cmp r4, #0
	bge _08043F1A
	rsbs r1, r4, #0
_08043F1A:
	ldr r0, _08043FE8 @ =0x000007FF
	cmp r1, r0
	bgt _08043F28
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	movs r6, #1
_08043F28:
	ldr r0, [r5, #0x54]
	ldr r1, _08043FEC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToUp2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F50
	adds r1, r4, #0
	cmp r4, #0
	bge _08043F42
	rsbs r1, r4, #0
_08043F42:
	ldr r0, _08043FE8 @ =0x000007FF
	cmp r1, r0
	bgt _08043F50
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	movs r6, #1
_08043F50:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F74
	adds r1, r4, #0
	cmp r4, #0
	bge _08043F66
	rsbs r1, r4, #0
_08043F66:
	ldr r0, _08043FE8 @ =0x000007FF
	cmp r1, r0
	bgt _08043F74
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	movs r6, #1
_08043F74:
	ldr r0, [r5, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToLeft2
	adds r4, r0, #0
	cmp r4, #0
	beq _08043F8E
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	str r0, [r5, #0x54]
_08043F8E:
	ldr r0, [r5, #0x54]
	ldr r1, _08043FEC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToRight2
	cmp r4, #0
	beq _08043FA4
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	str r0, [r5, #0x54]
_08043FA4:
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08043FF0 @ =0x0000A502
	cmp r0, r1
	beq _08043FC2
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08043FC2
	adds r0, r5, #0
	bl SetMotion
_08043FC2:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08043FD8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043FF4
_08043FD8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080440A0
	.align 2, 0
_08043FE0: .4byte 0x0000A501
_08043FE4: .4byte 0x08362378
_08043FE8: .4byte 0x000007FF
_08043FEC: .4byte 0xFFFFEE00
_08043FF0: .4byte 0x0000A502
_08043FF4:
	cmp r6, #1
	bne _080440A2
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080440A0
_08043FFE:
	ldr r1, _080440A8 @ =0x0000A503
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080440AC @ =0x08362348
	bl SetDDP
	ldr r4, _080440B0 @ =0x7FFFFFFF
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080440B4 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08044036
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _080440B8 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08044036
	adds r4, r1, #0
	str r4, [r5, #0x58]
_08044036:
	ldr r0, [r5, #0x54]
	ldr r1, _080440BC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _080440B4 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _0804405E
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _080440B8 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _0804405E
	adds r4, r1, #0
	str r4, [r5, #0x58]
_0804405E:
	ldr r0, [r5, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _080440B4 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r1, r4
	bge _08044086
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, _080440B8 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	ble _08044086
	str r1, [r5, #0x58]
_08044086:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804408C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _080440A2
	movs r0, #0
	strb r1, [r5, #0xd]
_080440A0:
	strb r0, [r5, #0xe]
_080440A2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080440A8: .4byte 0x0000A503
_080440AC: .4byte 0x08362348
_080440B0: .4byte 0x7FFFFFFF
_080440B4: .4byte 0xFFFFF000
_080440B8: .4byte 0xFFFFB000
_080440BC: .4byte 0xFFFFEE00

	thumb_func_start FUN_080440c0
FUN_080440c0: @ 0x080440C0
	movs r0, #1
	bx lr

	thumb_func_start volteelMode5
volteelMode5: @ 0x080440C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xc
	bls _080440D8
	bl _080449DC
_080440D8:
	lsls r0, r0, #2
	ldr r1, _080440E4 @ =_080440E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080440E4: .4byte _080440E8
_080440E8: @ jump table
	.4byte _0804411C @ case 0
	.4byte _080441E8 @ case 1
	.4byte _08044256 @ case 2
	.4byte _0804426E @ case 3
	.4byte _08044294 @ case 4
	.4byte _0804432A @ case 5
	.4byte _080443A0 @ case 6
	.4byte _080443B2 @ case 7
	.4byte _080443E4 @ case 8
	.4byte _08044426 @ case 9
	.4byte _08044666 @ case 10
	.4byte _080448FA @ case 11
	.4byte _08044964 @ case 12
_0804411C:
	adds r0, r6, #0
	adds r0, #0xdc
	ldr r2, [r6, #0x54]
	ldr r3, [r0]
	subs r1, r2, r3
	adds r7, r0, #0
	cmp r1, #0
	bgt _0804412E
	subs r1, r3, r2
_0804412E:
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r4, [r0]
	subs r3, r2, r4
	adds r5, r0, #0
	cmp r3, #0
	ble _08044142
	cmp r1, r3
	bgt _08044148
	b _0804417E
_08044142:
	subs r0, r4, r2
	cmp r1, r0
	ble _0804417E
_08044148:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804416C
	ldr r1, _08044168 @ =0x0000A507
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _08044170
	.align 2, 0
_08044168: .4byte 0x0000A507
_0804416C:
	ldrb r0, [r6, #0xe]
	adds r0, #2
_08044170:
	strb r0, [r6, #0xe]
	ldr r0, [r7]
	str r0, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xca
	movs r0, #3
	b _080441B0
_0804417E:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080441A0
	ldr r1, _0804419C @ =0x0000A507
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080441A4
	.align 2, 0
_0804419C: .4byte 0x0000A507
_080441A0:
	ldrb r0, [r6, #0xe]
	adds r0, #2
_080441A4:
	strb r0, [r6, #0xe]
	ldr r0, [r5]
	str r0, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xca
	movs r0, #1
_080441B0:
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xd8
	adds r2, r6, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r0, #0x90
	lsls r0, r0, #5
	adds r1, r1, r0
	str r1, [r6, #0x68]
	ldr r0, _080441E0 @ =0xFFFFFE30
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080441E4 @ =0x08362348
	bl SetDDP
	bl _080449DC
	.align 2, 0
_080441E0: .4byte 0xFFFFFE30
_080441E4: .4byte 0x08362348
_080441E8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08044248 @ =0x0000A507
	cmp r0, r1
	beq _08044204
	bl _080449DC
_08044204:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08044212
	bl _080449DC
_08044212:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _0804424C
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08044252
	.align 2, 0
_08044248: .4byte 0x0000A507
_0804424C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_08044252:
	strb r0, [r6, #0xa]
	b _0804495C
_08044256:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804428C @ =0x08362378
	bl SetDDP
	ldr r1, _08044290 @ =0x0000A501
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804426E:
	ldr r1, [r6, #0x60]
	adds r1, #0x10
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r1, #0
	ble _08044284
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08044284:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _080449DC
	.align 2, 0
_0804428C: .4byte 0x08362378
_08044290: .4byte 0x0000A501
_08044294:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	subs r1, r1, r2
	str r1, [r6, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _080442DA
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x60]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x60]
_080442DA:
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xc4
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xcc
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r1]
	movs r4, #0
	movs r0, #0x14
	strb r0, [r6, #0x12]
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x7a
	bl PlaySound
	ldr r1, _08044394 @ =0x0000A511
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804432A:
	ldrb r0, [r6, #0x13]
	adds r4, r6, #0
	adds r4, #0x71
	cmp r0, #0
	bne _0804434A
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _0804434A
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08044398 @ =0x08362348
	bl SetDDP
	movs r0, #1
	strb r0, [r6, #0x13]
_0804434A:
	ldrb r0, [r6, #0x13]
	cmp r0, #1
	bne _08044366
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bne _08044366
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804439C @ =0x08362330
	bl SetDDP
	movs r0, #2
	strb r0, [r6, #0x13]
_08044366:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	ble _0804437E
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
_0804437E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08044390
	b _080449DC
_08044390:
	b _0804495C
	.align 2, 0
_08044394: .4byte 0x0000A511
_08044398: .4byte 0x08362348
_0804439C: .4byte 0x08362330
_080443A0:
	ldr r1, _080443E0 @ =0x0000A512
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080443B2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080443D8
	b _0804492C
_080443D8:
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	b _08044932
	.align 2, 0
_080443E0: .4byte 0x0000A512
_080443E4:
	movs r1, #0
	movs r0, #0x1e
	strb r0, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, #0x28
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	movs r1, #0xef
	ands r1, r0
	ldr r0, [r6, #0x64]
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x68]
	str r0, [r6, #0x58]
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08044468 @ =0x08362330
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08044426:
	movs r4, #0
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _08044436
	b _080449DC
_08044436:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08044442
	b _080449DC
_08044442:
	adds r0, r6, #0
	adds r0, #0xb5
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #9
	bne _08044472
	adds r1, r6, #0
	adds r1, #0xc8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #3
	bhi _0804446C
	movs r4, #1
	b _0804447A
	.align 2, 0
_08044468: .4byte 0x08362330
_0804446C:
	mov r0, sb
	strb r4, [r0]
	b _0804447A
_08044472:
	adds r0, r6, #0
	adds r0, #0xc8
	strb r4, [r0]
	mov sb, r0
_0804447A:
	cmp r4, #1
	bne _0804448E
	movs r4, #9
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
	movs r1, #0xb6
	adds r1, r1, r6
	mov r8, r1
	b _080445DC
_0804448E:
	adds r0, r6, #0
	adds r0, #0xb6
	movs r2, #0
	ldrsb r2, [r7, r2]
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r2, r1
	bne _08044564
	ldr r0, _080444F4 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08044508
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _080444F8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080444FC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08044500 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08044504 @ =0x080FEE34
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r4, r0
	bne _080445D6
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _080445D6
	.align 2, 0
_080444F4: .4byte gMission
_080444F8: .4byte RNG_0202f388
_080444FC: .4byte 0x000343FD
_08044500: .4byte 0x00269EC3
_08044504: .4byte 0x080FEE34
_08044508:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08044554 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044558 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804455C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08044560 @ =0x080FEE56
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r4, r0
	bne _080445D6
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _080445D6
	.align 2, 0
_08044554: .4byte RNG_0202f388
_08044558: .4byte 0x000343FD
_0804455C: .4byte 0x00269EC3
_08044560: .4byte 0x080FEE56
_08044564:
	ldr r0, _08044590 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _080445A4
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08044594 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044598 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804459C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _080445A0 @ =0x080FEE34
	b _080445C2
	.align 2, 0
_08044590: .4byte gMission
_08044594: .4byte RNG_0202f388
_08044598: .4byte 0x000343FD
_0804459C: .4byte 0x00269EC3
_080445A0: .4byte 0x080FEE34
_080445A4:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _0804461C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044620 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08044624 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08044628 @ =0x080FEE56
_080445C2:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
_080445D6:
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
_080445DC:
	adds r0, r6, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, r6, #0
	adds r1, #0xa4
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0804463E
	subs r0, r4, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08044636
	movs r1, #0
	ldrsb r1, [r7, r1]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0804462C
	cmp r1, #5
	bne _0804462C
	movs r4, #9
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
	ldrb r0, [r7]
	strb r0, [r2]
	b _08044644
	.align 2, 0
_0804461C: .4byte RNG_0202f388
_08044620: .4byte 0x000343FD
_08044624: .4byte 0x00269EC3
_08044628: .4byte 0x080FEE56
_0804462C:
	movs r4, #5
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
	b _0804463E
_08044636:
	ldrb r0, [r7]
	mov r2, r8
	strb r0, [r2]
	b _08044644
_0804463E:
	ldrb r0, [r7]
	mov r1, r8
	strb r0, [r1]
_08044644:
	strb r4, [r7]
	cmp r4, #9
	beq _08044650
	movs r0, #0
	mov r2, sb
	strb r0, [r2]
_08044650:
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #5
	beq _0804465A
	b _080449DC
_0804465A:
	movs r1, #0
	strb r0, [r6, #0xd]
	movs r0, #0xa
	strb r0, [r6, #0xe]
	strb r1, [r6, #0xf]
	b _080449DC
_08044666:
	adds r0, r6, #0
	bl InitScalerotMotion1
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
	movs r0, #0
	strb r0, [r5]
	adds r1, r6, #0
	adds r1, #0x50
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _08044724 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044728 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804472C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r7, #3
	ands r0, r7
	adds r1, r0, #0
	cmp r0, #0
	bne _08044734
	adds r4, r6, #0
	adds r4, #0xdc
	adds r3, r6, #0
	adds r3, #0xe0
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xd4
	ldr r0, [r0]
	str r0, [r6, #0x58]
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r6, #0x68]
	adds r1, r6, #0
	adds r1, #0xca
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08044730 @ =0x08362330
	bl SetDDP
	movs r0, #0xc0
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	mov r2, r8
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	b _08044866
	.align 2, 0
_08044724: .4byte RNG_0202f388
_08044728: .4byte 0x000343FD
_0804472C: .4byte 0x00269EC3
_08044730: .4byte 0x08362330
_08044734:
	cmp r0, #1
	bne _080447A4
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r0, [r0]
	str r0, [r6, #0x54]
	adds r3, r6, #0
	adds r3, #0xd8
	adds r4, r6, #0
	adds r4, #0xd4
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xdc
	ldr r0, [r0]
	str r0, [r6, #0x64]
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xca
	strb r7, [r0]
	subs r0, #0x56
	ldr r1, _080447A0 @ =0x08362330
	bl SetDDP
	mov r0, r8
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	b _08044866
	.align 2, 0
_080447A0: .4byte 0x08362330
_080447A4:
	cmp r1, #2
	bne _08044804
	adds r4, r6, #0
	adds r4, #0xdc
	adds r3, r6, #0
	adds r3, #0xe0
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r6, #0x58]
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xd4
	ldr r0, [r0]
	str r0, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xca
	mov r2, r8
	strb r2, [r0]
	subs r0, #0x56
	ldr r1, _08044800 @ =0x08362330
	bl SetDDP
	movs r0, #0x40
	strb r0, [r5]
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	b _08044856
	.align 2, 0
_08044800: .4byte 0x08362330
_08044804:
	adds r0, r6, #0
	adds r0, #0xdc
	ldr r0, [r0]
	str r0, [r6, #0x54]
	adds r3, r6, #0
	adds r3, #0xd8
	adds r4, r6, #0
	adds r4, #0xd4
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r0, [r0]
	str r0, [r6, #0x64]
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xca
	movs r4, #1
	strb r4, [r0]
	subs r0, #0x56
	ldr r1, _08044924 @ =0x08362330
	bl SetDDP
	mov r0, r8
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
_08044856:
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	orrs r0, r1
_08044866:
	strb r0, [r6, #0xa]
	ldr r1, _08044928 @ =0x0000A512
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	subs r1, r1, r2
	str r1, [r6, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _080448B6
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x60]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x60]
_080448B6:
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xc4
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xcc
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r1]
	movs r0, #0x14
	strb r0, [r6, #0x12]
	strb r2, [r6, #0x13]
	movs r0, #0x7a
	bl PlaySound
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080448FA:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804492C
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	b _08044932
	.align 2, 0
_08044924: .4byte 0x08362330
_08044928: .4byte 0x0000A512
_0804492C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08044932:
	strb r0, [r6, #0xa]
	adds r2, r6, #0
	adds r2, #0xc4
	adds r0, r6, #0
	adds r0, #0xcc
	ldr r1, [r2]
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r2]
	cmp r1, #0
	bgt _080449DC
	movs r0, #0
	str r0, [r2]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804495C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080449DC
_0804495C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080449DC
_08044964:
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r6, #0x13]
	adds r5, r6, #0
	adds r5, #0x24
	strb r4, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	movs r1, #0xef
	ands r1, r0
	ldr r0, [r6, #0x64]
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x68]
	str r0, [r6, #0x58]
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080449E8 @ =0x08362330
	bl SetDDP
	movs r0, #9
	strb r0, [r6, #0xe]
	adds r0, r6, #0
	bl InitNonAffineMotion
	strb r4, [r5]
	adds r0, r6, #0
	adds r0, #0x50
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldr r1, _080449EC @ =0x0000A512
	adds r0, r6, #0
	bl SetMotion
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080449DC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080449E8: .4byte 0x08362330
_080449EC: .4byte 0x0000A512

	thumb_func_start FUN_080449f0
FUN_080449f0: @ 0x080449F0
	movs r0, #1
	bx lr

	thumb_func_start volteelMode6
volteelMode6: @ 0x080449F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08044A00
	b _08044CAC
_08044A00:
	lsls r0, r0, #2
	ldr r1, _08044A0C @ =_08044A10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044A0C: .4byte _08044A10
_08044A10: @ jump table
	.4byte _08044A24 @ case 0
	.4byte _08044BA2 @ case 1
	.4byte _08044C4E @ case 2
	.4byte _08044C6E @ case 3
	.4byte _08044CA4 @ case 4
_08044A24:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _08044A58 @ =pZero2
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r3, [r0, #0x54]
	ldr r0, [r1]
	subs r2, r3, r0
	adds r7, r1, #0
	cmp r2, #0
	bgt _08044A42
	subs r2, r0, r3
_08044A42:
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r5, [r0]
	subs r1, r3, r5
	adds r6, r0, #0
	cmp r1, #0
	ble _08044A5C
	cmp r2, r1
	bgt _08044A62
	b _08044A96
	.align 2, 0
_08044A58: .4byte pZero2
_08044A5C:
	subs r0, r5, r3
	cmp r2, r0
	ble _08044A96
_08044A62:
	ldr r0, [r6]
	str r0, [r4, #0x54]
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r4, #0x64]
	adds r2, r4, #0
	adds r2, #0xca
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	subs r2, #0x80
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	b _08044AC2
_08044A96:
	ldr r0, [r7]
	str r0, [r4, #0x54]
	ldr r0, [r6]
	ldr r2, _08044BF0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0xca
	movs r0, #3
	strb r0, [r1]
	subs r1, #0x7e
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
_08044AC2:
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #6
	adds r0, r1, r2
	str r0, [r4, #0x58]
	ldr r0, _08044BF4 @ =0x7FFFFFFF
	str r0, [r4, #0x68]
	ldr r0, [r4, #0x64]
	ldr r2, _08044BF8 @ =0xFFFFD400
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bge _08044B02
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _08044BFC @ =0xFFFFB000
	adds r0, r0, r1
	cmp r2, r0
	ble _08044B02
	str r2, [r4, #0x68]
_08044B02:
	ldr r0, [r4, #0x64]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _08044BFC @ =0xFFFFB000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bge _08044B2C
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _08044BFC @ =0xFFFFB000
	adds r0, r0, r1
	cmp r2, r0
	ble _08044B2C
	str r2, [r4, #0x68]
_08044B2C:
	ldr r0, [r4, #0x64]
	ldr r2, _08044C00 @ =0xFFFFEE00
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _08044BFC @ =0xFFFFB000
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bge _08044B54
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _08044BFC @ =0xFFFFB000
	adds r0, r0, r1
	cmp r2, r0
	ble _08044B54
	str r2, [r4, #0x68]
_08044B54:
	ldr r0, [r4, #0x64]
	movs r1, #0x50
	strb r1, [r4, #0x12]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x50
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r2, #0xc8
	lsls r2, r2, #8
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	subs r2, r2, r0
	adds r0, r2, #0
	movs r1, #0x50
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x4f
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	movs r0, #0x7a
	bl PlaySound
	ldr r1, _08044C04 @ =0x0000A512
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044C08 @ =0x08362330
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044BA2:
	ldr r2, [r4, #0x60]
	adds r2, #0x10
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r5, _08044C0C @ =0x0000A513
	cmp r0, r5
	beq _08044C2C
	ldrb r0, [r4, #0x13]
	ldrb r1, [r4, #0x12]
	lsrs r0, r0, #1
	cmp r1, r0
	bhs _08044C14
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044C10 @ =0x08362498
	bl SetDDP
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetMotion
	b _08044C2C
	.align 2, 0
_08044BF0: .4byte 0xFFFFC000
_08044BF4: .4byte 0x7FFFFFFF
_08044BF8: .4byte 0xFFFFD400
_08044BFC: .4byte 0xFFFFB000
_08044C00: .4byte 0xFFFFEE00
_08044C04: .4byte 0x0000A512
_08044C08: .4byte 0x08362330
_08044C0C: .4byte 0x0000A513
_08044C10: .4byte 0x08362498
_08044C14:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08044C24
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08044C2A
_08044C24:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08044C2A:
	strb r0, [r4, #0xa]
_08044C2C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08044C42
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044C42:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08044CAC
	subs r0, #1
	strb r0, [r4, #0x12]
	b _08044CAC
_08044C4E:
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08044CA0 @ =0x0000A502
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044C6E:
	ldr r2, [r4, #0x60]
	adds r2, #0x10
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08044C98
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08044CAC
_08044C98:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08044CAC
	.align 2, 0
_08044CA0: .4byte 0x0000A502
_08044CA4:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08044CAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044cb4
FUN_08044cb4: @ 0x08044CB4
	movs r0, #1
	bx lr

	thumb_func_start volteelElectricCage
volteelElectricCage: @ 0x08044CB8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xf
	bls _08044CC4
	b _08044EF2
_08044CC4:
	lsls r0, r0, #2
	ldr r1, _08044CD0 @ =_08044CD4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044CD0: .4byte _08044CD4
_08044CD4: @ jump table
	.4byte _08044D14 @ case 0
	.4byte _08044D74 @ case 1
	.4byte _08044D82 @ case 2
	.4byte _08044EF2 @ case 3
	.4byte _08044EF2 @ case 4
	.4byte _08044EF2 @ case 5
	.4byte _08044EF2 @ case 6
	.4byte _08044EF2 @ case 7
	.4byte _08044EF2 @ case 8
	.4byte _08044EF2 @ case 9
	.4byte _08044DDC @ case 10
	.4byte _08044DFC @ case 11
	.4byte _08044E2C @ case 12
	.4byte _08044E78 @ case 13
	.4byte _08044E98 @ case 14
	.4byte _08044EDC @ case 15
_08044D14:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08044D48
	ldr r0, [r4, #0x54]
	movs r1, #0xd8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08044D40 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _08044D44
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044D40: .4byte 0xFFFFF800
_08044D44:
	movs r0, #0xa
	b _08044EF0
_08044D48:
	ldr r0, [r4, #0x54]
	ldr r1, _08044D68 @ =0xFFFFCA00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08044D6C @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _08044D70
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044D68: .4byte 0xFFFFCA00
_08044D6C: .4byte 0xFFFFF800
_08044D70:
	movs r0, #0xa
	b _08044EF0
_08044D74:
	ldr r1, _08044DB8 @ =0x0000A507
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044D82:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08044D94
	b _08044EF2
_08044D94:
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08044DBC
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r2
	b _08044DD6
	.align 2, 0
_08044DB8: .4byte 0x0000A507
_08044DBC:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08044DD6:
	strb r0, [r4, #0xa]
	movs r0, #0xa
	b _08044EF0
_08044DDC:
	movs r0, #0x46
	strb r0, [r4, #0x12]
	ldr r1, _08044E24 @ =0x0000A508
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044E28 @ =0x08362348
	bl SetDDP
	movs r0, #0x12
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044DFC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08044EF2
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08044E1C
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08044EF2
_08044E1C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044E24: .4byte 0x0000A508
_08044E28: .4byte 0x08362348
_08044E2C:
	ldr r1, _08044E54 @ =0x0000A509
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044E58 @ =0x083623A8
	bl SetDDP
	ldr r2, _08044E5C @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _08044E64
	ldr r0, _08044E60 @ =0x0002D024
	b _08044E66
	.align 2, 0
_08044E54: .4byte 0x0000A509
_08044E58: .4byte 0x083623A8
_08044E5C: .4byte gOverworld
_08044E60: .4byte 0x0002D024
_08044E64:
	ldr r0, _08044E94 @ =0x0002D026
_08044E66:
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x7d
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044E78:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08044E8E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08044EF2
_08044E8E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044E94: .4byte 0x0002D026
_08044E98:
	ldr r1, _08044EB8 @ =0x0000A50A
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _08044EBC @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _08044EC4
	ldr r0, _08044EC0 @ =0x0002D024
	b _08044EC6
	.align 2, 0
_08044EB8: .4byte 0x0000A50A
_08044EBC: .4byte gOverworld
_08044EC0: .4byte 0x0002D024
_08044EC4:
	ldr r0, _08044EF8 @ =0x0002D026
_08044EC6:
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044EFC @ =0x08362348
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044EDC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08044EF2
	movs r0, #0
	strb r1, [r4, #0xd]
_08044EF0:
	strb r0, [r4, #0xe]
_08044EF2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08044EF8: .4byte 0x0002D026
_08044EFC: .4byte 0x08362348

	thumb_func_start FUN_08044f00
FUN_08044f00: @ 0x08044F00
	movs r0, #1
	bx lr

	thumb_func_start volteelMode8
volteelMode8: @ 0x08044F04
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _08044F10
	b _080450AE
_08044F10:
	lsls r0, r0, #2
	ldr r1, _08044F1C @ =_08044F20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044F1C: .4byte _08044F20
_08044F20: @ jump table
	.4byte _08044F44 @ case 0
	.4byte _08044F70 @ case 1
	.4byte _08044F94 @ case 2
	.4byte _08044FD8 @ case 3
	.4byte _08044FF0 @ case 4
	.4byte _08045010 @ case 5
	.4byte _08045036 @ case 6
	.4byte _08045080 @ case 7
	.4byte _08045098 @ case 8
_08044F44:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r1, _08044F8C @ =0x0000A50C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08044F90 @ =0x08362348
	bl SetDDP
	movs r0, #0x7b
	bl PlaySound
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r0, #0xb
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08044F70:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08044F82
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08044F82
	b _080450AE
_08044F82:
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08044F8C: .4byte 0x0000A50C
_08044F90: .4byte 0x08362348
_08044F94:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _08044FB6
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08044FB6
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08044FD4 @ =0x08362528
	bl SetDDP
	movs r0, #1
	strb r0, [r5, #0x13]
_08044FB6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08044FCC
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080450AE
_08044FCC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08044FD4: .4byte 0x08362528
_08044FD8:
	ldr r1, _08045008 @ =0x0000A50D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804500C @ =0x08362348
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08044FF0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080450AE
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08045008: .4byte 0x0000A50D
_0804500C: .4byte 0x08362348
_08045010:
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r1, _08045074 @ =0x0000A50B
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08045078 @ =0x08362348
	bl SetDDP
	movs r0, #0x7b
	bl PlaySound
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08045036:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _08045058
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08045058
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804507C @ =0x08362528
	bl SetDDP
	movs r0, #1
	strb r0, [r5, #0x13]
_08045058:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804506E
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080450AE
_0804506E:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080450AC
	.align 2, 0
_08045074: .4byte 0x0000A50B
_08045078: .4byte 0x08362348
_0804507C: .4byte 0x08362528
_08045080:
	ldr r1, _080450B4 @ =0x0000A50D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080450B8 @ =0x08362348
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08045098:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _080450AE
	movs r0, #0
	strb r1, [r5, #0xd]
_080450AC:
	strb r0, [r5, #0xe]
_080450AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080450B4: .4byte 0x0000A50D
_080450B8: .4byte 0x08362348

	thumb_func_start FUN_080450bc
FUN_080450bc: @ 0x080450BC
	movs r0, #1
	bx lr

	thumb_func_start volteelMode9
volteelMode9: @ 0x080450C0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080450CE
	b _08045454
_080450CE:
	lsls r0, r0, #2
	ldr r1, _080450D8 @ =_080450DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080450D8: .4byte _080450DC
_080450DC: @ jump table
	.4byte _080450F4 @ case 0
	.4byte _080452D0 @ case 1
	.4byte _080452EC @ case 2
	.4byte _080453A2 @ case 3
	.4byte _080453C0 @ case 4
	.4byte _080453F6 @ case 5
_080450F4:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r7, #0
	movs r6, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x24
	strb r6, [r0]
	ldr r2, _08045168 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804516C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08045170 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r5, r0, #0x11
	movs r3, #3
	ands r5, r3
	cmp r5, #0
	bne _08045174
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r5, [r0]
	subs r0, #0x7d
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
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	b _0804522E
	.align 2, 0
_08045168: .4byte RNG_0202f388
_0804516C: .4byte 0x000343FD
_08045170: .4byte 0x00269EC3
_08045174:
	cmp r5, #1
	bne _080451E8
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r5, [r0]
	subs r0, #0x7d
	strb r6, [r0]
	subs r2, #0x8a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080451E0 @ =0x0000A514
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080451E4 @ =0x083624C8
	bl SetDDP
	b _080452BE
	.align 2, 0
_080451E0: .4byte 0x0000A514
_080451E4: .4byte 0x083624C8
_080451E8:
	cmp r5, #2
	bne _0804525C
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x4d
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
_0804522E:
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08045254 @ =0x0000A516
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08045258 @ =0x083624F8
	bl SetDDP
	b _080452BE
	.align 2, 0
_08045254: .4byte 0x0000A516
_08045258: .4byte 0x083624F8
_0804525C:
	adds r0, r4, #0
	adds r0, #0xdc
	ldr r0, [r0]
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xca
	strb r3, [r0]
	subs r0, #0x7d
	strb r6, [r0]
	subs r2, #0x8a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080452E4 @ =0x0000A514
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080452E8 @ =0x083624C8
	bl SetDDP
_080452BE:
	strb r5, [r4, #0x13]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	movs r0, #0x7c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080452D0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080452E2
	b _08045454
_080452E2:
	b _080453A8
	.align 2, 0
_080452E4: .4byte 0x0000A514
_080452E8: .4byte 0x083624C8
_080452EC:
	ldr r2, _0804533C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08045340 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08045344 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r3, r0, #0x11
	movs r0, #3
	ands r3, r0
	adds r0, r4, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r3, r0
	bne _08045318
	adds r1, r3, #1
	adds r0, r1, #0
	asrs r3, r0, #2
	lsls r0, r3, #2
	subs r3, r1, r0
_08045318:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	cmp r3, #0
	bne _08045348
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [sp]
	adds r0, r4, #0
	adds r0, #0xd4
	b _0804536E
	.align 2, 0
_0804533C: .4byte RNG_0202f388
_08045340: .4byte 0x000343FD
_08045344: .4byte 0x00269EC3
_08045348:
	cmp r3, #1
	bne _08045352
	adds r0, r4, #0
	adds r0, #0xe0
	b _08045378
_08045352:
	cmp r3, #2
	bne _08045374
	adds r1, r4, #0
	adds r1, #0xdc
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [sp]
	adds r0, r4, #0
	adds r0, #0xd8
_0804536E:
	ldr r0, [r0]
	str r0, [sp, #4]
	b _08045390
_08045374:
	adds r0, r4, #0
	adds r0, #0xdc
_08045378:
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r4, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	str r1, [sp, #4]
_08045390:
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	mov r1, sp
	bl volteel_080bc0b0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080453A2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080453A8:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080453B8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08045454
_080453B8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08045454
_080453C0:
	adds r0, r4, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #0
	bne _080453D4
	ldr r1, _080453D0 @ =0x0000A517
	b _080453DA
	.align 2, 0
_080453D0: .4byte 0x0000A517
_080453D4:
	cmp r0, #1
	bne _080453E8
	ldr r1, _080453E4 @ =0x0000A515
_080453DA:
	adds r0, r4, #0
	bl SetMotion
	b _080453F0
	.align 2, 0
_080453E4: .4byte 0x0000A515
_080453E8:
	ldr r1, _0804545C @ =0x0000A515
	adds r0, r4, #0
	bl SetMotion
_080453F0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080453F6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08045454
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08045460 @ =0x08362330
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x4d
	movs r2, #0
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #5
	strb r0, [r4, #0xd]
	movs r0, #8
	strb r0, [r4, #0xe]
	strb r2, [r4, #0xf]
_08045454:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804545C: .4byte 0x0000A515
_08045460: .4byte 0x08362330

	thumb_func_start FUN_08045464
FUN_08045464: @ 0x08045464
	movs r0, #1
	bx lr

	thumb_func_start volteelEX
volteelEX: @ 0x08045468
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08045562
	lsls r0, r0, #2
	ldr r1, _0804547C @ =_08045480
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804547C: .4byte _08045480
_08045480: @ jump table
	.4byte _08045498 @ case 0
	.4byte _080454B8 @ case 1
	.4byte _080454D8 @ case 2
	.4byte _080454EC @ case 3
	.4byte _0804552E @ case 4
	.4byte _0804554C @ case 5
_08045498:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	movs r0, #4
	strb r0, [r4, #0x13]
	ldr r1, _080454D0 @ =0x0000A50E
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080454D4 @ =0x083623F0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080454B8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08045562
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08045560
	.align 2, 0
_080454D0: .4byte 0x0000A50E
_080454D4: .4byte 0x083623F0
_080454D8:
	movs r0, #0x7f
	bl PlaySound
	ldr r1, _08045518 @ =0x0000A50F
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080454EC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08045502
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08045562
_08045502:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08045512
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804551C
_08045512:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08045560
	.align 2, 0
_08045518: .4byte 0x0000A50F
_0804551C:
	adds r0, r4, #0
	bl FUN_080459e8
	movs r0, #0x80
	bl PlaySound
	movs r0, #0x30
	strb r0, [r4, #0x12]
	b _08045562
_0804552E:
	movs r0, #0x7f
	bl stopSound
	ldr r1, _08045568 @ =0x0000A50A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804556C @ =0x08362348
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804554C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08045562
	movs r0, #0
	strb r1, [r4, #0xd]
_08045560:
	strb r0, [r4, #0xe]
_08045562:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08045568: .4byte 0x0000A50A
_0804556C: .4byte 0x08362348

	thumb_func_start FUN_08045570
FUN_08045570: @ 0x08045570
	movs r0, #1
	bx lr

	thumb_func_start volteelMode11
volteelMode11: @ 0x08045574
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _080455C6
	movs r0, #0x7f
	bl isSoundPlaying
	cmp r0, #0
	beq _0804558E
	movs r0, #0x7f
	bl stopSound
_0804558E:
	ldr r2, _080455A4 @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _080455AC
	ldr r1, _080455A8 @ =0x0002D024
	b _080455AE
	.align 2, 0
_080455A4: .4byte gOverworld
_080455A8: .4byte 0x0002D024
_080455AC:
	ldr r1, _080455FC @ =0x0002D026
_080455AE:
	adds r0, r2, r1
	strb r5, [r0]
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	movs r0, #0x81
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080455C6:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0804560A
	movs r2, #0
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0xd0
	ldrb r0, [r0]
	adds r1, r0, #0
	cmp r1, #5
	beq _080455E8
	cmp r1, #9
	bne _08045600
_080455E8:
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	b _08045608
	.align 2, 0
_080455FC: .4byte 0x0002D026
_08045600:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	movs r0, #0xff
_08045608:
	strb r0, [r4, #0xf]
_0804560A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08045610
FUN_08045610: @ 0x08045610
	movs r0, #1
	bx lr

	thumb_func_start volteelKnockBackDamage
volteelKnockBackDamage: @ 0x08045614
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08045624
	cmp r5, #1
	beq _08045710
	b _080457B2
_08045624:
	movs r0, #0x81
	bl PlaySound
	ldr r1, _08045670 @ =0x0000A504
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x7f
	bl isSoundPlaying
	cmp r0, #0
	beq _08045642
	movs r0, #0x7f
	bl stopSound
_08045642:
	ldr r0, _08045674 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0804567C
	ldr r0, _08045678 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0804569E
	.align 2, 0
_08045670: .4byte 0x0000A504
_08045674: .4byte pZero2
_08045678: .4byte 0xFFFFFE00
_0804567C:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_0804569E:
	adds r5, r2, #0
	adds r0, r4, #0
	adds r0, #0xc0
	movs r3, #0
	str r3, [r0]
	ldr r2, _080456C0 @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _080456C8
	ldr r1, _080456C4 @ =0x0002D024
	b _080456CA
	.align 2, 0
_080456C0: .4byte gOverworld
_080456C4: .4byte 0x0002D024
_080456C8:
	ldr r1, _080457B8 @ =0x0002D026
_080456CA:
	adds r0, r2, r1
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r3, r4, #0
	adds r3, #0x49
	ldrb r1, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, #0x29
	strb r2, [r0]
	ldrb r1, [r5]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r5]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08045710:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08045732
	str r1, [r4, #0x60]
_08045732:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _08045760
	movs r3, #0x90
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r3, _080457BC @ =0xFFFFF800
	adds r1, r2, r3
	bl PushoutToLeft2
	adds r1, r0, #0
	cmp r1, #0
	beq _08045760
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08045760:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _08045782
	ldr r0, [r4, #0x54]
	ldr r1, _080457C0 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080457BC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight2
	adds r1, r0, #0
	cmp r1, #0
	beq _08045782
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08045782:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	beq _08045796
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08045796:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080457A6
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080457B2
_080457A6:
	movs r0, #0
	movs r1, #3
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	movs r0, #0xff
	strb r0, [r4, #0xf]
_080457B2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080457B8: .4byte 0x0002D026
_080457BC: .4byte 0xFFFFF800
_080457C0: .4byte 0xFFFFEE00

	thumb_func_start volteel_080457c4
volteel_080457c4: @ 0x080457C4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	bne _08045864
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08045864
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bne _08045818
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080457F4
	ldr r2, _080457F0 @ =0x08362590
	b _0804581A
	.align 2, 0
_080457F0: .4byte 0x08362590
_080457F4:
	cmp r0, #1
	bne _08045800
	ldr r2, _080457FC @ =0x08362598
	b _0804581A
	.align 2, 0
_080457FC: .4byte 0x08362598
_08045800:
	cmp r0, #2
	bne _0804580C
	ldr r2, _08045808 @ =0x08362588
	b _0804581A
	.align 2, 0
_08045808: .4byte 0x08362588
_0804580C:
	cmp r0, #3
	bne _08045824
	ldr r2, _08045814 @ =0x083625A0
	b _0804581A
	.align 2, 0
_08045814: .4byte 0x083625A0
_08045818:
	ldr r2, _0804585C @ =0x08362570
_0804581A:
	movs r0, #0xd
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
_08045824:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	cmp r0, #0
	beq _08045864
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x30
	bne _08045860
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r2, #0
	strb r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xd1
	strb r0, [r1]
	ldrb r0, [r4, #0xf]
	adds r1, #1
	strb r0, [r1]
	movs r0, #0xb
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _08045864
	.align 2, 0
_0804585C: .4byte 0x08362570
_08045860:
	movs r0, #0
	str r0, [r2]
_08045864:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804586c
FUN_0804586c: @ 0x0804586C
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _08045882
	cmp r0, #0xe
	beq _08045882
	cmp r0, #0xf
	bne _080458C4
_08045882:
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080458A4
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080458C4
_080458A4:
	ldr r0, _080458BC @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080458C4
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080458C0
	movs r0, #0xff
	b _080458C2
	.align 2, 0
_080458BC: .4byte gStageRun
_080458C0:
	movs r0, #0xfe
_080458C2:
	strb r0, [r2, #0x11]
_080458C4:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _08045904
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08045904
	ldr r0, [r2, #4]
	ldr r1, _0804590C @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08045904
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xc
	beq _08045904
	cmp r0, #9
	beq _08045904
	cmp r0, #5
	bne _080458FC
	ldrb r0, [r2, #0xe]
	cmp r0, #4
	bhi _08045904
_080458FC:
	movs r1, #0
	movs r0, #0xc
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08045904:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804590C: .4byte 0x000200FF

	thumb_func_start FUN_08045910
FUN_08045910: @ 0x08045910
	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _08045958
	bl FUN_080459d4
	adds r1, r0, #0
	cmp r1, #0
	beq _0804593C
	movs r2, #0
	ldr r5, _08045938 @ =0x080FEE90
	adds r3, r5, #0
_08045928:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804597C
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _08045928
	b _080459CC
	.align 2, 0
_08045938: .4byte 0x080FEE90
_0804593C:
	movs r2, #0
	ldr r5, _08045954 @ =0x080FEE86
	adds r3, r5, #0
_08045942:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08045986
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _08045942
	b _080459CC
	.align 2, 0
_08045954: .4byte 0x080FEE86
_08045958:
	bl FUN_080459d4
	adds r1, r0, #0
	cmp r1, #0
	beq _0804599A
	movs r2, #0
	ldr r5, _08045978 @ =0x080FEE90
	adds r3, r5, #0
_08045968:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08045990
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _08045968
	b _080459CC
	.align 2, 0
_08045978: .4byte 0x080FEE90
_0804597C:
	adds r0, r2, #1
	movs r1, #3
	bl __modsi3
	b _080459B6
_08045986:
	adds r0, r2, #1
	movs r1, #5
	bl __modsi3
	b _080459B6
_08045990:
	adds r0, r2, #1
	movs r1, #3
	bl __modsi3
	b _080459B6
_0804599A:
	movs r2, #0
	ldr r5, _080459C0 @ =0x080FEE86
	adds r3, r5, #0
_080459A0:
	ldrh r1, [r3]
	cmp r1, r4
	bne _080459C4
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _080459B0
	adds r0, r2, #4
_080459B0:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
_080459B6:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _080459CC
	.align 2, 0
_080459C0: .4byte 0x080FEE86
_080459C4:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _080459A0
_080459CC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080459d4
FUN_080459d4: @ 0x080459D4
	push {lr}
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _080459E0
	movs r0, #0
	b _080459E2
_080459E0:
	movs r0, #1
_080459E2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080459e8
FUN_080459e8: @ 0x080459E8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r2, [r6, #0x54]
	str r2, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _08045A54 @ =0xFFFFC200
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08045A60
	ldr r1, _08045A58 @ =0xFFFFEE00
	adds r0, r2, r1
	str r0, [sp]
	ldr r5, _08045A5C @ =gSineTable
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r4, sp, #8
	str r0, [r4, #4]
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #0x72
	bl FUN_0809f4dc
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	str r0, [r4, #4]
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #0x8e
	bl FUN_0809f4dc
	b _08045AAE
	.align 2, 0
_08045A54: .4byte 0xFFFFC200
_08045A58: .4byte 0xFFFFEE00
_08045A5C: .4byte gSineTable
_08045A60:
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r2, r1
	str r0, [sp]
	ldr r5, _08045AB8 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x64
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	add r4, sp, #8
	adds r0, r5, #0
	adds r0, #0xe4
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r4, #4]
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #0xf2
	bl FUN_0809f4dc
	adds r0, r5, #0
	adds r0, #0x9c
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r4, #4]
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #0xe
	bl FUN_0809f4dc
_08045AAE:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08045AB8: .4byte gSineTable

	thumb_func_start volteel_08045abc
volteel_08045abc: @ 0x08045ABC
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x1e]
	lsls r0, r0, #8
	adds r1, r2, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r3, _08045B00 @ =0x0000A507
	cmp r0, r3
	bne _08045B2C
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08045B62
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08045B04
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08045B1E
	.align 2, 0
_08045B00: .4byte 0x0000A507
_08045B04:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_08045B1E:
	strb r0, [r2, #0xa]
	movs r1, #0xa5
	lsls r1, r1, #8
	adds r0, r2, #0
	bl SetMotion
	b _08045B62
_08045B2C:
	ldr r0, _08045B4C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _08045B50
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08045B62
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
	b _08045B62
	.align 2, 0
_08045B4C: .4byte pZero2
_08045B50:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08045B62
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
_08045B62:
	pop {r0}
	bx r0
	.align 2, 0
