#ifndef GUARD_RMZ3_ANIM_LOADER_H
#define GUARD_RMZ3_ANIM_LOADER_H

#if MODERN
#define STATIC_GRAPHICS ((void*)(&gStaticMotionGraphics[0]))
#define STATIC_PALETTES ((void*)(&(gStaticMotionGraphics[0].pal)))
#else
#define STATIC_GRAPHICS ((void*)(0x085d78f8))
#define STATIC_PALETTES ((void*)(0x085d7904))
#endif

#define gStaticGraphic(ofs) ((const struct Graphic*)(STATIC_GRAPHICS + ofs))
#define gStaticPalette(ofs) ((const struct Palette*)(STATIC_PALETTES + ofs))

#define STATIC_GRAPHIC_LOADER(fn, n)                                              \
  {                                                                               \
    const struct Graphic* g;                                                      \
    const struct Palette* pal;                                                    \
    u32 ofs;                                                                      \
    ofs = (sizeof(ColorGraphic) * (n));                                           \
    g = gStaticGraphic(ofs);                                                      \
    fn(g, (void*)((wStaticGraphicTilenums[(n)] - g->tileId) * 32 + 0x10000));     \
    pal = gStaticPalette(ofs);                                                    \
    LoadPalette(pal, (wStaticMotionPalIDs[(n)] - pal->dst) * 32 + PLTT_SIZE / 2); \
  }

#define LOAD_STATIC_GRAPHIC(n) STATIC_GRAPHIC_LOADER(LoadGraphic, n)
#define REQUEST_STATIC_GRAPHIC(n) STATIC_GRAPHIC_LOADER(RequestGraphicTransfer, n)

#endif  // GUARD_RMZ3_ANIM_LOADER_H
