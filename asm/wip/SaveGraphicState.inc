	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	ldr r0, _080EE404 @ =0x00006258
	adds r1, r5, r0
	ldr r6, _080EE408 @ =gPaletteManager
	ldrh r0, [r6]
	str r0, [r1]
	bl SaveDispRegister
	ldr r4, _080EE40C @ =gBlendRegBuffer
	movs r2, #0xf7
	lsls r2, r2, #5
	adds r1, r5, r2
	movs r0, #0
	mov r8, r0
	adds r0, r4, #0
	movs r2, #0
	bl CpuFastSet
	movs r2, #0xf7
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r2, _080EE410 @ =0x04000002
	adds r0, r4, #0
	bl CpuSet
	mov r0, r8
	strh r0, [r4]
	ldr r4, _080EE414 @ =gWindowRegBuffer
	ldr r2, _080EE418 @ =0x00001EE8
	adds r1, r5, r2
	adds r0, r4, #0
	movs r2, #0
	bl CpuFastSet
	ldr r0, _080EE418 @ =0x00001EE8
	adds r1, r5, r0
	ldr r2, _080EE41C @ =0x04000004
	adds r0, r4, #0
	bl CpuSet
	mov r2, r8
	strh r2, [r4]
	movs r0, #0xff
	strb r0, [r4, #0xe]
	ldr r0, _080EE420 @ =0x06014000
	ldr r2, _080EE424 @ =0x00002058
	adds r1, r5, r2
	movs r2, #0x80
	lsls r2, r2, #5
	bl CpuFastSet
	movs r0, #0x80
	lsls r0, r0, #2
	adds r6, r6, r0
	ldr r2, _080EE428 @ =0x00006058
	adds r5, r5, r2
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x80
	bl CpuFastSet
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EE404: .4byte 0x00006258
_080EE408: .4byte gPaletteManager
_080EE40C: .4byte gBlendRegBuffer
_080EE410: .4byte 0x04000002
_080EE414: .4byte gWindowRegBuffer
_080EE418: .4byte 0x00001EE8
_080EE41C: .4byte 0x04000004
_080EE420: .4byte 0x06014000
_080EE424: .4byte 0x00002058
_080EE428: .4byte 0x00006058
