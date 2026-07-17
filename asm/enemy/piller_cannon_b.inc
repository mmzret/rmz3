	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PillerCannon_Die
PillerCannon_Die: @ 0x08068514
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0806855C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08068564
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
	ldr r1, _08068560 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080685F4
	.align 2, 0
_0806855C: .4byte gCurStory
_08068560: .4byte gEnemyFnTable
_08068564:
	ldrb r1, [r4, #0xe]
	cmp r1, #1
	beq _08068594
	cmp r1, #1
	bgt _08068574
	cmp r1, #0
	beq _0806857A
	b _080685F6
_08068574:
	cmp r1, #2
	beq _080685A4
	b _080685F6
_0806857A:
	movs r0, #1
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_08068594:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080685F6
_080685A4:
	ldr r0, [r4, #0x5c]
	str r0, [sp]
	ldr r0, [r4, #0x60]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08068600 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08068604 @ =0x0000270E
	cmp r1, r0
	bhi _080685D4
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080685D4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08068608 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_080685F4:
	str r0, [r4, #0x14]
_080685F6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068600: .4byte gScore
_08068604: .4byte 0x0000270E
_08068608: .4byte gEnemyFnTable

