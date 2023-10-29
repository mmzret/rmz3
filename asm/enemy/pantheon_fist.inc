	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createPantheonFistInElevator
createPantheonFistInElevator: @ 0x08094F40
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08094FA0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08094F96
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08094FA4 @ =gEnemyFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r4, [r0]
_08094F96:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094FA0: .4byte gZakoHeaderPtr
_08094FA4: .4byte gEnemyFnTable

	thumb_func_start FUN_08094fa8
FUN_08094fa8: @ 0x08094FA8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	ldr r3, _08094FD4 @ =0xFFFFF200
	adds r0, r0, r3
	cmp r1, #0
	ble _08094FBC
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
_08094FBC:
	ldr r1, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08094FD8
	movs r0, #0
	b _08094FDA
	.align 2, 0
_08094FD4: .4byte 0xFFFFF200
_08094FD8:
	movs r0, #1
_08094FDA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08094fe0
FUN_08094fe0: @ 0x08094FE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _0809500C
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08095008 @ =0x000007FF
	cmp r1, r0
	bgt _0809500C
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _0809500E
	.align 2, 0
_08095008: .4byte 0x000007FF
_0809500C:
	movs r0, #0
_0809500E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08095014
FUN_08095014: @ 0x08095014
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _0809506A
	cmp r5, #0
	bge _08095044
	ldr r0, [r4, #0x54]
	ldr r1, _0809503C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095040 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #1
	b _0809506C
	.align 2, 0
_0809503C: .4byte 0xFFFFF200
_08095040: .4byte 0xFFFFF600
_08095044:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095060 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #2
	b _0809506C
	.align 2, 0
_08095060: .4byte 0xFFFFF600
_08095064:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809506A:
	movs r0, #0
_0809506C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08095074
FUN_08095074: @ 0x08095074
	push {lr}
	adds r2, r0, #0
	cmp r1, #0
	beq _080950C4
	cmp r1, #0
	bge _080950A4
	ldr r0, [r2, #0x54]
	ldr r1, _0809509C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950A0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #1
	b _080950C6
	.align 2, 0
_0809509C: .4byte 0xFFFFF200
_080950A0: .4byte 0xFFFFF600
_080950A4:
	ldr r0, [r2, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950C0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #2
	b _080950C6
	.align 2, 0
_080950C0: .4byte 0xFFFFF600
_080950C4:
	movs r0, #0
_080950C6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_080950cc
nop_080950cc: @ 0x080950CC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080950d0
FUN_080950d0: @ 0x080950D0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809511C
	ldr r1, _08095110 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08095114
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08095116
	strb r4, [r2, #0xd]
	b _08095118
	.align 2, 0
_08095110: .4byte gEnemyFnTable
_08095114:
	movs r0, #1
_08095116:
	strb r0, [r2, #0xd]
_08095118:
	movs r0, #1
	b _0809511E
_0809511C:
	movs r0, #0
_0809511E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08095124
FUN_08095124: @ 0x08095124
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _080951AA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _080951AA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08095144
	cmp r0, #1
	beq _08095188
	b _080951AA
_08095144:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080951AA
	ldr r1, _08095180 @ =0x08369F80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08095184 @ =0x08369FA4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809517A:
	movs r0, #1
	b _080951AC
	.align 2, 0
_08095180: .4byte 0x08369F80
_08095184: .4byte 0x08369FA4
_08095188:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080951A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080951A4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0809517A
	strb r5, [r4, #0xf]
	b _080951AA
	.align 2, 0
_080951A4: .4byte 0x00020001
_080951A8:
	strb r0, [r4, #0xf]
_080951AA:
	movs r0, #0
_080951AC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080951b4
FUN_080951b4: @ 0x080951B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _080951F4
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080951F4
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _080951E0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080951F4
_080951E0:
	ldr r2, _080951FC @ =0x0836A064
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _080951F4
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080951F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080951FC: .4byte 0x0836A064

	thumb_func_start PantheonFist_Init
PantheonFist_Init: @ 0x08095200
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0x10]
	cmp r1, #1
	bne _08095212
	movs r0, #0
	strb r0, [r5, #0x10]
	strb r1, [r5, #0x11]
	b _08095216
_08095212:
	movs r0, #0
	strb r0, [r5, #0x11]
_08095216:
	ldr r1, _0809527C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08095280 @ =0x0836A06C
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08095284 @ =0x08369FD4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08095288 @ =nop_080950cc
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xb4
	str r6, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _0809528C
	adds r0, r5, #0
	adds r0, #0xb8
	strb r6, [r0]
	b _0809529E
	.align 2, 0
_0809527C: .4byte gEnemyFnTable
_08095280: .4byte 0x0836A06C
_08095284: .4byte 0x08369FD4
_08095288: .4byte nop_080950cc
_0809528C:
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
_0809529E:
	movs r2, #0
	ldr r0, _080952BC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080952AE
	movs r2, #1
_080952AE:
	cmp r2, #0
	beq _080952C0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080952C6
	.align 2, 0
_080952BC: .4byte pZero2
_080952C0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080952C6:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
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
	adds r0, r5, #0
	bl PantheonFist_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start PantheonFist_Update
PantheonFist_Update: @ 0x080952F0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080950d0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095330
	adds r0, r4, #0
	bl FUN_080951b4
	adds r0, r4, #0
	bl FUN_08095124
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095330
	ldr r1, _08095338 @ =0x08369F80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809533C @ =0x08369FA4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08095330:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095338: .4byte 0x08369F80
_0809533C: .4byte 0x08369FA4

	thumb_func_start PantheonFist_Die
PantheonFist_Die: @ 0x08095340
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x11]
	cmp r3, #0
	bne _08095394
	ldr r0, _0809538C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08095394
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _08095390 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _080953A4
	.align 2, 0
_0809538C: .4byte gCurStory
_08095390: .4byte gEnemyFnTable
_08095394:
	ldr r0, _080953A8 @ =0x08369FC8
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080953A4:
	pop {r0}
	bx r0
	.align 2, 0
_080953A8: .4byte 0x08369FC8

	thumb_func_start FUN_080953ac
FUN_080953ac:
	bx lr

	thumb_func_start FUN_080953b0
FUN_080953b0: @ 0x080953B0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080953CC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080953C8
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080953C8:
	pop {r0}
	bx r0
	.align 2, 0
_080953CC: .4byte 0x00020001

	thumb_func_start FUN_080953d0
FUN_080953d0: @ 0x080953D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _080953E6
	bl isKilled
	cmp r0, #0
	beq _08095406
_080953E6:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095424 @ =0x08369FEC
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08095406
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08095406:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08095428 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0809541C
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809541C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08095424: .4byte 0x08369FEC
_08095428: .4byte 0x00020001

	thumb_func_start FUN_0809542c
FUN_0809542c: @ 0x0809542C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809543C
	cmp r5, #1
	beq _08095456
	b _08095494
_0809543C:
	ldr r1, _0809549C @ =0x0000D406
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080954A0 @ =0x0836A004
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095456:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _0809548E
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08095472
	str r1, [r4, #0x60]
_08095472:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809548E
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_0809548E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08095494:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809549C: .4byte 0x0000D406
_080954A0: .4byte 0x0836A004

	thumb_func_start FUN_080954a4
FUN_080954a4: @ 0x080954A4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080954B4
	cmp r0, #1
	beq _080954D2
	b _08095572
_080954B4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080954F8 @ =0x08369FEC
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	movs r1, #0xd4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080954D2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldr r0, _080954FC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080954E8
	movs r2, #1
_080954E8:
	adds r5, r2, #0
	cmp r5, #0
	beq _08095500
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08095506
	.align 2, 0
_080954F8: .4byte 0x08369FEC
_080954FC: .4byte pZero2
_08095500:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08095506:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809555C
	lsls r0, r5, #1
	subs r5, r0, #1
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08095074
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08095550
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095556
_08095550:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _0809555C
_08095556:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0809555C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08095572
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08095572:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08095578
FUN_08095578: @ 0x08095578
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080955A8
	cmp r5, #1
	bgt _0809558C
	cmp r5, #0
	beq _08095596
	b _0809565E
_0809558C:
	cmp r5, #2
	beq _08095614
	cmp r5, #3
	beq _08095622
	b _0809565E
_08095596:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095610 @ =0x08369FEC
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080955A8:
	movs r1, #0xd4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #2
	bne _080955D6
	ldr r3, [r4, #0x54]
	adds r0, r3, #0
	subs r0, #0x80
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080955D4
	adds r2, r3, #0
	adds r2, #0x80
_080955D4:
	str r2, [r4, #0x54]
_080955D6:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080955E6
	str r1, [r4, #0x60]
_080955E6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08095606
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095606:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0809565E
	.align 2, 0
_08095610: .4byte 0x08369FEC
_08095614:
	ldr r1, _08095644 @ =0x0000D401
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095622:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _08095656
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	cmp r0, #0
	bne _08095648
	movs r0, #1
	strb r0, [r1]
	movs r0, #8
	b _08095650
	.align 2, 0
_08095644: .4byte 0x0000D401
_08095648:
	cmp r0, #2
	bne _0809564E
	strb r2, [r1]
_0809564E:
	movs r0, #1
_08095650:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08095656:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
_0809565E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08095664
FUN_08095664: @ 0x08095664
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095674
	cmp r0, #1
	beq _080956B8
	b _0809576E
_08095674:
	movs r2, #0
	ldr r0, _0809569C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08095684
	movs r2, #1
_08095684:
	lsls r1, r2, #8
	subs r1, #0x80
	adds r0, r4, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080956A0
	movs r0, #1
	b _0809576A
	.align 2, 0
_0809569C: .4byte pZero2
_080956A0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080956DC @ =0x08369FEC
	bl SetDDP
	ldr r1, _080956E0 @ =0x0000D402
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080956B8:
	movs r3, #0
	ldr r1, _080956E4 @ =pZero2
	ldr r0, [r1]
	ldr r2, [r4, #0x54]
	ldr r0, [r0, #0x54]
	mov ip, r1
	cmp r2, r0
	bge _080956CA
	movs r3, #1
_080956CA:
	adds r5, r3, #0
	adds r2, r5, #0
	cmp r5, #0
	beq _080956E8
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080956EE
	.align 2, 0
_080956DC: .4byte 0x08369FEC
_080956E0: .4byte 0x0000D402
_080956E4: .4byte pZero2
_080956E8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080956EE:
	strb r0, [r4, #0xa]
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r6, #0
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	mov r1, ip
	ldr r0, [r1]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, _08095774 @ =0x000063FF
	cmp r0, r1
	bhi _0809572C
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0809572C:
	lsls r0, r5, #8
	adds r5, r0, #0
	subs r5, #0x80
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809574E
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08095014
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08095752
_0809574E:
	strb r7, [r4, #0xd]
	strb r6, [r4, #0xe]
_08095752:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809576E
	movs r0, #2
_0809576A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809576E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08095774: .4byte 0x000063FF

	thumb_func_start FUN_08095778
FUN_08095778: @ 0x08095778
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095788
	cmp r0, #1
	beq _080957A4
	b _080957C6
_08095788:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080957CC @ =0x08369FEC
	bl SetDDP
	ldr r1, _080957D0 @ =0x0000D403
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080957A4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080957BE
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080957BE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
_080957C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080957CC: .4byte 0x08369FEC
_080957D0: .4byte 0x0000D403

	thumb_func_start FUN_080957d4
FUN_080957d4: @ 0x080957D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080957E8
	cmp r0, #1
	beq _0809583E
	b _08095900
_080957E8:
	ldr r0, _08095820 @ =0x00000109
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08095824 @ =0x0836A01C
	bl SetDDP
	movs r4, #0x10
	str r4, [r5, #0x64]
	movs r0, #0xa0
	lsls r0, r0, #3
	bl Sqrt
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	ldr r2, [r5, #0x64]
	adds r1, r0, #0
	muls r1, r2, r1
	str r1, [r5, #0x5c]
	ldrb r0, [r5, #0xa]
	ands r4, r0
	cmp r4, #0
	bne _08095828
	rsbs r0, r1, #0
	str r0, [r5, #0x5c]
	b _0809582C
	.align 2, 0
_08095820: .4byte 0x00000109
_08095824: .4byte 0x0836A01C
_08095828:
	rsbs r0, r2, #0
	str r0, [r5, #0x64]
_0809582C:
	movs r0, #0
	strb r0, [r5, #0x13]
	ldr r1, _0809590C @ =0x0000D404
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809583E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r7, _08095910 @ =pZero2
	ldr r0, [r7]
	adds r0, #0x8c
	ldr r0, [r0]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	beq _0809588C
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	mov r8, r1
	ands r0, r1
	cmp r0, #0
	beq _0809588C
	ldrb r0, [r5, #0x12]
	cmp r0, #0x10
	bls _0809588C
	ldrb r4, [r5, #0x13]
	cmp r4, #0
	bne _0809588C
	movs r0, #0x52
	bl PlaySound
	strb r6, [r5, #0x13]
	ldr r0, [r7]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r7]
	mov r1, r8
	strb r1, [r0, #0xd]
	ldr r0, [r7]
	strb r4, [r0, #0xe]
_0809588C:
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080958B2
	cmp r1, #8
	bls _080958B2
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
_080958B2:
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080958D4
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080958D4
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08095014
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080958DC
_080958D4:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080958DC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080958F8
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080958F8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08094fe0
_08095900:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809590C: .4byte 0x0000D404
_08095910: .4byte pZero2

	thumb_func_start FUN_08095914
FUN_08095914: @ 0x08095914
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095924
	cmp r0, #1
	beq _0809593C
	b _0809595C
_08095924:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095964 @ =0x08369FEC
	bl SetDDP
	ldr r1, _08095968 @ =0x0000D405
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809593C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08095954
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08095954:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
_0809595C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095964: .4byte 0x08369FEC
_08095968: .4byte 0x0000D405

	thumb_func_start FUN_0809596c
FUN_0809596c: @ 0x0809596C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809597C
	cmp r0, #1
	beq _08095A12
	b _08095AB6
_0809597C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080959F4 @ =0x0836A04C
	bl SetDDP
	ldr r1, _080959F8 @ =0x0000D406
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080959FC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08095A00 @ =0xFFFFE800
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
	beq _08095A04
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
	b _08095A0C
	.align 2, 0
_080959F4: .4byte 0x0836A04C
_080959F8: .4byte 0x0000D406
_080959FC: .4byte pZero2
_08095A00: .4byte 0xFFFFE800
_08095A04:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08095A0C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08095A12:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08095014
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095A34
	adds r6, r5, #0
	adds r6, #0x8c
	ldr r4, [r6]
	movs r0, #4
	ands r4, r0
	cmp r4, #0
	beq _08095A3C
_08095A34:
	adds r0, r5, #0
	bl FUN_08095b70
	b _08095AB6
_08095A3C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08095A4C
	str r1, [r5, #0x60]
_08095A4C:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08095A6C
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl FUN_08095b70
_08095A6C:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _08095AB6
	ldr r0, _08095ABC @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _08095AB6
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r4, [r6]
	adds r0, r5, #0
	adds r0, #0x90
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08095AC0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_08095AB6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095ABC: .4byte gStageRun+232
_08095AC0: .4byte gEnemyFnTable

	thumb_func_start FUN_08095ac4
FUN_08095ac4: @ 0x08095AC4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095AD4
	cmp r0, #1
	beq _08095B3E
	b _08095B68
_08095AD4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095B00 @ =0x08369FEC
	bl SetDDP
	ldr r1, _08095B04 @ =0x0000D402
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xb9
	ldrb r1, [r2]
	movs r0, #1
	adds r3, r0, #0
	eors r3, r1
	adds r5, r2, #0
	cmp r3, #0
	beq _08095B08
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08095B0E
	.align 2, 0
_08095B00: .4byte 0x08369FEC
_08095B04: .4byte 0x0000D402
_08095B08:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08095B0E:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r3
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0x80
	str r1, [r4, #0x5c]
	ldrb r0, [r5]
	lsls r0, r0, #8
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095B3E:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08095014
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08095B68
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_08095B68:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08095b70
FUN_08095b70: @ 0x08095B70
	push {r4, r5, lr}
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
	ldr r1, _08095BC0 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08095BC8
	ldr r2, _08095BC4 @ =0x0836A06E
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	b _08095BD4
	.align 2, 0
_08095BC0: .4byte 0xFFFFF000
_08095BC4: .4byte 0x0836A06E
_08095BC8:
	ldr r2, _08095C10 @ =0x0836A06E
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
_08095BD4:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08095C14 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08095C18 @ =0x0000270E
	cmp r1, r0
	bhi _08095BEE
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08095BEE:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08095C1C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08095C10: .4byte 0x0836A06E
_08095C14: .4byte gMission
_08095C18: .4byte 0x0000270E
_08095C1C: .4byte gEnemyFnTable

	thumb_func_start FUN_08095c20
FUN_08095c20: @ 0x08095C20
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08095C34
	cmp r5, #1
	bne _08095C32
	b _08095D34
_08095C32:
	b _08095D72
_08095C34:
	movs r6, #0
	ldr r0, _08095CB8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08095C46
	movs r6, #1
_08095C46:
	ldr r1, _08095CBC @ =0x0000D408
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095CE0
	movs r0, #0x20
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08095CC4
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095CC0 @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b84f4
	b _08095D1A
	.align 2, 0
_08095CB8: .4byte pZero2
_08095CBC: .4byte 0x0000D408
_08095CC0: .4byte 0x0836A074
_08095CC4:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095CDC @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b857c
	b _08095D1A
	.align 2, 0
_08095CDC: .4byte 0x0836A074
_08095CE0:
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08095D04
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095D00 @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	b _08095D1A
	.align 2, 0
_08095D00: .4byte 0x0836A074
_08095D04:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095D7C @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
_08095D1A:
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _08095D22
	adds r0, #3
_08095D22:
	asrs r0, r0, #2
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095D34:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _08095D58
	ldr r0, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08095D50
	str r1, [r4, #0x60]
_08095D50:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08094fe0
_08095D58:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095D72
	adds r0, r4, #0
	bl FUN_08095b70
_08095D72:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095D7C: .4byte 0x0836A074
