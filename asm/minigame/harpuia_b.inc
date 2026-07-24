	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start harpuia_minigame_080fab10
harpuia_minigame_080fab10: @ 0x080FAB10
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FAB2C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080FAB44
	cmp r0, #1
	bgt _080FAB30
	cmp r0, #0
	beq _080FAB3A
	b _080FAB7E
	.align 2, 0
_080FAB2C: .4byte 0x00000DCC
_080FAB30:
	cmp r0, #2
	beq _080FAB58
	cmp r0, #3
	beq _080FAB6C
	b _080FAB7E
_080FAB3A:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAB44:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAB7E
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FAB7E
_080FAB58:
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0x1d
	bl PlaySound
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAB6C:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FAB7E
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FAB7E:
	ldr r1, _080FABE0 @ =0x0810E270
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintJISString
	ldrh r0, [r5, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrh r2, [r5, #0x38]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080FABB2
	str r4, [r5, #0x3c]
_080FABB2:
	add r4, sp, #8
	ldr r1, _080FABE4 @ =0x0810E278
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintJISString
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
_080FABE0: .4byte 0x0810E270
_080FABE4: .4byte 0x0810E278

	thumb_func_start harpuia_minigame_080fabe8
harpuia_minigame_080fabe8: @ 0x080FABE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sb, r0
	ldr r7, _080FAC34 @ =0x00000DCC
	add r7, sb
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	ldr r2, _080FAC38 @ =0x00000DC4
	add r2, sb
	ldr r0, [r2]
	ldr r1, [r7, #0x34]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r7, #0x30]
	ldr r1, [r7, #0x34]
	adds r0, r0, r1
	str r0, [r7, #0x30]
	ldr r1, _080FAC3C @ =0x0003BFFF
	cmp r0, r1
	ble _080FAC44
	ldr r0, [r2]
	ldr r1, _080FAC40 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r7, #0x30]
	adds r0, r0, r1
	str r0, [r7, #0x30]
	ldr r2, [r7, #0x14]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r2, #0x54]
	movs r0, #1
	b _080FAC46
	.align 2, 0
_080FAC34: .4byte 0x00000DCC
_080FAC38: .4byte 0x00000DC4
_080FAC3C: .4byte 0x0003BFFF
_080FAC40: .4byte 0xFFFC4000
_080FAC44:
	movs r0, #0
_080FAC46:
	strb r0, [r7, #0xd]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	ldr r0, [r7, #0x14]
	ldrb r0, [r0, #0xc]
	adds r1, r7, #0
	adds r1, #0x20
	str r1, [sp, #0x2c]
	add r2, sp, #8
	mov sl, r2
	cmp r0, #1
	bhi _080FAD1C
	movs r3, #0
	ldrsh r0, [r7, r3]
	mov r2, sb
	movs r3, #6
	ldrsh r1, [r2, r3]
	bl __modsi3
	cmp r0, #0
	bne _080FAD1C
	ldr r1, [r7, #0x30]
	ldr r0, _080FACFC @ =0x000365FF
	cmp r1, r0
	bgt _080FAD1C
	ldr r5, _080FAD00 @ =gGameState
	ldr r0, _080FAD04 @ =0x0000626C
	adds r5, r5, r0
	ldr r0, [r5]
	ldr r1, _080FAD08 @ =0x41C64E6D
	mov r8, r1
	mov r4, r8
	muls r4, r0, r4
	ldr r6, _080FAD0C @ =0x00003039
	adds r4, r4, r6
	str r4, [r5]
	lsrs r0, r4, #0x10
	movs r1, #0x28
	bl __umodsi3
	adds r0, #0x64
	mov r2, sb
	strh r0, [r2, #6]
	ldr r0, _080FAD10 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r3, #0xfa
	lsls r3, r3, #8
	adds r0, r0, r3
	str r0, [sp, #0x14]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r6
	str r0, [r5]
	lsrs r0, r0, #0x10
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r0, r0, #8
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r0, r1
	add r1, sp, #0x14
	str r0, [r1, #4]
	movs r5, #0
	ldr r4, [sp, #0x2c]
_080FACCC:
	ldr r0, [r4]
	cmp r0, #0
	bne _080FAD14
	adds r0, r7, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0809b064
	adds r1, r0, #0
	cmp r1, #0
	beq _080FAD1C
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #0x17
	strb r0, [r2]
	str r1, [r4]
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x28
	adds r0, r0, r1
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0]
	b _080FAD1C
	.align 2, 0
_080FACFC: .4byte 0x000365FF
_080FAD00: .4byte gGameState
_080FAD04: .4byte 0x0000626C
_080FAD08: .4byte 0x41C64E6D
_080FAD0C: .4byte 0x00003039
_080FAD10: .4byte pZero2
_080FAD14:
	adds r4, #4
	adds r5, #1
	cmp r5, #1
	ble _080FACCC
_080FAD1C:
	ldr r6, [sp, #0x2c]
	movs r5, #0
	adds r3, r6, #0
	adds r4, r7, #0
	adds r4, #0x28
	ldr r2, _080FAD3C @ =gEnemyFnTable
	mov r8, r2
_080FAD2A:
	ldr r0, [r3]
	cmp r0, #0
	beq _080FAD84
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FAD40
	str r5, [r3]
	strh r5, [r4]
	b _080FAD84
	.align 2, 0
_080FAD3C: .4byte gEnemyFnTable
_080FAD40:
	ldrh r0, [r4]
	cmp r0, #0
	beq _080FAD50
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAD84
_080FAD50:
	ldr r2, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	add r1, r8
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_080FAD84:
	adds r3, #4
	adds r4, #2
	adds r0, r6, #4
	cmp r3, r0
	ble _080FAD2A
	ldr r0, [r7, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080FAE18
	movs r3, #0
	ldrsh r0, [r7, r3]
	movs r1, #0xdc
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FADC4
	ldr r0, _080FAEA0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0x8c
	lsls r1, r1, #9
	adds r0, r0, r1
	str r0, [sp, #0x1c]
	movs r0, #0xf0
	lsls r0, r0, #8
	add r1, sp, #0x1c
	str r0, [r1, #4]
	adds r0, r7, #0
	movs r2, #0
	bl FUN_080b1990
_080FADC4:
	ldr r0, [r7, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080FAE18
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #0xa0
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAE18
	ldr r0, _080FAEA0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r3, #0x8c
	lsls r3, r3, #9
	adds r0, r0, r3
	str r0, [sp, #0x24]
	ldr r1, _080FAEA4 @ =gGameState
	ldr r0, _080FAEA8 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080FAEAC @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080FAEB0 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r0, r0, #8
	movs r3, #0xd0
	lsls r3, r3, #8
	adds r0, r0, r3
	add r1, sp, #0x24
	str r0, [r1, #4]
	adds r0, r7, #0
	movs r2, #0
	bl FUN_080b19ec
_080FAE18:
	ldr r1, _080FAEB4 @ =0x0810E270
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintJISString
	ldrh r0, [r7, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrh r2, [r7, #0x38]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r7, #0x3c]
	cmp r4, r0
	bls _080FAE5E
	str r4, [r7, #0x3c]
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne _080FAE5E
	movs r0, #1
	strh r0, [r7, #0x3a]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
_080FAE5E:
	ldr r1, _080FAEB8 @ =0x0810E278
	mov r0, sl
	movs r2, #9
	bl memcpy
	mov r0, sl
	movs r1, #0xf
	movs r2, #0
	bl PrintJISString
	ldr r4, [r7, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	ldrb r1, [r7, #0xc]
	cmp r1, #0
	bne _080FAE8C
	ldrh r0, [r7, #4]
	adds r0, #1
	strh r0, [r7, #4]
	strh r1, [r7, #6]
_080FAE8C:
	movs r0, #1
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FAEA0: .4byte pZero2
_080FAEA4: .4byte gGameState
_080FAEA8: .4byte 0x0000626C
_080FAEAC: .4byte 0x41C64E6D
_080FAEB0: .4byte 0x00003039
_080FAEB4: .4byte 0x0810E270
_080FAEB8: .4byte 0x0810E278

	thumb_func_start harpuia_minigame_080faebc
harpuia_minigame_080faebc: @ 0x080FAEBC
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FAED8 @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080FAF58
	lsls r0, r0, #2
	ldr r1, _080FAEDC @ =_080FAEE0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FAED8: .4byte 0x00000DCC
_080FAEDC: .4byte _080FAEE0
_080FAEE0: @ jump table
	.4byte _080FAEF8 @ case 0
	.4byte _080FAF02 @ case 1
	.4byte _080FAF10 @ case 2
	.4byte _080FAF24 @ case 3
	.4byte _080FAF34 @ case 4
	.4byte _080FAF40 @ case 5
_080FAEF8:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAF02:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FAF58
	b _080FAF2C
_080FAF10:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xb7
	bl FadeOutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAF24:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FAF58
_080FAF2C:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FAF58
_080FAF34:
	ldr r1, _080FAF54 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FAF40:
	ldr r0, _080FAF54 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FAF58
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080FAFB0
	.align 2, 0
_080FAF54: .4byte gGameState
_080FAF58:
	ldr r1, _080FAFB8 @ =0x0810E270
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintJISString
	ldrh r0, [r5, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrh r2, [r5, #0x38]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080FAF8C
	str r4, [r5, #0x3c]
_080FAF8C:
	add r4, sp, #8
	ldr r1, _080FAFBC @ =0x0810E278
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintJISString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	movs r0, #1
_080FAFB0:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FAFB8: .4byte 0x0810E270
_080FAFBC: .4byte 0x0810E278


