#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from '@cliffy/command';
import { addr, getU16, ROM_PATH } from '../../common/index.ts';

// This script is write-off program for myself, so no longer needed
const main = async () => {
  const { args } = await new Command()
    .name('preload_entity.ts')
    .version('1.0.0')
    .description('List g<STAGE>Static')
    .arguments('<addr:string> <length:number>')
    .usage('0x08347f64 20')
    .parse(Deno.args);

  const rom8 = Deno.readFileSync(ROM_PATH);
  const rom = new DataView(rom8.buffer);
  const START: addr = Number(args[0]);
  const LENGTH = args[1];

  for (let i = 0; i < LENGTH; i++) {
    const start = START + (8 * i);
    console.log(`{
      ${rom8[start]},
      ${rom8[start + 1]},
      ${getU16(rom, start + 2)},
      ${rom8[start + 4]},
      ${rom8[start + 5]},
      ${rom8[start + 6]},
      ${rom8[start + 7]},
    },`);
  }
};

main();
