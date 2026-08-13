	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080140a8
FUN_080140a8: @ 0x080140A8
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x34]
	ldr r0, _080140CC @ =0x00000B3F
	cmp r1, r0
	bgt _080140D8
	ldr r1, [r2, #0x38]
	ldr r0, _080140D0 @ =0x000003BF
	cmp r1, r0
	bgt _080140D8
	movs r0, #0x40
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	ldr r0, _080140D4 @ =0x000004EC
	str r0, [r2, #0x4c]
	movs r0, #0xf0
	b _08014118
	.align 2, 0
_080140CC: .4byte 0x00000B3F
_080140D0: .4byte 0x000003BF
_080140D4: .4byte 0x000004EC
_080140D8:
	ldr r1, [r2, #0x34]
	ldr r0, _080140FC @ =0x00000EFF
	cmp r1, r0
	bgt _0801410A
	movs r0, #0x80
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	movs r0, #0xb4
	lsls r0, r0, #3
	str r0, [r2, #0x4c]
	ldr r1, [r2, #0x38]
	ldr r0, _08014100 @ =0x000003BF
	cmp r1, r0
	bgt _08014104
	movs r0, #0xc8
	lsls r0, r0, #1
	b _08014118
	.align 2, 0
_080140FC: .4byte 0x00000EFF
_08014100: .4byte 0x000003BF
_08014104:
	movs r0, #0xc8
	lsls r0, r0, #2
	b _08014118
_0801410A:
	movs r0, #0x80
	str r0, [r2, #0x44]
	str r0, [r2, #0x48]
	ldr r0, _08014120 @ =0x000008E8
	str r0, [r2, #0x4c]
	movs r0, #0x82
	lsls r0, r0, #3
_08014118:
	str r0, [r2, #0x50]
	pop {r0}
	bx r0
	.align 2, 0
_08014120: .4byte 0x000008E8

	thumb_func_start giant_elevator_08014124
giant_elevator_08014124: @ 0x08014124
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	bne _08014168
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r4, r3, #1
	ldr r5, _08014178 @ =gVideoRegBuffer+4
	adds r4, r4, r5
	ldr r1, [r6, #0x60]
	ldr r2, [r6, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r4]
	lsls r3, r3, #2
	adds r5, #8
	adds r3, r3, r5
	str r7, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _0801417C @ =gBgMapOffsets
	str r7, [sp]
	movs r2, #0x62
	movs r3, #0
	bl LoadBgMap
	strh r7, [r6, #0x10]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08014168:
	ldr r1, [r6, #0x34]
	ldr r0, _08014180 @ =0x0000034F
	cmp r1, r0
	bgt _08014184
	ldrh r0, [r6, #0x10]
	subs r0, #1
	b _08014188
	.align 2, 0
_08014178: .4byte gVideoRegBuffer+4
_0801417C: .4byte gBgMapOffsets
_08014180: .4byte 0x0000034F
_08014184:
	ldrh r0, [r6, #0x10]
	adds r0, #1
_08014188:
	strh r0, [r6, #0x10]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08014194
FUN_08014194: @ 0x08014194
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, _080141B4 @ =0x0000034F
	cmp r3, r0
	bgt _080141BC
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _080141B8 @ =gVideoRegBuffer+12
	adds r0, r0, r1
	adds r1, r3, #0
	subs r1, #0xf0
	b _080141C8
	.align 2, 0
_080141B4: .4byte 0x0000034F
_080141B8: .4byte gVideoRegBuffer+12
_080141BC:
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _080141E4 @ =gVideoRegBuffer+12
	adds r0, r0, r1
	ldr r5, _080141E8 @ =0xFFFFFB50
	adds r1, r3, r5
_080141C8:
	asrs r1, r1, #1
	strh r1, [r0]
	lsrs r2, r2, #4
	lsls r2, r2, #2
	ldr r0, _080141EC @ =0x0200214E
	adds r2, r2, r0
	ldr r1, [r4, #0x38]
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #1
	adds r1, r1, r0
	strh r1, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080141E4: .4byte gVideoRegBuffer+12
_080141E8: .4byte 0xFFFFFB50
_080141EC: .4byte gVideoRegBuffer+0xE

	thumb_func_start FUN_080141f0
FUN_080141f0: @ 0x080141F0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0801422C
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x14
	lsls r3, r3, #1
	ldr r1, _0801423C @ =gVideoRegBuffer+4
	adds r3, r3, r1
	ldr r1, [r4, #0x60]
	ldr r2, [r4, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #8
	lsrs r0, r0, #0x18
	ldr r1, _08014240 @ =gBgMapOffsets
	str r5, [sp]
	movs r2, #0x61
	movs r3, #0
	bl LoadBgMap
	strh r5, [r4, #0x10]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801422C:
	ldr r1, [r4, #0x34]
	ldr r0, _08014244 @ =0x0000034F
	cmp r1, r0
	bgt _08014248
	ldrh r0, [r4, #0x10]
	adds r0, #1
	b _0801424C
	.align 2, 0
_0801423C: .4byte gVideoRegBuffer+4
_08014240: .4byte gBgMapOffsets
_08014244: .4byte 0x0000034F
_08014248:
	ldrh r0, [r4, #0x10]
	subs r0, #1
_0801424C:
	strh r0, [r4, #0x10]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08014258
FUN_08014258: @ 0x08014258
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, _08014278 @ =0x0000034F
	cmp r3, r0
	bgt _08014280
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _0801427C @ =gVideoRegBuffer+12
	adds r0, r0, r1
	adds r1, r3, #0
	subs r1, #0xf0
	b _0801428C
	.align 2, 0
_08014278: .4byte 0x0000034F
_0801427C: .4byte gVideoRegBuffer+12
_08014280:
	lsrs r0, r1, #0x14
	lsls r0, r0, #2
	ldr r1, _080142A8 @ =gVideoRegBuffer+12
	adds r0, r0, r1
	ldr r5, _080142AC @ =0xFFFFFB50
	adds r1, r3, r5
_0801428C:
	asrs r1, r1, #2
	strh r1, [r0]
	lsrs r2, r2, #4
	lsls r2, r2, #2
	ldr r0, _080142B0 @ =0x0200214E
	adds r2, r2, r0
	ldr r1, [r4, #0x38]
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #2
	adds r1, r1, r0
	strh r1, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080142A8: .4byte gVideoRegBuffer+12
_080142AC: .4byte 0xFFFFFB50
_080142B0: .4byte gVideoRegBuffer+0xE
