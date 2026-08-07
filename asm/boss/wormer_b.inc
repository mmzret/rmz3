	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08042ff8
FUN_08042ff8: @ 0x08042FF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _0804303A
	cmp r0, #1
	bgt _08043014
	cmp r0, #0
	beq _08043022
	b _080431F4
_08043014:
	cmp r0, #2
	bne _0804301A
	b _080431D0
_0804301A:
	cmp r0, #3
	bne _08043020
	b _080431DA
_08043020:
	b _080431F4
_08043022:
	ldr r0, _080431B0 @ =0x00000129
	bl PlaySound
	movs r0, #0x14
	strb r0, [r7, #0x12]
	ldr r1, _080431B4 @ =0x00002B06
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804303A:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804304C
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0804304C:
	ldrb r0, [r7, #0x12]
	cmp r0, #0xf
	bhi _08043138
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043138
	ldr r5, _080431B8 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r1, _080431BC @ =0x000343FD
	mov sl, r1
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _080431C0 @ =0x00269EC3
	mov sb, r1
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #0xc
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	subs r0, r4, r0
	movs r2, #0x80
	lsls r2, r2, #5
	mov r8, r2
	add r0, r8
	ldr r4, [r7, #0x54]
	subs r4, r4, r0
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r2, _080431C4 @ =gStageRun+232
	ldr r1, [r2, #0x3c]
	subs r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807b184
	ldr r0, [r5]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #0xc
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	subs r0, r4, r0
	add r8, r0
	ldr r4, [r7, #0x54]
	mov r2, r8
	subs r4, r4, r2
	mov r0, sl
	muls r0, r6, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r2, _080431C4 @ =gStageRun+232
	ldr r1, [r2, #0x3c]
	subs r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807b184
_08043138:
	ldrb r1, [r7, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080431A6
	ldr r4, _080431B8 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080431BC @ =0x000343FD
	mov sl, r1
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _080431C0 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r2, #0xa0
	lsls r2, r2, #5
	mov sb, r2
	mov r1, sb
	bl __umodsi3
	ldr r6, _080431C8 @ =0xFFFFCF00
	adds r0, r0, r6
	ldr r2, [r7, #0x54]
	adds r2, r2, r0
	ldr r1, [r7, #0x58]
	ldr r5, _080431CC @ =0xFFFFBE00
	adds r1, r1, r5
	adds r0, r2, #0
	bl FUN_0807b0d0
	ldr r0, [r4]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	mov r1, sb
	bl __umodsi3
	adds r0, r0, r6
	ldr r2, [r7, #0x54]
	adds r2, r2, r0
	ldr r1, [r7, #0x58]
	adds r1, r1, r5
	adds r0, r2, #0
	bl FUN_0807b0d0
_080431A6:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _080431F4
	.align 2, 0
_080431B0: .4byte 0x00000129
_080431B4: .4byte 0x00002B06
_080431B8: .4byte RNG_0202f388
_080431BC: .4byte 0x000343FD
_080431C0: .4byte 0x00269EC3
_080431C4: .4byte gStageRun+232
_080431C8: .4byte 0xFFFFCF00
_080431CC: .4byte 0xFFFFBE00
_080431D0:
	movs r0, #0x10
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080431DA:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080431EE
	movs r0, #5
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_080431EE:
	adds r0, r7, #0
	bl UpdateEntityAnim
_080431F4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
