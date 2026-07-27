#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

static const struct Collision sCollisions[6];
static const EnemyFunc sUpdates[8];

void FUN_08086e34(struct Enemy* p);

void HanumachineObj_Die(struct Enemy* p);

void HanumachineObj_Update(struct Enemy* p);

void FUN_080866a4(struct Entity* e, u8 mode, u8 xflip) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HANUMACHINE_OBJ);
    (p->s).unk_28 = e;
    SET_XFLIP(&p->s, xflip);
    (p->s).work[0] = mode;
    (p->s).work[1] = 0;
  }
}

INCASM("asm/enemy/hanumachine_obj_a.inc");

void HanumachineObj_Update(struct Enemy* p) {
  struct Coord c1;
  struct Coord c2;
  u16* timer = (u16*)((u8*)p + 0xc0);
  s32 t;
  if (*timer == 0) {
    c1.x = (p->s).coord.x;
    c1.y = (p->s).coord.y - 0x800;
    PlaySound(0x2a);
    CreateSmoke(1, &c1);
    if (*(u8*)((u8*)p + 0xbd) != 0) {
      SetDDP(&p->body, &sCollisions[5]);
    } else {
      SetDDP(&p->body, &sCollisions[3]);
    }
    goto die;
  }
  if ((p->s).mode[1] != 7) {
    if (((p->body).status & 0x00020001) == 0x00020001) {
      (p->s).mode[1] = 7;
      (p->s).mode[2] = 0;
    }
    if ((p->s).mode[1] != 7) {
      goto cont;
    }
  }
  FUN_08086e34(p);
  return;

cont:
  if ((p->body).status & BODY_STATUS_DEAD) {
    c2.x = (p->s).coord.x;
    c2.y = (p->s).coord.y - 0x800;
    PlaySound(0x2a);
    CreateSmoke(1, &c2);
  die:
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    HanumachineObj_Die(p);
    return;
  }
  (sUpdates[(p->s).mode[1]])((void*)p);
  t = *timer - 1;
  *timer = t;
  if ((u16)t > 0x3b) {
    return;
  }
  if ((t & 3U) <= 1) {
    PaintEntityWhite(&p->s);
  } else {
    UpdateEntityPaletteID(&p->s);
  }
}

void HanumachineObj_Die(struct Enemy* p) {
  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/enemy/hanumachine_obj_b.inc");

void HanumachineObj_Init(struct Enemy* p);
void HanumachineObj_Update(struct Enemy* p);
void HanumachineObj_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHanumachineObjRoutine = {
    [ENTITY_INIT] =      (void*)HanumachineObj_Init,
    [ENTITY_UPDATE] =    (void*)HanumachineObj_Update,
    [ENTITY_DIE] =       (void*)HanumachineObj_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_0808693c(struct Enemy* p);
void FUN_080869a0(struct Enemy* p);
void FUN_080869f4(struct Enemy* p);
void FUN_08086a50(struct Enemy* p);
void FUN_08086b6c(struct Enemy* p);
void FUN_08086cbc(struct Enemy* p);
void FUN_08086dcc(struct Enemy* p);
void FUN_08086e34(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates[8] = {
    FUN_0808693c,
    FUN_080869a0,
    FUN_080869f4,
    FUN_08086a50,
    FUN_08086b6c,
    FUN_08086cbc,
    FUN_08086dcc,
    FUN_08086e34,
};
// clang-format on

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(26), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(8), PIXEL(26), PIXEL(28)},
    },
};
