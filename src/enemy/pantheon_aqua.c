#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "overworld.h"

static const struct Collision sCollisions[];

void PantheonAqua_Init(struct Enemy* p);
void PantheonAqua_Update(struct Enemy* p);
void PantheonAqua_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gPantheonAquaRoutine = {
    [ENTITY_INIT] =      (void*)PantheonAqua_Init,
    [ENTITY_UPDATE] =    (void*)PantheonAqua_Update,
    [ENTITY_DIE] =       (void*)PantheonAqua_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};


void FUN_08072ffc(struct Enemy* p);
void FUN_08072fb0(struct Enemy* p);
// clang-format on

struct Entity* CreatePantheonAqua(Coords32* c, u8 kind) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_P_AQUA);
    p->coord = *c;
    p->work[0] = kind;
  }
  return p;
}

// --------------------------------------------

INCASM("asm/enemy/pantheon_aqua_a.inc");

extern const EnemyFunc PTR_ARRAY_08366bd0[8];
extern const EnemyFunc PTR_ARRAY_08366bf0[8];
s32 FUN_08073368(struct Enemy* p);
void FUN_080731c4(struct Enemy* p);
void PantheonAqua_Die(struct Enemy* p);

void PantheonAqua_Update(struct Enemy* p) {
  u8 m;
  s32 sea;
  if (!((p->body).status & BODY_STATUS_DEAD)) {
    if (FUN_08073368(p)) {
      goto alive;
    }
  }
  SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  PantheonAqua_Die(p);
  return;

alive:
  {
    s32* ppx = (s32*)((u8*)p + 0xb4);
    s32 cx = (p->s).coord.x;
    s32 d = cx - *ppx;
    if (d > 0) {
      if (d > 0x9400) {
        goto setmode;
      }
    } else {
      if (*ppx - cx > 0x9400) {
        goto setmode;
      }
    }
    goto dispatch;
  setmode:
    if ((p->s).mode[1] != 3) {
      (p->s).mode[1] = 3;
      (p->s).mode[2] = 0;
    }
  }
dispatch:
  (PTR_ARRAY_08366bd0[(p->s).mode[1]])((void*)p);
  FUN_080731c4(p);
  m = (p->s).mode[1];
  if (m == 4) goto water;
  if (m == 6) goto water;
  if (IsFrozen(&p->s)) {
    return;
  }
water:
  sea = gOverworld.sea;
  if (sea > (p->s).coord.y - 0x1E00) {
    u8 f = p->buffer[4];
    if (f == 0) {
      SetSpriteAnimation(p, 0x2700);
      UpdateSpriteAnimation(p);
      (p->s).d.y = f;
    }
    p->buffer[4] = 1;
    (p->s).d.y += 0x20;
    if ((p->s).d.y > 0x700) {
      (p->s).d.y = 0x700;
    }
    (p->s).coord.y += (p->s).d.y;
    return;
  } else {
    if (p->buffer[4] == 1) {
      (p->s).mode[1] = 0;
      (p->s).mode[2] = 0;
    }
    p->buffer[4] = 0;
    (PTR_ARRAY_08366bf0[(p->s).mode[1]])((void*)p);
  }
}

INCASM("asm/enemy/pantheon_aqua_b.inc");

bool8 nop_080726a8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/pantheon_aqua_c.inc");

bool8 FUN_08072800(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/pantheon_aqua_d.inc");

bool8 FUN_080729e8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/pantheon_aqua_e.inc");

bool8 FUN_08072e40(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/pantheon_aqua_f.inc");

bool8 FUN_08072fac(struct Enemy* p) { return TRUE; }

void FUN_08072fb0(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    SetDDP(&p->body, &sCollisions[1]);
    (p->s).mode[2]++;
  }
  if (isKilled(*(struct Entity**)((u8*)p + 0xbc))) {
    SetDDP(&p->body, &sCollisions[0]);
    *(struct Entity**)((u8*)p + 0xbc) = NULL;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

bool8 FUN_08072ff8(struct Enemy* p) { return TRUE; }


void FUN_08072ffc(struct Enemy* p) {}

bool8 FUN_08073000(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/pantheon_aqua_g.inc");

bool8 FUN_080730cc(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/pantheon_aqua_h.inc");

s32 FUN_08073368(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/pantheon_aqua_i_a.inc");

u32 FUN_08073610(struct Enemy* p0) {
  register struct Enemy* p asm("r3");
  register s32 sea asm("r2");
  register s32 t asm("r1");
  register s32 k asm("r4");
  p = p0;
  {
    register u8* ow asm("r1");
    register u32 o asm("r2");
    ow = (u8*)&gOverworld;
    o = 0x2C00C;
    asm("" : "+l"(o));
    ow += o;
    sea = *(s32*)ow;
  }
  {
    register struct Camera* cam asm("r1");
    cam = &gStageRun.vm.camera;
    asm("" : "+l"(cam));
    t = cam->viewport.y;
    k = 0x4FFF;
    asm("" : "+l"(k));
    t += k;
  }
  if (sea < t) {
    t = (p->s).coord.y;
    k = -0x2600;
    asm("" : "+l"(k));
    t += k;
    if (sea <= t) {
      return;
    }
    k = 0x98 << 6;
    asm("" : "+l"(k));
    t = sea + k;
  } else {
    register s32 k2 asm("r2");
    t = (p->s).coord.y;
    k2 = 0x80 << 2;
    asm("" : "+l"(k2));
    t += k2;
  }
  (p->s).coord.y = t;
}

bool8 nop_080726a8(struct Enemy* p);
bool8 FUN_08072800(struct Enemy* p);
bool8 FUN_080729e8(struct Enemy* p);
bool8 FUN_08072e40(struct Enemy* p);
bool8 FUN_08072fac(struct Enemy* p);
bool8 FUN_08072ff8(struct Enemy* p);
bool8 FUN_08073000(struct Enemy* p);
bool8 FUN_080730cc(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366bd0[8] = {
    (EnemyFunc)nop_080726a8,
    (EnemyFunc)FUN_08072800,
    (EnemyFunc)FUN_080729e8,
    (EnemyFunc)FUN_08072e40,
    (EnemyFunc)FUN_08072fac,
    (EnemyFunc)FUN_08072ff8,
    (EnemyFunc)FUN_08073000,
    (EnemyFunc)FUN_080730cc,
};
// clang-format on

void FUN_080726ac(struct Enemy* p);
void FUN_08072804(struct Enemy* p);
void FUN_080729ec(struct Enemy* p);
void FUN_08072e44(struct Enemy* p);
void FUN_08072fb0(struct Enemy* p);
void FUN_08072ffc(struct Enemy* p);
void FUN_08073004(struct Enemy* p);
void FUN_080730d0(struct Enemy* p);

// clang-format off
const EnemyFunc PTR_ARRAY_08366bf0[8] = {
    (void*)FUN_080726ac,
    (void*)FUN_08072804,
    (void*)FUN_080729ec,
    (void*)FUN_08072e44,
    (void*)FUN_08072fb0,
    (void*)FUN_08072ffc,
    (void*)FUN_08073004,
    (void*)FUN_080730d0,
};
// clang-format on

// --------------------------------------------

// 0x08366c10
static const struct Collision sCollisions[] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(28), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(28), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(21), -PIXEL(29), PIXEL(19), PIXEL(9)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(21), -PIXEL(29), PIXEL(19), PIXEL(9)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(21), PIXEL(28), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(30), PIXEL(38)},
    },
};

// 0x08366ce8
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(23)};
