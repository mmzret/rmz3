	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804d0a4
FUN_0804d0a4: @ 0x0804D0A4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804D0D2
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _0804D0D2
	ldr r2, _0804D0F0 @ =sBeeServerElfxOffset
	movs r0, #0x12
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r4, #0
	adds r1, #0xb4
	str r0, [r1]
_0804D0D2:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0804D0F4 @ =0x00020008
	ands r0, r1
	cmp r0, r1
	bne _0804D0EA
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0xfc
	lsls r0, r0, #8
	strh r0, [r1]
_0804D0EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D0F0: .4byte sBeeServerElfxOffset
_0804D0F4: .4byte 0x00020008

	thumb_func_start FUN_0804d0f8
FUN_0804d0f8: @ 0x0804D0F8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0804D108
	cmp r0, #1
	beq _0804D126
	b _0804D18E
_0804D108:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804D194 @ =0x08363270
	bl SetDDP
	movs r0, #0xff
	strb r0, [r4, #0x12]
	movs r1, #0x8c
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804D126:
	adds r2, r4, #0
	adds r2, #0xba
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _0804D174
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0804D198 @ =0x00020008
	ands r0, r1
	cmp r0, r1
	bne _0804D174
	movs r0, #0x78
	strh r0, [r2]
	ldr r3, _0804D19C @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _0804D1A0 @ =0x000343FD
	adds r2, r1, #0
	muls r2, r0, r2
	ldr r0, _0804D1A4 @ =0x00269EC3
	adds r2, r2, r0
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r3]
	lsrs r2, r2, #0x11
	movs r0, #3
	ands r2, r0
	ldr r0, [r4, #0x54]
	lsrs r3, r2, #1
	lsls r3, r3, #0xe
	ldr r1, _0804D1A8 @ =0xFFFFE000
	adds r3, r3, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r3
	movs r3, #1
	ands r2, r3
	bl FUN_0807d6c0
_0804D174:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804D188
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804D188:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0804D18E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D194: .4byte sCollisions+(24*1)
_0804D198: .4byte 0x00020008
_0804D19C: .4byte RNG_0202f388
_0804D1A0: .4byte 0x000343FD
_0804D1A4: .4byte 0x00269EC3
_0804D1A8: .4byte 0xFFFFE000

	thumb_func_start FUN_0804d1ac
FUN_0804d1ac: @ 0x0804D1AC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0804D1F4
	cmp r0, #1
	bgt _0804D1C0
	cmp r0, #0
	beq _0804D1CA
	b _0804D234
_0804D1C0:
	cmp r0, #2
	beq _0804D20E
	cmp r0, #3
	beq _0804D21E
	b _0804D234
_0804D1CA:
	movs r1, #0x8c
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x45
	bl StartPaletteAnimation
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804D1F4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804D234
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804D234
_0804D20E:
	movs r1, #0x8c
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804D21E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _0804D23C @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0804D234
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804D234:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D23C: .4byte gStageRun

	thumb_func_start FUN_0804d240
FUN_0804d240: @ 0x0804D240
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	bne _0804D252
	b _0804D384
_0804D252:
	cmp r0, #1
	bgt _0804D25C
	cmp r0, #0
	beq _0804D26A
	b _0804D408
_0804D25C:
	cmp r0, #2
	bne _0804D262
	b _0804D3DC
_0804D262:
	cmp r0, #3
	bne _0804D268
	b _0804D3EE
_0804D268:
	b _0804D408
_0804D26A:
	ldr r0, _0804D288 @ =0x0000010F
	bl PlaySound
	ldr r0, _0804D28C @ =gCurStory
	ldrb r1, [r0, #9]
	lsrs r7, r1, #5
	movs r0, #1
	ands r7, r0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804D290
	adds r0, r7, #1
	b _0804D294
	.align 2, 0
_0804D288: .4byte 0x0000010F
_0804D28C: .4byte gCurStory
_0804D290:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
_0804D294:
	adds r7, r0, #0
	ldr r2, _0804D2A8 @ =gCurStory
	ldrb r1, [r2, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804D2AC
	adds r0, r7, #1
	lsls r0, r0, #0x18
	b _0804D2AE
	.align 2, 0
_0804D2A8: .4byte gCurStory
_0804D2AC:
	lsls r0, r7, #0x18
_0804D2AE:
	lsrs r3, r0, #0x18
	ldrb r1, [r2, #0xa]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	adds r0, r3, r0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _0804D2E0 @ =0x08363329
	adds r1, r7, r0
	mov ip, r1
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #4
	bne _0804D2E4
	mov r3, sp
	mov r2, sp
	mov r1, sp
	mov r0, sp
	strb r4, [r0, #3]
	strb r4, [r1, #2]
	strb r4, [r2, #1]
	strb r4, [r3]
	b _0804D34A
	.align 2, 0
_0804D2E0: .4byte u8_ARRAY_ARRAY_08363324+5
_0804D2E4:
	movs r4, #0
	mov r3, sp
	mov r2, sp
	mov r1, sp
	mov r0, sp
	strb r4, [r0, #3]
	strb r4, [r1, #2]
	strb r4, [r2, #1]
	strb r4, [r3]
	movs r5, #0
	mov r2, ip
	ldrb r2, [r2]
	cmp r5, r2
	bge _0804D34A
	ldr r2, _0804D3C0 @ =RNG_0202f388
_0804D302:
	adds r4, #1
	ldr r1, [r2]
	ldr r0, _0804D3C4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804D3C8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	str r2, [sp, #4]
	bl __umodsi3
	adds r4, r4, r0
	adds r0, r4, #0
	ldr r2, [sp, #4]
	cmp r4, #0
	bge _0804D32A
	adds r0, r4, #3
_0804D32A:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r4, r4, r0
	mov r0, sp
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804D302
	movs r0, #1
	strb r0, [r1]
	adds r5, #1
	mov r1, r8
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _0804D302
_0804D34A:
	movs r5, #0
	movs r4, #1
_0804D34E:
	mov r2, sp
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804D370
	ldr r0, [r6, #0x54]
	asrs r2, r5, #1
	ands r2, r4
	lsls r2, r2, #0xe
	ldr r1, _0804D3CC @ =0xFFFFE000
	adds r2, r2, r1
	ldr r1, [r6, #0x58]
	adds r1, r1, r2
	adds r2, r5, #0
	ands r2, r4
	bl FUN_0807d6c0
_0804D370:
	adds r5, #1
	cmp r5, #3
	ble _0804D34E
	ldr r1, _0804D3D0 @ =0x00004601
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804D384:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r2, _0804D3D4 @ =u8_ARRAY_ARRAY_08363324
	adds r1, r6, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0804D3D8 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804D408
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0804D408
	.align 2, 0
_0804D3C0: .4byte RNG_0202f388
_0804D3C4: .4byte 0x000343FD
_0804D3C8: .4byte 0x00269EC3
_0804D3CC: .4byte 0xFFFFE000
_0804D3D0: .4byte 0x00004601
_0804D3D4: .4byte u8_ARRAY_ARRAY_08363324
_0804D3D8: .4byte sCollisions
_0804D3DC:
	ldr r1, _0804D414 @ =0x00004602
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x80
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804D3EE:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804D408
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_0804D408:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D414: .4byte 0x00004602

	thumb_func_start FUN_0804d418
FUN_0804d418: @ 0x0804D418
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0804D428
	cmp r0, #1
	beq _0804D444
	b _0804D47C
_0804D428:
	ldr r0, _0804D484 @ =0x0000010F
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080a2f34
	ldr r1, _0804D488 @ =0x00004603
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804D444:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0804D48C @ =0x0836332E
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0804D490 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804D47C
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0804D47C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D484: .4byte 0x0000010F
_0804D488: .4byte 0x00004603
_0804D48C: .4byte u8_ARRAY_ARRAY_08363324+10
_0804D490: .4byte sCollisions

	thumb_func_start FUN_0804d494
FUN_0804d494: @ 0x0804D494
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _0804D4FE
	cmp r0, #1
	ble _0804D4A6
	b _0804D5D0
_0804D4A6:
	cmp r0, #0
	beq _0804D4AC
	b _0804D5D0
_0804D4AC:
	movs r0, #0x45
	bl RemovePaletteAnimation
	ldr r3, _0804D58C @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _0804D4D4
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0804D4D4
	ldr r0, _0804D590 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804D4D4:
	ldrb r2, [r7, #0xa]
	movs r0, #1
	movs r1, #0
	orrs r0, r2
	strb r0, [r7, #0xa]
	movs r0, #0xff
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804D4FE:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x12]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0804D55C
	ldr r1, [r7, #0x54]
	ldr r0, _0804D594 @ =0xFFFFE000
	adds r1, r1, r0
	ldr r6, _0804D598 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _0804D59C @ =0x000343FD
	muls r0, r5, r0
	ldr r2, _0804D5A0 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsls r0, r0, #1
	lsrs r0, r0, #0x12
	adds r0, r0, r1
	str r0, [sp]
	ldr r4, [r7, #0x58]
	ldr r0, _0804D5A4 @ =0xFFFFD200
	adds r4, r4, r0
	str r4, [sp, #4]
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xb8
	lsls r1, r1, #7
	bl __umodsi3
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
_0804D55C:
	ldrb r0, [r7, #0x12]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804D570
	movs r0, #0x2a
	bl PlaySound
_0804D570:
	movs r0, #0x12
	ldrsb r0, [r7, r0]
	ldrb r2, [r7, #0x12]
	cmp r0, #0
	blt _0804D5B0
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0804D5A8
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0804D5AE
	.align 2, 0
_0804D58C: .4byte gStageRun
_0804D590: .4byte 0x0000FFFE
_0804D594: .4byte 0xFFFFE000
_0804D598: .4byte RNG_0202f388
_0804D59C: .4byte 0x000343FD
_0804D5A0: .4byte 0x00269EC3
_0804D5A4: .4byte 0xFFFFD200
_0804D5A8:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804D5AE:
	strb r0, [r7, #0xa]
_0804D5B0:
	lsls r0, r2, #0x18
	cmp r0, #0
	bne _0804D5D0
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0xc
	bl TryDropItem
	ldr r2, _0804D5D8 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804D5D0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D5D8: .4byte gStageRun

