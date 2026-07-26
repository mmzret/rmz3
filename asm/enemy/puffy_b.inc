	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Puffy_Die
Puffy_Die: @ 0x0807C774
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0807C7A8 @ =gStageRun
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq _0807C7B4
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	movs r0, #0
	bl PlaySound
	ldr r2, _0807C7AC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C7B0 @ =0x0000270E
	cmp r1, r0
	bhi _0807C7A2
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C7A2:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807C936
	.align 2, 0
_0807C7A8: .4byte gStageRun
_0807C7AC: .4byte gScore
_0807C7B0: .4byte 0x0000270E
_0807C7B4:
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0807C7BC
	b _0807C954
_0807C7BC:
	lsls r0, r0, #2
	ldr r1, _0807C7C8 @ =_0807C7CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807C7C8: .4byte _0807C7CC
_0807C7CC: @ jump table
	.4byte _0807C7E0 @ case 0
	.4byte _0807C890 @ case 1
	.4byte _0807C8C0 @ case 2
	.4byte _0807C8D0 @ case 3
	.4byte _0807C90C @ case 4
_0807C7E0:
	ldr r1, _0807C840 @ =0x00004101
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807C848
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807C844 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl createGhost44
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl TryDropItem
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C890
	.align 2, 0
_0807C840: .4byte 0x00004101
_0807C844: .4byte 0xFFFFFA00
_0807C848:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807C884 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0807C888 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C88C @ =0x0000270E
	cmp r1, r0
	bhi _0807C87C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C87C:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807C936
	.align 2, 0
_0807C884: .4byte 0xFFFFFA00
_0807C888: .4byte gScore
_0807C88C: .4byte 0x0000270E
_0807C890:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807C8B0
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807C8B6
_0807C8B0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807C8B6:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807C954
	b _0807C904
_0807C8C0:
	adds r0, r4, #0
	bl PaintEntityWhite
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C8D0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807C8EA
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807C8F0
_0807C8EA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807C8F0:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807C954
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
_0807C904:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C954
_0807C90C:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807C91C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C954
_0807C91C:
	movs r0, #0
	bl PlaySound
	ldr r2, _0807C95C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C960 @ =0x0000270E
	cmp r1, r0
	bhi _0807C930
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C930:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
_0807C936:
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807C964 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0807C954:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C95C: .4byte gScore
_0807C960: .4byte 0x0000270E
_0807C964: .4byte gEnemyFnTable
