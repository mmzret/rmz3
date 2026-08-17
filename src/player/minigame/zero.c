#include "zero.h"

#include "collision.h"
#include "entity.h"
#include "global.h"
#include "minigame.h"
#include "physics.h"
#include "weapon.h"

static const struct Collision sCollisions[];

static void ZeroMini_Init(struct Zero* z);
static void ZeroMini_Update(struct Zero* z);
static void ZeroMini_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gZeroMiniRoutine = {
  [ENTITY_INIT] =       (void*)ZeroMini_Init,
  [ENTITY_UPDATE] =     (void*)ZeroMini_Update,
  [ENTITY_DIE]  =       (void*)ZeroMini_Die,
  [ENTITY_DISAPPEAR] =  (void*)RemovePlayer,
  [ENTITY_EXIT] =       (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateZeroMini(void* q, Coords32* c, u8 n) {
  struct Entity* p = AllocPlayer();
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_PLAYER_ROUTINE(p, PLAYER_MINIGAME_ZERO);
    p->coord = *c;
    p->work[0] = n;
    p->unk_28 = q;
  }
  return p;
}

// --------------------------------------------

static void ZeroMini_Init(struct Zero* z) {
  Coords32* c;
  EnableSpriteAnimation_Normal(z);
  SetSpriteTableDynamic(z);
  (z->s).flags |= DISPLAY;
  (z->s).flags |= FLIPABLE;
  SET_PLAYER_XFLIP(z, FALSE);
  INIT_BODY(z, &sCollisions[0], 32, NULL);
  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = 0, (z->s).mode[2] = 0, (z->s).mode[3] = 0;
  (z->mg).zero.unk_286 = 0;
  LoadZeroPalette((struct Entity*)z, BODY_CHIP_NONE);
  SetWeaponElement(WEAPON_BUSTER, 0);
  SetWeaponElement(WEAPON_SABER, 0);
  (z->mg).zero.unk_27c = 0, (z->mg).zero.unk_27d = 0;
  (z->s).work[3] = 0;
  (z->mg).zero.unk_284 = 0, (z->mg).zero.unk_285 = 0;

  {
    Coords32* c;
    c = &(z->s).d;
    c->x = c->y = 0;
    c = &(z->s).unk_coord;
    c->x = c->y = 0;
  }

  ZeroMini_Update(z);
}

// --------------------------------------------

static bool32 nop_0803658c(void* _ UNUSED);
bool8 FUN_080365d8(struct Zero* z);
void FUN_08036848(struct Zero* z);
void FUN_08036904(struct Zero* z);
static bool32 FUN_08036b94(void* _ UNUSED);

static void zeroMini_08036590(struct Zero* z);
void FUN_080366fc(struct Zero* z);
void FUN_08036870(struct Zero* z);
void recoil_minigame_08036938(struct Zero* z);
static void zeroMini_08036b98(struct Zero* z);

#define STATE ((struct MinigameState*)(z->s).unk_28)

static void ZeroMini_Update(struct Zero* z) {
  // clang-format off
  static const ZeroFunc sUpdates1[5] = {
      (void*)nop_0803658c,
      (void*)FUN_080365d8,
      (void*)FUN_08036848,
      (void*)FUN_08036904,
      (void*)FUN_08036b94,
  };
  // clang-format on

  // clang-format off
  static const ZeroFunc sUpdates2[5] = {
      (void*)zeroMini_08036590,
      (void*)FUN_080366fc,
      (void*)FUN_08036870,
      (void*)recoil_minigame_08036938,
      (void*)zeroMini_08036b98,
  };
  // clang-format on

  struct MinigameState* s = (struct MinigameState*)(z->s).unk_28;
  if (s->unk_04 != 2) {
    (sUpdates1[(z->s).mode[1]])((void*)z);
    (sUpdates2[(z->s).mode[1]])((void*)z);
  } else if (s->unk_0c == 0) {
    (sUpdates1[(z->s).mode[1]])((void*)z);
    (sUpdates2[(z->s).mode[1]])((void*)z);
  }

  if ((z->body).status & BODY_STATUS_WHITE) {
    PlaySound(SE_ZERO_STUN);
    if (((struct MinigameState*)(z->s).unk_28)->unk_0c != 0) {
      PlaySound(SE_NOT_ALLOWED);
      ((struct MinigameState*)(z->s).unk_28)->unk_0c--;
      if (((struct MinigameState*)(z->s).unk_28)->unk_0c == 0) {
        EXIT_BODY(z);
        (z->s).mode[1] = 4, (z->s).mode[2] = 0;
      }
    }
  }
  if ((z->body).invincibleTime != 0) {
    if (((z->mg).zero.unk_286 == 0) || (--(z->mg).zero.unk_286 == 0)) {
      (z->body).invincibleTime &= 0x7F;
    }
  }
}

// --------------------------------------------

static void ZeroMini_Die(struct Zero* z) {
  (z->s).flags &= ~DISPLAY;
  (z->s).flags &= ~FLIPABLE;
  EXIT_BODY(z);
  SET_PLAYER_ROUTINE(z, ENTITY_DISAPPEAR);
}

// --------------------------------------------

// 0x0803658c
static bool32 nop_0803658c(void* _) { return TRUE; }

// 0x08036590
static void zeroMini_08036590(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(z, MOTION(DM000_ZERO_NEUTRAL, 0));
      (z->s).work[2] = 60;
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(z);
      if (((z->s).work[2] == 0) || (--(z->s).work[2] == 0)) {
        (z->s).mode[1] = 1, (z->s).mode[2] = 0;
      }
      break;
    }
  }
}

