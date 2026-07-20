	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080614a8
FUN_080614a8: @ 0x080614A8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080614B6
	b _080615D0
_080614B6:
	lsls r0, r0, #2
	ldr r1, _080614C0 @ =_080614C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080614C0: .4byte _080614C4
_080614C4: @ jump table
	.4byte _080614D8 @ case 0
	.4byte _08061524 @ case 1
	.4byte _08061560 @ case 2
	.4byte _080615A2 @ case 3
	.4byte _080615AC @ case 4
_080614D8:
	movs r0, #0xa7
	bl RemovePaletteAnimation
	movs r0, #0xa8
	bl RemovePaletteAnimation
	movs r0, #0xa9
	bl RemovePaletteAnimation
	movs r0, #0xaa
	bl RemovePaletteAnimation
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0xa9
	bl StartPaletteAnimation
	movs r0, #3
	strb r0, [r4, #0x13]
	ldr r2, _0806158C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08061590 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08061594 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	adds r1, r4, #0
	adds r1, #0xc8
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061524:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _08061598 @ =sOmegaZXProjectileTemplates
	adds r0, r4, #0
	adds r0, #0xc8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #3
	ldrb r1, [r4, #0x13]
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r0, r1, r3
	ldrh r2, [r0]
	adds r3, #4
	adds r1, r1, r3
	ldrb r3, [r1]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080affe4
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08061560:
	movs r0, #0xa9
	bl StepPaletteAnimation
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080615D0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080615D0
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806159C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080615D0
	.align 2, 0
_0806158C: .4byte RNG_0202f388
_08061590: .4byte 0x000343FD
_08061594: .4byte 0x00269EC3
_08061598: .4byte sOmegaZXProjectileTemplates
_0806159C:
	movs r0, #1
	strb r0, [r4, #0xe]
	b _080615D0
_080615A2:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080615AC:
	movs r0, #0xa9
	bl StepPaletteAnimation
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080615D0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080615D0
	movs r0, #0xa9
	bl RemovePaletteAnimation
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_080615D0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

