#include "boss.h"
#include "collision.h"
#include "global.h"
#include "palette_animation.h"
#include "element.h"
#include "overworld.h"
#include "script.h"

void FUN_0807d6c0(s32 x, s32 y, u8 a2);
void FUN_080a2f34(s32 x, s32 y);

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[48];         // 0xB4
} BeeServer;
static_assert(sizeof(BeeServer) == sizeof(Boss));

static const struct Collision sCollisions[8];

NON_MATCH void BeeServer_Init(BeeServer* p);
void BeeServer_Update(BeeServer* p);
void BeeServer_Die(BeeServer* p);

// clang-format off
const BossRoutine gBeeServerRoutine = {
    [ENTITY_INIT] =      (void*)BeeServer_Init,
    [ENTITY_UPDATE] =    (void*)BeeServer_Update,
    [ENTITY_DIE] =       (void*)BeeServer_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


struct Entity* CreateSmoke(u8 kind, struct Coord* c);
static const Coords32 sBeeServerElfxOffset;
extern const u8 u8_ARRAY_0836332e[5];
static void (*const sDeads[1])(BeeServer*);
static void (*const sUpdates1[4])(BeeServer*);
static void (*const sUpdates2[4])(BeeServer*);
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) { return; }

static bool8 tryKillBeeServer(BeeServer* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    p->mode[1] = 0;
    BeeServer_Die(p);
    return TRUE;
  }
  return FALSE;
}

NON_MATCH void BeeServer_Init(BeeServer* p) {
#if MODERN
  {
    u32 tbl = (u32)gBossFnTable;
    u32 id = (p->id) << 2;
    EntityFunc** rt = (EntityFunc**)(tbl + id);
    register u32 one asm("r1");
    one = 1;
    *(u32*)(p->mode) = one;
    p->onUpdate = (void*)((*rt)[1]);
  }
  {
    register const u8* tb asm("r1");
    tb = (const u8*)0x08363318;
    asm("" : "+r"(tb));
    {
      register u32 idx asm("r0");
      idx = p->work[0];
      idx += (u32)tb;
      p->mode[1] = *(const u8*)idx;
    }
  }
  {
    u32 fl = p->flags;
    fl |= 2;
    asm("" : "+r"(fl));
    fl |= 1;
    p->flags = fl;
  }
  InitNonAffineMotion((struct Entity*)p);
  if ((gSystemSavedata.flags[22] & 0x20) != 0) {
    ResetBossBody(p, sCollisions, 0x30);
  } else {
    ResetBossBody(p, sCollisions, 0x20);
  }
  {
    void* f = (void*)onCollision;
    u8* b = (u8*)p + 0x74;
    *(void**)(b + 0x24) = f;
    asm("" : "+r"(b));
    b += 0x40;
    asm("" : "+r"(b));
    {
      register s32 z asm("r1");
      z = 0;
      *(u32*)b = z;
    }
  }
  {
    s32 cx = p->coord.x >> 8;
    s32 q;
    p->coord.x = cx;
    q = cx / 0xF0;
    {
      register s32 v asm("r1");
      register s32 k asm("r2");
      v = ((q << 4) - q) << 12;
      asm volatile("mov %0, #0xf0\n\tlsl %0, %0, #0x7" : "=l"(k));
      v += k;
      p->coord.x = v;
    }
  }
  {
    s32 cy = p->coord.y >> 8;
    s32 q2;
    p->coord.y = cy;
    q2 = cy / 0xA0;
    {
      register s32 v2 asm("r1");
      register s32 k2 asm("r0");
      v2 = ((q2 << 2) + q2) << 13;
      asm volatile("mov %0, #0xe0\n\tlsl %0, %0, #0x6" : "=l"(k2));
      v2 += k2;
      p->coord.y = v2;
    }
  }
  LOAD_STATIC_GRAPHIC(SM070_BEESERVER);
  LOAD_STATIC_GRAPHIC(SM071_MELLNET);
  *(s32*)((u8*)p + 0xbc) = p->coord.x;
  {
    u16* w = (u16*)((u8*)p + 0xb8);
    u16 z = 0;
    *w = z;
    asm("" : "+r"(w));
    w += 1;
    *w = z;
  }
  BeeServer_Update(p);
#else
  INCCODE("asm/boss/BeeServer_Init.inc");
#endif
}

void BeeServer_Update(BeeServer* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot != NULL && isKilled(*slot)) {
    *slot = NULL;
  }
  {
    register s16* h0 asm("r0");
    register s32 v asm("r1");
    register s16* h asm("r3");
    s32 lim;
    h0 = (s16*)(u8*)&p->unk_b4[4];
    v = *h0 + 0x100;
    lim = 0x200;
    h = h0;
    asm("" : "+r"(h));
    if ((u32)v > (u32)lim) {
      s32 t;
      *(u16*)h = -*(u16*)h;
      t = *h;
      *h = ((t * 15) << 4) / 0x100;
    } else {
      *h = 0;
    }
    {
      s32 bx = *(s32*)(u8*)&p->unk_b4[8];
      p->coord.x = bx;
      asm volatile("" ::: "memory");
      p->coord.x = bx + *h;
    }
  }
  {
    s16* w = (s16*)(u8*)&p->unk_b4[6];
    u16 wv = *(u16*)w;
    if (*w != 0) {
      *(u16*)w = wv - 1;
    }
  }
  if (!tryKillBeeServer(p)) {
    (sUpdates1[p->mode[1]])(p);
    (sUpdates2[p->mode[1]])(p);
    StepPaletteAnimation(0x45);
  }
}

