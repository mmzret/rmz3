#include "entity.h"

#include "collision.h"
#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "task.h"

/**
 * @brief 引数の EntityHeader の示す fnを処理していく
 * @note 0x08016e1c
 */
void UpdateEntities(struct EntityHeader *h) {
  struct Entity *p;

  setCurProcessedEntityHeader(h);

  // h->last->prev -> h->last->prev->prev -> h->last->prev->prev->prev -> ...
  p = h->last->prev;
  h->last = p;
  while (p != (struct Entity *)&h->next) {
    ((EntityFunc)p->onUpdate)(p);
    p = h->last->prev;
    h->last = p;
  }
}

void UpdateBlockingEntities(struct EntityHeader *h) {
  struct Entity *p;

  setCurProcessedEntityHeader(h);
  p = h->last = h->last->prev;
  while (p != (struct Entity *)&h->next) {
    ((EntityFunc)p->onUpdate)(p);
    if (p->flags2 & ENTITY_HAZARD) {
      AppendHazard((u16)p->uniqueID, p->hazardAttr, &p->coord, p->size);
    }

    p = h->last = h->last->prev;
  }
}

// EntityHeaderの全部のEntityのHitboxデータを CollisionManager に登録
void RegisterHitboxes(struct EntityHeader *h) {
  setCurProcessedEntityHeader(h);

  while (TRUE) {
    struct CollidableEntity *p;
    h->last = h->last->prev;
    p = (struct CollidableEntity *)h->last;
    if (p == (struct CollidableEntity *)&h->next) {
      break;
    }

    if ((p->s).flags & COLLIDABLE) {
      struct Body *body = &p->body;
      if ((p->s).flags & FLIPABLE) {
        if ((p->s).flags & AFFINE) {
          RegisterScalerotHitbox(body, ((p->s).flags & 0x30) >> 4, (p->s).angle);
        } else {
          RegisterFlipableHitbox(body, ((p->s).flags & 0x30) >> 4);
        }
      } else {
        ResisterNonAffineHitbox(body);
      }
    }
  }
}

/**
 * @brief 各EntityHeaderの持つEntityを見ていって、必要な場合は 無敵点滅処理 と ダメージSE を行う
 * @note 0x08016EF4
 */
WIP void RunDamageEffect(struct EntityHeader *h) {
#if MODERN
  struct CollidableEntity *p;

  setCurProcessedEntityHeader(h);
  h->last = h->last->prev;
  p = (struct CollidableEntity *)h->last;
  while (p != (struct CollidableEntity *)&h->next) {
    if (((p->s).flags & COLLIDABLE) && ((p->s).flags2 & ENTITY_FLAGS2_B4)) {
      if (((p->body).status & BODY_STATUS_WHITE) || ((p->body).prevStatus & 1) || ((p->body).invincibleTime & 2)) {
        gWhitePaintFlags[(p->s).invincibleID >> 5] |= (1 << ((p->s).invincibleID & 0x1F));
      }

      if ((wPauseFrame == 0) && ((p->body).status & BODY_STATUS_WHITE) && (((p->body).collisions)->layer != 0)) {
        gIsPlayDamageSE = TRUE;
      }
    }

    h->last = h->last->prev;
    p = (struct CollidableEntity *)h->last;
  }
#else
  INCCODE("asm/wip/RunDamageEffect.inc");
#endif
}

WIP void DrawEntity(struct EntityHeader *h, struct TaskManager *tm) {
#if MODERN
  struct Entity *p;

  setCurProcessedEntityHeader(h);
  p = h->last->prev;
  h->last = p;

  while (p != (struct Entity *)&h->next) {
    if (p->flags & DISPLAY) {
      struct Sprite *spr = &p->spr;

      if (p->flags & AFFINE) {
        (spr->oam).matrixNum = gMatrixCount;
        if (gMatrixCount < 31) {
          gMatrixCount++;
        }

        if (p->flags2 & SCALEROT) {
          if (p->flags2 & ENTITY_FLAG2_B1) {
            ScalerotSprite(spr, p->angle);
          } else {
            ScalerotSprite(spr, p->angle);
          }
        } else {
          RotateSprite(spr, p->angle);
        }
      }
      if (p->flags & OAM_PRIO) {
        AppendTask(tm, (struct Task *)spr, (spr->oam).priority, p->taskCol);
      } else {
        AppendTask(tm, (struct Task *)spr, 0, p->taskCol);
      }
    }
    p = h->last->prev;
    h->last = p;
  }
#else
  INCCODE("asm/wip/DrawEntity.inc");
#endif
}

