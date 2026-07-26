#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "entity/macros.h"
#include "motion.h"
#include "story.h"
#include "physics.h"
#include "metatile.h"
#include "sound.h"
#include "constants/song.h"
#include "constants/entity/enemy.h"
#include "projectile.h"
#include "vfx.h"
#include "definition.h"
#include "zero.h"
#include "syssav.h"
#include "element.h"
#include "stagerun.h"
#include "entity.h"
#include "gba/syscall.h"
#include "score.h"

bool8 FUN_08095d80(struct Enemy* p);
bool8 FUN_08095dc8(struct Enemy* p);
u8 FUN_08095e28(struct Enemy* p);
void Shellcrawler_Init(struct Enemy* p);
void Shellcrawler_Update(struct Enemy* p);
void Shellcrawler_Die(struct Enemy* p);
void FUN_08096348(struct Body* body, struct Coord* c1, struct Coord* c2);
void FUN_08096438(struct Enemy* p);
void FUN_08096468(struct Enemy* p);
void FUN_08096484(struct Enemy* p);
void FUN_080964bc(struct Enemy* p);
void FUN_080964c0(struct Enemy* p);
void FUN_08096570(struct Enemy* p);
void FUN_0809660c(struct Enemy* p);
void FUN_0809664c(struct Enemy* p);
void FUN_080966fc(struct Enemy* p);
void FUN_0809678c(struct Enemy* p);
void FUN_08096814(struct Enemy* p);
void FUN_08096950(struct Enemy* p);
void FUN_080969d0(struct Enemy* p);
void FUN_08096a90(struct Enemy* p);
void FUN_08096b84(struct Enemy* p);
void FUN_08096c28(struct Enemy* p);
void FUN_08096d84(struct Enemy* p);
void FUN_08096eac(struct Enemy* p);


extern const struct Coord Coord_080ff05c;
static const EnemyFunc sUpdates1[11];
static const EnemyFunc sUpdates2[11];
static const EnemyFunc sDeads[4];
static const struct Collision sCollisions[16];


void FUN_080b145c(struct Coord* c, s32 dx);
struct Entity* FUN_080b2b40(u8 kind, struct Coord* c, u16 r2, bool16 isDirRight);
struct VFX* FUN_080c6880(struct Entity* e);
void FUN_080c68cc(struct Entity* e, struct Coord* c);
void FUN_080c6934(struct Entity* e, u8 n);
bool8 FUN_08095d80(struct Enemy* p) {
  bool8 r = FALSE;
  s32 t;

  t = FUN_08009f6c((p->s).coord.x + 0xA00, (p->s).coord.y);
  if (t - (p->s).coord.y <= 0x43F) {
    r = TRUE;
  }
  t = FUN_08009f6c((p->s).coord.x - 0xA00, (p->s).coord.y);
  if (t - (p->s).coord.y <= 0x43F) {
    r = TRUE;
  }
  return r;
}

bool8 FUN_08095dc8(struct Enemy* p) {
  bool8 r = FALSE;
  s32 a = PushoutToUp1((p->s).coord.x + 0xA00, (p->s).coord.y);
  s32 b = FUN_08009f6c((p->s).coord.x - 0xA00, (p->s).coord.y);

  if (a < b) {
    if (a < 0 && a > -0x400) {
      (p->s).coord.y += a;
      r = TRUE;
    }
  } else {
    if (b < 0 && b > -0x400) {
      (p->s).coord.y += b;
      r = TRUE;
    }
  }
  return r;
}

u8 FUN_08095e28(struct Enemy* p) {
  s32 v;
  s32 dir;
  s32 dx;
  s32 push;

  v = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  if (v - (p->s).coord.y <= 0x43F) {
    (p->s).coord.y = v;
  }

  dir = 0;
  if ((p->s).d.x > 0) {
    dir = 1;
  }
  dx = dir * PIXEL(20) - PIXEL(10);
  v = (p->s).coord.y - PIXEL(8);

  if (dir != 0) {
    push = PushoutToLeft1((p->s).coord.x + dx, v);
    if (push < 0) {
      (p->s).coord.x += push;
      return 1;
    }
  } else {
    push = PushoutToRight1((p->s).coord.x + dx, v);
    if (push > 0) {
      (p->s).coord.x += push;
      return 1;
    }
  }

  v += PIXEL(16);
  if (FUN_080098a4((p->s).coord.x + dx, v) == 0) {
    return 2;
  }
  return 0;
}

