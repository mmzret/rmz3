# スケジューラ

ゼロ3 では プロセスの協調的スケジューリング を 行っています。

アドレス `03002a68` には、プロセスを表す構造体が格納された、長さ3の配列が格納されています。(構造体のサイズは24バイトです)

つまり、ゼロ3 では 3つのプロセスがスケジュールされています。プロセスを表す構造体(`Process`)は次のようになっています。

```c
struct Process {
    enum ProcessStatus status;
    bool8 doReset;
    u16 sleep;
    u16 * fn;                   // Addr to jump to when the process is scheduled.
    u16 * sp;                   // Saved stack pointer
    u8 field5_0xc[4];           // Unused?
    u8 field6_0x10[8];          // Unused?
};

typedef enum ProcessStatus {
    DISABLE=1,                  // If this flag is set, the process will never be executed.
    OK=2,                       // If DISABLE is cleared, the process is executed by the scheduler if this flag is set.
    SLEEP=4,                    // When this flag is set (and OK is cleared), if proc->sleep is non-zero, no scheduling is done. proc->sleep is decremented every frame.
    DISABLE_08=8                // Unused flag(always 0)
} ProcessStatus;
```

また、どのプロセスが配列の何番目にあるかはあらかじめ決まっています。

```
  proc0: SoftResetProcess(0800187c), IntroProcess(080eb8b8)
  proc1: MainProcess (080edfd8)
  proc2: SystemProcess (08001978)
```

これらは`GameLoop`関数（`080021f4`）によってスケジューリングされます。(以後、`GameLoop`関数はスケジューラと呼びます)

各プロセスはそれぞれスタックを持っており、スケジューラがプロセスを切り替えるとスタックも切り替わります。

もちろん、GBAはシングルコアなので、スケジューラとプロセスは並列に動作させることはできません。プロセスは`0x08000300`に存在する関数を呼び出すことで、CPUをスケジューラに返却します。
