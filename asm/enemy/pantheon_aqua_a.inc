	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonAqua_Init
PantheonAqua_Init: @ 0x08071CE4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _08071D30 @ =gSystemSavedata
	ldrb r1, [r0, #0x11]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08071D3C
	ldr r0, _08071D34 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08071D3C
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08071D38 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	b _08071D54
	.align 2, 0
_08071D30: .4byte gSystemSavedata
_08071D34: .4byte gCurStory
_08071D38: .4byte sCollisions
_08071D3C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08071DA4 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
_08071D54:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08071DA8 @ =gOverworld
	ldr r1, _08071DAC @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r6, #0x58]
	cmp r1, r0
	ble _08071DB4
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
	ldr r1, _08071DB0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _08071E68
	.align 2, 0
_08071DA4: .4byte sCollisions
_08071DA8: .4byte gOverworld
_08071DAC: .4byte 0x0002C00C
_08071DB0: .4byte gEnemyFnTable
_08071DB4:
	ldrb r2, [r6, #0x10]
	cmp r2, #0
	bne _08071DD8
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
	b _08071DFA
_08071DD8:
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
	strb r0, [r3]
_08071DFA:
	ldr r0, _08071E70 @ =FUN_0807336c
	str r0, [r4, #0x24]
	movs r4, #0
	str r4, [r6, #0x60]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r4, [r0, #4]
	str r4, [r6, #0x64]
	adds r0, #0x58
	str r4, [r0]
	subs r0, #3
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	subs r0, #2
	strb r4, [r0]
	ldr r1, _08071E74 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #0xc
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _08071E5C
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_08071E5C:
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	adds r0, r6, #0
	bl PantheonAqua_Update
_08071E68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08071E70: .4byte FUN_0807336c
_08071E74: .4byte gEnemyFnTable

