#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';

const main = async () => {
  const { args } = await new Command()
    .name('trim.ts')
    .version('1.0.0')
    .description(
      `.4bppの末尾に全部透明なタイルがある場合、それを削ぎ落とします`,
    )
    .arguments('<bpp4:string>')
    .usage('omega_zero.4bpp')
    .parse(Deno.args);

  const path = args[0];
  if (path.includes('.notrim')) return;
  if (path.includes('bg')) return;

  const bpp4 = Deno.readFileSync(path);
  let result = new Uint8Array([...bpp4]);
  if (bpp4.byteLength % 32 !== 0) {
    console.error(`Invalid 4bpp filesize (${bpp4.byteLength} Bytes)`);
    return;
  }

  let shouldWrite = false;
  let start = bpp4.byteLength;
  for (let tileno = 0; tileno < bpp4.byteLength / 32; tileno++) {
    start -= 32; // 末尾から見るので
    let isTransparent = true;
    for (let i = 0; i < 32; i++) {
      if (bpp4[start + i] !== 0) {
        isTransparent = false;
        break;
      }
    }
    if (isTransparent) {
      shouldWrite = true;
      result = bpp4.subarray(0, start);
    } else {
      break;
    }
  }

  if (shouldWrite) Deno.writeFileSync(path, result);
};

main();
