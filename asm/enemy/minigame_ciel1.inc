	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809bdd4
FUN_0809bdd4: @ 0x0809BDD4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809BE2C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BE24
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809BE30 @ =gEnemyFnTable
	movs r1, #0x46
	strb r1, [r3, #9]
	adds r1, #0xd2
	adds r0, r0, r1
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
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_0809BE24:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809BE2C: .4byte gZakoHeaderPtr
_0809BE30: .4byte gEnemyFnTable

	thumb_func_start CielMinigameEnemy_Init
CielMinigameEnemy_Init: @ 0x0809BE34
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, _0809BEC4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xe9
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #5
	adds r0, #0x18
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	str r2, [r4, #0x58]
	movs r0, #0xe1
	lsls r0, r0, #4
	adds r5, r5, r0
	ldrh r0, [r5]
	str r0, [r4, #0x60]
	ldrh r0, [r5]
	str r0, [r4, #0x5c]
	strb r2, [r4, #0x13]
	adds r0, r4, #0
	bl CielMinigameEnemy_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809BEC4: .4byte gEnemyFnTable

	thumb_func_start CielMinigameEnemy_Update
CielMinigameEnemy_Update: @ 0x0809BEC8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x58]
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bls _0809BEE4
	b _0809C06A
_0809BEE4:
	lsls r0, r0, #2
	ldr r1, _0809BEF0 @ =_0809BEF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809BEF0: .4byte _0809BEF4
_0809BEF4: @ jump table
	.4byte _0809BF08 @ case 0
	.4byte _0809BF2C @ case 1
	.4byte _0809BF46 @ case 2
	.4byte _0809BF62 @ case 3
	.4byte _0809BFE4 @ case 4
_0809BF08:
	ldr r0, [r4, #0x58]
	adds r0, #0x80
	str r0, [r4, #0x58]
	ldr r1, _0809BF28 @ =0x000006FF
	cmp r0, r1
	bgt _0809BF16
	b _0809C06A
_0809BF16:
	movs r0, #0xe0
	lsls r0, r0, #3
	str r0, [r4, #0x58]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
	.align 2, 0
_0809BF28: .4byte 0x000006FF
_0809BF2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0809BF3C
	b _0809C06A
_0809BF3C:
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
_0809BF46:
	ldr r0, [r4, #0x58]
	adds r0, #0x20
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0809BF5C
	b _0809C06A
_0809BF5C:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
_0809BF62:
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r5, r0, r2
	str r5, [r4, #0x58]
	ldr r1, _0809BFC0 @ =0x00000DCC
	adds r0, r7, r1
	ldrb r0, [r0, #4]
	adds r3, r2, #0
	cmp r0, #3
	bhi _0809BF9A
	ldr r6, _0809BFC4 @ =gJoypad
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809BF88
	adds r0, r5, r3
	str r0, [r4, #0x58]
_0809BF88:
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809BF9A
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
_0809BF9A:
	adds r0, r4, #0
	bl FUN_0809c110
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0809C06A
	cmp r0, #1
	bne _0809BFC8
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r0]
	ldr r0, [r4, #0x60]
	b _0809BFD8
	.align 2, 0
_0809BFC0: .4byte 0x00000DCC
_0809BFC4: .4byte gJoypad
_0809BFC8:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r4, #0x54]
	ldr r3, _0809BFE0 @ =0xFFFFE000
	adds r1, r1, r3
	str r1, [r0]
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
_0809BFD8:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
	.align 2, 0
_0809BFE0: .4byte 0xFFFFE000
_0809BFE4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r3, r0, r1
	str r3, [r4, #0x54]
	ldr r5, _0809C038 @ =0x00000DCC
	adds r0, r7, r5
	ldrb r0, [r0, #4]
	adds r2, r1, #0
	cmp r0, #3
	bhi _0809C01C
	ldr r5, _0809C03C @ =gJoypad
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809C00A
	adds r0, r3, r2
	str r0, [r4, #0x54]
_0809C00A:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809C01C
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_0809C01C:
	cmp r2, #0
	ble _0809C044
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r4, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	ble _0809C06A
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r3, _0809C040 @ =0x00000E04
	adds r1, r7, r3
	b _0809C058
	.align 2, 0
_0809C038: .4byte 0x00000DCC
_0809C03C: .4byte gJoypad
_0809C040: .4byte 0x00000E04
_0809C044:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r4, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	bge _0809C06A
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r5, _0809C0BC @ =0x00000E04
	adds r1, r7, r5
_0809C058:
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	str r0, [r4, #0x54]
	movs r0, #3
_0809C068:
	strb r0, [r4, #0xd]
_0809C06A:
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	ble _0809C0E8
	ldr r0, _0809C0C0 @ =0x00000DCC
	adds r3, r7, r0
	ldrb r0, [r3, #4]
	cmp r0, #3
	bhi _0809C0D6
	ldr r0, [r4, #0x54]
	asrs r1, r0, #8
	adds r2, r1, #0
	subs r2, #0x18
	adds r0, r2, #0
	cmp r2, #0
	bge _0809C08E
	adds r0, r1, #7
_0809C08E:
	asrs r1, r0, #5
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldrb r5, [r4, #0x11]
	cmp r0, r5
	bne _0809C0CC
	ldr r2, _0809C0C4 @ =0x00000DE9
	adds r0, r7, r2
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r3, #4]
	cmp r0, #3
	bhi _0809C0D6
	ldr r0, [r3, #8]
	adds r0, #0xa
	str r0, [r3, #8]
	ldr r1, _0809C0C8 @ =0x0001869F
	cmp r0, r1
	bls _0809C0D6
	str r1, [r3, #8]
	b _0809C0D6
	.align 2, 0
_0809C0BC: .4byte 0x00000E04
_0809C0C0: .4byte 0x00000DCC
_0809C0C4: .4byte 0x00000DE9
_0809C0C8: .4byte 0x0001869F
_0809C0CC:
	ldr r3, _0809C0F0 @ =0x00000E13
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0809C0D6:
	ldr r1, _0809C0F4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809C0E8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809C0F0: .4byte 0x00000E13
_0809C0F4: .4byte gEnemyFnTable

	thumb_func_start CielMinigameEnemy_Die
CielMinigameEnemy_Die: @ 0x0809C0F8
	ldr r2, _0809C10C @ =gEnemyFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0809C10C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c110
FUN_0809c110: @ 0x0809C110
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r5, [r0, #0x28]
	ldr r0, [r0, #0x54]
	asrs r1, r0, #8
	adds r0, r1, #0
	subs r0, #0x18
	cmp r0, #0
	bge _0809C12C
	adds r0, r1, #7
_0809C12C:
	asrs r0, r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0
	ldr r1, _0809C1A4 @ =0x0836A85C
	mov r8, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r6, r1, #1
	ldr r2, _0809C1A8 @ =0x0836A87A
	mov sb, r2
	lsls r1, r0, #2
	adds r1, r1, r0
	mov sl, r1
_0809C148:
	adds r0, r4, r6
	mov r7, r8
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0809C1BA
	ldrb r2, [r1]
	lsrs r0, r2, #1
	lsls r0, r0, #0xc
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r3, r0, r1
	lsls r1, r2, #1
	movs r7, #0xdf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0xff
	beq _0809C1B0
	mov r0, ip
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, r3
	bge _0809C1B0
	mov r1, ip
	ldr r0, [r1, #0x58]
	cmp r0, r3
	blt _0809C1B0
	mov r0, ip
	adds r0, #0xbc
	strb r2, [r0]
	ldr r2, _0809C1AC @ =0x00000E04
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r7, ip
	str r3, [r7, #0x58]
	mov r1, sl
	adds r0, r4, r1
	add r0, sb
	ldrb r0, [r0]
	b _0809C1BC
	.align 2, 0
_0809C1A4: .4byte 0x0836A85C
_0809C1A8: .4byte 0x0836A87A
_0809C1AC: .4byte 0x00000E04
_0809C1B0:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _0809C148
_0809C1BA:
	movs r0, #0
_0809C1BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
