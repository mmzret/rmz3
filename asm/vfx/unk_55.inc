	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c123c
FUN_080c123c: @ 0x080C123C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	movs r1, #0xc2
	lsls r1, r1, #7
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080C1264
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080C126A
_080C1264:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C126A:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x61
	bl LoadBlink
	strb r4, [r5, #0x12]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c12b0
FUN_080c12b0: @ 0x080C12B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldr r1, _080C12D8 @ =0x00006101
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080C12DC
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080C12E2
	.align 2, 0
_080C12D8: .4byte 0x00006101
_080C12DC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C12E2:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x61
	bl LoadBlink
	strb r4, [r5, #0x12]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c1328
FUN_080c1328: @ 0x080C1328
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080C137E
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080C13BE
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x65
	bl LoadBlink
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x60
	bl LoadBlink
	movs r0, #0x65
	bl UpdateBlinkMotionState
	movs r0, #0x60
	bl UpdateBlinkMotionState
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080C13BE
_080C137E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0x65
	bl UpdateBlinkMotionState
	movs r0, #0x60
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080C13BE
	movs r0, #0x65
	bl ClearBlink
	movs r0, #0x60
	bl ClearBlink
	ldr r1, _080C13C4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl VFX55_Die
_080C13BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C13C4: .4byte gVFXFnTable

	thumb_func_start FUN_080c13c8
FUN_080c13c8: @ 0x080C13C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	movs r0, #0x61
	bl UpdateBlinkMotionState
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C13EC
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080C13F2
_080C13EC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C13F2:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080C1410
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _080C1434 @ =0x0000B31B
	cmp r0, r1
	beq _080C142E
_080C1410:
	movs r0, #0x61
	bl ClearBlink
	ldr r1, _080C1438 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl VFX55_Die
_080C142E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1434: .4byte 0x0000B31B
_080C1438: .4byte gVFXFnTable

	thumb_func_start FUN_080c143c
FUN_080c143c: @ 0x080C143C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	movs r0, #0x61
	bl UpdateBlinkMotionState
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080C1460
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080C1466
_080C1460:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C1466:
	strb r0, [r4, #0xa]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ands r0, r3
	cmp r0, #0
	beq _080C14A6
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C14AC
_080C14A6:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C14AC:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080C14CA
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _080C14F0 @ =0x0000B31C
	cmp r0, r1
	beq _080C14E8
_080C14CA:
	movs r0, #0x61
	bl ClearBlink
	ldr r1, _080C14F4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl VFX55_Die
_080C14E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C14F0: .4byte 0x0000B31C
_080C14F4: .4byte gVFXFnTable
