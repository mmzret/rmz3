	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080af760
FUN_080af760: @ 0x080AF760
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
	ldr r1, _080AF7A8 @ =0x00008605
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r4, #0x60]
	ldr r1, _080AF7AC @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r0, #0x1c
	strb r0, [r4, #0x13]
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_080af7b0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF7A8: .4byte 0x00008605
_080AF7AC: .4byte 0xFFFFFA00

	thumb_func_start FUN_080af7b0
FUN_080af7b0: @ 0x080AF7B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x19
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AF7CE
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080AF7D2
_080AF7CE:
	ldrb r0, [r5, #0xa]
	orrs r0, r1
_080AF7D2:
	strb r0, [r5, #0xa]
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	bne _080AF814
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080AF810 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080AF8A8
	.align 2, 0
_080AF810: .4byte gProjectileFnTable
_080AF814:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AF824
	str r1, [r5, #0x60]
_080AF824:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r4, _080AF898 @ =gSineTable
	ldrb r2, [r5, #0x12]
	adds r2, #0x40
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	adds r2, r2, r4
	movs r6, #0
	ldrsh r3, [r2, r6]
	lsls r3, r3, #3
	ldrb r2, [r5, #0x12]
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r4, #0
	ldrsh r2, [r2, r4]
	lsls r2, r2, #3
	adds r0, r0, r3
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bge _080AF88A
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #1
	rsbs r0, r0, #0
	cmp r0, #0
	bge _080AF886
	adds r0, #0xff
_080AF886:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
_080AF88A:
	ldrb r1, [r5, #0x12]
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080AF89C
	adds r1, #8
	b _080AF89E
	.align 2, 0
_080AF898: .4byte gSineTable
_080AF89C:
	subs r1, #8
_080AF89E:
	strb r1, [r5, #0x12]
	adds r1, #0x20
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
_080AF8A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

