#include "entity.h"
#include "global.h"
#include "vfx.h"

struct Unk77Props { u32 unk_0; u8 unk_4[4]; u8 unk_8; };

void Ghost77_Init(struct VFX* p);
static void FUN_080c843c(struct VFX* p);
static void FUN_080c8488(struct VFX* p);
static void FUN_080c8628(struct VFX* p);
static void FUN_080c8684(struct VFX* p);
static void FUN_080c8744(struct VFX* p);
static const VFXFunc sUpdates[5];

void Ghost77_Update(struct VFX* p);
void Ghost77_Die(struct VFX* p);

// clang-format off
const VFXRoutine gMinigameIconRoutine = {
    [ENTITY_INIT] =      Ghost77_Init,
    [ENTITY_UPDATE] =    Ghost77_Update,
    [ENTITY_DIE] =       Ghost77_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateMinigameIcon_1(Coords32* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 0;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX* CreateCopyXIcon(struct Zero* z, struct Coord* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 1;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).unk_28 = (struct Entity*)z;
  }
  return p;
}

struct VFX* FUN_080c8204(struct Coord* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 2;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX* FUN_080c825c(struct Entity* e, struct Coord* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 3;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).unk_28 = e;
  }
  return p;
}

struct VFX* FUN_080c82b8(struct Entity* e, struct Coord* c, u8 a2, u32 a3, u8 a4) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 4;
    (p->s).work[1] = a2;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).unk_28 = e;
    ((struct Unk77Props*)p->buffer)->unk_0 = a3;
    ((struct Unk77Props*)p->buffer)->unk_8 = a4;
  }
  return p;
}

void Ghost77_Init(struct VFX* p0) {
  struct VFX* p = p0;
  register s32 w asm("r5");
  register s32 z asm("r2");
  w = (p->s).work[0];
  if (w == 0) {
    register s32 one asm("r2");
    (p->s).flags &= ~X_FLIP;
    one = 1;
    ((p->s).spr).xflip = w;
    {
      u8* oa = (u8*)p + 0x4a;
      s32 ov = *oa;
      s32 m11 = -0x11;
      m11 &= ov;
      *oa = m11;
    }
    {
      u32 tbl = (u32)gVFXFnTable;
      EntityFunc** rt = (EntityFunc**)(tbl + (((p->s).id) << 2));
      *(u32*)((p->s).mode) = one;
      (p->s).onUpdate = (void*)((*rt)[1]);
    }
    (p->s).mode[1] = w;
    (p->s).mode[2] = w;
    (p->s).mode[3] = w;
  } else if (w == 1) {
    u32 tbl;
    EntityFunc** rt;
    z = 0;
    (p->s).flags &= ~X_FLIP;
    ((p->s).spr).xflip = z;
    {
      u8* oa = (u8*)p + 0x4a;
      s32 ov = *oa;
      s32 m11 = -0x11;
      m11 &= ov;
      *oa = m11;
    }
    tbl = (u32)gVFXFnTable;
    rt = (EntityFunc**)(tbl + (((p->s).id) << 2));
    *(u32*)((p->s).mode) = w;
    (p->s).onUpdate = (void*)((*rt)[1]);
    (p->s).mode[1] = w;
    (p->s).mode[2] = z;
    (p->s).mode[3] = z;
  } else {
    u32 tbl;
    EntityFunc** rt;
    register s32 one2 asm("r3");
    if (w == 2) {
      goto arm3;
    }
    if (w == 3) {
      goto arm3;
    }
    if (w != 4) {
      goto done;
    }
  arm3:
    z = 0;
    (p->s).flags &= ~X_FLIP;
    one2 = 1;
    ((p->s).spr).xflip = z;
    {
      u8* oa = (u8*)p + 0x4a;
      s32 ov = *oa;
      s32 m11 = -0x11;
      m11 &= ov;
      *oa = m11;
    }
    tbl = (u32)gVFXFnTable;
    rt = (EntityFunc**)(tbl + (((p->s).id) << 2));
    *(u32*)((p->s).mode) = one2;
    (p->s).onUpdate = (void*)((*rt)[1]);
    (p->s).mode[1] = w;
    (p->s).mode[2] = z;
    (p->s).mode[3] = z;
  }
done:
  Ghost77_Update(p);
}

void Ghost77_Update(struct VFX* p) {
  (sUpdates[(p->s).mode[1]])(p);
}

void Ghost77_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

static void FUN_080c843c(struct VFX* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register u8 fv asm("r0");
      u8 t;
      InitNonAffineMotion(&p->s);
      t = (p->s).flags;
      fv = DISPLAY;
      fv |= t;
      fv |= FLIPABLE;
      (p->s).flags = fv;
      (p->s).coord.x = 0xF000;
      (p->s).coord.y = 0xA000;
      SetMotion(&p->s, MOTION(0xF4, 0x00));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim(&p->s);
      break;
  }
}

