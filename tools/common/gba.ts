export type addr = number;

export const BASE: addr = 0x0800_0000;
export const VRAM: addr = 0x0600_0000;

export const getU8 = (rom: DataView, address: addr) => rom.getUint8(address - BASE);
export const getU16 = (rom: DataView, address: addr) => rom.getUint16(address - BASE, true);
export const getU32 = (rom: DataView, address: addr) => rom.getUint32(address - BASE, true);

export const getS8 = (rom: DataView, address: addr) => rom.getInt8(address - BASE);
export const getS16 = (rom: DataView, address: addr) => rom.getInt16(address - BASE, true);
export const getS32 = (rom: DataView, address: addr) => rom.getInt32(address - BASE, true);

export const getSlice = (rom: DataView, address: addr, bytesize: number): ArrayBufferLike => rom.buffer.slice(address - BASE, address - BASE + bytesize);

export type rgb555 = number;

export const getRGBg = (rgb555: rgb555): string => {
  const val = rgb555 & 0xFFFF;
  // if (val === 0) return 'RGB_BLACK';
  const r5 = String((val >> 0) & 0x1F).padStart(2);
  const g5 = String((val >> 5) & 0x1F).padStart(2);
  const b5 = String((val >> 10) & 0x1F).padStart(2);
  const macro = (val & (1 << 15)) ? 'RGBg' : 'RGB';
  return `${macro}(${r5}, ${g5}, ${b5})`; // RGB(r5, g5, b5) or RGBg(r5, g5, b5)
};

export const getRGB888 = (rgb555: rgb555): [number, number, number] => {
  const val = rgb555 & 0xFFFF;
  const r5 = (val >> 0) & 0x1F;
  const g5 = (val >> 5) & 0x1F;
  const b5 = (val >> 10) & 0x1F;
  return [color8(r5), color8(g5), color8(b5)];
};

export const color8 = (c5: number): number => (Math.floor((c5 * 255) / 31));

/**
 * Decompresse LZ77 compressed data.
 * @param srcbuf Compressed data
 * @returns `Uint8Array` of decompressed data
 */
export const decompressLZ77 = (srcbuf: ArrayBufferLike): ArrayBufferLike => {
  let ofs = 0;
  const src = new Uint8Array(srcbuf);
  const id = src[ofs++];
  if (id !== 0x10) {
    return new ArrayBuffer(0);
  }
  const decompressedSize = src[ofs] | (src[ofs + 1] << 8) | (src[ofs + 2] << 16);
  ofs += 3;
  const result = new Uint8Array(decompressedSize);
  let resultOfs = 0;

  const BUFFER_LENGTH = 0x1000;
  const buffer = new Uint8Array(BUFFER_LENGTH);
  let bufferOffset = 0;
  let currentOutsize = 0;
  let flags = 0;
  let mask = 1;

  while (currentOutsize < decompressedSize) {
    if (mask == 1) {
      flags = src[ofs++] & 0xff;
      mask = 0x80;
    } else {
      mask = mask >> 1;
    }

    if ((flags & mask) > 0) {
      const byte1 = src[ofs++];
      const byte2 = src[ofs++];
      const len = (byte1 >> 4) + 3;
      const disp = (((byte1 & 0xf) << 8) | byte2) + 1;
      if (disp > currentOutsize) {
        throw new Error(`Size Error: ${disp} > ${currentOutsize}`);
      }

      let bufIdx = bufferOffset + BUFFER_LENGTH - disp;
      for (let i = 0; i < len; i++) {
        const next = buffer[bufIdx % BUFFER_LENGTH];
        bufIdx++;
        result[resultOfs++] = next;
        buffer[bufferOffset] = next;
        bufferOffset = (bufferOffset + 1) % BUFFER_LENGTH;
      }
      currentOutsize += len;
    } else {
      const next = src[ofs++];
      currentOutsize++;
      result[resultOfs++] = next;
      buffer[bufferOffset] = next;
      bufferOffset = (bufferOffset + 1) % BUFFER_LENGTH;
    }
  }

  return result.buffer;
};
