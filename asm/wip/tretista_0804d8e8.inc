	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	movs r0, #0x49
	bl StepPaletteAnimation
	movs r0, #0x4a
	bl StepPaletteAnimation
	movs r0, #0x4b
	bl StepPaletteAnimation
	movs r0, #0x4c
	bl StepPaletteAnimation
	ldrb r0, [r7, #0xe]
	cmp r0, #0x19
	bls _0804D912
	b _0804DC7C
_0804D912:
	lsls r0, r0, #2
	ldr r1, _0804D91C @ =_0804D920
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804D91C: .4byte _0804D920
_0804D920: @ jump table
	.4byte _0804D988 @ case 0
	.4byte _0804DADE @ case 1
	.4byte _0804DB14 @ case 2
	.4byte _0804DB86 @ case 3
	.4byte _0804DBB8 @ case 4
	.4byte _0804DC7C @ case 5
	.4byte _0804DC7C @ case 6
	.4byte _0804DC7C @ case 7
	.4byte _0804DC7C @ case 8
	.4byte _0804DC7C @ case 9
	.4byte _0804DADE @ case 10
	.4byte _0804DBCE @ case 11
	.4byte _0804DC7C @ case 12
	.4byte _0804DC7C @ case 13
	.4byte _0804DC7C @ case 14
	.4byte _0804DC7C @ case 15
	.4byte _0804DC7C @ case 16
	.4byte _0804DC7C @ case 17
	.4byte _0804DC7C @ case 18
	.4byte _0804DC7C @ case 19
	.4byte _0804DBE0 @ case 20
	.4byte _0804DBEA @ case 21
	.4byte _0804DBF8 @ case 22
	.4byte _0804DC20 @ case 23
	.4byte _0804DC38 @ case 24
	.4byte _0804DC64 @ case 25
_0804D988:
	ldr r1, _0804DAE8 @ =0x0000AB25
	adds r0, r7, #0
	bl SetMotion
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0804D9AC
	adds r0, r7, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0804D9BE
_0804D9AC:
	ldr r0, _0804DAEC @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0804D9BE
	ldrb r0, [r7, #0xf]
	cmp r0, #1
	beq _0804D9C0
_0804D9BE:
	movs r0, #0xa
_0804D9C0:
	strb r0, [r7, #0xe]
	movs r0, #0
	mov r8, r0
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	mov r1, r8
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r0, [r7, #0xa]
	movs r6, #0xfb
	ands r6, r0
	strb r6, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	cmp r0, #0
	bne _0804DA58
	ldr r3, [r7, #0x54]
	movs r0, #0x90
	lsls r0, r0, #5
	adds r3, r3, r0
	str r3, [sp]
	ldr r2, [r7, #0x58]
	ldr r1, _0804DAF0 @ =0xFFFFAC00
	adds r2, r2, r1
	str r2, [sp, #4]
	ldr r5, _0804DAF4 @ =RNG_0202f388
	ldr r1, [r5]
	ldr r0, _0804DAF8 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0804DAFC @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r5]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	str r3, [sp, #8]
	add r5, sp, #8
	str r2, [r5, #4]
	lsrs r1, r6, #4
	movs r6, #1
	ands r1, r6
	ldr r2, _0804DB00 @ =0x0000AB28
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0804DB04 @ =0x0000AB29
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0804DB08 @ =0x0000AB2A
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r6
	ldr r2, _0804DB0C @ =0x0000AB2B
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080becf8
_0804DA58:
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0
	bne _0804DAD4
	ldr r3, [r7, #0x54]
	ldr r1, _0804DB10 @ =0xFFFFF000
	adds r3, r3, r1
	str r3, [sp]
	ldr r2, [r7, #0x58]
	ldr r0, _0804DAF0 @ =0xFFFFAC00
	adds r2, r2, r0
	str r2, [sp, #4]
	ldr r5, _0804DAF4 @ =RNG_0202f388
	ldr r1, [r5]
	ldr r0, _0804DAF8 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0804DAFC @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r5]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	str r3, [sp, #0x10]
	add r6, sp, #0x10
	str r2, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _0804DB00 @ =0x0000AB28
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _0804DB04 @ =0x0000AB29
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _0804DB08 @ =0x0000AB2A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _0804DB0C @ =0x0000AB2B
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080becf8
_0804DAD4:
	adds r0, r7, #0
	adds r0, #0x5c
	mov r1, r8
	str r1, [r0, #4]
	str r1, [r7, #0x5c]
_0804DADE:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _0804DC2C
	.align 2, 0
_0804DAE8: .4byte 0x0000AB25
_0804DAEC: .4byte gStageRun
_0804DAF0: .4byte 0xFFFFAC00
_0804DAF4: .4byte RNG_0202f388
_0804DAF8: .4byte 0x000343FD
_0804DAFC: .4byte 0x00269EC3
_0804DB00: .4byte 0x0000AB28
_0804DB04: .4byte 0x0000AB29
_0804DB08: .4byte 0x0000AB2A
_0804DB0C: .4byte 0x0000AB2B
_0804DB10: .4byte 0xFFFFF000
_0804DB14:
	movs r0, #0
	str r0, [r7, #0x60]
	ldr r2, [r7, #0x54]
	str r2, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804DB2C
	str r2, [sp]
_0804DB2C:
	ldr r1, _0804DB4C @ =0xFFFFD000
	adds r0, r3, r1
	str r0, [sp, #4]
	ldrb r0, [r7, #0x11]
	cmp r0, #0xff
	beq _0804DB5A
	cmp r0, #0xfe
	bne _0804DB50
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _0804DB7E
	.align 2, 0
_0804DB4C: .4byte 0xFFFFD000
_0804DB50:
	ldr r0, _0804DB6C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r2
	ble _0804DB70
_0804DB5A:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _0804DB7E
	.align 2, 0
_0804DB6C: .4byte pZero2
_0804DB70:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_0804DB7E:
	movs r0, #0x2f
	bl PlaySound
	b _0804DC2C
_0804DB86:
	adds r1, r7, #0
	adds r1, #0x54
	ldr r2, _0804DBB0 @ =0x0000AB27
	ldrb r3, [r7, #0xa]
	lsrs r3, r3, #4
	movs r0, #1
	ands r3, r0
	adds r0, r7, #0
	bl FUN_0809c3b4
	ldr r1, _0804DBB4 @ =0x0000AB26
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0x44
	strb r0, [r7, #0x12]
	b _0804DC2C
	.align 2, 0
_0804DBB0: .4byte 0x0000AB27
_0804DBB4: .4byte 0x0000AB26
_0804DBB8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0804DBCE
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804DC7C
_0804DBCE:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804DC7C
	movs r0, #0x14
	strb r0, [r7, #0xe]
	b _0804DC7C
_0804DBE0:
	movs r0, #0x50
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804DBEA:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804DC7C
	b _0804DC2C
_0804DBF8:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804DC0C
	ldr r1, _0804DC08 @ =sTretista_ExplosionOffsets+(8*0)
	b _0804DC0E
	.align 2, 0
_0804DC08: .4byte sTretista_ExplosionOffsets+(8*0)
_0804DC0C:
	ldr r1, _0804DC34 @ =sTretista_ExplosionOffsets+(8*1)
_0804DC0E:
	adds r0, r7, #0
	bl CreateBossExplosion
	adds r1, r7, #0
	adds r1, #0xc0
	str r0, [r1]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804DC20:
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0804DC7C
_0804DC2C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0804DC7C
	.align 2, 0
_0804DC34: .4byte sTretista_ExplosionOffsets+(8*1)
_0804DC38:
	movs r0, #0x48
	strb r0, [r7, #0x12]
	movs r0, #0x49
	bl RemovePaletteAnimation
	movs r0, #0x4a
	bl RemovePaletteAnimation
	movs r0, #0x4b
	bl RemovePaletteAnimation
	movs r0, #0x4c
	bl RemovePaletteAnimation
	ldr r2, _0804DC88 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804DC64:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0804DC74
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804DC7C
_0804DC74:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
_0804DC7C:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804DC88: .4byte gStageRun
