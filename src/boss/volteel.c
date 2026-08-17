#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "physics.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4;             // 0xB4
  s8 prevModes[2];       // 0xB5
  u8 unk_b7;             // 0xB7
  Coords32 initCoords;   // 0xB8
  void* unk_c0;          // 0xC0
  u8 unk_c4[5];          // 0xC4
  u8 unk_c9;             // 0xC9
  u8 unk_ca;             // 0xCA
  u8 unk_cb[9];          // 0xCB
  s32 unk_d4;            // 0xD4
  s32 unk_d8;            // 0xD8
  s32 unk_dc;            // 0xDC
  s32 unk_e0;            // 0xE0
} Volteel;
static_assert(sizeof(Volteel) == sizeof(Boss));

static const struct Collision sCollisions[24];

bool8 volteel_080457c4(Volteel* p);

void Volteel_OnCollision(struct Body* body, Coords32* c1, Coords32* c2);

static void Volteel_Init(Volteel* p);
static void Volteel_Update(Volteel* p);
static void Volteel_Die(Volteel* p);

// clang-format off
const BossRoutine gVolteelRoutine = {
    [ENTITY_INIT] =      (void*)Volteel_Init,
    [ENTITY_UPDATE] =    (void*)Volteel_Update,
    [ENTITY_DIE] =       (void*)Volteel_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Volteel* Unused_CreateVolteel(Coords32* c, u8 n) {
  Volteel* p = (Volteel*)AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_VOLTEEL);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

NON_MATCH static void Volteel_Init(Volteel* p) {
#if MODERN
  s32 y;
  EnableSpriteAnimation_Normal(p);
  p->angle = 0;
  (p->spr).mag.x = 0x100, (p->spr).mag.y = 0x100;
  SetSpriteTableDynamic(p);
  p->flags &= ~DISPLAY;
  p->flags |= FLIPABLE;
  (p->spr).xflip = FALSE, (p->spr).oam.xflip = FALSE;
  p->flags &= ~X_FLIP;
  ResetBossBody((void*)p, &sCollisions[0], 64);
  p->unk_c9 = 64;
  SET_BOSS_COLLISION_HANDLER(p, Volteel_OnCollision);
  p->unk_b4 = 0;
  p->prevModes[0] = -1, p->prevModes[1] = -1;
  p->unk_c0 = NULL;
  p->unk_b7 = 0;
  y = (p->coord).y - PIXEL(64);
  (p->coord).y = FUN_0800a05c((p->coord).x, y);
  (p->initCoords).x = (p->coord).x, (p->initCoords).y = (p->coord).y;

  {
    s32 tmp = FUN_0800a134((p->coord).x, (p->coord).y);
    s32 tmp_e0 = FUN_0800a22c((p->coord).x, tmp);
    s32 tmp_dc = FUN_0800a31c((p->coord).x, tmp);
    s32 tmpX = tmp_dc + ((tmp_e0 - tmp_dc) >> 1);
    p->unk_d4 = FUN_0800a134(tmpX, (p->coord).y);
    p->unk_d8 = FUN_0800a05c(tmpX, (p->coord).y);
    p->unk_dc = tmp_dc;
    p->unk_e0 = tmp_e0;
  }
  p->unk_ca = 0;
  if (p->work[0] == 0) {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 3, p->mode[2] = 0, p->mode[3] = 0;
  }
  p->work[1] = 0;
  Volteel_Update(p);
#else
  INCCODE("asm/wip/Volteel_Init.inc");
#endif
}

bool8 nop_080438a4(Volteel* p);
bool8 FUN_080438f0(Volteel* p);
bool8 FUN_08043988(Volteel* p);
bool8 nop_080439d0(Volteel* p);
bool8 nop_08043db0(Volteel* p);
bool8 FUN_080440c0(Volteel* p);
bool8 FUN_080449f0(Volteel* p);
bool8 FUN_08044cb4(Volteel* p);
bool8 FUN_08044f00(Volteel* p);
bool8 FUN_080450bc(Volteel* p);
bool8 FUN_08045464(Volteel* p);
bool8 FUN_08045570(Volteel* p);
bool8 FUN_08045610(Volteel* p);

void volteelMode0(Volteel* p);
void volteelMode1(Volteel* p);
void volteelMode2(Volteel* p);
void volteelNeutral(Volteel* p);
void volteelMode4(Volteel* p);
void volteelMode5(Volteel* p);
void volteelMode6(Volteel* p);
void volteelElectricCage(Volteel* p);
void volteelMode8(Volteel* p);
void volteelMode9(Volteel* p);
void volteelEX(Volteel* p);
void volteelMode11(Volteel* p);
void volteelKnockBackDamage(Volteel* p);

static void Volteel_Update(Volteel* p) {
  // clang-format off
  static bool8 (*const sUpdates1[])(Volteel*) = {
      nop_080438a4,
      FUN_080438f0,
      FUN_08043988,
      nop_080439d0,
      nop_08043db0,
      FUN_080440c0,
      FUN_080449f0,
      FUN_08044cb4,
      FUN_08044f00,
      FUN_080450bc,
      FUN_08045464,
      FUN_08045570,
      FUN_08045610,
  };
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[])(Volteel*) = {
      volteelMode0,
      volteelMode1,
      volteelMode2,
      volteelNeutral,
      volteelMode4,
      volteelMode5,
      volteelMode6,
      volteelElectricCage,
      volteelMode8,
      volteelMode9,
      volteelEX,
      volteelMode11,
      volteelKnockBackDamage,
  };
  // clang-format on
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    PlaySound(SE_VOLTEEL_DEATH);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[3] = 1;
    } else {
      p->mode[3] = 0;
    }
    Volteel_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])((void*)p);
  volteel_080457c4(p);
  (sUpdates2[p->mode[1]])((void*)p);
}

