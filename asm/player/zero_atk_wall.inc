	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08030ab8
FUN_08030ab8: @ 0x08030AB8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldrb r0, [r5, #0xc]
	cmp r0, #3
	bne _08030AEA
	adds r0, r4, #0
	movs r1, #0
	bl GetWeaponCharge
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r0, #0x86
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #6
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _08030B0A
	b _08030B0E
_08030AEA:
	adds r0, r4, #0
	movs r1, #1
	bl GetWeaponCharge
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r0, #0x86
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _08030B0E
_08030B0A:
	movs r3, #0
	b _08030B34
_08030B0E:
	ldr r1, _08030B70 @ =0x00000225
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _08030B1A
	movs r3, #2
_08030B1A:
	ldrh r1, [r5, #0x12]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08030B34
	ldr r1, _08030B74 @ =0x0000022D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _08030B34
	movs r3, #2
	movs r7, #1
_08030B34:
	cmp r3, #2
	bne _08030BB6
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r1, [r2, #0x12]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08030B78
	ldr r0, [r6]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08030B56
	cmp r7, #0
	beq _08030B78
_08030B56:
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #5
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08030e20
	b _08030BF4
	.align 2, 0
_08030B70: .4byte 0x00000225
_08030B74: .4byte 0x0000022D
_08030B78:
	ldrh r1, [r2, #0x12]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x1a
	cmp r2, #0
	beq _08030BA0
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #4
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08030d90
	b _08030BF4
_08030BA0:
	adds r1, r4, #0
	adds r1, #0xed
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xee
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08030d00
	b _08030BF4
_08030BB6:
	adds r0, r4, #0
	movs r1, #0
	bl IsAttackOK
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08030BDE
	adds r2, r4, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xee
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08030bfc
	b _08030BF4
_08030BDE:
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
_08030BF4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08030bfc
FUN_08030bfc: @ 0x08030BFC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r7, #0
	movs r6, #3
	strb r6, [r0]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	movs r2, #0xb4
	lsls r2, r2, #6
	cmp r1, r2
	beq _08030C28
	adds r0, r4, #0
	adds r1, r2, #0
	bl SetMotion
_08030C28:
	adds r5, r4, #0
	adds r5, #0xee
	ldrb r0, [r5]
	cmp r0, #0
	bne _08030C42
	adds r0, r4, #0
	movs r1, #3
	bl CreateWeaponShieldGuard
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08030C7C
_08030C42:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r4, r0
	adds r0, r4, #0
	bl IsAttackOK
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08030C68
	adds r0, r4, #0
	adds r0, #0xec
	strb r6, [r0]
	adds r0, #1
	strb r7, [r0]
	adds r0, r4, #0
	bl zeroWallAtk
	b _08030C7C
_08030C68:
	cmp r0, #2
	beq _08030C7C
	adds r1, r4, #0
	adds r1, #0xed
	movs r0, #2
	strb r0, [r1]
	strb r7, [r5]
	adds r0, r4, #0
	bl FUN_08030c84
_08030C7C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08030c84
FUN_08030c84: @ 0x08030C84
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrb r0, [r5]
	cmp r0, #0
	bne _08030CA0
	ldr r1, _08030CD8 @ =0x00002D02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_08030CA0:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r4, r0
	adds r0, r4, #0
	bl IsAttackOK
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08030CDC
	adds r0, r4, #0
	adds r0, #0xec
	movs r2, #0
	movs r1, #3
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, r4, #0
	bl zeroWallAtk
	b _08030CFA
	.align 2, 0
_08030CD8: .4byte 0x00002D02
_08030CDC:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08030CFA
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
	adds r0, r4, #0
	adds r0, #0xec
	strb r5, [r0]
_08030CFA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08030d00
FUN_08030d00: @ 0x08030D00
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08030D8C @ =0x00000127
	adds r6, r4, r0
	movs r0, #2
	strb r0, [r6]
	adds r5, r4, #0
	adds r5, #0xee
	ldrb r0, [r5]
	cmp r0, #0
	bne _08030D2E
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	movs r1, #0
	bl CreateWeaponShieldFly
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_08030D2E:
	movs r5, #0xb8
	lsls r5, r5, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl KeepMotion
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	cmp r1, r5
	beq _08030D60
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl GotoMotion
_08030D60:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08030D84
	movs r0, #0xff
	strb r0, [r6]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
_08030D84:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030D8C: .4byte 0x00000127

	thumb_func_start FUN_08030d90
FUN_08030d90: @ 0x08030D90
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08030E1C @ =0x00000127
	adds r6, r4, r0
	movs r0, #2
	strb r0, [r6]
	adds r5, r4, #0
	adds r5, #0xee
	ldrb r0, [r5]
	cmp r0, #0
	bne _08030DBE
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	movs r1, #1
	bl CreateWeaponShieldFly
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_08030DBE:
	movs r5, #0xb8
	lsls r5, r5, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl KeepMotion
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	cmp r1, r5
	beq _08030DF0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl GotoMotion
_08030DF0:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08030E14
	movs r0, #0xff
	strb r0, [r6]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
_08030E14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030E1C: .4byte 0x00000127

	thumb_func_start FUN_08030e20
FUN_08030e20: @ 0x08030E20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08030EAC @ =0x00000127
	adds r6, r4, r0
	movs r0, #2
	strb r0, [r6]
	adds r5, r4, #0
	adds r5, #0xee
	ldrb r0, [r5]
	cmp r0, #0
	bne _08030E4E
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	movs r1, #2
	bl CreateWeaponShieldFly
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_08030E4E:
	movs r5, #0xb8
	lsls r5, r5, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl KeepMotion
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	cmp r1, r5
	beq _08030E80
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl GotoMotion
_08030E80:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08030EA4
	movs r0, #0xff
	strb r0, [r6]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
_08030EA4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030EAC: .4byte 0x00000127
