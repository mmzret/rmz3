#include "collision.h"
#include "global.h"
#include "solid.h"
#include "sound.h"
#include "stagerun.h"
#include "vfx.h"

/*
  旧居住区, アナトレーの森で、フレイムチップで木や蔦を燃やした際の炎のエフェクト(延焼処理に当たり判定を使うので Solid を使っているっぽい)
  ただし、Solid のスロットに余裕がないときは VFX29 を代わりに生成
*/

void FUN_0800e2c4(s32 x, s32 y);
void FUN_08010d20(s32 x, s32 y);

metatile_attr_t FUN_0800e284(s32 x, s32 y);
metatile_attr_t FUN_08010cd0(s32 x, s32 y);

static void onCollision(struct Body* body, Coords32* c1, Coords32* c2);

// --------------------------------------------

static void Solid3_Init(struct Solid* p);
static void Solid3_Update(struct Solid* p);
static void Solid3_Die(void* _ UNUSED);

// clang-format off
const SolidRoutine gBurningFlameRoutine = {
    [ENTITY_INIT] =      (void*)Solid3_Init,
    [ENTITY_UPDATE] =    (void*)Solid3_Update,
    [ENTITY_DIE] =       (void*)Solid3_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
}; // 0x0836fdc0
// clang-format on

// id: FALSE = 旧居住区, TRUE = アナトレーの森
// 作った時点では燃えてない、不可視の判定だけがあり、 onCollision で　着火を行う
struct Solid* CreateLeafBurn(u8 id) {
  struct Solid* p = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_BURNING_FLAME);
    (p->s).work[0] = id, (p->s).work[1] = 0;
  }
  return p;
}

void FUN_080cb3b8(struct Entity* e, s32 x, s32 y) {
  struct Entity* p = NULL;
  // Solid のスロットに余裕があるなら Solid で作るが、そうでないなら VFX で作る
  if (gSolidHeaderPtr->remaining >= 8) {
    p = AllocEntityLast(gSolidHeaderPtr);
    if (p != NULL) {
      INIT_SOLID_ROUTINE(p, SOLID_BURNING_FLAME);
      (p->coord).x = (x & ~(PIXEL(16) - 1)) + PIXEL(8);
      (p->coord).y = (y & ~(PIXEL(16) - 1)) + PIXEL(16);
      p->work[0] = e->work[0];
      if (e->work[1] < 0xFF) {
        p->work[1] = e->work[1] + 1;  // 延焼の連鎖数
      } else {
        p->work[1] = e->work[1];
      }
    }
  }
  if (p == NULL) {
    // 妥協召喚
    p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_BURNING_FLAME_FX);
      (p->coord).x = (x & ~(PIXEL(16) - 1)) + PIXEL(8);
      (p->coord).y = (y & ~(PIXEL(16) - 1)) + PIXEL(16);
      p->work[0] = e->work[0];
      if (e->work[1] < 0xFF) {
        p->work[1] = e->work[1] + 1;  // 延焼の連鎖数
      } else {
        p->work[1] = e->work[1];
      }
    }
  }
  if (p != NULL) {
    if (e->work[0] == 0) {
      FUN_0800e2c4(x, y);  // 旧居住区
    } else {
      FUN_08010d20(x, y);  // アナトレーの森
    }
  }
}

void FUN_080cb4c0(struct Entity* p) {
  s32 y, y2;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SetSpriteAnimation(p, MOTION(SM032_BURNING_FIRE, 0));
  (p->spr).oam.priority = 0;
  if (p->work[0] == 0) {
    y = (p->coord).y;  // 旧居住区
  } else {
    y = (p->coord).y - PIXEL(480);  // アナトレーの森
  }
  y >>= 12;
  y2 = y;
  if (y < 0) {
    y += 31;
  }
  p->renderPrio = 31 - (y2 - (y >> 5) * 32);
  p->work[2] = (p->work[1] & 3) + 5;  // lifetime
}

