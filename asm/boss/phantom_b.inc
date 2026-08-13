	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08060838
FUN_08060838: @ 0x08060838
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x54]
	ldr r0, _08060854 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	cmp r3, r1
	beq _08060858
	movs r0, #0
	cmp r3, r1
	bge _08060860
	movs r0, #1
	b _08060860
	.align 2, 0
_08060854: .4byte pZero2
_08060858:
	ldrb r0, [r2, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
_08060860:
	pop {r1}
	bx r1

	thumb_func_start FUN_08060864
FUN_08060864: @ 0x08060864
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	adds r4, r0, r1
	adds r0, r2, #0
	adds r0, #0xd4
	ldr r3, [r0]
	subs r1, r4, r3
	adds r0, #8
	ldr r0, [r0]
	cmp r1, r0
	bhi _08060882
	str r4, [r2, #0x54]
	movs r0, #0
	b _08060894
_08060882:
	cmp r4, r3
	bge _0806088A
	str r3, [r2, #0x54]
	b _08060892
_0806088A:
	adds r0, r2, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r2, #0x54]
_08060892:
	movs r0, #1
_08060894:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806089c
FUN_0806089c: @ 0x0806089C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x58]
	adds r5, r2, r1
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl FUN_08009f6c
	cmp r5, r0
	blt _080608BE
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #1
	b _080608C2
_080608BE:
	str r5, [r4, #0x58]
	movs r0, #0
_080608C2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080608c8
FUN_080608c8: @ 0x080608C8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #3
	bl FUN_080607a0
	adds r0, r4, #0
	bl FUN_080607f0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080608e0
FUN_080608e0: @ 0x080608E0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0806091E
	adds r0, r2, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0806091E
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	movs r0, #1
	b _08060920
_0806091E:
	movs r0, #0
_08060920:
	pop {r1}
	bx r1

	thumb_func_start FUN_08060924
FUN_08060924: @ 0x08060924
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _08060954 @ =sCollisions+(12*24)
	bl SetDDP
	ldr r5, [r4, #0x60]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0806089c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08060958
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080607a0
	adds r0, r4, #0
	bl FUN_080607f0
	movs r0, #1
	b _0806096C
	.align 2, 0
_08060954: .4byte sCollisions+(12*24)
_08060958:
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bne _08060964
	adds r0, r5, #0
	adds r0, #0xa8
	b _08060968
_08060964:
	adds r0, r5, #0
	adds r0, #0x40
_08060968:
	str r0, [r4, #0x60]
	movs r0, #0
_0806096C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08060974
FUN_08060974: @ 0x08060974
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _08060990 @ =sCollisions
	bl SetDDP
	adds r4, #0x73
	ldrb r0, [r4]
	cmp r0, #2
	bne _08060994
	movs r0, #1
	rsbs r0, r0, #0
	b _0806099E
	.align 2, 0
_08060990: .4byte sCollisions
_08060994:
	cmp r0, #3
	beq _0806099C
	movs r0, #0
	b _0806099E
_0806099C:
	movs r0, #1
_0806099E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080609a4
FUN_080609a4: @ 0x080609A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x2c]
	ldr r1, [r5, #0x60]
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _08060A3C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r3, [r4, #0x54]
	ldr r2, [r5, #0x54]
	ldr r1, [r5, #0x58]
	subs r1, r1, r0
	ldr r0, _080609F8 @ =0xFFFFFB00
	adds r1, r1, r0
	subs r2, r2, r3
	movs r0, #0x80
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r2, r0
	bhi _08060A04
	movs r3, #0
	ldr r4, _080609FC @ =0xFFFFF700
	ldr r2, _08060A00 @ =s32_ARRAY_08365240
_080609DE:
	adds r2, #4
	adds r3, #1
	subs r1, #0x80
	ldr r0, [r2]
	adds r0, r0, r4
	rsbs r0, r0, #0
	cmp r0, r1
	bge _080609DE
	subs r0, r3, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _08060A40
	.align 2, 0
_080609F8: .4byte 0xFFFFFB00
_080609FC: .4byte 0xFFFFF700
_08060A00: .4byte s32_ARRAY_08365240
_08060A04:
	movs r3, #0
	ldr r5, _08060A30 @ =0xFFFFF700
	adds r4, r0, #0
	ldr r2, _08060A34 @ =s32_ARRAY_08365240
_08060A0C:
	adds r2, #4
	adds r3, #1
	ldr r0, [r2]
	adds r0, r0, r5
	cmp r0, r4
	ble _08060A0C
	subs r3, #1
	adds r0, r3, #0
	adds r0, #8
	lsls r0, r0, #7
	subs r1, r1, r0
	ldr r0, _08060A38 @ =0xFFFFE000
	cmp r1, r0
	bgt _08060A3C
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	b _08060A40
	.align 2, 0
_08060A30: .4byte 0xFFFFF700
_08060A34: .4byte s32_ARRAY_08365240
_08060A38: .4byte 0xFFFFE000
_08060A3C:
	movs r0, #1
	rsbs r0, r0, #0
_08060A40:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
