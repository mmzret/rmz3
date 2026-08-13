#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"

void FUN_0809f970(s32 x, s32 y, s32 n);
void FUN_080bc594(s32 x1, s32 y1, s32 x2, s32 y2, u8 n);
void babyelf_08045c84(struct Boss* p);

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[27];         // 0xB4
  u8 unk_cf;             // 0xCF
  u8 unk_d0;             // 0xD0
  u8 unk_d1[19];         // 0xD1
} BabyElf;
static_assert(sizeof(BabyElf) == sizeof(Boss));

void BabyElf_Init(BabyElf* p);
void BabyElf_Update(BabyElf* p);
void BabyElf_Die(BabyElf* p);

// clang-format off
const BossRoutine gBabyElfRoutine = {
    [ENTITY_INIT] =      (void*)BabyElf_Init,
    [ENTITY_UPDATE] =    (void*)BabyElf_Update,
    [ENTITY_DIE] =       (void*)BabyElf_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void FUN_08045b68(BabyElf* p) {
  if (p->work[0] == 0) {
    switch (p->unk_d0) {
      case 0: {
        if (p->unk_cf) {
          StartPaletteAnimation(25, 0x320);
          StepPaletteAnimation(25);
          p->unk_d0++;
        }
        break;
      }
      case 1: {
        StepPaletteAnimation(25);
        if (!p->unk_cf) {
          RemovePaletteAnimation(25);
          p->unk_d0 = 0;
        }
        break;
      }
    }
  }
}

INCASM("asm/boss/baby_elf_a.inc");

void babyelf_080467c4(BabyElf* p0) {
  BabyElf* p;
  p = p0;
  switch (p->mode[2]) {
    case 0:
      *(u16*)((u8*)p + 0xc4) = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      u16* a1;
      u8* dir;
      u32 nv;
      a1 = (u16*)((u8*)p + 0xc4);
      dir = (u8*)p + 0xc7;
      {
        s32 step;
        u32 av;
        u32 t;
        {
          register u32 d asm("r0");
          d = *dir;
          step = d * 6;
        }
        step += 0xFFFD;
        asm volatile("" : "+l"(step));
        av = *a1;
        t = step + av;
        *a1 = t;
        nv = (u16)t;
      }
      {
        u32 lim = 0xFF7F;
        asm volatile("" : "+l"(lim));
        if (nv <= lim) {
          if (*dir == 0) {
            goto inc1;
          }
        }
      }
      if (nv > 0x80) {
        if (*dir == 1) {
        inc1:
          p->mode[2]++;
        }
      }
      babyelf_08045c84((struct Boss*)p);
      goto tail3;
    }
    case 2: {
      if (RANDOM(RNG_0202f388) & 1) {
        PlaySound(0x8A << 1);
      } else {
        PlaySound(0x115);
      }
      *(u16*)((u8*)p + 0xc4) = 0;
      {
        s32* c0p;
        s32 k4;
        c0p = (s32*)((u8*)p + 0xc0);
        *c0p = p->coord.y;
        k4 = 0xB0 << 8;
        p->d.x = k4;
        {
          u8* dir2;
          u32 dv;
          dir2 = (u8*)p + 0xc7;
          dv = *dir2;
          if (dv == 0) {
            *c0p += -0x1800;
          } else {
            p->d.x = -k4;
            *c0p += 0x1800;
          }
        }
      }
      p->d.x /= 128;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      u16* a3;
      p->coord.x += p->d.x;
      p->coord.y = *(s32*)((u8*)p + 0xc0);
      a3 = (u16*)((u8*)p + 0xc4);
      {
        u32 n3 = *a3 + 4;
        *a3 = n3;
        if ((u32)(n3 << 16) > 0x01FF0000) {
          p->mode[2]++;
        }
      }
      if (*((u8*)p + 0xc7) == 0) {
        const s16* st;
        st = gSineTable;
        asm("" : "+r"(st));
        {
          s32 sv = *(const s16*)((((u32)(u8)(*(u8*)a3 + 0x40)) << 1) + (u32)st);
          p->coord.y += (sv * 3) << 3;
        }
      } else {
        const s16* st2;
        asm volatile("");
        st2 = gSineTable;
        asm(" " : "+r"(st2));
        {
          s32 sv2 = *(const s16*)((((u32)(u8)(*(u8*)a3 + 0x40)) << 1) + (u32)st2);
          p->coord.y -= (sv2 * 3) << 3;
        }
      }
    tail3:
      StepPaletteAnimation(*((u8*)p + 0xc6));
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 4: {
      {
        s32* bcp;
        bcp = (s32*)((u8*)p + 0xbc);
        *bcp = p->coord.x;
        asm("" : "+r"(bcp));
      }
      {
        s32* c0p4;
        c0p4 = (s32*)((u8*)p + 0xc0);
        *c0p4 = p->coord.y;
        {
          u8* dir4;
          u32 nx4;
          asm volatile("" ::: "r0", "r1");
          dir4 = (u8*)p + 0xc7;
          nx4 = *dir4;
          nx4 ^= 1;
          *dir4 = nx4;
          if (nx4 == 0) {
            *c0p4 += 0x80 << 6;
            *(u16*)((u8*)p + 0xc4) = 0x80;
          } else {
            *c0p4 += -0x2000;
            {
              u32 fv;
              u16* c4d;
              c4d = (u16*)((u8*)p + 0xc4);
              fv = 0xFF80;
              asm volatile("" : "+r"(fv));
              *c4d = fv;
            }
          }
        }
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      u16* a5;
      u8* dir5;
      u32 nv5;
      dir5 = (u8*)p + 0xc7;
      a5 = (u16*)((u8*)p + 0xc4);
      {
        s32 step5;
        u32 t5;
        {
          register u32 d5 asm("r1");
          d5 = *dir5;
          step5 = d5 * 6;
          step5 -= 3;
        }
        asm volatile(" " : "+l"(step5));
        t5 = *a5 - step5;
        *a5 = t5;
        nv5 = (u16)t5;
      }
      if (nv5 > 0x80 << 1) {
        if (*dir5 == 0) {
          goto set10;
        }
      }
      {
        u32 lim5 = 0xFEFF;
        asm volatile(" " : "+l"(lim5));
        if (nv5 > lim5) {
          goto skip5;
        }
      }
      if (*dir5 != 1) {
        goto skip5;
      }
    set10:
      p->mode[1] = 1;
      p->mode[2] = 0;
    skip5:
      babyelf_08045c84((struct Boss*)p);
      StepPaletteAnimation(*((u8*)p + 0xc6));
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
  p->work[2]++;
  if ((u8)(p->work[2] % 7) == 0) {
    register u32 a asm("r0");
    register u32 r1v asm("r1");
    u32 s1;
    s32 x;
    s32 y;
    a = RNG_0202f388;
    r1v = (a * 0x343FD + 0x269EC3) << 1;
    asm volatile("" :: "r"(a));
    asm("" : "+r"(r1v));
    s1 = r1v >> 1;
    {
      register s32 xoff asm("r1");
      xoff = (s32)((r1v << 4) >> 21) + -0x400;
      asm volatile("" : "+r"(xoff));
      x = p->coord.x + xoff;
    }
    s1 *= 0x343FD;
    s1 += 0x269EC3;
    s1 <<= 1;
    asm("" : "+r"(s1));
    RNG_0202f388 = s1 >> 1;
    {
      s32 yoff = (s32)((s1 << 5) >> 22) + 0x800;
      asm volatile("" : "+r"(yoff));
      y = p->coord.y + yoff;
    }
    FUN_080bc594(x, y, 0, 0, p->work[0]);
  }
}

INCASM("asm/boss/baby_elf_b.inc");

void babyelf_08046e5c(BabyElf* p0) {
  BabyElf* p;
  struct Entity* q;
  p = p0;
  q = p->unk_2c;
  switch (p->mode[2]) {
    case 0: {
      u32 z0;
      *((u8*)p + 0xc9) = (z0 = 0);
      *(u16*)((u8*)p + 0xc4) = z0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register u8* dir asm("r2");
      register u32 nv asm("r1");
      u16* a1;
      a1 = (u16*)((u8*)p + 0xc4);
      dir = (u8*)p + 0xc7;
      {
        s32 step;
        register u32 av asm("r3");
        u32 t;
        {
          register u32 d asm("r0");
          d = *dir;
          step = d * 6;
        }
        step += 0xFFFD;
        asm volatile("" : "+l"(step));
        av = *a1;
        t = step + av;
        *a1 = t;
        nv = (u16)t;
      }
      {
        u32 lim = 0xFE7F;
        asm volatile("" : "+l"(lim));
        if (nv <= lim) {
          if (*dir == 0) {
            goto bump1;
          }
        }
      }
      if (nv <= 0x80) {
        goto setm1;
      }
      if (*dir != 1) {
        goto setm1;
      }
    bump1:
      p->mode[2]++;
    setm1:
      babyelf_08045c84((struct Boss*)p);
      break;
    }
    case 2: {
      u16* c4b;
      u32 za;
      u32 zb;
      c4b = (u16*)((u8*)p + 0xc4);
      za = 0;
      asm("" : "+r"(za));
      zb = 0;
      *c4b = zb;
      p->work[3] = za;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      u16* a3;
      a3 = (u16*)((u8*)p + 0xc4);
      if (p->work[3] == 0) {
        if (RANDOM(RNG_0202f388) & 1) {
          PlaySound(0x115);
        }
        FUN_0809f970(p->coord.x, p->coord.y, 0);
      }
      p->work[3]++;
      {
        u32 kv = *(volatile u8*)&p->work[3];
        asm("" : "+r"(kv));
        p->work[3] = kv & 0x1F;
      }
      {
        u32 n3 = *a3 + 1;
        *a3 = n3;
        if ((u32)(n3 << 16) > (u32)(0x80 << 17)) {
          p->mode[2]++;
        }
      }
      {
        const s16* st;
        if (*((u8*)p + 0xc7) == 0) {
          s32 sv;
          s32 v7;
          st = gSineTable;
          asm("" : "+r"(st));
          sv = *(const s16*)((((u32)*(u8*)a3) << 1) + (u32)st);
          v7 = (sv << 3) - sv;
          v7 <<= 6;
          if (v7 < 0) {
            v7 += 0xFF;
          }
          p->coord.x += v7 >> 8;
        } else {
          s32 sv2;
          s32 v72;
          asm volatile("");
          st = gSineTable;
          asm(" " : "+r"(st));
          sv2 = *(const s16*)((((u32)*(u8*)a3) << 1) + (u32)st);
          v72 = (sv2 << 3) - sv2;
          v72 <<= 6;
          if (v72 < 0) {
            v72 += 0xFF;
          }
          p->coord.x -= v72 >> 8;
        }
        {
          s32 sy;
          s32 vy;
          asm volatile("");
          sy = *(const s16*)((((u32)(u8)(*(u8*)a3 + 0x40)) << 1) + (u32)st);
          vy = sy * 0x2C;
          if (vy < 0) {
            vy += 0xFF;
          }
          p->coord.y += vy >> 8;
        }
      }
      break;
    }
    case 4: {
      u32 fv;
      u16* c4d;
      p->work[3] = 2;
      *((u8*)p + 0xc9) = 1;
      c4d = (u16*)((u8*)p + 0xc4);
      fv = 0xFE80;
      asm volatile("" : "+r"(fv));
      *c4d = fv;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      {
        u32 w3 = p->work[3];
        if (w3 != 0) {
          w3 -= 1;
          p->work[3] = w3;
          {
            u32 tb = (u8)w3;
            asm("" : "+r"(tb));
            if (tb == 0) {
              *((u8*)p + 0xc9) = tb;
            }
          }
        }
      }
      if (*((u8*)q + 0xc9) != 0) {
        p->mode[2]++;
      }
      asm volatile("" :: "r"(q));
      {
        u8* a7;
        s32 step5;
        a7 = (u8*)p + 0xc7;
        {
          register u32 d5 asm("r1");
          d5 = *a7;
          step5 = d5 * 6;
          step5 += 0xFFFD;
          asm volatile("" :: "r"(d5));
        }
        asm volatile(" " : "+l"(step5));
        step5 += *(u16*)((u8*)p + 0xc4);
        *(u16*)((u8*)p + 0xc4) = step5;
      }
      babyelf_08045c84((struct Boss*)p);
      break;
    }
    case 6: {
      u8* c9f;
      c9f = (u8*)p + 0xc9;
      *c9f = 0;
      {
        register s16* sp6 asm("r0");
        s32 sv6;
        sp6 = (s16*)((u8*)p + 0xc4);
        sv6 = *sp6;
        asm volatile("" :: "r"(c9f));
        *(u16*)((u8*)p + 0xc4) = sv6 % 512;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7: {
      u32 fl7;
      register u8* dir7 asm("r3");
      u16* a7v;
      a7v = (u16*)((u8*)p + 0xc4);
      fl7 = 0;
      {
        register u32 n7 asm("r1");
        n7 = *a7v;
        {
          u32 lim7 = 0xFF7F;
          asm volatile("  " : "+l"(lim7));
          dir7 = (u8*)p + 0xc7;
          if (n7 <= lim7) {
            if (*dir7 == 0) {
              goto set7;
            }
          }
        }
        if (n7 <= 0xC0 << 1) {
          goto skip7;
        }
        if (*dir7 != 1) {
          goto skip7;
        }
      set7:
        fl7 = 1;
      skip7:;
      }
      {
        register u16* acc2 asm("r2");
        register u8* dir5b asm("r5");
        acc2 = (u16*)((u8*)p + 0xc4);
        asm("" : "+r"(acc2));
        dir5b = dir7;
        asm("" : "+r"(dir5b));
        {
          register u32 d7 asm("r1");
          s32 step7;
          u32 c7;
          d7 = *dir5b;
          step7 = d7 * 2;
          step7 += d7;
          step7 *= 2;
          asm volatile("   " : "+l"(step7));
          c7 = 0xFFFD;
          asm volatile("" : "+l"(c7));
          *acc2 += step7 + c7;
        }
        {
          s32 n7b = *(s16*)acc2;
          s32 res = n7b % 512;
          u32 resu;
          *(u16*)((u8*)p + 0xc4) = res;
          resu = (u16)res;
          {
            u32 lim7b = 0xFF7F;
            asm volatile("   " : "+l"(lim7b));
            if (resu <= lim7b) {
              if (*dir5b == 0) {
                goto set7b;
              }
            }
          }
          if (resu <= 0xC0 << 1) {
            goto skip7b;
          }
          if (*dir7 != 1) {
            goto skip7b;
          }
        set7b:
          if (fl7 == 0) {
            p->mode[1] = 1;
            p->mode[2] = 1;
          }
        skip7b:;
        }
      }
      babyelf_08045c84((struct Boss*)p);
      asm volatile("");
      break;
    }
  }
  p->work[2]++;
  if ((u8)(p->work[2] % 7) == 0) {
    register u32 a asm("r0");
    register u32 r1v asm("r1");
    u32 s1;
    s32 x;
    s32 y;
    u32 r2v;
    a = RNG_0202f388;
    r1v = (a * 0x343FD + 0x269EC3) << 1;
    asm volatile("" :: "r"(a));
    asm("" : "+r"(r1v));
    s1 = r1v >> 1;
    {
      register s32 xoff asm("r1");
      xoff = (s32)((r1v << 4) >> 21) + -0x400;
      asm volatile("" : "+r"(xoff));
      x = p->coord.x + xoff;
    }
    s1 *= 0x343FD;
    s1 += 0x269EC3;
    s1 <<= 1;
    asm("" : "+r"(s1));
    RNG_0202f388 = s1 >> 1;
    {
      s32 yoff = (s32)((s1 << 5) >> 22) + 0x800;
      asm volatile("" : "+r"(yoff));
      y = p->coord.y + yoff;
    }
    FUN_080bc594(x, y, 0, 0, p->work[0]);
  }
  StepPaletteAnimation(*((u8*)p + 0xc6));
  UpdateEntityAnim((struct Entity*)p);
}

INCASM("asm/boss/baby_elf_c.inc");

void nop_08046150(BabyElf* p);

// clang-format off
static void (*const sUpdates1[19])(BabyElf*) = {
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
    nop_08046150,
}; // 0x083625BC
// clang-format on

void babyelf_08046154(BabyElf* p);
void babyelf_0804662c(BabyElf* p);
void babyelf_080467c4(BabyElf* p);
void babyelf_08046a7c(BabyElf* p);
void FUN_08046ccc(BabyElf* p);
void babyelf_08046e5c(BabyElf* p);
void babyelf_08047184(BabyElf* p);
void babyelf_08047338(BabyElf* p);
void babyelf_080475a0(BabyElf* p);
void babyelf_080477b8(BabyElf* p);
void FUN_080478b8(BabyElf* p);
void babyelf_080479d4(BabyElf* p);
void babyelf_08047c70(BabyElf* p);
void babyelf_08047e30(BabyElf* p);
void FUN_08047f84(BabyElf* p);
void FUN_08048190(BabyElf* p);
void FUN_0804839c(BabyElf* p);
void FUN_08048548(BabyElf* p);
void FUN_0804874c(BabyElf* p);

// clang-format off
static void (*const sUpdates2[19])(BabyElf*) = {
    babyelf_08046154,
    babyelf_0804662c,
    babyelf_080467c4,
    babyelf_08046a7c,
    FUN_08046ccc,
    babyelf_08046e5c,
    babyelf_08047184,
    babyelf_08047338,
    babyelf_080475a0,
    babyelf_080477b8,
    FUN_080478b8,
    babyelf_080479d4,
    babyelf_08047c70,
    babyelf_08047e30,
    FUN_08047f84,
    FUN_08048190,
    FUN_0804839c,
    FUN_08048548,
    FUN_0804874c,
}; // 0x08362608
// clang-format on

void FUN_08048788(BabyElf* p);
void FUN_080488cc(BabyElf* p);

static void (*const sDeinitializers[2])(BabyElf*) = {
    FUN_08048788,
    FUN_080488cc,
};  // 0x08362654

// --------------------------------------------

// 0x0836265C
static const struct Collision sCollisions[5] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1E00, 0x1E00},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1E00, 0x1E00},
    },
};

// 0x083626d4
const u8 u8_ARRAY_083626d4[64] = {
    1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 1, 1, 2, 2, 3, 3, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 2, 2, 2, 12, 12, 12, 3, 3, 3, 13, 13, 13, 13, 1, 2, 12, 12, 3, 3, 13, 13, 7, 7, 7, 7, 7, 7, 7, 7,
};

// 0x08362714
static const u8 sInitModes[4] = {0, 0, 0, 0};
