	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start mothjiro_080885fc
mothjiro_080885fc: @ 0x080885FC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	beq _0808860C
	cmp r7, #1
	beq _08088688
	b _08088894
_0808860C:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080886C8 @ =0x083687C8
	bl SetDDP
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, _080886CC @ =0xFFFFF000
	adds r1, r1, r0
	ldr r5, _080886D0 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r3, _080886D4 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080886D8 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsls r0, r0, #2
	lsrs r0, r0, #0x13
	adds r1, r1, r0
	str r1, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xbc
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r1]
	adds r1, r1, r0
	str r1, [r6, #0x68]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r6, #0x12]
	strb r7, [r6, #0x13]
	strb r7, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08088688:
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08088710
	ldrb r3, [r6, #0xa]
	movs r4, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _080886E4
	ldr r0, [r6, #0x54]
	ldr r1, _080886DC @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	ldr r1, _080886E0 @ =0xFFFFD000
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r4, #0
	orrs r0, r3
	b _08088780
	.align 2, 0
_080886C8: .4byte 0x083687C8
_080886CC: .4byte 0xFFFFF000
_080886D0: .4byte RNG_0202f388
_080886D4: .4byte 0x000343FD
_080886D8: .4byte 0x00269EC3
_080886DC: .4byte 0xFFFFFE80
_080886E0: .4byte 0xFFFFD000
_080886E4:
	ldr r0, [r6, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r3, #0
	orrs r0, r4
	b _08088780
_08088710:
	ldrb r3, [r6, #0xa]
	movs r4, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _08088750
	ldr r0, [r6, #0x54]
	ldr r1, _08088748 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	ldr r1, _0808874C @ =0xFFFFD000
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r4, #0
	orrs r0, r3
	b _08088780
	.align 2, 0
_08088748: .4byte 0xFFFFFE80
_0808874C: .4byte 0xFFFFD000
_08088750:
	ldr r0, [r6, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r3, #0
	orrs r0, r4
	b _08088780
_0808877C:
	movs r0, #0xef
	ands r0, r3
_08088780:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0808879A:
	ldrb r4, [r6, #0x13]
	cmp r4, #7
	bhi _080887F8
	ldrb r3, [r6, #0x12]
	cmp r3, #0
	bne _080887D4
	ldr r0, [r6, #0x58]
	ldr r1, _080887CC @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808884E
	ldr r1, _080887D0 @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [r6, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r6, #0x12]
	adds r0, r4, #1
	b _0808884C
	.align 2, 0
_080887CC: .4byte 0xFFFFFB00
_080887D0: .4byte 0xFFFFF400
_080887D4:
	ldr r0, [r6, #0x58]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808884E
	adds r0, r2, r1
	str r0, [r6, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r6, #0x12]
	adds r0, r4, #1
	b _0808884C
_080887F8:
	ldrb r3, [r6, #0x12]
	cmp r3, #0
	bne _08088820
	ldr r0, [r6, #0x58]
	ldr r1, _08088818 @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088844
	ldr r1, _0808881C @ =0xFFFFE800
	b _08088836
	.align 2, 0
_08088818: .4byte 0xFFFFFB00
_0808881C: .4byte 0xFFFFE800
_08088820:
	ldr r0, [r6, #0x58]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088844
_08088836:
	adds r0, r2, r1
	str r0, [r6, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r6, #0x12]
	adds r0, r4, #1
	strb r0, [r6, #0x13]
_08088844:
	ldrb r0, [r6, #0x13]
	cmp r0, #0xa
	bls _0808884E
	movs r0, #0
_0808884C:
	strb r0, [r6, #0x13]
_0808884E:
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08088874
	adds r0, r6, #0
	adds r0, #0x54
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_08088874:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	bl FUN_08088ae0
	adds r2, r0, #0
	cmp r2, #0
	bne _08088894
	ldr r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	str r0, [r6, #0x64]
	str r1, [r6, #0x68]
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r2, [r6, #0xe]
_08088894:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

