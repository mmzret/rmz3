	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807dee8
FUN_0807dee8: @ 0x0807DEE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807DEF8
	cmp r0, #1
	beq _0807DF2C
	b _0807DF90
_0807DEF8:
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r2, [r0]
	ldr r3, _0807DF98 @ =0x08367D5A
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r0, r0, r3
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r3, #3
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807DF2C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0807DF8A
	ldr r0, _0807DF9C @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0807DF8A
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
	ldr r1, _0807DFA0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0807DF8A:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0807DF90:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807DF98: .4byte sMotions+(10*2)
_0807DF9C: .4byte gStageRun+232
_0807DFA0: .4byte gEnemyFnTable

	thumb_func_start FUN_0807dfa4
FUN_0807dfa4: @ 0x0807DFA4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	movs r1, #0
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
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0807DFF4
	ldr r2, _0807DFF0 @ =0x08367D5E
	adds r0, r5, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	b _0807E000
	.align 2, 0
_0807DFF0: .4byte sMotions+(12*2)
_0807DFF4:
	ldr r2, _0807E014 @ =0x08367D5E
	adds r0, r5, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
_0807E000:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0807E018
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
	b _0807E024
	.align 2, 0
_0807E014: .4byte sMotions+(12*2)
_0807E018:
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
_0807E024:
	adds r1, r4, #0
	ldr r3, _0807E054 @ =gScore
	ldrh r2, [r3, #0xc]
	ldr r0, _0807E058 @ =0x0000270E
	cmp r2, r0
	bhi _0807E034
	adds r0, r2, #1
	strh r0, [r3, #0xc]
_0807E034:
	adds r0, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0807E05C @ =gEnemyFnTable
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
_0807E054: .4byte gScore
_0807E058: .4byte 0x0000270E
_0807E05C: .4byte gEnemyFnTable

	thumb_func_start FUN_0807e060
FUN_0807e060: @ 0x0807E060
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807E072
	cmp r5, #1
	beq _0807E126
	b _0807E16C
_0807E072:
	movs r6, #0
	ldr r0, _0807E0EC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0807E084
	movs r6, #1
_0807E084:
	lsls r0, r6, #8
	subs r0, r1, r0
	str r0, [r4, #0x54]
	ldr r1, _0807E0F0 @ =0x00004705
	adds r0, r4, #0
	bl SetMotion
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
	ldr r0, [r4, #0x54]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
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
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0807E0F8
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _0807E0F4 @ =0x08367D64
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b84f4
	b _0807E10E
	.align 2, 0
_0807E0EC: .4byte pZero2
_0807E0F0: .4byte 0x00004705
_0807E0F4: .4byte sMotions+(15*2)
_0807E0F8:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _0807E174 @ =0x08367D64
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b857c
_0807E10E:
	ldr r0, [sp, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807E126:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807E13E
	str r1, [r4, #0x60]
_0807E13E:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807E166
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807E16C
_0807E166:
	adds r0, r4, #0
	bl FUN_0807dfa4
_0807E16C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807E174: .4byte sMotions+(15*2)

	thumb_func_start FUN_0807e178
FUN_0807e178: @ 0x0807E178
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0807E188
	cmp r0, #1
	beq _0807E236
	b _0807E276
_0807E188:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E218 @ =0x08367D24
	bl SetDDP
	ldr r2, _0807E21C @ =0x08367D66
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _0807E220 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _0807E224 @ =0xFFFFE800
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
	beq _0807E228
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
	b _0807E230
	.align 2, 0
_0807E218: .4byte sCollisions+(3*24)
_0807E21C: .4byte sMotions+(16*2)
_0807E220: .4byte pZero2
_0807E224: .4byte 0xFFFFE800
_0807E228:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0807E230:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E236:
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
	ble _0807E24E
	str r1, [r5, #0x60]
_0807E24E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807E270
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807E276
_0807E270:
	adds r0, r5, #0
	bl FUN_0807dfa4
_0807E276:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
