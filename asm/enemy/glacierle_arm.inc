	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createGlacierleAtkHand
createGlacierleAtkHand: @ 0x08082194
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, _08082210 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r7, r0, #0
	cmp r7, #0
	beq _08082204
	adds r1, r7, #0
	adds r1, #0x25
	movs r5, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08082214 @ =gEnemyFnTable
	movs r1, #0x27
	strb r1, [r7, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r7, #0x14]
	movs r6, #0
	strh r5, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r7, #0xb]
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r7, #0xb]
	ldrb r0, [r7, #0x1c]
	strb r0, [r7, #0x1d]
	strb r6, [r7, #0x10]
	adds r0, r7, #0
	bl InitRotatableMotion
	str r5, [r7, #0x2c]
	mov r0, r8
	str r0, [r7, #0x28]
	str r5, [r7, #0x5c]
	str r5, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0xb5
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb4
	strb r6, [r0]
	ldrb r0, [r7, #0xb]
	orrs r4, r0
	strb r4, [r7, #0xb]
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	strb r0, [r7, #0x1d]
_08082204:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08082210: .4byte gZakoHeaderPtr
_08082214: .4byte gEnemyFnTable

	thumb_func_start createGlacierleJoint
createGlacierleJoint: @ 0x08082218
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _080822A4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080822D8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080822A8 @ =gEnemyFnTable
	movs r1, #0x27
	strb r1, [r3, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	ldr r0, [r7, #0x2c]
	str r0, [r3, #0x2c]
	str r7, [r3, #0x28]
	ldr r2, [r7, #0x2c]
	cmp r2, #0
	beq _080822AC
	str r3, [r2, #0x28]
	ldr r0, [r2, #0x5c]
	str r0, [r3, #0x5c]
	ldr r0, [r2, #0x60]
	str r0, [r3, #0x60]
	ldr r5, [r2, #0x54]
	str r5, [r3, #0x54]
	ldr r6, [r2, #0x58]
	str r6, [r3, #0x58]
	ldr r4, [r2, #0x2c]
	cmp r4, #0
	beq _0808229A
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	adds r0, r5, r0
	str r0, [r3, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	adds r0, r6, r0
	str r0, [r3, #0x58]
_0808229A:
	ldr r0, [r3, #0x54]
	str r0, [r3, #0x64]
	ldr r0, [r3, #0x58]
	str r0, [r3, #0x68]
	b _080822B0
	.align 2, 0
_080822A4: .4byte gZakoHeaderPtr
_080822A8: .4byte gEnemyFnTable
_080822AC:
	str r2, [r3, #0x5c]
	str r2, [r3, #0x60]
_080822B0:
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	strb r0, [r3, #0x1d]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	str r3, [r7, #0x2c]
	adds r1, r7, #0
	adds r1, #0xb4
	ldrb r0, [r1]
	adds r2, r3, #0
	adds r2, #0xb6
	strb r0, [r2]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080822D8:
	adds r0, r3, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start createGlacierleSucker
createGlacierleSucker: @ 0x080822E4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08082340 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08082336
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08082344 @ =gEnemyFnTable
	movs r1, #0x27
	strb r1, [r3, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r2, [r3, #0xb]
	movs r1, #0x10
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x2c]
	orrs r1, r2
	strb r1, [r3, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r3, #0x1d]
	adds r0, r3, #0
	adds r0, #0xbc
	str r4, [r0]
_08082336:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08082340: .4byte gZakoHeaderPtr
_08082344: .4byte gEnemyFnTable

	thumb_func_start FUN_08082348
FUN_08082348: @ 0x08082348
	push {lr}
	adds r1, r0, #0
	ldr r3, [r1, #0x2c]
	cmp r3, #0
	beq _0808239C
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _0808235A
	str r1, [r0, #0x28]
_0808235A:
	ldr r0, [r3, #0x2c]
	str r0, [r1, #0x2c]
	adds r1, #0xb4
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _080823A0 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_0808239C:
	pop {r0}
	bx r0
	.align 2, 0
_080823A0: .4byte gEnemyFnTable

	thumb_func_start FUN_080823a4
FUN_080823a4: @ 0x080823A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r2, #0xa
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r2, r0
	beq _080823E6
	adds r1, r0, #0
	cmp r2, r1
	ble _080823D2
	subs r0, r2, r1
	cmp r0, #0
	ble _080823E6
	adds r4, r0, #0
_080823C2:
	adds r0, r5, #0
	adds r1, r6, #0
	bl createGlacierleJoint
	subs r4, #1
	cmp r4, #0
	bne _080823C2
	b _080823E6
_080823D2:
	subs r0, #0xa
	cmp r0, #0
	ble _080823E6
	adds r4, r0, #0
_080823DA:
	adds r0, r5, #0
	bl FUN_08082348
	subs r4, #1
	cmp r4, #0
	bne _080823DA
_080823E6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080823ec
FUN_080823ec: @ 0x080823EC
	push {lr}
	ldr r3, [r0, #0x2c]
	cmp r3, #0
	beq _08082426
	ldr r2, [r3, #0x2c]
	cmp r2, #0
	beq _08082426
	ldr r1, [r2, #0x54]
	ldr r0, [r3, #0x54]
	subs r1, r1, r0
	ldr r0, [r2, #0x58]
	ldr r2, [r3, #0x58]
	subs r0, r0, r2
	asrs r1, r1, #8
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	asrs r0, r0, #8
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r1, r0, #8
	adds r0, r1, #0
	b _08082428
_08082426:
	movs r0, #0
_08082428:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808242c
FUN_0808242c: @ 0x0808242C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r1
	mov r8, r2
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r2, [r1]
	ldr r4, [r0, #0x2c]
	cmp r4, #0
	beq _08082478
	adds r7, r1, #0
	mov r6, r8
	muls r6, r2, r6
	mov r5, sb
	muls r5, r2, r5
_0808244E:
	ldrb r1, [r7]
	adds r0, r5, #0
	bl __divsi3
	ldr r1, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r1, [r7]
	adds r0, r6, #0
	bl __divsi3
	ldr r1, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	mov r0, r8
	subs r6, r6, r0
	mov r0, sb
	subs r5, r5, r0
	ldr r4, [r4, #0x2c]
	cmp r4, #0
	bne _0808244E
_08082478:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08082484
FUN_08082484: @ 0x08082484
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	mov sl, r2
	ldr r0, [r6, #0x54]
	subs r1, r1, r0
	mov sb, r1
	ldr r0, [r6, #0x58]
	subs r2, r2, r0
	mov sl, r2
	asrs r0, r1, #8
	adds r5, r0, #0
	muls r5, r0, r5
	asrs r0, r2, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r5, r5, r0
	adds r0, r5, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #8
	ldr r2, [r6, #0x54]
	mov r8, r2
	ldr r7, [r6, #0x58]
	cmp r5, #0
	beq _080824FA
	mov r1, sb
	lsls r0, r1, #8
	adds r1, r5, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r2, r4, #2
	mov r8, r2
	ldr r0, [r6, #0x54]
	add r8, r0
	mov r1, sl
	lsls r0, r1, #8
	adds r1, r5, #0
	bl __divsi3
	lsls r7, r0, #2
	ldr r1, [r6, #0x58]
	adds r7, r7, r1
	lsls r4, r4, #3
	mov r2, sb
	subs r2, r2, r4
	mov sb, r2
	lsls r0, r0, #3
	mov r1, sl
	subs r1, r1, r0
	mov sl, r1
_080824FA:
	ldr r4, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0xb4
	ldrb r0, [r1]
	cmp r0, #1
	bne _08082522
	mov r2, sb
	asrs r2, r2, #8
	str r2, [sp]
	mov r0, sl
	asrs r0, r0, #8
	str r0, [sp, #4]
	adds r6, #0x24
	str r6, [sp, #8]
	cmp r4, #0
	beq _08082572
	mov r1, r8
	str r1, [r4, #0x54]
	str r7, [r4, #0x58]
	b _08082572
_08082522:
	mov r2, sb
	asrs r2, r2, #8
	str r2, [sp]
	mov r0, sl
	asrs r0, r0, #8
	str r0, [sp, #4]
	adds r6, #0x24
	str r6, [sp, #8]
	cmp r4, #0
	beq _08082572
	adds r5, r1, #0
	movs r1, #0
	str r1, [sp, #0xc]
	movs r6, #0
_0808253E:
	mov r2, r8
	str r2, [r4, #0x54]
	ldrb r1, [r5]
	subs r1, #1
	adds r0, r6, #0
	bl __divsi3
	add r0, r8
	str r0, [r4, #0x54]
	str r0, [r4, #0x64]
	str r7, [r4, #0x58]
	ldrb r1, [r5]
	subs r1, #1
	ldr r0, [sp, #0xc]
	bl __divsi3
	adds r0, r7, r0
	str r0, [r4, #0x58]
	str r0, [r4, #0x68]
	ldr r0, [sp, #0xc]
	add r0, sl
	str r0, [sp, #0xc]
	add r6, sb
	ldr r4, [r4, #0x2c]
	cmp r4, #0
	bne _0808253E
_08082572:
	ldr r1, [sp]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #4]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsrs r0, r0, #8
	ldr r1, [sp, #8]
	strb r0, [r1]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start glacierle_08082598
glacierle_08082598: @ 0x08082598
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	ldr r4, [r0, #0x2c]
	cmp r1, #0
	beq _080825F2
	cmp r4, #0
	beq _0808261E
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0808261E
_080825BA:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r3, r1, r0
	str r3, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	cmp r2, #0
	ble _080825E4
	adds r0, r3, #0
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r6, #0
	bge _080825E4
	ldr r0, [r4, #0x58]
	adds r0, r0, r6
	str r0, [r4, #0x58]
_080825E4:
	ldr r4, [r4, #0x2c]
	cmp r4, #0
	beq _0808261E
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _080825BA
	b _0808261E
_080825F2:
	cmp r4, #0
	beq _0808261E
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _0808261E
_080825FC:
	ldr r2, [r4, #0x60]
	adds r2, #0x20
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r4, r3, #0
	cmp r4, #0
	beq _0808261E
	ldr r0, [r4, #0x2c]
	adds r3, r0, #0
	cmp r3, #0
	bne _080825FC
_0808261E:
	mov r0, r8
	ldr r4, [r0, #0x2c]
	movs r3, #0
	cmp r4, #0
	beq _080826A8
	ldr r3, [r4, #0x2c]
	b _080826A8
_0808262C:
	ldr r1, [r3, #0x54]
	ldr r0, [r4, #0x54]
	subs r7, r1, r0
	ldr r1, [r3, #0x58]
	ldr r0, [r4, #0x58]
	subs r6, r1, r0
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	str r3, [sp]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r3, [sp]
	cmp r5, #0
	beq _080826A4
	lsls r0, r7, #8
	adds r1, r5, #0
	bl __divsi3
	adds r7, r0, #0
	lsls r0, r6, #8
	adds r1, r5, #0
	bl __divsi3
	adds r6, r0, #0
	mov r1, r8
	ldr r0, [r1, #0x64]
	subs r5, r5, r0
	lsrs r0, r5, #0x1f
	adds r0, r5, r0
	asrs r5, r0, #1
	adds r0, r7, #0
	muls r0, r5, r0
	ldr r3, [sp]
	cmp r0, #0
	bge _0808267E
	adds r0, #0xff
_0808267E:
	asrs r7, r0, #8
	adds r0, r6, #0
	muls r0, r5, r0
	cmp r0, #0
	bge _0808268A
	adds r0, #0xff
_0808268A:
	asrs r6, r0, #8
	ldr r0, [r4, #0x54]
	adds r0, r0, r7
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r6
	str r0, [r4, #0x58]
	ldr r0, [r3, #0x54]
	subs r0, r0, r7
	str r0, [r3, #0x54]
	ldr r0, [r3, #0x58]
	subs r0, r0, r6
	str r0, [r3, #0x58]
_080826A4:
	adds r4, r3, #0
	ldr r3, [r3, #0x2c]
_080826A8:
	cmp r3, #0
	bne _0808262C
	mov r2, r8
	ldr r4, [r2, #0x2c]
	adds r1, r4, #0
	cmp r4, #0
	beq _080826F2
_080826B6:
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x64]
	subs r7, r3, r0
	ldr r2, [r4, #0x58]
	ldr r0, [r4, #0x68]
	subs r6, r2, r0
	movs r5, #0xfa
	mov r0, sb
	cmp r0, #0
	beq _080826CC
	movs r5, #0xe1
_080826CC:
	adds r0, r7, #0
	muls r0, r5, r0
	cmp r0, #0
	bge _080826D6
	adds r0, #0xff
_080826D6:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	adds r0, r6, #0
	muls r0, r5, r0
	cmp r0, #0
	bge _080826E4
	adds r0, #0xff
_080826E4:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	str r3, [r4, #0x64]
	str r2, [r4, #0x68]
	ldr r4, [r4, #0x2c]
	cmp r4, #0
	bne _080826B6
_080826F2:
	mov r2, sb
	cmp r2, #0
	bne _080826FA
	b _08082816
_080826FA:
	adds r3, r1, #0
	cmp r3, #0
	bne _08082702
	b _08082878
_08082702:
	ldr r5, [r3, #0x54]
	mov r6, r8
	str r5, [r6, #0x54]
	ldr r3, [r3, #0x58]
	str r3, [r6, #0x58]
	mov r7, r8
	adds r7, #0x24
	ldrb r4, [r7]
	adds r0, r4, #0
	adds r0, #0x40
	lsls r1, r0, #0x18
	cmp r1, #0
	blt _08082792
	ldr r6, _0808277C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #0xc
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08082730
	adds r0, #0xff
_08082730:
	asrs r2, r0, #8
	lsrs r0, r1, #0x17
	adds r0, r0, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r6, r2, r0
	adds r1, r3, r6
	adds r0, r5, #0
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _0808278C
	ldr r2, _08082780 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08082784 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08082788 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r5, #0
	adds r0, #0xff
	asrs r0, r0, #8
	subs r0, r4, r0
	b _080827F8
	.align 2, 0
_0808277C: .4byte gSineTable
_08082780: .4byte RNG_0202f388
_08082784: .4byte 0x000343FD
_08082788: .4byte 0x00269EC3
_0808278C:
	subs r0, r4, #2
	strb r0, [r7]
	b _08082878
_08082792:
	ldr r6, _08082800 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #0xc
	rsbs r0, r0, #0
	cmp r0, #0
	bge _080827A6
	adds r0, #0xff
_080827A6:
	asrs r2, r0, #8
	lsrs r0, r1, #0x17
	adds r0, r0, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #9
	rsbs r0, r0, #0
	cmp r0, #0
	bge _080827BE
	adds r0, #0xff
_080827BE:
	asrs r0, r0, #8
	adds r6, r2, r0
	adds r1, r3, r6
	adds r0, r5, #0
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _08082810
	ldr r2, _08082804 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08082808 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808280C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	bl __umodsi3
	subs r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r5, #0
	adds r0, #0xff
	asrs r0, r0, #8
	adds r0, r4, r0
_080827F8:
	strb r0, [r7]
	movs r0, #1
	b _0808287A
	.align 2, 0
_08082800: .4byte gSineTable
_08082804: .4byte RNG_0202f388
_08082808: .4byte 0x000343FD
_0808280C: .4byte 0x00269EC3
_08082810:
	adds r0, r4, #2
	strb r0, [r7]
	b _08082878
_08082816:
	adds r3, r1, #0
	cmp r3, #0
	beq _08082878
	ldr r4, [r3, #0x2c]
	cmp r4, #0
	beq _08082878
	ldr r1, [r4, #0x54]
	ldr r0, [r3, #0x54]
	subs r7, r1, r0
	ldr r1, [r4, #0x58]
	ldr r0, [r3, #0x58]
	subs r6, r1, r0
	lsls r0, r7, #8
	asrs r0, r0, #0x10
	lsls r1, r6, #8
	asrs r1, r1, #0x10
	str r3, [sp]
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x18
	mov r0, r8
	adds r0, #0x24
	strb r4, [r0]
	ldr r3, [sp]
	ldr r1, [r3, #0x54]
	mov r2, r8
	str r1, [r2, #0x54]
	ldr r2, _08082888 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #2
	subs r1, r1, r0
	mov r6, r8
	str r1, [r6, #0x54]
	ldr r1, [r3, #0x58]
	str r1, [r6, #0x58]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	subs r1, r1, r0
	str r1, [r6, #0x58]
_08082878:
	movs r0, #0
_0808287A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08082888: .4byte gSineTable

	thumb_func_start FUN_0808288c
FUN_0808288c: @ 0x0808288C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r4, [r5, #0x2c]
	cmp r4, #0
	beq _080828D2
	adds r1, r6, #0
	subs r1, #0x40
	adds r0, #0x24
	strb r1, [r0]
	ldr r2, [r5, #0x54]
	str r2, [r4, #0x54]
	ldr r3, _080828D8 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	adds r0, r0, r1
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r2, [r5, #0x58]
	str r2, [r4, #0x58]
	lsls r0, r6, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	adds r2, r2, r0
	str r2, [r4, #0x58]
_080828D2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080828D8: .4byte gSineTable

	thumb_func_start nop_080828dc
nop_080828dc: @ 0x080828DC
	bx lr
	.align 2, 0

	thumb_func_start GlacierleAtkArm_Init
GlacierleAtkArm_Init: @ 0x080828E0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08082940 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08082944 @ =0x08368170
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r1, r0
	movs r0, #1
	movs r2, #0
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _08082932
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08082948 @ =0x08368140
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0808294C @ =nop_080828dc
	str r0, [r4, #0x24]
_08082932:
	adds r0, r5, #0
	bl GlacierleAtkArm_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082940: .4byte gEnemyFnTable
_08082944: .4byte 0x08368170
_08082948: .4byte 0x08368140
_0808294C: .4byte nop_080828dc

	thumb_func_start GlacierleAtkArm_Update
GlacierleAtkArm_Update: @ 0x08082950
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808297C @ =0x08368128
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08082980 @ =0x08368134
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808297C: .4byte 0x08368128
_08082980: .4byte 0x08368134

	thumb_func_start GlacierleAtkArm_Die
GlacierleAtkArm_Die: @ 0x08082984
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	blt _08082A12
	cmp r0, #1
	ble _08082998
	cmp r0, #2
	beq _08082A00
	b _08082A12
_08082998:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080829A4
	cmp r0, #1
	beq _080829AC
	b _08082A12
_080829A4:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080829AC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080829BC
	str r1, [r4, #0x60]
_080829BC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08082A12
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080829E8
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	b _08082A00
_080829E8:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08082A00
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_08082A00:
	ldr r1, _08082A18 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_08082A12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08082A18: .4byte gEnemyFnTable

	thumb_func_start nop_08082a1c
nop_08082a1c: @ 0x08082A1C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08082a20
FUN_08082a20: @ 0x08082A20
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08082A30
	cmp r0, #1
	beq _08082A68
	b _08082A78
_08082A30:
	adds r4, r6, #0
	adds r4, #0x24
	ldrb r5, [r4]
	adds r0, r6, #0
	bl InitRotatableMotion
	movs r1, #0xb2
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	strb r5, [r4]
	adds r0, r6, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08082A58
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08082A58:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08082A98 @ =0x08368158
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08082A68:
	adds r0, r6, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082A78
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08082A78:
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08082A92
	ldr r1, _08082A9C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_08082A92:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082A98: .4byte 0x08368158
_08082A9C: .4byte gEnemyFnTable

	thumb_func_start FUN_08082aa0
FUN_08082aa0: @ 0x08082AA0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08082AB0
	cmp r0, #1
	beq _08082AC4
	b _08082ACA
_08082AB0:
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldr r1, _08082AF0 @ =0x00005901
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08082AC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08082ACA:
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08082AE8
	ldr r1, _08082AF4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_08082AE8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08082AF0: .4byte 0x00005901
_08082AF4: .4byte gEnemyFnTable

	thumb_func_start FUN_08082af8
FUN_08082af8: @ 0x08082AF8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08082B08
	cmp r0, #1
	beq _08082B24
	b _08082B2A
_08082B08:
	adds r4, r6, #0
	adds r4, #0x24
	ldrb r5, [r4]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldr r1, _08082B50 @ =0x00005902
	adds r0, r6, #0
	bl SetMotion
	strb r5, [r4]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08082B24:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08082B2A:
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08082B48
	ldr r1, _08082B54 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_08082B48:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082B50: .4byte 0x00005902
_08082B54: .4byte gEnemyFnTable
