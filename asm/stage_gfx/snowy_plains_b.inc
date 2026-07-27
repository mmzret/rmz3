	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080133e8
FUN_080133e8: @ 0x080133E8
	push {r4, r5, r6, lr}
	ldr r1, [r0]
	ldr r2, _08013408 @ =0xFFFFF800
	adds r1, r1, r2
	asrs r5, r1, #0xc
	ldr r0, [r0, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	asrs r6, r0, #0xc
	ldr r0, _0801340C @ =0x0000018B
	cmp r5, r0
	bne _08013414
	ldr r4, _08013410 @ =0x08343F58
	b _08013444
	.align 2, 0
_08013408: .4byte 0xFFFFF800
_0801340C: .4byte 0x0000018B
_08013410: .4byte 0x08343F58
_08013414:
	ldr r0, _08013420 @ =0x00000193
	cmp r5, r0
	bne _08013428
	ldr r4, _08013424 @ =0x08343F58
	b _08013444
	.align 2, 0
_08013420: .4byte 0x00000193
_08013424: .4byte 0x08343F58
_08013428:
	ldr r0, _08013434 @ =0x000001AB
	cmp r5, r0
	bne _0801343C
	ldr r4, _08013438 @ =0x08343F60
	b _08013444
	.align 2, 0
_08013434: .4byte 0x000001AB
_08013438: .4byte 0x08343F60
_0801343C:
	ldr r0, _0801345C @ =0x000001B9
	cmp r5, r0
	bne _08013464
	ldr r4, _08013460 @ =0x08343F68
_08013444:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl PatchMetatileMap
	adds r1, r6, #1
	adds r0, r5, #0
	adds r2, r4, #0
	bl PatchMetatileMap
	b _0801347A
	.align 2, 0
_0801345C: .4byte 0x000001B9
_08013460: .4byte 0x08343F68
_08013464:
	ldr r4, _08013480 @ =0x08343F50
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl PatchMetatileMap
	adds r1, r6, #1
	adds r0, r5, #0
	adds r2, r4, #0
	bl PatchMetatileMap
_0801347A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013480: .4byte 0x08343F50
