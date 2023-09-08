#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "task.h"

extern const u8* const sSpriteSize[2];
extern const u8* const sAffineSpriteSize[2];

WIP void TaskCB_DrawNoAffineSprite(struct Sprite* s, struct DrawPivot* tc) {
#if MODERN
  struct Coord* c = s->c;
  struct MetaspriteHeader* h = &s->sprites[s->spriteIdx];
  struct Subsprite* ss = (struct Subsprite*)(PTR_U32(&(s->sprites)->ofs) + h->ofs);
  s32 len = h->subspriteCount;
  if (PTR_U32(gOamManager.p) < (PTR_U32(&gOamManager.p) - (len * sizeof(struct OamData)))) {
    for (; len != 0; len--) {
      s32 Y = (c->y - (tc->lefttop).y) >> 8;
      if (s->yflip) {
        Y = (Y - ss->y) - sSpriteSize[1][ss->size | (ss->shape << 2)];
      } else {
        Y = (Y + ss->y);
      }
      if (Y < DISPLAY_HEIGHT) {
        s32 X = (c->x - (tc->lefttop).x) >> 8;
        if (s->xflip) {
          X = (X - ss->x) - sSpriteSize[0][ss->size | (ss->shape << 2)];
        } else {
          X = (X + ss->x);
        }
        if (X < DISPLAY_WIDTH + 6) {
          struct OamDataNoAffine* oam = (struct OamDataNoAffine*)gOamManager.p;
          oam->y = s->oam.y | Y;
          oam->x = s->oam.x | X;
          oam->affineMode = s->oam.affineMode;
          oam->objMode = s->oam.objMode;
          oam->mosaic = s->oam.mosaic;
          oam->bpp = s->oam.bpp;
          oam->xflip = s->oam.xflip ^ ss->xflip;
          oam->yflip = s->oam.yflip ^ ss->yflip;
          oam->size = s->oam.size | ss->size;
          oam->shape = s->oam.shape | ss->shape;
          oam->tileNum = s->oam.tileNum + ss->tileNum;
          oam->paletteNum = s->oam.paletteNum;
          oam->priority = s->oam.priority;

          gOamManager.p = &gOamManager.p[1];
        }
      }
      ss = &ss[1];
    }
  }
#else
  INCCODE("asm/wip/TaskCB_DrawNoAffineSprite.inc");
#endif
}

WIP void TaskCB_DrawRotatableSprite(struct Sprite* s, struct DrawPivot* tc) {
#if MODERN
  struct Coord* c = s->c;
  struct MetaspriteHeader* h = &s->sprites[s->spriteIdx];
  struct Subsprite* ss = (struct Subsprite*)(PTR_U32(&(s->sprites)->ofs) + h->ofs);
  s32 len = h->subspriteCount;
  if (PTR_U32(gOamManager.p) < (PTR_U32(&gOamManager.p) - (len * sizeof(struct OamData)))) {
    u8 angle = s->angle;
    if (s->xflip != s->yflip) {
      angle = -angle;
    }

    s16 sin = SIN(angle);
    s16 cos = COS(angle);

    for (; len != 0; len--) {
      s32 X, Y;

      const u32 shape = ss->size | (ss->shape << 2);
      const s32 W = sAffineSpriteSize[0][shape];
      const s32 H = sAffineSpriteSize[1][shape];

      s32 x = sin * (ss->x + W);
      if (s->xflip) {
        x = -x;
      }
      s32 y = cos * (ss->y + H);
      if (s->yflip) {
        y = -y;
      }
      Y = ((x + y) >> 8) - (H * 2) + ((c->y - (tc->lefttop).y) >> 8);

      if (Y < DISPLAY_HEIGHT) {
        s32 x = cos * (ss->x + W);
        if (s->xflip) {
          x = -x;
        }
        s32 y = sin * (ss->y + H);
        if (s->yflip) {
          y = -y;
        }
        X = ((x + y) >> 8) - (W * 2) + ((c->x - (tc->lefttop).x) >> 8);

        if (x < DISPLAY_WIDTH + 6) {
          struct OamData* oam = gOamManager.p;
          *(u32*)oam = *(u32*)&s->oam;
          oam->y |= Y;
          oam->x |= X;
          oam->size |= ss->size;
          oam->shape |= ss->shape;
          oam->tileNum = s->oam.tileNum + ss->tileNum;
          oam->paletteNum = s->oam.paletteNum;
          oam->priority = s->oam.priority;

          gOamManager.p = &gOamManager.p[1];
        }
      }
      ss = &ss[1];
    }
  }
#else
  INCCODE("asm/wip/TaskCB_DrawRotatableSprite.inc");
#endif
}

