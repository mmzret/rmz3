#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from '@cliffy/command';
import { addr, gElfMugshotGraphics, getRGB888, getRGBg, getU16, getU32, gStaticMotionGraphics, rgb555, ROM_PATH, sizeof, toHex } from '../common/index.ts';
import { join } from '@std/path';

const main = async () => {
  await new Command()
    .name('dump.ts')
    .version('1.0.0')
    .command('value', Subcommands['value'])
    .command('gbapal', Subcommands['gbapal'])
    .command('rom', Subcommands['rom'])
    .command('elf', Subcommands['elf'])
    .command('sm', Subcommands['sm'])
    .parse(Deno.args);
};

const getPalettesFromROM = (rom: DataView, start: addr, length: number): rgb555[] => {
  const colors: rgb555[] = [];
  for (let i = 0; i < length; i++) {
    const addr: addr = start + (i * 2);
    const val = getU16(rom, addr);
    colors.push(val);
  }
  return colors;
};

const dumpPaletteForC = (colors: rgb555[]): string => {
  const result: string[] = [];
  const length = colors.length;
  for (let i = 0; i < length; i++) {
    result.push(`${getRGBg(colors[i])}`);
  }
  return result.join(', ');
};

const dumpPaletteForJasc = (colors: rgb555[]): string => {
  const length = colors.length;
  const header = ['JASC-PAL', '0100', `${length}`].join('\n');
  const result: string[] = [];
  for (let i = 0; i < length; i++) {
    const rgb555 = colors[i];
    if (rgb555 & (1 << 15)) {
      console.warn(`Warning: bit15 is set for color index ${i}`);
    }
    const [r, g, b] = getRGB888(colors[i]);
    result.push(`${r} ${g} ${b}`);
  }
  return [header, ...result].join('\n');
};

const dumpPaletteForVscodeColorCode = (colors: rgb555[]): string => {
  const length = colors.length;
  const result: string[] = [];
  for (let i = 0; i < length; i++) {
    const rgb555 = colors[i];
    if (rgb555 & (1 << 15)) {
      console.warn(`Warning: bit15 is set for color index ${i}`);
    }
    const [r, g, b] = getRGB888(colors[i]);
    const hex = `#${toHex(r, 2)}${toHex(g, 2)}${toHex(b, 2)}`;
    result.push(`"${hex}"`);
  }
  return `const colors = [\n  ${result.join(',\n  ')}\n];`;
};

const Subcommands = {
  'value': new Command().name('value')
    .argument('<rgb565:number>', 'RGB565の値')
    .usage('0xB4A0')
    .action((_, rgb565: number) => {
      const val = rgb565 & 0xFFFF;
      console.log(`0x${toHex(val, 4)} => ${getRGBg(val)}`);
    }),
  'gbapal': new Command().name('gbapal')
    .argument('<filepath:string>', 'GBAPALファイルのパス')
    .action((_, filepath: string) => {
      const data = new DataView(Deno.readFileSync(filepath).buffer);
      const length = data.byteLength >> 1;
      const result: string[] = [];
      for (let i = 0; i < length; i++) {
        const val = data.getUint16(i * 2, true);
        result.push(`${getRGBg(val)}`);
      }
      console.log(result.join(',\n'));
    }),
  'rom': new Command().name('rom')
    .description('ROMからアドレスと長さを指定してRGB565の値を標準出力に出力する')
    .argument('<start:number>', 'ROMの開始位置')
    .argument('<length:number>', '色の数')
    .option('-j, --jasc', 'JASC-PALフォーマットで出力', { default: false })
    .option('--vscode', 'VSCodeでカラーコードに色がつくtsで出力', { default: false })
    .usage('0x080FF15C 16')
    .action(({ jasc, vscode }, start: addr, length: number) => {
      const rom = new DataView(Deno.readFileSync(ROM_PATH).buffer);
      const colors: rgb555[] = getPalettesFromROM(rom, start, length);
      if (jasc) {
        console.log(dumpPaletteForJasc(colors));
      } else if (vscode) {
        console.log(dumpPaletteForVscodeColorCode(colors));
      } else {
        console.log(dumpPaletteForC(colors));
      }
    }),
  // oneshots
  'elf': new Command().name('elf')
    .description('for graphics/cyberelf/mugshot')
    .argument('<id:number>', 'gElfMugshotGraphics の idx')
    .argument('<output:string>', 'graphics/cyberelf/mugshot/<output>')
    .usage('13 slime/a.pal')
    .action((_, id: number, output: string) => {
      // e.g. ./tools/dumper/rgb565.ts elf 13 slime/a.pal
      const rom = new DataView(Deno.readFileSync(ROM_PATH).buffer);
      const addr = gElfMugshotGraphics + (id * sizeof.ColorGraphic) + sizeof.Graphic; // e.g. id:1 -> 0x08635f44
      const offset = getU32(rom, addr);
      const length = getU16(rom, addr + 4) >> 1;
      console.log(`id: ${id}, hdr: 0x${toHex(addr, 8)}, addr: 0x${toHex(addr + offset, 8)}, length: ${length}`);
      if (length === 0) {
        console.error(`Error: length is 0 for id ${id}`);
        Deno.exit(1);
      }
      const colors: rgb555[] = getPalettesFromROM(rom, addr + offset, length);

      const outputPath = join('./graphics/cyberelf/mugshot', output);
      const data = dumpPaletteForJasc(colors) + '\n';
      Deno.writeTextFileSync(outputPath, data);
    }),
  'sm': new Command().name('sm')
    .description('for sprites/static')
    .argument('<id:number>', 'gStaticMotionGraphics の idx')
    .argument('<output:string>', 'sprites/static/<output>')
    .usage('187 resistance/alouette/alouette.pal')
    .action((_, id: number, output: string) => {
      // e.g. ./tools/dumper/rgb565.ts sm 187 resistance/alouette/alouette.pal
      const rom = new DataView(Deno.readFileSync(ROM_PATH).buffer);
      const addr = gStaticMotionGraphics + (id * sizeof.ColorGraphic) + sizeof.Graphic; // e.g. id:1 -> 0x08635f44
      const offset = getU32(rom, addr);
      const length = getU16(rom, addr + 4) >> 1;
      console.log(`id: ${id}, hdr: 0x${toHex(addr, 8)}, addr: 0x${toHex(addr + offset, 8)}, length: ${length}`);
      if (length === 0) {
        console.error(`Error: length is 0 for id ${id}`);
        Deno.exit(1);
      }
      const colors: rgb555[] = getPalettesFromROM(rom, addr + offset, length);

      const outputPath = join('./sprites/static', output);
      const data = dumpPaletteForJasc(colors) + '\n';
      Deno.writeTextFileSync(outputPath, data);
    }),
};

main();
