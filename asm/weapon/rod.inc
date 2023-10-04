	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Rod_Update
Rod_Update: @ 0x08039664
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xb4
	ldr r5, [r4]
	movs r1, #0x93
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080396BC
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080396B8 @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08039928
	.align 2, 0
_080396B8: .4byte gWeaponFnTable
_080396BC:
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080396DC
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _080396DC
	movs r0, #0x2b
	bl PlaySound
	movs r0, #0
	strb r0, [r4, #8]
_080396DC:
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r2, [r0, #6]
	adds r7, r0, #0
	movs r3, #0x71
	adds r3, r3, r6
	mov r8, r3
	cmp r2, #0
	beq _08039768
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #1
	ble _08039768
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r0, [r1, #0xc]
	cmp r0, #2
	beq _08039706
	ldrb r0, [r1, #0xd]
	cmp r0, #2
	bne _08039764
_08039706:
	ldrb r0, [r7, #4]
	ldrb r1, [r1, #0xe]
	cmp r0, r1
	bne _08039764
	cmp r2, #1
	bne _0803973C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl CreateSoulLauncher
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	bl CreateSoulLauncher
	adds r0, r5, #0
	movs r1, #2
	movs r2, #1
	bl CreateSoulLauncher
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl CreateSoulLauncher
	b _08039764
_0803973C:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl CreateSoulLauncher
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl CreateSoulLauncher
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl CreateSoulLauncher
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0
	bl CreateSoulLauncher
_08039764:
	movs r0, #0
	strb r0, [r7, #6]
_08039768:
	ldrb r0, [r6, #0x10]
	cmp r0, #0xd
	bne _080397E6
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bne _080397E6
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080397A8
	ldr r0, [r6, #0x54]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r1, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080397DA
	ldr r0, [r6, #0x54]
	ldr r1, _080397A4 @ =0xFFFFF700
	adds r0, r0, r1
	b _080397C8
	.align 2, 0
_080397A4: .4byte 0xFFFFF700
_080397A8:
	ldr r0, [r6, #0x54]
	ldr r1, _08039838 @ =0xFFFFFE00
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080397DA
	ldr r0, [r6, #0x54]
	movs r3, #0x90
	lsls r3, r3, #4
	adds r0, r0, r3
_080397C8:
	ldr r1, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080397E6
_080397DA:
	movs r0, #0x13
	strb r0, [r6, #0x10]
	ldr r3, _0803983C @ =0x00000135
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_080397E6:
	ldr r0, [r5, #0x54]
	str r0, [r6, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r6, #0x58]
	movs r1, #0x93
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, r1
	beq _08039824
	strb r1, [r6, #0x10]
	ldr r1, _08039840 @ =0x08360430
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, r8
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r0, #0x72
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r6, #0
	bl GotoMotion
_08039824:
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08039844
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0803984A
	.align 2, 0
_08039838: .4byte 0xFFFFFE00
_0803983C: .4byte 0x00000135
_08039840: .4byte 0x08360430
_08039844:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803984A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x10]
	cmp r0, #0x15
	bne _080398AC
	adds r0, r6, #0
	adds r0, #0x74
	ldr r2, _080398A4 @ =0x083611F4
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	mov r3, r8
	movs r2, #0
	ldrsb r2, [r3, r2]
	ldr r1, [r1]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrb r2, [r7, #5]
	ldrb r3, [r7, #4]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp]
	ldr r5, _080398A8 @ =0x08361260
	mov r7, r8
	movs r4, #0
	ldrsb r4, [r7, r4]
	adds r4, r4, r5
	ldrb r4, [r4]
	b _080398D8
	.align 2, 0
_080398A4: .4byte 0x083611F4
_080398A8: .4byte 0x08361260
_080398AC:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _080398E4
	adds r0, r6, #0
	adds r0, #0x74
	ldr r2, _080398E0 @ =0x083611F4
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	mov r3, r8
	movs r2, #0
	ldrsb r2, [r3, r2]
	ldr r1, [r1]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrb r2, [r7, #5]
	ldrb r3, [r7, #4]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp]
	ldrb r4, [r7, #7]
_080398D8:
	str r4, [sp, #4]
	bl InitWeaponBody
	b _0803990E
	.align 2, 0
_080398E0: .4byte 0x083611F4
_080398E4:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r2, _08039938 @ =0x083611F4
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	mov r3, r8
	movs r2, #0
	ldrsb r2, [r3, r2]
	ldr r1, [r1]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrb r2, [r7, #5]
	ldrb r3, [r7, #4]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	bl InitWeaponBody
_0803990E:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803992A
	ldr r1, _0803993C @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_08039928:
	str r0, [r6, #0x14]
_0803992A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039938: .4byte 0x083611F4
_0803993C: .4byte gWeaponFnTable

	thumb_func_start Rod_Die
Rod_Die: @ 0x08039940
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803995C @ =gWeaponFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0803995C: .4byte gWeaponFnTable

	thumb_func_start FUN_08039960
FUN_08039960: @ 0x08039960
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	ldr r4, [r1, #0x2c]
	ldr r0, [r1, #0xc]
	ldr r6, [r0, #0x2c]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r7, [r0]
	ldr r0, [r1, #0x14]
	movs r5, #4
	ands r0, r5
	cmp r0, #0
	beq _080399E6
	ldr r3, _080399EC @ =gMission
	ldrh r2, [r3, #0x20]
	ldr r0, _080399F0 @ =0x0000FFFE
	cmp r2, r0
	bhi _08039988
	adds r0, r2, #1
	strh r0, [r3, #0x20]
_08039988:
	ldr r0, [r1, #0x14]
	ands r0, r5
	cmp r0, #0
	beq _080399E6
	ldrb r0, [r4, #0x10]
	subs r0, #0xb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bhi _080399B2
	ldr r4, [r1, #0x2c]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080399F4 @ =0x08360460
	ldrb r1, [r4, #0x10]
	subs r1, #0xb
	adds r1, r1, r2
	ldrb r1, [r1]
	bl CreateWeapon13
_080399B2:
	ldrb r0, [r4, #0x10]
	cmp r0, #0xd
	bne _080399CC
	ldr r1, [r4, #0x58]
	ldr r0, [r6, #0x58]
	cmp r1, r0
	bge _080399CC
	movs r0, #0x13
	strb r0, [r4, #0x10]
	ldr r0, _080399F8 @ =0x00000135
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_080399CC:
	ldrb r0, [r4, #0x10]
	cmp r0, #0x10
	bne _080399E6
	ldr r1, [r4, #0x58]
	ldr r0, [r6, #0x58]
	cmp r1, r0
	bge _080399E6
	movs r0, #0x14
	strb r0, [r4, #0x10]
	ldr r0, _080399F8 @ =0x00000135
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_080399E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080399EC: .4byte gMission
_080399F0: .4byte 0x0000FFFE
_080399F4: .4byte 0x08360460
_080399F8: .4byte 0x00000135

	thumb_func_start FUN_080399fc
FUN_080399fc: @ 0x080399FC
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #9]
	cmp r0, #4
	bne _08039A3C
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08039A40 @ =gWeaponFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_08039A3C:
	pop {r0}
	bx r0
	.align 2, 0
_08039A40: .4byte gWeaponFnTable
