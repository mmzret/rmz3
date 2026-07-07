	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start VFX50_Init
VFX50_Init: @ 0x080C0854
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080C0896
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x80
	b _080C08BC
_080C0896:
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x80
	rsbs r0, r0, #0
_080C08BC:
	str r0, [r4, #0x5c]
	movs r2, #0
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080C08E4
	ldr r1, _080C08E0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080C08F8
	.align 2, 0
_080C08E0: .4byte gVFXFnTable
_080C08E4:
	ldr r1, _080C0910 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_080C08F8:
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl VFX50_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0910: .4byte gVFXFnTable

	thumb_func_start VFX50_Update
VFX50_Update: @ 0x080C0914
	push {lr}
	ldr r2, _080C0928 @ =0x0836F178
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C0928: .4byte 0x0836F178

	thumb_func_start VFX50_Die
VFX50_Die: @ 0x080C092C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C0948 @ =gVFXFnTable
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
_080C0948: .4byte gVFXFnTable

	thumb_func_start FUN_080c094c
FUN_080c094c: @ 0x080C094C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C095C
	cmp r5, #1
	beq _080C0984
	b _080C09B8
_080C095C:
	ldr r1, _080C09C0 @ =sVFX50Animations
	adds r0, r4, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #9
	strb r0, [r1]
	movs r0, #0xa
	strb r0, [r4, #0x13]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C0984:
	ldr r1, [r4, #0x60]
	subs r1, #0x20
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080C09A6
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C09B8
_080C09A6:
	ldr r1, _080C09C4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C09B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C09C0: .4byte sVFX50Animations
_080C09C4: .4byte gVFXFnTable

	thumb_func_start FUN_080c09c8
FUN_080c09c8: @ 0x080C09C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080C0A22
	cmp r5, #1
	bgt _080C09DC
	cmp r5, #0
	beq _080C09E2
	b _080C0A98
_080C09DC:
	cmp r5, #2
	beq _080C0A6A
	b _080C0A98
_080C09E2:
	ldr r1, _080C0A00 @ =0x0000B01C
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080C0A04
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080C0A0A
	.align 2, 0
_080C0A00: .4byte 0x0000B01C
_080C0A04:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080C0A5C @ =0xFFFFF400
_080C0A0A:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C0A22:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C0A60
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	b _080C0A98
	.align 2, 0
_080C0A5C: .4byte 0xFFFFF400
_080C0A60:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080C0A98
_080C0A6A:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080C0A98
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080C0AA0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C0A98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0AA0: .4byte gVFXFnTable
