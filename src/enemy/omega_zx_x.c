#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "script.h"
#include "score.h"
#include "vfx.h"

// OmegaZX のスプライト部分 (というか手前の X っぽい部分)

struct OmegaZX_X {
  COLLISION_OBJECT_HDR;  // 0x00
  Coords32 c;            // 0xB4
  u8 unk_bc[8];          // 0xBC
};
static_assert(sizeof(struct OmegaZX_X) == sizeof(struct Enemy));

static const struct Collision sCollisions[];

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void Enemy60_Init(struct OmegaZX_X* p);
void Enemy60_Update(struct Enemy* p);
void Enemy60_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gEnemy60Routine = {
    [ENTITY_INIT] =      (void*)Enemy60_Init,
    [ENTITY_UPDATE] =    (void*)Enemy60_Update,
    [ENTITY_DIE] =       (void*)Enemy60_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};









void FUN_08092918(struct Enemy* p);
void FUN_08092ba0(struct Enemy* p);
void FUN_08092b54(struct Enemy* p);
void FUN_08092acc(struct OmegaZX_X* p);
void FUN_08092aac(struct Enemy* p);
void FUN_08092a60(struct Enemy* p);
void FUN_080929e8(struct OmegaZX_X* p);
void FUN_080929c8(struct Enemy* p);
void FUN_08092980(struct Enemy* p);
// clang-format on

// --------------------------------------------

struct Entity* FUN_08092444(Coords32* c, u8 kind, struct Entity* boss) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA_ZX_X);
    p->coord = *c;
    p->work[0] = kind, p->work[1] = 0;
    p->unk_28 = (void*)boss;
  }
  return p;
}

static struct Entity* unused_FUN_080924a8(struct Entity* e, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA_ZX_X);
    p->work[0] = kind, p->work[1] = 1;
    p->unk_28 = (void*)e;
  }
  return p;
}

// --------------------------------------------

static void Enemy60_Init(struct OmegaZX_X* p) {
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  SET_XFLIP(p, FALSE);
  p->flags &= ~DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 1, onCollision);
  (&p->d)->x = (&p->d)->y = 0;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  (p->c).x = 0, (p->c).y = 0;
  {
    p->coord.y = ((p->unk_28)->coord).y;
    p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
    p->flags2 |= WHITE_PAINTABLE;
    p->invincibleID = (p->unk_28)->uniqueID;
  }
  Enemy60_Update((struct Enemy*)p);
}

static const EnemyFunc sDeads[2];

INCASM("asm/enemy/omega_zx_x_a.inc");

void Enemy60_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])((void*)p);
}

INCASM("asm/enemy/omega_zx_x_b.inc");

void FUN_08092918(struct Enemy* p) {
  struct Coord c;
  if ((p->s).mode[2] == 0) {
    c.x = (p->s).coord.x;
    c.y = (p->s).coord.y;
    CreateSmoke(1, &c);
    PlaySound(0x2a);
    if (gScore.enemyCount <= 0x270e) {
      gScore.enemyCount++;
    }
    DropEnemyDisk(p, &(p->s).coord);
    (p->s).flags &= ~DISPLAY;
    SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  }
}

void FUN_08092980(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      if ((p->s).unk_28->scriptEntity->flags & 1) {
        (p->s).flags |= DISPLAY;
        SetSpriteAnimation(p, 0xb600);
        UpdateSpriteAnimation(p);
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_080929c8(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      break;
  }
}

void FUN_080929e8(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      SetSpriteAnimation(p, 0xb600);
      SET_XFLIP(p, FALSE);
      SetDDP(&p->body, &sCollisions[3]);
      p->d.y = 0;
      p->d.x = 0;
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      p->coord.y = (p->c).y + ((p->unk_28)->coord).y;
      p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
      UpdateSpriteAnimation(p);
      break;
  }
}

