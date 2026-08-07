#include "collision.h"
#include "global.h"
#include "weapon.h"

static const motion_t sMotions[4];
static const struct Collision sCollisions[2];

NON_MATCH void Weapon13_Init(Weapon* p);
void Weapon13_Update(Weapon* p);
void Weapon13_Die(Weapon* p);

// clang-format off
const WeaponRoutine gWeapon13Routine = {
    [ENTITY_INIT] =      (void*)Weapon13_Init,
    [ENTITY_UPDATE] =    (void*)Weapon13_Update,
    [ENTITY_DIE] =       (void*)Weapon13_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_Weapon13(WeaponCommon* p) {
  if ((p->props).z->unk_136 & (1 << 2)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateWeapon13(struct Zero* z, u8 n) {
  u8 element;
  WeaponCommon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_ROD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_13);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(0, element);
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_13);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(1, element);
    }
    (p->props).z = z;
    p->work[0] = n;
    p->work[1] = ++z->unk_137;
  }
  return (void*)p;
}

NON_MATCH void Weapon13_Init(Weapon* w) {
#if MODERN

  struct Zero* z = (*(struct Zero**)w->buffer);
  u8 w0;
  u8 ang;
  register u32 zf2v asm("r2");
  InitNonAffineMotion((struct Entity*)w);
  ResetDynamicMotion((struct Entity*)w);
  w->flags |= FLIPABLE;
  SetMotion((struct Entity*)w, sMotions[w->work[0]]);
  {
    register u8 fl asm("r1");
    u32 xf;
    fl = w->flags;
    fl |= DISPLAY;
    w->flags = fl;
    xf = (z->s.flags >> 4) & 1;
    if (xf) {
      fl |= X_FLIP;
    } else {
      fl &= ~X_FLIP;
    }
    w->flags = fl;
    w->spr.xflip = xf & 1;
    w->spr.oam.xflip = xf;
  }
  {
    u8 w0a = *(volatile u8*)((u8*)w + 0x10);
    if (w0a == 0 || w0a == 3) {
      u8 zfl = z->s.flags;
      u32 t = zfl & 0x10;
      zf2v = zfl & 0xFF;
      if (t != 0) {
        ang = u8_ARRAY_083616d4[0] + 0x80;
        w0 = w->work[0];
      } else {
        ang = u8_ARRAY_083616d4[0];
        w0 = w->work[0];
      }
    } else {
      w0 = w->work[0];
      ang = u8_ARRAY_083616d4[w0];
      zf2v = z->s.flags;
    }
  }
  if (zf2v & 0x10) {
    w->coord.x = z->s.coord.x - (s8_ARRAY_ARRAY_083616cc[0][w0] << 8);
  } else {
    w->coord.x = z->s.coord.x + (s8_ARRAY_ARRAY_083616cc[0][w0] << 8);
  }
  {
    const s8* row1 = &s8_ARRAY_ARRAY_083616cc[1][0];
    asm("" : "+r"(row1));
    w->coord.y = z->s.coord.y + (row1[z->s.work[0]] << 8);
  }
  {
    s32 dx;
    s32 dy;
    dx = gSineTable[(u8)(ang + 0x40)] << 2;
    w->d.x = dx;
    if (w->work[0] == 3) {
      w->d.x = -dx;
      {
        u32 sh = z->s.flags >> 4;
        u32 nf = 1;
        nf &= ~sh;
        if (nf) {
          w->flags |= X_FLIP;
        } else {
          w->flags &= ~X_FLIP;
        }
        w->spr.xflip = nf & 1;
        w->spr.oam.xflip = nf;
      }
    }
    dy = gSineTable[ang] << 2;
    w->d.y = dy;
    w->unk_coord.x = w->d.x / 0x1A;
    w->unk_coord.y = dy / 0x1A;
  }
  SET_WEAPON_ROUTINE(w, ENTITY_UPDATE);
  Weapon13_Update(w);

#else
  INCCODE("asm/weapon/unk_13_init.inc");
#endif
}

void Weapon13_Update(Weapon* w) {
  if (w->work[1] != (*(struct Zero**)w->buffer)->unk_137) {
    w->flags &= ~DISPLAY;
    w->flags &= ~FLIPABLE;
    EXIT_BODY(w);
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }
  UpdateEntityAnim((struct Entity*)w);
  w->coord.x += w->d.x;
  w->coord.y += w->d.y;
  w->d.x = w->d.x - w->unk_coord.x;
  w->d.y = w->d.y - w->unk_coord.y;
  if (w->motion.state == 3) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
    Weapon13_Die(w);
  }
}

void Weapon13_Die(Weapon* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

static const s8 s8_ARRAY_ARRAY_083616cc[2][4] = {
    {0xEA, 0xF5, 0x03, 0x16},
    {0xF2, 0xD8, 0x02, 0xF3},
};  // 0x083616cc

// 0x083616d4
static const u8 u8_ARRAY_083616d4[4] = {0x80, 0xC0, 0x40, 0x00};

// 0x083616d8
static const motion_t sWeapon13Animations[4] = {
    MOTION(DM104_UNK, 0),
    MOTION(DM104_UNK, 1),
    MOTION(DM104_UNK, 1),
    MOTION(DM104_UNK, 0),
};
