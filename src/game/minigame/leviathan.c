#include "game.h"
#include "global.h"
#include "vfx.h"
#include "text.h"
#include "minigame.h"
#include "text.h"

void FUN_08099fb8(struct Entity* e, s32 y, u8 n, u8 w);
void leviathan_minigame_080fb5dc(struct GameState* g);
struct Enemy* FUN_0809a02c(void* parent, u8 n);
bool32 leviathan_minigame_080fb66c(struct GameState* g);

extern const u8 Unicode_SCORE_0810e298[];
extern const u8 Unicode_HI_SCORE_0810e2a0[];

// 0x080fb550

const GameLoopFunc LeviathanMinigameLoops[3];
extern const u8 Unicode_REST_0810e2ac[];
const u8 u8_ARRAY_08386bb0[16];
void MinigameLeviathan_DrawScoreHiscore(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;

  PrintJISString(Unicode_SCORE_0810e298, 1, 0);
  PrintMinigameNumber(s->unk_24, 12, 0);
  PrintJISString(Unicode_HI_SCORE_0810e2a0, 15, 0);
  PrintMinigameNumber(s->unk_2c, 28, 0);
}

void leviathan_minigame_080fb594(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;

  PrintJISString(Unicode_REST_0810e2ac, 10, 19);
  PrintMinigameNumber(s->unk_20 / 60 % 60, 18, 19);
  PrintMinigameNumber(s->unk_20 / 3600, 15, 19);
}

void leviathan_minigame_080fb5dc(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  s32 t = *(u16*)(mg + 0x16) - 1;
  *(u16*)(mg + 0x16) = t;
  if ((t << 16) == 0) {
    s32 a;
    u8 b;
    u8 c;
    *(u16*)(mg + 0x16) = *(u16*)(mg + 0x14);
    a = (RANDOM(RNG_0202f388) % 0x5000) + 0x3F000;
    b = RANDOM(RNG_0202f388) & 1;
    c = u8_ARRAY_08386bb0[RANDOM(RNG_0202f388) & 0xF];
    FUN_08099fb8((struct Entity*)mg, a, b, c);
  }
}

INCASM("asm/minigame/leviathan_a.inc");

bool32 leviathanMinigame(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  bool32 r = ((MinigameFunc)LeviathanMinigameLoops[mg[0]])(g);
  leviathan_minigame_080fb594(g);
  if (*(s32*)(mg + 0x24) < 0) {
    *(s32*)(mg + 0x24) = 0;
  } else if (*(s32*)(mg + 0x24) > 0x1869F) {
    *(s32*)(mg + 0x24) = 0x1869F;
  }
  if (*(s32*)(mg + 0x24) > *(s32*)(mg + 0x2c)) {
    u8* f = mg + 0x30;
    if (*f == 0) {
      *f = 1;
      PlaySound(0x138);
    } else {
      PlaySound(0x137);
    }
    *(s32*)(mg + 0x2c) = *(s32*)(mg + 0x24);
  } else if (*(s32*)(mg + 0x28) != *(s32*)(mg + 0x24)) {
    PlaySound(0x137);
  }
  *(s32*)(mg + 0x28) = *(s32*)(mg + 0x24);
  MinigameLeviathan_DrawScoreHiscore(g);
  return r;
}

bool32 leviathan_minigame_080fbba0(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  switch (mg[1]) {
    case 0:
      *((u8*)g + 0xDFF) = 0x3c;
      mg[1]++;
      /* fallthrough */
    case 1: {
      u8* t = mg + 0x33;
      s32 v = *t - 1;
      *t = v;
      if ((v << 24) != 0) {
        break;
      }
      mg[1]++;
      break;
    }
    case 2:
      PlaySound(0x1d);
      *(struct VFX**)(mg + 8) = (struct VFX*)CreateMissionAlert(0);
      mg[1]++;
      /* fallthrough */
    case 3:
      if (*(u8*)(*(u8**)(mg + 8) + 0xc) > 1) {
        u8 t0 = mg[0] + 1;
        u8 z = 0;
        mg[0] = t0;
        mg[1] = z;
        mg[2] = z;
        mg[3] = z;
      }
      break;
  }
  *(u16*)(mg + 0x10) = 0;
  *(u16*)(mg + 0x12) = 0;
  leviathan_minigame_080fb5dc(g);
  return 1;
}

