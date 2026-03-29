#include "game.h"
#include "global.h"
#include "minigame.h"

NAKED void initCopyXMinigame(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	str r0, [sp, #0xc]\n\
	ldr r1, _080FA510 @ =0x00000DCC\n\
	adds r7, r0, r1\n\
	ldr r2, _080FA514 @ =0x00000DC4\n\
	adds r1, r0, r2\n\
	movs r0, #0xb4\n\
	lsls r0, r0, #9\n\
	str r0, [r1]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #8\n\
	str r0, [r1, #4]\n\
	movs r0, #4\n\
	bl ResetLandscape\n\
	movs r5, #0x8c\n\
	lsls r5, r5, #1\n\
	ldr r0, _080FA518 @ =gStaticMotionGraphics\n\
	mov r8, r0\n\
	ldr r1, _080FA51C @ =wStaticGraphicTilenums\n\
	mov sb, r1\n\
	ldrh r1, [r1, #0x1c]\n\
	ldr r2, _080FA520 @ =0x085D7A10\n\
	ldrh r0, [r2, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	adds r0, r2, #0\n\
	bl LoadGraphic\n\
	ldr r1, _080FA524 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r1\n\
	ldr r6, _080FA528 @ =wStaticMotionPalIDs\n\
	ldrh r1, [r6, #0x1c]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	add r1, sl\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r4, _080FA52C @ =0x0000071C\n\
	mov r1, r8\n\
	adds r0, r4, r1\n\
	mov r1, sb\n\
	adds r1, #0xb6\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	adds r0, r6, #0\n\
	adds r0, #0xb6\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0xe6\n\
	lsls r4, r4, #3\n\
	mov r1, r8\n\
	adds r0, r4, r1\n\
	mov r1, sb\n\
	adds r1, #0xb8\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	adds r0, r6, #0\n\
	adds r0, #0xb8\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _080FA530 @ =0x0000076C\n\
	mov r1, r8\n\
	adds r0, r4, r1\n\
	mov r1, sb\n\
	adds r1, #0xbe\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	adds r0, r6, #0\n\
	adds r0, #0xbe\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r0, #0\n\
	mov r1, sb\n\
	strh r0, [r1, #0x1c]\n\
	movs r0, #7\n\
	strh r0, [r6, #0x1c]\n\
	ldr r2, _080FA520 @ =0x085D7A10\n\
	ldrh r1, [r2, #6]\n\
	lsrs r1, r1, #6\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	subs r1, r0, r1\n\
	adds r0, r2, #0\n\
	bl LoadGraphic\n\
	ldrh r1, [r6, #0x1c]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r5, _080FA534 @ =0x00001310\n\
	mov r1, r8\n\
	adds r0, r5, r1\n\
	movs r4, #0xf4\n\
	lsls r4, r4, #1\n\
	mov r2, sb\n\
	adds r1, r2, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	adds r4, r6, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	add r0, sp, #4\n\
	movs r1, #0\n\
	bl CreateMinigameIcon_1\n\
	movs r1, #0xb9\n\
	lsls r1, r1, #1\n\
	mov r2, sb\n\
	strh r1, [r2]\n\
	movs r0, #0xe\n\
	strh r0, [r6]\n\
	mov r2, r8\n\
	ldrh r0, [r2, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	bl LoadGraphic\n\
	ldrh r1, [r6]\n\
	ldr r2, _080FA524 @ =gStaticMotionGraphics+12\n\
	ldrb r0, [r2, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r2, #0\n\
	bl LoadPalette\n\
	movs r4, #0x9f\n\
	lsls r0, r4, #1\n\
	add sb, r0\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #1\n\
	mov r2, sb\n\
	strh r1, [r2]\n\
	adds r6, r6, r0\n\
	movs r0, #9\n\
	strh r0, [r6]\n\
	lsls r4, r4, #4\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	adds r4, r4, r0\n\
	add r8, r4\n\
	mov r2, r8\n\
	ldrh r0, [r2, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	bl LoadGraphic\n\
	ldr r1, _080FA524 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r1\n\
	ldrh r1, [r6]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #9\n\
	str r0, [sp, #4]\n\
	movs r0, #0xf6\n\
	lsls r0, r0, #8\n\
	str r0, [sp, #8]\n\
	adds r0, r7, #0\n\
	add r1, sp, #4\n\
	movs r2, #0\n\
	bl CreatePlayerCopyX\n\
	movs r1, #0\n\
	add r6, sp, #4\n\
	movs r5, #0x80\n\
	lsls r5, r5, #5\n\
_080FA4A8:\n\
	adds r4, r1, #1\n\
	movs r0, #0xec\n\
	lsls r0, r0, #9\n\
	subs r0, r0, r5\n\
	str r0, [sp, #4]\n\
	movs r0, #0x94\n\
	lsls r0, r0, #9\n\
	str r0, [r6, #4]\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp]\n\
	adds r0, r7, #0\n\
	add r1, sp, #4\n\
	movs r2, #2\n\
	adds r3, r7, #0\n\
	adds r3, #0xc\n\
	bl FUN_080c82b8\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r5, r5, r2\n\
	adds r1, r4, #0\n\
	cmp r1, #2\n\
	ble _080FA4A8\n\
	movs r4, #0\n\
	movs r0, #3\n\
	strb r0, [r7, #0xc]\n\
	strh r4, [r7]\n\
	movs r0, #0x78\n\
	strh r0, [r7, #2]\n\
	str r4, [r7, #0x20]\n\
	strh r4, [r7, #4]\n\
	strh r4, [r7, #6]\n\
	str r4, [r7, #0x18]\n\
	str r4, [r7, #0x1c]\n\
	ldr r0, _080FA538 @ =gSystemSavedataManager\n\
	ldr r0, [r0, #0x2c]\n\
	str r0, [r7, #0x24]\n\
	strh r4, [r7, #0xe]\n\
	movs r0, #0xb3\n\
	bl playBGM\n\
	ldr r0, [sp, #0xc]\n\
	strh r4, [r0, #4]\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080FA510: .4byte 0x00000DCC\n\
_080FA514: .4byte 0x00000DC4\n\
_080FA518: .4byte gStaticMotionGraphics\n\
_080FA51C: .4byte wStaticGraphicTilenums\n\
_080FA520: .4byte 0x085D7A10\n\
_080FA524: .4byte gStaticMotionGraphics+12\n\
_080FA528: .4byte wStaticMotionPalIDs\n\
_080FA52C: .4byte 0x0000071C\n\
_080FA530: .4byte 0x0000076C\n\
_080FA534: .4byte 0x00001310\n\
_080FA538: .4byte gSystemSavedataManager\n\
 .syntax divided\n");
}

bool32 copyx_minigame_080fa560(struct GameState* g);
bool32 copyx_minigame_080fa62c(struct GameState* g);
bool32 copyx_minigame_080fa764(struct GameState* g);

bool32 copyXMinigame(struct GameState* g) {
  static const MinigameFunc sUpdates[3] = {
      copyx_minigame_080fa560,
      copyx_minigame_080fa62c,
      copyx_minigame_080fa764,
  };  // 0x08386b80

  struct MinigameState* s = &(g->sceneState).mg;
  return (sUpdates[s->unk_04])(g);
}

INCASM("asm/minigame/copy_x.inc");

bool32 exitCopyXMinigame(struct GameState* g) {
  struct MinigameState* s = &(g->sceneState).mg;
  if (s->unk_06 == 0) {
    *((s16*)s->unk_00) = 2;
    s->unk_06++;
    return TRUE;
  }
  if (s->unk_06 == 1) {
    if ((*((s16*)s->unk_00) <= 0 || (--(*((s16*)s->unk_00)) <= 0))) {
      if (s->unk_24 > gSystemSavedataManager.minigameHiscores[MINIGAME_COPY_X]) {
        gSystemSavedataManager.minigameHiscores[MINIGAME_COPY_X] = s->unk_24;
        SaveSystemData();
      }
      return FALSE;
    }
  }
  return TRUE;
}
