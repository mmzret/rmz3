#include "collision.h"
#include "global.h"
#include "physics.h"
#include "weapon.h"
#include "score.h"

void FUN_0803b4b0(struct Body* body);
s32 FUN_0800a40c(s32 x, s32 y);

typedef struct {
  COLLISION_OBJECT_HDR;
  struct SoulLauncherProps {
    struct Zero* z;  // 0xB4
    u8 unk_b8[8];    // 0xB8
    u8 unk_c0;       // 0xC0
    u8 element;      // 0xC1
    u8 unk_c2[42];   // 0xC2
  } props;
} SoulLauncher;
static_assert(sizeof(SoulLauncher) == sizeof(Weapon));

static const struct Collision sCollisions[2];


void SoulLauncher_Die(SoulLauncher* p);
metatile_attr_t FUN_0803b4e8(s32 x, s32 y);
void SoulLauncher_Update(SoulLauncher* p);
void MenuExit_SoulLauncher(SoulLauncher* p) {
  struct Zero* z = (struct Zero*)p->unk_28;
  if (((&p->props)->element != ((&z->unk_b4)->status).element) || (z->unk_136 & (1 << WEAPON_ROD))) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateSoulLauncher(struct Zero* z, u8 r1, u8 r2) {
  SoulLauncher* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_ROD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SOUL_LANCHER);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SOUL_LANCHER);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
    }
    p->unk_28 = (void*)z;
    p->work[0] = r1, p->work[1] = r2;
    (&p->props)->element = ((&z->unk_b4)->status).element;
  }
  return (void*)p;
}

void SoulLauncher_Init(SoulLauncher* p) {
  struct Zero* z;
  register struct Body* b asm("r4");
  register const struct Collision* coll asm("r8");
  register s32 z5 asm("r5");
  z = (struct Zero*)p->unk_28;
  SET_WEAPON_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion((struct Entity*)p);
  ResetDynamicMotion((struct Entity*)p);
  {
    register u8 fl asm("r1");
    register s32 f asm("r0");
    fl = p->flags;
    f = 1;
    f |= fl;
    {
      register s32 k asm("r1");
      k = 2;
      f |= k;
    }
    p->flags = f;
  }
  if (p->work[1] == 1) {
    SetMotion((struct Entity*)p, 0xCE * 128);
  } else {
    SetMotion((struct Entity*)p, MOTION(0x67, 0x03));
  }
  {
    register s32 zz asm("r2");
    u8* oa;
    s32 m11, ov;
    zz = 0;
    {
      register u8 h asm("r1");
      register u8 g asm("r0");
      h = p->flags;
      asm("" : "+r"(h));
      g = 0xEF;
      g &= h;
      p->flags = g;
    }
    *((u8*)p + 0x4c) = zz;
    oa = (u8*)p + 0x4a;
    ov = *oa;
    m11 = -0x11;
    m11 &= ov;
    *oa = m11;
  }
  {
    register s32 dx asm("r1");
    register s32 cx asm("r0");
    if (((z->s).flags & 0x10) != 0) {
      cx = (z->s).coord.x;
      dx = 0xB0 * 16;
    } else {
      cx = (z->s).coord.x;
      dx = -0xB00;
    }
    p->coord.x = cx + dx;
  }
  p->coord.y = (z->s).coord.y + -0x4800;
  {
    register const s32* tb asm("r1");
    tb = (const s32*)0x0836159C;
    asm("" : "+r"(tb));
    p->d.x = tb[p->work[0]];
  }
  p->d.y = -0x700;
  z5 = 0;
  p->mode[1] = 5;
  p->work[2] = 0x40;
  {
    u8* a = (u8*)p + 0xb4;
    a[0xc] = z5;
  }
  {
    register u8 fl4 asm("r1");
    register s32 f4 asm("r0");
    fl4 = p->flags;
    f4 = 4;
    f4 |= fl4;
    p->flags = f4;
  }
  b = &p->body;
  coll = (const struct Collision*)0x08361558;
  ((void (*)(struct Body*, const struct Collision*, struct Coord*, s32))InitBody)(b, coll, &p->coord, 1);
  b->parent = (struct Entity*)p;
  b->fn = (BodyFunc)z5;
  if (p->work[1] == 0) {
    {
      register s32 bo asm("r0");
      register u32 bv asm("r2");
      bo = ((s32(*)(struct Zero*))CalcRodBonus)(z);
      bo += 8;
      bo <<= 24;
      bv = (u32)bo >> 24;
      ((void (*)(struct Body*, const struct Collision*, s32, s32, s32, s32))InitWeaponBody)(b, coll, bv, 0, -1, -1);
    }
  } else {
    {
      register s32 bo2 asm("r0");
      register u32 bv2 asm("r2");
      bo2 = ((s32(*)(struct Zero*))CalcRodBonus)(z);
      bo2 += 0xA;
      bo2 <<= 24;
      bv2 = (u32)bo2 >> 24;
      ((void (*)(struct Body*, const struct Collision*, s32, s32, s32, s32))InitWeaponBody)(b, coll, bv2, 2, -1, -1);
    }
  }
  b->fn = (BodyFunc)FUN_0803b4b0;
  SoulLauncher_Update(p);
  asm volatile("" ::"l"(z));
}

