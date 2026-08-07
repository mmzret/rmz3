#include "global.h"
#include "score.h"
#include "weapon.h"
#include "stagerun.h"

// ラクサイガ雷が地面につくる電撃

static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

// 0x083616e0
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      element : ELEMENT_THUNDER,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};

void SmashElec_Init(Weapon* w);
void SmashElec_Update(Weapon* w);
void SmashElec_Die(Weapon* w);
static void SmashElec_Disappear(struct Entity* p);

// clang-format off
const WeaponRoutine gSmashElecRoutine = {
    [ENTITY_INIT] =      (void*)SmashElec_Init,
    [ENTITY_UPDATE] =    (void*)SmashElec_Update,
    [ENTITY_DIE] =       (void*)SmashElec_Die,
    [ENTITY_DISAPPEAR] = (void*)SmashElec_Disappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_SaberSmash(Weapon* p) {
  struct Zero* z = (struct Zero*)p->unk_28;
  if (P_ELEMENT(z) != ELEMENT_THUNDER || (z->unk_136 & (1 << 1))) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateSmashElec(struct Zero* z, Coords32* c, u8 leftOrRight) {
  struct Entity* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_RAKUSAIGA);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_RAKUSAIGA);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
    }
    p->unk_28 = (void*)z;
    (p->coord) = *c;
    p->work[0] = leftOrRight, p->work[1] = 0;
    z->saberSmashElecCount++;
  }
  return p;
}

void SmashElec_Init(Weapon* w) {
  register struct Zero* z asm("r8");
  register s32 zr asm("r6");
  register s32 zr2 asm("sb");
  register struct Body* bd asm("r4");
  register const struct Collision* col asm("r5");
  z = (struct Zero*)w->unk_28;
  {
    u32 tbl = (u32)gWeaponFnTable;
    EntityFunc** rt = (EntityFunc**)(((w->id) << 2) + tbl);
    register u32 one asm("r1");
    one = 1;
    *(u32*)(w->mode) = one;
    w->onUpdate = (void*)((*rt)[1]);
  }
  InitNonAffineMotion((struct Entity*)w);
  ResetDynamicMotion((struct Entity*)w);
  {
    register u8 g asm("r0");
    register u8 h asm("r1");
    h = w->flags2;
    asm("" : "+r"(h));
    g = 0xFB;
    g &= h;
    zr = 0;
    w->flags2 = g;
  }
  {
    register s32 z0 asm("r0");
    z0 = 0;
    asm volatile("strh %0, [%1, #0x20]" :: "l"(zr), "l"(w) : "memory");
    *((u8*)w + 0x22) = z0;
  }
  {
    register u8 g2 asm("r0");
    register s32 k asm("r1");
    register s32 k0 asm("r2");
    g2 = w->flags;
    k = 1;
    k0 = 0;
    asm volatile("mov %0, %1" : "=r"(zr2) : "l"(k0));
    g2 |= k;
    k = 2;
    g2 |= k;
    w->flags = g2;
  }
  SetMotion((struct Entity*)w, 0x1A06);
  {
    register u8 g3 asm("r0");
    register s32 k4 asm("r1");
    g3 = w->flags;
    k4 = 4;
    g3 |= k4;
    w->flags = g3;
  }
  bd = &w->body;
  col = (const struct Collision*)0x083616E0;
  InitBody(bd, col, &w->coord, 1);
  *(struct Weapon**)((u8*)bd + 0x2c) = w;
  *(s32*)((u8*)bd + 0x24) = zr;
  {
    register s32 atk asm("r2");
    register s32 m1 asm("r3");
    {
      register s32 rv asm("r0");
      rv = ((s32 (*)(struct Zero*))CalcSaberBonus)(z);
      asm volatile("add %0, %1, #0" : "=l"(atk) : "l"(rv));
    }
    atk += 8;
    atk = (u32)(atk << 24) >> 24;
    m1 = 1;
    m1 = -m1;
    ((void (*)(struct Body*, const struct Collision*, s32, s32, s32, s32))InitWeaponBody)(bd, col, atk, m1, m1, m1);
  }
  {
    register s32 wv asm("r2");
    register u8 g4 asm("r0");
    wv = w->work[0];
    if (wv != 0) {
      register s32 k10 asm("r1");
      g4 = w->flags;
      k10 = 0x10;
      g4 |= k10;
    } else {
      register u8 h4 asm("r1");
      h4 = w->flags;
      asm("" : "+r"(h4));
      g4 = 0xEF;
      g4 &= h4;
    }
    w->flags = g4;
    {
      register s32 v asm("r1");
      v = 1;
      v &= wv;
      *((u8*)w + 0x4c) = v;
      {
        register u8* oa asm("r3");
        register s32 sh asm("r1");
        register s32 ov asm("r2");
        register s32 m11 asm("r0");
        oa = (u8*)w + 0x4a;
        sh = v << 4;
        ov = *oa;
        m11 = 0x11;
        m11 = -m11;
        m11 &= ov;
        m11 |= sh;
        *oa = m11;
      }
    }
  }
  {
    register s32 dv asm("r0");
    if ((w->flags & 0x10) != 0) {
      dv = 0x80 << 3;
    } else {
      dv = 0xFFFFFC00;
    }
    w->d.x = dv;
  }
  {
    register s32 gy asm("r3");
    register s32 cy asm("r1");
    register s32 d asm("r2");
    gy = FUN_08009f6c(w->coord.x, w->coord.y);
    cy = w->coord.y;
    d = gy - cy;
    if (d < 0) {
      goto neg;
    }
    {
      register s32 lim2 asm("r0");
      lim2 = 0xf0 << 4;
      if (d > lim2) {
        goto die;
      }
      goto ok;
    }
  neg:
    {
      register s32 lim asm("r0");
      cy -= gy;
      lim = 0xf0 << 4;
      if (cy <= lim) {
        goto ok;
      }
    }
  die:
    {
      register u8 g5 asm("r0");
      register u8 h5 asm("r1");
      register s32 z5 asm("r2");
      h5 = w->flags;
      asm("" : "+r"(h5));
      g5 = 0xFE;
      g5 &= h5;
      z5 = 0;
      h5 = 0xFD;
      g5 &= h5;
      w->flags = g5;
      {
        u8* a = (u8*)w + 0x8c;
        *(s32*)a = z5;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = z5;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z5;
      }
    }
    w->flags &= 0xFB;
    {
      u32 tbl2 = (u32)gWeaponFnTable;
      EntityFunc** rt2 = (EntityFunc**)(((w->id) << 2) + tbl2);
      register u32 three asm("r1");
      three = 3;
      *(u32*)(w->mode) = three;
      w->onUpdate = (void*)((*rt2)[3]);
    }
    return;
  ok:
    w->coord.y = gy;
  }
  w->work[2] = 0xff;
  {
    register void* f asm("r1");
    register u8* b asm("r0");
    f = (void*)onCollision;
    b = (u8*)w + 0x74;
    *(void**)(b + 0x24) = f;
  }
  SmashElec_Update(w);
}

