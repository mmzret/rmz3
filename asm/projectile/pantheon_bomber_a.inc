	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonBombProjectile_Init
PantheonBombProjectile_Init: @ 0x080AD0BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r6, [r7, #0x11]
	cmp r6, #0
	bne _080AD118
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080AD110 @ =0x0836C84C
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080AD114 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r6, [r7, #0xe]
	strb r6, [r7, #0xf]
	b _080AD17A
	.align 2, 0
_080AD110: .4byte 0x0836C84C
_080AD114: .4byte gProjectileFnTable
_080AD118:
	cmp r6, #1
	bne _080AD17A
	adds r0, r7, #0
	bl InitScalerotMotion1
	adds r1, r7, #0
	adds r1, #0x50
	movs r5, #0
	movs r0, #0
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x24
	strb r5, [r0]
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080AD190 @ =0x0836C84C
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r7, [r4, #0x2c]
	mov r0, r8
	str r0, [r4, #0x24]
	ldr r1, _080AD194 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
_080AD17A:
	movs r0, #0xff
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	bl PantheonBombProjectile_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD190: .4byte 0x0836C84C
_080AD194: .4byte gProjectileFnTable

	thumb_func_start PantheonBombProjectile_Update
PantheonBombProjectile_Update: @ 0x080AD198
	push {lr}
	adds r2, r0, #0
	ldr r0, _080AD1E4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080AD1EC
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080AD1E8 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl PantheonBombProjectile_Die
	b _080AD1FC
	.align 2, 0
_080AD1E4: .4byte gCurStory
_080AD1E8: .4byte gProjectileFnTable
_080AD1EC:
	ldr r0, _080AD200 @ =0x0836C844
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080AD1FC:
	pop {r0}
	bx r0
	.align 2, 0
_080AD200: .4byte 0x0836C844

