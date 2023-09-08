export * from './load.ts';
export * from './parser.ts';
export * from './types.ts';

export const toHex = (val: number, maxLength: number, prefix = ''): string => {
  const abs = Math.abs(val);
  let s = (abs).toString(16).toUpperCase().padStart(maxLength, '0');
  if (prefix) {
    if (val < 0) s = `-${prefix}${s}`;
    if (val >= 0) s = `${prefix}${s}`;
  }
  return s;
};

export const pad100 = (n: number): string => {
  return `${n < 100 ? '0' : ''}${n < 10 ? '0' : ''}${n}`;
};
