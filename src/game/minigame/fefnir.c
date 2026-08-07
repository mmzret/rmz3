#include "game.h"
#include "global.h"
#include "vfx.h"
#include "minigame.h"
#include "text.h"

struct Enemy* FUN_08071470(struct Entity* a, struct Entity* e, s32 x, s32 y, u8 n);

extern const u8 Unicode_SCORE_0810e284[];
extern const u8 Unicode_HI_SCORE_0810e28c[];


const GameLoopFunc FefnirMinigameLoops[3];
void MinigameFefnir_DrawScoreHiscore(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;

  PrintJISString(Unicode_SCORE_0810e284, 1, 0);
  PrintMinigameNumber(s->unk_20, 12, 0);
  PrintJISString(Unicode_HI_SCORE_0810e28c, 15, 0);
  PrintMinigameNumber(s->unk_28, 28, 0);
}

INCASM("asm/minigame/fefnir_a.inc");

bool32 fefnirMinigame(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  bool32 r = ((MinigameFunc)FefnirMinigameLoops[mg[0]])(g);
  if (*(s32*)(mg + 0x20) > 0x1869F) {
    *(s32*)(mg + 0x20) = 0x1869F;
  }
  if (*(s32*)(mg + 0x20) > *(s32*)(mg + 0x28)) {
    u8* f = mg + 0x2c;
    if (*f == 0) {
      *f = 1;
      PlaySound(0x138);
    } else {
      PlaySound(0x137);
    }
    *(s32*)(mg + 0x28) = *(s32*)(mg + 0x20);
  } else if (*(s32*)(mg + 0x24) != *(s32*)(mg + 0x20)) {
    PlaySound(0x137);
  }
  *(s32*)(mg + 0x24) = *(s32*)(mg + 0x20);
  MinigameFefnir_DrawScoreHiscore(g);
  return r;
}

bool32 fefnir_minigame_080fb2d8(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  s32 t;
  switch (mg[1]) {
    case 0:
      *(s32*)(mg + 0x1c) = 0x3c;
      mg[1]++;
      /* fallthrough */
    case 1:
      t = *(s32*)(mg + 0x1c) - 1;
      *(s32*)(mg + 0x1c) = t;
      if (t != 0) {
        break;
      }
      mg[1]++;
      break;
    case 2:
      PlaySound(0x1d);
      *(struct VFX**)(mg + 0x14) = (struct VFX*)CreateMissionAlert(0);
      mg[1]++;
      /* fallthrough */
    case 3:
      if (*(u8*)(*(u8**)(mg + 0x14) + 0xc) > 1) {
        u8 t0 = mg[0] + 1;
        u8 z = 0;
        mg[0] = t0;
        mg[1] = z;
        mg[2] = z;
        mg[3] = z;
      }
      break;
  }
  *(u16*)(mg + 0x18) = 0;
  *(u16*)(mg + 0x1a) = 0;
  return 1;
}

