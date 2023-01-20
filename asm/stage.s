	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08009990
FUN_08009990: @ 0x08009990
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sb, r1
	mov r4, sb
	movs r5, #0
	ldr r0, _080099E4 @ =0x020023B8
	mov r8, r0
	movs r7, #0xc5
	lsls r7, r7, #3
	add r7, r8
	ldr r1, _080099E8 @ =0x0000800F
	mov sl, r1
_080099B0:
	ldrh r1, [r7]
	asrs r0, r4, #0xc
	muls r0, r1, r0
	asrs r1, r6, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r2, r8
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08009A20
	cmp r1, sl
	beq _08009A20
	cmp r0, #1
	bne _080099F0
	ldr r0, _080099EC @ =0xFFFFF000
	ands r0, r4
	subs r4, r0, #1
	b _08009A1A
	.align 2, 0
_080099E4: .4byte 0x020023B8
_080099E8: .4byte 0x0000800F
_080099EC: .4byte 0xFFFFF000
_080099F0:
	ldr r1, _08009A34 @ =0x08338DE8
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, _08009A38 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009A20
	adds r1, r4, #0
	adds r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _08009A20
_08009A1A:
	adds r5, #1
	cmp r5, #0xf
	ble _080099B0
_08009A20:
	cmp r5, #0xf
	bgt _08009A3C
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0800acc8
	mov r1, sb
	subs r0, r0, r1
	b _08009A3E
	.align 2, 0
_08009A34: .4byte 0x08338DE8
_08009A38: .4byte 0x00000FFF
_08009A3C:
	movs r0, #1
_08009A3E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009a4c
FUN_08009a4c: @ 0x08009A4C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	movs r7, #0
	ldr r0, _08009AA0 @ =0x020023B8
	mov sb, r0
	movs r2, #0xc5
	lsls r2, r2, #3
	add r2, sb
	mov r8, r2
_08009A68:
	mov r0, r8
	ldrh r1, [r0]
	asrs r0, r4, #0xc
	muls r0, r1, r0
	asrs r1, r6, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009AD6
	ldr r0, _08009AA4 @ =0x0000800F
	cmp r1, r0
	beq _08009AD6
	cmp r2, #1
	bne _08009AAC
	ldr r0, _08009AA8 @ =0xFFFFF000
	ands r0, r4
	subs r4, r0, #1
	b _08009AE4
	.align 2, 0
_08009AA0: .4byte 0x020023B8
_08009AA4: .4byte 0x0000800F
_08009AA8: .4byte 0xFFFFF000
_08009AAC:
	ldr r1, _08009ADC @ =0x08338DE8
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009AE0 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009AD6
	adds r1, r4, #0
	adds r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	bne _08009AE4
_08009AD6:
	subs r0, r4, r5
	b _08009AEC
	.align 2, 0
_08009ADC: .4byte 0x08338DE8
_08009AE0: .4byte 0x00000FFF
_08009AE4:
	adds r7, #1
	cmp r7, #0xf
	ble _08009A68
	movs r0, #1
_08009AEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009af8
FUN_08009af8: @ 0x08009AF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sb, r1
	mov r4, sb
	movs r5, #0
	ldr r0, _08009B5C @ =0x020023B8
	mov r8, r0
	movs r1, #0xc5
	lsls r1, r1, #3
	add r1, r8
	mov sl, r1
	ldr r3, _08009B60 @ =0x00000FFF
_08009B1A:
	mov r2, sl
	ldrh r1, [r2]
	asrs r0, r4, #0xc
	muls r0, r1, r0
	asrs r1, r6, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r7, r8
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009B9A
	movs r7, #0x84
	lsls r7, r7, #8
	adds r0, r7, #0
	ands r1, r0
	cmp r1, #0
	bne _08009B9A
	cmp r2, #1
	bne _08009B68
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, _08009B64 @ =0xFFFFF000
	ands r4, r0
	b _08009B94
	.align 2, 0
_08009B5C: .4byte 0x020023B8
_08009B60: .4byte 0x00000FFF
_08009B64: .4byte 0xFFFFF000
_08009B68:
	ldr r1, _08009BAC @ =0x08338E28
	lsls r0, r2, #2
	adds r0, r0, r1
	adds r1, r3, #0
	bics r1, r4
	ldr r2, [r0]
	adds r0, r6, #0
	ands r0, r3
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	cmp r0, #0
	beq _08009B9A
	adds r1, r4, #0
	subs r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _08009B9A
_08009B94:
	adds r5, #1
	cmp r5, #0xf
	ble _08009B1A
_08009B9A:
	cmp r5, #0xf
	bgt _08009BB0
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0800ad50
	mov r1, sb
	subs r0, r0, r1
	b _08009BB4
	.align 2, 0
_08009BAC: .4byte 0x08338E28
_08009BB0:
	movs r0, #1
	rsbs r0, r0, #0
_08009BB4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009bc4
FUN_08009bc4: @ 0x08009BC4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	movs r7, #0
	ldr r0, _08009C24 @ =0x020023B8
	mov sb, r0
	movs r2, #0xc5
	lsls r2, r2, #3
	add r2, sb
	mov r8, r2
_08009BE0:
	mov r3, r8
	ldrh r1, [r3]
	asrs r0, r4, #0xc
	muls r0, r1, r0
	asrs r1, r6, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009C56
	movs r3, #0x84
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08009C56
	cmp r2, #1
	bne _08009C2C
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, _08009C28 @ =0xFFFFF000
	ands r4, r0
	b _08009C64
	.align 2, 0
_08009C24: .4byte 0x020023B8
_08009C28: .4byte 0xFFFFF000
_08009C2C:
	ldr r1, _08009C5C @ =0x08338E28
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009C60 @ =0x00000FFF
	adds r1, r2, #0
	bics r1, r4
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009C56
	adds r1, r4, #0
	subs r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	bne _08009C64
_08009C56:
	subs r0, r4, r5
	b _08009C6E
	.align 2, 0
_08009C5C: .4byte 0x08338E28
_08009C60: .4byte 0x00000FFF
_08009C64:
	adds r7, #1
	cmp r7, #0xf
	ble _08009BE0
	movs r0, #1
	rsbs r0, r0, #0
_08009C6E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009c7c
FUN_08009c7c: @ 0x08009C7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r4
	movs r5, #0
	ldr r0, _08009CD4 @ =0x020023B8
	mov r8, r0
	movs r7, #0xc5
	lsls r7, r7, #3
	add r7, r8
_08009C96:
	ldrh r1, [r7]
	asrs r0, r6, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r2, r8
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009D0C
	movs r3, #0x84
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08009D0C
	cmp r2, #1
	bne _08009CDC
	ldr r0, _08009CD8 @ =0xFFFFF000
	ands r0, r4
	subs r4, r0, #1
	b _08009D06
	.align 2, 0
_08009CD4: .4byte 0x020023B8
_08009CD8: .4byte 0xFFFFF000
_08009CDC:
	ldr r1, _08009D20 @ =0x08338E68
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009D24 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009D0C
	adds r1, r4, #0
	adds r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _08009D0C
_08009D06:
	adds r5, #1
	cmp r5, #0xf
	ble _08009C96
_08009D0C:
	cmp r5, #0xf
	bgt _08009D28
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0800adec
	mov r1, sb
	subs r0, r0, r1
	b _08009D2A
	.align 2, 0
_08009D20: .4byte 0x08338E68
_08009D24: .4byte 0x00000FFF
_08009D28:
	movs r0, #1
_08009D2A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009d38
FUN_08009d38: @ 0x08009D38
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	movs r7, #0
	ldr r0, _08009D94 @ =0x020023B8
	mov sb, r0
	movs r2, #0xc5
	lsls r2, r2, #3
	add r2, sb
	mov r8, r2
_08009D54:
	mov r3, r8
	ldrh r1, [r3]
	asrs r0, r6, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009DC6
	movs r3, #0x84
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08009DC6
	cmp r2, #1
	bne _08009D9C
	ldr r0, _08009D98 @ =0xFFFFF000
	ands r0, r4
	subs r4, r0, #1
	b _08009DD4
	.align 2, 0
