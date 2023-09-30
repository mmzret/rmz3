	push {r4, r5, r6, lr}
	ldr r0, _08001938 @ =gIntrManager
	ldr r2, _0800193C @ =0x00000165
	adds r1, r0, r2
	ldrb r0, [r1]
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	bl ResetVideoRegister
	ldr r0, _08001940 @ =gGameState+16
	ldr r4, _08001944 @ =gVideoRegBuffer+4
	ldrh r2, [r4]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	movs r3, #0xf0
	lsls r3, r3, #2
	bl MaskBg0
	ldr r1, _08001948 @ =gJoypad
	movs r2, #0x18
	strb r2, [r1, #0x14]
	movs r3, #4
	strb r3, [r1, #0x15]
	adds r0, r1, #0
	adds r0, #0x2c
	strb r2, [r0]
	adds r1, #0x2d
	strb r3, [r1]
	ldr r6, _0800194C @ =gPaletteManager
	ldr r1, _08001950 @ =0x00000402
	adds r0, r6, r1
	movs r1, #0x20
	strb r1, [r0]
	ldr r2, _08001954 @ =0x00000401
	adds r0, r6, r2
	strb r1, [r0]
	subs r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r6, r1
	str r5, [r0]
	bl ClearBlinkings
	ldr r0, _08001958 @ =gBlendRegBuffer
	strh r5, [r0]
	ldr r1, _0800195C @ =gWindowRegBuffer
	strh r5, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xe]
	ldr r0, _08001960 @ =wMOSAIC
	strh r5, [r0]
	strh r5, [r6]
	bl StopAllMusics
	bl text_080e9730
	bl LoadKatakanaBold
	subs r4, #4
	ldrh r1, [r4]
	ldr r0, _08001964 @ =0x0000FFF8
	ands r0, r1
	ldr r1, _08001968 @ =0x0000F0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	str r5, [r4, #0xc]
	ldr r0, _0800196C @ =gIntro
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08001924
	ldr r1, _08001970 @ =0x00007FFF
	adds r0, r1, #0
	strh r0, [r6]
_08001924:
	movs r0, #1
	bl SwitchProcess
	ldr r0, _08001974 @ =Process_Intro
	bl exec
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001938: .4byte gIntrManager
_0800193C: .4byte 0x00000165
_08001940: .4byte gGameState+16
_08001944: .4byte gVideoRegBuffer+4
_08001948: .4byte gJoypad
_0800194C: .4byte gPaletteManager
_08001950: .4byte 0x00000402
_08001954: .4byte 0x00000401
_08001958: .4byte gBlendRegBuffer
_0800195C: .4byte gWindowRegBuffer
_08001960: .4byte wMOSAIC
_08001964: .4byte 0x0000FFF8
_08001968: .4byte 0x0000F0FF
_0800196C: .4byte gIntro
_08001970: .4byte 0x00007FFF
_08001974: .4byte Process_Intro
