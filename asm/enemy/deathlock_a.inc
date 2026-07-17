	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808d160
FUN_0808d160: @ 0x0808D160
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #0
	bge _0808D1E8
	ldr r4, _0808D1DC @ =0xFFFFEE00
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	str r0, [sp]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D1E0 @ =0xFFFFF100
	adds r1, r1, r2
	bl PushoutToRight1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D1E4 @ =0xFFFFE200
	adds r1, r1, r2
	bl PushoutToRight1
	str r0, [sp, #8]
	movs r0, #0
_0808D19E:
	adds r4, r0, #1
	adds r3, r4, #0
	cmp r4, #2
	bgt _0808D1C4
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r1, r0
	lsls r0, r4, #2
	add r0, sp
_0808D1B0:
	ldr r1, [r5]
	ldr r2, [r0]
	cmp r1, r2
	bge _0808D1BC
	str r2, [r5]
	str r1, [r0]
_0808D1BC:
	adds r0, #4
	adds r3, #1
	cmp r3, #2
	ble _0808D1B0
_0808D1C4:
	adds r0, r4, #0
	cmp r0, #1
	ble _0808D19E
	ldr r1, [sp]
	cmp r1, #0
	ble _0808D25C
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #1
	b _0808D25E
	.align 2, 0
_0808D1DC: .4byte 0xFFFFEE00
_0808D1E0: .4byte 0xFFFFF100
_0808D1E4: .4byte 0xFFFFE200
_0808D1E8:
	movs r4, #0x90
	lsls r4, r4, #5
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	str r0, [sp]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D254 @ =0xFFFFF100
	adds r1, r1, r2
	bl PushoutToLeft1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D258 @ =0xFFFFE200
	adds r1, r1, r2
	bl PushoutToLeft1
	str r0, [sp, #8]
	movs r0, #0
_0808D218:
	adds r4, r0, #1
	adds r3, r4, #0
	cmp r4, #2
	bgt _0808D23E
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r1, r0
	lsls r0, r4, #2
	add r0, sp
_0808D22A:
	ldr r1, [r5]
	ldr r2, [r0]
	cmp r1, r2
	ble _0808D236
	str r2, [r5]
	str r1, [r0]
_0808D236:
	adds r0, #4
	adds r3, #1
	cmp r3, #2
	ble _0808D22A
_0808D23E:
	adds r0, r4, #0
	cmp r0, #1
	ble _0808D218
	ldr r1, [sp]
	cmp r1, #0
	bge _0808D25C
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #2
	b _0808D25E
	.align 2, 0
_0808D254: .4byte 0xFFFFF100
_0808D258: .4byte 0xFFFFE200
_0808D25C:
	movs r0, #0
_0808D25E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808d268
FUN_0808d268: @ 0x0808D268
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [r7, #0x58]
	adds r2, r0, r1
	str r2, [r7, #0x58]
	cmp r1, #0
	bge _0808D2B4
	ldr r0, [r7, #0x54]
	ldr r1, _0808D2AC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r4, _0808D2B0 @ =0xFFFFE200
	adds r1, r2, r4
	bl PushoutToDown1
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl PushoutToDown1
	adds r6, r0, #0
	cmp r5, r6
	bge _0808D29E
	adds r5, r0, #0
_0808D29E:
	cmp r5, #0
	ble _0808D2EC
	ldr r0, [r7, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	movs r0, #1
	b _0808D2EE
	.align 2, 0
_0808D2AC: .4byte 0xFFFFEE00
_0808D2B0: .4byte 0xFFFFE200
_0808D2B4:
	ldr r0, [r7, #0x54]
	ldr r1, _0808D2E8 @ =0xFFFFEE00
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToUp1
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r5, r6
	ble _0808D2D8
	adds r5, r0, #0
_0808D2D8:
	cmp r5, #0
	bge _0808D2EC
	ldr r0, [r7, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	movs r0, #2
	b _0808D2EE
	.align 2, 0
_0808D2E8: .4byte 0xFFFFEE00
_0808D2EC:
	movs r0, #0
_0808D2EE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

