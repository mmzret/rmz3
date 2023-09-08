#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadI16, loadI32, loadU16, toHex } from '../../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 8;

// This script is write-off program for myself, so no longer needed
const main = async () => {
  const { args } = await new Command()
    .name('entity_template_coord.ts')
    .version('1.0.0')
    .description('List gXXXEntityCoord')
    .arguments('<addr:string> <length:number>')
    .usage('0x08348004 69')
    .parse(Deno.args);

  const rom = Deno.readFileSync('./baserom.gba');
  const START = Number(args[0]);
  const LENGTH = args[1];

  for (let i = 0; i < LENGTH; i++) {
    const start = START + (SIZE * i) - BASE;
    const x = toHex(loadI32(rom, start), 8, '0x');
    const y = toHex(loadI16(rom, start + 4), 4, '0x');
    const idx = loadU16(rom, start + 6);
    console.log(`    [${i}] = { ${x}, ${y}, ${idx} },`);
  }
};

main();
