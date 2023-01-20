#!/usr/bin/env deno run --allow-read

import { Command } from "https://deno.land/x/cliffy@v0.25.4/command/mod.ts";

const toHex = (val: number, maxLength: number, prefix = ""): string => {
  return prefix + (val).toString(16).toUpperCase().padStart(maxLength, "0");
};

const main = async () => {
  const { options, args } = await new Command()
    .name("diff.ts")
    .version("1.0.0")
    .description("check diff between two binary files")
    .option("-w, --width=[n]", "log data width", { default: 1 })
    .option(
      "-o, --offset=[n:number]",
      "start offset from comparision",
      {
        default: 0,
      },
    )
    .arguments("<expected> <actual>")
    .usage("expected.gba actual.gba")
    .parse(Deno.args);

  const [expectPath, actualPath] = args;

  const expectRom = Deno.readFileSync(expectPath);
  const actualRom = Deno.readFileSync(actualPath);

  for (let i = Number(options.offset); i < expectRom.length; i++) {
    const e = expectRom[i];
    const a = actualRom[i];
    if (e !== a) {
      console.error(`Offset: 0x${i.toString(16)}`);

      for (let i = 0; i < options.width; i++) {
        const data = actualRom[i];
        console.log(`  0x${toHex(i, 8)}: 0x${toHex(data, 2)}`);
      }
      return;
    }
  }

  console.log("Binary is correct.");
};

main();
