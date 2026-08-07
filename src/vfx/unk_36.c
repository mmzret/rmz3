#include "global.h"
#include "vfx.h"
#include "script.h"

struct Projectile* FUN_0809f48c(struct Entity* e, struct Coord* c);

// volteel の尻尾と電撃

static void VFX36_Init(struct Entity* p);
static void VFX36_Update(struct Entity* p);
static void VFX36_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX36Routine = {
    [ENTITY_INIT] =      (VFXFunc)VFX36_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX36_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX36_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Entity* FUN_080bc058(struct Entity* e, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_036);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = e;
  }
  return p;
}

struct Entity* volteel_080bc0b0(struct Entity* e, Coords32* c, u8 kind) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_036);
    p->work[0] = kind, p->work[1] = 1;
    p->coord.x = c->x, p->coord.y = c->y;
    p->unk_28 = e;
  }
  return p;
}

// --------------------------------------------

static void VFX36_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteTableDynamic(p);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
    (p->d).x = PIXEL(1) / 2;  // 右
  } else {
    SET_XFLIP(p, TRUE);
    (p->d).x = -PIXEL(1) / 2;  // 左
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 1, p->mode[2] = 0, p->mode[3] = 0;
  } else {
    p->work[2] = 0xFF;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  }
  VFX36_Update((void*)p);
}

void FUN_080bc200(struct Entity* p);
void FUN_080bc464(struct Entity* p);

static void VFX36_Update(struct Entity* p) {
  static const VFXFunc sUpdates[2] = {
      (VFXFunc)FUN_080bc200,
      (VFXFunc)FUN_080bc464,
  };  // 0x0836edb8
  (sUpdates[p->mode[1]])((void*)p);
}

static void VFX36_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

void FUN_080bc200(struct Entity* p) {
  struct Coord c;
  if (((struct Entity*)p->unk_28)->mode[0] > 1) {
    CreateSmoke(1, &p->coord);
    PlaySound(0x2A);
    goto die;
  }
  switch (p->mode[2]) {
    case 0: {
      u8 w0;
      *((u8*)p + 0x49) |= 0xC;
      w0 = p->work[0];
      if (w0 == 0) {
        SetMotion(p, 0xA605);
        SET_YFLIP(p, w0);
      } else if (w0 == 1) {
        SetMotion(p, 0xA602);
        SET_XFLIP(p, 0);
      } else if (w0 == 2) {
        SetMotion(p, 0xA605);
        SET_YFLIP(p, 1);
      } else {
        SetMotion(p, 0xA602);
        SET_XFLIP(p, 1);
      }
      PlaySound(0);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim(p);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    case 2: {
      motion_t m;
      p->work[2] = 0xA;
      if (p->work[0] == 0) {
        goto m606;
      }
      if (p->work[0] == 1) {
        m = 0xA603;
        goto mcall;
      }
      if (p->work[0] == 2) {
      m606:
        m = 0xA606;
      mcall:
        SetMotion(p, m);
      } else {
        SetMotion(p, 0xA603);
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3:
      UpdateEntityAnim(p);
      {
        s32 t = p->work[2];
        if (t != 0) {
          t--;
          p->work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    case 4: {
      u32 w = p->work[0];
      if (w == 0) {
        c.x = w;
        c.y = 0x2000;
      } else if (w == 1) {
        c.x = -0x2000;
        c.y = 0;
      } else if (w == 2) {
        c.x = 0;
        c.y = -0x2000;
      } else {
        c.x = 0x2000;
        c.y = 0;
      }
      c.x = p->coord.x + c.x;
      c.y = p->coord.y + c.y;
      FUN_0809f48c(p->unk_28, &c);
      PlaySound(0x7E);
      UpdateEntityAnim(p);
      p->work[2] = 0xA;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5:
      UpdateEntityAnim(p);
      {
        s32 t = p->work[2];
        if (t != 0) {
          t--;
          p->work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    case 6: {
      motion_t m;
      if (p->work[0] == 0) {
        goto m607;
      }
      if (p->work[0] == 1) {
        m = 0xA604;
        goto mcall2;
      }
      if (p->work[0] == 2) {
      m607:
        m = 0xA607;
      mcall2:
        SetMotion(p, m);
      } else {
        SetMotion(p, 0xA604);
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7:
      UpdateEntityAnim(p);
      if (p->motion.state == 3) {
      die:
        SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
  }
}

void FUN_080bc464(struct Entity* p) {
  register s32 m asm("r5");
  m = p->mode[2];
  switch (m) {
    case 0: {
      register struct Entity* q asm("r1");
      register s32 dx asm("r0");
      register s32 k asm("r2");
      SetMotion(p, MOTION(0xA5, 0x05));
      p->work[2] = 0x1E;
      if (p->d.x > 0) {
        q = p->unk_28;
        dx = (q->coord).x;
        k = 0xC00;
      } else {
        q = p->unk_28;
        dx = (q->coord).x;
        k = -0xC00;
      }
      dx += k;
      p->unk_coord.x = dx;
      p->d.y = 0x80;
      p->unk_coord.y = (q->coord).y + 0x600;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      {
        register s32 t asm("r0");
        register s32 cx asm("r1");
        t = p->unk_coord.x;
        cx = p->coord.x;
        t -= cx;
        t <<= 4;
        t >>= 8;
        cx += t;
        p->coord.x = cx;
      }
      {
        register s32 t2 asm("r0");
        register s32 cy asm("r1");
        t2 = p->unk_coord.y;
        cy = p->coord.y;
        t2 -= cy;
        t2 <<= 4;
        t2 >>= 8;
        cy += t2;
        p->coord.y = cy;
      }
      UpdateEntityAnim(p);
      if ((p->unk_28)->flags & 1) {
        p->flags |= 1;
      } else {
        p->flags &= 0xFE;
      }
      break;
    }
    case 2:
      if ((p->unk_28)->scriptEntity->flags & 0x80) {
        CreateSmoke(1, &p->coord);
        PlaySound(0x2A);
        {
          u32 tbl = (u32)gVFXFnTable;
          u32 id = (p->id) << 2;
          EntityFunc** rt = (EntityFunc**)(tbl + id);
          *(u32*)(p->mode) = m;
          p->onUpdate = (void*)((*rt)[2]);
        }
      }
      break;
  }
}
