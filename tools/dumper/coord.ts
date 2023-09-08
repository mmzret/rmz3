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
  for (let i = 0; i < length; i++) {
    const addr = start + (i * SIZE);
    const x = toHex(loadI32(rom, addr + 0, BASE), 8, '0x');
    const y = toHex(loadI32(rom, addr + 4, BASE), 8, '0x');
    console.log(`{${x}, ${y}},`);
  }
};

main();
