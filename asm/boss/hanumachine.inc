	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Hanumachine_Init
Hanumachine_Init: @ 0x0805B94C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, _0805BA3C @ =0x00000848
	ldr r1, _0805BA40 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _0805BA44 @ =wStaticGraphicTilenums
	adds r1, #0xd4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805BA48 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _0805BA4C @ =wStaticMotionPalIDs
	adds r0, #0xd4
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xb5
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xbd
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _0805BA50 @ =0x08364E38
	adds r0, r6, #0
	movs r2, #0x40
	bl resetBossData
	ldr r1, _0805BA54 @ =FUN_0805d568
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r6, #0x54]
	adds r1, r4, #0
	bl FUN_0800a31c
	adds r1, r6, #0
	adds r1, #0xb4
	str r0, [r1]
	ldr r0, [r6, #0x54]
	adds r1, r4, #0
	bl FUN_0800a22c
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc4
	str r5, [r0]
	ldr r1, _0805BA58 @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	adds r0, r6, #0
	bl Hanumachine_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805BA3C: .4byte 0x00000848
_0805BA40: .4byte gStaticMotionGraphics
_0805BA44: .4byte wStaticGraphicTilenums
_0805BA48: .4byte gStaticMotionGraphics+12
_0805BA4C: .4byte wStaticMotionPalIDs
_0805BA50: .4byte 0x08364E38
_0805BA54: .4byte FUN_0805d568
_0805BA58: .4byte gBossFnTable

	thumb_func_start Hanumachine_Update
Hanumachine_Update: @ 0x0805BA5C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0805BA7A
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0805BAA8
_0805BA7A:
	ldr r0, _0805BAA0 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0805BAA8
	ldr r1, _0805BAA4 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Hanumachine_Die
	b _0805BB34
	.align 2, 0
_0805BAA0: .4byte gStageRun
_0805BAA4: .4byte gBossFnTable
_0805BAA8:
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r0, [r4, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x58]
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r5, r4, #0
	adds r5, #0x8c
	cmp r0, #0x1d
	beq _0805BAE2
	ldr r0, [r5]
	ldr r1, _0805BB3C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0805BAE2
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0805BAE2
	movs r0, #0x1d
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805BAE2:
	ldr r0, [r5]
	movs r1, #1
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0xc4
	cmp r0, #0
	beq _0805BB02
	ldr r0, [r5]
	cmp r0, #0
	bne _0805BB02
	ldr r2, _0805BB40 @ =0x08365048
	movs r0, #0x1c
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
_0805BB02:
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0805BB10
	movs r0, #0
	str r0, [r5]
_0805BB10:
	ldr r1, _0805BB44 @ =0x08364DC0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0805BB24
	adds r0, r4, #0
	bl _call_via_r1
_0805BB24:
	ldr r0, _0805BB48 @ =0x08364D48
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0805BB34:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805BB3C: .4byte 0x00020001
_0805BB40: .4byte 0x08365048
_0805BB44: .4byte 0x08364DC0
_0805BB48: .4byte 0x08364D48

	thumb_func_start Hanumachine_Die
Hanumachine_Die: @ 0x0805BB4C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BC20
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #9
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0805BBCA
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0805BBA4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r3, [r0]
	movs r0, #0
	mov r1, sp
	bl FUN_080b2b40
	ldr r1, _0805BBA8 @ =0x0000B503
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805BBAC
	movs r0, #0x40
	str r0, [r4, #0x5c]
	subs r0, #0x41
	b _0805BBB4
	.align 2, 0
_0805BBA4: .4byte 0xFFFFF000
_0805BBA8: .4byte 0x0000B503
_0805BBAC:
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #1
_0805BBB4:
	str r0, [r4, #0x64]
	movs r0, #0x2f
	bl PlaySound
	adds r0, r4, #0
	bl FUN_0808a6bc
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xf]
	b _0805BBDC
_0805BBCA:
	ldr r1, _0805BC38 @ =0x0000B50F
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xf]
	movs r0, #0x40
	strb r0, [r4, #0x12]
_0805BBDC:
	movs r0, #0x4e
	bl PlaySound
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r3, _0805BC3C @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0805BC1A
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0805BC1A
	ldr r0, _0805BC40 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805BC1A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BC20:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _0805BC62
	cmp r0, #1
	bgt _0805BC44
	cmp r0, #0
	beq _0805BC4E
	b _0805BCD4
	.align 2, 0
_0805BC38: .4byte 0x0000B50F
_0805BC3C: .4byte gStageRun
_0805BC40: .4byte 0x0000FFFE
_0805BC44:
	cmp r0, #2
	beq _0805BC9C
	cmp r0, #3
	beq _0805BCB8
	b _0805BCD4
_0805BC4E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	cmp r1, #0
	bne _0805BCD4
	b _0805BC90
_0805BC62:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805BCD4
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0805BC7A
	movs r0, #0xc0
	lsls r0, r0, #4
	b _0805BC7E
_0805BC7A:
	movs r0, #0xa8
	lsls r0, r0, #5
_0805BC7E:
	str r0, [sp, #8]
	ldr r1, _0805BC98 @ =0xFFFFEE00
	add r0, sp, #8
	str r1, [r0, #4]
	adds r1, r0, #0
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
_0805BC90:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _0805BCD4
	.align 2, 0
_0805BC98: .4byte 0xFFFFEE00
_0805BC9C:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0805BCD4
	ldr r2, _0805BCB4 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _0805BCCE
	.align 2, 0
_0805BCB4: .4byte gStageRun
_0805BCB8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805BCD4
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_0805BCCE:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0805BCD4:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805bcdc
FUN_0805bcdc: @ 0x0805BCDC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #1
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0805BCF6
	movs r0, #0x19
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805BCF6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start hanu_0805bcfc
hanu_0805bcfc: @ 0x0805BCFC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805BD16
	movs r1, #0xb5
	lsls r1, r1, #8
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	strb r5, [r4, #0xf]
_0805BD16:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0805BD30
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_0805BD30:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start hanu_0805bd38
hanu_0805bd38: @ 0x0805BD38
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BD5A
	ldr r1, _0805BD78 @ =0x0000B510
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x50
	bl PlaySound
	movs r0, #0xa0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BD5A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	bne _0805BD80
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805BDA4
	ldr r1, _0805BD7C @ =0x0000B516
	b _0805BD92
	.align 2, 0
_0805BD78: .4byte 0x0000B510
_0805BD7C: .4byte 0x0000B516
_0805BD80:
	cmp r0, #2
	bne _0805BDA4
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805BDA4
	movs r1, #0xb5
	lsls r1, r1, #8
_0805BD92:
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BDA4:
	ldr r0, _0805BDBC @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0805BDB6
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805BDB6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805BDBC: .4byte gStageRun

	thumb_func_start hanu_0805bdc0
hanu_0805bdc0: @ 0x0805BDC0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl UpdateMotionGraphic
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a31c
	ldr r1, [r4]
	cmp r1, r0
	bne _0805BDEA
	adds r4, #4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a22c
	ldr r1, [r4]
	cmp r1, r0
	beq _0805BDF6
_0805BDEA:
	movs r1, #0
	movs r0, #0xd
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xf]
	strb r1, [r5, #0xe]
	b _0805BF0A
_0805BDF6:
	adds r1, r5, #0
	adds r1, #0xbd
	ldrb r2, [r1]
	movs r0, #1
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0805BE68
	ldr r0, _0805BE2C @ =gMission
	ldr r1, [r0]
	ldrb r1, [r1, #1]
	adds r6, r0, #0
	cmp r1, #4
	bls _0805BE3C
	ldr r2, _0805BE30 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805BE34 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805BE38 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #7
	ands r1, r0
	b _0805BE6E
	.align 2, 0
_0805BE2C: .4byte gMission
_0805BE30: .4byte RNG_0202f388
_0805BE34: .4byte 0x000343FD
_0805BE38: .4byte 0x00269EC3
_0805BE3C:
	ldr r2, _0805BE5C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805BE60 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805BE64 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _0805BE6E
	.align 2, 0
_0805BE5C: .4byte RNG_0202f388
_0805BE60: .4byte 0x000343FD
_0805BE64: .4byte 0x00269EC3
_0805BE68:
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x19
	ldr r6, _0805BE7C @ =gMission
_0805BE6E:
	cmp r1, #7
	bhi _0805BEDE
	lsls r0, r1, #2
	ldr r1, _0805BE80 @ =_0805BE84
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805BE7C: .4byte gMission
_0805BE80: .4byte _0805BE84
_0805BE84: @ jump table
	.4byte _0805BEA4 @ case 0
	.4byte _0805BEAE @ case 1
	.4byte _0805BEB2 @ case 2
	.4byte _0805BEB6 @ case 3
	.4byte _0805BEC8 @ case 4
	.4byte _0805BED2 @ case 5
	.4byte _0805BED6 @ case 6
	.4byte _0805BEDA @ case 7
_0805BEA4:
	movs r0, #0xd
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xf]
	b _0805BEDE
_0805BEAE:
	movs r0, #8
	b _0805BEDC
_0805BEB2:
	movs r0, #0xa
	b _0805BEDC
_0805BEB6:
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805BEC4
	movs r0, #0x16
	b _0805BEDC
_0805BEC4:
	movs r0, #4
	b _0805BEDC
_0805BEC8:
	movs r1, #0
	movs r0, #0xd
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xf]
	b _0805BEDE
_0805BED2:
	movs r0, #0x16
	b _0805BEDC
_0805BED6:
	movs r0, #0x19
	b _0805BEDC
_0805BEDA:
	movs r0, #0x13
_0805BEDC:
	strb r0, [r5, #0xd]
_0805BEDE:
	adds r2, r4, #0
	ldrb r0, [r2]
	adds r1, r0, #1
	movs r3, #0
	strb r1, [r2]
	ldr r0, [r6]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0805BEFC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0805BF06
	strb r3, [r2]
	b _0805BF06
_0805BEFC:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bls _0805BF06
	strb r3, [r4]
_0805BF06:
	movs r0, #0
	strb r0, [r5, #0xe]
_0805BF0A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start hanu_0805bf10
hanu_0805bf10: @ 0x0805BF10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BF38
	movs r1, #0xb5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805BF5C @ =0x08364E38
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0x20
	strb r0, [r4, #0x12]
_0805BF38:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805BF54
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805BF54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805BF5C: .4byte 0x08364E38

	thumb_func_start hanu_0805bf60
hanu_0805bf60: @ 0x0805BF60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BFF4
	ldr r1, _0805BFC0 @ =0x0000B501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805BFC4 @ =0x08364E68
	bl SetDDP
	movs r3, #0
	ldr r0, _0805BFC8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805BF8C
	movs r3, #1
_0805BF8C:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805BF9E
	movs r3, #1
_0805BF9E:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0805BFCC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805BFD2
	.align 2, 0
_0805BFC0: .4byte 0x0000B501
_0805BFC4: .4byte 0x08364E68
_0805BFC8: .4byte pZero2
_0805BFCC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805BFD2:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805BFE4
	movs r0, #0xe0
	lsls r0, r0, #2
	b _0805BFE6
_0805BFE4:
	ldr r0, _0805C044 @ =0xFFFFFC80
_0805BFE6:
	str r0, [r4, #0x5c]
	movs r0, #0x4e
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BFF4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0805C068
	ldr r0, [r4, #0x54]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0805C02E
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
_0805C02E:
	ldr r1, [r4, #0x54]
	adds r2, r1, r5
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	adds r3, r1, #0
	cmp r2, r0
	ble _0805C048
	movs r1, #0
	movs r0, #5
	b _0805C05A
	.align 2, 0
_0805C044: .4byte 0xFFFFFC80
_0805C048:
	ldr r2, _0805C060 @ =0xFFFFE000
	adds r1, r3, r2
	ldr r0, _0805C064 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _0805C0C4
	movs r1, #0
	movs r0, #3
_0805C05A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0805C0CA
	.align 2, 0
_0805C060: .4byte 0xFFFFE000
_0805C064: .4byte pZero2
_0805C068:
	ldr r0, [r4, #0x54]
	ldr r1, _0805C0A4 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805C08E
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
_0805C08E:
	ldr r1, [r4, #0x54]
	ldr r0, _0805C0A4 @ =0xFFFFF000
	adds r2, r1, r0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r3, r1, #0
	cmp r2, r0
	bge _0805C0A8
	movs r0, #5
	b _0805C0BA
	.align 2, 0
_0805C0A4: .4byte 0xFFFFF000
_0805C0A8:
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r3, r2
	ldr r0, _0805C0C0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0805C0C4
	movs r0, #3
_0805C0BA:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _0805C0CA
	.align 2, 0
_0805C0C0: .4byte pZero2
_0805C0C4:
	ldr r0, [r4, #0x5c]
	adds r0, r3, r0
	str r0, [r4, #0x54]
_0805C0CA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start hanu_0805c0d0
hanu_0805c0d0: @ 0x0805C0D0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C154
	adds r0, r4, #0
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C120 @ =0x0000B501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C124 @ =0x08364E98
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	ldr r2, _0805C128 @ =0xFFFFFC80
	str r2, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C130
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r4, #0x54]
	ldr r1, _0805C12C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x64]
	b _0805C142
	.align 2, 0
_0805C120: .4byte 0x0000B501
_0805C124: .4byte 0x08364E98
_0805C128: .4byte 0xFFFFFC80
_0805C12C: .4byte 0xFFFFF000
_0805C130:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x64]
	str r2, [r4, #0x60]
_0805C142:
	ldr r0, [r4, #0x58]
	ldr r2, _0805C190 @ =0xFFFFEA00
	adds r0, r0, r2
	str r0, [r4, #0x58]
	movs r0, #0x80
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C154:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0805C180
	ldr r0, [r4, #0x64]
	ldr r2, _0805C194 @ =0xFFFFD000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C188
_0805C180:
	movs r0, #6
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C188:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C190: .4byte 0xFFFFEA00
_0805C194: .4byte 0xFFFFD000

	thumb_func_start hanu_0805c198
hanu_0805c198: @ 0x0805C198
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _0805C24E
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C200 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C204 @ =0x08364EC8
	bl SetDDP
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805C208
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C20E
	.align 2, 0
_0805C200: .4byte 0x0000B506
_0805C204: .4byte 0x08364EC8
_0805C208:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C20E:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C22C
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x54]
	str r1, [r4, #0x64]
	movs r0, #0x80
	lsls r0, r0, #2
	b _0805C238
_0805C22C:
	ldr r0, [r4, #0x54]
	ldr r1, _0805C298 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r4, #0x54]
	str r1, [r4, #0x64]
	ldr r0, _0805C29C @ =0xFFFFFE00
_0805C238:
	str r0, [r4, #0x5c]
	ldr r0, _0805C2A0 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C24E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805C272
	str r0, [r4, #0x60]
_0805C272:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C292
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C292:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C298: .4byte 0xFFFFF600
_0805C29C: .4byte 0xFFFFFE00
_0805C2A0: .4byte 0xFFFFFD00

	thumb_func_start hanu_0805c2a4
hanu_0805c2a4: @ 0x0805C2A4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C2E8
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _0805C2CC @ =0x0000B514
	cmp r0, r1
	bne _0805C2D0
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _0805C2D8
	.align 2, 0
_0805C2CC: .4byte 0x0000B514
_0805C2D0:
	ldr r1, _0805C304 @ =0x0000B507
	adds r0, r4, #0
	bl SetMotion
_0805C2D8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C308 @ =0x08364EF8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C2E8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0805C2FE
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0805C2FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C304: .4byte 0x0000B507
_0805C308: .4byte 0x08364EF8

	thumb_func_start hanu_0805c30c
hanu_0805c30c: @ 0x0805C30C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C388
	ldr r1, _0805C364 @ =0x0000B50A
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C368 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C32E
	movs r3, #1
_0805C32E:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C340
	movs r3, #1
_0805C340:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0805C36C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C372
	.align 2, 0
_0805C364: .4byte 0x0000B50A
_0805C368: .4byte pZero2
_0805C36C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C372:
	strb r0, [r4, #0xa]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	movs r0, #3
	strb r0, [r4, #0x13]
	movs r0, #0x4f
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C388:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0805C3B6
	ldrb r1, [r4, #0x13]
	subs r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	bl FUN_080866a4
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	b _0805C3BA
_0805C3B6:
	subs r0, #1
	strb r0, [r4, #0x12]
_0805C3BA:
	ldrb r1, [r4, #0x13]
	cmp r1, #0
	bne _0805C3C6
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C3C6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c3cc
FUN_0805c3cc: @ 0x0805C3CC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C3E4
	ldr r1, _0805C400 @ =0x0000B50B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C3E4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0805C3FA
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0805C3FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C400: .4byte 0x0000B50B

	thumb_func_start FUN_0805c404
FUN_0805c404: @ 0x0805C404
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C476
	ldr r1, _0805C45C @ =0x0000B508
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C460 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C426
	movs r3, #1
_0805C426:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C438
	movs r3, #1
_0805C438:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0805C464
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C46A
	.align 2, 0
_0805C45C: .4byte 0x0000B508
_0805C460: .4byte pZero2
_0805C464:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C46A:
	strb r0, [r4, #0xa]
	ldr r0, _0805C4A0 @ =0xFFFFFB80
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C476:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805C49A
	movs r1, #0
	movs r0, #0xb
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C49A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C4A0: .4byte 0xFFFFFB80

	thumb_func_start hanu_0805c4a4
hanu_0805c4a4: @ 0x0805C4A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805C4DE
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C4FC @ =0x0000B509
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x58]
	ldr r1, _0805C500 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0x30
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C504 @ =0x08364F28
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C4DE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C520
	ldrb r0, [r4, #0x12]
	cmp r0, #0x20
	bne _0805C508
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x50
	b _0805C538
	.align 2, 0
_0805C4FC: .4byte 0x0000B509
_0805C500: .4byte 0xFFFFF000
_0805C504: .4byte 0x08364F28
_0805C508:
	cmp r0, #0x10
	bne _0805C514
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x40
	b _0805C538
_0805C514:
	cmp r0, #0
	bne _0805C558
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x30
	b _0805C538
_0805C520:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x20
	bne _0805C52E
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xb0
	b _0805C538
_0805C52E:
	cmp r0, #0x10
	bne _0805C544
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xc0
_0805C538:
	bl hanu_080ad598
	movs r0, #0x51
	bl PlaySound
	b _0805C558
_0805C544:
	cmp r0, #0
	bne _0805C558
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xd0
	bl hanu_080ad598
	movs r0, #0x51
	bl PlaySound
_0805C558:
	ldrb r0, [r4, #0x13]
	adds r0, #0x10
	strb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805C57A
	movs r0, #0xc
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C57A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c580
FUN_0805c580: @ 0x0805C580
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805C62A
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r6, #1
	ands r2, r6
	movs r1, #2
	bl hanu_080ad598
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C5FC @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C600 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C5C2
	movs r3, #1
_0805C5C2:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C5D4
	movs r3, #1
_0805C5D4:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	adds r1, r6, #0
	ands r1, r3
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805C604
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C60A
	.align 2, 0
_0805C5FC: .4byte 0x0000B506
_0805C600: .4byte pZero2
_0805C604:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C60A:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C66C @ =0x08364EC8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C62A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805C646
	str r0, [r4, #0x60]
_0805C646:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C666
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C666:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805C66C: .4byte 0x08364EC8

	thumb_func_start hanu_0805c670
hanu_0805c670: @ 0x0805C670
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C714
	ldr r1, _0805C6C8 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C6CC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C692
	movs r3, #1
_0805C692:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C6A4
	movs r3, #1
_0805C6A4:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0805C6D0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C6D6
	.align 2, 0
_0805C6C8: .4byte 0x0000B506
_0805C6CC: .4byte pZero2
_0805C6D0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C6D6:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C6F4
	ldr r0, _0805C6EC @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	ldr r0, _0805C6F0 @ =0xFFFFF000
	b _0805C6FE
	.align 2, 0
_0805C6EC: .4byte 0xFFFFFE80
_0805C6F0: .4byte 0xFFFFF000
_0805C6F4:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805C6FE:
	str r0, [r4, #0x64]
	ldr r0, _0805C75C @ =0xFFFFFC40
	str r0, [r4, #0x60]
	movs r0, #0xe
	strb r0, [r4, #0x12]
	movs r0, #0x50
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C714:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805C732
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805C732:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805C754
	movs r0, #0xe
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C754:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C75C: .4byte 0xFFFFFC40

	thumb_func_start FUN_0805c760
FUN_0805c760: @ 0x0805C760
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C77C
	ldr r1, _0805C7C0 @ =0x0000B50C
	adds r0, r4, #0
	movs r2, #2
	movs r3, #5
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C77C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805C79A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805C79A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805C7B8
	movs r1, #0
	movs r0, #0xf
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C7B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C7C0: .4byte 0x0000B50C

	thumb_func_start hanu_0805c7c4
hanu_0805c7c4: @ 0x0805C7C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C80E
	ldr r1, _0805C7F8 @ =0x0000B50D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C7FC @ =0x08364F58
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C800
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805C806
	.align 2, 0
_0805C7F8: .4byte 0x0000B50D
_0805C7FC: .4byte 0x08364F58
_0805C800:
	ldr r0, _0805C864 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
	ldr r0, _0805C868 @ =0xFFFFF000
_0805C806:
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C80E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C874
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C84A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805C84A:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	movs r0, #0x52
	bl PlaySound
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0805C86C
	movs r0, #0x10
	b _0805C86E
	.align 2, 0
_0805C864: .4byte 0xFFFFFC00
_0805C868: .4byte 0xFFFFF000
_0805C86C:
	movs r0, #0x11
_0805C86E:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C874:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805c87c
FUN_0805c87c: @ 0x0805C87C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0805C926
	ldr r1, _0805C8D0 @ =0x0000B50E
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805C8D4 @ =0x08364EC8
	bl SetDDP
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _0805C8D8
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C8DE
	.align 2, 0
_0805C8D0: .4byte 0x0000B50E
_0805C8D4: .4byte 0x08364EC8
_0805C8D8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C8DE:
	strb r0, [r5, #0xa]
	ldr r0, _0805C918 @ =0xFFFFFB80
	str r0, [r5, #0x60]
	movs r0, #0
	str r0, [r5, #0x5c]
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a31c
	ldr r1, [r4]
	cmp r1, r0
	bne _0805C91C
	adds r4, #4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a22c
	ldr r1, [r4]
	cmp r1, r0
	bne _0805C91C
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r1, [r5, #0x58]
	str r1, [r0]
	movs r0, #0xff
	b _0805C91E
	.align 2, 0
_0805C918: .4byte 0xFFFFFB80
_0805C91C:
	movs r0, #0x1b
_0805C91E:
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805C926:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	adds r1, #0x40
	str r1, [r5, #0x60]
	ldrb r1, [r5, #0x12]
	adds r0, r1, #0
	cmp r0, #0xff
	bne _0805C972
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, r2
	bgt _0805C986
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C986
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xbe
	strb r1, [r0]
	b _0805C986
_0805C972:
	subs r0, r1, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805C986
	movs r0, #0xe
	strb r0, [r5, #0xd]
	movs r0, #0
	strb r0, [r5, #0xe]
_0805C986:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start hanu_0805c98c
hanu_0805c98c: @ 0x0805C98C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805C9C2
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805CA3C @ =0x0000B50D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x60
	strb r0, [r1]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, _0805CA40 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	strb r5, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C9C2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CA58
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C9F2
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805C9F2:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805CA44
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CA4A
	.align 2, 0
_0805CA3C: .4byte 0x0000B50D
_0805CA40: .4byte 0xFFFFFC00
_0805CA44:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CA4A:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	rsbs r1, r1, #0
	str r1, [r4, #0x5c]
_0805CA58:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CAEA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CA82
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805CA82:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #5
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #5
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #5
	ldrb r2, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805CACC
	ldrb r0, [r4, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _0805CAD2
_0805CACC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
_0805CAD2:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	rsbs r1, r1, #0
	str r1, [r4, #0x60]
	cmp r1, #0
	bge _0805CAEA
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0805CAEA:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bls _0805CAF8
	movs r1, #0
	movs r0, #0x12
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CAF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805cb00
FUN_0805cb00: @ 0x0805CB00
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _0805CBA6
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0805CB24
	movs r1, #1
_0805CB24:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r3, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0805CB34
	movs r3, #1
_0805CB34:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0805CB56
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CB5C
_0805CB56:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CB5C:
	strb r0, [r4, #0xa]
	ldr r1, _0805CB8C @ =0x0000B50E
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805CB90 @ =0x08364EC8
	bl SetDDP
	ldr r0, _0805CB94 @ =0xFFFFFB80
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805CB98
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805CB9E
	.align 2, 0
_0805CB8C: .4byte 0x0000B50E
_0805CB90: .4byte 0x08364EC8
_0805CB94: .4byte 0xFFFFFB80
_0805CB98:
	ldr r0, _0805CBF4 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	ldr r0, _0805CBF8 @ =0xFFFFF000
_0805CB9E:
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CBA6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CBC4
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805CBC4:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CBEE
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CBEE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805CBF4: .4byte 0xFFFFFE00
_0805CBF8: .4byte 0xFFFFF000

	thumb_func_start hanu_0805cbfc
hanu_0805cbfc: @ 0x0805CBFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805CC78
	ldr r1, _0805CC54 @ =0x0000B510
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805CC58 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CC1E
	movs r3, #1
_0805CC1E:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CC30
	movs r3, #1
_0805CC30:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0805CC5C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CC62
	.align 2, 0
_0805CC54: .4byte 0x0000B510
_0805CC58: .4byte pZero2
_0805CC5C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CC62:
	strb r0, [r4, #0xa]
	movs r0, #0x50
	bl PlaySound
	movs r1, #0
	movs r0, #0x28
	strb r0, [r4, #0x12]
	strb r1, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CC78:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0805CCA0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805CCB2
	ldr r1, _0805CC9C @ =0x0000B511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _0805CCB2
	.align 2, 0
_0805CC9C: .4byte 0x0000B511
_0805CCA0:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805CCB2
	movs r1, #0
	movs r0, #0x14
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CCB2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start hanu_0805ccc0
hanu_0805ccc0: @ 0x0805CCC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805CD28
	ldr r1, _0805CCFC @ =0x0000B512
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805CD00 @ =0x08364F88
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805CD08
	ldr r0, [r4, #0x54]
	ldr r1, _0805CD04 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #6
	b _0805CD18
	.align 2, 0
_0805CCFC: .4byte 0x0000B512
_0805CD00: .4byte 0x08364F88
_0805CD04: .4byte 0xFFFFF000
_0805CD08:
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, _0805CDB0 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
	ldr r0, _0805CDB4 @ =0xFFFFD000
_0805CD18:
	str r0, [r4, #0x64]
	ldr r0, _0805CDB0 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CD28:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r6, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0805CDA4
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CD56
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805CD56:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x64]
	adds r0, r0, r2
	ldr r5, _0805CDB8 @ =0xFFFFE000
	adds r1, r1, r5
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CDAA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CD94
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_08010dd8
_0805CD94:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
_0805CDA4:
	movs r0, #0x15
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0805CDAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805CDB0: .4byte 0xFFFFFC00
_0805CDB4: .4byte 0xFFFFD000
_0805CDB8: .4byte 0xFFFFE000

	thumb_func_start FUN_0805cdbc
FUN_0805cdbc: @ 0x0805CDBC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805CDFE
	ldr r1, _0805CDE8 @ =0x0000B513
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805CDEC @ =0x08364EC8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805CDF0
	movs r0, #0x80
	lsls r0, r0, #2
	b _0805CDF2
	.align 2, 0
_0805CDE8: .4byte 0x0000B513
_0805CDEC: .4byte 0x08364EC8
_0805CDF0:
	ldr r0, _0805CE4C @ =0xFFFFFE00
_0805CDF2:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CDFE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CE1C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805CE1C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CE46
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CE46:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805CE4C: .4byte 0xFFFFFE00

	thumb_func_start FUN_0805ce50
FUN_0805ce50: @ 0x0805CE50
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0805CF06
	ldr r1, _0805CEA4 @ =0x0000B506
	adds r0, r5, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805CEA8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CE72
	movs r3, #1
_0805CE72:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CE84
	movs r3, #1
_0805CE84:
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r2, r3, #4
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	cmp r3, #0
	beq _0805CEAC
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CEB2
	.align 2, 0
_0805CEA4: .4byte 0x0000B506
_0805CEA8: .4byte pZero2
_0805CEAC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CEB2:
	strb r0, [r5, #0xa]
	ldr r0, _0805CEF4 @ =pZero2
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r0, #0x54]
	ldr r4, [r1]
	subs r0, r0, r4
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r1, r2
	adds r4, r4, r0
	ldr r0, [r5, #0x54]
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x18
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r1, _0805CEF8 @ =0xFFFFFA00
	str r1, [r5, #0x60]
	cmp r0, #0
	ble _0805CEFC
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805CEFE
	.align 2, 0
_0805CEF4: .4byte pZero2
_0805CEF8: .4byte 0xFFFFFA00
_0805CEFC:
	ldr r0, _0805CF54 @ =0xFFFFF000
_0805CEFE:
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805CF06:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x64]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CF24
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805CF24:
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CF3C
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0805CF3C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, #0
	blt _0805CF4E
	movs r1, #0
	movs r0, #0x17
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0805CF4E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805CF54: .4byte 0xFFFFF000

	thumb_func_start hanu_0805cf58
hanu_0805cf58: @ 0x0805CF58
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805CF7C
	ldr r1, _0805CF9C @ =0x0000B514
	bl SetMotion
	movs r0, #0x4e
	bl PlaySound
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	strb r5, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CF7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	bne _0805CFA0
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0805CFE0
	adds r0, r1, #1
	strb r0, [r4, #0xf]
	b _0805CFE0
	.align 2, 0
_0805CF9C: .4byte 0x0000B514
_0805CFA0:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0805CFC4
	movs r1, #0
	movs r0, #0x18
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0805CFE0
_0805CFC4:
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CFE0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0805CFE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805cfe8
FUN_0805cfe8: @ 0x0805CFE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805D02C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D00C
	ldr r0, _0805D004 @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	ldr r0, _0805D008 @ =0xFFFFF000
	b _0805D016
	.align 2, 0
_0805D004: .4byte 0xFFFFFE80
_0805D008: .4byte 0xFFFFF000
_0805D00C:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805D016:
	str r0, [r4, #0x64]
	ldr r0, _0805D07C @ =0xFFFFFC40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl hanu_080ad598
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D02C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D04A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805D04A:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D074
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D074:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805D07C: .4byte 0xFFFFFC40

	thumb_func_start FUN_0805d080
FUN_0805d080: @ 0x0805D080
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805D16C
	ldr r1, _0805D0D4 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805D0D8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805D0A2
	movs r3, #1
_0805D0A2:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805D0B4
	movs r3, #1
_0805D0B4:
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r2, r3, #4
	ldrb r1, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	cmp r3, #0
	beq _0805D0DC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805D0E2
	.align 2, 0
_0805D0D4: .4byte 0x0000B506
_0805D0D8: .4byte pZero2
_0805D0DC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805D0E2:
	strb r0, [r4, #0xa]
	ldr r0, _0805D128 @ =pZero2
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r0, #0x54]
	ldr r5, [r1]
	subs r2, r0, r5
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r2, #0
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r2, r1, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D134
	adds r0, r5, r2
	ldr r1, _0805D12C @ =0xFFFFB800
	adds r2, r0, r1
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r3, _0805D130 @ =0xFFFFE800
	adds r0, r1, r3
	cmp r2, r0
	ble _0805D148
	b _0805D146
	.align 2, 0
_0805D128: .4byte pZero2
_0805D12C: .4byte 0xFFFFB800
_0805D130: .4byte 0xFFFFE800
_0805D134:
	adds r0, r5, r2
	movs r1, #0x90
	lsls r1, r1, #7
	adds r2, r0, r1
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r5, r3
	cmp r2, r0
	bge _0805D148
_0805D146:
	adds r2, r0, #0
_0805D148:
	ldr r0, [r4, #0x54]
	subs r0, r2, r0
	movs r1, #0x1c
	bl __divsi3
	str r0, [r4, #0x5c]
	cmp r0, #0
	ble _0805D15E
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805D160
_0805D15E:
	ldr r0, _0805D1BC @ =0xFFFFF000
_0805D160:
	str r0, [r4, #0x64]
	ldr r0, _0805D1C0 @ =0xFFFFF900
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D16C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D18A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805D18A:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D1A2
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0805D1A2:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	cmp r0, #0
	blt _0805D1B4
	movs r1, #0
	movs r0, #0x1a
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D1B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D1BC: .4byte 0xFFFFF000
_0805D1C0: .4byte 0xFFFFF900

	thumb_func_start FUN_0805d1c4
FUN_0805d1c4: @ 0x0805D1C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805D1E0
	ldr r1, _0805D20C @ =0x0000B50C
	movs r2, #2
	movs r3, #5
	bl GotoMotion
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D1E0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805D204
	movs r1, #0
	movs r0, #0x1b
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D204:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D20C: .4byte 0x0000B50C

	thumb_func_start FUN_0805d210
FUN_0805d210: @ 0x0805D210
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805D268
	adds r0, r4, #0
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805D250 @ =0x0000B50D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0xe0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805D254 @ =0x08364F58
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D258
	movs r0, #0x80
	lsls r0, r0, #3
	b _0805D25A
	.align 2, 0
_0805D250: .4byte 0x0000B50D
_0805D254: .4byte 0x08364F58
_0805D258:
	ldr r0, _0805D2BC @ =0xFFFFFC00
_0805D25A:
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D268:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0805D2C0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D29A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805D29A:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	movs r1, #0
	movs r0, #0x1c
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0805D308
	.align 2, 0
_0805D2BC: .4byte 0xFFFFFC00
_0805D2C0:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D308
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D2EA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805D2EA:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0x1c
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0805D308:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d310
FUN_0805d310: @ 0x0805D310
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _0805D376
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805D350 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805D354 @ =0x08364E38
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D360
	ldr r0, _0805D358 @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	ldr r0, _0805D35C @ =0xFFFFF000
	b _0805D36A
	.align 2, 0
_0805D350: .4byte 0x0000B506
_0805D354: .4byte 0x08364E38
_0805D358: .4byte 0xFFFFFE80
_0805D35C: .4byte 0xFFFFF000
_0805D360:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805D36A:
	str r0, [r4, #0x64]
	ldr r0, _0805D3C4 @ =0xFFFFFC40
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D376:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D394
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805D394:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D3BE
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D3BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805D3C4: .4byte 0xFFFFFC40

	thumb_func_start FUN_0805d3c8
FUN_0805d3c8: @ 0x0805D3C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0805D3D4
	b _0805D4E2
_0805D3D4:
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldr r1, _0805D438 @ =0x0000B502
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805D43C @ =0x08364E38
	bl SetDDP
	adds r4, r5, #0
	adds r4, #0xbc
	ldrb r1, [r4]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r0, [r4]
	movs r1, #0x4a
	adds r1, r1, r5
	mov ip, r1
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #4
	mov r0, ip
	ldrb r3, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r4]
	ands r2, r0
	cmp r2, #0
	beq _0805D440
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805D446
	.align 2, 0
_0805D438: .4byte 0x0000B502
_0805D43C: .4byte 0x08364E38
_0805D440:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805D446:
	strb r0, [r5, #0xa]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D498
	ldr r0, [r5, #0x54]
	ldr r2, _0805D488 @ =0xFFFFEE00
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	ldr r2, _0805D48C @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D480
	ldr r0, [r5, #0x54]
	ldr r1, _0805D488 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0805D48C @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a31c
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805D480:
	ldr r0, _0805D490 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldr r0, _0805D494 @ =0xFFFFF000
	b _0805D4D2
	.align 2, 0
_0805D488: .4byte 0xFFFFEE00
_0805D48C: .4byte 0xFFFFF800
_0805D490: .4byte 0xFFFFFE00
_0805D494: .4byte 0xFFFFF000
_0805D498:
	ldr r0, [r5, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	ldr r2, _0805D518 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D4C8
	ldr r0, [r5, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0805D518 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a22c
	ldr r1, _0805D51C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805D4C8:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805D4D2:
	str r0, [r5, #0x64]
	ldr r0, _0805D520 @ =0xFFFFFC00
	str r0, [r5, #0x60]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805D4E2:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	adds r4, r0, r1
	ldr r1, [r5, #0x58]
	adds r0, r4, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D536
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D524
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r4, r0
	ble _0805D536
	b _0805D52E
	.align 2, 0
_0805D518: .4byte 0xFFFFF800
_0805D51C: .4byte 0xFFFFEE00
_0805D520: .4byte 0xFFFFFC00
_0805D524:
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r4, r0
	bge _0805D536
_0805D52E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805D536:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, #0x40
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D560
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0805D560:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d568
FUN_0805d568: @ 0x0805D568
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805D58E
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #0x2c]
	ldr r2, [r2, #0x2c]
	movs r3, #0
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _0805D588
	movs r3, #1
_0805D588:
	adds r0, r2, #0
	adds r0, #0xbc
	strb r3, [r0]
_0805D58E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d594
FUN_0805d594: @ 0x0805D594
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0805D5C4
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	ldr r2, _0805D5CC @ =0xFFFFE000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0805D5C4
	movs r0, #0
_0805D5C4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805D5CC: .4byte 0xFFFFE000
