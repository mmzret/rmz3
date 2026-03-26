#!/usr/bin/env -S deno run --allow-read

import { Command } from '@cliffy/command';
import { loadI16, loadI32, toHex } from '../common/index.ts';

const ROM_PATH = 'baserom.gba';
const BASE = 0x0800_0000;

const Subcommands = {
  // e.g. ./tools/dumper/dump.ts pixel 0x0833ecec 4 -w=16 > result.txt
  //       -> "PIXEL(0), PIXEL(0), -PIXEL(16), PIXEL(16),"
  'pixel': new Command().name('pixel')
    .description(`開始アドレス(start) から 長さNだけ、PIXEL(xx) としてダンプします。`)
    .argument('<start_addr:string>', '開始アドレス')
    .argument('<length:number>', 'エントリ数 (ビット幅が32なら エントリ数 x 4 バイトがダンプされる)')
    .option('-w, --width=[n:number]', 'エントリのビット幅 (s32 か s16)', { default: 32 })
    .option('--columns=[n:number]', '1行あたりのエントリ数', { default: 4 })
    .option('--coord32', 'Coord[エントリ数] としてダンプする (-w は無視される)')
    .action((options, start_addr: string, length: number) => {
      const isCoord32 = !!options.coord32; // {PIXEL(x1), PIXEL(y1)}, {PIXEL(x2), PIXEL(y2)}, ...}  の形式でダンプするかどうか
      const w = isCoord32 ? 32 : Number(options.width);
      const columns = Number(options.columns || 4);
      const rom = Deno.readFileSync(ROM_PATH);
      const start = Number(start_addr);
      const SIZE = w / 8;

      if (isCoord32) {
        length *= 2; // Coord[エントリ数] としてダンプする場合、x と y のペアで1エントリとみなすため、実際のエントリ数は倍になる
      }

      const pixels: string[] = [];

      for (let i = 0; i < length; i++) {
        let result: string;
        const addr = start + (i * SIZE);
        const val = w == 32 ? (loadI32(rom, addr, BASE)) : (loadI16(rom, addr, BASE));
        if ((val & 0xFF) === 0x00) {
          const pixel = val >> 8;
          result = (pixel >= 0) ? `PIXEL(${pixel})` : `-PIXEL(${-pixel})`;
        } else {
          result = toHex(val, w / 4, '0x');
        }
        pixels.push(result);
      }

      if (isCoord32) {
        let output = '';
        for (let i = 0; i < pixels.length; i += 2) {
          const x = pixels[i];
          const y = pixels[i + 1];
          output += `{${x}, ${y}}, `;
        }
        console.log(output);
        return;
      }

      let output = '';
      for (let i = 0; i < pixels.length; i++) {
        output += `${pixels[i]}, `;
        if ((i + 1) % columns === 0) {
          output += '\n';
        }
      }
      console.log(output);
    }),
};

const main = async () => {
  const { args, cmd } = await new Command()
    .name('dump.ts')
    .version('1.0.0')
    .command('pixel', Subcommands['pixel'])
    .parse(Deno.args);
  if (cmd.getParent()) return;

  // default command
  console.log('default');
};

main();