void Shellcrawler_Init(struct Enemy* p) {
  u8 f;

  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  if ((p->s).work[0] == 4) {
    (p->s).mode[1] = 9;
    (p->s).flags |= FLIPABLE;
    INIT_BODY(p, &sCollisions[6], 1, FUN_08096348);
  } else {
    (p->s).mode[1] = 0;
    (p->s).flags |= FLIPABLE;
    InitNonAffineMotion(&p->s);
    (p->s).flags |= DISPLAY;
    if ((gSystemSavedata.flags[19] & 0x10) && (f = gCurStory.s.gameflags[0] & 0x40) == 0) {
      INIT_BODY(p, sCollisions, 0x10, NULL);
    } else {
      INIT_BODY(p, sCollisions, 0xc, NULL);
    }
    SET_BODY_INTERSECT_HANDLER(p, FUN_08096348);
    SetMotion(&p->s, MOTION(0xdb, 1));
    (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
    if ((p->s).work[0] == 0) {
      SET_XFLIP(p, (pZero2->s).coord.x - (p->s).coord.x > 0);
    } else if ((p->s).work[0] == 2) {
      SET_XFLIP(p, FALSE);
    } else {
      SET_XFLIP(p, TRUE);
    }
    (p->s).work[0] = 0;
    p->buffer[8] = 0;
    *(u32*)&p->buffer[4] = 0;
  }
  Shellcrawler_Update(p);
}

void Shellcrawler_Update(struct Enemy* p) {
  struct Coord c = Coord_080ff05c;
  u32 st;
  u8 n;
  u8 m;
  s32 t;

  st = (p->body).status & 0x200;
  if (st != 0) {
    if ((p->s).work[0] == 4) {
      goto handlers;
    }
    m = (p->s).mode[1];
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if (((p->body).status & 0x18000) == 0x10000) {
      (p->s).mode[1] = 1;
    } else if ((p->body).status & 0x20000) {
      (p->s).mode[1] = 3;
    } else {
      (p->s).mode[1] = (p->body).status & 0x20000;
    }
    (p->s).mode[3] = m;
    Shellcrawler_Die(p);
    return;
  }
  if ((p->s).work[0] == 4) {
    goto handlers;
  }
  if (CalcFromCamera(&gStageRun.vm.camera, &(p->s).coord) > 0x8000) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = st;
    (p->body).prevStatus = st;
    (p->body).invincibleTime = st;
    (p->s).flags &= ~COLLIDABLE;
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if ((*(struct Entity**)((u8*)p + 0xb8)) == NULL && ((p->body).status & 1)) {
    if ((p->s).mode[1] == 0xa) {
      goto check;
    }
    (*(struct Entity**)((u8*)p + 0xb8)) = ApplyElementEffect(0, (struct CollisionObject*)p, &c);
    if ((*(struct Entity**)((u8*)p + 0xb8)) != NULL) {
      if ((p->s).work[0] == 0) {
        SetDDP(&p->body, &sCollisions[4]);
      } else {
        SetDDP(&p->body, &sCollisions[12]);
      }
      (p->s).unk_coord.y = (p->s).d.y;
      (p->s).d.y = 0;
    }
  }
  if ((p->s).mode[1] == 0xa) {
    goto check;
  }
  if ((*(struct Entity**)((u8*)p + 0xb8)) != NULL) {
    goto check2;
  }
  n = (p->s).mode[3];
  if (n == 0) {
    if (IsFrozen(&p->s)) {
      (p->s).mode[3] = 1;
    }
    n = (p->s).mode[3];
    if (n == 0) {
      goto check;
    }
  }
  if (n == 1) {
    UpdateEntityAnim(&p->s);
    (p->s).mode[3] = 2;
  }
  if (!IsFrozen(&p->s)) {
    (p->s).mode[3] = 0;
  }
  if (((p->body).status & 0x00020001) != 0x00020001) {
    return;
  }
check:
  if ((*(struct Entity**)((u8*)p + 0xb8)) == NULL) {
    goto handlers;
  }
check2:
  if ((p->s).mode[1] != 0xa) {
    goto rest;
  }
handlers:
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
  return;
rest:
  if (isKilled((struct Entity*)(*(struct Entity**)((u8*)p + 0xb8)))) {
    if ((p->s).work[0] == 0) {
      SetDDP(&p->body, sCollisions);
    } else {
      SetDDP(&p->body, &sCollisions[2]);
    }
    (*(struct Entity**)((u8*)p + 0xb8)) = NULL;
    (p->s).d.y = (p->s).unk_coord.y;
  } else if (!IsFrozen(&p->s)) {
    if (PushoutToUp1((p->s).coord.x - 0xA00, (p->s).coord.y) >= 0 &&
        PushoutToUp1((p->s).coord.x + 0xA00, (p->s).coord.y) >= 0) {
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      t = PushoutToUp1((p->s).coord.x - 0x800, (p->s).coord.y);
      if (t < 0) {
        (p->s).coord.y += t;
      }
      t = PushoutToUp1((p->s).coord.x + 0x800, (p->s).coord.y);
      if (t < 0) {
        (p->s).coord.y += t;
      }
    }
  }
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 0xa;
    (p->s).mode[2] = 0;
  }
}

