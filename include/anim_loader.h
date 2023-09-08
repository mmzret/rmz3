#ifndef GUARD_RMZ3_ANIM_LOADER_H
#define GUARD_RMZ3_ANIM_LOADER_H

#define STATIC_GRAPHIC_LOADER(fn, n)                                            \
  {                                                                             \
    const struct Graphic* g;                                                    \
    const struct Palette* pal;                                                  \
    u32 ofs;                                                                    \
    ofs = (sizeof(struct ColorGraphic) * n);                                    \
    g = gStaticGraphic(ofs);                                                    \
    fn(g, (void*)((wStaticGraphicTilenums[n] - g->ofs) * 32 + 0x10000));        \
    pal = gStaticPalette(ofs);                                                  \
    LoadPalette(pal, (wStaticMotionPalIDs[n] - pal->dst) * 32 + PLTT_SIZE / 2); \
  }

#define LOAD_STATIC_GRAPHIC(n) STATIC_GRAPHIC_LOADER(LoadGraphic, n)
#define REQUEST_STATIC_GRAPHIC(n) STATIC_GRAPHIC_LOADER(RequestGraphicTransfer, n)

#endif  // GUARD_RMZ3_ANIM_LOADER_H
