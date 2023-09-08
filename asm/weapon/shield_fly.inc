	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shield_08039d3c
shield_08039d3c: @ 0x08039D3C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r1, _08039D88 @ =0x00000127
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r1, r2, #0
	cmp r1, #0xff
	bne _08039D90
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08039D8C @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08039E1E
	.align 2, 0
_08039D88: .4byte 0x00000127
_08039D8C: .4byte gWeaponFnTable
_08039D90:
	ldrb r0, [r4, #0x10]
	cmp r0, r1
	beq _08039DC4
	strb r2, [r4, #0x10]
	ldr r2, _08039DE0 @ =0x0836126C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	ldrb r1, [r4, #0x11]
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_08039DC4:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08039DE4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08039DEA
	.align 2, 0
_08039DE0: .4byte 0x0836126C
_08039DE4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08039DEA:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08039E1E
	ldr r1, _08039E24 @ =0x08361334
	ldrb r0, [r4, #0x11]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08039E1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08039E24: .4byte 0x08361334

	thumb_func_start shield_08039e28
shield_08039e28: @ 0x08039E28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xb4
	ldr r0, [r5]
	mov r8, r0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	beq _08039E46
	b _08039F48
_08039E46:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r2, #0
	mov sl, r2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r3, _08039EB8 @ =0x083612AC
	mov sb, r3
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	mov r1, sb
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	mov r0, r8
	bl CalcShieldBonus
	adds r2, r0, #0
	adds r2, #0xc
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _08039EBC @ =0x08361284
	ldrb r0, [r5, #0xd]
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sb
	bl InitWeaponBody
	ldr r0, _08039EC0 @ =onHit
	str r0, [r4, #0x24]
	ldr r1, _08039EC4 @ =0x00006D01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _08039EE6
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08039EC8
	movs r0, #0x10
	orrs r0, r2
	b _08039ECC
	.align 2, 0
_08039EB8: .4byte 0x083612AC
_08039EBC: .4byte 0x08361284
_08039EC0: .4byte onHit
_08039EC4: .4byte 0x00006D01
_08039EC8:
	movs r0, #0xef
	ands r0, r2
_08039ECC:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_08039EE6:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08039F10
	ldr r2, _08039F0C @ =0x0836128C
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	b _08039F28
	.align 2, 0
_08039F0C: .4byte 0x0836128C
_08039F10:
	ldr r2, _08039F84 @ =0x0836128C
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0x80
_08039F28:
	strb r0, [r1, #0xc]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r1, r2, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, _08039F88 @ =0x08361288
	ldrb r0, [r0, #2]
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08039F48:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08039F8C
	ldr r0, [r6, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _08039FAC
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0x80
	strb r0, [r1, #0xc]
	b _08039FAC
	.align 2, 0
_08039F84: .4byte 0x0836128C
_08039F88: .4byte 0x08361288
_08039F8C:
	ldr r0, [r6, #0x54]
	ldr r2, _08039FF8 @ =0xFFFFFA00
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _08039FAC
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xb4
	strb r4, [r0, #0xc]
_08039FAC:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08039FD2
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r1, [r0, #0xc]
	adds r1, #0x80
	strb r1, [r0, #0xc]
	movs r0, #1
	strb r0, [r6, #0x12]
_08039FD2:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08039FE8
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_08039FE8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039FF8: .4byte 0xFFFFFA00

	thumb_func_start shield_08039ffc
shield_08039ffc: @ 0x08039FFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov ip, r0
	ldr r6, [r5, #0x54]
	ldr r7, [r5, #0x58]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A038
	ldr r2, _0803A030 @ =gZeroRanges
	ldr r3, _0803A034 @ =0x00000147
	add r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r4, ip
	ldr r0, [r4, #0x54]
	subs r4, r0, r1
	b _0803A04E
	.align 2, 0
_0803A030: .4byte gZeroRanges
_0803A034: .4byte 0x00000147
_0803A038:
	ldr r2, _0803A08C @ =gZeroRanges
	ldr r3, _0803A090 @ =0x00000147
	add r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r4, ip
	ldr r0, [r4, #0x54]
	adds r4, r0, r1
_0803A04E:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r1, #2
	ldrsh r0, [r0, r1]
	mov r2, ip
	ldr r1, [r2, #0x58]
	adds r1, r1, r0
	subs r4, r4, r6
	subs r1, r1, r7
	adds r0, r4, #0
	bl FUN_0803a574
	adds r3, r0, #0
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r4, [r1, #0xc]
	subs r2, r4, r3
	adds r2, #4
	movs r0, #0xff
	ands r2, r0
	mov r8, r1
	cmp r2, #8
	bls _0803A09C
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0803A09C
	cmp r4, #0
	beq _0803A094
	adds r4, #4
	b _0803A096
	.align 2, 0
_0803A08C: .4byte gZeroRanges
_0803A090: .4byte 0x00000147
_0803A094:
	subs r4, #4
_0803A096:
	movs r0, #0xff
	ands r4, r0
	b _0803A0A8
_0803A09C:
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #4
	bl FUN_0803a5c8
	adds r4, r0, #0
_0803A0A8:
	mov r3, r8
	strb r4, [r3, #0xc]
	movs r0, #0x7f
	movs r1, #0xd8
	lsls r1, r1, #2
	ldr r3, _0803A104 @ =gSineTable
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	asrs r1, r1, #8
	movs r0, #0xc0
	lsls r0, r0, #3
	subs r1, r0, r1
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r1, #0
	muls r2, r0, r2
	asrs r2, r2, #8
	str r2, [r5, #0x5c]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	adds r6, r6, r2
	adds r7, r7, r0
	str r6, [r5, #0x54]
	str r7, [r5, #0x58]
	movs r0, #1
	strb r0, [r5, #0xe]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A104: .4byte gSineTable

	thumb_func_start shield_0803a108
shield_0803a108: @ 0x0803A108
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xb4
	ldr r0, [r5]
	mov sb, r0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	beq _0803A126
	b _0803A234
_0803A126:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r2, #0
	mov sl, r2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r0, _0803A198 @ =0x083612DC
	mov r8, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	mov r0, sb
	bl CalcShieldBonus
	adds r2, r0, #0
	adds r2, #0xc
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _0803A19C @ =0x08361284
	ldrb r0, [r5, #0xd]
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	bl InitWeaponBody
	ldr r0, _0803A1A0 @ =onHit
	str r0, [r4, #0x24]
	movs r1, #0x8e
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0803A1C2
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0803A1A4
	movs r0, #0x10
	orrs r0, r2
	b _0803A1A8
	.align 2, 0
_0803A198: .4byte 0x083612DC
_0803A19C: .4byte 0x08361284
_0803A1A0: .4byte onHit
_0803A1A4:
	movs r0, #0xef
	ands r0, r2
_0803A1A8:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0803A1C2:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A1E8
	ldr r1, _0803A1E4 @ =0x0836129C
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xc0
	lsls r0, r0, #2
	b _0803A1FC
	.align 2, 0
_0803A1E4: .4byte 0x0836129C
_0803A1E8:
	ldr r1, _0803A270 @ =0x0836129C
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _0803A274 @ =0xFFFFFD00
_0803A1FC:
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x10]
	movs r0, #0x40
	str r0, [r6, #0x64]
	ldr r0, _0803A278 @ =0x0836128C
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r0, #0
	ldrsh r1, [r1, r0]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r1, #0
	str r1, [r6, #0x60]
	movs r0, #0x20
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r1, r6, #0
	movs r2, #0
	bl CreateShieldSweep
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803A234:
	ldr r0, [r6, #0x54]
	ldr r2, [r6, #0x5c]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r1, #0x40
	str r1, [r6, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r3, r2, #0
	cmp r1, r0
	ble _0803A254
	str r0, [r6, #0x60]
_0803A254:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A27C
	ldr r0, [r6, #0x64]
	adds r0, r3, r0
	str r0, [r6, #0x5c]
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803A28A
	b _0803A288
	.align 2, 0
_0803A270: .4byte 0x0836129C
_0803A274: .4byte 0xFFFFFD00
_0803A278: .4byte 0x0836128C
_0803A27C:
	ldr r0, [r6, #0x64]
	subs r0, r2, r0
	str r0, [r6, #0x5c]
	ldr r1, _0803A2B8 @ =0xFFFFFB00
	cmp r0, r1
	bge _0803A28A
_0803A288:
	str r1, [r6, #0x5c]
_0803A28A:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	movs r2, #0xd0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_08009f6c
	adds r3, r0, #0
	ldr r0, _0803A2BC @ =0xFFFFF300
	adds r2, r3, r0
	ldr r1, [r6, #0x58]
	cmp r2, r1
	bge _0803A308
	movs r0, #0
	str r0, [r6, #0x60]
	subs r1, r1, r2
	movs r0, #0xf0
	lsls r0, r0, #4
	cmp r1, r0
	ble _0803A2C0
	movs r0, #1
	strb r0, [r6, #0x13]
	b _0803A2C2
	.align 2, 0
_0803A2B8: .4byte 0xFFFFFB00
_0803A2BC: .4byte 0xFFFFF300
_0803A2C0:
	str r2, [r6, #0x58]
_0803A2C2:
	mov r0, sb
	adds r0, #0xb4
	ldrb r0, [r0, #0xe]
	cmp r0, #1
	bne _0803A334
	ldrb r1, [r6, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0803A334
	ldr r0, [r6, #0x58]
	subs r1, r0, r2
	cmp r1, #0
	blt _0803A2EC
	ldr r0, _0803A2E8 @ =0x00000FFF
	cmp r1, r0
	ble _0803A2F4
	b _0803A334
	.align 2, 0
_0803A2E8: .4byte 0x00000FFF
_0803A2EC:
	subs r1, r2, r0
	ldr r0, _0803A304 @ =0x00000FFF
	cmp r1, r0
	bgt _0803A334
_0803A2F4:
	ldr r1, [r6, #0x54]
	movs r0, #0xd0
	lsls r0, r0, #4
	adds r2, r2, r0
	mov r0, sb
	bl CreateShieldSweepElec
	b _0803A334
	.align 2, 0
_0803A304: .4byte 0x00000FFF
_0803A308:
	subs r1, r2, r1
	ldr r0, _0803A350 @ =0x000007FF
	cmp r1, r0
	bgt _0803A334
	movs r0, #0
	str r0, [r6, #0x60]
	str r2, [r6, #0x58]
	mov r0, sb
	adds r0, #0xb4
	ldrb r0, [r0, #0xe]
	cmp r0, #1
	bne _0803A334
	ldrb r1, [r6, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0803A334
	ldr r1, [r6, #0x54]
	mov r0, sb
	adds r2, r3, #0
	bl CreateShieldSweepElec
_0803A334:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A354
	ldr r0, [r6, #0x54]
	movs r1, #0xd0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	b _0803A360
	.align 2, 0
_0803A350: .4byte 0x000007FF
_0803A354:
	ldr r0, [r6, #0x54]
	ldr r2, _0803A3B0 @ =0xFFFFF300
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
_0803A360:
	cmp r0, #0
	beq _0803A368
	movs r0, #1
	strb r0, [r6, #0x13]
_0803A368:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803A37C
	movs r0, #1
	strb r0, [r6, #0x13]
_0803A37C:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0803A390
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _0803A3A0
_0803A390:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0xc0
	strb r0, [r1, #0xc]
	movs r0, #2
	strb r0, [r6, #0xd]
	movs r0, #0
	strb r0, [r6, #0xe]
_0803A3A0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A3B0: .4byte 0xFFFFF300

	thumb_func_start shield_0803a3b4
shield_0803a3b4: @ 0x0803A3B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0xb4
	ldr r0, [r6]
	mov sb, r0
	ldrb r5, [r7, #0xe]
	cmp r5, #0
	beq _0803A3D2
	b _0803A4E6
_0803A3D2:
	ldrb r1, [r7, #0xa]
	movs r0, #4
	movs r3, #0
	mov r2, sp
	strb r3, [r2, #8]
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r0, _0803A44C @ =0x083612DC
	mov sl, r0
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	mov r1, sl
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	ldr r1, _0803A450 @ =onHit
	mov r8, r1
	str r1, [r4, #0x24]
	mov r0, sb
	bl CalcShieldBonus
	adds r2, r0, #0
	adds r2, #0xc
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _0803A454 @ =0x08361284
	ldrb r0, [r6, #0xd]
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	mov r1, sl
	bl InitWeaponBody
	mov r2, r8
	str r2, [r4, #0x24]
	movs r1, #0x8e
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x10]
	cmp r0, #2
	bne _0803A476
	ldrb r2, [r7, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0803A458
	movs r0, #0x10
	orrs r0, r2
	b _0803A45C
	.align 2, 0
_0803A44C: .4byte 0x083612DC
_0803A450: .4byte onHit
_0803A454: .4byte 0x08361284
_0803A458:
	movs r0, #0xef
	ands r0, r2
_0803A45C:
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0803A476:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A49C
	ldr r1, _0803A498 @ =0x0836129C
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	movs r0, #0
	b _0803A4B0
	.align 2, 0
_0803A498: .4byte 0x0836129C
_0803A49C:
	ldr r1, _0803A4D4 @ =0x0836129C
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	movs r0, #0x80
_0803A4B0:
	strb r0, [r7, #0x13]
	ldrb r1, [r7, #0x10]
	ldr r0, _0803A4D8 @ =0x0836128C
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r3, #0
	ldrsh r1, [r1, r3]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	mov r0, sb
	adds r0, #0xb4
	ldrb r0, [r0, #0xe]
	cmp r0, #3
	bne _0803A4DC
	movs r0, #0xc0
	b _0803A4DE
	.align 2, 0
_0803A4D4: .4byte 0x0836129C
_0803A4D8: .4byte 0x0836128C
_0803A4DC:
	movs r0, #0x80
_0803A4DE:
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0803A4E6:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A4F6
	ldrb r0, [r7, #0x13]
	subs r0, #8
	b _0803A4FA
_0803A4F6:
	ldrb r0, [r7, #0x13]
	adds r0, #8
_0803A4FA:
	strb r0, [r7, #0x13]
	ldr r2, _0803A54C @ =gSineTable
	ldrb r0, [r7, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	mov r3, sb
	ldr r1, [r3, #0x54]
	adds r3, r1, r0
	str r3, [r7, #0x54]
	ldrb r0, [r7, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #5
	ldr r0, _0803A550 @ =0xFFFFF000
	adds r1, r1, r0
	mov r2, sb
	ldr r0, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0803A564
	ldr r0, [r2, #0x54]
	cmp r3, r0
	ble _0803A554
	adds r1, r7, #0
	adds r1, #0xb4
	movs r0, #0x80
	b _0803A55A
	.align 2, 0
_0803A54C: .4byte gSineTable
_0803A550: .4byte 0xFFFFF000
_0803A554:
	adds r1, r7, #0
	adds r1, #0xb4
	movs r0, #0
_0803A55A:
	strb r0, [r1, #0xc]
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_0803A564:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803a574
FUN_0803a574: @ 0x0803A574
	push {lr}
	b _0803A58C
_0803A578:
	adds r2, r0, #0
	cmp r0, #0
	bge _0803A580
	adds r2, #0xf
_0803A580:
	asrs r0, r2, #4
	adds r2, r1, #0
	cmp r1, #0
	bge _0803A58A
	adds r2, #0xf
_0803A58A:
	asrs r1, r2, #4
_0803A58C:
	adds r2, r0, #0
	cmp r0, #0
	bge _0803A594
	rsbs r2, r0, #0
_0803A594:
	ldr r3, _0803A5C4 @ =0x00007FFF
	cmp r2, r3
	bgt _0803A578
	adds r2, r1, #0
	cmp r1, #0
	bge _0803A5A2
	rsbs r2, r1, #0
_0803A5A2:
	cmp r2, r3
	bgt _0803A578
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x80
	asrs r0, r0, #8
	movs r1, #0xff
	ands r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_0803A5C4: .4byte 0x00007FFF

	thumb_func_start FUN_0803a5c8
FUN_0803a5c8: @ 0x0803A5C8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	adds r4, r2, #0
	subs r2, r6, r3
	adds r0, r2, r4
	movs r5, #0xff
	ands r0, r5
	lsls r1, r4, #1
	cmp r0, r1
	bhi _0803A5E2
	adds r3, r6, #0
	b _0803A5F4
_0803A5E2:
	ands r2, r5
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, #0x7f
	bgt _0803A5EE
	movs r0, #1
_0803A5EE:
	muls r0, r4, r0
	adds r3, r3, r0
	ands r3, r5
_0803A5F4:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start shield_0803a5fc
shield_0803a5fc: @ 0x0803A5FC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov ip, r0
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A630
	ldr r2, _0803A628 @ =gZeroRanges
	ldr r3, _0803A62C @ =0x00000147
	add r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r4, ip
	ldr r0, [r4, #0x54]
	subs r4, r0, r1
	b _0803A646
	.align 2, 0
_0803A628: .4byte gZeroRanges
_0803A62C: .4byte 0x00000147
_0803A630:
	ldr r2, _0803A690 @ =gZeroRanges
	ldr r3, _0803A694 @ =0x00000147
	add r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r4, ip
	ldr r0, [r4, #0x54]
	adds r4, r0, r1
_0803A646:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r2, #2
	ldrsh r1, [r0, r2]
	mov r3, ip
	ldr r0, [r3, #0x58]
	adds r1, r0, r1
	ldr r0, [r5, #0x54]
	subs r4, r4, r0
	ldr r0, [r5, #0x58]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, r2
	movs r2, #0x80
	lsls r2, r2, #6
	cmp r0, r2
	bhi _0803A698
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r1, r3
	cmp r0, r2
	bhi _0803A698
	adds r0, r4, #0
	muls r0, r4, r0
	adds r4, r1, #0
	muls r4, r1, r4
	adds r1, r4, #0
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	cmp r0, r1
	bgt _0803A698
	movs r0, #1
	b _0803A69A
	.align 2, 0
_0803A690: .4byte gZeroRanges
_0803A694: .4byte 0x00000147
_0803A698:
	movs r0, #0
_0803A69A:
	pop {r4, r5}
	pop {r1}
	bx r1
