export type GraphicProp = '4bpp' | '8bpp' | 'lz77' | 'no_pal' | 'chunked';

export type GraphicHeader = {
  name: string;
  ofs: number;
  chunkSize: number;
  props: GraphicProp[];
  palette?: {
    color: number;
    id: number;
  };
  files?: string[];
  hdrOnly?: boolean;
};
