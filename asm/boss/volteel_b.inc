	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start volteelMode1
volteelMode1: @ 0x080438F4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08043982
	lsls r0, r0, #2
	ldr r1, _08043908 @ =_0804390C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08043908: .4byte _0804390C
_0804390C: @ jump table
	.4byte _08043924 @ case 0
	.4byte _08043958 @ case 1
	.4byte _08043938 @ case 2
	.4byte _0804394A @ case 3
	.4byte _08043958 @ case 4
	.4byte _08043974 @ case 5
_08043924:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	movs r0, #0x79
	bl PlaySound
	ldr r1, _08043934 @ =0x0000A50E
	b _0804394C
	.align 2, 0
_08043934: .4byte 0x0000A50E
_08043938:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08043968
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043982
	b _08043968
_0804394A:
	ldr r1, _08043970 @ =0x0000A510
_0804394C:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08043958:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08043982
_08043968:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08043982
	.align 2, 0
_08043970: .4byte 0x0000A510
_08043974:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08043982:
	pop {r4}
	pop {r0}
	bx r0

