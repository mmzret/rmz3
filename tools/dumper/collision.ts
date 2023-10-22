#!/usr/bin/env -S deno run --allow-read --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { Parser } from 'npm:binary-parser@2.2.1';
import { Rect, toHex } from '../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 24;
const KIND = ['DDP', 'DRP', 'DRP2'];
const FACTION = ['FACTION_ALLY', 'FACTION_ENEMY', 'FACTION_NEUTRAL'];
const SPECIAL = ['0', 'HALFABLE', 'CS_BOSS'];
const HARDNESS: Record<number, string> = {
  1: 'METAL',
  2: 'NO_DAMAGE',
  8: 'HARDNESS_B3',
};

const Collision = new Parser().endianness('little')
  .uint8('kind')
  .uint8('faction')
  .uint8('special')
  .uint8('damage')
  .uint8('atkType')
  .uint8('element')
  .uint8('nature')
  .uint8('comboLv')
  .uint8('hitzone')
  .uint8('hardness')
  .uint8('unk_0a')
  .uint8('remaining')
  .uint32('layer')
  .nest('range', { type: Rect });

type ParseResult = {
  kind: number;
  faction: number;
  special: number;
  damage: number;
  atkType: number;
  element: number;
  nature: number;
  comboLv: number;
  hitzone: number;
  hardness: number;
  unk_0a: number;
  remaining: number;
  layer: number;
  range: {
    w: number;
    h: number;
    x: number;
    y: number;
  };
};

const main = async () => {
  const { args, options } = await new Command()
    .name('collision.ts')
    .version('1.0.0')
    .description(`En: Dump Collision C struct array from <start>\nJa: 開始アドレス(start) から 長さNだけ、 C言語のCollision構造体としてダンプします。`)
    .arguments('<start> <length:number>')
    .option('-i, --index', 'add index prefix as \'[idx] = \'')
    .usage('0x08361c68 15')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]);
  const length = args[1];

  console.log(`static const struct Collision sCollisions[${length}] = {`);
  for (let i = 0; i < length; i++) {
    const addr = start + (i * SIZE) - BASE;
    const result = Collision.parse(rom.slice(addr, addr + SIZE)) as ParseResult;
    const collision = {
      atkType: `0x${toHex(result.atkType, 2)}`,
      element: `0x${toHex(result.element, 2)}`,
      nature: `0x${toHex(result.nature, 2)}`,
      hardness: HARDNESS[result.hardness] ?? String(result.hardness),
      unk_0a: `0x${toHex(result.unk_0a, 2)}`,
      layer: `0x${toHex(result.layer, 8)}`,
      rect_0: result.range.x >> 8,
      rect_1: result.range.y >> 8,
      rect_2: result.range.w >> 8,
      rect_3: result.range.h >> 8,
    };

    const layerName = result.kind === 1 ? `priorityLayer` : `layer`;
    console.log(`${options.index ? `[${i}] = ` : ''}{`);
    console.log(`    kind: ${KIND[result.kind]},`);
    console.log(`    faction: ${FACTION[result.faction]},`);
    if (result.special !== 0) console.log(`    special: ${SPECIAL[result.special] ?? result.special},`);
    if (result.damage !== 0) console.log(`    damage: ${result.damage},`);

    switch (KIND[result.kind]) {
      case 'DRP2':
      case 'DDP': {
        if (result.atkType !== 0) console.log(`    atkType: ${collision.atkType},`);
        if (result.element !== 0) console.log(`    element: ${collision.element},`);
        if (result.nature !== 0) console.log(`    nature: ${collision.nature},`);
        if (result.comboLv !== 0) console.log(`    comboLv: ${result.comboLv},`);
        break;
      }
      case 'DRP': {
        let layerLo = result.atkType;
        layerLo |= result.element << 8;
        let layerHi = result.nature;
        layerHi |= result.comboLv << 8;
        console.log(`    LAYER(0x${toHex(layerHi, 4)}${toHex(layerLo, 4)}),`);
        break;
      }
    }

    if ((KIND[result.kind] !== 'DDP') || (result.hitzone !== 0)) console.log(`    hitzone: ${result.hitzone},`);
    if (result.hardness !== 0) console.log(`    hardness: ${collision.hardness},`);
    if (result.unk_0a !== 0) console.log(`    unk_0a: ${collision.unk_0a},`);
    console.log(`    remaining: ${result.remaining},`);
    if (result.layer !== 0) console.log(`    ${layerName}: ${collision.layer},`);

    console.log(`    range: {${collision.rect_0 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_0)}), ${collision.rect_1 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_1)}), ${collision.rect_2 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_2)}), ${collision.rect_3 < 0 ? '-' : ''}PIXEL(${Math.abs(collision.rect_3)})},`);
    console.log(`},`);
  }
  console.log('};');
};

main();
