#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";

// gfx.ts を会話の mugshot 向けにラップしたモノ

const CMD = "./tools/dumper/gfx.ts";
const DIR = "./data/gfx/dialog/mugshot";

const main = async () => {
  const { args } = await new Command()
    .name("chara_mugshot.ts")
    .version("1.0.0")
    .description("gfx.ts を会話の mugshot 向けにラップしたモノ")
    .arguments("<rom> <addr> <output>")
    .usage("chara_mugshot.ts rmz3.gba 0x085a9320 deathtanz")
    .parse(Deno.args);

  const name = args[2];
  if (name.length === 0) {
    return;
  }
  try {
    Deno.mkdirSync(`${DIR}/${name}`);
  } catch (_) {}

  const png = `${DIR}/${name}/${name}.png`;
  const cmd = `${CMD} ${args[0]} ${args[1]} ${png} -w=6`;
  await Deno.run({ cmd: cmd.split(" ") }).status();
};

main();
