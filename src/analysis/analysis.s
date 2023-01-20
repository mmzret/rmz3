	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initAnalysisScreen
initAnalysisScreen: @ 0x080F7D94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r4, #0
	movs r5, #0
	strh r5, [r7, #4]
	ldr r1, _080F7E2C @ =0x00000DCC
	adds r0, r7, r1
	strb r4, [r0, #0xa]
	strb r4, [r0, #0xb]
	strb r4, [r0, #0xd]
	strb r4, [r0, #0xe]
	strb r4, [r0, #0xf]
	strb r4, [r0, #0x10]
	strb r4, [r0, #0x11]
	strb r4, [r0, #0x12]
	adds r0, r7, #0
	bl sd_analysis_080f83ac
	ldr r4, _080F7E30 @ =0x02002140
	ldrh r1, [r4]
	ldr r0, _080F7E34 @ =0x0000FFF8
	ands r0, r1
	ldr r1, _080F7E38 @ =0x0000F0FF
	ands r0, r1
	movs r2, #0x98
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _080F7E3C @ =0x00004206
	adds r0, r1, #0
	strh r0, [r4, #6]
	str r5, [r4, #0x10]
	ldr r1, _080F7E40 @ =0x02002180
	ldr r0, _080F7E44 @ =0x00002010
	strh r0, [r1]
	ldr r0, _080F7E48 @ =0x08547438
	movs r5, #0xc
	movs r1, #0x80
	lsls r1, r1, #7
	bl loadGraphic
	ldr r0, _080F7E4C @ =0x08547444
	movs r1, #0
	bl transferPalette
	ldr r2, _080F7E50 @ =0x00000ED8
	adds r0, r7, r2
	ldr r2, _080F7E54 @ =0x08522434
	ldr r1, [r2]
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0
	bl loadBgMap
	ldr r0, _080F7E58 @ =0x020021B0
	adds r0, #0x4b
	ldrb r0, [r0]
	cmp r0, #1
	bne _080F7E64
	ldr r0, _080F7E5C @ =0x08547550
	ldrh r2, [r4, #6]
	adds r1, r5, #0
	ands r1, r2
	lsls r1, r1, #0xc
	bl loadGraphic
	ldr r0, _080F7E60 @ =0x0854755C
	movs r1, #0
	bl transferPalette
	b _080F7E7E
	.align 2, 0
_080F7E2C: .4byte 0x00000DCC
_080F7E30: .4byte 0x02002140
_080F7E34: .4byte 0x0000FFF8
_080F7E38: .4byte 0x0000F0FF
_080F7E3C: .4byte 0x00004206
_080F7E40: .4byte 0x02002180
_080F7E44: .4byte 0x00002010
_080F7E48: .4byte 0x08547438
_080F7E4C: .4byte 0x08547444
_080F7E50: .4byte 0x00000ED8
_080F7E54: .4byte 0x08522434
_080F7E58: .4byte 0x020021B0
_080F7E5C: .4byte 0x08547550
_080F7E60: .4byte 0x0854755C
_080F7E64:
	cmp r0, #2
	bne _080F7E7E
	ldr r0, _080F7F78 @ =0x08547564
	ldrh r2, [r4, #6]
	adds r1, r5, #0
	ands r1, r2
	lsls r1, r1, #0xc
	bl loadGraphic
	ldr r0, _080F7F7C @ =0x08547570
	movs r1, #0
	bl transferPalette
_080F7E7E:
	adds r0, r7, #0
	bl setSecretDiskPalette
	movs r4, #0x8c
	lsls r4, r4, #1
	ldr r0, _080F7F80 @ =0x085D78F8
	mov r8, r0
	adds r0, r4, r0
	ldr r6, _080F7F84 @ =0x0202F790
	ldrh r1, [r6, #0x1c]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl loadGraphic
	ldr r0, _080F7F88 @ =0x085D7904
	mov sl, r0
	add r4, sl
	ldr r5, _080F7F8C @ =0x0202F590
	ldrh r1, [r5, #0x1c]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl transferPalette
	ldr r4, _080F7F90 @ =0x0000067C
	add r8, r4
	adds r6, #0xa6
	ldrh r1, [r6]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl loadGraphic
	add r4, sl
	adds r5, #0xa6
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl transferPalette
	adds r0, r7, #0
	movs r1, #3
	bl createMenuCursor
	adds r0, r7, #0
	movs r1, #4
	bl createMenuCursor
	adds r0, r7, #0
	movs r1, #0
	bl createSecretDiskModalBorder
	adds r0, r7, #0
	movs r1, #1
	bl createSecretDiskModalBorder
	adds r0, r7, #0
	movs r1, #2
	bl createSecretDiskModalBorder
	adds r0, r7, #0
	movs r1, #3
	bl createSecretDiskModalBorder
	movs r0, #0x40
	movs r1, #0
	bl loadBlink
	movs r2, #0
	ldr r3, _080F7F94 @ =0x03002BE0
	adds r4, r3, #0
	subs r4, #0x20
_080F7F34:
	lsls r0, r2, #1
	adds r1, r0, r3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _080F7F34
	ldr r1, _080F7F98 @ =0x00000ED8
	adds r0, r7, r1
	ldr r1, _080F7F9C @ =0x02002146
	ldrh r2, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	bl appendBgMapTask
	movs r0, #1
	strb r0, [r7, #1]
	adds r0, r7, #0
	bl openAnalysisScreen
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F7F78: .4byte 0x08547564
_080F7F7C: .4byte 0x08547570
_080F7F80: .4byte 0x085D78F8
_080F7F84: .4byte 0x0202F790
_080F7F88: .4byte 0x085D7904
_080F7F8C: .4byte 0x0202F590
_080F7F90: .4byte 0x0000067C
_080F7F94: .4byte 0x03002BE0
_080F7F98: .4byte 0x00000ED8
_080F7F9C: .4byte 0x02002146

	thumb_func_start openAnalysisScreen
openAnalysisScreen: @ 0x080F7FA0
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #4]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble _080F7FE4
	ldr r1, _080F7FD8 @ =0x03002AC0
	ldr r2, _080F7FDC @ =0x00000402
	adds r0, r1, r2
	movs r2, #0x20
	strb r2, [r0]
	ldr r4, _080F7FE0 @ =0x00000401
	adds r0, r1, r4
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	strb r2, [r1]
	movs r0, #2
	strb r0, [r3, #1]
	adds r0, r3, #0
	bl sdAnalysisFrameScript
	b _080F7FFE
	.align 2, 0
_080F7FD8: .4byte 0x03002AC0
_080F7FDC: .4byte 0x00000402
_080F7FE0: .4byte 0x00000401
_080F7FE4:
	ldr r2, _080F8004 @ =0x03002AC0
	ldr r3, _080F8008 @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	ldr r4, _080F800C @ =0x00000401
	adds r1, r2, r4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
_080F7FFE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F8004: .4byte 0x03002AC0
_080F8008: .4byte 0x00000402
_080F800C: .4byte 0x00000401

	thumb_func_start sdAnalysisFrameScript
sdAnalysisFrameScript: @ 0x080F8010
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r4, _080F80A8 @ =0x00000DCC
	add r4, sb
	movs r0, #0
	strb r0, [r4, #0xc]
	ldr r1, _080F80AC @ =0x083864AC
	mov r2, sb
	ldrb r0, [r2, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	ldr r0, _080F80B0 @ =0x02001EB0
	ldrh r1, [r0, #4]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080F8046
	movs r0, #3
	mov r3, sb
	strb r0, [r3, #1]
_080F8046:
	ldr r7, _080F80B4 @ =0x08372210
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	ldr r2, _080F80B8 @ =0x08372AA0
	mov r8, r2
	add r0, r8
	movs r1, #0x11
	movs r2, #1
	bl print
	ldrb r0, [r4, #0xa]
	adds r0, #1
	movs r1, #0x16
	movs r2, #1
	bl printThreeDigitNumber
	ldr r0, _080F80BC @ =0x0203DC50
	ldr r1, [r0]
	ldrb r2, [r4, #0xa]
	lsls r0, r2, #0x18
	lsrs r3, r0, #0x18
	lsrs r0, r0, #0x1a
	adds r5, r1, r0
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #3
	ands r1, r2
	asrs r0, r1
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _080F808E
	b _080F823C
_080F808E:
	ldrb r0, [r5]
	adds r1, #4
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080F809C
	b _080F8214
_080F809C:
	cmp r3, #5
	bhi _080F80C0
	movs r3, #0xaf
	lsls r3, r3, #2
	adds r0, r3, #0
	b _080F80CA
	.align 2, 0
_080F80A8: .4byte 0x00000DCC
_080F80AC: .4byte 0x083864AC
_080F80B0: .4byte 0x02001EB0
_080F80B4: .4byte 0x08372210
_080F80B8: .4byte 0x08372AA0
_080F80BC: .4byte 0x0203DC50
_080F80C0:
	cmp r3, #0x13
	bhi _080F80E0
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r1, #0
_080F80CA:
	ldrb r4, [r4, #0xa]
	adds r0, r0, r4
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	add r0, r8
	movs r1, #0x11
	movs r2, #4
	bl print
	b _080F81F8
_080F80E0:
	cmp r3, #0x5d
	bhi _080F8140
	ldrb r0, [r4, #0xa]
	adds r6, r0, #0
	adds r6, #0x50
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	add r0, r8
	movs r1, #0x11
	movs r2, #4
	bl print
	lsls r4, r6, #1
	adds r4, r4, r7
	ldrh r0, [r4]
	add r0, r8
	movs r1, #0x11
	movs r2, #6
	bl print
	ldr r3, _080F8138 @ =0x000005A2
	adds r0, r7, r3
	ldrh r5, [r0]
	add r5, r8
	ldrh r0, [r4]
	add r0, r8
	bl getStringLength
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r1, #0x11
	adds r0, r5, #0
	movs r2, #6
	bl print
	ldr r1, _080F813C @ =0x000005A4
	adds r0, r7, r1
	ldrh r0, [r0]
	add r0, r8
	b _080F81BC
	.align 2, 0
_080F8138: .4byte 0x000005A2
_080F813C: .4byte 0x000005A4
_080F8140:
	cmp r3, #0x6d
	bhi _080F81E0
	ldr r2, _080F81C8 @ =0x000005A6
	adds r0, r7, r2
	ldrh r0, [r0]
	add r0, r8
	movs r1, #0x11
	movs r2, #4
	bl print
	movs r6, #0
	ldr r1, _080F81CC @ =0x083864B8
	ldrb r0, [r4, #0xa]
	subs r0, #0x5e
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #0
	beq _080F817C
_080F8166:
	adds r0, r2, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r2, #0
	bne _080F8166
_080F817C:
	ldr r1, _080F81CC @ =0x083864B8
	ldr r0, _080F81D0 @ =0x00000DCC
	add r0, sb
	ldrb r0, [r0, #0xa]
	subs r0, #0x5e
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r1, r6, #0
	adds r1, #0x11
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r2, #0
	movs r2, #6
	bl printNumber
	ldr r4, _080F81D4 @ =0x08372210
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrh r0, [r0]
	ldr r5, _080F81D8 @ =0x08372AA0
	adds r0, r0, r5
	adds r1, r6, #0
	adds r1, #0x12
	movs r2, #6
	bl print
	ldr r0, _080F81DC @ =0x000005AA
	adds r4, r4, r0
	ldrh r0, [r4]
	adds r0, r0, r5
_080F81BC:
	movs r1, #0x11
	movs r2, #8
	bl print
	b _080F81F8
	.align 2, 0
_080F81C8: .4byte 0x000005A6
_080F81CC: .4byte 0x083864B8
_080F81D0: .4byte 0x00000DCC
_080F81D4: .4byte 0x08372210
_080F81D8: .4byte 0x08372AA0
_080F81DC: .4byte 0x000005AA
_080F81E0:
	ldrb r0, [r4, #0xa]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	add r0, r8
	movs r1, #0x11
	movs r2, #4
	bl print
_080F81F8:
	ldr r0, _080F8208 @ =0x08372210
	ldr r2, _080F820C @ =0x000003BA
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, _080F8210 @ =0x08372AA0
	adds r0, r0, r1
	b _080F822E
	.align 2, 0
_080F8208: .4byte 0x08372210
_080F820C: .4byte 0x000003BA
_080F8210: .4byte 0x08372AA0
_080F8214:
	ldr r3, _080F8238 @ =0x000003BE
	adds r0, r7, r3
	ldrh r0, [r0]
	add r0, r8
	movs r1, #0x11
	movs r2, #4
	bl print
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	add r0, r8
_080F822E:
	movs r1, #1
	movs r2, #0x12
	bl print
	b _080F824C
	.align 2, 0
_080F8238: .4byte 0x000003BE
_080F823C:
	ldr r2, _080F82AC @ =0x000003BA
	adds r0, r7, r2
	ldrh r0, [r0]
	add r0, r8
	movs r1, #1
	movs r2, #0x12
	bl print
_080F824C:
	ldr r5, _080F82B0 @ =0x00000DCC
	add r5, sb
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080F82BC
	ldr r2, _080F82B4 @ =0x03002AC0
	ldrb r1, [r5, #0x12]
	lsls r1, r1, #0xa
	ldrb r0, [r5, #0x11]
	lsls r0, r0, #5
	orrs r1, r0
	ldrb r0, [r5, #0x10]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _080F82B8 @ =0x02002190
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x10
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xe]
	movs r0, #3
	orrs r0, r1
	strb r0, [r2, #0xe]
	ldrb r3, [r5, #0xe]
	adds r1, r3, #0
	adds r1, #0x40
	movs r4, #0xff
	ands r1, r4
	movs r0, #0x40
	subs r0, r0, r3
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2, #4]
	ldrb r3, [r5, #0xf]
	adds r1, r3, #0
	adds r1, #0x50
	ands r1, r4
	movs r0, #0x50
	subs r0, r0, r3
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2, #8]
	b _080F82CE
	.align 2, 0
_080F82AC: .4byte 0x000003BA
_080F82B0: .4byte 0x00000DCC
_080F82B4: .4byte 0x03002AC0
_080F82B8: .4byte 0x02002190
_080F82BC:
	ldr r2, _080F82F0 @ =0x02002190
	ldrh r1, [r2]
	ldr r0, _080F82F4 @ =0x0000DFFF
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	strb r1, [r5, #0x10]
	strb r1, [r5, #0x11]
	strb r1, [r5, #0x12]
_080F82CE:
	movs r0, #0x40
	bl FUN_08004068
	ldr r0, _080F82F8 @ =0x00000DCC
	add r0, sb
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	beq _080F82E4
	mov r0, sb
	bl setSecretDiskPalette
_080F82E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F82F0: .4byte 0x02002190
_080F82F4: .4byte 0x0000DFFF
_080F82F8: .4byte 0x00000DCC

	thumb_func_start blackoutAnalysis
blackoutAnalysis: @ 0x080F82FC
	push {r4, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #4]
	subs r0, #1
	movs r3, #0
	adds r1, r0, #0
	strh r0, [r2, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080F833C
	ldr r0, _080F8334 @ =0x03002AC0
	ldr r4, _080F8338 @ =0x00000402
	adds r1, r0, r4
	strb r3, [r1]
	subs r4, #1
	adds r1, r0, r4
	strb r3, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r3, [r0]
	movs r0, #4
	strb r0, [r2, #1]
	adds r0, r2, #0
	bl closeAnalysis
	b _080F8356
	.align 2, 0
_080F8334: .4byte 0x03002AC0
_080F8338: .4byte 0x00000402
_080F833C:
	ldr r2, _080F835C @ =0x03002AC0
	ldr r3, _080F8360 @ =0x00000402
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #0xff
	ands r0, r1
	ldr r4, _080F8364 @ =0x00000401
	adds r1, r2, r4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
_080F8356:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F835C: .4byte 0x03002AC0
_080F8360: .4byte 0x00000402
_080F8364: .4byte 0x00000401

	thumb_func_start closeAnalysis
closeAnalysis: @ 0x080F8368
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x40
	bl clearBlink
	ldr r2, _080F8398 @ =0x02002190
	ldrh r1, [r2]
	ldr r0, _080F839C @ =0x0000DFFF
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r0, _080F83A0 @ =0x03002AC0
	strh r1, [r0]
	ldr r0, _080F83A4 @ =0x00000DCC
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1, #0xd]
	ldr r1, _080F83A8 @ =0x05030400
	adds r0, r4, #0
	bl setGameMode
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F8398: .4byte 0x02002190
_080F839C: .4byte 0x0000DFFF
_080F83A0: .4byte 0x03002AC0
_080F83A4: .4byte 0x00000DCC
_080F83A8: .4byte 0x05030400

	thumb_func_start sd_analysis_080f83ac
sd_analysis_080f83ac: @ 0x080F83AC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080F83F4 @ =0x00000DC4
	adds r1, r5, r0
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r1, #4]
	ldr r0, _080F83F8 @ =0x00000DB8
	adds r6, r5, r0
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0800469c
	ldr r0, _080F83FC @ =0x00000BAC
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_08004e14
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08004e4c
	ldr r0, _080F8400 @ =0x00000978
	adds r5, r5, r0
	ldr r1, _080F8404 @ =0x0203BB50
	adds r0, r5, #0
	movs r2, #0x40
	bl initMenuComponentHeader
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F83F4: .4byte 0x00000DC4
_080F83F8: .4byte 0x00000DB8
_080F83FC: .4byte 0x00000BAC
_080F8400: .4byte 0x00000978
_080F8404: .4byte 0x0203BB50

	thumb_func_start sd_analysis_080f8408
sd_analysis_080f8408: @ 0x080F8408
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080F8448 @ =0x00000DC4
	adds r2, r5, r0
	ldr r0, _080F844C @ =0x02002150
	ldrh r1, [r0]
	ldr r0, _080F8450 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080F8454 @ =0x00000BAC
	adds r5, r5, r0
	adds r0, r5, #0
	bl FUN_08004f00
	ldr r4, _080F8458 @ =0x02030300
	ldr r0, [r4]
	bl runEntityFn
	ldr r0, [r4]
	adds r1, r5, #0
	bl FUN_08016fa4
	adds r0, r5, #0
	bl FUN_08004eb0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8448: .4byte 0x00000DC4
_080F844C: .4byte 0x02002150
_080F8450: .4byte 0x000001FF
_080F8454: .4byte 0x00000BAC
_080F8458: .4byte 0x02030300

	thumb_func_start setSecretDiskPalette
setSecretDiskPalette: @ 0x080F845C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldr r6, _080F84F8 @ =0x00000ED8
	add r6, r8
	movs r5, #0
	ldr r0, _080F84FC @ =0x0203DC50
	mov sb, r0
	ldr r1, _080F8500 @ =0x02002146
	mov sl, r1
	ldr r2, _080F8504 @ =0x000031A2
	adds r7, r2, #0
_080F847A:
	mov r3, sb
	ldr r2, [r3]
	ldr r0, _080F8508 @ =0x00000DCC
	add r0, r8
	ldrb r0, [r0, #0xb]
	lsls r1, r0, #2
	adds r1, r1, r0
	adds r1, r1, r5
	asrs r0, r1, #2
	adds r3, r2, r0
	ldrb r2, [r3]
	movs r0, #0xf
	ands r0, r2
	movs r2, #3
	ands r2, r1
	asrs r0, r2
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _080F856C
	ldrb r0, [r3]
	adds r1, r2, #4
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _080F8514
	adds r0, r5, #0
	movs r1, #5
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsls r4, r4, #6
	lsrs r0, r0, #0x17
	adds r4, r4, r0
	lsls r4, r4, #1
	adds r2, r4, r6
	adds r1, r2, #0
	adds r1, #0xc6
	ldr r3, _080F850C @ =0x000080ED
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r3, #0x1f
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r2, _080F8510 @ =0x0000810E
	b _080F855C
	.align 2, 0
_080F84F8: .4byte 0x00000ED8
_080F84FC: .4byte 0x0203DC50
_080F8500: .4byte 0x02002146
_080F8504: .4byte 0x000031A2
_080F8508: .4byte 0x00000DCC
_080F850C: .4byte 0x000080ED
_080F8510: .4byte 0x0000810E
_080F8514:
	adds r0, r5, #0
	movs r1, #5
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsls r4, r4, #6
	lsrs r0, r0, #0x17
	adds r4, r4, r0
	lsls r4, r4, #1
	adds r2, r4, r6
	adds r1, r2, #0
	adds r1, #0xc6
	ldr r3, _080F8564 @ =0x000080EB
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r3, #0x1f
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r2, _080F8568 @ =0x0000810C
_080F855C:
	adds r0, r2, #0
	strh r0, [r1]
	b _080F85A8
	.align 2, 0
_080F8564: .4byte 0x000080EB
_080F8568: .4byte 0x0000810C
_080F856C:
	adds r0, r5, #0
	movs r1, #5
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsls r4, r4, #6
	lsrs r0, r0, #0x17
	adds r4, r4, r0
	lsls r4, r4, #1
	adds r1, r4, r6
	adds r0, r1, #0
	adds r0, #0xc6
	strh r7, [r0]
	adds r0, #2
	strh r7, [r0]
	movs r3, #0x83
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r7, [r0]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r1, r2
	strh r7, [r0]
_080F85A8:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x1d
	bhi _080F85B4
	b _080F847A
_080F85B4:
	ldr r0, _080F85DC @ =0x00000ED8
	add r0, r8
	mov r3, sl
	ldrh r2, [r3]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	bl appendBgMapTask
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F85DC: .4byte 0x00000ED8

	thumb_func_start sd_analysis_080f85e0
sd_analysis_080f85e0: @ 0x080F85E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _080F8638
	ldr r0, _080F8634 @ =0x00000DCC
	adds r5, r6, r0
	movs r0, #1
	strb r0, [r5, #0xc]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e6420
	adds r4, r0, #0
	str r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, #0x18
	adds r4, #0x74
	strh r0, [r4]
	ldr r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #0xb]
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x18
	adds r4, #0x76
	strh r0, [r4]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
	b _080F8754
	.align 2, 0
_080F8634: .4byte 0x00000DCC
_080F8638:
	ldr r0, _080F8654 @ =0x00000DCC
	adds r3, r6, r0
	ldrb r1, [r3, #0xa]
	ldr r0, _080F8658 @ =0x02001EB0
	ldrh r2, [r0, #6]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080F865C
	cmp r1, #0
	beq _080F868C
	subs r0, r1, #1
	b _080F868A
	.align 2, 0
_080F8654: .4byte 0x00000DCC
_080F8658: .4byte 0x02001EB0
_080F865C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080F866C
	cmp r1, #0xb2
	bhi _080F868C
	adds r0, r1, #1
	b _080F868A
_080F866C:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080F867C
	cmp r1, #4
	bls _080F868C
	subs r0, r1, #5
	b _080F868A
_080F867C:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _080F868C
	cmp r1, #0xae
	bhi _080F868C
	adds r0, r1, #5
_080F868A:
	strb r0, [r3, #0xa]
_080F868C:
	ldr r0, _080F86B4 @ =0x00000DCC
	adds r4, r6, r0
	ldrb r0, [r4, #0xa]
	cmp r1, r0
	beq _080F869C
	movs r0, #1
	bl playSound
_080F869C:
	ldrb r0, [r4, #0xa]
	movs r1, #5
	bl __udivsi3
	adds r2, r0, #0
	ldrb r1, [r4, #0xb]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	bls _080F86B8
	strb r2, [r4, #0xb]
	b _080F86C4
	.align 2, 0
_080F86B4: .4byte 0x00000DCC
_080F86B8:
	ldrb r1, [r4, #0xb]
	subs r0, #5
	cmp r1, r0
	bge _080F86C8
	subs r0, r2, #5
	strb r0, [r4, #0xb]
_080F86C4:
	movs r0, #1
	strb r0, [r4, #0xc]
_080F86C8:
	ldr r0, _080F8734 @ =0x00000DCC
	adds r5, r6, r0
	ldr r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, #0x18
	adds r4, #0x74
	strh r0, [r4]
	ldr r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #0xb]
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x18
	adds r4, #0x76
	strh r0, [r4]
	ldr r0, _080F8738 @ =0x02001EB0
	ldrh r1, [r0, #4]
	movs r4, #1
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080F8748
	ldr r0, _080F873C @ =0x0203DC50
	ldr r0, [r0]
	ldrb r2, [r5, #0xa]
	lsrs r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	movs r1, #3
	ands r1, r2
	asrs r0, r1
	ands r0, r3
	cmp r0, #0
	beq _080F8740
	ldr r0, [r5, #4]
	adds r0, #0x78
	strb r4, [r0]
	strb r4, [r6, #2]
	movs r0, #0
	strb r0, [r6, #3]
	b _080F8754
	.align 2, 0
_080F8734: .4byte 0x00000DCC
_080F8738: .4byte 0x02001EB0
_080F873C: .4byte 0x0203DC50
_080F8740:
	movs r0, #4
	bl playSound
	b _080F8754
_080F8748:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080F8754
	movs r0, #3
	strb r0, [r6, #1]
_080F8754:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sd_analysis_080f875c
sd_analysis_080f875c: @ 0x080F875C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _080F880C
	ldr r0, _080F8798 @ =0x0203DC50
	ldr r1, [r0]
	ldr r0, _080F879C @ =0x00000DCC
	add r0, r8
	ldrb r2, [r0, #0xa]
	lsrs r0, r2, #2
	adds r1, r1, r0
	ldrb r1, [r1]
	movs r0, #3
	ands r0, r2
	adds r0, #4
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080F87A0
	movs r0, #2
	bl playSound
	b _080F87A6
	.align 2, 0
_080F8798: .4byte 0x0203DC50
_080F879C: .4byte 0x00000DCC
_080F87A0:
	movs r0, #0xe
	bl playSound
_080F87A6:
	ldr r4, _080F87CC @ =0x00000DCC
	add r4, r8
	ldrb r1, [r4, #0xa]
	mov r0, r8
	movs r2, #0
	bl openSecretDisk
	ldrb r0, [r4, #0xa]
	cmp r0, #0x13
	bls _080F87F4
	cmp r0, #0x2e
	bhi _080F87D0
	movs r0, #0x13
	strb r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #0x11]
	movs r0, #9
	strb r0, [r4, #0x12]
	b _080F87FC
	.align 2, 0
_080F87CC: .4byte 0x00000DCC
_080F87D0:
	cmp r0, #0x3b
	bhi _080F87E2
	movs r0, #2
	strb r0, [r4, #0x10]
	movs r0, #0x11
	strb r0, [r4, #0x11]
	movs r0, #7
	strb r0, [r4, #0x12]
	b _080F87FC
_080F87E2:
	cmp r0, #0x5d
	bhi _080F87F4
	movs r0, #8
	strb r0, [r4, #0x10]
	movs r0, #0xb
	strb r0, [r4, #0x11]
	movs r0, #0x16
	strb r0, [r4, #0x12]
	b _080F87FC
_080F87F4:
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x11]
	strb r0, [r4, #0x10]
_080F87FC:
	ldr r1, _080F88E0 @ =0x00000DCC
	add r1, r8
	movs r0, #1
	strb r0, [r1, #0xc]
	mov r1, r8
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_080F880C:
	movs r7, #2
	ldr r2, _080F88E4 @ =0x03002BC0
	mov sl, r2
	movs r4, #0x1f
	mov sb, r4
	movs r5, #0x1f
	mov ip, r5
_080F881A:
	lsls r0, r7, #1
	mov r1, sl
	adds r6, r0, r1
	ldrh r1, [r6]
	adds r4, r1, #0
	ldr r2, _080F88E8 @ =0x03002BE0
	adds r0, r0, r2
	ldrh r2, [r0]
	str r2, [sp, #0xc]
	movs r0, #0x1f
	adds r3, r1, #0
	ands r3, r0
	adds r0, r2, #0
	mov r5, ip
	ands r0, r5
	lsrs r0, r0, #1
	cmp r3, r0
	bls _080F8844
	subs r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080F8844:
	lsrs r1, r1, #5
	mov r0, ip
	ands r1, r0
	lsrs r0, r2, #5
	mov r2, sb
	ands r0, r2
	lsrs r0, r0, #1
	cmp r1, r0
	bls _080F885C
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_080F885C:
	lsrs r2, r4, #0xa
	mov r4, ip
	ands r2, r4
	ldr r5, [sp, #0xc]
	lsrs r0, r5, #0xa
	mov r4, sb
	ands r0, r4
	lsrs r0, r0, #1
	cmp r2, r0
	bls _080F8876
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080F8876:
	lsls r0, r2, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r3
	strh r0, [r6]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0xf
	bls _080F881A
	ldr r5, _080F88EC @ =0x083864D8
	ldr r4, _080F88E0 @ =0x00000DCC
	add r4, r8
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _080F8950
	ldrb r0, [r1, #5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x19
	ldrb r3, [r4, #0xe]
	cmp r3, r2
	bhs _080F88F0
	lsrs r1, r0, #0x1c
	adds r1, r3, r1
	strb r1, [r4, #0xe]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0, #6]
	lsrs r0, r0, #4
	ldrb r2, [r4, #0xf]
	adds r0, r0, r2
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	adds r2, r0, r5
	ldrb r0, [r2, #5]
	lsrs r0, r0, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, r0
	bls _080F88D2
	strb r0, [r4, #0xe]
_080F88D2:
	ldrb r0, [r2, #6]
	lsrs r1, r0, #1
	ldrb r0, [r4, #0xf]
	cmp r0, r1
	bls _080F8950
	strb r1, [r4, #0xf]
	b _080F8950
	.align 2, 0
_080F88E0: .4byte 0x00000DCC
_080F88E4: .4byte 0x03002BC0
_080F88E8: .4byte 0x03002BE0
_080F88EC: .4byte 0x083864D8
_080F88F0:
	strb r2, [r4, #0xe]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	ldr r5, _080F897C @ =0x083864D8
	adds r0, r0, r5
	ldrb r0, [r0, #6]
	lsrs r0, r0, #1
	strb r0, [r4, #0xf]
	mov r1, r8
	ldrb r0, [r1, #3]
	ldrb r5, [r4, #0xa]
	cmp r0, #1
	bne _080F8950
	lsls r0, r5, #3
	ldr r2, _080F897C @ =0x083864D8
	adds r0, r0, r2
	ldrb r2, [r0, #4]
	ldrh r3, [r0]
	movs r1, #2
	ldrsb r1, [r0, r1]
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #8
	str r0, [sp]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	ldr r1, _080F897C @ =0x083864D8
	adds r0, r0, r1
	movs r1, #3
	ldrsb r1, [r0, r1]
	movs r0, #0x50
	subs r0, r0, r1
	lsls r0, r0, #8
	str r0, [sp, #4]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	ldr r4, _080F897C @ =0x083864D8
	adds r0, r0, r4
	ldrb r0, [r0, #7]
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r5, #0
	bl FUN_080e83d0
	mov r5, r8
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_080F8950:
	ldr r0, _080F8980 @ =0x02001EB0
	ldrh r1, [r0, #4]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080F896A
	movs r0, #3
	bl playSound
	mov r1, r8
	ldrb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #2]
_080F896A:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F897C: .4byte 0x083864D8
_080F8980: .4byte 0x02001EB0

	thumb_func_start sd_analysis_080f8984
sd_analysis_080f8984: @ 0x080F8984
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _080F89B8 @ =0x00000DCC
	adds r2, r3, r0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080F89F4
	adds r4, r0, #0
	ldr r1, _080F89BC @ =0x083864D8
	ldrb r0, [r2, #0xa]
	lsls r0, r0, #3
	adds r5, r0, r1
	ldrb r0, [r5, #5]
	lsrs r1, r0, #4
	subs r0, r4, r1
	cmp r0, #0
	ble _080F89C6
	strb r0, [r2, #0xe]
	ldrb r3, [r2, #0xf]
	ldrb r0, [r5, #6]
	lsrs r1, r0, #4
	subs r0, r3, r1
	cmp r0, #0
	ble _080F89C0
	strb r0, [r2, #0xf]
	b _080F8A18
	.align 2, 0
_080F89B8: .4byte 0x00000DCC
_080F89BC: .4byte 0x083864D8
_080F89C0:
	movs r0, #0
	strb r0, [r2, #0xf]
	b _080F8A18
_080F89C6:
	movs r0, #0
	strb r0, [r2, #0xe]
	strb r0, [r2, #0xf]
	strb r0, [r3, #2]
	strb r0, [r3, #3]
	movs r2, #2
	ldr r3, _080F89F0 @ =0x03002BC0
	adds r4, r3, #0
	adds r4, #0x20
_080F89D8:
	lsls r0, r2, #1
	adds r1, r0, r3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _080F89D8
	b _080F8A18
	.align 2, 0
_080F89F0: .4byte 0x03002BC0
_080F89F4:
	strb r0, [r2, #0xe]
	strb r0, [r2, #0xf]
	strb r0, [r3, #2]
	strb r0, [r3, #3]
	movs r2, #2
	ldr r3, _080F8A20 @ =0x03002BC0
	adds r4, r3, #0
	adds r4, #0x20
_080F8A04:
	lsls r0, r2, #1
	adds r1, r0, r3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _080F8A04
_080F8A18:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8A20: .4byte 0x03002BC0

	thumb_func_start printThreeDigitNumber
printThreeDigitNumber: @ 0x080F8A24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r5, #0
	ldr r0, _080F8A7C @ =0x08372210
	mov r8, r0
_080F8A3C:
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, #0x3c
	add r0, r8
	ldrh r0, [r0]
	ldr r1, _080F8A80 @ =0x08372AA0
	adds r0, r0, r1
	subs r1, r7, r5
	adds r2, r6, #0
	bl print
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	bls _080F8A3C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F8A7C: .4byte 0x08372210
_080F8A80: .4byte 0x08372AA0

	thumb_func_start openSecretDisk
openSecretDisk: @ 0x080F8A84
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	ldr r1, _080F8AD8 @ =0x000064AC
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r2, #0
	beq _080F8AA4
	subs r0, r5, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bls _080F8B6C
	cmp r5, #0x6d
	bhi _080F8B6C
_080F8AA4:
	ldr r0, _080F8ADC @ =0x0203DC50
	ldr r1, [r0]
	lsrs r0, r5, #2
	adds r6, r1, r0
	ldrb r2, [r6]
	movs r3, #3
	ands r3, r5
	adds r1, r3, #4
	adds r0, r2, #0
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080F8B6C
	movs r0, #0x10
	lsls r0, r3
	orrs r2, r0
	strb r2, [r6]
	cmp r5, #5
	bhi _080F8B48
	lsls r0, r5, #2
	ldr r1, _080F8AE0 @ =_080F8AE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F8AD8: .4byte 0x000064AC
_080F8ADC: .4byte 0x0203DC50
_080F8AE0: .4byte _080F8AE4
_080F8AE4: @ jump table
	.4byte _080F8AFC @ case 0
	.4byte _080F8B06 @ case 1
	.4byte _080F8B10 @ case 2
	.4byte _080F8B1E @ case 3
	.4byte _080F8B28 @ case 4
	.4byte _080F8B32 @ case 5
_080F8AFC:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x17]
	movs r0, #4
	b _080F8B18
_080F8B06:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x17]
	movs r0, #2
	b _080F8B18
_080F8B10:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x17]
	movs r0, #8
_080F8B18:
	orrs r0, r1
	strb r0, [r2, #0x17]
	b _080F8B3E
_080F8B1E:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x19]
	movs r0, #0x40
	b _080F8B3A
_080F8B28:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x19]
	movs r0, #2
	b _080F8B3A
_080F8B32:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x19]
	movs r0, #0x80
_080F8B3A:
	orrs r0, r1
	strb r0, [r2, #0x19]
_080F8B3E:
	ldr r1, _080F8B44 @ =0x0000017B
	b _080F8B84
	.align 2, 0
_080F8B44: .4byte 0x0000017B
_080F8B48:
	cmp r5, #0x13
	bls _080F8B6C
	cmp r5, #0x5d
	bhi _080F8B68
	ldr r0, _080F8B64 @ =0x020302FC
	ldr r1, [r0]
	adds r1, r5, r1
	subs r1, #0x14
	ldrb r0, [r1]
	movs r2, #1
	orrs r0, r2
	strb r0, [r1]
	b _080F8B82
	.align 2, 0
_080F8B64: .4byte 0x020302FC
_080F8B68:
	cmp r5, #0x6d
	bls _080F8B70
_080F8B6C:
	movs r0, #0
	b _080F8B86
_080F8B70:
	ldr r1, _080F8B8C @ =0x083864B8
	adds r0, r5, #0
	subs r0, #0x5e
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl addECrystal
_080F8B82:
	ldr r1, _080F8B90 @ =0x0000010D
_080F8B84:
	adds r0, r5, r1
_080F8B86:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080F8B8C: .4byte 0x083864B8
_080F8B90: .4byte 0x0000010D

	thumb_func_start clearSecretDiskData
clearSecretDiskData: @ 0x080F8B94
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080F8BC8 @ =0x0203DC50
	str r4, [r0]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080F8BCC @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x20
	ldr r2, _080F8BD0 @ =0x05000004
	adds r1, r4, #0
	bl CpuSet
	bl clearStageDisk
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8BC8: .4byte 0x0203DC50
_080F8BCC: .4byte 0x01000008
_080F8BD0: .4byte 0x05000004

	thumb_func_start clearSecretDiskDataHard
clearSecretDiskDataHard: @ 0x080F8BD4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080F8C08 @ =0x0203DC50
	str r4, [r0]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080F8C0C @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x20
	ldr r2, _080F8C10 @ =0x05000004
	adds r1, r4, #0
	bl CpuSet
	bl clearStageDisk
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8C08: .4byte 0x0203DC50
_080F8C0C: .4byte 0x01000008
_080F8C10: .4byte 0x05000004

	thumb_func_start unlockAllSecretDisk
unlockAllSecretDisk: @ 0x080F8C14
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r6, _080F8C74 @ =0x0203DC50
	str r4, [r6]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080F8C78 @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x20
	ldr r2, _080F8C7C @ =0x05000004
	adds r1, r4, #0
	bl CpuSet
	movs r7, #3
_080F8C3C:
	ldr r2, [r6]
	lsrs r4, r5, #2
	adds r2, r2, r4
	adds r3, r5, #0
	ands r3, r7
	movs r0, #1
	lsls r0, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r6]
	adds r2, r2, r4
	movs r0, #0x10
	lsls r0, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xb3
	bls _080F8C3C
	bl clearStageDisk
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F8C74: .4byte 0x0203DC50
_080F8C78: .4byte 0x01000008
_080F8C7C: .4byte 0x05000004

	thumb_func_start clearStageDisk
clearStageDisk: @ 0x080F8C80
	push {r4, r5, lr}
	movs r2, #0
	ldr r5, _080F8CA8 @ =0x0203DC50
	adds r4, r5, #4
	movs r3, #0xff
_080F8C8A:
	adds r0, r2, r4
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #9
	bls _080F8C8A
	movs r0, #0
	strb r0, [r5, #0xe]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8CA8: .4byte 0x0203DC50

	thumb_func_start getDiskInStageRun
getDiskInStageRun: @ 0x080F8CAC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, _080F8CDC @ =0x0203DC50
	ldr r2, [r3]
	lsrs r0, r0, #0x1a
	adds r2, r2, r0
	movs r1, #3
	ands r1, r4
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #4
	ldrb r1, [r3, #0xe]
	adds r0, r0, r1
	strb r4, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F8CDC: .4byte 0x0203DC50

	thumb_func_start allSecretDiskFound
allSecretDiskFound: @ 0x080F8CE0
	push {r4, lr}
	movs r2, #0
	ldr r0, _080F8D08 @ =0x0203DC50
	ldr r3, [r0]
	movs r4, #0xf
_080F8CEA:
	lsrs r0, r2, #2
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, #0
	ands r1, r0
	movs r0, #3
	ands r0, r2
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080F8D0C
	movs r0, #0
	b _080F8D18
	.align 2, 0
_080F8D08: .4byte 0x0203DC50
_080F8D0C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xb3
	bls _080F8CEA
	movs r0, #1
_080F8D18:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
