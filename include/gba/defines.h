#ifndef GUARD_GBA_DEFINES
#define GUARD_GBA_DEFINES

#include <stddef.h>

#define TRUE 1
#define FALSE 0

#define BSS_DATA __attribute__((section(".bss")))

#define IWRAM_DATA __attribute__((section("iwram_data")))
#define EWRAM_DATA __attribute__((section("ewram_data")))

#define NAKED __attribute__((naked))
#define UNUSED __attribute__((unused))
#define PACKED __attribute__((packed))
#define LONGCALL __attribute__((long_call))

#if MODERN
#define FALLTHROUGH __attribute__((fallthrough));
#else
#define FALLTHROUGH
#endif

#define ALIGNED(n) __attribute__((aligned(n)))

extern struct SoundInfo *SOUND_INFO_PTR;

#define EWRAM 0x2000000
#define IWRAM 0x3000000

#define PLTT 0x5000000
#define PLTT_SIZE 0x400

#define BG_PLTT PLTT
#define BG_PLTT_SIZE 0x200

#define OBJ_PLTT (PLTT + 0x200)
#define OBJ_PLTT_SIZE 0x200

#define VRAM 0x6000000
#define VRAM_SIZE 0x18000

#define BG_VRAM VRAM
#define BG_VRAM_SIZE 0x10000
#define BG_CHAR_ADDR(n) (void *)(BG_VRAM + (0x4000 * (n)))
#define BG_SCREEN_ADDR(n) (void *)(BG_VRAM + (0x800 * (n)))
#define BG_TILE_ADDR(n) (void *)(BG_VRAM + (0x80 * (n)))

// text-mode BG
#define OBJ_VRAM0 (void *)(VRAM + 0x10000)
#define OBJ_VRAM0_SIZE 0x8000

// bitmap-mode BG
#define OBJ_VRAM1 (void *)(VRAM + 0x14000)
#define OBJ_VRAM1_SIZE 0x4000

#define OAM 0x7000000
#define OAM_SIZE 0x400

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 160

#define TILE_SIZE_4BPP 32
#define TILE_SIZE_8BPP 64

#define TOTAL_OBJ_TILE_COUNT 1024

#define RGB(r, g, b) ((r) | ((g) << 5) | ((b) << 10))

#define RGB_BLACK RGB(0, 0, 0)
#define RGB_WHITE RGB(31, 31, 31)

#define WIN_RANGE(a, b) (((a) << 8) | (b))

// Program logic is probably correct for NON_MATCH, but unknown for WIP.
#if MODERN
#define WIP
#define NON_MATCH
#define NORETURN __attribute__((noreturn))
#else
#define WIP __attribute__((naked))
#define NON_MATCH __attribute__((naked))
#define NORETURN
#endif

#define static_assert(cond) extern char assertion[(cond) ? 1 : -1]

#endif  // GUARD_GBA_DEFINES