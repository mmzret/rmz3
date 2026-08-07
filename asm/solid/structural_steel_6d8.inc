	.include "asm/macros.inc"

	.syntax unified
	
	.text

	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080DF6E8
	cmp r0, #1
	beq _080DF700
	b _080DF760
_080DF6E8:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080DF700:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080DF720
	ldr r0, _080DF718 @ =gOverworld
	ldr r1, _080DF71C @ =0x0002D02C
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r2, r0, #8
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0x10
	adds r2, r2, r0
	b _080DF730
	.align 2, 0
_080DF718: .4byte gOverworld
_080DF71C: .4byte 0x0002D02C
_080DF720:
	ldr r0, _080DF73C @ =gOverworld
	ldr r1, _080DF740 @ =0x0002D030
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r2, r0, #8
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0xf
	subs r2, r2, r0
_080DF730:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080DF744
	movs r1, #0xc2
	lsls r1, r1, #0xb
	b _080DF748
	.align 2, 0
_080DF73C: .4byte gOverworld
_080DF740: .4byte 0x0002D030
_080DF744:
	movs r1, #0x88
	lsls r1, r1, #0xa
_080DF748:
	adds r0, r2, #0
	bl __modsi3
	adds r2, r0, #0
	ldr r0, [r4, #0x64]
	adds r0, r2, r0
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x68]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080DF760:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
