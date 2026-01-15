#!/usr/bin/env -S deno run --allow-read

import { Command } from '@cliffy/command';
import { loadU32, toHex } from '../../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 4;

const main = async () => {
  const { args } = await new Command()
    .name('relative.ts')
    .version('1.0.0')
    .description('絶対アドレスのポインタテーブルを .+XX という再配置可能なasmテーブルとして出力します')
    .arguments('<rom> <start> <length:number>')
    .usage('rmz3.gba 0x085c0874 254')
    .parse(Deno.args);

  const rom = Deno.readFileSync(args[0]);
  const start = Number(args[1]);
  const length = args[2];
  for (let i = 0; i < length; i++) {
    const addr = start + (i * SIZE);
    const abs = loadU32(rom, addr + 0, BASE);
    const absHex = toHex(abs, 8, '0x');
    const relative = abs - addr;
    console.log(`  .4byte .+${relative} @ ${absHex}`);
  }
};

main();
