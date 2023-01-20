#!/usr/bin/env deno run

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";

const increments = [
  "Increment",
  "Decrement",
  "Fix",
  "Increment/Reload",
] as const;
const MODES = ["Immediate", "VBlank", "HBlank", "Special"] as const;

const main = async () => {
  const { args } = await new Command()
    .name("dma.ts")
    .version("1.0.0")
    .description("Parse DMA 32bit param")
    .arguments("<param>")
    .usage("0x85010000")
    .parse(Deno.args);

  console.log(`DMA's Param: ${args[0]}`);
  const param = Number(args[0]);
  const cnth = (param >> 16) & 0xFFFF;

  const count = param & 0xFFFF;
  if (count != 0) {
    console.log(`  Count: ${count}`);
  } else {
    console.log(`  Count: 0x4000 or 0x10000(DMA3)`);
  }

  const unit = ((cnth >> 10) & 0b1) > 0 ? "32 bit" : "16 bit";
  console.log(`  Unit: ${unit}`);

  const [dst, src] = [
    increments[(cnth >> 5) & 0b11],
    increments[(cnth >> 7) & 0b11],
  ];
  console.log(`  Src: ${src}`);
  console.log(`  Dst: ${dst}`);
  console.log(`  Repeat: ${(cnth >> 9 & 0b1) > 0}`);
  console.log(`  Mode: ${MODES[(cnth >> 12) & 0b11]}`);
  console.log(`  IRQ: ${((cnth >> 14) & 0b1) > 0}`);
  console.log(`  Enabled: ${((cnth >> 15) & 0b1) > 0}`);
};

main();
