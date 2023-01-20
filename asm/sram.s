	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start clear0x02001ee0
clear0x02001ee0: @ 0x080031F8
	ldr r1, _08003204 @ =0x02001EE0
	movs r0, #0
	strb r0, [r1]
	strh r0, [r1, #2]
	bx lr
	.align 2, 0
_08003204: .4byte 0x02001EE0

	thumb_func_start sramScript
sramScript: @ 0x08003208
	push {lr}
	ldr r0, _08003220 @ =0x02001EE0
	ldr r2, _08003224 @ =0x08338CC0
	ldrb r1, [r0, #2]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08003220: .4byte 0x02001EE0
_08003224: .4byte 0x08338CC0

	thumb_func_start checkSavedataCorrect
checkSavedataCorrect: @ 0x08003228
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r1, sp
	ldr r0, _0800324C @ =0x080FECAC
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	cmp r5, #5
	bls _08003254
	b _080032CA
	.align 2, 0
_0800324C: .4byte 0x080FECAC
_08003250:
	movs r0, #1
	b _080032CC
_08003254:
	movs r7, #3
	ldr r1, _080032DC @ =0x00000AAA
	adds r0, r5, #0
	muls r0, r1, r0
	mov sl, r0
	mov r4, sp
	ldr r2, _080032E0 @ =0x080FECBC
	mov r8, r2
	adds r0, r5, #6
	adds r3, r0, #0
	muls r3, r1, r3
	mov sb, r3
_0800326C:
	movs r0, #0xe0
	lsls r0, r0, #0x14
	add r0, sl
	mov r1, sp
	movs r2, #0x10
	bl ReadSram
	ldr r1, [sp]
	mov r2, r8
	ldr r0, [r2]
	cmp r1, r0
	bne _08003296
	ldr r0, [sp, #8]
	cmp r0, r6
	bne _08003296
	ldrb r0, [r4, #0xc]
	cmp r0, #0xb
	bne _08003296
	ldrb r0, [r4, #0xe]
	cmp r0, r5
	beq _08003250
_08003296:
	movs r0, #0xe0
	lsls r0, r0, #0x14
	add r0, sb
	mov r1, sp
	movs r2, #0x10
	bl ReadSram
	ldr r1, [sp]
	mov r3, r8
	ldr r0, [r3]
	cmp r1, r0
	bne _080032C0
	ldr r0, [sp, #8]
	cmp r0, r6
	bne _080032C0
	ldrb r0, [r4, #0xc]
	cmp r0, #0xb
	bne _080032C0
	ldrb r0, [r4, #0xe]
	cmp r0, r5
	beq _08003250
_080032C0:
	subs r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	bne _0800326C
_080032CA:
	movs r0, #0
_080032CC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080032DC: .4byte 0x00000AAA
_080032E0: .4byte 0x080FECBC

	thumb_func_start writeSramINTI
writeSramINTI: @ 0x080032E4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r0, #0
	str r0, [sp]
	cmp r7, #5
	bhi _08003324
	ldr r6, _08003320 @ =0x00000AAA
	adds r1, r7, #0
	muls r1, r6, r1
	movs r5, #0xe0
	lsls r5, r5, #0x14
	adds r1, r1, r5
	mov r0, sp
	movs r2, #4
	bl WriteSramEx
	adds r4, r0, #0
	adds r0, r7, #6
	adds r1, r0, #0
	muls r1, r6, r1
	adds r1, r1, r5
	mov r0, sp
	movs r2, #4
	bl WriteSramEx
	orrs r4, r0
	adds r0, r4, #0
	b _08003328
	.align 2, 0
_08003320: .4byte 0x00000AAA
_08003324:
	movs r0, #1
	rsbs r0, r0, #0
_08003328:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sram_08003330
sram_08003330: @ 0x08003330
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	cmp r2, #5
	bhi _0800336C
	ldr r3, _08003364 @ =0x02001EE0
	ldrb r1, [r3]
	cmp r1, #0
	bne _0800336C
	ldr r0, _08003368 @ =0x00000ABA
	cmp r4, r0
	bhi _0800336C
	strb r2, [r3, #1]
	str r5, [r3, #8]
	str r4, [r3, #0x14]
	strh r1, [r3, #0x1c]
	movs r0, #2
	strb r0, [r3]
	movs r0, #1
	strh r0, [r3, #2]
	movs r0, #0
	b _08003370
	.align 2, 0
_08003364: .4byte 0x02001EE0
_08003368: .4byte 0x00000ABA
_0800336C:
	movs r0, #1
	rsbs r0, r0, #0
_08003370:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sram_08003378
sram_08003378: @ 0x08003378
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r0, #0
	cmp r0, #5
	bhi _080033C4
	ldr r4, _080033BC @ =0x02001EE0
	ldrb r6, [r4]
	cmp r6, #0
	bne _080033C4
	adds r1, r5, #0
	bl checkSavedataCorrect
	cmp r0, #0
	beq _080033C4
	ldr r0, _080033C0 @ =0x00000ABA
	cmp r5, r0
	bhi _080033C4
	strb r7, [r4, #1]
	mov r0, r8
	str r0, [r4, #8]
	str r5, [r4, #0x14]
	strh r6, [r4, #0x1e]
	movs r0, #1
	strb r0, [r4]
	movs r0, #2
	strh r0, [r4, #2]
	movs r0, #0
	b _080033C8
	.align 2, 0
_080033BC: .4byte 0x02001EE0
_080033C0: .4byte 0x00000ABA
_080033C4:
	movs r0, #1
	rsbs r0, r0, #0
_080033C8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_080033d4
nop_080033d4: @ 0x080033D4
	bx lr
	.align 2, 0

	thumb_func_start saveSram
saveSram: @ 0x080033D8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r5, #0x82
	lsls r5, r5, #4
	ldrb r1, [r4, #3]
	cmp r1, #1
	beq _08003408
	cmp r1, #1
	bgt _080033F2
	cmp r1, #0
	beq _080033FE
	b _08003526
_080033F2:
	cmp r1, #2
	beq _080034A0
	cmp r1, #3
	bne _080033FC
	b _08003500
_080033FC:
	b _08003526
_080033FE:
	movs r0, #3
	strh r0, [r4, #4]
	strh r1, [r4, #6]
	movs r0, #1
	strb r0, [r4, #3]
_08003408:
	ldr r0, [r4, #8]
	str r0, [r4, #0xc]
	ldrh r1, [r4, #6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldrb r1, [r4, #1]
	adds r0, r0, r1
	ldr r1, _08003484 @ =0x00000AAA
	muls r0, r1, r0
	movs r2, #0xe0
	lsls r2, r2, #0x14
	adds r0, r0, r2
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x14]
	str r0, [r4, #0x18]
	adds r5, r0, #0
	ldr r0, _08003488 @ =0x080FECBC
	ldr r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r3, r5, #0
	ldrb r6, [r4, #1]
	cmp r5, #0
	beq _08003450
_0800343C:
	ldr r0, [r4, #0xc]
	ldrb r2, [r0]
	ldr r1, [sp, #4]
	adds r1, r1, r2
	str r1, [sp, #4]
	adds r0, #1
	str r0, [r4, #0xc]
	subs r5, #1
	cmp r5, #0
	bne _0800343C
_08003450:
	str r3, [sp, #8]
	mov r1, sp
	movs r0, #0xb
	strb r0, [r1, #0xc]
	movs r0, #6
	strb r0, [r1, #0xd]
	mov r0, sp
	strb r6, [r0, #0xe]
	movs r0, #1
	strb r0, [r1, #0xf]
	ldr r1, [r4, #0x10]
	mov r0, sp
	movs r2, #0x10
	bl WriteSramEx
	cmp r0, #0
	beq _08003490
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	ldr r1, _0800348C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08003526
	b _080034D4
	.align 2, 0
_08003484: .4byte 0x00000AAA
_08003488: .4byte 0x080FECBC
_0800348C: .4byte 0x0000FFFF
_08003490:
	ldr r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x10]
	adds r0, #0x10
	str r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #3]
	b _08003526
_080034A0:
	ldr r0, [r4, #0x18]
	cmp r0, r5
	bhi _080034AC
	adds r5, r0, #0
	movs r0, #3
	strb r0, [r4, #3]
_080034AC:
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	adds r2, r5, #0
	bl WriteSramEx
	cmp r0, #0
	beq _080034E8
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	ldr r1, _080034D0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080034D4
	movs r0, #1
	strb r0, [r4, #3]
	b _08003526
	.align 2, 0
_080034D0: .4byte 0x0000FFFF
_080034D4:
	ldr r0, _080034E4 @ =0x02001EE0
	ldrh r1, [r0, #0x1c]
	orrs r1, r2
	strh r1, [r0, #0x1c]
	movs r0, #3
	strb r0, [r4, #3]
	b _08003526
	.align 2, 0
_080034E4: .4byte 0x02001EE0
_080034E8:
	ldr r0, [r4, #0xc]
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x10]
	adds r0, r0, r1
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x18]
	subs r0, r0, r5
	str r0, [r4, #0x18]
	b _08003526
_08003500:
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _08003512
	strh r1, [r4, #4]
	movs r1, #1
	movs r0, #1
	strh r0, [r4, #6]
	strb r1, [r4, #3]
	b _08003526
_08003512:
	ldr r1, _08003530 @ =0x02001EE0
	movs r2, #0x1c
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _08003520
	movs r0, #1
	strh r0, [r1, #0x1c]
_08003520:
	movs r0, #0
	strb r0, [r4]
	strh r0, [r4, #2]
_08003526:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003530: .4byte 0x02001EE0

	thumb_func_start loadSram
loadSram: @ 0x08003534
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #3]
	cmp r1, #1
	beq _0800355C
	cmp r1, #1
	bgt _08003548
	cmp r1, #0
	beq _08003552
	b _0800368E
_08003548:
	cmp r1, #2
	beq _080035D0
	cmp r1, #3
	beq _08003602
	b _0800368E
_08003552:
	movs r0, #3
	strh r0, [r5, #4]
	strh r1, [r5, #6]
	movs r0, #1
	strb r0, [r5, #3]
_0800355C:
	ldr r0, [r5, #8]
	str r0, [r5, #0xc]
	ldr r0, [r5, #0x14]
	str r0, [r5, #0x18]
	ldrh r1, [r5, #6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldrb r1, [r5, #1]
	adds r0, r0, r1
	ldr r1, _080035B0 @ =0x00000AAA
	muls r0, r1, r0
	movs r2, #0xe0
	lsls r2, r2, #0x14
	adds r0, r0, r2
	str r0, [r5, #0x10]
	ldr r4, _080035B4 @ =0x02000010
	adds r1, r4, #0
	movs r2, #0x10
	bl ReadSram
	ldr r0, _080035B8 @ =0x080FECBC
	ldr r1, [r4]
	ldr r0, [r0]
	cmp r1, r0
	beq _080035C4
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
	ldr r1, _080035BC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800368E
	ldr r0, _080035C0 @ =0x02001EE0
	ldrh r1, [r0, #0x1e]
	orrs r1, r2
	strh r1, [r0, #0x1e]
	movs r0, #3
	strb r0, [r5, #3]
	b _0800368E
	.align 2, 0
_080035B0: .4byte 0x00000AAA
_080035B4: .4byte 0x02000010
_080035B8: .4byte 0x080FECBC
_080035BC: .4byte 0x0000FFFF
_080035C0: .4byte 0x02001EE0
_080035C4:
	ldr r0, [r5, #0x10]
	adds r0, #0x10
	str r0, [r5, #0x10]
	movs r0, #2
	strb r0, [r5, #3]
	b _0800368E
_080035D0:
	movs r4, #0x82
	lsls r4, r4, #4
	ldr r0, [r5, #0x18]
	cmp r0, r4
	bhi _080035E0
	adds r4, r0, #0
	movs r0, #3
	strb r0, [r5, #3]
_080035E0:
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0xc]
	adds r2, r4, #0
	bl ReadSram
	ldr r0, [r5, #0xc]
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r5, #0xc]
	ldr r0, [r5, #0x10]
	adds r0, r0, r1
	str r0, [r5, #0x10]
	ldr r0, [r5, #0x18]
	subs r0, r0, r4
	str r0, [r5, #0x18]
	b _0800368E
_08003602:
	ldr r0, _0800364C @ =0x02001EE0
	movs r2, #0x1e
	ldrsh r1, [r0, r2]
	adds r6, r0, #0
	cmp r1, #0
	bne _08003666
	ldr r0, [r5, #8]
	str r0, [r5, #0xc]
	ldr r4, [r5, #0x14]
	ldr r7, _08003650 @ =0x02000010
	cmp r4, #0
	beq _08003630
	adds r3, r7, #0
_0800361C:
	ldr r0, [r5, #0xc]
	ldrb r2, [r0]
	ldr r1, [r3, #4]
	subs r1, r1, r2
	str r1, [r3, #4]
	adds r0, #1
	str r0, [r5, #0xc]
	subs r4, #1
	cmp r4, #0
	bne _0800361C
_08003630:
	ldr r0, [r7, #4]
	cmp r0, #0
	beq _0800365E
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
	ldr r2, _08003654 @ =0x0000FFFF
	adds r1, r2, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08003658
	movs r0, #1
	strb r0, [r5, #3]
	b _0800368E
	.align 2, 0
_0800364C: .4byte 0x02001EE0
_08003650: .4byte 0x02000010
_08003654: .4byte 0x0000FFFF
_08003658:
	ldrh r0, [r6, #0x1e]
	orrs r0, r1
	strh r0, [r6, #0x1e]
_0800365E:
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08003684
_08003666:
	ldrh r0, [r5, #6]
	cmp r0, #0
	bne _0800367C
	strh r0, [r6, #0x1e]
	movs r0, #3
	strh r0, [r5, #4]
	movs r1, #1
	movs r0, #1
	strh r0, [r5, #6]
	strb r1, [r5, #3]
	b _0800368E
_0800367C:
	movs r2, #0x1e
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bne _08003688
_08003684:
	movs r0, #1
	strh r0, [r6, #0x1e]
_08003688:
	movs r0, #0
	strb r0, [r5]
	strh r0, [r5, #2]
_0800368E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
