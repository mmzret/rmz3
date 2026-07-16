	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start mothjiro_080881dc
mothjiro_080881dc: @ 0x080881DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080881EC
	cmp r0, #1
	beq _0808827E
	b _08088496
_080881EC:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088240 @ =0x083687C8
	bl SetDDP
	ldr r2, _08088244 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08088248 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808824C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0x12]
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _08088250
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08088272
	.align 2, 0
_08088240: .4byte 0x083687C8
_08088244: .4byte RNG_0202f388
_08088248: .4byte 0x000343FD
_0808824C: .4byte 0x00269EC3
_08088250:
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08088272:
	movs r0, #0
	strb r0, [r4, #0x13]
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808827E:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080882EA
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _080882C4
	ldr r0, [r4, #0x54]
	ldr r2, _080882BC @ =0xFFFFFE80
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x64]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	ble _0808836A
	ldr r1, _080882C0 @ =0xFFFF4000
	adds r0, r2, r1
	str r0, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r5, #0
	orrs r0, r3
	b _08088350
	.align 2, 0
_080882BC: .4byte 0xFFFFFE80
_080882C0: .4byte 0xFFFF4000
_080882C4:
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	subs r0, r1, r0
	cmp r0, #0
	bge _0808836A
	str r1, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r3, #0
	orrs r0, r5
	b _08088350
_080882EA:
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _08088320
	ldr r0, [r4, #0x54]
	ldr r1, _0808831C @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	subs r0, r0, r1
	cmp r0, #0
	bge _0808836A
	str r1, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r5, #0
	orrs r0, r3
	b _08088350
	.align 2, 0
_0808831C: .4byte 0xFFFFFE80
_08088320:
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x64]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	ble _0808836A
	adds r0, r2, r1
	str r0, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r3, #0
	orrs r0, r5
	b _08088350
_0808834C:
	movs r0, #0xef
	ands r0, r3
_08088350:
	strb r0, [r4, #0xa]
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
_0808836A:
	ldrb r5, [r4, #0x13]
	cmp r5, #7
	bhi _080883C8
	ldrb r3, [r4, #0x12]
	cmp r3, #0
	bne _080883A4
	ldr r0, [r4, #0x58]
	ldr r1, _0808839C @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808841E
	ldr r1, _080883A0 @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r4, #0x12]
	adds r0, r5, #1
	b _0808841C
	.align 2, 0
_0808839C: .4byte 0xFFFFFB00
_080883A0: .4byte 0xFFFFF400
_080883A4:
	ldr r0, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808841E
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r4, #0x12]
	adds r0, r5, #1
	b _0808841C
_080883C8:
	ldrb r3, [r4, #0x12]
	cmp r3, #0
	bne _080883F0
	ldr r0, [r4, #0x58]
	ldr r1, _080883E8 @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088414
	ldr r1, _080883EC @ =0xFFFFE800
	b _08088406
	.align 2, 0
_080883E8: .4byte 0xFFFFFB00
_080883EC: .4byte 0xFFFFE800
_080883F0:
	ldr r0, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088414
_08088406:
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r4, #0x12]
	adds r0, r5, #1
	strb r0, [r4, #0x13]
_08088414:
	ldrb r0, [r4, #0x13]
	cmp r0, #0xa
	bls _0808841E
	movs r0, #0
_0808841C:
	strb r0, [r4, #0x13]
_0808841E:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08088444
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_08088444:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	bl FUN_08088ae0
	cmp r0, #0
	beq _08088496
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r4, #0x54]
	subs r6, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	subs r7, r1, r0
	asrs r0, r6, #2
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r7, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r1, r0, #0xe
	ldr r0, _0808849C @ =0x000077FF
	cmp r1, r0
	bgt _08088496
	adds r0, r4, #0
	adds r0, #0xb4
	str r1, [r0]
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08088496:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808849C: .4byte 0x000077FF

