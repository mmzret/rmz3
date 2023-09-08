#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { loadU16, loadU32 } from '../common/index.ts';

/*
  xxx.lz.png:        LZ77 compressed image
  xxx.lz.8bpp.png:   LZ77 compressed image(8bpp)
  xxx.notrim.png:    If the last tile in the data is a transparent tile, that tile is normally removed, but `.notrim` prevents that.
  xxx.notrim.lz.png: LZ77 compressed image version for `.notrim.png`
*/

const GBAGFX = './tools/gbagfx/gbagfx';

const main = async () => {
  const { args, options } = await new Command()
    .name('gfx.ts')
    .version('1.0.0')
    .description(
      `Graphic構造体 のアドレスを与えると、それの指すグラフィックデータ と パレットデータ を ダンプし、それを使って、GBAGFXで利用可能なpngを作成します。
LZ77圧縮されている場合は、output に .lz   をつけてください e.g. output.lz.png
8BPPフォーマットの場合は、output に .8bpp をつけてください e.g. output.lz.8bpp.png`,
    )
    .option('-w, --width=[n]', 'image width(not px but tile)', { default: 1 })
    .option('--nopal', 'no dump palette')
    .option('-p, --pal=[s:string]', 'use specified gbapal')
    .option('-g, --grayscale', 'use grayscale palettes')
    .option('-z, --zero', 'use zero palettes')
    .option('-W, --weapon', 'use weapon palettes')
    .arguments('<addr:string> <output:string>')
    .usage('0x08547550 output.png')
    .parse(Deno.args);

  const base = 0x0800_0000;
  const rom = Deno.readFileSync('baserom.gba');
  const addr = Number(args[0]);

  const gfx = {
    src: loadU32(rom, addr, 0x0800_0000) + addr,
    size: loadU16(rom, addr + 4, 0x0800_0000),
    pal: loadU32(rom, addr + 12, 0x0800_0000) + (addr + 12),
    palSize: loadU16(rom, addr + 16, 0x0800_0000),
  };

  const outputPath = args[1];
  const isLz77 = outputPath.includes('.lz.'); // e.g. ".lz.png"
  const bpp = outputPath.includes('.8bpp.') ? 8 : 4; // e.g. ".lz.8bpp.png"
  const bppPath = args[1].replaceAll('.png', `.${bpp}bpp`);

  // dump gbapal
  let pal: Uint8Array;
  let palPath: string;
  if (options.grayscale) {
    palPath = './tools/dumper/grayscale.gbapal';
  } else if (options.zero) {
    palPath = './tools/dumper/zero.gbapal';
  } else if (options.weapon) {
    palPath = './tools/dumper/weapon.gbapal';
  } else if (options.pal) {
    palPath = options.pal as string;
  } else {
    palPath = args[1].replaceAll('.png', '.gbapal');
    pal = rom.slice(gfx.pal - base, gfx.pal - base + gfx.palSize);
    switch (bpp) {
      case 4: {
        if (pal.byteLength > 16 * 2) {
          // deno-fmt-ignore
          const dst = palPath.replaceAll(isLz77 ? ".lz.gbapal" : ".gbapal", "_2.pal");
          Deno.writeFileSync(dst, pal.slice(32));
          pal = pal.slice(0, 32);
        }
        break;
      }
      case 8: {
        if (pal.byteLength < (256 * 2)) {
          // deno-fmt-ignore
          const dst = palPath.replaceAll(isLz77 ? ".lz.gbapal" : ".gbapal", "_2.pal");
          Deno.writeFileSync(dst, pal.slice(512));
          const old = [...pal];
          pal = new Uint8Array(512);
          pal.set(old, 0);
        }
        break;
      }
    }
    Deno.writeFileSync(palPath, pal);
  }

  if (isLz77) {
    // dump as LZ77
    const lz77Path = args[1].replaceAll('.png', '.lz');
    const lz77 = rom.slice(gfx.src - base, gfx.src - base + gfx.size);
    Deno.writeFileSync(lz77Path, lz77);

    // decompress LZ77 into 4bpp
    await Deno.run({ cmd: [GBAGFX, lz77Path, bppPath] }).status(); // $ gbagfx xxx.lz xxx.4bpp
    Deno.removeSync(lz77Path);
  } else {
    // dump as 4BPP
    Deno.writeFileSync(
      bppPath,
      rom.slice(gfx.src - base, gfx.src - base + gfx.size),
    );
  }

  // create png
  // $ gbagfx xxx.4bpp xxx.png -width 6 -palette xxx.gbapal
  await Deno.run({
    cmd: [
      GBAGFX,
      bppPath,
      args[1],
      '-width',
      `${options.width}`,
      '-palette',
      palPath,
    ],
  }).status();
  Deno.removeSync(bppPath);
  if (
    options.nopal && !options.grayscale && !options.zero && !options.weapon &&
    !options.pal
  ) {
    Deno.removeSync(palPath);
  }
};

main();
