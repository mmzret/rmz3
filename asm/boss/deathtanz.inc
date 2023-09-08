	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start deathtanzAI2
deathtanzAI2: @ 0x08048D6C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	movs r3, #0
	adds r0, #0xb4
	mov r2, ip
	ldr r1, [r2, #0x54]
	ldr r2, [r0]
	cmp r1, r2
	bge _08048D84
	movs r3, #1
_08048D84:
	ldr r0, _08048DA4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r2
	bge _08048D92
	movs r0, #1
	eors r3, r0
_08048D92:
	ldr r7, _08048DA8 @ =RNG_0202f388
	mov r5, ip
	adds r5, #0xc3
	ldr r0, _08048DAC @ =0x08362E84
	mov r8, r0
	lsls r6, r3, #4
	mov r4, ip
	adds r4, #0xc4
	b _08048DBA
	.align 2, 0
_08048DA4: .4byte pZero2
_08048DA8: .4byte RNG_0202f388
_08048DAC: .4byte 0x08362E84
_08048DB0:
	ldr r0, _08048DF8 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bhi _08048DE6
_08048DBA:
	ldr r1, [r7]
	ldr r0, _08048DFC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08048E00 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r3, r0, #0x11
	movs r0, #0xf
	ands r3, r0
	adds r0, r3, r6
	add r0, r8
	ldrb r1, [r5]
	ldrb r2, [r0]
	cmp r1, r2
	bne _08048DE2
	ldrb r0, [r4]
	cmp r0, #0
	bne _08048DBA
_08048DE2:
	cmp r2, #0x11
	beq _08048DB0
_08048DE6:
	adds r0, r3, r6
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r5]
	cmp r0, r1
	bne _08048E04
	ldrb r0, [r4]
	adds r0, #1
	b _08048E08
	.align 2, 0
_08048DF8: .4byte gMission
_08048DFC: .4byte 0x000343FD
_08048E00: .4byte 0x00269EC3
_08048E04:
	movs r0, #0
	strb r1, [r5]
