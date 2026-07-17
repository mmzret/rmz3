	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tilecannon_08078198
tilecannon_08078198: @ 0x08078198
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _080781A8
	cmp r0, #1
	beq _080781EC
	b _08078208
_080781A8:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08078208
	ldr r1, _080781E4 @ =0x08367418
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080781E8 @ =0x0836743C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #1
	b _0807820A
	.align 2, 0
_080781E4: .4byte 0x08367418
_080781E8: .4byte 0x0836743C
_080781EC:
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _080781F8
	adds r0, r4, #0
	bl FUN_080780c4
_080781F8:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08078206
	movs r0, #1
	b _0807820A
_08078206:
	strb r0, [r4, #0xf]
_08078208:
	movs r0, #0
_0807820A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start tilecannon_08078210
tilecannon_08078210: @ 0x08078210
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r5, [r6]
	cmp r5, #0
	bne _0807823E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807823E
	ldr r2, _08078244 @ =0x08367538
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807823E
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0807823E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078244: .4byte 0x08367538

	thumb_func_start TileCannon_Init
TileCannon_Init: @ 0x08078248
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080782B8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _080782BC @ =0x08367540
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0x10]
	cmp r1, #2
	beq _080782C4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080782C0 @ =0x08367460
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _08078324
	.align 2, 0
_080782B8: .4byte gEnemyFnTable
_080782BC: .4byte 0x08367540
_080782C0: .4byte 0x08367460
_080782C4:
	ldr r0, _080782F8 @ =gSystemSavedata
	ldrb r0, [r0, #0x15]
	ands r1, r0
	cmp r1, #0
	beq _08078304
	ldr r0, _080782FC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08078304
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08078300 @ =0x08367508
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _0807831C
	.align 2, 0
_080782F8: .4byte gSystemSavedata
_080782FC: .4byte gCurStory
_08078300: .4byte 0x08367508
_08078304:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08078348 @ =0x08367508
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_0807831C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_08078324:
	ldr r0, _0807834C @ =FUN_08078170
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	movs r0, #0x28
	strb r0, [r6, #0x12]
	subs r1, #0x8f
	movs r0, #0x1f
	strb r0, [r1]
	adds r0, r6, #0
	bl TileCannon_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078348: .4byte 0x08367508
_0807834C: .4byte FUN_08078170