static void FUN_080c8488(struct VFX* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register s32 z asm("r4");
      register s32 w1 asm("r1");
      register s32 cx asm("r2");
      register s32 cy asm("r3");
      InitScalerotMotion1(&p->s);
      {
        u8* a;
        register s32 v asm("r0");
        a = (u8*)p + 0x24;
        v = 0;
        *a = v;
        a += 0x2c;
        z = 0;
        v = 0x80 << 1;
        *(u16*)a = v;
        a += 2;
        asm("" : "+r"(a));
        *(u16*)a = v;
      }
      {
        register s32 g asm("r0");
        s32 k;
        g = (p->s).flags;
        asm("" : "+r"(g));
        k = 1;
        g |= k;
        k = 2;
        g |= k;
        (p->s).flags = g;
      }
      {
        register u8* b asm("r0");
        b = (u8*)p + 0x74;
        *b = z;
      }
      cx = 0xf0 << 8;
      (p->s).coord.x = cx;
      cy = 0xa0 << 8;
      (p->s).coord.y = cy;
      w1 = (p->s).work[1];
      {
        register s32 nx asm("r0");
        if (w1 != 0) {
          goto nz;
        }
        (p->s).coord.x = 0x88 << 9;
        (p->s).coord.y = 0xa8 << 8;
        (p->s).work[3] = z;
        goto setm;
      nz:
        if (w1 != 1) {
          goto n1;
        }
        nx = 0x80 << 4;
        asm("" : "+r"(nx));
        nx = cx + nx;
        goto store;
      n1:
        if (w1 != 2) {
          goto setm;
        }
        z = 0xe0 << 6;
        nx = cx + z;
      store:
        (p->s).coord.x = nx;
        nx = 0xc0 << 4;
        asm("" : "+r"(nx));
        nx = cy + nx;
        (p->s).coord.y = nx;
        (p->s).work[3] = w1;
      }
    setm: {
      const u16* tb;
      register s32 i asm("r0");
      tb = (const u16*)0x0836F998;
      asm("" : "+r"(tb));
      i = (p->s).work[3];
      i <<= 1;
      i += (s32)tb;
      SetMotion(&p->s, *(const u16*)i);
    }
      (p->s).d.y = 0x80 << 1;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      if (*((u8*)p + 0x74) == 0) {
        goto upd;
      }
      (p->s).work[2] = 5;
      goto bump;
    case 2: {
      register u16* sp asm("r1");
      {
        register s32 v asm("r0");
        v = (p->s).d.y;
        v -= 0x33;
        (p->s).d.y = v;
        if (v < 0) {
          (p->s).d.y = 0;
        }
      }
      {
        register s32 v2 asm("r0");
        v2 = (p->s).d.y;
        sp = (u16*)((u8*)p + 0x50);
        *sp = v2;
      }
      if ((p->s).work[2] != 0) {
        if ((u8)--(p->s).work[2] != 0) {
          goto upd;
        }
      }
      *sp = 0;
    bump:
      (p->s).mode[2]++;
    upd:
      UpdateEntityAnim(&p->s);
      break;
    }
    case 3: {
      register s32 nv asm("r0");
      if (*((u8*)p + 0x74) == 1) {
        nv = (p->s).work[3];
        if (nv != 0) {
          nv -= 1;
        } else {
          nv = 2;
        }
      } else {
        nv = (p->s).work[3];
        if ((u32)nv <= 1) {
          nv += 1;
        } else {
          nv = 0;
        }
      }
      (p->s).work[3] = nv;
      {
        register const u16* tb asm("r4");
        tb = (const u16*)0x0836F998;
      asm("" : "+r"(tb));
        nv = ((u32)(p->s).work[3]) % 3;
        nv = ((u32)(u8)nv) << 1;
        nv += (s32)tb;
        SetMotion(&p->s, *(const u16*)nv);
      }
      nv = 0;
      (p->s).d.y = nv;
      (p->s).work[2] = 5;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 4: {
      register s32 lim asm("r4");
      register u16* sp2 asm("r6");
      {
        register s32 v asm("r0");
        v = (p->s).d.y;
        v += 0x33;
        (p->s).d.y = v;
        lim = 0x80 << 1;
        if (v > lim) {
          (p->s).d.y = lim;
        }
      }
      {
        register s32 v2 asm("r0");
        v2 = (p->s).d.y;
        sp2 = (u16*)((u8*)p + 0x50);
        *sp2 = v2;
      }
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] != 0) {
        if ((u8)--(p->s).work[2] != 0) {
          break;
        }
      }
      {
        register u8* b2 asm("r0");
        register s32 z2 asm("r1");
        b2 = (u8*)p + 0x74;
        z2 = 0;
        *b2 = z2;
      }
      *sp2 = lim;
      (p->s).mode[2] = 1;
      break;
    }
  }
}

