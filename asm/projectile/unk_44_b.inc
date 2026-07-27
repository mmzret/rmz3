	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b1798
FUN_080b1798: @ 0x080B1798
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080B17D4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17D4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b17d8
FUN_080b17d8:
  bx lr
	.align 2, 0

	thumb_func_start FUN_080b17dc
FUN_080b17dc: @ 0x080B17DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B17EC
	cmp r0, #1
	beq _080B1834
	b _080B18C2
_080B17EC:
	movs r0, #0x40
	str r0, [r4, #0x64]
	movs r0, #0xa0
	lsls r0, r0, #3
	bl Sqrt
	ldr r1, [r4, #0x64]
	rsbs r1, r1, #0
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	adds r2, r1, #0
	muls r2, r3, r2
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080B1812
	str r1, [r4, #0x64]
	rsbs r0, r2, #0
	str r0, [r4, #0x5c]
_080B1812:
	lsls r0, r3, #1
	str r0, [r4, #0x68]
	movs r2, #0xa0
	ldrb r1, [r4, #0x13]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x60]
	movs r1, #0xd7
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B1834:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _080B184C
	subs r0, #1
	str r0, [r4, #0x68]
	ldr r0, [r4, #0x64]
	adds r0, r1, r0
	str r0, [r4, #0x5c]
_080B184C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080B1880
	ldr r0, _080B1878 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080B187C @ =0xFFFF2800
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bge _080B18C2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _080B1894
	.align 2, 0
_080B1878: .4byte gStageRun+232
_080B187C: .4byte 0xFFFF2800
_080B1880:
	ldr r0, _080B18C8 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080B18CC @ =0x0000D7FF
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	ble _080B18C2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B1894:
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
	ldr r1, _080B18D0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080B18C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B18C8: .4byte gStageRun+232
_080B18CC: .4byte 0x0000D7FF
_080B18D0: .4byte gProjectileFnTable
