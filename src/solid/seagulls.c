#include "entity.h"
#include "global.h"
#include "mod.h"
#include "solid.h"
#include "syssav.h"
#include "stagerun.h"

struct Seagulls {
  struct Entity s;
  struct Body body;
  // props (16bytes, offset: 0xB4..)
  s32 unk_b4_x;   // 0xB4
  u8 unk_b8[12];  // 0xB8
};

typedef struct {
  COLLISION_OBJECT_HDR;
  s32 unk_b4_x;   // 0xB4
  u8 unk_b8[12];  // 0xB8
} Seagulls;
static_assert(sizeof(Seagulls) == sizeof(struct Solid));

static void Seagulls_Init(Seagulls* p);
static void Seagulls_Update(Seagulls* p);
static void Seagulls_Die(Seagulls* p);

// clang-format off
const SolidRoutine gSeagullsRoutine = {
    [ENTITY_INIT] =      (void*)Seagulls_Init,
    [ENTITY_UPDATE] =    (void*)Seagulls_Update,
    [ENTITY_DIE] =       (void*)Seagulls_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateSeagulls(struct Entity* q, u8 t, u8 param_3) {
  struct Entity* p = AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_SEAGULLS);
    p->unk_28 = (void*)q;
    p->coord = q->coord;
    p->work[0] = t, p->work[1] = param_3;
  }
  return p;
}

static void FUN_080dcd20(Seagulls* p);
void FUN_080dcdac(Seagulls* p);
void FUN_080dced4(Seagulls* p);

static void Seagulls_Init(Seagulls* p) {
  switch (p->work[0]) {
    case 0: {
      FUN_080dcd20(p);
      break;
    }
    case 1: {
      FUN_080dcdac(p);
      break;
    }
    case 2: {
      FUN_080dced4(p);
      break;
    }
  }
}

void FUN_080dd02c(Seagulls* p);
void FUN_080dd11c(Seagulls* p);
NON_MATCH void FUN_080dd364(Seagulls* p);

static void Seagulls_Update(Seagulls* p) {
  switch (p->work[0]) {
    case 0: {
      FUN_080dd02c(p);
      break;
    }
    case 1: {
      FUN_080dd11c(p);
      break;
    }
    case 2: {
      FUN_080dd364(p);
      break;
    }
  }
}

void FUN_080dd400(Seagulls* p);
void FUN_080dd418(Seagulls* p);
void FUN_080dd430(Seagulls* p);

static void Seagulls_Die(Seagulls* p) {
  switch (p->work[0]) {
    case 0: {
      FUN_080dd400(p);
      break;
    }
    case 1: {
      FUN_080dd418(p);
      break;
    }
    case 2: {
      FUN_080dd430(p);
      break;
    }
  }
}

// --------------------------------------------

