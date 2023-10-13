	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CarrybeeG_Init
CarrybeeG_Init: @ 0x0808A908
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r0, _0808A974 @ =nop_0808b534
	adds r4, r6, #0
	adds r4, #0x74
	str r0, [r4, #0x24]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA00
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0808a8b0
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA00
	adds r1, r6, #0
	adds r1, #0xc3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0808A978 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808A984
	ldr r0, _0808A97C @ =gCurStory
	ldrb r1, [r0, #4]
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808A984
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0808A980 @ =0x08368C6C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	b _0808A99C
	.align 2, 0
_0808A974: .4byte nop_0808b534
_0808A978: .4byte gSystemSavedataManager
_0808A97C: .4byte gCurStory
_0808A980: .4byte 0x08368C6C
_0808A984:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808A9F8 @ =0x08368C6C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x30
_0808A99C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xbc
	movs r2, #0
	str r2, [r0]
	str r2, [r6, #0x2c]
	str r2, [r6, #0x28]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldr r1, _0808A9FC @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r2, [r6, #0xd]
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x14
	strb r0, [r1]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0808AA5C
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0808AA5C
	.align 2, 0
_0808A9F8: .4byte 0x08368C6C
_0808A9FC: .4byte gEnemyFnTable
_0808AA00:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0808AA88 @ =0x08368C54
	bl SetDDP
	ldr r1, _0808AA8C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x16
	strb r0, [r1]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0808AA5C
	ldrb r0, [r6, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r1, _0808AA90 @ =0x00006E06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0808AA5C:
	movs r0, #0
	strb r0, [r6, #0x11]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA72
	ldr r1, _0808AA94 @ =gOverworld
	ldr r0, _0808AA98 @ =0x0002D02C
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0808AA72:
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	bl CarrybeeG_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AA88: .4byte 0x08368C54
_0808AA8C: .4byte gEnemyFnTable
_0808AA90: .4byte 0x00006E06
_0808AA94: .4byte gOverworld
_0808AA98: .4byte 0x0002D02C

	thumb_func_start CarrybeeG_Update
CarrybeeG_Update: @ 0x0808AA9C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808AAD4
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0808AAD4
	ldr r1, _0808AAD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl CarrybeeG_Die
	b _0808AC28
	.align 2, 0
_0808AAD0: .4byte gEnemyFnTable
_0808AAD4:
	ldr r1, _0808AB30 @ =0x08368C2C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0808AB82
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808AB82
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #2
	bls _0808AB38
	adds r0, r4, #0
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
	ldr r1, _0808AB34 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #0x11]
	b _0808AC28
	.align 2, 0
_0808AB30: .4byte 0x08368C2C
_0808AB34: .4byte gEnemyFnTable
_0808AB38:
	cmp r0, #1
	bls _0808AB82
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808AB5C
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0808AB62
_0808AB5C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808AB62:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
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
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808AB82:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _0808AC28
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _0808AC18
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	cmp r0, #0
	beq _0808ABC0
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808ABA4
	str r1, [r2]
_0808ABA4:
	adds r1, r4, #0
	adds r1, #0xc0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808ABB8
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808ABC0
_0808ABB8:
	ldr r0, [r2]
	adds r0, #0x25
	movs r1, #0x18
	strb r1, [r0]
_0808ABC0:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0808ABEC
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808ABD0
	movs r0, #0
	str r0, [r4, #0x2c]
_0808ABD0:
	adds r1, r4, #0
	adds r1, #0xc1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808ABE4
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808ABEC
_0808ABE4:
	ldr r0, [r4, #0x2c]
	adds r0, #0x25
	movs r1, #0x18
	strb r1, [r0]
_0808ABEC:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _0808AC18
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808ABFC
	movs r0, #0
	str r0, [r4, #0x28]
_0808ABFC:
	adds r1, r4, #0
	adds r1, #0xc2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808AC10
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808AC18
_0808AC10:
	ldr r0, [r4, #0x28]
	adds r0, #0x25
	movs r1, #0x18
	strb r1, [r0]
_0808AC18:
	ldr r0, _0808AC30 @ =0x08368C40
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0808AC28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808AC30: .4byte 0x08368C40

	thumb_func_start CarrybeeG_Die
CarrybeeG_Die: @ 0x0808AC34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r2, [r7, #0x10]
	cmp r2, #0
	beq _0808AC4A
	b _0808AEC8
_0808AC4A:
	ldr r0, _0808AC8C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808AC94
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _0808AC90 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0808AF2C
	.align 2, 0
_0808AC8C: .4byte gCurStory
_0808AC90: .4byte gEnemyFnTable
_0808AC94:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xc
	bls _0808AC9C
	b _0808AF2E
_0808AC9C:
	lsls r0, r0, #2
	ldr r1, _0808ACA8 @ =_0808ACAC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808ACA8: .4byte _0808ACAC
_0808ACAC: @ jump table
	.4byte _0808ACE0 @ case 0
	.4byte _0808AD0C @ case 1
	.4byte _0808AF2E @ case 2
	.4byte _0808AF2E @ case 3
	.4byte _0808AF2E @ case 4
	.4byte _0808AF2E @ case 5
	.4byte _0808AF2E @ case 6
	.4byte _0808AF2E @ case 7
	.4byte _0808AF2E @ case 8
	.4byte _0808AF2E @ case 9
	.4byte _0808AD0C @ case 10
	.4byte _0808AD40 @ case 11
	.4byte _0808AE80 @ case 12
_0808ACE0:
	ldr r1, _0808AD34 @ =0x00006E09
	adds r0, r7, #0
	bl SetMotion
	movs r2, #0
	movs r0, #0xa
	strb r0, [r7, #0xe]
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
	adds r0, r7, #0
	adds r0, #0x5c
	str r2, [r0, #4]
	str r2, [r7, #0x5c]
_0808AD0C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r2, #0
	movs r0, #0x78
	strb r0, [r7, #0x12]
	str r2, [r7, #0x60]
	movs r0, #0x80
	str r0, [r7, #0x5c]
	ldr r1, _0808AD38 @ =gOverworld
	ldr r0, _0808AD3C @ =0x0002D02C
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc3
	strb r2, [r0]
	b _0808AE78
	.align 2, 0
_0808AD34: .4byte 0x00006E09
_0808AD38: .4byte gOverworld
_0808AD3C: .4byte 0x0002D02C
_0808AD40:
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _0808AD50
	str r1, [r7, #0x60]
_0808AD50:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r5, r1, r0
	str r5, [r7, #0x58]
	ldr r1, [r7, #0x54]
	ldr r0, [r7, #0x5c]
	adds r4, r1, r0
	str r4, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808AE2C
	str r4, [sp]
	str r5, [sp, #4]
	ldr r1, _0808AE44 @ =0xFFFFD800
	adds r4, r4, r1
	ldr r2, _0808AE48 @ =RNG_0202f388
	mov sl, r2
	ldr r0, [r2]
	ldr r1, _0808AE4C @ =0x000343FD
	mov sb, r1
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _0808AE50 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r6, r0, #1
	mov r2, sl
	str r6, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r4, r4, r0
	str r4, [sp]
	ldr r0, _0808AE54 @ =0xFFFFE800
	adds r4, r5, r0
	mov r0, sb
	muls r0, r6, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, sl
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	adds r4, r4, r0
	str r4, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	mov r1, sl
	ldr r0, [r1]
	mov r4, sb
	muls r4, r0, r4
	add r4, r8
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r1]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [sp]
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r6, sp, #8
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	mov sb, r2
	ands r1, r2
	ldr r0, _0808AE58 @ =0x00006E07
	mov r8, r0
	adds r0, r6, #0
	mov r2, r8
	adds r3, r4, #0
	bl CreateVFX63
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	mov r2, sb
	ands r1, r2
	ldr r2, _0808AE5C @ =0x00006E08
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX63
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	mov r0, sb
	ands r1, r0
	adds r0, r6, #0
	mov r2, r8
	adds r3, r4, #0
	bl CreateVFX63
_0808AE2C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808AE60
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0808AE66
	.align 2, 0
_0808AE44: .4byte 0xFFFFD800
_0808AE48: .4byte RNG_0202f388
_0808AE4C: .4byte 0x000343FD
_0808AE50: .4byte 0x00269EC3
_0808AE54: .4byte 0xFFFFE800
_0808AE58: .4byte 0x00006E07
_0808AE5C: .4byte 0x00006E08
_0808AE60:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808AE66:
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0808AE78
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808AF2E
_0808AE78:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808AF2E
_0808AE80:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	bne _0808AF14
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #0
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0808AEC0 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808AEC4 @ =0x0000270E
	cmp r1, r0
	bhi _0808AEB6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808AEB6:
	adds r0, r7, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	b _0808AF14
	.align 2, 0
_0808AEC0: .4byte gMission
_0808AEC4: .4byte 0x0000270E
_0808AEC8:
	ldr r0, _0808AF0C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808AF14
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
	ldr r1, _0808AF10 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0808AF2C
	.align 2, 0
_0808AF0C: .4byte gCurStory
_0808AF10: .4byte gEnemyFnTable
_0808AF14:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808AF40 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0808AF2C:
	str r0, [r7, #0x14]
_0808AF2E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AF40: .4byte gEnemyFnTable

	thumb_func_start CarrybeeG_Disappear
CarrybeeG_Disappear: @ 0x0808AF44
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	bne _0808AF64
	adds r0, r2, #0
	adds r0, #0xc3
	ldrb r0, [r0]
	cmp r0, #1
	bne _0808AF64
	ldr r1, _0808AF70 @ =gOverworld
	ldr r0, _0808AF74 @ =0x0002D02C
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0808AF64:
	adds r0, r2, #0
	bl DeleteEnemy
	pop {r0}
	bx r0
	.align 2, 0
_0808AF70: .4byte gOverworld
_0808AF74: .4byte 0x0002D02C

	thumb_func_start FUN_0808af78
FUN_0808af78: @ 0x0808AF78
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808af7c
FUN_0808af7c: @ 0x0808AF7C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808AF9C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808AFA0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808AFA4
	cmp r5, #1
	beq _0808AFD4
	b _0808AFF8
	.align 2, 0
_0808AF9C: .4byte gStageRun+232
_0808AFA0: .4byte 0xFFFFC000
_0808AFA4:
	adds r0, r4, #0
	adds r0, #0xb8
	str r5, [r0]
	ldr r0, _0808B000 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x64]
	movs r0, #0x8c
	lsls r0, r0, #7
	str r0, [r4, #0x5c]
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808B004 @ =0x08368C6C
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808AFD4:
	ldr r0, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r0, r2
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r1, r0
	ble _0808AFF2
	str r1, [r4, #0x68]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808AFF2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808AFF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B000: .4byte pZero2
_0808B004: .4byte 0x08368C6C

	thumb_func_start FUN_0808b008
FUN_0808b008: @ 0x0808B008
	movs r0, #1
	bx lr

	thumb_func_start carrybeeg_0808b00c
carrybeeg_0808b00c: @ 0x0808B00C
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r0, _0808B02C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B030 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	beq _0808B034
	cmp r0, #1
	beq _0808B03E
	b _0808B100
	.align 2, 0
_0808B02C: .4byte gStageRun+232
_0808B030: .4byte 0xFFFFC000
_0808B034:
	movs r0, #0x40
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0808B03E:
	ldrb r0, [r3, #0x12]
	adds r4, r0, #1
	strb r4, [r3, #0x12]
	adds r0, r3, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3, #0x68]
	ldr r2, _0808B0D0 @ =gSineTable
	ldrb r0, [r3, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r2, [r0, r5]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r3, #0x58]
	ldrb r0, [r3, #0x13]
	cmp r0, #0
	beq _0808B07A
	subs r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B0EA
_0808B07A:
	adds r0, r3, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	beq _0808B090
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _0808B090
	ldr r0, [r3, #0x28]
	cmp r0, #0
	bne _0808B0E4
_0808B090:
	ldr r0, _0808B0D4 @ =gZakoHeaderPtr
	ldr r1, [r0]
	movs r2, #8
	ldrsh r0, [r1, r2]
	movs r5, #0xa
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #5
	bgt _0808B0E4
	ldr r2, _0808B0D8 @ =gCurStory
	ldrb r1, [r2, #8]
	movs r0, #0x42
	ands r0, r1
	cmp r0, #0
	bne _0808B0E4
	ldrb r1, [r2, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808B0C6
	ldr r0, _0808B0DC @ =gSystemSavedataManager
	ldr r1, [r0, #0x40]
	ldr r0, _0808B0E0 @ =0x000032DA
	cmp r1, r0
	beq _0808B0C6
	cmp r1, #0
	bne _0808B0E4
_0808B0C6:
	movs r1, #0
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
	b _0808B0FA
	.align 2, 0
_0808B0D0: .4byte gSineTable
_0808B0D4: .4byte gZakoHeaderPtr
_0808B0D8: .4byte gCurStory
_0808B0DC: .4byte gSystemSavedataManager
_0808B0E0: .4byte 0x000032DA
_0808B0E4:
	movs r0, #0x40
	strb r0, [r3, #0x13]
	b _0808B0FA
_0808B0EA:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _0808B0FA
	movs r0, #3
	strb r0, [r3, #0xd]
	movs r0, #0
	strb r0, [r3, #0xe]
_0808B0FA:
	adds r0, r3, #0
	bl UpdateMotionGraphic
_0808B100:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808b108
FUN_0808b108:
  movs r0, #1
	bx lr

	thumb_func_start FUN_0808b10c
FUN_0808b10c: @ 0x0808B10C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808B134 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B138 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0808B128
	b _0808B2A8
_0808B128:
	lsls r0, r0, #2
	ldr r1, _0808B13C @ =_0808B140
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808B134: .4byte gStageRun+232
_0808B138: .4byte 0xFFFFC000
_0808B13C: .4byte _0808B140
_0808B140: @ jump table
	.4byte _0808B15C @ case 0
	.4byte _0808B16A @ case 1
	.4byte _0808B1B4 @ case 2
	.4byte _0808B24C @ case 3
	.4byte _0808B1BA @ case 4
	.4byte _0808B24C @ case 5
	.4byte _0808B2A0 @ case 6
_0808B15C:
	ldr r1, _0808B1AC @ =0x00006E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B16A:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B1B0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808B1A8
	b _0808B2A8
_0808B1A8:
	b _0808B28E
	.align 2, 0
_0808B1AC: .4byte 0x00006E01
_0808B1B0: .4byte gSineTable
_0808B1B4:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	b _0808B246
_0808B1BA:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0808B1FC @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r2, #0xd8
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp, #4]
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	bne _0808B200
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r5]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc0
	b _0808B23A
	.align 2, 0
_0808B1FC: .4byte 0xFFFFF600
_0808B200:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _0808B21E
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r4, #0x2c]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc1
	b _0808B23A
_0808B21E:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _0808B23E
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r4, #0x28]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc2
_0808B23A:
	movs r0, #0x20
	strb r0, [r1]
_0808B23E:
	ldr r1, _0808B298 @ =0x00006E03
	adds r0, r4, #0
	bl SetMotion
_0808B246:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B24C:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B29C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0808B28E
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B2A8
_0808B28E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B2A8
	.align 2, 0
_0808B298: .4byte 0x00006E03
_0808B29C: .4byte gSineTable
_0808B2A0:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808B2A8:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808b2b0
FUN_0808b2b0:
  movs r0, #1
	bx lr

	thumb_func_start FUN_0808b2b4
FUN_0808b2b4: @ 0x0808B2B4
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808B2DC @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B2E0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0808B2D0
	b _0808B40A
_0808B2D0:
	lsls r0, r0, #2
	ldr r1, _0808B2E4 @ =_0808B2E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808B2DC: .4byte gStageRun+232
_0808B2E0: .4byte 0xFFFFC000
_0808B2E4: .4byte _0808B2E8
_0808B2E8: @ jump table
	.4byte _0808B304 @ case 0
	.4byte _0808B312 @ case 1
	.4byte _0808B354 @ case 2
	.4byte _0808B390 @ case 3
	.4byte _0808B35A @ case 4
	.4byte _0808B390 @ case 5
	.4byte _0808B3DC @ case 6
_0808B304:
	ldr r1, _0808B34C @ =0x00006E04
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B312:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B350 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808B40A
	b _0808B3CC
	.align 2, 0
_0808B34C: .4byte 0x00006E04
_0808B350: .4byte gSineTable
_0808B354:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	b _0808B38A
_0808B35A:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r1, #0xac
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #0
	bl FUN_080adad0
	ldr r1, _0808B3D4 @ =0x00006E05
	adds r0, r4, #0
	bl SetMotion
_0808B38A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B390:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B3D8 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0808B3CC
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B40A
_0808B3CC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B40A
	.align 2, 0
_0808B3D4: .4byte 0x00006E05
_0808B3D8: .4byte gSineTable
_0808B3DC:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B414 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808B40A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B414: .4byte gSineTable

	thumb_func_start FUN_0808b418
FUN_0808b418:
  movs r0, #1
	bx lr

	thumb_func_start FUN_0808b41c
FUN_0808b41c: @ 0x0808B41C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldrb r0, [r2, #0xc]
	cmp r0, #2
	bls _0808B442
	adds r0, r4, #0
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
	b _0808B46A
_0808B442:
	ldr r0, _0808B48C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808B494
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
_0808B46A:
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808B490 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #0x11]
	adds r0, r4, #0
	bl CarrybeeG_Die
	b _0808B52E
	.align 2, 0
_0808B48C: .4byte gCurStory
_0808B490: .4byte gEnemyFnTable
_0808B494:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0808B4D0
	cmp r5, #1
	bgt _0808B4A4
	cmp r5, #0
	beq _0808B4AA
	b _0808B52E
_0808B4A4:
	cmp r5, #2
	beq _0808B4F8
	b _0808B52E
_0808B4AA:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r1, _0808B4F0 @ =0x00006E06
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808B4F4 @ =0x08368C54
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B4D0:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808B52E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B52E
	.align 2, 0
_0808B4F0: .4byte 0x00006E06
_0808B4F4: .4byte 0x08368C54
_0808B4F8:
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808B518
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0808B51E
_0808B518:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808B51E:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808B52E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_0808b534
nop_0808b534: @ 0x0808B534
	bx lr
	.align 2, 0
