#include "collision.h"
#include "entity.h"
#include "gba/gba.h"
#include "gfx.h"
#include "global.h"
#include "motion.h"

void InitNonAffineMotion(struct Entity *p) {
  struct Sprite *spr = &p->spr;
  ResetMotion(&p->motion, gStaticMotionCmdTable[0]);
  InitNonAffineSprite(spr, (struct MetaspriteHeader *)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags >> 4) & 1;
  spr->oam.xflip = (p->flags >> 4) & 1;
  spr->yflip = (p->flags >> 5) & 1;
  spr->oam.yflip = (p->flags >> 5) & 1;

  p->motionID = 0xFF;
  p->flags |= OAM_PRIO;
  p->flags &= ~AFFINE;
  p->flags2 &= ~SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void InitRotatableMotion(struct Entity *p) {
  struct Sprite *spr = &p->spr;
  ResetMotion(&p->motion, gStaticMotionCmdTable[0]);
  InitRotatableSprite(spr, (struct MetaspriteHeader *)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags >> 4) & 1;
  spr->oam.xflip = (p->flags >> 4) & 1;
  spr->yflip = (p->flags >> 5) & 1;
  spr->oam.yflip = (p->flags >> 5) & 1;

  p->motionID = 0xFF;
  p->angle = 0;
  p->flags |= OAM_PRIO;
  p->flags |= AFFINE;
  p->flags2 &= ~SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void InitScalerotMotion1(struct Entity *p) {
  struct Sprite *spr = &p->spr;
  ResetMotion(&p->motion, gStaticMotionCmdTable[0]);
  InitScalerotSprite1(spr, (struct MetaspriteHeader *)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags >> 4) & 1;
  spr->oam.xflip = (p->flags >> 4) & 1;
  spr->yflip = (p->flags >> 5) & 1;
  spr->oam.yflip = (p->flags >> 5) & 1;

  p->motionID = 0xFF;
  p->angle = 0;
  spr->mag.x = 0x100;
  spr->mag.y = 0x100;
  p->flags |= OAM_PRIO;
  p->flags |= AFFINE;
  p->flags2 |= SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void InitScalerotMotion2(struct Entity *p) {
  struct Sprite *spr = &p->spr;
  ResetMotion(&p->motion, gStaticMotionCmdTable[0]);
  InitScalerotSprite2(spr, (struct MetaspriteHeader *)gStaticMotionMetaspriteTable[0], &p->coord);

  spr->xflip = (p->flags >> 4) & 1;
  spr->oam.xflip = (p->flags >> 4) & 1;
  spr->yflip = (p->flags >> 5) & 1;
  spr->oam.yflip = (p->flags >> 5) & 1;

  p->motionID = 0xFF;
  p->angle = 0;
  spr->mag.x = 0x100;
  spr->mag.y = 0x100;
  p->flags |= OAM_PRIO;
  p->flags |= AFFINE;
  p->flags2 |= SCALEROT;
  p->flags2 &= ~ENTITY_FLAG2_B1;
  p->flags2 &= ~DYNAMIC;
  p->flags2 &= ~PALETTE_FORCED;
}

void ResetDynamicMotion(struct Entity *p) {
  p->motionID = 0xFF;
  p->motionStep = 0xFF;
  p->flags2 |= DYNAMIC;
}

WIP void SetMotion(struct Entity *p, motion_t m) {
#if MODERN
  motion_id_t id = (m >> 8) & 0xFF;
  if (id != p->motionID) {
    if (p->flags2 & DYNAMIC) {
      (p->motion).cmds = gDynamicMotionCmdTable[id];
      p->motionStep = 0xFF;
    } else {
      (p->motion).cmds = gStaticMotionCmdTable[id];
      (p->spr).sprites = (struct MetaspriteHeader *)gStaticMotionMetaspriteTable[id];
    }
    p->motionID = id;
  }

  if (!(p->flags2 & DYNAMIC)) {
    struct Sprite *spr = &p->spr;
    u16 palID = (u16)p->palID + wStaticMotionPalIDs[id];

    (spr->oam).tileNum = wStaticGraphicTilenums[id] + p->tileNum;
    if (!(p->flags2 & PALETTE_FORCED)) {
      (spr->oam).paletteNum = palID;
      p->savedPalID = palID;
    }
  }
  setMotionStep(&p->motion, (u8)(m & 0xFF));
#else
  INCCODE("asm/wip/SetMotion.inc");
#endif
}

// SetMotion は cmdIdx とかは 0 つまり motion の初めからになるが、これはmotionの途中状態にもセットできる
void GotoMotion(struct Entity *p, motion_t motion, u16 cmdIdx, u16 r3) {
  SetMotion(p, motion);
  (p->motion).cmdIdx = cmdIdx;
  (p->motion).duration = r3;
}

WIP void UpdateMotionGraphic(struct Entity *p) {
#if MODERN
  UpdateMotionState(&p->motion);
  (p->spr).spriteIdx = (p->motion).cmds[(p->motion).step][(p->motion).cmdIdx].spriteIdx;
  if (p->flags2 & DYNAMIC) {
    u8 step;
    struct MetaspriteHeader *metaspriteTable = gDynamicMotionMetaspriteTable[p->motionID];
    if ((p->spr).sprites != metaspriteTable) {
      (p->spr).sprites = metaspriteTable;
    }

    step = metaspriteTable[(p->spr).spriteIdx].step;
    if (step != p->motionStep) {
      u16 tileNum, palID;
      p->motionStep = step;
      tileNum = wDynamicGraphicTilenums[p->motionID] + p->tileNum;
      palID = wDynamicMotionPalIDs[p->motionID] + p->palID;
      if (p->motionID < 144) {
        struct Graphic *g = &((struct Graphic *)OFFSET_TABLE(gDynamicMotionGraphicOffsets, p->motionID))[step];
        RequestGraphicTransfer(g, (void *)((tileNum - g->ofs) * 32 + 0x10000));
      } else {
        struct ColorGraphic *g = &((struct ColorGraphic *)OFFSET_TABLE(gDynamicMotionGraphicOffsets, p->motionID))[step];
        RequestGraphicTransfer(&g->g, (void *)((tileNum - (g->g).ofs) * 32 + 0x10000));
        LoadPalette(&g->pal, (palID - (g->pal).dst) * 32 + 512);
      }
      (p->spr).oam.tileNum = tileNum;
      if (!(p->flags2 & PALETTE_FORCED)) {
        (p->spr).oam.paletteNum = palID;
        p->savedPalID = palID;
      }
    }
  }
#else
  INCCODE("asm/wip/UpdateMotionGraphic.inc");
#endif
}

WIP void FUN_0801779c(struct Entity *p) {
#if MODERN
  UpdateMotionState(&p->motion);
  (p->spr).spriteIdx = (p->motion).cmds[(p->motion).step][(p->motion).cmdIdx].spriteIdx;
  if (p->flags2 & DYNAMIC) {
    u8 step;
    if ((p->spr).sprites != gDynamicMotionMetaspriteTable[p->motionID]) {
      (p->spr).sprites = gDynamicMotionMetaspriteTable[p->motionID];
    }

    step = (p->spr).sprites[(p->spr).spriteIdx].step;
    if (step != (p->motionStep & 0x7F)) {
      u16 tileNum, palID;
      p->motionStep = step | 0x80;
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

NAKED static void unused_0801785c(struct Entity *p) { INCCODE("asm/unused/unused_0801785c.inc"); }

void UpdateEntityPaletteID(struct Entity *p) {
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

u8 GetEntityPalID(struct Entity *p) {
  u16 palID;
  if (p->flags2 & DYNAMIC) {
    palID = p->palID + wDynamicMotionPalIDs[p->motionID];
  } else {
    palID = p->palID + wStaticMotionPalIDs[p->motionID];
  }
  return palID;
}

void ForceEntityPalette(struct Entity *p, u8 palID) {
  p->flags2 |= PALETTE_FORCED;
  (p->spr).oam.paletteNum = palID;
  p->savedPalID = palID;
}

void PaintEntityWhite(struct Entity *p) {
  u8 palID = 13;
  gWhitePaintFlags[p->invincibleID >> 5] |= (1 << (p->invincibleID & 0x1F));
  p->flags2 |= PALETTE_FORCED;
  (p->spr).oam.paletteNum = palID;
  p->savedPalID = palID;
}

NON_MATCH void InitMotionLocation(void) {
#if MODERN
  s16 i;
  for (i = 0; i < STATIC_MOTION_COUNT; i++) {
    wStaticGraphicTilenums[i] = gStaticMotionGraphics[i].g.ofs;
    wStaticMotionPalIDs[i] = gStaticMotionGraphics[i].pal.dst;
  }
  for (i = 0; i < DYNAMIC_MOTION_COUNT; i++) {
    struct ColorGraphic *g = (struct ColorGraphic *)OFFSET_TABLE(gDynamicMotionGraphicOffsets, i);
    wDynamicGraphicTilenums[i] = (g->g).ofs;
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
