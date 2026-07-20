	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08061234
FUN_08061234: @ 0x08061234
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _080612CC
	lsls r0, r0, #2
	ldr r1, _08061248 @ =_0806124C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08061248: .4byte _0806124C
_0806124C: @ jump table
	.4byte _08061260 @ case 0
	.4byte _08061294 @ case 1
	.4byte _0806128E @ case 2
	.4byte _08061294 @ case 3
	.4byte _080612B8 @ case 4
_08061260:
	movs r0, #0xa7
	bl RemovePaletteAnimation
	movs r0, #0xa8
	bl RemovePaletteAnimation
	movs r0, #0xa9
	bl RemovePaletteAnimation
	movs r0, #0xaa
	bl RemovePaletteAnimation
	movs r1, #0xb0
	lsls r1, r1, #2
	movs r0, #0xa7
	bl StartPaletteAnimation
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08061294
_0806128E:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	b _080612B0
_08061294:
	adds r0, r4, #0
	bl FUN_080616fc
	movs r0, #0xa7
	bl StepPaletteAnimation
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080612CC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080612CC
_080612B0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080612CC
_080612B8:
	adds r0, r4, #0
	bl FUN_080616fc
	movs r0, #0xa7
	bl RemovePaletteAnimation
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080612CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