void Shellcrawler_Die(struct Enemy* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sDeads[(p->s).mode[1]])(p);
}

void FUN_08096348(struct Body* body, struct Coord* c1, struct Coord* c2) {
  struct Enemy* p = (struct Enemy*)body->parent;
  struct Enemy* c;
  u8 m;
  u8 n;

  *(s32*)&p->buffer[0] = (pZero2->s).coord.x - (p->s).coord.x;
  if ((body->hitboxFlags & 1) == 0) {
    return;
  }
  if ((p->s).work[0] == 4) {
    p = (struct Enemy*)(p->s).unk_28;
  } else {
    m = (p->s).mode[1];
    if (m == 3 || m == 4 || m == 8) {
      return;
    }
  }
  if (p->buffer[8] != 0) {
    return;
  }
  p->buffer[8] = 1;
  if ((p->s).work[0] != 4 && (p->s).unk_2c != NULL) {
    c = NULL;
    (p->s).unk_2c = (struct Entity*)c;
    (c->s).flags &= ~DISPLAY;
    (c->s).flags &= ~FLIPABLE;
    EXIT_BODY(c);
    SET_ENEMY_ROUTINE(c, ENTITY_DISAPPEAR);
  }
  (p->s).work[0] = 1;
  (p->s).mode[1] = 7;
  (p->s).mode[2] = 0;
  SetMotion(&p->s, MOTION(0xdb, 8));
  UpdateEntityAnim(&p->s);
  if (*(u32*)&p->buffer[4] == 0) {
    SetDDP(&p->body, &sCollisions[2]);
  } else {
    SetDDP(&p->body, &sCollisions[12]);
  }
  n = 0;
  if (*(s32*)&p->buffer[0] > 0) {
    n = 1;
  }
  FUN_080c6934(&p->s, n);
}

void FUN_08096438(struct Enemy* p) {
  if (FUN_08095d80(p) == 0) {
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  } else if (*(u32*)((u8*)p + 0x8c) & 1) {
    (p->s).mode[1] = 5;
    (p->s).mode[2] = 0;
  }
}

void FUN_08096468(struct Enemy* p) {
  if (FUN_08095d80(p) == 0) {
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  }
}

