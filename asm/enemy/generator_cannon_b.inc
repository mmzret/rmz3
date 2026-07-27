	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808c764
FUN_0808c764: @ 0x0808C764
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808C780 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808C77C
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0808C77C:
	pop {r0}
	bx r0
	.align 2, 0
_0808C780: .4byte 0x00020001

	thumb_func_start FUN_0808c784
FUN_0808c784: @ 0x0808C784
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808C79A
	bl isKilled
	cmp r0, #0
	beq _0808C7BA
_0808C79A:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808C7D8 @ =0x08368F70
	bl SetDDP
	adds r0, r4, #0
	bl IsFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808C7BA
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808C7BA:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808C7DC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808C7D0
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808C7D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C7D8: .4byte sCollisions+(1*24)
_0808C7DC: .4byte 0x00020001

	thumb_func_start generatorcannon_0808c7e0
generatorcannon_0808c7e0: @ 0x0808C7E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808C7F0
	cmp r5, #1
	beq _0808C814
	b _0808C85A
_0808C7F0:
	movs r1, #0xe4
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	str r5, [r4, #0x60]
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808C860 @ =0x08368F88
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C814:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	bne _0808C85A
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0808C83C
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808C834
	str r1, [r4, #0x60]
_0808C834:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0808C83C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0808C85A
	movs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, _0808C864 @ =0xFFFFF800
	cmp r1, r0
	ble _0808C85A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0808C85A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C860: .4byte sCollisions+(2*24)
_0808C864: .4byte 0xFFFFF800

	thumb_func_start generatorcannon_0808c868
generatorcannon_0808c868: @ 0x0808C868
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808C878
	cmp r0, #1
	beq _0808C894
	b _0808C8CE
_0808C878:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808C8B4 @ =0x08369090
	bl SetDDP
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldr r1, _0808C8B8 @ =0x00007106
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C894:
	ldrb r0, [r4, #0x12]
	adds r5, r0, #0
	cmp r5, #0
	bne _0808C8C4
	ldr r0, _0808C8BC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _0808C8C0 @ =0x00000FFF
	cmp r0, r1
	bhi _0808C8C8
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _0808C8C8
	.align 2, 0
_0808C8B4: .4byte sCollisions+(13*24)
_0808C8B8: .4byte 0x00007106
_0808C8BC: .4byte gStageRun+232
_0808C8C0: .4byte 0x00000FFF
_0808C8C4:
	subs r0, #1
	strb r0, [r4, #0x12]
_0808C8C8:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808C8CE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start generatorcannon_0808c8d4
generatorcannon_0808c8d4: @ 0x0808C8D4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0808C8E4
	cmp r1, #1
	beq _0808C8FA
	b _0808C95E
_0808C8E4:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	movs r1, #0xe2
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C8FA:
	ldrb r0, [r4, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C922
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bhi _0808C922
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0808C964 @ =0xFFFFF000
	adds r1, r1, r2
	ldrb r2, [r4, #0x13]
	bl CreateGeneratorCannon
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
_0808C922:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808C936
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808C936:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808C968 @ =0x0836911C
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808C96C @ =0x08368F58
	adds r1, r1, r2
	bl SetDDP
_0808C95E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C964: .4byte 0xFFFFF000
_0808C968: .4byte 0x0836911C
_0808C96C: .4byte sCollisions

	thumb_func_start generatorcannon_0808c970
generatorcannon_0808c970: @ 0x0808C970
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808C99C
	cmp r0, #1
	bgt _0808C984
	cmp r0, #0
	beq _0808C98E
	b _0808CA1A
_0808C984:
	cmp r0, #2
	beq _0808C9E4
	cmp r0, #3
	beq _0808CA00
	b _0808CA1A
_0808C98E:
	ldr r1, _0808C9D8 @ =0x00007101
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C99C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808C9B2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C9B2:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808C9DC @ =0x08369120
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808C9E0 @ =0x08368F58
	adds r1, r1, r2
	bl SetDDP
	b _0808CA1A
	.align 2, 0
_0808C9D8: .4byte 0x00007101
_0808C9DC: .4byte 0x08369120
_0808C9E0: .4byte sCollisions
_0808C9E4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808CA20 @ =0x08369090
	bl SetDDP
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldr r1, _0808CA24 @ =0x00007106
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808CA00:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808CA14
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808CA14:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808CA1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808CA20: .4byte sCollisions+(13*24)
_0808CA24: .4byte 0x00007106

	thumb_func_start generatorcannon_0808ca28
generatorcannon_0808ca28: @ 0x0808CA28
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0808CA4E
	cmp r0, #1
	bgt _0808CA3E
	cmp r0, #0
	beq _0808CA44
	b _0808CAD0
_0808CA3E:
	cmp r0, #2
	beq _0808CA9A
	b _0808CAD0
_0808CA44:
	movs r0, #3
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0808CA4E:
	movs r0, #0x2c
	bl PlaySound
	ldr r0, [r6, #0x54]
	ldr r1, _0808CAC0 @ =0xFFFFDB00
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r4, _0808CAC4 @ =0xFFFFF200
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r5, #0xc0
	lsls r5, r5, #2
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0
	bl CreateLemon
	ldr r0, [r6, #0x54]
	movs r1, #0x94
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0x80
	bl CreateLemon
	ldr r1, _0808CAC8 @ =0x00007102
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0808CA9A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808CAD0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808CACC
	movs r0, #1
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	b _0808CAD0
	.align 2, 0
_0808CAC0: .4byte 0xFFFFDB00
_0808CAC4: .4byte 0xFFFFF200
_0808CAC8: .4byte 0x00007102
_0808CACC:
	movs r0, #1
	strb r0, [r6, #0xe]
_0808CAD0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start generatorcannon_0808cad8
generatorcannon_0808cad8: @ 0x0808CAD8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808CB24
	cmp r0, #1
	bgt _0808CAEC
	cmp r0, #0
	beq _0808CAF6
	b _0808CC00
_0808CAEC:
	cmp r0, #2
	beq _0808CB90
	cmp r0, #3
	beq _0808CBA2
	b _0808CC00
_0808CAF6:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808CB40 @ =0x08368F70
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldrb r1, [r4, #0x12]
	movs r0, #2
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x10
	strb r0, [r4, #0x13]
	movs r1, #0xe4
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808CB24:
	movs r2, #0
	ldr r0, _0808CB44 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0808CB34
	movs r2, #1
_0808CB34:
	cmp r2, #0
	beq _0808CB48
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808CB4E
	.align 2, 0
_0808CB40: .4byte sCollisions+(1*24)
_0808CB44: .4byte pZero2
_0808CB48:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808CB4E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	ldr r1, _0808CB8C @ =0xFFFFFD00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808CC00
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808CC00
	.align 2, 0
_0808CB8C: .4byte 0xFFFFFD00
_0808CB90:
	ldrb r0, [r4, #0x12]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0x18
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808CBA2:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808CBB6
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808CBB6:
	movs r2, #0
	ldr r0, _0808CBD4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0808CBC6
	movs r2, #1
_0808CBC6:
	cmp r2, #0
	beq _0808CBD8
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0808CBDE
	.align 2, 0
_0808CBD4: .4byte pZero2
_0808CBD8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808CBDE:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808CC00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start generatorcannon_0808cc08
generatorcannon_0808cc08: @ 0x0808CC08
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0808CC18
	cmp r0, #1
	beq _0808CCF0
	b _0808CD4E
_0808CC18:
	ldr r0, _0808CCB0 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _0808CCB4 @ =0x00003FFF
	cmp r0, r1
	bhi _0808CC30
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound
_0808CC30:
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #1
	strb r0, [r1]
	subs r1, #0x93
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0808CCB8 @ =0x08368F70
	bl SetDDP
	ldr r0, _0808CCBC @ =pZero2
	ldr r1, [r0]
	ldr r5, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r5, r5, r0
	ldr r0, [r7, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r6, [r1, #0x58]
	subs r6, r6, r0
	asrs r0, r5, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r6, #8
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #8
	lsls r5, r5, #8
	adds r0, r5, #0
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r6, r6, #8
	adds r0, r6, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r5, r5, #2
	str r5, [r7, #0x5c]
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	movs r1, #0
	cmp r5, #0
	ble _0808CCA0
	movs r1, #1
_0808CCA0:
	adds r2, r1, #0
	cmp r2, #0
	beq _0808CCC0
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0808CCC6
	.align 2, 0
_0808CCB0: .4byte gStageRun+232
_0808CCB4: .4byte 0x00003FFF
_0808CCB8: .4byte sCollisions+(1*24)
_0808CCBC: .4byte pZero2
_0808CCC0:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808CCC6:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _0808CD54 @ =0x00007201
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808CCF0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, _0808CD58 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808CD4E
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808CD5C @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_0808CD4E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CD54: .4byte 0x00007201
_0808CD58: .4byte gStageRun+232
_0808CD5C: .4byte gEnemyFnTable

	thumb_func_start generatorcannon_0808cd60
generatorcannon_0808cd60: @ 0x0808CD60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808CD70
	cmp r0, #1
	beq _0808CE06
	b _0808CE46
_0808CD70:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0808CDEC @ =0x083690F0
	bl SetDDP
	movs r1, #0xe4
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _0808CDF0 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _0808CDF4 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _0808CDF8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0808CE00
	.align 2, 0
_0808CDEC: .4byte sCollisions+(17*24)
_0808CDF0: .4byte pZero2
_0808CDF4: .4byte 0xFFFFE800
_0808CDF8:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0808CE00:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808CE06:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808CE1E
	str r1, [r5, #0x60]
_0808CE1E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808CE40
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0808CE46
_0808CE40:
	adds r0, r5, #0
	bl FUN_0808cefc
_0808CE46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808ce4c
FUN_0808ce4c: @ 0x0808CE4C
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #0
	strb r0, [r5, #0xb]
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0808CEE8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r4, _0808CEEC @ =0x08369124
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0808CEF0 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0808CEF4 @ =0x0000270E
	cmp r1, r0
	bhi _0808CEC4
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808CEC4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldr r1, _0808CEF8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CEE8: .4byte 0xFFFFF000
_0808CEEC: .4byte sMotions
_0808CEF0: .4byte gScore
_0808CEF4: .4byte 0x0000270E
_0808CEF8: .4byte gEnemyFnTable

	thumb_func_start FUN_0808cefc
FUN_0808cefc: @ 0x0808CEFC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0808CF80 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808CF84 @ =0x0836912A
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #0
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0808CF88 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0808CF8C @ =0x0000270E
	cmp r1, r0
	bhi _0808CF5C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808CF5C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0808CF90 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CF80: .4byte 0xFFFFF000
_0808CF84: .4byte sMotions+(3*2)
_0808CF88: .4byte gScore
_0808CF8C: .4byte 0x0000270E
_0808CF90: .4byte gEnemyFnTable

	thumb_func_start FUN_0808cf94
FUN_0808cf94: @ 0x0808CF94
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0808CFA6
	cmp r6, #1
	beq _0808D05E
	b _0808D0A4
_0808CFA6:
	movs r7, #0
	ldr r0, _0808D020 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808CFB8
	movs r7, #1
_0808CFB8:
	lsls r4, r7, #8
	subs r0, r1, r4
	str r0, [r5, #0x54]
	ldr r1, _0808D024 @ =0x00007202
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0x10]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #0xc
	adds r3, r7, #0
	bl FUN_080b2b40
	movs r0, #0x80
	subs r0, r0, r4
	str r0, [sp, #0xc]
	movs r0, #0x60
	str r0, [sp, #0x10]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D02C
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808D028 @ =0x08369130
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #0xc
	movs r3, #0x20
	bl FUN_080b84f4
	b _0808D046
	.align 2, 0
_0808D020: .4byte pZero2
_0808D024: .4byte 0x00007202
_0808D028: .4byte sMotions+(6*2)
_0808D02C:
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808D0AC @ =0x08369130
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x19
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	movs r3, #0x20
	bl FUN_080b85fc
_0808D046:
	ldr r0, [sp, #0xc]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r5, #0x5c]
	movs r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808D05E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x15
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808D076
	str r1, [r5, #0x60]
_0808D076:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808D09E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808D0A4
_0808D09E:
	adds r0, r5, #0
	bl FUN_0808cefc
_0808D0A4:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D0AC: .4byte sMotions+(6*2)
