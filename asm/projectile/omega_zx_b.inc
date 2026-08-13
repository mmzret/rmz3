	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b0bb0
FUN_080b0bb0: @ 0x080B0BB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #9
	bhi _080B0BE0
	ldr r6, [r5, #0x28]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bhi _080B0BDC
	ldrb r0, [r5, #0x11]
	movs r1, #6
	bl __umodsi3
	adds r4, r0, #0
	ldrb r0, [r6, #0x11]
	movs r1, #6
	bl __umodsi3
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	bne _080B0BE0
_080B0BDC:
	movs r0, #0xa
	strb r0, [r5, #0xe]
_080B0BE0:
	ldrb r6, [r5, #0xe]
	cmp r6, #1
	beq _080B0C40
	cmp r6, #1
	bgt _080B0BF0
	cmp r6, #0
	beq _080B0BFA
	b _080B0C98
_080B0BF0:
	cmp r6, #0xa
	beq _080B0C50
	cmp r6, #0xb
	beq _080B0C76
	b _080B0C98
_080B0BFA:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B0C48 @ =0x0836D6CC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	strb r6, [r5, #0x12]
	ldr r1, _080B0C4C @ =0x0000BA02
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B0C40:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _080B0C98
	.align 2, 0
_080B0C48: .4byte 0x0836D6CC
_080B0C4C: .4byte 0x0000BA02
_080B0C50:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B0CA0 @ =0x0000BA03
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B0C76:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B0C98
	ldr r1, _080B0CA4 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B0C98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0CA0: .4byte 0x0000BA03
_080B0CA4: .4byte gProjectileFnTable

	thumb_func_start omega2_080b0ca8
omega2_080b0ca8: @ 0x080B0CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #9
	bhi _080B0CC8
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080B0CC8
	movs r0, #0xa
	strb r0, [r7, #0xe]
_080B0CC8:
	ldr r2, _080B0CF4 @ =pZero2
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B0CE0
	ldrb r0, [r7, #0xe]
	cmp r0, #0x13
	bhi _080B0CE0
	movs r0, #0x14
	strb r0, [r7, #0xe]
_080B0CE0:
	ldrb r0, [r7, #0xe]
	cmp r0, #0x14
	bls _080B0CE8
	b _080B109C
_080B0CE8:
	lsls r0, r0, #2
	ldr r1, _080B0CF8 @ =_080B0CFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B0CF4: .4byte pZero2
_080B0CF8: .4byte _080B0CFC
_080B0CFC: @ jump table
	.4byte _080B0D50 @ case 0
	.4byte _080B0D7E @ case 1
	.4byte _080B0DA4 @ case 2
	.4byte _080B0FBC @ case 3
	.4byte _080B109C @ case 4
	.4byte _080B109C @ case 5
	.4byte _080B109C @ case 6
	.4byte _080B109C @ case 7
	.4byte _080B109C @ case 8
	.4byte _080B109C @ case 9
	.4byte _080B1080 @ case 10
	.4byte _080B109C @ case 11
	.4byte _080B109C @ case 12
	.4byte _080B109C @ case 13
	.4byte _080B109C @ case 14
	.4byte _080B109C @ case 15
	.4byte _080B109C @ case 16
	.4byte _080B109C @ case 17
	.4byte _080B109C @ case 18
	.4byte _080B109C @ case 19
	.4byte _080B1080 @ case 20
_080B0D50:
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x24
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0D7E:
	ldr r0, [r7, #0x28]
	ldr r1, [r0, #0x54]
	str r1, [r7, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080B0D96
	b _080B0F6A
_080B0D96:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B0DA2
	b _080B109C
_080B0DA2:
	b _080B0F6A
_080B0DA4:
	movs r6, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x64]
	str r0, [sp]
	ldrb r1, [r7, #0x11]
	cmp r1, #0
	bne _080B0DD4
	ldr r1, _080B0DD0 @ =0xFFFFBC00
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0x13
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	subs r0, #4
	str r0, [r7, #0x60]
	movs r6, #2
	b _080B0E04
	.align 2, 0
_080B0DD0: .4byte 0xFFFFBC00
_080B0DD4:
	cmp r1, #1
	bne _080B0DF0
	ldr r2, _080B0DEC @ =0xFFFF8C00
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #3
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	subs r0, #0x1f
	str r0, [r7, #0x60]
	movs r6, #3
	b _080B0E04
	.align 2, 0
_080B0DEC: .4byte 0xFFFF8C00
_080B0DF0:
	cmp r1, #2
	bne _080B0E04
	ldr r4, _080B0F74 @ =0xFFFF5C00
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #0x23
	str r0, [r7, #0x5c]
	subs r0, #0x50
	str r0, [r7, #0x60]
	movs r6, #4
_080B0E04:
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	lsls r0, r0, #8
	str r0, [r7, #0x60]
	adds r0, r7, #0
	mov r1, sp
	bl FUN_080b0048
	adds r0, r7, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x9a
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _080B0F78 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0E6A
	ldr r0, [r7, #0x28]
	bl CreateGhost84
	str r0, [r7, #0x2c]
	cmp r0, #0
	beq _080B0E4E
	str r7, [r0, #0x2c]
_080B0E4E:
	ldr r2, _080B0F7C @ =gWindowRegBuffer
	ldrb r1, [r2, #0xe]
	movs r0, #0xe1
	ands r0, r1
	movs r3, #0
	movs r1, #0x1f
	orrs r0, r1
	strb r0, [r2, #0xe]
	ldr r1, _080B0F80 @ =gPaletteManager
	ldr r4, _080B0F84 @ =0x0000FFFF
	adds r0, r4, #0
	strh r0, [r1]
	strh r3, [r2, #6]
	strh r3, [r2, #0xa]
_080B0E6A:
	ldr r5, _080B0F88 @ =gStageRun+232
	ldr r4, [r5, #0x3c]
	ldr r1, _080B0F8C @ =0x00003FFF
	adds r0, r4, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	ldr r0, _080B0F78 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	ldr r2, [r7, #0x60]
	str r2, [sp, #8]
	ldr r1, [r7, #0x58]
	mov ip, r1
	cmp r0, #0
	beq _080B0EBC
	ldr r3, _080B0F7C @ =gWindowRegBuffer
	ldr r1, [r7, #0x68]
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	subs r1, r1, r4
	asrs r1, r1, #8
	movs r2, #0xff
	ands r1, r2
	add r0, ip
	subs r0, r0, r4
	ldr r2, [sp, #8]
	adds r0, r0, r2
	asrs r0, r0, #8
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #0xa]
	ldrh r1, [r3]
	ldr r0, _080B0F90 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r3]
_080B0EBC:
	ldr r1, _080B0F94 @ =0x020302DC
	ldr r4, [r7, #0x54]
	ldr r3, _080B0F98 @ =0xFFFF8801
	adds r4, r4, r3
	ldr r2, [r5, #0x38]
	subs r4, r4, r2
	ldr r0, [r7, #0x5c]
	adds r4, r4, r0
	asrs r0, r4, #8
	subs r0, #0x10
	mov sl, r0
	str r0, [r1]
	ldr r0, _080B0F9C @ =0x020302C4
	mov r8, r0
	ldr r0, _080B0FA0 @ =0x020302D4
	mov r1, sl
	str r1, [r0]
	mov r0, r8
	str r1, [r0]
	ldr r1, _080B0FA4 @ =0x020302CC
	movs r0, #0
	str r0, [r1]
	ldr r0, [r7, #0x64]
	adds r0, r0, r3
	subs r0, r0, r2
	subs r4, r4, r0
	lsls r1, r6, #8
	adds r0, r4, r1
	ldr r2, _080B0FA8 @ =0x020302E4
	str r0, [r2]
	subs r4, r4, r1
	ldr r1, _080B0FAC @ =0x020302C8
	str r4, [r1]
	ldr r2, [r7, #0x68]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r2, r2, r1
	ldr r3, [r5, #0x3c]
	subs r2, r2, r3
	asrs r2, r2, #8
	mov sb, r2
	add r1, ip
	subs r1, r1, r3
	ldr r2, [sp, #8]
	adds r1, r1, r2
	asrs r6, r1, #8
	mov r1, sb
	subs r5, r1, r6
	adds r1, r5, #0
	bl __divsi3
	mov r8, r0
	ldr r2, _080B0FA8 @ =0x020302E4
	str r0, [r2]
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	adds r2, r0, #0
	ldr r4, _080B0FAC @ =0x020302C8
	str r2, [r4]
	ldr r0, _080B0FB0 @ =0x020302D0
	str r6, [r0]
	ldr r0, _080B0FB4 @ =0x020302D8
	mov r1, sb
	str r1, [r0]
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	beq _080B0F66
	mov r4, sl
	str r4, [r0, #0x74]
	ldr r0, [r7, #0x2c]
	str r6, [r0, #0x78]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B0FB8 @ =0x020302C0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
	ldr r0, [r7, #0x2c]
	adds r0, #0x80
	mov r1, sb
	str r1, [r0]
	ldr r0, [r7, #0x2c]
	mov r4, r8
	str r4, [r0, #0x5c]
	str r2, [r0, #0x64]
_080B0F66:
	movs r0, #0x14
	strb r0, [r7, #0x12]
_080B0F6A:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080B109C
	.align 2, 0
_080B0F74: .4byte 0xFFFF5C00
_080B0F78: .4byte pZero2
_080B0F7C: .4byte gWindowRegBuffer
_080B0F80: .4byte gPaletteManager
_080B0F84: .4byte 0x0000FFFF
_080B0F88: .4byte gStageRun+232
_080B0F8C: .4byte 0x00003FFF
_080B0F90: .4byte 0x0000BFFF
_080B0F94: .4byte 0x020302DC
_080B0F98: .4byte 0xFFFF8801
_080B0F9C: .4byte 0x020302C4
_080B0FA0: .4byte 0x020302D4
_080B0FA4: .4byte 0x020302CC
_080B0FA8: .4byte 0x020302E4
_080B0FAC: .4byte 0x020302C8
_080B0FB0: .4byte 0x020302D0
_080B0FB4: .4byte 0x020302D8
_080B0FB8: .4byte 0x020302C0
_080B0FBC:
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r7, #0x58]
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080B1014
	ldr r1, _080B0FF4 @ =gPaletteManager
	ldr r2, _080B0FF8 @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
	ldrb r1, [r7, #0x12]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080B1004
	ldr r2, _080B0FFC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080B1000 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	b _080B1014
	.align 2, 0
_080B0FF4: .4byte gPaletteManager
_080B0FF8: .4byte 0x0000FFFF
_080B0FFC: .4byte gWindowRegBuffer
_080B1000: .4byte 0x0000BFFF
_080B1004:
	ldr r0, _080B1064 @ =gWindowRegBuffer
	ldrh r2, [r0]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r1, r2
	strh r1, [r0]
	strb r3, [r0, #0xd]
_080B1014:
	ldr r1, [r7, #0x2c]
	cmp r1, #0
	beq _080B1048
	ldr r0, _080B1068 @ =0x020302DC
	ldr r0, [r0]
	str r0, [r1, #0x74]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B106C @ =0x020302D0
	ldr r0, [r0]
	str r0, [r1, #0x78]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B1070 @ =0x020302C0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
	ldr r0, [r7, #0x2c]
	adds r0, #0x80
	ldr r1, _080B1074 @ =0x020302D8
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B1078 @ =0x020302E4
	ldr r0, [r0]
	str r0, [r1, #0x5c]
	ldr r0, _080B107C @ =0x020302C8
	ldr r0, [r0]
	str r0, [r1, #0x64]
_080B1048:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B105E
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B109C
_080B105E:
	movs r0, #0xa
	strb r0, [r7, #0xe]
	b _080B109C
	.align 2, 0
_080B1064: .4byte gWindowRegBuffer
_080B1068: .4byte 0x020302DC
_080B106C: .4byte 0x020302D0
_080B1070: .4byte 0x020302C0
_080B1074: .4byte 0x020302D8
_080B1078: .4byte 0x020302E4
_080B107C: .4byte 0x020302C8
_080B1080:
	ldr r2, _080B10AC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080B10B0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080B10B4 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080B109C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B10AC: .4byte gWindowRegBuffer
_080B10B0: .4byte 0x0000BFFF
_080B10B4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b10b8
FUN_080b10b8: @ 0x080B10B8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #1
	beq _080B1124
	cmp r6, #1
	bgt _080B10CC
	cmp r6, #0
	beq _080B10D2
	b _080B1162
_080B10CC:
	cmp r6, #0xa
	beq _080B1150
	b _080B1162
_080B10D2:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1140 @ =0x0836D6E4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1144 @ =0x0000BB06
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldr r0, _080B1148 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080B114C @ =0x00003FFF
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1124:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080B113A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1162
_080B113A:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _080B1162
	.align 2, 0
_080B1140: .4byte 0x0836D6E4
_080B1144: .4byte 0x0000BB06
_080B1148: .4byte gStageRun+232
_080B114C: .4byte 0x00003FFF
_080B1150:
	ldr r1, _080B1168 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B1162:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1168: .4byte gProjectileFnTable

	thumb_func_start FUN_080b116c
FUN_080b116c: @ 0x080B116C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080B11EA
	cmp r0, #4
	beq _080B11EA
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B1188
	cmp r6, #1
	beq _080B11B4
	b _080B1220
_080B1188:
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1228 @ =0x0836D48C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B11B4:
	ldr r2, [r5, #0x2c]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	ldr r0, _080B122C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x54]
	adds r2, #0xbc
	ldr r1, [r2]
	asrs r1, r1, #9
	adds r0, r5, #0
	adds r0, #0x74
	movs r2, #0x10
	subs r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080B1228 @ =0x0836D48C
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r5, #0x2c]
	ldrb r0, [r0, #0xe]
	cmp r0, #9
	bls _080B1220
_080B11EA:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1230 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080B1220:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1228: .4byte 0x0836D48C
_080B122C: .4byte pZero2
_080B1230: .4byte gProjectileFnTable
