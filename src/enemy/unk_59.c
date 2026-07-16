#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

// ファントムの出すオブジェクト?
typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 x_b4;       // 0xB4
  u8 unk_b8[12];  // 0xB8
} Enemy59;
static_assert(sizeof(Enemy59) == sizeof(struct Enemy));

void FUN_080c4c2c(s32 x, s32 y, s32 amplitude, u8 theta);
void CreateGhost18(Coords32* c, u8 kind, bool8 xflip, u8 r3);

static void Enemy59_Init(Enemy59* p);
void Enemy59_Update(Enemy59* p);
void Enemy59_Die(Enemy59* p);

// clang-format off
const EnemyRoutine gEnemy59Routine = {
    [ENTITY_INIT] =      (void*)Enemy59_Init,
    [ENTITY_UPDATE] =    (void*)Enemy59_Update,
    [ENTITY_DIE] =       (void*)Enemy59_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_08091280(struct Entity* p) {
  s32 x, y, amplitude;
  u8 theta;
  x = (p->coord).x + PIXEL((RANDOM(RNG_0202f388) & 0x1F) - 16);
  y = (p->coord).y - PIXEL(-RANDOM(RNG_0202f388) % 48);
  amplitude = 0x100;
  theta = 0x80 | (RANDOM(RNG_0202f388) & 0x7F);
  FUN_080c4c2c(x, y, amplitude, theta);
}

void FUN_0809130c(struct Entity* e, u8 idx) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_59);
    (p->coord).x = (e->coord).x, (p->coord).y = (e->coord).y;
    if (idx < 4) {
      s32 x = (idx - 2) * PIXEL(48) + PIXEL(24);
      (p->unk_coord).x = (e->coord).x + x;
    }
    if (idx > 4) {
      s32 x = (idx - 7) * PIXEL(48) + PIXEL(24);
      (p->coord).x = (e->coord).x + x;
    }
    p->unk_28 = e;
    EnableSpriteAnimation_Normal(p);
    SetSpriteTableDynamic(p);
    (p->spr).sprites = (*(void**)&e->kind);
    {
      u8 palID = *((u8*)e + 0x15);
      (p->spr).oam.paletteNum = palID >> 4;
    }
    p->work[0] = idx;
  }
}

// 0x080913C0
void FUN_080913c0(Enemy59* q, u8 kind) {
  Enemy59* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_59);
    (p->coord).x = (q->coord).x;
    (p->coord).y = (q->coord).y;
    p->work[0] = kind;
    p->work[3] = q->x_b4 > 0;
  }
}

/**
 * @note まきびし?
 * @note 0x0809142C
 */
void FUN_0809142c(struct Entity* q, u8 kind) {
  Enemy59* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_59);
    (p->coord).x = (q->coord).x;
    (p->coord).y = (q->coord).y - PIXEL(10);
    p->work[0] = 12;
    p->work[2] = kind;
    p->unk_28 = q;
  }
}

static const struct Collision sCollisions[];
static const u8 u8_ARRAY_08369a14[];
void FUN_08091790(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void Enemy59_Init(Enemy59* p) {
  if (p->work[0] == 12) {
    SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
    p->flags |= FLIPABLE;
    p->flags |= DISPLAY;
    INIT_BODY(p, sCollisions, 6, FUN_08091790);
    p->mode[1] = u8_ARRAY_08369a14[p->work[0]];
    Enemy59_Update(p);
    return;
  }
  if (p->work[0] > 8) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    p->flags |= FLIPABLE;
    p->flags |= DISPLAY;
    p->mode[1] = u8_ARRAY_08369a14[p->work[0]];
    Enemy59_Die(p);
    return;
  }

  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  INIT_BODY(p, sCollisions, 1, FUN_08091790);
  p->mode[1] = u8_ARRAY_08369a14[p->work[0]];
  Enemy59_Update(p);
}

INCASM("asm/enemy/unk_59.inc");

