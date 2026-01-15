#!/usr/bin/env -S deno run --allow-read

import { Command } from '@cliffy/command';
import { loadI16, loadI32, loadI8, loadU16, loadU32, loadU8, toHex } from '../common/index.ts';

/*
  バイナリファイルからword(32bit)の配列をアセンブリ形式で(標準出力に)ダンプする
  例: rom.gba 0x085222a0 3
    .word xxxxxxxx @ 0x085222a0
    .word yyyyyyyy @ 0x085222a4
    .word zzzzzzzz @ 0x085222a8
*/

const IntTypes = ['u8', 'u16', 'u32', 's8', 's16', 's32'] as const;
type Format = typeof IntTypes[number];

const Units: Record<Format, number> = {
  'u8': 1,
  'u16': 2,
  'u32': 4,
  's8': 1,
  's16': 2,
  's32': 4,
};

const Loader = {
  'u8': loadU8,
  'u16': loadU16,
  'u32': loadU32,
  's8': loadI8,
  's16': loadI16,
  's32': loadI32,
};

const Size = {
  'u8': '.byte',
  'u16': '.hword',
  'u32': '.word',
  's8': '.byte',
  's16': '.hword',
  's32': '.word',
};

const main = async () => {
  const { options, args } = await new Command()
    .name('byte.ts')
    .version('1.0.0')
    .description('Dump byte sequence from binary')
    .option(
      '-f, --format=<s:string>',
      'data format (u8, u16, u32, s8, s16, s32)',
      { default: 'u8' },
    )
    .option('-b, --base=[b:number]', 'baseN(10 or 16)', { default: 16 })
    .option('-s, --small', 'dump non-capital Hex')
    .option('-m, --mode=[mode]', 'dump mode', { default: 'asm' })
    .option('-w, --width=[n]', 'a number of data by line')
    .option('--prefix=[p:string]', 'prefix of data')
    .option('-i, --index', "add index prefix as '[idx] = ' (only C)")
    .arguments('<rom> <addr> <length>')
    .usage('rmz3.gba 0x085222a0 134 -f=u8 -m=c')
    .parse(Deno.args);

  const [start, length] = [Number(args[1]), Number(args[2])];
  const format = options.format as Format;
  if (!IntTypes.includes(format)) {
    console.error(`Format(-f, --format) must be either of ${IntTypes}`);
    return;
  }

  const column = options.width ? Number(options.width) : length;
  const mode = options.mode as string;
  const unit = Units[format];
  const load = Loader[format];
  const isDecimal = options.base === 10;

  const rom = Deno.readFileSync(args[0]);

  let result = '';
  for (let i = 0; i < length; i++) {
    const addr = start + (i * unit);
    const val = load(rom, addr, 0x0800_0000);

    let hex = isDecimal ? Math.abs(val).toString(10) : toHex(Math.abs(val), unit * 2, '0x');
    if (options.small) {
      hex = hex.toLowerCase();
    }
    if (val < 0) {
      hex = '-' + hex;
    }

    switch (mode.toLowerCase()) {
      case 'asm': {
        if (i % column == 0) {
          result += `\n${Size[format]} ${hex}`;
        } else {
          result += `, ${hex}`;
        }
        break;
      }

      // "c"
      default: {
        if (i % column == 0) {
          result += `\n${options.index ? `[${i}] = ` : ''}${options.prefix ? options.prefix : ''}${hex}`;
          if (i % column == column - 1) result += `,`;
        } else {
          result += `, ${hex}`;
          if (i % column == column - 1) result += `,`;
        }
      }
    }
  }

  console.log(result);
};

main();
