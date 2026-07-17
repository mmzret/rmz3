	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start phantom_0805f198
phantom_0805f198: @ 0x0805F198
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, [r5, #0x5c]
	bl FUN_08060864
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805F208
	ldrb r4, [r5, #0xa]
	lsrs r4, r4, #4
	movs r6, #1
	ands r4, r6
	adds r0, r5, #0
	bl FUN_08060838
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bne _0805F208
	ldr r4, _0805F1F8 @ =pZero2
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	ldr r2, [r5, #0x54]
	subs r1, r0, r2
	ldr r0, _0805F1FC @ =0x000040C0
	adds r1, r1, r0
	ldr r0, _0805F200 @ =0x00008180
	cmp r1, r0
	bhi _0805F20C
	ldr r1, [r5, #0x58]
	adds r0, r2, #0
	bl FUN_08009f6c
	ldr r1, [r4]
	ldr r1, [r1, #0x58]
	subs r1, r0, r1
	ldr r0, _0805F204 @ =0x000013FF
	cmp r1, r0
	bgt _0805F20C
	movs r0, #0xfb
	bl PlaySound
	strb r6, [r5, #0xf]
	adds r0, r5, #0
	movs r1, #7
	bl FUN_080607a0
	b _0805F20C
	.align 2, 0
_0805F1F8: .4byte pZero2
_0805F1FC: .4byte 0x000040C0
_0805F200: .4byte 0x00008180
_0805F204: .4byte 0x000013FF
_0805F208:
	movs r0, #2
	strh r0, [r5, #0xe]
_0805F20C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f214
FUN_0805f214: @ 0x0805F214
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x71
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _0805F22E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805F264 @ =0x08365320
	bl SetDDP
_0805F22E:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #3
	bne _0805F240
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805F268 @ =sCollisions
	bl SetDDP
_0805F240:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08060864
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F25E
	movs r0, #2
	strh r0, [r4, #0xe]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080607a0
_0805F25E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805F264: .4byte 0x08365320
_0805F268: .4byte sCollisions

