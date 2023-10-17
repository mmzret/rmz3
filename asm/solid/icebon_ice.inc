	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ca700
FUN_080ca700: @ 0x080CA700
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #2
	bls _080CA748
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080CA744 @ =gSolidFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080CA762
	.align 2, 0
_080CA744: .4byte gSolidFnTable
_080CA748:
	cmp r0, #1
	bls _080CA762
	ldr r1, _080CA768 @ =gSolidFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	movs r0, #0
	strb r0, [r3, #0xd]
_080CA762:
	pop {r0}
	bx r0
	.align 2, 0
_080CA768: .4byte gSolidFnTable

	thumb_func_start FUN_080ca76c
FUN_080ca76c: @ 0x080CA76C
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #2
	bls _080CA7B4
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080CA7B0 @ =gSolidFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080CA7CE
	.align 2, 0
_080CA7B0: .4byte gSolidFnTable
_080CA7B4:
	cmp r0, #1
	bls _080CA7CE
	ldr r1, _080CA7D4 @ =gSolidFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	movs r0, #0
	strb r0, [r3, #0xd]
_080CA7CE:
	pop {r0}
	bx r0
	.align 2, 0
_080CA7D4: .4byte gSolidFnTable

	thumb_func_start FUN_080ca7d8
FUN_080ca7d8: @ 0x080CA7D8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	ble _080CA7F2
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	b _080CA7FA
_080CA7F2:
	ldr r1, _080CA80C @ =0x00001102
	adds r0, r4, #0
	bl SetMotion
_080CA7FA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CA810
	cmp r0, #1
	beq _080CA83C
	b _080CA868
	.align 2, 0
_080CA80C: .4byte 0x00001102
_080CA810:
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x58]
	str r0, [r1]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CA870 @ =0x0836FD58
	str r0, [r4, #0x30]
	ldr r0, _080CA874 @ =0x00000801
	strh r0, [r4, #0x26]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CA878 @ =0x0836FCF8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CA83C:
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	subs r0, #0x80
	str r0, [r1]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	cmp r0, #0
	bge _080CA850
	adds r0, #7
_080CA850:
	asrs r0, r0, #3
	adds r0, r1, r0
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	ldr r1, _080CA87C @ =0xFFFFF100
	cmp r0, r1
	bgt _080CA868
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CA868:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CA870: .4byte 0x0836FD58
_080CA874: .4byte 0x00000801
_080CA878: .4byte 0x0836FCF8
_080CA87C: .4byte 0xFFFFF100

	thumb_func_start FUN_080ca880
FUN_080ca880: @ 0x080CA880
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	ble _080CA89C
	ldr r1, _080CA898 @ =0x00001101
	adds r0, r4, #0
	bl SetMotion
	b _080CA8A4
	.align 2, 0
_080CA898: .4byte 0x00001101
_080CA89C:
	ldr r1, _080CA8B8 @ =0x00001103
	adds r0, r4, #0
	bl SetMotion
_080CA8A4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CA8BC
	cmp r5, #1
	beq _080CA8E2
	b _080CA980
	.align 2, 0
_080CA8B8: .4byte 0x00001103
_080CA8BC:
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CA938 @ =0x0836FD58
	str r0, [r4, #0x30]
	ldr r0, _080CA93C @ =0x00000801
	strh r0, [r4, #0x26]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CA940 @ =0x0836FCF8
	bl SetDDP
	movs r0, #0x30
	strb r0, [r4, #0x12]
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CA8E2:
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, [r2]
	subs r1, #0x80
	str r1, [r2]
	movs r6, #0
	ldr r0, _080CA944 @ =gOverworld
	ldr r3, _080CA948 @ =0x0002C00C
	adds r0, r0, r3
	ldr r0, [r0]
	adds r5, r2, #0
	cmp r1, r0
	bge _080CA900
	str r0, [r5]
	movs r6, #1
_080CA900:
	ldr r0, [r4, #0x54]
	ldr r1, [r5]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	ble _080CA916
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r5]
	movs r6, #1
_080CA916:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	ldr r2, [r4, #0x58]
	cmp r0, #0
	beq _080CA950
	ldr r0, _080CA94C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	cmp r2, r0
	ble _080CA950
	movs r0, #0x80
	lsls r0, r0, #4
	b _080CA952
	.align 2, 0
_080CA938: .4byte 0x0836FD58
_080CA93C: .4byte 0x00000801
_080CA940: .4byte 0x0836FCF8
_080CA944: .4byte gOverworld
_080CA948: .4byte 0x0002C00C
_080CA94C: .4byte pZero2
_080CA950:
	movs r0, #0
_080CA952:
	str r0, [r4, #0x68]
	cmp r6, #0
	beq _080CA96C
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CA96C
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CA96C:
	ldr r0, [r5]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	subs r0, r0, r2
	cmp r0, #0
	bge _080CA97A
	adds r0, #7
_080CA97A:
	asrs r0, r0, #3
	adds r0, r2, r0
	str r0, [r4, #0x58]
_080CA980:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ca988
FUN_080ca988: @ 0x080CA988
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080CA99C
	cmp r0, #1
	beq _080CA9D2
	b _080CAAEE
_080CA99C:
	adds r0, r7, #0
	bl InitScalerotMotion1
	adds r0, r7, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	ble _080CA9BC
	ldr r1, _080CA9B8 @ =0x00001101
	adds r0, r7, #0
	bl SetMotion
	b _080CA9C4
	.align 2, 0
_080CA9B8: .4byte 0x00001101
_080CA9BC:
	ldr r1, _080CAA70 @ =0x00001103
	adds r0, r7, #0
	bl SetMotion
_080CA9C4:
	movs r0, #0xff
	strb r0, [r7, #0x12]
	movs r0, #0
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080CA9D2:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080CAA24
	ldr r4, _080CAA74 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080CAA78 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080CAA7C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CAA80 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r2, [r7, #0x54]
	adds r2, r2, r0
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	adds r0, r2, #0
	bl FUN_080b98ac
_080CAA24:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	adds r1, r7, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r7, #0x12]
	subs r0, #8
	strb r0, [r7, #0x12]
	adds r2, r7, #0
	adds r2, #0xb4
	ldr r0, _080CAA84 @ =gOverworld
	ldr r1, _080CAA88 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	adds r4, r2, #0
	cmp r1, r0
	bge _080CAA4E
	str r0, [r4]
_080CAA4E:
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r0, #4
	ands r1, r0
	ldr r3, [r7, #0x58]
	adds r5, r2, #0
	cmp r1, #0
	beq _080CAA90
	ldr r0, _080CAA8C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	cmp r3, r0
	ble _080CAA90
	movs r0, #0x80
	lsls r0, r0, #4
	b _080CAA92
	.align 2, 0
_080CAA70: .4byte 0x00001103
_080CAA74: .4byte RNG_0202f388
_080CAA78: .4byte 0x000343FD
_080CAA7C: .4byte 0x00269EC3
_080CAA80: .4byte 0xFFFFF200
_080CAA84: .4byte gOverworld
_080CAA88: .4byte 0x0002C00C
_080CAA8C: .4byte pZero2
_080CAA90:
	movs r0, #0
_080CAA92:
	str r0, [r7, #0x68]
	ldr r0, [r4]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	subs r0, r0, r3
	cmp r0, #0
	bge _080CAAA2
	adds r0, #7
_080CAAA2:
	asrs r0, r0, #3
	adds r0, r3, r0
	str r0, [r7, #0x58]
	ldrb r2, [r7, #0x12]
	cmp r2, #0x9f
	bhi _080CAAB6
	ldrb r1, [r7, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7, #0xb]
_080CAAB6:
	cmp r2, #8
	bhi _080CAAEE
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	str r2, [r5]
	adds r0, r7, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080CAAF8 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080CAAEE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CAAF8: .4byte gSolidFnTable

	thumb_func_start FUN_080caafc
FUN_080caafc: @ 0x080CAAFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CAB0C
	cmp r0, #1
	beq _080CAB28
	b _080CAB48
_080CAB0C:
	ldr r1, _080CAB50 @ =0x00001104
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CAB54 @ =0x0836FD28
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CAB28:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CAB3C
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CAB3C:
	ldr r0, [r4, #0x58]
	subs r0, #0x80
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CAB48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CAB50: .4byte 0x00001104
_080CAB54: .4byte 0x0836FD28

	thumb_func_start FUN_080cab58
FUN_080cab58: @ 0x080CAB58
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CAB68
	cmp r0, #1
	beq _080CAB84
	b _080CABD0
_080CAB68:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CABD8 @ =0x0836FD28
	bl SetDDP
	ldr r1, _080CABDC @ =0x00001105
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CAB84:
	ldr r1, [r4, #0x58]
	subs r1, #0x80
	str r1, [r4, #0x58]
	movs r5, #0
	ldr r0, _080CABE0 @ =gOverworld
	ldr r2, _080CABE4 @ =0x0002C00C
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bge _080CAB9C
	str r0, [r4, #0x58]
	movs r5, #1
_080CAB9C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	ble _080CABB2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r5, #1
_080CABB2:
	cmp r5, #0
	beq _080CABCA
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CABCA
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CABCA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CABD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CABD8: .4byte 0x0836FD28
_080CABDC: .4byte 0x00001105
_080CABE0: .4byte gOverworld
_080CABE4: .4byte 0x0002C00C

	thumb_func_start FUN_080cabe8
FUN_080cabe8: @ 0x080CABE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	beq _080CAC00
	cmp r4, #1
	beq _080CAC1A
	b _080CACD0
_080CAC00:
	adds r0, r7, #0
	bl InitScalerotMotion1
	ldr r1, _080CACE0 @ =0x00001105
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xff
	strb r0, [r7, #0x12]
	strb r4, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080CAC1A:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	movs r1, #0
	mov sb, r1
	strb r0, [r7, #0x13]
	movs r1, #3
	mov sl, r1
	ands r0, r1
	cmp r0, #0
	bne _080CAC72
	ldr r4, _080CACE4 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080CACE8 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080CACEC @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CACF0 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r2, [r7, #0x54]
	adds r2, r2, r0
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	adds r0, r2, #0
	bl FUN_080b98ac
_080CAC72:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r1, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r7, #0x12]
	adds r1, r7, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r7, #0x12]
	subs r0, #8
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _080CACD0
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	mov r1, sb
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0x94
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080CACF4 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, sl
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080CACD0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CACE0: .4byte 0x00001105
_080CACE4: .4byte RNG_0202f388
_080CACE8: .4byte 0x000343FD
_080CACEC: .4byte 0x00269EC3
_080CACF0: .4byte 0xFFFFF200
_080CACF4: .4byte gSolidFnTable
