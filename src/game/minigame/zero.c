#include "game.h"
#include "global.h"
#include "minigame.h"
#include "text.h"

const Coords32 Coord_ARRAY_08386af8[6];
const Coords32 Coord_ARRAY_08386b28[6];
struct Enemy* FUN_0809aff0(struct Entity* e, struct Coord* c, u8 a2, u8 a3);
extern const u8 Unicode_HI_SCORE_0810e250[];
extern const u8 Unicode_SCORE_0810e248[];

INCASM("asm/minigame/zero_a.inc");

bool32 zeroMinigamePhase1(struct GameState* g) {
  struct MinigameState* s = &(g->sceneState).mg;
  u8 b1[8];
  u8 b2[12];
  struct Coord c;
  u8 scrolled;
  *(s32*)&s->unk_18 += 1;
  if (*(s32*)&s->unk_30 > 0x3BFFF) {
    (g->unk_0dc4).x += -0x3C000;
    *(s32*)&s->unk_30 += -0x3C000;
    ((struct Entity*)s->mg_unk_14)->coord.x += -0x3C000;
    scrolled = 1;
  } else {
    scrolled = 0;
  }
  s->unk_0d = scrolled;
  *(u16*)s->unk_00 += 1;
  if (((struct Entity*)s->mg_unk_14)->mode[0] <= 1 && *(s16*)s->unk_00 % g->unk_006 == 0) {
    struct Enemy* e;
    u16 n = *(u16*)&s->unk_0e;
    if ((n + 1) % 10 == 0) {
      u32 r;
      {
        u8* base = (u8*)&gGameState;
        u32 ofs = 0x626c;
        u32* seedp;
        asm("" : "+r"(base));
        asm("" : "+r"(ofs));
        seedp = (u32*)(base + ofs);
        *seedp = *seedp * 0x41C64E6D + 0x3039;
        r = ((*seedp >> 16) & 1) + 2;
      }
      g->unk_008[0] = r;
      if (r & 1) {
        s32 cy;
        c.x = Coord_ARRAY_08386af8[g->unk_008[0]].x + 0x2EE000;
        cy = Coord_ARRAY_08386af8[g->unk_008[0]].y + (0xA0 << 8);
        asm volatile("@ay");
        c.y = cy;
      } else {
        s32 cy;
        c.x = Coord_ARRAY_08386af8[g->unk_008[0]].x + 0x2DF000;
        cy = Coord_ARRAY_08386af8[g->unk_008[0]].y + (0xA0 << 8);
        c.y = cy;
      }
      e = FUN_0809aff0((struct Entity*)s, &c, 0, 1);
    } else {
      if ((u16)(n % 10) != 0) {
        {
          u8* base = (u8*)&gGameState;
          u32 ofs = 0x626c;
          u32* seedp;
          asm("" : "+r"(base));
          asm("" : "+r"(ofs));
          seedp = (u32*)(base + ofs);
          *seedp = *seedp * 0x41C64E6D + 0x3039;
          g->unk_008[0] = (*seedp >> 16) % 6;
        }
      }
      if (g->unk_008[0] & 1) {
        register s32 cx asm("r0");
        register s32 ka asm("r2");
        cx = Coord_ARRAY_08386af8[g->unk_008[0]].x;
        ka = 0x2EE000;
        asm volatile("@bx" : "+l"(ka));
        cx += ka;
        c.x = cx;
      } else {
        register s32 cx asm("r0");
        register s32 k asm("r3");
        cx = Coord_ARRAY_08386af8[g->unk_008[0]].x;
        k = 0x2DF000;
        asm volatile("@bx2" : "+l"(k));
        cx += k;
        c.x = cx;
      }
      {
        register struct Coord* cp asm("r2");
        cp = &c;
        asm volatile("" : "+l"(cp));
        cp->y = Coord_ARRAY_08386af8[g->unk_008[0]].y + (0xA0 << 8);
        {
          register struct Coord* a1 asm("r1");
          a1 = cp;
          asm volatile("" : "+l"(a1));
          e = FUN_0809aff0((struct Entity*)s, a1, 0, 0);
        }
      }
    }
    if (e != NULL) {
      u16 t;
      if (g->unk_008[0] & 1) {
        register s32 ux asm("r0");
        ux = Coord_ARRAY_08386b28[g->unk_008[0]].x;
        asm volatile("" : "+l"(ux));
        (e->s).unk_coord.x = ux + 0x2EE000;
      } else {
        register s32 ux asm("r0");
        ux = Coord_ARRAY_08386b28[g->unk_008[0]].x;
        asm volatile("" : "+l"(ux));
        (e->s).unk_coord.x = ux + 0x2DF000;
      }
      (e->s).unk_coord.y = Coord_ARRAY_08386b28[g->unk_008[0]].y + (0xA0 << 8);
      t = (*(u16*)&s->unk_0e += 1);
      if (t <= 0x13) {
        g->unk_006 = 0x58;
      } else if (t <= 0x27) {
        g->unk_006 = 0x4c;
      } else {
        g->unk_006 = 0x40;
      }
    }
  }
  memcpy(b1, Unicode_SCORE_0810e248, 6);
  PrintJISString(b1, 1, 0);
  {
    u32 score = *(u16*)s->unk_38;
    PrintMinigameNumber(score, 0xa, 0);
    if (score > (u32)s->unk_3c) {
      s->unk_3c = score;
      if (*(u16*)&s->unk_38[2] == 0) {
        *(u16*)&s->unk_38[2] = 1;
        PlaySound(0x9c << 1);
      }
    }
  }
  memcpy(b2, Unicode_HI_SCORE_0810e250, 9);
  PrintJISString(b2, 0xf, 0);
  {
    register u32 hs0 asm("r4");
    u32 hs;
    hs0 = s->unk_3c;
    asm volatile("add %0, %1, #0" : "=&l"(hs) : "l"(hs0));
    PrintMinigameNumber(hs, 0x1b, 0);
  }
  {
    u8 c0 = s->unk_0c;
    if (c0 == 0) {
      *(u16*)&s->unk_04 += 1;
      *(u16*)&s->unk_06 = c0;
    }
  }
  return 1;
}

