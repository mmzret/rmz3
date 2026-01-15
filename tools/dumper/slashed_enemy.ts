#!/usr/bin/env -S deno run --allow-read --unstable

import { Command } from '@cliffy/command';
import { loadI16, loadU16, loadU8, toHex } from '../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 28;

const main = async () => {
  const { args, options } = await new Command()
    .name('slashed_enemy.ts')
    .version('1.0.0')
    .description('Dump SlashedEnemy C struct array from <start>')
    .arguments('<start> <length:number>')
    .option('-i, --index', "add index prefix as '[idx] = '")
    .usage('0x08366720 4')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]);
  const length = args[1];

  console.log(`static const struct SlashedEnemy sSlashedEnemies[${length}] = {`);
  for (let i = 0; i < length; i++) {
    const addr = start + (i * SIZE);
    const slashedEnemy = {
      m: toHex(loadU16(rom, addr, BASE), 4, '0x'),
      unk_02: [loadU8(rom, addr + 2, BASE), loadU8(rom, addr + 3, BASE)],
      c: [loadI16(rom, addr + 4, BASE), loadI16(rom, addr + 6, BASE)],
      d: [loadI16(rom, addr + 8, BASE), loadI16(rom, addr + 10, BASE)],
      unk_coord_0c: [loadI16(rom, addr + 12, BASE), loadI16(rom, addr + 14, BASE)],
      unk_10: [loadI16(rom, addr + 16, BASE), loadI16(rom, addr + 18, BASE)],
      unk_14: [loadU16(rom, addr + 20, BASE), loadU16(rom, addr + 22, BASE)],
      unk: [
        loadU8(rom, addr + 24, BASE),
        loadU8(rom, addr + 25, BASE),
        loadU8(rom, addr + 26, BASE),
        loadU8(rom, addr + 27, BASE),
      ],
    };
    console.log(`${options.index ? `[${i}] = ` : ''}{
    m: ${slashedEnemy.m},
    unk_02: {${slashedEnemy.unk_02[0]}, ${slashedEnemy.unk_02[1]}},
    c: {${toHex(slashedEnemy.c[0], 4, '0x')}, ${toHex(slashedEnemy.c[1], 4, '0x')}},
    d: {${toHex(slashedEnemy.d[0], 4, '0x')}, ${toHex(slashedEnemy.d[1], 4, '0x')}},
    unk_coord_0c: {${toHex(slashedEnemy.unk_coord_0c[0], 4, '0x')}, ${toHex(slashedEnemy.unk_coord_0c[1], 4, '0x')}},
    unk_10: {${toHex(slashedEnemy.unk_10[0], 4, '0x')}, ${toHex(slashedEnemy.unk_10[1], 4, '0x')}},
    unk_14: {${slashedEnemy.unk_14[0]}, ${slashedEnemy.unk_14[1]}},`);
    if (slashedEnemy.unk[0] !== 0 || slashedEnemy.unk[1] !== 0 || slashedEnemy.unk[2] !== 0 || slashedEnemy.unk[3] !== 0) {
      console.log(`    _: {${slashedEnemy.unk[0]}, ${slashedEnemy.unk[1]}, ${slashedEnemy.unk[2]}, ${slashedEnemy.unk[3]}},`);
    }
    console.log(`},`);
  }
  console.log('};');
};

main();
