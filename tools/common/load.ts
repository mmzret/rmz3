export const loadU8 = (
  src: Uint8Array,
  addr: number,
  start = 0,
): number => {
  const val = src[addr - start];
  return val;
};

export const loadI8 = (
  src: Uint8Array,
  addr: number,
  start = 0,
): number => {
  let result = loadU8(src, addr, start);
  if (result >= 0x80) {
    result -= 0x100;
  }
  return result;
};

export const loadU16 = (
  src: Uint8Array,
  addr: number,
  start = 0,
): number => {
  const lo = src[addr - start];
  const hi = src[addr + 1 - start];
  return lo | (hi << 8);
};

export const loadI16 = (
  src: Uint8Array,
  addr: number,
  start = 0,
): number => {
  let result = loadU16(src, addr, start);
  if (result >= 0x8000) {
    result -= 0x10000;
  }
  return result;
};

export const loadU32 = (
  src: Uint8Array,
  addr: number,
  start = 0,
): number => {
  const b0 = loadU8(src, addr, start);
  const b1 = loadU8(src, addr + 1, start);
  const b2 = loadU8(src, addr + 2, start);
  const b3 = loadU8(src, addr + 3, start);
  let result = (b3 << 24) | (b2 << 16) | (b1 << 8) | (b0 << 0);
  if (result < 0) {
    result += 0x1_0000_0000;
  }
  return result;
};

export const loadI32 = (
  src: Uint8Array,
  addr: number,
  start = 0,
): number => {
  let result = loadU32(src, addr, start);
  if (result >= 0x8000_0000) {
    result -= 0x1_0000_0000;
  }
  return result;
};
