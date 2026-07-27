	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
