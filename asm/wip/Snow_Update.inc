	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080C9308 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	ldr r1, [r4, #0x64]
	adds r1, r1, r0
	ldrb r0, [r4, #0x12]
	adds r0, #3
	strb r0, [r4, #0x12]
	ldr r2, [r4, #0x5c]
	adds r1, r1, r2
	str r1, [r4, #0x54]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r3, _080C930C @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080C9310 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C9314 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x74]
	adds r1, r0, #0
	subs r0, #1
	str r0, [r4, #0x74]
	cmp r1, #0
	bne _080C9302
	ldr r1, _080C9318 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Snow_Die
_080C9302:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C9308: .4byte gSineTable
_080C930C: .4byte RNG_0202f388
_080C9310: .4byte 0x000343FD
_080C9314: .4byte 0x00269EC3
_080C9318: .4byte gVFXFnTable