INCASM("asm/minigame/zero_b.inc");

void zeroMinigamePhase0(struct GameState* g);
bool32 zeroMinigamePhase1(struct GameState* g);
void zeroMinigamePhase2(struct GameState* g);

const GameLoopFunc ZeroMinigameLoops[3] = {
    (GameLoopFunc)zeroMinigamePhase0,
    (GameLoopFunc)zeroMinigamePhase1,
    (GameLoopFunc)zeroMinigamePhase2,
};

// clang-format off
const Coords32 Coord_ARRAY_08386af8[6] = {
    {-0x2000, 0x1000}, {+0x2000, 0x1000},
    {-0x2000, 0x4800}, {+0x2000, 0x4800},
    {-0x2000, 0x8000}, {+0x2000, 0x8000},
};
// clang-format on

// clang-format off
const Coords32 Coord_ARRAY_08386b28[6] = {
    {+0x2800, 0x1000}, {-0x2800, 0x1000},
    {+0x1800, 0x4800}, {-0x1800, 0x4800},
    {+0x2800, 0x8000}, {-0x2800, 0x8000},
};
// clang-format on

// 0x080f9848
bool32 exitZeroMinigame(struct GameState* g) {
  struct MinigameState* s = &(g->sceneState).mg;
  if (s->unk_06 == 0) {
    *((s16*)s->unk_00) = 2;
    s->unk_06++;
    return TRUE;
  }
  if (s->unk_06 == 1) {
    if ((*((s16*)s->unk_00) <= 0 || (--(*((s16*)s->unk_00)) <= 0))) {
      if (s->unk_3c > gSystemSavedata.minigameHiscores[MINIGAME_ZERO]) {
        gSystemSavedata.minigameHiscores[MINIGAME_ZERO] = s->unk_3c;
        SaveSystemData();
      }
      return FALSE;
    }
  }
  return TRUE;
}