// --------------------------------------------

bool8 FUN_080365d8(struct Zero* z) {
  if (*(s16*)((u8*)(z->s).unk_28 + 4) == 1) {
    if (gJoypad[0].pressed & B_BUTTON) {
      register u32 h asm("r1");
      h = gJoypad[0].input;
      if (h & DPAD_UP) {
        register u32 c1 asm("r4");
        u8* a1;
        c1 = 0x287;
        asm("" : "+l"(c1));
        a1 = (u8*)z + c1;
        asm volatile("" ::"l"(c1));
        *a1 = 2;
      } else {
        u32 m = DPAD_DOWN;
        u32 t;
        m &= h;
        m <<= 16;
        t = m >> 16;
        asm volatile("" ::"l"(m));
        if (t != 0) {
          register u32 c2 asm("r5");
          u8* a2;
          c2 = 0x287;
          asm("" : "+l"(c2));
          a2 = (u8*)z + c2;
          asm volatile("" ::"l"(c2));
          *a2 = 4;
        } else {
          register u32 c3 asm("r4");
          u8* a3;
          c3 = 0x287;
          asm("" : "+l"(c3));
          a3 = (u8*)z + c3;
          asm volatile("" ::"l"(c3));
          *a3 = t;
        }
      }
      (z->s).mode[1] = 3;
      (z->s).mode[2] = 0;
    }
    {
      register u32 o7d asm("r5");
      register u8* f7d asm("r4");
      register u8* sa asm("r1");
      s32 sv;
      o7d = 0x27D;
      f7d = (u8*)z + o7d;
      if (*f7d == 1) {
        register u32 h2 asm("r2");
        u32 m2;
        u32 t2;
        h2 = gJoypad[0].input;
        m2 = B_BUTTON;
        m2 &= h2;
        m2 <<= 16;
        t2 = m2 >> 16;
        asm volatile("" ::"l"(m2));
        if (t2 != 0) {
          goto ret;
        }
        o7d -= 1;
        {
          u8* af = (u8*)z + o7d;
          asm volatile("" ::"l"(o7d));
          *af = t2;
        }
        *f7d = t2;
        if (h2 & DPAD_UP) {
          register u32 c4 asm("r0");
          c4 = 0x287;
          asm("" : "+l"(c4));
          sa = (u8*)z + c4;
          sv = 7;
          goto sharedstore;
        } else if (h2 & DPAD_DOWN) {
          register u32 c5 asm("r2");
          c5 = 0x287;
          asm("" : "+l"(c5));
          sa = (u8*)z + c5;
          sv = 8;
          goto sharedstore;
        } else {
          register u32 c6 asm("r4");
          c6 = 0x287;
          asm("" : "+l"(c6));
          sa = (u8*)z + c6;
          sv = 6;
          goto sharedstore;
        }
      } else {
        register u32 o7c asm("r5");
        u8* f7c;
        o7c = 0x27C;
        asm("" : "+l"(o7c));
        f7c = (u8*)z + o7c;
        asm volatile("" ::"l"(o7c));
        if (*f7c > 0xA) {
          register u32 h3 asm("r2");
          u32 m3;
          u32 t3;
          h3 = gJoypad[0].input;
          m3 = B_BUTTON;
          m3 &= h3;
          t3 = (u16)m3;
          if (t3 != 0) {
            goto ret;
          }
          *f7c = t3;
          *f7d = t3;
          if (h3 & DPAD_UP) {
            register u32 c7 asm("r0");
            c7 = 0x287;
            asm("" : "+l"(c7));
            sa = (u8*)z + c7;
            sv = 2;
          sharedstore:
            *sa = sv;
          } else {
            u32 md = DPAD_DOWN;
            u32 td;
            md &= h3;
            md <<= 16;
            td = md >> 16;
            asm volatile("" ::"l"(md));
            if (td != 0) {
              register u32 c8 asm("r2");
              c8 = 0x287;
              asm("" : "+l"(c8));
              sa = (u8*)z + c8;
              sv = 4;
              goto sharedstore;
            } else {
              register u32 c9 asm("r4");
              u8* a9;
              c9 = 0x287;
              asm("" : "+l"(c9));
              a9 = (u8*)z + c9;
              asm volatile("" ::"l"(c9));
              *a9 = td;
            }
          }
          (z->s).mode[1] = 3;
          (z->s).mode[2] = 0;
        }
      }
    }
  }
ret:
  return TRUE;
}