void BeeServer_Die(BeeServer* p) {
  (sDeads[p->mode[1]])(p);
}

void nop_0804d0a0(BeeServer* p) {}

void FUN_0804d0a4(BeeServer* p) {
  if (((p->body).status & BODY_STATUS_WHITE) && (p->body).elemented == 2) {
    *(struct VFX**)(u8*)&p->unk_b4[0] = (struct VFX*)ApplyElementEffect(0x12, (struct CollisionObject*)p, &sBeeServerElfxOffset);
  }
  if (((p->body).status & 0x00020008) == 0x00020008) {
    u16* q = (u16*)(u8*)&p->unk_b4[4];
    register s32 v asm("r0");
    v = 0xFC00;
    *q = v;
  }
}

void FUN_0804d0f8(BeeServer* p) {
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 0xFF;
      SetMotion((struct Entity*)p, MOTION(0x46, 0x00));
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      s16* t = (s16*)(u8*)&p->unk_b4[6];
      u8 v;
      if (*t == 0 && ((p->body).status & 0x00020008) == 0x00020008) {
        u32 r;
        *t = 0x78;
        r = RANDOM(RNG_0202f388) & 3;
        FUN_0807d6c0(p->coord.x,
                     p->coord.y + ({
                       s32 o_ = ((r >> 1) << 14) - 0x2000;
                       asm("" : "+r"(o_));
                       o_;
                     }),
                     r & 1);
      }
      v = --p->work[2];
      if (v == 0) {
        p->mode[1] = 2;
        p->mode[2] = v;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_0804d1ac(BeeServer* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0x46, 0x00));
      {
        u32 g0 = GetEntityPaletteID((struct Entity*)p);
        u32 g = (u8)g0 << 5;
        StartPaletteAnimation(0x45, g | 0x200);
      }
      p->mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->scriptEntity->flags & 1) {
        p->mode[2]++;
      }
      break;
    case 2:
      SetMotion((struct Entity*)p, MOTION(0x46, 0x00));
      p->mode[2]++;
      /* fallthrough */
    case 3: {
      u32 v;
      UpdateEntityAnim((struct Entity*)p);
      v = gStageRun.vm.active & 1;
      if (v == 0) {
        p->mode[1] = v;
        p->mode[2] = v;
      }
      break;
    }
  }
}

INCASM("asm/boss/bee_server_a.inc");

void FUN_0804d418(BeeServer* p) {
  switch (p->mode[2]) {
    case 0:
      PlaySound(0x10F);
      FUN_080a2f34(p->coord.x, p->coord.y);
      SetMotion((struct Entity*)p, MOTION(0x46, 0x03));
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      SetDDP(&p->body, &sCollisions[u8_ARRAY_0836332e[(s8)p->motion.cmdIdx]]);
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 0;
        p->mode[2] = 0;
      }
      break;
  }
}

