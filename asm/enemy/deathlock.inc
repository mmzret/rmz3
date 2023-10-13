	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808d0b0
FUN_0808d0b0: @ 0x0808D0B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0808D104 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808D0FC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808D108 @ =gEnemyFnTable
	movs r1, #0x37
	strb r1, [r3, #9]
	adds r0, #0xdc
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
	strb r4, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
_0808D0FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D104: .4byte gZakoHeaderPtr
_0808D108: .4byte gEnemyFnTable

	thumb_func_start FUN_0808d10c
FUN_0808d10c: @ 0x0808D10C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808D158 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808D152
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808D15C @ =gEnemyFnTable
	movs r1, #0x37
	strb r1, [r3, #9]
	adds r0, #0xdc
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
	movs r0, #9
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
_0808D152:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808D158: .4byte gZakoHeaderPtr
_0808D15C: .4byte gEnemyFnTable

	thumb_func_start FUN_0808d160
FUN_0808d160: @ 0x0808D160
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #0
	bge _0808D1E8
	ldr r4, _0808D1DC @ =0xFFFFEE00
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	str r0, [sp]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D1E0 @ =0xFFFFF100
	adds r1, r1, r2
	bl PushoutToRight1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D1E4 @ =0xFFFFE200
	adds r1, r1, r2
	bl PushoutToRight1
	str r0, [sp, #8]
	movs r0, #0
_0808D19E:
	adds r4, r0, #1
	adds r3, r4, #0
	cmp r4, #2
	bgt _0808D1C4
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r1, r0
	lsls r0, r4, #2
	add r0, sp
_0808D1B0:
	ldr r1, [r5]
	ldr r2, [r0]
	cmp r1, r2
	bge _0808D1BC
	str r2, [r5]
	str r1, [r0]
_0808D1BC:
	adds r0, #4
	adds r3, #1
	cmp r3, #2
	ble _0808D1B0
_0808D1C4:
	adds r0, r4, #0
	cmp r0, #1
	ble _0808D19E
	ldr r1, [sp]
	cmp r1, #0
	ble _0808D25C
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #1
	b _0808D25E
	.align 2, 0
_0808D1DC: .4byte 0xFFFFEE00
_0808D1E0: .4byte 0xFFFFF100
_0808D1E4: .4byte 0xFFFFE200
_0808D1E8:
	movs r4, #0x90
	lsls r4, r4, #5
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	str r0, [sp]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D254 @ =0xFFFFF100
	adds r1, r1, r2
	bl PushoutToLeft1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D258 @ =0xFFFFE200
	adds r1, r1, r2
	bl PushoutToLeft1
	str r0, [sp, #8]
	movs r0, #0
_0808D218:
	adds r4, r0, #1
	adds r3, r4, #0
	cmp r4, #2
	bgt _0808D23E
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r1, r0
	lsls r0, r4, #2
	add r0, sp
_0808D22A:
	ldr r1, [r5]
	ldr r2, [r0]
	cmp r1, r2
	ble _0808D236
	str r2, [r5]
	str r1, [r0]
_0808D236:
	adds r0, #4
	adds r3, #1
	cmp r3, #2
	ble _0808D22A
_0808D23E:
	adds r0, r4, #0
	cmp r0, #1
	ble _0808D218
	ldr r1, [sp]
	cmp r1, #0
	bge _0808D25C
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #2
	b _0808D25E
	.align 2, 0
_0808D254: .4byte 0xFFFFF100
_0808D258: .4byte 0xFFFFE200
_0808D25C:
	movs r0, #0
_0808D25E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808d268
FUN_0808d268: @ 0x0808D268
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [r7, #0x58]
	adds r2, r0, r1
	str r2, [r7, #0x58]
	cmp r1, #0
	bge _0808D2B4
	ldr r0, [r7, #0x54]
	ldr r1, _0808D2AC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r4, _0808D2B0 @ =0xFFFFE200
	adds r1, r2, r4
	bl PushoutToDown1
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl PushoutToDown1
	adds r6, r0, #0
	cmp r5, r6
	bge _0808D29E
	adds r5, r0, #0
_0808D29E:
	cmp r5, #0
	ble _0808D2EC
	ldr r0, [r7, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	movs r0, #1
	b _0808D2EE
	.align 2, 0
_0808D2AC: .4byte 0xFFFFEE00
_0808D2B0: .4byte 0xFFFFE200
_0808D2B4:
	ldr r0, [r7, #0x54]
	ldr r1, _0808D2E8 @ =0xFFFFEE00
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToUp1
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r5, r6
	ble _0808D2D8
	adds r5, r0, #0
_0808D2D8:
	cmp r5, #0
	bge _0808D2EC
	ldr r0, [r7, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	movs r0, #2
	b _0808D2EE
	.align 2, 0
_0808D2E8: .4byte 0xFFFFEE00
_0808D2EC:
	movs r0, #0
_0808D2EE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start nop_0808d2f4
nop_0808d2f4: @ 0x0808D2F4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808d2f8
FUN_0808d2f8: @ 0x0808D2F8
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808D368
	ldr r1, _0808D328 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #9
	bne _0808D32C
	movs r0, #0
	b _0808D35C
	.align 2, 0
_0808D328: .4byte gEnemyFnTable
_0808D32C:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0808D344
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #1
	strb r0, [r1]
	strb r4, [r2, #0xd]
	b _0808D35E
_0808D344:
	adds r0, r2, #0
	adds r0, #0xbb
	strb r1, [r0]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0808D35A
	movs r0, #3
	b _0808D35C
_0808D35A:
	movs r0, #1
_0808D35C:
	strb r0, [r2, #0xd]
_0808D35E:
	adds r0, r2, #0
	bl Deathlock_Die
	movs r0, #1
	b _0808D36A
_0808D368:
	movs r0, #0
_0808D36A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808d370
FUN_0808d370: @ 0x0808D370
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	bne _0808D37C
	b _0808D496
_0808D37C:
	ldrb r0, [r4, #0x10]
	cmp r0, #9
	bne _0808D384
	b _0808D496
_0808D384:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	beq _0808D390
	b _0808D496
_0808D390:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808D39C
	cmp r0, #1
	beq _0808D420
	b _0808D496
_0808D39C:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808D496
	ldr r1, _0808D40C @ =0x08369148
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808D410 @ =0x08369168
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _0808D3FA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808D414 @ =0x0836930C
	adds r5, r4, #0
	adds r5, #0xb9
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D418 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _0808D41C @ =0x08369300
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
_0808D3FA:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808D406:
	movs r0, #1
	b _0808D498
	.align 2, 0
_0808D40C: .4byte 0x08369148
_0808D410: .4byte 0x08369168
_0808D414: .4byte 0x0836930C
_0808D418: .4byte 0x08369198
_0808D41C: .4byte 0x08369300
_0808D420:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808D494
	ldr r0, [r4, #0x54]
	ldr r1, _0808D48C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808D45C
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _0808D462
_0808D45C:
	adds r0, r4, #0
	bl FUN_0808d160
_0808D462:
	ldrb r1, [r4, #0xd]
	cmp r1, #3
	bne _0808D46C
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
_0808D46C:
	ldrb r0, [r4, #0x10]
	cmp r0, #8
	beq _0808D406
	cmp r1, #3
	beq _0808D406
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808D490 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808D406
	movs r0, #0
	strb r0, [r4, #0xf]
	b _0808D498
	.align 2, 0
_0808D48C: .4byte 0xFFFFEE00
_0808D490: .4byte 0x00020001
_0808D494:
	strb r0, [r4, #0xf]
_0808D496:
	movs r0, #0
_0808D498:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808d4a0
FUN_0808d4a0: @ 0x0808D4A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0808D4EE
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0808D4EE
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808D4EE
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _0808D4DA
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0808D4EE
_0808D4DA:
	ldr r2, _0808D4F4 @ =0x08369314
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808D4EE
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808D4EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D4F4: .4byte 0x08369314

	thumb_func_start Deathlock_Init
Deathlock_Init: @ 0x0808D4F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808D524 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0x11]
	ldrb r0, [r6, #0x10]
	cmp r0, #8
	bne _0808D52C
	movs r0, #7
	strb r0, [r6, #0xd]
	ldr r0, [r6, #0x58]
	ldr r1, _0808D528 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _0808D538
	.align 2, 0
_0808D524: .4byte gEnemyFnTable
_0808D528: .4byte 0xFFFFF800
_0808D52C:
	cmp r0, #9
	bne _0808D536
	movs r0, #5
	strb r0, [r6, #0xd]
	b _0808D538
_0808D536:
	strb r1, [r6, #0xd]
_0808D538:
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r1, r0
	movs r0, #1
	movs r4, #0
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #7
	bhi _0808D5C0
	ldr r0, _0808D58C @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808D598
	ldr r0, _0808D590 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0808D598
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D594 @ =0x08369198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xe
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	b _0808D5E0
	.align 2, 0
_0808D58C: .4byte gSystemSavedataManager
_0808D590: .4byte gCurStory
_0808D594: .4byte 0x08369198
_0808D598:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D5BC @ =0x08369198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	b _0808D5E0
	.align 2, 0
_0808D5BC: .4byte 0x08369198
_0808D5C0:
	cmp r0, #9
	bne _0808D5E4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D600 @ =0x08369198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
_0808D5E0:
	ldr r0, _0808D604 @ =nop_0808d2f4
	str r0, [r4, #0x24]
_0808D5E4:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	bhi _0808D608
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	b _0808D618
	.align 2, 0
_0808D600: .4byte 0x08369198
_0808D604: .4byte nop_0808d2f4
_0808D608:
	subs r1, r0, #4
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0808D618
	strb r1, [r6, #0x10]
	movs r0, #1
	strb r0, [r6, #0x11]
_0808D618:
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, r6, #0
	bl Deathlock_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Deathlock_Update
Deathlock_Update: @ 0x0808D638
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #8
	beq _0808D690
	ldr r0, _0808D688 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808D690
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
	ldr r1, _0808D68C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0808D6CE
	.align 2, 0
_0808D688: .4byte gCurStory
_0808D68C: .4byte gEnemyFnTable
_0808D690:
	adds r0, r4, #0
	bl FUN_0808d2f8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808D6CE
	adds r0, r4, #0
	bl FUN_0808d4a0
	adds r0, r4, #0
	bl FUN_0808d370
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808D6CE
	ldr r1, _0808D6D4 @ =0x08369148
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808D6D8 @ =0x08369168
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808D6CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808D6D4: .4byte 0x08369148
_0808D6D8: .4byte 0x08369168

	thumb_func_start Deathlock_Die
Deathlock_Die: @ 0x0808D6DC
	push {lr}
	ldr r2, _0808D6F0 @ =0x08369188
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0808D6F0: .4byte 0x08369188

	thumb_func_start FUN_0808d6f4
FUN_0808d6f4:
	bx lr

	thumb_func_start FUN_0808d6f8
FUN_0808d6f8: @ 0x0808D6F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808D70E
	bl isKilled
	cmp r0, #0
	beq _0808D742
_0808D70E:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808D760 @ =0x0836930C
	adds r1, r4, #0
	adds r1, #0xb9
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D764 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808D742
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808D742:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808D768 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808D758
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808D758:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D760: .4byte 0x0836930C
_0808D764: .4byte 0x08369198
_0808D768: .4byte 0x00020001

	thumb_func_start FUN_0808d76c
FUN_0808d76c: @ 0x0808D76C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808D788 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808D784
	movs r1, #0
	movs r0, #6
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0808D784:
	pop {r0}
	bx r0
	.align 2, 0
_0808D788: .4byte 0x00020001

	thumb_func_start FUN_0808d78c
FUN_0808d78c: @ 0x0808D78C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808D79C
	cmp r5, #1
	beq _0808D7D8
	b _0808D88C
_0808D79C:
	ldr r1, _0808D850 @ =0x08369300
	adds r6, r4, #0
	adds r6, #0xb9
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808D854 @ =0x0836931C
	ldrb r1, [r6]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D858 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808D7D8:
	ldr r0, [r4, #0x54]
	ldr r1, _0808D85C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r5, r0, #0
	cmp r5, #0
	bne _0808D80A
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r5, r0, #0
	cmp r5, #0
	beq _0808D812
_0808D80A:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d160
_0808D812:
	adds r0, r4, #0
	bl isFrozen
	adds r6, r0, #0
	cmp r6, #0
	bne _0808D88C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808d268
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808D860
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808D83C
	str r1, [r4, #0x60]
_0808D83C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808d268
	b _0808D88C
	.align 2, 0
_0808D850: .4byte 0x08369300
_0808D854: .4byte 0x0836931C
_0808D858: .4byte 0x08369198
_0808D85C: .4byte 0xFFFFEE00
_0808D860:
	str r6, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0808D88C
	cmp r5, #0
	bne _0808D88C
	adds r0, r4, #0
	adds r0, #0xbb
	strb r5, [r0]
	adds r0, #1
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0808D894 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_0808D88C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D894: .4byte gEnemyFnTable

	thumb_func_start FUN_0808d898
FUN_0808d898: @ 0x0808D898
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0808D8A8
	cmp r6, #1
	beq _0808D958
	b _0808DA12
_0808D8A8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _0808D8F0 @ =0x0836930C
	adds r4, r5, #0
	adds r4, #0xb9
	ldrb r1, [r4]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D8F4 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _0808D8D0
	cmp r0, #2
	bne _0808D8F8
_0808D8D0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _0808D91A
	.align 2, 0
_0808D8F0: .4byte 0x0836930C
_0808D8F4: .4byte 0x08369198
_0808D8F8:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
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
_0808D91A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808D930
	ldr r0, _0808D92C @ =0x08369300
	ldrb r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	b _0808D938
	.align 2, 0
_0808D92C: .4byte 0x08369300
_0808D930:
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bhi _0808D944
	ldr r1, _0808D940 @ =0x00007402
_0808D938:
	adds r0, r5, #0
	bl SetMotion
	b _0808D94C
	.align 2, 0
_0808D940: .4byte 0x00007402
_0808D944:
	ldr r1, _0808D9CC @ =0x00007401
	adds r0, r5, #0
	bl SetMotion
_0808D94C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808D958:
	ldr r0, [r5, #0x54]
	ldr r1, _0808D9D0 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808D98A
	ldr r0, [r5, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _0808D9A4
_0808D98A:
	adds r0, r5, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808D99E
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808D99E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0808D9A4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808d268
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808D9BA
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808D9BA:
	adds r1, r5, #0
	adds r1, #0xba
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808D9D4
	subs r0, #1
	strb r0, [r1]
	b _0808DA12
	.align 2, 0
_0808D9CC: .4byte 0x00007401
_0808D9D0: .4byte 0xFFFFEE00
_0808D9D4:
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r3, [r0]
	cmp r3, #0
	bne _0808DA12
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bhi _0808DA12
	ldr r0, _0808DA18 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, _0808DA1C @ =0x00008FFF
	cmp r0, r1
	bhi _0808DA12
	ldr r0, [r2, #0x58]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	ldr r1, _0808DA20 @ =0x00003FFF
	cmp r0, r1
	bhi _0808DA12
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r3, [r5, #0xe]
_0808DA12:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808DA18: .4byte pZero2
_0808DA1C: .4byte 0x00008FFF
_0808DA20: .4byte 0x00003FFF

	thumb_func_start FUN_0808da24
FUN_0808da24: @ 0x0808DA24
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808DA34
	cmp r5, #1
	beq _0808DA88
	b _0808DB56
_0808DA34:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808DA6C @ =0x0836930C
	adds r6, r4, #0
	adds r6, #0xb9
	ldrb r1, [r6]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808DA70 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r6]
	cmp r0, #0
	beq _0808DA78
	ldr r0, _0808DA74 @ =0x08369300
	ldrb r1, [r6]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
	b _0808DA82
	.align 2, 0
_0808DA6C: .4byte 0x0836930C
_0808DA70: .4byte 0x08369198
_0808DA74: .4byte 0x08369300
_0808DA78:
	movs r1, #0xe8
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_0808DA82:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DA88:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808DA98
	str r1, [r4, #0x60]
_0808DA98:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_0808d268
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808DB0E
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x54]
	ldr r1, _0808DAE8 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	cmp r0, #0
	bne _0808DADE
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	cmp r0, #0
	beq _0808DAEC
_0808DADE:
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _0808DB0E
	.align 2, 0
_0808DAE8: .4byte 0xFFFFEE00
_0808DAEC:
	adds r1, r4, #0
	adds r1, #0xbb
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0808DB5C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_0808DB0E:
	ldr r0, _0808DB60 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808DB56
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
	ldr r1, _0808DB5C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0808DB56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808DB5C: .4byte gEnemyFnTable
_0808DB60: .4byte gStageRun+232

	thumb_func_start FUN_0808db64
FUN_0808db64: @ 0x0808DB64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0808DB7C
	cmp r0, #1
	beq _0808DBC8
	b _0808DD4E
_0808DB7C:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x64]
	ldr r1, _0808DBA0 @ =0x08369300
	adds r4, r7, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r4]
	cmp r0, #0
	bne _0808DBA4
	movs r0, #8
	b _0808DBA6
	.align 2, 0
_0808DBA0: .4byte 0x08369300
_0808DBA4:
	movs r0, #0x18
_0808DBA6:
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r2, _0808DC14 @ =0x0836930C
	ldrb r1, [r4]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808DC18 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808DBC8:
	ldr r0, [r7, #0x54]
	ldr r1, _0808DC1C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808DBF6
	ldr r0, [r7, #0x54]
	movs r3, #0x90
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
_0808DBF6:
	ldr r0, [r7, #0x64]
	str r0, [r7, #0x54]
	cmp r1, #0
	beq _0808DC0A
	adds r0, r7, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808DC20
_0808DC0A:
	movs r1, #0
	movs r0, #1
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
	b _0808DC40
	.align 2, 0
_0808DC14: .4byte 0x0836930C
_0808DC18: .4byte 0x08369198
_0808DC1C: .4byte 0xFFFFEE00
_0808DC20:
	ldr r2, [r7, #0x54]
	ldr r3, _0808DD5C @ =0xFFFFFE00
	adds r2, r2, r3
	ldr r3, _0808DD60 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _0808DD64 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808DD68 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	str r2, [r7, #0x54]
_0808DC40:
	ldrb r0, [r7, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808DC94
	ldr r1, [r7, #0x54]
	ldr r2, _0808DD6C @ =0xFFFFF000
	mov r8, r2
	add r1, r8
	ldr r3, _0808DD60 @ =RNG_0202f388
	mov sb, r3
	ldr r0, [r3]
	ldr r6, _0808DD64 @ =0x000343FD
	muls r0, r6, r0
	ldr r3, _0808DD68 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	ldr r5, _0808DD70 @ =0x00001FFF
	ands r0, r5
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, [r7, #0x58]
	add r2, r8
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, sb
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_0808DC94:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _0808DD06
	movs r0, #0x56
	bl PlaySound
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r5, r7, #0
	adds r5, #0xb9
	ldrb r2, [r5]
	ldrb r3, [r7, #0xa]
	lsrs r3, r3, #4
	movs r4, #1
	ands r3, r4
	bl CreateGhost65
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	strb r6, [r7, #0xe]
	ldrb r0, [r5]
	cmp r0, #5
	bls _0808DD06
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808DD74 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_0808DD06:
	ldr r0, _0808DD78 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808DD4E
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808DD74 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_0808DD4E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DD5C: .4byte 0xFFFFFE00
_0808DD60: .4byte RNG_0202f388
_0808DD64: .4byte 0x000343FD
_0808DD68: .4byte 0x00269EC3
_0808DD6C: .4byte 0xFFFFF000
_0808DD70: .4byte 0x00001FFF
_0808DD74: .4byte gEnemyFnTable
_0808DD78: .4byte gStageRun+232

	thumb_func_start FUN_0808dd7c
FUN_0808dd7c: @ 0x0808DD7C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808DDAC
	cmp r0, #1
	bgt _0808DD90
	cmp r0, #0
	beq _0808DD9A
	b _0808DDFE
_0808DD90:
	cmp r0, #2
	beq _0808DDD0
	cmp r0, #3
	beq _0808DDDE
	b _0808DDFE
_0808DD9A:
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldr r1, _0808DDCC @ =0x00007402
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DDAC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808DDC4
	adds r0, r4, #0
	bl FUN_0808d10c
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DDC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0808DDFE
	.align 2, 0
_0808DDCC: .4byte 0x00007402
_0808DDD0:
	ldr r1, _0808DEA8 @ =0x00007403
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DDDE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808DDFE
	adds r2, r4, #0
	adds r2, #0xba
	movs r0, #0
	movs r1, #0x20
	strb r1, [r2]
	movs r1, #1
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808DDFE:
	ldr r0, [r4, #0x54]
	ldr r1, _0808DEAC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808DE30
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _0808DE44
_0808DE30:
	adds r0, r4, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808DE44
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808DE44:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808d268
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808DE5A
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808DE5A:
	ldr r0, _0808DEB0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808DEA2
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
	ldr r1, _0808DEB4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0808DEA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808DEA8: .4byte 0x00007403
_0808DEAC: .4byte 0xFFFFEE00
_0808DEB0: .4byte gStageRun+232
_0808DEB4: .4byte gEnemyFnTable

	thumb_func_start FUN_0808deb8
FUN_0808deb8: @ 0x0808DEB8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	cmp r5, #0
	beq _0808DECC
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0808DECC
	movs r5, #0
	str r5, [r4, #0x28]
_0808DECC:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808DF16
	cmp r0, #1
	bgt _0808DEDC
	cmp r0, #0
	beq _0808DEE6
	b _0808E006
_0808DEDC:
	cmp r0, #2
	beq _0808DF7C
	cmp r0, #3
	beq _0808DFB6
	b _0808E006
_0808DEE6:
	movs r0, #0x83
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808DF60 @ =0x083691B0
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r0, _0808DF64 @ =0xFFFFE400
	str r0, [r4, #0x68]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldr r1, _0808DF68 @ =0x00007410
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DF16:
	ldr r2, [r5, #0x54]
	ldr r0, _0808DF6C @ =0xFFFFFE00
	adds r2, r2, r0
	ldr r3, _0808DF70 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _0808DF74 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808DF78 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	subs r1, #0x80
	str r1, [r4, #0x68]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808DF52
	cmp r5, #0
	bne _0808DF58
_0808DF52:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DF58:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0808E006
	.align 2, 0
_0808DF60: .4byte 0x083691B0
_0808DF64: .4byte 0xFFFFE400
_0808DF68: .4byte 0x00007410
_0808DF6C: .4byte 0xFFFFFE00
_0808DF70: .4byte RNG_0202f388
_0808DF74: .4byte 0x000343FD
_0808DF78: .4byte 0x00269EC3
_0808DF7C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808E00C @ =0x08369198
	bl SetDDP
	ldr r0, _0808E010 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldr r0, _0808E014 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0808DF9C
	movs r2, #0x80
	lsls r2, r2, #2
_0808DF9C:
	str r2, [r4, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Sqrt
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DFB6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
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
	ble _0808DFD4
	str r1, [r4, #0x60]
_0808DFD4:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808E006
	adds r1, r4, #0
	adds r1, #0xbc
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0808E018 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_0808E006:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E00C: .4byte 0x08369198
_0808E010: .4byte 0xFFFFFE00
_0808E014: .4byte pZero2
_0808E018: .4byte gEnemyFnTable

	thumb_func_start FUN_0808e01c
FUN_0808e01c: @ 0x0808E01C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808E02C
	cmp r0, #1
	beq _0808E0E2
	b _0808E17C
_0808E02C:
	ldr r1, _0808E0C0 @ =0x08369300
	adds r4, r5, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _0808E0C4 @ =0x0836930C
	ldrb r1, [r4]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808E0C8 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0808E0CC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _0808E0D0 @ =0xFFFFE800
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
	beq _0808E0D4
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
	b _0808E0DC
	.align 2, 0
_0808E0C0: .4byte 0x08369300
_0808E0C4: .4byte 0x0836930C
_0808E0C8: .4byte 0x08369198
_0808E0CC: .4byte pZero2
_0808E0D0: .4byte 0xFFFFE800
_0808E0D4:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0808E0DC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808E0E2:
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808E0FE
	adds r6, r5, #0
	adds r6, #0x8c
	ldr r4, [r6]
	movs r0, #4
	ands r4, r0
	cmp r4, #0
	beq _0808E10E
_0808E0FE:
	adds r1, r5, #0
	adds r1, #0xbb
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl maybeKillDeathlock
	b _0808E17C
_0808E10E:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808E11E
	str r1, [r5, #0x60]
_0808E11E:
	ldr r1, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_0808d268
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808E138
	adds r0, r5, #0
	adds r0, #0xbb
	strb r4, [r0]
	adds r0, r5, #0
	bl maybeKillDeathlock
_0808E138:
	ldr r0, _0808E184 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808E17C
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
	ldr r1, _0808E188 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_0808E17C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E184: .4byte gStageRun+232
_0808E188: .4byte gEnemyFnTable

	thumb_func_start FUN_0808e18c
FUN_0808e18c: @ 0x0808E18C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0808E19C
	cmp r1, #1
	beq _0808E1BA
	b _0808E222
_0808E19C:
	movs r0, #0x40
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	movs r1, #0xec
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808E1BA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808E21C
	movs r0, #0xc0
	strb r0, [r4, #0x12]
	ldr r0, _0808E1F0 @ =pZero2
	ldr r0, [r0]
	ldr r3, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r3, r0
	bge _0808E1F4
	ldr r0, [r4, #0x58]
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r0, r2
	ldrb r0, [r4, #0x13]
	movs r2, #7
	cmp r0, #1
	bne _0808E1E8
	movs r2, #5
_0808E1E8:
	adds r0, r3, #0
	bl FUN_0808d0b0
	b _0808E20C
	.align 2, 0
_0808E1F0: .4byte pZero2
_0808E1F4:
	ldr r0, [r4, #0x58]
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r0, r2
	ldrb r0, [r4, #0x13]
	movs r2, #6
	cmp r0, #1
	bne _0808E206
	movs r2, #4
_0808E206:
	adds r0, r3, #0
	bl FUN_0808d0b0
_0808E20C:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #0x13]
_0808E21C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808E222:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808e228
FUN_0808e228: @ 0x0808E228
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
	ldr r1, _0808E288 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808E28C @ =0x08369322
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	ldr r1, _0808E290 @ =gEnemyFnTable
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
_0808E288: .4byte 0xFFFFF000
_0808E28C: .4byte 0x08369322
_0808E290: .4byte gEnemyFnTable

	thumb_func_start maybeKillDeathlock
maybeKillDeathlock: @ 0x0808E294
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _0808E348 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E2FC
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r5, [r0]
	cmp r5, #5
	bgt _0808E2FC
_0808E2E2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r6, #0xa]
	lsrs r3, r3, #4
	movs r4, #1
	ands r3, r4
	bl CreateGhost65
	adds r5, #1
	cmp r5, #5
	ble _0808E2E2
_0808E2FC:
	adds r0, r6, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E32E
	ldrb r0, [r6, #0x10]
	adds r4, r6, #0
	adds r4, #0x54
	cmp r0, #9
	beq _0808E318
	movs r0, #0
	adds r1, r4, #0
	bl TryDropItem
_0808E318:
	ldr r2, _0808E34C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808E350 @ =0x0000270E
	cmp r1, r0
	bhi _0808E326
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808E326:
	adds r0, r6, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
_0808E32E:
	ldr r1, _0808E354 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E348: .4byte 0xFFFFF000
_0808E34C: .4byte gMission
_0808E350: .4byte 0x0000270E
_0808E354: .4byte gEnemyFnTable

	thumb_func_start FUN_0808e358
FUN_0808e358: @ 0x0808E358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808E372
	cmp r0, #1
	beq _0808E45E
	b _0808E4BC
_0808E372:
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r6, [r0]
	adds r7, r5, #0
	adds r7, #0x8c
	movs r0, #0x90
	adds r0, r0, r5
	mov r8, r0
	movs r2, #0x94
	adds r2, r2, r5
	mov sb, r2
	movs r0, #0x54
	adds r0, r0, r5
	mov sl, r0
	cmp r6, #5
	bgt _0808E3AC
_0808E392:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r5, #0xa]
	lsrs r3, r3, #4
	movs r4, #1
	ands r3, r4
	bl CreateGhost65
	adds r6, #1
	cmp r6, #5
	ble _0808E392
_0808E3AC:
	movs r4, #0
	ldr r0, _0808E434 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808E3BE
	movs r4, #1
_0808E3BE:
	lsls r0, r4, #8
	subs r0, r1, r0
	str r0, [r5, #0x54]
	ldr r1, _0808E438 @ =0x0000740F
	adds r0, r5, #0
	bl SetMotion
	movs r6, #0
	str r6, [r7]
	mov r2, r8
	str r6, [r2]
	mov r0, sb
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_080b2b40
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl PushoutToUp1
	mvns r0, r0
	lsrs r0, r0, #0x1f
	strb r0, [r5, #0x13]
	movs r2, #0x60
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #6
	subs r1, r2, r1
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	cmp r0, #0
	beq _0808E440
	ldr r0, _0808E43C @ =0x08369328
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sl
	add r2, sp, #8
	movs r3, #0x20
	bl FUN_080b857c
	str r6, [r5, #0x60]
	b _0808E454
	.align 2, 0
_0808E434: .4byte pZero2
_0808E438: .4byte 0x0000740F
_0808E43C: .4byte 0x08369328
_0808E440:
	ldr r0, _0808E4AC @ =0x08369328
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sl
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
_0808E454:
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808E45E:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0808E47C
	ldr r0, [r5, #0x60]
	adds r0, #0x15
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808E474
	str r1, [r5, #0x60]
_0808E474:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0808E47C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r1, r0, #1
	strb r1, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0808E4B0
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0808E4A2
	ldr r1, [r5, #0x54]
	adds r0, r1, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808E4BC
_0808E4A2:
	adds r0, r5, #0
	bl maybeKillDeathlock
	b _0808E4BC
	.align 2, 0
_0808E4AC: .4byte 0x08369328
_0808E4B0:
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _0808E4BC
	adds r0, r5, #0
	bl maybeKillDeathlock
_0808E4BC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