void FUN_08096484(struct Enemy* p) {
  if (FUN_08095d80(p) == 0) {
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  }
  if ((*(u32*)((u8*)p + 0x8c) & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 0xa;
    (p->s).mode[2] = 0;
  }
}

void FUN_080964bc(struct Enemy* p) {}

void FUN_080964c0(struct Enemy* p) {
  s32 v;

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).work[2] = 0x60;
      (p->s).d.x = -0x40;
      v = -0x40;
      if ((p->s).flags & X_FLIP) {
        v = 0x40;
      }
      (p->s).d.x = v;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      v = (p->s).d.x < 0;
      if ((((p->s).flags & X_FLIP) && v == 0) || (((p->s).flags & X_FLIP) == 0 && v != 0)) {
        SetMotion(&p->s, MOTION(0xdb, 0));
      } else {
        SetMotion(&p->s, MOTION(0xdb, 2));
      }
      (p->s).mode[2]++;
      // fallthrough
    case 2:
      if (--(p->s).work[2] == 0) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
        break;
      }
      (p->s).coord.x += (p->s).d.x;
      if (FUN_08095e28(p)) {
        (p->s).d.x = -(p->s).d.x;
        (p->s).mode[2] = 1;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_08096570(struct Enemy* p) {
  u8 m;

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).d.y = 0;
      if ((p->s).work[0] == 0) {
        if ((p->s).d.x < 0) {
          SetMotion(&p->s, MOTION(0xdb, 0));
        } else {
          SetMotion(&p->s, MOTION(0xdb, 2));
        }
      } else {
        if ((p->s).d.x < 0) {
          SetMotion(&p->s, MOTION(0xdb, 0x0f));
        } else {
          SetMotion(&p->s, MOTION(0xdb, 5));
        }
      }
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.x += (p->s).d.x;
      FUN_08095e28(p);
      if (FUN_08095dc8(p)) {
        m = (p->s).work[0];
        if (m != 0) {
          m = 6;
        }
        (p->s).mode[1] = m;
        (p->s).mode[2] = 1;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_0809660c(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0xdb, 3));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state == 3) {
        (p->s).mode[1] = (p->s).motion.state;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_0809664c(struct Enemy* p) {
  struct Entity* e;

  switch ((p->s).mode[2]) {
    case 0:
      e = AllocEntityFirst(gEnemyHeaderPtr);
      if (e != NULL) {
        INIT_ENEMY_ROUTINE(e, ENEMY_SHELLCRAWLER);
        e->work[0] = 4;
        e->unk_28 = &p->s;
      }
      (p->s).unk_2c = e;
      SetDDP(&p->body, &sCollisions[8]);
      SetMotion(&p->s, MOTION(0xdb, 0x0e));
      (p->s).work[2] = 0x1e;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      if (--(p->s).work[2] == 0xf) {
        PlaySound(SE_SHELL_CRAWLER);
      }
      if ((p->s).work[2] == 0) {
        (p->s).mode[1] = 8;
        (p->s).mode[2] = 0;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_080966fc(struct Enemy* p) {
  struct Enemy* c;
  u8 state;

  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0xdb, 0x10));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim(&p->s);
      state = (p->s).motion.state;
      if (state != 3) {
        break;
      }
      SetDDP(&p->body, sCollisions);
      c = (struct Enemy*)(p->s).unk_2c;
      if (c != NULL) {
        (c->s).flags &= ~DISPLAY;
        (c->s).flags &= ~FLIPABLE;
        EXIT_BODY(c);
        SET_ENEMY_ROUTINE(c, ENTITY_DISAPPEAR);
        (p->s).unk_2c = NULL;
      }
      (p->s).mode[1] = 0;
      (p->s).mode[2] = 1;
      (p->s).work[2] = 0x60;
      break;
  }
}

void FUN_0809678c(struct Enemy* p) {
  s32 v;
  u8 m;

  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0xdb, 1));
      (p->s).unk_coord.x = (p->s).d.x;
      (p->s).d.x = 0x100;
      v = 0x100;
      if (*(s32*)&p->buffer[0] > 0) {
        v = -0x100;
      }
      (p->s).d.x = v;
      (p->s).work[3] = 2;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.x += (p->s).d.x;
      FUN_08095e28(p);
      if ((p->s).work[2] > 1) {
        (p->s).work[2]--;
      }
      if (--(p->s).work[3] == 0) {
        (p->s).d.x = (p->s).unk_coord.x;
        m = (p->s).work[0];
        if (m != 0) {
          m = 6;
        }
        (p->s).mode[1] = m;
        (p->s).mode[2] = 1;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_08096814(struct Enemy* p) {
  struct Coord c;
  s32 v;
  s32 a;
  s32 dir;
  s32 x;
  u8 flip;

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).work[2] = 0x3c;
      (p->s).work[3] = 6;
      p->buffer[9] = 0;
      flip = (p->s).flags & X_FLIP;
      v = 1;
      if (flip) {
        v = -1;
      }
      (p->s).d.x = v;
      (p->s).unk_coord.x = 0x10;
      v = 0x10;
      if (flip) {
        v = -0x10;
      }
      (p->s).unk_coord.x = v;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      if ((p->s).d.x < 0) {
        SetMotion(&p->s, MOTION(0xdb, 0x0f));
      } else {
        SetMotion(&p->s, MOTION(0xdb, 5));
      }
      (p->s).mode[2]++;
      // fallthrough
    case 2:
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
      } else if (--(p->s).work[3] == 0) {
        (p->s).work[3] = 6;
        p->buffer[9]++;
        if (p->buffer[9] == 3) {
          p->buffer[9] = 0;
          (p->s).work[2] = 0x3c;
        }
        dir = ((p->s).flags >> 4) & 1;
        x = (p->s).coord.x - PIXEL(12);
        c.x = dir * PIXEL(24) + x;
        c.y = (p->s).coord.y - PIXEL(10);
        PlaySound(SE_ENEMY_SHOT);
        CreateLemon(&c, -PIXEL(3), dir * 0x80 - 0x80);
      }
      (p->s).coord.x += (p->s).d.x;
      a = (p->s).d.x;
      if (a < 0) {
        a = -a;
      }
      if (a <= 0x13F) {
        (p->s).d.x += (p->s).unk_coord.x;
      }
      if (FUN_08095e28(p)) {
        (p->s).d.x = -(p->s).d.x;
        (p->s).mode[2] = 1;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_08096950(struct Enemy* p) {
  s32 v;

  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0xdb, 8));
      (p->s).unk_coord.x = (p->s).d.x;
      (p->s).d.x = 0x100;
      v = 0x100;
      if (*(s32*)&p->buffer[0] > 0) {
        v = -0x100;
      }
      (p->s).d.x = v;
      (p->s).work[3] = 2;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.x += (p->s).d.x;
      FUN_08095e28(p);
      if ((p->s).work[2] > 1) {
        (p->s).work[2]--;
      }
      if (--(p->s).work[3] == 0) {
        (p->s).d.x = (p->s).unk_coord.x;
        (p->s).mode[1] = 6;
        (p->s).mode[2] = 0;
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_080969d0(struct Enemy* p) {
  struct Coord c;
  s32 dir;
  s32 x;

  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0xdb, 4));
      (p->s).work[2] = 8;
      (p->s).mode[2]++;
      UpdateEntityAnim(&p->s);
      // fallthrough
    case 1:
      if (--(p->s).work[2] == 0) {
        (p->s).mode[2]++;
      }
      break;
    case 2:
      (p->s).work[2] = 0;
      (p->s).mode[2]++;
      // fallthrough
    case 3:
      if ((p->s).work[2] == 2) {
        dir = ((p->s).flags >> 4) & 1;
        x = (p->s).coord.x - PIXEL(16);
        c.x = dir * PIXEL(32) + x;
        c.y = (p->s).coord.y - PIXEL(10);
        FUN_080b145c(&c, dir * PIXEL(6) - PIXEL(3));
      }
      (p->s).work[2]++;
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state == 3) {
        (p->s).mode[1] = 4;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_08096a90(struct Enemy* p) {
  struct Enemy* q = (struct Enemy*)(p->s).unk_28;
  u8 f = gCurStory.s.gameflags[4] & 0x40;

  if (f) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((q->s).mode[0] > 1) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
  }

  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, sCollisions);
      (p->s).flags &= ~DISPLAY;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      if (*(u32*)&q->buffer[4] == 0) {
        SetDDP(&p->body, sCollisions);
      } else {
        SetDDP(&p->body, &sCollisions[14]);
      }
      (p->s).coord.x = (q->s).coord.x;
      (p->s).coord.y = (q->s).coord.y;
      break;
  }
}

