	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Wormer_Init
Wormer_Init: @ 0x0804243C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _080424B0 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _080424B4 @ =0x08362260
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _080424C8
	movs r4, #0xd2
	lsls r4, r4, #2
	ldr r1, _080424B8 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080424BC @ =wStaticGraphicTilenums
	adds r1, #0x54
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080424C0 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080424C4 @ =wStaticMotionPalIDs
	adds r0, #0x54
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	b _080424FA
	.align 2, 0
_080424B0: .4byte gBossFnTable
_080424B4: .4byte 0x08362260
_080424B8: .4byte gStaticMotionGraphics
_080424BC: .4byte wStaticGraphicTilenums
_080424C0: .4byte gStaticMotionGraphics+12
_080424C4: .4byte wStaticMotionPalIDs
_080424C8:
	ldr r0, _080425B4 @ =0x085D7DF8
	ldr r1, _080425B8 @ =wStaticGraphicTilenums
	adds r1, #0x80
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080425BC @ =0x085D7E04
	ldr r1, _080425C0 @ =wStaticMotionPalIDs
	adds r1, #0x80
	ldrh r1, [r1]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
_080424FA:
	movs r4, #0xd7
	lsls r4, r4, #2
	ldr r0, _080425C4 @ =gStaticMotionGraphics
	mov r8, r0
	adds r0, r4, r0
	ldr r6, _080425B8 @ =wStaticGraphicTilenums
	adds r1, r6, #0
	adds r1, #0x56
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080425C8 @ =gStaticMotionGraphics+12
	mov sl, r0
	add r4, sl
	ldr r5, _080425C0 @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x56
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xdc
	lsls r4, r4, #2
	add r8, r4
	adds r6, #0x58
	ldrh r1, [r6]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	add r4, sl
	adds r5, #0x58
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	ldrb r1, [r7, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldr r0, _080425CC @ =gSystemSavedataManager
	ldrb r1, [r0, #0x16]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08042598
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	beq _080425A6
_08042598:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080425D4
	ldrb r0, [r7, #0x10]
	cmp r0, #1
	bne _080425D4
_080425A6:
	ldr r1, _080425D0 @ =0x083620F8
	adds r0, r7, #0
	movs r2, #0x50
	bl resetBossData
	b _080425DE
	.align 2, 0
_080425B4: .4byte 0x085D7DF8
_080425B8: .4byte wStaticGraphicTilenums
_080425BC: .4byte 0x085D7E04
_080425C0: .4byte wStaticMotionPalIDs
_080425C4: .4byte gStaticMotionGraphics
_080425C8: .4byte gStaticMotionGraphics+12
_080425CC: .4byte gSystemSavedataManager
_080425D0: .4byte 0x083620F8
_080425D4:
	ldr r1, _08042640 @ =0x083620F8
	adds r0, r7, #0
	movs r2, #0x40
	bl resetBossData
_080425DE:
	ldr r1, _08042644 @ =nop_080423e0
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	adds r1, r7, #0
	adds r1, #0xb4
	str r0, [r1]
	adds r1, #4
	movs r5, #0
	movs r2, #0
	movs r0, #0xc0
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xba
	strb r5, [r0]
	adds r0, #2
	str r2, [r0]
	adds r4, r7, #0
	adds r4, #0xc4
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r4]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r4]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r5, [r0]
	adds r0, r7, #0
	bl Wormer_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042640: .4byte 0x083620F8
_08042644: .4byte nop_080423e0

	thumb_func_start Wormer_Update
Wormer_Update: @ 0x08042648
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r0, [r4]
	cmp r0, #0
	beq _08042662
	bl isKilled
	cmp r0, #0
	beq _08042682
	movs r0, #0
	b _08042680
_08042662:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08042682
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08042682
	ldr r2, _08042704 @ =0x08362264
	movs r0, #0xc
	adds r1, r5, #0
	bl ApplyElementEffect
_08042680:
	str r0, [r4]
_08042682:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080426D2
	ldrb r0, [r5, #0xd]
	cmp r0, #1
	beq _080426D2
	adds r1, r5, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080426D2
	movs r0, #0xc0
	strh r0, [r1]
	ldr r4, _08042708 @ =gStageRun+232
	ldr r2, _0804270C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042710 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042714 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #0xc
	ldr r0, _08042718 @ =0xFFFFF800
	adds r2, r2, r0
	ldr r1, [r4, #0x38]
	adds r1, r1, r2
	adds r0, r5, #0
	bl summonPurpleNerple
_080426D2:
	adds r0, r5, #0
	bl tryKillOrWormer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080426FE
	ldr r1, _0804271C @ =0x083620A0
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r1, _08042720 @ =0x083620CC
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_080426FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042704: .4byte 0x08362264
_08042708: .4byte gStageRun+232
_0804270C: .4byte RNG_0202f388
_08042710: .4byte 0x000343FD
_08042714: .4byte 0x00269EC3
_08042718: .4byte 0xFFFFF800
_0804271C: .4byte 0x083620A0
_08042720: .4byte 0x083620CC

	thumb_func_start Wormer_Die
Wormer_Die: @ 0x08042724
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _08042796
	cmp r0, #1
	ble _0804273C
	b _0804287E
_0804273C:
	cmp r0, #0
	beq _08042742
	b _0804287E
_08042742:
	ldr r3, _08042828 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _08042764
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08042764
	ldr r0, _0804282C @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08042764:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08042830 @ =0x00002B08
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xff
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_08042796:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x12]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080427FA
	ldr r4, [r7, #0x54]
	ldr r0, _08042834 @ =0xFFFFEC00
	adds r4, r4, r0
	str r4, [sp]
	ldr r5, _08042838 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r1, _0804283C @ =0x000343FD
	mov sb, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _08042840 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	adds r0, r0, r4
	str r0, [sp]
	ldr r2, [r7, #0x58]
	mov r0, sb
	muls r0, r6, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsls r0, r0, #1
	lsrs r0, r0, #0x12
	subs r2, r2, r0
	str r2, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
_080427FA:
	ldrb r0, [r7, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804280E
	movs r0, #0x2a
	bl PlaySound
_0804280E:
	movs r0, #0x12
	ldrsb r0, [r7, r0]
	ldrb r2, [r7, #0x12]
	cmp r0, #0
	blt _0804284C
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08042844
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0804284A
	.align 2, 0
_08042828: .4byte gStageRun
_0804282C: .4byte 0x0000FFFE
_08042830: .4byte 0x00002B08
_08042834: .4byte 0xFFFFEC00
_08042838: .4byte RNG_0202f388
_0804283C: .4byte 0x000343FD
_08042840: .4byte 0x00269EC3
_08042844:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804284A:
	strb r0, [r7, #0xa]
_0804284C:
	lsls r0, r2, #0x18
	cmp r0, #0
	bne _0804287E
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08042864
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0xa
	bl TryDropItem
	b _0804286E
_08042864:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0xb
	bl TryDropItem
_0804286E:
	ldr r2, _0804288C @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_0804287E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804288C: .4byte gStageRun

	thumb_func_start nop_08042890
nop_08042890: @ 0x08042890
	bx lr
	.align 2, 0

	thumb_func_start FUN_08042894
FUN_08042894: @ 0x08042894
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0x10]
	cmp r1, #1
	bne _080428BE
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080428BE
	adds r0, r2, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _080428BE
	movs r1, #0
	movs r0, #8
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080428BE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080428c4
FUN_080428c4: @ 0x080428C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080428D4
	cmp r0, #1
	beq _080428F0
	b _0804290A
_080428D4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08042910 @ =0x083620F8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x80
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080428F0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08042904
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08042904:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0804290A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08042910: .4byte 0x083620F8

	thumb_func_start FUN_08042914
FUN_08042914: @ 0x08042914
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	beq _08042952
	cmp r0, #1
	bgt _08042928
	cmp r0, #0
	beq _08042932
	b _0804297C
_08042928:
	cmp r0, #2
	beq _08042966
	cmp r0, #3
	beq _0804296A
	b _0804297C
_08042932:
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	bne _08042944
	adds r3, r2, #0
	adds r3, #0x49
	ldrb r0, [r3]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r3]
_08042944:
	ldrb r0, [r2, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08042952:
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804297C
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
	b _0804297C
_08042966:
	movs r0, #3
	strb r0, [r2, #0xe]
_0804296A:
	ldr r0, _08042980 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0804297C
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0804297C:
	pop {r0}
	bx r0
	.align 2, 0
_08042980: .4byte gStageRun

	thumb_func_start FUN_08042984
FUN_08042984: @ 0x08042984
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08042A6C
	cmp r0, #1
	bgt _08042998
	cmp r0, #0
	beq _080429A6
	b _08042B36
_08042998:
	cmp r0, #2
	bne _0804299E
	b _08042AE8
_0804299E:
	cmp r0, #3
	bne _080429A4
	b _08042AF6
_080429A4:
	b _08042B36
_080429A6:
	ldrb r4, [r5, #0x10]
	cmp r4, #1
	bne _08042A1A
	movs r0, #0x55
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r0, [r0]
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	cmp r1, #0
	beq _080429E4
	subs r0, #0x74
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, _080429E0 @ =0xFFFFA000
	b _08042A06
	.align 2, 0
_080429E0: .4byte 0xFFFFA000
_080429E4:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #7
_08042A06:
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r5, #0
	adds r1, #0xb4
	str r0, [r1]
	b _08042A20
_08042A1A:
	movs r0, #0x55
	bl PlaySound
_08042A20:
	adds r0, r5, #0
	adds r0, #0xba
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0xbb
	movs r4, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r2, [r5, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042AD0 @ =0x08362110
	adds r1, r1, r2
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #0xa8
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, _08042AD4 @ =0xFFFFFEB0
	str r0, [r5, #0x60]
	movs r1, #0xac
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042A6C:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #1
	ands r0, r1
	adds r4, r5, #0
	adds r4, #0xb4
	cmp r0, #0
	bne _08042AB2
	ldr r2, _08042AD8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042ADC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042AE0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _08042AE4 @ =0xFFFFF400
	adds r0, r0, r1
	ldr r3, [r5, #0x54]
	adds r3, r3, r0
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0x22
	ldrb r2, [r0]
	adds r0, r3, #0
	bl CreateGhost35
_08042AB2:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r4]
	cmp r0, r1
	bge _08042AC8
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042AC8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08042B36
	.align 2, 0
_08042AD0: .4byte 0x08362110
_08042AD4: .4byte 0xFFFFFEB0
_08042AD8: .4byte RNG_0202f388
_08042ADC: .4byte 0x000343FD
_08042AE0: .4byte 0x00269EC3
_08042AE4: .4byte 0xFFFFF400
_08042AE8:
	ldr r1, _08042B3C @ =0x00002B01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042AF6:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _08042B40 @ =0x0836226C
	adds r1, r5, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r3, [r5, #0x10]
	lsls r2, r3, #3
	subs r2, r2, r3
	ldrb r1, [r1]
	adds r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08042B44 @ =0x083620F8
	adds r1, r1, r2
	bl SetDDP
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08042B36
	movs r0, #0
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
_08042B36:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042B3C: .4byte 0x00002B01
_08042B40: .4byte 0x0836226C
_08042B44: .4byte 0x083620F8

	thumb_func_start FUN_08042b48
FUN_08042b48: @ 0x08042B48
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08042B54
	b _08042C6E
_08042B54:
	lsls r0, r0, #2
	ldr r1, _08042B60 @ =_08042B64
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042B60: .4byte _08042B64
_08042B64: @ jump table
	.4byte _08042B78 @ case 0
	.4byte _08042B94 @ case 1
	.4byte _08042BDE @ case 2
	.4byte _08042C10 @ case 3
	.4byte _08042C1E @ case 4
_08042B78:
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r2, [r4, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042BBC @ =0x08362170
	adds r1, r1, r2
	bl SetDDP
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042B94:
	ldr r2, _08042BC0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042BC4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042BC8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08042BD0
	ldr r1, _08042BCC @ =0x00002B04
	adds r0, r4, #0
	bl SetMotion
	b _08042BD8
	.align 2, 0
_08042BBC: .4byte 0x08362170
_08042BC0: .4byte RNG_0202f388
_08042BC4: .4byte 0x000343FD
_08042BC8: .4byte 0x00269EC3
_08042BCC: .4byte 0x00002B04
_08042BD0:
	ldr r1, _08042C08 @ =0x00002B03
	adds r0, r4, #0
	bl SetMotion
_08042BD8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042BDE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08042C6E
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08042C0C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08042C6C
	.align 2, 0
_08042C08: .4byte 0x00002B03
_08042C0C:
	movs r0, #1
	b _08042C6C
_08042C10:
	ldr r1, _08042C44 @ =0x00002B05
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042C1E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08042C6E
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08042C4E
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0
	beq _08042C48
	movs r0, #6
	strb r0, [r4, #0xd]
	b _08042C6A
	.align 2, 0
_08042C44: .4byte 0x00002B05
_08042C48:
	movs r0, #4
	strb r0, [r4, #0xd]
	b _08042C6A
_08042C4E:
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _08042C5E
	movs r0, #0xa
	b _08042C60
_08042C5E:
	movs r0, #9
_08042C60:
	strb r0, [r4, #0xd]
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	strb r0, [r2]
_08042C6A:
	movs r0, #0
_08042C6C:
	strb r0, [r4, #0xe]
_08042C6E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042c74
FUN_08042c74: @ 0x08042C74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _08042CB2
	cmp r0, #1
	bgt _08042C88
	cmp r0, #0
	beq _08042C8E
	b _08042D46
_08042C88:
	cmp r0, #2
	beq _08042CFE
	b _08042D46
_08042C8E:
	adds r0, r6, #0
	adds r0, #0x74
	ldrb r2, [r6, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042D20 @ =0x08362170
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _08042D24 @ =0x00002B06
	adds r0, r6, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08042CB2:
	movs r0, #0x18
	strb r0, [r6, #0x13]
	movs r0, #0x2d
	bl PlaySound
	ldr r5, [r6, #0x54]
	ldr r0, _08042D28 @ =0xFFFFDA00
	adds r5, r5, r0
	ldr r4, [r6, #0x58]
	ldr r1, _08042D2C @ =0xFFFFB800
	adds r4, r4, r1
	ldr r2, _08042D30 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042D34 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042D38 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x28
	bl __umodsi3
	adds r2, r0, #0
	adds r2, #0x6c
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r0, #0x22
	ldrb r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateWormerRockDrone
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08042CFE:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08042D40
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08042D3C
	movs r0, #5
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	b _08042D40
	.align 2, 0
_08042D20: .4byte 0x08362170
_08042D24: .4byte 0x00002B06
_08042D28: .4byte 0xFFFFDA00
_08042D2C: .4byte 0xFFFFB800
_08042D30: .4byte RNG_0202f388
_08042D34: .4byte 0x000343FD
_08042D38: .4byte 0x00269EC3
_08042D3C:
	movs r0, #1
	strb r0, [r6, #0xe]
_08042D40:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08042D46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042d4c
FUN_08042d4c: @ 0x08042D4C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08042D5C
	cmp r0, #1
	beq _08042D7C
	b _08042D94
_08042D5C:
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r2, [r4, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042D9C @ =0x08362170
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _08042DA0 @ =0x00002B07
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042D7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08042D94
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08042D94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08042D9C: .4byte 0x08362170
_08042DA0: .4byte 0x00002B07

	thumb_func_start FUN_08042da4
FUN_08042da4: @ 0x08042DA4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _08042DE0
	cmp r4, #1
	bgt _08042DB8
	cmp r4, #0
	beq _08042DBE
	b _08042E4E
_08042DB8:
	cmp r4, #2
	beq _08042E0A
	b _08042E4E
_08042DBE:
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r2, [r5, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042E30 @ =0x08362170
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _08042E34 @ =0x00002B06
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042DE0:
	ldr r0, [r5, #0x54]
	ldr r1, _08042E38 @ =0xFFFFDA00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08042E3C @ =0xFFFFC000
	adds r1, r1, r2
	ldr r4, _08042E40 @ =0x08362278
	ldrb r3, [r5, #0x12]
	lsls r3, r3, #3
	adds r2, r3, r4
	ldr r2, [r2]
	adds r4, #4
	adds r3, r3, r4
	ldr r3, [r3]
	bl FUN_08075c40
	movs r0, #0x10
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042E0A:
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08042E48
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08042E44
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08042E48
	.align 2, 0
_08042E30: .4byte 0x08362170
_08042E34: .4byte 0x00002B06
_08042E38: .4byte 0xFFFFDA00
_08042E3C: .4byte 0xFFFFC000
_08042E40: .4byte 0x08362278
_08042E44:
	movs r0, #1
	strb r0, [r5, #0xe]
_08042E48:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08042E4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042e54
FUN_08042e54: @ 0x08042E54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08042E80
	cmp r0, #1
	bgt _08042E68
	cmp r0, #0
	beq _08042E72
	b _08042F82
_08042E68:
	cmp r0, #2
	beq _08042ED0
	cmp r0, #3
	beq _08042F10
	b _08042F82
_08042E72:
	ldr r1, _08042EC4 @ =0x00002B02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042E80:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08042EC8 @ =0x08362290
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r3, [r4, #0x10]
	lsls r2, r3, #3
	subs r2, r2, r3
	ldrb r1, [r1]
	adds r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08042ECC @ =0x083620F8
	adds r1, r1, r2
	bl SetDDP
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08042F82
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08042F82
	.align 2, 0
_08042EC4: .4byte 0x00002B02
_08042EC8: .4byte 0x08362290
_08042ECC: .4byte 0x083620F8
_08042ED0:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08042EDE
	movs r0, #0x55
	bl PlaySound
	b _08042EE4
_08042EDE:
	movs r0, #0x55
	bl PlaySound
_08042EE4:
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r2, [r4, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042F88 @ =0x08362110
	adds r1, r1, r2
	bl SetDDP
	movs r0, #0xa8
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	movs r1, #0xac
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042F10:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0xb4
	cmp r0, #0
	bne _08042F58
	ldr r2, _08042F8C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042F90 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042F94 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r2, _08042F98 @ =0xFFFFF400
	adds r0, r0, r2
	ldr r3, [r4, #0x54]
	adds r3, r3, r0
	ldr r1, [r5]
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r2, [r0]
	adds r0, r3, #0
	bl CreateGhost35
_08042F58:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r5]
	movs r2, #0xa8
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	ble _08042F7C
	adds r0, r4, #0
	adds r0, #0xba
	strb r6, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	strb r6, [r4, #0xd]
	strb r6, [r4, #0xe]
_08042F7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08042F82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042F88: .4byte 0x08362110
_08042F8C: .4byte RNG_0202f388
_08042F90: .4byte 0x000343FD
_08042F94: .4byte 0x00269EC3
_08042F98: .4byte 0xFFFFF400

	thumb_func_start FUN_08042f9c
FUN_08042f9c: @ 0x08042F9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08042FAC
	cmp r0, #1
	beq _08042FD6
	b _08042FEA
_08042FAC:
	ldr r1, _08042FF0 @ =0x00002B03
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r2, [r4, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042FF4 @ =0x083621A0
	adds r1, r1, r2
	bl SetDDP
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042FD6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08042FEA
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08042FEA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08042FF0: .4byte 0x00002B03
_08042FF4: .4byte 0x083621A0

	thumb_func_start FUN_08042ff8
FUN_08042ff8: @ 0x08042FF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _0804303A
	cmp r0, #1
	bgt _08043014
	cmp r0, #0
	beq _08043022
	b _080431F4
_08043014:
	cmp r0, #2
	bne _0804301A
	b _080431D0
_0804301A:
	cmp r0, #3
	bne _08043020
	b _080431DA
_08043020:
	b _080431F4
_08043022:
	ldr r0, _080431B0 @ =0x00000129
	bl PlaySound
	movs r0, #0x14
	strb r0, [r7, #0x12]
	ldr r1, _080431B4 @ =0x00002B06
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804303A:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804304C
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804304C:
	ldrb r0, [r7, #0x12]
	cmp r0, #0xf
	bhi _08043138
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043138
	ldr r5, _080431B8 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r1, _080431BC @ =0x000343FD
	mov sl, r1
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _080431C0 @ =0x00269EC3
	mov sb, r1
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #0xc
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	subs r0, r4, r0
	movs r2, #0x80
	lsls r2, r2, #5
	mov r8, r2
	add r0, r8
	ldr r4, [r7, #0x54]
	subs r4, r4, r0
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r2, _080431C4 @ =gStageRun+232
	ldr r1, [r2, #0x3c]
	subs r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807b184
	ldr r0, [r5]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #0xc
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	subs r0, r4, r0
	add r8, r0
	ldr r4, [r7, #0x54]
	mov r2, r8
	subs r4, r4, r2
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r2, _080431C4 @ =gStageRun+232
	ldr r1, [r2, #0x3c]
	subs r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807b184
_08043138:
	ldrb r1, [r7, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080431A6
	ldr r4, _080431B8 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080431BC @ =0x000343FD
	mov sl, r1
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _080431C0 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r2, #0xa0
	lsls r2, r2, #5
	mov sb, r2
	mov r1, sb
	bl __umodsi3
	ldr r6, _080431C8 @ =0xFFFFCF00
	adds r0, r0, r6
	ldr r2, [r7, #0x54]
	adds r2, r2, r0
	ldr r1, [r7, #0x58]
	ldr r5, _080431CC @ =0xFFFFBE00
	adds r1, r1, r5
	adds r0, r2, #0
	bl FUN_0807b0d0
	ldr r0, [r4]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	bl __umodsi3
	adds r0, r0, r6
	ldr r2, [r7, #0x54]
	adds r2, r2, r0
	ldr r1, [r7, #0x58]
	adds r1, r1, r5
	adds r0, r2, #0
	bl FUN_0807b0d0
_080431A6:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _080431F4
	.align 2, 0
_080431B0: .4byte 0x00000129
_080431B4: .4byte 0x00002B06
_080431B8: .4byte RNG_0202f388
_080431BC: .4byte 0x000343FD
_080431C0: .4byte 0x00269EC3
_080431C4: .4byte gStageRun+232
_080431C8: .4byte 0xFFFFCF00
_080431CC: .4byte 0xFFFFBE00
_080431D0:
	movs r0, #0x10
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080431DA:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080431EE
	movs r0, #5
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_080431EE:
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080431F4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08043204
FUN_08043204: @ 0x08043204
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #1
	beq _08043236
	cmp r1, #1
	bgt _08043218
	cmp r1, #0
	beq _08043222
	b _080432C4
_08043218:
	cmp r1, #2
	beq _080432A0
	cmp r1, #3
	beq _080432AA
	b _080432C4
_08043222:
	movs r0, #0x28
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldr r1, _08043244 @ =0x00002B06
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08043236:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08043248
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080432C4
	.align 2, 0
_08043244: .4byte 0x00002B06
_08043248:
	ldrb r0, [r5, #0x12]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043288
	movs r0, #0x43
	bl PlaySound
	ldr r0, [r5, #0x54]
	movs r1, #0xb0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08043298 @ =0xFFFFBA00
	adds r1, r1, r2
	ldr r4, _0804329C @ =0x0836229A
	ldrb r3, [r5, #0x13]
	lsls r3, r3, #2
	adds r2, r3, r4
	movs r6, #0
	ldrsh r2, [r2, r6]
	adds r4, #2
	adds r3, r3, r4
	movs r4, #0
	ldrsh r3, [r3, r4]
	bl FUN_0807b124
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
_08043288:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080432C4
	.align 2, 0
_08043298: .4byte 0xFFFFBA00
_0804329C: .4byte 0x0836229A
_080432A0:
	movs r0, #0x20
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080432AA:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080432BE
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080432BE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080432C4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
