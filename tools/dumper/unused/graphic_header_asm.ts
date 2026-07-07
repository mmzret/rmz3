#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from '@cliffy/command';
import { getU16, getU32, getU8, toHex } from '../../common/index.ts';

const GBAGFX = './tools/gbagfx/gbagfx';

const template = `    graphic [
        src: 0x085d8cd0,
        size: 2816,
        ofs: 160,
        chunk_size: 0x638,
        props: (LZ77 | BPP4)
    ]
    palette [
        src: 0x085d97d0,
        length: 32,
        lz77: 0,
        dst: 14
    ]
`;

const main = async () => {
  const { args, options } = await new Command()
    .name('gfx.ts')
    .version('1.0.0')
    .description(
      `Graphic構造体 の配列の先頭アドレスと、配列の長さを与えると asm用にヘッダーを標準出力にダンプします。`,
    )
    .arguments('<rom:string> <addr:string> <length:number>')
    .option('--nopal', 'graphic header only')
    .option('--label', 'add label for each graphic header')
    .usage('rmz3.gba 0x085d78f8 254')
    .parse(Deno.args);

  const rom = new DataView(Deno.readFileSync(args[0]).buffer);
  const start = Number(args[1]);
  const length = Number(args[2]);

  for (let i = 0; i < length; i++) {
    const addr = start + (i * (options.nopal ? 12 : 20));

    const gfx = {
      srcrel: getU32(rom, addr),
      srcabs: getU32(rom, addr) + addr,
      size: getU32(rom, addr + 4) & 0x3FFFFF,
      ofs: getU16(rom, addr + 6) >> 6,
      chunk: getU16(rom, addr + 8),
      props: getU16(rom, addr + 10),
      palrel: getU32(rom, addr + 12),
      palabs: getU32(rom, addr + 12) + (addr + 12),
      palLength: getU16(rom, addr + 16) / 2,
      palLz77: getU8(rom, addr + 18),
      dst: getU8(rom, addr + 19),
    };

    const printProps = (props: number) => {
      if (props === 0x22) return '(LZ77 | BPP4)';
      if (props === 0x26) return '(LZ77 | BPP4 | NO_PAL)';
      if (props === 0x24) return '(BPP4 | NO_PAL)';
      if (props === 0x20) return 'BPP4';
      return `${props}`;
    };

    const template = `${options.label ? `Graphic_${toHex(addr, 8)}: @ 0x${toHex(addr, 8)}\n` : ''}    graphic_raw [ ${options.label ? '' : `@ 0x${toHex(addr, 8)}`}
        src: 0x${toHex(gfx.srcrel, 8)}, @ 0x${toHex(gfx.srcabs, 8)}
        size: ${gfx.size},
        ofs: ${gfx.ofs},
        chunk_size: ${gfx.chunk},
        props: ${printProps(gfx.props)}
    ]${
      options.nopal ? '' : `\n    palette_raw [
        src: 0x${toHex(gfx.palrel, 8)}, @ 0x${toHex(gfx.palabs, 8)}
        length: ${gfx.palLength},
        lz77: ${gfx.palLz77},
        dst: ${gfx.dst}
    ]`
    }
`;

    console.log(template);
  }
};

main();
