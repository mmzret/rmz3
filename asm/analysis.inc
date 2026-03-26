	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start sd_analysis_080f85e0
sd_analysis_080f85e0: @ 0x080F85E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _080F8638
	ldr r0, _080F8634 @ =0x00000DCC
	adds r5, r6, r0
	movs r0, #1
	strb r0, [r5, #0xc]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl CreateMenuComp2
	adds r4, r0, #0
	str r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, #0x18
	adds r4, #0x74
	strh r0, [r4]
	ldr r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #0xb]
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x18
	adds r4, #0x76
	strh r0, [r4]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
	b _080F8754
	.align 2, 0
_080F8634: .4byte 0x00000DCC
_080F8638:
	ldr r0, _080F8654 @ =0x00000DCC
	adds r3, r6, r0
	ldrb r1, [r3, #0xa]
	ldr r0, _080F8658 @ =gJoypad
	ldrh r2, [r0, #6]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080F865C
	cmp r1, #0
	beq _080F868C
	subs r0, r1, #1
	b _080F868A
	.align 2, 0
_080F8654: .4byte 0x00000DCC
_080F8658: .4byte gJoypad
_080F865C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080F866C
	cmp r1, #0xb2
	bhi _080F868C
	adds r0, r1, #1
	b _080F868A
_080F866C:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080F867C
	cmp r1, #4
	bls _080F868C
	subs r0, r1, #5
	b _080F868A
_080F867C:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _080F868C
	cmp r1, #0xae
	bhi _080F868C
	adds r0, r1, #5
_080F868A:
	strb r0, [r3, #0xa]
_080F868C:
	ldr r0, _080F86B4 @ =0x00000DCC
	adds r4, r6, r0
	ldrb r0, [r4, #0xa]
	cmp r1, r0
	beq _080F869C
	movs r0, #1
	bl PlaySound
_080F869C:
	ldrb r0, [r4, #0xa]
	movs r1, #5
	bl __udivsi3
	adds r2, r0, #0
	ldrb r1, [r4, #0xb]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	bls _080F86B8
	strb r2, [r4, #0xb]
	b _080F86C4
	.align 2, 0
_080F86B4: .4byte 0x00000DCC
_080F86B8:
	ldrb r1, [r4, #0xb]
	subs r0, #5
	cmp r1, r0
	bge _080F86C8
	subs r0, r2, #5
	strb r0, [r4, #0xb]
_080F86C4:
	movs r0, #1
	strb r0, [r4, #0xc]
_080F86C8:
	ldr r0, _080F8734 @ =0x00000DCC
	adds r5, r6, r0
	ldr r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, #0x18
	adds r4, #0x74
	strh r0, [r4]
	ldr r4, [r5, #4]
	ldrb r0, [r5, #0xa]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #0xb]
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x18
	adds r4, #0x76
	strh r0, [r4]
	ldr r0, _080F8738 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r4, #1
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080F8748
	ldr r0, _080F873C @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r2, [r5, #0xa]
	lsrs r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	movs r1, #3
	ands r1, r2
	asrs r0, r1
	ands r0, r3
	cmp r0, #0
	beq _080F8740
	ldr r0, [r5, #4]
	adds r0, #0x78
	strb r4, [r0]
	strb r4, [r6, #2]
	movs r0, #0
	strb r0, [r6, #3]
	b _080F8754
	.align 2, 0
_080F8734: .4byte 0x00000DCC
_080F8738: .4byte gJoypad
_080F873C: .4byte gStageDiskManager
_080F8740:
	movs r0, #4
	bl PlaySound
	b _080F8754
_080F8748:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080F8754
	movs r0, #3
	strb r0, [r6, #1]
_080F8754:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sd_analysis_080f875c
sd_analysis_080f875c: @ 0x080F875C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _080F880C
	ldr r0, _080F8798 @ =gStageDiskManager
	ldr r1, [r0]
	ldr r0, _080F879C @ =0x00000DCC
	add r0, r8
	ldrb r2, [r0, #0xa]
	lsrs r0, r2, #2
	adds r1, r1, r0
	ldrb r1, [r1]
	movs r0, #3
	ands r0, r2
	adds r0, #4
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080F87A0
	movs r0, #2
	bl PlaySound
	b _080F87A6
	.align 2, 0
_080F8798: .4byte gStageDiskManager
_080F879C: .4byte 0x00000DCC
_080F87A0:
	movs r0, #0xe
	bl PlaySound
_080F87A6:
	ldr r4, _080F87CC @ =0x00000DCC
	add r4, r8
	ldrb r1, [r4, #0xa]
	mov r0, r8
	movs r2, #0
	bl openSecretDisk
	ldrb r0, [r4, #0xa]
	cmp r0, #0x13
	bls _080F87F4
	cmp r0, #0x2e
	bhi _080F87D0
	movs r0, #0x13
	strb r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #0x11]
	movs r0, #9
	strb r0, [r4, #0x12]
	b _080F87FC
	.align 2, 0
_080F87CC: .4byte 0x00000DCC
_080F87D0:
	cmp r0, #0x3b
	bhi _080F87E2
	movs r0, #2
	strb r0, [r4, #0x10]
	movs r0, #0x11
	strb r0, [r4, #0x11]
	movs r0, #7
	strb r0, [r4, #0x12]
	b _080F87FC
_080F87E2:
	cmp r0, #0x5d
	bhi _080F87F4
	movs r0, #8
	strb r0, [r4, #0x10]
	movs r0, #0xb
	strb r0, [r4, #0x11]
	movs r0, #0x16
	strb r0, [r4, #0x12]
	b _080F87FC
_080F87F4:
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x11]
	strb r0, [r4, #0x10]
_080F87FC:
	ldr r1, _080F88E0 @ =0x00000DCC
	add r1, r8
	movs r0, #1
	strb r0, [r1, #0xc]
	mov r1, r8
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_080F880C:
	movs r7, #2
	ldr r2, _080F88E4 @ =0x03002BC0
	mov sl, r2
	movs r4, #0x1f
	mov sb, r4
	movs r5, #0x1f
	mov ip, r5
_080F881A:
	lsls r0, r7, #1
	mov r1, sl
	adds r6, r0, r1
	ldrh r1, [r6]
	adds r4, r1, #0
	ldr r2, _080F88E8 @ =0x03002BE0
	adds r0, r0, r2
	ldrh r2, [r0]
	str r2, [sp, #0xc]
	movs r0, #0x1f
	adds r3, r1, #0
	ands r3, r0
	adds r0, r2, #0
	mov r5, ip
	ands r0, r5
	lsrs r0, r0, #1
	cmp r3, r0
	bls _080F8844
	subs r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080F8844:
	lsrs r1, r1, #5
	mov r0, ip
	ands r1, r0
	lsrs r0, r2, #5
	mov r2, sb
	ands r0, r2
	lsrs r0, r0, #1
	cmp r1, r0
	bls _080F885C
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_080F885C:
	lsrs r2, r4, #0xa
	mov r4, ip
	ands r2, r4
	ldr r5, [sp, #0xc]
	lsrs r0, r5, #0xa
	mov r4, sb
	ands r0, r4
	lsrs r0, r0, #1
	cmp r2, r0
	bls _080F8876
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080F8876:
	lsls r0, r2, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r3
	strh r0, [r6]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0xf
	bls _080F881A
	ldr r5, _080F88EC @ =u8_ARRAY_ARRAY_083864d8
	ldr r4, _080F88E0 @ =0x00000DCC
	add r4, r8
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _080F8950
	ldrb r0, [r1, #5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x19
	ldrb r3, [r4, #0xe]
	cmp r3, r2
	bhs _080F88F0
	lsrs r1, r0, #0x1c
	adds r1, r3, r1
	strb r1, [r4, #0xe]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0, #6]
	lsrs r0, r0, #4
	ldrb r2, [r4, #0xf]
	adds r0, r0, r2
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	adds r2, r0, r5
	ldrb r0, [r2, #5]
	lsrs r0, r0, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, r0
	bls _080F88D2
	strb r0, [r4, #0xe]
_080F88D2:
	ldrb r0, [r2, #6]
	lsrs r1, r0, #1
	ldrb r0, [r4, #0xf]
	cmp r0, r1
	bls _080F8950
	strb r1, [r4, #0xf]
	b _080F8950
	.align 2, 0
_080F88E0: .4byte 0x00000DCC
_080F88E4: .4byte 0x03002BC0
_080F88E8: .4byte 0x03002BE0
_080F88EC: .4byte u8_ARRAY_ARRAY_083864d8
_080F88F0:
	strb r2, [r4, #0xe]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	ldr r5, _080F897C @ =u8_ARRAY_ARRAY_083864d8
	adds r0, r0, r5
	ldrb r0, [r0, #6]
	lsrs r0, r0, #1
	strb r0, [r4, #0xf]
	mov r1, r8
	ldrb r0, [r1, #3]
	ldrb r5, [r4, #0xa]
	cmp r0, #1
	bne _080F8950
	lsls r0, r5, #3
	ldr r2, _080F897C @ =u8_ARRAY_ARRAY_083864d8
	adds r0, r0, r2
	ldrb r2, [r0, #4]
	ldrh r3, [r0]
	movs r1, #2
	ldrsb r1, [r0, r1]
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #8
	str r0, [sp]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	ldr r1, _080F897C @ =u8_ARRAY_ARRAY_083864d8
	adds r0, r0, r1
	movs r1, #3
	ldrsb r1, [r0, r1]
	movs r0, #0x50
	subs r0, r0, r1
	lsls r0, r0, #8
	str r0, [sp, #4]
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #3
	ldr r4, _080F897C @ =u8_ARRAY_ARRAY_083864d8
	adds r0, r0, r4
	ldrb r0, [r0, #7]
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r5, #0
	bl FUN_080e83d0
	mov r5, r8
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_080F8950:
	ldr r0, _080F8980 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080F896A
	movs r0, #3
	bl PlaySound
	mov r1, r8
	ldrb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #2]
_080F896A:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F897C: .4byte u8_ARRAY_ARRAY_083864d8
_080F8980: .4byte gJoypad

	thumb_func_start sd_analysis_080f8984
sd_analysis_080f8984: @ 0x080F8984
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _080F89B8 @ =0x00000DCC
	adds r2, r3, r0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080F89F4
	adds r4, r0, #0
	ldr r1, _080F89BC @ =u8_ARRAY_ARRAY_083864d8
	ldrb r0, [r2, #0xa]
	lsls r0, r0, #3
	adds r5, r0, r1
	ldrb r0, [r5, #5]
	lsrs r1, r0, #4
	subs r0, r4, r1
	cmp r0, #0
	ble _080F89C6
	strb r0, [r2, #0xe]
	ldrb r3, [r2, #0xf]
	ldrb r0, [r5, #6]
	lsrs r1, r0, #4
	subs r0, r3, r1
	cmp r0, #0
	ble _080F89C0
	strb r0, [r2, #0xf]
	b _080F8A18
	.align 2, 0
_080F89B8: .4byte 0x00000DCC
_080F89BC: .4byte u8_ARRAY_ARRAY_083864d8
_080F89C0:
	movs r0, #0
	strb r0, [r2, #0xf]
	b _080F8A18
_080F89C6:
	movs r0, #0
	strb r0, [r2, #0xe]
	strb r0, [r2, #0xf]
	strb r0, [r3, #2]
	strb r0, [r3, #3]
	movs r2, #2
	ldr r3, _080F89F0 @ =0x03002BC0
	adds r4, r3, #0
	adds r4, #0x20
_080F89D8:
	lsls r0, r2, #1
	adds r1, r0, r3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _080F89D8
	b _080F8A18
	.align 2, 0
_080F89F0: .4byte 0x03002BC0
_080F89F4:
	strb r0, [r2, #0xe]
	strb r0, [r2, #0xf]
	strb r0, [r3, #2]
	strb r0, [r3, #3]
	movs r2, #2
	ldr r3, _080F8A20 @ =0x03002BC0
	adds r4, r3, #0
	adds r4, #0x20
_080F8A04:
	lsls r0, r2, #1
	adds r1, r0, r3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _080F8A04
_080F8A18:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8A20: .4byte 0x03002BC0

	thumb_func_start printThreeDigitNumber
printThreeDigitNumber: @ 0x080F8A24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r5, #0
	ldr r0, _080F8A7C @ =StringOfsTable
	mov r8, r0
_080F8A3C:
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, #0x3c
	add r0, r8
	ldrh r0, [r0]
	ldr r1, _080F8A80 @ =gStringData
	adds r0, r0, r1
	subs r1, r7, r5
	adds r2, r6, #0
	bl PrintString
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #2
	bls _080F8A3C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F8A7C: .4byte StringOfsTable
_080F8A80: .4byte gStringData

	thumb_func_start openSecretDisk
openSecretDisk: @ 0x080F8A84
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	ldr r1, _080F8AD8 @ =0x000064AC
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r2, #0
	beq _080F8AA4
	subs r0, r5, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bls _080F8B6C
	cmp r5, #0x6d
	bhi _080F8B6C
_080F8AA4:
	ldr r0, _080F8ADC @ =gStageDiskManager
	ldr r1, [r0]
	lsrs r0, r5, #2
	adds r6, r1, r0
	ldrb r2, [r6]
	movs r3, #3
	ands r3, r5
	adds r1, r3, #4
	adds r0, r2, #0
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080F8B6C
	movs r0, #0x10
	lsls r0, r3
	orrs r2, r0
	strb r2, [r6]
	cmp r5, #5
	bhi _080F8B48
	lsls r0, r5, #2
	ldr r1, _080F8AE0 @ =_080F8AE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F8AD8: .4byte 0x000064AC
_080F8ADC: .4byte gStageDiskManager
_080F8AE0: .4byte _080F8AE4
_080F8AE4: @ jump table
	.4byte _080F8AFC @ case 0
	.4byte _080F8B06 @ case 1
	.4byte _080F8B10 @ case 2
	.4byte _080F8B1E @ case 3
	.4byte _080F8B28 @ case 4
	.4byte _080F8B32 @ case 5
_080F8AFC:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x17]
	movs r0, #4
	b _080F8B18
_080F8B06:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x17]
	movs r0, #2
	b _080F8B18
_080F8B10:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x17]
	movs r0, #8
_080F8B18:
	orrs r0, r1
	strb r0, [r2, #0x17]
	b _080F8B3E
_080F8B1E:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x19]
	movs r0, #0x40
	b _080F8B3A
_080F8B28:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x19]
	movs r0, #2
	b _080F8B3A
_080F8B32:
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r2, #0x19]
	movs r0, #0x80
_080F8B3A:
	orrs r0, r1
	strb r0, [r2, #0x19]
_080F8B3E:
	ldr r1, _080F8B44 @ =0x0000017B
	b _080F8B84
	.align 2, 0
_080F8B44: .4byte 0x0000017B
_080F8B48:
	cmp r5, #0x13
	bls _080F8B6C
	cmp r5, #0x5d
	bhi _080F8B68
	ldr r0, _080F8B64 @ =gUnlockedElfPtr
	ldr r1, [r0]
	adds r1, r5, r1
	subs r1, #0x14
	ldrb r0, [r1]
	movs r2, #1
	orrs r0, r2
	strb r0, [r1]
	b _080F8B82
	.align 2, 0
_080F8B64: .4byte gUnlockedElfPtr
_080F8B68:
	cmp r5, #0x6d
	bls _080F8B70
_080F8B6C:
	movs r0, #0
	b _080F8B86
_080F8B70:
	ldr r1, _080F8B8C @ =DiskECrystalAmounts
	adds r0, r5, #0
	subs r0, #0x5e
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl AddECrystal
_080F8B82:
	ldr r1, _080F8B90 @ =0x0000010D
_080F8B84:
	adds r0, r5, r1
_080F8B86:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080F8B8C: .4byte DiskECrystalAmounts
_080F8B90: .4byte 0x0000010D

	thumb_func_start clearSecretDiskData
clearSecretDiskData: @ 0x080F8B94
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080F8BC8 @ =gStageDiskManager
	str r4, [r0]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080F8BCC @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x20
	ldr r2, _080F8BD0 @ =0x05000004
	adds r1, r4, #0
	bl CpuSet
	bl clearStageDisk
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8BC8: .4byte gStageDiskManager
_080F8BCC: .4byte 0x01000008
_080F8BD0: .4byte 0x05000004

	thumb_func_start clearSecretDiskDataHard
clearSecretDiskDataHard: @ 0x080F8BD4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080F8C08 @ =gStageDiskManager
	str r4, [r0]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080F8C0C @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x20
	ldr r2, _080F8C10 @ =0x05000004
	adds r1, r4, #0
	bl CpuSet
	bl clearStageDisk
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8C08: .4byte gStageDiskManager
_080F8C0C: .4byte 0x01000008
_080F8C10: .4byte 0x05000004

	thumb_func_start unlockAllSecretDisk
unlockAllSecretDisk: @ 0x080F8C14
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r6, _080F8C74 @ =gStageDiskManager
	str r4, [r6]
	movs r5, #0
	str r5, [sp]
	ldr r2, _080F8C78 @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	str r5, [sp, #4]
	add r0, sp, #4
	adds r4, #0x20
	ldr r2, _080F8C7C @ =0x05000004
	adds r1, r4, #0
	bl CpuSet
	movs r7, #3
_080F8C3C:
	ldr r2, [r6]
	lsrs r4, r5, #2
	adds r2, r2, r4
	adds r3, r5, #0
	ands r3, r7
	movs r0, #1
	lsls r0, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r6]
	adds r2, r2, r4
	movs r0, #0x10
	lsls r0, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xb3
	bls _080F8C3C
	bl clearStageDisk
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F8C74: .4byte gStageDiskManager
_080F8C78: .4byte 0x01000008
_080F8C7C: .4byte 0x05000004

	thumb_func_start clearStageDisk
clearStageDisk: @ 0x080F8C80
	push {r4, r5, lr}
	movs r2, #0
	ldr r5, _080F8CA8 @ =gStageDiskManager
	adds r4, r5, #4
	movs r3, #0xff
_080F8C8A:
	adds r0, r2, r4
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #9
	bls _080F8C8A
	movs r0, #0
	strb r0, [r5, #0xe]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F8CA8: .4byte gStageDiskManager

	thumb_func_start getDiskInStageRun
getDiskInStageRun: @ 0x080F8CAC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, _080F8CDC @ =gStageDiskManager
	ldr r2, [r3]
	lsrs r0, r0, #0x1a
	adds r2, r2, r0
	movs r1, #3
	ands r1, r4
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #4
	ldrb r1, [r3, #0xe]
	adds r0, r0, r1
	strb r4, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F8CDC: .4byte gStageDiskManager

	thumb_func_start allSecretDiskFound
allSecretDiskFound: @ 0x080F8CE0
	push {r4, lr}
	movs r2, #0
	ldr r0, _080F8D08 @ =gStageDiskManager
	ldr r3, [r0]
	movs r4, #0xf
_080F8CEA:
	lsrs r0, r2, #2
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, #0
	ands r1, r0
	movs r0, #3
	ands r0, r2
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080F8D0C
	movs r0, #0
	b _080F8D18
	.align 2, 0
_080F8D08: .4byte gStageDiskManager
_080F8D0C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xb3
	bls _080F8CEA
	movs r0, #1
_080F8D18:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
