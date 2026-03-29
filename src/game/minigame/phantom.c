#include "game.h"
#include "global.h"
#include "minigame.h"

NAKED void phantomMinigame_080fbddc(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, _080FBE14 @ =0x00000DCC\n\
	adds r4, r4, r0\n\
	ldr r0, _080FBE18 @ =0x0810E2B8\n\
	movs r1, #1\n\
	movs r2, #0\n\
	bl PrintUnicodeString\n\
	ldr r0, [r4, #0x34]\n\
	movs r1, #0xc\n\
	movs r2, #0\n\
	bl minigame_str_080e9d04\n\
	ldr r0, _080FBE1C @ =0x0810E2C0\n\
	movs r1, #0xf\n\
	movs r2, #0\n\
	bl PrintUnicodeString\n\
	ldr r0, [r4, #0x3c]\n\
	movs r1, #0x1c\n\
	movs r2, #0\n\
	bl minigame_str_080e9d04\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080FBE14: .4byte 0x00000DCC\n\
_080FBE18: .4byte Unicode_SCORE_0810e2b8\n\
_080FBE1C: .4byte Unicode_HI_SCORE_0810e2c0\n\
 .syntax divided\n");
}

INCASM("asm/minigame/phantom.inc");

void phantomMinigame_080fc13c(struct GameState* p);
void phantomMinigame_080fc1b8(struct GameState* p);
void phantomMinigame_080fc390(struct GameState* p);

const GameLoopFunc PhantomMinigameLoops[3] = {
    phantomMinigame_080fc13c,
    phantomMinigame_080fc1b8,
    phantomMinigame_080fc390,
};

bool32 exitPhantomMinigame(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  gSystemSavedataManager.minigameHiscores[MINIGAME_PHANTOM] = s->unk_3c;
  SaveSystemData();
  return FALSE;
}
