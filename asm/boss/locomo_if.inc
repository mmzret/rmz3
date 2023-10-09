	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start nop_0805474c
nop_0805474c: @ 0x0805474C
	bx lr
	.align 2, 0

	thumb_func_start tryKillLocomoIF
tryKillLocomoIF: @ 0x08054750
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0805476E
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080547A4
_0805476E:
	ldr r0, _0805479C @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _080547A4
	ldr r1, _080547A0 @ =gBossFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	strb r3, [r2, #0xd]
	adds r0, r2, #0
	bl LocomoIF_Die
	movs r0, #1
	b _080547A6
	.align 2, 0
_0805479C: .4byte gStageRun
_080547A0: .4byte gBossFnTable
_080547A4:
	movs r0, #0
_080547A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start LocomoIF_Init
LocomoIF_Init: @ 0x080547AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r1, _08054800 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _08054804 @ =0x08363B40
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
	ldr r0, _08054808 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x16]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08054810
	ldr r1, _0805480C @ =0x08363AF8
	adds r0, r7, #0
	movs r2, #0x30
	bl ResetBossBody
	b _0805481A
	.align 2, 0
_08054800: .4byte gBossFnTable
_08054804: .4byte 0x08363B40
_08054808: .4byte gSystemSavedataManager
_0805480C: .4byte 0x08363AF8
_08054810:
	ldr r1, _08054A18 @ =0x08363AF8
	adds r0, r7, #0
	movs r2, #0x20
	bl ResetBossBody
