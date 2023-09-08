	push {r4, r5, r6, lr}
	bl ClearMemory
	bl InitIntrHandlers
	bl clear0x020014e0
	bl InitInput
	bl clear0x02001ee0
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x80
	strh r0, [r1]
	bl ClearVRAM
	bl InitPaletteManager
	bl ClearBlinkings
	bl ResetVideoRegister
	bl ResetOAM
	bl ClearBLDCLT_1
	bl ResetWindow
	bl ClearMOSAIC
	bl InitSound
	ldr r4, _0800184C @ =gGameState+16
	ldr r0, _08001850 @ =gVideoRegBuffer+4
	ldrh r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r4, #0
	bl MaskBg0
	adds r0, r4, #0
	bl InitTextPrinter
	ldr r1, _08001854 @ =gPaletteManager
	ldr r2, _08001858 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _0800185C @ =gIntrManager
	ldr r6, _08001860 @ =0x00000165
	adds r1, r3, r6
	ldrb r0, [r1]
	movs r5, #0
	movs r2, #1
	strb r2, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _08001864 @ =usrHBlankCallback
	str r0, [r1]
	ldr r0, _08001868 @ =0x04000006
	ldrh r0, [r0]
	movs r0, #0
	adds r6, #1
	adds r1, r3, r6
	strb r0, [r1]
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _0800186C @ =usrVBlankCallback
	str r0, [r1]
	subs r4, #0x10
	str r2, [r4, #0xc]
	ldr r4, _08001870 @ =gIntro
	adds r0, r4, #0
	movs r1, #0
	bl SetIntroMode
	strh r5, [r4, #0x12]
	movs r0, #1
	bl InitScheduler
	ldr r1, _08001874 @ =Process_SoftReset
	movs r0, #0
	bl ResetProcess
	ldr r1, _08001878 @ =Process_System
	movs r0, #2
	bl ResetProcess
	bl GameLoop
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800184C: .4byte gGameState+16
_08001850: .4byte gVideoRegBuffer+4
_08001854: .4byte gPaletteManager
_08001858: .4byte 0x00007FFF
_0800185C: .4byte gIntrManager
_08001860: .4byte 0x00000165
_08001864: .4byte usrHBlankCallback
_08001868: .4byte 0x04000006
_0800186C: .4byte usrVBlankCallback
_08001870: .4byte gIntro
_08001874: .4byte Process_SoftReset
_08001878: .4byte Process_System
