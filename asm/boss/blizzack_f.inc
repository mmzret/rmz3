	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blizzackJump
blizzackJump: @ 0x0805A230
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A26A
	ldr r1, _0805A2B4 @ =0x0000B403
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A2B8 @ =0x00006403
	strh r1, [r0]
	strb r2, [r4, #0xe]
	ldr r0, _0805A2BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x34
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0805A2C0 @ =0xFFFFF640
	str r0, [r4, #0x60]
_0805A26A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x60
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805A28E
	str r0, [r4, #0x60]
_0805A28E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _0805A2AC
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #6
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A2AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805A2B4: .4byte 0x0000B403
_0805A2B8: .4byte 0x00006403
_0805A2BC: .4byte pZero2
_0805A2C0: .4byte 0xFFFFF640

	thumb_func_start blizzackStamp
blizzackStamp: @ 0x0805A2C4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0805A2FC
	ldr r1, _0805A35C @ =0x0000B404
	adds r0, r5, #0
	bl SetMotion
	ldr r1, [r5, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r5, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A360 @ =0x00006404
	strh r1, [r0]
	strb r2, [r5, #0xe]
	strb r2, [r5, #0x12]
	movs r0, #0x91
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
_0805A2FC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	strb r0, [r5, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0805A342
	adds r4, r5, #0
	adds r4, #0x54
	movs r3, #0x8c
	lsls r3, r3, #1
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #2
	rsbs r0, r0, #0
	subs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl CreateVFX57
	ldr r3, _0805A364 @ =0xFFFFFEE8
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #2
	rsbs r0, r0, #0
	subs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl CreateVFX57
_0805A342:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805A352
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
_0805A352:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805A35C: .4byte 0x0000B404
_0805A360: .4byte 0x00006404
_0805A364: .4byte 0xFFFFFEE8

	thumb_func_start blizzackMode7
blizzackMode7: @ 0x0805A368
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A3F2
	ldr r1, _0805A3D4 @ =0x0000B407
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x2c]
	movs r5, #1
	strb r5, [r0, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A3D8 @ =0x00006407
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r3, #0
	ldr r0, _0805A3DC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805A39C
	movs r3, #1
_0805A39C:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805A3AE
	movs r3, #1
_0805A3AE:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	adds r1, r5, #0
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
	beq _0805A3E0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805A3E6
	.align 2, 0
_0805A3D4: .4byte 0x0000B407
_0805A3D8: .4byte 0x00006407
_0805A3DC: .4byte pZero2
_0805A3E0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805A3E6:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805A410 @ =0x08364BE0
	bl SetDDP
_0805A3F2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805A40A
	movs r0, #8
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A40A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805A410: .4byte sCollisions+(24*2)

