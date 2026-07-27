	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08083644
FUN_08083644: @ 0x08083644
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _08083652
	b _080839F6
_08083652:
	lsls r0, r0, #2
	ldr r1, _0808365C @ =_08083660
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808365C: .4byte _08083660
_08083660: @ jump table
	.4byte _080836C4 @ case 0
	.4byte _080836D4 @ case 1
	.4byte _0808370C @ case 2
	.4byte _08083722 @ case 3
	.4byte _0808373A @ case 4
	.4byte _08083784 @ case 5
	.4byte _080837F4 @ case 6
	.4byte _0808381A @ case 7
	.4byte _080839F6 @ case 8
	.4byte _080839F6 @ case 9
	.4byte _080838A4 @ case 10
	.4byte _080838E8 @ case 11
	.4byte _08083908 @ case 12
	.4byte _080839F6 @ case 13
	.4byte _080839F6 @ case 14
	.4byte _080839F6 @ case 15
	.4byte _080839F6 @ case 16
	.4byte _080839F6 @ case 17
	.4byte _080839F6 @ case 18
	.4byte _080839F6 @ case 19
	.4byte _08083922 @ case 20
	.4byte _08083958 @ case 21
	.4byte _08083998 @ case 22
	.4byte _080839D0 @ case 23
	.4byte _080839D6 @ case 24
