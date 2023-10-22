	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08091280
FUN_08091280: @ 0x08091280
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	mov sl, r0
	ldr r0, _08091300 @ =RNG_0202f388
	mov sb, r0
	ldr r0, [r0]
	ldr r6, _08091304 @ =0x000343FD
	muls r0, r6, r0
	ldr r4, _08091308 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r0, r0, #8
	mov r1, sl
	ldr r5, [r1, #0x54]
	adds r5, r5, r0
	adds r0, r2, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r2, r0, #1
	mov r8, r2
	mov r1, sb
	str r2, [r1]
	lsrs r0, r0, #0x11
	rsbs r0, r0, #0
	movs r1, #0x30
	bl __umodsi3
	lsls r0, r0, #8
	mov r2, sl
	ldr r1, [r2, #0x58]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #1
	mov r3, r8
	muls r3, r6, r3
	adds r3, r3, r4
	lsls r3, r3, #1
	lsrs r0, r3, #1
	mov r4, sb
	str r0, [r4]
	lsrs r3, r3, #0x11
	movs r0, #0x7f
	ands r3, r0
	movs r0, #0x80
	orrs r3, r0
	adds r0, r5, #0
	bl FUN_080c4c2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08091300: .4byte RNG_0202f388
_08091304: .4byte 0x000343FD
_08091308: .4byte 0x00269EC3

	thumb_func_start FUN_0809130c
FUN_0809130c: @ 0x0809130C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	adds r7, r6, #0
	ldr r0, _080913B8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080913B2
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080913BC @ =gEnemyFnTable
	movs r1, #0x3b
	strb r1, [r4, #9]
	adds r0, #0xec
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	cmp r6, #3
	bhi _08091372
	subs r0, r6, #2
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r1, r0
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x64]
_08091372:
	cmp r6, #4
	bls _0809138A
	subs r0, r6, #7
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r1, r0
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0809138A:
	str r5, [r4, #0x28]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r0, [r5, #8]
	str r0, [r4, #0x3c]
	ldrb r1, [r5, #0x15]
	adds r3, r4, #0
	adds r3, #0x49
	lsrs r1, r1, #4
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	strb r7, [r4, #0x10]
_080913B2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080913B8: .4byte gZakoHeaderPtr
_080913BC: .4byte gEnemyFnTable

	thumb_func_start FUN_080913c0
FUN_080913c0: @ 0x080913C0
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _08091424 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809141E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08091428 @ =gEnemyFnTable
	movs r1, #0x3b
	strb r1, [r3, #9]
	adds r0, #0xec
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x10]
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809141C
	movs r1, #1
_0809141C:
	strb r1, [r3, #0x13]
_0809141E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091424: .4byte gZakoHeaderPtr
_08091428: .4byte gEnemyFnTable

	thumb_func_start FUN_0809142c
FUN_0809142c: @ 0x0809142C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _0809148C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08091484
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08091490 @ =gEnemyFnTable
	movs r1, #0x3b
	strb r1, [r3, #9]
	adds r0, #0xec
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _08091494 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r3, #0x58]
	movs r0, #0xc
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x12]
	str r4, [r3, #0x28]
_08091484:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809148C: .4byte gZakoHeaderPtr
_08091490: .4byte gEnemyFnTable
_08091494: .4byte 0xFFFFF600

	thumb_func_start Enemy59_Init
Enemy59_Init: @ 0x08091498
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #0xc
	bne _08091500
	ldr r1, _080914F0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080914F4 @ =0x08369864
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080914F8 @ =FUN_08091790
	str r0, [r4, #0x24]
	ldr r1, _080914FC @ =0x08369A14
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	bl Enemy59_Update
	b _08091586
	.align 2, 0
_080914F0: .4byte gEnemyFnTable
_080914F4: .4byte 0x08369864
_080914F8: .4byte FUN_08091790
_080914FC: .4byte 0x08369A14
_08091500:
	cmp r0, #8
	bls _0809153C
	ldr r1, _08091534 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08091538 @ =0x08369A14
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	bl Enemy59_Die
	b _08091586
	.align 2, 0
_08091534: .4byte gEnemyFnTable
_08091538: .4byte 0x08369A14
_0809153C:
	ldr r1, _0809158C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08091590 @ =0x08369864
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08091594 @ =FUN_08091790
	str r0, [r4, #0x24]
	ldr r1, _08091598 @ =0x08369A14
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	bl Enemy59_Update
_08091586:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809158C: .4byte gEnemyFnTable
_08091590: .4byte 0x08369864
_08091594: .4byte FUN_08091790
_08091598: .4byte 0x08369A14

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
	ldr r1, _0809176C @ =0x083699B4
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r1, _08091770 @ =0x083699DC
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
_0809176C: .4byte 0x083699B4
_08091770: .4byte 0x083699DC
_08091774: .4byte 0xFFFFFC00

	thumb_func_start Enemy59_Die
Enemy59_Die: @ 0x08091778
	push {lr}
	ldr r2, _0809178C @ =0x08369A04
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809178C: .4byte 0x08369A04

	thumb_func_start FUN_08091790
FUN_08091790: @ 0x08091790
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, [r1, #0xc]
	ldr r4, [r0, #0x2c]
	ldr r3, [r1, #0x2c]
	ldrb r0, [r3, #0x10]
	cmp r0, #0xc
	bne _080917F4
	ldr r0, [r1, #0x14]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08091804
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _08091804
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	bne _08091804
	ldrb r0, [r4, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08091804
	ldrb r0, [r4, #9]
	cmp r0, #0x15
	bne _08091804
	ldr r0, [r3, #0xc]
	ldr r1, _080917F0 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0xc2
	lsls r1, r1, #0xa
	cmp r0, r1
	bne _08091804
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r0, [r4, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #9
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
	b _08091804
	.align 2, 0
_080917F0: .4byte 0x00FFFF00
_080917F4:
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r0, _0809180C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	str r0, [r2]
_08091804:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809180C: .4byte pZero2

	thumb_func_start FUN_08091810
FUN_08091810:
  bx lr
	.align 2, 0

	thumb_func_start FUN_08091814
FUN_08091814: @ 0x08091814
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	adds r0, #0x34
	adds r2, r5, #0
	adds r2, #0x34
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0809182C
	cmp r1, #1
	beq _0809183C
	b _080918E2
_0809182C:
	ldr r1, [r2, #8]
	adds r2, r4, #0
	adds r2, #0x54
	bl InitNonAffineSprite
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809183C:
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r1, [r0]
	movs r2, #8
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _08091856
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091868 @ =0x08369864
	bl SetDDP
_08091856:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _0809186C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091872
	.align 2, 0
_08091868: .4byte 0x08369864
_0809186C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091872:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08091884
	strb r2, [r4, #0x12]
_08091884:
	adds r3, r5, #0
	ldr r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080918C4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _080918E8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080918C4:
	ldr r0, [r3]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080918D4
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080918D4:
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080918E2
	strb r1, [r4, #0xd]
	strb r2, [r4, #0xe]
_080918E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080918E8: .4byte gEnemyFnTable

	thumb_func_start FUN_080918ec
FUN_080918ec: @ 0x080918EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080918FC
	cmp r5, #1
	beq _08091924
	b _0809197A
_080918FC:
	movs r6, #0
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0809190A
	movs r6, #1
_0809190A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091934 @ =0x08369894
	bl SetDDP
	lsls r0, r6, #9
	ldr r1, _08091938 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091924:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _0809193C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091942
	.align 2, 0
_08091934: .4byte 0x08369894
_08091938: .4byte 0xFFFFFF00
_0809193C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091942:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _08091954
	movs r0, #0
	strb r0, [r4, #0x12]
_08091954:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r1, r0, r1
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x64]
	subs r2, r0, r1
	adds r3, r0, #0
	cmp r2, #0
	blt _0809196C
	cmp r2, #0xff
	ble _08091972
	b _0809197A
_0809196C:
	subs r0, r1, r3
	cmp r0, #0xff
	bgt _0809197A
_08091972:
	str r3, [r4, #0x54]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0809197A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08091980
FUN_08091980: @ 0x08091980
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _0809198C
	b _08091AA6
_0809198C:
	lsls r0, r0, #2
	ldr r1, _08091998 @ =_0809199C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08091998: .4byte _0809199C
_0809199C: @ jump table
	.4byte _080919BC @ case 0
	.4byte _080919D0 @ case 1
	.4byte _080919E0 @ case 2
	.4byte _080919EA @ case 3
	.4byte _08091A08 @ case 4
	.4byte _08091A12 @ case 5
	.4byte _08091A3C @ case 6
	.4byte _08091A46 @ case 7
_080919BC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080919DC @ =0x08369894
	bl SetDDP
	movs r0, #0x1b
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080919D0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	b _08091A30
	.align 2, 0
_080919DC: .4byte 0x08369894
_080919E0:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080919EA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _08091A26
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _08091A2C
_08091A08:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091A12:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08091A26
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _08091A2C
_08091A26:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091A2C:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
_08091A30:
	cmp r0, #0
	bne _08091AA6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08091AA6
_08091A3C:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091A46:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08091A64
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _08091A6A
_08091A64:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091A6A:
	strb r0, [r4, #0xa]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	bne _08091AA6
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _08091AAC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091AA6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091AAC: .4byte gEnemyFnTable

	thumb_func_start FUN_08091ab0
FUN_08091ab0: @ 0x08091AB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	adds r0, #0x34
	adds r2, r5, #0
	adds r2, #0x34
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _08091AC8
	cmp r1, #1
	beq _08091AE2
	b _08091B56
_08091AC8:
	ldr r1, [r2, #8]
	adds r2, r4, #0
	adds r2, #0x54
	bl InitNonAffineSprite
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091AF4 @ =0x08369894
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091AE2:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _08091AF8
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091AFE
	.align 2, 0
_08091AF4: .4byte 0x08369894
_08091AF8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091AFE:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _08091B10
	strb r2, [r4, #0x12]
_08091B10:
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08091B56
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _08091B5C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091B56:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091B5C: .4byte gEnemyFnTable

	thumb_func_start FUN_08091b60
FUN_08091b60: @ 0x08091B60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x34
	mov r6, r8
	adds r6, #0x34
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08091B80
	cmp r5, #1
	beq _08091BB8
	b _08091C46
_08091B80:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091BD0 @ =0x08369894
	bl SetDDP
	ldr r1, [r6, #8]
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r7, #0
	bl InitScalerotSprite1
	ldrb r1, [r4, #0xa]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	strb r5, [r4, #0x12]
	movs r0, #0x20
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091BB8:
	ldrb r0, [r4, #0x12]
	adds r3, r0, #0
	ldrb r2, [r4, #0x13]
	cmp r3, #0
	bne _08091BD4
	cmp r2, #0x55
	bhi _08091BD4
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091BDA
	.align 2, 0
_08091BD0: .4byte 0x08369894
_08091BD4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091BDA:
	strb r0, [r4, #0xa]
	adds r0, r3, #1
	movs r3, #0
	strb r0, [r4, #0x12]
	lsls r1, r2, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsrs r1, r1, #0x1c
	cmp r0, r1
	bne _08091BF4
	adds r0, r2, #3
	strb r0, [r4, #0x13]
	strb r3, [r4, #0x12]
_08091BF4:
	mov r0, r8
	adds r0, #0x52
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xc4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08091C46
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08091C50 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091C46:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091C50: .4byte gEnemyFnTable

	thumb_func_start FUN_08091c54
FUN_08091c54: @ 0x08091C54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x34
	mov r6, r8
	adds r6, #0x34
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08091C74
	cmp r5, #1
	beq _08091CAC
	b _08091D00
_08091C74:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091CBC @ =0x08369894
	bl SetDDP
	ldr r1, [r6, #8]
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r7, #0
	bl InitScalerotSprite1
	ldrb r1, [r4, #0xa]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	strb r5, [r4, #0x12]
	movs r0, #0x59
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091CAC:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _08091CC0
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091CC6
	.align 2, 0
_08091CBC: .4byte 0x08369894
_08091CC0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091CC6:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	ldrb r2, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsrs r1, r2, #4
	cmp r0, r1
	bne _08091CE0
	movs r0, #0
	strb r0, [r4, #0x12]
	subs r0, r2, #3
	strb r0, [r4, #0x13]
_08091CE0:
	mov r0, r8
	adds r0, #0x52
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x52
	movs r2, #0
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xc4
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08091D00
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
_08091D00:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08091d0c
FUN_08091d0c:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0xA0, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28, 0x25, 0xD0, 0x3B, 0xE0, 0x20, 0x1C, 0x74, 0x30
	.byte 0x1E, 0x49, 0x75, 0xF7, 0x77, 0xFA, 0x20, 0x1C, 0x85, 0xF7, 0xEC, 0xFA, 0xA1, 0x7C, 0x49, 0x06
	.byte 0xF8, 0x20, 0x80, 0x05, 0x09, 0x18, 0x1A, 0x4A, 0x80, 0x23, 0xDB, 0x05, 0xC8, 0x18, 0xC0, 0x0D
	.byte 0x80, 0x18, 0x00, 0x23, 0xC0, 0x5E, 0x80, 0x00, 0xE0, 0x65, 0xC9, 0x0D, 0x89, 0x18, 0x00, 0x22
	.byte 0x88, 0x5E, 0x80, 0x00, 0x20, 0x66, 0x88, 0x21, 0x09, 0x02, 0x20, 0x1C, 0x85, 0xF7, 0x04, 0xFC
	.byte 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x60, 0x6D, 0xE1, 0x6D, 0x40, 0x18, 0x60, 0x65, 0xA1, 0x6D
	.byte 0x22, 0x6E, 0x89, 0x18, 0xA1, 0x65, 0x77, 0xF7, 0x0B, 0xFE, 0x01, 0x1C, 0x00, 0x29, 0x06, 0xDA
	.byte 0xA0, 0x6D, 0x40, 0x18, 0xA0, 0x65, 0x00, 0x21, 0x07, 0x20, 0x60, 0x73, 0xA1, 0x73, 0x20, 0x1C
	.byte 0x85, 0xF7, 0x64, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xF4, 0x98, 0x36, 0x08
	.byte 0x74, 0xEA, 0x0F, 0x08

	thumb_func_start FUN_08091da4
FUN_08091da4: @ 0x08091DA4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08091DB4
	cmp r0, #1
	beq _08091E26
	b _08091E4E
_08091DB4:
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091DE8 @ =0x08369924
	bl SetDDP
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08091DEC @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _08091DF0 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	lsrs r2, r0, #1
	cmp r2, #0
	beq _08091DF4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08091DFA
	.align 2, 0
_08091DE8: .4byte 0x08369924
_08091DEC: .4byte 0xFFFFFE80
_08091DF0: .4byte 0xFFFFFC00
_08091DF4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08091DFA:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldr r1, _08091E54 @ =0x00008801
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091E26:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	cmp r0, #0
	ble _08091E40
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08091E40:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08091E4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091E54: .4byte 0x00008801

	thumb_func_start FUN_08091e58
FUN_08091e58: @ 0x08091E58
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08091E86
	cmp r0, #1
	bgt _08091E6E
	cmp r0, #0
	beq _08091E78
	b _08091EF6
_08091E6E:
	cmp r0, #2
	beq _08091EC4
	cmp r0, #3
	beq _08091ECE
	b _08091EF6
_08091E78:
	ldr r1, _08091EC0 @ =0x00008802
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091E86:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _08091EB8
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091EB8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08091EF6
	.align 2, 0
_08091EC0: .4byte 0x00008802
_08091EC4:
	movs r0, #0xc0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091ECE:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08091EE0
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _08091EF6
_08091EE0:
	ldr r1, _08091EFC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #3
	strb r0, [r4, #0xd]
_08091EF6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091EFC: .4byte gEnemyFnTable

	thumb_func_start FUN_08091f00
FUN_08091f00: @ 0x08091F00
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08091F10
	cmp r0, #1
	beq _08091F38
	b _08091F90
_08091F10:
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _08091F98 @ =0xFFFFFD00
	str r0, [r4, #0x5c]
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bge _08091F2C
	movs r1, #0xc0
	lsls r1, r1, #2
_08091F2C:
	str r1, [r4, #0x5c]
	ldr r0, _08091F9C @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091F38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _08091FA0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _08091F90
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
	ldr r1, _08091FA4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091F90:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091F98: .4byte 0xFFFFFD00
_08091F9C: .4byte 0xFFFFFE00
_08091FA0: .4byte gStageRun+232
_08091FA4: .4byte gEnemyFnTable

	thumb_func_start FUN_08091fa8
FUN_08091fa8: @ 0x08091FA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _08092016
	cmp r0, #1
	bgt _08091FC2
	cmp r0, #0
	beq _08091FCC
	b _080921A6
_08091FC2:
	cmp r0, #2
	beq _08092044
	cmp r0, #3
	beq _0809204E
	b _080921A6
_08091FCC:
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r2, [r7, #0x13]
	cmp r2, #0
	beq _08091FE0
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08091FE6
_08091FE0:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_08091FE6:
	strb r0, [r7, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08092040 @ =0x00001303
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x12
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08092016:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08092030
	adds r0, r7, #0
	bl FUN_08091280
_08092030:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _08092038
	b _080921A6
_08092038:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080921A6
	.align 2, 0
_08092040: .4byte 0x00001303
_08092044:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809204E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08092060
	movs r0, #0x2a
	bl PlaySound
_08092060:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08092072
	b _080921A6
_08092072:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _08092094 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r4, _08092098 @ =0x083697F4
	ldrb r2, [r7, #0x13]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0809209C
	orrs r3, r2
	b _0809209E
	.align 2, 0
_08092094: .4byte 0xFFFFE800
_08092098: .4byte 0x083697F4
_0809209C:
	adds r3, r2, #0
_0809209E:
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r5, _080920C0 @ =0x08369810
	ldrb r2, [r7, #0x13]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080920C4
	orrs r3, r2
	b _080920C6
	.align 2, 0
_080920C0: .4byte 0x08369810
_080920C4:
	adds r3, r2, #0
_080920C6:
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r5, _080920E8 @ =0x0836982C
	ldrb r2, [r7, #0x13]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080920EC
	orrs r3, r2
	b _080920EE
	.align 2, 0
_080920E8: .4byte 0x0836982C
_080920EC:
	adds r3, r2, #0
_080920EE:
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r0, [r7, #0x58]
	ldr r1, _080921B4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r3, _080921B8 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r2, _080921BC @ =0x000343FD
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r5, _080921C0 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r8, r0
	lsrs r1, r1, #0x11
	movs r6, #0x1f
	ands r1, r6
	movs r4, #0x10
	subs r1, r4, r1
	lsls r1, r1, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	bl CreateSmoke
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r6
	subs r4, r4, r0
	lsls r4, r4, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080921C4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
_080921A6:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080921B4: .4byte 0xFFFFF000
_080921B8: .4byte RNG_0202f388
_080921BC: .4byte 0x000343FD
_080921C0: .4byte 0x00269EC3
_080921C4: .4byte gEnemyFnTable

	thumb_func_start FUN_080921c8
FUN_080921c8: @ 0x080921C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08092230
	cmp r0, #1
	bgt _080921DC
	cmp r0, #0
	beq _080921E6
	b _080922D6
_080921DC:
	cmp r0, #2
	beq _0809225C
	cmp r0, #3
	beq _08092266
	b _080922D6
_080921E6:
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	beq _080921FA
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08092200
_080921FA:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08092200:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
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
	ldr r1, _08092258 @ =0x00001303
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x12
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092230:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0809224A
	adds r0, r5, #0
	bl FUN_08091280
_0809224A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080922D6
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080922D6
	.align 2, 0
_08092258: .4byte 0x00001303
_0809225C:
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092266:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08092278
	movs r0, #0x2a
	bl PlaySound
_08092278:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080922D6
	adds r4, r5, #0
	adds r4, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	ldrb r3, [r5, #0x13]
	adds r0, r4, #0
	movs r1, #0
	bl CreateGhost18
	ldr r6, _080922B4 @ =0x08369848
	ldrb r2, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080922B8
	orrs r3, r2
	b _080922BA
	.align 2, 0
_080922B4: .4byte 0x08369848
_080922B8:
	adds r3, r2, #0
_080922BA:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r1, _080922DC @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080922D6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080922DC: .4byte gEnemyFnTable

	thumb_func_start FUN_080922e0
FUN_080922e0: @ 0x080922E0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08092348
	cmp r0, #1
	bgt _080922F4
	cmp r0, #0
	beq _080922FE
	b _080923E2
_080922F4:
	cmp r0, #2
	beq _08092374
	cmp r0, #3
	beq _0809237E
	b _080923E2
_080922FE:
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	beq _08092312
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08092318
_08092312:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08092318:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
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
	ldr r1, _08092370 @ =0x00001303
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x12
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092348:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08092362
	adds r0, r5, #0
	bl FUN_08091280
_08092362:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080923E2
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080923E2
	.align 2, 0
_08092370: .4byte 0x00001303
_08092374:
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809237E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08092390
	movs r0, #0x2a
	bl PlaySound
_08092390:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	adds r4, r5, #0
	adds r4, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	ldrb r3, [r5, #0x13]
	adds r0, r4, #0
	movs r1, #0
	bl CreateGhost18
	ldr r6, _080923C0 @ =0x08369848
	ldrb r2, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080923C4
	orrs r3, r2
	b _080923C6
	.align 2, 0
_080923C0: .4byte 0x08369848
_080923C4:
	adds r3, r2, #0
_080923C6:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r1, _080923E8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080923E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080923E8: .4byte gEnemyFnTable

	thumb_func_start FUN_080923ec
FUN_080923ec: @ 0x080923EC
	push {r4, lr}
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
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0809243C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _08092440 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809243C: .4byte 0xFFFFF800
_08092440: .4byte gEnemyFnTable
