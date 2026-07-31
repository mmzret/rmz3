	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bba8c
FUN_080bba8c: @ 0x080BBA8C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bhi _080BBB00
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080BBAA4
	cmp r0, #1
	beq _080BBAB2
	b _080BBB1E
_080BBAA4:
	ldr r1, _080BBB24 @ =0x00002802
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080BBAB2:
	ldr r3, [r5, #0x54]
	str r3, [r6, #0x54]
	ldr r4, [r5, #0x58]
	str r4, [r6, #0x58]
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r1, [r0]
	ldr r5, _080BBB28 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xc0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r7, #0
	ldrsh r2, [r0, r7]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r3, r3, r0
	str r3, [r6, #0x54]
	adds r1, #0x80
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r5
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r4, r4, r0
	str r4, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080BBB1E
_080BBB00:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080BBB2C @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080BBB1E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BBB24: .4byte 0x00002802
_080BBB28: .4byte gSineTable
_080BBB2C: .4byte gVFXFnTable

	thumb_func_start FUN_080bbb30
FUN_080bbb30: @ 0x080BBB30
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bhi _080BBBA4
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080BBB48
	cmp r0, #1
	beq _080BBB56
	b _080BBBC2
_080BBB48:
	ldr r1, _080BBBC8 @ =0x00002804
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080BBB56:
	ldr r3, [r5, #0x54]
	str r3, [r6, #0x54]
	ldr r4, [r5, #0x58]
	str r4, [r6, #0x58]
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r1, [r0]
	ldr r5, _080BBBCC @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xc0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r7, #0
	ldrsh r2, [r0, r7]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r3, r3, r0
	str r3, [r6, #0x54]
	adds r1, #0x80
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r5
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r4, r4, r0
	str r4, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080BBBC2
_080BBBA4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080BBBD0 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080BBBC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BBBC8: .4byte 0x00002804
_080BBBCC: .4byte gSineTable
_080BBBD0: .4byte gVFXFnTable

	thumb_func_start FUN_080bbbd4
FUN_080bbbd4: @ 0x080BBBD4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	beq _080BBBEA
	cmp r6, #1
	beq _080BBC60
	b _080BBCE2
_080BBBEA:
	adds r0, r7, #0
	bl InitRotatableMotion
	ldr r5, _080BBC74 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r1, _080BBC78 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _080BBC7C @ =0x00269EC3
	mov sb, r1
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r4, [r7, #0x11]
	ldr r1, _080BBC80 @ =sMotions
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	subs r4, #1
	lsls r4, r4, #8
	ldr r0, [r5]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ldr r2, _080BBC84 @ =0x000001FF
	ands r0, r2
	adds r4, r4, r0
	ldr r0, _080BBC88 @ =0xFFFFFF00
	adds r4, r4, r0
	str r4, [r7, #0x5c]
	mov r0, r8
	muls r0, r1, r0
	add r0, sb
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	ands r0, r2
	ldr r1, _080BBC8C @ =0xFFFFFE00
	subs r1, r1, r0
	str r1, [r7, #0x60]
	strb r6, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BBC60:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BBC90
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BBC96
	.align 2, 0
_080BBC74: .4byte RNG_0202f388
_080BBC78: .4byte 0x000343FD
_080BBC7C: .4byte 0x00269EC3
_080BBC80: .4byte sMotions
_080BBC84: .4byte 0x000001FF
_080BBC88: .4byte 0xFFFFFF00
_080BBC8C: .4byte 0xFFFFFE00
_080BBC90:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BBC96:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r1, #0x40
	str r1, [r7, #0x60]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080BBCE2
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080BBCE2
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080BBCF0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080BBCE2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BBCF0: .4byte gVFXFnTable
