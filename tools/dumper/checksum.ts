#!/usr/bin/env -S deno run --allow-read --allow-write

// ロックマンゼロ3のセーブスロット1のチェックサムを計算します

import { loadU8, toHex } from "../util/index.ts";

const STORY_SIZE = 592;
const HEADER_SIZE = 16;
const BACKUP = 16380;

const main = () => {
  const args = Deno.args;
  if (args.length !== 1) {
    console.log("Usage: checksum.ts SAVPATH");
    console.log("       checksum.ts rmz3.sav");
    return;
  }

  const input = args[0];
  if (!(input.endsWith(".sav"))) {
    console.log("Is not save file");
    return;
  }
  const rom = Deno.readFileSync(input);

  let checksum = 0;
  for (let i = 0; i < STORY_SIZE; i++) {
    checksum += loadU8(rom, i + BACKUP + HEADER_SIZE, 0);
  }

  console.log(`Checksum: 0x${toHex(checksum, 4)}(${checksum})`);
};

main();
