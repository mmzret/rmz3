#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "story.h"
#include "zero.h"

struct PhantomTeleporterObject {
  OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  void* player;           // 0xB4
  Coords32* destination;  // 0xB8
  u8 unk_bc[8];
};
static_assert(sizeof(struct PhantomTeleporterObject) == sizeof(struct Solid));

static const u16 u16_ARRAY_08371064[10];
static const struct Collision sCollisions[2];

Coords32* GetWarpDestination1(Coords32* c);

static void PhantomTeleporter_Init(struct Solid* p);
static void PhantomTeleporter_Update(struct Entity* p);
static void PhantomTeleporter_Die(struct Solid* p);

// clang-format off
const SolidRoutine gPhantomTeleporterRoutine = {
    [ENTITY_INIT] =      (void*)PhantomTeleporter_Init,
    [ENTITY_UPDATE] =    (void*)PhantomTeleporter_Update,
    [ENTITY_DIE] =       (void*)PhantomTeleporter_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void PhantomTeleporter_Init(struct Solid* p) {
  if (((p->s).work[0] == 8) && (!FLAG(gCurStory.s.gameflags, IN_CYBERSPACE))) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  EnableSpriteAnimation_Normal(p);
  (p->s).spr.oam.priority = 1;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + PIXEL(1);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0, (p->s).mode[2] = (p->s).mode[3] = 0;
  PhantomTeleporter_Update((void*)p);
}

static void updatePhantomTeleporter(struct PhantomTeleporterObject* p);

static void PhantomTeleporter_Update(struct Entity* p) {
  static const EntityFunc sUpdates[1] = {
      (void*)updatePhantomTeleporter,
  };
  (sUpdates[p->mode[1]])(p);
}

static void PhantomTeleporter_Die(struct Solid* p) {
  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// 0x080d87c8
static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  struct PhantomTeleporterObject* p = (struct PhantomTeleporterObject*)body->parent;
  struct Entity* q = (struct Entity*)(body->enemy)->parent;
  if (q->kind == ENTITY_PLAYER) {
    p->player = q;
  }
}

// 0x080d87e4
static void updatePhantomTeleporter(struct PhantomTeleporterObject* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      if (!FLAG(gCurStory.s.gameflags, u16_ARRAY_08371064[(p->s).work[0]])) {
        SetSpriteAnimation(p, MOTION(SM123_TELEPORTAL, 1));
        INIT_BODY(p, sCollisions, 0, onCollision);
        p->player = NULL;
      } else {
        SetSpriteAnimation(p, MOTION(SM123_TELEPORTAL, 0));
        EXIT_BODY(p);
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (gInTransport || (gStageRun.vm.unk_004 & 1)) {
        if ((p->body).status & BODY_STATUS_TELEPORTAL) {
          if (p->player != NULL) {
            gStageRun.vm.unk_004 |= (1 << 1);
            (p->s).work[2] = 30;
            (p->s).mode[2]++;
          }
        }
      }
      break;
    }
    case 2: {
      UpdateSpriteAnimation(p);
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        break;
      }
      PlaySound(SE_TELEPORT);
      SetSpriteAnimation(p, MOTION(SM123_TELEPORTAL, 2));
      (p->s).work[2] = 20;
      (p->s).mode[2]++;
      break;
    }
    case 3: {
      register Coords32* dest asm("r1");
      UpdateSpriteAnimation(p);
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        break;
      }
      Camera_SetMode(&gStageRun.vm.camera, CM1);
      dest = GetWarpDestination1(&(p->s).coord);
      p->destination = dest;
      if (dest != NULL) {
        (pZero2->s).coord.x = (p->destination)->x;
        (pZero2->s).coord.y = (p->destination)->y;
        resetSateliteElfPosition(pZero2);
      }
      (pZero2->s).spr.xflip = TRUE, (pZero2->s).spr.oam.xflip = TRUE;
      (pZero2->s).flags |= X_FLIP;
      (p->s).work[2] = 90;
      (p->s).mode[2]++;
      break;
    }
    case 4: {
      UpdateSpriteAnimation(p);
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        break;
      }
      PlaySound(SE_TENSOU_BACK);
      SetSpriteAnimation(p, MOTION(SM123_TELEPORTAL, 3));
      gStageRun.vm.transition = TRANSITION_BLACKOUT;
      (p->s).mode[2]++;
      break;
    }
    case 5: {
      UpdateSpriteAnimation(p);
      if (gStageRun.vm.transition == TRANSITION_NONE) {
        gStageRun.vm.unk_004 &= ~(1 << 1);
        Camera_SetMode(&gStageRun.vm.camera, CM6);
        (&gStageRun.vm.camera)->chaseMode = CHASE_MODE_B3;
        (&gStageRun.vm.camera)->counter = 0;
        gStageRun.vm.transition = TRANSITION_REVERSE;
        gInTransport = FALSE;
        PlaySound(SE_TENSOU);
        resetSateliteElfPosition(pZero2);
        (pZero2->s).mode[1] = 10, (pZero2->s).mode[2] = 4, (pZero2->s).mode[3] = 0;
        p->player = NULL;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_TELEPORTAL,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0400, 0x0800, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_TELEPORTAL,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

static const u16 u16_ARRAY_08371064[10] = {
    0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F, 0x0017, 0x0000,
};
