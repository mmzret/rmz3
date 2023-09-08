#ifndef GUARD_RMZ3_SPRITE_H
#define GUARD_RMZ3_SPRITE_H

#include "common.h"
#include "entity.h"
#include "gba/types.h"
#include "overworld.h"

void ResetPivot(struct Pivot *p, struct Coord *c, u32 _, void *nullVal);
void CreateDrawPivot(struct DrawPivot *c, struct Pivot *p, void *_ UNUSED);

void TaskCB_DrawNoAffineSprite(struct Sprite *s, struct DrawPivot *c);
void TaskCB_DrawRotatableSprite(struct Sprite *s, struct DrawPivot *c);
void TaskCB_SetMetaspriteTileNum1(struct Sprite *s, struct DrawPivot *tc);
void TaskCB_SetMetaspriteTileNum2(struct Sprite *s, struct DrawPivot *tc);

#endif  // GUARD_RMZ3_SPRITE_H
