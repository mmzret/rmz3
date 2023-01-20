#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";
import { loadU32, toHex } from "../util/index.ts";

const MOTION_PLTT_OFFSETS = 0x085b5cd0;

// This script is write-off program for myself, so no longer needed
const main = async () => {
  const { args } = await new Command()
    .name("motionpltt.ts")
    .version("1.0.0")
    .description("List Motion Palette addresses")
    .arguments("<rom:string>")
    .parse(Deno.args);

  const rom = Deno.readFileSync(args[0]);

  for (let i = 0; i < 280; i++) {
    const n = String(i).padStart(3, "0"); // 1 -> "001", 133 -> "133"

    const entry = MOTION_PLTT_OFFSETS + (i * 4);
    const offset = loadU32(rom, entry);
    const hdr = entry + offset; // e.g. 0x085b6130
    console.log(`${toHex(hdr, 8, "0x")}, # ${n}`);
  }
};

main();
