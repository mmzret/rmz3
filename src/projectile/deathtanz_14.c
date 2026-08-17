#include "collision.h"
#include "global.h"
#include "projectile.h"

static const struct Collision sCollisions[10];

typedef struct {
  COLLISION_OBJECT_HDR;
  u8 unk_b4[8];  // 0xB4
  u8 unk_bc;     // 0xBC
  u32 unk_c0;    // 0xC0
} Projectile14;
static_assert(sizeof(Projectile14) == sizeof(Projectile));

void Projectile14_Init(Projectile14* p);
void Projectile14_Update(Projectile14* p);
void Projectile14_Die(Projectile14* p);

// clang-format off
const ProjectileRoutine gProjectile14Routine = {
    [ENTITY_INIT] =      (void*)Projectile14_Init,
    [ENTITY_UPDATE] =    (void*)Projectile14_Update,
    [ENTITY_DIE] =       (void*)Projectile14_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a0888(s32 x, s32 y, u8 kind, bool8 xflip) {
  struct Entity* p = (struct Entity*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 4;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = kind, p->work[3] = xflip;
  }
}

void FUN_080a08e0(struct Entity* q, s32 x, s32 y, bool8 xflip) {
  struct Entity* p = (struct Entity*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = xflip;
    p->unk_28 = q;
  }
}

void deathtanz_080a0934(struct Entity* q, s32 x, s32 y, bool8 xflip, bool8 r4) {
  Projectile14* p = (Projectile14*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 1;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = xflip;
    p->unk_28 = q, p->unk_bc = r4;
  }
}

void deathtanz_080a09a0(struct Entity* q, s32 x, s32 y, bool8 xflip) {
  struct Entity* p = (struct Entity*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 2;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = xflip;
    p->unk_28 = q;
  }
}

void deathtanz_080a09f4(struct Entity* q, s32 x, s32 y, u8 kind, bool8 xflip) {
  struct Entity* p = (struct Entity*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 14);
    p->work[0] = 3;
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = kind, p->work[3] = xflip;
    p->unk_28 = q;
  }
}

// 0x080a0a5c
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

INCASM("asm/projectile/unk_14_a.inc");

void FUN_080a0dc0(Projectile14* p) {
  struct Entity* q = p->unk_28;
  s32 lim, k, z, lim4;

  switch (p->mode[2]) {
    case 0:
      p->unk_coord.y = p->coord.y;
      SetDDP(&p->body, sCollisions);
      p->d.x = 0x80;
      SetSpriteAnimation(p, 0x3701);
      p->mode[2]++;
      /* fallthrough */
    case 1:
      if (p->work[2] != 0) {
        p->coord.x += p->d.x;
        if (p->coord.x > *(s32*)((u8*)p + 0xb4) + 0x6800) {
          goto bump1;
        }
        break;
      bump1:
        goto bump;
      } else {
        p->coord.x -= p->d.x;
        if (p->coord.x < *(s32*)((u8*)p + 0xb4) - 0x6800) {
          goto bump2;
        }
        break;
      bump2:
        goto bump;
      }
    case 2:
      p->coord.y -= p->d.x;
      lim = *(s32*)((u8*)p + 0xb8) - 0x9000;
      if (p->coord.y >= lim) {
        break;
      }
      p->coord.y = lim;
      goto bump;
    case 3:
      p->work[2] ^= 1;
      p->mode[2]++;
      /* fallthrough */
    case 4:
      if (p->work[2] != 0) {
        register s32 nx asm("r2");
        register s32 kk asm("r0");
        nx = p->coord.x;
        nx += p->d.x;
        p->coord.x = nx;
        kk = *((u8*)p + 0xbc);
        kk <<= 11;
        kk -= 0x800;
        lim4 = (q->coord).x;
        lim4 -= kk;
        if (nx <= lim4) {
          break;
        }
      } else {
        register s32 nx asm("r2");
        register s32 kk asm("r0");
        nx = p->coord.x;
        nx -= p->d.x;
        p->coord.x = nx;
        kk = *((u8*)p + 0xbc);
        kk <<= 11;
        kk -= 0x800;
        lim4 = (q->coord).x;
        lim4 += kk;
        if (nx >= lim4) {
          break;
        }
      }
      p->coord.x = lim4;
    bump:
      p->mode[2]++;
      break;
    case 5: {
      register s32 ny asm("r2");
      register s32 kv asm("r1");
      s32 lim5;
      ny = p->coord.y;
      ny += p->d.x;
      p->coord.y = ny;
      kv = *((u8*)p + 0xbc);
      k = kv * 3 << 11;
      k += 0x1000;
      lim5 = p->unk_coord.y;
      lim5 -= k;
      if (ny > lim5) {
        p->mode[2]++;
        *((u8*)q + 0xbe) = 1;
      }
      break;
    }
    case 6:
      p->work[2] = 2;
      p->mode[2]++;
      /* fallthrough */
    case 7:
      lim = p->work[2] - 1;
      p->work[2] = lim;
      z = (u8)lim;
      if (z != 0) {
        break;
      }
      p->flags &= ~DISPLAY;
      p->flags &= ~FLIPABLE;
      (p->body).status = z;
      (p->body).prevStatus = z;
      (p->body).invincibleTime = z;
      p->flags &= ~COLLIDABLE;
      SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
  }
  UpdateEntityAnim((struct Entity*)p);
  p->d.x += 0x30;
  if (p->d.x > 0xA00) {
    p->d.x = 0xA00;
  }
  if (q->mode[0] > 1) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

INCASM("asm/projectile/unk_14_b.inc");

void nop_080a0b6c(Projectile14* p);

// clang-format off
// 0x0836b0f4
static const ProjectileFunc sUpdates1[5] = {
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
    (void*)nop_080a0b6c,
};
// clang-format on

void FUN_080a0b70(Projectile14* p);
void FUN_080a0dc0(Projectile14* p);
void FUN_080a0fa8(Projectile14* p);
void FUN_080a1280(Projectile14* p);
void FUN_080a133c(Projectile14* p);

// clang-format off
// 0x0836b108
static const ProjectileFunc sUpdates2[5] = {
    (void*)FUN_080a0b70,
    (void*)FUN_080a0dc0,
    (void*)FUN_080a0fa8,
    (void*)FUN_080a1280,
    (void*)FUN_080a133c,
};
// clang-format on

// --------------------------------------------

// 0x0836b11c
static const struct Collision sCollisions[10] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(40), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(50), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(26), PIXEL(50)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(4), PIXEL(2), PIXEL(40), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(20), PIXEL(19), PIXEL(8), PIXEL(51)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(60)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(57), -PIXEL(24), PIXEL(36), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(11), PIXEL(37), PIXEL(13)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(57), -PIXEL(39), PIXEL(36), PIXEL(14)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(53), PIXEL(37), PIXEL(13)},
    },
};

// 0x0836b20c
static const u8 u8_ARRAY_0836b20c[5] = {0, 1, 2, 3, 4};

// 0x0836b211
static const u8 u8_ARRAY_0836b211[2] = {6, 8};
