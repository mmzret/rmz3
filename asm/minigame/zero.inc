	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initZeroMinigame
initZeroMinigame: @ 0x080F91E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r7, _080F9384 @ =0x00000DCC
	add r7, sl
	ldr r1, _080F9388 @ =0x00000DC4
	add r1, sl
	ldr r0, _080F938C @ =0x002E6800
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r1, #4]
	movs r0, #3
	bl ResetLandscape
	ldr r4, _080F9390 @ =0x0000058C
	ldr r1, _080F9394 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080F9398 @ =wStaticGraphicTilenums
	adds r1, #0x8e
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080F939C @ =gStaticMotionGraphics+12
	mov r8, r0
	add r4, r8
	ldr r6, _080F93A0 @ =wStaticMotionPalIDs
	adds r0, r6, #0
	adds r0, #0x8e
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
	movs r4, #0x9e
	lsls r5, r4, #1
	ldr r1, _080F9398 @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xe1
	lsls r1, r1, #2
	strh r1, [r0]
	adds r5, r6, r5
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r4, r4, r2
	ldr r2, _080F9394 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xf0
	ldr r0, _080F9398 @ =wStaticGraphicTilenums
	strh r1, [r0]
	movs r0, #0xe
	strh r0, [r6]
	ldr r2, _080F9394 @ =gStaticMotionGraphics
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r2, #0
	bl LoadGraphic
	ldrh r1, [r6]
	mov r2, r8
	ldrb r0, [r2, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	mov r0, r8
	bl LoadPalette
	ldr r0, _080F938C @ =0x002E6800
	str r0, [sp, #4]
	movs r0, #0xb4
	lsls r0, r0, #8
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	bl CreateZeroMini
	str r0, [r7, #0x14]
	ldr r1, _080F93A4 @ =pZero2
	str r0, [r1]
	movs r1, #0
	add r6, sp, #4
	movs r5, #0x80
	lsls r5, r5, #5
_080F92E2:
	adds r4, r1, #1
	ldr r0, _080F93A8 @ =0x002ED800
	subs r0, r0, r5
	str r0, [sp, #4]
	movs r0, #0x94
	lsls r0, r0, #9
	str r0, [r6, #4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	adds r3, r7, #0
	adds r3, #0xc
	bl FUN_080c82b8
	movs r1, #0x80
	lsls r1, r1, #5
	adds r5, r5, r1
	adds r1, r4, #0
	cmp r1, #2
	ble _080F92E2
	movs r4, #0
	movs r0, #3
	strb r0, [r7, #0xc]
	movs r5, #0
	strh r4, [r7]
	movs r0, #0x60
	mov r2, sl
	strh r0, [r2, #6]
	ldr r1, _080F93AC @ =gGameState
	ldr r0, _080F93B0 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080F93B4 @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080F93B8 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __umodsi3
	mov r1, sl
	strh r0, [r1, #8]
	strh r4, [r1, #0xa]
	strh r4, [r7, #4]
	strh r4, [r7, #6]
	strh r4, [r7, #8]
	strh r4, [r7, #0xa]
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	str r4, [r7, #0x30]
	str r4, [r7, #0x2c]
	strh r4, [r7, #0x38]
	movs r0, #0xe0
	lsls r0, r0, #1
	str r0, [r7, #0x34]
	strb r5, [r7, #0xd]
	strh r4, [r7, #0xe]
	str r4, [r7, #0x20]
	str r4, [r7, #0x24]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	strh r4, [r1, #4]
	ldr r0, _080F93BC @ =gSystemSavedataManager
	ldr r0, [r0, #0x24]
	str r0, [r7, #0x3c]
	strh r4, [r7, #0x3a]
	movs r0, #0xad
	bl playBGM
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F9384: .4byte 0x00000DCC
_080F9388: .4byte 0x00000DC4
_080F938C: .4byte 0x002E6800
_080F9390: .4byte 0x0000058C
_080F9394: .4byte gStaticMotionGraphics
_080F9398: .4byte wStaticGraphicTilenums
_080F939C: .4byte gStaticMotionGraphics+12
_080F93A0: .4byte wStaticMotionPalIDs
_080F93A4: .4byte pZero2
_080F93A8: .4byte 0x002ED800
_080F93AC: .4byte gGameState
_080F93B0: .4byte 0x0000626C
_080F93B4: .4byte 0x41C64E6D
_080F93B8: .4byte 0x00003039
_080F93BC: .4byte gSystemSavedataManager

	thumb_func_start zeroMinigame
zeroMinigame: @ 0x080F93C0
	push {lr}
	ldr r2, _080F93DC @ =0x00000DCC
	adds r1, r0, r2
	ldr r2, _080F93E0 @ =0x08386AEC
	movs r3, #4
	ldrsh r1, [r1, r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_080F93DC: .4byte 0x00000DCC
_080F93E0: .4byte 0x08386AEC

	thumb_func_start zeroMinigamePhase0
zeroMinigamePhase0: @ 0x080F93E4
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080F9400 @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080F9418
	cmp r0, #1
	bgt _080F9404
	cmp r0, #0
	beq _080F940E
	b _080F9452
	.align 2, 0
_080F9400: .4byte 0x00000DCC
_080F9404:
	cmp r0, #2
	beq _080F942C
	cmp r0, #3
	beq _080F9440
	b _080F9452
_080F940E:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F9418:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080F9452
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080F9452
_080F942C:
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0x1d
	bl PlaySound
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F9440:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080F9452
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080F9452:
	ldr r1, _080F94A8 @ =0x0810E248
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r4, [r5, #0x38]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080F947A
	str r4, [r5, #0x3c]
_080F947A:
	add r4, sp, #8
	ldr r1, _080F94AC @ =0x0810E250
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	movs r0, #1
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080F94A8: .4byte 0x0810E248
_080F94AC: .4byte 0x0810E250

	thumb_func_start zeroMinigamePhase1
zeroMinigamePhase1: @ 0x080F94B0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r0, _080F94E8 @ =0x00000DCC
	adds r5, r4, r0
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldr r1, [r5, #0x30]
	ldr r0, _080F94EC @ =0x0003BFFF
	cmp r1, r0
	ble _080F94F8
	ldr r1, _080F94F0 @ =0x00000DC4
	adds r2, r4, r1
	ldr r0, [r2]
	ldr r1, _080F94F4 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r5, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x30]
	ldr r2, [r5, #0x14]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r2, #0x54]
	movs r0, #1
	b _080F94FA
	.align 2, 0
_080F94E8: .4byte 0x00000DCC
_080F94EC: .4byte 0x0003BFFF
_080F94F0: .4byte 0x00000DC4
_080F94F4: .4byte 0xFFFC4000
_080F94F8:
	movs r0, #0
_080F94FA:
	strb r0, [r5, #0xd]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r0, [r5, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080F950C
	b _080F96D4
_080F950C:
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #6
	ldrsh r1, [r4, r3]
	bl __modsi3
	cmp r0, #0
	beq _080F951E
	b _080F96D4
_080F951E:
	ldrh r6, [r5, #0xe]
	adds r0, r6, #1
	movs r1, #0xa
	bl __modsi3
	cmp r0, #0
	bne _080F95C4
	ldr r1, _080F9574 @ =gGameState
	ldr r0, _080F9578 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080F957C @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080F9580 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	adds r0, #2
	strh r0, [r4, #8]
	ands r0, r1
	cmp r0, #0
	beq _080F958C
	ldr r1, _080F9584 @ =Coord_ARRAY_08386af8
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _080F9588 @ =0x002EE000
	adds r0, r0, r2
	str r0, [sp, #0x14]
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	b _080F95B0
	.align 2, 0
_080F9574: .4byte gGameState
_080F9578: .4byte 0x0000626C
_080F957C: .4byte 0x41C64E6D
_080F9580: .4byte 0x00003039
_080F9584: .4byte Coord_ARRAY_08386af8
_080F9588: .4byte 0x002EE000
_080F958C:
	ldr r1, _080F95BC @ =Coord_ARRAY_08386af8
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F95C0 @ =0x002DF000
	adds r0, r0, r3
	str r0, [sp, #0x14]
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r0, r3
_080F95B0:
	add r1, sp, #0x14
	str r0, [r1, #4]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #1
	b _080F9654
	.align 2, 0
_080F95BC: .4byte Coord_ARRAY_08386af8
_080F95C0: .4byte 0x002DF000
_080F95C4:
	adds r0, r6, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080F95EE
	ldr r1, _080F960C @ =gGameState
	ldr r0, _080F9610 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080F9614 @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080F9618 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __umodsi3
	strh r0, [r4, #8]
_080F95EE:
	ldrh r1, [r4, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080F9624
	ldr r1, _080F961C @ =Coord_ARRAY_08386af8
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _080F9620 @ =0x002EE000
	adds r0, r0, r2
	b _080F9634
	.align 2, 0
_080F960C: .4byte gGameState
_080F9610: .4byte 0x0000626C
_080F9614: .4byte 0x41C64E6D
_080F9618: .4byte 0x00003039
_080F961C: .4byte Coord_ARRAY_08386af8
_080F9620: .4byte 0x002EE000
_080F9624:
	ldr r1, _080F9678 @ =Coord_ARRAY_08386af8
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F967C @ =0x002DF000
	adds r0, r0, r3
_080F9634:
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r2, #4]
	adds r1, r2, #0
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
_080F9654:
	bl FUN_0809aff0
	adds r2, r0, #0
	cmp r2, #0
	beq _080F96D4
	ldrh r1, [r4, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080F9688
	ldr r1, _080F9680 @ =Coord_ARRAY_08386b28
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F9684 @ =0x002EE000
	b _080F9696
	.align 2, 0
_080F9678: .4byte Coord_ARRAY_08386af8
_080F967C: .4byte 0x002DF000
_080F9680: .4byte Coord_ARRAY_08386b28
_080F9684: .4byte 0x002EE000
_080F9688:
	ldr r1, _080F96C0 @ =Coord_ARRAY_08386b28
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _080F96C4 @ =0x002DF000
_080F9696:
	adds r0, r0, r3
	str r0, [r2, #0x64]
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r2, #0x68]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _080F96C8
	movs r0, #0x58
	b _080F96D2
	.align 2, 0
_080F96C0: .4byte Coord_ARRAY_08386b28
_080F96C4: .4byte 0x002DF000
_080F96C8:
	cmp r0, #0x27
	bhi _080F96D0
	movs r0, #0x4c
	b _080F96D2
_080F96D0:
	movs r0, #0x40
_080F96D2:
	strh r0, [r4, #6]
_080F96D4:
	ldr r1, _080F9748 @ =0x0810E248
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r4, [r5, #0x38]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080F970E
	str r4, [r5, #0x3c]
	ldrh r0, [r5, #0x3a]
	cmp r0, #0
	bne _080F970E
	movs r0, #1
	strh r0, [r5, #0x3a]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
_080F970E:
	add r4, sp, #8
	ldr r1, _080F974C @ =0x0810E250
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	ldrb r1, [r5, #0xc]
	cmp r1, #0
	bne _080F973E
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080F973E:
	movs r0, #1
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080F9748: .4byte 0x0810E248
_080F974C: .4byte 0x0810E250

	thumb_func_start zeroMinigamePhase2
zeroMinigamePhase2: @ 0x080F9750
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080F976C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080F97EC
	lsls r0, r0, #2
	ldr r1, _080F9770 @ =_080F9774
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F976C: .4byte 0x00000DCC
_080F9770: .4byte _080F9774
_080F9774: @ jump table
	.4byte _080F978C @ case 0
	.4byte _080F9796 @ case 1
	.4byte _080F97A4 @ case 2
	.4byte _080F97B8 @ case 3
	.4byte _080F97C8 @ case 4
	.4byte _080F97D4 @ case 5
_080F978C:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F9796:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080F97EC
	b _080F97C0
_080F97A4:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xad
	bl fadeoutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F97B8:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080F97EC
_080F97C0:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080F97EC
_080F97C8:
	ldr r1, _080F97E8 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F97D4:
	ldr r0, _080F97E8 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080F97EC
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080F9838
	.align 2, 0
_080F97E8: .4byte gGameState
_080F97EC:
	ldr r1, _080F9840 @ =0x0810E248
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldrh r4, [r5, #0x38]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080F9814
	str r4, [r5, #0x3c]
_080F9814:
	add r4, sp, #8
	ldr r1, _080F9844 @ =0x0810E250
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	movs r0, #1
_080F9838:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080F9840: .4byte 0x0810E248
_080F9844: .4byte 0x0810E250

