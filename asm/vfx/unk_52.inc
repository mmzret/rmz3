	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX52
CreateVFX52: @ 0x080C0C60
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080C0CA4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C0C9A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C0CA8 @ =gVFXFnTable
	movs r1, #0x34
	strb r1, [r3, #9]
	adds r0, #0xd0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r0, [r3, #0x11]
	str r4, [r3, #0x28]
_080C0C9A:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C0CA4: .4byte gVFXHeaderPtr
_080C0CA8: .4byte gVFXFnTable

	thumb_func_start VFX52_Init
VFX52_Init: @ 0x080C0CAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C0CF0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitScalerotMotion1
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xd
	bl ForceEntityPalette
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x80
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl VFX52_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0CF0: .4byte gVFXFnTable

	thumb_func_start VFX52_Update
VFX52_Update: @ 0x080C0CF4
	push {r4, lr}
	mov ip, r0
	ldr r4, [r0, #0x28]
	ldr r0, [r4, #0x54]
	mov r1, ip
	str r0, [r1, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r1, #0x58]
	ldrb r0, [r1, #0x13]
	adds r1, r0, #0
	adds r1, #8
	mov r2, ip
	strb r1, [r2, #0x13]
	ldr r1, _080C0D7C @ =gSineTable
	adds r0, #0x48
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	asrs r0, r0, #3
	movs r3, #8
	rsbs r3, r3, #0
	adds r1, r3, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r2
	mov r1, ip
	adds r1, #0x50
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r1, [r0]
	lsls r1, r1, #0x16
	mov r3, ip
	adds r3, #0x48
	lsrs r1, r1, #0x16
	ldrh r2, [r3]
	ldr r0, _080C0D80 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	ldr r0, [r4, #0x3c]
	mov r1, ip
	str r0, [r1, #0x3c]
	adds r0, r4, #0
	adds r0, #0x4e
	ldrb r0, [r0]
	adds r1, #0x4e
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080C0D84
	mov r3, ip
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r3, #0xa]
	b _080C0D90
	.align 2, 0
_080C0D7C: .4byte gSineTable
_080C0D80: .4byte 0xFFFFFC00
_080C0D84:
	mov r0, ip
	ldrb r1, [r0, #0xa]
	movs r0, #0xef
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
_080C0D90:
	adds r1, r2, #0
	mov r0, ip
	adds r0, #0x4c
	strb r1, [r0]
	mov r3, ip
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bhi _080C0DB8
	mov r2, ip
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	beq _080C0DD2
_080C0DB8:
	ldr r1, _080C0DD8 @ =gVFXFnTable
	mov r3, ip
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	mov r0, ip
	bl VFX52_Die
_080C0DD2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0DD8: .4byte gVFXFnTable

	thumb_func_start VFX52_Die
VFX52_Die: @ 0x080C0DDC
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C0DF8 @ =gVFXFnTable
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
_080C0DF8: .4byte gVFXFnTable
