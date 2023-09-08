	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazinMode0
blazinMode0: @ 0x0803EE30
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0803EE40
	cmp r0, #1
	beq _0803EE66
	b _0803EE80
_0803EE40:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x15
	ldr r2, _0803EE88 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803EE66:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803EE80
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_0803EE80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE88: .4byte 0xFFFFA200

	thumb_func_start FUN_0803ee8c
FUN_0803ee8c: @ 0x0803EE8C
	movs r0, #1
	bx lr

	thumb_func_start blazinMode1
blazinMode1: @ 0x0803EE90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _0803EF5E
	lsls r0, r0, #2
	ldr r1, _0803EEA4 @ =_0803EEA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803EEA4: .4byte _0803EEA8
_0803EEA8: @ jump table
	.4byte _0803EEC0 @ case 0
	.4byte _0803EEE8 @ case 1
	.4byte _0803EF32 @ case 2
	.4byte _0803EF00 @ case 3
	.4byte _0803EF22 @ case 4
	.4byte _0803EF50 @ case 5
_0803EEC0:
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x27
	ldr r2, _0803EEFC @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x73
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803EEE8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EF5E
	b _0803EF42
	.align 2, 0
_0803EEFC: .4byte 0xFFFFA200
_0803EF00:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x28
	ldr r2, _0803EF4C @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803EF22:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EF5E
_0803EF32:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0803EF42
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EF5E
_0803EF42:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0803EF5E
	.align 2, 0
_0803EF4C: .4byte 0xFFFFA200
_0803EF50:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0803EF5E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803ef64
FUN_0803ef64: @ 0x0803EF64
	movs r0, #1
	bx lr

	thumb_func_start blazinMode2
blazinMode2: @ 0x0803EF68
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0803EF78
	cmp r0, #1
	beq _0803EFA2
	b _0803EFBA
_0803EF78:
	adds r4, r5, #0
	adds r4, #0xc4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #2
	bl createBlazinTail
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r1, r0
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803EFA2:
	ldr r0, _0803EFC0 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0803EFB4
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0803EFB4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0803EFBA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803EFC0: .4byte gStageRun

	thumb_func_start true_0803efc4
true_0803efc4: @ 0x0803EFC4
	movs r0, #1
	bx lr

	thumb_func_start blazinNeutral
blazinNeutral: @ 0x0803EFC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0803F062
	cmp r0, #1
	bgt _0803EFE2
	cmp r0, #0
	beq _0803EFE8
	b _0803F262
_0803EFE2:
	cmp r0, #2
	beq _0803F0AA
	b _0803F262
_0803EFE8:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _0803F00C
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r1, r0
	adds r0, r6, #0
	bl SetMotion
	b _0803F028
_0803F00C:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #1
	ldr r2, _0803F050 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl GotoMotion
