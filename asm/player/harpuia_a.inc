	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Harpuia_Update
Harpuia_Update: @ 0x08035118
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r0, #2
	beq _0803515C
	ldr r1, [r4, #0x54]
	ldr r0, [r5, #0x34]
	adds r3, r1, r0
	str r3, [r4, #0x54]
	movs r6, #0x9f
	lsls r6, r6, #2
	adds r2, r4, r6
	ldr r1, [r2]
	ldr r0, [r5, #0x30]
	adds r0, r1, r0
	cmp r3, r0
	beq _0803515C
	ldr r6, _080351A8 @ =0xFFFFF800
	adds r1, r3, r6
	subs r1, r0, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r0, r3, r0
	str r0, [r4, #0x54]
	ldr r2, [r2]
	ldr r1, [r5, #0x30]
	adds r1, r2, r1
	cmp r0, r1
	blt _0803515C
	str r1, [r4, #0x54]
_0803515C:
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x30]
	adds r0, r0, r1
	ldr r6, _080351AC @ =0xFFFF9C00
	adds r0, r0, r6
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bge _08035176
	b _080352A2
_08035176:
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r0, #2
	beq _080351B8
	ldr r1, _080351B0 @ =0x0835EAD0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080351B4 @ =0x0835EAE4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl harpuia_08035684
	b _080351DE
	.align 2, 0
_080351A8: .4byte 0xFFFFF800
_080351AC: .4byte 0xFFFF9C00
_080351B0: .4byte 0x0835EAD0
_080351B4: .4byte 0x0835EAE4
_080351B8:
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	bne _080351DE
	ldr r1, _080352D4 @ =0x0835EAD0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080352D8 @ =0x0835EAE4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080351DE:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #4
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _08035204
	ldr r1, [r4, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _08035204
	ldrh r0, [r1, #0x38]
	adds r0, #1
	strh r0, [r1, #0x38]
	ldr r0, _080352DC @ =0x00000137
	bl PlaySound
_08035204:
	ldr r0, [r5]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803523C
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _08035244
	subs r0, #1
	strb r0, [r1, #0xc]
	movs r0, #0xf8
	bl PlaySound
	movs r0, #4
	bl PlaySound
	ldr r6, _080352E0 @ =0x00000287
	adds r1, r4, r6
	movs r0, #0x5a
	strb r0, [r1]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	bne _0803526E
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0803523C:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	bne _0803526E
_08035244:
	ldr r0, _080352E0 @ =0x00000287
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08035252
	subs r0, #1
	strb r0, [r1]
_08035252:
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803526E
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
_0803526E:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r1, [r2]
	ldr r0, [r4, #0x54]
	str r0, [r1, #0x54]
	ldr r1, [r2]
	ldr r0, [r4, #0x58]
	str r0, [r1, #0x58]
	ldr r0, [r2]
	ldr r1, [r0, #0x2c]
	cmp r1, #0
	beq _08035294
	ldr r0, [r4, #0x54]
	str r0, [r1, #0x54]
	ldr r0, [r2]
	ldr r1, [r0, #0x2c]
	ldr r0, [r4, #0x58]
	str r0, [r1, #0x58]
_08035294:
	ldr r0, [r4, #0x58]
	ldr r2, _080352E4 @ =0xFFFF9C00
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #9
	cmp r0, r1
	ble _080352CC
_080352A2:
	movs r0, #0xf8
	bl PlaySound
	movs r0, #4
	bl PlaySound
	ldr r0, [r4, #0x28]
	movs r2, #0
	strb r2, [r0, #0xc]
	ldr r1, _080352E8 @ =gPlayerFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
_080352CC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080352D4: .4byte 0x0835EAD0
_080352D8: .4byte 0x0835EAE4
_080352DC: .4byte 0x00000137
_080352E0: .4byte 0x00000287
_080352E4: .4byte 0xFFFF9C00
_080352E8: .4byte gPlayerFnTable

	thumb_func_start Harpuia_Die
Harpuia_Die: @ 0x080352EC
	adds r3, r0, #0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08035328 @ =gPlayerFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	bx lr
	.align 2, 0
_08035328: .4byte gPlayerFnTable
