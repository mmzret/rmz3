#include "global.h"
#include "overworld.h"

// Blocking領域内かチェックしてそうだとしたらBlocking領域のmetatile_attr_tを返す
NAKED metatile_attr_t GetBlockingMetatileAttr(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	mov sl, r0\n\
	mov sb, r1\n\
	movs r5, #0\n\
	ldr r0, _0800AC94 @ =gOverworld\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r1, r0, r2\n\
	ldrb r1, [r1]\n\
	cmp r5, r1\n\
	bge _0800ACB4\n\
	movs r7, #0xf0\n\
	lsls r7, r7, #1\n\
	adds r7, r7, r0\n\
	mov ip, r7\n\
	adds r2, #0xa\n\
	adds r2, r0, r2\n\
	str r2, [sp]\n\
	adds r3, r0, #0\n\
	movs r6, #0\n\
	mov r8, r1\n\
_0800AC4C:\n\
	movs r7, #0xec\n\
	lsls r7, r7, #1\n\
	adds r0, r3, r7\n\
	ldrh r1, [r0]\n\
	lsls r2, r1, #1\n\
	ldr r0, [sp]\n\
	ldr r4, [r0]\n\
	mov r7, sl\n\
	subs r0, r7, r4\n\
	adds r0, r0, r1\n\
	cmp r2, r0\n\
	bls _0800ACA0\n\
	movs r1, #0xed\n\
	lsls r1, r1, #1\n\
	adds r0, r3, r1\n\
	ldrh r0, [r0]\n\
	lsls r2, r0, #1\n\
	mov r7, ip\n\
	ldr r1, [r7]\n\
	mov r7, sb\n\
	subs r1, r7, r1\n\
	adds r1, r1, r0\n\
	subs r1, #1\n\
	cmp r2, r1\n\
	bls _0800ACA0\n\
	ldr r1, _0800AC98 @ =gOverworld+484\n\
	adds r0, r6, r1\n\
	ldr r0, [r0]\n\
	subs r0, r4, r0\n\
	ldr r2, _0800AC9C @ =s32_ARRAY_02000028\n\
	str r0, [r2]\n\
	movs r7, #0xeb\n\
	lsls r7, r7, #1\n\
	adds r0, r3, r7\n\
	ldrh r0, [r0]\n\
	b _0800ACB6\n\
	.align 2, 0\n\
_0800AC94: .4byte gOverworld\n\
_0800AC98: .4byte gOverworld+484\n\
_0800AC9C: .4byte s32_ARRAY_02000028\n\
_0800ACA0:\n\
	movs r0, #0x18\n\
	add ip, r0\n\
	ldr r1, [sp]\n\
	adds r1, #0x18\n\
	str r1, [sp]\n\
	adds r3, #0x18\n\
	adds r6, #0x18\n\
	adds r5, #1\n\
	cmp r5, r8\n\
	blt _0800AC4C\n\
_0800ACB4:\n\
	movs r0, #0\n\
_0800ACB6:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// めり込んでた時の上への押し出し距離を返す
WIP s32 CalcPushout_Up(s32 x, s32 y) {
#if MODERN
  s32 i;
  for (i = 0; i < gOverworld.unk_1c8.hazardLength; i++) {
    struct Hazard *b = HAZARD(i);
    const u32 w = (u32)((u16)b->w);
    if ((u32)(x - (b->start).x) + w < (w << 1)) {
      const u32 h = (u32)((u16)b->h);
      u32 unk = (u32)(y - (b->start).y) + h - 1;
      if (unk < (h * 2)) {
        return (b->start).y - h;  // 押し出し量 = ((b->start).y - b->h) - y
      }
    }
  }
  return y;  // 押し出しなし
#else
  INCCODE("asm/wip/CalcPushout_Up.inc");
#endif
}

WIP s32 CalcPushout_Down(s32 x, s32 y) {
#if MODERN
  s32 i;
  for (i = 0; i < gOverworld.unk_1c8.hazardLength; i++) {
    struct Hazard *b = HAZARD(i);
    const u32 w = (u32)((u16)b->w);
    if ((u32)(x - (b->start).x) + w < (w << 1)) {
      const u32 h = (u32)((u16)b->h);
      u32 unk = (u32)(y - (b->start).y) + h - 1;
      if (unk < (h * 2) && ((b->attr & 0x8400) == 0)) {
        return (b->start).y + h + 1;  // 押し出し量 = ((b->start).y - b->h) - y
      }
    }
  }
  return y;  // 押し出しなし
#else
  INCCODE("asm/wip/CalcPushout_Down.inc");
#endif
}

NAKED s32 CalcPushout_Left(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	str r1, [sp]\n\
	ldr r0, _0800AE6C @ =gOverworld\n\
	str r0, [sp, #4]\n\
_0800AE00:\n\
	movs r5, #0\n\
	ldr r1, [sp, #4]\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	bge _0800AE7E\n\
	movs r7, #0xf0\n\
	lsls r7, r7, #1\n\
	adds r7, r7, r1\n\
	mov sb, r7\n\
	adds r2, #0xa\n\
	adds r2, r2, r1\n\
	mov r8, r2\n\
	mov ip, r1\n\
	mov sl, r0\n\
_0800AE22:\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r3, [r0]\n\
	lsls r1, r3, #1\n\
	mov r7, r8\n\
	ldr r4, [r7]\n\
	subs r0, r6, r4\n\
	adds r0, r0, r3\n\
	cmp r1, r0\n\
	bls _0800AE70\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	lsls r2, r0, #1\n\
	mov r7, sb\n\
	ldr r1, [r7]\n\
	ldr r7, [sp]\n\
	subs r1, r7, r1\n\
	adds r1, r1, r0\n\
	subs r1, #1\n\
	cmp r2, r1\n\
	bls _0800AE70\n\
	movs r0, #0xeb\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800AE70\n\
	subs r0, r4, r3\n\
	subs r6, r0, #1\n\
	b _0800AE00\n\
	.align 2, 0\n\
_0800AE6C: .4byte gOverworld\n\
_0800AE70:\n\
	movs r0, #0x18\n\
	add sb, r0\n\
	add r8, r0\n\
	add ip, r0\n\
	adds r5, #1\n\
	cmp r5, sl\n\
	blt _0800AE22\n\
_0800AE7E:\n\
	adds r0, r6, #0\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 CalcPushout_Right(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	str r1, [sp]\n\
	ldr r0, _0800AF0C @ =gOverworld\n\
	str r0, [sp, #4]\n\
_0800AEA4:\n\
	movs r5, #0\n\
	ldr r1, [sp, #4]\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	bge _0800AF1E\n\
	movs r7, #0xf0\n\
	lsls r7, r7, #1\n\
	adds r7, r7, r1\n\
	mov sb, r7\n\
	adds r2, #0xa\n\
	adds r2, r2, r1\n\
	mov r8, r2\n\
	mov ip, r1\n\
	mov sl, r0\n\
_0800AEC6:\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r3, [r0]\n\
	lsls r1, r3, #1\n\
	mov r7, r8\n\
	ldr r4, [r7]\n\
	subs r0, r6, r4\n\
	adds r0, r0, r3\n\
	cmp r1, r0\n\
	bls _0800AF10\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	lsls r2, r0, #1\n\
	mov r7, sb\n\
	ldr r1, [r7]\n\
	ldr r7, [sp]\n\
	subs r1, r7, r1\n\
	adds r1, r1, r0\n\
	subs r1, #1\n\
	cmp r2, r1\n\
	bls _0800AF10\n\
	movs r0, #0xeb\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800AF10\n\
	adds r6, r4, r3\n\
	b _0800AEA4\n\
	.align 2, 0\n\
_0800AF0C: .4byte gOverworld\n\
_0800AF10:\n\
	movs r0, #0x18\n\
	add sb, r0\n\
	add r8, r0\n\
	add ip, r0\n\
	adds r5, #1\n\
	cmp r5, sl\n\
	blt _0800AEC6\n\
_0800AF1E:\n\
	adds r0, r6, #0\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800af30(s32 x, s32 y, s32 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	str r0, [sp]\n\
	adds r7, r1, #0\n\
	adds r5, r2, #0\n\
	cmp r5, r7\n\
	bge _0800AF4E\n\
	adds r1, r5, #0\n\
	bl CalcPushout_Up\n\
	b _0800AFC0\n\
_0800AF4E:\n\
	subs r0, r5, r7\n\
	asrs r0, r0, #1\n\
	mov sl, r0\n\
	add r7, sl\n\
	ldr r0, _0800AFD0 @ =gOverworld\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r1, r0, r2\n\
	ldrb r1, [r1]\n\
	cmp r1, #0\n\
	beq _0800AFBE\n\
	movs r3, #0xf0\n\
	lsls r3, r3, #1\n\
	adds r3, r3, r0\n\
	mov sb, r3\n\
	adds r2, #0xa\n\
	adds r2, r2, r0\n\
	mov r8, r2\n\
	mov ip, r0\n\
	adds r6, r1, #0\n\
_0800AF76:\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	lsls r2, r1, #1\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	ldr r3, [sp]\n\
	subs r0, r3, r0\n\
	adds r0, r0, r1\n\
	cmp r2, r0\n\
	bls _0800AFB0\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r4, [r0]\n\
	mov r1, sl\n\
	adds r0, r4, r1\n\
	lsls r2, r0, #1\n\
	mov r1, sb\n\
	ldr r3, [r1]\n\
	subs r1, r7, r3\n\
	adds r1, r1, r0\n\
	cmp r2, r1\n\
	bls _0800AFB0\n\
	subs r0, r3, r4\n\
	cmp r5, r0\n\
	ble _0800AFB0\n\
	adds r5, r0, #0\n\
_0800AFB0:\n\
	movs r2, #0x18\n\
	add sb, r2\n\
	add r8, r2\n\
	add ip, r2\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne _0800AF76\n\
_0800AFBE:\n\
	adds r0, r5, #0\n\
_0800AFC0:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800AFD0: .4byte gOverworld\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800afd4(s32 x, s32 y1, s32 y2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	str r0, [sp]\n\
	adds r7, r1, #0\n\
	adds r5, r2, #0\n\
	cmp r5, r7\n\
	ble _0800AFF2\n\
	adds r1, r5, #0\n\
	bl CalcPushout_Down\n\
	b _0800B078\n\
_0800AFF2:\n\
	subs r0, r7, r5\n\
	asrs r0, r0, #1\n\
	mov sl, r0\n\
	subs r7, r7, r0\n\
	ldr r0, _0800B088 @ =gOverworld\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r1, r0, r2\n\
	ldrb r1, [r1]\n\
	cmp r1, #0\n\
	beq _0800B076\n\
	movs r3, #0xf0\n\
	lsls r3, r3, #1\n\
	adds r3, r3, r0\n\
	mov sb, r3\n\
	adds r2, #0xa\n\
	adds r2, r2, r0\n\
	mov r8, r2\n\
	mov ip, r0\n\
	adds r6, r1, #0\n\
_0800B01A:\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	lsls r2, r1, #1\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	ldr r3, [sp]\n\
	subs r0, r3, r0\n\
	adds r0, r0, r1\n\
	cmp r2, r0\n\
	bls _0800B068\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r4, [r0]\n\
	mov r1, sl\n\
	adds r0, r4, r1\n\
	lsls r2, r0, #1\n\
	mov r1, sb\n\
	ldr r3, [r1]\n\
	subs r1, r7, r3\n\
	adds r1, r1, r0\n\
	cmp r2, r1\n\
	blo _0800B068\n\
	adds r0, r3, r4\n\
	adds r2, r0, #1\n\
	cmp r5, r2\n\
	bge _0800B068\n\
	movs r0, #0xeb\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800B068\n\
	adds r5, r2, #0\n\
_0800B068:\n\
	movs r2, #0x18\n\
	add sb, r2\n\
	add r8, r2\n\
	add ip, r2\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne _0800B01A\n\
_0800B076:\n\
	adds r0, r5, #0\n\
_0800B078:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800B088: .4byte gOverworld\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800b08c(s32 x, s32 y1, s32 y2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r7, r0, #0\n\
	str r1, [sp]\n\
	adds r5, r2, #0\n\
	cmp r5, r7\n\
	bge _0800B0AA\n\
	adds r0, r5, #0\n\
	bl CalcPushout_Left\n\
	b _0800B12E\n\
_0800B0AA:\n\
	subs r0, r5, r7\n\
	asrs r0, r0, #1\n\
	mov sl, r0\n\
	add r7, sl\n\
	ldr r0, _0800B140 @ =gOverworld\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r1, r0, r2\n\
	ldrb r1, [r1]\n\
	cmp r1, #0\n\
	beq _0800B12C\n\
	movs r3, #0xee\n\
	lsls r3, r3, #1\n\
	adds r3, r3, r0\n\
	mov sb, r3\n\
	adds r2, #0xe\n\
	adds r2, r2, r0\n\
	mov r8, r2\n\
	mov ip, r0\n\
	adds r6, r1, #0\n\
_0800B0D2:\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	lsls r2, r0, #1\n\
	mov r3, r8\n\
	ldr r1, [r3]\n\
	ldr r3, [sp]\n\
	subs r1, r3, r1\n\
	adds r1, r1, r0\n\
	cmp r2, r1\n\
	bls _0800B11E\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r4, [r0]\n\
	mov r0, sl\n\
	adds r1, r4, r0\n\
	lsls r2, r1, #1\n\
	mov r0, sb\n\
	ldr r3, [r0]\n\
	subs r0, r7, r3\n\
	adds r0, r0, r1\n\
	cmp r2, r0\n\
	bls _0800B11E\n\
	subs r2, r3, r4\n\
	cmp r5, r2\n\
	ble _0800B11E\n\
	movs r0, #0xeb\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800B11E\n\
	subs r5, r2, #1\n\
_0800B11E:\n\
	movs r2, #0x18\n\
	add sb, r2\n\
	add r8, r2\n\
	add ip, r2\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne _0800B0D2\n\
_0800B12C:\n\
	adds r0, r5, #0\n\
_0800B12E:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800B140: .4byte gOverworld\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800b144(s32 x, s32 y1, s32 y2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r7, r0, #0\n\
	str r1, [sp]\n\
	adds r5, r2, #0\n\
	cmp r5, r7\n\
	ble _0800B162\n\
	adds r0, r5, #0\n\
	bl CalcPushout_Right\n\
	b _0800B1E6\n\
_0800B162:\n\
	subs r0, r7, r5\n\
	asrs r0, r0, #1\n\
	mov sl, r0\n\
	subs r7, r7, r0\n\
	ldr r0, _0800B1F8 @ =gOverworld\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r1, r0, r2\n\
	ldrb r1, [r1]\n\
	cmp r1, #0\n\
	beq _0800B1E4\n\
	movs r3, #0xee\n\
	lsls r3, r3, #1\n\
	adds r3, r3, r0\n\
	mov sb, r3\n\
	adds r2, #0xe\n\
	adds r2, r2, r0\n\
	mov r8, r2\n\
	mov ip, r0\n\
	adds r6, r1, #0\n\
_0800B18A:\n\
	movs r0, #0xed\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r0, [r0]\n\
	lsls r2, r0, #1\n\
	mov r3, r8\n\
	ldr r1, [r3]\n\
	ldr r3, [sp]\n\
	subs r1, r3, r1\n\
	adds r1, r1, r0\n\
	cmp r2, r1\n\
	bls _0800B1D6\n\
	movs r0, #0xec\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r4, [r0]\n\
	mov r0, sl\n\
	adds r1, r4, r0\n\
	lsls r2, r1, #1\n\
	mov r0, sb\n\
	ldr r3, [r0]\n\
	subs r0, r7, r3\n\
	adds r0, r0, r1\n\
	cmp r2, r0\n\
	bls _0800B1D6\n\
	adds r2, r3, r4\n\
	cmp r5, r2\n\
	bge _0800B1D6\n\
	movs r0, #0xeb\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrh r1, [r0]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0800B1D6\n\
	adds r5, r2, #0\n\
_0800B1D6:\n\
	movs r2, #0x18\n\
	add sb, r2\n\
	add r8, r2\n\
	add ip, r2\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne _0800B18A\n\
_0800B1E4:\n\
	adds r0, r5, #0\n\
_0800B1E6:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800B1F8: .4byte gOverworld\n\
 .syntax divided\n");
}
