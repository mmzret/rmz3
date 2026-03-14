	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c019c
FUN_080c019c: @ 0x080C019C
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x77
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C01E4
	movs r0, #6
	strb r0, [r3, #0x12]
	strb r0, [r3, #0x13]
	ldr r2, _080C01E0 @ =gSineTable
	movs r0, #0x75
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	str r0, [r3, #0x5c]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	b _080C0206
	.align 2, 0
_080C01E0: .4byte gSineTable
_080C01E4:
	ldr r1, _080C0218 @ =gSineTable
	adds r2, r3, #0
	adds r2, #0x75
	ldrb r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	asrs r0, r0, #2
	str r0, [r3, #0x5c]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
_080C0206:
	asrs r0, r0, #2
	str r0, [r3, #0x60]
	movs r0, #0
	str r0, [r3, #0x64]
	movs r0, #1
	str r0, [r3, #0x68]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0218: .4byte gSineTable

	thumb_func_start FUN_080c021c
FUN_080c021c: @ 0x080C021C
	push {r4, lr}
	adds r3, r0, #0
	adds r3, #0x74
	ldrb r1, [r3]
	ldr r2, _080C0254 @ =gSineTable
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x17
	adds r1, r1, r2
	movs r4, #0
	ldrsh r2, [r1, r4]
	lsls r2, r2, #1
	ldr r1, [r0, #0x78]
	adds r1, r1, r2
	str r1, [r0, #0x54]
	ldrb r1, [r3]
	adds r2, r1, #1
	adds r0, r2, #0
	cmp r2, #0
	bge _080C0246
	adds r0, r1, #0
	adds r0, #0x40
_080C0246:
	asrs r0, r0, #6
	lsls r0, r0, #6
	subs r0, r2, r0
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0254: .4byte gSineTable

