#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

void CreateVFX43(s32 x, s32 y);

void CreateLavaGeyserPlatform(struct Solid* s);

static const struct Collision sCollisions[];
static const struct Rect sSize;

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];  // 0xB4
  s32 unk_b8_y;  // 0xB8
  s32 unk_bc_y;  // 0xBC
  s32 unk_c0_x;  // 0xC0
} LavaGeyser;
static_assert(sizeof(LavaGeyser) == sizeof(struct Solid));

// ------------------------------------------------------------------------------------------------------------------------------------

static void Solid7_Init(LavaGeyser* p);
static void Solid7_Update(LavaGeyser* p);
static void Solid7_Die(void* _);

// clang-format off
const SolidRoutine gLavaGeyserRoutine = {
    [ENTITY_INIT] =      (void*)Solid7_Init,
    [ENTITY_UPDATE] =    (void*)Solid7_Update,
    [ENTITY_DIE] =       (void*)Solid7_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateLavaGeyser(struct Entity* e, s32 x, s32 y, s32 n, s32 n2 UNUSED) {
  s32 i;
  for (i = 0; i < 6; i++) {
    struct Entity* p = AllocEntityLast(gSolidHeaderPtr);
    if (p != NULL) {
      register s32 r0 asm("r0");
      register s32 r1 asm("r1");

      INIT_SOLID_ROUTINE(p, SOLID_LAVA_GEYSER);
      (p->work)[0] = 12;
      (p->work)[1] = i;

      r0 = abs(n - y);
      r1 = r0;
      if (r0 < 0) {  // never reached?
        r1 = r0 + ((1 << 11) - 1);
      }
      r0 = r1 >> 11;
      (p->work)[3] = r0;

      (p->coord).x = x;
      (p->coord).y = y;
      y += PIXEL(16);
      p->unk_28 = (void*)e;
    }
  }
}

static void CreateSolid7_Unused(s32 x, u8 n) {
  struct Entity* p = AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_LAVA_GEYSER);
    (p->work)[0] = n;
    (p->coord).x = x;
  }
}

bool8 FUN_080cc814(struct Entity* p) { return (p->mode)[1] == ENTITY_EXIT; }

// 0x080cc828
static void LavaGeyser_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  struct Entity* q = (struct Entity*)(body->enemy)->parent;
  LavaGeyser* p = (LavaGeyser*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_B3) {
    p->unk_bc_y = (q->coord).y;
  }
}

static void Solid7_Init(LavaGeyser* p) {
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  if (p->work[0] == 12) {
    p->mode[1] = 5;
  } else {
    p->mode[1] = 0;
    INIT_BODY(p, &sCollisions[0], 1, LavaGeyser_OnCollision);
    (p->coord).y = FUN_08009f6c((p->coord).x, (p->coord).y) - PIXEL(14);
    p->unk_b8_y = (p->coord).y;
    p->unk_c0_x = (p->coord).x;
    p->flags2 |= ENTI_PHYSICS;
    p->size = &sSize;
    p->physicsAttr = MTATTR_B11 | MTATTR_SPIKE | SHAPE_BLOCK;
    CreateLavaGeyserPlatform((void*)p);
  }
  Solid7_Update(p);
}

void nop_080cc930(LavaGeyser* _);
void FUN_080cc934(LavaGeyser* p);

void FUN_080cc968(LavaGeyser* p);
void FUN_080cca14(LavaGeyser* p);
void FUN_080ccae0(LavaGeyser* p);
void FUN_080ccb50(LavaGeyser* p);
void FUN_080ccc1c(LavaGeyser* p);
void FUN_080ccca4(LavaGeyser* p);

static void Solid7_Update(LavaGeyser* p) {
  // clang-format off
  static void (*const sUpdates1[6])(LavaGeyser*) = {
    FUN_080cc934,
    FUN_080cc934,
    FUN_080cc934,
    FUN_080cc934,
    nop_080cc930,
    nop_080cc930,
  };  // 0x0836FF7C
  // clang-format on
  // clang-format off
  static void (*const sUpdates2[6])(LavaGeyser*) = {
    FUN_080cc968,
    FUN_080cca14,
    FUN_080ccae0,
    FUN_080ccb50,
    FUN_080ccc1c,
    FUN_080ccca4,
  };  // 0x0836FF94
  // clang-format on
  sUpdates1[p->mode[1]](p);
  sUpdates2[p->mode[1]](p);
}

static void Solid7_Die(void* _) {}

// --------------------------------------------

void nop_080cc930(LavaGeyser* _) {}