void SoulLauncher_Update(SoulLauncher* p) {
  s32 r, z2, zv;
  u16 atv;

  if (((struct SoulLauncherProps*)((u8*)p + 0xb4))->unk_c0 != 0) {
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    p->flags &= ~COLLIDABLE;
  }
  p->coord.x += FUN_0800a40c(p->coord.x, p->coord.y + 0x800);
  switch (p->mode[1]) {
    case 0:
      UpdateEntityAnim((struct Entity*)p);
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      p->d.y += 0x40;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      if ((u16)FUN_0803b4e8(p->coord.x, p->coord.y) == 0) {
        break;
      }
      r = PushoutToUp1(p->coord.x, p->coord.y);
      if (r >= -0x800) {
        p->coord.y += r;
      }
      if (p->work[1] != 0) {
        p->mode[1] = 1;
        break;
      }
      goto die;
    case 1:
      SetMotion((struct Entity*)p, 0x6701);
      p->work[2] = 0x40;
      p->mode[1] = 2;
      /* fallthrough */
    case 2:
      UpdateEntityAnim((struct Entity*)p);
      if ((u16)FUN_0803b4e8(p->coord.x, p->coord.y + 1) == 0) {
        p->coord.y += p->d.y;
      }
      r = PushoutToUp1(p->coord.x, p->coord.y);
      if ((u32)(r + 0x800) <= 0x7FF) {
        p->coord.y += r;
      }
      p->work[2]--;
      if ((u8)p->work[2] == 0xFF) {
        p->mode[1] = 3;
      }
      break;
    case 3:
      SetMotion((struct Entity*)p, 0x6702);
      p->mode[1] = 4;
      /* fallthrough */
    case 4:
      UpdateEntityAnim((struct Entity*)p);
      if ((u16)FUN_0803b4e8(p->coord.x, p->coord.y + 1) == 0) {
        p->coord.y += p->d.y;
        r = PushoutToUp1(p->coord.x, p->coord.y);
        if (r >= -0x800) {
          p->coord.y += r;
        }
      }
      if (p->motion.state != 3) {
        break;
      }
    die:
      SET_WEAPON_ROUTINE(p, ENTITY_DIE);
      SoulLauncher_Die(p);
      break;
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      p->coord.y += p->d.y;
      atv = FUN_080098a4(p->coord.x, p->coord.y);
      if (atv != 0) {
        zv = (u16)(atv & 0x8000);
        if (zv == 0) {
          r = PushoutToDown1(p->coord.x, p->coord.y);
          if (r < -p->d.y) {
            p->coord.y += r;
          }
          p->d.y = zv;
          p->mode[1] = zv;
          break;
        }
      }
      p->work[2]--;
      z2 = 0;
      if ((u8)p->work[2] == 0xFF) {
        p->d.y = z2;
        p->mode[1] = z2;
      }
      break;
  }
}

void SoulLauncher_Die(SoulLauncher* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

void FUN_0803b4b0(struct Body* body) {
  if (body->hitboxFlags & BODY_STATUS_B2) {
    struct Weapon* w = (struct Weapon*)body->parent;
    if (gScore.weaponCount[WEAPON_ROD] <= 0xFFFE) {
      gScore.weaponCount[WEAPON_ROD]++;
    }
    if (w->work[1] == 0) {
      ((struct SoulLauncherProps*)((u8*)w + 0xb4))->unk_c0 = 1;
    }
  }
}

metatile_attr_t FUN_0803b4e8(s32 x, s32 y) {
  metatile_attr_t result = FUN_080098a4(x, y);
  if (result == 0x800F) {
    result = 0;
  }
  return result;
}

// 0x08361558
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 1,
      atkType : ATK_SOUL_LAUNCHER,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00200000,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
};

// --------------------------------------------

void SoulLauncher_Init(SoulLauncher* p);
void SoulLauncher_Update(SoulLauncher* p);
void SoulLauncher_Die(SoulLauncher* p);

// clang-format off
const WeaponRoutine gSoulLauncherRoutine = {
    [ENTITY_INIT] =      (void*)SoulLauncher_Init,
    [ENTITY_UPDATE] =    (void*)SoulLauncher_Update,
    [ENTITY_DIE] =       (void*)SoulLauncher_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

// 0x0836159c
static const s32 sSoulLauncherDx[4] = {-PIXEL(2), -PIXEL(1), PIXEL(1), PIXEL(2)};