bool32 fefnir_minigame_080fb354(struct GameState* g) {
  register u8* mg asm("r6");
  register struct Enemy** arr asm("sb");
  register u8* c asm("r8");
  register u32* rp asm("ip");
  s32 dirty;
  register u8* h asm("r5");
  mg = (u8*)g + 0xDCC;
  *(u16*)(mg + 0x18) = gJoypad[0].input;
  *(u16*)(mg + 0x1a) = gJoypad[0].pressed;
  dirty = 0;
  {
    register u32 k asm("r2");
    k = 0xDD0;
    asm("" : "+r"(k));
    arr = (struct Enemy**)(k + (u32)g);
  }
  {
    register struct Enemy* zero asm("r3");
    struct Enemy** q;
    s32 n;
    zero = NULL;
    {
      register u32 k2 asm("r2");
      k2 = 0xDD0;
      asm("" : "+r"(k2));
      q = (struct Enemy**)((u8*)g + k2);
    }
    n = 3;
    do {
      struct Enemy* e = *q;
      if (e != NULL && (e->s).mode[0] > 1) {
        *q = zero;
        dirty = 1;
      }
      q++;
      n--;
    } while (n >= 0);
  }
  if (dirty != 0) {
    u8* f;
    u8 z;
    asm volatile("add %0, %1, #0\n\tadd %0, #0x2f" : "=&l"(f) : "l"(mg));
    z = 0;
    *f = 1;
    mg[0]++;
    mg[1] = z;
    mg[2] = z;
    mg[3] = z;
  }
  {
    u8* t;
    u8 cv;
    asm volatile("add %0, %1, #0\n\tadd %0, #0x2d" : "=&l"(t) : "l"(mg));
    cv = *t;
    c = t;
    if (cv != 0) {
      goto done;
    }
  }
  {
    register u32 raw asm("r1");
    register u32 K asm("r3");
    register u32 C asm("r2");
    register u32 s1 asm("r4");
    register s32 i asm("r2");
    register s32 start asm("r7");
    rp = &RNG_0202f388;
    {
      register u32 st asm("r0");
      s32 hv;
      st = *rp;
      asm("" : "+r"(st));
      K = 0x343FD;
      raw = st;
      raw *= K;
      C = 0x269EC3;
      raw += C;
      raw <<= 1;
      s1 = raw >> 1;
      raw >>= 0x11;
      {
        register u32 m asm("r0");
        m = 0x1f;
        raw &= m;
      }
      asm volatile("add %0, %1, #0\n\tadd %0, #0x2e" : "=&l"(h) : "l"(mg));
      hv = *h >> 3;
      hv -= 0x30;
      asm("" : "+r"(hv));
      raw -= hv;
      *c = raw;
    }
    {
      register u32 v asm("r0");
      v = s1;
      v *= K;
      v += C;
      v <<= 1;
      {
        register u32 nv asm("r1");
        register u32* rq asm("r2");
        nv = v >> 1;
        rq = rp;
        *rq = nv;
      }
      i = v >> 0x11;
      {
        register u32 m3 asm("r0");
        m3 = 3;
        i &= m3;
      }
      asm("" :: "l"(dirty));
    }
    start = i;
    asm("" : "+r"(start));
    {
      s32 lim = i + 4;
      if (i >= lim) {
        goto after;
      }
    }
    {
      register u32* rq asm("r4");
      rq = rp;
      while (1) {
        s32 k;
        struct Enemy* e;
        k = i;
        if (i < 0) {
          k = i + 3;
        }
        k >>= 2;
        k <<= 2;
        k = i - k;
        e = arr[k];
        if (e == NULL) {
          goto inc;
        }
        {
          u32 v2 = (*rq * 0x343FD + 0x269EC3) << 1;
          *rq = v2 >> 1;
          FUN_08071470((struct Entity*)mg, (struct Entity*)e, 0x0026E800, 0xE0 << 9, (v2 >> 0x11) & 1);
        }
        break;
      inc:
        i++;
        if (i >= start + 4) {
          break;
        }
      }
    }
  after:
    {
      u8 hv2 = *h;
      if (hv2 <= 0xFE) {
        *h = hv2 + 1;
      }
    }
  }
done:
  {
    register u8* cc asm("r2");
    cc = c;
    *cc = *cc - 1;
  }
  return 1;
}

bool32 fefnir_minigame_080fb48c(struct GameState* g) {
  u8* mg = (u8*)g + 0xDCC;
  s32 t;
  *(u16*)(mg + 0x18) = 0;
  *(u16*)(mg + 0x1a) = 0;
  switch (mg[1]) {
    case 0:
      FadeOutBGM(0xbd);
      *(s32*)(mg + 0x1c) = 0x3c;
      mg[1]++;
      /* fallthrough */
    case 1:
      t = *(s32*)(mg + 0x1c) - 1;
      *(s32*)(mg + 0x1c) = t;
      if (t != 0) {
        break;
      }
      goto adv;
    case 2:
      *(struct VFX**)(mg + 0x14) = (struct VFX*)CreateMissionAlert(4);
      mg[1]++;
      /* fallthrough */
    case 3:
      if (*(u8*)(*(u8**)(mg + 0x14) + 0xc) <= 1) {
        break;
      }
    adv:
      mg[1]++;
      break;
    case 4:
      gGameState.frames = 0x40;
      mg[1]++;
      /* fallthrough */
    case 5:
      *(s32*)(mg + 0x1c) = *(s32*)(mg + 0x1c) - 1;
      if (gGameState.frames == 0x20) {
        return 0;
      }
      break;
  }
  return 1;
}

bool32 fefnir_minigame_080fb2d8(struct GameState* g);
bool32 fefnir_minigame_080fb354(struct GameState* g);
bool32 fefnir_minigame_080fb48c(struct GameState* g);

const GameLoopFunc FefnirMinigameLoops[3] = {
    (GameLoopFunc)fefnir_minigame_080fb2d8,
    (GameLoopFunc)fefnir_minigame_080fb354,
    (GameLoopFunc)fefnir_minigame_080fb48c,
};

bool32 exitFefnirMinigame(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  gSystemSavedata.minigameHiscores[MINIGAME_FEFNIR] = s->unk_28;
  SaveSystemData();
  return FALSE;
}
