	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start FUN_08060a48
FUN_08060a48: @ 0x08060A48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r2, [r6, #0x2c]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r2, #0x5c]
	ldr r1, [r2, #0x60]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r5, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	bls _08060A7E
	movs r5, #1
_08060A7E:
	add r0, sp, #8
	mov sb, r0
	add r1, sp, #0x10
	mov r8, r1
	movs r0, #0xbc
	adds r0, r0, r6
	mov sl, r0
	adds r1, r6, #0
	adds r1, #0xc0
	str r1, [sp, #0x18]
_08060A92:
	ldr r1, _08060AE0 @ =PTR_ARRAY_08365568
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	mov r1, sp
	mov r2, sb
	mov r3, r8
	bl _call_via_r4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08060AB6
	movs r0, #0
	cmp r5, #0
	bne _08060AB4
	movs r0, #1
_08060AB4:
	adds r5, r0, #0
_08060AB6:
	lsls r0, r7, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r7, r0, #0x18
	cmp r0, #0
	bne _08060A92
	ldr r0, [sp]
	mov r1, sl
	str r0, [r1]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x18]
	str r0, [r1]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060AE0: .4byte PTR_ARRAY_08365568

