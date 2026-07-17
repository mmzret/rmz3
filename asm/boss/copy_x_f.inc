	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start copyx_080577c8
copyx_080577c8: @ 0x080577C8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08057836
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #1
	beq _08057824
	cmp r0, #1
	bgt _080577E8
	cmp r0, #0
	beq _080577F2
	b _080578D6
_080577E8:
	cmp r0, #2
	beq _0805782A
	cmp r0, #3
	beq _08057830
	b _080578D6
_080577F2:
	ldr r0, _0805781C @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	asrs r0, r0, #8
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080578B0
	movs r0, #9
	strb r0, [r4, #0xd]
	movs r0, #0x15
	strb r0, [r4, #0xf]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x58
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _08057820 @ =0xFFFFFA80
	b _080578D4
	.align 2, 0
_0805781C: .4byte pZero2
_08057820: .4byte 0xFFFFFA80
_08057824:
	movs r0, #0x1c
	strb r0, [r4, #0xd]
	b _080578D6
_0805782A:
	movs r0, #0x1a
	strb r0, [r4, #0xd]
	b _080578D6
_08057830:
	movs r0, #0x1e
	strb r0, [r4, #0xd]
	b _080578D6
_08057836:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805786C
	ldr r2, _08057860 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08057864 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08057868 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #9
	bhi _080578A0
	b _08057888
	.align 2, 0
_08057860: .4byte RNG_0202f388
_08057864: .4byte 0x000343FD
_08057868: .4byte 0x00269EC3
_0805786C:
	ldr r2, _08057894 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08057898 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805789C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #5
	bhi _080578A0
_08057888:
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	b _080578D6
	.align 2, 0
_08057894: .4byte RNG_0202f388
_08057898: .4byte 0x000343FD
_0805789C: .4byte 0x00269EC3
_080578A0:
	ldr r0, _080578B8 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	asrs r0, r0, #9
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080578BC
_080578B0:
	movs r0, #0x11
	strb r0, [r4, #0xd]
	b _080578D6
	.align 2, 0
_080578B8: .4byte pZero2
_080578BC:
	movs r0, #9
	strb r0, [r4, #0xd]
	movs r0, #0x15
	strb r0, [r4, #0xf]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x50
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _080578DC @ =0xFFFFFB00
_080578D4:
	str r0, [r4, #0x60]
_080578D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080578DC: .4byte 0xFFFFFB00

	thumb_func_start copyx_080578e0
copyx_080578e0: @ 0x080578E0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r3, #0
	movs r2, #0
	ldr r0, _08057960 @ =RNG_0202f388
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0xdc
	ldrb r1, [r0]
	movs r6, #1
	adds r5, r0, #0
_080578F8:
	adds r0, r1, #0
	asrs r0, r2
	ands r0, r6
	cmp r0, #0
	beq _0805790A
	mov r7, sp
	adds r0, r7, r3
	strb r2, [r0]
	adds r3, #1
_0805790A:
	adds r2, #1
	cmp r2, #3
	ble _080578F8
	mov r0, ip
	ldr r1, [r0]
	ldr r0, _08057964 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08057968 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, ip
	str r1, [r2]
	lsrs r0, r0, #0x11
	adds r1, r3, #0
	bl __umodsi3
	movs r1, #5
	strb r1, [r4, #0xd]
	mov r7, sp
	adds r2, r7, r0
	ldrb r0, [r2]
	strb r0, [r4, #0xf]
	movs r4, #1
	adds r0, r4, #0
	ldrb r1, [r2]
	lsls r0, r1
	movs r3, #0xf
	eors r0, r3
	ldrb r1, [r5]
	ands r0, r1
	strb r0, [r5]
	cmp r0, #0
	bne _08057958
	adds r0, r4, #0
	ldrb r2, [r2]
	lsls r0, r2
	eors r0, r3
	strb r0, [r5]
_08057958:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08057960: .4byte RNG_0202f388
_08057964: .4byte 0x000343FD
_08057968: .4byte 0x00269EC3

