#!/usr/bin/env -S deno run --allow-read

// 開始アドレス(Address) から Length x 2 バイトだけ、 asm としてダンプします。

import { loadU16, toHex } from "../util/index.ts";

const UNIT = 2;
const SIZE = "hword";

const main = () => {
  const args = Deno.args;
  if (args.length < 3) {
    console.log(
      `Usage: ${SIZE}.ts ROMPATH Address Length [COLMUNS="16"] [MODE="asm"]`,
    );
    console.log(`       ${SIZE}.ts rmz3.gba 0x083836cc 100 8`);
    return;
  }

  const [path, start, length] = [
    args[0],
    Number(args[1]),
    Number(args[2]),
  ];
  const column = args.length >= 4 ? Number(args[3]) : 16;
  const mode = args.length >= 5 ? args[4] : "asm";

  const rom = Deno.readFileSync(path);

  let result = "";
  for (let i = 0; i < length; i++) {
    const addr = start + (i * UNIT);
    const val = loadU16(rom, addr);
    const hex = toHex(val, UNIT * 2, "0x");

    switch (mode) {
      case "asm":
        if (i % column == 0) {
          result += `\n.${SIZE} ${hex}`;
        } else {
          result += `, ${hex}`;
        }
        break;

      // "c"
      default:
        if (i % column == 0) {
          result += `\n${hex}`;
        } else {
          result += `, ${hex}`;
          if (i % column == column - 1) {
            result += `,`;
          }
        }
    }
  }

  console.log(result);
};

main();
