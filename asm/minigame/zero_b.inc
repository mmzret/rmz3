	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start zeroMinigamePhase2
zeroMinigamePhase2: @ 0x080F9750
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080F976C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080F97EC
	lsls r0, r0, #2
	ldr r1, _080F9770 @ =_080F9774
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F976C: .4byte 0x00000DCC
_080F9770: .4byte _080F9774
_080F9774: @ jump table
	.4byte _080F978C @ case 0
	.4byte _080F9796 @ case 1
	.4byte _080F97A4 @ case 2
	.4byte _080F97B8 @ case 3
	.4byte _080F97C8 @ case 4
	.4byte _080F97D4 @ case 5
_080F978C:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F9796:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080F97EC
	b _080F97C0
_080F97A4:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xad
	bl FadeOutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F97B8:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080F97EC
_080F97C0:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080F97EC
_080F97C8:
	ldr r1, _080F97E8 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080F97D4:
	ldr r0, _080F97E8 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080F97EC
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080F9838
	.align 2, 0
_080F97E8: .4byte gGameState
_080F97EC:
	ldr r1, _080F9840 @ =0x0810E248
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl PrintJISString
	ldrh r4, [r5, #0x38]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl PrintMinigameNumber
	ldr r0, [r5, #0x3c]
	cmp r4, r0
	bls _080F9814
	str r4, [r5, #0x3c]
_080F9814:
	add r4, sp, #8
	ldr r1, _080F9844 @ =0x0810E250
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl PrintJISString
	ldr r4, [r5, #0x3c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl PrintMinigameNumber
	movs r0, #1
_080F9838:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080F9840: .4byte 0x0810E248
_080F9844: .4byte 0x0810E250
