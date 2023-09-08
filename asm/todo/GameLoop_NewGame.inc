	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r0, _080EE5C8 @ =0x0000625C
	adds r6, r4, r0
	movs r3, #0
	strh r3, [r6, #2]
	ldr r0, _080EE5CC @ =gGameState
	ldr r1, _080EE5D0 @ =0x000064AC
	adds r2, r0, r1
	adds r1, #4
	adds r0, r0, r1
	ldr r1, _080EE5D4 @ =0x02037C60
	str r1, [r0]
	str r1, [r2]
	ldr r1, _080EE5D8 @ =0x00006260
	adds r0, r4, r1
	movs r1, #1
	mov sl, r1
	mov r1, sl
	strh r1, [r0]
	strh r3, [r6]
	ldr r0, _080EE5DC @ =0x00006270
	adds r5, r4, r0
	adds r0, r5, #0
	bl FUN_08019678
	ldr r1, _080EE5E0 @ =0x00006410
	adds r0, r4, r1
	bl ClearPlayInfo
	ldr r0, _080EE5E4 @ =0x00006318
	adds r0, r0, r4
	mov sb, r0
	bl clearSecretDiskData
	ldr r1, _080EE5E8 @ =0x00006378
	adds r1, r1, r4
	mov r8, r1
	mov r0, r8
	bl clearUnlockedCyberElfData
	ldr r0, _080EE5EC @ =0x00006460
	adds r7, r4, r0
	adds r0, r7, #0
	bl ClearZeroStatus
	ldr r0, _080EE5F0 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x18]
	ldr r0, _080EE5F4 @ =gSineTable
	ldrb r0, [r0, #0x10]
	cmp r1, r0
	bne _080EE564
	ldr r0, _080EE5F8 @ =gJoypad
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080EE564
	mov r1, sl
	strh r1, [r6, #2]
	ldrb r1, [r5]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5]
	mov r0, sb
	bl clearSecretDiskDataHard
	mov r0, r8
	bl clearUnlockedCyberElfDataHard
	adds r0, r7, #0
	bl ClearZeroStatusHard
_080EE564:
	ldr r0, _080EE5F0 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x19]
	ldr r0, _080EE5F4 @ =gSineTable
	ldrb r0, [r0, #0x12]
	cmp r1, r0
	bne _080EE5A8
	ldr r0, _080EE5F8 @ =gJoypad
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080EE5A8
	ldr r0, _080EE5C8 @ =0x0000625C
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1, #2]
	ldr r1, _080EE5DC @ =0x00006270
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080EE5E4 @ =0x00006318
	adds r0, r4, r1
	bl unlockAllSecretDisk
	ldr r1, _080EE5E8 @ =0x00006378
	adds r0, r4, r1
	bl unlockAllElvesForUltimate
	ldr r1, _080EE5EC @ =0x00006460
	adds r0, r4, r1
	bl ClearZeroStatusUltimate
_080EE5A8:
	ldr r1, _080EE5D8 @ =0x00006260
	adds r0, r4, r1
	ldrb r0, [r0]
	bl InitStageRun
	ldr r1, _080EE5C8 @ =0x0000625C
	adds r0, r4, r1
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080EE5FC
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetGameMode
	b _080EE606
	.align 2, 0
_080EE5C8: .4byte 0x0000625C
_080EE5CC: .4byte gGameState
_080EE5D0: .4byte 0x000064AC
_080EE5D4: .4byte 0x02037C60
_080EE5D8: .4byte 0x00006260
_080EE5DC: .4byte 0x00006270
_080EE5E0: .4byte 0x00006410
_080EE5E4: .4byte 0x00006318
_080EE5E8: .4byte 0x00006378
_080EE5EC: .4byte 0x00006460
_080EE5F0: .4byte gSystemSavedataManager
_080EE5F4: .4byte gSineTable
_080EE5F8: .4byte gJoypad
_080EE5FC:
	movs r1, #0xd0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetGameMode
_080EE606:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
