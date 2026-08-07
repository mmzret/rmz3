#include "collision.h"
#include "global.h"

static void hitZSaber(struct Body* body);
#include "weapon.h"
#include "score.h"

// Saber wave by cyberelf, Cottus
typedef struct {
  COLLISION_OBJECT_HDR;
  struct SaberWave_b4 {
    Weapon* saber;  // 0xB4, projectile -> saber (if saber, this is null)
    Player* z;      // 0xB8
    u8 props[4];    // 0xBC
    u8 element;     // 0xC0
    u8 atk;         // 0xC1
    u8 flags;       // 0xC2
    bool8 unk;      // 0xC3
    u8 unk_c4[40];  // 0xC4
  } props;          // props (56bytes, offset: 0xB4..)
} SaverWave;
static_assert(sizeof(SaverWave) == sizeof(Weapon));

// 0x08361338
static const struct Collision sCollisions[16] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x1000, 0x0000, 0x2000, 0x0800},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x1000, 0x0000, 0x2000, 0x0800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0F00, 0x0000, 0x1E00, 0x0800},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0F00, 0x0000, 0x1E00, 0x0800},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0E00, 0x0000, 0x1C00, 0x0C00},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0E00, 0x0000, 0x1C00, 0x0C00},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0D00, 0x0000, 0x1A00, 0x1000},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0D00, 0x0000, 0x1A00, 0x1000},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0C00, 0x0000, 0x1800, 0x1400},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0C00, 0x0000, 0x1800, 0x1400},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0B00, 0x0000, 0x1600, 0x1800},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0B00, 0x0000, 0x1600, 0x1800},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0A00, 0x0000, 0x1400, 0x1C00},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0A00, 0x0000, 0x1400, 0x1C00},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0700, 0x0000, 0x1000, 0x2000},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0700, 0x0000, 0x1000, 0x2000},
    },
};

void Weapon5_Init(SaverWave* p);
void Weapon5_Update(SaverWave* p);
void Weapon5_Die(SaverWave* p);

// clang-format off
const WeaponRoutine gSaberWaveRoutine = {
    [ENTITY_INIT] =      (void*)Weapon5_Init,
    [ENTITY_UPDATE] =    (void*)Weapon5_Update,
    [ENTITY_DIE] =       (void*)Weapon5_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

struct Entity* CreateSaberWave(Player* z, Weapon* saber, bool8 isProjectile) {
  SaverWave* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SABER_WAVE);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SABER_WAVE);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
    }
    (&p->props)->saber = saber;
    (&p->props)->z = z;
    p->work[0] = isProjectile, p->work[1] = 0;
    if (!isProjectile) CreateSaberWave(z, (void*)p, TRUE);
  }
  return (struct Entity*)p;
}

