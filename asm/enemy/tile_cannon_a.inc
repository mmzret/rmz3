	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08078108
FUN_08078108: @ 0x08078108
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08078168 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _08078160
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807816C @ =gEnemyFnTable
	movs r0, #0x19
	strb r0, [r4, #9]
	ldr r0, [r1, #0x64]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r2, #0x10
	orrs r1, r2
	orrs r1, r3
	strb r1, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #2
	strb r0, [r4, #0x10]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	str r5, [r4, #0x28]
	orrs r1, r2
	strb r1, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
_08078160:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08078168: .4byte gEnemyHeaderPtr
_0807816C: .4byte gEnemyFnTable

	thumb_func_start FUN_08078170
FUN_08078170: @ 0x08078170
	bx lr
	.align 2, 0

	thumb_func_start tilecannon_08078174
tilecannon_08078174: @ 0x08078174
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0807818A
	movs r0, #0
	b _08078192
_0807818A:
	adds r0, r2, #0
	bl TileCannon_Die
	movs r0, #1
_08078192:
	pop {r1}
	bx r1
	.align 2, 0

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
