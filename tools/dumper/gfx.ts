#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from '@cliffy/command';
import { addr, decompressLZ77, getSlice, getU16, getU32, ROM_PATH } from '../common/index.ts';

const GBAGFX = './tools/gbagfx/gbagfx';

// e.g. ./tools/dumper/gfx.ts 0x085d8208 ./tmp/gfx/deathlock.png -- -width 4 -object
// -- 以降のものはそのまま gbagfx に渡されるオプション
// 処理の流れ
// 1. 引数で渡したアドレスの指すGraphic構造体を読み取って、グラフィックデータ(.bpp) と パレットデータ(.gbapal) をダンプ
// 2. それを使って、GBAGFXを呼び出して、pngを作成
// 3. GBAGFX に渡すために用意した グラフィックデータ(.bpp) と パレットデータ(.gbapal) を削除
const main = async () => {
  await new Command()
    .name('gfx.ts')
    .version('1.0.0')
    .description('Graphic構造体 のアドレスを与えると、それの指すグラフィックデータ と パレットデータ を ダンプし、それを使って、GBAGFXで利用可能なpngを作成します。')
    .option('-n, --noop', 'このスクリプトのデバッグ用, 何もせず、引数の内容を表示する')
    .option('--nodiscard', '中間生成物(.bpp, .gbapal)を削除しない', { default: false })
    .option('-p, --pal [val:string]', 'use pre-defined gbapal')
    .option('-g, --grayscale', "don't use palette, output grayscale image")
    .argument('<addr:number>', 'Graphic or ColorGraphic 構造体のアドレス')
    .argument('<dst:string>', '出力先のpngファイルパス')
    .argument('[...gbagfx_options:string]', 'GBAGFXに渡すオプション, see gbagfx/README.md')
    // gfx.ts <addr> <dst> -- [gbagfx_options]
    .usage('0x085d8208 ./tmp/gfx/deathlock.png -- -width 4 -object')
    .action(function (options, addr: number, dst: string) {
      const opts = this.getLiteralArgs(); // "--" 以降の引数を取得する
      if (options.noop) {
        console.log('dump');
        console.log(`options: ${JSON.stringify(options)}`);
        console.log(`addr=0x${addr.toString(16)}, dst=${dst}, opts='${opts.join(' ')}'`);
        return;
      }
      const rom = new DataView(Deno.readFileSync(ROM_PATH).buffer);
      const predefPal = options.pal ? options.pal as string : '';
      dump(rom, addr, dst, opts, predefPal, options.nodiscard, options.grayscale || false);
    })
    .parse(Deno.args);
};

const dump = (rom: DataView, addr: number, dst: string, opts: string[], predefPal: string, nodiscard: boolean, grayscale: boolean) => {
  const props = getU16(rom, addr + 10);
  const gfx = {
    src: getU32(rom, addr) + addr,
    bytesize: getU16(rom, addr + 4),
    lz77: (props & (1 << 1)) !== 0,
    bpp8: (props & (1 << 6)) !== 0,
    pal: getU32(rom, addr + 12) + (addr + 12),
    palSize: getU16(rom, addr + 16),
  } as {
    src: addr;
    bytesize: number;
    lz77: boolean;
    bpp8: boolean;
    pal: addr;
    palSize: number;
  };
  if (gfx.bpp8) {
    console.error(`Error: 8bpp graphics are not supported yet`);
    Deno.exit(1);
  }

  const bpp = gfx.bpp8 ? '.8bpp' : '.4bpp';
  const bppPath = dst.replaceAll('.png', bpp); // "%.4bpp" or "%.8bpp"

  // GBAGFX に必要な パレットデータ をROMから取り出す
  let pal: Uint8Array;
  let palPath: string = '';
  let usePredefPalettes = false;
  if (!grayscale) {
    if (predefPal) {
      palPath = predefPal as string;
      usePredefPalettes = true;
    } else {
      palPath = dst.replaceAll('.png', '.gbapal');
      pal = new Uint8Array(getSlice(rom, gfx.pal, gfx.palSize));
      Deno.writeFileSync(palPath, pal);
    }
  }

  let tiles = getSlice(rom, gfx.src, gfx.bytesize);
  if (gfx.lz77) tiles = decompressLZ77(tiles);
  Deno.writeFileSync(bppPath, new Uint8Array(tiles));

  // create png
  const gbagfxargs: string[] = [bppPath, dst, ...opts];
  if (!grayscale && palPath) gbagfxargs.push(`-palette`, palPath);
  const { code, stdout, stderr } = Deno.spawnAndWaitSync(GBAGFX, gbagfxargs); // $ gbagfx xxx.4bpp xxx.png -width 6 -palette xxx.gbapal
  if (code !== 0) {
    console.error(`Error: gbagfx failed with exit code ${code}`);
    console.log(`command: ${GBAGFX} ${gbagfxargs.join(' ')}`);
    const stdoutStr = new TextDecoder().decode(stdout);
    if (stdoutStr) console.log(`  gbagfx: ${stdoutStr}`);
    const stderrStr = new TextDecoder().decode(stderr);
    if (stderrStr) console.log(`  gbagfx: ${stderrStr}`);
    Deno.exit(1);
  }

  const numTiles = tiles.byteLength / (gfx.bpp8 ? 64 : 32);
  console.log(`${bppPath}: GFX_OPTS := -num_tiles ${numTiles}`);

  // 中間ファイルの削除
  if (!nodiscard) {
    Deno.removeSync(bppPath); // .bpp ファイルは GBAGFXでpngを作成した後は不要
    if (!usePredefPalettes && palPath) Deno.removeSync(palPath);
  }
};

main();
