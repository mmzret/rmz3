	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e3388
FUN_080e3388: @ 0x080E3388
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r2
	mov r8, r3
	ldr r5, [sp, #0x1c]
	ldr r0, [r1]
	ldr r2, [r7]
	subs r0, r0, r2
	ldr r1, [r1, #4]
	ldr r2, [r7, #4]
	subs r1, r1, r2
	bl CalcAngle
	adds r6, r0, #0
	mov r0, sb
	ldr r4, [r0]
	adds r3, r6, #0
	cmp r4, #0
	ble _080E33D0
	mov r1, r8
	ldrb r3, [r1]
	subs r0, r6, r3
	adds r0, #0x3f
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7e
	bgt _080E33D0
	adds r0, r6, #0
	adds r1, r3, #0
	ldr r2, [sp, #0x34]
	bl FUN_080e964c
	adds r3, r0, #0
_080E33D0:
	mov r0, r8
	strb r3, [r0]
	subs r0, r6, r3
	adds r0, #0x3f
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7e
	bgt _080E33F2
	cmp r5, #0
	bgt _080E33E8
	ldr r5, [sp, #0x20]
	b _080E33F4
_080E33E8:
	ldr r1, [sp, #0x24]
	cmp r5, r1
	ble _080E33F4
	adds r5, r1, #0
	b _080E33F4
_080E33F2:
	movs r5, #0
_080E33F4:
	cmp r4, r5
	beq _080E3422
	cmp r4, r5
	bge _080E3406
	ldr r0, [sp, #0x2c]
	adds r4, r4, r0
	cmp r4, r5
	ble _080E341E
	b _080E341C
_080E3406:
	ldr r1, [sp, #0x28]
	cmp r1, #0
	ble _080E3414
	cmp r4, r1
	ble _080E3414
	ldr r0, [sp, #0x30]
	b _080E3416
_080E3414:
	ldr r0, [sp, #0x2c]
_080E3416:
	subs r4, r4, r0
	cmp r4, r5
	bge _080E341E
_080E341C:
	adds r4, r5, #0
_080E341E:
	mov r1, sb
	str r4, [r1]
_080E3422:
	cmp r4, #0
	ble _080E3458
	ldr r2, _080E3464 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r7]
	adds r0, r0, r1
	str r0, [r7]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r7, #4]
	adds r0, r0, r1
	str r0, [r7, #4]
_080E3458:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E3464: .4byte gSineTable

