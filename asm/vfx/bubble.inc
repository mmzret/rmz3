	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b30b4
FUN_080b30b4: @ 0x080B30B4
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	adds r0, #8
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080B3130 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	ldr r1, [r4, #0x5c]
	adds r1, r1, r0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _080B3134 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	cmp r0, #0
	bne _080B3116
	ldr r0, _080B3138 @ =gOverworld
	ldr r1, _080B313C @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r4, #0x60]
	lsls r1, r1, #1
	ldr r2, [r4, #0x58]
	subs r1, r2, r1
	ldr r0, [r0]
	cmp r0, r1
	blt _080B3128
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	beq _080B3128
_080B3116:
	ldr r1, _080B3140 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B3128:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B3130: .4byte gSineTable
_080B3134: .4byte gStageRun+232
_080B3138: .4byte gOverworld
_080B313C: .4byte 0x0002C00C
_080B3140: .4byte gVFXFnTable

	thumb_func_start FUN_080b3144
FUN_080b3144: @ 0x080B3144
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldr r2, [r4, #0x5c]
	adds r2, #8
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080B31C4 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	asrs r2, r2, #8
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r0, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _080B31C8 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	cmp r0, #0
	bne _080B31AC
	ldr r0, _080B31CC @ =gOverworld
	ldr r1, _080B31D0 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r4, #0x60]
	lsls r1, r1, #1
	ldr r2, [r4, #0x58]
	subs r1, r2, r1
	ldr r0, [r0]
	cmp r0, r1
	blt _080B31BE
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	beq _080B31BE
_080B31AC:
	ldr r1, _080B31D4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B31BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B31C4: .4byte gSineTable
_080B31C8: .4byte gStageRun+232
_080B31CC: .4byte gOverworld
_080B31D0: .4byte 0x0002C00C
_080B31D4: .4byte gVFXFnTable

	thumb_func_start FUN_080b31d8
FUN_080b31d8: @ 0x080B31D8
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	adds r0, #8
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x60]
	subs r0, #0x60
	str r0, [r4, #0x60]
	ldr r1, _080B3260 @ =0xFFFFFF00
	cmp r0, r1
	bge _080B31F4
	str r1, [r4, #0x60]
_080B31F4:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080B3264 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	ldr r1, [r4, #0x5c]
	adds r1, r1, r0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _080B3268 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	cmp r0, #0
	bne _080B3248
	ldr r0, _080B326C @ =gOverworld
	ldr r1, _080B3270 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r4, #0x60]
	lsls r1, r1, #1
	ldr r2, [r4, #0x58]
	subs r1, r2, r1
	ldr r0, [r0]
	cmp r0, r1
	blt _080B325A
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	beq _080B325A
_080B3248:
	ldr r1, _080B3274 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B325A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B3260: .4byte 0xFFFFFF00
_080B3264: .4byte gSineTable
_080B3268: .4byte gStageRun+232
_080B326C: .4byte gOverworld
_080B3270: .4byte 0x0002C00C
_080B3274: .4byte gVFXFnTable

	thumb_func_start FUN_080b3278
FUN_080b3278: @ 0x080B3278
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	adds r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	subs r0, #0x60
	str r0, [r4, #0x60]
	ldr r1, _080B3308 @ =0xFFFFFF00
	cmp r0, r1
	bge _080B329A
	str r1, [r4, #0x60]
_080B329A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080B330C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #8
	muls r1, r0, r1
	ldr r0, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _080B3310 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	cmp r0, #0
	bne _080B32EE
	ldr r0, _080B3314 @ =gOverworld
	ldr r1, _080B3318 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r4, #0x60]
	lsls r1, r1, #1
	ldr r2, [r4, #0x58]
	subs r1, r2, r1
	ldr r0, [r0]
	cmp r0, r1
	blt _080B3300
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	beq _080B3300
_080B32EE:
	ldr r1, _080B331C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B3300:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B3308: .4byte 0xFFFFFF00
_080B330C: .4byte gSineTable
_080B3310: .4byte gStageRun+232
_080B3314: .4byte gOverworld
_080B3318: .4byte 0x0002C00C
_080B331C: .4byte gVFXFnTable
