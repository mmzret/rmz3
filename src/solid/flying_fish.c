#include "collision.h"
#include "entity.h"
#include "global.h"
#include "pickup.h"
#include "mod.h"
#include "overworld.h"
#include "solid.h"
#include "vfx.h"

// 改造カードでベースに出現するトビウオ

// Entity.work[0]
#define FLYING_FISH_MANAGER 0
#define FLYING_FISH_MAIN 1

static const struct Collision sCollisions[2];

static void Solid37_Init(struct Solid* p);
static void Solid37_Update(struct Solid* p);
static void Solid37_Die(struct Solid* p);

// clang-format off
const SolidRoutine gFlyingFishRoutine = {
    [ENTITY_INIT] =      (void*)Solid37_Init,
    [ENTITY_UPDATE] =    (void*)Solid37_Update,
    [ENTITY_DIE] =       (void*)Solid37_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x080dc768
static void CreateFlyingFish(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_FLYING_FISH);
    p->unk_28 = e;
    p->coord = e->coord;
    p->work[0] = FLYING_FISH_MAIN, p->work[1] = 0;
  }
}

static void FUN_080dc81c(struct Solid* p);
void FUN_080dc900(struct Solid* p);

static void Solid37_Init(struct Solid* p) {
  if ((p->s).work[0] == FLYING_FISH_MANAGER) {
    FUN_080dc81c(p);  // spawner
  } else {
    FUN_080dc900(p);  // spawned fish
  }
}

static void FUN_080dc898(struct Solid* p);
void FUN_080dca60(struct Solid* p);

static void Solid37_Update(struct Solid* p) {
  if ((p->s).work[0] == FLYING_FISH_MANAGER) {
    FUN_080dc898(p);
  } else {
    FUN_080dca60(p);
  }
}

static void FUN_080dc8e8(struct Entity* p);
static void FUN_080dcb80(struct Solid* p);

static void Solid37_Die(struct Solid* p) {
  if ((p->s).work[0] == FLYING_FISH_MANAGER) {
    FUN_080dc8e8((void*)p);
  } else {
    FUN_080dcb80(p);
  }
}

// --------------------------------------------

// 0x080dc81c
static void FUN_080dc81c(struct Solid* p) {
  if (!FLAG(gSystemSavedata.flags, MOD_FLYING_FISH)) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (p->s).work[2] = 0, (p->s).work[3] = 30;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid37_Update(p);
}

static void FUN_080dc898(struct Solid* p) {
  if ((--(p->s).work[3]) == 0xFF) {
    CreateFlyingFish((void*)p);
    (p->s).work[3] = (RANDOM(RNG_0202f388) & 0x1F) + 8;
  }
  if ((p->s).work[2] > 30) (p->s).work[2] = 0;
}

static void FUN_080dc8e8(struct Entity* p) { SET_SOLID_ROUTINE(p, ENTITY_EXIT); }

void FUN_080dc900(struct Solid* p) {
  register s32 one4 asm("r4");
  u32 keep7;
  {
    u32 tbl = (u32)(gSolidFnTable);
    u32 id;
    EntityFunc** rt;
    id = ((p->s).id) << 2;
    rt = (EntityFunc**)(tbl + id);
    one4 = 1;
    *(u32*)((p->s).mode) = one4;
    (p->s).onUpdate = (void*)(*rt)[1];
  }
  if (((p->s).unk_28)->work[2] == 0x1E) {
    InitScalerotMotion1(&p->s);
    {
      u16* mg = (u16*)((u8*)p + 0x50);
      register u32 mv asm("r1");
      mv = 0x200;
      *mg = mv;
      asm("" : "+r"(mg));
      mg += 1;
      asm("" : "+r"(mg));
      *mg = mv;
    }
    {
      register s32 ofs2 asm("r1");
      ofs2 = -0x2000;
      (p->s).coord.x += ofs2;
    }
    *(s32*)((u8*)p + 0xb8) = (p->s).coord.y + 0x1000;
    (p->s).d.x = -0x200;
    {
      register u32* rp asm("r2");
      u32 sd, r0v;
      rp = &RNG_0202f388;
      sd = *rp;
      r0v = sd * 0x343FD;
      keep7 = 0x269EC3;
      asm("" : "+r"(keep7));
      r0v += keep7;
      r0v <<= 1;
      *rp = r0v >> 1;
      (p->s).d.y = -(s32)((((r0v >> 0x11) & 3) + 0x18) << 6);
    }
    (p->s).work[1] = one4;
    ((p->s).unk_28)->work[2]++;
  } else {
    InitNonAffineMotion(&p->s);
    {
      register u32* rp asm("r5");
      register u32 A3 asm("r3");
      register u32 C3 asm("r2");
      register u32 sd4 asm("r4");
      register u32 sd asm("r0");
      u32 r0v, r1v, r2v;
      rp = &RNG_0202f388;
      sd = *rp;
      A3 = 0x343FD;
      asm("" : "+r"(A3));
      sd = sd * A3;
      C3 = 0x269EC3;
      asm("" : "+r"(C3));
      sd += C3;
      sd <<= 1;
      sd4 = sd >> 1;
      {
        u32 rsh = (sd << 2) >> 19;
        s32 cx = (p->s).coord.x + rsh;
        (p->s).coord.x = cx;
      }
      {
        s32* b8 = (s32*)((u8*)p + 0xb8);
        s32 cy = (p->s).coord.y;
        keep7 = 0x1000;
        *b8 = cy + keep7;
      }
      r1v = sd4 * A3;
      r1v += C3;
      r1v <<= 1;
      sd4 = r1v >> 1;
      {
        s32 rr = r1v >> 0x11;
        s32 mk = 0x3F;
        rr &= mk;
        mk -= 0xFF;
        (p->s).d.x = mk - rr;
      }
      r2v = sd4 * A3;
      r2v += C3;
      r2v <<= 1;
      *rp = r2v >> 1;
      (p->s).d.y = -(s32)((((r2v >> 0x11) & 3) + 0x18) << 6);
    }
    {
      s32 z5 = 0;
      struct Body* bd;
      {
        register u32 fl asm("r1");
        register s32 c4 asm("r0");
        fl = (p->s).flags;
        c4 = 4;
        z5 = 0;
        asm("" : "+r"(z5) : "r"(c4));
        (p->s).flags = c4 | fl;
      }
      bd = &p->body;
      InitBody(bd, sCollisions, &(p->s).coord, 2);
      bd->parent = (struct Entity*)p;
      bd->fn = (void*)z5;
    }
  }
  {
    u32 fl2 = (p->s).flags;
    s32 t = 1;
    t |= fl2;
    t |= 2;
    (p->s).flags = t;
  }
  SetMotion(&p->s, 0xE600);
  {
    register s32 z2 asm("r2");
    z2 = 0;
    (p->s).flags &= 0xEF;
    (p->s).spr.xflip = z2;
    {
      u8* oa = (u8*)p + 0x4a;
      s32 ov = *oa;
      s32 m11 = -0x11;
      m11 &= ov;
      *oa = m11;
    }
  }
  Solid37_Update(p);
  asm volatile("" : : "r"(keep7));
}

