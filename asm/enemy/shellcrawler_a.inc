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
	ldr r0, _08095F60 @ =gSystemSavedata
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
_08095F60: .4byte gSystemSavedata
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
	ldr r0, _080960AC @ =Coord_080ff05c
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
_080960AC: .4byte Coord_080ff05c
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
	bl Camera_GetDistance
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
	bl IsFrozen
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
	bl UpdateEntityAnim
	movs r0, #2
	strb r0, [r4, #0xf]
_080961AE:
	adds r0, r4, #0
	bl IsFrozen
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
	bl IsFrozen
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