_0803F028:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F054 @ =0x08361C80
	bl SetDDP
	movs r1, #0
	str r1, [r6, #0x60]
	str r1, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r1, [r0, #4]
	str r1, [r6, #0x64]
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _0803F058
	movs r0, #1
	strb r0, [r6, #0x13]
	strb r1, [r6, #0xf]
	b _0803F05C
	.align 2, 0
_0803F050: .4byte 0xFFFFA200
_0803F054: .4byte 0x08361C80
_0803F058:
	movs r0, #0x24
	strb r0, [r6, #0x13]
_0803F05C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F062:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803F07C
	str r1, [r6, #0x68]
_0803F07C:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r2
	ble _0803F0A2
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r1, r0
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F0A2:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0803F262
_0803F0AA:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r0, r6, #0
	bl setBlazinDirection
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803F0D0
	str r1, [r6, #0x68]
_0803F0D0:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r4
	ble _0803F0DE
	str r4, [r6, #0x58]
_0803F0DE:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _0803F0EE
	b _0803F262
_0803F0EE:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0803F0F6
	b _0803F262
_0803F0F6:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0803F104
	b _0803F262
_0803F104:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	mov r8, r0
	mov sb, r1
	cmp r3, r2
	bne _0803F1E0
	ldr r0, _0803F170 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0803F184
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F174 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F178 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F17C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F180 @ =0x080FED27
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0803F252
	adds r0, r6, #0
	movs r2, #1
	bl blazin_080402fc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0803F252
	.align 2, 0
_0803F170: .4byte gMission
_0803F174: .4byte RNG_0202f388
_0803F178: .4byte 0x000343FD
_0803F17C: .4byte 0x00269EC3
_0803F180: .4byte 0x080FED27
_0803F184:
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F1D0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F1D4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F1D8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F1DC @ =0x080FECF4
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0803F252
	adds r0, r6, #0
	movs r2, #0
	bl blazin_080402fc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0803F252
	.align 2, 0
_0803F1D0: .4byte RNG_0202f388
_0803F1D4: .4byte 0x000343FD
_0803F1D8: .4byte 0x00269EC3
_0803F1DC: .4byte 0x080FECF4
_0803F1E0:
	ldr r0, _0803F20C @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0803F220
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F210 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F214 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F218 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F21C @ =0x080FED27
	b _0803F23E
	.align 2, 0
_0803F20C: .4byte gMission
_0803F210: .4byte RNG_0202f388
_0803F214: .4byte 0x000343FD
_0803F218: .4byte 0x00269EC3
_0803F21C: .4byte 0x080FED27
_0803F220:
	adds r0, r6, #0
	bl howFarBlazin
	adds r3, r0, #0
	ldr r2, _0803F270 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F274 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F278 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0803F27C @ =0x080FECF4
_0803F23E:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
_0803F252:
	strb r1, [r6, #0xd]
	strb r7, [r6, #0xe]
	mov r2, r8
	ldrb r0, [r2]
	mov r2, sb
	strb r0, [r2]
	mov r0, r8
	strb r1, [r0]
_0803F262:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F270: .4byte RNG_0202f388
_0803F274: .4byte 0x000343FD
_0803F278: .4byte 0x00269EC3
_0803F27C: .4byte 0x080FECF4

	thumb_func_start nop_0803f280
nop_0803f280: @ 0x0803F280
	movs r0, #1
	bx lr

	thumb_func_start blazinMode4
blazinMode4: @ 0x0803F284
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0803F290
	b _0803F3E8
_0803F290:
	lsls r0, r0, #2
	ldr r1, _0803F29C @ =_0803F2A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F29C: .4byte _0803F2A0
_0803F2A0: @ jump table
	.4byte _0803F2B8 @ case 0
	.4byte _0803F312 @ case 1
	.4byte _0803F33C @ case 2
	.4byte _0803F364 @ case 3
	.4byte _0803F39C @ case 4
	.4byte _0803F3D2 @ case 5
_0803F2B8:
	ldr r2, _0803F330 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803F334 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803F338 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r2, #3
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0xca
	ldrb r3, [r0]
	cmp r1, r3
	bne _0803F2DE
	adds r1, #1
	ands r1, r2
_0803F2DE:
	strb r1, [r0]
	adds r0, r4, #0
	bl blazin_080403a0
	movs r1, #0x30
	strb r1, [r4, #0x12]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x30
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #9
	movs r1, #0x30
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x2f
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F312:
	adds r0, r4, #0
	bl setBlazinDirection
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0803F328
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F3E8
_0803F328:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F3E6
	.align 2, 0
_0803F330: .4byte RNG_0202f388
_0803F334: .4byte 0x000343FD
_0803F338: .4byte 0x00269EC3
_0803F33C:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #1
	ldr r2, _0803F394 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F398 @ =0x08361CB0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F364:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0803F38E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F3E8
_0803F38E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F3E6
	.align 2, 0
_0803F394: .4byte 0xFFFFA200
_0803F398: .4byte 0x08361CB0
_0803F39C:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #2
	ldr r3, _0803F3F0 @ =0xFFFFA200
	adds r0, r3, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F3F4 @ =0x08361C80
	bl SetDDP
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0803F3F8 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F3D2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803F3E8
	movs r0, #0
	strb r1, [r4, #0xd]
_0803F3E6:
	strb r0, [r4, #0xe]
_0803F3E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F3F0: .4byte 0xFFFFA200
_0803F3F4: .4byte 0x08361C80
_0803F3F8: .4byte 0xFFFFF000

	thumb_func_start FUN_0803f3fc
FUN_0803f3fc: @ 0x0803F3FC
	movs r0, #1
	bx lr

	thumb_func_start blazinMode5
blazinMode5: @ 0x0803F400
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0803F40C
	b _0803F52C
_0803F40C:
	lsls r0, r0, #2
	ldr r1, _0803F418 @ =_0803F41C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F418: .4byte _0803F41C
_0803F41C: @ jump table
	.4byte _0803F434 @ case 0
	.4byte _0803F460 @ case 1
	.4byte _0803F480 @ case 2
	.4byte _0803F4A2 @ case 3
	.4byte _0803F4F8 @ case 4
	.4byte _0803F516 @ case 5
_0803F434:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #6
	ldr r2, _0803F478 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F47C @ =0x08361C80
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F460:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803F52C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F52A
	.align 2, 0
_0803F478: .4byte 0xFFFFA200
_0803F47C: .4byte 0x08361C80
_0803F480:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803F4F0 @ =0x08361CE0
	bl SetDDP
	adds r0, r4, #0
	bl blazin_080402a4
	adds r1, r4, #0
	adds r1, #0xcc
	str r0, [r1]
	movs r0, #0x70
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F4A2:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0803F4D2
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	bne _0803F4D2
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #6
	ldr r2, _0803F4F4 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl GotoMotion
	movs r0, #1
	strb r0, [r4, #0x13]
_0803F4D2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0xcc
	ldr r0, [r1]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0803F52C
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0803F52A
	.align 2, 0
_0803F4F0: .4byte 0x08361CE0
_0803F4F4: .4byte 0xFFFFA200
_0803F4F8:
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #7
	ldr r2, _0803F534 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803F516:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803F52C
	movs r0, #0
	strb r1, [r4, #0xd]
_0803F52A:
	strb r0, [r4, #0xe]
_0803F52C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F534: .4byte 0xFFFFA200

	thumb_func_start nop_0803f538
nop_0803f538: @ 0x0803F538
	movs r0, #1
	bx lr

	thumb_func_start blazinMode6
blazinMode6: @ 0x0803F53C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _0803F548
	b _0803F708
_0803F548:
	lsls r0, r0, #2
	ldr r1, _0803F554 @ =_0803F558
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F554: .4byte _0803F558
_0803F558: @ jump table
	.4byte _0803F578 @ case 0
	.4byte _0803F5A0 @ case 1
	.4byte _0803F5C4 @ case 2
	.4byte _0803F600 @ case 3
	.4byte _0803F630 @ case 4
	.4byte _0803F66A @ case 5
	.4byte _0803F6F4 @ case 6
	.4byte _0803F700 @ case 7
_0803F578:
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0xa
	ldr r2, _0803F5BC @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803F5C0 @ =0x08361C80
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F5A0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803F5B2
	b _0803F708
_0803F5B2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0803F708
	.align 2, 0
_0803F5BC: .4byte 0xFFFFA200
_0803F5C0: .4byte 0x08361C80
_0803F5C4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803F624 @ =0x08361D70
	bl SetDDP
	movs r0, #0
	strb r0, [r5, #0x13]
	ldr r4, _0803F628 @ =0x080FED98
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r2, _0803F62C @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r4, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F600:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803F610
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F6E2
_0803F610:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0803F6A2
	ldr r4, _0803F628 @ =0x080FED98
	b _0803F6B6
	.align 2, 0
_0803F624: .4byte 0x08361D70
_0803F628: .4byte 0x080FED98
_0803F62C: .4byte 0xFFFFA200
_0803F630:
	movs r0, #0
	strb r0, [r5, #0xf]
	strb r0, [r5, #0x13]
	ldr r4, _0803F6AC @ =0x080FED64
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r2, _0803F6B0 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r4, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r5, #0x12]
	movs r0, #0x48
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F66A:
	ldrb r0, [r5, #0xf]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0803F67E
	ldrb r1, [r5, #0x12]
	ldrb r2, [r5, #0x13]
	adds r0, r5, #0
	bl blazin_08040044
_0803F67E:
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803F694
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F6E2
_0803F694:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _0803F6B4
_0803F6A2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0803F6E2
	.align 2, 0
_0803F6AC: .4byte 0x080FED64
_0803F6B0: .4byte 0xFFFFA200
_0803F6B4:
	ldr r4, _0803F6EC @ =0x080FED64
_0803F6B6:
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r1, r5, #0
	adds r1, #0xc8
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r2, _0803F6F0 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r4, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r5, #0x12]
_0803F6E2:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0803F708
	.align 2, 0
_0803F6EC: .4byte 0x080FED64
_0803F6F0: .4byte 0xFFFFA200
_0803F6F4:
	movs r0, #0x48
	bl stopSound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803F700:
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0803F708:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_0803f710
nop_0803f710: @ 0x0803F710
	movs r0, #1
	bx lr

	thumb_func_start blazinMode7
blazinMode7: @ 0x0803F714
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xe
	bls _0803F720
	b _0803F9A2
_0803F720:
	lsls r0, r0, #2
	ldr r1, _0803F72C @ =_0803F730
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F72C: .4byte _0803F730
_0803F730: @ jump table
	.4byte _0803F76C @ case 0
	.4byte _0803F77E @ case 1
	.4byte _0803F7B6 @ case 2
	.4byte _0803F7E0 @ case 3
	.4byte _0803F814 @ case 4
	.4byte _0803F860 @ case 5
	.4byte _0803F880 @ case 6
	.4byte _0803F8AA @ case 7
	.4byte _0803F9A2 @ case 8
	.4byte _0803F9A2 @ case 9
	.4byte _0803F8D0 @ case 10
	.4byte _0803F8FE @ case 11
	.4byte _0803F918 @ case 12
	.4byte _0803F948 @ case 13
	.4byte _0803F96C @ case 14
_0803F76C:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	beq _0803F778
	b _0803F95C
_0803F778:
	movs r0, #0xa
	strb r0, [r6, #0xe]
	b _0803F9A2
_0803F77E:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F78A
	b _0803F99C
_0803F78A:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x12
	ldr r2, _0803F7D8 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F7DC @ =0x08361C80
	bl SetDDP
	movs r0, #3
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F7B6:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F7C2
	b _0803F99C
_0803F7C2:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803F7D4
	b _0803F9A2
_0803F7D4:
	b _0803F95C
	.align 2, 0
_0803F7D8: .4byte 0xFFFFA200
_0803F7DC: .4byte 0x08361C80
_0803F7E0:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F7EC
	b _0803F99C
_0803F7EC:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x13
	ldr r2, _0803F858 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F85C @ =0x08361D40
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F814:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F820
	b _0803F99C
_0803F820:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803F832
	b _0803F9A2
_0803F832:
	movs r4, #0
	ldrb r0, [r6, #0x13]
	cmp r4, r0
	bge _0803F84C
_0803F83A:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl blazin_0803ffdc
	adds r4, #1
	ldrb r2, [r6, #0x13]
	cmp r4, r2
	blt _0803F83A
_0803F84C:
	movs r0, #0x6f
	bl PlaySound
	movs r0, #2
	b _0803F95A
	.align 2, 0
_0803F858: .4byte 0xFFFFA200
_0803F85C: .4byte 0x08361D40
_0803F860:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F86C
	b _0803F99C
_0803F86C:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803F95C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F87E
	b _0803F9A2
_0803F87E:
	b _0803F95C
_0803F880:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	bne _0803F88C
	b _0803F99C
_0803F88C:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x14
	ldr r2, _0803F8CC @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F8AA:
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r1, [r0]
	cmp r1, #0
	beq _0803F99C
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803F9A2
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	b _0803F9A2
	.align 2, 0
_0803F8CC: .4byte 0xFFFFA200
_0803F8D0:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x12
	ldr r2, _0803F910 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x73
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F914 @ =0x08361C80
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F8FE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803F9A2
	b _0803F95C
	.align 2, 0
_0803F910: .4byte 0xFFFFA200
_0803F914: .4byte 0x08361C80
_0803F918:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #0x13
	ldr r2, _0803F964 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0xd0
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803F968 @ =0x08361D40
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803F948:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803F9A2
	movs r0, #8
_0803F95A:
	strb r0, [r6, #0x12]
_0803F95C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0803F9A2
	.align 2, 0
_0803F964: .4byte 0xFFFFA200
_0803F968: .4byte 0x08361D40
_0803F96C:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803F97C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F9A2
_0803F97C:
	adds r0, r6, #0
	adds r0, #0xd0
	movs r4, #0
	strb r4, [r0]
	adds r5, r6, #0
	adds r5, #0xc4
	str r4, [r5]
	adds r0, r6, #0
	movs r1, #2
	bl createBlazinTail
	str r0, [r5]
	adds r0, r6, #0
	adds r0, #0xc8
	movs r1, #0
	strh r4, [r0]
_0803F99C:
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_0803F9A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803f9a8
FUN_0803f9a8: @ 0x0803F9A8
	movs r0, #1
	bx lr

	thumb_func_start blazinMode8
blazinMode8: @ 0x0803F9AC
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	bne _0803F9BA
	movs r0, #1
	strb r0, [r1, #0xe]
_0803F9BA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803f9c0
FUN_0803f9c0: @ 0x0803F9C0
	movs r0, #1
	bx lr

	thumb_func_start blazinEX
blazinEX: @ 0x0803F9C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xa
	bls _0803F9D0
	b _0803FC64
_0803F9D0:
	lsls r0, r0, #2
	ldr r1, _0803F9DC @ =_0803F9E0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F9DC: .4byte _0803F9E0
_0803F9E0: @ jump table
	.4byte _0803FA0C @ case 0
	.4byte _0803FA5C @ case 1
	.4byte _0803FA7A @ case 2
	.4byte _0803FAA6 @ case 3
	.4byte _0803FAF0 @ case 4
	.4byte _0803FB2C @ case 5
	.4byte _0803FB50 @ case 6
	.4byte _0803FB82 @ case 7
	.4byte _0803FBBC @ case 8
	.4byte _0803FC22 @ case 9
	.4byte _0803FC4E @ case 10
_0803FA0C:
	adds r0, r6, #0
	movs r1, #1
	bl blazin_080403a0
	adds r5, r0, #0
	adds r0, r6, #0
	movs r1, #2
	bl blazin_080403a0
	adds r4, r0, #0
	adds r0, r6, #0
	movs r1, #1
	bl blazin_080403a0
	subs r4, r4, r0
	asrs r4, r4, #1
	adds r5, r5, r4
	movs r0, #0x30
	strb r0, [r6, #0x12]
	ldr r0, [r6, #0x54]
	subs r5, r5, r0
	adds r0, r5, #0
	movs r1, #0x30
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #9
	movs r1, #0x30
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	movs r0, #0x2f
	strb r0, [r6, #0x12]
	movs r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FA5C:
	adds r0, r6, #0
	bl setBlazinDirection
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _0803FA74
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FA74
	b _0803FC64
_0803FA74:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
_0803FA7A:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #1
	ldr r2, _0803FAE8 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803FAEC @ =0x08361CB0
	bl SetDDP
	movs r0, #0
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FAA6:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	cmp r0, #0
	ble _0803FABA
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0803FABA
	movs r0, #1
	strb r0, [r6, #0x13]
_0803FABA:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803FAE2
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FAE2
	b _0803FC64
_0803FAE2:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
	.align 2, 0
_0803FAE8: .4byte 0xFFFFA200
_0803FAEC: .4byte 0x08361CB0
_0803FAF0:
	movs r0, #0x72
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #2
	ldr r2, _0803FB44 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803FB48 @ =0x08361C80
	bl SetDDP
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, _0803FB4C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FB2C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803FB3E
	b _0803FC64
_0803FB3E:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
	.align 2, 0
_0803FB44: .4byte 0xFFFFA200
_0803FB48: .4byte 0x08361C80
_0803FB4C: .4byte 0xFFFFF000
_0803FB50:
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #8
	ldr r2, _0803FBB4 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803FBB8 @ =0x08361D10
	bl SetDDP
	movs r1, #0
	movs r0, #0xf0
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	strb r1, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FB82:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _0803FC64
	ldrb r0, [r6, #0xf]
	movs r1, #6
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl FUN_080401d4
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
	.align 2, 0
_0803FBB4: .4byte 0xFFFFA200
_0803FBB8: .4byte 0x08361D10
_0803FBBC:
	ldrb r1, [r6, #0xf]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0803FBFA
	ldrb r4, [r6, #0x13]
	adds r0, r1, #0
	movs r1, #6
	bl __udivsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl createBlazinEXFireBall
	ldrb r4, [r6, #0x13]
	ldrb r0, [r6, #0xf]
	movs r1, #6
	bl __udivsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0x14
	bl createBlazinEXFireBall
_0803FBFA:
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803FC1C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803FC64
_0803FC1C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0803FC62
_0803FC22:
	movs r0, #0x72
	bl stopSound
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #9
	ldr r2, _0803FC6C @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xff
	strb r0, [r6, #0x12]
	movs r0, #0
	strb r0, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803FC4E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0803FC64
	movs r0, #0
	strb r1, [r6, #0xd]
_0803FC62:
	strb r0, [r6, #0xe]
_0803FC64:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803FC6C: .4byte 0xFFFFA200

	thumb_func_start FUN_0803fc70
FUN_0803fc70: @ 0x0803FC70
	movs r0, #1
	bx lr

	thumb_func_start blazinMode10
blazinMode10: @ 0x0803FC74
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0803FC84
	cmp r6, #1
	beq _0803FCD4
	b _0803FD14
_0803FC84:
	adds r1, r5, #0
	adds r1, #0xd0
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803FCA6
	strb r6, [r1]
	adds r4, r5, #0
	adds r4, #0xc4
	str r6, [r4]
	adds r0, r5, #0
	movs r1, #2
	bl createBlazinTail
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0xc8
	strh r6, [r0]
_0803FCA6:
	movs r0, #0x48
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FCB6
	movs r0, #0x48
	bl stopSound
_0803FCB6:
	movs r0, #0x72
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FCC6
	movs r0, #0x72
	bl stopSound
_0803FCC6:
	strb r6, [r5, #0x13]
	movs r0, #0x74
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803FCD4:
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0
	beq _0803FD14
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	bne _0803FD14
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0803FD14
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #6
	ldr r2, _0803FD40 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	movs r2, #4
	movs r3, #0
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r0, #1
	strb r0, [r5, #0x13]
_0803FD14:
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, [r4]
	bl isKilled
	cmp r0, #0
	beq _0803FD50
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r1, [r2]
	cmp r1, #0
	beq _0803FD44
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0803FD50
	movs r0, #0
	str r0, [r2]
	str r0, [r4]
	movs r1, #3
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
	b _0803FD4C
	.align 2, 0
_0803FD40: .4byte 0xFFFFA200
_0803FD44:
	str r1, [r4]
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0803FD4C:
	movs r0, #0xff
	strb r0, [r5, #0xf]
_0803FD50:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803fd58
FUN_0803fd58: @ 0x0803FD58
	movs r0, #1
	bx lr

	thumb_func_start blazinKnockBackDamage
blazinKnockBackDamage: @ 0x0803FD5C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0803FD6C
	cmp r6, #1
	beq _0803FE0C
	b _0803FED2
_0803FD6C:
	movs r0, #0x74
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0xd0
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803FD94
	strb r6, [r1]
	adds r4, r5, #0
	adds r4, #0xc4
	str r6, [r4]
	adds r0, r5, #0
	movs r1, #2
	bl createBlazinTail
	str r0, [r4]
	adds r0, r5, #0
	adds r0, #0xc8
	strh r6, [r0]
_0803FD94:
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0
	bne _0803FDB6
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r1, #3
	ldr r2, _0803FDE8 @ =0xFFFFA200
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
_0803FDB6:
	movs r0, #0x48
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FDC6
	movs r0, #0x48
	bl stopSound
_0803FDC6:
	movs r0, #0x72
	bl isSoundPlaying
	cmp r0, #0
	beq _0803FDD6
	movs r0, #0x72
	bl stopSound
_0803FDD6:
	ldr r0, _0803FDEC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0803FDF4
	ldr r0, _0803FDF0 @ =0xFFFFFE00
	b _0803FDF8
	.align 2, 0
_0803FDE8: .4byte 0xFFFFA200
_0803FDEC: .4byte pZero2
_0803FDF0: .4byte 0xFFFFFE00
_0803FDF4:
	movs r0, #0x80
	lsls r0, r0, #2
_0803FDF8:
	str r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0xc0
	movs r0, #0
	str r0, [r1]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803FE0C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803FE2E
	str r1, [r5, #0x60]
_0803FE2E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r2, r1, r0
	str r2, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _0803FE5C
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r0, r3
	ldr r3, _0803FEC0 @ =0xFFFFF800
	adds r1, r2, r3
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0803FE5C
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0803FE5C:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _0803FE7E
	ldr r0, [r5, #0x54]
	ldr r1, _0803FEC4 @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0803FEC0 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0803FE7E
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0803FE7E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0803FE92
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0803FE92:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803FEA2
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803FED2
_0803FEA2:
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r1, [r2]
	cmp r1, #0
	beq _0803FEC8
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _0803FED2
	movs r0, #0
	str r0, [r2]
	movs r1, #3
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
	b _0803FECE
	.align 2, 0
_0803FEC0: .4byte 0xFFFFF800
_0803FEC4: .4byte 0xFFFFE000
_0803FEC8:
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0803FECE:
	movs r0, #0xff
	strb r0, [r5, #0xf]
_0803FED2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start blazin_0803fed8
blazin_0803fed8: @ 0x0803FED8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r6, [r5]
	cmp r6, #0
	bne _0803FF1E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803FF1E
	ldr r2, _0803FF18 @ =0x08361DD0
	movs r0, #9
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0803FF1E
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x10
	bne _0803FF1C
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
	b _0803FF1E
	.align 2, 0
_0803FF18: .4byte 0x08361DD0
_0803FF1C:
	str r6, [r5]
_0803FF1E:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803ff28
FUN_0803ff28: @ 0x0803FF28
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _0803FF40
	cmp r0, #0xe
	beq _0803FF40
	cmp r0, #0xf
	bne _0803FF80
_0803FF40:
	ldr r2, [r3, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0803FF5E
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0803FF80
_0803FF5E:
	ldr r0, _0803FF78 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0803FF80
	ldr r1, [r2, #0x54]
	ldr r0, [r4]
	cmp r1, r0
	bge _0803FF7C
	movs r0, #0xff
	b _0803FF7E
	.align 2, 0
_0803FF78: .4byte gStageRun
_0803FF7C:
	movs r0, #0xfe
_0803FF7E:
	strb r0, [r2, #0x11]
_0803FF80:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _0803FFB6
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0803FFB6
	ldr r0, [r2, #4]
	ldr r1, _0803FFBC @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0803FFB6
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xb
	beq _0803FFB6
	cmp r0, #5
	beq _0803FFB6
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803FFB6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803FFBC: .4byte 0x000200FF

	thumb_func_start FUN_0803ffc0
FUN_0803ffc0: @ 0x0803FFC0
	push {lr}
	sub sp, #8
	ldr r1, [r0, #0x54]
	str r1, [sp]
	ldr r1, [r0, #0x58]
	str r1, [sp, #4]
	mov r1, sp
	bl FUN_0809c430
	movs r0, #1
	add sp, #8
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start blazin_0803ffdc
blazin_0803ffdc: @ 0x0803FFDC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08040008 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08040010
	ldr r0, _0804000C @ =0x080FEE20
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	rsbs r0, r0, #0
	b _08040018
	.align 2, 0
_08040008: .4byte 0xFFFFD800
_0804000C: .4byte 0x080FEE20
_08040010:
	ldr r0, _08040040 @ =0x080FEE20
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
_08040018:
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	add r2, sp, #8
	str r0, [r2, #4]
	ldr r1, [sp]
	ldr r0, [sp, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0809e55c
	movs r0, #1
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08040040: .4byte 0x080FEE20

	thumb_func_start blazin_08040044
blazin_08040044: @ 0x08040044
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r7, r5, #0
	lsls r2, r2, #0x18
	lsrs r3, r2, #0x18
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804009C
	ldr r0, _08040080 @ =0x080FEDA8
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	movs r1, #0xc0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	cmp r3, #6
	bhi _08040084
	adds r0, r4, r5
	b _08040086
	.align 2, 0
_08040080: .4byte 0x080FEDA8
_08040084:
	subs r0, r4, r5
_08040086:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _08040098 @ =0x080FEDB8
	lsls r3, r3, #3
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r1, [sp]
	adds r0, r0, r1
	b _080400CA
	.align 2, 0
_08040098: .4byte 0x080FEDB8
_0804009C:
	ldr r0, _080400B4 @ =0x080FEDA8
	adds r0, r3, r0
	ldrb r1, [r0]
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r3, #6
	bhi _080400B8
	subs r0, r4, r5
	b _080400BA
	.align 2, 0
_080400B4: .4byte 0x080FEDA8
_080400B8:
	adds r0, r4, r7
_080400BA:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _08040108 @ =0x080FEDB8
	lsls r3, r3, #3
	adds r0, r3, r2
	ldr r1, [r0]
	ldr r0, [sp]
	subs r0, r0, r1
_080400CA:
	str r0, [sp]
	adds r0, r2, #4
	adds r0, r3, r0
	ldr r0, [r0]
	ldr r1, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, _0804010C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r2, sp, #8
	str r0, [r2, #4]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_0809e500
	movs r0, #1
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08040108: .4byte 0x080FEDB8
_0804010C: .4byte gSineTable

	thumb_func_start createBlazinEXFireBall
createBlazinEXFireBall: @ 0x08040110
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r3, #0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08040140
	ldr r0, _0804013C @ =0x080FEE2C
	adds r0, r3, r0
	movs r1, #0xd
	muls r1, r2, r1
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	b _08040150
	.align 2, 0
_0804013C: .4byte 0x080FEE2C
_08040140:
	ldr r0, _080401C8 @ =0x080FEE2C
	adds r0, r3, r0
	movs r1, #0xd
	muls r1, r2, r1
	ldrb r0, [r0]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_08040150:
	ldr r1, _080401CC @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	rsbs r0, r0, #0
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _080401D0 @ =0xFFFFE400
	add r1, sp, #8
	str r0, [r1, #4]
	ldr r2, [sp]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xb
	asrs r0, r0, #8
	ldr r2, [sp, #8]
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xb
	asrs r0, r0, #8
	ldr r2, [r1, #4]
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, [r4, #0x54]
	ldr r2, [sp, #8]
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	ldr r2, [r1, #4]
	adds r0, r0, r2
	str r0, [r1, #4]
	adds r3, #0x80
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	mov r2, sp
	bl _createBlazinEXFireBall
	cmp r0, #0
	beq _080401BE
	adds r0, #0xbc
	str r5, [r0]
_080401BE:
	movs r0, #1
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080401C8: .4byte 0x080FEE2C
_080401CC: .4byte gSineTable
_080401D0: .4byte 0xFFFFE400

	thumb_func_start FUN_080401d4
FUN_080401d4: @ 0x080401D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r0, #0
	mov sl, r0
	ldr r1, _08040290 @ =0x7FFFFFFF
	mov sb, r1
	movs r2, #0
	movs r0, #0xd
	mov r3, r8
	muls r3, r0, r3
	str r3, [sp]
	ldr r0, _08040294 @ =gSineTable
	mov r8, r0
_080401FE:
	ldr r0, _08040298 @ =0x080FEE2C
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r1, [sp]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	add r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r6, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	rsbs r0, r0, #0
	adds r7, r0, #0
	ldr r5, _0804029C @ =0xFFFFE400
	lsls r1, r1, #1
	adds r1, r1, r6
	lsls r1, r1, #0xb
	asrs r4, r1, #8
	lsls r0, r0, #1
	adds r0, r0, r7
	lsls r0, r0, #0xb
	asrs r0, r0, #8
	adds r5, r5, r0
	ldr r1, [sp, #0xc]
	ldr r0, [r1, #0x54]
	adds r4, r4, r0
	ldr r0, [r1, #0x58]
	adds r5, r5, r0
	ldr r0, _080402A0 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	subs r6, r0, r4
	ldr r0, [r1, #0x58]
	subs r7, r0, r5
	asrs r0, r6, #2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	asrs r1, r7, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	str r2, [sp, #4]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	ldr r2, [sp, #4]
	cmp r0, sb
	bge _08040276
	mov sb, r0
	mov sl, r2
_08040276:
	adds r2, #1
	cmp r2, #4
	ble _080401FE
	mov r0, sl
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08040290: .4byte 0x7FFFFFFF
_08040294: .4byte gSineTable
_08040298: .4byte 0x080FEE2C
_0804029C: .4byte 0xFFFFE400
_080402A0: .4byte pZero2

	thumb_func_start blazin_080402a4
blazin_080402a4: @ 0x080402A4
	push {r4, lr}
	sub sp, #0x10
	adds r2, r0, #0
	movs r3, #0x54
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080402B8
	movs r3, #0xac
_080402B8:
	ldr r1, _080402F4 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	rsbs r0, r0, #0
	str r0, [sp, #4]
	ldr r0, [r2, #0x54]
	str r0, [sp, #8]
	ldr r0, [r2, #0x58]
	add r1, sp, #8
	ldr r3, _080402F8 @ =0xFFFFF800
	adds r0, r0, r3
	str r0, [r1, #4]
	adds r0, r2, #0
	mov r2, sp
	bl blazin_0809e620
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080402F4: .4byte gSineTable
_080402F8: .4byte 0xFFFFF800

	thumb_func_start blazin_080402fc
blazin_080402fc: @ 0x080402FC
	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _0804032A
	movs r2, #0
	ldr r5, _0804031C @ =0x080FED5A
	adds r3, r5, #0
_0804030A:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08040320
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0804030A
	b _0804035C
	.align 2, 0
_0804031C: .4byte 0x080FED5A
_08040320:
	adds r0, r2, #1
	movs r1, #5
	bl __modsi3
	b _08040346
_0804032A:
	movs r2, #0
	ldr r5, _08040350 @ =0x080FED5A
	adds r3, r5, #0
_08040330:
	ldrh r1, [r3]
	cmp r1, r4
	bne _08040354
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _08040340
	adds r0, r2, #4
_08040340:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
_08040346:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0804035C
	.align 2, 0
_08040350: .4byte 0x080FED5A
_08040354:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _08040330
_0804035C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start howFarBlazin
howFarBlazin: @ 0x08040364
	push {lr}
	ldr r1, _08040380 @ =pZero2
	ldr r1, [r1]
	ldr r2, [r1, #0x54]
	ldr r0, [r0, #0x54]
	subs r1, r2, r0
	cmp r1, #0
	bgt _08040376
	subs r1, r0, r2
_08040376:
	ldr r0, _08040384 @ =0x00004EFF
	cmp r1, r0
	bgt _08040388
	movs r0, #0
	b _0804039A
	.align 2, 0
_08040380: .4byte pZero2
_08040384: .4byte 0x00004EFF
_08040388:
	ldr r0, _08040394 @ =0x00008EFF
	cmp r1, r0
	ble _08040398
	movs r0, #2
	b _0804039A
	.align 2, 0
_08040394: .4byte 0x00008EFF
_08040398:
	movs r0, #1
_0804039A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start blazin_080403a0
blazin_080403a0: @ 0x080403A0
	push {lr}
	cmp r1, #0
	bne _080403AA
	adds r0, #0xd4
	b _080403BC
_080403AA:
	cmp r1, #1
	bne _080403B2
	adds r0, #0xd8
	b _080403BC
_080403B2:
	cmp r1, #2
	beq _080403BA
	adds r0, #0xe0
	b _080403BC
_080403BA:
	adds r0, #0xdc
_080403BC:
	ldr r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start setBlazinDirection
setBlazinDirection: @ 0x080403C4
	push {lr}
	adds r2, r0, #0
	ldr r0, _080403F8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _080403FC
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08040422
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08040420
	.align 2, 0
_080403F8: .4byte pZero2
_080403FC:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08040422
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_08040420:
	strb r0, [r2, #0xa]
_08040422:
	pop {r0}
	bx r0
	.align 2, 0
