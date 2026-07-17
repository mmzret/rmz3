	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start OmegaGoldProjectile_Init
OmegaGoldProjectile_Init: @ 0x080AC448
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r5, [r6, #0x10]
	cmp r5, #0
	bne _080AC4A0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AC498 @ =0x0836C644
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x25
	strb r5, [r0]
	ldr r1, _080AC49C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	b _080AC4E8
	.align 2, 0
_080AC498: .4byte 0x0836C644
_080AC49C: .4byte gProjectileFnTable
_080AC4A0:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AC4FC @ =0x0836C614
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080AC500 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080AC504 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #2
	strb r0, [r6, #0xd]
_080AC4E8:
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl OmegaGoldProjectile_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AC4FC: .4byte 0x0836C614
_080AC500: .4byte 0xFFFFFF00
_080AC504: .4byte gProjectileFnTable

