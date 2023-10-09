#!/usr/bin/env -S deno run --allow-read --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadI32, toHex } from '../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 8;

const main = async () => {
  const { args } = await new Command()
    .name('coord.ts')
    .version('1.0.0')
    .description(`En: Dump Coord C struct array from <start>\nJa: 開始アドレス(start) から 長さNだけ、 C言語のCoord構造体としてダンプします。`)
    .arguments('<start> <length:number>')
    .usage('0x08361dd0 5')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]);
  const length = args[1];

  console.log();
  if (length >= 5) console.log(`// clang-format off`);
  console.log(`static const struct Coord sCoords[${length}] = {`);
  for (let i = 0; i < length; i++) {
    let x, y: string;
    const addr = start + (i * SIZE);
    const xRaw = loadI32(rom, addr + 0, BASE);
    const yRaw = loadI32(rom, addr + 4, BASE);
    if (((xRaw & 0xFF) === 0x00) && ((yRaw & 0xFF) === 0x00)) {
      const pixel = [xRaw >> 8, yRaw >> 8];
      x = (pixel[0] >= 0) ? `PIXEL(${pixel[0]})` : `-PIXEL(${-pixel[0]})`;
      y = (pixel[1] >= 0) ? `PIXEL(${pixel[1]})` : `-PIXEL(${-pixel[1]})`;
    } else {
      x = toHex(xRaw, 8, '0x');
      y = toHex(yRaw, 8, '0x');
    }
    console.log(`    {${x}, ${y}},`);
  }
  console.log('};');
  if (length >= 5) console.log(`// clang-format on`);
};

main();
