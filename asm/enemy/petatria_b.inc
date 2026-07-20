	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Petatria_Die
Petatria_Die: @ 0x08090130
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0809017C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08090184
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08090180 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08090270
	.align 2, 0
_0809017C: .4byte gCurStory
_08090180: .4byte gEnemyFnTable
_08090184:
	ldrb r2, [r7, #0xe]
	cmp r2, #1
	beq _080901BC
	cmp r2, #1
	bgt _08090194
	cmp r2, #0
	beq _0809019E
	b _08090272
_08090194:
	cmp r2, #0xa
	beq _080901BC
	cmp r2, #0xb
	beq _080901C4
	b _08090272
_0809019E:
	movs r0, #0xa
	strb r0, [r7, #0xe]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	str r2, [r7, #0x60]
	str r2, [r7, #0x5c]
_080901BC:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08090272
_080901C4:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov r8, r0
	movs r0, #4
	mov r1, r8
	bl TryDropItem
	ldr r2, _08090280 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090284 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _08090288 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	ldr r1, _0809028C @ =0xFFFFF400
	adds r0, r0, r1
	add r6, sp, #8
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _08090290 @ =0x00007E1A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08090294 @ =0x00007E1B
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08090298 @ =0x00007E1C
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldr r2, _0809029C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080902A0 @ =0x0000270E
	cmp r1, r0
	bhi _08090250
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08090250:
	adds r0, r7, #0
	mov r1, r8
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080902A4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_08090270:
	str r0, [r7, #0x14]
_08090272:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090280: .4byte RNG_0202f388
_08090284: .4byte 0x000343FD
_08090288: .4byte 0x00269EC3
_0809028C: .4byte 0xFFFFF400
_08090290: .4byte 0x00007E1A
_08090294: .4byte 0x00007E1B
_08090298: .4byte 0x00007E1C
_0809029C: .4byte gScore
_080902A0: .4byte 0x0000270E
_080902A4: .4byte gEnemyFnTable

