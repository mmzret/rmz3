	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitMode1
cubitMode1: @ 0x08052B9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08052C2A
	lsls r0, r0, #2
	ldr r1, _08052BB0 @ =_08052BB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08052BB0: .4byte _08052BB4
_08052BB4: @ jump table
	.4byte _08052BCC @ case 0
	.4byte _08052C00 @ case 1
	.4byte _08052BE0 @ case 2
	.4byte _08052BF2 @ case 3
	.4byte _08052C00 @ case 4
	.4byte _08052C1C @ case 5
_08052BCC:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	movs r0, #0xc9
	bl PlaySound
	ldr r1, _08052BDC @ =0x0000B007
	b _08052BF4
	.align 2, 0
_08052BDC: .4byte 0x0000B007
_08052BE0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08052C10
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08052C2A
	b _08052C10
_08052BF2:
	ldr r1, _08052C18 @ =0x0000B009
_08052BF4:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052C00:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08052C2A
_08052C10:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08052C2A
	.align 2, 0
_08052C18: .4byte 0x0000B009
_08052C1C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08052C2A:
	pop {r4}
	pop {r0}
	bx r0

