#!/usr/bin/env -S deno run --allow-read --unstable

import { Command } from '@cliffy/command';
import { loadU32, toHex } from '../common/index.ts';

const BASE = 0x0800_0000;

const main = async () => {
  const { args } = await new Command()
    .name('mml.ts')
    .version('1.0.0')
    .description('Dump mml as asm byte data')
    .arguments('<addr> <length:number>')
    .usage('0x0833168b 181 > output.bin')
    .parse(Deno.args);

  const [start, length] = [Number(args[0]), args[1]];
  const rom = Deno.readFileSync('baserom.gba');

  let result = '';
  let prefix = true;
  for (let i = 0; i < length; i++) {
    const addr = start + i - BASE;
    const val = rom[addr];
    let hex = toHex(Math.abs(val), 2, '0x');
    if (val < 0) {
      hex = '-' + hex;
    }

    switch (val) {
      case 0xB1: {
        result += `\n  .byte FINE`;
        prefix = true;
        break;
      }
      case 0xB2: {
        result += `\n  .byte GOTO`;
        const arg = loadU32(rom, addr + 1);
        const delta = arg - (BASE + addr + 1);
        const dst = `.${delta > 0 ? '+' : '-'}${Math.abs(delta)}`;
        i += 4;
        result += `\n  .word ${dst}`;
        prefix = true;
        break;
      }
      case 0xB3: {
        result += `\n  .byte PATT`;
        const arg = loadU32(rom, addr + 1);
        const delta = arg - (BASE + addr + 1);
        const dst = `.${delta > 0 ? '+' : '-'}${Math.abs(delta)}`;
        i += 4;
        result += `\n  .word ${dst}`;
        prefix = true;
        break;
      }
      default: {
        if (prefix) {
          result += `\n  .byte ${hex}`;
          prefix = false;
        } else {
          result += `, ${hex}`;
        }
        break;
      }
    }
  }

  console.log(result);
};

main();
