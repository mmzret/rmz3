	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Elf7_Init
Elf7_Init: @ 0x080E3A5C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r0, _080E3A90 @ =gPause
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0xa]
	orrs r4, r0
	movs r0, #2
	orrs r4, r0
	strb r4, [r5, #0xa]
	ldr r1, _080E3A94 @ =0x00000121
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi _080E3A98
	movs r0, #0
	b _080E3A9E
	.align 2, 0
_080E3A90: .4byte gPause
_080E3A94: .4byte 0x00000121
_080E3A98:
	cmp r0, #0x27
	bhi _080E3AB0
	movs r0, #1
_080E3A9E:
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	b _080E3AC2
_080E3AB0:
	movs r0, #2
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
_080E3AC2:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
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
	beq _080E3AF4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E3AFA
_080E3AF4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E3AFA:
	strb r0, [r5, #0xa]
	ldr r1, _080E3B44 @ =0x08371D94
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0xba
	movs r2, #0
	strb r0, [r1]
	adds r1, #6
	movs r0, #0xc0
	lsls r0, r0, #4
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0xb8
	strb r2, [r0]
	adds r0, #3
	strb r2, [r0]
	subs r1, #7
	movs r0, #0x20
	strb r0, [r1]
	ldr r1, _080E3B48 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Elf7_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E3B44: .4byte 0x08371D94
_080E3B48: .4byte gElfFnTable

	thumb_func_start Elf7_Update
Elf7_Update: @ 0x080E3B4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	ldr r1, _080E3BA0 @ =gZeroRanges
	ldr r2, _080E3BA4 @ =0x00000147
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r6, [r0, #4]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E3B8A
	adds r0, r4, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _080E3BAC
_080E3B8A:
	ldr r1, _080E3BA8 @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080E3D08
	.align 2, 0
_080E3BA0: .4byte gZeroRanges
_080E3BA4: .4byte 0x00000147
_080E3BA8: .4byte gElfFnTable
_080E3BAC:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	asrs r1, r5, #0x10
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, _080E3C40 @ =0x08371D88
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _080E3C44 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x82
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, r8
	muls r1, r0, r1
	asrs r1, r1, #8
	mov r0, r8
	subs r1, r0, r1
	movs r3, #2
	ldrsh r0, [r2, r3]
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	asrs r0, r0, #8
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r5, r1, r0
	cmp r5, #0
	beq _080E3C4C
	ldr r0, _080E3C48 @ =0x000FFFFF
	cmp r5, r0
	bgt _080E3C4C
	movs r4, #0x80
	lsls r4, r4, #0xd
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl __modsi3
	cmp r0, #0
	beq _080E3C2A
	adds r6, #1
_080E3C2A:
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	adds r1, r7, #0
	adds r1, #0xb8
	lsrs r0, r0, #0x10
	ldrb r4, [r1]
	adds r2, r0, r4
	b _080E3C54
	.align 2, 0
_080E3C40: .4byte 0x08371D88
_080E3C44: .4byte gSineTable
_080E3C48: .4byte 0x000FFFFF
_080E3C4C:
	adds r1, r7, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	adds r2, r0, #1
_080E3C54:
	movs r3, #0xff
	ands r2, r3
	strb r2, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	bne _080E3C6A
	movs r1, #1
_080E3C6A:
	ldr r6, _080E3D14 @ =gSineTable
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	asrs r0, r0, #8
	muls r1, r0, r1
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r3
	movs r1, #0x10
	cmp r0, #0x7f
	ble _080E3C94
	movs r1, #0x11
_080E3C94:
	adds r0, r7, #0
	adds r0, #0x25
	strb r1, [r0]
	adds r5, r7, #0
	adds r5, #0xbb
	ldrb r0, [r5]
	adds r4, r0, #1
	adds r0, r4, #0
	movs r1, #0x1c
	bl __modsi3
	adds r4, r0, #0
	strb r4, [r5]
	lsls r0, r4, #8
	movs r1, #0x1c
	bl __divsi3
	adds r4, r0, #0
	movs r2, #0xa0
	lsls r2, r2, #4
	ldr r0, _080E3D18 @ =0x000012FF
	cmp r8, r0
	bgt _080E3CD4
	ldr r0, _080E3D1C @ =0xFFFFF400
	add r0, r8
	muls r2, r0, r2
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r2, #0
	bl __divsi3
	adds r2, r0, #0
_080E3CD4:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r2, r0, #8
	ldr r0, [r7, #0x58]
	subs r0, r0, r2
	str r0, [r7, #0x58]
	adds r4, r7, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E3D08
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r4]
_080E3D08:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E3D14: .4byte gSineTable
_080E3D18: .4byte 0x000012FF
_080E3D1C: .4byte 0xFFFFF400

	thumb_func_start Elf7_Die
Elf7_Die: @ 0x080E3D20
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	ldr r1, _080E3D48 @ =gPause
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080E3D4C @ =0x00000121
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #5
	cmp r0, #0x2f
	bls _080E3D3C
	b _080E3EB0
_080E3D3C:
	lsls r0, r0, #2
	ldr r1, _080E3D50 @ =_080E3D54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E3D48: .4byte gPause
_080E3D4C: .4byte 0x00000121
_080E3D50: .4byte _080E3D54
_080E3D54: @ jump table
	.4byte _080E3E14 @ case 0
	.4byte _080E3E24 @ case 1
	.4byte _080E3E40 @ case 2
	.4byte _080E3E40 @ case 3
	.4byte _080E3EB0 @ case 4
	.4byte _080E3EB0 @ case 5
	.4byte _080E3EB0 @ case 6
	.4byte _080E3EB0 @ case 7
	.4byte _080E3EB0 @ case 8
	.4byte _080E3EB0 @ case 9
	.4byte _080E3EB0 @ case 10
	.4byte _080E3EB0 @ case 11
	.4byte _080E3EB0 @ case 12
	.4byte _080E3EB0 @ case 13
	.4byte _080E3EB0 @ case 14
	.4byte _080E3EB0 @ case 15
	.4byte _080E3EB0 @ case 16
	.4byte _080E3EB0 @ case 17
	.4byte _080E3EB0 @ case 18
	.4byte _080E3EB0 @ case 19
	.4byte _080E3EB0 @ case 20
	.4byte _080E3EB0 @ case 21
	.4byte _080E3E9C @ case 22
	.4byte _080E3EA6 @ case 23
	.4byte _080E3EA6 @ case 24
	.4byte _080E3EA6 @ case 25
	.4byte _080E3EA6 @ case 26
	.4byte _080E3EB0 @ case 27
	.4byte _080E3EB0 @ case 28
	.4byte _080E3EB0 @ case 29
	.4byte _080E3EB0 @ case 30
	.4byte _080E3EB0 @ case 31
	.4byte _080E3EB0 @ case 32
	.4byte _080E3EB0 @ case 33
	.4byte _080E3EB0 @ case 34
	.4byte _080E3EB0 @ case 35
	.4byte _080E3EB0 @ case 36
	.4byte _080E3EB0 @ case 37
	.4byte _080E3EA6 @ case 38
	.4byte _080E3EB0 @ case 39
	.4byte _080E3EA6 @ case 40
	.4byte _080E3EB0 @ case 41
	.4byte _080E3EB0 @ case 42
	.4byte _080E3EB0 @ case 43
	.4byte _080E3EB0 @ case 44
	.4byte _080E3EB0 @ case 45
	.4byte _080E3EB0 @ case 46
	.4byte _080E3EB0 @ case 47
_080E3E14:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #3
	movs r2, #0
	strh r0, [r1, #4]
	strb r2, [r1, #0xa]
	b _080E3E32
_080E3E24:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #3
	movs r2, #0
	strh r0, [r1, #4]
	strb r2, [r1, #0xb]
_080E3E32:
	ldr r0, _080E3E3C @ =0x00000103
	movs r1, #0x5a
	bl PrintTextWindow
	b _080E3EB0
	.align 2, 0
_080E3E3C: .4byte 0x00000103
_080E3E40:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #5
	strh r0, [r1, #4]
	movs r0, #6
	bl PlaySound
	ldr r2, _080E3E98 @ =gMission
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3E76
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3E76
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3E76
	adds r0, #1
	strb r0, [r1]
_080E3E76:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _080E3EB0
	ldr r2, _080E3E98 @ =gMission
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3EB0
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3EB0
	adds r0, #1
	strb r0, [r1]
	b _080E3EB0
	.align 2, 0
_080E3E98: .4byte gMission
_080E3E9C:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #5
	b _080E3EAE
_080E3EA6:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #3
_080E3EAE:
	strh r0, [r1, #4]
_080E3EB0:
	ldr r0, _080E3F14 @ =gMission
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080E3EC2
	adds r0, #1
	strb r0, [r1]
_080E3EC2:
	ldr r1, _080E3F18 @ =gUnlockedElfPtr
	ldr r2, _080E3F1C @ =0x00000121
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080E3F20 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E3F14: .4byte gMission
_080E3F18: .4byte gUnlockedElfPtr
_080E3F1C: .4byte 0x00000121
_080E3F20: .4byte gElfFnTable

	thumb_func_start FUN_080e3f24
FUN_080e3f24: @ 0x080E3F24
	push {lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xc0
	ldr r0, [r2]
	adds r0, #0x30
	str r0, [r2]
	ldr r1, _080E3F50 @ =0x000027FF
	cmp r0, r1
	ble _080E3F4C
	movs r0, #0xa0
	lsls r0, r0, #6
	str r0, [r2]
	adds r1, r3, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080E3F4C:
	pop {r0}
	bx r0
	.align 2, 0
_080E3F50: .4byte 0x000027FF

	thumb_func_start FUN_080e3f54
FUN_080e3f54: @ 0x080E3F54
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xbc
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	cmp r0, #0
	bne _080E3F6C
	ldrb r0, [r2, #0xd]
	adds r0, #1
	strb r0, [r2, #0xd]
_080E3F6C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080e3f70
FUN_080e3f70: @ 0x080E3F70
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r1, _080E3FD8 @ =gZeroRanges
	ldr r2, _080E3FDC @ =0x00000147
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, [r0, #4]
	mov r1, sb
	adds r1, #0xc0
	ldr r0, [r1]
	subs r0, #0x60
	str r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #4
	cmp r0, r2
	bgt _080E3FB8
	str r2, [r1]
	ldr r1, _080E3FE0 @ =gElfFnTable
	mov r2, sb
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_080E3FB8:
	mov r0, sb
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E3FE8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x54]
	adds r2, r1, r0
	asrs r1, r3, #0x10
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	ldr r1, _080E3FE4 @ =0xFFFFFE00
	adds r7, r0, r1
	b _080E4006
	.align 2, 0
_080E3FD8: .4byte gZeroRanges
_080E3FDC: .4byte 0x00000147
_080E3FE0: .4byte gElfFnTable
_080E3FE4: .4byte 0xFFFFFE00
_080E3FE8:
	cmp r0, #1
	bne _080E3FF8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x54]
	adds r2, r1, r0
	ldr r7, [r5, #0x58]
	b _080E4006
_080E3FF8:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x54]
	adds r2, r1, r0
	asrs r1, r4, #0x10
	ldr r0, [r5, #0x58]
	subs r7, r0, r1
_080E4006:
	mov r0, sb
	ldr r6, [r0, #0x54]
	subs r2, r2, r6
	ldr r1, [r0, #0x58]
	mov r8, r1
	subs r7, r7, r1
	adds r0, #0xc0
	ldr r4, [r0]
	movs r5, #0xa0
	lsls r5, r5, #6
	subs r4, r5, r4
	adds r0, r2, #0
	muls r0, r4, r0
	adds r1, r5, #0
	bl __divsi3
	adds r2, r0, #0
	adds r0, r7, #0
	muls r0, r4, r0
	adds r1, r5, #0
	str r2, [sp]
	bl __divsi3
	adds r7, r0, #0
	ldr r2, [sp]
	adds r6, r6, r2
	mov r2, sb
	str r6, [r2, #0x54]
	add r8, r7
	mov r0, r8
	str r0, [r2, #0x58]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
