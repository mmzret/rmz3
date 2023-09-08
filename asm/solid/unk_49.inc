	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid49_Init
Solid49_Init: @ 0x080DF420
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, _080DF47C @ =gSystemSavedataManager
	ldr r1, _080DF480 @ =0x08371892
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsrs r0, r1, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #7
	ands r0, r1
	asrs r2, r0
	movs r5, #1
	ands r2, r5
	cmp r2, #0
	bne _080DF488
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080DF484 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080DF4FA
	.align 2, 0
_080DF47C: .4byte gSystemSavedataManager
_080DF480: .4byte 0x08371892
_080DF484: .4byte gSolidFnTable
_080DF488:
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080DF500 @ =0x08371888
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _080DF4E4
	ldr r0, [r4, #0x54]
	ldr r1, _080DF504 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080DF4E4:
	ldr r1, _080DF508 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Solid49_Update
_080DF4FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DF500: .4byte 0x08371888
_080DF504: .4byte 0xFFFFFC00
_080DF508: .4byte gSolidFnTable

	thumb_func_start Solid49_Update
Solid49_Update: @ 0x080DF50C
	push {lr}
	bl UpdateMotionGraphic
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Solid49_Die
Solid49_Die: @ 0x080DF518
	ldr r2, _080DF52C @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080DF52C: .4byte gSolidFnTable
