#!/usr/bin/env -S deno run --allow-read --allow-write --unstable

import { dirname, join } from 'https://deno.land/std/path/mod.ts';
import { Command } from 'https://deno.land/x/cliffy@v0.25.4/command/mod.ts';
import { camelToSnakeCase } from '../common/index.ts';

type Layer = {
  bg: number;
  prio: number;
  scrollPower: [number, number];
  scroll: [number, number];
};

type JsonData = {
  name: string;
  id: number;
  layers: Layer[];
  unk_78: [number, number];
};

const main = async () => {
  const { args, options } = await new Command()
    .name('stage.ts')
    .version('1.0.0')
    .description(
      'Create a Header file from a stage.json.',
    )
    .arguments('<json:string>')
    .option('--verbose', 'verbose')
    .usage('data/stage/spacecraft/stage.json')
    .parse(Deno.args);

  const s = JSON.parse(Deno.readTextFileSync(args[0])) as JsonData;
  if (options.verbose) {
    console.log(s);
  }
  const l = s.layers;
  const bgIdxs = l.map((layer) => [0x12, 0x24, 0x38][layer.bg - 1]);
  const dir = camelToSnakeCase(s.name);

  let layerData = '';

  for (let i = 1; i <= 3; i++) {
    layerData += `
extern const struct ScreenLayout sScreenMap${i};
INCBIN_STATIC(sScreenMap${i}, "data/stage/${dir}/layer${i}.bin");
`;
  }

  layerData += `
extern const tileset_ofs_t sTilesetOffset[];
INCBIN_STATIC(sTilesetOffset, "data/stage/${dir}/tileset_offset.bin");
`;

  layerData += `
extern const u16 sScreenBehavior[];
INCBIN_STATIC(sScreenBehavior, "data/stage/${dir}/screen_behavior.bin");
`;

  Deno.writeTextFileSync(join(dirname(args[0]), 'layer.h'), layerData);

  const landscape = `
const struct Stage g${s.name}Landscape = {
  id : ${s.id},
  fn : sStageRoutine,
  terrainHdr : &gStageTerrains[${s.id}],
  maps : {&sScreenMap1, &sScreenMap2, &sScreenMap3},
  bgIdx : {${bgIdxs[0]}, ${bgIdxs[1]}, ${bgIdxs[2]}},
  prio : {${l[0].prio}, ${l[1].prio}, ${l[2].prio}},
  screenBase : {BGMAP_BLOCK(2), BGMAP_BLOCK(4), BGMAP_BLOCK(6)},
  scrollPower : {{${scrollPower(l[0].scrollPower[0])}, ${scrollPower(l[0].scrollPower[1])}}, {${scrollPower(l[1].scrollPower[0])}, ${scrollPower(l[1].scrollPower[1])}}, {${scrollPower(l[2].scrollPower[0])}, ${scrollPower(l[2].scrollPower[1])}}},
  scroll : {{${l[0].scroll[0]}, ${l[0].scroll[1]}}, {${l[1].scroll[0]}, ${l[1].scroll[1]}}, {${l[2].scroll[0]}, ${l[2].scroll[1]}}},
  tilesetOffset : sTilesetOffset,
  bgFns : sLayerRoutine,
  behavior : sScreenBehavior,
  unk_78 : {${s.unk_78[0]}, ${s.unk_78[1]}},
};
`;

  Deno.writeTextFileSync(join(dirname(args[0]), 'landscape.h'), landscape);
};

const scrollPower = (val: number): number => {
  return ((val * 256) >> 0);
};

main();
