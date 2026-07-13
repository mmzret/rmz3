	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08094c80
FUN_08094c80: @ 0x08094C80
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08094D40
	lsls r0, r0, #2
	ldr r1, _08094C94 @ =_08094C98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08094C94: .4byte _08094C98
_08094C98: @ jump table
	.4byte _08094CB0 @ case 0
	.4byte _08094CC2 @ case 1
	.4byte _08094CD0 @ case 2
	.4byte _08094CE4 @ case 3
	.4byte _08094D0A @ case 4
	.4byte _08094D14 @ case 5
_08094CB0:
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094CC2:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D40
	b _08094CFC
_08094CD0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldrb r2, [r4, #0x10]
	bl FUN_08094a54
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094CE4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D40
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D04
_08094CFC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08094D40
_08094D04:
	movs r0, #2
	strb r0, [r4, #0xe]
	b _08094D40
_08094D0A:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094D14:
	ldrb r0, [r4, #0x12]
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D2C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldrb r2, [r4, #0x10]
	bl FUN_080949d4
_08094D2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08094D40
	strb r0, [r4, #0xe]
	movs r0, #0x78
	strb r0, [r4, #0x12]
_08094D40:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08094d48
FUN_08094d48: @ 0x08094D48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08094D58
	cmp r5, #1
	beq _08094D6A
	b _08094DFC
_08094D58:
	movs r1, #0xc8
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094D6A:
	ldr r0, _08094D84 @ =pZero2
	ldr r0, [r0]
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _08094D8C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08094D88 @ =sCollisions
	bl SetDDP
	b _08094D96
	.align 2, 0
_08094D84: .4byte pZero2
_08094D88: .4byte sCollisions
_08094D8C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08094E04 @ =0x08369F14
	bl SetDDP
_08094D96:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r5, r1, r0
	str r5, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r3, r1, r0
	str r3, [r4, #0x58]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #6
	cmp r0, r1
	ble _08094DF6
	ldrb r2, [r4, #0x11]
	adds r0, r5, #0
	adds r1, r3, #0
	bl FUN_08094a54
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
	ldr r1, _08094E08 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08094DF6:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08094DFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094E04: .4byte sCollisions+(24*1)
_08094E08: .4byte gEnemyFnTable
