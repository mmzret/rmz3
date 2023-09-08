	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r0, _08001A70 @ =gSystemBuffer
	mov r8, r0
	movs r1, #0x90
	lsls r1, r1, #5
	add r1, r8
	mov sl, r1
	ldr r7, _08001A74 @ =0x030016F5
	subs r6, r7, #1
_08001994:
	bl PrintAllStrings
	bl ExecBlink
	movs r2, #0
	ldr r1, _08001A78 @ =0x00001202
	add r1, r8
	ldrh r0, [r1]
	cmp r0, #0
	bne _080019AA
	movs r2, #1
_080019AA:
	movs r0, #0
	strh r2, [r1]
	mov r3, sl
	strh r0, [r3]
	bl sramScript
_080019B6:
	ldrb r1, [r6]
	ldrb r0, [r7]
	cmp r1, r0
	blo _080019B6
	ldr r0, _08001A7C @ =0x04000006
	ldrh r0, [r0]
	cmp r0, #0xa1
	bne _080019B6
	ldrb r0, [r6]
	movs r0, #0
	strb r0, [r6]
	bl pollKeyInput
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	ldr r3, _08001A80 @ =0x0000FF7F
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2]
	bl FlashVideoRegister
	bl FlashOAM
	bl FlashBlendRegister
	bl FlashWinRegister
	bl FlashMOSAIC
	bl transferData
	bl FUN_080e98ec
	bl flashPalette_08003b24
	bl doGraphicTransferTasks
	ldr r0, _08001A84 @ =gSramState
	ldrb r0, [r0]
	cmp r0, #0
	bne _08001A66
	ldr r0, _08001A88 @ =gGameState
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _08001A66
	ldr r5, _08001A8C @ =gJoypad
	ldrh r1, [r5]
	movs r2, #0xc
	ands r2, r1
	cmp r2, #0xc
	bne _08001A66
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08001A66
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08001A66
	ldrh r1, [r5, #4]
	ands r2, r1
	cmp r2, #0
	bne _08001A4A
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08001A4A
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08001A66
_08001A4A:
	movs r0, #0
	bl disableProcess
	movs r0, #1
	bl disableProcess
	ldr r0, _08001A90 @ =gIntro
	movs r1, #1
	bl SetIntroMode
	movs r0, #0
	ldr r1, _08001A94 @ =Process_SoftReset
	bl ResetProcess
_08001A66:
	mov r0, sb
	movs r1, #1
	bl InterruptSystemProcess
	b _08001994
	.align 2, 0
_08001A70: .4byte gSystemBuffer
_08001A74: .4byte 0x030016F5
_08001A78: .4byte 0x00001202
_08001A7C: .4byte 0x04000006
_08001A80: .4byte 0x0000FF7F
_08001A84: .4byte gSramState
_08001A88: .4byte gGameState
_08001A8C: .4byte gJoypad
_08001A90: .4byte gIntro
_08001A94: .4byte Process_SoftReset
