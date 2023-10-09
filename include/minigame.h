#ifndef GUARD_RMZ3_MINIGAME_H
#define GUARD_RMZ3_MINIGAME_H

#include "gba/gba.h"

struct GameState;

typedef void (*MinigameLoopFunc)(struct GameState*);

struct MinigameState {
  u8 unk_00[4];
  s16 unk_04;
  u8 unk_06[6];
  u8 unk_0c;
  u8 unk_0d[3];
  u8 unk_10[240];
};

void MinigameLoop_Main(struct GameState* p);
void MinigameLoop_ExitMinigame(struct GameState* p);

void initZeroMinigame(struct GameState* p);
void initCielMinigame(struct GameState* p);
void initCopyXMinigame(struct GameState* p);
void initHarpuiaMinigame(struct GameState* p);
void initFefnirMinigame(struct GameState* p);
void initLeviathanMinigame(struct GameState* p);
void initPhantomMinigame(struct GameState* p);

void zeroMinigame(struct GameState* p);
void cielMinigame(struct GameState* p);
void copyXMinigame(struct GameState* p);
void harpuiaMinigame(struct GameState* p);
void fefnirMinigame(struct GameState* p);
void leviathanMinigame(struct GameState* p);
void phantomMinigame(struct GameState* p);

void exitZeroMinigame(struct GameState* p);
void exitCielMinigame(struct GameState* p);
void exitCopyXMinigame(struct GameState* p);
void exitHarpuiaMinigame(struct GameState* p);
void exitFefnirMinigame(struct GameState* p);
void exitLeviathanMinigame(struct GameState* p);
void exitPhantomMinigame(struct GameState* p);

void zeroMinigamePhase0(struct GameState* p);
void zeroMinigamePhase1(struct GameState* p);
void zeroMinigamePhase2(struct GameState* p);

void copyx_minigame_080fa560(struct GameState* p);
void copyx_minigame_080fa62c(struct GameState* p);
void copyx_minigame_080fa764(struct GameState* p);

void harpuia_minigame_080fab10(struct GameState* p);
void harpuia_minigame_080fabe8(struct GameState* p);
void harpuia_minigame_080faebc(struct GameState* p);

void fefnir_minigame_080fb2d8(struct GameState* p);
void fefnir_minigame_080fb354(struct GameState* p);
void fefnir_minigame_080fb48c(struct GameState* p);

void leviathan_minigame_080fbba0(struct GameState* p);
void leviathan_minigame_080fbc30(struct GameState* p);
void leviathan_minigame_080fbcdc(struct GameState* p);

void phantomMinigame_080fc13c(struct GameState* p);
void phantomMinigame_080fc1b8(struct GameState* p);
void phantomMinigame_080fc390(struct GameState* p);

#endif  // GUARD_RMZ3_MINIGAME_H
