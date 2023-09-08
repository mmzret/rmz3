	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _0800B9CC @ =gOverworld
	ldr r1, _0800B9D0 @ =0x0002D025
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800B9D8
	ldr r0, _0800B9D4 @ =gVideoRegBuffer
	lsls r1, r3, #8
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _0800B9E2
	.align 2, 0
_0800B9CC: .4byte gOverworld
_0800B9D0: .4byte 0x0002D025
_0800B9D4: .4byte gVideoRegBuffer
_0800B9D8:
	ldr r2, _0800BACC @ =gVideoRegBuffer
	lsls r1, r3, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_0800B9E2:
	ldr r2, _0800BAD0 @ =gOverworld
	mov r8, r2
	ldr r0, _0800BAD4 @ =0x0002C002
	add r0, r8
	ldrh r0, [r0]
	lsrs r3, r3, #4
	mov sb, r3
	cmp r0, #0
	beq _0800BA3A
	ldr r0, _0800BAD8 @ =0x08522348
	ldr r0, [r0]
	ldr r6, _0800BADC @ =0x08522350
	adds r0, r0, r6
	lsls r5, r3, #1
	ldr r1, _0800BAE0 @ =gVideoRegBuffer+4
	adds r5, r5, r1
	ldrh r2, [r5]
	movs r4, #0xf8
	lsls r4, r4, #5
	adds r1, r4, #0
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	movs r1, #0
	ldrh r0, [r5]
	ands r4, r0
	lsls r4, r4, #3
	ldr r0, _0800BAE4 @ =0x06000800
	adds r4, r4, r0
	str r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r2, r6
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
_0800BA3A:
	ldr r0, _0800BAE8 @ =0x0002D028
	add r0, r8
	ldr r2, [r0]
	mov r5, r8
	cmp r2, #0
	beq _0800BA84
	ldr r6, _0800BAEC @ =0x0002D02C
	adds r1, r5, r6
	ldr r0, [r2, #0x54]
	str r0, [r1]
	ldr r0, _0800BAF0 @ =0x0002D030
	adds r1, r5, r0
	ldr r0, [r2, #0x58]
	str r0, [r1]
	ldr r0, _0800BAF4 @ =0x0202F360
	ldrb r1, [r2, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0800BA84
	ldr r1, _0800BAF8 @ =gPaletteManager
	ldr r6, _0800BAFC @ =0x00000404
	adds r2, r1, r6
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r0, _0800BB00 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0x20
	strh r0, [r1]
_0800BA84:
	mov r1, sb
	lsls r3, r1, #2
	ldr r2, _0800BB04 @ =gVideoRegBuffer+12
	adds r4, r3, r2
	ldr r1, [r7, #0x34]
	ldr r6, _0800BAEC @ =0x0002D02C
	adds r0, r5, r6
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x30
	ldr r0, [r7, #0x2c]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r4]
	adds r2, #2
	adds r3, r3, r2
	ldr r1, [r7, #0x38]
	ldr r2, _0800BAF0 @ =0x0002D030
	adds r0, r5, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x90
	ldr r0, [r7, #0x30]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r3]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BACC: .4byte gVideoRegBuffer
_0800BAD0: .4byte gOverworld
_0800BAD4: .4byte 0x0002C002
_0800BAD8: .4byte 0x08522348
_0800BADC: .4byte 0x08522350
_0800BAE0: .4byte gVideoRegBuffer+4
_0800BAE4: .4byte 0x06000800
_0800BAE8: .4byte 0x0002D028
_0800BAEC: .4byte 0x0002D02C
_0800BAF0: .4byte 0x0002D030
_0800BAF4: .4byte 0x0202F360
_0800BAF8: .4byte gPaletteManager
_0800BAFC: .4byte 0x00000404
_0800BB00: .4byte 0x00000406
_0800BB04: .4byte gVideoRegBuffer+12
