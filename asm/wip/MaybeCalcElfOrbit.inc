	push {lr}
	b _080E95E4
_080E95D0:
	adds r2, r0, #0
	cmp r0, #0
	bge _080E95D8
	adds r2, #0xf
_080E95D8:
	asrs r0, r2, #4
	adds r2, r1, #0
	cmp r1, #0
	bge _080E95E2
	adds r2, #0xf
_080E95E2:
	asrs r1, r2, #4
_080E95E4:
	adds r2, r0, #0
	cmp r0, #0
	bge _080E95EC
	rsbs r2, r0, #0
_080E95EC:
	ldr r3, _080E961C @ =0x00007FFF
	cmp r2, r3
	bgt _080E95D0
	adds r2, r1, #0
	cmp r1, #0
	bge _080E95FA
	rsbs r2, r1, #0
_080E95FA:
	cmp r2, r3
	bgt _080E95D0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x80
	asrs r0, r0, #8
	movs r1, #0xff
	ands r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_080E961C: .4byte 0x00007FFF
