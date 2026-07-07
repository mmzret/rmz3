import { addr } from './gba.ts';

export const gStaticMotionGraphics: addr = 0x085d78f8;
export const gElfMugshotGraphics: addr = 0x08635f24;
export const gStageTilesetOffsets: addr = 0x087044b0;

export const sizeof = {
  Graphic: 12,
  Palette: 8,
  ColorGraphic: 12 + 8,
};
