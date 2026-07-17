	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonHunter_Die
PantheonHunter_Die: @ 0x08064ACC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _08064B5E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08064AFC
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #0
	beq _08064B04
_08064AFC:
	strb r5, [r4, #0xd]
	adds r5, r4, #0
	adds r5, #0x8c
	b _08064B42
_08064B04:
	adds r1, r4, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	adds r5, r1, #0
	cmp r2, #0
	beq _08064B40
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08064B3C @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r3, [r0]
	movs r0, #0
	mov r1, sp
	bl FUN_080b2b40
	movs r0, #1
	strb r0, [r4, #0xd]
	b _08064B42
	.align 2, 0
_08064B3C: .4byte 0xFFFFEC00
_08064B40:
	strb r2, [r4, #0xd]
_08064B42:
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064B5E:
	ldr r0, _08064BA4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08064BAC
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
	ldr r1, _08064BA8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08064BBC
	.align 2, 0
_08064BA4: .4byte gCurStory
_08064BA8: .4byte gEnemyFnTable
_08064BAC:
	ldr r0, _08064BC4 @ =sDeads
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08064BBC:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08064BC4: .4byte sDeads

	thumb_func_start phunter_08064bc8
phunter_08064bc8: @ 0x08064BC8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	bls _08064C08
	cmp r0, #0xc
	beq _08064C08
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08064C04
	ldr r1, [r4, #0x58]
	ldr r0, _08064C00 @ =0xFFFFF000
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _08064C08
	.align 2, 0
_08064C00: .4byte 0xFFFFF000
_08064C04:
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08064C08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

