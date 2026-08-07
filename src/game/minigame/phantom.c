#include "game.h"
#include "global.h"
#include "vfx.h"
#include "minigame.h"
#include "text.h"

void CreateIronStar(struct Entity* e, s32 x, s32 y);
void FUN_080d91b4(void* m, s32 x, s32 y, u8 r3);

extern const u8 Unicode_SCORE_0810e2b8[];
extern const u8 Unicode_HI_SCORE_0810e2c0[];


const GameLoopFunc PhantomMinigameLoops[3];
void MinigamePhantom_DrawScoreHiscore(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;

  PrintJISString(Unicode_SCORE_0810e2b8, 1, 0);
  PrintMinigameNumber(s->unk_34, 12, 0);
  PrintJISString(Unicode_HI_SCORE_0810e2c0, 15, 0);
  PrintMinigameNumber(s->unk_3c, 28, 0);
}

INCASM("asm/minigame/phantom_a.inc");

bool32 phantomMinigame(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  register bool32 r asm("r8");
  r = ((MinigameFunc)PhantomMinigameLoops[mg[0]])(g);
  if (*(s32*)(mg + 0x34) > 0x1869F) {
    *(s32*)(mg + 0x34) = 0x1869F;
  }
  if (*(s32*)(mg + 0x34) > *(s32*)(mg + 0x3c)) {
    u8* f = (u8*)g + 0xEA3;
    if (*f == 0) {
      *f = 1;
      PlaySound(0x138);
    } else {
      PlaySound(0x137);
    }
    *(s32*)(mg + 0x3c) = *(s32*)(mg + 0x34);
  } else if (*(s32*)(mg + 0x38) != *(s32*)(mg + 0x34)) {
    PlaySound(0x137);
  }
  *(s32*)(mg + 0x38) = *(s32*)(mg + 0x34);
  MinigamePhantom_DrawScoreHiscore(g);
  {
    register s32 i asm("r5");
    u8* n;
    u8* n0;
    i = 0;
    n0 = mg + 0xd5;
    asm volatile("add %0, %1, #0" : "=&l"(n) : "l"(n0));
    if (i < *n) {
      register struct Sprite* sp asm("r4");
      sp = (struct Sprite*)(mg + 0x44);
      do {
        void (*f)(struct Sprite*, struct DrawPivot*) = sp->fn;
        register struct Sprite* a0 asm("r0");
        a0 = sp;
        asm("" : "+r"(mg));
        f(a0, (struct DrawPivot*)(mg + 0xbc));
        sp = (struct Sprite*)((u8*)sp + 0x20);
        i++;
      } while (i < *n);
    }
    asm volatile("" ::"r"(mg));
  }
  return r;
}