void SmashElec_Update(Weapon* p) {
  UpdateEntityAnim((struct Entity*)p);
  if (p->work[1] == 0) {
    s32 y;
    s32 cy;
    s32 d;
    p->work[2]--;
    p->coord.x += p->d.x;
    y = FUN_08009f6c(p->coord.x, p->coord.y);
    cy = p->coord.y;
    d = y - cy;
    if (d >= 0) {
      if (d > 0xF00) {
        goto die;
      }
    } else {
      if (cy - y > 0xF00) {
        goto die;
      }
    }
    p->coord.y = y;
    if ((u8)--p->work[2] != 0xFF) {
      goto cam;
    }
  }
die:
  SET_WEAPON_ROUTINE(p, 2);
  SmashElec_Die(p);
  return;
cam:
  if (Camera_GetDistance(&gStageRun.vm.camera, &p->coord) > 0x3000) {
    SET_WEAPON_ROUTINE(p, 2);
    SmashElec_Die(p);
  }
}

void SmashElec_Die(Weapon* w) {
  struct Zero* z = (struct Zero*)w->unk_28;
  if (z->saberSmashElecCount != 0) z->saberSmashElecCount--;
  {
    u8 f = ~DISPLAY & w->flags;
    s32 z0 = 0;
    w->flags = f;
    (w->body).status = z0;
    (w->body).prevStatus = z0;
    (w->body).invincibleTime = z0;
  }
  w->flags &= ~COLLIDABLE;
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
}

static void SmashElec_Disappear(struct Entity* p) {
  Player* z = (Player*)(p->unk_28);
  if (z->saberSmashElecCount != 0) z->saberSmashElecCount--;
  p->flags &= ~DISPLAY;
  DeleteWeapon(p);
}

// 0x0803cb64
static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B2) {
    struct Entity* p = (struct Entity*)body->parent;
    IncWeaponUseCount(WEAPON_SABER);
    p->work[1] = 1;
  }
}
