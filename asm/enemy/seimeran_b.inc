	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808f728
FUN_0808f728: @ 0x0808F728
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808f72c
FUN_0808f72c: @ 0x0808F72C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808F742
	bl isKilled
	cmp r0, #0
	beq _0808F7A4
_0808F742:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0xc
	bne _0808F760
	subs r0, #0x4c
	ldr r1, _0808F75C @ =0x08369524
	bl SetDDP
	b _0808F77A
	.align 2, 0
_0808F75C: .4byte sCollisions+(11*24)
_0808F760:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808F794 @ =0x08369584
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808F798 @ =0x0836941C
	adds r1, r1, r2
	bl SetDDP
_0808F77A:
	adds r0, r4, #0
	bl IsFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808F7A4
	ldrb r0, [r5]
	cmp r0, #0xc
	bne _0808F79C
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0808F7A4
	.align 2, 0
_0808F794: .4byte sCollisionIdxs
_0808F798: .4byte sCollisions
_0808F79C:
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #3
	strb r0, [r4, #0xe]
_0808F7A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808f7ac
FUN_0808f7ac: @ 0x0808F7AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0808F812
	adds r5, r4, #0
	adds r5, #0xc0
	ldrb r0, [r5]
	cmp r0, #0xc
	bne _0808F7E0
	movs r1, #0xee
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F7DC @ =0x0836953C
	bl SetDDP
	b _0808F80C
	.align 2, 0
_0808F7DC: .4byte sCollisions+(12*24)
_0808F7E0:
	ldr r1, _0808F818 @ =0x00007701
	ldrb r2, [r5]
	adds r0, r4, #0
	movs r3, #3
	bl GotoMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808F81C @ =0x08369584
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808F820 @ =0x08369434
	adds r1, r1, r2
	bl SetDDP
_0808F80C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F812:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F818: .4byte 0x00007701
_0808F81C: .4byte sCollisionIdxs
_0808F820: .4byte sCollisions+(1*24)

	thumb_func_start FUN_0808f824
FUN_0808f824: @ 0x0808F824
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808F85E
	cmp r0, #1
	bgt _0808F838
	cmp r0, #0
	beq _0808F842
	b _0808F8CC
_0808F838:
	cmp r0, #2
	beq _0808F880
	cmp r0, #3
	beq _0808F88E
	b _0808F8CC
_0808F842:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F878 @ =0x08369434
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r1, _0808F87C @ =0x00007707
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F85E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F870
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F870:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0808F8CC
	.align 2, 0
_0808F878: .4byte sCollisions+(1*24)
_0808F87C: .4byte 0x00007707
_0808F880:
	ldr r1, _0808F8D4 @ =0x00007701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F88E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0808F8A4
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808F8A4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808F8D8 @ =0x08369584
	adds r5, r4, #0
	adds r5, #0x71
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808F8DC @ =0x0836941C
	adds r1, r1, r2
	bl SetDDP
	ldrb r1, [r5]
	adds r0, r4, #0
	adds r0, #0xc0
	strb r1, [r0]
_0808F8CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F8D4: .4byte 0x00007701
_0808F8D8: .4byte sCollisionIdxs
_0808F8DC: .4byte sCollisions

	thumb_func_start FUN_0808f8e0
FUN_0808f8e0: @ 0x0808F8E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808F8F0
	cmp r0, #1
	beq _0808F90E
	b _0808F928
_0808F8F0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F930 @ =0x08369524
	bl SetDDP
	movs r0, #0xa0
	strb r0, [r4, #0x12]
	movs r1, #0xee
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F90E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808F922
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808F922:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808F928:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F930: .4byte sCollisions+(11*24)

	thumb_func_start FUN_0808f934
FUN_0808f934: @ 0x0808F934
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0808F96A
	cmp r0, #1
	bgt _0808F948
	cmp r0, #0
	beq _0808F952
	b _0808FA16
_0808F948:
	cmp r0, #2
	beq _0808F98C
	cmp r0, #3
	beq _0808F9FE
	b _0808FA16
_0808F952:
	ldr r0, _0808F984 @ =0x00000103
	bl PlaySound
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r1, _0808F988 @ =0x00007702
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808F96A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808FA16
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808FA16
	.align 2, 0
_0808F984: .4byte 0x00000103
_0808F988: .4byte 0x00007702
_0808F98C:
	adds r6, r5, #0
	adds r6, #0xb8
	ldr r0, [r6]
	cmp r0, #0
	bne _0808F9D0
	adds r7, r5, #0
	adds r7, #0xbc
	ldr r0, [r7]
	cmp r0, #0
	bne _0808F9D0
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0808F9D0
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	ldr r4, _0808F9CC @ =0xFFFFE400
	adds r2, r2, r4
	adds r0, r5, #0
	movs r3, #0
	bl CreateClone
	str r0, [r6]
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	adds r2, r2, r4
	adds r0, r5, #0
	movs r3, #1
	bl CreateClone
	str r0, [r7]
	b _0808F9F0
	.align 2, 0
_0808F9CC: .4byte 0xFFFFE400
_0808F9D0:
	movs r0, #0x2d
	bl PlaySound
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r4, _0808FA1C @ =0xFFFFE400
	adds r1, r1, r4
	movs r2, #0
	bl FUN_0808f2e4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	movs r2, #1
	bl FUN_0808f2e4
_0808F9F0:
	ldr r1, _0808FA20 @ =0x00007703
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808F9FE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808FA16
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808FA16:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FA1C: .4byte 0xFFFFE400
_0808FA20: .4byte 0x00007703

	thumb_func_start FUN_0808fa24
FUN_0808fa24: @ 0x0808FA24
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808FA34
	cmp r0, #1
	beq _0808FA48
	b _0808FA60
_0808FA34:
	ldr r0, _0808FA68 @ =0x00000103
	bl PlaySound
	ldr r1, _0808FA6C @ =0x00007704
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FA48:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808FA60
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808FA60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FA68: .4byte 0x00000103
_0808FA6C: .4byte 0x00007704

	thumb_func_start FUN_0808fa70
FUN_0808fa70: @ 0x0808FA70
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808FA80
	cmp r0, #1
	beq _0808FAE0
	b _0808FB06
_0808FA80:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808FA98 @ =0x08369434
	bl SetDDP
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0808FA9C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808FAA2
	.align 2, 0
_0808FA98: .4byte sCollisions+(1*24)
_0808FA9C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808FAA2:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	movs r0, #0x80
	lsls r0, r0, #2
	bl Sqrt
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldr r1, _0808FB0C @ =0x00007707
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FAE0:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808FAF4
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808FAF4:
	ldr r1, [r4, #0x60]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808FB06:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FB0C: .4byte 0x00007707

	thumb_func_start FUN_0808fb10
FUN_0808fb10: @ 0x0808FB10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808FB46
	cmp r0, #1
	bgt _0808FB24
	cmp r0, #0
	beq _0808FB2E
	b _0808FB7C
_0808FB24:
	cmp r0, #2
	beq _0808FB68
	cmp r0, #3
	beq _0808FB76
	b _0808FB7C
_0808FB2E:
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #9
	ldr r1, _0808FB60 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, _0808FB64 @ =0x00007708
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FB46:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808FB7C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808FB7C
	.align 2, 0
_0808FB60: .4byte 0xFFFFFF00
_0808FB64: .4byte 0x00007708
_0808FB68:
	ldr r1, _0808FB9C @ =0x00007709
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FB76:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808FB7C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0808FBA0
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _0808FBB6
	b _0808FBB0
	.align 2, 0
_0808FB9C: .4byte 0x00007709
_0808FBA0:
	ldr r1, _0808FC08 @ =0xFFFFFA00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _0808FBB6
_0808FBB0:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0808FBB6:
	ldr r0, [r4, #0x60]
	adds r0, #0x15
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808FBC6
	str r1, [r4, #0x60]
_0808FBC6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0808FBE8
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808FBE8:
	ldr r2, [r4, #0x64]
	ldr r3, _0808FC0C @ =0xFFFFD400
	adds r0, r2, r3
	ldr r1, [r4, #0x54]
	cmp r1, r0
	blt _0808FBFE
	movs r3, #0xb0
	lsls r3, r3, #6
	adds r0, r2, r3
	cmp r1, r0
	ble _0808FC00
_0808FBFE:
	str r0, [r4, #0x54]
_0808FC00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FC08: .4byte 0xFFFFFA00
_0808FC0C: .4byte 0xFFFFD400

	thumb_func_start FUN_0808fc10
FUN_0808fc10: @ 0x0808FC10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808FC20
	cmp r0, #1
	beq _0808FC8E
	b _0808FCD8
_0808FC20:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808FC38 @ =0x08369554
	bl SetDDP
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0808FC3C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808FC42
	.align 2, 0
_0808FC38: .4byte sCollisions+(13*24)
_0808FC3C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808FC42:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0808FCE0 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	bl Sqrt
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldr r1, _0808FCE4 @ =0x0000770B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FC8E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r2, #0xe0
	lsls r2, r2, #3
	cmp r0, r2
	ble _0808FCAC
	str r2, [r4, #0x60]
_0808FCAC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808FCD8
	ldr r1, _0808FCE8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
_0808FCD8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FCE0: .4byte 0xFFFFFE80
_0808FCE4: .4byte 0x0000770B
_0808FCE8: .4byte gEnemyFnTable

	thumb_func_start maybeKillSeimeran
maybeKillSeimeran: @ 0x0808FCEC
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
	ldr r1, [r4, #0x58]
	str r1, [sp, #4]
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _0808FD20
	ldr r2, _0808FD58 @ =0xFFFFF000
	adds r0, r1, r2
	str r0, [sp, #4]
_0808FD20:
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _0808FD64
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0808FD5C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0808FD60 @ =0x0000270E
	cmp r1, r0
	bhi _0808FD4E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808FD4E:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	b _0808FD6A
	.align 2, 0
_0808FD58: .4byte 0xFFFFF000
_0808FD5C: .4byte gScore
_0808FD60: .4byte 0x0000270E
_0808FD64:
	movs r0, #0x35
	bl PlaySound
_0808FD6A:
	ldr r1, _0808FD84 @ =gEnemyFnTable
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
_0808FD84: .4byte gEnemyFnTable

	thumb_func_start FUN_0808fd88
FUN_0808fd88: @ 0x0808FD88
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808FD9A
	cmp r0, #1
	beq _0808FE4C
	b _0808FE64
_0808FD9A:
	movs r3, #0
	ldr r0, _0808FDBC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808FDAC
	movs r3, #1
_0808FDAC:
	adds r6, r3, #0
	adds r2, r6, #0
	cmp r6, #0
	beq _0808FDC0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808FDC6
	.align 2, 0
_0808FDBC: .4byte pZero2
_0808FDC0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808FDC6:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r1, r6, #8
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _0808FE6C @ =0x00007706
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808FE70 @ =sMotions
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808FE4C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808FE64
	adds r0, r5, #0
	bl maybeKillSeimeran
_0808FE64:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808FE6C: .4byte 0x00007706
_0808FE70: .4byte sMotions