_08048E08:
	strb r0, [r4]
	adds r0, r3, r6
	add r0, r8
	ldrb r0, [r0]
	movs r1, #0
	mov r2, ip
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08048e24
FUN_08048e24: @ 0x08048E24
	push {r4, lr}
	ldr r1, [r0, #0xc]
	ldr r3, [r1, #0x2c]
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08048E56
	adds r1, r2, #0
	adds r1, #0xc8
	ldr r0, [r3, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r3, #0x58]
	str r0, [r1]
	movs r4, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r3, #0x54]
	cmp r1, r0
	bge _08048E50
	movs r4, #1
_08048E50:
	adds r0, r2, #0
	adds r0, #0xc2
	strb r4, [r0]
_08048E56:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start tryKillDeathtanz
tryKillDeathtanz: @ 0x08048E5C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08048E7C
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08048EC8
_08048E7C:
	ldr r0, _08048EB4 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08048EC8
	movs r0, #0x61
	bl PlaySound
	ldr r1, _08048EB8 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _08048EBC
	movs r0, #1
	strb r0, [r4, #0xd]
	b _08048EBE
	.align 2, 0
_08048EB4: .4byte gStageRun
_08048EB8: .4byte gBossFnTable
_08048EBC:
	strb r1, [r4, #0xd]
_08048EBE:
	adds r0, r4, #0
	bl Deathtanz_Die
	movs r0, #1
	b _08048ECA
_08048EC8:
	movs r0, #0
_08048ECA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Deathtanz_Init
Deathtanz_Init: @ 0x08048ED0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _08049014 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _08049018 @ =0x08362EA4
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _0804901C @ =0x083627DC
	adds r0, r7, #0
	movs r2, #0x40
	bl resetBossData
	ldr r1, _08049020 @ =FUN_08048e24
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	ldrb r0, [r7, #0x10]
	str r0, [sp]
	cmp r0, #0
	bne _08048FFC
	movs r4, #0x87
	lsls r4, r4, #3
	ldr r1, _08049024 @ =gStaticMotionGraphics
	mov r8, r1
	adds r0, r4, r1
	ldr r6, _08049028 @ =wStaticGraphicTilenums
	adds r1, r6, #0
	adds r1, #0x6c
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0804902C @ =gStaticMotionGraphics+12
	mov sl, r0
	add r4, sl
	ldr r5, _08049030 @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x6c
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _08049034 @ =0x0000044C
	add r8, r4
	adds r6, #0x6e
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
	bl LoadGraphic
	add r4, sl
	adds r5, #0x6e
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	adds r4, r7, #0
	adds r4, #0xb4
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r4]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r4]
	adds r1, r7, #0
	adds r1, #0xb8
	ldr r0, [r7, #0x58]
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbd
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xc1
	movs r0, #3
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0xc3
	ldrb r0, [r2]
	movs r1, #0xff
	orrs r0, r1
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xc4
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0]
_08048FFC:
	adds r0, r7, #0
	bl Deathtanz_Update
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08049014: .4byte gBossFnTable
_08049018: .4byte 0x08362EA4
_0804901C: .4byte 0x083627DC
_08049020: .4byte FUN_08048e24
_08049024: .4byte gStaticMotionGraphics
_08049028: .4byte wStaticGraphicTilenums
_0804902C: .4byte gStaticMotionGraphics+12
_08049030: .4byte wStaticMotionPalIDs
_08049034: .4byte 0x0000044C

	thumb_func_start Deathtanz_Update
Deathtanz_Update: @ 0x08049038
	push {r4, lr}
	adds r4, r0, #0
	bl tryKillDeathtanz
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08049066
	ldr r1, _0804906C @ =0x0836272C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08049070 @ =0x08362780
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08049066:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804906C: .4byte 0x0836272C
_08049070: .4byte 0x08362780

	thumb_func_start Deathtanz_Die
Deathtanz_Die: @ 0x08049074
	push {lr}
	ldr r2, _08049088 @ =0x083627D4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08049088: .4byte 0x083627D4

	thumb_func_start nop_0804908c
nop_0804908c: @ 0x0804908C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08049090
FUN_08049090: @ 0x08049090
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080490B2
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080490B2
	movs r1, #0
	movs r0, #0x14
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080490B2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start deathtanzMode0
deathtanzMode0: @ 0x080490B8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _080490C6
	b _0804931E
_080490C6:
	lsls r0, r0, #2
	ldr r1, _080490D0 @ =_080490D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080490D0: .4byte _080490D4
_080490D4: @ jump table
	.4byte _08049104 @ case 0
	.4byte _08049112 @ case 1
	.4byte _0804912C @ case 2
	.4byte _0804913A @ case 3
	.4byte _08049160 @ case 4
	.4byte _080491AC @ case 5
	.4byte _08049200 @ case 6
	.4byte _08049228 @ case 7
	.4byte _08049254 @ case 8
	.4byte _08049290 @ case 9
	.4byte _080492E4 @ case 10
	.4byte _08049306 @ case 11
_08049104:
	ldr r1, _08049128 @ =0x0000A701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049112:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08049126
	b _0804931E
_08049126:
	b _080492D8
	.align 2, 0
_08049128: .4byte 0x0000A701
_0804912C:
	ldr r1, _08049158 @ =0x0000A702
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804913A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x70]
	ldr r1, _0804915C @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x83
	lsls r1, r1, #9
	cmp r0, r1
	beq _08049150
	b _080492CE
_08049150:
	movs r0, #0x5b
	bl PlaySound
	b _080492CE
	.align 2, 0
_08049158: .4byte 0x0000A702
_0804915C: .4byte 0x00FFFF00
_08049160:
	ldr r1, _080491F8 @ =0x0000A703
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080491FC @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	adds r3, r0, #0
	str r3, [r4, #0x2c]
	cmp r3, #0
	beq _0804919E
	adds r1, r3, #0
	adds r1, #0x74
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	str r2, [r3, #0x78]
_0804919E:
	movs r1, #0
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080491AC:
	ldr r1, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #7
	subs r0, r0, r1
	cmp r0, #0
	bge _080491BA
	adds r0, #0xf
_080491BA:
	asrs r0, r0, #4
	adds r5, r1, r0
	str r5, [r4, #0x5c]
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _080491DC
	adds r2, r5, #0
	cmp r5, #0
	bge _080491CE
	adds r2, r5, #7
_080491CE:
	asrs r2, r2, #3
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	muls r0, r2, r0
	adds r0, r5, r0
	str r0, [r3, #0x78]
_080491DC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080491EE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080491EE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0804931E
	.align 2, 0
_080491F8: .4byte 0x0000A703
_080491FC: .4byte 0xFFFFE000
_08049200:
	ldr r1, _08049250 @ =0x0000A704
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x29
	bl LoadBlink
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049228:
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _08049246
	ldr r5, [r4, #0x5c]
	adds r2, r5, #0
	cmp r5, #0
	bge _08049238
	adds r2, r5, #7
_08049238:
	asrs r2, r2, #3
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	muls r0, r2, r0
	adds r0, r5, r0
	str r0, [r3, #0x78]
_08049246:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r0, #0x29
	b _080492C4
	.align 2, 0
_08049250: .4byte 0x0000A704
_08049254:
	ldr r1, _080492E0 @ =0x0000A705
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x29
	bl ClearBlink
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x2a
	bl LoadBlink
	movs r0, #0x45
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080bdaf8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049290:
	ldr r1, [r4, #0x5c]
	rsbs r0, r1, #0
	cmp r0, #0
	bge _0804929A
	adds r0, #0xf
_0804929A:
	asrs r0, r0, #4
	adds r5, r1, r0
	str r5, [r4, #0x5c]
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _080492BC
	adds r2, r5, #0
	cmp r5, #0
	bge _080492AE
	adds r2, r5, #7
_080492AE:
	asrs r2, r2, #3
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	muls r0, r2, r0
	adds r0, r5, r0
	str r0, [r3, #0x78]
_080492BC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r0, #0x2a
_080492C4:
	bl GetBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080492CE:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804931E
_080492D8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804931E
	.align 2, 0
_080492E0: .4byte 0x0000A705
_080492E4:
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _080492F2
	adds r1, r3, #0
	adds r1, #0x77
	movs r0, #1
	strb r0, [r1]
_080492F2:
	movs r0, #0x2a
	bl ClearBlink
	ldr r1, _08049328 @ =0x0000A706
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049306:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _0804932C @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r2, #1
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne _0804931E
	strb r2, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804931E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08049328: .4byte 0x0000A706
_0804932C: .4byte gStageRun

	thumb_func_start deathtanzNeutral
deathtanzNeutral: @ 0x08049330
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08049340
	cmp r0, #1
	beq _080493B2
	b _080493EA
_08049340:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08049390 @ =0x083627F4
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _0804939C
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
	beq _08049394
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804939A
	.align 2, 0
_08049390: .4byte 0x083627F4
_08049394:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804939A:
	strb r0, [r4, #0xa]
_0804939C:
	movs r0, #0
	strb r0, [r5]
	movs r0, #8
	strb r0, [r4, #0x12]
	ldr r1, _080493F0 @ =0x0000A706
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080493B2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080493EA
	ldr r0, _080493F4 @ =pZero2
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080493EA
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080493EA
	adds r0, r4, #0
	bl deathtanzAI2
_080493EA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080493F0: .4byte 0x0000A706
_080493F4: .4byte pZero2

	thumb_func_start deathtanzMode2
deathtanzMode2: @ 0x080493F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0804945E
	cmp r0, #1
	bgt _0804940C
	cmp r0, #0
	beq _08049418
	b _0804959C
_0804940C:
	cmp r0, #2
	beq _08049480
	cmp r0, #3
	bne _08049416
	b _08049538
_08049416:
	b _0804959C
_08049418:
	strb r0, [r4, #0x12]
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	ble _0804942A
	movs r2, #1
_0804942A:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804943A
	cmp r2, #0
	beq _0804943E
	b _08049442
_0804943A:
	cmp r2, #0
	beq _08049442
_0804943E:
	movs r0, #2
	b _0804959A
_08049442:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08049478 @ =0x0836283C
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0x12]
	ldr r1, _0804947C @ =0x0000A707
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804945E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08049470
	b _0804959C
_08049470:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804959A
	.align 2, 0
_08049478: .4byte 0x0836283C
_0804947C: .4byte 0x0000A707
_08049480:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080494C8
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
	beq _080494C0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080494C6
_080494C0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080494C6:
	strb r0, [r4, #0xa]
_080494C8:
	ldr r3, _08049508 @ =0x08362EA6
	ldr r2, _0804950C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08049510 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08049514 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xbc
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08049520
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08049518 @ =0x08362884
	bl SetDDP
	ldr r1, _0804951C @ =0x0000A708
	adds r0, r4, #0
	bl SetMotion
	b _08049532
	.align 2, 0
_08049508: .4byte 0x08362EA6
_0804950C: .4byte RNG_0202f388
_08049510: .4byte 0x000343FD
_08049514: .4byte 0x00269EC3
_08049518: .4byte 0x08362884
_0804951C: .4byte 0x0000A708
_08049520:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804957C @ =0x083628B4
	bl SetDDP
	ldr r1, _08049580 @ =0x0000A709
	adds r0, r4, #0
	bl SetMotion
_08049532:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049538:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r5, [r0]
	cmp r5, #3
	bne _0804959C
	movs r0, #0x5c
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _08049596
	ldr r2, _08049584 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08049588 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804958C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08049590
	movs r0, #6
	strb r0, [r4, #0xd]
	b _08049598
	.align 2, 0
_0804957C: .4byte 0x083628B4
_08049580: .4byte 0x0000A709
_08049584: .4byte RNG_0202f388
_08049588: .4byte 0x000343FD
_0804958C: .4byte 0x00269EC3
_08049590:
	movs r0, #9
	strb r0, [r4, #0xd]
	b _08049598
_08049596:
	strb r5, [r4, #0xd]
_08049598:
	movs r0, #0
_0804959A:
	strb r0, [r4, #0xe]
_0804959C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start deathtanzMode3
deathtanzMode3: @ 0x080495A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _080495B0
	b _08049764
_080495B0:
	lsls r0, r0, #2
	ldr r1, _080495BC @ =_080495C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080495BC: .4byte _080495C0
_080495C0: @ jump table
	.4byte _080495D8 @ case 0
	.4byte _08049658 @ case 1
	.4byte _08049694 @ case 2
	.4byte _080496AC @ case 3
	.4byte _080496EC @ case 4
	.4byte _08049704 @ case 5
_080495D8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049604 @ =0x083628FC
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	lsls r0, r0, #5
	adds r0, #0x10
	lsls r6, r0, #8
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r5, #0x54]
	ldr r2, [r0]
	cmp r1, r2
	bge _0804960C
	ldr r1, _08049608 @ =0xFFFF8800
	adds r0, r6, r1
	subs r6, r2, r0
	b _08049612
	.align 2, 0
_08049604: .4byte 0x083628FC
_08049608: .4byte 0xFFFF8800
_0804960C:
	ldr r1, _0804968C @ =0xFFFF8800
	adds r0, r6, r1
	adds r6, r2, r0
_08049612:
	movs r4, #0xc3
	lsls r4, r4, #3
	adds r0, r4, #0
	bl Sqrt
	adds r1, r0, #0
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	bl __divsi3
	str r0, [r5, #0x5c]
	adds r0, r4, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	rsbs r1, r1, #0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	str r1, [r5, #0x60]
	ldr r1, _08049690 @ =0x0000A70A
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049658:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x2a
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08049670
	str r1, [r5, #0x60]
_08049670:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	cmp r1, #0
	ble _08049682
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049682:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08049764
	.align 2, 0
_0804968C: .4byte 0xFFFF8800
_08049690: .4byte 0x0000A70A
_08049694:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080496E4 @ =0x08362944
	bl SetDDP
	ldr r1, _080496E8 @ =0x0000A70B
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080496AC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x2a
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080496CA
	str r1, [r5, #0x60]
_080496CA:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r1, [r1]
	cmp r0, r1
	ble _08049764
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _08049762
	.align 2, 0
_080496E4: .4byte 0x08362944
_080496E8: .4byte 0x0000A70B
_080496EC:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049730 @ =0x083628B4
	bl SetDDP
	ldr r1, _08049734 @ =0x0000A709
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049704:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049764
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08049740
	ldr r0, _08049738 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	ldr r1, _0804973C @ =0x000045FF
	cmp r0, r1
	bls _08049750
	b _0804975C
	.align 2, 0
_08049730: .4byte 0x083628B4
_08049734: .4byte 0x0000A709
_08049738: .4byte pZero2
_0804973C: .4byte 0x000045FF
_08049740:
	ldr r0, _08049754 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r5, #0x54]
	ldr r1, [r1, #0x54]
	subs r0, r0, r1
	ldr r1, _08049758 @ =0x000045FF
	cmp r0, r1
	bhi _0804975C
_08049750:
	movs r0, #4
	b _0804975E
	.align 2, 0
_08049754: .4byte pZero2
_08049758: .4byte 0x000045FF
_0804975C:
	movs r0, #5
_0804975E:
	strb r0, [r5, #0xd]
	movs r0, #0
_08049762:
	strb r0, [r5, #0xe]
_08049764:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start deathtanzMode4
deathtanzMode4: @ 0x0804976C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _08049778
	b _08049894
_08049778:
	lsls r0, r0, #2
	ldr r1, _08049784 @ =_08049788
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08049784: .4byte _08049788
_08049788: @ jump table
	.4byte _080497A8 @ case 0
	.4byte _080497CE @ case 1
	.4byte _080497C0 @ case 2
	.4byte _080497CE @ case 3
	.4byte _080497EC @ case 4
	.4byte _08049826 @ case 5
	.4byte _08049864 @ case 6
	.4byte _0804987C @ case 7
_080497A8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080497B8 @ =0x083627F4
	bl SetDDP
	ldr r1, _080497BC @ =0x0000A732
	b _080497C2
	.align 2, 0
_080497B8: .4byte 0x083627F4
_080497BC: .4byte 0x0000A732
_080497C0:
	ldr r1, _080497E8 @ =0x0000A733
_080497C2:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080497CE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049894
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08049894
	.align 2, 0
_080497E8: .4byte 0x0000A733
_080497EC:
	movs r0, #0x5e
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08049844 @ =0x0836298C
	bl SetDDP
	movs r0, #0xe0
	lsls r0, r0, #1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xa
	rsbs r2, r0, #0
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08049818
	str r2, [r4, #0x5c]
_08049818:
	ldr r1, _08049848 @ =0x0000A734
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049826:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804984C
	adds r0, r2, #0
	adds r0, #0x40
	str r0, [r4, #0x5c]
	cmp r0, #0
	ble _0804985C
	b _08049856
	.align 2, 0
_08049844: .4byte 0x0836298C
_08049848: .4byte 0x0000A734
_0804984C:
	adds r0, r2, #0
	subs r0, #0x40
	str r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804985C
_08049856:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804985C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08049894
_08049864:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804989C @ =0x083627F4
	bl SetDDP
	ldr r1, _080498A0 @ =0x0000A735
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804987C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049894
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08049894:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804989C: .4byte 0x083627F4
_080498A0: .4byte 0x0000A735

	thumb_func_start deathtanzPreAI
deathtanzPreAI: @ 0x080498A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080498B4
	cmp r0, #1
	beq _08049900
	b _08049918
_080498B4:
	adds r2, r4, #0
	adds r2, #0xbd
	strb r0, [r2]
	movs r3, #0
	ldr r0, _080498DC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	adds r5, r2, #0
	cmp r1, r0
	ble _080498CC
	movs r3, #1
_080498CC:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080498E0
	cmp r3, #0
	beq _08049910
	b _080498E4
	.align 2, 0
_080498DC: .4byte pZero2
_080498E0:
	cmp r3, #0
	bne _08049910
_080498E4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08049920 @ =0x0836283C
	bl SetDDP
	movs r0, #1
	strb r0, [r5]
	ldr r1, _08049924 @ =0x0000A707
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049900:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049918
_08049910:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08049918:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08049920: .4byte 0x0836283C
_08049924: .4byte 0x0000A707

	thumb_func_start deathtanzMode6
deathtanzMode6: @ 0x08049928
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _08049934
	b _08049B46
_08049934:
	lsls r0, r0, #2
	ldr r1, _08049940 @ =_08049944
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08049940: .4byte _08049944
_08049944: @ jump table
	.4byte _08049964 @ case 0
	.4byte _08049A00 @ case 1
	.4byte _08049A44 @ case 2
	.4byte _08049A5C @ case 3
	.4byte _08049A98 @ case 4
	.4byte _08049ABA @ case 5
	.4byte _08049AD2 @ case 6
	.4byte _08049B2E @ case 7
_08049964:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804999C @ =0x08362944
	bl SetDDP
	adds r3, r5, #0
	adds r3, #0xb4
	ldr r1, [r5, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _080499A0
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r0, [r3]
	movs r1, #0xa8
	lsls r1, r1, #7
	b _080499C0
	.align 2, 0
_0804999C: .4byte 0x08362944
_080499A0:
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r3]
	ldr r1, _08049A38 @ =0xFFFFAC00
_080499C0:
	adds r6, r0, r1
	str r6, [r5, #0x64]
	ldr r4, _08049A3C @ =0x00000666
	adds r0, r4, #0
	bl Sqrt
	adds r0, #0x10
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	adds r0, r4, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r0
	rsbs r1, r1, #0
	str r1, [r5, #0x60]
	ldr r1, _08049A40 @ =0x0000A70A
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049A00:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x19
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08049A18
	str r1, [r5, #0x60]
_08049A18:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bls _08049A36
	b _08049B46
_08049A36:
	b _08049ACA
	.align 2, 0
_08049A38: .4byte 0xFFFFAC00
_08049A3C: .4byte 0x00000666
_08049A40: .4byte 0x0000A70A
_08049A44:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049A90 @ =0x083629D4
	bl SetDDP
	ldr r1, _08049A94 @ =0x0000A720
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049A5C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x19
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08049A74
	str r1, [r5, #0x60]
_08049A74:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08049B46
	b _08049ACA
	.align 2, 0
_08049A90: .4byte 0x083629D4
_08049A94: .4byte 0x0000A720
_08049A98:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	bge _08049AAC
	ldr r1, _08049AA8 @ =0xFFFFAC00
	b _08049AB0
	.align 2, 0
_08049AA8: .4byte 0xFFFFAC00
_08049AAC:
	movs r1, #0xa8
	lsls r1, r1, #7
_08049AB0:
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049ABA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049B46
_08049ACA:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08049B46
_08049AD2:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049B14 @ =0x08362A1C
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
	beq _08049B18
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08049B1E
	.align 2, 0
_08049B14: .4byte 0x08362A1C
_08049B18:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08049B1E:
	strb r0, [r5, #0xa]
	ldr r1, _08049B4C @ =0x0000A721
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049B2E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049B46
	movs r1, #0
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08049B46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08049B4C: .4byte 0x0000A721

	thumb_func_start deathtanzMode7
deathtanzMode7: @ 0x08049B50
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _08049B8E
	cmp r4, #1
	bgt _08049B64
	cmp r4, #0
	beq _08049B6E
	b _08049C4A
_08049B64:
	cmp r4, #2
	beq _08049C18
	cmp r4, #3
	beq _08049C32
	b _08049C4A
_08049B6E:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049BD0 @ =0x08362A7C
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbe
	strb r4, [r0]
	ldr r1, _08049BD4 @ =0x0000A723
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049B8E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08049BFA
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08049BFA
	movs r0, #1
	strb r0, [r5, #0x12]
	adds r2, r5, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x5d
	bl PlaySound
	ldr r2, [r5, #0x54]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08049BD8
	movs r0, #0x90
	lsls r0, r0, #6
	b _08049BDA
	.align 2, 0
_08049BD0: .4byte 0x08362A7C
_08049BD4: .4byte 0x0000A723
_08049BD8:
	ldr r0, _08049C0C @ =0xFFFFDC00
_08049BDA:
	adds r1, r2, r0
	ldr r2, [r5, #0x58]
	ldr r0, _08049C10 @ =0xFFFFC900
	adds r2, r2, r0
	ldrb r3, [r5, #0xa]
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r5, #0
	bl FUN_080a08e0
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049C14 @ =0x08362ADC
	bl SetDDP
_08049BFA:
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049C4A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08049C4A
	.align 2, 0
_08049C0C: .4byte 0xFFFFDC00
_08049C10: .4byte 0xFFFFC900
_08049C14: .4byte 0x08362ADC
_08049C18:
	adds r2, r5, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08049C50 @ =0x0000A725
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049C32:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049C4A
	movs r1, #0
	movs r0, #8
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08049C4A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08049C50: .4byte 0x0000A725

	thumb_func_start deathtanzMode8
deathtanzMode8: @ 0x08049C54
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08049CB4
	cmp r5, #1
	bgt _08049C68
	cmp r5, #0
	beq _08049C72
	b _08049D2C
_08049C68:
	cmp r5, #2
	beq _08049CFC
	cmp r5, #3
	beq _08049D14
	b _08049D2C
_08049C72:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08049CEC @ =0x08362944
	bl SetDDP
	ldr r0, _08049CF0 @ =0xFFFFD000
	str r0, [r4, #0x5c]
	ldr r0, _08049CF4 @ =0x00000666
	bl Sqrt
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #0x5c]
	bl __divsi3
	adds r2, r0, #0
	str r2, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08049CA4
	rsbs r0, r2, #0
	str r0, [r4, #0x5c]
_08049CA4:
	str r5, [r4, #0x60]
	ldr r1, _08049CF8 @ =0x0000A70B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049CB4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x19
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08049CCC
	str r1, [r4, #0x60]
_08049CCC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r1, r0
	ble _08049CE4
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049CE4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08049D2C
	.align 2, 0
_08049CEC: .4byte 0x08362944
_08049CF0: .4byte 0xFFFFD000
_08049CF4: .4byte 0x00000666
_08049CF8: .4byte 0x0000A70B
_08049CFC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08049D34 @ =0x083628B4
	bl SetDDP
	ldr r1, _08049D38 @ =0x0000A709
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08049D14:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049D2C
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08049D2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08049D34: .4byte 0x083628B4
_08049D38: .4byte 0x0000A709

	thumb_func_start deathtanzMode9
deathtanzMode9: @ 0x08049D3C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _08049E00
	cmp r4, #1
	bgt _08049D50
	cmp r4, #0
	beq _08049D5C
	b _08049ED6
_08049D50:
	cmp r4, #2
	beq _08049E48
	cmp r4, #3
	bne _08049D5A
	b _08049EBE
_08049D5A:
	b _08049ED6
_08049D5C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049D9C @ =0x083628FC
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbf
	strb r4, [r0]
	adds r3, r5, #0
	adds r3, #0xb4
	ldr r1, [r5, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _08049DA0
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r3]
	movs r1, #0xa8
	lsls r1, r1, #7
	b _08049DC0
	.align 2, 0
_08049D9C: .4byte 0x083628FC
_08049DA0:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r3]
	ldr r1, _08049E3C @ =0xFFFFAC00
_08049DC0:
	adds r6, r0, r1
	str r6, [r5, #0x64]
	ldr r4, _08049E40 @ =0x00000851
	adds r0, r4, #0
	bl Sqrt
	adds r0, #0x10
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	adds r0, r4, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r0
	rsbs r1, r1, #0
	str r1, [r5, #0x60]
	ldr r1, _08049E44 @ =0x0000A70A
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049E00:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x19
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08049E18
	str r1, [r5, #0x60]
_08049E18:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08049ED6
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08049ED6
	.align 2, 0
_08049E3C: .4byte 0xFFFFAC00
_08049E40: .4byte 0x00000851
_08049E44: .4byte 0x0000A70A
_08049E48:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049E88 @ =0x08362B24
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
	beq _08049E8C
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08049E92
	.align 2, 0
_08049E88: .4byte 0x08362B24
_08049E8C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08049E92:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	bge _08049EA8
	ldr r1, _08049EA4 @ =0xFFFFAC00
	b _08049EAC
	.align 2, 0
_08049EA4: .4byte 0xFFFFAC00
_08049EA8:
	movs r1, #0xa8
	lsls r1, r1, #7
_08049EAC:
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _08049EDC @ =0x0000A70C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049EBE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08049ED6
	movs r1, #0
	movs r0, #0xa
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08049ED6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08049EDC: .4byte 0x0000A70C

	thumb_func_start deathtanzMode10
deathtanzMode10: @ 0x08049EE0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _08049EEC
	b _0804A0A2
_08049EEC:
	lsls r0, r0, #2
	ldr r1, _08049EF8 @ =_08049EFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08049EF8: .4byte _08049EFC
_08049EFC: @ jump table
	.4byte _08049F14 @ case 0
	.4byte _08049FA2 @ case 1
	.4byte _08049FDC @ case 2
	.4byte _08049FEE @ case 3
	.4byte _0804A05C @ case 4
	.4byte _0804A074 @ case 5
_08049F14:
	movs r0, #0x5d
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08049FD0 @ =0x08362944
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r3, [r0]
	ldr r1, _08049FD4 @ =0xFFFFEC00
	adds r0, r3, r1
	str r0, [r5, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08049F42
	movs r0, #0xa0
	lsls r0, r0, #5
	adds r2, r3, r0
_08049F42:
	ldr r1, [r5, #0x54]
	subs r1, r2, r1
	str r1, [r5, #0x5c]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, [r5, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r4, r4, #3
	str r4, [r5, #0x5c]
	lsls r0, r0, #3
	str r0, [r5, #0x60]
	adds r0, r6, #0
	asrs r0, r0, #0xb
	strb r0, [r5, #0x12]
	ldr r1, _08049FD8 @ =0x0000A70B
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049FA2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bhi _08049FC6
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049FC6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0804A0A2
	.align 2, 0
_08049FD0: .4byte 0x08362944
_08049FD4: .4byte 0xFFFFEC00
_08049FD8: .4byte 0x0000A70B
_08049FDC:
	movs r0, #0
	strb r0, [r5, #0x12]
	ldr r1, _0804A050 @ =0x0000A726
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08049FEE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804A014
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r1, r0
	ble _0804A014
	str r0, [r5, #0x58]
	movs r0, #1
	strb r0, [r5, #0x12]
_0804A014:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A02A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A02A:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _0804A054 @ =0x08362EB6
	adds r1, r5, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0804A058 @ =0x083627DC
	adds r1, r1, r2
	bl SetDDP
	b _0804A0A2
	.align 2, 0
_0804A050: .4byte 0x0000A726
_0804A054: .4byte 0x08362EB6
_0804A058: .4byte 0x083627DC
_0804A05C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804A094 @ =0x08362884
	bl SetDDP
	ldr r1, _0804A098 @ =0x0000A708
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A074:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A0A2
	adds r0, r5, #0
	adds r0, #0xbf
	ldrb r1, [r0]
	cmp r1, #0
	beq _0804A09C
	movs r1, #0
	movs r0, #5
	b _0804A09E
	.align 2, 0
_0804A094: .4byte 0x08362884
_0804A098: .4byte 0x0000A708
_0804A09C:
	movs r0, #0xb
_0804A09E:
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804A0A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start deathtanzMode11
deathtanzMode11: @ 0x0804A0A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0804A154
	cmp r0, #1
	bgt _0804A0BC
	cmp r0, #0
	beq _0804A0C8
	b _0804A22A
_0804A0BC:
	cmp r0, #2
	beq _0804A190
	cmp r0, #3
	bne _0804A0C6
	b _0804A20A
_0804A0C6:
	b _0804A22A
_0804A0C8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804A180 @ =0x083628FC
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r3, [r0]
	ldr r1, _0804A184 @ =0xFFFFAC00
	adds r0, r3, r1
	str r0, [r5, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804A0F0
	movs r0, #0xa8
	lsls r0, r0, #7
	adds r2, r3, r0
_0804A0F0:
	ldr r1, [r5, #0x54]
	subs r1, r2, r1
	str r1, [r5, #0x5c]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _0804A188 @ =0xFFFF9800
	adds r0, r0, r2
	ldr r2, [r5, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r4, r4, #3
	str r4, [r5, #0x5c]
	lsls r0, r0, #3
	str r0, [r5, #0x60]
	adds r0, r6, #0
	asrs r0, r0, #0xb
	strb r0, [r5, #0x12]
	ldr r1, _0804A18C @ =0x0000A70A
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A154:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804A176
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A176:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0804A22A
	.align 2, 0
_0804A180: .4byte 0x083628FC
_0804A184: .4byte 0xFFFFAC00
_0804A188: .4byte 0xFFFF9800
_0804A18C: .4byte 0x0000A70A
_0804A190:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804A1D0 @ =0x08362B24
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
	beq _0804A1D4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804A1DA
	.align 2, 0
_0804A1D0: .4byte 0x08362B24
_0804A1D4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804A1DA:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	bge _0804A1F4
	ldr r1, _0804A1F0 @ =0xFFFFAC00
	adds r0, r0, r1
	b _0804A1FA
	.align 2, 0
_0804A1F0: .4byte 0xFFFFAC00
_0804A1F4:
	movs r2, #0xa8
	lsls r2, r2, #7
	adds r0, r0, r2
_0804A1FA:
	str r0, [r5, #0x54]
	ldr r1, _0804A230 @ =0x0000A70C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A20A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A22A
	adds r2, r5, #0
	adds r2, #0xbf
	movs r0, #0
	movs r1, #1
	strb r1, [r2]
	movs r1, #0xa
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
_0804A22A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804A230: .4byte 0x0000A70C

	thumb_func_start deathtanzMode12
deathtanzMode12: @ 0x0804A234
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0804A29A
	cmp r5, #1
	bgt _0804A24A
	cmp r5, #0
	beq _0804A254
	b _0804A35E
_0804A24A:
	cmp r5, #2
	beq _0804A314
	cmp r5, #3
	beq _0804A344
	b _0804A35E
_0804A254:
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x54]
	ldr r1, [r1]
	subs r0, r0, r1
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #0xc8
	lsls r1, r1, #7
	cmp r0, r1
	bls _0804A27A
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0804A35E
_0804A27A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804A304 @ =0x08362D7C
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbe
	strb r5, [r0]
	ldr r1, _0804A308 @ =0x0000A70D
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A29A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0804A2F2
	ldrb r5, [r4, #0x12]
	cmp r5, #0
	bne _0804A2F2
	movs r6, #1
	strb r6, [r4, #0x12]
	movs r0, #0x5d
	bl PlaySound
	ldr r2, [r4, #0x54]
	ldr r0, _0804A30C @ =0xFFFFC900
	adds r1, r2, r0
	ldrb r3, [r4, #0xa]
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _0804A2D4
	movs r0, #0xdc
	lsls r0, r0, #6
	adds r1, r2, r0
_0804A2D4:
	ldr r2, [r4, #0x58]
	ldr r0, _0804A310 @ =0xFFFFCE00
	adds r2, r2, r0
	lsrs r3, r3, #4
	ands r3, r6
	str r5, [sp]
	adds r0, r4, #0
	bl deathtanz_080a0934
	adds r2, r4, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
_0804A2F2:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A35E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804A35E
	.align 2, 0
_0804A304: .4byte 0x08362D7C
_0804A308: .4byte 0x0000A70D
_0804A30C: .4byte 0xFFFFC900
_0804A310: .4byte 0xFFFFCE00
_0804A314:
	ldr r2, _0804A368 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804A36C @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _0804A370 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #0x3c
	strb r0, [r4, #0x12]
	ldr r1, _0804A374 @ =0x0000A70E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A344:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804A358
	movs r0, #0xd
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804A358:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0804A35E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804A368: .4byte RNG_0202f388
_0804A36C: .4byte 0x000343FD
_0804A370: .4byte 0x00269EC3
_0804A374: .4byte 0x0000A70E

	thumb_func_start deathtanzMode13
deathtanzMode13: @ 0x0804A378
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0804A3A8
	cmp r5, #1
	bgt _0804A38E
	cmp r5, #0
	beq _0804A398
	b _0804A446
_0804A38E:
	cmp r5, #2
	beq _0804A420
	cmp r5, #3
	beq _0804A42E
	b _0804A446
_0804A398:
	ldr r1, _0804A414 @ =0x0000A70F
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A3A8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _0804A400
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0804A400
	movs r5, #1
	strb r5, [r4, #0x12]
	movs r0, #0x5d
	bl PlaySound
	ldr r2, [r4, #0x54]
	ldr r0, _0804A418 @ =0xFFFFC900
	adds r1, r2, r0
	ldrb r3, [r4, #0xa]
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _0804A3E2
	movs r0, #0xdc
	lsls r0, r0, #6
	adds r1, r2, r0
_0804A3E2:
	ldr r2, [r4, #0x58]
	ldr r0, _0804A41C @ =0xFFFFCE00
	adds r2, r2, r0
	lsrs r3, r3, #4
	ands r3, r5
	str r5, [sp]
	adds r0, r4, #0
	bl deathtanz_080a0934
	adds r2, r4, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
_0804A400:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A446
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804A446
	.align 2, 0
_0804A414: .4byte 0x0000A70F
_0804A418: .4byte 0xFFFFC900
_0804A41C: .4byte 0xFFFFCE00
_0804A420:
	ldr r1, _0804A450 @ =0x0000A710
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A42E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804A446
	movs r1, #0
	movs r0, #0xe
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804A446:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804A450: .4byte 0x0000A710

	thumb_func_start deathtanzMode14
deathtanzMode14: @ 0x0804A454
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _0804A530
	lsls r0, r0, #2
	ldr r1, _0804A468 @ =_0804A46C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804A468: .4byte _0804A46C
_0804A46C: @ jump table
	.4byte _0804A484 @ case 0
	.4byte _0804A4A6 @ case 1
	.4byte _0804A4BC @ case 2
	.4byte _0804A4D4 @ case 3
	.4byte _0804A4F4 @ case 4
	.4byte _0804A518 @ case 5
_0804A484:
	adds r3, r4, #0
	adds r3, #0xc1
	ldrb r1, [r3]
	movs r0, #2
	movs r2, #0
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xbe
	strb r2, [r0]
	ldr r1, _0804A4B8 @ =0x0000A711
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A4A6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A530
	b _0804A4E4
	.align 2, 0
_0804A4B8: .4byte 0x0000A711
_0804A4BC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804A4EC @ =0x08362DAC
	bl SetDDP
	ldr r1, _0804A4F0 @ =0x0000A713
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A4D4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804A530
_0804A4E4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804A530
	.align 2, 0
_0804A4EC: .4byte 0x08362DAC
_0804A4F0: .4byte 0x0000A713
_0804A4F4:
	adds r2, r4, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804A538 @ =0x08362D7C
	bl SetDDP
	ldr r1, _0804A53C @ =0x0000A715
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A518:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A530
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804A530:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A538: .4byte 0x08362D7C
_0804A53C: .4byte 0x0000A715

	thumb_func_start deathtanzMode15
deathtanzMode15: @ 0x0804A540
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804A550
	cmp r5, #1
	beq _0804A574
	b _0804A58C
_0804A550:
	movs r0, #0x5c
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804A594 @ =0x083627F4
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xbe
	strb r5, [r0]
	ldr r1, _0804A598 @ =0x0000A716
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A574:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A58C
	movs r1, #0
	movs r0, #0x10
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804A58C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804A594: .4byte 0x083627F4
_0804A598: .4byte 0x0000A716

	thumb_func_start deathtanzMode16
deathtanzMode16: @ 0x0804A59C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0804A5A8
	b _0804A6AA
_0804A5A8:
	lsls r0, r0, #2
	ldr r1, _0804A5B4 @ =_0804A5B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804A5B4: .4byte _0804A5B8
_0804A5B8: @ jump table
	.4byte _0804A5D0 @ case 0
	.4byte _0804A61C @ case 1
	.4byte _0804A640 @ case 2
	.4byte _0804A664 @ case 3
	.4byte _0804A684 @ case 4
	.4byte _0804A692 @ case 5
_0804A5D0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804A630 @ =0x08362DF4
	bl SetDDP
	ldr r2, [r4, #0x54]
	ldr r0, _0804A634 @ =0xFFFFF800
	adds r1, r2, r0
	ldrb r3, [r4, #0xa]
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _0804A5F0
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r2, r0
_0804A5F0:
	ldr r2, [r4, #0x58]
	ldr r0, _0804A638 @ =0xFFFFDA00
	adds r2, r2, r0
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r4, #0
	bl deathtanz_080a09a0
	adds r2, r4, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
	ldr r1, _0804A63C @ =0x0000A718
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A61C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804A6AA
	b _0804A674
	.align 2, 0
_0804A630: .4byte 0x08362DF4
_0804A634: .4byte 0xFFFFF800
_0804A638: .4byte 0xFFFFDA00
_0804A63C: .4byte 0x0000A718
_0804A640:
	adds r2, r4, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804A67C @ =0x083627F4
	bl SetDDP
	ldr r1, _0804A680 @ =0x0000A71A
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A664:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A6AA
_0804A674:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804A6AA
	.align 2, 0
_0804A67C: .4byte 0x083627F4
_0804A680: .4byte 0x0000A71A
_0804A684:
	ldr r1, _0804A6B0 @ =0x0000A71B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804A692:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A6AA
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804A6AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A6B0: .4byte 0x0000A71B

	thumb_func_start deathtanzEX1
deathtanzEX1: @ 0x0804A6B4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _0804A6C2
	b _0804A8AE
_0804A6C2:
	lsls r0, r0, #2
	ldr r1, _0804A6CC @ =_0804A6D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804A6CC: .4byte _0804A6D0
_0804A6D0: @ jump table
	.4byte _0804A6F4 @ case 0
	.4byte _0804A77E @ case 1
	.4byte _0804A79C @ case 2
	.4byte _0804A7FE @ case 3
	.4byte _0804A814 @ case 4
	.4byte _0804A824 @ case 5
	.4byte _0804A84C @ case 6
	.4byte _0804A882 @ case 7
	.4byte _0804A894 @ case 8
_0804A6F4:
	adds r1, r5, #0
	adds r1, #0xc0
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	strb r2, [r5, #0x12]
	movs r1, #0
	ldr r0, _0804A744 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r2, r0
	bge _0804A710
	movs r1, #1
_0804A710:
	adds r4, r1, #0
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r3, [r0]
	subs r0, r2, r3
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0804A748
	movs r0, #0
	cmp r2, r3
	bge _0804A730
	movs r0, #1
_0804A730:
	cmp r4, r0
	beq _0804A748
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0804A8AE
	.align 2, 0
_0804A744: .4byte pZero2
_0804A748:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804A758
	cmp r4, #0
	beq _0804A762
	b _0804A75C
_0804A758:
	cmp r4, #0
	bne _0804A762
_0804A75C:
	movs r0, #2
	strb r0, [r5, #0xe]
	b _0804A8AE
_0804A762:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804A794 @ =0x0836283C
	bl SetDDP
	movs r0, #1
	strb r0, [r5, #0x12]
	ldr r1, _0804A798 @ =0x0000A707
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A77E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804A790
	b _0804A8AE
_0804A790:
	b _0804A86A
	.align 2, 0
_0804A794: .4byte 0x0836283C
_0804A798: .4byte 0x0000A707
_0804A79C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804A7E4 @ =0x08362E3C
	bl SetDDP
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804A7F0
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
	beq _0804A7E8
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804A7EE
	.align 2, 0
_0804A7E4: .4byte 0x08362E3C
_0804A7E8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804A7EE:
	strb r0, [r5, #0xa]
_0804A7F0:
	ldr r1, _0804A810 @ =0x0000A727
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A7FE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A8AE
	b _0804A86A
	.align 2, 0
_0804A810: .4byte 0x0000A727
_0804A814:
	movs r0, #0x5f
	bl PlaySound
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A824:
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	ldr r0, _0804A874 @ =0xFFFFB700
	adds r2, r2, r0
	ldrb r3, [r5, #0x12]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r4, #1
	ands r0, r4
	str r0, [sp]
	adds r0, r5, #0
	bl deathtanz_080a09f4
	ldr r1, _0804A878 @ =0x0000A729
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A84C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804A8AE
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0804A87C
_0804A86A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804A8AE
	.align 2, 0
_0804A874: .4byte 0xFFFFB700
_0804A878: .4byte 0x0000A729
_0804A87C:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0804A8AE
_0804A882:
	ldr r1, _0804A8B8 @ =0x0000A72A
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x5a
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A894:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804A8AE
	movs r0, #0x12
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804A8AE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804A8B8: .4byte 0x0000A72A

	thumb_func_start deathtanzEX2
deathtanzEX2: @ 0x0804A8BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _0804A8C8
	b _0804AA1A
_0804A8C8:
	lsls r0, r0, #2
	ldr r1, _0804A8D4 @ =_0804A8D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804A8D4: .4byte _0804A8D8
_0804A8D8: @ jump table
	.4byte _0804A8F8 @ case 0
	.4byte _0804A914 @ case 1
	.4byte _0804A948 @ case 2
	.4byte _0804A95A @ case 3
	.4byte _0804A994 @ case 4
	.4byte _0804A9A6 @ case 5
	.4byte _0804A9F4 @ case 6
	.4byte _0804AA02 @ case 7
_0804A8F8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804A940 @ =0x083627F4
	bl SetDDP
	ldr r1, _0804A944 @ =0x0000A72B
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A914:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0804A9DE
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804A9DE
	movs r0, #0x5d
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
	b _0804A9CC
	.align 2, 0
_0804A940: .4byte 0x083627F4
_0804A944: .4byte 0x0000A72B
_0804A948:
	ldr r1, _0804A990 @ =0x0000A72D
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A95A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0804A9DE
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804A9DE
	adds r0, r5, #0
	adds r0, #0xc0
	movs r4, #1
	strb r4, [r0]
	movs r0, #0x5d
	bl PlaySound
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldrb r3, [r5, #0xa]
	lsrs r3, r3, #4
	ands r3, r4
	movs r2, #1
	b _0804A9DA
	.align 2, 0
_0804A990: .4byte 0x0000A72D
_0804A994:
	ldr r1, _0804A9F0 @ =0x0000A72F
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804A9A6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0804A9DE
	ldrb r1, [r5, #0x12]
	cmp r1, #0
	bne _0804A9DE
	adds r0, r5, #0
	adds r0, #0xc0
	strb r1, [r0]
	movs r0, #0x5d
	bl PlaySound
_0804A9CC:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldrb r3, [r5, #0xa]
	lsrs r3, r3, #4
	movs r2, #1
	ands r3, r2
	movs r2, #0
_0804A9DA:
	bl FUN_080a0888
_0804A9DE:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804AA1A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804AA1A
	.align 2, 0
_0804A9F0: .4byte 0x0000A72F
_0804A9F4:
	ldr r1, _0804AA20 @ =0x0000A731
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804AA02:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804AA1A
	movs r1, #0
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804AA1A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804AA20: .4byte 0x0000A731

	thumb_func_start deathtanzKnockBackDamage
deathtanzKnockBackDamage: @ 0x0804AA24
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0804AA34
	cmp r0, #1
	beq _0804AABA
	b _0804AB44
_0804AA34:
	movs r0, #0x60
	bl PlaySound
	ldr r1, _0804AAD8 @ =0x0000A736
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r5, #0x54]
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r2, _0804AADC @ =0xFFFFD000
	adds r0, r0, r2
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r2, [r2]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r1, r0, #0
	str r1, [r5, #0x60]
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #7
	cmp r0, #0
	bge _0804AAA0
	adds r0, #0xff
_0804AAA0:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _0804AAB0
	adds r0, #0xff
_0804AAB0:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804AABA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r1, r0, r1
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r2, r0, r3
	cmp r1, r2
	ble _0804AAE0
	str r2, [r5, #0x54]
	b _0804AAEA
	.align 2, 0
_0804AAD8: .4byte 0x0000A736
_0804AADC: .4byte 0xFFFFD000
_0804AAE0:
	ldr r2, _0804AB24 @ =0xFFFFB000
	adds r0, r0, r2
	cmp r1, r0
	bge _0804AAEA
	str r0, [r5, #0x54]
_0804AAEA:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804AAFA
	str r1, [r5, #0x60]
_0804AAFA:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	cmp r1, #0
	ble _0804AB28
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r6, #0
	bge _0804AB3E
	ldr r0, [r5, #0x58]
	adds r0, r0, r6
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _0804AB3E
	.align 2, 0
_0804AB24: .4byte 0xFFFFB000
_0804AB28:
	ldr r0, [r5, #0x54]
	ldr r3, _0804AB4C @ =0xFFFFE000
	adds r1, r2, r3
	bl PushoutToDown1
	adds r6, r0, #0
	cmp r6, #0
	bge _0804AB3E
	ldr r0, [r5, #0x58]
	adds r0, r0, r6
	str r0, [r5, #0x58]
_0804AB3E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0804AB44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AB4C: .4byte 0xFFFFE000

	thumb_func_start deathtanzMode19
deathtanzMode19: @ 0x0804AB50
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0804AB62
	cmp r1, #1
	beq _0804ABD0
	b _0804AC38
_0804AB62:
	ldrb r0, [r4, #0xb]
	movs r7, #0x10
	movs r6, #0
	orrs r0, r7
	strb r0, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
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
	beq _0804ABBA
	ldrb r0, [r4, #0xa]
	orrs r0, r7
	b _0804ABC0
_0804ABBA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804ABC0:
	strb r0, [r4, #0xa]
	ldr r1, _0804ABE4 @ =0x0000A739
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804ABD0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0804ABE8
	movs r0, #0xf6
	b _0804ABEA
	.align 2, 0
_0804ABE4: .4byte 0x0000A739
_0804ABE8:
	movs r0, #0xfa
_0804ABEA:
	muls r0, r1, r0
	cmp r0, #0
	bge _0804ABF2
	adds r0, #0xff
_0804ABF2:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_0801779c
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bne _0804AC38
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
	ldr r1, _0804AC40 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0804AC38:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804AC40: .4byte gBossFnTable

	thumb_func_start FUN_0804ac44
FUN_0804ac44: @ 0x0804AC44
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0804AC52
	b _0804ADA0
_0804AC52:
	lsls r0, r0, #2
	ldr r1, _0804AC5C @ =_0804AC60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804AC5C: .4byte _0804AC60
_0804AC60: @ jump table
	.4byte _0804AC74 @ case 0
	.4byte _0804AD46 @ case 1
	.4byte _0804AD78 @ case 2
	.4byte _0804AD88 @ case 3
	.4byte _0804ADA0 @ case 4
_0804AC74:
	movs r5, #0
	adds r2, r4, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _0804ACBC
	movs r5, #1
	ldr r3, [r4, #0x54]
	ldr r1, _0804AD60 @ =0xFFFFD600
	adds r0, r3, r1
	str r0, [sp]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804ACA2
	movs r0, #0xb0
	lsls r0, r0, #6
	adds r2, r3, r0
_0804ACA2:
	str r2, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0804AD64 @ =0xFFFFE700
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_080bdb44
_0804ACBC:
	ldrb r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804ACE4
	movs r5, #1
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0804AD68 @ =0xFFFFB400
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_080bdb44
_0804ACE4:
	cmp r5, #0
	beq _0804ACEE
	movs r0, #0x2a
	bl PlaySound
_0804ACEE:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r3, _0804AD6C @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0804AD34
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804AD34
	ldr r0, _0804AD70 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804AD34:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldr r1, _0804AD74 @ =0x0000A737
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804AD46:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804ADA0
	b _0804AD9A
	.align 2, 0
_0804AD60: .4byte 0xFFFFD600
_0804AD64: .4byte 0xFFFFE700
_0804AD68: .4byte 0xFFFFB400
_0804AD6C: .4byte gStageRun
_0804AD70: .4byte 0x0000FFFE
_0804AD74: .4byte 0x0000A737
_0804AD78:
	ldr r1, _0804ADA8 @ =0x08362EC4
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804AD88:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0804ADA0
	ldr r2, _0804ADAC @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_0804AD9A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804ADA0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804ADA8: .4byte 0x08362EC4
_0804ADAC: .4byte gStageRun

	thumb_func_start deathtanz_0804adb0
deathtanz_0804adb0: @ 0x0804ADB0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0804ADBE
	b _0804AFD2
_0804ADBE:
	lsls r0, r0, #2
	ldr r1, _0804ADC8 @ =_0804ADCC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804ADC8: .4byte _0804ADCC
_0804ADCC: @ jump table
	.4byte _0804ADE0 @ case 0
	.4byte _0804AF32 @ case 1
	.4byte _0804AFAA @ case 2
	.4byte _0804AFBA @ case 3
	.4byte _0804AFD2 @ case 4
_0804ADE0:
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0xc1
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _0804AE28
	movs r6, #1
	ldr r3, [r4, #0x54]
	ldr r1, _0804AF50 @ =0xFFFFD600
	adds r0, r3, r1
	str r0, [sp]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804AE0E
	movs r0, #0xb0
	lsls r0, r0, #6
	adds r2, r3, r0
_0804AE0E:
	str r2, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0804AF54 @ =0xFFFFE700
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_080bdb44
_0804AE28:
	ldrb r1, [r5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804AE50
	movs r6, #1
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0804AF58 @ =0xFFFFB400
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_080bdb44
_0804AE50:
	cmp r6, #0
	beq _0804AE5A
	movs r0, #0x2a
	bl PlaySound
_0804AE5A:
	movs r0, #0x2f
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xc2
	ldrb r6, [r0]
	ldr r0, _0804AF5C @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0804AEC2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0804AF60 @ =gBossFnTable
	movs r0, #7
	strb r0, [r3, #9]
	ldr r0, [r1, #0x1c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r3, #0x5c]
	str r4, [r3, #0x28]
	movs r1, #1
	strb r1, [r3, #0x10]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	ands r0, r1
	eors r0, r6
	strb r0, [r3, #0x13]
_0804AEC2:
	ldr r1, _0804AF64 @ =0x0000A738
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r3, _0804AF68 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0804AF04
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804AF04
	ldr r0, _0804AF6C @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804AF04:
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0804AF70 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r0, #0x32
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804AF32:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc2
	ldrb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804AF74
	cmp r3, #1
	bne _0804AF78
	b _0804AF7C
	.align 2, 0
_0804AF50: .4byte 0xFFFFD600
_0804AF54: .4byte 0xFFFFE700
_0804AF58: .4byte 0xFFFFB400
_0804AF5C: .4byte gBossHeaderPtr
_0804AF60: .4byte gBossFnTable
_0804AF64: .4byte 0x0000A738
_0804AF68: .4byte gStageRun
_0804AF6C: .4byte 0x0000FFFE
_0804AF70: .4byte 0xFFFFE000
_0804AF74:
	cmp r3, #0
	beq _0804AF7C
_0804AF78:
	movs r0, #0xfa
	b _0804AF7E
_0804AF7C:
	movs r0, #0xf6
_0804AF7E:
	muls r0, r2, r0
	cmp r0, #0
	bge _0804AF86
	adds r0, #0xff
_0804AF86:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804AFA2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804AFA2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0804AFD2
_0804AFAA:
	ldr r1, _0804AFDC @ =0x08362ECC
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804AFBA:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0804AFD2
	ldr r2, _0804AFE0 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804AFD2:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AFDC: .4byte 0x08362ECC
_0804AFE0: .4byte gStageRun