void FUN_08096b84(struct Enemy* p) {
  struct Coord c;
  struct Coord* pc;

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags &= ~DISPLAY;
      EXIT_BODY(p);
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y - PIXEL(8);
      CreateSmoke(1, &c);
      FUN_080c68cc(&p->s, &c);
      PlaySound(SE_ZAKO_EXPLODE);
      pc = &(p->s).coord;
      TryDropItem(2, pc);
      if (gScore.enemyCount <= 0x270E) {
        gScore.enemyCount++;
      }
      TryDropZakoDisk(&p->s, pc);
      SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      break;
  }
}

void FUN_08096c28(struct Enemy* p) {
  struct Coord c;
  struct Coord* pc;
  u16 dir;
  u8 n;

  switch ((p->s).mode[2]) {
    case 0:
      if (p->buffer[8] == 0) {
        p->buffer[8] = 1;
        n = 0;
        if (*(s32*)&p->buffer[0] > 0) {
          n = 1;
        }
        FUN_080c6934(&p->s, n);
      }
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y - PIXEL(8);
      dir = 0;
      if (*(s32*)&p->buffer[0] > 0) {
        dir = 1;
      }
      FUN_080b2b40(0, &c, 0x200, dir);
      SetMotion(&p->s, MOTION(0xdb, 9));
      (p->s).d.x = 0x200 - dir * 0x400;
      (p->s).work[2] = 0x14;
      EXIT_BODY(p);
      FUN_080c6880(&p->s);
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.x += (p->s).d.x;
      (p->s).d.x = (p->s).d.x * 240 / 256;
      FUN_08095e28(p);
      if (--(p->s).work[2] == 0) {
        (p->s).flags &= ~DISPLAY;
        c.x = (p->s).coord.x;
        c.y = (p->s).coord.y - PIXEL(8);
        CreateSmoke(1, &c);
        PlaySound(SE_ZAKO_EXPLODE);
        pc = &(p->s).coord;
        TryDropItem(2, pc);
        if (gScore.enemyCount <= 0x270E) {
          gScore.enemyCount++;
        }
        TryDropZakoDisk(&p->s, pc);
        (p->s).mode[2]++;
      }
      UpdateEntityAnim(&p->s);
      break;
    case 2:
      (p->s).flags &= ~DISPLAY;
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
      } else {
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      }
      break;
  }
}

