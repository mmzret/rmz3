export * from './load.ts';
export * from './parser.ts';
export * from './types.ts';

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