static void FUN_080dcd20(Seagulls* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  if (!FLAG(gSystemSavedata.flags, MOD_SEAGULLS)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  p->unk_2c = (void*)CreateSeagulls((void*)p, 1, 0);
  p->unk_b4_x = p->coord.x;
  p->work[2] = 0, p->work[3] = 0;
  Seagulls_Update(p);
}

void FUN_080dcdac(Seagulls* p) {
  s32* pb4;
  u8* a;
  u8 fl;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion((struct Entity*)p);
  {
    register u8 f0 asm("r1");
    register s32 d0 asm("r0");
    f0 = p->flags;
    d0 = DISPLAY;
    d0 |= f0;
    {
      register s32 c2 asm("r1");
      c2 = FLIPABLE;
      d0 |= c2;
    }
    p->flags = d0;
  }
  SetMotion((struct Entity*)p, 0xDA00);
  {
    u8* pr = (u8*)p + 0x49;
    *pr |= 0xC;
  }
  p->renderPrio = 0x1D;
  pb4 = &((struct Seagulls*)p)->unk_b4_x;
  *pb4 = p->coord.x;
  p->flags |= X_FLIP;
  (p->spr).xflip = 1;
  a = (u8*)p + 0x4a;
  {
    u32 ten = 0x10;
    u8 b2 = *a;
    s32 msk = -0x11;
    msk &= b2;
    msk |= ten;
    *a = msk;
    ten &= p->flags;
    fl = (u8)ten;
  }
  if (fl != 0) {
    struct Camera* cam = &gStageRun.vm.camera;
    s32* pb8;
    s32 r;
    p->coord.x = cam->viewport.x - 0x8800;
    pb8 = (s32*)(a + 0x6e);
    r = ((RANDOM(RNG_0202f388) & 0x3F) << 8) + 0x2000;
    *pb8 = *pb4 + r;
    p->d.x = 0;
  } else {
    struct Camera* cam = &gStageRun.vm.camera;
    s32* pb8;
    s32 r;
    p->coord.x = cam->viewport.x + 0x87FF;
    pb8 = (s32*)((u8*)p + 0xb8);
    r = ((RANDOM(RNG_0202f388) & 0x3F) << 8) + 0x2000;
    *pb8 = *pb4 - r;
    p->d.x = fl;
  }
  p->work[2] = 0;
  Seagulls_Update(p);
}

void FUN_080dced4(Seagulls* p) {
  register s32 z6 asm("r6");
  s32 one;
  {
    u32 tbl = (u32)(gSolidFnTable);
    u32 id;
    EntityFunc** rt;
    register s32 mo asm("r1");
    id = (p->id) << 2;
    rt = (EntityFunc**)(tbl + id);
    mo = 1;
    *(u32*)(p->mode) = mo;
    p->onUpdate = (void*)(*rt)[1];
  }
  InitNonAffineMotion((struct Entity*)p);
  {
    u32 fl = p->flags;
    one = 1;
    asm("" : "+r"(one) : "r"(fl));
    z6 = 0;
    asm volatile("" : "+r"(z6) : "r"(one));
    fl |= one;
    fl |= 2;
    p->flags = fl;
  }
  SetMotion((struct Entity*)p, 0xDA02);
  {
    u8* pr = (u8*)p + 0x49;
    *pr |= 0xC;
  }
  {
    u8* a2 = (u8*)p + 0x25;
    *a2 = 0x1E;
    a2 += 0x8F;
    *(s32*)a2 = p->coord.x;
  }
  {
    s32 r = RANDOM(RNG_0202f388) & one;
    s32 sh;
    if (r != 0) {
      p->flags |= 0x10;
    } else {
      p->flags &= 0xEF;
    }
    sh = r;
    asm("" : "+r"(r));
    p->spr.xflip = sh;
    {
      u8* oa = (u8*)p + 0x4a;
      s32 ov, m11;
      sh <<= 4;
      ov = *oa;
      m11 = -0x11;
      m11 &= ov;
      *oa = m11 | sh;
    }
  }
  if (p->flags & 0x10) {
    struct Camera* cam = &gStageRun.vm.camera;
    p->coord.x = cam->viewport.x - 0x8800;
    p->d.x = (RANDOM(RNG_0202f388) & 0x7F) + 0x80;
  } else {
    struct Camera* cam = &gStageRun.vm.camera;
    register u32 sd asm("r1");
    register u32 ac asm("r0");
    s32 mk;
    p->coord.x = cam->viewport.x + 0x87FF;
    sd = RNG_0202f388;
    ac = 0x343FD;
    sd = sd * ac;
    ac = 0x269EC3;
    sd = sd + ac;
    sd <<= 1;
    RNG_0202f388 = sd >> 1;
    sd >>= 0x11;
    mk = 0x7F;
    sd &= mk;
    mk -= 0xFF;
    p->d.x = mk - sd;
  }
  {
    s32 r3 = RANDOM(RNG_0202f388) & 0x3F;
    p->coord.y += (0x20 - r3) << 8;
  }
  Seagulls_Update(p);
}

void FUN_080dd02c(Seagulls* p) {
  struct Camera* cam = &gStageRun.vm.camera;
  if (p->coord.x < cam->viewport.x + -0x29400) {
    {
      register u8 g asm("r0");
      register u8 h asm("r1");
      register s32 z asm("r2");
      h = p->flags;
      asm("" : "+r"(h));
      g = 0xFE;
      g &= h;
      z = 0;
      h = 0xFD;
      g &= h;
      p->flags = g;
      {
        u8* a = (u8*)p + 0x8c;
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z;
      }
    }
    {
      register u8 g2 asm("r0");
      register u8 h2 asm("r1");
      h2 = p->flags;
      asm("" : "+r"(h2));
      g2 = 0xFB;
      g2 &= h2;
      p->flags = g2;
    }
    SET_SOLID_ROUTINE(p, 3);
    return;
  }
  if (p->unk_2c != NULL) {
    if ((p->unk_2c)->mode[0] > 1) {
      p->unk_2c = NULL;
      p->work[3] = RANDOM(RNG_0202f388) & 0x3F;
    }
  } else {
    s32 t = p->work[3];
    asm("" : "+r"(t));
    p->work[3] = t + 1;
    if ((u8)t > 0x78) {
      p->unk_2c = (struct Entity*)CreateSeagulls((struct Entity*)p, 1, 0);
    }
  }
  {
    s32 t2 = p->work[2];
    asm("" : "+r"(t2));
    p->work[2] = t2 + 1;
    if ((u8)t2 > 0xF0) {
      CreateSeagulls((struct Entity*)p, 2, 0);
      p->work[2] = RANDOM(RNG_0202f388) & 0x3F;
    }
  }
}

void FUN_080dd11c(Seagulls* p) {
  register s32 m asm("r4");
  {
    s32 m2 = p->mode[2];
    if (m2 == 0) {
      if ((p->unk_28)->mode[0] > 1) {
        asm("" : "+l"(m2));
        p->mode[2] = m2 + 1;
      }
    } else {
      p->work[2] = 0xf;
    }
  }
  UpdateEntityAnim((struct Entity*)p);
  m = p->mode[1];
  switch (m) {
    case 0: {
      register s32 cx asm("r6");
      s32 cx0 = p->coord.x;
      s32 dx = p->d.x;
      p->coord.x = cx0 + dx;
      if ((p->flags & X_FLIP) != 0) {
        if (dx <= 0x1BF) {
          p->d.x = dx + 4;
        } else {
          if (p->motion.cmdIdx == 3) {
            GotoMotion((struct Entity*)p, MOTION(0xDA, 0x00), 3, 4);
          }
        }
        {
          s32 w0;
          w0 = p->work[2];
          asm("" : "+l"(w0));
          cx = p->coord.x;
          asm volatile("add %0, %1, #0" : "=&l"(m) : "l"(w0));
        }
        if (m != 0xf) {
          if (*(s32*)((u8*)p + 0xb8) >= cx) {
            goto after;
          }
          goto divmode;
        }
      } else {
        if (dx > -0x1C0) {
          p->d.x = dx - 4;
        } else {
          if (p->motion.cmdIdx == 3) {
            GotoMotion((struct Entity*)p, MOTION(0xDA, 0x00), 3, 4);
          }
        }
        {
          s32 w0;
          w0 = p->work[2];
          asm("" : "+l"(w0));
          cx = p->coord.x;
          asm volatile("add %0, %1, #0" : "=&l"(m) : "l"(w0));
        }
        if (m != 0xf) {
          if (*(s32*)((u8*)p + 0xb8) <= cx) {
            goto after;
          }
        divmode:
          p->unk_coord.x = p->d.x / 0x18;
          p->mode[1]++;
        }
      }
    after:
      if (m != 0xf) {
        break;
      }
      if ((p->flags & X_FLIP) != 0) {
        if (cx > (0x8a << 0xb)) {
          SET_SOLID_ROUTINE(p, 2);
          break;
        }
        if (cx > (&gStageRun.vm.camera)->viewport.x + 0x97FF) {
          SET_SOLID_ROUTINE(p, 2);
        }
        break;
      }
      if (cx < (&gStageRun.vm.camera)->viewport.x - 0x9800) {
        SET_SOLID_ROUTINE(p, 2);
      }
      break;
    }
    case 1: {
      u32 f;
      u32 nv;
      SetMotion((struct Entity*)p, MOTION(0xDA, 0x01));
      f = p->flags;
      nv = m;
      nv &= ~(f >> 4);
      if (nv != 0) {
        u32 t = 0x10;
        t |= f;
        p->flags = t;
      } else {
        u32 t = 0xef;
        t &= f;
        p->flags = t;
      }
      {
        u32 one = 1;
        u32 v = one & nv;
        register u8* oa asm("r3");
        s32 sh4;
        s32 ov;
        s32 m11;
        *((u8*)p + 0x4c) = v;
        oa = (u8*)p + 0x4a;
        sh4 = v << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11 | sh4;
      }
      UpdateEntityAnim((struct Entity*)p);
      p->work[2]++;
      p->mode[1]++;
      FALLTHROUGH;
    }
    case 2: {
      s32 dx;
      p->coord.x += p->d.x;
      dx = p->d.x;
      p->d.x = dx - p->unk_coord.x;
      if (p->motion.state != 3) {
        break;
      }
      SetMotion((struct Entity*)p, MOTION(0xDA, 0x00));
      UpdateEntityAnim((struct Entity*)p);
      if ((p->flags & X_FLIP) != 0) {
        register s32* dst asm("r4");
        register s32* src asm("r3");
        u32 r;
        s32 o;
        dst = (s32*)((u8*)p + 0xb8);
        src = (s32*)((u8*)p + 0xb4);
        r = RNG_0202f388 * 0x343FD + 0x269EC3;
        r <<= 1;
        RNG_0202f388 = r >> 1;
        o = ((r >> 0x11) & 0x3f) << 8;
        o += 0x80 << 6;
        *dst = *src + o;
      } else {
        register s32* dst asm("r4");
        register s32* src asm("r3");
        u32 r;
        s32 o;
        dst = (s32*)((u8*)p + 0xb8);
        src = (s32*)((u8*)p + 0xb4);
        r = RNG_0202f388 * 0x343FD + 0x269EC3;
        r <<= 1;
        RNG_0202f388 = r >> 1;
        o = ((r >> 0x11) & 0x3f) << 8;
        o += 0x80 << 6;
        *dst = *src - o;
      }
      p->mode[1] = 0;
      break;
    }
  }
}

NON_MATCH void FUN_080dd364(Seagulls* p) {
#if MODERN
  s32 x;
  register u8 fl asm("r3");
  u8 t;
  s32 mm;
  u8 fv;
  u32 z;
  UpdateEntityAnim((struct Entity*)p);
  {
    register s32 cx asm("r1");
    cx = p->coord.x;
    x = cx + p->d.x;
  }
  p->coord.x = x;
  fl = p->flags;
  mm = 0x10 & fl;
  t = mm;
  if (t != 0) {
    if (x > 0x45000) {
      fv = 0xFE & fl;
      z = 0;
      goto kill;
    }
    if (x > gStageRun.vm.camera.viewport.x + 0x97FF) {
      fv = 0xFE & fl;
      z = 0;
      goto kill;
    }
    return;
  }
  if (x >= gStageRun.vm.camera.viewport.x - 0x9800) {
    return;
  }
  fv = 0xFE & fl;
  z = t;
kill: {
  register u8* q asm("r0");
  fv &= 0xFD;
  p->flags = fv;
  q = (u8*)p + 0x8c;
  *(u32*)q = z;
  asm volatile("add %0, #4" : "+r"(q));
  *(u32*)q = z;
  asm volatile("add %0, #4" : "+r"(q));
  *q = z;
  p->flags &= 0xFB;
  SET_SOLID_ROUTINE(p, 3);
}
#else
  INCCODE("asm/solid/seagulls_080dd364.inc");
#endif
}

void FUN_080dd400(Seagulls* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080dd418(Seagulls* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080dd430(Seagulls* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}
