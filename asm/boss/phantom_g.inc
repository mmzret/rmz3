	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805fa5c
FUN_0805fa5c: @ 0x0805FA5C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r5, #0
	movs r6, #1
	movs r4, #1
	strb r4, [r7, #0xf]
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	movs r1, #0x2e
	bl __divsi3
	str r0, [r7, #0x5c]
	ldr r0, _0805FAB4 @ =0xFFFFFA40
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl FUN_080608c8
	adds r0, r7, #0
	adds r0, #0xc4
	str r5, [r0]
	adds r0, #4
	strb r4, [r0]
	ldr r2, _0805FAB8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805FABC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805FAC0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r6
	adds r1, r7, #0
	adds r1, #0xc9
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0805fac4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805FAB4: .4byte 0xFFFFFA40
_0805FAB8: .4byte RNG_0202f388
_0805FABC: .4byte 0x000343FD
_0805FAC0: .4byte 0x00269EC3
