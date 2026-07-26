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
	ldr r0, _0808D104 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
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
_0808D104: .4byte gEnemyHeaderPtr
_0808D108: .4byte gEnemyFnTable

	thumb_func_start FUN_0808d10c
FUN_0808d10c: @ 0x0808D10C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808D158 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
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
_0808D158: .4byte gEnemyHeaderPtr
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
	bl IsFrozen
	cmp r0, #0
	beq _0808D496
	ldr r1, _0808D40C @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808D410 @ =sUpdates2
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
	ldr r2, _0808D414 @ =sCollisionIdxs1
	adds r5, r4, #0
	adds r5, #0xb9
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D418 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _0808D41C @ =sMotions1
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
	bl UpdateEntityAnim
_0808D406:
	movs r0, #1
	b _0808D498
	.align 2, 0
_0808D40C: .4byte sUpdates1
_0808D410: .4byte sUpdates2
_0808D414: .4byte sCollisionIdxs1
_0808D418: .4byte sCollisions
_0808D41C: .4byte sMotions1
_0808D420:
	adds r0, r4, #0
	bl IsFrozen
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