// 0x080cb528
// アチアチ
s16 FUN_080cb528(struct Entity* p) {
  s32 x, y;
  u8 count = 0;
  u8 ldru = 0;  // 延焼方向 (左, 下, 右, 上)
  UpdateSpriteAnimation(p);
  if (p->work[2] != 0) {
    p->work[2]--;
    return TRUE;
  }
  x = (p->coord).x;
  y = (p->coord).y - PIXEL(8);
  if (p->work[0] == 0) {
    // 旧居住区
    if (FUN_0800e284(x, y - PIXEL(16))) {
      count++;
      ldru |= (1 << 0);
    }
    if (FUN_0800e284(x + PIXEL(16), y)) {
      count++;
      ldru |= (1 << 1);
    }
    if (FUN_0800e284(x, y + PIXEL(16))) {
      count++;
      ldru |= (1 << 2);
    }
    if (FUN_0800e284(x - PIXEL(16), y)) {
      count++;
      ldru |= (1 << 3);
    }
  } else {
    // アナトレーの森
    if (FUN_08010cd0(x, y - PIXEL(16))) {
      count++;
      ldru |= (1 << 0);
    }
    if (FUN_08010cd0(x + PIXEL(16), y)) {
      count++;
      ldru |= (1 << 1);
    }
    if (FUN_08010cd0(x, y + PIXEL(16))) {
      count++;
      ldru |= (1 << 2);
    }
    if (FUN_08010cd0(x - PIXEL(16), y)) {
      count++;
      ldru |= (1 << 3);
    }
  }
  if (count == 0) {
    return FALSE;
  }
  if (gSolidHeaderPtr->remaining + gVFXHeaderPtr->remaining < ((s32)count - 1)) {
    return TRUE;
  }

  if (ldru & (1 << 0)) {
    (p->coord).y -= PIXEL(16);
    ldru ^= (1 << 0);
  } else if (ldru & (1 << 1)) {
    (p->coord).x += PIXEL(16);
    ldru ^= (1 << 1);
  } else if (ldru & (1 << 2)) {
    (p->coord).y += PIXEL(16);
    ldru ^= (1 << 2);
  } else if (ldru & (1 << 3)) {
    (p->coord).x -= PIXEL(16);
    ldru ^= (1 << 3);
  }

  if (p->work[0] == 0) {
    FUN_0800e2c4((p->coord).x, (p->coord).y - PIXEL(8));  // 旧居住区
  } else {
    FUN_08010d20((p->coord).x, (p->coord).y - PIXEL(8));  // アナトレーの森
  }
  if (ldru & (1 << 0)) FUN_080cb3b8(p, x, y - PIXEL(16));
  if (ldru & (1 << 1)) FUN_080cb3b8(p, x + PIXEL(16), y);
  if (ldru & (1 << 2)) FUN_080cb3b8(p, x, y + PIXEL(16));
  if (ldru & (1 << 3)) FUN_080cb3b8(p, x - PIXEL(16), y);
  FUN_080cb4c0(p);
  return TRUE;
}

static const struct Collision sCollision;

void Solid3_Init(struct Solid* p) {
  (p->s).flags |= FLIPABLE;
  if ((p->s).work[1] == 0) {
    INIT_BODY(p, &sCollision, 0, onCollision);
    (p->s).flags2 &= ~WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
  } else {
    FUN_080cb4c0(&p->s);
  }
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  Solid3_Update(p);
}

