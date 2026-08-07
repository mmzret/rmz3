#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

// Shelluno

static void VFX38_Init(struct Entity* p);
static void VFX38_Update(struct Entity* p);
static void VFX38_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX38Routine = {
    [ENTITY_INIT] =      (void*)VFX38_Init,
    [ENTITY_UPDATE] =    (void*)VFX38_Update,
    [ENTITY_DIE] =       (void*)VFX38_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


const u8* const PTR_ARRAY_0836ee90[3];
struct Entity* FUN_080bcf68(Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_038);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
  }
  return p;
}

struct Entity* FUN_080bcfbc(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_038);
    p->work[0] = kind, p->work[1] = 1;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->m_74 = m, p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX38_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if (p->work[0] == 0) {
    (p->d).x = -PIXEL(1) / 2;
  } else {
    (p->d).x = PIXEL(1) / 2;
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    p->work[2] = 127 + (RANDOM(RNG_0202f388) & 7);
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 2, p->mode[2] = 0, p->mode[3] = 0;
  }
  VFX38_Update(p);
}

static void nop_080bd17c(void* _ UNUSED);
void FUN_080bd180(struct VFX* p);
void FUN_080bd288(struct VFX* p);

static void VFX38_Update(struct Entity* p) {
  static const VFXFunc sUpdates[3] = {
      (void*)nop_080bd17c,
      (void*)FUN_080bd180,
      (void*)FUN_080bd288,
  };  // 0x0836ee24

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    VFX38_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void VFX38_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080bd17c(void* _ UNUSED) {}

void FUN_080bd180(struct VFX* vfx) {
  s32 t = (vfx->s).work[2] - 1;
  (vfx->s).work[2] = t;
  if ((t << 24) == 0) {
    struct Coord c;
    s32 r;
    CreateSmoke(2, &(vfx->s).coord);
    r = RANDOM(RNG_0202f388) & 3;
    c.x = (vfx->s).coord.x;
    c.y = (vfx->s).coord.y;
    FUN_080bcfbc(&c, (vfx->s).work[0], MOTION(0x35, 0x06), r);
    FUN_080bcfbc(&c, (vfx->s).work[0], MOTION(0x35, 0x08), r);
    PlaySound(0x31);
    SET_VFX_ROUTINE(vfx, ENTITY_DIE);
  } else {
    s32 md = (vfx->s).mode[2];
    switch (md) {
      case 0:
        (vfx->s).work[2] = 0x28;
        (vfx->s).d.y = (RANDOM(RNG_0202f388) & 0x1F) - 0x180;
        SetMotion(&vfx->s, MOTION(0x35, 0x05));
        (vfx->s).mode[2]++;
        // fallthrough
      case 1: {
        s32 v = (vfx->s).d.y + 0x10;
        (vfx->s).d.y = v;
        if (v > 0x700) {
          (vfx->s).d.y = 0x700;
        }
        (vfx->s).coord.y += (vfx->s).d.y;
        (vfx->s).coord.x += (vfx->s).d.x;
        UpdateEntityAnim(&vfx->s);
        break;
      }
    }
  }
}

void FUN_080bd288(struct VFX* p) {
  {
    s32 t = (p->s).work[2] - 1;
    (p->s).work[2] = t;
    if ((t << 24) == 0) {
      goto smoke;
    }
  }
  {
    u16 a = FUN_080098a4((p->s).coord.x, (p->s).coord.y);
    if (a != 0) {
      if (!(a & 0x8000)) {
        if ((p->s).d.y > 0) {
        smoke:
          CreateSmoke(2, &(p->s).coord);
          SET_VFX_ROUTINE(p, ENTITY_DIE);
          return;
        }
      }
    }
  }
  {
    register u32 m9 asm("r9");
    m9 = (p->s).mode[2];
    switch (m9) {
      case 0: {
        const u8* const* t4 = PTR_ARRAY_0836ee90;
        register u16* mo8 asm("r8");
        register const u8* row asm("r0");
        register const s32* ent asm("r2");
        u32 mv0;
        {
          register u8* a1 asm("r1");
          u32 av = 0x74;
          asm("" : "+r"(av));
          av += (u32)p;
          a1 = (u8*)av;
          asm("" : "+r"(a1));
          mo8 = (u16*)a1;
          mv0 = *(u16*)a1;
        }
        {
          register u32 three asm("r1");
          u32 md;
          three = 3;
          asm("" : "+r"(three));
          md = mv0 % three;
          row = t4[(u16)md];
        }
        {
          register u32 offb asm("r2");
          offb = *(s32*)((u8*)p + 0x78) << 3;
          offb += (u32)row;
          ent = (const s32*)offb;
        }
        {
          register u32* rp asm("r3");
          register u32 A3 asm("r6");
          register u32 C3 asm("r5");
          register u32 seed2 asm("r4");
          u32 sd;
          u32 r0v;
          u32 r2v;
          rp = &RNG_0202f388;
          sd = *rp;
          asm("" : "+r"(sd));
          A3 = 0x343FD;
          asm("" : "+r"(A3));
          r0v = sd * A3;
          C3 = 0x269EC3;
          asm("" : "+r"(C3));
          r0v += C3;
          r0v <<= 1;
          seed2 = r0v >> 1;
          *rp = seed2;
          (p->s).d.y = ent[1] + ((r0v >> 0x11) & 0x1F);
          r2v = seed2 * A3;
          r2v += C3;
          r2v <<= 1;
          *rp = r2v >> 1;
          (p->s).d.x = ent[0] - ((r2v >> 0x11) & 0x3F);
        }
        SetMotion(&p->s, *mo8);
        asm("" : "+r"(m9));
        {
          register s32 w1 asm("r1");
          w1 = m9;
          (p->s).work[3] = w1;
        }
        (p->s).mode[2]++;
      }
        /* fallthrough */
      case 1: {
        register u32 one asm("r1");
        s32 t3 = (p->s).work[3] + 1;
        u32 tf;
        s32 v2;
        (p->s).work[3] = t3;
        tf = t3 & 0xFF;
        one = 1;
        if (tf & one) {
          register s32 vf asm("r0");
          vf = (p->s).flags;
          vf |= one;
          v2 = vf;
        } else {
          register u8 lf3 asm("r1");
          register s32 vv3 asm("r0");
          lf3 = (p->s).flags;
          vv3 = 0xFE;
          vv3 &= lf3;
          v2 = vv3;
        }
        (p->s).flags = v2;
        (p->s).d.y += 0x10;
        if ((p->s).d.y > 0x700) {
          (p->s).d.y = 0x700;
        }
        (p->s).coord.y += (p->s).d.y;
        (p->s).coord.x += (p->s).d.x;
        UpdateEntityAnim(&p->s);
        break;
      }
    }
  }
}

static const u8 u8_ARRAY_0836ee30[32 * 3] = {
    0x20, 0x01, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0xA0, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0xA0, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0xA0, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0xA0, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0xA0, 0xFE, 0xFF, 0xFF, 0x20, 0x01, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x50, 0xFF, 0xFF, 0xFF, 0xA0, 0xFE, 0xFF, 0xFF,
};

// 0x0836ee90
const u8* const PTR_ARRAY_0836ee90[3] = {
    &u8_ARRAY_0836ee30[0],
    &u8_ARRAY_0836ee30[32],
    &u8_ARRAY_0836ee30[64],
};
