#ifndef GUARD_GBA_MACRO_H
#define GUARD_GBA_MACRO_H

#define CPU_FILL(value, dest, size, bit)                                                                  \
  {                                                                                                       \
    vu##bit tmp = (vu##bit)(value);                                                                       \
    CpuSet((void *)&tmp, dest, CPU_SET_##bit##BIT | CPU_SET_SRC_FIXED | ((size) / (bit / 8) & 0x1FFFFF)); \
  }

#define CpuFill16(value, dest, size) CPU_FILL(value, dest, size, 16)
#define CpuFill32(value, dest, size) CPU_FILL(value, dest, size, 32)

#define CPU_COPY(src, dest, bytesize, bit) CpuSet(src, dest, CPU_SET_##bit##BIT | ((bytesize) / (bit / 8) & 0x1FFFFF))

#define CpuCopy16(src, dest, bytesize) CPU_COPY(src, dest, bytesize, 16)
#define CpuCopy32(src, dest, bytesize) CPU_COPY(src, dest, bytesize, 32)

#define CpuFastFill(value, dest, bytesize)                                                       \
  {                                                                                              \
    vu32 tmp = (vu32)(value);                                                                    \
    CpuFastSet((void *)&tmp, dest, CPU_FAST_SET_SRC_FIXED | ((bytesize) / (32 / 8) & 0x1FFFFF)); \
  }

#define CpuFastFill16(value, dest, size) CpuFastFill(((value) << 16) | (value), (dest), (size))

#define CpuFastCopy(src, dest, bytesize) CpuFastSet(src, dest, ((bytesize) / (32 / 8) & 0x1FFFFF))

#define DmaSet(dmaNum, src, dest, control)        \
  {                                               \
    vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA##dmaNum; \
    dmaRegs[0] = (vu32)(src);                     \
    dmaRegs[1] = (vu32)(dest);                    \
    dmaRegs[2] = (vu32)(control);                 \
    dmaRegs[2];                                   \
  }

#define DMA_FILL(dmaNum, value, dest, size, bit)                                                                                           \
  {                                                                                                                                        \
    vu##bit tmp = (vu##bit)(value);                                                                                                        \
    DmaSet(dmaNum, &tmp, dest, (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_FIXED | DMA_DEST_INC) << 16 | ((size) / (bit / 8))); \
  }

#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)

// Note that the DMA clear macros cause the DMA control value to be calculated
// at runtime rather than compile time. The size is divided by the DMA transfer
// unit size (2 or 4 bytes) and then combined with the DMA control flags using a
// bitwise OR operation.

#define DMA_CLEAR(dmaNum, dest, size, bit) \
  {                                        \
    vu##bit *_dest = (vu##bit *)(dest);    \
    u32 _size = size;                      \
    DmaFill##bit(dmaNum, 0, _dest, _size); \
  }

#define DmaClear16(dmaNum, dest, size) DMA_CLEAR(dmaNum, dest, size, 16)
#define DmaClear32(dmaNum, dest, size) DMA_CLEAR(dmaNum, dest, size, 32)

#define DMA_COPY(dmaNum, src, dest, size, bit) DmaSet(dmaNum, src, dest, (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_INC | DMA_DEST_INC) << 16 | ((size) / (bit / 8)))

#define DmaCopy16(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 16)
#define DmaCopy32(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 32)

#define DmaStop(dmaNum)                                         \
  {                                                             \
    vu16 *dmaRegs = (vu16 *)REG_ADDR_DMA##dmaNum;               \
    dmaRegs[5] &= ~(DMA_START_MASK | DMA_DREQ_ON | DMA_REPEAT); \
    dmaRegs[5] &= ~DMA_ENABLE;                                  \
    dmaRegs[5];                                                 \
  }

#define DmaCopyLarge(dmaNum, src, dest, size, block, bit) \
  {                                                       \
    const void *_src = src;                               \
    void *_dest = (void *)(dest);                         \
    u32 _size = size;                                     \
    while (1) {                                           \
      DmaCopy##bit(dmaNum, _src, _dest, (block));         \
      _src += (block);                                    \
      _dest += (block);                                   \
      _size -= (block);                                   \
      if (_size <= (block)) {                             \
        DmaCopy##bit(dmaNum, _src, _dest, _size);         \
        break;                                            \
      }                                                   \
    }                                                     \
  }

#define DmaClearLarge(dmaNum, dest, size, block, bit) \
  {                                                   \
    void *_dest = dest;                               \
    u32 _size = size;                                 \
    while (1) {                                       \
      DmaFill##bit(dmaNum, 0, _dest, (block));        \
      _dest += (block);                               \
      _size -= (block);                               \
      if (_size <= (block)) {                         \
        DmaFill##bit(dmaNum, 0, _dest, _size);        \
        break;                                        \
      }                                               \
    }                                                 \
  }

#define DmaCopyLarge16(dmaNum, src, dest, size, block) DmaCopyLarge(dmaNum, src, dest, size, block, 16)
#define DmaCopyLarge32(dmaNum, src, dest, size, block) DmaCopyLarge(dmaNum, src, dest, size, block, 32)

#define DmaClearLarge16(dmaNum, dest, size, block) DmaClearLarge(dmaNum, dest, size, block, 16)
#define DmaClearLarge32(dmaNum, dest, size, block) DmaClearLarge(dmaNum, dest, size, block, 32)

#define DmaCopyDefvars(dmaNum, src, dest, size, bit) \
  {                                                  \
    const void *_src = src;                          \
    void *_dest = (void *)(dest);                    \
    u32 _size = size;                                \
    DmaCopy##bit(dmaNum, _src, _dest, _size);        \
  }

#define DmaCopy16Defvars(dmaNum, src, dest, size) DmaCopyDefvars(dmaNum, src, dest, size, 16)
#define DmaCopy32Defvars(dmaNum, src, dest, size) DmaCopyDefvars(dmaNum, src, dest, size, 32)

#define DmaFillLarge(dmaNum, fillval, dest, size, block, bit) \
  {                                                           \
    void *_dest = (void *)(dest);                             \
    u32 _size = (u32)(size);                                  \
    while (1) {                                               \
      DmaFill##bit(dmaNum, fillval, _dest, (block));          \
      _dest += (block);                                       \
      _size -= (block);                                       \
      if (_size <= (block)) {                                 \
        DmaFill##bit(dmaNum, fillval, _dest, _size);          \
        break;                                                \
      }                                                       \
    }                                                         \
  }

#define DmaFill16Large(dmaNum, fillval, dest, size, block) DmaFillLarge(dmaNum, fillval, dest, size, block, 16)
#define DmaFill32Large(dmaNum, fillval, dest, size, block) DmaFillLarge(dmaNum, fillval, dest, size, block, 32)

#define DmaFillDefvars(dmaNum, fillval, dest, size, bit) \
  {                                                      \
    void *_dest = (void *)(dest);                        \
    u32 _size = (u##bit)(size);                          \
    DmaFill##bit(dmaNum, fillval, _dest, _size);         \
  }

#define DmaFill16Defvars(dmaNum, fillval, dest, size) DmaFillDefvars(dmaNum, fillval, dest, size, 16)
#define DmaFill32Defvars(dmaNum, fillval, dest, size) DmaFillDefvars(dmaNum, fillval, dest, size, 32)

// from pokeemerald
// Maximum amount of data we will transfer in one operation
#define MAX_DMA_BLOCK_SIZE 0x1000

#define MAX_DMA_REQUESTS 128

#define DMA_REQUEST_COPY32 1
#define DMA_REQUEST_FILL32 2
#define DMA_REQUEST_COPY16 3
#define DMA_REQUEST_FILL16 4

#define Dma3CopyLarge_(src, dest, size, bit)            \
  {                                                     \
    const void *_src = src;                             \
    void *_dest = dest;                                 \
    u32 _size = size;                                   \
    while (1) {                                         \
      if (_size <= MAX_DMA_BLOCK_SIZE) {                \
        DmaCopy##bit(3, _src, _dest, _size);            \
        break;                                          \
      }                                                 \
      DmaCopy##bit(3, _src, _dest, MAX_DMA_BLOCK_SIZE); \
      _src += MAX_DMA_BLOCK_SIZE;                       \
      _dest += MAX_DMA_BLOCK_SIZE;                      \
      _size -= MAX_DMA_BLOCK_SIZE;                      \
    }                                                   \
  }

#define Dma3CopyLarge16_(src, dest, size) Dma3CopyLarge_(src, dest, size, 16)
#define Dma3CopyLarge32_(src, dest, size) Dma3CopyLarge_(src, dest, size, 32)

#define Dma3FillLarge_(value, dest, size, bit)           \
  {                                                      \
    void *_dest = dest;                                  \
    u32 _size = size;                                    \
    while (1) {                                          \
      if (_size <= MAX_DMA_BLOCK_SIZE) {                 \
        DmaFill##bit(3, value, _dest, _size);            \
        break;                                           \
      }                                                  \
      DmaFill##bit(3, value, _dest, MAX_DMA_BLOCK_SIZE); \
      _dest += MAX_DMA_BLOCK_SIZE;                       \
      _size -= MAX_DMA_BLOCK_SIZE;                       \
    }                                                    \
  }

#define Dma3FillLarge16_(value, dest, size) Dma3FillLarge_(value, dest, size, 16)
#define Dma3FillLarge32_(value, dest, size) Dma3FillLarge_(value, dest, size, 32)

#endif  // GUARD_GBA_MACRO_H