bool32 phantomMinigame_080fc13c(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  s32 t;
  switch (mg[1]) {
    case 0:
      *(s32*)(mg + 0x40) = 0x3c;
      mg[1]++;
      /* fallthrough */
    case 1:
      t = *(s32*)(mg + 0x40) - 1;
      *(s32*)(mg + 0x40) = t;
      if (t != 0) {
        break;
      }
      mg[1]++;
      break;
    case 2:
      PlaySound(0x1d);
      *(struct VFX**)(mg + 0xc) = (struct VFX*)CreateMissionAlert(0);
      mg[1]++;
      /* fallthrough */
    case 3:
      if (*(u8*)(*(u8**)(mg + 0xc) + 0xc) > 1) {
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
  return 1;
}

bool32 phantomMinigame_080fc1b8(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  register s32 z asm("r4");
  struct Entity* e;
  s32* base;

  {
    struct KeyState* jp = gJoypad;
    u16 kv = jp->input;
    z = 0;
    *(u16*)(mg + 0x10) = kv;
    *(u16*)(mg + 0x12) = jp->pressed;
  }
  e = *(struct Entity**)(mg + 8);
  {
    register s32 k asm("r1");
    k = 0xDC4;
    asm("" : "+l"(k));
    base = (s32*)((u8*)g + k);
    asm("" : : "l"(k));
  }

  if (e->coord.x > *base) {
    *(s32*)(mg + 0x30) += e->coord.x - *base;
    *(s32*)(mg + 0x04) += e->coord.x - *base;
    *(s32*)(mg + 0x1c) += e->coord.x - *base;
    *(s32*)(mg + 0x24) += e->coord.x - *base;

    if (*(s32*)(mg + 0x24) >= *(s32*)(mg + 0x28)) {
      s32 t = *(s32*)(mg + 0x28) - 0x100;
      s32 a;
      u32 r;
      *(s32*)(mg + 0x28) = t;
      if (t < 0x3C00) {
        *(s32*)(mg + 0x28) = 0x3C00;
      }
      a = *(s32*)(mg + 4) + 0xA7000;
      r = RNG_0202f388 * 0x343FD + 0x269EC3;
      r <<= 1;
      RNG_0202f388 = r >> 1;
      CreateIronStar((struct Entity*)mg, a, ((r << 1) >> 0x12) + 0x5D000);
      *(s32*)(mg + 0x24) = z;
    }

    if (*(s32*)(mg + 0x1c) >= *(s32*)(mg + 0x20)) {
      {
        s32 h = *(u16*)(mg + 0x2c) + 1;
        s32 w;
        s32 lim;
        u32 r;
        *(u16*)(mg + 0x2c) = h;
        if ((s16)h > 0x200) {
          *(u16*)(mg + 0x2c) = 0x200;
        }
        lim = *(s32*)(mg + 0x20) - 0x100;
        *(s32*)(mg + 0x20) = lim;
        if (lim < 0x5000) {
          *(s32*)(mg + 0x20) = 0x5000;
        }
        w = *(s32*)(mg + 0x18) - 0x2000;
        r = RNG_0202f388 * 0x343FD + 0x269EC3;
        r <<= 1;
        RNG_0202f388 = r >> 1;
        w += (r << 1) >> 0x12;
        *(s32*)(mg + 0x18) = w;
        if (w < 0x5E000) {
          *(s32*)(mg + 0x18) = 0x5E000;
        }
        if (*(s32*)(mg + 0x18) > 0x63000) {
          *(s32*)(mg + 0x18) = 0x63000;
        }
        FUN_080d91b4(mg, *(s32*)(mg + 4) + 0xA7000, *(s32*)(mg + 0x18), 0);
        mg[0xd4]++;
        *(s32*)(mg + 0x1c) = 0;
      }
    }

    {
      s32 v = *(s32*)(mg + 4);
      if (v % 0xF000 < v) {
        *(s32*)(mg + 0x14) = -0xF000;
      } else {
        *(s32*)(mg + 0x14) = 0;
      }
      *(s32*)(mg + 4) = v % 0xF000;
    }
    *(s32*)((u8*)g + 0xDC4) = 0x9D800;
    *(s32*)((u8*)g + 0xDC4) = *(s32*)(mg + 4) + 0x9D800;
    if (*(s32*)(mg + 0x30) > 0x1000) {
      *(s32*)(mg + 0x30) -= 0x1000;
      *(s32*)(mg + 0x34) += 1;
    }
  } else {
    *(s32*)(mg + 0x14) = z;
  }

  if ((*(struct Entity**)(mg + 8))->coord.y > 0x69000 || mg[0xd5] == 0) {
    u8* q = mg + 0xd6;
    u8 zb = 0;
    *q = 1;
    mg[0] = mg[0] + 1;
    mg[1] = zb;
    mg[2] = zb;
    mg[3] = zb;
  }
  return 1;
}

bool32 phantomMinigame_080fc390(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  u16 z = 0;
  s->unk_10 = z;
  s->unk_12 = z;
  switch (s->unk_00[1]) {
    case 0:
      FadeOutBGM(0xA8);
      *(s32*)&s->unk_40[0] = 0x3C;
      s->unk_00[1]++;
    case 1:
      *(s32*)&s->unk_40[0] -= 1;
      if (*(s32*)&s->unk_40[0] != 0) {
        goto end1;
      }
      goto inc;
    case 2:
      *(struct VFX**)&s->unk_0c = (struct VFX*)CreateMissionAlert(4);
      s->unk_00[1]++;
    case 3:
      if (((*(struct VFX**)&s->unk_0c)->s).mode[0] <= 1) {
        return 1;
      }
    inc:
      s->unk_00[1]++;
      break;
    case 4:
      gGameState.frames = 0x40;
      s->unk_00[1]++;
    case 5:
      if (gGameState.frames != 0x20) {
        break;
      }
      return 0;
  }
end1:
  return 1;
}

bool32 phantomMinigame_080fc13c(struct GameState* p);
bool32 phantomMinigame_080fc1b8(struct GameState* p);
bool32 phantomMinigame_080fc390(struct GameState* p);

const GameLoopFunc PhantomMinigameLoops[3] = {
    (GameLoopFunc)phantomMinigame_080fc13c,
    (GameLoopFunc)phantomMinigame_080fc1b8,
    (GameLoopFunc)phantomMinigame_080fc390,
};

bool32 exitPhantomMinigame(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  gSystemSavedata.minigameHiscores[MINIGAME_PHANTOM] = s->unk_3c;
  SaveSystemData();
  return FALSE;
}
