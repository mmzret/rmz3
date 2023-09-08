#!/usr/bin/env deno run

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';

const unitname: { [unit: number]: string } = {
  2: 'hword',
  4: 'word',
};

const main = async () => {
  const { options, args } = await new Command()
    .name('cpuset.ts')
    .version('1.0.0')
    .description('Parse CpuSet/CpuFastSet param command')
    .option('-f, --fast', 'Parse as CpuFastSet param')
    .arguments('<param>')
    .usage('0x1000080 -f')
    .parse(Deno.args);

  const param = Number(args[0]);
  const isFast = !!options.fast;

  const name = isFast ? 'CpuFastSet' : 'CpuSet';
  console.log(`${name}'s Param: ${Deno.args[0]}`);
  const mode = ((param >> 24) & 0b1) > 0 ? 'Fill' : 'Copy';
  console.log(` Mode: ${mode}`);

  const size = param & 0b1_1111_1111_1111_1111_1111;
  let unit = 4;
  if (!isFast && (((param >> 26) & 0b1) === 0)) {
    unit = 2;
  }
  console.log(` Size: ${size} ${unitname[unit]}`);
  console.log(` ByteSize: ${size * unit} Bytes`);
};

main();
