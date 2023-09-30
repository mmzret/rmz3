	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateHeavyCannonBall
CreateHeavyCannonBall: @ 0x0807AA8C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _0807AAE0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _0807AAD8
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807AAE4 @ =gEnemyFnTable
	movs r0, #0x1c
	strb r0, [r4, #9]
	ldr r0, [r1, #0x70]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	strb r5, [r4, #0x12]
	str r6, [r4, #0x54]
	str r7, [r4, #0x58]
_0807AAD8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807AAE0: .4byte gZakoHeaderPtr
_0807AAE4: .4byte gEnemyFnTable

	thumb_func_start FUN_0807aae8
FUN_0807aae8: @ 0x0807AAE8
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0xc]
	ldr r5, [r0, #0x2c]
	ldr r3, [r2, #0x2c]
	ldr r0, [r2, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807AB10
	movs r4, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0807AB0A
	movs r4, #1
_0807AB0A:
	adds r0, r3, #0
	adds r0, #0xb4
	strb r4, [r0]
_0807AB10:
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807AB2A
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0807AB2A
	movs r0, #0xff
	strb r0, [r3, #0x12]
_0807AB2A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807ab30
FUN_0807ab30: @ 0x0807AB30
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0807AB46
	movs r0, #0
	b _0807AB60
_0807AB46:
	ldr r1, _0807AB64 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl HeavyCannon_Die
	movs r0, #1
_0807AB60:
	pop {r1}
	bx r1
	.align 2, 0
_0807AB64: .4byte gEnemyFnTable

	thumb_func_start HeavyCannon_Init
HeavyCannon_Init: @ 0x0807AB68
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0807ABD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0807ABD4 @ =0x083677CC
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0807ABD8 @ =0x08367784
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0xa
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0807ABDC @ =FUN_0807aae8
	str r0, [r5, #0x24]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r4, #0
	bl HeavyCannon_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807ABD0: .4byte gEnemyFnTable
_0807ABD4: .4byte 0x083677CC
_0807ABD8: .4byte 0x08367784
_0807ABDC: .4byte FUN_0807aae8

	thumb_func_start HeavyCannon_Update
HeavyCannon_Update: @ 0x0807ABE0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0807AC28 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0807AC30
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
	ldr r1, _0807AC2C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0807AC5C
	.align 2, 0
_0807AC28: .4byte gCurStory
_0807AC2C: .4byte gEnemyFnTable
_0807AC30:
	adds r0, r4, #0
	bl FUN_0807ab30
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807AC5C
	ldr r1, _0807AC64 @ =0x08367774
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807AC68 @ =0x0836777C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0807AC5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807AC64: .4byte 0x08367774
_0807AC68: .4byte 0x0836777C

	thumb_func_start HeavyCannon_Die
HeavyCannon_Die: @ 0x0807AC6C
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0807ACC8 @ =0x083677CE
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	ldr r1, _0807ACCC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807ACC8: .4byte 0x083677CE
_0807ACCC: .4byte gEnemyFnTable

	thumb_func_start FUN_0807acd0
FUN_0807acd0: @ 0x0807ACD0
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807acd4
FUN_0807acd4: @ 0x0807ACD4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0807ACE4
	cmp r0, #1
	beq _0807AD5A
	b _0807B002
_0807ACE4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807AD04 @ =0x0836779C
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	ldrb r2, [r5, #0x12]
	cmp r2, #0
	beq _0807AD08
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0807AD0E
	.align 2, 0
_0807AD04: .4byte 0x0836779C
_0807AD08:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807AD0E:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _0807AD80 @ =0x00003804
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	movs r0, #0xff
	strb r0, [r5, #0x13]
	str r4, [r5, #0x60]
	ldr r0, _0807AD84 @ =0xFFFFFE80
	str r0, [r5, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807AD52
	movs r2, #0xc0
	lsls r2, r2, #1
_0807AD52:
	str r2, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807AD5A:
	movs r6, #0
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r1, [r0]
	ldr r2, _0807AD88 @ =0x00020001
	ands r1, r2
	adds r7, r0, #0
	cmp r1, r2
	bne _0807AD96
	adds r0, #0x28
	ldrb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807AD8C
	cmp r2, #1
	bne _0807AD96
	b _0807AD90
	.align 2, 0
_0807AD80: .4byte 0x00003804
_0807AD84: .4byte 0xFFFFFE80
_0807AD88: .4byte 0x00020001
_0807AD8C:
	cmp r2, #0
	bne _0807AD96
_0807AD90:
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_0807AD96:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807ADA6
	str r1, [r5, #0x60]
_0807ADA6:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	cmp r1, #0
	ble _0807AE70
	ldr r0, [r5, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r1, r2, r3
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bge _0807AE70
	ldr r1, [r5, #0x60]
	movs r0, #0xb0
	lsls r0, r0, #2
	cmp r1, r0
	ble _0807ADF0
	ldr r0, _0807ADEC @ =0x00000105
	bl PlaySound
	movs r6, #1
	ldr r1, [r5, #0x60]
	rsbs r1, r1, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	cmp r0, #0
	bge _0807ADE6
	adds r0, #0xff
_0807ADE6:
	asrs r0, r0, #8
	b _0807AE00
	.align 2, 0
_0807ADEC: .4byte 0x00000105
_0807ADF0:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _0807ADFE
	adds r0, #5
	bl PlaySound
_0807ADFE:
	movs r0, #0
_0807AE00:
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r1, r0, r4
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _0807AE44
	ldr r0, [r5, #0x54]
	subs r0, #0x40
	bl FUN_08009f6c
	adds r4, r0, #0
	ldr r0, _0807AE3C @ =0xFFFFFA00
	adds r1, r4, r0
	ldr r0, [r5, #0x58]
	subs r4, r1, r0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	ldr r0, _0807AE40 @ =0x00001FFF
	cmp r1, r0
	bhi _0807AE70
	cmp r4, #0
	bge _0807AE34
	adds r0, r4, #3
	asrs r4, r0, #2
_0807AE34:
	ldr r0, [r5, #0x5c]
	subs r0, r0, r4
	b _0807AE6E
	.align 2, 0
_0807AE3C: .4byte 0xFFFFFA00
_0807AE40: .4byte 0x00001FFF
_0807AE44:
	ldr r0, [r5, #0x54]
	adds r0, #0x40
	bl FUN_08009f6c
	adds r4, r0, #0
	ldr r3, _0807AEB8 @ =0xFFFFFA00
	adds r1, r4, r3
	ldr r0, [r5, #0x58]
	subs r4, r1, r0
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r4, r0
	ldr r0, _0807AEBC @ =0x00001FFF
	cmp r1, r0
	bhi _0807AE70
	cmp r4, #0
	bge _0807AE6A
	adds r0, r4, #3
	asrs r4, r0, #2
_0807AE6A:
	ldr r0, [r5, #0x5c]
	adds r0, r0, r4
_0807AE6E:
	str r0, [r5, #0x5c]
_0807AE70:
	ldr r0, [r5, #0x60]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, #0xff
	cmp r0, r1
	bhi _0807AEA4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807AEA4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	ldr r3, _0807AEB8 @ =0xFFFFFA00
	adds r0, r0, r3
	str r0, [r5, #0x58]
	movs r0, #0
	str r0, [r5, #0x60]
_0807AEA4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	bge _0807AEC4
	ldr r2, _0807AEC0 @ =0xFFFFF800
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	b _0807AECE
	.align 2, 0
_0807AEB8: .4byte 0xFFFFFA00
_0807AEBC: .4byte 0x00001FFF
_0807AEC0: .4byte 0xFFFFF800
_0807AEC4:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807AF4C @ =0xFFFFF800
_0807AECE:
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807AEF6
	movs r6, #1
	ldr r0, _0807AF50 @ =0x00000105
	bl PlaySound
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	ldr r1, _0807AF54 @ =0x000002FF
	adds r0, r0, r1
	cmp r0, r1
	bhi _0807AEF6
	ldr r0, _0807AF58 @ =0xFFFFFD00
	str r0, [r5, #0x60]
_0807AEF6:
	ldr r0, _0807AF5C @ =pZero2
	ldr r0, [r0]
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807AF1C
	ldr r0, [r7]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807AF1C
	ldr r0, _0807AF50 @ =0x00000105
	bl PlaySound
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_0807AF1C:
	ldrb r0, [r5, #0x13]
	subs r1, r0, #1
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0x12]
	adds r0, r6, r0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0807AF36
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _0807AF64
_0807AF36:
	ldr r1, _0807AF60 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _0807B002
	.align 2, 0
_0807AF4C: .4byte 0xFFFFF800
_0807AF50: .4byte 0x00000105
_0807AF54: .4byte 0x000002FF
_0807AF58: .4byte 0xFFFFFD00
_0807AF5C: .4byte pZero2
_0807AF60: .4byte gEnemyFnTable
_0807AF64:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _0807AF8A
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _0807AFAC
_0807AF8A:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_0807AFAC:
	ldr r0, _0807AFF4 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0807AFFC
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r2, [r7]
	adds r0, r5, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0807AFF8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _0807B002
	.align 2, 0
_0807AFF4: .4byte gStageRun+232
_0807AFF8: .4byte gEnemyFnTable
_0807AFFC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0807B002:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807b008
FUN_0807b008: @ 0x0807B008
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _0807B018
	cmp r2, #1
	beq _0807B036
	b _0807B0C2
_0807B018:
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
	strb r2, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807B036:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807B04E
	str r1, [r4, #0x60]
_0807B04E:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807B06C
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807B072
_0807B06C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807B072:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _0807B0C8 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0807B0C2
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
	ldr r1, _0807B0CC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0807B0C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B0C8: .4byte gStageRun+232
_0807B0CC: .4byte gEnemyFnTable
