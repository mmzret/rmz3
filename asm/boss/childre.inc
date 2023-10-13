	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080404e4
FUN_080404e4: @ 0x080404E4
	push {r4, lr}
	ldr r1, [r0, #0xc]
	ldr r3, [r1, #0x2c]
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08040516
	adds r1, r2, #0
	adds r1, #0xc8
	ldr r0, [r3, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r3, #0x58]
	str r0, [r1]
	movs r4, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r3, #0x54]
	cmp r1, r0
	bge _08040510
	movs r4, #1
_08040510:
	adds r0, r2, #0
	adds r0, #0xc6
	strb r4, [r0]
_08040516:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start tryKillChildre
tryKillChildre: @ 0x0804051C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0804053C
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08040588
_0804053C:
	ldr r0, _08040574 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08040588
	movs r0, #0x6e
	bl PlaySound
	ldr r1, _08040578 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0804057C
	movs r0, #1
	strb r0, [r4, #0xd]
	b _0804057E
	.align 2, 0
_08040574: .4byte gStageRun
_08040578: .4byte gBossFnTable
_0804057C:
	strb r1, [r4, #0xd]
_0804057E:
	adds r0, r4, #0
	bl Childre_Die
	movs r0, #1
	b _0804058A
_08040588:
	movs r0, #0
_0804058A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Childre_Init
Childre_Init: @ 0x08040590
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _080406FC @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _08040700 @ =0x08362060
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _08040704 @ =0x08361EAC
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
	ldr r1, _08040708 @ =FUN_080404e4
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	ldrb r0, [r7, #0x10]
	str r0, [sp]
	cmp r0, #0
	bne _080406E4
	movs r4, #0xb4
	lsls r4, r4, #2
	ldr r5, _0804070C @ =gStaticMotionGraphics
	adds r0, r4, r5
	ldr r1, _08040710 @ =wStaticGraphicTilenums
	mov sb, r1
	adds r1, #0x48
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08040714 @ =gStaticMotionGraphics+12
	mov r8, r0
	add r4, r8
	ldr r1, _08040718 @ =wStaticMotionPalIDs
	mov sl, r1
	mov r0, sl
	adds r0, #0x48
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xb9
	lsls r4, r4, #2
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0x4a
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0x4a
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r5, r4, r5
	mov r0, sb
	adds r0, #0x4c
	ldrh r1, [r0]
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0x4c
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r1, [sp]
	str r1, [r0]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xc0
	str r0, [r1]
	adds r4, r7, #0
	adds r4, #0xbc
	ldr r0, [r7, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #8
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r4]
	adds r2, r7, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	movs r1, #0xff
	orrs r0, r1
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xc5
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
_080406E4:
	adds r0, r7, #0
	bl Childre_Main
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080406FC: .4byte gBossFnTable
_08040700: .4byte 0x08362060
_08040704: .4byte 0x08361EAC
_08040708: .4byte FUN_080404e4
_0804070C: .4byte gStaticMotionGraphics
_08040710: .4byte wStaticGraphicTilenums
_08040714: .4byte gStaticMotionGraphics+12
_08040718: .4byte wStaticMotionPalIDs

	thumb_func_start Childre_Main
Childre_Main: @ 0x0804071C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08040736
	bl isKilled
	cmp r0, #0
	beq _08040736
	movs r0, #0
	str r0, [r5]
_08040736:
	adds r0, r4, #0
	bl tryKillChildre
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040762
	ldr r1, _08040768 @ =0x08361E0C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0804076C @ =0x08361E58
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08040762:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040768: .4byte 0x08361E0C
_0804076C: .4byte 0x08361E58

	thumb_func_start Childre_Die
Childre_Die: @ 0x08040770
	push {lr}
	ldr r2, _08040784 @ =0x08361EA4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08040784: .4byte 0x08361EA4

	thumb_func_start nop_08040788
nop_08040788: @ 0x08040788
	bx lr
	.align 2, 0

	thumb_func_start childreNeutral
childreNeutral: @ 0x0804078C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080407A4
	b _080408D8
_080407A4:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080407DE
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	bne _080407D6
	ldr r3, [r4, #0x54]
	movs r5, #0x80
	lsls r5, r5, #4
	adds r0, r3, r5
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080407CE
	ldr r0, _08040858 @ =0xFFFFF800
	adds r2, r3, r0
_080407CE:
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
_080407D6:
	movs r1, #0
	movs r0, #0x12
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080407DE:
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _080408D8
	ldr r0, [r4, #0x58]
	ldr r2, _0804085C @ =0xFFFFF000
	adds r0, r0, r2
	ldr r1, _08040860 @ =gOverworld
	ldr r3, _08040864 @ =0x0002C00C
	adds r1, r1, r3
	ldr r1, [r1]
	cmp r0, r1
	ble _080408C0
	ldr r3, _08040868 @ =RNG_0202f388
	ldr r5, _0804086C @ =0x000343FD
	ldr r7, _08040870 @ =0x00001FFF
	adds r6, r2, #0
	movs r0, #4
	mov r8, r0
_0804080A:
	ldr r0, [r3]
	muls r0, r5, r0
	ldr r1, _08040874 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r2, r0, #1
	str r2, [r3]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08040878
	adds r1, r2, #0
	muls r1, r5, r1
	ldr r0, _08040874 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	ands r1, r7
	adds r1, r1, r6
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	muls r2, r5, r2
	ldr r1, _08040874 @ =0x00269EC3
	adds r2, r2, r1
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r3]
	lsrs r2, r2, #0x11
	ands r2, r7
	adds r2, r2, r6
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	movs r2, #0
	str r3, [sp]
	bl CreateBubble
	b _080408AC
	.align 2, 0
_08040858: .4byte 0xFFFFF800
_0804085C: .4byte 0xFFFFF000
_08040860: .4byte gOverworld
_08040864: .4byte 0x0002C00C
_08040868: .4byte RNG_0202f388
_0804086C: .4byte 0x000343FD
_08040870: .4byte 0x00001FFF
_08040874: .4byte 0x00269EC3
_08040878:
	adds r1, r2, #0
	muls r1, r5, r1
	ldr r0, _080408BC @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	ands r1, r7
	adds r1, r1, r6
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	muls r2, r5, r2
	ldr r1, _080408BC @ =0x00269EC3
	adds r2, r2, r1
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r3]
	lsrs r2, r2, #0x11
	ands r2, r7
	adds r2, r2, r6
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	movs r2, #1
	str r3, [sp]
	bl CreateBubble
_080408AC:
	ldr r3, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0804080A
	b _080408D0
	.align 2, 0
_080408BC: .4byte 0x00269EC3
_080408C0:
	ldr r2, _080408E4 @ =0x08362064
	movs r0, #0xa
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r4, #0
	adds r1, #0xb4
	str r0, [r1]
_080408D0:
	movs r1, #0
	movs r0, #0x11
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080408D8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080408E4: .4byte 0x08362064

	thumb_func_start childreMode0
childreMode0: @ 0x080408E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08040964
	cmp r5, #1
	bgt _080408FC
	cmp r5, #0
	beq _08040908
	b _08040A4A
_080408FC:
	cmp r5, #2
	beq _080409B0
	cmp r5, #3
	bne _08040906
	b _08040A12
_08040906:
	b _08040A4A
_08040908:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08040938 @ =0x08361EC4
	bl SetDDP
	strb r5, [r4, #0x12]
	ldr r0, _0804093C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r1, r0
	lsrs r2, r2, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08040940
	cmp r2, #0
	beq _08040944
	b _0804094C
	.align 2, 0
_08040938: .4byte 0x08361EC4
_0804093C: .4byte pZero2
_08040940:
	cmp r2, #0
	beq _0804094C
_08040944:
	ldrb r0, [r4, #0xe]
	adds r0, #2
	strb r0, [r4, #0xe]
	b _08040A4A
_0804094C:
	movs r0, #0x67
	bl PlaySound
	ldr r1, _080409A8 @ =0x0000A408
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080409AC @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08040964:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08040974
	str r1, [r4, #0x60]
_08040974:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	subs r0, r0, r1
	cmp r0, #0
	bge _0804098C
	adds r0, r1, r0
	str r0, [r4, #0x58]
_0804098C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08040A4A
	movs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08040A4A
	.align 2, 0
_080409A8: .4byte 0x0000A408
_080409AC: .4byte 0xFFFFFE00
_080409B0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080409F4
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _080409EC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080409F2
_080409EC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080409F2:
	strb r0, [r4, #0xa]
_080409F4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08040A50 @ =0x08361EC4
	bl SetDDP
	movs r0, #0x20
	strb r0, [r4, #0x12]
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08040A12:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040A44
	ldr r0, _08040A54 @ =pZero2
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08040A44
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08040A44
	adds r0, r4, #0
	bl childre_08040428
_08040A44:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08040A4A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040A50: .4byte 0x08361EC4
_08040A54: .4byte pZero2

	thumb_func_start childreMode1
childreMode1: @ 0x08040A58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _08040A6E
	b _08040D02
_08040A6E:
	lsls r0, r0, #2
	ldr r1, _08040A78 @ =_08040A7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040A78: .4byte _08040A7C
_08040A7C: @ jump table
	.4byte _08040AAC @ case 0
	.4byte _08040ABC @ case 1
	.4byte _08040AD2 @ case 2
	.4byte _08040AEA @ case 3
	.4byte _08040B04 @ case 4
	.4byte _08040B20 @ case 5
	.4byte _08040B84 @ case 6
	.4byte _08040B96 @ case 7
	.4byte _08040BB0 @ case 8
	.4byte _08040BC2 @ case 9
	.4byte _08040CDC @ case 10
	.4byte _08040CEC @ case 11
_08040AAC:
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040ABC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08040AD0
	b _08040D02
_08040AD0:
	b _08040CB8
_08040AD2:
	movs r0, #0x65
	bl PlaySound
	movs r0, #4
	strb r0, [r7, #0x12]
	ldr r1, _08040B00 @ =0x0000A41B
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040AEA:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040AFE
	b _08040D02
_08040AFE:
	b _08040CB8
	.align 2, 0
_08040B00: .4byte 0x0000A41B
_08040B04:
	movs r0, #0x67
	bl PlaySound
	ldr r0, _08040B78 @ =0xFFFFFE00
	str r0, [r7, #0x60]
	movs r0, #0
	strb r0, [r7, #0x12]
	ldr r1, _08040B7C @ =0x0000A41C
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040B20:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08040B30
	str r1, [r7, #0x60]
_08040B30:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08040B4E
	cmp r1, #0
	ble _08040B4E
	movs r0, #1
	strb r0, [r7, #0x12]
	ldr r1, _08040B80 @ =0x0000A41D
	adds r0, r7, #0
	bl SetMotion
_08040B4E:
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldr r2, [r7, #0x58]
	subs r1, r0, r2
	str r1, [sp, #0xc]
	cmp r1, #0
	bge _08040B6E
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _08040B6E
	adds r0, r2, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040B6E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _08040D02
	.align 2, 0
_08040B78: .4byte 0xFFFFFE00
_08040B7C: .4byte 0x0000A41C
_08040B80: .4byte 0x0000A41D
_08040B84:
	movs r0, #4
	strb r0, [r7, #0x12]
	ldr r1, _08040BAC @ =0x0000A41B
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040B96:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040BAA
	b _08040D02
_08040BAA:
	b _08040CB8
	.align 2, 0
_08040BAC: .4byte 0x0000A41B
_08040BB0:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldr r1, _08040CC0 @ =0x0000A419
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040BC2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _08040BDC
	movs r0, #0x66
	bl PlaySound
_08040BDC:
	ldrb r0, [r7, #0x12]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040CAE
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08040C00
	cmp r0, #4
	beq _08040C00
	cmp r0, #5
	bne _08040CAE
_08040C00:
	ldr r0, [r7, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r7, #0x58]
	ldr r1, _08040CC4 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #0x14]
	ldr r6, _08040CC8 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _08040CCC @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _08040CD0 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r0, r0, #1
	add r1, sp, #0x14
	mov r8, r1
	movs r2, #0x55
	rsbs r2, r2, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r2, r2, r0
	mov r0, r8
	str r2, [r0, #4]
	ldr r1, _08040CD4 @ =0x0836206C
	mov sl, r1
	str r1, [sp]
	movs r0, #0x18
	mov sb, r0
	str r0, [sp, #4]
	adds r0, r7, #0
	add r1, sp, #0xc
	mov r2, r8
	movs r3, #0
	bl FUN_080b834c
	ldr r0, [r7, #0x54]
	ldr r1, _08040CD8 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r7, #0x58]
	ldr r1, _08040CC4 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #0x60
	str r0, [sp, #0x14]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r0, r0, #1
	movs r2, #0x20
	rsbs r2, r2, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r2, r2, r0
	mov r0, r8
	str r2, [r0, #4]
	mov r1, sl
	str r1, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #0x19
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #0xc
	mov r2, r8
	movs r3, #0
	bl FUN_080b8454
_08040CAE:
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08040D02
_08040CB8:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08040D02
	.align 2, 0
_08040CC0: .4byte 0x0000A419
_08040CC4: .4byte 0xFFFFEC00
_08040CC8: .4byte RNG_0202f388
_08040CCC: .4byte 0x000343FD
_08040CD0: .4byte 0x00269EC3
_08040CD4: .4byte 0x0836206C
_08040CD8: .4byte 0xFFFFF800
_08040CDC:
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040CEC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, _08040D14 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08040D02
	strb r1, [r7, #0xd]
	strb r1, [r7, #0xe]
_08040D02:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040D14: .4byte gStageRun

	thumb_func_start childreMode2
childreMode2: @ 0x08040D18
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08040D28
	cmp r0, #1
	beq _08040DBA
	b _08040E58
_08040D28:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08040D64 @ =0x08361EC4
	bl SetDDP
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, _08040D68 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	ldr r3, _08040D6C @ =0xFFFFC800
	adds r0, r0, r3
	str r0, [r2]
	ldrb r3, [r4, #0x12]
	ldr r0, [r1, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08040D52
	movs r0, #1
	eors r3, r0
_08040D52:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08040D70
	cmp r3, #1
	bne _08040D96
	b _08040D74
	.align 2, 0
_08040D64: .4byte 0x08361EC4
_08040D68: .4byte pZero2
_08040D6C: .4byte 0xFFFFC800
_08040D70:
	cmp r3, #0
	bne _08040D96
_08040D74:
	ldr r3, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08040D84
	movs r0, #0xe0
	lsls r0, r0, #7
	adds r3, r3, r0
_08040D84:
	str r3, [r2]
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	adds r0, r4, #0
	bl childreMode3
	b _08040E58
_08040D96:
	ldr r3, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08040DA6
	movs r0, #0xe0
	lsls r0, r0, #7
	adds r3, r3, r0
_08040DA6:
	str r3, [r2]
	ldr r1, _08040E3C @ =0x0000A408
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08040E40 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08040DBA:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08040DCA
	str r1, [r4, #0x60]
_08040DCA:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	subs r0, r0, r1
	cmp r0, #0
	bge _08040DE2
	adds r0, r1, r0
	str r0, [r4, #0x58]
_08040DE2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08040E58
	ldr r1, _08040E44 @ =0x0000A404
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r2, #0x4a
	adds r2, r2, r4
	mov ip, r2
	lsls r3, r1, #4
	ldrb r2, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r3, ip
	strb r0, [r3]
	cmp r1, #0
	beq _08040E48
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08040E4E
	.align 2, 0
_08040E3C: .4byte 0x0000A408
_08040E40: .4byte 0xFFFFFE00
_08040E44: .4byte 0x0000A404
_08040E48:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08040E4E:
	strb r0, [r4, #0xa]
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08040E58:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start childreMode3
childreMode3: @ 0x08040E60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08040E6C
	b _08041026
_08040E6C:
	lsls r0, r0, #2
	ldr r1, _08040E78 @ =_08040E7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040E78: .4byte _08040E7C
_08040E7C: @ jump table
	.4byte _08040E94 @ case 0
	.4byte _08040EB0 @ case 1
	.4byte _08040ED4 @ case 2
	.4byte _08040F4A @ case 3
	.4byte _08040FCC @ case 4
	.4byte _08040FDE @ case 5
_08040E94:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08040ECC @ =0x08361EC4
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	ldr r1, _08040ED0 @ =0x0000A404
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08040EB0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040EC4
	b _08041026
_08040EC4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08041024
	.align 2, 0
_08040ECC: .4byte 0x08361EC4
_08040ED0: .4byte 0x0000A404
_08040ED4:
	movs r0, #0x67
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, [r4, #0x54]
	subs r2, r1, r0
	movs r0, #0xc0
	lsls r0, r0, #6
	adds r1, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #7
	cmp r1, r0
	bls _08040F1E
	movs r3, #0
	cmp r2, #0
	ble _08040EFA
	movs r3, #1
_08040EFA:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08040F0A
	cmp r3, #0
	beq _08040F0E
	b _08040F1E
_08040F0A:
	cmp r3, #0
	beq _08040F1E
_08040F0E:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	adds r0, r4, #0
	bl childreStartRising
	b _08041026
_08040F1E:
	ldr r1, _08040FBC @ =0x0000A405
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08040FC0 @ =0xFFFFFD00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08040F3A
	movs r2, #0xc0
	lsls r2, r2, #2
_08040F3A:
	str r2, [r4, #0x5c]
	ldr r0, _08040FC4 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08040F4A:
	ldr r0, [r4, #0x54]
	ldr r5, [r4, #0x5c]
	adds r3, r0, r5
	str r3, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	subs r2, r0, r3
	movs r0, #0xc0
	lsls r0, r0, #7
	adds r1, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #8
	cmp r1, r0
	bls _08040F6C
	subs r0, r3, r5
	str r0, [r4, #0x54]
_08040F6C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08040F7C
	str r1, [r4, #0x60]
_08040F7C:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08040F94
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08040F94
	ldr r1, _08040FC8 @ =0x0000A406
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0x12]
_08040F94:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08040FB4
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08040FB4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08041026
	.align 2, 0
_08040FBC: .4byte 0x0000A405
_08040FC0: .4byte 0xFFFFFD00
_08040FC4: .4byte 0xFFFFFC00
_08040FC8: .4byte 0x0000A406
_08040FCC:
	movs r0, #4
	strb r0, [r4, #0x12]
	ldr r1, _08041014 @ =0x0000A407
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08040FDE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08041026
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08041002
	movs r2, #1
_08041002:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08041018
	cmp r2, #0
	beq _0804101C
	b _08041022
	.align 2, 0
_08041014: .4byte 0x0000A407
_08041018:
	cmp r2, #0
	beq _08041022
_0804101C:
	movs r0, #0
	strb r0, [r4, #0xd]
	b _08041024
_08041022:
	movs r0, #2
_08041024:
	strb r0, [r4, #0xe]
_08041026:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start childreStartRising
childreStartRising: @ 0x0804102C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0804103C
	cmp r0, #1
	beq _080410A8
	b _08041122
_0804103C:
	movs r0, #0x67
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041128 @ =0x08361EF4
	bl SetDDP
	ldr r0, [r4, #0x58]
	ldr r1, _0804112C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r5, #6
	rsbs r1, r1, #0
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r3, [r0]
	ldr r1, _08041130 @ =0xFFFFA000
	adds r0, r3, r1
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804108C
	movs r0, #0xc0
	lsls r0, r0, #7
	adds r2, r3, r0
_0804108C:
	ldr r0, [r4, #0x54]
	subs r0, r2, r0
	str r0, [r4, #0x5c]
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r1, _08041134 @ =0x0000A41A
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080410A8:
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	subs r5, r0, r1
	movs r0, #0xd0
	lsls r0, r0, #7
	adds r1, r5, r0
	movs r0, #0xd0
	lsls r0, r0, #8
	cmp r1, r0
	bls _080410CA
	movs r3, #1
_080410CA:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080410DA
	str r1, [r4, #0x60]
_080410DA:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	cmp r3, #0
	bne _080410EA
	cmp r1, #0
	ble _0804110E
_080410EA:
	ldr r3, [r2]
	ldr r1, _08041138 @ =0xFFFF9800
	adds r0, r3, r1
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08041104
	movs r0, #0xd0
	lsls r0, r0, #7
	adds r2, r3, r0
_08041104:
	str r2, [r4, #0x54]
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804110E:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	beq _08041122
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08041122:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08041128: .4byte 0x08361EF4
_0804112C: .4byte 0xFFFFF800
_08041130: .4byte 0xFFFFA000
_08041134: .4byte 0x0000A41A
_08041138: .4byte 0xFFFF9800

	thumb_func_start childreRising
childreRising: @ 0x0804113C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08041148
	b _08041314
_08041148:
	lsls r0, r0, #2
	ldr r1, _08041154 @ =_08041158
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08041154: .4byte _08041158
_08041158: @ jump table
	.4byte _08041170 @ case 0
	.4byte _080411A6 @ case 1
	.4byte _080411C8 @ case 2
	.4byte _080411F4 @ case 3
	.4byte _080412EC @ case 4
	.4byte _080412FE @ case 5
_08041170:
	movs r0, #0x68
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080411C0 @ =0x08361EC4
	bl SetDDP
	adds r0, r4, #0
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #4
	strb r0, [r4, #0x12]
	ldr r1, _080411C4 @ =0x0000A404
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080411A6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080411BA
	b _08041314
_080411BA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08041312
	.align 2, 0
_080411C0: .4byte 0x08361EC4
_080411C4: .4byte 0x0000A404
_080411C8:
	movs r0, #0x67
	bl PlaySound
	ldr r1, _08041220 @ =0x0000A405
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _08041224 @ =0xFFFFFC00
	str r2, [r4, #0x60]
	str r2, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080411EA
	rsbs r0, r2, #0
	str r0, [r4, #0x5c]
_080411EA:
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080411F4:
	ldrb r0, [r4, #0xa]
	lsrs r5, r0, #4
	movs r0, #1
	ands r5, r0
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	subs r0, #0x40
	lsls r1, r5, #7
	adds r1, r0, r1
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08041238
	cmp r1, #0
	bge _08041228
	cmp r5, #1
	bne _0804122C
	b _08041238
	.align 2, 0
_08041220: .4byte 0x0000A405
_08041224: .4byte 0xFFFFFC00
_08041228:
	cmp r5, #0
	beq _08041238
_0804122C:
	ldr r1, _08041260 @ =0x0000A406
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0x12]
_08041238:
	ldr r1, [r4, #0x54]
	ldr r3, [r4, #0x5c]
	adds r1, r1, r3
	str r1, [r4, #0x54]
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	subs r0, r0, r1
	movs r1, #0xd0
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xd0
	lsls r1, r1, #8
	cmp r0, r1
	bls _08041282
	cmp r3, #0
	bge _08041264
	cmp r5, #1
	bne _08041268
	b _08041282
	.align 2, 0
_08041260: .4byte 0x0000A406
_08041264:
	cmp r5, #0
	beq _08041282
_08041268:
	ldr r0, [r2]
	ldr r3, _080412C8 @ =0xFFFF9800
	adds r0, r0, r3
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r1, r1, r5
	lsls r1, r1, #0xc
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041282:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldr r1, _080412CC @ =0xFFFE8000
	adds r2, r0, r1
	ldr r1, [r4, #0x58]
	cmp r1, r2
	blt _080412A4
	ldr r0, _080412D0 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r3, _080412D4 @ =0xFFFF7000
	adds r0, r0, r3
	cmp r1, r0
	bge _08041314
_080412A4:
	str r2, [r4, #0x58]
	ldr r2, _080412D8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080412DC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080412E0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080412E4
	movs r0, #6
	b _080412E6
	.align 2, 0
_080412C8: .4byte 0xFFFF9800
_080412CC: .4byte 0xFFFE8000
_080412D0: .4byte gStageRun+232
_080412D4: .4byte 0xFFFF7000
_080412D8: .4byte RNG_0202f388
_080412DC: .4byte 0x000343FD
_080412E0: .4byte 0x00269EC3
_080412E4:
	movs r0, #9
_080412E6:
	strb r0, [r4, #0xd]
	movs r0, #0
	b _08041312
_080412EC:
	movs r0, #4
	strb r0, [r4, #0x12]
	ldr r1, _0804131C @ =0x0000A407
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080412FE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08041314
	movs r0, #2
_08041312:
	strb r0, [r4, #0xe]
_08041314:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804131C: .4byte 0x0000A407

	thumb_func_start childreMode6
childreMode6: @ 0x08041320
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080413AA
	cmp r0, #1
	bgt _08041334
	cmp r0, #0
	beq _0804133E
	b _0804142A
_08041334:
	cmp r0, #2
	beq _080413BE
	cmp r0, #3
	beq _080413F6
	b _0804142A
_0804133E:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08041394 @ =0x08361EC4
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08041398
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804139E
	.align 2, 0
_08041394: .4byte 0x08361EC4
_08041398:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804139E:
	strb r0, [r5, #0xa]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080413AA:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804142A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804142A
_080413BE:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r3, r1
	str r0, [r5, #0x54]
	adds r1, r0, #0
	ldrb r2, [r5, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080413DC
	ldr r0, _08041430 @ =0xFFFFB000
	adds r1, r3, r0
_080413DC:
	str r1, [r5, #0x54]
	movs r0, #1
	movs r4, #0
	orrs r0, r2
	strb r0, [r5, #0xa]
	ldr r1, _08041434 @ =0x0000A406
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080413F6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804140C
	str r1, [r5, #0x60]
_0804140C:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, _08041438 @ =gOverworld
	ldr r2, _0804143C @ =0x0002C00C
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	ble _0804142A
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804142A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08041430: .4byte 0xFFFFB000
_08041434: .4byte 0x0000A406
_08041438: .4byte gOverworld
_0804143C: .4byte 0x0002C00C

	thumb_func_start childreMode7
childreMode7: @ 0x08041440
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0804144C
	b _080415AC
_0804144C:
	lsls r0, r0, #2
	ldr r1, _08041458 @ =_0804145C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08041458: .4byte _0804145C
_0804145C: @ jump table
	.4byte _08041474 @ case 0
	.4byte _08041494 @ case 1
	.4byte _080414B8 @ case 2
	.4byte _080414EC @ case 3
	.4byte _08041560 @ case 4
	.4byte _08041596 @ case 5
_08041474:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080414B0 @ =0x08361EC4
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	movs r0, #3
	strb r0, [r4, #0x13]
	ldr r1, _080414B4 @ =0x0000A404
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041494:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080414A8
	b _080415AC
_080414A8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080415AA
	.align 2, 0
_080414B0: .4byte 0x08361EC4
_080414B4: .4byte 0x0000A404
_080414B8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl CreateSplitMineBomb
	ldr r1, _08041548 @ =0x0000A405
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _0804154C @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080414DC
	movs r2, #0x80
	lsls r2, r2, #2
_080414DC:
	str r2, [r4, #0x5c]
	ldr r0, _08041550 @ =0xFFFFFA00
	str r0, [r4, #0x60]
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080414EC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x80
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08041504
	str r1, [r4, #0x60]
_08041504:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0804151C
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0804151C
	ldr r1, _08041554 @ =0x0000A406
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0x12]
_0804151C:
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	ldr r0, _08041558 @ =gOverworld
	ldr r3, _0804155C @ =0x0002C00C
	adds r0, r0, r3
	ldr r0, [r0]
	subs r0, r0, r1
	cmp r0, #0
	bge _08041540
	cmp r2, #0
	ble _08041540
	adds r0, r1, r0
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041540:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080415AC
	.align 2, 0
_08041548: .4byte 0x0000A405
_0804154C: .4byte 0xFFFFFE00
_08041550: .4byte 0xFFFFFA00
_08041554: .4byte 0x0000A406
_08041558: .4byte gOverworld
_0804155C: .4byte 0x0002C00C
_08041560:
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08041588
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl CreateSplitMineBomb
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	adds r0, r4, #0
	bl childreMode8
	b _080415AC
_08041588:
	ldr r1, _080415B4 @ =0x0000A407
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041596:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080415AC
	movs r0, #2
_080415AA:
	strb r0, [r4, #0xe]
_080415AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080415B4: .4byte 0x0000A407

	thumb_func_start childreMode8
childreMode8: @ 0x080415B8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080415F8
	cmp r5, #1
	bgt _080415CC
	cmp r5, #0
	beq _080415D6
	b _080416DE
_080415CC:
	cmp r5, #2
	beq _08041638
	cmp r5, #3
	beq _0804164A
	b _080416DE
_080415D6:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041630 @ =0x08361EC4
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08041634 @ =0x0000A406
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080415F8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804160E
	str r1, [r4, #0x60]
_0804160E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080416DE
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080416DC
	.align 2, 0
_08041630: .4byte 0x08361EC4
_08041634: .4byte 0x0000A406
_08041638:
	ldr r0, _080416C8 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldr r1, _080416CC @ =0x0000A408
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804164A:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804165A
	str r1, [r4, #0x60]
_0804165A:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	subs r1, r0, r2
	cmp r1, #0
	bge _08041672
	adds r0, r2, r1
	str r0, [r4, #0x58]
_08041672:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080416DE
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _080416D0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080416D6
	.align 2, 0
_080416C8: .4byte 0xFFFFFE00
_080416CC: .4byte 0x0000A408
_080416D0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080416D6:
	strb r0, [r4, #0xa]
	movs r0, #0
	strb r0, [r4, #0xd]
_080416DC:
	strb r0, [r4, #0xe]
_080416DE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start childreStartScrewIce
childreStartScrewIce: @ 0x080416E4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08041720
	cmp r0, #1
	bgt _080416F8
	cmp r0, #0
	beq _08041702
	b _080417FA
_080416F8:
	cmp r0, #2
	beq _08041734
	cmp r0, #3
	beq _08041762
	b _080417FA
_08041702:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041720:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080417FA
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080417FA
_08041734:
	movs r0, #0x6a
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080417D0 @ =0x08361F24
	bl SetDDP
	ldr r0, _080417D4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080417D8 @ =0x0000A40B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041762:
	ldr r0, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r1, r0, r2
	str r1, [r4, #0x58]
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _080417F4
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _080417DC @ =0xFFFFFB00
	adds r0, r0, r2
	movs r2, #0x68
	bl CreateChildreScrewIce
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x18
	bl CreateChildreScrewIce
	ldr r0, [r4, #0x54]
	ldr r2, _080417DC @ =0xFFFFFB00
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	movs r2, #0x78
	bl CreateChildreScrewIce
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #8
	bl CreateChildreScrewIce
	ldr r0, _080417E0 @ =gOverworld
	ldr r2, _080417E4 @ =0x0002C00C
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, [r5]
	subs r0, r0, r1
	ldr r1, _080417E8 @ =0xFFFFE000
	cmp r0, r1
	ble _080417EC
	movs r1, #0
	movs r0, #0xa
	b _080417F0
	.align 2, 0
_080417D0: .4byte 0x08361F24
_080417D4: .4byte pZero2
_080417D8: .4byte 0x0000A40B
_080417DC: .4byte 0xFFFFFB00
_080417E0: .4byte gOverworld
_080417E4: .4byte 0x0002C00C
_080417E8: .4byte 0xFFFFE000
_080417EC:
	movs r1, #0
	movs r0, #0xb
_080417F0:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080417F4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080417FA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start childreMaybeMiddleScrewIce
childreMaybeMiddleScrewIce: @ 0x08041800
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08041810
	cmp r0, #1
	beq _08041832
	b _0804184C
_08041810:
	movs r0, #0x40
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041854 @ =0x08361F54
	bl SetDDP
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldr r1, _08041858 @ =0x0000A40C
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041832:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804184C
	movs r0, #0xb
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804184C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041854: .4byte 0x08361F54
_08041858: .4byte 0x0000A40C

	thumb_func_start childreScrewIce
childreScrewIce: @ 0x0804185C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08041898
	cmp r0, #1
	bgt _08041870
	cmp r0, #0
	beq _0804187A
	b _08041964
_08041870:
	cmp r0, #2
	beq _080418B8
	cmp r0, #3
	beq _080418FA
	b _08041964
_0804187A:
	movs r0, #0x40
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080418B0 @ =0x08361F54
	bl SetDDP
	ldr r1, _080418B4 @ =0x0000A40D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041898:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08041964
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08041964
	.align 2, 0
_080418B0: .4byte 0x08361F54
_080418B4: .4byte 0x0000A40D
_080418B8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804196C @ =0x08361EF4
	bl SetDDP
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl CreateVFX31_2
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080418DE
	ldr r2, _08041970 @ =0xFFFFFD80
_080418DE:
	str r2, [r4, #0x5c]
	ldr r0, _08041974 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	ldr r1, _08041978 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _0804197C @ =0x0000A40E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080418FA:
	ldr r0, [r4, #0x54]
	ldr r3, [r4, #0x5c]
	adds r2, r0, r3
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	subs r0, r0, r2
	movs r5, #0xc0
	lsls r5, r5, #7
	adds r1, r0, r5
	movs r0, #0xc0
	lsls r0, r0, #8
	cmp r1, r0
	bls _0804191C
	subs r0, r2, r3
	str r0, [r4, #0x54]
_0804191C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804192C
	str r1, [r4, #0x60]
_0804192C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	ldr r2, _08041980 @ =0xFFFFF800
	adds r0, r0, r2
	subs r0, r0, r1
	cmp r0, #0
	bge _0804195E
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r5]
	str r0, [r4, #0x58]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0804195E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08041964:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804196C: .4byte 0x08361EF4
_08041970: .4byte 0xFFFFFD80
_08041974: .4byte 0xFFFFFD00
_08041978: .4byte 0xFFFFE000
_0804197C: .4byte 0x0000A40E
_08041980: .4byte 0xFFFFF800

	thumb_func_start childreMissile
childreMissile: @ 0x08041984
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08041990
	b _08041B38
_08041990:
	lsls r0, r0, #2
	ldr r1, _0804199C @ =_080419A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804199C: .4byte _080419A0
_080419A0: @ jump table
	.4byte _080419B4 @ case 0
	.4byte _08041A04 @ case 1
	.4byte _08041A50 @ case 2
	.4byte _08041AA8 @ case 3
	.4byte _08041AE8 @ case 4
_080419B4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080419E0 @ =0x08361EC4
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x12]
	ldr r0, _080419E4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r1, r0
	lsrs r2, r2, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080419E8
	cmp r2, #0
	beq _080419EC
	b _080419F2
	.align 2, 0
_080419E0: .4byte 0x08361EC4
_080419E4: .4byte pZero2
_080419E8:
	cmp r2, #0
	beq _080419F2
_080419EC:
	ldrb r0, [r4, #0xe]
	adds r0, #2
	b _08041B36
_080419F2:
	ldr r1, _08041A48 @ =0x0000A408
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08041A4C @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041A04:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08041A14
	str r1, [r4, #0x60]
_08041A14:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	subs r0, r0, r1
	cmp r0, #0
	bge _08041A2C
	adds r0, r1, r0
	str r0, [r4, #0x58]
_08041A2C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08041A3E
	b _08041B38
_08041A3E:
	movs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08041B36
	.align 2, 0
_08041A48: .4byte 0x0000A408
_08041A4C: .4byte 0xFFFFFE00
_08041A50:
	movs r0, #0x69
	bl PlaySound
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08041A9E
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08041A96
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08041A9C
_08041A96:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08041A9C:
	strb r0, [r4, #0xa]
_08041A9E:
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041AA8:
	ldr r1, _08041B18 @ =0x0836206E
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08041ADE
	movs r0, #0x64
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _08041B1C @ =0xFFFFE600
	adds r1, r1, r2
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r3, #1
	ands r2, r3
	bl CreateChildreMissile
_08041ADE:
	movs r0, #0x18
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041AE8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	adds r0, r1, #0
	cmp r0, #0
	beq _08041AFA
	cmp r0, #5
	bne _08041B24
_08041AFA:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _08041B38
	adds r0, r1, #1
	movs r1, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08041B20
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08041B38
	.align 2, 0
_08041B18: .4byte 0x0836206E
_08041B1C: .4byte 0xFFFFE600
_08041B20:
	strb r2, [r4, #0xe]
	b _08041B38
_08041B24:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08041B38
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #3
_08041B36:
	strb r0, [r4, #0xe]
_08041B38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start childreStartEarShot
childreStartEarShot: @ 0x08041B40
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08041B4C
	b _08041CB4
_08041B4C:
	lsls r0, r0, #2
	ldr r1, _08041B58 @ =_08041B5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08041B58: .4byte _08041B5C
_08041B5C: @ jump table
	.4byte _08041B74 @ case 0
	.4byte _08041BC6 @ case 1
	.4byte _08041C0C @ case 2
	.4byte _08041C72 @ case 3
	.4byte _08041C90 @ case 4
	.4byte _08041C9C @ case 5
_08041B74:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041BA0 @ =0x08361EC4
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x12]
	ldr r0, _08041BA4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r2, r1, r0
	lsrs r2, r2, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08041BA8
	cmp r2, #0
	beq _08041BAC
	b _08041BB4
	.align 2, 0
_08041BA0: .4byte 0x08361EC4
_08041BA4: .4byte pZero2
_08041BA8:
	cmp r2, #0
	beq _08041BB4
_08041BAC:
	ldrb r0, [r4, #0xe]
	adds r0, #2
	strb r0, [r4, #0xe]
	b _08041CB4
_08041BB4:
	ldr r1, _08041C04 @ =0x0000A408
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08041C08 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041BC6:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08041BD6
	str r1, [r4, #0x60]
_08041BD6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	subs r0, r0, r1
	cmp r0, #0
	bge _08041BEE
	adds r0, r1, r0
	str r0, [r4, #0x58]
_08041BEE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08041CB4
	movs r0, #1
	strb r0, [r4, #0x12]
	b _08041C82
	.align 2, 0
_08041C04: .4byte 0x0000A408
_08041C08: .4byte 0xFFFFFE00
_08041C0C:
	ldr r1, _08041C54 @ =0x0000A413
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08041C60
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08041C58
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08041C5E
	.align 2, 0
_08041C54: .4byte 0x0000A413
_08041C58:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08041C5E:
	strb r0, [r4, #0xa]
_08041C60:
	ldr r1, _08041C8C @ =0x0000A403
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041C72:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08041CB4
_08041C82:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08041CB4
	.align 2, 0
_08041C8C: .4byte 0x0000A403
_08041C90:
	movs r0, #0x6c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041C9C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08041CB4
	movs r1, #0
	movs r0, #0xe
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08041CB4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start childreEarShot
childreEarShot: @ 0x08041CBC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08041D1C
	cmp r0, #1
	bgt _08041CD0
	cmp r0, #0
	beq _08041CDA
	b _08041DE4
_08041CD0:
	cmp r0, #2
	beq _08041D3C
	cmp r0, #3
	beq _08041DCC
	b _08041DE4
_08041CDA:
	ldr r0, _08041CF8 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08041D04
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041CFC @ =0x08361FCC
	bl SetDDP
	ldr r1, _08041D00 @ =0x0000A417
	adds r0, r4, #0
	bl SetMotion
	b _08041D16
	.align 2, 0
_08041CF8: .4byte gMission
_08041CFC: .4byte 0x08361FCC
_08041D00: .4byte 0x0000A417
_08041D04:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041D34 @ =0x08361F84
	bl SetDDP
	ldr r1, _08041D38 @ =0x0000A414
	adds r0, r4, #0
	bl SetMotion
_08041D16:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041D1C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08041DE4
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08041DE4
	.align 2, 0
_08041D34: .4byte 0x08361F84
_08041D38: .4byte 0x0000A414
_08041D3C:
	movs r0, #0x6b
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041D84 @ =0x08361EC4
	bl SetDDP
	ldr r0, _08041D88 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08041D94
	ldr r1, [r4, #0x54]
	ldr r0, _08041D8C @ =0xFFFFB400
	adds r3, r1, r0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08041D6C
	movs r0, #0x98
	lsls r0, r0, #7
	adds r3, r1, r0
_08041D6C:
	ldr r1, [r4, #0x58]
	ldr r0, _08041D90 @ =0xFFFFF400
	adds r1, r1, r0
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r3, #0
	movs r3, #1
	bl createEarShot
	b _08041DBE
	.align 2, 0
_08041D84: .4byte 0x08361EC4
_08041D88: .4byte gMission
_08041D8C: .4byte 0xFFFFB400
_08041D90: .4byte 0xFFFFF400
_08041D94:
	ldr r1, [r4, #0x54]
	ldr r0, _08041DEC @ =0xFFFFDB00
	adds r3, r1, r0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08041DAA
	movs r0, #0x94
	lsls r0, r0, #6
	adds r3, r1, r0
_08041DAA:
	ldr r1, [r4, #0x58]
	ldr r0, _08041DF0 @ =0xFFFFF300
	adds r1, r1, r0
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r3, #0
	movs r3, #0
	bl createEarShot
_08041DBE:
	ldr r1, _08041DF4 @ =0x0000A415
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041DCC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08041DE4
	movs r1, #0
	movs r0, #0xf
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08041DE4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041DEC: .4byte 0xFFFFDB00
_08041DF0: .4byte 0xFFFFF300
_08041DF4: .4byte 0x0000A415

	thumb_func_start childreEndEarShot
childreEndEarShot: @ 0x08041DF8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08041E08
	cmp r0, #1
	beq _08041E20
	b _08041E36
_08041E08:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08041E3C @ =0x08361EC4
	bl SetDDP
	ldr r1, _08041E40 @ =0x0000A416
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041E20:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08041E36
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08041E36:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041E3C: .4byte 0x08361EC4
_08041E40: .4byte 0x0000A416

	thumb_func_start childreMode16
childreMode16: @ 0x08041E44
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _08041E56
	cmp r1, #1
	beq _08041EC4
	b _08041F2C
_08041E56:
	ldrb r0, [r4, #0xb]
	movs r7, #0x10
	movs r6, #0
	orrs r0, r7
	strb r0, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08041EAE
	ldrb r0, [r4, #0xa]
	orrs r0, r7
	b _08041EB4
_08041EAE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08041EB4:
	strb r0, [r4, #0xa]
	ldr r1, _08041ED8 @ =0x0000A409
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041EC4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08041EDC
	movs r0, #0xf6
	b _08041EDE
	.align 2, 0
_08041ED8: .4byte 0x0000A409
_08041EDC:
	movs r0, #0xfa
_08041EDE:
	muls r0, r1, r0
	cmp r0, #0
	bge _08041EE6
	adds r0, #0xff
_08041EE6:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_0801779c
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bne _08041F2C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
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
	ldr r1, _08041F34 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08041F2C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041F34: .4byte gBossFnTable

	thumb_func_start childreStun
childreStun: @ 0x08041F38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08041F48
	cmp r5, #1
	beq _08041FA4
	b _08041FFC
_08041F48:
	movs r0, #0x6d
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _08041F90 @ =0x0000A41F
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	str r5, [r4, #0x60]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r1, r0, r2
	ldr r2, [r4, #0x54]
	cmp r2, r1
	ble _08041F94
	str r1, [r4, #0x54]
	b _08041F9E
	.align 2, 0
_08041F90: .4byte 0x0000A41F
_08041F94:
	ldr r3, _08042004 @ =0xFFFFA000
	adds r0, r0, r3
	cmp r2, r0
	bge _08041F9E
	str r0, [r4, #0x54]
_08041F9E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041FA4:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08041FB4
	str r1, [r4, #0x60]
_08041FB4:
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	subs r5, r0, r1
	cmp r5, #0
	bge _08041FD6
	cmp r2, #0
	ble _08041FD6
	adds r0, r1, r5
	str r0, [r4, #0x58]
_08041FD6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08041FEC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08041FFC
_08041FEC:
	cmp r5, #0
	bge _08041FFC
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08041FFC
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08041FFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042004: .4byte 0xFFFFA000

	thumb_func_start childreMode18
childreMode18: @ 0x08042008
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08042018
	cmp r0, #1
	beq _080420C0
	b _08042136
_08042018:
	movs r0, #0x6d
	bl PlaySound
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldr r1, _080420DC @ =0x0000A41F
	adds r0, r5, #0
	bl SetMotion
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r1, r2
	str r0, [r5, #0x58]
	adds r2, r5, #0
	adds r2, #0xc8
	ldr r0, [r5, #0x54]
	ldr r2, [r2]
	subs r0, r0, r2
	str r0, [r5, #0x5c]
	ldr r3, _080420E0 @ =0xFFFFD800
	adds r1, r1, r3
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r2, [r2]
	subs r1, r1, r2
	str r1, [r5, #0x60]
	asrs r0, r0, #8
	adds r6, r0, #0
	muls r6, r0, r6
	asrs r1, r1, #8
	adds r0, r1, #0
	muls r0, r1, r0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r1, r0, #0
	str r1, [r5, #0x60]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	subs r0, r0, r4
	lsls r0, r0, #7
	cmp r0, #0
	bge _080420A2
	adds r0, #0xff
_080420A2:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _080420B6
	adds r0, #0xff
_080420B6:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080420C0:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r1, r0, r1
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #7
	adds r2, r0, r3
	cmp r1, r2
	ble _080420E4
	str r2, [r5, #0x54]
	b _080420EE
	.align 2, 0
_080420DC: .4byte 0x0000A41F
_080420E0: .4byte 0xFFFFD800
_080420E4:
	ldr r2, _0804213C @ =0xFFFFA000
	adds r0, r0, r2
	cmp r1, r0
	bge _080420EE
	str r0, [r5, #0x54]
_080420EE:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080420FE
	str r1, [r5, #0x60]
_080420FE:
	ldr r0, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r0, r2
	str r1, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	subs r6, r0, r1
	cmp r6, #0
	bge _08042120
	cmp r2, #0
	ble _08042120
	adds r0, r1, r6
	str r0, [r5, #0x58]
_08042120:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	cmp r6, #0
	bge _08042136
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08042136
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_08042136:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804213C: .4byte 0xFFFFA000

	thumb_func_start childre_08042140
childre_08042140: @ 0x08042140
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _08042214
	lsls r0, r0, #2
	ldr r1, _08042154 @ =_08042158
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042154: .4byte _08042158
_08042158: @ jump table
	.4byte _0804216C @ case 0
	.4byte _080421C4 @ case 1
	.4byte _080421EC @ case 2
	.4byte _080421FC @ case 3
	.4byte _08042214 @ case 4
_0804216C:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r3, _080421E0 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _080421B2
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080421B2
	ldr r0, _080421E4 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080421B2:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldr r1, _080421E8 @ =0x0000A41F
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080421C4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08042214
	b _0804220E
	.align 2, 0
_080421E0: .4byte gStageRun
_080421E4: .4byte 0x0000FFFE
_080421E8: .4byte 0x0000A41F
_080421EC:
	ldr r1, _0804221C @ =0x0836207C
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080421FC:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08042214
	ldr r2, _08042220 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_0804220E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042214:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804221C: .4byte 0x0836207C
_08042220: .4byte gStageRun

	thumb_func_start childre_08042224
childre_08042224: @ 0x08042224
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08042232
	b _080423CE
_08042232:
	lsls r0, r0, #2
	ldr r1, _0804223C @ =_08042240
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804223C: .4byte _08042240
_08042240: @ jump table
	.4byte _08042254 @ case 0
	.4byte _08042338 @ case 1
	.4byte _080423A6 @ case 2
	.4byte _080423B6 @ case 3
	.4byte _080423CE @ case 4
_08042254:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	movs r0, #0x2f
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r6, [r0]
	ldr r0, _08042358 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080422C8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0804235C @ =gBossFnTable
	movs r0, #3
	strb r0, [r3, #9]
	ldr r0, [r1, #0xc]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r3, #0x5c]
	str r4, [r3, #0x28]
	movs r1, #1
	strb r1, [r3, #0x10]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	ands r0, r1
	eors r0, r6
	strb r0, [r3, #0x13]
_080422C8:
	ldr r1, _08042360 @ =0x0000A40A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r3, _08042364 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0804230A
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804230A
	ldr r0, _08042368 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804230A:
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0804236C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r0, #0x32
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042338:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08042370
	cmp r3, #1
	bne _08042374
	b _08042378
	.align 2, 0
_08042358: .4byte gBossHeaderPtr
_0804235C: .4byte gBossFnTable
_08042360: .4byte 0x0000A40A
_08042364: .4byte gStageRun
_08042368: .4byte 0x0000FFFE
_0804236C: .4byte 0xFFFFF000
_08042370:
	cmp r3, #0
	beq _08042378
_08042374:
	movs r0, #0xfa
	b _0804237A
_08042378:
	movs r0, #0xf6
_0804237A:
	muls r0, r2, r0
	cmp r0, #0
	bge _08042382
	adds r0, #0xff
_08042382:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804239E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804239E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080423CE
_080423A6:
	ldr r1, _080423D8 @ =0x08362084
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080423B6:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080423CE
	ldr r2, _080423DC @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080423CE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080423D8: .4byte 0x08362084
_080423DC: .4byte gStageRun
