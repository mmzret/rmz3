#include "collision.h"
#include "enemy.h"
#include "global.h"

void FUN_08082348(struct Entity* e);
struct Enemy* createGlacierleJoint(struct Entity* e, struct Entity* parent);

INCASM("asm/enemy/glacierle_arm_a.inc");

void FUN_080823a4(struct Entity* e0, struct Entity* parent0) {
  register struct Entity* e asm("r5");
  register struct Entity* parent asm("r6");
  register s32 ten asm("r2");
  register s32 n asm("r4");
  register s32 cur asm("r0");
  e = e0;
  parent = parent0;
  ten = 10;
  {
    register u8* q asm("r0");
    q = (u8*)e + 0xb4;
    cur = *q;
  }
  if (ten == cur) {
    return;
  }
  {
    register s32 c2 asm("r1");
    c2 = cur;
    if (ten > c2) {
      register s32 m asm("r0");
      m = ten - c2;
      if (m <= 0) {
        return;
      }
      n = m;
      do {
        createGlacierleJoint(e, parent);
        n--;
      } while (n != 0);
      return;
    }
  }
  {
    register s32 m asm("r0");
    m = cur - 10;
    if (m <= 0) {
      return;
    }
    n = m;
    do {
      FUN_08082348(e);
      n--;
    } while (n != 0);
  }
}

u32 FUN_080823ec(struct Enemy* p) {
  struct Entity* a = (p->s).unk_2c;
  if (a != NULL) {
    struct Entity* b = a->unk_2c;
    if (b != NULL) {
      register s32 dx asm("r1");
      register s32 dy asm("r0");
      register u32 res asm("r1");
      dx = (b->coord).x;
      dx -= (a->coord).x;
      dy = (b->coord).y;
      dy -= (a->coord).y;
      dx >>= 8;
      dx = dx * dx;
      dy >>= 8;
      dy = dy * dy;
      dx += dy;
      res = (u16)Sqrt(dx) << 8;
      return res;
    }
  }
  return 0;
}

INCASM("asm/enemy/glacierle_arm_b.inc");

void GlacierleAtkArm_Init(struct Enemy* p);
void GlacierleAtkArm_Update(struct Enemy* p);
void GlacierleAtkArm_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGlacierleAtkArmRoutine = {
    [ENTITY_INIT] =      (void*)GlacierleAtkArm_Init,
    [ENTITY_UPDATE] =    (void*)GlacierleAtkArm_Update,
    [ENTITY_DIE] =       (void*)GlacierleAtkArm_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void nop_08082a1c(struct Enemy* p);

static const EnemyFunc sUpdates1[3] = {
    nop_08082a1c,
    nop_08082a1c,
    nop_08082a1c,
};

void FUN_08082a20(struct Enemy* p);
void FUN_08082aa0(struct Enemy* p);
void FUN_08082af8(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    FUN_08082a20,
    FUN_08082aa0,
    FUN_08082af8,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(12), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
};

static const u8 sInitModes[3] = {0, 1, 2};
