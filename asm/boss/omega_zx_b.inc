	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080610a8
FUN_080610a8: @ 0x080610A8
	movs r0, #1
	bx lr

	thumb_func_start Boss22Neutral
Boss22Neutral: @ 0x080610AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080610C0
	cmp r4, #1
	beq _080610E6
	b _08061216
_080610C0:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080610D8 @ =sCollisions+24
	bl SetDDP
	ldrb r0, [r5, #0xf]
	cmp r0, #0xff
	bne _080610DC
	movs r0, #1
	strb r0, [r5, #0x13]
	strb r4, [r5, #0xf]
	b _080610E0
	.align 2, 0
_080610D8: .4byte sCollisions+24
_080610DC:
	movs r0, #0x78
	strb r0, [r5, #0x13]
_080610E0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080610E6:
	adds r0, r5, #0
	bl FUN_080616fc
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _080610F4
	b _08061216
_080610F4:
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08061102
	b _08061216
_08061102:
	adds r0, r5, #0
	adds r0, #0xb5
	adds r1, r5, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r7, r0, #0
	mov r8, r1
	cmp r3, r2
	bne _080611B4
	subs r0, #0x11
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bgt _0806116C
	ldr r2, _0806115C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08061160 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08061164 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _08061168 @ =gOmegaZXMode2
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _0806120A
	adds r0, r5, #0
	bl FUN_08061648
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0806120A
	.align 2, 0
_0806115C: .4byte RNG_0202f388
_08061160: .4byte 0x000343FD
_08061164: .4byte 0x00269EC3
_08061168: .4byte gOmegaZXMode2
_0806116C:
	ldr r2, _080611A4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080611A8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080611AC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _080611B0 @ =gOmegaZXMode1
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	bne _0806120A
	adds r0, r5, #0
	bl FUN_08061648
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0806120A
	.align 2, 0
_080611A4: .4byte RNG_0202f388
_080611A8: .4byte 0x000343FD
_080611AC: .4byte 0x00269EC3
_080611B0: .4byte gOmegaZXMode1
_080611B4:
	adds r0, r5, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x20
	bgt _080611E8
	ldr r2, _080611D8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080611DC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080611E0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _080611E4 @ =gOmegaZXMode2
	b _080611FE
	.align 2, 0
_080611D8: .4byte RNG_0202f388
_080611DC: .4byte 0x000343FD
_080611E0: .4byte 0x00269EC3
_080611E4: .4byte gOmegaZXMode2
_080611E8:
	ldr r2, _08061220 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08061224 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08061228 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r4, _0806122C @ =gOmegaZXMode1
_080611FE:
	ldrb r1, [r4]
	bl __umodsi3
	adds r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
_0806120A:
	strb r1, [r5, #0xd]
	strb r6, [r5, #0xe]
	ldrb r0, [r7]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r7]
_08061216:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061220: .4byte RNG_0202f388
_08061224: .4byte 0x000343FD
_08061228: .4byte 0x00269EC3
_0806122C: .4byte gOmegaZXMode1

