	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createPAquaModRubble
createPAquaModRubble: @ 0x08080804
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08080850 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808084A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08080854 @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
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
	movs r0, #8
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
_0808084A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080850: .4byte gZakoHeaderPtr
_08080854: .4byte gEnemyFnTable

	thumb_func_start FUN_08080858
FUN_08080858: @ 0x08080858
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080808AC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080808A6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080808B0 @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
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
	movs r0, #6
	strb r0, [r3, #0x10]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
_080808A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080808AC: .4byte gZakoHeaderPtr
_080808B0: .4byte gEnemyFnTable

	thumb_func_start FUN_080808b4
FUN_080808b4: @ 0x080808B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08080900 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080808FA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08080904 @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
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
	movs r0, #3
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
_080808FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080900: .4byte gZakoHeaderPtr
_08080904: .4byte gEnemyFnTable

	thumb_func_start FUN_08080908
FUN_08080908: @ 0x08080908
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808095C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _08080954
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08080960 @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r4, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	str r5, [r4, #0x28]
_08080954:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808095C: .4byte gZakoHeaderPtr
_08080960: .4byte gEnemyFnTable

	thumb_func_start FUN_08080964
FUN_08080964: @ 0x08080964
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080809B8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080809B2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080809BC @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
_080809B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080809B8: .4byte gZakoHeaderPtr
_080809BC: .4byte gEnemyFnTable

	thumb_func_start createLaserSign2
createLaserSign2: @ 0x080809C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08080A1C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08080A16
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08080A20 @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
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
	movs r0, #2
	strb r0, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _08080A24 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
_08080A16:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080A1C: .4byte gZakoHeaderPtr
_08080A20: .4byte gEnemyFnTable
_08080A24: .4byte 0xFFFFF400

	thumb_func_start createSweepLaserSign
createSweepLaserSign: @ 0x08080A28
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08080A84 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08080A7E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08080A88 @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
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
	movs r0, #2
	strb r0, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _08080A8C @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
_08080A7E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080A84: .4byte gZakoHeaderPtr
_08080A88: .4byte gEnemyFnTable
_08080A8C: .4byte 0xFFFFF400

	thumb_func_start createStretchedGrabArm
createStretchedGrabArm: @ 0x08080A90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _08080B68 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _08080B06
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08080B6C @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r4, #9]
	adds r0, #0x98
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #5
	strb r0, [r4, #0x10]
	strb r6, [r4, #0x11]
	mov r0, r8
	ldr r1, [r0, #0x54]
	ldr r0, _08080B70 @ =0xFFFFE900
	adds r1, r1, r0
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #3
	subs r0, r0, r6
	lsls r0, r0, #9
	adds r1, r1, r0
	str r1, [r4, #0x54]
	mov r1, r8
	ldr r0, [r1, #0x58]
	ldr r1, _08080B74 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	mov r0, r8
	str r0, [r4, #0x28]
_08080B06:
	movs r5, #0
	movs r7, #0
	ldr r0, _08080B78 @ =0x083659E0
	mov sb, r0
_08080B0E:
	ldr r0, _08080B68 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	adds r3, r5, #1
	cmp r2, #0
	beq _08080B54
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0x26
	strb r0, [r2, #9]
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r7, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r7, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #4
	strb r0, [r2, #0x10]
	strb r6, [r2, #0x11]
	mov r0, r8
	str r0, [r2, #0x28]
	str r4, [r2, #0x2c]
	strb r3, [r2, #0x12]
_08080B54:
	adds r5, r3, #0
	cmp r5, #5
	ble _08080B0E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080B68: .4byte gZakoHeaderPtr
_08080B6C: .4byte gEnemyFnTable
_08080B70: .4byte 0xFFFFE900
_08080B74: .4byte 0xFFFFFC00
_08080B78: .4byte 0x083659E0

	thumb_func_start createStretchedArms
createStretchedArms: @ 0x08080B7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r6, #0
_08080B8A:
	ldr r0, _08080C58 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _08080BEA
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0x26
	strb r0, [r4, #9]
	ldr r1, _08080C5C @ =0x083659E0
	ldr r0, [r1]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	movs r1, #0
	strb r1, [r0]
	ldrb r0, [r4, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #7
	strb r0, [r4, #0x10]
	strb r6, [r4, #0x11]
	ldr r1, [r7, #0x54]
	ldr r0, _08080C60 @ =0xFFFFE900
	adds r1, r1, r0
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #3
	subs r0, r0, r6
	lsls r0, r0, #9
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r7, #0x58]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r7, [r4, #0x28]
_08080BEA:
	movs r5, #0
	adds r0, r6, #1
	mov sb, r0
	mov r8, r5
	ldr r1, _08080C5C @ =0x083659E0
	mov sl, r1
_08080BF6:
	ldr r0, _08080C58 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	adds r3, r5, #1
	cmp r2, #0
	beq _08080C3E
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0x26
	strb r0, [r2, #9]
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	mov r0, r8
	strh r0, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	mov r1, r8
	strb r1, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #4
	strb r0, [r2, #0x10]
	strb r6, [r2, #0x11]
	str r7, [r2, #0x28]
	str r4, [r2, #0x2c]
	strb r3, [r2, #0x12]
_08080C3E:
	adds r5, r3, #0
	cmp r5, #5
	ble _08080BF6
	mov r6, sb
	cmp r6, #1
	ble _08080B8A
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080C58: .4byte gZakoHeaderPtr
_08080C5C: .4byte 0x083659E0
_08080C60: .4byte 0xFFFFE900

	thumb_func_start FUN_08080c64
FUN_08080c64: @ 0x08080C64
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08080CB4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08080CAE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08080CB8 @ =gEnemyFnTable
	movs r1, #0x26
	strb r1, [r3, #9]
	adds r0, #0x98
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
	movs r0, #9
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_08080CAE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08080CB4: .4byte gZakoHeaderPtr
_08080CB8: .4byte gEnemyFnTable

	thumb_func_start FUN_08080cbc
FUN_08080cbc: @ 0x08080CBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r1, #0
	ldr r4, [r0, #8]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r0, r5, #0
	bl Malloc
	str r0, [sp]
	cmp r0, #0
	bne _08080CDE
	b _08080E96
_08080CDE:
	movs r0, #0
	ldr r1, [sp]
	adds r2, r5, #0
	bl FillMemory
	ldr r0, [r4, #0x54]
	ldr r1, [r6, #8]
	subs r0, r0, r1
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [r4, #0x58]
	ldr r1, [r6, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r2, #0
	adds r4, #0xb4
	str r4, [sp, #0x1c]
_08080D06:
	lsls r2, r2, #0x10
	asrs r0, r2, #0x10
	mov sb, r0
	ldr r0, [sp, #0x1c]
	add r0, sb
	ldrb r1, [r0]
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	ldr r3, _08080DF0 @ =gSineTable
	adds r1, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r6, [r0]
	ldrh r5, [r1]
	mov ip, r5
	movs r0, #0
	ldrsh r3, [r1, r0]
	movs r1, #1
	mov sl, r1
	str r2, [sp, #0x20]
	cmp r3, #0
	bge _08080D3A
	ldr r2, _08080DF4 @ =0x0000FFFF
	mov sl, r2
_08080D3A:
	mov r5, sl
	str r5, [sp, #0xc]
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	movs r0, #1
	mov r8, r0
	cmp r1, #0
	bge _08080D4E
	ldr r2, _08080DF4 @ =0x0000FFFF
	mov r8, r2
_08080D4E:
	mov r5, r8
	str r5, [sp, #0x10]
	cmp r3, #0
	bge _08080D5E
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
_08080D5E:
	cmp r1, #0
	bge _08080D68
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08080D68:
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	lsls r1, r6, #0x10
	asrs r3, r1, #0x10
	adds r2, r0, #0
	cmp r5, r3
	ble _08080DF8
	ldr r7, [sp, #4]
	ldr r4, [sp, #8]
	movs r1, #1
	ldr r5, [sp, #0xc]
	lsls r0, r5, #0x10
	mov r5, sb
	lsls r5, r5, #3
	mov sl, r5
	asrs r0, r0, #0x10
	mov sb, r0
	mov r8, r3
	asrs r6, r2, #0x10
	ldr r2, [sp, #0x10]
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
_08080D96:
	lsls r3, r7, #0x10
	cmp r1, #0
	beq _08080DB2
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	ldr r1, [sp]
	adds r0, r0, r1
	asrs r1, r3, #0x10
	mov r2, sl
	lsls r1, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	movs r1, #0
_08080DB2:
	asrs r0, r3, #0x10
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0xef
	bhi _08080E60
	mov r3, ip
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov ip, r3
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08080D96
	movs r1, #1
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x9f
	bls _08080D96
	b _08080E60
	.align 2, 0
_08080DF0: .4byte gSineTable
_08080DF4: .4byte 0x0000FFFF
_08080DF8:
	ldr r7, [sp, #4]
	ldr r4, [sp, #8]
	mov r2, r8
	lsls r0, r2, #0x10
	mov r3, sb
	lsls r3, r3, #3
	str r3, [sp, #0x14]
	asrs r0, r0, #0x10
	str r0, [sp, #0x18]
	mov ip, r5
	asrs r1, r1, #0x10
	mov sb, r1
	mov r5, sl
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
_08080E18:
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	ldr r0, [sp]
	adds r3, r3, r0
	lsls r0, r7, #0x10
	asrs r5, r0, #0x10
	adds r0, r5, #0
	ldr r1, [sp, #0x14]
	lsls r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r3, [sp, #0x18]
	adds r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	cmp r4, #0x9f
	bhi _08080E60
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r1, ip
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bgt _08080E18
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r2, r8
	adds r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	b _08080E18
_08080E60:
	ldr r3, [sp, #0x20]
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r3, r5
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08080E72
	b _08080D06
_08080E72:
	movs r0, #0xa0
	ldr r1, _08080EA8 @ =gWindowRegBuffer
	strh r0, [r1, #0xa]
	ldr r2, _08080EAC @ =gIntrManager
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r5, [sp]
	str r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08080EB0 @ =0x04000042
	str r0, [r1]
	adds r3, #8
	adds r1, r2, r3
	ldr r0, _08080EB4 @ =0xA2600001
	str r0, [r1]
_08080E96:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080EA8: .4byte gWindowRegBuffer
_08080EAC: .4byte gIntrManager
_08080EB0: .4byte 0x04000042
_08080EB4: .4byte 0xA2600001

	thumb_func_start nop_08080eb8
nop_08080eb8: @ 0x08080EB8
	bx lr
	.align 2, 0

	thumb_func_start PantheonAquaModObj_Init
PantheonAquaModObj_Init: @ 0x08080EBC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08080F24 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08080F28 @ =0x083680F0
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	beq _08080F16
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08080F2C @ =0x08368000
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08080F30 @ =nop_08080eb8
	str r0, [r4, #0x24]
_08080F16:
	adds r0, r5, #0
	bl PantheonAquaModObj_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08080F24: .4byte gEnemyFnTable
_08080F28: .4byte 0x083680F0
_08080F2C: .4byte 0x08368000
_08080F30: .4byte nop_08080eb8

	thumb_func_start PantheonAquaModObj_Update
PantheonAquaModObj_Update: @ 0x08080F34
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08080F64
	ldr r1, _08080F60 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl PantheonAquaModObj_Die
	b _08080F84
	.align 2, 0
_08080F60: .4byte gEnemyFnTable
_08080F64:
	ldr r1, _08080F8C @ =0x08367FB0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08080F90 @ =0x08367FD8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08080F84:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080F8C: .4byte 0x08367FB0
_08080F90: .4byte 0x08367FD8

	thumb_func_start PantheonAquaModObj_Die
PantheonAquaModObj_Die: @ 0x08080F94
	push {r4, lr}
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
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	ldr r2, _08080FE0 @ =0x083680FA
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b81a0
	ldr r1, _08080FE4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080FE0: .4byte 0x083680FA
_08080FE4: .4byte gEnemyFnTable

	thumb_func_start FUN_08080fe8
FUN_08080fe8: @ 0x08080FE8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08080fec
FUN_08080fec: @ 0x08080FEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0808105C
	cmp r0, #1
	bgt _08081008
	cmp r0, #0
	beq _08081012
	b _080811D4
_08081008:
	cmp r0, #2
	beq _0808109C
	cmp r0, #3
	beq _080810EA
	b _080811D4
_08081012:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	asrs r0, r0, #8
	str r0, [r5, #0x54]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x58]
	asrs r0, r0, #8
	str r0, [r5, #0x58]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r2, #0xd0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r5, #0x58]
	str r1, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808105C:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldr r1, [r5, #0x68]
	str r1, [r5, #0x58]
	ldr r2, _08081098 @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0808108E
	b _080811D4
_0808108E:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080811D4
	.align 2, 0
_08081098: .4byte gSineTable
_0808109C:
	movs r0, #0x29
	bl PlaySound
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	ldr r1, _080811E0 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	movs r3, #0
	bl FUN_080b2b40
	movs r0, #0x28
	str r0, [sp, #8]
	movs r0, #0x30
	str r0, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _080811E4 @ =0x08368100
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b857c
	ldr r1, _080811E8 @ =0x00002709
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080810EA:
	ldr r0, [r5, #0x54]
	adds r0, #8
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, #8
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08081166
	ldr r3, _080811EC @ =RNG_0202f388
	ldr r7, _080811F0 @ =0x000343FD
	ldr r6, _080811F4 @ =0x00269EC3
	add r2, sp, #8
	mov r8, r2
	movs r4, #2
_08081112:
	ldr r1, [r5, #0x54]
	ldr r0, _080811F8 @ =0xFFFFF800
	adds r1, r1, r0
	ldr r0, [r3]
	muls r0, r7, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	adds r1, r1, r0
	str r1, [sp, #8]
	ldr r1, [r5, #0x58]
	ldr r0, _080811FC @ =0xFFFFE000
	adds r1, r1, r0
	adds r0, r2, #0
	muls r0, r7, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsls r0, r0, #2
	lsrs r0, r0, #0x13
	adds r1, r1, r0
	mov r0, r8
	str r1, [r0, #4]
	adds r1, r2, #0
	muls r1, r7, r1
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	add r0, sp, #8
	str r3, [sp, #0x10]
	bl FUN_080ba9f4
	subs r4, #1
	ldr r3, [sp, #0x10]
	cmp r4, #0
	bge _08081112
_08081166:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080811D4
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	ldr r4, _080811F8 @ =0xFFFFF800
	adds r0, r0, r4
	str r0, [sp, #0xc]
	ldr r2, _08081200 @ =0x08368102
	adds r0, r5, #0
	add r1, sp, #8
	movs r3, #4
	bl FUN_080b81a0
	ldr r0, [sp, #0xc]
	adds r0, r0, r4
	str r0, [sp, #0xc]
	movs r0, #1
	add r1, sp, #8
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
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
	ldr r1, _08081204 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080811D4:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080811E0: .4byte 0xFFFFF000
_080811E4: .4byte 0x08368100
_080811E8: .4byte 0x00002709
_080811EC: .4byte RNG_0202f388
_080811F0: .4byte 0x000343FD
_080811F4: .4byte 0x00269EC3
_080811F8: .4byte 0xFFFFF800
_080811FC: .4byte 0xFFFFE000
_08081200: .4byte 0x08368102
_08081204: .4byte gEnemyFnTable

	thumb_func_start FUN_08081208
FUN_08081208: @ 0x08081208
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bls _08081216
	b _08081428
_08081216:
	lsls r0, r0, #2
	ldr r1, _08081220 @ =_08081224
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08081220: .4byte _08081224
_08081224: @ jump table
	.4byte _0808124C @ case 0
	.4byte _08081296 @ case 1
	.4byte _080812D4 @ case 2
	.4byte _080812EE @ case 3
	.4byte _0808132C @ case 4
	.4byte _08081342 @ case 5
	.4byte _08081394 @ case 6
	.4byte _0808139E @ case 7
	.4byte _080813B8 @ case 8
	.4byte _080813C4 @ case 9
_0808124C:
	movs r0, #0x20
	strb r0, [r4, #0x12]
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	asrs r0, r0, #8
	str r0, [r4, #0x54]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xb6
	lsls r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x58]
	asrs r0, r0, #8
	str r0, [r4, #0x58]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r2, #0xe0
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r4, #0x58]
	str r1, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081296:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, [r4, #0x68]
	str r1, [r4, #0x58]
	ldr r2, _080812D0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080812C6
	b _08081428
_080812C6:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08081428
	.align 2, 0
_080812D0: .4byte gSineTable
_080812D4:
	ldr r0, [r4, #0x54]
	ldr r1, _08081324 @ =0xFFFFAC00
	adds r0, r0, r1
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x58]
	ldr r2, _08081328 @ =0xFFFFD000
	adds r0, r0, r2
	str r0, [r4, #0x68]
	movs r0, #0x64
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080812EE:
	ldrb r0, [r4, #0x12]
	subs r6, r0, #1
	strb r6, [r4, #0x12]
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x54]
	subs r1, r1, r2
	ldr r0, [r4, #0x68]
	ldr r5, [r4, #0x58]
	subs r3, r0, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	bge _0808130A
	adds r0, #0xff
_0808130A:
	asrs r0, r0, #8
	adds r0, r2, r0
	str r0, [r4, #0x54]
	adds r0, r3, #0
	cmp r0, #0
	bge _08081318
	adds r0, #0xf
_08081318:
	asrs r0, r0, #4
	adds r0, r5, r0
	str r0, [r4, #0x58]
	lsls r0, r6, #0x18
	b _080813A6
	.align 2, 0
_08081324: .4byte 0xFFFFAC00
_08081328: .4byte 0xFFFFD000
_0808132C:
	adds r2, r5, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xa0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081342:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0808137E
	ldr r2, _08081384 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08081388 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808138C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r2, _08081390 @ =0xFFFFF600
	adds r0, r0, r2
	ldr r2, [r4, #0x54]
	adds r2, r2, r0
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl FUN_080c025c
_0808137E:
	ldrb r0, [r4, #0x12]
	b _080813A6
	.align 2, 0
_08081384: .4byte RNG_0202f388
_08081388: .4byte 0x000343FD
_0808138C: .4byte 0x00269EC3
_08081390: .4byte 0xFFFFF600
_08081394:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808139E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
_080813A6:
	cmp r0, #0
	bne _080813B0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080813B0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08081428
_080813B8:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080813C4:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x60]
	adds r1, #4
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _08081430 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _08081428
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08081434 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08081428:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081430: .4byte gStageRun+232
_08081434: .4byte gEnemyFnTable

	thumb_func_start FUN_08081438
FUN_08081438: @ 0x08081438
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov sb, r0
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _08081456
	ldr r0, _080814A8 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080814B8
_08081456:
	ldr r2, _080814AC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080814B0 @ =0x0000BFFF
	ands r0, r1
	movs r4, #0
	movs r3, #0
	strh r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080814B4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	mov r2, sb
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	b _0808179C
	.align 2, 0
_080814A8: .4byte pZero2
_080814AC: .4byte gWindowRegBuffer
_080814B0: .4byte 0x0000BFFF
_080814B4: .4byte gEnemyFnTable
_080814B8:
	ldrb r0, [r5, #0xe]
	movs r1, #0xb6
	adds r1, r1, r5
	mov r8, r1
	adds r7, r5, #0
	adds r7, #0xb7
	cmp r0, #5
	bls _080814CA
	b _08081756
_080814CA:
	lsls r0, r0, #2
	ldr r1, _080814D4 @ =_080814D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080814D4: .4byte _080814D8
_080814D8: @ jump table
	.4byte _080814F0 @ case 0
	.4byte _080815A0 @ case 1
	.4byte _08081604 @ case 2
	.4byte _08081614 @ case 3
	.4byte _080816B2 @ case 4
	.4byte _080816B8 @ case 5
_080814F0:
	ldrb r0, [r5, #0x11]
	cmp r0, #1
	bne _08081540
	adds r0, r5, #0
	bl FUN_080808b4
	movs r2, #0
	ldr r0, _08081518 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0808150C
	movs r2, #1
_0808150C:
	cmp r2, #0
	beq _0808151C
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08081522
	.align 2, 0
_08081518: .4byte pZero2
_0808151C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08081522:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
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
	b _0808155E
_08081540:
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0808155E:
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080815F4 @ =FUN_08080cbc
	bl SetTaskCallback
	ldrb r1, [r5, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xa]
	str r5, [r5, #0x3c]
	ldr r1, _080815F8 @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x21
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #4
	strb r0, [r1]
	strb r3, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	mov r8, r1
_080815A0:
	ldrb r0, [r5, #0x13]
	lsrs r0, r0, #3
	adds r0, #4
	adds r1, r5, #0
	adds r1, #0xb7
	strb r0, [r1]
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #0x10
	bls _080815C2
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080815C2:
	ldrb r0, [r5, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, _080815FC @ =gPaletteManager
	ldr r3, _08081600 @ =0x0836810A
	lsls r1, r6, #1
	adds r1, r1, r6
	adds r0, r3, #2
	adds r0, r1, r0
	ldrb r2, [r0]
	lsls r2, r2, #0xa
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, r0, #5
	orrs r2, r0
	adds r1, r1, r3
	ldrb r0, [r1]
	orrs r0, r2
	strh r0, [r4]
	b _08081756
	.align 2, 0
_080815F4: .4byte FUN_08080cbc
_080815F8: .4byte gWindowRegBuffer
_080815FC: .4byte gPaletteManager
_08081600: .4byte 0x0836810A
_08081604:
	adds r1, r5, #0
	adds r1, #0xb6
	ldrb r0, [r1]
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	mov r8, r1
_08081614:
	ldrb r0, [r5, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, _0808169C @ =gPaletteManager
	ldr r3, _080816A0 @ =0x0836810A
	lsls r1, r6, #1
	adds r1, r1, r6
	adds r0, r3, #2
	adds r0, r1, r0
	ldrb r2, [r0]
	lsls r2, r2, #0xa
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, r0, #5
	orrs r2, r0
	adds r1, r1, r3
	ldrb r0, [r1]
	orrs r0, r2
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0xb7
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #0x18
	bls _08081662
	mov r0, sb
	adds r0, #0xb4
	ldr r1, [r0]
	movs r2, #2
	orrs r1, r2
	str r1, [r0]
_08081662:
	ldrb r1, [r7]
	ldrb r0, [r5, #0x12]
	subs r2, r1, r0
	cmp r2, #3
	ble _08081670
	subs r0, r1, #3
	strb r0, [r5, #0x12]
_08081670:
	ldrb r4, [r7]
	mov r0, r8
	strb r4, [r0]
	adds r0, r6, #1
	muls r0, r2, r0
	movs r1, #3
	bl __divsi3
	subs r4, r4, r0
	mov r1, r8
	strb r4, [r1]
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080816A4
	ldrb r0, [r7]
	cmp r0, #0x20
	bls _08081756
	b _080816AA
	.align 2, 0
_0808169C: .4byte gPaletteManager
_080816A0: .4byte 0x0836810A
_080816A4:
	ldrb r0, [r7]
	cmp r0, #0x78
	bls _08081756
_080816AA:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08081756
_080816B2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080816B8:
	adds r0, r5, #0
	adds r0, #0xb6
	ldrb r1, [r0]
	adds r1, #1
	movs r4, #0
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb7
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r0
	adds r7, r2, #0
	ldrb r3, [r7]
	cmp r1, r3
	blo _08081722
	mov r2, sb
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	ldr r2, _08081770 @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _08081774 @ =0x0000BFFF
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08081778 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_08081722:
	ldrb r0, [r5, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, _0808177C @ =gPaletteManager
	ldr r3, _08081780 @ =0x0836810A
	lsls r1, r6, #1
	adds r1, r1, r6
	adds r0, r3, #2
	adds r0, r1, r0
	ldrb r2, [r0]
	lsls r2, r2, #0xa
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, r0, #5
	orrs r2, r0
	adds r1, r1, r3
	ldrb r0, [r1]
	orrs r0, r2
	strh r0, [r4]
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
_08081756:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08081784
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r0, #0xb4
	strb r1, [r0]
	ldrb r1, [r7]
	adds r0, #1
	b _0808179A
	.align 2, 0
_08081770: .4byte gWindowRegBuffer
_08081774: .4byte 0x0000BFFF
_08081778: .4byte gEnemyFnTable
_0808177C: .4byte gPaletteManager
_08081780: .4byte 0x0836810A
_08081784:
	mov r1, r8
	ldrb r0, [r1]
	movs r1, #0x80
	subs r0, r1, r0
	adds r2, r5, #0
	adds r2, #0xb5
	strb r0, [r2]
	ldrb r0, [r7]
	subs r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xb4
_0808179A:
	strb r1, [r0]
_0808179C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080817a8
FUN_080817a8: @ 0x080817A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bne _080817F4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080817F0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080818A0
	.align 2, 0
_080817F0: .4byte gEnemyFnTable
_080817F4:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08081800
	cmp r0, #1
	beq _08081818
	b _080818A0
_08081800:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080818AC @ =0x08368018
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081818:
	ldr r0, _080818B0 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	ldr r6, [r5, #0x54]
	subs r3, r0, r6
	ldr r0, [r5, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	mov ip, r1
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r0, #1
	ldrb r0, [r0]
	adds r1, r1, r0
	lsrs r1, r1, #1
	ldr r2, _080818B4 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	mov r8, r0
	movs r7, #0
	ldrsh r0, [r0, r7]
	mov r8, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r2, [r1, r0]
	mov r0, r8
	muls r0, r3, r0
	cmp r0, #0
	bge _08081864
	adds r0, #0xff
_08081864:
	asrs r3, r0, #8
	mov r0, ip
	muls r0, r2, r0
	cmp r0, #0
	bge _08081870
	adds r0, #0xff
_08081870:
	asrs r0, r0, #8
	adds r3, r3, r0
	cmp r3, #0
	bge _0808187A
	movs r3, #0
_0808187A:
	str r6, [r4, #0x54]
	mov r0, r8
	muls r0, r3, r0
	cmp r0, #0
	bge _08081886
	adds r0, #0xff
_08081886:
	asrs r0, r0, #8
	adds r0, r6, r0
	str r0, [r4, #0x54]
	ldr r1, [r5, #0x58]
	str r1, [r4, #0x58]
	adds r0, r2, #0
	muls r0, r3, r0
	cmp r0, #0
	bge _0808189A
	adds r0, #0xff
_0808189A:
	asrs r0, r0, #8
	adds r0, r1, r0
	str r0, [r4, #0x58]
_080818A0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080818AC: .4byte 0x08368018
_080818B0: .4byte pZero2
_080818B4: .4byte gSineTable

	thumb_func_start FUN_080818b8
FUN_080818b8: @ 0x080818B8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bhi _080818CC
	ldr r7, [r6, #0x2c]
	ldrb r0, [r7, #0xc]
	cmp r0, #4
	bne _08081908
_080818CC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08081904 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _0808197C
	.align 2, 0
_08081904: .4byte gEnemyFnTable
_08081908:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08081914
	cmp r0, #1
	beq _08081936
	b _0808197C
_08081914:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldrb r1, [r6, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _08081984 @ =0x00004D04
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08081936:
	ldrb r1, [r6, #0x11]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xb
	ldr r1, _08081988 @ =0xFFFFEC00
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	ldr r4, [r7, #0x54]
	subs r1, r1, r4
	ldr r5, [r5, #0x58]
	ldr r0, _0808198C @ =0xFFFFFB00
	adds r5, r5, r0
	ldr r0, [r7, #0x58]
	subs r5, r5, r0
	str r4, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	muls r0, r1, r0
	movs r1, #6
	bl __divsi3
	adds r4, r4, r0
	str r4, [r6, #0x54]
	ldr r4, [r7, #0x58]
	str r4, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	muls r0, r5, r0
	movs r1, #6
	bl __divsi3
	adds r4, r4, r0
	str r4, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0808197C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081984: .4byte 0x00004D04
_08081988: .4byte 0xFFFFEC00
_0808198C: .4byte 0xFFFFFB00

	thumb_func_start FUN_08081990
FUN_08081990: @ 0x08081990
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080819B4
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	b _08081C08
_080819B4:
	ldrb r0, [r5, #0xe]
	adds r4, r5, #0
	adds r4, #0x8c
	cmp r0, #7
	bls _080819C0
	b _08081C3A
_080819C0:
	lsls r0, r0, #2
	ldr r1, _080819CC @ =_080819D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080819CC: .4byte _080819D0
_080819D0: @ jump table
	.4byte _080819F0 @ case 0
	.4byte _08081AC8 @ case 1
	.4byte _08081B1C @ case 2
	.4byte _08081B26 @ case 3
	.4byte _08081B44 @ case 4
	.4byte _08081B6A @ case 5
	.4byte _08081BAE @ case 6
	.4byte _08081BBE @ case 7
_080819F0:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08081A6C @ =0x08368030
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0xe
	strb r0, [r1]
	ldrb r1, [r5, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldrb r0, [r6, #0x1c]
	strb r0, [r5, #0x1d]
	str r2, [r5, #0x68]
	ldr r0, [r5, #0x54]
	ldr r1, _08081A70 @ =pZero2
	ldr r3, [r1]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r4, #0xc0
	lsls r4, r4, #5
	adds r2, r1, r4
	ldr r1, [r3, #0x58]
	subs r1, r2, r1
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _08081A78
	adds r0, r4, #0
	subs r0, #0x48
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x40
	bls _08081A5A
	movs r0, #0
	cmp r4, #0x9f
	bhi _08081A58
	movs r0, #0x40
_08081A58:
	adds r4, r0, #0
_08081A5A:
	adds r0, r4, #0
	adds r0, #0x48
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _08081A74 @ =0x00004D05
	adds r0, r5, #0
	bl SetMotion
	b _08081A9E
	.align 2, 0
_08081A6C: .4byte 0x08368030
_08081A70: .4byte pZero2
_08081A74: .4byte 0x00004D05
_08081A78:
	adds r0, r4, #0
	adds r0, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x40
	bls _08081A8E
	movs r0, #0
	cmp r4, #0x9f
	bhi _08081A8C
	movs r0, #0x40
_08081A8C:
	adds r4, r0, #0
_08081A8E:
	adds r0, r4, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _08081AE4 @ =0x00004D0A
	adds r0, r5, #0
	bl SetMotion
_08081A9E:
	ldr r1, _08081AE8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #2
	str r0, [r5, #0x60]
	movs r0, #0
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08081AC8:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #4
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _08081AEC
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08081C3A
	.align 2, 0
_08081AE4: .4byte 0x00004D0A
_08081AE8: .4byte gSineTable
_08081AEC:
	ldr r0, [r5, #0x64]
	adds r0, #1
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r0, r0, r3
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	lsls r3, r3, #2
	adds r0, r0, r3
	lsls r2, r2, #2
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08081BA6
_08081B14:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08081BA6
_08081B1C:
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08081B26:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08081B38
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08081B38:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r4, r5, #0
	adds r4, #0x8c
	b _08081C3A
_08081B44:
	ldr r0, [r5, #0x5c]
	movs r4, #3
	rsbs r4, r4, #0
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x60]
	ldr r1, [r5, #0x64]
	lsls r0, r1, #1
	adds r0, r0, r1
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08081B6A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x64]
	subs r0, #1
	str r0, [r5, #0x64]
	adds r4, r5, #0
	adds r4, #0x8c
	cmp r0, #7
	bgt _08081BA6
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08081B14
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _08081BE8
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0]
	movs r2, #0x81
	rsbs r2, r2, #0
	b _08081BF0
_08081BA6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08081C3A
_08081BAE:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08081BE4 @ =0x083680D8
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08081BBE:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #4
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	bne _08081C34
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _08081BE8
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0]
	movs r2, #0x81
	rsbs r2, r2, #0
	b _08081BF0
	.align 2, 0
_08081BE4: .4byte 0x083680D8
_08081BE8:
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r2, _08081C2C @ =0xFFFFFEFF
_08081BF0:
	ands r1, r2
	str r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r2, [r4]
	adds r0, r5, #0
	adds r0, #0x90
_08081C08:
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08081C30 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _08081D22
	.align 2, 0
_08081C2C: .4byte 0xFFFFFEFF
_08081C30: .4byte gEnemyFnTable
_08081C34:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08081C3A:
	ldr r0, [r5, #0x68]
	cmp r0, #0
	beq _08081CB4
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	bne _08081C8C
	str r1, [r5, #0x68]
	str r1, [r4]
	adds r0, r5, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _08081C78
	ldr r1, _08081C74 @ =0x00004D05
	adds r0, r5, #0
	bl SetMotion
	b _08081C80
	.align 2, 0
_08081C74: .4byte 0x00004D05
_08081C78:
	ldr r1, _08081C88 @ =0x00004D0A
	adds r0, r5, #0
	bl SetMotion
_08081C80:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08081D22
	.align 2, 0
_08081C88: .4byte 0x00004D0A
_08081C8C:
	ldr r0, _08081CB0 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r5, #0x54]
	str r0, [r2, #0x54]
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r2, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r2, #0x58]
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	b _08081D22
	.align 2, 0
_08081CB0: .4byte pZero2
_08081CB4:
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08081D22
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08081D08 @ =0x08368060
	bl SetDDP
	adds r2, r6, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r2]
	movs r0, #1
	str r0, [r5, #0x68]
	adds r2, r5, #0
	adds r2, #0xb8
	ldr r0, _08081D0C @ =pZero2
	ldr r3, [r0]
	ldr r0, [r3, #0x54]
	str r0, [r2]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r2]
	adds r2, #4
	ldr r0, [r3, #0x58]
	str r0, [r2]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	str r0, [r2]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _08081D14
	ldr r1, _08081D10 @ =0x00004D06
	adds r0, r5, #0
	bl SetMotion
	b _08081D1C
	.align 2, 0
_08081D08: .4byte 0x08368060
_08081D0C: .4byte pZero2
_08081D10: .4byte 0x00004D06
_08081D14:
	ldr r1, _08081D28 @ =0x00004D0B
	adds r0, r5, #0
	bl SetMotion
_08081D1C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08081D22:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081D28: .4byte 0x00004D0B

	thumb_func_start FUN_08081d2c
FUN_08081d2c: @ 0x08081D2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08081D3E
	cmp r5, #1
	beq _08081D78
	b _08081DF4
_08081D3E:
	movs r0, #0x49
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xe
	strb r0, [r1]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x55
	bl LoadBlink
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081D78:
	ldrb r1, [r4, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	bne _08081D8C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _08081D92
_08081D8C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
_08081D92:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	movs r5, #0
	strb r0, [r4, #0x12]
	movs r0, #0x55
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08081DBA
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _08081DF4
_08081DBA:
	movs r0, #0x55
	bl ClearBlink
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08081DFC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08081DF4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081DFC: .4byte gEnemyFnTable

	thumb_func_start FUN_08081e00
FUN_08081e00: @ 0x08081E00
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _08081E0E
	b _08081F80
_08081E0E:
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08081E16
	b _08081FB6
_08081E16:
	lsls r0, r0, #2
	ldr r1, _08081E20 @ =_08081E24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08081E20: .4byte _08081E24
_08081E24: @ jump table
	.4byte _08081E3C @ case 0
	.4byte _08081E98 @ case 1
	.4byte _08081EC8 @ case 2
	.4byte _08081EF8 @ case 3
	.4byte _08081F1C @ case 4
	.4byte _08081F3E @ case 5
_08081E3C:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08081E6C @ =0x083680C0
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xe
	strb r0, [r1]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08081E74
	ldr r1, _08081E70 @ =0x00004D05
	adds r0, r4, #0
	bl SetMotion
	b _08081E7C
	.align 2, 0
_08081E6C: .4byte 0x083680C0
_08081E70: .4byte 0x00004D05
_08081E74:
	ldr r1, _08081EBC @ =0x00004D0A
	adds r0, r4, #0
	bl SetMotion
_08081E7C:
	ldrb r1, [r4, #0x11]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #9
	ldr r1, _08081EC0 @ =0xFFFFFD00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _08081EC4 @ =0xFFFFFF00
	str r0, [r4, #0x60]
	movs r0, #0
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081E98:
	ldr r0, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x54]
	ldr r3, [r4, #0x5c]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	lsls r3, r3, #1
	adds r0, r0, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	b _08081F04
	.align 2, 0
_08081EBC: .4byte 0x00004D0A
_08081EC0: .4byte 0xFFFFFD00
_08081EC4: .4byte 0xFFFFFF00
_08081EC8:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08081EDC
	ldr r1, _08081ED8 @ =0x00004D0C
	adds r0, r4, #0
	bl SetMotion
	b _08081EE4
	.align 2, 0
_08081ED8: .4byte 0x00004D0C
_08081EDC:
	ldr r1, _08081F18 @ =0x00004D0D
	adds r0, r4, #0
	bl SetMotion
_08081EE4:
	adds r2, r5, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081EF8:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
_08081F04:
	cmp r0, #0
	beq _08081F0E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081F0E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08081FB6
	.align 2, 0
_08081F18: .4byte 0x00004D0D
_08081F1C:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08081F30
	ldr r1, _08081F2C @ =0x00004D05
	adds r0, r4, #0
	bl SetMotion
	b _08081F38
	.align 2, 0
_08081F2C: .4byte 0x00004D05
_08081F30:
	ldr r1, _08081F70 @ =0x00004D0A
	adds r0, r4, #0
	bl SetMotion
_08081F38:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08081F3E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0
	bne _08081FB6
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08081F74
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r0]
	movs r2, #0x81
	rsbs r2, r2, #0
	b _08081F7C
	.align 2, 0
_08081F70: .4byte 0x00004D0A
_08081F74:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r2, _08081FBC @ =0xFFFFFEFF
_08081F7C:
	ands r1, r2
	str r1, [r0]
_08081F80:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08081FC0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08081FB6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081FBC: .4byte 0xFFFFFEFF
_08081FC0: .4byte gEnemyFnTable

	thumb_func_start FUN_08081fc4
FUN_08081fc4: @ 0x08081FC4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08081FD4
	cmp r5, #1
	beq _08082006
	b _080820AC
_08081FD4:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08082064 @ =0x08368090
	bl SetDDP
	strb r5, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldr r0, _08082068 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _0808206C @ =0xFFFF9000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
	movs r1, #0x9e
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08082006:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0808203A
	ldr r2, _08082070 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08082074 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _08082078 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsls r1, r1, #3
	lsrs r1, r1, #0x14
	ldr r2, _0808207C @ =0xFFFFF800
	adds r1, r1, r2
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_080c02f4
_0808203A:
	ldr r0, [r4, #0x60]
	adds r0, #0x15
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808204A
	str r1, [r4, #0x60]
_0808204A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1d
	bhi _08082080
	adds r0, #1
	strb r0, [r4, #0x12]
	b _080820AC
	.align 2, 0
_08082064: .4byte 0x08368090
_08082068: .4byte gStageRun+232
_0808206C: .4byte 0xFFFF9000
_08082070: .4byte RNG_0202f388
_08082074: .4byte 0x000343FD
_08082078: .4byte 0x00269EC3
_0808207C: .4byte 0xFFFFF800
_08082080:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080820AC
	movs r0, #0xe2
	bl PlaySound
	ldr r1, _080820B4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080820AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080820B4: .4byte gEnemyFnTable

	thumb_func_start FUN_080820b8
FUN_080820b8: @ 0x080820B8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080820CA
	cmp r0, #1
	beq _08082104
	b _08082180
_080820CA:
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1b
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r1, _08082188 @ =0x0000270B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08082104:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08082118
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_080ba9a0
_08082118:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	movs r5, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _0808218C @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _08082180
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08082190 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08082180:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082188: .4byte 0x0000270B
_0808218C: .4byte gStageRun+232
_08082190: .4byte gEnemyFnTable
