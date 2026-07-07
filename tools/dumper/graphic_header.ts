#!/usr/bin/env -S deno run --allow-read

import { Command } from '@cliffy/command';
import { addr, getU16, getU32, getU8, gStageTilesetOffsets, ROM_PATH, SEPARATOR, sizeof, toHex } from '../common/index.ts';

const LABEL = 'Gfx';

const getProps = (prop: number): string => {
  if (prop === 0) return '0';

  const props: string[] = [];
  if (prop & (1 << 0)) props.push('MAP2D');
  if (prop & (1 << 1)) props.push('LZ77');
  if (prop & (1 << 2)) props.push('NO_PAL');
  if (prop & (1 << 5)) props.push('BPP4');
  if (prop & (1 << 6)) props.push('BPP8');
  if (props.length === 1) return props[0];
  return `(${props.join(' | ')})`;
};

// dump "struct Graphic"
const printGraphicHeader = (rom: DataView, addr: addr, label: string): string => {
  const offset = getU32(rom, addr);
  const data04 = getU32(rom, addr + 4);
  const size = data04 & 0x3FFFFF;
  const tileId = data04 >>> 22;
  const rowsize = getU16(rom, addr + 8);
  const prop = getU16(rom, addr + 10);
  const src: addr = addr + offset;

  const header = `${label}: @ 0x${toHex(addr, 8)}
\t.4byte ${`${label}_Tiles-. @ data: 0x${toHex(src, 8)} = .+${offset}`}
\t.4byte ${size} | (${tileId} << 22) \t@ bit0..21: bytesize, bit22..31: dst (VRAM TileID)
\t.2byte ${rowsize}, ${getProps(prop)} \t@ rowsize${(prop & 1) ? '' : '(unused)'}, props
`;
  return header;
};

// dump "struct Palette"
const printPaletteHeader = (rom: DataView, addr: addr, label: string): string => {
  const offset = getU32(rom, addr);
  const src: addr = addr + offset;
  const bytesize = getU16(rom, addr + 4);
  const dst = getU8(rom, addr + 7);
  const header = `\t@ Palette 0x${toHex(addr, 8)}
\t\t.4byte ${`${label}_Pal-. @ data: 0x${toHex(src, 8)} = .+${offset}`}
\t\t.2byte ${bytesize} @ bytesize
\t\t.byte 0, ${dst} @ lz77(bool8), dst = PaletteID`;
  return header;
};

// ./tools/dumper/graphic_header.ts d 0x08756c84 4 > tmp/header.inc
const mainCommand = new Command().name('dump')
  .description(`Graphic構造体 の配列の先頭アドレスと、配列の長さを与えると asmを標準出力に表示します`)
  .argument('<start:number>', '開始アドレス')
  .argument('<length:number>', 'エントリ数')
  .option('--nopal', '対象が、 "ColorGraphic" ではなく "Graphic" の場合には、有効にする必要がある')
  .usage('0x085197C4 4')
  .action((options, start: addr, length: number) => {
    const rom = new DataView(Deno.readFileSync(ROM_PATH).buffer);
    const nopal = !!options.nopal;

    const headers: string[] = [];
    const size = nopal ? sizeof.Graphic : sizeof.ColorGraphic;

    for (let i = 0; i < length; i++) {
      const addr: addr = start + (i * size);
      const label = `${LABEL}${i}`;
      let hdr = printGraphicHeader(rom, addr, label);
      if (!nopal) hdr += printPaletteHeader(rom, addr + sizeof.Graphic, label);
      headers.push(hdr);
    }

    console.log(headers.join('\n\n') + '\n');
  });

// ./tools/dumper/graphic_header.ts tileset 2 > tmp/header.inc
const Oneshots = {
  'tileset': new Command().name('tileset')
    .argument('<id:number>', "gStageTilesetOffsets's idx")
    .usage('2') // -> gVolcanoTilesetGraphics
    .action((_, id: number) => {
      const rom = new DataView(Deno.readFileSync(ROM_PATH).buffer);
      const srp: addr = gStageTilesetOffsets + (id * 4);
      const start: addr = getU32(rom, srp) + srp; // e.g. 0x08721768 = gVolcanoTilesetGraphics
      const length = getU32(rom, start) / sizeof.ColorGraphic;

      const symbols = [
        'SnowTileset',
        'SnowTileset',
        'VolcanoTileset',
        'WatersideTileset',
        'FactoryTileset',
        'RuinTileset',
        'MissileTileset',
        'DesertTileset',
        'ForestTileset',
        'AntarcticTileset',
        'AreaX2Tileset',
        'PlantTileset',
        'SnowTileset',
        'WatersideTileset',
        'ElevatorTileset',
        'SubArcadiaTileset',
        'WeilLaboTileset',
        'ResistanceBaseTileset',
        'MiscTileset',
      ];
      const dirnames = [
        'snow',
        'snow',
        'volcano',
        'waterside',
        'factory',
        'ruin',
        'missile',
        'desert',
        'forest',
        'antarctic',
        'area_x2',
        'plant',
        'snow',
        'waterside',
        'giant_elevator',
        'sub_arcadia',
        'weil_labo',
        'resistance_base',
        'misc',
      ];

      const symbol = symbols[id] || `Tileset${id}`;
      const dirname = `data/tilesets/${dirnames[id]}/${dirnames[id]}`;

      const headers: string[] = [];
      for (let i = 0; i < length; i++) {
        const addr: addr = start + (i * sizeof.ColorGraphic);
        const label = `${symbol}${i}`;
        const hdr = printGraphicHeader(rom, addr, label) + printPaletteHeader(rom, addr + sizeof.Graphic, label);
        headers.push(hdr);
      }
      console.log(headers.join('\n\n') + '\n\n' + SEPARATOR + '\n');

      for (let i = 0; i < length; i++) {
        const addr: addr = start + (i * sizeof.ColorGraphic);
        const lz77 = (getU16(rom, addr + 10) & (1 << 1)) !== 0;
        console.log(`${symbol}${i}_Tiles:`);
        console.log(`\t.incbin "${dirname}${i}.4bpp${lz77 ? '.lz' : ''}"`);
        console.log(`${symbol}${i}_Pal:`);
        console.log(`\t.incbin "${dirname}${i}.gbapal"\n`);
      }

      for (let i = 0; i < length; i++) {
        const addr: addr = start + (i * sizeof.ColorGraphic);
        const pltt: addr = (addr + sizeof.Graphic) + getU32(rom, addr + sizeof.Graphic);
        const len = getU16(rom, addr + sizeof.Graphic + 4) >> 1;
        const cmd1 = `@ ./tools/dumper/rgb565.ts rom 0x${toHex(pltt, 8)} ${len} -j > ${dirname}${i}.pal`;
        const cmd2 = `@ ./tools/dumper/gfx.ts -g 0x${toHex(addr, 8)} ${dirname}${i}.png -- -width 32`;
        console.log(cmd1);
        console.log(cmd2);
      }
    }),
};

const main = async () => {
  await new Command()
    .name('dump.ts')
    .version('1.0.0')
    .command('dump', mainCommand).alias('d')
    // oneshots
    .command('tileset', Oneshots['tileset'])
    .parse(Deno.args);
};

main();