void Weapon5_Init(SaverWave* w) {
  register struct Entity* e asm("r8");
  register struct Zero* z asm("sb");
  register s32 one asm("r4");
  register s32 zr asm("r5");
  {
    u8* q = (u8*)w + 0xb4;
    z = *(struct Zero**)(q + 4);
    e = *(struct Entity**)q;
  }
  {
    u32 tbl = (u32)gWeaponFnTable;
    EntityFunc** rt = (EntityFunc**)(((w->id) << 2) + tbl);
    one = 1;
    *(u32*)(w->mode) = one;
    w->onUpdate = (void*)((*rt)[1]);
  }
  InitScalerotMotion1((struct Entity*)w);
  {
    register u8 g asm("r0");
    register s32 h asm("r1");
    h = w->flags2;
    asm("" : "+r"(h));
    g = 0xFB;
    g &= h;
    h = 0;
    w->flags2 = g;
    {
      register s32 z0 asm("r0");
      z0 = 0;
      asm volatile("strh %0, [%1, #0x20]" :: "l"(h), "l"(w) : "memory");
      *((u8*)w + 0x22) = z0;
    }
  }
  {
    register u8 g2 asm("r0");
    register s32 k asm("r1");
    g2 = w->flags;
    k = 1;
    zr = 0;
    asm volatile("" : "+r"(zr));
    g2 |= k;
    k = 2;
    g2 |= k;
    w->flags = g2;
  }
  SetMotion((struct Entity*)w, 0x1c);
  {
    register s32 v asm("r2");
    register s32 g3 asm("r0");
    {
      register struct Entity* ee asm("r1");
      ee = e;
      g3 = ee->flags;
    }
    v = (u32)g3 >> 4;
    v &= one;
    if (v != 0) {
      register s32 k10 asm("r1");
      g3 = w->flags;
      k10 = 0x10;
      g3 |= k10;
    } else {
      register s32 h3 asm("r1");
      h3 = w->flags;
      asm("" : "+r"(h3));
      g3 = 0xEF;
      g3 &= h3;
    }
    w->flags = g3;
    {
      register s32 sh asm("r1");
      register u8* oa asm("r2");
      asm volatile("add %0, %1, #0" : "=l"(sh) : "l"(v));
      *((u8*)w + 0x4c) = sh;
      oa = (u8*)w + 0x4a;
      sh <<= 4;
      {
        register s32 ov asm("r3");
        register s32 m11 asm("r0");
        ov = *oa;
        m11 = 0x11;
        m11 = -m11;
        m11 &= ov;
        m11 |= sh;
        *oa = m11;
      }
      {
        register s32 w0 asm("r3");
        register u8* oa2 asm("r4");
        register s32 g4 asm("r0");
        w0 = w->work[0];
        oa2 = oa;
        if (w0 != 0) {
          register s32 k20 asm("r1");
          g4 = w->flags;
          k20 = 0x20;
          g4 |= k20;
        } else {
          register s32 h4 asm("r1");
          h4 = w->flags;
          asm("" : "+r"(h4));
          g4 = 0xDF;
          g4 &= h4;
        }
        w->flags = g4;
        {
          register s32 v2 asm("r0");
          v2 = 1;
          asm volatile("and %0, %1" : "+l"(v2) : "l"(w0));
          *((u8*)w + 0x4d) = v2;
          v2 <<= 5;
          {
            register s32 ov2 asm("r2");
            register s32 m21 asm("r1");
            ov2 = *oa2;
            m21 = 0x21;
            m21 = -m21;
            m21 &= ov2;
            m21 |= v2;
            *oa2 = m21;
          }
        }
      }
    }
  }
  {
    s32 w1;
    register struct Body* bd asm("r4");
    register const struct Collision* col asm("r5");
    w1 = w->work[0];
    if (w1 != 0) {
      goto upd;
    }
    {
      register u8 g5 asm("r0");
      register s32 k4 asm("r1");
      g5 = w->flags;
      k4 = 4;
      g5 |= k4;
      w->flags = g5;
    }
    bd = &w->body;
    col = (const struct Collision*)0x08361338;
    InitBody(bd, col, &w->coord, 1);
    *(struct Entity**)((u8*)bd + 0x2c) = (struct Entity*)w;
    *(s32*)((u8*)bd + 0x24) = w1;
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
      register s32 uv asm("r0");
      if ((w->flags & 0x10) != 0) {
        register s32 k5 asm("r1");
        {
          register struct Entity* e2 asm("r1");
          e2 = e;
          uv = (e2->coord).x;
        }
        k5 = 0x88 << 6;
        uv += k5;
        w->coord.x = uv;
        w->d.x = 0x80 << 3;
        uv = 0x55;
        uv = -uv;
      } else {
        register s32 k6 asm("r1");
        {
          register struct Entity* e3 asm("r1");
          e3 = e;
          uv = (e3->coord).x;
        }
        k6 = 0xFFFFDE00;
        uv += k6;
        w->coord.x = uv;
        w->d.x = 0xFFFFFC00;
        uv = 0x55;
      }
      w->unk_coord.x = uv;
    }
    {
      register s32 cy asm("r0");
      register s32 k7 asm("r1");
      {
        register struct Entity* e4 asm("r1");
        e4 = e;
        cy = (e4->coord).y;
      }
      k7 = 0xFFFFEC00;
      cy += k7;
      w->coord.y = cy;
    }
    w->work[2] = 0x12;
    *(void**)((u8*)bd + 0x24) = (void*)hitZSaber;
  }
