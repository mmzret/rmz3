## Cooperative scheduling

MegamanZero3 has a cooperative process scheduling system.

Address `03002a68` contains an array of structures representing the process. The size of the structure is 24 bytes and the length of the array is 3. 

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

In an array of processes(`03002a68`), the use of each element is already determined.

```
  proc0: SoftResetProcess(0800187c), IntroProcess(080eb8b8)
  proc1: MainProcess (080edfd8)
  proc2: SystemProcess (08001978)
```

They are scheduled by the GameLoop function (Address: `080021f4`). For convenience, the GameLoop function is referred to as the scheduler.

Each process has its own stack, and when the scheduler switches processes, it also switches stacks.

Of course, the GBA is single-core, so the scheduler and processes cannot run in parallel. The process returns the CPU to the scheduler by calling the function present in `08000300`.