_08009D94: .4byte 0x020023B8
_08009D98: .4byte 0xFFFFF000
_08009D9C:
	ldr r1, _08009DCC @ =0x08338E68
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009DD0 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009DC6
	adds r1, r4, #0
	adds r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	bne _08009DD4
_08009DC6:
	subs r0, r4, r5
	b _08009DDC
	.align 2, 0
_08009DCC: .4byte 0x08338E68
_08009DD0: .4byte 0x00000FFF
_08009DD4:
	adds r7, #1
	cmp r7, #0xf
	ble _08009D54
	movs r0, #1
_08009DDC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009de8
FUN_08009de8: @ 0x08009DE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r4
	movs r5, #0
	ldr r0, _08009E4C @ =0x020023B8
	mov r8, r0
	movs r1, #0xc5
	lsls r1, r1, #3
	add r1, r8
	mov sl, r1
	ldr r3, _08009E50 @ =0x00000FFF
_08009E0A:
	mov r2, sl
	ldrh r1, [r2]
	asrs r0, r6, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r7, r8
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009E8A
	movs r7, #0x84
	lsls r7, r7, #8
	adds r0, r7, #0
	ands r1, r0
	cmp r1, #0
	bne _08009E8A
	cmp r2, #1
	bne _08009E58
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, _08009E54 @ =0xFFFFF000
	ands r4, r0
	b _08009E84
	.align 2, 0
_08009E4C: .4byte 0x020023B8
_08009E50: .4byte 0x00000FFF
_08009E54: .4byte 0xFFFFF000
_08009E58:
	ldr r1, _08009E9C @ =0x08338EA8
	lsls r0, r2, #2
	adds r0, r0, r1
	adds r1, r3, #0
	bics r1, r4
	ldr r2, [r0]
	adds r0, r6, #0
	ands r0, r3
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	cmp r0, #0
	beq _08009E8A
	adds r1, r4, #0
	subs r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _08009E8A
_08009E84:
	adds r5, #1
	cmp r5, #0xf
	ble _08009E0A
_08009E8A:
	cmp r5, #0xf
	bgt _08009EA0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0800ae90
	mov r1, sb
	subs r0, r0, r1
	b _08009EA4
	.align 2, 0
_08009E9C: .4byte 0x08338EA8
_08009EA0:
	movs r0, #1
	rsbs r0, r0, #0
_08009EA4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009eb4
FUN_08009eb4: @ 0x08009EB4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	movs r7, #0
	ldr r0, _08009F14 @ =0x020023B8
	mov sb, r0
	movs r2, #0xc5
	lsls r2, r2, #3
	add r2, sb
	mov r8, r2
_08009ED0:
	mov r3, r8
	ldrh r1, [r3]
	asrs r0, r6, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009F46
	movs r3, #0x84
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08009F46
	cmp r2, #1
	bne _08009F1C
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, _08009F18 @ =0xFFFFF000
	ands r4, r0
	b _08009F54
	.align 2, 0
_08009F14: .4byte 0x020023B8
_08009F18: .4byte 0xFFFFF000
_08009F1C:
	ldr r1, _08009F4C @ =0x08338EA8
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009F50 @ =0x00000FFF
	adds r1, r2, #0
	bics r1, r4
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009F46
	adds r1, r4, #0
	subs r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	bne _08009F54
_08009F46:
	subs r0, r4, r5
	b _08009F5E
	.align 2, 0
_08009F4C: .4byte 0x08338EA8
_08009F50: .4byte 0x00000FFF
_08009F54:
	adds r7, #1
	cmp r7, #0xf
	ble _08009ED0
	movs r0, #1
	rsbs r0, r0, #0
_08009F5E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009f6c
FUN_08009f6c: @ 0x08009F6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	mov sb, r1
	mov r4, sb
	asrs r0, r7, #0xc
	mov r8, r0
	asrs r1, r4, #0xc
	ldr r0, _08009F90 @ =0x0000077F
	cmp r8, r0
	bls _08009F94
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A04C
	.align 2, 0
_08009F90: .4byte 0x0000077F
_08009F94:
	movs r6, #0
	ldr r0, _08009FF0 @ =0x000004FF
	cmp r1, r0
	bhi _0800A01E
	ldr r2, _08009FF4 @ =0x020023B8
	movs r0, #0xc5
	lsls r0, r0, #3
	adds r2, r2, r0
	mov sl, r2
_08009FA6:
	mov r2, sl
	ldrh r0, [r2]
	muls r0, r1, r0
	add r0, r8
	adds r0, #2
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	ldr r2, _08009FF4 @ =0x020023B8
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #0xf
	ands r0, r5
	lsls r0, r0, #2
	ldr r1, _08009FF8 @ =0x08338DE8
	adds r0, r0, r1
	ldr r2, _08009FFC @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r7, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009FE4
	ldr r0, _0800A000 @ =0x0000800F
	cmp r5, r0
	bne _0800A01E
_08009FE4:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _0800A004
	adds r4, #1
	b _0800A010
	.align 2, 0
_08009FF0: .4byte 0x000004FF
_08009FF4: .4byte 0x020023B8
_08009FF8: .4byte 0x08338DE8
_08009FFC: .4byte 0x00000FFF
_0800A000: .4byte 0x0000800F
_0800A004:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, r2
	asrs r0, r0, #0xc
	lsls r0, r0, #0xc
	subs r4, r0, #1
_0800A010:
	asrs r1, r4, #0xc
	adds r6, #1
	cmp r6, #0x7f
	bgt _0800A022
	ldr r0, _0800A028 @ =0x000004FF
	cmp r1, r0
	bls _08009FA6
_0800A01E:
	cmp r6, #0x7f
	ble _0800A030
_0800A022:
	ldr r2, _0800A02C @ =0x7FFFFFFF
	b _0800A040
	.align 2, 0
_0800A028: .4byte 0x000004FF
_0800A02C: .4byte 0x7FFFFFFF
_0800A030:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08009990
	adds r1, r0, #0
	cmp r1, #0
	bgt _0800A04A
	adds r2, r4, r1
_0800A040:
	adds r0, r7, #0
	mov r1, sb
	bl FUN_0800af30
	b _0800A04C
_0800A04A:
	movs r0, #0
_0800A04C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a05c
FUN_0800a05c: @ 0x0800A05C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r1, #0
	asrs r0, r7, #0xc
	mov sl, r0
	asrs r1, r4, #0xc
	movs r6, #0
	ldr r0, _0800A0D0 @ =0x000004FF
	cmp r1, r0
	bhi _0800A0FE
	ldr r2, _0800A0D4 @ =0x020023B8
	mov sb, r2
	movs r0, #0xc5
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_0800A084:
	mov r2, r8
	ldrh r0, [r2]
	muls r0, r1, r0
	add r0, sl
	adds r0, #2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #0xf
	ands r0, r5
	lsls r0, r0, #2
	ldr r1, _0800A0D8 @ =0x08338DE8
	adds r0, r0, r1
	ldr r2, _0800A0DC @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r7, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _0800A0C2
	ldr r0, _0800A0E0 @ =0x0000800F
	cmp r5, r0
	bne _0800A0FE
_0800A0C2:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _0800A0E4
	adds r4, #1
	b _0800A0F0
	.align 2, 0
_0800A0D0: .4byte 0x000004FF
_0800A0D4: .4byte 0x020023B8
_0800A0D8: .4byte 0x08338DE8
_0800A0DC: .4byte 0x00000FFF
_0800A0E0: .4byte 0x0000800F
_0800A0E4:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, r2
	asrs r0, r0, #0xc
	lsls r0, r0, #0xc
	subs r4, r0, #1
_0800A0F0:
	asrs r1, r4, #0xc
	adds r6, #1
	cmp r6, #0x7f
	bgt _0800A102
	ldr r0, _0800A108 @ =0x000004FF
	cmp r1, r0
	bls _0800A084
_0800A0FE:
	cmp r6, #0x7f
	ble _0800A110
_0800A102:
	ldr r0, _0800A10C @ =0x7FFFFFFF
	b _0800A124
	.align 2, 0
_0800A108: .4byte 0x000004FF
_0800A10C: .4byte 0x7FFFFFFF
_0800A110:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08009a4c
	adds r1, r0, #0
	cmp r1, #0
	bgt _0800A122
	adds r0, r4, r1
	b _0800A124
