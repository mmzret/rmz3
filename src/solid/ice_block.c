#include "collision.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "solid.h"
#include "stagerun.h"

// 壊れた宇宙船の屋内とかで上から落ちてくる氷ブロック

static const struct Collision sCollisions[2];
static const struct Rect sIceBlock_Size;

bool16 FUN_0800bd38(s32 x, s32 y);
void FUN_0800bd78(s32 x, s32 y);

NON_MATCH static void IceBlock_Init(struct Solid* p);
void IceBlock_Update(struct Solid* p);
void IceBlock_Die(struct Solid* p);
static void IceBlock_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gIceBlockRoutine = {
    [ENTITY_INIT] =      IceBlock_Init,
    [ENTITY_UPDATE] =    IceBlock_Update,
    [ENTITY_DIE] =       IceBlock_Die,
    [ENTITY_DISAPPEAR] = IceBlock_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on


NON_MATCH static void IceBlock_Init(struct Solid* p) {
#if MODERN
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  (&(p->s).d)->x = (&(p->s).d)->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y -= PIXEL(11);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);

  if (FUN_0800bd38((p->s).coord.x, (p->s).coord.y) == 0) {
    (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + PIXEL(32);
    if (FUN_0800bd38((p->s).coord.x, (p->s).coord.y) == 0) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }
    if (FUN_0800bd38((p->s).coord.x, (p->s).coord.y + PIXEL(32))) {
      (p->s).coord.y += PIXEL(32);
    }
    (p->s).flags2 |= ENTI_PHYSICS;
    (p->s).size = &sIceBlock_Size;
    (p->s).physicsAttr = MTATTR_CONVEYOR1 | MTATTR_SLIP | MTATTR_B11 | SHAPE_BLOCK;
    FUN_0800bd78((p->s).coord.x, (p->s).coord.y);
    SetSpriteAnimation(p, MOTION(SM203_ICE_BLOCK, 1));
    INIT_BODY(p, &sCollisions[1], 80, NULL);
    (p->s).mode[1] = (p->s).work[0] = 2;
  } else {
    SetSpriteAnimation(p, MOTION(SM203_ICE_BLOCK, 0));
    INIT_BODY(p, &sCollisions[0], 80, NULL);
  }
  IceBlock_Update(p);
#else
  INCCODE("asm/wip/IceBlock_Init.inc");
#endif
}