static void FUN_080c8628(struct VFX* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register u8 fv asm("r0");
      u8 t;
      InitNonAffineMotion(&p->s);
      t = (p->s).flags;
      fv = DISPLAY;
      fv |= t;
      fv |= FLIPABLE;
      (p->s).flags = fv;
      SetMotion(&p->s, 9);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state == 3) {
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

static void FUN_080c8684(struct VFX* p) {
  switch ((p->s).mode[2]) {
    case 0:
      InitNonAffineMotion(&p->s);
      (p->s).flags = DISPLAY | (p->s).flags;
      (p->s).flags |= FLIPABLE;
      if ((p->s).work[1] == 0) {
        SetMotion(&p->s, 8);
      } else {
        SetMotion(&p->s, 0x12);
      }
      ForceEntityPalette(&p->s, 0xE);
      (p->s).work[2] = 0;
      (p->s).work[3] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 w;
      s32 two;
      (p->s).coord = ((p->s).unk_28)->coord;
      (p->s).coord.y -= 0x1000;
      w = (p->s).work[2] + 1;
      (p->s).work[2] = w;
      if ((u8)w > 0x5A) {
        (p->s).work[2] = 0x5A;
      }
      if ((p->s).work[2] > 0x24 && (p->s).work[3] == 0) {
        (p->s).work[3] = 1;
        ForceEntityPalette(&p->s, 0xF);
      }
      UpdateEntityAnim(&p->s);
      {
        s32 inp = gJoypad[0].input;
        s32 t;
        two = 2;
        asm volatile("add %0, %1, #0" : "=&l"(t) : "l"(two));
        t &= inp;
        if (t == 0) {
          u32 tbl = (u32)gVFXFnTable;
          u32 id = ((p->s).id) << 2;
          EntityFunc** rt = (EntityFunc**)(tbl + id);
          *(u32*)((p->s).mode) = two;
          (p->s).onUpdate = (void*)(*rt)[ENTITY_DIE];
        }
      }
      break;
    }
  }
}

static void FUN_080c8744(struct VFX* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      u8 w;
      InitNonAffineMotion(&p->s);
      {
        register u8 fv asm("r1");
        register u8 k asm("r0");
        k = (p->s).flags;
        fv = 1;
        fv |= k;
        k = 2;
        fv |= k;
        (p->s).flags = fv;
      }
      w = (p->s).work[1];
      if (w == 0) {
        SetMotion(&p->s, MOTION(0x9E, 0));
      } else if (w == 2) {
        SetMotion(&p->s, MOTION(0x9F, 0));
      } else {
        SetMotion(&p->s, MOTION(0xA1, 0));
      }
      (p->s).work[2] = 0;
      (p->s).work[3] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register u8* lim asm("r6");
      register u8* cur asm("r5");
      u8 w1;
      lim = *(u8**)((u8*)p + 0x74);
      w1 = (p->s).work[1];
      cur = (u8*)p + 0x7c;
      if (w1 == 3) {
        u8* q = (u8*)(p->s).unk_2c + 0xDC4;
        s32 t = (*cur << 12) + -0x6800;
        s32 v = *(s32*)q - t;
        struct Entity* e;
        (p->s).coord.x = v + -0x800;
        (p->s).coord.y = *(s32*)(q + 4) + 0x3800;
        e = (p->s).unk_28;
        if (*(s16*)((u8*)e + 4) == 1) {
          s32 u = v + -0xA00;
          u += *(s32*)((u8*)e + 0x34);
          (p->s).coord.x = u;
        }
      }
      UpdateEntityAnim(&p->s);
      if (*cur >= *lim) {
        (p->s).mode[2]++;
      }
      break;
    }
    case 2:
      (p->s).mode[2] = 3;
      FALLTHROUGH;
    case 3:
      SET_VFX_ROUTINE(p, 2);
      break;
  }
}

// --------------------------------------------

static void FUN_080c843c(struct VFX* p);
static void FUN_080c8488(struct VFX* p);
static void FUN_080c8628(struct VFX* p);
static void FUN_080c8684(struct VFX* p);
static void FUN_080c8744(struct VFX* p);

// clang-format off
static const VFXFunc sUpdates[5] = {
    FUN_080c843c,
    FUN_080c8488,
    FUN_080c8628,
    FUN_080c8684,
    FUN_080c8744,
};
// clang-format on

// --------------------------------------------

// 0x0836f998
const motion_t motion_t_ARRAY_0836f998[3] = {
    MOTION(SM014_CHIPICON, 8),
    MOTION(SM014_CHIPICON, 7),
    MOTION(SM014_CHIPICON, 9),
};
