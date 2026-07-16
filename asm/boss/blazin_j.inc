	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazin_0803ffdc
blazin_0803ffdc: @ 0x0803FFDC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08040008 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08040010
	ldr r0, _0804000C @ =s32_ARRAY_080fee20
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	rsbs r0, r0, #0
	b _08040018
	.align 2, 0
_08040008: .4byte 0xFFFFD800
_0804000C: .4byte s32_ARRAY_080fee20
_08040010:
	ldr r0, _08040040 @ =s32_ARRAY_080fee20
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
_08040018:
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	add r2, sp, #8
	str r0, [r2, #4]
	ldr r1, [sp]
	ldr r0, [sp, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0809e55c
	movs r0, #1
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08040040: .4byte s32_ARRAY_080fee20

	thumb_func_start blazin_08040044
blazin_08040044: @ 0x08040044
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r7, r5, #0
	lsls r2, r2, #0x18
	lsrs r3, r2, #0x18
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804009C
	ldr r0, _08040080 @ =u8_ARRAY_080feda8
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	movs r1, #0xc0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	cmp r3, #6
	bhi _08040084
	adds r0, r4, r5
	b _08040086
	.align 2, 0
_08040080: .4byte u8_ARRAY_080feda8
_08040084:
	subs r0, r4, r5
_08040086:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _08040098 @ =Coord_ARRAY_080fedb8
	lsls r3, r3, #3
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r1, [sp]
	adds r0, r0, r1
	b _080400CA
	.align 2, 0
_08040098: .4byte Coord_ARRAY_080fedb8
_0804009C:
	ldr r0, _080400B4 @ =u8_ARRAY_080feda8
	adds r0, r3, r0
	ldrb r1, [r0]
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r3, #6
	bhi _080400B8
	subs r0, r4, r5
	b _080400BA
	.align 2, 0
_080400B4: .4byte u8_ARRAY_080feda8
_080400B8:
	adds r0, r4, r7
_080400BA:
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _08040108 @ =Coord_ARRAY_080fedb8
	lsls r3, r3, #3
	adds r0, r3, r2
	ldr r1, [r0]
	ldr r0, [sp]
	subs r0, r0, r1
_080400CA:
	str r0, [sp]
	adds r0, r2, #4
	adds r0, r3, r0
	ldr r0, [r0]
	ldr r1, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, _0804010C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r2, sp, #8
	str r0, [r2, #4]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_0809e500
	movs r0, #1
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08040108: .4byte Coord_ARRAY_080fedb8
_0804010C: .4byte gSineTable

	thumb_func_start createBlazinEXFireBall
createBlazinEXFireBall: @ 0x08040110
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r3, #0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08040140
	ldr r0, _0804013C @ =BlazinFireballAngles
	adds r0, r3, r0
	movs r1, #0xd
	muls r1, r2, r1
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	b _08040150
	.align 2, 0
_0804013C: .4byte BlazinFireballAngles
_08040140:
	ldr r0, _080401C8 @ =BlazinFireballAngles
	adds r0, r3, r0
	movs r1, #0xd
	muls r1, r2, r1
	ldrb r0, [r0]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_08040150:
	ldr r1, _080401CC @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	rsbs r0, r0, #0
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _080401D0 @ =0xFFFFE400
	add r1, sp, #8
	str r0, [r1, #4]
	ldr r2, [sp]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xb
	asrs r0, r0, #8
	ldr r2, [sp, #8]
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r2, [sp, #4]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xb
	asrs r0, r0, #8
	ldr r2, [r1, #4]
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, [r4, #0x54]
	ldr r2, [sp, #8]
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	ldr r2, [r1, #4]
	adds r0, r0, r2
	str r0, [r1, #4]
	adds r3, #0x80
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	mov r2, sp
	bl _createBlazinEXFireBall
	cmp r0, #0
	beq _080401BE
	adds r0, #0xbc
	str r5, [r0]
_080401BE:
	movs r0, #1
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080401C8: .4byte BlazinFireballAngles
_080401CC: .4byte gSineTable
_080401D0: .4byte 0xFFFFE400

	thumb_func_start FUN_080401d4
FUN_080401d4: @ 0x080401D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r0, #0
	mov sl, r0
	ldr r1, _08040290 @ =0x7FFFFFFF
	mov sb, r1
	movs r2, #0
	movs r0, #0xd
	mov r3, r8
	muls r3, r0, r3
	str r3, [sp]
	ldr r0, _08040294 @ =gSineTable
	mov r8, r0
_080401FE:
	ldr r0, _08040298 @ =BlazinFireballAngles
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r1, [sp]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	add r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r6, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	rsbs r0, r0, #0
	adds r7, r0, #0
	ldr r5, _0804029C @ =0xFFFFE400
	lsls r1, r1, #1
	adds r1, r1, r6
	lsls r1, r1, #0xb
	asrs r4, r1, #8
	lsls r0, r0, #1
	adds r0, r0, r7
	lsls r0, r0, #0xb
	asrs r0, r0, #8
	adds r5, r5, r0
	ldr r1, [sp, #0xc]
	ldr r0, [r1, #0x54]
	adds r4, r4, r0
	ldr r0, [r1, #0x58]
	adds r5, r5, r0
	ldr r0, _080402A0 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	subs r6, r0, r4
	ldr r0, [r1, #0x58]
	subs r7, r0, r5
	asrs r0, r6, #2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	asrs r1, r7, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	str r2, [sp, #4]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	ldr r2, [sp, #4]
	cmp r0, sb
	bge _08040276
	mov sb, r0
	mov sl, r2
_08040276:
	adds r2, #1
	cmp r2, #4
	ble _080401FE
	mov r0, sl
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08040290: .4byte 0x7FFFFFFF
_08040294: .4byte gSineTable
_08040298: .4byte BlazinFireballAngles
_0804029C: .4byte 0xFFFFE400
_080402A0: .4byte pZero2

	thumb_func_start blazin_080402a4
blazin_080402a4: @ 0x080402A4
	push {r4, lr}
	sub sp, #0x10
	adds r2, r0, #0
	movs r3, #0x54
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080402B8
	movs r3, #0xac
_080402B8:
	ldr r1, _080402F4 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	rsbs r0, r0, #0
	str r0, [sp, #4]
	ldr r0, [r2, #0x54]
	str r0, [sp, #8]
	ldr r0, [r2, #0x58]
	add r1, sp, #8
	ldr r3, _080402F8 @ =0xFFFFF800
	adds r0, r0, r3
	str r0, [r1, #4]
	adds r0, r2, #0
	mov r2, sp
	bl blazin_0809e620
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080402F4: .4byte gSineTable
_080402F8: .4byte 0xFFFFF800

	thumb_func_start blazin_080402fc
blazin_080402fc: @ 0x080402FC
	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _0804032A
	movs r2, #0
	ldr r5, _0804031C @ =UnkBlaizinModes_080fed5a
	adds r3, r5, #0
_0804030A:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08040320
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0804030A
	b _0804035C
	.align 2, 0
_0804031C: .4byte UnkBlaizinModes_080fed5a
_08040320:
	adds r0, r2, #1
	movs r1, #5
	bl __modsi3
	b _08040346
_0804032A:
	movs r2, #0
	ldr r5, _08040350 @ =UnkBlaizinModes_080fed5a
	adds r3, r5, #0
_08040330:
	ldrh r1, [r3]
	cmp r1, r4
	bne _08040354
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _08040340
	adds r0, r2, #4
_08040340:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
_08040346:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0804035C
	.align 2, 0
_08040350: .4byte UnkBlaizinModes_080fed5a
_08040354:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _08040330
_0804035C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