_0800A122:
	movs r0, #0
_0800A124:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a134
FUN_0800a134: @ 0x0800A134
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov sb, r1
	mov r5, sb
	asrs r0, r7, #0xc
	mov r8, r0
	asrs r1, r5, #0xc
	ldr r0, _0800A158 @ =0x0000077F
	cmp r8, r0
	bls _0800A15C
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A218
	.align 2, 0
_0800A158: .4byte 0x0000077F
_0800A15C:
	movs r6, #0
	ldr r0, _0800A1C4 @ =0x000004FF
	cmp r1, r0
	bhi _0800A1E6
	ldr r2, _0800A1C8 @ =0x020023B8
	movs r0, #0xc5
	lsls r0, r0, #3
	adds r2, r2, r0
	mov sl, r2
	ldr r3, _0800A1CC @ =0x00000FFF
_0800A170:
	mov r2, sl
	ldrh r0, [r2]
	muls r0, r1, r0
	add r0, r8
	adds r0, #2
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	ldr r2, _0800A1C8 @ =0x020023B8
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #0xf
	ands r0, r4
	lsls r0, r0, #2
	ldr r1, _0800A1D0 @ =0x08338E28
	adds r0, r0, r1
	adds r1, r3, #0
	bics r1, r5
	ldr r2, [r0]
	adds r0, r7, #0
	ands r0, r3
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	cmp r0, #0
	beq _0800A1B6
	movs r2, #0x84
	lsls r2, r2, #8
	adds r0, r2, #0
	ands r4, r0
	cmp r4, #0
	beq _0800A1E6
_0800A1B6:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _0800A1D4
	subs r5, #1
	b _0800A1D8
	.align 2, 0
_0800A1C4: .4byte 0x000004FF
_0800A1C8: .4byte 0x020023B8
_0800A1CC: .4byte 0x00000FFF
_0800A1D0: .4byte 0x08338E28
_0800A1D4:
	asrs r0, r5, #0xc
	lsls r5, r0, #0xc
_0800A1D8:
	asrs r1, r5, #0xc
	adds r6, #1
	cmp r6, #0x7f
	bgt _0800A1EA
	ldr r0, _0800A1F8 @ =0x000004FF
	cmp r1, r0
	bls _0800A170
_0800A1E6:
	cmp r6, #0x7f
	ble _0800A1FC
_0800A1EA:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl FUN_0800afd4
	b _0800A218
	.align 2, 0
_0800A1F8: .4byte 0x000004FF
_0800A1FC:
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08009af8
	adds r1, r0, #0
	cmp r1, #0
	blt _0800A216
	adds r2, r5, r1
	adds r0, r7, #0
	mov r1, sb
	bl FUN_0800afd4
	b _0800A218
_0800A216:
	ldr r0, _0800A228 @ =0x7FFFFFFF
_0800A218:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A228: .4byte 0x7FFFFFFF

	thumb_func_start FUN_0800a22c
FUN_0800a22c: @ 0x0800A22C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	mov r8, r4
	asrs r1, r4, #0xc
	asrs r7, r6, #0xc
	ldr r0, _0800A24C @ =0x000004FF
	cmp r7, r0
	bls _0800A250
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A30C
	.align 2, 0
_0800A24C: .4byte 0x000004FF
_0800A250:
	movs r5, #0
	ldr r0, _0800A2B0 @ =0x0000077F
	cmp r1, r0
	bhi _0800A2DE
	ldr r0, _0800A2B4 @ =0x020023B8
	mov sl, r0
	movs r2, #0xc5
	lsls r2, r2, #3
	add r2, sl
	mov sb, r2
_0800A264:
	mov r2, sb
	ldrh r0, [r2]
	muls r0, r7, r0
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	mov r2, sl
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _0800A2B8 @ =0x0000800F
	cmp r2, r0
	beq _0800A2A2
	ldr r1, _0800A2BC @ =0x08338E68
	movs r0, #0xf
	ands r2, r0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _0800A2C0 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	bne _0800A2DE
_0800A2A2:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _0800A2C4
	adds r4, #1
	b _0800A2D0
	.align 2, 0
_0800A2B0: .4byte 0x0000077F
_0800A2B4: .4byte 0x020023B8
_0800A2B8: .4byte 0x0000800F
_0800A2BC: .4byte 0x08338E68
_0800A2C0: .4byte 0x00000FFF
_0800A2C4:
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, r1
	asrs r0, r0, #0xc
	lsls r0, r0, #0xc
	subs r4, r0, #1
_0800A2D0:
	asrs r1, r4, #0xc
	adds r5, #1
	cmp r5, #0x7f
	bgt _0800A2E2
	ldr r0, _0800A2E8 @ =0x0000077F
	cmp r1, r0
	bls _0800A264
_0800A2DE:
	cmp r5, #0x7f
	ble _0800A2F0
_0800A2E2:
	ldr r2, _0800A2EC @ =0x7FFFFFFF
	b _0800A300
	.align 2, 0
_0800A2E8: .4byte 0x0000077F
_0800A2EC: .4byte 0x7FFFFFFF
_0800A2F0:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08009c7c
	adds r1, r0, #0
	cmp r1, #0
	bgt _0800A30A
	adds r2, r4, r1
_0800A300:
	mov r0, r8
	adds r1, r6, #0
	bl FUN_0800b08c
	b _0800A30C
_0800A30A:
	movs r0, #0
_0800A30C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a31c
FUN_0800a31c: @ 0x0800A31C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	mov r8, r4
	asrs r2, r4, #0xc
	asrs r7, r6, #0xc
	ldr r0, _0800A33C @ =0x000004FF
	cmp r7, r0
	bls _0800A340
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A3F8
	.align 2, 0
_0800A33C: .4byte 0x000004FF
_0800A340:
	movs r5, #0
	ldr r0, _0800A3A0 @ =0x0000077F
	cmp r2, r0
	bhi _0800A3C6
	ldr r0, _0800A3A4 @ =0x020023B8
	mov sl, r0
	movs r1, #0xc5
	lsls r1, r1, #3
	add r1, sl
	mov sb, r1
_0800A354:
	mov r1, sb
	ldrh r0, [r1]
	muls r0, r7, r0
	adds r0, r0, r2
	adds r0, #2
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	mov r2, sl
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _0800A3A8 @ =0x0000800F
	cmp r2, r0
	beq _0800A392
	ldr r1, _0800A3AC @ =0x08338EA8
	movs r0, #0xf
	ands r2, r0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _0800A3B0 @ =0x00000FFF
	adds r1, r2, #0
	bics r1, r4
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	bne _0800A3C6
_0800A392:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _0800A3B4
	subs r4, #1
	b _0800A3B8
	.align 2, 0
_0800A3A0: .4byte 0x0000077F
_0800A3A4: .4byte 0x020023B8
_0800A3A8: .4byte 0x0000800F
_0800A3AC: .4byte 0x08338EA8
_0800A3B0: .4byte 0x00000FFF
_0800A3B4:
	asrs r0, r4, #0xc
	lsls r4, r0, #0xc
_0800A3B8:
	asrs r2, r4, #0xc
	adds r5, #1
	cmp r5, #0x7f
	bgt _0800A3CA
	ldr r0, _0800A3D8 @ =0x0000077F
	cmp r2, r0
	bls _0800A354
_0800A3C6:
	cmp r5, #0x7f
	ble _0800A3DC
_0800A3CA:
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0800b144
	b _0800A3F8
	.align 2, 0
_0800A3D8: .4byte 0x0000077F
_0800A3DC:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08009de8
	adds r2, r0, #0
	cmp r2, #0
	blt _0800A3F6
	adds r2, r4, r2
	mov r0, r8
	adds r1, r6, #0
	bl FUN_0800b144
	b _0800A3F8
_0800A3F6:
	ldr r0, _0800A408 @ =0x7FFFFFFF
_0800A3F8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A408: .4byte 0x7FFFFFFF

	thumb_func_start FUN_0800a40c
