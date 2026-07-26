	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080aa15c
FUN_080aa15c: @ 0x080AA15C
	push {r4, r5, r6, lr}
	adds r3, r1, #0
	adds r3, #8
	ldr r2, [r0, #8]
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bhi _080AA242
	ldr r0, [r2, #0x54]
	ldr r1, [r1, #8]
	subs r0, r0, r1
	asrs r4, r0, #8
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r3, #4]
	subs r0, r0, r1
	asrs r0, r0, #8
	adds r6, r0, #0
	subs r6, #0x20
	ldrb r1, [r2, #0x13]
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bls _080AA19C
	ldr r1, _080AA194 @ =gPaletteManager
	ldr r5, _080AA198 @ =0x00007FFF
	b _080AA1A0
	.align 2, 0
_080AA194: .4byte gPaletteManager
_080AA198: .4byte 0x00007FFF
_080AA19C:
	ldr r1, _080AA1D0 @ =gPaletteManager
	ldr r5, _080AA1D4 @ =0x000003FF
_080AA1A0:
	adds r0, r5, #0
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3]
	subs r0, r0, r1
	lsls r0, r0, #8
	lsrs r5, r0, #0x10
	lsls r0, r4, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r5, #0x10
	lsls r0, r2, #0x10
	cmp r1, r0
	ble _080AA1C2
	lsrs r5, r0, #0x10
	lsrs r2, r1, #0x10
_080AA1C2:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA1D8
	movs r5, #0
	b _080AA1DE
	.align 2, 0
_080AA1D0: .4byte gPaletteManager
_080AA1D4: .4byte 0x000003FF
_080AA1D8:
	cmp r0, #0xf0
	ble _080AA1DE
	movs r5, #0xf0
_080AA1DE:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA1EA
	movs r2, #0
	b _080AA1F0
_080AA1EA:
	cmp r0, #0xf0
	ble _080AA1F0
	movs r2, #0xf0
_080AA1F0:
	adds r1, r6, #0
	subs r1, #8
	lsls r1, r1, #0x10
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	bge _080AA20A
	movs r6, #0
	b _080AA210
_080AA20A:
	cmp r1, #0xa0
	ble _080AA210
	movs r6, #0xa0
_080AA210:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA21C
	movs r4, #0
	b _080AA222
_080AA21C:
	cmp r0, #0xa0
	ble _080AA222
	movs r4, #0xa0
_080AA222:
	ldr r3, _080AA248 @ =gWindowRegBuffer
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	movs r2, #0xff
	ands r1, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #6]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ands r0, r2
	lsls r1, r6, #0x10
	asrs r1, r1, #8
	orrs r0, r1
	strh r0, [r3, #0xa]
_080AA242:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA248: .4byte gWindowRegBuffer

