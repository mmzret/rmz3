#!/usr/bin/env -S deno run --allow-read

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";
import { loadI8, loadU8, toHex } from "../util/index.ts";

const UNIT = 1;
const SIZE = "byte";

// ./tools/dumper/int32.ts ./baserom.gba 0x080ff00c 80
const main = async () => {
  const { options, args } = await new Command()
    .name("dump byte command")
    .version("1.0.0")
    .description("Dump byte sequence from binary")
    .option("-s, --signed", "dump as signed int8")
    .option("-d, --decimal", "dump as decimal")
    .option("-m, --mode=[mode]", "dump mode", { default: "asm" })
    .option("-c, --column=[n]", "column size")
    .arguments("<rom> <addr> <length>")
    .parse(Deno.args);

  const [start, length] = [Number(args[1]), Number(args[2])];
  const column = options.column ? Number(options.column) : length;
  const mode = options.mode;
  const signed = !!options.signed;
  const decimal = !!options.decimal;

  const rom = Deno.readFileSync(args[0]);

  let result = "";
  for (let i = 0; i < length; i++) {
    const addr = start + (i * UNIT);
    const val = signed ? loadI8(rom, addr) : loadU8(rom, addr);

    let hex = decimal
      ? Math.abs(val).toString(10)
      : toHex(Math.abs(val), UNIT * 2, "0x");
    if (val < 0) {
      hex = "-" + hex;
    }

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
