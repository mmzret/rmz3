	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800e308
FUN_0800e308: @ 0x0800E308
	push {lr}
	ldr r1, [r0]
	ldr r2, _0800E32C @ =0xFFFFF000
	adds r1, r1, r2
	asrs r1, r1, #0xc
	ldr r0, [r0, #4]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	asrs r3, r0, #0xc
	cmp r3, #0x13
	bgt _0800E334
	adds r2, r1, #0
	subs r2, #0xf8
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E330 @ =0x0833DFE2
	b _0800E342
	.align 2, 0
_0800E32C: .4byte 0xFFFFF000
_0800E330: .4byte 0x0833DFE2
_0800E334:
	cmp r3, #0x38
	ble _0800E354
	adds r2, r1, #0
	subs r2, #0xf6
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E350 @ =0x0833E032
_0800E342:
	adds r2, r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl PatchMetatileMap
	b _0800E368
	.align 2, 0
_0800E350: .4byte 0x0833E032
_0800E354:
	adds r2, r1, #0
	subs r2, #0xf2
	asrs r2, r2, #1
	lsls r2, r2, #3
	ldr r0, _0800E36C @ =0x0833DFFA
	adds r2, r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl PatchMetatileMap
_0800E368:
	pop {r0}
	bx r0
	.align 2, 0
_0800E36C: .4byte 0x0833DFFA

