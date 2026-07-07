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

extern struct SoundInfo* SOUND_INFO_PTR;

#define EWRAM 0x2000000
#define EWRAM_SIZE 0x40000
#define IWRAM 0x3000000
#define IWRAM_SIZE 0x8000

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
#define BG_CHAR_SIZE 0x4000
#define BG_SCREEN_SIZE 0x800
#define BG_CHAR_OFFSET(n) ((void*)(BG_CHAR_SIZE * (n)))
#define BG_CHAR_ADDR(n) ((void*)(BG_VRAM + (BG_CHAR_SIZE * (n))))
#define BG_SCREEN_ADDR(n) ((void*)(BG_VRAM + (BG_SCREEN_SIZE * (n))))
#define BG_TILE_ADDR(n) ((void*)(BG_VRAM + (0x80 * (n))))

// text-mode BG
#define OBJ_VRAM0 ((void*)(VRAM + 0x10000))
#define OBJ_VRAM0_SIZE 0x8000

// bitmap-mode BG
#define OBJ_VRAM1 ((void*)(VRAM + 0x14000))
#define OBJ_VRAM1_SIZE 0x4000

#define OAM 0x7000000
#define OAM_SIZE 0x400

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 160

#define TILE_SIZE_4BPP 32
#define TILE_SIZE_8BPP 64

#define TOTAL_OBJ_TILE_COUNT 1024

// NON_MATCH は　ロジックは合ってそうだが、レジスタ割り当てなどが合わない場合に使っていて、 modernビルドでコンパイル対象になります
// WIP は　ロジックも合ってなさそうだったり、文字通りdecomp途中の関数に使っていて、 modernビルドでもコンパイル対象になりません (そもそもコンパイル通る保証もないです、文字通り、WIPです)
// 中で使われている ALWAYS_FALSE は vscode が "#if 0" のときにコードをグレーアウトしてしまうのを防ぐためのもので、常に偽になるように意図的に定義していません
#define WIP __attribute__((naked))
#if MODERN
#define NON_MATCH
#define NORETURN __attribute__((noreturn))
#else
#define NON_MATCH __attribute__((naked))
#define NORETURN
#endif

#define static_assert(cond) extern char assertion[(cond) ? 1 : -1]

#endif  // GUARD_GBA_DEFINES
