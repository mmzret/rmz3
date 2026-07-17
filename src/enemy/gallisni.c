#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "stagerun.h"
#include "camera.h"
#include "story.h"

static const EnemyFunc sUpdates1[8];
static const EnemyFunc sUpdates2[8];
static const EnemyFunc sDeads[3];
static const struct Collision sCollisions[5];
bool8 gallisni_080870bc(struct Enemy* p);
bool8 gallisni_08087118(struct Enemy* p);
void gallisni_080871b4(struct Enemy* p);

void CreateGallisni(s32 x, s32 y, u8 a2) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_GALLISNI);
    (p->s).work[0] = 1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[2] = a2;
  }
}

INCASM("asm/enemy/gallisni_a.inc");

void Gallisni_Update(struct Enemy* p) {
  if ((p->s).work[0] == 1) {
    u8 sf = (u8)(gCurStory.s.gameflags[4] & 2);
    if (sf) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      goto despawn;
    }
    if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x8000) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      (p->body).status = sf;
      // do/while needed to match: forces sf into its home register here.
      do {
        (p->body).prevStatus = sf;
      } while (0);
      (p->body).invincibleTime = sf;
    despawn:
      (p->s).flags &= ~COLLIDABLE;
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }
  }
  if (gallisni_080870bc(p)) {
    return;
  }
  gallisni_080871b4(p);
  if (gallisni_08087118(p)) {
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

void Gallisni_Die(struct Enemy* p) {
  (sDeads[(p->s).mode[1]])(p);
}

void nop_0808737c(struct Enemy* p) {}


void FUN_08087380(struct Enemy* p) {
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 7;
    (p->s).mode[2] = 0;
  }
}


void FUN_080873a0(struct Enemy* p) {
  struct Entity** slot = (struct Entity**)((u8*)p + 0xb4);
  if (*slot == NULL || isKilled(*slot)) {
    *slot = NULL;
    SetDDP(&p->body, &sCollisions[2]);
    if (!IsFrozen(&p->s)) {
      (p->s).mode[1] = 3;
      (p->s).mode[2] = 0;
    }
  }
  if (((p->body).status & 0x00020001) == 0x00020001) {
    (p->s).mode[1] = 7;
    (p->s).mode[2] = 0;
  }
}

void FUN_080873fc(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    SetSpriteAnimation(p, MOTION(0x67, 3));
    UpdateSpriteAnimation(p);
    SetDDP(&p->body, &sCollisions[3]);
    (p->s).mode[2]++;
  }
}

void FUN_08087434(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[0]);
      (p->s).work[2] = 0x80;
      (p->s).renderPrio = 0xf;
      SetSpriteAnimation(p, MOTION(0x67, 1));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      UpdateSpriteAnimation(p);
      if ((s8)(p->s).motion.cmdIdx == 8) {
        SetDDP(&p->body, &sCollisions[1]);
      }
      break;
  }
}

void FUN_080874ac(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).work[2] = 0x18;
      SetDDP(&p->body, &sCollisions[0]);
      SetSpriteAnimation(p, MOTION(0x67, 2));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      if (p->buffer[4] != 0) p->buffer[4]--;
      if ((p->s).work[2] == 0 || --(p->s).work[2] == 0) {
        if (p->buffer[4] == 0) {
          (p->s).mode[1] = 1;
          (p->s).mode[2] = 0;
        }
      }
      UpdateSpriteAnimation(p);
      break;
  }
}

INCASM("asm/enemy/gallisni_b.inc");

void Gallisni_Init(struct Enemy* p);
void Gallisni_Update(struct Enemy* p);
void Gallisni_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGallisniRoutine = {
    [ENTITY_INIT] =      Gallisni_Init,
    [ENTITY_UPDATE] =    Gallisni_Update,
    [ENTITY_DIE] =       Gallisni_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

void FUN_080873a0(struct Enemy* p);
void nop_0808737c(struct Enemy* p);
void FUN_08087380(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_080873a0,
    nop_0808737c,
    nop_0808737c,
    FUN_08087380,
    FUN_08087380,
    FUN_08087380,
    FUN_08087380,
    nop_0808737c,
};
// clang-format on

void FUN_080873fc(struct Enemy* p);
void FUN_08087434(struct Enemy* p);
void FUN_080874ac(struct Enemy* p);
void FUN_08087518(struct Enemy* p);
void FUN_080875c8(struct Enemy* p);
void FUN_0808772c(struct Enemy* p);
void FUN_0808778c(struct Enemy* p);
void FUN_08087ab0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_080873fc,
    FUN_08087434,
    FUN_080874ac,
    FUN_08087518,
    FUN_080875c8,
    FUN_0808772c,
    FUN_0808778c,
    FUN_08087ab0,
};
// clang-format on

void FUN_080878f0(struct Enemy* p);
void FUN_08087988(struct Enemy* p);
void FUN_08087ab0(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    FUN_080878f0,
    FUN_08087988,
    FUN_08087ab0,
};

// --------------------------------------------

static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(30), PIXEL(14), PIXEL(58)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(2), PIXEL(0), PIXEL(26), PIXEL(26)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};
static const u8 sInitModes[2] = {1, 3};

static const motion_t sMotions[4] = {
    MOTION(103, 8),
    MOTION(103, 9),
    MOTION(103, 10),
    MOTION(103, 6),
};
