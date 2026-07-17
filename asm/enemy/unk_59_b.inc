	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Enemy59_Update
Enemy59_Update: @ 0x0809159C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r4, [r6, #0x28]
	adds r5, r6, #0
	adds r5, #0x34
	ldrb r0, [r6, #0x10]
	cmp r0, #0xc
	bne _080915E8
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080915C4
	b _080916F4
_080915C4:
	ldr r1, _080915E4 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
	adds r0, r6, #0
	bl Enemy59_Die
	b _0809175E
	.align 2, 0
_080915E4: .4byte gEnemyFnTable
_080915E8:
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _08091614
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
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
	b _080916DC
_08091614:
	adds r1, r6, #0
	adds r1, #0x8c
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _080916F4
	adds r0, r6, #0
	bl FUN_08091280
	adds r2, r4, #0
	adds r2, #0xc4
	ldr r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _08091680 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	cmp r0, #0
	beq _080916A6
	movs r3, #0
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08091660
	movs r3, #1
_08091660:
	movs r0, #0
	mov r1, sp
	mov r2, r8
	bl FUN_080b2b40
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08091684
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_080913c0
	b _080916AE
	.align 2, 0
_08091680: .4byte 0xFFFFEC00
_08091684:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _0809169C
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080913c0
	b _080916AE
_0809169C:
	adds r0, r6, #0
	movs r1, #9
	bl FUN_080913c0
	b _080916AE
_080916A6:
	adds r0, r6, #0
	movs r1, #9
	bl FUN_080913c0
_080916AE:
	movs r3, #0
	str r3, [r7]
	adds r5, r6, #0
	adds r5, #0x90
	str r3, [r5]
	adds r4, r6, #0
	adds r4, #0x94
	strb r3, [r4]
	ldrb r1, [r6, #0xa]
	movs r2, #0xfb
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	str r3, [r7]
	str r3, [r5]
	strb r3, [r4]
	ldrb r0, [r6, #0xa]
	ands r2, r0
	strb r2, [r6, #0xa]
_080916DC:
	ldr r1, _080916F0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _0809175E
	.align 2, 0
_080916F0: .4byte gEnemyFnTable
_080916F4:
	ldr r1, _0809176C @ =sUpdates1
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r1, _08091770 @ =sUpdates2
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldrb r0, [r6, #0x10]
	cmp r0, #0xc
	beq _0809175E
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r1, [r0]
	ldr r0, [r4, #0x6c]
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0x1a]
	adds r1, r4, #0
	adds r1, #0x34
	ldr r0, [r1, #8]
	str r0, [r5, #8]
	ldrh r1, [r1, #0x14]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #0x14]
	ldr r0, _08091774 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #0x14]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x23
	strb r1, [r0]
_0809175E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809176C: .4byte sUpdates1
_08091770: .4byte sUpdates2
_08091774: .4byte 0xFFFFFC00

