	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start copyx_minigame_080fa560
copyx_minigame_080fa560: @ 0x080FA560
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FA57C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080FA594
	cmp r0, #1
	bgt _080FA580
	cmp r0, #0
	beq _080FA58A
	b _080FA5CE
	.align 2, 0
_080FA57C: .4byte 0x00000DCC
_080FA580:
	cmp r0, #2
	beq _080FA5A8
	cmp r0, #3
	beq _080FA5BC
	b _080FA5CE
_080FA58A:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA594:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FA5CE
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FA5CE
_080FA5A8:
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0x1d
	bl PlaySound
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA5BC:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FA5CE
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FA5CE:
	ldr r1, _080FA624 @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA5F6
	str r4, [r5, #0x24]
_080FA5F6:
	add r4, sp, #8
	ldr r1, _080FA628 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl PrintMinigameNumber
	movs r0, #1
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA624: .4byte 0x0810E25C
_080FA628: .4byte 0x0810E264

	thumb_func_start copyx_minigame_080fa62c
copyx_minigame_080fa62c: @ 0x080FA62C
	push {r4, r5, lr}
	sub sp, #0x1c
	ldr r1, _080FA6AC @ =0x00000DCC
	adds r5, r0, r1
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #2
	ldrsh r1, [r5, r3]
	bl __modsi3
	adds r4, r0, #0
	cmp r4, #0
	bne _080FA6E8
	ldr r1, _080FA6B0 @ =gGameState
	ldr r0, _080FA6B4 @ =0x0000626C
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r3, _080FA6B8 @ =0x41C64E6D
	muls r0, r3, r0
	ldr r2, _080FA6BC @ =0x00003039
	adds r0, r0, r2
	muls r0, r3, r0
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [sp, #0x14]
	movs r0, #0xf0
	lsls r0, r0, #8
	add r1, sp, #0x14
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r0, r0, r3
	str r0, [sp, #0x14]
	ldr r0, [r1, #4]
	ldr r3, _080FA6C0 @ =0xFFFFD000
	adds r0, r0, r3
	str r0, [r1, #4]
	adds r0, r5, #0
	bl FUN_080b1934
	ldr r0, [r5, #0x20]
	adds r0, #1
	str r0, [r5, #0x20]
	strh r4, [r5]
	cmp r0, #3
	bhi _080FA6C4
	movs r0, #0x78
	b _080FA6E6
	.align 2, 0
_080FA6AC: .4byte 0x00000DCC
_080FA6B0: .4byte gGameState
_080FA6B4: .4byte 0x0000626C
_080FA6B8: .4byte 0x41C64E6D
_080FA6BC: .4byte 0x00003039
_080FA6C0: .4byte 0xFFFFD000
_080FA6C4:
	cmp r0, #0xb
	bhi _080FA6CC
	movs r0, #0x70
	b _080FA6E6
_080FA6CC:
	cmp r0, #0x17
	bhi _080FA6D4
	movs r0, #0x68
	b _080FA6E6
_080FA6D4:
	cmp r0, #0x1f
	bhi _080FA6DC
	movs r0, #0x60
	b _080FA6E6
_080FA6DC:
	cmp r0, #0x2f
	bhi _080FA6E4
	movs r0, #0x58
	b _080FA6E6
_080FA6E4:
	movs r0, #0x46
_080FA6E6:
	strh r0, [r5, #2]
_080FA6E8:
	ldr r1, _080FA75C @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA722
	str r4, [r5, #0x24]
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne _080FA722
	movs r0, #1
	strh r0, [r5, #0xe]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
_080FA722:
	add r4, sp, #8
	ldr r1, _080FA760 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl PrintMinigameNumber
	ldrb r1, [r5, #0xc]
	cmp r1, #0
	bne _080FA752
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FA752:
	movs r0, #1
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA75C: .4byte 0x0810E25C
_080FA760: .4byte 0x0810E264

	thumb_func_start copyx_minigame_080fa764
copyx_minigame_080fa764: @ 0x080FA764
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FA780 @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080FA800
	lsls r0, r0, #2
	ldr r1, _080FA784 @ =_080FA788
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FA780: .4byte 0x00000DCC
_080FA784: .4byte _080FA788
_080FA788: @ jump table
	.4byte _080FA7A0 @ case 0
	.4byte _080FA7AA @ case 1
	.4byte _080FA7B8 @ case 2
	.4byte _080FA7CC @ case 3
	.4byte _080FA7DC @ case 4
	.4byte _080FA7E8 @ case 5
_080FA7A0:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7AA:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FA800
	b _080FA7D4
_080FA7B8:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xb3
	bl fadeoutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7CC:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FA800
_080FA7D4:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FA800
_080FA7DC:
	ldr r1, _080FA7FC @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7E8:
	ldr r0, _080FA7FC @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FA800
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080FA84C
	.align 2, 0
_080FA7FC: .4byte gGameState
_080FA800:
	ldr r1, _080FA854 @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA828
	str r4, [r5, #0x24]
_080FA828:
	add r4, sp, #8
	ldr r1, _080FA858 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl PrintMinigameNumber
	movs r0, #1
_080FA84C:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA854: .4byte 0x0810E25C
_080FA858: .4byte 0x0810E264