FUN_0800a40c: @ 0x0800A40C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	asrs r3, r5, #0xc
	asrs r2, r6, #0xc
	movs r0, #0xee
	lsls r0, r0, #3
	cmp r3, r0
	bhi _0800A4AA
	ldr r0, _0800A470 @ =0x000004F5
	cmp r2, r0
	bhi _0800A4AA
	ldr r7, _0800A474 @ =0x020023B8
	movs r0, #0xc5
	lsls r0, r0, #3
	adds r1, r7, r0
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, _0800A478 @ =0x08338DE8
	movs r2, #0xf
	ands r2, r4
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r3, _0800A47C @ =0x00000FFF
	adds r0, r5, #0
	ands r0, r3
	adds r1, r6, #0
	ands r1, r3
	ldr r2, [r2]
	bl _call_via_r2
	cmp r0, #0
	beq _0800A498
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r4
	cmp r0, #0
	beq _0800A484
	ldr r1, _0800A480 @ =0x0002BE50
	adds r0, r7, r1
	b _0800A4B0
	.align 2, 0
_0800A470: .4byte 0x000004F5
_0800A474: .4byte 0x020023B8
_0800A478: .4byte 0x08338DE8
_0800A47C: .4byte 0x00000FFF
_0800A480: .4byte 0x0002BE50
_0800A484:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r4, r0
	cmp r4, #0
	beq _0800A498
	ldr r1, _0800A494 @ =0x0002BE4C
	adds r0, r7, r1
	b _0800A4B0
	.align 2, 0
_0800A494: .4byte 0x0002BE4C
_0800A498:
	adds r0, r5, #0
	adds r1, r6, #0
	bl blocking_0800ac18
	movs r1, #0x80
	lsls r1, r1, #6
	ands r1, r0
	cmp r1, #0
	bne _0800A4AE
_0800A4AA:
	movs r0, #0
	b _0800A4B2
_0800A4AE:
	ldr r0, _0800A4B8 @ =0x02000028
_0800A4B0:
	ldr r0, [r0]
_0800A4B2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A4B8: .4byte 0x02000028

	thumb_func_start FUN_0800a4bc
FUN_0800a4bc: @ 0x0800A4BC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	asrs r4, r6, #0xc
	asrs r2, r3, #0xc
	movs r0, #0xee
	lsls r0, r0, #3
	cmp r4, r0
	bhi _0800A548
	ldr r0, _0800A51C @ =0x000004F5
	cmp r2, r0
	bhi _0800A548
	ldr r5, _0800A520 @ =0x020023B8
	movs r0, #0xc5
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r0, r0, r4
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, _0800A524 @ =0x08338DE8
	movs r1, #0xf
	ands r1, r4
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, _0800A528 @ =0x00000FFF
	ands r3, r0
	ldr r2, [r1]
	ands r0, r6
	adds r1, r3, #0
	bl _call_via_r2
	cmp r0, #0
	beq _0800A548
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r4
	cmp r0, #0
	beq _0800A530
	ldr r1, _0800A52C @ =0x0002BE50
	b _0800A53C
	.align 2, 0
_0800A51C: .4byte 0x000004F5
_0800A520: .4byte 0x020023B8
_0800A524: .4byte 0x08338DE8
_0800A528: .4byte 0x00000FFF
_0800A52C: .4byte 0x0002BE50
_0800A530:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r4, r0
	cmp r4, #0
	beq _0800A548
	ldr r1, _0800A544 @ =0x0002BE4C
_0800A53C:
	adds r0, r5, r1
	ldr r0, [r0]
	b _0800A54A
	.align 2, 0
_0800A544: .4byte 0x0002BE4C
_0800A548:
	movs r0, #0
_0800A54A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a550
FUN_0800a550: @ 0x0800A550
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #1
	rsbs r0, r0, #0
	adds r1, r3, #0
	bl FUN_0800a564
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a564
FUN_0800a564: @ 0x0800A564
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	mov r8, r1
	mov ip, r2
	adds r4, #1
	ldr r2, _0800A5D0 @ =0x02002200
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r4, r1
	bge _0800A5E0
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r2, r3
	mov sb, r1
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r6, r1, r0
	movs r7, #0xee
	lsls r7, r7, #1
	adds r0, r1, r7
	adds r5, r0, r2
	adds r3, r1, r2
_0800A59C:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	lsls r2, r1, #1
	ldr r0, [r5]
	mov r7, r8
	subs r0, r7, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800A5D4
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	lsls r2, r0, #1
	ldr r1, [r6]
	mov r7, ip
	subs r1, r7, r1
	adds r1, r1, r0
	subs r1, #1
	cmp r2, r1
	bls _0800A5D4
	adds r0, r4, #0
	b _0800A5E4
	.align 2, 0
_0800A5D0: .4byte 0x02002200
_0800A5D4:
	adds r6, #0x18
	adds r5, #0x18
	adds r3, #0x18
	adds r4, #1
	cmp r4, sb
	blt _0800A59C
_0800A5E0:
	movs r0, #1
	rsbs r0, r0, #0
_0800A5E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start appendBlocking
appendBlocking: @ 0x0800A5F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r2
	mov r8, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800A6C4 @ =0x02002200
	movs r0, #0xe9
	lsls r0, r0, #1
	adds r4, r2, r0
	ldrb r3, [r4]
	adds r0, r3, #1
	mov ip, r2
	cmp r0, #0x1f
	ble _0800A61A
	b _0800A728
