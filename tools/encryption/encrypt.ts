#!/usr/bin/env deno run --allow-read --allow-write

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";

const main = async () => {
  const { args } = await new Command()
    .name("encrypt.ts")
    .version("1.0.0")
    .description("Take xor for src code encryption")
    .arguments("<key> <src> <dst>")
    .usage("rmz3.gba src/gfx.c src/gfx.encrypted.bin")
    .parse(Deno.args);

  const key = Deno.readFileSync(args[0]);
  const src = Deno.readFileSync(args[1]);
  let i = 0;
  for (const b of key) {
    src[i] = (src[i] ^ b) & 0xFF;
    i = (i + 1) % src.byteLength;
  }
  Deno.writeFileSync(args[2], src);
};

main();
