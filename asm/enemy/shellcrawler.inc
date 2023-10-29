	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08095d80
FUN_08095d80: @ 0x08095D80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	subs r0, r2, r1
	ldr r6, _08095DC0 @ =0x0000043F
	cmp r0, r6
	bgt _08095DA2
	movs r5, #1
_08095DA2:
	ldr r0, [r4, #0x54]
	ldr r2, _08095DC4 @ =0xFFFFF600
	adds r0, r0, r2
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r2, r0
	cmp r0, r6
	bgt _08095DB8
	movs r5, #1
_08095DB8:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095DC0: .4byte 0x0000043F
_08095DC4: .4byte 0xFFFFF600

	thumb_func_start FUN_08095dc8
FUN_08095dc8: @ 0x08095DC8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, _08095E00 @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	cmp r5, r1
	bge _08095E08
	cmp r5, #0
	bge _08095E1A
	ldr r0, _08095E04 @ =0xFFFFFC00
	cmp r5, r0
	ble _08095E1A
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	b _08095E16
	.align 2, 0
_08095E00: .4byte 0xFFFFF600
_08095E04: .4byte 0xFFFFFC00
_08095E08:
	cmp r1, #0
	bge _08095E1A
	ldr r0, _08095E24 @ =0xFFFFFC00
	cmp r1, r0
	ble _08095E1A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
_08095E16:
	str r0, [r4, #0x58]
	movs r6, #1
_08095E1A:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095E24: .4byte 0xFFFFFC00

	thumb_func_start FUN_08095e28
FUN_08095e28: @ 0x08095E28
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r4, r0
	ldr r1, _08095E74 @ =0x0000043F
	cmp r0, r1
	bgt _08095E42
	str r4, [r5, #0x58]
_08095E42:
	movs r2, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _08095E4C
	movs r2, #1
_08095E4C:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #0xa
	ldr r1, _08095E78 @ =0xFFFFF600
	adds r6, r0, r1
	ldr r0, [r5, #0x58]
	ldr r1, _08095E7C @ =0xFFFFF800
	adds r4, r0, r1
	cmp r2, #0
	beq _08095E80
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	adds r1, r4, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _08095E9A
	b _08095E90
	.align 2, 0
_08095E74: .4byte 0x0000043F
_08095E78: .4byte 0xFFFFF600
_08095E7C: .4byte 0xFFFFF800
_08095E80:
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	adds r1, r4, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _08095E9A
_08095E90:
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #1
	b _08095EB6
_08095E9A:
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095EB4
	movs r0, #0
	b _08095EB6
_08095EB4:
	movs r0, #2
_08095EB6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Shellcrawler_Init
Shellcrawler_Init: @ 0x08095EBC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08095F04 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldrb r0, [r6, #0x10]
	cmp r0, #4
	bne _08095F10
	movs r0, #9
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08095F08 @ =0x0836A11C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08095F0C @ =FUN_08096348
	str r0, [r4, #0x24]
	b _0809604E
	.align 2, 0
_08095F04: .4byte gEnemyFnTable
_08095F08: .4byte 0x0836A11C
_08095F0C: .4byte FUN_08096348
_08095F10:
	movs r0, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r4, #0
	adds r2, r1, #0
	orrs r2, r0
	strb r2, [r6, #0xa]
	ldr r0, _08095F60 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x13]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08095F6C
	ldr r0, _08095F64 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08095F6C
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08095F68 @ =0x0836A08C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	b _08095F84
	.align 2, 0
_08095F60: .4byte gSystemSavedataManager
_08095F64: .4byte gCurStory
_08095F68: .4byte 0x0836A08C
_08095F6C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08095FC8 @ =0x0836A08C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
_08095F84:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08095FCC @ =FUN_08096348
	str r0, [r4, #0x24]
	ldr r1, _08095FD0 @ =0x0000DB01
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08095FFA
	movs r2, #0
	ldr r0, _08095FD4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08095FBA
	movs r2, #1
_08095FBA:
	cmp r2, #0
	beq _08095FD8
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08095FDE
	.align 2, 0
_08095FC8: .4byte 0x0836A08C
_08095FCC: .4byte FUN_08096348
_08095FD0: .4byte 0x0000DB01
_08095FD4: .4byte pZero2
_08095FD8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_08095FDE:
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
	b _0809603E
_08095FFA:
	cmp r0, #2
	bne _0809601E
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08096040
_0809601E:
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
_0809603E:
	strb r0, [r3]
_08096040:
	movs r0, #0
	strb r0, [r6, #0x10]
	adds r1, r6, #0
	adds r1, #0xbc
	strb r0, [r1]
	subs r1, #4
	str r0, [r1]
_0809604E:
	adds r0, r6, #0
	bl Shellcrawler_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Shellcrawler_Update
Shellcrawler_Update: @ 0x0809605C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080960AC @ =0x080FF05C
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r5, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _080960CC
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _08096084
	b _080961D6
_08096084:
	ldrb r3, [r4, #0xd]
	ldr r1, _080960B0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r2, [r6]
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bne _080960B4
	movs r0, #1
	b _080960C0
	.align 2, 0
_080960AC: .4byte 0x080FF05C
_080960B0: .4byte gEnemyFnTable
_080960B4:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r2
	cmp r0, #0
	beq _080960C0
	movs r0, #3
_080960C0:
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl Shellcrawler_Die
	b _080962CA
_080960CC:
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _080960D4
	b _080961D6
_080960D4:
	ldr r0, _0809611C @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bls _08096124
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08096120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080962CA
	.align 2, 0
_0809611C: .4byte gStageRun+232
_08096120: .4byte gEnemyFnTable
_08096124:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0809617A
	ldr r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809617A
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	beq _080961CA
	movs r0, #0
	adds r1, r4, #0
	mov r2, sp
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0809617A
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08096168
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096164 @ =0x0836A0EC
	bl SetDDP
	b _08096172
	.align 2, 0
_08096164: .4byte 0x0836A0EC
_08096168:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080961F8 @ =0x0836A1AC
	bl SetDDP
_08096172:
	ldr r0, [r4, #0x60]
	str r0, [r4, #0x68]
	movs r0, #0
	str r0, [r4, #0x60]
_0809617A:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	beq _080961CA
	ldr r0, [r5]
	cmp r0, #0
	bne _080961D0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _080961A0
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0809619A
	movs r0, #1
	strb r0, [r4, #0xf]
_0809619A:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _080961CA
_080961A0:
	cmp r0, #1
	bne _080961AE
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #2
	strb r0, [r4, #0xf]
_080961AE:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _080961BA
	strb r0, [r4, #0xf]
_080961BA:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080961FC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	beq _080961CA
	b _080962CA
_080961CA:
	ldr r0, [r5]
	cmp r0, #0
	beq _080961D6
_080961D0:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	bne _08096208
_080961D6:
	ldr r1, _08096200 @ =0x0836A20C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08096204 @ =0x0836A238
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _080962CA
	.align 2, 0
_080961F8: .4byte 0x0836A1AC
_080961FC: .4byte 0x00020001
_08096200: .4byte 0x0836A20C
_08096204: .4byte 0x0836A238
_08096208:
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08096240
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08096228
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096224 @ =0x0836A08C
	bl SetDDP
	b _08096232
	.align 2, 0
_08096224: .4byte 0x0836A08C
_08096228:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809623C @ =0x0836A0BC
	bl SetDDP
_08096232:
	movs r0, #0
	str r0, [r5]
	ldr r0, [r4, #0x68]
	str r0, [r4, #0x60]
	b _080962B4
	.align 2, 0
_0809623C: .4byte 0x0836A0BC
_08096240:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _080962B4
	ldr r0, [r4, #0x54]
	ldr r1, _080962D4 @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	cmp r0, #0
	blt _080962B4
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	cmp r0, #0
	blt _080962B4
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809627C
	str r1, [r4, #0x60]
_0809627C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _080962D8 @ =0xFFFFF800
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809629A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0809629A:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080962B4
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080962B4:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080962DC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080962CA
	movs r1, #0
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080962CA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080962D4: .4byte 0xFFFFF600
_080962D8: .4byte 0xFFFFF800
_080962DC: .4byte 0x00020001

	thumb_func_start Shellcrawler_Die
Shellcrawler_Die: @ 0x080962E0
	push {lr}
	adds r3, r0, #0
	ldr r0, _08096328 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08096330
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
	ldr r1, _0809632C @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _08096340
	.align 2, 0
_08096328: .4byte gCurStory
_0809632C: .4byte gEnemyFnTable
_08096330:
	ldr r0, _08096344 @ =0x0836A264
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_08096340:
	pop {r0}
	bx r0
	.align 2, 0
_08096344: .4byte 0x0836A264

	thumb_func_start FUN_08096348
FUN_08096348: @ 0x08096348
	push {r4, lr}
	ldr r4, [r0, #0x2c]
	adds r3, r4, #0
	adds r3, #0xb4
	ldr r1, _08096370 @ =pZero2
	ldr r1, [r1]
	ldr r1, [r1, #0x54]
	ldr r2, [r4, #0x54]
	subs r1, r1, r2
	str r1, [r3]
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809642E
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _08096374
	ldr r4, [r4, #0x28]
	b _08096384
	.align 2, 0
_08096370: .4byte pZero2
_08096374:
	ldrb r1, [r4, #0xd]
	subs r0, r1, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0809642E
	cmp r1, #8
	beq _0809642E
_08096384:
	adds r1, r4, #0
	adds r1, #0xbc
	ldrb r2, [r1]
	cmp r2, #0
	bne _0809642E
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	beq _080963D2
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _080963D2
	str r2, [r4, #0x2c]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	movs r0, #0x8c
	str r2, [r0]
	movs r0, #0x90
	str r2, [r0]
	movs r0, #0x94
	strb r2, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _08096404 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_080963D2:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0x10]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	ldr r1, _08096408 @ =0x0000DB08
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, #0
	bne _08096410
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809640C @ =0x0836A0BC
	bl SetDDP
	b _0809641A
	.align 2, 0
_08096404: .4byte gEnemyFnTable
_08096408: .4byte 0x0000DB08
_0809640C: .4byte 0x0836A0BC
_08096410:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096434 @ =0x0836A1AC
	bl SetDDP
_0809641A:
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08096428
	movs r1, #1
_08096428:
	adds r0, r4, #0
	bl FUN_080c6934
_0809642E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096434: .4byte 0x0836A1AC

	thumb_func_start FUN_08096438
FUN_08096438: @ 0x08096438
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08095d80
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809644C
	movs r0, #1
	b _0809645E
_0809644C:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08096462
	movs r1, #0
	movs r0, #5
_0809645E:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08096462:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08096468
FUN_08096468: @ 0x08096468
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08095d80
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809647E
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809647E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08096484
FUN_08096484: @ 0x08096484
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08095d80
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809649A
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809649A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080964B8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080964B0
	movs r1, #0
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080964B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080964B8: .4byte 0x00020001

	thumb_func_start FUN_080964bc
FUN_080964bc:
	bx lr

	thumb_func_start FUN_080964c0
FUN_080964c0: @ 0x080964C0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080964F8
	cmp r0, #1
	bgt _080964D4
	cmp r0, #0
	beq _080964DA
	b _08096568
_080964D4:
	cmp r0, #2
	beq _0809652A
	b _08096568
_080964DA:
	movs r0, #0x60
	strb r0, [r4, #0x12]
	subs r0, #0xa0
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080964F0
	movs r2, #0x40
_080964F0:
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080964F8:
	ldr r0, [r4, #0x5c]
	lsrs r2, r0, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0809650C
	cmp r2, #0
	beq _08096510
	b _0809651C
_0809650C:
	cmp r2, #0
	beq _0809651C
_08096510:
	movs r1, #0xdb
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	b _08096524
_0809651C:
	ldr r1, _08096540 @ =0x0000DB02
	adds r0, r4, #0
	bl SetMotion
_08096524:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809652A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08096544
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08096568
	.align 2, 0
_08096540: .4byte 0x0000DB02
_08096544:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_08095e28
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096562
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #1
	strb r0, [r4, #0xe]
_08096562:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08096568:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08096570
FUN_08096570:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28, 0x1F, 0xD0, 0x40, 0xE0
	.byte 0x20, 0x66, 0x20, 0x7C, 0x00, 0x28, 0x09, 0xD1, 0xE0, 0x6D, 0x00, 0x28, 0x02, 0xDA, 0xDB, 0x21
	.byte 0x09, 0x02, 0x07, 0xE0, 0x00, 0x49, 0x05, 0xE0, 0x02, 0xDB, 0x00, 0x00, 0xE0, 0x6D, 0x00, 0x28
	.byte 0x06, 0xDA, 0x02, 0x49, 0x20, 0x1C, 0x80, 0xF7, 0xDF, 0xFF, 0x05, 0xE0, 0x0F, 0xDB, 0x00, 0x00
	.byte 0x15, 0x49, 0x20, 0x1C, 0x80, 0xF7, 0xD8, 0xFF, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xA0, 0x6D
	.byte 0x21, 0x6E, 0x40, 0x18, 0xA0, 0x65, 0x40, 0x31, 0x21, 0x66, 0xE0, 0x20, 0xC0, 0x00, 0x81, 0x42
	.byte 0x00, 0xDD, 0x20, 0x66, 0x60, 0x6D, 0xE1, 0x6D, 0x40, 0x18, 0x60, 0x65, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x23, 0xFC, 0x20, 0x1C, 0xFF, 0xF7, 0xF0, 0xFB, 0x00, 0x06, 0x00, 0x28, 0x06, 0xD0, 0x20, 0x7C
	.byte 0x00, 0x28, 0x00, 0xD0, 0x06, 0x20, 0x60, 0x73, 0x01, 0x20, 0xA0, 0x73, 0x20, 0x1C, 0x81, 0xF7
	.byte 0x2D, 0xF8, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x05, 0xDB, 0x00, 0x00

	thumb_func_start FUN_0809660c
FUN_0809660c: @ 0x0809660C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809661C
	cmp r0, #1
	beq _0809662A
	b _08096640
_0809661C:
	ldr r1, _08096648 @ =0x0000DB03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809662A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08096640
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_08096640:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096648: .4byte 0x0000DB03

	thumb_func_start FUN_0809664c
FUN_0809664c: @ 0x0809664C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809665C
	cmp r5, #1
	beq _080966BC
	b _080966E2
_0809665C:
	ldr r0, _080966E8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _0809669E
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080966EC @ =gEnemyFnTable
	movs r1, #0x41
	strb r1, [r2, #9]
	adds r1, #0xc3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r0, #0
	strh r5, [r2, #0x20]
	adds r1, r2, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r2, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #4
	strb r0, [r2, #0x10]
	str r4, [r2, #0x28]
_0809669E:
	str r2, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080966F0 @ =0x0836A14C
	bl SetDDP
	ldr r1, _080966F4 @ =0x0000DB0E
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080966BC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bne _080966D0
	ldr r0, _080966F8 @ =0x00000107
	bl PlaySound
_080966D0:
	ldrb r1, [r4, #0x12]
	cmp r1, #0
	bne _080966DC
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080966DC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080966E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080966E8: .4byte gZakoHeaderPtr
_080966EC: .4byte gEnemyFnTable
_080966F0: .4byte 0x0836A14C
_080966F4: .4byte 0x0000DB0E
_080966F8: .4byte 0x00000107

	thumb_func_start FUN_080966fc
FUN_080966fc: @ 0x080966FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809670C
	cmp r0, #1
	beq _0809671A
	b _0809677A
_0809670C:
	ldr r1, _08096780 @ =0x0000DB10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809671A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r5, [r0]
	cmp r5, #3
	bne _0809677A
	adds r0, #1
	ldr r1, _08096784 @ =0x0836A08C
	bl SetDDP
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _0809676E
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
	ldr r1, _08096788 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	str r2, [r4, #0x2c]
_0809676E:
	movs r0, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0x60
	strb r0, [r4, #0x12]
_0809677A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096780: .4byte 0x0000DB10
_08096784: .4byte 0x0836A08C
_08096788: .4byte gEnemyFnTable

	thumb_func_start FUN_0809678c
FUN_0809678c: @ 0x0809678C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809679C
	cmp r0, #1
	beq _080967C8
	b _08096804
_0809679C:
	ldr r1, _0809680C @ =0x0000DB01
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	str r0, [r4, #0x64]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _080967BC
	ldr r1, _08096810 @ =0xFFFFFF00
_080967BC:
	str r1, [r4, #0x5c]
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080967C8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_08095e28
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _080967E0
	subs r0, #1
	strb r0, [r4, #0x12]
_080967E0:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080967FE
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080967F8
	movs r0, #6
_080967F8:
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_080967FE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08096804:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809680C: .4byte 0x0000DB01
_08096810: .4byte 0xFFFFFF00

	thumb_func_start FUN_08096814
FUN_08096814: @ 0x08096814
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #1
	beq _08096866
	cmp r1, #1
	bgt _0809682A
	cmp r1, #0
	beq _08096830
	b _08096936
_0809682A:
	cmp r1, #2
	beq _0809688A
	b _08096936
_08096830:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	movs r0, #6
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0xbd
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	beq _08096852
	subs r1, #2
_08096852:
	str r1, [r5, #0x5c]
	str r2, [r5, #0x64]
	movs r1, #0x10
	cmp r0, #0
	beq _0809685E
	subs r1, #0x20
_0809685E:
	str r1, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096866:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _0809687C
	ldr r1, _08096878 @ =0x0000DB0F
	adds r0, r5, #0
	bl SetMotion
	b _08096884
	.align 2, 0
_08096878: .4byte 0x0000DB0F
_0809687C:
	ldr r1, _08096898 @ =0x0000DB05
	adds r0, r5, #0
	bl SetMotion
_08096884:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809688A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809689C
	subs r0, #1
	strb r0, [r5, #0x12]
	b _080968FE
	.align 2, 0
_08096898: .4byte 0x0000DB05
_0809689C:
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080968FE
	movs r0, #6
	strb r0, [r5, #0x13]
	adds r1, r5, #0
	adds r1, #0xbd
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080968C6
	strb r2, [r1]
	movs r0, #0x3c
	strb r0, [r5, #0x12]
_080968C6:
	ldrb r4, [r5, #0xa]
	lsrs r4, r4, #4
	movs r0, #1
	ands r4, r0
	ldr r1, [r5, #0x54]
	ldr r0, _08096940 @ =0xFFFFF400
	adds r1, r1, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #0xb
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08096944 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	ldr r1, _08096948 @ =0xFFFFFD00
	lsls r4, r4, #7
	subs r4, #0x80
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r0, sp
	adds r2, r4, #0
	bl CreateLemon
_080968FE:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r2, r1, #0
	cmp r1, #0
	bge _0809690E
	rsbs r2, r1, #0
_0809690E:
	ldr r0, _0809694C @ =0x0000013F
	cmp r2, r0
	bgt _0809691A
	ldr r0, [r5, #0x64]
	adds r0, r1, r0
	str r0, [r5, #0x5c]
_0809691A:
	adds r0, r5, #0
	bl FUN_08095e28
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096930
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	movs r0, #1
	strb r0, [r5, #0xe]
_08096930:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08096936:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096940: .4byte 0xFFFFF400
_08096944: .4byte 0xFFFFF600
_08096948: .4byte 0xFFFFFD00
_0809694C: .4byte 0x0000013F

	thumb_func_start FUN_08096950
FUN_08096950: @ 0x08096950
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08096960
	cmp r0, #1
	beq _0809698C
	b _080969C2
_08096960:
	ldr r1, _080969C8 @ =0x0000DB08
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	str r0, [r4, #0x64]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08096980
	ldr r1, _080969CC @ =0xFFFFFF00
_08096980:
	str r1, [r4, #0x5c]
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809698C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_08095e28
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _080969A4
	subs r0, #1
	strb r0, [r4, #0x12]
_080969A4:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080969BC
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x5c]
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080969BC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080969C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080969C8: .4byte 0x0000DB08
_080969CC: .4byte 0xFFFFFF00

	thumb_func_start FUN_080969d0
FUN_080969d0: @ 0x080969D0
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08096A08
	cmp r0, #1
	bgt _080969E6
	cmp r0, #0
	beq _080969F0
	b _08096A7A
_080969E6:
	cmp r0, #2
	beq _08096A20
	cmp r0, #3
	beq _08096A2A
	b _08096A7A
_080969F0:
	ldr r1, _08096A1C @ =0x0000DB04
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08096A08:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08096A7A
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08096A78
	.align 2, 0
_08096A1C: .4byte 0x0000DB04
_08096A20:
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096A2A:
	ldrb r0, [r4, #0x12]
	cmp r0, #2
	bne _08096A5C
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	ldr r1, [r4, #0x54]
	ldr r0, _08096A84 @ =0xFFFFF000
	adds r1, r1, r0
	lsls r0, r2, #0xd
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08096A88 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #9
	ldr r0, _08096A8C @ =0xFFFFFD00
	adds r1, r1, r0
	mov r0, sp
	bl FUN_080b145c
_08096A5C:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08096A7A
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #0
_08096A78:
	strb r0, [r4, #0xe]
_08096A7A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096A84: .4byte 0xFFFFF000
_08096A88: .4byte 0xFFFFF600
_08096A8C: .4byte 0xFFFFFD00

	thumb_func_start FUN_08096a90
FUN_08096a90: @ 0x08096A90
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r0, _08096AE0 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08096AE8
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
	ldr r1, _08096AE4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08096B7A
	.align 2, 0
_08096AE0: .4byte gCurStory
_08096AE4: .4byte gEnemyFnTable
_08096AE8:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _08096B22
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _08096B30 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08096B22:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08096B34
	cmp r0, #1
	beq _08096B4C
	b _08096B7A
	.align 2, 0
_08096B30: .4byte gEnemyFnTable
_08096B34:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096B64 @ =0x0836A08C
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096B4C:
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, #0
	bne _08096B68
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096B64 @ =0x0836A08C
	bl SetDDP
	b _08096B72
	.align 2, 0
_08096B64: .4byte 0x0836A08C
_08096B68:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096B80 @ =0x0836A1DC
	bl SetDDP
_08096B72:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
_08096B7A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096B80: .4byte 0x0836A1DC

	thumb_func_start FUN_08096b84
FUN_08096b84: @ 0x08096B84
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _08096B96
	cmp r2, #1
	beq _08096BBA
	b _08096C10
_08096B96:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
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
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096BBA:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08096C18 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c68cc
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08096C1C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08096C20 @ =0x0000270E
	cmp r1, r0
	bhi _08096BF6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08096BF6:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08096C24 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_08096C10:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096C18: .4byte 0xFFFFF800
_08096C1C: .4byte gMission
_08096C20: .4byte 0x0000270E
_08096C24: .4byte gEnemyFnTable

	thumb_func_start FUN_08096c28
FUN_08096c28: @ 0x08096C28
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08096CC4
	cmp r0, #1
	bgt _08096C3E
	cmp r0, #0
	beq _08096C46
	b _08096D76
_08096C3E:
	cmp r0, #2
	bne _08096C44
	b _08096D50
_08096C44:
	b _08096D76
_08096C46:
	adds r1, r5, #0
	adds r1, #0xbc
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0xb4
	cmp r0, #0
	bne _08096C68
	movs r0, #1
	strb r0, [r1]
	movs r1, #0
	ldr r0, [r4]
	cmp r0, #0
	ble _08096C62
	movs r1, #1
_08096C62:
	adds r0, r5, #0
	bl FUN_080c6934
_08096C68:
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08096D40 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r6, #0
	ldr r0, [r4]
	cmp r0, #0
	ble _08096C7E
	movs r6, #1
_08096C7E:
	movs r4, #0x80
	lsls r4, r4, #2
	movs r0, #0
	mov r1, sp
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080b2b40
	ldr r1, _08096D44 @ =0x0000DB09
	adds r0, r5, #0
	bl SetMotion
	lsls r0, r6, #0xa
	subs r4, r4, r0
	str r4, [r5, #0x5c]
	movs r1, #0
	movs r0, #0x14
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl FUN_080c6880
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096CC4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08096CD8
	adds r0, #0xff
_08096CD8:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08095e28
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08096D38
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08096D40 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #2
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _08096D48 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08096D4C @ =0x0000270E
	cmp r1, r0
	bhi _08096D2A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08096D2A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096D38:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08096D76
	.align 2, 0
_08096D40: .4byte 0xFFFFF800
_08096D44: .4byte 0x0000DB09
_08096D48: .4byte gMission
_08096D4C: .4byte 0x0000270E
_08096D50:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08096D64
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08096D76
_08096D64:
	ldr r1, _08096D80 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_08096D76:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096D80: .4byte gEnemyFnTable

	thumb_func_start FUN_08096d84
FUN_08096d84: @ 0x08096D84
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #1
	beq _08096DE0
	cmp r1, #1
	bgt _08096D9A
	cmp r1, #0
	beq _08096DA0
	b _08096E9E
_08096D9A:
	cmp r1, #2
	beq _08096E78
	b _08096E9E
_08096DA0:
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
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08096DC4
	movs r2, #1
_08096DC4:
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #8
	movs r0, #0xa0
	lsls r0, r0, #2
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _08096E6C @ =0xFFFFFB80
	str r0, [r4, #0x60]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096DE0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _08096DFE
	str r0, [r4, #0x60]
_08096DFE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096E1E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08096E9E
_08096E1E:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c68cc
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08096E70 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08096E74 @ =0x0000270E
	cmp r1, r0
	bhi _08096E5C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08096E5C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08096E9E
	.align 2, 0
_08096E6C: .4byte 0xFFFFFB80
_08096E70: .4byte gMission
_08096E74: .4byte 0x0000270E
_08096E78:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08096E8C
	subs r0, #1
	strb r0, [r4, #0x12]
	b _08096E9E
_08096E8C:
	ldr r1, _08096EA8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_08096E9E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096EA8: .4byte gEnemyFnTable

	thumb_func_start FUN_08096eac
FUN_08096eac: @ 0x08096EAC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08096EBC
	cmp r0, #1
	beq _08096F6A
	b _08096FAA
_08096EBC:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08096ED8 @ =0x0836A17C
	bl SetDDP
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _08096EE0
	ldr r1, _08096EDC @ =0x0000DB04
	adds r0, r5, #0
	bl SetMotion
	b _08096EE8
	.align 2, 0
_08096ED8: .4byte 0x0836A17C
_08096EDC: .4byte 0x0000DB04
_08096EE0:
	ldr r1, _08096F50 @ =0x0000DB0F
	adds r0, r5, #0
	bl SetMotion
_08096EE8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _08096F54 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08096F58 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
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
	cmp r6, #0
	beq _08096F5C
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
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08096F64
	.align 2, 0
_08096F50: .4byte 0x0000DB0F
_08096F54: .4byte pZero2
_08096F58: .4byte 0xFFFFE800
_08096F5C:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08096F64:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096F6A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08096F82
	str r1, [r5, #0x60]
_08096F82:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08096FA4
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08096FAA
_08096FA4:
	adds r0, r5, #0
	bl FUN_08096b84
_08096FAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