void volteelDeath0(Volteel* p);
void volteelDeath1(Volteel* p);

static void Volteel_Die(Volteel* p) {
  static void (*const seq[2])(Volteel*) = {
      volteelDeath0,
      volteelDeath1,
  };
  (seq[p->mode[1]])((void*)p);
}

INCASM("asm/boss/volteel_a.inc");

bool8 nop_080438a4(Volteel* p) { return TRUE; }

void volteelMode0(Volteel* p) {
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SetSpriteAnimation(p, MOTION(DM165_VOLTEEL, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->scriptEntity)->flags & (1 << 0)) p->mode[1] = 1, p->mode[2] = 0;
      break;
    }
  }
}

bool8 FUN_080438f0(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_b.inc");

bool8 FUN_08043988(Volteel* p) { return TRUE; }

void volteelMode2(Volteel* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM165_VOLTEEL, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (!(gStageRun.vm.active & VM_ACTIVE)) p->mode[1] = 3, p->mode[2] = 0;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

bool8 nop_080439d0(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_c.inc");

bool8 nop_08043db0(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_d.inc");

bool8 FUN_080440c0(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_e.inc");

bool8 FUN_080449f0(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_f.inc");

bool8 FUN_08044cb4(Volteel* p) { return TRUE; }

void volteelElectricCage(Volteel* p) {
  switch (p->mode[2]) {
    case 0:
      if (!(p->flags & 0x10)) {
        s32 r0v = FUN_08009f6c(p->coord.x + 0x3600, p->coord.y + -0x800);
        s32 r;
        asm volatile("add %0, %1, #0" : "=&l"(r) : "l"(r0v));
        if (r != p->coord.y) {
          p->mode[2]++;
        } else {
          p->mode[2] = 0xA;
        }
      } else {
        s32 r0v = FUN_08009f6c(p->coord.x + -0x3600, p->coord.y + -0x800);
        s32 r;
        asm volatile("add %0, %1, #0" : "=&l"(r) : "l"(r0v));
        if (r != p->coord.y) {
          p->mode[2]++;
        } else {
          p->mode[2] = 0xA;
        }
      }
      break;
    case 1:
      SetSpriteAnimation(p, 0xA507);
      p->mode[2]++;
      FALLTHROUGH;
    case 2:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        u32 m10;
        u32 f2 = p->flags;
        u32 tt;
        m10 = 0x10;
        asm("" : "+r"(m10));
        tt = 0x10;
        tt &= f2;
        if (tt == 0) {
          u8* xa = (u8*)p + 0x4c;
          u8 ov;
          u8 fv;
          *xa = 1;
          xa -= 2;
          ov = *xa;
          ov |= m10;
          *xa = ov;
          fv = p->flags;
          fv |= m10;
          p->flags = fv;
        } else {
          u8* xa = (u8*)p + 0x4c;
          s32 z = 0;
          asm("" : "+r"(z));
          *xa = z;
          {
            u8* oa = (u8*)p + 0x4a;
            s32 ov2 = *oa;
            s32 m11;
            asm("" : "+r"(z));
            m11 = z - 0x11;
            m11 &= ov2;
            *oa = m11;
          }
          p->flags &= ~0x10;
        }
        p->mode[2] = 0xA;
      }
      break;
    case 10:
      p->work[2] = 0x46;
      SetSpriteAnimation(p, 0xA508);
      SetDDP(&p->body, &sCollisions[1]);
      p->work[3] = 0x12;
      p->mode[2]++;
      FALLTHROUGH;
    case 11: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      t = p->work[3];
      if (t != 0) {
        t--;
        p->work[3] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 12: {
      u8* ow;
      s32 k;
      SetSpriteAnimation(p, 0xA509);
      SetDDP(&p->body, &sCollisions[5]);
      ow = (u8*)&gOverworld;
      if ((*(u16*)(ow + 0x1D0) & 0x7F) == 0xD) {
        k = 0x2D024;
        asm volatile("");
      } else {
        k = 0x2D026;
      }
      *(ow + k) = 1;
      PlaySound(0x7D);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 13: {
      s32 t;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2];
      if (t != 0) {
        t--;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 14: {
      u8* ow;
      s32 k;
      SetSpriteAnimation(p, 0xA50A);
      ow = (u8*)&gOverworld;
      if ((*(u16*)(ow + 0x1D0) & 0x7F) == 0xD) {
        k = 0x2D024;
        asm volatile("");
      } else {
        k = 0x2D026;
      }
      *(ow + k) = 0;
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 15:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 3;
        p->mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_08044f00(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_h.inc");

bool8 FUN_080450bc(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_i.inc");

bool8 FUN_08045464(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_j.inc");

bool8 FUN_08045570(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_k.inc");

bool8 FUN_08045610(Volteel* p) { return TRUE; }

INCASM("asm/boss/volteel_l.inc");

bool8 FUN_080459d4(Volteel* p) {
  if (p->mode[1] == 5) return TRUE;
  return FALSE;
}

INCASM("asm/boss/volteel_m.inc");

// --------------------------------------------

// 0x08362330
static const struct Collision sCollisions[24] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, -0x1200, 0x2400, 0x2600},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1800, 0x1C00, 0x2600},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, -0x1900, 0x1E00, 0x2800},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1C00, 0x3C00},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, -0x1D00, 0x1E00, 0x3E00},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0200, -0x1C00, 0x1A00, 0x3600},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x2800, -0x0F00, 0x1700, 0x2100},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {-0x0300, -0x1D00, 0x1C00, 0x3800},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0700, -0x1600, 0x1F00, 0x2600},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0A00, -0x3F00, 0x2300, 0x1100},
    },
    [10] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {-0x0800, -0x1700, 0x2100, 0x2800},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0600, -0x1100, 0x7C00, 0x1000},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0700, -0x1200, 0x7E00, 0x1200},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1100, 0x1000, 0x7C00},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, -0x1200, 0x1200, 0x7E00},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1A00, 0x3600},
    },
    [16] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0100, -0x1D00, 0x1C00, 0x3800},
    },
    [17] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0E00, 0x0000, 0x1C00, 0x0E00},
    },
    [18] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {-0x0F00, 0x0000, 0x1E00, 0x1000},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0E00, 0x0E00, 0x1C00},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0000, 0x0F00, 0x1000, 0x1E00},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x1C00, 0x1A00, 0x3600},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      atkType : 0x00,
      element : 0x01,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000002,
      range : {-0x4E00, -0x1900, 0x4500, 0x1000},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {0x0100, -0x1D00, 0x1C00, 0x3800},
    },
};

// 0x08362570
const Coords32 Coord_ARRAY_08362570[7] = {
    {0x00000000, -0x00002000}, {0x00000600, -0x00002500}, {0x00000600, -0x00002500}, {0x00000000, 0x00000400}, {0x00000000, 0x00000400}, {-0x00001000, 0x00000000}, {-0x00001000, 0x00000000},
};
