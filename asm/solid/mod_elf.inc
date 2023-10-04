	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ModElf_Init
ModElf_Init: @ 0x080DF900
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _080DF91A
	ldr r0, _080DF968 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xf]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080DF930
_080DF91A:
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	bne _080DF970
	ldr r0, _080DF968 @ =gSystemSavedataManager
	ldrb r1, [r0, #0xb]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080DF970
_080DF930:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _080DF96C @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080DFA10
	.align 2, 0
_080DF968: .4byte gSystemSavedataManager
_080DF96C: .4byte gSolidFnTable
_080DF970:
	ldr r1, _080DFA18 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r0, #2
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	movs r5, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DFA1C @ =0x083718F0
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	ldr r2, _080DFA20 @ =0xFFFFD000
	adds r0, r0, r2
	str r0, [r1]
	strb r5, [r6, #0x12]
	adds r0, r6, #0
	bl ModElf_Update
_080DFA10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DFA18: .4byte gSolidFnTable
_080DFA1C: .4byte 0x083718F0
_080DFA20: .4byte 0xFFFFD000

	thumb_func_start ModElf_Update
ModElf_Update: @ 0x080DFA24
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r4, #0x64]
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r1, _080DFA78 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x68]
	subs r2, #0x54
	str r2, [r4, #0x40]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080DFA6A
	adds r0, r2, #0
	movs r1, #2
	bl FUN_080bfc94
_080DFA6A:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080DFA7C
	cmp r0, #1
	beq _080DFAD0
	b _080DFADE
	.align 2, 0
_080DFA78: .4byte gSineTable
_080DFA7C:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	beq _080DFADE
	ldr r0, _080DFAB4 @ =gInChat
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DFADE
	ldr r0, _080DFAB8 @ =gCollisionManager
	movs r1, #0xc5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x74
	ldr r0, [r0]
	cmp r0, r1
	bne _080DFADE
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080DFAC0
	ldr r0, _080DFABC @ =0x000002D5
	bl PrintNormalMessage
	b _080DFAC8
	.align 2, 0
_080DFAB4: .4byte gInChat
_080DFAB8: .4byte gCollisionManager
_080DFABC: .4byte 0x000002D5
_080DFAC0:
	movs r0, #0xb5
	lsls r0, r0, #2
	bl PrintNormalMessage
_080DFAC8:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080DFADE
_080DFAD0:
	ldr r0, _080DFAE4 @ =gTextWindow+8
	ldrh r1, [r0, #2]
	cmp r1, #0
	bne _080DFADE
	ldr r0, _080DFAE8 @ =gInChat
	strb r1, [r0]
	strb r1, [r4, #0xd]
_080DFADE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DFAE4: .4byte gTextWindow+8
_080DFAE8: .4byte gInChat

	thumb_func_start ModElf_Die
ModElf_Die: @ 0x080DFAEC
	ldr r2, _080DFB00 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080DFB00: .4byte gSolidFnTable
