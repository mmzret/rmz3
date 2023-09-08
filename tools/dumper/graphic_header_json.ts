#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadU16, loadU8 } from '../common/index.ts';
import { GraphicHeader, GraphicProp } from '../common/index.ts';

const main = async () => {
  const { args, options } = await new Command()
    .name('graphic_header_json.ts')
    .version('1.0.0')
    .description(`Graphic構造体 の配列の先頭アドレスと、配列の長さを与えると JSONをダンプします`)
    .arguments('<addr:string> <length:number>')
    .option('--nopal', 'graphic header only')
    .usage('0x085197C4 4')
    .parse(Deno.args);

  const rom = Deno.readFileSync('baserom.gba');
  const start = Number(args[0]);
  const length = Number(args[1]);

  const headers: GraphicHeader[] = [];

  for (let i = 0; i < length; i++) {
    const addr = start + (i * (options.nopal ? 12 : 20));
    const hdr = printGraphicHeader(rom, addr, options.nopal ?? false);
    hdr.name = `${i}.png`;
    headers.push(hdr);
  }

  console.log(JSON.stringify({ data: headers }, null, 2));
};

const getProps = (props: number): GraphicProp[] => {
  if (props === 0x22) return ['lz77', '4bpp'];
  if (props === 0x26) return ['lz77', '4bpp', 'no_pal'];
  if (props === 0x24) return ['4bpp', 'no_pal'];
  if (props === 0x25) return ['4bpp', 'no_pal', 'chunked'];
  if (props === 0x20) return ['4bpp'];
  if (props === 0x00) return [];
  throw new Error(`Unknown props: ${props}`);
};

export const printGraphicHeader = (
  rom: Uint8Array,
  addr: number,
  nopal: boolean,
): GraphicHeader => {
  const BASE = 0x0800_0000;
  const gfx = {
    ofs: loadU16(rom, addr + 6, BASE) >> 6,
    chunk: loadU16(rom, addr + 8, BASE),
    props: loadU16(rom, addr + 10, BASE),
    palLength: loadU16(rom, addr + 16, BASE) / 2,
    dst: loadU8(rom, addr + 19, BASE),
  };

  const data: GraphicHeader = {
    name: '',
    ofs: gfx.ofs,
    chunkSize: gfx.chunk,
    props: getProps(gfx.props),
  };

  if (nopal) {
    return data;
  }

  data.palette = {
    color: gfx.palLength,
    id: gfx.dst,
  };
  return data;
};

main();
