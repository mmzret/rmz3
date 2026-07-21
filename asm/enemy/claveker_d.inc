	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808ebb4
FUN_0808ebb4: @ 0x0808EBB4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0808EBC0
	b _0808EFEE
_0808EBC0:
	lsls r0, r0, #2
	ldr r1, _0808EBCC @ =_0808EBD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808EBCC: .4byte _0808EBD0
_0808EBD0: @ jump table
	.4byte _0808EBE8 @ case 0
	.4byte _0808EC98 @ case 1
	.4byte _0808EF6E @ case 2
	.4byte _0808EF8A @ case 3
	.4byte _0808EFA4 @ case 4
	.4byte _0808EFAA @ case 5
_0808EBE8:
	ldr r1, _0808EC1C @ =0x00007501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808EC20 @ =0x08369388
	bl SetDDP
	ldr r0, _0808EC24 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808EC40
	ldr r3, _0808EC28 @ =0xFFFFD000
	adds r0, r0, r3
	str r0, [r4, #0x64]
	ldr r0, [r2, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808EC30
	ldr r0, _0808EC2C @ =0x00002FFF
	cmp r2, r0
	bgt _0808EC38
	b _0808EC6C
	.align 2, 0
_0808EC1C: .4byte 0x00007501
_0808EC20: .4byte 0x08369388
_0808EC24: .4byte pZero2
_0808EC28: .4byte 0xFFFFD000
_0808EC2C: .4byte 0x00002FFF
_0808EC30:
	subs r1, r1, r0
	ldr r0, _0808EC3C @ =0x00002FFF
	cmp r1, r0
	ble _0808EC6C
_0808EC38:
	movs r0, #0
	b _0808EC6E
	.align 2, 0
_0808EC3C: .4byte 0x00002FFF
_0808EC40:
	movs r3, #0xc0
	lsls r3, r3, #6
	adds r0, r0, r3
	str r0, [r4, #0x64]
	ldr r0, [r2, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EC5C
	ldr r0, _0808EC58 @ =0x00002FFF
	cmp r2, r0
	bgt _0808EC64
	b _0808EC6C
	.align 2, 0
_0808EC58: .4byte 0x00002FFF
_0808EC5C:
	subs r1, r0, r1
	ldr r0, _0808EC68 @ =0x00002FFF
	cmp r1, r0
	ble _0808EC6C
_0808EC64:
	movs r0, #0
	b _0808EC6E
	.align 2, 0
_0808EC68: .4byte 0x00002FFF
_0808EC6C:
	movs r0, #1
_0808EC6E:
	strb r0, [r4, #0xf]
	ldr r2, _0808ECC8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808ECCC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808ECD0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0x3c
	movs r1, #0
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EC98:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808ECA0
	b _0808EDB8
_0808ECA0:
	ldr r5, _0808ECD4 @ =pZero2
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808ED3C
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #4
	adds r1, r1, r3
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808ECD8
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ECC8: .4byte RNG_0202f388
_0808ECCC: .4byte 0x000343FD
_0808ECD0: .4byte 0x00269EC3
_0808ECD4: .4byte pZero2
_0808ECD8:
	ldr r0, [r4, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r0, r3
	str r1, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808ED02
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
_0808ED02:
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808ED1C
	ldr r0, _0808ED18 @ =0x00002FFF
	cmp r2, r0
	ble _0808ED26
	b _0808EECC
	.align 2, 0
_0808ED18: .4byte 0x00002FFF
_0808ED1C:
	subs r1, r1, r0
	ldr r0, _0808ED30 @ =0x00002FFF
	cmp r1, r0
	ble _0808ED26
	b _0808EECC
_0808ED26:
	ldr r0, _0808ED34 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, _0808ED38 @ =0xFFFFD000
	b _0808EEC2
	.align 2, 0
_0808ED30: .4byte 0x00002FFF
_0808ED34: .4byte pZero2
_0808ED38: .4byte 0xFFFFD000
_0808ED3C:
	ldr r3, _0808ED58 @ =0xFFFFEC00
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808ED5C
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ED58: .4byte 0xFFFFEC00
_0808ED5C:
	ldr r0, [r4, #0x54]
	ldr r3, _0808ED84 @ =0xFFFFFD00
	adds r1, r0, r3
	str r1, [r4, #0x54]
	ldr r1, _0808ED88 @ =0xFFFFE900
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808ED8C
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ED84: .4byte 0xFFFFFD00
_0808ED88: .4byte 0xFFFFE900
_0808ED8C:
	ldr r0, [r5]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EDA8
	ldr r0, _0808EDA4 @ =0x00002FFF
	cmp r2, r0
	bgt _0808EDA0
	b _0808EEB8
_0808EDA0:
	b _0808EECC
	.align 2, 0
_0808EDA4: .4byte 0x00002FFF
_0808EDA8:
	subs r1, r0, r1
	ldr r0, _0808EDB4 @ =0x00002FFF
	cmp r1, r0
	ble _0808EDB2
	b _0808EECC
_0808EDB2:
	b _0808EEB8
	.align 2, 0
_0808EDB4: .4byte 0x00002FFF
_0808EDB8:
	ldr r5, _0808EDE0 @ =pZero2
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808EE50
	ldr r3, _0808EDE4 @ =0xFFFFEC00
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808EDE8
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808EDE0: .4byte pZero2
_0808EDE4: .4byte 0xFFFFEC00
_0808EDE8:
	ldr r0, [r4, #0x54]
	ldr r3, _0808EE10 @ =0xFFFFFD00
	adds r1, r0, r3
	str r1, [r4, #0x54]
	ldr r1, _0808EE14 @ =0xFFFFE900
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808EE18
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808EE10: .4byte 0xFFFFFD00
_0808EE14: .4byte 0xFFFFE900
_0808EE18:
	ldr r0, [r5]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EE30
	ldr r0, _0808EE2C @ =0x00002FFF
	cmp r2, r0
	bgt _0808EE38
	b _0808EECC
	.align 2, 0
_0808EE2C: .4byte 0x00002FFF
_0808EE30:
	subs r1, r0, r1
	ldr r0, _0808EE44 @ =0x00002FFF
	cmp r1, r0
	ble _0808EECC
_0808EE38:
	ldr r0, _0808EE48 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, _0808EE4C @ =0xFFFFD000
	b _0808EEC2
	.align 2, 0
_0808EE44: .4byte 0x00002FFF
_0808EE48: .4byte pZero2
_0808EE4C: .4byte 0xFFFFD000
_0808EE50:
	movs r3, #0xa0
	lsls r3, r3, #5
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808EE6C
	movs r0, #3
	b _0808EECA
_0808EE6C:
	ldr r0, [r4, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r0, r3
	str r1, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808EE96
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
_0808EE96:
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808EEB0
	ldr r0, _0808EEAC @ =0x00002FFF
	cmp r2, r0
	bgt _0808EEB8
	b _0808EECC
	.align 2, 0
_0808EEAC: .4byte 0x00002FFF
_0808EEB0:
	subs r1, r1, r0
	ldr r0, _0808EEE8 @ =0x00002FFF
	cmp r1, r0
	ble _0808EECC
_0808EEB8:
	ldr r0, _0808EEEC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #6
_0808EEC2:
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
_0808EECA:
	strb r0, [r4, #0xe]
_0808EECC:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r3, [r4, #0x54]
	ldr r1, [r0]
	subs r2, r3, r1
	adds r5, r0, #0
	cmp r2, #0
	ble _0808EEF0
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _0808EEFA
	b _0808EF48
	.align 2, 0
_0808EEE8: .4byte 0x00002FFF
_0808EEEC: .4byte pZero2
_0808EEF0:
	subs r1, r1, r3
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _0808EF48
_0808EEFA:
	ldr r0, [r4, #0x54]
	ldr r1, [r5]
	cmp r0, r1
	ble _0808EF0A
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r1, r3
	b _0808EF0E
_0808EF0A:
	ldr r2, _0808EF28 @ =0xFFFF6000
	adds r0, r1, r2
_0808EF0E:
	str r0, [r4, #0x54]
	ldr r0, _0808EF2C @ =pZero2
	ldr r0, [r0]
	ldr r3, [r4, #0x54]
	ldr r1, [r0, #0x54]
	subs r2, r3, r1
	cmp r2, #0
	ble _0808EF34
	ldr r0, _0808EF30 @ =0x00002FFF
	cmp r2, r0
	ble _0808EF3C
	b _0808EF44
	.align 2, 0
_0808EF28: .4byte 0xFFFF6000
_0808EF2C: .4byte pZero2
_0808EF30: .4byte 0x00002FFF
_0808EF34:
	subs r1, r1, r3
	ldr r0, _0808EF40 @ =0x00002FFF
	cmp r1, r0
	bgt _0808EF44
_0808EF3C:
	movs r0, #2
	b _0808EF46
	.align 2, 0
_0808EF40: .4byte 0x00002FFF
_0808EF44:
	movs r0, #3
_0808EF46:
	strb r0, [r4, #0xe]
_0808EF48:
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bne _0808EF66
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0808EF66
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_0808EF66:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0808EFEE
_0808EF6E:
	adds r5, r4, #0
	adds r5, #0x71
	movs r1, #0
	ldrsb r1, [r5, r1]
	cmp r1, #0
	beq _0808EFE8
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #7
	bne _0808EFEE
	b _0808EFE6
_0808EF8A:
	ldr r1, _0808EFA0 @ =0x0000750B
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808EFEE
	.align 2, 0
_0808EFA0: .4byte 0x0000750B
_0808EFA4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EFAA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r2, r3
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bne _0808EFD8
	ldr r0, _0808EFD4 @ =pZero2
	ldr r0, [r0]
	movs r3, #0xd0
	lsls r3, r3, #8
	adds r1, r2, r3
	ldr r0, [r0, #0x54]
	cmp r0, r1
	bge _0808EFEE
	b _0808EFE6
	.align 2, 0
_0808EFD4: .4byte pZero2
_0808EFD8:
	ldr r0, _0808EFF4 @ =pZero2
	ldr r0, [r0]
	ldr r2, _0808EFF8 @ =0xFFFFD000
	adds r1, r1, r2
	ldr r0, [r0, #0x54]
	cmp r0, r1
	ble _0808EFEE
_0808EFE6:
	movs r1, #0
_0808EFE8:
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808EFEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EFF4: .4byte pZero2
_0808EFF8: .4byte 0xFFFFD000

