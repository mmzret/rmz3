import { Parser } from '@binary-parser';

export const CoordParser = new Parser().endianness('little').int32('x').int32('y');
export const Rect = new Parser().endianness('little').int16('x').int16('y')
  .int16('w').int16('h');
