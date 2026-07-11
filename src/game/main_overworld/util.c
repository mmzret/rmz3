#include "game.h"
#include "global.h"
#include "text.h"

NAKED u16 handleWrapTwoChoice(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, _080F32C0 @ =gJoypad\n\
	ldrh r1, [r5, #6]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F3258\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r4, #0xa]\n\
	adds r0, #1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	strh r0, [r4, #0xa]\n\
_080F3258:\n\
	ldrh r1, [r5, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F3272\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r4, #0xa]\n\
	adds r0, #1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	strh r0, [r4, #0xa]\n\
_080F3272:\n\
	ldr r0, _080F32C4 @ =StringOfsTable\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F32C8 @ =gStringData\n\
	adds r5, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F32CC @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r3, r0, #0\n\
	cmp r1, #0\n\
	bne _080F328C\n\
	ldrb r0, [r3, #4]\n\
	cmp r0, #1\n\
	bne _080F328E\n\
_080F328C:\n\
	movs r2, #1\n\
_080F328E:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	movs r0, #0xa\n\
	ldrsh r2, [r4, r0]\n\
	lsls r2, r2, #1\n\
	adds r2, #2\n\
	ldrb r3, [r3, #5]\n\
	adds r2, r2, r3\n\
	adds r0, r5, #0\n\
	bl PrintString\n\
	ldr r0, _080F32C0 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F32D0\n\
	movs r0, #3\n\
	bl PlaySound\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	b _080F32F2\n\
	.align 2, 0\n\
_080F32C0: .4byte gJoypad\n\
_080F32C4: .4byte StringOfsTable\n\
_080F32C8: .4byte gStringData\n\
_080F32CC: .4byte gTextWindow+8\n\
_080F32D0:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F32F0\n\
	movs r0, #2\n\
	bl PlaySound\n\
	movs r1, #0xa\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0\n\
	bne _080F32EA\n\
	movs r0, #1\n\
	b _080F32F2\n\
_080F32EA:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	b _080F32F2\n\
_080F32F0:\n\
	movs r0, #0\n\
_080F32F2:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// 0x080f32f8
s16 save_080f32f8(struct GameState* g) {
  // Handle Dpad input
  if (gJoypad[0].field3_0x6 & DPAD_DOWN) {
    PlaySound(SE_CURSOR);
    g->unk_008[1] = (g->unk_008[1] + 1) % 3;
  }
  if (gJoypad[0].field3_0x6 & DPAD_UP) {
    PlaySound(SE_CURSOR);
    g->unk_008[1] = (g->unk_008[1] + 2) % 3;
  }

  {
    // Draw the cursor
    const char* s = STRING(STR_CURSOR);  // ▷
    s32 no_left_mugshot = 0;
    if ((&gTextWindow.text)->mugshotRight || (&gTextWindow.text)->mugshot == NO_MUGSHOT) {
      no_left_mugshot = 1;
    }
    PrintString(s, 8 - (no_left_mugshot * 7), (&gTextWindow.text)->y8 + (g->unk_008[1] * 2));  // ▷
  }

  // Handle A/B input
  if (gJoypad[0].pressed & B_BUTTON) {
    PlaySound(SE_NO);
    return -2;
  }
  if (gJoypad[0].pressed & A_BUTTON) {
    PlaySound(SE_YES);
    return g->unk_008[1] + 1;
  }
  return 0;
}

/**
 * @brief セーブデータの1行分のテキストを描画する
 * @param idx Save sector index (0..)
 * @param rank 0: F, 1: E, 2: D, 3: C, 4: B, 5: A, 6: S
 * @param playTime プレイ時間 (フレーム単位)
 * @param lap 何周目か (0: 1周目, 1: 2周目, ...)
 * @param mode 0: Normal, 1: Hardmode, 2: Ultimate
 * @param y8 描画先のy座標 (タイル単位)
 * @details ▷${idx+1} レベル${rank} ${playTime} ${lap} ${mode}, e.g.  ▷1 レベルS 01:21'20 2 H
 * @note ゲーム内で強制セーブする時 は PrintSaveDataRowText ?
 * @note 0x080F33B8
 */
NAKED void PrintSaveDataRow(s32 idx, u8 rank, u32 playTime, u8 lap, u8 mode, u8 y8) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	mov r8, r2\n\
	ldr r2, [sp, #0x24]\n\
	ldr r4, [sp, #0x28]\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	mov sl, r1\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	mov sb, r3\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	str r2, [sp]\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	movs r2, #0\n\
	ldr r0, _080F357C @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r3, r0, #0\n\
	cmp r1, #0\n\
	bne _080F33F6\n\
	ldrb r0, [r3, #4]\n\
	cmp r0, #1\n\
	bne _080F33F8\n\
_080F33F6:\n\
	movs r2, #1\n\
_080F33F8:\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	movs r0, #9\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	ldrb r0, [r3, #5]\n\
	adds r0, r4, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldr r7, _080F3580 @ =StringOfsTable\n\
	adds r0, r6, #0\n\
	adds r0, #0x1f\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	ldr r6, _080F3584 @ =gStringData\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	mov r0, sl\n\
	adds r0, #0x28\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #2\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	ldr r1, _080F3588 @ =0x0020F580\n\
	mov r0, r8\n\
	bl __udivsi3\n\
	adds r0, #0x1e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #7\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	ldr r1, _080F358C @ =0x00034BC0\n\
	mov r0, r8\n\
	bl __udivsi3\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	adds r0, #0x1e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #8\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	ldrh r0, [r7, #0xe]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #9\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	ldr r1, _080F3590 @ =0x00008CA0\n\
	mov r0, r8\n\
	bl __udivsi3\n\
	movs r1, #6\n\
	bl __umodsi3\n\
	adds r0, #0x1e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #0xa\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #4\n\
	mov r0, r8\n\
	bl __udivsi3\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	adds r0, #0x1e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #0xb\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	ldrh r0, [r7, #0x10]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #0xc\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	movs r1, #0x96\n\
	lsls r1, r1, #2\n\
	mov r0, r8\n\
	bl __udivsi3\n\
	movs r1, #6\n\
	bl __umodsi3\n\
	adds r0, #0x1e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #0xd\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	mov r0, r8\n\
	movs r1, #0x3c\n\
	bl __udivsi3\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	adds r0, #0x1e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #0xe\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	beq _080F3560\n\
	cmp r0, #9\n\
	bls _080F3542\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, #0x3c\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #0x10\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
_080F3542:\n\
	mov r0, sb\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, #0x3c\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r6\n\
	adds r1, r5, #0\n\
	adds r1, #0x11\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
_080F3560:\n\
	ldr r0, [sp]\n\
	cmp r0, #1\n\
	bne _080F3594\n\
	ldr r0, _080F3580 @ =StringOfsTable\n\
	ldrh r0, [r0, #6]\n\
	ldr r1, _080F3584 @ =gStringData\n\
	adds r0, r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x12\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
	b _080F35AC\n\
	.align 2, 0\n\
_080F357C: .4byte gTextWindow+8\n\
_080F3580: .4byte StringOfsTable\n\
_080F3584: .4byte gStringData\n\
_080F3588: .4byte 0x0020F580\n\
_080F358C: .4byte 0x00034BC0\n\
_080F3590: .4byte 0x00008CA0\n\
_080F3594:\n\
	ldr r0, [sp]\n\
	cmp r0, #2\n\
	bne _080F35AC\n\
	ldr r0, _080F35BC @ =StringOfsTable\n\
	ldrh r0, [r0, #8]\n\
	ldr r1, _080F35C0 @ =gStringData\n\
	adds r0, r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x12\n\
	adds r2, r4, #0\n\
	bl PrintString\n\
_080F35AC:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F35BC: .4byte StringOfsTable\n\
_080F35C0: .4byte gStringData\n\
 .syntax divided\n");
}
