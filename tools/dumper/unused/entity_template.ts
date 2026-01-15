#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from '@cliffy/command';

const BASE = 0x0800_0000;

const kind = [
  'ENTITY_PLAYER',
  'ENTITY_WEAPON',
  'ENTITY_BOSS',
  'ENTITY_ENEMY',
  'ENTITY_PROJECTILE',
  'ENTITY_VFX',
  'ENTITY_SOLID',
  'ENTITY_ITEM',
  'ENTITY_ELF',
  'ENTITY_WIDGET',
];

// This script is write-off program for myself, so no longer needed
const main = async () => {
  const { args } = await new Command()
    .name('entity_template.ts')
    .version('1.0.0')
    .description('List g<STAGE>Entity')
    .arguments('<addr:string> <length:number>')
    .usage('0x08347dcc 51')
    .parse(Deno.args);

  const rom = Deno.readFileSync('./baserom.gba');
  const START = Number(args[0]);
  const LENGTH = args[1];

  for (let i = 0; i < LENGTH; i++) {
    const start = START + (8 * i) - BASE;
    console.log(`[${i}] = {
      ${rom[start]},
      ${kind[rom[start + 1]] ?? rom[start + 1]},
      ${rom[start + 2]},
      ${rom[start + 3]},
      ${rom[start + 4]},
      ${rom[start + 5]},
      ${rom[start + 6]},
      ${rom[start + 7]},
    },`);
  }
};

main();
