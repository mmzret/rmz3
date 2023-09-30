	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e5048
FUN_080e5048: @ 0x080E5048
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080E5094 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E508C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E5098 @ =gElfFnTable
	movs r0, #0xb
	strb r0, [r3, #9]
	ldr r0, [r1, #0x2c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	adds r0, #0x92
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	strb r4, [r3, #0x10]
	strb r1, [r3, #0x11]
_080E508C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080E5094: .4byte gElfHeaderPtr
_080E5098: .4byte gElfFnTable

	thumb_func_start Elf11_Init
Elf11_Init: @ 0x080E509C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080E50F4 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x22
	movs r5, #1
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xb]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0xa]
	orrs r0, r5
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E50F8 @ =0x08371DF8
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Elf11_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E50F4: .4byte gElfFnTable
_080E50F8: .4byte 0x08371DF8

	thumb_func_start Elf11_Update
Elf11_Update: @ 0x080E50FC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _080E5154 @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	bne _080E5170
	ldr r1, _080E5158 @ =0x00000232
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E5160
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E515C @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080E5170
	.align 2, 0
_080E5154: .4byte gPause
_080E5158: .4byte 0x00000232
_080E515C: .4byte gElfFnTable
_080E5160:
	ldr r0, _080E5178 @ =0x08371E08
	ldrb r1, [r4, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_080E5170:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5178: .4byte 0x08371E08

	thumb_func_start Elf11_Die
Elf11_Die: @ 0x080E517C
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080E51AC @ =gElfFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080E51AC: .4byte gElfFnTable

	thumb_func_start FUN_080e51b0
FUN_080e51b0: @ 0x080E51B0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	adds r0, #4
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	adds r5, r6, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _080E51F8
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E51FE
_080E51F8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E51FE:
	strb r0, [r6, #0xa]
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _080E529C
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	bne _080E525E
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080E529C
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
	beq _080E5294
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E529A
_080E525E:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
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
	beq _080E5294
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E529A
_080E5294:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E529A:
	strb r0, [r6, #0xa]
_080E529C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	bl FUN_08034520
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6, #0xa]
	movs r1, #4
	movs r5, #0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _080E52EC @ =0x08371E18
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E52F0
	movs r0, #0xc0
	lsls r0, r0, #3
	b _080E52F2
	.align 2, 0
_080E52EC: .4byte 0x08371E18
_080E52F0:
	ldr r0, _080E52FC @ =0xFFFFFA00
_080E52F2:
	str r0, [r6, #0x5c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E52FC: .4byte 0xFFFFFA00

	thumb_func_start FUN_080e5300
FUN_080e5300: @ 0x080E5300
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r7, #0
	bl SetMotion
	adds r6, r7, #0
	adds r6, #0x4c
	movs r0, #0
	strb r0, [r6]
	movs r1, #0x4a
	adds r1, r1, r7
	mov sl, r1
	ldrb r1, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r2, sl
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	bl FUN_08034520
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r7, #0xa]
	movs r2, #4
	orrs r1, r2
	strb r1, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _080E53DC @ =0x08371E18
	adds r1, r1, r0
	adds r5, r7, #0
	adds r5, #0x54
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	mov r2, r8
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	adds r0, r5, #0
	bl FUN_080e1608
	adds r1, r0, #0
	str r1, [r7, #0x2c]
	cmp r1, #0
	beq _080E53E4
	mov r0, sp
	bl FUN_080e16c4
	ldr r2, [sp]
	ldr r3, [sp, #4]
	ldr r0, [r7, #0x54]
	subs r0, r2, r0
	ldr r1, [r7, #0x58]
	subs r1, r3, r1
	bl CalcAngle
	adds r2, r7, #0
	adds r2, #0xbc
	strb r0, [r2]
	ldr r3, _080E53E0 @ =gSineTable
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	str r0, [r7, #0x5c]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	b _080E5494
	.align 2, 0
_080E53DC: .4byte 0x08371E18
_080E53E0: .4byte gSineTable
_080E53E4:
	mov r4, sb
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _080E547C
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	mov r0, sb
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	bne _080E5440
	mov r0, sb
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080E547C
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	strb r0, [r6]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	lsls r3, r1, #4
	mov r0, sl
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, sl
	strb r0, [r2]
	cmp r1, #0
	beq _080E5474
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E547A
_080E5440:
	mov r4, sb
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	strb r0, [r6]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	lsls r3, r1, #4
	mov r0, sl
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, sl
	strb r0, [r2]
	cmp r1, #0
	beq _080E5474
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E547A
_080E5474:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E547A:
	strb r0, [r7, #0xa]
_080E547C:
	mov r4, sb
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E548E
	movs r0, #0xc0
	lsls r0, r0, #3
	b _080E5490
_080E548E:
	ldr r0, _080E54A8 @ =0xFFFFFA00
_080E5490:
	str r0, [r7, #0x5c]
	movs r0, #0
_080E5494:
	str r0, [r7, #0x60]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E54A8: .4byte 0xFFFFFA00

	thumb_func_start FUN_080e54ac
FUN_080e54ac: @ 0x080E54AC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	adds r0, #4
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	adds r5, r6, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _080E54F4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E54FA
_080E54F4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E54FA:
	strb r0, [r6, #0xa]
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _080E5598
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	bne _080E555A
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080E5598
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
	beq _080E5590
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E5596
_080E555A:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
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
	beq _080E5590
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E5596
_080E5590:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E5596:
	strb r0, [r6, #0xa]
_080E5598:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	bl FUN_0803455c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6, #0xa]
	movs r1, #4
	movs r5, #0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _080E55E8 @ =0x08371E18
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E55EC
	movs r0, #0x80
	lsls r0, r0, #3
	b _080E55EE
	.align 2, 0
_080E55E8: .4byte 0x08371E18
_080E55EC:
	ldr r0, _080E5600 @ =0xFFFFFC00
_080E55EE:
	str r0, [r6, #0x5c]
	ldr r0, _080E5604 @ =0xFFFFFD00
	str r0, [r6, #0x60]
	movs r0, #0xb4
	strb r0, [r6, #0x12]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E5600: .4byte 0xFFFFFC00
_080E5604: .4byte 0xFFFFFD00

	thumb_func_start FUN_080e5608
FUN_080e5608: @ 0x080E5608
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xb8
	ldr r7, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl SetMotion
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
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
	beq _080E564A
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E5650
_080E564A:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E5650:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	bl FUN_0803455c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6, #0xa]
	movs r1, #4
	movs r5, #0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080E569C @ =0x08371F08
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	movs r0, #0x27
	bl PlaySound
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E569C: .4byte 0x08371F08

	thumb_func_start FUN_080e56a0
FUN_080e56a0: @ 0x080E56A0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_080e586c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E56C6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E56E4
_080E56C6:
	ldr r1, _080E56E0 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
	b _080E570C
	.align 2, 0
_080E56E0: .4byte gElfFnTable
_080E56E4:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _080E570C
	movs r0, #0x2b
	bl PlaySound
	ldr r1, _080E5714 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
_080E570C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E5714: .4byte gElfFnTable

	thumb_func_start FUN_080e5718
FUN_080e5718: @ 0x080E5718
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl FUN_080e586c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E5746
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E5764
_080E5746:
	ldr r1, _080E5760 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
	b _080E578C
	.align 2, 0
_080E5760: .4byte gElfFnTable
_080E5764:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _080E578C
	movs r0, #0x2b
	bl PlaySound
	ldr r1, _080E5794 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
_080E578C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E5794: .4byte gElfFnTable

	thumb_func_start FUN_080e5798
FUN_080e5798: @ 0x080E5798
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _080E57BE
	str r0, [r4, #0x60]
_080E57BE:
	adds r0, r4, #0
	bl FUN_080e586c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #0x12]
	subs r2, r1, #1
	strb r2, [r4, #0x12]
	cmp r0, #1
	beq _080E57E6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080E5810 @ =0x00001004
	ands r0, r1
	cmp r0, #0
	bne _080E57E6
	lsls r0, r2, #0x18
	cmp r0, #0
	bne _080E5808
_080E57E6:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #3
	bl FUN_080e5048
	ldr r1, _080E5814 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
_080E5808:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5810: .4byte 0x00001004
_080E5814: .4byte gElfFnTable

	thumb_func_start FUN_080e5818
FUN_080e5818: @ 0x080E5818
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080E5840
	movs r1, #0
	str r1, [r3]
	adds r0, r2, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
_080E5840:
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E5862
	ldr r1, _080E5868 @ =gElfFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl Elf11_Die
_080E5862:
	pop {r0}
	bx r0
	.align 2, 0
_080E5868: .4byte gElfFnTable

	thumb_func_start FUN_080e586c
FUN_080e586c: @ 0x080E586C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r2, _080E5894 @ =0x7FF20000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080E5888
	movs r1, #0
_080E5888:
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	beq _080E5898
	movs r0, #1
	b _080E58B6
	.align 2, 0
_080E5894: .4byte 0x7FF20000
_080E5898:
	ldr r0, _080E58B0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bhi _080E58B4
	movs r0, #0
	b _080E58B6
	.align 2, 0
_080E58B0: .4byte gStageRun+232
_080E58B4:
	movs r0, #2
_080E58B6:
	pop {r4}
	pop {r1}
	bx r1