bool32 leviathan_minigame_080fbc30(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  u8* t;
  asm("" : "+r"(mg));
  *(u16*)(mg + 0x10) = gJoypad[0].input;
  *(u16*)(mg + 0x12) = gJoypad[0].pressed;
  t = (u8*)g + 0xDFD;
  asm("" : "+r"(t));
  if (*t != 0) {
    *t = *t - 1;
  } else {
    struct Entity* e = *(struct Entity**)(mg + 0xc);
    if (e == NULL || e->mode[0] > 1) {
      *(struct Enemy**)(mg + 0xc) = FUN_0809a02c(mg, RANDOM(RNG_0202f388) & 1);
    }
    leviathan_minigame_080fb66c(g);
  }
  if (*(s32*)(mg + 0x20) > 0x2A30) {
    *(s32*)(mg + 0x20) = 0x2A30;
  }
  if (*(s32*)(mg + 0x20) != 0) {
    s32 v = *(s32*)(mg + 0x20) - 1;
    *(s32*)(mg + 0x20) = v;
    if (v > 0) {
      return 1;
    }
  }
  {
    u8 t0 = mg[0] + 1;
    u8 z = 0;
    mg[0] = t0;
    mg[1] = z;
    mg[2] = z;
    mg[3] = z;
    *(mg + 0x34) = 1;
    *(s32*)(mg + 0x20) = z;
  }
  return 1;
}

bool32 leviathan_minigame_080fbcdc(struct GameState* g) {
  register u8* mg asm("r4");
  register s32 z asm("r5");
  mg = (u8*)g + 0xDCC;
  z = 0;
  *(u16*)(mg + 0x10) = z;
  *(u16*)(mg + 0x12) = z;
  {
    u8* t = (u8*)g + 0xDFD;
    if (*t != 0) {
      *t = *t - 1;
    }
  }
  leviathan_minigame_080fb5dc(g);
  if (*(s32*)(mg + 0x20) > 0x2A30) {
    *(s32*)(mg + 0x20) = 0x2A30;
  }
  if (*(s32*)(mg + 0x20) <= 0) {
    *(s32*)(mg + 0x20) = z;
  }
  switch (mg[1]) {
    case 0:
      FadeOutBGM(0xB6);
      PlaySound(0xF6);
      *(mg + 0x33) = 0x3C;
      mg[1]++;
      FALLTHROUGH;
    case 1: {
      u8* c = mg + 0x33;
      s32 t = *c - 1;
      *c = t;
      t <<= 24;
      if (t != 0) {
        break;
      }
      goto inc;
    }
    case 2:
      *(void**)(mg + 8) = (void*)CreateMissionAlert(4);
      mg[1]++;
      FALLTHROUGH;
    case 3:
      if ((*(struct Entity**)(mg + 8))->mode[0] <= 1) {
        break;
      }
    inc:
      mg[1]++;
      break;
    case 4:
      gGameState.frames = 0x40;
      mg[1]++;
      FALLTHROUGH;
    case 5:
      if (gGameState.frames != 0x20) {
        break;
      }
      StopSound(0x32);
      return 0;
  }
  return 1;
}

bool32 leviathan_minigame_080fbba0(struct GameState* g);
bool32 leviathan_minigame_080fbc30(struct GameState* g);
bool32 leviathan_minigame_080fbcdc(struct GameState* g);

const GameLoopFunc LeviathanMinigameLoops[3] = {
    (GameLoopFunc)leviathan_minigame_080fbba0,
    (GameLoopFunc)leviathan_minigame_080fbc30,
    (GameLoopFunc)leviathan_minigame_080fbcdc,
};

const u8 u8_ARRAY_08386bb0[16] = {
    2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 5, 5,
};

const u8 u8_ARRAY_08386bc0[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 3, 3, 3, 5,
};

bool32 exitLeviathanMinigame(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  gSystemSavedata.minigameHiscores[MINIGAME_LEVIATHAN] = s->unk_2c;
  SaveSystemData();
  return FALSE;
}
