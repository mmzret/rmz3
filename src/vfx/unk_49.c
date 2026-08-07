#include "global.h"
#include "palette_animation.h"
#include "vfx.h"


static void VFX49_Init(struct Entity* p);
static void VFX49_Update(struct Entity* p);
static void VFX49_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX49Routine = {
    [ENTITY_INIT] =      (void*)VFX49_Init,
    [ENTITY_UPDATE] =    (void*)VFX49_Update,
    [ENTITY_DIE] =       (void*)VFX49_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080c025c(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 0;
    p->coord.x = x, p->coord.y = y;
  }
}

void createLaserSign(struct Entity* e, s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 1;
    p->coord.x = x, p->coord.y = y;
    p->unk_28 = (void*)e;
  }
}

void FUN_080c02f4(s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 2;
    p->coord.x = x, p->coord.y = y;
  }
}

void FUN_080c0340(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_049);
    p->work[0] = 3;
    p->unk_28 = (void*)e;
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX49_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX49_Update(p);
}

void FUN_080c0400(struct VFX* p);
void FUN_080c04d4(struct VFX* p);
void FUN_080c05a8(struct VFX* p);
void FUN_080c065c(struct VFX* p);

static void VFX49_Update(struct Entity* p) {
  static const VFXFunc sUpdates[4] = {
      (void*)FUN_080c0400,
      (void*)FUN_080c04d4,
      (void*)FUN_080c05a8,
      (void*)FUN_080c065c,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

static void VFX49_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

void FUN_080c0400(struct VFX* p) {
  register s32 m asm("r5");
  m = (p->s).mode[2];
  switch (m) {
    case 0:
      (p->s).renderPrio = 0x19;
      SetMotion(&p->s, (RANDOM(RNG_0202f388) & 3) + 0x5102);
      (p->s).d.y = m;
      (p->s).work[2] = 0x46;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      register s32 t asm("r1");
      register s32 z asm("r2");
      register u32 u asm("r0");
      register u8 f asm("r0");
      {
        register s32 dy asm("r1");
        register s32 cy asm("r0");
        dy = (p->s).d.y;
        dy += 4;
        (p->s).d.y = dy;
        cy = (p->s).coord.y;
        cy += dy;
        (p->s).coord.y = cy;
      }
      {
        register s32 tl asm("r0");
        tl = (p->s).work[2];
        t = tl - 1;
      }
      z = 0;
      asm volatile("" : "+r"(z));
      (p->s).work[2] = t;
      u = (u8)t;
      if (u <= 9) {
        s32 k = 1;
        t &= k;
        asm volatile("" ::: "cc");
        if (t == 0) {
          goto clr;
        }
        {
          register u8 fv asm("r0");
          register s32 one asm("r1");
          fv = (p->s).flags;
          one = 1;
          fv |= one;
          asm volatile("" : "+r"(fv));
          f = fv;
        }
        goto fs;
      }
      if (u > 0x13) {
        goto after;
      }
      {
        s32 k2 = 2;
        t &= k2;
        asm volatile("" : "+r"(t));
        if (t == 0) {
          goto clr;
        }
        {
          register u8 fv2 asm("r0");
          register s32 one2 asm("r1");
          fv2 = (p->s).flags;
          one2 = 1;
          fv2 |= one2;
          f = fv2;
        }
        goto fs;
      }
    clr : {
      register u8 h asm("r1");
      h = (p->s).flags;
      asm("" : "+r"(h));
      f = 0xFE;
      f &= h;
    }
    fs:
      (p->s).flags = f;
    after:
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] == 0) {
        register u8 g2 asm("r0");
        register u8 h2 asm("r1");
        h2 = (p->s).flags;
        asm("" : "+r"(h2));
        g2 = 0xFE;
        g2 &= h2;
        h2 = 0xFD;
        g2 &= h2;
        (p->s).flags = g2;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void FUN_080c04d4(struct VFX* p) {
  struct Entity* q = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0: {
      u32 pid;
      register u32 k2 asm("r2");
      register u32 k0 asm("r0");
      SetMotion(&p->s, 0x4E00);
      pid = ((u32)GetEntityPaletteID(&p->s) << 24) >> 19;
      k2 = 0x200;
      asm volatile("add %0, %1, #0" : "=&l"(k0) : "l"(k2));
      pid |= k0;
      ((void (*)(u16, u32))StartPaletteAnimation)(0x57, pid);
      StepPaletteAnimation(0x57);
      (p->s).work[2] = 0x1e;
      (p->s).mode[2]++;
    }
      /* fallthrough */
    case 1: {
      s32 raw = (p->s).work[2] - 1;
      (p->s).work[2] = raw;
      if ((raw << 24) == 0) {
        (p->s).mode[2]++;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
    case 2: {
      u32* st;
      RemovePaletteAnimation(0x57);
      st = (u32*)((u8*)q + 0xb4);
      *st |= 4;
      SetMotion(&p->s, 0x4E01);
      (p->s).mode[2]++;
    }
      /* fallthrough */
    case 3: {
      s32 m;
      UpdateEntityAnim(&p->s);
      m = *(u8*)((u8*)p + 0x73);
      if (m == 3) {
        u32* st2 = (u32*)((u8*)q + 0xb4);
        *st2 |= 8;
        {
          register u8 fv asm("r0");
          register u8 fl asm("r1");
          fl = (p->s).flags;
          asm("" : "+r"(fl));
          fv = 0xFE;
          fv &= fl;
          fl = 0xFD;
          fv &= fl;
          (p->s).flags = fv;
        }
        {
          u32 tbl = (u32)gVFXFnTable;
          u32 id = ((p->s).id) << 2;
          EntityFunc** rt = (EntityFunc**)(tbl + id);
          *(u32*)((p->s).mode) = m;
          (p->s).onUpdate = (void*)(*rt)[ENTITY_DISAPPEAR];
        }
      }
      break;
    }
  }
}

void FUN_080c05a8(struct VFX* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, (RANDOM(RNG_0202f388) & 1) + MOTION(0x4F, 0x03));
      (p->s).work[2] = 0x1a;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      register u8 w asm("r1");
      (p->s).coord.y -= 0x100;
      w = (p->s).work[2];
      if (w <= 0xd) {
        register u8 m asm("r0");
        m = 1;
        m &= w;
        if (m != 0) {
          register u8 f asm("r0");
          register u8 t asm("r1");
          t = (p->s).flags;
          f = DISPLAY;
          f |= t;
          (p->s).flags = f;
        } else {
          register u8 f asm("r0");
          register u8 t asm("r1");
          t = (p->s).flags;
          f = 0xFE;
          f &= t;
          asm volatile("" ::"r"(t));
          (p->s).flags = f;
        }
      }
      UpdateEntityAnim(&p->s);
      if ((u8)--(p->s).work[2] == 0) {
        register u8 f asm("r0");
        register u8 t asm("r1");
        register u8 k2 asm("r1");
        t = (p->s).flags;
        f = 0xFE;
        f &= t;
        asm volatile("" ::"r"(t));
        k2 = 0xFD;
        f &= k2;
        (p->s).flags = f;
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void FUN_080c065c(struct VFX* p) {
  struct Entity* e = (p->s).unk_28;
  if (e->mode[0] == 4) {
    RemovePaletteAnimation(0x57);
    {
      register u8 e1 asm("r1");
      register s32 fp asm("r0");
      e1 = (p->s).flags;
      fp = 0xFE;
      fp &= e1;
      {
        register s32 c2 asm("r1");
        c2 = 0xFD;
        fp &= c2;
      }
      (p->s).flags = fp;
    }
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, 0x4E02);
      {
        u32 g0 = GetEntityPaletteID(&p->s);
        u32 g = (u8)g0 << 5;
        StartPaletteAnimation(0x57, g | 0x200);
      }
      StepPaletteAnimation(0x57);
      (p->s).work[2] = 2;
      (p->s).coord.x = e->coord.x;
      (p->s).coord.y = e->coord.y;
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      if ((p->s).work[2] != 0) {
        if ((p->s).work[2] == 1) {
          RemovePaletteAnimation(0x57);
        }
        (p->s).work[2]--;
      }
      UpdateEntityAnim(&p->s);
      if (e->mode[0] > 1) {
        RemovePaletteAnimation(0x57);
        {
          register u8 e1 asm("r1");
          register s32 fp asm("r0");
          e1 = (p->s).flags;
          fp = 0xFE;
          fp &= e1;
          {
            register s32 c2 asm("r1");
            c2 = 0xFD;
            fp &= c2;
          }
          (p->s).flags = fp;
        }
        SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
        break;
      }
      if ((*(u32*)((u8*)e + 0xb4) & 0x800) == 0) {
        (p->s).mode[2]++;
      }
      break;
    case 2:
      SetMotion(&p->s, 0x4E03);
      (p->s).mode[2]++;
      /* fallthrough */
    case 3:
      UpdateEntityAnim(&p->s);
      {
        u8 st = (p->s).motion.state;
        if (st != 3) {
          break;
        }
        {
          register u8 e1 asm("r1");
          register s32 fp asm("r0");
          e1 = (p->s).flags;
          fp = 0xFE;
          fp &= e1;
          {
            register s32 c2 asm("r1");
            c2 = 0xFD;
            fp &= c2;
          }
          (p->s).flags = fp;
        }
        {
          u32 tbl, id;
          EntityFunc** routine_table;
          tbl = (u32)gVFXFnTable;
          id = ((p->s).id) << 2;
          routine_table = (EntityFunc**)(tbl + id);
          *(u32*)((p->s).mode) = st;
          (p->s).onUpdate = (void*)(*routine_table)[3];
        }
      }
      break;
  }
}

static const u8 sInitModes[4] = {0, 1, 2, 3};
