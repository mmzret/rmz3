	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ReactorCore_Init
ReactorCore_Init: @ 0x08061758
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r1, [r7, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldr r0, _080618CC @ =0x083656C8
	str r0, [r7, #0x30]
	movs r2, #1
	strh r2, [r7, #0x26]
	ldr r1, _080618D0 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _080618D4 @ =0x083656D0
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r1, [r7, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r4, #0
_0806179C:
	adds r0, r7, #0
	adds r0, #0xb4
	adds r0, r0, r4
	movs r1, #7
	strb r1, [r0]
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	ldrb r2, [r7, #0x10]
	adds r0, r7, #0
	bl FUN_080935b4
	adds r4, #1
	cmp r4, #5
	ble _0806179C
	adds r0, r7, #0
	adds r0, #0xbc
	movs r1, #0
	str r1, [r0]
	ldr r5, _080618D8 @ =0x00000ADC
	ldr r2, _080618DC @ =gStaticMotionGraphics
	mov sb, r2
	adds r0, r5, r2
	ldr r1, _080618E0 @ =wStaticGraphicTilenums
	mov r8, r1
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080618E4 @ =gStaticMotionGraphics+12
	mov sl, r0
	add r5, sl
	ldr r6, _080618E8 @ =wStaticMotionPalIDs
	adds r4, r6, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r5, #0
	bl LoadPalette
	ldr r4, _080618EC @ =0x0000053C
	add sb, r4
	movs r0, #0x86
	add r8, r0
	mov r2, r8
	ldrh r1, [r2]
	mov r2, sb
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, sb
	bl LoadGraphic
	add r4, sl
	adds r6, #0x86
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080618F0 @ =0x083656B0
	adds r0, r7, #0
	movs r2, #1
	bl ResetBossBody
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r1, _080618F4 @ =0xFFFFE800
	adds r0, r0, r1
	ldrb r2, [r7, #0x10]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0xb
	subs r0, r0, r1
	str r0, [r7, #0x58]
	adds r5, r7, #0
	adds r5, #0x22
	movs r2, #0
	strb r2, [r5]
	movs r4, #0x8b
	lsls r4, r4, #8
	adds r0, r7, #0
	adds r1, r4, #0
	bl SetMotion
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	movs r0, #0xcb
	bl LoadBlink
	movs r0, #1
	strb r0, [r5]
	adds r0, r7, #0
	adds r1, r4, #0
	bl SetMotion
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	movs r0, #0xcc
	bl LoadBlink
	movs r0, #0xe0
	bl PlaySound
	adds r0, r7, #0
	bl ReactorCore_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080618CC: .4byte 0x083656C8
_080618D0: .4byte gBossFnTable
_080618D4: .4byte 0x083656D0
_080618D8: .4byte 0x00000ADC
_080618DC: .4byte gStaticMotionGraphics
_080618E0: .4byte wStaticGraphicTilenums
_080618E4: .4byte gStaticMotionGraphics+12
_080618E8: .4byte wStaticMotionPalIDs
_080618EC: .4byte 0x0000053C
_080618F0: .4byte 0x083656B0
_080618F4: .4byte 0xFFFFE800

	thumb_func_start ReactorCore_Update
ReactorCore_Update: @ 0x080618F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0xcb
	bl UpdateBlinkMotionState
	movs r0, #0xcc
	bl UpdateBlinkMotionState
	ldr r2, _080619D8 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080619A2
	ldrb r0, [r7, #0x10]
	str r0, [sp]
	cmp r0, #1
	bne _080619A2
	adds r6, r7, #0
	adds r6, #0xbc
	ldr r0, [r6]
	cmp r0, #0
	bne _0806199C
	movs r0, #0x5a
	str r0, [r6]
	adds r2, #0xe8
	mov r8, r2
	ldr r5, [r2, #0x38]
	ldr r1, _080619DC @ =0xFFFFA000
	adds r5, r5, r1
	ldr r2, _080619E0 @ =RNG_0202f388
	ldr r0, [r2]
	ldr r3, _080619E4 @ =0x000343FD
	mov sl, r3
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r4, _080619E8 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r2, r0, #1
	mov sb, r2
	ldr r3, _080619E0 @ =RNG_0202f388
	str r2, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #8
	bl __umodsi3
	adds r5, r5, r0
	mov r0, r8
	ldr r1, [r0, #0x3c]
	ldr r2, _080619EC @ =0xFFFFD000
	adds r1, r1, r2
	mov r3, sl
	mov r0, sb
	muls r0, r3, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsls r0, r0, #1
	lsrs r0, r0, #0x12
	adds r1, r1, r0
	mov r0, sl
	muls r0, r2, r0
	adds r2, r0, #0
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r0, r2, #1
	ldr r3, _080619E0 @ =RNG_0202f388
	str r0, [r3]
	lsrs r2, r2, #0x11
	ldr r0, [sp]
	ands r2, r0
	adds r0, r5, #0
	bl FUN_0807cbf4
_0806199C:
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
_080619A2:
	movs r3, #0
	movs r1, #0
	adds r2, r7, #0
	adds r2, #0xb4
_080619AA:
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r3, r3, r0
	adds r1, #1
	cmp r1, #5
	ble _080619AA
	cmp r3, #0
	bne _080619F4
	ldr r1, _080619F0 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	strb r3, [r7, #0xd]
	adds r0, r7, #0
	bl ReactorCore_Die
	b _08061A14
	.align 2, 0
_080619D8: .4byte gStageRun
_080619DC: .4byte 0xFFFFA000
_080619E0: .4byte RNG_0202f388
_080619E4: .4byte 0x000343FD
_080619E8: .4byte 0x00269EC3
_080619EC: .4byte 0xFFFFD000
_080619F0: .4byte gBossFnTable
_080619F4:
	ldr r1, _08061A24 @ =0x0836569C
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	ldr r1, _08061A28 @ =0x083656A4
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_08061A14:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061A24: .4byte 0x0836569C
_08061A28: .4byte 0x083656A4

	thumb_func_start ReactorCore_Die
ReactorCore_Die: @ 0x08061A2C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xcb
	bl UpdateBlinkMotionState
	movs r0, #0xcc
	bl UpdateBlinkMotionState
	ldr r1, _08061A54 @ =0x083656AC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061A54: .4byte 0x083656AC

	thumb_func_start ReactorCore_Disappear
ReactorCore_Disappear: @ 0x08061A58
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xcb
	bl ClearBlink
	movs r0, #0xcc
	bl ClearBlink
	adds r0, r4, #0
	bl DeleteBoss
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_08061a74
nop_08061a74: @ 0x08061A74
	bx lr
	.align 2, 0

	thumb_func_start FUN_08061a78
FUN_08061a78: @ 0x08061A78
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08061A88
	cmp r0, #1
	beq _08061A98
	b _08061A9E
_08061A88:
	movs r1, #0x8b
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061A98:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08061A9E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08061aa4
FUN_08061aa4: @ 0x08061AA4
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0xe]
	cmp r1, #0
	beq _08061AB4
	cmp r1, #1
	beq _08061AC6
	b _08061AD4
_08061AB4:
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08061AD4
	strb r3, [r2, #0xe]
	b _08061AD4
_08061AC6:
	ldr r0, _08061AD8 @ =gStageRun
	ldrb r0, [r0, #0x12]
	ands r0, r1
	cmp r0, #0
	bne _08061AD4
	strb r0, [r2, #0xd]
	strb r0, [r2, #0xe]
_08061AD4:
	pop {r0}
	bx r0
	.align 2, 0
_08061AD8: .4byte gStageRun

	thumb_func_start FUN_08061adc
FUN_08061adc: @ 0x08061ADC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08061AEC
	cmp r5, #1
	beq _08061B3C
	b _08061B58
_08061AEC:
	movs r0, #0xe0
	bl stopSound
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r3, _08061B60 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _08061B32
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08061B32
	ldr r0, _08061B64 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08061B32:
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061B3C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08061B58
	ldr r2, _08061B60 @ =gStageRun
	ldrb r0, [r2, #0x12]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061B58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08061B60: .4byte gStageRun
_08061B64: .4byte 0x0000FFFE
