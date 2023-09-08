	push {r4, r5, lr}
	adds r5, r0, #0
	bl RestoreBackground
	movs r1, #0xf7
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r4, _080EE49C @ =gBlendRegBuffer
	adds r1, r4, #0
	movs r2, #0
	bl CpuFastSet
	movs r1, #0xf7
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r2, _080EE4A0 @ =0x04000002
	adds r1, r4, #0
	bl CpuSet
	ldr r1, _080EE4A4 @ =0x00001EE8
	adds r0, r5, r1
	ldr r4, _080EE4A8 @ =gWindowRegBuffer
	adds r1, r4, #0
	movs r2, #0
	bl CpuFastSet
	ldr r1, _080EE4A4 @ =0x00001EE8
	adds r0, r5, r1
	ldr r2, _080EE4AC @ =0x04000004
	adds r1, r4, #0
	bl CpuSet
	ldr r1, _080EE4B0 @ =0x00002058
	adds r0, r5, r1
	ldr r1, _080EE4B4 @ =0x06014000
	movs r2, #0x80
	lsls r2, r2, #5
	bl CpuFastSet
	ldr r1, _080EE4B8 @ =0x00006058
	adds r0, r5, r1
	ldr r4, _080EE4BC @ =0x03002CC0
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _080EE4C0 @ =0xFFFFFE00
	adds r4, r4, r0
	ldr r1, _080EE4C4 @ =0x00006258
	adds r5, r5, r1
	ldr r0, [r5]
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080EE49C: .4byte gBlendRegBuffer
_080EE4A0: .4byte 0x04000002
_080EE4A4: .4byte 0x00001EE8
_080EE4A8: .4byte gWindowRegBuffer
_080EE4AC: .4byte 0x04000004
_080EE4B0: .4byte 0x00002058
_080EE4B4: .4byte 0x06014000
_080EE4B8: .4byte 0x00006058
_080EE4BC: .4byte 0x03002CC0
_080EE4C0: .4byte 0xFFFFFE00
_080EE4C4: .4byte 0x00006258