upd:
  Weapon5_Update(w);
}

void Weapon5_Update(SaverWave* w) {
  u8* pp = (u8*)w + 0xb4;
  struct Entity* sb = *(struct Entity**)pp;
  register struct Zero* z asm("r8");
  z = *(struct Zero**)(pp + 4);
  if (sb->mode[0] > 1) {
    u8 f = ~1 & w->flags;
    s32 z2;
    z2 = 0;
    f = f & ~2;
    w->flags = f;
    {
      u8* a = (u8*)w + 0x8c;
      *(u32*)a = z2;
      asm("" : "+r"(a));
      a += 4;
      *(u32*)a = z2;
      asm("" : "+r"(a));
      a += 4;
      asm("" : "+r"(a));
      *a = z2;
    }
    w->flags &= 0xFB;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }
  UpdateEntityAnim((struct Entity*)w);
  if (w->work[0] == 0) {
    if ((w->body).status & 0x1000) {
      PlaySound(0x2B);
    }
    {
      u32 t = (u8)--w->work[2];
      if (t == 0) {
        goto die;
      }
      w->coord.x += w->d.x;
      {
        s32 mg1;
        register s32 mg2 asm("r4");
        if (t <= 0xB) {
          register s32 h asm("r5");
          s32 q;
          w->d.x += w->unk_coord.x;
          q = 0xC - w->work[2];
          mg1 = q << 8;
          asm("" : "+r"(mg1));
          mg2 = mg1;
          mg1 = mg2 / 12;
          h = 0x100;
          mg1 += h;
          mg2 = -mg2;
          mg2 = mg2 / 12;
          asm("" : "+r"(mg2));
          mg2 += h;
        } else {
          mg2 = 0x100;
          mg1 = mg2;
        }
        {
          register u8* mp asm("r0");
          mp = (u8*)w + 0x50;
          *(u16*)mp = mg1;
          asm("" : "+r"(mp));
          mp += 2;
          asm("" : "+r"(mp));
          *(u16*)mp = mg2;
        }
        mg2 += 0x10;
        asm("" : "+r"(mg2));
        {
          register s32 tc asm("r0");
          tc = mg2;
          asm("" : "+r"(tc));
          if (mg2 < 0) {
            tc += 0x1F;
          }
          {
          s32 v = tc >> 5;
          if (v != 0) {
            u8 dmg = CalcSaberBonus(z) + 8;
            if (v > 7) {
              v = 7;
            }
            InitWeaponBody(&w->body, &sCollisions[v * 2], dmg, -1, -1, -1);
          }
          }
        }
      }
    }
  } else {
    if (sb->mode[0] <= 1) {
      w->coord.x = (sb->coord).x;
      w->coord.y = (sb->coord).y;
      {
        u16 m1 = *(u16*)((u8*)sb + 0x50);
        *(u16*)((u8*)w + 0x50) = m1;
      }
      {
        u16 m2 = *(u16*)((u8*)sb + 0x52);
        *(u16*)((u8*)w + 0x52) = m2;
      }
    } else {
    die:
      SET_WEAPON_ROUTINE(w, ENTITY_DIE);
      Weapon5_Die(w);
    }
  }
}

void Weapon5_Die(SaverWave* w) {
  EXIT_BODY(w);
  w->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
}

static void hitZSaber(struct Body* body) {
  if (body->hitboxFlags & BODY_STATUS_B2) {
    if (gScore.weaponCount[WEAPON_SABER] <= 0xFFFE) {
      gScore.weaponCount[WEAPON_SABER]++;
    }
  }
}