static void Solid3_Update(struct Solid* p) {
  if ((p->s).work[1] == 0) {  // 最初の炎
    struct Camera* cam = &gStageRun.vm.camera;
    (p->s).coord.x = (cam->viewport).x;
    (p->s).coord.y = (cam->viewport).y;
    if ((p->s).mode[1] != 0) {
      s32 x1 = (p->s).unk_coord.x;
      s32 y1 = (p->s).unk_coord.y;
      s32 x2 = (p->s).d.x;
      s32 y2 = (p->s).d.y;
      if ((p->s).work[0] == 0) {
        // 旧居住区
        if (FUN_0800e284(x1, y1)) FUN_080cb3b8(&p->s, x1, y1);
        if (FUN_0800e284(x1 + x2, y1 + y2)) FUN_080cb3b8(&p->s, x1 + x2, y1 + y2);
        if (FUN_0800e284(x1 + x2, y1 - y2)) FUN_080cb3b8(&p->s, x1 + x2, y1 - y2);
        if (FUN_0800e284(x1 - x2, y1 + y2)) FUN_080cb3b8(&p->s, x1 - x2, y1 + y2);
        if (FUN_0800e284(x1 - x2, y1 - y2)) FUN_080cb3b8(&p->s, x1 - x2, y1 - y2);
      } else {
        // アナトレーの森
        if (FUN_08010cd0(x1, y1)) FUN_080cb3b8(&p->s, x1, y1);
        if (FUN_08010cd0(x1 + x2, y1 + y2)) FUN_080cb3b8(&p->s, x1 + x2, y1 + y2);
        if (FUN_08010cd0(x1 + x2, y1 - y2)) FUN_080cb3b8(&p->s, x1 + x2, y1 - y2);
        if (FUN_08010cd0(x1 - x2, y1 + y2)) FUN_080cb3b8(&p->s, x1 - x2, y1 + y2);
        if (FUN_08010cd0(x1 - x2, y1 - y2)) FUN_080cb3b8(&p->s, x1 - x2, y1 - y2);
      }
      (p->s).mode[1] = 0;
    }
  } else {
    if (!FUN_080cb528(&p->s)) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    }
  }
}

static void Solid3_Die(void* _) {}

// 0x080cb980
static void onCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  struct Entity* p = body->parent;
  if (p->mode[1] == 0) {
    s32 x, y;
    s32 dx, dy;
    const struct Collision* collisions = (body->enemy)->processing;
    Coords32* c = (body->enemy)->coord;
    const struct Rect* range = &collisions->range;
    if ((((body->enemy)->parent)->flags & X_FLIP) == 0) {
      x = c->x + range->x;
    } else {
      x = c->x - range->x;
    }
    y = c->y + range->y;
    dx = (u16)range->w >> 1;
    dy = (u16)range->h >> 1;
    if (p->work[0] == 0) {
      // 旧居住区
      if (FUN_0800e284(x, y) || FUN_0800e284(x + dx, y + dy) || FUN_0800e284(x + dx, y - dy) || FUN_0800e284(x - dx, y + dy) || FUN_0800e284(x - dx, y - dy)) {
        (p->unk_coord).x = x, (p->unk_coord).y = y;
        (p->d).x = dx, (p->d).y = dy;
        if (!isSoundPlaying(SE_FLAME)) PlaySound(SE_FLAME);
        p->mode[1] = 1;
      }
    } else {
      // アナトレーの森
      if (FUN_08010cd0(x, y) || FUN_08010cd0(x + dx, y + dy) || FUN_08010cd0(x + dx, y - dy) || FUN_08010cd0(x - dx, y + dy) || FUN_08010cd0(x - dx, y - dy)) {
        (p->unk_coord).x = x, (p->unk_coord).y = y;
        (p->d).x = dx, (p->d).y = dy;
        if (!isSoundPlaying(SE_FLAME)) PlaySound(SE_FLAME);
        p->mode[1] = 1;
      }
    }
    (body->status) &= ~BODY_STATUS_WHITE;
  }
}

// --------------------------------------------

// 0x0836fdd4
static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  damage : 0,
  LAYER(0x442108),
  hitzone : 0xFF,
  remaining : 0,
  range : {PIXEL(0), PIXEL(0), -PIXEL(1), -PIXEL(1)},
};
