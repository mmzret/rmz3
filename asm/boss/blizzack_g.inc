	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blizzackMode9
blizzackMode9: @ 0x0805A450
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A482
	ldr r1, _0805A4A4 @ =0x0000B408
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A4A8 @ =0x00006408
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805A4AC @ =sCollisions
	bl SetDDP
_0805A482:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805A49E
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A49E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805A4A4: .4byte 0x0000B408
_0805A4A8: .4byte 0x00006408
_0805A4AC: .4byte sCollisions

	thumb_func_start blizzackStartBlizzard
blizzackStartBlizzard: @ 0x0805A4B0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A4DE
	ldr r1, _0805A4FC @ =0x0000B409
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A500 @ =0x00006409
	strh r1, [r0]
	strb r2, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805A504 @ =0x08364BE0
	bl SetDDP
_0805A4DE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805A4F6
	movs r0, #0xb
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A4F6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805A4FC: .4byte 0x0000B409
_0805A500: .4byte 0x00006409
_0805A504: .4byte sCollisions+(24*2)

	thumb_func_start blizzackBlizzard
blizzackBlizzard: @ 0x0805A508
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A53C
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r0, #0xb4
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_080aac28
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	movs r1, #1
	bl CreateEnemy42
	movs r0, #0x44
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0xc8
	strh r0, [r1]
_0805A53C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805A558
	movs r0, #0xc
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A558:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start blizzackEndBlizzard
blizzackEndBlizzard: @ 0x0805A560
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A59E
	ldr r1, _0805A5C0 @ =0x0000B408
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A5C4 @ =0x00006408
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl StopSound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805A5C8 @ =sCollisions
	bl SetDDP
_0805A59E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805A5BA
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A5BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805A5C0: .4byte 0x0000B408
_0805A5C4: .4byte 0x00006408
_0805A5C8: .4byte sCollisions

	thumb_func_start blizzackBombJump
blizzackBombJump: @ 0x0805A5CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0805A5DE
	b _0805A6FC
