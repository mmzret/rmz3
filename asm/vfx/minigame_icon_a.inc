	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Ghost77_Init
Ghost77_Init: @ 0x080C8330
	push {r4, r5, lr}
	mov ip, r0
	ldrb r5, [r0, #0x10]
	cmp r5, #0
	bne _080C8378
	ldrb r1, [r0, #0xa]
	movs r0, #0xef
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
	movs r2, #1
	mov r0, ip
	adds r0, #0x4c
	strb r5, [r0]
	mov r3, ip
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r1, _080C8374 @ =gVFXFnTable
	mov r3, ip
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r3, #0x14]
	strb r5, [r3, #0xd]
	strb r5, [r3, #0xe]
	strb r5, [r3, #0xf]
	b _080C83F4
	.align 2, 0
_080C8374: .4byte gVFXFnTable
_080C8378:
	cmp r5, #1
	bne _080C83AC
	movs r2, #0
	mov r4, ip
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	mov r0, ip
	adds r0, #0x4c
	strb r2, [r0]
	mov r3, ip
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r1, _080C83A8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	b _080C83E8
	.align 2, 0
_080C83A8: .4byte gVFXFnTable
_080C83AC:
	cmp r5, #2
	beq _080C83B8
	cmp r5, #3
	beq _080C83B8
	cmp r5, #4
	bne _080C83F4
_080C83B8:
	movs r2, #0
	mov r0, ip
	ldrb r1, [r0, #0xa]
	movs r0, #0xef
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
	movs r3, #1
	mov r0, ip
	adds r0, #0x4c
	strb r2, [r0]
	mov r4, ip
	adds r4, #0x4a
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
	ldr r1, _080C8400 @ =gVFXFnTable
	mov r4, ip
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
_080C83E8:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
_080C83F4:
	mov r0, ip
	bl Ghost77_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C8400: .4byte gVFXFnTable