_0805481A:
	ldr r1, _08054A1C @ =nop_0805474c
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	movs r1, #0
	str r1, [r0]
	movs r4, #0x69
	lsls r5, r4, #2
	ldr r6, _08054A20 @ =gStaticMotionGraphics
	adds r0, r5, r6
	ldr r2, _08054A24 @ =wStaticGraphicTilenums
	mov sb, r2
	ldrh r1, [r2, #0x2a]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	ldr r1, _08054A2C @ =wStaticMotionPalIDs
	mov sl, r1
	ldrh r1, [r1, #0x2a]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	add r1, r8
	adds r0, r5, #0
	bl LoadPalette
	lsls r4, r4, #4
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xa8
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xa8
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _08054A30 @ =0x000006A4
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xaa
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xaa
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xd7
	lsls r4, r4, #3
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xac
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xac
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _08054A34 @ =0x000006CC
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0xae
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xae
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xdc
	lsls r4, r4, #3
	adds r6, r4, r6
	mov r0, sb
	adds r0, #0xb0
	ldrh r1, [r0]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	adds r0, r6, #0
	bl LoadGraphic
	ldr r0, _08054A28 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	mov r0, sl
	adds r0, #0xb0
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r7, #0x54]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x58]
	asrs r0, r0, #8
	str r0, [r7, #0x58]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	movs r2, #2
	bl CreateTopGabyoall
	adds r1, r7, #0
	adds r1, #0xc0
	str r0, [r1]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, _08054A38 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08054A3C @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #2
	movs r2, #2
	bl CreateTopGabyoall
	adds r1, r7, #0
	adds r1, #0xc4
	str r0, [r1]
	mov r0, sp
	movs r1, #3
	movs r2, #2
	bl CreateTopGabyoall
	adds r1, r7, #0
	adds r1, #0xc8
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb8
	movs r2, #0
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, r7, #0
	bl CreateLocomoIFPlatform
	adds r0, r7, #0
	bl LocomoIF_Update
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054A18: .4byte 0x08363AF8
_08054A1C: .4byte nop_0805474c
_08054A20: .4byte gStaticMotionGraphics
_08054A24: .4byte wStaticGraphicTilenums
_08054A28: .4byte gStaticMotionGraphics+12
_08054A2C: .4byte wStaticMotionPalIDs
_08054A30: .4byte 0x000006A4
_08054A34: .4byte 0x000006CC
_08054A38: .4byte gStageRun+232
_08054A3C: .4byte 0xFFFFB000

	thumb_func_start LocomoIF_Update
LocomoIF_Update: @ 0x08054A40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08054A5A
	bl isKilled
	cmp r0, #0
	beq _08054A82
	movs r0, #0
	b _08054A80
_08054A5A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08054A82
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08054A82
	ldr r2, _08054AB4 @ =0x08363B44
	movs r0, #0x17
	adds r1, r4, #0
	bl ApplyElementEffect
_08054A80:
	str r0, [r5]
_08054A82:
	adds r0, r4, #0
	bl tryKillLocomoIF
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08054AAE
	ldr r1, _08054AB8 @ =0x08363ABC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08054ABC @ =0x08363AD8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08054AAE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08054AB4: .4byte 0x08363B44
_08054AB8: .4byte 0x08363ABC
_08054ABC: .4byte 0x08363AD8

	thumb_func_start LocomoIF_Die
LocomoIF_Die: @ 0x08054AC0
	push {lr}
	ldr r2, _08054AD4 @ =0x08363AF4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08054AD4: .4byte 0x08363AF4

	thumb_func_start nop_08054ad8
nop_08054ad8: @ 0x08054AD8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08054adc
FUN_08054adc: @ 0x08054ADC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08054AEC
	cmp r0, #1
	beq _08054B00
	b _08054B1A
_08054AEC:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	movs r1, #0xa8
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054B00:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08054B14
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08054B14:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08054B1A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054b20
FUN_08054b20: @ 0x08054B20
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08054B54
	cmp r0, #1
	bgt _08054B34
	cmp r0, #0
	beq _08054B3E
	b _08054B8E
_08054B34:
	cmp r0, #2
	beq _08054B6E
	cmp r0, #3
	beq _08054B72
	b _08054B8E
_08054B3E:
	adds r0, r4, #0
	bl InitRotatableMotion
	movs r1, #0xa8
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054B54:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08054B66
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054B66:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08054B8E
_08054B6E:
	movs r0, #3
	strb r0, [r4, #0xe]
_08054B72:
	adds r1, r4, #0
	adds r1, #0xbd
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08054B94 @ =gStageRun
	ldrb r1, [r1, #0x12]
	ands r0, r1
	cmp r0, #0
	bne _08054B88
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08054B88:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08054B8E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054B94: .4byte gStageRun

	thumb_func_start FUN_08054b98
FUN_08054b98: @ 0x08054B98
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08054C7C
	lsls r0, r0, #2
	ldr r1, _08054BAC @ =_08054BB0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08054BAC: .4byte _08054BB0
_08054BB0: @ jump table
	.4byte _08054BC8 @ case 0
	.4byte _08054BE0 @ case 1
	.4byte _08054C04 @ case 2
	.4byte _08054C1C @ case 3
	.4byte _08054C44 @ case 4
	.4byte _08054C52 @ case 5
_08054BC8:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0
	str r0, [r1]
	str r0, [r4, #0x5c]
	ldr r0, _08054C00 @ =0x00000AAA
	bl Sqrt
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054BE0:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r4, #0x5c]
	adds r0, #0x18
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08054C34
	b _08054C2E
	.align 2, 0
_08054C00: .4byte 0x00000AAA
_08054C04:
	ldr r0, _08054C3C @ =0x00000AAA
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054C1C:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _08054C40 @ =0x000307FF
	cmp r0, r1
	bls _08054C34
_08054C2E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054C34:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08054C7C
	.align 2, 0
_08054C3C: .4byte 0x00000AAA
_08054C40: .4byte 0x000307FF
_08054C44:
	ldr r0, _08054C94 @ =0x00000AAA
	bl Sqrt
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054C52:
	ldr r1, [r4, #0x5c]
	subs r1, #0x18
	str r1, [r4, #0x5c]
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08054C76
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08054C76:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08054C7C:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _08054C98
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	lsrs r0, r0, #8
	rsbs r0, r0, #0
	b _08054CA0
	.align 2, 0
_08054C94: .4byte 0x00000AAA
_08054C98:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	lsrs r0, r0, #8
_08054CA0:
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08054cac
FUN_08054cac: @ 0x08054CAC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #4
	bls _08054CB8
	b _08054E8C
_08054CB8:
	lsls r0, r0, #2
	ldr r1, _08054CC8 @ =0x08054CCC
	adds r0, r0, r1
	ldr r0, [r0]
	adds r7, r6, #0
	adds r7, #0xbe
	mov pc, r0
	.align 2, 0
_08054CC8: .4byte 0x08054CCC
_08054CCC:
	.byte 0xE0, 0x4C, 0x05, 0x08
	.byte 0x4E, 0x4D, 0x05, 0x08, 0x7C, 0x4D, 0x05, 0x08, 0xDE, 0x4D, 0x05, 0x08, 0x1C, 0x4E, 0x05, 0x08
	.byte 0x96, 0x20, 0xAF, 0xF7, 0x5D, 0xFC, 0x30, 0x1C, 0x74, 0x30, 0x21, 0x49, 0xB2, 0xF7, 0x92, 0xFA
	.byte 0x31, 0x1C, 0x24, 0x31, 0x80, 0x20, 0x08, 0x70, 0x1E, 0x49, 0x30, 0x1C, 0xC2, 0xF7, 0x34, 0xFC
	.byte 0x30, 0x1C, 0xBE, 0x30, 0x01, 0x78, 0x07, 0x1C, 0x00, 0x29, 0x04, 0xD0, 0x38, 0x78, 0xAF, 0xF7
	.byte 0xD1, 0xF9, 0x00, 0x20, 0x38, 0x70, 0x35, 0x1C, 0xBC, 0x35, 0x2C, 0x78, 0x64, 0x04, 0xF5, 0x20
	.byte 0x00, 0x04, 0x24, 0x18, 0x24, 0x0C, 0x30, 0x1C, 0xC2, 0xF7, 0x64, 0xFE, 0x01, 0x1C, 0x09, 0x06
	.byte 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00, 0x10, 0x1C, 0x01, 0x43, 0x20, 0x1C, 0xAF, 0xF7, 0xF6, 0xF8
	.byte 0x28, 0x78, 0x40, 0x00, 0x0B, 0x38, 0x38, 0x70, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x38, 0x78
	.byte 0xAF, 0xF7, 0x8A, 0xF9, 0x30, 0x1C, 0xC2, 0xF7, 0x81, 0xFC, 0x30, 0x1C, 0x71, 0x30, 0x00, 0x78
	.byte 0x00, 0x06, 0x00, 0x16, 0x01, 0x28, 0x4C, 0xD1, 0x30, 0x1C, 0x74, 0x30, 0x02, 0x49, 0x46, 0xE0
	.byte 0xF8, 0x3A, 0x36, 0x08, 0x01, 0x54, 0x00, 0x00, 0x10, 0x3B, 0x36, 0x08, 0x30, 0x1C, 0x24, 0x30
	.byte 0x00, 0x24, 0x04, 0x70, 0x23, 0x49, 0x30, 0x1C, 0xC2, 0xF7, 0xEE, 0xFB, 0x30, 0x1C, 0xBE, 0x30
	.byte 0x01, 0x78, 0x07, 0x1C, 0x00, 0x29, 0x03, 0xD0, 0x38, 0x78, 0xAF, 0xF7, 0x8B, 0xF9, 0x3C, 0x70
	.byte 0x35, 0x1C, 0xBC, 0x35, 0x28, 0x78, 0x40, 0x00, 0xF7, 0x24, 0x24, 0x1A, 0x24, 0x04, 0x24, 0x0C
	.byte 0x30, 0x1C, 0xC2, 0xF7, 0x1F, 0xFE, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00
	.byte 0x10, 0x1C, 0x01, 0x43, 0x20, 0x1C, 0xAF, 0xF7, 0xB1, 0xF8, 0x29, 0x78, 0x49, 0x00, 0x09, 0x22
	.byte 0x52, 0x42, 0x10, 0x1C, 0x40, 0x1A, 0x38, 0x70, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x38, 0x78
	.byte 0xAF, 0xF7, 0x42, 0xF9, 0x30, 0x1C, 0xC2, 0xF7, 0x39, 0xFC, 0x30, 0x1C, 0x71, 0x30, 0x00, 0x78
	.byte 0x00, 0x06, 0x00, 0x16, 0x01, 0x28, 0x04, 0xD1, 0x30, 0x1C, 0x74, 0x30, 0x06, 0x49, 0xB2, 0xF7
	.byte 0x09, 0xFA, 0x30, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x3F, 0xD1, 0xB0, 0x7B, 0x01, 0x30
	.byte 0xB0, 0x73, 0x3B, 0xE0, 0x02, 0x54, 0x00, 0x00, 0xF8, 0x3A, 0x36, 0x08, 0xA8, 0x21, 0xC9, 0x01
	.byte 0x30, 0x1C, 0xC2, 0xF7, 0xA1, 0xFB, 0x37, 0x1C, 0xBE, 0x37, 0x38, 0x78, 0x00, 0x28, 0x03, 0xD0
	.byte 0xAF, 0xF7, 0x40, 0xF9, 0x00, 0x20, 0x38, 0x70, 0x35, 0x1C, 0xBC, 0x35, 0x28, 0x78, 0x40, 0x00
	.byte 0xF6, 0x24, 0x24, 0x1A, 0x24, 0x04, 0x24, 0x0C, 0x30, 0x1C, 0xC2, 0xF7, 0xD3, 0xFD, 0x01, 0x1C
	.byte 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00, 0x10, 0x1C, 0x01, 0x43, 0x20, 0x1C, 0xAF, 0xF7
	.byte 0x65, 0xF8, 0x28, 0x78, 0x40, 0x00, 0x0A, 0x22, 0x52, 0x42, 0x11, 0x1C, 0x09, 0x1A, 0x00, 0x24
	.byte 0x39, 0x70, 0x38, 0x78, 0xAF, 0xF7, 0xF8, 0xF8, 0x30, 0x1C, 0xC2, 0xF7, 0xEF, 0xFB, 0x28, 0x78
	.byte 0x01, 0x21, 0x48, 0x40, 0x28, 0x70, 0x05, 0x20, 0x70, 0x73, 0xB4, 0x73
_08054E8C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08054e94
FUN_08054e94: @ 0x08054E94
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08054EA8
	cmp r0, #1
	beq _08054ECA
	adds r2, r4, #0
	adds r2, #0xb8
	b _08054EF6
_08054EA8:
	movs r0, #0xaa
	bl Sqrt
	strb r0, [r4, #0x12]
	movs r0, #0xaa
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	rsbs r1, r1, #0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054ECA:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r4, #0x5c]
	adds r0, #0x18
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08054EF6
	movs r0, #0x80
	lsls r0, r0, #8
	str r0, [r2]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08054EF6:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _08054F08
	ldr r0, [r2]
	lsrs r0, r0, #8
	rsbs r0, r0, #0
	b _08054F0C
_08054F08:
	ldr r0, [r2]
	lsrs r0, r0, #8
_08054F0C:
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start locomoIF_08054f18
locomoIF_08054f18: @ 0x08054F18
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08054F44
	cmp r0, #1
	bgt _08054F2C
	cmp r0, #0
	beq _08054F36
	b _08054FC0
_08054F2C:
	cmp r0, #2
	beq _08054F7C
	cmp r0, #3
	beq _08054FA6
	b _08054FC0
_08054F36:
	ldr r1, _08054F74 @ =0x00005403
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054F44:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08054F5A
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054F5A:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08054FC0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08054F78 @ =0x08363B28
	bl SetDDP
	b _08054FC0
	.align 2, 0
_08054F74: .4byte 0x00005403
_08054F78: .4byte 0x08363B28
_08054F7C:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _08054F98
	ldr r1, _08054F94 @ =0x00005406
	adds r0, r4, #0
	bl SetMotion
	b _08054FA0
	.align 2, 0
_08054F94: .4byte 0x00005406
_08054F98:
	ldr r1, _08054FC8 @ =0x00005407
	adds r0, r4, #0
	bl SetMotion
_08054FA0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08054FA6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08054FBA
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08054FBA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08054FC0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054FC8: .4byte 0x00005407

	thumb_func_start FUN_08054fcc
FUN_08054fcc: @ 0x08054FCC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0805501E
	cmp r0, #1
	bgt _08054FE0
	cmp r0, #0
	beq _08054FEA
	b _080550DC
_08054FE0:
	cmp r0, #2
	beq _080550A0
	cmp r0, #3
	beq _080550AE
	b _080550DC
_08054FEA:
	ldr r1, _08055008 @ =0x00005404
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x5a
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _08055010
	ldr r0, _0805500C @ =0x00000129
	bl PlaySound
	b _08055018
	.align 2, 0
_08055008: .4byte 0x00005404
_0805500C: .4byte 0x00000129
_08055010:
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound
_08055018:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805501E:
	ldrb r0, [r5, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08055082
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _08055060
	ldr r0, [r5, #0x54]
	ldr r2, _0805505C @ =0xFFFFF400
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	adds r1, r1, r2
	movs r2, #0
	bl FUN_080a7c60
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0805505C @ =0xFFFFF400
	adds r1, r1, r2
	movs r2, #1
	bl FUN_080a7c60
	b _08055082
	.align 2, 0
_0805505C: .4byte 0xFFFFF400
_08055060:
	ldr r0, [r5, #0x54]
	ldr r1, _0805509C @ =0xFFFFF400
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r4, #0xc0
	lsls r4, r4, #4
	adds r1, r1, r4
	movs r2, #0
	bl FUN_080a7cb0
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	movs r2, #1
	bl FUN_080a7cb0
_08055082:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08055094
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08055094:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080550DC
	.align 2, 0
_0805509C: .4byte 0xFFFFF400
_080550A0:
	ldr r1, _080550E4 @ =0x00005405
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080550AE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080550C4
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_080550C4:
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080550DC
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080550E8 @ =0x08363AF8
	bl SetDDP
_080550DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080550E4: .4byte 0x00005405
_080550E8: .4byte 0x08363AF8

	thumb_func_start locomoIF_080550ec
locomoIF_080550ec: @ 0x080550EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bls _08055102
	b _0805531C
_08055102:
	lsls r0, r0, #2
	ldr r1, _0805510C @ =_08055110
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805510C: .4byte _08055110
_08055110: @ jump table
	.4byte _08055124 @ case 0
	.4byte _080551D2 @ case 1
	.4byte _080551FC @ case 2
	.4byte _08055206 @ case 3
	.4byte _08055314 @ case 4
_08055124:
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080551EC @ =0x00005408
	adds r0, r7, #0
	bl SetMotion
	adds r4, r7, #0
	adds r4, #0xbe
	ldrb r0, [r4]
	cmp r0, #0
	beq _08055144
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_08055144:
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _08055156
	adds r1, r0, #0
	adds r1, #0xc2
	movs r0, #1
	strb r0, [r1]
_08055156:
	adds r0, r7, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	beq _08055168
	adds r1, r0, #0
	adds r1, #0xc2
	movs r0, #1
	strb r0, [r1]
_08055168:
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	cmp r0, #0
	beq _0805517A
	adds r1, r0, #0
	adds r1, #0xc2
	movs r0, #1
	strb r0, [r1]
_0805517A:
	ldr r3, _080551F0 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _0805519C
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0805519C
	ldr r0, _080551F4 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805519C:
	adds r0, r7, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldr r2, _080551F8 @ =0x08363B4C
	adds r0, r7, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080551D2:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080551E4
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080551E4:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _0805531C
	.align 2, 0
_080551EC: .4byte 0x00005408
_080551F0: .4byte gStageRun
_080551F4: .4byte 0x0000FFFE
_080551F8: .4byte 0x08363B4C
_080551FC:
	movs r0, #0xc8
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08055206:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x12]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080552C0
	ldr r1, [r7, #0x54]
	ldr r5, _080552F8 @ =0xFFFFE000
	adds r1, r1, r5
	ldr r2, _080552FC @ =RNG_0202f388
	ldr r0, [r2]
	ldr r4, _08055300 @ =0x000343FD
	muls r0, r4, r0
	ldr r2, _08055304 @ =0x00269EC3
	mov r8, r2
	add r0, r8
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	ldr r3, _08055308 @ =0x00003FFF
	ands r0, r3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r2, [r7, #0x58]
	add r0, sp, #8
	mov sb, r0
	adds r2, r2, r5
	ldr r1, _08055300 @ =0x000343FD
	adds r0, r4, #0
	muls r0, r1, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	ldr r4, _080552FC @ =RNG_0202f388
	str r1, [r4]
	lsrs r0, r0, #0x11
	ands r0, r3
	adds r0, r0, r2
	mov r1, sb
	str r0, [r1, #4]
	movs r0, #1
	bl CreateSmoke
	ldr r4, [r7, #0x54]
	ldr r2, _0805530C @ =0xFFFFE800
	mov sl, r2
	add r4, sl
	str r4, [sp, #8]
	ldr r1, _080552FC @ =RNG_0202f388
	ldr r0, [r1]
	ldr r2, _08055300 @ =0x000343FD
	muls r0, r2, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r1]
	lsrs r0, r0, #0x11
	movs r6, #0xc0
	lsls r6, r6, #6
	adds r1, r6, #0
	bl __umodsi3
	adds r4, r4, r0
	str r4, [sp, #8]
	ldr r4, [r7, #0x58]
	add r4, sl
	mov r0, sb
	str r4, [r0, #4]
	ldr r1, _08055300 @ =0x000343FD
	adds r0, r5, #0
	muls r0, r1, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	ldr r2, _080552FC @ =RNG_0202f388
	str r1, [r2]
	lsrs r0, r0, #0x11
	adds r1, r6, #0
	bl __umodsi3
	adds r4, r4, r0
	mov r0, sb
	str r4, [r0, #4]
	ldr r1, [sp, #8]
	adds r0, r7, #0
	adds r2, r4, #0
	bl CreateVFX51
_080552C0:
	ldrb r0, [r7, #0x12]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080552D4
	movs r0, #0x2a
	bl PlaySound
_080552D4:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _0805531C
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0xe
	bl TryDropItem
	ldr r2, _08055310 @ =gStageRun
	ldrb r0, [r2, #0x12]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0805531C
	.align 2, 0
_080552F8: .4byte 0xFFFFE000
_080552FC: .4byte RNG_0202f388
_08055300: .4byte 0x000343FD
_08055304: .4byte 0x00269EC3
_08055308: .4byte 0x00003FFF
_0805530C: .4byte 0xFFFFE800
_08055310: .4byte gStageRun
_08055314:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
_0805531C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
