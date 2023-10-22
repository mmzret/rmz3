import { Parser } from 'npm:binary-parser@2.2.1';

export const CoordParser = new Parser().endianness('little').int32('x').int32('y');
export const Rect = new Parser().endianness('little').int16('x').int16('y')
  .int16('w').int16('h');
