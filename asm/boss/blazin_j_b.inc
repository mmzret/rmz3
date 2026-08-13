	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazin_080402fc
blazin_080402fc: @ 0x080402FC
	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _0804032A
	movs r2, #0
	ldr r5, _0804031C @ =UnkBlaizinModes_080fed5a
	adds r3, r5, #0
_0804030A:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08040320
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0804030A
	b _0804035C
	.align 2, 0
_0804031C: .4byte UnkBlaizinModes_080fed5a
_08040320:
	adds r0, r2, #1
	movs r1, #5
	bl __modsi3
	b _08040346
_0804032A:
	movs r2, #0
	ldr r5, _08040350 @ =UnkBlaizinModes_080fed5a
	adds r3, r5, #0
_08040330:
	ldrh r1, [r3]
	cmp r1, r4
	bne _08040354
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _08040340
	adds r0, r2, #4
_08040340:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
_08040346:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0804035C
	.align 2, 0
_08040350: .4byte UnkBlaizinModes_080fed5a
_08040354:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _08040330
_0804035C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
