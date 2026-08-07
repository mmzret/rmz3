	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
_0804D2E0: .4byte u8_ARRAY_08363329
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
	ldr r2, _0804D3D4 @ =u8_ARRAY_08363324
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
_0804D3D4: .4byte u8_ARRAY_08363324
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