WIP void RotateSprite(struct Sprite* s, s32 angle) {
#if MODERN
  struct OamData* oam = &gOamManager.buf[s->oam.matrixNum * 4];
  s->angle = angle;
  if (s->xflip != s->yflip) {
    angle = (-angle) & 0xFF;
  }

  oam[0].affineParam = COS(angle);
  oam[1].affineParam = SIN(angle);
  if (s->xflip) {
    oam[0].affineParam = -COS(angle);
    oam[1].affineParam = -SIN(angle);
  }

  oam[2].affineParam = -SIN(angle);
  oam[3].affineParam = COS(angle);
  if (s->yflip) {
    oam[2].affineParam = SIN(angle);
    oam[3].affineParam = -COS(angle);
  }
#else
  INCCODE("asm/wip/RotateSprite.inc");
#endif
}

WIP void ScalerotSprite(struct Sprite* s, s32 angle) {
#if MODERN
  u8 angle1, angle2;
  struct OamData* oam = &gOamManager.buf[s->oam.matrixNum * 4];
  s->angle = angle;
  if (s->xflip != s->yflip) {
    angle = (u8)(-angle);
  }

  if (s->xflip) {
    oam[0].affineParam = -((COS(angle) << 8) / (s->mag.x + 22));
    oam[1].affineParam = -((SIN(angle) << 8) / (s->mag.x + 22));
  } else {
    oam[0].affineParam = ((COS(angle) << 8) / (s->mag.x + 22));
    oam[1].affineParam = ((SIN(angle) << 8) / (s->mag.x + 22));
  }

  if (s->yflip) {
    oam[2].affineParam = ((SIN(angle) << 8) / (s->mag.y + 22));
    oam[3].affineParam = -((COS(angle) << 8) / (s->mag.y + 22));
  } else {
    oam[2].affineParam = -((SIN(angle) << 8) / (s->mag.y + 22));
    oam[3].affineParam = ((COS(angle) << 8) / (s->mag.y + 22));
  }
#else
  INCCODE("asm/wip/ScalerotSprite.inc");
#endif
}

const u8 sSpriteWidth[12] = {
    0x07, 0x0F, 0x1F, 0x3F, 0x0F, 0x1F, 0x1F, 0x3F, 0x07, 0x07, 0x0F, 0x1F,
};

const u8 sSpriteHeight[12] = {
    0x07, 0x0F, 0x1F, 0x3F, 0x07, 0x07, 0x0F, 0x1F, 0x0F, 0x1F, 0x1F, 0x3F,
};

// 0x080006a0
const u8* const sSpriteSize[2] = {
    sSpriteWidth,
    sSpriteHeight,
};

const u8 sSpriteAffineWidth[12] = {
    0x04, 0x08, 0x10, 0x20, 0x08, 0x10, 0x10, 0x20, 0x04, 0x04, 0x08, 0x10,
};

const u8 sSpriteAffineHeight[12] = {
    0x04, 0x08, 0x10, 0x20, 0x04, 0x04, 0x08, 0x10, 0x08, 0x10, 0x10, 0x20,
};

const u8* const sAffineSpriteSize[2] = {
    sSpriteAffineWidth,
    sSpriteAffineHeight,
};
