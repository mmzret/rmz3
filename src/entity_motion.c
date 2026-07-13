#include "collision.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "motion.h"

/**
 * @note 直接呼ばずに EnableSpriteAnimation_Normal() を呼ぶ
 */
void InitNonAffineMotion(struct Entity* p) {
  struct Sprite* spr = &p->spr;
  ResetAnimState(&p->motion, gStaticMotionCmdTable[0]);
  InitNonAffineSprite(spr, (struct MetaspriteHeader*)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags & X_FLIP) != 0;
  (spr->oam).xflip = (p->flags & X_FLIP) != 0;
  spr->yflip = (p->flags & Y_FLIP) != 0;
  (spr->oam).yflip = (p->flags & Y_FLIP) != 0;

  p->motionID = 0xFF;
  p->flags |= USE_COMMON_OAM_RENDERER;
  p->flags &= ~AFFINE;
  p->flags2 &= ~SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void InitRotatableMotion(struct Entity* p) {
  struct Sprite* spr = &p->spr;
  ResetAnimState(&p->motion, gStaticMotionCmdTable[0]);
  InitRotatableSprite(spr, (struct MetaspriteHeader*)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags & X_FLIP) != 0;
  (spr->oam).xflip = (p->flags & X_FLIP) != 0;
  spr->yflip = (p->flags & Y_FLIP) != 0;
  (spr->oam).yflip = (p->flags & Y_FLIP) != 0;

  p->motionID = 0xFF;
  p->angle = 0;
  p->flags |= USE_COMMON_OAM_RENDERER;
  p->flags |= AFFINE;
  p->flags2 &= ~SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void InitScalerotMotion1(struct Entity* p) {
  struct Sprite* spr = &p->spr;
  ResetAnimState(&p->motion, gStaticMotionCmdTable[0]);
  InitScalerotSprite1(spr, (struct MetaspriteHeader*)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags & X_FLIP) != 0;
  (spr->oam).xflip = (p->flags & X_FLIP) != 0;
  spr->yflip = (p->flags & Y_FLIP) != 0;
  (spr->oam).yflip = (p->flags & Y_FLIP) != 0;

  p->motionID = 0xFF;
  p->angle = 0;
  (spr->mag).x = 0x100, (spr->mag).y = 0x100;
  p->flags |= USE_COMMON_OAM_RENDERER;
  p->flags |= AFFINE;
  p->flags2 |= SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void InitScalerotMotion2(struct Entity* p) {
  struct Sprite* spr = &p->spr;
  ResetAnimState(&p->motion, gStaticMotionCmdTable[0]);
  InitScalerotSprite2(spr, (struct MetaspriteHeader*)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags & X_FLIP) != 0;
  (spr->oam).xflip = (p->flags & X_FLIP) != 0;
  spr->yflip = (p->flags & Y_FLIP) != 0;
  (spr->oam).yflip = (p->flags & Y_FLIP) != 0;

  p->motionID = 0xFF;
  p->angle = 0;
  (spr->mag).x = 0x100, (spr->mag).y = 0x100;
  p->flags |= USE_COMMON_OAM_RENDERER;
  p->flags |= AFFINE;
  p->flags2 |= SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void ResetDynamicMotion(struct Entity* p) {
  p->motionID = 0xFF;
  p->texture = 0xFF;
  p->flags2 |= DYNAMIC;
}

NON_MATCH void SetMotion(struct Entity* p, motion_t m) {
#if MODERN
  motion_id_t id = m >> 8;
  if (id != p->motionID) {
    if (p->flags2 & DYNAMIC) {
      (p->motion).table = *(const AnimCmd***)((void*)gDynamicMotionCmdTable + ((u32)id << 2));  // = gDynamicMotionCmdTable[id]
      p->texture = 0xFF;
    } else {
      (p->motion).table = *(const AnimCmd***)((void*)gStaticMotionCmdTable + ((u32)id << 2));                 // = gStaticMotionCmdTable[id]
      (p->spr).sprites = *(struct MetaspriteHeader**)((void*)gStaticMotionMetaspriteTable + ((u32)id << 2));  // = gStaticMotionMetaspriteTable[id];
    }
    p->motionID = id;  // ここら辺のレジスタの割り当てがあわない
  }

  if ((p->flags2 & DYNAMIC) == 0) {
    struct Sprite* spr = &p->spr;
    u16 tileNum = p->tileNum + wStaticGraphicTilenums[id];
    u16 palID = p->palID + wStaticMotionPalIDs[id];

    (spr->oam).tileNum = tileNum;
    if ((p->flags2 & PALETTE_FORCED) == 0) {
      (spr->oam).paletteNum = palID;
      p->savedPalID = (u8)palID;
    }
  }
  SetAnimSubID(&p->motion, (u8)m);
#else
  INCCODE("asm/wip/SetMotion.inc");
#endif
}

// SetMotion は cmdIdx とかは 0 つまり motion の初めからになるが、これはmotionの途中状態にもセットできる
void GotoMotion(struct Entity* p, motion_t motion, u16 cmdIdx, u16 duration) {
  SetSpriteAnimation(p, motion);
  (p->motion).cmdIdx = cmdIdx;
  (p->motion).duration = duration;
}

// 0x0801765C
NON_MATCH void UpdateEntityAnim(struct Entity* p) {
#if MODERN
  u8 spriteIdx;
  struct Sprite* spr = &p->spr;
  StepAnimState(&p->motion);
  spr->spriteIdx = spriteIdx = (p->motion).table[(p->motion).id][(p->motion).cmdIdx].param;
  if (p->flags2 & DYNAMIC) {
    u8 texture;
    struct MetaspriteHeader* metaspriteTable = gDynamicMotionMetaspriteTable[p->motionID];
    if (spr->sprites != metaspriteTable) {
      (p->spr).sprites = metaspriteTable;
    }

    texture = metaspriteTable[spriteIdx].texture;
    if (texture != p->texture) {
      u16 tileNum, palID;

      p->texture = texture;

      tileNum = p->tileNum + wDynamicGraphicTilenums[p->motionID];
      palID = p->palID + wDynamicMotionPalIDs[p->motionID];
      if (p->motionID < 144) {
        struct Graphic* g = (struct Graphic*)SELF_REL_PTR(&gDynamicMotionGraphicOffsets[p->motionID]) + texture;
        RequestGraphicTransfer((void*)g, (void*)((tileNum - g->tileId) * 32 + 0x10000));
      } else {
        ColorGraphic* g = (ColorGraphic*)SELF_REL_PTR(&gDynamicMotionGraphicOffsets[p->motionID]) + texture;
        RequestGraphicTransfer((void*)g, (void*)((tileNum - (g->g).tileId) * 32 + 0x10000));
        LoadPalette(&g->pal, (palID - (g->pal).dst) * 32 + 512);
      }
      (spr->oam).tileNum = tileNum;
      if (!(p->flags2 & PALETTE_FORCED)) {
        (spr->oam).paletteNum = palID;
        p->savedPalID = palID;
      }
    }
  }
#else
  INCCODE("asm/wip/UpdateEntityAnim.inc");
#endif
}

NON_MATCH void FUN_0801779c(struct Entity* p) {
#if MODERN
  StepAnimState(&p->motion);
  (p->spr).spriteIdx = (p->motion).table[(p->motion).id][(p->motion).cmdIdx].param;
  if (p->flags2 & DYNAMIC) {
    u8 texture;
    if ((p->spr).sprites != gDynamicMotionMetaspriteTable[p->motionID]) {
      (p->spr).sprites = gDynamicMotionMetaspriteTable[p->motionID];
    }

    texture = (p->spr).sprites[(p->spr).spriteIdx].texture;
    if (texture != (p->texture & 0x7F)) {
      u16 tileNum, palID;
      p->texture = texture | 0x80;
      tileNum = wDynamicGraphicTilenums[p->motionID] + p->tileNum;
      palID = wDynamicMotionPalIDs[p->motionID] + p->palID;

      (p->spr).oam.tileNum = tileNum;
      if (!(p->flags2 & PALETTE_FORCED)) {
        (p->spr).oam.paletteNum = palID;
        p->savedPalID = palID;
      }
    }
  }
#else
  INCCODE("asm/wip/FUN_0801779c.inc");
#endif
}

NAKED static void unused_0801785c(struct Entity* p) { INCCODE("asm/unused/unused_0801785c.inc"); }

void UpdateEntityPaletteID(struct Entity* p) {
  u16 pal;
  if (p->flags2 & DYNAMIC) {
    pal = p->palID + wDynamicMotionPalIDs[p->motionID];
  } else {
    pal = p->palID + wStaticMotionPalIDs[p->motionID];
  }
  (p->spr).oam.paletteNum = pal;
  p->savedPalID = pal;
  p->flags2 &= ~PALETTE_FORCED;
}

u8 GetEntityPalID(struct Entity* p) {
  u16 palID;
  if (p->flags2 & DYNAMIC) {
    palID = p->palID + wDynamicMotionPalIDs[p->motionID];
  } else {
    palID = p->palID + wStaticMotionPalIDs[p->motionID];
  }
  return palID;
}

void ForceEntityPalette(struct Entity* p, u8 palID) {
  p->flags2 |= PALETTE_FORCED;
  (p->spr).oam.paletteNum = palID;
  p->savedPalID = palID;
}

void PaintEntityWhite(struct Entity* p) {
  u8 palID = 13;
  SET_FLAG32(gWhitePaintFlags, p->invincibleID);
  p->flags2 |= PALETTE_FORCED;
  (p->spr).oam.paletteNum = palID;
  p->savedPalID = palID;
}

NON_MATCH void InitMotionLocation(void) {
#if MODERN
  s16 i;
  for (i = 0; i < STATIC_MOTION_COUNT; i++) {
    wStaticGraphicTilenums[i] = gStaticMotionGraphics[i].g.tileId;
    wStaticMotionPalIDs[i] = gStaticMotionGraphics[i].pal.dst;
  }
  for (i = 0; i < DYNAMIC_MOTION_COUNT; i++) {
    ColorGraphic* g = SELF_REL_PTR(&gDynamicMotionGraphicOffsets[i]);
    wDynamicGraphicTilenums[i] = (g->g).tileId;
    if (i < 144) {
      wDynamicMotionPalIDs[i] = 0;
    } else {
      wDynamicMotionPalIDs[i] = (g->pal).dst;
    }
  }
#else
  INCCODE("asm/wip/InitMotionLocation.inc");
#endif
}
