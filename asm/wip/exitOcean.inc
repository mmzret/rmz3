	push {r4, r5, lr}
	movs r0, #0xe5
	bl ClearBlink
	movs r0, #0xe6
	bl ClearBlink
	movs r0, #0xe7
	bl ClearBlink
	movs r0, #0xe8
	bl ClearBlink
	movs r0, #0xe9
	bl ClearBlink
	movs r0, #0xea
	bl ClearBlink
	movs r0, #0xeb
	bl ClearBlink
	movs r0, #0xec
	bl ClearBlink
	movs r0, #0xed
	bl ClearBlink
	movs r0, #0xee
	bl ClearBlink
	movs r0, #0xef
	bl ClearBlink
	movs r0, #0
	movs r4, #0
	ldr r5, _0800D108 @ =gSolidFnTable
_0800D0B6:
	lsls r2, r0, #0x18
	asrs r2, r2, #0x18
	lsls r0, r2, #2
	ldr r1, _0800D10C @ =0x0202F22C
	adds r0, r0, r1
	ldr r3, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldrb r1, [r3, #9]
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #3
	str r0, [r3, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r0, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #3
	ble _0800D0B6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D108: .4byte gSolidFnTable
_0800D10C: .4byte 0x0202F22C
