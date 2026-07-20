	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Mothjiro_Init
Mothjiro_Init: @ 0x08087BFC
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
	ldr r0, _08087C48 @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08087C54
	ldr r0, _08087C4C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08087C54
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08087C50 @ =0x083687C8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _08087C6C
	.align 2, 0
_08087C48: .4byte gSystemSavedata
_08087C4C: .4byte gCurStory
_08087C50: .4byte 0x083687C8
_08087C54:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08087CE8 @ =0x083687C8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_08087C6C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08087CEC @ =FUN_08088b0c
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xc0
	movs r4, #0
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r0, [r6, #0x54]
	ldr r2, _08087CF0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	ldr r2, _08087CF4 @ =0xFFFFB000
	adds r0, r0, r2
	str r0, [r1]
	ldr r1, _08087CF8 @ =gEnemyFnTable
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
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _08087CD8
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_08087CD8:
	strb r4, [r6, #0x11]
	adds r0, r6, #0
	bl Mothjiro_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087CE8: .4byte 0x083687C8
_08087CEC: .4byte FUN_08088b0c
_08087CF0: .4byte 0xFFFFC000
_08087CF4: .4byte 0xFFFFB000
_08087CF8: .4byte gEnemyFnTable

