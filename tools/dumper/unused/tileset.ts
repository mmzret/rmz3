#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { Parser } from 'npm:binary-parser@2.2.1';
import { join } from 'https://deno.land/std/path/mod.ts';

// All tileset dump are completed, so this tool is no longer needed.

const BASE = 0x0800_0000;
const SIZE = 12 + 8;

const GraphicHeader = new Parser().endianness('little')
  .uint32('src')
  .uint32('sizeOfs')
  .uint16('chunkSize')
  .uint16('props');

const PaletteHeader = new Parser().endianness('little')
  .uint32('src')
  .uint16('size')
  .uint8('lz77')
  .uint8('dst');

type GraphicHeaderStruct = {
  src: number;
  sizeOfs: number;
  chunkSize: number;
  props: number;
};

type PaletteHeaderStruct = {
  src: number;
  size: number;
  lz77: number;
  dst: number;
};

const main = async () => {
  const { args, options } = await new Command()
    .name('tileset.ts')
    .version('1.0.0')
    .arguments('<header:string>')
    .option('-o, --output <dir:string>', 'output directory', { default: './' })
    .option('--verbose', 'verbose')
    .usage('0x08744c48')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]) - BASE;

  const graphic = GraphicHeader.parse(
    rom.slice(start, start + 12),
  ) as GraphicHeaderStruct;
  if (options.verbose) {
    console.log(graphic);
  }

  const palette = PaletteHeader.parse(
    rom.slice(start + 12, start + 12 + 8),
  ) as PaletteHeaderStruct;
  if (options.verbose) {
    console.log(palette);
  }

  {
    const src = start + graphic.src;
    const graphicData = rom.slice(src, src + (graphic.sizeOfs & 0x3FFFFF));
    const isLz77 = graphic.props & 0x02;
    const filename = isLz77 ? `tiles.4bpp.lz` : `tiles.4bpp`;
    Deno.writeFileSync(join(options.output, filename), graphicData);
  }

  {
    const src = start + 12 + palette.src;
    const paletteNum = palette.size / 32;
    for (let i = 0; i < paletteNum; i++) {
      const id = i + palette.dst;
      const paletteData = rom.slice(src + i * 32, src + (i + 1) * 32);
      const filename = `${('00' + id).slice(-2)}.pal`;
      Deno.writeFileSync(join(options.output, filename), paletteData);
    }
  }
};

main();
