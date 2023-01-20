#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";
import { loadU32 } from "../util/load.ts";

// gfx.ts をサイバーエルフの mugshot 向けにラップしたモノ

const CMD = "./tools/dumper/gfx.ts";
const DIR = "./data/gfx/elf/mugshot";

const main = async () => {
  const { args, options } = await new Command()
    .name("elf_mugshot.ts")
    .version("1.0.0")
    .description("gfx.ts をサイバーエルフの mugshot 向けにラップしたモノ")
    .option("-l, --lz77", "is Lz77 compressed?")
    .arguments("<rom> <addr:string>")
    .usage("elf_mugshot.ts rmz3.gba 0x08635f24")
    .parse(Deno.args);

  const addr = args[1];
  try {
    Deno.mkdirSync(`${DIR}/${addr}`);
  } catch (_) {}

  // gfx.ts 0x08635f24 0x08635f24.png <--lz77> -w=4
  const png = `${DIR}/${addr}/${addr}.png`;
  const cmd = `${CMD} ${args[0]} ${addr} ${png}${
    options.lz77 ? " --lz77" : ""
  } -w=4`;
  await Deno.run({ cmd: cmd.split(" ") }).status();

  await Deno.renameSync(
    png.replaceAll(".png", ".gbapal"),
    `${DIR}/${addr}/color.gbapal`,
  );

  const rom = Deno.readFileSync(args[0]);
  const address = Number(args[1]);
  const pal = loadU32(rom, address + 12) + (address + 12);
  const grayscale = rom.slice(pal + 32 - 0x08000000, pal + 64 - 0x08000000);
  Deno.writeFileSync(
    `${DIR}/${addr}/grayscale.gbapal`,
    grayscale,
  );

  if (options.lz77) {
    Deno.renameSync(png, png.replaceAll(".png", ".lz.png"));
  }
};

main();
