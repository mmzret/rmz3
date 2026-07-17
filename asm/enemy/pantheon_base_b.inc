	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start pBase_0808a47c
pBase_0808a47c: @ 0x0808A47C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808A48E
	cmp r0, #1
	beq _0808A49E
	b _0808A50C
_0808A48E:
	movs r1, #0xda
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808A49E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808A4D4 @ =0x08368BE5
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808A4D8 @ =0x08368984
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0808A4DC
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808A4E2
	.align 2, 0
_0808A4D4: .4byte 0x08368BE5
_0808A4D8: .4byte 0x08368984
_0808A4DC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808A4E2:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808A50C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start pBase_0808a514
pBase_0808a514: @ 0x0808A514
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0808A5B4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r4, _0808A5B8 @ =0x08368BEE
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r2, r4, #6
	adds r0, r5, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r4, #0xc
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0808A5BC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0808A5C0 @ =0x0000270E
	cmp r1, r0
	bhi _0808A590
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808A590:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldr r1, _0808A5C4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A5B4: .4byte 0xFFFFF000
_0808A5B8: .4byte 0x08368BEE
_0808A5BC: .4byte gScore
_0808A5C0: .4byte 0x0000270E
_0808A5C4: .4byte gEnemyFnTable

	thumb_func_start FUN_0808a5c8
FUN_0808a5c8: @ 0x0808A5C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r7, [r5, #0x28]
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0808A5DC
	cmp r6, #1
	beq _0808A65A
	b _0808A6A4
_0808A5DC:
	movs r4, #0
	ldr r0, _0808A6AC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808A5EE
	movs r4, #1
_0808A5EE:
	lsls r0, r4, #8
	subs r0, r1, r0
	str r0, [r5, #0x54]
	ldr r1, _0808A6B0 @ =0x00006D01
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_080b2b40
	ldr r0, [r7, #0x5c]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [sp, #8]
	movs r0, #0x60
	str r0, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808A6B4 @ =0x08368C00
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b834c
	strb r4, [r5, #0x12]
	ldr r0, [r7, #0x5c]
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808A65A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808A672
	str r1, [r5, #0x60]
_0808A672:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808A69E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0808A6B8 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808A6A4
_0808A69E:
	adds r0, r5, #0
	bl pBase_0808a514
_0808A6A4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808A6AC: .4byte pZero2
_0808A6B0: .4byte 0x00006D01
_0808A6B4: .4byte 0x08368C00
_0808A6B8: .4byte 0xFFFFF000

