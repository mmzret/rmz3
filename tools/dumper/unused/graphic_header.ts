#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from '@cliffy/command';
import { getU16, getU32, getU8, toHex } from '../../common/index.ts';

const main = async () => {
  const { args, options } = await new Command()
    .name('gfx.ts')
    .version('1.0.0')
    .description(
      `Graphic構造体 の配列の先頭アドレスと、配列の長さを与えると C言語用にヘッダーを標準出力にダンプします。`,
    )
    .arguments('<rom:string> <addr:string> <length:number>')
    .option('--nopal', 'graphic header only')
    .option('--index', "add '[i] =' as entry prefix")
    .usage('rmz3.gba 0x085d78f8 254')
    .parse(Deno.args);

  const rom = new DataView(Deno.readFileSync(args[0]).buffer);
  const start = Number(args[1]);
  const length = Number(args[2]);

  for (let i = 0; i < length; i++) {
    const addr = start + (i * (options.nopal ? 12 : 20));
    const hdr = printGraphicHeader(rom, addr, options.nopal ?? false);
    console.log(`${options.index ? `[${i}] = ` : ''}${hdr},`);
  }
};

const printProps = (props: number) => {
  if (props === 0x22) return '(LZ77 | BPP4)';
  if (props === 0x26) return '(LZ77 | BPP4 | NO_PAL)';
  if (props === 0x24) return '(BPP4 | NO_PAL)';
  if (props === 0x20) return 'BPP4';
  return `${props}`;
};

export const printGraphicHeader = (
  rom: DataView,
  addr: number,
  nopal: boolean,
): string => {
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

  const graphic = `{${nopal ? `  // 0x${toHex(addr, 8)}` : ''}
      src: 0x${toHex(gfx.srcrel, 8)}, // 0x${toHex(gfx.srcabs, 8)}
      size: ${gfx.size},
      ofs: ${gfx.ofs},
      chunkSize: ${gfx.chunk},
      props: ${printProps(gfx.props)}
    }`;

  if (nopal) {
    return graphic;
  } else {
    const colorGraphic = `{   // 0x${toHex(addr, 8)}
    g: ${graphic},
    pal: {
      src: 0x${toHex(gfx.palrel, 8)}, // 0x${toHex(gfx.palabs, 8)}
      size: ${gfx.palLength} * COLOR,
      lz77: ${gfx.palLz77 ? 'TRUE' : 'FALSE'},
      dst: ${gfx.dst},
    },
}`;
    return colorGraphic;
  }
};

// main();
