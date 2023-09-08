#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';

type JsonData = {
  label?: string;
  data: Sequence[];
};

type Sequence = MotionCmd[];

type MotionCmd = {
  frameIdx: number;
  duration: number;
};

const main = async () => {
  const { args, options } = await new Command()
    .name('sequence.ts')
    .version('1.0.0')
    .description(
      'Create a Asm file from a sequence.json.',
    )
    .arguments('<json:string>')
    .option('--verbose', 'verbose')
    .option('-l, --label', 'label')
    .usage('sprites/zero/dash/sequence.json')
    .parse(Deno.args);

  const json = JSON.parse(Deno.readTextFileSync(args[0])) as JsonData;
  const sequences = json.data;
  if (options.verbose) {
    console.log(json);
  }

  const sizes = sequences.map((seq, i) => (seq.length * 2));

  const headers: string[] = [];
  for (let i = 0; i < sequences.length; i++) {
    let ofs = 4 * (sequences.length - i);
    if (i > 0) {
      ofs += sum(sizes.slice(0, i));
    }
    const header = `.4byte .+${ofs}`;
    headers.push(header);
  }

  console.log(`.section .rodata`);
  console.log(`.balign 4, 0`);

  if (options.label) {
    console.log(`.global ${options.label}`);
    console.log(`${options.label}:`);
  } else if (json.label != null) {
    console.log(`.global ${json.label}`);
    console.log(`${json.label}:`);
  }
  console.log(headers.join('\n'));

  sequences.forEach((seq) => {
    seq.forEach((cmd) => {
      console.log(`.byte ${cmd.frameIdx}, ${cmd.duration}`);
    });
  });
  console.log(`.balign 4, 0`);
};

const sum = (numbers: number[]) => {
  return numbers.reduce((accumulator, current) => accumulator + current, 0);
};

main();
