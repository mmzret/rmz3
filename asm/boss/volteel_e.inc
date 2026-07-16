	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelMode5
volteelMode5: @ 0x080440C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xc
	bls _080440D8
	bl _080449DC
_080440D8:
	lsls r0, r0, #2
	ldr r1, _080440E4 @ =_080440E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080440E4: .4byte _080440E8
_080440E8: @ jump table
	.4byte _0804411C @ case 0
	.4byte _080441E8 @ case 1
	.4byte _08044256 @ case 2
	.4byte _0804426E @ case 3
	.4byte _08044294 @ case 4
	.4byte _0804432A @ case 5
	.4byte _080443A0 @ case 6
	.4byte _080443B2 @ case 7
	.4byte _080443E4 @ case 8
	.4byte _08044426 @ case 9
	.4byte _08044666 @ case 10
	.4byte _080448FA @ case 11
	.4byte _08044964 @ case 12
_0804411C:
	adds r0, r6, #0
	adds r0, #0xdc
	ldr r2, [r6, #0x54]
	ldr r3, [r0]
	subs r1, r2, r3
	adds r7, r0, #0
	cmp r1, #0
	bgt _0804412E
	subs r1, r3, r2
_0804412E:
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r4, [r0]
	subs r3, r2, r4
	adds r5, r0, #0
	cmp r3, #0
	ble _08044142
	cmp r1, r3
	bgt _08044148
	b _0804417E
_08044142:
	subs r0, r4, r2
	cmp r1, r0
	ble _0804417E
_08044148:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804416C
	ldr r1, _08044168 @ =0x0000A507
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _08044170
	.align 2, 0
_08044168: .4byte 0x0000A507
_0804416C:
	ldrb r0, [r6, #0xe]
	adds r0, #2
_08044170:
	strb r0, [r6, #0xe]
	ldr r0, [r7]
	str r0, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xca
	movs r0, #3
	b _080441B0
_0804417E:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080441A0
	ldr r1, _0804419C @ =0x0000A507
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080441A4
	.align 2, 0
_0804419C: .4byte 0x0000A507
_080441A0:
	ldrb r0, [r6, #0xe]
	adds r0, #2
_080441A4:
	strb r0, [r6, #0xe]
	ldr r0, [r5]
	str r0, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xca
	movs r0, #1
_080441B0:
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xd8
	adds r2, r6, #0
	adds r2, #0xd4
	ldr r1, [r0]
	ldr r0, [r2]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r0, #0x90
	lsls r0, r0, #5
	adds r1, r1, r0
	str r1, [r6, #0x68]
	ldr r0, _080441E0 @ =0xFFFFFE30
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080441E4 @ =sCollisions+(24*1)
	bl SetDDP
	bl _080449DC
	.align 2, 0
_080441E0: .4byte 0xFFFFFE30
_080441E4: .4byte sCollisions+(24*1)
_080441E8:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08044248 @ =0x0000A507
	cmp r0, r1
	beq _08044204
	bl _080449DC
_08044204:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08044212
	bl _080449DC
_08044212:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _0804424C
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08044252
	.align 2, 0
_08044248: .4byte 0x0000A507
_0804424C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_08044252:
	strb r0, [r6, #0xa]
	b _0804495C
_08044256:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804428C @ =0x08362378
	bl SetDDP
	ldr r1, _08044290 @ =0x0000A501
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804426E:
	ldr r1, [r6, #0x60]
	adds r1, #0x10
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r1, #0
	ble _08044284
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08044284:
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _080449DC
	.align 2, 0
_0804428C: .4byte sCollisions+(3*24)
_08044290: .4byte 0x0000A501
_08044294:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	subs r1, r1, r2
	str r1, [r6, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _080442DA
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x60]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x60]
_080442DA:
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xc4
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xcc
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r1]
	movs r4, #0
	movs r0, #0x14
	strb r0, [r6, #0x12]
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x7a
	bl PlaySound
	ldr r1, _08044394 @ =0x0000A511
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804432A:
	ldrb r0, [r6, #0x13]
	adds r4, r6, #0
	adds r4, #0x71
	cmp r0, #0
	bne _0804434A
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _0804434A
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08044398 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #1
	strb r0, [r6, #0x13]
_0804434A:
	ldrb r0, [r6, #0x13]
	cmp r0, #1
	bne _08044366
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bne _08044366
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804439C @ =sCollisions
	bl SetDDP
	movs r0, #2
	strb r0, [r6, #0x13]
_08044366:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	ble _0804437E
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
_0804437E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08044390
	b _080449DC
_08044390:
	b _0804495C
	.align 2, 0
_08044394: .4byte 0x0000A511
_08044398: .4byte sCollisions+(24*1)
_0804439C: .4byte sCollisions
_080443A0:
	ldr r1, _080443E0 @ =0x0000A512
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080443B2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080443D8
	b _0804492C
_080443D8:
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	b _08044932
	.align 2, 0
_080443E0: .4byte 0x0000A512
_080443E4:
	movs r1, #0
	movs r0, #0x1e
	strb r0, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, #0x28
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	movs r1, #0xef
	ands r1, r0
	ldr r0, [r6, #0x64]
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x68]
	str r0, [r6, #0x58]
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08044468 @ =sCollisions
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08044426:
	movs r4, #0
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _08044436
	b _080449DC
_08044436:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08044442
	b _080449DC
_08044442:
	adds r0, r6, #0
	adds r0, #0xb5
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #9
	bne _08044472
	adds r1, r6, #0
	adds r1, #0xc8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #3
	bhi _0804446C
	movs r4, #1
	b _0804447A
	.align 2, 0
_08044468: .4byte sCollisions
_0804446C:
	mov r0, sb
	strb r4, [r0]
	b _0804447A
_08044472:
	adds r0, r6, #0
	adds r0, #0xc8
	strb r4, [r0]
	mov sb, r0
_0804447A:
	cmp r4, #1
	bne _0804448E
	movs r4, #9
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
	movs r1, #0xb6
	adds r1, r1, r6
	mov r8, r1
	b _080445DC
_0804448E:
	adds r0, r6, #0
	adds r0, #0xb6
	movs r2, #0
	ldrsb r2, [r7, r2]
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r2, r1
	bne _08044564
	ldr r0, _080444F4 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08044508
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _080444F8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080444FC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08044500 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08044504 @ =VolteelModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r4, r0
	bne _080445D6
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _080445D6
	.align 2, 0
_080444F4: .4byte gScore
_080444F8: .4byte RNG_0202f388
_080444FC: .4byte 0x000343FD
_08044500: .4byte 0x00269EC3
_08044504: .4byte VolteelModes
_08044508:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08044554 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044558 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804455C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08044560 @ =VolteelEXModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r4, r0
	bne _080445D6
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08045910
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _080445D6
	.align 2, 0
_08044554: .4byte RNG_0202f388
_08044558: .4byte 0x000343FD
_0804455C: .4byte 0x00269EC3
_08044560: .4byte VolteelEXModes
_08044564:
	ldr r0, _08044590 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _080445A4
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _08044594 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044598 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804459C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _080445A0 @ =VolteelModes
	b _080445C2
	.align 2, 0
_08044590: .4byte gScore
_08044594: .4byte RNG_0202f388
_08044598: .4byte 0x000343FD
_0804459C: .4byte 0x00269EC3
_080445A0: .4byte VolteelModes
_080445A4:
	adds r0, r6, #0
	bl FUN_080459d4
	adds r3, r0, #0
	ldr r2, _0804461C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044620 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08044624 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _08044628 @ =VolteelEXModes
_080445C2:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
_080445D6:
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
_080445DC:
	adds r0, r6, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, r6, #0
	adds r1, #0xa4
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0804463E
	subs r0, r4, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08044636
	movs r1, #0
	ldrsb r1, [r7, r1]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0804462C
	cmp r1, #5
	bne _0804462C
	movs r4, #9
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
	ldrb r0, [r7]
	strb r0, [r2]
	b _08044644
	.align 2, 0
_0804461C: .4byte RNG_0202f388
_08044620: .4byte 0x000343FD
_08044624: .4byte 0x00269EC3
_08044628: .4byte VolteelEXModes
_0804462C:
	movs r4, #5
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
	b _0804463E
_08044636:
	ldrb r0, [r7]
	mov r2, r8
	strb r0, [r2]
	b _08044644
_0804463E:
	ldrb r0, [r7]
	mov r1, r8
	strb r0, [r1]
_08044644:
	strb r4, [r7]
	cmp r4, #9
	beq _08044650
	movs r0, #0
	mov r2, sb
	strb r0, [r2]
_08044650:
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #5
	beq _0804465A
	b _080449DC
_0804465A:
	movs r1, #0
	strb r0, [r6, #0xd]
	movs r0, #0xa
	strb r0, [r6, #0xe]
	strb r1, [r6, #0xf]
	b _080449DC
_08044666:
	adds r0, r6, #0
	bl InitScalerotMotion1
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
	movs r0, #0
	strb r0, [r5]
	adds r1, r6, #0
	adds r1, #0x50
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _08044724 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08044728 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804472C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r7, #3
	ands r0, r7
	adds r1, r0, #0
	cmp r0, #0
	bne _08044734
	adds r4, r6, #0
	adds r4, #0xdc
	adds r3, r6, #0
	adds r3, #0xe0
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xd4
	ldr r0, [r0]
	str r0, [r6, #0x58]
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r6, #0x68]
	adds r1, r6, #0
	adds r1, #0xca
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08044730 @ =sCollisions
	bl SetDDP
	movs r0, #0xc0
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	mov r2, r8
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	b _08044866
	.align 2, 0
_08044724: .4byte RNG_0202f388
_08044728: .4byte 0x000343FD
_0804472C: .4byte 0x00269EC3
_08044730: .4byte sCollisions
_08044734:
	cmp r0, #1
	bne _080447A4
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r0, [r0]
	str r0, [r6, #0x54]
	adds r3, r6, #0
	adds r3, #0xd8
	adds r4, r6, #0
	adds r4, #0xd4
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xdc
	ldr r0, [r0]
	str r0, [r6, #0x64]
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xca
	strb r7, [r0]
	subs r0, #0x56
	ldr r1, _080447A0 @ =sCollisions
	bl SetDDP
	mov r0, r8
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	b _08044866
	.align 2, 0
_080447A0: .4byte sCollisions
_080447A4:
	cmp r1, #2
	bne _08044804
	adds r4, r6, #0
	adds r4, #0xdc
	adds r3, r6, #0
	adds r3, #0xe0
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r6, #0x58]
	ldr r0, [r3]
	ldr r1, [r4]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xd4
	ldr r0, [r0]
	str r0, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xca
	mov r2, r8
	strb r2, [r0]
	subs r0, #0x56
	ldr r1, _08044800 @ =sCollisions
	bl SetDDP
	movs r0, #0x40
	strb r0, [r5]
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	b _08044856
	.align 2, 0
_08044800: .4byte sCollisions
_08044804:
	adds r0, r6, #0
	adds r0, #0xdc
	ldr r0, [r0]
	str r0, [r6, #0x54]
	adds r3, r6, #0
	adds r3, #0xd8
	adds r4, r6, #0
	adds r4, #0xd4
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	movs r2, #0x90
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r0, [r0]
	str r0, [r6, #0x64]
	ldr r1, [r3]
	ldr r0, [r4]
	subs r0, r1, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	adds r1, r1, r2
	str r1, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xca
	movs r4, #1
	strb r4, [r0]
	subs r0, #0x56
	ldr r1, _08044924 @ =sCollisions
	bl SetDDP
	mov r0, r8
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
_08044856:
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	orrs r0, r1
_08044866:
	strb r0, [r6, #0xa]
	ldr r1, _08044928 @ =0x0000A512
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	subs r1, r1, r2
	str r1, [r6, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _080448B6
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r0, [r6, #0x60]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r6, #0x60]
_080448B6:
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xc4
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xcc
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r1]
	movs r0, #0x14
	strb r0, [r6, #0x12]
	strb r2, [r6, #0x13]
	movs r0, #0x7a
	bl PlaySound
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080448FA:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804492C
	ldrb r0, [r6, #0xa]
	orrs r0, r1
	b _08044932
	.align 2, 0
_08044924: .4byte sCollisions
_08044928: .4byte 0x0000A512
_0804492C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08044932:
	strb r0, [r6, #0xa]
	adds r2, r6, #0
	adds r2, #0xc4
	adds r0, r6, #0
	adds r0, #0xcc
	ldr r1, [r2]
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r2]
	cmp r1, #0
	bgt _080449DC
	movs r0, #0
	str r0, [r2]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804495C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080449DC
_0804495C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080449DC
_08044964:
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r6, #0x13]
	adds r5, r6, #0
	adds r5, #0x24
	strb r4, [r5]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	movs r1, #0xef
	ands r1, r0
	ldr r0, [r6, #0x64]
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x68]
	str r0, [r6, #0x58]
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080449E8 @ =sCollisions
	bl SetDDP
	movs r0, #9
	strb r0, [r6, #0xe]
	adds r0, r6, #0
	bl InitNonAffineMotion
	strb r4, [r5]
	adds r0, r6, #0
	adds r0, #0x50
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldr r1, _080449EC @ =0x0000A512
	adds r0, r6, #0
	bl SetMotion
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl UpdateEntityAnim
_080449DC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080449E8: .4byte sCollisions
_080449EC: .4byte 0x0000A512

