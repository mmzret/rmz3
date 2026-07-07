#!/usr/bin/env -S deno run --allow-read

import { Command } from '@cliffy/command';
import { addr, getS16, getS32, getS8, getU16, getU32, getU8, ROM_PATH, toHex } from '../common/index.ts';

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
  'u8': getU8,
  'u16': getU16,
  'u32': getU32,
  's8': getS8,
  's16': getS16,
  's32': getS32,
};

const Size = {
  'u8': '.byte',
  'u16': '.2byte',
  'u32': '.4byte',
  's8': '.byte',
  's16': '.2byte',
  's32': '.4byte',
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
    .argument('<addr:number>', '開始アドレス')
    .argument('<length:number>', 'エントリ数')
    .usage('0x085222a0 134 -f=u8 -m=c')
    .parse(Deno.args);

  const start: addr = Number(args[0]);
  const length: number = Number(args[1]);
  const format = options.format as Format;
  if (!IntTypes.includes(format)) {
    console.error(`Format(-f, --format) must be either of ${IntTypes}`);
    return;
  }

  const rom = new DataView(Deno.readFileSync(ROM_PATH).buffer);

  const column = options.width ? Number(options.width) : length;
  const mode = options.mode as string;
  const unit = Units[format];
  const load = Loader[format];
  const isDecimal = options.base === 10;

  let result = '';
  for (let i = 0; i < length; i++) {
    const addr: addr = start + (i * unit);
    const val = load(rom, addr);

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