INCASM("asm/player/zero_minigame_a.inc");

// 0x08036b94
static bool32 FUN_08036b94(void* _) { return TRUE; }

// 0x08036b98
static void zeroMini_08036b98(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(z, MOTION(DM001_ZERO_DYING, 0));
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 dy;
      (z->s).d.y += PIXEL(1) / 4;
      if (PIXEL(7) < (z->s).d.y) {
        (z->s).d.y = PIXEL(7);
      }

      (z->s).coord.y += (z->s).d.y;
      dy = PushoutToUp2((z->s).coord.x, (z->s).coord.y);
      if (dy != 0) {
        (z->s).d.y = 0;
        (z->s).coord.y += dy;
      }
      UpdateSpriteAnimation(z);
      break;
    }
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x0835eca0
static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(20), PIXEL(26)},
    },

    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(23), -PIXEL(56), PIXEL(26), PIXEL(56)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(7), -PIXEL(76), PIXEL(36), PIXEL(23)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(36), PIXEL(28), PIXEL(50)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(23), -PIXEL(56), PIXEL(26), PIXEL(56)},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(7), -PIXEL(76), PIXEL(36), PIXEL(23)},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(36), PIXEL(28), PIXEL(50)},
    },
};

// --------------------------------------------

// clang-format off
// 0x0835ed48
const motion_t sZeroMiniMotions[9] = {
  MOTION(DM030_ZERO_ROD, 0),
  MOTION(DM030_ZERO_ROD, 1),
  MOTION(DM031_ZERO_ROD_UP, 0),
  MOTION(DM031_ZERO_ROD_UP, 1),
  MOTION(DM032_ZERO_ROD_DOWN, 0),
  MOTION(DM032_ZERO_ROD_DOWN, 1),
  MOTION(DM055_ZERO_ROD_CHARGE, 0),
  MOTION(DM056_ZERO_ROD_CHARGE_UP, 0),
  MOTION(DM057_ZERO_ROD_CHARGE_DOWN, 1),
};
// clang-format on
