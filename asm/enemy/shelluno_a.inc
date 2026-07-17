	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Shelluno_Init
Shelluno_Init: @ 0x080789FC
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
	ldr r0, _08078A48 @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08078A54
	ldr r0, _08078A4C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08078A54
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08078A50 @ =0x0836759C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #9
	b _08078A6C
	.align 2, 0
_08078A48: .4byte gSystemSavedata
_08078A4C: .4byte gCurStory
_08078A50: .4byte 0x0836759C
_08078A54:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08078A98 @ =0x0836759C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #5
_08078A6C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r2, [r6, #0x10]
	cmp r2, #0
	bne _08078A9C
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
	b _08078ABE
	.align 2, 0
_08078A98: .4byte 0x0836759C
_08078A9C:
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
_08078ABE:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a05c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb9
	movs r5, #0
	strb r5, [r0]
	ldr r0, _08078B38 @ =FUN_0807a3ec
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r6, #0x5c]
	adds r0, #8
	str r5, [r0, #4]
	str r5, [r6, #0x64]
	adds r0, #0x58
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _08078B3C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _08078B24
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_08078B24:
	adds r0, r6, #0
	adds r0, #0xba
	strb r5, [r0]
	adds r0, r6, #0
	bl Shelluno_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078B38: .4byte FUN_0807a3ec
_08078B3C: .4byte gEnemyFnTable

