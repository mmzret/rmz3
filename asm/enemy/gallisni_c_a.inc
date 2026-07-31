	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Gallisni_Init
Gallisni_Init: @ 0x08087200
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808727C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08087280 @ =0x08368758
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08087284 @ =0x083686D8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08087288 @ =FUN_08086ff0
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb4
	str r5, [r0]
	ldrb r4, [r6, #0x10]
	cmp r4, #0
	bne _08087270
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r4, [r0]
_08087270:
	adds r0, r6, #0
	bl Gallisni_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808727C: .4byte gEnemyFnTable
_08087280: .4byte 0x08368758
_08087284: .4byte 0x083686D8
_08087288: .4byte FUN_08086ff0