void FUN_080cc934(LavaGeyser* p) {
  if (((p->body).status & BODY_STATUS_B3) && ((p->body).elemented == ELEMENT_ICE)) {
    PlaySound(SE_ICE_40);
    p->mode[1] = 4, p->mode[2] = 0;
  }
}

void FUN_080cc968(LavaGeyser* p) {
  switch (p->mode[2]) {
    case 0: {
      (p->unk_coord).x = (p->coord).x;
      SetDDP(&p->body, sCollisions);
      SetSpriteAnimation(p, MOTION(SM057_GEYSER, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 val = (gOverworld.work.volcano.unk_004 - (67 * (p->work[0] % 4)) + 1) % 268;
      if (val > 236) {
        (p->coord).x = (p->unk_c0_x - PIXEL(2));
        (p->coord).x += (RANDOM(RNG_0202f388) & 0x3FF);
      }
      if (val == 0) p->mode[1] = 1, p->mode[2] = 0;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

void FUN_080cca14(LavaGeyser* p0) {
  register struct Solid* p asm("r4");
  u8 m;
  p = (struct Solid*)p0;
  m = (p->s).mode[2];
  switch (m) {
    case 0: {
      register s32 t asm("r2");
      register s32 t2 asm("r1");
      s32 k;
      register s32 k2 asm("r5");
      s32 u;
      PlaySound(0x77);
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).d.y = m;
      {
        u32 w0 = (p->s).work[0];
        asm volatile("lsr %0, %1, #0x2" : "=l"(k2) : "l"(w0));
      }
      k = k2 * 3;
      u = (k << 11) - 0xC000;
      (p->s).unk_coord.y = u;
      t = k2 << 2;
      t2 = 0x18 - t;
      asm volatile("add %0, %1, #0" : "=l"(t) : "l"(t2));
      t *= t2;
      asm volatile("add %0, %1, #0" : "=l"(t2) : "l"(t));
      (p->s).unk_coord.y = u / t2;
      (p->s).mode[2]++;
    }
      /* fallthrough */
    case 1: {
      s32 base;
      s32 cy0;
      s32 cy;
      s32 dy;
      register s32 k3 asm("r5");
      s32 sh;
      s32 diff;
      s32 ny;
      register s32* lp asm("r3");
      {
        u32 w0b = (p->s).work[0];
        asm volatile("lsr %0, %1, #0x2" : "=l"(k3) : "l"(w0b));
      }
      {
        register s32 k200 asm("r0");
        s32 bv = *(s32*)((u8*)p + 0xc0);
        k200 = -0x200;
        asm("" : "+r"(k200));
        base = bv + k200;
      }
      (p->s).coord.x = base + (RANDOM(RNG_0202f388) & 0x3FF);
      cy0 = (p->s).coord.y;
      dy = (p->s).d.y;
      cy = cy0 + dy;
      (p->s).coord.y = cy;
      (p->s).d.y = dy + (p->s).unk_coord.y;
      lp = (s32*)((u8*)p + 0xb8);
      diff = *lp - cy;
      sh = (k3 * 3) << 11;
      if (diff > 0x6000 - sh) {
        (p->s).coord.x = (p->s).unk_coord.x;
        ny = *lp - 0x6000;
        (p->s).coord.y = ny + sh;
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void FUN_080ccae0(LavaGeyser* p) {
  s32 a;
  switch (p->mode[2]) {
    case 0:
      p->unk_coord.x = p->coord.x;
      p->work[2] = 0x18;
      p->mode[2]++;
      // fallthrough
    case 1: {
      a = p->unk_coord.x;
      {
        s32 t = a - PIXEL(2);
        p->coord.x = t + (RANDOM(RNG_0202f388) & 0x1FF);
      }
      if (--p->work[2] == 0) {
        p->coord.x = a;
        p->mode[1] = 3;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080ccb50(LavaGeyser* p) {
  u8 m = p->mode[2];
  switch (m) {
    case 0: {
      s32 k;
      s32 k2;
      s32 c0;
      register s32 t asm("r2");
      register s32 t2 asm("r1");
      s32 u;
      p->flags2 |= 8;
      p->size = &sSize;
      p->physicsAttr = 0x811;
      SetDDP(&p->body, sCollisions);
      p->unk_coord.x = p->coord.x;
      p->d.y = m;
      k2 = p->work[0] >> 2;
      c0 = 0xC000;
      asm("" : "+r"(c0));
      k = k2 * 3;
      t = k << 3;
      u = c0 - (k << 11);
      p->unk_coord.y = u;
      t2 = 0x64 - t;
      asm volatile("add %0, %1, #0" : "=l"(t) : "l"(t2));
      t *= t2;
      asm volatile("add %0, %1, #0" : "=l"(t2) : "l"(t));
      p->unk_coord.y = u / t2;
      p->mode[2]++;
    }
      /* fallthrough */
    case 1: {
      s32 base;
      s32 cy0;
      s32 cy;
      s32 dy;
      s32* lim;
      base = *(s32*)((u8*)p + 0xc0) - 0x200;
      p->coord.x = base + (RANDOM(RNG_0202f388) & 0x1FF);
      cy0 = p->coord.y;
      dy = p->d.y;
      cy = cy0 + dy;
      p->coord.y = cy;
      p->d.y = dy + p->unk_coord.y;
      lim = (s32*)((u8*)p + 0xb8);
      if (cy > *lim) {
        p->coord.x = p->unk_coord.x;
        p->coord.y = *lim;
        p->mode[1] = 0;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void FUN_080ccc1c(LavaGeyser* p) {
  switch (p->mode[2]) {
    case 0:
      p->flags2 |= 8;
      p->size = &sSize;
      p->physicsAttr = 0x801;
      p->coord.x = p->unk_coord.x;
      SetDDP(&p->body, &sCollisions[1]);
      CreateLavaGeyser((struct Entity*)p, p->coord.x, p->coord.y, *(s32*)((u8*)p + 0xbc), *(s32*)((u8*)p + 0xb8));
      SetMotion((struct Entity*)p, MOTION(0x39, 0x00));
      UpdateEntityAnim((struct Entity*)p);
      p->work[2] = 0xD8;
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      s32 t = (u8)--p->work[2];
      if (t == 0) {
        p->mode[1] = 3;
        p->mode[2] = t;
      }
      break;
    }
  }
}

void FUN_080ccca4(LavaGeyser* p) {
  if ((p->unk_28)->mode[0] > 1) {
    u32 z;
    u8 t = p->flags;
    u8 fv = 0xFE;
    fv &= t;
    asm volatile("" ::"r"(t));
    z = 0;
    fv &= 0xFD;
    p->flags = fv;
    (p->body).status = z;
    (p->body).prevStatus = z;
    (p->body).invincibleTime = z;
    p->flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  switch (p->mode[2]) {
    case 0: {
      u8 w1;
      u32 k;
      p->renderPrio = 0x1D;
      p->flags &= ~DISPLAY;
      k = 0xD8;
      p->work[2] = k - (p->work[1] << 4);
      w1 = p->work[1];
      if (w1 == 0) {
        SetMotion((struct Entity*)p, MOTION(0x39, 0x01));
      } else if (({
                   u8 m_ = 1;
                   m_ &= w1;
                   m_;
                 }) != 0) {
        SetMotion((struct Entity*)p, MOTION(0x39, 0x02));
      } else {
        SetMotion((struct Entity*)p, MOTION(0x39, 0x03));
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register u8 w2 asm("r0");
      u32 w2c;
      if (p->work[3] != 0) {
        p->work[3]--;
        if ((u8)p->work[3] != 0) {
          goto tick;
        }
      }
      p->flags |= DISPLAY;
    tick:
      w2 = p->work[2];
      w2c = w2;
      asm("" : "+r"(w2c));
      if (w2c <= 0xF) {
        if (({
              u8 m2_ = 2;
              m2_ &= w2c;
              m2_;
            }) != 0) {
          p->flags |= DISPLAY;
        } else {
          u8 t = p->flags;
          u8 fv = 0xFE;
          fv &= t;
          asm volatile("" ::"r"(t));
          p->flags = fv;
        }
      }
      {
        u32 v = w2c - 1;
        u32 z;
        p->work[2] = v;
        z = (u8)v;
        if (z == 0) {
          PlaySound(0x3F);
        CreateVFX43(p->coord.x, p->coord.y + 0x800);
        {
          u8 t = p->flags;
          u8 fv = 0xFE;
          fv &= t;
          asm volatile("" ::"r"(t));
          fv &= 0xFD;
          p->flags = fv;
        }
        (p->body).status = z;
        (p->body).prevStatus = z;
        (p->body).invincibleTime = z;
          p->flags &= ~COLLIDABLE;
          SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

// --------------------------------------------

// 0x0836ffac
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 254,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(111)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : 8,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(111)},
    },
};

// --------------------------------------------

// 0x0836FFDC
static const struct Rect sSize = {PIXEL(0), PIXEL(57), PIXEL(32), PIXEL(120)};