void FUN_08092a60(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      if ((p->s).unk_28->scriptEntity->flags & 1) {
        (p->s).flags |= DISPLAY;
        SetSpriteAnimation(p, 0xb601);
        UpdateSpriteAnimation(p);
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_08092aac(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      break;
  }
}

void FUN_08092acc(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0:
      SetSpriteAnimation(p, 0xb601);
      SET_XFLIP(p, FALSE);
      SetDDP(&p->body, &sCollisions[5]);
      p->d.y = 0;
      p->d.x = 0;
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      p->work[2] += 2;
      p->coord.y += (((p->c).y + ((p->unk_28)->coord).y - p->coord.y) << 4) >> 8;
      p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
      UpdateSpriteAnimation(p);
      break;
  }
}

void FUN_08092b54(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      if (((p->s).unk_28->scriptEntity)->flags & 1) {
        (p->s).flags |= DISPLAY;
        SetSpriteAnimation(p, 0xb602);
        UpdateSpriteAnimation(p);
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_08092ba0(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      break;
  }
}

INCASM("asm/enemy/omega_zx_x_c.inc");

void FUN_08092980(struct Enemy* p);
void FUN_080929c8(struct Enemy* p);
void FUN_080929e8(struct OmegaZX_X* p);
static void FUN_0809357c(struct OmegaZX_X* p);

static const EnemyFunc sUpdates1[4] = {
    (void*)FUN_08092980,
    (void*)FUN_080929c8,
    (void*)FUN_080929e8,
    (void*)FUN_0809357c,
};

void FUN_08092a60(struct Enemy* p);
void FUN_08092aac(struct Enemy* p);
void FUN_08092acc(struct OmegaZX_X* p);

static const EnemyFunc sUpdates2[4] = {
    (void*)FUN_08092a60,
    (void*)FUN_08092aac,
    (void*)FUN_08092acc,
    (void*)FUN_0809357c,
};

void FUN_08092b54(struct Enemy* p);
void FUN_08092ba0(struct Enemy* p);
void FUN_08092bc0(struct Enemy* p);
void FUN_08092c5c(struct Enemy* p);
void FUN_08092f18(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates3[8] = {
    (void*)FUN_08092b54,
    (void*)FUN_08092ba0,
    (void*)FUN_08092bc0,
    (void*)FUN_08092c5c,
    (void*)FUN_0809357c,
    (void*)FUN_0809357c,
    (void*)FUN_0809357c,
    (void*)FUN_08092f18,
};
// clang-format on

static const EnemyFunc* const sUpdates[3] = {
    (void*)sUpdates1,
    (void*)sUpdates2,
    (void*)sUpdates3,
};

void FUN_08092664(struct Enemy* p);
void FUN_08092918(struct Enemy* p);

static const EnemyFunc sDeads[2] = {
    (void*)FUN_08092664,
    (void*)FUN_08092918,
};

// --------------------------------------------

// 0x08093578
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

static void FUN_0809357c(struct OmegaZX_X* p) {
  switch (p->mode[2]) {
    case 0: {
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->coord.y = (p->c).y + ((p->unk_28)->coord).y;
      p->coord.x = (p->c).x + ((p->unk_28)->coord).x;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// --------------------------------------------

// 0x08369a8c
static const struct Collision sCollisions[24] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(39), PIXEL(6), PIXEL(44), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(39), PIXEL(6), PIXEL(44), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(28), PIXEL(14), PIXEL(35), PIXEL(42)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(28), PIXEL(14), PIXEL(35), PIXEL(42)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(37), -PIXEL(32), PIXEL(48), PIXEL(65)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(37), -PIXEL(32), PIXEL(48), PIXEL(65)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(30)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(12)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(6)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(4)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(2)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 6,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(66), PIXEL(8), -PIXEL(1), PIXEL(1)},
    },
};

// clang-format off
static const Coords32 sPixelCoords[11] = {
    {-25, -45},
    {-49, -22},
    {-64, 7},
    {-49, 36},
    {-25, 59},
    {0, -48},
    {38, -18},
    {38, 18},
    {0, 54},
    {-38, 18},
    {-38, -18},
};
// clang-format on
