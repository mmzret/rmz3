	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start AgbMain
AgbMain: @ 0x08001780
	push {r4, r5, r6, lr}
	bl FUN_08001ab4
	bl initIntrHandlers
	bl clear0x020014e0
	bl initKeys
	bl clear0x02001ee0
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x80
	strh r0, [r1]
	bl fillVRAM
	bl flashPalette_08003abc
	bl clearBlinkings
	bl resetVideoRegister
	bl resetOAM
	bl clearBLDCLT_1
	bl FUN_0800439c
	bl clearMOSAIC
	bl initSound
	ldr r4, _0800184C @ =0x02030B70
	ldr r0, _08001850 @ =0x02002144
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
	bl setBg0Mask
	adds r0, r4, #0
	bl FUN_080e96e0
	ldr r1, _08001854 @ =0x03002AC0
	ldr r2, _08001858 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _0800185C @ =0x03001590
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
	ldr r4, _08001870 @ =0x02030900
	adds r0, r4, #0
	movs r1, #0
	bl setIntroMode
	strh r5, [r4, #0x12]
	movs r0, #1
	bl initScheduler
	ldr r1, _08001874 @ =SoftResetProcess
	movs r0, #0
	bl resetProcess
	ldr r1, _08001878 @ =SystemProcess
	movs r0, #2
	bl resetProcess
	bl GameLoop
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800184C: .4byte 0x02030B70
_08001850: .4byte 0x02002144
_08001854: .4byte 0x03002AC0
_08001858: .4byte 0x00007FFF
_0800185C: .4byte 0x03001590
_08001860: .4byte 0x00000165
_08001864: .4byte usrHBlankCallback
_08001868: .4byte 0x04000006
_0800186C: .4byte usrVBlankCallback
_08001870: .4byte 0x02030900
_08001874: .4byte SoftResetProcess
_08001878: .4byte SystemProcess

	thumb_func_start SoftResetProcess
SoftResetProcess: @ 0x0800187C
	push {r4, r5, r6, lr}
	ldr r0, _08001938 @ =0x03001590
	ldr r2, _0800193C @ =0x00000165
	adds r1, r0, r2
	ldrb r0, [r1]
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	bl resetVideoRegister
	ldr r0, _08001940 @ =0x02030B70
	ldr r4, _08001944 @ =0x02002144
	ldrh r2, [r4]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	movs r3, #0xf0
	lsls r3, r3, #2
	bl setBg0Mask
	ldr r1, _08001948 @ =0x02001EB0
	movs r2, #0x18
	strb r2, [r1, #0x14]
	movs r3, #4
	strb r3, [r1, #0x15]
	adds r0, r1, #0
	adds r0, #0x2c
	strb r2, [r0]
	adds r1, #0x2d
	strb r3, [r1]
	ldr r6, _0800194C @ =0x03002AC0
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
	bl clearBlinkings
	ldr r0, _08001958 @ =0x02002180
	strh r5, [r0]
	ldr r1, _0800195C @ =0x02002190
	strh r5, [r1]
	movs r0, #0xff
	strb r0, [r1, #0xe]
	ldr r0, _08001960 @ =0x020021A0
	strh r5, [r0]
	strh r5, [r6]
	bl stopAllMusics
	bl FUN_080e9730
	bl copyTileData_080e97f0
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
	ldr r0, _0800196C @ =0x02030900
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08001924
	ldr r1, _08001970 @ =0x00007FFF
	adds r0, r1, #0
	strh r0, [r6]
_08001924:
	movs r0, #1
	bl switchProcess
	ldr r0, _08001974 @ =IntroProcess
	bl exec
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001938: .4byte 0x03001590
_0800193C: .4byte 0x00000165
_08001940: .4byte 0x02030B70
_08001944: .4byte 0x02002144
_08001948: .4byte 0x02001EB0
_0800194C: .4byte 0x03002AC0
_08001950: .4byte 0x00000402
_08001954: .4byte 0x00000401
_08001958: .4byte 0x02002180
_0800195C: .4byte 0x02002190
_08001960: .4byte 0x020021A0
_08001964: .4byte 0x0000FFF8
_08001968: .4byte 0x0000F0FF
_0800196C: .4byte 0x02030900
_08001970: .4byte 0x00007FFF
_08001974: .4byte IntroProcess

	thumb_func_start SystemProcess
SystemProcess: @ 0x08001978
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r0, _08001A70 @ =0x03000380
	mov r8, r0
	movs r1, #0x90
	lsls r1, r1, #5
	add r1, r8
	mov sl, r1
	ldr r7, _08001A74 @ =0x030016F5
	subs r6, r7, #1
_08001994:
	bl printAllStrings
	bl blink
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
	bl flashVideoRegister
	bl flashOAM
	bl flashBlendRegister
	bl flashWinRegister
	bl flashMOSAIC
	bl transferData
	bl FUN_080e98ec
	bl flashPalette_08003b24
	bl doGraphicTasks
	ldr r0, _08001A84 @ =0x02001EE0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08001A66
	ldr r0, _08001A88 @ =0x02030B60
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _08001A66
	ldr r5, _08001A8C @ =0x02001EB0
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
	ldr r0, _08001A90 @ =0x02030900
	movs r1, #1
	bl setIntroMode
	movs r0, #0
	ldr r1, _08001A94 @ =SoftResetProcess
	bl resetProcess
_08001A66:
	mov r0, sb
	movs r1, #1
	bl interruptSystemProcess
	b _08001994
	.align 2, 0
_08001A70: .4byte 0x03000380
_08001A74: .4byte 0x030016F5
_08001A78: .4byte 0x00001202
_08001A7C: .4byte 0x04000006
_08001A80: .4byte 0x0000FF7F
_08001A84: .4byte 0x02001EE0
_08001A88: .4byte 0x02030B60
_08001A8C: .4byte 0x02001EB0
_08001A90: .4byte 0x02030900
_08001A94: .4byte SoftResetProcess

	thumb_func_start usrHBlankCallback
usrHBlankCallback: @ 0x08001A98
	push {lr}
	bl _usrHBlankCallback
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start usrVBlankCallback
usrVBlankCallback: @ 0x08001AA4
	push {lr}
	bl FUN_0800295c
	bl FUN_080044a0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08001ab4
FUN_08001ab4: @ 0x08001AB4
	sub sp, #4
	ldr r1, _08001AF8 @ =0x04000204
	ldr r2, _08001AFC @ =0x000045B7
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0
	str r2, [sp]
	ldr r0, _08001B00 @ =0x040000D4
	mov r3, sp
	str r3, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	str r1, [r0, #4]
	ldr r1, _08001B04 @ =0x85001F80
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	str r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x12
	str r1, [r0, #4]
	ldr r1, _08001B08 @ =0x85010000
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _08001B0C @ =0x03000380
	ldr r3, _08001B10 @ =0x00001202
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	strh r2, [r0]
	add sp, #4
	bx lr
	.align 2, 0
_08001AF8: .4byte 0x04000204
_08001AFC: .4byte 0x000045B7
_08001B00: .4byte 0x040000D4
_08001B04: .4byte 0x85001F80
_08001B08: .4byte 0x85010000
_08001B0C: .4byte 0x03000380
_08001B10: .4byte 0x00001202

	thumb_func_start malloc
malloc: @ 0x08001B14
	push {r4, r5, lr}
	ldr r3, _08001B44 @ =0x03000380
	ldr r2, _08001B48 @ =0x00001202
	adds r1, r3, r2
	ldrh r1, [r1]
	lsls r2, r1, #3
	adds r2, r2, r1
	lsls r2, r2, #8
	movs r1, #0x90
	lsls r1, r1, #5
	adds r5, r3, r1
	ldrh r4, [r5]
	lsls r1, r4, #2
	adds r1, r1, r3
	adds r2, r2, r1
	movs r1, #0x90
	lsls r1, r1, #2
	subs r1, r1, r4
	adds r0, #3
	lsrs r0, r0, #2
	cmp r1, r0
	bhs _08001B4C
	movs r0, #0
	b _08001B52
	.align 2, 0
_08001B44: .4byte 0x03000380
_08001B48: .4byte 0x00001202
_08001B4C:
	adds r0, r4, r0
	strh r0, [r5]
	adds r0, r2, #0
_08001B52:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08001b58
FUN_08001b58: @ 0x08001B58
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r7, r1, #0
	movs r0, #2
	rsbs r0, r0, #0
	ands r5, r0
	cmp r5, #0
	beq _08001BC6
	ands r6, r0
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _08001B84
	strh r1, [r6]
	subs r5, #2
	cmp r5, #0
	beq _08001BC6
	adds r6, #2
_08001B84:
	cmp r5, #0x20
	bls _08001BB2
	lsls r0, r1, #0x10
	orrs r0, r1
	str r0, [sp]
	movs r4, #0x20
	rsbs r4, r4, #0
	ands r4, r5
	lsrs r2, r4, #2
	ldr r0, _08001BD0 @ =0x001FFFFF
	ands r2, r0
	movs r0, #0x80
	lsls r0, r0, #0x11
	orrs r2, r0
	mov r0, sp
	adds r1, r6, #0
	bl CpuFastSet
	adds r6, r6, r4
	movs r0, #0x1f
	ands r5, r0
	cmp r5, #0
	beq _08001BC6
_08001BB2:
	add r0, sp, #4
	strh r7, [r0]
	lsls r2, r5, #0xa
	lsrs r2, r2, #0xb
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r2, r1
	adds r1, r6, #0
	bl CpuSet
_08001BC6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001BD0: .4byte 0x001FFFFF

	thumb_func_start transferMax30Bytes
transferMax30Bytes: @ 0x08001BD4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r0, #2
	rsbs r0, r0, #0
	ands r4, r0
	cmp r4, #0
	beq _08001C42
	ands r5, r0
	ands r6, r0
	movs r1, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08001BFC
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08001C0A
_08001BFC:
	lsls r2, r4, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	adds r1, r6, #0
	bl CpuSet
	b _08001C42
_08001C0A:
	cmp r4, #0x1f
	bls _08001C2A
	movs r2, #0x20
	rsbs r2, r2, #0
	ands r2, r4
	lsrs r2, r2, #2
	ldr r0, _08001C48 @ =0x001FFFFF
	ands r2, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl CpuFastSet
	movs r0, #0x1f
	ands r0, r4
	cmp r0, #0
	beq _08001C42
_08001C2A:
	movs r0, #0x20
	rsbs r0, r0, #0
	ands r0, r4
	adds r5, r5, r0
	adds r6, r6, r0
	movs r2, #0x1f
	ands r2, r4
	lsrs r2, r2, #1
	adds r0, r5, #0
	adds r1, r6, #0
	bl CpuSet
_08001C42:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001C48: .4byte 0x001FFFFF

	thumb_func_start initIntrHandlers
initIntrHandlers: @ 0x08001C4C
	push {r4, lr}
	ldr r4, _08001D00 @ =IntrMain
	ldr r0, _08001D04 @ =0x030015C8
	mov ip, r0
	ldr r3, _08001D08 @ =0x080FEC74
	mov r2, ip
	subs r2, #0x38
	movs r1, #0xd
_08001C5C:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08001C5C
	ldr r0, _08001D0C @ =0x040000D4
	str r4, [r0]
	mov r1, ip
	str r1, [r0, #4]
	ldr r1, _08001D10 @ =0x84000048
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _08001D14 @ =0x03007FFC
	mov r4, ip
	str r4, [r0]
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	str r1, [r0]
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	str r1, [r0]
	movs r0, #0x97
	lsls r0, r0, #1
	add r0, ip
	strb r1, [r0]
	ldr r0, _08001D18 @ =0x04000208
	movs r3, #1
	strh r3, [r0]
	ldr r2, _08001D1C @ =0x04000200
	ldr r4, _08001D20 @ =0x00002005
	adds r0, r4, #0
	strh r0, [r2]
	ldr r2, _08001D24 @ =0x04000004
	movs r0, #0x28
	strh r0, [r2]
	ldr r2, _08001D28 @ =0x0000012D
	add r2, ip
	ldrb r0, [r2]
	strb r3, [r2]
	movs r0, #0x96
	lsls r0, r0, #1
	add r0, ip
	ldrb r2, [r0]
	strb r1, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	str r1, [r0]
	ldr r0, _08001D2C @ =0x0000012F
	add r0, ip
	strb r1, [r0]
	movs r2, #0x9c
	lsls r2, r2, #1
	add r2, ip
	movs r0, #0xa2
	lsls r0, r0, #1
	add r0, ip
	str r1, [r0]
	str r1, [r2]
	movs r2, #0xa8
	lsls r2, r2, #1
	add r2, ip
	movs r0, #0xb0
	lsls r0, r0, #1
	add r0, ip
	str r1, [r0]
	str r1, [r2]
	movs r2, #0xba
	lsls r2, r2, #1
	add r2, ip
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	str r1, [r0]
	str r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001D00: .4byte IntrMain
_08001D04: .4byte 0x030015C8
_08001D08: .4byte 0x080FEC74
_08001D0C: .4byte 0x040000D4
_08001D10: .4byte 0x84000048
_08001D14: .4byte 0x03007FFC
_08001D18: .4byte 0x04000208
_08001D1C: .4byte 0x04000200
_08001D20: .4byte 0x00002005
_08001D24: .4byte 0x04000004
_08001D28: .4byte 0x0000012D
_08001D2C: .4byte 0x0000012F
_08001D30:
	.byte 0x01, 0x49, 0x01, 0x20, 0x08, 0x80, 0x70, 0x47, 0x08, 0x02, 0x00, 0x04

	thumb_func_start transferData
transferData: @ 0x08001D3C
	push {r4, lr}
	ldr r4, _08001D6C @ =0x03001710
	subs r2, r4, #4
	ldr r3, [r2]
	cmp r3, #0
	beq _08001D70
	adds r1, r4, #0
	subs r1, #0x18
	adds r0, r4, #0
	subs r0, #0xc
	ldr r0, [r0]
	str r0, [r1]
	adds r1, #4
	adds r0, r4, #0
	subs r0, #8
	ldr r0, [r0]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r2]
	str r0, [r1]
	movs r0, #0
	str r0, [r2]
	b _08001D94
	.align 2, 0
_08001D6C: .4byte 0x03001710
_08001D70:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _08001D8E
	adds r1, r4, #0
	subs r1, #0x18
	ldr r0, [r4, #0x10]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x14]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x18]
	str r0, [r1]
	str r3, [r4, #0x18]
	b _08001D94
_08001D8E:
	adds r1, r4, #0
	subs r1, #0x10
	str r0, [r1]
_08001D94:
	bl runDMA0
	ldr r0, [r4, #0x10]
	str r0, [r4]
	ldr r0, [r4, #0x14]
	str r0, [r4, #4]
	ldr r0, [r4, #0x18]
	str r0, [r4, #8]
	movs r1, #0
	str r1, [r4, #0x18]
	adds r4, #0x24
	ldr r0, [r4, #0x10]
	str r0, [r4]
	ldr r0, [r4, #0x14]
	str r0, [r4, #4]
	ldr r0, [r4, #0x18]
	str r0, [r4, #8]
	str r1, [r4, #0x18]
	bl transferByHand
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start HBlankIntrDummy
HBlankIntrDummy: @ 0x08001DC4
	bx lr
	.align 2, 0

	thumb_func_start VBlankIntr
VBlankIntr: @ 0x08001DC8
	push {r4, r5, lr}
	ldr r3, _08001E1C @ =0x03001590
	ldr r0, _08001E20 @ =0x00000167
	adds r4, r3, r0
	ldrb r1, [r4]
	movs r5, #1
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08001E14
	adds r0, r5, #0
	orrs r0, r1
	strb r0, [r4]
	ldr r0, _08001E24 @ =0x03007FF8
	strh r2, [r0]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08001E06
	bl _call_via_r0
_08001E06:
	bl runDMA0
	bl transferByHand
	ldrb r0, [r4]
	eors r0, r5
	strb r0, [r4]
_08001E14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001E1C: .4byte 0x03001590
_08001E20: .4byte 0x00000167
_08001E24: .4byte 0x03007FF8

	thumb_func_start VCountIntr
VCountIntr: @ 0x08001E28
	push {lr}
	sub sp, #4
	mov r1, sp
	ldr r0, _08001E98 @ =0x04000006
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r2, _08001E9C @ =0x03001590
	ldr r0, _08001EA0 @ =0x00000167
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08001EBA
	movs r0, #2
	orrs r0, r1
	strb r0, [r3]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0
	bne _08001E5E
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08001E5E:
	mov r0, sp
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08001E7E
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08001E7E
	bl _call_via_r0
_08001E7E:
	mov r0, sp
	ldr r1, _08001E9C @ =0x03001590
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrb r2, [r2]
	ldrh r0, [r0]
	adds r3, r1, #0
	cmp r0, r2
	bhs _08001EA8
	ldr r0, _08001EA4 @ =0x04000005
	strb r2, [r0]
	b _08001EAE
	.align 2, 0
_08001E98: .4byte 0x04000006
_08001E9C: .4byte 0x03001590
_08001EA0: .4byte 0x00000167
_08001EA4: .4byte 0x04000005
_08001EA8:
	ldr r1, _08001EC0 @ =0x04000005
	movs r0, #0
	strb r0, [r1]
_08001EAE:
	ldr r0, _08001EC4 @ =0x00000167
	adds r2, r3, r0
	ldrb r0, [r2]
	movs r1, #2
	eors r0, r1
	strb r0, [r2]
_08001EBA:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08001EC0: .4byte 0x04000005
_08001EC4: .4byte 0x00000167

	thumb_func_start runDMA0
runDMA0: @ 0x08001EC8
	push {r4, r5, lr}
	ldr r2, _08001F10 @ =0x040000B8
	movs r0, #0
	str r0, [r2]
	ldr r1, _08001F14 @ =0x03001590
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r3, [r0]
	cmp r3, #0
	beq _08001F74
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r0, r1, r4
	ldr r5, [r0]
	adds r4, #4
	adds r0, r1, r4
	ldr r4, [r0]
	ldr r0, _08001F18 @ =0x040000B0
	str r5, [r0]
	adds r0, #4
	str r4, [r0]
	ldr r0, _08001F1C @ =0xCDFFFFFF
	ands r0, r3
	str r0, [r2]
	ldr r0, [r2]
	ldr r2, _08001F20 @ =0x0000FFFF
	ands r2, r3
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r3
	cmp r0, #0
	beq _08001F24
	lsls r2, r2, #2
	b _08001F26
	.align 2, 0
_08001F10: .4byte 0x040000B8
_08001F14: .4byte 0x03001590
_08001F18: .4byte 0x040000B0
_08001F1C: .4byte 0xCDFFFFFF
_08001F20: .4byte 0x0000FFFF
_08001F24:
	lsls r2, r2, #1
_08001F26:
	movs r1, #0xc0
	lsls r1, r1, #0xf
	ands r1, r3
	cmp r1, #0
	bne _08001F32
	adds r4, r4, r2
_08001F32:
	movs r0, #0x80
	lsls r0, r0, #0xe
	cmp r1, r0
	bne _08001F3C
	subs r4, r4, r2
_08001F3C:
	movs r1, #0xc0
	lsls r1, r1, #0x11
	ands r1, r3
	cmp r1, #0
	bne _08001F48
	adds r5, r5, r2
_08001F48:
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _08001F52
	subs r5, r5, r2
_08001F52:
	ldr r2, _08001F7C @ =0x040000B0
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, #0
	bge _08001F66
_08001F5E:
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08001F5E
_08001F66:
	ldr r0, _08001F7C @ =0x040000B0
	str r5, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	str r3, [r0]
	ldr r0, [r0]
_08001F74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001F7C: .4byte 0x040000B0

	thumb_func_start transferByHand
transferByHand: @ 0x08001F80
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08001FA0 @ =0x03001710
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _08001FC0
	ldr r0, [r4]
	str r0, [r4, #0xc]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r1, r0
	cmp r1, #0
	beq _08001FA4
	strh r5, [r4, #0x1c]
	b _08001FA8
	.align 2, 0
_08001FA0: .4byte 0x03001710
_08001FA4:
	movs r0, #1
	strh r0, [r4, #0x1c]
_08001FA8:
	movs r0, #1
	strh r0, [r4, #0x1e]
	ldr r0, [r4, #8]
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	bl _transferByHand
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
_08001FC0:
	adds r4, #0x24
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _08001FF6
	ldr r0, [r4]
	str r0, [r4, #0xc]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r1, r0
	cmp r1, #0
	beq _08001FDA
	movs r0, #0
	b _08001FDC
_08001FDA:
	movs r0, #1
_08001FDC:
	strh r0, [r4, #0x1c]
	movs r0, #1
	strh r0, [r4, #0x1e]
	ldr r0, [r4, #8]
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	bl _transferByHand
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r0, r1
	lsrs r5, r0, #0x10
_08001FF6:
	lsls r0, r5, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	beq _08002022
	ldr r2, _08002028 @ =0x04000004
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r2, _0800202C @ =0x03001590
	ldr r1, _08002030 @ =0x08338C90
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #4]
	ldr r2, _08002034 @ =0x04000200
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
_08002022:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08002028: .4byte 0x04000004
_0800202C: .4byte 0x03001590
_08002030: .4byte 0x08338C90
_08002034: .4byte 0x04000200

	thumb_func_start HBlankIntr1
HBlankIntr1: @ 0x08002038
	push {r4, lr}
	sub sp, #4
	mov r1, sp
	ldr r0, _08002084 @ =0x04000006
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0xa0
	bhi _0800207C
	ldr r4, _08002088 @ =0x03001710
	adds r0, r4, #0
	bl _transferByHand
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0xa0
	bne _0800207C
	ldr r1, _0800208C @ =0x04000004
	ldrh r2, [r1]
	ldr r0, _08002090 @ =0x0000FFEF
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	ldr r0, _08002094 @ =0xFFFFFE80
	adds r1, r4, r0
	ldr r0, _08002098 @ =HBlankIntrDummy
	str r0, [r1, #4]
	ldr r1, _0800209C @ =0x04000200
	ldrh r2, [r1]
	ldr r0, _080020A0 @ =0x0000FFFD
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
_0800207C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002084: .4byte 0x04000006
_08002088: .4byte 0x03001710
_0800208C: .4byte 0x04000004
_08002090: .4byte 0x0000FFEF
_08002094: .4byte 0xFFFFFE80
_08002098: .4byte HBlankIntrDummy
_0800209C: .4byte 0x04000200
_080020A0: .4byte 0x0000FFFD

	thumb_func_start HBlankIntr2
HBlankIntr2: @ 0x080020A4
	push {r4, lr}
	sub sp, #4
	mov r1, sp
	ldr r0, _080020F0 @ =0x04000006
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0xa0
	bhi _080020E8
	ldr r4, _080020F4 @ =0x03001734
	adds r0, r4, #0
	bl _transferByHand
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0xa0
	bne _080020E8
	ldr r1, _080020F8 @ =0x04000004
	ldrh r2, [r1]
	ldr r0, _080020FC @ =0x0000FFEF
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	ldr r0, _08002100 @ =0xFFFFFE5C
	adds r1, r4, r0
	ldr r0, _08002104 @ =HBlankIntrDummy
	str r0, [r1, #4]
	ldr r1, _08002108 @ =0x04000200
	ldrh r2, [r1]
	ldr r0, _0800210C @ =0x0000FFFD
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
_080020E8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080020F0: .4byte 0x04000006
_080020F4: .4byte 0x03001734
_080020F8: .4byte 0x04000004
_080020FC: .4byte 0x0000FFEF
_08002100: .4byte 0xFFFFFE5C
_08002104: .4byte HBlankIntrDummy
_08002108: .4byte 0x04000200
_0800210C: .4byte 0x0000FFFD

	thumb_func_start FUN_08002110
FUN_08002110: @ 0x08002110
	push {r4, lr}
	sub sp, #4
	mov r1, sp
	ldr r0, _08002164 @ =0x04000006
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0xa0
	bhi _0800215C
	ldr r4, _08002168 @ =0x03001710
	adds r0, r4, #0
	bl _transferByHand
	adds r4, #0x24
	adds r0, r4, #0
	bl _transferByHand
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0xa0
	bne _0800215C
	ldr r1, _0800216C @ =0x04000004
	ldrh r2, [r1]
	ldr r0, _08002170 @ =0x0000FFEF
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	ldr r0, _08002174 @ =0xFFFFFE5C
	adds r1, r4, r0
	ldr r0, _08002178 @ =HBlankIntrDummy
	str r0, [r1, #4]
	ldr r1, _0800217C @ =0x04000200
	ldrh r2, [r1]
	ldr r0, _08002180 @ =0x0000FFFD
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
_0800215C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002164: .4byte 0x04000006
_08002168: .4byte 0x03001710
_0800216C: .4byte 0x04000004
_08002170: .4byte 0x0000FFEF
_08002174: .4byte 0xFFFFFE5C
_08002178: .4byte HBlankIntrDummy
_0800217C: .4byte 0x04000200
_08002180: .4byte 0x0000FFFD

	thumb_func_start _transferByHand
_transferByHand: @ 0x08002184
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r3, [r2, #0xc]
	ldr r4, [r2, #4]
	ldrh r1, [r2, #0x20]
	cmp r1, #0
	beq _080021B0
_08002192:
	ldrh r0, [r3]
	strh r0, [r4]
	movs r5, #0x1e
	ldrsh r0, [r2, r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r5, #0x1c
	ldrsh r0, [r2, r5]
	lsls r0, r0, #1
	adds r3, r3, r0
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08002192
_080021B0:
	str r3, [r2, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start clear0x020014e0
clear0x020014e0: @ 0x080021B8
	ldr r1, _080021C0 @ =0x020014E0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080021C0: .4byte 0x020014E0

	thumb_func_start initScheduler
initScheduler: @ 0x080021C4
	push {lr}
	ldr r3, _080021EC @ =0x03002A68
	adds r1, r3, #0
	subs r1, #8
	movs r2, #0
	str r2, [r1]
	subs r1, r3, #4
	str r0, [r1]
	ldr r0, _080021F0 @ =0x02000000
	str r2, [r0]
	movs r1, #1
	movs r0, #2
_080021DC:
	strb r1, [r3]
	subs r0, #1
	adds r3, #0x18
	cmp r0, #0
	bge _080021DC
	pop {r0}
	bx r0
	.align 2, 0
_080021EC: .4byte 0x03002A68
_080021F0: .4byte 0x02000000

	thumb_func_start GameLoop
GameLoop: @ 0x080021F4
	push {r4, r5, r6, r7, lr}
	ldr r6, _08002278 @ =0x03001760
	ldr r0, _0800227C @ =0x00001350
	adds r5, r6, r0
	ldr r1, _08002280 @ =0x00001304
	adds r7, r6, r1
_08002200:
	movs r0, #0
	str r0, [r5]
	ldr r2, _08002284 @ =0x00001308
	adds r4, r6, r2
_08002208:
	ldrb r1, [r4]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08002252
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08002232
	ldrh r1, [r4, #2]
	movs r2, #2
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _0800222E
	subs r0, r1, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08002232
_0800222E:
	movs r0, #2
	strb r0, [r4]
_08002232:
	ldrb r0, [r4]
	cmp r0, #2
	bne _08002252
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08002246
	ldr r0, [r5]
	ldr r1, [r4, #4]
	bl resetProcess
_08002246:
	ldr r1, [r4, #4]
	ldr r2, [r4, #8]
	adds r0, r4, #0
	ldr r3, _08002288 @ =0x02000000
	bl callProcess
_08002252:
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	adds r4, #0x18
	cmp r0, #2
	bls _08002208
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, [r7]
	cmp r0, #0
	bne _08002200
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002278: .4byte 0x03001760
_0800227C: .4byte 0x00001350
_08002280: .4byte 0x00001304
_08002284: .4byte 0x00001308
_08002288: .4byte 0x02000000

	thumb_func_start disableAllProcesses
disableAllProcesses: @ 0x0800228C
	push {r4, r5, lr}
	ldr r5, _080022AC @ =0x03002A68
	movs r4, #0
_08002292:
	ldrb r0, [r5]
	cmp r0, #1
	beq _0800229E
	adds r0, r4, #0
	bl disableProcess
_0800229E:
	adds r4, #1
	adds r5, #0x18
	cmp r4, #2
	ble _08002292
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080022AC: .4byte 0x03002A68

	thumb_func_start resetProcess
resetProcess: @ 0x080022B0
	lsls r3, r0, #1
	adds r0, r3, r0
	lsls r0, r0, #3
	ldr r2, _080022D8 @ =0x03002A68
	adds r0, r0, r2
	str r1, [r0, #4]
	ldr r1, _080022DC @ =0x08338CA0
	adds r3, r3, r1
	ldr r1, _080022E0 @ =0xFFFFECF8
	adds r2, r2, r1
	ldrh r3, [r3]
	adds r2, r2, r3
	str r2, [r0, #8]
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #2]
	strb r2, [r0, #1]
	movs r1, #2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080022D8: .4byte 0x03002A68
_080022DC: .4byte 0x08338CA0
_080022E0: .4byte 0xFFFFECF8

	thumb_func_start switchProcess
switchProcess: @ 0x080022E4
	push {lr}
	adds r3, r0, #0
	ldr r2, _08002318 @ =0x03001760
	ldr r1, _0800231C @ =0x00001350
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _08002320 @ =0x00001308
	adds r2, r2, r1
	adds r1, r0, r2
	cmp r3, #0
	beq _08002312
	strh r3, [r1, #2]
	movs r0, #4
	strb r0, [r1]
	adds r0, r1, #4
	adds r1, #8
	ldr r2, _08002324 @ =0x02000000
	ldr r2, [r2]
	bl returnCallProcess
_08002312:
	pop {r0}
	bx r0
	.align 2, 0
_08002318: .4byte 0x03001760
_0800231C: .4byte 0x00001350
_08002320: .4byte 0x00001308
_08002324: .4byte 0x02000000

	thumb_func_start interruptSystemProcess
interruptSystemProcess: @ 0x08002328
	push {lr}
	adds r2, r0, #0
	cmp r1, #0
	beq _08002344
	strh r1, [r2, #2]
	movs r0, #4
	strb r0, [r2]
	adds r0, r2, #4
	adds r1, r2, #0
	adds r1, #8
	ldr r2, _08002348 @ =0x02000000
	ldr r2, [r2]
	bl returnCallProcess
_08002344:
	pop {r0}
	bx r0
	.align 2, 0
_08002348: .4byte 0x02000000

	thumb_func_start exitProcess
exitProcess: @ 0x0800234C
	push {lr}
	ldr r2, _08002378 @ =0x03001760
	ldr r1, _0800237C @ =0x00001350
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _08002380 @ =0x00001308
	adds r2, r2, r0
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r1, #4
	adds r1, #8
	ldr r2, _08002384 @ =0x02000000
	ldr r2, [r2]
	bl returnCallProcess
	pop {r0}
	bx r0
	.align 2, 0
_08002378: .4byte 0x03001760
_0800237C: .4byte 0x00001350
_08002380: .4byte 0x00001308
_08002384: .4byte 0x02000000

	thumb_func_start disableProcess
disableProcess: @ 0x08002388
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080023A4 @ =0x03002A68
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #1
	beq _0800239E
	movs r0, #1
	strb r0, [r1]
_0800239E:
	pop {r0}
	bx r0
	.align 2, 0
_080023A4: .4byte 0x03002A68

	thumb_func_start exec
exec: @ 0x080023A8
	push {lr}
	ldr r3, _080023D0 @ =0x03001760
	ldr r2, _080023D4 @ =0x00001350
	adds r1, r3, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080023D8 @ =0x00001308
	adds r3, r3, r2
	adds r1, r1, r3
	movs r2, #1
	strb r2, [r1, #1]
	str r0, [r1, #4]
	ldr r0, _080023DC @ =0x02000000
	ldr r0, [r0]
	bl returnToGameLoop
	pop {r0}
	bx r0
	.align 2, 0
_080023D0: .4byte 0x03001760
_080023D4: .4byte 0x00001350
_080023D8: .4byte 0x00001308
_080023DC: .4byte 0x02000000

	thumb_func_start FUN_080023e0
FUN_080023e0: @ 0x080023E0
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080023FC @ =0x03002A68
	adds r1, r1, r0
	ldrb r2, [r1]
	cmp r2, #1
	beq _080023F8
	movs r0, #8
	orrs r0, r2
	strb r0, [r1]
_080023F8:
	pop {r0}
	bx r0
	.align 2, 0
_080023FC: .4byte 0x03002A68

	thumb_func_start FUN_08002400
FUN_08002400: @ 0x08002400
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _08002424 @ =0x03002A68
	adds r1, r1, r0
	ldrb r2, [r1]
	cmp r2, #1
	beq _08002420
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08002420
	movs r0, #0xf7
	ands r0, r2
	strb r0, [r1]
_08002420:
	pop {r0}
	bx r0
	.align 2, 0
_08002424: .4byte 0x03002A68

	thumb_func_start FUN_08002428
FUN_08002428: @ 0x08002428
	push {r4, lr}
	movs r2, #0
	adds r4, r0, #0
	adds r4, #0xc
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x10
_08002436:
	adds r0, r4, r2
	strb r3, [r0]
	strh r3, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _08002436
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
