	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonBomber_Init
PantheonBomber_Init: @ 0x08085D6C
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
	ldr r0, _08085DB8 @ =gSystemSavedata
	ldrb r1, [r0, #0x12]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08085DC4
	ldr r0, _08085DBC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08085DC4
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08085DC0 @ =0x08368534
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _08085DDC
	.align 2, 0
_08085DB8: .4byte gSystemSavedata
_08085DBC: .4byte gCurStory
_08085DC0: .4byte 0x08368534
_08085DC4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08085E5C @ =0x08368534
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_08085DDC:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08085E60 @ =FUN_0808665c
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r4, #0
	strb r4, [r0]
	adds r0, #4
	str r4, [r0]
	subs r0, #3
	strb r4, [r0]
	ldr r0, [r6, #0x54]
	ldr r1, _08085E64 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _08085E68 @ =gEnemyFnTable
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
	beq _08085E4A
	ldr r1, _08085E6C @ =0x00006903
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_08085E4A:
	adds r0, r6, #0
	adds r0, #0xba
	strb r4, [r0]
	adds r0, r6, #0
	bl PantheonBomber_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085E5C: .4byte 0x08368534
_08085E60: .4byte FUN_0808665c
_08085E64: .4byte 0xFFFFF800
_08085E68: .4byte gEnemyFnTable
_08085E6C: .4byte 0x00006903

