	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start mob_chat_080d97b4
mob_chat_080d97b4: @ 0x080D97B4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080D983C
	ldr r1, _080D980C @ =sMobNPCTalks
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
	ldrh r0, [r1]
	bl PrintNormalMessage
	adds r0, r4, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D9836
	movs r2, #0
	ldr r0, _080D9810 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080D9800
	movs r2, #1
_080D9800:
	cmp r2, #0
	beq _080D9814
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080D981A
	.align 2, 0
_080D980C: .4byte sMobNPCTalks
_080D9810: .4byte pZero2
_080D9814:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080D981A:
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
_080D9836:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D983C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _080D9870 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080D98DE
	ldr r2, _080D9874 @ =gSystemSavedata
	ldrb r1, [r2, #0xf]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D9898
	adds r3, r4, #0
	adds r3, #0xba
	ldrh r1, [r3]
	ldr r0, _080D9878 @ =0x0000029E
	cmp r1, r0
	bne _080D987C
	adds r0, #1
	strh r0, [r3]
	ldrh r0, [r3]
	bl PrintNormalMessage
	b _080D98DE
	.align 2, 0
_080D9870: .4byte gTextWindow+8
_080D9874: .4byte gSystemSavedata
_080D9878: .4byte 0x0000029E
_080D987C:
	movs r0, #0xa8
	lsls r0, r0, #2
	cmp r1, r0
	beq _080D988A
	ldr r0, _080D9894 @ =0x000002A2
	cmp r1, r0
	bne _080D9898
_080D988A:
	adds r0, #1
	strh r0, [r3]
	bl PrintNormalMessage
	b _080D98DE
	.align 2, 0
_080D9894: .4byte 0x000002A2
_080D9898:
	ldrb r1, [r2, #0xe]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D98D0
	adds r2, r4, #0
	adds r2, #0xba
	ldrh r1, [r2]
	ldr r0, _080D98C4 @ =0x000002A7
	cmp r1, r0
	beq _080D98BA
	ldr r0, _080D98C8 @ =0x000002A9
	cmp r1, r0
	beq _080D98BA
	ldr r0, _080D98CC @ =0x000002AB
	cmp r1, r0
	bne _080D98D0
_080D98BA:
	adds r0, #1
	strh r0, [r2]
	bl PrintNormalMessage
	b _080D98DE
	.align 2, 0
_080D98C4: .4byte 0x000002A7
_080D98C8: .4byte 0x000002A9
_080D98CC: .4byte 0x000002AB
_080D98D0:
	ldr r1, _080D98E4 @ =gInChat
	movs r0, #0
	strb r0, [r1]
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080D98DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D98E4: .4byte gInChat
