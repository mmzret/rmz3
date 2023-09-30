#include "global.h"
#include "overworld.h"

static void clearQuakeManager(void);

void ClearQuakeManager(void) {
  gQuakeManager.rng = 0;
  gQuakeManager.frame = 0;
  gQuakeManager.power = 0;
  gQuakeManager.unk_1a6 = 0;
  clearQuakeManager();
}

static void clearQuakeManager(void) {
  gQuakeManager.length = 0;
  gQuakeManager.quakes[0].power = 0;
  gQuakeManager.unk_1a4 = 0;
  gQuakeManager.unk_0d0[0].power = 0;
}

void AppendQuake(u8 power, struct Coord *c) {
  if (power != 0) {
    s32 n = gQuakeManager.length;
    if (n < 16) {
      gQuakeManager.quakes[n].c.x = c->x;
      gQuakeManager.quakes[n].c.y = c->y;
      gQuakeManager.quakes[n].power = power;

      n++;
      gQuakeManager.quakes[n].power = 0;
      gQuakeManager.length = n;
    }
  }
}

// 画面を揺らす量を計算して第二引数のCoordにセットする
// gSineTableを読み込む位置がおかしい以外は問題なさそう？
WIP void CalcQuake(struct Coord *c, struct Coord *ofs) {
#if MODERN
  struct Quake *q = &gQuakeManager.quakes[0];
  s32 power = gQuakeManager.power;

  while (q->power != 0) {
    if (power < (s32)(q->power << 8)) {
      power = q->power << 8;
    }
    q++;
  }

  if ((power >> 6) != 0) {
    u32 rng = gQuakeManager.frame++;
    s32 mag = Sin((rng & 3) << 6, power);

    ofs->x = mag >> 4;
    gQuakeManager.rng = LCG(gQuakeManager.rng);
    ofs->x = (s32)(ofs->x * (((gQuakeManager.rng >> 16) & 0xFF) - 0x7F)) >> 7;

    ofs->y = mag;
    mag -= 3;
    gQuakeManager.rng = LCG(gQuakeManager.rng);
    ofs->y = (s32)(mag + ((gQuakeManager.rng >> 16) & 0x7)) >> 1;
  } else {
    ofs->x = ofs->y = 0;
  }

  gQuakeManager.power = (((power << 4) - power) >> 4);
  gQuakeManager.length = 0;
  gQuakeManager.quakes[0].power = 0;
#else
  INCCODE("asm/wip/CalcQuake.inc");
#endif
}

static void Unused_0801ac88(u32 power, struct Coord *c) {
  if (power != 0) {
    s32 n = gQuakeManager.unk_1a4;
    if (n < 16) {
      gQuakeManager.unk_0d0[n].c.x = c->x;
      gQuakeManager.unk_0d0[n].c.y = c->y;
      gQuakeManager.unk_0d0[n].power = power;

      n++;
      gQuakeManager.unk_0d0[n].power = 0;
      gQuakeManager.unk_1a4 = n;
    }
  }
}

s32 quake_0801acdc(struct Coord *_) {
  struct Quake *q = &gQuakeManager.unk_0d0[0];
  s32 power = gQuakeManager.unk_1a6;
  while (q->power != 0) {
    if (power < (s32)(q->power << 8)) {
      power = q->power << 8;
    }
    q++;
  }

  if (power > 0x2000) {
    power = 0x2000;
  }
  gQuakeManager.unk_1a6 = (((power << 4) - power) >> 4);
  gQuakeManager.unk_1a4 = 0;
  gQuakeManager.unk_0d0[0].power = 0;
  return power >> 8;
}