_0800A61A:
	strb r0, [r4]
	adds r6, r3, #0
	lsls r2, r6, #1
	mov sl, r2
	adds r0, r2, r6
	lsls r4, r0, #3
	mov r3, ip
	adds r0, r4, r3
	movs r2, #0xea
	lsls r2, r2, #1
	adds r7, r0, r2
	strh r5, [r7]
	movs r3, #0xeb
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r1, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	add r1, ip
	adds r1, r4, r1
	mov r0, r8
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r2
	str r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #1
	add r1, ip
	adds r1, r4, r1
	mov r0, r8
	movs r3, #2
	ldrsh r2, [r0, r3]
	mov r3, sb
	ldr r0, [r3, #4]
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0
	ldr r0, _0800A6C8 @ =0x000001D3
	add r0, ip
	ldrb r0, [r0]
	cmp r3, r0
	bge _0800A6D4
	mov r5, ip
	mov sb, r4
	ldrh r4, [r7]
	mov r1, ip
	ldr r7, _0800A6CC @ =0x000004D4
	adds r2, r0, #0
_0800A67E:
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r4
	beq _0800A68E
	adds r1, #0x18
	adds r3, #1
	cmp r3, r2
	blt _0800A67E
_0800A68E:
	ldr r1, _0800A6C8 @ =0x000001D3
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r3, r0
	bge _0800A6D4
	movs r0, #0xf2
	lsls r0, r0, #1
	adds r2, r5, r0
	add r2, sb
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #3
	ldr r3, _0800A6D0 @ =0x000004DC
	adds r0, r5, r3
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0xf4
	lsls r0, r0, #1
	adds r2, r5, r0
	add r2, sb
	adds r3, #4
	adds r0, r5, r3
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _0800A704
	.align 2, 0
_0800A6C4: .4byte 0x02002200
_0800A6C8: .4byte 0x000001D3
_0800A6CC: .4byte 0x000004D4
_0800A6D0: .4byte 0x000004DC
_0800A6D4:
	lsls r3, r6, #1
	adds r1, r3, r6
	lsls r1, r1, #3
	movs r2, #0xf2
	lsls r2, r2, #1
	add r2, ip
	adds r2, r1, r2
	movs r0, #0xee
	lsls r0, r0, #1
	add r0, ip
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [r2]
	movs r2, #0xf4
	lsls r2, r2, #1
	add r2, ip
	adds r2, r1, r2
	movs r0, #0xf0
	lsls r0, r0, #1
	add r0, ip
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	mov sl, r3
_0800A704:
	mov r1, sl
	adds r0, r1, r6
	lsls r0, r0, #3
	mov r3, ip
	adds r2, r0, r3
	mov r1, r8
	ldrh r0, [r1, #4]
	lsrs r0, r0, #1
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r2, r3
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #6]
	lsrs r0, r0, #1
	adds r3, #2
	adds r1, r2, r3
	strh r0, [r1]
_0800A728:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800a738
FUN_0800a738: @ 0x0800A738
	movs r0, #0
	bx lr

	thumb_func_start FUN_0800a73c
FUN_0800a73c: @ 0x0800A73C
	mvns r0, r1
	bx lr

	thumb_func_start FUN_0800a740
FUN_0800a740: @ 0x0800A740
	push {lr}
	ldr r2, _0800A754 @ =0xFFFFF000
	adds r1, r1, r2
	asrs r0, r0, #1
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800A758
	movs r0, #0
	b _0800A75A
	.align 2, 0
_0800A754: .4byte 0xFFFFF000
_0800A758:
	rsbs r0, r0, #0
_0800A75A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a760
FUN_0800a760: @ 0x0800A760
	push {lr}
	ldr r2, _0800A774 @ =0xFFFFF800
	adds r1, r1, r2
	asrs r0, r0, #1
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800A778
	movs r0, #0
	b _0800A77A
	.align 2, 0
_0800A774: .4byte 0xFFFFF800
_0800A778:
	rsbs r0, r0, #0
_0800A77A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a780
FUN_0800a780: @ 0x0800A780
	push {lr}
	ldr r2, _0800A794 @ =0xFFFFF000
	adds r1, r1, r2
	asrs r0, r0, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800A798
	movs r0, #0
	b _0800A79A
	.align 2, 0
_0800A794: .4byte 0xFFFFF000
_0800A798:
	rsbs r0, r0, #0
_0800A79A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a7a0
FUN_0800a7a0: @ 0x0800A7A0
	push {lr}
	ldr r2, _0800A7B4 @ =0xFFFFF400
	adds r1, r1, r2
	asrs r0, r0, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800A7B8
	movs r0, #0
	b _0800A7BA
	.align 2, 0
_0800A7B4: .4byte 0xFFFFF400
_0800A7B8:
	rsbs r0, r0, #0
_0800A7BA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a7c0
FUN_0800a7c0: @ 0x0800A7C0
	push {lr}
	ldr r2, _0800A7D4 @ =0xFFFFF800
	adds r1, r1, r2
	asrs r0, r0, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800A7D8
	movs r0, #0
	b _0800A7DA
	.align 2, 0
_0800A7D4: .4byte 0xFFFFF800
_0800A7D8:
	rsbs r0, r0, #0
_0800A7DA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a7e0
FUN_0800a7e0: @ 0x0800A7E0
	push {lr}
	ldr r2, _0800A7F4 @ =0xFFFFFC00
	adds r1, r1, r2
	asrs r0, r0, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800A7F8
	movs r0, #0
	b _0800A7FA
	.align 2, 0
_0800A7F4: .4byte 0xFFFFFC00
_0800A7F8:
	rsbs r0, r0, #0
_0800A7FA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a800
FUN_0800a800: @ 0x0800A800
	push {lr}
	asrs r0, r0, #1
	subs r0, r1, r0
	cmp r0, #0
	bgt _0800A80E
	movs r0, #0
	b _0800A810
_0800A80E:
	rsbs r0, r0, #0
_0800A810:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a814
FUN_0800a814: @ 0x0800A814
	push {lr}
	ldr r2, _0800A828 @ =0xFFFFF800
	adds r1, r1, r2
	asrs r0, r0, #1
	subs r0, r1, r0
	cmp r0, #0
	bgt _0800A82C
	movs r0, #0
	b _0800A82E
	.align 2, 0
_0800A828: .4byte 0xFFFFF800
_0800A82C:
	rsbs r0, r0, #0
_0800A82E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a834
FUN_0800a834: @ 0x0800A834
	push {lr}
	asrs r0, r0, #2
	subs r0, r1, r0
	cmp r0, #0
	bgt _0800A842
	movs r0, #0
	b _0800A844
_0800A842:
	rsbs r0, r0, #0
_0800A844:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a848
FUN_0800a848: @ 0x0800A848
	push {lr}
	ldr r2, _0800A85C @ =0xFFFFFC00
	adds r1, r1, r2
	asrs r0, r0, #2
	subs r0, r1, r0
	cmp r0, #0
	bgt _0800A860
	movs r0, #0
	b _0800A862
	.align 2, 0
_0800A85C: .4byte 0xFFFFFC00
_0800A860:
	rsbs r0, r0, #0
_0800A862:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a868
FUN_0800a868: @ 0x0800A868
	push {lr}
	ldr r2, _0800A87C @ =0xFFFFF800
	adds r1, r1, r2
	asrs r0, r0, #2
	subs r0, r1, r0
	cmp r0, #0
	bgt _0800A880
	movs r0, #0
	b _0800A882
	.align 2, 0
_0800A87C: .4byte 0xFFFFF800
_0800A880:
	rsbs r0, r0, #0
_0800A882:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a888
FUN_0800a888: @ 0x0800A888
	push {lr}
	ldr r2, _0800A89C @ =0xFFFFF400
	adds r1, r1, r2
	asrs r0, r0, #2
	subs r0, r1, r0
	cmp r0, #0
	bgt _0800A8A0
	movs r0, #0
	b _0800A8A2
	.align 2, 0
_0800A89C: .4byte 0xFFFFF400
_0800A8A0:
	rsbs r0, r0, #0
_0800A8A2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a8a8
FUN_0800a8a8: @ 0x0800A8A8
	push {lr}
	asrs r0, r0, #1
	cmp r1, r0
	blt _0800A8B4
	movs r0, #0
	b _0800A8B6
_0800A8B4:
	mvns r0, r1
_0800A8B6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a8bc
FUN_0800a8bc: @ 0x0800A8BC
	push {lr}
	asrs r0, r0, #1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	cmp r1, r0
	blt _0800A8CE
	movs r0, #0
	b _0800A8D0
_0800A8CE:
	mvns r0, r1
_0800A8D0:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a8d4
FUN_0800a8d4: @ 0x0800A8D4
	push {lr}
	asrs r0, r0, #2
	cmp r1, r0
	blt _0800A8E0
	movs r0, #0
	b _0800A8E2
_0800A8E0:
	mvns r0, r1
_0800A8E2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a8e8
FUN_0800a8e8: @ 0x0800A8E8
	push {lr}
	asrs r0, r0, #2
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	cmp r1, r0
	blt _0800A8FA
	movs r0, #0
	b _0800A8FC
_0800A8FA:
	mvns r0, r1
_0800A8FC:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a900
FUN_0800a900: @ 0x0800A900
	push {lr}
	asrs r0, r0, #2
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	cmp r1, r0
	blt _0800A912
	movs r0, #0
	b _0800A914
_0800A912:
	mvns r0, r1
_0800A914:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a918
FUN_0800a918: @ 0x0800A918
	push {lr}
	asrs r0, r0, #2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
	cmp r1, r0
	blt _0800A92A
	movs r0, #0
	b _0800A92C
_0800A92A:
	mvns r0, r1
_0800A92C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a930
FUN_0800a930: @ 0x0800A930
	push {lr}
	adds r2, r1, #0
	asrs r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #5
	subs r1, r1, r0
	cmp r2, r1
	blt _0800A944
	movs r0, #0
	b _0800A946
_0800A944:
	mvns r0, r2
_0800A946:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a94c
FUN_0800a94c: @ 0x0800A94C
	push {lr}
	adds r2, r1, #0
	asrs r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #5
	subs r1, r1, r0
	cmp r2, r1
	blt _0800A960
	movs r0, #0
	b _0800A962
_0800A960:
	mvns r0, r2
_0800A962:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a968
FUN_0800a968: @ 0x0800A968
	push {lr}
	adds r2, r1, #0
	asrs r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #5
	subs r1, r1, r0
	cmp r2, r1
	blt _0800A97C
	movs r0, #0
	b _0800A97E
_0800A97C:
	mvns r0, r2
_0800A97E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a984
FUN_0800a984: @ 0x0800A984
	push {lr}
	adds r2, r1, #0
	asrs r0, r0, #2
	movs r1, #0xc0
	lsls r1, r1, #4
	subs r1, r1, r0
	cmp r2, r1
	blt _0800A998
	movs r0, #0
	b _0800A99A
_0800A998:
	mvns r0, r2
_0800A99A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a9a0
FUN_0800a9a0: @ 0x0800A9A0
	push {lr}
	adds r2, r1, #0
	asrs r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #4
	subs r1, r1, r0
	cmp r2, r1
	blt _0800A9B4
	movs r0, #0
	b _0800A9B6
_0800A9B4:
	mvns r0, r2
_0800A9B6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a9bc
FUN_0800a9bc: @ 0x0800A9BC
	push {lr}
	adds r2, r1, #0
	asrs r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0800A9D0
	movs r0, #0
	b _0800A9D2
_0800A9D0:
	mvns r0, r2
_0800A9D2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a9d8
FUN_0800a9d8: @ 0x0800A9D8
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800A9E8 @ =0x000007FF
	cmp r2, r0
	ble _0800A9EC
	mvns r0, r1
	b _0800AA02
	.align 2, 0
_0800A9E8: .4byte 0x000007FF
_0800A9EC:
	ldr r0, _0800A9FC @ =0xFFFFF000
	adds r1, r1, r0
	lsls r0, r2, #1
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800AA00
	movs r0, #0
	b _0800AA02
	.align 2, 0
_0800A9FC: .4byte 0xFFFFF000
_0800AA00:
	rsbs r0, r0, #0
_0800AA02:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800aa08
FUN_0800aa08: @ 0x0800AA08
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AA28 @ =0x000007FF
	cmp r2, r0
	ble _0800AA22
	ldr r0, _0800AA2C @ =0xFFFFF000
	adds r1, r1, r0
	ldr r3, _0800AA30 @ =0xFFFFF800
	adds r0, r2, r3
	lsls r0, r0, #1
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800AA34
_0800AA22:
	movs r0, #0
	b _0800AA36
	.align 2, 0
_0800AA28: .4byte 0x000007FF
_0800AA2C: .4byte 0xFFFFF000
_0800AA30: .4byte 0xFFFFF800
_0800AA34:
	rsbs r0, r0, #0
_0800AA36:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800aa3c
FUN_0800aa3c: @ 0x0800AA3C
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AA4C @ =0x000003FF
	cmp r2, r0
	ble _0800AA50
	mvns r0, r1
	b _0800AA66
	.align 2, 0
_0800AA4C: .4byte 0x000003FF
_0800AA50:
	ldr r0, _0800AA60 @ =0xFFFFF000
	adds r1, r1, r0
	lsls r0, r2, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800AA64
	movs r0, #0
	b _0800AA66
	.align 2, 0
_0800AA60: .4byte 0xFFFFF000
_0800AA64:
	rsbs r0, r0, #0
_0800AA66:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800aa6c
FUN_0800aa6c: @ 0x0800AA6C
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AA80 @ =0x000003FF
	cmp r2, r0
	ble _0800AA98
	ldr r0, _0800AA84 @ =0x000007FF
	cmp r2, r0
	ble _0800AA88
	mvns r0, r1
	b _0800AAA6
	.align 2, 0
_0800AA80: .4byte 0x000003FF
_0800AA84: .4byte 0x000007FF
_0800AA88:
	ldr r0, _0800AA9C @ =0xFFFFF000
	adds r1, r1, r0
	ldr r3, _0800AAA0 @ =0xFFFFFC00
	adds r0, r2, r3
	lsls r0, r0, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800AAA4
_0800AA98:
	movs r0, #0
	b _0800AAA6
	.align 2, 0
_0800AA9C: .4byte 0xFFFFF000
_0800AAA0: .4byte 0xFFFFFC00
_0800AAA4:
	rsbs r0, r0, #0
_0800AAA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800aaac
FUN_0800aaac: @ 0x0800AAAC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AAC0 @ =0x000007FF
	cmp r2, r0
	ble _0800AAD8
	ldr r0, _0800AAC4 @ =0x00000BFF
	cmp r2, r0
	ble _0800AAC8
	mvns r0, r1
	b _0800AAE6
	.align 2, 0
_0800AAC0: .4byte 0x000007FF
_0800AAC4: .4byte 0x00000BFF
_0800AAC8:
	ldr r0, _0800AADC @ =0xFFFFF000
	adds r1, r1, r0
	ldr r3, _0800AAE0 @ =0xFFFFF800
	adds r0, r2, r3
	lsls r0, r0, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800AAE4
_0800AAD8:
	movs r0, #0
	b _0800AAE6
	.align 2, 0
_0800AADC: .4byte 0xFFFFF000
_0800AAE0: .4byte 0xFFFFF800
_0800AAE4:
	rsbs r0, r0, #0
_0800AAE6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800aaec
FUN_0800aaec: @ 0x0800AAEC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AB0C @ =0x00000BFF
	cmp r2, r0
	ble _0800AB06
	ldr r0, _0800AB10 @ =0xFFFFF000
	adds r1, r1, r0
	ldr r3, _0800AB14 @ =0xFFFFF400
	adds r0, r2, r3
	lsls r0, r0, #2
	adds r0, r1, r0
	cmp r0, #0
	bgt _0800AB18
_0800AB06:
	movs r0, #0
	b _0800AB1A
	.align 2, 0
_0800AB0C: .4byte 0x00000BFF
_0800AB10: .4byte 0xFFFFF000
_0800AB14: .4byte 0xFFFFF400
_0800AB18:
	rsbs r0, r0, #0
_0800AB1A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ab20
FUN_0800ab20: @ 0x0800AB20
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AB38 @ =0x000007FF
	cmp r2, r0
	ble _0800AB40
	ldr r3, _0800AB3C @ =0xFFFFF800
	adds r0, r2, r3
	lsls r0, r0, #1
	cmp r1, r0
	bge _0800AB40
	mvns r0, r1
	b _0800AB42
	.align 2, 0
_0800AB38: .4byte 0x000007FF
_0800AB3C: .4byte 0xFFFFF800
_0800AB40:
	movs r0, #0
_0800AB42:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ab48
FUN_0800ab48: @ 0x0800AB48
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AB5C @ =0x000007FF
	cmp r2, r0
	bgt _0800AB58
	lsls r0, r2, #1
	cmp r1, r0
	bge _0800AB60
_0800AB58:
	mvns r0, r1
	b _0800AB62
	.align 2, 0
_0800AB5C: .4byte 0x000007FF
_0800AB60:
	movs r0, #0
_0800AB62:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ab68
FUN_0800ab68: @ 0x0800AB68
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AB80 @ =0x00000BFF
	cmp r2, r0
	ble _0800AB88
	ldr r3, _0800AB84 @ =0xFFFFF400
	adds r0, r2, r3
	lsls r0, r0, #2
	cmp r1, r0
	bge _0800AB88
	mvns r0, r1
	b _0800AB8A
	.align 2, 0
_0800AB80: .4byte 0x00000BFF
_0800AB84: .4byte 0xFFFFF400
_0800AB88:
	movs r0, #0
_0800AB8A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ab90
FUN_0800ab90: @ 0x0800AB90
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800ABB0 @ =0x000007FF
	cmp r2, r0
	ble _0800ABBC
	ldr r0, _0800ABB4 @ =0x00000BFF
	cmp r2, r0
	bgt _0800ABAA
	ldr r3, _0800ABB8 @ =0xFFFFF800
	adds r0, r2, r3
	lsls r0, r0, #2
	cmp r1, r0
	bge _0800ABBC
_0800ABAA:
	mvns r0, r1
	b _0800ABBE
	.align 2, 0
_0800ABB0: .4byte 0x000007FF
_0800ABB4: .4byte 0x00000BFF
_0800ABB8: .4byte 0xFFFFF800
_0800ABBC:
	movs r0, #0
_0800ABBE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800abc4
FUN_0800abc4: @ 0x0800ABC4
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800ABE4 @ =0x000003FF
	cmp r2, r0
	ble _0800ABF0
	ldr r0, _0800ABE8 @ =0x000007FF
	cmp r2, r0
	bgt _0800ABDE
	ldr r3, _0800ABEC @ =0xFFFFFC00
	adds r0, r2, r3
	lsls r0, r0, #2
	cmp r1, r0
	bge _0800ABF0
_0800ABDE:
	mvns r0, r1
	b _0800ABF2
	.align 2, 0
_0800ABE4: .4byte 0x000003FF
_0800ABE8: .4byte 0x000007FF
_0800ABEC: .4byte 0xFFFFFC00
_0800ABF0:
	movs r0, #0
_0800ABF2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800abf8
FUN_0800abf8: @ 0x0800ABF8
	push {lr}
	adds r2, r0, #0
	ldr r0, _0800AC0C @ =0x000003FF
	cmp r2, r0
	bgt _0800AC08
	lsls r0, r2, #2
	cmp r1, r0
	bge _0800AC10
_0800AC08:
	mvns r0, r1
	b _0800AC12
	.align 2, 0
_0800AC0C: .4byte 0x000003FF
_0800AC10:
	movs r0, #0
_0800AC12:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start blocking_0800ac18
blocking_0800ac18: @ 0x0800AC18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	mov sb, r1
	movs r5, #0
	ldr r0, _0800AC94 @ =0x02002200
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r5, r1
	bge _0800ACB4
	movs r7, #0xf0
	lsls r7, r7, #1
	adds r7, r7, r0
	mov ip, r7
	adds r2, #0xa
	adds r2, r0, r2
	str r2, [sp]
	adds r3, r0, #0
	movs r6, #0
	mov r8, r1
_0800AC4C:
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrh r1, [r0]
	lsls r2, r1, #1
	ldr r0, [sp]
	ldr r4, [r0]
	mov r7, sl
	subs r0, r7, r4
	adds r0, r0, r1
	cmp r2, r0
	bls _0800ACA0
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	lsls r2, r0, #1
	mov r7, ip
	ldr r1, [r7]
	mov r7, sb
	subs r1, r7, r1
	adds r1, r1, r0
	subs r1, #1
	cmp r2, r1
	bls _0800ACA0
	ldr r1, _0800AC98 @ =0x020023E4
	adds r0, r6, r1
	ldr r0, [r0]
	subs r0, r4, r0
	ldr r2, _0800AC9C @ =0x02000028
	str r0, [r2]
	movs r7, #0xeb
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrh r0, [r0]
	b _0800ACB6
	.align 2, 0
_0800AC94: .4byte 0x02002200
_0800AC98: .4byte 0x020023E4
_0800AC9C: .4byte 0x02000028
_0800ACA0:
	movs r0, #0x18
	add ip, r0
	ldr r1, [sp]
	adds r1, #0x18
	str r1, [sp]
	adds r3, #0x18
	adds r6, #0x18
	adds r5, #1
	cmp r5, r8
	blt _0800AC4C
_0800ACB4:
	movs r0, #0
_0800ACB6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800acc8
FUN_0800acc8: @ 0x0800ACC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r5, r1, #0
	ldr r6, _0800AD2C @ =0x02002200
_0800ACD8:
	movs r4, #0
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _0800AD3E
	mov sb, r0
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xee
	lsls r0, r0, #1
	adds r7, r6, r0
	mov ip, r6
_0800ACF8:
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	lsls r2, r1, #1
	ldr r0, [r7]
	mov r3, sl
	subs r0, r3, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800AD30
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r2, [r0]
	lsls r1, r2, #1
	mov r0, r8
	ldr r3, [r0]
	subs r0, r5, r3
	adds r0, r0, r2
	subs r0, #1
	cmp r1, r0
	bls _0800AD30
	subs r5, r3, r2
	b _0800ACD8
	.align 2, 0
_0800AD2C: .4byte 0x02002200
_0800AD30:
	movs r1, #0x18
	add r8, r1
	adds r7, #0x18
	add ip, r1
	adds r4, #1
	cmp r4, sb
	blt _0800ACF8
_0800AD3E:
	adds r0, r5, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ad50
FUN_0800ad50: @ 0x0800AD50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r6, r1, #0
	ldr r0, _0800ADC8 @ =0x02002200
	mov ip, r0
_0800AD62:
	movs r5, #0
	movs r0, #0xe9
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r5, r0
	bge _0800ADDA
	movs r1, #0xf0
	lsls r1, r1, #1
	add r1, ip
	mov r8, r1
	movs r7, #0xee
	lsls r7, r7, #1
	add r7, ip
	mov r3, ip
	mov sb, r0
_0800AD82:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrh r1, [r0]
	lsls r2, r1, #1
	ldr r0, [r7]
	mov r4, sl
	subs r0, r4, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800ADCC
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r2, [r0]
	lsls r1, r2, #1
	mov r0, r8
	ldr r4, [r0]
	subs r0, r6, r4
	adds r0, r0, r2
	subs r0, #1
	cmp r1, r0
	bls _0800ADCC
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800ADCC
	adds r0, r4, r2
	adds r6, r0, #1
	b _0800AD62
	.align 2, 0
_0800ADC8: .4byte 0x02002200
_0800ADCC:
	movs r4, #0x18
	add r8, r4
	adds r7, #0x18
	adds r3, #0x18
	adds r5, #1
	cmp r5, sb
	blt _0800AD82
_0800ADDA:
	adds r0, r6, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800adec
FUN_0800adec: @ 0x0800ADEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	ldr r0, _0800AE6C @ =0x02002200
	str r0, [sp, #4]
_0800AE00:
	movs r5, #0
	ldr r1, [sp, #4]
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r5, r0
	bge _0800AE7E
	movs r7, #0xf0
	lsls r7, r7, #1
	adds r7, r7, r1
	mov sb, r7
	adds r2, #0xa
	adds r2, r2, r1
	mov r8, r2
	mov ip, r1
	mov sl, r0
_0800AE22:
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r3, [r0]
	lsls r1, r3, #1
	mov r7, r8
	ldr r4, [r7]
	subs r0, r6, r4
	adds r0, r0, r3
	cmp r1, r0
	bls _0800AE70
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r2, r0, #1
	mov r7, sb
	ldr r1, [r7]
	ldr r7, [sp]
	subs r1, r7, r1
	adds r1, r1, r0
	subs r1, #1
	cmp r2, r1
	bls _0800AE70
	movs r0, #0xeb
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800AE70
	subs r0, r4, r3
	subs r6, r0, #1
	b _0800AE00
	.align 2, 0
_0800AE6C: .4byte 0x02002200
_0800AE70:
	movs r0, #0x18
	add sb, r0
	add r8, r0
	add ip, r0
	adds r5, #1
	cmp r5, sl
	blt _0800AE22
_0800AE7E:
	adds r0, r6, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800ae90
FUN_0800ae90: @ 0x0800AE90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	ldr r0, _0800AF0C @ =0x02002200
	str r0, [sp, #4]
_0800AEA4:
	movs r5, #0
	ldr r1, [sp, #4]
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r5, r0
	bge _0800AF1E
	movs r7, #0xf0
	lsls r7, r7, #1
	adds r7, r7, r1
	mov sb, r7
	adds r2, #0xa
	adds r2, r2, r1
	mov r8, r2
	mov ip, r1
	mov sl, r0
_0800AEC6:
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r3, [r0]
	lsls r1, r3, #1
	mov r7, r8
	ldr r4, [r7]
	subs r0, r6, r4
	adds r0, r0, r3
	cmp r1, r0
	bls _0800AF10
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r2, r0, #1
	mov r7, sb
	ldr r1, [r7]
	ldr r7, [sp]
	subs r1, r7, r1
	adds r1, r1, r0
	subs r1, #1
	cmp r2, r1
	bls _0800AF10
	movs r0, #0xeb
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800AF10
	adds r6, r4, r3
	b _0800AEA4
	.align 2, 0
_0800AF0C: .4byte 0x02002200
_0800AF10:
	movs r0, #0x18
	add sb, r0
	add r8, r0
	add ip, r0
	adds r5, #1
	cmp r5, sl
	blt _0800AEC6
_0800AF1E:
	adds r0, r6, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800af30
FUN_0800af30: @ 0x0800AF30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	adds r7, r1, #0
	adds r5, r2, #0
	cmp r5, r7
	bge _0800AF4E
	adds r1, r5, #0
	bl FUN_0800acc8
	b _0800AFC0
_0800AF4E:
	subs r0, r5, r7
	asrs r0, r0, #1
	mov sl, r0
	add r7, sl
	ldr r0, _0800AFD0 @ =0x02002200
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, #0
	beq _0800AFBE
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r3, r3, r0
	mov sb, r3
	adds r2, #0xa
	adds r2, r2, r0
	mov r8, r2
	mov ip, r0
	adds r6, r1, #0
_0800AF76:
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	lsls r2, r1, #1
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [sp]
	subs r0, r3, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800AFB0
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r4, [r0]
	mov r1, sl
	adds r0, r4, r1
	lsls r2, r0, #1
	mov r1, sb
	ldr r3, [r1]
	subs r1, r7, r3
	adds r1, r1, r0
	cmp r2, r1
	bls _0800AFB0
	subs r0, r3, r4
	cmp r5, r0
	ble _0800AFB0
	adds r5, r0, #0
_0800AFB0:
	movs r2, #0x18
	add sb, r2
	add r8, r2
	add ip, r2
	subs r6, #1
	cmp r6, #0
	bne _0800AF76
_0800AFBE:
	adds r0, r5, #0
_0800AFC0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800AFD0: .4byte 0x02002200

	thumb_func_start FUN_0800afd4
FUN_0800afd4: @ 0x0800AFD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	adds r7, r1, #0
	adds r5, r2, #0
	cmp r5, r7
	ble _0800AFF2
	adds r1, r5, #0
	bl FUN_0800ad50
	b _0800B078
_0800AFF2:
	subs r0, r7, r5
	asrs r0, r0, #1
	mov sl, r0
	subs r7, r7, r0
	ldr r0, _0800B088 @ =0x02002200
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, #0
	beq _0800B076
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r3, r3, r0
	mov sb, r3
	adds r2, #0xa
	adds r2, r2, r0
	mov r8, r2
	mov ip, r0
	adds r6, r1, #0
_0800B01A:
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	lsls r2, r1, #1
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [sp]
	subs r0, r3, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800B068
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r4, [r0]
	mov r1, sl
	adds r0, r4, r1
	lsls r2, r0, #1
	mov r1, sb
	ldr r3, [r1]
	subs r1, r7, r3
	adds r1, r1, r0
	cmp r2, r1
	blo _0800B068
	adds r0, r3, r4
	adds r2, r0, #1
	cmp r5, r2
	bge _0800B068
	movs r0, #0xeb
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800B068
	adds r5, r2, #0
_0800B068:
	movs r2, #0x18
	add sb, r2
	add r8, r2
	add ip, r2
	subs r6, #1
	cmp r6, #0
	bne _0800B01A
_0800B076:
	adds r0, r5, #0
_0800B078:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800B088: .4byte 0x02002200

	thumb_func_start FUN_0800b08c
FUN_0800b08c: @ 0x0800B08C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	str r1, [sp]
	adds r5, r2, #0
	cmp r5, r7
	bge _0800B0AA
	adds r0, r5, #0
	bl FUN_0800adec
	b _0800B12E
_0800B0AA:
	subs r0, r5, r7
	asrs r0, r0, #1
	mov sl, r0
	add r7, sl
	ldr r0, _0800B140 @ =0x02002200
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, #0
	beq _0800B12C
	movs r3, #0xee
	lsls r3, r3, #1
	adds r3, r3, r0
	mov sb, r3
	adds r2, #0xe
	adds r2, r2, r0
	mov r8, r2
	mov ip, r0
	adds r6, r1, #0
_0800B0D2:
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r2, r0, #1
	mov r3, r8
	ldr r1, [r3]
	ldr r3, [sp]
	subs r1, r3, r1
	adds r1, r1, r0
	cmp r2, r1
	bls _0800B11E
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r4, [r0]
	mov r0, sl
	adds r1, r4, r0
	lsls r2, r1, #1
	mov r0, sb
	ldr r3, [r0]
	subs r0, r7, r3
	adds r0, r0, r1
	cmp r2, r0
	bls _0800B11E
	subs r2, r3, r4
	cmp r5, r2
	ble _0800B11E
	movs r0, #0xeb
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800B11E
	subs r5, r2, #1
_0800B11E:
	movs r2, #0x18
	add sb, r2
	add r8, r2
	add ip, r2
	subs r6, #1
	cmp r6, #0
	bne _0800B0D2
_0800B12C:
	adds r0, r5, #0
_0800B12E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800B140: .4byte 0x02002200

	thumb_func_start FUN_0800b144
FUN_0800b144: @ 0x0800B144
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	str r1, [sp]
	adds r5, r2, #0
	cmp r5, r7
	ble _0800B162
	adds r0, r5, #0
	bl FUN_0800ae90
	b _0800B1E6
_0800B162:
	subs r0, r7, r5
	asrs r0, r0, #1
	mov sl, r0
	subs r7, r7, r0
	ldr r0, _0800B1F8 @ =0x02002200
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, #0
	beq _0800B1E4
	movs r3, #0xee
	lsls r3, r3, #1
	adds r3, r3, r0
	mov sb, r3
	adds r2, #0xe
	adds r2, r2, r0
	mov r8, r2
	mov ip, r0
	adds r6, r1, #0
_0800B18A:
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r2, r0, #1
	mov r3, r8
	ldr r1, [r3]
	ldr r3, [sp]
	subs r1, r3, r1
	adds r1, r1, r0
	cmp r2, r1
	bls _0800B1D6
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r4, [r0]
	mov r0, sl
	adds r1, r4, r0
	lsls r2, r1, #1
	mov r0, sb
	ldr r3, [r0]
	subs r0, r7, r3
	adds r0, r0, r1
	cmp r2, r0
	bls _0800B1D6
	adds r2, r3, r4
	cmp r5, r2
	bge _0800B1D6
	movs r0, #0xeb
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800B1D6
	adds r5, r2, #0
_0800B1D6:
	movs r2, #0x18
	add sb, r2
	add r8, r2
	add ip, r2
	subs r6, #1
	cmp r6, #0
	bne _0800B18A
_0800B1E4:
	adds r0, r5, #0
_0800B1E6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800B1F8: .4byte 0x02002200

.include "asm/stage_gfx/unk_stage.s"
.include "asm/stage_gfx/spacecraft.s"
.include "asm/stage_gfx/volcano.s"
.include "asm/stage_gfx/ocean.s"
.include "asm/stage_gfx/repair_factory.s"
.include "asm/stage_gfx/old_life_space.s"
.include "asm/stage_gfx/missile_factory.s"
.include "asm/stage_gfx/twilight_desert.s"
.include "asm/stage_gfx/anatre_forest.s"
.include "asm/stage_gfx/frost_base_line.s"
.include "asm/stage_gfx/area_x2.s"
.include "asm/stage_gfx/energy_facility.s"
.include "asm/stage_gfx/snowy_plains.s"
.include "asm/stage_gfx/sunken_library.s"
.include "asm/stage_gfx/giant_elevator.s"
.include "asm/stage_gfx/sub_arcadia.s"
.include "asm/stage_gfx/weil_labo.s"
.include "asm/stage_gfx/resistance_base.s"

	thumb_func_start resetData_08016db4
resetData_08016db4: @ 0x08016DB4
	push {lr}
	bl FUN_08017aa8
	ldr r0, _08016DF0 @ =0x0202F34C
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08016DF4 @ =0x0202F344
	strb r1, [r0]
	ldr r0, _08016DF8 @ =0x0202F330
	strb r1, [r0]
	ldr r0, _08016DFC @ =0x0202F380
	movs r1, #0
	str r1, [r0]
	ldr r0, _08016E00 @ =0x0202F38C
	str r1, [r0]
	ldr r0, _08016E04 @ =0x0202F35C
	str r1, [r0]
	ldr r0, _08016E08 @ =0x0202F348
	strb r1, [r0]
	ldr r0, _08016E0C @ =0x0202F358
	strb r1, [r0]
	ldr r0, _08016E10 @ =0x0202F338
	strb r1, [r0]
	ldr r0, _08016E14 @ =0x0202F350
	strb r1, [r0]
	ldr r0, _08016E18 @ =0x0202F33C
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08016DF0: .4byte 0x0202F34C
_08016DF4: .4byte 0x0202F344
_08016DF8: .4byte 0x0202F330
_08016DFC: .4byte 0x0202F380
_08016E00: .4byte 0x0202F38C
_08016E04: .4byte 0x0202F35C
_08016E08: .4byte 0x0202F348
_08016E0C: .4byte 0x0202F358
_08016E10: .4byte 0x0202F338
_08016E14: .4byte 0x0202F350
_08016E18: .4byte 0x0202F33C
