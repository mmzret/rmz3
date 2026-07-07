export * from './parser.ts';
export * from './entity.ts';
export * from './gba.ts';
export * from './rmz3.ts';

export type Nullable<T> = T | null | undefined;
export type BitField = Record<number, string>;

export const ROM_PATH = 'baserom.gba';
export const SEPARATOR = '@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@';

export const toHex = (val: number, maxLength: number, prefix = ''): string => {
  const abs = Math.abs(val);
  let s = abs.toString(16).toUpperCase().padStart(maxLength, '0');
  if (prefix) {
    if (val < 0) s = `-${prefix}${s}`;
    if (val >= 0) s = `${prefix}${s}`;
  }
  return s;
};

export const pad100 = (n: number): string => {
  return `${n < 100 ? '0' : ''}${n < 10 ? '0' : ''}${n}`;
};

export const camelToSnakeCase = (str: string) => str[0].toLowerCase() + str.slice(1, str.length).replace(/[A-Z]/g, (letter) => `_${letter.toLowerCase()}`);

export const Coord = (c: number): string => {
  const tmp = c >> 8;
  const result = (tmp >= 0) ? `${tmp}*PX` : `-${-tmp}*PX`;
  return result;
};

export const dumpBitField = (val: number, bitField: BitField): string => {
  const flags: string[] = [];
  Object.entries(bitField).forEach(([key, name]) => {
    const bit = Number(key);
    if (val & (1 << bit)) {
      flags.push(name);
      val &= ~(1 << bit);
    }
  });
  if (val !== 0) {
    console.warn(`Warning: Unknown bit(s) set: 0x${toHex(val, 8)}`);
  }
  return flags.join(' | ') || '0';
};
