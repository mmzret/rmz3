#include "enemy.h"
#include "global.h"

static void HanumachineNecro_Init(struct Enemy* p);
static void HanumachineNecro_Update(struct Enemy* p);
static void HanumachineNecro_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHanumachineNecroRoutine = {
    [ENTITY_INIT] =      HanumachineNecro_Init,
    [ENTITY_UPDATE] =    HanumachineNecro_Update,
    [ENTITY_DIE] =       HanumachineNecro_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

struct Enemy* CreateEnemy50(struct Boss* hanu) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    bool8 xflip;

    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_HANUMACHINE_NECRO);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = (hanu->s).coord;
    (p->s).unk_28 = &hanu->s;
    xflip = (((hanu->s).flags >> 4) & 1) != 0;
    if (xflip) {
      (p->s).flags |= X_FLIP;
    } else {
      (p->s).flags &= ~X_FLIP;
    }
    {
      register bool8 tmp asm("r1") = xflip;
      (p->s).spr.oam.xflip = (p->s).spr.xflip = tmp;
      (p->s).work[0] = 0;
      (p->s).work[1] = 0;
    }
    return p;
  } else {
    return NULL;
  }
}

// --------------------------------------------

static void HanumachineNecro_Init(struct Enemy* p) {
  struct Boss* hanu;

  hanu = (struct Boss*)(p->s).unk_28;
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, MOTION(DM181_HANUMACHINE, 4));
  (p->s).flags2 |= WHITE_PAINTABLE;
  (p->s).invincibleID = (hanu->s).uniqueID;
  if ((p->s).flags & X_FLIP) {
    (p->s).d.x = -(PIXEL(1) / 4);
    (p->s).unk_coord.x = 1;
  } else {
    (p->s).d.x = PIXEL(1) / 4;
    (p->s).unk_coord.x = -1;
  }
  (p->s).work[2] = 0;
  SET_ZAKO_ROUTINE(p, ENTITY_UPDATE);
  HanumachineNecro_Update(p);
}

static void HanumachineNecro_Update(struct Enemy* p) {
  struct Entity* hanu;
  UpdateMotionGraphic(&p->s);
  if ((p->s).mode[3] == 0) {
    u8 frame;
    (p->s).coord.x += (p->s).d.x;
    (p->s).d.x += (p->s).unk_coord.x;
    frame = (p->s).work[2]++;
    if (frame > 64) {
      (p->s).mode[3]++;
      (p->s).work[2] = 0;
    }
    return;
  }

  hanu = (struct Entity*)(p->s).unk_28;
  if (hanu->mode[1] > 2) {
    SET_ZAKO_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

static void HanumachineNecro_Die(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  SET_ZAKO_ROUTINE(p, ENTITY_EXIT);
}