void FUN_080dca60(struct Solid* p) {
  u32* ps = (u32*)((u8*)p + 0x8c);
  s32 st = *ps & 0x200;
  if (st != 0) {
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    Solid37_Die(p);
    return;
  }
  UpdateEntityAnim(&p->s);
  (p->s).coord.x += (p->s).d.x;
  {
    s32 cy0 = (p->s).coord.y;
    s32 ndy = (p->s).d.y;
    s32 ny = cy0 + ndy;
    (p->s).coord.y = ny;
    ndy += 0x40;
    (p->s).d.y = ndy;
    switch ((p->s).mode[1]) {
      case 0:
        if (ndy > -0x40) {
          SetMotion(&p->s, MOTION(0xE6, 0x01));
          UpdateEntityAnim(&p->s);
          (p->s).mode[1]++;
        }
        break;
      case 1:
        if ((p->s).motion.state == 3) {
          SetMotion(&p->s, MOTION(0xE6, 0x02));
          UpdateEntityAnim(&p->s);
          if ((p->s).work[1] != 0) {
            ((p->s).spr).oam.priority = 1;
            CreatePickupItem(4, &(p->s).coord, 0);
          }
          (p->s).mode[1]++;
        }
        break;
      case 2:
        if (ny > *(s32*)((u8*)p + 0xb8)) {
          PlaySound(0xF);
          if ((p->s).work[1] == 0) {
            struct Entity* q = (p->s).unk_28;
            q->work[2] = st;
          }
          {
            register u8 f1 asm("r1");
            register s32 f2 asm("r0");
            f1 = (p->s).flags;
            f2 = 0xFE;
            f2 &= f1;
            {
              register s32 c2 asm("r1");
              c2 = 0xFD;
              f2 &= c2;
            }
            (p->s).flags = f2;
          }
          *ps = st;
          *(u32*)((u8*)p + 0x90) = st;
          *((u8*)p + 0x94) = st;
          (p->s).flags &= ~COLLIDABLE;
          SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
        }
        break;
    }
  }
}

// 0x080dcb80
static void FUN_080dcb80(struct Solid* p) {
  struct Camera* cam;
  if ((p->s).mode[1] == 0) {
    struct Entity* q;
    SetSpriteAnimation(p, MOTION(SM230_FLYING_FISH, 0));
    (p->s).d.x = PIXEL(7) / 4;
    (p->s).d.y = -PIXEL(4);
    (p->s).work[2] = 0;
    q = (p->s).unk_28;
    q->work[2]++;
    EXIT_BODY(p);
    (p->s).mode[1]++;
  }
  UpdateSpriteAnimation(p);
  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  (p->s).d.y += PIXEL(1) / 4;
  (p->s).work[2]++;
  if ((p->s).work[2] & 1) {
    (p->s).flags &= ~DISPLAY;
  } else {
    (p->s).flags |= DISPLAY;
  }
  cam = &gStageRun.vm.camera;
  if ((p->s).coord.x > ((cam->viewport).x + PIXEL(136) - 1)) {
    SET_SOLID_ROUTINE(p, ENTITY_EXIT);
  }
}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x02,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x02,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(14), PIXEL(14)},
    },
};