void FUN_0804d494(BeeServer* p) {
  struct Coord c;
  switch (p->mode[2]) {
    case 0: {
      register s32 one asm("r4");
      RemovePaletteAnimation(0x45);
      {
        register struct StageRun* sr asm("r3");
        register u16 ms asm("r2");
        sr = &gStageRun;
        ms = sr->missionStatus;
        one = 1;
        {
          register s32 t asm("r0");
          t = one;
          t &= ms;
          if (t == 0) {
            goto skip;
          }
        }
        {
          register u8 av asm("r1");
          register s32 t2 asm("r0");
          av = (sr->vm).active;
          t2 = one;
          t2 &= av;
          if (t2 != 0) {
            goto skip;
          }
        }
        {
          register s32 nv asm("r0");
          register s32 k asm("r1");
          nv = 0xFFFE;
          nv &= ms;
          k = 0x10;
          nv |= k;
          sr->missionStatus = nv;
        }
      }
    skip : {
      register u8 f2 asm("r2");
      register s32 f asm("r0");
      register s32 zz asm("r1");
      u8* a;
      f2 = p->flags;
      f = 1;
      zz = 0;
      f |= f2;
      p->flags = f;
      p->work[2] = 0xFF;
      a = (u8*)p + 0x8c;
      *(u32*)a = zz;
      asm("" : "+r"(a));
      a += 4;
      asm("" : "+r"(a));
      *(u32*)a = zz;
      asm("" : "+r"(a));
      a += 4;
      asm("" : "+r"(a));
      *a = zz;
      p->flags &= ~COLLIDABLE;
    }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 w asm("r2");
      UpdateEntityAnim((struct Entity*)p);
      p->work[2]--;
      {
        register s32 w7 asm("r0");
        register s32 k7 asm("r1");
        w7 = p->work[2];
        asm("" : "+r"(w7));
        k7 = 7;
        w7 &= k7;
        if (w7 != 0) {
          goto nosmoke;
        }
      }
      {
        register u32* rp asm("r6");
        register u32 mul asm("r5");
        register u32 add asm("r2");
        register u32 s1 asm("r3");
        register s32 cy asm("r4");
        register u32 v asm("r0");
        {
          register s32 cx asm("r1");
          cx = p->coord.x + -0x2000;
          rp = &RNG_0202f388;
          asm("" : "+r"(rp));
          v = *rp;
          mul = 0x343FD;
          v *= mul;
          add = 0x269EC3;
          v += add;
          v <<= 1;
          asm("" : "+r"(v));
          s1 = v >> 1;
          v <<= 1;
          v >>= 0x12;
          c.x = v + cx;
        }
        cy = p->coord.y + -0x2E00;
        c.y = cy;
        asm volatile("" ::: "memory");
        {
          register u32 v2 asm("r0");
          register u32 d2 asm("r1");
          asm volatile("add %0, %1, #0" : "=&l"(v2) : "l"(s1));
          v2 *= mul;
          v2 += add;
          v2 <<= 1;
          asm("" : "+r"(v2));
          *rp = v2 >> 1;
          v2 >>= 0x11;
          d2 = 0xB8 * 128;
          c.y = v2 % d2 + cy;
        }
        ((struct Entity * (*)(s32, struct Coord*)) CreateSmoke)(1, &c);
      }
    nosmoke:;
      {
        register u32 t3 asm("r0");
        register u32 d3 asm("r1");
        t3 = p->work[2];
        d3 = 0x14;
        if ((u8)(t3 % d3) == 0) {
          PlaySound(0x2A);
        }
      }
      {
        register s32 sw asm("r0");
        sw = *(s8*)((u8*)p + 0x12);
        w = p->work[2];
        if (sw >= 0) {
          register s32 t4 asm("r0");
          t4 = 2;
          t4 &= w;
          if (t4 != 0) {
            register u8 fv asm("r0");
            register s32 k1 asm("r1");
            fv = p->flags;
            k1 = 1;
            fv |= k1;
            p->flags = fv;
          } else {
            register u8 h asm("r1");
            register u8 g asm("r0");
            h = p->flags;
            asm("" : "+r"(h));
            g = 0xFE;
            g &= h;
            p->flags = g;
          }
        }
      }
      {
        register s32 t8 asm("r0");
        t8 = w << 24;
        asm("" : "+r"(t8));
        if (t8 != 0) {
          break;
        }
      }
      {
        register struct StageRun* sr2 asm("r2");
        TryDropItem(0xC, &p->coord);
        sr2 = &gStageRun;
        {
          register u8 av2 asm("r1");
          register s32 k2 asm("r0");
          av2 = (sr2->vm).active;
          k2 = 2;
          k2 |= av2;
          (sr2->vm).active = k2;
        }
        p->mode[2]++;
      }
      break;
    }
    case 2:
      break;
  }
}

void FUN_0804d0a4(BeeServer* p);
void nop_0804d0a0(BeeServer* p);

static void (*const sUpdates1[4])(BeeServer*) = {
    FUN_0804d0a4,
    nop_0804d0a0,
    FUN_0804d0a4,
    FUN_0804d0a4,
};

void FUN_0804d0f8(BeeServer* p);
void FUN_0804d1ac(BeeServer* p);
void FUN_0804d240(BeeServer* p);
void FUN_0804d418(BeeServer* p);

static void (*const sUpdates2[4])(BeeServer*) = {
    FUN_0804d0f8,
    FUN_0804d1ac,
    FUN_0804d240,
    FUN_0804d418,
};  // 0x08363244

void FUN_0804d494(BeeServer* p);

static void (*const sDeads[1])(BeeServer*) = {
    FUN_0804d494,
};  // 0x08363254

// --------------------------------------------

// 0x08363258
static const struct Collision sCollisions[8] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(84)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(84)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(88)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(55), PIXEL(94)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      comboLv : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(55), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(35), PIXEL(55), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(7), PIXEL(55), PIXEL(19)},
    },
};

static const u8 sBeeServerInitModes[4] = {1, 0, 0, 0};  // 0x08363318

static const Coords32 sBeeServerElfxOffset = {PIXEL(0), PIXEL(0)};  // 0x0836331c

const u8 u8_ARRAY_08363324[5] = {2, 3, 4, 5, 5};  // 0x08363324
const u8 u8_ARRAY_08363329[5] = {4, 3, 3, 2, 2};  // 0x08363329
const u8 u8_ARRAY_0836332e[5] = {5, 5, 4, 3, 2};  // 0x0836332e
