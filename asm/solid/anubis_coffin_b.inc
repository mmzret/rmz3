	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start AnubisCoffin_Init
AnubisCoffin_Init: @ 0x080CDE70
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080CDED8 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080CDEDC @ =0x08370240
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080CDEE0 @ =0x08370208
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080CDEE4 @ =nop_080cde6c
	str r0, [r5, #0x24]
	adds r0, r4, #0
	adds r0, #0xbc
	strb r6, [r0]
	adds r0, r4, #0
	bl AnubisCoffin_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CDED8: .4byte gSolidFnTable
_080CDEDC: .4byte 0x08370240
_080CDEE0: .4byte 0x08370208
_080CDEE4: .4byte nop_080cde6c

	thumb_func_start AnubisCoffin_Update
AnubisCoffin_Update: @ 0x080CDEE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080CDF14 @ =0x083701F0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080CDF18 @ =0x083701FC
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
_080CDF14: .4byte 0x083701F0
_080CDF18: .4byte 0x083701FC

	thumb_func_start AnubisCoffin_Die
AnubisCoffin_Die: @ 0x080CDF1C
	ldr r2, _080CDF30 @ =gSolidFnTable
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
_080CDF30: .4byte gSolidFnTable
