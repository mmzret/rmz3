#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";
import { loadU16, loadU32 } from "../util/index.ts";

const GBAGFX = "./tools/gbagfx/gbagfx";

const main = async () => {
  const { args, options } = await new Command()
    .name("gfx.ts")
    .version("1.0.0")
    .description(
      "Graphic構造体 のアドレスを与えると、それの指すグラフィックデータ と パレットデータ を ダンプし、それを使って、GBAGFXで利用可能なpngを作成します。",
    )
    .option("-w, --width=[n]", "image width(not px but tile)", { default: 1 })
    .option("-l, --lz77", "is Lz77 compressed?")
    .arguments("<rom:string> <addr:string> <output:string>")
    .usage("gfx.ts rmz3.gba 0x08547550 output.png")
    .parse(Deno.args);

  const base = 0x0800_0000;
  const rom = Deno.readFileSync(args[0]);
  const addr = Number(args[1]);

  const gfx = {
    src: loadU32(rom, addr) + addr,
    size: loadU16(rom, addr + 4),
    pal: loadU32(rom, addr + 12) + (addr + 12),
    palSize: loadU16(rom, addr + 16),
  };
  const bppPath = args[2].replaceAll(".png", ".4bpp");

  // dump gbapal
  const palPath = args[2].replaceAll(".png", ".gbapal");
  let pal = rom.slice(gfx.pal - base, gfx.pal - base + gfx.palSize);
  if (pal.byteLength > 32) pal = pal.slice(0, 32);
  Deno.writeFileSync(palPath, pal);

  if (options.lz77) {
    // dump as LZ77
    const lz77Path = args[2].replaceAll(".png", ".lz");
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
      args[2],
      "-width",
      `${options.width}`,
      "-palette",
      palPath,
    ],
  }).status();
  Deno.removeSync(bppPath);
};

main();
