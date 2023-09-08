	push {r4, r5, r6, lr}
	mov ip, r0
	movs r2, #0
	strb r1, [r0]
	strb r2, [r0, #1]
	movs r0, #0
	mov r1, ip
	strh r2, [r1, #4]
	strb r0, [r1, #3]
	ldr r6, _08021B78 @ =gStageRun
	ldr r5, _08021B7C @ =gPaletteManager
	movs r1, #0xb
	mov r0, ip
	adds r0, #0xc0
_08021AD8:
	str r2, [r0]
	subs r0, #0x10
	subs r1, #1
	cmp r1, #0
	bge _08021AD8
	movs r2, #0
	mov r0, ip
	adds r0, #0xd0
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	movs r0, #0xa4
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	strh r2, [r0]
	movs r0, #0xa2
	lsls r0, r0, #1
	add r0, ip
	str r2, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xa6
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xa7
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xa8
	lsls r0, r0, #1
	add r0, ip
	str r2, [r0]
	movs r0, #0xaa
	lsls r0, r0, #1
	add r0, ip
	str r2, [r0]
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, ip
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _08021B80 @ =0x0000FFFF
	strh r0, [r1]
	movs r1, #0xae
	lsls r1, r1, #1
	add r1, ip
	adds r0, r3, #0
	strh r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0xb2
	lsls r0, r0, #1
	add r0, ip
	str r3, [r0]
	str r3, [r1]
	strb r4, [r6, #0x12]
	strh r2, [r5]
	ldr r1, _08021B84 @ =0x00000402
	adds r0, r5, r1
	strb r4, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	bl stopAllMusics
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08021B78: .4byte gStageRun
_08021B7C: .4byte gPaletteManager
_08021B80: .4byte 0x0000FFFF
_08021B84: .4byte 0x00000402
