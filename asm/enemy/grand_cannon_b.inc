	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start explodeGrandCannon
explodeGrandCannon: @ 0x0806962C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080696B8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080696BC @ =sMotions
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #3
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080696C0 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080696C4 @ =0x0000270E
	cmp r1, r0
	bhi _0806968C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806968C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _080696C8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080696B8: .4byte 0xFFFFF000
_080696BC: .4byte sMotions
_080696C0: .4byte gScore
_080696C4: .4byte 0x0000270E
_080696C8: .4byte gEnemyFnTable

	thumb_func_start slashGrandCannon
slashGrandCannon: @ 0x080696CC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080696DE
	cmp r0, #1
	beq _08069792
	b _080697AA
_080696DE:
	movs r3, #0
	ldr r0, _08069700 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080696F0
	movs r3, #1
_080696F0:
	adds r6, r3, #0
	adds r2, r6, #0
	cmp r6, #0
	beq _08069704
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806970A
	.align 2, 0
_08069700: .4byte pZero2
_08069704:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806970A:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r1, r6, #8
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _080697B4 @ =0x00000701
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r1, r1, r0
	str r1, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _080697B8 @ =0x083662C2
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08069792:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080697AA
	adds r0, r5, #0
	bl explodeGrandCannon
_080697AA:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080697B4: .4byte 0x00000701
_080697B8: .4byte sMotions+6

	thumb_func_start FUN_080697bc
FUN_080697bc: @ 0x080697BC
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #4
	bne _080697FE
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08069804 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080697FE:
	pop {r0}
	bx r0
	.align 2, 0
_08069804: .4byte gEnemyFnTable

