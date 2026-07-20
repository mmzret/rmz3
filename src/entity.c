#include "entity.h"

#include "collision.h"
#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "renderer.h"

// 0x08016db4
void ResetEntityEnvironment(void) {
  InitMotionLocation();
  gEntityIDGenerator = 0;
  gInHitStopFrames = FALSE;
  gIsPlayDamageSE = FALSE;
  gLifeRecoverAmount = 0;
  gSubtankRecoverAmount = 0;
  gECrystalGainAmount = 0;
  gInChat = 0;
  gIsUsingDoor3D = FALSE;
  gInTransport = FALSE;
  gPause = FALSE;
  gTimeElfTimer = 0;
}

/**
 * @brief 引数の EntityHeader の示す fnを処理していく
 * @note 0x08016e1c
 */
void UpdateEntities(struct EntityHeader* h) {
  struct Entity* p = StartEntityListIteration(h);
  while (p != ((void*)&h->tail)) {
    ((EntityFunc)p->onUpdate)(p);
    p = GetNextEntity(h);
  }
}

void UpdateHazardEntities(struct EntityHeader* h) {
  struct Entity* p = StartEntityListIteration(h);
  while (p != (struct Entity*)&h->tail) {
    ((EntityFunc)p->onUpdate)(p);
    if (p->flags2 & ENTI_PHYSICS) {
      AppendHazard(p->uniqueID, p->physicsAttr, &p->coord, p->size);
    }
    p = GetNextEntity(h);
  }
}

// EntityHeaderの全部のEntityのHitboxデータを CollisionManager に登録
void RegisterHitboxes(struct EntityHeader* h) {
  Object* p = (void*)StartEntityListIteration(h);

  while (p != (Object*)&h->tail) {
    if (p->flags & COLLIDABLE) {
      struct Body* body = &p->body;
      if (p->flags & FLIPABLE) {
        if (p->flags & AFFINE) {
          RegisterScalerotHitbox(body, (p->flags & 0x30) >> 4, p->angle);
        } else {
          RegisterFlipableHitbox(body, (p->flags & 0x30) >> 4);
        }
      } else {
        ResisterNonAffineHitbox(body);
      }
    }
    p = (Object*)GetNextEntity(h);
  }
}

/**
 * @brief 各EntityHeaderの持つEntityを見ていって、必要な場合は 無敵点滅処理 と ダメージSE を行う
 * @note 0x08016EF4
 */
NON_MATCH void RunDamageEffect(struct EntityHeader* h) {
#if MODERN
  Object* p = (void*)StartEntityListIteration(h);

  while (p != ((void*)&h->tail)) {
    if ((p->flags & COLLIDABLE) && (p->flags2 & WHITE_PAINTABLE)) {
      if (((p->body).status & BODY_STATUS_WHITE) || ((p->body).prevStatus & 1) || ((p->body).invincibleTime & 2)) {
        gWhitePaintFlags[p->invincibleID >> 5] |= (1 << (p->invincibleID & 0x1F));
      }
      if (!gInHitStopFrames) {
        if (((p->body).status & BODY_STATUS_WHITE) && (((p->body).collisions)->faction != FACTION_ALLY)) {
          gIsPlayDamageSE = TRUE;
        }
      }
    }
    p = (Object*)GetNextEntity(h);
  }
#else
  INCCODE("asm/wip/RunDamageEffect.inc");
#endif
}

void DrawEntity(struct EntityHeader* h, Renderer* r) {
  struct Entity* p = StartEntityListIteration(h);

  while (p != ((void*)&h->tail)) {
    if (p->flags & DISPLAY) {
      struct Sprite* spr = &p->spr;

      if (p->flags & AFFINE) {
        (spr->oam).matrixNum = gMatrixCount;
        if (gMatrixCount < 31) gMatrixCount++;

        if (p->flags2 & SCALEROT) {
          if (p->flags2 & ENTITY_FLAG2_B1) {
            ScalerotSprite(spr, p->angle);
          } else {
            ScalerotSprite2(spr, p->angle);
          }
        } else {
          RotateSprite(spr, p->angle);
        }
      }
      if (p->flags & USE_COMMON_OAM_RENDERER) {
        Renderer_SendTask(r, (void*)spr, (spr->oam).priority, p->renderPrio);  // normal rendering (as GBA sprites)
      } else {
        Renderer_SendTask(r, (void*)spr, 0, p->renderPrio);  // custom rendering
      }
    }
    p = GetNextEntity(h);
  }
}

// gWhitePaintFlags を見て白塗りにするか以外は DrawEntity と同じ
void DrawCollidableEntity(struct EntityHeader* h, Renderer* r) {
  struct Entity* p = StartEntityListIteration(h);

  while (p != ((void*)&h->tail)) {
    if (p->flags & DISPLAY) {
      struct Sprite* spr = &p->spr;

      if (p->flags & USE_COMMON_OAM_RENDERER) {
        if (gWhitePaintFlags[p->invincibleID >> 5] & (1 << (p->invincibleID & 0x1F))) {
          (spr->oam).paletteNum = 13;
        } else {
          (spr->oam).paletteNum = p->savedPalID;
        }

        if (p->flags & AFFINE) {
          (spr->oam).matrixNum = gMatrixCount;
          if (gMatrixCount < 31) gMatrixCount++;

          if (p->flags2 & SCALEROT) {
            if (p->flags2 & ENTITY_FLAG2_B1) {
              ScalerotSprite(spr, p->angle);
            } else {
              ScalerotSprite2(spr, p->angle);
            }
          } else {
            RotateSprite(spr, p->angle);
          }
        }
        Renderer_SendTask(r, (void*)spr, (spr->oam).priority, p->renderPrio);  // normal rendering (as GBA sprites)
      } else {
        Renderer_SendTask(r, (void*)spr, 0, p->renderPrio);  // custom rendering
      }
    }
    p = GetNextEntity(h);
  }
}

struct Entity* GetNearestEntity(struct EntityHeader* h, Coords32* c) {
  struct Entity* p;
  struct Entity* result = NULL;
  u32 min = 0xFFFFFFFF;
  if (h->length == h->remaining) {
    return result;
  }

  p = GetEntityList(h);
  while (p != (struct Entity*)&h->tail) {
    if ((p->flags & DISPLAY) && (p->flags & COLLIDABLE)) {
      s32 x = ((p->coord).x - c->x) >> 8;
      s32 y = ((p->coord).y - c->y) >> 8;
      u32 d = (x * x) + (y * y);
      if (d < min) {
        min = d;
        result = p;
      }
    }
    p = GetNextEntity(h);
  }
  return result;
}

u16 countSpecificEntities1(struct EntityHeader* h, u8 id) {
  struct Entity* p;
  struct Entity* saved;
  u16 val = 0;
  if (h->length == h->remaining) return 0;

  saved = h->cur;
  p = GetEntityList(h);
  while (p != (struct Entity*)&h->tail) {
    if (p->id == id) val++;
    p = GetNextEntity(h);
  }
  h->cur = saved;
  return val;
}

u16 countSpecificEntities2(struct EntityHeader* h, u8 id, u8 r2, u8 r3) {
  struct Entity* p;
  struct Entity* saved;
  u16 val = 0;
  if (h->length == h->remaining) return 0;

  saved = h->cur;
  p = GetEntityList(h);
  while (p != (struct Entity*)&h->tail) {
    if (((p->id == id) && (p->work[0] == r2)) && (p->work[1] == r3)) val++;
    p = GetNextEntity(h);
  }
  h->cur = saved;
  return val;
}
