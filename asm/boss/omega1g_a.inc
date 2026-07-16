	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start OmegaGold_Init
OmegaGold_Init: @ 0x0805AFAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	bl FUN_08016080
	ldr r0, _0805B0F4 @ =gOverworld
	ldr r1, _0805B0F8 @ =0x0002D025
	adds r0, r0, r1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _0805B0FC @ =gStaticMotionGraphics
	adds r0, #0xb4
	ldr r4, _0805B100 @ =wStaticGraphicTilenums
	ldrh r1, [r4, #0x12]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	mov r8, r2
	add r1, r8
	bl LoadGraphic
	ldr r0, _0805B104 @ =gStaticMotionGraphics+12
	mov sb, r0
	adds r0, #0xb4
	ldr r5, _0805B108 @ =wStaticMotionPalIDs
	ldrh r1, [r5, #0x12]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	add r1, sl
	bl LoadPalette
	ldr r0, _0805B0FC @ =gStaticMotionGraphics
	adds r0, #0xc8
	ldrh r1, [r4, #0x14]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	add r1, r8
	bl LoadGraphic
	mov r0, sb
	adds r0, #0xc8
	ldrh r1, [r5, #0x14]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	add r1, sl
	bl LoadPalette
	movs r6, #0
	movs r1, #0xc0
	lsls r1, r1, #2
	strh r1, [r4, #0x18]
	movs r0, #7
	strh r0, [r5, #0x18]
	ldr r0, _0805B0FC @ =gStaticMotionGraphics
	adds r0, #0xf0
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	add r1, r8
	bl LoadGraphic
	mov r0, sb
	adds r0, #0xf0
	ldrh r1, [r5, #0x18]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	add r1, sl
	bl LoadPalette
	adds r4, #0xca
	movs r1, #0xc5
	lsls r1, r1, #2
	strh r1, [r4]
	adds r5, #0xca
	movs r0, #8
	strh r0, [r5]
	ldr r4, _0805B10C @ =0x000007E4
	ldr r2, _0805B0FC @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	add r1, r8
	bl LoadGraphic
	add r4, sb
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _0805B110 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x60
	bl ResetBossBody
	ldr r1, _0805B114 @ =onCollision
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	movs r1, #0
	str r1, [r0]
	subs r0, #5
	strb r6, [r0]
	adds r0, #9
	strh r1, [r0]
	ldr r1, [r7, #0x58]
	ldr r2, _0805B118 @ =0xFFFFB000
	adds r1, r1, r2
	ldr r0, [r7, #0x54]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xb8
	str r0, [r1]
	str r0, [r7, #0x68]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _0805B120
	ldr r1, _0805B11C @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	b _0805B136
	.align 2, 0
_0805B0F4: .4byte gOverworld
_0805B0F8: .4byte 0x0002D025
_0805B0FC: .4byte gStaticMotionGraphics
_0805B100: .4byte wStaticGraphicTilenums
_0805B104: .4byte gStaticMotionGraphics+12
_0805B108: .4byte wStaticMotionPalIDs
_0805B10C: .4byte 0x000007E4
_0805B110: .4byte sCollisions
_0805B114: .4byte onCollision
_0805B118: .4byte 0xFFFFB000
_0805B11C: .4byte gBossFnTable
_0805B120:
	ldr r1, _0805B198 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #1
	str r2, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	movs r0, #3
	strb r0, [r7, #0xd]
_0805B136:
	strb r6, [r7, #0xe]
	strb r6, [r7, #0xf]
	mov r0, sp
	movs r1, #0
	adds r2, r7, #0
	bl FUN_08082b58
	movs r0, #0
	str r0, [r7, #0x2c]
	mov r0, sp
	movs r1, #1
	adds r2, r7, #0
	bl FUN_08082b58
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	adds r2, r7, #0
	bl CreateOmega1gSword
	adds r1, r7, #0
	adds r1, #0xc8
	str r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #2
	movs r0, #0xb
	bl StartPaletteAnimation
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0x66
	bl StartPaletteAnimation
	ldr r0, _0805B19C @ =0x0000010F
	movs r1, #0xa0
	lsls r1, r1, #2
	bl StartPaletteAnimation
	adds r0, r7, #0
	bl OmegaGold_Update
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805B198: .4byte gBossFnTable
_0805B19C: .4byte 0x0000010F

