#!/usr/bin/env -S deno run --allow-read

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadI16, loadI32, toHex } from '../common/index.ts';

const BASE = 0x0800_0000;

const main = async () => {
  const { args, options } = await new Command()
    .name('coord.ts')
    .version('1.0.0')
    .description(`En: Dump Coord C struct array from <start>\nJa: 開始アドレス(start) から 長さNだけ、 C言語のCoord構造体としてダンプします。`)
    .arguments('<start> <length:number>')
    .option('-w, --width=[n:number]', 'a size', { default: 32 })
    .usage('0x08361dd0 5')
    .parse(Deno.args);

  const w = Number(options.width);
  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]);
  const length = args[1];
  const SIZE = w / 4;
  const TYPE_NAME = `Coord${w == 32 ? '' : w}`;

  console.log();
  if (length >= 5) console.log(`// clang-format off`);
  console.log(`static const struct ${TYPE_NAME} sCoords[${length}] = {`);
  for (let i = 0; i < length; i++) {
    let x, y: string;
    const addr = start + (i * SIZE);
    const xRaw = w == 32 ? (loadI32(rom, addr + 0, BASE)) : (loadI16(rom, addr + 0, BASE));
    const yRaw = w == 32 ? (loadI32(rom, addr + 4, BASE)) : (loadI16(rom, addr + 2, BASE));
    if (((xRaw & 0xFF) === 0x00) && ((yRaw & 0xFF) === 0x00)) {
      const pixel = [xRaw >> 8, yRaw >> 8];
      x = (pixel[0] >= 0) ? `PIXEL(${pixel[0]})` : `-PIXEL(${-pixel[0]})`;
      y = (pixel[1] >= 0) ? `PIXEL(${pixel[1]})` : `-PIXEL(${-pixel[1]})`;
    } else {
      x = toHex(xRaw, w / 4, '0x');
      y = toHex(yRaw, w / 4, '0x');
    }
    console.log(`    {${x}, ${y}},`);
  }
  console.log('};');
  if (length >= 5) console.log(`// clang-format on`);
};

main();
