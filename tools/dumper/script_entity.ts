#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from '@cliffy/command';
import { Parser } from '@binary-parser';
import { CoordParser, toHex } from '../common/index.ts';

const BASE = 0x0800_0000;
const SIZE = 16;
const ROM = 'baserom.gba';

const ScriptEntityTemplate = new Parser().endianness('little')
  .uint8('kind')
  .uint8('variant')
  .uint8('unk_02')
  .uint8('unk_03')
  .nest('coord', { type: CoordParser })
  .uint32('flag');

const main = async () => {
  const { args } = await new Command()
    .name('script_entity.ts')
    .version('1.0.0')
    .description('Parser for ScriptEntityTemplate struct')
    .arguments('<start> <length:number>')
    .usage('0x08350b98 15')
    .parse(Deno.args);

  const rom = Deno.readFileSync(ROM);
  const [start, len] = [Number(args[0]), Number(args[1])];

  for (let i = 0; i < len; i++) {
    console.log('');
    const addr = start + (i * SIZE) - BASE;
    const result = ScriptEntityTemplate.parse(rom.slice(addr, addr + SIZE));
    console.log(`Entity_${toHex(start + (i * SIZE), 8).toLowerCase()}:`);
    switch (result.kind) {
      case 0: {
        console.log(`  .byte PLAYER, ZERO, 0, 0`);
        break;
      }
      case 2: {
        console.log(`  .byte BOSS, ${result.variant}, ${result.unk_02}, ${result.unk_03}`);
        break;
      }
      case 6: {
        const kind = (result.variant === 21) ? 'SOLID_SCRIPT_ACTOR' : `${result.variant}`;
        console.log(`  .byte SOLID, ${kind}, ${result.unk_02}, ${result.unk_03}`);
        break;
      }
      default: {
        console.log(`  .byte ${result.kind}, ${result.variant}, ${result.unk_02}, ${result.unk_03}`);
        break;
      }
    }
    const pixel = [result.coord.x >> 8, result.coord.y >> 8];
    const x = (pixel[0] >= 0) ? `${pixel[0]}*PX` : `-${-pixel[0]}*PX`;
    const y = (pixel[1] >= 0) ? `${pixel[1]}*PX` : `-${-pixel[1]}*PX`;
    console.log(`  .4byte ${x}, ${y}`);
    switch (result.flag) {
      case 0x0: {
        console.log(`  .4byte DIR_LEFT`);
        break;
      }
      case 0x1: {
        console.log(`  .4byte DIR_RIGHT`);
        break;
      }
      default: {
        console.log(`  .4byte 0x${toHex(result.flag, 8)}`);
        break;
      }
    }
  }
};

main();
