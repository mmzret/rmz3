#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";
import { loadU16, loadU32, toHex } from "../util/index.ts";

const BGMAP_OFFSETS = 0x085222a0;

// This script is write-off program for myself, so no longer needed
const main = async () => {
  const { options, args } = await new Command()
    .name("bgmap.ts")
    .version("1.0.0")
    .description("Dump bgmap binary")
    .option("-t, --type", "check hdr type")
    .arguments("<rom:string> [start:number] [end:number]")
    .parse(Deno.args);

  const rom = Deno.readFileSync(args[0]);
  const range = [args[1] || 0, args[2] || 134];

  let max = 0x085224b8;
  for (let i = 0; i < range[0]; i++) {
    const entry = BGMAP_OFFSETS + (i * 4);
    const offset = loadU32(rom, entry);
    const hdr = entry + offset; // e.g. 0x085224b8
    if (hdr > max) {
      max = hdr;
    }
  }

  for (let i = range[0]; i < range[1]; i++) {
    const n = String(i).padStart(3, "0"); // 1 -> "001", 133 -> "133"

    const entry = BGMAP_OFFSETS + (i * 4);
    const offset = loadU32(rom, entry);
    const hdr = entry + offset; // e.g. 0x085224b8
    if (hdr <= max) {
      // already done
      continue;
    }

    if (options.type) {
      const type = loadU32(rom, hdr);
      if (type !== 0x10001) {
        console.log(`${n}: 0x${toHex(type, 5)}`);
      }
      continue;
    }

    const start = hdr + 8; // e.g. 0x085224c0
    const w = loadU16(rom, hdr + 4);
    const h = loadU16(rom, hdr + 6);

    const size = (w * h + (w * h) % 2) * 2;

    const end = start + size; // e.g. 0x085229c0
    const cmd =
      `./tools/dumper/bin.ts ./baserom.gba ${start} ${end} ./data/gfx/bgmaps/${n}.bin`;
    // console.log(cmd);
    await Deno.run({ cmd: cmd.split(" ") }).status(); // $ gbagfx xxx.lz xxx.4bpp
    console.log(
      `BgMap(${i}, ${w}, ${h}, "${n}.bin");   // 0x${toHex(hdr, 8)}`,
    );
  }
};

main();
