#ifndef GUARD_RMZ3_SYSTEM_H
#define GUARD_RMZ3_SYSTEM_H

#include "gba/types.h"

// Process.status
#define PROCESS_DISABLED (1 << 0)
#define PROCESS_OK (1 << 1)
#define PROCESS_SLEEP (1 << 2)
#define PROCESS_DISABLED_08 (1 << 3)

// GameLoop関数 (080021f4) でスケジューリングされる処理 Unixのプロセスに近い
struct Process {
  u8 status;
  bool8 doReset;  // true なら Process がスケジューリングされる直前に 080022b0 が呼び出される
  u16 sleep;      // フレームごとにデクリメントされていき、0になったら Process が実行される
  void* fn;       // Process がスケジューリングされる際に 実際に行う処理
  u16* sp;        // この Process 用の sp
  u8 unk_0c[4];
  u8 unk_10[8];
};  // 24 bytes

struct TransferReservation {
  void* start;
  u16* dst;
  u32 count;
  u16* src;
  void* DMA0SAD;
  void* DMA0DAD;
  void* DMA0CNT;
  s16 delta_src;
  s16 delta_dst;
  u16 remaining;
  u16 _;
};  // 36 bytes

// Malloc(0x08001b14)で確保される汎用メモリ領域(0x03000380)
struct SystemBuffer {
  u32 buf[2][576];
  u16 ofs;  // buf[.idx]で空の領域の先頭を指す
  u16 idx;  // buf0とbuf1のどっちを使っているか
};

// 0x03001590
struct InterruptManager {
  VoidFunc table[14];  // 0x080fec74 の内容がコピーされる
  u32 main[72];        // IntrMain(0x080001bc) が ここにコピーされる
  VoidFunc vblankCallback;
  VoidFunc hblankCallback;
  u32 frame;         // ゲーム開始時から経過したフレーム数
  vu8 frame2;        // ゲーム速度コントロール用のフレームカウンタ, VBlank割り込みのたびにインクリメントされる
  u8 slowGameRatio;  // この値をxにするとゲームスピードが 1/x になる
  u8 lyc;
  u8 intrLock;
  u32 dma0[3];
  u32 reservedDma0[3];
  struct TransferReservation tr[2];
};

// 0x03001760
struct ProcessManager {
  // Stack buffer for Proc N
  u8 stack[1248 + 2304 + 1280 + 32];
  u32 masterFrame;  // ゲーム起動してから経過したフレーム(ソフトリセットしてもクリアされない)
  bool32 systemOK;  // Falseにするとゲームがクラッシュ
  struct Process processes[3];
  u32 procID;  // 現在実行されている .processes の idx(0, 1, 2)
  u8 _[12];
};

extern void* StackFramePointer;
extern struct SystemBuffer gSystemBuffer;
extern const VoidFunc HBlankIntrs[3];
extern struct InterruptManager gIntrManager;
extern u32 u32_020014e0;
extern struct ProcessManager gProcessManager;
extern const u16 gProcessStackPointerOffsets[3];

void ResetProcess(s32 i, void* fn);
void Process_SoftReset(struct Process* _);
void Process_System(struct Process* p);
void _usrHBlankCallback(void);
void LinkVSync(void);
void FUN_080044a0(void);
void disableProcess(s32 i);
void SwitchProcess(bool32 b);
void ExitProcess(void);
void FUN_08002428(struct Process* p);
void Transfer30Bytes(void* src, void* dst, u32 bytesize);
void FillMemory(u16 fillval, u16* dst, u32 bytesize);

/*
処理内容:
  1. r13 = StackFramePointer (0x02000000)
  2. r4,r5,r6,r7,r8,r9,r10,r11 を pop (r13 が r0 なことに注意)
  3. r3 (値: 08002253) を pop し lr　に格納して lr (08002253) にジャンプ
*/
void ReturnToGameLoop(void* p);

/*
現在の実行状況を保存して、callProcess からリターンする関数
次にこの Process が実行される際は、 lr (この関数の戻り先) から再開される

1. r4,r5,r6,r7,r8,r9,r10,r11 を push
2. *fn = lr, *sp = r13
3. r13 = wStackPointer
4. r4,r5,r6,r7,r8,r9,r10,r11 を pop (spが StackFramePointer になっていることに注意)
5. r3(callProcessのlr) を pop し、callProcess の呼び出し元へリターン
*/
void returnCallProcess(u32* fn, u32* sp, void* lr);
void exec(void* fn);
void CallProcess(struct Process* proc, void* fn, void* sp, void* pSp);

void _transferByHand(struct TransferReservation* t);

#endif  // GUARD_RMZ3_SYSTEM_H
