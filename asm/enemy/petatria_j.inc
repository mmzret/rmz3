	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809118c
FUN_0809118c: @ 0x0809118C
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r0, _080911F8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r7]
	subs r4, r1, r0
	ldr r0, [r7, #4]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	subs r5, r1, r0
	asrs r0, r4, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r5, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0xe
	cmp r6, #0
	beq _080911D8
	lsls r0, r4, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	adds r5, r0, #0
_080911D8:
	cmp r4, #0
	ble _0809122A
	cmp r5, #0
	ble _08091206
	ldr r0, _080911FC @ =gSineTable
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08091200
	movs r0, #0x7e
	subs r0, r0, r2
	b _0809123E
	.align 2, 0
_080911F8: .4byte pZero2
_080911FC: .4byte gSineTable
_08091200:
	adds r0, r2, #0
	adds r0, #0x7e
	b _0809123E
_08091206:
	ldr r0, _08091220 @ =gSineTable
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08091224
	adds r0, r2, #0
	adds r0, #0x7f
	b _0809123E
	.align 2, 0
_08091220: .4byte gSineTable
_08091224:
	rsbs r0, r2, #0
	adds r0, #0x7f
	b _0809123E
_0809122A:
	cmp r5, #0
	ble _08091248
	ldr r0, _08091244 @ =gSineTable
	adds r1, r5, #0
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
_0809123E:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _08091256
	.align 2, 0
_08091244: .4byte gSineTable
_08091248:
	ldr r1, _08091278 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrb r2, [r0]
_08091256:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r7, #0
	bl CreateLemon
	adds r1, r0, #0
	cmp r1, #0
	beq _08091272
	lsls r0, r4, #9
	asrs r0, r0, #8
	str r0, [r1, #0x5c]
	lsls r0, r5, #9
	asrs r0, r0, #8
	str r0, [r1, #0x60]
_08091272:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091278: .4byte gSineTable

