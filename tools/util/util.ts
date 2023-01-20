export const rgb555To888 = (rgb555: number): [number, number, number] => {
  const r5 = rgb555 & 0b11111;
  const g5 = (rgb555 >> 5) & 0b11111;
  const b5 = (rgb555 >> 10) & 0b11111;

  // 5bit color: abcde -> 8bit color: abcde abc
  const r = (r5 << 3) | (r5 >> 2);
  const g = (g5 << 3) | (g5 >> 2);
  const b = (b5 << 3) | (b5 >> 2);
  return [r, g, b];
};

export const toHex = (val: number, maxLength: number, prefix = ""): string => {
  return prefix + (val).toString(16).toUpperCase().padStart(maxLength, "0");
};

/**
 * Decompresse LZ77 compressed data.
 * @param data Original binary. Normally, this is GBA ROM data
 * @param addr Offset for compressed data in `data`
 * @returns `[decompressed_data_binary, compressed_data_size]`
 */
export const decompressLZ77 = (
  data: Uint8Array,
  addr: number,
): [Uint8Array, number] => {
  const oldAddr = addr;
  const id = data[addr++];
  if (id !== 0x10) {
    return [new Uint8Array(0), 0];
  }
  const decompressedSize = data[addr] | (data[addr + 1] << 8) |
    (data[addr + 2] << 16);
  addr += 3;
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
      flags = data[addr++] & 0xff;
      mask = 0x80;
    } else {
      mask = mask >> 1;
    }

    if ((flags & mask) > 0) {
      const byte1 = data[addr++];
      const byte2 = data[addr++];
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
      const next = data[addr++];
      currentOutsize++;
      result[resultOfs++] = next;
      buffer[bufferOffset] = next;
      bufferOffset = (bufferOffset + 1) % BUFFER_LENGTH;
    }
  }

  return [result, addr - oldAddr];
};