void IceBlock_Update(struct Solid* p) {
  register s32 m asm("r5");
  m = (p->s).mode[1];
  switch (m) {
    case 0: {
      register struct Camera* cam asm("r3");
      register s32 cx asm("r2");
      register s32 vx asm("r1");
      UpdateEntityAnim(&p->s);
      cam = &gStageRun.vm.camera;
      vx = *(s32*)((u8*)cam + 0x38);
      cx = (p->s).coord.x;
      {
        register s32 hi asm("r0");
        register s32 k asm("r2");
        k = 0x000077FF;
        hi = vx + k;
        cx = (p->s).coord.x;
        if (cx > hi) {
          break;
        }
      }
      {
        register s32 lo asm("r0");
        m = 0xFFFF8800;
        lo = vx + m;
        if (cx < lo) {
          break;
        }
      }
      {
        register s32 cy asm("r3");
        register s32 t asm("r0");
        register s32 k2 asm("r1");
        t = *(s32*)((u8*)cam + 0x3c);
        k2 = 0xFFFF6800;
        t += k2;
        cy = (p->s).coord.y;
        if (cy < t) {
          break;
        }
        (p->s).flags2 |= 8;
        (p->s).size = (struct Rect*)&sIceBlock_Size;
        (p->s).physicsAttr = 0x3801;
        FUN_0800bd78(cx, cy);
      }
      (p->s).work[0] = 1;
      (p->s).mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 dy asm("r1");
      UpdateEntityAnim(&p->s);
      dy = (p->s).d.y;
      if (dy <= 0x6FF) {
        register s32 nv asm("r0");
        nv = dy;
        nv += 0x40;
        (p->s).d.y = nv;
      }
      {
        register s32 ny asm("r1");
        register s32 dv asm("r0");
        ny = (p->s).coord.y;
        dv = (p->s).d.y;
        ny += dv;
        (p->s).coord.y = ny;
        (p->s).unk_coord.y = ny;
        if (PushoutToUp1((p->s).coord.x, ny) == 0) {
          break;
        }
      }
      {
        register s32 v asm("r1");
        register s32 lim asm("r0");
        v = (p->s).d.y;
        lim = 0x80 << 2;
        if (v > lim) {
          lim -= 0xe3;
          ((void (*)(s32))PlaySound)(lim);
          AppendQuake(4, &(p->s).coord);
        }
      }
      (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      (p->s).d.y = 0;
      SetDDP(&p->body, &sCollisions[1]);
      SetMotion(&p->s, 0xCB01);
      (p->s).work[0] = 2;
      (p->s).mode[1]++;
      break;
    }
    case 2: {
      register s32* st asm("r2");
      UpdateEntityAnim(&p->s);
      if (PushoutToUp1((p->s).coord.x, (p->s).coord.y + 1) == 0) {
        SetDDP(&p->body, sCollisions);
        (p->s).work[0] = 1;
        (p->s).mode[1] = 1;
      }
      st = (s32*)((u8*)p + 0x8c);
      if ((*st & 1) == 0) {
        break;
      }
      {
        register s32 mid asm("r0");
        register s32 k3 asm("r1");
        mid = (p->s).motionID << 8;
        mid |= *(u8*)((u8*)p + 0x70);
        k3 = 0xCB01;
        if (mid == k3) {
          k3 += 1;
          ((void (*)(struct Entity*, s32))SetMotion)(&p->s, k3);
          break;
        }
      }
      {
        register s32 z asm("r1");
        z = 0;
        *st = z;
        {
          u8* a = (u8*)p + 0x90;
          *(s32*)a = z;
          asm("" : "+r"(a));
          a += 4;
          asm("" : "+r"(a));
          *a = z;
        }
      }
      (p->s).flags &= 0xFB;
      (p->s).flags2 &= 0xF7;
      {
        u32 tbl = (u32)gSolidFnTable;
        EntityFunc** rt = (EntityFunc**)((((p->s).id) << 2) + tbl);
        *(u32*)((p->s).mode) = m;
        (p->s).onUpdate = (void*)((*rt)[2]);
      }
      break;
    }
  }
}

void IceBlock_Die(struct Solid* p) {
  u8 m = (p->s).mode[1];
  switch (m) {
    case 0:
      SetMotion(&p->s, 0xCB03);
      PlaySound(0x3F);
      (p->s).d.y = m;
      (p->s).work[3] = m;
      (p->s).mode[1]++;
      /* fallthrough */
    case 1: {
      register s32 w3 asm("r1");
      register s32 k1 asm("r0");
      w3 = (p->s).work[3];
      (p->s).work[3] = w3 + 1;
      k1 = 1;
      k1 &= w3;
      if (k1 != 0) {
        (p->s).flags &= 0xFE;
      } else {
        (p->s).flags |= 1;
      }
      UpdateEntityAnim(&p->s);
      if ((p->s).d.y <= 0x6FF) {
        (p->s).d.y += 0x20;
      }
      (p->s).coord.y += (p->s).d.y;
      (p->s).unk_coord.y = (p->s).coord.y;
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x2000) {
        s32 z;
        {
          register u8 fl asm("r1");
          u8 fv;
          fl = (p->s).flags;
          fv = 0xFE & fl;
          z = 0;
          asm("" : "+r"(z));
          (p->s).flags = fv;
        }
        *(u32*)((u8*)p + 0x8c) = z;
        *(u32*)((u8*)p + 0x90) = z;
        *(u8*)((u8*)p + 0x94) = z;
        (p->s).flags &= 0xFB;
        (p->s).flags2 &= 0xF7;
        SET_SOLID_ROUTINE(p, ENTITY_EXIT);
      }
      break;
    }
  }
}

void FUN_0800bdd4(s32 x, s32 y);

static void IceBlock_Disappear(struct Solid* p) {
  if ((p->s).work[0] == 1) {
    (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  }
  if ((p->s).work[0] != 0) {
    FUN_0800bdd4((p->s).coord.x, (p->s).coord.y - PIXEL(8));
  }
  DeleteSolid((void*)p);
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 254,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(12), PIXEL(20), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(12), PIXEL(40), PIXEL(28)},
    },
};

static const struct Rect sIceBlock_Size = {PIXEL(0), -PIXEL(12), PIXEL(32), PIXEL(32)};  // 0x083710d8
