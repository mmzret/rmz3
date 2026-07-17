	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start EyeCannon_Init
EyeCannon_Init: @ 0x080847F0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r5, _08084864 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r3, #1
	str r3, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r4, #0
	strb r3, [r6, #0xd]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	beq _08084870
	ldr r1, _08084868 @ =gCurStory
	ldr r2, _0808486C @ =0x08368358
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	lsrs r0, r2, #3
	adds r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #7
	ands r2, r1
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _08084870
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080848BA
	.align 2, 0
_08084864: .4byte gEnemyFnTable
_08084868: .4byte gCurStory
_0808486C: .4byte 0x08368358
_08084870:
	ldrb r1, [r6, #0xa]
	movs r0, #2
	movs r5, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080848C0 @ =0x08368310
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #7
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _080848C4 @ =0x08084705
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb4
	str r5, [r0]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl EyeCannon_Update
_080848BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080848C0: .4byte 0x08368310
_080848C4: .4byte 0x08084705