_0805A5DE:
	ldr r1, _0805A628 @ =0x0000B403
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x2c]
	movs r7, #1
	strb r7, [r0, #0xe]
	ldr r0, [r5, #0x2c]
	adds r0, #0xbc
	movs r1, #0
	mov r8, r1
	ldr r1, _0805A62C @ =0x00006403
	strh r1, [r0]
	mov r0, r8
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r6, [r5, #0x54]
	subs r2, r0, r6
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r2, r0
	ble _0805A634
	ldr r4, _0805A630 @ =pZero2
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	subs r0, r0, r6
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #2
	strb r0, [r5, #0x13]
	mov sb, r4
	b _0805A6A8
	.align 2, 0
_0805A628: .4byte 0x0000B403
_0805A62C: .4byte 0x00006403
_0805A630: .4byte pZero2
_0805A634:
	ldr r0, _0805A658 @ =pZero2
	ldr r1, [r0]
	ldr r4, [r1, #0x54]
	subs r3, r4, r6
	movs r1, #0xa0
	lsls r1, r1, #7
	mov sb, r0
	cmp r3, r1
	ble _0805A65C
	adds r0, r3, #0
	movs r1, #0x34
	bl __divsi3
	str r0, [r5, #0x5c]
	mov r1, r8
	strb r1, [r5, #0x13]
	b _0805A6A8
	.align 2, 0
_0805A658: .4byte pZero2
_0805A65C:
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _0805A69C
	ldr r2, _0805A690 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805A694 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805A698 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r7
	cmp r0, #0
	beq _0805A69C
	adds r0, r3, #0
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #2
	strb r0, [r5, #0x13]
	b _0805A6A8
	.align 2, 0
_0805A690: .4byte RNG_0202f388
_0805A694: .4byte 0x000343FD
_0805A698: .4byte 0x00269EC3
_0805A69C:
	subs r0, r6, r4
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x5c]
	strb r7, [r5, #0x13]
_0805A6A8:
	ldr r0, _0805A6F0 @ =0xFFFFF640
	str r0, [r5, #0x60]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	movs r2, #0
	mov r0, sb
	ldr r4, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0805A6C0
	movs r2, #1
_0805A6C0:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0805A6D2
	movs r3, #1
_0805A6D2:
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
	beq _0805A6F4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805A6FA
	.align 2, 0
_0805A6F0: .4byte 0xFFFFF640
_0805A6F4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805A6FA:
	strb r0, [r5, #0xa]
_0805A6FC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, #0x60
	str r1, [r5, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805A720
	str r0, [r5, #0x60]
_0805A720:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805A736
	movs r0, #0xe
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
_0805A736:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start blizzackBomb
blizzackBomb: @ 0x0805A744
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A76A
	ldr r1, _0805A7B0 @ =0x0000B40F
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A7B4 @ =0x0000640E
	strh r1, [r0]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0x12]
_0805A76A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r3, #0
	ldr r0, _0805A7B8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805A780
	movs r3, #1
_0805A780:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805A792
	movs r3, #1
_0805A792:
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
	beq _0805A7BC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805A7C2
	.align 2, 0
_0805A7B0: .4byte 0x0000B40F
_0805A7B4: .4byte 0x0000640E
_0805A7B8: .4byte pZero2
_0805A7BC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805A7C2:
	strb r0, [r4, #0xa]
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
	ble _0805A7E2
	str r0, [r4, #0x60]
_0805A7E2:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bne _0805A864
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0805A814
	ldr r0, _0805A80C @ =pZero2
	ldr r3, [r0]
	ldr r0, [r3, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #0xc
	asrs r0, r0, #0x10
	ldr r2, [r4, #0x58]
	ldr r1, _0805A810 @ =0xFFFFE000
	b _0805A828
	.align 2, 0
_0805A80C: .4byte pZero2
_0805A810: .4byte 0xFFFFE000
_0805A814:
	ldr r0, _0805A87C @ =pZero2
	ldr r3, [r0]
	ldr r0, [r3, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #0xc
	asrs r0, r0, #0x10
	ldr r2, [r4, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #6
_0805A828:
	adds r2, r2, r1
	ldr r1, [r3, #0x58]
	subs r1, r1, r2
	lsls r1, r1, #0xc
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	asrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #0x43
	bl PlaySound
	adds r1, r5, #6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl blizzack_080aaae0
	subs r1, r5, #6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl blizzack_080aaae0
_0805A864:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805A876
	movs r0, #0xf
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A876:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805A87C: .4byte pZero2

	thumb_func_start blizzackBombFall
blizzackBombFall: @ 0x0805A880
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A8A4
	ldr r1, _0805A8EC @ =0x0000B403
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A8F0 @ =0x00006403
	strh r1, [r0]
	strb r2, [r4, #0xe]
_0805A8A4:
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
	ble _0805A8C8
	str r0, [r4, #0x60]
_0805A8C8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _0805A8E6
	movs r0, #0x10
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_0805A8E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805A8EC: .4byte 0x0000B403
_0805A8F0: .4byte 0x00006403

	thumb_func_start blizzackBombStamp
blizzackBombStamp: @ 0x0805A8F4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0805A92C
	ldr r1, _0805A990 @ =0x0000B404
	adds r0, r5, #0
	bl SetMotion
	ldr r1, [r5, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r5, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A994 @ =0x00006404
	strh r1, [r0]
	strb r2, [r5, #0xe]
	strb r2, [r5, #0x12]
	movs r0, #0x91
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
_0805A92C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	strb r0, [r5, #0x12]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0805A972
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
	ldr r3, _0805A998 @ =0xFFFFFEE8
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #2
	rsbs r0, r0, #0
	subs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl CreateVFX57
_0805A972:
	ldrb r0, [r5, #0x12]
	cmp r0, #0x30
	bne _0805AA3A
	adds r0, r5, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805A99C
	movs r0, #4
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
	movs r0, #5
	b _0805AA38
	.align 2, 0
_0805A990: .4byte 0x0000B404
_0805A994: .4byte 0x00006404
_0805A998: .4byte 0xFFFFFEE8
_0805A99C:
	adds r0, r5, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #1
	bls _0805A9D8
	adds r0, r5, #0
	adds r0, #0xd0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xa4
	asrs r0, r0, #1
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _0805A9D4
	ldr r0, _0805A9D0 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0805A9D4
	movs r0, #0xa
	b _0805A9F6
	.align 2, 0
_0805A9D0: .4byte gScore
_0805A9D4:
	movs r0, #7
	b _0805A9F6
_0805A9D8:
	ldr r2, _0805AA00 @ =RNG_0202f388
	ldr r0, [r2]
	ldr r3, _0805AA04 @ =0x000343FD
	muls r0, r3, r0
	ldr r1, _0805AA08 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r4, #7
	ands r0, r4
	cmp r0, #0
	bne _0805AA0C
	movs r0, #2
_0805A9F6:
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
	b _0805AA3A
	.align 2, 0
_0805AA00: .4byte RNG_0202f388
_0805AA04: .4byte 0x000343FD
_0805AA08: .4byte 0x00269EC3
_0805AA0C:
	adds r0, r1, #0
	muls r0, r3, r0
	ldr r1, _0805AA2C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805AA30
	strb r4, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _0805AA3A
	.align 2, 0
_0805AA2C: .4byte 0x00269EC3
_0805AA30:
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	movs r0, #0xd
_0805AA38:
	strb r0, [r5, #0xf]
_0805AA3A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start blizzackMode17
blizzackMode17: @ 0x0805AA44
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805AA6C
	ldr r1, _0805AAB4 @ =0x0000B405
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805AAB8 @ =0x00006405
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #0x18
	strb r0, [r4, #0x12]
_0805AA6C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0xc
	bne _0805AAEC
	ldr r1, [r4, #0x58]
	ldr r0, _0805AABC @ =0xFFFFC000
	adds r1, r1, r0
	ldr r0, _0805AAC0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	ble _0805AAC4
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	bl CreateProjectile31
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	bl CreateProjectile31
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	bl CreateProjectile31
	adds r0, r4, #0
	movs r1, #1
	movs r2, #7
	bl CreateProjectile31
	b _0805AAEC
	.align 2, 0
_0805AAB4: .4byte 0x0000B405
_0805AAB8: .4byte 0x00006405
_0805AABC: .4byte 0xFFFFC000
_0805AAC0: .4byte pZero2
_0805AAC4:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl CreateProjectile31
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl CreateProjectile31
	adds r0, r4, #0
	movs r1, #1
	movs r2, #2
	bl CreateProjectile31
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	bl CreateProjectile31
_0805AAEC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805AB02
	movs r0, #0x12
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805AB02:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start blizzackMode18
blizzackMode18: @ 0x0805AB08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805AB30
	ldr r1, _0805AB54 @ =0x0000B406
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805AB58 @ =0x00006406
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #8
	strb r0, [r4, #0x12]
_0805AB30:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805AB4C
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805AB4C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805AB54: .4byte 0x0000B406
_0805AB58: .4byte 0x00006406

	thumb_func_start blizzackMode19
blizzackMode19: @ 0x0805AB5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805ABA2
	ldr r1, _0805ABE8 @ =0x0000B40B
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805ABEC @ =0x0000640B
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x5c]
	ldr r0, _0805ABF0 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805AB98
	rsbs r0, r1, #0
	str r0, [r4, #0x5c]
_0805AB98:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805ABF4 @ =sCollisions
	bl SetDDP
_0805ABA2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x60
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805ABBE
	str r0, [r4, #0x60]
_0805ABBE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _0805ABF8
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	cmp r0, #0
	bne _0805AC00
	movs r0, #0x14
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	b _0805AC00
	.align 2, 0
_0805ABE8: .4byte 0x0000B40B
_0805ABEC: .4byte 0x0000640B
_0805ABF0: .4byte 0xFFFFFD00
_0805ABF4: .4byte sCollisions
_0805ABF8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805AC00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start blizzackMode20
blizzackMode20: @ 0x0805AC08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805AC30
	ldr r1, _0805AC54 @ =0x0000B40E
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805AC58 @ =0x0000640D
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #8
	strb r0, [r4, #0x12]
_0805AC30:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805AC4C
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805AC4C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805AC54: .4byte 0x0000B40E
_0805AC58: .4byte 0x0000640D

	thumb_func_start blizzack_0805ac5c
blizzack_0805ac5c: @ 0x0805AC5C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r3, _0805ACEC @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0805AC84
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0805AC84
	ldr r0, _0805ACF0 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805AC84:
	adds r0, r4, #0
	adds r0, #0xc8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl StopSound
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0x12]
	movs r2, #0
	ldr r0, _0805ACF4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805ACA6
	movs r2, #1
_0805ACA6:
	adds r5, r4, #0
	adds r5, #0xc4
	strb r2, [r5]
	ldr r1, _0805ACF8 @ =0x0000B40B
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _0805AD00
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0805ACFC @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r3, [r5]
	movs r0, #0
	mov r1, sp
	bl FUN_080b2b40
	movs r0, #2
	b _0805AD02
	.align 2, 0
_0805ACEC: .4byte gStageRun
_0805ACF0: .4byte 0x0000FFFE
_0805ACF4: .4byte pZero2
_0805ACF8: .4byte 0x0000B40B
_0805ACFC: .4byte 0xFFFFE400
_0805AD00:
	movs r0, #1
_0805AD02:
	strb r0, [r4, #0xd]
	movs r2, #0
	movs r1, #1
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x2c]
	strb r1, [r0, #0xf]
	str r2, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start blizzack_0805ad2c
blizzack_0805ad2c: @ 0x0805AD2C
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805AD4A
	ldr r1, _0805AD60 @ =0x0000B40B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	str r0, [r4, #0x60]
	strb r0, [r4, #0x12]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
_0805AD4A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _0805AD90
	cmp r0, #1
	bgt _0805AD64
	cmp r0, #0
	beq _0805AD6A
	b _0805ADC8
	.align 2, 0
_0805AD60: .4byte 0x0000B40B
_0805AD64:
	cmp r0, #2
	beq _0805ADAC
	b _0805ADC8
_0805AD6A:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805ADC8
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [sp]
	ldr r0, _0805AD8C @ =0xFFFFE800
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	b _0805ADC2
	.align 2, 0
_0805AD8C: .4byte 0xFFFFE800
_0805AD90:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0805ADC8
	ldr r2, _0805ADA8 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _0805ADC2
	.align 2, 0
_0805ADA8: .4byte gStageRun
_0805ADAC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805ADC8
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_0805ADC2:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0805ADC8:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start blizzack_0805add0
blizzack_0805add0: @ 0x0805ADD0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0805AE6E
	ldr r1, _0805AE24 @ =0x0000B40C
	adds r0, r5, #0
	bl SetMotion
	adds r4, r5, #0
	adds r4, #0xc4
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
	beq _0805AE28
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805AE2E
	.align 2, 0
_0805AE24: .4byte 0x0000B40C
_0805AE28:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805AE2E:
	strb r0, [r5, #0xa]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805AE42
	movs r0, #0x20
	str r0, [r5, #0x5c]
	subs r0, #0x21
	b _0805AE4A
_0805AE42:
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	movs r0, #1
_0805AE4A:
	str r0, [r5, #0x64]
	movs r4, #0
	movs r0, #0x20
	strb r0, [r5, #0x12]
	strb r4, [r5, #0xe]
	strb r4, [r5, #0xf]
	lsls r2, r1, #0x18
	lsrs r2, r2, #0x1c
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	movs r1, #2
	bl CreateEnemy42
	str r4, [r5, #0x2c]
	movs r0, #0x2f
	bl PlaySound
_0805AE6E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	beq _0805AEAC
	cmp r0, #1
	bgt _0805AE84
	cmp r0, #0
	beq _0805AE8E
	b _0805AF0C
_0805AE84:
	cmp r0, #2
	beq _0805AED4
	cmp r0, #3
	beq _0805AEF0
	b _0805AF0C
_0805AE8E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x64]
	adds r1, r1, r0
	str r1, [r5, #0x5c]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805AF0C
	b _0805AF06
_0805AEAC:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805AF0C
	movs r0, #0xe0
	lsls r0, r0, #4
	str r0, [sp]
	ldr r0, _0805AED0 @ =0xFFFFE800
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sp
	bl CreateBossExplosion
	str r0, [r5, #0x2c]
	b _0805AF06
	.align 2, 0
_0805AED0: .4byte 0xFFFFE800
_0805AED4:
	ldr r0, [r5, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0805AF0C
	ldr r2, _0805AEEC @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	movs r0, #0x20
	strb r0, [r5, #0x12]
	b _0805AF06
	.align 2, 0
_0805AEEC: .4byte gStageRun
_0805AEF0:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805AF0C
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
_0805AF06:
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_0805AF0C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