_080836C4:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x68]
	str r0, [r5, #0x68]
	movs r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080836D4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	ldr r1, _08083704 @ =0xFFFFFD00
	cmp r0, r1
	bge _080836E8
	str r1, [r5, #0x60]
_080836E8:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	ldr r2, _08083708 @ =0xFFFF8600
	adds r1, r1, r2
	cmp r0, r1
	blt _080836FC
	b _080839F6
_080836FC:
	str r1, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _080839C4
	.align 2, 0
_08083704: .4byte 0xFFFFFD00
_08083708: .4byte 0xFFFF8600
_0808370C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083714
	b _080839F6
_08083714:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083720
	b _080839F6
_08083720:
	b _080839C4
_08083722:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080837D8 @ =0x08368238
	bl SetDDP
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808373A:
	ldr r1, _080837DC @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _080837E0 @ =0x08368298
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _080837E4 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083784:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _080837E8 @ =0xFFFF8800
	adds r4, r0, #0
	cmp r2, r1
	bge _080837A2
	ldr r0, [r5, #0x5c]
	subs r0, #0x40
	str r0, [r5, #0x5c]
	movs r1, #0x80
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080837A2
	str r1, [r5, #0x5c]
_080837A2:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r1, _080837EC @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r4]
	ldr r0, _080837F0 @ =0xFFFF8000
	cmp r1, r0
	bge _0808388A
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083884
	movs r0, #6
	strb r0, [r5, #0xe]
	b _080839F6
	.align 2, 0
_080837D8: .4byte 0x08368238
_080837DC: .4byte 0x00000902
_080837E0: .4byte 0x08368298
_080837E4: .4byte 0xFFFFFE00
_080837E8: .4byte 0xFFFF8800
_080837EC: .4byte 0xFFFFED00
_080837F0: .4byte 0xFFFF8000
_080837F4:
	ldr r1, _08083870 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083874 @ =0x08368298
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _08083878 @ =0xFFFF8000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808381A:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0808387C @ =0xFFFFF800
	adds r4, r0, #0
	cmp r2, r1
	ble _08083836
	ldr r0, [r5, #0x5c]
	adds r0, #0x40
	str r0, [r5, #0x5c]
	cmp r0, #0x80
	ble _08083836
	movs r0, #0x80
	str r0, [r5, #0x5c]
_08083836:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r4, _08083880 @ =0xFFFFED00
	adds r0, r0, r4
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0808388A
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083884
	movs r0, #4
	strb r0, [r5, #0xe]
	b _080839F6
	.align 2, 0
_08083870: .4byte 0x00000902
_08083874: .4byte 0x08368298
_08083878: .4byte 0xFFFF8000
_0808387C: .4byte 0xFFFFF800
_08083880: .4byte 0xFFFFED00
_08083884:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _080839F6
_0808388A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083892
	b _080839F6
_08083892:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808389E
	b _080839F6
_0808389E:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _080839F6
_080838A4:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080838BC
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r0, r0, r2
	b _080838C2
_080838BC:
	ldr r0, [r5, #0x54]
	ldr r1, _08083900 @ =0xFFFFFA00
	adds r0, r0, r1
_080838C2:
	str r0, [sp]
	ldr r0, [r5, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp, #4]
	ldr r0, _08083904 @ =0x0000012D
	bl PlaySound
	movs r1, #0xfa
	lsls r1, r1, #1
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_080ac818
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080838E8:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080838F0
	b _080839F6
_080838F0:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080838FC
	b _080839F6
_080838FC:
	b _080839C4
	.align 2, 0
_08083900: .4byte 0xFFFFFA00
_08083904: .4byte 0x0000012D
_08083908:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808391C
	movs r0, #7
	strb r0, [r5, #0xe]
	b _080839F6
_0808391C:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _080839F6
_08083922:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x24
	movs r4, #0
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _08083950 @ =0x08368238
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r1, _08083954 @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	b _080839C4
	.align 2, 0
_08083950: .4byte 0x08368238
_08083954: .4byte 0xFFFFED00
_08083958:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080839F6
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080839F6
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083994 @ =0x08368220
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080839C4
	.align 2, 0
_08083994: .4byte 0x08368220
_08083998:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	adds r0, #0x80
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _080839AE
	str r1, [r5, #0x60]
_080839AE:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _080839CC @ =0xFFFFC600
	adds r0, r0, r2
	cmp r1, r0
	ble _080839F6
	str r0, [r5, #0x58]
_080839C4:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080839F6
	.align 2, 0
_080839CC: .4byte 0xFFFFC600
_080839D0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080839D6:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _08083A00 @ =0xFFFFC600
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _080839F6
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080839F6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083A00: .4byte 0xFFFFC600

	thumb_func_start FUN_08083a04
FUN_08083a04: @ 0x08083A04
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _08083A12
	b _08083E06
_08083A12:
	lsls r0, r0, #2
	ldr r1, _08083A1C @ =_08083A20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083A1C: .4byte _08083A20
_08083A20: @ jump table
	.4byte _08083A84 @ case 0
	.4byte _08083AF4 @ case 1
	.4byte _08083B48 @ case 2
	.4byte _08083B5E @ case 3
	.4byte _08083B6C @ case 4
	.4byte _08083BB2 @ case 5
	.4byte _08083C1C @ case 6
	.4byte _08083C42 @ case 7
	.4byte _08083E06 @ case 8
	.4byte _08083E06 @ case 9
	.4byte _08083CC8 @ case 10
	.4byte _08083CF2 @ case 11
	.4byte _08083D10 @ case 12
	.4byte _08083E06 @ case 13
	.4byte _08083E06 @ case 14
	.4byte _08083E06 @ case 15
	.4byte _08083E06 @ case 16
	.4byte _08083E06 @ case 17
	.4byte _08083E06 @ case 18
	.4byte _08083E06 @ case 19
	.4byte _08083D2A @ case 20
	.4byte _08083D94 @ case 21
	.4byte _08083DA6 @ case 22
	.4byte _08083DE0 @ case 23
	.4byte _08083DE6 @ case 24
_08083A84:
	ldr r1, _08083B3C @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r3, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	movs r4, #0
	strb r3, [r0]
	movs r2, #0x20
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083B40 @ =0x08368298
	bl SetDDP
	strb r4, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	str r4, [r5, #0x60]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x68]
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083AF4:
	ldrb r0, [r5, #0x13]
	cmp r0, #0x3f
	bhi _08083AFE
	adds r0, #4
	strb r0, [r5, #0x13]
_08083AFE:
	ldrb r0, [r5, #0x13]
	mvns r0, r0
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08083B1E
	str r1, [r5, #0x60]
_08083B1E:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	ldr r2, _08083B44 @ =0xFFFFFE00
	adds r1, r1, r2
	cmp r0, r1
	bgt _08083B32
	b _08083E06
_08083B32:
	str r1, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _08083DD2
	.align 2, 0
_08083B3C: .4byte 0x00000902
_08083B40: .4byte 0x08368298
_08083B44: .4byte 0xFFFFFE00
_08083B48:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083B50
	b _08083E06
_08083B50:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083B5C
	b _08083E06
_08083B5C:
	b _08083DD2
_08083B5E:
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x50
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083B6C:
	ldr r1, _08083C04 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083C08 @ =0x08368298
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _08083C0C @ =0xFFFFFF00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083BB2:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _08083C10 @ =0xFFFFD180
	adds r4, r0, #0
	cmp r2, r1
	bge _08083BD0
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0x40
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08083BD0
	str r1, [r5, #0x60]
_08083BD0:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	ldr r1, _08083C14 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r4]
	ldr r0, _08083C18 @ =0xFFFFD000
	cmp r1, r0
	bge _08083CAE
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CA8
	movs r0, #6
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083C04: .4byte 0x00000902
_08083C08: .4byte 0x08368298
_08083C0C: .4byte 0xFFFFFF00
_08083C10: .4byte 0xFFFFD180
_08083C14: .4byte 0xFFFFFE00
_08083C18: .4byte 0xFFFFD000
_08083C1C:
	ldr r1, _08083C94 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083C98 @ =0x08368298
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _08083C9C @ =0xFFFFD000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083C42:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _08083CA0 @ =0xFFFFFE80
	adds r4, r0, #0
	cmp r2, r1
	ble _08083C5E
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, #0x3f
	bgt _08083C5E
	movs r0, #0x40
	str r0, [r5, #0x60]
_08083C5E:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	ldr r4, _08083CA4 @ =0xFFFFFE00
	adds r0, r0, r4
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x68]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _08083CAE
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CA8
	movs r0, #4
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083C94: .4byte 0x00000902
_08083C98: .4byte 0x08368298
_08083C9C: .4byte 0xFFFFD000
_08083CA0: .4byte 0xFFFFFE80
_08083CA4: .4byte 0xFFFFFE00
_08083CA8:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _08083E06
_08083CAE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083CB6
	b _08083E06
_08083CB6:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CC2
	b _08083E06
_08083CC2:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _08083E06
_08083CC8:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	ldr r2, _08083D08 @ =0xFFFFEE00
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldr r0, _08083D0C @ =0x0000012D
	bl PlaySound
	movs r1, #0xc8
	lsls r1, r1, #2
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_080ac880
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083CF2:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083CFA
	b _08083E06
_08083CFA:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083D06
	b _08083E06
_08083D06:
	b _08083DD2
	.align 2, 0
_08083D08: .4byte 0xFFFFEE00
_08083D0C: .4byte 0x0000012D
_08083D10:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08083D24
	movs r0, #7
	strb r0, [r5, #0xe]
	b _08083E06
_08083D24:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _08083E06
_08083D2A:
	ldr r1, _08083D8C @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _08083D90 @ =0x08368268
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x32
	strb r0, [r5, #0x12]
	b _08083DD2
	.align 2, 0
_08083D8C: .4byte 0x00000901
_08083D90: .4byte 0x08368268
_08083D94:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08083E06
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08083E06
	b _08083DD2
_08083DA6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	subs r0, #4
	str r0, [r5, #0x60]
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08083DBC
	str r1, [r5, #0x60]
_08083DBC:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _08083DDC @ =0xFFFFC800
	adds r0, r0, r2
	cmp r1, r0
	bge _08083E06
	str r0, [r5, #0x58]
_08083DD2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083DDC: .4byte 0xFFFFC800
_08083DE0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083DE6:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _08083E10 @ =0xFFFFC800
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _08083E06
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08083E06:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083E10: .4byte 0xFFFFC800
