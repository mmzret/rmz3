	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b9070
FUN_080b9070: @ 0x080B9070
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B9080
	cmp r0, #1
	beq _080B9090
	b _080B90B2
_080B9080:
	movs r1, #0xd0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B9090:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B90B2
	ldr r1, _080B90B8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B90B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B90B8: .4byte gVFXFnTable

	thumb_func_start FUN_080b90bc
FUN_080b90bc: @ 0x080B90BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B90CC
	cmp r0, #1
	beq _080B90DA
	b _080B9124
_080B90CC:
	ldr r1, _080B912C @ =0x00000D09
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B90DA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x80
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B90F8
	str r1, [r4, #0x60]
_080B90F8:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r2, r0, r1
	str r2, [r4, #0x58]
	cmp r1, #0
	ble _080B9124
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080B9124
	ldr r1, _080B9130 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B9124:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B912C: .4byte 0x00000D09
_080B9130: .4byte gVFXFnTable

	thumb_func_start FUN_080b9134
FUN_080b9134: @ 0x080B9134
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B9144
	cmp r0, #1
	beq _080B9152
	b _080B9174
_080B9144:
	ldr r1, _080B917C @ =0x00000D01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B9152:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B9174
	ldr r1, _080B9180 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B9174:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B917C: .4byte 0x00000D01
_080B9180: .4byte gVFXFnTable
