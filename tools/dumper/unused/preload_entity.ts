#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadU16 } from '../../common/index.ts';

const BASE = 0x0800_0000;

// This script is write-off program for myself, so no longer needed
const main = async () => {
  const { args } = await new Command()
    .name('preload_entity.ts')
    .version('1.0.0')
    .description('List g<STAGE>Static')
    .arguments('<addr:string> <length:number>')
    .usage('0x08347f64 20')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const START = Number(args[0]);
  const LENGTH = args[1];

  for (let i = 0; i < LENGTH; i++) {
    const start = START + (8 * i) - BASE;
    console.log(`{
      ${rom[start]},
      ${rom[start + 1]},
      ${loadU16(rom, start + 2)},
      ${rom[start + 4]},
      ${rom[start + 5]},
      ${rom[start + 6]},
      ${rom[start + 7]},
    },`);
  }
};

main();