// 0x083697F4
static const struct SlashedEnemy sSlashedEnemies[4] = {
    {
      m : 0x1306,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0080, -0x0500},
      unk_coord_0c : {0x00FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : 0x1307,
      unk_02 : {254, 17},
      c : {0x0000, 0x0000},
      d : {0x0080, -0x0200},
      unk_coord_0c : {0x007F, 0x007F},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : 0x1308,
      unk_02 : {254, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
    {
      m : 0x1304,
      unk_02 : {16, 4},
      c : {0x0800, -0x1800},
      d : {-0x0080, -0x0100},
      unk_coord_0c : {0x0000, 0x0000},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {512, 512},
    },
};

// 0x08369864
static const struct Collision sCollisions[14] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 5,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(2), PIXEL(22), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 3,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 2,
      range : {PIXEL(1), -PIXEL(2), PIXEL(22), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : 8,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(1), -PIXEL(8), PIXEL(8), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : 8,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(1), -PIXEL(2), PIXEL(22), PIXEL(8)},
    },
};

// --------------------------------------------

void FUN_08091810(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[10] = {
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
    FUN_08091810,
};
// clang-format on

void FUN_08091814(struct Enemy* p);
void FUN_080918ec(struct Enemy* p);
void FUN_08091980(struct Enemy* p);
void FUN_08091ab0(struct Enemy* p);
void FUN_08091b60(struct Enemy* p);
void FUN_08091c54(struct Enemy* p);
void FUN_08091d0c(struct Enemy* p);
void FUN_08091da4(struct Enemy* p);
void FUN_08091e58(struct Enemy* p);
void FUN_08091f00(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[10] = {
    FUN_08091814,
    FUN_080918ec,
    FUN_08091980,
    FUN_08091ab0,
    FUN_08091b60,
    FUN_08091c54,
    FUN_08091d0c,
    FUN_08091da4,
    FUN_08091e58,
    FUN_08091f00,
};
// clang-format on

// --------------------------------------------

void FUN_08091fa8(struct Enemy* p);
void FUN_080921c8(struct Enemy* p);
static void FUN_080922e0(struct Entity* p);
static void FUN_080923ec(Enemy59* p);

static const EnemyFunc sDeads[4] = {
    (void*)FUN_08091fa8,
    (void*)FUN_080921c8,
    (void*)FUN_080922e0,
    (void*)FUN_080923ec,
};

NON_MATCH static void FUN_080922e0(struct Entity* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      EnableSpriteAnimation_Normal(p);
      SET_XFLIP(p, p->work[3]);
      SetSpriteAnimation(p, MOTION(SM019_PANTHEON_HUNTER, 3));  // 分身のハズレ枠
      p->work[2] = 18;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      p->work[2]--;
      if ((p->work[2] & 3) == 0) FUN_08091280(p);
      if (p->work[2] == 0) p->mode[2]++;
      break;
    }

    case 2: {
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      if (p->work[2] == 0) PlaySound(SE_ZAKO_EXPLODE);
      p->work[2]++;
      {
        register Coords32* c asm("r4") = &p->coord;
        CreateGhost18(c, 0, (p->flags & X_FLIP) != 0, p->work[3]);
        {
          register const struct SlashedEnemy* tmp asm("r6") = &sSlashedEnemies[3];
          u8 work3 = p->work[3];
          if (p->flags & X_FLIP) work3 |= p->flags & X_FLIP;
          CreateSlashedEnemy(c, tmp, 0, work3);
        }
      }
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
    }
    default: {
      break;
    }
  }
#else
  INCCODE("asm/wip/FUN_080922e0.inc");
#endif
}

static void FUN_080923ec(Enemy59* p) {
  Coords32 c;
  EXIT_BODY(p);
  c.x = (p->coord).x;
  c.y = (p->coord).y - PIXEL(8);
  CreateSmoke(1, &c);
  PlaySound(SE_ZAKO_EXPLODE);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

// 0x08369a14
static const u8 u8_ARRAY_08369a14[16] = {
    1, 1, 1, 1, 2, 5, 5, 5, 5, 0, 1, 2, 6, 0, 0, 0,
};