void FUN_08096d84(struct Enemy* p) {
  struct Coord c;
  struct Coord* pc;
  s32 dir;

  switch ((p->s).mode[2]) {
    case 0:
      EXIT_BODY(p);
      dir = 0;
      if (*(s32*)&p->buffer[0] > 0) {
        dir = 1;
      }
      (p->s).d.x = 0x280 - dir * 0x500;
      (p->s).d.y = -0x480;
      (p->s).work[2] = 0x14;
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      UpdateEntityAnim(&p->s);
      if (--(p->s).work[2] == 0 || FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0) {
        c.x = (p->s).coord.x;
        c.y = (p->s).coord.y + PIXEL(1);
        CreateSmoke(1, &c);
        FUN_080c68cc(&p->s, &c);
        PlaySound(SE_ZAKO_EXPLODE);
        pc = &(p->s).coord;
        TryDropItem(2, pc);
        if (gScore.enemyCount <= 0x270E) {
          gScore.enemyCount++;
        }
        TryDropZakoDisk(&p->s, pc);
        (p->s).mode[2]++;
      }
      break;
    case 2:
      (p->s).flags &= ~DISPLAY;
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
      } else {
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
      }
      break;
  }
}

void FUN_08096eac(struct Enemy* p) {
  struct Zero* z;
  s32 dist;
  s32 t;
  s32 dy;

  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[10]);
      if ((p->s).work[0] == 0) {
        SetMotion(&p->s, MOTION(0xdb, 4));
      } else {
        SetMotion(&p->s, MOTION(0xdb, 0x0f));
      }
      UpdateEntityAnim(&p->s);
      z = pZero2;
      (p->s).d.x = (p->s).coord.x - (z->s).coord.x;
      dy = (p->s).coord.y - 0x1800;
      (p->s).d.y = dy - (z->s).coord.y;
      dist = ((p->s).d.x >> 8) * ((p->s).d.x >> 8);
      dist += ((p->s).d.y >> 8) * ((p->s).d.y >> 8);
      dist = Sqrt(dist) << 8;
      if (dist != 0) {
        (p->s).d.x = ((p->s).d.x << 8) / dist;
        t = ((p->s).d.y << 8) / dist;
        (p->s).d.x = (p->s).d.x * 6;
        (p->s).d.y = t * 6;
      } else {
        (p->s).d.x = 0x600;
        (p->s).d.y = dist;
      }
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.x += (p->s).d.x;
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      if (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0 || (p->body).status & BODY_STATUS_B2) {
        FUN_08096b84(p);
      }
      break;
  }
}


// clang-format off
const EnemyRoutine gShellcrawlerRoutine = {
    [ENTITY_INIT] =      Shellcrawler_Init,
    [ENTITY_UPDATE] =    Shellcrawler_Update,
    [ENTITY_DIE] =       Shellcrawler_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollisions[16] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 1,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(10), -PIXEL(8), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      priorityLayer : 0xFFFFFFDF,
      range : {PIXEL(0), -PIXEL(10), PIXEL(20), PIXEL(20)},
    },
};


// clang-format off
static const EnemyFunc sUpdates1[11] = {
    FUN_08096438,
    FUN_080964bc,
    FUN_08096468,
    FUN_08096484,
    FUN_08096484,
    FUN_08096468,
    FUN_08096484,
    FUN_08096484,
    FUN_08096484,
    FUN_080964bc,
    FUN_080964bc,
};
// clang-format on


// clang-format off
static const EnemyFunc sUpdates2[11] = {
    FUN_080964c0,
    FUN_08096570,
    FUN_0809660c,
    FUN_0809664c,
    FUN_080966fc,
    FUN_0809678c,
    FUN_08096814,
    FUN_08096950,
    FUN_080969d0,
    FUN_08096a90,
    FUN_08096eac,
};
// clang-format on


static const EnemyFunc sDeads[4] = {
    FUN_08096b84,
    FUN_08096c28,
    FUN_08096d84,
    FUN_08096eac,
};