// gWhitePaintFlags を見て白塗りにするか以外は DrawEntity と同じ
WIP void DrawCollidableEntity(struct EntityHeader *h, struct TaskManager *tm) {
#if MODERN
  struct Entity *p;

  setCurProcessedEntityHeader(h);
  p = h->last->prev;
  h->last = p;

  while (p != (struct Entity *)&h->next) {
    if (p->flags & DISPLAY) {
      struct Sprite *spr = &p->spr;

      if (p->flags & OAM_PRIO) {
        if (gWhitePaintFlags[p->invincibleID >> 5] & (1 << (p->invincibleID & 0x1F))) {
          (spr->oam).paletteNum = 13;
        } else {
          (spr->oam).paletteNum = p->savedPalID;
        }

        if (p->flags & AFFINE) {
          (spr->oam).matrixNum = gMatrixCount;
          if (gMatrixCount < 31) {
            gMatrixCount++;
          }
          if (p->flags2 & SCALEROT) {
            if (p->flags2 & ENTITY_FLAG2_B1) {
              ScalerotSprite(spr, p->angle);
            } else {
              ScalerotSprite(spr, p->angle);
            }
          } else {
            RotateSprite(spr, p->angle);
          }
        }
        AppendTask(tm, (struct Task *)spr, (spr->oam).priority, p->taskCol);
      } else {
        AppendTask(tm, (struct Task *)spr, 0, p->taskCol);
      }
    }

    p = h->last->prev;
    h->last = p;
  }
#else
  INCCODE("asm/wip/DrawCollidableEntity.inc");
#endif
}

struct Entity *GetNearestEntity(struct EntityHeader *h, struct Coord *c) {
  struct Entity *p;
  struct Entity *result = NULL;
  u32 min = 0xFFFFFFFF;
  if (h->length == h->remaining) {
    return result;
  }

  ignoreEntityFn(h);
  p = h->last = h->last->prev;
  while (p != (struct Entity *)&h->next) {
    if ((p->flags & DISPLAY) && (p->flags & COLLIDABLE)) {
      s32 x = ((p->coord).x - c->x) >> 8;
      s32 y = ((p->coord).y - c->y) >> 8;
      u32 d = (x * x) + (y * y);
      if (d < min) {
        min = d;
        result = p;
      }
    }
    p = h->last = h->last->prev;
  }
  return result;
}

u16 countSpecificEntities1(struct EntityHeader *h, u8 id) {
  struct Entity *p;
  struct Entity *last;
  u16 val = 0;
  if (h->length == h->remaining) return 0;

  last = h->last;
  ignoreEntityFn(h);
  p = h->last->prev;
  h->last = p;
  while (p != (struct Entity *)&h->next) {
    if (p->id == id) {
      val++;
    }
    p = h->last->prev;
    h->last = p;
  }
  h->last = last;
  return val;
}

u16 countSpecificEntities2(struct EntityHeader *h, u8 id, u8 r2, u8 r3) {
  struct Entity *p;
  struct Entity *last;
  u16 val = 0;
  if (h->length == h->remaining) return 0;

  last = h->last;
  ignoreEntityFn(h);

  h->last = h->last->prev;
  p = h->last;

  while (p != (struct Entity *)&h->next) {
    if (((p->id == id) && (p->work[0] == r2)) && (p->work[1] == r3)) {
      val++;
    }
    h->last = h->last->prev;
    p = h->last;
  }
  h->last = last;
  return val;
}
